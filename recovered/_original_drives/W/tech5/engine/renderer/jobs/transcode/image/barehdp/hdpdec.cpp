
// ========================================================================
// ReadQuantizerIndex
// EA  : 0x828EDBB8
// RVA : 0x008EDBB8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdec.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall ReadQuantizerIndex(unsigned __int8 *pQPIndex, hdpBitIO_t *pIO, __int64 numChannels)
{
  unsigned int v5; // r29
  int v6; // r26
  unsigned __int64 bitCnt; // r11 OVERLAPPED
  int v8; // r9
  char v9; // r9
  unsigned int i; // r30
  unsigned __int64 v11; // r11 OVERLAPPED
  int v12; // r9
  char v13; // r9
  unsigned __int64 bitBuff; // [sp+50h] [-50h] BYREF
  unsigned __int64 v16[9]; // [sp+58h] [-48h] BYREF

  v5 = HIDWORD(numChannels);
  v6 = 0;
  if ( HIDWORD(numChannels) > 1 )
  {
    bitCnt = pIO->bitCnt;
    bitBuff = pIO->bitBuff;
    HIDWORD(bitCnt) = bitBuff;
    v16[0] = bitCnt;
    if ( (unsigned int)bitCnt < 2 )
    {
      HIDWORD(numChannels) = v16;
      FillBitBuffer(pIO, &bitBuff, bitCnt: numChannels);
      bitCnt = v16[0];
    }
    LODWORD(bitCnt) = bitCnt - 2;
    v8 = 3;
    pIO->bitBuff = *(unsigned __int64 *)((char *)&bitCnt + 4);
    *(unsigned __int64 *)((char *)&bitCnt + 4) >>= bitCnt;
    pIO->bitCnt = bitCnt;
    v6 = (unsigned __int8)(BYTE3(bitCnt) & v9);
  }
  if ( (_BYTE)v6 != 0 )
  {
    if ( (unsigned __int8)v6 == 1 )
      v5 = 2;
  }
  else
  {
    v5 = 1;
  }
  for ( i = 0; i < v5; ++i )
  {
    v11 = pIO->bitCnt;
    v16[0] = pIO->bitBuff;
    HIDWORD(v11) = v16[0];
    bitBuff = v11;
    if ( (unsigned int)v11 < 8 )
    {
      HIDWORD(numChannels) = &bitBuff;
      FillBitBuffer(pIO, bitBuff: v16, bitCnt: numChannels);
      v11 = bitBuff;
    }
    LODWORD(v11) = v11 - 8;
    v12 = 255;
    pIO->bitBuff = *(unsigned __int64 *)((char *)&v11 + 4);
    *(unsigned __int64 *)((char *)&v11 + 4) >>= v11;
    pIO->bitCnt = v11;
    LODWORD(numChannels) = (unsigned __int8)(BYTE3(v11) & v13);
    pQPIndex[i] = numChannels;
  }
  return v6;
}


// ========================================================================
// ReadQuantizer
// EA  : 0x828EDCD0
// RVA : 0x008EDCD0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdec.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall ReadQuantizer(hdpQuantizer_t **pQuantizer, hdpBitIO_t *pIO, __int64 iPos, bool transcode)
{
  int v6; // r30
  int v7; // r24
  int v9; // r23
  unsigned __int64 bitCnt; // r11 OVERLAPPED
  int v11; // r9
  char v12; // r9
  int v13; // r26
  hdpQuantizer_t **v14; // r29
  int i; // r30
  unsigned __int64 v16; // r11 OVERLAPPED
  int v17; // r9
  int v18; // ctr
  hdpQuantizer_t **v19; // r11
  unsigned __int64 bitBuff; // [sp+50h] [-70h] BYREF
  unsigned __int64 v22[13]; // [sp+58h] [-68h] BYREF

  v6 = HIDWORD(iPos);
  v7 = iPos;
  v9 = 0;
  if ( HIDWORD(iPos) > 1 )
  {
    bitCnt = pIO->bitCnt;
    bitBuff = pIO->bitBuff;
    HIDWORD(bitCnt) = bitBuff;
    v22[0] = bitCnt;
    if ( (unsigned int)bitCnt < 2 )
    {
      HIDWORD(iPos) = v22;
      FillBitBuffer(pIO, &bitBuff, bitCnt: iPos);
      bitCnt = v22[0];
    }
    LODWORD(bitCnt) = bitCnt - 2;
    v11 = 3;
    pIO->bitBuff = *(unsigned __int64 *)((char *)&bitCnt + 4);
    *(unsigned __int64 *)((char *)&bitCnt + 4) >>= bitCnt;
    pIO->bitCnt = bitCnt;
    v9 = (unsigned __int8)(BYTE3(bitCnt) & v12);
  }
  if ( (_BYTE)v9 != 0 )
  {
    v13 = 2;
    if ( (unsigned __int8)v9 != 1 )
      v13 = v6;
  }
  else
  {
    v13 = 1;
  }
  if ( v13 != 0 )
  {
    v14 = pQuantizer - 1;
    for ( i = v13; i != 0; --i )
    {
      v16 = pIO->bitCnt;
      v22[0] = pIO->bitBuff;
      HIDWORD(v16) = v22[0];
      bitBuff = v16;
      if ( (unsigned int)v16 < 8 )
      {
        HIDWORD(iPos) = &bitBuff;
        FillBitBuffer(pIO, bitBuff: v22, bitCnt: iPos);
        v16 = bitBuff;
      }
      LODWORD(v16) = v16 - 8;
      v17 = 255;
      pIO->bitBuff = *(unsigned __int64 *)((char *)&v16 + 4);
      pIO->bitCnt = v16;
      (*++v14)[v7].iIndex = *(unsigned __int64 *)((char *)&v16 + 4) >> v16;
    }
  }
  if ( transcode && v13 != 0 )
  {
    v18 = v13;
    v19 = pQuantizer - 1;
    do
    {
      (*++v19)[v7].iIndex = 0;
      --v18;
    }
    while ( v18 != 0 );
  }
  return v9;
}


// ========================================================================
// ReadPacketHeader
// EA  : 0x828EDE30
// RVA : 0x008EDE30
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdec.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall ReadPacketHeader(hdpBitIO_t *pIO, unsigned __int8 ptPacketType, __int64 pID)
{
  unsigned __int64 bitCnt; // r11 OVERLAPPED
  char v6; // r26
  bool (__fastcall **v7)(idAIEvent *__hidden, const struct idEntity *, int); // r9
  int v8; // r9
  __int64 v9; // r6
  char v10; // r28
  unsigned __int64 v11; // r10 OVERLAPPED
  unsigned int v12; // r11
  int v13; // r7
  char v14; // r27
  __int64 v15; // r6
  unsigned __int64 v16; // r10 OVERLAPPED
  unsigned int v17; // r11
  int v18; // r7
  char v19; // r29
  __int64 v20; // r6
  __int128 v21; // r11
  unsigned __int8 v22; // r11
  unsigned __int64 bitBuff; // [sp+50h] [-50h] BYREF
  unsigned __int64 v25[9]; // [sp+58h] [-48h] BYREF

  bitCnt = pIO->bitCnt;
  v6 = BYTE3(pID);
  bitBuff = pIO->bitBuff;
  HIDWORD(bitCnt) = bitBuff;
  v25[0] = bitCnt;
  if ( (unsigned int)bitCnt < 8 )
  {
    HIDWORD(pID) = v25;
    FillBitBuffer(pIO, &bitBuff, bitCnt: pID);
    bitCnt = v25[0];
  }
  v7 = &off_82230000;
  v25[0] = *(unsigned __int64 *)((char *)&bitCnt + 4);
  LODWORD(bitCnt) = bitCnt - 8;
  bitBuff = bitCnt;
  pIO->bitCnt = bitCnt;
  LODWORD(v9) = (unsigned __int8)(*(unsigned __int64 *)((char *)&bitCnt + 4) >> bitCnt);
  v8 = 255;
  pIO->bitBuff = *(unsigned __int64 *)((char *)&bitCnt + 4);
  v10 = v9;
  if ( (unsigned int)bitCnt < 8 )
  {
    HIDWORD(v9) = &bitBuff;
    FillBitBuffer(pIO, bitBuff: v25, bitCnt: v9);
  }
  v11 = HIDWORD(bitBuff) | 0xFF00000000LL;
  v12 = bitBuff - 8;
  v25[0] = v11;
  pIO->bitBuff = v11;
  pIO->bitCnt = *(unsigned __int64 *)((char *)&v11 - 4);
  v13 = v11 >> v12;
  bitBuff = *(unsigned __int64 *)((char *)&v11 - 4);
  v14 = v13 & BYTE3(v11);
  if ( v12 < 8 )
  {
    HIDWORD(v15) = &bitBuff;
    LODWORD(v15) = v13 & HIDWORD(v11);
    FillBitBuffer(pIO, bitBuff: v25, bitCnt: v15);
  }
  v16 = HIDWORD(bitBuff) | 0xFF00000000LL;
  v17 = bitBuff - 8;
  v25[0] = v16;
  pIO->bitBuff = v16;
  pIO->bitCnt = *(unsigned __int64 *)((char *)&v16 - 4);
  v18 = v16 >> v17;
  bitBuff = *(unsigned __int64 *)((char *)&v16 - 4);
  v19 = v18 & BYTE3(v16);
  if ( v17 < 8 )
  {
    HIDWORD(v20) = &bitBuff;
    LODWORD(v20) = v18 & HIDWORD(v16);
    FillBitBuffer(pIO, bitBuff: v25, bitCnt: v20);
  }
  *(_QWORD *)((char *)&v21 + 4) = HIDWORD(bitBuff) | 0xFF00000000LL;
  LODWORD(v21) = bitBuff - 8;
  pIO->bitBuff = *(_QWORD *)((char *)&v21 + 4);
  pIO->bitCnt = v21;
  v22 = (*(_QWORD *)((char *)&v21 + 4) >> v21) & BYTE7(v21);
  if ( v10 != 0 || v14 != 0 || v19 != 1 || v22 >> 3 != v6 )
    return -5;
  else
    return ptPacketType == (v22 & 7) ? 0 : 0xFFFFFFFB;
}


