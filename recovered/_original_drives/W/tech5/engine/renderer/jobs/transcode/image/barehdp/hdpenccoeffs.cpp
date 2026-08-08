
// ========================================================================
// ?DeriveHPCBP@@YAXPAUhdpCodec_t@@PAUhdpContext_t@@@Z
// EA  : 0x828F68D0
// RVA : 0x008F68D0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenccoeffs.cpp
// ========================================================================

void __fastcall DeriveHPCBP(hdpCodec_t *codec, hdpContext_t *context)
{
  int v2; // r27
  hdpColorFormat_t colorFormat; // r23
  __int16 *v4; // r28
  int *fixedLengthCodeBits; // r29
  int v6; // r10
  const int *v7; // r9
  int v8; // r31
  int v9; // r4
  const int *v10; // r7
  int i; // ctr
  int v12; // r9
  __int16 *v13; // r11

  v2 = 0;
  colorFormat = codec->codecParms.colorFormat;
  if ( (int)codec->codecParms.numChannels > 0 )
  {
    v4 = &codec->MBInfo.compactDCLP[15][14];
    fixedLengthCodeBits = context->adaptCNModelHP.fixedLengthCodeBits;
    do
    {
      if ( v2 <= 0 )
        goto LABEL_8;
      if ( colorFormat == CF_YUV_422 )
      {
        v6 = 8;
        v7 = blkOffsetUV_422;
        goto LABEL_9;
      }
      if ( colorFormat == CF_YUV_420 )
      {
        v6 = 4;
        v7 = blkOffsetUV_420;
      }
      else
      {
LABEL_8:
        v6 = 16;
        v7 = blkOffset;
      }
LABEL_9:
      v8 = 0;
      v9 = 1;
      v10 = v7;
      for ( i = v6; i != 0; --i )
      {
        v12 = 1;
        v13 = (__int16 *)(2 * *v10 + *((_DWORD *)v4 + 209) + 2);
        while ( *v13 + (1 << *fixedLengthCodeBits) - 1 < (unsigned int)(2 * ((1 << *fixedLengthCodeBits) - 1) + 1) )
        {
          ++v12;
          ++v13;
          if ( v12 >= 16 )
            goto LABEL_15;
        }
        v8 |= v9;
LABEL_15:
        ++v10;
        v9 = __ROL4__(v9, 1);
      }
      ++v2;
      v4 += 2;
      *(_DWORD *)v4 = v8;
      ++fixedLengthCodeBits;
    }
    while ( v2 < (signed int)codec->codecParms.numChannels );
  }
}


// ========================================================================
// EncodeHPCBP
// EA  : 0x828F69E0
// RVA : 0x008F69E0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenccoeffs.cpp
// ========================================================================

void __fastcall EncodeHPCBP(hdpCodec_t *codec, hdpContext_t *context)
{
  hdpColorFormat_t colorFormat; // r15
  signed int numChannels; // r11
  hdpBitIO_t *bitIOHP; // r25
  int v6; // r20
  int v7; // r19
  const int *encTable; // r17
  int *residualCBP; // r14
  const int *deltaTable; // r16
  int discriminant; // r21
  int v12; // r22
  int v13; // r11
  int v14; // r31
  unsigned __int16 v15; // r11
  int v16; // r30
  int v17; // r5
  int i; // r18
  int v19; // r31
  int v20; // r23
  int v21; // r11
  int v22; // r29
  int v23; // r10
  int v24; // r27
  const int *v25; // r26
  int v26; // r11
  int v27; // r30
  char v28; // r5
  unsigned int v29; // r4
  char v30; // r5
  unsigned int v31; // r4
  int v32; // r5
  int j; // r30
  unsigned __int16 v34; // r11
  const int *v35; // r11
  int v36; // r5
  signed int v38; // [sp+50h] [-A0h]
  hdpAdaptiveHuffman_t *v39; // [sp+54h] [-9Ch]

  colorFormat = codec->codecParms.colorFormat;
  if ( colorFormat == CF_N_CHANNEL || (numChannels = 1, colorFormat == CF_CMYK) )
    numChannels = codec->codecParms.numChannels;
  bitIOHP = context->bitIOHP;
  v6 = codec->MBInfo.residualCBP[1];
  v7 = codec->MBInfo.residualCBP[2];
  v39 = &context->adaptHuffCBP[1];
  if ( numChannels > 0 )
  {
    v38 = numChannels;
    encTable = context->adaptHuffCBP[1].encTable;
    residualCBP = codec->MBInfo.residualCBP;
    deltaTable = context->adaptHuffCBP[1].deltaTable;
    discriminant = context->adaptHuffCBP[1].discriminant;
    do
    {
      v12 = *residualCBP;
      v13 = *residualCBP;
      if ( colorFormat == CF_YUV_444 )
        v13 = v12 | v7 | v6;
      v14 = ((16 * (((v13 >> 8) & 0xF0) != 0))
           | (((16 * (((v13 >> 8) & 0xF) != 0))
             | (((16 * (((v13 >> 4) & 0xF) != 0)) | ((16 * ((v13 & 0xF) != 0)) >> 1)) >> 1)) >> 1)) >> 1;
      v15 = (((unsigned __int16)(v14 - (((unsigned __int16)v14 >> 1) & 0x5555)) >> 2) & 0x3333)
          + ((v14 - (((unsigned __int16)v14 >> 1) & 0x5555)) & 0x3333);
      v16 = (unsigned __int8)(((unsigned __int16)(((v15 >> 4) + v15) & 0xF0F) >> 8) + (((v15 >> 4) + v15) & 0xF));
      WriteBits16(pIO: bitIOHP, uiBits: encTable[2 * v16 + 1], cBits: encTable[2 * v16 + 2]);
      v17 = gTabLen[v14];
      discriminant += deltaTable[v16];
      if ( v17 != 0 )
        WriteBits16(pIO: bitIOHP, uiBits: gTabCode[v14], cBits: v17);
      for ( i = 4; i != 0; --i )
      {
        v19 = 0;
        v20 = 0;
        if ( colorFormat == CF_YUV_444 )
        {
          v20 = v7 & 0xF;
          v19 = v6 & 0xF;
          v6 >>= 4;
          v21 = (16 * ((2 * (v20 != 0)) | (v19 != 0))) | v12 & 0xF;
          v12 >>= 4;
          v7 >>= 4;
        }
        else
        {
          v21 = v12 & 0xF;
          v12 >>= 4;
        }
        if ( v21 != 0 )
        {
          v22 = v21 >> 4;
          v23 = v21 & 0xF;
          if ( colorFormat == CF_YUV_422 )
          {
            v19 = (v21 >> 4) & 3;
            v20 = (v21 >> 6) & 3;
            v22 = v19 != 0;
            if ( v20 != 0 )
              v22 += 2;
          }
          v24 = v23;
          v25 = &gTab0[v23];
          v26 = *v25;
          if ( v22 != 0 )
          {
            if ( v26 <= 2 )
              v27 = v26 + 5;
            else
              v27 = 8;
          }
          else
          {
            v27 = v26 - 1;
          }
          WriteBits16(
            pIO: bitIOHP,
            uiBits: context->adaptHuffCBP[0].encTable[2 * v27 + 1],
            cBits: context->adaptHuffCBP[0].encTable[2 * v27 + 2]);
          context->adaptHuffCBP[0].discriminant += context->adaptHuffCBP[0].deltaTable[v27];
          if ( v22 != 0 )
          {
            if ( v22 == 1 )
            {
              v28 = 1;
              v29 = 1;
            }
            else
            {
              v28 = 2;
              v29 = 3 - v22;
            }
            WriteBits16(pIO: bitIOHP, uiBits: v29, cBits: v28);
          }
          if ( v27 == 8 )
          {
            if ( *v25 == 3 )
            {
              v30 = 1;
              v31 = 1;
            }
            else
            {
              v30 = 2;
              v31 = 5 - *v25;
            }
            WriteBits16(pIO: bitIOHP, uiBits: v31, cBits: v30);
          }
          v32 = gFL0[v24];
          if ( v32 != 0 )
            WriteBits16(pIO: bitIOHP, uiBits: gCode0[v24], cBits: v32);
          if ( colorFormat == CF_YUV_444 )
          {
            for ( j = 2; j != 0; --j )
            {
              if ( v19 != 0 )
              {
                v34 = (((unsigned __int16)(v19 - (((unsigned __int16)v19 >> 1) & 0x5555)) >> 2) & 0x3333)
                    + ((v19 - (((unsigned __int16)v19 >> 1) & 0x5555)) & 0x3333);
                v35 = &context->adaptHuffCBP[2].encTable[2
                                                       * (unsigned __int8)(((unsigned __int16)(((v34 >> 4) + v34) & 0xF0F) >> 8)
                                                                         + (((v34 >> 4) + v34) & 0xF))
                                                       - 2];
                WriteBits16(pIO: bitIOHP, uiBits: v35[1], cBits: v35[2]);
                v36 = gTabLen[v19];
                if ( v36 != 0 )
                  WriteBits16(pIO: bitIOHP, uiBits: gTabCode[v19], cBits: v36);
              }
              v19 = v20;
            }
          }
        }
      }
      ++residualCBP;
    }
    while ( v38-- != 1 );
    v39->discriminant = discriminant;
  }
}


