
// ========================================================================
// InitMono
// EA  : 0x828EB308
// RVA : 0x008EB308
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

void __fastcall InitMono(
        hdpImageInfo_t *imageInfo,
        hdpCodecParms_t *codecParms,
        hdpStream_t *stream,
        void *temp,
        unsigned int tempSize,
        unsigned __int8 *buf,
        unsigned int bufSize,
        unsigned int width,
        int height,
        int quality,
        bool entropyOnly,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        unsigned int a28,
        int a29,
        int a30,
        int a31,
        bool a32)
{
  int v36; // ctr
  hdpOrientation_t *p_orientation; // r9

  v36 = 10;
  p_orientation = &imageInfo[-1].orientation;
  do
  {
    *++p_orientation = O_NONE;
    --v36;
  }
  while ( v36 != 0 );
  imageInfo->imageWidth = width;
  imageInfo->colorFormat = CF_MONO;
  imageInfo->bitDepth = BD_8;
  imageInfo->bitsPerUnit = 8;
  imageInfo->imageHeight = a28;
  memset(Dst: codecParms, Val: 0, Size: sizeof(hdpCodecParms_t));
  codecParms->baseStream = stream;
  codecParms->tempBuffer = temp;
  codecParms->tempBufferSize = tempSize;
  codecParms->colorFormat = CF_N_CHANNEL;
  codecParms->subBands = a30 != 0;
  codecParms->numChannels = 1;
  codecParms->overlap = OL_ONE;
  codecParms->streamLayout = SL_SPATIAL;
  codecParms->quantizationDefault = a30;
  codecParms->tempBufferUsed = 0;
  codecParms->decodeCoeffientsOnly = a32;
  codecParms->thumbnailWidth = width;
  codecParms->thumbnailHeight = a28;
  codecParms->postProcStrength = 0;
  CreateWS_Memory(stream, pv: buf, cb: bufSize);
}


// ========================================================================
// InitGrayScale
// EA  : 0x828EB3E8
// RVA : 0x008EB3E8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

void __fastcall InitGrayScale(
        hdpImageInfo_t *imageInfo,
        hdpCodecParms_t *codecParms,
        hdpStream_t *stream,
        void *temp,
        unsigned int tempSize,
        unsigned __int8 *buf,
        unsigned int bufSize,
        unsigned int width,
        int height,
        int quality,
        bool entropyOnly,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        unsigned int a28,
        int a29,
        int a30,
        int a31,
        bool a32)
{
  int v36; // ctr
  hdpOrientation_t *p_orientation; // r9

  v36 = 10;
  p_orientation = &imageInfo[-1].orientation;
  do
  {
    *++p_orientation = O_NONE;
    --v36;
  }
  while ( v36 != 0 );
  imageInfo->imageWidth = width;
  imageInfo->colorFormat = CF_GRAYSCALE;
  imageInfo->bitsPerUnit = 32;
  imageInfo->bitDepth = BD_8;
  imageInfo->imageHeight = a28;
  memset(Dst: codecParms, Val: 0, Size: sizeof(hdpCodecParms_t));
  codecParms->baseStream = stream;
  codecParms->tempBuffer = temp;
  codecParms->tempBufferSize = tempSize;
  codecParms->colorFormat = CF_N_CHANNEL;
  codecParms->subBands = a30 != 0;
  codecParms->numChannels = 1;
  codecParms->overlap = OL_ONE;
  codecParms->streamLayout = SL_SPATIAL;
  codecParms->quantizationDefault = a30;
  codecParms->tempBufferUsed = 0;
  codecParms->decodeCoeffientsOnly = a32;
  codecParms->thumbnailWidth = width;
  codecParms->thumbnailHeight = a28;
  codecParms->postProcStrength = 0;
  CreateWS_Memory(stream, pv: buf, cb: bufSize);
}


// ========================================================================
// InitRGB
// EA  : 0x828EB4C8
// RVA : 0x008EB4C8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

void __fastcall InitRGB(
        hdpImageInfo_t *imageInfo,
        hdpCodecParms_t *codecParms,
        hdpStream_t *stream,
        void *temp,
        unsigned int tempSize,
        unsigned __int8 *buf,
        unsigned int bufSize,
        unsigned int width,
        int height,
        int quality,
        bool hasAlpha,
        bool entropyOnly,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        unsigned int a28,
        int a29,
        int a30,
        int a31,
        bool a32,
        int a33,
        bool a34)
{
  int v38; // ctr
  hdpOrientation_t *p_orientation; // r9
  int v43; // r11

  v38 = 10;
  p_orientation = &imageInfo[-1].orientation;
  do
  {
    *++p_orientation = O_NONE;
    --v38;
  }
  while ( v38 != 0 );
  imageInfo->imageWidth = width;
  imageInfo->colorFormat = CF_RGB;
  imageInfo->bitsPerUnit = 32;
  imageInfo->bitDepth = BD_8;
  imageInfo->imageHeight = a28;
  memset(Dst: codecParms, Val: 0, Size: sizeof(hdpCodecParms_t));
  codecParms->overlap = OL_ONE;
  codecParms->colorFormat = CF_YUV_444;
  codecParms->numChannels = 3;
  codecParms->streamLayout = SL_SPATIAL;
  codecParms->hasAlphaChannel = a32;
  codecParms->subBands = a30 != 0;
  codecParms->quantizationDefault = a30;
  if ( a30 >= 16 )
  {
    if ( a30 <= 48 )
      v43 = a30 + 18;
    else
      v43 = a30 + 20;
    if ( v43 > 255 )
      LOBYTE(v43) = -1;
  }
  else
  {
    LOBYTE(v43) = 2 * a30;
  }
  codecParms->baseStream = stream;
  codecParms->tempBuffer = temp;
  codecParms->quantizationUV = v43;
  codecParms->tempBufferSize = tempSize;
  codecParms->tempBufferUsed = 0;
  codecParms->decodeCoeffientsOnly = a34;
  codecParms->thumbnailWidth = width;
  codecParms->thumbnailHeight = a28;
  codecParms->postProcStrength = 0;
  CreateWS_Memory(stream, pv: buf, cb: bufSize);
}


// ========================================================================
// InitYCoCg
// EA  : 0x828EB5E8
// RVA : 0x008EB5E8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

void __fastcall InitYCoCg(
        hdpImageInfo_t *imageInfo,
        hdpCodecParms_t *codecParms,
        hdpStream_t *stream,
        void *temp,
        unsigned int tempSize,
        unsigned __int8 *buf,
        unsigned int bufSize,
        unsigned int width,
        int height,
        int quality,
        bool entropyOnly,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        unsigned int a28,
        int a29,
        int a30,
        int a31,
        bool a32)
{
  int v36; // ctr
  hdpOrientation_t *p_orientation; // r9
  int v41; // r11

  v36 = 10;
  p_orientation = &imageInfo[-1].orientation;
  do
  {
    *++p_orientation = O_NONE;
    --v36;
  }
  while ( v36 != 0 );
  imageInfo->imageWidth = width;
  imageInfo->colorFormat = CF_COCG_Y;
  imageInfo->bitsPerUnit = 32;
  imageInfo->bitDepth = BD_8;
  imageInfo->imageHeight = a28;
  memset(Dst: codecParms, Val: 0, Size: sizeof(hdpCodecParms_t));
  codecParms->overlap = OL_ONE;
  codecParms->streamLayout = SL_SPATIAL;
  codecParms->colorFormat = CF_YUV_444;
  codecParms->numChannels = 3;
  codecParms->quantizationDefault = a30;
  codecParms->subBands = a30 != 0;
  if ( a30 >= 16 )
  {
    if ( a30 <= 48 )
      v41 = a30 + 18;
    else
      v41 = a30 + 20;
    if ( v41 > 255 )
      LOBYTE(v41) = -1;
  }
  else
  {
    LOBYTE(v41) = 2 * a30;
  }
  codecParms->baseStream = stream;
  codecParms->tempBuffer = temp;
  codecParms->quantizationUV = v41;
  codecParms->tempBufferSize = tempSize;
  codecParms->tempBufferUsed = 0;
  codecParms->decodeCoeffientsOnly = a32;
  codecParms->thumbnailWidth = width;
  codecParms->thumbnailHeight = a28;
  codecParms->postProcStrength = 0;
  CreateWS_Memory(stream, pv: buf, cb: bufSize);
}


// ========================================================================
// InitNormalMap
// EA  : 0x828EB700
// RVA : 0x008EB700
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

