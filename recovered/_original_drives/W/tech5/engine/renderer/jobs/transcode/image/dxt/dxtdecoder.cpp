
// ========================================================================
// ?DecodeAlphaValues@idDxtDecoder@@AAAXPAEH@Z
// EA  : 0x829225D0
// RVA : 0x009225D0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtdecoder.cpp
// ========================================================================

void __fastcall idDxtDecoder::DecodeAlphaValues(idDxtDecoder *this, unsigned __int8 *colorBlock, const int offset)
{
  const unsigned __int8 *inData; // r10
  unsigned __int8 v4; // r9
  unsigned __int8 v5; // r7
  int v6; // r7
  unsigned int v7; // r9
  unsigned __int8 v8; // r11
  unsigned __int8 *v9; // r4
  unsigned __int8 v10; // r6
  int v11; // r5
  int v12; // r31
  int v13; // r28
  const unsigned __int8 *v14; // r9
  unsigned __int8 v15; // r6
  const unsigned __int8 *v16; // r11
  int v17; // r9
  unsigned int v18; // r7
  unsigned __int8 v19; // r6
  unsigned __int8 v20; // r8
  int v21; // r9
  int v22; // r5
  unsigned __int8 v23; // r3
  char back_chain; // [sp+0h] [-50h] BYREF

  inData = this->inData;
  this->inData = inData + 1;
  this->inData = inData + 2;
  v4 = inData[2];
  this->inData = inData + 3;
  v5 = inData[3];
  this->inData = inData + 4;
  v6 = (unsigned __int16)((inData[4] << 8) | v5);
  this->inData = inData + 5;
  v7 = (v6 << 8) | v4;
  v8 = *(&back_chain + ((v7 >> 6) & 7));
  v9 = &colorBlock[offset];
  *v9 = *(&back_chain + (v7 & 7));
  v10 = *(&back_chain + ((v7 >> 3) & 7));
  v11 = (v7 >> 12) & 7;
  v12 = (v7 >> 18) & 7;
  LOBYTE(inData) = *(&back_chain + ((v7 >> 9) & 7));
  v13 = (v7 >> 21) & 7;
  LOBYTE(v7) = *(&back_chain + ((v7 >> 15) & 7));
  LOBYTE(v6) = *(&back_chain + v11);
  v9[8] = v8;
  v9[4] = v10;
  LOBYTE(v12) = *(&back_chain + v12);
  LOBYTE(v13) = *(&back_chain + v13);
  v9[12] = (unsigned __int8)inData;
  v9[16] = v6;
  v9[20] = v7;
  v9[24] = v12;
  v9[28] = v13;
  v14 = this->inData;
  LOBYTE(v6) = *v14;
  this->inData = v14 + 1;
  v15 = v14[1];
  v16 = v14 + 3;
  this->inData = v14 + 2;
  v17 = (unsigned __int16)((v14[2] << 8) | v15);
  this->inData = v16;
  v18 = (v17 << 8) | (unsigned __int8)v6;
  v19 = *(&back_chain + ((v18 >> 3) & 7));
  LOBYTE(inData) = *(&back_chain + ((v18 >> 6) & 7));
  v9[32] = *(&back_chain + (v18 & 7));
  v9[36] = v19;
  v20 = *(&back_chain + ((v18 >> 9) & 7));
  v21 = (v18 >> 12) & 7;
  v9[40] = (unsigned __int8)inData;
  v22 = (v18 >> 15) & 7;
  v18 >>= 18;
  v9[44] = v20;
  LOBYTE(v22) = *(&back_chain + v22);
  v9[48] = *(&back_chain + v21);
  v23 = *(&back_chain + (v18 & 7));
  LOBYTE(v16) = *(&back_chain + ((v18 >> 3) & 7));
  v9[52] = v22;
  v9[56] = v23;
  v9[60] = (unsigned __int8)v16;
}


// ========================================================================
// ?DecodeColorValues@idDxtDecoder@@AAAXPAE_N1@Z
// EA  : 0x829228A8
// RVA : 0x009228A8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtdecoder.cpp
// ========================================================================

