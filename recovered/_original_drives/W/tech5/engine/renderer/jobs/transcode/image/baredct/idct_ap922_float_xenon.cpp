
// ========================================================================
// ?IDCT_AP922_float_Xenon@@YAXPIBFPIBGPIAF@Z
// EA  : 0x828EAB78
// RVA : 0x008EAB78
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall IDCT_AP922_float_Xenon(const __int16 *coeff, const unsigned __int16 *quant, __int16 *dest)
{
  __asm { lvx128    v63, r0, r3 }
  _R31 = dest;
  __asm { lvx128    v62, r0, r4 }
  _R5 = 16;
  __asm { vupkhsh128 v61, v63 }
  _R6 = 32;
  __asm { vupkhsh128 v60, v62 }
  _R7 = 48;
  _R8 = 64;
  __asm { vupklsh128 v59, v62 }
  _R9 = 80;
  __asm
  {
    vupklsh128 v37, v63
    vcsxwfp128 v57, v61, 0
    lvx128    v58, r3, r5
    vcsxwfp128 v55, v60, 0
    lvx128    v54, r4, r5
    lvx128    v53, r4, r6
    vupkhsh128 v52, v58
    lvx128    v56, r3, r6
    vupkhsh128 v50, v54
    vupkhsh128 v48, v53
  }
  _R10 = 96;
  __asm
  {
    vupkhsh128 v51, v56
    lvx128    v49, r3, r7
    lvx128    v43, r4, r8
    vcsxwfp128 v46, v52, 0
    lvx128    v41, r3, r9
    vcsxwfp128 v42, v50, 0
    vcsxwfp128 v40, v48, 0
    lvx128    v47, r3, r8
    vcsxwfp128 v44, v51, 0
    lvx128    v39, r3, r10
  }
  _R11 = 112;
  __asm
  {
    vupkhsh128 v35, v49
    vupkhsh128 v48, v43
    lvx128    v45, r4, r7
    vupkhsh128 v60, v41
    lvx128    v36, r4, r9
    vmulfp128 v32, v89, v55
    vupkhsh128 v33, v47
    vupkhsh128 v57, v39
    lvx128    v34, r4, r10
    lvx128    v38, r3, r11
    vupklsh128 v62, v54
    lvx128    v61, r4, r11
    vcsxwfp128 v52, v35, 0
    vcsxwfp128 v54, v48, 0
    vupklsh128 v48, v58
    vcsxwfp128 v35, v60, 0
    vupkhsh128 v51, v45
    vcsxwfp128 v50, v33, 0
    vupklsh128 v56, v56
    vcsxwfp128 v60, v57, 0
    vupklsh128 v58, v53
    vupkhsh128 v55, v38
  }
  __asm { vupkhsh128 v33, v36 }
  __asm
  {
    vupkhsh128 v57, v34
    vmulfp128 v46, v78, v42
    vupkhsh128 v63, v61
    vmulfp128 v40, v76, v40
    vupklsh128 v45, v45
    vcsxwfp128 v44, v56, 0
    vupklsh128 v42, v47
    vcsxwfp128 v55, v55, 0
    vcsxwfp128 v51, v51, 0
    vupklsh128 v49, v49
    vcsxwfp128 v33, v33, 0
    vupklsh128 v43, v43
    vcsxwfp128 v57, v57, 0
  }
  _R4 = &tab_i_04_0_0;
  __asm { vcsxwfp128 v53, v63, 0 }
  _R3 = &tab_i_17_0_0;
  __asm
  {
    vcsxwfp128 v59, v59, 0
    vspltw128 v47, v32, 0
    vcsxwfp128 v37, v37, 0
    vcsxwfp128 v62, v62, 0
    vcsxwfp128 v48, v48, 0
    vcsxwfp128 v58, v58, 0
    vcsxwfp128 v56, v45, 0
    vmulfp128 v45, v82, v54
    vupklsh128 v36, v36
    vcsxwfp128 v54, v43, 0
    vupklsh128 v50, v41
    vcsxwfp128 v43, v42, 0
    vspltw128 v41, v46, 0
    vmulfp128 v42, v69, v59
    lvx128    v63, r0, r4
    vcsxwfp128 v37, v36, 0
    vupklsh128 v36, v34
    vcsxwfp128 v49, v49, 0
  }
  __asm
  {
    vcsxwfp128 v34, v50, 0
    vupklsh128 v59, v39
    vmulfp128 v50, v80, v62
    lvx128    v62, r0, r3
    vmulfp128 v12, v95, v47
  }
  _R3 = &tab_i_04_2;
  __asm { vmulfp128 v47, v67, v33 }
  __asm { vmulfp128 v9, v94, v41 }
  __asm { vmulfp128 v48, v84, v51 }
  _R4 = &tab_i_17_2;
  __asm
  {
    vspltw128 v41, v45, 0
    vmulfp128 v44, v76, v58
    vmulfp128 v35, v92, v57
  }
  __asm
  {
    vmulfp128 v33, v75, v54
    lvx128    v0, r0, r3
    vmulfp128 v58, v87, v53
    vspltw128 v11, v42, 0
    vmulfp128 v7, v95, v41
  }
  _R3 = &tab_i_26_0_0;
  __asm { vmulfp128 v39, v81, v56 }
  _R30 = &tab_i_35_0_0;
  __asm
  {
    vmulfp128 v57, v66, v37
    lvx128    v13, r0, r4
    vcsxwfp128 v56, v36, 0
    vspltw128 v8, v50, 0
    vcsxwfp128 v55, v59, 0
    vupklsh128 v51, v61
    vmaddfp   v10, v0, v12, v11
  }
  __asm { vupklsh128 v49, v38 }
  __asm
  {
    vspltw128 v54, v40, 0
    lvx128    v61, r0, r3
    vspltw128 v53, v48, 0
    lvx128    v60, r0, r30
    vspltw128 v52, v47, 0
  }
  _R3 = &tab_i_26_2;
  __asm
  {
    vspltw128 v12, v33, 0
    vmaddfp   v9, v13, v9, v8
  }
  _R4 = &tab_i_35_2;
  __asm
  {
    vmulfp128 v6, v93, v54
    vmulfp128 v5, v92, v53
    vspltw128 v1, v32, 2
    vmulfp128 v3, v92, v52
    vspltw128 v31, v46, 2
    vcsxwfp128 v43, v51, 0
    vspltw128 v29, v40, 2
    vcsxwfp128 v41, v49, 0
    vspltw128 v28, v48, 2
    vmaddfp   v8, v0, v7, v12
    vspltw128 v30, v45, 2
    vspltw128 v26, v42, 2
    vmulfp128 v38, v87, v56
    vspltw128 v25, v50, 2
  }
  __asm { vspltw128 v27, v47, 2 }
  __asm { vspltw128 v11, v44, 0 }
  __asm
  {
    vspltw128 v23, v44, 2
    vspltw128 v4, v39, 0
    vspltw128 v22, v39, 2
    vspltw128 v2, v57, 0
    vspltw128 v24, v33, 2
    vspltw128 v21, v57, 2
    vspltw128 v37, v35, 0
    lvx128    v0, r0, r3
  }
  _R3 = &tab_i_04_1;
  __asm
  {
    lvx128    v12, r0, r4
    vmaddfp   v7, v0, v6, v11
    vmaddfp   v6, v12, v5, v4
  }
  _R30 = &tab_i_17_1;
  __asm { vmaddfp   v5, v12, v3, v2 }
  __asm
  {
    vmulfp128 v34, v73, v43
    lvx128    v12, r0, r3
  }
  _R4 = &tab_i_35_1;
  _R3 = &tab_i_26_1;
  __asm
  {
    vmaddfp   v4, v12, v10, v1
    lvx128    v11, r0, r30
    vmaddfp   v2, v12, v8, v30
    vmaddfp   v3, v11, v9, v31
  }
  _R30 = &tab_i_04_3;
  __asm
  {
    vspltw128 v36, v58, 0
    lvx128    v9, r0, r4
  }
  __asm { lvx128    v10, r0, r3 }
  _R29 = &tab_i_35_3;
  __asm
  {
    vmulfp128 v31, v93, v37
    vmaddfp   v1, v10, v7, v29
    lvx128    v12, r0, r30
    vmaddfp   v6, v9, v6, v28
  }
  _R4 = &tab_i_17_3;
  _R3 = &tab_i_26_3;
  __asm { vmaddfp   v5, v9, v5, v27 }
  __asm
  {
    vmulfp128 v29, v94, v36
    lvx128    v7, r0, r29
  }
  __asm { vmaddfp   v4, v12, v4, v26 }
  __asm
  {
    vmaddfp   v12, v12, v2, v24
    lvx128    v9, r0, r4
    lvx128    v8, r0, r3
    vmaddfp   v3, v9, v3, v25
  }
  _R3 = &tab_i_04_4;
  __asm { vspltw128 v61, v32, 1 }
  __asm { vspltw128 v59, v46, 1 }
  _R30 = &tab_i_17_4;
  __asm { vspltw128 v56, v40, 1 }
  _R29 = &tab_i_26_4;
  __asm
  {
    vspltw128 v55, v48, 1
    vmaddfp   v2, v8, v1, v23
  }
  _R4 = &tab_i_35_4;
  __asm
  {
    vmaddfp   v6, v7, v6, v22
    lvx128    v63, r0, r3
    vspltw128 v54, v45, 1
    vmaddfp   v1, v7, v5, v21
    vspltw128 v53, v47, 1
  }
  __asm
  {
    vspltw128 v30, v38, 0
    vmulfp128 v7, v95, v61
    lvx128    v60, r0, r4
    vmr128    v52, v4
    vmr128    v51, v12
    vspltw128 v12, v34, 0
    lvx128    v62, r0, r30
    vmr128    v49, v3
    lvx128    v61, r0, r29
    vmulfp128 v28, v94, v59
    vmulfp128 v27, v93, v56
  }
  _R3 = &tab_i_04_6;
  __asm { vmulfp128 v26, v92, v55 }
  __asm { vmulfp128 v25, v95, v54 }
  __asm
  {
    vmulfp128 v24, v92, v53
    vmr128    v43, v2
    vmr128    v41, v6
    vmaddfp   v5, v0, v31, v30
    vspltw128 v6, v42, 1
  }
  __asm
  {
    vmaddfp   v4, v13, v29, v12
    lvx128    v0, r0, r3
  }
  _R3 = &tab_i_17_6;
  __asm { vmaddfp   v3, v0, v7, v6 }
  __asm { vspltw128 v2, v50, 1 }
  _R30 = &tab_i_26_6;
  _R4 = &tab_i_04_5;
  __asm
  {
    vspltw128 v22, v35, 2
    vspltw128 v29, v33, 1
  }
  __asm
  {
    lvx128    v7, r0, r3
    vspltw128 v20, v32, 3
    vmaddfp   v2, v7, v28, v2
    vspltw128 v31, v44, 1
  }
  _R3 = &tab_i_35_6;
  __asm
  {
    lvx128    v13, r0, r30
    lvx128    v6, r0, r4
    vmaddfp   v29, v0, v25, v29
    vmaddfp   v10, v10, v5, v22
  }
  _R4 = &tab_i_17_5;
  __asm
  {
    vspltw128 v30, v39, 1
    vmaddfp   v31, v13, v27, v31
    vspltw128 v23, v57, 1
  }
  __asm
  {
    vspltw128 v21, v58, 2
    lvx128    v12, r0, r3
    vmaddfp   v3, v6, v3, v20
    vspltw128 v27, v46, 3
    lvx128    v5, r0, r4
  }
  _R3 = &tab_i_04_7;
  __asm
  {
    vmaddfp   v30, v12, v26, v30
    vmr128    v37, v1
    vmaddfp   v28, v12, v24, v23
  }
  __asm
  {
    vmaddfp   v4, v11, v4, v21
    vspltw128 v24, v45, 3
    vmaddfp   v1, v5, v2, v27
    vspltw128 v22, v38, 2
    vspltw128 v27, v42, 3
  }
  _R4 = &tab_i_35_5;
  __asm { vspltw128 v36, v35, 1 }
  __asm
  {
    lvx128    v11, r0, r3
    vmaddfp   v6, v6, v29, v24
  }
  _R3 = &tab_i_26_5;
  __asm
  {
    vmaddfp   v10, v8, v10, v22
    vspltw128 v25, v48, 3
  }
  __asm
  {
    vmulfp128 v29, v93, v36
    vspltw128 v23, v47, 3
    vmaddfp   v8, v11, v3, v27
    lvx128    v12, r0, r4
    vspltw128 v26, v40, 3
  }
  _R4 = &tab_i_17_7;
  __asm
  {
    vspltw128 v2, v34, 2
    lvx128    v0, r0, r3
    vmaddfp   v30, v12, v30, v25
  }
  __asm
  {
    vmaddfp   v12, v12, v28, v23
    vspltw128 v28, v33, 3
    vmaddfp   v31, v0, v31, v26
    vspltw128 v26, v50, 3
    vmaddfp   v9, v9, v4, v2
    vspltw128 v4, v38, 1
    lvx128    v2, r0, r4
  }
  __asm
  {
    vmaddfp   v11, v11, v6, v28
    vspltw128 v27, v35, 3
    vspltw128 v21, v44, 3
    vmaddfp   v3, v2, v1, v26
    vspltw128 v25, v39, 3
  }
  _R3 = &tab_i_35_7;
  __asm
  {
    vspltw128 v24, v57, 3
    vmaddfp   v4, v13, v29, v4
    vspltw128 v23, v38, 3
  }
  _R4 = &tab_i_26_7;
  __asm
  {
    vspltw128 v35, v58, 1
    vmr128    v33, v10
    vspltw128 v28, v34, 1
    vmr128    v32, v8
  }
  __asm
  {
    lvx128    v13, r0, r3
    vmulfp128 v29, v94, v35
    vmaddfp   v8, v13, v30, v25
    lvx128    v10, r0, r4
    vmaddfp   v30, v13, v12, v24
    vspltw128 v26, v58, 3
    vmaddfp   v4, v0, v4, v27
  }
  _R3 = &vmx_float_tg_3_16;
  __asm
  {
    vmaddfp   v31, v10, v31, v21
    vspltw128 v22, v34, 3
    vaddfp128 v59, v83, v11
  }
  __asm
  {
    vsubfp128 v60, v83, v11
    vmr128    v56, v9
    vsubfp128 v63, v84, v32
  }
  _R4 = &vmx_float_tg_2_16;
  __asm
  {
    lvx128    v13, r0, r3
    vaddfp128 v62, v84, v32
    vsubfp128 v61, v81, v3
  }
  __asm { vaddfp128 v1, v81, v3 }
  _R3 = &vmx_float_tg_1_16;
  __asm
  {
    vmaddfp   v7, v7, v29, v28
    lvx128    v12, r0, r4
    vsubfp128 v55, v73, v8
  }
  __asm
  {
    vmr128    v57, v30
    vmaddfp   v28, v10, v4, v23
  }
  _R4 = &vmx_float_cos_4_16;
  __asm
  {
    vmr128    v58, v31
    vaddfp128 v31, v73, v8
    lvx128    v0, r0, r3
    vsubfp128 v53, v69, v57
    vpermwi128 v52, v60, 0xE4
    vaddfp128 v30, v69, v57
    vpermwi128 v54, v63, 0xE4
    vsubfp128 v51, v75, v58
    lvx128    v63, r0, r4
    vaddfp128 v4, v75, v58
    vpermwi128 v29, v61, 0xE4
    vaddfp128 v50, v94, v59
    vsubfp128 v47, v86, v52
    vmaddfp   v25, v5, v7, v26
    vpermwi128 v5, v55, 0xE4
    vsubfp128 v49, v94, v59
    vaddfp128 v48, v86, v52
    vsubfp128 v46, v65, v28
    vaddfp128 v27, v65, v28
    vpermwi128 v26, v53, 0xE4
    vnmsubfp  v24, v31, v30, v13
    vmaddfp   v6, v30, v31, v13
    vpermwi128 v28, v51, 0xE4
    vmaddfp   v31, v26, v5, v13
    vnmsubfp  v30, v5, v26, v13
    vmaddfp   v5, v2, v25, v22
    vpermwi128 v13, v46, 0xE4
    vmaddfp   v2, v13, v28, v12
    vmr128    v45, v6
    vmaddfp   v6, v27, v4, v12
    vmr128    v44, v31
    vnmsubfp  v31, v4, v27, v12
    vnmsubfp  v12, v28, v13, v12
    vsubfp128 v43, v88, v5
    vaddfp128 v13, v88, v5
    vsubfp128 v39, v80, v2
    vsubfp128 v42, v82, v6
    vaddfp128 v41, v82, v6
    vaddfp128 v38, v80, v2
    vaddfp128 v40, v79, v12
    vsubfp128 v35, v79, v12
    vpermwi128 v12, v43, 0xE4
    vnmsubfp  v7, v1, v13, v0
    vmaddfp   v9, v13, v1, v0
    vaddfp128 v37, v81, v31
    vnmsubfp  v13, v29, v12, v0
    vsubfp128 v36, v81, v31
    vmaddfp   v0, v12, v29, v0
    vaddfp128 v34, v7, v24
    vsubfp128 v33, v9, v45
    vsubfp128 v32, v24, v7
    vaddfp128 v62, v13, v30
    vsubfp128 v61, v0, v44
    vaddfp128 v59, v9, v45
    vsubfp128 v57, v65, v34
    vaddfp128 v56, v65, v34
    vaddfp128 v55, v74, v32
    vsubfp128 v51, v74, v32
    vaddfp128 v58, v0, v44
    vsubfp128 v60, v30, v13
    vsubfp128 v54, v93, v62
    vaddfp128 v53, v93, v62
    vaddfp128 v49, v73, v59
    vsubfp128 v46, v73, v59
    vmulfp128 v45, v89, v63
    vmulfp128 v44, v88, v63
    vaddfp128 v48, v70, v58
    vsubfp128 v50, v71, v60
    vsubfp128 v47, v70, v58
    vaddfp128 v52, v71, v60
    vrfin128  v43, v55
    vrfin128  v38, v51
    vmulfp128 v42, v86, v63
    vmulfp128 v41, v85, v63
    vrfin128  v33, v49
    vrfin128  v62, v46
    vaddfp128 v61, v68, v45
    vaddfp128 v60, v69, v44
    vsubfp128 v59, v69, v44
    vsubfp128 v54, v68, v45
    vrfin128  v34, v50
    vrfin128  v39, v52
    vrfin128  v32, v48
    vcfpsxws128 v53, v43, 0
    vaddfp128 v58, v67, v42
    vaddfp128 v57, v72, v41
    vsubfp128 v56, v72, v41
    vsubfp128 v55, v67, v42
    vrfin128  v63, v47
    vrfin128  v49, v61
    vrfin128  v48, v60
    vrfin128  v47, v59
    vrfin128  v42, v54
    vcfpsxws128 v52, v39, 0
    vcfpsxws128 v51, v34, 0
    vcfpsxws128 v50, v32, 0
    vrfin128  v46, v58
    vrfin128  v45, v57
    vrfin128  v44, v56
    vrfin128  v43, v55
    vcfpsxws128 v40, v38, 0
    vcfpsxws128 v41, v33, 0
    vcfpsxws128 v38, v49, 0
    vcfpsxws128 v37, v48, 0
    vcfpsxws128 v32, v47, 0
    vcfpsxws128 v58, v42, 0
    vpkswss128 v39, v85, v52
    vcfpsxws128 v56, v63, 0
    vcfpsxws128 v55, v62, 0
    vcfpsxws128 v36, v46, 0
    vcfpsxws128 v35, v45, 0
    vcfpsxws128 v34, v44, 0
    vcfpsxws128 v60, v43, 0
    vpkswss128 v61, v72, v51
    stvx128   v39, r31, r7
    vpkswss128 v33, v73, v50
    vpkswss128 v52, v87, v56
    stvx128   v61, r31, r8
    vpkswss128 v59, v70, v36
    stvx128   v33, r0, r31
    vpkswss128 v57, v69, v35
    vpkswss128 v54, v64, v34
    vpkswss128 v53, v90, v60
    stvx128   v52, r31, r11
    stvx128   v59, r31, r5
    stvx128   v57, r31, r6
    stvx128   v54, r31, r9
    stvx128   v53, r31, r10
  }
}


