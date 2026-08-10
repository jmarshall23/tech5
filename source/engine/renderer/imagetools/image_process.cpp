#include "imageprocess.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <new>

unsigned char * R_ResampleTexture( const unsigned char * input,
		const int inputWidth, const int inputHeight, const int outputWidth,
		const int outputHeight ) {
	if ( input == nullptr || inputWidth <= 0 || inputHeight <= 0 ||
			outputWidth <= 0 || outputHeight <= 0 ) return nullptr;
	unsigned char * output = new ( std::nothrow ) unsigned char[
		static_cast< std::size_t >( outputWidth ) * outputHeight * 4];
	if ( output == nullptr ) return nullptr;
	for ( int y = 0; y < outputHeight; ++y ) {
		const float sourceY = ( y + 0.5f ) * inputHeight / outputHeight - 0.5f;
		const int y0 = (std::max)( 0, (std::min)( inputHeight - 1, static_cast< int >( std::floor( sourceY ) ) ) );
		const int y1 = (std::min)( y0 + 1, inputHeight - 1 );
		const float fy = (std::max)( 0.0f, sourceY - std::floor( sourceY ) );
		for ( int x = 0; x < outputWidth; ++x ) {
			const float sourceX = ( x + 0.5f ) * inputWidth / outputWidth - 0.5f;
			const int x0 = (std::max)( 0, (std::min)( inputWidth - 1, static_cast< int >( std::floor( sourceX ) ) ) );
			const int x1 = (std::min)( x0 + 1, inputWidth - 1 );
			const float fx = (std::max)( 0.0f, sourceX - std::floor( sourceX ) );
			for ( int component = 0; component < 4; ++component ) {
				const float top = input[( y0 * inputWidth + x0 ) * 4 + component] * ( 1.0f - fx ) +
					input[( y0 * inputWidth + x1 ) * 4 + component] * fx;
				const float bottom = input[( y1 * inputWidth + x0 ) * 4 + component] * ( 1.0f - fx ) +
					input[( y1 * inputWidth + x1 ) * 4 + component] * fx;
				output[( y * outputWidth + x ) * 4 + component] =
					static_cast< unsigned char >( top * ( 1.0f - fy ) + bottom * fy + 0.5f );
			}
		}
	}
	return output;
}

unsigned char * R_Dropsample( const unsigned char * input, int inputWidth,
		int inputHeight, int outputWidth, int outputHeight ) {
	if ( input == nullptr || inputWidth <= 0 || inputHeight <= 0 || outputWidth <= 0 || outputHeight <= 0 ) return nullptr;
	unsigned char * output = new ( std::nothrow ) unsigned char[
		static_cast< std::size_t >( outputWidth ) * outputHeight * 4];
	if ( output == nullptr ) return nullptr;
	for ( int y = 0; y < outputHeight; ++y ) for ( int x = 0; x < outputWidth; ++x ) {
		const int sourceX = (std::min)( inputWidth - 1, x * inputWidth / outputWidth );
		const int sourceY = (std::min)( inputHeight - 1, y * inputHeight / outputHeight );
		std::memcpy( output + ( y * outputWidth + x ) * 4,
			input + ( sourceY * inputWidth + sourceX ) * 4, 4 );
	}
	return output;
}

unsigned char * R_MipMap( const unsigned char * input, int width, int height ) {
	if ( input == nullptr || width <= 0 || height <= 0 ) return nullptr;
	const int outputWidth = (std::max)( width >> 1, 1 );
	const int outputHeight = (std::max)( height >> 1, 1 );
	unsigned char * output = new ( std::nothrow ) unsigned char[
		static_cast< std::size_t >( outputWidth ) * outputHeight * 4];
	if ( output == nullptr ) return nullptr;
	for ( int y = 0; y < outputHeight; ++y ) for ( int x = 0; x < outputWidth; ++x ) {
		for ( int component = 0; component < 4; ++component ) {
			int total = 0;
			for ( int dy = 0; dy < 2; ++dy ) for ( int dx = 0; dx < 2; ++dx )
				total += input[( (std::min)( y * 2 + dy, height - 1 ) * width +
					(std::min)( x * 2 + dx, width - 1 ) ) * 4 + component];
			output[( y * outputWidth + x ) * 4 + component] = static_cast< unsigned char >( ( total + 2 ) >> 2 );
		}
	}
	return output;
}

