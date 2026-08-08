
// ========================================================================
// ?Multiply@idRenderMatrix@@SAXABV1@0AAV1@@Z
// EA  : 0x82F1F758
// RVA : 0x00F1F758
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

void __fastcall idRenderMatrix::Multiply(const idRenderMatrix *a, const idRenderMatrix *b, idRenderMatrix *out)
{
  _R9 = 16;
  __asm { lvlx128   v63, r0, r3 }
  _R10 = 32;
  __asm { lvlx128   v62, r0, r4 }
  _R11 = 48;
  _R8 = 64;
  __asm
  {
    lvrx128   v61, r9, r3
    lvrx128   v60, r10, r3
    vor128    v59, v95, v61
    lvlx128   v58, r9, r3
    lvrx128   v57, r11, r3
    vor128    v56, v90, v60
    lvlx128   v55, r10, r3
    lvrx128   v54, r9, r4
    vor128    v53, v87, v57
    lvrx128   v52, r8, r3
    vor128    v51, v94, v54
    lvlx128   v50, r11, r3
    vspltw128 v49, v59, 0
    vor128    v48, v82, v52
    vspltw128 v47, v56, 0
    vspltw128 v46, v53, 0
    lvrx128   v45, r10, r4
    lvlx128   v44, r9, r4
    vspltw128 v12, v59, 1
    vmulfp128 v11, v81, v51
    vor128    v0, v76, v45
    vspltw128 v43, v48, 0
    vmulfp128 v8, v79, v51
    vmulfp128 v31, v78, v51
    vspltw128 v10, v56, 1
    vspltw128 v1, v53, 1
    lvrx128   v42, r11, r4
    vspltw128 v29, v48, 1
    lvlx128   v41, r10, r4
    vmulfp128 v4, v75, v51
    vor128    v13, v73, v42
    vspltw128 v30, v59, 2
    lvrx128   v40, r8, r4
    vspltw128 v5, v56, 2
    lvlx128   v39, r11, r4
    vspltw128 v6, v53, 2
    vspltw128 v7, v59, 3
    vspltw128 v9, v56, 3
    vmaddfp   v3, v12, v11, v0
    vor128    v12, v71, v40
    vmaddfp   v2, v10, v8, v0
    vspltw128 v8, v48, 2
    vmaddfp   v1, v1, v31, v0
    vspltw128 v10, v53, 3
    vspltw128 v11, v48, 3
    vmaddfp   v0, v29, v4, v0
    vmaddfp   v3, v30, v3, v13
    vmaddfp   v5, v5, v2, v13
    vmaddfp   v6, v6, v1, v13
    vmaddfp   v0, v8, v0, v13
    vmaddfp   v7, v7, v3, v12
    vmaddfp   v9, v9, v5, v12
    vmaddfp   v13, v10, v6, v12
    vmaddfp   v0, v11, v0, v12
    stvlx     v7, r0, r5
    stvrx     v7, r5, r9
    stvlx     v9, r5, r9
    stvrx     v9, r5, r10
    stvlx     v13, r5, r10
    stvrx     v13, r5, r11
    stvlx     v0, r5, r11
    stvrx     v0, r5, r8
  }
}


// ========================================================================
// ?InverseByDoubles@idRenderMatrix@@SA_NABV1@AAV1@@Z
// EA  : 0x82F1F870
// RVA : 0x00F1F870
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

int __fastcall idRenderMatrix::InverseByDoubles(const idRenderMatrix *src, idRenderMatrix *out)
{
  double v2; // fp0
  double v3; // fp13
  double v4; // fp6
  double v5; // fp7
  double v6; // fp11
  double v7; // fp31
  double v8; // fp10
  double v9; // fp9
  double v10; // fp3
  double v11; // fp24
  double v12; // fp1
  double v13; // fp12
  double v14; // fp27
  double v15; // fp29
  double v16; // fp2
  double v17; // fp30
  double v18; // fp22
  double v19; // fp8
  double v20; // fp21
  double v21; // fp5
  double v22; // fp20
  double v23; // fp19
  double v24; // fp25
  double v25; // fp23
  double v26; // fp10
  double v27; // fp9
  double v28; // fp18
  double v29; // fp0
  double v30; // fp19
  double v31; // fp7
  double v32; // fp8
  double v33; // fp4
  double v34; // fp28
  double v35; // fp9
  double v36; // fp25
  double v37; // fp11
  double v39; // fp16
  double v40; // fp13
  double v41; // fp18
  double v42; // fp6
  double v43; // [sp+10h] [-D0h]
  double v44; // [sp+20h] [-C0h]
  double v45; // [sp+28h] [-B8h]
  double v46; // [sp+38h] [-A8h]
  double v47; // [sp+40h] [-A0h]

  v2 = src->m[5];
  v3 = src->m[3];
  v4 = src->m[4];
  v5 = src->m[2];
  v6 = src->m[1];
  v7 = src->m[12];
  v8 = src->m[6];
  v9 = src->m[7];
  v10 = src->m[0];
  v11 = src->m[14];
  v12 = src->m[10];
  v13 = v9 * v6 - v3 * v2;
  v14 = src->m[13];
  v15 = src->m[9];
  v16 = v8 * v10 - v5 * v4;
  v17 = v10 * v2 - v6 * v4;
  v43 = v9 * v10 - v3 * v4;
  v18 = src->m[15];
  v19 = v9 * v5 - v3 * v8;
  v20 = src->m[8];
  v44 = v19;
  v21 = v8 * v6 - v5 * v2;
  v22 = src->m[11];
  v45 = v11 * v4 - v7 * v8;
  v46 = v11 * v10 - v7 * v5;
  v23 = v14 * v8;
  v24 = v18 * v4 - v7 * v9;
  v25 = v18 * v2 - v14 * v9;
  v26 = v18 * v8 - v11 * v9;
  v27 = v20 * v19 - v12 * v43;
  v28 = v7 * v2;
  v29 = v11 * v2 - v23;
  v30 = v15 * v24;
  v31 = v11 * v6 - v14 * v5;
  v47 = v22 * v21 + v15 * v19 - v12 * v13;
  v32 = v22 * v17 + v20 * v13 - v15 * v43;
  v33 = v12 * v17 + v20 * v21 - v15 * v16;
  v34 = v12 * v24;
  v35 = v22 * v16 + v27;
  v36 = v14 * v10 - v7 * v6;
  v37 = v18 * v6 - v14 * v3;
  v39 = v18 * v10 - v7 * v3;
  v40 = v18 * src->m[2] - v11 * v3;
  v41 = v14 * v4 - v28;
  v42 = 1.0 / (v18 * v33 - (v11 * v32 - (v14 * v35 - v7 * v47)));
  out->m[4] = (v22 * v45 + v20 * v26 - v34) * v42;
  out->m[12] = (v12 * v41 + v20 * v29 - v15 * v45) * v42;
  out->m[1] = (v22 * v31 + v15 * v40 - v12 * v37) * v42;
  out->m[8] = -((v22 * v41 + v20 * v25 - v30) * v42);
  out->m[0] = -((v22 * v29 + v15 * v26 - v12 * v25) * v42);
  out->m[9] = (v22 * v36 + v20 * v37 - v15 * v39) * v42;
  out->m[13] = -((v12 * v36 + v20 * v31 - v15 * v46) * v42);
  out->m[5] = -((v22 * v46 + v20 * v40 - v12 * v39) * v42);
  out->m[14] = -((v11 * v17 + v7 * v21 - v14 * v16) * v42);
  out->m[10] = (v18 * v17 + v7 * v13 - v14 * v43) * v42;
  out->m[2] = (v18 * v21 + v14 * v44 - v11 * v13) * v42;
  out->m[6] = -((v18 * v16 + v7 * v44 - v11 * v43) * v42);
  out->m[7] = v42 * v35;
  out->m[11] = -(v42 * v32);
  out->m[3] = -(v42 * v47);
  out->m[15] = v42 * v33;
  return 1;
}


// ========================================================================
// ?BuildProjection@idRenderMatrix@@SAXMMMMMMAAV1@@Z
// EA  : 0x82F1FBC0
// RVA : 0x00F1FBC0
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

void __fastcall idRenderMatrix::BuildProjection(
        double xMin,
        double xMax,
        double yMin,
        double yMax,
        double zNear,
        double zFar,
        idRenderMatrix *out,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        float *a13)
{
  double v13; // fp8
  double v14; // fp3

  v13 = (float)((float)yMin + (float)yMax);
  a13[1] = 0.0;
  a13[3] = 0.0;
  v14 = (float)((float)1.0 / (float)((float)yMax - (float)yMin));
  a13[4] = 0.0;
  a13[7] = 0.0;
  a13[8] = 0.0;
  a13[9] = 0.0;
  *a13 = (float)((float)1.0 / (float)((float)xMax - (float)xMin)) * (float)((float)zNear * (float)2.0);
  a13[2] = (float)((float)xMin + (float)xMax) * (float)((float)1.0 / (float)((float)xMax - (float)xMin));
  a13[5] = (float)v14 * (float)((float)zNear * (float)2.0);
  a13[6] = (float)v13 * (float)v14;
  if ( zFar > zNear )
  {
    a13[12] = 0.0;
    a13[13] = 0.0;
    a13[14] = -1.0;
    a13[15] = 0.0;
    a13[10] = -(float)((float)zFar / (float)((float)zFar - (float)zNear));
    a13[11] = -(float)((float)((float)zNear * (float)zFar) / (float)((float)zFar - (float)zNear));
  }
  else
  {
    a13[10] = -1.0;
    a13[11] = -zNear;
    a13[12] = 0.0;
    a13[13] = 0.0;
    a13[14] = -1.0;
    a13[15] = 0.0;
  }
}


// ========================================================================
// ?BuildProjectionFov@idRenderMatrix@@SAXMMMMMMAAV1@@Z
// EA  : 0x82F1FC90
// RVA : 0x00F1FC90
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