// ========================================================================
// `dynamic initializer for 'tg_1_16''_2
// EA  : 0x83352010
// RVA : 0x01352010
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tg_1_16___2(long double a1)
{
  *(_QWORD *)&a1 = 0x3FC921FB60000000LL;
  tg_1_16_2 = tan(x: a1);
}


// ========================================================================
// `dynamic initializer for 'tg_2_16''_2
// EA  : 0x83352048
// RVA : 0x01352048
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tg_2_16___2(long double a1)
{
  *(_QWORD *)&a1 = 0x3FD921FB60000000LL;
  tg_2_16_2 = tan(x: a1);
}


// ========================================================================
// `dynamic initializer for 'tg_3_16''_2
// EA  : 0x83352080
// RVA : 0x01352080
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tg_3_16___2(long double a1)
{
  *(_QWORD *)&a1 = 0x3FE2D97C80000000LL;
  tg_3_16_2 = tan(x: a1);
}


// ========================================================================
// `dynamic initializer for 'cos_4_16''_2
// EA  : 0x833520B8
// RVA : 0x013520B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__cos_4_16___2(long double a1)
{
  *(_QWORD *)&a1 = 0x3FE921FB60000000LL;
  cos_4_16_2 = cos(x: a1);
}


// ========================================================================
// `dynamic initializer for 'tab_i_04_0''
// EA  : 0x833520F0
// RVA : 0x013520F0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_04_0__(long double a1)
{
  double v1; // fp29
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp29
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp29
  long double v8; // fp2
  long double v9; // fp2
  double v10; // fp29
  long double v11; // fp2

  *(double *)&a1 = 0.7853981852531433;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.7853981852531433;
  tab_i_04_0_0.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 0.7853981852531433;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.7853981852531433;
  tab_i_04_0_0.vector4_f32[1] = (float)((float)cos(x: v5) * (float)v4) * (float)0.25;
  *(double *)&v6 = 0.7853981852531433;
  v7 = (float)cos(x: v6);
  *(double *)&v8 = 0.7853981852531433;
  tab_i_04_0_0.vector4_f32[2] = (float)((float)cos(x: v8) * (float)v7) * (float)0.25;
  *(double *)&v9 = 0.7853981852531433;
  v10 = (float)cos(x: v9);
  *(double *)&v11 = 0.7853981852531433;
  tab_i_04_0_0.vector4_f32[3] = (float)((float)cos(x: v11) * (float)v10) * (float)0.25;
}