void __fastcall InitNormalMap(
        hdpImageInfo_t *imageInfo,
        hdpCodecParms_t *codecParms,
        hdpStream_t *stream,
        void *temp,
        unsigned int tempSize,
        unsigned __int8 *buf,
        unsigned int bufSize,
        unsigned int width,
        int height,
        int quality,
        bool entropyOnly,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        unsigned int a28,
        int a29,
        int a30,
        int a31,
        bool a32)
{
  int v36; // ctr
  hdpOrientation_t *p_orientation; // r9

  v36 = 10;
  p_orientation = &imageInfo[-1].orientation;
  do
  {
    *++p_orientation = O_NONE;
    --v36;
  }
  while ( v36 != 0 );
  imageInfo->imageWidth = width;
  imageInfo->colorFormat = CF_NORMAL_Y_X;
  imageInfo->bitsPerUnit = 32;
  imageInfo->bitDepth = BD_8;
  imageInfo->imageHeight = a28;
  memset(Dst: codecParms, Val: 0, Size: sizeof(hdpCodecParms_t));
  codecParms->baseStream = stream;
  codecParms->tempBuffer = temp;
  codecParms->tempBufferSize = tempSize;
  codecParms->colorFormat = CF_N_CHANNEL;
  codecParms->subBands = a30 != 0;
  codecParms->numChannels = 2;
  codecParms->overlap = OL_ONE;
  codecParms->streamLayout = SL_SPATIAL;
  codecParms->quantizationDefault = a30;
  codecParms->tempBufferUsed = 0;
  codecParms->decodeCoeffientsOnly = a32;
  codecParms->thumbnailWidth = width;
  codecParms->thumbnailHeight = a28;
  codecParms->postProcStrength = 0;
  CreateWS_Memory(stream, pv: buf, cb: bufSize);
}


// ========================================================================
// ??0idBareHDP@@QAA@XZ
// EA  : 0x828EB7E8
// RVA : 0x008EB7E8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

idBareHDP *__fastcall idBareHDP::idBareHDP(idBareHDP *this)
{
  this->quality = 0;
  this->tempBuffer = nullptr;
  this->tempBufferSize = 0;
  this->tempBufferUsed = 0;
  this->imageROILeftX = 0;
  this->imageROITopY = 0;
  this->imageROIWidth = 0;
  this->imageROIHeight = 0;
  this->imageByteStride = 0;
  this->codec = nullptr;
  return this;
}


// ========================================================================
// ?EstimateTempMemory@idBareHDP@@SAHHHH@Z
// EA  : 0x828EB818
// RVA : 0x008EB818
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

// attributes: thunk
unsigned int __fastcall idBareHDP::EstimateTempMemory(int width, int height, int numComponents)
{
  return HDPEstimateTempMemory(width, height, numComponents);
}


// ========================================================================
// ?BeginDecompressImageGrayScale@idBareHDP@@QAAXPBEHHH@Z
// EA  : 0x828EB820
// RVA : 0x008EB820
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

void __fastcall idBareHDP::BeginDecompressImageGrayScale(
        idBareHDP *this,
        unsigned __int8 *inBuf,
        unsigned int width,
        unsigned int height,
        unsigned int inputBytes)
{
  unsigned int v5; // r29
  unsigned int v6; // r30
  unsigned int imageROITopY; // r9
  unsigned int imageROILeftX; // r10
  int imageROIWidth; // r11
  int imageROIHeight; // r8
  unsigned int tempBufferUsed; // r10
  int v13; // [sp+8h] [-198h]
  int v14; // [sp+Ch] [-194h]
  bool v15; // [sp+13h] [-18Dh]
  int v16; // [sp+14h] [-18Ch]
  int v17; // [sp+18h] [-188h]
  int v18; // [sp+1Ch] [-184h]
  int v19; // [sp+20h] [-180h]
  int v20; // [sp+24h] [-17Ch]
  int v21; // [sp+28h] [-178h]
  int v22; // [sp+2Ch] [-174h]
  int v23; // [sp+30h] [-170h]
  int v24; // [sp+34h] [-16Ch]
  int v25; // [sp+38h] [-168h]
  int v26; // [sp+3Ch] [-164h]
  int v27; // [sp+40h] [-160h]
  int v28; // [sp+44h] [-15Ch]
  int v29; // [sp+48h] [-158h]
  int v30; // [sp+4Ch] [-154h]
  int v31; // [sp+50h] [-150h]
  int v32; // [sp+58h] [-148h]
  int v33; // [sp+60h] [-140h]
  hdpCodec_t *v34; // [sp+70h] [-130h] BYREF
  hdpImageInfo_t v35; // [sp+80h] [-120h] BYREF
  hdpCodecParms_t v36; // [sp+B0h] [-F0h] BYREF

  v5 = height;
  v6 = width;
  InitGrayScale(
    imageInfo: &v35,
    codecParms: &v36,
    stream: (hdpStream_t *)this->streamTemp,
    temp: this->tempBuffer,
    tempSize: this->tempBufferSize,
    buf: inBuf,
    bufSize: inputBytes,
    width,
    height: v13,
    quality: v14,
    entropyOnly: v15,
    a12: v16,
    a13: v17,
    a14: v18,
    a15: v19,
    a16: v20,
    a17: v21,
    a18: v22,
    a19: v23,
    a20: v24,
    a21: v25,
    a22: v26,
    a23: v27,
    a24: v28,
    a25: v29,
    a26: v30,
    a27: v31,
    a28: height,
    a29: v32,
    a30: this->quality,
    a31: v33,
    a32: false);
  imageROITopY = this->imageROITopY;
  imageROILeftX = this->imageROILeftX;
  imageROIWidth = this->imageROIWidth;
  imageROIHeight = this->imageROIHeight;
  v36.fullImageROILeftX = imageROILeftX;
  v36.fullImageROITopY = imageROITopY;
  if ( imageROIWidth > 0 )
    v6 = imageROILeftX + imageROIWidth;
  v36.fullImageROIRightX = v6 - 1;
  if ( imageROIHeight > 0 )
    v5 = imageROITopY + imageROIHeight;
  v34 = nullptr;
  v36.fullImageROIBottomY = v5 - 1;
  this->imageByteStride = 16 * ((int)v35.bitsPerUnit >> 3);
  if ( HDPDecInit(imageInfo: &v35, codecParms: &v36, codecOut: &v34) != HDP_ERROR_NONE )
  {
    this->codec = nullptr;
  }
  else
  {
    tempBufferUsed = v36.tempBufferUsed;
    this->codec = v34;
    this->tempBufferUsed = tempBufferUsed;
  }
}


// ========================================================================
// ?DecompressImageGrayScaleMacroBlock@idBareHDP@@QAAXPAEHH@Z
// EA  : 0x828EB908
// RVA : 0x008EB908
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

void __fastcall idBareHDP::DecompressImageGrayScaleMacroBlock(
        idBareHDP *this,
        unsigned __int8 *outBuf,
        unsigned int blockNum,
        unsigned int byteStride)
{
  hdpImageBufferInfo_t v4; // [sp+50h] [-20h] BYREF

  v4.buffer = outBuf;
  v4.macroblockIndex = blockNum;
  v4.byteStride = byteStride;
  v4.lineCount = 16;
  HDPDecOutputMB_GrayScale_Xenon_16(codec: this->codec, bufferInfo: &v4);
}


// ========================================================================
// ?BeginDecompressImageRGB@idBareHDP@@QAAXPBEHHH@Z
// EA  : 0x828EB948
// RVA : 0x008EB948
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

