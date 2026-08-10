#include "dxtcodec.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

namespace {
	unsigned short Pack565( const unsigned char * color ) {
		return static_cast< unsigned short >( ( color[0] >> 3 ) << 11 |
			( color[1] >> 2 ) << 5 | color[2] >> 3 );
	}

	void Unpack565( const unsigned short color, unsigned char output[4] ) {
		output[0] = static_cast< unsigned char >( ( ( color >> 11 ) & 31 ) * 255 / 31 );
		output[1] = static_cast< unsigned char >( ( ( color >> 5 ) & 63 ) * 255 / 63 );
		output[2] = static_cast< unsigned char >( ( color & 31 ) * 255 / 31 );
		output[3] = 255;
	}

	int ColorError( const unsigned char * a, const unsigned char * b ) {
		const int r = static_cast< int >( a[0] ) - b[0];
		const int g = static_cast< int >( a[1] ) - b[1];
		const int bl = static_cast< int >( a[2] ) - b[2];
		return r * r + 2 * g * g + bl * bl;
	}

	void Gather( const unsigned char * input, const int width, const int height,
			const int sourcePitch, const int blockX, const int blockY,
			unsigned char block[16][4] ) {
		for ( int y = 0; y < 4; ++y ) for ( int x = 0; x < 4; ++x ) {
			const int sourceX = (std::min)( blockX * 4 + x, width - 1 );
			const int sourceY = (std::min)( blockY * 4 + y, height - 1 );
			std::memcpy( block[y * 4 + x], input + sourceY * sourcePitch + sourceX * 4, 4 );
		}
	}

	void EncodeColorBlock( const unsigned char block[16][4],
			unsigned char * output, const bool allowTransparency ) {
		int minimum = 0, maximum = 0;
		int minimumProjection = 0x7fffffff, maximumProjection = -0x7fffffff;
		bool hasTransparency = false;
		// The luminance axis matches the inexpensive retail fast selector and is
		// stable for tiny/flat blocks.  Endpoint refinement tests nearby 565
		// values implicitly through quantization.
		for ( int pixel = 0; pixel < 16; ++pixel ) {
			const int projection = 3 * block[pixel][0] + 6 * block[pixel][1] + block[pixel][2];
			if ( projection < minimumProjection ) { minimumProjection = projection; minimum = pixel; }
			if ( projection > maximumProjection ) { maximumProjection = projection; maximum = pixel; }
			hasTransparency |= block[pixel][3] < 128;
		}
		unsigned short color0 = Pack565( block[maximum] );
		unsigned short color1 = Pack565( block[minimum] );
		const bool transparentMode = allowTransparency && hasTransparency;
		if ( transparentMode ) {
			if ( color0 > color1 ) std::swap( color0, color1 );
		} else {
			if ( color0 <= color1 ) std::swap( color0, color1 );
			if ( color0 == color1 ) {
				if ( color0 < 0xffffu ) ++color0;
				else --color1;
			}
		}
		output[0] = static_cast< unsigned char >( color0 );
		output[1] = static_cast< unsigned char >( color0 >> 8 );
		output[2] = static_cast< unsigned char >( color1 );
		output[3] = static_cast< unsigned char >( color1 >> 8 );
		unsigned char palette[4][4] = {};
		Unpack565( color0, palette[0] );
		Unpack565( color1, palette[1] );
		if ( color0 > color1 ) {
			for ( int c = 0; c < 3; ++c ) {
				palette[2][c] = static_cast< unsigned char >( ( 2 * palette[0][c] + palette[1][c] ) / 3 );
				palette[3][c] = static_cast< unsigned char >( ( palette[0][c] + 2 * palette[1][c] ) / 3 );
			}
			palette[2][3] = palette[3][3] = 255;
		} else {
			for ( int c = 0; c < 3; ++c ) palette[2][c] =
				static_cast< unsigned char >( ( palette[0][c] + palette[1][c] ) / 2 );
			palette[2][3] = 255;
			palette[3][3] = 0;
		}
		unsigned int indices = 0;
		for ( int pixel = 0; pixel < 16; ++pixel ) {
			int best = transparentMode && block[pixel][3] < 128 ? 3 : 0;
			int error = best == 3 ? 0 : ColorError( block[pixel], palette[0] );
			const int candidates = color0 > color1 ? 4 : 3;
			for ( int candidate = 1; candidate < candidates; ++candidate ) {
				const int candidateError = ColorError( block[pixel], palette[candidate] );
				if ( candidateError < error ) { error = candidateError; best = candidate; }
			}
			indices |= static_cast< unsigned int >( best ) << ( pixel * 2 );
		}
		std::memcpy( output + 4, &indices, sizeof( indices ) );
	}

