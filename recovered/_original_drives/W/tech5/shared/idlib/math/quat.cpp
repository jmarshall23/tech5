
// ========================================================================
// ?ToRotation@idQuat@@QBA?AVidRotation@@XZ
// EA  : 0x82F39370
// RVA : 0x00F39370
// PDB : w:\tech5\shared\idlib\math\quat.cpp
// ========================================================================

idQuat *__fastcall idQuat::ToRotation(idQuat *this, idRotation *result, long double a3)
{
  double v5; // fp11
  double v6; // fp1
  double z; // fp8
  double v8; // fp31
  double v11; // fp13
  double v12; // fp3
  double v13; // fp1
  double v14; // fp0
  double v15; // fp13
  double y; // fp12
  double x; // fp13
  idVec3 v19; // [sp+50h] [-30h] BYREF

  *(double *)&a3 = result->vec.x;
  v5 = 1.0;
  if ( *(double *)&a3 >= (float)-(float)((float)((float)0.00000011920929 * (float)4.0) - (float)1.0) )
  {
    v8 = 0.0;
    x = 0.0;
    y = 0.0;
  }
  else
  {
    v6 = idMath::ACos(a: a3);
    z = result->origin.z;
    v8 = (float)((float)((float)v6 * idMath::M_RAD2DEG) * (float)2.0);
    _FP3 = (float)((float)((float)(result->origin.x * result->origin.x)
                         + (float)((float)(result->origin.z * result->origin.z)
                                 + (float)(result->origin.y * result->origin.y)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f1, f3, f4, f13 }
    v11 = __frsqrte(_FP1);
    v12 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11
                                                                                        * (float)((float)((float)(result->origin.x * result->origin.x) + (float)((float)(result->origin.z * result->origin.z) + (float)(result->origin.y * result->origin.y)))
                                                                                                * (float)0.5))
                                                                                * (float)v11)
                                                                        - (float)1.5)
                                                        * (float)v11)
                                                * (float)((float)((float)(result->origin.x * result->origin.x)
                                                                + (float)((float)(result->origin.z * result->origin.z)
                                                                        + (float)(result->origin.y * result->origin.y)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v11
                                                                                * (float)((float)((float)(result->origin.x * result->origin.x)
                                                                                                + (float)((float)(result->origin.z * result->origin.z) + (float)(result->origin.y * result->origin.y)))
                                                                                        * (float)0.5))
                                                                        * (float)v11)
                                                                - (float)1.5)
                                                * (float)v11))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v11
                                                        * (float)((float)((float)(result->origin.x * result->origin.x)
                                                                        + (float)((float)(result->origin.z
                                                                                        * result->origin.z)
                                                                                + (float)(result->origin.y
                                                                                        * result->origin.y)))
                                                                * (float)0.5))
                                                * (float)v11)
                                        - (float)1.5)
                        * (float)v11));
    v13 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11 * (float)((float)((float)(result->origin.x * result->origin.x) + (float)((float)(result->origin.z * result->origin.z) + (float)(result->origin.y * result->origin.y))) * (float)0.5)) * (float)v11) - (float)1.5)
                                                                                        * (float)v11)
                                                                                * (float)((float)((float)(result->origin.x * result->origin.x)
                                                                                                + (float)((float)(result->origin.z * result->origin.z) + (float)(result->origin.y * result->origin.y)))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v11 * (float)((float)((float)(result->origin.x * result->origin.x) + (float)((float)(result->origin.z * result->origin.z) + (float)(result->origin.y * result->origin.y))) * (float)0.5)) * (float)v11)
                                                                                                - (float)1.5)
                                                                                * (float)v11))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v11
                                                                                        * (float)((float)((float)(result->origin.x * result->origin.x) + (float)((float)(result->origin.z * result->origin.z) + (float)(result->origin.y * result->origin.y)))
                                                                                                * (float)0.5))
                                                                                * (float)v11)
                                                                        - (float)1.5)
                                                        * (float)v11))
                                        * (float)((float)((float)(result->origin.x * result->origin.x)
                                                        + (float)((float)(result->origin.z * result->origin.z)
                                                                + (float)(result->origin.y * result->origin.y)))
                                                * (float)0.5))
                                * (float)v12)
                        - (float)1.5);
    v14 = (float)((float)v13
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11
                                                                                                * (float)((float)((float)(result->origin.x * result->origin.x) + (float)((float)(result->origin.z * result->origin.z) + (float)(result->origin.y * result->origin.y))) * (float)0.5))
                                                                                        * (float)v11)
                                                                                - (float)1.5)
                                                                * (float)v11)
                                                        * (float)((float)((float)(result->origin.x * result->origin.x)
                                                                        + (float)((float)(result->origin.z
                                                                                        * result->origin.z)
                                                                                + (float)(result->origin.y
                                                                                        * result->origin.y)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v11
                                                                                        * (float)((float)((float)(result->origin.x * result->origin.x) + (float)((float)(result->origin.z * result->origin.z) + (float)(result->origin.y * result->origin.y)))
                                                                                                * (float)0.5))
                                                                                * (float)v11)
                                                                        - (float)1.5)
                                                        * (float)v11))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v11
                                                                * (float)((float)((float)(result->origin.x
                                                                                        * result->origin.x)
                                                                                + (float)((float)(result->origin.z
                                                                                                * result->origin.z)
                                                                                        + (float)(result->origin.y
                                                                                                * result->origin.y)))
                                                                        * (float)0.5))
                                                        * (float)v11)
                                                - (float)1.5)
                                * (float)v11)));
    v15 = (float)((float)((float)v13
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11 * (float)((float)((float)(result->origin.x * result->origin.x) + (float)((float)(result->origin.z * result->origin.z) + (float)(result->origin.y * result->origin.y))) * (float)0.5))
                                                                                                * (float)v11)
                                                                                        - (float)1.5)
                                                                        * (float)v11)
                                                                * (float)((float)((float)(result->origin.x
                                                                                        * result->origin.x)
                                                                                + (float)((float)(result->origin.z
                                                                                                * result->origin.z)
                                                                                        + (float)(result->origin.y
                                                                                                * result->origin.y)))
                                                                        * (float)0.5))
                                                        * (float)((float)-(float)((float)((float)((float)v11
                                                                                                * (float)((float)((float)(result->origin.x * result->origin.x) + (float)((float)(result->origin.z * result->origin.z) + (float)(result->origin.y * result->origin.y))) * (float)0.5))
                                                                                        * (float)v11)
                                                                                - (float)1.5)
                                                                * (float)v11))
                                                - (float)1.5)
                                * (float)((float)-(float)((float)((float)((float)v11
                                                                        * (float)((float)((float)(result->origin.x
                                                                                                * result->origin.x)
                                                                                        + (float)((float)(result->origin.z * result->origin.z)
                                                                                                + (float)(result->origin.y * result->origin.y)))
                                                                                * (float)0.5))
                                                                * (float)v11)
                                                        - (float)1.5)
                                        * (float)v11)))
                * result->origin.x);
    v19.y = result->origin.y * (float)v14;
    v19.x = v15;
    v19.z = (float)z * (float)v14;
    idVec3::FixDegenerateNormal(this: &v19);
    v5 = v19.z;
    y = v19.y;
    x = v19.x;
  }
  *(idVec3 *)&this->x = vec3_origin;
  this->w = x;
  *((float *)this + 4) = y;
  *((float *)this + 5) = v5;
  *((_BYTE *)this + 64) = 0;
  *((float *)this + 6) = v8;
  *(idMat3 *)((char *)this + 28) = mat3_identity;
  return this;
}


