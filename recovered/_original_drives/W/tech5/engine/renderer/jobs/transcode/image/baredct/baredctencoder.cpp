
// ========================================================================
// ?MonoToTile@idBareDctEncoder@@AAAXPBEPAFH@Z
// EA  : 0x828E7448
// RVA : 0x008E7448
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

void __fastcall idBareDctEncoder::MonoToTile(
        idBareDctEncoder *this,
        const unsigned __int8 *mono,
        __int16 *ms,
        int stride)
{
  const unsigned __int8 *v4; // r11
  __int16 *v5; // r10
  int i; // ctr
  __int16 v7; // r9

  v4 = mono + 2;
  v5 = ms - 1;
  for ( i = 8; i != 0; --i )
  {
    v5[1] = *(v4 - 2) - 128;
    v5[2] = *(v4 - 1) - 128;
    v5[3] = *v4 - 128;
    v5[4] = v4[1] - 128;
    v5[5] = v4[2] - 128;
    v5[6] = v4[3] - 128;
    v5[7] = v4[4] - 128;
    v7 = v4[5];
    v4 += stride;
    v5 += 8;
    *v5 = v7 - 128;
  }
}


// ========================================================================
// ?RGBToGrayScaleTile@idBareDctEncoder@@AAAXPBEPAFH@Z
// EA  : 0x828E74D0
// RVA : 0x008E74D0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

void __fastcall idBareDctEncoder::RGBToGrayScaleTile(
        idBareDctEncoder *this,
        const unsigned __int8 *rgb,
        __int16 *ms,
        int stride)
{
  const unsigned __int8 *v4; // r11
  __int16 *v5; // r10
  int i; // ctr
  int v7; // r4

  v4 = rgb + 1;
  v5 = ms - 1;
  for ( i = 8; i != 0; --i )
  {
    v5[1] = (2 * (*(v4 - 1) + v4[1] + *v4) + 3) / 6 - 128;
    v5[2] = (2 * (v4[5] + v4[4] + v4[3]) + 3) / 6 - 128;
    v5[3] = (2 * (v4[9] + v4[8] + v4[7]) + 3) / 6 - 128;
    v5[4] = (2 * (v4[13] + v4[12] + v4[11]) + 3) / 6 - 128;
    v5[5] = (2 * (v4[17] + v4[16] + v4[15]) + 3) / 6 - 128;
    v5[6] = (2 * (v4[21] + v4[20] + v4[19]) + 3) / 6 - 128;
    v5[7] = (2 * (v4[25] + v4[24] + v4[23]) + 3) / 6 - 128;
    v7 = v4[29] + v4[28] + v4[27];
    v4 += stride;
    v5 += 8;
    *v5 = (2 * v7 + 3) / 6 - 128;
  }
}


// ========================================================================
// ?RGBToYCoCgTile@idBareDctEncoder@@AAAXPBEPAFH@Z
// EA  : 0x828E7638
// RVA : 0x008E7638
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

void __fastcall idBareDctEncoder::RGBToYCoCgTile(
        idBareDctEncoder *this,
        const unsigned __int8 *rgb,
        __int16 *YCoCg,
        int stride)
{
  int v4; // r23
  __int16 *v5; // r7
  const unsigned __int8 *v6; // r8
  __int16 *v7; // r24
  __int16 *v8; // r25
  int v9; // r22
  int v10; // r9
  _WORD *v11; // r3
  __int16 *v12; // r10
  int i; // ctr
  unsigned __int8 *v14; // r11
  int v15; // r7
  const unsigned __int8 *v16; // r31
  int v17; // r30
  int v18; // r8
  int v19; // r27
  int v20; // r28
  int v21; // r7
  int v22; // r8
  int v23; // r30
  int v24; // r29
  int v25; // r26
  int v26; // r7
  int v27; // r20
  int v28; // r30
  int v29; // r8
  int v30; // r17
  int v31; // r29
  int v32; // r20
  int v33; // r8
  int v34; // r30
  int v35; // r11
  int v36; // r29
  int v37; // r11

  v4 = 0;
  v5 = YCoCg + 8;
  do
  {
    v6 = &rgb[4 * (v4 & 2) * stride + 4 * ((8 * v4) & 8)];
    v7 = &YCoCg[16 * (v4 & 2) + 256 + 4 * (v4 & 1)];
    v8 = v5;
    v9 = 4;
    do
    {
      v10 = 0;
      v11 = v7 + 63;
      v12 = v8 - 1;
      for ( i = 4; i != 0; --i )
      {
        v14 = (unsigned __int8 *)&v6[v10];
        v15 = v6[v10];
        v16 = &v6[stride];
        v17 = v6[v10 + 1];
        v18 = v6[v10 + 2];
        v19 = 2 * (v17 + 256) - v18 - v15;
        v20 = 2 * (v15 + 256) - __ROL4__(v18, 1);
        *(v12 - 7) = ((2 * (v17 + 1) + v18 + v15) >> 2) - 128;
        v21 = v14[4];
        v22 = v14[6];
        v23 = v14[5];
        v24 = __ROL4__(v22, 1);
        *(v12 - 6) = ((2 * (v23 + 1) + v22 + v21) >> 2) - 128;
        v25 = 2 * (v23 + 256) - v22 - v21;
        v27 = 2 * (v21 + 256);
        v26 = v16[v10];
        v28 = v16[v10 + 1];
        v29 = v16[v10 + 2];
        v30 = __ROL4__(v29, 1);
        v31 = v27 - v24;
        v32 = 2 * (v28 + 256) - v29;
        v12[1] = ((2 * (v28 + 1) + v29 + v26) >> 2) - 128;
        v33 = v16[v10 + 6];
        v34 = v16[v10 + 5];
        v35 = v16[v10 + 4];
        v12 += 2;
        *v12 = ((2 * (v34 + 1) + v33 + v35) >> 2) - 128;
        v36 = ((2 * (v35 + 256) - __ROL4__(v33, 1) + 2 * (v26 + 256) - v30 + v31 + v20) >> 2) + 2;
        v37 = 2 * (v34 + 256) - v33 - v35;
        *(v11 - 63) = (v36 >> 2) - 128;
        v6 = &v16[-stride];
        v10 += 8;
        *++v11 = ((((v37 + v32 - v26 + v25 + v19) >> 2) + 2) >> 2) - 128;
      }
      --v9;
      v8 += 16;
      v7 += 8;
      v6 += 2 * stride;
    }
    while ( v9 != 0 );
    ++v4;
    v5 = v8;
  }
  while ( v4 < 4 );
}


// ========================================================================
// ?RGBToYCbCrTile@idBareDctEncoder@@AAAXPBEPAFH@Z
// EA  : 0x828E7848
// RVA : 0x008E7848
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

void __fastcall idBareDctEncoder::RGBToYCbCrTile(
        idBareDctEncoder *this,
        const unsigned __int8 *rgb,
        __int16 *YCbCr,
        int stride)
{
  int v4; // r22
  __int16 *v5; // r31
  const unsigned __int8 *v6; // r3
  __int16 *v7; // r23
  __int16 *v8; // r24
  int v9; // r21
  int v10; // r8
  _WORD *v11; // r29
  __int16 *v12; // r7
  int i; // ctr
  int v14; // r31
  int v15; // r30
  int v16; // r25
  int v17; // r26
  int v18; // r28
  int v19; // r27
  const unsigned __int8 *v20; // r30
  int v21; // r19
  int v22; // r31
  int v23; // r3
  int v24; // r26
  int v25; // r28
  int v26; // r3
  int v27; // r25
  int v28; // r31
  int v29; // r28
  int v30; // r27
  int v31; // r31
  int v32; // r25
  int v33; // r9

  v4 = 0;
  v5 = YCbCr + 8;
  do
  {
    v6 = &rgb[4 * (v4 & 2) * stride + 4 * ((8 * v4) & 8)];
    v7 = &YCbCr[16 * (v4 & 2) + 256 + 4 * (v4 & 1)];
    v8 = v5;
    v9 = 4;
    do
    {
      v10 = 0;
      v11 = v7 + 63;
      v12 = v8 - 1;
      for ( i = 4; i != 0; --i )
      {
        v14 = v6[v10];
        v15 = v6[v10 + 2];
        v16 = v6[v10 + 1];
        v17 = 19595 * v14 + 7471 * v15 + 38470 * v16 + 0x8000;
        v18 = (((v15 + 1) << 15) - 21709 * v16 - 11059 * v14) >> 16;
        v19 = (((v14 + 1) << 15) - 27439 * v16 - 5329 * v15) >> 16;
        v20 = &v6[stride];
        *(v12 - 7) = HIWORD(v17) - 128;
        v21 = v6[v10 + 5];
        v22 = v6[v10 + 4];
        v23 = v6[v10 + 6];
        v24 = ((v22 + 1) << 15) - 27439 * v21 - 5329 * v23;
        v25 = ((((v23 + 1) << 15) - 21709 * v21 - 11059 * v22) >> 16) + v18;
        *(v12 - 6) = ((unsigned int)(19595 * v22 + 7471 * v23 + 38470 * v21 + 0x8000) >> 16) - 128;
        v26 = v20[v10];
        v27 = v20[v10 + 1];
        v28 = v20[v10 + 2];
        v29 = ((((v28 + 1) << 15) - 21709 * v27 - 11059 * v26) >> 16) + v25;
        v30 = ((((v26 + 1) << 15) - 27439 * v27 - 5329 * v28) >> 16) + (v24 >> 16) + v19;
        LOWORD(v28) = ((unsigned int)(19595 * v26 + 7471 * v28 + 38470 * v27 + 0x8000) >> 16) - 128;
        v6 = &v20[-stride];
        v12[1] = v28;
        v31 = v20[v10 + 4];
        v32 = v20[v10 + 5];
        v33 = v20[v10 + 6];
        v10 += 8;
        v12 += 2;
        *v12 = ((unsigned int)(19595 * v31 + 7471 * v33 + 38470 * v32 + 0x8000) >> 16) - 128;
        *(v11 - 63) = (((((v33 + 1) << 15) - 21709 * v32 - 11059 * v31) >> 16) + v29) >> 2;
        *++v11 = (((((v31 + 1) << 15) - 27439 * v32 - 5329 * v33) >> 16) + v30) >> 2;
      }
      --v9;
      v8 += 16;
      v7 += 8;
      v6 += 2 * stride;
    }
    while ( v9 != 0 );
    ++v4;
    v5 = v8;
  }
  while ( v4 < 4 );
}


