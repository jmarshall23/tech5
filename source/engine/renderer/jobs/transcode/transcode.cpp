#include "transcode.h"

#include "image/dxt/dxtcodec.h"
#include "image/wiccodec.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

namespace {
	static const int PAGE_SIZE = 128;
	static const int PAGE_PIXELS = PAGE_SIZE * PAGE_SIZE;
	static const int PAGE_PLANE_BYTES = PAGE_PIXELS * 4;
	static const int PAGE_ALL_BYTES = PAGE_PLANE_BYTES * 3;

	unsigned char ClampByte( const float value ) {
		return static_cast< unsigned char >( (std::max)( 0.0f, (std::min)( 255.0f, value ) ) + 0.5f );
	}

	int AlignUp( const int value, const int alignment ) {
		const int safeAlignment = (std::max)( alignment, 1 );
		return ( value + safeAlignment - 1 ) & ~( safeAlignment - 1 );
	}

	void FillMissing( unsigned char * dest, const int pageLevel = 0, const int numLevels = 1 ) {
		if ( dest == nullptr ) return;
		const unsigned char level = static_cast< unsigned char >( numLevels > 1 ?
			( std::max )( 0, ( std::min )( 255, pageLevel * 255 / ( numLevels - 1 ) ) ) : 0 );
		for ( int y = 0; y < PAGE_SIZE; ++y ) for ( int x = 0; x < PAGE_SIZE; ++x ) {
			unsigned char * diffuse = dest + ( y * PAGE_SIZE + x ) * 4;
			unsigned char * normal = diffuse + PAGE_PLANE_BYTES;
			unsigned char * specular = normal + PAGE_PLANE_BYTES;
			diffuse[0] = static_cast< unsigned char >( x * 2 );
			diffuse[1] = static_cast< unsigned char >( y * 2 );
			diffuse[2] = level;
			diffuse[3] = 255;
			normal[0] = normal[1] = 128;
			normal[2] = 255;
			normal[3] = 255;
			specular[0] = specular[1] = specular[2] = 0;
			specular[3] = 255;
		}
	}

	void CopyDecodedImage( const std::vector< unsigned char > & image, const int width,
			const int height, unsigned char * output ) {
		if ( output == nullptr || image.empty() || width <= 0 || height <= 0 ) return;
		for ( int y = 0; y < PAGE_SIZE; ++y ) {
			const int sy = (std::min)( height - 1, y * height / PAGE_SIZE );
			for ( int x = 0; x < PAGE_SIZE; ++x ) {
				const int sx = (std::min)( width - 1, x * width / PAGE_SIZE );
				std::memcpy( output + ( y * PAGE_SIZE + x ) * 4,
					&image[( sy * width + sx ) * 4], 4 );
			}
		}
	}

	bool DecodeWICStream( const unsigned char * data, const unsigned int length,
			unsigned char * output ) {
		std::vector< unsigned char > rgba;
		int width = 0, height = 0;
		if ( !RendererWICDecode( data, length, rgba, width, height ) ) return false;
		CopyDecodedImage( rgba, width, height, output );
		return true;
	}

