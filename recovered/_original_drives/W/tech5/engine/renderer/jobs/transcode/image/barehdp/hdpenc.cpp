
// ========================================================================
// WriteQuantizer
// EA  : 0x828F4740
// RVA : 0x008F4740
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenc.cpp
// ========================================================================

void __fastcall WriteQuantizer(
        hdpQuantizer_t **pQuantizer,
        hdpBitIO_t *pIO,
        unsigned __int8 cChMode,
        unsigned int numChannels,
        unsigned int iPos)
{
  unsigned __int8 v7; // r31
  int v10; // r11
  unsigned int v11; // r31
  unsigned int v12; // r29
  hdpQuantizer_t **v13; // r30

  v7 = cChMode;
  if ( cChMode > 2u )
    v7 = 2;
  if ( numChannels <= 1 )
    v7 = 0;
  else
    WriteBits16(pIO, uiBits: v7, cBits: 2);
  v10 = v7;
  if ( v7 != 0 )
  {
    v11 = 2;
    if ( v10 != 1 )
      v11 = numChannels;
  }
  else
  {
    v11 = 1;
  }
  if ( v11 != 0 )
  {
    v12 = iPos;
    v13 = pQuantizer - 1;
    do
    {
      WriteBits16(pIO, uiBits: (*++v13)[v12].iIndex, cBits: 8);
      --v11;
    }
    while ( v11 != 0 );
  }
}


// ========================================================================
// WritePacketHeader
// EA  : 0x828F47F0
// RVA : 0x008F47F0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenc.cpp
// ========================================================================

void __fastcall WritePacketHeader(hdpBitIO_t *pIO, unsigned __int8 ptPacketType, int pID)
{
  WriteBits16(pIO, uiBits: 0, cBits: 8);
  WriteBits16(pIO, uiBits: 0, cBits: 8);
  WriteBits16(pIO, uiBits: 1u, cBits: 8);
  WriteBits16(pIO, uiBits: (ptPacketType & 7) + ((8 * pID) & 0x7F8), cBits: 8);
}


// ========================================================================
// WriteTileHeaderQuantizerDC
// EA  : 0x828F4858
// RVA : 0x008F4858
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenc.cpp
// ========================================================================

hdpError_t __fastcall WriteTileHeaderQuantizerDC(hdpCodec_t *codec, hdpBitIO_t *pIO)
{
  hdpTileQuantization_t *v4; // r26
  int v5; // r27
  unsigned int v6; // r29
  int v7; // r30
  hdpError_t result; // r3
  unsigned int numChannels; // r5
  unsigned int v10; // r30
  unsigned __int8 *p_cNumQPLP; // r29
  int v12; // r28
  unsigned __int8 v13; // r30
  unsigned int v14; // r31
  unsigned __int8 *v15; // r30

  v4 = &codec->tileQuantization[codec->currentTileColumn];
  v5 = rand() & 3;
  if ( codec->currentTileRow + codec->currentTileColumn != 0 )
  {
LABEL_5:
    numChannels = codec->codecParms.numChannels;
    v10 = 0;
    if ( numChannels != 0 )
    {
      p_cNumQPLP = &v4[-1].cNumQPLP;
      do
      {
        p_cNumQPLP += 4;
        v12 = *(_DWORD *)p_cNumQPLP;
        ++v10;
        *(_BYTE *)(v12 + 13) = (rand() & 0x2F) + 1;
        numChannels = codec->codecParms.numChannels;
      }
      while ( v10 < numChannels );
    }
    FormatQuantizer(
      pQuantizer: v4->pQuantizerDC,
      cMode: v5,
      numChannels,
      iPos: 0,
      useShiftedUV: true,
      useScaledArith: codec->codecParms.useScaledArith,
      useRoundDC: true);
    v13 = v5;
    v14 = codec->codecParms.numChannels;
    if ( (unsigned __int8)v5 > 2u )
      v13 = 2;
    if ( v14 <= 1 )
      v13 = 0;
    else
      WriteBits16(pIO, uiBits: v13, cBits: 2);
    if ( v13 != 0 )
    {
      if ( v13 == 1 )
        v14 = 2;
    }
    else
    {
      v14 = 1;
    }
    if ( v14 != 0 )
    {
      v15 = &v4[-1].cNumQPLP;
      do
      {
        v15 += 4;
        WriteBits16(pIO, uiBits: *(unsigned __int8 *)(*(_DWORD *)v15 + 13), cBits: 8);
        --v14;
      }
      while ( v14 != 0 );
    }
    return HDP_ERROR_NONE;
  }
  else
  {
    v6 = 0;
    v7 = 0;
    while ( 1 )
    {
      result = AllocateQuantizer(
                 codecParms: &codec->codecParms,
                 pQuantizer: codec->tileQuantization[v7].pQuantizerDC,
                 numChannels: codec->codecParms.numChannels,
                 numQuantizers: 1u);
      if ( result != HDP_ERROR_NONE )
        break;
      ++v6;
      ++v7;
      if ( v6 > codec->codecParms.numTilesWideMinusOne )
        goto LABEL_5;
    }
  }
  return result;
}


// ========================================================================
// WriteTileHeaderQuantizerLP
// EA  : 0x828F49C0
// RVA : 0x008F49C0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenc.cpp
// ========================================================================

hdpError_t __fastcall WriteTileHeaderQuantizerLP(hdpCodec_t *codec, hdpBitIO_t *pIO)
{
  hdpTileQuantization_t *v4; // r24
  unsigned int v5; // r30
  char v6; // r11
  hdpError_t result; // r3
  unsigned __int8 QuantizerBits; // r3
  int cNumQPLP; // r11
  unsigned int v10; // r27
  char v11; // r3
  unsigned int numChannels; // r5
  unsigned __int8 v13; // r25
  unsigned int v14; // r30
  hdpQuantizer_t **v15; // r29
  int v16; // r28

  v4 = &codec->tileQuantization[codec->currentTileColumn];
  v5 = (rand() & 1) == 0;
  WriteBits16(pIO, uiBits: (_cntlzw(v5) & 0x20) != 0, cBits: 1);
  v4->cBitsLP = 0;
  if ( v5 != 0 )
    v6 = (rand() & 0xF) + 1;
  else
    v6 = 1;
  v4->cNumQPLP = v6;
  if ( codec->currentTileRow != 0 )
    FreeQuantizer(codecParms: &codec->codecParms, pQuantizer: v4->pQuantizerLP);
  result = AllocateQuantizer(
             codecParms: &codec->codecParms,
             pQuantizer: v4->pQuantizerLP,
             numChannels: codec->codecParms.numChannels,
             numQuantizers: v4->cNumQPLP);
  if ( result == HDP_ERROR_NONE )
  {
    if ( v5 != 0 )
    {
      UseDCQuantizerForLP(codec, iTile: codec->currentTileColumn);
      return HDP_ERROR_NONE;
    }
    else
    {
      WriteBits16(pIO, uiBits: v4->cNumQPLP - 1, cBits: 4);
      QuantizerBits = GetQuantizerBits(numQuantizers: v4->cNumQPLP);
      cNumQPLP = v4->cNumQPLP;
      v4->cBitsLP = QuantizerBits;
      if ( cNumQPLP != 0 )
      {
        v10 = 0;
        do
        {
          v11 = rand();
          numChannels = codec->codecParms.numChannels;
          v13 = v11 & 3;
          v14 = 0;
          if ( numChannels != 0 )
          {
            v15 = &v4->pQuantizerDC[15];
            do
            {
              v16 = (int)*++v15;
              ++v14;
              *(_BYTE *)(v16 + 16 * v10 + 13) = (rand() & 0xFE) + 1;
              numChannels = codec->codecParms.numChannels;
            }
            while ( v14 < numChannels );
          }
          FormatQuantizer(
            pQuantizer: v4->pQuantizerLP,
            cMode: v13,
            numChannels,
            iPos: v10,
            useShiftedUV: true,
            useScaledArith: codec->codecParms.useScaledArith,
            useRoundDC: false);
          WriteQuantizer(
            pQuantizer: v4->pQuantizerLP,
            pIO,
            cChMode: v13,
            numChannels: codec->codecParms.numChannels,
            iPos: v10);
          v10 = (unsigned __int8)(v10 + 1);
        }
        while ( v10 < v4->cNumQPLP );
      }
      return HDP_ERROR_NONE;
    }
  }
  return result;
}


