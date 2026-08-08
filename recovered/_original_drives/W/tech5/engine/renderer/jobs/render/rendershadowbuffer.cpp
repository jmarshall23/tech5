
// ========================================================================
// ?GetPointLightViewMatrix@@YAXHAAVidRenderMatrix@@@Z
// EA  : 0x828E1DC0
// RVA : 0x008E1DC0
// PDB : w:\tech5\engine\renderer\jobs\render\rendershadowbuffer.cpp
// ========================================================================

void __fastcall GetPointLightViewMatrix(
        unsigned int side,
        idRenderMatrix *lightViewMatrix,
        int a3,
        int a4,
        int a5,
        __int64 a6)
{
  char *v6; // r11
  int i; // ctr
  double v8; // fp0
  char v9; // [sp+48h] [-58h] BYREF
  idRenderMatrix v10; // [sp+50h] [-50h] BYREF

  v6 = &v9;
  LODWORD(a6) = 0;
  for ( i = 8; i != 0; --i )
  {
    v6 += 8;
    *(_QWORD *)v6 = a6;
  }
  v10.m[15] = 1.0;
  if ( side <= 5 )
  {
    if ( side != 1 )
    {
      switch ( side )
      {
        case 2u:
          v10.m[1] = 1.0;
          v10.m[10] = 1.0;
          v8 = -1.0;
          break;
        case 3u:
          v10.m[10] = 1.0;
          v8 = -1.0;
          v10.m[1] = -1.0;
          break;
        case 4u:
          v10.m[2] = 1.0;
          v10.m[9] = 1.0;
          v8 = -1.0;
          break;
        case 0u:
          v10.m[0] = 1.0;
          v10.m[9] = 1.0;
          v10.m[6] = -1.0;
          goto LABEL_16;
        default:
          v10.m[9] = 1.0;
          v8 = -1.0;
          v10.m[2] = -1.0;
          break;
      }
      v10.m[4] = v8;
      goto LABEL_16;
    }
    v10.m[9] = 1.0;
    v10.m[0] = -1.0;
    v10.m[6] = -1.0;
  }
LABEL_16:
  idRenderMatrix::Multiply(a: &renderMatrix_flipToOpenGL, b: &v10, out: lightViewMatrix);
}


// ========================================================================
// ?GetSpotLightViewMatrix@@YAXABVidVec3@@00AAVidRenderMatrix@@@Z
// EA  : 0x828E1EB8
// RVA : 0x008E1EB8
// PDB : w:\tech5\engine\renderer\jobs\render\rendershadowbuffer.cpp
// ========================================================================