// ========================================================================
// EncodeLPCBP
// EA  : 0x828F6D90
// RVA : 0x008F6D90
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenccoeffs.cpp
// ========================================================================

void __fastcall EncodeLPCBP(hdpCodec_t *codec, hdpContext_t *context, int *iNumCoeffs)
{
  hdpColorFormat_t colorFormat; // r11
  signed int numChannels; // r31
  unsigned int v7; // r5
  hdpBitIO_t *bitIOHP; // r26
  int maxCount; // r28
  int zeroCount; // r27
  int v11; // r29
  unsigned int v12; // r31
  unsigned int v13; // r4
  unsigned int v14; // r11
  int v15; // r11
  int v16; // r11

  colorFormat = codec->codecParms.colorFormat;
  numChannels = codec->codecParms.numChannels;
  if ( colorFormat == CF_YUV_420 || (v7 = codec->codecParms.numChannels, colorFormat == CF_YUV_422) )
    v7 = 2;
  bitIOHP = context->bitIOHP;
  if ( colorFormat == CF_YUV_444 || colorFormat == CF_YUV_420 || colorFormat == CF_YUV_422 )
  {
    maxCount = context->adaptCBPModelLP.maxCount;
    zeroCount = context->adaptCBPModelLP.zeroCount;
    v11 = 4 * v7 - 5;
    v12 = (((-iNumCoeffs[1] & (unsigned int)~iNumCoeffs[1]) >> 30) & 2)
        + ((-*iNumCoeffs & (unsigned int)~*iNumCoeffs) >> 31);
    if ( v7 == 3 )
      v12 += ((-iNumCoeffs[2] & (unsigned int)~iNumCoeffs[2]) >> 29) & 4;
    if ( zeroCount <= 0 || maxCount < 0 )
    {
      v14 = v12;
      if ( maxCount < zeroCount )
        v14 = v11 - v12;
      if ( v14 != 0 )
      {
        if ( v14 == 1 )
        {
          v13 = (v7 + 1) & 6;
        }
        else
        {
          LOBYTE(v7) = v7 + 1;
          v13 = v14 + v11 + 1;
        }
      }
      else
      {
        LOBYTE(v7) = 1;
        v13 = 0;
      }
    }
    else
    {
      v13 = v12;
    }
    WriteBits16(pIO: context->bitIOHP, uiBits: v13, cBits: v7);
    v15 = maxCount - ((_cntlzw(v11 - v12) >> 3) & 4) + 1;
    if ( v15 >= -8 )
    {
      if ( v15 > 7 )
        v15 = 7;
    }
    else
    {
      v15 = -8;
    }
    context->adaptCBPModelLP.maxCount = v15;
    v16 = zeroCount - ((_cntlzw(v12) >> 3) & 4) + 1;
    if ( v16 >= -8 )
    {
      if ( v16 > 7 )
        v16 = 7;
      context->adaptCBPModelLP.zeroCount = v16;
    }
    else
    {
      context->adaptCBPModelLP.zeroCount = -8;
    }
  }
  else if ( numChannels > 0 )
  {
    do
    {
      WriteBits16(pIO: bitIOHP, uiBits: (-*iNumCoeffs & (unsigned int)~*iNumCoeffs) >> 31, cBits: 1);
      --numChannels;
      ++iNumCoeffs;
    }
    while ( numChannels != 0 );
  }
}


// ========================================================================
// EncodeBlock
// EA  : 0x828F6F40
// RVA : 0x008F6F40
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenccoeffs.cpp
// ========================================================================