// ========================================================================
// ?YCoCgTo420Tile@idBareDctEncoder@@AAAXPBEPAFH@Z
// EA  : 0x828E7AD0
// RVA : 0x008E7AD0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

void __fastcall idBareDctEncoder::YCoCgTo420Tile(
        idBareDctEncoder *this,
        const unsigned __int8 *YCoCg,
        __int16 *YCoCgTile,
        int stride)
{
  int v4; // r27
  __int16 *v5; // r26
  __int16 *v6; // r11
  const unsigned __int8 *v7; // r10
  __int16 *v8; // r9
  int i; // ctr
  int v10; // r7
  int v11; // r31
  int v12; // r8
  int v13; // r7
  unsigned __int8 *v14; // r10
  int v15; // r7
  unsigned __int8 *v16; // r8
  int v17; // r3
  int v18; // r30
  __int16 v19; // r29
  int v20; // r10
  unsigned __int8 *v21; // r10
  int v22; // r29
  unsigned __int8 *v23; // r7
  int v24; // r31
  __int16 v25; // r25
  int v26; // r3
  int v27; // r8
  int v28; // r3
  int v29; // r30
  int v30; // r31
  int v31; // r8
  int v32; // r30
  int v33; // r10
  int v34; // r30
  int v35; // r3
  unsigned __int8 *v36; // r10
  int v37; // r8
  int v38; // r7
  int v39; // r3
  int v40; // r7
  int v41; // r3
  int v42; // r7
  int v43; // r29
  int v44; // r30
  int v45; // r31
  int v46; // r7
  int v47; // r7
  int v48; // r8
  int v49; // r30
  int v50; // r8

  v4 = 0;
  v5 = YCoCgTile;
  do
  {
    v6 = v5 - 1;
    v7 = &YCoCg[4 * (v4 & 2) * stride + 4 * ((8 * v4) & 8)];
    v8 = &YCoCgTile[4 * ((4 * v4) & 8) + 315 + 4 * (v4 & 1)];
    for ( i = 4; i != 0; --i )
    {
      v10 = *v7;
      v11 = v7[1];
      v6[1] = v7[3] - 128;
      v12 = v7[5];
      v13 = v7[4] + v10;
      v6[2] = v7[7] - 128;
      v14 = (unsigned __int8 *)&v7[stride];
      v15 = *v14 + v13;
      v17 = v14[1] + v12 + v11;
      v16 = &v14[-stride];
      v6[9] = v14[3] - 128;
      v18 = v14[5];
      v19 = v14[7] - 128;
      v20 = v14[4] + v15;
      v6[10] = v19;
      *(v8 - 59) = v20 >> 2;
      v21 = &v16[stride];
      v8[5] = (v18 + v17) >> 2;
      v22 = v16[9];
      v23 = v16;
      v24 = v16[8];
      v6[3] = v16[11] - 128;
      v25 = v16[15] - 128;
      v26 = v16[13];
      v27 = v16[12] + v24;
      v6[4] = v25;
      v28 = v26 + v22;
      v29 = v21[8];
      v30 = v21[9];
      v6[11] = v21[11] - 128;
      LOWORD(v22) = v21[15] - 128;
      v31 = v29 + v27;
      v32 = v21[13];
      v33 = v21[12] + v31;
      v6[12] = v22;
      *(v8 - 58) = v33 >> 2;
      v8[6] = (v32 + v30 + v28) >> 2;
      v34 = v23[17];
      v35 = v23[16];
      v6[5] = v23[19] - 128;
      v36 = &v23[stride];
      LOWORD(v22) = v23[23] - 128;
      v37 = v23[21];
      v38 = v23[20] + v35;
      v6[6] = v22;
      v39 = v36[17] + v37 + v34;
      v40 = v36[16] + v38;
      v6[13] = v36[19] - 128;
      v41 = v36[21] + v39;
      v42 = (v36[20] + v40) >> 2;
      v6[14] = v36[23] - 128;
      *(v8 - 57) = v42;
      v8[7] = v41 >> 2;
      v43 = v36[-stride + 24];
      v44 = v36[-stride + 25];
      v6[7] = v36[-stride + 27] - 128;
      v45 = v36[-stride + 28];
      v46 = v36[-stride + 29] + v44;
      v6[8] = v36[-stride + 31] - 128;
      v47 = v36[25] + v46;
      v48 = v36[24] + v45 + v43;
      v6[15] = v36[27] - 128;
      v49 = (v36[28] + v48) >> 2;
      v50 = v36[29] + v47;
      v6 += 16;
      *v6 = v36[31] - 128;
      v7 = &v36[2 * stride - stride];
      *(v8 - 56) = v49;
      v8 += 8;
      *v8 = v50 >> 2;
    }
    ++v4;
    v5 += 64;
  }
  while ( v4 < 4 );
}


// ========================================================================
// ?YCoCgTo444Tile@idBareDctEncoder@@AAAXPBEPAFH@Z
// EA  : 0x828E7D48
// RVA : 0x008E7D48
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

void __fastcall idBareDctEncoder::YCoCgTo444Tile(
        idBareDctEncoder *this,
        const unsigned __int8 *YCoCg,
        __int16 *YCoCgTile,
        int stride)
{
  int v4; // r31
  __int16 *v5; // r9
  __int16 *v6; // r5
  int v7; // r3
  const unsigned __int8 *v8; // r8
  int v9; // r9
  __int16 *v10; // r11
  int i; // ctr
  const unsigned __int8 *v12; // r8
  __int16 v13; // r7
  unsigned __int8 *v14; // r10
  __int16 v15; // r7

  v4 = 0;
  v5 = YCoCgTile + 512;
  do
  {
    v6 = v5;
    v7 = 4;
    v8 = &YCoCg[4 * (v4 & 2) * stride + 4 * ((8 * v4) & 8)];
    do
    {
      v9 = 0;
      v10 = v6 - 505;
      for ( i = 4; i != 0; --i )
      {
        v10[249] = v8[v9];
        v10[505] = v8[v9 + 1];
        *(v10 - 7) = v8[v9 + 3] - 128;
        v10[250] = v8[v9 + 4];
        v10[506] = v8[v9 + 5];
        v13 = v8[v9 + 7];
        v12 = &v8[stride];
        v14 = (unsigned __int8 *)&v12[v9];
        *(v10 - 6) = v13 - 128;
        v15 = v12[v9];
        v8 = &v12[-stride];
        v9 += 8;
        v10[257] = v15;
        v10[513] = v14[1];
        v10[1] = v14[3] - 128;
        v10[258] = v14[4];
        v10[514] = v14[5];
        v10 += 2;
        *v10 = v14[7] - 128;
      }
      --v7;
      v6 += 16;
      v8 += 2 * stride;
    }
    while ( v7 != 0 );
    ++v4;
    v5 = v6;
  }
  while ( v4 < 4 );
}


// ========================================================================
// ?NormalMapToTile@idBareDctEncoder@@AAAXPBEPAFH@Z
// EA  : 0x828E7E48
// RVA : 0x008E7E48
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

void __fastcall idBareDctEncoder::NormalMapToTile(
        idBareDctEncoder *this,
        const unsigned __int8 *normalMap,
        __int16 *ms,
        int stride)
{
  const unsigned __int8 *v4; // r11
  __int16 *v5; // r10
  int i; // ctr
  __int16 v7; // r9

  v4 = normalMap + 3;
  v5 = ms + 63;
  for ( i = 8; i != 0; --i )
  {
    *(v5 - 63) = *(v4 - 2) - 128;
    v5[1] = *v4 - 128;
    *(v5 - 62) = v4[2] - 128;
    v5[2] = v4[4] - 128;
    *(v5 - 61) = v4[6] - 128;
    v5[3] = v4[8] - 128;
    *(v5 - 60) = v4[10] - 128;
    v5[4] = v4[12] - 128;
    *(v5 - 59) = v4[14] - 128;
    v5[5] = v4[16] - 128;
    *(v5 - 58) = v4[18] - 128;
    v5[6] = v4[20] - 128;
    *(v5 - 57) = v4[22] - 128;
    v5[7] = v4[24] - 128;
    *(v5 - 56) = v4[26] - 128;
    v7 = v4[28] - 128;
    v4 += stride;
    v5 += 8;
    *v5 = v7;
  }
}


// ========================================================================
// ?EmitBits@idBareDctEncoder@@AAA_NPAEIH@Z
// EA  : 0x828E7F30
// RVA : 0x008E7F30
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

int __fastcall idBareDctEncoder::EmitBits(idBareDctEncoder *this, unsigned __int8 *out, unsigned int code, int size)
{
  int v5; // r7
  unsigned int v6; // r8
  unsigned __int8 *v7; // r10
  unsigned int v8; // ctr

  if ( size == 0 )
    return 0;
  v5 = this->bitCnt + size;
  v6 = ((((1 << size) - 1) & code) << (24 - v5)) | this->bitBuff;
  if ( v5 >= 8 )
  {
    v7 = out - 1;
    v8 = (unsigned int)v5 >> 3;
    v5 -= v5 & 0xFFFFFFF8;
    do
    {
      *++v7 = BYTE1(v6);
      if ( this->useMarkers && *v7 == 255 )
      {
        *++v7 = 0;
        ++this->dataBytes;
      }
      v6 <<= 8;
      ++this->dataBytes;
      --v8;
    }
    while ( v8 != 0 );
  }
  this->bitBuff = v6;
  this->bitCnt = v5;
  return 1;
}


