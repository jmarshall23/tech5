#pragma once

#include "hdpbitio.h"

enum hdpColorFormat_t : int { HDP_COLOR_MONO, HDP_COLOR_GRAY, HDP_COLOR_RGB, HDP_COLOR_YCOCG, HDP_COLOR_NORMAL };
enum hdpStreamLayout_t : int { HDP_STREAM_SPATIAL, HDP_STREAM_FREQUENCY };
enum hdpSubBands_t : int { HDP_SUBBANDS_ALL, HDP_SUBBANDS_NO_FLEXBITS, HDP_SUBBANDS_DC_ONLY };
enum hdpOverlap_t : int { HDP_OVERLAP_NONE, HDP_OVERLAP_ONE, HDP_OVERLAP_TWO };

struct hdpCodecParms_t {
	hdpColorFormat_t colorFormat;
	unsigned int numChannels;
	hdpStreamLayout_t streamLayout;
	hdpSubBands_t subBands;
	hdpOverlap_t overlap;
	unsigned char mantissaLengthOrShift;
	char exponentBias;
	bool useScaledArith;
	bool hasAlphaChannel;
	unsigned char quantizerIndexDC[16];
	unsigned char quantizerIndexLP[16];
	unsigned char quantizerIndexHP[16];
	hdpStream_t * baseStream;
	void * tempBuffer;
	unsigned int tempBufferSize;
	unsigned int tempBufferUsed;
};

struct hdpImageInfo_t { unsigned int width, height, channels; };
struct hdpImageBufferInfo_t { unsigned char * data; unsigned int stride; };
struct hdpCodec_t {
	hdpImageInfo_t imageInfo;
	hdpImageBufferInfo_t imageBufferInfo;
	hdpCodecParms_t codecParms;
	unsigned int widthInMacroblocks;
	unsigned int heightInMacroblocks;
	unsigned int currentMacroblockRow;
	unsigned int currentMacroblockColumn;
};

unsigned int HDPEstimateTempMemory( int width, int height, int channels );