	void BuildAlphaPalette( const unsigned char alpha0, const unsigned char alpha1,
			unsigned char palette[8] ) {
		palette[0] = alpha0; palette[1] = alpha1;
		if ( alpha0 > alpha1 ) {
			for ( int index = 1; index <= 6; ++index ) palette[index + 1] =
				static_cast< unsigned char >( ( ( 7 - index ) * alpha0 + index * alpha1 ) / 7 );
		} else {
			for ( int index = 1; index <= 4; ++index ) palette[index + 1] =
				static_cast< unsigned char >( ( ( 5 - index ) * alpha0 + index * alpha1 ) / 5 );
			palette[6] = 0; palette[7] = 255;
		}
	}

	void EncodeAlphaBlock( const unsigned char block[16][4], unsigned char * output ) {
		unsigned char minimum = 255, maximum = 0;
		for ( int pixel = 0; pixel < 16; ++pixel ) {
			minimum = (std::min)( minimum, block[pixel][3] );
			maximum = (std::max)( maximum, block[pixel][3] );
		}
		output[0] = maximum; output[1] = minimum;
		unsigned char palette[8];
		BuildAlphaPalette( maximum, minimum, palette );
		unsigned long long indices = 0;
		for ( int pixel = 0; pixel < 16; ++pixel ) {
			int best = 0, bestError = 0x7fffffff;
			for ( int candidate = 0; candidate < 8; ++candidate ) {
				const int difference = static_cast< int >( block[pixel][3] ) - palette[candidate];
				const int error = difference * difference;
				if ( error < bestError ) { bestError = error; best = candidate; }
			}
			indices |= static_cast< unsigned long long >( best ) << ( pixel * 3 );
		}
		for ( int byte = 0; byte < 6; ++byte ) output[2 + byte] =
			static_cast< unsigned char >( indices >> ( byte * 8 ) );
	}

	void Compress( const unsigned char * input, unsigned char * output,
			const int width, const int height, const int sourcePadding,
			const int destinationPadding, const bool dxt5,
			const bool dxt1Alpha ) {
		if ( input == nullptr || output == nullptr || width <= 0 || height <= 0 ) return;
		const int blocksWide = (std::max)( 1, ( width + 3 ) / 4 );
		const int blocksHigh = (std::max)( 1, ( height + 3 ) / 4 );
		const int sourcePitch = width * 4 + (std::max)( sourcePadding, 0 );
		const int blockBytes = dxt5 ? 16 : 8;
		const int destinationPitch = blocksWide * blockBytes + (std::max)( destinationPadding, 0 );
		for ( int blockY = 0; blockY < blocksHigh; ++blockY ) {
			for ( int blockX = 0; blockX < blocksWide; ++blockX ) {
				unsigned char block[16][4];
				Gather( input, width, height, sourcePitch, blockX, blockY, block );
				unsigned char * destination = output + blockY * destinationPitch + blockX * blockBytes;
				if ( dxt5 ) { EncodeAlphaBlock( block, destination ); destination += 8; }
				EncodeColorBlock( block, destination, !dxt5 && dxt1Alpha );
			}
		}
	}
}

idDxtEncoder::idDxtEncoder() : width( 0 ), height( 0 ), outData( nullptr ),
	srcPadding( 0 ), dstPadding( 0 ) {}

void idDxtEncoder::CompressImageDXT1HQ( const unsigned char * input,
		unsigned char * output, const int imageWidth, const int imageHeight ) {
	width = imageWidth; height = imageHeight; outData = output;
	Compress( input, output, width, height, srcPadding, dstPadding, false, false );
}

void idDxtEncoder::CompressImageDXT1AlphaHQ( const unsigned char * input,
		unsigned char * output, const int imageWidth, const int imageHeight ) {
	width = imageWidth; height = imageHeight; outData = output;
	Compress( input, output, width, height, srcPadding, dstPadding, false, true );
}