// ========================================================================
// ?ToMat3@idQuat@@QBA?AVidMat3@@XZ
// EA  : 0x82F39528
// RVA : 0x00F39528
// PDB : w:\tech5\shared\idlib\math\quat.cpp
// ========================================================================

idQuat *__fastcall idQuat::ToMat3(idQuat *this, idMat3 *result)
{
  double v2; // fp2
  double v3; // fp0
  double v4; // fp10
  double v5; // fp1
  double v6; // fp11
  double v7; // fp12
  double v8; // fp9
  double v9; // fp8
  double v10; // fp7

  v2 = (float)(result->mat[0].x * (float)(result->mat[0].y * (float)2.0));
  v3 = (float)(result->mat[0].y * (float)(result->mat[0].z * (float)2.0));
  v4 = (float)(result->mat[1].x * (float)(result->mat[0].z * (float)2.0));
  v5 = (float)(result->mat[0].x * (float)(result->mat[0].z * (float)2.0));
  v6 = (float)(result->mat[1].x * (float)(result->mat[0].y * (float)2.0));
  v7 = (float)(result->mat[1].x * (float)(result->mat[0].x * (float)2.0));
  v8 = (float)((float)(result->mat[0].z * (float)(result->mat[0].z * (float)2.0))
             + (float)(result->mat[0].y * (float)(result->mat[0].y * (float)2.0)));
  v9 = (float)((float)(result->mat[0].y * (float)(result->mat[0].y * (float)2.0))
             + (float)(result->mat[0].x * (float)(result->mat[0].x * (float)2.0)));
  v10 = (float)((float)(result->mat[0].z * (float)(result->mat[0].z * (float)2.0))
              + (float)(result->mat[0].x * (float)(result->mat[0].x * (float)2.0)));
  this->y = (float)(result->mat[0].x * (float)(result->mat[0].y * (float)2.0))
          - (float)(result->mat[1].x * (float)(result->mat[0].z * (float)2.0));
  this->w = (float)v4 + (float)v2;
  this->z = (float)v6 + (float)v5;
  *((float *)this + 6) = (float)v5 - (float)v6;
  *((float *)this + 5) = (float)v3 - (float)v7;
  *((float *)this + 7) = (float)v7 + (float)v3;
  this->x = (float)1.0 - (float)v8;
  *((float *)this + 8) = (float)1.0 - (float)v9;
  *((float *)this + 4) = (float)1.0 - (float)v10;
  return this;
}


