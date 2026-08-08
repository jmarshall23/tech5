
// ========================================================================
// ?WriteTinyColorDXT1@idDxtEncoder@@AAAXPBEHH@Z
// EA  : 0x82922E80
// RVA : 0x00922E80
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder.cpp
// ========================================================================

void __fastcall idDxtEncoder::WriteTinyColorDXT1(
        idDxtEncoder *this,
        const unsigned __int8 *inBuf,
        int width,
        int height)
{
  signed int v4; // r11
  int v5; // r9
  int v6; // ctr
  __int16 v7; // r8
  __int16 v8; // r7
  unsigned int v9; // r6
  unsigned __int8 *v10; // r10
  unsigned __int8 *v11; // r10

  v4 = (width + 3) / 4 * ((height + 3) / 4);
  __twllei(v4, 0);
  v5 = 4 * (width * height / v4);
  __twlgei(v4 & ~(__ROL4__(width * height, 1) - 1), 0xFFFFFFFF);
  if ( v4 > 0 )
  {
    v6 = (width + 3) / 4 * ((height + 3) / 4);
    do
    {
      v7 = inBuf[1];
      v8 = (32 * *inBuf) & 0x3F00;
      v9 = inBuf[2];
      inBuf += v5;
      LOWORD(v9) = (8 * (v8 | v7)) & 0xFFE0 | (v9 >> 3);
      *this->outData = v9;
      this->outData[1] = BYTE2(v9);
      v10 = this->outData + 2;
      this->outData = v10;
      *v10 = 0;
      this->outData[1] = 0;
      v11 = this->outData + 2;
      this->outData = v11;
      *v11 = 0;
      this->outData[1] = 0;
      this->outData[2] = 0;
      this->outData[3] = 0;
      this->outData += 4;
      --v6;
    }
    while ( v6 != 0 );
  }
}


// ========================================================================
// ?WriteTinyColorDXT5@idDxtEncoder@@AAAXPBEHH@Z
// EA  : 0x82922F58
// RVA : 0x00922F58
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder.cpp
// ========================================================================

void __fastcall idDxtEncoder::WriteTinyColorDXT5(
        idDxtEncoder *this,
        const unsigned __int8 *inBuf,
        int width,
        int height)
{
  signed int v4; // r11
  int v5; // r9
  int v6; // ctr
  unsigned __int8 *v7; // r10
  unsigned __int8 *v8; // r10
  unsigned __int8 *v9; // r10
  unsigned __int8 *v10; // r10
  unsigned __int8 *v11; // r10
  unsigned __int8 *v12; // r10
  unsigned __int8 *v13; // r10
  unsigned __int8 *v14; // r10
  int v15; // r6
  __int16 v16; // r5
  unsigned __int8 *v17; // r10
  unsigned __int8 *v18; // r10

  v4 = (width + 3) / 4 * ((height + 3) / 4);
  __twllei(v4, 0);
  v5 = 4 * (width * height / v4);
  __twlgei(v4 & ~(__ROL4__(width * height, 1) - 1), 0xFFFFFFFF);
  if ( v4 > 0 )
  {
    v6 = (width + 3) / 4 * ((height + 3) / 4);
    do
    {
      *this->outData = inBuf[3];
      v7 = this->outData + 1;
      this->outData = v7;
      *v7 = 0;
      v8 = this->outData + 1;
      this->outData = v8;
      *v8 = 0;
      v9 = this->outData + 1;
      this->outData = v9;
      *v9 = 0;
      v10 = this->outData + 1;
      this->outData = v10;
      *v10 = 0;
      v11 = this->outData + 1;
      this->outData = v11;
      *v11 = 0;
      v12 = this->outData + 1;
      this->outData = v12;
      *v12 = 0;
      v13 = this->outData + 1;
      this->outData = v13;
      *v13 = 0;
      v14 = this->outData + 1;
      this->outData = v14;
      v15 = inBuf[2] >> 3;
      v16 = (8 * ((32 * *inBuf) & 0x3F00 | inBuf[1])) & 0xFFE0;
      *v14 = (8 * inBuf[1]) & 0xE0 | v15;
      inBuf += v5;
      this->outData[1] = (unsigned __int16)(v16 | v15) >> 8;
      v17 = this->outData + 2;
      this->outData = v17;
      *v17 = 0;
      this->outData[1] = 0;
      v18 = this->outData + 2;
      this->outData = v18;
      *v18 = 0;
      this->outData[1] = 0;
      this->outData[2] = 0;
      this->outData[3] = 0;
      this->outData += 4;
      --v6;
    }
    while ( v6 != 0 );
  }
}


// ========================================================================
// ?GetSquareAlphaError@idDxtEncoder@@ABAHPBEHEEH@Z
// EA  : 0x829230B0
// RVA : 0x009230B0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder.cpp
// ========================================================================

int __fastcall idDxtEncoder::GetSquareAlphaError(
        idDxtEncoder *this,
        const unsigned __int8 *colorBlock,
        const int alphaOffset,
        const unsigned __int8 minAlpha,
        const unsigned __int8 maxAlpha,
        int lastError)
{
  int v6; // r10
  int v7; // r11
  int v8; // r9
  unsigned __int8 v9; // r7
  unsigned __int8 v10; // r6
  unsigned __int8 v11; // r31
  unsigned __int8 v12; // r30
  unsigned __int8 v13; // r29
  const unsigned __int8 *v14; // r5
  int result; // r3
  int v16; // r28
  int v17; // r27
  int v18; // r26
  int v19; // r7
  unsigned int v20; // r9
  unsigned int v21; // r7

  v6 = minAlpha;
  v7 = maxAlpha;
  if ( maxAlpha <= (unsigned int)minAlpha )
  {
    v8 = (4 * maxAlpha + minAlpha) / 5;
    v9 = (3 * maxAlpha + 2 * minAlpha) / 5;
    v10 = (2 * v7 + 3 * minAlpha) / 5;
    v11 = (4 * v6 + v7) / 5;
    v12 = 0;
    v13 = -1;
  }
  else
  {
    v8 = (6 * maxAlpha + minAlpha) / 7;
    v9 = (5 * maxAlpha + 2 * minAlpha) / 7;
    v10 = (4 * v7 + 3 * minAlpha) / 7;
    v11 = (3 * v7 + 4 * v6) / 7;
    v12 = (2 * v7 + 5 * v6) / 7;
    v13 = (6 * v6 + v7) / 7;
  }
  v14 = &colorBlock[alphaOffset];
  result = 0;
  v16 = 0;
  v17 = (unsigned __int8)v8;
  v18 = v9;
  do
  {
    v19 = *v14;
    v20 = -1;
    if ( (v19 - v7) * (v19 - v7) != -1 )
      v20 = (v19 - v7) * (v19 - v7);
    if ( (v19 - v6) * (v19 - v6) < v20 )
      v20 = (v19 - v6) * (v19 - v6);
    if ( (v19 - v17) * (v19 - v17) < v20 )
      v20 = (v19 - v17) * (v19 - v17);
    if ( (v19 - v18) * (v19 - v18) < v20 )
      v20 = (v19 - v18) * (v19 - v18);
    if ( (v19 - v10) * (v19 - (unsigned int)v10) < v20 )
      v20 = (v19 - v10) * (v19 - v10);
    if ( (v19 - v11) * (v19 - (unsigned int)v11) < v20 )
      v20 = (v19 - v11) * (v19 - v11);
    if ( (v19 - v12) * (v19 - (unsigned int)v12) < v20 )
      v20 = (v19 - v12) * (v19 - v12);
    v21 = (v19 - v13) * (v19 - v13);
    if ( v21 < v20 )
      v20 = v21;
    result += v20;
    if ( result >= lastError )
      break;
    ++v16;
    v14 += 4;
  }
  while ( v16 < 16 );
  return result;
}


// ========================================================================
// ?GetMinMaxAlphaHQ@idDxtEncoder@@ABAHPBEHPAE1@Z
// EA  : 0x829232A8
// RVA : 0x009232A8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder.cpp
// ========================================================================

int __fastcall idDxtEncoder::GetMinMaxAlphaHQ(
        idDxtEncoder *this,
        const unsigned __int8 *colorBlock,
        int alphaOffset,
        unsigned __int8 *minColor,
        unsigned __int8 *maxColor)
{
  int v8; // ctr
  unsigned __int8 v11; // r11
  int v12; // r8
  unsigned __int8 v13; // r6
  const unsigned __int8 *v14; // r7
  unsigned int v15; // r10
  unsigned int v16; // r10
  unsigned int v17; // r10
  unsigned int v18; // r10
  unsigned __int8 v19; // r10
  unsigned __int8 v20; // r11
  int v21; // r27
  int i; // r24
  int j; // r28
  int v24; // r8
  int SquareAlphaError; // r3
  int v26; // r3

  v8 = 4;
  v11 = -1;
  v12 = 0x7FFFFFFF;
  v13 = 0;
  v14 = &colorBlock[alphaOffset + 8];
  do
  {
    v15 = *(v14 - 8);
    if ( v15 < v11 )
      v11 = *(v14 - 8);
    if ( v15 > v13 )
      v13 = *(v14 - 8);
    v16 = *(v14 - 4);
    if ( v16 < v11 )
      v11 = *(v14 - 4);
    if ( v16 > v13 )
      v13 = *(v14 - 4);
    v17 = *v14;
    if ( v17 < v11 )
      v11 = *v14;
    if ( v17 > v13 )
      v13 = *v14;
    v18 = v14[4];
    if ( v18 < v11 )
      v11 = v14[4];
    if ( v18 > v13 )
      v13 = v14[4];
    v14 += 16;
    --v8;
  }
  while ( v8 != 0 );
  v19 = 0;
  if ( v11 > 0x20u )
    v19 = v11 - 32;
  if ( v13 < 0xDFu )
    v20 = v13 + 32;
  else
    v20 = -1;
  v21 = v19;
  for ( i = v20; v21 <= i; ++v21 )
  {
    for ( j = i; j >= v21; --j )
    {
      SquareAlphaError = idDxtEncoder::GetSquareAlphaError(
                           this,
                           colorBlock,
                           alphaOffset,
                           minAlpha: v21,
                           maxAlpha: j,
                           lastError: v12);
      if ( SquareAlphaError < v24 )
      {
        minColor[alphaOffset] = v21;
        v24 = SquareAlphaError;
        maxColor[alphaOffset] = j;
      }
      v26 = idDxtEncoder::GetSquareAlphaError(this, colorBlock, alphaOffset, minAlpha: j, maxAlpha: v21, lastError: v24);
      if ( v26 < v12 )
      {
        minColor[alphaOffset] = v21;
        v12 = v26;
        maxColor[alphaOffset] = j;
      }
    }
  }
  return v12;
}


// ========================================================================
// ?GetSquareColorsError@idDxtEncoder@@ABAHPBEGGH@Z
// EA  : 0x82923468
// RVA : 0x00923468
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder.cpp
// ========================================================================