void __fastcall idBareHDP::BeginDecompressImageRGB(
        idBareHDP *this,
        unsigned __int8 *inBuf,
        unsigned int width,
        unsigned int height,
        unsigned int inputBytes)
{
  unsigned int v5; // r29
  unsigned int v6; // r30
  unsigned int imageROITopY; // r9
  unsigned int imageROILeftX; // r10
  int imageROIWidth; // r11
  int imageROIHeight; // r8
  unsigned int tempBufferUsed; // r10
  int v13; // [sp+8h] [-198h]
  int v14; // [sp+Ch] [-194h]
  bool v15; // [sp+13h] [-18Dh]
  bool v16; // [sp+17h] [-189h]
  int v17; // [sp+18h] [-188h]
  int v18; // [sp+1Ch] [-184h]
  int v19; // [sp+20h] [-180h]
  int v20; // [sp+24h] [-17Ch]
  int v21; // [sp+28h] [-178h]
  int v22; // [sp+2Ch] [-174h]
  int v23; // [sp+30h] [-170h]
  int v24; // [sp+34h] [-16Ch]
  int v25; // [sp+38h] [-168h]
  int v26; // [sp+3Ch] [-164h]
  int v27; // [sp+40h] [-160h]
  int v28; // [sp+44h] [-15Ch]
  int v29; // [sp+48h] [-158h]
  int v30; // [sp+4Ch] [-154h]
  int v31; // [sp+50h] [-150h]
  int v32; // [sp+58h] [-148h]
  int v33; // [sp+60h] [-140h]
  int v34; // [sp+68h] [-138h]
  hdpCodec_t *v35; // [sp+70h] [-130h] BYREF
  hdpImageInfo_t v36; // [sp+80h] [-120h] BYREF
  hdpCodecParms_t v37; // [sp+B0h] [-F0h] BYREF

  v5 = height;
  v6 = width;
  InitRGB(
    imageInfo: &v36,
    codecParms: &v37,
    stream: (hdpStream_t *)this->streamTemp,
    temp: this->tempBuffer,
    tempSize: this->tempBufferSize,
    buf: inBuf,
    bufSize: inputBytes,
    width,
    height: v13,
    quality: v14,
    hasAlpha: v15,
    entropyOnly: v16,
    a13: v17,
    a14: v18,
    a15: v19,
    a16: v20,
    a17: v21,
    a18: v22,
    a19: v23,
    a20: v24,
    a21: v25,
    a22: v26,
    a23: v27,
    a24: v28,
    a25: v29,
    a26: v30,
    a27: v31,
    a28: height,
    a29: v32,
    a30: this->quality,
    a31: v33,
    a32: false,
    a33: v34,
    a34: false);
  imageROITopY = this->imageROITopY;
  imageROILeftX = this->imageROILeftX;
  imageROIWidth = this->imageROIWidth;
  imageROIHeight = this->imageROIHeight;
  v37.fullImageROILeftX = imageROILeftX;
  v37.fullImageROITopY = imageROITopY;
  if ( imageROIWidth > 0 )
    v6 = imageROILeftX + imageROIWidth;
  v37.fullImageROIRightX = v6 - 1;
  if ( imageROIHeight > 0 )
    v5 = imageROITopY + imageROIHeight;
  v35 = nullptr;
  v37.fullImageROIBottomY = v5 - 1;
  this->imageByteStride = 16 * ((int)v36.bitsPerUnit >> 3);
  if ( HDPDecInit(imageInfo: &v36, codecParms: &v37, codecOut: &v35) != HDP_ERROR_NONE )
  {
    this->codec = nullptr;
  }
  else
  {
    tempBufferUsed = v37.tempBufferUsed;
    this->codec = v35;
    this->tempBufferUsed = tempBufferUsed;
  }
}


// ========================================================================
// ?DecompressImageRGBMacroBlock@idBareHDP@@QAAXPAEHH@Z
// EA  : 0x828EBA30
// RVA : 0x008EBA30
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

void __fastcall idBareHDP::DecompressImageRGBMacroBlock(
        idBareHDP *this,
        unsigned __int8 *outBuf,
        unsigned int blockNum,
        unsigned int byteStride)
{
  hdpImageBufferInfo_t v4; // [sp+50h] [-20h] BYREF

  v4.buffer = outBuf;
  v4.macroblockIndex = blockNum;
  v4.byteStride = byteStride;
  v4.lineCount = 16;
  HDPDecOutputMB_RGB_Xenon_16(codec: this->codec, bufferInfo: &v4);
}


// ========================================================================
// ?BeginDecompressImageYCoCg@idBareHDP@@QAAXPBEHHH@Z
// EA  : 0x828EBA70
// RVA : 0x008EBA70
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

void __fastcall idBareHDP::BeginDecompressImageYCoCg(
        idBareHDP *this,
        unsigned __int8 *inBuf,
        unsigned int width,
        unsigned int height,
        unsigned int inputBytes)
{
  unsigned int v5; // r29
  unsigned int v6; // r30
  unsigned int imageROITopY; // r9
  unsigned int imageROILeftX; // r10
  int imageROIWidth; // r11
  int imageROIHeight; // r8
  unsigned int tempBufferUsed; // r10
  int v13; // [sp+8h] [-198h]
  int v14; // [sp+Ch] [-194h]
  bool v15; // [sp+13h] [-18Dh]
  int v16; // [sp+14h] [-18Ch]
  int v17; // [sp+18h] [-188h]
  int v18; // [sp+1Ch] [-184h]
  int v19; // [sp+20h] [-180h]
  int v20; // [sp+24h] [-17Ch]
  int v21; // [sp+28h] [-178h]
  int v22; // [sp+2Ch] [-174h]
  int v23; // [sp+30h] [-170h]
  int v24; // [sp+34h] [-16Ch]
  int v25; // [sp+38h] [-168h]
  int v26; // [sp+3Ch] [-164h]
  int v27; // [sp+40h] [-160h]
  int v28; // [sp+44h] [-15Ch]
  int v29; // [sp+48h] [-158h]
  int v30; // [sp+4Ch] [-154h]
  int v31; // [sp+50h] [-150h]
  int v32; // [sp+58h] [-148h]
  int v33; // [sp+60h] [-140h]
  hdpCodec_t *v34; // [sp+70h] [-130h] BYREF
  hdpImageInfo_t v35; // [sp+80h] [-120h] BYREF
  hdpCodecParms_t v36; // [sp+B0h] [-F0h] BYREF

  v5 = height;
  v6 = width;
  InitYCoCg(
    imageInfo: &v35,
    codecParms: &v36,
    stream: (hdpStream_t *)this->streamTemp,
    temp: this->tempBuffer,
    tempSize: this->tempBufferSize,
    buf: inBuf,
    bufSize: inputBytes,
    width,
    height: v13,
    quality: v14,
    entropyOnly: v15,
    a12: v16,
    a13: v17,
    a14: v18,
    a15: v19,
    a16: v20,
    a17: v21,
    a18: v22,
    a19: v23,
    a20: v24,
    a21: v25,
    a22: v26,
    a23: v27,
    a24: v28,
    a25: v29,
    a26: v30,
    a27: v31,
    a28: height,
    a29: v32,
    a30: this->quality,
    a31: v33,
    a32: false);
  imageROITopY = this->imageROITopY;
  imageROILeftX = this->imageROILeftX;
  imageROIWidth = this->imageROIWidth;
  imageROIHeight = this->imageROIHeight;
  v36.fullImageROILeftX = imageROILeftX;
  v36.fullImageROITopY = imageROITopY;
  if ( imageROIWidth > 0 )
    v6 = imageROILeftX + imageROIWidth;
  v36.fullImageROIRightX = v6 - 1;
  if ( imageROIHeight > 0 )
    v5 = imageROITopY + imageROIHeight;
  v34 = nullptr;
  v36.fullImageROIBottomY = v5 - 1;
  this->imageByteStride = 16 * ((int)v35.bitsPerUnit >> 3);
  if ( HDPDecInit(imageInfo: &v35, codecParms: &v36, codecOut: &v34) != HDP_ERROR_NONE )
  {
    this->codec = nullptr;
  }
  else
  {
    tempBufferUsed = v36.tempBufferUsed;
    this->codec = v34;
    this->tempBufferUsed = tempBufferUsed;
  }
}


// ========================================================================
// ?BeginDecompressImageYCoCgMacroBlockRow@idBareHDP@@QAAXXZ
// EA  : 0x828EBB58
// RVA : 0x008EBB58
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

void __fastcall idBareHDP::BeginDecompressImageYCoCgMacroBlockRow(idBareHDP *this)
{
  HDPDecDecodeMBRow(firstCodec: this->codec);
}


// ========================================================================
// ?DecompressImageYCoCgMacroBlock@idBareHDP@@QAAXPAEHH@Z
// EA  : 0x828EBB60
// RVA : 0x008EBB60
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

void __fastcall idBareHDP::DecompressImageYCoCgMacroBlock(
        idBareHDP *this,
        unsigned __int8 *outBuf,
        unsigned int blockNum,
        unsigned int byteStride)
{
  hdpImageBufferInfo_t v4; // [sp+50h] [-20h] BYREF

  v4.buffer = outBuf;
  v4.macroblockIndex = blockNum;
  v4.byteStride = byteStride;
  v4.lineCount = 16;
  HDPDecOutputMB_CoCg_Y_Xenon_16(codec: this->codec, bufferInfo: &v4);
}


// ========================================================================
// ?BeginDecompressImageNormalMap@idBareHDP@@QAAXPBEHHH@Z
// EA  : 0x828EBBA0
// RVA : 0x008EBBA0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