// ========================================================================
// WriteTileHeaderQuantizerHP
// EA  : 0x828F4B60
// RVA : 0x008F4B60
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenc.cpp
// ========================================================================

hdpError_t __fastcall WriteTileHeaderQuantizerHP(hdpCodec_t *codec, hdpBitIO_t *pIO)
{
  hdpTileQuantization_t *v4; // r25
  unsigned int v5; // r30
  unsigned __int8 cNumQPLP; // r11
  hdpError_t result; // r3
  unsigned __int8 QuantizerBits; // r3
  int cNumQPHP; // r11
  unsigned int v10; // r27
  char v11; // r3
  unsigned int numChannels; // r5
  unsigned __int8 v13; // r24
  unsigned int v14; // r30
  hdpQuantizer_t **v15; // r29
  int v16; // r28

  v4 = &codec->tileQuantization[codec->currentTileColumn];
  v5 = (rand() & 1) == 0;
  WriteBits16(pIO, uiBits: (_cntlzw(v5) & 0x20) != 0, cBits: 1);
  v4->cBitsHP = 0;
  if ( v5 != 0 )
    cNumQPLP = (rand() & 0xF) + 1;
  else
    cNumQPLP = v4->cNumQPLP;
  v4->cNumQPHP = cNumQPLP;
  if ( codec->currentTileRow != 0 )
    FreeQuantizer(codecParms: &codec->codecParms, pQuantizer: v4->pQuantizerHP);
  result = AllocateQuantizer(
             codecParms: &codec->codecParms,
             pQuantizer: v4->pQuantizerHP,
             numChannels: codec->codecParms.numChannels,
             numQuantizers: v4->cNumQPHP);
  if ( result == HDP_ERROR_NONE )
  {
    if ( v5 != 0 )
    {
      UseLPQuantizerForHP(codec, numQuantizers: v4->cNumQPHP, iTile: codec->currentTileColumn);
      return HDP_ERROR_NONE;
    }
    else
    {
      WriteBits16(pIO, uiBits: v4->cNumQPHP - 1, cBits: 4);
      QuantizerBits = GetQuantizerBits(numQuantizers: v4->cNumQPHP);
      cNumQPHP = v4->cNumQPHP;
      v4->cBitsHP = QuantizerBits;
      if ( cNumQPHP != 0 )
      {
        v10 = 0;
        do
        {
          v11 = rand();
          numChannels = codec->codecParms.numChannels;
          v13 = v11 & 3;
          v14 = 0;
          if ( numChannels != 0 )
          {
            v15 = &v4->pQuantizerLP[15];
            do
            {
              v16 = (int)*++v15;
              ++v14;
              *(_BYTE *)(v16 + 16 * v10 + 13) = (rand() & 0xFE) + 1;
              numChannels = codec->codecParms.numChannels;
            }
            while ( v14 < numChannels );
          }
          FormatQuantizer(
            pQuantizer: v4->pQuantizerHP,
            cMode: v13,
            numChannels,
            iPos: v10,
            useShiftedUV: false,
            useScaledArith: codec->codecParms.useScaledArith,
            useRoundDC: false);
          WriteQuantizer(
            pQuantizer: v4->pQuantizerHP,
            pIO,
            cChMode: v13,
            numChannels: codec->codecParms.numChannels,
            iPos: v10);
          v10 = (unsigned __int8)(v10 + 1);
        }
        while ( v10 < v4->cNumQPHP );
      }
      return HDP_ERROR_NONE;
    }
  }
  return result;
}


// ========================================================================
// WriteTileHeader
// EA  : 0x828F4D00
// RVA : 0x008F4D00
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenc.cpp
// ========================================================================

hdpError_t __fastcall WriteTileHeader(hdpCodec_t *codec)
{
  unsigned int currentTileColumn; // r11
  hdpContext_t *v3; // r29
  unsigned int v4; // r6
  hdpSubBands_t subBands; // r11
  int v6; // r30
  hdpBitIO_t *bitIOFL; // r3
  unsigned __int8 v8; // r4
  hdpCodec_t *v9; // r30
  hdpCodec_t *v10; // r30
  hdpCodec_t *v11; // r30
  unsigned int v12; // r4
  hdpBitIO_t *v13; // r3

  currentTileColumn = codec->currentTileColumn;
  v3 = &codec->tileContexts[currentTileColumn];
  if ( codec->isSecondaryCodec )
    goto LABEL_29;
  v4 = (codec->codecParms.numTilesWideMinusOne + 1) * codec->currentTileRow + currentTileColumn;
  subBands = codec->codecParms.subBands;
  v6 = v4 & 0x1F;
  if ( codec->codecParms.streamLayout != SL_SPATIAL )
  {
    if ( subBands < SB_ISOLATED )
      WritePacketHeader(pIO: v3->bitIODC, ptPacketType: 1u, pID: v4 & 0x1F);
    if ( codec->codecParms.subBands < SB_NO_LOWPASS )
      WritePacketHeader(pIO: v3->bitIOLP, ptPacketType: 2u, pID: v6);
    if ( codec->codecParms.subBands < SB_NO_HIGHPASS )
      WritePacketHeader(pIO: v3->bitIOHP, ptPacketType: 3u, pID: v6);
    if ( codec->codecParms.subBands >= SB_NO_FLEXBITS )
      goto LABEL_14;
    bitIOFL = v3->bitIOFL;
    v8 = 4;
  }
  else
  {
    if ( subBands >= SB_ISOLATED )
      goto LABEL_14;
    bitIOFL = v3->bitIODC;
    v8 = 0;
  }
  WritePacketHeader(pIO: bitIOFL, ptPacketType: v8, pID: v6);
LABEL_14:
  if ( codec->codecParms.subBands < SB_ISOLATED && (codec->codecParms.quantizationMode & 1) != 0 )
  {
    v9 = codec;
    do
    {
      WriteTileHeaderQuantizerDC(codec: v9, pIO: v3->bitIODC);
      v9 = v9->nextCodec;
    }
    while ( v9 != nullptr );
  }
  if ( codec->codecParms.subBands < SB_NO_LOWPASS && (codec->codecParms.quantizationMode & 2) != 0 )
  {
    v10 = codec;
    do
    {
      WriteTileHeaderQuantizerLP(codec: v10, pIO: v3->bitIOLP);
      v10 = v10->nextCodec;
    }
    while ( v10 != nullptr );
  }
  if ( codec->codecParms.subBands < SB_NO_HIGHPASS && (codec->codecParms.quantizationMode & 4) != 0 )
  {
    v11 = codec;
    do
    {
      WriteTileHeaderQuantizerHP(codec: v11, pIO: v3->bitIOHP);
      v11 = v11->nextCodec;
    }
    while ( v11 != nullptr );
  }
  if ( codec->codecParms.subBands < SB_NO_FLEXBITS && codec->codecParms.hasPerTileTrimFlexbits )
  {
    v12 = rand() & 0xF;
    v13 = v3->bitIOFL;
    v3->trimTileFlexBits = v12;
    WriteBits16(pIO: v13, uiBits: v12, cBits: 4);
  }
LABEL_29:
  ResetCodingContext(context: v3);
  return HDP_ERROR_NONE;
}


// ========================================================================
// PutVLWordEsc
// EA  : 0x828F4EC0
// RVA : 0x008F4EC0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenc.cpp
// ========================================================================

void __fastcall PutVLWordEsc(hdpBitIO_t *pIO, unsigned int iEscape, unsigned int s)
{
  unsigned __int16 v4; // r29
  unsigned int v5; // r28

  v4 = s;
  if ( iEscape != 0 )
  {
    WriteBits16(pIO, uiBits: iEscape, cBits: 8);
  }
  else if ( s >= 0xFB00 )
  {
    v5 = HIWORD(s);
    WriteBits16(pIO, uiBits: 0xFBu, cBits: 8);
    WriteBits16(pIO, uiBits: (unsigned __int16)v5, cBits: 16);
    WriteBits16(pIO, uiBits: v4, cBits: 16);
  }
  else
  {
    WriteBits16(pIO, uiBits: s, cBits: 16);
  }
}


