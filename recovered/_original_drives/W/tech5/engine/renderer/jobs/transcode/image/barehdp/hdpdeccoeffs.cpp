
// ========================================================================
// DecodeQuantizerIndex
// EA  : 0x828F00D8
// RVA : 0x008F00D8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdeccoeffs.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall DecodeQuantizerIndex(hdpBitIO_t *pIO, unsigned __int8 cBits, __int64 a3)
{
  unsigned __int64 bitCnt; // r11 OVERLAPPED
  bool (__fastcall **v6)(idAIEvent *__hidden, const struct idEntity *, int); // r9
  int v7; // r9 OVERLAPPED
  int v8; // r7
  __int64 v10; // r6
  unsigned __int64 v11; // r10
  __int128 v12; // r8
  unsigned __int64 bitBuff; // [sp+50h] [-30h] BYREF
  unsigned __int64 v14[5]; // [sp+58h] [-28h] BYREF

  bitCnt = pIO->bitCnt;
  bitBuff = pIO->bitBuff;
  HIDWORD(bitCnt) = bitBuff;
  v14[0] = bitCnt;
  if ( (_DWORD)bitCnt == 0 )
  {
    HIDWORD(a3) = v14;
    FillBitBuffer(pIO, &bitBuff, bitCnt: a3);
    bitCnt = v14[0];
  }
  v6 = &off_82230000;
  LODWORD(bitCnt) = bitCnt - 1;
  v8 = *(unsigned __int64 *)((char *)&bitCnt + 4) >> bitCnt;
  v7 = 1;
  pIO->bitBuff = *(unsigned __int64 *)((char *)&bitCnt + 4);
  pIO->bitCnt = bitCnt;
  if ( (v8 & 1) == 0 )
    return 0;
  bitBuff = bitCnt;
  v14[0] = *(unsigned __int64 *)((char *)&bitCnt + 4);
  if ( cBits > (unsigned int)bitCnt )
  {
    HIDWORD(v10) = &bitBuff;
    LODWORD(v10) = v8 & 1;
    FillBitBuffer(pIO, bitBuff: v14, bitCnt: v10);
  }
  LODWORD(v11) = HIDWORD(bitBuff);
  HIDWORD(v11) = 4 * cBits;
  LODWORD(v12) = bitBuff - cBits;
  *(_QWORD *)((char *)&v12 + 4) = v11 >> ((unsigned __int8)bitBuff - cBits);
  DWORD1(v12) = *(const int *)((char *)maskTable + HIDWORD(v11));
  HIDWORD(v12) = v11 >> ((unsigned __int8)bitBuff - cBits);
  pIO->bitBuff = v11;
  pIO->bitCnt = v12;
  return (unsigned __int8)((BYTE3(v12) & BYTE7(v12)) + 1);
}


// ========================================================================
// DecodeHPCBP
// EA  : 0x828F01B0
// RVA : 0x008F01B0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdeccoeffs.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall DecodeHPCBP(hdpCodec_t *codec, hdpContext_t *context)
{
  hdpColorFormat_t colorFormat; // r15
  signed int numChannels; // r10
  hdpBitIO_t *bitIOHP; // r26
  bool v6; // cr57
  unsigned __int64 v7; // r8 OVERLAPPED
  __int64 v8; // r6 OVERLAPPED
  unsigned __int64 bitCnt; // r11
  int discriminant; // r14
  int v11; // r18
  int v12; // r16
  int v13; // r17
  const int *deltaTable; // r9
  int v15; // r23
  int v16; // r31
  int v17; // r21
  int i; // r25
  const __int16 *decTable; // r30
  unsigned __int64 v20; // r10
  __int16 v21; // r3
  int v22; // r31
  const int *v23; // r9
  int v24; // r31
  int v25; // r28
  unsigned int v26; // r30
  int v27; // r31
  int v28; // r29
  int j; // r30
  const __int16 *v30; // r31
  __int16 v31; // r3
  int v32; // r31
  int v33; // r10
  int *residualCBP; // [sp+50h] [-C0h]
  int v36; // [sp+54h] [-BCh]
  hdpAdaptiveHuffman_t *v37; // [sp+58h] [-B8h]
  unsigned __int64 v38; // [sp+60h] [-B0h] BYREF
  unsigned __int64 v39[21]; // [sp+68h] [-A8h] BYREF

  colorFormat = codec->codecParms.colorFormat;
  if ( colorFormat == CF_N_CHANNEL || (numChannels = 1, colorFormat == CF_CMYK) )
    numChannels = codec->codecParms.numChannels;
  bitIOHP = context->bitIOHP;
  v6 = numChannels > 0;
  v37 = &context->adaptHuffCBP[1];
  *(unsigned __int64 *)((char *)&v7 + 4) = bitIOHP->bitBuff;
  bitCnt = bitIOHP->bitCnt;
  v39[0] = bitIOHP->bitBuff;
  v38 = bitCnt;
  if ( v6 )
  {
    discriminant = context->adaptHuffCBP[1].discriminant;
    v36 = HIDWORD(bitCnt);
    residualCBP = codec->MBInfo.residualCBP;
    do
    {
      v11 = 0;
      v12 = 0;
      v13 = 0;
      if ( (unsigned int)bitCnt < 5 )
      {
        HIDWORD(v8) = &v38;
        FillBitBuffer(pIO: bitIOHP, bitBuff: v39, bitCnt: v8);
        *(unsigned __int64 *)((char *)&v7 + 4) = v39[0];
        LODWORD(bitCnt) = v38;
      }
      deltaTable = v37->deltaTable;
      LODWORD(v7) = v37->decTable[(*(unsigned __int64 *)((char *)&v7 + 4) >> ((unsigned __int8)bitCnt - 5)) & 0x1F];
      v15 = (int)v7 >> 3;
      LODWORD(v8) = v7 & 7;
      LODWORD(bitCnt) = bitCnt - v8;
      HIDWORD(bitCnt) = ((int)v7 >> 3) - 1;
      v38 = bitCnt;
      discriminant += deltaTable[(int)v7 >> 3];
      if ( HIDWORD(bitCnt) <= 3 )
      {
        switch ( (int)v7 >> 3 )
        {
          case 2:
            if ( (unsigned int)bitCnt < 2 )
            {
              HIDWORD(v8) = &v38;
              FillBitBuffer(pIO: bitIOHP, bitBuff: v39, bitCnt: v8);
              *(unsigned __int64 *)((char *)&v7 + 4) = v39[0];
              LODWORD(bitCnt) = v38;
            }
            LODWORD(bitCnt) = bitCnt - 2;
            HIDWORD(bitCnt) = 3;
            v38 = bitCnt;
            v16 = (*(unsigned __int64 *)((char *)&v7 + 4) >> bitCnt) & 3;
            if ( v16 != 0 )
            {
              if ( v16 == 1 )
              {
                v15 = 5;
              }
              else
              {
                if ( (_DWORD)bitCnt == 0 )
                {
                  HIDWORD(v8) = &v38;
                  FillBitBuffer(pIO: bitIOHP, bitBuff: v39, bitCnt: v8);
                  *(unsigned __int64 *)((char *)&v7 + 4) = v39[0];
                  LODWORD(bitCnt) = v38;
                }
                LODWORD(bitCnt) = bitCnt - 1;
                HIDWORD(bitCnt) = 1;
                v7 = *(unsigned __int64 *)((char *)&v7 + 4) >> bitCnt;
                v38 = bitCnt;
                LODWORD(v8) = v7;
                v15 = gTab[2 * v16 - 4 + (v7 & 1)];
              }
            }
            else
            {
              v15 = 3;
            }
            break;
          case 3:
            if ( (unsigned int)bitCnt < 2 )
            {
              HIDWORD(v8) = &v38;
              FillBitBuffer(pIO: bitIOHP, bitBuff: v39, bitCnt: v8);
              *(unsigned __int64 *)((char *)&v7 + 4) = v39[0];
              LODWORD(bitCnt) = v38;
            }
            LODWORD(bitCnt) = bitCnt - 2;
            HIDWORD(bitCnt) = 3;
            v38 = bitCnt;
            LODWORD(v7) = *(unsigned __int64 *)((char *)&v7 + 4) >> bitCnt;
            LODWORD(v8) = v7 & 3;
            v15 = (1 << (v7 & 3)) ^ 0xF;
            break;
          case 1:
            if ( (unsigned int)bitCnt < 2 )
            {
              HIDWORD(v8) = &v38;
              FillBitBuffer(pIO: bitIOHP, bitBuff: v39, bitCnt: v8);
              *(unsigned __int64 *)((char *)&v7 + 4) = v39[0];
              LODWORD(bitCnt) = v38;
            }
            LODWORD(bitCnt) = bitCnt - 2;
            HIDWORD(bitCnt) = 3;
            v38 = bitCnt;
            LODWORD(v7) = *(unsigned __int64 *)((char *)&v7 + 4) >> bitCnt;
            LODWORD(v8) = v7 & 3;
            v15 = 1 << (v7 & 3);
            break;
          default:
            v15 = 15;
            break;
        }
      }
      v17 = 1;
      for ( i = 0; i < 16; i += 4 )
      {
        if ( (v17 & v15) != 0 )
        {
          decTable = context->adaptHuffCBP[0].decTable;
          if ( (unsigned int)bitCnt < 5 )
          {
            HIDWORD(v8) = &v38;
            FillBitBuffer(pIO: bitIOHP, bitBuff: v39, bitCnt: v8);
            *(unsigned __int64 *)((char *)&v7 + 4) = v39[0];
            LODWORD(bitCnt) = v38;
          }
          LODWORD(v20) = bitCnt - 5;
          HIDWORD(v20) = 31;
          v7 = *(unsigned __int64 *)((char *)&v7 + 4) >> ((unsigned __int8)bitCnt - 5);
          LODWORD(v8) = v7;
          v21 = decTable[v7 & 0x1F];
          v22 = v21;
          if ( v21 < 0 )
          {
            LODWORD(v7) = v20;
            v38 = v20;
            if ( (unsigned int)v20 < 0x10 )
            {
              HIDWORD(v8) = &v38;
              FillBitBuffer(pIO: bitIOHP, bitBuff: v39, bitCnt: v8);
              LODWORD(v8) = HIDWORD(v39[0]);
              v7 = v38;
            }
            bitCnt = (unsigned __int16)(*(unsigned __int64 *)((char *)&v7 + 4) >> ((unsigned __int8)v7 - 16));
            do
            {
              LODWORD(bitCnt) = 2 * bitCnt;
              ++HIDWORD(bitCnt);
              v22 = decTable[(((int)bitCnt >> 16) & 1) + 0x8000 + v22];
            }
            while ( v22 < 0 );
            LODWORD(bitCnt) = v7 - HIDWORD(bitCnt);
          }
          else
          {
            LODWORD(bitCnt) = bitCnt - (v21 & 7);
            v22 = v21 >> 3;
          }
          v23 = context->adaptHuffCBP[0].deltaTable;
          HIDWORD(bitCnt) = context->adaptHuffCBP[0].discriminant;
          v38 = bitCnt;
          v25 = 0;
          LODWORD(v8) = v23[v22] + HIDWORD(bitCnt);
          v24 = v22 + 1;
          context->adaptHuffCBP[0].discriminant = v8;
          if ( v24 >= 6 )
          {
            if ( (_DWORD)bitCnt == 0 )
            {
              HIDWORD(v8) = &v38;
              FillBitBuffer(pIO: bitIOHP, bitBuff: v39, bitCnt: v8);
              *(unsigned __int64 *)((char *)&v7 + 4) = v39[0];
              LODWORD(bitCnt) = v38;
            }
            LODWORD(bitCnt) = bitCnt - 1;
            HIDWORD(bitCnt) = 1;
            v38 = bitCnt;
            LODWORD(v8) = (*(unsigned __int64 *)((char *)&v7 + 4) >> bitCnt) & 1;
            if ( (_DWORD)v8 != 0 )
            {
              v25 = 16;
            }
            else
            {
              if ( (_DWORD)bitCnt == 0 )
              {
                HIDWORD(v8) = &v38;
                FillBitBuffer(pIO: bitIOHP, bitBuff: v39, bitCnt: v8);
                *(unsigned __int64 *)((char *)&v7 + 4) = v39[0];
                LODWORD(bitCnt) = v38;
              }
              LODWORD(bitCnt) = bitCnt - 1;
              HIDWORD(bitCnt) = 1;
              v38 = bitCnt;
              LODWORD(v8) = (*(unsigned __int64 *)((char *)&v7 + 4) >> bitCnt) & 1;
              v25 = (_DWORD)v8 == 0 ? 48 : 32;
            }
            if ( v24 == 9 )
            {
              if ( (_DWORD)bitCnt == 0 )
              {
                HIDWORD(v8) = &v38;
                FillBitBuffer(pIO: bitIOHP, bitBuff: v39, bitCnt: v8);
                *(unsigned __int64 *)((char *)&v7 + 4) = v39[0];
                LODWORD(bitCnt) = v38;
              }
              LODWORD(bitCnt) = bitCnt - 1;
              HIDWORD(bitCnt) = 1;
              v38 = bitCnt;
              LODWORD(v8) = (*(unsigned __int64 *)((char *)&v7 + 4) >> bitCnt) & 1;
              if ( (_DWORD)v8 == 0 )
              {
                if ( (_DWORD)bitCnt == 0 )
                {
                  HIDWORD(v8) = &v38;
                  FillBitBuffer(pIO: bitIOHP, bitBuff: v39, bitCnt: v8);
                  *(unsigned __int64 *)((char *)&v7 + 4) = v39[0];
                  LODWORD(bitCnt) = v38;
                }
                LODWORD(bitCnt) = bitCnt - 1;
                HIDWORD(bitCnt) = 1;
                v38 = bitCnt;
                LODWORD(v8) = (*(unsigned __int64 *)((char *)&v7 + 4) >> bitCnt) & 1;
                v24 = ((_cntlzw(v8) & 0x20) != 0) + 10;
              }
            }
            v24 -= 6;
          }
          v26 = gFLC0[v24];
          v27 = gOff0[v24];
          if ( v26 != 0 )
          {
            if ( v26 > (unsigned int)bitCnt )
            {
              HIDWORD(v8) = &v38;
              FillBitBuffer(pIO: bitIOHP, bitBuff: v39, bitCnt: v8);
              *(unsigned __int64 *)((char *)&v7 + 4) = v39[0];
              LODWORD(bitCnt) = v38;
            }
            LODWORD(bitCnt) = bitCnt - v26;
            HIDWORD(bitCnt) = 4 * v26;
            v38 = bitCnt;
            v27 += (*(unsigned __int64 *)((char *)&v7 + 4) >> bitCnt) & maskTable[v26];
          }
          v28 = gOut0[v27] + v25;
          LODWORD(v8) = (v28 & 0xF) << i;
          v11 |= v8;
          if ( colorFormat == CF_YUV_444 )
          {
            for ( j = 0; j < 2; ++j )
            {
              if ( ((v28 >> (j + 4)) & 1) != 0 )
              {
                v30 = context->adaptHuffCBP[2].decTable;
                if ( (unsigned int)bitCnt < 5 )
                {
                  HIDWORD(v8) = &v38;
                  FillBitBuffer(pIO: bitIOHP, bitBuff: v39, bitCnt: v8);
                  *(unsigned __int64 *)((char *)&v7 + 4) = v39[0];
                  LODWORD(bitCnt) = v38;
                }
                v7 = *(unsigned __int64 *)((char *)&v7 + 4) >> ((unsigned __int8)bitCnt - 5);
                LODWORD(v8) = v7;
                v31 = v30[v7 & 0x1F];
                LODWORD(bitCnt) = bitCnt - (v31 & 7);
                HIDWORD(bitCnt) = v31 >> 3;
                v38 = bitCnt;
                if ( HIDWORD(bitCnt) <= 3 )
                {
                  if ( HIDWORD(bitCnt) != 0 )
                  {
                    if ( HIDWORD(bitCnt) == 1 )
                    {
                      if ( (unsigned int)bitCnt < 2 )
                      {
                        HIDWORD(v8) = &v38;
                        FillBitBuffer(pIO: bitIOHP, bitBuff: v39, bitCnt: v8);
                        *(unsigned __int64 *)((char *)&v7 + 4) = v39[0];
                        LODWORD(bitCnt) = v38;
                      }
                      LODWORD(bitCnt) = bitCnt - 2;
                      HIDWORD(bitCnt) = 3;
                      v38 = bitCnt;
                      v32 = (*(unsigned __int64 *)((char *)&v7 + 4) >> bitCnt) & 3;
                      if ( v32 != 0 )
                      {
                        if ( v32 == 1 )
                        {
                          HIDWORD(bitCnt) = 5;
                        }
                        else
                        {
                          if ( (_DWORD)bitCnt == 0 )
                          {
                            HIDWORD(v8) = &v38;
                            FillBitBuffer(pIO: bitIOHP, bitBuff: v39, bitCnt: v8);
                            *(unsigned __int64 *)((char *)&v7 + 4) = v39[0];
                            LODWORD(bitCnt) = v38;
                          }
                          LODWORD(bitCnt) = bitCnt - 1;
                          HIDWORD(bitCnt) = 1;
                          v7 = *(unsigned __int64 *)((char *)&v7 + 4) >> bitCnt;
                          v38 = bitCnt;
                          LODWORD(v8) = v7;
                          HIDWORD(bitCnt) = gTab[2 * v32 - 4 + (v7 & 1)];
                        }
                      }
                      else
                      {
                        HIDWORD(bitCnt) = 3;
                      }
                    }
                    else if ( HIDWORD(bitCnt) == 2 )
                    {
                      if ( (unsigned int)bitCnt < 2 )
                      {
                        HIDWORD(v8) = &v38;
                        FillBitBuffer(pIO: bitIOHP, bitBuff: v39, bitCnt: v8);
                        *(unsigned __int64 *)((char *)&v7 + 4) = v39[0];
                        LODWORD(bitCnt) = v38;
                      }
                      LODWORD(bitCnt) = bitCnt - 2;
                      HIDWORD(bitCnt) = 3;
                      v38 = bitCnt;
                      LODWORD(v7) = *(unsigned __int64 *)((char *)&v7 + 4) >> bitCnt;
                      LODWORD(v8) = v7 & 3;
                      HIDWORD(bitCnt) = (1 << (v7 & 3)) ^ 0xF;
                    }
                    else
                    {
                      HIDWORD(bitCnt) = 15;
                    }
                  }
                  else
                  {
                    if ( (unsigned int)bitCnt < 2 )
                    {
                      HIDWORD(v8) = &v38;
                      FillBitBuffer(pIO: bitIOHP, bitBuff: v39, bitCnt: v8);
                      *(unsigned __int64 *)((char *)&v7 + 4) = v39[0];
                      LODWORD(bitCnt) = v38;
                    }
                    LODWORD(bitCnt) = bitCnt - 2;
                    HIDWORD(bitCnt) = 3;
                    v38 = bitCnt;
                    LODWORD(v7) = *(unsigned __int64 *)((char *)&v7 + 4) >> bitCnt;
                    LODWORD(v8) = v7 & 3;
                    HIDWORD(bitCnt) = 1 << (v7 & 3);
                  }
                }
                v33 = HIDWORD(bitCnt) << i;
                if ( j != 0 )
                  v13 |= v33;
                else
                  v12 |= v33;
              }
            }
          }
        }
        v17 = __ROL4__(v17, 1);
      }
      *residualCBP = v11;
      if ( colorFormat == CF_YUV_444 || colorFormat == CF_YUV_422 || colorFormat == CF_YUV_420 )
      {
        codec->MBInfo.residualCBP[1] = v12;
        codec->MBInfo.residualCBP[2] = v13;
      }
      ++residualCBP;
    }
    while ( v36-- != 1 );
    HIDWORD(bitCnt) = v37;
    v37->discriminant = discriminant;
  }
  bitIOHP->bitCnt = bitCnt;
  bitIOHP->bitBuff = *(unsigned __int64 *)((char *)&v7 + 4);
}