// ========================================================================
// ReadTileHeaderQuantizerDC
// EA  : 0x828EDFE0
// RVA : 0x008EDFE0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdec.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
hdpError_t __fastcall ReadTileHeaderQuantizerDC(hdpCodec_t *codec, hdpBitIO_t *pIO, __int64 a3)
{
  unsigned int v5; // r29
  hdpCodecParms_t *p_codecParms; // r27
  int v7; // r31
  hdpError_t result; // r3
  unsigned __int8 v9; // r25
  unsigned int numChannels; // r31
  bool transcode; // r23
  hdpTileQuantization_t *v12; // r24
  unsigned __int64 bitCnt; // r11 OVERLAPPED
  int v14; // r9
  char v15; // r9
  int v16; // r26
  unsigned __int8 *p_cNumQPLP; // r29
  int v18; // r31
  unsigned __int64 v19; // r11 OVERLAPPED
  int v20; // r9
  unsigned __int8 *v21; // r11
  int i; // ctr
  unsigned __int64 bitBuff; // [sp+50h] [-80h] BYREF
  unsigned __int64 v24; // [sp+58h] [-78h] BYREF
  unsigned __int64 v25; // [sp+60h] [-70h] BYREF
  unsigned __int64 v26; // [sp+68h] [-68h] BYREF

  if ( codec->currentTileRow + codec->currentTileColumn != 0 )
  {
LABEL_5:
    v9 = 0;
    numChannels = codec->codecParms.numChannels;
    transcode = codec->codecParms.transcode;
    v12 = &codec->tileQuantization[codec->currentTileColumn];
    if ( numChannels > 1 )
    {
      bitCnt = pIO->bitCnt;
      bitBuff = pIO->bitBuff;
      HIDWORD(bitCnt) = bitBuff;
      v24 = bitCnt;
      if ( (unsigned int)bitCnt < 2 )
      {
        HIDWORD(a3) = &v24;
        FillBitBuffer(pIO, &bitBuff, bitCnt: a3);
        bitCnt = v24;
      }
      LODWORD(bitCnt) = bitCnt - 2;
      v14 = 3;
      pIO->bitBuff = *(unsigned __int64 *)((char *)&bitCnt + 4);
      *(unsigned __int64 *)((char *)&bitCnt + 4) >>= bitCnt;
      pIO->bitCnt = bitCnt;
      v9 = BYTE3(bitCnt) & v15;
    }
    if ( v9 != 0 )
    {
      v16 = 2;
      if ( v9 != 1 )
        v16 = numChannels;
    }
    else
    {
      v16 = 1;
    }
    if ( v16 != 0 )
    {
      p_cNumQPLP = &v12[-1].cNumQPLP;
      v18 = v16;
      do
      {
        v19 = pIO->bitCnt;
        v25 = pIO->bitBuff;
        HIDWORD(v19) = v25;
        v26 = v19;
        if ( (unsigned int)v19 < 8 )
        {
          HIDWORD(a3) = &v26;
          FillBitBuffer(pIO, bitBuff: &v25, bitCnt: a3);
          v19 = v26;
        }
        LODWORD(v19) = v19 - 8;
        v20 = 255;
        pIO->bitBuff = *(unsigned __int64 *)((char *)&v19 + 4);
        --v18;
        pIO->bitCnt = v19;
        p_cNumQPLP += 4;
        *(_BYTE *)(*(_DWORD *)p_cNumQPLP + 13) = *(unsigned __int64 *)((char *)&v19 + 4) >> v19;
      }
      while ( v18 != 0 );
    }
    if ( transcode && v16 != 0 )
    {
      v21 = &v12[-1].cNumQPLP;
      for ( i = v16; i != 0; --i )
      {
        v21 += 4;
        *(_BYTE *)(*(_DWORD *)v21 + 13) = 0;
      }
    }
    FormatQuantizer(
      pQuantizer: v12->pQuantizerDC,
      cMode: v9,
      numChannels: codec->codecParms.numChannels,
      iPos: 0,
      useShiftedUV: true,
      useScaledArith: codec->codecParms.useScaledArith,
      useRoundDC: true);
    return HDP_ERROR_NONE;
  }
  else
  {
    v5 = 0;
    p_codecParms = &codec->codecParms;
    v7 = 0;
    while ( 1 )
    {
      result = AllocateQuantizer(
                 codecParms: p_codecParms,
                 pQuantizer: codec->tileQuantization[v7].pQuantizerDC,
                 numChannels: codec->codecParms.numChannels,
                 numQuantizers: 1u);
      if ( result != HDP_ERROR_NONE )
        break;
      ++v5;
      ++v7;
      if ( v5 > codec->codecParms.numTilesWideMinusOne )
        goto LABEL_5;
    }
  }
  return result;
}


// ========================================================================
// ReadTileHeaderQuantizerLP
// EA  : 0x828EE1B0
// RVA : 0x008EE1B0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdec.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
hdpError_t __fastcall ReadTileHeaderQuantizerLP(hdpCodec_t *codec, hdpBitIO_t *pIO, __int64 a3)
{
  unsigned __int64 bitCnt; // r11 OVERLAPPED
  hdpTileQuantization_t *tileQuantization; // r8
  unsigned int currentTileColumn; // r9
  hdpTileQuantization_t *v8; // r29
  bool (__fastcall **v9)(idAIEvent *__hidden, const struct idEntity *, int); // r9
  int v10; // r9
  int v11; // r7
  __int64 v12; // r6
  bool v13; // r27
  hdpError_t result; // r3
  unsigned __int64 v15; // r11 OVERLAPPED
  int v16; // r9
  char v17; // r9
  unsigned __int8 v18; // r3
  unsigned int v19; // r28
  __int64 v20; // r6
  unsigned __int8 Quantizer; // r3
  unsigned __int64 v22; // [sp+50h] [-40h] BYREF
  unsigned __int64 v23[7]; // [sp+58h] [-38h] BYREF

  bitCnt = pIO->bitCnt;
  *(unsigned __int64 *)((char *)&bitCnt + 4) = pIO->bitBuff;
  tileQuantization = codec->tileQuantization;
  currentTileColumn = codec->currentTileColumn;
  v23[0] = bitCnt;
  v22 = *(unsigned __int64 *)((char *)&bitCnt + 4);
  v8 = &tileQuantization[currentTileColumn];
  if ( (_DWORD)bitCnt == 0 )
  {
    HIDWORD(a3) = v23;
    FillBitBuffer(pIO, bitBuff: &v22, bitCnt: a3);
    bitCnt = v23[0];
  }
  v9 = &off_82230000;
  LODWORD(bitCnt) = bitCnt - 1;
  v11 = *(unsigned __int64 *)((char *)&bitCnt + 4) >> bitCnt;
  v10 = 1;
  LODWORD(v12) = 1;
  pIO->bitBuff = *(unsigned __int64 *)((char *)&bitCnt + 4);
  pIO->bitCnt = bitCnt;
  v8->cNumQPLP = 1;
  v8->cBitsLP = 0;
  v13 = (v11 & 1) != 0;
  if ( codec->currentTileRow != 0 )
    FreeQuantizer(codecParms: &codec->codecParms, pQuantizer: v8->pQuantizerLP);
  if ( v13 )
  {
    result = AllocateQuantizer(
               codecParms: &codec->codecParms,
               pQuantizer: v8->pQuantizerLP,
               numChannels: codec->codecParms.numChannels,
               numQuantizers: v8->cNumQPLP);
    if ( result == HDP_ERROR_NONE )
    {
      UseDCQuantizerForLP(codec, iTile: codec->currentTileColumn);
      return HDP_ERROR_NONE;
    }
  }
  else
  {
    v15 = pIO->bitCnt;
    v23[0] = pIO->bitBuff;
    HIDWORD(v15) = v23[0];
    v22 = v15;
    if ( (unsigned int)v15 < 4 )
    {
      HIDWORD(v12) = &v22;
      FillBitBuffer(pIO, bitBuff: v23, bitCnt: v12);
      v15 = v22;
    }
    LODWORD(v15) = v15 - 4;
    v16 = 15;
    pIO->bitBuff = *(unsigned __int64 *)((char *)&v15 + 4);
    *(unsigned __int64 *)((char *)&v15 + 4) >>= v15;
    pIO->bitCnt = v15;
    v18 = (BYTE3(v15) & v17) + 1;
    v8->cNumQPLP = v18;
    v8->cBitsLP = GetQuantizerBits(numQuantizers: v18);
    result = AllocateQuantizer(
               codecParms: &codec->codecParms,
               pQuantizer: v8->pQuantizerLP,
               numChannels: codec->codecParms.numChannels,
               numQuantizers: v8->cNumQPLP);
    if ( result == HDP_ERROR_NONE )
    {
      if ( v8->cNumQPLP != 0 )
      {
        v19 = 0;
        do
        {
          LODWORD(v20) = v19;
          HIDWORD(v20) = codec->codecParms.numChannels;
          Quantizer = ReadQuantizer(
                        pQuantizer: v8->pQuantizerLP,
                        pIO,
                        iPos: v20,
                        transcode: codec->codecParms.transcode);
          FormatQuantizer(
            pQuantizer: v8->pQuantizerLP,
            cMode: Quantizer,
            numChannels: codec->codecParms.numChannels,
            iPos: v19,
            useShiftedUV: true,
            useScaledArith: codec->codecParms.useScaledArith,
            useRoundDC: false);
          v19 = (unsigned __int8)(v19 + 1);
        }
        while ( v19 < v8->cNumQPLP );
      }
      return HDP_ERROR_NONE;
    }
  }
  return result;
}