void __fastcall idBareHDP::BeginDecompressImageNormalMap(
        idBareHDP *this,
        unsigned __int8 *inBuf,
        unsigned int width,
        unsigned int height,
        unsigned int inputBytes)
{
  unsigned int v5; // r29
  unsigned int v6; // r30
  unsigned int imageROITopY; // r9
  unsigned int imageROILeftX; // r10
  int imageROIWidth; // r11
  int imageROIHeight; // r8
  unsigned int tempBufferUsed; // r10
  int v13; // [sp+8h] [-198h]
  int v14; // [sp+Ch] [-194h]
  bool v15; // [sp+13h] [-18Dh]
  int v16; // [sp+14h] [-18Ch]
  int v17; // [sp+18h] [-188h]
  int v18; // [sp+1Ch] [-184h]
  int v19; // [sp+20h] [-180h]
  int v20; // [sp+24h] [-17Ch]
  int v21; // [sp+28h] [-178h]
  int v22; // [sp+2Ch] [-174h]
  int v23; // [sp+30h] [-170h]
  int v24; // [sp+34h] [-16Ch]
  int v25; // [sp+38h] [-168h]
  int v26; // [sp+3Ch] [-164h]
  int v27; // [sp+40h] [-160h]
  int v28; // [sp+44h] [-15Ch]
  int v29; // [sp+48h] [-158h]
  int v30; // [sp+4Ch] [-154h]
  int v31; // [sp+50h] [-150h]
  int v32; // [sp+58h] [-148h]
  int v33; // [sp+60h] [-140h]
  hdpCodec_t *v34; // [sp+70h] [-130h] BYREF
  hdpImageInfo_t v35; // [sp+80h] [-120h] BYREF
  hdpCodecParms_t v36; // [sp+B0h] [-F0h] BYREF

  v5 = height;
  v6 = width;
  InitNormalMap(
    imageInfo: &v35,
    codecParms: &v36,
    stream: (hdpStream_t *)this->streamTemp,
    temp: this->tempBuffer,
    tempSize: this->tempBufferSize,
    buf: inBuf,
    bufSize: inputBytes,
    width,
    height: v13,
    quality: v14,
    entropyOnly: v15,
    a12: v16,
    a13: v17,
    a14: v18,
    a15: v19,
    a16: v20,
    a17: v21,
    a18: v22,
    a19: v23,
    a20: v24,
    a21: v25,
    a22: v26,
    a23: v27,
    a24: v28,
    a25: v29,
    a26: v30,
    a27: v31,
    a28: height,
    a29: v32,
    a30: this->quality,
    a31: v33,
    a32: false);
  imageROITopY = this->imageROITopY;
  imageROILeftX = this->imageROILeftX;
  imageROIWidth = this->imageROIWidth;
  imageROIHeight = this->imageROIHeight;
  v36.fullImageROILeftX = imageROILeftX;
  v36.fullImageROITopY = imageROITopY;
  if ( imageROIWidth > 0 )
    v6 = imageROILeftX + imageROIWidth;
  v36.fullImageROIRightX = v6 - 1;
  if ( imageROIHeight > 0 )
    v5 = imageROITopY + imageROIHeight;
  v34 = nullptr;
  v36.fullImageROIBottomY = v5 - 1;
  this->imageByteStride = 16 * ((int)v35.bitsPerUnit >> 3);
  if ( HDPDecInit(imageInfo: &v35, codecParms: &v36, codecOut: &v34) != HDP_ERROR_NONE )
  {
    this->codec = nullptr;
  }
  else
  {
    tempBufferUsed = v36.tempBufferUsed;
    this->codec = v34;
    this->tempBufferUsed = tempBufferUsed;
  }
}


// ========================================================================
// ?DecompressImageNormalMapMacroBlock@idBareHDP@@QAAXPAEHH@Z
// EA  : 0x828EBC88
// RVA : 0x008EBC88
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

void __fastcall idBareHDP::DecompressImageNormalMapMacroBlock(
        idBareHDP *this,
        unsigned __int8 *outBuf,
        unsigned int blockNum,
        unsigned int byteStride)
{
  hdpImageBufferInfo_t v4; // [sp+50h] [-20h] BYREF

  v4.buffer = outBuf;
  v4.macroblockIndex = blockNum;
  v4.byteStride = byteStride;
  v4.lineCount = 16;
  HDPDecOutputMB_Normal_Y_X_Xenon_16(codec: this->codec, bufferInfo: &v4);
}


// ========================================================================
// ?TerminateMacroBlockRowDecoding@idBareHDP@@QAAXXZ
// EA  : 0x828EBCC8
// RVA : 0x008EBCC8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

void __fastcall idBareHDP::TerminateMacroBlockRowDecoding(idBareHDP *this)
{
  HDPDecShutdown(firstCodec: this->codec);
}


// ========================================================================
// EncodeHDPhoto
// EA  : 0x828EBCD0
// RVA : 0x008EBCD0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

int __fastcall EncodeHDPhoto(
        hdpImageInfo_t *imageInfo,
        hdpCodecParms_t *codecParms,
        unsigned __int8 *inBuf,
        int width,
        int height,
        unsigned int *tempUsed,
        int *outputBytes)
{
  unsigned int bitsPerUnit; // r11
  unsigned int v13; // r25
  int v15; // r29
  signed int v16; // r31
  hdpCodec_t *v17; // [sp+50h] [-80h] BYREF
  unsigned int v18[3]; // [sp+54h] [-7Ch] BYREF
  hdpImageBufferInfo_t v19; // [sp+60h] [-70h] BYREF

  bitsPerUnit = imageInfo->bitsPerUnit;
  v17 = nullptr;
  v13 = (bitsPerUnit >> 3) * width;
  if ( HDPEncInit(imageInfo, codecParms, codecOut: &v17) != HDP_ERROR_NONE )
    return 0;
  v15 = 0;
  *tempUsed = codecParms->tempBufferUsed;
  if ( height > 0 )
  {
    v16 = height;
    do
    {
      v19.buffer = inBuf;
      v19.lineCount = 16;
      if ( v16 <= 16 )
        v19.lineCount = v16;
      v19.byteStride = v13;
      v19.macroblockIndex = 0;
      if ( HDPEncInputMBRowFast_Generic(codec: v17, bufferInfo: &v19) != HDP_ERROR_NONE
        || HDPEncEncodeMBRow(firstCodec: v17) != HDP_ERROR_NONE )
      {
        return 0;
      }
      v15 += 16;
      inBuf += 16 * v13;
      v16 -= 16;
    }
    while ( v15 < height );
  }
  if ( HDPEncShutdown(firstCodec: v17) != HDP_ERROR_NONE )
    return 0;
  GetPosWS_Memory(stream: codecParms->baseStream, poffPos: v18);
  *outputBytes = v18[0];
  idLobbyBackend360::StartArbitration(pexcept: (_exception *)codecParms->baseStream);
  return 1;
}


// ========================================================================
// DecodeHDPhoto
// EA  : 0x828EBDD0
// RVA : 0x008EBDD0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

int __fastcall DecodeHDPhoto(
        hdpImageInfo_t *imageInfo,
        hdpCodecParms_t *codecParms,
        unsigned __int8 *outBuf,
        int width,
        int height,
        char mipLevel,
        unsigned int *tempUsed,
        int inputBytes)
{
  unsigned int bitsPerUnit; // r10
  int v9; // r28
  signed int v13; // r30
  unsigned int v14; // r23
  int v16; // r27
  signed int v17; // r31
  hdpCodec_t *v18; // [sp+50h] [-80h] BYREF
  unsigned int v19[3]; // [sp+54h] [-7Ch] BYREF
  hdpImageBufferInfo_t v20; // [sp+60h] [-70h] BYREF

  bitsPerUnit = imageInfo->bitsPerUnit;
  v9 = height >> mipLevel;
  codecParms->thumbnailWidth = width >> mipLevel;
  codecParms->thumbnailHeight = height >> mipLevel;
  v18 = nullptr;
  v13 = 16 >> mipLevel;
  v14 = (bitsPerUnit >> 3) * (width >> mipLevel);
  if ( HDPDecInit(imageInfo, codecParms, codecOut: &v18) != HDP_ERROR_NONE )
    return 0;
  v16 = 0;
  *tempUsed = codecParms->tempBufferUsed;
  if ( v9 > 0 )
  {
    v17 = v9;
    do
    {
      v20.buffer = outBuf;
      v20.lineCount = v13;
      if ( v13 >= v17 )
        v20.lineCount = v17;
      v20.byteStride = v14;
      v20.macroblockIndex = 0;
      if ( HDPDecDecodeMBRow(firstCodec: v18) != HDP_ERROR_NONE
        || HDPDecOutputMBRowFast_Xenon_16(codec: v18, bufferInfo: &v20) != HDP_ERROR_NONE )
      {
        return 0;
      }
      v16 += v13;
      outBuf += v14 * v13;
      v17 -= v13;
    }
    while ( v16 < v9 );
  }
  if ( HDPDecShutdown(firstCodec: v18) != HDP_ERROR_NONE )
    return 0;
  GetPosWS_Memory(stream: codecParms->baseStream, poffPos: v19);
  idLobbyBackend360::StartArbitration(pexcept: (_exception *)codecParms->baseStream);
  return 1;
}


// ========================================================================
// ?DecompressImageMono@idBareHDP@@QAA_NPBEPAEHHHH@Z
// EA  : 0x828EBED8
// RVA : 0x008EBED8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

