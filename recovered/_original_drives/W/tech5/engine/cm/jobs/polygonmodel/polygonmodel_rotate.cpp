
// ========================================================================
// ?CM_TanZeroHalfPI@@YAMM@Z
// EA  : 0x825EBBE0
// RVA : 0x005EBBE0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

float __fastcall CM_TanZeroHalfPI(double a)
{
  double v1; // fp0
  char v2; // r11
  double v3; // fp1

  v1 = a;
  if ( a <= idMath::ONEFOURTH_PI )
  {
    v2 = 0;
  }
  else
  {
    v2 = 1;
    v1 = (float)(idMath::HALF_PI - (float)a);
  }
  v3 = (float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)v1 * (float)v1) * (float)0.0095168091) + (float)0.002900525)
                                                                                             * (float)((float)v1 * (float)v1))
                                                                                     + (float)0.024565089)
                                                                             * (float)((float)v1 * (float)v1))
                                                                     + (float)0.053374059)
                                                             * (float)((float)v1 * (float)v1))
                                                     + (float)0.13339239)
                                             * (float)((float)v1 * (float)v1))
                                     + (float)0.33333141)
                             * (float)((float)v1 * (float)v1))
                     + (float)1.0)
             * (float)v1);
  if ( v2 != 0 )
    v3 = (float)((float)1.0
               / (float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)v1 * (float)v1) * (float)0.0095168091) + (float)0.002900525) * (float)((float)v1 * (float)v1))
                                                                                               + (float)0.024565089)
                                                                                       * (float)((float)v1 * (float)v1))
                                                                               + (float)0.053374059)
                                                                       * (float)((float)v1 * (float)v1))
                                                               + (float)0.13339239)
                                                       * (float)((float)v1 * (float)v1))
                                               + (float)0.33333141)
                                       * (float)((float)v1 * (float)v1))
                               + (float)1.0)
                       * (float)v1));
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?CM_ArcTanPositive@@YAMM@Z
// EA  : 0x825EBC78
// RVA : 0x005EBC78
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

float __fastcall CM_ArcTanPositive(double a)
{
  double v1; // fp0
  double v2; // fp7
  double v3; // fp1

  v1 = a;
  if ( a <= 1.0 )
  {
    v2 = 0.0;
  }
  else
  {
    v2 = idMath::HALF_PI;
    v1 = (float)((float)-1.0 / (float)a);
  }
  v3 = (float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)v1 * (float)v1) * (float)0.0028662258) - (float)0.016165737) * (float)((float)v1 * (float)v1)) + (float)0.042909615) * (float)((float)v1 * (float)v1)) - (float)0.075289637) * (float)((float)v1 * (float)v1))
                                                                                             + (float)0.10656264)
                                                                                     * (float)((float)v1 * (float)v1))
                                                                             - (float)0.14208899)
                                                                     * (float)((float)v1 * (float)v1))
                                                             + (float)0.19993551)
                                                     * (float)((float)v1 * (float)v1))
                                             - (float)0.33333147)
                                     * (float)((float)v1 * (float)v1))
                             + (float)1.0)
                     * (float)v1)
             + (float)v2);
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?EdgeIntersectsBoundsShort@idPolygonModelCollisionDetection@@CA_NABVidBoundsShort@@ABVidVec3@@1@Z
// EA  : 0x825EBD18
// RVA : 0x005EBD18
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

BOOL __fastcall idPolygonModelCollisionDetection::EdgeIntersectsBoundsShort(
        const idBoundsShort *bounds,
        const idVec3 *start,
        const idVec3 *end)
{
  unsigned __int8 v8; // cr56
  unsigned __int8 v9; // cr57
  unsigned __int8 v10; // cr58
  unsigned __int8 v11; // cr59
  unsigned __int16 v12; // r6
  unsigned __int8 v13; // cr56
  unsigned __int8 v14; // cr57
  unsigned __int8 v15; // cr58
  unsigned __int8 v16; // cr59

  __asm { lvx128    v62, r0, r3 }
  _R10 = 80;
  __asm { lvx128    v60, r0, r4 }
  _R9 = vmxi_float_abs_mask_4;
  __asm { vsldoi128 v59, v94, v62, 6 }
  _R8 = 32;
  __asm { lvx128    v58, r0, r5 }
  _R7 = -128;
  __asm
  {
    lvx128    v63, r9, r10
    vand128   v57, v94, v63
    lvx128    v62, r9, r8
    vand128   v56, v91, v63
    lvx128    v61, r9, r7
    vand128   v55, v92, v62
    lvx128    v63, r0, r9
    vand128   v54, v90, v62
    vupkhsh128 v53, v57
    vupkhsh128 v52, v56
    vsubfp128 v51, v86, v55
    vcsxwfp128 v50, v53, 0
    vcsxwfp128 v49, v52, 0
    vmulfp128 v48, v83, v61
    vaddfp128 v47, v82, v49
    vaddfp128 v46, v87, v48
    vand128   v0, v80, v63
    vmulfp128 v45, v79, v61
    vsubfp128 v13, v78, v45
    vsubfp128 v44, v81, v45
    vand128   v43, v13, v63
    vsubfp128 v42, v75, v0
    vcmpgtfp128. v41, v74, v44
  }
  v12 = (v8 << 7) | (v9 << 6) | (32 * v10) | (16 * v11);
  __asm
  {
    vpermwi128 v40, v13, 0x63 # 'c'
    vpermwi128 v39, v0, 0x63 # 'c'
    vpermwi128 v12, v48, 0x63 # 'c'
    vpermwi128 v9, v44, 0x63 # 'c'
    vmulfp128 v11, v80, v40
    vmulfp128 v10, v76, v39
    vnmsubfp  v11, v13, v11, v12
    vmaddfp   v0, v0, v10, v9
    vand128   v38, v11, v63
    vcmpgtfp128. v37, v70, v0
  }
  return ((unsigned __int16)((v13 << 7) | (v14 << 6) | (32 * v15) | (16 * v16)) & v12 & 0x20) != 0;
}


// ========================================================================
// ?RotationSetup@idPolygonModelCollisionDetection@@CAXPIAVidTraceWork@@ABVidVec3@@1M11ABVidMat3@@12@Z
// EA  : 0x825EBDE0
// RVA : 0x005EBDE0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::RotationSetup(
        idTraceWork *tw,
        const idVec3 *rorg,
        const idVec3 *axis,
        double angle,
        const idVec3 *start,
        const idVec3 *offset,
        const idMat3 *trmAxis,
        const idVec3 *modelOrigin,
        const idMat3 *modelAxis,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29)
{
  double x; // fp31
  double v31; // fp29
  double v32; // fp28
  double v35; // fp7
  double v37; // fp30
  double v38; // fp4
  double v39; // fp27
  double v40; // fp10
  double y; // fp26
  double v43; // fp25
  double v45; // fp24
  idMat3x4 *p_trmTransform; // r31
  double z; // fp23
  double v48; // fp22
  double v49; // fp21
  double v50; // fp1
  double v51; // fp0
  double v52; // fp13
  double v53; // fp12
  double v54; // fp9
  double v55; // fp10
  double v56; // fp8
  double v57; // fp7
  double v58; // fp11
  double v59; // fp6
  double v60; // fp5
  double v61; // fp4
  double v62; // fp3
  double v63; // fp25
  double v64; // fp0
  double v65; // fp27
  double v66; // fp2
  double v67; // fp28
  double v68; // fp1
  double v69; // fp0
  double v70; // fp12
  double v71; // fp11
  double v72; // fp10
  double v73; // fp13
  char v74; // r8
  double v75; // fp9
  double v76; // fp8
  double v77; // fp5
  double v78; // fp4
  double v79; // fp3
  double v80; // fp10
  double v81; // fp2
  double v82; // fp1
  double v83; // fp11
  double v84; // fp7
  double v85; // fp6
  double v86; // fp6
  double v87; // fp12
  double v88; // fp10
  double v89; // fp7
  double v90; // fp9
  double v91; // fp8

  x = offset->x;
  v31 = modelOrigin->x;
  v32 = modelOrigin[1].x;
  v35 = (float)(offset->y - modelAxis->mat[0].y);
  v37 = modelAxis->mat[0].x;
  v38 = (float)(offset->z - modelAxis->mat[0].z);
  v39 = modelOrigin[2].x;
  v40 = (float)(offset->x - modelAxis->mat[0].x);
  y = modelOrigin->y;
  v43 = modelOrigin[1].y;
  v45 = modelOrigin[2].y;
  p_trmTransform = &tw->trmTransform;
  z = modelOrigin->z;
  v48 = modelOrigin[1].z;
  v49 = modelOrigin[2].z;
  tw->trmTransform.mat[0] = modelOrigin->x;
  tw->trmTransform.mat[1] = v32;
  tw->trmTransform.mat[2] = v39;
  tw->trmTransform.mat[4] = y;
  tw->trmTransform.mat[5] = v43;
  tw->trmTransform.mat[6] = v45;
  tw->trmTransform.mat[8] = z;
  tw->trmTransform.mat[9] = v48;
  tw->trmTransform.mat[10] = v49;
  tw->trmTransform.mat[3] = v40;
  tw->trmTransform.mat[7] = v35;
  tw->trmTransform.mat[11] = v38;
  tw->angle = angle;
  v50 = CM_TanZeroHalfPI(a: __fabs((float)((float)((float)3.1415927 * (float)0.0027777778) * (float)angle)));
  v51 = (float)(trmAxis->mat[0].y * (float)v32);
  v52 = trmAxis->mat[0].z;
  v53 = (float)(trmAxis->mat[0].y * (float)v43);
  v54 = offset->z;
  v55 = (float)(trmAxis->mat[0].y * (float)v48);
  v56 = rorg->z;
  v57 = (float)(rorg->z - offset->z);
  v58 = trmAxis->mat[0].x;
  v59 = offset->y;
  v60 = rorg->y;
  v61 = axis->z;
  v62 = (float)(rorg->y - offset->y);
  v63 = rorg->x;
  tw->initialTan = v50;
  tw->maxTan = v50;
  v64 = (float)((float)((float)v52 * (float)v39) + (float)v51);
  v65 = axis->y;
  v66 = modelAxis->mat[0].y;
  v67 = modelAxis->mat[0].z;
  v68 = axis->x;
  v69 = (float)((float)((float)v58 * (float)v31) + (float)v64);
  v70 = (float)((float)((float)v58 * (float)y) + (float)((float)((float)v52 * (float)v45) + (float)v53));
  v71 = (float)((float)((float)v58 * (float)z) + (float)((float)((float)v52 * (float)v49) + (float)v55));
  v72 = (float)((float)(axis->x * (float)((float)v63 - (float)x))
              + (float)((float)(axis->y * (float)v62) + (float)((float)v61 * (float)v57)));
  tw->start.y = (float)((float)v59 + (float)v70) - modelAxis->mat[0].y;
  tw->start.z = (float)((float)v54 + (float)v71) - (float)v67;
  tw->start.x = (float)((float)x + (float)v69) - (float)v37;
  v73 = *(float *)a29;
  tw->origin.x = (float)((float)v63 - (float)((float)v68 * (float)v72)) - (float)v37;
  tw->origin.y = (float)((float)v60 - (float)((float)v65 * (float)v72)) - (float)v66;
  tw->origin.z = (float)((float)v56 - (float)((float)v61 * (float)v72)) - (float)v67;
  tw->axis.x = v68;
  tw->axis.y = v65;
  tw->axis.z = v61;
  if ( v73 != 1.0 || *(float *)(a29 + 16) != 1.0 || (v74 = 0, *(float *)(a29 + 32) != 1.0) )
    v74 = 1;
  if ( v74 != 0 )
  {
    v75 = *(float *)(a29 + 16);
    v76 = *(float *)(a29 + 28);
    v77 = *(float *)(a29 + 4);
    v78 = *(float *)(a29 + 12);
    v79 = *(float *)(a29 + 24);
    v80 = tw->start.z;
    v81 = *(float *)(a29 + 8);
    v82 = *(float *)(a29 + 20);
    v83 = *(float *)(a29 + 32);
    v84 = (float)((float)(*(float *)(a29 + 12) * tw->start.x) + (float)(*(float *)(a29 + 16) * tw->start.y));
    v85 = (float)((float)(*(float *)(a29 + 24) * tw->start.x) + (float)(*(float *)(a29 + 28) * tw->start.y));
    tw->start.x = (float)(*(float *)(a29 + 8) * tw->start.z)
                + (float)((float)(*(float *)(a29 + 4) * tw->start.y) + (float)((float)v73 * tw->start.x));
    tw->start.y = (float)((float)v82 * (float)v80) + (float)v84;
    tw->start.z = (float)((float)v83 * (float)v80) + (float)v85;
    v86 = tw->origin.z;
    v87 = (float)((float)((float)v78 * tw->origin.x) + (float)((float)v75 * tw->origin.y));
    v88 = (float)((float)((float)v79 * tw->origin.x) + (float)((float)v76 * tw->origin.y));
    tw->origin.x = (float)((float)v81 * tw->origin.z)
                 + (float)((float)((float)v77 * tw->origin.y) + (float)((float)v73 * tw->origin.x));
    tw->origin.y = (float)((float)v82 * (float)v86) + (float)v87;
    tw->origin.z = (float)((float)v83 * (float)v86) + (float)v88;
    v89 = tw->axis.z;
    v90 = (float)((float)((float)v78 * tw->axis.x) + (float)((float)v75 * tw->axis.y));
    v91 = (float)((float)((float)v79 * tw->axis.x) + (float)((float)v76 * tw->axis.y));
    tw->axis.x = (float)((float)v81 * tw->axis.z)
               + (float)((float)((float)v77 * tw->axis.y) + (float)((float)v73 * tw->axis.x));
    tw->axis.y = (float)((float)v82 * (float)v89) + (float)v90;
    tw->axis.z = (float)((float)v83 * (float)v89) + (float)v91;
    idMat3x4::LeftTransposeMultiply(this: p_trmTransform, m: (const idMat3 *)a29);
  }
}


// ========================================================================
// ?TransformFromOriginAxisAngle@idPolygonModelCollisionDetection@@CAXAAVidMat3x4@@ABVidVec3@@1M@Z
// EA  : 0x825EC0C8
// RVA : 0x005EC0C8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::TransformFromOriginAxisAngle(
        idMat3x4 *transform,
        const idVec3 *origin,
        const idVec3 *axis,
        double angle)
{
  double v8; // fp1
  double v9; // fp4
  double v10; // fp2
  double v11; // fp1
  double v12; // fp12
  double v13; // fp11
  double v14; // fp8
  double v15; // fp7
  double v16; // fp6
  double v17; // fp3
  double v18; // fp5
  double v19; // fp13
  double v20; // fp1
  double v21; // fp12
  double v22; // fp11
  double v23; // fp10
  double v24; // fp9
  double v25; // fp5
  double v26; // fp4
  double v27; // fp1
  double v28; // fp2
  double v29; // fp6
  double v30; // fp7
  double v31; // fp3
  double x; // fp13
  double v33; // fp12
  double z; // fp11
  double y; // fp10
  double v36; // fp10
  double v37; // fp7

  v8 = CM_TanZeroHalfPI(a: (float)((float)__fabs(angle) * (float)((float)3.1415927 * (float)0.0013888889)));
  if ( angle < 0.0 )
    v8 = -v8;
  v9 = (float)((float)((float)1.0 - (float)((float)v8 * (float)v8))
             * (float)((float)1.0 / (float)((float)((float)v8 * (float)v8) + (float)1.0)));
  v10 = (float)(axis->y
              * (float)((float)((float)((float)1.0 / (float)((float)((float)v8 * (float)v8) + (float)1.0)) * (float)v8)
                      * (float)2.0));
  v12 = (float)(axis->x
              * (float)((float)((float)((float)1.0 / (float)((float)((float)v8 * (float)v8) + (float)1.0)) * (float)v8)
                      * (float)2.0));
  v13 = (float)((float)(axis->y
                      * (float)((float)((float)((float)1.0 / (float)((float)((float)v8 * (float)v8) + (float)1.0))
                                      * (float)v8)
                              * (float)2.0))
              * (float)2.0);
  v14 = (float)((float)((float)(axis->y
                              * (float)((float)((float)((float)1.0 / (float)((float)((float)v8 * (float)v8) + (float)1.0))
                                              * (float)v8)
                                      * (float)2.0))
                      * (float)2.0)
              * (float)(axis->y
                      * (float)((float)((float)((float)1.0 / (float)((float)((float)v8 * (float)v8) + (float)1.0))
                                      * (float)v8)
                              * (float)2.0)));
  v11 = (float)(axis->z
              * (float)((float)((float)((float)1.0 / (float)((float)((float)v8 * (float)v8) + (float)1.0)) * (float)v8)
                      * (float)2.0));
  v15 = (float)((float)((float)v11 * (float)2.0) * (float)v11);
  v16 = (float)((float)v13 * (float)v12);
  v17 = (float)((float)v13 * (float)v9);
  v18 = (float)((float)((float)v11 * (float)2.0) * (float)v12);
  v19 = (float)((float)((float)v12 * (float)2.0) * (float)v12);
  v23 = (float)((float)((float)((float)v11 * (float)2.0) * (float)v11) + (float)((float)v13 * (float)v10));
  v22 = (float)((float)((float)v12 * (float)2.0) * (float)v9);
  v21 = (float)((float)((float)v11 * (float)2.0) * (float)v10);
  v20 = (float)((float)((float)v11 * (float)2.0) * (float)v9);
  v24 = (float)((float)v18 - (float)v17);
  transform->mat[2] = (float)v18 - (float)v17;
  v25 = (float)((float)v17 + (float)v18);
  v26 = (float)((float)v20 + (float)v16);
  transform->mat[1] = (float)v20 + (float)v16;
  v27 = (float)((float)v16 - (float)v20);
  v28 = (float)((float)v15 + (float)v19);
  v29 = (float)((float)v14 + (float)v19);
  v30 = (float)((float)v22 + (float)v21);
  v31 = (float)((float)1.0 - (float)v23);
  transform->mat[0] = (float)1.0 - (float)v23;
  x = origin->x;
  v33 = (float)((float)v21 - (float)v22);
  z = origin->z;
  y = origin->y;
  transform->mat[6] = v30;
  transform->mat[4] = v27;
  transform->mat[5] = (float)1.0 - (float)v28;
  transform->mat[3] = (float)x
                    - (float)((float)((float)z * (float)v24)
                            + (float)((float)((float)x * (float)v31) + (float)((float)v26 * (float)y)));
  v36 = origin->y;
  v37 = (float)((float)(origin->z * (float)v30) + (float)(origin->x * (float)v27));
  transform->mat[9] = v33;
  transform->mat[8] = v25;
  transform->mat[10] = (float)1.0 - (float)v29;
  transform->mat[7] = (float)v36 - (float)((float)((float)((float)1.0 - (float)v28) * (float)v36) + (float)v37);
  transform->mat[11] = origin->z
                     - (float)((float)((float)((float)1.0 - (float)v29) * origin->z)
                             + (float)((float)((float)v33 * origin->y) + (float)((float)v25 * origin->x)));
}


// ========================================================================
// ?TransformAxisToZAxis@idPolygonModelCollisionDetection@@CAXAAVidMat3x4@@ABVidVec3@@1@Z
// EA  : 0x825EC250
// RVA : 0x005EC250
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::TransformAxisToZAxis(
        idMat3x4 *transform,
        const idVec3 *origin,
        const idVec3 *axis)
{
  double v3; // fp0
  double v4; // fp0
  double v5; // fp13
  double v6; // fp10
  double v7; // fp1
  double v8; // fp10
  double v9; // fp3
  double v10; // fp1
  double v11; // fp9
  double x; // fp5
  double y; // fp9
  double z; // fp12

  v3 = (float)((float)(axis->x * axis->x) + (float)(axis->y * axis->y));
  if ( __fabs(v3) > idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    v6 = __frsqrte(v3);
    v7 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6
                                                                                       * (float)((float)v3 * (float)0.5))
                                                                               * (float)v6)
                                                                       - (float)1.5)
                                                       * (float)v6)
                                               * (float)((float)v3 * (float)0.5))
                                       * (float)((float)-(float)((float)((float)((float)v6
                                                                               * (float)((float)v3 * (float)0.5))
                                                                       * (float)v6)
                                                               - (float)1.5)
                                               * (float)v6))
                               - (float)1.5)
               * (float)((float)-(float)((float)((float)((float)v6 * (float)((float)v3 * (float)0.5)) * (float)v6)
                                       - (float)1.5)
                       * (float)v6));
    v8 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6 * (float)((float)v3 * (float)0.5)) * (float)v6) - (float)1.5)
                                                                                       * (float)v6)
                                                                               * (float)((float)v3 * (float)0.5))
                                                                       * (float)((float)-(float)((float)((float)((float)v6 * (float)((float)v3 * (float)0.5)) * (float)v6)
                                                                                               - (float)1.5)
                                                                               * (float)v6))
                                                               - (float)1.5)
                                               * (float)((float)-(float)((float)((float)((float)v6
                                                                                       * (float)((float)v3 * (float)0.5))
                                                                               * (float)v6)
                                                                       - (float)1.5)
                                                       * (float)v6))
                                       * (float)((float)v3 * (float)0.5))
                               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6 * (float)((float)v3 * (float)0.5)) * (float)v6)
                                                                                               - (float)1.5)
                                                                               * (float)v6)
                                                                       * (float)((float)v3 * (float)0.5))
                                                               * (float)((float)-(float)((float)((float)((float)v6 * (float)((float)v3 * (float)0.5))
                                                                                               * (float)v6)
                                                                                       - (float)1.5)
                                                                       * (float)v6))
                                                       - (float)1.5)
                                       * (float)((float)-(float)((float)((float)((float)v6
                                                                               * (float)((float)v3 * (float)0.5))
                                                                       * (float)v6)
                                                               - (float)1.5)
                                               * (float)v6)))
                       - (float)1.5);
    v4 = (float)(axis->x * (float)((float)v8 * (float)v7));
    v5 = -(float)((float)((float)v8 * (float)v7) * axis->y);
  }
  else
  {
    v4 = 0.0;
    v5 = 1.0;
  }
  transform->mat[0] = v5;
  transform->mat[1] = v4;
  transform->mat[2] = 0.0;
  transform->mat[3] = -(float)((float)(origin->z * (float)0.0)
                             + (float)((float)(origin->y * (float)v4) + (float)(origin->x * (float)v5)));
  v9 = -(float)((float)v4 * axis->z);
  transform->mat[4] = v9;
  v10 = (float)((float)v5 * axis->z);
  transform->mat[5] = (float)v5 * axis->z;
  v11 = (float)((float)(axis->x * (float)v4) - (float)((float)v5 * axis->y));
  transform->mat[6] = (float)(axis->x * (float)v4) - (float)((float)v5 * axis->y);
  transform->mat[7] = -(float)((float)((float)v9 * origin->x)
                             + (float)((float)((float)v11 * origin->z) + (float)(origin->y * (float)v10)));
  x = axis->x;
  transform->mat[8] = axis->x;
  y = axis->y;
  transform->mat[9] = axis->y;
  z = axis->z;
  transform->mat[10] = axis->z;
  transform->mat[11] = -(float)((float)((float)x * origin->x)
                              + (float)((float)((float)z * origin->z) + (float)(origin->y * (float)y)));
}


// ========================================================================
// ?CM_PointRotationBounds@@YAXABVidVec3@@000AAVidVec4@@1@Z
// EA  : 0x825EC398
// RVA : 0x005EC398
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

