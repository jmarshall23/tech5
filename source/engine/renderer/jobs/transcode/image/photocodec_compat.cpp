#include "photocodec_compat.h"

#include <algorithm>
#include <cstring>
#include <vector>

struct portablePhotoDecodeState_t {
	std::vector< unsigned char > rgba;
	int width;
	int height;
};

namespace {
	void BuildRGBA( const unsigned char * input, const int width, const int height,
			const portablePhotoPixels_t pixels, const bool flip,
			std::vector< unsigned char > & rgba ) {
		rgba.resize( static_cast< std::size_t >( width ) * height * 4 );
		for ( int y = 0; y < height; ++y ) {
			const int sourceY = flip ? height - 1 - y : y;
			for ( int x = 0; x < width; ++x ) {
				unsigned char * const destination =
					&rgba[( static_cast< std::size_t >( y ) * width + x ) * 4];
				if ( pixels == PORTABLE_PHOTO_MONO ) {
					const unsigned char value = input[sourceY * width + x];
					destination[0] = destination[1] = destination[2] = value;
					destination[3] = 255;
				} else {
					std::memcpy( destination,
						input + ( static_cast< std::size_t >( sourceY ) * width + x ) * 4, 4 );
				}
			}
		}
	}
}

bool PortablePhotoEncode( const unsigned char * input, unsigned char * output,
		const int outputCapacity, const int width, const int height, int & outputBytes,
		const portablePhotoPixels_t pixels, const rendererWICContainer_t container,
		const int quality, const bool flipVertical ) {
	outputBytes = 0;
	if ( input == nullptr || output == nullptr || outputCapacity <= 0 ||
		width <= 0 || height <= 0 ) return false;
	std::vector< unsigned char > rgba;
	BuildRGBA( input, width, height, pixels, flipVertical, rgba );
	std::vector< unsigned char > encoded;
	const float normalizedQuality = (std::max)( 1, (std::min)( quality, 100 ) ) / 100.0f;
	if ( !RendererWICEncode( rgba.data(), width, height, width * 4, container,
		normalizedQuality, encoded ) || encoded.size() > static_cast< std::size_t >( outputCapacity ) )
		return false;
	std::memcpy( output, encoded.data(), encoded.size() );
	outputBytes = static_cast< int >( encoded.size() );
	return true;
}

portablePhotoDecodeState_t * PortablePhotoBeginDecode( const unsigned char * input,
		const int inputBytes, const int width, const int height ) {
	portablePhotoDecodeState_t * state = new portablePhotoDecodeState_t();
	int decodedWidth = 0, decodedHeight = 0;
	if ( !RendererWICDecode( input, inputBytes, state->rgba, decodedWidth, decodedHeight ) ||
		decodedWidth != width || decodedHeight != height ) {
		delete state;
		return nullptr;
	}
	state->width = decodedWidth;
	state->height = decodedHeight;
	return state;
}

void PortablePhotoEndDecode( portablePhotoDecodeState_t * state ) { delete state; }

bool PortablePhotoDecode( const unsigned char * input, const int inputBytes,
		unsigned char * output, const int width, const int height, const int mipLevel,
		const portablePhotoPixels_t pixels ) {
	if ( output == nullptr || mipLevel < 0 || mipLevel > 12 ) return false;
	portablePhotoDecodeState_t * state = PortablePhotoBeginDecode(
		input, inputBytes, width, height );
	if ( state == nullptr ) return false;
	const int scale = 1 << mipLevel;
	const int outWidth = (std::max)( width / scale, 1 );
	const int outHeight = (std::max)( height / scale, 1 );
	for ( int y = 0; y < outHeight; ++y ) for ( int x = 0; x < outWidth; ++x ) {
		const unsigned char * source = &state->rgba[
			( static_cast< std::size_t >( (std::min)( y * scale, height - 1 ) ) * width +
			( std::min )( x * scale, width - 1 ) ) * 4];
		if ( pixels == PORTABLE_PHOTO_MONO ) output[y * outWidth + x] = source[0];
		else std::memcpy( output + ( static_cast< std::size_t >( y ) * outWidth + x ) * 4,
			source, 4 );
	}
	PortablePhotoEndDecode( state );
	return true;
}

void PortablePhotoCopyMacroBlock( const portablePhotoDecodeState_t * state,
		unsigned char * output, const int blockNumber, const int byteStride,
		const portablePhotoPixels_t pixels ) {
	if ( state == nullptr || output == nullptr || blockNumber < 0 || byteStride <= 0 ) return;
	const int blocksWide = ( state->width + 15 ) / 16;
	const int blockX = ( blockNumber % blocksWide ) * 16;
	const int blockY = ( blockNumber / blocksWide ) * 16;
	for ( int y = 0; y < 16 && blockY + y < state->height; ++y ) {
		for ( int x = 0; x < 16 && blockX + x < state->width; ++x ) {
			const unsigned char * source = &state->rgba[
				( static_cast< std::size_t >( blockY + y ) * state->width + blockX + x ) * 4];
			if ( pixels == PORTABLE_PHOTO_MONO ) output[y * byteStride + x] = source[0];
			else std::memcpy( output + y * byteStride + x * 4, source, 4 );
		}
	}
}
