
// ========================================================================
// ?PredictDCLPDec@@YAXPAUhdpCodec_t@@@Z
// EA  : 0x828F9A78
// RVA : 0x008F9A78
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdppredictiondec.cpp
// ========================================================================

void __fastcall PredictDCLPDec(hdpCodec_t *codec)
{
  hdpColorFormat_t colorFormat; // r25
  signed int numChannels; // r26
  unsigned int currentMacroblockColumn; // r30
  char PredictionModeDCLP; // r3
  int v6; // r28
  int v7; // r6
  int v8; // r5
  hdpPredictionInfo_t **predInfoCurRow; // r29
  __int16 *v10; // r31
  char v11; // r3
  __int16 v12; // r9
  hdpPredictionInfo_t *v13; // r11
  __int16 v14; // r8
  __int16 v15; // r4
  __int16 v16; // r9
  int v17; // r11
  int PredictionModeHP; // r3
  int v19; // r31
  int *v20; // r30

  colorFormat = codec->codecParms.colorFormat;
  if ( colorFormat == CF_YUV_420 || colorFormat == CF_YUV_422 )
    numChannels = 1;
  else
    numChannels = codec->codecParms.numChannels;
  currentMacroblockColumn = codec->currentMacroblockColumn;
  PredictionModeDCLP = GetPredictionModeDCLP(codec, channel: 0, mbX: currentMacroblockColumn);
  v6 = 0;
  v7 = PredictionModeDCLP & 3;
  v8 = PredictionModeDCLP & 0xC;
  if ( numChannels > 0 )
  {
    predInfoCurRow = codec->predInfoCurRow;
    v10 = &codec->MBInfo.compactDCLP[0][8];
    do
    {
      if ( colorFormat == CF_N_CHANNEL && v6 > 0 )
      {
        v11 = GetPredictionModeDCLP(codec, channel: v6, mbX: currentMacroblockColumn);
        v7 = v11 & 3;
        v8 = v11 & 0xC;
      }
      if ( v7 == 1 )
      {
        *(v10 - 8) += predInfoCurRow[16][currentMacroblockColumn].iDC;
      }
      else if ( v7 != 0 )
      {
        if ( v7 == 2 )
          *(v10 - 8) += ((*predInfoCurRow)[currentMacroblockColumn - 1].iDC
                       + predInfoCurRow[16][currentMacroblockColumn].iDC) >> 1;
      }
      else
      {
        *(v10 - 8) += (*predInfoCurRow)[currentMacroblockColumn - 1].iDC;
      }
      if ( v8 == 4 )
      {
        v12 = v10[4];
        v13 = &predInfoCurRow[16][currentMacroblockColumn];
        v14 = *v10;
        *(v10 - 4) += v13->iLP[3];
        *v10 = v13->iLP[4] + v14;
        v10[4] = v12 + v13->iLP[5];
      }
      else if ( v8 == 0 )
      {
        v15 = *(v10 - 6);
        v16 = *(v10 - 5);
        v17 = (int)&(*predInfoCurRow)[currentMacroblockColumn];
        *(v10 - 7) += *(_WORD *)(v17 - 14);
        *(v10 - 6) = v15 + *(_WORD *)(v17 - 12);
        *(v10 - 5) = v16 + *(_WORD *)(v17 - 10);
      }
      ++v6;
      ++predInfoCurRow;
      v10 += 16;
    }
    while ( v6 < numChannels );
  }
  PredictionModeHP = GetPredictionModeHP(codec, channel: 0);
  v19 = 0;
  if ( numChannels > 0 )
  {
    v20 = &codec->MBInfo.residualCBP[15];
    do
    {
      if ( colorFormat == CF_N_CHANNEL && v19 > 0 )
        PredictionModeHP = GetPredictionModeHP(codec, channel: v19);
      ++v19;
      *++v20 = 2 - PredictionModeHP;
    }
    while ( v19 < numChannels );
  }
}


// ========================================================================
// ?PredictHPDec@@YAXPAUhdpCodec_t@@@Z
// EA  : 0x828F9CD0
// RVA : 0x008F9CD0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdppredictiondec.cpp
// ========================================================================