int __fastcall idBareHDP::DecompressImageMono(
        idBareHDP *this,
        unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        unsigned int width,
        unsigned int height,
        unsigned int inputBytes,
        char mipLevel)
{
  unsigned int imageROITopY; // r9
  int imageROIWidth; // r11
  int imageROIHeight; // r8
  unsigned int v15; // r11
  bool v16; // zf
  unsigned int v17; // r11
  int v19; // [sp+8h] [-1C8h]
  int v20; // [sp+Ch] [-1C4h]
  bool v21; // [sp+13h] [-1BDh]
  int v22; // [sp+14h] [-1BCh]
  int v23; // [sp+18h] [-1B8h]
  int v24; // [sp+1Ch] [-1B4h]
  int v25; // [sp+20h] [-1B0h]
  int v26; // [sp+24h] [-1ACh]
  int v27; // [sp+28h] [-1A8h]
  int v28; // [sp+2Ch] [-1A4h]
  int v29; // [sp+30h] [-1A0h]
  int v30; // [sp+34h] [-19Ch]
  int v31; // [sp+38h] [-198h]
  int v32; // [sp+3Ch] [-194h]
  int v33; // [sp+40h] [-190h]
  int v34; // [sp+44h] [-18Ch]
  int v35; // [sp+48h] [-188h]
  int v36; // [sp+4Ch] [-184h]
  int v37; // [sp+50h] [-180h]
  int v38; // [sp+58h] [-178h]
  int v39; // [sp+60h] [-170h]
  hdpImageInfo_t v40; // [sp+70h] [-160h] BYREF
  hdpCodecParms_t v41; // [sp+A0h] [-130h] BYREF
  hdpStream_t v42[2]; // [sp+170h] [-60h] BYREF

  InitMono(
    imageInfo: &v40,
    codecParms: &v41,
    stream: v42,
    temp: this->tempBuffer,
    tempSize: this->tempBufferSize,
    buf: inBuf,
    bufSize: inputBytes,
    width,
    height: v19,
    quality: v20,
    entropyOnly: v21,
    a12: v22,
    a13: v23,
    a14: v24,
    a15: v25,
    a16: v26,
    a17: v27,
    a18: v28,
    a19: v29,
    a20: v30,
    a21: v31,
    a22: v32,
    a23: v33,
    a24: v34,
    a25: v35,
    a26: v36,
    a27: v37,
    a28: height,
    a29: v38,
    a30: this->quality,
    a31: v39,
    a32: false);
  imageROITopY = this->imageROITopY;
  imageROIWidth = this->imageROIWidth;
  imageROIHeight = this->imageROIHeight;
  v41.fullImageROILeftX = this->imageROILeftX;
  v41.fullImageROITopY = imageROITopY;
  v16 = imageROIWidth > 0;
  v15 = v41.fullImageROILeftX + imageROIWidth;
  if ( !v16 )
    v15 = width;
  v41.fullImageROIRightX = v15 - 1;
  v17 = imageROITopY + imageROIHeight;
  if ( imageROIHeight <= 0 )
    v17 = height;
  v41.fullImageROIBottomY = v17 - 1;
  return DecodeHDPhoto(
           imageInfo: &v40,
           codecParms: &v41,
           outBuf,
           width,
           height,
           mipLevel,
           tempUsed: (unsigned int *)&this->tempBufferUsed,
           inputBytes: v41.fullImageROILeftX);
}


// ========================================================================
// ?CompressImageMono@idBareHDP@@QAA_NPBEPAEHHHAAH@Z
// EA  : 0x828EBFA0
// RVA : 0x008EBFA0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

int __fastcall idBareHDP::CompressImageMono(
        idBareHDP *this,
        unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        unsigned int outBufSize,
        unsigned int width,
        unsigned int height,
        int *outputBytes)
{
  unsigned int imageROITopY; // r9
  int imageROIWidth; // r11
  int imageROIHeight; // r8
  unsigned int v15; // r11
  bool v16; // zf
  unsigned int v17; // r11
  int v19; // [sp+8h] [-1C8h]
  int v20; // [sp+Ch] [-1C4h]
  bool v21; // [sp+13h] [-1BDh]
  int v22; // [sp+14h] [-1BCh]
  int v23; // [sp+18h] [-1B8h]
  int v24; // [sp+1Ch] [-1B4h]
  int v25; // [sp+20h] [-1B0h]
  int v26; // [sp+24h] [-1ACh]
  int v27; // [sp+28h] [-1A8h]
  int v28; // [sp+2Ch] [-1A4h]
  int v29; // [sp+30h] [-1A0h]
  int v30; // [sp+34h] [-19Ch]
  int v31; // [sp+38h] [-198h]
  int v32; // [sp+3Ch] [-194h]
  int v33; // [sp+40h] [-190h]
  int v34; // [sp+44h] [-18Ch]
  int v35; // [sp+48h] [-188h]
  int v36; // [sp+4Ch] [-184h]
  int v37; // [sp+50h] [-180h]
  int v38; // [sp+58h] [-178h]
  int v39; // [sp+60h] [-170h]
  hdpImageInfo_t v40; // [sp+70h] [-160h] BYREF
  hdpCodecParms_t v41; // [sp+A0h] [-130h] BYREF
  hdpStream_t v42[2]; // [sp+170h] [-60h] BYREF

  InitMono(
    imageInfo: &v40,
    codecParms: &v41,
    stream: v42,
    temp: this->tempBuffer,
    tempSize: this->tempBufferSize,
    buf: outBuf,
    bufSize: outBufSize,
    width,
    height: v19,
    quality: v20,
    entropyOnly: v21,
    a12: v22,
    a13: v23,
    a14: v24,
    a15: v25,
    a16: v26,
    a17: v27,
    a18: v28,
    a19: v29,
    a20: v30,
    a21: v31,
    a22: v32,
    a23: v33,
    a24: v34,
    a25: v35,
    a26: v36,
    a27: v37,
    a28: height,
    a29: v38,
    a30: this->quality,
    a31: v39,
    a32: false);
  imageROITopY = this->imageROITopY;
  imageROIWidth = this->imageROIWidth;
  imageROIHeight = this->imageROIHeight;
  v41.fullImageROILeftX = this->imageROILeftX;
  v41.fullImageROITopY = imageROITopY;
  v16 = imageROIWidth > 0;
  v15 = v41.fullImageROILeftX + imageROIWidth;
  if ( !v16 )
    v15 = width;
  v41.fullImageROIRightX = v15 - 1;
  v17 = imageROITopY + imageROIHeight;
  if ( imageROIHeight <= 0 )
    v17 = height;
  v41.fullImageROIBottomY = v17 - 1;
  return EncodeHDPhoto(
           imageInfo: &v40,
           codecParms: &v41,
           inBuf,
           width,
           height,
           tempUsed: (unsigned int *)&this->tempBufferUsed,
           outputBytes);
}


// ========================================================================
// ?CompressImageGrayScale@idBareHDP@@QAA_NPBEPAEHHHAAH@Z
// EA  : 0x828EC068
// RVA : 0x008EC068
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

int __fastcall idBareHDP::CompressImageGrayScale(
        idBareHDP *this,
        unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        unsigned int outBufSize,
        unsigned int width,
        unsigned int height,
        int *outputBytes)
{
  unsigned int imageROITopY; // r9
  int imageROIWidth; // r11
  int imageROIHeight; // r8
  unsigned int v15; // r11
  bool v16; // zf
  unsigned int v17; // r11
  int v19; // [sp+8h] [-1C8h]
  int v20; // [sp+Ch] [-1C4h]
  bool v21; // [sp+13h] [-1BDh]
  int v22; // [sp+14h] [-1BCh]
  int v23; // [sp+18h] [-1B8h]
  int v24; // [sp+1Ch] [-1B4h]
  int v25; // [sp+20h] [-1B0h]
  int v26; // [sp+24h] [-1ACh]
  int v27; // [sp+28h] [-1A8h]
  int v28; // [sp+2Ch] [-1A4h]
  int v29; // [sp+30h] [-1A0h]
  int v30; // [sp+34h] [-19Ch]
  int v31; // [sp+38h] [-198h]
  int v32; // [sp+3Ch] [-194h]
  int v33; // [sp+40h] [-190h]
  int v34; // [sp+44h] [-18Ch]
  int v35; // [sp+48h] [-188h]
  int v36; // [sp+4Ch] [-184h]
  int v37; // [sp+50h] [-180h]
  int v38; // [sp+58h] [-178h]
  int v39; // [sp+60h] [-170h]
  hdpImageInfo_t v40; // [sp+70h] [-160h] BYREF
  hdpCodecParms_t v41; // [sp+A0h] [-130h] BYREF
  hdpStream_t v42[2]; // [sp+170h] [-60h] BYREF

  InitGrayScale(
    imageInfo: &v40,
    codecParms: &v41,
    stream: v42,
    temp: this->tempBuffer,
    tempSize: this->tempBufferSize,
    buf: outBuf,
    bufSize: outBufSize,
    width,
    height: v19,
    quality: v20,
    entropyOnly: v21,
    a12: v22,
    a13: v23,
    a14: v24,
    a15: v25,
    a16: v26,
    a17: v27,
    a18: v28,
    a19: v29,
    a20: v30,
    a21: v31,
    a22: v32,
    a23: v33,
    a24: v34,
    a25: v35,
    a26: v36,
    a27: v37,
    a28: height,
    a29: v38,
    a30: this->quality,
    a31: v39,
    a32: false);
  imageROITopY = this->imageROITopY;
  imageROIWidth = this->imageROIWidth;
  imageROIHeight = this->imageROIHeight;
  v41.fullImageROILeftX = this->imageROILeftX;
  v41.fullImageROITopY = imageROITopY;
  v16 = imageROIWidth > 0;
  v15 = v41.fullImageROILeftX + imageROIWidth;
  if ( !v16 )
    v15 = width;
  v41.fullImageROIRightX = v15 - 1;
  v17 = imageROITopY + imageROIHeight;
  if ( imageROIHeight <= 0 )
    v17 = height;
  v41.fullImageROIBottomY = v17 - 1;
  return EncodeHDPhoto(
           imageInfo: &v40,
           codecParms: &v41,
           inBuf,
           width,
           height,
           tempUsed: (unsigned int *)&this->tempBufferUsed,
           outputBytes);
}