	template< typename headerType_t > void DecodePhotoPage( const headerType_t * header,
			const unsigned char * src, const unsigned int srcLen, unsigned char * dest ) {
		FillMissing( dest );
		if ( header == nullptr || src == nullptr || dest == nullptr ) return;
		const unsigned int coverSize = ( header->flags & 8 ) != 0 ? PAGE_PIXELS / 8 : 0;
		const unsigned int total = static_cast< unsigned int >( header->diffuseSize ) +
			header->normalSize + header->specularSize + header->powerSize + coverSize + header->alphaSize;
		if ( total > srcLen || header->diffuseSize == 0 || header->normalSize == 0 ||
			header->specularSize == 0 || header->powerSize == 0 ) return;
		unsigned int offset = 0;
		const bool diffuseOkay = DecodeWICStream( src + offset, header->diffuseSize, dest );
		offset += header->diffuseSize;
		const bool normalOkay = DecodeWICStream( src + offset, header->normalSize,
			dest + PAGE_PLANE_BYTES );
		offset += header->normalSize;
		const bool specularOkay = DecodeWICStream( src + offset, header->specularSize,
			dest + PAGE_PLANE_BYTES * 2 );
		offset += header->specularSize;
		// The retail fourth stream carried a 32x32 material-power field.  PC-created
		// pages retain it for wire compatibility; full-color normal streams already
		// carry the corresponding channel, so no destructive overwrite is needed.
		offset += header->powerSize;
		unsigned char * specular = dest + PAGE_PLANE_BYTES * 2;
		if ( coverSize != 0 ) {
			const unsigned char * cover = src + offset;
			for ( int i = 0; i < PAGE_PIXELS; ++i ) specular[i * 4 + 3] =
				( cover[i >> 3] & ( 1u << ( i & 7 ) ) ) != 0 ? 255 : 0;
			offset += coverSize;
		}
		if ( header->alphaSize != 0 ) {
			std::vector< unsigned char > alpha;
			int width = 0, height = 0;
			if ( RendererWICDecode( src + offset, header->alphaSize, alpha, width, height ) ) {
				for ( int y = 0; y < PAGE_SIZE; ++y ) for ( int x = 0; x < PAGE_SIZE; ++x ) {
					const int sx = (std::min)( width - 1, x * width / PAGE_SIZE );
					const int sy = (std::min)( height - 1, y * height / PAGE_SIZE );
					specular[( y * PAGE_SIZE + x ) * 4 + 3] = alpha[( sy * width + sx ) * 4];
				}
			}
		}
		if ( !diffuseOkay ) FillMissing( dest );
		if ( !normalOkay ) {
			for ( int i = 0; i < PAGE_PIXELS; ++i ) {
				unsigned char * normal = dest + PAGE_PLANE_BYTES + i * 4;
				normal[0] = normal[1] = 128; normal[2] = normal[3] = 255;
			}
		}
		if ( !specularOkay ) std::memset( dest + PAGE_PLANE_BYTES * 2, 0, PAGE_PLANE_BYTES );
	}

	float CubicWeight( const float x ) {
		const float a = -0.5f;
		const float t = std::fabs( x );
		if ( t < 1.0f ) return ( a + 2.0f ) * t * t * t - ( a + 3.0f ) * t * t + 1.0f;
		if ( t < 2.0f ) return a * t * t * t - 5.0f * a * t * t + 8.0f * a * t - 4.0f * a;
		return 0.0f;
	}

	void ResampleRegion( unsigned char * plane, const float startX, const float startY,
			const float regionWidth, const float regionHeight, const float sharpen,
			const unsigned int noiseSeed ) {
		std::vector< unsigned char > source( plane, plane + PAGE_PLANE_BYTES );
		for ( int y = 0; y < PAGE_SIZE; ++y ) for ( int x = 0; x < PAGE_SIZE; ++x ) {
			const float sy = startY + ( y + 0.5f ) * regionHeight / PAGE_SIZE - 0.5f;
			const float sx = startX + ( x + 0.5f ) * regionWidth / PAGE_SIZE - 0.5f;
			const int iy = static_cast< int >( std::floor( sy ) );
			const int ix = static_cast< int >( std::floor( sx ) );
			for ( int channel = 0; channel < 4; ++channel ) {
				float value = 0.0f, weightTotal = 0.0f;
				for ( int yy = -1; yy <= 2; ++yy ) for ( int xx = -1; xx <= 2; ++xx ) {
					const float weight = CubicWeight( sy - ( iy + yy ) ) * CubicWeight( sx - ( ix + xx ) );
					const int sampleX = (std::max)( 0, (std::min)( PAGE_SIZE - 1, ix + xx ) );
					const int sampleY = (std::max)( 0, (std::min)( PAGE_SIZE - 1, iy + yy ) );
					value += source[( sampleY * PAGE_SIZE + sampleX ) * 4 + channel] * weight;
					weightTotal += weight;
				}
				if ( weightTotal != 0.0f ) value /= weightTotal;
				if ( sharpen > 0.0f && channel < 3 ) {
					const int nearestX = (std::max)( 0, (std::min)( PAGE_SIZE - 1, static_cast< int >( sx + 0.5f ) ) );
					const int nearestY = (std::max)( 0, (std::min)( PAGE_SIZE - 1, static_cast< int >( sy + 0.5f ) ) );
					const float nearest = source[( nearestY * PAGE_SIZE + nearestX ) * 4 + channel];
					value += ( nearest - value ) * sharpen;
				}
				unsigned int hash = noiseSeed ^ ( x * 0x9E3779B9u ) ^ ( y * 0x85EBCA6Bu ) ^ channel;
				hash ^= hash >> 16; hash *= 0x7FEB352Du; hash ^= hash >> 15;
				const float noise = noiseSeed != 0 ? ( static_cast< int >( hash & 255 ) - 127.5f ) / 255.0f : 0.0f;
				plane[( y * PAGE_SIZE + x ) * 4 + channel] = ClampByte( value + noise );
			}
		}
	}

