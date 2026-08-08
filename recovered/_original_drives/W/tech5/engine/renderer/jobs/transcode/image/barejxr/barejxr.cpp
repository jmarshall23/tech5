
// ========================================================================
// ??0idBareJXR@@QAA@XZ
// EA  : 0x82902D48
// RVA : 0x00902D48
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

idBareJXR *__fastcall idBareJXR::idBareJXR(idBareJXR *this)
{
  this->quality = 0;
  this->tempBuffer = nullptr;
  this->tempBufferSize = 0;
  this->tempBufferUsed = 0;
  this->cROILeftX = 0;
  this->cROITopY = 0;
  this->cROIWidth = 0;
  this->cROIHeight = 0;
  return this;
}


// ========================================================================
// ?EstimateTempMemory@idBareJXR@@SAHHHH@Z
// EA  : 0x82902D70
// RVA : 0x00902D70
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

// attributes: thunk
int __fastcall idBareJXR::EstimateTempMemory(int width, int height, int numComponents)
{
  return jxr_estimate_temp_memory(width, height, numChannels: numComponents);
}


// ========================================================================
// ?JXR_CompressImageMono@@YAXPAUjxr_image@@HHPAH@Z
// EA  : 0x82902D78
// RVA : 0x00902D78
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

void __fastcall JXR_CompressImageMono(jxr_image *image, int mx, int my, int *data)
{
  _DWORD *user_data; // r3
  int v8; // r10
  int v9; // r9
  int v10; // r11
  int i; // ctr
  int v12; // r7
  int v13; // r6

  user_data = jxr_get_user_data(image);
  v8 = 0;
  v9 = 16 * (*user_data * my + mx) + user_data[3];
  do
  {
    v10 = 0;
    for ( i = 16; i != 0; --i )
    {
      v12 = *(unsigned __int8 *)(v10 + v9);
      v13 = v8 + v10++;
      data[v13] = v12;
    }
    v8 += 16;
    v9 += *user_data;
  }
  while ( v8 < 256 );
}


// ========================================================================
// ?CompressImageMono@idBareJXR@@QAA_NPBEPAEHHHAAH@Z
// EA  : 0x82902DF0
// RVA : 0x00902DF0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

int __fastcall idBareJXR::CompressImageMono(
        idBareJXR *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        unsigned int outBufSize,
        int width,
        int height,
        int *outputBytes)
{
  jxr_image *image; // r27
  unsigned int v12; // r3
  unsigned __int8 v14[16]; // [sp+50h] [-50h] BYREF
  _DWORD v15[16]; // [sp+60h] [-40h] BYREF

  v15[3] = inBuf;
  v15[0] = width;
  v15[1] = height;
  v15[2] = 1;
  v14[0] = 0;
  v14[1] = 0;
  v14[2] = 0;
  v14[3] = 0;
  v14[4] = 0;
  image = jxr_create_image(width, height, windowing: v14, buffer: this->tempBuffer);
  v12 = jxr_image_size();
  jxr_set_temp_memory(image, buffer: this->tempBuffer, size: this->tempBufferSize, used: v12);
  jxr_set_user_data(image, data: v15);
  jxr_set_INTERNAL_CLR_FMT(image, fmt: 0, channels: 1u);
  jxr_set_OUTPUT_CLR_FMT(image, fmt: JXR_OCF_YONLY);
  jxr_set_OUTPUT_BITDEPTH(image, bd: JXR_BD8);
  jxr_set_OVERLAP_FILTER(image, flag: 1);
  jxr_set_QP_UNIFORM(image, quant: this->quality);
  jxr_set_BANDS_PRESENT(image, bp: (jxr_bands_present_e)(this->quality != 0));
  jxr_set_block_input(image, fun: JXR_CompressImageMono);
  *outputBytes = jxr_write_image_bitstream(image, data: outBuf, size: outBufSize);
  this->tempBufferUsed = jxr_used_temp_memory(image);
  return 1;
}