void __fastcall idRenderMatrix::BuildProjectionFov(
        long double yFovDegrees,
        double zNear,
        double zFar,
        double xOffset,
        double yOffset,
        idRenderMatrix *out,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        float *a12)
{
  double v12; // fp30
  long double v18; // fp2
  double v19; // fp12
  double v20; // fp30
  long double v21; // fp2
  int v22; // r8
  int v23; // r7
  int v24; // r6
  int v25; // r5
  int v26; // r4
  idRenderMatrix *v27; // r3

  v12 = *((double *)&yFovDegrees + 1);
  *(double *)&yFovDegrees = (float)((float)(idMath::M_DEG2RAD * (float)*(double *)&yFovDegrees) * (float)0.5);
  v18 = tan(x: yFovDegrees);
  v19 = (float)(idMath::M_DEG2RAD * (float)v12);
  v20 = (float)((float)*(double *)&v18 * (float)zNear);
  *(double *)&v18 = (float)((float)v19 * (float)0.5);
  v21 = tan(x: v18);
  idRenderMatrix::BuildProjection(
    xMin: (float)((float)-v20 + (float)xOffset),
    xMax: (float)((float)v20 + (float)xOffset),
    yMin: (float)((float)-(float)((float)*(double *)&v21 * (float)zNear) + (float)yOffset),
    yMax: (float)((float)((float)*(double *)&v21 * (float)zNear) + (float)yOffset),
    zNear,
    zFar,
    out: v27,
    a8: v26,
    a9: v25,
    a10: v24,
    a11: v23,
    a12: v22,
    a13: a12);
}


// ========================================================================
// ?OffsetScaleForBounds@idRenderMatrix@@SAXABV1@ABVidBounds@@AAV1@@Z
// EA  : 0x82F1FD48
// RVA : 0x00F1FD48
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

void __fastcall idRenderMatrix::OffsetScaleForBounds(
        const idRenderMatrix *src,
        const idBounds *bounds,
        idRenderMatrix *out)
{
  _R11 = 16;
  __asm { lvlx128   v63, r0, r4 }
  _R10 = 24;
  __asm { vspltisw128 v61, 0 }
  _R9 = 8;
  __asm { lvlx128   v60, r0, r3 }
  _R7 = 64;
  __asm { lvrx128   v59, r11, r4 }
  _R6 = vectori_float_keep_last;
  __asm
  {
    lvrx128   v57, r10, r4
    vor128    v58, v95, v59
    lvlx128   v56, r9, r4
  }
  _R9 = 32;
  __asm { vor128    v55, v88, v57 }
  _R10 = 48;
  __asm { lvrx128   v54, r11, r3 }
  _R8 = 64;
  __asm
  {
    vrlimi128 v58, v61, 1, 0
    lvx128    v62, r6, r7
    lvlx128   v53, r11, r3
    vor128    v13, v92, v54
    vsldoi128 v52, v87, v61, 4
    lvrx128   v51, r9, r3
    lvrx128   v50, r10, r3
    vor128    v12, v85, v51
    lvlx128   v49, r9, r3
  }
  _R4 = 128;
  __asm
  {
    lvrx128   v48, r8, r3
    vor128    v11, v81, v50
    vaddfp128 v46, v84, v58
    lvlx128   v47, r10, r3
    vsubfp128 v45, v84, v58
    vor128    v10, v79, v48
    lvx128    v63, r0, r6
    lvx128    v61, r6, r4
    vmulfp128 v44, v78, v62
    vmulfp128 v43, v77, v62
    vmsum3fp128 v42, v13, v44
    vmsum3fp128 v41, v12, v44
    vor128    v0, v75, v61
    vmsum3fp128 v40, v11, v44
    vmsum3fp128 v39, v10, v44
    vand128   v9, v74, v63
    vand128   v8, v73, v63
    vand128   v7, v72, v63
    vand128   v6, v71, v63
    vmaddfp   v13, v13, v9, v0
    vmaddfp   v12, v12, v8, v0
    vmaddfp   v11, v11, v7, v0
    vmaddfp   v0, v10, v6, v0
    stvlx     v13, r0, r5
    stvrx     v13, r5, r11
    stvlx     v12, r5, r11
    stvrx     v12, r5, r9
    stvlx     v11, r5, r9
    stvrx     v11, r5, r10
    stvlx     v0, r5, r10
    stvrx     v0, r5, r8
  }
}


// ========================================================================
// ?InverseOffsetScaleForBounds@idRenderMatrix@@SAXABV1@ABVidBounds@@AAV1@@Z
// EA  : 0x82F1FE38
// RVA : 0x00F1FE38
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

void __fastcall idRenderMatrix::InverseOffsetScaleForBounds(
        const idRenderMatrix *src,
        const idBounds *bounds,
        idRenderMatrix *out)
{
  _R11 = 16;
  __asm { lvlx128   v63, r0, r4 }
  _R10 = 24;
  __asm { vspltisw128 v61, 0 }
  _R9 = 8;
  __asm { lvlx128   v60, r0, r3 }
  _R7 = 80;
  __asm { lvrx128   v59, r11, r4 }
  _R6 = vectori_float_keep_last;
  __asm
  {
    lvrx128   v57, r10, r4
    vor128    v58, v95, v59
    lvlx128   v56, r9, r4
  }
  _R4 = 96;
  __asm { vor128    v55, v88, v57 }
  _R10 = 32;
  _R9 = 48;
  __asm
  {
    lvrx128   v54, r11, r3
    vrlimi128 v58, v61, 1, 0
    lvx128    v62, r6, r7
    lvx128    v63, r0, r6
    vor128    v7, v92, v54
    vsldoi128 v53, v87, v61, 4
    lvx128    v10, r6, r4
    lvrx128   v52, r10, r3
  }
  _R8 = 64;
  __asm
  {
    lvlx128   v51, r11, r3
    lvrx128   v50, r9, r3
    vor128    v6, v83, v52
    vsubfp128 v47, v90, v53
    lvlx128   v49, r10, r3
    vaddfp128 v45, v85, v58
    vor128    v9, v81, v50
    lvlx128   v48, r9, r3
    lvrx128   v46, r8, r3
    vor128    v44, v80, v46
    vmulfp128 v11, v79, v62
    vmulfp128 v43, v77, v62
    vrefp     v0, v11
    vnmsubfp  v8, v0, v10, v11
    vmaddfp   v0, v8, v0, v0
    vnmsubfp  v12, v0, v10, v11
    vmaddfp   v0, v12, v0, v0
    vmulfp128 v42, v75, v0
    vspltw    v10, v0, 0
    vspltw    v12, v0, 1
    vspltw    v0, v0, 2
    vspltw128 v41, v42, 0
    vspltw128 v40, v42, 1
    vspltw128 v39, v42, 2
    vand128   v11, v73, v63
    vand128   v8, v72, v63
    vand128   v13, v71, v63
    vmaddfp   v11, v7, v11, v10
    vmaddfp   v12, v6, v8, v12
    vmaddfp   v0, v9, v13, v0
    stvlx     v11, r0, r5
    stvrx     v11, r5, r11
    stvlx     v12, r5, r11
    stvrx     v12, r5, r10
    stvlx     v0, r5, r10
    stvrx     v0, r5, r9
    stvlx128  v44, r5, r9
    stvrx128  v44, r5, r8
  }
}


// ========================================================================
// ?Inverse@idRenderMatrix@@SA_NABV1@AAV1@@Z
// EA  : 0x82F1FF40
// RVA : 0x00F1FF40
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

int __fastcall idRenderMatrix::Inverse(const idRenderMatrix *src, idRenderMatrix *out)
{
  char v8; // cr56

  _R9 = 16;
  __asm { lvlx128   v63, r0, r3 }
  _R10 = 32;
  __asm { vspltisw128 v62, 0xF }
  _R11 = 48;
  __asm { vspltisw128 v61, 2 }
  _R8 = 64;
  __asm { vspltisw128 v60, 0 }
  __asm
  {
    lvrx128   v59, r9, r3
    lvrx128   v58, r10, r3
    vor128    v57, v95, v59
    lvlx128   v56, r9, r3
    vslw128   v55, v93, v62
    vor128    v54, v88, v58
    lvrx128   v53, r11, r3
    lvlx128   v52, r10, r3
  }
  _R6 = &vector_float_inverse_epsilon;
  __asm
  {
    lvrx128   v51, r8, r3
    vsldoi128 v10, v89, v57, 0xC
    lvlx128   v50, r11, r3
    vor128    v49, v84, v53
    vsldoi128 v48, v86, v54, 4
    vor128    v47, v82, v51
    vsldoi128 v46, v89, v57, 4
    vslw128   v45, v87, v62
    vsldoi128 v9, v86, v54, 8
    vsldoi128 v0, v81, v49, 0xC
    vmulfp128 v13, v10, v48
    vsldoi128 v7, v79, v47, 8
    vsldoi128 v8, v81, v49, 8
    vsldoi128 v6, v79, v47, 0xC
    vmulfp128 v44, v78, v9
    vsldoi128 v5, v79, v47, 4
    vmulfp128 v43, v0, v7
    vsldoi128 v4, v89, v57, 8
    vsldoi128 v3, v86, v54, 0xC
    vmulfp128 v42, v8, v6
    vsldoi128 v2, v81, v49, 4
    vmulfp128 v12, v0, v5
    vmrghw128 v41, v92, v45
    vmulfp128 v11, v4, v48
    vmrghw128 v40, v77, v60
    vsldoi128 v39, v13, v13, 8
    vmulfp128 v27, v76, v6
    vsldoi128 v1, v76, v44, 4
    vmulfp128 v20, v76, v0
    vmulfp128 v26, v71, v7
    vsldoi128 v31, v75, v43, 0xC
    vmulfp128 v25, v80, v43
    vmulfp128 v24, v80, v42
    vsldoi128 v30, v74, v42, 0xC
    vmulfp128 v23, v78, v43
    vsldoi    v29, v12, v12, v8
    vmulfp128 v22, v78, v42
    vsldoi    v28, v11, v11, v4
    vmulfp128 v21, v71, v8
    vmaddfp   v27, v1, v27, v5
    vmaddfp   v6, v11, v26, v6
    vmaddfp   v26, v9, v25, v29
    vmaddfp   v9, v9, v24, v12
    vmaddfp   v29, v4, v23, v29
    vmaddfp   v12, v4, v22, v12
    vmaddfp   v0, v11, v21, v0
    vmaddfp   v11, v1, v20, v2
    vmaddfp   v7, v13, v27, v7
    vmaddfp   v6, v28, v6, v5
    vmaddfp   v5, v3, v26, v31
    vmaddfp   v9, v3, v9, v30
    vmaddfp   v4, v10, v29, v31
    vmaddfp   v12, v10, v12, v30
    vmaddfp   v0, v28, v0, v2
    vmaddfp   v13, v13, v11, v8
    vsubfp128 v38, v7, v6
    vsubfp128 v37, v9, v5
    vsubfp128 v36, v12, v4
    vsubfp128 v35, v13, v0
    vxor128   v60, v70, v41
    vxor128   v63, v69, v41
    vxor128   v59, v68, v40
    vmulfp128 v34, v89, v63
    vsldoi128 v33, v66, v34, 4
    lvx128    v61, r0, r6
    vxor128   v58, v67, v40
    vaddfp128 v32, v66, v33
    vsldoi128 v62, v64, v32, 8
    vaddfp128 v62, v94, v32
    vandc128  v57, v94, v45
    vcmpgefp128. v56, v93, v57
  }
  if ( v8 != 0 )
    return 0;
  __asm
  {
    vrefp128  v55, v62
    vmrghw128 v54, v95, v60
    vmrghw128 v53, v91, v58
  }
  __asm
  {
    vmrglw128 v52, v95, v60
    vmrglw128 v51, v91, v58
    vmrghw128 v50, v86, v53
    vmrglw128 v49, v86, v53
    vmrghw128 v48, v84, v51
    vmrglw128 v47, v84, v51
    vaddfp128 v12, v87, v55
    vor128    v13, v87, v55
    vmulfp128 v0, v94, v55
    vnmsubfp  v12, v0, v12, v13
    vmulfp128 v46, v82, v12
    vmulfp128 v45, v81, v12
    vmulfp128 v44, v80, v12
    vmulfp128 v43, v79, v12
    stvlx128  v46, r0, r4
    stvrx128  v46, r4, r9
    stvlx128  v45, r4, r9
    stvrx128  v45, r4, r10
    stvlx128  v44, r4, r10
    stvrx128  v44, r4, r11
    stvlx128  v43, r4, r11
    stvrx128  v43, r4, r8
  }
  return 1;
}