void R_HorizontalFlip( unsigned char * data, int width, int height ) {
	if ( data == nullptr ) return;
	for ( int y = 0; y < height; ++y ) for ( int x = 0; x < width / 2; ++x )
		for ( int component = 0; component < 4; ++component ) std::swap(
			data[( y * width + x ) * 4 + component],
			data[( y * width + width - 1 - x ) * 4 + component] );
}

void R_VerticalFlip( unsigned char * data, int width, int height ) {
	if ( data == nullptr ) return;
	for ( int y = 0; y < height / 2; ++y ) for ( int x = 0; x < width; ++x )
		for ( int component = 0; component < 4; ++component ) std::swap(
			data[( y * width + x ) * 4 + component],
			data[( ( height - 1 - y ) * width + x ) * 4 + component] );
}

void R_RotatePic( unsigned char * data, int width ) {
	if ( data == nullptr || width <= 0 ) return;
	unsigned char * copy = new unsigned char[static_cast< std::size_t >( width ) * width * 4];
	std::memcpy( copy, data, static_cast< std::size_t >( width ) * width * 4 );
	for ( int y = 0; y < width; ++y ) for ( int x = 0; x < width; ++x )
		std::memcpy( data + ( y * width + x ) * 4,
			copy + ( ( width - 1 - x ) * width + y ) * 4, 4 );
	delete[] copy;
}

void R_SetAlphaNormalDivergence( unsigned char * data, int width, int height ) {
	if ( data == nullptr ) return;
	for ( int pixel = 0; pixel < width * height; ++pixel ) {
		const float nx = data[pixel * 4 + 0] * ( 2.0f / 255.0f ) - 1.0f;
		const float ny = data[pixel * 4 + 1] * ( 2.0f / 255.0f ) - 1.0f;
		const float nz = data[pixel * 4 + 2] * ( 2.0f / 255.0f ) - 1.0f;
		const float length = std::sqrt( nx * nx + ny * ny + nz * nz );
		data[pixel * 4 + 3] = static_cast< unsigned char >(
			(std::max)( 0.0f, (std::min)( 255.0f, length * 255.0f ) ) );
	}
}

void R_BlendCubeBorders( unsigned char * faces[6], int size ) {
	if ( faces == nullptr || size <= 1 ) return;
	// Average all corners across the three faces meeting there.  Edge filtering
	// remains face-local, avoiding the 360 tiled-address assumptions.
	for ( int corner = 0; corner < 4; ++corner ) {
		const int x = ( corner & 1 ) != 0 ? size - 1 : 0;
		const int y = ( corner & 2 ) != 0 ? size - 1 : 0;
		for ( int component = 0; component < 4; ++component ) {
			int total = 0, count = 0;
			for ( int face = 0; face < 6; ++face ) if ( faces[face] != nullptr ) {
				total += faces[face][( y * size + x ) * 4 + component]; ++count;
			}
			for ( int face = 0; face < 6; ++face ) if ( faces[face] != nullptr )
				faces[face][( y * size + x ) * 4 + component] = static_cast< unsigned char >( total / (std::max)( count, 1 ) );
		}
	}
}

void R_FilterCube( unsigned char * faces[6], int size ) {
	if ( faces == nullptr ) return;
	for ( int face = 0; face < 6; ++face ) {
		if ( faces[face] == nullptr ) continue;
		unsigned char * filtered = R_ResampleTexture( faces[face], size, size, size, size );
		if ( filtered != nullptr ) { std::memcpy( faces[face], filtered, static_cast< std::size_t >( size ) * size * 4 ); delete[] filtered; }
	}
	R_BlendCubeBorders( faces, size );
}