	void UpsamplePage( unsigned char * data, const transcodeParms_t & parms ) {
		if ( data == nullptr || parms.upsampleLevel <= 0 ) return;
		const int level = (std::min)( parms.upsampleLevel, 12 );
		const int subdivisions = 1 << level;
		const int mask = subdivisions - 1;
		const float pageInterior = 120.0f;
		const float region = pageInterior / subdivisions;
		const float startX = 4.0f + ( parms.upsampleX & mask ) * region;
		const float startY = 4.0f + ( parms.upsampleY & mask ) * region;
		const float sharpen = (std::min)( parms.upsampleSharpen / 65535.0f, 1.0f );
		const unsigned int noise = parms.upsampleNoise >> (std::min)( parms.pageLevel, 15 );
		ResampleRegion( data, startX, startY, region, region, sharpen,
			noise ^ static_cast< unsigned int >( parms.pageX * 31 + parms.pageY * 131 ) );
		ResampleRegion( data + PAGE_PLANE_BYTES, startX, startY, region, region, 0.0f, 0 );
		ResampleRegion( data + PAGE_PLANE_BYTES * 2, startX, startY, region, region, 0.0f, 0 );
	}

	void PaletteColor( const int index, unsigned char rgba[4] ) {
		static const unsigned char palette[][4] = {
			{ 0, 0, 0, 255 }, { 255, 0, 0, 255 }, { 0, 255, 0, 255 },
			{ 0, 0, 255, 255 }, { 255, 255, 0, 255 }, { 0, 255, 255, 255 },
			{ 255, 0, 255, 255 }, { 255, 255, 255, 255 }, { 32, 32, 32, 255 },
			{ 128, 128, 128, 255 }, { 255, 128, 0, 255 }
		};
		std::memcpy( rgba, palette[( index < 0 ? -index : index ) %
			( sizeof( palette ) / sizeof( palette[0] ) )], 4 );
	}

	void FillDebugColor( unsigned char * data, const int number ) {
		unsigned char y = 0, co = 0, cg = 0;
		BrightColorForNumber( number, &y, &co, &cg );
		const int dco = static_cast< int >( co ) - 128;
		const int dcg = static_cast< int >( cg ) - 128;
		const unsigned char r = ClampByte( static_cast< float >( y + dco - dcg ) );
		const unsigned char g = ClampByte( static_cast< float >( y + dcg ) );
		const unsigned char b = ClampByte( static_cast< float >( y - dco - dcg ) );
		for ( int i = 0; i < PAGE_PIXELS; ++i ) {
			unsigned char * diffuse = data + i * 4;
			unsigned char * normal = diffuse + PAGE_PLANE_BYTES;
			unsigned char * specular = normal + PAGE_PLANE_BYTES;
			diffuse[0] = r; diffuse[1] = g; diffuse[2] = b; diffuse[3] = 255;
			normal[0] = normal[1] = 128; normal[2] = normal[3] = 255;
			specular[0] = specular[1] = specular[2] = 0; specular[3] = 255;
		}
	}

