
// ========================================================================
// ?QuantizeMacroblock@@YA?AW4hdpError_t@@PAUhdpCodec_t@@@Z
// EA  : 0x828FB040
// RVA : 0x008FB040
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpquantizationenc.cpp
// ========================================================================

hdpError_t __fastcall QuantizeMacroblock(hdpCodec_t *codec)
{
  unsigned int numChannels; // r23
  hdpColorFormat_t colorFormat; // r22
  unsigned int v3; // r26
  hdpQuantizer_t **pQuantizerHP; // r28
  __int16 **macroBlockPrevColumnPtr; // r27
  int v7; // r31
  const int *v8; // r30
  int v9; // r6
  signed int *v10; // r4
  signed int *v11; // r5
  unsigned int *v12; // r10
  int v13; // r11
  __int16 *v14; // r11
  signed int v15; // r8
  signed int v16; // r21
  __int16 v17; // r9
  int v18; // r7
  int v19; // r9
  int v20; // r7
  int i; // ctr
  unsigned int v22; // r8
  int v23; // r7
  signed int v24; // r21
  __int16 v25; // r19
  int v26; // r20
  __int16 v27; // r18
  __int16 v28; // r17
  signed int v29; // r8
  unsigned int v30; // r21
  signed int v31; // r16
  unsigned int v32; // r8
  signed int v33; // r8
  int v34; // r9
  unsigned int v35; // r20
  int v36; // r21
  signed int v37; // r19
  unsigned int v38; // r8
  signed int v39; // r8
  unsigned int v40; // r20
  signed int v41; // r19
  int v42; // r9
  unsigned int v43; // r7
  signed int v44; // r8
  unsigned int v45; // r20
  signed int v46; // r19
  int v47; // r9
  unsigned int v48; // r7
  signed int v49; // r7
  unsigned int v50; // r6
  __int16 *v51; // r10
  __int16 **j; // r5
  __int16 *v53; // r11
  __int16 *v54; // r8
  const int *v55; // r9
  int k; // ctr

  numChannels = codec->codecParms.numChannels;
  colorFormat = codec->codecParms.colorFormat;
  v3 = 0;
  if ( numChannels != 0 )
  {
    pQuantizerHP = codec->tileQuantization[codec->currentTileColumn].pQuantizerHP;
    macroBlockPrevColumnPtr = codec->macroBlockPrevColumnPtr;
    while ( v3 != 0 && (colorFormat == CF_YUV_444 || colorFormat == CF_YUV_422 || colorFormat == CF_YUV_420) )
    {
      if ( colorFormat == CF_YUV_422 )
      {
        v7 = 8;
        v8 = blkOffsetUV_422;
      }
      else
      {
        if ( colorFormat != CF_YUV_420 )
          break;
        v7 = 4;
        v8 = blkOffsetUV_420;
      }
LABEL_15:
      v9 = 0;
      v10 = (int *)((char *)&(*(pQuantizerHP - 16))->iQP + __ROL4__(codec->MBInfo.quantizerIndexLP, 4));
      v11 = (signed int *)*(pQuantizerHP - 32);
      v12 = (unsigned int *)((char *)*pQuantizerHP + __ROL4__(codec->MBInfo.quantizerIndexHP, 4));
      v13 = 0;
      do
      {
        v14 = &(*macroBlockPrevColumnPtr)[v8[v13]];
        if ( v9 != 0 )
        {
          if ( codec->codecParms.subBands >= SB_NO_LOWPASS )
            goto LABEL_21;
          v15 = v10[1];
          v16 = *v10;
        }
        else
        {
          v15 = v11[1];
          v16 = *v11;
        }
        v17 = *v14;
        __twllei(v16, 0);
        v18 = v17;
        v19 = v17 >> 15;
        v20 = (v18 ^ v19) + v15 - v19;
        *v14 = ((v20 / v16) ^ v19) - v19;
        __twlgei(v16 & ~(__ROL4__(v20, 1) - 1), 0xFFFFFFFF);
LABEL_21:
        if ( codec->codecParms.subBands < SB_NO_HIGHPASS )
        {
          for ( i = 3; i != 0; --i )
          {
            v22 = v12[1];
            v23 = v14[1];
            v24 = *v12;
            v25 = v14[3];
            v26 = v14[2];
            v27 = v14[4];
            v28 = v14[5];
            __twllei(*v12, 0);
            v29 = ((v23 >> 15) ^ v23) - (v23 >> 15) + v22;
            v14[1] = ((v29 / v24) ^ (v23 >> 15)) - (v23 >> 15);
            v30 = v24 & ~(__ROL4__(v29, 1) - 1);
            v31 = *v12;
            v32 = v12[1];
            __twlgei(v30, 0xFFFFFFFF);
            v33 = ((v26 >> 15) ^ v26) - (v26 >> 15) + v32;
            v34 = v25 >> 15;
            v14[2] = ((v33 / v31) ^ (v26 >> 15)) - (v26 >> 15);
            v35 = v31 & ~(__ROL4__(v33, 1) - 1);
            v36 = v34 ^ v25;
            v37 = *v12;
            v38 = v12[1];
            __twlgei(v35, 0xFFFFFFFF);
            __twllei(v31, 0);
            v39 = v36 - v34 + v38;
            v40 = v37 & ~(__ROL4__(v39, 1) - 1);
            v14[3] = ((v39 / v37) ^ v34) - v34;
            __twllei(v37, 0);
            v41 = *v12;
            v42 = v27 >> 15;
            v43 = v12[1];
            __twlgei(v40, 0xFFFFFFFF);
            v44 = (v42 ^ v27) - v42 + v43;
            v45 = v41 & ~(__ROL4__(v44, 1) - 1);
            v14[4] = ((v44 / v41) ^ v42) - v42;
            __twllei(v41, 0);
            v46 = *v12;
            v47 = v28 >> 15;
            v48 = v12[1];
            __twlgei(v45, 0xFFFFFFFF);
            v49 = (v47 ^ v28) - v47 + v48;
            __twllei(v46, 0);
            __twlgei(v46 & ~(__ROL4__(v49, 1) - 1), 0xFFFFFFFF);
            v14 += 5;
            *v14 = ((v49 / v46) ^ v47) - v47;
          }
        }
        v13 = ++v9;
      }
      while ( v9 < v7 );
      ++v3;
      ++pQuantizerHP;
      ++macroBlockPrevColumnPtr;
      if ( v3 >= numChannels )
        goto LABEL_26;
    }
    v7 = 16;
    v8 = blkOffset;
    goto LABEL_15;
  }
LABEL_26:
  v50 = 0;
  if ( numChannels != 0 )
  {
    v51 = &codec->MBInfo.compactDCLP[0][5];
    for ( j = codec->macroBlockPrevColumnPtr; ; ++j )
    {
      v53 = *j;
      if ( v50 == 0 )
        break;
      if ( colorFormat == CF_YUV_422 )
      {
        *(v51 - 5) = *v53;
        *(v51 - 4) = v53[64];
        *(v51 - 3) = v53[16];
        *(v51 - 2) = v53[80];
        *(v51 - 1) = v53[32];
        *v51 = v53[96];
        v51[1] = v53[48];
        v51[2] = v53[112];
      }
      else
      {
        if ( colorFormat != CF_YUV_420 )
          break;
        *(v51 - 5) = *v53;
        *(v51 - 4) = v53[32];
        *(v51 - 3) = v53[16];
        *(v51 - 2) = v53[48];
      }
LABEL_35:
      ++v50;
      v51 += 16;
      if ( v50 >= numChannels )
        return HDP_ERROR_NONE;
    }
    v54 = v51 - 6;
    v55 = &blkOffsetUV_420[3];
    for ( k = 4; k != 0; --k )
    {
      v54[1] = v53[v55[1]];
      v54[2] = v53[v55[2]];
      v54[3] = v53[v55[3]];
      v55 += 4;
      v54 += 4;
      *v54 = v53[*v55];
    }
    goto LABEL_35;
  }
  return HDP_ERROR_NONE;
}