int __fastcall idDxtEncoder::GetSquareColorsError(
        idDxtEncoder *this,
        const unsigned __int8 *colorBlock,
        const unsigned __int16 color0,
        const unsigned __int16 color1,
        int lastError)
{
  int v5; // r9
  int v6; // r8
  int v7; // r6
  int v8; // r5
  int v9; // r10
  int v10; // r3
  bool v11; // cr57
  int v12; // r31
  int v13; // r28
  int v14; // r30
  int v15; // r27
  int v16; // r29
  int v17; // r26
  int v18; // r11
  unsigned __int8 v19; // r10
  unsigned __int8 v20; // r9
  unsigned __int8 v21; // r8
  unsigned __int8 v22; // r6
  unsigned __int8 v23; // r5
  int result; // r3
  int v25; // r18
  int v26; // r24
  int v27; // r23
  int v28; // r22
  int v29; // r21
  int v30; // r19
  const unsigned __int8 *v31; // r4
  int v32; // r10
  unsigned int v33; // r11
  int v34; // r9
  int v35; // r8
  int v36; // r17
  int v37; // r5
  int v38; // r17
  int v39; // r5
  int v40; // r17
  int v41; // r5
  unsigned int v42; // r10

  v5 = (color0 >> 9) & 3 | (color0 >> 3) & 0xFC;
  v6 = (unsigned __int8)((8 * color0) | (color0 >> 2) & 7);
  v9 = (color0 >> 13) | HIBYTE(color0) & 0xF8;
  v10 = (unsigned __int8)((8 * color1) | (color1 >> 2) & 7);
  v11 = color0 > (unsigned int)color1;
  v8 = (color1 >> 9) & 3 | (color1 >> 3) & 0xFC;
  v7 = (color1 >> 13) | HIBYTE(color1) & 0xF8;
  v12 = (unsigned __int8)v9;
  v13 = (unsigned __int8)v7;
  v14 = (unsigned __int8)v5;
  v15 = (unsigned __int8)v8;
  v16 = (unsigned __int8)v6;
  v17 = (unsigned __int8)v10;
  if ( v11 )
  {
    v18 = (((2 * v9) & 0x1FE) + (unsigned __int8)v7) / 3;
    v19 = (((2 * v5) & 0x1FE) + (unsigned __int8)v8) / 3;
    v20 = (((2 * v6) & 0x1FE) + (unsigned __int8)v10) / 3;
    v21 = (((2 * v7) & 0x1FE) + v12) / 3;
    v22 = (((2 * v8) & 0x1FE) + v14) / 3;
    v23 = (((2 * v10) & 0x1FE) + v16) / 3;
  }
  else
  {
    LOBYTE(v18) = ((unsigned __int8)v7 + (unsigned __int8)v9) / 2;
    v21 = 0;
    v19 = ((unsigned __int8)v8 + (unsigned __int8)v5) / 2;
    v20 = ((unsigned __int8)v10 + v16) / 2;
    v22 = 0;
    v23 = 0;
  }
  result = 0;
  v25 = 0;
  v26 = v20;
  v27 = v19;
  v28 = (unsigned __int8)v18;
  v29 = v23;
  v30 = v21;
  v31 = colorBlock + 1;
  do
  {
    v32 = v31[1];
    v33 = -1;
    v34 = *(v31 - 1);
    v35 = *v31;
    v36 = v35 - v14;
    v37 = (v34 - v12) * (v34 - v12) + (v32 - v16) * (v32 - v16);
    if ( v37 + v36 * v36 != -1 )
      v33 = v37 + v36 * v36;
    v38 = v34 - v13;
    v39 = (v32 - v17) * (v32 - v17) + (v35 - v15) * (v35 - v15);
    if ( v39 + v38 * v38 < v33 )
      v33 = v39 + v38 * v38;
    v40 = v32 - v26;
    v41 = (v35 - v27) * (v35 - v27) + (v34 - v28) * (v34 - v28);
    if ( v41 + v40 * v40 < v33 )
      v33 = v41 + v40 * v40;
    v42 = (v35 - v22) * (v35 - v22) + (v34 - v30) * (v34 - v30) + (v32 - v29) * (v32 - v29);
    if ( v42 < v33 )
      v33 = v42;
    result += v33;
    if ( result > lastError )
      break;
    ++v25;
    v31 += 4;
  }
  while ( v25 < 16 );
  return result;
}


// ========================================================================
// ?GetSquareNormalYError@idDxtEncoder@@ABAHPBEGGHH@Z
// EA  : 0x829236A0
// RVA : 0x009236A0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idDxtEncoder::GetSquareNormalYError(
        idDxtEncoder *this,
        __int64 color0,
        const unsigned __int16 color1,
        int lastError,
        __int64 scale)
{
  int v5; // r2 OVERLAPPED
  int v6; // r6
  bool v7; // cr57
  __int64 v8; // r11
  int v9; // r3
  int v10; // r3
  int v11; // r3
  unsigned __int8 v12; // r3
  int v13; // r6
  int v14; // r3
  int v15; // r6
  unsigned __int8 *v16; // r9
  double v17; // fp12
  double v18; // fp11
  double v19; // fp10
  double v20; // fp13
  double v21; // fp9
  unsigned int v22; // r11
  double v23; // fp0
  double v24; // fp4
  double v25; // fp3
  double v26; // fp7
  double v27; // fp6
  double v28; // fp7
  double v29; // fp6
  double v30; // fp8
  int v31; // r3
  int v32; // r3
  int result; // r3

  v7 = (unsigned __int16)color0 > (unsigned int)color1;
  v6 = (color1 >> 9) & 3 | (color1 >> 3) & 0xFC;
  HIDWORD(v8) = ((unsigned __int16)color0 >> 9) & 3 | ((unsigned __int16)color0 >> 3) & 0xFC;
  LODWORD(v8) = (unsigned __int8)v6;
  if ( v7 )
  {
    v9 = (((2 * (((unsigned __int16)color0 >> 9) & 3 | ((unsigned __int16)color0 >> 3) & 0xFC)) & 0x1FE)
        + (unsigned __int8)v6)
       / 3;
    LOBYTE(scale) = (((2 * v6) & 0x1FE) + HIDWORD(v8)) / 3;
  }
  else
  {
    LOBYTE(scale) = 0;
    v10 = ((unsigned __int8)v6 + HIDWORD(v8)) / 2;
  }
  LODWORD(color0) = (unsigned __int8)scale;
  v13 = v12;
  v11 = HIDWORD(v8);
  LODWORD(scale) = HIDWORD(scale);
  v17 = (float)*(__int64 *)(&v5 - 1);
  v14 = 0;
  v18 = (float)v8;
  v19 = (float)*(__int64 *)((char *)&color0 - 4);
  v15 = 0;
  v20 = (float)scale;
  v21 = (float)((float)color0 / (float)scale);
  v16 = (unsigned __int8 *)(HIDWORD(color0) + 1);
  do
  {
    HIDWORD(color0) = *v16;
    v22 = -1;
    v24 = (float)((float)((float)*(__int64 *)((char *)&color0 + 4) / (float)v20) - (float)((float)v17 / (float)v20));
    v25 = (float)((float)v24 * (float)v24);
    if ( (int)v25 != -1 )
      v22 = (int)v25;
    v26 = (float)((float)((float)*(__int64 *)((char *)&color0 + 4) / (float)v20) - (float)((float)v18 / (float)v20));
    v27 = (float)((float)v26 * (float)v26);
    if ( (int)v27 < v22 )
      v22 = (int)v27;
    v28 = (float)((float)((float)*(__int64 *)((char *)&color0 + 4) / (float)v20) - (float)((float)v19 / (float)v20));
    v29 = (float)((float)v28 * (float)v28);
    if ( (int)v29 < v22 )
      v22 = (int)v29;
    v23 = (float)((float)*(__int64 *)((char *)&color0 + 4) / (float)v20);
    v30 = (float)((float)((float)v23 - (float)v21) * (float)((float)v23 - (float)v21));
    if ( (int)v30 < v22 )
      v22 = (int)v30;
    v32 = v22 + v31;
    if ( v32 > lastError )
      break;
    ++v15;
    v16 += 4;
  }
  while ( v15 < 16 );
  return result;
}


// ========================================================================
// ?FindColorIndices@idDxtEncoder@@ABAHPBEGGAAI@Z
// EA  : 0x82923858
// RVA : 0x00923858
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder.cpp
// ========================================================================

int __fastcall idDxtEncoder::FindColorIndices(
        idDxtEncoder *this,
        const unsigned __int8 *colorBlock,
        const unsigned __int16 color0,
        const unsigned __int16 color1,
        unsigned int *result)
{
  int v5; // r10
  int v6; // r9
  int v7; // r8
  int v8; // r6
  int v9; // r5
  int v10; // r11
  bool v11; // cr57
  int v12; // r31
  int v13; // r27
  int v14; // r30
  int v15; // r26
  int v16; // r29
  int v17; // r25
  unsigned __int8 v18; // r11
  int v19; // r3
  int v20; // r9
  unsigned __int8 v21; // r8
  unsigned __int8 v22; // r6
  unsigned __int8 v23; // r5
  int v24; // r23
  int v25; // r16
  int v26; // r22
  int v27; // ctr
  int v28; // r20
  int v29; // r19
  int v30; // r18
  int v31; // r17
  _DWORD *v32; // r28
  const unsigned __int8 *v33; // r4
  int v34; // r10
  unsigned int v35; // r11
  int v36; // r9
  int v37; // r8
  int v38; // r7
  int v39; // r5
  int v40; // r7
  int v41; // r5
  int v42; // r8
  int v43; // r9
  int v44; // r9
  int v45; // r10
  int v46; // r8
  int v47; // r7
  int v48; // r5
  unsigned int v49; // r11
  int v50; // r7
  int v51; // r5
  int v52; // r6
  int v53; // r9
  int v54; // r3
  int v55; // r9
  int v56; // r10
  int v57; // ctr
  _DWORD *v58; // r11
  int v59; // r6
  int v60; // r4
  int v61; // r30
  int v62; // r4
  int v63; // r8
  _BYTE back_chain[220]; // [sp+0h] [-DCh] BYREF

  v5 = (color0 >> 9) & 3 | (color0 >> 3) & 0xFC;
  v6 = (unsigned __int8)((8 * color0) | (color0 >> 2) & 7);
  v7 = (color1 >> 13) | HIBYTE(color1) & 0xF8;
  v10 = (color0 >> 13) | HIBYTE(color0) & 0xF8;
  v11 = color0 > (unsigned int)color1;
  v12 = v10;
  v9 = (unsigned __int8)((8 * color1) | (color1 >> 2) & 7);
  v13 = v7;
  v8 = (color1 >> 9) & 3 | (color1 >> 3) & 0xFC;
  v14 = (unsigned __int8)v5;
  v15 = (unsigned __int8)v8;
  v16 = (unsigned __int8)v6;
  v17 = (unsigned __int8)v9;
  if ( v11 )
  {
    v18 = (((2 * v10) & 0x1FE) + v7) / 3;
    v19 = (((2 * v5) & 0x1FE) + (unsigned __int8)v8) / 3;
    v20 = (((2 * v6) & 0x1FE) + (unsigned __int8)v9) / 3;
    v21 = (((2 * v7) & 0x1FE) + v12) / 3;
    v23 = (((2 * v9) & 0x1FE) + v16) / 3;
    v22 = (((2 * v8) & 0x1FE) + (unsigned __int8)v5) / 3;
  }
  else
  {
    v18 = (v7 + v10) / 2;
    v19 = ((unsigned __int8)v8 + (unsigned __int8)v5) / 2;
    v21 = 0;
    v20 = ((unsigned __int8)v9 + (unsigned __int8)v6) / 2;
    v22 = 0;
    v23 = 0;
  }
  v24 = 0;
  v25 = 0;
  v26 = (unsigned __int8)v20;
  v27 = 8;
  v28 = v18;
  v29 = v23;
  v30 = v22;
  v31 = v21;
  v32 = back_chain;
  v33 = colorBlock + 5;
  do
  {
    v34 = *(v33 - 4);
    v35 = -1;
    v36 = *(v33 - 5);
    v37 = *(v33 - 3);
    v38 = v37 - v16;
    v39 = (v36 - v12) * (v36 - v12) + (v34 - v14) * (v34 - v14);
    if ( v39 + v38 * v38 != -1 )
    {
      v35 = v39 + v38 * v38;
      *(v32 - 1) = 0;
    }
    if ( (v36 - v13) * (v36 - v13) + (v34 - v15) * (v34 - v15) + (v37 - v17) * (v37 - v17) < v35 )
    {
      v35 = (v36 - v13) * (v36 - v13) + (v34 - v15) * (v34 - v15) + (v37 - v17) * (v37 - v17);
      *(v32 - 1) = 1;
    }
    v40 = v37 - v26;
    v41 = (v36 - v28) * (v36 - v28) + (v34 - (unsigned __int8)v19) * (v34 - (unsigned __int8)v19);
    if ( v41 + v40 * v40 < v35 )
    {
      v35 = v41 + v40 * v40;
      *(v32 - 1) = 2;
    }
    v42 = v37 - v29;
    v43 = (v36 - v31) * (v36 - v31) + (v34 - v30) * (v34 - v30);
    if ( v43 + v42 * v42 < v35 )
    {
      v35 = v43 + v42 * v42;
      *(v32 - 1) = 3;
    }
    v44 = *(v33 - 1);
    v24 += v35;
    v45 = *v33;
    v46 = v33[1];
    v47 = v45 - v14;
    v48 = v46 - v16;
    v49 = -1;
    if ( v47 * v47 + (v44 - v12) * (v44 - v12) + v48 * v48 != -1 )
    {
      v49 = v47 * v47 + (v44 - v12) * (v44 - v12) + v48 * v48;
      *v32 = 0;
    }
    if ( (v45 - v15) * (v45 - v15) + (v44 - v13) * (v44 - v13) + (v46 - v17) * (v46 - v17) < v49 )
    {
      v49 = (v45 - v15) * (v45 - v15) + (v44 - v13) * (v44 - v13) + (v46 - v17) * (v46 - v17);
      *v32 = 1;
    }
    v50 = v46 - v26;
    v51 = (v45 - (unsigned __int8)v19) * (v45 - (unsigned __int8)v19) + (v44 - v28) * (v44 - v28);
    if ( v51 + v50 * v50 < v49 )
    {
      v49 = v51 + v50 * v50;
      *v32 = 2;
    }
    v52 = v46 - v29;
    v53 = (v45 - v30) * (v45 - v30) + (v44 - v31) * (v44 - v31);
    if ( v53 + v52 * v52 < v49 )
    {
      v49 = v53 + v52 * v52;
      *v32 = 3;
    }
    v25 += v49;
    v33 += 8;
    v32 += 2;
    --v27;
  }
  while ( v27 != 0 );
  v54 = v25 + v24;
  v55 = 0;
  v56 = 4;
  v57 = 4;
  *result = 0;
  v58 = &back_chain[-20];
  do
  {
    v59 = v58[6];
    v60 = v58[5];
    v61 = v58[7];
    v58 += 4;
    v62 = (*v58 << (2 * v55)) | (v60 << (v56 - 2)) | (v61 << (v56 + 2));
    v55 += 4;
    v63 = v62 | (v59 << v56);
    v56 += 8;
    *result |= v63;
    --v57;
  }
  while ( v57 != 0 );
  return v54;
}


