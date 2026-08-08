
// ========================================================================
// ?ScaleQuantTable_Xenon@idBareDctBase@@KAXPAGPBGH@Z
// EA  : 0x828E4EF0
// RVA : 0x008E4EF0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctbase_xenon.cpp
// ========================================================================

void __fastcall idBareDctBase::ScaleQuantTable_Xenon(
        unsigned __int16 *result,
        const unsigned __int16 *standard,
        const int scale)
{
  __int64 back_chain; // [sp+0h] [-10h] BYREF

  __asm
  {
    vspltisb  v0, 0
    lvx128    v13, r0, r4
  }
  _R5 = 16;
  _R6 = 32;
  __asm { vmrglh    v10, v0, v13 }
  _R7 = 48;
  __asm { vmrghh    v9, v0, v13 }
  __asm
  {
    lvx128    v12, r4, r5
    lvx128    v13, r4, r6
  }
  _R9 = &back_chain;
  __asm
  {
    vcuxwfp128 v63, v10, 0
    vmrglh    v8, v0, v12
    vcuxwfp128 v62, v9, 0
    lvx128    v11, r4, r7
    vmrghh    v7, v0, v12
  }
  __asm
  {
    vmrglh    v6, v0, v13
    vmrghh    v5, v0, v13
    vcuxwfp128 v60, v8, 0
    vmrglh    v4, v0, v11
  }
  __asm
  {
    vmrghh    v3, v0, v11
    vcuxwfp128 v59, v7, 0
  }
  __asm { vcuxwfp128 v58, v6, 0 }
  __asm { vcuxwfp128 v57, v5, 0 }
  _R11 = &vmx_float_one_12;
  __asm
  {
    vcuxwfp128 v56, v4, 0
    lvx128    v61, r0, r9
    vcuxwfp128 v55, v3, 0
    vmulfp128 v54, v95, v61
    lvx128    v63, r0, r11
    vmulfp128 v53, v94, v61
  }
  _R10 = 16;
  __asm { vmulfp128 v52, v92, v61 }
  _R8 = 64;
  __asm { vmulfp128 v51, v91, v61 }
  _R9 = 80;
  __asm
  {
    vmulfp128 v50, v90, v61
    vmulfp128 v49, v89, v61
    vmulfp128 v48, v88, v61
    lvx128    v62, r11, r10
    vmulfp128 v47, v87, v61
  }
  _R10 = 96;
  __asm { vmaxfp128 v46, v86, v63 }
  _R11 = 112;
  __asm
  {
    lvx128    v13, r4, r8
    lvx128    v12, r4, r9
    vmrglh    v2, v0, v13
    lvx128    v11, r4, r10
    vmrghh    v1, v0, v13
    vmaxfp128 v45, v85, v63
    lvx128    v10, r4, r11
    vmaxfp128 v44, v84, v63
    vmrglh    v31, v0, v12
    vmaxfp128 v43, v83, v63
    vmrghh    v30, v0, v12
    vmaxfp128 v42, v82, v63
    vmaxfp128 v41, v81, v63
    vmaxfp128 v40, v80, v63
    vmaxfp128 v39, v79, v63
    vminfp128 v38, v78, v62
    vminfp128 v37, v77, v62
    vminfp128 v36, v76, v62
    vminfp128 v35, v75, v62
    vminfp128 v34, v74, v62
    vminfp128 v33, v73, v62
    vminfp128 v32, v72, v62
    vminfp128 v60, v71, v62
    vcfpuxws128 v59, v38, 0
    vcfpuxws128 v58, v37, 0
    vmrglh    v29, v0, v11
    vcuxwfp128 v56, v2, 0
    vmrghh    v28, v0, v11
    vcuxwfp128 v55, v1, 0
    vmrglh    v27, v0, v10
    vcuxwfp128 v54, v31, 0
    vmrghh    v26, v0, v10
    vcuxwfp128 v53, v30, 0
    vcuxwfp128 v52, v29, 0
    vpkuhus128 v51, v90, v59
    vcuxwfp128 v50, v28, 0
    vcuxwfp128 v49, v27, 0
    vcuxwfp128 v48, v26, 0
    vcfpuxws128 v57, v36, 0
    vcfpuxws128 v47, v35, 0
    vcfpuxws128 v46, v34, 0
    vcfpuxws128 v44, v32, 0
    stvx128   v51, r0, r3
    vmulfp128 v43, v88, v61
    vmulfp128 v42, v87, v61
    vmulfp128 v41, v86, v61
    vmulfp128 v40, v85, v61
    vmulfp128 v39, v84, v61
    vmulfp128 v38, v82, v61
    vmulfp128 v37, v81, v61
    vmulfp128 v36, v80, v61
    vcfpuxws128 v35, v60, 0
    vpkuhus128 v34, v79, v57
    vcfpuxws128 v45, v33, 0
    vmaxfp128 v32, v75, v63
    vmaxfp128 v61, v74, v63
    vmaxfp128 v60, v73, v63
    vmaxfp128 v59, v72, v63
    vmaxfp128 v58, v71, v63
    stvx128   v34, r3, r5
    vmaxfp128 v57, v70, v63
    vmaxfp128 v56, v69, v63
    vmaxfp128 v55, v68, v63
    vpkuhus128 v54, v67, v44
    vpkuhus128 v33, v77, v46
    vminfp128 v53, v64, v62
    vminfp128 v52, v93, v62
    vminfp128 v51, v92, v62
    vminfp128 v50, v91, v62
    stvx128   v54, r3, r7
    vminfp128 v49, v90, v62
    stvx128   v33, r3, r6
    vminfp128 v48, v89, v62
    vminfp128 v47, v88, v62
    vminfp128 v46, v87, v62
    vcfpuxws128 v45, v53, 0
    vcfpuxws128 v44, v52, 0
    vcfpuxws128 v43, v51, 0
    vcfpuxws128 v42, v50, 0
    vcfpuxws128 v41, v49, 0
    vcfpuxws128 v40, v48, 0
    vcfpuxws128 v39, v47, 0
    vcfpuxws128 v38, v46, 0
    vpkuhus128 v37, v76, v45
    vpkuhus128 v36, v74, v43
    vpkuhus128 v35, v72, v41
    vpkuhus128 v34, v70, v39
    stvx128   v37, r3, r8
    stvx128   v36, r3, r9
    stvx128   v35, r3, r10
    stvx128   v34, r3, r11
  }
}