// ========================================================================
// ?ToForward@idQuat@@QBA?AVidVec3@@XZ
// EA  : 0x82F395D0
// RVA : 0x00F395D0
// PDB : w:\tech5\shared\idlib\math\quat.cpp
// ========================================================================

idQuat *__fastcall idQuat::ToForward(idQuat *this, idVec3 *result)
{
  double x; // fp9
  double v3; // fp8
  double v4; // fp4
  double v5; // fp3

  x = result[1].x;
  v3 = (float)(result->y * (float)2.0);
  v4 = (float)(result->x * (float)(result->z * (float)2.0));
  v5 = (float)((float)(result->z * (float)(result->z * (float)2.0))
             + (float)(result->y * (float)(result->y * (float)2.0)));
  this->y = (float)(result->x * (float)(result->y * (float)2.0))
          - (float)(result[1].x * (float)(result->z * (float)2.0));
  this->z = (float)((float)x * (float)v3) + (float)v4;
  this->x = (float)1.0 - (float)v5;
  return this;
}


// ========================================================================
// ?ToAngularVelocity@idQuat@@QBA?AVidVec3@@XZ
// EA  : 0x82F39628
// RVA : 0x00F39628
// PDB : w:\tech5\shared\idlib\math\quat.cpp
// ========================================================================