// ========================================================================
// ReadTileHeaderQuantizerHP
// EA  : 0x828EE380
// RVA : 0x008EE380
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdec.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
hdpError_t __fastcall ReadTileHeaderQuantizerHP(hdpCodec_t *codec, hdpBitIO_t *pIO, __int64 a3)
{
  unsigned __int64 bitCnt; // r11 OVERLAPPED
  hdpTileQuantization_t *tileQuantization; // r8
  unsigned int currentTileColumn; // r9
  hdpTileQuantization_t *v8; // r30
  bool (__fastcall **v9)(idAIEvent *__hidden, const struct idEntity *, int); // r9
  int v10; // r9
  int v11; // r7
  __int64 v12; // r6
  bool v13; // r27
  unsigned int cNumQPLP; // r6
  hdpError_t result; // r3
  unsigned __int64 v16; // r11 OVERLAPPED
  int v17; // r9
  char v18; // r9
  unsigned __int8 v19; // r3
  unsigned int v20; // r28
  __int64 v21; // r6
  unsigned __int8 Quantizer; // r3
  unsigned __int64 v23; // [sp+50h] [-40h] BYREF
  unsigned __int64 v24[7]; // [sp+58h] [-38h] BYREF

  bitCnt = pIO->bitCnt;
  *(unsigned __int64 *)((char *)&bitCnt + 4) = pIO->bitBuff;
  tileQuantization = codec->tileQuantization;
  currentTileColumn = codec->currentTileColumn;
  v24[0] = bitCnt;
  v23 = *(unsigned __int64 *)((char *)&bitCnt + 4);
  v8 = &tileQuantization[currentTileColumn];
  if ( (_DWORD)bitCnt == 0 )
  {
    HIDWORD(a3) = v24;
    FillBitBuffer(pIO, bitBuff: &v23, bitCnt: a3);
    bitCnt = v24[0];
  }
  v9 = &off_82230000;
  LODWORD(bitCnt) = bitCnt - 1;
  v11 = *(unsigned __int64 *)((char *)&bitCnt + 4) >> bitCnt;
  v10 = 1;
  LODWORD(v12) = 1;
  pIO->bitBuff = *(unsigned __int64 *)((char *)&bitCnt + 4);
  pIO->bitCnt = bitCnt;
  v8->cNumQPHP = 1;
  v8->cBitsHP = 0;
  v13 = (v11 & 1) != 0;
  if ( codec->currentTileRow != 0 )
    FreeQuantizer(codecParms: &codec->codecParms, pQuantizer: v8->pQuantizerHP);
  if ( v13 )
  {
    cNumQPLP = v8->cNumQPLP;
    v8->cNumQPHP = cNumQPLP;
    result = AllocateQuantizer(
               codecParms: &codec->codecParms,
               pQuantizer: v8->pQuantizerHP,
               numChannels: codec->codecParms.numChannels,
               numQuantizers: cNumQPLP);
    if ( result == HDP_ERROR_NONE )
    {
      UseLPQuantizerForHP(codec, numQuantizers: v8->cNumQPHP, iTile: codec->currentTileColumn);
      return HDP_ERROR_NONE;
    }
  }
  else
  {
    v16 = pIO->bitCnt;
    v24[0] = pIO->bitBuff;
    HIDWORD(v16) = v24[0];
    v23 = v16;
    if ( (unsigned int)v16 < 4 )
    {
      HIDWORD(v12) = &v23;
      FillBitBuffer(pIO, bitBuff: v24, bitCnt: v12);
      v16 = v23;
    }
    LODWORD(v16) = v16 - 4;
    v17 = 15;
    pIO->bitBuff = *(unsigned __int64 *)((char *)&v16 + 4);
    *(unsigned __int64 *)((char *)&v16 + 4) >>= v16;
    pIO->bitCnt = v16;
    v19 = (BYTE3(v16) & v18) + 1;
    v8->cNumQPHP = v19;
    v8->cBitsHP = GetQuantizerBits(numQuantizers: v19);
    result = AllocateQuantizer(
               codecParms: &codec->codecParms,
               pQuantizer: v8->pQuantizerHP,
               numChannels: codec->codecParms.numChannels,
               numQuantizers: v8->cNumQPHP);
    if ( result == HDP_ERROR_NONE )
    {
      if ( v8->cNumQPHP != 0 )
      {
        v20 = 0;
        do
        {
          LODWORD(v21) = v20;
          HIDWORD(v21) = codec->codecParms.numChannels;
          Quantizer = ReadQuantizer(
                        pQuantizer: v8->pQuantizerHP,
                        pIO,
                        iPos: v21,
                        transcode: codec->codecParms.transcode);
          FormatQuantizer(
            pQuantizer: v8->pQuantizerHP,
            cMode: Quantizer,
            numChannels: codec->codecParms.numChannels,
            iPos: v20,
            useShiftedUV: false,
            useScaledArith: codec->codecParms.useScaledArith,
            useRoundDC: false);
          v20 = (unsigned __int8)(v20 + 1);
        }
        while ( v20 < v8->cNumQPHP );
      }
      return HDP_ERROR_NONE;
    }
  }
  return result;
}


// ========================================================================
// ReadTileHeader
// EA  : 0x828EE560
// RVA : 0x008EE560
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdec.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
hdpError_t __fastcall ReadTileHeader(hdpCodec_t *codec, int a2, unsigned __int64 a3)
{
  hdpContext_t *v4; // r28
  unsigned int numSubBands; // r11
  unsigned int i; // r29
  unsigned int v7; // r30
  hdpSubBands_t subBands; // r11
  int v9; // r30
  hdpError_t result; // r3
  hdpCodec_t *v11; // r30
  hdpCodec_t *v12; // r30
  hdpCodec_t *v13; // r30
  hdpBitIO_t *bitIOFL; // r31
  unsigned __int64 bitCnt; // r11 OVERLAPPED
  bool (__fastcall **v16)(idAIEvent *__hidden, const struct idEntity *, int); // r9
  int v17; // r9
  int v18; // r6
  unsigned __int64 bitBuff; // [sp+50h] [-40h] BYREF
  unsigned __int64 v20; // [sp+58h] [-38h] BYREF

  v4 = &codec->tileContexts[codec->currentTileColumn];
  if ( codec->isSecondaryCodec )
    goto LABEL_40;
  if ( codec->tileIndex != nullptr )
  {
    numSubBands = codec->numSubBands;
    for ( i = 0; i < numSubBands; ++i )
    {
      v7 = numSubBands * codec->currentTileColumn + i;
      if ( codec->currentTileRow != 0 )
        StreamReadDetach(pIO: &codec->tileBitIOs[v7], a2, a3);
      ((void (*)(void))codec->codecParms.baseStream->SetPos)();
      StreamReadAttach(pIO: &codec->tileBitIOs[v7], stream: codec->codecParms.baseStream);
      numSubBands = codec->numSubBands;
    }
  }
  LODWORD(a3) = (codec->codecParms.numTilesWideMinusOne + 1) * codec->currentTileRow + codec->currentTileColumn;
  subBands = codec->codecParms.subBands;
  v9 = a3 & 0x1F;
  if ( codec->codecParms.streamLayout == SL_SPATIAL )
  {
    if ( subBands < SB_ISOLATED )
    {
      HIDWORD(a3) = a3 & 0x1F;
      result = ReadPacketHeader(pIO: v4->bitIODC, ptPacketType: 0, pID: a3);
      if ( result != HDP_ERROR_NONE )
        return result;
    }
    goto LABEL_20;
  }
  if ( subBands < SB_ISOLATED )
  {
    HIDWORD(a3) = a3 & 0x1F;
    if ( ReadPacketHeader(pIO: v4->bitIODC, ptPacketType: 1u, pID: a3) != 0 )
      return HDP_ERROR_DECODE;
  }
  if ( codec->codecParms.subBands >= SB_NO_LOWPASS
    || (HIDWORD(a3) = v9, (result = ReadPacketHeader(pIO: v4->bitIOLP, ptPacketType: 2u, pID: a3)) == HDP_ERROR_NONE) )
  {
    if ( codec->codecParms.subBands >= SB_NO_HIGHPASS
      || (HIDWORD(a3) = v9, (result = ReadPacketHeader(pIO: v4->bitIOHP, ptPacketType: 3u, pID: a3)) == HDP_ERROR_NONE) )
    {
      if ( codec->codecParms.subBands >= SB_NO_FLEXBITS
        || (HIDWORD(a3) = v9, (result = ReadPacketHeader(pIO: v4->bitIOFL, ptPacketType: 4u, pID: a3)) == HDP_ERROR_NONE) )
      {
LABEL_20:
        if ( codec->codecParms.subBands < SB_ISOLATED && (codec->codecParms.quantizationMode & 1) != 0 )
        {
          v11 = codec;
          do
          {
            result = ReadTileHeaderQuantizerDC(codec: v11, pIO: v4->bitIODC, a3);
            if ( result != HDP_ERROR_NONE )
              return result;
            v11 = v11->nextCodec;
          }
          while ( v11 != nullptr );
        }
        if ( codec->codecParms.subBands < SB_NO_LOWPASS && (codec->codecParms.quantizationMode & 2) != 0 )
        {
          v12 = codec;
          do
          {
            result = ReadTileHeaderQuantizerLP(codec: v12, pIO: v4->bitIOLP, a3);
            if ( result != HDP_ERROR_NONE )
              return result;
            v12 = v12->nextCodec;
          }
          while ( v12 != nullptr );
        }
        if ( codec->codecParms.subBands < SB_NO_HIGHPASS && (codec->codecParms.quantizationMode & 4) != 0 )
        {
          v13 = codec;
          do
          {
            result = ReadTileHeaderQuantizerHP(codec: v13, pIO: v4->bitIOHP, a3);
            if ( result != HDP_ERROR_NONE )
              return result;
            v13 = v13->nextCodec;
          }
          while ( v13 != nullptr );
        }
        if ( codec->codecParms.subBands < SB_NO_FLEXBITS && codec->codecParms.hasPerTileTrimFlexbits )
        {
          bitIOFL = v4->bitIOFL;
          bitCnt = bitIOFL->bitCnt;
          bitBuff = bitIOFL->bitBuff;
          HIDWORD(bitCnt) = bitBuff;
          v20 = bitCnt;
          if ( (unsigned int)bitCnt < 4 )
          {
            HIDWORD(a3) = &v20;
            FillBitBuffer(pIO: bitIOFL, &bitBuff, bitCnt: a3);
            bitCnt = v20;
          }
          v16 = &off_82230000;
          LODWORD(bitCnt) = bitCnt - 4;
          v18 = *(unsigned __int64 *)((char *)&bitCnt + 4) >> bitCnt;
          v17 = 15;
          bitIOFL->bitBuff = *(unsigned __int64 *)((char *)&bitCnt + 4);
          bitIOFL->bitCnt = bitCnt;
          v4->trimTileFlexBits = v18 & 0xF;
        }
LABEL_40:
        ResetCodingContext(context: v4);
        return HDP_ERROR_NONE;
      }
    }
  }
  return result;
}