// ========================================================================
// ??0idBareDctEncoder@@QAA@XZ
// EA  : 0x828E7FF0
// RVA : 0x008E7FF0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

idBareDctEncoder *__fastcall idBareDctEncoder::idBareDctEncoder(idBareDctEncoder *this)
{
  idBareDctBase::idBareDctBase(this);
  idBareDCTHuffmanTable::idBareDCTHuffmanTable(this: &this->huffTableYDC, huffmanType: HUFFMAN_TYPE_Y_DC, encode: true);
  idBareDCTHuffmanTable::idBareDCTHuffmanTable(this: &this->huffTableYAC, huffmanType: HUFFMAN_TYPE_Y_AC, encode: true);
  idBareDCTHuffmanTable::idBareDCTHuffmanTable(
    this: &this->huffTableCoCgDC,
    huffmanType: HUFFMAN_TYPE_COCG_DC,
    encode: true);
  idBareDCTHuffmanTable::idBareDCTHuffmanTable(
    this: &this->huffTableCoCgAC,
    huffmanType: HUFFMAN_TYPE_COCG_AC,
    encode: true);
  idBareDCTHuffmanTable::idBareDCTHuffmanTable(this: &this->huffTableADC, huffmanType: HUFFMAN_TYPE_Y_DC, encode: true);
  idBareDCTHuffmanTable::idBareDCTHuffmanTable(this: &this->huffTableAAC, huffmanType: HUFFMAN_TYPE_Y_AC, encode: true);
  this->imageWidth = 0;
  this->imageHeight = 0;
  this->bitCnt = 0;
  this->bitBuff = 0;
  this->dcA = 0;
  this->dcCg = 0;
  this->dcCo = 0;
  this->dcY = 0;
  this->dataBytes = 0;
  this->data = nullptr;
  this->useMarkers = false;
  idBareDctBase::InitQuantTable(this);
  return this;
}


// ========================================================================
// __unwind$71995
// EA  : 0x828E80C8
// RVA : 0x008E80C8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

void _unwind_71995()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 112 + 132));
}


// ========================================================================
// ?HuffmanEncode@idBareDctEncoder@@AAA_NPBFABVidBareDCTHuffmanTable@@1PAH@Z
// EA  : 0x828E80F0
// RVA : 0x008E80F0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

int __fastcall idBareDctEncoder::HuffmanEncode(
        idBareDctEncoder *this,
        const __int16 *coef,
        const idBareDCTHuffmanTable *dctbl,
        const idBareDCTHuffmanTable *actbl,
        int *lastDC)
{
  int v7; // r9
  signed int v9; // r29
  int v10; // r11
  int i; // r30
  int result; // r3
  int v13; // r29
  const int *v14; // r26
  __int16 v15; // r9
  int v16; // r30
  unsigned int v17; // r27
  int v18; // r11
  int v19; // r30
  bool v20; // zf

  v7 = *coef;
  v9 = v7 - *lastDC;
  *lastDC = v7;
  v10 = v9;
  if ( v9 < 0 )
    v10 = -v9--;
  for ( i = 0; v10 != 0; ++i )
    v10 >>= 1;
  if ( (unsigned __int8)idBareDctEncoder::EmitBits(
                          this,
                          out: &this->data[this->dataBytes],
                          code: dctbl->code[i],
                          size: dctbl->size[i]) != 0
    && (i == 0
     || (unsigned __int8)idBareDctEncoder::EmitBits(this, out: &this->data[this->dataBytes], code: v9, size: i) != 0) )
  {
    v13 = 0;
    v14 = &dct_natural_order_1[1];
    while ( 1 )
    {
      v15 = coef[*v14];
      v16 = v15;
      if ( v15 != 0 )
      {
        if ( v13 > 15 )
        {
          while ( (unsigned __int8)idBareDctEncoder::EmitBits(
                                     this,
                                     out: &this->data[this->dataBytes],
                                     code: actbl->code[240],
                                     size: actbl->size[240]) != 0 )
          {
            v13 -= 16;
            if ( v13 <= 15 )
              goto LABEL_15;
          }
          return 0;
        }
LABEL_15:
        v17 = v16;
        if ( v16 < 0 )
        {
          v16 = -v16;
          --v17;
        }
        v18 = v16 >> 1;
        v20 = v16 >> 1 == 0;
        v19 = 1;
        if ( !v20 )
        {
          do
          {
            v18 >>= 1;
            ++v19;
          }
          while ( v18 != 0 );
        }
        if ( (unsigned __int8)idBareDctEncoder::EmitBits(
                                this,
                                out: &this->data[this->dataBytes],
                                code: actbl->code[16 * v13 + v19],
                                size: actbl->size[16 * v13 + v19]) == 0
          || (unsigned __int8)idBareDctEncoder::EmitBits(this, out: &this->data[this->dataBytes], code: v17, size: v19) == 0 )
        {
          return 0;
        }
        v13 = 0;
      }
      else
      {
        ++v13;
      }
      if ( (int)++v14 >= (int)&dct_natural_order_1[64] )
      {
        if ( v13 <= 0 )
          return 1;
        v20 = (unsigned __int8)idBareDctEncoder::EmitBits(
                                 this,
                                 out: &this->data[this->dataBytes],
                                 code: actbl->code[0],
                                 size: actbl->size[0]) == 0;
        result = 0;
        if ( !v20 )
          return 1;
        return result;
      }
    }
  }
  return 0;
}


// ========================================================================
// ?CompressOneTileMono@idBareDctEncoder@@AAAXPBEH@Z
// EA  : 0x828E8310
// RVA : 0x008E8310
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

void __fastcall idBareDctEncoder::CompressOneTileMono(idBareDctEncoder *this, const unsigned __int8 *mono, int stride)
{
  int v5; // r6
  int v6; // r6
  const unsigned __int8 *v7; // r30
  int v8; // r6
  __int16 v9[64]; // [sp+50h] [-230h] BYREF
  __int16 v10[64]; // [sp+D0h] [-1B0h] BYREF
  __int16 v11[64]; // [sp+150h] [-130h] BYREF
  __int16 v12[88]; // [sp+1D0h] [-B0h] BYREF

  idBareDctEncoder::MonoToTile(this, mono, ms: v9, stride);
  idBareDctEncoder::MonoToTile(this, mono: mono + 8, ms: v10, stride: v5);
  v7 = &mono[8 * v6];
  idBareDctEncoder::MonoToTile(this, mono: v7, ms: v11, stride: v6);
  idBareDctEncoder::MonoToTile(this, mono: v7 + 8, ms: v12, stride: v8);
  FDCT_AP922_float(src: v9, quant: this->quantTableY, coeff: v9);
  FDCT_AP922_float(src: v10, quant: this->quantTableY, coeff: v10);
  FDCT_AP922_float(src: v11, quant: this->quantTableY, coeff: v11);
  FDCT_AP922_float(src: v12, quant: this->quantTableY, coeff: v12);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v9,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcY);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v10,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcY);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v11,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcY);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v12,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcY);
}


// ========================================================================
// ?CompressOneTileGrayScale@idBareDctEncoder@@AAAXPBEH@Z
// EA  : 0x828E8428
// RVA : 0x008E8428
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

void __fastcall idBareDctEncoder::CompressOneTileGrayScale(
        idBareDctEncoder *this,
        const unsigned __int8 *gray,
        int stride)
{
  int v5; // r6
  int v6; // r6
  int v7; // r6
  __int16 v8[64]; // [sp+50h] [-230h] BYREF
  __int16 v9[64]; // [sp+D0h] [-1B0h] BYREF
  __int16 v10[64]; // [sp+150h] [-130h] BYREF
  __int16 v11[88]; // [sp+1D0h] [-B0h] BYREF

  idBareDctEncoder::RGBToGrayScaleTile(this, rgb: gray, ms: v8, stride);
  idBareDctEncoder::RGBToGrayScaleTile(this, rgb: gray + 32, ms: v9, stride: v5);
  idBareDctEncoder::RGBToGrayScaleTile(this, rgb: &gray[8 * v6], ms: v10, stride: v6);
  idBareDctEncoder::RGBToGrayScaleTile(this, rgb: &gray[8 * v7 + 32], ms: v11, stride: v7);
  FDCT_AP922_float(src: v8, quant: this->quantTableY, coeff: v8);
  FDCT_AP922_float(src: v9, quant: this->quantTableY, coeff: v9);
  FDCT_AP922_float(src: v10, quant: this->quantTableY, coeff: v10);
  FDCT_AP922_float(src: v11, quant: this->quantTableY, coeff: v11);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v8,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcY);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v9,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcY);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v10,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcY);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v11,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcY);
}


// ========================================================================
// ?CompressOneTileRGB@idBareDctEncoder@@AAAXPBEH@Z
// EA  : 0x828E8540
// RVA : 0x008E8540
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

void __fastcall idBareDctEncoder::CompressOneTileRGB(idBareDctEncoder *this, const unsigned __int8 *rgb, int stride)
{
  __int16 v4[64]; // [sp+50h] [-330h] BYREF
  __int16 v5[64]; // [sp+D0h] [-2B0h] BYREF
  __int16 v6[64]; // [sp+150h] [-230h] BYREF
  __int16 v7[64]; // [sp+1D0h] [-1B0h] BYREF
  __int16 v8[64]; // [sp+250h] [-130h] BYREF
  __int16 v9[88]; // [sp+2D0h] [-B0h] BYREF

  idBareDctEncoder::RGBToYCoCgTile(this, rgb, YCoCg: v4, stride);
  FDCT_AP922_float(src: v4, quant: this->quantTableY, coeff: v4);
  FDCT_AP922_float(src: v5, quant: this->quantTableY, coeff: v5);
  FDCT_AP922_float(src: v6, quant: this->quantTableY, coeff: v6);
  FDCT_AP922_float(src: v7, quant: this->quantTableY, coeff: v7);
  FDCT_AP922_float(src: v8, quant: this->quantTableCoCg, coeff: v8);
  FDCT_AP922_float(src: v9, quant: this->quantTableCoCg, coeff: v9);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v4,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcY);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v5,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcY);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v6,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcY);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v7,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcY);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v8,
    dctbl: &this->huffTableCoCgDC,
    actbl: &this->huffTableCoCgAC,
    lastDC: &this->dcCo);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v9,
    dctbl: &this->huffTableCoCgDC,
    actbl: &this->huffTableCoCgAC,
    lastDC: &this->dcCg);
}


