
// ========================================================================
// ?TestPerformance_JXR_DXT@@YAXABUtranscodeParms_t@@@Z
// EA  : 0x82936528
// RVA : 0x00936528
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_jxr_dxt.cpp
// ========================================================================

void __fastcall TestPerformance_JXR_DXT(const transcodeParms_t *parms)
{
  unsigned __int8 *tempData; // r27
  const unsigned __int8 *inPageHeader; // r30
  const unsigned __int8 *inPageData; // r26
  int v5; // r10
  int v6; // r9
  int i; // r28
  unsigned int j; // r29
  int k; // r28
  unsigned int m; // r29
  int v11; // r11
  unsigned int v12; // r7
  int n; // r28
  unsigned int ii; // r29
  int v15; // r10
  int v16; // r11
  unsigned int v17; // r7
  int jj; // r29
  unsigned int kk; // r30
  unsigned __int8 *v20; // r29
  const unsigned __int8 *v21; // r30
  int imageFlags; // r11
  int v23; // r27
  int mm; // r30
  int nn; // r30
  int i1; // r27
  int i2; // r30
  int i3; // r27
  int i4; // r30
  idDxtEncoder v30; // [sp+50h] [-E0h] BYREF
  idBareJXR v31; // [sp+70h] [-C0h] BYREF
  idBareJXR v32; // [sp+90h] [-A0h] BYREF
  idBareJXR v33[4]; // [sp+B0h] [-80h] BYREF

  if ( (parms->imageFlags & 0x10) != 0 )
  {
    tempData = parms->tempData;
    inPageHeader = parms->inPageHeader;
    inPageData = parms->inPageData;
    if ( (parms->imageFlags & 1) != 0 )
    {
      idBareJXR::idBareJXR(this: &v31);
      v5 = inPageHeader[2];
      v6 = inPageHeader[4] & 4;
      v31.tempBuffer = tempData + 1024;
      v31.tempBufferSize = 0x20000;
      v31.quality = v5;
      if ( v6 != 0 )
      {
        idBareJXR::BeginDecompressImageRGB(
          this: &v31,
          inBuf: &inPageData[*((unsigned __int16 *)inPageHeader + 4) + *((unsigned __int16 *)inPageHeader + 3)],
          width: 128,
          height: 128,
          inputBytes: *((unsigned __int16 *)inPageHeader + 5));
        for ( i = 8; i != 0; --i )
        {
          idBareJXR::BeginDecompressImageGrayScaleMacroBlockRow(this: &v31);
          for ( j = 0; j < 8; ++j )
            idBareJXR::DecompressImageGrayScaleMacroBlock(this: &v31, outBuf: tempData, blockNum: j, byteStride: 64);
        }
      }
      else
      {
        idBareJXR::BeginDecompressImageRGB(
          this: &v31,
          inBuf: &inPageData[*((unsigned __int16 *)inPageHeader + 4) + *((unsigned __int16 *)inPageHeader + 3)],
          width: 128,
          height: 128,
          inputBytes: *((unsigned __int16 *)inPageHeader + 5));
        for ( k = 8; k != 0; --k )
        {
          idBareJXR::BeginDecompressImageGrayScaleMacroBlockRow(this: &v31);
          for ( m = 0; m < 8; ++m )
            idBareJXR::DecompressImageRGBMacroBlock(this: &v31, outBuf: tempData, blockNum: m, byteStride: 64);
        }
      }
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v31);
    }
    if ( (parms->imageFlags & 2) != 0 )
    {
      idBareJXR::idBareJXR(this: &v32);
      v11 = *inPageHeader;
      v32.tempBuffer = tempData + 1024;
      v32.tempBufferSize = 0x20000;
      v12 = *((unsigned __int16 *)inPageHeader + 3);
      v32.quality = v11;
      idBareJXR::BeginDecompressImageRGB(this: &v32, inBuf: inPageData, width: 128, height: 128, inputBytes: v12);
      for ( n = 8; n != 0; --n )
      {
        idBareJXR::BeginDecompressImageGrayScaleMacroBlockRow(this: &v32);
        for ( ii = 0; ii < 8; ++ii )
          idBareJXR::DecompressImageYCoCgMacroBlock(this: &v32, outBuf: tempData, blockNum: ii, byteStride: 64);
      }
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v32);
    }
    if ( (parms->imageFlags & 4) != 0 )
    {
      idBareJXR::idBareJXR(this: v33);
      v15 = inPageHeader[1];
      v33[0].tempBuffer = tempData + 1024;
      v33[0].tempBufferSize = 0x20000;
      v16 = *((unsigned __int16 *)inPageHeader + 3);
      v17 = *((unsigned __int16 *)inPageHeader + 4);
      v33[0].quality = v15;
      idBareJXR::BeginDecompressImageRGB(this: v33, inBuf: &inPageData[v16], width: 128, height: 128, inputBytes: v17);
      for ( jj = 8; jj != 0; --jj )
      {
        idBareJXR::BeginDecompressImageGrayScaleMacroBlockRow(this: v33);
        for ( kk = 0; kk < 8; ++kk )
          idBareJXR::DecompressImageNormalMapMacroBlock(this: v33, outBuf: tempData, blockNum: kk, byteStride: 64);
      }
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)v33);
    }
  }
  if ( (parms->imageFlags & 8) != 0 )
  {
    v20 = parms->tempData;
    v21 = parms->inPageHeader;
    memset(Dst: v20, Val: 0, Size: 0x400u);
    imageFlags = parms->imageFlags;
    v30.dstPadding = 0;
    v30.srcPadding = 0;
    if ( (imageFlags & 1) != 0 )
    {
      v23 = 8;
      if ( (v21[4] & 8) != 0 )
      {
        do
        {
          for ( mm = 8; mm != 0; --mm )
            idDxtEncoder::CompressImageDXT1Fast_Xenon(this: &v30, inBuf: v20, outBuf: v20 + 1024, width: 16, height: 16);
          --v23;
        }
        while ( v23 != 0 );
      }
      else
      {
        do
        {
          for ( nn = 8; nn != 0; --nn )
            idDxtEncoder::CompressImageDXT1AlphaFast_Xenon(
              this: &v30,
              inBuf: v20,
              outBuf: v20 + 1024,
              width: 16,
              height: 16);
          --v23;
        }
        while ( v23 != 0 );
      }
    }
    if ( (parms->imageFlags & 2) != 0 )
    {
      for ( i1 = 8; i1 != 0; --i1 )
      {
        for ( i2 = 8; i2 != 0; --i2 )
          idDxtEncoder::CompressYCoCgDXT5Fast_Xenon(this: &v30, inBuf: v20, outBuf: v20 + 1024, width: 16, height: 16);
      }
    }
    if ( (parms->imageFlags & 4) != 0 )
    {
      for ( i3 = 8; i3 != 0; --i3 )
      {
        for ( i4 = 8; i4 != 0; --i4 )
          idDxtEncoder::CompressNormalMapDXT5Fast_Xenon(
            this: &v30,
            inBuf: v20,
            outBuf: v20 + 1024,
            width: 16,
            height: 16);
      }
    }
  }
}