// ========================================================================
// WriteIndexTable
// EA  : 0x828F4F80
// RVA : 0x008F4F80
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenc.cpp
// ========================================================================

hdpError_t __fastcall WriteIndexTable(hdpCodec_t *codec)
{
  unsigned int numTileBitIOs; // r10
  hdpBitIO_t *bitIOHeader; // r26
  unsigned int v4; // r29
  unsigned int numTilesHighMinusOne; // r8
  unsigned int v6; // r10
  unsigned int i; // r11
  unsigned int v8; // r6
  unsigned int v9; // r9
  int v10; // r3
  unsigned int v11; // r28
  unsigned int *tileIndex; // r11
  int v13; // r30
  unsigned int v14; // r7

  numTileBitIOs = codec->numTileBitIOs;
  if ( numTileBitIOs != 0 )
  {
    bitIOHeader = codec->bitIOHeader;
    v4 = (codec->codecParms.numTilesHighMinusOne + 1) * numTileBitIOs;
    WriteBits16(pIO: bitIOHeader, uiBits: 1u, cBits: 16);
    numTilesHighMinusOne = codec->codecParms.numTilesHighMinusOne;
    if ( numTilesHighMinusOne != 0 )
    {
      v6 = codec->numTileBitIOs;
      do
      {
        for ( i = 0; i < v6; v6 = codec->numTileBitIOs )
        {
          v8 = codec->numTileBitIOs;
          v9 = v8 * numTilesHighMinusOne + i;
          v10 = (numTilesHighMinusOne - 1) * v8 + i++;
          codec->tileIndex[v9] -= codec->tileIndex[v10];
        }
        --numTilesHighMinusOne;
      }
      while ( numTilesHighMinusOne != 0 );
    }
    v11 = 0;
    if ( v4 != 0 )
    {
      tileIndex = codec->tileIndex;
      v13 = 0;
      do
      {
        PutVLWordEsc(pIO: bitIOHeader, iEscape: (unsigned __int8)-(tileIndex[v13] <= 4), s: v11);
        tileIndex = codec->tileIndex;
        v14 = tileIndex[v13++];
        --v4;
        v11 += v14 <= 4 ? 0 : v14;
      }
      while ( v4 != 0 );
    }
    WriteBits16(pIO: bitIOHeader, uiBits: 0xFFu, cBits: 8);
    WriteUpToByte(pIO: bitIOHeader);
  }
  return HDP_ERROR_NONE;
}


// ========================================================================
// InitImagePlaneEnc
// EA  : 0x828F50A8
// RVA : 0x008F50A8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenc.cpp
// ========================================================================

