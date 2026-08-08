
// ========================================================================
// ?FreeCodingContexts@@YAXPAUhdpCodec_t@@@Z
// EA  : 0x828ED1A0
// RVA : 0x008ED1A0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpcontext.cpp
// ========================================================================

void __fastcall FreeCodingContexts(hdpCodec_t *codec)
{
  unsigned int v2; // r25
  hdpCodecParms_t *p_codecParms; // r28
  int v4; // r27
  int v5; // r31
  hdpContext_t *v6; // r29
  hdpAdaptiveHuffman_t *adaptHuffDC; // r30
  hdpAdaptiveHuffman_t *adaptHuffLP; // r30
  int i; // r31
  hdpAdaptiveHuffman_t *adaptHuffHP; // r30
  int j; // r31
  hdpAdaptiveHuffman_t *adaptHuffCBP; // r30
  int k; // r31

  if ( codec->tileContexts != nullptr )
  {
    v2 = 0;
    p_codecParms = &codec->codecParms;
    v4 = 0;
    do
    {
      v5 = 3;
      v6 = &codec->tileContexts[v4];
      adaptHuffDC = v6->adaptHuffDC;
      do
      {
        ShutdownAdaptiveHuffman(codecParms: p_codecParms, adaptHuff: adaptHuffDC);
        --v5;
        ++adaptHuffDC;
      }
      while ( v5 != 0 );
      adaptHuffLP = v6->adaptHuffLP;
      for ( i = 8; i != 0; --i )
        ShutdownAdaptiveHuffman(codecParms: p_codecParms, adaptHuff: adaptHuffLP++);
      adaptHuffHP = v6->adaptHuffHP;
      for ( j = 8; j != 0; --j )
        ShutdownAdaptiveHuffman(codecParms: p_codecParms, adaptHuff: adaptHuffHP++);
      adaptHuffCBP = v6->adaptHuffCBP;
      for ( k = 3; k != 0; --k )
        ShutdownAdaptiveHuffman(codecParms: p_codecParms, adaptHuff: adaptHuffCBP++);
      ++v2;
      ++v4;
    }
    while ( v2 <= codec->codecParms.numTilesWideMinusOne );
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)p_codecParms);
  }
}


// ========================================================================
// ?InitContextBitIOs@@YAXPAUhdpCodec_t@@@Z
// EA  : 0x828ED278
// RVA : 0x008ED278
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpcontext.cpp
// ========================================================================

void __fastcall InitContextBitIOs(hdpCodec_t *codec)
{
  unsigned int v1; // r10
  int v2; // r6
  int v3; // r5
  hdpContext_t *v4; // r11
  unsigned int numSubBands; // r9
  unsigned int v6; // r9
  unsigned int v7; // r9
  hdpContext_t *tileContexts; // r11

  if ( codec->numTileBitIOs != 0 )
  {
    v1 = 0;
    v2 = 0;
    v3 = 0;
    do
    {
      v4 = &codec->tileContexts[v3];
      if ( codec->codecParms.streamLayout != SL_SPATIAL )
      {
        v4->bitIODC = &codec->tileBitIOs[codec->numSubBands * v1];
        numSubBands = codec->numSubBands;
        if ( numSubBands > 1 )
          v4->bitIOLP = &codec->tileBitIOs[numSubBands * v1 + 1];
        v6 = codec->numSubBands;
        if ( v6 > 2 )
          v4->bitIOHP = &codec->tileBitIOs[v6 * v1 + 2];
        v7 = codec->numSubBands;
        if ( v7 > 3 )
          v4->bitIOFL = &codec->tileBitIOs[v7 * v1 + 3];
      }
      else
      {
        v4->bitIODC = &codec->tileBitIOs[v2];
        v4->bitIOLP = &codec->tileBitIOs[v2];
        v4->bitIOHP = &codec->tileBitIOs[v2];
        v4->bitIOFL = &codec->tileBitIOs[v2];
      }
      ++v1;
      ++v3;
      ++v2;
    }
    while ( v1 <= codec->codecParms.numTilesWideMinusOne );
  }
  else
  {
    tileContexts = codec->tileContexts;
    tileContexts->bitIODC = codec->bitIOHeader;
    tileContexts->bitIOLP = codec->bitIOHeader;
    tileContexts->bitIOHP = codec->bitIOHeader;
    tileContexts->bitIOFL = codec->bitIOHeader;
  }
}


