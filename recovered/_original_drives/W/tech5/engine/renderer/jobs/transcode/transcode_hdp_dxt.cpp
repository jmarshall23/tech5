
// ========================================================================
// ?TestPerformance_HDP_DXT@@YAXABUtranscodeParms_t@@@Z
// EA  : 0x829331C8
// RVA : 0x009331C8
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_hdp_dxt.cpp
// ========================================================================

void __fastcall TestPerformance_HDP_DXT(const transcodeParms_t *parms)
{
  unsigned __int8 *tempData; // r27
  const unsigned __int8 *inPageHeader; // r30
  unsigned __int8 *inPageData; // r26
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
  idDxtEncoder v30; // [sp+50h] [-280h] BYREF
  idBareHDP v31; // [sp+70h] [-260h] BYREF
  idBareHDP v32; // [sp+120h] [-1B0h] BYREF
  idBareHDP v33; // [sp+1D0h] [-100h] BYREF

  if ( (parms->imageFlags & 0x10) != 0 )
  {
    tempData = parms->tempData;
    inPageHeader = parms->inPageHeader;
    inPageData = (unsigned __int8 *)parms->inPageData;
    if ( (parms->imageFlags & 1) != 0 )
    {
      idBareHDP::idBareHDP(this: &v31);
      v5 = inPageHeader[2];
      v6 = inPageHeader[4] & 4;
      v31.tempBuffer = tempData + 1024;
      v31.tempBufferSize = 33792;
      v31.quality = v5;
      if ( v6 != 0 )
      {
        idBareHDP::BeginDecompressImageGrayScale(
          this: &v31,
          inBuf: &inPageData[*((unsigned __int16 *)inPageHeader + 4) + *((unsigned __int16 *)inPageHeader + 3)],
          width: 0x80u,
          height: 0x80u,
          inputBytes: *((unsigned __int16 *)inPageHeader + 5));
        for ( i = 8; i != 0; --i )
        {
          idBareHDP::BeginDecompressImageYCoCgMacroBlockRow(this: &v31);
          for ( j = 0; j < 8; ++j )
            idBareHDP::DecompressImageGrayScaleMacroBlock(this: &v31, outBuf: tempData, blockNum: j, byteStride: 0x40u);
        }
      }
      else
      {
        idBareHDP::BeginDecompressImageRGB(
          this: &v31,
          inBuf: &inPageData[*((unsigned __int16 *)inPageHeader + 4) + *((unsigned __int16 *)inPageHeader + 3)],
          width: 0x80u,
          height: 0x80u,
          inputBytes: *((unsigned __int16 *)inPageHeader + 5));
        for ( k = 8; k != 0; --k )
        {
          idBareHDP::BeginDecompressImageYCoCgMacroBlockRow(this: &v31);
          for ( m = 0; m < 8; ++m )
            idBareHDP::DecompressImageRGBMacroBlock(this: &v31, outBuf: tempData, blockNum: m, byteStride: 0x40u);
        }
      }
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v31);
    }
    if ( (parms->imageFlags & 2) != 0 )
    {
      idBareHDP::idBareHDP(this: &v32);
      v11 = *inPageHeader;
      v32.tempBuffer = tempData + 1024;
      v32.tempBufferSize = 33792;
      v12 = *((unsigned __int16 *)inPageHeader + 3);
      v32.quality = v11;
      idBareHDP::BeginDecompressImageYCoCg(this: &v32, inBuf: inPageData, width: 0x80u, height: 0x80u, inputBytes: v12);
      for ( n = 8; n != 0; --n )
      {
        idBareHDP::BeginDecompressImageYCoCgMacroBlockRow(this: &v32);
        for ( ii = 0; ii < 8; ++ii )
          idBareHDP::DecompressImageYCoCgMacroBlock(this: &v32, outBuf: tempData, blockNum: ii, byteStride: 0x40u);
      }
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v32);
    }
    if ( (parms->imageFlags & 4) != 0 )
    {
      idBareHDP::idBareHDP(this: &v33);
      v15 = inPageHeader[1];
      v33.tempBuffer = tempData + 1024;
      v33.tempBufferSize = 33792;
      v16 = *((unsigned __int16 *)inPageHeader + 3);
      v17 = *((unsigned __int16 *)inPageHeader + 4);
      v33.quality = v15;
      idBareHDP::BeginDecompressImageNormalMap(
        this: &v33,
        inBuf: &inPageData[v16],
        width: 0x80u,
        height: 0x80u,
        inputBytes: v17);
      for ( jj = 8; jj != 0; --jj )
      {
        idBareHDP::BeginDecompressImageYCoCgMacroBlockRow(this: &v33);
        for ( kk = 0; kk < 8; ++kk )
          idBareHDP::DecompressImageNormalMapMacroBlock(this: &v33, outBuf: tempData, blockNum: kk, byteStride: 0x40u);
      }
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v33);
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
// __unwind$73841
// EA  : 0x82933540
// RVA : 0x00933540
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_hdp_dxt.cpp
// ========================================================================