void __fastcall GetSpotLightViewMatrix(
        const idVec3 *lightTarget,
        const idVec3 *lightRight,
        const idVec3 *lightUp,
        idRenderMatrix *lightViewMatrix)
{
  double x; // fp8
  double v5; // fp3
  double z; // fp7
  double v7; // fp30
  double v8; // fp28
  double y; // fp31
  double v10; // fp29
  double v17; // fp1
  double v18; // fp13
  double v19; // fp11
  double v20; // fp5
  double v21; // fp4
  double v22; // fp2
  double v23; // fp12
  double v24; // fp11
  double v25; // fp6
  double v26; // fp0
  double v27; // fp13
  double v28; // fp12
  double v29; // fp10
  idRenderMatrix v30; // [sp+50h] [-80h] BYREF

  x = lightRight->x;
  v5 = lightUp->x;
  z = lightTarget->z;
  v7 = lightRight->z;
  v8 = lightUp->z;
  y = lightRight->y;
  v10 = lightUp->y;
  _FP1 = (float)((float)((float)(lightTarget->z * lightTarget->z)
                       + (float)((float)(lightTarget->x * lightTarget->x) + (float)(lightTarget->y * lightTarget->y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  _FP11 = (float)((float)((float)(lightRight->z * lightRight->z)
                        + (float)((float)(lightRight->x * lightRight->x) + (float)(lightRight->y * lightRight->y)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  _FP26 = (float)((float)((float)(lightUp->z * lightUp->z)
                        + (float)((float)(lightUp->x * lightUp->x) + (float)(lightUp->y * lightUp->y)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm
  {
    fsel      f5, f1, f5, f13
    fsel      f4, f11, f4, f13
    fsel      f2, f26, f2, f13
  }
  v17 = __frsqrte(_FP5);
  v18 = __frsqrte(_FP4);
  v19 = __frsqrte(_FP2);
  v20 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                      * (float)((float)((float)(lightTarget->z * lightTarget->z) + (float)((float)(lightTarget->x * lightTarget->x) + (float)(lightTarget->y * lightTarget->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v17)
                                                                      - (float)1.5)
                                                      * (float)v17)
                                              * (float)((float)((float)(lightTarget->z * lightTarget->z)
                                                              + (float)((float)(lightTarget->x * lightTarget->x)
                                                                      + (float)(lightTarget->y * lightTarget->y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v17
                                                                              * (float)((float)((float)(lightTarget->z * lightTarget->z)
                                                                                              + (float)((float)(lightTarget->x * lightTarget->x) + (float)(lightTarget->y * lightTarget->y)))
                                                                                      * (float)0.5))
                                                                      * (float)v17)
                                                              - (float)1.5)
                                              * (float)v17))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v17
                                                      * (float)((float)((float)(lightTarget->z * lightTarget->z)
                                                                      + (float)((float)(lightTarget->x * lightTarget->x)
                                                                              + (float)(lightTarget->y * lightTarget->y)))
                                                              * (float)0.5))
                                              * (float)v17)
                                      - (float)1.5)
                      * (float)v17));
  v21 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18
                                                                                      * (float)((float)((float)(lightRight->z * lightRight->z) + (float)((float)(lightRight->x * lightRight->x) + (float)(lightRight->y * lightRight->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v18)
                                                                      - (float)1.5)
                                                      * (float)v18)
                                              * (float)((float)((float)(lightRight->z * lightRight->z)
                                                              + (float)((float)(lightRight->x * lightRight->x)
                                                                      + (float)(lightRight->y * lightRight->y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v18
                                                                              * (float)((float)((float)(lightRight->z * lightRight->z)
                                                                                              + (float)((float)(lightRight->x * lightRight->x) + (float)(lightRight->y * lightRight->y)))
                                                                                      * (float)0.5))
                                                                      * (float)v18)
                                                              - (float)1.5)
                                              * (float)v18))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v18
                                                      * (float)((float)((float)(lightRight->z * lightRight->z)
                                                                      + (float)((float)(lightRight->x * lightRight->x)
                                                                              + (float)(lightRight->y * lightRight->y)))
                                                              * (float)0.5))
                                              * (float)v18)
                                      - (float)1.5)
                      * (float)v18));
  v22 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                      * (float)((float)((float)(lightUp->z * lightUp->z) + (float)((float)(lightUp->x * lightUp->x) + (float)(lightUp->y * lightUp->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v19)
                                                                      - (float)1.5)
                                                      * (float)v19)
                                              * (float)((float)((float)(lightUp->z * lightUp->z)
                                                              + (float)((float)(lightUp->x * lightUp->x)
                                                                      + (float)(lightUp->y * lightUp->y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v19
                                                                              * (float)((float)((float)(lightUp->z * lightUp->z)
                                                                                              + (float)((float)(lightUp->x * lightUp->x) + (float)(lightUp->y * lightUp->y)))
                                                                                      * (float)0.5))
                                                                      * (float)v19)
                                                              - (float)1.5)
                                              * (float)v19))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v19
                                                      * (float)((float)((float)(lightUp->z * lightUp->z)
                                                                      + (float)((float)(lightUp->x * lightUp->x)
                                                                              + (float)(lightUp->y * lightUp->y)))
                                                              * (float)0.5))
                                              * (float)v19)
                                      - (float)1.5)
                      * (float)v19));
  v23 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                              * (float)((float)((float)(lightUp->z * lightUp->z) + (float)((float)(lightUp->x * lightUp->x) + (float)(lightUp->y * lightUp->y))) * (float)0.5))
                                                                                      * (float)v19)
                                                                              - (float)1.5)
                                                              * (float)v19)
                                                      * (float)((float)((float)(lightUp->z * lightUp->z)
                                                                      + (float)((float)(lightUp->x * lightUp->x)
                                                                              + (float)(lightUp->y * lightUp->y)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v19
                                                                                      * (float)((float)((float)(lightUp->z * lightUp->z) + (float)((float)(lightUp->x * lightUp->x) + (float)(lightUp->y * lightUp->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v19)
                                                                      - (float)1.5)
                                                      * (float)v19))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v19
                                                              * (float)((float)((float)(lightUp->z * lightUp->z)
                                                                              + (float)((float)(lightUp->x * lightUp->x)
                                                                                      + (float)(lightUp->y * lightUp->y)))
                                                                      * (float)0.5))
                                                      * (float)v19)
                                              - (float)1.5)
                              * (float)v19))
              * (float)((float)((float)(lightUp->z * lightUp->z)
                              + (float)((float)(lightUp->x * lightUp->x) + (float)(lightUp->y * lightUp->y)))
                      * (float)0.5));
  v24 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)((float)((float)(lightTarget->z * lightTarget->z) + (float)((float)(lightTarget->x * lightTarget->x) + (float)(lightTarget->y * lightTarget->y))) * (float)0.5)) * (float)v17) - (float)1.5)
                                                                                      * (float)v17)
                                                                              * (float)((float)((float)(lightTarget->z * lightTarget->z)
                                                                                              + (float)((float)(lightTarget->x * lightTarget->x) + (float)(lightTarget->y * lightTarget->y)))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)((float)(lightTarget->z * lightTarget->z) + (float)((float)(lightTarget->x * lightTarget->x) + (float)(lightTarget->y * lightTarget->y))) * (float)0.5)) * (float)v17)
                                                                                              - (float)1.5)
                                                                              * (float)v17))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v17
                                                                                      * (float)((float)((float)(lightTarget->z * lightTarget->z) + (float)((float)(lightTarget->x * lightTarget->x) + (float)(lightTarget->y * lightTarget->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v17)
                                                                      - (float)1.5)
                                                      * (float)v17))
                                      * (float)((float)((float)(lightTarget->z * lightTarget->z)
                                                      + (float)((float)(lightTarget->x * lightTarget->x)
                                                              + (float)(lightTarget->y * lightTarget->y)))
                                              * (float)0.5))
                              * (float)v20)
                      - (float)1.5);
  v25 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(lightRight->z * lightRight->z) + (float)((float)(lightRight->x * lightRight->x) + (float)(lightRight->y * lightRight->y))) * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                      * (float)v18)
                                                                              * (float)((float)((float)(lightRight->z * lightRight->z)
                                                                                              + (float)((float)(lightRight->x * lightRight->x) + (float)(lightRight->y * lightRight->y)))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(lightRight->z * lightRight->z) + (float)((float)(lightRight->x * lightRight->x) + (float)(lightRight->y * lightRight->y))) * (float)0.5)) * (float)v18)
                                                                                              - (float)1.5)
                                                                              * (float)v18))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v18
                                                                                      * (float)((float)((float)(lightRight->z * lightRight->z) + (float)((float)(lightRight->x * lightRight->x) + (float)(lightRight->y * lightRight->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v18)
                                                                      - (float)1.5)
                                                      * (float)v18))
                                      * (float)((float)((float)(lightRight->z * lightRight->z)
                                                      + (float)((float)(lightRight->x * lightRight->x)
                                                              + (float)(lightRight->y * lightRight->y)))
                                              * (float)0.5))
                              * (float)v21)
                      - (float)1.5);
  v26 = (float)((float)v24
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                              * (float)((float)((float)(lightTarget->z * lightTarget->z) + (float)((float)(lightTarget->x * lightTarget->x) + (float)(lightTarget->y * lightTarget->y))) * (float)0.5))
                                                                                      * (float)v17)
                                                                              - (float)1.5)
                                                              * (float)v17)
                                                      * (float)((float)((float)(lightTarget->z * lightTarget->z)
                                                                      + (float)((float)(lightTarget->x * lightTarget->x)
                                                                              + (float)(lightTarget->y * lightTarget->y)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v17
                                                                                      * (float)((float)((float)(lightTarget->z * lightTarget->z) + (float)((float)(lightTarget->x * lightTarget->x) + (float)(lightTarget->y * lightTarget->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v17)
                                                                      - (float)1.5)
                                                      * (float)v17))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v17
                                                              * (float)((float)((float)(lightTarget->z * lightTarget->z)
                                                                              + (float)((float)(lightTarget->x
                                                                                              * lightTarget->x)
                                                                                      + (float)(lightTarget->y
                                                                                              * lightTarget->y)))
                                                                      * (float)0.5))
                                                      * (float)v17)
                                              - (float)1.5)
                              * (float)v17)));
  v27 = (float)((float)v25
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18
                                                                                              * (float)((float)((float)(lightRight->z * lightRight->z) + (float)((float)(lightRight->x * lightRight->x) + (float)(lightRight->y * lightRight->y))) * (float)0.5))
                                                                                      * (float)v18)
                                                                              - (float)1.5)
                                                              * (float)v18)
                                                      * (float)((float)((float)(lightRight->z * lightRight->z)
                                                                      + (float)((float)(lightRight->x * lightRight->x)
                                                                              + (float)(lightRight->y * lightRight->y)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v18
                                                                                      * (float)((float)((float)(lightRight->z * lightRight->z) + (float)((float)(lightRight->x * lightRight->x) + (float)(lightRight->y * lightRight->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v18)
                                                                      - (float)1.5)
                                                      * (float)v18))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v18
                                                              * (float)((float)((float)(lightRight->z * lightRight->z)
                                                                              + (float)((float)(lightRight->x
                                                                                              * lightRight->x)
                                                                                      + (float)(lightRight->y
                                                                                              * lightRight->y)))
                                                                      * (float)0.5))
                                                      * (float)v18)
                                              - (float)1.5)
                              * (float)v18)));
  v28 = (float)((float)-(float)((float)((float)v23 * (float)v22) - (float)1.5) * (float)v22);
  v29 = (float)((float)((float)v24
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)((float)((float)(lightTarget->z * lightTarget->z) + (float)((float)(lightTarget->x * lightTarget->x) + (float)(lightTarget->y * lightTarget->y))) * (float)0.5))
                                                                                              * (float)v17)
                                                                                      - (float)1.5)
                                                                      * (float)v17)
                                                              * (float)((float)((float)(lightTarget->z * lightTarget->z)
                                                                              + (float)((float)(lightTarget->x
                                                                                              * lightTarget->x)
                                                                                      + (float)(lightTarget->y
                                                                                              * lightTarget->y)))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v17
                                                                                              * (float)((float)((float)(lightTarget->z * lightTarget->z) + (float)((float)(lightTarget->x * lightTarget->x) + (float)(lightTarget->y * lightTarget->y))) * (float)0.5))
                                                                                      * (float)v17)
                                                                              - (float)1.5)
                                                              * (float)v17))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v17
                                                                      * (float)((float)((float)(lightTarget->z
                                                                                              * lightTarget->z)
                                                                                      + (float)((float)(lightTarget->x * lightTarget->x)
                                                                                              + (float)(lightTarget->y * lightTarget->y)))
                                                                              * (float)0.5))
                                                              * (float)v17)
                                                      - (float)1.5)
                                      * (float)v17)))
              * lightTarget->y);
  v30.m[0] = lightTarget->x
           * (float)((float)v24
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)((float)((float)(lightTarget->z * lightTarget->z) + (float)((float)(lightTarget->x * lightTarget->x) + (float)(lightTarget->y * lightTarget->y))) * (float)0.5))
                                                                                           * (float)v17)
                                                                                   - (float)1.5)
                                                                   * (float)v17)
                                                           * (float)((float)((float)(lightTarget->z * lightTarget->z)
                                                                           + (float)((float)(lightTarget->x
                                                                                           * lightTarget->x)
                                                                                   + (float)(lightTarget->y
                                                                                           * lightTarget->y)))
                                                                   * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)((float)v17
                                                                                           * (float)((float)((float)(lightTarget->z * lightTarget->z) + (float)((float)(lightTarget->x * lightTarget->x) + (float)(lightTarget->y * lightTarget->y))) * (float)0.5))
                                                                                   * (float)v17)
                                                                           - (float)1.5)
                                                           * (float)v17))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)((float)v17
                                                                   * (float)((float)((float)(lightTarget->z
                                                                                           * lightTarget->z)
                                                                                   + (float)((float)(lightTarget->x * lightTarget->x)
                                                                                           + (float)(lightTarget->y * lightTarget->y)))
                                                                           * (float)0.5))
                                                           * (float)v17)
                                                   - (float)1.5)
                                   * (float)v17)));
  v30.m[1] = v29;
  v30.m[2] = (float)v26 * (float)z;
  v30.m[4] = -(float)((float)x * (float)v27);
  v30.m[5] = -(float)((float)y * (float)v27);
  v30.m[3] = 0.0;
  v30.m[6] = -(float)((float)v7 * (float)v27);
  v30.m[7] = 0.0;
  v30.m[11] = 0.0;
  v30.m[12] = 0.0;
  v30.m[13] = 0.0;
  v30.m[14] = 0.0;
  v30.m[15] = 1.0;
  v30.m[8] = (float)v5 * (float)v28;
  v30.m[9] = (float)v10 * (float)v28;
  v30.m[10] = (float)v8 * (float)v28;
  idRenderMatrix::Multiply(a: &renderMatrix_flipToOpenGL, b: &v30, out: lightViewMatrix);
}