// ========================================================================
// `dynamic initializer for 'tab_i_04_1''
// EA  : 0x833521D8
// RVA : 0x013521D8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_04_1__(long double a1)
{
  double v1; // fp27
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp27
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp28
  long double v8; // fp2
  long double v9; // fp2
  double v10; // fp8
  double v11; // fp29
  long double v12; // fp2

  *(double *)&a1 = 0.3926990926265717;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.7853981852531433;
  tab_i_04_1.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 1.178097248077393;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.7853981852531433;
  tab_i_04_1.vector4_f32[1] = (float)((float)cos(x: v5) * (float)v4) * (float)0.25;
  *(double *)&v6 = 1.178097248077393;
  v7 = (float)cos(x: v6);
  *(double *)&v8 = 0.7853981852531433;
  v10 = (float)((float)((float)cos(x: v8) * (float)v7) * (float)0.25);
  *(double *)&v9 = 0.3926990926265717;
  tab_i_04_1.vector4_f32[2] = -v10;
  v11 = (float)cos(x: v9);
  *(double *)&v12 = 0.7853981852531433;
  tab_i_04_1.vector4_f32[3] = -(float)((float)((float)cos(x: v12) * (float)v11) * (float)0.25);
}


// ========================================================================
// `dynamic initializer for 'tab_i_04_2''
// EA  : 0x833522D0
// RVA : 0x013522D0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_04_2__(long double a1)
{
  double v1; // fp29
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp29
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp10
  double v8; // fp29
  long double v9; // fp2
  long double v10; // fp2
  double v11; // fp7
  double v12; // fp29
  long double v13; // fp2

  *(double *)&a1 = 0.7853981852531433;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.7853981852531433;
  tab_i_04_2.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 0.7853981852531433;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.7853981852531433;
  v7 = (float)((float)((float)cos(x: v5) * (float)v4) * (float)0.25);
  *(double *)&v6 = 0.7853981852531433;
  tab_i_04_2.vector4_f32[1] = -v7;
  v8 = (float)cos(x: v6);
  *(double *)&v9 = 0.7853981852531433;
  v11 = (float)((float)((float)cos(x: v9) * (float)v8) * (float)0.25);
  *(double *)&v10 = 0.7853981852531433;
  tab_i_04_2.vector4_f32[2] = -v11;
  v12 = (float)cos(x: v10);
  *(double *)&v13 = 0.7853981852531433;
  tab_i_04_2.vector4_f32[3] = (float)((float)cos(x: v13) * (float)v12) * (float)0.25;
}