// ========================================================================
// ?FindAlphaIndices@idDxtEncoder@@ABAHPBEHEEPAE@Z
// EA  : 0x82923BF0
// RVA : 0x00923BF0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder.cpp
// ========================================================================

int __fastcall idDxtEncoder::FindAlphaIndices(
        idDxtEncoder *this,
        const unsigned __int8 *colorBlock,
        const int alphaOffset,
        const unsigned __int8 alpha0,
        const unsigned __int8 alpha1,
        unsigned __int8 *rindexes)
{
  int v6; // r10
  int v7; // r30
  int v8; // r26
  unsigned __int8 v9; // r11
  unsigned __int8 v10; // r9
  unsigned __int8 v11; // r7
  unsigned __int8 v12; // r6
  unsigned __int8 v13; // r3
  unsigned __int8 v14; // r31
  const unsigned __int8 *v15; // r4
  int v16; // r28
  int v17; // r27
  int v18; // r26
  int v19; // ctr
  int v20; // r29
  int v21; // r22
  int *p_back_chain; // r6
  int v23; // r7
  unsigned int v24; // r11
  int v25; // r7
  unsigned int v26; // r11
  char v28; // r26
  char v29; // r29
  char v30; // r5
  unsigned int v31; // r7
  char v32; // r30
  unsigned int v33; // r10
  int v34; // r6
  unsigned __int8 v35; // r31
  int v36; // [sp+0h] [-D0h]
  int back_chain; // [sp+4h] [-CCh] BYREF
  unsigned int v38; // [sp+8h] [-C8h]
  int v39; // [sp+Ch] [-C4h]
  int v40; // [sp+10h] [-C0h]
  unsigned int v41; // [sp+14h] [-BCh]
  int v42; // [sp+18h] [-B8h]
  int v43; // [sp+1Ch] [-B4h]
  int v44; // [sp+20h] [-B0h]
  int v45; // [sp+24h] [-ACh]
  unsigned int v46; // [sp+28h] [-A8h]
  int v47; // [sp+2Ch] [-A4h]
  int v48; // [sp+30h] [-A0h]
  unsigned int v49; // [sp+34h] [-9Ch]
  int v50; // [sp+38h] [-98h]
  int v51; // [sp+3Ch] [-94h]

  v6 = alpha0;
  v7 = alpha1;
  if ( alpha0 <= (unsigned int)alpha1 )
  {
    v11 = (3 * alpha1 + 2 * alpha0) / 5;
    v10 = (2 * v7 + 3 * alpha0) / 5;
    v12 = (4 * v7 + alpha0) / 5;
    v9 = (4 * v6 + v7) / 5;
    v13 = 0;
    v14 = -1;
  }
  else
  {
    v8 = 6 * alpha1;
    v9 = (6 * alpha0 + alpha1) / 7;
    v10 = (2 * alpha1 + 5 * alpha0) / 7;
    v11 = (3 * alpha1 + 4 * alpha0) / 7;
    v12 = (4 * v7 + 3 * alpha0) / 7;
    v13 = (5 * v7 + 2 * v6) / 7;
    v14 = (v8 + v6) / 7;
  }
  v15 = &colorBlock[alphaOffset];
  v16 = 0;
  v17 = 0;
  v18 = v9;
  v19 = 8;
  v20 = v12;
  v21 = v11;
  p_back_chain = &back_chain;
  do
  {
    v23 = *v15;
    v24 = -1;
    if ( (v23 - v6) * (v23 - v6) != -1 )
    {
      v24 = (v23 - v6) * (v23 - v6);
      *(p_back_chain - 1) = 0;
    }
    if ( (v23 - v7) * (v23 - v7) < v24 )
    {
      v24 = (v23 - v7) * (v23 - v7);
      *(p_back_chain - 1) = 1;
    }
    if ( (v23 - v18) * (v23 - v18) < v24 )
    {
      v24 = (v23 - v18) * (v23 - v18);
      *(p_back_chain - 1) = 2;
    }
    if ( (v23 - v10) * (v23 - (unsigned int)v10) < v24 )
    {
      v24 = (v23 - v10) * (v23 - v10);
      *(p_back_chain - 1) = 3;
    }
    if ( (v23 - v21) * (v23 - v21) < v24 )
    {
      v24 = (v23 - v21) * (v23 - v21);
      *(p_back_chain - 1) = 4;
    }
    if ( (v23 - v20) * (v23 - v20) < v24 )
    {
      v24 = (v23 - v20) * (v23 - v20);
      *(p_back_chain - 1) = 5;
    }
    if ( (v23 - v13) * (v23 - (unsigned int)v13) < v24 )
    {
      v24 = (v23 - v13) * (v23 - v13);
      *(p_back_chain - 1) = 6;
    }
    if ( (v23 - v14) * (v23 - (unsigned int)v14) < v24 )
    {
      v24 = (v23 - v14) * (v23 - v14);
      *(p_back_chain - 1) = 7;
    }
    v25 = v15[4];
    v16 += v24;
    v26 = -1;
    if ( (v25 - v6) * (v25 - v6) != -1 )
    {
      v26 = (v25 - v6) * (v25 - v6);
      *p_back_chain = 0;
    }
    if ( (v25 - v7) * (v25 - v7) < v26 )
    {
      v26 = (v25 - v7) * (v25 - v7);
      *p_back_chain = 1;
    }
    if ( (v25 - v18) * (v25 - v18) < v26 )
    {
      v26 = (v25 - v18) * (v25 - v18);
      *p_back_chain = 2;
    }
    if ( (v25 - v10) * (v25 - (unsigned int)v10) < v26 )
    {
      v26 = (v25 - v10) * (v25 - v10);
      *p_back_chain = 3;
    }
    if ( (v25 - v21) * (v25 - v21) < v26 )
    {
      v26 = (v25 - v21) * (v25 - v21);
      *p_back_chain = 4;
    }
    if ( (v25 - v20) * (v25 - v20) < v26 )
    {
      v26 = (v25 - v20) * (v25 - v20);
      *p_back_chain = 5;
    }
    if ( (v25 - v13) * (v25 - (unsigned int)v13) < v26 )
    {
      v26 = (v25 - v13) * (v25 - v13);
      *p_back_chain = 6;
    }
    if ( (v25 - v14) * (v25 - (unsigned int)v14) < v26 )
    {
      v26 = (v25 - v14) * (v25 - v14);
      *p_back_chain = 7;
    }
    v17 += v26;
    v15 += 8;
    p_back_chain += 2;
    --v19;
  }
  while ( v19 != 0 );
  v28 = v44;
  v29 = 8 * ((8 * HIBYTE(v46)) | HIBYTE(v45));
  v30 = 2 * ((8 * ((8 * HIBYTE(v49)) | HIBYTE(v48))) | HIBYTE(v47));
  v31 = v46 >> 2;
  v32 = 4 * ((8 * HIBYTE(v51)) | HIBYTE(v50));
  v33 = v49 >> 1;
  v34 = (4 * ((8 * v43) | v42)) | (v41 >> 1);
  v35 = (8 * ((8 * HIBYTE(v38)) | HIBYTE(back_chain))) | v36;
  rindexes[1] = (2 * ((8 * ((8 * v41) | v40)) | v39)) | (v38 >> 2);
  rindexes[2] = v34;
  *rindexes = v35;
  rindexes[3] = v29 | v28;
  rindexes[4] = v30 | v31;
  rindexes[5] = v32 | v33;
  return v17 + v16;
}


// ========================================================================
// ?GetMinMaxBBox@idDxtEncoder@@ABAXPBEPAE1@Z
// EA  : 0x82923FC0
// RVA : 0x00923FC0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder.cpp
// ========================================================================

void __fastcall idDxtEncoder::GetMinMaxBBox(
        idDxtEncoder *this,
        const unsigned __int8 *colorBlock,
        unsigned __int8 *minColor,
        unsigned __int8 *maxColor)
{
  int v4; // ctr
  const unsigned __int8 *v5; // r10
  unsigned int v6; // r11
  unsigned int v7; // r11
  unsigned int v8; // r11
  unsigned int v9; // r11
  unsigned int v10; // r11
  unsigned int v11; // r11
  unsigned int v12; // r11
  unsigned int v13; // r11

  minColor[3] = -1;
  minColor[2] = -1;
  minColor[1] = -1;
  v4 = 16;
  *minColor = -1;
  v5 = colorBlock + 2;
  maxColor[3] = 0;
  maxColor[2] = 0;
  maxColor[1] = 0;
  *maxColor = 0;
  do
  {
    v6 = *(v5 - 2);
    if ( v6 < *minColor )
      *minColor = v6;
    v7 = *(v5 - 1);
    if ( v7 < minColor[1] )
      minColor[1] = v7;
    v8 = *v5;
    if ( v8 < minColor[2] )
      minColor[2] = v8;
    v9 = v5[1];
    if ( v9 < minColor[3] )
      minColor[3] = v9;
    v10 = *(v5 - 2);
    if ( v10 > *maxColor )
      *maxColor = v10;
    v11 = *(v5 - 1);
    if ( v11 > maxColor[1] )
      maxColor[1] = v11;
    v12 = *v5;
    if ( v12 > maxColor[2] )
      maxColor[2] = v12;
    v13 = v5[1];
    if ( v13 > maxColor[3] )
      maxColor[3] = v13;
    v5 += 4;
    --v4;
  }
  while ( v4 != 0 );
}


