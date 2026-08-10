#pragma once

#include <cstdint>

struct hdpCodec_t;

// HD Photo was the 360-era name for JPEG XR.  Windows Imaging Component is
// the native PC implementation, while this facade preserves the recovered
// renderer API and its macroblock streaming entrypoints.
class idBareHDP {
public:
	idBareHDP();
	~idBareHDP();
	static int EstimateTempMemory( int width, int height, int channels, int mipLevel );

	bool CompressImageMono( const unsigned char *, unsigned char *, int,
		int, int, int & );
	bool CompressImageGrayScale( const unsigned char *, unsigned char *, int,
		int, int, int & );
	bool CompressImageRGB( const unsigned char *, unsigned char *, int,
		int, int, int & );
	bool CompressImageYCoCg( const unsigned char *, unsigned char *, int,
		int, int, int & );
	bool CompressImageNormalMap( const unsigned char *, unsigned char *, int,
		int, int, int & );

	bool DecompressImageMono( const unsigned char *, unsigned char *, int,
		int, int, int );
	bool DecompressImageGrayScale( const unsigned char *, unsigned char *, int,
		int, int, int );
	bool DecompressImageRGB( const unsigned char *, unsigned char *, int,
		int, int, int );
	bool DecompressImageYCoCg( const unsigned char *, unsigned char *, int,
		int, int, int );
	bool DecompressImageNormalMap( const unsigned char *, unsigned char *, int,
		int, int, int );

	void BeginDecompressImageGrayScale( const unsigned char *, int, int, int );
	void BeginDecompressImageRGB( const unsigned char *, int, int, int );
	void BeginDecompressImageYCoCg( const unsigned char *, int, int, int );
	void BeginDecompressImageNormalMap( const unsigned char *, int, int, int );
	void BeginDecompressImageYCoCgMacroBlockRow();
	void DecompressImageGrayScaleMacroBlock( unsigned char *, int, int );
	void DecompressImageRGBMacroBlock( unsigned char *, int, int );
	void DecompressImageYCoCgMacroBlock( unsigned char *, int, int );
	void DecompressImageNormalMapMacroBlock( unsigned char *, int, int );
	void TerminateMacroBlockRowDecoding();

	int quality;
	void * tempBuffer;
	int tempBufferSize;
	int tempBufferUsed;
	int imageROILeftX;
	int imageROITopY;
	int imageROIWidth;
	int imageROIHeight;
	int imageByteStride;
	hdpCodec_t * codec;
	std::uint8_t streamTemp[128];
	void * portableState;
};