	void DrawDebugBorder( unsigned char * data ) {
		unsigned char colors[3][4];
		PaletteColor( 10, colors[0] ); PaletteColor( 9, colors[1] ); PaletteColor( 9, colors[2] );
		for ( int plane = 0; plane < 3; ++plane ) for ( int y = 0; y < PAGE_SIZE; ++y )
			for ( int x = 0; x < PAGE_SIZE; ++x ) if ( x < 4 || y < 4 || x >= 124 || y >= 124 )
				std::memcpy( data + plane * PAGE_PLANE_BYTES + ( y * PAGE_SIZE + x ) * 4,
					colors[plane], 4 );
	}

	void ApplyDebugVisualization( unsigned char * data, const transcodeParms_t & parms ) {
		if ( parms.dbgShowPageColors )
			FillDebugColor( data, parms.pageX * 73856093 ^ parms.pageY * 19349663 ^ parms.pageLevel * 83492791 );
		else if ( parms.dbgShowPageSources ) FillDebugColor( data, parms.pageSource );
		else if ( parms.dbgShowPageUsage ) FillDebugColor( data, parms.dbgShowPageUsage );
		else if ( parms.dbgShowPageMips != 0 && parms.pageLevel >= parms.dbgShowPageMips - 1 )
			FillDebugColor( data, parms.pageLevel );
		if ( parms.dbgShowPageBorders || parms.dbgShowPageInfo || parms.dbgShowPageNumbers ||
			parms.dbgShowPageColors || parms.dbgShowPageSources || parms.dbgShowPageMips != 0 ||
			parms.dbgShowPageSizes != 0 ) DrawDebugBorder( data );
		if ( parms.dbgShowPageNumbers || parms.dbgShowPageInfo || parms.inPageData == nullptr ) {
			char number[32];
			std::snprintf( number, sizeof( number ), "%d%d", parms.pageX & 99, parms.pageY & 99 );
			for ( int plane = 0; plane < 3; ++plane ) DrawPixelNumber(
				data + plane * PAGE_PLANE_BYTES + 8 * PAGE_SIZE * 4 + 8 * 4,
				PAGE_SIZE * 4, number, 2, 2, 4, 10, 8 );
		}
	}

	void CompressTargets( const transcodeParms_t & parms, unsigned char * data ) {
		if ( parms.outPageCompression == COMP_NONE ) {
			CopyUncompressed( parms.targetImage, const_cast< int * >( parms.targetBytePitch ),
				static_cast< char >( parms.imageFlags ), data, PAGE_ALL_BYTES );
			return;
		}
		if ( parms.outPageCompression != COMP_DXT ) return;
		idDxtEncoder encoder;
		if ( ( parms.imageFlags & TRANSCODE_IMAGE_SPECULAR ) != 0 && parms.targetImage[0] != nullptr ) {
			encoder.dstPadding = parms.targetBytePitch[0] - PAGE_SIZE / 2;
			encoder.CompressImageDXT1AlphaFast_Xenon( data + PAGE_PLANE_BYTES * 2,
				parms.targetImage[0], PAGE_SIZE, PAGE_SIZE );
		}
		if ( ( parms.imageFlags & TRANSCODE_IMAGE_DIFFUSE ) != 0 && parms.targetImage[1] != nullptr ) {
			encoder.dstPadding = parms.targetBytePitch[1] - PAGE_SIZE;
			encoder.CompressYCoCgDXT5Fast_Xenon( data, parms.targetImage[1], PAGE_SIZE, PAGE_SIZE );
		}
		if ( ( parms.imageFlags & TRANSCODE_IMAGE_NORMAL ) != 0 && parms.targetImage[2] != nullptr ) {
			encoder.dstPadding = parms.targetBytePitch[2] - PAGE_SIZE;
			encoder.CompressNormalMapDXT5Fast_Xenon( data + PAGE_PLANE_BYTES,
				parms.targetImage[2], PAGE_SIZE, PAGE_SIZE );
		}
	}
}