// ========================================================================
// DecodeLPCBP
// EA  : 0x828F08F8
// RVA : 0x008F08F8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdeccoeffs.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall DecodeLPCBP(hdpCodec_t *codec, hdpContext_t *context, __int64 a3)
{
  hdpColorFormat_t colorFormat; // r10
  signed int numChannels; // r28
  unsigned int v6; // r29
  hdpBitIO_t *bitIOLP; // r23
  unsigned int v8; // r30
  bool v9; // cr58
  unsigned __int64 bitBuff; // r8 OVERLAPPED
  unsigned __int64 bitCnt; // r11 OVERLAPPED
  signed int v12; // r31
  int v13; // r9
  int zeroCount; // r25
  int maxCount; // r27
  int v17; // r26
  unsigned int v18; // r31
  unsigned int v19; // r29
  __int64 v20; // r6
  int v21; // r9
  __int64 v22; // r6
  int v23; // r31
  int v24; // r10
  unsigned __int64 v25; // [sp+50h] [-60h] BYREF
  unsigned __int64 v26[11]; // [sp+58h] [-58h] BYREF

  colorFormat = codec->codecParms.colorFormat;
  numChannels = codec->codecParms.numChannels;
  if ( colorFormat == CF_YUV_420 || (v6 = codec->codecParms.numChannels, colorFormat == CF_YUV_422) )
    v6 = 2;
  bitIOLP = context->bitIOLP;
  v8 = 0;
  v9 = colorFormat == CF_YUV_444;
  bitBuff = bitIOLP->bitBuff;
  bitCnt = bitIOLP->bitCnt;
  v26[0] = bitIOLP->bitBuff;
  v25 = bitCnt;
  if ( v9 || HIDWORD(bitCnt) == 2 || HIDWORD(bitCnt) == 1 )
  {
    zeroCount = context->adaptCBPModelLP.zeroCount;
    maxCount = context->adaptCBPModelLP.maxCount;
    v17 = 4 * v6 - 5;
    if ( zeroCount <= 0 || maxCount < 0 )
    {
      v8 = 0;
      if ( (_DWORD)bitCnt == 0 )
      {
        HIDWORD(a3) = &v25;
        FillBitBuffer(pIO: bitIOLP, bitBuff: v26, bitCnt: a3);
        bitBuff = v26[0];
        LODWORD(bitCnt) = v25;
      }
      LODWORD(bitCnt) = bitCnt - 1;
      *(unsigned __int64 *)((char *)&bitCnt + 4) = bitBuff >> bitCnt;
      v25 = bitCnt;
      HIDWORD(bitBuff) = bitBuff >> bitCnt;
      if ( (bitBuff & 0x100000000LL) != 0 )
      {
        v18 = v6 - 1;
        v8 = 1;
        v19 = v6 - 1;
        if ( v19 > (unsigned int)bitCnt )
        {
          HIDWORD(v20) = &v25;
          LODWORD(v20) = BYTE3(bitBuff) & 1;
          FillBitBuffer(pIO: bitIOLP, bitBuff: v26, bitCnt: v20);
          bitBuff = v26[0];
          LODWORD(bitCnt) = v25;
        }
        LODWORD(bitCnt) = bitCnt - v19;
        HIDWORD(bitCnt) = 4 * v18;
        *(unsigned __int64 *)((char *)&bitBuff - 4) = bitBuff >> bitCnt;
        v25 = bitCnt;
        HIDWORD(bitBuff) = maskTable[v18];
        LODWORD(v22) = v21;
        v23 = v21 & HIDWORD(bitBuff);
        if ( (v21 & HIDWORD(bitBuff)) != 0 )
        {
          if ( (_DWORD)bitCnt == 0 )
          {
            HIDWORD(v22) = &v25;
            FillBitBuffer(pIO: bitIOLP, bitBuff: v26, bitCnt: v22);
            bitBuff = v26[0];
            LODWORD(bitCnt) = v25;
          }
          LODWORD(bitCnt) = bitCnt - 1;
          v8 = 2 * v23 + ((bitBuff >> bitCnt) & 1);
        }
      }
      if ( maxCount < zeroCount )
        v8 = v17 - v8;
    }
    else
    {
      if ( v6 > (unsigned int)bitCnt )
      {
        HIDWORD(a3) = &v25;
        FillBitBuffer(pIO: bitIOLP, bitBuff: v26, bitCnt: a3);
        bitBuff = v26[0];
        LODWORD(bitCnt) = v25;
      }
      LODWORD(bitCnt) = bitCnt - v6;
      v8 = (bitBuff >> bitCnt) & maskTable[v6];
    }
    v24 = maxCount - ((_cntlzw(v17 - v8) >> 3) & 4) + 1;
    if ( v24 >= -8 )
    {
      if ( v24 > 7 )
        v24 = 7;
    }
    else
    {
      v24 = -8;
    }
    context->adaptCBPModelLP.maxCount = v24;
    HIDWORD(bitBuff) = (_cntlzw(v8) >> 3) & 4;
    HIDWORD(bitCnt) = zeroCount - HIDWORD(bitBuff) + 1;
    if ( SHIDWORD(bitCnt) >= -8 )
    {
      if ( SHIDWORD(bitCnt) > 7 )
        HIDWORD(bitCnt) = 7;
    }
    else
    {
      HIDWORD(bitCnt) = -8;
    }
    context->adaptCBPModelLP.zeroCount = HIDWORD(bitCnt);
    goto LABEL_37;
  }
  v12 = 0;
  if ( numChannels <= 0 )
  {
LABEL_37:
    bitIOLP->bitBuff = bitBuff;
    bitIOLP->bitCnt = bitCnt;
    return v8;
  }
  do
  {
    if ( (_DWORD)bitCnt == 0 )
    {
      HIDWORD(a3) = &v25;
      FillBitBuffer(pIO: bitIOLP, bitBuff: v26, bitCnt: a3);
      bitBuff = v26[0];
      LODWORD(bitCnt) = v25;
    }
    LODWORD(bitCnt) = bitCnt - 1;
    HIDWORD(bitCnt) = 1;
    *(unsigned __int64 *)((char *)&bitBuff - 4) = bitBuff >> bitCnt;
    v25 = bitCnt;
    HIDWORD(bitBuff) = v13;
    LODWORD(a3) = v13 & 1;
    v8 |= (_DWORD)a3 << v12++;
  }
  while ( v12 < numChannels );
  bitIOLP->bitBuff = bitBuff;
  bitIOLP->bitCnt = bitCnt;
  return v8;
}


// ========================================================================
// DecodeBlockFlexBits
// EA  : 0x828F0B90
// RVA : 0x008F0B90
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdeccoeffs.cpp
// ========================================================================

void __fastcall DecodeBlockFlexBits(hdpBitIO_t *pIO, const int iFlexBits, __int16 iTrimFlexBits, __int16 *pCoeffs)
{
  unsigned __int64 v4; // r7
  unsigned __int64 bitCnt; // r10
  int v6; // r24
  char v9; // r26
  int v10; // r29
  unsigned int v12; // r28
  const int *v13; // r31
  __int64 v14; // r6
  int v15; // r30
  int v16; // r5
  int v17; // r8
  int v18; // r4
  int v19; // r3
  unsigned __int64 v20; // [sp+50h] [-70h] BYREF
  unsigned __int64 bitBuff; // [sp+58h] [-68h] BYREF

  bitCnt = pIO->bitCnt;
  v6 = iFlexBits + 1;
  v9 = iTrimFlexBits;
  bitBuff = pIO->bitBuff;
  LODWORD(v4) = bitBuff;
  v20 = bitCnt;
  v10 = HIDWORD(bitBuff);
  v12 = iFlexBits + 1;
  v13 = &coeffOrderHP[1];
  do
  {
    LODWORD(v14) = iTrimFlexBits;
    v15 = *(__int16 *)(2 * *v13 + v10) >> iTrimFlexBits;
    if ( v12 > (unsigned int)bitCnt )
    {
      HIDWORD(v14) = &v20;
      FillBitBuffer(pIO, &bitBuff, bitCnt: v14);
      LODWORD(v4) = bitBuff;
      LODWORD(bitCnt) = v20;
    }
    HIDWORD(v4) = *v13;
    v16 = (v4 >> ((unsigned __int8)bitCnt - (unsigned __int8)v12)) & maskTable[v6];
    HIDWORD(bitCnt) = (int)(abs32(v15) - 1) >> 31;
    v17 = iFlexBits - ((-(v16 >> 1) >> 31) & HIDWORD(bitCnt));
    v18 = 2 * *v13;
    v19 = (((v16 >> 1) ^ (-(v16 & 1) & HIDWORD(bitCnt) | (v15 >> 31)))
         - (-(v16 & 1) & HIDWORD(bitCnt) | (v15 >> 31))
         + v15) << v9;
    HIDWORD(bitCnt) = (__int16)v19;
    ++v13;
    *(_WORD *)(v18 + v10) = v19;
    LODWORD(bitCnt) = bitCnt - v17;
    v20 = bitCnt;
  }
  while ( (int)v13 < (int)idxCC );
  pIO->bitBuff = v4;
  pIO->bitCnt = bitCnt;
}


// ========================================================================
// DecodeBlockModelBits
// EA  : 0x828F0CB0
// RVA : 0x008F0CB0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdeccoeffs.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall DecodeBlockModelBits(hdpBitIO_t *pIO, const int iModelBits, __int16 *pCoeffs)
{
  unsigned __int64 bitBuff; // r7 OVERLAPPED
  int v4; // r26
  unsigned __int64 bitCnt; // r10
  unsigned int v9; // r28
  int v10; // r30
  int v11; // r31
  unsigned __int64 *v12; // r5
  int v13; // r8
  int v14; // r4
  int v15; // r4
  int v16; // r11
  unsigned __int64 v17; // [sp+50h] [-60h] BYREF
  unsigned __int64 v18; // [sp+58h] [-58h] BYREF

  bitBuff = pIO->bitBuff;
  v4 = iModelBits + 1;
  bitCnt = pIO->bitCnt;
  v9 = iModelBits + 1;
  v18 = pIO->bitBuff;
  v10 = 15;
  v17 = bitCnt;
  do
  {
    v11 = pCoeffs[1];
    if ( v9 > (unsigned int)bitCnt )
    {
      v12 = &v17;
      FillBitBuffer(pIO, bitBuff: &v18, bitCnt: *(unsigned __int64 *)((char *)&bitBuff + 4));
      bitBuff = v18;
      LODWORD(bitCnt) = v17;
    }
    v13 = (bitBuff >> ((unsigned __int8)bitCnt - (unsigned __int8)v9)) & maskTable[v4];
    HIDWORD(bitCnt) = (int)(abs32(v11) - 1) >> 31;
    v14 = -(v13 & 1);
    v13 >>= 1;
    v15 = v14 & HIDWORD(bitCnt) | (v11 >> 31);
    HIDWORD(bitCnt) = iModelBits - ((-v13 >> 31) & HIDWORD(bitCnt));
    v16 = (v13 ^ v15) - v15;
    HIDWORD(bitBuff) = v16 + v11;
    LODWORD(bitCnt) = bitCnt - HIDWORD(bitCnt);
    --v10;
    v17 = bitCnt;
    *++pCoeffs = v16 + v11;
  }
  while ( v10 != 0 );
  pIO->bitBuff = bitBuff;
  pIO->bitCnt = bitCnt;
}