void __fastcall PredictHPDec(hdpCodec_t *codec)
{
  hdpColorFormat_t colorFormat; // r11
  unsigned int numChannels; // r11
  __int16 **macroBlockColumnPtr1; // r24
  unsigned int i; // r23
  __int16 *v5; // r11
  int v6; // r10
  int v7; // r29
  __int16 *v8; // r26
  int j; // r25
  __int16 v10; // r9
  __int16 v11; // r8
  int v12; // r10
  __int16 v13; // r7
  int k; // ctr
  int v15; // r5
  int v16; // r4
  int v17; // r6
  __int16 v18; // r3
  __int16 v19; // r8
  __int16 v20; // r7
  __int16 v21; // r3
  int v22; // r29
  _WORD *v23; // r27
  int m; // r26
  __int16 v25; // r9
  __int16 v26; // r8
  int v27; // r10
  __int16 v28; // r7
  _WORD *v29; // r6
  int n; // ctr
  int v31; // r4
  int v32; // r5

  colorFormat = codec->codecParms.colorFormat;
  if ( colorFormat == CF_YUV_420 || colorFormat == CF_YUV_422 )
    numChannels = 1;
  else
    numChannels = codec->codecParms.numChannels;
  if ( numChannels != 0 )
  {
    macroBlockColumnPtr1 = codec->macroBlockColumnPtr1;
    for ( i = numChannels; i != 0; --i )
    {
      v5 = *macroBlockColumnPtr1;
      v6 = 2 - (_DWORD)*(macroBlockColumnPtr1 - 160);
      if ( v6 == 1 )
      {
        v7 = 2;
        v8 = v5 + 2;
        for ( j = 4; j != 0; --j )
        {
          v10 = v8[8];
          v11 = *v8;
          v12 = 16;
          v13 = v8[7];
          for ( k = 3; k != 0; --k )
          {
            v15 = v7 + 8 + v12;
            v16 = v7 + v12;
            v17 = v7 + 7 + v12;
            v18 = v11;
            v19 = v13;
            v12 += 16;
            v20 = v5[v16] + v18;
            v21 = v5[v17] + v19;
            v11 = v20;
            v10 += v5[v15];
            v5[v16] = v20;
            v13 = v21;
            v5[v15] = v10;
            v5[v17] = v21;
          }
          v8 += 64;
          v7 += 64;
        }
      }
      else if ( v6 == 0 )
      {
        v22 = 6;
        v23 = v5 + 1;
        for ( m = 4; m != 0; --m )
        {
          v25 = v23[4];
          v26 = *v23;
          v27 = 64;
          v28 = v23[5];
          v29 = v23;
          for ( n = 3; n != 0; --n )
          {
            v31 = v22 - 1 + v27;
            v32 = v22 + v27;
            v27 += 64;
            v26 += v29[64];
            v25 += v5[v31];
            v28 += v5[v32];
            v29 += 64;
            *v29 = v26;
            v5[v31] = v25;
            v5[v32] = v28;
          }
          v23 += 16;
          v22 += 16;
        }
      }
      ++macroBlockColumnPtr1;
    }
  }
}


// ========================================================================
// ?PredictHPCBPDec@@YAXPAUhdpCodec_t@@PAUhdpContext_t@@HH@Z
// EA  : 0x828F9E78
// RVA : 0x008F9E78
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdppredictiondec.cpp
// ========================================================================