void __fastcall CM_PointRotationBounds(
        const idVec3 *origin,
        const idVec3 *axis,
        const idVec3 *start,
        const idVec3 *end,
        idVec4 *boundsMin,
        idVec4 *boundsMax)
{
  double x; // fp0
  double v7; // fp28
  double v8; // fp26
  unsigned int v9; // r28
  unsigned int v10; // r30
  unsigned int v11; // r31
  double y; // fp9
  double z; // fp10
  BOOL v14; // r3
  double v15; // fp11
  double v16; // fp12
  double v17; // fp13
  BOOL v18; // r4
  BOOL v19; // r29
  double v20; // fp11
  double v21; // fp12
  double v22; // fp13

  x = origin->x;
  v7 = (float)(start->z - origin->z);
  v8 = (float)(start->y - origin->y);
  v9 = (COERCE_UNSIGNED_INT((float)(axis->y * (float)(end->x - origin->x)) - (float)(axis->x
                                                                                   * (float)(end->y - origin->y))) >> 31)
     ^ (COERCE_UNSIGNED_INT((float)(axis->y * (float)(start->x - origin->x)) - (float)(axis->x
                                                                                     * (float)(start->y - origin->y))) >> 31);
  v10 = (COERCE_UNSIGNED_INT((float)(axis->x * (float)(end->z - origin->z)) - (float)(axis->z
                                                                                    * (float)(end->x - origin->x))) >> 31)
      ^ (COERCE_UNSIGNED_INT((float)(axis->x * (float)(start->z - origin->z)) - (float)(axis->z
                                                                                      * (float)(start->x - origin->x))) >> 31);
  v11 = (COERCE_UNSIGNED_INT((float)(axis->z * (float)(end->y - origin->y)) - (float)(axis->y
                                                                                    * (float)(end->z - origin->z))) >> 31)
      ^ (COERCE_UNSIGNED_INT((float)(axis->z * (float)(start->y - origin->y)) - (float)(axis->y
                                                                                      * (float)(start->z - origin->z))) >> 31);
  y = origin->y;
  z = origin->z;
  v15 = __fsqrts((float)((float)__fabs((float)-(float)((float)(axis->x * axis->x) - (float)1.0))
                       * (float)((float)((float)(start->x - origin->x) * (float)(start->x - origin->x))
                               + (float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)))));
  v16 = __fsqrts((float)((float)__fabs((float)-(float)((float)(axis->y * axis->y) - (float)1.0))
                       * (float)((float)((float)(start->x - origin->x) * (float)(start->x - origin->x))
                               + (float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)))));
  v17 = __fsqrts((float)((float)__fabs((float)-(float)((float)(axis->z * axis->z) - (float)1.0))
                       * (float)((float)((float)(start->x - origin->x) * (float)(start->x - origin->x))
                               + (float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)))));
  v14 = (float)((float)(end->x + start->x) * (float)0.5) < x;
  if ( (float)((float)(end->x + start->x) * (float)0.5) < x )
    v15 = -v15;
  v18 = (float)((float)(end->y + start->y) * (float)0.5) < y;
  if ( (float)((float)(end->y + start->y) * (float)0.5) < y )
    v16 = -v16;
  v19 = (float)((float)(end->z + start->z) * (float)0.5) < z;
  if ( (float)((float)(end->z + start->z) * (float)0.5) < z )
    v17 = -v17;
  v20 = (float)((float)x + (float)v15);
  v21 = (float)((float)y + (float)v16);
  v22 = (float)((float)z + (float)v17);
  if ( (_BYTE)v11 != 0 && (float)((float)(end->x + start->x) * (float)0.5) < x )
  {
    _FP0 = v20;
  }
  else
  {
    _FP0 = (float)(start->x - end->x);
    __asm { fsel      f0, f0, f7, f8 }
  }
  boundsMin->x = _FP0;
  if ( (_BYTE)v10 != 0 && v18 )
  {
    _FP0 = v21;
  }
  else
  {
    _FP9 = (float)(start->y - end->y);
    __asm { fsel      f0, f9, f0, f10 }
  }
  boundsMin->y = _FP0;
  if ( (_BYTE)v9 != 0 && v19 )
  {
    _FP0 = v22;
  }
  else
  {
    _FP9 = (float)(start->z - end->z);
    __asm { fsel      f0, f9, f0, f10 }
  }
  boundsMin->z = _FP0;
  if ( (_BYTE)v11 == 0 || v14 )
  {
    _FP10 = (float)(start->x - end->x);
    __asm { fsel      f0, f10, f11, f0 }
  }
  else
  {
    _FP0 = v20;
  }
  boundsMax->x = _FP0;
  if ( (_BYTE)v10 == 0 || v18 )
  {
    _FP11 = (float)(start->y - end->y);
    __asm { fsel      f0, f11, f12, f0 }
  }
  else
  {
    _FP0 = v21;
  }
  boundsMax->y = _FP0;
  if ( (_BYTE)v9 == 0 || v19 )
  {
    _FP12 = (float)(start->z - end->z);
    __asm { fsel      f0, f12, f13, f0 }
  }
  else
  {
    _FP0 = v22;
  }
  boundsMax->z = _FP0;
  boundsMin->x = boundsMin->x - (float)1.0;
  boundsMin->y = boundsMin->y - (float)1.0;
  boundsMin->z = boundsMin->z - (float)1.0;
  boundsMax->x = boundsMax->x + (float)1.0;
  boundsMax->y = boundsMax->y + (float)1.0;
  boundsMax->z = boundsMax->z + (float)1.0;
}


// ========================================================================
// ?RotationVerts@idPolygonModelCollisionDetection@@CAXPIAVidTraceWork@@PIBVidTraceModel@@PIAVidVec4@@@Z
// EA  : 0x825EC6E8
// RVA : 0x005EC6E8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::RotationVerts(
        idTraceWork *tw,
        const idTraceModel *trm,
        idVec4 *zverts)
{
  unsigned int v21; // r31

  _R10 = 6272;
  __asm { vspltisw128 v63, 0 }
  _R8 = 16;
  _R30 = &vmx_float_zero;
  __asm
  {
    vor128    v53, v95, v63
    lvx128    v50, r3, r10
  }
  _R7 = 160;
  __asm { vor128    v13, v82, v50 }
  _R10 = &vmx_float_posInfinity_4;
  __asm { vor128    v0, v82, v50 }
  __asm { lvx128    v22, r30, r8 }
  _R31 = 6080;
  _R8 = &vmx_float_negInfinity_4;
  __asm
  {
    vspltw128 v10, v50, 0
    lvx128    v109, r30, r7
  }
  _R7 = 6192;
  __asm
  {
    vnmsubfp  v12, v0, v22, v13
    lvx128    v52, r0, r10
  }
  _R6 = 6048;
  __asm { vspltw128 v9, v50, 1 }
  _R10 = 6336;
  __asm
  {
    lvx128    v59, r3, r31
    lvx128    v51, r0, r8
  }
  _R11 = 6064;
  __asm { lvx128    v62, r3, r7 }
  _R31 = 6320;
  _R8 = 6352;
  __asm
  {
    vspltw128 v8, v50, 2
    lvx128    v61, r3, r6
  }
  _R7 = 6368;
  __asm { lvx128    v58, r3, r10 }
  _R6 = 6288;
  _R29 = 6304;
  __asm { lvx128    v60, r3, r11 }
  _R10 = 6256;
  __asm
  {
    lvx128    v0, r3, r31
    lvx128    v57, r3, r8
  }
  __asm { lvx128    v56, r3, r7 }
  v21 = 0;
  __asm
  {
    vand128   v49, v12, v109
    lvx128    v55, r3, r6
    lvx128    v54, r3, r29
  }
  __asm
  {
    lvx128    v13, r3, r10
    vspltw128 v108, v49, 0
    vspltw128 v107, v49, 1
    vspltw128 v106, v49, 2
  }
  if ( tw->numVerts != 0 )
  {
    _R8 = zverts + 2;
    __asm { vspltw128 v42, v59, 3 }
    _R6 = 32;
    __asm { vspltw128 v41, v59, 0 }
    _R5 = 48;
    __asm
    {
      vspltw128 v40, v59, 1
      vspltw128 v39, v59, 2
    }
    _R9 = 176;
    _R29 = 144;
    __asm { vspltw128 v50, v61, 3 }
    _R28 = 96;
    __asm
    {
      vspltw128 v49, v61, 0
      lvx128    v59, r30, r6
    }
    _R27 = 112;
    __asm { lvx128    v23, r30, r5 }
    _R7 = trm->vertsZ;
    _R4 = 64;
    __asm { vspltw128 v48, v61, 1 }
    _R6 = 208;
    __asm { vspltw128 v47, v61, 2 }
    _R5 = 224;
    __asm
    {
      vspltw128 v46, v60, 3
      vspltw128 v45, v60, 0
      lvx128    v61, r30, r27
      vspltw128 v44, v60, 1
    }
    _R10 = &tw->vertexPluecker[1];
    __asm
    {
      vspltw128 v43, v60, 2
      lvx128    v60, r30, r9
      vspltw128 v126, v56, 3
      lvx128    v11, r30, r6
      vspltw128 v125, v56, 0
      lvx128    v4, r30, r5
      vspltw128 v124, v56, 1
    }
    _R11 = &tw->vertexPosition[1];
    __asm
    {
      vspltw128 v123, v56, 2
      lvx128    v56, r30, r29
      vspltw128 v113, v62, 3
    }
    _R18 = -256;
    __asm { vspltw128 v112, v62, 0 }
    _R29 = -16;
    __asm { vspltw128 v111, v62, 1 }
    _R9 = 16;
    __asm
    {
      vspltw128 v110, v62, 2
      lvx128    v62, r30, r28
      vspltw128 v38, v58, 3
    }
    _R19 = 32;
    __asm { vspltw128 v37, v58, 0 }
    _R20 = 496;
    __asm { vspltw128 v36, v58, 1 }
    _R21 = 512;
    __asm
    {
      vspltw128 v35, v58, 2
      lvx128    v58, r0, r30
      vspltw128 v34, v57, 3
    }
    _R22 = 528;
    __asm { vspltw128 v33, v57, 0 }
    _R23 = 544;
    __asm { vspltw128 v32, v57, 1 }
    _R24 = -32;
    __asm
    {
      vspltw128 v127, v57, 2
      lvx128    v57, r30, r4
      vspltw128 v122, v55, 0
    }
    _R25 = -2064;
    __asm { vspltw128 v121, v55, 1 }
    _R26 = -2048;
    __asm { vspltw128 v120, v55, 2 }
    _R27 = -2032;
    __asm { vspltw128 v119, v54, 0 }
    _R28 = -2016;
    __asm
    {
      vspltw128 v118, v54, 1
      vspltw128 v117, v54, 2
      vspltw128 v116, v0, 0
      vspltw128 v115, v0, 1
      vspltw128 v114, v0, 2
      vspltw    v21, v13, 0
      vspltw    v20, v13, 1
      vspltw    v19, v13, 2
    }
    do
    {
      __asm
      {
        vor128    v7, v81, v49
        lvx128    v0, r7, r18
        vor128    v6, v77, v45
      }
      _R6 = -128;
      __asm
      {
        vor128    v5, v72, v40
        lvx128    v12, r0, r7
        vor128    v3, v65, v33
        vmaddcfp128 v7, v0, v7, v50
        vmr128    v2, v125
        vmaddcfp128 v6, v0, v6, v46
        vmaddcfp128 v0, v73, v0, v42
        lvx128    v13, r7, r6
      }
      _R6 = _R10 - 1;
      __asm
      {
        vmaddfp128 v7, v13, v48, v7
        vmaddfp128 v6, v13, v44, v6
        vmaddcfp128 v5, v13, v5, v0
        vor128    v0, v79, v47
        vor128    v13, v75, v43
        vmaddcfp128 v0, v12, v0, v7
        vmaddcfp128 v13, v12, v13, v6
        vmaddcfp128 v12, v71, v12, v5
        vor128    v5, v69, v37
        vsubfp128 v55, v0, v21
        vmrghw128 v54, v13, v63
        vmaddcfp128 v5, v0, v5, v38
        vmrghw    v1, v0, v12
        vmaddcfp128 v3, v0, v3, v34
        vmrglw    v31, v0, v12
        vmaddcfp128 v2, v0, v2, v126
        vmrglw128 v30, v13, v63
        vsubfp    v7, v13, v20
        vsubfp    v6, v12, v19
        vmrghw128 v29, v1, v54
        vmrglw128 v54, v1, v54
        vmrghw    v28, v31, v30
        vmrglw    v27, v31, v30
        vmulfp128 v1, v87, v122
        vmulfp128 v31, v87, v119
        stvx128   v29, r11, r29
        vmulfp128 v30, v87, v116
        stvx128   v54, r0, r11
        vmaddfp128 v5, v13, v36, v5
        stvx128   v28, r11, r9
        vmaddfp128 v3, v13, v32, v3
        stvx128   v27, r11, r19
        vmaddfp128 v2, v13, v124, v2
        vmaddfp128 v1, v7, v121, v1
        vmaddfp128 v31, v7, v118, v31
        vmaddfp128 v30, v7, v115, v30
        vmaddfp128 v5, v12, v35, v5
        vmaddfp128 v3, v12, v127, v3
        vmaddfp128 v2, v12, v123, v2
        vmaddfp128 v1, v6, v120, v1
        vmaddfp128 v31, v6, v117, v31
        vmaddfp128 v30, v6, v114, v30
        vmr128    v54, v5
        vmr128    v105, v3
        vmr128    v104, v2
        vmrghw128 v26, v105, v63
        vmrghw128 v25, v86, v104
        vmrglw128 v24, v86, v104
        vmrglw128 v18, v105, v63
        vmrghw128 v5, v31, v63
        vmrghw    v3, v1, v30
        vmrghw    v17, v25, v26
        vmrglw    v16, v25, v26
        vmrghw    v15, v24, v18
        vmrghw    v28, v3, v5
        vmrglw    v14, v24, v18
        vmrglw    v30, v1, v30
        vmrglw128 v29, v31, v63
        vmrglw    v27, v3, v5
        vmulfp128 v3, v87, v10
        stvx128   v17, r11, r20
        vmr128    v5, v112
        stvx128   v16, r11, r21
        stvx128   v15, r11, r22
        vmrghw128 v55, v30, v29
        stvx128   v14, r11, r23
        vmrglw    v26, v30, v29
        stvx128   v28, r8, r24
        vmaddcfp128 v5, v0, v5, v113
        stvx128   v55, r0, r8
        vmaddfp   v7, v7, v3, v9
        vmr128    v3, v111
      }
      _R5 = _R10 + 1;
      __asm
      {
        stvx128   v27, r8, r29
        stvx128   v26, r8, r9
      }
      _R4 = _R10 + 2;
      __asm
      {
        vaddfp128 v96, v0, v54
        vaddfp128 v95, v13, v105
        vaddfp128 v94, v12, v104
        vmaddcfp128 v3, v13, v3, v5
        vmaddfp   v5, v6, v7, v8
        vmr128    v7, v110
        vmaddcfp128 v7, v12, v7, v3
        vmaddfp   v6, v5, v21, v10
        vand128   v55, v7, v109
        vmaddfp   v7, v5, v20, v9
        vmaddfp   v5, v5, v19, v8
        vsubfp    v3, v0, v6
        vmaxfp128 v53, v85, v55
        vsubfp128 v55, v13, v7
        vmrghw128 v25, v7, v63
        vsubfp    v29, v12, v5
        vmrglw128 v24, v7, v63
        vmrghw    v18, v6, v5
        vmrglw    v17, v6, v5
        vmrghw    v16, v18, v25
        vmrglw    v15, v18, v25
        vmrghw    v14, v17, v24
        vmrglw    v28, v17, v24
        vmulfp128 v31, v87, v9
        stvlx     v16, r0, r6
        stvrx     v16, r6, r9
        stvlx     v15, r0, r10
        stvrx     v15, r10, r9
        stvlx     v14, r0, r5
        stvrx     v14, r5, r9
        stvlx     v28, r0, r4
        stvrx     v28, r4, r9
        vmaddfp   v3, v3, v31, v10
        vmaddfp   v3, v29, v3, v8
        vmaddfp   v7, v3, v7, v9
        vmaddfp   v5, v3, v5, v8
        vmaddfp   v6, v3, v6, v10
        vmr128    v103, v7
        vmr128    v102, v5
        vmr128    v101, v6
        vsubfp128 v24, v105, v103
        vsubfp128 v25, v13, v103
        vsubfp128 v55, v104, v102
        vsubfp128 v7, v12, v102
        vsubfp128 v6, v0, v101
        vsubfp128 v14, v86, v101
        vmulfp128 v28, v24, v8
        vmulfp128 v29, v25, v8
        vmulfp128 v27, v25, v25
        vor128    v3, v87, v55
        vmulfp128 v18, v87, v10
        vmulfp128 v15, v7, v10
        vnmsubfp  v5, v3, v28, v9
        vnmsubfp  v29, v7, v29, v9
        vmaddfp   v3, v6, v27, v6
        vmr       v27, v24
        vnmsubfp  v16, v14, v18, v8
        vmr       v24, v10
        vmulfp128 v14, v14, v9
        vxor128   v55, v29, v5
        vmaddfp   v5, v7, v3, v7
        vmr       v29, v6
        vsraw128  v100, v87, v60
        vmulfp128 v55, v6, v9
        vmulfp128 v99, v5, v108
        vmulfp128 v98, v5, v107
        vmulfp128 v97, v5, v106
        vcmpeqfp128 v17, v99, v58
        vmr128    v31, v99
        vcmpeqfp128 v18, v98, v58
        vmr128    v6, v98
        vcmpeqfp128 v30, v97, v58
        vmr128    v7, v97
        vnmsubfp  v15, v29, v15, v8
        vsel      v29, v31, v22, v17
        vsel      v2, v7, v22, v30
        vnmsubfp  v28, v27, v14, v10
        vsel      v1, v6, v22, v18
        vmulfp128 v18, v63, v59
        vor128    v27, v87, v55
        vmulfp128 v17, v62, v59
        vrsqrtefp v7, v29
      }
      v21 += 4;
      __asm { vrsqrtefp v5, v2 }
      _R10 += 4;
      __asm { vrsqrtefp v6, v1 }
      _R7 += 4;
      __asm { vmulfp128 v29, v96, v59 }
      _R8 += 4;
      __asm
      {
        vnmsubfp128 v27, v25, v24, v27
        vminfp128 v3, v0, v54
        vxor128   v55, v15, v16
        vcmpgtfp128 v25, v103, v18
        vcmpgtfp128 v24, v102, v17
        vmulfp128 v30, v99, v7
        vsraw128  v55, v87, v60
        vmulfp128 v16, v7, v57
        vmulfp128 v31, v98, v6
        vmulfp128 v1, v97, v5
        vcmpgtfp128 v29, v101, v29
        vxor      v18, v27, v28
        vmulfp128 v15, v6, v57
        vmulfp128 v14, v5, v57
        vsraw128  v17, v18, v60
        vand128   v26, v87, v25
        vmaddfp   v30, v30, v23, v7
        vand      v27, v17, v24
        vmaddfp   v6, v31, v23, v6
        vmaddfp   v7, v1, v23, v5
        vand128   v1, v24, v56
        vmaxfp128 v5, v0, v54
        vand128   v2, v100, v29
        vand128   v54, v29, v56
        vminfp128 v31, v13, v105
        vandc128  v28, v100, v29
        vandc128  v29, v87, v25
        vand128   v0, v25, v56
        vmulfp128 v30, v16, v30
        vmulfp128 v55, v15, v6
        vmulfp128 v25, v14, v7
        vmulfp128 v18, v30, v99
        vandc     v30, v17, v24
        vmulfp128 v55, v87, v98
        vmulfp128 v16, v25, v97
        vxor128   v54, v18, v54
        vxor128   v55, v87, v0
        vxor      v15, v16, v1
        vaddfp128 v54, v86, v101
        vaddfp128 v55, v87, v103
        vaddfp128 v0, v15, v102
        vor128    v7, v86, v54
        vor128    v6, v86, v54
        vor128    v1, v87, v55
        vsel      v14, v3, v7, v2
        vminfp128 v2, v12, v104
        vmaxfp128 v7, v13, v105
        vsel      v3, v5, v6, v28
        vmaxfp128 v13, v12, v104
        vsel      v26, v31, v1, v26
        vor128    v12, v87, v55
        vmrghw128 v54, v26, v63
        vmrglw128 v31, v26, v63
        vsel      v1, v2, v0, v27
        vsel      v6, v7, v12, v29
        vsel      v12, v13, v0, v30
        vmrghw128 v55, v14, v1
        vmrghw128 v13, v6, v63
        vmrghw    v7, v3, v12
        vmrglw    v0, v14, v1
        vmrghw128 v5, v87, v54
        vmrglw    v3, v3, v12
        vmrglw128 v2, v6, v63
        vmrghw    v1, v7, v13
        vsubfp128 v30, v5, v62
        vaddfp128 v29, v1, v62
        vmrghw    v27, v0, v31
        vmrghw    v28, v3, v2
        vaddfp128 v15, v30, v61
        vmrglw128 v54, v87, v54
        vminfp128 v52, v84, v30
        vmrglw128 v55, v7, v13
      }
      __asm
      {
        vsubfp128 v18, v27, v62
        vmrglw    v26, v0, v31
        vaddfp128 v24, v28, v62
        vmrglw    v25, v3, v2
        vsubfp128 v54, v86, v62
        vaddfp128 v55, v87, v62
        vsubfp128 v17, v26, v62
        vaddfp128 v16, v25, v62
        vsubfp128 v14, v29, v61
        vctsxs    v3, v15, 0
        vmaxfp128 v51, v83, v29
        vaddfp128 v7, v18, v61
        vsubfp128 v12, v24, v61
        vaddfp128 v0, v86, v61
        vsubfp128 v13, v87, v61
        vaddfp128 v6, v17, v61
        vsubfp128 v5, v16, v61
        vminfp128 v54, v84, v54
        vctsxs    v2, v14, 0
        vsubsws   v26, v3, v11
        vmaxfp128 v52, v83, v55
        vctsxs    v29, v7, 0
        vctsxs    v30, v12, 0
        vctsxs    v1, v0, 0
        vctsxs    v31, v13, 0
        vctsxs    v28, v6, 0
        vctsxs    v27, v5, 0
        vminfp128 v51, v86, v18
        vaddsws   v25, v2, v11
        vmaxfp128 v24, v84, v24
        vpkswss128 v55, v26, v25
        vsubsws   v0, v29, v11
        vaddsws   v14, v30, v11
        vsubsws   v18, v1, v11
        vaddsws   v15, v31, v11
        vperm128  v12, v87, v55, v4
        vsubsws   v13, v28, v11
        vpkswss128 v55, v0, v14
        vaddsws   v7, v27, v11
        vminfp128 v52, v83, v17
        vpkswss128 v54, v18, v15
        vperm128  v55, v87, v55, v4
        vmaxfp128 v51, v24, v16
        vperm128  v54, v86, v54, v4
        stvx128   v12, r11, r25
        stvx128   v55, r11, r27
        vpkswss128 v55, v13, v7
        stvx128   v54, r11, r26
        vperm128  v54, v87, v55, v4
        stvx128   v54, r11, r28
      }
      _R11 += 4;
    }
    while ( v21 < tw->numVerts );
  }
  _R11 = 80;
  _R10 = 6224;
  _R9 = 6144;
  _R8 = 6160;
  __asm
  {
    lvx128    v63, r30, r11
    vaddfp128 v53, v85, v63
    vpermwi128 v50, v53, 0xB1
    vmaxfp128 v49, v85, v50
    vpermwi128 v48, v49, 0x4E # 'N'
    vmaxfp128 v47, v81, v48
    stvewx128 v47, r3, r10
    stvx128   v52, r3, r9
    stvx128   v51, r3, r8
  }
}