// ========================================================================
// DecodeMacroblockDC
// EA  : 0x828F0DA0
// RVA : 0x008F0DA0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdeccoeffs.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
hdpError_t __fastcall DecodeMacroblockDC(hdpCodec_t *codec, hdpContext_t *context, __int64 mbY)
{
  signed int numChannels; // r4
  hdpColorFormat_t colorFormat; // r14
  hdpBitIO_t *bitIODC; // r31
  int v8; // r10
  unsigned int v9; // r11
  unsigned int v10; // ctr
  hdpPostProcessInfo_t **v11; // r20
  int *v12; // r23
  int *fixedLengthCodeBits; // r22
  signed int v14; // r21
  __int128 v15; // r11 OVERLAPPED
  int v16; // r25
  int v17; // r30
  const __int16 *v18; // r29
  __int16 v19; // r3
  int v20; // r30
  int v21; // r7
  int v22; // r29
  int v23; // r11
  unsigned __int64 v24; // r10
  unsigned __int64 v25; // r11 OVERLAPPED
  unsigned int v26; // r30
  unsigned __int64 v27; // r9
  unsigned __int64 v28; // r11 OVERLAPPED
  int v29; // r9
  int v30; // r9 OVERLAPPED
  unsigned int v31; // r30
  unsigned __int64 v32; // r11 OVERLAPPED
  int v33; // r9
  int v34; // r9 OVERLAPPED
  __int128 v35; // r11
  int v36; // r28
  int v37; // r27
  unsigned __int64 v38; // r11 OVERLAPPED
  int v39; // r9
  unsigned __int64 v40; // r10
  unsigned __int64 v41; // r11 OVERLAPPED
  bool v42; // cr57
  int v43; // r9
  unsigned __int64 v44; // r10
  unsigned __int64 v45; // r11 OVERLAPPED
  bool v46; // cr57
  int v47; // r9
  unsigned __int64 v48; // r11 OVERLAPPED
  int v49; // r9
  unsigned __int64 bitBuff; // r9 OVERLAPPED
  int v51; // r25
  int v52; // r22
  unsigned __int64 bitCnt; // r11 OVERLAPPED
  const __int16 *decTable; // r30
  __int64 v55; // r6
  int v56; // r20
  __int64 v57; // r6
  int v58; // r30
  int v59; // r21
  int v60; // r24
  const __int16 *v61; // r29
  __int16 v62; // r3
  int v63; // r30
  int v64; // r7
  int v65; // r29
  int v66; // r11
  unsigned __int64 v67; // r10
  unsigned __int64 v68; // r11 OVERLAPPED
  unsigned int v69; // r30
  unsigned __int64 v70; // r9
  unsigned __int64 v71; // r11 OVERLAPPED
  int v72; // r9
  int v73; // r9 OVERLAPPED
  unsigned int v74; // r30
  unsigned __int64 v75; // r11 OVERLAPPED
  int v76; // r9
  int v77; // r9 OVERLAPPED
  __int128 v78; // r11
  int v79; // r28
  int v80; // r27
  unsigned __int64 v81; // r11 OVERLAPPED
  int v82; // r9
  unsigned __int64 v83; // r10
  unsigned __int64 v84; // r11 OVERLAPPED
  bool v85; // cr57
  int v86; // r9
  unsigned __int64 v87; // r10
  unsigned __int64 v88; // r11 OVERLAPPED
  bool v89; // cr57
  int v90; // r9
  unsigned __int64 v91; // r11 OVERLAPPED
  int v92; // r9
  __int128 v93; // r11 OVERLAPPED
  const __int16 *v94; // r29
  __int16 v95; // r3
  int v96; // r30
  int v97; // r7
  int v98; // r29
  int v99; // r11
  unsigned __int64 v100; // r10
  unsigned __int64 v101; // r11 OVERLAPPED
  unsigned int v102; // r30
  unsigned __int64 v103; // r9
  unsigned __int64 v104; // r11 OVERLAPPED
  int v105; // r9
  int v106; // r9 OVERLAPPED
  unsigned int v107; // r30
  unsigned __int64 v108; // r11 OVERLAPPED
  int v109; // r9
  int v110; // r9 OVERLAPPED
  __int128 v111; // r11
  int v112; // r28
  int v113; // r27
  unsigned __int64 v114; // r11 OVERLAPPED
  int v115; // r9
  unsigned __int64 v116; // r10
  unsigned __int64 v117; // r11 OVERLAPPED
  bool v118; // cr57
  int v119; // r9
  unsigned __int64 v120; // r10
  unsigned __int64 v121; // r11 OVERLAPPED
  bool v122; // cr57
  int v123; // r9
  unsigned __int64 v124; // r11 OVERLAPPED
  int v125; // r9
  __int128 v126; // r11 OVERLAPPED
  const __int16 *v127; // r29
  __int16 v128; // r3
  int v129; // r30
  int v130; // r7
  int v131; // r29
  int v132; // r11
  unsigned __int64 v133; // r10
  unsigned __int64 v134; // r11 OVERLAPPED
  unsigned int v135; // r30
  unsigned __int64 v136; // r9
  unsigned __int64 v137; // r11 OVERLAPPED
  int v138; // r9
  int v139; // r9 OVERLAPPED
  unsigned int v140; // r30
  unsigned __int64 v141; // r11 OVERLAPPED
  int v142; // r9
  int v143; // r9 OVERLAPPED
  __int128 v144; // r11
  int v145; // r28
  int v146; // r27
  unsigned __int64 v147; // r11 OVERLAPPED
  int v148; // r9
  unsigned __int64 v149; // r10
  unsigned __int64 v150; // r11 OVERLAPPED
  bool v151; // cr57
  int v152; // r9
  unsigned int v153; // r11
  unsigned __int64 v154; // r10
  unsigned __int64 v155; // r11 OVERLAPPED
  bool v156; // cr57
  int v157; // r9
  unsigned __int64 v158; // r11 OVERLAPPED
  int v159; // r9
  unsigned __int64 v161; // [sp+50h] [-170h] BYREF
  unsigned __int64 v162; // [sp+58h] [-168h] BYREF
  unsigned __int64 v163; // [sp+60h] [-160h] BYREF
  unsigned __int64 v164; // [sp+68h] [-158h] BYREF
  unsigned __int64 v165; // [sp+70h] [-150h] BYREF
  unsigned __int64 v166; // [sp+78h] [-148h] BYREF
  unsigned __int64 v167; // [sp+80h] [-140h] BYREF
  unsigned __int64 v168; // [sp+88h] [-138h] BYREF
  unsigned __int64 v169; // [sp+90h] [-130h] BYREF
  unsigned __int64 v170; // [sp+98h] [-128h] BYREF
  unsigned __int64 v171; // [sp+A0h] [-120h] BYREF
  unsigned __int64 v172; // [sp+A8h] [-118h] BYREF
  unsigned __int64 v173; // [sp+B0h] [-110h] BYREF
  unsigned __int64 v174; // [sp+B8h] [-108h] BYREF
  unsigned __int64 v175; // [sp+C0h] [-100h] BYREF
  unsigned __int64 v176; // [sp+C8h] [-F8h] BYREF
  signed int v177; // [sp+D0h] [-F0h]
  int v178; // [sp+E0h] [-E0h] BYREF
  _DWORD v179[55]; // [sp+E4h] [-DCh] BYREF

  colorFormat = codec->codecParms.colorFormat;
  bitIODC = context->bitIODC;
  numChannels = codec->codecParms.numChannels;
  v8 = 0;
  v9 = (32 * numChannels + 127) & 0xFFFFFF80;
  v178 = 0;
  memset(v179, 0, 60);
  v177 = numChannels;
  if ( v9 != 0 )
  {
    v10 = ((v9 - 1) >> 7) + 1;
    do
    {
      __asm { dcbz128   r10, r15 }
      v8 += 128;
      --v10;
    }
    while ( v10 != 0 );
  }
  if ( colorFormat == CF_YUV_444 || colorFormat == CF_YUV_422 || colorFormat == CF_YUV_420 )
  {
    bitCnt = bitIODC->bitCnt;
    bitBuff = bitIODC->bitBuff;
    HIDWORD(bitBuff) = _cntlzw(HIDWORD(bitCnt));
    v51 = context->adaptCNModelDC.fixedLengthCodeBits[0];
    v52 = context->adaptCNModelDC.fixedLengthCodeBits[1];
    HIDWORD(bitCnt) = (bitBuff & 0x2000000000LL) != 0;
    decTable = context->adaptHuffDC[0].decTable;
    v161 = bitCnt;
    v162 = bitBuff;
    LODWORD(v55) = 4 * (HIDWORD(bitCnt) + 71);
    v56 = *(int *)((char *)&context->bitIODC + v55);
    if ( (unsigned int)bitCnt < 5 )
    {
      HIDWORD(v55) = &v161;
      FillBitBuffer(pIO: bitIODC, bitBuff: &v162, bitCnt: v55);
      LODWORD(bitBuff) = v162;
      LODWORD(bitCnt) = v161;
    }
    HIDWORD(bitCnt) = &off_82230000;
    bitIODC->bitCnt = bitCnt;
    HIDWORD(bitBuff) = bitCnt - 5;
    bitIODC->bitBuff = bitBuff;
    HIDWORD(bitBuff) = (unsigned __int16)decTable[(bitBuff >> SBYTE3(bitBuff)) & 0x1F];
    HIDWORD(bitCnt) = SWORD1(bitBuff) >> 3;
    LODWORD(v57) = SBYTE3(bitBuff) & 7;
    LODWORD(bitCnt) = bitCnt - v57;
    v58 = (SWORD1(bitBuff) >> 5) & 1;
    bitIODC->bitCnt = bitCnt;
    v59 = BYTE3(bitCnt) & 1;
    v60 = (SWORD1(bitBuff) >> 4) & 1;
    if ( v58 != 0 )
    {
      v61 = context->adaptHuffDC[1].decTable;
      HIDWORD(bitCnt) = bitCnt;
      v162 = bitBuff;
      v161 = bitCnt;
      if ( (unsigned int)bitCnt < 5 )
      {
        HIDWORD(v57) = &v161;
        FillBitBuffer(pIO: bitIODC, bitBuff: &v162, bitCnt: v57);
        *(unsigned __int64 *)((char *)&bitCnt + 4) = v161;
      }
      LODWORD(bitCnt) = HIDWORD(bitCnt) - 5;
      HIDWORD(bitBuff) = 31;
      bitIODC->bitBuff = bitBuff;
      bitIODC->bitCnt = *(unsigned __int64 *)((char *)&bitCnt + 4);
      LODWORD(v57) = bitBuff >> (BYTE3(bitCnt) - 5);
      v62 = v61[v57 & 0x1F];
      v63 = v62;
      if ( v62 < 0 )
      {
        bitIODC->bitCnt = bitCnt;
        HIDWORD(bitBuff) = HIDWORD(bitCnt) - 5;
        v172 = bitBuff;
        v170 = bitCnt;
        if ( (unsigned int)bitCnt < 0x10 )
        {
          HIDWORD(v57) = &v170;
          FillBitBuffer(pIO: bitIODC, bitBuff: &v172, bitCnt: v57);
          bitBuff = __PAIR64__(v170, v172);
        }
        v64 = 0xFFFF;
        bitIODC->bitBuff = bitBuff;
        bitIODC->bitCnt = *(unsigned __int64 *)((char *)&bitBuff + 4);
        bitCnt = (unsigned __int16)(bitBuff >> (BYTE3(bitBuff) - 16));
        do
        {
          LODWORD(bitCnt) = 2 * bitCnt;
          ++HIDWORD(bitCnt);
          LODWORD(bitBuff) = ((int)bitCnt >> 16) & 1;
          LODWORD(v57) = bitBuff + v63 + 0x8000;
          v63 = v61[(_DWORD)v57];
        }
        while ( v63 < 0 );
        HIDWORD(bitCnt) = HIDWORD(bitBuff) - HIDWORD(bitCnt);
      }
      else
      {
        HIDWORD(bitCnt) -= v62 & 7;
        v63 = v62 >> 3;
      }
      bitIODC->bitCnt = *(unsigned __int64 *)((char *)&bitCnt + 4);
      v65 = v63;
      context->adaptHuffDC[1].discriminant += context->adaptHuffDC[1].deltaTable[v63];
      if ( v63 >= 2 )
      {
        if ( v63 >= 6 )
        {
          v71 = bitIODC->bitCnt;
          v175 = bitIODC->bitBuff;
          HIDWORD(v71) = v175;
          v171 = v71;
          if ( (unsigned int)v71 < 4 )
          {
            HIDWORD(v57) = &v171;
            FillBitBuffer(pIO: bitIODC, bitBuff: &v175, bitCnt: v57);
            v71 = v171;
          }
          LODWORD(v71) = v71 - 4;
          v72 = 15;
          bitIODC->bitBuff = *(unsigned __int64 *)((char *)&v71 + 4);
          bitIODC->bitCnt = v71;
          v73 = (*(unsigned __int64 *)((char *)&v71 + 4) >> v71) & 0xF;
          v74 = v73 + 4;
          if ( v73 == 15 )
          {
            v169 = v71;
            v165 = *(unsigned __int64 *)((char *)&v71 + 4);
            if ( (unsigned int)v71 < 2 )
            {
              HIDWORD(v57) = &v169;
              FillBitBuffer(pIO: bitIODC, bitBuff: &v165, bitCnt: v57);
            }
            *(unsigned __int64 *)((char *)&v75 + 4) = HIDWORD(v169) | 0x300000000LL;
            LODWORD(v75) = v169 - 2;
            bitIODC->bitBuff = *(unsigned __int64 *)((char *)&v75 + 4);
            bitIODC->bitCnt = v75;
            v77 = (*(unsigned __int64 *)((char *)&v75 + 4) >> v75) & v76;
            v74 = v77 + 19;
            if ( v77 == 3 )
            {
              v167 = v75;
              v173 = *(unsigned __int64 *)((char *)&v75 + 4);
              if ( (unsigned int)v75 < 3 )
              {
                HIDWORD(v57) = &v167;
                FillBitBuffer(pIO: bitIODC, bitBuff: &v173, bitCnt: v57);
              }
              *(_QWORD *)((char *)&v78 + 4) = HIDWORD(v167) | 0x700000000LL;
              LODWORD(v78) = v167 - 3;
              bitIODC->bitBuff = *(_QWORD *)((char *)&v78 + 4);
              bitIODC->bitCnt = v78;
              v74 = ((*(_QWORD *)((char *)&v78 + 4) >> v78) & DWORD1(v78)) + 22;
            }
          }
          v79 = 0;
          v80 = (1 << v74) + 2;
          if ( v74 > 0x10 )
          {
            v81 = bitIODC->bitCnt;
            v176 = bitIODC->bitBuff;
            HIDWORD(v81) = v176;
            v174 = v81;
            if ( (unsigned int)v81 < 0x10 )
            {
              HIDWORD(v57) = &v174;
              FillBitBuffer(pIO: bitIODC, bitBuff: &v176, bitCnt: v57);
              v81 = v174;
            }
            LODWORD(v81) = v81 - 16;
            v82 = 0xFFFF;
            v74 -= 16;
            bitIODC->bitBuff = *(unsigned __int64 *)((char *)&v81 + 4);
            bitIODC->bitCnt = v81;
            LODWORD(v57) = (unsigned __int16)(*(unsigned __int64 *)((char *)&v81 + 4) >> v81);
            v79 = (_DWORD)v57 << v74;
          }
          v83 = bitIODC->bitCnt;
          v85 = v74 > HIDWORD(bitIODC->bitBuff);
          v164 = bitIODC->bitBuff;
          v84 = v164;
          v163 = *(unsigned __int64 *)((char *)&v84 + 4);
          if ( v85 )
          {
            HIDWORD(v57) = &v163;
            FillBitBuffer(pIO: bitIODC, bitBuff: &v164, bitCnt: v57);
            v84 = __PAIR64__(v163, v164);
          }
          HIDWORD(v84) -= v74;
          bitIODC->bitBuff = v84;
          v86 = 4 * v74;
          bitIODC->bitCnt = *(unsigned __int64 *)((char *)&v84 + 4);
          LODWORD(v57) = v84 >> SBYTE3(v84);
          v66 = (v57 & maskTable[v74] | v79) + v80;
        }
        else
        {
          v67 = bitIODC->bitCnt;
          v69 = *(_DWORD *)(v65 * 4 + HIDWORD(v67));
          v168 = bitIODC->bitBuff;
          v68 = v168;
          v166 = *(unsigned __int64 *)((char *)&v68 + 4);
          if ( v69 > HIDWORD(v168) )
          {
            HIDWORD(v57) = &v166;
            FillBitBuffer(pIO: bitIODC, bitBuff: &v168, bitCnt: v57);
            v68 = __PAIR64__(v166, v168);
          }
          LODWORD(v70) = HIDWORD(v68) - v69;
          bitIODC->bitBuff = v68;
          HIDWORD(v70) = 4 * v69;
          HIDWORD(v68) = gSignificantAbsLevelRemap[v65];
          bitIODC->bitCnt = v70;
          LODWORD(v57) = maskTable[v69];
          v66 = ((v68 >> v70) & v57) + HIDWORD(v68);
        }
      }
      else
      {
        v66 = v63 + 2;
      }
      v58 = v66 - 1;
      ++v178;
    }
    if ( v51 > 0 )
    {
      v87 = bitIODC->bitCnt;
      v89 = (unsigned int)v51 > HIDWORD(bitIODC->bitBuff);
      v162 = bitIODC->bitBuff;
      v88 = v162;
      v161 = *(unsigned __int64 *)((char *)&v88 + 4);
      if ( v89 )
      {
        HIDWORD(v57) = &v161;
        FillBitBuffer(pIO: bitIODC, bitBuff: &v162, bitCnt: v57);
        v88 = __PAIR64__(v161, v162);
      }
      HIDWORD(v88) -= v51;
      bitIODC->bitBuff = v88;
      v90 = 4 * v51;
      bitIODC->bitCnt = *(unsigned __int64 *)((char *)&v88 + 4);
      LODWORD(v57) = v88 >> SBYTE3(v88);
      v58 = v57 & maskTable[v51] | (v58 << v51);
    }
    if ( v58 != 0 )
    {
      v91 = bitIODC->bitCnt;
      v162 = bitIODC->bitBuff;
      HIDWORD(v91) = v162;
      v161 = v91;
      if ( (_DWORD)v91 == 0 )
      {
        HIDWORD(v57) = &v161;
        FillBitBuffer(pIO: bitIODC, bitBuff: &v162, bitCnt: v57);
        v91 = v161;
      }
      LODWORD(v91) = v91 - 1;
      v92 = 1;
      bitIODC->bitBuff = *(unsigned __int64 *)((char *)&v91 + 4);
      bitIODC->bitCnt = v91;
      LODWORD(v57) = (*(unsigned __int64 *)((char *)&v91 + 4) >> v91) & 1;
      if ( (_DWORD)v57 != 0 )
        v58 = -v58;
    }
    codec->MBInfo.compactDCLP[0][0] = v58;
    if ( v60 != 0 )
    {
      *(_QWORD *)((char *)&v93 + 4) = bitIODC->bitCnt;
      v94 = context->adaptHuffDC[2].decTable;
      v162 = bitIODC->bitBuff;
      DWORD1(v93) = v162;
      v161 = *(_QWORD *)((char *)&v93 + 4);
      if ( DWORD2(v93) < 5 )
      {
        HIDWORD(v57) = &v161;
        FillBitBuffer(pIO: bitIODC, bitBuff: &v162, bitCnt: v57);
        *(_QWORD *)((char *)&v93 + 4) = v161;
      }
      LODWORD(v93) = DWORD2(v93) - 5;
      HIDWORD(v93) = 31;
      bitIODC->bitBuff = *(_QWORD *)&v93;
      bitIODC->bitCnt = *(_QWORD *)((char *)&v93 + 4);
      LODWORD(v57) = *(_QWORD *)&v93 >> (BYTE11(v93) - 5);
      v95 = v94[v57 & 0x1F];
      v96 = v95;
      if ( v95 < 0 )
      {
        bitIODC->bitCnt = v93;
        HIDWORD(v93) = DWORD2(v93) - 5;
        v172 = *(_QWORD *)&v93;
        v170 = v93;
        if ( (unsigned int)v93 < 0x10 )
        {
          HIDWORD(v57) = &v170;
          FillBitBuffer(pIO: bitIODC, bitBuff: &v172, bitCnt: v57);
          *(_QWORD *)&v93 = __PAIR64__(v170, v172);
        }
        v97 = 0xFFFF;
        bitIODC->bitBuff = *(_QWORD *)&v93;
        bitIODC->bitCnt = *(_QWORD *)((char *)&v93 + 12);
        *((_QWORD *)&v93 + 1) = (unsigned __int16)(*(_QWORD *)&v93 >> (BYTE3(v93) - 16));
        do
        {
          LODWORD(v93) = 2 * v93;
          ++DWORD2(v93);
          DWORD1(v93) = ((int)v93 >> 16) & 1;
          LODWORD(v57) = DWORD1(v93) + v96 + 0x8000;
          v96 = v94[(_DWORD)v57];
        }
        while ( v96 < 0 );
        DWORD2(v93) = HIDWORD(v93) - DWORD2(v93);
      }
      else
      {
        DWORD2(v93) -= v95 & 7;
        v96 = v95 >> 3;
      }
      bitIODC->bitCnt = *(_QWORD *)((char *)&v93 + 4);
      v98 = v96;
      context->adaptHuffDC[2].discriminant += context->adaptHuffDC[2].deltaTable[v96];
      if ( v96 >= 2 )
      {
        if ( v96 >= 6 )
        {
          v104 = bitIODC->bitCnt;
          v175 = bitIODC->bitBuff;
          HIDWORD(v104) = v175;
          v171 = v104;
          if ( (unsigned int)v104 < 4 )
          {
            HIDWORD(v57) = &v171;
            FillBitBuffer(pIO: bitIODC, bitBuff: &v175, bitCnt: v57);
            v104 = v171;
          }
          LODWORD(v104) = v104 - 4;
          v105 = 15;
          bitIODC->bitBuff = *(unsigned __int64 *)((char *)&v104 + 4);
          bitIODC->bitCnt = v104;
          v106 = (*(unsigned __int64 *)((char *)&v104 + 4) >> v104) & 0xF;
          v107 = v106 + 4;
          if ( v106 == 15 )
          {
            v169 = v104;
            v165 = *(unsigned __int64 *)((char *)&v104 + 4);
            if ( (unsigned int)v104 < 2 )
            {
              HIDWORD(v57) = &v169;
              FillBitBuffer(pIO: bitIODC, bitBuff: &v165, bitCnt: v57);
            }
            *(unsigned __int64 *)((char *)&v108 + 4) = HIDWORD(v169) | 0x300000000LL;
            LODWORD(v108) = v169 - 2;
            bitIODC->bitBuff = *(unsigned __int64 *)((char *)&v108 + 4);
            bitIODC->bitCnt = v108;
            v110 = (*(unsigned __int64 *)((char *)&v108 + 4) >> v108) & v109;
            v107 = v110 + 19;
            if ( v110 == 3 )
            {
              v167 = v108;
              v173 = *(unsigned __int64 *)((char *)&v108 + 4);
              if ( (unsigned int)v108 < 3 )
              {
                HIDWORD(v57) = &v167;
                FillBitBuffer(pIO: bitIODC, bitBuff: &v173, bitCnt: v57);
              }
              *(_QWORD *)((char *)&v111 + 4) = HIDWORD(v167) | 0x700000000LL;
              LODWORD(v111) = v167 - 3;
              bitIODC->bitBuff = *(_QWORD *)((char *)&v111 + 4);
              bitIODC->bitCnt = v111;
              v107 = ((*(_QWORD *)((char *)&v111 + 4) >> v111) & DWORD1(v111)) + 22;
            }
          }
          v112 = 0;
          v113 = (1 << v107) + 2;
          if ( v107 > 0x10 )
          {
            v114 = bitIODC->bitCnt;
            v176 = bitIODC->bitBuff;
            HIDWORD(v114) = v176;
            v174 = v114;
            if ( (unsigned int)v114 < 0x10 )
            {
              HIDWORD(v57) = &v174;
              FillBitBuffer(pIO: bitIODC, bitBuff: &v176, bitCnt: v57);
              v114 = v174;
            }
            LODWORD(v114) = v114 - 16;
            v115 = 0xFFFF;
            v107 -= 16;
            bitIODC->bitBuff = *(unsigned __int64 *)((char *)&v114 + 4);
            bitIODC->bitCnt = v114;
            LODWORD(v57) = (unsigned __int16)(*(unsigned __int64 *)((char *)&v114 + 4) >> v114);
            v112 = (_DWORD)v57 << v107;
          }
          v116 = bitIODC->bitCnt;
          v118 = v107 > HIDWORD(bitIODC->bitBuff);
          v164 = bitIODC->bitBuff;
          v117 = v164;
          v163 = *(unsigned __int64 *)((char *)&v117 + 4);
          if ( v118 )
          {
            HIDWORD(v57) = &v163;
            FillBitBuffer(pIO: bitIODC, bitBuff: &v164, bitCnt: v57);
            v117 = __PAIR64__(v163, v164);
          }
          HIDWORD(v117) -= v107;
          bitIODC->bitBuff = v117;
          v119 = 4 * v107;
          bitIODC->bitCnt = *(unsigned __int64 *)((char *)&v117 + 4);
          LODWORD(v57) = v117 >> SBYTE3(v117);
          v99 = (maskTable[v107] & v57 | v112) + v113;
        }
        else
        {
          v100 = bitIODC->bitCnt;
          v102 = *(_DWORD *)(v98 * 4 + HIDWORD(v100));
          v168 = bitIODC->bitBuff;
          v101 = v168;
          v166 = *(unsigned __int64 *)((char *)&v101 + 4);
          if ( v102 > HIDWORD(v168) )
          {
            HIDWORD(v57) = &v166;
            FillBitBuffer(pIO: bitIODC, bitBuff: &v168, bitCnt: v57);
            v101 = __PAIR64__(v166, v168);
          }
          LODWORD(v103) = HIDWORD(v101) - v102;
          bitIODC->bitBuff = v101;
          HIDWORD(v103) = 4 * v102;
          HIDWORD(v101) = gSignificantAbsLevelRemap[v98];
          bitIODC->bitCnt = v103;
          LODWORD(v57) = maskTable[v102];
          v99 = ((v101 >> v103) & v57) + HIDWORD(v101);
        }
      }
      else
      {
        v99 = v96 + 2;
      }
      v60 = v99 - 1;
      ++v179[0];
    }
    if ( v52 > 0 )
    {
      v120 = bitIODC->bitCnt;
      v122 = (unsigned int)v52 > HIDWORD(bitIODC->bitBuff);
      v162 = bitIODC->bitBuff;
      v121 = v162;
      v161 = *(unsigned __int64 *)((char *)&v121 + 4);
      if ( v122 )
      {
        HIDWORD(v57) = &v161;
        FillBitBuffer(pIO: bitIODC, bitBuff: &v162, bitCnt: v57);
        v121 = __PAIR64__(v161, v162);
      }
      HIDWORD(v121) -= v52;
      bitIODC->bitBuff = v121;
      v123 = 4 * v52;
      bitIODC->bitCnt = *(unsigned __int64 *)((char *)&v121 + 4);
      LODWORD(v57) = v121 >> SBYTE3(v121);
      v60 = v57 & maskTable[v52] | (v60 << v52);
    }
    if ( v60 != 0 )
    {
      v124 = bitIODC->bitCnt;
      v162 = bitIODC->bitBuff;
      HIDWORD(v124) = v162;
      v161 = v124;
      if ( (_DWORD)v124 == 0 )
      {
        HIDWORD(v57) = &v161;
        FillBitBuffer(pIO: bitIODC, bitBuff: &v162, bitCnt: v57);
        v124 = v161;
      }
      LODWORD(v124) = v124 - 1;
      v125 = 1;
      bitIODC->bitBuff = *(unsigned __int64 *)((char *)&v124 + 4);
      bitIODC->bitCnt = v124;
      LODWORD(v57) = (*(unsigned __int64 *)((char *)&v124 + 4) >> v124) & 1;
      if ( (_DWORD)v57 != 0 )
        v60 = -v60;
    }
    codec->MBInfo.compactDCLP[1][0] = v60;
    if ( v59 != 0 )
    {
      *(_QWORD *)((char *)&v126 + 4) = bitIODC->bitCnt;
      v127 = context->adaptHuffDC[2].decTable;
      v162 = bitIODC->bitBuff;
      DWORD1(v126) = v162;
      v161 = *(_QWORD *)((char *)&v126 + 4);
      if ( DWORD2(v126) < 5 )
      {
        HIDWORD(v57) = &v161;
        FillBitBuffer(pIO: bitIODC, bitBuff: &v162, bitCnt: v57);
        *(_QWORD *)((char *)&v126 + 4) = v161;
      }
      LODWORD(v126) = DWORD2(v126) - 5;
      HIDWORD(v126) = 31;
      bitIODC->bitBuff = *(_QWORD *)&v126;
      bitIODC->bitCnt = *(_QWORD *)((char *)&v126 + 4);
      LODWORD(v57) = *(_QWORD *)&v126 >> (BYTE11(v126) - 5);
      v128 = v127[v57 & 0x1F];
      v129 = v128;
      if ( v128 < 0 )
      {
        bitIODC->bitCnt = v126;
        HIDWORD(v126) = DWORD2(v126) - 5;
        v172 = *(_QWORD *)&v126;
        v170 = v126;
        if ( (unsigned int)v126 < 0x10 )
        {
          HIDWORD(v57) = &v170;
          FillBitBuffer(pIO: bitIODC, bitBuff: &v172, bitCnt: v57);
          *(_QWORD *)&v126 = __PAIR64__(v170, v172);
        }
        v130 = 0xFFFF;
        bitIODC->bitBuff = *(_QWORD *)&v126;
        bitIODC->bitCnt = *(_QWORD *)((char *)&v126 + 12);
        *((_QWORD *)&v126 + 1) = (unsigned __int16)(*(_QWORD *)&v126 >> (BYTE3(v126) - 16));
        do
        {
          LODWORD(v126) = 2 * v126;
          ++DWORD2(v126);
          DWORD1(v126) = ((int)v126 >> 16) & 1;
          LODWORD(v57) = DWORD1(v126) + v129 + 0x8000;
          v129 = v127[(_DWORD)v57];
        }
        while ( v129 < 0 );
        DWORD2(v126) = HIDWORD(v126) - DWORD2(v126);
      }
      else
      {
        DWORD2(v126) -= v128 & 7;
        v129 = v128 >> 3;
      }
      bitIODC->bitCnt = *(_QWORD *)((char *)&v126 + 4);
      v131 = v129;
      context->adaptHuffDC[2].discriminant += context->adaptHuffDC[2].deltaTable[v129];
      if ( v129 >= 2 )
      {
        if ( v129 >= 6 )
        {
          v137 = bitIODC->bitCnt;
          v175 = bitIODC->bitBuff;
          HIDWORD(v137) = v175;
          v171 = v137;
          if ( (unsigned int)v137 < 4 )
          {
            HIDWORD(v57) = &v171;
            FillBitBuffer(pIO: bitIODC, bitBuff: &v175, bitCnt: v57);
            v137 = v171;
          }
          LODWORD(v137) = v137 - 4;
          v138 = 15;
          bitIODC->bitBuff = *(unsigned __int64 *)((char *)&v137 + 4);
          bitIODC->bitCnt = v137;
          v139 = (*(unsigned __int64 *)((char *)&v137 + 4) >> v137) & 0xF;
          v140 = v139 + 4;
          if ( v139 == 15 )
          {
            v169 = v137;
            v165 = *(unsigned __int64 *)((char *)&v137 + 4);
            if ( (unsigned int)v137 < 2 )
            {
              HIDWORD(v57) = &v169;
              FillBitBuffer(pIO: bitIODC, bitBuff: &v165, bitCnt: v57);
            }
            *(unsigned __int64 *)((char *)&v141 + 4) = HIDWORD(v169) | 0x300000000LL;
            LODWORD(v141) = v169 - 2;
            bitIODC->bitBuff = *(unsigned __int64 *)((char *)&v141 + 4);
            bitIODC->bitCnt = v141;
            v143 = (*(unsigned __int64 *)((char *)&v141 + 4) >> v141) & v142;
            v140 = v143 + 19;
            if ( v143 == 3 )
            {
              v167 = v141;
              v173 = *(unsigned __int64 *)((char *)&v141 + 4);
              if ( (unsigned int)v141 < 3 )
              {
                HIDWORD(v57) = &v167;
                FillBitBuffer(pIO: bitIODC, bitBuff: &v173, bitCnt: v57);
              }
              *(_QWORD *)((char *)&v144 + 4) = HIDWORD(v167) | 0x700000000LL;
              LODWORD(v144) = v167 - 3;
              bitIODC->bitBuff = *(_QWORD *)((char *)&v144 + 4);
              bitIODC->bitCnt = v144;
              v140 = ((*(_QWORD *)((char *)&v144 + 4) >> v144) & DWORD1(v144)) + 22;
            }
          }
          v145 = 0;
          v146 = (1 << v140) + 2;
          if ( v140 > 0x10 )
          {
            v147 = bitIODC->bitCnt;
            v176 = bitIODC->bitBuff;
            HIDWORD(v147) = v176;
            v174 = v147;
            if ( (unsigned int)v147 < 0x10 )
            {
              HIDWORD(v57) = &v174;
              FillBitBuffer(pIO: bitIODC, bitBuff: &v176, bitCnt: v57);
              v147 = v174;
            }
            LODWORD(v147) = v147 - 16;
            v148 = 0xFFFF;
            v140 -= 16;
            bitIODC->bitBuff = *(unsigned __int64 *)((char *)&v147 + 4);
            bitIODC->bitCnt = v147;
            LODWORD(v57) = (unsigned __int16)(*(unsigned __int64 *)((char *)&v147 + 4) >> v147);
            v145 = (_DWORD)v57 << v140;
          }
          v149 = bitIODC->bitCnt;
          v151 = v140 > HIDWORD(bitIODC->bitBuff);
          v164 = bitIODC->bitBuff;
          v150 = v164;
          v163 = *(unsigned __int64 *)((char *)&v150 + 4);
          if ( v151 )
          {
            HIDWORD(v57) = &v163;
            FillBitBuffer(pIO: bitIODC, bitBuff: &v164, bitCnt: v57);
            v150 = __PAIR64__(v163, v164);
          }
          HIDWORD(v150) -= v140;
          bitIODC->bitBuff = v150;
          v152 = 4 * v140;
          bitIODC->bitCnt = *(unsigned __int64 *)((char *)&v150 + 4);
          LODWORD(v57) = v150 >> SBYTE3(v150);
          v132 = (v57 & maskTable[v140] | v145) + v146;
        }
        else
        {
          v133 = bitIODC->bitCnt;
          v135 = *(_DWORD *)(v131 * 4 + HIDWORD(v133));
          v168 = bitIODC->bitBuff;
          v134 = v168;
          v166 = *(unsigned __int64 *)((char *)&v134 + 4);
          if ( v135 > HIDWORD(v168) )
          {
            HIDWORD(v57) = &v166;
            FillBitBuffer(pIO: bitIODC, bitBuff: &v168, bitCnt: v57);
            v134 = __PAIR64__(v166, v168);
          }
          LODWORD(v136) = HIDWORD(v134) - v135;
          bitIODC->bitBuff = v134;
          HIDWORD(v136) = 4 * v135;
          HIDWORD(v134) = gSignificantAbsLevelRemap[v131];
          bitIODC->bitCnt = v136;
          LODWORD(v57) = maskTable[v135];
          v132 = (v57 & (v134 >> v136)) + HIDWORD(v134);
        }
      }
      else
      {
        v132 = v129 + 2;
      }
      v59 = v132 - 1;
      v153 = (_cntlzw(colorFormat - 3) >> 3) & 4;
      ++*(_DWORD *)((char *)v179 + v153);
    }
    if ( v56 > 0 )
    {
      v154 = bitIODC->bitCnt;
      v156 = (unsigned int)v56 > HIDWORD(bitIODC->bitBuff);
      v162 = bitIODC->bitBuff;
      v155 = v162;
      v161 = *(unsigned __int64 *)((char *)&v155 + 4);
      if ( v156 )
      {
        HIDWORD(v57) = &v161;
        FillBitBuffer(pIO: bitIODC, bitBuff: &v162, bitCnt: v57);
        v155 = __PAIR64__(v161, v162);
      }
      HIDWORD(v155) -= v56;
      bitIODC->bitBuff = v155;
      v157 = 4 * v56;
      bitIODC->bitCnt = *(unsigned __int64 *)((char *)&v155 + 4);
      LODWORD(v57) = v155 >> SBYTE3(v155);
      v59 = v57 & maskTable[v56] | (v59 << v56);
    }
    if ( v59 != 0 )
    {
      v158 = bitIODC->bitCnt;
      v162 = bitIODC->bitBuff;
      HIDWORD(v158) = v162;
      v161 = v158;
      if ( (_DWORD)v158 == 0 )
      {
        HIDWORD(v57) = &v161;
        FillBitBuffer(pIO: bitIODC, bitBuff: &v162, bitCnt: v57);
        v158 = v161;
      }
      LODWORD(v158) = v158 - 1;
      v159 = 1;
      bitIODC->bitBuff = *(unsigned __int64 *)((char *)&v158 + 4);
      bitIODC->bitCnt = v158;
      if ( ((*(unsigned __int64 *)((char *)&v158 + 4) >> v158) & 1) != 0 )
        v59 = -v59;
    }
    codec->MBInfo.compactDCLP[2][0] = v59;
  }
  else
  {
    if ( numChannels <= 0 )
      goto LABEL_185;
    v11 = codec[-1].postProcInfo[15];
    v12 = &v178;
    fixedLengthCodeBits = context->adaptCNModelDC.fixedLengthCodeBits;
    v14 = numChannels;
    do
    {
      *((_QWORD *)&v15 + 1) = bitIODC->bitCnt;
      v16 = *fixedLengthCodeBits;
      v163 = bitIODC->bitBuff;
      DWORD2(v15) = v163;
      v164 = v15;
      if ( (_DWORD)v15 == 0 )
      {
        HIDWORD(mbY) = &v164;
        FillBitBuffer(pIO: bitIODC, bitBuff: &v163, bitCnt: mbY);
        *((_QWORD *)&v15 + 1) = v164;
      }
      LODWORD(v15) = v15 - 1;
      DWORD1(v15) = 1;
      bitIODC->bitBuff = *(_QWORD *)((char *)&v15 + 4);
      v17 = 0;
      bitIODC->bitCnt = v15;
      LODWORD(mbY) = (*(_QWORD *)((char *)&v15 + 4) >> v15) & 1;
      if ( (_DWORD)mbY != 0 )
      {
        v18 = context->adaptHuffDC[1].decTable;
        DWORD1(v15) = v15;
        v164 = *(_QWORD *)((char *)&v15 + 4);
        v163 = v15;
        if ( (unsigned int)v15 < 5 )
        {
          HIDWORD(mbY) = &v163;
          FillBitBuffer(pIO: bitIODC, bitBuff: &v164, bitCnt: mbY);
          *(_QWORD *)((char *)&v15 + 4) = __PAIR64__(v163, v164);
        }
        LODWORD(v15) = DWORD1(v15) - 5;
        HIDWORD(v15) = 31;
        bitIODC->bitBuff = *(_QWORD *)((char *)&v15 + 4);
        bitIODC->bitCnt = *(_QWORD *)&v15;
        LODWORD(mbY) = *(_QWORD *)((char *)&v15 + 4) >> (BYTE7(v15) - 5);
        v19 = v18[mbY & 0x1F];
        v20 = v19;
        if ( v19 < 0 )
        {
          *(_QWORD *)&v15 = __PAIR64__(v15, DWORD2(v15));
          bitIODC->bitCnt = v15;
          v174 = *(_QWORD *)((char *)&v15 + 4);
          v176 = v15;
          if ( (unsigned int)v15 < 0x10 )
          {
            HIDWORD(mbY) = &v176;
            FillBitBuffer(pIO: bitIODC, bitBuff: &v174, bitCnt: mbY);
            *(_QWORD *)&v15 = __PAIR64__(v176, v174);
          }
          v21 = 0xFFFF;
          bitIODC->bitBuff = *(_QWORD *)&v15;
          bitIODC->bitCnt = *(_QWORD *)((char *)&v15 + 12);
          *((_QWORD *)&v15 + 1) = (unsigned __int16)(*(_QWORD *)&v15 >> (BYTE3(v15) - 16));
          do
          {
            LODWORD(v15) = 2 * v15;
            ++DWORD2(v15);
            DWORD1(v15) = ((int)v15 >> 16) & 1;
            LODWORD(mbY) = DWORD1(v15) + v20 + 0x8000;
            v20 = v18[(_DWORD)mbY];
          }
          while ( v20 < 0 );
          DWORD2(v15) = HIDWORD(v15) - DWORD2(v15);
        }
        else
        {
          DWORD2(v15) = DWORD1(v15) - (v19 & 7);
          v20 = v19 >> 3;
        }
        bitIODC->bitCnt = *(_QWORD *)((char *)&v15 + 4);
        v22 = v20;
        context->adaptHuffDC[1].discriminant += context->adaptHuffDC[1].deltaTable[v20];
        if ( v20 >= 2 )
        {
          if ( v20 >= 6 )
          {
            v28 = bitIODC->bitCnt;
            v169 = bitIODC->bitBuff;
            HIDWORD(v28) = v169;
            v165 = v28;
            if ( (unsigned int)v28 < 4 )
            {
              HIDWORD(mbY) = &v165;
              FillBitBuffer(pIO: bitIODC, bitBuff: &v169, bitCnt: mbY);
              v28 = v165;
            }
            LODWORD(v28) = v28 - 4;
            v29 = 15;
            bitIODC->bitBuff = *(unsigned __int64 *)((char *)&v28 + 4);
            bitIODC->bitCnt = v28;
            v30 = (*(unsigned __int64 *)((char *)&v28 + 4) >> v28) & 0xF;
            v31 = v30 + 4;
            if ( v30 == 15 )
            {
              v175 = v28;
              v171 = *(unsigned __int64 *)((char *)&v28 + 4);
              if ( (unsigned int)v28 < 2 )
              {
                HIDWORD(mbY) = &v175;
                FillBitBuffer(pIO: bitIODC, bitBuff: &v171, bitCnt: mbY);
              }
              *(unsigned __int64 *)((char *)&v32 + 4) = HIDWORD(v175) | 0x300000000LL;
              LODWORD(v32) = v175 - 2;
              bitIODC->bitBuff = *(unsigned __int64 *)((char *)&v32 + 4);
              bitIODC->bitCnt = v32;
              v34 = (*(unsigned __int64 *)((char *)&v32 + 4) >> v32) & v33;
              v31 = v34 + 19;
              if ( v34 == 3 )
              {
                v168 = v32;
                v166 = *(unsigned __int64 *)((char *)&v32 + 4);
                if ( (unsigned int)v32 < 3 )
                {
                  HIDWORD(mbY) = &v168;
                  FillBitBuffer(pIO: bitIODC, bitBuff: &v166, bitCnt: mbY);
                }
                *(_QWORD *)((char *)&v35 + 4) = HIDWORD(v168) | 0x700000000LL;
                LODWORD(v35) = v168 - 3;
                bitIODC->bitBuff = *(_QWORD *)((char *)&v35 + 4);
                bitIODC->bitCnt = v35;
                v31 = ((*(_QWORD *)((char *)&v35 + 4) >> v35) & DWORD1(v35)) + 22;
              }
            }
            v36 = 0;
            v37 = (1 << v31) + 2;
            if ( v31 > 0x10 )
            {
              v38 = bitIODC->bitCnt;
              v170 = bitIODC->bitBuff;
              HIDWORD(v38) = v170;
              v172 = v38;
              if ( (unsigned int)v38 < 0x10 )
              {
                HIDWORD(mbY) = &v172;
                FillBitBuffer(pIO: bitIODC, bitBuff: &v170, bitCnt: mbY);
                v38 = v172;
              }
              LODWORD(v38) = v38 - 16;
              v39 = 0xFFFF;
              v31 -= 16;
              bitIODC->bitBuff = *(unsigned __int64 *)((char *)&v38 + 4);
              bitIODC->bitCnt = v38;
              LODWORD(mbY) = (unsigned __int16)(*(unsigned __int64 *)((char *)&v38 + 4) >> v38);
              v36 = (_DWORD)mbY << v31;
            }
            v40 = bitIODC->bitCnt;
            v42 = v31 > HIDWORD(bitIODC->bitBuff);
            v161 = bitIODC->bitBuff;
            v41 = v161;
            v162 = *(unsigned __int64 *)((char *)&v41 + 4);
            if ( v42 )
            {
              HIDWORD(mbY) = &v162;
              FillBitBuffer(pIO: bitIODC, bitBuff: &v161, bitCnt: mbY);
              v41 = __PAIR64__(v162, v161);
            }
            HIDWORD(v41) -= v31;
            bitIODC->bitBuff = v41;
            v43 = 4 * v31;
            bitIODC->bitCnt = *(unsigned __int64 *)((char *)&v41 + 4);
            LODWORD(mbY) = v41 >> SBYTE3(v41);
            v23 = (mbY & maskTable[v31] | v36) + v37;
          }
          else
          {
            v24 = bitIODC->bitCnt;
            v26 = *(_DWORD *)(v22 * 4 + HIDWORD(v24));
            v167 = bitIODC->bitBuff;
            v25 = v167;
            v173 = *(unsigned __int64 *)((char *)&v25 + 4);
            if ( v26 > HIDWORD(v167) )
            {
              HIDWORD(mbY) = &v173;
              FillBitBuffer(pIO: bitIODC, bitBuff: &v167, bitCnt: mbY);
              v25 = __PAIR64__(v173, v167);
            }
            LODWORD(v27) = HIDWORD(v25) - v26;
            bitIODC->bitBuff = v25;
            HIDWORD(v27) = 4 * v26;
            HIDWORD(v25) = gSignificantAbsLevelRemap[v22];
            bitIODC->bitCnt = v27;
            LODWORD(mbY) = maskTable[v26];
            v23 = ((v25 >> v27) & mbY) + HIDWORD(v25);
          }
        }
        else
        {
          v23 = v20 + 2;
        }
        v17 = v23 - 1;
        ++*v12;
      }
      if ( v16 > 0 )
      {
        v44 = bitIODC->bitCnt;
        v46 = (unsigned int)v16 > HIDWORD(bitIODC->bitBuff);
        v162 = bitIODC->bitBuff;
        v45 = v162;
        v161 = *(unsigned __int64 *)((char *)&v45 + 4);
        if ( v46 )
        {
          HIDWORD(mbY) = &v161;
          FillBitBuffer(pIO: bitIODC, bitBuff: &v162, bitCnt: mbY);
          v45 = __PAIR64__(v161, v162);
        }
        HIDWORD(v45) -= v16;
        bitIODC->bitBuff = v45;
        v47 = 4 * v16;
        bitIODC->bitCnt = *(unsigned __int64 *)((char *)&v45 + 4);
        LODWORD(mbY) = v45 >> SBYTE3(v45);
        v17 = mbY & maskTable[v16] | (v17 << v16);
      }
      if ( v17 != 0 )
      {
        v48 = bitIODC->bitCnt;
        v162 = bitIODC->bitBuff;
        HIDWORD(v48) = v162;
        v161 = v48;
        if ( (_DWORD)v48 == 0 )
        {
          HIDWORD(mbY) = &v161;
          FillBitBuffer(pIO: bitIODC, bitBuff: &v162, bitCnt: mbY);
          v48 = v161;
        }
        LODWORD(v48) = v48 - 1;
        v49 = 1;
        bitIODC->bitBuff = *(unsigned __int64 *)((char *)&v48 + 4);
        bitIODC->bitCnt = v48;
        LODWORD(mbY) = (*(unsigned __int64 *)((char *)&v48 + 4) >> v48) & 1;
        if ( (_DWORD)mbY != 0 )
          v17 = -v17;
      }
      --v14;
      v11 += 8;
      *(_WORD *)v11 = v17;
      ++fixedLengthCodeBits;
      ++v12;
    }
    while ( v14 != 0 );
  }
  numChannels = v177;
LABEL_185:
  UpdateAdaptiveCoefficientNormalization(
    cf: colorFormat,
    iNumChannels: numChannels,
    iLaplacianMean: &v178,
    pModel: &context->adaptCNModelDC);
  if ( codec->adaptContextHuffman )
    AdaptContextHuffmanDC(context);
  return HDP_ERROR_NONE;
}