void __fastcall PredictHPCBPDec(hdpCodec_t *codec, hdpContext_t *context, int mbX, int mbY)
{
  hdpColorFormat_t colorFormat; // r11
  signed int numChannels; // r10
  signed int v6; // ctr
  hdpAdaptiveCBPModelHP_t *p_adaptCBPModelHP; // r6
  int v8; // r8
  int v9; // r30
  hdpPredictionInfo_t **predInfoCurRow; // r29
  char *v11; // r31
  hdpPredictionInfo_t **v12; // r4
  int v13; // r11
  int v14; // r7
  int v15; // r11
  int v16; // r9
  int v17; // r5
  int v18; // r11
  char *v19; // r11
  unsigned __int16 v20; // r10
  int v21; // r10
  int v22; // r5
  int v23; // r10
  int v24; // r10
  int v25; // r11

  colorFormat = codec->codecParms.colorFormat;
  if ( colorFormat == CF_YUV_420 || colorFormat == CF_YUV_422 )
    numChannels = 1;
  else
    numChannels = codec->codecParms.numChannels;
  if ( numChannels > 0 )
  {
    v6 = numChannels;
    p_adaptCBPModelHP = &context->adaptCBPModelHP;
    v8 = 16;
    v9 = mbX;
    predInfoCurRow = codec->predInfoCurRow;
    while ( 1 )
    {
      v11 = (char *)p_adaptCBPModelHP + v8 * 4;
      v12 = &predInfoCurRow[v8];
      v13 = p_adaptCBPModelHP->countZeros[v8];
      v14 = (int)predInfoCurRow[v8 - 224];
      if ( v13 != 0 )
      {
        if ( v13 == 2 )
          v14 ^= 0xFFFFu;
        goto LABEL_17;
      }
      if ( !codec->atTileLeftMB )
        break;
      if ( !codec->atTileTopMB )
      {
        v16 = (*v12)[v9].iCBP >> 10;
LABEL_13:
        v15 = v16 & 1 ^ v14;
        goto LABEL_14;
      }
      v15 = v14 ^ 1;
LABEL_14:
      v17 = (8 * ((2 * v15) & 2 ^ v15)) & 0x10 ^ (2 * v15) & 2 ^ v15;
      v18 = (((4 * ((2 * (_BYTE)v17) & 0x20 ^ (unsigned __int8)v17))
            & 0xCF
            ^ (2 * (_WORD)v17)
            & 0x20
            ^ (unsigned __int16)v17) << 6)
          & 0x3300
          ^ (4 * ((2 * (_BYTE)v17) & 0x20 ^ (unsigned __int8)v17))
          & 0xCF
          ^ (2 * v17)
          & 0x20
          ^ v17;
      v14 = (4 * (_WORD)v18) & 0xCC00 ^ v18;
LABEL_17:
      v19 = (char *)p_adaptCBPModelHP + v8 * 4;
      v20 = (((unsigned __int16)(v14 - (((unsigned __int16)v14 >> 1) & 0x5555)) >> 2) & 0x3333)
          + ((v14 - (((unsigned __int16)v14 >> 1) & 0x5555)) & 0x3333);
      v21 = (unsigned __int8)(((unsigned __int16)(((v20 >> 4) + v20) & 0xF0F) >> 8) + (((v20 >> 4) + v20) & 0xF));
      v22 = p_adaptCBPModelHP->countOnes[v8] - v21;
      v23 = p_adaptCBPModelHP->countOnes[v8 - 16] + v21 - 3;
      *((_DWORD *)v19 - 16) = v23;
      p_adaptCBPModelHP->countOnes[v8] = v22 + 13;
      v24 = (((unsigned __int8)((v23 - 16) & ~(unsigned __int8)((v23 + 16) >> 31)) | (unsigned __int8)((15 - v23) >> 31))
           & 0x1F)
          - 16;
      *((_DWORD *)v19 - 16) = v24;
      v25 = (((v22 - 3) & ~((v22 + 29) >> 31) | ((15 - (v22 + 13)) >> 31)) & 0x1F) - 16;
      p_adaptCBPModelHP->countOnes[v8] = v25;
      if ( v24 >= 0 )
      {
        *((_DWORD *)v11 + 16) = (v25 >> 31) & 2;
      }
      else if ( v24 >= v25 )
      {
        *((_DWORD *)v11 + 16) = 2;
      }
      else
      {
        *((_DWORD *)v11 + 16) = 1;
      }
      *(v12 - 240) = (hdpPredictionInfo_t *)v14;
      ++v8;
      (*(v12 - 16))[v9].iCBP = v14;
      if ( --v6 == 0 )
        return;
    }
    v16 = (*(v12 - 16))[v9 - 1].iCBP >> 5;
    goto LABEL_13;
  }
}

