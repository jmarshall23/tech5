
// ========================================================================
// ?ComputePointLightProjectionMatrix@idRenderLightParms@@QBAXAAVidRenderMatrix@@@Z
// EA  : 0x82943DD8
// RVA : 0x00943DD8
// PDB : w:\tech5\engine\renderer\renderlightparms.cpp
// ========================================================================

void __fastcall idRenderLightParms::ComputePointLightProjectionMatrix(
        idRenderLightParms *this,
        idRenderMatrix *localProject)
{
  memset(Dst: localProject, Val: 0, Size: sizeof(idRenderMatrix));
  localProject->m[0] = (float)0.5 / this->lightRadius.x;
  localProject->m[5] = (float)0.5 / this->lightRadius.y;
  localProject->m[10] = (float)0.5 / this->lightRadius.z;
  localProject->m[3] = 0.5;
  localProject->m[7] = 0.5;
  localProject->m[11] = 0.5;
  localProject->m[15] = 1.0;
}


// ========================================================================
// ?ComputeSpotLightProjectionMatrix@idRenderLightParms@@QBAXAAVidRenderMatrix@@@Z
// EA  : 0x82943E60
// RVA : 0x00943E60
// PDB : w:\tech5\engine\renderer\renderlightparms.cpp
// ========================================================================