hdpError_t __fastcall EncodeBlock(
        unsigned int *aLocalCoef,
        int iNumNonzero,
        hdpAdaptiveHuffman_t *adaptHuff,
        int bChroma,
        hdpBitIO_t *pOut,
        int iLocation)
{
  unsigned int v6; // r28
  int v12; // r15
  BOOL v13; // r26
  BOOL v14; // r27
  int v15; // r22
  hdpAdaptiveHuffman_t *v16; // r31
  int v17; // r29
  const int *deltaTable1; // r6
  int discriminant1; // r9
  int v20; // r20
  hdpAdaptiveHuffman_t *v21; // r31
  signed int v22; // r28
  int v23; // r11
  int i; // r29
  __int64 v25; // r6
  int v26; // r7
  int v27; // r29
  int v28; // r27
  int v29; // r11
  unsigned int v30; // r31
  unsigned int v31; // r4
  int v32; // r5
  int v33; // r11
  int v34; // r10
  int v35; // r11
  int v36; // r29
  int v37; // r21
  int v38; // r23
  const int *v39; // r26
  int v40; // r11
  int v41; // r31
  unsigned int v42; // r4
  int v43; // r5
  int v44; // r11
  int v45; // r10
  int v46; // r11
  int v47; // r29
  unsigned int v48; // r28
  hdpAdaptiveHuffman_t *v49; // r31
  BOOL v50; // r27
  unsigned int v51; // r10
  int v52; // r29
  const int *v53; // r5
  int v54; // r10
  int v55; // r11
  unsigned int v56; // r5
  hdpAdaptiveHuffman_t *v57; // r31
  signed int v58; // r28
  int v59; // r11
  int j; // r29
  __int64 v61; // r6
  int v62; // r7
  int v63; // r29
  int v64; // r27

  v6 = aLocalCoef[1];
  v12 = (unsigned __int8)bChroma + ((2 * bChroma) & 0x1FE);
  v13 = (_cntlzw(*aLocalCoef) & 0x20) != 0;
  v14 = v6 + 1 > 2;
  v15 = 1;
  if ( iNumNonzero == 1 )
  {
    v15 = 0;
  }
  else if ( (int)aLocalCoef[2] > 0 )
  {
    v15 = 2;
  }
  v16 = &adaptHuff[v12];
  v17 = 2 * (2 * v15 + v14) + v13;
  WriteBits16(pIO: pOut, uiBits: 2 * v16->encTable[2 * v17 + 1] + (v6 >> 31), cBits: v16->encTable[2 * v17 + 2] + 1);
  deltaTable1 = v16->deltaTable1;
  discriminant1 = v16->discriminant1;
  v20 = v15 & v13;
  v16->discriminant += v16->deltaTable[v17];
  v16->discriminant1 = deltaTable1[v17] + discriminant1;
  if ( v14 )
  {
    v21 = &adaptHuff[v20 + 6];
    v22 = abs32(v6) - 2;
    if ( v22 < 16 )
    {
      v26 = gSignificantAbsLevelRemap_0[v22];
      v27 = 4 * v26;
      v28 = gSignificantAbsLevelFixedLength_0[v26];
      WriteBits16(pIO: pOut, uiBits: v21->encTable[2 * v26 + 1], cBits: v21->encTable[2 * v26 + 2]);
      LODWORD(v25) = v21->deltaTable;
      HIDWORD(v25) = v28;
      v21->discriminant += *(_DWORD *)(v25 + v27);
    }
    else
    {
      v23 = v22 >> 5;
      for ( i = 4; v23 != 0; ++i )
        v23 >>= 1;
      WriteBits16(pIO: pOut, uiBits: *((_DWORD *)v21->encTable + 13), cBits: *((_DWORD *)v21->encTable + 14));
      v21->discriminant += *((_DWORD *)v21->deltaTable + 6);
      if ( i <= 18 )
      {
        WriteBits16(pIO: pOut, uiBits: i - 4, cBits: 4);
        HIDWORD(v25) = i;
      }
      else
      {
        WriteBits16(pIO: pOut, uiBits: 0xFu, cBits: 4);
        if ( i <= 21 )
        {
          WriteBits16(pIO: pOut, uiBits: i - 19, cBits: 2);
        }
        else
        {
          WriteBits16(pIO: pOut, uiBits: 3u, cBits: 2);
          WriteBits16(pIO: pOut, uiBits: i - 22, cBits: 3);
        }
        HIDWORD(v25) = i;
      }
    }
    WriteBits32(pIO: pOut, uiBits: v22, cBits: v25);
  }
  if ( !v13 )
  {
    v29 = 15 - iLocation;
    v30 = *aLocalCoef;
    if ( 15 - iLocation >= 5 )
    {
      v33 = gSignificantRunBin[v29];
      v34 = 5 * v33;
      v35 = gSignificantRunRemap_0[14 * v33 - 1 + v30];
      v36 = gSignificantRunFixedLength[v34 + v35];
      WriteBits16(pIO: pOut, uiBits: gSignificantRunBits[v35], cBits: gSignificantRunNumBits_0[v35]);
      LOBYTE(v32) = v36;
      v31 = v30 + 1;
    }
    else
    {
      if ( v29 <= 1 )
        goto LABEL_23;
      v31 = v30 != v29;
      v32 = gSignificantRunShortLength[v29 - v30] + v29 - 4;
    }
    WriteBits16(pIO: pOut, uiBits: v31, cBits: v32);
  }
LABEL_23:
  v37 = 1;
  v38 = *aLocalCoef + iLocation + 1;
  if ( iNumNonzero > 1 )
  {
    v39 = (const int *)(aLocalCoef + 2);
    do
    {
      if ( v15 == 2 )
      {
        v40 = 15 - v38;
        v41 = *v39;
        if ( 15 - v38 >= 5 )
        {
          v44 = gSignificantRunBin[v40];
          v45 = 5 * v44;
          v46 = gSignificantRunRemap_0[14 * v44 - 1 + v41];
          v47 = gSignificantRunFixedLength[v45 + v46];
          WriteBits16(pIO: pOut, uiBits: gSignificantRunBits[v46], cBits: gSignificantRunNumBits_0[v46]);
          LOBYTE(v43) = v47;
          v42 = v41 + 1;
          goto LABEL_30;
        }
        if ( v40 > 1 )
        {
          v42 = v41 != v40;
          v43 = gSignificantRunShortLength[v40 - v41] + v40 - 4;
LABEL_30:
          WriteBits16(pIO: pOut, uiBits: v42, cBits: v43);
        }
      }
      v15 = 1;
      v38 += *v39 + 1;
      if ( v37 == iNumNonzero - 1 )
      {
        v15 = 0;
      }
      else if ( v39[2] > 0 )
      {
        v15 = 2;
      }
      v48 = v39[1];
      v49 = &adaptHuff[v20 + v12 + 1];
      v50 = v48 + 1 > 2;
      v51 = v48 >> 31;
      v52 = 2 * v15 + v50;
      if ( v38 >= 15 )
      {
        if ( v38 == 15 )
        {
          v55 = 2 * gIndexCode[v52];
          v56 = gIndexLen[v52] + 1;
        }
        else
        {
          v55 = 2 * v52;
          LOBYTE(v56) = 2;
        }
        WriteBits16(pIO: pOut, uiBits: v55 + v51, cBits: v56);
      }
      else
      {
        WriteBits16(pIO: pOut, uiBits: 2 * v49->encTable[2 * v52 + 1] + v51, cBits: v49->encTable[2 * v52 + 2] + 1);
        v53 = v49->deltaTable1;
        v54 = v49->discriminant1;
        v49->discriminant += v49->deltaTable[v52];
        v49->discriminant1 = v53[v52] + v54;
      }
      v20 &= v15;
      if ( v50 )
      {
        v57 = &adaptHuff[v20 + 6];
        v58 = abs32(v48) - 2;
        if ( v58 < 16 )
        {
          v62 = gSignificantAbsLevelRemap_0[v58];
          v63 = 4 * v62;
          v64 = gSignificantAbsLevelFixedLength_0[v62];
          WriteBits16(pIO: pOut, uiBits: v57->encTable[2 * v62 + 1], cBits: v57->encTable[2 * v62 + 2]);
          LODWORD(v61) = v57->deltaTable;
          HIDWORD(v61) = v64;
          v57->discriminant += *(_DWORD *)(v61 + v63);
        }
        else
        {
          v59 = v58 >> 5;
          for ( j = 4; v59 != 0; ++j )
            v59 >>= 1;
          WriteBits16(pIO: pOut, uiBits: *((_DWORD *)v57->encTable + 13), cBits: *((_DWORD *)v57->encTable + 14));
          v57->discriminant += *((_DWORD *)v57->deltaTable + 6);
          if ( j <= 18 )
          {
            WriteBits16(pIO: pOut, uiBits: j - 4, cBits: 4);
            HIDWORD(v61) = j;
          }
          else
          {
            WriteBits16(pIO: pOut, uiBits: 0xFu, cBits: 4);
            if ( j <= 21 )
            {
              WriteBits16(pIO: pOut, uiBits: j - 19, cBits: 2);
            }
            else
            {
              WriteBits16(pIO: pOut, uiBits: 3u, cBits: 2);
              WriteBits16(pIO: pOut, uiBits: j - 22, cBits: 3);
            }
            HIDWORD(v61) = j;
          }
        }
        WriteBits32(pIO: pOut, uiBits: v58, cBits: v61);
      }
      ++v37;
      v39 += 2;
    }
    while ( v37 < iNumNonzero );
  }
  return HDP_ERROR_NONE;
}


// ========================================================================
// AdaptiveScan
// EA  : 0x828F7518
// RVA : 0x008F7518
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenccoeffs.cpp
// ========================================================================