// ========================================================================
// ?EmitColorIndices@idDxtEncoder@@AAAXPBE00@Z
// EA  : 0x829240C0
// RVA : 0x009240C0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder.cpp
// ========================================================================

void __fastcall idDxtEncoder::EmitColorIndices(
        idDxtEncoder *this,
        const unsigned __int8 *colorBlock,
        const unsigned __int8 *minColor,
        const unsigned __int8 *maxColor)
{
  const unsigned __int8 *v4; // r9
  int v5; // ctr
  int v6; // r5
  int v7; // r6
  int v8; // r7
  int v9; // r3
  int v10; // r10
  int v11; // r29
  int v12; // r30
  int v13; // r25
  int v14; // r21
  int v15; // r23
  int v16; // r27
  int v17; // r26
  int v18; // r18
  int v19; // r17
  int v20; // r10
  int v21; // r16
  int v22; // r22
  int v23; // r8
  int v24; // r3
  int v25; // r4
  int v26; // r14
  unsigned int v27; // r10
  int v28; // r4
  unsigned int v29; // r8
  unsigned int v30; // r11
  unsigned int v31; // r10
  unsigned int v32; // r7
  int v33; // r8
  int v34; // [sp+0h] [-D0h]
  int v35; // [sp+4h] [-CCh]
  int back_chain; // [sp+8h] [-C8h]
  int v37; // [sp+Ch] [-C4h]
  int v38; // [sp+10h] [-C0h]
  int v39; // [sp+14h] [-BCh]
  int v40; // [sp+18h] [-B8h]
  int v41; // [sp+1Ch] [-B4h]
  int v42; // [sp+28h] [-A8h]
  int v43; // [sp+30h] [-A0h]

  v4 = colorBlock + 62;
  v5 = 16;
  v35 = (maxColor[1] >> 6) | maxColor[1] & 0xFC;
  v34 = (maxColor[2] >> 5) | maxColor[2] & 0xF8;
  back_chain = (*maxColor >> 5) | *maxColor & 0xF8;
  v39 = (*minColor >> 5) | *minColor & 0xF8;
  v38 = (minColor[1] >> 6) | minColor[1] & 0xFC;
  v37 = (minColor[2] >> 5) | minColor[2] & 0xF8;
  v41 = (unsigned __int16)((2 * v35 + v38) / 3);
  v40 = (unsigned __int16)((2 * back_chain + v39) / 3);
  v6 = 0;
  v42 = (unsigned __int16)((2 * v38 + v35) / 3);
  v7 = 15;
  do
  {
    v8 = *v4;
    v9 = *(v4 - 1);
    v10 = *(v4 - 2);
    v11 = back_chain - v10;
    v12 = v38 - v9;
    v13 = (v35 - v9) >> 31;
    v14 = v39 - v10;
    v15 = (back_chain - v10) >> 31;
    v16 = v40 - v10;
    v17 = v41 - v9;
    v18 = (v38 - v9) >> 31;
    v19 = (v39 - v10) >> 31;
    v21 = (v40 - v10) >> 31;
    v20 = (unsigned __int16)((2 * v39 + back_chain) / 3) - v10;
    v22 = (v41 - v9) >> 31;
    v23 = v42 - v9;
    v25 = (v35 - v9) ^ v13;
    v26 = (v42 - v9) >> 31;
    v24 = v20 >> 31;
    v43 = v20 ^ (v20 >> 31);
    v27 = abs32(v34 - v8) + v25 - v13;
    v28 = v43 - v24 + (v23 ^ v26) - v26;
    v29 = v27 + (v11 ^ v15) - v15;
    v30 = v28 + abs32((unsigned __int16)((2 * v37 + v34) / 3) - v8);
    v31 = (v16 ^ v21) - v21 + (v17 ^ v22) - v22 + abs32((unsigned __int16)((2 * v34 + v37) / 3) - v8);
    v32 = abs32(v37 - v8) + (v12 ^ v18) - v18 + (v14 ^ v19) - v19;
    LOBYTE(v24) = ((((v29 ^ v30) & 0x80000000) == 0) + (v30 >= v29)) & 1;
    v33 = ((2
          * (((((v29 ^ v31) & 0x80000000) == 0) + (v31 >= v29))
           & 1
           & ((((v32 ^ v31) & 0x80000000) == 0) + (v31 >= v32))
           & 1
           | ((((v32 ^ v30) & 0x80000000) == 0) + (v30 >= v32)) & 1 & (unsigned __int8)v24))
         | (((~(v31 ^ v30) & 0x80000000) != 0) + (v30 >= v31)) & 1 & (unsigned __int8)v24) << (2 * v7--);
    v6 |= v33;
    v4 -= 4;
    --v5;
  }
  while ( v5 != 0 );
  *this->outData = v6;
  this->outData[1] = BYTE2(v6);
  this->outData[2] = BYTE1(v6);
  this->outData[3] = HIBYTE(v6);
  this->outData += 4;
}


// ========================================================================
// ?EmitAlphaIndices@idDxtEncoder@@AAAXPBEHEE@Z
// EA  : 0x829243D8
// RVA : 0x009243D8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder.cpp
// ========================================================================

void __fastcall idDxtEncoder::EmitAlphaIndices(
        idDxtEncoder *this,
        const unsigned __int8 *colorBlock,
        const int offset,
        int minAlpha,
        int maxAlpha)
{
  int v5; // r10
  int v6; // r22
  int v7; // r27
  int v8; // r8
  int v9; // r11
  int v10; // r30
  int v11; // r31
  int v12; // r6
  int v13; // r7
  unsigned int v14; // r23
  int v15; // ctr
  const unsigned __int8 *v16; // r10
  int v17; // r9
  unsigned int v18; // r29
  int v19; // r5
  unsigned int v20; // r9
  int v21; // r31
  char v22; // r27
  unsigned __int8 v23; // r5
  int v24; // r8
  int v25; // r4
  unsigned __int8 *v26; // r11
  unsigned __int8 *v27; // r11
  unsigned __int8 *v28; // r11
  unsigned __int8 *v29; // r11
  unsigned __int8 *v30; // r11
  _BYTE back_chain[2]; // [sp+0h] [-70h] BYREF
  unsigned __int8 v32; // [sp+2h] [-6Eh]
  char v33; // [sp+3h] [-6Dh]
  char v34; // [sp+4h] [-6Ch]
  unsigned __int8 v35; // [sp+5h] [-6Bh]
  char v36; // [sp+6h] [-6Ah]
  unsigned __int8 v37; // [sp+7h] [-69h]
  char v38; // [sp+8h] [-68h]
  char v39; // [sp+9h] [-67h]
  unsigned __int8 v40; // [sp+Ah] [-66h]
  unsigned __int8 v41; // [sp+Bh] [-65h]
  unsigned __int8 v42; // [sp+Ch] [-64h]
  unsigned __int8 v43; // [sp+Dh] [-63h]
  char v44; // [sp+Eh] [-62h]
  unsigned __int8 v45; // [sp+Fh] [-61h]

  v5 = (unsigned __int8)minAlpha;
  v6 = (unsigned __int8)minAlpha + ((8 * minAlpha) & 0x7F8);
  v7 = (unsigned __int8)maxAlpha + ((2 * maxAlpha) & 0x1FE);
  v8 = (unsigned __int8)minAlpha + (unsigned __int8)maxAlpha + 1;
  v9 = 13 * (unsigned __int8)minAlpha + (unsigned __int8)maxAlpha;
  v10 = (13 * (unsigned __int8)maxAlpha + (unsigned __int8)minAlpha + 7) / 14;
  v11 = ((unsigned __int8)minAlpha + ((2 * minAlpha) & 0x1FE) + 11 * (unsigned __int8)maxAlpha + 7) / 14;
  v12 = ((unsigned __int8)minAlpha + ((4 * minAlpha) & 0x3FC) + (unsigned __int8)maxAlpha + ((8 * maxAlpha) & 0x7F8) + 7)
      / 14;
  v13 = (v6 + (unsigned __int8)maxAlpha + ((4 * maxAlpha) & 0x3FC) + 7) / 14;
  v14 = (unsigned __int8)((11 * v5 + v7 + 7) / 14);
  v15 = 16;
  v16 = &colorBlock[offset];
  v17 = 0;
  do
  {
    v18 = *v16;
    v16 += 4;
    v19 = -((v18 >= (unsigned __int8)((v9 + 7) / 14))
          + (v18 >= v14)
          + (v18 >= (unsigned __int8)v13)
          + (v18 >= (unsigned __int8)(7 * v8 / 14))
          + (v18 >= (unsigned __int8)v12)
          + (v18 >= (unsigned __int8)v11)
          + (v18 >= (unsigned __int8)v10))
        & 7;
    back_chain[v17++] = (v19 >= 2) ^ v19;
    --v15;
  }
  while ( v15 != 0 );
  v20 = v40;
  *this->outData = (8 * (__ROL4__(v32, 3) | back_chain[1])) | back_chain[0];
  v21 = v45;
  v22 = v44;
  v23 = (8 * (__ROL4__(v20, 3) | v39)) | v38;
  v24 = v43 >> 1;
  v25 = (8 * (__ROL4__(v43, 3) | v42)) | v41;
  v26 = this->outData + 1;
  this->outData = v26;
  *v26 = (2 * ((8 * (__ROL4__(v35, 3) | v34)) | v33)) | (v32 >> 2);
  v27 = this->outData + 1;
  this->outData = v27;
  *v27 = (4 * (__ROL4__(v37, 3) | v36)) | (v35 >> 1);
  v28 = this->outData + 1;
  this->outData = v28;
  *v28 = v23;
  v29 = this->outData + 1;
  this->outData = v29;
  *v29 = (2 * v25) | (v20 >> 2);
  v30 = this->outData + 1;
  this->outData = v30;
  *v30 = (4 * (__ROL4__(v21, 3) | v22)) | v24;
  ++this->outData;
}


// ========================================================================
// ?InsetYCoCgAlpaBBox@idDxtEncoder@@ABAXPAE0@Z
// EA  : 0x82924678
// RVA : 0x00924678
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder.cpp
// ========================================================================

void __fastcall idDxtEncoder::InsetYCoCgAlpaBBox(
        idDxtEncoder *this,
        unsigned __int8 *minColor,
        unsigned __int8 *maxColor)
{
  int v3; // r11
  int v4; // r3
  int v5; // r10
  int v6; // r7
  int v7; // r30
  int v8; // r31
  int v9; // r6
  int v10; // r29
  int v11; // r28
  int v12; // r11
  int v13; // r27
  int v14; // r10
  int v15; // r26
  int v16; // r9
  int v17; // r3
  int v18; // r8
  int v19; // r31
  int v20; // r28
  unsigned int v21; // r11
  int v22; // r7
  int v23; // r6
  int v24; // r3
  int v25; // r26
  int v26; // r27
  unsigned int v27; // r9
  unsigned int v28; // r8
  int v29; // r31
  int v30; // r29
  int v31; // r30
  int v32; // r28
  int v33; // r11
  int v34; // r9
  unsigned __int8 v35; // r8
  bool v36; // zf

  v3 = *minColor;
  v4 = *maxColor;
  v5 = minColor[1];
  v6 = __ROL4__(v3, 4);
  v7 = maxColor[1];
  v8 = minColor[2];
  v9 = __ROL4__(v5, 4);
  v10 = maxColor[2];
  v11 = minColor[3];
  v12 = v4 - v3 - 7;
  v13 = maxColor[3];
  v14 = v7 - v5 - 7;
  v15 = __ROL4__(v4, 4);
  v16 = v10 - v8 - 7;
  v17 = __ROL4__(v8, 4);
  v18 = v13 - v11 - 15;
  v19 = __ROL4__(v11, 5);
  v20 = v15 - v12;
  v21 = (v6 + v12) >> 4;
  v22 = (v9 + v14) >> 4;
  v23 = (v17 + v16) >> 4;
  v25 = __ROL4__(v10, 4) - v16;
  v26 = __ROL4__(v13, 5) - v18;
  v27 = (unsigned int)(v17 + v16) >> 31;
  v24 = (v19 + v18) >> 5;
  v28 = (unsigned int)(v19 + v18) >> 31;
  v29 = v20 >> 4;
  v30 = (__ROL4__(v7, 4) - v14) >> 4;
  v31 = v25 >> 4;
  v33 = ((v21 >> 31) - 1) & v21;
  v34 = (v27 - 1) & v23;
  v35 = (v28 - 1) & v24;
  v36 = v20 >> 4 <= 255;
  v32 = v26 >> 5;
  if ( !v36 )
    v29 = 255;
  if ( v30 > 255 )
    v30 = 255;
  if ( v31 > 255 )
    v31 = 255;
  if ( v32 > 255 )
    LOBYTE(v32) = -1;
  minColor[3] = v35;
  *minColor = (v33 >> 5) | v33 & 0xF8;
  minColor[1] = ((int)((((unsigned int)v22 >> 31) - 1) & v22) >> 6) | (v22 < 0 ? 0 : v22) & 0xFC;
  minColor[2] = (v34 >> 5) | v34 & 0xF8;
  *maxColor = (v29 >> 5) | v29 & 0xF8;
  maxColor[1] = (v30 >> 6) | v30 & 0xFC;
  maxColor[2] = (v31 >> 5) | v31 & 0xF8;
  maxColor[3] = v32;
}


