#include "barehdp.h"

#include "../photocodec_compat.h"

#include <algorithm>
#include <cstring>

idBareHDP::idBareHDP() : quality( 90 ), tempBuffer( nullptr ),
	tempBufferSize( 0 ), tempBufferUsed( 0 ), imageROILeftX( 0 ),
	imageROITopY( 0 ), imageROIWidth( 0 ), imageROIHeight( 0 ),
	imageByteStride( 0 ), codec( nullptr ), portableState( nullptr ) {
	std::memset( streamTemp, 0, sizeof( streamTemp ) );
}
idBareHDP::~idBareHDP() { TerminateMacroBlockRowDecoding(); }

int idBareHDP::EstimateTempMemory( const int width, const int height,
		const int channels, const int mipLevel ) {
	const int scale = 1 << (std::max)( 0, (std::min)( mipLevel, 12 ) );
	return (std::max)( width / scale, 1 ) * (std::max)( height / scale, 1 ) *
		(std::max)( channels, 1 ) + 4096;
}
namespace {
	bool Encode( idBareHDP & self, const unsigned char * input,
			unsigned char * output, const int capacity, const int width,
			const int height, int & bytes, const portablePhotoPixels_t pixels ) {
		return PortablePhotoEncode( input, output, capacity, width, height, bytes,
			pixels, RENDERER_WIC_JPEG_XR, self.quality );
	}
	bool Decode( const unsigned char * input, unsigned char * output,
			const int width, const int height, const int bytes, const int mip,
			const portablePhotoPixels_t pixels ) {
		return PortablePhotoDecode( input, bytes, output, width, height, mip, pixels );
	}
}

#define HDP_ENCODE(name, pixels) \
bool idBareHDP::name( const unsigned char * i, unsigned char * o, int c, int w, int h, int & b ) { \
	return Encode( *this, i, o, c, w, h, b, pixels ); }
HDP_ENCODE( CompressImageMono, PORTABLE_PHOTO_MONO )
HDP_ENCODE( CompressImageGrayScale, PORTABLE_PHOTO_RGBA )
HDP_ENCODE( CompressImageRGB, PORTABLE_PHOTO_RGBA )
HDP_ENCODE( CompressImageYCoCg, PORTABLE_PHOTO_RGBA )
HDP_ENCODE( CompressImageNormalMap, PORTABLE_PHOTO_RGBA )
#undef HDP_ENCODE

#define HDP_DECODE(name, pixels) \
bool idBareHDP::name( const unsigned char * i, unsigned char * o, int w, int h, int b, int m ) { \
	return Decode( i, o, w, h, b, m, pixels ); }
HDP_DECODE( DecompressImageMono, PORTABLE_PHOTO_MONO )
HDP_DECODE( DecompressImageGrayScale, PORTABLE_PHOTO_RGBA )
HDP_DECODE( DecompressImageRGB, PORTABLE_PHOTO_RGBA )
HDP_DECODE( DecompressImageYCoCg, PORTABLE_PHOTO_RGBA )
HDP_DECODE( DecompressImageNormalMap, PORTABLE_PHOTO_RGBA )
#undef HDP_DECODE

namespace {
	void Begin( idBareHDP & self, const unsigned char * input, const int width,
			const int height, const int bytes ) {
		self.TerminateMacroBlockRowDecoding();
		self.portableState = PortablePhotoBeginDecode( input, bytes, width, height );
		self.imageROIWidth = width;
		self.imageROIHeight = height;
	}
}
void idBareHDP::BeginDecompressImageGrayScale( const unsigned char * i, int w, int h, int b ) { Begin( *this, i, w, h, b ); }
void idBareHDP::BeginDecompressImageRGB( const unsigned char * i, int w, int h, int b ) { Begin( *this, i, w, h, b ); }
void idBareHDP::BeginDecompressImageYCoCg( const unsigned char * i, int w, int h, int b ) { Begin( *this, i, w, h, b ); }
void idBareHDP::BeginDecompressImageNormalMap( const unsigned char * i, int w, int h, int b ) { Begin( *this, i, w, h, b ); }
void idBareHDP::BeginDecompressImageYCoCgMacroBlockRow() {}
void idBareHDP::DecompressImageGrayScaleMacroBlock( unsigned char * o, int n, int s ) { PortablePhotoCopyMacroBlock( static_cast< portablePhotoDecodeState_t * >( portableState ), o, n, s, PORTABLE_PHOTO_RGBA ); }
void idBareHDP::DecompressImageRGBMacroBlock( unsigned char * o, int n, int s ) { PortablePhotoCopyMacroBlock( static_cast< portablePhotoDecodeState_t * >( portableState ), o, n, s, PORTABLE_PHOTO_RGBA ); }
void idBareHDP::DecompressImageYCoCgMacroBlock( unsigned char * o, int n, int s ) { PortablePhotoCopyMacroBlock( static_cast< portablePhotoDecodeState_t * >( portableState ), o, n, s, PORTABLE_PHOTO_RGBA ); }
void idBareHDP::DecompressImageNormalMapMacroBlock( unsigned char * o, int n, int s ) { PortablePhotoCopyMacroBlock( static_cast< portablePhotoDecodeState_t * >( portableState ), o, n, s, PORTABLE_PHOTO_RGBA ); }
void idBareHDP::TerminateMacroBlockRowDecoding() {
	PortablePhotoEndDecode( static_cast< portablePhotoDecodeState_t * >( portableState ) );
	portableState = nullptr;
}