void _unwind_73841()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 720 + 112));
}


// ========================================================================
// __unwind$73842
// EA  : 0x82933568
// RVA : 0x00933568
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_hdp_dxt.cpp
// ========================================================================

void _unwind_73842()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 720 + 288));
}


// ========================================================================
// __unwind$73843
// EA  : 0x82933590
// RVA : 0x00933590
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_hdp_dxt.cpp
// ========================================================================

void _unwind_73843()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 720 + 464));
}


// ========================================================================
// ?TranscodePage_HDP_DXT@@YAXABUtranscodeParms_t@@@Z
// EA  : 0x829335C0
// RVA : 0x009335C0
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_hdp_dxt.cpp
// ========================================================================

void __fastcall TranscodePage_HDP_DXT(const transcodeParms_t *parms)
{
  int imageFlags; // r11
  int v3; // r3
  int v4; // r12
  unsigned __int8 *tempData; // r15
  int v6; // r11
  unsigned __int8 *v7; // r18
  unsigned __int8 *v8; // r4
  unsigned __int8 *v9; // r28
  int v10; // r10
  unsigned __int8 *v11; // r16
  unsigned __int8 *v12; // r29
  const unsigned __int8 *inPageHeader; // r21
  unsigned __int8 *inPageData; // r27
  unsigned __int8 *v15; // r30
  bool v16; // r11
  bool v17; // r20
  int v18; // r14
  unsigned __int8 v19; // r18
  int v20; // r10
  int v21; // r26
  int v22; // r25
  int v23; // r23
  int v24; // r11
  unsigned int v25; // r22
  BOOL v26; // r15
  int v27; // r20
  const unsigned __int8 *v28; // r19
  unsigned int v29; // r26
  unsigned int i; // r23
  int v31; // r10
  int v32; // r9
  int v33; // r8
  int v34; // r25
  int v35; // r20
  int v36; // r11
  unsigned int v37; // r7
  int v38; // r23
  int j; // r22
  unsigned int v40; // r25
  unsigned int k; // r26
  int v42; // r24
  int v43; // r10
  int v44; // r25
  int v45; // r11
  unsigned int v46; // r26
  unsigned int v47; // r26
  unsigned int v48; // r5
  unsigned int v49; // r27
  unsigned int v50; // r11
  unsigned int v51; // r9
  unsigned int v52; // r10
  unsigned __int8 *v53; // r7
  unsigned __int8 v54; // r26
  unsigned int v55; // r8
  unsigned __int8 v56; // r24
  unsigned __int8 *v57; // r3
  unsigned __int8 v58; // r27
  unsigned __int8 *v59; // r5
  unsigned __int8 v60; // r21
  unsigned __int8 *v61; // r4
  unsigned __int8 v62; // r23
  unsigned __int8 *v63; // r28
  unsigned __int8 *v64; // r27
  unsigned __int8 v65; // r18
  unsigned __int8 v66; // r17
  unsigned __int8 v67; // r19
  unsigned __int8 v68; // r25
  unsigned __int8 v69; // r23
  unsigned __int8 v70; // r22
  unsigned __int8 v71; // r6
  unsigned __int8 v72; // r21
  unsigned __int8 v73; // r20
  unsigned __int8 v74; // r15
  unsigned __int8 v75; // r18
  unsigned __int8 v76; // r14
  unsigned __int8 *v77; // r17
  unsigned __int8 v78; // r16
  unsigned __int8 v79; // r18
  unsigned __int8 v80; // r29
  unsigned __int8 v81; // r26
  unsigned __int8 v82; // r26
  int v83; // r29
  unsigned __int8 *v84; // r28
  int back_chain[13]; // [sp+0h] [-390h]
  unsigned __int8 v86; // [sp+37h] [-359h]
  char v87; // [sp+50h] [-340h]
  unsigned __int8 v88; // [sp+51h] [-33Fh]
  unsigned __int8 v89; // [sp+52h] [-33Eh]
  unsigned __int8 v90; // [sp+53h] [-33Dh]
  char v91; // [sp+54h] [-33Ch]
  char v92; // [sp+55h] [-33Bh]
  BOOL v93; // [sp+58h] [-338h]
  unsigned __int8 *v94; // [sp+5Ch] [-334h]
  unsigned __int8 *v95; // [sp+60h] [-330h]
  unsigned int v96; // [sp+64h] [-32Ch]
  unsigned __int8 *v97; // [sp+68h] [-328h]
  unsigned __int8 *v98; // [sp+6Ch] [-324h]
  int v99; // [sp+70h] [-320h]
  unsigned __int8 *v100; // [sp+74h] [-31Ch]
  int v101; // [sp+78h] [-318h]
  unsigned int v102; // [sp+7Ch] [-314h]
  unsigned __int8 *v103; // [sp+80h] [-310h]
  idDxtEncoder v104; // [sp+90h] [-300h] BYREF
  idDxtEncoder v105; // [sp+B0h] [-2E0h] BYREF
  char v106; // [sp+CFh] [-2C1h] BYREF
  idDxtEncoder v107; // [sp+D0h] [-2C0h] BYREF
  idBareHDP v108; // [sp+F0h] [-2A0h] BYREF
  idBareHDP v109; // [sp+1A0h] [-1F0h] BYREF
  idBareHDP v110; // [sp+250h] [-140h] BYREF

  imageFlags = parms->imageFlags;
  parms->startedExecution = true;
  if ( imageFlags != 0 )
  {
    if ( parms->tempData == nullptr )
    {
      v3 = ((int (*)(void))RtlCheckStack12)();
      *(int *)((char *)back_chain + v4) = back_chain[0];
      *(_DWORD *)(v3 + 108) = (unsigned int)&v106 & 0xFFFFFF80;
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
    v8 = parms->targetImage[2];
    v9 = tempData + 33792;
    v10 = parms->imageFlags & 1;
    v11 = parms->targetImage[0];
    v12 = tempData + 34816;
    inPageHeader = parms->inPageHeader;
    inPageData = (unsigned __int8 *)parms->inPageData;
    v95 = tempData;
    v15 = tempData + 35840;
    v98 = tempData + 33792;
    v94 = v7;
    v97 = tempData + 34816;
    v103 = v8;
    v16 = v10 != 0 && (v6 & 4) != 0 && (inPageHeader[4] & 3) != 2;
    v17 = v16;
    if ( v10 != 0 )
    {
      v18 = parms->targetBytePitch[0];
      idBareHDP::idBareHDP(this: &v108);
      v19 = inPageHeader[4];
      v20 = inPageHeader[2];
      v108.tempBuffer = tempData;
      v108.tempBufferSize = 33792;
      v93 = (v19 & 4) != 0;
      v108.quality = v20;
      v21 = *((unsigned __int16 *)inPageHeader + 4);
      v22 = *((unsigned __int16 *)inPageHeader + 3);
      v23 = *((unsigned __int16 *)inPageHeader + 5);
      if ( (v19 & 4) != 0 )
        idBareHDP::BeginDecompressImageGrayScale(
          this: &v108,
          inBuf: &inPageData[v22 + v21],
          width: 0x80u,
          height: 0x80u,
          inputBytes: *((unsigned __int16 *)inPageHeader + 5));
      else
        idBareHDP::BeginDecompressImageRGB(
          this: &v108,
          inBuf: &inPageData[v22 + v21],
          width: 0x80u,
          height: 0x80u,
          inputBytes: *((unsigned __int16 *)inPageHeader + 5));
      v24 = *((unsigned __int16 *)inPageHeader + 6);
      v104.srcPadding = 0;
      v25 = 0;
      v104.dstPadding = v18 - 32;
      v26 = v17;
      v27 = 0;
      v28 = &inPageData[v24 + v22 + v21 + v23];
      do
      {
        idBareHDP::BeginDecompressImageYCoCgMacroBlockRow(this: &v108);
        v29 = 0;
        for ( i = 0; i < 0x40; i += 8 )
        {
          if ( v93 )
            idBareHDP::DecompressImageGrayScaleMacroBlock(this: &v108, outBuf: v15, blockNum: v29, byteStride: 0x40u);
          else
            idBareHDP::DecompressImageRGBMacroBlock(this: &v108, outBuf: v15, blockNum: v29, byteStride: 0x40u);
          if ( v26 )
            DynamicScaleSpecular16x16_1(specularScale: v12, tileX: v29, tileY: v25, rgba: v15);
          else
            ConstantScaleSpecular16x16_1(
              specularScale: v12,
              tileX: v29,
              tileY: v25,
              rgba: v15,
              specularShift: v19 & 3,
              a6: v33,
              a7: v32,
              a8: v31,
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
              a20: v86);
          v34 = 4 * (v27 + i);
          if ( (v19 & 8) != 0 )
          {
            DecompressCover16x16_1(cover: v28, tileX: v29, tileY: v25, rgba: v15, byteStride: 64);
            idDxtEncoder::CompressImageDXT1AlphaFast_Xenon(
              this: &v104,
              inBuf: v15,
              outBuf: &v11[v34],
              width: 16,
              height: 16);
          }
          else
          {
            idDxtEncoder::CompressImageDXT1Fast_Xenon(this: &v104, inBuf: v15, outBuf: &v11[v34], width: 16, height: 16);
          }
          ++v29;
        }
        ++v25;
        v27 += v18;
      }
      while ( v25 < 8 );
      idBareHDP::TerminateMacroBlockRowDecoding(this: &v108);
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v108);
      v7 = v94;
      tempData = v95;
    }
    if ( (parms->imageFlags & 2) != 0 )
    {
      v35 = parms->targetBytePitch[1];
      idBareHDP::idBareHDP(this: &v110);
      v36 = *inPageHeader;
      v110.tempBuffer = tempData;
      v110.tempBufferSize = 33792;
      v37 = *((unsigned __int16 *)inPageHeader + 3);
      v110.quality = v36;
      idBareHDP::BeginDecompressImageYCoCg(this: &v110, inBuf: inPageData, width: 0x80u, height: 0x80u, inputBytes: v37);
      v105.srcPadding = 0;
      v38 = 0;
      v105.dstPadding = v35 - 64;
      for ( j = 8; j != 0; --j )
      {
        idBareHDP::BeginDecompressImageYCoCgMacroBlockRow(this: &v110);
        v40 = 0;
        for ( k = 0; k < 0x80; k += 16 )
        {
          idBareHDP::DecompressImageYCoCgMacroBlock(this: &v110, outBuf: v15, blockNum: v40, byteStride: 0x40u);
          idDxtEncoder::CompressYCoCgDXT5Fast_Xenon(
            this: &v105,
            inBuf: v15,
            outBuf: &v7[4 * v38 + 4 * k],
            width: 16,
            height: 16);
          ++v40;
        }
        v38 += v35;
      }
      idBareHDP::TerminateMacroBlockRowDecoding(this: &v110);
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v110);
    }
    if ( (parms->imageFlags & 4) != 0 )
    {
      if ( (parms->imageFlags & 1) == 0 )
        memset(Dst: v12, Val: 8 * (1 << (inPageHeader[4] & 3)) - 8, Size: 0x400u);
      v42 = parms->targetBytePitch[2];
      v101 = v42;
      idBareHDP::idBareHDP(this: &v109);
      v43 = inPageHeader[3];
      v109.tempBuffer = tempData;
      v109.tempBufferSize = 33792;
      v44 = *((unsigned __int16 *)inPageHeader + 3);
      v45 = *((unsigned __int16 *)inPageHeader + 5);
      v109.quality = v43;
      v46 = *((unsigned __int16 *)inPageHeader + 4);
      idBareHDP::DecompressImageMono(
        this: &v109,
        inBuf: &inPageData[v45 + v44 + v46],
        outBuf: v9,
        width: 0x20u,
        height: 0x20u,
        inputBytes: *((unsigned __int16 *)inPageHeader + 6),
        mipLevel: 0);
      v109.quality = inPageHeader[1];
      idBareHDP::BeginDecompressImageNormalMap(
        this: &v109,
        inBuf: &inPageData[v44],
        width: 0x80u,
        height: 0x80u,
        inputBytes: v46);
      v47 = 0;
      v107.srcPadding = 0;
      v107.dstPadding = v42 - 64;
      v94 = nullptr;
      v93 = false;
      while ( 1 )
      {
        idBareHDP::BeginDecompressImageYCoCgMacroBlockRow(this: &v109);
        v48 = 0;
        v99 = 0;
        v95 = nullptr;
        v49 = 0;
        v96 = 0;
        v102 = (v47 + 384) >> 2;
        while ( 1 )
        {
          idBareHDP::DecompressImageNormalMapMacroBlock(this: &v109, outBuf: v15, blockNum: v48, byteStride: 0x40u);
          v50 = (v47 >> 2) + v49;
          v51 = ((v47 + 256) >> 2) + v49;
          v52 = ((v47 + 128) >> 2) + v49;
          v53 = &v9[v50];
          v54 = v9[v50];
          v55 = v49 + v102;
          v56 = v12[v50];
          v57 = &v12[v50];
          v59 = &v9[v51];
          v60 = v9[v50 + 1];
          LOBYTE(v50) = v9[v50 + 2];
          v61 = &v9[v49 + v102];
          v62 = *v61;
          v58 = v9[v52];
          v90 = v9[v51];
          v91 = v58;
          v64 = &v12[v51];
          v87 = v50;
          v88 = v60;
          v100 = &v12[v55];
          v89 = v62;
          v65 = v57[2];
          v66 = v57[3];
          v67 = v57[1];
          LOBYTE(v50) = v9[v52 + 1];
          v68 = v9[v52 + 2];
          v69 = v9[v51 + 1];
          v70 = v9[v51 + 2];
          LOBYTE(v51) = v12[v51];
          LOBYTE(v53) = v53[3];
          v71 = v9[v52 + 3];
          v72 = v9[v55 + 1];
          v73 = v9[v55 + 2];
          v63 = &v12[v52];
          LOBYTE(v55) = v12[v55];
          v74 = v90;
          v90 = v12[v52];
          LOBYTE(v57) = v91;
          LOBYTE(v52) = v87;
          v87 = v65;
          v91 = v51;
          v75 = v63[1];
          LOBYTE(v51) = v64[1];
          v76 = v88;
          v88 = v66;
          v77 = v100;
          v78 = v89;
          v89 = v75;
          v92 = v51;
          v79 = v63[2];
          LOBYTE(v51) = v64[2];
          LOBYTE(v59) = v59[3];
          LOBYTE(v61) = v61[3];
          LOBYTE(v63) = v63[3];
          LOBYTE(v64) = v64[3];
          v80 = v100[1];
          *v15 = v54;
          v15[16] = v76;
          v15[32] = v52;
          v15[48] = (unsigned __int8)v53;
          v15[256] = (unsigned __int8)v57;
          v15[272] = v50;
          v15[288] = v68;
          v15[304] = v71;
          v15[512] = v74;
          v15[528] = v69;
          v15[544] = v70;
          v15[560] = (unsigned __int8)v59;
          LOBYTE(v59) = v87;
          v15[306] = (unsigned __int8)v63;
          v81 = v90;
          LOBYTE(v63) = v91;
          LOBYTE(v52) = v77[2];
          v15[34] = (unsigned __int8)v59;
          LOBYTE(v59) = v88;
          v15[258] = v81;
          v15[514] = (unsigned __int8)v63;
          LOBYTE(v63) = v92;
          v82 = v89;
          v15[50] = (unsigned __int8)v59;
          LOBYTE(v59) = v77[3];
          v15[816] = (unsigned __int8)v61;
          v15[530] = (unsigned __int8)v63;
          v15[546] = v51;
          v15[786] = v80;
          v15[802] = v52;
          v15[818] = (unsigned __int8)v59;
          v15[768] = v78;
          v15[784] = v72;
          v15[800] = v73;
          v15[2] = v56;
          v15[18] = v67;
          v15[274] = v82;
          v15[290] = v79;
          v15[562] = (unsigned __int8)v64;
          v15[770] = v55;
          v83 = v99;
          v84 = v94;
          idDxtEncoder::CompressNormalMapDXT5Fast_Xenon(
            this: &v107,
            inBuf: v15,
            outBuf: &v103[4 * (_DWORD)&v94[v99]],
            width: 16,
            height: 16);
          v49 = v96 + 4;
          v48 = (unsigned int)(v95 + 1);
          v99 = v83 + 16;
          ++v95;
          v96 = v49;
          if ( v49 >= 0x20 )
            break;
          v47 = v93;
          v12 = v97;
          v9 = v98;
        }
        v47 = v93 + 512;
        v94 = &v84[v101];
        v93 = v47;
        if ( v47 >= 0x1000 )
          break;
        v12 = v97;
        v9 = v98;
      }
      idBareHDP::TerminateMacroBlockRowDecoding(this: &v109);
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v109);
    }
  }
}


// ========================================================================
// __unwind$73980
// EA  : 0x82933CFC
// RVA : 0x00933CFC
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_hdp_dxt.cpp
// ========================================================================

void _unwind_73980()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 912 + 240));
}


// ========================================================================
// __unwind$73981
// EA  : 0x82933D24
// RVA : 0x00933D24
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_hdp_dxt.cpp
// ========================================================================

void _unwind_73981()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 912 + 592));
}


// ========================================================================
// __unwind$73982
// EA  : 0x82933D4C
// RVA : 0x00933D4C
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_hdp_dxt.cpp
// ========================================================================

void _unwind_73982()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 912 + 416));
}


// ========================================================================
// `dynamic initializer for 'register_TranscodePage_HDP_DXT''
// EA  : 0x83358140
// RVA : 0x01358140
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_hdp_dxt.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_TranscodePage_HDP_DXT__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_TranscodePage_HDP_DXT,
           function: (void (__fastcall *)(void *))TranscodePage_HDP_DXT,
           name: "TranscodePage_HDP_DXT");
}

