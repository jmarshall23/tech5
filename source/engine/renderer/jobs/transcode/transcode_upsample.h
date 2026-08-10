#pragma once

#include <algorithm>
#include <cmath>
#include <cstring>

// Portable replacement for the recovered VMX128 16x16 tile kernel.  The long
// signature is retained because the specialized retail jobs passed their
// precomputed cubic coefficients as individual arguments.
inline void UpSample16x16_Bicubic( unsigned char * dst, unsigned int dstX,
		unsigned int dstY, unsigned int dstBytePitch, const unsigned char * src,
		unsigned int srcX, unsigned int srcY, unsigned int srcMaskY, int upsampleLevel,
		int sharpenScale, int noiseScale, int, int, unsigned int, int, unsigned int,
		int, unsigned int, int, int, int, unsigned int, int, unsigned int, int, int,
		int, int, int, int, int, int ) {
	if ( dst == nullptr || src == nullptr || dstBytePitch == 0 ) return;
	const int scale = 1 << (std::max)( 0, (std::min)( upsampleLevel, 12 ) );
	for ( int y = 0; y < 16; ++y ) for ( int x = 0; x < 16; ++x ) {
		const float fx = srcX + ( dstX + x + 0.5f ) / scale - 0.5f;
		const float fy = srcY + ( dstY + y + 0.5f ) / scale - 0.5f;
		const int x0 = static_cast< int >( std::floor( fx ) );
		const int y0 = static_cast< int >( std::floor( fy ) );
		const float tx = fx - x0, ty = fy - y0;
		for ( int channel = 0; channel < 4; ++channel ) {
			float value = 0.0f;
			for ( int yy = 0; yy < 2; ++yy ) for ( int xx = 0; xx < 2; ++xx ) {
				const int sx = (std::max)( 0, (std::min)( 127, x0 + xx ) );
				const int sy = ( y0 + yy ) & static_cast< int >( srcMaskY );
				const float weight = ( xx ? tx : 1.0f - tx ) * ( yy ? ty : 1.0f - ty );
				value += src[( sy * 128 + sx ) * 4 + channel] * weight;
			}
			if ( sharpenScale != 0 && channel < 3 ) value += ( value - 128.0f ) * sharpenScale / 65535.0f;
			if ( noiseScale != 0 && channel < 3 ) {
				unsigned int hash = ( dstX + x ) * 1664525u + ( dstY + y ) * 1013904223u + channel;
				value += static_cast< int >( hash >> 24 ) * noiseScale / ( 255.0f * 65535.0f );
			}
			dst[( dstY + y ) * dstBytePitch + ( dstX + x ) * 4 + channel] =
				static_cast< unsigned char >( (std::max)( 0.0f, (std::min)( 255.0f, value ) ) );
		}
	}
}

#define TRANSCODE_UPSAMPLE_ALIAS( suffix ) \
	template< typename... args_t > inline void UpSample16x16_Bicubic_##suffix( args_t... args ) { UpSample16x16_Bicubic( args... ); }
TRANSCODE_UPSAMPLE_ALIAS( 0 )
TRANSCODE_UPSAMPLE_ALIAS( 1 )
TRANSCODE_UPSAMPLE_ALIAS( 2 )
TRANSCODE_UPSAMPLE_ALIAS( 3 )
#undef TRANSCODE_UPSAMPLE_ALIAS
