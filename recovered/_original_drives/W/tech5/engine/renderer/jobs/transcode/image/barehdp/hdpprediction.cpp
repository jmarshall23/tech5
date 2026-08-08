
// ========================================================================
// ?AllocatePredictionInfo@@YA?AW4hdpError_t@@PAUhdpCodec_t@@@Z
// EA  : 0x828F94F8
// RVA : 0x008F94F8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpprediction.cpp
// ========================================================================

int __fastcall AllocatePredictionInfo(hdpCodec_t *codec)
{
  unsigned int widthInMacroblocks; // r30
  unsigned int numChannels; // r29
  char *v4; // r3
  unsigned int v6; // ctr
  hdpPredictionInfo_t **v7; // r11
  int v8; // r9

  widthInMacroblocks = codec->widthInMacroblocks;
  numChannels = codec->codecParms.numChannels;
  v4 = TempAlloc(codecParms: &codec->codecParms, size: 48 * numChannels * widthInMacroblocks, align: 0x10u);
  if ( v4 == nullptr )
    return -2;
  codec->predInfoMemory = (hdpPredictionInfo_t *)v4;
  if ( numChannels != 0 )
  {
    v6 = numChannels;
    v7 = &codec->predInfoCurRow[15];
    v8 = 24 * widthInMacroblocks;
    do
    {
      *(v7 - 15) = (hdpPredictionInfo_t *)v4;
      *++v7 = (hdpPredictionInfo_t *)&v4[v8];
      v4 += v8 + v8;
      --v6;
    }
    while ( v6 != 0 );
  }
  return 0;
}


// ========================================================================
// ?FreePredictionInfo@@YAXPAUhdpCodec_t@@@Z
// EA  : 0x828F9580
// RVA : 0x008F9580
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpprediction.cpp
// ========================================================================

void __fastcall FreePredictionInfo(hdpCodec_t *codec)
{
  if ( codec->predInfoMemory != nullptr )
  {
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&codec->codecParms);
    codec->predInfoMemory = nullptr;
  }
}


// ========================================================================
// ?GetPredictionModeHP@@YAHPAUhdpCodec_t@@H@Z
// EA  : 0x828F95C8
// RVA : 0x008F95C8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpprediction.cpp
// ========================================================================

int __fastcall GetPredictionModeHP(hdpCodec_t *codec, int channel)
{
  __int16 *v2; // r11
  hdpColorFormat_t colorFormat; // r9
  int v4; // r10
  int v5; // r11
  __int16 v6; // r9
  __int16 v7; // r8

  v2 = codec->MBInfo.compactDCLP[channel];
  colorFormat = codec->codecParms.colorFormat;
  v4 = abs16(v2[3]) + abs16(v2[2]) + abs16(v2[1]);
  v5 = abs16(v2[12]) + abs16(v2[8]) + abs16(v2[4]);
  if ( colorFormat != CF_Y_ONLY && colorFormat != CF_N_CHANNEL )
  {
    v4 += abs16(codec->MBInfo.compactDCLP[2][1]) + abs16(codec->MBInfo.compactDCLP[1][1]);
    if ( colorFormat == CF_YUV_420 )
    {
      v6 = codec->MBInfo.compactDCLP[2][2];
      v7 = codec->MBInfo.compactDCLP[1][2];
    }
    else
    {
      if ( colorFormat == CF_YUV_422 )
      {
        v5 += abs16(codec->MBInfo.compactDCLP[2][6])
            + abs16(codec->MBInfo.compactDCLP[2][2])
            + abs16(codec->MBInfo.compactDCLP[1][6])
            + abs16(codec->MBInfo.compactDCLP[1][2]);
        v4 += abs16(codec->MBInfo.compactDCLP[2][5]) + abs16(codec->MBInfo.compactDCLP[1][5]);
        goto LABEL_9;
      }
      v6 = codec->MBInfo.compactDCLP[2][4];
      v7 = codec->MBInfo.compactDCLP[1][4];
    }
    v5 += abs16(v6) + abs16(v7);
  }
LABEL_9:
  if ( 4 * v4 >= v5 )
    return __CFADD__(4 * v5 - v4, v4 ^ 0x80000000) ? 0 : 2;
  else
    return 1;
}


// ========================================================================
// ?GetPredictionModeDCLP@@YAHPAUhdpCodec_t@@HI@Z
// EA  : 0x828F97B8
// RVA : 0x008F97B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpprediction.cpp
// ========================================================================

