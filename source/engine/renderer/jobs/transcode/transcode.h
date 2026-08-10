#pragma once

#include "pagecompression.h"

#include <cstddef>
#include <cstdint>

enum transcodeImageFlags_t : int {
	TRANSCODE_IMAGE_SPECULAR = 1,
	TRANSCODE_IMAGE_DIFFUSE = 2,
	TRANSCODE_IMAGE_NORMAL = 4
};

enum transcodeImageIndex_t : int {
	TRANSCODE_SPECULAR_INDEX = 0,
	TRANSCODE_DIFFUSE_INDEX = 1,
	TRANSCODE_NORMAL_INDEX = 2
};

struct transcodeParms_t {
	int imageFlags;
	int layoutVersion;
	int numLevels;
	int pageSource;
	int pageLevel;
	int pageX;
	int pageY;
	int physicalPageNum;
	pageCompression_t inPageCompression;
	pageCompression_t outPageCompression;
	int inPageDataLength;
	int outPageDataLength;
	int pageHeaderSize;
	int diskOffsetScale;
	int tempSize;
	int targetBytePitch[3];
	int upsampleX;
	int upsampleY;
	int upsampleLevel;
	int upsampleFilter;
	std::uint16_t upsampleSharpen;
	std::uint16_t upsampleNoise;
	volatile bool startedExecution;
	bool stripPageBorders;
	std::uint8_t reservedDebugBits : 3;
	std::uint8_t dbgShowPageBorders : 1;
	std::uint8_t dbgShowPageInfo : 1;
	std::uint8_t dbgShowPageNumbers : 1;
	std::uint8_t dbgShowPageColors : 1;
	std::uint8_t dbgShowPageSources : 1;
	std::uint8_t dbgShowPageMips;
	std::uint8_t dbgShowPageSizes;
	std::uint8_t dbgShowPageUsage;
	const unsigned char * inPageHeader;
	const unsigned char * inPageData;
	unsigned char * tempData;
	unsigned char * targetImage[3];
	void ( __fastcall * TranscodePageFunc )( const transcodeParms_t * );
};

void DrawPixelNumber( unsigned char * dest, int byteStride, const char * text,
	int scaleX, int scaleY, int pixelStride, int frontColor, int backColor );
void BrightColorForNumber( int number, unsigned char * y, unsigned char * co, unsigned char * cg );

void DXT_Decompress( int pageHeaderSize, int diskOffsetScale,
	const unsigned char * src, int srcLen, unsigned char * dest );
void DCT_Decompress( const DCTHeader_t * header, const unsigned char * src,
	unsigned int srcLen, unsigned char * dest );
void HDP_Decompress( const HDPHeader_t * header, unsigned char * src,
	unsigned int srcLen, unsigned char * dest );
void JXR_Decompress( const JXRHeader_t * header, const unsigned char * src,
	int srcLen, unsigned char * dest );

void CopyUncompressed( unsigned char * const * targetImage, int * targetBytePitch,
	char imageFlags, const unsigned char * src, int srcLength );
void ConvertDXT5_DXT1Alpha( unsigned char * dst, int dstBytePitch,
	const unsigned char * src );
void CopyDXTCompressed( unsigned char * const * targetImage, int * targetBytePitch,
	char imageFlags, const unsigned char * src, int srcLength,
	int pageHeaderSize, int diskOffsetScale );
void StripPageBorder( unsigned char * dst );
void TranscodePage( const transcodeParms_t * parms );

void TranscodePage_DXT_DXT( const transcodeParms_t * parms );
void TranscodePage_DXT_DXT_upsample( const transcodeParms_t * parms );
void TranscodePage_DCT_DXT( const transcodeParms_t * parms );
void TranscodePage_DCT_DXT_upsample( const transcodeParms_t * parms );
void TranscodePage_HDP_DXT( const transcodeParms_t * parms );
void TranscodePage_HDP_DXT_upsample( const transcodeParms_t * parms );
void TranscodePage_JXR_DXT( const transcodeParms_t * parms );
void TranscodePage_JXR_DXT_upsample( const transcodeParms_t * parms );

#if defined( _M_IX86 )
static_assert( offsetof( transcodeParms_t, inPageHeader ) == 100,
	"Recovered transcode parameter ABI changed" );
#endif