// ========================================================================
// ?RotationEdges@idPolygonModelCollisionDetection@@CAXPIAVidTraceWork@@PIBVidTraceModel@@PIBVidVec4@@@Z
// EA  : 0x825ECE08
// RVA : 0x005ECE08
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::RotationEdges(
        idTraceWork *tw,
        const idTraceModel *trm,
        const idVec4 *zverts)
{
  int v18; // r4
  int v20; // r28
  int v22; // r30
  int v24; // r26
  int v26; // r22
  int v28; // r24
  int v30; // r20
  int v32; // r18
  int v36; // r6
  __int64 back_chain; // [sp+20h] [-A0h]

  _R11 = 6288;
  _R9 = 6304;
  __asm { vspltisw128 v52, 0 }
  _R6 = 6048;
  _R31 = 6064;
  __asm { lvx128    v63, r3, r11 }
  _R11 = 6080;
  __asm { lvx128    v62, r3, r9 }
  _R8 = 0x18B000000000LL;
  __asm
  {
    lvx128    v61, r3, r7
    vspltw128 v60, v63, 0
    vspltw128 v59, v62, 0
    lvx128    v58, r3, r6
    vspltw128 v57, v61, 0
    lvx128    v0, r3, r31
    vspltw128 v11, v63, 1
    lvx128    v13, r3, r11
    vmulfp128 v12, v90, v60
    vspltw128 v9, v62, 1
    vmulfp128 v10, v90, v59
    vspltw128 v7, v61, 1
    vmulfp128 v8, v90, v57
    vspltw128 v6, v63, 2
    vspltw128 v5, v62, 2
  }
  __asm
  {
    vspltw128 v4, v61, 2
    vmaddfp   v12, v0, v12, v11
    vmaddfp   v11, v0, v10, v9
    vmaddfp   v10, v0, v8, v7
    vmaddfp   v0, v13, v12, v6
    vmaddfp   v12, v13, v11, v5
    vmaddfp   v13, v13, v10, v4
  }
  if ( tw->numEdges != 0 )
  {
    __asm { vspltw128 v51, v0, 0 }
    _R9 = (unsigned __int16 *)trm->edges + 1;
    __asm { vspltw    v22, v0, 1 }
    _R4 = vmxi_pluecker_perm3;
    __asm { vspltw    v21, v0, 2 }
    _R6 = 16;
    __asm { vspltw128 v50, v12, 0 }
    _R7 = 32;
    __asm { vspltw    v20, v12, 1 }
    _R31 = -176;
    __asm { vspltw    v19, v12, 2 }
    _R30 = -16;
    __asm
    {
      vspltw128 v49, v13, 0
      lvx128    v7, r0, r4
    }
    _R10 = &tw->edgePluecker[0].p[4];
    __asm { lvx128    v54, r4, r6 }
    _R11 = &tw->edges[1];
    __asm
    {
      lvx128    v53, r4, r7
      vspltw    v18, v13, 1
      lvx128    v63, r4, r31
      vspltw    v17, v13, 2
      lvx128    v0, r4, r30
    }
    do
    {
      v18 = *(_R9 - 1);
      _R31 = -16;
      v20 = _R9[1];
      _R29 = 16;
      v22 = *_R9;
      _R27 = __ROL4__(v18, 4);
      v24 = _R9[2];
      _R23 = __ROL4__(v20, 4);
      v26 = _R9[4];
      _R25 = __ROL4__(v22, 4);
      v28 = _R9[3];
      _R21 = __ROL4__(v24, 4);
      v30 = _R9[5];
      _R17 = __ROL4__(v26, 4);
      v32 = _R9[6];
      _R19 = __ROL4__(v28, 4);
      _R16 = __ROL4__(v30, 4);
      __asm { lvx128    v13, r27, r3 }
      _R15 = __ROL4__(v32, 4);
      __asm
      {
        lvx128    v12, r25, r3
        lvx128    v11, r23, r3
        vmaxsh    v9, v13, v12
        lvx128    v10, r21, r3
        vminsh    v8, v13, v12
        vmaxsh    v6, v11, v10
        lvx128    v13, r19, r3
        vminsh    v5, v11, v10
        lvx128    v11, r16, r3
        lvx128    v10, r15, r3
      }
      __asm
      {
        lvx128    v12, r17, r3
        vmaxsh    v2, v11, v10
        vmaxsh    v4, v13, v12
      }
      __asm { vminsh    v3, v13, v12 }
      __asm { vminsh    v1, v11, v10 }
      v36 = 16 * (v18 + 128);
      __asm { vand128   v56, v9, v53 }
      HIDWORD(_R8) = v22;
      __asm { vand128   v55, v8, v54 }
      back_chain = _R8;
      __asm { vand128   v48, v6, v53 }
      _R8 = 32;
      __asm { vand128   v47, v5, v54 }
      __asm { vand128   v46, v4, v53 }
      __asm { vand128   v45, v3, v54 }
      __asm { vand128   v44, v2, v53 }
      __asm { vand128   v43, v1, v54 }
      __asm { vor128    v42, v87, v56 }
      __asm { vor128    v41, v79, v48 }
      __asm { vor128    v40, v77, v46 }
      __asm { vor128    v39, v75, v44 }
      __asm { stvx128   v42, r11, r31 }
      __asm { stvx128   v41, r0, r11 }
      _R14 = 16 * (v20 + 128);
      __asm { stvx128   v40, r11, r29 }
      __asm { stvx128   v39, r11, r8 }
      _R11[-1].vertexNum[0] = v18;
      _R11[-1].vertexNum[1] = v22;
      _R11->vertexNum[0] = v20;
      _R4 = 16 * (v24 + 128);
      _R11->vertexNum[1] = v24;
      _R11[1].vertexNum[0] = v28;
      _R11[1].vertexNum[1] = v26;
      _R11[2].vertexNum[0] = v30;
      _R11[2].vertexNum[1] = v32;
      __asm { lvx128    v35, r4, r3 }
      __asm { lvx128    v38, r14, r3 }
      _R7 = 16 * (v32 + 128);
      _R31 = v36;
      __asm { vor128    v59, v67, v63 }
      _R4 = 16 * (v30 + 128);
      __asm
      {
        lvx128    v45, r7, r3
        lvx128    v37, r31, r3
      }
      _R31 = 16 * (v22 + 128);
      __asm
      {
        vor128    v62, v69, v63
        lvx128    v46, r4, r3
      }
      __asm { lvx128    v36, r31, r3 }
      _R6 = 16 * (v28 + 128);
      __asm { vor128    v61, v68, v63 }
      __asm
      {
        vor128    v60, v70, v63
        lvx128    v58, r6, r3
        vpermwi128 v34, v61, 0x6E # 'n'
      }
      _R31 = 16 * (v26 + 128);
      __asm
      {
        vpermwi128 v33, v62, 1
        vor128    v58, v90, v63
        vperm128  v48, v93, v59, v7
        lvx128    v47, r31, r3
        vor128    v57, v79, v63
        vperm128  v32, v94, v60, v0
        vor128    v56, v78, v63
        vor128    v55, v77, v63
        vmulfp128 v4, v65, v34
        vpermwi128 v44, v58, 1
        vor128    v6, v91, v59
        vpermwi128 v43, v57, 0x6E # 'n'
        lvx128    v38, r27, r5
        vmulfp128 v31, v64, v48
        vperm128  v42, v90, v56, v0
        vperm128  v41, v89, v55, v7
        vor128    v12, v87, v55
        vpermwi128 v40, v59, 0xED
        lvx128    v37, r25, r5
        vpermwi128 v39, v55, 0xED
        vmulfp128 v29, v76, v43
        vpermwi128 v11, v62, 0x6E # 'n'
        lvx128    v36, r23, r5
        vmulfp128 v2, v74, v41
        vpermwi128 v13, v61, 1
        vmulfp128 v30, v92, v40
        vperm128  v8, v94, v60, v7
        vmulfp128 v3, v88, v39
        vperm128  v10, v93, v59, v0
        vpermwi128 v9, v58, 0x6E # 'n'
        lvx128    v35, r21, r5
        vnmsubfp  v1, v13, v4, v11
        vpermwi128 v4, v57, 1
        vperm128  v11, v90, v56, v7
        lvx128    v34, r19, r5
        vpermwi128 v5, v60, 0xED
        lvx128    v33, r17, r5
        vnmsubfp  v31, v10, v31, v8
        vperm128  v10, v89, v55, v0
        vpermwi128 v13, v56, 0xED
      }
      _R30 = -16;
      __asm
      {
        vor128    v62, v70, v63
        vnmsubfp  v8, v4, v29, v9
      }
      _R6 = 16;
      _R4 = 32;
      __asm
      {
        vor128    v61, v69, v63
        vnmsubfp  v9, v10, v2, v11
      }
      _R7 = 48;
      _R31 = 64;
      __asm
      {
        vor128    v60, v68, v63
        vnmsubfp  v30, v6, v30, v5
        vor128    v59, v67, v63
        vnmsubfp  v11, v12, v3, v13
        stvx128   v8, r10, r4
      }
      _R4 = _R16;
      __asm { stvx128   v30, r10, r6 }
      _R6 = -962;
      __asm
      {
        vor128    v58, v66, v63
        vor128    v57, v65, v63
        vpermwi128 v48, v61, 0x6E # 'n'
        vpermwi128 v47, v62, 1
        stvx128   v9, r10, r7
        lvx128    v32, r4, r5
      }
      _R4 = _R15;
      __asm
      {
        vor128    v56, v64, v63
        vperm128  v46, v93, v59, v7
        lvx128    v44, r9, r6
        vperm128  v45, v94, v60, v0
        vmulfp128 v6, v76, v51
      }
      _R7 = -834;
      __asm
      {
        vmulfp128 v8, v76, v50
        vpermwi128 v43, v59, 0xED
        lvx128    v55, r4, r5
        vmulfp128 v10, v76, v49
        vor128    v55, v87, v63
        vpermwi128 v42, v57, 0x6E # 'n'
        vpermwi128 v41, v58, 1
        vmulfp128 v26, v79, v48
        vperm128  v39, v90, v56, v0
        vmulfp128 v27, v77, v46
        vmulfp128 v28, v92, v43
        lvx128    v13, r9, r7
        vperm128  v40, v89, v55, v7
        stvx128   v1, r10, r30
        vmulfp128 v29, v73, v42
        vpermwi128 v9, v62, 0x6E # 'n'
        vpermwi128 v1, v61, 1
      }
      _R6 = -706;
      __asm
      {
        vperm128  v3, v94, v60, v7
        vor128    v4, v91, v59
        vmulfp128 v30, v71, v40
        vperm128  v2, v93, v59, v0
        vmaddfp   v23, v13, v6, v22
        vpermwi128 v5, v60, 0xED
        vmaddfp   v24, v13, v8, v20
        vpermwi128 v6, v57, 1
        vmaddfp   v25, v13, v10, v18
        vpermwi128 v8, v58, 0x6E # 'n'
        vperm128  v10, v90, v56, v7
        lvx128    v12, r9, r6
        vnmsubfp  v26, v1, v26, v9
        vperm128  v9, v89, v55, v0
        vpermwi128 v38, v55, 0xED
        vnmsubfp  v1, v2, v27, v3
        vnmsubfp  v3, v4, v28, v5
        stvx128   v31, r0, r10
        stvx128   v11, r10, r31
      }
      _R4 = 752;
      __asm { vnmsubfp  v5, v6, v29, v8 }
      __asm { vmulfp128 v31, v88, v38 }
      _R6 = 784;
      _R31 = 800;
      __asm
      {
        vor128    v11, v87, v55
        vnmsubfp  v6, v9, v30, v10
      }
      _R30 = 816;
      __asm
      {
        vmaddfp   v8, v12, v23, v21
        vpermwi128 v13, v56, 0xED
        vmaddfp   v9, v12, v24, v19
      }
      _R7 = HIDWORD(back_chain);
      __asm { vmaddfp   v10, v12, v25, v17 }
      _R29 = 832;
      _R28 = 4848;
      LODWORD(_R8) = back_chain + 4;
      __asm { stvx128   v26, r10, r4 }
      _R9 += 8;
      __asm
      {
        stvx128   v1, r10, r7
        stvx128   v3, r10, r6
        stvx128   v5, r10, r31
        vnmsubfp  v12, v11, v31, v13
        stvx128   v6, r10, r30
        vmrghw128 v37, v9, v52
        vmrghw128 v36, v8, v10
        vmrglw128 v35, v8, v10
      }
      _R4 = 4864;
      __asm { vmrglw128 v34, v9, v52 }
      HIDWORD(_R8) = 4880;
      __asm { vmrghw128 v33, v68, v37 }
      _R6 = 4896;
      __asm
      {
        vmrglw128 v32, v68, v37
        stvx128   v12, r10, r29
      }
      _R10 += 24;
      __asm
      {
        vmrghw128 v62, v67, v34
        vmrglw128 v61, v67, v34
        stvx128   v33, r11, r28
        stvx128   v32, r11, r4
        stvx128   v62, r11, r7
        stvx128   v61, r11, r6
      }
      _R11 += 4;
    }
    while ( (unsigned int)(back_chain + 4) < tw->numEdges );
  }
}


// ========================================================================
// ?RotationPolys@idPolygonModelCollisionDetection@@CAXPIAVidTraceWork@@PIBVidTraceModel@@@Z
// EA  : 0x825ED318
// RVA : 0x005ED318
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::RotationPolys(idTraceWork *tw, const idTraceModel *trm)
{
  unsigned int v6; // r28
  unsigned int maxPolyEdges; // r24
  int v32; // r8
  unsigned int v33; // ctr
  unsigned int v38; // r4
  unsigned int v39; // r31
  unsigned int v40; // r30
  unsigned int v41; // r29

  _R11 = 6048;
  _R9 = 6064;
  _R8 = 6080;
  v6 = 0;
  __asm
  {
    lvx128    v63, r3, r11
    lvx128    v62, r3, r9
    lvx128    v61, r3, r8
  }
  if ( tw->numPolys != 0 )
  {
    maxPolyEdges = trm->maxPolyEdges;
    _R9 = trm->polyEdges[1];
    __asm { vspltw128 v60, v63, 0 }
    _R10 = trm->polyPlaneY;
    __asm { vspltw128 v4, v63, 1 }
    _R4 = vmxi_half_bounds_max_mask;
    __asm { vspltw128 v3, v63, 2 }
    _R5 = -16;
    __asm { vspltw128 v59, v62, 0 }
    _R25 = -64;
    __asm { vspltw128 v2, v62, 1 }
    _R26 = 64;
    __asm
    {
      vspltw128 v1, v62, 2
      vspltw128 v58, v61, 0
    }
    _R11 = &tw->polys[1];
    __asm
    {
      vspltw128 v31, v61, 1
      lvx128    v56, r0, r4
      vspltw128 v30, v61, 2
      lvx128    v57, r4, r5
    }
    __asm { vspltw128 v63, v63, 3 }
    _R7 = 64;
    __asm
    {
      vspltw128 v62, v62, 3
      vspltw128 v61, v61, 3
    }
    _R27 = 128;
    _R16 = -48;
    _R17 = 16;
    _R18 = 80;
    _R19 = 144;
    _R20 = -32;
    _R21 = 32;
    _R22 = 96;
    _R23 = 160;
    do
    {
      __asm
      {
        lvx128    v55, r10, r8
        vor128    v10, v95, v63
        vmulfp128 v6, v87, v60
        lvx128    v0, r0, r10
        vmulfp128 v7, v87, v59
        lvx128    v13, r10, r7
        vmulfp128 v9, v87, v58
        lvx128    v8, r10, r27
        vor128    v11, v94, v62
      }
      __asm { vor128    v12, v93, v61 }
      _R4 = 16 * ((*_R9 & 0x7F) + 32);
      __asm { vmaddfp   v5, v0, v6, v4 }
      __asm { vmaddfp   v6, v0, v7, v2 }
      __asm { vmaddfp   v0, v0, v9, v31 }
      _R31 = 16 * ((_R9[16] & 0x7F) + 32);
      _R30 = 16 * ((_R9[32] & 0x7F) + 32);
      _R29 = 16 * ((*(_R9 - 16) & 0x7F) + 32);
      _R7 = _R9 - 16;
      _R6 = _R9 + 16;
      _R5 = _R9 + 32;
      v32 = 1;
      __asm
      {
        vmaddfp   v7, v13, v5, v3
        vmaddfp   v9, v13, v6, v1
        vmaddfp   v0, v13, v0, v30
        vnmsubfp  v8, v7, v8, v10
        vmr128    v54, v9
        vmr128    v53, v0
        vor128    v13, v86, v54
        vmrghw128 v52, v7, v53
        vmrglw128 v51, v7, v53
        vnmsubfp  v10, v13, v8, v11
        vnmsubfp  v13, v0, v10, v12
        vmrghw128 v50, v86, v13
        vmrglw128 v49, v86, v13
        vmrghw128 v48, v84, v50
        vmrglw128 v47, v84, v50
        vmrghw128 v46, v83, v49
        vmrglw128 v45, v83, v49
        stvx128   v48, r11, r25
        stvx128   v47, r0, r11
        stvx128   v46, r11, r26
        stvx128   v45, r11, r27
        lvx128    v12, r31, r3
        lvx128    v11, r30, r3
        lvx128    v0, r29, r3
        lvx128    v13, r4, r3
        vmr       v9, v13
        vmr       v10, v0
        vmr       v8, v12
        vmr       v7, v11
      }
      if ( maxPolyEdges > 1 )
      {
        v33 = maxPolyEdges - 1;
        do
        {
          _R4 = 16 * ((_R7[v32] & 0x7F) + 32);
          _R31 = 16 * ((_R9[v32] & 0x7F) + 32);
          _R30 = 16 * ((_R6[v32] & 0x7F) + 32);
          _R29 = 16 * ((_R5[v32] & 0x7F) + 32);
          __asm
          {
            lvx128    v6, r4, r3
            lvx128    v5, r31, r3
            vminsh    v29, v0, v6
            vminsh    v28, v13, v5
          }
          ++v32;
          __asm
          {
            vmaxsh    v10, v10, v6
            lvx128    v0, r30, r3
            vmaxsh    v9, v9, v5
            lvx128    v13, r29, r3
            vminsh    v12, v12, v0
            vminsh    v11, v11, v13
            vmaxsh    v8, v8, v0
            vmaxsh    v7, v7, v13
            vmr       v0, v29
            vmr       v13, v28
          }
          --v33;
        }
        while ( v33 != 0 );
      }
      __asm { vand128   v44, v10, v56 }
      v38 = *((_DWORD *)_R10 + 112);
      __asm { vand128   v43, v0, v57 }
      v39 = *((_DWORD *)_R10 + 115);
      __asm { vand128   v42, v9, v56 }
      v40 = *((_DWORD *)_R10 + 113);
      __asm { vand128   v41, v13, v57 }
      v41 = *((_DWORD *)_R10 + 114);
      __asm
      {
        vand128   v40, v8, v56
        lvx128    v39, r0, r9
        vand128   v38, v12, v57
        lvx128    v37, r0, r7
        vand128   v36, v7, v56
        lvx128    v35, r0, r6
        vand128   v34, v11, v57
        lvx128    v33, r0, r5
        vor128    v32, v75, v44
      }
      v6 += 4;
      __asm { vor128    v55, v73, v42 }
      _R10 += 4;
      __asm { vor128    v54, v70, v40 }
      _R9 += 64;
      __asm { vor128    v53, v66, v36 }
      __asm { stvx128   v32, r11, r16 }
      _R7 = 64;
      __asm
      {
        stvx128   v55, r11, r17
        stvx128   v54, r11, r18
        stvx128   v53, r11, r19
      }
      _R11[-1].numEdges = v38;
      __asm { stvx128   v37, r11, r20 }
      _R11[2].numEdges = v39;
      __asm { stvx128   v39, r11, r21 }
      _R11->numEdges = v40;
      __asm { stvx128   v35, r11, r22 }
      _R11[1].numEdges = v41;
      __asm { stvx128   v33, r11, r23 }
      _R11 += 4;
    }
    while ( v6 < tw->numPolys );
  }
}


// ========================================================================
// ?RotationBounds@idPolygonModelCollisionDetection@@CAXPIAVidTraceWork@@@Z
// EA  : 0x825ED600
// RVA : 0x005ED600
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::RotationBounds(idTraceWork *tw)
{
  _R10 = 6144;
  _R9 = vmxi_word_perm_bounds_short_2;
  _R8 = 6160;
  _R7 = -112;
  _R6 = 5984;
  __asm { lvx128    v62, r3, r10 }
  _R5 = -64;
  _R4 = -16;
  __asm
  {
    lvx128    v7, r0, r9
    lvx128    v61, r3, r8
  }
  _R11 = 6096;
  __asm { lvx128    v63, r9, r7 }
  _R10 = 6112;
  __asm
  {
    vaddfp128 v60, v94, v63
    lvx128    v59, r3, r6
    vsubfp128 v58, v93, v63
    lvx128    v63, r9, r5
    vsubfp128 v57, v94, v59
    lvx128    v0, r9, r4
    vsubfp128 v56, v93, v59
  }
  _R9 = 6128;
  _R8 = 6176;
  __asm
  {
    vcfpsxws128 v13, v60, 0
    vcfpsxws128 v12, v58, 0
    vand128   v55, v89, v63
    stvx128   v57, r3, r11
    vand128   v54, v88, v63
    stvx128   v56, r3, r10
    vmaxfp128 v53, v87, v54
    vsubsws   v11, v13, v0
    vaddsws   v10, v12, v0
    vpkswss128 v63, v11, v10
    stvx128   v53, r3, r9
    vperm128  v52, v95, v63, v7
    stvx128   v52, r3, r8
  }
}


// ========================================================================
// ?RotationEdgePlueckerCache@idPolygonModelCollisionDetection@@CAXPIAVidTraceWork@@PIBUcm_polygon_t@@@Z
// EA  : 0x825ED698
// RVA : 0x005ED698
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::RotationEdgePlueckerCache(
        idTraceWork *tw,
        const cm_polygon_t *polygon)
{
  int v6; // r6
  int firstEdge; // r21
  unsigned int v14; // ctr
  unsigned __int16 *polygonEdges; // r8
  cm_edge_t *edges; // r10
  unsigned __int16 *v24; // r9
  unsigned __int16 v25; // r18
  int v26; // r19
  cm_edge_t *v27; // r9
  int v28; // r7
  cm_edge_t *v29; // r8
  cm_edge_t *v30; // r7
  cm_edge_t *v31; // r10

  _R10 = 6288;
  _R9 = 6304;
  _R8 = 6320;
  v6 = 0;
  __asm
  {
    lvx128    v63, r3, r10
    lvx128    v62, r3, r9
    lvx128    v61, r3, r8
  }
  if ( polygon->numEdges != 0 )
  {
    firstEdge = polygon->firstEdge;
    __asm { vspltw128 v2, v63, 3 }
    _R22 = -16;
    __asm
    {
      vspltw128 v1, v62, 3
      vspltw128 v31, v61, 3
    }
    _R23 = 16;
    __asm
    {
      vspltw128 v30, v63, 0
      vspltw128 v29, v63, 1
    }
    __asm { vspltw128 v28, v62, 0 }
    _R24 = 32;
    __asm { vspltw128 v27, v62, 1 }
    _R25 = 48;
    __asm { vspltw128 v26, v61, 0 }
    _R26 = 64;
    v14 = (((unsigned int)polygon->numEdges - 1) >> 2) + 1;
    _R11 = &tw->polygonEdgePlueckerCache[0].p[4];
    __asm
    {
      vspltw128 v25, v61, 1
      vspltw128 v24, v63, 2
    }
    _R27 = 368;
    __asm { vspltw128 v23, v62, 2 }
    _R28 = 384;
    __asm { vspltw128 v22, v61, 2 }
    _R29 = 400;
    _R30 = 416;
    _R31 = 432;
    _R4 = 448;
    do
    {
      polygonEdges = tw->subModelPtrs.polygonEdges;
      edges = tw->subModelPtrs.edges;
      _R20 = tw->subModelPtrs.vertices;
      v24 = &polygonEdges[firstEdge + v6];
      v25 = v24[1];
      v26 = polygonEdges[firstEdge + 3 + v6] & 0x3FFF;
      v27 = &edges[*v24 & 0x3FFF];
      v28 = polygonEdges[firstEdge + 2 + v6] & 0x3FFF;
      v29 = &edges[v25 & 0x3FFF];
      v30 = &edges[v28];
      v31 = &edges[v26];
      _R5 = __ROL4__(v27->vertexNum[0], 4);
      _R9 = __ROL4__(v27->vertexNum[1], 4);
      _R19 = __ROL4__(v29->vertexNum[0], 4);
      _R18 = __ROL4__(v30->vertexNum[0], 4);
      __asm { lvx128    v63, r5, r20 }
      _R8 = __ROL4__(v29->vertexNum[1], 4);
      _R7 = __ROL4__(v30->vertexNum[1], 4);
      __asm { lvx128    v62, r9, r20 }
      _R17 = __ROL4__(v31->vertexNum[0], 4);
      __asm { lvx128    v61, r19, r20 }
      _R5 = __ROL4__(v31->vertexNum[1], 4);
      __asm
      {
        lvx128    v59, r18, r20
        lvx128    v60, r8, r20
        vmrghw128 v56, v95, v59
        lvx128    v58, r7, r20
        vmrglw128 v48, v95, v59
        lvx128    v57, r17, r20
        lvx128    v55, r5, r20
        vmrglw128 v50, v94, v58
        vmrghw128 v53, v93, v57
        vmrglw128 v51, v92, v55
        vmrghw128 v54, v94, v58
        vmrghw128 v52, v92, v55
        vmrghw128 v0, v88, v53
        vmrglw128 v10, v88, v53
        vmrghw128 v12, v82, v51
        vmrglw128 v13, v86, v52
        vmrglw128 v49, v93, v57
        vmaddfp   v6, v0, v2, v30
        vmrghw128 v11, v86, v52
        vmulfp128 v20, v0, v12
        vmulfp128 v19, v10, v12
        vmr       v4, v13
        vmulfp128 v21, v0, v13
        vmrghw128 v9, v80, v49
        vsubfp128 v47, v0, v11
        vmr       v3, v9
        vnmsubfp  v8, v11, v20, v9
        vnmsubfp  v7, v4, v19, v3
        vnmsubfp  v21, v11, v21, v10
        vmr128    v46, v8
        vmaddfp   v8, v11, v1, v28
        vmr128    v45, v7
        vmaddfp   v7, v11, v31, v26
        vmrghw128 v44, v21, v47
        vmaddfp   v11, v11, v2, v30
        vmrglw128 v43, v21, v47
        vmaddfp   v5, v0, v1, v28
        vmrghw128 v42, v78, v45
        vmaddfp   v0, v0, v31, v26
        vmrglw128 v41, v78, v45
        vmaddfp   v8, v13, v8, v27
      }
      v6 += 4;
      __asm
      {
        vmaddfp   v6, v10, v6, v29
        vmaddfp   v7, v13, v7, v25
        vmrglw128 v39, v76, v42
        vsubfp128 v40, v13, v10
        vmrglw128 v37, v75, v41
        vmaddfp   v13, v13, v11, v29
        vmrghw128 v36, v76, v42
        vsubfp128 v38, v9, v12
        vmrghw128 v35, v75, v41
        vmaddfp   v11, v10, v5, v27
        vmaddfp   v0, v10, v0, v25
        stvx128   v36, r11, r22
        vmaddfp   v8, v12, v8, v23
        stvx128   v35, r11, r24
        vmaddfp   v10, v9, v6, v24
        vmaddfp   v7, v12, v7, v22
        vmaddfp   v13, v12, v13, v24
        vmrghw128 v34, v70, v40
        vmrglw128 v33, v70, v40
        vsldoi128 v32, v66, v34, 8
        vmaddfp   v11, v9, v11, v23
        vsldoi128 v63, v65, v33, 8
        vmaddfp   v0, v9, v0, v22
        vmr128    v59, v8
        vmr128    v56, v10
        vsldoi128 v62, v64, v39, 8
        vmr128    v57, v7
        vsldoi128 v61, v71, v32, 8
        vsldoi128 v60, v95, v37, 8
        vmr128    v55, v13
        vsldoi128 v58, v69, v63, 8
        vmulfp128 v8, v88, v59
        vor128    v10, v91, v59
        vmulfp128 v7, v88, v57
        vor128    v12, v87, v55
        vsubfp128 v52, v88, v55
        stvx128   v62, r0, r11
        vmulfp128 v6, v11, v57
        vmr       v13, v11
        vmr128    v54, v0
        vsubfp128 v53, v91, v11
        vor128    v0, v87, v55
        stvx128   v61, r11, r23
        stvx128   v60, r11, r25
        stvx128   v58, r11, r26
        vor128    v11, v86, v54
        vsubfp128 v51, v86, v57
        vor128    v9, v86, v54
        vnmsubfp  v8, v0, v8, v13
        vnmsubfp  v0, v12, v7, v11
        vnmsubfp  v13, v10, v6, v9
        vmrghw128 v50, v83, v53
        vmrglw128 v49, v83, v53
        vmrghw128 v46, v8, v52
        vmrglw128 v45, v8, v52
        vsldoi128 v48, v82, v50, 8
        vsldoi128 v47, v81, v49, 8
        vmrghw128 v44, v0, v13
        vmrglw128 v43, v0, v13
        vmrglw128 v42, v78, v44
        vmrglw128 v41, v77, v43
        vmrghw128 v40, v78, v44
        vmrghw128 v39, v77, v43
        vsldoi128 v38, v80, v42, 8
        vsldoi128 v37, v74, v48, 8
        vsldoi128 v36, v79, v41, 8
        vsldoi128 v35, v73, v47, 8
        stvx128   v40, r11, r27
        stvx128   v39, r11, r30
        stvx128   v38, r11, r28
        stvx128   v37, r11, r29
        stvx128   v36, r11, r31
        stvx128   v35, r11, r4
      }
      _R11 += 24;
      --v14;
    }
    while ( v14 != 0 );
  }
}


