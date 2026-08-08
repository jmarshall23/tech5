
// ========================================================================
// ?DequantizeLP_444@@YAXPIAFPIBFABH@Z
// EA  : 0x828FAD38
// RVA : 0x008FAD38
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpquantizationdec.cpp
// ========================================================================

void __fastcall DequantizeLP_444(__int16 *pRec, const __int16 *pOrg, const int *iQPLP)
{
  __asm { lvx128    v63, r0, r4 }
  _R11 = 16;
  __asm { lvlx128   v62, r0, r5 }
  _R10 = 256;
  __asm { vupkhsh128 v61, v63 }
  _R9 = 128;
  __asm { vspltw128 v60, v62, 0 }
  _R8 = 416;
  __asm { vupklsh128 v59, v63 }
  _R7 = 64;
  __asm { lvx128    v58, r4, r11 }
  _R6 = 480;
  __asm { vcsxwfp128 v57, v61, 0 }
  _R5 = 96;
  __asm
  {
    vcsxwfp128 v56, v60, 0
    vupkhsh128 v55, v58
    vcsxwfp128 v54, v59, 0
    vupklsh128 v53, v58
  }
  _R4 = 448;
  _R11 = 32;
  __asm { vcsxwfp128 v52, v55, 0 }
  _R31 = 384;
  __asm { vcsxwfp128 v51, v53, 0 }
  _R30 = 160;
  _R29 = 288;
  _R28 = 224;
  _R27 = 352;
  _R26 = 192;
  _R25 = 320;
  __asm
  {
    vmulfp128 v50, v89, v56
    vmulfp128 v49, v86, v56
    vmulfp128 v48, v84, v56
    vmulfp128 v47, v83, v56
    vcfpsxws128 v11, v50, 0
    vcfpsxws128 v0, v49, 0
    vcfpsxws128 v13, v48, 0
    vcfpsxws128 v12, v47, 0
    vsplth    v10, v11, 3
    vsplth    v9, v11, 5
    vsplth    v8, v11, 7
    vsplth    v7, v0, 1
    vsplth    v6, v0, 3
    vsplth    v5, v0, 5
    vsplth    v4, v0, 7
    vsplth    v3, v13, 1
    stvehx    v10, r3, r10
    vsplth    v2, v13, 3
    stvehx    v9, r3, r9
    vsplth    v1, v13, 5
    stvehx    v8, r3, r8
    vsplth    v31, v13, 7
    stvehx    v7, r3, r7
    vsplth    v30, v12, 1
    stvehx    v6, r3, r6
    vsplth    v29, v12, 3
    stvehx    v5, r3, r5
    vsplth    v28, v12, 5
    stvehx    v4, r3, r4
    vsplth    v27, v12, 7
    stvehx    v3, r3, r11
    stvehx    v2, r3, r31
    stvehx    v1, r3, r30
    stvehx    v31, r3, r29
    stvehx    v30, r3, r28
    stvehx    v29, r3, r27
    stvehx    v28, r3, r26
    stvehx    v27, r3, r25
  }
}


// ========================================================================
// ?DequantizeHP_444@@YAXPIAFABH@Z
// EA  : 0x828FAE50
// RVA : 0x008FAE50
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpquantizationdec.cpp
// ========================================================================