// ========================================================================
// ?GetMinMaxColorsHQ@idDxtEncoder@@ABAHPBEPAE1_N@Z
// EA  : 0x829247F0
// RVA : 0x009247F0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder.cpp
// ========================================================================

int __fastcall idDxtEncoder::GetMinMaxColorsHQ(
        idDxtEncoder *this,
        const unsigned __int8 *colorBlock,
        unsigned __int8 *minColor,
        unsigned __int8 *maxColor,
        bool noBlack)
{
  unsigned __int16 v6; // r26
  int v9; // ctr
  unsigned __int8 v10; // r29
  unsigned __int8 v11; // r28
  int v12; // r7
  unsigned __int8 v13; // r3
  unsigned __int8 v14; // r31
  unsigned __int8 v15; // r30
  unsigned __int8 v16; // r27
  const unsigned __int8 *v17; // r4
  unsigned int v18; // r6
  unsigned int v19; // r9
  unsigned int v20; // r11
  unsigned int v21; // r6
  unsigned int v22; // r9
  unsigned int v23; // r11
  unsigned int v24; // r6
  unsigned int v25; // r9
  unsigned int v26; // r11
  unsigned int v27; // r6
  unsigned int v28; // r9
  unsigned int v29; // r11
  int v30; // ctr
  int v31; // r11
  unsigned int v32; // r10
  unsigned __int8 v33; // r10
  unsigned __int8 v34; // r8
  unsigned __int8 v35; // r10
  unsigned __int8 v36; // r10
  char v37; // r10
  unsigned __int8 v38; // r9
  char v39; // r10
  char v40; // r11
  int v41; // r20
  unsigned __int16 v42; // r25
  int v43; // r22
  int j; // r23
  int v45; // r24
  int v46; // r14
  int v47; // r18
  int v48; // r16
  int k; // r28
  int v50; // r29
  signed int v51; // r17
  int v52; // r27
  __int16 v53; // r9
  __int16 v54; // r8
  unsigned __int16 v55; // r31
  unsigned __int16 v56; // r30
  int SquareColorsError; // r3
  int v58; // r3
  char v60; // [sp+50h] [-B0h] BYREF
  unsigned __int8 v61; // [sp+51h] [-AFh]
  unsigned __int8 v62; // [sp+52h] [-AEh]
  char v63; // [sp+54h] [-ACh] BYREF
  unsigned __int8 v64; // [sp+55h] [-ABh]
  unsigned __int8 v65; // [sp+56h] [-AAh]
  _BYTE v66[4]; // [sp+58h] [-A8h] BYREF
  int v67; // [sp+5Ch] [-A4h]
  int v68; // [sp+60h] [-A0h]
  int i; // [sp+64h] [-9Ch]

  v6 = 0;
  v9 = 4;
  v10 = 0;
  v11 = 0;
  v12 = 0x7FFFFFFF;
  v13 = -1;
  v14 = -1;
  v15 = -1;
  v16 = 0;
  v17 = colorBlock + 2;
  do
  {
    v18 = *(v17 - 2);
    if ( v18 < v15 )
      v15 = *(v17 - 2);
    v19 = *(v17 - 1);
    if ( v19 < v14 )
      v14 = *(v17 - 1);
    v20 = *v17;
    if ( v20 < v13 )
      v13 = *v17;
    if ( v18 > v16 )
      v16 = *(v17 - 2);
    if ( v19 > v11 )
      v11 = *(v17 - 1);
    if ( v20 > v10 )
      v10 = *v17;
    v21 = v17[2];
    if ( v21 < v15 )
      v15 = v17[2];
    v22 = v17[3];
    if ( v22 < v14 )
      v14 = v17[3];
    v23 = v17[4];
    if ( v23 < v13 )
      v13 = v17[4];
    if ( v21 > v16 )
      v16 = v17[2];
    if ( v22 > v11 )
      v11 = v17[3];
    if ( v23 > v10 )
      v10 = v17[4];
    v24 = v17[6];
    if ( v24 < v15 )
      v15 = v17[6];
    v25 = v17[7];
    if ( v25 < v14 )
      v14 = v17[7];
    v26 = v17[8];
    if ( v26 < v13 )
      v13 = v17[8];
    if ( v24 > v16 )
      v16 = v17[6];
    if ( v25 > v11 )
      v11 = v17[7];
    if ( v26 > v10 )
      v10 = v17[8];
    v27 = v17[10];
    if ( v27 < v15 )
      v15 = v17[10];
    v28 = v17[11];
    if ( v28 < v14 )
      v14 = v17[11];
    v29 = v17[12];
    if ( v29 < v13 )
      v13 = v17[12];
    if ( v27 > v16 )
      v16 = v17[10];
    if ( v28 > v11 )
      v11 = v17[11];
    if ( v29 > v10 )
      v10 = v17[12];
    v17 += 16;
    --v9;
  }
  while ( v9 != 0 );
  v60 = v15 >> 3;
  v61 = v14 >> 2;
  v30 = 3;
  v62 = v13 >> 3;
  v63 = v16 >> 3;
  v31 = 0;
  v64 = v11 >> 2;
  v65 = v10 >> 3;
  do
  {
    v32 = (unsigned __int8)(*(&v63 + v31) - *(&v60 + v31));
    v66[v31] = v32;
    if ( v32 < 0x10 )
    {
      if ( v32 < 8 )
      {
        if ( v32 < 4 )
          v66[v31] = 0;
        else
          v66[v31] = (unsigned __int8)v32 >> 2;
      }
      else
      {
        v66[v31] = (int)(2 * v32) / 4;
      }
    }
    else
    {
      v66[v31] = (int)(3 * v32) / 4;
    }
    ++v31;
    --v30;
  }
  while ( v30 != 0 );
  v33 = 0;
  if ( (unsigned __int8)(v15 >> 3) > 1u )
    v33 = (v15 >> 3) - 1;
  v34 = v33;
  v35 = 0;
  if ( (unsigned __int8)(v14 >> 2) > 1u )
    v35 = (v14 >> 2) - 1;
  v61 = v35;
  v36 = 0;
  if ( (unsigned __int8)(v13 >> 3) > 1u )
    v36 = (v13 >> 3) - 1;
  v62 = v36;
  v37 = 31;
  if ( (unsigned __int8)(v16 >> 3) < 0x1Eu )
    v37 = (v16 >> 3) + 1;
  v38 = v37;
  v39 = 63;
  if ( (unsigned __int8)(v11 >> 2) < 0x3Eu )
    v39 = (v11 >> 2) + 1;
  v64 = v39;
  if ( (unsigned __int8)(v10 >> 3) < 0x1Eu )
    v40 = (v10 >> 3) + 1;
  else
    v40 = 31;
  v41 = v34;
  v65 = v40;
  v68 = v34;
  v42 = 0;
  for ( i = v38; v41 <= i; ++v41 )
  {
    v43 = i;
    if ( i >= v68 )
    {
      v67 = v41 - i;
      do
      {
        if ( (int)abs32(v67) >= v66[0] )
        {
          for ( j = v61; j <= v64; ++j )
          {
            v45 = v64;
            if ( v64 >= (int)v61 )
            {
              v46 = j - v64;
              do
              {
                if ( (int)abs32(v46) >= v66[1] )
                {
                  v47 = v62;
                  v48 = v65;
                  for ( k = v62; k <= v48; ++k )
                  {
                    v50 = v48;
                    if ( v48 >= v47 )
                    {
                      v51 = v66[2];
                      v52 = k - v48;
                      do
                      {
                        if ( (int)abs32(v52) >= v51 )
                        {
                          v53 = ((_WORD)v41 << 6) | j;
                          v54 = ((_WORD)v43 << 6) | v45;
                          v55 = (32 * v53) | k;
                          v56 = (32 * v54) | v50;
                          if ( noBlack )
                          {
                            if ( (unsigned __int16)((32 * v53) | k) <= (unsigned int)(unsigned __int16)((32 * v54) | v50) )
                            {
                              v55 = (32 * v54) | v50;
                              v56 = (32 * v53) | k;
                            }
                          }
                          else
                          {
                            SquareColorsError = idDxtEncoder::GetSquareColorsError(
                                                  this,
                                                  colorBlock,
                                                  color0: (32 * v54) | v50,
                                                  color1: (32 * v53) | k,
                                                  lastError: v12);
                            if ( SquareColorsError < v12 )
                            {
                              v12 = SquareColorsError;
                              v42 = v55;
                              v6 = v56;
                            }
                          }
                          v58 = idDxtEncoder::GetSquareColorsError(
                                  this,
                                  colorBlock,
                                  color0: v55,
                                  color1: v56,
                                  lastError: v12);
                          if ( v58 < v12 )
                          {
                            v12 = v58;
                            v42 = v55;
                            v6 = v56;
                          }
                        }
                        --v50;
                        ++v52;
                      }
                      while ( v50 >= v47 );
                    }
                  }
                }
                --v45;
                ++v46;
              }
              while ( v45 >= v61 );
            }
          }
        }
        --v43;
        ++v67;
      }
      while ( v43 >= v68 );
    }
  }
  *minColor = (v42 >> 13) | HIBYTE(v42) & 0xF8;
  minColor[1] = (v42 >> 9) & 3 | (v42 >> 3) & 0xFC;
  minColor[2] = (8 * v42) | (v42 >> 2) & 7;
  *maxColor = (v6 >> 13) | HIBYTE(v6) & 0xF8;
  maxColor[2] = (8 * v6) | (v6 >> 2) & 7;
  maxColor[1] = (v6 >> 9) & 3 | (v6 >> 3) & 0xFC;
  return v12;
}


// ========================================================================
// ?GetMinMaxNormalYHQ@idDxtEncoder@@ABAHPBEPAE1_NH@Z
// EA  : 0x82924DD8
// RVA : 0x00924DD8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder.cpp
// ========================================================================