// ========================================================================
// ?SetQuality_Xenon@idBareDctBase@@QAAXHHH@Z
// EA  : 0x828E5140
// RVA : 0x008E5140
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctbase_xenon.cpp
// ========================================================================

void __fastcall idBareDctBase::SetQuality_Xenon(
        idBareDctBase *this,
        int luminanceQuality,
        int chrominanceQuality,
        int alphaQuality)
{
  int v7; // r28
  int v8; // r27
  int v9; // r29

  v7 = (unsigned __int16)idBareDctBase::QuantizationScaleFromQuality(quality: luminanceQuality);
  v8 = (unsigned __int16)idBareDctBase::QuantizationScaleFromQuality(quality: chrominanceQuality);
  v9 = (unsigned __int16)idBareDctBase::QuantizationScaleFromQuality(quality: alphaQuality);
  idBareDctBase::ScaleQuantTable_Xenon(result: this->quantTableY, standard: std_luminance_quant_tbl_0, scale: v7);
  idBareDctBase::ScaleQuantTable_Xenon(result: this->quantTableCoCg, standard: std_chrominance_quant_tbl_0, scale: v8);
  idBareDctBase::ScaleQuantTable_Xenon(result: this->quantTableA, standard: std_alpha_quant_tbl_0, scale: v9);
}