hdpError_t __fastcall InitImagePlaneEnc(hdpCodec_t *codec)
{
  hdpError_t result; // r3
  hdpColorFormat_t colorFormat; // r27
  hdpColorFormat_t v4; // r10
  bool v5; // r11
  int v6; // r10
  bool v7; // zf
  unsigned int v8; // r30
  __int16 *v9; // r3
  __int16 *resampleU; // r10
  int v11; // r30
  unsigned __int8 quantizationUV; // r29
  unsigned int quantizationDefault; // r9
  bool v14; // r10
  hdpBitDepth_t bitDepth; // r11
  unsigned int v16; // r11
  unsigned int v17; // r11
  char v18; // r10
  unsigned int v19; // r11
  unsigned __int8 *quantizerIndexDC; // r9
  unsigned __int8 v21; // r10
  unsigned int v22; // r11
  unsigned __int8 *quantizerIndexLP; // r9
  unsigned __int8 v24; // r10
  unsigned int v25; // r11
  unsigned __int8 *quantizerIndexHP; // r9
  unsigned __int8 v27; // r10
  unsigned int v28; // r11
  int v29; // r10

  if ( codec->codecParms.numTilesWideMinusOne >= 0x1000 )
    return HDP_ERROR_DECODE;
  colorFormat = codec->codecParms.colorFormat;
  v4 = codec->imageInfo.colorFormat;
  if ( colorFormat == CF_YUV_420 )
  {
    if ( v4 == CF_YUV_420 )
      goto LABEL_9;
  }
  else if ( colorFormat != CF_YUV_422 || v4 == CF_YUV_422 )
  {
    goto LABEL_9;
  }
  v5 = true;
  if ( v4 == CF_Y_ONLY )
LABEL_9:
    v5 = false;
  codec->codecParms.changeSubsamplingUV = v5;
  if ( v5 )
  {
    v7 = v4 == CF_YUV_422;
    v6 = 128;
    if ( !v7 )
      v6 = 256;
    v8 = 2 * (((colorFormat != CF_YUV_420 ? 0 : 0x20) + v6) * codec->widthInMacroblocks + 256);
    codec->resampleU = (__int16 *)TempAlloc(codecParms: &codec->codecParms, size: v8, align: 0x10u);
    v9 = (__int16 *)TempAlloc(codecParms: &codec->codecParms, size: v8, align: 0x10u);
    resampleU = codec->resampleU;
    codec->resampleV = v9;
    if ( resampleU == nullptr || v9 == nullptr )
      return HDP_ERROR_OUT_OF_MEMORY;
  }
  codec->currentTileColumn = 0;
  codec->currentTileRow = 0;
  result = AllocateTileQuantization(codec);
  if ( result != HDP_ERROR_NONE )
    return result;
  LOBYTE(v11) = 0;
  quantizationUV = 0;
  if ( !codec->codecParms.transcode )
  {
    quantizationDefault = codec->codecParms.quantizationDefault;
    codec->codecParms.quantizationMode = 1704;
    if ( quantizationDefault > 1
      || codec->codecParms.subBands != SB_ALL
      || (v14 = false, codec->codecParms.changeSubsamplingUV) )
    {
      v14 = true;
    }
    bitDepth = codec->imageInfo.bitDepth;
    codec->codecParms.useScaledArith = v14;
    if ( bitDepth == BD_32 || bitDepth == BD_32S || bitDepth == BD_32F )
      codec->codecParms.useScaledArith = false;
    v11 = (unsigned __int8)quantizationDefault >= 2u ? (unsigned __int8)quantizationDefault : 0;
    if ( codec->codecParms.quantizationUV != 0 )
    {
      quantizationUV = codec->codecParms.quantizationUV;
    }
    else
    {
      v16 = (unsigned __int16)-((unsigned __int8)quantizationDefault >= 2u)
          & (unsigned __int16)(unsigned __int8)quantizationDefault;
      if ( v16 >= 0x10 )
      {
        if ( colorFormat == CF_YUV_420 )
        {
          v18 = 4;
        }
        else
        {
          v18 = 8;
          if ( colorFormat != CF_YUV_422 )
            v18 = 18;
        }
        quantizationUV = ((unsigned __int8)quantizationDefault >= 2u ? quantizationDefault : 0) + v18;
        if ( v16 <= 0x30 )
          goto LABEL_41;
        LOBYTE(v17) = quantizationUV + 2;
      }
      else if ( colorFormat == CF_YUV_420 )
      {
        v17 = ((int)(v16 + 2) >> 2) + v16;
      }
      else if ( colorFormat == CF_YUV_422 )
      {
        v17 = ((int)(v16 + 1) >> 1) + v16;
      }
      else
      {
        LOBYTE(v17) = 2 * ((unsigned __int8)quantizationDefault >= 2u ? quantizationDefault : 0);
      }
      quantizationUV = v17;
    }
  }
LABEL_41:
  if ( codec->codecParms.subBands < SB_ISOLATED && (codec->codecParms.quantizationMode & 1) == 0 )
  {
    result = AllocateQuantizer(
               codecParms: &codec->codecParms,
               pQuantizer: codec->tileQuantization->pQuantizerDC,
               numChannels: codec->codecParms.numChannels,
               numQuantizers: 1u);
    if ( result != HDP_ERROR_NONE )
      return result;
    SetUniformQuantizerDC(codec);
    v19 = 0;
    if ( codec->codecParms.numChannels != 0 )
    {
      quantizerIndexDC = codec->codecParms.quantizerIndexDC;
      do
      {
        if ( codec->codecParms.transcode )
        {
          codec->tileQuantization->pQuantizerDC[v19]->iIndex = quantizerIndexDC[v19];
        }
        else if ( colorFormat == CF_YUV_420 || colorFormat == CF_YUV_422 || colorFormat == CF_YUV_444 )
        {
          v21 = v11;
          if ( v19 != 0 )
            v21 = quantizationUV;
          quantizerIndexDC[v19] = v21;
          codec->tileQuantization->pQuantizerDC[v19]->iIndex = v21;
        }
        else
        {
          quantizerIndexDC[v19] = v11;
          codec->tileQuantization->pQuantizerDC[v19]->iIndex = v11;
        }
        ++v19;
      }
      while ( v19 < codec->codecParms.numChannels );
    }
    FormatQuantizer(
      pQuantizer: codec->tileQuantization->pQuantizerDC,
      cMode: (codec->codecParms.quantizationMode >> 3) & 3,
      numChannels: codec->codecParms.numChannels,
      iPos: 0,
      useShiftedUV: true,
      useScaledArith: codec->codecParms.useScaledArith,
      useRoundDC: true);
  }
  if ( codec->codecParms.subBands < SB_NO_LOWPASS && (codec->codecParms.quantizationMode & 2) == 0 )
  {
    result = AllocateQuantizer(
               codecParms: &codec->codecParms,
               pQuantizer: codec->tileQuantization->pQuantizerLP,
               numChannels: codec->codecParms.numChannels,
               numQuantizers: 1u);
    if ( result != HDP_ERROR_NONE )
      return result;
    SetUniformQuantizerLP(codec);
    v22 = 0;
    if ( codec->codecParms.numChannels != 0 )
    {
      quantizerIndexLP = codec->codecParms.quantizerIndexLP;
      do
      {
        if ( codec->codecParms.transcode )
        {
          codec->tileQuantization->pQuantizerLP[v22]->iIndex = quantizerIndexLP[v22];
        }
        else if ( colorFormat == CF_YUV_444 || colorFormat == CF_YUV_420 || colorFormat == CF_YUV_422 )
        {
          v24 = v11;
          if ( v22 != 0 )
            v24 = quantizationUV;
          quantizerIndexLP[v22] = v24;
          codec->tileQuantization->pQuantizerLP[v22]->iIndex = v24;
        }
        else
        {
          quantizerIndexLP[v22] = v11;
          codec->tileQuantization->pQuantizerLP[v22]->iIndex = v11;
        }
        ++v22;
      }
      while ( v22 < codec->codecParms.numChannels );
    }
    FormatQuantizer(
      pQuantizer: codec->tileQuantization->pQuantizerLP,
      cMode: (codec->codecParms.quantizationMode >> 5) & 3,
      numChannels: codec->codecParms.numChannels,
      iPos: 0,
      useShiftedUV: true,
      useScaledArith: codec->codecParms.useScaledArith,
      useRoundDC: false);
  }
  if ( codec->codecParms.subBands < SB_NO_HIGHPASS && (codec->codecParms.quantizationMode & 4) == 0 )
  {
    result = AllocateQuantizer(
               codecParms: &codec->codecParms,
               pQuantizer: codec->tileQuantization->pQuantizerHP,
               numChannels: codec->codecParms.numChannels,
               numQuantizers: 1u);
    if ( result != HDP_ERROR_NONE )
      return result;
    SetUniformQuantizerHP(codec);
    v25 = 0;
    if ( codec->codecParms.numChannels != 0 )
    {
      quantizerIndexHP = codec->codecParms.quantizerIndexHP;
      do
      {
        if ( codec->codecParms.transcode )
        {
          codec->tileQuantization->pQuantizerHP[v25]->iIndex = quantizerIndexHP[v25];
        }
        else
        {
          if ( colorFormat == CF_YUV_444 || colorFormat == CF_YUV_420 || colorFormat == CF_YUV_422 )
          {
            v27 = v11;
            if ( v25 != 0 )
              v27 = quantizationUV;
          }
          else
          {
            v27 = v11;
          }
          quantizerIndexHP[v25] = v27;
          codec->tileQuantization->pQuantizerHP[v25]->iIndex = v27;
        }
        ++v25;
      }
      while ( v25 < codec->codecParms.numChannels );
    }
    FormatQuantizer(
      pQuantizer: codec->tileQuantization->pQuantizerHP,
      cMode: (codec->codecParms.quantizationMode >> 7) & 3,
      numChannels: codec->codecParms.numChannels,
      iPos: 0,
      useShiftedUV: false,
      useScaledArith: codec->codecParms.useScaledArith,
      useRoundDC: false);
  }
  result = AllocatePredictionInfo(codec);
  if ( result == HDP_ERROR_NONE )
  {
    result = AllocateCodingContexts(codec);
    if ( result == HDP_ERROR_NONE )
    {
      v28 = 0;
      v29 = 0;
      do
      {
        ++v28;
        codec->tileContexts[v29++].trimTileFlexBits = codec->codecParms.uniformTrimFlexBits;
      }
      while ( v28 <= codec->codecParms.numTilesWideMinusOne );
      return HDP_ERROR_NONE;
    }
  }
  return result;
}


// ========================================================================
// InitIOEnc
// EA  : 0x828F5658
// RVA : 0x008F5658
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenc.cpp
// ========================================================================

hdpError_t __fastcall InitIOEnc(hdpCodec_t *codec)
{
  bool v2; // r11
  hdpError_t result; // r3
  unsigned int numTileBitIOs; // r11
  char *v5; // r3
  unsigned int v6; // r28
  int v7; // r29
  int v8; // r30

  if ( codec->codecParms.streamLayout != SL_SPATIAL
    || (v2 = false, codec->codecParms.numTilesWideMinusOne + codec->codecParms.numTilesHighMinusOne != 0) )
  {
    v2 = true;
  }
  codec->codecParms.hasTileIndex = v2;
  result = AllocateAdditionalBitIOs(codec);
  if ( result == HDP_ERROR_NONE )
  {
    StreamWriteAttach(pIO: codec->bitIOHeader, stream: codec->codecParms.baseStream);
    numTileBitIOs = codec->numTileBitIOs;
    if ( numTileBitIOs != 0 )
    {
      v5 = TempAlloc(codecParms: &codec->codecParms, size: 4 * numTileBitIOs, align: 0x10u);
      codec->tileStreams = (hdpStream_t **)v5;
      if ( v5 == nullptr )
        return HDP_ERROR_OUT_OF_MEMORY;
      memset(Dst: v5, Val: 0, Size: 4 * codec->numTileBitIOs);
      v6 = 0;
      if ( codec->numTileBitIOs != 0 )
      {
        v7 = 0;
        v8 = 0;
        do
        {
          CreateWS_Memory(stream: codec->tileStreams[v8], pv: nullptr, cb: 0);
          StreamWriteAttach(pIO: &codec->tileBitIOs[v7], stream: codec->tileStreams[v8]);
          ++v6;
          ++v8;
          ++v7;
        }
        while ( v6 < codec->numTileBitIOs );
      }
    }
    return HDP_ERROR_NONE;
  }
  return result;
}


// ========================================================================
// CopyStream
// EA  : 0x828F5758
// RVA : 0x008F5758
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenc.cpp
// ========================================================================

hdpError_t __fastcall CopyStream(hdpStream_t *pSrc, hdpStream_t *pDst, unsigned int iBytes)
{
  unsigned int v5; // r31
  unsigned int v6; // r30
  _BYTE v8[1072]; // [sp+50h] [-430h] BYREF

  v5 = iBytes;
  if ( iBytes > 4 )
  {
    if ( iBytes > 0x400 )
    {
      v6 = ((iBytes - 1025) >> 10) + 1;
      do
      {
        pSrc->Read(a1: pSrc, a2: v8, a3: 1024u);
        pDst->Write(a1: pDst, a2: v8, a3: 1024u);
        --v6;
        v5 -= 1024;
      }
      while ( v6 != 0 );
    }
    pSrc->Read(a1: pSrc, a2: v8, a3: v5);
    pDst->Write(a1: pDst, a2: v8, a3: v5);
  }
  else
  {
    pSrc->Read(a1: pSrc, a2: v8, a3: iBytes);
  }
  return HDP_ERROR_NONE;
}