// ========================================================================
// ?RotationCullPolygonEdges@idPolygonModelCollisionDetection@@CAXPIAVidTraceWork@@PIBUcm_polygon_t@@@Z
// EA  : 0x825ED9C8
// RVA : 0x005ED9C8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::RotationCullPolygonEdges(
        idTraceWork *tw,
        const cm_polygon_t *polygon)
{
  unsigned int i; // r28
  unsigned __int16 v5; // r7
  int v6; // r30
  int v7; // r29
  cm_edge_t *v8; // r11

  for ( i = 0; i < polygon->numEdges; ++i )
  {
    v5 = tw->subModelPtrs.polygonEdges[polygon->firstEdge + i];
    if ( (v5 & 0x4000) == 0 )
    {
      v6 = (tw->subModelPtrs.polygonEdges[polygon->firstEdge + i] & 0x3FFF) >> 3;
      v7 = 1 << (v5 & 7);
      if ( (tw->modelCheckCounts.edgeCheckCounts[v6] & (unsigned __int8)v7) == 0 )
      {
        v8 = &tw->subModelPtrs.edges[tw->subModelPtrs.polygonEdges[polygon->firstEdge + i] & 0x3FFF];
        if ( !idPolygonModelCollisionDetection::EdgeIntersectsBoundsShort(
                bounds: &tw->traceBoundsShort,
                start: (const idVec3 *)((char *)&tw->subModelPtrs.vertices->p + __ROL4__(v8->vertexNum[0], 4)),
                end: (const idVec3 *)((char *)&tw->subModelPtrs.vertices->p + __ROL4__(v8->vertexNum[1], 4))) )
          tw->modelCheckCounts.edgeCheckCounts[v6] |= v7;
      }
    }
  }
}


// ========================================================================
// ?CollisionBetweenEdgeBounds@idPolygonModelCollisionDetection@@CAHPIBVidTraceWork@@ABVidVec3@@111MAAV3@2@Z
// EA  : 0x825EDAA0
// RVA : 0x005EDAA0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::CollisionBetweenEdgeBounds(
        const idTraceWork *tw,
        const idVec3 *va,
        const idVec3 *vb,
        const idVec3 *vc,
        const idVec3 *vd,
        double tanHalfAngle,
        idVec3 *collisionPoint,
        idVec3 *collisionNormal,
        float *a9)
{
  double v9; // fp1
  double v10; // fp17
  double v11; // fp22
  double v12; // fp18
  double v13; // fp16
  double v14; // fp25
  double v15; // fp3
  double x; // fp9
  double y; // fp10
  double z; // fp11
  double v19; // fp6
  double v20; // fp7
  double v21; // fp8
  double v22; // fp1
  double v23; // fp3
  double v24; // fp2
  double v25; // fp24
  double v26; // fp5
  double v27; // fp4
  double v28; // fp3
  double v29; // fp5
  double v30; // fp1
  double v32; // fp12
  double v33; // fp27
  double v34; // fp3
  double v35; // fp4
  double v36; // fp8
  double v37; // fp3
  double v38; // fp0
  double v39; // fp0
  double v40; // fp13
  double v41; // fp6
  double v42; // fp5
  double v43; // fp4
  double v44; // fp3
  double v45; // fp1
  double v46; // fp31
  double angle; // fp30
  double v48; // fp0
  double v49; // fp13
  double v50; // fp12
  double v51; // fp0
  double v52; // fp13
  double v53; // fp10
  double v54; // fp7
  float v55; // [sp+0h] [-F0h]
  float v56; // [sp+8h] [-E8h]
  float v57; // [sp+Ch] [-E4h]
  float v58; // [sp+10h] [-E0h]
  const idVec3 v63; // 0:^18.12
  const idVec3 v64; // 0:^28.12

  v55 = 0.0;
  v63 = *va;
  v64 = *vb;
  if ( tanHalfAngle == 0.0 )
  {
    z = v63.z;
    y = v63.y;
    x = v63.x;
    v21 = v64.z;
    v20 = v64.y;
    v19 = v64.x;
  }
  else
  {
    v10 = (float)((float)((float)(v63.y - tw->origin.y)
                        - (float)(tw->axis.y
                                * (float)((float)(tw->axis.x * (float)(v63.x - tw->origin.x))
                                        + (float)((float)((float)(v63.y - tw->origin.y) * tw->axis.y)
                                                + (float)((float)(v63.z - tw->origin.z) * tw->axis.z)))))
                * (float)((float)((float)1.0 - (float)((float)tanHalfAngle * (float)tanHalfAngle))
                        * (float)((float)1.0 / (float)((float)((float)tanHalfAngle * (float)tanHalfAngle) + (float)1.0))));
    v11 = (float)((float)((float)(v63.z - tw->origin.z)
                        - (float)(tw->axis.z
                                * (float)((float)(tw->axis.x * (float)(v63.x - tw->origin.x))
                                        + (float)((float)((float)(v63.y - tw->origin.y) * tw->axis.y)
                                                + (float)((float)(v63.z - tw->origin.z) * tw->axis.z)))))
                * (float)((float)((float)1.0 - (float)((float)tanHalfAngle * (float)tanHalfAngle))
                        * (float)((float)1.0 / (float)((float)((float)tanHalfAngle * (float)tanHalfAngle) + (float)1.0))));
    v12 = (float)((float)((float)(v63.x - tw->origin.x)
                        - (float)(tw->axis.x
                                * (float)((float)(tw->axis.x * (float)(v63.x - tw->origin.x))
                                        + (float)((float)((float)(v63.y - tw->origin.y) * tw->axis.y)
                                                + (float)((float)(v63.z - tw->origin.z) * tw->axis.z)))))
                * (float)((float)((float)1.0 - (float)((float)tanHalfAngle * (float)tanHalfAngle))
                        * (float)((float)1.0 / (float)((float)((float)tanHalfAngle * (float)tanHalfAngle) + (float)1.0))));
    v13 = (float)((float)((float)(v64.x - tw->origin.x)
                        - (float)((float)((float)((float)(v64.z - tw->origin.z) * tw->axis.z)
                                        + (float)((float)((float)(v64.x - tw->origin.x) * tw->axis.x)
                                                + (float)((float)(v64.y - tw->origin.y) * tw->axis.y)))
                                * tw->axis.x))
                * (float)((float)((float)1.0 - (float)((float)tanHalfAngle * (float)tanHalfAngle))
                        * (float)((float)1.0 / (float)((float)((float)tanHalfAngle * (float)tanHalfAngle) + (float)1.0))));
    v14 = (float)((float)((float)(v64.y - tw->origin.y)
                        - (float)((float)((float)((float)(v64.z - tw->origin.z) * tw->axis.z)
                                        + (float)((float)((float)(v64.x - tw->origin.x) * tw->axis.x)
                                                + (float)((float)(v64.y - tw->origin.y) * tw->axis.y)))
                                * tw->axis.y))
                * (float)((float)((float)1.0 - (float)((float)tanHalfAngle * (float)tanHalfAngle))
                        * (float)((float)1.0 / (float)((float)((float)tanHalfAngle * (float)tanHalfAngle) + (float)1.0))));
    v15 = (float)((float)((float)(v64.z - tw->origin.z)
                        - (float)((float)((float)((float)(v64.z - tw->origin.z) * tw->axis.z)
                                        + (float)((float)((float)(v64.x - tw->origin.x) * tw->axis.x)
                                                + (float)((float)(v64.y - tw->origin.y) * tw->axis.y)))
                                * tw->axis.z))
                * (float)((float)((float)1.0 - (float)((float)tanHalfAngle * (float)tanHalfAngle))
                        * (float)((float)1.0 / (float)((float)((float)tanHalfAngle * (float)tanHalfAngle) + (float)1.0))));
    v9 = (float)((float)((float)((float)1.0 / (float)((float)((float)tanHalfAngle * (float)tanHalfAngle) + (float)1.0))
                       * (float)tanHalfAngle)
               * (float)2.0);
    x = (float)((float)((float)((float)v12
                              - (float)((float)((float)((float)((float)(v63.z - tw->origin.z)
                                                              - (float)(tw->axis.z
                                                                      * (float)((float)(tw->axis.x
                                                                                      * (float)(v63.x - tw->origin.x))
                                                                              + (float)((float)((float)(v63.y - tw->origin.y)
                                                                                              * tw->axis.y)
                                                                                      + (float)((float)(v63.z - tw->origin.z)
                                                                                              * tw->axis.z)))))
                                                      * tw->axis.y)
                                              - (float)((float)((float)(v63.y - tw->origin.y)
                                                              - (float)(tw->axis.y
                                                                      * (float)((float)(tw->axis.x
                                                                                      * (float)(v63.x - tw->origin.x))
                                                                              + (float)((float)((float)(v63.y - tw->origin.y)
                                                                                              * tw->axis.y)
                                                                                      + (float)((float)(v63.z - tw->origin.z)
                                                                                              * tw->axis.z)))))
                                                      * tw->axis.z))
                                      * (float)v9))
                      + (float)(tw->axis.x
                              * (float)((float)(tw->axis.x * (float)(v63.x - tw->origin.x))
                                      + (float)((float)((float)(v63.y - tw->origin.y) * tw->axis.y)
                                              + (float)((float)(v63.z - tw->origin.z) * tw->axis.z)))))
              + tw->origin.x);
    y = (float)((float)((float)((float)v10
                              - (float)((float)((float)((float)((float)(v63.x - tw->origin.x)
                                                              - (float)(tw->axis.x
                                                                      * (float)((float)(tw->axis.x
                                                                                      * (float)(v63.x - tw->origin.x))
                                                                              + (float)((float)((float)(v63.y - tw->origin.y)
                                                                                              * tw->axis.y)
                                                                                      + (float)((float)(v63.z - tw->origin.z)
                                                                                              * tw->axis.z)))))
                                                      * tw->axis.z)
                                              - (float)((float)((float)(v63.z - tw->origin.z)
                                                              - (float)(tw->axis.z
                                                                      * (float)((float)(tw->axis.x
                                                                                      * (float)(v63.x - tw->origin.x))
                                                                              + (float)((float)((float)(v63.y - tw->origin.y)
                                                                                              * tw->axis.y)
                                                                                      + (float)((float)(v63.z - tw->origin.z)
                                                                                              * tw->axis.z)))))
                                                      * tw->axis.x))
                                      * (float)v9))
                      + (float)(tw->axis.y
                              * (float)((float)(tw->axis.x * (float)(v63.x - tw->origin.x))
                                      + (float)((float)((float)(v63.y - tw->origin.y) * tw->axis.y)
                                              + (float)((float)(v63.z - tw->origin.z) * tw->axis.z)))))
              + tw->origin.y);
    z = (float)((float)((float)((float)v11
                              - (float)((float)((float)((float)((float)(v63.y - tw->origin.y)
                                                              - (float)(tw->axis.y
                                                                      * (float)((float)(tw->axis.x
                                                                                      * (float)(v63.x - tw->origin.x))
                                                                              + (float)((float)((float)(v63.y - tw->origin.y)
                                                                                              * tw->axis.y)
                                                                                      + (float)((float)(v63.z - tw->origin.z)
                                                                                              * tw->axis.z)))))
                                                      * tw->axis.x)
                                              - (float)((float)((float)(v63.x - tw->origin.x)
                                                              - (float)(tw->axis.x
                                                                      * (float)((float)(tw->axis.x
                                                                                      * (float)(v63.x - tw->origin.x))
                                                                              + (float)((float)((float)(v63.y - tw->origin.y)
                                                                                              * tw->axis.y)
                                                                                      + (float)((float)(v63.z - tw->origin.z)
                                                                                              * tw->axis.z)))))
                                                      * tw->axis.y))
                                      * (float)v9))
                      + (float)(tw->axis.z
                              * (float)((float)(tw->axis.x * (float)(v63.x - tw->origin.x))
                                      + (float)((float)((float)(v63.y - tw->origin.y) * tw->axis.y)
                                              + (float)((float)(v63.z - tw->origin.z) * tw->axis.z)))))
              + tw->origin.z);
    v19 = (float)((float)((float)((float)v13
                                - (float)((float)((float)((float)((float)(v64.z - tw->origin.z)
                                                                - (float)((float)((float)((float)(v64.z - tw->origin.z)
                                                                                        * tw->axis.z)
                                                                                + (float)((float)((float)(v64.x - tw->origin.x)
                                                                                                * tw->axis.x)
                                                                                        + (float)((float)(v64.y - tw->origin.y)
                                                                                                * tw->axis.y)))
                                                                        * tw->axis.z))
                                                        * tw->axis.y)
                                                - (float)((float)((float)(v64.y - tw->origin.y)
                                                                - (float)((float)((float)((float)(v64.z - tw->origin.z)
                                                                                        * tw->axis.z)
                                                                                + (float)((float)((float)(v64.x - tw->origin.x)
                                                                                                * tw->axis.x)
                                                                                        + (float)((float)(v64.y - tw->origin.y)
                                                                                                * tw->axis.y)))
                                                                        * tw->axis.y))
                                                        * tw->axis.z))
                                        * (float)v9))
                        + (float)((float)((float)((float)(v64.z - tw->origin.z) * tw->axis.z)
                                        + (float)((float)((float)(v64.x - tw->origin.x) * tw->axis.x)
                                                + (float)((float)(v64.y - tw->origin.y) * tw->axis.y)))
                                * tw->axis.x))
                + tw->origin.x);
    v20 = (float)((float)((float)((float)v14
                                - (float)((float)((float)((float)((float)(v64.x - tw->origin.x)
                                                                - (float)((float)((float)((float)(v64.z - tw->origin.z)
                                                                                        * tw->axis.z)
                                                                                + (float)((float)((float)(v64.x - tw->origin.x)
                                                                                                * tw->axis.x)
                                                                                        + (float)((float)(v64.y - tw->origin.y)
                                                                                                * tw->axis.y)))
                                                                        * tw->axis.x))
                                                        * tw->axis.z)
                                                - (float)((float)((float)(v64.z - tw->origin.z)
                                                                - (float)((float)((float)((float)(v64.z - tw->origin.z)
                                                                                        * tw->axis.z)
                                                                                + (float)((float)((float)(v64.x - tw->origin.x)
                                                                                                * tw->axis.x)
                                                                                        + (float)((float)(v64.y - tw->origin.y)
                                                                                                * tw->axis.y)))
                                                                        * tw->axis.z))
                                                        * tw->axis.x))
                                        * (float)v9))
                        + (float)((float)((float)((float)(v64.z - tw->origin.z) * tw->axis.z)
                                        + (float)((float)((float)(v64.x - tw->origin.x) * tw->axis.x)
                                                + (float)((float)(v64.y - tw->origin.y) * tw->axis.y)))
                                * tw->axis.y))
                + tw->origin.y);
    v21 = (float)((float)((float)((float)v15
                                - (float)((float)((float)((float)((float)(v64.y - tw->origin.y)
                                                                - (float)((float)((float)((float)(v64.z - tw->origin.z)
                                                                                        * tw->axis.z)
                                                                                + (float)((float)((float)(v64.x - tw->origin.x)
                                                                                                * tw->axis.x)
                                                                                        + (float)((float)(v64.y - tw->origin.y)
                                                                                                * tw->axis.y)))
                                                                        * tw->axis.y))
                                                        * tw->axis.x)
                                                - (float)((float)((float)(v64.x - tw->origin.x)
                                                                - (float)((float)((float)((float)(v64.z - tw->origin.z)
                                                                                        * tw->axis.z)
                                                                                + (float)((float)((float)(v64.x - tw->origin.x)
                                                                                                * tw->axis.x)
                                                                                        + (float)((float)(v64.y - tw->origin.y)
                                                                                                * tw->axis.y)))
                                                                        * tw->axis.x))
                                                        * tw->axis.y))
                                        * (float)v9))
                        + (float)((float)((float)((float)(v64.z - tw->origin.z) * tw->axis.z)
                                        + (float)((float)((float)(v64.x - tw->origin.x) * tw->axis.x)
                                                + (float)((float)(v64.y - tw->origin.y) * tw->axis.y)))
                                * tw->axis.z))
                + tw->origin.z);
  }
  v22 = (float)(vd->x - vc->x);
  v23 = (float)(vd->z - vc->z);
  v56 = (float)v19 - (float)x;
  v24 = v55;
  v57 = (float)v20 - (float)y;
  v58 = (float)v21 - (float)z;
  v25 = (float)(v58 * (float)(vd->y - vc->y));
  v26 = (float)((float)(vd->z - vc->z) * v56);
  v27 = (float)((float)((float)(vd->y - vc->y) * v56) - (float)(v57 * (float)(vd->x - vc->x)));
  a9[2] = (float)((float)(vd->y - vc->y) * v56) - (float)(v57 * (float)(vd->x - vc->x));
  v28 = (float)((float)(v57 * (float)v23) - (float)v25);
  *a9 = v28;
  v29 = (float)((float)(v58 * (float)v22) - (float)v26);
  a9[1] = v29;
  v30 = (float)((float)((float)((float)(vd->y * (float)v27) - (float)(vd->z * (float)v29))
                      * (float)((float)x - (float)v19))
              + (float)((float)((float)v29 * (float)((float)((float)v21 * (float)x) - (float)((float)z * (float)v19)))
                      + (float)((float)((float)-v28
                                      * (float)((float)((float)v21 * (float)y) - (float)((float)v20 * (float)z)))
                              + (float)((float)((float)((float)(vd->x * (float)v27) - (float)(vd->z * (float)v28)) * v57)
                                      + (float)((float)((float)((float)z - (float)v21)
                                                      * (float)((float)(vd->x * (float)v29) - (float)(vd->y * (float)v28)))
                                              + (float)((float)-v27
                                                      * (float)((float)((float)v20 * (float)x)
                                                              - (float)((float)y * (float)v19))))))));
  if ( (float)((float)v30
             * (float)((float)((float)((float)((float)v27 * vc->y) - (float)(vc->z * (float)v29))
                             * (float)((float)x - (float)v19))
                     + (float)((float)((float)v29
                                     * (float)((float)((float)v21 * (float)x) - (float)((float)z * (float)v19)))
                             + (float)((float)((float)-v28
                                             * (float)((float)((float)v21 * (float)y) - (float)((float)v20 * (float)z)))
                                     + (float)((float)((float)((float)((float)v27 * vc->x) - (float)(vc->z * (float)v28))
                                                     * v57)
                                             + (float)((float)((float)((float)z - (float)v21)
                                                             * (float)((float)(vc->x * (float)v29)
                                                                     - (float)((float)v28 * vc->y)))
                                                     + (float)((float)-v27
                                                             * (float)((float)((float)v20 * (float)x)
                                                                     - (float)((float)y * (float)v19))))))))) > (double)v55 )
    return 0;
  v32 = (float)((float)((float)v29 * (float)((float)(vd->z * vc->x) - (float)(vc->z * vd->x)))
              + (float)((float)((float)-v28 * (float)((float)(vd->z * vc->y) - (float)(vc->z * vd->y)))
                      + (float)((float)((float)((float)((float)v27 * (float)v19) - (float)((float)v28 * (float)v21))
                                      * (float)(vd->y - vc->y))
                              + (float)((float)((float)(vc->z - vd->z)
                                              * (float)((float)((float)v29 * (float)v19)
                                                      - (float)((float)v28 * (float)v20)))
                                      + (float)((float)-v27 * (float)((float)(vc->x * vd->y) - (float)(vd->x * vc->y)))))));
  if ( (float)((float)((float)((float)((float)((float)v27 * (float)v20) - (float)((float)v29 * (float)v21))
                             * (float)(vc->x - vd->x))
                     + (float)v32)
             * (float)((float)((float)((float)((float)v27 * (float)y) - (float)((float)v29 * (float)z))
                             * (float)(vc->x - vd->x))
                     + (float)((float)((float)v29 * (float)((float)(vd->z * vc->x) - (float)(vc->z * vd->x)))
                             + (float)((float)((float)-v28 * (float)((float)(vd->z * vc->y) - (float)(vc->z * vd->y)))
                                     + (float)((float)((float)((float)((float)v27 * (float)x)
                                                             - (float)((float)v28 * (float)z))
                                                     * (float)(vd->y - vc->y))
                                             + (float)((float)((float)(vc->z - vd->z)
                                                             * (float)((float)((float)v29 * (float)x)
                                                                     - (float)((float)v28 * (float)y)))
                                                     + (float)((float)-v27
                                                             * (float)((float)(vc->x * vd->y) - (float)(vd->x * vc->y))))))))) > v24 )
    return 0;
  v33 = (float)((float)(vd->y - vc->y) * (float)v27);
  v35 = (float)((float)((float)v27 * (float)(vd->x - vc->x)) - (float)((float)(vd->z - vc->z) * (float)v28));
  v34 = (float)((float)((float)(vd->y - vc->y) * (float)v28) - (float)((float)v29 * (float)(vd->x - vc->x)));
  v36 = (float)((float)v34 * (float)v21);
  v38 = (float)((float)((float)((float)((float)(vd->z - vc->z) * (float)v29) - (float)v33) * (float)x)
              + (float)((float)v34 * (float)z));
  v37 = (float)((float)(vc->z * (float)v34) + (float)(vc->y * (float)v35));
  v39 = (float)((float)((float)((float)v35 * (float)y) + (float)v38)
              - (float)((float)(vc->x * (float)((float)((float)(vd->z - vc->z) * (float)v29) - (float)v33)) + (float)v37));
  v40 = (float)((float)((float)((float)v35 * (float)v20)
                      + (float)((float)((float)((float)((float)(vd->z - vc->z) * (float)v29) - (float)v33) * (float)v19)
                              + (float)v36))
              - (float)((float)(vc->x * (float)((float)((float)(vd->z - vc->z) * (float)v29) - (float)v33)) + (float)v37));
  if ( v39 == v40 )
    return 0;
  v41 = tw->origin.x;
  v42 = tw->origin.y;
  v43 = tw->origin.z;
  v44 = tw->axis.z;
  v45 = tw->axis.y;
  v46 = tw->axis.x;
  angle = tw->angle;
  v48 = (float)((float)v39 / (float)((float)v39 - (float)v40));
  collisionNormal->x = (float)(v56 * (float)v48) + (float)x;
  collisionNormal->y = (float)(v57 * (float)v48) + (float)y;
  collisionNormal->z = (float)(v58 * (float)v48) + (float)z;
  v50 = (float)((float)((float)((float)((float)(v56 * (float)v48) + (float)x) - (float)v41) * (float)v45)
              - (float)((float)((float)((float)(v57 * (float)v48) + (float)y) - (float)v42) * (float)v46));
  v49 = (float)((float)((float)((float)((float)(v58 * (float)v48) + (float)z) - (float)v43) * (float)v46)
              - (float)((float)((float)((float)(v56 * (float)v48) + (float)x) - (float)v41) * (float)v44));
  v51 = (float)((float)((float)((float)((float)(v57 * (float)v48) + (float)y) - (float)v42) * (float)v44)
              - (float)((float)((float)((float)(v58 * (float)v48) + (float)z) - (float)v43) * (float)v45));
  if ( angle < v24 )
  {
    v51 = -v51;
    v49 = -v49;
    v50 = -v50;
  }
  v53 = *a9;
  v54 = (float)((float)(*a9 * (float)v51) + (float)((float)(a9[2] * (float)v50) + (float)(a9[1] * (float)v49)));
  v52 = a9[2];
  if ( v54 > v24 )
  {
    a9[1] = -a9[1];
    *a9 = -v53;
    a9[2] = -v52;
  }
  return 1;
}