void BrightColorForNumber( int number, unsigned char * y, unsigned char * co, unsigned char * cg ) {
	unsigned int state = static_cast< unsigned int >( number );
	unsigned int r, g, b;
	do {
		state = state * 1103515245u + 12345u; r = ( state >> 23 ) & 255;
		state = state * 1103515245u + 12345u; g = ( state >> 23 ) & 255;
		state = state * 1103515245u + 12345u; b = ( state >> 23 ) & 255;
	} while ( r + g + b < 255 || ( r < 128 && g < 128 && b < 128 ) );
	if ( y != nullptr ) *y = ClampByte( ( r + 2.0f * g + b ) * 0.25f );
	if ( co != nullptr ) *co = ClampByte( 128.0f + ( static_cast< float >( r ) - b ) * 0.5f );
	if ( cg != nullptr ) *cg = ClampByte( 128.0f + ( 2.0f * g - r - b ) * 0.25f );
}

void DrawPixelNumber( unsigned char * dest, const int byteStride, const char * text,
		const int scaleX, const int scaleY, const int pixelStride,
		const int frontColor, const int backColor ) {
	static const unsigned short glyphs[10] = {
		0x7B6F, 0x2492, 0x73E7, 0x73CF, 0x5BC9,
		0x79CF, 0x79EF, 0x7249, 0x7BEF, 0x7BCF
	};
	if ( dest == nullptr || text == nullptr || scaleX <= 0 || scaleY <= 0 ||
		byteStride <= 0 || pixelStride <= 0 ) return;
	unsigned char front[4], back[4];
	PaletteColor( frontColor, front ); PaletteColor( backColor, back );
	int cursor = 0;
	for ( ; *text != '\0'; ++text ) {
		if ( *text < '0' || *text > '9' ) { cursor += 4 * scaleX; continue; }
		const unsigned short bits = glyphs[*text - '0'];
		for ( int row = 0; row < 5; ++row ) for ( int column = 0; column < 3; ++column ) {
			const unsigned char * color = ( bits & ( 1u << ( 14 - row * 3 - column ) ) ) != 0 ? front : back;
			for ( int yy = 0; yy < scaleY; ++yy ) for ( int xx = 0; xx < scaleX; ++xx )
				std::memcpy( dest + ( row * scaleY + yy ) * byteStride +
					( cursor + column * scaleX + xx ) * pixelStride, color,
					(std::min)( pixelStride, 4 ) );
		}
		cursor += 4 * scaleX;
	}
}

void DXT_Decompress( const int pageHeaderSize, const int diskOffsetScale,
		const unsigned char * src, const int srcLen, unsigned char * dest ) {
	FillMissing( dest );
	if ( src == nullptr || dest == nullptr || srcLen <= 0 ) return;
	const int alignedLength = AlignUp( pageHeaderSize + srcLen, diskOffsetScale );
	const bool specularDXT1 = alignedLength == AlignUp( pageHeaderSize + 40960, diskOffsetScale );
	const bool specularDXT5 = alignedLength == AlignUp( pageHeaderSize + 49152, diskOffsetScale );
	if ( !specularDXT1 && !specularDXT5 ) return;
	idDxtDecoder decoder;
	const int specularSize = specularDXT1 ? 8192 : 16384;
	if ( specularDXT1 ) decoder.DecompressImageDXT1( src, dest + PAGE_PLANE_BYTES * 2, 128, 128 );
	else decoder.DecompressImageDXT5( src, dest + PAGE_PLANE_BYTES * 2, 128, 128 );
	decoder.DecompressYCoCgDXT5( src + specularSize, dest, 128, 128 );
	unsigned char * normal = dest + PAGE_PLANE_BYTES;
	decoder.DecompressImageDXT5( src + specularSize + 16384, normal, 128, 128 );
	for ( int i = 0; i < PAGE_PIXELS; ++i ) {
		unsigned char * pixel = normal + i * 4;
		pixel[0] = pixel[3];
		const float nx = pixel[0] * ( 2.0f / 255.0f ) - 1.0f;
		const float ny = pixel[1] * ( 2.0f / 255.0f ) - 1.0f;
		pixel[2] = ClampByte( ( std::sqrt( (std::max)( 0.0f, 1.0f - nx * nx - ny * ny ) ) * 0.5f + 0.5f ) * 255.0f );
		pixel[3] = 255;
	}
}