// ========================================================================
// `dynamic initializer for 'tab_i_04_3''
// EA  : 0x833523C0
// RVA : 0x013523C0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_04_3__(long double a1)
{
  double v1; // fp27
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp27
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp10
  double v8; // fp28
  long double v9; // fp2
  long double v10; // fp2
  double v11; // fp29
  long double v12; // fp2

  *(double *)&a1 = 1.178097248077393;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.7853981852531433;
  tab_i_04_3.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 0.3926990926265717;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.7853981852531433;
  v7 = (float)((float)((float)cos(x: v5) * (float)v4) * (float)0.25);
  *(double *)&v6 = 0.3926990926265717;
  tab_i_04_3.vector4_f32[1] = -v7;
  v8 = (float)cos(x: v6);
  *(double *)&v9 = 0.7853981852531433;
  tab_i_04_3.vector4_f32[2] = (float)((float)cos(x: v9) * (float)v8) * (float)0.25;
  *(double *)&v10 = 1.178097248077393;
  v11 = (float)cos(x: v10);
  *(double *)&v12 = 0.7853981852531433;
  tab_i_04_3.vector4_f32[3] = -(float)((float)((float)cos(x: v12) * (float)v11) * (float)0.25);
}


// ========================================================================
// `dynamic initializer for 'tab_i_04_4''
// EA  : 0x833524B8
// RVA : 0x013524B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_04_4__(long double a1)
{
  double v1; // fp29
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp29
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp29
  long double v8; // fp2
  long double v9; // fp2
  double v10; // fp29
  long double v11; // fp2

  *(_QWORD *)&a1 = 0x3FC921FB60000000LL;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.7853981852531433;
  tab_i_04_4.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(_QWORD *)&v3 = 0x3FE2D97C80000000LL;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.7853981852531433;
  tab_i_04_4.vector4_f32[1] = (float)((float)cos(x: v5) * (float)v4) * (float)0.25;
  *(_QWORD *)&v6 = 0x3FEF6A7A40000000LL;
  v7 = (float)cos(x: v6);
  *(double *)&v8 = 0.7853981852531433;
  tab_i_04_4.vector4_f32[2] = (float)((float)cos(x: v8) * (float)v7) * (float)0.25;
  *(_QWORD *)&v9 = 0x3FF5FDBC00000000LL;
  v10 = (float)cos(x: v9);
  *(double *)&v11 = 0.7853981852531433;
  tab_i_04_4.vector4_f32[3] = (float)((float)cos(x: v11) * (float)v10) * (float)0.25;
}


// ========================================================================
// `dynamic initializer for 'tab_i_04_5''
// EA  : 0x833525B0
// RVA : 0x013525B0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_04_5__(long double a1)
{
  double v1; // fp29
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp29
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp10
  double v8; // fp29
  long double v9; // fp2
  long double v10; // fp2
  double v11; // fp7
  double v12; // fp29
  long double v13; // fp2

  *(_QWORD *)&a1 = 0x3FE2D97C80000000LL;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.7853981852531433;
  tab_i_04_5.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(_QWORD *)&v3 = 0x3FF5FDBC00000000LL;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.7853981852531433;
  v7 = (float)((float)((float)cos(x: v5) * (float)v4) * (float)0.25);
  *(_QWORD *)&v6 = 0x3FC921FB60000000LL;
  tab_i_04_5.vector4_f32[1] = -v7;
  v8 = (float)cos(x: v6);
  *(double *)&v9 = 0.7853981852531433;
  v11 = (float)((float)((float)cos(x: v9) * (float)v8) * (float)0.25);
  *(_QWORD *)&v10 = 0x3FEF6A7A40000000LL;
  tab_i_04_5.vector4_f32[2] = -v11;
  v12 = (float)cos(x: v10);
  *(double *)&v13 = 0.7853981852531433;
  tab_i_04_5.vector4_f32[3] = -(float)((float)((float)cos(x: v13) * (float)v12) * (float)0.25);
}


// ========================================================================
// `dynamic initializer for 'tab_i_04_6''
// EA  : 0x833526B0
// RVA : 0x013526B0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_04_6__(long double a1)
{
  double v1; // fp29
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp29
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp10
  double v8; // fp29
  long double v9; // fp2
  long double v10; // fp2
  double v11; // fp29
  long double v12; // fp2

  *(_QWORD *)&a1 = 0x3FEF6A7A40000000LL;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.7853981852531433;
  tab_i_04_6.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(_QWORD *)&v3 = 0x3FC921FB60000000LL;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.7853981852531433;
  v7 = (float)((float)((float)cos(x: v5) * (float)v4) * (float)0.25);
  *(_QWORD *)&v6 = 0x3FF5FDBC00000000LL;
  tab_i_04_6.vector4_f32[1] = -v7;
  v8 = (float)cos(x: v6);
  *(double *)&v9 = 0.7853981852531433;
  tab_i_04_6.vector4_f32[2] = (float)((float)cos(x: v9) * (float)v8) * (float)0.25;
  *(_QWORD *)&v10 = 0x3FE2D97C80000000LL;
  v11 = (float)cos(x: v10);
  *(double *)&v12 = 0.7853981852531433;
  tab_i_04_6.vector4_f32[3] = (float)((float)cos(x: v12) * (float)v11) * (float)0.25;
}


// ========================================================================
// `dynamic initializer for 'tab_i_04_7''
// EA  : 0x833527A8
// RVA : 0x013527A8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_04_7__(long double a1)
{
  double v1; // fp29
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp29
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp10
  double v8; // fp29
  long double v9; // fp2
  long double v10; // fp2
  double v11; // fp29
  long double v12; // fp2

  *(_QWORD *)&a1 = 0x3FF5FDBC00000000LL;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.7853981852531433;
  tab_i_04_7.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(_QWORD *)&v3 = 0x3FEF6A7A40000000LL;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.7853981852531433;
  v7 = (float)((float)((float)cos(x: v5) * (float)v4) * (float)0.25);
  *(_QWORD *)&v6 = 0x3FE2D97C80000000LL;
  tab_i_04_7.vector4_f32[1] = -v7;
  v8 = (float)cos(x: v6);
  *(double *)&v9 = 0.7853981852531433;
  tab_i_04_7.vector4_f32[2] = (float)((float)cos(x: v9) * (float)v8) * (float)0.25;
  *(_QWORD *)&v10 = 0x3FC921FB60000000LL;
  v11 = (float)cos(x: v10);
  *(double *)&v12 = 0.7853981852531433;
  tab_i_04_7.vector4_f32[3] = -(float)((float)((float)cos(x: v12) * (float)v11) * (float)0.25);
}