// ========================================================================
// ?CompressOneTileYCoCg@idBareDctEncoder@@AAAXPBEH@Z
// EA  : 0x828E8670
// RVA : 0x008E8670
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

void __fastcall idBareDctEncoder::CompressOneTileYCoCg(
        idBareDctEncoder *this,
        const unsigned __int8 *YCoCg,
        int stride)
{
  idBareDCTHuffmanTable *p_huffTableCoCgAC; // r30
  idBareDCTHuffmanTable *p_huffTableCoCgDC; // r29
  int *p_dcCg; // r7
  const __int16 *v7; // r4
  __int16 v8[64]; // [sp+50h] [-630h] BYREF
  __int16 v9[64]; // [sp+D0h] [-5B0h] BYREF
  __int16 v10[64]; // [sp+150h] [-530h] BYREF
  __int16 v11[64]; // [sp+1D0h] [-4B0h] BYREF
  __int16 v12[64]; // [sp+250h] [-430h] BYREF
  __int16 v13[64]; // [sp+2D0h] [-3B0h] BYREF
  __int16 v14[64]; // [sp+350h] [-330h] BYREF
  __int16 v15[64]; // [sp+3D0h] [-2B0h] BYREF
  __int16 v16[64]; // [sp+450h] [-230h] BYREF
  __int16 v17[64]; // [sp+4D0h] [-1B0h] BYREF
  __int16 v18[64]; // [sp+550h] [-130h] BYREF
  __int16 v19[88]; // [sp+5D0h] [-B0h] BYREF

  if ( this->sampleMode == SAMPLE_420 )
  {
    idBareDctEncoder::YCoCgTo420Tile(this, YCoCg, YCoCgTile: v8, stride);
    FDCT_AP922_float(src: v8, quant: this->quantTableY, coeff: v8);
    FDCT_AP922_float(src: v9, quant: this->quantTableY, coeff: v9);
    FDCT_AP922_float(src: v10, quant: this->quantTableY, coeff: v10);
    FDCT_AP922_float(src: v11, quant: this->quantTableY, coeff: v11);
    FDCT_AP922_float(src: v12, quant: this->quantTableCoCg, coeff: v12);
    FDCT_AP922_float(src: v13, quant: this->quantTableCoCg, coeff: v13);
    idBareDctEncoder::HuffmanEncode(
      this,
      coef: v8,
      dctbl: &this->huffTableYDC,
      actbl: &this->huffTableYAC,
      lastDC: &this->dcY);
    idBareDctEncoder::HuffmanEncode(
      this,
      coef: v9,
      dctbl: &this->huffTableYDC,
      actbl: &this->huffTableYAC,
      lastDC: &this->dcY);
    idBareDctEncoder::HuffmanEncode(
      this,
      coef: v10,
      dctbl: &this->huffTableYDC,
      actbl: &this->huffTableYAC,
      lastDC: &this->dcY);
    idBareDctEncoder::HuffmanEncode(
      this,
      coef: v11,
      dctbl: &this->huffTableYDC,
      actbl: &this->huffTableYAC,
      lastDC: &this->dcY);
    p_huffTableCoCgAC = &this->huffTableCoCgAC;
    p_huffTableCoCgDC = &this->huffTableCoCgDC;
    idBareDctEncoder::HuffmanEncode(
      this,
      coef: v12,
      dctbl: &this->huffTableCoCgDC,
      actbl: &this->huffTableCoCgAC,
      lastDC: &this->dcCo);
    p_dcCg = &this->dcCg;
    v7 = v13;
  }
  else
  {
    idBareDctEncoder::YCoCgTo444Tile(this, YCoCg, YCoCgTile: v8, stride);
    FDCT_AP922_float(src: v8, quant: this->quantTableY, coeff: v8);
    FDCT_AP922_float(src: v9, quant: this->quantTableY, coeff: v9);
    FDCT_AP922_float(src: v10, quant: this->quantTableY, coeff: v10);
    FDCT_AP922_float(src: v11, quant: this->quantTableY, coeff: v11);
    FDCT_AP922_float(src: v12, quant: this->quantTableCoCg, coeff: v12);
    FDCT_AP922_float(src: v13, quant: this->quantTableCoCg, coeff: v13);
    FDCT_AP922_float(src: v14, quant: this->quantTableCoCg, coeff: v14);
    FDCT_AP922_float(src: v15, quant: this->quantTableCoCg, coeff: v15);
    FDCT_AP922_float(src: v16, quant: this->quantTableCoCg, coeff: v16);
    FDCT_AP922_float(src: v17, quant: this->quantTableCoCg, coeff: v17);
    FDCT_AP922_float(src: v18, quant: this->quantTableCoCg, coeff: v18);
    FDCT_AP922_float(src: v19, quant: this->quantTableCoCg, coeff: v19);
    idBareDctEncoder::HuffmanEncode(
      this,
      coef: v8,
      dctbl: &this->huffTableYDC,
      actbl: &this->huffTableYAC,
      lastDC: &this->dcY);
    idBareDctEncoder::HuffmanEncode(
      this,
      coef: v9,
      dctbl: &this->huffTableYDC,
      actbl: &this->huffTableYAC,
      lastDC: &this->dcY);
    idBareDctEncoder::HuffmanEncode(
      this,
      coef: v10,
      dctbl: &this->huffTableYDC,
      actbl: &this->huffTableYAC,
      lastDC: &this->dcY);
    idBareDctEncoder::HuffmanEncode(
      this,
      coef: v11,
      dctbl: &this->huffTableYDC,
      actbl: &this->huffTableYAC,
      lastDC: &this->dcY);
    p_huffTableCoCgAC = &this->huffTableCoCgAC;
    p_huffTableCoCgDC = &this->huffTableCoCgDC;
    idBareDctEncoder::HuffmanEncode(
      this,
      coef: v12,
      dctbl: &this->huffTableCoCgDC,
      actbl: &this->huffTableCoCgAC,
      lastDC: &this->dcCo);
    idBareDctEncoder::HuffmanEncode(
      this,
      coef: v13,
      dctbl: &this->huffTableCoCgDC,
      actbl: &this->huffTableCoCgAC,
      lastDC: &this->dcCo);
    idBareDctEncoder::HuffmanEncode(
      this,
      coef: v14,
      dctbl: &this->huffTableCoCgDC,
      actbl: &this->huffTableCoCgAC,
      lastDC: &this->dcCo);
    idBareDctEncoder::HuffmanEncode(
      this,
      coef: v15,
      dctbl: &this->huffTableCoCgDC,
      actbl: &this->huffTableCoCgAC,
      lastDC: &this->dcCo);
    idBareDctEncoder::HuffmanEncode(
      this,
      coef: v16,
      dctbl: &this->huffTableCoCgDC,
      actbl: &this->huffTableCoCgAC,
      lastDC: &this->dcCg);
    idBareDctEncoder::HuffmanEncode(
      this,
      coef: v17,
      dctbl: &this->huffTableCoCgDC,
      actbl: &this->huffTableCoCgAC,
      lastDC: &this->dcCg);
    idBareDctEncoder::HuffmanEncode(
      this,
      coef: v18,
      dctbl: &this->huffTableCoCgDC,
      actbl: &this->huffTableCoCgAC,
      lastDC: &this->dcCg);
    p_dcCg = &this->dcCg;
    v7 = v19;
  }
  idBareDctEncoder::HuffmanEncode(this, coef: v7, dctbl: p_huffTableCoCgDC, actbl: p_huffTableCoCgAC, lastDC: p_dcCg);
}


// ========================================================================
// ?CompressOneTileNormalMap@idBareDctEncoder@@AAAXPBEH@Z
// EA  : 0x828E89A8
// RVA : 0x008E89A8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

void __fastcall idBareDctEncoder::CompressOneTileNormalMap(
        idBareDctEncoder *this,
        const unsigned __int8 *normalMap,
        int stride)
{
  int v5; // r6
  int v6; // r6
  int v7; // r6
  __int16 v8[64]; // [sp+50h] [-430h] BYREF
  __int16 v9[64]; // [sp+D0h] [-3B0h] BYREF
  __int16 v10[64]; // [sp+150h] [-330h] BYREF
  __int16 v11[64]; // [sp+1D0h] [-2B0h] BYREF
  __int16 v12[64]; // [sp+250h] [-230h] BYREF
  __int16 v13[64]; // [sp+2D0h] [-1B0h] BYREF
  __int16 v14[64]; // [sp+350h] [-130h] BYREF
  __int16 v15[88]; // [sp+3D0h] [-B0h] BYREF

  idBareDctEncoder::NormalMapToTile(this, normalMap, ms: v8, stride);
  idBareDctEncoder::NormalMapToTile(this, normalMap: normalMap + 32, ms: v10, stride: v5);
  idBareDctEncoder::NormalMapToTile(this, normalMap: &normalMap[8 * v6], ms: v12, stride: v6);
  idBareDctEncoder::NormalMapToTile(this, normalMap: &normalMap[8 * v7 + 32], ms: v14, stride: v7);
  FDCT_AP922_float(src: v8, quant: this->quantTableY, coeff: v8);
  FDCT_AP922_float(src: v9, quant: this->quantTableY, coeff: v9);
  FDCT_AP922_float(src: v10, quant: this->quantTableY, coeff: v10);
  FDCT_AP922_float(src: v11, quant: this->quantTableY, coeff: v11);
  FDCT_AP922_float(src: v12, quant: this->quantTableY, coeff: v12);
  FDCT_AP922_float(src: v13, quant: this->quantTableY, coeff: v13);
  FDCT_AP922_float(src: v14, quant: this->quantTableY, coeff: v14);
  FDCT_AP922_float(src: v15, quant: this->quantTableY, coeff: v15);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v8,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcY);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v10,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcY);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v12,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcY);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v14,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcY);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v9,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcA);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v11,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcA);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v13,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcA);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v15,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcA);
}