// ========================================================================
// ?JXR_CompressImageGrayScale@@YAXPAUjxr_image@@HHPAH@Z
// EA  : 0x82902F08
// RVA : 0x00902F08
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

void __fastcall JXR_CompressImageGrayScale(jxr_image *image, int mx, int my, int *data)
{
  _DWORD *user_data; // r3
  int v8; // r7
  int v9; // r29
  int v10; // r10
  unsigned __int8 *v11; // r11
  int i; // ctr
  int *v13; // r8
  int v14; // r28
  int v15; // r6
  int v16; // r8

  user_data = jxr_get_user_data(image);
  v8 = 0;
  v9 = ((*user_data * my + mx) << 6) + user_data[3];
  do
  {
    v10 = 0;
    v11 = (unsigned __int8 *)(v9 - 2);
    for ( i = 4; i != 0; --i )
    {
      v13 = &data[v8 + v10];
      v14 = v8 + 3 + v10;
      v15 = v8 + v10 + 2;
      *v13 = (2 * (v11[3] + v11[4] + v11[2]) + 3) / 6;
      v10 += 4;
      v13[1] = (2 * (v11[6] + v11[7] + v11[8]) + 3) / 6;
      data[v15] = (2 * (v11[10] + v11[11] + v11[12]) + 3) / 6;
      v16 = v11[14] + v11[15];
      v11 += 16;
      data[v14] = (2 * (v16 + *v11) + 3) / 6;
    }
    v8 += 16;
    v9 += 4 * *user_data;
  }
  while ( v8 < 256 );
}


// ========================================================================
// ?CompressImageGrayScale@idBareJXR@@QAA_NPBEPAEHHHAAH@Z
// EA  : 0x82903030
// RVA : 0x00903030
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

int __fastcall idBareJXR::CompressImageGrayScale(
        idBareJXR *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        unsigned int outBufSize,
        int width,
        int height,
        int *outputBytes)
{
  jxr_image *image; // r27
  unsigned int v12; // r3
  unsigned __int8 v14[16]; // [sp+50h] [-50h] BYREF
  _DWORD v15[16]; // [sp+60h] [-40h] BYREF

  v15[3] = inBuf;
  v15[0] = width;
  v15[1] = height;
  v15[2] = 1;
  v14[0] = 0;
  v14[1] = 0;
  v14[2] = 0;
  v14[3] = 0;
  v14[4] = 0;
  image = jxr_create_image(width, height, windowing: v14, buffer: this->tempBuffer);
  v12 = jxr_image_size();
  jxr_set_temp_memory(image, buffer: this->tempBuffer, size: this->tempBufferSize, used: v12);
  jxr_set_user_data(image, data: v15);
  jxr_set_INTERNAL_CLR_FMT(image, fmt: 0, channels: 1u);
  jxr_set_OUTPUT_CLR_FMT(image, fmt: JXR_OCF_YONLY);
  jxr_set_OUTPUT_BITDEPTH(image, bd: JXR_BD8);
  jxr_set_OVERLAP_FILTER(image, flag: 1);
  jxr_set_QP_UNIFORM(image, quant: this->quality);
  jxr_set_BANDS_PRESENT(image, bp: (jxr_bands_present_e)(this->quality != 0));
  jxr_set_block_input(image, fun: JXR_CompressImageGrayScale);
  *outputBytes = jxr_write_image_bitstream(image, data: outBuf, size: outBufSize);
  this->tempBufferUsed = jxr_used_temp_memory(image);
  return 1;
}


// ========================================================================
// ?JXR_CompressImageRGB@@YAXPAUjxr_image@@HHPAH@Z
// EA  : 0x82903148
// RVA : 0x00903148
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