idQuat *__fastcall idQuat::ToAngularVelocity(idQuat *this, idVec3 *result)
{
  long double v2; // fp2
  double v6; // fp2
  double v7; // fp3
  double v8; // fp31
  double v9; // fp30
  double v10; // fp29
  double v11; // fp1

  *(double *)&v2 = result[1].x;
  _FP5 = (float)((float)((float)(result->x * result->x)
                       + (float)((float)(result->z * result->z) + (float)(result->y * result->y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f13 }
  v6 = __frsqrte(_FP3);
  v7 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6
                                                                                     * (float)((float)((float)(result->x * result->x) + (float)((float)(result->z * result->z) + (float)(result->y * result->y)))
                                                                                             * (float)0.5))
                                                                             * (float)v6)
                                                                     - (float)1.5)
                                                     * (float)v6)
                                             * (float)((float)((float)(result->x * result->x)
                                                             + (float)((float)(result->z * result->z)
                                                                     + (float)(result->y * result->y)))
                                                     * (float)0.5))
                                     * (float)((float)-(float)((float)((float)((float)v6
                                                                             * (float)((float)((float)(result->x * result->x)
                                                                                             + (float)((float)(result->z * result->z) + (float)(result->y * result->y)))
                                                                                     * (float)0.5))
                                                                     * (float)v6)
                                                             - (float)1.5)
                                             * (float)v6))
                             - (float)1.5)
             * (float)((float)-(float)((float)((float)((float)v6
                                                     * (float)((float)((float)(result->x * result->x)
                                                                     + (float)((float)(result->z * result->z)
                                                                             + (float)(result->y * result->y)))
                                                             * (float)0.5))
                                             * (float)v6)
                                     - (float)1.5)
                     * (float)v6));
  *((double *)&v2 + 1) = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6 * (float)((float)((float)(result->x * result->x) + (float)((float)(result->z * result->z) + (float)(result->y * result->y))) * (float)0.5)) * (float)v6)
                                                                                               - (float)1.5)
                                                                               * (float)v6)
                                                                       * (float)((float)((float)(result->x * result->x)
                                                                                       + (float)((float)(result->z * result->z)
                                                                                               + (float)(result->y * result->y)))
                                                                               * (float)0.5))
                                                               * (float)((float)-(float)((float)((float)((float)v6 * (float)((float)((float)(result->x * result->x) + (float)((float)(result->z * result->z) + (float)(result->y * result->y))) * (float)0.5))
                                                                                               * (float)v6)
                                                                                       - (float)1.5)
                                                                       * (float)v6))
                                                       - (float)1.5)
                                       * (float)((float)-(float)((float)((float)((float)v6
                                                                               * (float)((float)((float)(result->x * result->x)
                                                                                               + (float)((float)(result->z * result->z) + (float)(result->y * result->y)))
                                                                                       * (float)0.5))
                                                                       * (float)v6)
                                                               - (float)1.5)
                                               * (float)v6))
                               * (float)((float)((float)(result->x * result->x)
                                               + (float)((float)(result->z * result->z) + (float)(result->y * result->y)))
                                       * (float)0.5));
  v8 = (float)((float)((float)-(float)((float)((float)*((double *)&v2 + 1) * (float)v7) - (float)1.5) * (float)v7)
             * result->x);
  v9 = (float)((float)((float)-(float)((float)((float)*((double *)&v2 + 1) * (float)v7) - (float)1.5) * (float)v7)
             * result->y);
  v10 = (float)((float)((float)-(float)((float)((float)*((double *)&v2 + 1) * (float)v7) - (float)1.5) * (float)v7)
              * result->z);
  v11 = idMath::ACos(a: v2);
  this->x = (float)((float)v11 * (float)-2.0) * (float)v8;
  this->y = (float)((float)v11 * (float)-2.0) * (float)v9;
  this->z = (float)((float)v11 * (float)-2.0) * (float)v10;
  return this;
}


// ========================================================================
// ?Slerp@idQuat@@QAAAAV1@ABV1@0M@Z
// EA  : 0x82F39710
// RVA : 0x00F39710
// PDB : w:\tech5\shared\idlib\math\quat.cpp
// ========================================================================