// ========================================================================
// ?DecompressImageGrayScale@idBareHDP@@QAA_NPBEPAEHHHH@Z
// EA  : 0x828EC130
// RVA : 0x008EC130
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

int __fastcall idBareHDP::DecompressImageGrayScale(
        idBareHDP *this,
        unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        unsigned int width,
        unsigned int height,
        unsigned int inputBytes,
        char mipLevel)
{
  unsigned int imageROITopY; // r9
  int imageROIWidth; // r11
  int imageROIHeight; // r8
  unsigned int v15; // r11
  bool v16; // zf
  unsigned int v17; // r11
  int v19; // [sp+8h] [-1C8h]
  int v20; // [sp+Ch] [-1C4h]
  bool v21; // [sp+13h] [-1BDh]
  int v22; // [sp+14h] [-1BCh]
  int v23; // [sp+18h] [-1B8h]
  int v24; // [sp+1Ch] [-1B4h]
  int v25; // [sp+20h] [-1B0h]
  int v26; // [sp+24h] [-1ACh]
  int v27; // [sp+28h] [-1A8h]
  int v28; // [sp+2Ch] [-1A4h]
  int v29; // [sp+30h] [-1A0h]
  int v30; // [sp+34h] [-19Ch]
  int v31; // [sp+38h] [-198h]
  int v32; // [sp+3Ch] [-194h]
  int v33; // [sp+40h] [-190h]
  int v34; // [sp+44h] [-18Ch]
  int v35; // [sp+48h] [-188h]
  int v36; // [sp+4Ch] [-184h]
  int v37; // [sp+50h] [-180h]
  int v38; // [sp+58h] [-178h]
  int v39; // [sp+60h] [-170h]
  hdpImageInfo_t v40; // [sp+70h] [-160h] BYREF
  hdpCodecParms_t v41; // [sp+A0h] [-130h] BYREF
  hdpStream_t v42[2]; // [sp+170h] [-60h] BYREF

  InitGrayScale(
    imageInfo: &v40,
    codecParms: &v41,
    stream: v42,
    temp: this->tempBuffer,
    tempSize: this->tempBufferSize,
    buf: inBuf,
    bufSize: inputBytes,
    width,
    height: v19,
    quality: v20,
    entropyOnly: v21,
    a12: v22,
    a13: v23,
    a14: v24,
    a15: v25,
    a16: v26,
    a17: v27,
    a18: v28,
    a19: v29,
    a20: v30,
    a21: v31,
    a22: v32,
    a23: v33,
    a24: v34,
    a25: v35,
    a26: v36,
    a27: v37,
    a28: height,
    a29: v38,
    a30: this->quality,
    a31: v39,
    a32: false);
  imageROITopY = this->imageROITopY;
  imageROIWidth = this->imageROIWidth;
  imageROIHeight = this->imageROIHeight;
  v41.fullImageROILeftX = this->imageROILeftX;
  v41.fullImageROITopY = imageROITopY;
  v16 = imageROIWidth > 0;
  v15 = v41.fullImageROILeftX + imageROIWidth;
  if ( !v16 )
    v15 = width;
  v41.fullImageROIRightX = v15 - 1;
  v17 = imageROITopY + imageROIHeight;
  if ( imageROIHeight <= 0 )
    v17 = height;
  v41.fullImageROIBottomY = v17 - 1;
  return DecodeHDPhoto(
           imageInfo: &v40,
           codecParms: &v41,
           outBuf,
           width,
           height,
           mipLevel,
           tempUsed: (unsigned int *)&this->tempBufferUsed,
           inputBytes: v41.fullImageROILeftX);
}


// ========================================================================
// ?CompressImageRGB@idBareHDP@@QAA_NPBEPAEHHHAAH@Z
// EA  : 0x828EC1F8
// RVA : 0x008EC1F8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

int __fastcall idBareHDP::CompressImageRGB(
        idBareHDP *this,
        unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        unsigned int outBufSize,
        unsigned int width,
        unsigned int height,
        int *outputBytes)
{
  unsigned int imageROITopY; // r9
  int imageROIWidth; // r11
  int imageROIHeight; // r8
  unsigned int v15; // r11
  bool v16; // zf
  unsigned int v17; // r11
  int v19; // [sp+8h] [-1C8h]
  int v20; // [sp+Ch] [-1C4h]
  bool v21; // [sp+13h] [-1BDh]
  bool v22; // [sp+17h] [-1B9h]
  int v23; // [sp+18h] [-1B8h]
  int v24; // [sp+1Ch] [-1B4h]
  int v25; // [sp+20h] [-1B0h]
  int v26; // [sp+24h] [-1ACh]
  int v27; // [sp+28h] [-1A8h]
  int v28; // [sp+2Ch] [-1A4h]
  int v29; // [sp+30h] [-1A0h]
  int v30; // [sp+34h] [-19Ch]
  int v31; // [sp+38h] [-198h]
  int v32; // [sp+3Ch] [-194h]
  int v33; // [sp+40h] [-190h]
  int v34; // [sp+44h] [-18Ch]
  int v35; // [sp+48h] [-188h]
  int v36; // [sp+4Ch] [-184h]
  int v37; // [sp+50h] [-180h]
  int v38; // [sp+58h] [-178h]
  int v39; // [sp+60h] [-170h]
  int v40; // [sp+68h] [-168h]
  hdpImageInfo_t v41; // [sp+70h] [-160h] BYREF
  hdpCodecParms_t v42; // [sp+A0h] [-130h] BYREF
  hdpStream_t v43[2]; // [sp+170h] [-60h] BYREF

  InitRGB(
    imageInfo: &v41,
    codecParms: &v42,
    stream: v43,
    temp: this->tempBuffer,
    tempSize: this->tempBufferSize,
    buf: outBuf,
    bufSize: outBufSize,
    width,
    height: v19,
    quality: v20,
    hasAlpha: v21,
    entropyOnly: v22,
    a13: v23,
    a14: v24,
    a15: v25,
    a16: v26,
    a17: v27,
    a18: v28,
    a19: v29,
    a20: v30,
    a21: v31,
    a22: v32,
    a23: v33,
    a24: v34,
    a25: v35,
    a26: v36,
    a27: v37,
    a28: height,
    a29: v38,
    a30: this->quality,
    a31: v39,
    a32: false,
    a33: v40,
    a34: false);
  imageROITopY = this->imageROITopY;
  imageROIWidth = this->imageROIWidth;
  imageROIHeight = this->imageROIHeight;
  v42.fullImageROILeftX = this->imageROILeftX;
  v42.fullImageROITopY = imageROITopY;
  v16 = imageROIWidth > 0;
  v15 = v42.fullImageROILeftX + imageROIWidth;
  if ( !v16 )
    v15 = width;
  v42.fullImageROIRightX = v15 - 1;
  v17 = imageROITopY + imageROIHeight;
  if ( imageROIHeight <= 0 )
    v17 = height;
  v42.fullImageROIBottomY = v17 - 1;
  return EncodeHDPhoto(
           imageInfo: &v41,
           codecParms: &v42,
           inBuf,
           width,
           height,
           tempUsed: (unsigned int *)&this->tempBufferUsed,
           outputBytes);
}


// ========================================================================
// ?DecompressImageRGB@idBareHDP@@QAA_NPBEPAEHHHH@Z
// EA  : 0x828EC2C8
// RVA : 0x008EC2C8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