int __fastcall AdaptiveScan(
        const __int16 *pCoeffs,
        int *pResidual,
        hdpAdaptiveScan_t *pScan,
        int iModelBits,
        int iTrimBits,
        int *pRLCoeffs,
        int iCount)
{
  int v8; // r10
  int v9; // r7
  __int16 v10; // r4
  hdpAdaptiveScan_t *v11; // r11
  hdpAdaptiveScan_t v12; // r6
  int *v13; // r9
  __int16 v14; // r4
  int v15; // r8
  unsigned int v16; // r4
  unsigned int v17; // r6
  unsigned int v18; // r3
  int result; // r3
  int v20; // r7
  int v21; // r3
  __int16 v22; // r31
  int v23; // r4
  unsigned int v24; // r30
  int v25; // r11
  hdpAdaptiveScan_t *v26; // r10
  int v27; // r31
  int *v28; // r5
  __int16 v29; // r8
  int v30; // r11
  unsigned int v31; // r29
  hdpAdaptiveScan_t v32; // r9
  unsigned int v33; // r28
  int v34; // r11
  bool v35; // zf
  unsigned int scanIndex; // r10
  int v37; // r30
  __int16 v38; // r29
  unsigned int v39; // r28
  int v40; // r11
  int v41; // r31
  unsigned int v42; // r26
  unsigned int v43; // r10
  hdpAdaptiveScan_t *v44; // r5
  int v45; // r29
  int *v46; // r8
  unsigned int v47; // r10
  unsigned int v48; // r26
  hdpAdaptiveScan_t v49; // r11
  int v50; // r9
  int v51; // r9
  unsigned int v52; // r11
  unsigned int scanTotal; // r26
  unsigned int v54; // r11
  unsigned int v55; // r25
  unsigned int v56; // r11

  if ( iModelBits != 0 )
  {
    if ( iModelBits > iTrimBits )
    {
      scanIndex = pScan[1].scanIndex;
      result = 0;
      v37 = (1 << iModelBits) - 1;
      v38 = pCoeffs[scanIndex];
      v39 = 2 * v37 + 1;
      if ( v38 + v37 < v39 )
      {
        v42 = scanIndex;
        v41 = 1;
        v43 = ((int)(v38 - ((unsigned int)v38 >> 31)) >> iTrimBits) + ((unsigned int)v38 >> 31);
        pResidual[v42] = 4 * (-(v43 >> 31) ^ v43) + (v43 != 0) + (-(v43 >> 31) & 6);
      }
      else
      {
        result = 1;
        v40 = abs16(v38);
        v41 = 0;
        pResidual[scanIndex] = 2 * ((v40 & (unsigned int)v37) >> iTrimBits);
        ++pScan[1].scanTotal;
        *pRLCoeffs = 0;
        pRLCoeffs[1] = ((v40 >> iModelBits) ^ -((unsigned int)v38 >> 31)) + ((unsigned int)v38 >> 31);
      }
      if ( iCount > 2 )
      {
        v44 = pScan + 2;
        v45 = iCount - 2;
        v46 = &pRLCoeffs[2 * result - 1];
        do
        {
          v47 = v44->scanIndex;
          v48 = v47;
          v49.scanIndex = pCoeffs[v47];
          v49.scanTotal = -(v49.scanIndex >> 31);
          if ( v49.scanIndex + v37 < v39 )
          {
            ++v41;
            v56 = ((signed int)(v49.scanIndex - (v49.scanIndex >> 31)) >> iTrimBits) + (v49.scanIndex >> 31);
            pResidual[v48] = 4 * (-(v56 >> 31) ^ v56) + (v56 != 0) + (-(v56 >> 31) & 6);
          }
          else
          {
            v50 = (-(v49.scanIndex >> 31) ^ v49.scanIndex) + (v49.scanIndex >> 31);
            v52 = (v50 & (unsigned int)v37) >> iTrimBits;
            v51 = v50 >> iModelBits;
            pResidual[v48] = 2 * v52;
            scanTotal = v44[-1].scanTotal;
            v54 = v44->scanTotal + 1;
            v44->scanTotal = v54;
            if ( v54 > scanTotal )
            {
              v49 = *v44;
              v55 = v44[-1].scanIndex;
              v44->scanTotal = scanTotal;
              v44[-1] = v49;
              v44->scanIndex = v55;
            }
            v46[1] = v41;
            ++result;
            v41 = 0;
            v46 += 2;
            *v46 = (v51 ^ v49.scanTotal) - v49.scanTotal;
          }
          --v45;
          ++v44;
        }
        while ( v45 != 0 );
      }
    }
    else
    {
      v20 = 1;
      v21 = (1 << iModelBits) - 1;
      v22 = pCoeffs[pScan[1].scanIndex];
      v23 = 0;
      v24 = 2 * v21 + 1;
      if ( v22 + v21 >= v24 )
      {
        ++pScan[1].scanTotal;
        *pRLCoeffs = 0;
        v25 = (int)abs16(v22) >> iModelBits;
        if ( v22 < 0 )
          v25 = -v25;
        pRLCoeffs[1] = v25;
        v23 = 1;
        v20 = 0;
      }
      if ( iCount > 2 )
      {
        v26 = pScan + 2;
        v27 = iCount - 2;
        v28 = &pRLCoeffs[2 * v23 - 1];
        do
        {
          ++v20;
          v29 = pCoeffs[v26->scanIndex];
          v30 = v29;
          if ( v29 + v21 >= v24 )
          {
            v31 = v26[-1].scanTotal;
            v32.scanIndex = v26->scanTotal + 1;
            v26->scanTotal = v32.scanIndex;
            v32.scanTotal = (int)abs16(v29) >> iModelBits;
            if ( v32.scanIndex > v31 )
            {
              v32 = *v26;
              v33 = v26[-1].scanIndex;
              v26->scanTotal = v31;
              v26[-1] = v32;
              v26->scanIndex = v33;
            }
            v28[1] = v20 - 1;
            v35 = v30 < 0;
            v34 = -v32.scanTotal;
            if ( !v35 )
              v34 = v32.scanTotal;
            v28 += 2;
            *v28 = v34;
            ++v23;
            v20 = 0;
          }
          --v27;
          ++v26;
        }
        while ( v27 != 0 );
      }
      return v23;
    }
  }
  else
  {
    v8 = 1;
    v9 = 0;
    v10 = pCoeffs[pScan[1].scanIndex];
    if ( v10 != 0 )
    {
      v9 = 1;
      v8 = 0;
      ++pScan[1].scanTotal;
      *pRLCoeffs = 0;
      pRLCoeffs[1] = v10;
    }
    if ( iCount > 2 )
    {
      v11 = pScan + 2;
      v12.scanTotal = iCount - 2;
      v13 = &pRLCoeffs[2 * v9 - 1];
      do
      {
        ++v8;
        v14 = pCoeffs[v11->scanIndex];
        v15 = v14;
        if ( v14 != 0 )
        {
          v16 = v11[-1].scanTotal;
          v17 = v11->scanTotal + 1;
          v11->scanTotal = v17;
          if ( v17 > v16 )
          {
            v12 = *v11;
            v18 = v11[-1].scanIndex;
            v11->scanTotal = v16;
            v11[-1] = v12;
            v11->scanIndex = v18;
          }
          ++v9;
          v13[1] = v8 - 1;
          v8 = 0;
          v13 += 2;
          *v13 = v15;
        }
        --v12.scanTotal;
        ++v11;
      }
      while ( v12.scanTotal != 0 );
    }
    return v9;
  }
  return result;
}


// ========================================================================
// EncodeMacroblockHighPass
// EA  : 0x828F78E8
// RVA : 0x008F78E8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenccoeffs.cpp
// ========================================================================

