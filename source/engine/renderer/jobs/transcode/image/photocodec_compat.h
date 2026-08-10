#pragma once

#include "wiccodec.h"

enum portablePhotoPixels_t {
	PORTABLE_PHOTO_MONO,
	PORTABLE_PHOTO_RGBA
};

bool PortablePhotoEncode( const unsigned char * input, unsigned char * output,
	int outputCapacity, int width, int height, int & outputBytes,
	portablePhotoPixels_t pixels, rendererWICContainer_t container,
	int quality, bool flipVertical = false );

bool PortablePhotoDecode( const unsigned char * input, int inputBytes,
	unsigned char * output, int width, int height, int mipLevel,
	portablePhotoPixels_t pixels );

struct portablePhotoDecodeState_t;
portablePhotoDecodeState_t * PortablePhotoBeginDecode(
	const unsigned char * input, int inputBytes, int width, int height );
void PortablePhotoEndDecode( portablePhotoDecodeState_t * state );
void PortablePhotoCopyMacroBlock( const portablePhotoDecodeState_t * state,
	unsigned char * output, int blockNumber, int byteStride,
	portablePhotoPixels_t pixels );