// ========================================================================
// ?InverseByTranspose@idRenderMatrix@@SAXABV1@AAV1@@Z
// EA  : 0x82F20120
// RVA : 0x00F20120
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

void __fastcall idRenderMatrix::InverseByTranspose(const idRenderMatrix *src, idRenderMatrix *out)
{
  double v2; // fp6

  out->m[0] = src->m[0];
  out->m[4] = src->m[1];
  out->m[8] = src->m[2];
  out->m[12] = 0.0;
  out->m[1] = src->m[4];
  out->m[5] = src->m[5];
  out->m[9] = src->m[6];
  out->m[13] = 0.0;
  out->m[2] = src->m[8];
  out->m[6] = src->m[9];
  out->m[10] = src->m[10];
  out->m[14] = 0.0;
  out->m[3] = -(float)((float)(src->m[3] * src->m[0])
                     + (float)((float)(src->m[4] * src->m[7]) + (float)(src->m[11] * src->m[8])));
  out->m[7] = -(float)((float)(src->m[7] * src->m[5])
                     + (float)((float)(src->m[11] * src->m[9]) + (float)(src->m[1] * src->m[3])));
  v2 = (float)-(float)((float)(src->m[10] * src->m[11])
                     + (float)((float)(src->m[7] * src->m[6]) + (float)(src->m[3] * src->m[2])));
  out->m[15] = 1.0;
  out->m[11] = v2;
}


// ========================================================================
// ?CopyMatrix@idRenderMatrix@@SAXABV1@AAVidVec4@@111@Z
// EA  : 0x82F20208
// RVA : 0x00F20208
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

void __fastcall idRenderMatrix::CopyMatrix(
        const idRenderMatrix *matrix,
        idVec4 *row0,
        idVec4 *row1,
        idVec4 *row2,
        idVec4 *row3)
{
  _R9 = 16;
  __asm { lvlx128   v63, r0, r3 }
  _R10 = 32;
  _R11 = 48;
  _R8 = 64;
  __asm
  {
    lvrx128   v62, r9, r3
    lvrx128   v61, r10, r3
    vor128    v60, v95, v62
    lvlx128   v59, r9, r3
    lvrx128   v58, r11, r3
    vor128    v57, v91, v61
    lvlx128   v56, r10, r3
    lvrx128   v55, r8, r3
    vor128    v54, v88, v58
    lvlx128   v53, r11, r3
    vor128    v52, v85, v55
    stvx128   v60, r0, r4
    stvx128   v57, r0, r5
    stvx128   v54, r0, r6
    stvx128   v52, r0, r7
  }
}


// ========================================================================
// ?SetMVP@idRenderMatrix@@SAXABV1@AAVidVec4@@111AA_N@Z
// EA  : 0x82F20260
// RVA : 0x00F20260
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

void __fastcall idRenderMatrix::SetMVP(
        const idRenderMatrix *mvp,
        idVec4 *row0,
        idVec4 *row1,
        idVec4 *row2,
        idVec4 *row3,
        bool *negativeDeterminant)
{
  unsigned __int8 v11; // cr56
  unsigned __int8 v12; // cr57

  _R9 = 48;
  __asm { vspltisw128 v63, 0xF }
  _R10 = 32;
  __asm { vspltisw128 v62, 2 }
  _R31 = 64;
  __asm { vspltisw128 v61, 0 }
  _R11 = 16;
  __asm
  {
    lvlx128   v60, r0, r3
    lvrx128   v59, r9, r3
    vslw128   v58, v94, v63
    lvlx128   v57, r10, r3
    lvrx128   v56, r31, r3
    vor128    v55, v89, v59
    lvlx128   v54, r9, r3
    vor128    v53, v86, v56
    lvrx128   v52, r10, r3
    lvlx128   v51, r11, r3
    vslw128   v50, v90, v63
    vsldoi128 v49, v87, v55, 8
    vor128    v48, v83, v52
    vsldoi128 v47, v87, v55, 0xC
    lvrx128   v46, r11, r3
    vsldoi128 v45, v85, v53, 0xC
    vor128    v44, v92, v46
    vsldoi128 v43, v85, v53, 8
    vsldoi128 v42, v85, v53, 4
    vsldoi128 v41, v80, v48, 4
    vmulfp128 v40, v81, v45
    vsldoi128 v13, v80, v48, 8
    vmulfp128 v39, v79, v43
    vsldoi128 v12, v80, v48, 0xC
    vmulfp128 v0, v79, v42
    vmrghw128 v38, v93, v50
    stvx128   v44, r0, r4
    stvx128   v48, r0, r5
    stvx128   v55, r0, r6
    stvx128   v53, r0, r7
    vmulfp128 v11, v73, v40
    vsldoi128 v8, v72, v40, 0xC
    vmulfp128 v10, v73, v39
    vsldoi128 v7, v71, v39, 0xC
    vsldoi    v9, v0, v0, v8
    vmaddfp   v0, v13, v11, v0
    vmaddfp   v13, v13, v10, v9
    vmaddfp   v0, v12, v0, v8
    vmaddfp   v13, v12, v13, v7
    vsubfp128 v37, v0, v13
    vxor128   v36, v69, v38
    vmulfp128 v35, v76, v36
    vsldoi128 v34, v67, v35, 4
    vaddfp128 v33, v67, v34
    vsldoi128 v32, v65, v33, 8
    vaddfp128 v63, v64, v33
    vcmpgefp128. v62, v93, v63
  }
  *negativeDeterminant = (((v11 << 7) | (v12 << 6)) & 0x80) != 0;
}


// ========================================================================
// ?SetMVPForBounds@idRenderMatrix@@SAXABV1@ABVidBounds@@AAVidVec4@@222AA_N@Z
// EA  : 0x82F20350
// RVA : 0x00F20350
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

void __fastcall idRenderMatrix::SetMVPForBounds(
        const idRenderMatrix *mvp,
        const idBounds *bounds,
        idVec4 *row0,
        idVec4 *row1,
        idVec4 *row2,
        idVec4 *row3,
        bool *negativeDeterminant)
{
  unsigned __int8 v17; // cr56
  unsigned __int8 v18; // cr57

  _R11 = 16;
  __asm { lvlx128   v63, r0, r4 }
  _R10 = 24;
  __asm { vspltisw128 v60, 0 }
  _R31 = 8;
  __asm { lvlx128   v59, r0, r3 }
  __asm { vspltisw128 v58, 0xF }
  _R29 = -64;
  __asm
  {
    vspltisw128 v57, 2
    lvrx128   v56, r11, r4
  }
  _R30 = &vector_float_last_one;
  __asm
  {
    lvrx128   v54, r10, r4
    vor128    v55, v95, v56
    lvlx128   v53, r31, r4
  }
  _R4 = 48;
  __asm { vor128    v52, v85, v54 }
  _R10 = 32;
  _R31 = 64;
  __asm
  {
    lvlx128   v51, r11, r3
    vrlimi128 v55, v60, 1, 0
    lvx128    v62, r30, r29
    lvrx128   v50, r11, r3
  }
  _R11 = -128;
  __asm
  {
    vsldoi128 v49, v84, v60, 4
    lvrx128   v48, r4, r3
    lvlx128   v47, r10, r3
    vor128    v9, v91, v50
    lvrx128   v46, r31, r3
    vor128    v0, v79, v48
    lvlx128   v45, r4, r3
    vslw128   v41, v89, v58
    vaddfp128 v43, v81, v55
    vor128    v13, v77, v46
    vsubfp128 v42, v81, v55
    lvrx128   v44, r10, r3
    vor128    v10, v83, v44
    lvx128    v63, r30, r11
    lvx128    v61, r0, r30
    vslw128   v40, v73, v58
    vmrghw128 v39, v92, v40
    vmulfp128 v38, v75, v62
    vmulfp128 v37, v74, v62
    vmsum3fp128 v36, v0, v38
    vmsum3fp128 v35, v13, v38
    vor128    v11, v69, v61
    vmsum3fp128 v34, v10, v38
    vmsum3fp128 v33, v9, v38
    vand128   v12, v68, v63
    vand128   v8, v67, v63
    vand128   v7, v66, v63
    vand128   v6, v65, v63
    vmaddfp   v12, v0, v12, v11
    vmaddfp   v0, v13, v8, v11
    vmaddfp   v13, v10, v7, v11
    vmaddfp   v11, v9, v6, v11
    vsldoi128 v32, v12, v12, 8
    vsldoi128 v63, v0, v0, 0xC
    vsldoi128 v62, v0, v0, 8
    vsldoi128 v61, v12, v12, 0xC
    stvx128   v11, r0, r5
    vsldoi128 v59, v0, v0, 4
    stvx128   v13, r0, r6
    vmulfp128 v58, v64, v63
    stvx128   v12, r0, r7
    vsldoi128 v57, v13, v13, 4
    stvx128   v0, r0, r8
    vmulfp128 v56, v93, v62
    vsldoi    v12, v13, v13, v8
    vsldoi    v10, v13, v13, v12
    vmulfp128 v13, v93, v59
    vmulfp128 v0, v89, v58
    vsldoi128 v7, v90, v58, 0xC
    vmulfp128 v9, v89, v56
    vsldoi128 v6, v88, v56, 0xC
    vsldoi    v8, v13, v13, v8
    vmaddfp   v0, v12, v0, v13
    vmaddfp   v13, v12, v9, v8
    vmaddfp   v0, v10, v0, v7
    vmaddfp   v13, v10, v13, v6
    vsubfp128 v55, v0, v13
    vxor128   v54, v87, v39
    vmulfp128 v53, v11, v54
    vsldoi128 v52, v85, v53, 4
    vaddfp128 v51, v85, v52
    vsldoi128 v50, v83, v51, 8
    vaddfp128 v49, v82, v51
    vcmpgefp128. v48, v92, v49
  }
  *negativeDeterminant = (((v17 << 7) | (v18 << 6)) & 0x80) != 0;
}