void __fastcall JXR_CompressImageRGB(jxr_image *image, int mx, int my, int *data)
{
  _DWORD *user_data; // r3
  int v8; // r7
  int v9; // r6
  int v10; // r9
  unsigned __int8 *v11; // r11
  int i; // ctr
  int *v13; // r10

  user_data = jxr_get_user_data(image);
  v8 = 0;
  v9 = ((*user_data * my + mx) << 6) + user_data[3];
  do
  {
    v10 = 0;
    v11 = (unsigned __int8 *)(v9 - 2);
    for ( i = 16; i != 0; --i )
    {
      v13 = &data[3 * v8 + 3 * v10++];
      *v13 = v11[2];
      v13[1] = v11[3];
      v11 += 4;
      v13[2] = *v11;
    }
    v8 += 16;
    v9 += 4 * *user_data;
  }
  while ( v8 < 256 );
}


// ========================================================================
// ?CompressImageRGB@idBareJXR@@QAA_NPBEPAEHHHAAH@Z
// EA  : 0x829031E8
// RVA : 0x009031E8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

int __fastcall idBareJXR::CompressImageRGB(
        idBareJXR *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        unsigned int outBufSize,
        int width,
        int height,
        int *outputBytes)
{
  int quality; // r11
  int v12; // r10
  void *tempBuffer; // r6
  jxr_image *image; // r27
  unsigned int v15; // r3
  unsigned __int8 v17[4]; // [sp+50h] [-50h] BYREF
  unsigned __int8 v18[12]; // [sp+54h] [-4Ch] BYREF
  _DWORD v19[16]; // [sp+60h] [-40h] BYREF

  quality = this->quality;
  v19[0] = width;
  v19[1] = height;
  v19[2] = 3;
  v19[3] = inBuf;
  v17[0] = quality;
  if ( quality >= 16 )
  {
    v12 = quality + 20;
    if ( quality <= 48 )
      v12 = quality + 18;
    if ( v12 > 255 )
      LOBYTE(v12) = -1;
  }
  else
  {
    LOBYTE(v12) = 2 * quality;
  }
  v17[1] = v12;
  tempBuffer = this->tempBuffer;
  v18[0] = 0;
  v18[1] = 0;
  v18[2] = 0;
  v18[3] = 0;
  v18[4] = 0;
  image = jxr_create_image(width, height, windowing: v18, buffer: tempBuffer);
  v15 = jxr_image_size();
  jxr_set_temp_memory(image, buffer: this->tempBuffer, size: this->tempBufferSize, used: v15);
  jxr_set_user_data(image, data: v19);
  jxr_set_INTERNAL_CLR_FMT(image, fmt: 3u, channels: 3u);
  jxr_set_OUTPUT_CLR_FMT(image, fmt: JXR_OCF_RGB);
  jxr_set_OUTPUT_BITDEPTH(image, bd: JXR_BD8);
  jxr_set_OVERLAP_FILTER(image, flag: 1);
  jxr_set_QP_SEPARATE(image, quant_per_channel: v17);
  jxr_set_BANDS_PRESENT(image, bp: (jxr_bands_present_e)(this->quality != 0));
  jxr_set_block_input(image, fun: JXR_CompressImageRGB);
  *outputBytes = jxr_write_image_bitstream(image, data: outBuf, size: outBufSize);
  this->tempBufferUsed = jxr_used_temp_memory(image);
  return 1;
}


// ========================================================================
// ?JXR_CompressImageYCoCg@@YAXPAUjxr_image@@HHPAH@Z
// EA  : 0x82903338
// RVA : 0x00903338
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

void __fastcall JXR_CompressImageYCoCg(jxr_image *image, int mx, int my, int *data)
{
  _DWORD *user_data; // r3
  int v8; // r7
  int v9; // r6
  int v10; // r9
  unsigned __int8 *v11; // r11
  int i; // ctr
  int *v13; // r10

  user_data = jxr_get_user_data(image);
  v8 = 0;
  v9 = ((*user_data * my + mx) << 6) + user_data[3];
  do
  {
    v10 = 0;
    v11 = (unsigned __int8 *)(v9 - 3);
    for ( i = 16; i != 0; --i )
    {
      v13 = &data[3 * v8 + 3 * v10++];
      *v13 = v11[6];
      v13[1] = v11[3];
      v11 += 4;
      v13[2] = *v11;
    }
    v8 += 16;
    v9 += 4 * *user_data;
  }
  while ( v8 < 256 );
}


