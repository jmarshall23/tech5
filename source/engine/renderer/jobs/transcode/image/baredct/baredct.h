#pragma once

#include <cstdint>

enum sampleMode_t : int {
	SAMPLE_MODE_444 = 0,
	SAMPLE_MODE_420 = 1
};

class idBareDCTHuffmanTable;

// The table members retain the recovered layout.  The PC implementation uses
// Windows' JPEG codec at the public image boundary; the quantizers remain
// useful to tools which inspect or tune retail page qualities.
class idBareDctBase {
public:
	idBareDctBase();
	void SetQuality_Generic( int luminance, int chrominance, int alpha );
	void SetQuality_Xenon( int luminance, int chrominance, int alpha );
	static int QuantizationScaleFromQuality( int quality );
	static void ScaleQuantTable( std::uint16_t * destination,
		const std::uint16_t * source, int scale );
	static void ScaleQuantTable_Xenon( std::uint16_t * destination,
		const std::uint16_t * source, int scale );

	int luminanceQuality;
	int chrominanceQuality;
	int alphaQuality;
	sampleMode_t sampleMode;
	std::uint16_t quantTableY[64];
	std::uint16_t quantTableCoCg[64];
	std::uint16_t quantTableA[64];

protected:
	void InitQuantTable();
};

class idBareDctEncoder : public idBareDctBase {
public:
	idBareDctEncoder();
	bool CompressImageMono_Generic( const unsigned char * input,
		unsigned char * output, int outputCapacity, int width, int height,
		int & outputBytes );
	bool CompressImageGrayScale_Generic( const unsigned char * input,
		unsigned char * output, int outputCapacity, int width, int height,
		int & outputBytes );
	bool CompressImageRGB_Generic( const unsigned char * input,
		unsigned char * output, int outputCapacity, int width, int height,
		int & outputBytes );
	bool CompressImageYCoCg_Generic( const unsigned char * input,
		unsigned char * output, int outputCapacity, int width, int height,
		int & outputBytes );
	bool CompressImageNormalMap_Generic( const unsigned char * input,
		unsigned char * output, int outputCapacity, int width, int height,
		int & outputBytes );
	bool CompressImageRGB_JPEG( const unsigned char * input,
		unsigned char * output, int outputCapacity, int width, int height,
		int & outputBytes, bool flipVertical );
};

class idBareDctDecoder : public idBareDctBase {
public:
	idBareDctDecoder();
	void SetHuffmanTables( const idBareDCTHuffmanTable *,
		const idBareDCTHuffmanTable *, const idBareDCTHuffmanTable *,
		const idBareDCTHuffmanTable *, const idBareDCTHuffmanTable *,
		const idBareDCTHuffmanTable * );
	bool DecompressImageMono_Xenon( const unsigned char * input,
		unsigned char * output, int width, int inputBytes, int mipLevel = 0 );
	bool DecompressImageGrayScale_Xenon( const unsigned char * input,
		unsigned char * output, int width, int inputBytes, int mipLevel = 0 );
	bool DecompressImageRGB_Xenon( const unsigned char * input,
		unsigned char * output, int width, int inputBytes, int mipLevel = 0 );
	bool DecompressImageYCoCg_Xenon( const unsigned char * input,
		unsigned char * output, int width, int inputBytes, int mipLevel = 0 );
	bool DecompressImageNormalMap_Xenon( const unsigned char * input,
		unsigned char * output, int width, int inputBytes, int mipLevel = 0 );
};

void FDCT_AP922_float( const float * input, const std::uint16_t * quantTable,
	float * output );
void IDCT_AP922_float( const float * input, const std::uint16_t * quantTable,
	float * output );
void IDCT_AP922_float_Xenon( const float * input,
	const std::uint16_t * quantTable, float * output );