// ========================================================================
// `dynamic initializer for 'tab_i_17_0''
// EA  : 0x833528A8
// RVA : 0x013528A8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_17_0__(long double a1)
{
  double v1; // fp28
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp28
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp28
  long double v8; // fp2
  long double v9; // fp2
  double v10; // fp31
  long double v11; // fp2

  *(double *)&a1 = 0.7853981852531433;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.1963495463132858;
  tab_i_17_0_0.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 0.7853981852531433;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.1963495463132858;
  tab_i_17_0_0.vector4_f32[1] = (float)((float)cos(x: v5) * (float)v4) * (float)0.25;
  *(double *)&v6 = 0.7853981852531433;
  v7 = (float)cos(x: v6);
  *(double *)&v8 = 0.1963495463132858;
  tab_i_17_0_0.vector4_f32[2] = (float)((float)cos(x: v8) * (float)v7) * (float)0.25;
  *(double *)&v9 = 0.7853981852531433;
  v10 = (float)cos(x: v9);
  *(double *)&v11 = 0.1963495463132858;
  tab_i_17_0_0.vector4_f32[3] = (float)((float)cos(x: v11) * (float)v10) * (float)0.25;
}


// ========================================================================
// `dynamic initializer for 'tab_i_17_1''
// EA  : 0x83352990
// RVA : 0x01352990
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_17_1__(long double a1)
{
  double v1; // fp27
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp27
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp28
  long double v8; // fp2
  long double v9; // fp2
  double v10; // fp8
  double v11; // fp29
  long double v12; // fp2

  *(double *)&a1 = 0.3926990926265717;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.1963495463132858;
  tab_i_17_1.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 1.178097248077393;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.1963495463132858;
  tab_i_17_1.vector4_f32[1] = (float)((float)cos(x: v5) * (float)v4) * (float)0.25;
  *(double *)&v6 = 1.178097248077393;
  v7 = (float)cos(x: v6);
  *(double *)&v8 = 0.1963495463132858;
  v10 = (float)((float)((float)cos(x: v8) * (float)v7) * (float)0.25);
  *(double *)&v9 = 0.3926990926265717;
  tab_i_17_1.vector4_f32[2] = -v10;
  v11 = (float)cos(x: v9);
  *(double *)&v12 = 0.1963495463132858;
  tab_i_17_1.vector4_f32[3] = -(float)((float)((float)cos(x: v12) * (float)v11) * (float)0.25);
}


// ========================================================================
// `dynamic initializer for 'tab_i_17_2''
// EA  : 0x83352A88
// RVA : 0x01352A88
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_17_2__(long double a1)
{
  double v1; // fp28
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp28
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp10
  double v8; // fp28
  long double v9; // fp2
  long double v10; // fp2
  double v11; // fp7
  double v12; // fp31
  long double v13; // fp2

  *(double *)&a1 = 0.7853981852531433;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.1963495463132858;
  tab_i_17_2.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 0.7853981852531433;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.1963495463132858;
  v7 = (float)((float)((float)cos(x: v5) * (float)v4) * (float)0.25);
  *(double *)&v6 = 0.7853981852531433;
  tab_i_17_2.vector4_f32[1] = -v7;
  v8 = (float)cos(x: v6);
  *(double *)&v9 = 0.1963495463132858;
  v11 = (float)((float)((float)cos(x: v9) * (float)v8) * (float)0.25);
  *(double *)&v10 = 0.7853981852531433;
  tab_i_17_2.vector4_f32[2] = -v11;
  v12 = (float)cos(x: v10);
  *(double *)&v13 = 0.1963495463132858;
  tab_i_17_2.vector4_f32[3] = (float)((float)cos(x: v13) * (float)v12) * (float)0.25;
}


// ========================================================================
// `dynamic initializer for 'tab_i_17_3''
// EA  : 0x83352B78
// RVA : 0x01352B78
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_17_3__(long double a1)
{
  double v1; // fp27
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp27
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp10
  double v8; // fp28
  long double v9; // fp2
  long double v10; // fp2
  double v11; // fp29
  long double v12; // fp2

  *(double *)&a1 = 1.178097248077393;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.1963495463132858;
  tab_i_17_3.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 0.3926990926265717;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.1963495463132858;
  v7 = (float)((float)((float)cos(x: v5) * (float)v4) * (float)0.25);
  *(double *)&v6 = 0.3926990926265717;
  tab_i_17_3.vector4_f32[1] = -v7;
  v8 = (float)cos(x: v6);
  *(double *)&v9 = 0.1963495463132858;
  tab_i_17_3.vector4_f32[2] = (float)((float)cos(x: v9) * (float)v8) * (float)0.25;
  *(double *)&v10 = 1.178097248077393;
  v11 = (float)cos(x: v10);
  *(double *)&v12 = 0.1963495463132858;
  tab_i_17_3.vector4_f32[3] = -(float)((float)((float)cos(x: v12) * (float)v11) * (float)0.25);
}


// ========================================================================
// `dynamic initializer for 'tab_i_17_4''
// EA  : 0x83352C70
// RVA : 0x01352C70
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_17_4__(long double a1)
{
  double v1; // fp29
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp29
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp29
  long double v8; // fp2
  long double v9; // fp2
  double v10; // fp29
  long double v11; // fp2

  *(double *)&a1 = 0.1963495463132858;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.1963495463132858;
  tab_i_17_4.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(_QWORD *)&v3 = 0x3FE2D97C80000000LL;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.1963495463132858;
  tab_i_17_4.vector4_f32[1] = (float)((float)cos(x: v5) * (float)v4) * (float)0.25;
  *(_QWORD *)&v6 = 0x3FEF6A7A40000000LL;
  v7 = (float)cos(x: v6);
  *(double *)&v8 = 0.1963495463132858;
  tab_i_17_4.vector4_f32[2] = (float)((float)cos(x: v8) * (float)v7) * (float)0.25;
  *(_QWORD *)&v9 = 0x3FF5FDBC00000000LL;
  v10 = (float)cos(x: v9);
  *(double *)&v11 = 0.1963495463132858;
  tab_i_17_4.vector4_f32[3] = (float)((float)cos(x: v11) * (float)v10) * (float)0.25;
}


// ========================================================================
// `dynamic initializer for 'tab_i_17_5''
// EA  : 0x83352D60
// RVA : 0x01352D60
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_17_5__(long double a1)
{
  double v1; // fp29
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp29
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp10
  double v8; // fp29
  long double v9; // fp2
  long double v10; // fp2
  double v11; // fp7
  double v12; // fp29
  long double v13; // fp2

  *(_QWORD *)&a1 = 0x3FE2D97C80000000LL;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.1963495463132858;
  tab_i_17_5.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(_QWORD *)&v3 = 0x3FF5FDBC00000000LL;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.1963495463132858;
  v7 = (float)((float)((float)cos(x: v5) * (float)v4) * (float)0.25);
  *(double *)&v6 = 0.1963495463132858;
  tab_i_17_5.vector4_f32[1] = -v7;
  v8 = (float)cos(x: v6);
  *(double *)&v9 = 0.1963495463132858;
  v11 = (float)((float)((float)cos(x: v9) * (float)v8) * (float)0.25);
  *(_QWORD *)&v10 = 0x3FEF6A7A40000000LL;
  tab_i_17_5.vector4_f32[2] = -v11;
  v12 = (float)cos(x: v10);
  *(double *)&v13 = 0.1963495463132858;
  tab_i_17_5.vector4_f32[3] = -(float)((float)((float)cos(x: v13) * (float)v12) * (float)0.25);
}


// ========================================================================
// `dynamic initializer for 'tab_i_17_6''
// EA  : 0x83352E60
// RVA : 0x01352E60
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_17_6__(long double a1)
{
  double v1; // fp29
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp29
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp10
  double v8; // fp29
  long double v9; // fp2
  long double v10; // fp2
  double v11; // fp29
  long double v12; // fp2

  *(_QWORD *)&a1 = 0x3FEF6A7A40000000LL;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.1963495463132858;
  tab_i_17_6.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 0.1963495463132858;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.1963495463132858;
  v7 = (float)((float)((float)cos(x: v5) * (float)v4) * (float)0.25);
  *(_QWORD *)&v6 = 0x3FF5FDBC00000000LL;
  tab_i_17_6.vector4_f32[1] = -v7;
  v8 = (float)cos(x: v6);
  *(double *)&v9 = 0.1963495463132858;
  tab_i_17_6.vector4_f32[2] = (float)((float)cos(x: v9) * (float)v8) * (float)0.25;
  *(_QWORD *)&v10 = 0x3FE2D97C80000000LL;
  v11 = (float)cos(x: v10);
  *(double *)&v12 = 0.1963495463132858;
  tab_i_17_6.vector4_f32[3] = (float)((float)cos(x: v12) * (float)v11) * (float)0.25;
}


