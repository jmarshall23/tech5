#include "baredct.h"

#include "../photocodec_compat.h"

namespace {
	bool DecodeDCT( const unsigned char * input, unsigned char * output,
			const int width, const int inputBytes, const int mipLevel,
			const portablePhotoPixels_t pixels ) {
		return PortablePhotoDecode( input, inputBytes, output, width, width,
			mipLevel, pixels );
	}
}

bool idBareDctDecoder::DecompressImageMono_Xenon( const unsigned char * input,
		unsigned char * output, const int width, const int inputBytes, const int mipLevel ) {
	return DecodeDCT( input, output, width, inputBytes, mipLevel, PORTABLE_PHOTO_MONO );
}
bool idBareDctDecoder::DecompressImageGrayScale_Xenon( const unsigned char * input,
		unsigned char * output, const int width, const int inputBytes, const int mipLevel ) {
	return DecodeDCT( input, output, width, inputBytes, mipLevel, PORTABLE_PHOTO_RGBA );
}
bool idBareDctDecoder::DecompressImageRGB_Xenon( const unsigned char * input,
		unsigned char * output, const int width, const int inputBytes, const int mipLevel ) {
	return DecodeDCT( input, output, width, inputBytes, mipLevel, PORTABLE_PHOTO_RGBA );
}
bool idBareDctDecoder::DecompressImageYCoCg_Xenon( const unsigned char * input,
		unsigned char * output, const int width, const int inputBytes, const int mipLevel ) {
	return DecodeDCT( input, output, width, inputBytes, mipLevel, PORTABLE_PHOTO_RGBA );
}
bool idBareDctDecoder::DecompressImageNormalMap_Xenon( const unsigned char * input,
		unsigned char * output, const int width, const int inputBytes, const int mipLevel ) {
	return DecodeDCT( input, output, width, inputBytes, mipLevel, PORTABLE_PHOTO_RGBA );
}