// ========================================================================
// ?CompressImageYCoCg@idBareJXR@@QAA_NPBEPAEHHHAAH@Z
// EA  : 0x829033D8
// RVA : 0x009033D8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

int __fastcall idBareJXR::CompressImageYCoCg(
        idBareJXR *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        unsigned int outBufSize,
        int width,
        int height,
        int *outputBytes)
{
  int quality; // r11
  int v12; // r10
  void *tempBuffer; // r6
  jxr_image *image; // r27
  unsigned int v15; // r3
  unsigned __int8 v17[4]; // [sp+50h] [-50h] BYREF
  unsigned __int8 v18[12]; // [sp+54h] [-4Ch] BYREF
  _DWORD v19[16]; // [sp+60h] [-40h] BYREF

  quality = this->quality;
  v19[0] = width;
  v19[1] = height;
  v19[2] = 3;
  v19[3] = inBuf;
  v17[0] = quality;
  if ( quality >= 16 )
  {
    v12 = quality + 20;
    if ( quality <= 48 )
      v12 = quality + 18;
    if ( v12 > 255 )
      LOBYTE(v12) = -1;
  }
  else
  {
    LOBYTE(v12) = 2 * quality;
  }
  v17[1] = v12;
  tempBuffer = this->tempBuffer;
  v18[0] = 0;
  v18[1] = 0;
  v18[2] = 0;
  v18[3] = 0;
  v18[4] = 0;
  image = jxr_create_image(width, height, windowing: v18, buffer: tempBuffer);
  v15 = jxr_image_size();
  jxr_set_temp_memory(image, buffer: this->tempBuffer, size: this->tempBufferSize, used: v15);
  jxr_set_user_data(image, data: v19);
  jxr_set_INTERNAL_CLR_FMT(image, fmt: 3u, channels: 3u);
  jxr_set_OUTPUT_CLR_FMT(image, fmt: JXR_OCF_YUV444);
  jxr_set_OUTPUT_BITDEPTH(image, bd: JXR_BD8);
  jxr_set_OVERLAP_FILTER(image, flag: 1);
  jxr_set_QP_SEPARATE(image, quant_per_channel: v17);
  jxr_set_BANDS_PRESENT(image, bp: (jxr_bands_present_e)(this->quality != 0));
  jxr_set_block_input(image, fun: JXR_CompressImageYCoCg);
  *outputBytes = jxr_write_image_bitstream(image, data: outBuf, size: outBufSize);
  this->tempBufferUsed = jxr_used_temp_memory(image);
  return 1;
}


// ========================================================================
// ?JXR_CompressImageNormalMap@@YAXPAUjxr_image@@HHPAH@Z
// EA  : 0x82903528
// RVA : 0x00903528
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

void __fastcall JXR_CompressImageNormalMap(jxr_image *image, int mx, int my, int *data)
{
  _DWORD *user_data; // r3
  int v8; // r7
  int v9; // r6
  int v10; // r11
  unsigned __int8 *v11; // r10
  int i; // ctr
  int v13; // r9
  int *v14; // r9

  user_data = jxr_get_user_data(image);
  v8 = 0;
  v9 = ((*user_data * my + mx) << 6) + user_data[3];
  do
  {
    v10 = 0;
    v11 = (unsigned __int8 *)(v9 - 3);
    for ( i = 16; i != 0; --i )
    {
      v13 = 2 * (v8 + v10++);
      v14 = &data[v13];
      *v14 = v11[6];
      v11 += 4;
      v14[1] = *v11;
    }
    v8 += 16;
    v9 += 4 * *user_data;
  }
  while ( v8 < 256 );
}