// ========================================================================
// ?RotateEdgeThroughEdge@idPolygonModelCollisionDetection@@CAHABVidPluecker@@0MMMAAM@Z
// EA  : 0x825EDFB0
// RVA : 0x005EDFB0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::RotateEdgeThroughEdge(
        const idPluecker *pl1,
        const idPluecker *pl2,
        double angle,
        double minTan,
        double maxTan,
        float *tanHalfAngle,
        int a7,
        int a8,
        float *a9)
{
  double v9; // fp12
  double v10; // fp0
  double v12; // fp13
  double v13; // fp0
  double v14; // fp13
  double v15; // fp8
  double v16; // fp8
  double v17; // fp4
  double v18; // fp13
  double v19; // fp13

  *a9 = maxTan;
  v9 = idMath::FLT_SMALLEST_NON_DENORMAL;
  v10 = (float)-(float)((float)(pl1->p[5] * pl2->p[3])
                      - (float)((float)(pl1->p[3] * pl2->p[5])
                              + (float)((float)(pl2->p[1] * pl1->p[2]) - (float)(pl2->p[2] * pl1->p[1]))));
  if ( __fabs((float)((float)((float)(pl2->p[4] * pl1->p[0]) + (float)(pl1->p[4] * pl2->p[0]))
                    - (float)((float)(pl2->p[5] * pl1->p[1])
                            + (float)((float)(pl2->p[3] * pl1->p[2])
                                    + (float)((float)(pl2->p[1] * pl1->p[5]) + (float)(pl2->p[2] * pl1->p[3])))))) > idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    v14 = (float)((float)((float)v10 * (float)v10)
                - (float)((float)((float)((float)(pl2->p[5] * pl1->p[1])
                                        + (float)((float)(pl2->p[3] * pl1->p[2])
                                                + (float)((float)(pl2->p[1] * pl1->p[5]) + (float)(pl2->p[2] * pl1->p[3]))))
                                + (float)((float)(pl2->p[4] * pl1->p[0]) + (float)(pl1->p[4] * pl2->p[0])))
                        * (float)((float)((float)(pl2->p[4] * pl1->p[0]) + (float)(pl1->p[4] * pl2->p[0]))
                                - (float)((float)(pl2->p[5] * pl1->p[1])
                                        + (float)((float)(pl2->p[3] * pl1->p[2])
                                                + (float)((float)(pl2->p[1] * pl1->p[5]) + (float)(pl2->p[2] * pl1->p[3])))))));
    if ( v14 <= v9 )
      return 0;
    v15 = __frsqrte(v14);
    v16 = (float)((float)-(float)((float)((float)((float)v15
                                                * (float)((float)((float)((float)v10 * (float)v10)
                                                                - (float)((float)((float)((float)(pl2->p[5] * pl1->p[1])
                                                                                        + (float)((float)(pl2->p[3] * pl1->p[2])
                                                                                                + (float)((float)(pl2->p[1] * pl1->p[5]) + (float)(pl2->p[2] * pl1->p[3]))))
                                                                                + (float)((float)(pl2->p[4] * pl1->p[0])
                                                                                        + (float)(pl1->p[4] * pl2->p[0])))
                                                                        * (float)((float)((float)(pl2->p[4] * pl1->p[0])
                                                                                        + (float)(pl1->p[4] * pl2->p[0]))
                                                                                - (float)((float)(pl2->p[5] * pl1->p[1])
                                                                                        + (float)((float)(pl2->p[3] * pl1->p[2])
                                                                                                + (float)((float)(pl2->p[1] * pl1->p[5]) + (float)(pl2->p[2] * pl1->p[3])))))))
                                                        * (float)0.5))
                                        * (float)v15)
                                - (float)1.5)
                * (float)v15);
    v17 = (float)((float)-(float)((float)((float)((float)v16
                                                * (float)((float)((float)((float)v10 * (float)v10)
                                                                - (float)((float)((float)((float)(pl2->p[5] * pl1->p[1])
                                                                                        + (float)((float)(pl2->p[3] * pl1->p[2])
                                                                                                + (float)((float)(pl2->p[1] * pl1->p[5]) + (float)(pl2->p[2] * pl1->p[3]))))
                                                                                + (float)((float)(pl2->p[4] * pl1->p[0])
                                                                                        + (float)(pl1->p[4] * pl2->p[0])))
                                                                        * (float)((float)((float)(pl2->p[4] * pl1->p[0])
                                                                                        + (float)(pl1->p[4] * pl2->p[0]))
                                                                                - (float)((float)(pl2->p[5] * pl1->p[1])
                                                                                        + (float)((float)(pl2->p[3] * pl1->p[2])
                                                                                                + (float)((float)(pl2->p[1] * pl1->p[5]) + (float)(pl2->p[2] * pl1->p[3])))))))
                                                        * (float)0.5))
                                        * (float)v16)
                                - (float)1.5)
                * (float)v16);
    v18 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16
                                                                                                * (float)((float)v14 * (float)0.5))
                                                                                        * (float)v16)
                                                                                - (float)1.5)
                                                                * (float)v16)
                                                        * (float)((float)v14 * (float)0.5))
                                                * (float)v17)
                                        - (float)1.5)
                        * (float)v17)
                * (float)((float)((float)v10 * (float)v10)
                        - (float)((float)((float)((float)(pl2->p[5] * pl1->p[1])
                                                + (float)((float)(pl2->p[3] * pl1->p[2])
                                                        + (float)((float)(pl2->p[1] * pl1->p[5])
                                                                + (float)(pl2->p[2] * pl1->p[3]))))
                                        + (float)((float)(pl2->p[4] * pl1->p[0]) + (float)(pl1->p[4] * pl2->p[0])))
                                * (float)((float)((float)(pl2->p[4] * pl1->p[0]) + (float)(pl1->p[4] * pl2->p[0]))
                                        - (float)((float)(pl2->p[5] * pl1->p[1])
                                                + (float)((float)(pl2->p[3] * pl1->p[2])
                                                        + (float)((float)(pl2->p[1] * pl1->p[5])
                                                                + (float)(pl2->p[2] * pl1->p[3]))))))));
    if ( v10 <= 0.0 )
      v19 = (float)((float)-v10 - (float)v18);
    else
      v19 = (float)((float)v18
                  - (float)-(float)((float)(pl1->p[5] * pl2->p[3])
                                  - (float)((float)(pl1->p[3] * pl2->p[5])
                                          + (float)((float)(pl2->p[1] * pl1->p[2]) - (float)(pl2->p[2] * pl1->p[1])))));
    v13 = (float)((float)v19
                / (float)((float)((float)(pl2->p[4] * pl1->p[0]) + (float)(pl1->p[4] * pl2->p[0]))
                        - (float)((float)(pl2->p[5] * pl1->p[1])
                                + (float)((float)(pl2->p[3] * pl1->p[2])
                                        + (float)((float)(pl2->p[1] * pl1->p[5]) + (float)(pl2->p[2] * pl1->p[3]))))));
    v12 = (float)((float)((float)((float)(pl2->p[5] * pl1->p[1])
                                + (float)((float)(pl2->p[3] * pl1->p[2])
                                        + (float)((float)(pl2->p[1] * pl1->p[5]) + (float)(pl2->p[2] * pl1->p[3]))))
                        + (float)((float)(pl2->p[4] * pl1->p[0]) + (float)(pl1->p[4] * pl2->p[0])))
                / (float)v19);
  }
  else
  {
    if ( __fabs(v10) <= v9 )
      return 0;
    v12 = 1.0e10;
    v13 = -(float)((float)((float)((float)(pl2->p[5] * pl1->p[1])
                                 + (float)((float)(pl2->p[3] * pl1->p[2])
                                         + (float)((float)(pl2->p[1] * pl1->p[5]) + (float)(pl2->p[2] * pl1->p[3]))))
                         + (float)((float)(pl2->p[4] * pl1->p[0]) + (float)(pl1->p[4] * pl2->p[0])))
                 / (float)((float)-(float)((float)(pl1->p[5] * pl2->p[3])
                                         - (float)((float)(pl1->p[3] * pl2->p[5])
                                                 + (float)((float)(pl2->p[1] * pl1->p[2])
                                                         - (float)(pl2->p[2] * pl1->p[1]))))
                         * (float)2.0));
  }
  if ( angle < 0.0 )
  {
    v13 = -v13;
    v12 = -v12;
  }
  if ( v13 >= minTan && v13 < maxTan )
    *a9 = v13;
  if ( v12 >= minTan && v12 < *a9 )
    *a9 = v12;
  if ( angle < 0.0 )
    *a9 = -*a9;
  return 1;
}


// ========================================================================
// ?EdgeFurthestFromEdge@idPolygonModelCollisionDetection@@CAHABVidPluecker@@0MAAM1@Z
// EA  : 0x825EE158
// RVA : 0x005EE158
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::EdgeFurthestFromEdge(
        const idPluecker *pl1,
        const idPluecker *pl2,
        double angle,
        float *tanHalfAngle,
        float *dir,
        float *a6)
{
  double v6; // fp13
  double v7; // fp11
  double v8; // fp0
  double v9; // fp10
  double v10; // fp0
  double v11; // fp12
  double v13; // fp0
  double v14; // fp12
  double v15; // fp13
  double v16; // fp13
  double v17; // fp8
  double v18; // fp3
  double v19; // fp8
  double v20; // fp0

  *dir = 0.0;
  v6 = (float)((float)(pl2->p[3] * pl1->p[2])
             + (float)((float)(pl1->p[5] * pl2->p[1])
                     + (float)((float)(pl1->p[3] * pl2->p[2]) + (float)(pl2->p[5] * pl1->p[1]))));
  v7 = (float)-(float)((float)(pl2->p[3] * pl1->p[5])
                     - (float)((float)(pl2->p[5] * pl1->p[3])
                             + (float)((float)(pl2->p[1] * pl1->p[2]) - (float)(pl2->p[2] * pl1->p[1]))));
  v8 = (float)((float)((float)(pl2->p[4] * pl1->p[0]) + (float)(pl1->p[4] * pl2->p[0]))
             + (float)((float)(pl2->p[3] * pl1->p[2])
                     + (float)((float)(pl1->p[5] * pl2->p[1])
                             + (float)((float)(pl1->p[3] * pl2->p[2]) + (float)(pl2->p[5] * pl1->p[1])))));
  if ( angle <= 0.0 )
  {
    if ( v8 > 0.0 )
    {
      *a6 = -v7;
      goto LABEL_7;
    }
  }
  else if ( v8 <= 0.0 )
  {
    *a6 = -v7;
    goto LABEL_7;
  }
  *a6 = -(float)((float)(pl2->p[3] * pl1->p[5])
               - (float)((float)(pl2->p[5] * pl1->p[3])
                       + (float)((float)(pl2->p[1] * pl1->p[2]) - (float)(pl2->p[2] * pl1->p[1]))));
LABEL_7:
  if ( *a6 >= 0.0 )
  {
    v9 = -v7;
    v10 = -v6;
    v11 = idMath::FLT_SMALLEST_NON_DENORMAL;
    if ( __fabs(-v7) > idMath::FLT_SMALLEST_NON_DENORMAL )
    {
      v16 = (float)((float)((float)v10 * (float)v10) - (float)((float)v9 * (float)v7));
      if ( v16 <= v11 )
        return 0;
      v17 = __frsqrte(v16);
      v18 = (float)((float)-(float)((float)((float)((float)v17
                                                  * (float)((float)((float)((float)v10 * (float)v10)
                                                                  - (float)((float)v9 * (float)v7))
                                                          * (float)0.5))
                                          * (float)v17)
                                  - (float)1.5)
                  * (float)v17);
      v19 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                  * (float)((float)v16 * (float)0.5))
                                                                          * (float)v17)
                                                                  - (float)1.5)
                                                  * (float)v17)
                                          * (float)((float)v16 * (float)0.5))
                                  * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v16 * (float)0.5))
                                                                  * (float)v17)
                                                          - (float)1.5)
                                          * (float)v17))
                          - (float)1.5);
      if ( v10 <= 0.0 )
        v20 = (float)((float)-v10
                    - (float)((float)((float)-(float)((float)((float)((float)((float)v19 * (float)v18)
                                                                    * (float)((float)((float)((float)v10 * (float)v10)
                                                                                    - (float)((float)v9 * (float)v7))
                                                                            * (float)0.5))
                                                            * (float)((float)v19 * (float)v18))
                                                    - (float)1.5)
                                    * (float)((float)v19 * (float)v18))
                            * (float)((float)((float)v10 * (float)v10) - (float)((float)v9 * (float)v7))));
      else
        v20 = (float)((float)((float)((float)-(float)((float)((float)((float)((float)v19 * (float)v18)
                                                                    * (float)((float)((float)((float)v10 * (float)v10)
                                                                                    - (float)((float)v9 * (float)v7))
                                                                            * (float)0.5))
                                                            * (float)((float)v19 * (float)v18))
                                                    - (float)1.5)
                                    * (float)((float)v19 * (float)v18))
                            * (float)((float)((float)v10 * (float)v10) - (float)((float)v9 * (float)v7)))
                    - (float)v10);
      v15 = (float)((float)v20 / (float)v9);
      v13 = (float)((float)v7 / (float)v20);
    }
    else
    {
      if ( __fabs(v10) <= v11 )
        return 0;
      v14 = (float)((float)v7 / (float)((float)v10 * (float)2.0));
      v13 = 1.0e10;
      v15 = -v14;
    }
    if ( angle < 0.0 )
    {
      v15 = -v15;
      v13 = -v13;
    }
    if ( v15 < 0.0 && v13 < 0.0 )
      return 0;
    if ( v15 <= v13 )
      *dir = v13;
    else
      *dir = v15;
    if ( angle < 0.0 )
      *dir = -*dir;
  }
  return 1;
}


// ========================================================================
// ?RotateTrmEdgesThroughPolygon@idPolygonModelCollisionDetection@@CA_NPIAVidTraceWork@@PIBUcm_polygon_t@@@Z
// EA  : 0x825EE320
// RVA : 0x005EE320
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::RotateTrmEdgesThroughPolygon(
        idTraceWork *tw,
        const cm_polygon_t *poly)
{
  unsigned int v5; // r21
  float *v8; // r22
  float *p_z; // r18
  unsigned __int8 v11; // cr58
  unsigned __int8 v12; // cr59
  unsigned int v13; // r20
  float *v14; // r24
  unsigned int v15; // r7
  int v16; // r6
  unsigned __int16 v17; // r28
  cm_vertex_t *vertices; // r10
  cm_edge_t *v19; // r11
  const idVec3 *v20; // r29
  const idVec3 *v21; // r27
  int v22; // r7
  int v23; // r6
  float *v24; // r5
  double v25; // fp13
  double v26; // fp10
  double v27; // fp4
  double v28; // fp0
  double v29; // fp6
  double v30; // fp1
  double v31; // fp11
  double v32; // fp3
  double v33; // fp8
  double v34; // fp5
  double v35; // fp31
  double v36; // fp26
  const idPluecker *v37; // r3
  double v38; // fp25
  double v39; // fp27
  double v40; // fp23
  double v41; // fp24
  double v42; // fp2
  double v43; // fp22
  double v44; // fp9
  double v45; // fp7
  double v46; // fp21
  double v47; // fp1
  double v48; // fp31
  idVec3 *v49; // r8
  const idVec3 *v50; // r30
  trace_t *traceResult; // r11
  double v52; // fp0
  double v53; // fp13
  double v54; // fp11
  trace_t *v55; // r11
  double y; // fp0
  char *v57; // r10
  double z; // fp13
  double x; // fp12
  double v60; // fp10
  int v61; // r4
  double v62; // fp9
  double v63; // fp8
  double v64; // fp11
  double v65; // fp6
  const idPluecker *v68; // r9
  int v69; // r7
  int v70; // r6
  float *v71; // r5
  double maxTan; // fp3
  float v73; // [sp+50h] [-130h] BYREF
  float v74; // [sp+54h] [-12Ch] BYREF
  float v75[2]; // [sp+58h] [-128h] BYREF
  float v76[4]; // [sp+60h] [-120h] BYREF
  idVec3 v77; // [sp+70h] [-110h] BYREF
  idPluecker v78[5]; // [sp+80h] [-100h] BYREF

  _R25 = poly;
  v5 = 0;
  if ( tw->numEdges == 0 )
    return 0;
  _R17 = vmxi_half_bnds_intersect_perm2_4;
  _R7 = -16;
  v8 = &tw->edgeZAxisPluecker[0].p[2];
  __asm { lvx128    v7, r0, r17 }
  p_z = &tw->edgeNormal[0].z;
  __asm { lvx128    v0, r17, r7 }
  while ( 1 )
  {
    _R26 = p_z - 1218;
    __asm
    {
      lvx128    v63, r0, r25
      lvx128    v62, r0, r26
      vperm128  v13, v94, v63, v7
      vperm128  v12, v94, v63, v0
      vcmpgtsh. v11, v12, v13
    }
    if ( ((32 * v11) & 0x20 | (16 * v12) & 0x20) != 0 )
    {
      v13 = 0;
      if ( _R25->numEdges != 0 )
        break;
    }
LABEL_17:
    ++v5;
    p_z += 4;
    v8 += 6;
    if ( v5 >= tw->numEdges )
      return 0;
  }
  v14 = &tw->polygonVertexPlueckerCache[0].p[2];
  while ( 1 )
  {
    v15 = _R25->firstEdge + v13;
    v16 = tw->subModelPtrs.polygonEdges[v15];
    v17 = tw->subModelPtrs.polygonEdges[v15];
    if ( ((1 << (v16 & 7)) & tw->modelCheckCounts.edgeCheckCounts[(v16 & 0x3FFF) >> 3]) != 0 )
      goto LABEL_15;
    if ( (v16 & 0x4000) != 0 )
      goto LABEL_15;
    vertices = tw->subModelPtrs.vertices;
    v19 = &tw->subModelPtrs.edges[v16 & 0x3FFF];
    v20 = (idVec3 *)((char *)&vertices->p
                   + __ROL4__(
                       *(unsigned __int16 *)((char *)v19->vertexNum + ((tw->subModelPtrs.polygonEdges[v15] >> 14) & 2)),
                       4));
    v21 = (idVec3 *)((char *)&vertices->p
                   + __ROL4__(*(unsigned __int16 *)((char *)v19->vertexNum + (((unsigned int)~v16 >> 14) & 2)), 4));
    if ( !idPolygonModelCollisionDetection::EdgeIntersectsBoundsShort(
            bounds: (const idBoundsShort *)p_z - 406,
            start: v20,
            end: v21) )
      goto LABEL_15;
    v25 = (float)(*(p_z - 1) * (float)0.25009999);
    v26 = (float)(*(p_z - 1) * (float)0.25);
    v27 = *(v8 - 1);
    v28 = v14[3];
    v29 = (float)(*p_z * (float)0.25009999);
    v30 = (float)(*p_z * (float)0.25);
    v31 = v8[1];
    v32 = (float)(*(p_z - 2) * (float)0.25);
    v33 = (float)(v14[3] * *(v8 - 1));
    v34 = v8[3];
    v35 = *(v8 - 2);
    v36 = v14[2];
    v37 = (const idPluecker *)(v14 - 2);
    v38 = *(v14 - 2);
    v39 = (float)-(float)((float)(v8[2] * (float)(*(p_z - 1) * (float)0.25009999)) - v8[1]);
    v40 = *(v14 - 1);
    v41 = (float)-(float)((float)(v8[2] * (float)(*(p_z - 1) * (float)0.25)) - v8[1]);
    v42 = *v8;
    v43 = (float)(v8[3] * (float)(*(p_z - 2) * (float)0.25009999));
    v44 = *v14;
    v45 = (float)-(float)((float)(v8[2] * (float)(*(p_z - 2) * (float)0.25009999)) - *(v8 - 1));
    v78[0].p[4] = v8[2];
    v78[0].p[5] = v34;
    v46 = (float)(v14[1] * (float)v42);
    v78[0].p[2] = v42;
    v78[0].p[3] = -(float)((float)((float)v34 * (float)v30) - (float)v41);
    v78[0].p[1] = (float)((float)v42 * (float)v30) - (float)((float)(v78[0].p[4] * (float)v32) - (float)v27);
    v78[0].p[0] = (float)((float)((float)v42 * (float)v26) + (float)((float)v34 * (float)v32)) + (float)v35;
    v47 = -tw->angle;
    if ( (float)((float)((float)((float)((float)((float)((float)v44 * (float)v31)
                                               + (float)((float)((float)v36 * (float)v35) + (float)v33))
                                       + (float)(v78[0].p[4] * (float)v38))
                               + (float)((float)v40 * (float)v34))
                       + (float)v46)
               * (float)((float)((float)((float)((float)((float)v36
                                                       * (float)((float)((float)((float)v42 * (float)v25) + (float)v43)
                                                               + (float)v35))
                                               + (float)((float)((float)v28
                                                               * (float)((float)((float)v42 * (float)v29) + (float)v45))
                                                       + (float)((float)v44
                                                               * (float)-(float)((float)((float)v34 * (float)v29)
                                                                               - (float)v39))))
                                       + (float)(v78[0].p[4] * (float)v38))
                               + (float)((float)v40 * (float)v34))
                       + (float)v46)) > 0.0 )
    {
      if ( idPolygonModelCollisionDetection::RotateEdgeThroughEdge(
             pl1: v37,
             pl2: v78,
             angle: v47,
             minTan: 0.0,
             maxTan: tw->maxTan,
             tanHalfAngle: v24,
             a7: v23,
             a8: v22,
             a9: &v73) != 0 )
        goto LABEL_11;
      goto LABEL_15;
    }
    if ( idPolygonModelCollisionDetection::EdgeFurthestFromEdge(
           pl1: v37,
           pl2: (const idPluecker *)(v8 - 2),
           angle: v47,
           tanHalfAngle: v24,
           dir: v75,
           a6: &v74) != 0 )
    {
      if ( v74 <= 0.0 )
      {
        v73 = 0.0;
        v48 = 0.0;
        goto LABEL_12;
      }
      v48 = v75[0];
      maxTan = tw->maxTan;
      if ( __fabs(v75[0]) < maxTan )
        break;
    }
LABEL_15:
    ++v13;
    v14 += 6;
    if ( v13 >= _R25->numEdges )
    {
      _R11 = -16;
      __asm
      {
        lvx128    v7, r0, r17
        lvx128    v0, r17, r11
      }
      goto LABEL_17;
    }
  }
  if ( idPolygonModelCollisionDetection::RotateEdgeThroughEdge(
         pl1: v68,
         pl2: v78,
         angle: -tw->angle,
         minTan: __fabs(v48),
         maxTan,
         tanHalfAngle: v71,
         a7: v70,
         a8: v69,
         a9: &v73) != 0 )
  {
LABEL_11:
    v48 = v73;
    goto LABEL_12;
  }
  v73 = v48;
LABEL_12:
  if ( __fabs(v48) >= tw->maxTan )
    goto LABEL_15;
  v49 = (idVec3 *)(16 * (*((unsigned __int16 *)_R26 + 7) + 128));
  v50 = (const idVec3 *)&tw->vertexPosition[*((unsigned __int16 *)_R26 + 6)];
  if ( idPolygonModelCollisionDetection::CollisionBetweenEdgeBounds(
         tw,
         va: v50,
         vb: (const idVec3 *)((char *)tw + (_DWORD)v49),
         vc: v20,
         vd: v21,
         tanHalfAngle: v48,
         collisionPoint: v49,
         collisionNormal: &v77,
         a9: v76) == 0 )
    goto LABEL_15;
  traceResult = tw->traceResult;
  v52 = v76[0];
  v53 = v76[1];
  v54 = v76[2];
  tw->maxTan = __fabs(v48);
  traceResult->c.normal.x = v52;
  traceResult->c.normal.y = v53;
  traceResult->c.normal.z = v54;
  idVec3::NormalizeFast(this: &traceResult->c.normal);
  v55 = tw->traceResult;
  y = v50->y;
  v57 = (char *)tw->subModelPtrs.materials + __ROL4__(_R25->material, 4);
  z = v50->z;
  x = v50->x;
  v60 = v77.x;
  v61 = (tw->subModelNum << 16) & 0x1FFF0000 | 0x40000000 | v17 & 0x3FFF;
  v62 = v77.y;
  v63 = v77.z;
  v64 = tw->maxTan;
  v65 = (float)((float)(v55->c.normal.x * v20->x)
              + (float)((float)(v55->c.normal.z * v20->z) + (float)(v55->c.normal.y * v20->y)));
  v55->c.dist = (float)(v55->c.normal.x * v20->x)
              + (float)((float)(v55->c.normal.z * v20->z) + (float)(v55->c.normal.y * v20->y));
  v55->c.separation = (float)((float)(v55->c.normal.x * (float)x)
                            + (float)((float)(v55->c.normal.z * (float)z) + (float)(v55->c.normal.y * (float)y)))
                    - (float)v65;
  v55->c.contentFlags = *(_DWORD *)v57;
  v55->c.surfaceFlags = *((_DWORD *)v57 + 1);
  v55->c.surfaceType = *((_DWORD *)v57 + 2);
  v55->c.surfaceColor[0] = v57[12];
  v55->c.surfaceColor[1] = v57[13];
  v55->c.surfaceColor[2] = v57[14];
  v55->c.type = CONTACT_EDGE;
  v55->c.modelFeature = v61;
  v55->c.trmFeature = v5;
  v55->c.point.x = v60;
  v55->c.point.y = v62;
  v55->c.point.z = v63;
  v55->c.flags = 0;
  if ( v64 != 0.0 )
    goto LABEL_15;
  return 1;
}


// ========================================================================
// ?RotatePointThroughPlane@idPolygonModelCollisionDetection@@CAHABVidVec3@@ABVidPlane@@MMMAAM@Z
// EA  : 0x825EE7B0
// RVA : 0x005EE7B0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::RotatePointThroughPlane(
        const idVec3 *point,
        const idPlane *plane,
        double angle,
        double minTan,
        double maxTan,
        float *tanHalfAngle,
        int a7,
        int a8,
        float *a9)
{
  double v9; // fp12
  double v10; // fp0
  double v12; // fp13
  double v13; // fp0
  double v14; // fp13
  double v15; // fp8
  double v16; // fp8
  double v17; // fp4
  double v18; // fp13
  double v19; // fp13

  *a9 = maxTan;
  v9 = idMath::FLT_SMALLEST_NON_DENORMAL;
  v10 = (float)((float)(plane->a * point->y) - (float)(point->x * plane->b));
  if ( __fabs((float)((float)((float)(point->z * plane->c) + plane->d)
                    - (float)((float)(plane->a * point->x) + (float)(plane->b * point->y)))) > idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    v14 = (float)((float)((float)v10 * (float)v10)
                - (float)((float)((float)((float)(plane->a * point->x) + (float)(plane->b * point->y))
                                + (float)((float)(point->z * plane->c) + plane->d))
                        * (float)((float)((float)(point->z * plane->c) + plane->d)
                                - (float)((float)(plane->a * point->x) + (float)(plane->b * point->y)))));
    if ( v14 <= v9 )
      return 0;
    v15 = __frsqrte(v14);
    v16 = (float)((float)-(float)((float)((float)((float)v15
                                                * (float)((float)((float)((float)v10 * (float)v10)
                                                                - (float)((float)((float)((float)(plane->a * point->x)
                                                                                        + (float)(plane->b * point->y))
                                                                                + (float)((float)(point->z * plane->c)
                                                                                        + plane->d))
                                                                        * (float)((float)((float)(point->z * plane->c)
                                                                                        + plane->d)
                                                                                - (float)((float)(plane->a * point->x)
                                                                                        + (float)(plane->b * point->y)))))
                                                        * (float)0.5))
                                        * (float)v15)
                                - (float)1.5)
                * (float)v15);
    v17 = (float)((float)-(float)((float)((float)((float)v16
                                                * (float)((float)((float)((float)v10 * (float)v10)
                                                                - (float)((float)((float)((float)(plane->a * point->x)
                                                                                        + (float)(plane->b * point->y))
                                                                                + (float)((float)(point->z * plane->c)
                                                                                        + plane->d))
                                                                        * (float)((float)((float)(point->z * plane->c)
                                                                                        + plane->d)
                                                                                - (float)((float)(plane->a * point->x)
                                                                                        + (float)(plane->b * point->y)))))
                                                        * (float)0.5))
                                        * (float)v16)
                                - (float)1.5)
                * (float)v16);
    v18 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16
                                                                                                * (float)((float)v14 * (float)0.5))
                                                                                        * (float)v16)
                                                                                - (float)1.5)
                                                                * (float)v16)
                                                        * (float)((float)v14 * (float)0.5))
                                                * (float)v17)
                                        - (float)1.5)
                        * (float)v17)
                * (float)((float)((float)v10 * (float)v10)
                        - (float)((float)((float)((float)(plane->a * point->x) + (float)(plane->b * point->y))
                                        + (float)((float)(point->z * plane->c) + plane->d))
                                * (float)((float)((float)(point->z * plane->c) + plane->d)
                                        - (float)((float)(plane->a * point->x) + (float)(plane->b * point->y))))));
    if ( v10 <= 0.0 )
      v19 = (float)((float)-v10 - (float)v18);
    else
      v19 = (float)((float)v18 - (float)((float)(plane->a * point->y) - (float)(point->x * plane->b)));
    v13 = (float)((float)v19
                / (float)((float)((float)(point->z * plane->c) + plane->d)
                        - (float)((float)(plane->a * point->x) + (float)(plane->b * point->y))));
    v12 = (float)((float)((float)((float)(plane->a * point->x) + (float)(plane->b * point->y))
                        + (float)((float)(point->z * plane->c) + plane->d))
                / (float)v19);
  }
  else
  {
    if ( __fabs(v10) <= v9 )
      return 0;
    v12 = 1.0e10;
    v13 = -(float)((float)((float)((float)(plane->a * point->x) + (float)(plane->b * point->y))
                         + (float)((float)(point->z * plane->c) + plane->d))
                 / (float)((float)((float)(plane->a * point->y) - (float)(point->x * plane->b)) * (float)2.0));
  }
  if ( angle < 0.0 )
  {
    v13 = -v13;
    v12 = -v12;
  }
  if ( v13 >= minTan && v13 < maxTan )
    *a9 = v13;
  if ( v12 >= minTan && v12 < *a9 )
    *a9 = v12;
  if ( angle < 0.0 )
    *a9 = -*a9;
  return 1;
}


