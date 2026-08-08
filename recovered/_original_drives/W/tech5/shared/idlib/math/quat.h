
// ========================================================================
// ?Normalize@idQuat@@QAAAAV1@XZ
// EA  : 0x826D0BC8
// RVA : 0x006D0BC8
// PDB : w:\tech5\shared\idlib\math\quat.h
// ========================================================================

idQuat *__fastcall idQuat::Normalize(idQuat *this)
{
  double y; // fp11
  double z; // fp8
  double w; // fp7
  double v6; // fp13
  double v7; // fp1
  double v8; // fp10

  y = this->y;
  z = this->z;
  w = this->w;
  _FP3 = (float)((float)((float)(this->w * this->w)
                       + (float)((float)(this->z * this->z)
                               + (float)((float)(this->x * this->x) + (float)(this->y * this->y))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f1, f3, f4, f13 }
  v6 = __frsqrte(_FP1);
  v7 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6
                                                                                     * (float)((float)((float)(this->w * this->w) + (float)((float)(this->z * this->z) + (float)((float)(this->x * this->x) + (float)(this->y * this->y))))
                                                                                             * (float)0.5))
                                                                             * (float)v6)
                                                                     - (float)1.5)
                                                     * (float)v6)
                                             * (float)((float)((float)(this->w * this->w)
                                                             + (float)((float)(this->z * this->z)
                                                                     + (float)((float)(this->x * this->x)
                                                                             + (float)(this->y * this->y))))
                                                     * (float)0.5))
                                     * (float)((float)-(float)((float)((float)((float)v6
                                                                             * (float)((float)((float)(this->w * this->w)
                                                                                             + (float)((float)(this->z * this->z) + (float)((float)(this->x * this->x) + (float)(this->y * this->y))))
                                                                                     * (float)0.5))
                                                                     * (float)v6)
                                                             - (float)1.5)
                                             * (float)v6))
                             - (float)1.5)
             * (float)((float)-(float)((float)((float)((float)v6
                                                     * (float)((float)((float)(this->w * this->w)
                                                                     + (float)((float)(this->z * this->z)
                                                                             + (float)((float)(this->x * this->x)
                                                                                     + (float)(this->y * this->y))))
                                                             * (float)0.5))
                                             * (float)v6)
                                     - (float)1.5)
                     * (float)v6));
  v8 = (float)((float)-(float)((float)((float)((float)v7
                                             * (float)((float)((float)(this->w * this->w)
                                                             + (float)((float)(this->z * this->z)
                                                                     + (float)((float)(this->x * this->x)
                                                                             + (float)(this->y * this->y))))
                                                     * (float)0.5))
                                     * (float)v7)
                             - (float)1.5)
             * (float)v7);
  this->x = this->x
          * (float)((float)-(float)((float)((float)((float)v7
                                                  * (float)((float)((float)(this->w * this->w)
                                                                  + (float)((float)(this->z * this->z)
                                                                          + (float)((float)(this->x * this->x)
                                                                                  + (float)(this->y * this->y))))
                                                          * (float)0.5))
                                          * (float)v7)
                                  - (float)1.5)
                  * (float)v7);
  this->y = (float)y * (float)v8;
  this->z = (float)z * (float)v8;
  this->w = (float)w * (float)v8;
  return this;
}


// ========================================================================
// ?Inverse@idQuat@@QBA?AV1@XZ
// EA  : 0x826D1280
// RVA : 0x006D1280
// PDB : w:\tech5\shared\idlib\math\quat.h
// ========================================================================