hdpError_t __fastcall EncodeMacroblockHighPass(hdpCodec_t *codec, hdpContext_t *context, int mbX, int mbY)
{
  hdpColorFormat_t colorFormat; // r19
  hdpCodec_t *v5; // r23
  unsigned int numChannels; // r25
  int v10; // r21
  hdpStreamLayout_t streamLayout; // r11
  unsigned __int8 cBitsHP; // r29
  int quantizerIndexHP; // r30
  char v14; // r5
  hdpBitIO_t *bitIOHP; // r31
  hdpBitIO_t *v16; // r3
  unsigned int v17; // r4
  hdpCodec_t *v18; // r3
  int trimTileFlexBits; // r28
  int *v20; // r24
  int *fixedLengthCodeBits; // r14
  int *actualCBP; // r17
  hdpAdaptiveScan_t *v23; // r18
  int v24; // r22
  int v25; // r30
  int v26; // r20
  int v27; // r25
  const int *v28; // r16
  int i; // r15
  const int *v30; // r23
  int v31; // r19
  int v32; // r11
  int v33; // r10
  int v34; // r29
  int v35; // r3
  hdpBitIO_t *v36; // r7
  const int *v37; // r31
  const int *v38; // r31
  char v39; // r5
  __int16 v40; // r9
  int v41; // r10
  unsigned int v42; // r4
  int v44; // [sp+50h] [-1C0h]
  signed int v45; // [sp+54h] [-1BCh]
  hdpColorFormat_t v46; // [sp+58h] [-1B8h]
  unsigned int v47; // [sp+60h] [-1B0h]
  int v48[16]; // [sp+70h] [-1A0h] BYREF
  int v49[16]; // [sp+B0h] [-160h] BYREF
  unsigned int v50[72]; // [sp+F0h] [-120h] BYREF

  colorFormat = codec->codecParms.colorFormat;
  v5 = codec;
  numChannels = codec->codecParms.numChannels;
  v46 = colorFormat;
  v47 = numChannels;
  if ( colorFormat == CF_YUV_420 || colorFormat == CF_YUV_422 )
    v45 = 1;
  else
    v45 = codec->codecParms.numChannels;
  v10 = 0;
  streamLayout = codec->codecParms.streamLayout;
  memset(v48, 0, sizeof(v48));
  if ( streamLayout == SL_FREQUENCY )
  {
    cBitsHP = codec->tileQuantization[codec->currentTileColumn].cBitsHP;
    if ( cBitsHP != 0 )
    {
      quantizerIndexHP = codec->MBInfo.quantizerIndexHP;
      v14 = 1;
      bitIOHP = context->bitIOHP;
      v16 = bitIOHP;
      if ( v5->MBInfo.quantizerIndexHP != 0 )
      {
        WriteBits16(pIO: bitIOHP, uiBits: 1u, cBits: 1);
        v14 = cBitsHP;
        v17 = quantizerIndexHP - 1;
        v16 = bitIOHP;
      }
      else
      {
        v17 = 0;
      }
      WriteBits16(pIO: v16, uiBits: v17, cBits: v14);
    }
  }
  if ( v5->resetAdaptiveScanTotals )
    ResetAdaptiveScanTotalsHP(context);
  DeriveHPCBP(codec: v5, context);
  PredictHPCBPEnc(codec: v18, context, mbX, mbY);
  EncodeHPCBP(codec: v5, context);
  v44 = 0;
  trimTileFlexBits = context->trimTileFlexBits;
  if ( v45 > 0 )
  {
    v20 = v48;
    fixedLengthCodeBits = context->adaptCNModelHP.fixedLengthCodeBits;
    actualCBP = v5->MBInfo.actualCBP;
    while ( 1 )
    {
      v23 = context->adaptScanVerHP[0];
      if ( actualCBP[32] != 1 )
        v23 = context->adaptScanHorHP[0];
      v24 = *fixedLengthCodeBits;
      v25 = 0;
      v26 = *actualCBP;
      v27 = 0;
      if ( trimTileFlexBits <= *fixedLengthCodeBits && v5->codecParms.subBands < SB_NO_FLEXBITS )
      {
        v25 = v24 - trimTileFlexBits;
        v27 = (1 << (v24 - trimTileFlexBits)) - 1;
      }
      if ( v44 > 0 && (colorFormat == CF_YUV_444 || colorFormat == CF_YUV_422 || colorFormat == CF_YUV_420) )
        v10 = 1;
      v28 = blkOffset;
      for ( i = 4; i != 0; --i )
      {
        v30 = v28;
        v31 = 4;
        v28 += 4;
        do
        {
          v32 = actualCBP[208];
          v33 = 2 * *v30;
          v34 = v33 + v32;
          if ( (v26 & 1) != 0 )
          {
            v35 = AdaptiveScan(
                    pCoeffs: (const __int16 *)(v33 + v32),
                    pResidual: v49,
                    pScan: v23,
                    iModelBits: v24,
                    iTrimBits: trimTileFlexBits,
                    pRLCoeffs: (int *)v50,
                    iCount: 16);
            v36 = context->bitIOHP;
            *v20 += v35;
            EncodeBlock(
              aLocalCoef: v50,
              iNumNonzero: v35,
              adaptHuff: context->adaptHuffHP,
              bChroma: v10,
              pOut: v36,
              iLocation: 1);
            if ( v25 != 0 )
            {
              v37 = &coeffOrderHP[1];
              do
              {
                WriteBits16(pIO: context->bitIOFL, uiBits: v49[*v37] >> 1, cBits: (v49[*v37] & 1) + v25);
                ++v37;
              }
              while ( (int)v37 < (int)idxCC );
            }
          }
          else if ( v25 != 0 )
          {
            v38 = &coeffOrderHP[1];
            do
            {
              v39 = v25;
              v40 = *(_WORD *)(2 * *v38 + v34);
              v41 = (int)abs16(v40) >> trimTileFlexBits;
              v42 = v41 & v27;
              if ( v41 != 0 )
              {
                v39 = v25 + 1;
                v42 = ((unsigned int)v40 >> 31) + 2 * v42;
              }
              WriteBits16(pIO: context->bitIOFL, uiBits: v42, cBits: v39);
              ++v38;
            }
            while ( (int)v38 < (int)idxCC );
          }
          v26 >>= 1;
          --v31;
          ++v30;
        }
        while ( v31 != 0 );
      }
      ++actualCBP;
      ++v20;
      v5 = codec;
      colorFormat = v46;
      ++fixedLengthCodeBits;
      if ( ++v44 >= v45 )
        break;
      v10 = 0;
    }
    numChannels = v47;
  }
  UpdateAdaptiveCoefficientNormalization(
    cf: colorFormat,
    iNumChannels: numChannels,
    iLaplacianMean: v48,
    pModel: &context->adaptCNModelHP);
  if ( v5->adaptContextHuffman )
    AdaptContextHuffmanHP(context);
  return HDP_ERROR_NONE;
}


// ========================================================================
// EncodeMacroblockLowPass
// EA  : 0x828F7C60
// RVA : 0x008F7C60
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenccoeffs.cpp
// ========================================================================

