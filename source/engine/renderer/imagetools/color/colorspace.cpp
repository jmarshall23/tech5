#include "colorspace.h"

#include <algorithm>

namespace {
	unsigned char ClampByte( const int value ) {
		return static_cast< unsigned char >( (std::max)( 0, (std::min)( value, 255 ) ) );
	}
}

void idColorSpace::ConvertRGBToCoCg_Y( unsigned char * destination,
	const unsigned char * source, const int width, const int height ) {
	if ( destination == nullptr || source == nullptr ) return;
	for ( int pixel = 0; pixel < width * height; ++pixel ) {
		const int red = source[pixel * 4 + 0];
		const int green = source[pixel * 4 + 1];
		const int blue = source[pixel * 4 + 2];
		destination[pixel * 4 + 0] = ClampByte( ( 2 * ( red + 1 ) - 2 * blue ) / 4 + 128 );
		destination[pixel * 4 + 1] = ClampByte( ( 2 * green - blue - red + 2 ) / 4 + 128 );
		destination[pixel * 4 + 2] = 0;
		destination[pixel * 4 + 3] = ClampByte( ( 2 * green + blue + red + 2 ) / 4 );
	}
}

void idColorSpace::ConvertCoCg_YToRGB( unsigned char * destination,
	const unsigned char * source, const int width, const int height ) {
	if ( destination == nullptr || source == nullptr ) return;
	for ( int pixel = 0; pixel < width * height; ++pixel ) {
		const int co = source[pixel * 4 + 0] - 128;
		const int cg = source[pixel * 4 + 1] - 128;
		const int y = source[pixel * 4 + 3];
		destination[pixel * 4 + 0] = ClampByte( y - cg + co );
		destination[pixel * 4 + 1] = ClampByte( y + cg );
		destination[pixel * 4 + 2] = ClampByte( y - cg - co );
		destination[pixel * 4 + 3] = source[pixel * 4 + 2];
	}
}