int __fastcall idBareHDP::DecompressImageRGB(
        idBareHDP *this,
        unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        unsigned int width,
        unsigned int height,
        unsigned int inputBytes,
        char mipLevel)
{
  unsigned int imageROITopY; // r9
  int imageROIWidth; // r11
  int imageROIHeight; // r8
  unsigned int v15; // r11
  bool v16; // zf
  unsigned int v17; // r11
  int v19; // [sp+8h] [-1D8h]
  int v20; // [sp+Ch] [-1D4h]
  bool v21; // [sp+13h] [-1CDh]
  bool v22; // [sp+17h] [-1C9h]
  int v23; // [sp+18h] [-1C8h]
  int v24; // [sp+1Ch] [-1C4h]
  int v25; // [sp+20h] [-1C0h]
  int v26; // [sp+24h] [-1BCh]
  int v27; // [sp+28h] [-1B8h]
  int v28; // [sp+2Ch] [-1B4h]
  int v29; // [sp+30h] [-1B0h]
  int v30; // [sp+34h] [-1ACh]
  int v31; // [sp+38h] [-1A8h]
  int v32; // [sp+3Ch] [-1A4h]
  int v33; // [sp+40h] [-1A0h]
  int v34; // [sp+44h] [-19Ch]
  int v35; // [sp+48h] [-198h]
  int v36; // [sp+4Ch] [-194h]
  int v37; // [sp+50h] [-190h]
  int v38; // [sp+58h] [-188h]
  int v39; // [sp+60h] [-180h]
  int v40; // [sp+68h] [-178h]
  hdpImageInfo_t v41; // [sp+70h] [-170h] BYREF
  hdpCodecParms_t v42; // [sp+A0h] [-140h] BYREF
  hdpStream_t v43[2]; // [sp+170h] [-70h] BYREF

  InitRGB(
    imageInfo: &v41,
    codecParms: &v42,
    stream: v43,
    temp: this->tempBuffer,
    tempSize: this->tempBufferSize,
    buf: inBuf,
    bufSize: inputBytes,
    width,
    height: v19,
    quality: v20,
    hasAlpha: v21,
    entropyOnly: v22,
    a13: v23,
    a14: v24,
    a15: v25,
    a16: v26,
    a17: v27,
    a18: v28,
    a19: v29,
    a20: v30,
    a21: v31,
    a22: v32,
    a23: v33,
    a24: v34,
    a25: v35,
    a26: v36,
    a27: v37,
    a28: height,
    a29: v38,
    a30: this->quality,
    a31: v39,
    a32: false,
    a33: v40,
    a34: false);
  imageROITopY = this->imageROITopY;
  imageROIWidth = this->imageROIWidth;
  imageROIHeight = this->imageROIHeight;
  v42.fullImageROILeftX = this->imageROILeftX;
  v42.fullImageROITopY = imageROITopY;
  v16 = imageROIWidth > 0;
  v15 = v42.fullImageROILeftX + imageROIWidth;
  if ( !v16 )
    v15 = width;
  v42.fullImageROIRightX = v15 - 1;
  v17 = imageROITopY + imageROIHeight;
  if ( imageROIHeight <= 0 )
    v17 = height;
  v42.fullImageROIBottomY = v17 - 1;
  return DecodeHDPhoto(
           imageInfo: &v41,
           codecParms: &v42,
           outBuf,
           width,
           height,
           mipLevel,
           tempUsed: (unsigned int *)&this->tempBufferUsed,
           inputBytes: v42.fullImageROILeftX);
}


// ========================================================================
// ?CompressImageYCoCg@idBareHDP@@QAA_NPBEPAEHHHAAH@Z
// EA  : 0x828EC398
// RVA : 0x008EC398
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

int __fastcall idBareHDP::CompressImageYCoCg(
        idBareHDP *this,
        unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        unsigned int outBufSize,
        unsigned int width,
        unsigned int height,
        int *outputBytes)
{
  unsigned int imageROITopY; // r9
  int imageROIWidth; // r11
  int imageROIHeight; // r8
  unsigned int v15; // r11
  bool v16; // zf
  unsigned int v17; // r11
  int v19; // [sp+8h] [-1C8h]
  int v20; // [sp+Ch] [-1C4h]
  bool v21; // [sp+13h] [-1BDh]
  int v22; // [sp+14h] [-1BCh]
  int v23; // [sp+18h] [-1B8h]
  int v24; // [sp+1Ch] [-1B4h]
  int v25; // [sp+20h] [-1B0h]
  int v26; // [sp+24h] [-1ACh]
  int v27; // [sp+28h] [-1A8h]
  int v28; // [sp+2Ch] [-1A4h]
  int v29; // [sp+30h] [-1A0h]
  int v30; // [sp+34h] [-19Ch]
  int v31; // [sp+38h] [-198h]
  int v32; // [sp+3Ch] [-194h]
  int v33; // [sp+40h] [-190h]
  int v34; // [sp+44h] [-18Ch]
  int v35; // [sp+48h] [-188h]
  int v36; // [sp+4Ch] [-184h]
  int v37; // [sp+50h] [-180h]
  int v38; // [sp+58h] [-178h]
  int v39; // [sp+60h] [-170h]
  hdpImageInfo_t v40; // [sp+70h] [-160h] BYREF
  hdpCodecParms_t v41; // [sp+A0h] [-130h] BYREF
  hdpStream_t v42[2]; // [sp+170h] [-60h] BYREF

  InitYCoCg(
    imageInfo: &v40,
    codecParms: &v41,
    stream: v42,
    temp: this->tempBuffer,
    tempSize: this->tempBufferSize,
    buf: outBuf,
    bufSize: outBufSize,
    width,
    height: v19,
    quality: v20,
    entropyOnly: v21,
    a12: v22,
    a13: v23,
    a14: v24,
    a15: v25,
    a16: v26,
    a17: v27,
    a18: v28,
    a19: v29,
    a20: v30,
    a21: v31,
    a22: v32,
    a23: v33,
    a24: v34,
    a25: v35,
    a26: v36,
    a27: v37,
    a28: height,
    a29: v38,
    a30: this->quality,
    a31: v39,
    a32: false);
  imageROITopY = this->imageROITopY;
  imageROIWidth = this->imageROIWidth;
  imageROIHeight = this->imageROIHeight;
  v41.fullImageROILeftX = this->imageROILeftX;
  v41.fullImageROITopY = imageROITopY;
  v16 = imageROIWidth > 0;
  v15 = v41.fullImageROILeftX + imageROIWidth;
  if ( !v16 )
    v15 = width;
  v41.fullImageROIRightX = v15 - 1;
  v17 = imageROITopY + imageROIHeight;
  if ( imageROIHeight <= 0 )
    v17 = height;
  v41.fullImageROIBottomY = v17 - 1;
  return EncodeHDPhoto(
           imageInfo: &v40,
           codecParms: &v41,
           inBuf,
           width,
           height,
           tempUsed: (unsigned int *)&this->tempBufferUsed,
           outputBytes);
}


// ========================================================================
// ?DecompressImageYCoCg@idBareHDP@@QAA_NPBEPAEHHHH@Z
// EA  : 0x828EC460
// RVA : 0x008EC460
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