idQuat *__fastcall idQuat::Slerp(idQuat *this, const idQuat *from, const idQuat *to, double t)
{
  idQuat *v5; // r30
  double w; // fp11
  char v9; // r11
  double v11; // fp2
  double v14; // fp7
  double v15; // fp12
  double v16; // fp28
  double v17; // fp27
  double v18; // fp31

  v5 = this;
  if ( t > 0.0 )
  {
    if ( t < 1.0 )
    {
      if ( from->x != to->x || from->y != to->y || from->z != to->z || (v9 = 1, from->w != to->w) )
        v9 = 0;
      if ( v9 != 0 )
      {
        *this = *to;
        return this;
      }
      _FP29 = (float)((float)(to->y * from->y)
                    + (float)((float)(from->w * to->w) + (float)((float)(to->x * from->x) + (float)(from->z * to->z))));
      v11 = __fabs(_FP29);
      if ( (float)((float)1.0 - (float)v11) <= 0.000001 )
      {
        v18 = (float)((float)1.0 - (float)t);
      }
      else
      {
        _FP10 = (float)((float)-(float)((float)((float)v11 * (float)v11) - (float)1.0)
                      - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f8, f10, f11, f13 }
        v14 = __frsqrte(_FP8);
        v15 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14
                                                                                            * (float)((float)-(float)((float)((float)v11 * (float)v11) - (float)1.0) * (float)0.5))
                                                                                    * (float)v14)
                                                                            - (float)1.5)
                                                            * (float)v14)
                                                    * (float)((float)-(float)((float)((float)v11 * (float)v11)
                                                                            - (float)1.0)
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v14
                                                                                    * (float)((float)-(float)((float)((float)v11 * (float)v11) - (float)1.0)
                                                                                            * (float)0.5))
                                                                            * (float)v14)
                                                                    - (float)1.5)
                                                    * (float)v14))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v14
                                                            * (float)((float)-(float)((float)((float)v11 * (float)v11)
                                                                                    - (float)1.0)
                                                                    * (float)0.5))
                                                    * (float)v14)
                                            - (float)1.5)
                            * (float)v14));
        v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)-(float)((float)((float)v11 * (float)v11) - (float)1.0) * (float)0.5)) * (float)v14) - (float)1.5) * (float)v14)
                                                                                            * (float)((float)-(float)((float)((float)v11 * (float)v11) - (float)1.0) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)-(float)((float)((float)v11 * (float)v11) - (float)1.0) * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                            * (float)v14))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)-(float)((float)((float)v11 * (float)v11) - (float)1.0) * (float)0.5))
                                                                                            * (float)v14)
                                                                                    - (float)1.5)
                                                                    * (float)v14))
                                                    * (float)((float)-(float)((float)((float)v11 * (float)v11)
                                                                            - (float)1.0)
                                                            * (float)0.5))
                                            * (float)v15)
                                    - (float)1.5)
                    * (float)v15);
        v17 = idMath::ATan16(
                y: (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)-(float)((float)((float)v11 * (float)v11) - (float)1.0) * (float)0.5)) * (float)v14) - (float)1.5) * (float)v14) * (float)((float)-(float)((float)((float)v11 * (float)v11) - (float)1.0) * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)-(float)((float)((float)v11 * (float)v11) - (float)1.0) * (float)0.5)) * (float)v14) - (float)1.5) * (float)v14))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)-(float)((float)((float)v11 * (float)v11) - (float)1.0) * (float)0.5)) * (float)v14)
                                                                                              - (float)1.5)
                                                                              * (float)v14))
                                                              * (float)((float)-(float)((float)((float)v11 * (float)v11)
                                                                                      - (float)1.0)
                                                                      * (float)0.5))
                                                      * (float)v15)
                                              - (float)1.5)
                              * (float)v15)
                      * (float)-(float)((float)((float)v11 * (float)v11) - (float)1.0)),
                x: v11);
        v18 = (float)(idMath::Sin16(a: (float)((float)((float)1.0 - (float)t) * (float)v17)) * (float)v16);
        idMath::Sin16(a: (float)((float)v17 * (float)t));
      }
      __asm { fsel      f11, f29, f30, f0 }
      v5->x = (float)(from->x * (float)v18) + (float)(to->x * (float)_FP11);
      v5->y = (float)(to->y * (float)_FP11) + (float)((float)v18 * from->y);
      v5->z = (float)(to->z * (float)_FP11) + (float)(from->z * (float)v18);
      w = (float)((float)(from->w * (float)v18) + (float)((float)_FP11 * to->w));
    }
    else
    {
      this->x = to->x;
      this->y = to->y;
      this->z = to->z;
      w = to->w;
    }
  }
  else
  {
    this->x = from->x;
    this->y = from->y;
    this->z = from->z;
    w = from->w;
  }
  v5->w = w;
  return v5;
}


// ========================================================================
// ?Lerp@idQuat@@QAAAAV1@ABV1@0M@Z
// EA  : 0x82F39948
// RVA : 0x00F39948
// PDB : w:\tech5\shared\idlib\math\quat.cpp
// ========================================================================