// ========================================================================
// ?SetMVPForInverseProject@idRenderMatrix@@SAXABV1@0AAVidVec4@@111AA_N@Z
// EA  : 0x82F204C8
// RVA : 0x00F204C8
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

void __fastcall idRenderMatrix::SetMVPForInverseProject(
        const idRenderMatrix *mvp,
        const idRenderMatrix *inverseProject,
        idVec4 *row0,
        idVec4 *row1,
        idVec4 *row2,
        idVec4 *row3,
        bool *negativeDeterminant)
{
  unsigned __int8 v14; // cr56
  unsigned __int8 v15; // cr57

  _R30 = inverseProject;
  __asm { lvlx128   v63, r0, r3 }
  _R31 = mvp;
  __asm { vspltisw128 v61, 0xF }
  _R4 = 16;
  __asm { vspltisw128 v60, 2 }
  _R10 = 32;
  _R11 = 48;
  _R3 = 64;
  __asm
  {
    lvlx128   v62, r0, r30
    lvlx128   v59, r4, r31
    lvrx128   v58, r10, r31
    lvrx128   v55, r11, r31
    vor128    v56, v91, v58
    lvlx128   v53, r10, r31
    lvrx128   v57, r4, r31
    vor128    v51, v85, v55
    vor128    v54, v95, v57
    lvrx128   v47, r4, r30
    lvrx128   v52, r3, r31
    vor128    v46, v94, v47
    lvlx128   v50, r11, r31
    vspltw128 v49, v56, 0
    vor128    v48, v82, v52
    vspltw128 v44, v51, 0
    vspltw128 v45, v54, 0
    lvrx128   v43, r10, r30
    lvlx128   v42, r4, r30
    vspltw128 v9, v56, 1
    vmulfp128 v8, v81, v46
    vor128    v0, v74, v43
    vspltw128 v41, v48, 0
    vmulfp128 v6, v76, v46
    vmulfp128 v11, v77, v46
    vspltw128 v7, v51, 1
    vspltw128 v12, v54, 1
    lvrx128   v40, r11, r30
    vspltw128 v5, v48, 1
    lvlx128   v39, r10, r30
    vmulfp128 v4, v73, v46
    vor128    v13, v71, v40
    vspltw128 v1, v51, 2
    lvrx128   v38, r3, r30
    vspltw128 v3, v54, 2
    lvlx128   v37, r11, r30
    vspltw128 v31, v48, 2
    vspltw128 v2, v56, 2
    vspltw128 v28, v51, 3
    vspltw128 v30, v54, 3
    vmaddfp   v9, v9, v8, v0
    vspltw128 v29, v56, 3
    vmaddfp   v8, v7, v6, v0
    vmaddfp   v10, v12, v11, v0
    vor128    v12, v69, v38
    vspltw128 v11, v48, 3
    vmaddfp   v0, v5, v4, v0
    vmaddfp   v9, v2, v9, v13
    vmaddfp   v8, v1, v8, v13
    vmaddfp   v10, v3, v10, v13
    vmaddfp   v0, v31, v0, v13
    vmaddfp   v9, v29, v9, v12
    vmaddfp   v13, v28, v8, v12
    vmaddfp   v10, v30, v10, v12
    vmaddfp   v0, v11, v0, v12
    vsldoi128 v34, v9, v9, 4
    vmr128    v35, v13
    vsldoi    v13, v9, v9, v8
    vmr128    v36, v10
    vsldoi    v12, v9, v9, v12
    vsldoi128 v33, v67, v35, 0xC
    vsldoi128 v32, v0, v0, 0xC
    stvx128   v36, r0, r5
    vsldoi128 v62, v0, v0, 8
    stvx128   v9, r0, r6
    vsldoi128 v63, v67, v35, 8
    stvx128   v35, r0, r7
    vsldoi128 v59, v0, v0, 4
    stvx128   v0, r0, r8
    vmulfp128 v57, v65, v62
    vmulfp128 v58, v95, v32
    vmulfp128 v0, v65, v59
    vmulfp128 v7, v66, v58
    vsldoi    v9, v0, v0, v8
    vmulfp128 v8, v66, v57
    vsldoi128 v10, v90, v58, 0xC
    vsldoi128 v11, v89, v57, 0xC
    vslw128   v56, v92, v61
    vspltisw128 v55, 0
    vslw128   v54, v88, v61
    vmrghw128 v53, v87, v54
    vmaddfp   v7, v13, v7, v0
    vmaddfp   v0, v13, v8, v9
    vmaddfp   v13, v12, v7, v10
    vmaddfp   v0, v12, v0, v11
    vsubfp128 v52, v13, v0
    vxor128   v51, v84, v53
    vmulfp128 v50, v68, v51
    vsldoi128 v49, v82, v50, 4
    vaddfp128 v48, v82, v49
    vsldoi128 v47, v80, v48, 8
    vaddfp128 v46, v79, v48
    vcmpgefp128. v45, v87, v46
  }
  *negativeDeterminant = (((v14 << 7) | (v15 << 6)) & 0x80) != 0;
}


// ========================================================================
// ?CullPointToMVPbits@idRenderMatrix@@SA_NABV1@ABVidVec3@@PAE_N@Z
// EA  : 0x82F20680
// RVA : 0x00F20680
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

int __fastcall idRenderMatrix::CullPointToMVPbits(
        const idRenderMatrix *mvp,
        const idVec3 *p,
        unsigned __int8 *outBits,
        bool zeroToOne)
{
  double v4; // fp13
  double v5; // fp10
  double v6; // fp11
  double v7; // fp12
  double v8; // fp0
  int v9; // r11

  v4 = (float)((float)((float)(p->x * mvp->m[0]) + (float)((float)(mvp->m[1] * p->y) + (float)(mvp->m[2] * p->z)))
             + mvp->m[3]);
  v5 = (float)((float)((float)(mvp->m[10] * p->z) + (float)((float)(mvp->m[8] * p->x) + (float)(mvp->m[9] * p->y)))
             + mvp->m[11]);
  v6 = (float)((float)((float)(mvp->m[6] * p->z) + (float)((float)(mvp->m[4] * p->x) + (float)(mvp->m[5] * p->y)))
             + mvp->m[7]);
  v7 = (float)((float)((float)(mvp->m[14] * p->z) + (float)((float)(mvp->m[12] * p->x) + (float)(mvp->m[13] * p->y)))
             + mvp->m[15]);
  if ( zeroToOne )
    v8 = 0.0;
  else
    v8 = -v7;
  v9 = v4 > v8;
  if ( v4 < v7 )
    v9 |= 2u;
  if ( v6 > v8 )
    v9 |= 4u;
  if ( v6 < v7 )
    v9 |= 8u;
  if ( v5 > v8 )
    v9 |= 0x10u;
  if ( v5 < v7 )
    v9 |= 0x20u;
  *outBits = v9 ^ 0x3F;
  return -63 - ((v9 == 63) - 64);
}


// ========================================================================
// ?CullBoundsToMVPbits@idRenderMatrix@@SA_NABV1@ABVidBounds@@PAE_N@Z
// EA  : 0x82F20790
// RVA : 0x00F20790
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