// ========================================================================
// ?ResetAdaptiveScanTotalsLP@@YAXPAUhdpContext_t@@@Z
// EA  : 0x828ED3C8
// RVA : 0x008ED3C8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpcontext.cpp
// ========================================================================

void __fastcall ResetAdaptiveScanTotalsLP(hdpContext_t *context)
{
  int v1; // r10
  int v2; // r11
  int i; // ctr
  char *v4; // r9

  v1 = 32;
  context->adaptScanLP[0][0].scanTotal = 0x7FFF;
  v2 = 1;
  for ( i = 15; i != 0; --i )
  {
    v4 = (char *)context + 8 * v2++;
    *((_DWORD *)v4 + 153) = v1;
    v1 -= 2;
  }
}


// ========================================================================
// ?ResetAdaptiveScanTotalsHP@@YAXPAUhdpContext_t@@@Z
// EA  : 0x828ED400
// RVA : 0x008ED400
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpcontext.cpp
// ========================================================================

void __fastcall ResetAdaptiveScanTotalsHP(hdpContext_t *context)
{
  int v1; // r11
  int v2; // r10
  int i; // ctr
  char *v4; // r9

  v1 = 32;
  context->adaptScanHorHP[0][0].scanTotal = 0x7FFF;
  context->adaptScanVerHP[0][0].scanTotal = 0x7FFF;
  v2 = 1;
  for ( i = 15; i != 0; --i )
  {
    v4 = (char *)context + 8 * v2++;
    *((_DWORD *)v4 + 185) = v1;
    *((_DWORD *)v4 + 217) = v1;
    v1 -= 2;
  }
}


// ========================================================================
// ?AdaptContextHuffmanDC@@YA?AW4hdpError_t@@PAUhdpContext_t@@@Z
// EA  : 0x828ED440
// RVA : 0x008ED440
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpcontext.cpp
// ========================================================================

hdpError_t __fastcall AdaptContextHuffmanDC(hdpContext_t *context)
{
  hdpAdaptiveHuffman_t *adaptHuffDC; // r30
  int i; // r31

  adaptHuffDC = context->adaptHuffDC;
  for ( i = 3; i != 0; --i )
    AdaptiveHuffmanDiscriminant(adaptHuff: adaptHuffDC++);
  return HDP_ERROR_NONE;
}


// ========================================================================
// ?AdaptContextHuffmanLP@@YA?AW4hdpError_t@@PAUhdpContext_t@@@Z
// EA  : 0x828ED490
// RVA : 0x008ED490
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpcontext.cpp
// ========================================================================

hdpError_t __fastcall AdaptContextHuffmanLP(hdpContext_t *context)
{
  hdpAdaptiveHuffman_t *adaptHuffLP; // r30
  int i; // r31

  adaptHuffLP = context->adaptHuffLP;
  for ( i = 8; i != 0; --i )
    AdaptiveHuffmanDiscriminant(adaptHuff: adaptHuffLP++);
  return HDP_ERROR_NONE;
}


// ========================================================================
// ?AdaptContextHuffmanHP@@YA?AW4hdpError_t@@PAUhdpContext_t@@@Z
// EA  : 0x828ED4E0
// RVA : 0x008ED4E0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpcontext.cpp
// ========================================================================

