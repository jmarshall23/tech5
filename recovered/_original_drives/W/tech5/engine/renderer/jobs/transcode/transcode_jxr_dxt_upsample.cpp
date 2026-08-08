
// ========================================================================
// ?TranscodePage_JXR_DXT_upsample@@YAXABUtranscodeParms_t@@@Z
// EA  : 0x82938240
// RVA : 0x00938240
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_jxr_dxt_upsample.cpp
// ========================================================================

void __fastcall TranscodePage_JXR_DXT_upsample(const transcodeParms_t *parms)
{
  int imageFlags; // r11
  const transcodeParms_t *v2; // r25
  int v3; // r3
  int v4; // r12
  unsigned __int8 *tempData; // r21
  unsigned int v6; // r4
  unsigned int v7; // r14
  unsigned __int8 *v8; // r18
  unsigned __int8 *v9; // r3
  unsigned __int8 *v10; // r10
  int v11; // r8
  const unsigned __int8 *inPageData; // r20
  int upsampleLevel; // r9
  char *v14; // r30
  const unsigned __int8 *inPageHeader; // r15
  int v16; // r11
  int v17; // r10
  int v18; // r10
  int v19; // r8
  int v20; // r6
  unsigned int v21; // r23
  unsigned int v22; // r22
  int v23; // r26
  char v24; // r11
  unsigned __int8 v25; // r24
  int v26; // r29
  unsigned __int8 v27; // r16
  int v28; // r9
  int v29; // r28
  int v30; // r27
  unsigned int v31; // r26
  int v32; // r19
  char *v33; // r22
  int v34; // r11
  unsigned int v35; // r23
  const unsigned __int8 *v36; // r20
  int v37; // r26
  int v38; // r21
  unsigned int v39; // r17
  unsigned int v40; // r18
  int v41; // r11
  int v42; // r27
  int v43; // r24
  unsigned int v44; // r29
  unsigned __int8 *v45; // r28
  unsigned int v46; // r29
  int v47; // r27
  int v48; // r10
  int v49; // r9
  int v50; // r8
  unsigned __int8 *v51; // r3
  unsigned __int8 *v52; // r5
  int v53; // r16
  int v54; // r29
  int v55; // r9
  int pageLevel; // r3
  unsigned int v57; // r26
  unsigned int v58; // r17
  int v59; // r24
  int v60; // r23
  unsigned int v61; // r18
  int upsampleSharpen; // r22
  int v63; // r21
  int v64; // r11
  int v65; // r20
  int v66; // r19
  unsigned int v67; // r29
  unsigned __int8 *v68; // r28
  unsigned int v69; // r28
  unsigned int v70; // r29
  int v71; // r20
  int v72; // r28
  int v73; // r27
  int v74; // r8
  int v75; // r29
  unsigned int v76; // r28
  int v77; // r3
  int v78; // r24
  unsigned int v79; // r10
  unsigned int v80; // r11
  unsigned int v81; // r26
  unsigned int v82; // r23
  int v83; // r9
  unsigned __int8 *v84; // r22
  int v85; // r21
  int v86; // r20
  unsigned int v87; // r28
  unsigned __int8 *v88; // r27
  unsigned int v89; // r9
  unsigned __int8 *v90; // r11
  int i; // ctr
  int v92; // r10
  unsigned __int8 *v93; // r10
  unsigned __int8 v94; // r7
  unsigned __int8 v95; // r6
  unsigned __int8 v96; // r5
  unsigned __int8 v97; // r4
  unsigned int v98; // r28
  unsigned int v99; // r29
  unsigned __int8 *v100; // r11
  unsigned __int8 *v101; // r10
  unsigned __int8 *v102; // r9
  unsigned __int8 *v103; // r8
  char v104; // r24
  unsigned __int8 *v105; // r5
  char v106; // r23
  char v107; // r22
  char v108; // r21
  char v109; // r20
  char v110; // r25
  char v111; // r19
  char v112; // r18
  char v113; // r17
  char v114; // r16
  char v115; // r15
  char v116; // r14
  _DWORD back_chain[2]; // [sp+0h] [-1F0h]
  int v118; // [sp+8h] [-1E8h]
  int v119; // [sp+Ch] [-1E4h]
  int v120; // [sp+10h] [-1E0h]
  int v121; // [sp+14h] [-1DCh]
  int v122; // [sp+18h] [-1D8h]
  unsigned int v123; // [sp+1Ch] [-1D4h]
  int v124; // [sp+20h] [-1D0h]
  unsigned int v125; // [sp+24h] [-1CCh]
  int v126; // [sp+28h] [-1C8h]
  unsigned int v127; // [sp+2Ch] [-1C4h]
  int v128; // [sp+30h] [-1C0h]
  int v129; // [sp+34h] [-1BCh]
  int v130; // [sp+38h] [-1B8h]
  unsigned int v131; // [sp+3Ch] [-1B4h]
  int v132; // [sp+40h] [-1B0h]
  unsigned int v133; // [sp+44h] [-1ACh]
  int v134; // [sp+48h] [-1A8h]
  int v135; // [sp+4Ch] [-1A4h]
  int v136; // [sp+50h] [-1A0h]
  int v137; // [sp+58h] [-198h]
  int v138; // [sp+60h] [-190h]
  const unsigned __int8 *v139; // [sp+70h] [-180h]
  unsigned __int8 *v140; // [sp+74h] [-17Ch]
  unsigned __int8 *v141; // [sp+78h] [-178h]
  unsigned int v142; // [sp+7Ch] [-174h]
  int v143; // [sp+80h] [-170h]
  unsigned int v144; // [sp+84h] [-16Ch]
  int v145; // [sp+88h] [-168h]
  unsigned int v146; // [sp+8Ch] [-164h]
  int v147; // [sp+90h] [-160h]
  unsigned int v148; // [sp+94h] [-15Ch]
  int v149; // [sp+98h] [-158h]
  unsigned __int8 *v150; // [sp+9Ch] [-154h]
  idBareJXR v151; // [sp+A0h] [-150h] BYREF
  idBareJXR v152; // [sp+C0h] [-130h] BYREF
  idBareJXR v153; // [sp+E0h] [-110h] BYREF
  idDxtEncoder v154; // [sp+100h] [-F0h] BYREF
  idDxtEncoder v155; // [sp+120h] [-D0h] BYREF
  idDxtEncoder v156; // [sp+140h] [-B0h] BYREF

  imageFlags = parms->imageFlags;
  v2 = parms;
  parms->startedExecution = true;
  if ( imageFlags != 0 )
  {
    if ( parms->tempData == nullptr )
    {
      v3 = ((int (*)(void))RtlCheckStack12)();
      *(_DWORD *)((char *)back_chain + v4) = back_chain[0];
      *(_DWORD *)(v3 + 108) = ((unsigned int)&v153.tempBufferUsed + 3) & 0xFFFFFF80;
    }
    __asm { dcbz128   0, r11 }
    __asm { dcbz128   r10, r9 }
    __asm { dcbz128   r8, r7 }
    __asm { dcbz128   r6, r5 }
    __asm { dcbz128   r4, r3 }
    __asm { dcbz128   r11, r10 }
    __asm { dcbz128   r9, r8 }
    __asm { dcbz128   r7, r6 }
    tempData = v2->tempData;
    v6 = 0;
    v7 = 0;
    v8 = tempData + 0x20000;
    v9 = v2->targetImage[1];
    v10 = v2->targetImage[2];
    v11 = 0;
    inPageData = v2->inPageData;
    upsampleLevel = v2->upsampleLevel;
    v14 = (char *)(tempData + 133120);
    inPageHeader = v2->inPageHeader;
    v16 = 1;
    v141 = v2->targetImage[0];
    v143 = (int)tempData;
    v146 = 0;
    v140 = tempData + 0x20000;
    v147 = (int)v9;
    v150 = v10;
    v144 = 0;
    v139 = inPageData;
    if ( upsampleLevel > 0 )
    {
      do
      {
        v17 = 124 * v16;
        if ( (v2->upsampleX & v16) == 0 )
          v17 = 4 * v16;
        v6 += v17;
        v18 = 124 * v16;
        if ( (v2->upsampleY & v16) == 0 )
          v18 = 4 * v16;
        ++v11;
        v7 += v18;
        v16 *= 2;
      }
      while ( v11 < upsampleLevel );
      v144 = v7;
      v146 = v6;
    }
    v19 = v2->imageFlags;
    v20 = v2->imageFlags & 1;
    v21 = ((v6 >> upsampleLevel == 4) + (((v6 >> upsampleLevel) - 4) >> 31) - 1) & ((v6 >> upsampleLevel) - 4);
    v22 = ((v7 >> upsampleLevel == 4) + (((v7 >> upsampleLevel) - 4) >> 31) - 1) & ((v7 >> upsampleLevel) - 4);
    v23 = (128 >> upsampleLevel) + 8;
    v148 = v21;
    v142 = v22;
    v145 = v23;
    if ( v20 == 0 || (v19 & 4) == 0 || (v24 = 1, (inPageHeader[4] & 3) == 2) )
      v24 = 0;
    v25 = v24;
    if ( v20 != 0 )
    {
      v26 = 4 << upsampleLevel;
      v149 = v2->targetBytePitch[0];
      idBareJXR::idBareJXR(this: &v151);
      v27 = inPageHeader[4];
      v28 = inPageHeader[2];
      v151.tempBuffer = tempData;
      v151.tempBufferSize = 0x20000;
      v151.cROILeftX = v21;
      v151.cROITopY = v22;
      v151.quality = v28;
      v151.cROIWidth = v23;
      v151.cROIHeight = v23;
      v29 = *((unsigned __int16 *)inPageHeader + 4);
      v30 = *((unsigned __int16 *)inPageHeader + 3);
      v31 = *((unsigned __int16 *)inPageHeader + 5);
      idBareJXR::BeginDecompressImageRGB(
        this: &v151,
        inBuf: &inPageData[v30 + v29],
        width: 128,
        height: 128,
        inputBytes: v31);
      v32 = 0;
      v33 = (char *)(tempData + 134144);
      v34 = *((unsigned __int16 *)inPageHeader + 6) + v30;
      v154.srcPadding = 0;
      v35 = 0;
      v36 = &v139[v34 + v29 + v31];
      v154.dstPadding = v149 - 32;
      v37 = -1;
      v38 = v25;
      v39 = (int)(v26 + v144) / 16 + 1;
      v40 = (int)(v144 - v26) / 16;
      do
      {
        v41 = v2->upsampleLevel;
        v42 = (v39 >> v41) & 7;
        v43 = (v40 >> v41) & 7;
        while ( v37 < v42 )
        {
          idBareJXR::BeginDecompressImageGrayScaleMacroBlockRow(this: &v151);
          if ( ++v37 >= v43 )
          {
            v44 = 0;
            v45 = (unsigned __int8 *)&v33[(v37 << 13) & 0x2000];
            do
            {
              if ( (v27 & 4) != 0 )
                idBareJXR::DecompressImageGrayScaleMacroBlock(this: &v151, outBuf: v45, blockNum: v44, byteStride: 512);
              else
                idBareJXR::DecompressImageRGBMacroBlock(this: &v151, outBuf: v45, blockNum: v44, byteStride: 512);
              if ( (v27 & 8) != 0 )
                DecompressCover16x16_4(cover: v36, tileX: v44, tileY: v37, rgba: v45, byteStride: 512);
              ++v44;
              v45 += 64;
            }
            while ( v44 < 8 );
          }
        }
        v46 = 0;
        v47 = 0;
        do
        {
          UpSample16x16_Bicubic_3(
            dst: (unsigned __int8 *)v14,
            dstX: 16 * v46,
            dstY: 16 * v35,
            dstBytePitch: 0x40u,
            src: (const unsigned __int8 *)v14 + 1024,
            srcX: v146,
            srcY: v144,
            srcMaskY: 0x1Fu,
            upsampleLevel: v118,
            sharpenScale: v119,
            noiseScale: v120,
            a12: v121,
            a13: v122,
            a14: v123,
            a15: v124,
            a16: v125,
            a17: v126,
            a18: v127,
            a19: v128,
            a20: v129,
            a21: v130,
            a22: v131,
            a23: v132,
            a24: v133,
            a25: v134,
            a26: v135,
            a27: v136,
            a28: v2->upsampleLevel,
            a29: v137,
            a30: 0,
            a31: v138,
            a32: 0);
          v51 = v140 + 1024;
          if ( v38 != 0 )
            DynamicScaleSpecular16x16_4(specularScale: v51, tileX: v46, tileY: v35, rgba: (unsigned __int8 *)v14);
          else
            ConstantScaleSpecular16x16_4(
              specularScale: v51,
              tileX: v46,
              tileY: v35,
              rgba: (unsigned __int8 *)v14,
              specularShift: v27 & 3,
              a6: v50,
              a7: v49,
              a8: v48,
              a9: v118,
              a10: v119,
              a11: v120,
              a12: v121,
              a13: v122,
              a14: v123,
              a15: v124,
              a16: v125,
              a17: v126,
              a18: v127,
              a19: v128,
              a20: v129);
          v52 = &v141[4 * v32 + 4 * v47];
          if ( (v27 & 8) != 0 )
            idDxtEncoder::CompressImageDXT1AlphaFast_Xenon(
              this: &v154,
              inBuf: (const unsigned __int8 *)v14,
              outBuf: v52,
              width: 16,
              height: 16);
          else
            idDxtEncoder::CompressImageDXT1Fast_Xenon(
              this: &v154,
              inBuf: (const unsigned __int8 *)v14,
              outBuf: v52,
              width: 16,
              height: 16);
          ++v46;
          v47 += 8;
        }
        while ( v46 < 8 );
        ++v35;
        ++v40;
        ++v39;
        v32 += v149;
      }
      while ( v35 < 8 );
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v151);
      v7 = v144;
      inPageData = v139;
      v8 = v140;
      tempData = (unsigned __int8 *)v143;
      v21 = v148;
      v22 = v142;
      v23 = v145;
    }
    if ( (v2->imageFlags & 2) != 0 )
    {
      v53 = v2->targetBytePitch[1];
      v54 = 4 << v2->upsampleLevel;
      idBareJXR::idBareJXR(this: &v153);
      v55 = *inPageHeader;
      v153.tempBuffer = tempData;
      v153.cROILeftX = v21;
      v153.tempBufferSize = 0x20000;
      v153.cROITopY = v22;
      v153.quality = v55;
      v153.cROIWidth = v23;
      v153.cROIHeight = v23;
      idBareJXR::BeginDecompressImageRGB(
        this: &v153,
        inBuf: inPageData,
        width: 128,
        height: 128,
        inputBytes: *((unsigned __int16 *)inPageHeader + 3));
      pageLevel = v2->pageLevel;
      v57 = 0;
      v58 = (int)(v54 + v7) / 16 + 1;
      v155.srcPadding = 0;
      v59 = 0;
      v155.dstPadding = v53 - 64;
      v60 = -1;
      v61 = (int)(v7 - v54) / 16;
      upsampleSharpen = v2->upsampleSharpen;
      v63 = v2->upsampleNoise >> pageLevel;
      do
      {
        v64 = v2->upsampleLevel;
        v65 = (v58 >> v64) & 7;
        v66 = (v61 >> v64) & 7;
        while ( v60 < v65 )
        {
          idBareJXR::BeginDecompressImageGrayScaleMacroBlockRow(this: &v153);
          if ( ++v60 >= v66 )
          {
            v67 = 0;
            v68 = (unsigned __int8 *)&v14[((v60 << 13) & 0x2000) + 1024];
            do
            {
              idBareJXR::DecompressImageYCoCgMacroBlock(this: &v153, outBuf: v68, blockNum: v67++, byteStride: 512);
              v68 += 64;
            }
            while ( v67 < 8 );
          }
        }
        v69 = v146;
        v70 = 0;
        v71 = v147;
        do
        {
          UpSample16x16_Bicubic_3(
            dst: (unsigned __int8 *)v14,
            dstX: v70,
            dstY: v57,
            dstBytePitch: 0x40u,
            src: (const unsigned __int8 *)v14 + 1024,
            srcX: v69,
            srcY: v7,
            srcMaskY: 0x1Fu,
            upsampleLevel: v118,
            sharpenScale: v119,
            noiseScale: v120,
            a12: v121,
            a13: v122,
            a14: v123,
            a15: v124,
            a16: v125,
            a17: v126,
            a18: v127,
            a19: v128,
            a20: v129,
            a21: v130,
            a22: v131,
            a23: v132,
            a24: v133,
            a25: v134,
            a26: v135,
            a27: v136,
            a28: v2->upsampleLevel,
            a29: v137,
            a30: upsampleSharpen,
            a31: v138,
            a32: v63);
          idDxtEncoder::CompressYCoCgDXT5Fast_Xenon(
            this: &v155,
            inBuf: (const unsigned __int8 *)v14,
            outBuf: (unsigned __int8 *)(4 * (v59 + v70) + v71),
            width: 16,
            height: 16);
          v70 += 16;
        }
        while ( v70 < 0x80 );
        v57 += 16;
        ++v61;
        ++v58;
        v59 += v53;
      }
      while ( v57 < 0x80 );
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v153);
      inPageData = v139;
      v8 = v140;
      tempData = (unsigned __int8 *)v143;
      v21 = v148;
      v22 = v142;
      v23 = v145;
    }
    if ( (v2->imageFlags & 4) != 0 )
    {
      if ( (v2->imageFlags & 1) == 0 )
        memset(Dst: v8 + 1024, Val: 8 * (1 << (inPageHeader[4] & 3)) - 8, Size: 0x400u);
      v73 = 4 << v2->upsampleLevel;
      v147 = v2->targetBytePitch[2];
      v72 = v147;
      idBareJXR::idBareJXR(this: &v152);
      v74 = inPageHeader[3];
      v152.tempBuffer = tempData;
      v156.dstPadding = v72 - 64;
      v152.tempBufferSize = 0x20000;
      v156.srcPadding = 0;
      v152.quality = v74;
      v75 = *((unsigned __int16 *)inPageHeader + 3);
      v76 = *((unsigned __int16 *)inPageHeader + 4);
      idBareJXR::DecompressImageMono(
        this: &v152,
        inBuf: &inPageData[*((unsigned __int16 *)inPageHeader + 5) + v75 + v76],
        outBuf: v8,
        width: 32,
        height: 32,
        inputBytes: *((unsigned __int16 *)inPageHeader + 6),
        mipLevel: 0);
      v77 = inPageHeader[1];
      v152.cROILeftX = v21;
      v152.cROITopY = v22;
      v152.cROIWidth = v23;
      v152.cROIHeight = v23;
      v152.quality = v77;
      idBareJXR::BeginDecompressImageRGB(this: &v152, inBuf: &inPageData[v75], width: 128, height: 128, inputBytes: v76);
      v141 = nullptr;
      v139 = nullptr;
      v78 = -1;
      v143 = -1;
      v79 = (int)(v73 + v7) / 16 + 1;
      v80 = (int)(v7 - v73) / 16;
      v81 = 0;
      v142 = v79;
      v82 = 0;
      v145 = v80;
      while ( 1 )
      {
        v83 = v2->upsampleLevel;
        v84 = v140;
        v85 = (v79 >> v83) & 7;
        v86 = (v80 >> v83) & 7;
        if ( v78 < v85 )
        {
          do
          {
            idBareJXR::BeginDecompressImageGrayScaleMacroBlockRow(this: &v152);
            if ( ++v78 >= v86 )
            {
              v87 = 0;
              v88 = (unsigned __int8 *)&v14[((v78 << 13) & 0x2000) + 1024];
              do
              {
                idBareJXR::DecompressImageNormalMapMacroBlock(this: &v152, outBuf: v88, blockNum: v87, byteStride: 512);
                v89 = 0;
                v90 = v88 - 452;
                for ( i = 16; i != 0; --i )
                {
                  v92 = (v89++ >> 2) + 4 * v78;
                  v93 = &v84[4 * v87 + ((32 * v92) & 0x3FFFFFE0)];
                  v94 = *v93;
                  v95 = v93[1];
                  v96 = v93[2];
                  v97 = v93[3];
                  v90[452] = *v93;
                  v90[456] = v94;
                  v90[460] = v94;
                  v90[464] = v94;
                  v90[468] = v95;
                  v90[472] = v95;
                  v90[476] = v95;
                  v90[480] = v95;
                  v90[484] = v96;
                  v90[488] = v96;
                  v90[492] = v96;
                  v90[496] = v96;
                  v90[500] = v97;
                  v90[504] = v97;
                  v90[508] = v97;
                  v90 += 512;
                  *v90 = v97;
                }
                ++v87;
                v88 += 64;
              }
              while ( v87 < 8 );
            }
          }
          while ( v78 < v85 );
          v143 = v78;
        }
        v98 = 0;
        v99 = 0;
        while ( 1 )
        {
          UpSample16x16_Bicubic_3(
            dst: (unsigned __int8 *)v14,
            dstX: v98,
            dstY: v82,
            dstBytePitch: 0x40u,
            src: (const unsigned __int8 *)v14 + 1024,
            srcX: v146,
            srcY: v144,
            srcMaskY: 0x1Fu,
            upsampleLevel: v118,
            sharpenScale: v119,
            noiseScale: v120,
            a12: v121,
            a13: v122,
            a14: v123,
            a15: v124,
            a16: v125,
            a17: v126,
            a18: v127,
            a19: v128,
            a20: v129,
            a21: v130,
            a22: v131,
            a23: v132,
            a24: v133,
            a25: v134,
            a26: v135,
            a27: v136,
            a28: v2->upsampleLevel,
            a29: v137,
            a30: 0,
            a31: v138,
            a32: 0);
          v100 = &v140[(v81 >> 2) + 1024 + v99];
          v101 = &v140[((v81 + 128) >> 2) + 1024 + v99];
          v102 = &v140[((v81 + 256) >> 2) + 1024 + v99];
          v103 = &v140[((v81 + 384) >> 2) + 1024 + v99];
          v104 = *v100;
          v105 = &v150[4 * (_DWORD)&v141[v98]];
          v106 = v100[1];
          v107 = v100[2];
          v108 = *v101;
          v109 = v101[1];
          v110 = v101[2];
          v111 = *v102;
          v112 = v102[1];
          v113 = v102[2];
          v114 = *v103;
          v115 = v103[1];
          v116 = v103[2];
          LOBYTE(v100) = v100[3];
          LOBYTE(v101) = v101[3];
          LOBYTE(v102) = v102[3];
          LOBYTE(v103) = v103[3];
          v14[2] = v104;
          v14[18] = v106;
          v14[34] = v107;
          v14[50] = (char)v100;
          v14[258] = v108;
          v14[274] = v109;
          v14[290] = v110;
          v14[306] = (char)v101;
          v14[514] = v111;
          v14[530] = v112;
          v14[546] = v113;
          v14[562] = (char)v102;
          v14[770] = v114;
          v14[786] = v115;
          v14[802] = v116;
          v14[818] = (char)v103;
          idDxtEncoder::CompressNormalMapDXT5Fast_Xenon(
            this: &v156,
            inBuf: (const unsigned __int8 *)v14,
            outBuf: v105,
            width: 16,
            height: 16);
          v99 += 4;
          v98 += 16;
          if ( v99 >= 0x20 )
            break;
          v2 = parms;
          v82 = (unsigned int)v139;
        }
        v81 += 512;
        v82 = (unsigned int)(v139 + 16);
        v80 = v145 + 1;
        v79 = v142 + 1;
        ++v145;
        ++v142;
        v141 += v147;
        v139 = (const unsigned __int8 *)v82;
        if ( v82 >= 0x80 )
          break;
        v2 = parms;
        v78 = v143;
      }
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v152);
    }
  }
}


// ========================================================================
// __unwind$74438
// EA  : 0x82938C60
// RVA : 0x00938C60
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_jxr_dxt_upsample.cpp
// ========================================================================

void _unwind_74438()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 496 + 160));
}


// ========================================================================
// __unwind$74439
// EA  : 0x82938C88
// RVA : 0x00938C88
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_jxr_dxt_upsample.cpp
// ========================================================================

void _unwind_74439()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 496 + 224));
}


// ========================================================================
// __unwind$74440
// EA  : 0x82938CB0
// RVA : 0x00938CB0
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_jxr_dxt_upsample.cpp
// ========================================================================

void _unwind_74440()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 496 + 192));
}


// ========================================================================
// `dynamic initializer for 'register_TranscodePage_JXR_DXT_upsample''
// EA  : 0x833581D0
// RVA : 0x013581D0
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_jxr_dxt_upsample.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_TranscodePage_JXR_DXT_upsample__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_TranscodePage_JXR_DXT_upsample,
           function: (void (__fastcall *)(void *))TranscodePage_JXR_DXT_upsample,
           name: "TranscodePage_JXR_DXT_upsample");
}

