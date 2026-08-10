#pragma once

#include <algorithm>

inline void DecompressCover16x16( const unsigned char * cover, int tileX, int tileY,
		unsigned char * rgba, int byteStride ) {
	if ( cover == nullptr || rgba == nullptr || byteStride < 64 ) return;
	const int originX = tileX * 16;
	const int originY = tileY * 16;
	for ( int y = 0; y < 16; ++y ) for ( int x = 0; x < 16; ++x ) {
		const int pixel = ( originY + y ) * 128 + originX + x;
		rgba[y * byteStride + x * 4 + 3] = ( cover[pixel >> 3] & ( 1u << ( pixel & 7 ) ) ) != 0 ? 255 : 0;
	}
}

inline void DynamicScaleSpecular16x16( unsigned char * specularScale, int tileX,
		int tileY, unsigned char * rgba ) {
	if ( specularScale == nullptr || rgba == nullptr ) return;
	for ( int y = 0; y < 16; ++y ) for ( int x = 0; x < 16; ++x ) {
		const int sx = ( tileX * 16 + x ) >> 2;
		const int sy = ( tileY * 16 + y ) >> 2;
		const unsigned int scale = specularScale[sy * 32 + sx];
		unsigned char * pixel = rgba + ( y * 16 + x ) * 4;
		pixel[0] = static_cast< unsigned char >( (std::min)( 255u, pixel[0] * scale / 255u ) );
		pixel[1] = static_cast< unsigned char >( (std::min)( 255u, pixel[1] * scale / 255u ) );
		pixel[2] = static_cast< unsigned char >( (std::min)( 255u, pixel[2] * scale / 255u ) );
	}
}

inline void ConstantScaleSpecular16x16( unsigned char * specularScale, int tileX,
		int tileY, unsigned char * rgba, unsigned char specularShift,
		int, int, int, int, int, int, int, int, int, int, int, int, int, int,
		unsigned char ) {
	if ( specularScale == nullptr ) return;
	const int shift = (std::min)( static_cast< int >( specularShift ), 5 );
	const unsigned char value = static_cast< unsigned char >(
		(std::min)( 255, 8 * ( ( 1 << shift ) - 1 ) ) );
	for ( int y = 0; y < 4; ++y ) for ( int x = 0; x < 4; ++x )
		specularScale[( tileY * 4 + y ) * 32 + tileX * 4 + x] = value;
	DynamicScaleSpecular16x16( specularScale, tileX, tileY, rgba );
}

#define TRANSCODE_SUPPORT_ALIAS( suffix ) \
	inline void DecompressCover16x16_##suffix( const unsigned char * c, int x, int y, unsigned char * p, int s ) { DecompressCover16x16( c, x, y, p, s ); } \
	inline void DynamicScaleSpecular16x16_##suffix( unsigned char * q, int x, int y, unsigned char * p ) { DynamicScaleSpecular16x16( q, x, y, p ); } \
	inline void ConstantScaleSpecular16x16_##suffix( unsigned char * q, int x, int y, unsigned char * p, unsigned char s, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, unsigned char a20 ) { ConstantScaleSpecular16x16( q, x, y, p, s, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20 ); }

TRANSCODE_SUPPORT_ALIAS( 0 )
TRANSCODE_SUPPORT_ALIAS( 1 )
TRANSCODE_SUPPORT_ALIAS( 2 )
TRANSCODE_SUPPORT_ALIAS( 3 )
TRANSCODE_SUPPORT_ALIAS( 4 )

#undef TRANSCODE_SUPPORT_ALIAS