int __fastcall idBareHDP::DecompressImageYCoCg(
        idBareHDP *this,
        unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        unsigned int width,
        unsigned int height,
        unsigned int inputBytes,
        char mipLevel)
{
  unsigned int imageROITopY; // r9
  int imageROIWidth; // r11
  int imageROIHeight; // r8
  unsigned int v15; // r11
  bool v16; // zf
  unsigned int v17; // r11
  int v19; // [sp+8h] [-1C8h]
  int v20; // [sp+Ch] [-1C4h]
  bool v21; // [sp+13h] [-1BDh]
  int v22; // [sp+14h] [-1BCh]
  int v23; // [sp+18h] [-1B8h]
  int v24; // [sp+1Ch] [-1B4h]
  int v25; // [sp+20h] [-1B0h]
  int v26; // [sp+24h] [-1ACh]
  int v27; // [sp+28h] [-1A8h]
  int v28; // [sp+2Ch] [-1A4h]
  int v29; // [sp+30h] [-1A0h]
  int v30; // [sp+34h] [-19Ch]
  int v31; // [sp+38h] [-198h]
  int v32; // [sp+3Ch] [-194h]
  int v33; // [sp+40h] [-190h]
  int v34; // [sp+44h] [-18Ch]
  int v35; // [sp+48h] [-188h]
  int v36; // [sp+4Ch] [-184h]
  int v37; // [sp+50h] [-180h]
  int v38; // [sp+58h] [-178h]
  int v39; // [sp+60h] [-170h]
  hdpImageInfo_t v40; // [sp+70h] [-160h] BYREF
  hdpCodecParms_t v41; // [sp+A0h] [-130h] BYREF
  hdpStream_t v42[2]; // [sp+170h] [-60h] BYREF

  InitYCoCg(
    imageInfo: &v40,
    codecParms: &v41,
    stream: v42,
    temp: this->tempBuffer,
    tempSize: this->tempBufferSize,
    buf: inBuf,
    bufSize: inputBytes,
    width,
    height: v19,
    quality: v20,
    entropyOnly: v21,
    a12: v22,
    a13: v23,
    a14: v24,
    a15: v25,
    a16: v26,
    a17: v27,
    a18: v28,
    a19: v29,
    a20: v30,
    a21: v31,
    a22: v32,
    a23: v33,
    a24: v34,
    a25: v35,
    a26: v36,
    a27: v37,
    a28: height,
    a29: v38,
    a30: this->quality,
    a31: v39,
    a32: false);
  imageROITopY = this->imageROITopY;
  imageROIWidth = this->imageROIWidth;
  imageROIHeight = this->imageROIHeight;
  v41.fullImageROILeftX = this->imageROILeftX;
  v41.fullImageROITopY = imageROITopY;
  v16 = imageROIWidth > 0;
  v15 = v41.fullImageROILeftX + imageROIWidth;
  if ( !v16 )
    v15 = width;
  v41.fullImageROIRightX = v15 - 1;
  v17 = imageROITopY + imageROIHeight;
  if ( imageROIHeight <= 0 )
    v17 = height;
  v41.fullImageROIBottomY = v17 - 1;
  return DecodeHDPhoto(
           imageInfo: &v40,
           codecParms: &v41,
           outBuf,
           width,
           height,
           mipLevel,
           tempUsed: (unsigned int *)&this->tempBufferUsed,
           inputBytes: v41.fullImageROILeftX);
}


// ========================================================================
// ?CompressImageNormalMap@idBareHDP@@QAA_NPBEPAEHHHAAH@Z
// EA  : 0x828EC528
// RVA : 0x008EC528
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

int __fastcall idBareHDP::CompressImageNormalMap(
        idBareHDP *this,
        unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        unsigned int outBufSize,
        unsigned int width,
        unsigned int height,
        int *outputBytes)
{
  unsigned int imageROITopY; // r9
  int imageROIWidth; // r11
  int imageROIHeight; // r8
  unsigned int v15; // r11
  bool v16; // zf
  unsigned int v17; // r11
  int v19; // [sp+8h] [-1C8h]
  int v20; // [sp+Ch] [-1C4h]
  bool v21; // [sp+13h] [-1BDh]
  int v22; // [sp+14h] [-1BCh]
  int v23; // [sp+18h] [-1B8h]
  int v24; // [sp+1Ch] [-1B4h]
  int v25; // [sp+20h] [-1B0h]
  int v26; // [sp+24h] [-1ACh]
  int v27; // [sp+28h] [-1A8h]
  int v28; // [sp+2Ch] [-1A4h]
  int v29; // [sp+30h] [-1A0h]
  int v30; // [sp+34h] [-19Ch]
  int v31; // [sp+38h] [-198h]
  int v32; // [sp+3Ch] [-194h]
  int v33; // [sp+40h] [-190h]
  int v34; // [sp+44h] [-18Ch]
  int v35; // [sp+48h] [-188h]
  int v36; // [sp+4Ch] [-184h]
  int v37; // [sp+50h] [-180h]
  int v38; // [sp+58h] [-178h]
  int v39; // [sp+60h] [-170h]
  hdpImageInfo_t v40; // [sp+70h] [-160h] BYREF
  hdpCodecParms_t v41; // [sp+A0h] [-130h] BYREF
  hdpStream_t v42[2]; // [sp+170h] [-60h] BYREF

  InitNormalMap(
    imageInfo: &v40,
    codecParms: &v41,
    stream: v42,
    temp: this->tempBuffer,
    tempSize: this->tempBufferSize,
    buf: outBuf,
    bufSize: outBufSize,
    width,
    height: v19,
    quality: v20,
    entropyOnly: v21,
    a12: v22,
    a13: v23,
    a14: v24,
    a15: v25,
    a16: v26,
    a17: v27,
    a18: v28,
    a19: v29,
    a20: v30,
    a21: v31,
    a22: v32,
    a23: v33,
    a24: v34,
    a25: v35,
    a26: v36,
    a27: v37,
    a28: height,
    a29: v38,
    a30: this->quality,
    a31: v39,
    a32: false);
  imageROITopY = this->imageROITopY;
  imageROIWidth = this->imageROIWidth;
  imageROIHeight = this->imageROIHeight;
  v41.fullImageROILeftX = this->imageROILeftX;
  v41.fullImageROITopY = imageROITopY;
  v16 = imageROIWidth > 0;
  v15 = v41.fullImageROILeftX + imageROIWidth;
  if ( !v16 )
    v15 = width;
  v41.fullImageROIRightX = v15 - 1;
  v17 = imageROITopY + imageROIHeight;
  if ( imageROIHeight <= 0 )
    v17 = height;
  v41.fullImageROIBottomY = v17 - 1;
  return EncodeHDPhoto(
           imageInfo: &v40,
           codecParms: &v41,
           inBuf,
           width,
           height,
           tempUsed: (unsigned int *)&this->tempBufferUsed,
           outputBytes);
}


// ========================================================================
// ?DecompressImageNormalMap@idBareHDP@@QAA_NPBEPAEHHHH@Z
// EA  : 0x828EC5F0
// RVA : 0x008EC5F0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.cpp
// ========================================================================

int __fastcall idBareHDP::DecompressImageNormalMap(
        idBareHDP *this,
        unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        unsigned int width,
        unsigned int height,
        unsigned int inputBytes,
        char mipLevel)
{
  unsigned int imageROITopY; // r9
  int imageROIWidth; // r11
  int imageROIHeight; // r8
  unsigned int v15; // r11
  bool v16; // zf
  unsigned int v17; // r11
  int v19; // [sp+8h] [-1C8h]
  int v20; // [sp+Ch] [-1C4h]
  bool v21; // [sp+13h] [-1BDh]
  int v22; // [sp+14h] [-1BCh]
  int v23; // [sp+18h] [-1B8h]
  int v24; // [sp+1Ch] [-1B4h]
  int v25; // [sp+20h] [-1B0h]
  int v26; // [sp+24h] [-1ACh]
  int v27; // [sp+28h] [-1A8h]
  int v28; // [sp+2Ch] [-1A4h]
  int v29; // [sp+30h] [-1A0h]
  int v30; // [sp+34h] [-19Ch]
  int v31; // [sp+38h] [-198h]
  int v32; // [sp+3Ch] [-194h]
  int v33; // [sp+40h] [-190h]
  int v34; // [sp+44h] [-18Ch]
  int v35; // [sp+48h] [-188h]
  int v36; // [sp+4Ch] [-184h]
  int v37; // [sp+50h] [-180h]
  int v38; // [sp+58h] [-178h]
  int v39; // [sp+60h] [-170h]
  hdpImageInfo_t v40; // [sp+70h] [-160h] BYREF
  hdpCodecParms_t v41; // [sp+A0h] [-130h] BYREF
  hdpStream_t v42[2]; // [sp+170h] [-60h] BYREF

  InitNormalMap(
    imageInfo: &v40,
    codecParms: &v41,
    stream: v42,
    temp: this->tempBuffer,
    tempSize: this->tempBufferSize,
    buf: inBuf,
    bufSize: inputBytes,
    width,
    height: v19,
    quality: v20,
    entropyOnly: v21,
    a12: v22,
    a13: v23,
    a14: v24,
    a15: v25,
    a16: v26,
    a17: v27,
    a18: v28,
    a19: v29,
    a20: v30,
    a21: v31,
    a22: v32,
    a23: v33,
    a24: v34,
    a25: v35,
    a26: v36,
    a27: v37,
    a28: height,
    a29: v38,
    a30: this->quality,
    a31: v39,
    a32: false);
  imageROITopY = this->imageROITopY;
  imageROIWidth = this->imageROIWidth;
  imageROIHeight = this->imageROIHeight;
  v41.fullImageROILeftX = this->imageROILeftX;
  v41.fullImageROITopY = imageROITopY;
  v16 = imageROIWidth > 0;
  v15 = v41.fullImageROILeftX + imageROIWidth;
  if ( !v16 )
    v15 = width;
  v41.fullImageROIRightX = v15 - 1;
  v17 = imageROITopY + imageROIHeight;
  if ( imageROIHeight <= 0 )
    v17 = height;
  v41.fullImageROIBottomY = v17 - 1;
  return DecodeHDPhoto(
           imageInfo: &v40,
           codecParms: &v41,
           outBuf,
           width,
           height,
           mipLevel,
           tempUsed: (unsigned int *)&this->tempBufferUsed,
           inputBytes: v41.fullImageROILeftX);
}

