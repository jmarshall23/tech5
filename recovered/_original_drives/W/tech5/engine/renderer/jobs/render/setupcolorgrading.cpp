
// ========================================================================
// ?SetupColorGrading@@YAXPBUsetupColorGradingParms_t@@@Z
// EA  : 0x828E4568
// RVA : 0x008E4568
// PDB : w:\tech5\engine\renderer\jobs\render\setupcolorgrading.cpp
// ========================================================================

void __fastcall SetupColorGrading(const setupColorGradingParms_t *parms)
{
  unsigned int v3; // r11
  double v4; // fp0
  idImage *imageLUT; // r8
  int v18; // r9
  unsigned int v23; // r11
  unsigned int v25; // ctr

  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_SETUP_COLOR_GRADING);
  v3 = _S5;
  if ( (_S5 & 1) != 0 )
  {
    v4 = fscale;
  }
  else
  {
    v3 = _S5 | 1;
    _S5 |= 1u;
    v4 = 0.000020504936;
    fscale = 0.000020504936;
  }
  _R5 = &SIMD_SP_fscale;
  if ( (v3 & 2) == 0 )
  {
    SIMD_SP_fscale.vector4_f32[0] = v4;
    SIMD_SP_fscale.vector4_f32[1] = v4;
    SIMD_SP_fscale.vector4_f32[2] = v4;
    _S5 = v3 | 2;
    SIMD_SP_fscale.vector4_f32[3] = v4;
  }
  _R4 = &_vmx_3f8000003f8000003f8000003f800000;
  _R7 = &SIMD_SP_epsilon;
  __asm { lvx128    v62, r0, r4 }
  _R11 = renderThreadParmState;
  _R4 = 16 * (parms->rpCGColorDodgeBlend->parmIndex + 3);
  _R10 = 16 * (parms->rpCGColorBurnBlend->parmIndex + 3);
  __asm { lvx128    v63, r0, r7 }
  _R6 = &_vmx_3f8000003f8000003f8000003f800000;
  __asm { lvx128    v61, r4, r11 }
  _R4 = 16 * (parms->rpCGColorScreenBlend->parmIndex + 3);
  __asm
  {
    vsubfp128 v60, v94, v61
    lvx128    v59, r10, r11
    vaddfp128 v6, v91, v63
    lvx128    v1, r0, r6
  }
  _R29 = &_vmx_00000000000000000000000000000000;
  __asm { lvx128    v58, r4, r11 }
  __asm { vsubfp128 v57, v94, v58 }
  _R28 = 16 * (parms->rpCGColorMultiplyBlend->parmIndex + 3);
  __asm { lvx128    v61, r0, r29 }
  imageLUT = parms->imageLUT;
  _R3 = 16 * (parms->rpCGHighlight->parmIndex + 3);
  __asm { lvx128    v56, r28, r11 }
  __asm { vaddfp128 v5, v92, v63 }
  _R10 = 16 * (parms->rpCGShadow->parmIndex + 3);
  __asm { vrefp     v9, v6 }
  v18 = imageLUT->opts.height * imageLUT->opts.width;
  __asm { vrefp     v8, v5 }
  __asm
  {
    vnmsubfp  v4, v9, v1, v6
    lvx128    v13, r3, r11
  }
  _R3 = &SIMD_SP_1_over_255;
  __asm { lvx128    v0, r10, r11 }
  _R27 = &_vmx_000000003f8000004000000040400000;
  _R7 = 16 * (parms->rpCGMidtone->parmIndex + 3);
  __asm
  {
    vcmpgefp128 v11, v0, v61
    vcmpgefp128 v10, v13, v61
  }
  __asm
  {
    lvx128    v63, r0, r27
    lvx128    v12, r7, r11
    vnmsubfp  v6, v8, v1, v5
    vmaddfp   v9, v4, v9, v9
    vmaddfp   v8, v6, v8, v8
    vmulfp128 v55, v94, v9
    vmulfp128 v54, v94, v8
    vmulfp128 v53, v89, v55
    vmulfp128 v52, v86, v56
    vsubfp128 v9, v94, v53
    lvx128    v62, r0, r3
    vmulfp128 v51, v84, v53
    vmulfp128 v8, v94, v51
  }
  _R8 = (char *)imageLUT->lockRect[0].pBits;
  if ( v18 > 0 )
  {
    __asm { lvx128    v61, r0, r5 }
    v23 = (unsigned int)(v18 - 1) >> 2;
    _R9 = &`VertexColorToByteWithScale'::`2'::SIMD_SP_255;
    __asm { lvx128    v62, r0, r9 }
    v25 = v23 + 1;
    _R11 = &SIMD_SP_4;
    _R7 = &SIMD_2_over_3;
    _R5 = &SIMD_SP_16;
    _R4 = &SIMD_SP_256;
    __asm { lvx128    v54, r0, r11 }
    _R3 = &SIMD_SP_272;
    _R11 = &SIMD_1_over_3;
    _R9 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
    __asm
    {
      lvx128    v55, r0, r7
      lvx128    v56, r0, r5
      lvx128    v57, r0, r4
      lvx128    v58, r0, r3
      lvx128    v59, r0, r11
      lvx128    v60, r0, r9
    }
    while ( 1 )
    {
      __asm
      {
        vsubfp128 v4, v90, v63
        vspltw128 v21, v63, 3
        vaddfp128 v2, v95, v56
        vspltw128 v22, v63, 2
        vsubfp128 v50, v95, v60
        vspltw128 v23, v63, 1
        vsubfp128 v49, v89, v63
        vrefp     v7, v4
        vrefp     v6, v2
        vmulfp128 v48, v82, v50
        vnmsubfp  v31, v7, v1, v4
        vnmsubfp  v5, v6, v1, v2
        vmulfp128 v47, v80, v61
        vmaddfp   v4, v31, v7, v7
        vmaddfp   v6, v5, v6, v6
        vsubfp128 v46, v91, v47
        vsubfp128 v45, v87, v47
        vmulfp128 v44, v81, v4
        vmulfp128 v43, v95, v6
        vspltw128 v7, v46, 3
        vspltw128 v29, v46, 2
        vspltw128 v31, v46, 1
        vspltw128 v1, v46, 3
        vspltw128 v3, v46, 2
        vspltw128 v6, v46, 1
        vspltw128 v24, v45, 3
        vspltw128 v25, v45, 2
        vspltw128 v26, v45, 1
        vspltw128 v5, v46, 0
        vspltw128 v27, v44, 3
        vspltw128 v28, v44, 2
        vspltw128 v30, v44, 1
        vspltw128 v2, v43, 3
        vsel      v20, v27, v7, v11
        vspltw128 v4, v43, 2
        vsel      v27, v28, v29, v11
        vspltw128 v7, v43, 1
        vsel      v29, v30, v31, v11
        vsel      v30, v1, v2, v10
        vmaddfp   v31, v20, v21, v0
        vsel      v1, v3, v4, v10
        vmaddfp   v2, v27, v22, v0
        vsel      v3, v6, v7, v10
        vmaddfp   v7, v29, v23, v0
        vrfiz     v4, v31
        vrfiz     v6, v2
        vspltw128 v2, v63, 0
        vrfiz     v7, v7
        vaddfp128 v63, v95, v54
        vmaddfp   v4, v24, v4, v12
        vmaddfp   v6, v25, v6, v12
        vmaddfp   v7, v26, v7, v12
        vrfiz     v4, v4
        vrfiz     v6, v6
        vrfiz     v7, v7
        vmaddfp   v4, v30, v4, v13
        vmaddfp   v6, v1, v6, v13
        vmaddfp   v7, v3, v7, v13
        vspltw128 v3, v45, 0
        vrfiz     v4, v4
        vrfiz     v6, v6
        vrfiz     v7, v7
        vmaddfp   v4, v4, v9, v8
        vmaddfp   v6, v6, v9, v8
        vmaddfp   v7, v7, v9, v8
        vmulfp128 v42, v4, v62
        vspltw128 v4, v44, 0
        vmulfp128 v41, v6, v62
        vspltw128 v6, v46, 0
        vmulfp128 v40, v7, v62
        vspltw128 v7, v43, 0
        vsel      v1, v4, v5, v11
        vsel      v5, v6, v7, v10
        vmaddfp   v4, v1, v2, v0
        vcfpsxws128 v39, v42, 0
        vcfpsxws128 v38, v41, 0
        vcfpsxws128 v34, v40, 0
        vrfiz     v7, v4
        vpermwi128 v37, v39, 0x93
        vpermwi128 v36, v38, 0x93
        vpkswss128 v35, v68, v37
        vmaddfp   v7, v3, v7, v12
        vpermwi128 v33, v34, 0x93
        vrfiz     v7, v7
        vmaddfp   v7, v5, v7, v13
        vrfiz     v7, v7
        vmaddfp   v7, v7, v9, v8
        vmulfp128 v32, v7, v62
        vcfpsxws128 v53, v32, 0
        vpermwi128 v52, v53, 0x93
        vpkswss128 v51, v84, v33
        vpkshus128 v50, v83, v35
        stvx128   v50, r0, r8
      }
      _R8 += 16;
      if ( --v25 == 0 )
        break;
      __asm { lvx128    v1, r0, r6 }
    }
  }
  idDeclRenderParm::SetImage(this: parms->rpColorGradingLUT, image: parms->imageLUT);
  idRenderLog::CloseMainBlock(this: &renderLog);
}