// ========================================================================
// DecodeQuantizerIndexLPHP
// EA  : 0x828F20A0
// RVA : 0x008F20A0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdeccoeffs.cpp
// ========================================================================

hdpError_t __fastcall DecodeQuantizerIndexLPHP(hdpCodec_t *codec, hdpContext_t *context, __int64 a3)
{
  hdpTileQuantization_t *tileQuantization; // r10
  hdpStreamLayout_t streamLayout; // r8
  unsigned int currentTileColumn; // r11
  hdpBitIO_t *bitIODC; // r29
  unsigned __int8 *v8; // r30
  hdpError_t result; // r3

  tileQuantization = codec->tileQuantization;
  streamLayout = codec->codecParms.streamLayout;
  currentTileColumn = codec->currentTileColumn;
  bitIODC = context->bitIODC;
  codec->MBInfo.quantizerIndexLP = 0;
  codec->MBInfo.quantizerIndexHP = 0;
  v8 = (unsigned __int8 *)&tileQuantization[currentTileColumn];
  if ( streamLayout == SL_SPATIAL )
  {
    if ( codec->codecParms.subBands < SB_NO_LOWPASS && v8[194] != 0 )
      codec->MBInfo.quantizerIndexLP = DecodeQuantizerIndex(pIO: bitIODC, cBits: v8[194], a3);
    if ( codec->codecParms.subBands < SB_NO_HIGHPASS && v8[195] != 0 )
      codec->MBInfo.quantizerIndexHP = DecodeQuantizerIndex(pIO: bitIODC, cBits: v8[195], a3);
  }
  if ( v8[195] == 0 && v8[193] > 1u )
    codec->MBInfo.quantizerIndexHP = codec->MBInfo.quantizerIndexLP;
  if ( codec->MBInfo.quantizerIndexLP >= (unsigned int)v8[192] )
    return HDP_ERROR_DECODE;
  result = HDP_ERROR_NONE;
  if ( codec->MBInfo.quantizerIndexHP >= (unsigned int)v8[193] )
    return HDP_ERROR_DECODE;
  return result;
}