idQuat *__fastcall idQuat::Inverse(idQuat *this, idQuat *result)
{
  float x; // r9
  double w; // fp11
  float z; // r7
  float v5; // r5
  double y; // fp10
  double v7; // fp9
  double v8; // fp8
  double v9; // fp7
  double v10; // fp13
  double v11; // fp6
  double v13; // fp12
  double v15; // fp9
  double v16; // fp13
  double v17; // fp12

  x = result->x;
  w = result->w;
  z = result->z;
  v5 = result->w;
  this->y = result->y;
  y = this->y;
  this->x = x;
  v7 = this->x;
  this->z = z;
  v8 = this->z;
  this->w = v5;
  v9 = this->w;
  v10 = idMath::FLT_SMALLEST_NON_DENORMAL;
  this->w = w;
  v11 = v7;
  _FP1 = (float)((float)((float)((float)v9 * (float)v9)
                       + (float)((float)((float)v8 * (float)v8)
                               + (float)((float)((float)v7 * (float)v7) + (float)((float)y * (float)y))))
               - (float)v10);
  v13 = (float)((float)((float)((float)v9 * (float)v9)
                      + (float)((float)((float)v8 * (float)v8)
                              + (float)((float)((float)v7 * (float)v7) + (float)((float)y * (float)y))))
              * (float)0.5);
  __asm { fsel      f11, f1, f2, f13 }
  v15 = __frsqrte(_FP11);
  v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)v13)
                                                                              * (float)v15)
                                                                      - (float)1.5)
                                                      * (float)v15)
                                              * (float)v13)
                                      * (float)((float)-(float)((float)((float)((float)v15 * (float)v13) * (float)v15)
                                                              - (float)1.5)
                                              * (float)v15))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v15 * (float)v13) * (float)v15) - (float)1.5) * (float)v15));
  v17 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)v13)
                                                                                      * (float)v15)
                                                                              - (float)1.5)
                                                              * (float)v15)
                                                      * (float)v13)
                                              * (float)((float)-(float)((float)((float)((float)v15 * (float)v13)
                                                                              * (float)v15)
                                                                      - (float)1.5)
                                                      * (float)v15))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v15 * (float)v13) * (float)v15) - (float)1.5)
                              * (float)v15))
              * (float)v13);
  this->x = -(float)((float)v11 * (float)((float)-(float)((float)((float)v17 * (float)v16) - (float)1.5) * (float)v16));
  this->y = -(float)((float)y * (float)((float)-(float)((float)((float)v17 * (float)v16) - (float)1.5) * (float)v16));
  this->z = -(float)((float)v8 * (float)((float)-(float)((float)((float)v17 * (float)v16) - (float)1.5) * (float)v16));
  return this;
}


// ========================================================================
// ??0idQuat@@QAA@ABVidVec3@@V?$idTypesafeNumber@MW4RadiansUnique_t@@@@@Z
// EA  : 0x826EDF70
// RVA : 0x006EDF70
// PDB : w:\tech5\shared\idlib\math\quat.h
// ========================================================================

idQuat *__fastcall idQuat::idQuat(
        idQuat *this,
        const idVec3 *axis,
        const idTypesafeNumber<float,enum RadiansUnique_t> *angle,
        long double a4)
{
  double v6; // fp31
  long double v7; // fp2
  double v8; // fp30
  long double v9; // fp2

  v6 = (float)(angle->value * (float)0.5);
  *(double *)&a4 = v6;
  v7 = sin(x: a4);
  v8 = (float)*(double *)&v7;
  *(double *)&v7 = v6;
  v9 = cos(x: v7);
  this->w = *(double *)&v9;
  this->x = axis->x * (float)v8;
  this->y = axis->y * (float)v8;
  this->z = axis->z * (float)v8;
  return this;
}


// ========================================================================
// ??DidQuat@@QBA?AVidVec3@@ABV1@@Z
// EA  : 0x826F8C88
// RVA : 0x006F8C88
// PDB : w:\tech5\shared\idlib\math\quat.h
// ========================================================================