// ========================================================================
// ?CompressOneTileJPEG@idBareDctEncoder@@AAAXPBEH@Z
// EA  : 0x828E8B60
// RVA : 0x008E8B60
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

void __fastcall idBareDctEncoder::CompressOneTileJPEG(idBareDctEncoder *this, const unsigned __int8 *rgb, int stride)
{
  __int16 v4[64]; // [sp+50h] [-330h] BYREF
  __int16 v5[64]; // [sp+D0h] [-2B0h] BYREF
  __int16 v6[64]; // [sp+150h] [-230h] BYREF
  __int16 v7[64]; // [sp+1D0h] [-1B0h] BYREF
  __int16 v8[64]; // [sp+250h] [-130h] BYREF
  __int16 v9[88]; // [sp+2D0h] [-B0h] BYREF

  idBareDctEncoder::RGBToYCbCrTile(this, rgb, YCbCr: v4, stride);
  FDCT_AP922_float(src: v4, quant: this->quantTableY, coeff: v4);
  FDCT_AP922_float(src: v5, quant: this->quantTableY, coeff: v5);
  FDCT_AP922_float(src: v6, quant: this->quantTableY, coeff: v6);
  FDCT_AP922_float(src: v7, quant: this->quantTableY, coeff: v7);
  FDCT_AP922_float(src: v8, quant: this->quantTableCoCg, coeff: v8);
  FDCT_AP922_float(src: v9, quant: this->quantTableCoCg, coeff: v9);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v4,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcY);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v5,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcY);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v6,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcY);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v7,
    dctbl: &this->huffTableYDC,
    actbl: &this->huffTableYAC,
    lastDC: &this->dcY);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v8,
    dctbl: &this->huffTableCoCgDC,
    actbl: &this->huffTableCoCgAC,
    lastDC: &this->dcCo);
  idBareDctEncoder::HuffmanEncode(
    this,
    coef: v9,
    dctbl: &this->huffTableCoCgDC,
    actbl: &this->huffTableCoCgAC,
    lastDC: &this->dcCg);
}


// ========================================================================
// ?CompressImageMono_Generic@idBareDctEncoder@@AAA_NPBEPAEHHAAH@Z
// EA  : 0x828E8C90
// RVA : 0x008E8C90
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

int __fastcall idBareDctEncoder::CompressImageMono_Generic(
        idBareDctEncoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height,
        int *outputBytes)
{
  int v6; // r18
  int v12; // r16
  int i; // r17
  int v14; // r22
  int v15; // r24
  int v16; // r10
  int v17; // r27
  signed int v18; // r30
  int v19; // r28
  unsigned __int8 *v20; // r31
  const unsigned __int8 *v21; // r29
  int v22; // r9
  unsigned __int8 v23; // r11
  int v24; // ctr
  int v25; // r7
  unsigned __int8 v27[400]; // [sp+50h] [-190h] BYREF

  this->imageWidth = width;
  this->imageHeight = height;
  this->data = outBuf;
  v6 = (width + 15) >> 4;
  this->dataBytes = 0;
  this->bitCnt = 0;
  this->bitBuff = 0;
  this->dcA = 0;
  this->dcCg = 0;
  this->dcCo = 0;
  this->dcY = 0;
  v12 = (height + 15) >> 4;
  *outputBytes = 0;
  for ( i = 0; i < v12; ++i )
  {
    v14 = 0;
    if ( v6 > 0 )
    {
      v15 = 16 * i;
      do
      {
        v16 = 16 * v14;
        v17 = 16;
        v18 = 16;
        if ( 16 * i + 16 > height )
          v17 = height - v15;
        if ( v16 + 16 > width )
          v18 = width - v16;
        v19 = 0;
        v20 = v27;
        v21 = &inBuf[(v15 - 1) * width + v16];
        do
        {
          if ( v19 >= v17 )
          {
            *(_OWORD *)v20 = *(_OWORD *)&v27[16 * v17 - 16];
          }
          else
          {
            v21 += width;
            memcpy(Dst: v20, Src: v21, Size: v18);
            if ( v18 < 16 )
            {
              v22 = (int)&v20[v18 - 1];
              v23 = v21[v18 - 1];
              v24 = 16 - v18;
              do
              {
                *(_BYTE *)++v22 = v23;
                --v24;
              }
              while ( v24 != 0 );
            }
          }
          ++v19;
          v20 += 16;
        }
        while ( v19 < 16 );
        idBareDctEncoder::CompressOneTileMono(this, mono: v27, stride: 16);
        ++v14;
      }
      while ( v14 < v6 );
    }
  }
  if ( this->bitCnt > 0 )
  {
    this->data[this->dataBytes] = HIWORD(this->bitBuff);
    v25 = this->dataBytes + 1;
    this->bitBuff = 0;
    this->bitCnt = 0;
    this->dataBytes = v25;
  }
  *outputBytes = this->dataBytes;
  return 1;
}


// ========================================================================
// ?CompressImageGrayScale_Generic@idBareDctEncoder@@AAA_NPBEPAEHHAAH@Z
// EA  : 0x828E8E30
// RVA : 0x008E8E30
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

int __fastcall idBareDctEncoder::CompressImageGrayScale_Generic(
        idBareDctEncoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height,
        int *outputBytes)
{
  int v6; // r15
  int v7; // r11
  int v12; // r24
  int v13; // r14
  int v14; // r19
  int v15; // r23
  int v16; // r11
  int v17; // r25
  int v18; // r28
  const unsigned __int8 *v19; // r31
  int v20; // r26
  unsigned __int8 *v21; // r29
  unsigned __int8 *v22; // r27
  const unsigned __int8 *v23; // r10
  unsigned __int8 *v24; // r11
  int v25; // r9
  unsigned __int8 v26; // r7
  unsigned __int8 v27; // r6
  unsigned __int8 v28; // r5
  int v29; // r6
  int i; // [sp+50h] [-4B0h]
  unsigned __int8 v32[1184]; // [sp+60h] [-4A0h] BYREF
  int *v33; // [sp+53Ch] [+3Ch]

  this->imageWidth = width;
  this->imageHeight = height;
  this->data = outBuf;
  v6 = (width + 15) >> 4;
  v33 = outputBytes;
  v7 = (height + 15) >> 4;
  this->dataBytes = 0;
  this->bitCnt = 0;
  this->bitBuff = 0;
  this->dcA = 0;
  this->dcCg = 0;
  this->dcCo = 0;
  v12 = 4 * width;
  this->dcY = 0;
  v13 = 0;
  *outputBytes = 0;
  for ( i = v7; v13 < v7; ++v13 )
  {
    v14 = 0;
    if ( v6 > 0 )
    {
      v15 = 16 * v13;
      do
      {
        v16 = 16 * v14;
        v17 = 16;
        v18 = 16;
        if ( 16 * v13 + 16 > height )
          v17 = height - v15;
        if ( v16 + 16 > width )
          v18 = width - v16;
        v19 = &inBuf[64 * v14 + (v15 - 1) * v12];
        v20 = 0;
        v21 = v32;
        v22 = &v32[4 * v18];
        do
        {
          if ( v20 >= v17 )
          {
            memcpy(Dst: v21, Src: &v32[64 * v17 - 64], Size: 0x40u);
          }
          else
          {
            v19 += v12;
            memcpy(Dst: v21, Src: v19, Size: 4 * v18);
            if ( v18 < 16 )
            {
              v23 = &v19[4 * v18];
              v24 = v22 - 4;
              v25 = 16 - v18;
              do
              {
                v24 += 4;
                v26 = *(v23 - 3);
                --v25;
                v27 = *(v23 - 2);
                v28 = *(v23 - 1);
                *v24 = *(v23 - 4);
                v24[1] = v26;
                v24[2] = v27;
                v24[3] = v28;
              }
              while ( v25 != 0 );
            }
          }
          ++v20;
          v22 += 64;
          v21 += 64;
        }
        while ( v20 < 16 );
        idBareDctEncoder::CompressOneTileGrayScale(this, gray: v32, stride: 64);
        ++v14;
      }
      while ( v14 < v6 );
      v7 = i;
      outputBytes = v33;
    }
  }
  if ( this->bitCnt > 0 )
  {
    this->data[this->dataBytes] = HIWORD(this->bitBuff);
    v29 = this->dataBytes + 1;
    this->bitBuff = 0;
    this->bitCnt = 0;
    this->dataBytes = v29;
  }
  *outputBytes = this->dataBytes;
  return 1;
}


// ========================================================================
// ?CompressImageRGB_Generic@idBareDctEncoder@@AAA_NPBEPAEHHAAH@Z
// EA  : 0x828E9008
// RVA : 0x008E9008
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