// ========================================================================
// GetVLWordEsc
// EA  : 0x828EE870
// RVA : 0x008EE870
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdec.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall GetVLWordEsc(hdpBitIO_t *pIO, int *iEscape, __int64 a3)
{
  unsigned __int64 bitCnt; // r11 OVERLAPPED
  bool (__fastcall **v6)(idAIEvent *__hidden, const struct idEntity *, int); // r9
  int v7; // r9 OVERLAPPED
  unsigned __int64 v8; // r8 OVERLAPPED
  int v9; // r30
  __int128 v10; // r11
  int v12; // r30
  unsigned __int64 v13; // r11
  unsigned __int64 v14; // r10
  unsigned __int64 v15; // r11 OVERLAPPED
  int v16; // r9
  __int64 v17; // r6
  int v18; // r30
  unsigned __int64 v19; // r10
  __int128 v20; // r11
  unsigned __int64 bitBuff; // [sp+50h] [-40h] BYREF
  unsigned __int64 v22[7]; // [sp+58h] [-38h] BYREF

  if ( iEscape != nullptr )
    *iEscape = 0;
  bitCnt = pIO->bitCnt;
  bitBuff = pIO->bitBuff;
  HIDWORD(bitCnt) = bitBuff;
  v22[0] = bitCnt;
  if ( (unsigned int)bitCnt < 8 )
  {
    HIDWORD(a3) = v22;
    FillBitBuffer(pIO, &bitBuff, bitCnt: a3);
    bitCnt = v22[0];
  }
  v6 = &off_82230000;
  LODWORD(bitCnt) = bitCnt - 8;
  v8 = *(unsigned __int64 *)((char *)&bitCnt + 4) >> bitCnt;
  HIDWORD(v8) = *(unsigned __int64 *)((char *)&bitCnt + 4) >> bitCnt;
  v7 = 255;
  pIO->bitBuff = *(unsigned __int64 *)((char *)&bitCnt + 4);
  v9 = BYTE3(v8);
  pIO->bitCnt = bitCnt;
  if ( BYTE3(v8) == 253 || BYTE3(v8) == 254 || BYTE3(v8) == 255 )
  {
    if ( iEscape != nullptr )
      *iEscape = BYTE3(v8);
    return 0;
  }
  else if ( BYTE3(v8) >= 0xFBu )
  {
    v12 = BYTE3(v8) - 251;
    if ( BYTE3(v8) != 251 )
    {
      bitBuff = bitCnt;
      v22[0] = *(unsigned __int64 *)((char *)&bitCnt + 4);
      if ( (unsigned int)bitCnt < 0x10 )
      {
        HIDWORD(a3) = &bitBuff;
        FillBitBuffer(pIO, bitBuff: v22, bitCnt: a3);
        v7 = HIDWORD(v22[0]);
      }
      v13 = bitBuff;
      pIO->bitBuff = *(_QWORD *)(&v7 - 1);
      LODWORD(v13) = v13 - 16;
      bitBuff = *(_QWORD *)(&v7 - 1);
      v22[0] = v13;
      pIO->bitCnt = v13;
      if ( (unsigned int)v13 < 0x10 )
      {
        HIDWORD(a3) = v22;
        FillBitBuffer(pIO, &bitBuff, bitCnt: a3);
      }
      LODWORD(v14) = bitBuff;
      v12 = 0;
      HIDWORD(v14) = LODWORD(v22[0]) - 16;
      pIO->bitCnt = *(unsigned __int64 *)((char *)&v8 - 4);
      pIO->bitBuff = v14;
    }
    v15 = pIO->bitCnt;
    v22[0] = pIO->bitBuff;
    HIDWORD(v15) = v22[0];
    bitBuff = v15;
    if ( (unsigned int)v15 < 0x10 )
    {
      HIDWORD(a3) = &bitBuff;
      FillBitBuffer(pIO, bitBuff: v22, bitCnt: a3);
      v15 = bitBuff;
    }
    LODWORD(v15) = v15 - 16;
    v16 = 0xFFFF;
    v22[0] = *(unsigned __int64 *)((char *)&v15 + 4);
    pIO->bitCnt = v15;
    pIO->bitBuff = *(unsigned __int64 *)((char *)&v15 + 4);
    bitBuff = v15;
    LODWORD(v17) = (unsigned __int16)(*(unsigned __int64 *)((char *)&v15 + 4) >> v15);
    v18 = ((_DWORD)v17 << 16) | v12;
    if ( (unsigned int)v15 < 0x10 )
    {
      HIDWORD(v17) = &bitBuff;
      FillBitBuffer(pIO, bitBuff: v22, bitCnt: v17);
    }
    v19 = HIDWORD(bitBuff) | 0xFFFF00000000LL;
    LODWORD(v20) = bitBuff - 16;
    pIO->bitBuff = v19;
    *(_QWORD *)((char *)&v20 + 4) = v19 >> v20;
    pIO->bitCnt = v20;
    return DWORD2(v20) & DWORD1(v20) | v18;
  }
  else
  {
    bitBuff = bitCnt;
    v22[0] = *(unsigned __int64 *)((char *)&bitCnt + 4);
    if ( (unsigned int)bitCnt < 8 )
    {
      HIDWORD(a3) = &bitBuff;
      FillBitBuffer(pIO, bitBuff: v22, bitCnt: a3);
    }
    *(_QWORD *)((char *)&v10 + 4) = HIDWORD(bitBuff) | 0xFF00000000LL;
    LODWORD(v10) = bitBuff - 8;
    pIO->bitBuff = *(_QWORD *)((char *)&v10 + 4);
    pIO->bitCnt = v10;
    return (v9 << 8) | (*(_QWORD *)((char *)&v10 + 4) >> v10) & DWORD1(v10);
  }
}


// ========================================================================
// ReadIndexTable
// EA  : 0x828EEA90
// RVA : 0x008EEA90
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdec.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall ReadIndexTable(hdpCodec_t *codec, int a2, __int64 a3)
{
  hdpBitIO_t *bitIOHeader; // r31
  unsigned __int64 bitCnt; // r11 OVERLAPPED
  bool (__fastcall **v6)(idAIEvent *__hidden, const struct idEntity *, int); // r9
  int v7; // r9
  unsigned int v9; // r29
  int v10; // r28
  unsigned __int64 v11; // r9
  unsigned __int64 bitBuff; // [sp+50h] [-40h] BYREF
  unsigned __int64 v13; // [sp+58h] [-38h] BYREF

  bitIOHeader = codec->bitIOHeader;
  if ( codec->numTileBitIOs != 0 )
  {
    bitCnt = bitIOHeader->bitCnt;
    bitBuff = bitIOHeader->bitBuff;
    HIDWORD(bitCnt) = bitBuff;
    v13 = bitCnt;
    if ( (unsigned int)bitCnt < 0x10 )
    {
      HIDWORD(a3) = &v13;
      FillBitBuffer(pIO: bitIOHeader, &bitBuff, bitCnt: a3);
      bitCnt = v13;
    }
    v6 = &off_82230000;
    LODWORD(bitCnt) = bitCnt - 16;
    LODWORD(a3) = *(unsigned __int64 *)((char *)&bitCnt + 4) >> bitCnt;
    v7 = 0xFFFF;
    bitIOHeader->bitBuff = *(unsigned __int64 *)((char *)&bitCnt + 4);
    HIDWORD(a3) = (unsigned __int16)a3;
    bitIOHeader->bitCnt = bitCnt;
    if ( (unsigned __int16)a3 != 1 )
      return -5;
    v9 = (codec->codecParms.numTilesHighMinusOne + 1) * codec->numTileBitIOs;
    if ( v9 != 0 )
    {
      v10 = 0;
      do
      {
        --v9;
        codec->tileIndex[v10++] = GetVLWordEsc(pIO: bitIOHeader, iEscape: nullptr, a3);
      }
      while ( v9 != 0 );
    }
  }
  codec->baseTileOffset = GetVLWordEsc(pIO: bitIOHeader, iEscape: nullptr, a3);
  LODWORD(v11) = LODWORD(bitIOHeader->bitCnt) - (bitIOHeader->bitCnt & 7);
  bitIOHeader->bitCnt = v11;
  codec->baseTileOffset += codec->bitIOHeader->streamOffset
                         - (codec->bitIOHeader->bitCnt >> 3)
                         + codec->bitIOHeader->byteCount;
  return 0;
}


// ========================================================================
// InitImagePlaneDec
// EA  : 0x828EEBA8
// RVA : 0x008EEBA8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdec.cpp
// ========================================================================