// ========================================================================
// ?GetParallelLightViewMatrix@@YAXABVidVec3@@AAVidRenderMatrix@@@Z
// EA  : 0x828E2098
// RVA : 0x008E2098
// PDB : w:\tech5\engine\renderer\jobs\render\rendershadowbuffer.cpp
// ========================================================================

void __fastcall GetParallelLightViewMatrix(const idVec3 *direction, idRenderMatrix *lightViewMatrix)
{
  double v2; // fp5
  double v3; // fp4
  double v6; // fp11
  double v7; // fp1
  double v8; // fp6
  double v9; // fp11
  double v10; // fp9
  double v11; // fp12
  double v12; // fp10
  double v13; // fp1
  double v14; // fp0
  double v15; // fp10
  double v16; // fp7
  double v19; // fp6
  double v20; // fp5
  idRenderMatrix v21; // [sp+50h] [-50h] BYREF

  v2 = 0.0;
  v3 = -1.0;
  _FP11 = (float)((float)((float)(direction->x * direction->x)
                        + (float)((float)(direction->z * direction->z) + (float)(direction->y * direction->y)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f1, f11, f1, f8 }
  v6 = __frsqrte(_FP1);
  v7 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6
                                                                                     * (float)((float)((float)(direction->x * direction->x) + (float)((float)(direction->z * direction->z) + (float)(direction->y * direction->y)))
                                                                                             * (float)0.5))
                                                                             * (float)v6)
                                                                     - (float)1.5)
                                                     * (float)v6)
                                             * (float)((float)((float)(direction->x * direction->x)
                                                             + (float)((float)(direction->z * direction->z)
                                                                     + (float)(direction->y * direction->y)))
                                                     * (float)0.5))
                                     * (float)((float)-(float)((float)((float)((float)v6
                                                                             * (float)((float)((float)(direction->x * direction->x)
                                                                                             + (float)((float)(direction->z * direction->z) + (float)(direction->y * direction->y)))
                                                                                     * (float)0.5))
                                                                     * (float)v6)
                                                             - (float)1.5)
                                             * (float)v6))
                             - (float)1.5)
             * (float)((float)-(float)((float)((float)((float)v6
                                                     * (float)((float)((float)(direction->x * direction->x)
                                                                     + (float)((float)(direction->z * direction->z)
                                                                             + (float)(direction->y * direction->y)))
                                                             * (float)0.5))
                                             * (float)v6)
                                     - (float)1.5)
                     * (float)v6));
  v8 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6 * (float)((float)((float)(direction->x * direction->x) + (float)((float)(direction->z * direction->z) + (float)(direction->y * direction->y))) * (float)0.5)) * (float)v6) - (float)1.5)
                                                                                     * (float)v6)
                                                                             * (float)((float)((float)(direction->x * direction->x)
                                                                                             + (float)((float)(direction->z * direction->z) + (float)(direction->y * direction->y)))
                                                                                     * (float)0.5))
                                                                     * (float)((float)-(float)((float)((float)((float)v6 * (float)((float)((float)(direction->x * direction->x) + (float)((float)(direction->z * direction->z) + (float)(direction->y * direction->y))) * (float)0.5)) * (float)v6)
                                                                                             - (float)1.5)
                                                                             * (float)v6))
                                                             - (float)1.5)
                                             * (float)((float)-(float)((float)((float)((float)v6
                                                                                     * (float)((float)((float)(direction->x * direction->x) + (float)((float)(direction->z * direction->z) + (float)(direction->y * direction->y)))
                                                                                             * (float)0.5))
                                                                             * (float)v6)
                                                                     - (float)1.5)
                                                     * (float)v6))
                                     * (float)((float)((float)(direction->x * direction->x)
                                                     + (float)((float)(direction->z * direction->z)
                                                             + (float)(direction->y * direction->y)))
                                             * (float)0.5))
                             * (float)v7)
                     - (float)1.5);
  v10 = (float)(direction->x
              * (float)((float)v8
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6 * (float)((float)((float)(direction->x * direction->x) + (float)((float)(direction->z * direction->z) + (float)(direction->y * direction->y))) * (float)0.5))
                                                                                              * (float)v6)
                                                                                      - (float)1.5)
                                                                      * (float)v6)
                                                              * (float)((float)((float)(direction->x * direction->x)
                                                                              + (float)((float)(direction->z
                                                                                              * direction->z)
                                                                                      + (float)(direction->y
                                                                                              * direction->y)))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v6
                                                                                              * (float)((float)((float)(direction->x * direction->x) + (float)((float)(direction->z * direction->z) + (float)(direction->y * direction->y))) * (float)0.5))
                                                                                      * (float)v6)
                                                                              - (float)1.5)
                                                              * (float)v6))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v6
                                                                      * (float)((float)((float)(direction->x
                                                                                              * direction->x)
                                                                                      + (float)((float)(direction->z * direction->z)
                                                                                              + (float)(direction->y * direction->y)))
                                                                              * (float)0.5))
                                                              * (float)v6)
                                                      - (float)1.5)
                                      * (float)v6))));
  v11 = (float)(direction->y
              * (float)((float)v8
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6 * (float)((float)((float)(direction->x * direction->x) + (float)((float)(direction->z * direction->z) + (float)(direction->y * direction->y))) * (float)0.5))
                                                                                              * (float)v6)
                                                                                      - (float)1.5)
                                                                      * (float)v6)
                                                              * (float)((float)((float)(direction->x * direction->x)
                                                                              + (float)((float)(direction->z
                                                                                              * direction->z)
                                                                                      + (float)(direction->y
                                                                                              * direction->y)))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v6
                                                                                              * (float)((float)((float)(direction->x * direction->x) + (float)((float)(direction->z * direction->z) + (float)(direction->y * direction->y))) * (float)0.5))
                                                                                      * (float)v6)
                                                                              - (float)1.5)
                                                              * (float)v6))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v6
                                                                      * (float)((float)((float)(direction->x
                                                                                              * direction->x)
                                                                                      + (float)((float)(direction->z * direction->z)
                                                                                              + (float)(direction->y * direction->y)))
                                                                              * (float)0.5))
                                                              * (float)v6)
                                                      - (float)1.5)
                                      * (float)v6))));
  v9 = (float)(direction->z
             * (float)((float)v8
                     * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6 * (float)((float)((float)(direction->x * direction->x) + (float)((float)(direction->z * direction->z) + (float)(direction->y * direction->y))) * (float)0.5))
                                                                                             * (float)v6)
                                                                                     - (float)1.5)
                                                                     * (float)v6)
                                                             * (float)((float)((float)(direction->x * direction->x)
                                                                             + (float)((float)(direction->z
                                                                                             * direction->z)
                                                                                     + (float)(direction->y
                                                                                             * direction->y)))
                                                                     * (float)0.5))
                                                     * (float)((float)-(float)((float)((float)((float)v6
                                                                                             * (float)((float)((float)(direction->x * direction->x) + (float)((float)(direction->z * direction->z) + (float)(direction->y * direction->y))) * (float)0.5))
                                                                                     * (float)v6)
                                                                             - (float)1.5)
                                                             * (float)v6))
                                             - (float)1.5)
                             * (float)((float)-(float)((float)((float)((float)v6
                                                                     * (float)((float)((float)(direction->x
                                                                                             * direction->x)
                                                                                     + (float)((float)(direction->z * direction->z)
                                                                                             + (float)(direction->y * direction->y)))
                                                                             * (float)0.5))
                                                             * (float)v6)
                                                     - (float)1.5)
                                     * (float)v6))));
  v12 = (float)((float)((float)((float)v11 * (float)0.0) - (float)v9) + (float)((float)v10 * (float)0.0));
  if ( __fabs(v12) > 0.99000001 )
  {
    v2 = 1.0;
    v3 = 1.0;
    v12 = (float)((float)((float)((float)v10 * (float)0.0) + (float)v9) + (float)v11);
  }
  v21.m[3] = 0.0;
  v21.m[7] = 0.0;
  v21.m[11] = 0.0;
  v13 = (float)((float)v10 * (float)v12);
  v21.m[12] = 0.0;
  v21.m[13] = 0.0;
  v21.m[14] = 0.0;
  v21.m[15] = 1.0;
  v21.m[0] = v10;
  v21.m[1] = v11;
  v21.m[2] = v9;
  v14 = (float)((float)v2 - (float)((float)v11 * (float)v12));
  v15 = (float)((float)v3 - (float)((float)v9 * (float)v12));
  v16 = -v13;
  _FP2 = (float)((float)((float)((float)v16 * (float)v16)
                       + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f8, f2, f4, f8 }
  v19 = __frsqrte(_FP8);
  v20 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                      * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14)))
                                                                                              * (float)0.5))
                                                                              * (float)v19)
                                                                      - (float)1.5)
                                                      * (float)v19)
                                              * (float)((float)((float)((float)v16 * (float)v16)
                                                              + (float)((float)((float)v15 * (float)v15)
                                                                      + (float)((float)v14 * (float)v14)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v19
                                                                              * (float)((float)((float)((float)v16 * (float)v16)
                                                                                              + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14)))
                                                                                      * (float)0.5))
                                                                      * (float)v19)
                                                              - (float)1.5)
                                              * (float)v19))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v19
                                                      * (float)((float)((float)((float)v16 * (float)v16)
                                                                      + (float)((float)((float)v15 * (float)v15)
                                                                              + (float)((float)v14 * (float)v14)))
                                                              * (float)0.5))
                                              * (float)v19)
                                      - (float)1.5)
                      * (float)v19));
  v21.m[8] = (float)-v13
           * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) * (float)0.5)) * (float)v19) - (float)1.5) * (float)v19)
                                                                                           * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) * (float)0.5))
                                                                                   * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) * (float)0.5)) * (float)v19) - (float)1.5)
                                                                                           * (float)v19))
                                                                           - (float)1.5)
                                                           * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) * (float)0.5))
                                                                                           * (float)v19)
                                                                                   - (float)1.5)
                                                                   * (float)v19))
                                                   * (float)((float)((float)((float)v16 * (float)v16)
                                                                   + (float)((float)((float)v15 * (float)v15)
                                                                           + (float)((float)v14 * (float)v14)))
                                                           * (float)0.5))
                                           * (float)v20)
                                   - (float)1.5)
                   * (float)v20);
  v21.m[10] = (float)v15
            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) * (float)0.5)) * (float)v19) - (float)1.5) * (float)v19)
                                                                                            * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) * (float)0.5)) * (float)v19) - (float)1.5)
                                                                                            * (float)v19))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) * (float)0.5))
                                                                                            * (float)v19)
                                                                                    - (float)1.5)
                                                                    * (float)v19))
                                                    * (float)((float)((float)((float)v16 * (float)v16)
                                                                    + (float)((float)((float)v15 * (float)v15)
                                                                            + (float)((float)v14 * (float)v14)))
                                                            * (float)0.5))
                                            * (float)v20)
                                    - (float)1.5)
                    * (float)v20);
  v21.m[9] = (float)v14
           * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) * (float)0.5)) * (float)v19) - (float)1.5) * (float)v19)
                                                                                           * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) * (float)0.5))
                                                                                   * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) * (float)0.5)) * (float)v19) - (float)1.5)
                                                                                           * (float)v19))
                                                                           - (float)1.5)
                                                           * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) * (float)0.5))
                                                                                           * (float)v19)
                                                                                   - (float)1.5)
                                                                   * (float)v19))
                                                   * (float)((float)((float)((float)v16 * (float)v16)
                                                                   + (float)((float)((float)v15 * (float)v15)
                                                                           + (float)((float)v14 * (float)v14)))
                                                           * (float)0.5))
                                           * (float)v20)
                                   - (float)1.5)
                   * (float)v20);
  v21.m[5] = (float)((float)v10 * v21.m[10]) - (float)((float)v9 * v21.m[8]);
  v21.m[4] = (float)((float)v9 * v21.m[9]) - (float)((float)v11 * v21.m[10]);
  v21.m[6] = (float)((float)v11 * v21.m[8]) - (float)((float)v10 * v21.m[9]);
  idRenderMatrix::Multiply(a: &renderMatrix_flipToOpenGL, b: &v21, out: lightViewMatrix);
}