void __fastcall idDxtDecoder::DecodeColorValues(
        idDxtDecoder *this,
        unsigned __int8 *colorBlock,
        bool noBlack,
        bool writeAlpha)
{
  const unsigned __int8 *inData; // r11
  bool v5; // cr58
  const unsigned __int8 *v6; // r20
  int v7; // r7
  __int16 v8; // r5
  __int16 v9; // r10
  __int16 v10; // r8
  unsigned __int16 v11; // r8
  unsigned int v12; // r11
  int v13; // r5
  const unsigned __int8 *v14; // r10
  BOOL v15; // r5
  unsigned __int8 *v16; // r11
  int v17; // ctr
  const unsigned __int8 *v18; // r6
  int v19; // r7
  int v20; // r10
  int v21; // r9
  unsigned int v22; // r9
  int v23; // r10
  unsigned __int8 v24; // r7
  unsigned __int8 v25; // r6
  _BYTE back_chain[4]; // [sp+0h] [-80h] BYREF
  char v27; // [sp+8h] [-78h]
  char v28; // [sp+9h] [-77h]
  char v29; // [sp+Ah] [-76h]
  char v30; // [sp+Bh] [-75h]
  char v31; // [sp+Ch] [-74h]
  char v32; // [sp+Dh] [-73h]
  char v33; // [sp+Eh] [-72h]
  char v34; // [sp+Fh] [-71h]

  inData = this->inData;
  v5 = !noBlack;
  v6 = inData + 4;
  v7 = inData[1];
  v8 = *inData;
  this->inData = inData + 2;
  v9 = __ROL4__(v7, 8);
  v10 = inData[2];
  LOWORD(inData) = __ROL4__(inData[3], 8);
  this->inData = v6;
  v11 = (unsigned __int16)inData | v10;
  v12 = (unsigned __int16)(v9 | v8);
  v13 = (unsigned __int8)((8 * (v9 | v8)) | ((unsigned __int16)v12 >> 2) & 7);
  if ( v5 && v12 <= v11 )
  {
    v30 = -1;
    v27 = (((v11 >> 13) | HIBYTE(v11) & 0xF8) + (((unsigned __int16)v12 >> 13) | BYTE2(v12) & 0xF8)) >> 1;
    v28 = (((v11 >> 9) & 3 | (v11 >> 3) & 0xFC)
         + (((unsigned __int16)v12 >> 9) & 3 | ((unsigned __int16)v12 >> 3) & 0xFC)) >> 1;
    v31 = 0;
    v32 = 0;
    v29 = ((unsigned __int8)((8 * v11) | (v11 >> 2) & 7) + (unsigned __int8)v13) >> 1;
    v33 = 0;
    v34 = 0;
  }
  else
  {
    v30 = -1;
    v34 = -1;
    v28 = (((2 * (((unsigned __int16)v12 >> 9) & 3 | ((unsigned __int16)v12 >> 3) & 0xFC)) & 0x1FE)
         + ((v11 >> 9) & 3 | (v11 >> 3) & 0xFC))
        / 3;
    v27 = (((2 * (((unsigned __int16)v12 >> 13) | BYTE2(v12) & 0xF8)) & 0x1FE) + ((v11 >> 13) | HIBYTE(v11) & 0xF8)) / 3;
    v29 = (((2 * v13) & 0x1FE) + (unsigned __int8)((8 * v11) | (v11 >> 2) & 7)) / 3;
    v31 = (((2 * ((v11 >> 13) | HIBYTE(v11) & 0xF8)) & 0x1FE) + (((unsigned __int16)v12 >> 13) | BYTE2(v12) & 0xF8)) / 3;
    v32 = (((2 * ((v11 >> 9) & 3 | (v11 >> 3) & 0xFC)) & 0x1FE)
         + (((unsigned __int16)v12 >> 9) & 3 | ((unsigned __int16)v12 >> 3) & 0xFC))
        / 3;
    v33 = (((2 * (unsigned __int8)((8 * v11) | (v11 >> 2) & 7)) & 0x1FE) + (unsigned __int8)v13) / 3;
  }
  v14 = this->inData;
  v15 = writeAlpha;
  v16 = colorBlock + 2;
  v17 = 16;
  v18 = v14 + 4;
  v19 = v14[1];
  v20 = *v14;
  v21 = ((__ROL4__(v6[3], 8) | v6[2]) << 8) | v19;
  this->inData = v18;
  v22 = (v21 << 8) | v20;
  do
  {
    v23 = (4 * v22) & 0xC;
    v24 = back_chain[v23 + 1];
    v25 = back_chain[v23 + 2];
    *(v16 - 2) = back_chain[v23];
    *(v16 - 1) = v24;
    *v16 = v25;
    if ( v15 )
      v16[1] = back_chain[v23 + 3];
    v22 >>= 2;
    v16 += 4;
    --v17;
  }
  while ( v17 != 0 );
}


// ========================================================================
// ?DecompressImageDXT1@idDxtDecoder@@QAAXPBEPAEHH@Z
// EA  : 0x82922B00
// RVA : 0x00922B00
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtdecoder.cpp
// ========================================================================

void __fastcall idDxtDecoder::DecompressImageDXT1(
        idDxtDecoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height)
{
  int i; // r27
  int j; // r30
  unsigned __int8 *v11; // r29
  unsigned __int8 *v12; // r29
  unsigned __int8 *v13; // r29
  _QWORD v14[16]; // [sp+50h] [-80h] BYREF

  this->width = width;
  this->height = height;
  this->inData = inBuf;
  for ( i = 0; i < height; i += 4 )
  {
    for ( j = 0; j < width; j += 4 )
    {
      idDxtDecoder::DecodeColorValues(this, colorBlock: (unsigned __int8 *)v14, noBlack: false, writeAlpha: true);
      v11 = &outBuf[4 * this->width * i + 4 * j];
      *(_OWORD *)v11 = *(_OWORD *)v14;
      v12 = &v11[4 * this->width];
      *(_OWORD *)v12 = *(_OWORD *)&v14[2];
      v13 = &v12[4 * this->width];
      *(_OWORD *)v13 = *(_OWORD *)&v14[4];
      *(_OWORD *)&v13[4 * this->width] = *(_OWORD *)&v14[6];
    }
  }
}