// ========================================================================
// ShutdownIOEnc
// EA  : 0x828F5810
// RVA : 0x008F5810
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenc.cpp
// ========================================================================

hdpError_t __fastcall ShutdownIOEnc(hdpCodec_t *codec)
{
  hdpBitIO_t *bitIOHeader; // r30
  hdpStream_t *baseStream; // r27
  unsigned int v4; // r30
  int v5; // r29
  unsigned int numTileBitIOs; // r11
  unsigned int v7; // r29
  int v8; // r30
  unsigned int v9; // r25
  int v10; // r29
  unsigned int v11; // r28
  int v12; // r30
  int v13; // r26
  hdpStream_t *v14; // r4
  unsigned int v15; // r5
  hdpStream_t *v16; // r3
  unsigned int numSubBands; // r11
  unsigned int v18; // r11
  unsigned int v19; // r11
  unsigned int v20; // r29
  int v21; // r30

  bitIOHeader = codec->bitIOHeader;
  WriteUpToByte(pIO: bitIOHeader);
  WriteIndexTable(codec);
  StreamWriteDetach(pIO: bitIOHeader);
  if ( codec->numTileBitIOs == 0 )
    return HDP_ERROR_NONE;
  baseStream = codec->codecParms.baseStream;
  v4 = 0;
  v5 = 0;
  do
  {
    StreamWriteDetach(pIO: &codec->tileBitIOs[v5]);
    numTileBitIOs = codec->numTileBitIOs;
    ++v4;
    ++v5;
  }
  while ( v4 < numTileBitIOs );
  v7 = 0;
  if ( numTileBitIOs != 0 )
  {
    v8 = 0;
    do
    {
      codec->tileStreams[v8]->SetPos(a1: codec->tileStreams[v8], a2: 0);
      ++v7;
      ++v8;
    }
    while ( v7 < codec->numTileBitIOs );
  }
  v9 = 0;
  v10 = 0;
  do
  {
    v11 = 0;
    v12 = v10;
    v13 = 0;
    do
    {
      v14 = baseStream;
      if ( codec->codecParms.streamLayout == SL_SPATIAL )
      {
        v15 = codec->tileIndex[v12];
        v16 = codec->tileStreams[v13];
LABEL_17:
        CopyStream(pSrc: v16, pDst: v14, iBytes: v15);
        ++v12;
        ++v10;
        goto LABEL_18;
      }
      CopyStream(pSrc: codec->tileStreams[codec->numSubBands * v11], pDst: baseStream, iBytes: codec->tileIndex[v12]);
      numSubBands = codec->numSubBands;
      ++v10;
      ++v12;
      if ( numSubBands > 1 )
      {
        CopyStream(pSrc: codec->tileStreams[numSubBands * v11 + 1], pDst: baseStream, iBytes: codec->tileIndex[v12]);
        ++v10;
        ++v12;
      }
      v18 = codec->numSubBands;
      if ( v18 > 2 )
      {
        CopyStream(pSrc: codec->tileStreams[v18 * v11 + 2], pDst: baseStream, iBytes: codec->tileIndex[v12]);
        ++v10;
        ++v12;
      }
      v19 = codec->numSubBands;
      if ( v19 > 3 )
      {
        v15 = codec->tileIndex[v12];
        v14 = baseStream;
        v16 = codec->tileStreams[v19 * v11 + 3];
        goto LABEL_17;
      }
LABEL_18:
      ++v11;
      ++v13;
    }
    while ( v11 <= codec->codecParms.numTilesWideMinusOne );
    ++v9;
  }
  while ( v9 <= codec->codecParms.numTilesHighMinusOne );
  v20 = 0;
  if ( codec->numTileBitIOs != 0 )
  {
    v21 = 0;
    do
    {
      codec->tileStreams[v21]->Close(a1: codec->tileStreams[v21]);
      ++v20;
      ++v21;
    }
    while ( v20 < codec->numTileBitIOs );
  }
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&codec->codecParms);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&codec->codecParms);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&codec->codecParms);
  return HDP_ERROR_NONE;
}


// ========================================================================
// WriteImagePlaneHeader
// EA  : 0x828F5A58
// RVA : 0x008F5A58
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenc.cpp
// ========================================================================

hdpError_t __fastcall WriteImagePlaneHeader(hdpCodec_t *codec, hdpCodecParms_t *codecParms, hdpBitIO_t *pIO)
{
  hdpColorFormat_t colorFormat; // r11
  unsigned int v7; // r4
  unsigned int quantizationMode; // r11
  unsigned int v9; // r11
  unsigned int v10; // r11
  unsigned int v11; // r11
  unsigned int v12; // r11

  WriteBits16(pIO, uiBits: codecParms->colorFormat, cBits: 3);
  WriteBits16(pIO, uiBits: codecParms->useScaledArith, cBits: 1);
  WriteBits16(pIO, uiBits: codecParms->subBands, cBits: 4);
  colorFormat = codecParms->colorFormat;
  if ( codecParms->colorFormat > CF_Y_ONLY )
  {
    if ( colorFormat <= CF_YUV_444 )
    {
      v7 = 0;
    }
    else
    {
      if ( colorFormat != CF_N_CHANNEL )
        goto LABEL_7;
      v7 = codecParms->numChannels - 1;
    }
    WriteBits16(pIO, uiBits: v7, cBits: 4);
    WriteBits16(pIO, uiBits: 0, cBits: 4);
  }
LABEL_7:
  WriteBits16(pIO, uiBits: (codecParms->quantizationMode & 1) == 0, cBits: 1);
  quantizationMode = codecParms->quantizationMode;
  if ( (quantizationMode & 1) == 0 )
    WriteQuantizer(
      pQuantizer: codec->tileQuantization->pQuantizerDC,
      pIO,
      cChMode: (quantizationMode >> 3) & 3,
      numChannels: codecParms->numChannels,
      iPos: 0);
  if ( codecParms->subBands < SB_NO_LOWPASS )
  {
    WriteBits16(pIO, uiBits: (~codecParms->quantizationMode & 0x200) != 0, cBits: 1);
    v9 = codecParms->quantizationMode;
    if ( (v9 & 0x200) != 0 )
    {
      WriteBits16(pIO, uiBits: (~(_BYTE)v9 & 2) != 0, cBits: 1);
      v10 = codecParms->quantizationMode;
      if ( (v10 & 2) == 0 )
        WriteQuantizer(
          pQuantizer: codec->tileQuantization->pQuantizerLP,
          pIO,
          cChMode: (v10 >> 5) & 3,
          numChannels: codecParms->numChannels,
          iPos: 0);
    }
  }
  if ( codecParms->subBands < SB_NO_HIGHPASS )
  {
    WriteBits16(pIO, uiBits: (~codecParms->quantizationMode & 0x400) != 0, cBits: 1);
    v11 = codecParms->quantizationMode;
    if ( (v11 & 0x400) != 0 )
    {
      WriteBits16(pIO, uiBits: (~(_BYTE)v11 & 4) != 0, cBits: 1);
      v12 = codecParms->quantizationMode;
      if ( (v12 & 4) == 0 )
        WriteQuantizer(
          pQuantizer: codec->tileQuantization->pQuantizerHP,
          pIO,
          cChMode: (v12 >> 7) & 3,
          numChannels: codecParms->numChannels,
          iPos: 0);
    }
  }
  WriteUpToByte(pIO);
  return HDP_ERROR_NONE;
}


// ========================================================================
// SetUniformTiling
// EA  : 0x828F5C28
// RVA : 0x008F5C28
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenc.cpp
// ========================================================================