int __fastcall GetPredictionModeDCLP(hdpCodec_t *codec, int channel, unsigned int mbX)
{
  int v3; // r29
  int v5; // r9
  hdpColorFormat_t colorFormat; // r8
  unsigned int v7; // r11
  hdpPredictionInfo_t *v8; // r10
  __int16 iDC; // r7
  int v10; // r9
  int v11; // r7
  signed int v12; // r31
  hdpPredictionInfo_t *v13; // r10
  hdpPredictionInfo_t *v14; // r30
  hdpPredictionInfo_t *v15; // r9
  hdpPredictionInfo_t *v16; // r6
  int v17; // r11
  int v18; // r8
  __int16 v19; // r28
  __int16 v20; // r7
  __int16 v21; // r30

  v3 = 2;
  if ( codec->atTileLeftMB )
  {
    if ( codec->atTileTopMB )
      return 11;
    if ( codec->atTileLeftMB )
      goto LABEL_18;
  }
  if ( codec->atTileTopMB )
  {
LABEL_6:
    v5 = 0;
    v3 = codec->predInfoCurRow[channel][mbX - 1].iQPIndex == codec->MBInfo.quantizerIndexLP ? 0 : 2;
    return 4 * v3 + v5;
  }
  colorFormat = codec->codecParms.colorFormat;
  v7 = mbX;
  v8 = &codec->predInfoPrevRow[channel][mbX];
  iDC = v8[-1].iDC;
  v10 = iDC - v8->iDC;
  v11 = abs32(iDC - codec->predInfoCurRow[channel][mbX - 1].iDC);
  v12 = abs32(v10);
  if ( colorFormat != CF_Y_ONLY && colorFormat != CF_N_CHANNEL )
  {
    v13 = &codec->predInfoPrevRow[1][v7];
    v14 = &codec->predInfoCurRow[1][v7];
    v15 = &codec->predInfoPrevRow[2][v7];
    v16 = &codec->predInfoCurRow[2][v7];
    if ( colorFormat == CF_YUV_420 )
    {
      v17 = 8;
    }
    else
    {
      v17 = 4;
      if ( colorFormat != CF_YUV_422 )
        v17 = 2;
    }
    v18 = v17 * v11;
    v19 = v13[-1].iDC;
    v20 = v14[-1].iDC;
    v21 = v15[-1].iDC;
    v11 = abs32(v19 - v20) + abs32(v21 - v16[-1].iDC) + v18;
    v12 = abs32(v19 - v13->iDC) + abs32(v21 - v15->iDC) + v17 * v12;
  }
  if ( 4 * v11 < v12 )
  {
LABEL_18:
    v5 = 1;
    if ( codec->MBInfo.quantizerIndexLP != codec->predInfoPrevRow[channel][mbX].iQPIndex )
      return 4 * v3 + v5;
    return 5;
  }
  else
  {
    if ( 4 * v12 < v11 )
      goto LABEL_6;
    return 10;
  }
}


// ========================================================================
// ?UpdatePredictionInfo@@YAXPAUhdpCodec_t@@I@Z
// EA  : 0x828F99E8
// RVA : 0x008F99E8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpprediction.cpp
// ========================================================================

void __fastcall UpdatePredictionInfo(hdpCodec_t *codec, unsigned int mbX)
{
  hdpColorFormat_t colorFormat; // r11
  signed int numChannels; // r10
  signed int v4; // ctr
  __int16 **v5; // r8
  hdpCodec_t **p_nextCodec; // r11
  unsigned int v7; // r10

  colorFormat = codec->codecParms.colorFormat;
  if ( colorFormat == CF_YUV_420 || colorFormat == CF_YUV_422 )
    numChannels = 1;
  else
    numChannels = codec->codecParms.numChannels;
  if ( numChannels > 0 )
  {
    v4 = numChannels;
    v5 = &codec->macroBlockPrevColumnPtr[15];
    p_nextCodec = &codec[-1].nextCodec;
    do
    {
      v7 = (unsigned int)&(*++v5)[12 * mbX];
      *(_WORD *)(v7 + 8) = *((_WORD *)p_nextCodec + 4);
      *(_DWORD *)v7 = codec->MBInfo.quantizerIndexLP;
      *(_WORD *)(v7 + 10) = *((_WORD *)p_nextCodec + 5);
      *(_WORD *)(v7 + 12) = *((_WORD *)p_nextCodec + 6);
      *(_WORD *)(v7 + 14) = *((_WORD *)p_nextCodec + 7);
      *(_WORD *)(v7 + 16) = *((_WORD *)p_nextCodec + 8);
      *(_WORD *)(v7 + 18) = *((_WORD *)p_nextCodec + 12);
      p_nextCodec += 8;
      *(_WORD *)(v7 + 20) = *(_WORD *)p_nextCodec;
      --v4;
    }
    while ( v4 != 0 );
  }
}