hdpError_t __fastcall EncodeMacroblockLowPass(hdpCodec_t *codec, hdpContext_t *context, int mbX, int mbY)
{
  hdpColorFormat_t colorFormat; // r18
  signed int numChannels; // r15
  signed int v8; // r17
  hdpBitIO_t *bitIOLP; // r25
  int *v10; // r10
  signed int v11; // ctr
  hdpCodec_t *v12; // r11
  unsigned __int8 cBitsLP; // r31
  int quantizerIndexLP; // r30
  char v15; // r5
  hdpBitIO_t *v16; // r3
  unsigned int v17; // r4
  int *v18; // r28
  int *v19; // r29
  int *v20; // r27
  int v21; // r31
  signed int v22; // r30
  int v23; // r3
  signed int v24; // r11
  void (__fastcall *v25)(hdpBitIO_t *, unsigned int, char); // r22
  int *fixedLengthCodeBits; // r10
  int v27; // r24
  int v28; // r20
  int v29; // r23
  _DWORD *v30; // r10
  int v31; // r26
  int v32; // r6
  int v33; // r4
  int v34; // r11
  int v35; // r8
  hdpError_t result; // r3
  int v37; // r28
  __int16 *v38; // r31
  int v39; // r30
  int v40; // r11
  int i; // r31
  int v42; // [sp+50h] [-D50h] BYREF
  _DWORD v43[14]; // [sp+54h] [-D4Ch] BYREF
  int v44; // [sp+8Ch] [-D14h] BYREF
  _BYTE v45[4]; // [sp+90h] [-D10h] BYREF
  int v46; // [sp+94h] [-D0Ch]
  int v47; // [sp+98h] [-D08h]
  _BYTE v48[48]; // [sp+A0h] [-D00h] BYREF
  int v49[16]; // [sp+D0h] [-CD0h] BYREF
  _DWORD v50[256]; // [sp+110h] [-C90h] BYREF
  unsigned int v51[548]; // [sp+510h] [-890h] BYREF

  colorFormat = codec->codecParms.colorFormat;
  numChannels = codec->codecParms.numChannels;
  if ( colorFormat == CF_YUV_420 || (v8 = codec->codecParms.numChannels, colorFormat == CF_YUV_422) )
    v8 = 1;
  bitIOLP = context->bitIOLP;
  v42 = 0;
  memset(v43, 0, sizeof(v43));
  v44 = 0;
  if ( numChannels > 0 )
  {
    v10 = &v44;
    v11 = numChannels;
    v12 = codec;
    do
    {
      *++v10 = (int)v12;
      v12 = (hdpCodec_t *)((char *)v12 + 32);
      --v11;
    }
    while ( v11 != 0 );
  }
  if ( codec->resetAdaptiveScanTotals )
    ResetAdaptiveScanTotalsLP(context);
  if ( codec->codecParms.streamLayout == SL_FREQUENCY )
  {
    cBitsLP = codec->tileQuantization[codec->currentTileColumn].cBitsLP;
    if ( cBitsLP != 0 )
    {
      quantizerIndexLP = codec->MBInfo.quantizerIndexLP;
      v15 = 1;
      v16 = bitIOLP;
      if ( codec->MBInfo.quantizerIndexLP != 0 )
      {
        WriteBits16(pIO: bitIOLP, uiBits: 1u, cBits: 1);
        v15 = cBitsLP;
        v17 = quantizerIndexLP - 1;
        v16 = bitIOLP;
      }
      else
      {
        v17 = 0;
      }
      WriteBits16(pIO: v16, uiBits: v17, cBits: v15);
    }
  }
  if ( v8 > 0 )
  {
    v18 = v50;
    v19 = (int *)v51;
    v20 = &context->adaptCNModelLP.fixedLengthCodeState[15];
    v21 = 0;
    v22 = v8;
    do
    {
      v23 = AdaptiveScan(
              pCoeffs: *(const __int16 **)&v45[v21 * 4],
              pResidual: v18,
              pScan: context->adaptScanLP[0],
              iModelBits: *++v20,
              iTrimBits: 0,
              pRLCoeffs: v19,
              iCount: 16);
      --v22;
      v19 += 32;
      v18 += 16;
      v49[v21++] = v23;
    }
    while ( v22 != 0 );
  }
  EncodeLPCBP(codec, context, iNumCoeffs: v49);
  v24 = 0;
  v25 = WriteBits16;
  if ( v8 > 0 )
  {
    fixedLengthCodeBits = context->adaptCNModelLP.fixedLengthCodeBits;
    while ( *fixedLengthCodeBits <= 14 )
    {
      ++v24;
      ++fixedLengthCodeBits;
      if ( v24 >= v8 )
        goto LABEL_24;
    }
    v25 = (void (__fastcall *)(hdpBitIO_t *, unsigned int, char))WriteBits32;
  }
LABEL_24:
  v27 = 0;
  if ( v8 > 0 )
  {
    v28 = v47;
    v29 = v46;
    while ( 1 )
    {
      v30 = &v43[v27 - 1];
      v31 = context->adaptCNModelLP.fixedLengthCodeBits[v27];
      if ( v27 <= 0 )
        goto LABEL_34;
      if ( colorFormat == CF_YUV_422 || colorFormat == CF_YUV_420 )
      {
        v31 = context->adaptCNModelLP.fixedLengthCodeBits[1];
        v30 = v43;
      }
      if ( colorFormat == CF_YUV_444 || colorFormat == CF_YUV_422 || colorFormat == CF_YUV_420 )
        v32 = 1;
      else
LABEL_34:
        v32 = 0;
      v33 = v49[v27];
      if ( v33 != 0 )
        break;
LABEL_43:
      if ( v31 != 0 )
      {
        if ( v27 > 0 && (colorFormat == CF_YUV_420 || colorFormat == CF_YUV_422) )
        {
          v37 = 1;
          v38 = (__int16 *)(v29 + 2);
          v39 = v28 - v29;
          while ( 1 )
          {
            v40 = 4;
            if ( colorFormat != CF_YUV_420 )
              v40 = 8;
            if ( v37 >= v40 )
              break;
            v25(pIO: bitIOLP, uiBits: abs16(*v38), cBits: v31);
            if ( *(_WORD *)&v45[(_DWORD)v38 - v29] == 0 && *v38 != 0 )
              WriteBits16(pIO: bitIOLP, uiBits: (unsigned int)*v38 >> 31, cBits: 1);
            v25(pIO: bitIOLP, uiBits: abs16(*(__int16 *)((char *)v38 + v39)), cBits: v31);
            if ( *(_WORD *)&v48[(_DWORD)v38 - v29] == 0 && *(__int16 *)((char *)v38 + v39) != 0 )
              WriteBits16(pIO: bitIOLP, uiBits: (unsigned int)*(__int16 *)((char *)v38 + v39) >> 31, cBits: 1);
            ++v37;
            ++v38;
          }
        }
        else
        {
          for ( i = 1; i < 16; ++i )
            WriteBits16(pIO: bitIOLP, uiBits: (int)v50[16 * v27 + i] >> 1, cBits: (v50[16 * v27 + i] & 1) + v31);
        }
      }
      if ( ++v27 >= v8 )
        goto LABEL_61;
    }
    *v30 += v33;
    if ( colorFormat == CF_YUV_420 && v27 == 1 )
    {
      v34 = 1;
    }
    else
    {
      v34 = 0;
      if ( colorFormat == CF_YUV_422 )
      {
        v35 = 1;
        if ( v27 == 1 )
        {
LABEL_42:
          result = EncodeBlock(
                     aLocalCoef: &v51[32 * v27],
                     iNumNonzero: v33,
                     adaptHuff: context->adaptHuffLP,
                     bChroma: v32,
                     pOut: bitIOLP,
                     iLocation: 9 * v34 + v35 + 1);
          if ( result != HDP_ERROR_NONE )
            return result;
          goto LABEL_43;
        }
      }
    }
    v35 = 0;
    goto LABEL_42;
  }
LABEL_61:
  UpdateAdaptiveCoefficientNormalization(
    cf: colorFormat,
    iNumChannels: numChannels,
    iLaplacianMean: &v42,
    pModel: &context->adaptCNModelLP);
  if ( codec->adaptContextHuffman )
    AdaptContextHuffmanLP(context);
  return HDP_ERROR_NONE;
}


// ========================================================================
// ?EncodeMacroblockDC@@YA?AW4hdpError_t@@PAUhdpCodec_t@@PAUhdpContext_t@@HH@Z
// EA  : 0x828F8088
// RVA : 0x008F8088
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenccoeffs.cpp
// ========================================================================