unsigned int __fastcall SetUniformTiling(unsigned int *pTile, unsigned int cNumTile, unsigned int cNumMB)
{
  unsigned int v3; // r10
  unsigned int v4; // r11
  unsigned int *v5; // r9
  int v6; // ctr
  unsigned int v7; // r7

  v3 = cNumMB;
  __twllei(cNumTile, 0);
  if ( (cNumTile + cNumMB - 1) / cNumTile > 0xFFFF )
  {
    do
      __twllei(++cNumTile, 0);
    while ( (cNumMB - 1 + cNumTile) / cNumTile > 0xFFFF );
  }
  v4 = cNumTile;
  if ( cNumTile > 1 )
  {
    v5 = pTile - 1;
    v6 = cNumTile - 1;
    do
    {
      __twllei(v4, 0);
      v7 = (v3 + v4 - 1) / v4;
      *++v5 = v7;
      v3 -= v7;
      --v4;
      --v6;
    }
    while ( v6 != 0 );
  }
  return cNumTile;
}


// ========================================================================
// ValidateTiling
// EA  : 0x828F5CA0
// RVA : 0x008F5CA0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenc.cpp
// ========================================================================

unsigned int __fastcall ValidateTiling(unsigned int *pTile, unsigned int cNumTile, unsigned int cNumMB)
{
  unsigned int v5; // r6
  int v6; // r8
  unsigned int v7; // r11
  unsigned int *v8; // r10
  unsigned int v9; // r9
  unsigned int *v10; // r11
  int v11; // ctr
  int v12; // r10
  int v13; // ctr
  unsigned int *v14; // r11
  unsigned int v15; // r10

  if ( pTile == nullptr )
    return 1;
  if ( cNumTile == 0 )
    cNumTile = 1;
  if ( cNumTile <= cNumMB )
  {
    if ( cNumTile > 0x1000 )
      cNumTile = 4096;
  }
  else
  {
    cNumTile = 1;
  }
  v5 = 0;
  v6 = 0;
  if ( cNumTile > 1 )
  {
    v7 = 1;
    v8 = pTile;
    while ( 1 )
    {
      v9 = *v8;
      if ( *v8 == 0 || v9 > 0xFFFF )
        break;
      v5 += v9;
      if ( v5 >= cNumMB )
      {
        cNumTile = v6 + 1;
        goto LABEL_18;
      }
      ++v7;
      ++v6;
      ++v8;
      if ( v7 >= cNumTile )
        goto LABEL_18;
    }
    cNumTile = SetUniformTiling(pTile, cNumTile, cNumMB);
  }
LABEL_18:
  if ( cNumMB - v5 > 0x10000 )
    cNumTile = SetUniformTiling(pTile, cNumTile, cNumMB);
  if ( cNumTile > 1 )
  {
    v10 = pTile;
    v11 = cNumTile - 1;
    do
    {
      v12 = v10[1] + *v10;
      *++v10 = v12;
      --v11;
    }
    while ( v11 != 0 );
  }
  if ( cNumTile != 1 )
  {
    v13 = cNumTile - 1;
    v14 = &pTile[cNumTile];
    do
    {
      v15 = *(v14 - 2);
      *--v14 = v15;
      --v13;
    }
    while ( v13 != 0 );
  }
  *pTile = 0;
  return cNumTile;
}


// ========================================================================
// ValidateArgs
// EA  : 0x828F5DE8
// RVA : 0x008F5DE8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenc.cpp
// ========================================================================

int __fastcall ValidateArgs(hdpImageInfo_t *imageInfo, hdpCodecParms_t *codecParms)
{
  unsigned int imageHeight; // r11
  hdpBitDepth_t bitDepth; // r11
  hdpBitDepth_t v6; // r11
  hdpColorFormat_t colorFormat; // r11
  hdpBitDepth_t v8; // r11
  unsigned int v9; // r3
  unsigned int numTilesHighMinusOne; // r11
  unsigned int v11; // r3
  unsigned int numChannels; // r7
  hdpColorFormat_t v13; // r11
  hdpColorFormat_t v14; // r11
  hdpBitDepth_t v15; // r11
  unsigned __int8 v16; // r11

  if ( imageInfo->imageWidth > 0x10000000 )
    return -1;
  imageHeight = imageInfo->imageHeight;
  if ( imageHeight > 0x10000000 )
    return -1;
  if ( imageInfo->imageWidth == 0 )
    return -1;
  if ( imageHeight == 0 )
    return -1;
  bitDepth = imageInfo->bitDepth;
  if ( bitDepth == BD_5
    && (imageInfo->colorFormat != CF_RGB || imageInfo->bitsPerUnit != 16 || imageInfo->leadingPadding != 0) )
  {
    return -1;
  }
  if ( bitDepth == BD_565
    && (imageInfo->colorFormat != CF_RGB || imageInfo->bitsPerUnit != 16 || imageInfo->leadingPadding != 0)
    || bitDepth == BD_10
    && (imageInfo->colorFormat != CF_RGB || imageInfo->bitsPerUnit != 32 || imageInfo->leadingPadding != 0) )
  {
    return -1;
  }
  if ( (bitDepth == BD_5 || bitDepth == BD_565 || bitDepth == BD_10)
    && codecParms->colorFormat != CF_YUV_420
    && codecParms->colorFormat != CF_YUV_422 )
  {
    codecParms->colorFormat = CF_YUV_444;
  }
  v6 = imageInfo->bitDepth;
  if ( v6 == BD_1 || v6 == BD_1alt )
  {
    if ( imageInfo->colorFormat == CF_Y_ONLY )
    {
      codecParms->colorFormat = CF_Y_ONLY;
      goto LABEL_27;
    }
    return -1;
  }
LABEL_27:
  if ( codecParms->hasAlphaChannel )
  {
    colorFormat = imageInfo->colorFormat;
    switch ( colorFormat )
    {
      case CF_YUV_420:
        return -1;
      case CF_YUV_422:
        return -1;
      case CF_BAYER:
        return -1;
      default:
        break;
    }
    v8 = imageInfo->bitDepth;
    if ( v8 == BD_5 || v8 == BD_10 || v8 == BD_1 || v8 == BD_1alt )
      return -1;
  }
  if ( codecParms->tileMacroblockOffsetX == nullptr )
  {
    codecParms->tileMacroblockOffsetX = defaultMacroblockOffset;
    codecParms->numTilesWideMinusOne = 0;
  }
  if ( codecParms->tileMacroblockOffsetY == nullptr )
  {
    codecParms->tileMacroblockOffsetY = defaultMacroblockOffset;
    codecParms->numTilesHighMinusOne = 0;
  }
  v9 = ValidateTiling(
         pTile: codecParms->tileMacroblockOffsetX,
         cNumTile: codecParms->numTilesWideMinusOne + 1,
         cNumMB: (imageInfo->imageWidth + 15) >> 4);
  numTilesHighMinusOne = codecParms->numTilesHighMinusOne;
  codecParms->numTilesWideMinusOne = v9 - 1;
  v11 = ValidateTiling(
          pTile: codecParms->tileMacroblockOffsetY,
          cNumTile: numTilesHighMinusOne + 1,
          cNumMB: (imageInfo->imageHeight + 15) >> 4);
  numChannels = codecParms->numChannels;
  codecParms->numTilesHighMinusOne = v11 - 1;
  if ( numChannels > 0x10 )
    return -1;
  v13 = imageInfo->colorFormat;
  if ( v13 == CF_Y_ONLY && codecParms->colorFormat != CF_Y_ONLY
    || codecParms->colorFormat == CF_YUV_422 && (unsigned int)v13 < CF_YUV_422
    || codecParms->colorFormat == CF_YUV_444 && (unsigned int)v13 <= CF_YUV_422
    || v13 == CF_N_CHANNEL )
  {
    codecParms->colorFormat = v13;
  }
  v14 = codecParms->colorFormat;
  if ( imageInfo->colorFormat == CF_CMYK )
  {
    if ( v14 == CF_BAYER || v14 == CF_N_CHANNEL )
    {
      codecParms->colorFormat = CF_CMYK;
LABEL_52:
      codecParms->numChannels = 4;
      goto LABEL_53;
    }
  }
  else if ( v14 == CF_N_CHANNEL )
  {
    goto LABEL_53;
  }
  if ( v14 != CF_Y_ONLY )
  {
    if ( v14 == CF_CMYK || v14 == CF_BAYER )
      goto LABEL_52;
    codecParms->numChannels = 3;
  }
  else
  {
    codecParms->numChannels = 1;
  }
LABEL_53:
  if ( codecParms->subBands >= SB_ISOLATED )
    codecParms->subBands = SB_ALL;
  if ( codecParms->uniformTrimFlexBits > 0xFu )
    codecParms->uniformTrimFlexBits = 15;
  if ( codecParms->mantissaLengthOrShift == 0 )
  {
    v15 = imageInfo->bitDepth;
    if ( v15 == BD_32S )
    {
      v16 = 10;
    }
    else
    {
      if ( v15 != BD_32F )
        goto LABEL_69;
      v16 = 13;
    }
    codecParms->mantissaLengthOrShift = v16;
  }
LABEL_69:
  if ( codecParms->exponentBias != 0 )
  {
    codecParms->exponentBias += 0x80;
    return 0;
  }
  else
  {
    codecParms->exponentBias = 4;
    return 0;
  }
}