// ========================================================================
// DecodeBlockInverseScanAdaptive
// EA  : 0x828F2178
// RVA : 0x008F2178
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdeccoeffs.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall DecodeBlockInverseScanAdaptive(
        hdpAdaptiveHuffman_t *adaptHuff,
        int bChroma,
        __int64 iModelBits,
        __int16 *pCoef,
        hdpAdaptiveScan_t *pScan)
{
  unsigned __int64 v5; // r8 OVERLAPPED
  char v6; // r24
  int v7; // r15
  __int64 v9; // r11 OVERLAPPED
  hdpBitIO_t *v10; // r21
  hdpAdaptiveHuffman_t *v11; // r30
  char v12; // r20
  int v13; // r14
  const __int16 *decTable; // r29
  int v15; // r9
  __int64 v16; // r6
  int v17; // r9 OVERLAPPED
  int v18; // r31
  const int *deltaTable; // r9
  __int64 v20; // r6
  int v21; // r26
  int v22; // r23
  __int64 v23; // r6
  int v24; // r25
  int v25; // r18
  _BYTE v26[20]; // r11 OVERLAPPED
  hdpAdaptiveHuffman_t *v27; // r29
  const __int16 *v28; // r30
  __int16 v29; // r3
  int v30; // r31
  int v31; // r30
  unsigned int v32; // r31
  unsigned int v33; // r31
  int v34; // r30
  int v35; // r28
  __int16 v36; // r28
  __int64 v37; // r6
  unsigned int v38; // r31
  int v39; // r30
  __int64 v40; // r6
  int v41; // r4
  int v42; // r4
  int v43; // r3
  int v44; // r24
  int v45; // r25
  int v46; // r31
  unsigned int v47; // r31
  int v48; // r30
  int v49; // r3
  hdpAdaptiveHuffman_t *v50; // r31
  const __int16 *v51; // r30
  const int *deltaTable1; // r6
  const int *v53; // r4
  int v54; // r3
  int v55; // r30
  int v56; // r3
  __int64 v57; // r6
  __int64 v58; // r6
  int v59; // r26
  __int64 v60; // r6
  int v61; // r10
  hdpAdaptiveHuffman_t *v62; // r29
  const __int16 *v63; // r30
  __int64 v64; // r6
  __int16 v65; // r3
  int v66; // r31
  int v67; // r30
  unsigned int v68; // r31
  unsigned int v69; // r31
  int v70; // r30
  int v71; // r28
  __int16 v72; // r4
  int v73; // r4
  __int64 v75; // [sp+50h] [-B0h] BYREF
  unsigned __int64 v76[21]; // [sp+58h] [-A8h] BYREF
  char v77; // [sp+12Fh] [+2Fh]
  int v78; // [sp+134h] [+34h]

  v5 = *(_QWORD *)HIDWORD(iModelBits);
  v6 = 1;
  v77 = iModelBits;
  v7 = (unsigned __int8)bChroma + ((2 * bChroma) & 0x1FE);
  v9 = *(_QWORD *)(HIDWORD(iModelBits) + 8);
  v78 = *(_DWORD *)HIDWORD(iModelBits);
  HIDWORD(v9) = v7 << 6;
  v10 = (hdpBitIO_t *)HIDWORD(iModelBits);
  v76[0] = *(_QWORD *)HIDWORD(iModelBits);
  v11 = &adaptHuff[v7];
  v12 = iModelBits;
  v75 = v9;
  v13 = 1 << iModelBits;
  decTable = v11->decTable;
  if ( (unsigned int)v9 < 5 )
  {
    HIDWORD(iModelBits) = &v75;
    FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: iModelBits);
    v5 = v76[0];
    LODWORD(v9) = v75;
  }
  HIDWORD(v9) = v9 - 5;
  *(unsigned __int64 *)((char *)&v5 - 4) = v5 >> ((unsigned __int8)v9 - 5);
  LODWORD(v16) = v15;
  v17 = (unsigned __int16)decTable[v15 & 0x1F];
  v18 = (__int16)v17;
  if ( (v17 & 0x8000u) != 0 )
  {
    HIDWORD(v5) = HIDWORD(v9);
    v75 = *(__int64 *)((char *)&v9 + 4);
    if ( HIDWORD(v9) < 0x10 )
    {
      HIDWORD(v16) = &v75;
      FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v16);
      v5 = __PAIR64__(v75, v76[0]);
    }
    v9 = (unsigned __int16)(v5 >> (BYTE3(v5) - 16));
    do
    {
      LODWORD(v9) = 2 * v9;
      ++HIDWORD(v9);
      v18 = decTable[(((int)v9 >> 16) & 1) + 0x8000 + v18];
    }
    while ( v18 < 0 );
    LODWORD(v9) = HIDWORD(v5) - HIDWORD(v9);
  }
  else
  {
    LODWORD(v9) = v9 - (v17 & 7);
    v18 = (__int16)v17 >> 3;
  }
  deltaTable = v11->deltaTable;
  HIDWORD(v20) = v11->deltaTable1;
  HIDWORD(v9) = v11->discriminant;
  HIDWORD(v5) = v11->discriminant1;
  v75 = v9;
  LODWORD(v20) = *(_DWORD *)(HIDWORD(v20) + 4 * v18);
  v11->discriminant = deltaTable[v18] + HIDWORD(v9);
  v11->discriminant1 = v20 + HIDWORD(v5);
  if ( (_DWORD)v9 == 0 )
  {
    HIDWORD(v20) = &v75;
    FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v20);
    v5 = v76[0];
    LODWORD(v9) = v75;
  }
  *(_DWORD *)&v26[16] = v9 - 1;
  *(_DWORD *)&v26[12] = 1;
  v21 = v18 & 1;
  *(_QWORD *)&v26[4] = v5 >> v26[19];
  v75 = *(_QWORD *)&v26[12];
  *(_DWORD *)v26 = *(_DWORD *)&v26[8];
  v22 = v18 >> 2;
  LODWORD(v23) = v26[11] & 1;
  v24 = -(int)v23;
  v25 = (v18 >> 2) & (unsigned __int8)v21;
  *(_WORD *)&v26[10] = v13;
  if ( (v18 & 2) != 0 )
  {
    v27 = &adaptHuff[v25 + 6];
    v28 = v27->decTable;
    if ( *(_DWORD *)&v26[16] < 5u )
    {
      HIDWORD(v23) = &v75;
      FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v23);
      *(_QWORD *)v26 = v76[0];
      *(_DWORD *)&v26[16] = v75;
    }
    *(_DWORD *)&v26[12] = *(_DWORD *)&v26[16] - 5;
    *(_DWORD *)&v26[8] = 31;
    LODWORD(v23) = *(_QWORD *)v26 >> (v26[19] - 5);
    v29 = v28[v23 & 0x1F];
    v30 = v29;
    if ( v29 < 0 )
    {
      *(_DWORD *)v26 = *(_DWORD *)&v26[12];
      v75 = *(_QWORD *)&v26[8];
      if ( *(_DWORD *)&v26[12] < 0x10u )
      {
        HIDWORD(v23) = &v75;
        FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v23);
        *(_DWORD *)&v26[4] = v76[0];
        *(_DWORD *)v26 = v75;
      }
      *(_QWORD *)&v26[12] = (unsigned __int16)(*(_QWORD *)v26 >> (v26[3] - 16));
      do
      {
        *(_DWORD *)&v26[16] *= 2;
        ++*(_DWORD *)&v26[12];
        LODWORD(v23) = ((*(int *)&v26[16] >> 16) & 1) + v30;
        v30 = v28[(_DWORD)v23 + 0x8000];
      }
      while ( v30 < 0 );
      *(_DWORD *)&v26[16] = *(_DWORD *)v26 - *(_DWORD *)&v26[12];
    }
    else
    {
      *(_DWORD *)&v26[12] = v29 & 7;
      *(_DWORD *)&v26[16] -= *(_DWORD *)&v26[12];
      v30 = v29 >> 3;
    }
    v75 = *(_QWORD *)&v26[12];
    v31 = v30;
    *(_DWORD *)v26 = v27->deltaTable[v30] + v27->discriminant;
    v27->discriminant = *(_DWORD *)v26;
    if ( v30 >= 2 )
    {
      if ( v30 >= 6 )
      {
        if ( *(_DWORD *)&v26[16] < 4u )
        {
          HIDWORD(v23) = &v75;
          FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v23);
          *(_QWORD *)v26 = v76[0];
          *(_DWORD *)&v26[16] = v75;
        }
        *(_DWORD *)&v26[16] -= 4;
        *(_DWORD *)&v26[12] = 15;
        *(_QWORD *)&v26[4] = *(_QWORD *)v26 >> v26[19];
        v75 = *(_QWORD *)&v26[12];
        *(_DWORD *)v26 = *(_DWORD *)&v26[8];
        v33 = (v26[11] & 0xF) + 4;
        if ( (v26[11] & 0xF) == 0xF )
        {
          if ( *(_DWORD *)&v26[16] < 2u )
          {
            HIDWORD(v23) = &v75;
            FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v23);
            *(_QWORD *)v26 = v76[0];
            *(_DWORD *)&v26[16] = v75;
          }
          *(_DWORD *)&v26[16] -= 2;
          *(_DWORD *)&v26[12] = 3;
          *(_QWORD *)&v26[4] = *(_QWORD *)v26 >> v26[19];
          v75 = *(_QWORD *)&v26[12];
          *(_DWORD *)v26 = *(_DWORD *)&v26[8];
          v33 = (v26[11] & 3) + 19;
          if ( (v26[11] & 3) == 3 )
          {
            if ( *(_DWORD *)&v26[16] < 3u )
            {
              HIDWORD(v23) = &v75;
              FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v23);
              *(_QWORD *)v26 = v76[0];
              *(_DWORD *)&v26[16] = v75;
            }
            *(_DWORD *)&v26[16] -= 3;
            *(_DWORD *)&v26[12] = 7;
            *(_QWORD *)&v26[4] = *(_QWORD *)v26 >> v26[19];
            v75 = *(_QWORD *)&v26[12];
            *(_DWORD *)v26 = *(_DWORD *)&v26[8];
            v33 = (v26[11] & 7) + 22;
          }
        }
        v34 = 0;
        v35 = (1 << v33) + 2;
        if ( v33 > 0x10 )
        {
          if ( *(_DWORD *)&v26[16] < 0x10u )
          {
            HIDWORD(v23) = &v75;
            FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v23);
            *(_QWORD *)v26 = v76[0];
            *(_DWORD *)&v26[16] = v75;
          }
          *(_DWORD *)&v26[16] -= 16;
          *(_DWORD *)&v26[12] = 0xFFFF;
          v33 -= 16;
          *(_QWORD *)&v26[4] = *(_QWORD *)v26 >> v26[19];
          v75 = *(_QWORD *)&v26[12];
          *(_DWORD *)v26 = *(_DWORD *)&v26[8];
          LODWORD(v23) = *(unsigned __int16 *)&v26[10];
          v34 = *(unsigned __int16 *)&v26[10] << v33;
        }
        if ( v33 > *(_DWORD *)&v26[16] )
        {
          HIDWORD(v23) = &v75;
          FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v23);
          *(_QWORD *)v26 = v76[0];
          *(_DWORD *)&v26[16] = v75;
        }
        *(_DWORD *)&v26[16] -= v33;
        *(_QWORD *)&v26[4] = *(_QWORD *)v26 >> v26[19];
        LODWORD(v23) = *(_DWORD *)&v26[8];
        *(_DWORD *)&v26[12] = (*(_DWORD *)&v26[8] & maskTable[v33] | v34) + v35;
      }
      else
      {
        v32 = gSignificantAbsLevelFixedLength[v31];
        if ( v32 > *(_DWORD *)&v26[16] )
        {
          HIDWORD(v23) = &v75;
          FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v23);
          *(_DWORD *)&v26[4] = v76[0];
          *(_DWORD *)&v26[16] = v75;
        }
        *(_DWORD *)&v26[16] -= v32;
        *(_DWORD *)v26 = gSignificantAbsLevelRemap;
        *(_QWORD *)&v26[4] = *(_QWORD *)v26 >> v26[19];
        LODWORD(v23) = maskTable[v32];
        *(_DWORD *)&v26[12] = gSignificantAbsLevelRemap[v31] + (*(_DWORD *)&v26[8] & v23);
      }
      v75 = *(_QWORD *)&v26[12];
    }
    else
    {
      *(_DWORD *)&v26[12] = v30 + 2;
    }
    *(_DWORD *)&v26[8] = *(_DWORD *)&v26[12] << v12;
  }
  v36 = (*(_WORD *)&v26[10] ^ v24) - v24;
  if ( v21 == 0 )
  {
    if ( *(_DWORD *)&v26[16] < 4u )
    {
      HIDWORD(v23) = &v75;
      FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v23);
      *(_DWORD *)&v26[4] = v76[0];
      *(_DWORD *)&v26[16] = v75;
    }
    *(_DWORD *)v26 = 15;
    LODWORD(v37) = gSignificantRunIndex;
    *(_DWORD *)v26 = 4 * ((*(_QWORD *)v26 >> (v26[19] - 4)) & 0xF);
    *(_DWORD *)&v26[16] -= *(const int *)((char *)gSignificantRunNumBits + *(_DWORD *)v26);
    *(_DWORD *)&v26[12] = 4 * *(const int *)((char *)gSignificantRunIndex + *(_DWORD *)v26);
    v75 = *(_QWORD *)&v26[12];
    v38 = *(const int *)((char *)gSignificantRunFixedLength + *(_DWORD *)&v26[12]);
    v39 = *(const int *)((char *)gSignificantRunRemap + *(_DWORD *)&v26[12]);
    if ( v38 != 0 )
    {
      if ( v38 > *(_DWORD *)&v26[16] )
      {
        HIDWORD(v37) = &v75;
        FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v37);
        *(_QWORD *)v26 = v76[0];
        *(_DWORD *)&v26[16] = v75;
      }
      *(_DWORD *)&v26[16] -= v38;
      *(_DWORD *)&v26[12] = 4 * v38;
      *(_QWORD *)&v26[4] = *(_QWORD *)v26 >> v26[19];
      v75 = *(_QWORD *)&v26[12];
      v39 += *(_DWORD *)&v26[8] & maskTable[v38];
    }
    v6 = v39 + 1;
  }
  *(_DWORD *)&v26[8] = v6 & 0xF;
  LODWORD(v40) = pScan;
  *(_DWORD *)&v26[12] = &pScan[*(_DWORD *)&v26[8]];
  v41 = *(_DWORD *)(*(_DWORD *)&v26[12] + 4);
  *(_WORD *)(2 * v41 + v78) = v36;
  if ( (v6 & 0xF) != 0
    && (*(_DWORD *)v26 = **(_DWORD **)&v26[12],
        LODWORD(v40) = *(_DWORD *)(*(_DWORD *)&v26[12] - 8),
        **(_DWORD **)&v26[12] + 1 > (unsigned int)v40) )
  {
    LODWORD(v40) = v41;
    v42 = *(_DWORD *)(*(_DWORD *)&v26[12] - 8);
    v43 = *(_DWORD *)(*(_DWORD *)&v26[12] - 4);
    *(_DWORD *)(*(_DWORD *)&v26[12] - 4) = v40;
    *(_DWORD *)(*(_DWORD *)&v26[12] - 8) = *(_DWORD *)v26 + 1;
    **(_DWORD **)&v26[12] = v42;
    *(_DWORD *)(*(_DWORD *)&v26[12] + 4) = v43;
  }
  else
  {
    *(_DWORD *)v26 = **(_DWORD **)&v26[12] + 1;
    **(_DWORD **)&v26[12] = *(_DWORD *)v26;
  }
  *(_DWORD *)&v26[12] = *(_DWORD *)&v26[8] + 1;
  v44 = 1;
  v45 = (*(_DWORD *)&v26[8] + 1) & 0xF;
  if ( v22 == 0 )
  {
LABEL_136:
    v10->bitBuff = *(_QWORD *)v26;
    v10->bitCnt = *(_QWORD *)&v26[12];
    return v44;
  }
  while ( 1 )
  {
    if ( (v22 & 1) == 0 )
    {
      v46 = 15 - v45;
      if ( 15 - v45 < 5 )
      {
        if ( (unsigned int)(v46 - 1) > *(_DWORD *)&v26[16] )
        {
          HIDWORD(v40) = &v75;
          FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v40);
          *(_QWORD *)v26 = v76[0];
          *(_DWORD *)&v26[16] = v75;
        }
        *(_QWORD *)&v26[16] = *(_QWORD *)v26 >> (v26[19] - ((unsigned __int8)v46 - 1));
        LODWORD(v40) = maskTable[v46 - 1];
        *(_DWORD *)&v26[8] = v46 - 1;
        v49 = (4 * ~(*(_DWORD *)v26 & v40)) & 0x1C;
        *(_DWORD *)&v26[12] = *(const int *)((char *)gSignificantRunOffset + v49) + v46;
        if ( *(int *)&v26[12] < v46 - 1 )
          *(_DWORD *)&v26[8] = *(const int *)((char *)gSignificantRunOffset + v49) + v46;
        v45 += *(_DWORD *)&v26[12];
        *(_DWORD *)&v26[16] -= *(_DWORD *)&v26[8];
        v75 = *(_QWORD *)&v26[12];
      }
      else
      {
        if ( *(_DWORD *)&v26[16] < 4u )
        {
          HIDWORD(v40) = &v75;
          FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v40);
          *(_DWORD *)&v26[4] = v76[0];
          *(_DWORD *)&v26[16] = v75;
        }
        *(_DWORD *)v26 = 4 * v46;
        *(_DWORD *)v26 = 4 * ((*(_QWORD *)v26 >> (v26[19] - 4)) & 0xF);
        LODWORD(v40) = gSignificantRunNumBits;
        *(_DWORD *)&v26[12] = 5 * gSignificantRunBin[v46]
                            + *(const int *)((char *)gSignificantRunIndex + *(_DWORD *)v26);
        *(_DWORD *)&v26[16] -= *(const int *)((char *)gSignificantRunNumBits + *(_DWORD *)v26);
        v75 = *(_QWORD *)&v26[12];
        v47 = gSignificantRunFixedLength[*(_DWORD *)&v26[12]];
        v48 = gSignificantRunRemap[*(_DWORD *)&v26[12]];
        if ( v47 != 0 )
        {
          if ( v47 > *(_DWORD *)&v26[16] )
          {
            HIDWORD(v40) = &v75;
            FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v40);
            *(_QWORD *)v26 = v76[0];
            *(_DWORD *)&v26[16] = v75;
          }
          *(_DWORD *)&v26[16] -= v47;
          *(_DWORD *)&v26[12] = 4 * v47;
          *(_QWORD *)&v26[4] = *(_QWORD *)v26 >> v26[19];
          v75 = *(_QWORD *)&v26[12];
          *(_DWORD *)v26 = maskTable[v47];
          LODWORD(v40) = *(_DWORD *)&v26[8];
          v48 += *(_DWORD *)&v26[8] & *(_DWORD *)v26;
        }
        v45 += v48;
      }
      if ( v45 >= 16 )
        return 16;
    }
    ++v44;
    if ( v45 >= 14 )
    {
      if ( v45 != 14 )
      {
        if ( *(_DWORD *)&v26[16] < 2u )
        {
          HIDWORD(v40) = &v75;
          FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v40);
          *(_QWORD *)v26 = v76[0];
          *(_DWORD *)&v26[16] = v75;
        }
        *(_DWORD *)&v26[16] -= 2;
        *(_DWORD *)&v26[12] = 3;
        *(_QWORD *)&v26[4] = *(_QWORD *)v26 >> v26[19];
        *(_DWORD *)v26 = *(_DWORD *)&v26[8];
        LODWORD(v58) = v26[11] & 3;
        v55 = (int)v58 >> 1;
        v59 = -(v26[11] & 1);
        goto LABEL_97;
      }
      if ( *(_DWORD *)&v26[16] == 0 )
      {
        HIDWORD(v40) = &v75;
        FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v40);
        *(_QWORD *)v26 = v76[0];
        *(_DWORD *)&v26[16] = v75;
      }
      --*(_DWORD *)&v26[16];
      *(_DWORD *)&v26[12] = 1;
      *(_QWORD *)&v26[4] = *(_QWORD *)v26 >> v26[19];
      v75 = *(_QWORD *)&v26[12];
      *(_DWORD *)v26 = *(_DWORD *)&v26[8];
      LODWORD(v60) = v26[11] & 1;
      if ( (v26[11] & 1) != 0 )
      {
        if ( *(_DWORD *)&v26[16] == 0 )
        {
          HIDWORD(v60) = &v75;
          FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v60);
          *(_QWORD *)v26 = v76[0];
          *(_DWORD *)&v26[16] = v75;
        }
        --*(_DWORD *)&v26[16];
        *(_DWORD *)&v26[12] = 1;
        *(_QWORD *)&v26[4] = *(_QWORD *)v26 >> v26[19];
        v75 = *(_QWORD *)&v26[12];
        *(_DWORD *)v26 = *(_DWORD *)&v26[8];
        LODWORD(v60) = v26[11] & 1;
        if ( (v26[11] & 1) != 0 )
        {
          if ( *(_DWORD *)&v26[16] == 0 )
          {
            HIDWORD(v60) = &v75;
            FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v60);
            *(_QWORD *)v26 = v76[0];
            *(_DWORD *)&v26[16] = v75;
          }
          --*(_DWORD *)&v26[16];
          *(_DWORD *)&v26[12] = 1;
          *(_QWORD *)&v26[4] = *(_QWORD *)v26 >> v26[19];
          v75 = *(_QWORD *)&v26[12];
          *(_DWORD *)v26 = *(_DWORD *)&v26[8];
          LODWORD(v60) = v26[11] & 1;
          v55 = 2 * v60 + 1;
        }
        else
        {
          v55 = 2;
        }
      }
      else
      {
        v55 = 0;
      }
      if ( *(_DWORD *)&v26[16] == 0 )
      {
        HIDWORD(v60) = &v75;
        FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v60);
        *(_DWORD *)&v26[16] = v75 - 1;
        *(_DWORD *)&v26[12] = 1;
        *(_QWORD *)&v26[4] = v76[0] >> ((unsigned __int8)v75 - 1);
        *(_DWORD *)v26 = *(_DWORD *)&v26[8];
        LODWORD(v58) = v26[11] & 1;
        v59 = -(int)v58;
        goto LABEL_97;
      }
    }
    else
    {
      v50 = &adaptHuff[v25 + v7 + 1];
      v51 = v50->decTable;
      if ( *(_DWORD *)&v26[16] < 5u )
      {
        HIDWORD(v40) = &v75;
        FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v40);
        *(_QWORD *)v26 = v76[0];
        *(_DWORD *)&v26[16] = v75;
      }
      deltaTable1 = v50->deltaTable1;
      v53 = v50->deltaTable;
      v54 = *(_QWORD *)v26 >> (v26[19] - 5);
      *(_DWORD *)&v26[12] = v50->discriminant;
      *(_DWORD *)v26 = v50->discriminant1;
      *(_DWORD *)&v26[8] = v51[v54 & 0x1F];
      v55 = *(int *)&v26[8] >> 3;
      v56 = *(int *)&v26[8] >> 3;
      *(_DWORD *)&v26[16] -= v26[11] & 7;
      v75 = *(_QWORD *)&v26[12];
      LODWORD(v57) = deltaTable1[v56];
      v50->discriminant = v53[v56] + *(_DWORD *)&v26[12];
      v50->discriminant1 = v57 + *(_DWORD *)v26;
      if ( *(_DWORD *)&v26[16] == 0 )
      {
        HIDWORD(v57) = &v75;
        FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v57);
        *(_QWORD *)v26 = v76[0];
        *(_DWORD *)&v26[16] = v75;
      }
    }
    --*(_DWORD *)&v26[16];
    *(_DWORD *)&v26[12] = 1;
    *(_QWORD *)&v26[4] = *(_QWORD *)v26 >> v26[19];
    *(_DWORD *)v26 = *(_DWORD *)&v26[8];
    LODWORD(v58) = v26[11] & 1;
    v59 = -(int)v58;