void DCT_Decompress( const DCTHeader_t * header, const unsigned char * src,
		const unsigned int srcLen, unsigned char * dest ) {
	DecodePhotoPage( header, src, srcLen, dest );
}

void HDP_Decompress( const HDPHeader_t * header, unsigned char * src,
		const unsigned int srcLen, unsigned char * dest ) {
	DecodePhotoPage( header, src, srcLen, dest );
}

void JXR_Decompress( const JXRHeader_t * header, const unsigned char * src,
		const int srcLen, unsigned char * dest ) {
	DecodePhotoPage( header, src, static_cast< unsigned int >( (std::max)( srcLen, 0 ) ), dest );
}

void CopyUncompressed( unsigned char * const * targetImage, int * targetBytePitch,
		const char imageFlags, const unsigned char * src, const int srcLength ) {
	if ( targetImage == nullptr || targetBytePitch == nullptr || src == nullptr || srcLength < PAGE_ALL_BYTES ) return;
	const int flags = static_cast< unsigned char >( imageFlags );
	const int sourcePlanes[3] = { 2, 0, 1 };
	const int flagBits[3] = { TRANSCODE_IMAGE_SPECULAR, TRANSCODE_IMAGE_DIFFUSE, TRANSCODE_IMAGE_NORMAL };
	for ( int target = 0; target < 3; ++target ) {
		if ( ( flags & flagBits[target] ) == 0 || targetImage[target] == nullptr || targetBytePitch[target] < 512 ) continue;
		const unsigned char * source = src + sourcePlanes[target] * PAGE_PLANE_BYTES;
		for ( int y = 0; y < PAGE_SIZE; ++y )
			std::memcpy( targetImage[target] + y * targetBytePitch[target], source + y * 512, 512 );
	}
}

void ConvertDXT5_DXT1Alpha( unsigned char * dst, const int dstBytePitch, const unsigned char * src ) {
	if ( dst == nullptr || src == nullptr || dstBytePitch < 256 ) return;
	std::vector< unsigned char > rgba( PAGE_PLANE_BYTES );
	idDxtDecoder decoder;
	decoder.DecompressImageDXT5( src, rgba.data(), PAGE_SIZE, PAGE_SIZE );
	idDxtEncoder encoder;
	encoder.dstPadding = dstBytePitch - 256;
	encoder.CompressImageDXT1AlphaHQ( rgba.data(), dst, PAGE_SIZE, PAGE_SIZE );
}

void CopyDXTCompressed( unsigned char * const * targetImage, int * targetBytePitch,
		const char imageFlags, const unsigned char * src, const int srcLength,
		const int pageHeaderSize, const int diskOffsetScale ) {
	if ( targetImage == nullptr || targetBytePitch == nullptr || src == nullptr ) return;
	const int alignedLength = AlignUp( pageHeaderSize + srcLength, diskOffsetScale );
	const bool specularDXT1 = alignedLength == AlignUp( pageHeaderSize + 40960, diskOffsetScale );
	const bool specularDXT5 = alignedLength == AlignUp( pageHeaderSize + 49152, diskOffsetScale );
	if ( !specularDXT1 && !specularDXT5 ) return;
	const int specularSize = specularDXT1 ? 8192 : 16384;
	const int specularPitch = specularDXT1 ? 256 : 512;
	const int flags = static_cast< unsigned char >( imageFlags );
	if ( ( flags & TRANSCODE_IMAGE_SPECULAR ) != 0 && targetImage[0] != nullptr ) {
		if ( specularDXT1 ) {
			for ( int row = 0; row < 32; ++row ) std::memcpy(
				targetImage[0] + row * targetBytePitch[0], src + row * specularPitch, specularPitch );
		} else ConvertDXT5_DXT1Alpha( targetImage[0], targetBytePitch[0], src );
	}
	const unsigned char * diffuse = src + specularSize;
	const unsigned char * normal = diffuse + 16384;
	for ( int target = 1; target <= 2; ++target ) {
		const int bit = target == 1 ? TRANSCODE_IMAGE_DIFFUSE : TRANSCODE_IMAGE_NORMAL;
		if ( ( flags & bit ) == 0 || targetImage[target] == nullptr || targetBytePitch[target] < 512 ) continue;
		const unsigned char * source = target == 1 ? diffuse : normal;
		for ( int row = 0; row < 32; ++row ) std::memcpy(
			targetImage[target] + row * targetBytePitch[target], source + row * 512, 512 );
	}
}