void __fastcall DequantizeHP_444(__int16 *pRec, const int *iQPHP)
{
  int v7; // ctr

  __asm { lvlx128   v63, r0, r4 }
  _R10 = -32;
  __asm { vspltw128 v62, v63, 0 }
  _R9 = -16;
  _R8 = 16;
  _R11 = pRec + 16;
  v7 = 8;
  __asm { vcsxwfp128 v63, v62, 0 }
  do
  {
    __asm
    {
      lvx128    v61, r11, r10
      lvx128    v60, r11, r9
      lvx128    v59, r0, r11
      vupklsh128 v58, v61
      lvx128    v57, r11, r8
      vupkhsh128 v56, v61
      vupklsh128 v55, v60
      vupkhsh128 v54, v60
      vupklsh128 v53, v59
      vcsxwfp128 v52, v58, 0
      vupkhsh128 v51, v59
      vcsxwfp128 v50, v56, 0
      vupklsh128 v49, v57
      vcsxwfp128 v48, v55, 0
      vupkhsh128 v47, v57
      vcsxwfp128 v46, v54, 0
      vcsxwfp128 v45, v53, 0
      vcsxwfp128 v44, v51, 0
      vcsxwfp128 v43, v49, 0
      vcsxwfp128 v42, v47, 0
      vmulfp128 v41, v84, v63
      vmulfp128 v40, v82, v63
      vmulfp128 v39, v80, v63
      vmulfp128 v38, v78, v63
      vmulfp128 v37, v77, v63
      vmulfp128 v36, v76, v63
      vmulfp128 v35, v75, v63
      vmulfp128 v34, v74, v63
      vcfpsxws128 v33, v41, 0
      vcfpsxws128 v32, v40, 0
      vcfpsxws128 v62, v39, 0
      vcfpsxws128 v61, v38, 0
      vcfpsxws128 v60, v37, 0
      vcfpsxws128 v59, v36, 0
      vcfpsxws128 v58, v35, 0
      vcfpsxws128 v57, v34, 0
      vpkswss128 v56, v64, v33
      vpkswss128 v55, v93, v62
      vpkswss128 v54, v91, v60
      vpkswss128 v53, v89, v58
      stvx128   v56, r11, r10
      stvx128   v55, r11, r9
      stvx128   v54, r0, r11
      stvx128   v53, r11, r8
    }
    _R11 += 32;
    --v7;
  }
  while ( v7 != 0 );
}


// ========================================================================
// ?DequantizeMacroblock@@YA?AW4hdpError_t@@PAUhdpCodec_t@@@Z
// EA  : 0x828FAF30
// RVA : 0x008FAF30
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpquantizationdec.cpp
// ========================================================================

hdpError_t __fastcall DequantizeMacroblock(hdpCodec_t *codec)
{
  hdpColorFormat_t colorFormat; // r11
  unsigned int numChannels; // r25
  hdpTileQuantization_t *v4; // r26
  unsigned int v5; // r30
  __int16 **v6; // r29
  hdpQuantizer_t **v7; // r5
  int v8; // r6
  hdpCodec_t *v9; // r29
  __int16 **v10; // r27
  hdpQuantizer_t **v11; // r28
  _WORD *v12; // r10
  unsigned int v13; // ctr
  unsigned __int8 *p_cNumQPLP; // r11
  __int16 **v15; // r9

  colorFormat = codec->codecParms.colorFormat;
  numChannels = codec->codecParms.numChannels;
  v4 = &codec->tileQuantization[codec->currentTileColumn];
  if ( colorFormat == CF_YUV_420 || (v5 = codec->codecParms.numChannels, colorFormat == CF_YUV_422) )
    v5 = 1;
  if ( codec->codecParms.decodeHP && v5 != 0 )
  {
    v6 = &codec->macroBlockColumnPtr0[15];
    v7 = &v4->pQuantizerLP[15];
    do
      DequantizeHP_444(
        pRec: *++v6,
        iQPHP: (const int *)((char *)&v7[1]->iQP + __ROL4__(codec->MBInfo.quantizerIndexHP, 4)));
    while ( v8 != 1 );
  }
  if ( codec->codecParms.decodeLP && v5 != 0 )
  {
    v9 = codec;
    v10 = &codec->macroBlockColumnPtr0[15];
    v11 = &v4->pQuantizerDC[15];
    do
    {
      DequantizeLP_444(
        pRec: *++v10,
        pOrg: (const __int16 *)v9,
        iQPLP: (const int *)((char *)&(*++v11)->iQP + __ROL4__(codec->MBInfo.quantizerIndexLP, 4)));
      --v5;
      v9 = (hdpCodec_t *)((char *)v9 + 32);
    }
    while ( v5 != 0 );
  }
  if ( numChannels != 0 )
  {
    v12 = codec[-1].postProcInfo[15];
    v13 = numChannels;
    p_cNumQPLP = &v4[-1].cNumQPLP;
    v15 = &codec->macroBlockColumnPtr0[15];
    do
    {
      p_cNumQPLP += 4;
      v12 += 16;
      **++v15 = *v12 * **(_WORD **)p_cNumQPLP;
      --v13;
    }
    while ( v13 != 0 );
  }
  return HDP_ERROR_NONE;
}