LABEL_97:
    v22 = v55 >> 1;
    v75 = *(_QWORD *)&v26[12];
    v25 &= v55 >> 1;
    v61 = v13;
    if ( (v55 & 1) != 0 )
    {
      v62 = &adaptHuff[v25 + 6];
      v63 = v62->decTable;
      if ( *(_DWORD *)&v26[16] < 5u )
      {
        HIDWORD(v58) = &v75;
        FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v58);
        *(_QWORD *)v26 = v76[0];
        *(_DWORD *)&v26[16] = v75;
      }
      *(_DWORD *)&v26[12] = *(_DWORD *)&v26[16] - 5;
      *(_DWORD *)&v26[8] = 31;
      *(_QWORD *)&v26[16] = *(_QWORD *)v26 >> (v26[19] - 5);
      LODWORD(v64) = *(_DWORD *)v26;
      v65 = v63[v26[3] & 0x1F];
      v66 = v65;
      if ( v65 < 0 )
      {
        *(_DWORD *)v26 = *(_DWORD *)&v26[12];
        v75 = *(_QWORD *)&v26[8];
        if ( *(_DWORD *)&v26[12] < 0x10u )
        {
          HIDWORD(v64) = &v75;
          FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v64);
          *(_DWORD *)&v26[4] = v76[0];
          *(_DWORD *)v26 = v75;
        }
        *(_QWORD *)&v26[12] = (unsigned __int16)(*(_QWORD *)v26 >> (v26[3] - 16));
        do
        {
          *(_DWORD *)&v26[16] *= 2;
          ++*(_DWORD *)&v26[12];
          LODWORD(v64) = ((*(int *)&v26[16] >> 16) & 1) + v66;
          v66 = v63[(_DWORD)v64 + 0x8000];
        }
        while ( v66 < 0 );
        *(_DWORD *)&v26[16] = *(_DWORD *)v26 - *(_DWORD *)&v26[12];
      }
      else
      {
        *(_DWORD *)&v26[16] -= v65 & 7;
        v66 = v65 >> 3;
      }
      *(_DWORD *)&v26[12] = v62->deltaTable;
      v67 = v66;
      *(_DWORD *)&v26[8] = v62->discriminant;
      v75 = *(_QWORD *)&v26[12];
      v62->discriminant = *(_DWORD *)(*(_DWORD *)&v26[12] + 4 * v66) + *(_DWORD *)&v26[8];
      if ( v66 >= 2 )
      {
        if ( v66 >= 6 )
        {
          if ( *(_DWORD *)&v26[16] < 4u )
          {
            HIDWORD(v64) = &v75;
            FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v64);
            *(_QWORD *)v26 = v76[0];
            *(_DWORD *)&v26[16] = v75;
          }
          *(_DWORD *)&v26[16] -= 4;
          *(_DWORD *)&v26[12] = 15;
          *(_QWORD *)&v26[4] = *(_QWORD *)v26 >> v26[19];
          v75 = *(_QWORD *)&v26[12];
          *(_DWORD *)v26 = *(_DWORD *)&v26[8];
          v69 = (v26[11] & 0xF) + 4;
          if ( (v26[11] & 0xF) == 0xF )
          {
            if ( *(_DWORD *)&v26[16] < 2u )
            {
              HIDWORD(v64) = &v75;
              FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v64);
              *(_QWORD *)v26 = v76[0];
              *(_DWORD *)&v26[16] = v75;
            }
            *(_DWORD *)&v26[16] -= 2;
            *(_DWORD *)&v26[12] = 3;
            *(_QWORD *)&v26[4] = *(_QWORD *)v26 >> v26[19];
            v75 = *(_QWORD *)&v26[12];
            *(_DWORD *)v26 = *(_DWORD *)&v26[8];
            v69 = (v26[11] & 3) + 19;
            if ( (v26[11] & 3) == 3 )
            {
              if ( *(_DWORD *)&v26[16] < 3u )
              {
                HIDWORD(v64) = &v75;
                FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v64);
                *(_QWORD *)v26 = v76[0];
                *(_DWORD *)&v26[16] = v75;
              }
              *(_DWORD *)&v26[16] -= 3;
              *(_DWORD *)&v26[12] = 7;
              *(_QWORD *)&v26[4] = *(_QWORD *)v26 >> v26[19];
              v75 = *(_QWORD *)&v26[12];
              *(_DWORD *)v26 = *(_DWORD *)&v26[8];
              v69 = (v26[11] & 7) + 22;
            }
          }
          v70 = 0;
          v71 = (1 << v69) + 2;
          if ( v69 > 0x10 )
          {
            if ( *(_DWORD *)&v26[16] < 0x10u )
            {
              HIDWORD(v64) = &v75;
              FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v64);
              *(_QWORD *)v26 = v76[0];
              *(_DWORD *)&v26[16] = v75;
            }
            *(_DWORD *)&v26[16] -= 16;
            *(_DWORD *)&v26[12] = 0xFFFF;
            v69 -= 16;
            *(_QWORD *)&v26[4] = *(_QWORD *)v26 >> v26[19];
            v75 = *(_QWORD *)&v26[12];
            *(_DWORD *)v26 = *(_DWORD *)&v26[8];
            LODWORD(v64) = *(unsigned __int16 *)&v26[10];
            v70 = *(unsigned __int16 *)&v26[10] << v69;
          }
          if ( v69 > *(_DWORD *)&v26[16] )
          {
            HIDWORD(v64) = &v75;
            FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v64);
            *(_QWORD *)v26 = v76[0];
            *(_DWORD *)&v26[16] = v75;
          }
          *(_DWORD *)&v26[16] -= v69;
          *(_QWORD *)&v26[4] = *(_QWORD *)v26 >> v26[19];
          *(_DWORD *)&v26[12] = (*(_DWORD *)&v26[8] & maskTable[v69] | v70) + v71;
        }
        else
        {
          v68 = gSignificantAbsLevelFixedLength[v67];
          if ( v68 > *(_DWORD *)&v26[16] )
          {
            HIDWORD(v64) = &v75;
            FillBitBuffer(pIO: v10, bitBuff: v76, bitCnt: v64);
            *(_DWORD *)&v26[4] = v76[0];
            *(_DWORD *)&v26[16] = v75;
          }
          *(_DWORD *)&v26[16] -= v68;
          *(_DWORD *)v26 = gSignificantAbsLevelRemap;
          *(_QWORD *)&v26[4] = *(_QWORD *)v26 >> v26[19];
          *(_DWORD *)&v26[12] = gSignificantAbsLevelRemap[v67] + (*(_DWORD *)&v26[8] & maskTable[v68]);
        }
        v75 = *(_QWORD *)&v26[12];
      }
      else
      {
        *(_DWORD *)&v26[12] = v66 + 2;
      }
      v61 = *(_DWORD *)&v26[12] << v77;
    }
    LODWORD(v40) = v61 ^ v59;
    v72 = (v61 ^ v59) - v59;
    *(_DWORD *)&v26[12] = &pScan[v45];
    *(_DWORD *)v26 = 2 * *(_DWORD *)(*(_DWORD *)&v26[12] + 4);
    *(_WORD *)(*(_DWORD *)v26 + v78) = v72;
    if ( v45 != 0
      && (*(_DWORD *)&v26[8] = **(_DWORD **)&v26[12],
          *(_DWORD *)v26 = *(_DWORD *)(*(_DWORD *)&v26[12] - 8),
          LODWORD(v40) = **(_DWORD **)&v26[12] + 1,
          (unsigned int)v40 > *(_DWORD *)v26) )
    {
      *(_DWORD *)v26 = *(_DWORD *)(*(_DWORD *)&v26[12] + 4);
      LODWORD(v40) = *(_DWORD *)&v26[8] + 1;
      HIDWORD(v40) = *(_DWORD *)(*(_DWORD *)&v26[12] - 8);
      v73 = *(_DWORD *)(*(_DWORD *)&v26[12] - 4);
      *(_DWORD *)(*(_DWORD *)&v26[12] - 8) = *(_DWORD *)&v26[8] + 1;
      *(_DWORD *)(*(_DWORD *)&v26[12] - 4) = *(_DWORD *)v26;
      **(_DWORD **)&v26[12] = HIDWORD(v40);
      *(_DWORD *)(*(_DWORD *)&v26[12] + 4) = v73;
    }
    else
    {
      ++**(_DWORD **)&v26[12];
    }
    *(_DWORD *)&v26[12] = v45 + 1;
    v45 = (v45 + 1) & 0xF;
    if ( v22 == 0 )
      goto LABEL_136;
  }
}


