#include "dxtcodec.h"

#include <algorithm>
#include <cstring>

namespace {
	void Decode565( const unsigned short packed, unsigned char color[4] ) {
		color[0] = static_cast< unsigned char >( ( ( packed >> 11 ) & 31 ) * 255 / 31 );
		color[1] = static_cast< unsigned char >( ( ( packed >> 5 ) & 63 ) * 255 / 63 );
		color[2] = static_cast< unsigned char >( ( packed & 31 ) * 255 / 31 );
		color[3] = 255;
	}

	void DecodeColors( const unsigned char * input, unsigned char colors[4][4],
			const bool forceFourColor ) {
		const unsigned short color0 = static_cast< unsigned short >( input[0] | input[1] << 8 );
		const unsigned short color1 = static_cast< unsigned short >( input[2] | input[3] << 8 );
		Decode565( color0, colors[0] ); Decode565( color1, colors[1] );
		if ( color0 > color1 || forceFourColor ) {
			for ( int component = 0; component < 3; ++component ) {
				colors[2][component] = static_cast< unsigned char >( ( 2 * colors[0][component] + colors[1][component] ) / 3 );
				colors[3][component] = static_cast< unsigned char >( ( colors[0][component] + 2 * colors[1][component] ) / 3 );
			}
			colors[2][3] = colors[3][3] = 255;
		} else {
			for ( int component = 0; component < 3; ++component ) colors[2][component] =
				static_cast< unsigned char >( ( colors[0][component] + colors[1][component] ) / 2 );
			colors[2][3] = 255;
			std::memset( colors[3], 0, 4 );
		}
	}

	void DecodeAlpha( const unsigned char * input, unsigned char alpha[8] ) {
		alpha[0] = input[0]; alpha[1] = input[1];
		if ( alpha[0] > alpha[1] ) {
			for ( int index = 1; index <= 6; ++index ) alpha[index + 1] =
				static_cast< unsigned char >( ( ( 7 - index ) * alpha[0] + index * alpha[1] ) / 7 );
		} else {
			for ( int index = 1; index <= 4; ++index ) alpha[index + 1] =
				static_cast< unsigned char >( ( ( 5 - index ) * alpha[0] + index * alpha[1] ) / 5 );
			alpha[6] = 0; alpha[7] = 255;
		}
	}

	void Decompress( const unsigned char * input, unsigned char * output,
			const int width, const int height, const bool dxt5 ) {
		if ( input == nullptr || output == nullptr || width <= 0 || height <= 0 ) return;
		const int blocksWide = (std::max)( 1, ( width + 3 ) / 4 );
		const int blocksHigh = (std::max)( 1, ( height + 3 ) / 4 );
		const int blockBytes = dxt5 ? 16 : 8;
		for ( int blockY = 0; blockY < blocksHigh; ++blockY ) for ( int blockX = 0; blockX < blocksWide; ++blockX ) {
			const unsigned char * block = input + ( blockY * blocksWide + blockX ) * blockBytes;
			unsigned char alpha[8] = { 255, 255, 255, 255, 255, 255, 255, 255 };
			unsigned long long alphaIndices = 0;
			if ( dxt5 ) {
				DecodeAlpha( block, alpha );
				for ( int byte = 0; byte < 6; ++byte ) alphaIndices |=
					static_cast< unsigned long long >( block[2 + byte] ) << ( byte * 8 );
				block += 8;
			}
			unsigned char colors[4][4] = {};
			DecodeColors( block, colors, dxt5 );
			unsigned int colorIndices = 0;
			std::memcpy( &colorIndices, block + 4, sizeof( colorIndices ) );
			for ( int y = 0; y < 4; ++y ) for ( int x = 0; x < 4; ++x ) {
				const int destinationX = blockX * 4 + x;
				const int destinationY = blockY * 4 + y;
				if ( destinationX >= width || destinationY >= height ) continue;
				const int pixel = y * 4 + x;
				unsigned char * destination = output + ( destinationY * width + destinationX ) * 4;
				std::memcpy( destination, colors[( colorIndices >> ( pixel * 2 ) ) & 3], 4 );
				if ( dxt5 ) destination[3] = alpha[( alphaIndices >> ( pixel * 3 ) ) & 7];
			}
		}
	}
}

idDxtDecoder::idDxtDecoder() : width( 0 ), height( 0 ), inData( nullptr ) {}

void idDxtDecoder::DecompressImageDXT1( const unsigned char * input,
		unsigned char * output, const int imageWidth, const int imageHeight ) {
	inData = input; width = imageWidth; height = imageHeight;
	Decompress( input, output, width, height, false );
}

void idDxtDecoder::DecompressImageDXT5( const unsigned char * input,
		unsigned char * output, const int imageWidth, const int imageHeight ) {
	inData = input; width = imageWidth; height = imageHeight;
	Decompress( input, output, width, height, true );
}

void idDxtDecoder::DecompressImageDXT5_nVidia7x( const unsigned char * input,
		unsigned char * output, const int imageWidth, const int imageHeight ) {
	DecompressImageDXT5( input, output, imageWidth, imageHeight );
}

void idDxtDecoder::DecompressYCoCgDXT5( const unsigned char * input,
		unsigned char * output, const int imageWidth, const int imageHeight ) {
	DecompressImageDXT5( input, output, imageWidth, imageHeight );
	if ( output == nullptr ) return;
	for ( int pixel = 0; pixel < imageWidth * imageHeight; ++pixel ) {
		unsigned char * color = output + pixel * 4;
		const float scale = color[2] * ( 31.875f / 255.0f ) + 1.0f;
		const float co = ( static_cast< int >( color[0] ) - 128 ) / scale;
		const float cg = ( static_cast< int >( color[1] ) - 128 ) / scale;
		const float y = color[3];
		color[0] = static_cast< unsigned char >( (std::max)( 0.0f, (std::min)( 255.0f, y + co - cg ) ) );
		color[1] = static_cast< unsigned char >( (std::max)( 0.0f, (std::min)( 255.0f, y + cg ) ) );
		color[2] = static_cast< unsigned char >( (std::max)( 0.0f, (std::min)( 255.0f, y - co - cg ) ) );
		color[3] = 255;
	}
}