hdpError_t __fastcall InitImagePlaneDec(hdpCodec_t *codec)
{
  hdpError_t result; // r3
  hdpColorFormat_t colorFormat; // r11
  hdpColorFormat_t v4; // r10
  bool v5; // r11
  int v6; // r11
  unsigned int v7; // r29
  __int16 *v8; // r3
  __int16 *resampleU; // r8
  unsigned int v10; // r11
  int v11; // r9
  unsigned __int8 v12; // r10
  hdpQuantizer_t *v13; // r6
  unsigned int v14; // r11
  int v15; // r9
  unsigned __int8 v16; // r10
  hdpQuantizer_t *v17; // r6
  unsigned int v18; // r11
  int v19; // r9
  unsigned __int8 v20; // r10
  hdpQuantizer_t *v21; // r6
  unsigned int v22; // r11
  int v23; // r10

  if ( codec->codecParms.numTilesWideMinusOne >= 0x1000 )
    return HDP_ERROR_INVALID_PARM;
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
    v6 = 128;
    if ( v4 != CF_YUV_422 )
      v6 = 256;
    v7 = 2 * codec->widthInMacroblocks * v6;
    codec->resampleU = (__int16 *)TempAlloc(codecParms: &codec->codecParms, size: v7, align: 0x10u);
    v8 = (__int16 *)TempAlloc(codecParms: &codec->codecParms, size: v7, align: 0x10u);
    resampleU = codec->resampleU;
    codec->resampleV = v8;
    if ( resampleU == nullptr || v8 == nullptr )
      return HDP_ERROR_OUT_OF_MEMORY;
  }
  result = AllocateTileQuantization(codec);
  if ( result == HDP_ERROR_NONE )
  {
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
      v10 = 0;
      if ( codec->codecParms.numChannels != 0 )
      {
        v11 = 0;
        do
        {
          if ( codec->codecParms.transcode )
            v12 = 0;
          else
            v12 = codec->codecParms.quantizerIndexDC[v10];
          ++v10;
          v13 = codec->tileQuantization->pQuantizerDC[v11++];
          v13->iIndex = v12;
        }
        while ( v10 < codec->codecParms.numChannels );
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
      if ( (codec->codecParms.quantizationMode & 0x200) != 0 )
      {
        v14 = 0;
        if ( codec->codecParms.numChannels != 0 )
        {
          v15 = 16;
          do
          {
            if ( codec->codecParms.transcode )
              v16 = 0;
            else
              v16 = codec->codecParms.quantizerIndexLP[v14];
            ++v14;
            v17 = codec->tileQuantization->pQuantizerDC[v15++];
            v17->iIndex = v16;
          }
          while ( v14 < codec->codecParms.numChannels );
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
      else
      {
        UseDCQuantizerForLP(codec, iTile: 0);
      }
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
      if ( (codec->codecParms.quantizationMode & 0x400) != 0 )
      {
        v18 = 0;
        if ( codec->codecParms.numChannels != 0 )
        {
          v19 = 32;
          do
          {
            if ( codec->codecParms.transcode )
              v20 = 0;
            else
              v20 = codec->codecParms.quantizerIndexHP[v18];
            ++v18;
            v21 = codec->tileQuantization->pQuantizerDC[v19++];
            v21->iIndex = v20;
          }
          while ( v18 < codec->codecParms.numChannels );
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
      else
      {
        UseLPQuantizerForHP(codec, numQuantizers: 1u, iTile: 0);
      }
    }
    result = AllocatePredictionInfo(codec);
    if ( result == HDP_ERROR_NONE )
    {
      result = AllocateCodingContexts(codec);
      if ( result == HDP_ERROR_NONE )
      {
        v22 = 0;
        v23 = 0;
        do
        {
          ++v22;
          codec->tileContexts[v23++].trimTileFlexBits = codec->codecParms.uniformTrimFlexBits;
        }
        while ( v22 <= codec->codecParms.numTilesWideMinusOne );
        return HDP_ERROR_NONE;
      }
    }
  }
  return result;
}


// ========================================================================
// ReadImagePlaneHeader
// EA  : 0x828EEF68
// RVA : 0x008EEF68
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdec.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall ReadImagePlaneHeader(hdpCodecParms_t *codecParms, hdpBitIO_t *pIO, __int64 a3)
{
  unsigned __int64 bitCnt; // r11 OVERLAPPED
  bool (__fastcall **v6)(idAIEvent *__hidden, const struct idEntity *, int); // r9
  int v7; // r9
  int v8; // r7
  unsigned __int64 v9; // r11 OVERLAPPED
  __int64 v10; // r6
  int v11; // r9
  unsigned __int64 v12; // r9 OVERLAPPED
  unsigned __int64 v13; // r6
  unsigned __int64 v14; // r11 OVERLAPPED
  int v15; // r9
  hdpSubBands_t v16; // r9
  hdpColorFormat_t colorFormat; // r11
  unsigned int v18; // r11
  unsigned __int64 v19; // r11 OVERLAPPED
  int v20; // r10
  unsigned __int64 v21; // r11 OVERLAPPED
  int v22; // r9
  unsigned __int64 v23; // r9 OVERLAPPED
  unsigned __int64 v24; // r11 OVERLAPPED
  unsigned __int64 v25; // r11 OVERLAPPED
  int v26; // r9
  unsigned __int64 v27; // r9 OVERLAPPED
  unsigned int v28; // r11
  unsigned __int64 v29; // r11 OVERLAPPED
  int v30; // r9
  int v31; // r10
  unsigned __int64 v32; // r11 OVERLAPPED
  int v33; // r9
  unsigned __int64 v34; // r11 OVERLAPPED
  int v35; // r9
  int v36; // r10
  unsigned __int64 v37; // r11 OVERLAPPED
  int v38; // r9
  hdpSubBands_t subBands; // r11
  unsigned int v40; // r10
  unsigned __int64 bitBuff; // [sp+50h] [-30h] BYREF
  unsigned __int64 v43[5]; // [sp+58h] [-28h] BYREF

  bitCnt = pIO->bitCnt;
  bitBuff = pIO->bitBuff;
  HIDWORD(bitCnt) = bitBuff;
  v43[0] = bitCnt;
  if ( (unsigned int)bitCnt < 3 )
  {
    HIDWORD(a3) = v43;
    FillBitBuffer(pIO, &bitBuff, bitCnt: a3);
    bitCnt = v43[0];
  }
  v6 = &off_82230000;
  LODWORD(bitCnt) = bitCnt - 3;
  v8 = *(unsigned __int64 *)((char *)&bitCnt + 4) >> bitCnt;
  v7 = 7;
  pIO->bitBuff = *(unsigned __int64 *)((char *)&bitCnt + 4);
  pIO->bitCnt = bitCnt;
  codecParms->colorFormat = v8 & 7;
  v9 = pIO->bitCnt;
  v43[0] = pIO->bitBuff;
  HIDWORD(v9) = v43[0];
  bitBuff = v9;
  if ( (_DWORD)v9 == 0 )
  {
    HIDWORD(v10) = &bitBuff;
    LODWORD(v10) = v8 & 7;
    FillBitBuffer(pIO, bitBuff: v43, bitCnt: v10);
    v9 = bitBuff;
  }
  LODWORD(v9) = v9 - 1;
  v11 = 1;
  pIO->bitBuff = *(unsigned __int64 *)((char *)&v9 + 4);
  *(unsigned __int64 *)((char *)&v9 + 4) >>= v9;
  pIO->bitCnt = v9;
  HIDWORD(v12) = HIDWORD(v9);
  LODWORD(v13) = (HIDWORD(v9) & v12) - 1;
  codecParms->useScaledArith = (HIDWORD(v9) & (unsigned int)v12) != 0;
  v43[0] = pIO->bitBuff;
  bitBuff = pIO->bitCnt;
  v14 = bitBuff;
  if ( (unsigned int)bitBuff < 4 )
  {
    HIDWORD(v13) = &bitBuff;
    FillBitBuffer(pIO, bitBuff: v43, bitCnt: v13);
    v14 = bitBuff;
  }
  LODWORD(v14) = v14 - 4;
  v15 = 15;
  pIO->bitBuff = *(unsigned __int64 *)((char *)&v14 + 4);
  pIO->bitCnt = v14;
  v16 = (*(unsigned __int64 *)((char *)&v14 + 4) >> v14) & 0xF;
  colorFormat = codecParms->colorFormat;
  codecParms->subBands = v16;
  if ( (unsigned int)colorFormat <= CF_N_CHANNEL )
  {
    switch ( colorFormat )
    {
      case CF_YUV_420:
      case CF_YUV_422:
      case CF_YUV_444:
        codecParms->numChannels = 3;
        *(unsigned __int64 *)((char *)&v12 - 4) = pIO->bitBuff;
        bitBuff = pIO->bitCnt;
        v19 = bitBuff;
        v43[0] = *(unsigned __int64 *)((char *)&v12 - 4);
        if ( (unsigned int)bitBuff < 4 )
        {
          HIDWORD(v13) = &bitBuff;
          FillBitBuffer(pIO, bitBuff: v43, bitCnt: v13);
          LODWORD(v12) = HIDWORD(v43[0]);
          v19 = bitBuff;
        }
        LODWORD(v19) = v19 - 4;
        pIO->bitBuff = *(unsigned __int64 *)((char *)&v12 - 4);
        bitBuff = *(unsigned __int64 *)((char *)&v12 - 4);
        v43[0] = v19;
        pIO->bitCnt = v19;
        if ( (unsigned int)v19 < 4 )
        {
          HIDWORD(v13) = v43;
          FillBitBuffer(pIO, &bitBuff, bitCnt: v13);
        }
        v20 = bitBuff;
        LODWORD(v12) = LODWORD(v43[0]) - 4;
        pIO->bitCnt = v12;
        pIO->bitBuff = *(unsigned __int64 *)((char *)&v12 - 4);
        break;
      case CF_CMYK:
      case CF_BAYER:
        v18 = 4;
        goto LABEL_26;
      case CF_Y_ONLY:
        v18 = 1;
LABEL_26:
        codecParms->numChannels = v18;
        break;
      default:
        v21 = pIO->bitCnt;
        v43[0] = pIO->bitBuff;
        HIDWORD(v21) = v43[0];
        bitBuff = v21;
        if ( (unsigned int)v21 < 4 )
        {
          HIDWORD(v13) = &bitBuff;
          FillBitBuffer(pIO, bitBuff: v43, bitCnt: v13);
          v21 = bitBuff;
        }
        v22 = 15;
        LODWORD(v21) = v21 - 4;
        pIO->bitBuff = *(unsigned __int64 *)((char *)&v21 + 4);
        *(unsigned __int64 *)((char *)&v21 + 4) >>= v21;
        pIO->bitCnt = v21;
        HIDWORD(v23) = HIDWORD(v21);
        codecParms->numChannels = (HIDWORD(v21) & v23) + 1;
        v13 = pIO->bitBuff;
        v24 = pIO->bitCnt;
        bitBuff = pIO->bitBuff;
        v43[0] = v24;
        if ( (unsigned int)v24 < 4 )
        {
          HIDWORD(v13) = v43;
          FillBitBuffer(pIO, &bitBuff, bitCnt: v13);
          LODWORD(v24) = v43[0];
        }
        HIDWORD(v24) = bitBuff;
        LODWORD(v23) = v24 - 4;
        pIO->bitCnt = v23;
        pIO->bitBuff = *(unsigned __int64 *)((char *)&v24 + 4);
        break;
    }
  }
  codecParms->quantizationMode = 0;
  v43[0] = pIO->bitBuff;
  bitBuff = pIO->bitCnt;
  v25 = bitBuff;
  if ( (_DWORD)bitBuff == 0 )
  {
    HIDWORD(v13) = &bitBuff;
    FillBitBuffer(pIO, bitBuff: v43, bitCnt: v13);
    v25 = bitBuff;
  }
  LODWORD(v25) = v25 - 1;
  v26 = 1;
  pIO->bitBuff = *(unsigned __int64 *)((char *)&v25 + 4);
  *(unsigned __int64 *)((char *)&v25 + 4) >>= v25;
  pIO->bitCnt = v25;
  HIDWORD(v27) = HIDWORD(v25);
  if ( (HIDWORD(v25) & (unsigned int)v27) == 1 )
  {
    HIDWORD(v13) = codecParms->numChannels;
    v28 = ((8 * ReadQuantizerIndex(pQPIndex: codecParms->quantizerIndexDC, pIO, numChannels: v13)) & 0x7F8)
        + codecParms->quantizationMode;
  }
  else
  {
    v28 = codecParms->quantizationMode + 1;
  }
  codecParms->quantizationMode = v28;
  if ( codecParms->subBands < SB_NO_LOWPASS )
  {
    v29 = pIO->bitCnt;
    v43[0] = pIO->bitBuff;
    HIDWORD(v29) = v43[0];
    bitBuff = v29;
    if ( (_DWORD)v29 == 0 )
    {
      HIDWORD(v13) = &bitBuff;
      FillBitBuffer(pIO, bitBuff: v43, bitCnt: v13);
      v29 = bitBuff;
    }
    LODWORD(v29) = v29 - 1;
    v30 = 1;
    pIO->bitBuff = *(unsigned __int64 *)((char *)&v29 + 4);
    pIO->bitCnt = v29;
    *(unsigned __int64 *)((char *)&v27 - 4) = *(unsigned __int64 *)((char *)&v29 + 4) >> v29;
    HIDWORD(v27) = v31;
    if ( (v31 & (unsigned int)v27) != 0 )
    {
      codecParms->quantizationMode += 2
                                    * (((2 * codecParms->quantizationMode) & 0x30) + (codecParms->quantizationMode & 1));
    }
    else
    {
      codecParms->quantizationMode += 512;
      v32 = pIO->bitCnt;
      v43[0] = pIO->bitBuff;
      HIDWORD(v32) = v43[0];
      bitBuff = v32;
      if ( (_DWORD)v32 == 0 )
      {
        HIDWORD(v13) = &bitBuff;
        FillBitBuffer(pIO, bitBuff: v43, bitCnt: v13);
        v32 = bitBuff;
      }
      LODWORD(v32) = v32 - 1;
      v33 = 1;
      pIO->bitBuff = *(unsigned __int64 *)((char *)&v32 + 4);
      *(unsigned __int64 *)((char *)&v27 - 4) = *(unsigned __int64 *)((char *)&v32 + 4) >> v32;
      pIO->bitCnt = v32;
      HIDWORD(v27) = HIDWORD(v32);
      if ( (HIDWORD(v32) & (unsigned int)v27) == 1 )
      {
        HIDWORD(v13) = codecParms->numChannels;
        codecParms->quantizationMode += (32
                                       * ReadQuantizerIndex(
                                           pQPIndex: codecParms->quantizerIndexLP,
                                           pIO,
                                           numChannels: v13))
                                      & 0x1FE0;
      }
      else
      {
        codecParms->quantizationMode += 2;
      }
    }
  }
  if ( codecParms->subBands < SB_NO_HIGHPASS )
  {
    v34 = pIO->bitCnt;
    v43[0] = pIO->bitBuff;
    HIDWORD(v34) = v43[0];
    bitBuff = v34;
    if ( (_DWORD)v34 == 0 )
    {
      HIDWORD(v13) = &bitBuff;
      FillBitBuffer(pIO, bitBuff: v43, bitCnt: v13);
      v34 = bitBuff;
    }
    LODWORD(v34) = v34 - 1;
    v35 = 1;
    pIO->bitBuff = *(unsigned __int64 *)((char *)&v34 + 4);
    pIO->bitCnt = v34;
    *(unsigned __int64 *)((char *)&v27 - 4) = *(unsigned __int64 *)((char *)&v34 + 4) >> v34;
    HIDWORD(v27) = v36;
    if ( (v36 & (unsigned int)v27) != 0 )
    {
      codecParms->quantizationMode += 2
                                    * (((2 * codecParms->quantizationMode) & 0xC0) + (codecParms->quantizationMode & 2));
    }
    else
    {
      codecParms->quantizationMode += 1024;
      v37 = pIO->bitCnt;
      v43[0] = pIO->bitBuff;
      HIDWORD(v37) = v43[0];
      bitBuff = v37;
      if ( (_DWORD)v37 == 0 )
      {
        HIDWORD(v13) = &bitBuff;
        FillBitBuffer(pIO, bitBuff: v43, bitCnt: v13);
        v37 = bitBuff;
      }
      LODWORD(v37) = v37 - 1;
      v38 = 1;
      pIO->bitBuff = *(unsigned __int64 *)((char *)&v37 + 4);
      *(unsigned __int64 *)((char *)&v27 - 4) = *(unsigned __int64 *)((char *)&v37 + 4) >> v37;
      pIO->bitCnt = v37;
      HIDWORD(v27) = HIDWORD(v37);
      if ( (HIDWORD(v37) & (unsigned int)v27) == 1 )
      {
        HIDWORD(v13) = codecParms->numChannels;
        codecParms->quantizationMode += (ReadQuantizerIndex(
                                           pQPIndex: codecParms->quantizerIndexHP,
                                           pIO,
                                           numChannels: v13) << 7)
                                      & 0x7F80;
      }
      else
      {
        codecParms->quantizationMode += 4;
      }
    }
  }
  subBands = codecParms->subBands;
  if ( subBands == SB_NO_LOWPASS )
  {
    v40 = codecParms->quantizationMode | 0x200;
  }
  else
  {
    if ( subBands != SB_NO_HIGHPASS )
      goto LABEL_57;
    v40 = codecParms->quantizationMode | 0x400;
  }
  codecParms->quantizationMode = v40;
LABEL_57:
  if ( (codecParms->quantizationMode & 0x600) == 0 )
    return -5;
  LODWORD(v27) = LODWORD(pIO->bitCnt) - (pIO->bitCnt & 7);
  pIO->bitCnt = v27;
  return 0;
}


// ========================================================================
// ReadImageHeader
// EA  : 0x828EF4D0
// RVA : 0x008EF4D0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdec.cpp
// ========================================================================

hdpError_t __fastcall ReadImageHeader(hdpImageInfo_t *imageInfo, hdpCodecParms_t *codecParms, hdpBitIO_t *pIO)
{
  unsigned int v5; // r11
  unsigned int v6; // r11
  unsigned int *v7; // r3
  unsigned int *v8; // r3
  unsigned int imageHeight; // r9
  unsigned int v11; // r6

  v5 = imageInfo->imageWidth & 0xF;
  if ( v5 != 0 )
    codecParms->extraPixelsRight = 16 - v5;
  v6 = imageInfo->imageHeight & 0xF;
  if ( v6 != 0 )
    codecParms->extraPixelsBottom = 16 - v6;
  codecParms->numTilesWideMinusOne = 0;
  codecParms->numTilesHighMinusOne = 0;
  v7 = (unsigned int *)TempAlloc(codecParms, size: 4u, align: 0x10u);
  codecParms->tileMacroblockOffsetX = v7;
  *v7 = 0;
  v8 = (unsigned int *)TempAlloc(codecParms, size: 4 * (codecParms->numTilesHighMinusOne + 1), align: 0x10u);
  codecParms->tileMacroblockOffsetY = v8;
  *v8 = 0;
  imageHeight = imageInfo->imageHeight;
  imageInfo->fullImageWidth = codecParms->extraPixelsRight + imageInfo->imageWidth + codecParms->extraPixelsLeft;
  imageInfo->fullImageHeight = codecParms->extraPixelsBottom + imageHeight + codecParms->extraPixelsTop;
  v11 = codecParms->fullImageROITopY + codecParms->extraPixelsTop;
  codecParms->fullImageROILeftX += codecParms->extraPixelsLeft;
  codecParms->fullImageROITopY = v11;
  return HDP_ERROR_NONE;
}


// ========================================================================
// ProcessMacroblockDec
// EA  : 0x828EF5C0
// RVA : 0x008EF5C0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdec.cpp
// ========================================================================

hdpError_t __fastcall ProcessMacroblockDec(hdpCodec_t *firstCodec)
{
  unsigned __int8 v2; // r11
  hdpCodec_t *v3; // r31
  int v4; // r27
  int v5; // r29
  BOOL decodeFullFrame; // r10
  unsigned int currentMacroblockColumn; // r4
  unsigned int v8; // r11
  bool v9; // r30
  unsigned __int64 v10; // r6
  int v11; // r4
  hdpError_t result; // r3

  if ( firstCodec->currentMacroblockRow == firstCodec->heightInMacroblocks
    || (v2 = 0, firstCodec->currentMacroblockColumn == firstCodec->widthInMacroblocks) )
  {
    v2 = 1;
  }
  v3 = firstCodec;
  v4 = v2;
  v5 = firstCodec->codecParms.overlap == OL_NONE ? 0 : 0x10;
  while ( 1 )
  {
    decodeFullFrame = v3->codecParms.decodeFullFrame;
    v3->currentMacroblockRow = firstCodec->currentMacroblockRow;
    currentMacroblockColumn = firstCodec->currentMacroblockColumn;
    v3->currentMacroblockColumn = currentMacroblockColumn;
    v9 = true;
    if ( !decodeFullFrame
      && (16 * currentMacroblockColumn + v5 < v3->codecParms.fullImageROILeftX
       || 16 * currentMacroblockColumn > v3->codecParms.fullImageROIRightX + v5
       || (v8 = 16 * v3->currentMacroblockRow) + v5 < v3->codecParms.fullImageROITopY
       || v8 > v3->codecParms.fullImageROIBottomY + v5) )
    {
      v9 = false;
    }
    if ( v4 == 0 )
    {
      UpdateTilePos(codec: v3, mbX: currentMacroblockColumn, mbY: v3->currentMacroblockRow);
      if ( v3->atTileLeftMB && v3->atTileTopMB )
      {
        result = ReadTileHeader(codec: v3, a2: v11, a3: v10);
        if ( result != HDP_ERROR_NONE )
          break;
      }
      result = DecodeMacroblock(
                 codec: v3,
                 context: &v3->tileContexts[v3->currentTileColumn],
                 mbX: v3->currentMacroblockColumn,
                 mbY: v3->currentMacroblockRow);
      if ( result != HDP_ERROR_NONE )
        break;
      if ( v9 )
      {
        result = DequantizeMacroblock(codec: v3);
        if ( result != HDP_ERROR_NONE )
          break;
      }
    }
    if ( v9 && !v3->codecParms.decodeCoeffientsOnly )
      InvTransformMacroblock_Xenon_16(codec: v3);
    v3 = v3->nextCodec;
    if ( v3 == nullptr )
      return HDP_ERROR_NONE;
  }
  return result;
}


// ========================================================================
// ?HDPDecDecodeMBRow@@YA?AW4hdpError_t@@PAUhdpCodec_t@@@Z
// EA  : 0x828EF740
// RVA : 0x008EF740
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdec.cpp
// ========================================================================

hdpError_t __fastcall HDPDecDecodeMBRow(hdpCodec_t *firstCodec)
{
  hdpError_t result; // r3
  unsigned int *tileMacroblockOffsetX; // r11
  unsigned int fullImageROIRightTile; // r10
  unsigned int v5; // r28
  unsigned int widthInMacroblocks; // r11
  unsigned int v7; // r27
  unsigned int *tileMacroblockOffsetY; // r11
  unsigned int fullImageROIBottomTile; // r10
  unsigned int v10; // r29
  unsigned int heightInMacroblocks; // r11
  unsigned int v12; // r31
  hdpCodec_t *v13; // r10
  unsigned int v14; // r11
  unsigned int v15; // r9
  unsigned int i; // r7
  unsigned int v17; // r11
  unsigned int v18; // r9
  unsigned int fullImageROITopTile; // r11
  unsigned int fullImageROILeftTile; // r11
  unsigned int v21; // r10

  if ( firstCodec == nullptr )
    return HDP_ERROR_DECODE;
  tileMacroblockOffsetX = firstCodec->codecParms.tileMacroblockOffsetX;
  fullImageROIRightTile = firstCodec->codecParms.fullImageROIRightTile;
  v5 = tileMacroblockOffsetX[firstCodec->codecParms.fullImageROILeftTile];
  if ( fullImageROIRightTile >= firstCodec->codecParms.numTilesWideMinusOne )
    widthInMacroblocks = firstCodec->widthInMacroblocks;
  else
    widthInMacroblocks = tileMacroblockOffsetX[fullImageROIRightTile + 1];
  v7 = widthInMacroblocks - 1;
  tileMacroblockOffsetY = firstCodec->codecParms.tileMacroblockOffsetY;
  fullImageROIBottomTile = firstCodec->codecParms.fullImageROIBottomTile;
  v10 = tileMacroblockOffsetY[firstCodec->codecParms.fullImageROITopTile];
  if ( fullImageROIBottomTile >= firstCodec->codecParms.numTilesHighMinusOne )
    heightInMacroblocks = firstCodec->heightInMacroblocks;
  else
    heightInMacroblocks = tileMacroblockOffsetY[fullImageROIBottomTile + 1];
  v12 = heightInMacroblocks - 1;
  if ( firstCodec->processedFirstMBRow )
  {
    SwapMacroblockPredPtrs(firstCodec);
    SwapMacroblockRowPtrs(firstCodec);
    ++firstCodec->currentMacroblockRow;
  }
  if ( firstCodec->currentMacroblockRow > v12 + 1 )
    return HDP_ERROR_NONE;
  InitMacroblockColumnPtrs(firstCodec);
  v13 = firstCodec;
  do
  {
    v14 = 0;
    v15 = v13->widthInMacroblocks << 9;
    if ( v15 != 0 )
    {
      do
      {
        __asm { dcbz128   r11, r8 }
        v14 += 128;
      }
      while ( v14 < v15 );
    }
    for ( i = 1; i < v13->codecParms.numChannels; ++i )
    {
      v17 = 0;
      v18 = 2 * v13->widthInMacroblocks * 16 * cblkChromas[v13->codecParms.colorFormat];
      if ( v18 != 0 )
      {
        do
        {
          __asm { dcbz128   r11, r8 }
          v17 += 128;
        }
        while ( v17 < v18 );
      }
    }
    if ( !firstCodec->processedFirstMBRow )
    {
      fullImageROITopTile = firstCodec->codecParms.fullImageROITopTile;
      v13->currentMacroblockRow = v10;
      v13->currentTileRow = fullImageROITopTile;
    }
    fullImageROILeftTile = firstCodec->codecParms.fullImageROILeftTile;
    v13->currentMacroblockColumn = v5;
    v13->currentTileColumn = fullImageROILeftTile;
    v13 = v13->nextCodec;
  }
  while ( v13 != nullptr );
  firstCodec->currentMacroblockColumn = v5;
  if ( v5 > v7 )
  {
LABEL_25:
    result = ProcessMacroblockDec(firstCodec);
    if ( result != HDP_ERROR_NONE )
      return result;
    firstCodec->processedFirstMBRow = true;
    return HDP_ERROR_NONE;
  }
  while ( 1 )
  {
    result = ProcessMacroblockDec(firstCodec);
    if ( result != HDP_ERROR_NONE )
      return result;
    AdvanceMacroblockColumnPtrs(firstCodec);
    v21 = firstCodec->currentMacroblockColumn + 1;
    firstCodec->currentMacroblockColumn = v21;
    if ( v21 > v7 )
      goto LABEL_25;
  }
}


// ========================================================================
// ?HDPDecShutdown@@YA?AW4hdpError_t@@PAUhdpCodec_t@@@Z
// EA  : 0x828EF940
// RVA : 0x008EF940
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdec.cpp
// ========================================================================

int __fastcall HDPDecShutdown(hdpCodec_t *firstCodec)
{
  hdpCodec_t *v3; // r31
  hdpCodec_t *nextCodec; // r27
  unsigned __int64 v5; // r6
  int v6; // r4
  unsigned int v7; // r30
  int v8; // r29

  if ( firstCodec == nullptr )
    return -5;
  v3 = firstCodec;
  do
  {
    nextCodec = v3->nextCodec;
    if ( v3->codecParms.changeSubsamplingUV )
    {
      if ( v3->resampleU != nullptr )
        idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v3->codecParms);
      if ( v3->resampleV != nullptr )
        idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v3->codecParms);
    }
    FreePredictionInfo(codec: v3);
    FreeTileQuantization(codec: v3);
    FreeCodingContexts(codec: v3);
    if ( v3 == firstCodec )
    {
      StreamReadDetach(pIO: v3->bitIOHeader, a2: v6, a3: v5);
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v3->codecParms);
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v3->codecParms);
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v3->codecParms);
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v3->codecParms);
      v7 = 0;
      if ( v3->numTileBitIOs != 0 )
      {
        v8 = 0;
        do
        {
          v3->tileStreams[v8]->Close(a1: v3->tileStreams[v8]);
          ++v7;
          ++v8;
        }
        while ( v7 < v3->numTileBitIOs );
      }
      if ( v3->rotFlipOffsetX != nullptr )
        idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v3->codecParms);
      if ( v3->rotFlipOffsetY != nullptr )
        idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v3->codecParms);
    }
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v3->codecParms);
    v3 = nextCodec;
  }
  while ( nextCodec != nullptr );
  return 0;
}