// ========================================================================
// DecodeMacroblockHighPass
// EA  : 0x828F2E68
// RVA : 0x008F2E68
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdeccoeffs.cpp
// ========================================================================

int __fastcall DecodeMacroblockHighPass(hdpCodec_t *codec, hdpContext_t *context, __int64 mbY)
{
  hdpColorFormat_t colorFormat; // r26
  unsigned int numChannels; // r27
  int v7; // r29
  int v8; // r28
  signed int v9; // r14
  BOOL resetAdaptiveScanTotals; // r11
  hdpTileQuantization_t *v11; // r31
  unsigned __int8 v12; // r3
  unsigned int cNumQPHP; // r11
  int trimTileFlexBits; // r20
  int v16; // r18
  int *v17; // r29
  int *fixedLengthCodeBits; // r17
  int *actualCBP; // r22
  hdpAdaptiveScan_t *v20; // r23
  int v21; // r28
  int v22; // r27
  BOOL v23; // r24
  int v24; // r26
  int v25; // r19
  int v26; // r25
  int v27; // r11
  int v28; // r10
  int v29; // r11
  int v30; // r10
  __int16 *v31; // r31
  __int64 v32; // r6
  int v33; // r3
  hdpColorFormat_t v34; // [sp+50h] [-F0h]
  unsigned int v35; // [sp+54h] [-ECh]
  int v36[56]; // [sp+60h] [-E0h] BYREF

  colorFormat = codec->codecParms.colorFormat;
  numChannels = codec->codecParms.numChannels;
  v7 = HIDWORD(mbY);
  v8 = mbY;
  v34 = colorFormat;
  v35 = numChannels;
  if ( colorFormat == CF_YUV_420 || (v9 = codec->codecParms.numChannels, colorFormat == CF_YUV_422) )
    v9 = 1;
  resetAdaptiveScanTotals = codec->resetAdaptiveScanTotals;
  memset(v36, 0, 64);
  if ( resetAdaptiveScanTotals )
    ResetAdaptiveScanTotalsHP(context);
  if ( codec->codecParms.streamLayout == SL_FREQUENCY )
  {
    v11 = &codec->tileQuantization[codec->currentTileColumn];
    if ( v11->cBitsHP != 0 )
    {
      v12 = DecodeQuantizerIndex(pIO: context->bitIOHP, cBits: v11->cBitsHP, a3: mbY);
      cNumQPHP = v11->cNumQPHP;
      codec->MBInfo.quantizerIndexHP = v12;
      if ( v12 >= cNumQPHP )
        return -5;
    }
    else if ( v11->cNumQPHP > 1u )
    {
      codec->MBInfo.quantizerIndexHP = codec->MBInfo.quantizerIndexLP;
    }
  }
  DecodeHPCBP(codec, context);
  PredictHPCBPDec(codec, context, mbX: v7, mbY: v8);
  if ( codec->codecParms.decodeFlexbits )
    trimTileFlexBits = context->trimTileFlexBits;
  else
    trimTileFlexBits = 16;
  v16 = 0;
  if ( v9 > 0 )
  {
    v17 = v36;
    fixedLengthCodeBits = context->adaptCNModelHP.fixedLengthCodeBits;
    actualCBP = codec->MBInfo.actualCBP;
LABEL_17:
    v20 = context->adaptScanVerHP[0];
    if ( actualCBP[32] != 1 )
      v20 = context->adaptScanHorHP[0];
    v21 = *actualCBP;
    v22 = *fixedLengthCodeBits;
    v23 = v16 > 0 && (colorFormat == CF_YUV_444 || colorFormat == CF_YUV_422 || colorFormat == CF_YUV_420);
    v24 = 0;
    v25 = 0;
LABEL_26:
    v26 = 0;
    v27 = (4 * v24) & 0x3C;
    while ( 1 )
    {
      v28 = *(const int *)((char *)blkOffset + v27);
      v29 = actualCBP[192];
      v30 = 2 * v28;
      v31 = (__int16 *)(v30 + v29);
      if ( (v21 & 1) != 0 )
      {
        HIDWORD(v32) = context->bitIOHP;
        LODWORD(v32) = v22;
        v33 = DecodeBlockInverseScanAdaptive(
                adaptHuff: context->adaptHuffHP,
                bChroma: v23,
                iModelBits: v32,
                pCoef: (__int16 *)(v30 + v29),
                pScan: v20);
        *v17 += v33;
        if ( v33 >= 16 )
          return -5;
      }
      if ( v22 - trimTileFlexBits > 0 )
        DecodeBlockFlexBits(
          pIO: context->bitIOFL,
          iFlexBits: v22 - trimTileFlexBits,
          iTrimFlexBits: trimTileFlexBits,
          pCoeffs: v31);
      ++v26;
      ++v24;
      v21 >>= 1;
      v27 = (4 * v24) & 0x3C;
      if ( v26 >= 4 )
      {
        if ( ++v25 < 4 )
          goto LABEL_26;
        ++v16;
        colorFormat = v34;
        ++actualCBP;
        ++v17;
        ++fixedLengthCodeBits;
        if ( v16 >= v9 )
        {
          numChannels = v35;
          break;
        }
        goto LABEL_17;
      }
    }
  }
  UpdateAdaptiveCoefficientNormalization(
    cf: colorFormat,
    iNumChannels: numChannels,
    iLaplacianMean: v36,
    pModel: &context->adaptCNModelHP);
  if ( codec->adaptContextHuffman )
    AdaptContextHuffmanHP(context);
  return 0;
}


