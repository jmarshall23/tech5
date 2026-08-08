
// ========================================================================
// ?TranscodePage_HDP_DXT_upsample@@YAXABUtranscodeParms_t@@@Z
// EA  : 0x82934F00
// RVA : 0x00934F00
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_hdp_dxt_upsample.cpp
// ========================================================================

void __fastcall TranscodePage_HDP_DXT_upsample(const transcodeParms_t *parms)
{
  int imageFlags; // r11
  const transcodeParms_t *v2; // r25
  int v3; // r3
  int v4; // r12
  unsigned __int8 *tempData; // r20
  unsigned int v6; // r4
  unsigned __int8 *v7; // r10
  unsigned int v8; // r14
  unsigned __int8 *v9; // r18
  unsigned __int8 *v10; // r7
  unsigned __int8 *inPageData; // r19
  int v12; // r8
  int upsampleLevel; // r9
  const unsigned __int8 *inPageHeader; // r15
  char *v15; // r30
  int v16; // r11
  int v17; // r10
  int v18; // r10
  int v19; // r8
  int v20; // r6
  unsigned int v21; // r22
  unsigned int v22; // r21
  int v23; // r26
  char v24; // r11
  unsigned __int8 v25; // r24
  int v26; // r29
  unsigned __int8 v27; // r16
  int v28; // r9
  int v29; // r28
  int v30; // r27
  int v31; // r26
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
  unsigned int v75; // r23
  int v76; // r29
  unsigned int v77; // r28
  int v78; // r3
  int v79; // r24
  unsigned int v80; // r10
  unsigned int v81; // r11
  unsigned int v82; // r26
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
  _DWORD back_chain[2]; // [sp+0h] [-3A0h]
  int v118; // [sp+8h] [-398h]
  int v119; // [sp+Ch] [-394h]
  int v120; // [sp+10h] [-390h]
  int v121; // [sp+14h] [-38Ch]
  int v122; // [sp+18h] [-388h]
  unsigned int v123; // [sp+1Ch] [-384h]
  int v124; // [sp+20h] [-380h]
  unsigned int v125; // [sp+24h] [-37Ch]
  int v126; // [sp+28h] [-378h]
  unsigned int v127; // [sp+2Ch] [-374h]
  int v128; // [sp+30h] [-370h]
  int v129; // [sp+34h] [-36Ch]
  int v130; // [sp+38h] [-368h]
  unsigned int v131; // [sp+3Ch] [-364h]
  int v132; // [sp+40h] [-360h]
  unsigned int v133; // [sp+44h] [-35Ch]
  int v134; // [sp+48h] [-358h]
  int v135; // [sp+4Ch] [-354h]
  int v136; // [sp+50h] [-350h]
  int v137; // [sp+58h] [-348h]
  int v138; // [sp+60h] [-340h]
  unsigned __int8 *v139; // [sp+70h] [-330h]
  unsigned __int8 *v140; // [sp+74h] [-32Ch]
  unsigned __int8 *v141; // [sp+78h] [-328h]
  unsigned int v142; // [sp+7Ch] [-324h]
  int v143; // [sp+80h] [-320h]
  unsigned int v144; // [sp+84h] [-31Ch]
  int v145; // [sp+88h] [-318h]
  unsigned int v146; // [sp+8Ch] [-314h]
  int v147; // [sp+90h] [-310h]
  int v148; // [sp+94h] [-30Ch]
  unsigned int v149; // [sp+98h] [-308h]
  unsigned __int8 *v150; // [sp+9Ch] [-304h]
  idDxtEncoder v151; // [sp+A0h] [-300h] BYREF
  idDxtEncoder v152; // [sp+C0h] [-2E0h] BYREF
  idDxtEncoder v153; // [sp+E0h] [-2C0h] BYREF
  idBareHDP v154; // [sp+100h] [-2A0h] BYREF
  idBareHDP v155; // [sp+1B0h] [-1F0h] BYREF
  idBareHDP v156; // [sp+260h] [-140h] BYREF

  imageFlags = parms->imageFlags;
  v2 = parms;
  parms->startedExecution = true;
  if ( imageFlags != 0 )
  {
    if ( parms->tempData == nullptr )
    {
      v3 = ((int (*)(void))RtlCheckStack12)();
      *(_DWORD *)((char *)back_chain + v4) = back_chain[0];
      *(_DWORD *)(v3 + 108) = ((unsigned int)&v153.srcPadding + 3) & 0xFFFFFF80;
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
    v7 = v2->targetImage[1];
    v8 = 0;
    v9 = tempData + 33792;
    v10 = v2->targetImage[2];
    inPageData = (unsigned __int8 *)v2->inPageData;
    v12 = 0;
    upsampleLevel = v2->upsampleLevel;
    inPageHeader = v2->inPageHeader;
    v15 = (char *)(tempData + 35840);
    v141 = v2->targetImage[0];
    v143 = (int)tempData;
    v16 = 1;
    v146 = 0;
    v140 = tempData + 33792;
    v147 = (int)v7;
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
        ++v12;
        v8 += v18;
        v16 *= 2;
      }
      while ( v12 < upsampleLevel );
      v144 = v8;
      v146 = v6;
    }
    v19 = v2->imageFlags;
    v20 = v2->imageFlags & 1;
    v21 = ((v6 >> upsampleLevel == 4) + (((v6 >> upsampleLevel) - 4) >> 31) - 1) & ((v6 >> upsampleLevel) - 4);
    v22 = ((v8 >> upsampleLevel == 4) + (((v8 >> upsampleLevel) - 4) >> 31) - 1) & ((v8 >> upsampleLevel) - 4);
    v23 = (128 >> upsampleLevel) + 8;
    v149 = v21;
    v142 = v22;
    v145 = v23;
    if ( v20 == 0 || (v19 & 4) == 0 || (v24 = 1, (inPageHeader[4] & 3) == 2) )
      v24 = 0;
    v25 = v24;
    if ( v20 != 0 )
    {
      v26 = 4 << upsampleLevel;
      v148 = v2->targetBytePitch[0];
      idBareHDP::idBareHDP(this: &v154);
      v27 = inPageHeader[4];
      v28 = inPageHeader[2];
      v154.tempBuffer = tempData;
      v154.tempBufferSize = 33792;
      v154.imageROILeftX = v21;
      v154.imageROITopY = v22;
      v154.quality = v28;
      v154.imageROIWidth = v23;
      v154.imageROIHeight = v23;
      v29 = *((unsigned __int16 *)inPageHeader + 4);
      v30 = *((unsigned __int16 *)inPageHeader + 3);
      v31 = *((unsigned __int16 *)inPageHeader + 5);
      if ( (v27 & 4) != 0 )
        idBareHDP::BeginDecompressImageGrayScale(
          this: &v154,
          inBuf: &inPageData[v30 + v29],
          width: 0x80u,
          height: 0x80u,
          inputBytes: *((unsigned __int16 *)inPageHeader + 5));
      else
        idBareHDP::BeginDecompressImageRGB(
          this: &v154,
          inBuf: &inPageData[v30 + v29],
          width: 0x80u,
          height: 0x80u,
          inputBytes: *((unsigned __int16 *)inPageHeader + 5));
      v32 = 0;
      v33 = (char *)(tempData + 36864);
      v34 = *((unsigned __int16 *)inPageHeader + 6) + v30;
      v151.srcPadding = 0;
      v35 = 0;
      v36 = &v139[v34 + v29 + v31];
      v151.dstPadding = v148 - 32;
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
          idBareHDP::BeginDecompressImageYCoCgMacroBlockRow(this: &v154);
          if ( ++v37 >= v43 )
          {
            v44 = 0;
            v45 = (unsigned __int8 *)&v33[(v37 << 13) & 0x2000];
            do
            {
              if ( (v27 & 4) != 0 )
                idBareHDP::DecompressImageGrayScaleMacroBlock(
                  this: &v154,
                  outBuf: v45,
                  blockNum: v44,
                  byteStride: 0x200u);
              else
                idBareHDP::DecompressImageRGBMacroBlock(this: &v154, outBuf: v45, blockNum: v44, byteStride: 0x200u);
              if ( (v27 & 8) != 0 )
                DecompressCover16x16_2(cover: v36, tileX: v44, tileY: v37, rgba: v45, byteStride: 512);
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
          UpSample16x16_Bicubic_2(
            dst: (unsigned __int8 *)v15,
            dstX: 16 * v46,
            dstY: 16 * v35,
            dstBytePitch: 0x40u,
            src: (const unsigned __int8 *)v15 + 1024,
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
            DynamicScaleSpecular16x16_2(specularScale: v51, tileX: v46, tileY: v35, rgba: (unsigned __int8 *)v15);
          else
            ConstantScaleSpecular16x16_2(
              specularScale: v51,
              tileX: v46,
              tileY: v35,
              rgba: (unsigned __int8 *)v15,
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
              this: &v151,
              inBuf: (const unsigned __int8 *)v15,
              outBuf: v52,
              width: 16,
              height: 16);
          else
            idDxtEncoder::CompressImageDXT1Fast_Xenon(
              this: &v151,
              inBuf: (const unsigned __int8 *)v15,
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
        v32 += v148;
      }
      while ( v35 < 8 );
      idBareHDP::TerminateMacroBlockRowDecoding(this: &v154);
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v154);
      v8 = v144;
      inPageData = v139;
      v9 = v140;
      tempData = (unsigned __int8 *)v143;
      v21 = v149;
      v22 = v142;
      v23 = v145;
    }
    if ( (v2->imageFlags & 2) != 0 )
    {
      v53 = v2->targetBytePitch[1];
      v54 = 4 << v2->upsampleLevel;
      idBareHDP::idBareHDP(this: &v156);
      v55 = *inPageHeader;
      v156.tempBuffer = tempData;
      v156.imageROILeftX = v21;
      v156.tempBufferSize = 33792;
      v156.imageROITopY = v22;
      v156.quality = v55;
      v156.imageROIWidth = v23;
      v156.imageROIHeight = v23;
      idBareHDP::BeginDecompressImageYCoCg(
        this: &v156,
        inBuf: inPageData,
        width: 0x80u,
        height: 0x80u,
        inputBytes: *((unsigned __int16 *)inPageHeader + 3));
      pageLevel = v2->pageLevel;
      v57 = 0;
      v58 = (int)(v54 + v8) / 16 + 1;
      v152.srcPadding = 0;
      v59 = 0;
      v152.dstPadding = v53 - 64;
      v60 = -1;
      v61 = (int)(v8 - v54) / 16;
      upsampleSharpen = v2->upsampleSharpen;
      v63 = v2->upsampleNoise >> pageLevel;
      do
      {
        v64 = v2->upsampleLevel;
        v65 = (v58 >> v64) & 7;
        v66 = (v61 >> v64) & 7;
        while ( v60 < v65 )
        {
          idBareHDP::BeginDecompressImageYCoCgMacroBlockRow(this: &v156);
          if ( ++v60 >= v66 )
          {
            v67 = 0;
            v68 = (unsigned __int8 *)&v15[((v60 << 13) & 0x2000) + 1024];
            do
            {
              idBareHDP::DecompressImageYCoCgMacroBlock(this: &v156, outBuf: v68, blockNum: v67++, byteStride: 0x200u);
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
          UpSample16x16_Bicubic_2(
            dst: (unsigned __int8 *)v15,
            dstX: v70,
            dstY: v57,
            dstBytePitch: 0x40u,
            src: (const unsigned __int8 *)v15 + 1024,
            srcX: v69,
            srcY: v8,
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
            this: &v152,
            inBuf: (const unsigned __int8 *)v15,
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
      idBareHDP::TerminateMacroBlockRowDecoding(this: &v156);
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v156);
      inPageData = v139;
      v9 = v140;
      tempData = (unsigned __int8 *)v143;
      v21 = v149;
      v22 = v142;
      v23 = v145;
    }
    if ( (v2->imageFlags & 4) != 0 )
    {
      if ( (v2->imageFlags & 1) == 0 )
        memset(Dst: v9 + 1024, Val: 8 * (1 << (inPageHeader[4] & 3)) - 8, Size: 0x400u);
      v73 = 4 << v2->upsampleLevel;
      v147 = v2->targetBytePitch[2];
      v72 = v147;
      idBareHDP::idBareHDP(this: &v155);
      v74 = inPageHeader[3];
      v155.tempBufferSize = 33792;
      v75 = 0;
      v153.dstPadding = v72 - 64;
      v155.tempBuffer = tempData;
      v153.srcPadding = 0;
      v155.quality = v74;
      v76 = *((unsigned __int16 *)inPageHeader + 3);
      v77 = *((unsigned __int16 *)inPageHeader + 4);
      idBareHDP::DecompressImageMono(
        this: &v155,
        inBuf: &inPageData[*((unsigned __int16 *)inPageHeader + 5) + v76 + v77],
        outBuf: v9,
        width: 0x20u,
        height: 0x20u,
        inputBytes: *((unsigned __int16 *)inPageHeader + 6),
        mipLevel: 0);
      v78 = inPageHeader[1];
      v155.imageROILeftX = v21;
      v155.imageROITopY = v22;
      v155.imageROIWidth = v23;
      v155.imageROIHeight = v23;
      v155.quality = v78;
      idBareHDP::BeginDecompressImageNormalMap(
        this: &v155,
        inBuf: &inPageData[v76],
        width: 0x80u,
        height: 0x80u,
        inputBytes: v77);
      v141 = nullptr;
      v139 = nullptr;
      v79 = -1;
      v143 = -1;
      v80 = (int)(v73 + v8) / 16 + 1;
      v81 = (int)(v8 - v73) / 16;
      v82 = 0;
      v142 = v80;
      v145 = v81;
      while ( 1 )
      {
        v83 = v2->upsampleLevel;
        v84 = v140;
        v85 = (v80 >> v83) & 7;
        v86 = (v81 >> v83) & 7;
        if ( v79 < v85 )
        {
          do
          {
            idBareHDP::BeginDecompressImageYCoCgMacroBlockRow(this: &v155);
            if ( ++v79 >= v86 )
            {
              v87 = 0;
              v88 = (unsigned __int8 *)&v15[((v79 << 13) & 0x2000) + 1024];
              do
              {
                idBareHDP::DecompressImageNormalMapMacroBlock(
                  this: &v155,
                  outBuf: v88,
                  blockNum: v87,
                  byteStride: 0x200u);
                v89 = 0;
                v90 = v88 - 452;
                for ( i = 16; i != 0; --i )
                {
                  v92 = (v89++ >> 2) + 4 * v79;
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
          while ( v79 < v85 );
          v143 = v79;
        }
        v98 = 0;
        v99 = 0;
        while ( 1 )
        {
          UpSample16x16_Bicubic_2(
            dst: (unsigned __int8 *)v15,
            dstX: v98,
            dstY: v75,
            dstBytePitch: 0x40u,
            src: (const unsigned __int8 *)v15 + 1024,
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
          v100 = &v140[(v82 >> 2) + 1024 + v99];
          v101 = &v140[((v82 + 128) >> 2) + 1024 + v99];
          v102 = &v140[((v82 + 256) >> 2) + 1024 + v99];
          v103 = &v140[((v82 + 384) >> 2) + 1024 + v99];
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
          v15[2] = v104;
          v15[18] = v106;
          v15[34] = v107;
          v15[50] = (char)v100;
          v15[258] = v108;
          v15[274] = v109;
          v15[290] = v110;
          v15[306] = (char)v101;
          v15[514] = v111;
          v15[530] = v112;
          v15[546] = v113;
          v15[562] = (char)v102;
          v15[770] = v114;
          v15[786] = v115;
          v15[802] = v116;
          v15[818] = (char)v103;
          idDxtEncoder::CompressNormalMapDXT5Fast_Xenon(
            this: &v153,
            inBuf: (const unsigned __int8 *)v15,
            outBuf: v105,
            width: 16,
            height: 16);
          v99 += 4;
          v98 += 16;
          if ( v99 >= 0x20 )
            break;
          v2 = parms;
          v75 = (unsigned int)v139;
        }
        v82 += 512;
        v75 = (unsigned int)(v139 + 16);
        v81 = v145 + 1;
        v80 = v142 + 1;
        ++v145;
        ++v142;
        v141 += v147;
        v139 = (unsigned __int8 *)v75;
        if ( v75 >= 0x80 )
          break;
        v2 = parms;
        v79 = v143;
      }
      idBareHDP::TerminateMacroBlockRowDecoding(this: &v155);
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v155);
    }
  }
}


// ========================================================================
// __unwind$74433
// EA  : 0x82935940
// RVA : 0x00935940
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_hdp_dxt_upsample.cpp
// ========================================================================

void _unwind_74433()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 928 + 256));
}


// ========================================================================
// __unwind$74434
// EA  : 0x82935968
// RVA : 0x00935968
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_hdp_dxt_upsample.cpp
// ========================================================================

void _unwind_74434()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 928 + 608));
}


// ========================================================================
// __unwind$74435
// EA  : 0x82935990
// RVA : 0x00935990
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_hdp_dxt_upsample.cpp
// ========================================================================

void _unwind_74435()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 928 + 432));
}


// ========================================================================
// `dynamic initializer for 'register_TranscodePage_HDP_DXT_upsample''
// EA  : 0x83358178
// RVA : 0x01358178
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_hdp_dxt_upsample.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_TranscodePage_HDP_DXT_upsample__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_TranscodePage_HDP_DXT_upsample,
           function: (void (__fastcall *)(void *))TranscodePage_HDP_DXT_upsample,
           name: "TranscodePage_HDP_DXT_upsample");
}