BOOL __fastcall idRenderMatrix::CullBoundsToMVPbits(
        const idRenderMatrix *mvp,
        const idBounds *b,
        unsigned __int8 *outBits,
        bool zeroToOne)
{
  unsigned __int8 v21; // cr58
  unsigned __int8 v22; // cr59

  _R10 = 16;
  __asm { lvlx128   v63, r0, r3 }
  _R11 = &mvp->m[4];
  _R9 = &mvp->m[8];
  _R8 = &mvp->m[12];
  __asm
  {
    lvrx128   v62, r10, r3
    lvlx128   v61, r0, r11
    vor128    v62, v95, v62
    lvrx128   v58, r10, r11
  }
  __asm { lvlx128   v60, r0, r9 }
  _R11 = vectori_word_perm0;
  __asm
  {
    lvrx128   v57, r10, r9
    lvlx128   v59, r0, r8
    vor128    v61, v93, v58
    lvrx128   v56, r10, r8
    vor128    v60, v92, v57
    vor128    v59, v91, v56
  }
  _R9 = &vector_float_zero_0;
  if ( !zeroToOne )
    _R9 = &vector_float_neg_one;
  _R8 = 24;
  __asm { lvrx128   v54, r10, r4 }
  _R7 = 8;
  __asm
  {
    lvlx128   v55, r0, r4
    vspltisw128 v53, 0
    vor128    v63, v87, v54
  }
  _R6 = 16;
  __asm
  {
    lvx128    v7, r0, r11
    vspltw128 v5, v59, 3
    lvx128    v52, r0, r9
    lvrx128   v51, r8, r4
    vspltw128 v4, v59, 0
    lvlx128   v50, r7, r4
    vrlimi128 v63, v53, 1, 0
    vor128    v49, v82, v51
    vspltw128 v2, v60, 3
    lvx128    v6, r11, r6
    vspltw128 v1, v60, 0
    vspltw128 v31, v61, 3
  }
  _R4 = 128;
  __asm { vspltw128 v30, v61, 0 }
  _R3 = 96;
  __asm { vsldoi128 v58, v81, v53, 4 }
  _R10 = 80;
  __asm { vspltw128 v29, v62, 3 }
  _R9 = 64;
  __asm { vspltw128 v28, v62, 0 }
  _R8 = 48;
  __asm { vspltw128 v27, v59, 1 }
  _R7 = 112;
  __asm
  {
    vperm128  v12, v95, v58, v7
    lvx128    v57, r11, r4
    vperm128  v11, v95, v58, v6
    lvx128    v56, r11, r3
    vspltw128 v26, v60, 1
    vspltw128 v25, v61, 1
    vmaddfp   v6, v12, v5, v4
    vspltw128 v3, v62, 1
    vmaddfp   v4, v12, v2, v1
    vspltw128 v13, v63, 2
    vmaddfp   v2, v12, v31, v30
    vspltw128 v0, v58, 2
    vmaddfp   v12, v12, v29, v28
    vspltw128 v10, v59, 2
    vspltw128 v9, v60, 2
    lvx128    v60, r11, r8
    vspltw128 v8, v61, 2
    lvx128    v61, r11, r9
    vspltw128 v7, v62, 2
    lvx128    v62, r11, r10
    lvx128    v63, r11, r7
    vmaddfp   v5, v11, v6, v27
    vmaddfp   v4, v11, v4, v26
    vmaddfp   v6, v11, v2, v25
    vmaddfp   v12, v11, v12, v3
    vmaddfp   v2, v13, v5, v10
    vmaddfp   v3, v0, v5, v10
    vmaddfp   v5, v13, v4, v9
    vmaddfp   v9, v0, v4, v9
    vmaddfp   v10, v13, v6, v8
    vmaddfp   v11, v0, v6, v8
    vmaddfp   v13, v13, v12, v7
    vmaddfp   v0, v0, v12, v7
    vmulfp128 v48, v2, v52
    vmulfp128 v47, v3, v52
    vcmpgtfp128 v46, v2, v5
    vcmpgtfp128 v45, v3, v9
    vcmpgtfp128 v44, v2, v10
    vcmpgtfp128 v43, v3, v11
    vcmpgtfp128 v42, v2, v13
    vcmpgtfp128 v41, v3, v0
    vcmpgtfp128 v40, v5, v48
    vcmpgtfp128 v39, v9, v47
    vand128   v38, v78, v57
    vcmpgtfp128 v37, v11, v47
    vand128   v36, v77, v57
    vcmpgtfp128 v35, v10, v48
    vcmpgtfp128 v34, v0, v47
    vand128   v32, v76, v56
    vcmpgtfp128 v33, v13, v48
    vand128   v59, v75, v56
    vand128   v58, v69, v62
  }
  _R6 = 32;
  __asm
  {
    vand128   v57, v67, v62
    vand128   v56, v73, v61
    vand128   v55, v74, v61
    vand128   v50, v66, v60
    vand128   v49, v65, v60
    vand128   v54, v72, v63
    vand128   v53, v71, v63
    lvx128    v63, r11, r6
    vor128    v52, v64, v59
    vor128    v51, v89, v58
    vor128    v48, v87, v56
    vor128    v45, v81, v50
    vor128    v47, v70, v36
    vor128    v46, v86, v53
    vor128    v44, v83, v52
    vor128    v42, v77, v48
    vor128    v43, v78, v47
    vor128    v41, v74, v44
    vor128    v40, v73, v43
    vsldoi128 v39, v72, v40, 4
    vor128    v38, v72, v39
    vsldoi128 v37, v70, v38, 8
    vor128    v36, v70, v37
    vcmpequw128. v35, v68, v63
  }
  __asm { vxor128   v34, v68, v63 }
  __asm
  {
    vpkuhus128 v33, v66, v34
    vpkuwus128 v0, v65, v33
    stvebx    v0, 0, r5
  }
  return ((32 * v21) & 0x20 | (16 * v22) & 0x20) != 0;
}


// ========================================================================
// ?CullExtrudedBoundsToMVPbits@idRenderMatrix@@SA_NABV1@ABVidBounds@@ABVidVec3@@ABVidPlane@@PAE_N@Z
// EA  : 0x82F209B8
// RVA : 0x00F209B8
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

BOOL __fastcall idRenderMatrix::CullExtrudedBoundsToMVPbits(
        const idRenderMatrix *mvp,
        const idBounds *b,
        const idVec3 *extrudeDirection,
        const idPlane *clipPlane,
        unsigned __int8 *outBits,
        bool zeroToOne)
{
  unsigned __int8 v27; // cr58
  unsigned __int8 v28; // cr59

  _R10 = 16;
  __asm { lvlx128   v63, r0, r3 }
  _R11 = &mvp->m[4];
  _R9 = &mvp->m[8];
  _R31 = &mvp->m[12];
  __asm
  {
    lvrx128   v62, r10, r3
    lvlx128   v61, r0, r11
    vor128    v62, v95, v62
    lvrx128   v58, r10, r11
  }
  __asm { lvlx128   v60, r0, r9 }
  _R11 = vectori_word_perm0;
  __asm
  {
    lvlx128   v59, r0, r31
    lvrx128   v57, r10, r9
    vor128    v61, v93, v58
    lvrx128   v56, r10, r31
    vor128    v60, v92, v57
    vor128    v59, v91, v56
  }
  _R3 = &vector_float_zero_0;
  if ( !zeroToOne )
    _R3 = &vector_float_neg_one;
  _R9 = 8;
  __asm { lvrx128   v54, r10, r4 }
  _R8 = 24;
  __asm
  {
    lvlx128   v55, r0, r4
    vspltisw128 v53, 0
    vor128    v63, v87, v54
    lvx128    v0, r0, r11
    vspltw128 v2, v59, 3
    vspltw128 v1, v59, 0
  }
  _R10 = 16;
  __asm
  {
    lvlx128   v52, r9, r4
    vspltw128 v27, v60, 3
    lvrx128   v51, r8, r4
    vrlimi128 v63, v53, 1, 0
    vor128    v50, v84, v51
    vspltw128 v26, v60, 0
    vspltw128 v31, v62, 3
    lvx128    v44, r0, r3
    vspltw128 v30, v62, 0
    lvx128    v7, r11, r10
    vspltw128 v29, v61, 3
  }
  _R8 = 4;
  __asm { vsldoi128 v58, v82, v53, 4 }
  _R3 = 12;
  __asm { vspltw128 v28, v61, 0 }
  _R4 = 256;
  __asm { vspltw128 v25, v59, 1 }
  _R10 = 144;
  __asm
  {
    vspltw128 v22, v60, 1
    lvlx128   v49, r0, r6
    vperm128  v0, v95, v58, v0
    lvlx128   v48, r0, r5
    vperm128  v13, v95, v58, v7
    lvlx128   v47, r8, r6
    vspltw128 v24, v62, 1
    lvlx128   v46, r9, r6
    vspltw128 v23, v61, 1
    lvlx128   v45, r8, r5
    vmaddfp   v21, v0, v2, v1
    vspltw128 v11, v63, 2
    vmaddfp   v18, v0, v27, v26
    vspltw128 v10, v59, 2
    vmaddfp   v20, v0, v31, v30
    vspltw128 v7, v60, 2
    vmaddfp   v19, v0, v29, v28
    vspltw128 v12, v58, 2
    vspltw128 v9, v62, 2
    lvlx128   v43, r9, r5
    vspltw128 v8, v61, 2
    lvlx128   v34, r3, r6
    lvx128    v63, r11, r10
    vspltw128 v4, v49, 0
    vspltw128 v3, v47, 0
    vspltw128 v6, v46, 0
    vspltw128 v5, v48, 0
    vmaddfp   v21, v13, v21, v25
    vmaddfp   v18, v13, v18, v22
    vmaddfp   v20, v13, v20, v24
    vmaddfp   v19, v13, v19, v23
    vmaddfp   v17, v11, v21, v10
    vmaddfp   v14, v11, v18, v7
    vmaddfp   v21, v12, v21, v10
    vmaddfp   v18, v12, v18, v7
    vmaddfp   v16, v11, v20, v9
    vmaddfp   v15, v11, v19, v8
    vmaddfp   v20, v12, v20, v9
    vmaddfp   v19, v12, v19, v8
    vmr128    v42, v17
    vmr128    v41, v21
    vspltw128 v21, v45, 0
    vmr128    v38, v18
    lvx128    v18, r11, r4
    vmr128    v40, v16
    vmulfp128 v39, v74, v44
    vcmpgtfp128 v33, v74, v14
    vmr128    v36, v20
    vmulfp128 v37, v73, v44
    vmr128    v35, v19
    vspltw128 v20, v43, 0
    vspltw128 v19, v34, 0
    vcmpgtfp128 v32, v73, v38
    vmulfp128 v17, v6, v20
  }
  _R9 = 128;
  __asm { vmaddfp   v19, v3, v19, v13 }
  _R8 = 96;
  __asm { vcmpgtfp128 v55, v74, v15 }
  _R6 = 64;
  __asm { vcmpgtfp128 v50, v15, v39 }
  _R4 = 80;
  __asm { vcmpgtfp128 v56, v73, v35 }
  _R3 = 48;
  __asm { vcmpgtfp128 v54, v73, v36 }
  _R5 = 112;
  __asm
  {
    vcmpgtfp128 v53, v74, v40
    lvx128    v61, r11, r8
    lvx128    v59, r11, r6
    vcmpgtfp128 v51, v67, v37
    vcmpgtfp128 v57, v70, v37
    lvx128    v60, r11, r4
    vcmpgtfp128 v37, v68, v37
    lvx128    v58, r11, r3
    vcmpgtfp128 v52, v14, v39
    vcmpgtfp128 v36, v72, v39
    vmaddfp   v17, v3, v17, v21
    vmaddfp   v3, v4, v19, v0
    vand128   v35, v88, v61
    vand128   v56, v86, v59
    vand128   v54, v85, v59
    vmaddfp   v4, v4, v17, v5
    vmaddfp   v17, v6, v3, v11
    vmaddfp   v16, v6, v3, v12
    vrefp     v6, v4
    vnmsubfp  v15, v6, v18, v4
    vmaddfp   v6, v15, v6, v6
    vnmsubfp  v19, v6, v18, v4
    vmaddfp   v6, v19, v6, v6
    vxor128   v49, v6, v63
    lvx128    v63, r11, r9
    vand128   v47, v65, v63
    vand128   v48, v64, v63
    vand128   v33, v87, v61
    vmulfp128 v19, v17, v49
    vmulfp128 v18, v16, v49
    vmaddfp   v3, v5, v0, v19
    vmaddfp   v4, v5, v0, v18
    vmaddfp   v5, v21, v13, v19
    vmaddfp   v6, v21, v13, v18
    vmaddfp   v13, v20, v11, v19
    vmaddfp   v0, v20, v12, v18
    vmaddfp   v19, v3, v2, v1
    vmaddfp   v20, v3, v31, v30
    vmaddfp   v11, v3, v29, v28
    vmaddfp   v12, v3, v27, v26
    vmaddfp   v21, v4, v31, v30
    vmaddfp   v30, v4, v2, v1
    vmaddfp   v3, v4, v29, v28
    vmaddfp   v31, v4, v27, v26
    vmaddfp   v4, v5, v19, v25
    vmaddfp   v1, v5, v20, v24
    vmaddfp   v11, v5, v11, v23
    vmaddfp   v12, v5, v12, v22
    vmaddfp   v2, v6, v21, v24
    vmaddfp   v3, v6, v3, v23
    vmaddfp   v4, v13, v4, v10
    vmaddfp   v5, v13, v1, v9
    vmaddfp   v11, v13, v11, v8
    vmaddfp   v12, v13, v12, v7
    vmaddfp   v13, v0, v2, v9
    vmulfp128 v42, v4, v44
    vcmpgtfp128 v34, v4, v5
    vmr128    v46, v11
    vmaddfp   v11, v6, v31, v22
    vmr128    v45, v12
    vmaddfp   v12, v0, v3, v8
    vmr128    v43, v13
    vmaddfp   v13, v6, v30, v25
    vcmpgtfp128 v38, v4, v46
    vcmpgtfp128 v41, v4, v45
    vcmpgtfp128 v32, v78, v42
    vcmpgtfp128 v55, v5, v42
    vmaddfp   v13, v0, v13, v10
    vmaddfp   v0, v0, v11, v7
    vmulfp128 v39, v13, v44
    lvx128    v62, r11, r5
    vand128   v51, v83, v60
    vcmpgtfp128 v53, v77, v42
    vand128   v50, v82, v60
  }
  _R10 = 32;
  __asm
  {
    vand128   v49, v89, v62
    vand128   v46, v84, v62
    vand128   v45, v70, v61
    vor128    v38, v65, v35
    vcmpgtfp128 v33, v13, v0
    vor128    v57, v82, v51
    vcmpgtfp128 v35, v13, v43
    vand128   v42, v69, v58
    vcmpgtfp128 v37, v13, v12
    vor128    v52, v79, v48
    vor128    v51, v78, v49
    vand128   v40, v68, v58
    vcmpgtfp128 v46, v75, v39
    vand128   v36, v66, v59
    vcmpgtfp128 v48, v12, v39
    vor128    v34, v86, v56
    vcmpgtfp128 v44, v0, v39
    vand128   v56, v87, v58
    vor128    v55, v72, v42
    vand128   v32, v64, v60
    vand128   v54, v73, v63
    vor128    v49, v70, v45
    vand128   v40, v65, v63
    lvx128    v63, r11, r10
    vor128    v47, v66, v36
    vand128   v50, v85, v62
    vand128   v43, v67, v59
    vor128    v42, v89, v32
    vor128    v41, v87, v56
    vand128   v45, v69, v61
    vand128   v34, v80, v60
    vand128   v33, v78, v58
    vand128   v32, v76, v62
    vor128    v39, v84, v54
    vor128    v38, v83, v50
    vor128    v37, v81, v45
    vor128    v36, v79, v43
    vor128    v62, v74, v34
    vor128    v61, v73, v33
    vor128    v35, v71, v40
    vor128    v60, v70, v32
    vor128    v59, v94, v37
    vor128    v58, v93, v36
    vor128    v57, v92, v35
    vor128    v56, v90, v59
    vor128    v55, v88, v57
    vsldoi128 v54, v87, v55, 4
    vor128    v53, v87, v54
    vsldoi128 v52, v85, v53, 8
    vor128    v51, v85, v52
    vcmpequw128. v50, v83, v63
  }
  __asm { vxor128   v49, v83, v63 }
  __asm
  {
    vpkuhus128 v48, v81, v49
    vpkuwus128 v0, v80, v48
    stvebx    v0, 0, r7
  }
  return ((32 * v27) & 0x20 | (16 * v28) & 0x20) != 0;
}