// ========================================================================
// DecodeMacroblockLowPass
// EA  : 0x828F30F8
// RVA : 0x008F30F8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdeccoeffs.cpp
// ========================================================================

int __fastcall DecodeMacroblockLowPass(hdpCodec_t *codec, hdpContext_t *context, __int64 mbY)
{
  hdpColorFormat_t colorFormat; // r19
  unsigned int numChannels; // r18
  signed int v7; // r20
  BOOL resetAdaptiveScanTotals; // r11
  hdpBitIO_t *bitIOLP; // r22
  hdpTileQuantization_t *v10; // r31
  unsigned __int8 v11; // r3
  unsigned int cNumQPLP; // r11
  unsigned int quantizerIndexLP; // r10
  int v15; // r21
  int v16; // r28
  hdpCodec_t *v17; // r30
  int *v18; // r31
  int *fixedLengthCodeBits; // r26
  int v20; // r29
  BOOL v21; // r4
  __int64 v22; // r6
  int v23; // r3
  int v24[48]; // [sp+50h] [-C0h] BYREF

  colorFormat = codec->codecParms.colorFormat;
  numChannels = codec->codecParms.numChannels;
  if ( colorFormat == CF_YUV_420 || (v7 = codec->codecParms.numChannels, colorFormat == CF_YUV_422) )
    v7 = 2;
  resetAdaptiveScanTotals = codec->resetAdaptiveScanTotals;
  bitIOLP = context->bitIOLP;
  memset(v24, 0, 64);
  if ( resetAdaptiveScanTotals )
    ResetAdaptiveScanTotalsLP(context);
  if ( codec->codecParms.streamLayout == SL_FREQUENCY )
  {
    v10 = &codec->tileQuantization[codec->currentTileColumn];
    if ( v10->cBitsLP != 0 )
    {
      v11 = DecodeQuantizerIndex(pIO: bitIOLP, cBits: v10->cBitsLP, a3: mbY);
      cNumQPLP = v10->cNumQPLP;
      quantizerIndexLP = codec->MBInfo.quantizerIndexLP;
      codec->MBInfo.quantizerIndexLP = v11;
      if ( quantizerIndexLP >= cNumQPLP )
        return -5;
    }
  }
  v15 = DecodeLPCBP(codec, context, a3: mbY);
  v16 = 0;
  if ( v7 > 0 )
  {
    v17 = codec;
    v18 = v24;
    fixedLengthCodeBits = context->adaptCNModelLP.fixedLengthCodeBits;
    do
    {
      v20 = *fixedLengthCodeBits;
      v21 = v16 > 0 && (colorFormat == CF_YUV_444 || colorFormat == CF_YUV_422 || colorFormat == CF_YUV_420);
      if ( (v15 & 1) != 0 )
      {
        LODWORD(v22) = *fixedLengthCodeBits;
        HIDWORD(v22) = bitIOLP;
        v23 = DecodeBlockInverseScanAdaptive(
                adaptHuff: context->adaptHuffLP,
                bChroma: v21,
                iModelBits: v22,
                pCoef: (__int16 *)v17,
                pScan: context->adaptScanLP[0]);
        *v18 += v23;
        if ( v23 >= 16 )
          return -5;
      }
      if ( v20 > 0 )
        DecodeBlockModelBits(pIO: bitIOLP, iModelBits: v20, pCoeffs: (__int16 *)v17);
      ++v16;
      ++fixedLengthCodeBits;
      ++v18;
      v17 = (hdpCodec_t *)((char *)v17 + 32);
      v15 >>= 1;
    }
    while ( v16 < v7 );
  }
  UpdateAdaptiveCoefficientNormalization(
    cf: colorFormat,
    iNumChannels: numChannels,
    iLaplacianMean: v24,
    pModel: &context->adaptCNModelLP);
  if ( codec->adaptContextHuffman )
    AdaptContextHuffmanLP(context);
  return 0;
}


// ========================================================================
// ?DecodeMacroblock@@YA?AW4hdpError_t@@PIAUhdpCodec_t@@PIAUhdpContext_t@@HH@Z
// EA  : 0x828F32D8
// RVA : 0x008F32D8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpdeccoeffs.cpp
// ========================================================================

hdpError_t __fastcall DecodeMacroblock(hdpCodec_t *codec, hdpContext_t *context, __int64 mbY)
{
  unsigned int v5; // r29
  unsigned int v6; // r28
  __int64 v7; // r6
  hdpError_t result; // r3
  __int64 v9; // r6

  v5 = HIDWORD(mbY);
  v6 = mbY;
  result = DecodeQuantizerIndexLPHP(codec, context, a3: mbY);
  if ( result == HDP_ERROR_NONE )
  {
    result = DecodeMacroblockDC(codec, context, mbY: v7);
    if ( result == HDP_ERROR_NONE
      && (!codec->codecParms.decodeLP || (result = DecodeMacroblockLowPass(codec, context, mbY: v9)) == HDP_ERROR_NONE) )
    {
      PredictDCLPDec(codec);
      if ( codec->codecParms.decodeHP )
      {
        result = DecodeMacroblockHighPass(codec, context, mbY: __SPAIR64__(v5, v6));
        if ( result != HDP_ERROR_NONE )
          return result;
        PredictHPDec(codec);
      }
      UpdatePredictionInfo(codec, mbX: v5);
      return HDP_ERROR_NONE;
    }
  }
  return result;
}