// ========================================================================
// __unwind$73846
// EA  : 0x8293689C
// RVA : 0x0093689C
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_jxr_dxt.cpp
// ========================================================================

void _unwind_73846()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 304 + 112));
}


// ========================================================================
// __unwind$73847
// EA  : 0x829368C4
// RVA : 0x009368C4
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_jxr_dxt.cpp
// ========================================================================

void _unwind_73847()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 304 + 144));
}


// ========================================================================
// __unwind$73848
// EA  : 0x829368EC
// RVA : 0x009368EC
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_jxr_dxt.cpp
// ========================================================================

void _unwind_73848()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 304 + 176));
}


// ========================================================================
// ?TranscodePage_JXR_DXT@@YAXABUtranscodeParms_t@@@Z
// EA  : 0x82936920
// RVA : 0x00936920
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_jxr_dxt.cpp
// ========================================================================

void __fastcall TranscodePage_JXR_DXT(const transcodeParms_t *parms)
{
  int imageFlags; // r11
  int v3; // r3
  int v4; // r12
  unsigned __int8 *tempData; // r17
  int v6; // r11
  unsigned __int8 *v7; // r18
  unsigned __int8 *v8; // r28
  unsigned __int8 *v9; // r5
  int v10; // r10
  unsigned __int8 *v11; // r29
  unsigned __int8 *v12; // r16
  const unsigned __int8 *inPageHeader; // r21
  const unsigned __int8 *inPageData; // r27
  unsigned __int8 *v15; // r30
  bool v16; // r11
  bool v17; // r20
  int v18; // r14
  unsigned __int8 v19; // r18
  int v20; // r10
  int v21; // r26
  int v22; // r25
  unsigned int v23; // r23
  int v24; // r11
  unsigned int v25; // r22
  BOOL v26; // r15
  int v27; // r20
  const unsigned __int8 *v28; // r19
  int v29; // r26
  unsigned int i; // r23
  unsigned __int8 *v31; // r4
  int v32; // r10
  int v33; // r9
  int v34; // r8
  unsigned __int8 *v35; // r6
  unsigned __int8 *v36; // r3
  int v37; // r25
  int v38; // r20
  int v39; // r11
  unsigned int v40; // r7
  int v41; // r23
  int j; // r22
  int v43; // r25
  unsigned int k; // r26
  int v45; // r24
  int v46; // r10
  int v47; // r25
  int v48; // r11
  unsigned int v49; // r26
  unsigned int v50; // r26
  int v51; // r5
  unsigned int v52; // r27
  unsigned int v53; // r11
  unsigned int v54; // r9
  unsigned int v55; // r10
  unsigned __int8 *v56; // r7
  unsigned __int8 v57; // r26
  unsigned int v58; // r8
  unsigned __int8 v59; // r24
  char *v60; // r3
  unsigned __int8 v61; // r27
  unsigned __int8 *v62; // r5
  unsigned __int8 v63; // r21
  unsigned __int8 *v64; // r4
  unsigned __int8 v65; // r23
  char *v66; // r28
  char *v67; // r27
  char v68; // r18
  unsigned __int8 v69; // r17
  unsigned __int8 v70; // r19
  unsigned __int8 v71; // r25
  unsigned __int8 v72; // r23
  unsigned __int8 v73; // r22
  unsigned __int8 v74; // r6
  unsigned __int8 v75; // r21
  unsigned __int8 v76; // r20
  unsigned __int8 v77; // r15
  unsigned __int8 v78; // r18
  unsigned __int8 v79; // r14
  char *v80; // r17
  unsigned __int8 v81; // r16
  unsigned __int8 v82; // r18
  unsigned __int8 v83; // r29
  unsigned __int8 v84; // r26
  unsigned __int8 v85; // r26
  int v86; // r29
  unsigned __int8 *v87; // r28
  int back_chain[13]; // [sp+0h] [-1E0h]
  unsigned __int8 v89; // [sp+37h] [-1A9h]
  char v90; // [sp+50h] [-190h]
  unsigned __int8 v91; // [sp+51h] [-18Fh]
  unsigned __int8 v92; // [sp+52h] [-18Eh]
  unsigned __int8 v93; // [sp+53h] [-18Dh]
  char v94; // [sp+54h] [-18Ch]
  char v95; // [sp+55h] [-18Bh]
  BOOL v96; // [sp+58h] [-188h]
  unsigned __int8 *v97; // [sp+5Ch] [-184h]
  unsigned __int8 *v98; // [sp+60h] [-180h]
  unsigned int v99; // [sp+64h] [-17Ch]
  unsigned __int8 *v100; // [sp+68h] [-178h]
  unsigned __int8 *v101; // [sp+6Ch] [-174h]
  int v102; // [sp+70h] [-170h]
  char *v103; // [sp+74h] [-16Ch]
  int v104; // [sp+78h] [-168h]
  unsigned int v105; // [sp+7Ch] [-164h]
  unsigned __int8 *v106; // [sp+80h] [-160h]
  idBareJXR v107; // [sp+90h] [-150h] BYREF
  idBareJXR v108; // [sp+B0h] [-130h] BYREF
  idBareJXR v109; // [sp+D0h] [-110h] BYREF
  idDxtEncoder v110; // [sp+F0h] [-F0h] BYREF
  idDxtEncoder v111; // [sp+110h] [-D0h] BYREF
  idDxtEncoder v112; // [sp+130h] [-B0h] BYREF

  imageFlags = parms->imageFlags;
  parms->startedExecution = true;
  if ( imageFlags != 0 )
  {
    if ( parms->tempData == nullptr )
    {
      v3 = ((int (*)(void))RtlCheckStack12)();
      *(int *)((char *)back_chain + v4) = back_chain[0];
      *(_DWORD *)(v3 + 108) = ((unsigned int)&v108.cROIHeight + 3) & 0xFFFFFF80;
    }
    __asm { dcbz128   0, r11 }
    __asm { dcbz128   r10, r9 }
    __asm { dcbz128   r8, r7 }
    __asm { dcbz128   r6, r5 }
    __asm { dcbz128   r4, r3 }
    __asm { dcbz128   r11, r10 }
    __asm { dcbz128   r9, r8 }
    __asm { dcbz128   r7, r6 }
    tempData = parms->tempData;
    v6 = parms->imageFlags;
    v7 = parms->targetImage[1];
    v8 = tempData + 0x20000;
    v9 = parms->targetImage[2];
    v10 = parms->imageFlags & 1;
    v11 = tempData + 132096;
    v12 = parms->targetImage[0];
    inPageHeader = parms->inPageHeader;
    inPageData = parms->inPageData;
    v15 = tempData + 133120;
    v98 = tempData;
    v101 = tempData + 0x20000;
    v97 = v7;
    v100 = tempData + 132096;
    v106 = v9;
    v16 = v10 != 0 && (v6 & 4) != 0 && (inPageHeader[4] & 3) != 2;
    v17 = v16;
    if ( v10 != 0 )
    {
      v18 = parms->targetBytePitch[0];
      idBareJXR::idBareJXR(this: &v107);
      v19 = inPageHeader[4];
      v20 = inPageHeader[2];
      v107.tempBuffer = tempData;
      v107.tempBufferSize = 0x20000;
      v96 = (v19 & 4) != 0;
      v107.quality = v20;
      v21 = *((unsigned __int16 *)inPageHeader + 4);
      v22 = *((unsigned __int16 *)inPageHeader + 3);
      v23 = *((unsigned __int16 *)inPageHeader + 5);
      idBareJXR::BeginDecompressImageRGB(
        this: &v107,
        inBuf: &inPageData[v22 + v21],
        width: 128,
        height: 128,
        inputBytes: v23);
      v24 = *((unsigned __int16 *)inPageHeader + 6);
      v110.srcPadding = 0;
      v25 = 0;
      v110.dstPadding = v18 - 32;
      v26 = v17;
      v27 = 0;
      v28 = &inPageData[v24 + v22 + v21 + v23];
      do
      {
        idBareJXR::BeginDecompressImageGrayScaleMacroBlockRow(this: &v107);
        v29 = 0;
        for ( i = 0; i < 0x40; i += 8 )
        {
          v31 = tempData + 133120;
          if ( v96 )
            idBareJXR::DecompressImageGrayScaleMacroBlock(this: &v107, outBuf: v31, blockNum: v29, byteStride: 64);
          else
            idBareJXR::DecompressImageRGBMacroBlock(this: &v107, outBuf: v31, blockNum: v29, byteStride: 64);
          v35 = tempData + 133120;
          v36 = tempData + 132096;
          if ( v26 )
            DynamicScaleSpecular16x16_3(specularScale: v36, tileX: v29, tileY: v25, rgba: v35);
          else
            ConstantScaleSpecular16x16_3(
              specularScale: v36,
              tileX: v29,
              tileY: v25,
              rgba: v35,
              specularShift: v19 & 3,
              a6: v34,
              a7: v33,
              a8: v32,
              a9: back_chain[2],
              a10: back_chain[3],
              a11: back_chain[4],
              a12: back_chain[5],
              a13: back_chain[6],
              a14: back_chain[7],
              a15: back_chain[8],
              a16: back_chain[9],
              a17: back_chain[10],
              a18: back_chain[11],
              a19: back_chain[12],
              a20: v89);
          v37 = 4 * (v27 + i);
          if ( (v19 & 8) != 0 )
          {
            DecompressCover16x16_3(cover: v28, tileX: v29, tileY: v25, rgba: tempData + 133120, byteStride: 64);
            idDxtEncoder::CompressImageDXT1AlphaFast_Xenon(
              this: &v110,
              inBuf: tempData + 133120,
              outBuf: &v12[v37],
              width: 16,
              height: 16);
          }
          else
          {
            idDxtEncoder::CompressImageDXT1Fast_Xenon(
              this: &v110,
              inBuf: tempData + 133120,
              outBuf: &v12[v37],
              width: 16,
              height: 16);
          }
          ++v29;
        }
        ++v25;
        v27 += v18;
      }
      while ( v25 < 8 );
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v107);
      v7 = v97;
      tempData = v98;
    }
    if ( (parms->imageFlags & 2) != 0 )
    {
      v38 = parms->targetBytePitch[1];
      idBareJXR::idBareJXR(this: &v109);
      v39 = *inPageHeader;
      v109.tempBuffer = tempData;
      v109.tempBufferSize = 0x20000;
      v40 = *((unsigned __int16 *)inPageHeader + 3);
      v109.quality = v39;
      idBareJXR::BeginDecompressImageRGB(this: &v109, inBuf: inPageData, width: 128, height: 128, inputBytes: v40);
      v111.srcPadding = 0;
      v41 = 0;
      v111.dstPadding = v38 - 64;
      for ( j = 8; j != 0; --j )
      {
        idBareJXR::BeginDecompressImageGrayScaleMacroBlockRow(this: &v109);
        v43 = 0;
        for ( k = 0; k < 0x80; k += 16 )
        {
          idBareJXR::DecompressImageYCoCgMacroBlock(this: &v109, outBuf: v15, blockNum: v43, byteStride: 64);
          idDxtEncoder::CompressYCoCgDXT5Fast_Xenon(
            this: &v111,
            inBuf: v15,
            outBuf: &v7[4 * v41 + 4 * k],
            width: 16,
            height: 16);
          ++v43;
        }
        v41 += v38;
      }
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v109);
    }
    if ( (parms->imageFlags & 4) != 0 )
    {
      if ( (parms->imageFlags & 1) == 0 )
        memset(Dst: v11, Val: 8 * (1 << (inPageHeader[4] & 3)) - 8, Size: 0x400u);
      v45 = parms->targetBytePitch[2];
      v104 = v45;
      idBareJXR::idBareJXR(this: &v108);
      v46 = inPageHeader[3];
      v108.tempBuffer = tempData;
      v108.tempBufferSize = 0x20000;
      v47 = *((unsigned __int16 *)inPageHeader + 3);
      v48 = *((unsigned __int16 *)inPageHeader + 5);
      v108.quality = v46;
      v49 = *((unsigned __int16 *)inPageHeader + 4);
      idBareJXR::DecompressImageMono(
        this: &v108,
        inBuf: &inPageData[v48 + v47 + v49],
        outBuf: v8,
        width: 32,
        height: 32,
        inputBytes: *((unsigned __int16 *)inPageHeader + 6),
        mipLevel: 0);
      v108.quality = inPageHeader[1];
      idBareJXR::BeginDecompressImageRGB(this: &v108, inBuf: &inPageData[v47], width: 128, height: 128, inputBytes: v49);
      v50 = 0;
      v112.srcPadding = 0;
      v112.dstPadding = v45 - 64;
      v97 = nullptr;
      v96 = false;
      while ( 1 )
      {
        idBareJXR::BeginDecompressImageGrayScaleMacroBlockRow(this: &v108);
        v51 = 0;
        v102 = 0;
        v98 = nullptr;
        v52 = 0;
        v99 = 0;
        v105 = (v50 + 384) >> 2;
        while ( 1 )
        {
          idBareJXR::DecompressImageNormalMapMacroBlock(this: &v108, outBuf: v15, blockNum: v51, byteStride: 64);
          v53 = (v50 >> 2) + v52;
          v54 = ((v50 + 256) >> 2) + v52;
          v55 = ((v50 + 128) >> 2) + v52;
          v56 = &v8[v53];
          v57 = v8[v53];
          v58 = v52 + v105;
          v59 = v11[v53];
          v60 = (char *)&v11[v53];
          v62 = &v8[v54];
          v63 = v8[v53 + 1];
          LOBYTE(v53) = v8[v53 + 2];
          v64 = &v8[v52 + v105];
          v65 = *v64;
          v61 = v8[v55];
          v93 = v8[v54];
          v94 = v61;
          v67 = (char *)&v11[v54];
          v90 = v53;
          v91 = v63;
          v103 = (char *)&v11[v58];
          v92 = v65;
          v68 = v60[2];
          v69 = v60[3];
          v70 = v60[1];
          LOBYTE(v53) = v8[v55 + 1];
          v71 = v8[v55 + 2];
          v72 = v8[v54 + 1];
          v73 = v8[v54 + 2];
          LOBYTE(v54) = v11[v54];
          LOBYTE(v56) = v56[3];
          v74 = v8[v55 + 3];
          v75 = v8[v58 + 1];
          v76 = v8[v58 + 2];
          v66 = (char *)&v11[v55];
          LOBYTE(v58) = v11[v58];
          v77 = v93;
          v93 = v11[v55];
          LOBYTE(v60) = v94;
          LOBYTE(v55) = v90;
          v90 = v68;
          v94 = v54;
          v78 = v66[1];
          LOBYTE(v54) = v67[1];
          v79 = v91;
          v91 = v69;
          v80 = v103;
          v81 = v92;
          v92 = v78;
          v95 = v54;
          v82 = v66[2];
          LOBYTE(v54) = v67[2];
          LOBYTE(v62) = v62[3];
          LOBYTE(v64) = v64[3];
          LOBYTE(v66) = v66[3];
          LOBYTE(v67) = v67[3];
          v83 = v103[1];
          *v15 = v57;
          v15[16] = v79;
          v15[32] = v55;
          v15[48] = (unsigned __int8)v56;
          v15[256] = (unsigned __int8)v60;
          v15[272] = v53;
          v15[288] = v71;
          v15[304] = v74;
          v15[512] = v77;
          v15[528] = v72;
          v15[544] = v73;
          v15[560] = (unsigned __int8)v62;
          LOBYTE(v62) = v90;
          v15[306] = (unsigned __int8)v66;
          v84 = v93;
          LOBYTE(v66) = v94;
          LOBYTE(v55) = v80[2];
          v15[34] = (unsigned __int8)v62;
          LOBYTE(v62) = v91;
          v15[258] = v84;
          v15[514] = (unsigned __int8)v66;
          LOBYTE(v66) = v95;
          v85 = v92;
          v15[50] = (unsigned __int8)v62;
          LOBYTE(v62) = v80[3];
          v15[816] = (unsigned __int8)v64;
          v15[530] = (unsigned __int8)v66;
          v15[546] = v54;
          v15[786] = v83;
          v15[802] = v55;
          v15[818] = (unsigned __int8)v62;
          v15[768] = v81;
          v15[784] = v75;
          v15[800] = v76;
          v15[2] = v59;
          v15[18] = v70;
          v15[274] = v85;
          v15[290] = v82;
          v15[562] = (unsigned __int8)v67;
          v15[770] = v58;
          v86 = v102;
          v87 = v97;
          idDxtEncoder::CompressNormalMapDXT5Fast_Xenon(
            this: &v112,
            inBuf: v15,
            outBuf: &v106[4 * (_DWORD)&v97[v102]],
            width: 16,
            height: 16);
          v52 = v99 + 4;
          v51 = (int)(v98 + 1);
          v102 = v86 + 16;
          ++v98;
          v99 = v52;
          if ( v52 >= 0x20 )
            break;
          v50 = v96;
          v11 = v100;
          v8 = v101;
        }
        v50 = v96 + 512;
        v97 = &v87[v104];
        v96 = v50;
        if ( v50 >= 0x1000 )
          break;
        v11 = v100;
        v8 = v101;
      }
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v108);
    }
  }
}


// ========================================================================
// __unwind$73985
// EA  : 0x8293703C
// RVA : 0x0093703C
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_jxr_dxt.cpp
// ========================================================================

void _unwind_73985()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 480 + 144));
}


// ========================================================================
// __unwind$73986
// EA  : 0x82937064
// RVA : 0x00937064
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_jxr_dxt.cpp
// ========================================================================

void _unwind_73986()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 480 + 208));
}


// ========================================================================
// __unwind$73987
// EA  : 0x8293708C
// RVA : 0x0093708C
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_jxr_dxt.cpp
// ========================================================================

void _unwind_73987()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 480 + 176));
}


// ========================================================================
// `dynamic initializer for 'register_TranscodePage_JXR_DXT''
// EA  : 0x83358198
// RVA : 0x01358198
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_jxr_dxt.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_TranscodePage_JXR_DXT__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_TranscodePage_JXR_DXT,
           function: (void (__fastcall *)(void *))TranscodePage_JXR_DXT,
           name: "TranscodePage_JXR_DXT");
}