// ========================================================================
// `dynamic initializer for 'tab_i_17_7''
// EA  : 0x83352F58
// RVA : 0x01352F58
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_17_7__(long double a1)
{
  double v1; // fp29
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp29
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp10
  double v8; // fp29
  long double v9; // fp2
  long double v10; // fp2
  double v11; // fp29
  long double v12; // fp2

  *(_QWORD *)&a1 = 0x3FF5FDBC00000000LL;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.1963495463132858;
  tab_i_17_7.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(_QWORD *)&v3 = 0x3FEF6A7A40000000LL;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.1963495463132858;
  v7 = (float)((float)((float)cos(x: v5) * (float)v4) * (float)0.25);
  *(_QWORD *)&v6 = 0x3FE2D97C80000000LL;
  tab_i_17_7.vector4_f32[1] = -v7;
  v8 = (float)cos(x: v6);
  *(double *)&v9 = 0.1963495463132858;
  tab_i_17_7.vector4_f32[2] = (float)((float)cos(x: v9) * (float)v8) * (float)0.25;
  *(double *)&v10 = 0.1963495463132858;
  v11 = (float)cos(x: v10);
  *(double *)&v12 = 0.1963495463132858;
  tab_i_17_7.vector4_f32[3] = -(float)((float)((float)cos(x: v12) * (float)v11) * (float)0.25);
}


// ========================================================================
// `dynamic initializer for 'tab_i_26_0''
// EA  : 0x83353050
// RVA : 0x01353050
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_26_0__(long double a1)
{
  double v1; // fp28
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp28
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp28
  long double v8; // fp2
  long double v9; // fp2
  double v10; // fp31
  long double v11; // fp2

  *(double *)&a1 = 0.7853981852531433;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.3926990926265717;
  tab_i_26_0_0.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 0.7853981852531433;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.3926990926265717;
  tab_i_26_0_0.vector4_f32[1] = (float)((float)cos(x: v5) * (float)v4) * (float)0.25;
  *(double *)&v6 = 0.7853981852531433;
  v7 = (float)cos(x: v6);
  *(double *)&v8 = 0.3926990926265717;
  tab_i_26_0_0.vector4_f32[2] = (float)((float)cos(x: v8) * (float)v7) * (float)0.25;
  *(double *)&v9 = 0.7853981852531433;
  v10 = (float)cos(x: v9);
  *(double *)&v11 = 0.3926990926265717;
  tab_i_26_0_0.vector4_f32[3] = (float)((float)cos(x: v11) * (float)v10) * (float)0.25;
}


// ========================================================================
// `dynamic initializer for 'tab_i_26_1''
// EA  : 0x83353138
// RVA : 0x01353138
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_26_1__(long double a1)
{
  double v1; // fp28
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp28
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp29
  long double v8; // fp2
  long double v9; // fp2
  double v10; // fp8
  double v11; // fp29
  long double v12; // fp2

  *(double *)&a1 = 0.3926990926265717;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.3926990926265717;
  tab_i_26_1.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 1.178097248077393;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.3926990926265717;
  tab_i_26_1.vector4_f32[1] = (float)((float)cos(x: v5) * (float)v4) * (float)0.25;
  *(double *)&v6 = 1.178097248077393;
  v7 = (float)cos(x: v6);
  *(double *)&v8 = 0.3926990926265717;
  v10 = (float)((float)((float)cos(x: v8) * (float)v7) * (float)0.25);
  *(double *)&v9 = 0.3926990926265717;
  tab_i_26_1.vector4_f32[2] = -v10;
  v11 = (float)cos(x: v9);
  *(double *)&v12 = 0.3926990926265717;
  tab_i_26_1.vector4_f32[3] = -(float)((float)((float)cos(x: v12) * (float)v11) * (float)0.25);
}


// ========================================================================
// `dynamic initializer for 'tab_i_26_2''
// EA  : 0x83353228
// RVA : 0x01353228
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_26_2__(long double a1)
{
  double v1; // fp28
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp28
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp10
  double v8; // fp28
  long double v9; // fp2
  long double v10; // fp2
  double v11; // fp7
  double v12; // fp31
  long double v13; // fp2

  *(double *)&a1 = 0.7853981852531433;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.3926990926265717;
  tab_i_26_2.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 0.7853981852531433;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.3926990926265717;
  v7 = (float)((float)((float)cos(x: v5) * (float)v4) * (float)0.25);
  *(double *)&v6 = 0.7853981852531433;
  tab_i_26_2.vector4_f32[1] = -v7;
  v8 = (float)cos(x: v6);
  *(double *)&v9 = 0.3926990926265717;
  v11 = (float)((float)((float)cos(x: v9) * (float)v8) * (float)0.25);
  *(double *)&v10 = 0.7853981852531433;
  tab_i_26_2.vector4_f32[2] = -v11;
  v12 = (float)cos(x: v10);
  *(double *)&v13 = 0.3926990926265717;
  tab_i_26_2.vector4_f32[3] = (float)((float)cos(x: v13) * (float)v12) * (float)0.25;
}


// ========================================================================
// `dynamic initializer for 'tab_i_26_3''
// EA  : 0x83353318
// RVA : 0x01353318
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_26_3__(long double a1)
{
  double v1; // fp28
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp28
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp10
  double v8; // fp28
  long double v9; // fp2
  long double v10; // fp2
  double v11; // fp29
  long double v12; // fp2

  *(double *)&a1 = 1.178097248077393;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.3926990926265717;
  tab_i_26_3.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 0.3926990926265717;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.3926990926265717;
  v7 = (float)((float)((float)cos(x: v5) * (float)v4) * (float)0.25);
  *(double *)&v6 = 0.3926990926265717;
  tab_i_26_3.vector4_f32[1] = -v7;
  v8 = (float)cos(x: v6);
  *(double *)&v9 = 0.3926990926265717;
  tab_i_26_3.vector4_f32[2] = (float)((float)cos(x: v9) * (float)v8) * (float)0.25;
  *(double *)&v10 = 1.178097248077393;
  v11 = (float)cos(x: v10);
  *(double *)&v12 = 0.3926990926265717;
  tab_i_26_3.vector4_f32[3] = -(float)((float)((float)cos(x: v12) * (float)v11) * (float)0.25);
}


// ========================================================================
// `dynamic initializer for 'tab_i_26_4''
// EA  : 0x83353408
// RVA : 0x01353408
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_26_4__(long double a1)
{
  double v1; // fp29
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp29
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp29
  long double v8; // fp2
  long double v9; // fp2
  double v10; // fp29
  long double v11; // fp2

  *(_QWORD *)&a1 = 0x3FC921FB60000000LL;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.3926990926265717;
  tab_i_26_4.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(_QWORD *)&v3 = 0x3FE2D97C80000000LL;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.3926990926265717;
  tab_i_26_4.vector4_f32[1] = (float)((float)cos(x: v5) * (float)v4) * (float)0.25;
  *(_QWORD *)&v6 = 0x3FEF6A7A40000000LL;
  v7 = (float)cos(x: v6);
  *(double *)&v8 = 0.3926990926265717;
  tab_i_26_4.vector4_f32[2] = (float)((float)cos(x: v8) * (float)v7) * (float)0.25;
  *(_QWORD *)&v9 = 0x3FF5FDBC00000000LL;
  v10 = (float)cos(x: v9);
  *(double *)&v11 = 0.3926990926265717;
  tab_i_26_4.vector4_f32[3] = (float)((float)cos(x: v11) * (float)v10) * (float)0.25;
}