// ========================================================================
// DeriveDecoderParms
// EA  : 0x828EFA88
// RVA : 0x008EFA88
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdec.cpp
// ========================================================================

void __fastcall DeriveDecoderParms(hdpCodec_t *codec)
{
  unsigned int fullImageROILeftX; // r29
  unsigned int fullImageWidth; // r8
  unsigned int fullImageROIRightX; // r28
  unsigned int fullImageROITopY; // r30
  unsigned int extraPixelsBottom; // r8
  unsigned int fullImageROIBottomY; // r31
  unsigned int numTilesWideMinusOne; // r7
  bool v8; // xer_ca
  unsigned int numTilesHighMinusOne; // r26
  unsigned int v10; // r9
  int v11; // r10
  int v12; // r5
  unsigned int v13; // r9
  int v14; // r10
  unsigned int v15; // r9
  int v16; // r10
  unsigned int v17; // r9
  int v18; // r10
  unsigned int v19; // r10
  unsigned int v20; // r8
  unsigned int v21; // r10
  unsigned int v22; // r6
  bool v23; // r10
  bool v24; // r10
  bool v25; // r11
  bool v26; // r11
  bool v27; // r11

  fullImageROILeftX = codec->codecParms.fullImageROILeftX;
  if ( fullImageROILeftX <= codec->codecParms.extraPixelsLeft )
    fullImageROILeftX = codec->codecParms.extraPixelsLeft;
  codec->codecParms.fullImageROILeftX = fullImageROILeftX;
  fullImageWidth = codec->imageInfo.fullImageWidth;
  fullImageROIRightX = codec->codecParms.fullImageROIRightX;
  if ( fullImageROIRightX >= fullImageWidth - codec->codecParms.extraPixelsLeft - 1 )
    fullImageROIRightX = fullImageWidth - codec->codecParms.extraPixelsLeft - 1;
  codec->codecParms.fullImageROIRightX = fullImageROIRightX;
  fullImageROITopY = codec->codecParms.fullImageROITopY;
  if ( fullImageROITopY <= codec->codecParms.extraPixelsTop )
    fullImageROITopY = codec->codecParms.extraPixelsTop;
  codec->codecParms.fullImageROITopY = fullImageROITopY;
  extraPixelsBottom = codec->codecParms.extraPixelsBottom;
  fullImageROIBottomY = codec->codecParms.fullImageROIBottomY;
  if ( fullImageROIBottomY >= codec->imageInfo.fullImageHeight - extraPixelsBottom - 1 )
    fullImageROIBottomY = codec->imageInfo.fullImageHeight - extraPixelsBottom - 1;
  numTilesWideMinusOne = codec->codecParms.numTilesWideMinusOne;
  v8 = codec->codecParms.overlap == OL_NONE;
  numTilesHighMinusOne = codec->codecParms.numTilesHighMinusOne;
  codec->codecParms.fullImageROILeftTile = 0;
  v10 = 0;
  codec->codecParms.fullImageROITopTile = 0;
  codec->codecParms.fullImageROIBottomY = fullImageROIBottomY;
  v11 = 0;
  v12 = v8 ? 0 : 0x10;
  codec->codecParms.fullImageROIRightTile = numTilesWideMinusOne;
  codec->codecParms.fullImageROIBottomTile = numTilesHighMinusOne;
  while ( fullImageROILeftX - (v8 ? 0 : 0x10) <= 16 * codec->codecParms.tileMacroblockOffsetX[v11] )
  {
    ++v10;
    ++v11;
    if ( v10 > codec->codecParms.numTilesWideMinusOne )
      goto LABEL_14;
  }
  codec->codecParms.fullImageROILeftTile = v10;
LABEL_14:
  v13 = 0;
  v14 = 0;
  while ( fullImageROIRightX + v12 >= 16 * codec->codecParms.tileMacroblockOffsetX[v14] )
  {
    ++v13;
    ++v14;
    if ( v13 > codec->codecParms.numTilesWideMinusOne )
      goto LABEL_19;
  }
  codec->codecParms.fullImageROIRightTile = v13 - 1;
LABEL_19:
  v15 = 0;
  v16 = 0;
  while ( fullImageROITopY - v12 <= 16 * codec->codecParms.tileMacroblockOffsetY[v16] )
  {
    ++v15;
    ++v16;
    if ( v15 > codec->codecParms.numTilesHighMinusOne )
      goto LABEL_24;
  }
  codec->codecParms.fullImageROITopTile = v15;
LABEL_24:
  v17 = 0;
  v18 = 0;
  while ( fullImageROIBottomY + v12 >= 16 * codec->codecParms.tileMacroblockOffsetY[v18] )
  {
    ++v17;
    ++v18;
    if ( v17 > codec->codecParms.numTilesHighMinusOne )
      goto LABEL_29;
  }
  codec->codecParms.fullImageROIBottomTile = v17 - 1;
LABEL_29:
  v19 = codec->codecParms.fullImageROIRightX;
  v20 = codec->codecParms.fullImageROILeftX;
  codec->codecParms.thumbnailScale = 1;
  v21 = v19 - v20 + 1;
  if ( codec->codecParms.thumbnailWidth < v21 )
  {
    do
    {
      v22 = 2 * codec->codecParms.thumbnailScale;
      codec->codecParms.thumbnailScale = v22;
    }
    while ( v22 * codec->codecParms.thumbnailWidth < v21 );
  }
  v23 = codec->codecParms.subBands < SB_NO_LOWPASS
     && (codec->codecParms.streamLayout != SL_FREQUENCY || codec->codecParms.thumbnailScale < 0x10);
  codec->codecParms.decodeLP = v23;
  v24 = codec->codecParms.subBands < SB_NO_HIGHPASS
     && (codec->codecParms.streamLayout != SL_FREQUENCY || codec->codecParms.thumbnailScale < 4);
  codec->codecParms.decodeHP = v24;
  v25 = codec->codecParms.subBands < SB_NO_FLEXBITS
     && (codec->codecParms.streamLayout != SL_FREQUENCY || !codec->codecParms.skipFlexbits);
  codec->codecParms.decodeFlexbits = v25;
  if ( fullImageROILeftX + fullImageROITopY != 0
    || (fullImageROIRightX + 15) >> 4 < codec->imageInfo.fullImageWidth
    || (v26 = true, (fullImageROIBottomY + 15) >> 4 < codec->imageInfo.fullImageHeight) )
  {
    v26 = false;
  }
  codec->codecParms.decodeFullFrame = v26;
  if ( fullImageROILeftX != 0 || (v27 = true, (fullImageROIRightX + 15) >> 4 < codec->imageInfo.fullImageWidth) )
    v27 = false;
  codec->codecParms.decodeFullWidth = v27;
}