idQuat *__fastcall idQuat::operator*(idQuat *this, idVec3 *result, const idVec3 *a)
{
  double y; // fp5
  double z; // fp31
  double v5; // fp10
  double v6; // fp6
  double v7; // fp4
  double v8; // fp3

  y = a->y;
  z = a->z;
  v5 = (float)((float)((float)(result->y * result->z) * (float)2.0)
             + (float)((float)(result[1].x * result->x) * (float)2.0));
  v6 = (float)((float)((float)(result->y * result->z) * (float)2.0)
             - (float)((float)(result[1].x * result->x) * (float)2.0));
  v7 = (float)((float)((float)((float)((float)((float)(result->y * result->y) - (float)(result->x * result->x))
                                     - (float)(result->z * result->z))
                             + (float)(result[1].x * result[1].x))
                     * a->y)
             + (float)((float)((float)((float)(result->y * result->x) * (float)2.0)
                             - (float)((float)(result[1].x * result->z) * (float)2.0))
                     * a->x));
  v8 = (float)((float)((float)((float)((float)(result[1].x * result[1].x)
                                     - (float)((float)(result->y * result->y) + (float)(result->x * result->x)))
                             + (float)(result->z * result->z))
                     * a->z)
             + (float)((float)((float)((float)(result->y * result[1].x) * (float)2.0)
                             + (float)((float)(result->z * result->x) * (float)2.0))
                     * a->x));
  this->x = (float)((float)((float)((float)(result->z * result->x) * (float)2.0)
                          - (float)((float)(result->y * result[1].x) * (float)2.0))
                  * a->z)
          + (float)((float)((float)((float)((float)((float)(result->x * result->x) - (float)(result->y * result->y))
                                          - (float)(result->z * result->z))
                                  + (float)(result[1].x * result[1].x))
                          * a->x)
                  + (float)((float)((float)((float)(result[1].x * result->z) * (float)2.0)
                                  + (float)((float)(result->y * result->x) * (float)2.0))
                          * a->y));
  this->y = (float)((float)v5 * (float)z) + (float)v7;
  this->z = (float)((float)v6 * (float)y) + (float)v8;
  return this;
}


// ========================================================================
// ?ToMat3@idCQuat@@QBA?AVidMat3@@XZ
// EA  : 0x827CD520
// RVA : 0x007CD520
// PDB : w:\tech5\shared\idlib\math\quat.h
// ========================================================================

idCQuat *__fastcall idCQuat::ToMat3(idCQuat *this, idMat3 *result)
{
  double v2; // fp13
  double y; // fp12
  double x; // fp11
  idMat3 var20; // [sp+50h] [-20h] BYREF

  v2 = (float)(result->mat[0].z * result->mat[0].z);
  y = result->mat[0].y;
  x = result->mat[0].x;
  var20.mat[0].y = result->mat[0].y;
  var20.mat[0].x = x;
  var20.mat[0].z = result->mat[0].z;
  var20.mat[1].x = __fsqrts(__fabs((float)((float)1.0
                                         - (float)((float)((float)x * (float)x)
                                                 + (float)((float)((float)y * (float)y) + (float)v2)))));
  idQuat::ToMat3((idQuat *)this, result: &var20);
  return this;
}


// ========================================================================
// ??8idQuat@@QBA_NABV0@@Z
// EA  : 0x828398C8
// RVA : 0x008398C8
// PDB : w:\tech5\shared\idlib\math\quat.h
// ========================================================================

int __fastcall idQuat::operator==(idQuat *this, const idQuat *a)
{
  unsigned __int8 v2; // r11

  if ( this->x != a->x )
    return 0;
  if ( this->y != a->y )
    return 0;
  if ( this->z != a->z )
    return 0;
  v2 = 1;
  if ( this->w != a->w )
    return 0;
  return v2;
}


// ========================================================================
// ?MakeRotation@idQuat@@QAAXABVidVec3@@0@Z
// EA  : 0x82891A98
// RVA : 0x00891A98
// PDB : w:\tech5\shared\idlib\math\quat.h
// ========================================================================