// ========================================================================
// `dynamic initializer for 'tab_i_26_5''
// EA  : 0x83353500
// RVA : 0x01353500
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_26_5__(long double a1)
{
  double v1; // fp29
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp29
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp10
  double v8; // fp29
  long double v9; // fp2
  long double v10; // fp2
  double v11; // fp7
  double v12; // fp29
  long double v13; // fp2

  *(_QWORD *)&a1 = 0x3FE2D97C80000000LL;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.3926990926265717;
  tab_i_26_5.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(_QWORD *)&v3 = 0x3FF5FDBC00000000LL;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.3926990926265717;
  v7 = (float)((float)((float)cos(x: v5) * (float)v4) * (float)0.25);
  *(_QWORD *)&v6 = 0x3FC921FB60000000LL;
  tab_i_26_5.vector4_f32[1] = -v7;
  v8 = (float)cos(x: v6);
  *(double *)&v9 = 0.3926990926265717;
  v11 = (float)((float)((float)cos(x: v9) * (float)v8) * (float)0.25);
  *(_QWORD *)&v10 = 0x3FEF6A7A40000000LL;
  tab_i_26_5.vector4_f32[2] = -v11;
  v12 = (float)cos(x: v10);
  *(double *)&v13 = 0.3926990926265717;
  tab_i_26_5.vector4_f32[3] = -(float)((float)((float)cos(x: v13) * (float)v12) * (float)0.25);
}


// ========================================================================
// `dynamic initializer for 'tab_i_26_6''
// EA  : 0x83353600
// RVA : 0x01353600
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_26_6__(long double a1)
{
  double v1; // fp29
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp29
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp10
  double v8; // fp29
  long double v9; // fp2
  long double v10; // fp2
  double v11; // fp29
  long double v12; // fp2

  *(_QWORD *)&a1 = 0x3FEF6A7A40000000LL;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.3926990926265717;
  tab_i_26_6.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(_QWORD *)&v3 = 0x3FC921FB60000000LL;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.3926990926265717;
  v7 = (float)((float)((float)cos(x: v5) * (float)v4) * (float)0.25);
  *(_QWORD *)&v6 = 0x3FF5FDBC00000000LL;
  tab_i_26_6.vector4_f32[1] = -v7;
  v8 = (float)cos(x: v6);
  *(double *)&v9 = 0.3926990926265717;
  tab_i_26_6.vector4_f32[2] = (float)((float)cos(x: v9) * (float)v8) * (float)0.25;
  *(_QWORD *)&v10 = 0x3FE2D97C80000000LL;
  v11 = (float)cos(x: v10);
  *(double *)&v12 = 0.3926990926265717;
  tab_i_26_6.vector4_f32[3] = (float)((float)cos(x: v12) * (float)v11) * (float)0.25;
}


// ========================================================================
// `dynamic initializer for 'tab_i_26_7''
// EA  : 0x833536F8
// RVA : 0x013536F8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_26_7__(long double a1)
{
  double v1; // fp29
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp29
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp10
  double v8; // fp29
  long double v9; // fp2
  long double v10; // fp2
  double v11; // fp29
  long double v12; // fp2

  *(_QWORD *)&a1 = 0x3FF5FDBC00000000LL;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.3926990926265717;
  tab_i_26_7.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(_QWORD *)&v3 = 0x3FEF6A7A40000000LL;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.3926990926265717;
  v7 = (float)((float)((float)cos(x: v5) * (float)v4) * (float)0.25);
  *(_QWORD *)&v6 = 0x3FE2D97C80000000LL;
  tab_i_26_7.vector4_f32[1] = -v7;
  v8 = (float)cos(x: v6);
  *(double *)&v9 = 0.3926990926265717;
  tab_i_26_7.vector4_f32[2] = (float)((float)cos(x: v9) * (float)v8) * (float)0.25;
  *(_QWORD *)&v10 = 0x3FC921FB60000000LL;
  v11 = (float)cos(x: v10);
  *(double *)&v12 = 0.3926990926265717;
  tab_i_26_7.vector4_f32[3] = -(float)((float)((float)cos(x: v12) * (float)v11) * (float)0.25);
}


// ========================================================================
// `dynamic initializer for 'tab_i_35_0''
// EA  : 0x833537F8
// RVA : 0x013537F8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_35_0__(long double a1)
{
  double v1; // fp28
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp28
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp28
  long double v8; // fp2
  long double v9; // fp2
  double v10; // fp31
  long double v11; // fp2

  *(double *)&a1 = 0.7853981852531433;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.5890486240386963;
  tab_i_35_0_0.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 0.7853981852531433;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.5890486240386963;
  tab_i_35_0_0.vector4_f32[1] = (float)((float)cos(x: v5) * (float)v4) * (float)0.25;
  *(double *)&v6 = 0.7853981852531433;
  v7 = (float)cos(x: v6);
  *(double *)&v8 = 0.5890486240386963;
  tab_i_35_0_0.vector4_f32[2] = (float)((float)cos(x: v8) * (float)v7) * (float)0.25;
  *(double *)&v9 = 0.7853981852531433;
  v10 = (float)cos(x: v9);
  *(double *)&v11 = 0.5890486240386963;
  tab_i_35_0_0.vector4_f32[3] = (float)((float)cos(x: v11) * (float)v10) * (float)0.25;
}


// ========================================================================
// `dynamic initializer for 'tab_i_35_1''
// EA  : 0x833538E0
// RVA : 0x013538E0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_35_1__(long double a1)
{
  double v1; // fp27
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp27
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp28
  long double v8; // fp2
  long double v9; // fp2
  double v10; // fp8
  double v11; // fp29
  long double v12; // fp2

  *(double *)&a1 = 0.3926990926265717;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.5890486240386963;
  tab_i_35_1.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 1.178097248077393;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.5890486240386963;
  tab_i_35_1.vector4_f32[1] = (float)((float)cos(x: v5) * (float)v4) * (float)0.25;
  *(double *)&v6 = 1.178097248077393;
  v7 = (float)cos(x: v6);
  *(double *)&v8 = 0.5890486240386963;
  v10 = (float)((float)((float)cos(x: v8) * (float)v7) * (float)0.25);
  *(double *)&v9 = 0.3926990926265717;
  tab_i_35_1.vector4_f32[2] = -v10;
  v11 = (float)cos(x: v9);
  *(double *)&v12 = 0.5890486240386963;
  tab_i_35_1.vector4_f32[3] = -(float)((float)((float)cos(x: v12) * (float)v11) * (float)0.25);
}


// ========================================================================
// `dynamic initializer for 'tab_i_35_2''
// EA  : 0x833539D8
// RVA : 0x013539D8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_35_2__(long double a1)
{
  double v1; // fp28
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp28
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp10
  double v8; // fp28
  long double v9; // fp2
  long double v10; // fp2
  double v11; // fp7
  double v12; // fp31
  long double v13; // fp2

  *(double *)&a1 = 0.7853981852531433;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.5890486240386963;
  tab_i_35_2.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 0.7853981852531433;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.5890486240386963;
  v7 = (float)((float)((float)cos(x: v5) * (float)v4) * (float)0.25);
  *(double *)&v6 = 0.7853981852531433;
  tab_i_35_2.vector4_f32[1] = -v7;
  v8 = (float)cos(x: v6);
  *(double *)&v9 = 0.5890486240386963;
  v11 = (float)((float)((float)cos(x: v9) * (float)v8) * (float)0.25);
  *(double *)&v10 = 0.7853981852531433;
  tab_i_35_2.vector4_f32[2] = -v11;
  v12 = (float)cos(x: v10);
  *(double *)&v13 = 0.5890486240386963;
  tab_i_35_2.vector4_f32[3] = (float)((float)cos(x: v13) * (float)v12) * (float)0.25;
}


