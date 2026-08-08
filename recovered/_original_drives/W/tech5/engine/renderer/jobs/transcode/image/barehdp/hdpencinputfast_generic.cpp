
// ========================================================================
// InputMBRowFast
// EA  : 0x828F89D0
// RVA : 0x008F89D0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpencinputfast_generic.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall InputMBRowFast(hdpCodec_t *codec)
{
  unsigned int imageWidth; // r15
  char *buffer; // r16
  unsigned int v4; // r18
  char v5; // r31
  __int16 v6; // r30
  __int16 *v7; // r4
  unsigned int k; // r6
  int v9; // r11
  unsigned int v10; // ctr
  char *v11; // r10
  unsigned int v12; // r7
  int v13; // r9
  __int16 *v15; // r29
  unsigned int m; // r4
  int v17; // r10
  char *v18; // r11
  unsigned int n; // ctr
  unsigned int v20; // r27
  unsigned int v21; // r8
  int v22; // r9
  __int16 *v23; // r3
  __int16 *v24; // r29
  unsigned int v25; // r4
  __int16 *v26; // r28
  int v27; // r10
  char *v28; // r11
  unsigned int nn; // ctr
  unsigned int v30; // r5
  int v31; // r6
  __int16 v32; // r26
  unsigned int v33; // r7
  __int16 v34; // r25
  int v35; // r8
  int v36; // r7
  int v37; // r6
  int v38; // r5
  __int16 *v39; // r6
  __int16 *v40; // r5
  unsigned int v41; // r7
  __int16 *v42; // r4
  int v43; // r10
  char *v44; // r11
  unsigned int ii; // ctr
  unsigned int v46; // r9
  __int16 v47; // r8
  __int16 *v48; // r6
  __int16 *v49; // r5
  unsigned int jj; // r7
  int v51; // r11
  char *v52; // r10
  unsigned int kk; // ctr
  unsigned int v54; // r3
  int v55; // r8
  unsigned int v56; // r22
  int v57; // r21
  int v58; // r20
  int v59; // r19
  int v60; // r29
  int v61; // r28
  int v62; // r27
  int v63; // r26
  int v64; // r25
  int v65; // r24
  unsigned int mm; // r4
  unsigned int v67; // r5
  unsigned __int8 *v68; // r11
  __int16 v69; // r15
  __int16 v70; // r14
  __int16 v71; // r7
  unsigned int v72; // r10
  int v73; // r15
  __int16 v74; // r9
  __int16 v75; // r7
  __int64 v76; // r9 OVERLAPPED
  int v77; // r7
  __int16 v78; // r6
  double v79; // fp4
  double v80; // fp3
  int v81; // r7
  int v82; // r9
  int *v83; // r8
  unsigned int v84; // ctr
  int v85; // r6
  unsigned int numChannels; // r29
  unsigned int i; // r5
  unsigned int v88; // r7
  char *j; // r6
  int v90; // r11
  unsigned int v91; // ctr
  unsigned int v92; // r8
  _DWORD *v93; // r10
  int v94; // r3
  unsigned int v95; // [sp+58h] [-F8h]
  __int64 v96; // [sp+68h] [-E8h] BYREF
  _DWORD v97[8]; // [sp+70h] [-E0h] BYREF
  int v98; // [sp+90h] [-C0h] BYREF

  imageWidth = codec->imageInfo.imageWidth;
  buffer = (char *)codec->imageBufferInfo.buffer;
  v4 = codec->imageInfo.bitsPerUnit >> 3;
  v95 = imageWidth;
  v5 = !codec->codecParms.useScaledArith ? 0 : 3;
  v6 = 128 << v5;
  if ( (unsigned int)(codec->imageInfo.colorFormat - 6) > 8 )
    return 0;
  if ( codec->imageInfo.colorFormat == CF_N_CHANNEL )
  {
    numChannels = codec->codecParms.numChannels;
    if ( numChannels != 0 )
      blkmov(a1: v97, a2: codec->macroBlockColumnPtr1, a3: 4 * numChannels);
    for ( i = 0; i < 0x100; i += 16 )
    {
      v88 = 0;
      for ( j = &buffer[codec->imageInfo.leadingPadding]; v88 < imageWidth; j += v4 )
      {
        v90 = 0;
        if ( numChannels != 0 )
        {
          v91 = numChannels;
          v92 = 2 * ((unsigned __int8)idxCC[0][(v88 & 0xF) + i] + ((16 * v88) & 0xFFFFFF00));
          v93 = (_DWORD *)&v96 + 1;
          do
          {
            v94 = (unsigned __int8)j[v90];
            ++v93;
            ++v90;
            *(_WORD *)(v92 + *v93) = (v94 << v5) - v6;
            --v91;
          }
          while ( v91 != 0 );
        }
        ++v88;
      }
      buffer += codec->imageBufferInfo.byteStride;
    }
    return 0;
  }
  if ( codec->imageInfo.colorFormat != CF_RGB )
  {
    if ( codec->imageInfo.colorFormat != CF_RGBE && codec->imageInfo.colorFormat != CF_PALLETIZED )
    {
      switch ( codec->imageInfo.colorFormat )
      {
        case CF_MONO:
          v7 = codec->macroBlockColumnPtr1[0];
          for ( k = 0; k < 0x100; k += 16 )
          {
            v9 = 0;
            if ( imageWidth != 0 )
            {
              v10 = imageWidth;
              v11 = &buffer[codec->imageInfo.leadingPadding - v4];
              do
              {
                v11 += v4;
                v12 = (16 * v9) & 0xFFFFFF00;
                v13 = idxCC[0][(v9++ & 0xF) + k];
                v7[v13 + v12] = ((unsigned __int8)*v11 << v5) - v6;
                --v10;
              }
              while ( v10 != 0 );
            }
            buffer += codec->imageBufferInfo.byteStride;
          }
          return 0;
        case CF_GRAYSCALE:
          v15 = codec->macroBlockColumnPtr1[0];
          for ( m = 0; m < 0x100; m += 16 )
          {
            v17 = 0;
            v18 = &buffer[codec->imageInfo.leadingPadding];
            if ( imageWidth != 0 )
            {
              for ( n = imageWidth; n != 0; --n )
              {
                v20 = (v17 & 0xF) + m;
                v21 = (16 * v17++) & 0xFFFFFF00;
                v22 = 2 * ((unsigned __int8)v18[2] + (unsigned __int8)v18[1] + (unsigned __int8)*v18);
                v18 += v4;
                v15[(unsigned __int8)idxCC[0][v20] + v21] = (((v22 + 3) / 6) << v5) - v6;
              }
            }
            buffer += codec->imageBufferInfo.byteStride;
          }
          return 0;
        case CF_COCG_Y:
          v39 = codec->macroBlockColumnPtr1[0];
          v40 = codec->macroBlockColumnPtr1[1];
          v41 = 0;
          v42 = codec->macroBlockColumnPtr1[2];
          do
          {
            v43 = 0;
            v44 = &buffer[codec->imageInfo.leadingPadding];
            if ( imageWidth != 0 )
            {
              for ( ii = imageWidth; ii != 0; --ii )
              {
                v46 = (unsigned __int8)idxCC[0][(v43 & 0xF) + v41] + ((16 * v43) & 0xFFFFFF00);
                ++v43;
                v39[v46] = ((unsigned __int8)v44[3] << v5) - v6;
                v40[v46] = ((unsigned __int8)*v44 << v5) - v6;
                v47 = ((unsigned __int8)v44[1] << v5) - v6;
                v44 += v4;
                v42[v46] = v47;
              }
            }
            v41 += 16;
            buffer += codec->imageBufferInfo.byteStride;
          }
          while ( v41 < 0x100 );
          return 0;
        case CF_NORMAL_Y_X:
          v48 = codec->macroBlockColumnPtr1[0];
          v49 = codec->macroBlockColumnPtr1[1];
          for ( jj = 0; jj < 0x100; jj += 16 )
          {
            v51 = 0;
            if ( imageWidth != 0 )
            {
              v52 = &buffer[codec->imageInfo.leadingPadding + 1];
              for ( kk = imageWidth; kk != 0; --kk )
              {
                v54 = (unsigned __int8)idxCC[0][(v51 & 0xF) + jj] + ((16 * v51) & 0xFFFFFF00);
                ++v51;
                v48[v54] = ((unsigned __int8)v52[2] << v5) - v6;
                v55 = ((unsigned __int8)*v52 << v5) - v6;
                v52 += v4;
                v49[v54] = v55;
              }
            }
            buffer += codec->imageBufferInfo.byteStride;
          }
          return 0;
        default:
          v56 = codec->codecParms.numChannels;
          if ( v56 != 0 )
            blkmov(a1: v97, a2: codec->macroBlockColumnPtr1, a3: 4 * v56);
          v57 = v98;
          v58 = v97[7];
          v59 = v97[6];
          v60 = v97[5];
          v61 = v97[4];
          v62 = v97[3];
          v63 = v97[2];
          v64 = v97[1];
          v65 = v97[0];
          for ( mm = 0; mm < 0x100; mm += 16 )
          {
            v67 = 0;
            v68 = (unsigned __int8 *)&buffer[codec->imageInfo.leadingPadding];
            if ( imageWidth != 0 )
            {
              do
              {
                v69 = *v68 << v5;
                v70 = (v68[2] << v5) - v69;
                v71 = ((v70 + 1) >> 1) - (v68[1] << v5) + v69;
                v72 = 2 * ((unsigned __int8)idxCC[0][(v67 & 0xF) + mm] + ((16 * v67) & 0xFFFFFF00));
                *(_WORD *)(v72 + v65) = (v71 >> 1) - v6 + (v68[1] << v5);
                *(_WORD *)(v72 + v64) = -v71;
                *(_WORD *)(v72 + v63) = v70;
                v73 = (__int16)((v68[5] << v5) - (v68[3] << v5));
                v74 = v68[4] << v5;
                v75 = ((v73 + 1) >> 1) - v74 + (v68[3] << v5);
                *(_WORD *)(v72 + v62) = (v75 >> 1) - v6 + v74;
                *(_WORD *)(v72 + v61) = -v75;
                *(_WORD *)(v72 + v60) = v73;
                LODWORD(v76) = v68[7];
                HIDWORD(v76) = v68[6];
                v77 = HIDWORD(v76);
                LODWORD(v96) = v76;
                v78 = v68[8];
                v79 = (float)((float)((float)*(__int64 *)((char *)&v76 + 4) * (float)0.0078431377) - (float)1.0);
                v80 = (float)((float)((float)v76 * (float)0.0078431377) - (float)1.0);
                v81 = (int)(float)((float)((float)((float)__fsqrts(__fabs((float)-(float)((float)((float)v80 * (float)v80)
                                                                                        - (float)-(float)((float)((float)v79 * (float)v79) - (float)1.0))))
                                                 + (float)1.0)
                                         * (float)127.5)
                                 + (float)0.5);
                if ( v81 >= 0 )
                {
                  if ( v81 > 255 )
                    LOBYTE(v81) = -1;
                }
                else
                {
                  LOBYTE(v81) = 0;
                }
                *(_WORD *)(v72 + v59) = WORD1(v76) - v6 - v76;
                *(_WORD *)(v72 + v58) = v76 - v6;
                v82 = 9;
                *(_WORD *)(v72 + v57) = v78 - (unsigned __int8)v81;
                if ( v56 > 9 )
                {
                  v83 = &v98;
                  v84 = v56 - 9;
                  do
                  {
                    v85 = v68[v82];
                    ++v83;
                    ++v82;
                    *(_WORD *)(v72 + *v83) = (v85 << v5) - v6;
                    --v84;
                  }
                  while ( v84 != 0 );
                }
                imageWidth = v95;
                ++v67;
                v68 += v4;
              }
              while ( v67 < v95 );
            }
            buffer += codec->imageBufferInfo.byteStride;
          }
          return 0;
      }
    }
    return 0;
  }
  v23 = codec->macroBlockColumnPtr1[0];
  v24 = codec->macroBlockColumnPtr1[1];
  v25 = 0;
  v26 = codec->macroBlockColumnPtr1[2];
  do
  {
    v27 = 0;
    v28 = &buffer[codec->imageInfo.leadingPadding];
    if ( imageWidth != 0 )
    {
      for ( nn = imageWidth; nn != 0; --nn )
      {
        v30 = (16 * v27) & 0xFFFFFF00;
        v31 = (unsigned __int8)*v28 << v5;
        v32 = ((unsigned __int8)v28[2] << v5) - v31;
        v33 = (v27 & 0xF) + v25;
        v34 = (unsigned __int8)v28[1] << v5;
        ++v27;
        v28 += v4;
        LOWORD(v31) = ((v32 + 1) >> 1) - v34 + v31;
        v35 = (unsigned __int8)idxCC[0][v33] + v30;
        v36 = (__int16)v31 >> 1;
        v38 = -(__int16)v31;
        v37 = v35;
        v23[v37] = v36 - v6 + v34;
        v24[v37] = v38;
        v26[v37] = v32;
      }
    }
    v25 += 16;
    buffer += codec->imageBufferInfo.byteStride;
  }
  while ( v25 < 0x100 );
  return 0;
}


// ========================================================================
// ?HDPEncInputMBRowFast_Generic@@YA?AW4hdpError_t@@PAUhdpCodec_t@@PBUhdpImageBufferInfo_t@@@Z
// EA  : 0x828F90F8
// RVA : 0x008F90F8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpencinputfast_generic.cpp
// ========================================================================

hdpError_t __fastcall HDPEncInputMBRowFast_Generic(hdpCodec_t *codec, const hdpImageBufferInfo_t *bufferInfo)
{
  hdpCodec_t *nextCodec; // r11

  nextCodec = codec->nextCodec;
  codec->imageBufferInfo = *bufferInfo;
  if ( nextCodec != nullptr )
    nextCodec->imageBufferInfo = *bufferInfo;
  codec->currentMacroblockColumn = 0;
  InitMacroblockColumnPtrs(firstCodec: codec);
  InputMBRowFast(codec);
  return HDP_ERROR_NONE;
}