// ========================================================================
// ?GetPointShadowProjectionMatrix@@YAXMMAAVidRenderMatrix@@@Z
// EA  : 0x828E2248
// RVA : 0x008E2248
// PDB : w:\tech5\engine\renderer\jobs\render\rendershadowbuffer.cpp
// ========================================================================

void __fastcall GetPointShadowProjectionMatrix(long double zFar, idRenderMatrix *projectionMatrix, int a3, float *a4)
{
  double v4; // fp31
  double v5; // fp30
  long double v7; // fp2

  v4 = *(double *)&zFar;
  v5 = *((double *)&zFar + 1);
  *(double *)&zFar = (float)((float)3.1415927 * (float)0.25833333);
  v7 = tan(x: zFar);
  a4[1] = 0.0;
  a4[2] = 0.0;
  a4[3] = 0.0;
  a4[4] = 0.0;
  a4[6] = 0.0;
  a4[7] = 0.0;
  a4[8] = 0.0;
  a4[9] = 0.0;
  a4[12] = 0.0;
  a4[13] = 0.0;
  a4[15] = 0.0;
  a4[14] = -1.0;
  a4[10] = -(float)((float)v5 / (float)((float)v5 - (float)v4));
  a4[11] = -(float)((float)((float)v4 * (float)v5) / (float)((float)v5 - (float)v4));
  *a4 = (float)((float)v4
              / (float)((float)((float)*(double *)&v7 * (float)v4) - (float)-(float)((float)*(double *)&v7 * (float)v4)))
      * (float)2.0;
  a4[5] = (float)((float)v4
                / (float)((float)((float)*(double *)&v7 * (float)v4) - (float)-(float)((float)*(double *)&v7 * (float)v4)))
        * (float)2.0;
}


