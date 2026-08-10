#include "mipmap.h"

#include <algorithm>

bool idMipMap::CreateSingleMipMultiChannel( const unsigned char * source,
	const int width, const int height, const int channels,
	unsigned char * destination ) {
	if ( source == nullptr || destination == nullptr || width < 1 || height < 1
		|| channels < 1 || ( width == 1 && height == 1 ) ) return false;
	const int outputWidth = (std::max)( width >> 1, 1 );
	const int outputHeight = (std::max)( height >> 1, 1 );
	for ( int y = 0; y < outputHeight; ++y ) {
		const int y0 = (std::min)( y * 2, height - 1 );
		const int y1 = (std::min)( y0 + 1, height - 1 );
		for ( int x = 0; x < outputWidth; ++x ) {
			const int x0 = (std::min)( x * 2, width - 1 );
			const int x1 = (std::min)( x0 + 1, width - 1 );
			for ( int channel = 0; channel < channels; ++channel ) {
				const int a = source[( y0 * width + x0 ) * channels + channel];
				const int b = source[( y0 * width + x1 ) * channels + channel];
				const int c = source[( y1 * width + x0 ) * channels + channel];
				const int d = source[( y1 * width + x1 ) * channels + channel];
				destination[( y * outputWidth + x ) * channels + channel] =
					static_cast< unsigned char >( ( a + b + c + d ) >> 2 );
			}
		}
	}
	return true;
}

bool idMipMap::CreateSingleMip( const unsigned char * source,
	const int width, const int height, unsigned char * destination ) {
	return CreateSingleMipMultiChannel( source, width, height, 4, destination );
}