// ========================================================================
// ?DecompressImageDXT5@idDxtDecoder@@QAAXPBEPAEHH@Z
// EA  : 0x82922BE8
// RVA : 0x00922BE8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtdecoder.cpp
// ========================================================================

void __fastcall idDxtDecoder::DecompressImageDXT5(
        idDxtDecoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height)
{
  int i; // r27
  int j; // r30
  unsigned __int8 *v11; // r29
  unsigned __int8 *v12; // r29
  unsigned __int8 *v13; // r29
  _QWORD v14[16]; // [sp+50h] [-80h] BYREF

  this->width = width;
  this->height = height;
  this->inData = inBuf;
  for ( i = 0; i < height; i += 4 )
  {
    for ( j = 0; j < width; j += 4 )
    {
      idDxtDecoder::DecodeAlphaValues(this, colorBlock: (unsigned __int8 *)v14, offset: 3);
      idDxtDecoder::DecodeColorValues(this, colorBlock: (unsigned __int8 *)v14, noBlack: true, writeAlpha: false);
      v11 = &outBuf[4 * this->width * i + 4 * j];
      *(_OWORD *)v11 = *(_OWORD *)v14;
      v12 = &v11[4 * this->width];
      *(_OWORD *)v12 = *(_OWORD *)&v14[2];
      v13 = &v12[4 * this->width];
      *(_OWORD *)v13 = *(_OWORD *)&v14[4];
      *(_OWORD *)&v13[4 * this->width] = *(_OWORD *)&v14[6];
    }
  }
}


// ========================================================================
// ?DecompressImageDXT5_nVidia7x@idDxtDecoder@@QAAXPBEPAEHH@Z
// EA  : 0x82922CE0
// RVA : 0x00922CE0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtdecoder.cpp
// ========================================================================

void __fastcall idDxtDecoder::DecompressImageDXT5_nVidia7x(
        idDxtDecoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height)
{
  int i; // r27
  int j; // r30
  unsigned __int8 *v11; // r29
  unsigned __int8 *v12; // r29
  unsigned __int8 *v13; // r29
  _QWORD v14[16]; // [sp+50h] [-80h] BYREF

  this->width = width;
  this->height = height;
  this->inData = inBuf;
  for ( i = 0; i < height; i += 4 )
  {
    for ( j = 0; j < width; j += 4 )
    {
      idDxtDecoder::DecodeAlphaValues(this, colorBlock: (unsigned __int8 *)v14, offset: 3);
      idDxtDecoder::DecodeColorValues(this, colorBlock: (unsigned __int8 *)v14, noBlack: false, writeAlpha: false);
      v11 = &outBuf[4 * this->width * i + 4 * j];
      *(_OWORD *)v11 = *(_OWORD *)v14;
      v12 = &v11[4 * this->width];
      *(_OWORD *)v12 = *(_OWORD *)&v14[2];
      v13 = &v12[4 * this->width];
      *(_OWORD *)v13 = *(_OWORD *)&v14[4];
      *(_OWORD *)&v13[4 * this->width] = *(_OWORD *)&v14[6];
    }
  }
}


// ========================================================================
// ?DecompressYCoCgDXT5@idDxtDecoder@@QAAXPBEPAEHH@Z
// EA  : 0x82922DD8
// RVA : 0x00922DD8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtdecoder.cpp
// ========================================================================

void __fastcall idDxtDecoder::DecompressYCoCgDXT5(
        idDxtDecoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height)
{
  unsigned __int8 *v8; // r11
  int v9; // ctr
  int v10; // r6
  signed int v11; // r10
  int v12; // r4

  idDxtDecoder::DecompressImageDXT5_nVidia7x(this, inBuf, outBuf, width, height);
  if ( width * height > 0 )
  {
    v8 = outBuf - 2;
    v9 = width * height;
    do
    {
      v10 = v8[2] - 128;
      v11 = (v8[4] >> 3) + 1;
      v12 = v8[3] - 128;
      __twllei(v11, 0);
      v8[2] = v10 / v11 + 0x80;
      __twllei(v11, 0);
      v8[3] = v12 / v11 + 0x80;
      __twlgei(v11 & ~(__ROL4__(v10, 1) - 1), 0xFFFFFFFF);
      v8 += 4;
      *v8 = 0;
      __twlgei(v11 & ~(__ROL4__(v12, 1) - 1), 0xFFFFFFFF);
      --v9;
    }
    while ( v9 != 0 );
  }
}