// ========================================================================
// SetupShadowBufferMatrices
// EA  : 0x828E2338
// RVA : 0x008E2338
// PDB : w:\tech5\engine\renderer\jobs\render\rendershadowbuffer.cpp
// ========================================================================

int __fastcall SetupShadowBufferMatrices(
        const idRenderLightParms *lightParms,
        const idBounds *lightOrigin,
        const idBounds *lightBounds,
        const idVec3 *viewOrigin,
        idRenderMatrix *options,
        idRenderMatrix *shadowViewProjection,
        lightShadow_t *lightShadow)
{
  lightType_t lightType; // r11
  idRenderMatrix *v12; // r30
  float x; // r24
  __int64 v15; // r8
  lightType_t v16; // r11
  double v17; // fp31
  double v18; // fp12
  double v19; // fp11
  double v20; // fp10
  double v21; // fp6
  double v22; // fp7
  double v23; // fp4
  double v24; // fp5
  double v25; // fp30
  double v26; // fp3
  double v27; // fp2
  double v28; // fp9
  double v29; // fp29
  double v30; // fp20
  double v31; // fp28
  double v32; // fp27
  double v33; // fp26
  double v34; // fp21
  double v35; // fp7
  double v36; // fp24
  double v37; // fp23
  double v39; // fp22
  double v40; // fp4
  double v41; // fp3
  double v42; // fp2
  double v43; // fp19
  double v44; // fp18
  double v45; // fp16
  double v47; // fp13
  double v48; // fp13
  double v49; // fp10
  double v50; // fp30
  double v51; // fp9
  double v56; // fp0
  double v57; // fp13
  double v58; // fp13
  double v59; // fp12
  double v60; // fp11
  double v61; // fp10
  double v62; // fp9
  double v63; // fp8
  double v64; // fp7
  double v65; // fp6
  double v66; // fp5
  double v67; // fp4
  double v68; // fp3
  double v69; // fp1
  double v70; // fp11
  long double v71; // fp2
  long double v72; // fp4
  long double v73; // fp2
  __int64 v74; // r8
  double v75; // fp28
  double v76; // fp27
  long double v77; // fp2
  long double v78; // fp2
  long double v79; // fp2
  __int64 v80; // r11
  double v81; // fp6
  double v82; // fp5
  int v83; // r28
  idRenderMatrix *v84; // r27
  double v85; // fp28
  long double v86; // fp4
  double v87; // fp26
  long double v88; // fp2
  long double v89; // fp2
  double v90; // fp11
  __int64 v91; // r10
  lightType_t v92; // r11
  double v93; // fp13
  double v95; // fp13
  double v96; // fp29
  double v97; // fp13
  double v98; // fp13
  double v99; // fp13
  double v100; // fp12
  double y; // fp11
  double v102; // fp10
  double v103; // fp9
  double v104; // fp8
  double v105; // fp7
  double z; // fp6
  double v107; // fp5
  double v108; // fp4
  double v109; // fp3
  double v110; // fp2
  double v111; // fp1
  double v112; // fp11
  long double v113; // fp2
  int v114; // r4
  idRenderMatrix *v115; // r3
  __int64 v116; // r10
  int v117; // r7
  int v118; // r6
  int v119; // r5
  signed int i; // r31
  double v121; // fp13
  double v122; // fp4
  double v123; // fp9
  double v124; // fp6
  double v125; // fp1
  double v126; // fp2
  double v127; // fp12
  double v128; // fp11
  double v129; // fp10
  double v130; // fp5
  double v131; // fp7
  double v132; // fp3
  double v133; // fp0
  double v134; // fp31
  double v135; // fp30
  idVec3 v136; // [sp+50h] [-540h] BYREF
  float v137; // [sp+5Ch] [-534h] BYREF
  float v138[4]; // [sp+60h] [-530h] BYREF
  idRenderMatrix v139; // [sp+70h] [-520h] BYREF
  idRenderMatrix v140; // [sp+B0h] [-4E0h] BYREF
  idRenderMatrix v141; // [sp+F0h] [-4A0h] BYREF
  idRenderMatrix v142; // [sp+130h] [-460h] BYREF
  idRenderMatrix v143; // [sp+170h] [-420h] BYREF
  idRenderMatrix v144; // [sp+1B0h] [-3E0h] BYREF
  idRenderMatrix v145; // [sp+1F0h] [-3A0h] BYREF
  idRenderMatrix v146; // [sp+230h] [-360h] BYREF
  idRenderMatrix v147; // [sp+270h] [-320h] BYREF
  idRenderMatrix v148; // [sp+2B0h] [-2E0h] BYREF
  idRenderMatrix v149; // [sp+2F0h] [-2A0h] BYREF
  idRenderMatrix v150; // [sp+330h] [-260h] BYREF
  idRenderMatrix v151; // [sp+370h] [-220h] BYREF
  idRenderMatrix v152; // [sp+3B0h] [-1E0h] BYREF
  idRenderMatrix v153; // [sp+3F0h] [-1A0h] BYREF
  idRenderMatrix v154; // [sp+430h] [-160h] BYREF
  idRenderMatrix v155[3]; // [sp+470h] [-120h] BYREF

  lightType = lightParms->lightType;
  v12 = options;
  if ( lightType == LIGHT_PARALLEL )
  {
    LODWORD(x) = SLODWORD(viewOrigin->x) / 2;
  }
  else if ( lightType == LIGHT_SPOT )
  {
    x = viewOrigin->x;
  }
  else
  {
    LODWORD(x) = SLODWORD(viewOrigin->x) / 3;
  }
  memset(Dst: options, Val: 0, Size: 0x180u);
  memset(Dst: shadowViewProjection, Val: 0, Size: sizeof(idRenderMatrix));
  memset(Dst: &shadowViewProjection[1], Val: 0, Size: sizeof(idRenderMatrix));
  v16 = lightParms->lightType;
  if ( v16 == LIGHT_POINT || v16 == LIGHT_REAL )
  {
    v95 = __fabs(lightParms->lightCenter.x);
    v96 = 16.0;
    if ( (float)((float)v95 + lightParms->lightRadius.x) > 16.0 )
      v96 = (float)((float)v95 + lightParms->lightRadius.x);
    v97 = __fabs(lightParms->lightCenter.y);
    if ( (float)((float)v97 + lightParms->lightRadius.y) > v96 )
      v96 = (float)((float)v97 + lightParms->lightRadius.y);
    v98 = __fabs(lightParms->lightCenter.z);
    if ( (float)((float)v98 + lightParms->lightRadius.z) > v96 )
      v96 = (float)((float)v98 + lightParms->lightRadius.z);
    v99 = lightParms->axis.mat[1].x;
    v100 = lightParms->axis.mat[2].x;
    y = lightParms->axis.mat[0].y;
    v102 = lightParms->axis.mat[1].y;
    v103 = lightParms->origin.x;
    v104 = lightParms->axis.mat[2].y;
    v105 = lightParms->origin.y;
    z = lightParms->axis.mat[0].z;
    v107 = lightParms->axis.mat[1].z;
    v108 = lightParms->axis.mat[2].z;
    v109 = lightParms->origin.z;
    v141.m[0] = lightParms->axis.mat[0].x;
    v141.m[1] = v99;
    v141.m[12] = 0.0;
    v141.m[2] = v100;
    v141.m[13] = 0.0;
    v141.m[4] = y;
    v141.m[14] = 0.0;
    v141.m[5] = v102;
    v141.m[15] = 1.0;
    v141.m[3] = v103;
    v141.m[6] = v104;
    v141.m[7] = v105;
    v141.m[8] = z;
    v141.m[9] = v107;
    v141.m[10] = v108;
    v141.m[11] = v109;
    idRenderMatrix::Inverse(src: &v141, out: &v151);
    v110 = lightParms->lightCenter.x;
    v111 = lightParms->lightCenter.y;
    v112 = -lightParms->lightCenter.z;
    v140.m[0] = 1.0;
    v140.m[1] = 0.0;
    v140.m[2] = 0.0;
    v140.m[4] = 0.0;
    v140.m[5] = 1.0;
    v140.m[6] = 0.0;
    v140.m[8] = 0.0;
    v140.m[9] = 0.0;
    v140.m[10] = 1.0;
    v140.m[12] = 0.0;
    v140.m[13] = 0.0;
    v140.m[14] = 0.0;
    v140.m[15] = 1.0;
    v140.m[3] = -v110;
    v140.m[7] = -v111;
    v140.m[11] = v112;
    idRenderMatrix::Multiply(a: &v140, b: &v151, out: &v147);
    *(double *)&v113 = 8.0;
    *((double *)&v113 + 1) = v96;
    GetPointShadowProjectionMatrix(zFar: v113, projectionMatrix: v115, a3: v114, a4: v139.m);
    for ( i = 0; i < 6; ++i )
    {
      GetPointLightViewMatrix(side: i, lightViewMatrix: &v153, a3: v119, a4: v118, a5: v117, a6: v116);
      idRenderMatrix::Multiply(a: &v153, b: &v147, out: v155);
      idRenderMatrix::Multiply(a: &v139, b: v155, out: v12++);
    }
    shadowViewProjection[1] = v147;
    v121 = (float)(v139.m[4] * (float)0.5);
    v122 = (float)(v139.m[2] * (float)0.5);
    v123 = (float)(v139.m[6] * (float)0.5);
    v124 = (float)(v139.m[1] * (float)0.5);
    v125 = v139.m[8];
    v126 = (float)(v139.m[3] * (float)0.5);
    v127 = v139.m[9];
    v128 = (float)(v139.m[5] * (float)0.5);
    v129 = v139.m[10];
    v130 = (float)(v139.m[7] * (float)0.5);
    v131 = v139.m[11];
    v132 = v139.m[12];
    v133 = v139.m[13];
    v134 = v139.m[14];
    v135 = v139.m[15];
    shadowViewProjection->m[0] = v139.m[0] * (float)0.5;
    shadowViewProjection->m[1] = v124;
    shadowViewProjection->m[2] = v122;
    shadowViewProjection->m[3] = v126;
    shadowViewProjection->m[4] = v121;
    shadowViewProjection->m[5] = v128;
    shadowViewProjection->m[6] = v123;
    shadowViewProjection->m[7] = v130;
    shadowViewProjection->m[8] = v125;
    shadowViewProjection->m[9] = v127;
    shadowViewProjection->m[10] = v129;
    shadowViewProjection->m[11] = v131;
    shadowViewProjection->m[12] = v132;
    shadowViewProjection->m[13] = v133;
    shadowViewProjection->m[14] = v134;
    shadowViewProjection->m[15] = v135;
    return LODWORD(x);
  }
  else
  {
    v17 = 0.0;
    if ( v16 == LIGHT_SPOT )
    {
      v18 = (float)(lightParms->target.y * lightParms->target.y);
      v19 = lightParms->target.x;
      v20 = lightParms->target.z;
      v21 = (float)(lightParms->up.y * lightParms->up.y);
      v143.m[0] = lightParms->axis.mat[0].x;
      v22 = (float)(lightParms->right.y * lightParms->right.y);
      v23 = lightParms->up.x;
      v24 = lightParms->right.x;
      v143.m[15] = 1.0;
      v25 = lightParms->origin.x;
      v143.m[2] = lightParms->axis.mat[2].x;
      v143.m[3] = v25;
      v26 = lightParms->right.z;
      v143.m[1] = lightParms->axis.mat[1].x;
      v27 = lightParms->up.z;
      v143.m[8] = lightParms->axis.mat[0].z;
      v28 = lightParms->target.y;
      v29 = lightParms->axis.mat[0].y;
      v30 = (float)((float)((float)v27 * (float)v27) + (float)((float)((float)v23 * (float)v23) + (float)v21));
      v31 = lightParms->axis.mat[1].y;
      v32 = lightParms->axis.mat[2].y;
      v33 = lightParms->origin.y;
      v34 = (float)((float)((float)v26 * (float)v26) + (float)((float)((float)v24 * (float)v24) + (float)v22));
      v35 = lightParms->target.z;
      v36 = lightParms->axis.mat[1].z;
      v37 = lightParms->axis.mat[2].z;
      _FP17 = (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v19 * (float)v19) + (float)v18))
                    - idMath::FLT_SMALLEST_NON_DENORMAL);
      v39 = lightParms->origin.z;
      v40 = lightParms->start.y;
      v41 = lightParms->end.y;
      v42 = lightParms->start.z;
      v43 = lightParms->end.z;
      v44 = lightParms->start.x;
      v45 = lightParms->end.x;
      v143.m[12] = 0.0;
      v143.m[13] = 0.0;
      v143.m[14] = 0.0;
      __asm { fsel      f1, f17, f1, f13 }
      v143.m[4] = v29;
      v143.m[5] = v31;
      v143.m[6] = v32;
      v143.m[7] = v33;
      v143.m[9] = v36;
      v143.m[10] = v37;
      v143.m[11] = v39;
      v47 = __frsqrte(_FP1);
      v48 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v47
                                                                                          * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v19 * (float)v19) + (float)v18))
                                                                                                  * (float)0.5))
                                                                                  * (float)v47)
                                                                          - (float)1.5)
                                                          * (float)v47)
                                                  * (float)((float)((float)((float)v20 * (float)v20)
                                                                  + (float)((float)((float)v19 * (float)v19) + (float)v18))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v47
                                                                                  * (float)((float)((float)((float)v20 * (float)v20)
                                                                                                  + (float)((float)((float)v19 * (float)v19) + (float)v18))
                                                                                          * (float)0.5))
                                                                          * (float)v47)
                                                                  - (float)1.5)
                                                  * (float)v47))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v47
                                                          * (float)((float)((float)((float)v20 * (float)v20)
                                                                          + (float)((float)((float)v19 * (float)v19)
                                                                                  + (float)v18))
                                                                  * (float)0.5))
                                                  * (float)v47)
                                          - (float)1.5)
                          * (float)v47));
      v49 = (float)-(float)((float)((float)((float)v48
                                          * (float)((float)((float)((float)v20 * (float)v20)
                                                          + (float)((float)((float)v19 * (float)v19) + (float)v18))
                                                  * (float)0.5))
                                  * (float)v48)
                          - (float)1.5);
      v50 = (float)((float)v49 * (float)v48);
      v51 = (float)((float)v28 * (float)((float)v49 * (float)v48));
      _FP12 = (float)((float)((float)((float)((float)v19 * (float)((float)v49 * (float)v48)) * (float)v44)
                            + (float)((float)((float)v42 * (float)((float)v35 * (float)((float)v49 * (float)v48)))
                                    + (float)((float)v40 * (float)v51)))
                    - (float)8.0);
      _FP11 = (float)((float)((float)((float)v45 * (float)((float)v19 * (float)((float)v49 * (float)v48)))
                            + (float)((float)((float)v43 * (float)((float)v35 * (float)((float)v49 * (float)v48)))
                                    + (float)((float)v41 * (float)v51)))
                    - (float)16.0);
      __asm
      {
        fsel      f29, f12, f2, f0
        fsel      f28, f11, f1, f13
      }
      idRenderMatrix::Inverse(src: &v143, out: &v148);
      GetSpotLightViewMatrix(
        lightTarget: &lightParms->target,
        lightRight: &lightParms->right,
        lightUp: &lightParms->up,
        lightViewMatrix: &v150);
      v142.m[1] = 0.0;
      v142.m[2] = 0.0;
      v142.m[3] = 0.0;
      v142.m[4] = 0.0;
      v142.m[6] = 0.0;
      v142.m[14] = -1.0;
      v142.m[7] = 0.0;
      v142.m[8] = 0.0;
      v142.m[9] = 0.0;
      v142.m[12] = 0.0;
      v142.m[13] = 0.0;
      v142.m[15] = 0.0;
      v56 = (float)((float)((float)((float)__fsqrts(v34) * (float)v50) * (float)1.05) * (float)_FP29);
      v57 = (float)((float)((float)((float)__fsqrts(v30) * (float)v50) * (float)1.05) * (float)_FP29);
      v142.m[10] = (float)((float)-1.0 / (float)((float)_FP28 - (float)_FP29)) * (float)_FP28;
      v142.m[11] = -(float)((float)((float)_FP28 * (float)_FP29) / (float)((float)_FP28 - (float)_FP29));
      v142.m[0] = (float)((float)_FP29 / (float)((float)v56 - (float)-v56)) * (float)2.0;
      v142.m[5] = (float)((float)_FP29 / (float)((float)v57 - (float)-v57)) * (float)2.0;
      idRenderMatrix::Multiply(a: &v150, b: &v148, out: &v154);
      idRenderMatrix::Multiply(a: &v142, b: &v154, out: v12);
    }
    else if ( v16 == LIGHT_PARALLEL )
    {
      v58 = lightParms->axis.mat[1].x;
      v59 = lightParms->axis.mat[2].x;
      v60 = lightBounds->b[0].x;
      v61 = lightParms->axis.mat[0].y;
      v62 = lightParms->axis.mat[1].y;
      v63 = lightParms->axis.mat[2].y;
      v64 = lightBounds->b[0].y;
      v65 = lightParms->axis.mat[0].z;
      v66 = lightParms->axis.mat[1].z;
      v67 = lightParms->axis.mat[2].z;
      v68 = lightBounds->b[0].z;
      v145.m[0] = lightParms->axis.mat[0].x;
      v145.m[1] = v58;
      v145.m[2] = v59;
      v145.m[3] = v60;
      v145.m[12] = 0.0;
      v145.m[13] = 0.0;
      v145.m[14] = 0.0;
      v145.m[4] = v61;
      v145.m[15] = 1.0;
      v145.m[5] = v62;
      v145.m[6] = v63;
      v145.m[7] = v64;
      v145.m[8] = v65;
      v145.m[9] = v66;
      v145.m[10] = v67;
      v145.m[11] = v68;
      v69 = lightParms->lightCenter.y;
      v70 = -lightParms->lightCenter.z;
      v136.x = -lightParms->lightCenter.x;
      v136.y = -v69;
      v136.z = v70;
      idRenderMatrix::Inverse(src: &v145, out: &v152);
      GetParallelLightViewMatrix(direction: &v136, lightViewMatrix: &v149);
      idRenderMatrix::Multiply(a: &v149, b: &v152, out: &v146);
      *((_QWORD *)&v71 + 1) = 0x4008000000000000LL;
      *(double *)&v71 = 2.0;
      v73 = pow(x: v71, y: v72);
      *((float *)&v74 + 1) = x;
      v75 = (float)((float)((float)(viewOrigin[1].x * (float)*(double *)&v73) * (float)2.0) / (float)v74);
      v76 = (float)((float)1.0
                  / (float)((float)((float)(viewOrigin[1].x * (float)*(double *)&v73) * (float)2.0) / (float)v74));
      *(double *)&v73 = (float)(v146.m[3]
                              * (float)((float)1.0
                                      / (float)((float)((float)(viewOrigin[1].x * (float)*(double *)&v73) * (float)2.0)
                                              / (float)v74)));
      *(_QWORD *)&v136.x = v74;
      v77 = floor(x: v73);
      *((double *)&v77 + 1) = (float)*(double *)&v77;
      v146.m[3] = (float)*(double *)&v77 * (float)v75;
      *(double *)&v77 = (float)(v146.m[7] * (float)v76);
      v78 = floor(x: v77);
      v146.m[7] = (float)*(double *)&v78 * (float)v75;
      *(double *)&v78 = (float)(v146.m[11] * (float)v76);
      v79 = floor(x: v78);
      v146.m[11] = (float)*(double *)&v79 * (float)v75;
      idRenderMatrix::DepthBoundsForBounds(min: &v137, max: v138, mvp: &v146, b: lightOrigin, zeroToOne: false);
      v81 = -v138[0];
      v82 = -v137;
      v83 = 0;
      v84 = v12;
      v85 = (float)((float)v82 - (float)v81);
      *((double *)&v86 + 1) = (float)((float)-1.0 / (float)((float)v82 - (float)v81));
      v87 = (float)((float)((float)-1.0 / (float)((float)v82 - (float)v81)) * (float)v81);
      do
      {
        LODWORD(v80) = v83;
        *(double *)&v88 = 2.0;
        *(_QWORD *)&v136.x = v80;
        *((double *)&v88 + 1) = (float)v80;
        v89 = pow(x: v88, y: v86);
        v90 = viewOrigin[1].x;
        v144.m[1] = 0.0;
        v144.m[2] = 0.0;
        v144.m[4] = 0.0;
        v144.m[6] = 0.0;
        v144.m[8] = 0.0;
        v144.m[9] = 0.0;
        v144.m[10] = (float)-1.0 / (float)v85;
        v144.m[11] = v87;
        v144.m[12] = 0.0;
        v144.m[13] = 0.0;
        v144.m[14] = 0.0;
        v144.m[15] = 1.0;
        v144.m[0] = (float)2.0
                  / (float)((float)((float)*(double *)&v89 * (float)v90)
                          - (float)-(float)((float)*(double *)&v89 * (float)v90));
        v144.m[5] = (float)2.0
                  / (float)((float)-(float)((float)*(double *)&v89 * (float)v90)
                          - (float)((float)*(double *)&v89 * (float)v90));
        v144.m[3] = -(float)((float)((float)-(float)((float)*(double *)&v89 * (float)v90)
                                   + (float)((float)*(double *)&v89 * (float)v90))
                           / (float)((float)((float)*(double *)&v89 * (float)v90)
                                   - (float)-(float)((float)*(double *)&v89 * (float)v90)));
        v144.m[7] = -(float)((float)((float)-(float)((float)*(double *)&v89 * (float)v90)
                                   + (float)((float)*(double *)&v89 * (float)v90))
                           / (float)((float)-(float)((float)*(double *)&v89 * (float)v90)
                                   - (float)((float)*(double *)&v89 * (float)v90)));
        idRenderMatrix::Multiply(a: &v144, b: &v146, out: v84);
        ++v83;
        ++v84;
      }
      while ( v83 < 4 );
    }
    *((float *)&v91 + 1) = x;
    *(float *)&v91 = viewOrigin->x;
    v92 = lightParms->lightType;
    LODWORD(v15) = LODWORD(viewOrigin->x);
    *(_QWORD *)&v136.x = v15;
    if ( v92 == LIGHT_PARALLEL )
      v93 = 0.0;
    else
      v93 = (float)((float)((float)v91 * (float)0.5) / (float)v15);
    if ( v92 != LIGHT_PARALLEL )
      v17 = (float)((float)((float)v91 * (float)0.5) / (float)v15);
    shadowViewProjection[1].m[0] = (float)(v12->m[12] * (float)v93)
                                 + (float)(v12->m[0] * (float)((float)((float)v91 * (float)0.5) / (float)v15));
    shadowViewProjection[1].m[1] = (float)(v12->m[1] * (float)((float)((float)v91 * (float)0.5) / (float)v15))
                                 + (float)(v12->m[13] * (float)v93);
    shadowViewProjection[1].m[2] = (float)(v12->m[2] * (float)((float)((float)v91 * (float)0.5) / (float)v15))
                                 + (float)(v12->m[14] * (float)v93);
    shadowViewProjection[1].m[3] = (float)(v12->m[3] * (float)((float)((float)v91 * (float)0.5) / (float)v15))
                                 + (float)((float)v93 * v12->m[15]);
    shadowViewProjection[1].m[4] = (float)(v12->m[4] * (float)((float)((float)v91 * (float)0.5) / (float)v15))
                                 + (float)(v12->m[12] * (float)v17);
    shadowViewProjection[1].m[5] = (float)(v12->m[5] * (float)((float)((float)v91 * (float)0.5) / (float)v15))
                                 + (float)(v12->m[13] * (float)v17);
    shadowViewProjection[1].m[6] = (float)(v12->m[6] * (float)((float)((float)v91 * (float)0.5) / (float)v15))
                                 + (float)(v12->m[14] * (float)v17);
    shadowViewProjection[1].m[7] = (float)(v12->m[7] * (float)((float)((float)v91 * (float)0.5) / (float)v15))
                                 + (float)((float)v17 * v12->m[15]);
    shadowViewProjection[1].m[8] = v12->m[8];
    shadowViewProjection[1].m[9] = v12->m[9];
    shadowViewProjection[1].m[10] = v12->m[10];
    shadowViewProjection[1].m[11] = v12->m[11];
    shadowViewProjection[1].m[12] = v12->m[12];
    shadowViewProjection[1].m[13] = v12->m[13];
    shadowViewProjection[1].m[14] = v12->m[14];
    shadowViewProjection[1].m[15] = v12->m[15];
    return LODWORD(x);
  }
}