hdpError_t __fastcall AdaptContextHuffmanHP(hdpContext_t *context)
{
  hdpAdaptiveHuffman_t *adaptHuffHP; // r30
  int i; // r31
  hdpAdaptiveHuffman_t *adaptHuffCBP; // r30
  int j; // r31

  adaptHuffHP = context->adaptHuffHP;
  for ( i = 8; i != 0; --i )
    AdaptiveHuffmanDiscriminant(adaptHuff: adaptHuffHP++);
  adaptHuffCBP = context->adaptHuffCBP;
  for ( j = 3; j != 0; --j )
    AdaptiveHuffmanDiscriminant(adaptHuff: adaptHuffCBP++);
  return HDP_ERROR_NONE;
}


// ========================================================================
// ?UpdateAdaptiveCoefficientNormalization@@YAXW4hdpColorFormat_t@@HQAHPAUhdpAdaptiveCNModel_t@@@Z
// EA  : 0x828ED538
// RVA : 0x008ED538
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpcontext.cpp
// ========================================================================

void __fastcall UpdateAdaptiveCoefficientNormalization(
        hdpColorFormat_t cf,
        int iNumChannels,
        int *iLaplacianMean,
        hdpAdaptiveCNModel_t *pModel)
{
  int *v4; // r11
  int v5; // ctr
  int v6; // r8
  int v7; // r8
  int *fixedLengthCodeBits; // r10
  int v9; // r11
  int v10; // r9
  int v11; // r9
  int v12; // r9
  int v13; // r9

  *iLaplacianMean *= aWeight0[pModel->band - 1];
  if ( iNumChannels > 1 )
  {
    v4 = iLaplacianMean;
    v5 = iNumChannels - 1;
    do
    {
      v6 = aWeight0[pModel->band - 1] * v4[1];
      *++v4 = v6;
      --v5;
    }
    while ( v5 != 0 );
  }
  v7 = 0;
  fixedLengthCodeBits = pModel->fixedLengthCodeBits;
  while ( v7 < iNumChannels )
  {
    v9 = *(fixedLengthCodeBits - 16);
    v10 = (*iLaplacianMean - 70) >> 2;
    if ( v10 > -8 )
    {
      if ( v10 >= 8 )
      {
        v13 = v10 - 4;
        if ( v13 > 15 )
          v13 = 15;
        v9 += v13;
        if ( v9 > 8 )
        {
          if ( *fixedLengthCodeBits >= 15 )
          {
            v9 = 8;
            *fixedLengthCodeBits = 15;
            goto LABEL_21;
          }
          v12 = *fixedLengthCodeBits + 1;
          goto LABEL_20;
        }
      }
    }
    else
    {
      v11 = v10 + 4;
      if ( v11 < -16 )
        v11 = -16;
      v9 += v11;
      if ( v9 < -8 )
      {
        if ( *fixedLengthCodeBits == 0 )
        {
          v9 = -8;
          goto LABEL_21;
        }
        v12 = *fixedLengthCodeBits - 1;
LABEL_20:
        *fixedLengthCodeBits = v12;
        v9 = 0;
      }
    }
LABEL_21:
    *(fixedLengthCodeBits - 16) = v9;
    if ( cf == CF_Y_ONLY )
      return;
    ++v7;
    ++iLaplacianMean;
    ++fixedLengthCodeBits;
  }
}


// ========================================================================
// ?ResetCodingContext@@YAXPAUhdpContext_t@@@Z
// EA  : 0x828ED660
// RVA : 0x008ED660
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpcontext.cpp
// ========================================================================

