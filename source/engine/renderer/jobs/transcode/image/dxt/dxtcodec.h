#pragma once

// Portable BC1/BC3 codec behind the recovered DXT class names.  The retail
// Xenon entry points are retained because page-transcode jobs name them
// directly, but on PC they dispatch to the scalar implementation.
class idDxtEncoder {
public:
	idDxtEncoder();

	void CompressImageDXT1HQ( const unsigned char * inData,
		unsigned char * output, int width, int height );
	void CompressImageDXT1AlphaHQ( const unsigned char * inData,
		unsigned char * output, int width, int height );
	void CompressImageDXT5HQ( const unsigned char * inData,
		unsigned char * output, int width, int height );
	void CompressNormalMapDXT5HQ( const unsigned char * inData,
		unsigned char * output, int width, int height );
	void CompressYCoCgAlphaDXT5Fast( const unsigned char * inData,
		unsigned char * output, int width, int height );

	void CompressImageDXT1Fast_Xenon( const unsigned char * inData,
		unsigned char * output, int width, int height );
	void CompressImageDXT1AlphaFast_Xenon( const unsigned char * inData,
		unsigned char * output, int width, int height );
	void CompressImageDXT5Fast_Xenon( const unsigned char * inData,
		unsigned char * output, int width, int height );
	void CompressYCoCgDXT5Fast_Xenon( const unsigned char * inData,
		unsigned char * output, int width, int height );
	void CompressNormalMapDXT5Fast_Xenon( const unsigned char * inData,
		unsigned char * output, int width, int height );

	int width;
	int height;
	unsigned char * outData;
	int srcPadding;
	int dstPadding;
};

class idDxtDecoder {
public:
	idDxtDecoder();

	void DecompressImageDXT1( const unsigned char * input,
		unsigned char * output, int width, int height );
	void DecompressImageDXT5( const unsigned char * input,
		unsigned char * output, int width, int height );
	void DecompressImageDXT5_nVidia7x( const unsigned char * input,
		unsigned char * output, int width, int height );
	void DecompressYCoCgDXT5( const unsigned char * input,
		unsigned char * output, int width, int height );

	int width;
	int height;
	const unsigned char * inData;
};