// ========================================================================
// ShadowCasterSort
// EA  : 0x828E2C88
// RVA : 0x008E2C88
// PDB : w:\tech5\engine\renderer\jobs\render\rendershadowbuffer.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall ShadowCasterSort(shadowCaster_t *casters, float *distances, __int64 num)
{
  int v3; // r30 OVERLAPPED
  unsigned __int64 v4; // r11
  __int64 v5; // r29
  int v6; // r31 OVERLAPPED
  __int64 v7; // r8
  int v8; // r9
  __int128 v9; // r11
  __int64 v10; // r10
  double v11; // fp0
  int v12; // r5
  float *i; // r6
  int v14; // r11
  shadowCaster_t *v15; // r11
  const idRenderModelCommitted *v16; // r5
  const idBounds *v17; // r27
  const idRenderModelSurface *v18; // r26
  double v19; // fp13
  int v20; // r8
  int v21; // r11
  int v22; // r5
  int v23; // r10
  int v24; // r10
  shadowCaster_t *v25; // r10
  shadowCaster_t *v26; // r11
  int v27; // r8
  double v28; // fp0
  int v29; // r28
  const idRenderModelCommitted *model; // [sp+10h] [-870h]
  const idBounds *bounds; // [sp+14h] [-86Ch]
  const idRenderModelSurface *surfaces; // [sp+18h] [-868h]
  int numSurfaces; // [sp+1Ch] [-864h]
  int v34; // [sp+2Ch] [-854h]
  _QWORD v35[128]; // [sp+30h] [-850h] BYREF
  _QWORD v36[138]; // [sp+430h] [-450h] BYREF

  if ( SHIDWORD(num) > 0 )
  {
    v5 = 0;
    v6 = HIDWORD(num) - 1;
    while ( 1 )
    {
      while ( 1 )
      {
        LODWORD(v7) = v5;
        v8 = v6;
        if ( v6 - (int)v5 < 4 || SHIDWORD(v5) >= 127 )
          break;
        LODWORD(v4) = v6 + v5;
        *(_QWORD *)((char *)&v9 + 4) = v4 >> 63;
        LODWORD(v9) = DWORD2(v9) + v6 + v5;
        v10 = (__int64)v9 >> 1;
        v11 = distances[(_DWORD)v10];
        do
        {
          v12 = v7;
          for ( i = &distances[v7]; *i < v11; i = &distances[v7] )
          {
            LODWORD(v7) = v7 + 1;
            v12 = v7;
          }
          v14 = HIDWORD(v10);
          for ( HIDWORD(v7) = &distances[HIDWORD(v10)]; *(float *)HIDWORD(v7) > v11; HIDWORD(v7) = &distances[HIDWORD(v10)] )
            v14 = --HIDWORD(v10);
          if ( (int)v7 > SHIDWORD(v10) )
            break;
          LODWORD(v10) = &casters[v12];
          LODWORD(v7) = v7 + 1;
          v15 = &casters[v14];
          --HIDWORD(v10);
          v34 = *(_DWORD *)(v10 + 12);
          v16 = *(const idRenderModelCommitted **)v10;
          v17 = *(const idBounds **)(v10 + 4);
          v18 = *(const idRenderModelSurface **)(v10 + 8);
          v3 = v34;
          *(_DWORD *)v10 = v15->model;
          *(_DWORD *)(v10 + 4) = v15->bounds;
          *(_DWORD *)(v10 + 8) = v15->surfaces;
          *(_DWORD *)(v10 + 12) = v15->numSurfaces;
          v15->model = v16;
          v15->bounds = v17;
          v15->surfaces = v18;
          v15->numSurfaces = v34;
          v19 = *i;
          *i = *(float *)HIDWORD(v7);
          *(float *)HIDWORD(v7) = v19;
        }
        while ( (int)v7 < SHIDWORD(v10) );
        for ( ; distances[HIDWORD(v10)] == v11; --HIDWORD(v10) )
        {
          if ( (int)v5 >= SHIDWORD(v10) )
            break;
        }
        for ( ; distances[(_DWORD)v7] == v11; LODWORD(v7) = v7 + 1 )
        {
          if ( (int)v7 >= v6 )
            break;
        }
        LODWORD(v4) = 8 * HIDWORD(v5);
        HIDWORD(v4) = v36;
        HIDWORD(v7) = v35;
        ++HIDWORD(v5);
        *(_QWORD *)((char *)v36 + v4) = *(_QWORD *)(&v3 - 1);
        v6 = HIDWORD(v10);
        *(_QWORD *)(v4 + HIDWORD(v7)) = v7;
      }
      if ( (int)v5 < v6 )
      {
        do
        {
          v20 = v5;
          v21 = v5 + 1;
          if ( (int)v5 + 1 <= v8 )
          {
            if ( v8 - (int)v5 >= 4 )
            {
              v22 = v5 + 3;
              v23 = v5;
              do
              {
                if ( distances[v21] > (double)distances[v23] )
                  v20 = v21;
                if ( distances[v21 + 1] > (double)distances[v20] )
                  v20 = v22 - 1;
                if ( distances[v21 + 2] > (double)distances[v20] )
                  v20 = v22;
                if ( distances[v21 + 3] > (double)distances[v20] )
                  v20 = v22 + 1;
                v21 += 4;
                v22 += 4;
                v23 = v20;
              }
              while ( v21 <= v8 - 3 );
            }
            if ( v21 <= v8 )
            {
              v24 = v8 - v21 + 1;
              do
              {
                if ( distances[v21] > (double)distances[v20] )
                  v20 = v21;
                --v24;
                ++v21;
              }
              while ( v24 != 0 );
            }
          }
          v25 = &casters[v20];
          v26 = &casters[v8];
          v27 = v20;
          model = v25->model;
          bounds = v25->bounds;
          surfaces = v25->surfaces;
          numSurfaces = v25->numSurfaces;
          v25->model = v26->model;
          v25->bounds = v26->bounds;
          v25->surfaces = v26->surfaces;
          v25->numSurfaces = v26->numSurfaces;
          v26->model = model;
          v26->bounds = bounds;
          v26->surfaces = surfaces;
          v26->numSurfaces = numSurfaces;
          v28 = distances[v27];
          distances[v27] = distances[v8];
          distances[v8--] = v28;
        }
        while ( v8 > (int)v5 );
      }
      v29 = HIDWORD(v5) - 1;
      if ( v29 < 0 )
        break;
      HIDWORD(v4) = v35;
      *(_QWORD *)(&v3 - 1) = v36[v29];
      v5 = v35[v29];
    }
  }
}