// ========================================================================
// ?HDPDecInit@@YA?AW4hdpError_t@@PAUhdpImageInfo_t@@PAUhdpCodecParms_t@@PAPAUhdpCodec_t@@@Z
// EA  : 0x828EFD90
// RVA : 0x008EFD90
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdec.cpp
// ========================================================================

hdpError_t __fastcall HDPDecInit(hdpImageInfo_t *imageInfo, hdpCodecParms_t *codecParms, hdpCodec_t **codecOut)
{
  hdpBitIO_t *v6; // r5
  __int64 v7; // r6
  hdpError_t result; // r3
  unsigned int v9; // r26
  int v10; // r30
  char *v11; // r3
  hdpCodec_t *v12; // r31
  hdpCodec_t *v13; // r29
  hdpImageInfo_t *p_imageInfo; // r24
  hdpOrientation_t *p_orientation; // r11
  unsigned __int8 *v16; // r10
  int i; // ctr
  hdpCodecParms_t *p_codecParms; // r25
  unsigned int numChannels; // r4
  unsigned int *p_widthInMacroblocks; // r7
  unsigned int v21; // r11
  unsigned int v22; // r10
  __int16 **macroBlockRowBuffer1; // r9
  int v24; // r8
  unsigned int v25; // r10
  int v26; // r8
  char *v27; // r11
  int j; // ctr
  __int64 v29; // r10
  __int64 v30; // r6
  int v31; // r4
  char *v32; // r3
  hdpCodec_t *v33; // r31
  unsigned __int8 *v34; // r10
  hdpOrientation_t *v35; // r11
  int k; // ctr
  __int64 v37; // r6
  unsigned int widthInMacroblocks; // r10
  unsigned int v39; // r11
  hdpOrientation_t *v40; // r11
  hdpOrientation_t *v41; // r10
  int m; // ctr
  char v43; // [sp+48h] [-88h] BYREF
  hdpBitIO_t v44[3]; // [sp+50h] [-80h] BYREF

  *codecOut = nullptr;
  StreamReadAttach(pIO: v44, stream: codecParms->baseStream);
  result = ReadImageHeader(imageInfo, codecParms, pIO: v6);
  if ( result == HDP_ERROR_NONE )
  {
    result = ReadImagePlaneHeader(codecParms, pIO: v44, a3: v7);
    if ( result == HDP_ERROR_NONE )
    {
      v9 = (imageInfo->fullImageWidth + 15) >> 4;
      v10 = 32 * cblkChromas[codecParms->colorFormat];
      v11 = TempAlloc(codecParms, size: 2 * ((codecParms->numChannels - 1) * v10 + 512) * v9 + 1859, align: 0x80u);
      v12 = (hdpCodec_t *)v11;
      if ( v11 == nullptr )
        return HDP_ERROR_OUT_OF_MEMORY;
      v13 = (hdpCodec_t *)v11;
      memset(Dst: v11, Val: 0, Size: 0x69Cu);
      p_imageInfo = &v12->imageInfo;
      p_orientation = &imageInfo[-1].orientation;
      v16 = &v12->MBInfo.pad[58];
      for ( i = 10; i != 0; --i )
      {
        ++p_orientation;
        v16 += 4;
        *(hdpOrientation_t *)v16 = *p_orientation;
      }
      p_codecParms = &v12->codecParms;
      memcpy(Dst: &v12->codecParms, Src: codecParms, Size: sizeof(v12->codecParms));
      numChannels = v12->codecParms.numChannels;
      p_widthInMacroblocks = &v12->widthInMacroblocks;
      v21 = 0;
      v12->widthInMacroblocks = (imageInfo->fullImageWidth + 15) >> 4;
      v22 = ((unsigned int)&v12[1].MBInfo.compactDCLP[3][15] + 1) & 0xFFFFFF80;
      v12->heightInMacroblocks = (imageInfo->fullImageHeight + 15) >> 4;
      if ( numChannels != 0 )
      {
        macroBlockRowBuffer1 = v12->macroBlockRowBuffer1;
        do
        {
          *(macroBlockRowBuffer1 - 16) = (__int16 *)v22;
          v24 = v10;
          if ( v21 == 0 )
            v24 = 512;
          v25 = *p_widthInMacroblocks * v24 + v22;
          v26 = v10;
          *macroBlockRowBuffer1 = (__int16 *)v25;
          if ( v21 == 0 )
            v26 = 512;
          ++v21;
          ++macroBlockRowBuffer1;
          v22 = *p_widthInMacroblocks * v26 + v25;
        }
        while ( v21 < v12->codecParms.numChannels );
      }
      v12->bitIOHeader = (hdpBitIO_t *)v22;
      v27 = &v43;
      for ( j = 5; j != 0; --j )
      {
        v27 += 8;
        v29 = *(_QWORD *)v27;
        HIDWORD(v29) = *(_DWORD *)v27 + 8;
        *(_QWORD *)HIDWORD(v29) = v29;
      }
      result = AllocateAdditionalBitIOs(codec: v12);
      if ( result == HDP_ERROR_NONE )
      {
        result = ReadIndexTable(codec: v12, a2: v31, a3: v30);
        if ( result == HDP_ERROR_NONE )
        {
          result = InitImagePlaneDec(codec: v12);
          if ( result == HDP_ERROR_NONE )
          {
            InitContextBitIOs(codec: v12);
            DeriveDecoderParms(codec: v12);
            if ( !codecParms->hasAlphaChannel )
              goto LABEL_26;
            v32 = TempAlloc(codecParms, size: (v9 << 10) + 1819, align: 0x10u);
            v33 = (hdpCodec_t *)v32;
            if ( v32 == nullptr )
              return HDP_ERROR_OUT_OF_MEMORY;
            memset(Dst: v32, Val: 0, Size: (v9 << 10) + 1819);
            v34 = &v33->MBInfo.pad[58];
            v35 = &imageInfo[-1].orientation;
            for ( k = 10; k != 0; --k )
            {
              ++v35;
              v34 += 4;
              *(hdpOrientation_t *)v34 = *v35;
            }
            memcpy(Dst: &v33->codecParms, Src: codecParms, Size: sizeof(v33->codecParms));
            v33->widthInMacroblocks = (imageInfo->fullImageWidth + 15) >> 4;
            v33->heightInMacroblocks = (imageInfo->fullImageHeight + 15) >> 4;
            result = ReadImagePlaneHeader(codecParms: &v33->codecParms, pIO: v13->bitIOHeader, a3: v37);
            if ( result == HDP_ERROR_NONE )
            {
              widthInMacroblocks = v33->widthInMacroblocks;
              v33->nextCodec = nullptr;
              v39 = ((unsigned int)&v33[1].MBInfo.compactDCLP[3][15] + 1) & 0xFFFFFF80;
              v33->isSecondaryCodec = true;
              v33->macroBlockRowBuffer0[0] = (__int16 *)v39;
              v33->macroBlockRowBuffer1[0] = (__int16 *)((widthInMacroblocks << 9) + v39);
              v13->nextCodec = v33;
              result = InitImagePlaneDec(codec: v33);
              if ( result == HDP_ERROR_NONE )
              {
                v33->tileIndex = v13->tileIndex;
                v33->tileStreams = v13->tileStreams;
                v33->bitIOHeader = v13->bitIOHeader;
                v33->tileBitIOs = v13->tileBitIOs;
                v33->numTileBitIOs = v13->numTileBitIOs;
                v33->numSubBands = v13->numSubBands;
                InitContextBitIOs(codec: v33);
LABEL_26:
                v40 = &p_imageInfo[-1].orientation;
                v41 = &imageInfo[-1].orientation;
                for ( m = 10; m != 0; --m )
                  *++v41 = *++v40;
                memcpy(Dst: codecParms, Src: p_codecParms, Size: sizeof(hdpCodecParms_t));
                *codecOut = v13;
                return HDPDecDecodeMBRow(firstCodec: v13);
              }
            }
          }
        }
      }
    }
  }
  return result;
}