hdpError_t __fastcall EncodeMacroblockDC(hdpCodec_t *codec, hdpContext_t *context, int mbX, int mbY)
{
  hdpCodec_t *v4; // r14
  hdpColorFormat_t colorFormat; // r3
  hdpBitIO_t *bitIODC; // r31
  int numChannels; // r20
  int *v9; // r21
  __int16 *v10; // r23
  int *fixedLengthCodeBits; // r22
  int v12; // r26
  unsigned int v13; // r27
  signed int v14; // r25
  int v15; // r30
  signed int v16; // r28
  hdpAdaptiveHuffman_t *v17; // r30
  bool v18; // zf
  int v19; // r11
  int m; // r29
  __int64 v21; // r6
  int v22; // r8
  int v23; // r29
  int v24; // r19
  unsigned int v25; // r29
  int v26; // r25
  int v27; // r20
  unsigned int v28; // r22
  unsigned int v29; // r18
  signed int v30; // r24
  signed int v31; // r19
  int v32; // r17
  signed int v33; // r16
  int v34; // r30
  int v35; // r27
  int v36; // r21
  const int *v37; // r11
  signed int v38; // r26
  hdpAdaptiveHuffman_t *v39; // r30
  int v40; // r11
  int i; // r28
  char v42; // r5
  hdpBitIO_t *v43; // r3
  unsigned int v44; // r4
  __int64 v45; // r6
  int v46; // r8
  int v47; // r28
  int v48; // r14
  __int64 v49; // r6
  signed int v50; // r28
  hdpAdaptiveHuffman_t *v51; // r30
  int v52; // r11
  int j; // r29
  __int64 v54; // r6
  int v55; // r8
  int v56; // r29
  int v57; // r27
  int v58; // r28
  hdpAdaptiveHuffman_t *v59; // r30
  int v60; // r11
  int k; // r29
  __int64 v62; // r6
  int v63; // r8
  int v64; // r29
  int v65; // r27
  unsigned int v66; // r11
  hdpColorFormat_t v68; // [sp+50h] [-F0h]
  int v69; // [sp+54h] [-ECh]
  int v70; // [sp+60h] [-E0h] BYREF
  _DWORD v71[55]; // [sp+64h] [-DCh] BYREF

  v4 = codec;
  colorFormat = codec->codecParms.colorFormat;
  bitIODC = context->bitIODC;
  v70 = 0;
  memset(v71, 0, 60);
  numChannels = v4->codecParms.numChannels;
  v68 = colorFormat;
  v69 = numChannels;
  if ( colorFormat == CF_YUV_444 || colorFormat == CF_YUV_422 || colorFormat == CF_YUV_420 )
  {
    v25 = v4->MBInfo.compactDCLP[0][0];
    v26 = context->adaptCNModelDC.fixedLengthCodeBits[0];
    v27 = context->adaptCNModelDC.fixedLengthCodeBits[1];
    v28 = v4->MBInfo.compactDCLP[1][0];
    v29 = v4->MBInfo.compactDCLP[2][0];
    v30 = abs16(v4->MBInfo.compactDCLP[0][0]);
    v31 = abs16(v4->MBInfo.compactDCLP[1][0]);
    v32 = context->adaptCNModelDC.fixedLengthCodeBits[((_cntlzw(colorFormat - 3) & 0x20) != 0) + 1];
    v33 = abs16(v4->MBInfo.compactDCLP[2][0]);
    v34 = v30 >> v26;
    v35 = v31 >> v27;
    v36 = v33 >> v32;
    v37 = &context->adaptHuffDC[0].encTable[2
                                          * ((2 * ((2 * (v30 >> v26 != 0)) | (v31 >> v27 != 0))) | (v33 >> v32 != 0))];
    WriteBits16(pIO: bitIODC, uiBits: v37[1], cBits: v37[2]);
    if ( v30 >> v26 != 0 )
    {
      v38 = v34 - 1;
      v18 = v34 - 1 < 16;
      v39 = &context->adaptHuffDC[1];
      if ( v18 )
      {
        v46 = gSignificantAbsLevelRemap_0[v38];
        v47 = v46;
        v48 = gSignificantAbsLevelFixedLength_0[v46];
        WriteBits16(pIO: bitIODC, uiBits: v39->encTable[2 * v46 + 1], cBits: v39->encTable[2 * v46 + 2]);
        HIDWORD(v49) = v48;
        LODWORD(v49) = context->adaptHuffDC[1].deltaTable[v47] + context->adaptHuffDC[1].discriminant;
        context->adaptHuffDC[1].discriminant = v49;
        WriteBits32(pIO: bitIODC, uiBits: v38, cBits: v49);
        v4 = codec;
      }
      else
      {
        v40 = v38 >> 5;
        for ( i = 4; v40 != 0; ++i )
          v40 >>= 1;
        WriteBits16(pIO: bitIODC, uiBits: *((_DWORD *)v39->encTable + 13), cBits: *((_DWORD *)v39->encTable + 14));
        v42 = 4;
        v43 = bitIODC;
        context->adaptHuffDC[1].discriminant += *((_DWORD *)context->adaptHuffDC[1].deltaTable + 6);
        if ( i <= 18 )
        {
          v44 = i - 4;
        }
        else
        {
          WriteBits16(pIO: bitIODC, uiBits: 0xFu, cBits: 4);
          v42 = 2;
          v43 = bitIODC;
          if ( i <= 21 )
          {
            v44 = i - 19;
          }
          else
          {
            WriteBits16(pIO: bitIODC, uiBits: 3u, cBits: 2);
            v42 = 3;
            v44 = i - 22;
            v43 = bitIODC;
          }
        }
        WriteBits16(pIO: v43, uiBits: v44, cBits: v42);
        HIDWORD(v45) = i;
        WriteBits32(pIO: bitIODC, uiBits: v38, cBits: v45);
      }
      ++v70;
    }
    WriteBits16(pIO: bitIODC, uiBits: v30, cBits: v26);
    if ( v25 != 0 )
      WriteBits16(pIO: bitIODC, uiBits: v25 >> 31, cBits: 1);
    if ( v35 != 0 )
    {
      v50 = v35 - 1;
      v51 = &context->adaptHuffDC[2];
      if ( v35 - 1 < 16 )
      {
        v55 = gSignificantAbsLevelRemap_0[v50];
        v56 = v55;
        v57 = gSignificantAbsLevelFixedLength_0[v55];
        WriteBits16(pIO: bitIODC, uiBits: v51->encTable[2 * v55 + 1], cBits: v51->encTable[2 * v55 + 2]);
        HIDWORD(v54) = v57;
        LODWORD(v54) = context->adaptHuffDC[2].deltaTable[v56] + context->adaptHuffDC[2].discriminant;
        context->adaptHuffDC[2].discriminant = v54;
      }
      else
      {
        v52 = v50 >> 5;
        for ( j = 4; v52 != 0; ++j )
          v52 >>= 1;
        WriteBits16(pIO: bitIODC, uiBits: *((_DWORD *)v51->encTable + 13), cBits: *((_DWORD *)v51->encTable + 14));
        context->adaptHuffDC[2].discriminant += *((_DWORD *)context->adaptHuffDC[2].deltaTable + 6);
        if ( j <= 18 )
        {
          WriteBits16(pIO: bitIODC, uiBits: j - 4, cBits: 4);
          HIDWORD(v54) = j;
        }
        else
        {
          WriteBits16(pIO: bitIODC, uiBits: 0xFu, cBits: 4);
          if ( j <= 21 )
          {
            WriteBits16(pIO: bitIODC, uiBits: j - 19, cBits: 2);
          }
          else
          {
            WriteBits16(pIO: bitIODC, uiBits: 3u, cBits: 2);
            WriteBits16(pIO: bitIODC, uiBits: j - 22, cBits: 3);
          }
          HIDWORD(v54) = j;
        }
      }
      WriteBits32(pIO: bitIODC, uiBits: v50, cBits: v54);
      ++v71[0];
    }
    WriteBits16(pIO: bitIODC, uiBits: v31, cBits: v27);
    if ( v28 != 0 )
      WriteBits16(pIO: bitIODC, uiBits: v28 >> 31, cBits: 1);
    if ( v36 != 0 )
    {
      v58 = v36 - 1;
      v59 = &context->adaptHuffDC[2];
      if ( v36 - 1 < 16 )
      {
        v63 = gSignificantAbsLevelRemap_0[v58];
        v64 = v63;
        v65 = gSignificantAbsLevelFixedLength_0[v63];
        WriteBits16(pIO: bitIODC, uiBits: v59->encTable[2 * v63 + 1], cBits: v59->encTable[2 * v63 + 2]);
        HIDWORD(v62) = v65;
        LODWORD(v62) = context->adaptHuffDC[2].deltaTable[v64] + context->adaptHuffDC[2].discriminant;
        context->adaptHuffDC[2].discriminant = v62;
      }
      else
      {
        v60 = v58 >> 5;
        for ( k = 4; v60 != 0; ++k )
          v60 >>= 1;
        WriteBits16(pIO: bitIODC, uiBits: *((_DWORD *)v59->encTable + 13), cBits: *((_DWORD *)v59->encTable + 14));
        context->adaptHuffDC[2].discriminant += *((_DWORD *)context->adaptHuffDC[2].deltaTable + 6);
        if ( k <= 18 )
        {
          WriteBits16(pIO: bitIODC, uiBits: k - 4, cBits: 4);
          HIDWORD(v62) = k;
        }
        else
        {
          WriteBits16(pIO: bitIODC, uiBits: 0xFu, cBits: 4);
          if ( k <= 21 )
          {
            WriteBits16(pIO: bitIODC, uiBits: k - 19, cBits: 2);
          }
          else
          {
            WriteBits16(pIO: bitIODC, uiBits: 3u, cBits: 2);
            WriteBits16(pIO: bitIODC, uiBits: k - 22, cBits: 3);
          }
          HIDWORD(v62) = k;
        }
      }
      WriteBits32(pIO: bitIODC, uiBits: v36 - 1, cBits: v62);
      v66 = (_cntlzw(v68 - 3) >> 3) & 4;
      ++*(_DWORD *)((char *)v71 + v66);
    }
    WriteBits16(pIO: bitIODC, uiBits: v33, cBits: v32);
    if ( v29 != 0 )
      WriteBits16(pIO: bitIODC, uiBits: v29 >> 31, cBits: 1);
  }
  else
  {
    if ( numChannels <= 0 )
      goto LABEL_65;
    v9 = &v70;
    v10 = (__int16 *)v4;
    fixedLengthCodeBits = context->adaptCNModelDC.fixedLengthCodeBits;
    do
    {
      v12 = *fixedLengthCodeBits;
      v13 = *v10;
      v14 = abs16(*v10);
      v15 = v14 >> *fixedLengthCodeBits;
      WriteBits16(pIO: bitIODC, uiBits: v15 != 0, cBits: 1);
      if ( v15 != 0 )
      {
        v16 = v15 - 1;
        v18 = v15 - 1 < 16;
        v17 = &context->adaptHuffDC[1];
        if ( v18 )
        {
          v22 = gSignificantAbsLevelRemap_0[v16];
          v23 = v22;
          v24 = gSignificantAbsLevelFixedLength_0[v22];
          WriteBits16(pIO: bitIODC, uiBits: v17->encTable[2 * v22 + 1], cBits: v17->encTable[2 * v22 + 2]);
          HIDWORD(v21) = v24;
          LODWORD(v21) = context->adaptHuffDC[1].deltaTable[v23] + context->adaptHuffDC[1].discriminant;
          context->adaptHuffDC[1].discriminant = v21;
        }
        else
        {
          v19 = v16 >> 5;
          for ( m = 4; v19 != 0; ++m )
            v19 >>= 1;
          WriteBits16(pIO: bitIODC, uiBits: *((_DWORD *)v17->encTable + 13), cBits: *((_DWORD *)v17->encTable + 14));
          context->adaptHuffDC[1].discriminant += *((_DWORD *)context->adaptHuffDC[1].deltaTable + 6);
          if ( m <= 18 )
          {
            WriteBits16(pIO: bitIODC, uiBits: m - 4, cBits: 4);
            HIDWORD(v21) = m;
          }
          else
          {
            WriteBits16(pIO: bitIODC, uiBits: 0xFu, cBits: 4);
            if ( m <= 21 )
            {
              WriteBits16(pIO: bitIODC, uiBits: m - 19, cBits: 2);
            }
            else
            {
              WriteBits16(pIO: bitIODC, uiBits: 3u, cBits: 2);
              WriteBits16(pIO: bitIODC, uiBits: m - 22, cBits: 3);
            }
            HIDWORD(v21) = m;
          }
        }
        WriteBits32(pIO: bitIODC, uiBits: v16, cBits: v21);
        ++*v9;
      }
      WriteBits16(pIO: bitIODC, uiBits: v14, cBits: v12);
      if ( v13 != 0 )
        WriteBits16(pIO: bitIODC, uiBits: v13 >> 31, cBits: 1);
      --numChannels;
      v10 += 16;
      ++fixedLengthCodeBits;
      ++v9;
    }
    while ( numChannels != 0 );
  }
  colorFormat = v68;
LABEL_65:
  UpdateAdaptiveCoefficientNormalization(
    cf: colorFormat,
    iNumChannels: v69,
    iLaplacianMean: &v70,
    pModel: &context->adaptCNModelDC);
  if ( v4->adaptContextHuffman )
    AdaptContextHuffmanDC(context);
  return HDP_ERROR_NONE;
}