// ========================================================================
// ?ProjectedBounds@idRenderMatrix@@SAXAAVidBounds@@ABV1@ABV2@_N@Z
// EA  : 0x82F20DA8
// RVA : 0x00F20DA8
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

void __fastcall idRenderMatrix::ProjectedBounds(
        idBounds *projected,
        const idRenderMatrix *mvp,
        const idBounds *b,
        bool zeroToOne)
{
  __asm { lvlx128   v63, r0, r5 }
  _R7 = b;
  _R10 = 16;
  __asm { vspltisw128 v62, 0 }
  _R5 = 8;
  __asm { lvlx128   v61, r0, r4 }
  _R31 = 24;
  _R9 = &mvp->m[12];
  __asm { lvrx128   v60, r10, r7 }
  _R8 = &mvp->m[4];
  __asm
  {
    lvlx128   v59, r5, r7
    vor128    v63, v95, v60
    lvrx128   v58, r31, r7
  }
  _R11 = vectori_word_perm0;
  __asm
  {
    vor128    v57, v91, v58
    lvlx128   v56, r0, r9
    lvrx128   v55, r10, r9
  }
  _R7 = &mvp->m[8];
  __asm { vrlimi128 v63, v62, 1, 0 }
  _R9 = 16;
  __asm
  {
    vor128    v54, v88, v55
    lvrx128   v52, r10, r4
    vsldoi128 v62, v89, v62, 4
    lvx128    v0, r0, r11
    lvlx128   v53, r0, r8
    vor128    v50, v93, v52
    lvlx128   v51, r0, r7
    vspltw128 v13, v63, 2
    vspltw128 v11, v54, 3
    lvrx128   v49, r10, r8
    vperm128  v12, v95, v62, v0
    lvrx128   v48, r10, r7
    vspltw128 v0, v54, 0
    vor128    v47, v85, v49
    vor128    v46, v83, v48
    lvx128    v7, r11, r9
    vspltw128 v30, v54, 1
  }
  _R9 = 192;
  __asm { vperm128  v10, v95, v62, v7 }
  _R4 = 256;
  __asm
  {
    vmaddfp   v6, v12, v11, v0
    vspltw128 v7, v50, 3
    vspltw128 v11, v50, 0
  }
  __asm { vspltw128 v5, v47, 3 }
  __asm
  {
    vspltw128 v31, v46, 0
    lvx128    v63, r11, r9
    vspltw128 v2, v47, 0
    lvx128    v0, r11, r4
    vspltw128 v1, v46, 3
    vmaddfp   v3, v12, v7, v11
    vspltw128 v29, v50, 1
  }
  _R4 = &vector_float_neg_infinity;
  __asm { vspltw128 v28, v47, 1 }
  _R9 = &vector_float_pos_infinity;
  __asm
  {
    vmaddfp   v2, v12, v5, v2
    vspltw128 v9, v54, 2
    vmaddfp   v1, v12, v1, v31
    vspltw128 v31, v46, 1
    vspltw128 v11, v62, 2
    vspltw128 v12, v50, 2
    vmaddfp   v6, v10, v6, v30
    vspltw128 v7, v47, 2
    vspltw128 v5, v46, 2
    vmaddfp   v3, v10, v3, v29
    vmaddfp   v2, v10, v2, v28
    vmaddfp   v1, v10, v1, v31
    vmaddfp   v10, v13, v6, v9
    vmaddfp   v9, v11, v6, v9
    vmaddfp   v30, v13, v3, v12
    vmaddfp   v27, v11, v3, v12
    vmaddfp   v29, v13, v2, v7
    vmaddfp   v28, v13, v1, v5
    vmaddfp   v26, v11, v2, v7
    vmaddfp   v25, v11, v1, v5
    vmr128    v45, v10
    vmr       v6, v9
    vcmpgtfp128 v3, v95, v9
    vcmpgtfp128 v13, v95, v45
    vsel      v11, v10, v0, v13
    lvx128    v12, r0, r4
    vsel      v10, v6, v0, v3
    lvx128    v63, r0, r9
    vor128    v43, v13, v3
  }
  __asm
  {
    vmr       v5, v12
    vmr128    v44, v11
  }
  __asm
  {
    vmr128    v42, v10
    vsldoi128 v41, v75, v43, 4
    vmr       v7, v12
    vor128    v9, v95, v63
    vrefp128  v11, v44
    vor128    v2, v76, v44
    vrefp128  v10, v42
    vor128    v4, v74, v42
    vor128    v6, v76, v44
    vor128    v8, v74, v42
    vor128    v40, v75, v41
    vsldoi128 v39, v72, v40, 8
    vnmsubfp  v31, v11, v0, v2
    vor128    v13, v72, v39
    vnmsubfp  v2, v10, v0, v4
    vmaddfp   v3, v31, v11, v11
    vmaddfp   v4, v2, v10, v10
    vnmsubfp  v2, v3, v0, v6
    vnmsubfp  v6, v4, v0, v8
    vmaddfp   v10, v2, v3, v3
    vmaddfp   v11, v6, v4, v4
    vmulfp128 v38, v30, v10
    vmr128    v35, v11
    vmulfp128 v37, v29, v10
    vmulfp128 v36, v28, v10
    vor128    v11, v95, v63
    vmulfp128 v34, v27, v35
    vmulfp128 v33, v26, v35
    vmulfp128 v32, v25, v35
    vminfp128 v62, v70, v34
    vminfp128 v61, v69, v33
    vminfp128 v60, v68, v32
    vmaxfp128 v59, v70, v34
    vmaxfp128 v58, v69, v33
    vmaxfp128 v57, v68, v32
    vsldoi128 v56, v94, v62, 4
    vsldoi128 v55, v93, v61, 4
    vsldoi128 v54, v92, v60, 4
    vsldoi128 v53, v91, v59, 4
    vminfp128 v52, v94, v56
    vsldoi128 v51, v90, v58, 4
    vsldoi128 v49, v89, v57, 4
    vminfp128 v50, v93, v55
    vminfp128 v48, v92, v54
    vmaxfp128 v47, v91, v53
    vmaxfp128 v46, v90, v51
    vmaxfp128 v45, v89, v49
    vsldoi128 v44, v84, v52, 8
    vsldoi128 v43, v82, v50, 8
    vsldoi128 v42, v80, v48, 8
    vsldoi128 v41, v79, v47, 8
    vminfp128 v3, v84, v44
    vsldoi128 v40, v78, v46, 8
    vsldoi128 v39, v77, v45, 8
    vminfp128 v4, v82, v43
    vminfp128 v6, v80, v42
    vmaxfp128 v8, v79, v41
    vmaxfp128 v10, v78, v40
    vsel      v2, v3, v12, v13
    vmaxfp128 v12, v77, v39
    vsel      v3, v4, v5, v13
    vsel      v5, v6, v7, v13
    vsel      v7, v8, v9, v13
    vsel      v9, v10, v11, v13
    vsel128   v13, v12, v63, v13
    vmr       v12, v13
  }
  if ( zeroToOne )
  {
    _R9 = 224;
    _R8 = 208;
    __asm
    {
      lvx128    v13, r11, r9
      vmaddfp   v4, v2, v13, v13
      lvx128    v63, r11, r8
      vmaddfp   v6, v3, v13, v13
      vmaddfp   v8, v5, v13, v13
      vmaddfp   v10, v7, v13, v13
      vmaddfp   v11, v9, v13, v13
      vmaddfp   v13, v12, v13, v13
      vmaxfp128 v2, v4, v63
      vmaxfp128 v3, v6, v63
      vmaxfp128 v5, v8, v63
      vminfp    v7, v10, v0
      vminfp    v9, v11, v0
      vminfp    v12, v13, v0
    }
  }
  _R11 = 4;
  __asm { stvewx    v2, 0, r3 }
  _R9 = 12;
  _R8 = 20;
  __asm
  {
    stvewx    v3, r3, r11
    stvewx    v5, r3, r5
    stvewx    v7, r3, r9
    stvewx    v9, r3, r10
    stvewx    v12, r3, r8
  }
}