// ========================================================================
// ?HDPEncInit@@YA?AW4hdpError_t@@PAUhdpImageInfo_t@@PAUhdpCodecParms_t@@PAPAUhdpCodec_t@@@Z
// EA  : 0x828F6140
// RVA : 0x008F6140
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenc.cpp
// ========================================================================

hdpError_t __fastcall HDPEncInit(hdpImageInfo_t *imageInfo, hdpCodecParms_t *codecParms, hdpCodec_t **codecOut)
{
  hdpError_t result; // r3
  unsigned int v7; // r25
  int v8; // r26
  unsigned int v9; // r30
  char *v10; // r3
  hdpCodec_t *v11; // r31
  hdpCodec_t *v12; // r30
  unsigned __int8 *v13; // r10
  hdpOrientation_t *p_orientation; // r11
  int i; // ctr
  unsigned int numChannels; // r4
  unsigned int *p_widthInMacroblocks; // r7
  unsigned int v18; // r11
  unsigned int v19; // r10
  __int16 **macroBlockRowBuffer1; // r9
  int v21; // r8
  unsigned int v22; // r10
  int v23; // r8
  char *v24; // r3
  hdpCodec_t *v25; // r31
  unsigned __int8 *v26; // r10
  hdpOrientation_t *v27; // r11
  int j; // ctr
  unsigned int v29; // r11
  unsigned int v30; // r7
  unsigned int imageHeight; // r9

  *codecOut = nullptr;
  result = ValidateArgs(imageInfo, codecParms);
  if ( result == HDP_ERROR_NONE )
  {
    v7 = (imageInfo->imageWidth + 15) >> 4;
    v8 = 32 * cblkChromas[codecParms->colorFormat];
    v9 = 2 * ((codecParms->numChannels - 1) * v8 + 512) * v7 + 1859;
    v10 = TempAlloc(codecParms, size: v9, align: 0x10u);
    v11 = (hdpCodec_t *)v10;
    if ( v10 == nullptr )
      return HDP_ERROR_OUT_OF_MEMORY;
    memset(Dst: v10, Val: 0, Size: v9);
    v12 = v11;
    v13 = &v11->MBInfo.pad[58];
    p_orientation = &imageInfo[-1].orientation;
    for ( i = 10; i != 0; --i )
    {
      ++p_orientation;
      v13 += 4;
      *(hdpOrientation_t *)v13 = *p_orientation;
    }
    memcpy(Dst: &v11->codecParms, Src: codecParms, Size: sizeof(v11->codecParms));
    numChannels = v11->codecParms.numChannels;
    p_widthInMacroblocks = &v11->widthInMacroblocks;
    v18 = 0;
    v11->widthInMacroblocks = (imageInfo->imageWidth + 15) >> 4;
    v19 = ((unsigned int)&v11[1].MBInfo.compactDCLP[3][15] + 1) & 0xFFFFFF80;
    v11->heightInMacroblocks = (imageInfo->imageHeight + 15) >> 4;
    if ( numChannels != 0 )
    {
      macroBlockRowBuffer1 = v11->macroBlockRowBuffer1;
      do
      {
        *(macroBlockRowBuffer1 - 16) = (__int16 *)v19;
        v21 = v8;
        if ( v18 == 0 )
          v21 = 512;
        v22 = *p_widthInMacroblocks * v21 + v19;
        v23 = v8;
        *macroBlockRowBuffer1 = (__int16 *)v22;
        if ( v18 == 0 )
          v23 = 512;
        ++v18;
        ++macroBlockRowBuffer1;
        v19 = *p_widthInMacroblocks * v23 + v22;
      }
      while ( v18 < v11->codecParms.numChannels );
    }
    v11->bitIOHeader = (hdpBitIO_t *)v19;
    result = InitImagePlaneEnc(codec: v11);
    if ( result == HDP_ERROR_NONE )
    {
      result = InitIOEnc(codec: v11);
      if ( result == HDP_ERROR_NONE )
      {
        InitContextBitIOs(codec: v11);
        result = WriteImagePlaneHeader(codec: v11, codecParms: &v11->codecParms, pIO: v11->bitIOHeader);
        if ( result == HDP_ERROR_NONE )
        {
          if ( !codecParms->hasAlphaChannel )
            goto LABEL_22;
          v24 = TempAlloc(codecParms, size: (v7 << 10) + 1819, align: 0x10u);
          v25 = (hdpCodec_t *)v24;
          if ( v24 == nullptr )
            return HDP_ERROR_OUT_OF_MEMORY;
          memset(Dst: v24, Val: 0, Size: (v7 << 10) + 1819);
          v26 = &v25->MBInfo.pad[58];
          v27 = &imageInfo[-1].orientation;
          for ( j = 10; j != 0; --j )
          {
            ++v27;
            v26 += 4;
            *(hdpOrientation_t *)v26 = *v27;
          }
          memcpy(Dst: &v25->codecParms, Src: codecParms, Size: sizeof(v25->codecParms));
          v25->codecParms.colorFormat = CF_Y_ONLY;
          v25->codecParms.numChannels = 1;
          v29 = ((unsigned int)&v25[1].MBInfo.compactDCLP[3][15] + 1) & 0xFFFFFF80;
          v30 = (imageInfo->imageWidth + 15) >> 4;
          v25->widthInMacroblocks = v30;
          imageHeight = imageInfo->imageHeight;
          v25->macroBlockRowBuffer0[0] = (__int16 *)v29;
          v25->heightInMacroblocks = (imageHeight + 15) >> 4;
          v25->macroBlockRowBuffer1[0] = (__int16 *)((v30 << 9) + v29);
          v25->bitIOHeader = v12->bitIOHeader;
          v25->nextCodec = nullptr;
          v25->isSecondaryCodec = true;
          v12->nextCodec = v25;
          result = InitImagePlaneEnc(codec: v25);
          if ( result == HDP_ERROR_NONE )
          {
            v25->tileIndex = v12->tileIndex;
            v25->tileStreams = v12->tileStreams;
            v25->bitIOHeader = v12->bitIOHeader;
            v25->tileBitIOs = v12->tileBitIOs;
            v25->numTileBitIOs = v12->numTileBitIOs;
            v25->numSubBands = v12->numSubBands;
            InitContextBitIOs(codec: v12);
            result = WriteImagePlaneHeader(codec: v25, codecParms: &v25->codecParms, pIO: v25->bitIOHeader);
            if ( result == HDP_ERROR_NONE )
            {
LABEL_22:
              *codecOut = v12;
              if ( v12->numTileBitIOs == 0 )
              {
                WriteBits16(pIO: v12->bitIOHeader, uiBits: 0xFFu, cBits: 8);
                WriteUpToByte(pIO: v12->bitIOHeader);
              }
              return HDP_ERROR_NONE;
            }
          }
        }
      }
    }
  }
  return result;
}


// ========================================================================
// ProcessMacroblockEnc
// EA  : 0x828F6450
// RVA : 0x008F6450
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenc.cpp
// ========================================================================