void __fastcall ResetCodingContext(hdpContext_t *context)
{
  int v1; // r11
  int *v3; // r10
  int i; // ctr
  int *v5; // r10
  int j; // ctr
  int *v7; // r10
  int k; // ctr
  int *v9; // r10
  int m; // ctr
  int v11; // r6
  int v12; // ctr
  int v13; // r10
  hdpBitIO_t **v14; // r9
  unsigned int v15; // r30
  unsigned int v16; // r28
  unsigned int v17; // r3
  int v18; // r6
  unsigned int v19; // r3
  unsigned int v20; // r3
  unsigned int v21; // r3
  unsigned int v22; // r3
  int v23; // r3
  hdpBitIO_t *v24; // r4
  hdpAdaptiveHuffman_t *adaptHuffDC; // r29
  int v26; // r30
  hdpAdaptiveHuffman_t *adaptHuffLP; // r29
  int n; // r30
  hdpAdaptiveHuffman_t *adaptHuffHP; // r29
  int ii; // r30
  hdpAdaptiveHuffman_t *adaptHuffCBP; // r30
  int jj; // r31

  v1 = 1;
  v3 = &context->adaptCBPModelHP.countZeros[15];
  context->adaptCBPModelLP.maxCount = 1;
  context->adaptCBPModelLP.zeroCount = 1;
  for ( i = 16; i != 0; --i )
  {
    *(v3 - 31) = -4;
    *(v3 - 15) = 4;
    *++v3 = 0;
  }
  context->adaptCNModelDC.band = BAND_DC;
  v5 = &context->adaptCNModelDC.fixedLengthCodeState[15];
  for ( j = 16; j != 0; --j )
  {
    *(v5 - 15) = 0;
    *++v5 = 8;
  }
  v7 = &context->adaptCNModelLP.fixedLengthCodeState[15];
  context->adaptCNModelLP.band = BAND_LP;
  for ( k = 16; k != 0; --k )
  {
    *(v7 - 15) = 0;
    *++v7 = 4;
  }
  v9 = &context->adaptCNModelHP.fixedLengthCodeState[15];
  context->adaptCNModelHP.band = BAND_HP;
  for ( m = 16; m != 0; --m )
  {
    *(v9 - 15) = 0;
    *++v9 = 0;
  }
  context->adaptScanLP[0][0].scanIndex = 0;
  context->adaptScanHorHP[0][0].scanIndex = 0;
  context->adaptScanVerHP[0][0].scanIndex = 0;
  context->adaptScanLP[0][0].scanTotal = 0x7FFF;
  v11 = 32;
  context->adaptScanHorHP[0][0].scanTotal = 0x7FFF;
  v12 = 3;
  context->adaptScanVerHP[0][0].scanTotal = 0x7FFF;
  v13 = 0;
  do
  {
    v14 = &context->bitIODC + 2 * v1;
    v15 = grgiZigzagInv4x4_lowpass[v13 + 1];
    v14[153] = (hdpBitIO_t *)v11;
    context->adaptScanLP[0][v1].scanIndex = v15;
    v16 = coeffOrderHP[grgiZigzagInv4x4H_highpass[v13 + 1]];
    v14[185] = (hdpBitIO_t *)v11;
    context->adaptScanHorHP[0][v1].scanIndex = v16;
    v17 = coeffOrderHP[grgiZigzagInv4x4V_highpass[v13 + 1]];
    v14[217] = (hdpBitIO_t *)v11;
    v18 = v11 - 2;
    context->adaptScanVerHP[0][v1].scanIndex = v17;
    context->adaptScanLP[0][v1 + 1].scanIndex = grgiZigzagInv4x4_lowpass[v13 + 2];
    v14[155] = (hdpBitIO_t *)v18;
    context->adaptScanHorHP[0][v1 + 1].scanIndex = coeffOrderHP[grgiZigzagInv4x4H_highpass[v13 + 2]];
    v14[187] = (hdpBitIO_t *)v18;
    v19 = coeffOrderHP[grgiZigzagInv4x4V_highpass[v13 + 2]];
    v14[219] = (hdpBitIO_t *)v18;
    v18 -= 2;
    context->adaptScanVerHP[0][v1 + 1].scanIndex = v19;
    context->adaptScanLP[0][v1 + 2].scanIndex = grgiZigzagInv4x4_lowpass[v13 + 3];
    v14[157] = (hdpBitIO_t *)v18;
    v20 = coeffOrderHP[grgiZigzagInv4x4H_highpass[v13 + 3]];
    v14[189] = (hdpBitIO_t *)v18;
    context->adaptScanHorHP[0][v1 + 2].scanIndex = v20;
    v21 = coeffOrderHP[grgiZigzagInv4x4V_highpass[v13 + 3]];
    v14[221] = (hdpBitIO_t *)v18;
    v18 -= 2;
    context->adaptScanVerHP[0][v1 + 2].scanIndex = v21;
    v22 = grgiZigzagInv4x4_lowpass[v13 + 4];
    v14[159] = (hdpBitIO_t *)v18;
    context->adaptScanLP[0][v1 + 3].scanIndex = v22;
    context->adaptScanHorHP[0][v1 + 3].scanIndex = coeffOrderHP[grgiZigzagInv4x4H_highpass[v13 + 4]];
    v14[191] = (hdpBitIO_t *)v18;
    context->adaptScanVerHP[0][v1 + 3].scanIndex = coeffOrderHP[grgiZigzagInv4x4V_highpass[v13 + 4]];
    v14[223] = (hdpBitIO_t *)v18;
    v18 -= 2;
    context->adaptScanLP[0][v1 + 4].scanIndex = grgiZigzagInv4x4_lowpass[v13 + 5];
    v14[161] = (hdpBitIO_t *)v18;
    context->adaptScanHorHP[0][v1 + 4].scanIndex = coeffOrderHP[grgiZigzagInv4x4H_highpass[v13 + 5]];
    v14[193] = (hdpBitIO_t *)v18;
    v23 = 8 * (v1 + 113);
    v24 = (hdpBitIO_t *)coeffOrderHP[grgiZigzagInv4x4V_highpass[v13 + 5]];
    v14[225] = (hdpBitIO_t *)v18;
    v1 += 5;
    v13 += 5;
    v11 = v18 - 2;
    *(hdpBitIO_t **)((char *)&context->bitIODC + v23) = v24;
    --v12;
  }
  while ( v12 != 0 );
  context->adaptHuffDC[0].isInitialized = 0;
  adaptHuffDC = context->adaptHuffDC;
  context->adaptHuffDC[1].isInitialized = 0;
  v26 = 3;
  context->adaptHuffDC[2].isInitialized = 0;
  context->adaptHuffLP[0].isInitialized = 0;
  context->adaptHuffLP[1].isInitialized = 0;
  context->adaptHuffLP[2].isInitialized = 0;
  context->adaptHuffLP[3].isInitialized = 0;
  context->adaptHuffLP[4].isInitialized = 0;
  context->adaptHuffLP[5].isInitialized = 0;
  context->adaptHuffLP[6].isInitialized = 0;
  context->adaptHuffLP[7].isInitialized = 0;
  context->adaptHuffHP[0].isInitialized = 0;
  context->adaptHuffHP[1].isInitialized = 0;
  context->adaptHuffHP[2].isInitialized = 0;
  context->adaptHuffHP[3].isInitialized = 0;
  context->adaptHuffHP[4].isInitialized = 0;
  context->adaptHuffHP[5].isInitialized = 0;
  context->adaptHuffHP[6].isInitialized = 0;
  context->adaptHuffHP[7].isInitialized = 0;
  context->adaptHuffCBP[0].isInitialized = 0;
  context->adaptHuffCBP[1].isInitialized = 0;
  context->adaptHuffCBP[2].isInitialized = 0;
  do
  {
    AdaptiveHuffmanDiscriminant(adaptHuff: adaptHuffDC);
    --v26;
    ++adaptHuffDC;
  }
  while ( v26 != 0 );
  adaptHuffLP = context->adaptHuffLP;
  for ( n = 8; n != 0; --n )
    AdaptiveHuffmanDiscriminant(adaptHuff: adaptHuffLP++);
  adaptHuffHP = context->adaptHuffHP;
  for ( ii = 8; ii != 0; --ii )
    AdaptiveHuffmanDiscriminant(adaptHuff: adaptHuffHP++);
  adaptHuffCBP = context->adaptHuffCBP;
  for ( jj = 3; jj != 0; --jj )
    AdaptiveHuffmanDiscriminant(adaptHuff: adaptHuffCBP++);
}