// ========================================================================
// ?DepthBoundsForBounds@idRenderMatrix@@SAXAAM0ABV1@ABVidBounds@@_N@Z
// EA  : 0x82F21090
// RVA : 0x00F21090
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

void __fastcall idRenderMatrix::DepthBoundsForBounds(
        float *min,
        float *max,
        const idRenderMatrix *mvp,
        const idBounds *b,
        bool zeroToOne)
{
  _R8 = 16;
  __asm { lvlx128   v63, r0, r6 }
  _R9 = 24;
  __asm { vspltisw128 v62, 0 }
  _R31 = 8;
  _R10 = &mvp->m[12];
  __asm { lvrx128   v61, r8, r6 }
  _R30 = 16;
  __asm
  {
    lvrx128   v60, r9, r6
    vor128    v63, v95, v61
    lvlx128   v59, r31, r6
  }
  _R11 = vectori_word_perm0;
  __asm
  {
    vor128    v58, v91, v60
    lvrx128   v56, r8, r10
    lvlx128   v57, r0, r10
  }
  _R9 = &mvp->m[8];
  __asm { vor128    v55, v89, v56 }
  _R6 = 192;
  __asm { vrlimi128 v63, v62, 1, 0 }
  _R5 = 256;
  __asm
  {
    vsldoi128 v61, v90, v62, 4
    lvx128    v0, r0, r11
    lvx128    v7, r11, r30
  }
  __asm
  {
    vspltw128 v6, v55, 0
    lvrx128   v53, r8, r9
    vspltw128 v10, v55, 3
    lvlx128   v54, r0, r9
    vperm128  v9, v95, v61, v0
    vor128    v52, v86, v53
    vperm128  v8, v95, v61, v7
    lvx128    v62, r11, r6
    vspltw128 v1, v55, 1
    lvx128    v0, r11, r5
    vspltw128 v13, v63, 2
  }
  _R9 = &vector_float_neg_infinity;
  __asm
  {
    vmaddfp   v7, v9, v10, v6
    vspltw128 v5, v52, 3
    vspltw128 v4, v52, 0
  }
  __asm
  {
    vspltw128 v31, v52, 1
    vspltw128 v12, v55, 2
  }
  __asm
  {
    vspltw128 v3, v61, 2
    lvx128    v11, r0, r9
    vmaddfp   v6, v9, v5, v4
    vspltw128 v2, v52, 2
    vmaddfp   v9, v8, v7, v1
    vmaddfp   v30, v8, v6, v31
    vmaddfp   v8, v13, v9, v12
    vmaddfp   v12, v3, v9, v12
    vmaddfp   v29, v13, v30, v2
    vmaddfp   v4, v3, v30, v2
    vcmpgtfp128 v1, v94, v8
    vcmpgtfp128 v31, v94, v12
    vand128   v51, v94, v1
    vand128   v50, v94, v31
    vor128    v8, v8, v51
    vor128    v9, v12, v50
    vrefp     v13, v8
    vrefp     v12, v9
    vnmsubfp  v28, v13, v0, v8
    vnmsubfp  v5, v12, v0, v9
    vmaddfp   v6, v28, v13, v13
    vmaddfp   v7, v5, v12, v12
    vnmsubfp  v5, v6, v0, v8
    vnmsubfp  v8, v7, v0, v9
    vmaddfp   v12, v5, v6, v6
    vmaddfp   v13, v8, v7, v7
    vmulfp128 v12, v29, v12
    vmulfp128 v13, v4, v13
    vsel      v9, v12, v11, v1
    vsel      v12, v13, v11, v31
    vminfp128 v49, v9, v12
    vmaxfp128 v48, v9, v12
    vsldoi128 v47, v81, v49, 4
    vsldoi128 v46, v80, v48, 4
    vminfp128 v45, v81, v47
    vmaxfp128 v44, v80, v46
    vsldoi128 v43, v77, v45, 8
    vsldoi128 v42, v76, v44, 8
    vminfp128 v13, v77, v43
    vmaxfp128 v12, v76, v42
  }
  if ( zeroToOne )
  {
    _R10 = 224;
    _R9 = 208;
    __asm
    {
      lvx128    v11, r11, r10
      vmaddfp   v10, v13, v11, v11
      lvx128    v63, r11, r9
      vmaddfp   v13, v12, v11, v11
      vmaxfp128 v41, v10, v63
      vminfp128 v40, v13, v0
      stvewx128 v41, r0, r3
      stvewx128 v40, r0, r4
    }
  }
  else
  {
    __asm
    {
      stvewx    v13, 0, r3
      stvewx    v12, 0, r4
    }
  }
}


// ========================================================================
// ?DepthBoundsForExtrudedBounds@idRenderMatrix@@SAXAAM0ABV1@ABVidBounds@@ABVidVec3@@ABVidPlane@@_N@Z
// EA  : 0x82F21238
// RVA : 0x00F21238
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