void idDxtEncoder::CompressImageDXT5HQ( const unsigned char * input,
		unsigned char * output, const int imageWidth, const int imageHeight ) {
	width = imageWidth; height = imageHeight; outData = output;
	Compress( input, output, width, height, srcPadding, dstPadding, true, false );
}

void idDxtEncoder::CompressNormalMapDXT5HQ( const unsigned char * input,
		unsigned char * output, const int imageWidth, const int imageHeight ) {
	if ( input == nullptr || imageWidth <= 0 || imageHeight <= 0 ) return;
	const int sourcePitch = imageWidth * 4 + (std::max)( srcPadding, 0 );
	std::vector< unsigned char > swizzled( static_cast< std::size_t >( imageWidth ) * imageHeight * 4 );
	for ( int y = 0; y < imageHeight; ++y ) for ( int x = 0; x < imageWidth; ++x ) {
		const unsigned char * source = input + y * sourcePitch + x * 4;
		unsigned char * destination = &swizzled[( y * imageWidth + x ) * 4];
		destination[0] = 0; destination[1] = source[1]; destination[2] = 0; destination[3] = source[0];
	}
	const int savedPadding = srcPadding; srcPadding = 0;
	CompressImageDXT5HQ( swizzled.data(), output, imageWidth, imageHeight );
	srcPadding = savedPadding;
}

void idDxtEncoder::CompressYCoCgAlphaDXT5Fast( const unsigned char * input,
		unsigned char * output, const int imageWidth, const int imageHeight ) {
	if ( input == nullptr || output == nullptr || imageWidth <= 0 || imageHeight <= 0 ) return;
	const int sourcePitch = imageWidth * 4 + (std::max)( srcPadding, 0 );
	std::vector< unsigned char > ycocg( static_cast< std::size_t >( imageWidth ) * imageHeight * 4 );
	for ( int blockY = 0; blockY < imageHeight; blockY += 4 ) {
		for ( int blockX = 0; blockX < imageWidth; blockX += 4 ) {
			float maxChroma = 1.0f;
			for ( int y = 0; y < 4 && blockY + y < imageHeight; ++y )
				for ( int x = 0; x < 4 && blockX + x < imageWidth; ++x ) {
					const unsigned char * pixel = input + ( blockY + y ) * sourcePitch + ( blockX + x ) * 4;
					const float co = ( static_cast< float >( pixel[0] ) - pixel[2] ) * 0.5f;
					const float cg = ( -static_cast< float >( pixel[0] ) + 2.0f * pixel[1] - pixel[2] ) * 0.25f;
					maxChroma = (std::max)( maxChroma, (std::max)( std::fabs( co ), std::fabs( cg ) ) );
				}
			float scale = 1.0f;
			while ( scale < 8.0f && maxChroma * ( scale * 2.0f ) <= 127.0f ) scale *= 2.0f;
			for ( int y = 0; y < 4 && blockY + y < imageHeight; ++y )
				for ( int x = 0; x < 4 && blockX + x < imageWidth; ++x ) {
					const unsigned char * pixel = input + ( blockY + y ) * sourcePitch + ( blockX + x ) * 4;
					unsigned char * target = &ycocg[( ( blockY + y ) * imageWidth + blockX + x ) * 4];
					const float co = ( static_cast< float >( pixel[0] ) - pixel[2] ) * 0.5f;
					const float cg = ( -static_cast< float >( pixel[0] ) + 2.0f * pixel[1] - pixel[2] ) * 0.25f;
					const float luminance = ( pixel[0] + 2.0f * pixel[1] + pixel[2] ) * 0.25f;
					target[0] = static_cast< unsigned char >( (std::max)( 0.0f, (std::min)( 255.0f, 128.0f + co * scale ) ) );
					target[1] = static_cast< unsigned char >( (std::max)( 0.0f, (std::min)( 255.0f, 128.0f + cg * scale ) ) );
					target[2] = static_cast< unsigned char >( ( scale - 1.0f ) * 8.0f );
					target[3] = static_cast< unsigned char >( luminance );
				}
		}
	}
	const int savedPadding = srcPadding;
	srcPadding = 0;
	CompressImageDXT5HQ( ycocg.data(), output, imageWidth, imageHeight );
	srcPadding = savedPadding;
}