void StripPageBorder( unsigned char * dst ) {
	if ( dst == nullptr ) return;
	// Retail maps 4..124 (120 texels) back over the full 128 page with a
	// four-tap cubic filter.  This preserves that exact coordinate transform.
	ResampleRegion( dst, 4.0f, 4.0f, 120.0f, 120.0f, 0.0f, 0 );
}

void TranscodePage( const transcodeParms_t * parms ) {
	if ( parms == nullptr ) return;
	const_cast< transcodeParms_t * >( parms )->startedExecution = true;
	const bool debug = parms->dbgShowPageBorders || parms->dbgShowPageInfo ||
		parms->dbgShowPageNumbers || parms->dbgShowPageColors || parms->dbgShowPageSources ||
		parms->dbgShowPageMips != 0 || parms->dbgShowPageSizes != 0 || parms->dbgShowPageUsage != 0;
	if ( parms->inPageData != nullptr && parms->inPageCompression == parms->outPageCompression &&
		!parms->stripPageBorders && !debug && parms->upsampleLevel == 0 ) {
		if ( parms->inPageCompression == COMP_NONE ) CopyUncompressed( parms->targetImage,
			const_cast< int * >( parms->targetBytePitch ), static_cast< char >( parms->imageFlags ),
			parms->inPageData, parms->inPageDataLength );
		else if ( parms->inPageCompression == COMP_DXT ) CopyDXTCompressed( parms->targetImage,
			const_cast< int * >( parms->targetBytePitch ), static_cast< char >( parms->imageFlags ),
			parms->inPageData, parms->inPageDataLength, parms->pageHeaderSize, parms->diskOffsetScale );
		return;
	}
	std::vector< unsigned char > owned;
	unsigned char * temp = parms->tempData;
	if ( temp == nullptr || parms->tempSize < PAGE_ALL_BYTES ) {
		owned.resize( PAGE_ALL_BYTES );
		temp = owned.data();
	}
	FillMissing( temp, parms->pageLevel, parms->numLevels );
	if ( parms->inPageData != nullptr ) {
		switch ( parms->inPageCompression ) {
			case COMP_NONE:
				if ( parms->inPageDataLength >= PAGE_ALL_BYTES ) std::memcpy( temp, parms->inPageData, PAGE_ALL_BYTES );
				break;
			case COMP_DXT:
				DXT_Decompress( parms->pageHeaderSize, parms->diskOffsetScale,
					parms->inPageData, parms->inPageDataLength, temp );
				break;
			case COMP_DCT:
				DCT_Decompress( reinterpret_cast< const DCTHeader_t * >( parms->inPageHeader ),
					parms->inPageData, parms->inPageDataLength, temp );
				break;
			case COMP_HDP:
				HDP_Decompress( reinterpret_cast< const HDPHeader_t * >( parms->inPageHeader ),
					const_cast< unsigned char * >( parms->inPageData ), parms->inPageDataLength, temp );
				break;
			case COMP_JXR:
				JXR_Decompress( reinterpret_cast< const JXRHeader_t * >( parms->inPageHeader ),
					parms->inPageData, parms->inPageDataLength, temp );
				break;
			default: break;
		}
	}
	UpsamplePage( temp, *parms );
	ApplyDebugVisualization( temp, *parms );
	if ( parms->stripPageBorders ) {
		StripPageBorder( temp );
		StripPageBorder( temp + PAGE_PLANE_BYTES );
		StripPageBorder( temp + PAGE_PLANE_BYTES * 2 );
	}
	CompressTargets( *parms, temp );
}
