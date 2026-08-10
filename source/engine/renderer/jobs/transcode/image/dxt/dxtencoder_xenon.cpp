#include "dxtcodec.h"

// The 360 implementation used VMX128 block selectors.  These compatibility
// entry points intentionally keep their PDB-visible names and use the same
// BC bitstream through the portable encoder on Windows/D3D9.
void idDxtEncoder::CompressImageDXT1Fast_Xenon( const unsigned char * input,
		unsigned char * output, int imageWidth, int imageHeight ) {
	CompressImageDXT1HQ( input, output, imageWidth, imageHeight );
}

void idDxtEncoder::CompressImageDXT1AlphaFast_Xenon( const unsigned char * input,
		unsigned char * output, int imageWidth, int imageHeight ) {
	CompressImageDXT1AlphaHQ( input, output, imageWidth, imageHeight );
}

void idDxtEncoder::CompressImageDXT5Fast_Xenon( const unsigned char * input,
		unsigned char * output, int imageWidth, int imageHeight ) {
	CompressImageDXT5HQ( input, output, imageWidth, imageHeight );
}

void idDxtEncoder::CompressYCoCgDXT5Fast_Xenon( const unsigned char * input,
		unsigned char * output, int imageWidth, int imageHeight ) {
	CompressYCoCgAlphaDXT5Fast( input, output, imageWidth, imageHeight );
}

void idDxtEncoder::CompressNormalMapDXT5Fast_Xenon( const unsigned char * input,
		unsigned char * output, int imageWidth, int imageHeight ) {
	CompressNormalMapDXT5HQ( input, output, imageWidth, imageHeight );
}
