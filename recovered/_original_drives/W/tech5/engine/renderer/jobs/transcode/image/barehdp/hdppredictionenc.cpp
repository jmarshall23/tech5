
// ========================================================================
// ?PredictDCLPHPEnc@@YAXPAUhdpCodec_t@@@Z
// EA  : 0x828FA080
// RVA : 0x008FA080
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdppredictionenc.cpp
// ========================================================================

void __fastcall PredictDCLPHPEnc(hdpCodec_t *codec)
{
  hdpColorFormat_t colorFormat; // r31
  signed int numChannels; // r20
  unsigned int v4; // r26
  char PredictionModeDCLP; // r3
  int v6; // r22
  int v7; // r21
  int PredictionModeHP; // r3
  int v9; // r24
  __int16 *v10; // r28
  hdpPredictionInfo_t **predInfoPrevRow; // r25
  char v12; // r3
  __int16 v13; // r4
  __int16 v14; // r9
  hdpPredictionInfo_t *v15; // r11
  __int16 v16; // r4
  __int16 v17; // r9
  int v18; // r11
  int v19; // r11
  int v20; // r9
  int i; // r27
  int v22; // r10
  int j; // ctr
  int v24; // r6
  int v25; // r8
  int v26; // r7
  int v27; // r19
  int v28; // r18
  int v29; // r17
  int v30; // r9
  int v31; // r29
  int k; // r27
  int v33; // r10
  int v34; // ctr
  _WORD *v35; // r8
  int v36; // r6
  int v37; // r7
  int v38; // r18
  int v39; // r17
  int v40; // r16
  __int16 v41; // r14
  __int16 v42; // r19
  hdpColorFormat_t v43; // [sp+50h] [-A0h]

  colorFormat = codec->codecParms.colorFormat;
  v43 = colorFormat;
  if ( colorFormat == CF_YUV_420 || colorFormat == CF_YUV_422 )
    numChannels = 1;
  else
    numChannels = codec->codecParms.numChannels;
  v4 = codec->currentMacroblockColumn - 1;
  PredictionModeDCLP = GetPredictionModeDCLP(codec, channel: 0, mbX: v4);
  v6 = PredictionModeDCLP & 3;
  v7 = PredictionModeDCLP & 0xC;
  PredictionModeHP = GetPredictionModeHP(codec, channel: 0);
  v9 = 0;
  if ( numChannels > 0 )
  {
    v10 = &codec->MBInfo.compactDCLP[0][8];
    predInfoPrevRow = codec->predInfoPrevRow;
    while ( 1 )
    {
      if ( colorFormat == CF_N_CHANNEL && v9 > 0 )
      {
        v12 = GetPredictionModeDCLP(codec, channel: v9, mbX: v4);
        v6 = v12 & 3;
        v7 = v12 & 0xC;
        PredictionModeHP = GetPredictionModeHP(codec, channel: v9);
      }
      *(predInfoPrevRow - 208) = (hdpPredictionInfo_t *)(2 - PredictionModeHP);
      if ( v6 == 1 )
      {
        *(v10 - 8) -= (*predInfoPrevRow)[v4].iDC;
      }
      else if ( v6 != 0 )
      {
        if ( v6 == 2 )
          *(v10 - 8) -= ((*(predInfoPrevRow - 16))[v4 - 1].iDC + (*predInfoPrevRow)[v4].iDC) >> 1;
      }
      else
      {
        *(v10 - 8) -= (*(predInfoPrevRow - 16))[v4 - 1].iDC;
      }
      if ( v7 == 4 )
      {
        v13 = *v10;
        v14 = v10[4];
        v15 = &(*predInfoPrevRow)[v4];
        *(v10 - 4) -= v15->iLP[3];
        *v10 = v13 - v15->iLP[4];
        v10[4] = v14 - v15->iLP[5];
      }
      else if ( v7 == 0 )
      {
        v16 = *(v10 - 6);
        v17 = *(v10 - 5);
        v18 = (int)&(*(predInfoPrevRow - 16))[v4];
        *(v10 - 7) -= *(_WORD *)(v18 - 14);
        *(v10 - 6) = v16 - *(_WORD *)(v18 - 12);
        *(v10 - 5) = v17 - *(_WORD *)(v18 - 10);
      }
      v19 = (int)*(predInfoPrevRow - 32);
      if ( PredictionModeHP == 1 )
      {
        v20 = 10;
        for ( i = 4; i != 0; --i )
        {
          v22 = 48;
          for ( j = 3; j != 0; --j )
          {
            v24 = 2 * (v20 + v22);
            v25 = 2 * (v20 - 1 + v22);
            v26 = 2 * (v20 - 8 + v22);
            v27 = 2 * (v20 - 16 + v22);
            v28 = 2 * (v20 - 24 + v22);
            v29 = 2 * (v20 - 17 + v22);
            v22 -= 16;
            LOWORD(v28) = *(_WORD *)(v26 + v19) - *(_WORD *)(v28 + v19);
            LOWORD(v29) = *(_WORD *)(v25 + v19) - *(_WORD *)(v29 + v19);
            *(_WORD *)(v24 + v19) -= *(_WORD *)(v27 + v19);
            *(_WORD *)(v26 + v19) = v28;
            *(_WORD *)(v25 + v19) = v29;
          }
          v20 += 64;
        }
      }
      else if ( PredictionModeHP == 0 )
      {
        v30 = 5;
        v31 = v19 + 386;
        for ( k = 4; k != 0; --k )
        {
          v33 = 192;
          v34 = 3;
          v35 = (_WORD *)(v31 + 128);
          do
          {
            v36 = 2 * (v30 + v33);
            v37 = 2 * (v30 + 1 + v33);
            v38 = 2 * (v30 - 64 + v33);
            v39 = 2 * (v30 - 68 + v33);
            v40 = 2 * (v30 - 63 + v33);
            v33 -= 64;
            v41 = *(_WORD *)(v37 + v19);
            LOWORD(v40) = *(_WORD *)(v40 + v19);
            v42 = *(v35 - 64) - *(_WORD *)(v39 + v19);
            *(_WORD *)(v36 + v19) -= *(_WORD *)(v38 + v19);
            v35 -= 64;
            *v35 = v42;
            *(_WORD *)(v37 + v19) = v41 - v40;
            --v34;
          }
          while ( v34 != 0 );
          v31 += 32;
          v30 += 16;
        }
      }
      ++v9;
      ++predInfoPrevRow;
      v10 += 16;
      if ( v9 >= numChannels )
        break;
      colorFormat = v43;
    }
  }
}


