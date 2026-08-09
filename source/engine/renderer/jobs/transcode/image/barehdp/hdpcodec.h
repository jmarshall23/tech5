#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpcodec.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22799; PDB kind: struct.
struct __declspec(align(4)) hdpCodecParms_t
{
  hdpColorFormat_t colorFormat;
  unsigned int numChannels;
  hdpStreamLayout_t streamLayout;
  hdpSubBands_t subBands;
  hdpOverlap_t overlap;
  unsigned __int8 mantissaLengthOrShift;
  char exponentBias;
  bool useScaledArith;
  bool hasAlphaChannel;
  bool hasPerTileTrimFlexbits;
  unsigned __int8 uniformTrimFlexBits;
  unsigned __int8 quantizationDefault;
  unsigned __int8 quantizationUV;
  unsigned int quantizationMode;
  unsigned __int8 quantizerIndexDC[16];
  unsigned __int8 quantizerIndexLP[16];
  unsigned __int8 quantizerIndexHP[16];
  bool hasTileIndex;
  unsigned int numTilesHighMinusOne;
  unsigned int numTilesWideMinusOne;
  unsigned int *tileMacroblockOffsetX;
  unsigned int *tileMacroblockOffsetY;
  unsigned int extraPixelsTop;
  unsigned int extraPixelsLeft;
  unsigned int extraPixelsBottom;
  unsigned int extraPixelsRight;
  bool transcode;
  bool changeSubsamplingUV;
  hdpStream_t *baseStream;
  void *tempBuffer;
  unsigned int tempBufferSize;
  unsigned int tempBufferUsed;
  bool skipFlexbits;
  bool decodeCoeffientsOnly;
  unsigned int fullImageROILeftX;
  unsigned int fullImageROIRightX;
  unsigned int fullImageROITopY;
  unsigned int fullImageROIBottomY;
  unsigned int thumbnailWidth;
  unsigned int thumbnailHeight;
  unsigned __int8 postProcStrength;
  unsigned int fullImageROILeftTile;
  unsigned int fullImageROIRightTile;
  unsigned int fullImageROITopTile;
  unsigned int fullImageROIBottomTile;
  unsigned int thumbnailScale;
  bool decodeLP;
  bool decodeHP;
  bool decodeFlexbits;
  bool decodeFullFrame;
  bool decodeFullWidth;
};

// IDA Local Type ordinal 22811; PDB kind: struct.
struct __declspec(align(4)) hdpCodec_t
{
  hdpMacroblockInfo_t MBInfo;
  hdpImageInfo_t imageInfo;
  hdpImageBufferInfo_t imageBufferInfo;
  hdpCodecParms_t codecParms;
  unsigned int *tileIndex;
  unsigned int baseTileOffset;
  hdpBitIO_t *bitIOHeader;
  hdpStream_t **tileStreams;
  hdpBitIO_t *tileBitIOs;
  unsigned int numTileBitIOs;
  unsigned int numSubBands;
  hdpTileQuantization_t *tileQuantization;
  hdpContext_t *tileContexts;
  unsigned int currentTileRow;
  unsigned int currentTileColumn;
  bool atTileLeftMB;
  bool atTileTopMB;
  bool resetAdaptiveScanTotals;
  bool adaptContextHuffman;
  bool processedFirstMBRow;
  unsigned int widthInMacroblocks;
  unsigned int heightInMacroblocks;
  unsigned int currentMacroblockRow;
  unsigned int currentMacroblockColumn;
  __int16 *macroBlockRowBuffer0[16];
  __int16 *macroBlockRowBuffer1[16];
  __int16 *macroBlockColumnPtr0[16];
  __int16 *macroBlockColumnPtr1[16];
  __int16 *macroBlockPrevColumnPtr[16];
  hdpPredictionInfo_t *predInfoCurRow[16];
  hdpPredictionInfo_t *predInfoPrevRow[16];
  hdpPredictionInfo_t *predInfoMemory;
  hdpPostProcessInfo_t *postProcInfo[16][2];
  __int16 *resampleU;
  __int16 *resampleV;
  unsigned int *rotFlipOffsetX;
  unsigned int *rotFlipOffsetY;
  hdpCodec_t *nextCodec;
  bool isSecondaryCodec;
};
