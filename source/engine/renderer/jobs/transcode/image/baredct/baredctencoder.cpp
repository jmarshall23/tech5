#include "baredct.h"

#include "../photocodec_compat.h"

idBareDctEncoder::idBareDctEncoder() {}

namespace {
	bool EncodeDCT( idBareDctEncoder & encoder, const unsigned char * input,
			unsigned char * output, const int capacity, const int width,
			const int height, int & bytes, const portablePhotoPixels_t pixels,
			const bool flip = false ) {
		return PortablePhotoEncode( input, output, capacity, width, height, bytes,
			pixels, RENDERER_WIC_JPEG, encoder.luminanceQuality, flip );
	}
}

bool idBareDctEncoder::CompressImageMono_Generic( const unsigned char * input,
		unsigned char * output, const int capacity, const int width, const int height,
		int & bytes ) {
	return EncodeDCT( *this, input, output, capacity, width, height, bytes,
		PORTABLE_PHOTO_MONO );
}

bool idBareDctEncoder::CompressImageGrayScale_Generic( const unsigned char * input,
		unsigned char * output, const int capacity, const int width, const int height,
		int & bytes ) {
	return EncodeDCT( *this, input, output, capacity, width, height, bytes,
		PORTABLE_PHOTO_RGBA );
}

bool idBareDctEncoder::CompressImageRGB_Generic( const unsigned char * input,
		unsigned char * output, const int capacity, const int width, const int height,
		int & bytes ) {
	return EncodeDCT( *this, input, output, capacity, width, height, bytes,
		PORTABLE_PHOTO_RGBA );
}

bool idBareDctEncoder::CompressImageYCoCg_Generic( const unsigned char * input,
		unsigned char * output, const int capacity, const int width, const int height,
		int & bytes ) {
	return EncodeDCT( *this, input, output, capacity, width, height, bytes,
		PORTABLE_PHOTO_RGBA );
}

bool idBareDctEncoder::CompressImageNormalMap_Generic( const unsigned char * input,
		unsigned char * output, const int capacity, const int width, const int height,
		int & bytes ) {
	return EncodeDCT( *this, input, output, capacity, width, height, bytes,
		PORTABLE_PHOTO_RGBA );
}

bool idBareDctEncoder::CompressImageRGB_JPEG( const unsigned char * input,
		unsigned char * output, const int capacity, const int width, const int height,
		int & bytes, const bool flipVertical ) {
	return EncodeDCT( *this, input, output, capacity, width, height, bytes,
		PORTABLE_PHOTO_RGBA, flipVertical );
}

