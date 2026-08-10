#include "pagecompression.h"

#include "image/wiccodec.h"

#include <algorithm>
#include <cstring>
#include <limits>
#include <vector>

compressionStats_t::compressionStats_t() :
	headerBytes( 0 ), specularBytes( 0 ), diffuseBytes( 0 ), normalBytes( 0 ),
	powerBytes( 0 ), coverBytes( 0 ), wastedBytes( 0 ), diskOffsetScale( 1 ) {}

const char * PageCompressionName( const pageCompression_t compression ) {
	switch ( compression ) {
		case COMP_NONE: return "none";
		case COMP_DXT: return "dxt";
		case COMP_LZW: return "lzw";
		case COMP_DCT: return "dct";
		case COMP_HDP: return "hdp";
		case COMP_JXR: return "jxr";
		default: return "invalid";
	}
}

namespace {
	static const int PAGE_SIZE = 128;
	static const int PAGE_PLANE_BYTES = PAGE_SIZE * PAGE_SIZE * 4;

	struct encodedPage_t {
		std::vector< unsigned char > diffuse;
		std::vector< unsigned char > normal;
		std::vector< unsigned char > specular;
		std::vector< unsigned char > power;
		std::vector< unsigned char > alpha;
		std::vector< unsigned char > cover;
	};

	bool FitsHeaderField( const std::vector< unsigned char > & data ) {
		return data.size() <= (std::numeric_limits< std::uint16_t >::max)();
	}

	void BuildAuxiliaryImages( const unsigned char * normal, const unsigned char * specular,
			const bool storeCover, const bool storeAlpha,
			std::vector< unsigned char > & power, std::vector< unsigned char > & alpha,
			std::vector< unsigned char > & cover ) {
		power.resize( 32 * 32 * 4 );
		for ( int y = 0; y < 32; ++y ) {
			for ( int x = 0; x < 32; ++x ) {
				unsigned int total = 0;
				for ( int yy = 0; yy < 4; ++yy ) for ( int xx = 0; xx < 4; ++xx )
					total += normal[( ( y * 4 + yy ) * PAGE_SIZE + x * 4 + xx ) * 4 + 2];
				const unsigned char value = static_cast< unsigned char >( ( total + 8 ) / 16 );
				unsigned char * pixel = &power[( y * 32 + x ) * 4];
				pixel[0] = pixel[1] = pixel[2] = value;
				pixel[3] = 255;
			}
		}
		if ( storeAlpha ) {
			alpha.resize( PAGE_PLANE_BYTES );
			for ( int i = 0; i < PAGE_SIZE * PAGE_SIZE; ++i ) {
				const unsigned char value = specular[i * 4 + 3];
				alpha[i * 4 + 0] = alpha[i * 4 + 1] = alpha[i * 4 + 2] = value;
				alpha[i * 4 + 3] = 255;
			}
		}
		if ( storeCover ) {
			cover.assign( PAGE_SIZE * PAGE_SIZE / 8, 0 );
			for ( int i = 0; i < PAGE_SIZE * PAGE_SIZE; ++i )
				if ( specular[i * 4 + 3] >= 128 ) cover[i >> 3] |= 1u << ( i & 7 );
		}
	}

	bool EncodePage( const unsigned char * src, const int length,
			const rendererWICContainer_t container, const float diffuseQuality,
			const float normalQuality, const float specularQuality, const float powerQuality,
			const bool storeCover, const bool storeAlpha, encodedPage_t & encoded ) {
		if ( src == nullptr || length < PAGE_PLANE_BYTES * 3 ) return false;
		const unsigned char * diffuse = src;
		const unsigned char * normal = src + PAGE_PLANE_BYTES;
		const unsigned char * specular = src + PAGE_PLANE_BYTES * 2;
		std::vector< unsigned char > powerPixels, alphaPixels;
		BuildAuxiliaryImages( normal, specular, storeCover, storeAlpha,
			powerPixels, alphaPixels, encoded.cover );
		if ( !RendererWICEncode( diffuse, PAGE_SIZE, PAGE_SIZE, PAGE_SIZE * 4,
			container, diffuseQuality, encoded.diffuse ) ||
			!RendererWICEncode( normal, PAGE_SIZE, PAGE_SIZE, PAGE_SIZE * 4,
			container, normalQuality, encoded.normal ) ||
			!RendererWICEncode( specular, PAGE_SIZE, PAGE_SIZE, PAGE_SIZE * 4,
			container, specularQuality, encoded.specular ) ||
			!RendererWICEncode( powerPixels.data(), 32, 32, 32 * 4,
			container, powerQuality, encoded.power ) ) return false;
		if ( storeAlpha && !RendererWICEncode( alphaPixels.data(), PAGE_SIZE, PAGE_SIZE,
			PAGE_SIZE * 4, container, diffuseQuality, encoded.alpha ) ) return false;
		return FitsHeaderField( encoded.diffuse ) && FitsHeaderField( encoded.normal ) &&
			FitsHeaderField( encoded.specular ) && FitsHeaderField( encoded.power ) &&
			FitsHeaderField( encoded.alpha );
	}