void __fastcall idRenderLightParms::ComputeSpotLightProjectionMatrix(
        idRenderLightParms *this,
        idRenderMatrix *localProject)
{
  double x; // fp10
  double v3; // fp4
  double z; // fp26
  double v5; // fp12
  double v6; // fp30
  double v7; // fp3
  double y; // fp27
  double v9; // fp28
  double v10; // fp1
  double v11; // fp6
  double v12; // fp7
  double v14; // fp29
  double v15; // fp5
  double v16; // fp1
  double v17; // fp9
  double v18; // fp8
  double v21; // fp12
  double v22; // fp6
  double v23; // fp13
  double v24; // fp12
  double v25; // fp10
  double v26; // fp6
  double v27; // fp5
  double v28; // fp13
  double v29; // fp12
  double v30; // fp9
  double v35; // fp5
  double v36; // fp4
  idVec4 v37; // [sp+50h] [-50h] BYREF

  x = this->target.x;
  v3 = this->right.x;
  z = this->target.z;
  v5 = idMath::FLT_SMALLEST_NON_DENORMAL;
  v6 = this->right.z;
  v7 = this->up.x;
  y = this->target.y;
  v9 = this->up.z;
  v10 = (float)((float)(this->target.x * this->target.x) + (float)(this->target.y * this->target.y));
  v11 = (float)((float)(this->right.x * this->right.x) + (float)(this->right.y * this->right.y));
  v12 = this->right.y;
  v14 = this->up.y;
  v15 = (float)((float)(this->up.x * this->up.x) + (float)(this->up.y * this->up.y));
  localProject->m[3] = 0.0;
  localProject->m[7] = 0.0;
  v16 = (float)((float)((float)z * (float)z) + (float)v10);
  localProject->m[15] = 0.0;
  v17 = (float)((float)((float)v6 * (float)v6) + (float)v11);
  v18 = (float)((float)((float)v9 * (float)v9) + (float)v15);
  _FP6 = (float)((float)v16 - (float)v5);
  __asm { fsel      f2, f6, f1, f12 }
  v21 = __frsqrte(_FP2);
  v22 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21
                                                                                      * (float)((float)v16 * (float)0.5))
                                                                              * (float)v21)
                                                                      - (float)1.5)
                                                      * (float)v21)
                                              * (float)((float)v16 * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v21
                                                                              * (float)((float)v16 * (float)0.5))
                                                                      * (float)v21)
                                                              - (float)1.5)
                                              * (float)v21))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)v16 * (float)0.5)) * (float)v21)
                                      - (float)1.5)
                      * (float)v21));
  v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)v16 * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                              * (float)v21)
                                                                                      * (float)((float)v16 * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)v16 * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                      * (float)v21))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v21
                                                                                              * (float)((float)v16 * (float)0.5))
                                                                                      * (float)v21)
                                                                              - (float)1.5)
                                                              * (float)v21))
                                              * (float)((float)v16 * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)v16 * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                      * (float)v21)
                                                                              * (float)((float)v16 * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)v16 * (float)0.5)) * (float)v21)
                                                                                              - (float)1.5)
                                                                              * (float)v21))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v21
                                                                                      * (float)((float)v16 * (float)0.5))
                                                                              * (float)v21)
                                                                      - (float)1.5)
                                                      * (float)v21)))
                              - (float)1.5)
              * (float)v22);
  v25 = (float)((float)x
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)v16 * (float)0.5)) * (float)v21) - (float)1.5) * (float)v21)
                                                                                              * (float)((float)v16 * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)v16 * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                              * (float)v21))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)v16 * (float)0.5))
                                                                                              * (float)v21)
                                                                                      - (float)1.5)
                                                                      * (float)v21))
                                                      * (float)((float)v16 * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)v16 * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                              * (float)v21)
                                                                                      * (float)((float)v16 * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)v16 * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                      * (float)v21))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v21
                                                                                              * (float)((float)v16 * (float)0.5))
                                                                                      * (float)v21)
                                                                              - (float)1.5)
                                                              * (float)v21)))
                                      - (float)1.5)
                      * (float)v22));
  v24 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)v16 * (float)0.5)) * (float)v21) - (float)1.5) * (float)v21)
                                                                                              * (float)((float)v16 * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)v16 * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                              * (float)v21))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)v16 * (float)0.5))
                                                                                              * (float)v21)
                                                                                      - (float)1.5)
                                                                      * (float)v21))
                                                      * (float)((float)v16 * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)v16 * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                              * (float)v21)
                                                                                      * (float)((float)v16 * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)v16 * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                      * (float)v21))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v21
                                                                                              * (float)((float)v16 * (float)0.5))
                                                                                      * (float)v21)
                                                                              - (float)1.5)
                                                              * (float)v21)))
                                      - (float)1.5)
                      * (float)v22)
              * (float)v16);
  localProject->m[12] = v25;
  v26 = (float)((float)y * (float)v23);
  localProject->m[13] = (float)y * (float)v23;
  v27 = (float)((float)v23 * (float)z);
  localProject->m[14] = (float)v23 * (float)z;
  v28 = (float)((float)((float)v24 * (float)0.5) / (float)v17);
  v30 = (float)((float)v12 * (float)((float)((float)v24 * (float)0.5) / (float)v17));
  v29 = (float)((float)((float)v24 * (float)-0.5) / (float)v18);
  localProject->m[1] = v30;
  localProject->m[0] = (float)v3 * (float)v28;
  localProject->m[4] = (float)v7 * (float)v29;
  localProject->m[2] = (float)v28 * (float)v6;
  localProject->m[5] = (float)v29 * (float)v14;
  localProject->m[6] = (float)v9 * (float)v29;
  _FP9 = (float)((float)((float)(this->end.x * (float)v25)
                       + (float)((float)(this->end.y * (float)v26) + (float)(this->end.z * (float)v27)))
               - (float)16.0);
  _FP11 = (float)((float)((float)(this->start.x * (float)v25)
                        + (float)((float)(this->start.y * (float)v26) + (float)(this->start.z * (float)v27)))
                - (float)8.0);
  __asm
  {
    fsel      f7, f9, f12, f13
    fsel      f8, f11, f1, f0
  }
  localProject->m[8] = (float)v25 * (float)((float)((float)_FP7 + (float)_FP8) / (float)_FP7);
  localProject->m[9] = (float)v26 * (float)((float)((float)_FP7 + (float)_FP8) / (float)_FP7);
  localProject->m[10] = (float)v27 * (float)((float)((float)_FP7 + (float)_FP8) / (float)_FP7);
  localProject->m[11] = -(float)((float)((float)((float)_FP7 + (float)_FP8) / (float)_FP7) * (float)_FP8);
  idRenderMatrix::TransformPoint(this: localProject, in: &this->target, out: &v37);
  v35 = (float)-(float)((float)((float)((float)1.0 / v37.w) * v37.x) - (float)0.5);
  v36 = (float)-(float)((float)((float)((float)1.0 / v37.w) * v37.y) - (float)0.5);
  localProject->m[0] = (float)(localProject->m[12]
                             * (float)-(float)((float)((float)((float)1.0 / v37.w) * v37.x) - (float)0.5))
                     + localProject->m[0];
  localProject->m[1] = (float)((float)v35 * localProject->m[13]) + localProject->m[1];
  localProject->m[2] = (float)(localProject->m[14] * (float)v35) + localProject->m[2];
  localProject->m[3] = (float)((float)v35 * localProject->m[15]) + localProject->m[3];
  localProject->m[4] = (float)(localProject->m[12] * (float)v36) + localProject->m[4];
  localProject->m[5] = (float)((float)v36 * localProject->m[13]) + localProject->m[5];
  localProject->m[6] = (float)(localProject->m[14] * (float)v36) + localProject->m[6];
  localProject->m[7] = (float)((float)v36 * localProject->m[15]) + localProject->m[7];
}