// ========================================================================
// ?AllocateCodingContexts@@YA?AW4hdpError_t@@PAUhdpCodec_t@@@Z
// EA  : 0x828EDA18
// RVA : 0x008EDA18
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpcontext.cpp
// ========================================================================

int __fastcall AllocateCodingContexts(hdpCodec_t *codec)
{
  unsigned int numTilesWideMinusOne; // r11
  int v4; // r30
  hdpCodecParms_t *p_codecParms; // r27
  unsigned int v6; // r31
  char *v7; // r3
  hdpColorFormat_t colorFormat; // r11
  int v9; // r25
  int i; // r23
  int *v11; // r31
  hdpContext_t *v12; // r26
  hdpAdaptiveHuffman_t *adaptHuffDC; // r30
  int *v14; // r31
  hdpAdaptiveHuffman_t *adaptHuffLP; // r30
  int *v16; // r31
  hdpAdaptiveHuffman_t *adaptHuffHP; // r30
  hdpAdaptiveHuffman_t *adaptHuffCBP; // r30
  int *v19; // r29
  int j; // r31
  int v21; // [sp+4Ch] [-64h] BYREF
  int v22; // [sp+50h] [-60h]
  int v23; // [sp+54h] [-5Ch]
  int v24; // [sp+58h] [-58h]

  numTilesWideMinusOne = codec->codecParms.numTilesWideMinusOne;
  if ( numTilesWideMinusOne >= 0x1000 )
    return -1;
  v4 = numTilesWideMinusOne + 1;
  p_codecParms = &codec->codecParms;
  v6 = 2408 * (numTilesWideMinusOne + 1);
  v7 = TempAlloc(codecParms: &codec->codecParms, size: v6, align: 0x10u);
  codec->tileContexts = (hdpContext_t *)v7;
  if ( v7 == nullptr )
    return -2;
  memset(Dst: v7, Val: 0, Size: v6);
  colorFormat = p_codecParms->colorFormat;
  if ( p_codecParms->colorFormat == CF_Y_ONLY || colorFormat == CF_N_CHANNEL || colorFormat == CF_CMYK )
    v22 = 5;
  else
    v22 = 9;
  v23 = 5;
  v24 = 4;
  if ( v4 > 0 )
  {
    v9 = 0;
    for ( i = v4; i != 0; --i )
    {
      v11 = (int *)gAlphabetDC;
      v12 = &codec->tileContexts[v9];
      adaptHuffDC = v12->adaptHuffDC;
      do
        InitAdaptiveHuffman(codecParms: &codec->codecParms, adaptHuff: adaptHuffDC++, numSymbols: *v11++);
      while ( (int)v11 < (int)gAlphabetLP );
      v14 = (int *)gAlphabetLP;
      adaptHuffLP = v12->adaptHuffLP;
      do
        InitAdaptiveHuffman(codecParms: &codec->codecParms, adaptHuff: adaptHuffLP++, numSymbols: *v14++);
      while ( (int)v14 < (int)gAlphabetHP );
      v16 = (int *)gAlphabetHP;
      adaptHuffHP = v12->adaptHuffHP;
      do
        InitAdaptiveHuffman(codecParms: &codec->codecParms, adaptHuff: adaptHuffHP++, numSymbols: *v16++);
      while ( (int)v16 < (int)aWeight0 );
      adaptHuffCBP = v12->adaptHuffCBP;
      v19 = &v21;
      for ( j = 3; j != 0; --j )
        InitAdaptiveHuffman(codecParms: &codec->codecParms, adaptHuff: adaptHuffCBP++, numSymbols: *++v19);
      ResetCodingContext(context: v12);
      ++v9;
    }
  }
  return 0;
}

