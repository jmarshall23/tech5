#include "barejxr.h"

#include "../photocodec_compat.h"

#include <algorithm>

idBareJXR::idBareJXR() : quality( 90 ), tempBuffer( nullptr ), tempBufferSize( 0 ),
	tempBufferUsed( 0 ), cROILeftX( 0 ), cROITopY( 0 ), cROIWidth( 0 ),
	cROIHeight( 0 ), portableState( nullptr ) {}
idBareJXR::~idBareJXR() { PortablePhotoEndDecode(
	static_cast< portablePhotoDecodeState_t * >( portableState ) ); }

int idBareJXR::EstimateTempMemory( const int width, const int height,
		const int channels, const int mipLevel ) {
	const int scale = 1 << (std::max)( 0, (std::min)( mipLevel, 12 ) );
	return (std::max)( width / scale, 1 ) * (std::max)( height / scale, 1 ) *
		(std::max)( channels, 1 ) + 4096;
}

namespace {
	bool Encode( idBareJXR & self, const unsigned char * input,
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
#define JXR_ENCODE(name, pixels) \
bool idBareJXR::name( const unsigned char * i, unsigned char * o, int c, int w, int h, int & b ) { \
	return Encode( *this, i, o, c, w, h, b, pixels ); }
JXR_ENCODE( CompressImageMono, PORTABLE_PHOTO_MONO )
JXR_ENCODE( CompressImageGrayScale, PORTABLE_PHOTO_RGBA )
JXR_ENCODE( CompressImageRGB, PORTABLE_PHOTO_RGBA )
JXR_ENCODE( CompressImageYCoCg, PORTABLE_PHOTO_RGBA )
JXR_ENCODE( CompressImageNormalMap, PORTABLE_PHOTO_RGBA )
#undef JXR_ENCODE
#define JXR_DECODE(name, pixels) \
bool idBareJXR::name( const unsigned char * i, unsigned char * o, int w, int h, int b, int m ) { \
	return Decode( i, o, w, h, b, m, pixels ); }
JXR_DECODE( DecompressImageMono, PORTABLE_PHOTO_MONO )
JXR_DECODE( DecompressImageGrayScale, PORTABLE_PHOTO_RGBA )
JXR_DECODE( DecompressImageRGB, PORTABLE_PHOTO_RGBA )
JXR_DECODE( DecompressImageYCoCg, PORTABLE_PHOTO_RGBA )
JXR_DECODE( DecompressImageNormalMap, PORTABLE_PHOTO_RGBA )
#undef JXR_DECODE

namespace {
	void Begin( idBareJXR & self, const unsigned char * input, const int width,
			const int height, const int bytes ) {
		PortablePhotoEndDecode( static_cast< portablePhotoDecodeState_t * >( self.portableState ) );
		self.portableState = PortablePhotoBeginDecode( input, bytes, width, height );
		self.cROIWidth = width;
		self.cROIHeight = height;
	}
}
void idBareJXR::BeginDecompressImageGrayScale( const unsigned char * i, int w, int h, int b ) { Begin( *this, i, w, h, b ); }
void idBareJXR::BeginDecompressImageRGB( const unsigned char * i, int w, int h, int b ) { Begin( *this, i, w, h, b ); }
void idBareJXR::BeginDecompressImageYCoCg( const unsigned char * i, int w, int h, int b ) { Begin( *this, i, w, h, b ); }
void idBareJXR::BeginDecompressImageNormalMap( const unsigned char * i, int w, int h, int b ) { Begin( *this, i, w, h, b ); }
void idBareJXR::BeginDecompressImageGrayScaleMacroBlockRow() {}
void idBareJXR::DecompressImageGrayScaleMacroBlock( unsigned char * o, int n, int s ) { PortablePhotoCopyMacroBlock( static_cast< portablePhotoDecodeState_t * >( portableState ), o, n, s, PORTABLE_PHOTO_RGBA ); }
void idBareJXR::DecompressImageRGBMacroBlock( unsigned char * o, int n, int s ) { PortablePhotoCopyMacroBlock( static_cast< portablePhotoDecodeState_t * >( portableState ), o, n, s, PORTABLE_PHOTO_RGBA ); }
void idBareJXR::DecompressImageYCoCgMacroBlock( unsigned char * o, int n, int s ) { PortablePhotoCopyMacroBlock( static_cast< portablePhotoDecodeState_t * >( portableState ), o, n, s, PORTABLE_PHOTO_RGBA ); }
void idBareJXR::DecompressImageNormalMapMacroBlock( unsigned char * o, int n, int s ) { PortablePhotoCopyMacroBlock( static_cast< portablePhotoDecodeState_t * >( portableState ), o, n, s, PORTABLE_PHOTO_RGBA ); }