// ========================================================================
// ?EncodeQuantizerIndexLPHP@@YA?AW4hdpError_t@@PAUhdpCodec_t@@PAUhdpContext_t@@@Z
// EA  : 0x828F8790
// RVA : 0x008F8790
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenccoeffs.cpp
// ========================================================================

hdpError_t __fastcall EncodeQuantizerIndexLPHP(hdpCodec_t *codec, hdpContext_t *context)
{
  hdpBitIO_t *bitIODC; // r27
  hdpTileQuantization_t *v4; // r29
  int v5; // r3
  signed int cNumQPLP; // r10
  int v7; // r11
  int v8; // r3
  signed int cNumQPHP; // r10
  int v10; // r11
  char cBitsLP; // r28
  int quantizerIndexLP; // r30
  char v13; // r5
  hdpBitIO_t *v14; // r3
  unsigned int v15; // r4
  char cBitsHP; // r30
  int quantizerIndexHP; // r31

  bitIODC = context->bitIODC;
  v4 = &codec->tileQuantization[codec->currentTileColumn];
  if ( !codec->codecParms.transcode )
  {
    if ( v4->cNumQPLP <= 1u )
    {
      LOBYTE(v7) = 0;
    }
    else
    {
      v5 = rand();
      cNumQPLP = v4->cNumQPLP;
      __twllei(cNumQPLP, 0);
      v7 = v5 % cNumQPLP;
      __twlgei(cNumQPLP & ~(__ROL4__(v5, 1) - 1), 0xFFFFFFFF);
    }
    codec->MBInfo.quantizerIndexLP = v7;
    if ( v4->cNumQPHP <= 1u )
    {
      LOBYTE(v10) = 0;
    }
    else
    {
      v8 = rand();
      cNumQPHP = v4->cNumQPHP;
      __twllei(cNumQPHP, 0);
      v10 = v8 % cNumQPHP;
      __twlgei(cNumQPHP & ~(__ROL4__(v8, 1) - 1), 0xFFFFFFFF);
    }
    codec->MBInfo.quantizerIndexHP = v10;
  }
  if ( v4->cBitsHP == 0 && v4->cNumQPHP > 1u )
    codec->MBInfo.quantizerIndexHP = codec->MBInfo.quantizerIndexLP;
  if ( codec->codecParms.streamLayout == SL_SPATIAL )
  {
    if ( codec->codecParms.subBands < SB_NO_LOWPASS )
    {
      cBitsLP = v4->cBitsLP;
      if ( cBitsLP != 0 )
      {
        quantizerIndexLP = codec->MBInfo.quantizerIndexLP;
        v13 = 1;
        v14 = bitIODC;
        if ( codec->MBInfo.quantizerIndexLP != 0 )
        {
          WriteBits16(pIO: bitIODC, uiBits: 1u, cBits: 1);
          v13 = cBitsLP;
          v15 = quantizerIndexLP - 1;
          v14 = bitIODC;
        }
        else
        {
          v15 = 0;
        }
        WriteBits16(pIO: v14, uiBits: v15, cBits: v13);
      }
    }
    if ( codec->codecParms.subBands < SB_NO_HIGHPASS )
    {
      cBitsHP = v4->cBitsHP;
      if ( cBitsHP != 0 )
      {
        quantizerIndexHP = codec->MBInfo.quantizerIndexHP;
        if ( quantizerIndexHP == 0 )
        {
          WriteBits16(pIO: bitIODC, uiBits: 0, cBits: 1);
          return HDP_ERROR_NONE;
        }
        WriteBits16(pIO: bitIODC, uiBits: 1u, cBits: 1);
        WriteBits16(pIO: bitIODC, uiBits: quantizerIndexHP - 1, cBits: cBitsHP);
      }
    }
  }
  return HDP_ERROR_NONE;
}


// ========================================================================
// ?EncodeMacroblock@@YA?AW4hdpError_t@@PAUhdpCodec_t@@PAUhdpContext_t@@HH@Z
// EA  : 0x828F8920
// RVA : 0x008F8920
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpenccoeffs.cpp
// ========================================================================

hdpError_t __fastcall EncodeMacroblock(hdpCodec_t *codec, hdpContext_t *context, unsigned int mbX, int mbY)
{
  hdpError_t result; // r3
  int v9; // r6
  int v10; // r5

  UpdatePredictionInfo(codec, mbX);
  PredictDCLPHPEnc(codec);
  result = EncodeQuantizerIndexLPHP(codec, context);
  if ( result == HDP_ERROR_NONE )
  {
    result = EncodeMacroblockDC(codec, context, mbX, mbY);
    if ( result == HDP_ERROR_NONE
      && (codec->codecParms.subBands >= SB_NO_LOWPASS
       || (result = EncodeMacroblockLowPass(codec, context, mbX: v10, mbY: v9)) == HDP_ERROR_NONE) )
    {
      if ( codec->codecParms.subBands >= SB_NO_HIGHPASS )
        return HDP_ERROR_NONE;
      result = EncodeMacroblockHighPass(codec, context, mbX, mbY);
      if ( result == HDP_ERROR_NONE )
        return HDP_ERROR_NONE;
    }
  }
  return result;
}