// ========================================================================
// ?PointFurthestFromPlane@idPolygonModelCollisionDetection@@CAHABVidVec3@@ABVidPlane@@MAAM2@Z
// EA  : 0x825EE908
// RVA : 0x005EE908
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::PointFurthestFromPlane(
        const idVec3 *point,
        const idPlane *plane,
        double angle,
        float *tanHalfAngle,
        float *dir,
        float *a6)
{
  double v6; // fp13
  double v7; // fp11
  double v8; // fp0
  double v9; // fp10
  double v10; // fp0
  double v11; // fp12
  double v13; // fp0
  double v14; // fp12
  double v15; // fp13
  double v16; // fp13
  double v17; // fp8
  double v18; // fp3
  double v19; // fp8
  double v20; // fp0

  *dir = 0.0;
  v6 = (float)((float)(point->x * plane->a) + (float)(plane->b * point->y));
  v7 = (float)((float)(plane->a * point->y) - (float)(point->x * plane->b));
  v8 = (float)((float)((float)(point->z * plane->c) + plane->d)
             + (float)((float)(point->x * plane->a) + (float)(plane->b * point->y)));
  if ( angle <= 0.0 )
  {
    if ( v8 > 0.0 )
    {
      *a6 = -v7;
      goto LABEL_7;
    }
  }
  else if ( v8 <= 0.0 )
  {
    *a6 = -v7;
    goto LABEL_7;
  }
  *a6 = (float)(plane->a * point->y) - (float)(point->x * plane->b);
LABEL_7:
  if ( *a6 >= 0.0 )
  {
    v9 = -v7;
    v10 = -v6;
    v11 = idMath::FLT_SMALLEST_NON_DENORMAL;
    if ( __fabs(-v7) > idMath::FLT_SMALLEST_NON_DENORMAL )
    {
      v16 = (float)((float)((float)v10 * (float)v10) - (float)((float)v9 * (float)v7));
      if ( v16 <= v11 )
        return 0;
      v17 = __frsqrte(v16);
      v18 = (float)((float)-(float)((float)((float)((float)v17
                                                  * (float)((float)((float)((float)v10 * (float)v10)
                                                                  - (float)((float)v9 * (float)v7))
                                                          * (float)0.5))
                                          * (float)v17)
                                  - (float)1.5)
                  * (float)v17);
      v19 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                  * (float)((float)v16 * (float)0.5))
                                                                          * (float)v17)
                                                                  - (float)1.5)
                                                  * (float)v17)
                                          * (float)((float)v16 * (float)0.5))
                                  * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v16 * (float)0.5))
                                                                  * (float)v17)
                                                          - (float)1.5)
                                          * (float)v17))
                          - (float)1.5);
      if ( v10 <= 0.0 )
        v20 = (float)((float)-v10
                    - (float)((float)((float)-(float)((float)((float)((float)((float)v19 * (float)v18)
                                                                    * (float)((float)((float)((float)v10 * (float)v10)
                                                                                    - (float)((float)v9 * (float)v7))
                                                                            * (float)0.5))
                                                            * (float)((float)v19 * (float)v18))
                                                    - (float)1.5)
                                    * (float)((float)v19 * (float)v18))
                            * (float)((float)((float)v10 * (float)v10) - (float)((float)v9 * (float)v7))));
      else
        v20 = (float)((float)((float)((float)-(float)((float)((float)((float)((float)v19 * (float)v18)
                                                                    * (float)((float)((float)((float)v10 * (float)v10)
                                                                                    - (float)((float)v9 * (float)v7))
                                                                            * (float)0.5))
                                                            * (float)((float)v19 * (float)v18))
                                                    - (float)1.5)
                                    * (float)((float)v19 * (float)v18))
                            * (float)((float)((float)v10 * (float)v10) - (float)((float)v9 * (float)v7)))
                    - (float)v10);
      v15 = (float)((float)v20 / (float)v9);
      v13 = (float)((float)v7 / (float)v20);
    }
    else
    {
      if ( __fabs(v10) <= v11 )
        return 0;
      v14 = (float)((float)v7 / (float)((float)v10 * (float)2.0));
      v13 = 1.0e10;
      v15 = -v14;
    }
    if ( angle < 0.0 )
    {
      v15 = -v15;
      v13 = -v13;
    }
    if ( v15 < 0.0 && v13 < 0.0 )
      return 0;
    if ( v15 <= v13 )
      *dir = v13;
    else
      *dir = v15;
    if ( angle < 0.0 )
      *dir = -*dir;
  }
  return 1;
}


// ========================================================================
// ?RotatePointThroughEpsilonPlane@idPolygonModelCollisionDetection@@CAHPIBVidTraceWork@@ABVidVec3@@1ABVidPlane@@M1AAMAAV3@4@Z
// EA  : 0x825EEAA0
// RVA : 0x005EEAA0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::RotatePointThroughEpsilonPlane(
        const idTraceWork *tw,
        const idVec3 *point,
        const idVec3 *endPoint,
        const idPlane *plane,
        double angle,
        const idVec3 *rotationOrigin,
        float *tanHalfAngle,
        idVec3 *collisionPoint,
        idVec3 *endDir,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        float *a29)
{
  double b; // fp29
  double c; // fp28
  double v34; // fp7
  double v35; // fp4
  double a; // fp30
  double v40; // fp27
  double v41; // fp9
  double z; // fp13
  double y; // fp12
  idVec4 *p_axis; // r26
  double v45; // fp10
  double v46; // fp9
  double v47; // fp11
  double v48; // fp9
  double v49; // fp8
  double v50; // fp5
  double v51; // fp4
  double v52; // fp0
  double v53; // fp12
  double v54; // fp13
  int v55; // r7
  int v56; // r6
  float *v57; // r5
  double v58; // fp12
  double d; // fp7
  double v60; // fp4
  double v61; // fp11
  double v62; // fp9
  double v63; // fp10
  double v64; // fp30
  double v65; // fp29
  double v66; // fp28
  double v67; // fp27
  float *v68; // r9
  int v70; // r7
  int v71; // r6
  float *v72; // r5
  double v73; // fp25
  double maxTan; // fp3
  double v75; // fp13
  double v76; // fp12
  double v77; // fp11
  double v78; // fp8
  double v79; // fp6
  double v80; // fp9
  double v81; // fp1
  double v82; // fp13
  double v83; // fp12
  double v84; // fp1
  double v85; // fp8
  double v86; // fp9
  double v87; // fp27
  double v88; // fp0
  double v89; // fp5
  double v90; // fp10
  double v91; // fp9
  float v92; // [sp+50h] [-B0h] BYREF
  float v93; // [sp+54h] [-ACh] BYREF
  idVec3 v94[2]; // [sp+58h] [-A8h] BYREF
  idPlane v95[5]; // [sp+70h] [-90h] BYREF

  b = plane->b;
  c = plane->c;
  v34 = (float)(point->z - tanHalfAngle[2]);
  v35 = (float)(point->y - tanHalfAngle[1]);
  a = plane->a;
  v40 = (float)(plane->d - (float)0.25);
  v41 = (float)((float)((float)(*tanHalfAngle * plane->a)
                      + (float)((float)(tanHalfAngle[2] * plane->c) + (float)(tanHalfAngle[1] * plane->b)))
              + (float)(plane->d - (float)0.25));
  if ( (float)((float)v41 * (float)v41) > (double)(float)((float)((float)v35 * (float)v35)
                                                        + (float)((float)((float)(point->x - *tanHalfAngle)
                                                                        * (float)(point->x - *tanHalfAngle))
                                                                + (float)((float)v34 * (float)v34))) )
    return 0;
  p_axis = &tw->axis;
  v45 = (float)((float)((float)(point->z - tanHalfAngle[2]) * tw->axis.x)
              - (float)(tw->axis.z * (float)(point->x - *tanHalfAngle)));
  v46 = (float)((float)(tw->axis.y * (float)(point->x - *tanHalfAngle))
              - (float)((float)(point->y - tanHalfAngle[1]) * tw->axis.x));
  v47 = (float)((float)((float)(point->y - tanHalfAngle[1]) * tw->axis.z)
              - (float)((float)(point->z - tanHalfAngle[2]) * tw->axis.y));
  y = tw->axis.y;
  z = tw->axis.z;
  if ( angle < 0.0 )
  {
    v47 = -v47;
    v45 = -v45;
    v46 = -v46;
  }
  if ( (float)((float)((float)v47 * plane->a) + (float)((float)((float)v46 * plane->c) + (float)((float)v45 * plane->b))) >= 0.0 )
  {
    if ( (float)((float)((float)(endPoint->x * plane->a)
                       + (float)((float)(endPoint->z * plane->c) + (float)(endPoint->y * plane->b)))
               + (float)(plane->d - (float)0.25)) >= 0.0 )
      return 0;
    v48 = (float)(endPoint->x - *tanHalfAngle);
    v49 = (float)(endPoint->y - tanHalfAngle[1]);
    v50 = (float)((float)(endPoint->y - tanHalfAngle[1]) * tw->axis.x);
    v51 = (float)((float)(endPoint->z - tanHalfAngle[2]) * tw->axis.y);
    v52 = (float)((float)((float)(endPoint->z - tanHalfAngle[2]) * tw->axis.x)
                - (float)((float)(endPoint->x - *tanHalfAngle) * tw->axis.z));
    a29[1] = (float)((float)(endPoint->z - tanHalfAngle[2]) * tw->axis.x)
           - (float)((float)(endPoint->x - *tanHalfAngle) * tw->axis.z);
    v53 = (float)((float)((float)v48 * (float)y) - (float)v50);
    a29[2] = v53;
    v54 = (float)((float)((float)v49 * (float)z) - (float)v51);
    *a29 = v54;
    if ( angle < 0.0 )
    {
      *a29 = -v54;
      a29[1] = -v52;
      a29[2] = -v53;
    }
    if ( (float)((float)(a29[2] * (float)c) + (float)((float)((float)a * *a29) + (float)((float)b * a29[1]))) > 0.0 )
      return 0;
  }
  idMat3x4::Transform(this: &tw->ZAxisTransform, result: v94, v: point);
  v58 = plane->a;
  d = plane->d;
  v60 = tw->ZAxisTransform.mat[8];
  v61 = (float)((float)(tw->ZAxisTransform.mat[9] * plane->b) + (float)(tw->ZAxisTransform.mat[10] * plane->c));
  v62 = (float)((float)(plane->b * tw->origin.y)
              + (float)((float)(plane->c * tw->origin.z) + (float)(plane->a * tw->origin.x)));
  v63 = (float)((float)((float)(point->y * (float)b)
                      + (float)((float)((float)a * point->x) + (float)(point->z * (float)c)))
              + (float)v40);
  v64 = (float)((float)(plane->a * tw->ZAxisTransform.mat[0])
              + (float)((float)(tw->ZAxisTransform.mat[1] * plane->b) + (float)(tw->ZAxisTransform.mat[2] * plane->c)));
  v65 = (float)((float)(tw->ZAxisTransform.mat[4] * plane->a)
              + (float)((float)(tw->ZAxisTransform.mat[5] * plane->b) + (float)(tw->ZAxisTransform.mat[6] * plane->c)));
  v95[0].a = (float)(plane->a * tw->ZAxisTransform.mat[0])
           + (float)((float)(tw->ZAxisTransform.mat[1] * plane->b) + (float)(tw->ZAxisTransform.mat[2] * plane->c));
  v95[0].b = v65;
  v66 = (float)((float)((float)v60 * (float)v58) + (float)v61);
  v95[0].c = (float)((float)v60 * (float)v58) + (float)v61;
  v67 = (float)((float)v62 + (float)d);
  v95[0].d = (float)v62 + (float)d;
  if ( v63 <= 0.000099999997 )
  {
    if ( idPolygonModelCollisionDetection::PointFurthestFromPlane(
           point: v94,
           plane: v95,
           angle,
           tanHalfAngle: v57,
           dir: &v93,
           a6: &v92) == 0 )
      return 0;
    if ( v92 > 0.0 )
    {
      v73 = v93;
      maxTan = tw->maxTan;
      if ( __fabs(v93) >= maxTan )
        return 0;
      v95[0].a = v64;
      v95[0].b = v65;
      v95[0].c = v66;
      v95[0].d = (float)v67 - (float)0.25;
      if ( idPolygonModelCollisionDetection::RotatePointThroughPlane(
             point: v94,
             plane: v95,
             angle,
             minTan: __fabs(v73),
             maxTan,
             tanHalfAngle: v72,
             a7: v71,
             a8: v70,
             a9: &collisionPoint->x) == 0 )
        collisionPoint->x = v73;
    }
    else
    {
      collisionPoint->x = 0.0;
    }
  }
  else
  {
    v95[0].a = v64;
    v95[0].b = v65;
    v95[0].c = (float)((float)v60 * (float)v58) + (float)v61;
    v95[0].d = (float)((float)v62 + (float)d) - (float)0.25;
    if ( idPolygonModelCollisionDetection::RotatePointThroughPlane(
           point: v94,
           plane: v95,
           angle,
           minTan: 0.0,
           maxTan: tw->maxTan,
           tanHalfAngle: v57,
           a7: v56,
           a8: v55,
           a9: &collisionPoint->x) == 0 )
      return 0;
  }
  if ( __fabs(collisionPoint->x) >= tw->maxTan )
    return 0;
  endDir->x = point->x;
  v75 = point->y;
  endDir->y = point->y;
  v76 = point->z;
  endDir->z = point->z;
  if ( collisionPoint->x != 0.0 )
  {
    v77 = v68[1];
    v78 = (float)((float)v75 - v68[1]);
    v79 = *v68;
    v80 = (float)((float)v76 - v68[2]);
    v81 = (float)((float)((float)((float)v76 - v68[2]) * p_axis->z)
                + (float)((float)((float)(endDir->x - *v68) * p_axis->x)
                        + (float)((float)((float)v75 - v68[1]) * p_axis->y)));
    v82 = (float)((float)((float)((float)((float)v76 - v68[2]) * p_axis->z)
                        + (float)((float)((float)(endDir->x - *v68) * p_axis->x)
                                + (float)((float)((float)v75 - v68[1]) * p_axis->y)))
                * p_axis->x);
    v83 = (float)((float)v81 * p_axis->y);
    v85 = (float)((float)v78 - (float)((float)v81 * p_axis->y));
    v84 = (float)((float)v81 * p_axis->z);
    v86 = (float)((float)v80 - (float)v84);
    v87 = (float)((float)v85
                * (float)((float)((float)1.0 - (float)(collisionPoint->x * collisionPoint->x))
                        * (float)((float)1.0 / (float)((float)(collisionPoint->x * collisionPoint->x) + (float)1.0))));
    v88 = (float)((float)((float)((float)((float)(endDir->x - *v68) - (float)v82) * p_axis->z)
                        - (float)((float)v86 * p_axis->x))
                * (float)((float)((float)((float)1.0
                                        / (float)((float)(collisionPoint->x * collisionPoint->x) + (float)1.0))
                                * collisionPoint->x)
                        * (float)2.0));
    v89 = (float)((float)((float)((float)((float)(endDir->x - *v68) - (float)v82)
                                * (float)((float)((float)1.0 - (float)(collisionPoint->x * collisionPoint->x))
                                        * (float)((float)1.0
                                                / (float)((float)(collisionPoint->x * collisionPoint->x) + (float)1.0))))
                        - (float)((float)((float)((float)v86 * p_axis->y) - (float)((float)v85 * p_axis->z))
                                * (float)((float)((float)((float)1.0
                                                        / (float)((float)(collisionPoint->x * collisionPoint->x)
                                                                + (float)1.0))
                                                * collisionPoint->x)
                                        * (float)2.0)))
                + (float)v82);
    endDir->z = (float)((float)((float)((float)v86
                                      * (float)((float)((float)1.0 - (float)(collisionPoint->x * collisionPoint->x))
                                              * (float)((float)1.0
                                                      / (float)((float)(collisionPoint->x * collisionPoint->x)
                                                              + (float)1.0))))
                              - (float)((float)((float)((float)v85 * p_axis->x)
                                              - (float)((float)((float)(endDir->x - *v68) - (float)v82) * p_axis->y))
                                      * (float)((float)((float)((float)1.0
                                                              / (float)((float)(collisionPoint->x * collisionPoint->x)
                                                                      + (float)1.0))
                                                      * collisionPoint->x)
                                              * (float)2.0)))
                      + (float)v84)
              + v68[2];
    endDir->x = (float)v89 + (float)v79;
    endDir->y = (float)((float)((float)v87 - (float)v88) + (float)v83) + (float)v77;
  }
  v90 = -plane->b;
  v91 = -plane->c;
  *a29 = -plane->a;
  a29[1] = v90;
  a29[2] = v91;
  return 1;
}


// ========================================================================
// ?RotateTrmVertsThroughPolygon@idPolygonModelCollisionDetection@@CA_NPIAVidTraceWork@@PIBUcm_polygon_t@@ABVidPlane@@@Z
// EA  : 0x825EEF10
// RVA : 0x005EEF10
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::RotateTrmVertsThroughPolygon(
        idTraceWork *tw,
        const cm_polygon_t *poly,
        const idPlane *polygonPlane)
{
  unsigned int v7; // r26
  idPluecker *vertexPluecker; // r25
  unsigned __int8 v17; // cr58
  unsigned __int8 v18; // cr59
  unsigned int numEdges; // r5
  double z; // fp7
  unsigned int v21; // r10
  double y; // fp8
  double x; // fp6
  double v24; // fp12
  double v25; // fp13
  int firstEdge; // r6
  float *v27; // r11
  unsigned __int16 *polygonEdges; // r7
  int v29; // r8
  unsigned __int16 *v30; // r9
  double v31; // fp5
  double v32; // fp5
  double v33; // fp5
  trace_t *traceResult; // r9
  double a; // fp0
  int material; // r8
  double v37; // fp12
  double v38; // fp11
  cm_material_t *materials; // r11
  double v40; // fp10
  cm_polygon_t *polygons; // r7
  char *v42; // r11
  int subModelNum; // r5
  float *v48; // r11
  double v49; // fp5
  int v50; // [sp+8h] [-118h]
  int v51; // [sp+Ch] [-114h]
  int v52; // [sp+10h] [-110h]
  int v53; // [sp+14h] [-10Ch]
  int v54; // [sp+18h] [-108h]
  int v55; // [sp+1Ch] [-104h]
  int v56; // [sp+20h] [-100h]
  int v57; // [sp+24h] [-FCh]
  int v58; // [sp+28h] [-F8h]
  int v59; // [sp+2Ch] [-F4h]
  int v60; // [sp+30h] [-F0h]
  int v61; // [sp+34h] [-ECh]
  int v62; // [sp+38h] [-E8h]
  int v63; // [sp+3Ch] [-E4h]
  int v64; // [sp+40h] [-E0h]
  int v65; // [sp+44h] [-DCh]
  int v66; // [sp+48h] [-D8h]
  int v67; // [sp+4Ch] [-D4h]
  int v68; // [sp+50h] [-D0h]
  idVec3 v69; // [sp+60h] [-C0h] BYREF
  float v70; // [sp+6Ch] [-B4h]
  float v71; // [sp+70h] [-B0h]
  idVec3 v72; // [sp+78h] [-A8h] BYREF
  _BYTE v73[16]; // [sp+90h] [-90h] BYREF
  _BYTE v74[24]; // [sp+A0h] [-80h] BYREF

  _R29 = poly;
  v7 = 0;
  if ( tw->numVerts == 0 )
    return 0;
  _R9 = -16;
  _R22 = vmxi_half_bnds_intersect_perm2_4;
  _R8 = v73;
  _R7 = v74;
  vertexPluecker = tw->vertexPluecker;
  __asm { lvx128    v63, r0, r22 }
  _R28 = &tw->vertexPosition[0].y;
  __asm { lvx128    v62, r22, r9 }
  _R11 = -2052;
  __asm { stvx128   v63, r0, r8 }
  __asm { stvx128   v62, r0, r7 }
  while ( 1 )
  {
    _R10 = v73;
    __asm { lvx128    v63, r28, r11 }
    _R9 = v74;
    __asm
    {
      lvx128    v62, r0, r29
      lvx128    v0, r0, r10
      lvx128    v7, r0, r9
      vperm128  v6, v95, v62, v0
      vperm128  v5, v95, v62, v7
      vcmpgtsh. v4, v5, v6
    }
    if ( ((32 * v17) & 0x20 | (16 * v18) & 0x20) == 0
      || idPolygonModelCollisionDetection::RotatePointThroughEpsilonPlane(
           tw,
           point: (const idVec3 *)(_R28 - 1),
           endPoint: (const idVec3 *)(_R28 + 127),
           plane: polygonPlane,
           angle: tw->angle,
           rotationOrigin: (const idVec3 *)(((32 * v17) & 0x20 | (16 * v18) & 0x20) != 0),
           tanHalfAngle: vertexPluecker->p,
           collisionPoint: &v69,
           endDir: &v72,
           a10: v50,
           a11: v51,
           a12: v52,
           a13: v53,
           a14: v54,
           a15: v55,
           a16: v56,
           a17: v57,
           a18: v58,
           a19: v59,
           a20: v60,
           a21: v61,
           a22: v62,
           a23: v63,
           a24: v64,
           a25: v65,
           a26: v66,
           a27: v67,
           a28: v68,
           a29: &v69.z) == 0 )
    {
      goto LABEL_25;
    }
    numEdges = _R29->numEdges;
    z = v72.z;
    v21 = 0;
    y = v72.y;
    x = v72.x;
    v24 = -v71;
    v25 = -v69.z;
    if ( numEdges >= 4 )
    {
      firstEdge = _R29->firstEdge;
      v27 = &tw->polygonEdgePlueckerCache[0].p[2];
      polygonEdges = tw->subModelPtrs.polygonEdges;
      do
      {
        v29 = firstEdge + v21;
        v30 = &polygonEdges[firstEdge + v21];
        v31 = (float)((float)(v27[2] * (float)((float)(v70 * v72.x) - (float)(v69.z * v72.y)))
                    + (float)((float)((float)v24 * *(v27 - 2))
                            + (float)((float)(v70 * *(v27 - 1))
                                    + (float)((float)((float)v25 * v27[1])
                                            + (float)((float)((float)((float)(v71 * v72.y) - (float)(v70 * v72.z)) * *v27)
                                                    + (float)((float)((float)(v71 * v72.x) - (float)(v69.z * v72.z))
                                                            * v27[3]))))));
        if ( (*v30 & 0x8000) != 0 )
        {
          if ( v31 > 0.0 )
            goto LABEL_22;
        }
        else if ( v31 < 0.0 )
        {
          goto LABEL_22;
        }
        v32 = (float)((float)(v27[8] * (float)((float)(v70 * v72.x) - (float)(v69.z * v72.y)))
                    + (float)((float)((float)v24 * v27[4])
                            + (float)((float)(v70 * v27[5])
                                    + (float)((float)((float)((float)(v71 * v72.y) - (float)(v70 * v72.z)) * v27[6])
                                            + (float)((float)((float)((float)(v71 * v72.x) - (float)(v69.z * v72.z))
                                                            * v27[9])
                                                    + (float)((float)v25 * v27[7]))))));
        if ( (v30[1] & 0x8000) != 0 )
        {
          if ( v32 > 0.0 )
            goto LABEL_13;
        }
        else if ( v32 < 0.0 )
        {
LABEL_13:
          ++v21;
          goto LABEL_22;
        }
        v33 = (float)((float)(v27[14] * (float)((float)(v70 * v72.x) - (float)(v69.z * v72.y)))
                    + (float)((float)((float)v24 * v27[10])
                            + (float)((float)(v70 * v27[11])
                                    + (float)((float)((float)((float)(v71 * v72.y) - (float)(v70 * v72.z)) * v27[12])
                                            + (float)((float)((float)((float)(v71 * v72.x) - (float)(v69.z * v72.z))
                                                            * v27[15])
                                                    + (float)((float)v25 * v27[13]))))));
        if ( (polygonEdges[v29 + 2] & 0x8000) != 0 )
        {
          if ( v33 > 0.0 )
            goto LABEL_17;
        }
        else if ( v33 < 0.0 )
        {
LABEL_17:
          v21 += 2;
          goto LABEL_22;
        }
        if ( (polygonEdges[v29 + 3] & 0x8000) != 0 )
        {
          if ( (float)((float)(v27[20] * (float)((float)(v70 * v72.x) - (float)(v69.z * v72.y)))
                     + (float)((float)((float)v24 * v27[16])
                             + (float)((float)(v70 * v27[17])
                                     + (float)((float)((float)((float)(v71 * v72.y) - (float)(v70 * v72.z)) * v27[18])
                                             + (float)((float)(v27[21]
                                                             * (float)((float)(v71 * v72.x) - (float)(v69.z * v72.z)))
                                                     + (float)((float)v25 * v27[19])))))) > 0.0 )
            goto LABEL_21;
        }
        else if ( (float)((float)(v27[20] * (float)((float)(v70 * v72.x) - (float)(v69.z * v72.y)))
                        + (float)((float)(v27[21] * (float)((float)(v71 * v72.x) - (float)(v69.z * v72.z)))
                                + (float)((float)(v27[19] * (float)v25)
                                        + (float)((float)(v27[18] * (float)((float)(v71 * v72.y) - (float)(v70 * v72.z)))
                                                + (float)((float)(v27[17] * v70) + (float)(v27[16] * (float)v24)))))) < 0.0 )
        {
LABEL_21:
          v21 += 3;
          goto LABEL_22;
        }
        v21 += 4;
        v27 += 24;
      }
      while ( v21 < numEdges - 3 );
    }
    if ( v21 < numEdges )
    {
      v48 = &tw->polygonEdgePlueckerCache[v21].p[2];
      do
      {
        v49 = (float)((float)(v48[2] * (float)((float)(v70 * v72.x) - (float)(v69.z * v72.y)))
                    + (float)((float)((float)v24 * *(v48 - 2))
                            + (float)((float)(v70 * *(v48 - 1))
                                    + (float)((float)((float)v25 * v48[1])
                                            + (float)((float)((float)((float)(v71 * v72.y) - (float)(v70 * v72.z)) * *v48)
                                                    + (float)((float)((float)(v71 * v72.x) - (float)(v69.z * v72.z))
                                                            * v48[3]))))));
        if ( (tw->subModelPtrs.polygonEdges[_R29->firstEdge + v21] & 0x8000) != 0 )
        {
          if ( v49 > 0.0 )
            break;
        }
        else if ( v49 < 0.0 )
        {
          break;
        }
        ++v21;
        v48 += 6;
      }
      while ( v21 < numEdges );
LABEL_22:
      if ( v21 < numEdges )
        goto LABEL_25;
    }
    traceResult = tw->traceResult;
    a = polygonPlane->a;
    material = _R29->material;
    v37 = __fabs(v69.x);
    tw->maxTan = v37;
    v38 = _R28[1];
    materials = tw->subModelPtrs.materials;
    v40 = *(_R28 - 1);
    traceResult->c.normal.x = a;
    polygons = tw->subModelPtrs.polygons;
    v42 = (char *)materials + __ROL4__(material, 4);
    traceResult->c.normal.y = polygonPlane->b;
    traceResult->c.normal.z = polygonPlane->c;
    subModelNum = tw->subModelNum;
    traceResult->c.dist = -polygonPlane->d;
    traceResult->c.separation = (float)((float)(polygonPlane->a * (float)v40)
                                      + (float)((float)((float)v38 * polygonPlane->c) + (float)(*_R28 * polygonPlane->b)))
                              + polygonPlane->d;
    traceResult->c.contentFlags = *(_DWORD *)v42;
    traceResult->c.surfaceFlags = *((_DWORD *)v42 + 1);
    traceResult->c.surfaceType = *((_DWORD *)v42 + 2);
    traceResult->c.surfaceColor[0] = v42[12];
    traceResult->c.surfaceColor[1] = v42[13];
    traceResult->c.surfaceColor[2] = v42[14];
    traceResult->c.type = CONTACT_TRMVERTEX;
    traceResult->c.modelFeature = (unsigned __int16)(_R29 - polygons) | (subModelNum << 16) & 0x1FFF0000 | 0x60000000;
    traceResult->c.trmFeature = v7;
    traceResult->c.point.x = x;
    traceResult->c.point.y = y;
    traceResult->c.point.z = z;
    traceResult->c.flags = 0;
    if ( v37 == 0.0 )
      return 1;
    _R11 = -16;
    __asm { lvx128    v61, r0, r22 }
    _R10 = v73;
    _R9 = v74;
    __asm
    {
      lvx128    v60, r22, r11
      stvx128   v61, r0, r10
      stvx128   v60, r0, r9
    }
LABEL_25:
    ++v7;
    ++vertexPluecker;
    _R28 += 4;
    _R11 = -2052;
    if ( v7 >= tw->numVerts )
      return 0;
  }
}