int __fastcall idBareDctEncoder::CompressImageRGB_Generic(
        idBareDctEncoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height,
        int *outputBytes)
{
  int v6; // r15
  int v7; // r11
  int v12; // r24
  int v13; // r14
  int v14; // r19
  int v15; // r23
  int v16; // r11
  int v17; // r25
  int v18; // r28
  const unsigned __int8 *v19; // r31
  int v20; // r26
  unsigned __int8 *v21; // r29
  unsigned __int8 *v22; // r27
  const unsigned __int8 *v23; // r10
  unsigned __int8 *v24; // r11
  int v25; // r9
  unsigned __int8 v26; // r7
  unsigned __int8 v27; // r6
  unsigned __int8 v28; // r5
  int v29; // r6
  int i; // [sp+50h] [-4B0h]
  unsigned __int8 v32[1184]; // [sp+60h] [-4A0h] BYREF
  int *v33; // [sp+53Ch] [+3Ch]

  this->imageWidth = width;
  this->imageHeight = height;
  this->data = outBuf;
  v6 = (width + 15) >> 4;
  v33 = outputBytes;
  v7 = (height + 15) >> 4;
  this->dataBytes = 0;
  this->bitCnt = 0;
  this->bitBuff = 0;
  this->dcA = 0;
  this->dcCg = 0;
  this->dcCo = 0;
  v12 = 4 * width;
  this->dcY = 0;
  v13 = 0;
  *outputBytes = 0;
  for ( i = v7; v13 < v7; ++v13 )
  {
    v14 = 0;
    if ( v6 > 0 )
    {
      v15 = 16 * v13;
      do
      {
        v16 = 16 * v14;
        v17 = 16;
        v18 = 16;
        if ( 16 * v13 + 16 > height )
          v17 = height - v15;
        if ( v16 + 16 > width )
          v18 = width - v16;
        v19 = &inBuf[64 * v14 + (v15 - 1) * v12];
        v20 = 0;
        v21 = v32;
        v22 = &v32[4 * v18];
        do
        {
          if ( v20 >= v17 )
          {
            memcpy(Dst: v21, Src: &v32[64 * v17 - 64], Size: 0x40u);
          }
          else
          {
            v19 += v12;
            memcpy(Dst: v21, Src: v19, Size: 4 * v18);
            if ( v18 < 16 )
            {
              v23 = &v19[4 * v18];
              v24 = v22 - 4;
              v25 = 16 - v18;
              do
              {
                v24 += 4;
                v26 = *(v23 - 3);
                --v25;
                v27 = *(v23 - 2);
                v28 = *(v23 - 1);
                *v24 = *(v23 - 4);
                v24[1] = v26;
                v24[2] = v27;
                v24[3] = v28;
              }
              while ( v25 != 0 );
            }
          }
          ++v20;
          v22 += 64;
          v21 += 64;
        }
        while ( v20 < 16 );
        idBareDctEncoder::CompressOneTileRGB(this, rgb: v32, stride: 64);
        ++v14;
      }
      while ( v14 < v6 );
      v7 = i;
      outputBytes = v33;
    }
  }
  if ( this->bitCnt > 0 )
  {
    this->data[this->dataBytes] = HIWORD(this->bitBuff);
    v29 = this->dataBytes + 1;
    this->bitBuff = 0;
    this->bitCnt = 0;
    this->dataBytes = v29;
  }
  *outputBytes = this->dataBytes;
  return 1;
}


// ========================================================================
// ?CompressImageYCoCg_Generic@idBareDctEncoder@@AAA_NPBEPAEHHAAH@Z
// EA  : 0x828E91E0
// RVA : 0x008E91E0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

int __fastcall idBareDctEncoder::CompressImageYCoCg_Generic(
        idBareDctEncoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height,
        int *outputBytes)
{
  int v6; // r15
  int v7; // r11
  int v12; // r24
  int v13; // r14
  int v14; // r19
  int v15; // r23
  int v16; // r11
  int v17; // r25
  int v18; // r28
  const unsigned __int8 *v19; // r31
  int v20; // r26
  unsigned __int8 *v21; // r29
  unsigned __int8 *v22; // r27
  const unsigned __int8 *v23; // r10
  unsigned __int8 *v24; // r11
  int v25; // r9
  unsigned __int8 v26; // r7
  unsigned __int8 v27; // r6
  unsigned __int8 v28; // r5
  int v29; // r6
  int i; // [sp+50h] [-4B0h]
  unsigned __int8 v32[1184]; // [sp+60h] [-4A0h] BYREF
  int *v33; // [sp+53Ch] [+3Ch]

  this->imageWidth = width;
  this->imageHeight = height;
  this->data = outBuf;
  v6 = (width + 15) >> 4;
  v33 = outputBytes;
  v7 = (height + 15) >> 4;
  this->dataBytes = 0;
  this->bitCnt = 0;
  this->bitBuff = 0;
  this->dcA = 0;
  this->dcCg = 0;
  this->dcCo = 0;
  v12 = 4 * width;
  this->dcY = 0;
  v13 = 0;
  *outputBytes = 0;
  for ( i = v7; v13 < v7; ++v13 )
  {
    v14 = 0;
    if ( v6 > 0 )
    {
      v15 = 16 * v13;
      do
      {
        v16 = 16 * v14;
        v17 = 16;
        v18 = 16;
        if ( 16 * v13 + 16 > height )
          v17 = height - v15;
        if ( v16 + 16 > width )
          v18 = width - v16;
        v19 = &inBuf[64 * v14 + (v15 - 1) * v12];
        v20 = 0;
        v21 = v32;
        v22 = &v32[4 * v18];
        do
        {
          if ( v20 >= v17 )
          {
            memcpy(Dst: v21, Src: &v32[64 * v17 - 64], Size: 0x40u);
          }
          else
          {
            v19 += v12;
            memcpy(Dst: v21, Src: v19, Size: 4 * v18);
            if ( v18 < 16 )
            {
              v23 = &v19[4 * v18];
              v24 = v22 - 4;
              v25 = 16 - v18;
              do
              {
                v24 += 4;
                v26 = *(v23 - 3);
                --v25;
                v27 = *(v23 - 2);
                v28 = *(v23 - 1);
                *v24 = *(v23 - 4);
                v24[1] = v26;
                v24[2] = v27;
                v24[3] = v28;
              }
              while ( v25 != 0 );
            }
          }
          ++v20;
          v22 += 64;
          v21 += 64;
        }
        while ( v20 < 16 );
        idBareDctEncoder::CompressOneTileYCoCg(this, YCoCg: v32, stride: 64);
        ++v14;
      }
      while ( v14 < v6 );
      v7 = i;
      outputBytes = v33;
    }
  }
  if ( this->bitCnt > 0 )
  {
    this->data[this->dataBytes] = HIWORD(this->bitBuff);
    v29 = this->dataBytes + 1;
    this->bitBuff = 0;
    this->bitCnt = 0;
    this->dataBytes = v29;
  }
  *outputBytes = this->dataBytes;
  return 1;
}


// ========================================================================
// ?CompressImageNormalMap_Generic@idBareDctEncoder@@AAA_NPBEPAEHHAAH@Z
// EA  : 0x828E93B8
// RVA : 0x008E93B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

int __fastcall idBareDctEncoder::CompressImageNormalMap_Generic(
        idBareDctEncoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height,
        int *outputBytes)
{
  int v6; // r15
  int v7; // r11
  int v12; // r24
  int v13; // r14
  int v14; // r19
  int v15; // r23
  int v16; // r11
  int v17; // r25
  int v18; // r28
  const unsigned __int8 *v19; // r31
  int v20; // r26
  unsigned __int8 *v21; // r29
  unsigned __int8 *v22; // r27
  const unsigned __int8 *v23; // r10
  unsigned __int8 *v24; // r11
  int v25; // r9
  unsigned __int8 v26; // r7
  unsigned __int8 v27; // r6
  unsigned __int8 v28; // r5
  int v29; // r6
  int i; // [sp+50h] [-4B0h]
  unsigned __int8 v32[1184]; // [sp+60h] [-4A0h] BYREF
  int *v33; // [sp+53Ch] [+3Ch]

  this->imageWidth = width;
  this->imageHeight = height;
  this->data = outBuf;
  v6 = (width + 15) >> 4;
  v33 = outputBytes;
  v7 = (height + 15) >> 4;
  this->dataBytes = 0;
  this->bitCnt = 0;
  this->bitBuff = 0;
  this->dcA = 0;
  this->dcCg = 0;
  this->dcCo = 0;
  v12 = 4 * width;
  this->dcY = 0;
  v13 = 0;
  *outputBytes = 0;
  for ( i = v7; v13 < v7; ++v13 )
  {
    v14 = 0;
    if ( v6 > 0 )
    {
      v15 = 16 * v13;
      do
      {
        v16 = 16 * v14;
        v17 = 16;
        v18 = 16;
        if ( 16 * v13 + 16 > height )
          v17 = height - v15;
        if ( v16 + 16 > width )
          v18 = width - v16;
        v19 = &inBuf[64 * v14 + (v15 - 1) * v12];
        v20 = 0;
        v21 = v32;
        v22 = &v32[4 * v18];
        do
        {
          if ( v20 >= v17 )
          {
            memcpy(Dst: v21, Src: &v32[64 * v17 - 64], Size: 0x40u);
          }
          else
          {
            v19 += v12;
            memcpy(Dst: v21, Src: v19, Size: 4 * v18);
            if ( v18 < 16 )
            {
              v23 = &v19[4 * v18];
              v24 = v22 - 4;
              v25 = 16 - v18;
              do
              {
                v24 += 4;
                v26 = *(v23 - 3);
                --v25;
                v27 = *(v23 - 2);
                v28 = *(v23 - 1);
                *v24 = *(v23 - 4);
                v24[1] = v26;
                v24[2] = v27;
                v24[3] = v28;
              }
              while ( v25 != 0 );
            }
          }
          ++v20;
          v22 += 64;
          v21 += 64;
        }
        while ( v20 < 16 );
        idBareDctEncoder::CompressOneTileNormalMap(this, normalMap: v32, stride: 64);
        ++v14;
      }
      while ( v14 < v6 );
      v7 = i;
      outputBytes = v33;
    }
  }
  if ( this->bitCnt > 0 )
  {
    this->data[this->dataBytes] = HIWORD(this->bitBuff);
    v29 = this->dataBytes + 1;
    this->bitBuff = 0;
    this->bitCnt = 0;
    this->dataBytes = v29;
  }
  *outputBytes = this->dataBytes;
  return 1;
}


// ========================================================================
// ?CompressImageRGB_JPEG@idBareDctEncoder@@QAA_NPBEPAEHHAAH_N@Z
// EA  : 0x828E9590
// RVA : 0x008E9590
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctencoder.cpp
// ========================================================================