int __fastcall idDxtEncoder::GetMinMaxNormalYHQ(
        idDxtEncoder *this,
        const unsigned __int8 *colorBlock,
        unsigned __int8 *minColor,
        unsigned __int8 *maxColor,
        bool noBlack,
        int scale)
{
  int v10; // ctr
  unsigned __int8 v13; // r11
  int v14; // r7
  unsigned __int8 v15; // r6
  const unsigned __int8 *v16; // r8
  unsigned int v17; // r10
  unsigned int v18; // r10
  unsigned int v19; // r10
  unsigned int v20; // r10
  unsigned int v21; // r11
  unsigned __int8 v22; // r10
  unsigned __int8 v23; // r11
  int v24; // r24
  unsigned __int16 v25; // r29
  unsigned __int16 v26; // r28
  int v27; // r26
  int i; // r22
  int v29; // r27
  int v30; // r25
  __int64 v31; // r10
  int v32; // r31
  int v33; // r30
  __int64 v34; // r6
  int SquareNormalYError; // r3
  int v36; // r3
  unsigned __int8 v38; // r4
  unsigned __int8 v39; // r10

  v10 = 4;
  v13 = -1;
  v14 = 0x7FFFFFFF;
  v15 = 0;
  v16 = colorBlock + 5;
  do
  {
    v17 = *(v16 - 4);
    if ( v17 < v13 )
      v13 = *(v16 - 4);
    if ( v17 > v15 )
      v15 = *(v16 - 4);
    v18 = *v16;
    if ( v18 < v13 )
      v13 = *v16;
    if ( v18 > v15 )
      v15 = *v16;
    v19 = v16[4];
    if ( v19 < v13 )
      v13 = v16[4];
    if ( v19 > v15 )
      v15 = v16[4];
    v20 = v16[8];
    if ( v20 < v13 )
      v13 = v16[8];
    if ( v20 > v15 )
      v15 = v16[8];
    v16 += 16;
    --v10;
  }
  while ( v10 != 0 );
  v21 = v13 >> 2;
  v22 = 0;
  if ( v21 > 1 )
    v22 = v21 - 1;
  if ( (unsigned __int8)(v15 >> 2) < 0x3Eu )
    v23 = (v15 >> 2) + 1;
  else
    v23 = 63;
  v24 = v22;
  v25 = 0;
  v26 = 0;
  v27 = v22;
  for ( i = v23; v27 <= i; ++v27 )
  {
    v29 = i;
    if ( i >= v24 )
    {
      v30 = v27 - i;
      do
      {
        HIDWORD(v31) = abs32(v30);
        if ( v31 >= 0 )
        {
          v32 = (32 * v27) & 0xFFE0;
          v33 = (32 * v29) & 0xFFE0;
          if ( noBlack )
          {
            LODWORD(v31) = (unsigned __int16)(32 * v27);
            if ( (unsigned int)v31 <= (unsigned __int16)(32 * v29) )
            {
              v32 = (32 * v29) & 0xFFE0;
              v33 = (32 * v27) & 0xFFE0;
            }
          }
          else
          {
            LODWORD(v34) = (32 * v27) & 0xFFE0;
            HIDWORD(v34) = (32 * v29) & 0xFFE0;
            LODWORD(v31) = v30 ^ (v30 >> 31);
            SquareNormalYError = idDxtEncoder::GetSquareNormalYError(
                                   this,
                                   color0: v34,
                                   color1: v14,
                                   lastError: scale,
                                   scale: v31);
            if ( SquareNormalYError < v14 )
            {
              LOWORD(v14) = SquareNormalYError;
              v25 = 32 * v27;
              v26 = 32 * v29;
            }
          }
          v36 = idDxtEncoder::GetSquareNormalYError(
                  this,
                  color0: __SPAIR64__(v32, v33),
                  color1: v14,
                  lastError: scale,
                  scale: v31);
          if ( v36 < v14 )
          {
            v14 = v36;
            v25 = v32;
            v26 = v33;
          }
        }
        --v29;
        ++v30;
      }
      while ( v29 >= v24 );
    }
  }
  *minColor = (v25 >> 13) | HIBYTE(v25) & 0xF8;
  minColor[1] = (v25 >> 9) & 3 | (v25 >> 3) & 0xFC;
  minColor[2] = (8 * v25) | (v25 >> 2) & 7;
  *maxColor = (v26 >> 13) | HIBYTE(v26) & 0xF8;
  maxColor[1] = (v26 >> 9) & 3 | (v26 >> 3) & 0xFC;
  maxColor[2] = (8 * v26) | (v26 >> 2) & 7;
  v38 = *colorBlock;
  v39 = colorBlock[2];
  *maxColor = *colorBlock;
  *minColor = v38;
  maxColor[2] = v39;
  minColor[2] = v39;
  return v14;
}


// ========================================================================
// ?CompressImageDXT1HQ@idDxtEncoder@@QAAXPBEPAEHH@Z
// EA  : 0x82925060
// RVA : 0x00925060
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder.cpp
// ========================================================================

void __fastcall idDxtEncoder::CompressImageDXT1HQ(
        idDxtEncoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height)
{
  const unsigned __int8 *v6; // r24
  int v8; // r22
  unsigned int v9; // r25
  int v10; // r28
  const unsigned __int8 *v11; // r27
  unsigned int v12; // r26
  int v13; // r29
  unsigned __int16 v14; // r30
  int ColorIndices; // r21
  int v16; // r3
  unsigned __int8 *outData; // r10
  unsigned __int8 v18; // r9
  unsigned __int8 v19; // r6
  unsigned __int8 v20; // r5
  unsigned __int8 v21; // r4
  unsigned int v22; // r10
  unsigned __int8 *v23; // r11
  unsigned __int8 *v24; // r11
  unsigned __int8 *v25; // r11
  int v26; // r11
  unsigned __int8 v27[4]; // [sp+50h] [-B0h] BYREF
  unsigned __int8 v28; // [sp+54h] [-ACh] BYREF
  unsigned __int8 v29; // [sp+55h] [-ABh]
  unsigned __int8 v30; // [sp+56h] [-AAh]
  unsigned int v31; // [sp+58h] [-A8h] BYREF
  unsigned int v32; // [sp+5Ch] [-A4h] BYREF
  _QWORD v33[20]; // [sp+60h] [-A0h] BYREF

  this->width = width;
  v6 = inBuf;
  this->height = height;
  this->outData = outBuf;
  if ( (width <= 4 || (width & 3) == 0) && (height <= 4 || (height & 3) == 0) )
  {
    if ( width < 4 || height < 4 )
    {
      idDxtEncoder::WriteTinyColorDXT1(this, inBuf, width, height);
    }
    else
    {
      v8 = 16 * width;
      v9 = ((unsigned int)(height - 1) >> 2) + 1;
      do
      {
        if ( width > 0 )
        {
          v10 = 4 * width;
          v11 = v6;
          v12 = ((unsigned int)(width - 1) >> 2) + 1;
          do
          {
            *(_OWORD *)v33 = *(_OWORD *)v11;
            *(_OWORD *)&v33[2] = *(_OWORD *)&v11[4 * width];
            *(_OWORD *)&v33[4] = *(_OWORD *)&v11[v10 + v10];
            *(_OWORD *)&v33[6] = *(_OWORD *)&v11[v10 + v10 + v10];
            idDxtEncoder::GetMinMaxColorsHQ(
              this,
              colorBlock: (const unsigned __int8 *)v33,
              minColor: v27,
              maxColor: &v28,
              noBlack: false);
            v13 = (8 * ((32 * v28) & 0x3F00 | v29)) & 0xFFE0 | (v30 >> 3);
            v14 = (8 * ((32 * v27[0]) & 0x3F00 | v27[1])) & 0xFFE0 | (v27[2] >> 3);
            ColorIndices = idDxtEncoder::FindColorIndices(
                             this,
                             colorBlock: (const unsigned __int8 *)v33,
                             color0: v14,
                             color1: (8 * ((32 * v28) & 0x3F00 | v29)) & 0xFFE0 | (v30 >> 3),
                             result: &v31);
            v16 = idDxtEncoder::FindColorIndices(
                    this,
                    colorBlock: (const unsigned __int8 *)v33,
                    color0: v13,
                    color1: v14,
                    result: &v32);
            outData = this->outData;
            if ( ColorIndices >= v16 )
            {
              *outData = v13;
              v18 = HIBYTE(v14);
              v19 = v32;
              v20 = BYTE2(v32);
              v21 = BYTE1(v32);
              v22 = HIBYTE(v32);
              this->outData[1] = BYTE2(v13);
              v24 = this->outData + 2;
              this->outData = v24;
              *v24 = v14;
            }
            else
            {
              *outData = v14;
              v18 = BYTE2(v13);
              this->outData[1] = HIBYTE(v14);
              v19 = v31;
              v20 = BYTE2(v31);
              v21 = BYTE1(v31);
              v22 = HIBYTE(v31);
              v23 = this->outData + 2;
              this->outData = v23;
              *v23 = v13;
            }
            --v12;
            v11 += 16;
            this->outData[1] = v18;
            v25 = this->outData + 2;
            this->outData = v25;
            *v25 = v19;
            this->outData[1] = v20;
            this->outData[2] = v21;
            this->outData[3] = v22;
            this->outData += 4;
          }
          while ( v12 != 0 );
        }
        --v9;
        v26 = this->srcPadding + v8;
        this->outData += this->dstPadding;
        v6 += v26;
      }
      while ( v9 != 0 );
    }
  }
}


// ========================================================================
// ?CompressImageDXT5HQ@idDxtEncoder@@QAAXPBEPAEHH@Z
// EA  : 0x829252D0
// RVA : 0x009252D0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder.cpp
// ========================================================================