// ========================================================================
// ?CompressImageNormalMap@idBareJXR@@QAA_NPBEPAEHHHAAH@Z
// EA  : 0x829035B8
// RVA : 0x009035B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

int __fastcall idBareJXR::CompressImageNormalMap(
        idBareJXR *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        unsigned int outBufSize,
        int width,
        int height,
        int *outputBytes)
{
  jxr_image *image; // r27
  unsigned int v12; // r3
  unsigned __int8 v14[16]; // [sp+50h] [-50h] BYREF
  _DWORD v15[16]; // [sp+60h] [-40h] BYREF

  v15[3] = inBuf;
  v15[0] = width;
  v15[1] = height;
  v15[2] = 2;
  v14[0] = 0;
  v14[1] = 0;
  v14[2] = 0;
  v14[3] = 0;
  v14[4] = 0;
  image = jxr_create_image(width, height, windowing: v14, buffer: this->tempBuffer);
  v12 = jxr_image_size();
  jxr_set_temp_memory(image, buffer: this->tempBuffer, size: this->tempBufferSize, used: v12);
  jxr_set_user_data(image, data: v15);
  jxr_set_INTERNAL_CLR_FMT(image, fmt: 6u, channels: 2u);
  jxr_set_OUTPUT_CLR_FMT(image, fmt: JXR_OCF_NCOMPONENT);
  jxr_set_OUTPUT_BITDEPTH(image, bd: JXR_BD8);
  jxr_set_OVERLAP_FILTER(image, flag: 1);
  jxr_set_QP_UNIFORM(image, quant: this->quality);
  jxr_set_BANDS_PRESENT(image, bp: (jxr_bands_present_e)(this->quality != 0));
  jxr_set_block_input(image, fun: JXR_CompressImageNormalMap);
  *outputBytes = jxr_write_image_bitstream(image, data: outBuf, size: outBufSize);
  this->tempBufferUsed = jxr_used_temp_memory(image);
  return 1;
}


// ========================================================================
// ?DecompressImageGrayScaleMacroBlock@idBareJXR@@QAAXPAEHH@Z
// EA  : 0x829036D0
// RVA : 0x009036D0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

void __fastcall idBareJXR::DecompressImageGrayScaleMacroBlock(
        idBareJXR *this,
        unsigned __int8 *outBuf,
        int blockNum,
        int byteStride)
{
  jxr_output_mb_id_grayscale(image: (jxr_image *)this->tempBuffer, mx: blockNum, buffer: outBuf, byteStride);
}


// ========================================================================
// ?BeginDecompressImageGrayScaleMacroBlockRow@idBareJXR@@QAAXXZ
// EA  : 0x829036E8
// RVA : 0x009036E8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

void __fastcall idBareJXR::BeginDecompressImageGrayScaleMacroBlockRow(idBareJXR *this)
{
  jxr_image *tempBuffer; // r31
  int stripe_bitstream; // r3
  bool v3; // cr58
  int v4; // r3

  tempBuffer = (jxr_image *)this->tempBuffer;
  stripe_bitstream = jxr_read_stripe_bitstream(image: tempBuffer);
  if ( stripe_bitstream >= 0 )
  {
    v3 = stripe_bitstream == 0;
    do
    {
      if ( v3 )
        break;
      v4 = jxr_read_stripe_bitstream(image: tempBuffer);
      v3 = v4 == 0;
    }
    while ( v4 >= 0 );
  }
}


// ========================================================================
// ?DecompressImageRGBMacroBlock@idBareJXR@@QAAXPAEHH@Z
// EA  : 0x82903738
// RVA : 0x00903738
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