// ========================================================================
// ?ComputeWorldToLightMatrix@idRenderLightParms@@QBAXAAVidRenderMatrix@@0@Z
// EA  : 0x829440F8
// RVA : 0x009440F8
// PDB : w:\tech5\engine\renderer\renderlightparms.cpp
// ========================================================================

void __fastcall idRenderLightParms::ComputeWorldToLightMatrix(
        idRenderLightParms *this,
        idRenderMatrix *baseLightProject,
        idRenderMatrix *inverseBaseLightProject,
        int a4,
        int a5,
        __int64 a6)
{
  lightType_t lightType; // r11
  float *v10; // r11
  int i; // ctr
  double y; // fp12
  double z; // fp11
  double v14; // fp10
  double x; // fp12
  double v16; // fp11
  double v17; // fp10
  double v18; // fp9
  double v19; // fp8
  double v20; // fp7
  double v21; // fp6
  double v22; // fp5
  double v23; // fp4
  double v24; // fp3
  double v25; // fp2
  idRenderMatrix v26; // [sp+50h] [-F0h] BYREF
  idRenderMatrix v27; // [sp+90h] [-B0h] BYREF
  idRenderMatrix v28; // [sp+D0h] [-70h] BYREF

  lightType = this->lightType;
  if ( lightType == LIGHT_PARALLEL )
  {
    v10 = &v26.m[14];
    LODWORD(a6) = 0;
    for ( i = 8; i != 0; --i )
    {
      v10 += 2;
      *(_QWORD *)v10 = a6;
    }
    y = this->lightRadius.y;
    z = this->lightRadius.z;
    v14 = (float)((float)0.5 / this->lightRadius.x);
    v27.m[15] = 1.0;
    v27.m[3] = 0.5;
    v27.m[0] = v14;
    v27.m[5] = (float)0.5 / (float)y;
    v27.m[10] = (float)0.5 / (float)z;
    v27.m[7] = 0.5;
    v27.m[11] = 0.5;
  }
  else if ( lightType == LIGHT_SPOT )
  {
    idRenderLightParms::ComputeSpotLightProjectionMatrix(this, localProject: &v27);
  }
  else
  {
    idRenderLightParms::ComputePointLightProjectionMatrix(this, localProject: &v27);
  }
  x = this->axis.mat[1].x;
  v16 = this->axis.mat[2].x;
  v17 = this->origin.x;
  v18 = this->axis.mat[0].y;
  v19 = this->axis.mat[1].y;
  v20 = this->axis.mat[2].y;
  v21 = this->origin.y;
  v22 = this->axis.mat[0].z;
  v23 = this->axis.mat[1].z;
  v24 = this->axis.mat[2].z;
  v25 = this->origin.z;
  v26.m[0] = this->axis.mat[0].x;
  v26.m[12] = 0.0;
  v26.m[1] = x;
  v26.m[13] = 0.0;
  v26.m[2] = v16;
  v26.m[14] = 0.0;
  v26.m[3] = v17;
  v26.m[15] = 1.0;
  v26.m[4] = v18;
  v26.m[5] = v19;
  v26.m[6] = v20;
  v26.m[7] = v21;
  v26.m[8] = v22;
  v26.m[9] = v23;
  v26.m[10] = v24;
  v26.m[11] = v25;
  if ( !idRenderMatrix::Inverse(src: &v26, out: &v28) )
    idLib::Warning(fmt: "lightMatrix invert failed");
  idRenderMatrix::Multiply(a: &v27, b: &v28, out: baseLightProject);
  if ( !idRenderMatrix::Inverse(src: baseLightProject, out: inverseBaseLightProject) )
    idLib::Warning(fmt: "baseLightProject invert failed");
}