void __fastcall idDxtEncoder::CompressImageDXT5HQ(
        idDxtEncoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height)
{
  const unsigned __int8 *v6; // r24
  int v8; // r22
  unsigned int v9; // r25
  int v10; // r26
  const unsigned __int8 *v11; // r28
  unsigned int v12; // r27
  unsigned __int8 v13; // r30
  unsigned __int8 v14; // r29
  int AlphaIndices; // r21
  int v16; // r3
  unsigned __int8 *outData; // r11
  unsigned __int8 *v18; // r11
  unsigned __int8 v19; // r10
  unsigned __int8 v20; // r9
  unsigned __int8 v21; // r8
  unsigned __int8 v22; // r7
  unsigned __int8 v23; // r6
  unsigned __int8 v24; // r5
  unsigned __int8 *v25; // r11
  unsigned __int8 *v26; // r11
  unsigned __int8 *v27; // r11
  unsigned __int8 *v28; // r11
  unsigned __int8 *v29; // r11
  unsigned __int8 *v30; // r11
  unsigned __int8 *v31; // r11
  unsigned __int8 v32; // r6
  unsigned __int8 v33; // r9
  int v34; // r7
  unsigned __int8 v35; // r3
  int v36; // r10
  unsigned __int8 v37; // r29
  unsigned __int8 v38; // r5
  unsigned __int8 v39; // r8
  int v40; // r30
  int v41; // r29
  unsigned int v42; // r4
  unsigned __int8 *v43; // r11
  char v44; // r4
  unsigned __int8 v45; // r3
  unsigned __int8 v46; // r30
  unsigned __int16 v47; // r5
  unsigned __int8 *v48; // r11
  unsigned __int8 v49; // r9
  unsigned __int8 v50; // r8
  unsigned int v51; // r7
  unsigned __int8 v52; // [sp+50h] [-C0h] BYREF
  unsigned __int8 v53; // [sp+51h] [-BFh]
  unsigned __int8 v54; // [sp+52h] [-BEh]
  unsigned __int8 v55; // [sp+53h] [-BDh]
  unsigned __int8 v56; // [sp+54h] [-BCh] BYREF
  unsigned __int8 v57; // [sp+55h] [-BBh]
  unsigned __int8 v58; // [sp+56h] [-BAh]
  unsigned __int8 v59; // [sp+57h] [-B9h]
  unsigned int v60; // [sp+58h] [-B8h] BYREF
  unsigned __int8 v61[8]; // [sp+5Ch] [-B4h] BYREF
  unsigned __int8 v62[12]; // [sp+64h] [-ACh] BYREF
  _QWORD v63[20]; // [sp+70h] [-A0h] BYREF

  this->width = width;
  v6 = inBuf;
  this->height = height;
  this->outData = outBuf;
  if ( (width <= 4 || (width & 3) == 0) && (height <= 4 || (height & 3) == 0) )
  {
    if ( width < 4 || height < 4 )
    {
      idDxtEncoder::WriteTinyColorDXT5(this, inBuf, width, height);
    }
    else
    {
      v8 = 16 * width;
      v9 = ((unsigned int)(height - 1) >> 2) + 1;
      do
      {
        if ( width > 0 )
        {
          v10 = 4 * width;
          v11 = v6;
          v12 = ((unsigned int)(width - 1) >> 2) + 1;
          do
          {
            *(_OWORD *)v63 = *(_OWORD *)v11;
            *(_OWORD *)&v63[2] = *(_OWORD *)&v11[4 * width];
            *(_OWORD *)&v63[4] = *(_OWORD *)&v11[v10 + v10];
            *(_OWORD *)&v63[6] = *(_OWORD *)&v11[v10 + v10 + v10];
            idDxtEncoder::GetMinMaxColorsHQ(
              this,
              colorBlock: (const unsigned __int8 *)v63,
              minColor: &v56,
              maxColor: &v52,
              noBlack: true);
            idDxtEncoder::GetMinMaxAlphaHQ(
              this,
              colorBlock: (const unsigned __int8 *)v63,
              alphaOffset: 3,
              minColor: &v56,
              maxColor: &v52);
            v13 = v59;
            v14 = v55;
            AlphaIndices = idDxtEncoder::FindAlphaIndices(
                             this,
                             colorBlock: (const unsigned __int8 *)v63,
                             alphaOffset: 3,
                             alpha0: v55,
                             alpha1: v59,
                             rindexes: v62);
            v16 = idDxtEncoder::FindAlphaIndices(
                    this,
                    colorBlock: (const unsigned __int8 *)v63,
                    alphaOffset: 3,
                    alpha0: v13,
                    alpha1: v14,
                    rindexes: v61);
            outData = this->outData;
            if ( v16 >= AlphaIndices )
            {
              *outData = v14;
              v19 = v62[0];
              v20 = v62[1];
              v21 = v62[2];
              v22 = v62[3];
              v23 = v62[4];
              v24 = v62[5];
              v25 = this->outData + 1;
              this->outData = v25;
              *v25 = v13;
            }
            else
            {
              *outData = v13;
              v18 = this->outData + 1;
              this->outData = v18;
              v19 = v61[0];
              v20 = v61[1];
              v21 = v61[2];
              v22 = v61[3];
              v23 = v61[4];
              v24 = v61[5];
              *v18 = v14;
            }
            v26 = this->outData + 1;
            this->outData = v26;
            *v26 = v19;
            v27 = this->outData + 1;
            this->outData = v27;
            *v27 = v20;
            v28 = this->outData + 1;
            this->outData = v28;
            *v28 = v21;
            v29 = this->outData + 1;
            this->outData = v29;
            *v29 = v22;
            v30 = this->outData + 1;
            this->outData = v30;
            *v30 = v23;
            v31 = this->outData + 1;
            v32 = v57;
            v33 = v53;
            v34 = v56;
            v35 = v57;
            v36 = v52;
            v37 = v53;
            this->outData = v31;
            *v31 = v24;
            v38 = v58;
            v39 = v54;
            v40 = (8 * ((32 * v36) & 0x3F00 | v37)) & 0xFFE0;
            v41 = v54 >> 3;
            v42 = (8 * ((32 * v34) & 0x3F00 | v35)) & 0xFFE0 | (v58 >> 3);
            v43 = this->outData + 1;
            this->outData = v43;
            if ( (v40 | (unsigned int)v41) > v42 )
            {
              v44 = v36;
              v52 = v34;
              v45 = v33;
              v53 = v32;
              v46 = v39;
              v54 = v38;
              v56 = v36;
              LOBYTE(v36) = v34;
              v57 = v33;
              v33 = v32;
              v58 = v39;
              v39 = v38;
              LOBYTE(v34) = v44;
              v32 = v45;
              v38 = v46;
            }
            v47 = (8 * ((32 * (unsigned __int8)v34) & 0x3F00 | v32)) & 0xFFE0 | (v38 >> 3);
            *v43 = v47;
            this->outData[1] = HIBYTE(v47);
            v48 = this->outData + 2;
            this->outData = v48;
            *v48 = (8 * v33) & 0xE0 | (v39 >> 3);
            this->outData[1] = (unsigned __int16)((8 * ((32 * (unsigned __int8)v36) & 0x3F00 | v33)) & 0xFFE0) >> 8;
            this->outData += 2;
            idDxtEncoder::FindColorIndices(
              this,
              colorBlock: (const unsigned __int8 *)v63,
              color0: v47,
              color1: (8 * ((32 * (unsigned __int8)v36) & 0x3F00 | v33)) & 0xFFE0 | (v39 >> 3),
              result: &v60);
            --v12;
            v49 = BYTE2(v60);
            v50 = BYTE1(v60);
            v51 = HIBYTE(v60);
            *this->outData = v60;
            v11 += 16;
            this->outData[1] = v49;
            this->outData[2] = v50;
            this->outData[3] = v51;
            this->outData += 4;
          }
          while ( v12 != 0 );
        }
        --v9;
        v6 += v8 + this->srcPadding;
        this->outData += this->dstPadding;
      }
      while ( v9 != 0 );
    }
  }
}


// ========================================================================
// ?CompressNormalMapDXT5HQ@idDxtEncoder@@QAAXPBEPAEHH@Z
// EA  : 0x82925688
// RVA : 0x00925688
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder.cpp
// ========================================================================

void __fastcall idDxtEncoder::CompressNormalMapDXT5HQ(
        idDxtEncoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height)
{
  const unsigned __int8 *v6; // r23
  int v8; // r20
  unsigned int v9; // r21
  int v10; // r24
  const unsigned __int8 *v11; // r28
  const unsigned __int8 *v12; // r27
  unsigned int v13; // r26
  __int16 *v14; // r11
  int i; // ctr
  char v16; // r10
  char v17; // r9
  char v18; // r8
  char v19; // r7
  unsigned __int8 v20; // r30
  unsigned __int8 v21; // r29
  int AlphaIndices; // r19
  int v23; // r3
  unsigned __int8 *outData; // r11
  unsigned __int8 *v25; // r11
  unsigned __int8 v26; // r10
  unsigned __int8 v27; // r9
  unsigned __int8 v28; // r8
  unsigned __int8 v29; // r7
  unsigned __int8 v30; // r6
  unsigned __int8 v31; // r5
  unsigned __int8 *v32; // r11
  unsigned __int8 *v33; // r11
  unsigned __int8 *v34; // r11
  unsigned __int8 *v35; // r11
  unsigned __int8 *v36; // r11
  unsigned __int8 *v37; // r11
  unsigned __int8 *v38; // r11
  unsigned __int8 v39; // r6
  unsigned __int8 v40; // r9
  int v41; // r7
  unsigned __int8 v42; // r3
  int v43; // r10
  unsigned __int8 v44; // r29
  unsigned __int8 v45; // r5
  unsigned __int8 v46; // r8
  int v47; // r30
  int v48; // r29
  unsigned int v49; // r4
  unsigned __int8 *v50; // r11
  char v51; // r4
  unsigned __int8 v52; // r3
  unsigned __int8 v53; // r30
  unsigned __int16 v54; // r5
  unsigned __int8 *v55; // r11
  unsigned __int8 v56; // r9
  unsigned __int8 v57; // r8
  unsigned int v58; // r7
  unsigned __int8 v59; // [sp+50h] [-D0h] BYREF
  unsigned __int8 v60; // [sp+51h] [-CFh]
  unsigned __int8 v61; // [sp+52h] [-CEh]
  unsigned __int8 v62; // [sp+53h] [-CDh]
  unsigned __int8 v63; // [sp+54h] [-CCh] BYREF
  unsigned __int8 v64; // [sp+55h] [-CBh]
  unsigned __int8 v65; // [sp+56h] [-CAh]
  unsigned __int8 v66; // [sp+57h] [-C9h]
  unsigned int v67; // [sp+58h] [-C8h] BYREF
  unsigned __int8 v68[8]; // [sp+5Ch] [-C4h] BYREF
  unsigned __int8 v69[10]; // [sp+64h] [-BCh] BYREF
  __int16 v70; // [sp+6Eh] [-B2h] BYREF
  _QWORD v71[22]; // [sp+70h] [-B0h] BYREF

  this->width = width;
  v6 = inBuf;
  this->height = height;
  this->outData = outBuf;
  if ( (width <= 4 || (width & 3) == 0) && (height <= 4 || (height & 3) == 0) )
  {
    if ( width < 4 || height < 4 )
    {
      idDxtEncoder::WriteTinyColorDXT5(this, inBuf, width, height);
    }
    else
    {
      v8 = 16 * width;
      v9 = ((unsigned int)(height - 1) >> 2) + 1;
      do
      {
        if ( width > 0 )
        {
          v10 = 4 * width;
          v11 = v6;
          v12 = &v6[8 * width];
          v13 = ((unsigned int)(width - 1) >> 2) + 1;
          do
          {
            *(_OWORD *)v71 = *(_OWORD *)v11;
            *(_OWORD *)&v71[2] = *(_OWORD *)&v11[v10];
            *(_OWORD *)&v71[4] = *(_OWORD *)v12;
            *(_OWORD *)&v71[6] = *(_OWORD *)&v12[v10];
            v14 = &v70;
            for ( i = 4; i != 0; --i )
            {
              v16 = *((_BYTE *)v14 + 2);
              v17 = *((_BYTE *)v14 + 6);
              v18 = *((_BYTE *)v14 + 10);
              v19 = *((_BYTE *)v14 + 14);
              *((_BYTE *)v14 + 2) = 0;
              *((_BYTE *)v14 + 5) = v16;
              *((_BYTE *)v14 + 4) = 0;
              *((_BYTE *)v14 + 9) = v17;
              *((_BYTE *)v14 + 6) = 0;
              *((_BYTE *)v14 + 8) = 0;
              *((_BYTE *)v14 + 13) = v18;
              *((_BYTE *)v14 + 10) = 0;
              *((_BYTE *)v14 + 12) = 0;
              *((_BYTE *)v14 + 17) = v19;
              *((_BYTE *)v14 + 14) = 0;
              v14 += 8;
              *(_BYTE *)v14 = 0;
            }
            idDxtEncoder::GetMinMaxNormalYHQ(
              this,
              colorBlock: (const unsigned __int8 *)v71,
              minColor: &v63,
              maxColor: &v59,
              noBlack: true,
              scale: 1);
            idDxtEncoder::GetMinMaxAlphaHQ(
              this,
              colorBlock: (const unsigned __int8 *)v71,
              alphaOffset: 3,
              minColor: &v63,
              maxColor: &v59);
            v20 = v66;
            v21 = v62;
            AlphaIndices = idDxtEncoder::FindAlphaIndices(
                             this,
                             colorBlock: (const unsigned __int8 *)v71,
                             alphaOffset: 3,
                             alpha0: v62,
                             alpha1: v66,
                             rindexes: v69);
            v23 = idDxtEncoder::FindAlphaIndices(
                    this,
                    colorBlock: (const unsigned __int8 *)v71,
                    alphaOffset: 3,
                    alpha0: v20,
                    alpha1: v21,
                    rindexes: v68);
            outData = this->outData;
            if ( v23 >= AlphaIndices )
            {
              *outData = v21;
              v26 = v69[0];
              v27 = v69[1];
              v28 = v69[2];
              v29 = v69[3];
              v30 = v69[4];
              v31 = v69[5];
              v32 = this->outData + 1;
              this->outData = v32;
              *v32 = v20;
            }
            else
            {
              *outData = v20;
              v25 = this->outData + 1;
              this->outData = v25;
              v26 = v68[0];
              v27 = v68[1];
              v28 = v68[2];
              v29 = v68[3];
              v30 = v68[4];
              v31 = v68[5];
              *v25 = v21;
            }
            v33 = this->outData + 1;
            this->outData = v33;
            *v33 = v26;
            v34 = this->outData + 1;
            this->outData = v34;
            *v34 = v27;
            v35 = this->outData + 1;
            this->outData = v35;
            *v35 = v28;
            v36 = this->outData + 1;
            this->outData = v36;
            *v36 = v29;
            v37 = this->outData + 1;
            this->outData = v37;
            *v37 = v30;
            v38 = this->outData + 1;
            v39 = v64;
            v40 = v60;
            v41 = v63;
            v42 = v64;
            v43 = v59;
            v44 = v60;
            this->outData = v38;
            *v38 = v31;
            v45 = v65;
            v46 = v61;
            v47 = (8 * ((32 * v43) & 0x3F00 | v44)) & 0xFFE0;
            v48 = v61 >> 3;
            v49 = (8 * ((32 * v41) & 0x3F00 | v42)) & 0xFFE0 | (v65 >> 3);
            v50 = this->outData + 1;
            this->outData = v50;
            if ( (v47 | (unsigned int)v48) > v49 )
            {
              v51 = v43;
              v59 = v41;
              v52 = v40;
              v60 = v39;
              v53 = v46;
              v61 = v45;
              v63 = v43;
              LOBYTE(v43) = v41;
              v64 = v40;
              v40 = v39;
              v65 = v46;
              v46 = v45;
              LOBYTE(v41) = v51;
              v39 = v52;
              v45 = v53;
            }
            v54 = (8 * ((32 * (unsigned __int8)v41) & 0x3F00 | v39)) & 0xFFE0 | (v45 >> 3);
            *v50 = v54;
            this->outData[1] = HIBYTE(v54);
            v55 = this->outData + 2;
            this->outData = v55;
            *v55 = (8 * v40) & 0xE0 | (v46 >> 3);
            this->outData[1] = (unsigned __int16)((8 * ((32 * (unsigned __int8)v43) & 0x3F00 | v40)) & 0xFFE0) >> 8;
            this->outData += 2;
            idDxtEncoder::FindColorIndices(
              this,
              colorBlock: (const unsigned __int8 *)v71,
              color0: v54,
              color1: (8 * ((32 * (unsigned __int8)v43) & 0x3F00 | v40)) & 0xFFE0 | (v46 >> 3),
              result: &v67);
            --v13;
            v56 = BYTE2(v67);
            v57 = BYTE1(v67);
            v58 = HIBYTE(v67);
            *this->outData = v67;
            v11 += 16;
            v12 += 16;
            this->outData[1] = v56;
            this->outData[2] = v57;
            this->outData[3] = v58;
            this->outData += 4;
          }
          while ( v13 != 0 );
        }
        --v9;
        v6 += v8 + this->srcPadding;
        this->outData += this->dstPadding;
      }
      while ( v9 != 0 );
    }
  }
}