void __fastcall idBareJXR::DecompressImageRGBMacroBlock(
        idBareJXR *this,
        unsigned __int8 *outBuf,
        int blockNum,
        int byteStride)
{
  jxr_output_mb_id_rgb(image: (jxr_image *)this->tempBuffer, mx: blockNum, buffer: outBuf, byteStride);
}


// ========================================================================
// ?BeginDecompressImageRGB@idBareJXR@@QAAXPBEHHH@Z
// EA  : 0x82903750
// RVA : 0x00903750
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

void __fastcall idBareJXR::BeginDecompressImageRGB(
        idBareJXR *this,
        const unsigned __int8 *inBuf,
        int width,
        int height,
        unsigned int inputBytes)
{
  jxr_image *input; // r28
  unsigned int v9; // r3

  input = jxr_create_input(buffer: this->tempBuffer);
  v9 = jxr_image_size();
  jxr_set_temp_memory(image: input, buffer: this->tempBuffer, size: this->tempBufferSize, used: v9);
  jxr_init_read_stripe_bitstream(image: input, data: inBuf, size: inputBytes);
}


// ========================================================================
// ?DecompressImageYCoCgMacroBlock@idBareJXR@@QAAXPAEHH@Z
// EA  : 0x829037A8
// RVA : 0x009037A8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

void __fastcall idBareJXR::DecompressImageYCoCgMacroBlock(
        idBareJXR *this,
        unsigned __int8 *outBuf,
        int blockNum,
        int byteStride)
{
  jxr_output_mb_id_cocg_y(image: (jxr_image *)this->tempBuffer, mx: blockNum, buffer: outBuf, byteStride);
}


// ========================================================================
// ?DecompressImageNormalMapMacroBlock@idBareJXR@@QAAXPAEHH@Z
// EA  : 0x829037C0
// RVA : 0x009037C0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

void __fastcall idBareJXR::DecompressImageNormalMapMacroBlock(
        idBareJXR *this,
        unsigned __int8 *outBuf,
        int blockNum,
        int byteStride)
{
  jxr_output_mb_id_normal_y_x(image: (jxr_image *)this->tempBuffer, mx: blockNum, buffer: outBuf, byteStride);
}


// ========================================================================
// ?DecompressImageMono@idBareJXR@@QAA_NPBEPAEHHHH@Z
// EA  : 0x829037D8
// RVA : 0x009037D8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

int __fastcall idBareJXR::DecompressImageMono(
        idBareJXR *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height,
        unsigned int inputBytes,
        int mipLevel)
{
  jxr_image *input; // r25
  unsigned int v14; // r3
  unsigned int v15; // r27
  jxr_image *tempBuffer; // r31
  int stripe_bitstream; // r3
  bool v18; // cr58
  int v19; // r3
  int i; // r31

  input = jxr_create_input(buffer: this->tempBuffer);
  v14 = jxr_image_size();
  jxr_set_temp_memory(image: input, buffer: this->tempBuffer, size: this->tempBufferSize, used: v14);
  jxr_init_read_stripe_bitstream(image: input, data: inBuf, size: inputBytes);
  if ( height > 0 )
  {
    v15 = ((unsigned int)(height - 1) >> 4) + 1;
    do
    {
      tempBuffer = (jxr_image *)this->tempBuffer;
      stripe_bitstream = jxr_read_stripe_bitstream(image: tempBuffer);
      if ( stripe_bitstream >= 0 )
      {
        v18 = stripe_bitstream == 0;
        do
        {
          if ( v18 )
            break;
          v19 = jxr_read_stripe_bitstream(image: tempBuffer);
          v18 = v19 == 0;
        }
        while ( v19 >= 0 );
      }
      for ( i = 0; i < width; i += 16 )
        jxr_output_mb_id_mono(
          image: (jxr_image *)this->tempBuffer,
          mx: (unsigned int)i >> 4,
          buffer: &outBuf[i],
          byteStride: width);
      --v15;
      outBuf += 16 * width;
    }
    while ( v15 != 0 );
  }
  return 1;
}