void __fastcall idRenderMatrix::DepthBoundsForExtrudedBounds(
        float *min,
        float *max,
        const idRenderMatrix *mvp,
        const idBounds *b,
        const idVec3 *extrudeDirection,
        const idPlane *clipPlane,
        bool zeroToOne)
{
  _R31 = b;
  __asm { vspltisw128 v61, 0 }
  _R30 = extrudeDirection;
  __asm { lvlx128   v60, r0, r8 }
  _R6 = 16;
  _R7 = 8;
  __asm { vspltw128 v18, v60, 0 }
  _R28 = 24;
  __asm { lvlx128   v63, r0, r31 }
  _R10 = &mvp->m[12];
  __asm
  {
    lvlx128   v59, r0, r30
    lvrx128   v58, r6, r31
  }
  _R29 = clipPlane;
  __asm
  {
    lvlx128   v57, r7, r31
    vor128    v62, v95, v58
    lvrx128   v56, r28, r31
  }
  _R11 = vectori_word_perm0;
  __asm
  {
    vor128    v55, v89, v56
    lvrx128   v53, r6, r10
    lvlx128   v54, r0, r10
  }
  _R8 = &mvp->m[8];
  __asm { vrlimi128 v62, v61, 1, 0 }
  _R10 = 16;
  __asm { vor128    v51, v86, v53 }
  __asm
  {
    vsldoi128 v61, v87, v61, 4
    lvx128    v0, r0, r11
    lvlx128   v48, r7, r29
    vspltw128 v30, v59, 0
    lvrx128   v50, r6, r8
    vspltw128 v11, v62, 2
    vspltw128 v7, v51, 3
    lvlx128   v52, r0, r8
    vperm128  v13, v94, v61, v0
    vor128    v49, v84, v50
    vspltw128 v6, v51, 0
    lvx128    v5, r11, r10
    vspltw128 v10, v51, 2
  }
  _R8 = 192;
  __asm { vperm128  v12, v94, v61, v5 }
  _R6 = 256;
  __asm
  {
    vspltw128 v4, v49, 3
    lvlx128   v47, r7, r30
    vmaddfp   v1, v13, v7, v6
    vspltw128 v3, v49, 0
    vspltw128 v5, v51, 1
  }
  _R10 = 4;
  __asm
  {
    vspltw128 v2, v49, 1
    lvx128    v63, r11, r8
    vspltw128 v9, v61, 2
    lvx128    v0, r11, r6
    vmaddfp   v31, v13, v4, v3
  }
  _R8 = &vector_float_neg_infinity;
  _R7 = 12;
  __asm
  {
    vspltw128 v8, v49, 2
    lvlx128   v44, r10, r29
    lvlx128   v42, r10, r30
    lvx128    v62, r0, r8
    lvlx128   v43, r7, r29
    vor128    v24, v94, v62
    vor128    v26, v94, v62
    vmaddfp   v1, v12, v1, v5
    vmaddfp   v25, v12, v31, v2
    vmaddfp   v31, v11, v1, v10
    vmaddfp   v1, v9, v1, v10
    vmaddfp   v16, v11, v25, v8
    vcmpgtfp128 v20, v95, v31
    vcmpgtfp128 v19, v95, v1
    vand128   v46, v95, v20
    vand128   v45, v95, v19
    vor128    v23, v31, v46
    vor128    v21, v1, v45
    vrefp     v1, v23
    vrefp     v31, v21
    vnmsubfp  v22, v1, v0, v23
    vnmsubfp  v29, v31, v0, v21
    vmaddfp   v28, v22, v1, v1
    vspltw128 v1, v48, 0
    vmaddfp   v27, v29, v31, v31
    vspltw128 v31, v47, 0
    vmulfp128 v60, v1, v31
    vspltw128 v17, v44, 0
    vmaddfp   v15, v9, v25, v8
    vspltw128 v25, v43, 0
    vspltw128 v29, v42, 0
    vmr       v22, v27
    vmr128    v59, v0
  }
  _R6 = 144;
  __asm
  {
    vmaddfp   v14, v17, v25, v12
    vmr       v25, v28
  }
  __asm
  {
    vnmsubfp128 v59, v22, v21, v59
    lvx128    v61, r11, r6
    vmaddcfp128 v17, v29, v17, v60
    vmr128    v60, v0
    vnmsubfp128 v60, v25, v23, v60
    vmr       v23, v28
    vmaddfp   v25, v18, v14, v13
    vmaddfp   v22, v18, v17, v30
    vmaddcfp128 v23, v92, v23, v28
    vmr       v28, v27
    vmaddfp   v21, v1, v25, v9
    vmaddfp   v18, v1, v25, v11
    vmaddcfp128 v28, v91, v28, v27
    vrefp     v1, v22
    vmr       v27, v22
    vmulfp128 v23, v16, v23
    vmulfp128 v25, v15, v28
    vmr       v28, v22
    vsel      v22, v23, v24, v20
    vsel      v24, v25, v26, v19
    vnmsubfp  v25, v1, v0, v27
    vminfp128 v41, v22, v24
    vmaxfp128 v40, v22, v24
    vmaddfp   v27, v25, v1, v1
    vnmsubfp  v26, v27, v0, v28
    vmaddfp   v1, v26, v27, v27
    vxor128   v39, v1, v61
    vmulfp128 v1, v18, v39
    vmulfp128 v28, v21, v39
    vmaddfp   v26, v30, v13, v1
    vmaddfp   v30, v30, v13, v28
    vmaddfp   v13, v31, v9, v28
    vmaddfp   v27, v29, v12, v1
    vmaddfp   v1, v31, v11, v1
    vor128    v11, v94, v62
    vmaddfp   v12, v29, v12, v28
    vmaddfp   v9, v26, v7, v6
    vmaddfp   v31, v30, v7, v6
    vmaddfp   v7, v26, v4, v3
    vmaddfp   v6, v27, v9, v5
    vmaddfp   v9, v30, v4, v3
    vmaddfp   v5, v12, v31, v5
    vmaddfp   v7, v27, v7, v2
    vmaddfp   v6, v1, v6, v10
    vmaddfp   v9, v12, v9, v2
    vmaddfp   v12, v13, v5, v10
    vmaddfp   v1, v1, v7, v8
    vcmpgtfp128 v5, v95, v6
    vmaddfp   v2, v13, v9, v8
    vcmpgtfp128 v4, v95, v12
    vand128   v38, v95, v5
    vand128   v37, v95, v4
    vor128    v9, v6, v38
    vor128    v10, v12, v37
    vrefp     v13, v9
    vrefp     v12, v10
    vnmsubfp  v3, v13, v0, v9
    vnmsubfp  v6, v12, v0, v10
    vmaddfp   v8, v3, v13, v13
    vmaddfp   v12, v6, v12, v12
    vnmsubfp  v7, v8, v0, v9
    vnmsubfp  v9, v12, v0, v10
    vmaddfp   v10, v7, v8, v8
    vmaddfp   v13, v9, v12, v12
    vmulfp128 v12, v1, v10
    vmulfp128 v13, v2, v13
    vsel      v10, v12, v11, v5
    vmr       v12, v4
    vminfp128 v36, v73, v10
    vmaxfp128 v35, v72, v10
    vsel128   v12, v13, v62, v12
    vminfp128 v34, v68, v12
    vmaxfp128 v33, v67, v12
    vsldoi128 v32, v66, v34, 4
    vminfp128 v62, v66, v32
    vsldoi128 v63, v65, v33, 4
    vmaxfp128 v61, v65, v63
    vsldoi128 v60, v94, v62, 8
    vminfp128 v13, v94, v60
    vsldoi128 v59, v93, v61, 8
    vmaxfp128 v12, v93, v59
  }
  if ( zeroToOne )
  {
    _R10 = 224;
    _R9 = 208;
    __asm
    {
      lvx128    v11, r11, r10
      vmaddfp   v10, v13, v11, v11
      lvx128    v63, r11, r9
      vmaddfp   v13, v12, v11, v11
      vmaxfp128 v58, v10, v63
      vminfp128 v57, v13, v0
      stvewx128 v58, r0, r3
      stvewx128 v57, r0, r4
    }
  }
  else
  {
    __asm
    {
      stvewx    v13, 0, r3
      stvewx    v12, 0, r4
    }
  }
}


// ========================================================================
// ?TransformModelToClip@idRenderMatrix@@SAXABVidVec3@@ABV1@1AAVidVec4@@2@Z
// EA  : 0x82F21538
// RVA : 0x00F21538
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

void __fastcall idRenderMatrix::TransformModelToClip(
        const idVec3 *src,
        const idRenderMatrix *modelMatrix,
        const idRenderMatrix *projectionMatrix,
        idVec4 *eye,
        idVec4 *clip)
{
  double v5; // fp10
  double v6; // fp13

  eye->x = (float)((float)(src->x * modelMatrix->m[0])
                 + (float)((float)(modelMatrix->m[2] * src->z) + (float)(modelMatrix->m[1] * src->y)))
         + modelMatrix->m[3];
  eye->y = (float)((float)(modelMatrix->m[5] * src->y)
                 + (float)((float)(modelMatrix->m[4] * src->x) + (float)(modelMatrix->m[6] * src->z)))
         + modelMatrix->m[7];
  v5 = (float)((float)((float)(modelMatrix->m[9] * src->y)
                     + (float)((float)(modelMatrix->m[8] * src->x) + (float)(modelMatrix->m[10] * src->z)))
             + modelMatrix->m[11]);
  eye->z = (float)((float)(modelMatrix->m[9] * src->y)
                 + (float)((float)(modelMatrix->m[8] * src->x) + (float)(modelMatrix->m[10] * src->z)))
         + modelMatrix->m[11];
  v6 = (float)((float)((float)(modelMatrix->m[13] * src->y)
                     + (float)((float)(modelMatrix->m[12] * src->x) + (float)(modelMatrix->m[14] * src->z)))
             + modelMatrix->m[15]);
  eye->w = (float)((float)(modelMatrix->m[13] * src->y)
                 + (float)((float)(modelMatrix->m[12] * src->x) + (float)(modelMatrix->m[14] * src->z)))
         + modelMatrix->m[15];
  clip->x = (float)(projectionMatrix->m[0] * eye->x)
          + (float)((float)(projectionMatrix->m[3] * (float)v6)
                  + (float)((float)(projectionMatrix->m[2] * (float)v5) + (float)(projectionMatrix->m[1] * eye->y)));
  clip->y = (float)(projectionMatrix->m[7] * eye->w)
          + (float)((float)(projectionMatrix->m[4] * eye->x)
                  + (float)((float)(projectionMatrix->m[6] * eye->z) + (float)(projectionMatrix->m[5] * eye->y)));
  clip->z = (float)(projectionMatrix->m[11] * eye->w)
          + (float)((float)(projectionMatrix->m[8] * eye->x)
                  + (float)((float)(projectionMatrix->m[10] * eye->z) + (float)(projectionMatrix->m[9] * eye->y)));
  clip->w = (float)(projectionMatrix->m[15] * eye->w)
          + (float)((float)(projectionMatrix->m[12] * eye->x)
                  + (float)((float)(projectionMatrix->m[14] * eye->z) + (float)(projectionMatrix->m[13] * eye->y)));
}


// ========================================================================
// ?TransformClipToDevice@idRenderMatrix@@SAXABVidVec4@@AAVidVec3@@@Z
// EA  : 0x82F216D0
// RVA : 0x00F216D0
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

void __fastcall idRenderMatrix::TransformClipToDevice(const idVec4 *clip, idVec3 *normalized)
{
  double v2; // fp11

  v2 = (float)((float)1.0 / clip->w);
  normalized->x = clip->x * (float)((float)1.0 / clip->w);
  normalized->y = -(float)(clip->y * (float)v2);
  normalized->z = clip->z * (float)v2;
}


// ========================================================================
// `dynamic initializer for 'vector_float_pos_infinity''
// EA  : 0x83395538
// RVA : 0x01395538
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

void _dynamic_initializer_for__vector_float_pos_infinity__()
{
  vector_float_pos_infinity.vector4_f32[0] = 1.0e30;
  vector_float_pos_infinity.vector4_f32[1] = 1.0e30;
  vector_float_pos_infinity.vector4_f32[2] = 1.0e30;
  vector_float_pos_infinity.vector4_f32[3] = 1.0e30;
}


// ========================================================================
// `dynamic initializer for 'vector_float_neg_infinity''
// EA  : 0x83395560
// RVA : 0x01395560
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.cpp
// ========================================================================

void _dynamic_initializer_for__vector_float_neg_infinity__()
{
  vector_float_neg_infinity.vector4_f32[0] = -1.0e30;
  vector_float_neg_infinity.vector4_f32[1] = -1.0e30;
  vector_float_neg_infinity.vector4_f32[2] = -1.0e30;
  vector_float_neg_infinity.vector4_f32[3] = -1.0e30;
}