// ========================================================================
// ?PredictHPCBPEnc@@YAXPAUhdpCodec_t@@PAUhdpContext_t@@HH@Z
// EA  : 0x828FA428
// RVA : 0x008FA428
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdppredictionenc.cpp
// ========================================================================

void __fastcall PredictHPCBPEnc(hdpCodec_t *codec, hdpContext_t *context, int mbX, int mbY)
{
  hdpColorFormat_t colorFormat; // r11
  signed int numChannels; // r10
  signed int v6; // ctr
  hdpAdaptiveCBPModelHP_t *p_adaptCBPModelHP; // r6
  int v8; // r10
  int v9; // r30
  __int16 **macroBlockPrevColumnPtr; // r29
  __int16 **v11; // r5
  char *v12; // r31
  unsigned int v13; // r11
  int v14; // r8
  __int16 v15; // r9
  int v16; // r4
  int v17; // r9
  int v18; // r7
  char *v19; // r9
  int v20; // r8
  int v21; // r7
  int v22; // r26
  int v23; // r7
  int v24; // r7
  int v25; // r9

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
    v9 = 12 * mbX;
    macroBlockPrevColumnPtr = codec->macroBlockPrevColumnPtr;
    while ( 1 )
    {
      v11 = &macroBlockPrevColumnPtr[v8];
      v12 = (char *)p_adaptCBPModelHP + v8 * 4;
      v13 = (unsigned int)macroBlockPrevColumnPtr[v8 - 224];
      *(_DWORD *)&macroBlockPrevColumnPtr[v8][v9 + 2] = v13;
      v14 = p_adaptCBPModelHP->countZeros[v8];
      v15 = (((unsigned __int16)((((unsigned __int16)(v13 - (((unsigned __int16)v13 >> 1) & 0x5555)) >> 2) & 0x3333)
                               + ((v13 - (((unsigned __int16)v13 >> 1) & 0x5555)) & 0x3333)) >> 4)
           + (((unsigned __int16)(v13 - (((unsigned __int16)v13 >> 1) & 0x5555)) >> 2) & 0x3333)
           + ((v13 - (((unsigned __int16)v13 >> 1) & 0x5555)) & 0x3333))
          & 0xF0F;
      v16 = (unsigned __int8)(HIBYTE(v15) + v15);
      if ( v14 != 0 )
      {
        if ( v14 != 1 )
          v13 ^= 0xFFFFu;
        goto LABEL_17;
      }
      if ( !codec->atTileLeftMB )
        break;
      if ( !codec->atTileTopMB )
      {
        v18 = *(int *)&v11[16][v9 + 2] >> 10;
LABEL_13:
        v17 = v18 & 1;
        goto LABEL_14;
      }
      v17 = 1;
LABEL_14:
      v13 ^= (2 * ((2 * ((2 * ((8 * (_WORD)v13) & 0x660 | v13 & 2)) | v13 & 0x3333)) | v13 & 0x11)) | v17;
LABEL_17:
      v19 = (char *)p_adaptCBPModelHP + v8 * 4;
      v20 = p_adaptCBPModelHP->countOnes[v8] - v16 + 13;
      v21 = p_adaptCBPModelHP->countOnes[v8 - 16];
      v22 = p_adaptCBPModelHP->countOnes[v8] - v16 + 29;
      p_adaptCBPModelHP->countOnes[v8] = v20;
      v23 = v21 + v16 - 3;
      *((_DWORD *)v19 - 16) = v23;
      v24 = (((unsigned __int8)((v23 - 16) & ~((v23 + 16) >> 31)) | (unsigned __int8)((15 - v23) >> 31)) & 0x1F) - 16;
      *((_DWORD *)v19 - 16) = v24;
      v25 = (((v20 - 16) & ~(v22 >> 31) | ((15 - v20) >> 31)) & 0x1F) - 16;
      p_adaptCBPModelHP->countOnes[v8] = v25;
      if ( v24 >= 0 )
      {
        *((_DWORD *)v12 + 16) = (v25 >> 31) & 2;
      }
      else if ( v24 >= v25 )
      {
        *((_DWORD *)v12 + 16) = 2;
      }
      else
      {
        *((_DWORD *)v12 + 16) = 1;
      }
      *(v11 - 208) = (__int16 *)v13;
      ++v8;
      if ( --v6 == 0 )
        return;
    }
    v18 = *(int *)&(*v11)[v9 - 10] >> 5;
    goto LABEL_13;
  }
}