// ========================================================================
// ?DecompressImageGrayScale@idBareJXR@@QAA_NPBEPAEHHHH@Z
// EA  : 0x829038B8
// RVA : 0x009038B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

int __fastcall idBareJXR::DecompressImageGrayScale(
        idBareJXR *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height,
        unsigned int inputBytes,
        int mipLevel)
{
  jxr_image *input; // r25
  unsigned int v14; // r3
  int v15; // r29
  unsigned int v16; // r26
  jxr_image *tempBuffer; // r31
  int stripe_bitstream; // r3
  bool v19; // cr58
  int v20; // r3
  int i; // r31

  input = jxr_create_input(buffer: this->tempBuffer);
  v14 = jxr_image_size();
  jxr_set_temp_memory(image: input, buffer: this->tempBuffer, size: this->tempBufferSize, used: v14);
  jxr_init_read_stripe_bitstream(image: input, data: inBuf, size: inputBytes);
  if ( height > 0 )
  {
    v15 = 0;
    v16 = ((unsigned int)(height - 1) >> 4) + 1;
    do
    {
      tempBuffer = (jxr_image *)this->tempBuffer;
      stripe_bitstream = jxr_read_stripe_bitstream(image: tempBuffer);
      if ( stripe_bitstream >= 0 )
      {
        v19 = stripe_bitstream == 0;
        do
        {
          if ( v19 )
            break;
          v20 = jxr_read_stripe_bitstream(image: tempBuffer);
          v19 = v20 == 0;
        }
        while ( v20 >= 0 );
      }
      for ( i = 0; i < width; i += 16 )
        jxr_output_mb_id_grayscale(
          image: (jxr_image *)this->tempBuffer,
          mx: (unsigned int)i >> 4,
          buffer: &outBuf[4 * v15 + 4 * i],
          byteStride: width);
      --v16;
      v15 += 16 * width;
    }
    while ( v16 != 0 );
  }
  return 1;
}


// ========================================================================
// ?DecompressImageRGB@idBareJXR@@QAA_NPBEPAEHHHH@Z
// EA  : 0x829039A8
// RVA : 0x009039A8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

int __fastcall idBareJXR::DecompressImageRGB(
        idBareJXR *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height,
        unsigned int inputBytes,
        int mipLevel)
{
  jxr_image *input; // r25
  unsigned int v14; // r3
  int v15; // r29
  unsigned int v16; // r26
  jxr_image *tempBuffer; // r31
  int stripe_bitstream; // r3
  bool v19; // cr58
  int v20; // r3
  int i; // r31

  input = jxr_create_input(buffer: this->tempBuffer);
  v14 = jxr_image_size();
  jxr_set_temp_memory(image: input, buffer: this->tempBuffer, size: this->tempBufferSize, used: v14);
  jxr_init_read_stripe_bitstream(image: input, data: inBuf, size: inputBytes);
  if ( height > 0 )
  {
    v15 = 0;
    v16 = ((unsigned int)(height - 1) >> 4) + 1;
    do
    {
      tempBuffer = (jxr_image *)this->tempBuffer;
      stripe_bitstream = jxr_read_stripe_bitstream(image: tempBuffer);
      if ( stripe_bitstream >= 0 )
      {
        v19 = stripe_bitstream == 0;
        do
        {
          if ( v19 )
            break;
          v20 = jxr_read_stripe_bitstream(image: tempBuffer);
          v19 = v20 == 0;
        }
        while ( v20 >= 0 );
      }
      for ( i = 0; i < width; i += 16 )
        jxr_output_mb_id_rgb(
          image: (jxr_image *)this->tempBuffer,
          mx: (unsigned int)i >> 4,
          buffer: &outBuf[4 * v15 + 4 * i],
          byteStride: width);
      --v16;
      v15 += 16 * width;
    }
    while ( v16 != 0 );
  }
  return 1;
}