	template< typename headerType_t > int WritePage( const encodedPage_t & encoded,
			headerType_t & header, unsigned char * dest, const unsigned int maxDestLength,
			compressionStats_t * stats ) {
		const std::size_t total = sizeof( headerType_t ) + encoded.diffuse.size() +
			encoded.normal.size() + encoded.specular.size() + encoded.power.size() +
			encoded.cover.size() + encoded.alpha.size();
		if ( dest == nullptr || total > maxDestLength || total > static_cast< std::size_t >( INT_MAX ) )
			return 0;
		header.diffuseSize = static_cast< std::uint16_t >( encoded.diffuse.size() );
		header.normalSize = static_cast< std::uint16_t >( encoded.normal.size() );
		header.specularSize = static_cast< std::uint16_t >( encoded.specular.size() );
		header.powerSize = static_cast< std::uint16_t >( encoded.power.size() );
		header.alphaSize = static_cast< std::uint16_t >( encoded.alpha.size() );
		unsigned char * output = dest;
		std::memcpy( output, &header, sizeof( header ) ); output += sizeof( header );
		const std::vector< unsigned char > * streams[] = {
			&encoded.diffuse, &encoded.normal, &encoded.specular,
			&encoded.power, &encoded.cover, &encoded.alpha
		};
		for ( const std::vector< unsigned char > * stream : streams ) {
			if ( !stream->empty() ) std::memcpy( output, stream->data(), stream->size() );
			output += stream->size();
		}
		if ( stats != nullptr ) {
			stats->headerBytes += sizeof( headerType_t );
			stats->diffuseBytes += encoded.diffuse.size();
			stats->normalBytes += encoded.normal.size();
			stats->specularBytes += encoded.specular.size();
			stats->powerBytes += encoded.power.size();
			stats->coverBytes += encoded.cover.size();
			const int alignment = (std::max)( stats->diskOffsetScale, 1 );
			stats->wastedBytes += ( alignment - static_cast< int >( total % alignment ) ) % alignment;
		}
		return static_cast< int >( total );
	}

	int CompressPhotoPage( char * src, const int length, unsigned char * dest,
			const unsigned int maxDestLength, const bool storeCover, const bool storeAlpha,
			compressionStats_t * stats, const bool jxr ) {
		encodedPage_t encoded;
		const float diffuseQuality = 1.0f - 30.0f / 255.0f;
		const float normalQuality = 1.0f - 30.0f / 255.0f;
		const float specularQuality = 1.0f - 25.0f / 255.0f;
		const float powerQuality = 1.0f - 40.0f / 255.0f;
		if ( !EncodePage( reinterpret_cast< unsigned char * >( src ), length,
			RENDERER_WIC_JPEG_XR, diffuseQuality, normalQuality, specularQuality,
			powerQuality, storeCover, storeAlpha, encoded ) ) return 0;
		HDPHeader_t header = {};
		header.qualityDiffuse = 30;
		header.qualityNormal = 30;
		header.qualitySpecular = 25;
		header.qualityPower = 40;
		header.flags = storeCover ? 8 : 0;
		header.pad = jxr ? 'J' : 'H'; // PC streams are standard JPEG XR; tag aids diagnostics.
		return WritePage( encoded, header, dest, maxDestLength, stats );
	}
}

int DCT_Compress( const unsigned char * src, const int length, unsigned char * dest,
		const int maxDestLength, const bool storeCover, const bool storeAlpha,
		compressionStats_t * stats ) {
	if ( maxDestLength <= 0 ) return 0;
	encodedPage_t encoded;
	if ( !EncodePage( src, length, RENDERER_WIC_JPEG, 0.90f, 0.60f, 0.80f, 0.80f,
		storeCover, storeAlpha, encoded ) ) return 0;
	DCTHeader_t header = {};
	header.qualityLuma = 90;
	header.qualityChroma = 80;
	header.qualityNormal = 60;
	header.qualitySpecular = 80;
	header.qualityPower = 80;
	header.flags = storeCover ? 8 : 0;
	return WritePage( encoded, header, dest, static_cast< unsigned int >( maxDestLength ), stats );
}

int HDP_Compress( char * src, const int length, unsigned char * dest,
		const unsigned int maxDestLength, const bool storeCover, const bool storeAlpha,
		compressionStats_t * stats ) {
	return CompressPhotoPage( src, length, dest, maxDestLength, storeCover, storeAlpha, stats, false );
}

int JXR_Compress( char * src, const int length, unsigned char * dest,
		const unsigned int maxDestLength, const bool storeCover, const bool storeAlpha,
		compressionStats_t * stats ) {
	return CompressPhotoPage( src, length, dest, maxDestLength, storeCover, storeAlpha, stats, true );
}
