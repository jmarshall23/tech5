#include "../jobs/transcode/image/photocodec_compat.h"

#include <algorithm>
#include <cmath>

namespace {
	void FindQuality( const unsigned char * input, const int inputBytes,
			unsigned char * output, const int outputCapacity, const int targetBytes,
			const rendererWICContainer_t container ) {
		if ( input == nullptr || output == nullptr || inputBytes < 4 || outputCapacity <= 0 ) return;
		const int pixels = inputBytes / 4;
		const int width = static_cast< int >( std::sqrt( static_cast< double >( pixels ) ) );
		const int height = width > 0 ? pixels / width : 0;
		int low = 1, high = 100, selected = 1;
		for ( int iteration = 0; iteration < 7; ++iteration ) {
			const int quality = ( low + high ) / 2;
			int bytes = 0;
			if ( PortablePhotoEncode( input, output, outputCapacity, width, height,
				bytes, PORTABLE_PHOTO_RGBA, container, quality ) && bytes <= targetBytes ) {
				selected = quality; low = quality + 1;
			} else high = quality - 1;
		}
		int ignored = 0;
		PortablePhotoEncode( input, output, outputCapacity, width, height, ignored,
			PORTABLE_PHOTO_RGBA, container, selected );
	}
}

void FindDCTQualityForSize( const unsigned char * i, int n, unsigned char * o, int c, int target ) { FindQuality( i, n, o, c, target, RENDERER_WIC_JPEG ); }
void FindDCTQualityForRatio( const unsigned char * i, int n, unsigned char * o, int c, int ratio ) { FindQuality( i, n, o, c, n / (std::max)( ratio, 1 ), RENDERER_WIC_JPEG ); }
void FindHDPQualityForSize( const unsigned char * i, int n, unsigned char * o, int c, int target ) { FindQuality( i, n, o, c, target, RENDERER_WIC_JPEG_XR ); }
void FindHDPQualityForRatio( const unsigned char * i, int n, unsigned char * o, int c, int ratio ) { FindQuality( i, n, o, c, n / (std::max)( ratio, 1 ), RENDERER_WIC_JPEG_XR ); }
void FindJXRQualityForSize( const unsigned char * i, int n, unsigned char * o, int c, int target ) { FindQuality( i, n, o, c, target, RENDERER_WIC_JPEG_XR ); }
void FindJXRQualityForRatio( const unsigned char * i, int n, unsigned char * o, int c, int ratio ) { FindQuality( i, n, o, c, n / (std::max)( ratio, 1 ), RENDERER_WIC_JPEG_XR ); }