// ========================================================================
// `dynamic initializer for 'tab_i_35_3''
// EA  : 0x83353AC8
// RVA : 0x01353AC8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_35_3__(long double a1)
{
  double v1; // fp27
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp27
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp10
  double v8; // fp28
  long double v9; // fp2
  long double v10; // fp2
  double v11; // fp29
  long double v12; // fp2

  *(double *)&a1 = 1.178097248077393;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.5890486240386963;
  tab_i_35_3.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 0.3926990926265717;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.5890486240386963;
  v7 = (float)((float)((float)cos(x: v5) * (float)v4) * (float)0.25);
  *(double *)&v6 = 0.3926990926265717;
  tab_i_35_3.vector4_f32[1] = -v7;
  v8 = (float)cos(x: v6);
  *(double *)&v9 = 0.5890486240386963;
  tab_i_35_3.vector4_f32[2] = (float)((float)cos(x: v9) * (float)v8) * (float)0.25;
  *(double *)&v10 = 1.178097248077393;
  v11 = (float)cos(x: v10);
  *(double *)&v12 = 0.5890486240386963;
  tab_i_35_3.vector4_f32[3] = -(float)((float)((float)cos(x: v12) * (float)v11) * (float)0.25);
}


// ========================================================================
// `dynamic initializer for 'tab_i_35_4''
// EA  : 0x83353BC0
// RVA : 0x01353BC0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_35_4__(long double a1)
{
  double v1; // fp29
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp29
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp29
  long double v8; // fp2
  long double v9; // fp2
  double v10; // fp29
  long double v11; // fp2

  *(_QWORD *)&a1 = 0x3FC921FB60000000LL;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.5890486240386963;
  tab_i_35_4.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 0.5890486240386963;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.5890486240386963;
  tab_i_35_4.vector4_f32[1] = (float)((float)cos(x: v5) * (float)v4) * (float)0.25;
  *(_QWORD *)&v6 = 0x3FEF6A7A40000000LL;
  v7 = (float)cos(x: v6);
  *(double *)&v8 = 0.5890486240386963;
  tab_i_35_4.vector4_f32[2] = (float)((float)cos(x: v8) * (float)v7) * (float)0.25;
  *(_QWORD *)&v9 = 0x3FF5FDBC00000000LL;
  v10 = (float)cos(x: v9);
  *(double *)&v11 = 0.5890486240386963;
  tab_i_35_4.vector4_f32[3] = (float)((float)cos(x: v11) * (float)v10) * (float)0.25;
}


// ========================================================================
// `dynamic initializer for 'tab_i_35_5''
// EA  : 0x83353CB0
// RVA : 0x01353CB0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_35_5__(long double a1)
{
  double v1; // fp29
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp29
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp10
  double v8; // fp29
  long double v9; // fp2
  long double v10; // fp2
  double v11; // fp7
  double v12; // fp29
  long double v13; // fp2

  *(double *)&a1 = 0.5890486240386963;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.5890486240386963;
  tab_i_35_5.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(_QWORD *)&v3 = 0x3FF5FDBC00000000LL;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.5890486240386963;
  v7 = (float)((float)((float)cos(x: v5) * (float)v4) * (float)0.25);
  *(_QWORD *)&v6 = 0x3FC921FB60000000LL;
  tab_i_35_5.vector4_f32[1] = -v7;
  v8 = (float)cos(x: v6);
  *(double *)&v9 = 0.5890486240386963;
  v11 = (float)((float)((float)cos(x: v9) * (float)v8) * (float)0.25);
  *(_QWORD *)&v10 = 0x3FEF6A7A40000000LL;
  tab_i_35_5.vector4_f32[2] = -v11;
  v12 = (float)cos(x: v10);
  *(double *)&v13 = 0.5890486240386963;
  tab_i_35_5.vector4_f32[3] = -(float)((float)((float)cos(x: v13) * (float)v12) * (float)0.25);
}


// ========================================================================
// `dynamic initializer for 'tab_i_35_6''
// EA  : 0x83353DB0
// RVA : 0x01353DB0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_35_6__(long double a1)
{
  double v1; // fp29
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp29
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp10
  double v8; // fp29
  long double v9; // fp2
  long double v10; // fp2
  double v11; // fp29
  long double v12; // fp2

  *(_QWORD *)&a1 = 0x3FEF6A7A40000000LL;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.5890486240386963;
  tab_i_35_6.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(_QWORD *)&v3 = 0x3FC921FB60000000LL;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.5890486240386963;
  v7 = (float)((float)((float)cos(x: v5) * (float)v4) * (float)0.25);
  *(_QWORD *)&v6 = 0x3FF5FDBC00000000LL;
  tab_i_35_6.vector4_f32[1] = -v7;
  v8 = (float)cos(x: v6);
  *(double *)&v9 = 0.5890486240386963;
  tab_i_35_6.vector4_f32[2] = (float)((float)cos(x: v9) * (float)v8) * (float)0.25;
  *(double *)&v10 = 0.5890486240386963;
  v11 = (float)cos(x: v10);
  *(double *)&v12 = 0.5890486240386963;
  tab_i_35_6.vector4_f32[3] = (float)((float)cos(x: v12) * (float)v11) * (float)0.25;
}


// ========================================================================
// `dynamic initializer for 'tab_i_35_7''
// EA  : 0x83353EA8
// RVA : 0x01353EA8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_i_35_7__(long double a1)
{
  double v1; // fp29
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp29
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp10
  double v8; // fp29
  long double v9; // fp2
  long double v10; // fp2
  double v11; // fp29
  long double v12; // fp2

  *(_QWORD *)&a1 = 0x3FF5FDBC00000000LL;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.5890486240386963;
  tab_i_35_7.vector4_f32[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(_QWORD *)&v3 = 0x3FEF6A7A40000000LL;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.5890486240386963;
  v7 = (float)((float)((float)cos(x: v5) * (float)v4) * (float)0.25);
  *(double *)&v6 = 0.5890486240386963;
  tab_i_35_7.vector4_f32[1] = -v7;
  v8 = (float)cos(x: v6);
  *(double *)&v9 = 0.5890486240386963;
  tab_i_35_7.vector4_f32[2] = (float)((float)cos(x: v9) * (float)v8) * (float)0.25;
  *(_QWORD *)&v10 = 0x3FC921FB60000000LL;
  v11 = (float)cos(x: v10);
  *(double *)&v12 = 0.5890486240386963;
  tab_i_35_7.vector4_f32[3] = -(float)((float)((float)cos(x: v12) * (float)v11) * (float)0.25);
}


// ========================================================================
// `dynamic initializer for 'vmx_float_tg_1_16''
// EA  : 0x83353FA0
// RVA : 0x01353FA0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void _dynamic_initializer_for__vmx_float_tg_1_16__()
{
  vmx_float_tg_1_16.vector4_f32[0] = tg_1_16_2;
  vmx_float_tg_1_16.vector4_f32[1] = tg_1_16_2;
  vmx_float_tg_1_16.vector4_f32[2] = tg_1_16_2;
  vmx_float_tg_1_16.vector4_f32[3] = tg_1_16_2;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_tg_2_16''
// EA  : 0x83353FC8
// RVA : 0x01353FC8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void _dynamic_initializer_for__vmx_float_tg_2_16__()
{
  vmx_float_tg_2_16.vector4_f32[0] = tg_2_16_2;
  vmx_float_tg_2_16.vector4_f32[1] = tg_2_16_2;
  vmx_float_tg_2_16.vector4_f32[2] = tg_2_16_2;
  vmx_float_tg_2_16.vector4_f32[3] = tg_2_16_2;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_tg_3_16''
// EA  : 0x83353FF0
// RVA : 0x01353FF0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void _dynamic_initializer_for__vmx_float_tg_3_16__()
{
  vmx_float_tg_3_16.vector4_f32[0] = tg_3_16_2;
  vmx_float_tg_3_16.vector4_f32[1] = tg_3_16_2;
  vmx_float_tg_3_16.vector4_f32[2] = tg_3_16_2;
  vmx_float_tg_3_16.vector4_f32[3] = tg_3_16_2;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_cos_4_16''
// EA  : 0x83354018
// RVA : 0x01354018
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\idct_ap922_float_xenon.cpp
// ========================================================================

void _dynamic_initializer_for__vmx_float_cos_4_16__()
{
  vmx_float_cos_4_16.vector4_f32[0] = cos_4_16_2;
  vmx_float_cos_4_16.vector4_f32[1] = cos_4_16_2;
  vmx_float_cos_4_16.vector4_f32[2] = cos_4_16_2;
  vmx_float_cos_4_16.vector4_f32[3] = cos_4_16_2;
}

