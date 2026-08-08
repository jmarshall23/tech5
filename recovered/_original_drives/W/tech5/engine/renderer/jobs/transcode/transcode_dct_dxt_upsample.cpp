
// ========================================================================
// ?TranscodePage_DCT_DXT_upsample@@YAXABUtranscodeParms_t@@@Z
// EA  : 0x82930CE8
// RVA : 0x00930CE8
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_dct_dxt_upsample.cpp
// ========================================================================

void __fastcall TranscodePage_DCT_DXT_upsample(const transcodeParms_t *parms)
{
  int imageFlags; // r11
  const transcodeParms_t *v2; // r18
  int v3; // r3
  int v4; // r12
  unsigned __int8 *v5; // r10
  unsigned __int8 *v6; // r9
  unsigned __int8 *v7; // r8
  const unsigned __int8 *inPageData; // r26
  const unsigned __int8 *inPageHeader; // r14
  unsigned __int8 *v10; // r30
  unsigned __int64 v11; // r25
  int upsampleLevel; // r8
  int v13; // r11
  unsigned int v14; // r4
  unsigned int v15; // r21
  int v16; // r9
  int v17; // r10
  int v18; // r10
  int v19; // r10
  char v20; // r11
  unsigned __int8 v21; // r28
  int v22; // r27
  int v23; // r29
  int v24; // r5
  int v25; // r10
  int v26; // r6
  int v27; // r9
  unsigned int v28; // r23
  int v29; // r11
  int v30; // r20
  int v31; // r9
  __int64 v32; // r8
  const unsigned __int8 *v33; // r19
  int v34; // r26
  int v35; // r17
  unsigned int v36; // r16
  unsigned int v37; // r15
  int v38; // r11
  int v39; // r27
  int v40; // r24
  unsigned int v41; // r28
  unsigned __int8 *v42; // r29
  int i; // r29
  unsigned int v44; // r29
  int v45; // r27
  int v46; // r10
  int v47; // r9
  int v48; // r8
  unsigned __int8 *v49; // r3
  unsigned __int8 *v50; // r5
  int v51; // r15
  int v52; // r29
  int v53; // r5
  int v54; // r6
  __int64 v55; // r8
  unsigned int v56; // r16
  int v57; // r23
  int v58; // r24
  unsigned int v59; // r26
  unsigned int v60; // r17
  int upsampleSharpen; // r22
  int v62; // r21
  int v63; // r11
  int v64; // r20
  int v65; // r19
  int v66; // r29
  unsigned __int8 *v67; // r28
  unsigned int v68; // r20
  unsigned int v69; // r29
  unsigned int v70; // r28
  int v71; // r19
  int v72; // r26
  int v73; // r27
  int v74; // r5
  int v75; // r28
  int v76; // r29
  int v77; // r5
  int v78; // r6
  unsigned int v79; // r10
  int v80; // r24
  unsigned int v81; // r11
  unsigned int v82; // r23
  unsigned int v83; // r26
  int v84; // r9
  unsigned __int8 *v85; // r22
  int v86; // r21
  __int64 v87; // r8
  int v88; // r20
  unsigned __int8 *v89; // r27
  unsigned int k; // r29
  unsigned int v91; // r9
  unsigned __int8 *v92; // r11
  int m; // ctr
  int v94; // r10
  unsigned __int8 *v95; // r10
  unsigned __int8 v96; // r5
  int j; // r29
  unsigned int v98; // r28
  unsigned int v99; // r29
  unsigned __int8 *v100; // r11
  unsigned __int8 *v101; // r10
  unsigned __int8 *v102; // r9
  unsigned __int8 *v103; // r8
  unsigned __int8 v104; // r24
  unsigned __int8 *v105; // r5
  unsigned __int8 v106; // r23
  unsigned __int8 v107; // r22
  unsigned __int8 v108; // r21
  unsigned __int8 v109; // r20
  unsigned __int8 v110; // r25
  unsigned __int8 v111; // r19
  unsigned __int8 v112; // r18
  unsigned __int8 v113; // r17
  unsigned __int8 v114; // r16
  unsigned __int8 v115; // r15
  unsigned __int8 v116; // r14
  _DWORD back_chain[2]; // [sp+0h] [-2D60h]
  int v118; // [sp+8h] [-2D58h]
  int v119; // [sp+Ch] [-2D54h]
  int v120; // [sp+10h] [-2D50h]
  int v121; // [sp+14h] [-2D4Ch]
  int v122; // [sp+18h] [-2D48h]
  unsigned int v123; // [sp+1Ch] [-2D44h]
  int v124; // [sp+20h] [-2D40h]
  unsigned int v125; // [sp+24h] [-2D3Ch]
  int v126; // [sp+28h] [-2D38h]
  unsigned int v127; // [sp+2Ch] [-2D34h]
  int v128; // [sp+30h] [-2D30h]
  int v129; // [sp+34h] [-2D2Ch]
  int v130; // [sp+38h] [-2D28h]
  unsigned int v131; // [sp+3Ch] [-2D24h]
  int v132; // [sp+40h] [-2D20h]
  unsigned int v133; // [sp+44h] [-2D1Ch]
  int v134; // [sp+48h] [-2D18h]
  int v135; // [sp+4Ch] [-2D14h]
  int v136; // [sp+50h] [-2D10h]
  int v137; // [sp+58h] [-2D08h]
  int v138; // [sp+60h] [-2D00h]
  int v139; // [sp+70h] [-2CF0h]
  int v140; // [sp+74h] [-2CECh]
  unsigned int v141; // [sp+78h] [-2CE8h]
  unsigned __int8 *tempData; // [sp+7Ch] [-2CE4h]
  unsigned int v143; // [sp+80h] [-2CE0h]
  int v144; // [sp+84h] [-2CDCh]
  unsigned int v145; // [sp+88h] [-2CD8h]
  unsigned int v146; // [sp+8Ch] [-2CD4h]
  int v147; // [sp+90h] [-2CD0h]
  unsigned __int8 *v148; // [sp+94h] [-2CCCh]
  idDxtEncoder v149; // [sp+A0h] [-2CC0h] BYREF
  idDxtEncoder v150; // [sp+C0h] [-2CA0h] BYREF
  idDxtEncoder v151; // [sp+E0h] [-2C80h] BYREF
  idBareDctDecoder v152; // [sp+100h] [-2C60h] BYREF
  idBareDctDecoder v153; // [sp+2E0h] [-2A80h] BYREF
  idBareDctDecoder v154; // [sp+4C0h] [-28A0h] BYREF
  idBareDctDecoder v155; // [sp+6A0h] [-26C0h] BYREF
  idBareDCTHuffmanTable v156; // [sp+880h] [-24E0h] BYREF
  idBareDCTHuffmanTable v157; // [sp+1190h] [-1BD0h] BYREF
  idBareDCTHuffmanTable v158; // [sp+1AA0h] [-12C0h] BYREF
  idBareDCTHuffmanTable v159; // [sp+23B0h] [-9B0h] BYREF

  imageFlags = parms->imageFlags;
  v2 = parms;
  parms->startedExecution = true;
  if ( imageFlags != 0 )
  {
    if ( parms->tempData == nullptr )
    {
      v3 = ((int (*)(void))RtlCheckStack12)();
      *(_DWORD *)((char *)back_chain + v4) = back_chain[0];
      *(_DWORD *)(v3 + 108) = ((unsigned int)&v151.srcPadding + 3) & 0xFFFFFF80;
    }
    __asm { dcbz128   0, r11 }
    __asm { dcbz128   r24, r10 }
    __asm { dcbz128   r7, r8 }
    __asm { dcbz128   r6, r5 }
    __asm { dcbz128   r4, r3 }
    __asm { dcbz128   r11, r10 }
    __asm { dcbz128   r9, r8 }
    __asm { dcbz128   r7, r6 }
    v5 = v2->targetImage[0];
    v6 = v2->targetImage[1];
    v7 = v2->targetImage[2];
    inPageData = v2->inPageData;
    tempData = v2->tempData;
    inPageHeader = v2->inPageHeader;
    v143 = (unsigned int)v5;
    v10 = tempData + 2048;
    v147 = (int)v6;
    v148 = v7;
    v144 = (int)inPageData;
    idBareDCTHuffmanTable::idBareDCTHuffmanTable(this: &v157, huffmanType: 0, encode: false);
    idBareDCTHuffmanTable::idBareDCTHuffmanTable(this: &v156, huffmanType: 1u, encode: false);
    idBareDCTHuffmanTable::idBareDCTHuffmanTable(this: &v159, huffmanType: 2u, encode: false);
    idBareDCTHuffmanTable::idBareDCTHuffmanTable(this: &v158, huffmanType: 3u, encode: false);
    v11 = 0x8000000000LL;
    upsampleLevel = v2->upsampleLevel;
    v13 = 1;
    v14 = 0;
    v146 = 0;
    v15 = 0;
    v145 = 0;
    v16 = 0;
    if ( upsampleLevel > 0 )
    {
      do
      {
        v17 = 124 * v13;
        if ( (v2->upsampleX & v13) == 0 )
          v17 = 4 * v13;
        v14 += v17;
        v18 = 124 * v13;
        if ( (v2->upsampleY & v13) == 0 )
          v18 = 4 * v13;
        ++v16;
        v15 += v18;
        v13 *= 2;
      }
      while ( v16 < upsampleLevel );
      v145 = v15;
      v146 = v14;
    }
    v19 = v2->imageFlags & 1;
    if ( v19 == 0 || (v2->imageFlags & 4) == 0 || (v20 = 1, (inPageHeader[5] & 3) == 2) )
      v20 = 0;
    v21 = v20;
    if ( v19 != 0 )
    {
      v23 = 4 << upsampleLevel;
      v139 = v2->targetBytePitch[0];
      v22 = v139;
      idBareDctDecoder::idBareDctDecoder(this: &v152);
      idBareDctDecoder::SetHuffmanTables(
        this: &v152,
        tableYDC: &v157,
        tableYAC: &v156,
        tableCoCgDC: &v159,
        tableCoCgAC: &v158,
        tableADC: nullptr,
        tableAAC: nullptr);
      v24 = inPageHeader[3];
      v140 = v24;
      idBareDctBase::SetQuality_Xenon(this: &v152, luminanceQuality: v140, chrominanceQuality: v24, alphaQuality: v140);
      v25 = *((unsigned __int16 *)inPageHeader + 4);
      v26 = v23 + v15;
      v27 = *((unsigned __int16 *)inPageHeader + 3);
      HIDWORD(v32) = inPageHeader[5];
      v152.imageWidth = 128;
      v152.imageHeight = 128;
      v152.bitCnt = 0x8000000000LL;
      v140 = (v32 & 0x400000000LL) != 0;
      v152.data = &inPageData[v27 + v25];
      v28 = 0;
      v29 = *((unsigned __int16 *)inPageHeader + 5);
      v30 = v21;
      v31 = *((unsigned __int16 *)inPageHeader + 6) + v27;
      LODWORD(v32) = (v32 & 0x800000000LL) != 0;
      v152.dataBytes = v29;
      v152.bitBuff = 0x8000000000LL;
      memset(&v152.dcY, 0, 16);
      v33 = &inPageData[v31 + v25 + v29];
      v149.srcPadding = 0;
      v149.dstPadding = v22 - 32;
      v34 = -1;
      v141 = v32;
      v35 = 0;
      v36 = (int)(v23 + v15) / 16 + 1;
      v37 = (int)(v15 - v23) / 16;
      do
      {
        v38 = v2->upsampleLevel;
        v39 = (v36 >> v38) & 7;
        v40 = (v37 >> v38) & 7;
        while ( v34 < v39 )
        {
          if ( ++v34 < v40 )
          {
            for ( i = 8; i != 0; --i )
            {
              if ( v140 != 0 )
                idBareDctDecoder::DecompressOneTileGrayScale_Xenon(this: &v152, rgb: v10, stride: 64, a4: v26, a5: v32);
              else
                idBareDctDecoder::DecompressOneTileRGB_Xenon(this: &v152, rgb: v10, stride: 64, a4: v26, a5: v32);
            }
          }
          else
          {
            v41 = 0;
            v42 = &v10[((v34 << 13) & 0x2000) + 1024];
            do
            {
              if ( v140 != 0 )
                idBareDctDecoder::DecompressOneTileGrayScale_Xenon(this: &v152, rgb: v42, stride: 512, a4: v26, a5: v32);
              else
                idBareDctDecoder::DecompressOneTileRGB_Xenon(this: &v152, rgb: v42, stride: 512, a4: v26, a5: v32);
              if ( v141 != 0 )
                DecompressCover16x16_0(cover: v33, tileX: v41, tileY: v34, rgba: v42, byteStride: 512);
              ++v41;
              v42 += 64;
            }
            while ( v41 < 8 );
          }
        }
        HIDWORD(v11) = tempData;
        v44 = 0;
        v45 = 0;
        do
        {
          UpSample16x16_Bicubic_0(
            dst: v10,
            dstX: 16 * v44,
            dstY: 16 * v28,
            dstBytePitch: 0x40u,
            src: v10 + 1024,
            srcX: v146,
            srcY: v15,
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
          v49 = (unsigned __int8 *)(HIDWORD(v11) + 1024);
          if ( v30 != 0 )
            DynamicScaleSpecular16x16_0(specularScale: v49, tileX: v44, tileY: v28, rgba: v10);
          else
            ConstantScaleSpecular16x16_0(
              specularScale: v49,
              tileX: v44,
              tileY: v28,
              rgba: v10,
              specularShift: inPageHeader[5] & 3,
              a6: v48,
              a7: v47,
              a8: v46,
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
          v50 = (unsigned __int8 *)(4 * (v35 + v45) + v143);
          if ( v141 != 0 )
            idDxtEncoder::CompressImageDXT1AlphaFast_Xenon(this: &v149, inBuf: v10, outBuf: v50, width: 16, height: 16);
          else
            idDxtEncoder::CompressImageDXT1Fast_Xenon(this: &v149, inBuf: v10, outBuf: v50, width: 16, height: 16);
          ++v44;
          v45 += 8;
        }
        while ( v44 < 8 );
        ++v28;
        ++v37;
        ++v36;
        v35 += v139;
      }
      while ( v28 < 8 );
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v152);
    }
    if ( (v2->imageFlags & 2) != 0 )
    {
      v51 = v2->targetBytePitch[1];
      v52 = 4 << v2->upsampleLevel;
      idBareDctDecoder::idBareDctDecoder(this: &v154);
      idBareDctDecoder::SetHuffmanTables(
        this: &v154,
        tableYDC: &v157,
        tableYAC: &v156,
        tableCoCgDC: &v159,
        tableCoCgAC: &v158,
        tableADC: nullptr,
        tableAAC: nullptr);
      v53 = inPageHeader[1];
      v139 = *inPageHeader;
      idBareDctBase::SetQuality_Xenon(this: &v154, luminanceQuality: v139, chrominanceQuality: v53, alphaQuality: v139);
      LODWORD(v55) = *((unsigned __int16 *)inPageHeader + 3);
      v54 = (int)(v52 + v15) >> 4;
      v154.bitCnt = v11;
      HIDWORD(v55) = v15 - v52;
      v154.imageWidth = 128;
      v154.imageHeight = 128;
      v154.bitBuff = v11;
      v56 = (int)(v52 + v15) / 16 + 1;
      v154.dataBytes = v55;
      v154.data = (const unsigned __int8 *)v144;
      v57 = -1;
      v58 = 0;
      v59 = 0;
      memset(&v154.dcY, 0, 16);
      v60 = (int)(v15 - v52) / 16;
      v151.srcPadding = 0;
      v151.dstPadding = v51 - 64;
      upsampleSharpen = v2->upsampleSharpen;
      v62 = v2->upsampleNoise >> v2->pageLevel;
      do
      {
        v63 = v2->upsampleLevel;
        v64 = (v56 >> v63) & 7;
        v65 = (v60 >> v63) & 7;
        while ( v57 < v64 )
        {
          ++v57;
          v66 = 8;
          if ( v57 < v65 )
          {
            do
            {
              idBareDctDecoder::DecompressOneTileYCoCg_Xenon(this: &v154, rgb: v10, stride: 64, a4: v54, a5: v55);
              --v66;
            }
            while ( v66 != 0 );
          }
          else
          {
            v67 = &v10[((v57 << 13) & 0x2000) + 1024];
            do
            {
              idBareDctDecoder::DecompressOneTileYCoCg_Xenon(this: &v154, rgb: v67, stride: 512, a4: v54, a5: v55);
              --v66;
              v67 += 64;
            }
            while ( v66 != 0 );
          }
        }
        v68 = v146;
        v69 = 0;
        v70 = v145;
        v71 = v147;
        do
        {
          UpSample16x16_Bicubic_0(
            dst: v10,
            dstX: v69,
            dstY: v59,
            dstBytePitch: 0x40u,
            src: v10 + 1024,
            srcX: v68,
            srcY: v70,
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
            a32: v62);
          idDxtEncoder::CompressYCoCgDXT5Fast_Xenon(
            this: &v151,
            inBuf: v10,
            outBuf: (unsigned __int8 *)(4 * (v58 + v69) + v71),
            width: 16,
            height: 16);
          v69 += 16;
        }
        while ( v69 < 0x80 );
        v59 += 16;
        ++v60;
        ++v56;
        v58 += v51;
      }
      while ( v59 < 0x80 );
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v154);
      v15 = v145;
    }
    if ( (v2->imageFlags & 4) != 0 )
    {
      if ( (v2->imageFlags & 1) == 0 )
        memset(Dst: tempData + 1024, Val: 8 * (1 << (inPageHeader[5] & 3)) - 8, Size: 0x400u);
      v73 = 4 << v2->upsampleLevel;
      v147 = v2->targetBytePitch[2];
      v72 = v147;
      idBareDctDecoder::idBareDctDecoder(this: &v155);
      idBareDctDecoder::SetHuffmanTables(
        this: &v155,
        tableYDC: &v157,
        tableYAC: &v156,
        tableCoCgDC: nullptr,
        tableCoCgAC: nullptr,
        tableADC: nullptr,
        tableAAC: nullptr);
      v74 = inPageHeader[4];
      v139 = v74;
      idBareDctBase::SetQuality_Xenon(this: &v155, luminanceQuality: v139, chrominanceQuality: v74, alphaQuality: v139);
      v75 = *((unsigned __int16 *)inPageHeader + 3);
      v76 = *((unsigned __int16 *)inPageHeader + 4);
      HIDWORD(v11) = v144;
      idBareDctDecoder::DecompressImageMono_Xenon(
        this: &v155,
        inBuf: (const unsigned __int8 *)(*((unsigned __int16 *)inPageHeader + 5) + v75 + v76 + v144),
        outBuf: tempData,
        width: 32,
        inputBytes: *((unsigned __int16 *)inPageHeader + 6) | 0x2000000000LL);
      idBareDctDecoder::idBareDctDecoder(this: &v153);
      idBareDctDecoder::SetHuffmanTables(
        this: &v153,
        tableYDC: &v157,
        tableYAC: &v156,
        tableCoCgDC: nullptr,
        tableCoCgAC: nullptr,
        tableADC: nullptr,
        tableAAC: nullptr);
      v77 = inPageHeader[2];
      v139 = v77;
      idBareDctBase::SetQuality_Xenon(this: &v153, luminanceQuality: v139, chrominanceQuality: v77, alphaQuality: v139);
      v153.dataBytes = v76;
      v153.data = (const unsigned __int8 *)(v75 + HIDWORD(v11));
      v153.bitCnt = v11;
      v153.imageWidth = 128;
      v153.imageHeight = 128;
      v78 = v72 - 64;
      v153.bitBuff = v11;
      v79 = (int)(v73 + v15) / 16 + 1;
      v80 = -1;
      memset(&v153.dcY, 0, 16);
      v150.srcPadding = 0;
      v150.dstPadding = v72 - 64;
      v81 = (int)(v15 - v73) / 16;
      v140 = 0;
      v82 = 0;
      v139 = v79;
      v144 = -1;
      v83 = 0;
      v141 = 0;
      v143 = v81;
      while ( 1 )
      {
        v84 = v2->upsampleLevel;
        v85 = tempData;
        LODWORD(v87) = v79 >> v84;
        v86 = (v79 >> v84) & 7;
        HIDWORD(v87) = v81 >> v84;
        v88 = (v81 >> v84) & 7;
        if ( v80 < v86 )
        {
          do
          {
            if ( ++v80 < v88 )
            {
              for ( j = 8; j != 0; --j )
                idBareDctDecoder::DecompressOneTileNormalMap_Xenon(
                  this: &v153,
                  normalMap: v10,
                  stride: 64,
                  a4: v78,
                  a5: v87);
            }
            else
            {
              v89 = &v10[((v80 << 13) & 0x2000) + 1024];
              for ( k = 0; k < 0x20; k += 4 )
              {
                idBareDctDecoder::DecompressOneTileNormalMap_Xenon(
                  this: &v153,
                  normalMap: v89,
                  stride: 512,
                  a4: v78,
                  a5: v87);
                v91 = 0;
                v92 = v89 - 452;
                for ( m = 16; m != 0; --m )
                {
                  v94 = (v91++ >> 2) + 4 * v80;
                  v95 = &v85[((32 * v94) & 0x3FFFFFE0) + k];
                  LODWORD(v87) = *v95;
                  HIDWORD(v87) = v95[1];
                  v78 = v95[2];
                  v96 = v95[3];
                  v92[452] = v87;
                  v92[456] = v87;
                  v92[460] = v87;
                  v92[464] = v87;
                  v92[468] = BYTE3(v87);
                  v92[472] = BYTE3(v87);
                  v92[476] = BYTE3(v87);
                  v92[480] = BYTE3(v87);
                  v92[484] = v78;
                  v92[488] = v78;
                  v92[492] = v78;
                  v92[496] = v78;
                  v92[500] = v96;
                  v92[504] = v96;
                  v92[508] = v96;
                  v92 += 512;
                  *v92 = v96;
                }
                v89 += 64;
              }
            }
          }
          while ( v80 < v86 );
          v144 = v80;
        }
        v98 = 0;
        v99 = 0;
        while ( 1 )
        {
          UpSample16x16_Bicubic_0(
            dst: v10,
            dstX: v98,
            dstY: v82,
            dstBytePitch: 0x40u,
            src: v10 + 1024,
            srcX: v146,
            srcY: v145,
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
          v100 = &tempData[(v83 >> 2) + 1024 + v99];
          v101 = &tempData[((v83 + 128) >> 2) + 1024 + v99];
          v102 = &tempData[((v83 + 256) >> 2) + 1024 + v99];
          v103 = &tempData[v99 + 1024 + ((v83 + 384) >> 2)];
          v104 = *v100;
          v105 = &v148[4 * v140 + 4 * v98];
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
          v10[2] = v104;
          v10[18] = v106;
          v10[34] = v107;
          v10[50] = (unsigned __int8)v100;
          v10[258] = v108;
          v10[274] = v109;
          v10[290] = v110;
          v10[306] = (unsigned __int8)v101;
          v10[514] = v111;
          v10[530] = v112;
          v10[546] = v113;
          v10[562] = (unsigned __int8)v102;
          v10[770] = v114;
          v10[786] = v115;
          v10[802] = v116;
          v10[818] = (unsigned __int8)v103;
          idDxtEncoder::CompressNormalMapDXT5Fast_Xenon(this: &v150, inBuf: v10, outBuf: v105, width: 16, height: 16);
          v99 += 4;
          v98 += 16;
          if ( v99 >= 0x20 )
            break;
          v2 = parms;
          v82 = v141;
        }
        v83 += 512;
        v82 = v141 + 16;
        v81 = v143 + 1;
        v79 = v139 + 1;
        v78 = v140 + v147;
        ++v143;
        ++v139;
        v140 += v147;
        v141 = v82;
        if ( v82 >= 0x80 )
          break;
        v2 = parms;
        v80 = v144;
      }
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v153);
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v155);
    }
  }
}