// ========================================================================
// ?RotatePolygonVertsThroughTrm@idPolygonModelCollisionDetection@@CA_NPIAVidTraceWork@@PIBUcm_polygon_t@@@Z
// EA  : 0x825EF3D8
// RVA : 0x005EF3D8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::RotatePolygonVertsThroughTrm(
        idTraceWork *tw,
        const cm_polygon_t *poly)
{
  unsigned __int8 **p_edgeCheckCounts; // r5
  unsigned int v11; // r8
  int v12; // r10
  int v13; // r4
  int v14; // r30
  int v15; // r18
  cm_edge_t *v16; // r17
  unsigned int v17; // r16
  unsigned __int8 **p_vertexCheckCounts; // r15
  int v19; // r24
  int v20; // r3
  int v21; // r9
  cm_vertex_t *v22; // r29
  double x; // fp0
  double y; // fp12
  double z; // fp13
  char v26; // r11
  double v28; // fp13
  double v30; // fp12
  double v39; // fp8
  float *p_y; // r28
  float *p_z; // r27
  unsigned int v42; // r26
  double v43; // fp13
  double v44; // fp7
  double v45; // fp6
  float *v55; // r30
  unsigned __int8 v56; // cr58
  unsigned __int8 v57; // cr59
  double v58; // fp7
  double v59; // fp1
  double v60; // fp3
  double v61; // fp0
  unsigned int v62; // r7
  unsigned int v63; // r8
  double v64; // fp12
  double v65; // fp13
  int v66; // r11
  bool v67; // cr58
  idPluecker *v68; // r11
  double v69; // fp5
  int v70; // r11
  bool v71; // cr58
  idPluecker *v72; // r11
  double v73; // fp5
  int v74; // r11
  bool v75; // cr58
  idPluecker *v76; // r11
  double v77; // fp5
  int v78; // r11
  bool v79; // cr58
  idPluecker *v80; // r11
  double v81; // fp5
  trace_t *traceResult; // r11
  double v83; // fp0
  double v84; // fp13
  double v85; // fp11
  double v86; // fp4
  int material; // r9
  cm_material_t *materials; // r10
  double v89; // fp8
  char *v90; // r10
  int v91; // r5
  int v98; // r11
  bool v99; // cr58
  idPluecker *v100; // r11
  double v101; // fp5
  int v103; // [sp+8h] [-1B8h]
  int v104; // [sp+Ch] [-1B4h]
  int v105; // [sp+10h] [-1B0h]
  int v106; // [sp+14h] [-1ACh]
  int v107; // [sp+18h] [-1A8h]
  int v108; // [sp+1Ch] [-1A4h]
  int v109; // [sp+20h] [-1A0h]
  int v110; // [sp+24h] [-19Ch]
  int v111; // [sp+28h] [-198h]
  int v112; // [sp+2Ch] [-194h]
  int v113; // [sp+30h] [-190h]
  int v114; // [sp+34h] [-18Ch]
  int v115; // [sp+38h] [-188h]
  int v116; // [sp+3Ch] [-184h]
  int v117; // [sp+40h] [-180h]
  int v118; // [sp+44h] [-17Ch]
  int v119; // [sp+48h] [-178h]
  int v120; // [sp+4Ch] [-174h]
  int v121; // [sp+50h] [-170h]
  int v122; // [sp+60h] [-160h]
  unsigned __int8 **v123; // [sp+6Ch] [-154h]
  idVec3 v124; // [sp+74h] [-14Ch] BYREF
  _BYTE v125[16]; // [sp+80h] [-140h] BYREF
  float v126[6]; // [sp+90h] [-130h] BYREF
  float v127[4]; // [sp+A8h] [-118h] BYREF
  idVec3 v128; // [sp+B8h] [-108h] BYREF
  idVec3 v129; // [sp+C8h] [-F8h] BYREF
  float v130; // [sp+D8h] [-E8h] BYREF
  float v131; // [sp+DCh] [-E4h]
  float v132; // [sp+E0h] [-E0h]
  _BYTE v133[16]; // [sp+F0h] [-D0h] BYREF
  _BYTE v134[32]; // [sp+100h] [-C0h] BYREF

  _R12 = -176;
  __asm { stvx128   v127, r1, r12 }
  v122 = 0;
  if ( poly->numEdges == 0 )
  {
LABEL_43:
    _R0 = -176;
    __asm { lvx128    v127, r1, r0 }
    return 0;
  }
  p_edgeCheckCounts = &tw->modelCheckCounts.edgeCheckCounts;
  v123 = &tw->modelCheckCounts.edgeCheckCounts;
  _R7 = idBoundsShort::vector_int_max_ushort;
  _R6 = &idBoundsShort::vector_float_max_ushort;
  _R19 = 8;
  _R14 = idBoundsShort::vector_int_zero;
  while ( 1 )
  {
    v11 = tw->subModelPtrs.polygonEdges[poly->firstEdge + v122];
    v12 = (int)(v11 & 0x3FFF) >> 3;
    v13 = (unsigned __int8)(1 << (v11 & 7));
    v14 = (*p_edgeCheckCounts)[v12];
    (*p_edgeCheckCounts)[v12] = v14 | v13;
    if ( (v14 & v13) == 0 && (v11 & 0x4000) == 0 )
      break;
LABEL_42:
    if ( ++v122 >= (unsigned int)poly->numEdges )
      goto LABEL_43;
  }
  v15 = 0;
  v16 = &tw->subModelPtrs.edges[v11 & 0x3FFF];
  v17 = v11 >> 15;
  p_vertexCheckCounts = &tw->modelCheckCounts.vertexCheckCounts;
  while ( 1 )
  {
    v19 = v16->vertexNum[v17 ^ v15];
    v20 = (*p_vertexCheckCounts)[v19 >> 3];
    v21 = (unsigned __int8)(1 << (v19 & 7));
    (*p_vertexCheckCounts)[v19 >> 3] = v20 | v21;
    if ( (v20 & v21) == 0 )
    {
      v22 = &tw->subModelPtrs.vertices[v19];
      x = v22->p.x;
      if ( tw->traceBoundsMin.x > x
        || (y = v22->p.y, tw->traceBoundsMin.y > y)
        || (z = v22->p.z, tw->traceBoundsMin.z > z)
        || x > tw->traceBoundsMax.x
        || y > tw->traceBoundsMax.y
        || (v26 = 1, z > tw->traceBoundsMax.z) )
      {
        v26 = 0;
      }
      if ( v26 != 0 )
      {
        _R11 = v126;
        v28 = v22->p.y;
        _R10 = v126;
        v30 = v22->p.z;
        _R9 = 16;
        v126[0] = v22->p.x;
        v126[3] = x;
        _R8 = v126;
        v126[1] = v28;
        _R5 = v126;
        v126[2] = v30;
        _R4 = 24;
        v126[4] = v28;
        __asm { vspltisw128 v61, 0 }
        v126[5] = v30;
        __asm { lvrx128   v60, r9, r11 }
        __asm { lvlx128   v59, r0, r10 }
        _R3 = v125;
        __asm { lvrx128   v58, r4, r8 }
        _R11 = 4;
        __asm
        {
          lvlx128   v57, r19, r5
          vor128    v56, v89, v58
        }
        __asm
        {
          vor128    v55, v91, v60
          vsldoi128 v54, v88, v61, 4
        }
        __asm { lvx128    v63, r0, r6 }
        _R10 = v125;
        _R9 = v125;
        __asm { vrlimi128 v55, v61, 1, 0 }
        __asm { vsubfp128 v53, v86, v63 }
        v39 = tw->origin.z;
        __asm
        {
          lvx128    v0, r0, r7
          vaddfp128 v52, v87, v63
        }
        __asm { lvx128    v62, r0, r14 }
        p_y = &v22->p.y;
        p_z = &v22->p.z;
        v42 = 0;
        __asm
        {
          vcfpsxws128 v13, v53, 0
          vcfpsxws128 v12, v52, 0
        }
        v43 = (float)((float)((float)((float)v30 - tw->origin.z) * tw->axis.z)
                    + (float)((float)((float)v28 - tw->origin.y) * tw->axis.y));
        __asm { vaddsws   v11, v13, v0 }
        __asm
        {
          vsubsws   v10, v12, v0
          vpkswss128 v51, v11, v62
          vpkswss128 v50, v10, v62
          vsldoi128 v49, v93, v51, 0xA
        }
        __asm { vor128    v48, v82, v49 }
        v44 = (float)((float)((float)((float)((float)x - tw->origin.x) * tw->axis.x) + (float)v43) * tw->axis.z);
        __asm
        {
          vspltw128 v47, v48, 0
          vspltw128 v46, v48, 1
          vspltw128 v45, v48, 2
        }
        v45 = (float)((float)((float)((float)((float)((float)x - tw->origin.x) * tw->axis.x) + (float)v43) * tw->axis.x)
                    + tw->origin.x);
        v127[1] = (float)((float)((float)((float)((float)x - tw->origin.x) * tw->axis.x) + (float)v43) * tw->axis.y)
                + tw->origin.y;
        v127[0] = v45;
        v127[2] = (float)v44 + (float)v39;
        __asm
        {
          stvewx128 v47, r0, r3
          stvewx128 v46, r10, r11
          stvewx128 v45, r9, r19
        }
        if ( tw->numPolys != 0 )
          break;
      }
    }
LABEL_40:
    if ( ++v15 >= 2 )
    {
      p_edgeCheckCounts = v123;
      goto LABEL_42;
    }
  }
  _R10 = vmxi_half_bnds_intersect_perm2_4;
  _R9 = -16;
  _R8 = v125;
  _R7 = v133;
  _R6 = v134;
  _R25 = &tw->polys[0].numEdges;
  __asm { lvx128    v44, r0, r10 }
  _R11 = -12;
  __asm
  {
    lvx128    v43, r10, r9
    lvx128    v127, r0, r8
    stvx128   v44, r0, r7
    stvx128   v43, r0, r6
  }
  while ( 1 )
  {
    _R10 = v133;
    __asm { lvx128    v63, r25, r11 }
    _R9 = v134;
    v55 = (float *)(_R25 - 7);
    __asm
    {
      lvx128    v0, r0, r10
      lvx128    v7, r0, r9
      vperm128  v6, v95, v127, v0
      vperm128  v5, v95, v127, v7
      vcmpgtsh. v4, v5, v6
    }
    if ( ((32 * v56) & 0x20 | (16 * v57) & 0x20) == 0 )
      goto LABEL_38;
    v58 = tw->endTransform.mat[11];
    v59 = -tw->angle;
    v60 = (float)((float)(tw->endTransform.mat[8] * v22->p.x)
                + (float)((float)(tw->endTransform.mat[9] * *p_y) + (float)(tw->endTransform.mat[10] * *p_z)));
    v61 = (float)((float)((float)(tw->endTransform.mat[4] * v22->p.x)
                        + (float)((float)(tw->endTransform.mat[5] * *p_y) + (float)(tw->endTransform.mat[6] * *p_z)))
                + tw->endTransform.mat[7]);
    v128.x = (float)((float)(tw->endTransform.mat[0] * v22->p.x)
                   + (float)((float)(tw->endTransform.mat[1] * *p_y) + (float)(tw->endTransform.mat[2] * *p_z)))
           + tw->endTransform.mat[3];
    v128.y = v61;
    v128.z = (float)v60 + (float)v58;
    if ( idPolygonModelCollisionDetection::RotatePointThroughEpsilonPlane(
           tw,
           point: &v22->p,
           endPoint: &v128,
           plane: (const idPlane *)(_R25 - 7),
           angle: v59,
           rotationOrigin: (const idVec3 *)(((32 * v56) & 0x20 | (16 * v57) & 0x20) != 0),
           tanHalfAngle: v127,
           collisionPoint: &v124,
           endDir: &v129,
           a10: v103,
           a11: v104,
           a12: v105,
           a13: v106,
           a14: v107,
           a15: v108,
           a16: v109,
           a17: v110,
           a18: v111,
           a19: v112,
           a20: v113,
           a21: v114,
           a22: v115,
           a23: v116,
           a24: v117,
           a25: v118,
           a26: v119,
           a27: v120,
           a28: v121,
           a29: &v130) == 0 )
      goto LABEL_38;
    v62 = *_R25;
    v63 = 0;
    v64 = -v132;
    v65 = -v130;
    if ( (int)*_R25 >= 4 )
    {
      do
      {
        v66 = *((unsigned __int8 *)_R25 + v63 + 4);
        v67 = (v66 & 0x80) == 0;
        v68 = &tw->edgePluecker[v66 & 0xFFFFFF7F];
        v69 = (float)((float)(v68->p[0] * (float)v64)
                    + (float)((float)(v68->p[4] * (float)((float)(v131 * v129.x) - (float)(v129.y * v130)))
                            + (float)((float)(v68->p[5] * (float)((float)(v132 * v129.x) - (float)(v129.z * v130)))
                                    + (float)((float)(v68->p[3] * (float)v65)
                                            + (float)((float)(v68->p[1] * v131)
                                                    + (float)(v68->p[2]
                                                            * (float)((float)(v132 * v129.y) - (float)(v129.z * v131))))))));
        if ( v67 )
        {
          if ( v69 < 0.0 )
            goto LABEL_35;
        }
        else if ( v69 > 0.0 )
        {
          goto LABEL_35;
        }
        v70 = *((unsigned __int8 *)v55 + v63 + 33);
        v71 = (v70 & 0x80) == 0;
        v72 = &tw->edgePluecker[v70 & 0xFFFFFF7F];
        v73 = (float)((float)(v72->p[0] * (float)v64)
                    + (float)((float)(v72->p[4] * (float)((float)(v131 * v129.x) - (float)(v129.y * v130)))
                            + (float)((float)(v72->p[5] * (float)((float)(v132 * v129.x) - (float)(v129.z * v130)))
                                    + (float)((float)(v72->p[3] * (float)v65)
                                            + (float)((float)(v72->p[1] * v131)
                                                    + (float)(v72->p[2]
                                                            * (float)((float)(v132 * v129.y) - (float)(v129.z * v131))))))));
        if ( v71 )
        {
          if ( v73 < 0.0 )
          {
LABEL_26:
            ++v63;
            goto LABEL_35;
          }
        }
        else if ( v73 > 0.0 )
        {
          goto LABEL_26;
        }
        v74 = *((unsigned __int8 *)v55 + v63 + 34);
        v75 = (v74 & 0x80) == 0;
        v76 = &tw->edgePluecker[v74 & 0xFFFFFF7F];
        v77 = (float)((float)(v76->p[0] * (float)v64)
                    + (float)((float)(v76->p[4] * (float)((float)(v131 * v129.x) - (float)(v129.y * v130)))
                            + (float)((float)(v76->p[5] * (float)((float)(v132 * v129.x) - (float)(v129.z * v130)))
                                    + (float)((float)(v76->p[3] * (float)v65)
                                            + (float)((float)(v76->p[1] * v131)
                                                    + (float)(v76->p[2]
                                                            * (float)((float)(v132 * v129.y) - (float)(v129.z * v131))))))));
        if ( v75 )
        {
          if ( v77 < 0.0 )
          {
LABEL_30:
            v63 += 2;
            goto LABEL_35;
          }
        }
        else if ( v77 > 0.0 )
        {
          goto LABEL_30;
        }
        v78 = *((unsigned __int8 *)v55 + v63 + 35);
        v79 = (v78 & 0x80) == 0;
        v80 = &tw->edgePluecker[v78 & 0xFFFFFF7F];
        v81 = (float)((float)(v80->p[0] * (float)v64)
                    + (float)((float)(v80->p[4] * (float)((float)(v131 * v129.x) - (float)(v129.y * v130)))
                            + (float)((float)(v80->p[5] * (float)((float)(v132 * v129.x) - (float)(v129.z * v130)))
                                    + (float)((float)(v80->p[3] * (float)v65)
                                            + (float)((float)(v80->p[1] * v131)
                                                    + (float)(v80->p[2]
                                                            * (float)((float)(v132 * v129.y) - (float)(v129.z * v131))))))));
        if ( v79 )
        {
          if ( v81 < 0.0 )
          {
LABEL_34:
            v63 += 3;
            goto LABEL_35;
          }
        }
        else if ( v81 > 0.0 )
        {
          goto LABEL_34;
        }
        v63 += 4;
      }
      while ( v63 < v62 - 3 );
    }
    for ( ; v63 < v62; ++v63 )
    {
      v98 = *((unsigned __int8 *)v55 + v63 + 32);
      v99 = (v98 & 0x80) == 0;
      v100 = &tw->edgePluecker[v98 & 0xFFFFFF7F];
      v101 = (float)((float)(v100->p[0] * (float)v64)
                   + (float)((float)(v100->p[4] * (float)((float)(v131 * v129.x) - (float)(v129.y * v130)))
                           + (float)((float)(v100->p[5] * (float)((float)(v132 * v129.x) - (float)(v129.z * v130)))
                                   + (float)((float)(v100->p[3] * (float)v65)
                                           + (float)((float)(v100->p[1] * v131)
                                                   + (float)(v100->p[2]
                                                           * (float)((float)(v132 * v129.y) - (float)(v129.z * v131))))))));
      if ( v99 )
      {
        if ( v101 < 0.0 )
          break;
      }
      else if ( v101 > 0.0 )
      {
        break;
      }
    }
LABEL_35:
    if ( v63 < *_R25 )
      goto LABEL_38;
    traceResult = tw->traceResult;
    v83 = *v55;
    v84 = v55[1];
    v85 = v55[2];
    v86 = __fabs(v124.x);
    tw->maxTan = v86;
    traceResult->c.normal.x = -v83;
    material = poly->material;
    traceResult->c.normal.y = -v84;
    materials = tw->subModelPtrs.materials;
    traceResult->c.normal.z = -v85;
    v89 = v55[3];
    v90 = (char *)materials + __ROL4__(material, 4);
    v91 = (tw->subModelNum << 16) & 0x1FFF0000 | 0x20000000 | (unsigned __int16)v19;
    traceResult->c.dist = (float)(traceResult->c.normal.x * v22->p.x)
                        + (float)((float)((float)-v85 * *p_z) + (float)((float)-v84 * *p_y));
    traceResult->c.separation = (float)((float)((float)v85 * *p_z)
                                      + (float)((float)((float)v84 * *p_y) + (float)((float)v83 * v22->p.x)))
                              + (float)v89;
    traceResult->c.contentFlags = *(_DWORD *)v90;
    traceResult->c.surfaceFlags = *((_DWORD *)v90 + 1);
    traceResult->c.surfaceType = *((_DWORD *)v90 + 2);
    traceResult->c.surfaceColor[0] = v90[12];
    traceResult->c.surfaceColor[1] = v90[13];
    traceResult->c.surfaceColor[2] = v90[14];
    traceResult->c.type = CONTACT_MODELVERTEX;
    traceResult->c.modelFeature = v91;
    traceResult->c.trmFeature = v42;
    traceResult->c.point.x = v22->p.x;
    traceResult->c.point.y = *p_y;
    traceResult->c.point.z = *p_z;
    traceResult->c.flags = 0;
    if ( v86 == 0.0 )
      break;
    _R11 = vmxi_half_bnds_intersect_perm2_4;
    _R10 = -16;
    _R9 = v133;
    _R8 = v134;
    __asm
    {
      lvx128    v42, r0, r11
      lvx128    v41, r11, r10
      stvx128   v42, r0, r9
      stvx128   v41, r0, r8
    }
LABEL_38:
    ++v42;
    _R25 += 16;
    _R11 = -12;
    if ( v42 >= tw->numPolys )
    {
      _R7 = idBoundsShort::vector_int_max_ushort;
      _R6 = &idBoundsShort::vector_float_max_ushort;
      goto LABEL_40;
    }
  }
  _R0 = -176;
  __asm { lvx128    v127, r1, r0 }
  return 1;
}


// ========================================================================
// ?RotateTrmThroughPolygon@idPolygonModelCollisionDetection@@CA_NPIAVidTraceWork@@I@Z
// EA  : 0x825EFC50
// RVA : 0x005EFC50
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