hdpError_t __fastcall ProcessMacroblockEnc(hdpCodec_t *firstCodec)
{
  unsigned __int8 v2; // r11
  hdpCodec_t *v3; // r31
  int v4; // r27
  hdpError_t result; // r3
  unsigned int currentMacroblockRow; // r10
  unsigned int currentTileRow; // r11
  unsigned int v8; // r29
  int v9; // r30
  unsigned int v10; // r3
  int v11; // r7

  if ( firstCodec->currentMacroblockColumn == 0 || (v2 = 0, firstCodec->currentMacroblockRow == 0) )
    v2 = 1;
  v3 = firstCodec;
  v4 = v2;
  do
  {
    v3->currentMacroblockRow = firstCodec->currentMacroblockRow;
    v3->currentMacroblockColumn = firstCodec->currentMacroblockColumn;
    FwdTransformMacroblock(codec: v3);
    if ( v4 == 0 )
    {
      UpdateTilePos(codec: v3, mbX: v3->currentMacroblockColumn - 1, mbY: v3->currentMacroblockRow - 1);
      if ( v3->atTileLeftMB && v3->atTileTopMB )
      {
        result = WriteTileHeader(codec: v3);
        if ( result != HDP_ERROR_NONE )
          return result;
      }
      result = QuantizeMacroblock(codec: v3);
      if ( result != HDP_ERROR_NONE )
        return result;
      result = EncodeMacroblock(
                 codec: v3,
                 context: &v3->tileContexts[v3->currentTileColumn],
                 mbX: v3->currentMacroblockColumn - 1,
                 mbY: v3->currentMacroblockRow - 1);
      if ( result != HDP_ERROR_NONE )
        return result;
      if ( v3->currentMacroblockColumn == v3->widthInMacroblocks )
      {
        currentMacroblockRow = v3->currentMacroblockRow;
        if ( (currentMacroblockRow == v3->heightInMacroblocks
           || (currentTileRow = v3->currentTileRow) < v3->codecParms.numTilesHighMinusOne
           && currentMacroblockRow == v3->codecParms.tileMacroblockOffsetY[currentTileRow + 1])
          && !v3->isSecondaryCodec )
        {
          v8 = 0;
          if ( v3->numTileBitIOs != 0 )
          {
            v9 = 0;
            do
            {
              WriteUpToByte(pIO: &v3->tileBitIOs[v9]);
              v10 = GetWritePos(pIO: &v3->tileBitIOs[v9++]);
              v11 = v3->numTileBitIOs * v3->currentTileRow + v8++;
              v3->tileIndex[v11] = v10;
            }
            while ( v8 < v3->numTileBitIOs );
          }
        }
      }
    }
    v3 = v3->nextCodec;
  }
  while ( v3 != nullptr );
  return HDP_ERROR_NONE;
}


// ========================================================================
// ?HDPEncEncodeMBRow@@YA?AW4hdpError_t@@PAUhdpCodec_t@@@Z
// EA  : 0x828F65F0
// RVA : 0x008F65F0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenc.cpp
// ========================================================================

hdpError_t __fastcall HDPEncEncodeMBRow(hdpCodec_t *firstCodec)
{
  unsigned int widthInMacroblocks; // r11
  unsigned __int8 v3; // r11
  hdpCodec_t *v4; // r31
  int v5; // r27
  hdpError_t result; // r3
  unsigned int currentMacroblockRow; // r10
  unsigned int currentTileRow; // r11
  unsigned int v9; // r29
  int v10; // r30
  unsigned int v11; // r3
  int v12; // r7
  unsigned int v13; // r9

  widthInMacroblocks = firstCodec->widthInMacroblocks;
  firstCodec->currentMacroblockColumn = 0;
  if ( widthInMacroblocks != 0 )
  {
    do
    {
      if ( firstCodec->currentMacroblockColumn == 0 || (v3 = 0, firstCodec->currentMacroblockRow == 0) )
        v3 = 1;
      v4 = firstCodec;
      v5 = v3;
      do
      {
        v4->currentMacroblockRow = firstCodec->currentMacroblockRow;
        v4->currentMacroblockColumn = firstCodec->currentMacroblockColumn;
        FwdTransformMacroblock(codec: v4);
        if ( v5 == 0 )
        {
          UpdateTilePos(codec: v4, mbX: v4->currentMacroblockColumn - 1, mbY: v4->currentMacroblockRow - 1);
          if ( v4->atTileLeftMB && v4->atTileTopMB )
          {
            result = WriteTileHeader(codec: v4);
            if ( result != HDP_ERROR_NONE )
              return result;
          }
          result = QuantizeMacroblock(codec: v4);
          if ( result != HDP_ERROR_NONE )
            return result;
          result = EncodeMacroblock(
                     codec: v4,
                     context: &v4->tileContexts[v4->currentTileColumn],
                     mbX: v4->currentMacroblockColumn - 1,
                     mbY: v4->currentMacroblockRow - 1);
          if ( result != HDP_ERROR_NONE )
            return result;
          if ( v4->currentMacroblockColumn == v4->widthInMacroblocks )
          {
            currentMacroblockRow = v4->currentMacroblockRow;
            if ( (currentMacroblockRow == v4->heightInMacroblocks
               || (currentTileRow = v4->currentTileRow) < v4->codecParms.numTilesHighMinusOne
               && currentMacroblockRow == v4->codecParms.tileMacroblockOffsetY[currentTileRow + 1])
              && !v4->isSecondaryCodec )
            {
              v9 = 0;
              if ( v4->numTileBitIOs != 0 )
              {
                v10 = 0;
                do
                {
                  WriteUpToByte(pIO: &v4->tileBitIOs[v10]);
                  v11 = GetWritePos(pIO: &v4->tileBitIOs[v10++]);
                  v12 = v4->numTileBitIOs * v4->currentTileRow + v9++;
                  v4->tileIndex[v12] = v11;
                }
                while ( v9 < v4->numTileBitIOs );
              }
            }
          }
        }
        v4 = v4->nextCodec;
      }
      while ( v4 != nullptr );
      AdvanceMacroblockColumnPtrs(firstCodec);
      v13 = firstCodec->currentMacroblockColumn + 1;
      firstCodec->currentMacroblockColumn = v13;
    }
    while ( v13 < firstCodec->widthInMacroblocks );
  }
  result = ProcessMacroblockEnc(firstCodec);
  if ( result == HDP_ERROR_NONE )
  {
    if ( firstCodec->currentMacroblockRow != 0 )
      SwapMacroblockPredPtrs(firstCodec);
    ++firstCodec->currentMacroblockRow;
    SwapMacroblockRowPtrs(firstCodec);
    return HDP_ERROR_NONE;
  }
  return result;
}


// ========================================================================
// ?HDPEncShutdown@@YA?AW4hdpError_t@@PAUhdpCodec_t@@@Z
// EA  : 0x828F6800
// RVA : 0x008F6800
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenc.cpp
// ========================================================================

hdpError_t __fastcall HDPEncShutdown(hdpCodec_t *firstCodec)
{
  hdpCodec_t *v1; // r31
  hdpError_t result; // r3
  hdpCodec_t *nextCodec; // r30

  v1 = firstCodec;
  firstCodec->currentMacroblockColumn = 0;
  InitMacroblockColumnPtrs(firstCodec);
  result = HDPEncEncodeMBRow(firstCodec: v1);
  if ( result == HDP_ERROR_NONE )
  {
    ShutdownIOEnc(codec: v1);
    do
    {
      nextCodec = v1->nextCodec;
      if ( v1->codecParms.changeSubsamplingUV )
      {
        if ( v1->resampleU != nullptr )
          idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v1->codecParms);
        if ( v1->resampleV != nullptr )
          idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v1->codecParms);
      }
      FreePredictionInfo(codec: v1);
      FreeCodingContexts(codec: v1);
      FreeTileQuantization(codec: v1);
      v1->codecParms.exponentBias += 0x80;
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v1->codecParms);
      v1 = nextCodec;
    }
    while ( nextCodec != nullptr );
    return HDP_ERROR_NONE;
  }
  return result;
}