// ========================================================================
// __unwind$74476
// EA  : 0x829317CC
// RVA : 0x009317CC
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_dct_dxt_upsample.cpp
// ========================================================================

void _unwind_74476()
{
  int v0; // r12

  bfx::Planner3DInstance::Stop(this: (bfx::Planner3DInstance *)(v0 - 11616 + 256));
}


// ========================================================================
// __unwind$74477
// EA  : 0x829317F4
// RVA : 0x009317F4
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_dct_dxt_upsample.cpp
// ========================================================================

void _unwind_74477()
{
  int v0; // r12

  bfx::Planner3DInstance::Stop(this: (bfx::Planner3DInstance *)(v0 - 11616 + 1216));
}


// ========================================================================
// __unwind$74478
// EA  : 0x8293181C
// RVA : 0x0093181C
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_dct_dxt_upsample.cpp
// ========================================================================

void _unwind_74478()
{
  int v0; // r12

  bfx::Planner3DInstance::Stop(this: (bfx::Planner3DInstance *)(v0 - 11616 + 1696));
}


// ========================================================================
// __unwind$74479
// EA  : 0x82931844
// RVA : 0x00931844
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_dct_dxt_upsample.cpp
// ========================================================================

void _unwind_74479()
{
  int v0; // r12

  bfx::Planner3DInstance::Stop(this: (bfx::Planner3DInstance *)(v0 - 11616 + 736));
}


// ========================================================================
// `dynamic initializer for 'register_TranscodePage_DCT_DXT_upsample''
// EA  : 0x833580C8
// RVA : 0x013580C8
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_dct_dxt_upsample.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_TranscodePage_DCT_DXT_upsample__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_TranscodePage_DCT_DXT_upsample,
           function: (void (__fastcall *)(void *))TranscodePage_DCT_DXT_upsample,
           name: "TranscodePage_DCT_DXT_upsample");
}