BOOL __fastcall idPolygonModelCollisionDetection::RotateTrmThroughPolygon(
        idTraceWork *tw,
        int polygonNum,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v12; // r5
  int v13; // r3
  unsigned __int8 *polygonCheckCounts; // r10
  unsigned __int8 v20; // cr58
  unsigned __int8 v21; // cr59
  int v22; // r3
  idTraceWork *v23; // r3
  float v24; // [sp+8h] [-88h]
  float v25; // [sp+Ch] [-84h]
  float v26; // [sp+10h] [-80h]
  float v27; // [sp+14h] [-7Ch]
  float v28; // [sp+18h] [-78h]
  float v29; // [sp+1Ch] [-74h]
  float v30; // [sp+20h] [-70h]
  float v31; // [sp+24h] [-6Ch]
  idPlane v32[4]; // [sp+50h] [-40h] BYREF

  _R31 = tw;
  v12 = tw->modelCheckCounts.polygonCheckCounts[polygonNum >> 3];
  polygonCheckCounts = tw->modelCheckCounts.polygonCheckCounts;
  v13 = (unsigned __int8)(1 << (polygonNum & 7));
  polygonCheckCounts[polygonNum >> 3] = v12 | v13;
  if ( (v12 & v13) != 0 )
    return false;
  _R30 = &_R31->subModelPtrs.polygons[polygonNum];
  if ( (*(int *)((_BYTE *)&_R31->subModelPtrs.materials->contentFlags + __ROL4__(_R30->material, 4)) & _R31->contents) == 0 )
    return false;
  __asm { lvx128    v63, r0, r30 }
  _R10 = 6176;
  _R9 = vmxi_half_bnds_intersect_perm2_4;
  _R8 = -16;
  __asm
  {
    lvx128    v62, r31, r10
    lvx128    v0, r0, r9
    lvx128    v7, r9, r8
    vperm128  v0, v94, v63, v0
    vperm128  v13, v94, v63, v7
    vcmpgtsh. v12, v13, v0
  }
  if ( ((32 * v20) & 0x20 | (16 * v21) & 0x20) == 0
    || CM_BoundsShortPlaneCull(
         bs: &_R30->bounds,
         plane: &_R31->heartPlane1,
         cmpdist: _R31->maxDistFromHeartPlane1,
         a4,
         a5,
         a6,
         a7,
         a8,
         a9,
         a10,
         a11: v24,
         a12: v25,
         a13: v26,
         a14: v27,
         a15: v28,
         a16: v29,
         a17: v30,
         a18: v31) )
  {
    return false;
  }
  CM_GetPolygonPlane(subModel: &_R31->subModelPtrs, polygon: _R30, plane: v32);
  v22 = CM_BoundsPlaneSide(boundsMin: &_R31->traceBoundsMin, boundsMax: &_R31->traceBoundsMax, plane: v32);
  if ( v22 != 3 )
  {
    if ( v22 == 0 && _R31->subModelPtrs.isConvex != 0 )
    {
      _R31->quickExit = true;
      return true;
    }
    return false;
  }
  idPolygonModelCollisionDetection::RotationEdgePlueckerCache(tw: _R31, polygon: _R30);
  idPolygonModelCollisionDetection::RotationCullPolygonEdges(tw: v23, polygon: _R30);
  return (unsigned __int8)idPolygonModelCollisionDetection::RotateTrmVertsThroughPolygon(
                            tw: _R31,
                            poly: _R30,
                            polygonPlane: v32) != 0
      || (unsigned __int8)idPolygonModelCollisionDetection::RotateTrmEdgesThroughPolygon(tw: _R31, poly: _R30) != 0
      || (unsigned __int8)idPolygonModelCollisionDetection::RotatePolygonVertsThroughTrm(tw: _R31, poly: _R30) != 0;
}


// ========================================================================
// ?StartRotation@idPolygonModelCollisionDetection@@SA_NPAVidTraceWork@@PAUtrace_t@@ABVidVec3@@2M2PBVidTraceModel@@ABVidMat3@@H24@Z
// EA  : 0x825EFE00
// RVA : 0x005EFE00
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::StartRotation(
        idTraceWork *tw,
        trace_t *result,
        const idVec3 *rorg,
        const idVec3 *axis,
        double angle,
        const idVec3 *start,
        const idVec3 *trm,
        const idMat3 *trmAxis,
        idMat3 *contentMask,
        const idVec3 *modelOrigin,
        const idMat3 *modelAxis,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        const idMat3 *a31,
        int a32,
        int a33)
{
  float y; // r6
  const idVec3 *v42; // r5
  const idVec3 *v43; // r4
  double x; // fp0
  double v45; // fp13
  double z; // fp12
  idTraceWork *v47; // r3
  idTraceWork *v48; // r3
  idTraceWork *v49; // r3
  int v51; // [sp+8h] [-2A8h]
  int v52; // [sp+Ch] [-2A4h]
  int v53; // [sp+10h] [-2A0h]
  int v54; // [sp+14h] [-29Ch]
  int v55; // [sp+18h] [-298h]
  int v56; // [sp+1Ch] [-294h]
  int v57; // [sp+20h] [-290h]
  int v58; // [sp+24h] [-28Ch]
  int v59; // [sp+28h] [-288h]
  int v60; // [sp+2Ch] [-284h]
  int v61; // [sp+30h] [-280h]
  int v62; // [sp+34h] [-27Ch]
  int v63; // [sp+38h] [-278h]
  int v64; // [sp+3Ch] [-274h]
  int v65; // [sp+40h] [-270h]
  int v66; // [sp+44h] [-26Ch]
  int v67; // [sp+48h] [-268h]
  int v68; // [sp+4Ch] [-264h]
  int v69; // [sp+50h] [-260h]
  idVec4 v70[32]; // [sp+60h] [-250h] BYREF

  result->fraction = 1.0;
  result->endpos.x = trm->x;
  result->endpos.y = trm->y;
  result->endpos.z = trm->z;
  result->endAxis = *contentMask;
  XMemSet(dest: &result->c, c: 0, count: 0x4Cu);
  if ( angle == 0.0 || ((LODWORD(axis->z) | LODWORD(axis->y) | LODWORD(axis->x)) & 0x7FFFFFFF) == 0 )
    return 0;
  tw->contactsResult = nullptr;
  tw->fraction = 1.0;
  tw->traceType = TRACE_ROTATION;
  tw->clipResult = nullptr;
  tw->contents = a29;
  tw->traceResult = result;
  tw->isConvex = HIBYTE(trmAxis[42].mat[1].z);
  tw->quickExit = false;
  tw->numVerts = LODWORD(trmAxis[41].mat[0].x);
  y = trmAxis[41].mat[0].y;
  *(float *)&tw->numEdges = y;
  tw->numPolys = LODWORD(trmAxis[41].mat[0].z);
  idPolygonModelCollisionDetection::RotationSetup(
    tw,
    rorg,
    axis,
    angle,
    start: (const idVec3 *)LODWORD(y),
    offset: trm,
    trmAxis: (const idMat3 *)((char *)trmAxis + 1492),
    modelOrigin: contentMask->mat,
    modelAxis: a31,
    a10: v51,
    a11: v52,
    a12: v53,
    a13: v54,
    a14: v55,
    a15: v56,
    a16: v57,
    a17: v58,
    a18: v59,
    a19: v60,
    a20: v61,
    a21: v62,
    a22: v63,
    a23: v64,
    a24: v65,
    a25: v66,
    a26: v67,
    a27: v68,
    a28: v69,
    a29: a33);
  idPolygonModelCollisionDetection::TransformAxisToZAxis(
    transform: &tw->ZAxisTransform,
    origin: (const idVec3 *)&tw->origin,
    axis: (const idVec3 *)&tw->axis);
  idPolygonModelCollisionDetection::TransformFromOriginAxisAngle(
    transform: &tw->endTransform,
    origin: v43,
    axis: v42,
    angle);
  x = tw->axis.x;
  tw->heartPlane1.a = tw->axis.x;
  v45 = tw->axis.y;
  tw->heartPlane1.b = tw->axis.y;
  z = tw->axis.z;
  tw->heartPlane1.c = tw->axis.z;
  tw->heartPlane1.d = -(float)((float)((float)x * tw->start.x)
                             + (float)((float)(tw->start.z * (float)z) + (float)(tw->start.y * (float)v45)));
  idMat3x4::Transform(this: &tw->endTransform, result: (idVec3 *)&tw->end, v: (const idVec3 *)&tw->start);
  idPolygonModelCollisionDetection::RotationVerts(tw, trm: (const idTraceModel *)trmAxis, zverts: v70);
  idPolygonModelCollisionDetection::RotationEdges(tw: v47, trm: (const idTraceModel *)trmAxis, zverts: v70);
  idPolygonModelCollisionDetection::RotationPolys(tw: v48, trm: (const idTraceModel *)trmAxis);
  idPolygonModelCollisionDetection::RotationBounds(tw: v49);
  idMat3x4::Invert(this: &tw->endTransform);
  return 1;
}


// ========================================================================
// ?StartRotationPoint@idPolygonModelCollisionDetection@@SA_NPAVidTraceWork@@PAUtrace_t@@ABVidVec3@@2M2H2ABVidMat3@@@Z
// EA  : 0x825F0028
// RVA : 0x005F0028
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

int __fastcall idPolygonModelCollisionDetection::StartRotationPoint(
        idTraceWork *tw,
        trace_t *result,
        const idVec3 *rorg,
        const idVec3 *axis,
        double angle,
        const idVec3 *start,
        idVec3 *contentMask,
        const idVec3 *modelOrigin,
        const idMat3 *modelAxis,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        float *a29)
{
  char v37; // r24
  double v38; // fp1
  float *p_x; // r29
  double y; // fp10
  float *v41; // r28
  double v42; // fp9
  float *v43; // r30
  double v44; // fp6
  double v45; // fp6
  double z; // fp4
  double v47; // fp0
  double v48; // fp13
  double v49; // fp7
  double v50; // fp1
  double v51; // fp0
  double v52; // fp10
  double v53; // fp9
  double v54; // fp1
  double v55; // fp11
  double v56; // fp10
  double v57; // fp13
  double v58; // fp9
  double v59; // fp3
  double v60; // fp13
  double v61; // fp5
  double v62; // fp12
  double v63; // fp0
  double v64; // fp10
  const idVec3 *v65; // r5
  const idVec3 *v66; // r4
  double v67; // fp0
  double v68; // fp13
  double v69; // fp12
  double v70; // fp5
  double v71; // fp1
  double v72; // fp9
  double v73; // fp6

  _R31 = tw;
  result->fraction = 1.0;
  result->endpos = *contentMask;
  result->endAxis.mat[2].z = 1.0;
  result->endAxis.mat[1].y = 1.0;
  result->endAxis.mat[0].x = 1.0;
  result->endAxis.mat[1].z = 0.0;
  result->endAxis.mat[0].z = 0.0;
  result->endAxis.mat[0].y = 0.0;
  result->endAxis.mat[2].y = 0.0;
  result->endAxis.mat[2].x = 0.0;
  result->endAxis.mat[1].x = 0.0;
  XMemSet(dest: &result->c, c: 0, count: 0x4Cu);
  if ( angle == 0.0 || ((LODWORD(axis->z) | LODWORD(axis->x) | LODWORD(axis->y)) & 0x7FFFFFFF) == 0 )
    return 0;
  v37 = 0;
  _R31->fraction = 1.0;
  _R31->angle = angle;
  _R31->traceResult = result;
  _R31->isConvex = true;
  _R31->quickExit = false;
  _R31->contents = (int)modelOrigin;
  _R31->contactsResult = nullptr;
  _R31->clipResult = nullptr;
  _R31->traceType = TRACE_ROTATION_POINT;
  _R31->numVerts = 1;
  _R31->numEdges = 0;
  _R31->numPolys = 0;
  v38 = CM_TanZeroHalfPI(a: __fabs((float)((float)((float)3.1415927 * (float)0.0027777778) * (float)angle)));
  _R31->initialTan = v38;
  _R31->maxTan = v38;
  p_x = &_R31->start.x;
  y = contentMask->y;
  v41 = &_R31->origin.x;
  v42 = modelAxis->mat[0].y;
  v43 = &_R31->axis.x;
  v44 = (float)(contentMask->z - modelAxis->mat[0].z);
  _R31->start.x = contentMask->x - modelAxis->mat[0].x;
  _R31->start.y = (float)y - (float)v42;
  _R31->start.z = v44;
  v45 = modelAxis->mat[0].y;
  z = modelAxis->mat[0].z;
  v47 = (float)(rorg->y
              - (float)(axis->y
                      * (float)((float)(axis->x * (float)(rorg->x - contentMask->x))
                              + (float)((float)(axis->z * (float)(rorg->z - contentMask->z))
                                      + (float)(axis->y * (float)(rorg->y - contentMask->y))))));
  v48 = (float)(rorg->z
              - (float)(axis->z
                      * (float)((float)(axis->x * (float)(rorg->x - contentMask->x))
                              + (float)((float)(axis->z * (float)(rorg->z - contentMask->z))
                                      + (float)(axis->y * (float)(rorg->y - contentMask->y))))));
  _R31->origin.x = (float)(rorg->x
                         - (float)(axis->x
                                 * (float)((float)(axis->x * (float)(rorg->x - contentMask->x))
                                         + (float)((float)(axis->z * (float)(rorg->z - contentMask->z))
                                                 + (float)(axis->y * (float)(rorg->y - contentMask->y))))))
                 - modelAxis->mat[0].x;
  _R31->origin.y = (float)v47 - (float)v45;
  _R31->origin.z = (float)v48 - (float)z;
  _R31->axis.x = axis->x;
  _R31->axis.y = axis->y;
  _R31->axis.z = axis->z;
  if ( *a29 != 1.0 || a29[4] != 1.0 || a29[8] != 1.0 )
    v37 = 1;
  if ( v37 != 0 )
  {
    v49 = _R31->start.z;
    v50 = a29[8];
    v52 = (float)((float)(a29[7] * _R31->start.y) + (float)(_R31->start.x * a29[6]));
    v53 = (float)((float)(a29[3] * _R31->start.x) + (float)(a29[4] * _R31->start.y));
    v51 = a29[5];
    *p_x = (float)(_R31->start.y * a29[1]) + (float)((float)(_R31->start.z * a29[2]) + (float)(*a29 * _R31->start.x));
    _R31->start.z = (float)((float)v49 * (float)v50) + (float)v52;
    _R31->start.y = (float)((float)v51 * (float)v49) + (float)v53;
    v54 = _R31->origin.z;
    v55 = a29[8];
    v56 = a29[5];
    v57 = (float)((float)(a29[3] * _R31->origin.x) + (float)(a29[4] * _R31->origin.y));
    v58 = (float)((float)(a29[7] * _R31->origin.y) + (float)(_R31->origin.x * a29[6]));
    _R31->origin.x = (float)(_R31->origin.y * a29[1])
                   + (float)((float)(_R31->origin.z * a29[2]) + (float)(_R31->origin.x * *a29));
    _R31->origin.y = (float)((float)v56 * (float)v54) + (float)v57;
    _R31->origin.z = (float)((float)v54 * (float)v55) + (float)v58;
    v59 = _R31->axis.z;
    v60 = a29[1];
    v61 = _R31->axis.y;
    v62 = a29[8];
    v63 = (float)((float)(a29[7] * _R31->axis.y) + (float)(_R31->axis.x * a29[6]));
    v64 = (float)((float)(_R31->axis.z * a29[2]) + (float)(_R31->axis.x * *a29));
    _R31->axis.y = (float)(a29[5] * _R31->axis.z)
                 + (float)((float)(a29[3] * _R31->axis.x) + (float)(a29[4] * _R31->axis.y));
    _R31->axis.z = (float)((float)v59 * (float)v62) + (float)v63;
    *v43 = (float)((float)v61 * (float)v60) + (float)v64;
  }
  idPolygonModelCollisionDetection::TransformAxisToZAxis(
    transform: &_R31->ZAxisTransform,
    origin: (const idVec3 *)&_R31->origin,
    axis: (const idVec3 *)&_R31->axis);
  idPolygonModelCollisionDetection::TransformFromOriginAxisAngle(
    transform: &_R31->endTransform,
    origin: v66,
    axis: v65,
    angle);
  v67 = *v43;
  _R31->heartPlane1.a = *v43;
  v68 = _R31->axis.y;
  _R31->heartPlane1.b = _R31->axis.y;
  v69 = _R31->axis.z;
  _R31->heartPlane1.c = _R31->axis.z;
  _R31->heartPlane1.d = -(float)((float)(_R31->start.x * (float)v67)
                               + (float)((float)(_R31->start.z * (float)v69) + (float)(_R31->start.y * (float)v68)));
  _R31->maxDistFromHeartPlane1 = 1.0;
  idMat3x4::Transform(this: &_R31->endTransform, result: (idVec3 *)&_R31->end, v: (const idVec3 *)&_R31->start);
  _R31->vertexPosition[0].x = *p_x;
  _R31->vertexPosition[0].y = _R31->start.y;
  _R31->vertexPosition[0].z = _R31->start.z;
  _R31->vertexEndPosition[0].x = _R31->end.x;
  _R31->vertexEndPosition[0].y = _R31->end.y;
  _R31->vertexEndPosition[0].z = _R31->end.z;
  v70 = _R31->origin.z;
  v71 = *v41;
  v72 = (float)(_R31->axis.x
              * (float)((float)(_R31->axis.x * (float)(_R31->vertexPosition[0].x - _R31->origin.x))
                      + (float)((float)(_R31->axis.z * (float)(_R31->vertexPosition[0].z - _R31->origin.z))
                              + (float)(_R31->axis.y * (float)(_R31->vertexPosition[0].y - _R31->origin.y)))));
  v73 = (float)(_R31->axis.z
              * (float)((float)(_R31->axis.x * (float)(_R31->vertexPosition[0].x - _R31->origin.x))
                      + (float)((float)(_R31->axis.z * (float)(_R31->vertexPosition[0].z - _R31->origin.z))
                              + (float)(_R31->axis.y * (float)(_R31->vertexPosition[0].y - _R31->origin.y)))));
  _R31->vertexPluecker[0].p[1] = v41[1]
                               + (float)(v43[1]
                                       * (float)((float)(*v43 * (float)(_R31->vertexPosition[0].x - *v41))
                                               + (float)((float)(v43[2] * (float)(_R31->vertexPosition[0].z - v41[2]))
                                                       + (float)(v43[1] * (float)(_R31->vertexPosition[0].y - v41[1])))));
  _R31->vertexPluecker[0].p[0] = (float)v71 + (float)v72;
  _R31->vertexPluecker[0].p[2] = (float)v70 + (float)v73;
  CM_PointRotationBounds(
    origin: (const idVec3 *)_R31->vertexPluecker,
    axis: (const idVec3 *)&_R31->axis,
    start: (const idVec3 *)_R31->vertexPosition,
    end: (const idVec3 *)_R31->vertexEndPosition,
    boundsMin: &_R31->traceBoundsMin,
    boundsMax: &_R31->traceBoundsMax);
  _R10 = -96;
  __asm { vspltisw128 v62, 0 }
  _R9 = vmxi_word_max_ushort_4;
  __asm
  {
    lvx128    v63, r9, r10
    lvx128    v61, r0, r8
    vsubfp128 v60, v93, v63
    lvx128    v59, r0, r7
    vcfpsxws128 v13, v60, 0
    vaddfp128 v58, v91, v63
    lvx128    v0, r0, r9
    vaddsws   v11, v13, v0
    vcfpsxws128 v12, v58, 0
    vpkswss128 v57, v11, v62
    vsldoi128 v55, v94, v57, 0xA
    vsubsws   v10, v12, v0
    vpkswss128 v56, v10, v62
    vor128    v54, v88, v55
    stvx128   v54, r0, r31
  }
  idPolygonModelCollisionDetection::RotationBounds(tw: _R31);
  return 1;
}


// ========================================================================
// ?FinishRotation@idPolygonModelCollisionDetection@@SAXPAVidTraceWork@@ABVidVec3@@1M1ABVidMat3@@12HHHHH@Z
// EA  : 0x825F0518
// RVA : 0x005F0518
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_rotate.cpp
// ========================================================================

void __fastcall idPolygonModelCollisionDetection::FinishRotation(
        idTraceWork *tw,
        const idVec3 *rorg,
        const idVec3 *axis,
        double angle,
        const idVec3 *start,
        const idMat3 *trmAxis,
        const idMat3 *modelOrigin,
        const idMat3 *modelAxis,
        float *modelEntityNum,
        int modelPhysicsId,
        int modelBodyId,
        int selfId,
        int modelContentsOverride,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int modelEntityNum_0)
{
  double maxTan; // fp1
  char v46; // r11
  idVec3 *p_normal; // r11
  double v48; // fp7
  double z; // fp6
  double v50; // fp0
  double v51; // fp11
  double v52; // fp10
  idVec3 *p_point; // r11
  double x; // fp13
  double y; // fp0
  double v56; // fp12
  double v57; // fp10
  double v58; // fp4
  double v59; // fp3
  idVec3 *v60; // r11
  trace_t *traceResult; // r11
  trace_t *v62; // r11
  trace_t *v63; // r11
  double v64; // fp6
  double v65; // fp5
  double v66; // fp4
  double v67; // fp3
  double v68; // fp2
  double v69; // fp1
  double v70; // fp0
  double v71; // fp11
  idMat3x4 v72; // [sp+50h] [-80h] BYREF

  maxTan = tw->maxTan;
  if ( maxTan == tw->initialTan )
  {
    tw->traceResult->fraction = 1.0;
  }
  else
  {
    tw->traceResult->fraction = __fabs((float)(CM_ArcTanPositive(a: maxTan)
                                             * (float)((float)((float)360.0 / (float)3.1415927) / tw->angle)));
    if ( *modelEntityNum != 1.0 || modelEntityNum[4] != 1.0 || (v46 = 0, modelEntityNum[8] != 1.0) )
      v46 = 1;
    if ( v46 != 0 )
    {
      p_normal = &tw->traceResult->c.normal;
      v48 = modelEntityNum[7];
      z = tw->traceResult->c.normal.z;
      v50 = modelEntityNum[8];
      v51 = (float)((float)(p_normal->x * modelEntityNum[2]) + (float)(tw->traceResult->c.normal.y * modelEntityNum[5]));
      v52 = (float)((float)(tw->traceResult->c.normal.y * modelEntityNum[4]) + (float)(p_normal->x * modelEntityNum[1]));
      p_normal->x = (float)(p_normal->x * *modelEntityNum)
                  + (float)((float)(tw->traceResult->c.normal.y * modelEntityNum[3])
                          + (float)(modelEntityNum[6] * tw->traceResult->c.normal.z));
      p_normal->z = (float)((float)v50 * (float)z) + (float)v51;
      p_normal->y = (float)((float)z * (float)v48) + (float)v52;
      p_point = &tw->traceResult->c.point;
      x = p_point->x;
      y = tw->traceResult->c.point.y;
      v56 = modelEntityNum[3];
      v57 = modelEntityNum[2];
      v58 = (float)((float)(*modelEntityNum * p_point->x) + (float)(modelEntityNum[6] * tw->traceResult->c.point.z));
      v59 = (float)((float)(tw->traceResult->c.point.y * modelEntityNum[5])
                  + (float)(modelEntityNum[8] * tw->traceResult->c.point.z));
      p_point->y = (float)(tw->traceResult->c.point.y * modelEntityNum[4])
                 + (float)((float)(p_point->x * modelEntityNum[1])
                         + (float)(tw->traceResult->c.point.z * modelEntityNum[7]));
      p_point->x = (float)((float)y * (float)v56) + (float)v58;
      p_point->z = (float)((float)x * (float)v57) + (float)v59;
    }
    if ( ((LODWORD(modelAxis->mat[0].x) | LODWORD(modelAxis->mat[0].y) | LODWORD(modelAxis->mat[0].z)) & 0x7FFFFFFF) != 0 )
    {
      v60 = &tw->traceResult->c.point;
      v60->x = modelAxis->mat[0].x + v60->x;
      v60->y = modelAxis->mat[0].y + v60->y;
      v60->z = modelAxis->mat[0].z + v60->z;
      traceResult = tw->traceResult;
      traceResult->c.dist = (float)((float)(modelAxis->mat[0].x * traceResult->c.normal.x)
                                  + (float)((float)(traceResult->c.normal.y * modelAxis->mat[0].y)
                                          + (float)(traceResult->c.normal.z * modelAxis->mat[0].z)))
                          + traceResult->c.dist;
    }
    tw->traceResult->c.entityNum = a29;
    tw->traceResult->c.physicsId = a31;
    tw->traceResult->c.bodyId = a33;
    tw->traceResult->c.selfId = a35;
    if ( modelEntityNum_0 != 0 )
      tw->traceResult->c.contentFlags = modelEntityNum_0;
  }
  v62 = tw->traceResult;
  if ( v62->fraction != 0.0 )
  {
    idPolygonModelCollisionDetection::TransformFromOriginAxisAngle(
      transform: &v72,
      origin: rorg,
      axis,
      angle: (float)(v62->fraction * (float)angle));
    v63 = tw->traceResult;
    v64 = v72.mat[6];
    v65 = v72.mat[4];
    v66 = v72.mat[5];
    v67 = v72.mat[7];
    v68 = v72.mat[10];
    v69 = v72.mat[8];
    v70 = v72.mat[9];
    v71 = v72.mat[11];
    v63->endpos.x = (float)((float)(trmAxis->mat[0].x * v72.mat[0])
                          + (float)((float)(trmAxis->mat[0].y * v72.mat[1]) + (float)(trmAxis->mat[0].z * v72.mat[2])))
                  + v72.mat[3];
    v63->endpos.y = (float)((float)(trmAxis->mat[0].y * (float)v66)
                          + (float)((float)((float)v65 * trmAxis->mat[0].x) + (float)(trmAxis->mat[0].z * (float)v64)))
                  + (float)v67;
    v63->endpos.z = (float)((float)(trmAxis->mat[0].y * (float)v70)
                          + (float)((float)((float)v69 * trmAxis->mat[0].x) + (float)(trmAxis->mat[0].z * (float)v68)))
                  + (float)v71;
    idMat3x4::Rotate(this: &v72, result: &tw->traceResult->endAxis, m: modelOrigin);
    idMat3::OrthoNormalizeSelf(this: &tw->traceResult->endAxis);
  }
}