// ========================================================================
// ?ComputeLightGlobalOrigin@idRenderLightParms@@QBAXAAVidVec3@@@Z
// EA  : 0x82944278
// RVA : 0x00944278
// PDB : w:\tech5\engine\renderer\renderlightparms.cpp
// ========================================================================

void __fastcall idRenderLightParms::ComputeLightGlobalOrigin(idRenderLightParms *this, idVec3 *globalOrigin)
{
  lightType_t lightType; // r11
  double v5; // fp2
  double v6; // fp2
  double v7; // fp13
  double y; // fp9
  double z; // fp8
  double v10; // fp9
  double v11; // fp5
  double v12; // fp2
  double v13; // fp1
  idVec3 lightCenter; // 0:^0.12

  lightType = this->lightType;
  if ( lightType == LIGHT_PARALLEL )
  {
    lightCenter = this->lightCenter;
    _FP5 = (float)((float)((float)(lightCenter.x * lightCenter.x)
                         + (float)((float)(lightCenter.y * lightCenter.y) + (float)(lightCenter.z * lightCenter.z)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f3, f5, f6, f13 }
    v5 = __frsqrte(_FP3);
    v6 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5
                                                                                       * (float)((float)((float)(lightCenter.x * lightCenter.x) + (float)((float)(lightCenter.y * lightCenter.y) + (float)(lightCenter.z * lightCenter.z)))
                                                                                               * (float)0.5))
                                                                               * (float)v5)
                                                                       - (float)1.5)
                                                       * (float)v5)
                                               * (float)((float)((float)(lightCenter.x * lightCenter.x)
                                                               + (float)((float)(lightCenter.y * lightCenter.y)
                                                                       + (float)(lightCenter.z * lightCenter.z)))
                                                       * (float)0.5))
                                       * (float)((float)-(float)((float)((float)((float)v5
                                                                               * (float)((float)((float)(lightCenter.x * lightCenter.x)
                                                                                               + (float)((float)(lightCenter.y * lightCenter.y) + (float)(lightCenter.z * lightCenter.z)))
                                                                                       * (float)0.5))
                                                                       * (float)v5)
                                                               - (float)1.5)
                                               * (float)v5))
                               - (float)1.5)
               * (float)((float)-(float)((float)((float)((float)v5
                                                       * (float)((float)((float)(lightCenter.x * lightCenter.x)
                                                                       + (float)((float)(lightCenter.y * lightCenter.y)
                                                                               + (float)(lightCenter.z * lightCenter.z)))
                                                               * (float)0.5))
                                               * (float)v5)
                                       - (float)1.5)
                       * (float)v5));
    v7 = (float)(lightCenter.z
               * (float)((float)-(float)((float)((float)((float)v6
                                                       * (float)((float)((float)(lightCenter.x * lightCenter.x)
                                                                       + (float)((float)(lightCenter.y * lightCenter.y)
                                                                               + (float)(lightCenter.z * lightCenter.z)))
                                                               * (float)0.5))
                                               * (float)v6)
                                       - (float)1.5)
                       * (float)v6));
    if ( (float)((float)((float)-(float)((float)((float)((float)v6
                                                       * (float)((float)((float)(lightCenter.x * lightCenter.x)
                                                                       + (float)((float)(lightCenter.y * lightCenter.y)
                                                                               + (float)(lightCenter.z * lightCenter.z)))
                                                               * (float)0.5))
                                               * (float)v6)
                                       - (float)1.5)
                       * (float)v6)
               * (float)((float)(lightCenter.x * lightCenter.x)
                       + (float)((float)(lightCenter.y * lightCenter.y) + (float)(lightCenter.z * lightCenter.z)))) == 0.0 )
      v7 = 1.0;
    y = this->origin.y;
    z = this->origin.z;
    globalOrigin->x = this->origin.x
                    + (float)((float)(lightCenter.x
                                    * (float)((float)-(float)((float)((float)((float)v6
                                                                            * (float)((float)((float)(lightCenter.x * lightCenter.x)
                                                                                            + (float)((float)(lightCenter.y * lightCenter.y) + (float)(lightCenter.z * lightCenter.z)))
                                                                                    * (float)0.5))
                                                                    * (float)v6)
                                                            - (float)1.5)
                                            * (float)v6))
                            * (float)100000.0);
    globalOrigin->y = (float)y
                    + (float)((float)(lightCenter.y
                                    * (float)((float)-(float)((float)((float)((float)v6
                                                                            * (float)((float)((float)(lightCenter.x * lightCenter.x)
                                                                                            + (float)((float)(lightCenter.y * lightCenter.y) + (float)(lightCenter.z * lightCenter.z)))
                                                                                    * (float)0.5))
                                                                    * (float)v6)
                                                            - (float)1.5)
                                            * (float)v6))
                            * (float)100000.0);
    globalOrigin->z = (float)z + (float)((float)v7 * (float)100000.0);
  }
  else if ( lightType == LIGHT_SPOT )
  {
    *globalOrigin = this->origin;
  }
  else
  {
    v10 = this->origin.y;
    v11 = this->origin.z;
    v12 = (float)((float)(this->axis.mat[2].y * this->lightCenter.z)
                + (float)((float)(this->axis.mat[0].y * this->lightCenter.x)
                        + (float)(this->axis.mat[1].y * this->lightCenter.y)));
    v13 = (float)((float)(this->axis.mat[2].z * this->lightCenter.z)
                + (float)((float)(this->axis.mat[0].z * this->lightCenter.x)
                        + (float)(this->axis.mat[1].z * this->lightCenter.y)));
    globalOrigin->x = this->origin.x
                    + (float)((float)(this->lightCenter.x * this->axis.mat[0].x)
                            + (float)((float)(this->axis.mat[1].x * this->lightCenter.y)
                                    + (float)(this->axis.mat[2].x * this->lightCenter.z)));
    globalOrigin->y = (float)v10 + (float)v12;
    globalOrigin->z = (float)v11 + (float)v13;
  }
}