// ========================================================================
// ?DecompressImageYCoCg@idBareJXR@@QAA_NPBEPAEHHHH@Z
// EA  : 0x82903A98
// RVA : 0x00903A98
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

int __fastcall idBareJXR::DecompressImageYCoCg(
        idBareJXR *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height,
        unsigned int inputBytes,
        int mipLevel)
{
  jxr_image *input; // r25
  unsigned int v14; // r3
  int v15; // r29
  unsigned int v16; // r26
  jxr_image *tempBuffer; // r31
  int stripe_bitstream; // r3
  bool v19; // cr58
  int v20; // r3
  int i; // r31

  input = jxr_create_input(buffer: this->tempBuffer);
  v14 = jxr_image_size();
  jxr_set_temp_memory(image: input, buffer: this->tempBuffer, size: this->tempBufferSize, used: v14);
  jxr_init_read_stripe_bitstream(image: input, data: inBuf, size: inputBytes);
  if ( height > 0 )
  {
    v15 = 0;
    v16 = ((unsigned int)(height - 1) >> 4) + 1;
    do
    {
      tempBuffer = (jxr_image *)this->tempBuffer;
      stripe_bitstream = jxr_read_stripe_bitstream(image: tempBuffer);
      if ( stripe_bitstream >= 0 )
      {
        v19 = stripe_bitstream == 0;
        do
        {
          if ( v19 )
            break;
          v20 = jxr_read_stripe_bitstream(image: tempBuffer);
          v19 = v20 == 0;
        }
        while ( v20 >= 0 );
      }
      for ( i = 0; i < width; i += 16 )
        jxr_output_mb_id_cocg_y(
          image: (jxr_image *)this->tempBuffer,
          mx: (unsigned int)i >> 4,
          buffer: &outBuf[4 * v15 + 4 * i],
          byteStride: width);
      --v16;
      v15 += 16 * width;
    }
    while ( v16 != 0 );
  }
  return 1;
}


// ========================================================================
// ?DecompressImageNormalMap@idBareJXR@@QAA_NPBEPAEHHHH@Z
// EA  : 0x82903B88
// RVA : 0x00903B88
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\barejxr.cpp
// ========================================================================

int __fastcall idBareJXR::DecompressImageNormalMap(
        idBareJXR *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height,
        unsigned int inputBytes,
        int mipLevel)
{
  jxr_image *input; // r25
  unsigned int v14; // r3
  int v15; // r29
  unsigned int v16; // r26
  jxr_image *tempBuffer; // r31
  int stripe_bitstream; // r3
  bool v19; // cr58
  int v20; // r3
  int i; // r31

  input = jxr_create_input(buffer: this->tempBuffer);
  v14 = jxr_image_size();
  jxr_set_temp_memory(image: input, buffer: this->tempBuffer, size: this->tempBufferSize, used: v14);
  jxr_init_read_stripe_bitstream(image: input, data: inBuf, size: inputBytes);
  if ( height > 0 )
  {
    v15 = 0;
    v16 = ((unsigned int)(height - 1) >> 4) + 1;
    do
    {
      tempBuffer = (jxr_image *)this->tempBuffer;
      stripe_bitstream = jxr_read_stripe_bitstream(image: tempBuffer);
      if ( stripe_bitstream >= 0 )
      {
        v19 = stripe_bitstream == 0;
        do
        {
          if ( v19 )
            break;
          v20 = jxr_read_stripe_bitstream(image: tempBuffer);
          v19 = v20 == 0;
        }
        while ( v20 >= 0 );
      }
      for ( i = 0; i < width; i += 16 )
        jxr_output_mb_id_normal_y_x(
          image: (jxr_image *)this->tempBuffer,
          mx: (unsigned int)i >> 4,
          buffer: &outBuf[4 * v15 + 4 * i],
          byteStride: width);
      --v16;
      v15 += 16 * width;
    }
    while ( v16 != 0 );
  }
  return 1;
}