idQuat *__fastcall idQuat::Lerp(idQuat *this, const idQuat *from, const idQuat *to, double t)
{
  char v4; // r11
  double v5; // fp10
  double v8; // fp5
  double v9; // fp1
  double v10; // fp7
  double v11; // fp5
  double v12; // fp12
  double v13; // fp2
  double v14; // fp8
  double v15; // fp4
  double v18; // fp13
  double v19; // fp11
  double v20; // fp5
  double v21; // fp4
  double v22; // fp13

  if ( t > 0.0 )
  {
    if ( t < 1.0 )
    {
      if ( from->x != to->x || from->y != to->y || from->z != to->z || (v4 = 1, from->w != to->w) )
        v4 = 0;
      if ( v4 != 0 )
      {
        *this = *to;
      }
      else
      {
        v5 = (float)((float)1.0 - (float)t);
        _FP7 = (float)((float)(to->y * from->y)
                     + (float)((float)(from->w * to->w) + (float)((float)(to->x * from->x) + (float)(from->z * to->z))));
        __asm { fsel      f6, f7, f1, f8 }
        v8 = (float)((float)(to->x * (float)_FP6) + (float)(from->x * (float)((float)1.0 - (float)t)));
        this->x = (float)(to->x * (float)_FP6) + (float)(from->x * (float)((float)1.0 - (float)t));
        v9 = (float)((float)(to->y * (float)_FP6) + (float)((float)((float)1.0 - (float)t) * from->y));
        this->y = v9;
        v10 = v8;
        v11 = (float)((float)(to->z * (float)_FP6) + (float)(from->z * (float)v5));
        this->z = (float)(to->z * (float)_FP6) + (float)(from->z * (float)v5);
        v12 = v9;
        v13 = v11;
        v14 = (float)((float)(from->w * (float)v5) + (float)((float)_FP6 * to->w));
        this->w = (float)(from->w * (float)v5) + (float)((float)_FP6 * to->w);
        v15 = (float)((float)((float)v14 * (float)v14)
                    + (float)((float)((float)v11 * (float)v11)
                            + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))));
        _FP3 = (float)((float)((float)((float)v14 * (float)v14)
                             + (float)((float)((float)v11 * (float)v11)
                                     + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f1, f3, f4, f13 }
        v18 = (float)((float)v15 * (float)0.5);
        v19 = __frsqrte(_FP1);
        v20 = (float)((float)-(float)((float)((float)((float)v19 * (float)((float)v15 * (float)0.5)) * (float)v19)
                                    - (float)1.5)
                    * (float)v19);
        v21 = (float)((float)((float)-(float)((float)((float)((float)v19 * (float)((float)v15 * (float)0.5)) * (float)v19)
                                            - (float)1.5)
                            * (float)v19)
                    * (float)((float)v15 * (float)0.5));
        v22 = (float)((float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5) * (float)v20) * (float)v18);
        this->x = (float)v10
                * (float)((float)-(float)((float)((float)v22
                                                * (float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5)
                                                        * (float)v20))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5) * (float)v20));
        this->y = (float)v12
                * (float)((float)-(float)((float)((float)v22
                                                * (float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5)
                                                        * (float)v20))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5) * (float)v20));
        this->z = (float)v13
                * (float)((float)-(float)((float)((float)v22
                                                * (float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5)
                                                        * (float)v20))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5) * (float)v20));
        this->w = (float)v14
                * (float)((float)-(float)((float)((float)v22
                                                * (float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5)
                                                        * (float)v20))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5) * (float)v20));
      }
    }
    else
    {
      *this = *to;
    }
  }
  else
  {
    *this = *from;
  }
  return this;
}


// ========================================================================
// ?ToAngles@idQuat@@QBA?AVidAngles@@XZ
// EA  : 0x82F39B38
// RVA : 0x00F39B38
// PDB : w:\tech5\shared\idlib\math\quat.cpp
// ========================================================================

idQuat *__fastcall idQuat::ToAngles(idQuat *this, idMat3 *result)
{
  idAngles *v3; // r3
  long double v4; // fp4
  double v5; // fp2
  double v6; // fp1
  idQuat v8; // [sp+50h] [-40h] BYREF

  v3 = (idAngles *)idQuat::ToMat3(this: &v8, result);
  idMat3::ToAngles((idMat3 *)this, result: v3, a3: v6, a4: v5, a5: v4);
  return this;
}