int __fastcall idBareDctEncoder::CompressImageRGB_JPEG(
        idBareDctEncoder *this,
        const unsigned __int8 *inBuf,
        unsigned __int8 *outBuf,
        int width,
        int height,
        int *outputBytes,
        bool useMarkers_)
{
  int *v10; // r29
  unsigned __int8 *v11; // r11
  unsigned __int8 *v12; // r11
  unsigned __int8 *v13; // r11
  unsigned __int8 *v14; // r11
  unsigned __int8 *v15; // r11
  unsigned __int8 *v16; // r11
  unsigned __int8 *v17; // r11
  unsigned __int8 *v18; // r11
  unsigned __int8 *v19; // r11
  unsigned __int8 *v20; // r11
  unsigned __int8 *v21; // r11
  unsigned __int8 *v22; // r11
  int v23; // ctr
  _DWORD *v24; // r8
  unsigned __int8 *v25; // r11
  unsigned __int8 *v26; // r11
  unsigned __int8 *v27; // r11
  unsigned __int8 *v28; // r11
  unsigned __int8 *v29; // r11
  unsigned __int8 *v30; // r11
  unsigned __int8 *v31; // r11
  unsigned __int8 *v32; // r11
  unsigned __int8 *v33; // r11
  unsigned __int8 *v34; // r11
  unsigned __int8 *v35; // r11
  unsigned __int8 *v36; // r11
  unsigned __int8 *v37; // r11
  unsigned __int8 *v38; // r11
  unsigned __int8 *v39; // r11
  unsigned __int8 *v40; // r11
  int v41; // ctr
  _DWORD *v42; // r11
  unsigned __int8 *v43; // r8
  unsigned __int8 *v44; // r8
  unsigned __int8 *v45; // r8
  unsigned __int8 *v46; // r8
  unsigned __int8 *v47; // r11
  int v48; // r8
  unsigned __int8 *v49; // r11
  unsigned __int8 *v50; // r11
  unsigned __int8 *v51; // r11
  unsigned __int8 *v52; // r11
  unsigned __int8 *v53; // r11
  unsigned __int8 *v54; // r11
  unsigned __int8 *v55; // r11
  unsigned __int8 *v56; // r11
  unsigned __int8 *v57; // r11
  unsigned __int8 *v58; // r11
  unsigned __int8 *v59; // r11
  unsigned __int8 *v60; // r11
  unsigned __int8 *v61; // r11
  unsigned __int8 *v62; // r11
  int v63; // ctr
  unsigned __int8 *v64; // r11
  unsigned __int8 *v65; // r11
  unsigned __int8 *v66; // r11
  unsigned __int8 *v67; // r11
  unsigned __int8 *v68; // r11
  unsigned __int8 *v69; // r11
  unsigned __int8 *v70; // r11
  unsigned __int8 *v71; // r11
  unsigned __int8 *v72; // r7
  unsigned __int8 *v73; // r7
  unsigned __int8 *v74; // r7
  int v75; // ctr
  int v76; // r8
  unsigned __int8 *v77; // r7
  unsigned __int8 *v78; // r7
  unsigned __int8 *v79; // r7
  unsigned __int8 *v80; // r7
  unsigned __int8 *v81; // r7
  unsigned __int8 *v82; // r7
  int v83; // r8
  int v84; // ctr
  unsigned __int8 *v85; // r7
  unsigned __int8 *v86; // r7
  unsigned __int8 *v87; // r7
  int v88; // r8
  int i; // ctr
  unsigned __int8 *v90; // r7
  unsigned __int8 *v91; // r7
  unsigned __int8 *v92; // r7
  unsigned __int8 *v93; // r7
  unsigned __int8 *v94; // r7
  unsigned __int8 *v95; // r7
  int v96; // r8
  int v97; // ctr
  unsigned __int8 *v98; // r7
  unsigned __int8 *v99; // r7
  unsigned __int8 *v100; // r7
  int v101; // ctr
  int v102; // r8
  unsigned __int8 *v103; // r7
  unsigned __int8 *v104; // r7
  unsigned __int8 *v105; // r7
  unsigned __int8 *v106; // r7
  unsigned __int8 *v107; // r7
  unsigned __int8 *v108; // r7
  int v109; // r8
  int v110; // ctr
  unsigned __int8 *v111; // r7
  unsigned __int8 *v112; // r7
  unsigned __int8 *v113; // r7
  int v114; // r8
  int j; // ctr
  unsigned __int8 *v116; // r7
  unsigned __int8 *v117; // r7
  unsigned __int8 *v118; // r7
  unsigned __int8 *v119; // r7
  unsigned __int8 *v120; // r7
  unsigned __int8 *v121; // r7
  int v122; // r17
  int v123; // r16
  unsigned __int8 *v124; // r11
  unsigned __int8 *v125; // r11
  unsigned __int8 *v126; // r11
  unsigned __int8 *v127; // r11
  unsigned __int8 *v128; // r11
  unsigned __int8 *v129; // r11
  unsigned __int8 *v130; // r11
  unsigned __int8 *v131; // r11
  unsigned __int8 *v132; // r11
  unsigned __int8 *v133; // r11
  unsigned __int8 *v134; // r11
  unsigned __int8 *v135; // r11
  unsigned __int8 *v136; // r11
  int v137; // r4
  int v138; // r20
  int v139; // r22
  int v140; // r11
  int v141; // r23
  int v142; // r26
  const unsigned __int8 *v143; // r29
  int v144; // r24
  unsigned __int8 *v145; // r27
  unsigned __int8 *v146; // r25
  const unsigned __int8 *v147; // r10
  unsigned __int8 *v148; // r11
  int v149; // r9
  unsigned __int8 v150; // r7
  unsigned __int8 v151; // r6
  unsigned __int8 v152; // r5
  unsigned __int8 *data; // r8
  int v155; // r11
  int v156; // r7
  int v157; // [sp+50h] [-4B0h]
  unsigned __int8 v158[1184]; // [sp+60h] [-4A0h] BYREF

  this->data = outBuf;
  this->useMarkers = useMarkers_;
  this->imageWidth = width;
  this->bitCnt = 0;
  this->imageHeight = height;
  this->bitBuff = 0;
  this->dcA = 0;
  this->dcCg = 0;
  this->dcCo = 0;
  v10 = outputBytes;
  this->dcY = 0;
  *outBuf = -1;
  v11 = this->data + 1;
  this->data = v11;
  *v11 = -40;
  v12 = this->data + 1;
  this->data = v12;
  *v12 = -1;
  v13 = this->data + 1;
  this->data = v13;
  *v13 = -32;
  v14 = this->data + 1;
  this->data = v14;
  *v14 = 0;
  v15 = this->data + 1;
  this->data = v15;
  *v15 = 16;
  v16 = this->data + 1;
  this->data = v16;
  *v16 = 74;
  v17 = this->data + 1;
  this->data = v17;
  *v17 = 70;
  v18 = this->data + 1;
  this->data = v18;
  *v18 = 73;
  v19 = this->data + 1;
  this->data = v19;
  *v19 = 70;
  v20 = this->data + 1;
  this->data = v20;
  *v20 = 0;
  v21 = this->data + 1;
  this->data = v21;
  *v21 = 1;
  v22 = this->data + 1;
  this->data = v22;
  *v22 = 1;
  v23 = 16;
  v157 = 4 * width;
  v24 = &algn_82234FA2[2];
  v25 = this->data + 1;
  this->data = v25;
  *v25 = 0;
  v26 = this->data + 1;
  this->data = v26;
  *v26 = 0;
  v27 = this->data + 1;
  this->data = v27;
  *v27 = 1;
  v28 = this->data + 1;
  this->data = v28;
  *v28 = 0;
  v29 = this->data + 1;
  this->data = v29;
  *v29 = 1;
  v30 = this->data + 1;
  this->data = v30;
  *v30 = 0;
  v31 = this->data + 1;
  this->data = v31;
  *v31 = 0;
  v32 = this->data + 1;
  this->data = v32;
  *v32 = -1;
  v33 = this->data + 1;
  this->data = v33;
  *v33 = -37;
  v34 = this->data + 1;
  this->data = v34;
  *v34 = 0;
  v35 = this->data + 1;
  this->data = v35;
  *v35 = -124;
  v36 = this->data + 1;
  this->data = v36;
  *v36 = 0;
  ++this->data;
  do
  {
    *this->data = this->quantTableY[v24[1]];
    v37 = this->data + 1;
    this->data = v37;
    *v37 = this->quantTableY[v24[2]];
    v38 = this->data + 1;
    this->data = v38;
    *v38 = this->quantTableY[v24[3]];
    v39 = this->data + 1;
    this->data = v39;
    v24 += 4;
    *v39 = this->quantTableY[*v24];
    v40 = this->data + 1;
    this->data = v40;
    --v23;
  }
  while ( v23 != 0 );
  v41 = 16;
  *v40 = 1;
  v42 = &algn_82234FA2[2];
  ++this->data;
  do
  {
    *this->data = this->quantTableCoCg[v42[1]];
    v43 = this->data + 1;
    this->data = v43;
    *v43 = this->quantTableCoCg[v42[2]];
    v44 = this->data + 1;
    this->data = v44;
    *v44 = this->quantTableCoCg[v42[3]];
    v45 = this->data + 1;
    this->data = v45;
    v42 += 4;
    *v45 = this->quantTableCoCg[*v42];
    v46 = this->data + 1;
    this->data = v46;
    --v41;
  }
  while ( v41 != 0 );
  *v46 = -1;
  v47 = this->data + 1;
  this->data = v47;
  *v47 = -64;
  v48 = 0;
  v49 = this->data + 1;
  this->data = v49;
  *v49 = 0;
  v50 = this->data + 1;
  this->data = v50;
  *v50 = 17;
  v51 = this->data + 1;
  this->data = v51;
  *v51 = 8;
  v52 = this->data + 1;
  this->data = v52;
  *v52 = BYTE2(height);
  v53 = this->data + 1;
  this->data = v53;
  *v53 = height;
  v54 = this->data + 1;
  this->data = v54;
  *v54 = BYTE2(width);
  v55 = this->data + 1;
  this->data = v55;
  *v55 = width;
  v56 = this->data + 1;
  this->data = v56;
  *v56 = 3;
  v57 = this->data + 1;
  this->data = v57;
  *v57 = 1;
  v58 = this->data + 1;
  this->data = v58;
  *v58 = 34;
  v59 = this->data + 1;
  this->data = v59;
  *v59 = 0;
  v60 = this->data + 1;
  this->data = v60;
  *v60 = 2;
  v61 = this->data + 1;
  this->data = v61;
  *v61 = 17;
  v62 = this->data + 1;
  this->data = v62;
  *v62 = 1;
  v63 = 4;
  v64 = this->data + 1;
  this->data = v64;
  *v64 = 3;
  v65 = this->data + 1;
  this->data = v65;
  *v65 = 17;
  v66 = this->data + 1;
  this->data = v66;
  *v66 = 1;
  v67 = this->data + 1;
  this->data = v67;
  *v67 = -1;
  v68 = this->data + 1;
  this->data = v68;
  *v68 = -60;
  v69 = this->data + 1;
  this->data = v69;
  *v69 = 1;
  v70 = this->data + 1;
  this->data = v70;
  *v70 = -94;
  v71 = this->data + 1;
  this->data = v71;
  *v71 = 0;
  ++this->data;
  do
  {
    *this->data = bitsYDC[v48 + 1];
    v72 = this->data + 1;
    this->data = v72;
    *v72 = bitsYDC[v48 + 2];
    v73 = this->data + 1;
    this->data = v73;
    *v73 = bitsYDC[v48 + 3];
    v74 = this->data + 1;
    this->data = v74;
    *v74 = bitsYDC[v48 + 4];
    v48 += 4;
    ++this->data;
    --v63;
  }
  while ( v63 != 0 );
  v75 = 2;
  v76 = 0;
  do
  {
    *this->data = valYDC[v76];
    v77 = this->data + 1;
    this->data = v77;
    *v77 = valYDC[v76 + 1];
    v78 = this->data + 1;
    this->data = v78;
    *v78 = valYDC[v76 + 2];
    v79 = this->data + 1;
    this->data = v79;
    *v79 = valYDC[v76 + 3];
    v80 = this->data + 1;
    this->data = v80;
    *v80 = valYDC[v76 + 4];
    v81 = this->data + 1;
    this->data = v81;
    *v81 = valYDC[v76 + 5];
    v76 += 6;
    v82 = this->data + 1;
    this->data = v82;
    --v75;
  }
  while ( v75 != 0 );
  v83 = 0;
  *v82 = 16;
  v84 = 4;
  ++this->data;
  do
  {
    *this->data = bitsYAC[v83 + 1];
    v85 = this->data + 1;
    this->data = v85;
    *v85 = bitsYAC[v83 + 2];
    v86 = this->data + 1;
    this->data = v86;
    *v86 = bitsYAC[v83 + 3];
    v87 = this->data + 1;
    this->data = v87;
    *v87 = bitsYAC[v83 + 4];
    v83 += 4;
    ++this->data;
    --v84;
  }
  while ( v84 != 0 );
  v88 = 0;
  for ( i = 27; i != 0; --i )
  {
    *this->data = valYAC[v88];
    v90 = this->data + 1;
    this->data = v90;
    *v90 = valYAC[v88 + 1];
    v91 = this->data + 1;
    this->data = v91;
    *v91 = valYAC[v88 + 2];
    v92 = this->data + 1;
    this->data = v92;
    *v92 = valYAC[v88 + 3];
    v93 = this->data + 1;
    this->data = v93;
    *v93 = valYAC[v88 + 4];
    v94 = this->data + 1;
    this->data = v94;
    *v94 = valYAC[v88 + 5];
    v88 += 6;
    v95 = this->data + 1;
    this->data = v95;
  }
  v96 = 0;
  v97 = 4;
  *v95 = 1;
  ++this->data;
  do
  {
    *this->data = bitsCoCgDC[v96 + 1];
    v98 = this->data + 1;
    this->data = v98;
    *v98 = bitsCoCgDC[v96 + 2];
    v99 = this->data + 1;
    this->data = v99;
    *v99 = bitsCoCgDC[v96 + 3];
    v100 = this->data + 1;
    this->data = v100;
    *v100 = bitsCoCgDC[v96 + 4];
    v96 += 4;
    ++this->data;
    --v97;
  }
  while ( v97 != 0 );
  v101 = 2;
  v102 = 0;
  do
  {
    *this->data = valCoCgDC[v102];
    v103 = this->data + 1;
    this->data = v103;
    *v103 = valCoCgDC[v102 + 1];
    v104 = this->data + 1;
    this->data = v104;
    *v104 = valCoCgDC[v102 + 2];
    v105 = this->data + 1;
    this->data = v105;
    *v105 = valCoCgDC[v102 + 3];
    v106 = this->data + 1;
    this->data = v106;
    *v106 = valCoCgDC[v102 + 4];
    v107 = this->data + 1;
    this->data = v107;
    *v107 = valCoCgDC[v102 + 5];
    v102 += 6;
    v108 = this->data + 1;
    this->data = v108;
    --v101;
  }
  while ( v101 != 0 );
  v109 = 0;
  v110 = 4;
  *v108 = 17;
  ++this->data;
  do
  {
    *this->data = bitsCoCgAC[v109 + 1];
    v111 = this->data + 1;
    this->data = v111;
    *v111 = bitsCoCgAC[v109 + 2];
    v112 = this->data + 1;
    this->data = v112;
    *v112 = bitsCoCgAC[v109 + 3];
    v113 = this->data + 1;
    this->data = v113;
    *v113 = bitsCoCgAC[v109 + 4];
    v109 += 4;
    ++this->data;
    --v110;
  }
  while ( v110 != 0 );
  v114 = 0;
  for ( j = 27; j != 0; --j )
  {
    *this->data = valCoCgAC[v114];
    v116 = this->data + 1;
    this->data = v116;
    *v116 = valCoCgAC[v114 + 1];
    v117 = this->data + 1;
    this->data = v117;
    *v117 = valCoCgAC[v114 + 2];
    v118 = this->data + 1;
    this->data = v118;
    *v118 = valCoCgAC[v114 + 3];
    v119 = this->data + 1;
    this->data = v119;
    *v119 = valCoCgAC[v114 + 4];
    v120 = this->data + 1;
    this->data = v120;
    *v120 = valCoCgAC[v114 + 5];
    v114 += 6;
    v121 = this->data + 1;
    this->data = v121;
  }
  *v121 = -1;
  v122 = (width + 15) >> 4;
  v123 = 0;
  v124 = this->data + 1;
  this->data = v124;
  *v124 = -38;
  v125 = this->data + 1;
  this->data = v125;
  *v125 = 0;
  v126 = this->data + 1;
  this->data = v126;
  *v126 = 12;
  v127 = this->data + 1;
  this->data = v127;
  *v127 = 3;
  v128 = this->data + 1;
  this->data = v128;
  *v128 = 1;
  v129 = this->data + 1;
  this->data = v129;
  *v129 = 0;
  v130 = this->data + 1;
  this->data = v130;
  *v130 = 2;
  v131 = this->data + 1;
  this->data = v131;
  *v131 = 17;
  v132 = this->data + 1;
  this->data = v132;
  *v132 = 3;
  v133 = this->data + 1;
  this->data = v133;
  *v133 = 17;
  v134 = this->data + 1;
  this->data = v134;
  *v134 = 0;
  v135 = this->data + 1;
  this->data = v135;
  *v135 = 63;
  v136 = this->data + 1;
  this->data = v136;
  *v136 = 0;
  v137 = this->data - outBuf + 1;
  this->data = outBuf;
  this->dataBytes = v137;
  if ( (height + 15) >> 4 > 0 )
  {
    do
    {
      v138 = 0;
      if ( v122 > 0 )
      {
        v139 = 16 * v123;
        do
        {
          v140 = 16 * v138;
          v141 = 16;
          v142 = 16;
          if ( 16 * v123 + 16 > height )
            v141 = height - v139;
          if ( v140 + 16 > width )
            v142 = width - v140;
          v143 = &inBuf[64 * v138 + (height - v139) * v157];
          v144 = 0;
          v145 = v158;
          v146 = &v158[4 * v142];
          do
          {
            if ( v144 >= v141 )
            {
              memcpy(Dst: v145, Src: &v158[64 * v141 - 64], Size: 0x40u);
            }
            else
            {
              v143 -= v157;
              memcpy(Dst: v145, Src: v143, Size: 4 * v142);
              if ( v142 < 16 )
              {
                v147 = &v143[4 * v142];
                v148 = v146 - 4;
                v149 = 16 - v142;
                do
                {
                  v148 += 4;
                  v150 = *(v147 - 3);
                  --v149;
                  v151 = *(v147 - 2);
                  v152 = *(v147 - 1);
                  *v148 = *(v147 - 4);
                  v148[1] = v150;
                  v148[2] = v151;
                  v148[3] = v152;
                }
                while ( v149 != 0 );
              }
            }
            ++v144;
            v146 += 64;
            v145 += 64;
          }
          while ( v144 < 16 );
          idBareDctEncoder::CompressOneTileJPEG(this, rgb: v158, stride: 64);
          ++v138;
        }
        while ( v138 < v122 );
      }
      ++v123;
    }
    while ( v123 < (height + 15) >> 4 );
    v10 = outputBytes;
  }
  if ( this->bitCnt > 0 )
  {
    this->data[this->dataBytes] = HIWORD(this->bitBuff);
    this->bitBuff = 0;
    this->bitCnt = 0;
    ++this->dataBytes;
  }
  this->data[this->dataBytes] = -1;
  data = this->data;
  v155 = this->dataBytes + 1;
  this->dataBytes = v155;
  data[v155] = -39;
  v156 = this->dataBytes + 3;
  ++this->dataBytes;
  *v10 = v156;
  this->useMarkers = false;
  return 1;
}