// ========================================================================
// ?SelectColorsDiagonal@idDxtEncoder@@ABAXPBEPAE1@Z
// EA  : 0x82925A98
// RVA : 0x00925A98
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder.cpp
// ========================================================================

void __fastcall idDxtEncoder::SelectColorsDiagonal(
        idDxtEncoder *this,
        const unsigned __int8 *colorBlock,
        unsigned __int8 *minColor,
        unsigned __int8 *maxColor)
{
  int v4; // r23
  int v5; // r25
  int v6; // r22
  int v7; // r24
  int v8; // ctr
  unsigned int v9; // r31
  unsigned int v10; // r30
  unsigned int v11; // r29
  int v12; // r9
  int v13; // r8
  int v14; // r7
  int v15; // r3
  const unsigned __int8 *v16; // r11
  BOOL v17; // r19
  BOOL v18; // r20
  BOOL v19; // r21
  int v20; // r27
  int v21; // r26
  char v22; // r11
  unsigned __int8 v23; // r3
  unsigned __int8 v24; // r11
  int v25; // r4
  __int16 v26; // r10
  __int16 v27; // r11
  unsigned __int8 v28; // r11
  unsigned __int8 v29; // r9

  v4 = *minColor;
  v5 = *maxColor;
  v6 = minColor[2];
  v7 = maxColor[2];
  v8 = 8;
  v9 = (unsigned __int8)((v5 + v4 + 1) >> 1);
  v10 = (unsigned __int8)((minColor[1] + maxColor[1] + 1) >> 1);
  v11 = (unsigned __int8)((v7 + v6 + 1) >> 1);
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = colorBlock + 2;
  do
  {
    v17 = *(v16 - 2) >= v9;
    v18 = *(v16 - 1) >= v10;
    v19 = *v16 >= v11;
    v20 = (v16[2] >= v9) ^ (v16[3] >= v10);
    v21 = (v16[4] >= v11) ^ (v16[3] >= v10);
    v16 += 8;
    v12 += v17 ^ v18;
    v13 += v19 ^ v18;
    v14 += v20;
    v15 += v21;
    --v8;
  }
  while ( v8 != 0 );
  v22 = (~((v15 + v13) ^ 8) < 0) + ((unsigned int)(v15 + v13) <= 8);
  v23 = -(((v14 + v12 >= 0) + ((unsigned int)(v14 + v12) <= 8)) & 1) & (v4 ^ v5) ^ v5;
  v24 = -(v22 & 1) & (v6 ^ v7) ^ v7;
  *minColor = v23 ^ v4 ^ v5;
  v25 = v24 >> 3;
  *maxColor = v23;
  minColor[2] = v24 ^ v6 ^ v7;
  v26 = *maxColor;
  maxColor[2] = v24;
  v27 = *minColor;
  if ( ((8 * ((32 * v27) & 0x1F00 | minColor[1])) & 0xFFE0 | (minColor[2] >> 3)) > ((8
                                                                                   * ((32 * v26) & 0x1F00 | maxColor[1]))
                                                                                  & 0xFFE0
                                                                                  | (unsigned int)v25) )
  {
    *minColor = v26;
    *maxColor = v27;
    v28 = minColor[1];
    minColor[1] = maxColor[1];
    maxColor[1] = v28;
    v29 = minColor[2];
    minColor[2] = maxColor[2];
    maxColor[2] = v29;
  }
}


// ========================================================================
// ?CompressYCoCgAlphaDXT5Fast@idDxtEncoder@@QAAXPBEPAEHH@Z
// EA  : 0x82925CA0
// RVA : 0x00925CA0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtencoder.cpp
// ========================================================================

void __fastcall idDxtEncoder::CompressYCoCgAlphaDXT5Fast(
        idDxtEncoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height)
{
  int v8; // r23
  unsigned int v9; // r24
  int v10; // r27
  const unsigned __int8 *v11; // r30
  const unsigned __int8 *v12; // r29
  unsigned int v13; // r28
  unsigned __int8 *v14; // r11
  int i; // ctr
  int v16; // r9
  int v17; // r10
  int v18; // r9
  int v19; // r10
  int v20; // r9
  int v21; // r10
  int v22; // r9
  int v23; // r10
  int v24; // r7
  int v25; // r6
  unsigned __int8 *v26; // r11
  unsigned __int8 v27; // r8
  unsigned __int8 v28; // r7
  unsigned __int8 v29; // r9
  unsigned __int8 *v30; // r11
  int v31; // r11
  unsigned __int8 v32; // [sp+50h] [-A0h] BYREF
  unsigned __int8 v33; // [sp+51h] [-9Fh]
  unsigned __int8 v34; // [sp+52h] [-9Eh]
  unsigned __int8 v35; // [sp+53h] [-9Dh]
  unsigned __int8 v36; // [sp+54h] [-9Ch] BYREF
  unsigned __int8 v37; // [sp+55h] [-9Bh]
  unsigned __int8 v38; // [sp+56h] [-9Ah]
  unsigned __int8 v39; // [sp+57h] [-99h]
  _QWORD v40[18]; // [sp+60h] [-90h] BYREF

  this->width = width;
  this->height = height;
  this->outData = outBuf;
  if ( height > 0 )
  {
    v8 = 16 * width;
    v9 = ((unsigned int)(height - 1) >> 2) + 1;
    do
    {
      if ( width > 0 )
      {
        v10 = 4 * width;
        v11 = inBuf;
        v12 = &inBuf[8 * width];
        v13 = ((unsigned int)(width - 1) >> 2) + 1;
        do
        {
          *(_OWORD *)v40 = *(_OWORD *)v11;
          *(_OWORD *)&v40[2] = *(_OWORD *)&v11[v10];
          *(_OWORD *)&v40[4] = *(_OWORD *)v12;
          *(_OWORD *)&v40[6] = *(_OWORD *)&v12[v10];
          v14 = (unsigned __int8 *)v40;
          for ( i = 4; i != 0; --i )
          {
            v16 = *v14 - 132;
            if ( (int)abs32(v16) <= 8 )
            {
              v17 = v14[2] - 132;
              if ( (int)abs32(v17) <= 8 && v14[3] < 0x60u )
              {
                *v14 = v16 / 2 - 124;
                v14[2] = v17 / 2 - 124;
              }
            }
            v18 = v14[4] - 132;
            if ( (int)abs32(v18) <= 8 )
            {
              v19 = v14[6] - 132;
              if ( (int)abs32(v19) <= 8 && v14[7] < 0x60u )
              {
                v14[4] = v18 / 2 - 124;
                v14[6] = v19 / 2 - 124;
              }
            }
            v20 = v14[8] - 132;
            if ( (int)abs32(v20) <= 8 )
            {
              v21 = v14[10] - 132;
              if ( (int)abs32(v21) <= 8 && v14[11] < 0x60u )
              {
                v14[8] = v20 / 2 - 124;
                v14[10] = v21 / 2 - 124;
              }
            }
            v22 = v14[12] - 132;
            if ( (int)abs32(v22) <= 8 )
            {
              v23 = v14[14] - 132;
              if ( (int)abs32(v23) <= 8 && v14[15] < 0x60u )
              {
                v14[12] = v22 / 2 - 124;
                v14[14] = v23 / 2 - 124;
              }
            }
            v14 += 16;
          }
          idDxtEncoder::GetMinMaxBBox(this, colorBlock: (const unsigned __int8 *)v40, minColor: &v36, maxColor: &v32);
          idDxtEncoder::InsetYCoCgAlpaBBox(this, minColor: &v36, maxColor: &v32);
          idDxtEncoder::SelectColorsDiagonal(
            this,
            colorBlock: (const unsigned __int8 *)v40,
            minColor: &v36,
            maxColor: &v32);
          v24 = v35;
          v25 = v39;
          *this->outData = v35;
          v26 = this->outData + 1;
          this->outData = v26;
          *v26 = v25;
          ++this->outData;
          idDxtEncoder::EmitAlphaIndices(
            this,
            colorBlock: (const unsigned __int8 *)v40,
            offset: 3,
            minAlpha: v25,
            maxAlpha: v24);
          v27 = (unsigned __int16)((8 * ((32 * v32) & 0x3F00 | v33)) & 0xFFE0 | (v34 >> 3)) >> 8;
          v28 = (8 * v37) & 0xE0 | (v38 >> 3);
          v29 = (unsigned __int16)((8 * ((32 * v36) & 0x3F00 | v37)) & 0xFFE0 | (v38 >> 3)) >> 8;
          *this->outData = (8 * v33) & 0xE0 | (v34 >> 3);
          this->outData[1] = v27;
          v30 = this->outData + 2;
          this->outData = v30;
          *v30 = v28;
          this->outData[1] = v29;
          this->outData += 2;
          idDxtEncoder::EmitColorIndices(this, colorBlock: (const unsigned __int8 *)v40, minColor: &v36, maxColor: &v32);
          --v13;
          v11 += 16;
          v12 += 16;
        }
        while ( v13 != 0 );
      }
      --v9;
      v31 = this->srcPadding + v8;
      this->outData += this->dstPadding;
      inBuf += v31;
    }
    while ( v9 != 0 );
  }
}