// ========================================================================
// ?ComputeLightGlobalReferenceBounds@idRenderLightParms@@QBAXABVidRenderMatrix@@AAVidBounds@@QAVidVec3@@@Z
// EA  : 0x82944408
// RVA : 0x00944408
// PDB : w:\tech5\engine\renderer\renderlightparms.cpp
// ========================================================================

void __fastcall idRenderLightParms::ComputeLightGlobalReferenceBounds(
        idRenderLightParms *this,
        const idRenderMatrix *inverseBaseLightProject,
        idBounds *globalReferenceBounds,
        idVec3 *corners)
{
  __int64 v4; // r11
  int v5; // r3
  idVec3 *v6; // r9
  __int64 v7; // r8
  double v8; // fp13
  double v9; // fp11
  int v10; // ctr
  double v11; // fp2
  double v12; // fp10
  double v13; // fp8
  double v14; // fp5

  v5 = 0;
  globalReferenceBounds->b[0].z = 1.0e30;
  globalReferenceBounds->b[0].y = 1.0e30;
  globalReferenceBounds->b[0].x = 1.0e30;
  globalReferenceBounds->b[1].z = -1.0e30;
  globalReferenceBounds->b[1].y = -1.0e30;
  globalReferenceBounds->b[1].x = -1.0e30;
  do
  {
    LODWORD(v4) = v5;
    v6 = corners;
    HIDWORD(v7) = 0;
    v8 = (float)v4;
    corners += 4;
    do
    {
      LODWORD(v4) = HIDWORD(v7);
      v9 = (double)v4;
      v4 = (unsigned int)v6;
      v10 = 2;
      v6 += 2;
      do
      {
        LODWORD(v7) = HIDWORD(v4)++;
        v11 = (float)((float)((float)((float)v9 * inverseBaseLightProject->m[13])
                            + (float)((float)(inverseBaseLightProject->m[14] * (float)v7)
                                    + (float)((float)v8 * inverseBaseLightProject->m[12])))
                    + inverseBaseLightProject->m[15]);
        v13 = (float)((float)((float)((float)v7 * inverseBaseLightProject->m[10])
                            + (float)((float)(inverseBaseLightProject->m[8] * (float)v8)
                                    + (float)(inverseBaseLightProject->m[9] * (float)v9)))
                    + inverseBaseLightProject->m[11]);
        v14 = (float)((float)((float)((float)(inverseBaseLightProject->m[6] * (float)v7)
                                    + (float)((float)(inverseBaseLightProject->m[4] * (float)v8)
                                            + (float)(inverseBaseLightProject->m[5] * (float)v9)))
                            + inverseBaseLightProject->m[7])
                    * (float)((float)1.0
                            / (float)((float)((float)((float)v9 * inverseBaseLightProject->m[13])
                                            + (float)((float)(inverseBaseLightProject->m[14] * (float)v7)
                                                    + (float)((float)v8 * inverseBaseLightProject->m[12])))
                                    + inverseBaseLightProject->m[15])));
        v12 = (float)((float)((float)(inverseBaseLightProject->m[2] * (float)v7)
                            + (float)((float)(inverseBaseLightProject->m[1] * (float)v9)
                                    + (float)(inverseBaseLightProject->m[0] * (float)v8)))
                    + inverseBaseLightProject->m[3]);
        *(float *)(v4 + 4) = (float)((float)((float)(inverseBaseLightProject->m[6] * (float)v7)
                                           + (float)((float)(inverseBaseLightProject->m[4] * (float)v8)
                                                   + (float)(inverseBaseLightProject->m[5] * (float)v9)))
                                   + inverseBaseLightProject->m[7])
                           * (float)((float)1.0
                                   / (float)((float)((float)((float)v9 * inverseBaseLightProject->m[13])
                                                   + (float)((float)(inverseBaseLightProject->m[14] * (float)v7)
                                                           + (float)((float)v8 * inverseBaseLightProject->m[12])))
                                           + inverseBaseLightProject->m[15]));
        *(float *)(v4 + 8) = (float)v13 * (float)((float)1.0 / (float)v11);
        *(float *)v4 = (float)v12 * (float)((float)1.0 / (float)v11);
        LODWORD(v4) = v4 + 12;
        _FP7 = (float)(globalReferenceBounds->b[0].x - (float)((float)v12 * (float)((float)1.0 / (float)v11)));
        _FP31 = (float)(globalReferenceBounds->b[0].z - (float)((float)v13 * (float)((float)1.0 / (float)v11)));
        _FP30 = (float)((float)((float)v12 * (float)((float)1.0 / (float)v11)) - globalReferenceBounds->b[1].x);
        _FP29 = (float)((float)v14 - globalReferenceBounds->b[1].y);
        _FP28 = (float)((float)((float)v13 * (float)((float)1.0 / (float)v11)) - globalReferenceBounds->b[1].z);
        _FP8 = (float)(globalReferenceBounds->b[0].y - (float)v14);
        __asm { fsel      f9, f8, f5, f9 }
        globalReferenceBounds->b[0].y = _FP9;
        __asm { fsel      f8, f7, f6, f10 }
        globalReferenceBounds->b[0].x = _FP8;
        __asm { fsel      f7, f31, f4, f3 }
        globalReferenceBounds->b[0].z = _FP7;
        __asm { fsel      f6, f30, f6, f2 }
        globalReferenceBounds->b[1].x = _FP6;
        __asm { fsel      f5, f29, f5, f1 }
        globalReferenceBounds->b[1].y = _FP5;
        __asm { fsel      f4, f28, f4, f11 }
        globalReferenceBounds->b[1].z = _FP4;
        --v10;
      }
      while ( v10 != 0 );
      ++HIDWORD(v7);
    }
    while ( SHIDWORD(v7) <= 1 );
    ++v5;
  }
  while ( v5 <= 1 );
}