void __fastcall idQuat::MakeRotation(idQuat *this, const idVec3 *from, const idVec3 *to)
{
  double v3; // fp2
  double v4; // fp7
  double v5; // fp4
  double x; // fp1
  double v7; // fp11
  double v8; // fp3
  double v9; // fp2
  double v12; // fp5
  double v13; // fp3
  double v14; // fp6
  double v15; // fp5

  this->x = (float)(from->z * to->y) - (float)(from->y * to->z);
  v3 = (float)((float)(from->x * to->z) - (float)(to->x * from->z));
  this->y = (float)(from->x * to->z) - (float)(to->x * from->z);
  v4 = (float)((float)(from->y * to->x) - (float)(from->x * to->y));
  this->z = (float)(from->y * to->x) - (float)(from->x * to->y);
  v5 = v3;
  x = this->x;
  v7 = v4;
  v8 = (float)((float)(this->x * this->x) + (float)((float)v5 * (float)v5));
  v9 = (float)((float)((float)(from->y * to->y) + (float)((float)(from->x * to->x) + (float)(to->z * from->z)))
             + (float)1.0);
  this->w = (float)((float)(from->y * to->y) + (float)((float)(from->x * to->x) + (float)(to->z * from->z)))
          + (float)1.0;
  _FP7 = (float)((float)((float)((float)v9 * (float)v9) + (float)((float)((float)v7 * (float)v7) + (float)v8))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f6, f7, f8, f13 }
  v12 = (float)((float)((float)((float)v9 * (float)v9) + (float)((float)((float)v7 * (float)v7) + (float)v8))
              * (float)0.5);
  v13 = __frsqrte(_FP6);
  v14 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13 * (float)v12)
                                                                              * (float)v13)
                                                                      - (float)1.5)
                                                      * (float)v13)
                                              * (float)v12)
                                      * (float)((float)-(float)((float)((float)((float)v13 * (float)v12) * (float)v13)
                                                              - (float)1.5)
                                              * (float)v13))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v13 * (float)v12) * (float)v13) - (float)1.5) * (float)v13));
  v15 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13 * (float)v12)
                                                                                      * (float)v13)
                                                                              - (float)1.5)
                                                              * (float)v13)
                                                      * (float)v12)
                                              * (float)((float)-(float)((float)((float)((float)v13 * (float)v12)
                                                                              * (float)v13)
                                                                      - (float)1.5)
                                                      * (float)v13))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v13 * (float)v12) * (float)v13) - (float)1.5)
                              * (float)v13))
              * (float)v12);
  this->x = (float)x * (float)((float)-(float)((float)((float)v15 * (float)v14) - (float)1.5) * (float)v14);
  this->y = (float)v5 * (float)((float)-(float)((float)((float)v15 * (float)v14) - (float)1.5) * (float)v14);
  this->z = (float)v7 * (float)((float)-(float)((float)((float)v15 * (float)v14) - (float)1.5) * (float)v14);
  this->w = (float)v9 * (float)((float)-(float)((float)((float)v15 * (float)v14) - (float)1.5) * (float)v14);
}


// ========================================================================
// ?Compare@idQuat@@QBA_NABV1@M@Z
// EA  : 0x82CF5430
// RVA : 0x00CF5430
// PDB : w:\tech5\shared\idlib\math\quat.h
// ========================================================================

BOOL __fastcall idQuat::Compare(idQuat *this, const idQuat *a, double epsilon)
{
  return __fabs((float)(this->x - a->x)) <= epsilon
      && __fabs((float)(this->y - a->y)) <= epsilon
      && __fabs((float)(this->z - a->z)) <= epsilon
      && __fabs((float)(this->w - a->w)) <= epsilon;
}


// ========================================================================
// ?FixDenormals@idQuat@@QAA_NXZ
// EA  : 0x82CF54A8
// RVA : 0x00CF54A8
// PDB : w:\tech5\shared\idlib\math\quat.h
// ========================================================================

int __fastcall idQuat::FixDenormals(idQuat *this)
{
  double v1; // fp12
  int result; // r3

  v1 = __fabs(this->x);
  result = 0;
  if ( v1 <= 1.0e-30 )
  {
    this->x = 0.0;
    result = 1;
  }
  if ( __fabs(this->y) <= 1.0e-30 )
  {
    this->y = 0.0;
    result = 1;
  }
  if ( __fabs(this->z) <= 1.0e-30 )
  {
    this->z = 0.0;
    result = 1;
  }
  if ( __fabs(this->w) <= 1.0e-30 )
  {
    this->w = 0.0;
    return 1;
  }
  return result;
}

