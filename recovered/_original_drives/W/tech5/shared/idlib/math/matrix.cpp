
// ========================================================================
// ??0idMat3@@QAA@ABVidVec3@@V?$idTypesafeNumber@MW4RadiansUnique_t@@@@@Z
// EA  : 0x82F36868
// RVA : 0x00F36868
// PDB : w:\tech5\shared\idlib\math\matrix.cpp
// ========================================================================

idMat3 *__fastcall idMat3::idMat3(
        idMat3 *this,
        const idVec3 *axis,
        const idTypesafeNumber<float,enum RadiansUnique_t> *angle,
        long double a4)
{
  double v6; // fp31
  long double v7; // fp2
  double v8; // fp30
  long double v9; // fp2
  double v10; // fp7
  double v11; // fp6
  idMat3 v13; // [sp+50h] [-60h] BYREF

  v6 = (float)(angle->value * (float)0.5);
  *(double *)&a4 = v6;
  v7 = sin(x: a4);
  v8 = (float)*(double *)&v7;
  *(double *)&v7 = v6;
  v9 = cos(x: v7);
  v10 = (float)(axis->y * (float)v8);
  v11 = (float)(axis->z * (float)v8);
  v13.mat[0].x = axis->x * (float)v8;
  v13.mat[0].y = v10;
  v13.mat[0].z = v11;
  v13.mat[1].x = *(double *)&v9;
  *this = *idQuat::ToMat3(this: (idQuat *)&v13.mat[1].y, result: &v13);
  return this;
}


// ========================================================================
// ??0idMat3@@QAA@ABVidVec3@@MM@Z
// EA  : 0x82F36958
// RVA : 0x00F36958
// PDB : w:\tech5\shared\idlib\math\matrix.cpp
// ========================================================================

idMat3 *__fastcall idMat3::idMat3(idMat3 *this, const idVec3 *axis, double sineHalfAngle, double cosineHalfAngle)
{
  double v5; // fp9
  idMat3 v7; // [sp+50h] [-50h] BYREF

  v7.mat[0].x = axis->x * (float)sineHalfAngle;
  v7.mat[1].x = cosineHalfAngle;
  v5 = (float)(axis->z * (float)sineHalfAngle);
  v7.mat[0].y = axis->y * (float)sineHalfAngle;
  v7.mat[0].z = v5;
  *this = *idQuat::ToMat3(this: (idQuat *)&v7.mat[1].y, result: &v7);
  return this;
}


// ========================================================================
// ?Determinant@idMat3@@QBAMXZ
// EA  : 0x82F36A08
// RVA : 0x00F36A08
// PDB : w:\tech5\shared\idlib\math\matrix.cpp
// ========================================================================

float __fastcall idMat3::Determinant(idMat3 *this)
{
  double v1; // fp1

  v1 = (float)((float)((float)((float)(this->mat[1].x * this->mat[2].y) - (float)(this->mat[2].x * this->mat[1].y))
                     * this->mat[0].z)
             + (float)((float)((float)((float)(this->mat[1].y * this->mat[2].z)
                                     - (float)(this->mat[1].z * this->mat[2].y))
                             * this->mat[0].x)
                     - (float)((float)((float)(this->mat[1].x * this->mat[2].z)
                                     - (float)(this->mat[2].x * this->mat[1].z))
                             * this->mat[0].y)));
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?InverseSelf@idMat3@@QAA_NXZ
// EA  : 0x82F36A58
// RVA : 0x00F36A58
// PDB : w:\tech5\shared\idlib\math\matrix.cpp
// ========================================================================

int __fastcall idMat3::InverseSelf(idMat3 *this)
{
  double z; // fp11
  double x; // fp10
  double y; // fp9
  double v4; // fp8
  double v5; // fp7
  double v6; // fp6
  double v7; // fp13
  double v8; // fp0
  double v9; // fp12
  double v10; // fp4
  double v11; // fp3
  double v12; // fp2
  double v14; // fp2

  z = this->mat[2].z;
  x = this->mat[1].x;
  y = this->mat[2].y;
  v4 = this->mat[1].z;
  v5 = this->mat[2].x;
  v6 = this->mat[1].y;
  v7 = this->mat[0].y;
  v8 = this->mat[0].x;
  v9 = this->mat[0].z;
  v10 = (float)((float)(this->mat[1].y * this->mat[2].z) - (float)(this->mat[1].z * this->mat[2].y));
  v11 = (float)((float)(this->mat[1].x * this->mat[2].y) - (float)(this->mat[2].x * this->mat[1].y));
  v12 = (float)((float)(this->mat[0].z
                      * (float)((float)(this->mat[1].x * this->mat[2].y) - (float)(this->mat[2].x * this->mat[1].y)))
              + (float)((float)(this->mat[0].x
                              * (float)((float)(this->mat[1].y * this->mat[2].z)
                                      - (float)(this->mat[1].z * this->mat[2].y)))
                      + (float)(this->mat[0].y
                              * (float)((float)(this->mat[2].x * this->mat[1].z)
                                      - (float)(this->mat[1].x * this->mat[2].z)))));
  if ( __fabs(v12) < 9.9999998e-15 )
    return 0;
  v14 = 1.0 / v12;
  this->mat[1].x = (float)((float)(this->mat[2].x * this->mat[1].z) - (float)(this->mat[1].x * this->mat[2].z)) * v14;
  this->mat[0].x = v10 * v14;
  this->mat[2].x = v11 * v14;
  this->mat[0].y = (float)((float)((float)v9 * (float)y) - (float)((float)v7 * (float)z)) * v14;
  this->mat[0].z = (float)((float)((float)v7 * (float)v4) - (float)((float)v9 * (float)v6)) * v14;
  this->mat[1].y = (float)((float)((float)v8 * (float)z) - (float)((float)v9 * (float)v5)) * v14;
  this->mat[1].z = (float)((float)((float)v9 * (float)x) - (float)((float)v8 * (float)v4)) * v14;
  this->mat[2].y = (float)((float)((float)v7 * (float)v5) - (float)((float)v8 * (float)y)) * v14;
  this->mat[2].z = (float)((float)((float)v8 * (float)v6) - (float)((float)v7 * (float)x)) * v14;
  return 1;
}


// ========================================================================
// ?InertiaTranslateSelf@idMat3@@QAAAAV1@MABVidVec3@@0@Z
// EA  : 0x82F36BA8
// RVA : 0x00F36BA8
// PDB : w:\tech5\shared\idlib\math\matrix.cpp
// ========================================================================

idMat3 *__fastcall idMat3::InertiaTranslateSelf(
        idMat3 *this,
        double mass,
        const idVec3 *centerOfMass,
        const idVec3 *translation,
        float *a5)
{
  double v5; // fp8
  double v6; // fp6
  double x; // fp29
  double v8; // fp25
  double v9; // fp12
  double z; // fp31
  double y; // fp28
  double v12; // fp26
  double v13; // fp23
  double v14; // fp24
  double v15; // fp3
  double v16; // fp6
  double v17; // fp13
  double v18; // fp11
  double v19; // fp10
  double v20; // fp8
  double v21; // fp7
  double v22; // fp6

  v5 = (float)(a5[1] + translation->y);
  v6 = (float)(a5[2] + translation->z);
  x = this->mat[1].x;
  v8 = this->mat[2].x;
  v9 = this->mat[0].x;
  z = this->mat[0].z;
  y = this->mat[1].y;
  v12 = this->mat[1].z;
  v13 = this->mat[2].y;
  v14 = (float)((float)v6 * (float)v6);
  v15 = this->mat[2].z;
  v16 = (float)((float)((float)v5 * (float)v5) + (float)((float)v6 * (float)v6));
  v17 = (float)((float)((float)((float)(translation->x + *a5) * (float)(a5[1] + translation->y))
                      - (float)(translation->x * translation->y))
              * (float)mass);
  v18 = (float)((float)((float)((float)(a5[1] + translation->y) * (float)(a5[2] + translation->z))
                      - (float)(translation->y * translation->z))
              * (float)mass);
  v19 = (float)((float)((float)((float)(translation->x + *a5) * (float)(a5[2] + translation->z))
                      - (float)(translation->x * translation->z))
              * (float)mass);
  v20 = (float)((float)((float)(translation->x * translation->x) + (float)(translation->y * translation->y))
              - (float)((float)((float)(translation->x + *a5) * (float)(translation->x + *a5))
                      + (float)((float)v5 * (float)v5)));
  v21 = (float)((float)((float)(translation->y * translation->y) + (float)(translation->z * translation->z)) - (float)v16);
  v22 = (float)((float)((float)(translation->x * translation->x) + (float)(translation->z * translation->z))
              - (float)((float)((float)(translation->x + *a5) * (float)(translation->x + *a5)) + (float)v14));
  this->mat[0].y = this->mat[0].y
                 + (float)((float)((float)((float)(translation->x + *a5) * (float)(a5[1] + translation->y))
                                 - (float)(translation->x * translation->y))
                         * (float)mass);
  this->mat[1].x = (float)x + (float)v17;
  this->mat[1].z = (float)v12 + (float)v18;
  this->mat[2].x = (float)v8 + (float)v19;
  this->mat[0].z = (float)z + (float)v19;
  this->mat[2].y = (float)v13 + (float)v18;
  this->mat[2].z = (float)v15 + (float)((float)v20 * (float)mass);
  this->mat[0].x = (float)v9 + (float)((float)v21 * (float)mass);
  this->mat[1].y = (float)y + (float)((float)v22 * (float)mass);
  return this;
}


// ========================================================================
// ?RotateSelf@idMat3@@QAAABV1@ABVidVec3@@M@Z
// EA  : 0x82F36CD0
// RVA : 0x00F36CD0
// PDB : w:\tech5\shared\idlib\math\matrix.cpp
// ========================================================================

const idMat3 *__fastcall idMat3::RotateSelf(idMat3 *this, const idVec3 *axis, double angle)
{
  double y; // fp10
  double z; // fp2
  const idMat3 *v6; // r3
  idMat3 v8; // [sp+50h] [-90h] BYREF
  idRotation v9; // [sp+80h] [-60h] BYREF

  y = axis->y;
  v9.vec.x = axis->x;
  v9.vec.y = y;
  z = axis->z;
  v9.axisValid = false;
  v9.origin.x = vec3_origin.x;
  v9.vec.z = z;
  v9.origin.y = vec3_origin.y;
  v9.origin.z = vec3_origin.z;
  v9.axis.mat[0].x = mat3_identity.mat[0].x;
  v9.axis.mat[0].y = mat3_identity.mat[0].y;
  v9.axis.mat[0].z = mat3_identity.mat[0].z;
  v9.axis.mat[1].x = mat3_identity.mat[1].x;
  v9.axis.mat[1].y = mat3_identity.mat[1].y;
  v9.axis.mat[1].z = mat3_identity.mat[1].z;
  v9.angle = (float)-angle * idMath::M_RAD2DEG;
  v9.axis.mat[2].x = mat3_identity.mat[2].x;
  v9.axis.mat[2].y = mat3_identity.mat[2].y;
  v9.axis.mat[2].z = mat3_identity.mat[2].z;
  v6 = idRotation::ToMat3(this: &v9);
  *this = *idMat3::operator*(this: &v8, result: this, a: v6);
  return this;
}


// ========================================================================
// ?MakeRotation@idMat3@@QAA_NABVidVec3@@0@Z
// EA  : 0x82F36E00
// RVA : 0x00F36E00
// PDB : w:\tech5\shared\idlib\math\matrix.cpp
// ========================================================================

int __fastcall idMat3::MakeRotation(idMat3 *this, const idVec3 *from, const idVec3 *to)
{
  double v3; // fp11
  double x; // fp0
  double v6; // fp13
  double v7; // fp12
  double v8; // fp1
  double v9; // fp31
  double v10; // fp30
  int result; // r3
  double v12; // fp10
  double v13; // fp12
  double v16; // fp5
  double v17; // fp12
  double v18; // fp10
  double v19; // fp2
  double z; // fp0
  double y; // fp13
  double v22; // fp6
  double v23; // fp4
  idVec3 v24; // [sp+50h] [-30h] BYREF

  x = 1.0;
  v6 = 0.0;
  v7 = idMath::FLT_SMALLEST_NON_DENORMAL;
  v8 = 0.0;
  v9 = (float)((float)(to->x * from->x) + (float)((float)(from->y * to->y) + (float)(to->z * from->z)));
  v10 = (float)((float)1.0
              - (float)((float)(to->x * from->x) + (float)((float)(from->y * to->y) + (float)(to->z * from->z))));
  if ( v10 >= idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    if ( (float)((float)((float)(to->x * from->x) + (float)((float)(from->y * to->y) + (float)(to->z * from->z)))
               + (float)1.0) >= v7 )
    {
      z = from->z;
      y = to->y;
      v22 = (float)(to->z * from->y);
      v23 = (float)((float)(from->y * to->x) - (float)(to->y * from->x));
      v24.y = (float)(to->z * from->x) - (float)(from->z * to->x);
      v24.z = v23;
      v24.x = (float)((float)y * (float)z) - (float)v22;
      v8 = idVec3::NormalizeFast(this: &v24);
      v6 = v24.z;
      v13 = v24.y;
      x = v24.x;
    }
    else
    {
      v12 = (float)((float)(from->y * from->y) + (float)(from->x * from->x));
      if ( v12 > v7 )
      {
        _FP8 = (float)((float)((float)(from->y * from->y) + (float)(from->x * from->x))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f6, f8, f10, f12 }
        v16 = __frsqrte(_FP6);
        v17 = (float)((float)-(float)((float)((float)((float)((float)((float)(from->y * from->y)
                                                                    + (float)(from->x * from->x))
                                                            * (float)0.5)
                                                    * (float)v16)
                                            * (float)v16)
                                    - (float)1.5)
                    * (float)v16);
        v18 = (float)((float)((float)v12 * (float)0.5)
                    * (float)((float)-(float)((float)((float)((float)((float)v12 * (float)0.5) * (float)v16) * (float)v16)
                                            - (float)1.5)
                            * (float)v16));
        v19 = (float)(from->y
                    * (float)((float)-(float)((float)((float)((float)((float)((float)(from->y * from->y)
                                                                            + (float)(from->x * from->x))
                                                                    * (float)0.5)
                                                            * (float)((float)-(float)((float)((float)v18 * (float)v17)
                                                                                    - (float)1.5)
                                                                    * (float)v17))
                                                    * (float)((float)-(float)((float)((float)v18 * (float)v17)
                                                                            - (float)1.5)
                                                            * (float)v17))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)v18 * (float)v17) - (float)1.5) * (float)v17)));
        v3 = from->x;
        v13 = (float)((float)v3
                    * (float)((float)-(float)((float)((float)((float)((float)((float)(from->y * from->y)
                                                                            + (float)((float)v3 * (float)v3))
                                                                    * (float)0.5)
                                                            * (float)((float)-(float)((float)((float)v18 * (float)v17)
                                                                                    - (float)1.5)
                                                                    * (float)v17))
                                                    * (float)((float)-(float)((float)((float)v18 * (float)v17)
                                                                            - (float)1.5)
                                                            * (float)v17))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)v18 * (float)v17) - (float)1.5) * (float)v17)));
        x = -v19;
      }
      else
      {
        v13 = 0.0;
      }
    }
    result = 1;
    this->mat[1].y = (float)((float)((float)v10 * (float)v13) * (float)v13) + (float)v9;
    this->mat[2].z = (float)((float)((float)v10 * (float)v6) * (float)v6) + (float)v9;
    this->mat[0].y = (float)((float)((float)v10 * (float)v13) * (float)x) - (float)((float)v6 * (float)v8);
    this->mat[1].x = (float)((float)((float)v10 * (float)v13) * (float)x) + (float)((float)v6 * (float)v8);
    this->mat[1].z = (float)((float)((float)v10 * (float)v6) * (float)v13) - (float)((float)x * (float)v8);
    this->mat[2].x = (float)((float)((float)v10 * (float)v6) * (float)x) - (float)((float)v13 * (float)v8);
    this->mat[2].y = (float)((float)((float)v10 * (float)v6) * (float)v13) + (float)((float)x * (float)v8);
    v6 = (float)((float)((float)((float)v10 * (float)v6) * (float)x) + (float)((float)v13 * (float)v8));
    x = (float)((float)((float)((float)v10 * (float)x) * (float)x) + (float)v9);
  }
  else
  {
    this->mat[2].z = 1.0;
    result = 0;
    this->mat[1].y = 1.0;
    this->mat[1].z = 0.0;
    this->mat[0].y = 0.0;
    this->mat[2].y = 0.0;
    this->mat[2].x = 0.0;
    this->mat[1].x = 0.0;
  }
  this->mat[0].z = v6;
  this->mat[0].x = x;
  return result;
}


// ========================================================================
// ?ToPitch@idMat3@@QBAMXZ
// EA  : 0x82F36FE0
// RVA : 0x00F36FE0
// PDB : w:\tech5\shared\idlib\math\matrix.cpp
// ========================================================================

float __fastcall idMat3::ToPitch(idMat3 *this, double a2, double a3, long double a4)
{
  long double v4; // fp2
  long double v5; // fp2
  double v6; // fp1

  *(double *)&v4 = this->mat[0].z;
  *((double *)&v4 + 1) = __fsqrts((float)((float)(this->mat[0].y * this->mat[0].y)
                                        + (float)(this->mat[0].x * this->mat[0].x)));
  v5 = atan2(v: v4, u: a4);
  v6 = (float)((float)-(float)*(double *)&v5 * idMath::M_RAD2DEG);
  return *((float *)&v6 + 1);
}


// ========================================================================
// ?ToYaw@idMat3@@QBAMXZ
// EA  : 0x82F37030
// RVA : 0x00F37030
// PDB : w:\tech5\shared\idlib\math\matrix.cpp
// ========================================================================

float __fastcall idMat3::ToYaw(idMat3 *this, double a2, double a3, long double a4)
{
  long double v4; // fp2
  long double v5; // fp2
  double v6; // fp1
  long double v7; // fp2
  long double v8; // fp2

  if ( __fsqrts((float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y))) <= 0.00000011920929 )
  {
    *((double *)&v7 + 1) = this->mat[1].y;
    *(double *)&v7 = this->mat[1].x;
    v8 = atan2(v: v7, u: a4);
    v6 = (float)((float)-(float)*(double *)&v8 * idMath::M_RAD2DEG);
  }
  else
  {
    *(double *)&v4 = this->mat[0].y;
    *((double *)&v4 + 1) = this->mat[0].x;
    v5 = atan2(v: v4, u: a4);
    v6 = (float)(idMath::M_RAD2DEG * (float)*(double *)&v5);
  }
  return *((float *)&v6 + 1);
}


// ========================================================================
// ?ToAngles@idMat3@@QBA?AVidAngles@@XZ
// EA  : 0x82F370C0
// RVA : 0x00F370C0
// PDB : w:\tech5\shared\idlib\math\matrix.cpp
// ========================================================================

idMat3 *__fastcall idMat3::ToAngles(idMat3 *this, idAngles *result, double a3, double a4, long double a5)
{
  long double v7; // fp2
  long double v8; // fp2
  double v9; // fp13
  long double v10; // fp4
  long double v11; // fp2
  double v12; // fp9
  long double v13; // fp4
  long double v14; // fp2
  long double v17; // fp2
  long double v19; // fp2
  double v20; // fp13

  *((double *)&v7 + 1) = __fsqrts((float)((float)(result->pitch * result->pitch) + (float)(result->yaw * result->yaw)));
  if ( *((double *)&v7 + 1) <= 0.00000011920929 )
  {
    _FP12 = result->roll;
    *((double *)&v17 + 1) = result[1].yaw;
    *(double *)&v17 = result[1].pitch;
    __asm { fsel      f11, f12, f0, f13 }
    this->mat[0].x = _FP11;
    v19 = atan2(v: v17, u: a5);
    v20 = idMath::M_RAD2DEG;
    this->mat[0].z = 0.0;
    this->mat[0].y = (float)-(float)*(double *)&v19 * (float)v20;
    return this;
  }
  else
  {
    *(double *)&v7 = result->roll;
    v8 = atan2(v: v7, u: a5);
    v9 = (float)*(double *)&v8;
    *((double *)&v8 + 1) = result->pitch;
    *(double *)&v8 = result->yaw;
    this->mat[0].x = (float)-v9 * idMath::M_RAD2DEG;
    v11 = atan2(v: v8, u: v10);
    *((double *)&v11 + 1) = result[2].roll;
    v12 = (float)(idMath::M_RAD2DEG * (float)*(double *)&v11);
    *(double *)&v11 = result[1].roll;
    this->mat[0].y = v12;
    v14 = atan2(v: v11, u: v13);
    this->mat[0].z = idMath::M_RAD2DEG * (float)*(double *)&v14;
    return this;
  }
}


// ========================================================================
// ?ToQuat@idMat3@@QBA?AVidQuat@@XZ
// EA  : 0x82F371B8
// RVA : 0x00F371B8
// PDB : w:\tech5\shared\idlib\math\matrix.cpp
// ========================================================================

idMat3 *__fastcall idMat3::ToQuat(idMat3 *this, idQuat *result)
{
  double v2; // fp0
  double v3; // fp8
  double v4; // fp7
  double v5; // fp4
  double v8; // fp13
  double v9; // fp13
  int v10; // r9
  int v11; // r10
  int v12; // r11
  int v13; // r31
  int v14; // r30
  double v15; // fp10
  double v16; // fp9
  double v19; // fp6
  double v20; // fp7
  double v21; // fp13
  double v22; // fp6
  double v23; // fp4

  v2 = (float)((float)(result->x + result[1].x) + result[2].x);
  if ( v2 <= 0.0 )
  {
    v10 = result[1].x > (double)result->x;
    if ( result[2].x > (double)result[v10].x )
      v10 = 2;
    v11 = next_1[v10];
    v12 = next_1[v11];
    v13 = 4 * (3 * v11 + v12);
    v14 = 4 * (3 * v12 + v11);
    v15 = *(float *)((char *)&result->x + v13);
    v16 = *(float *)((char *)&result->x + v14);
    _FP1 = (float)((float)((float)(result[v10].x - (float)(result[v12].x + result[v11].x)) + (float)1.0)
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f7, f1, f0, f12 }
    v19 = __frsqrte(_FP7);
    v20 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                        * (float)((float)((float)(result[v10].x - (float)(result[v12].x + result[v11].x)) + (float)1.0)
                                                                                                * (float)0.5))
                                                                                * (float)v19)
                                                                        - (float)1.5)
                                                        * (float)v19)
                                                * (float)((float)((float)(result[v10].x
                                                                        - (float)(result[v12].x + result[v11].x))
                                                                + (float)1.0)
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v19
                                                                                * (float)((float)((float)(result[v10].x - (float)(result[v12].x + result[v11].x))
                                                                                                + (float)1.0)
                                                                                        * (float)0.5))
                                                                        * (float)v19)
                                                                - (float)1.5)
                                                * (float)v19))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v19
                                                        * (float)((float)((float)(result[v10].x
                                                                                - (float)(result[v12].x + result[v11].x))
                                                                        + (float)1.0)
                                                                * (float)0.5))
                                                * (float)v19)
                                        - (float)1.5)
                        * (float)v19));
    v21 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)(result[v10].x - (float)(result[v12].x + result[v11].x)) + (float)1.0) * (float)0.5)) * (float)v19) - (float)1.5) * (float)v19)
                                                                                                * (float)((float)((float)(result[v10].x - (float)(result[v12].x + result[v11].x)) + (float)1.0) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)(result[v10].x - (float)(result[v12].x + result[v11].x)) + (float)1.0) * (float)0.5)) * (float)v19) - (float)1.5)
                                                                                                * (float)v19))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)(result[v10].x - (float)(result[v12].x + result[v11].x)) + (float)1.0) * (float)0.5))
                                                                                                * (float)v19)
                                                                                        - (float)1.5)
                                                                        * (float)v19))
                                                        * (float)((float)((float)(result[v10].x
                                                                                - (float)(result[v12].x + result[v11].x))
                                                                        + (float)1.0)
                                                                * (float)0.5))
                                                * (float)v20)
                                        - (float)1.5)
                        * (float)v20)
                * (float)0.5);
    if ( (float)(*(float *)((char *)&result->x + v14) - *(float *)((char *)&result->x + v13)) < 0.0 )
      v21 = -v21;
    *(&this->mat[0].x + v10) = (float)v21
                             * (float)((float)(result[v10].x - (float)(result[v12].x + result[v11].x)) + (float)1.0);
    v22 = (float)(*(&result->x + 3 * v10 + v11) + *(&result->x + 3 * v11 + v10));
    v23 = (float)(*(&result->x + 3 * v10 + v12) + *(&result->x + 3 * v12 + v10));
    this->mat[1].x = (float)((float)v16 - (float)v15) * (float)v21;
    *(&this->mat[0].x + v11) = (float)v22 * (float)v21;
    *(&this->mat[0].x + v12) = (float)v23 * (float)v21;
  }
  else
  {
    v3 = (float)(result[1].w - result[1].y);
    v4 = (float)(result->z - result[1].z);
    v5 = (float)(result->w - result->y);
    _FP3 = (float)((float)((float)((float)(result->x + result[1].x) + result[2].x) + (float)1.0)
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f1, f3, f6, f13 }
    v8 = __frsqrte(_FP1);
    v9 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8
                                                                                       * (float)((float)((float)v2 + (float)1.0)
                                                                                               * (float)0.5))
                                                                               * (float)v8)
                                                                       - (float)1.5)
                                                       * (float)v8)
                                               * (float)((float)((float)v2 + (float)1.0) * (float)0.5))
                                       * (float)((float)-(float)((float)((float)((float)v8
                                                                               * (float)((float)((float)v2 + (float)1.0)
                                                                                       * (float)0.5))
                                                                       * (float)v8)
                                                               - (float)1.5)
                                               * (float)v8))
                               - (float)1.5)
               * (float)((float)-(float)((float)((float)((float)v8
                                                       * (float)((float)((float)v2 + (float)1.0) * (float)0.5))
                                               * (float)v8)
                                       - (float)1.5)
                       * (float)v8));
    this->mat[1].x = (float)((float)((float)-(float)((float)((float)((float)v9
                                                                   * (float)((float)((float)v2 + (float)1.0) * (float)0.5))
                                                           * (float)v9)
                                                   - (float)1.5)
                                   * (float)v9)
                           * (float)0.5)
                   * (float)((float)v2 + (float)1.0);
    this->mat[0].x = (float)v3
                   * (float)((float)((float)-(float)((float)((float)((float)v9
                                                                   * (float)((float)((float)v2 + (float)1.0) * (float)0.5))
                                                           * (float)v9)
                                                   - (float)1.5)
                                   * (float)v9)
                           * (float)0.5);
    this->mat[0].y = (float)v4
                   * (float)((float)((float)-(float)((float)((float)((float)v9
                                                                   * (float)((float)((float)v2 + (float)1.0) * (float)0.5))
                                                           * (float)v9)
                                                   - (float)1.5)
                                   * (float)v9)
                           * (float)0.5);
    this->mat[0].z = (float)v5
                   * (float)((float)((float)-(float)((float)((float)((float)v9
                                                                   * (float)((float)((float)v2 + (float)1.0) * (float)0.5))
                                                           * (float)v9)
                                                   - (float)1.5)
                                   * (float)v9)
                           * (float)0.5);
  }
  return this;
}


// ========================================================================
// ?ToRotation@idMat3@@QBA?AVidRotation@@XZ
// EA  : 0x82F373F0
// RVA : 0x00F373F0
// PDB : w:\tech5\shared\idlib\math\matrix.cpp
// ========================================================================

idMat3 *__fastcall idMat3::ToRotation(idMat3 *this, idQuat *result)
{
  long double v4; // fp2
  double v5; // fp1
  double x; // fp6
  double z; // fp5
  double y; // fp4
  double v9; // fp2
  double v12; // fp10
  double v13; // fp8
  double v14; // fp2
  double v15; // fp11
  double v16; // fp10
  idMat3 v18; // [sp+50h] [-30h] BYREF

  idMat3::ToQuat(this: &v18, result);
  if ( v18.mat[1].x >= (double)(float)-(float)((float)((float)0.00000011920929 * (float)4.0) - (float)1.0) )
  {
    this->mat[2].x = 0.0;
    this->mat[1].x = 0.0;
    this->mat[1].y = 0.0;
    this->mat[1].z = 1.0;
  }
  else
  {
    *(double *)&v4 = v18.mat[1].x;
    v5 = idMath::ACos(a: v4);
    x = v18.mat[0].x;
    z = v18.mat[0].z;
    y = v18.mat[0].y;
    v9 = (float)((float)(v18.mat[0].x * v18.mat[0].x) + (float)(v18.mat[0].y * v18.mat[0].y));
    this->mat[2].x = (float)((float)v5 * idMath::M_RAD2DEG) * (float)2.0;
    this->mat[1].x = x;
    this->mat[1].y = y;
    this->mat[1].z = z;
    _FP11 = (float)((float)((float)((float)z * (float)z) + (float)v9) - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f9, f11, f1, f13 }
    v12 = (float)((float)((float)((float)z * (float)z) + (float)v9) * (float)0.5);
    v13 = __frsqrte(_FP9);
    v14 = (float)-(float)((float)((float)((float)v13
                                        * (float)((float)((float)((float)z * (float)z) + (float)v9) * (float)0.5))
                                * (float)v13)
                        - (float)1.5);
    v15 = (float)((float)-(float)((float)((float)((float)((float)v14 * (float)v13) * (float)v12)
                                        * (float)((float)v14 * (float)v13))
                                - (float)1.5)
                * (float)((float)v14 * (float)v13));
    v16 = (float)((float)((float)-(float)((float)((float)((float)((float)v14 * (float)v13) * (float)v12)
                                                * (float)((float)v14 * (float)v13))
                                        - (float)1.5)
                        * (float)((float)v14 * (float)v13))
                * (float)v12);
    this->mat[1].x = (float)x * (float)((float)-(float)((float)((float)v16 * (float)v15) - (float)1.5) * (float)v15);
    this->mat[1].y = (float)y * (float)((float)-(float)((float)((float)v16 * (float)v15) - (float)1.5) * (float)v15);
    this->mat[1].z = (float)z * (float)((float)-(float)((float)((float)v16 * (float)v15) - (float)1.5) * (float)v15);
    idVec3::FixDegenerateNormal(this: &this->mat[1]);
  }
  this->mat[0].z = 0.0;
  this->mat[0].y = 0.0;
  this->mat[0].x = 0.0;
  this->mat[2].y = result->x;
  this->mat[2].z = result->y;
  *((float *)this + 9) = result->z;
  *((float *)this + 10) = result->w;
  *((float *)this + 11) = result[1].x;
  *((float *)this + 12) = result[1].y;
  *((float *)this + 13) = result[1].z;
  *((float *)this + 14) = result[1].w;
  *((float *)this + 15) = result[2].x;
  *((_BYTE *)this + 64) = 1;
  return this;
}


// ========================================================================
// ?ToAngularVelocity@idMat3@@QBA?AVidVec3@@XZ
// EA  : 0x82F375A0
// RVA : 0x00F375A0
// PDB : w:\tech5\shared\idlib\math\matrix.cpp
// ========================================================================

idMat3 *__fastcall idMat3::ToAngularVelocity(idMat3 *this, idQuat *result)
{
  idMat3 *v3; // r3
  idMat3 var20; // [sp+50h] [-20h] BYREF

  v3 = idMat3::ToQuat(this: &var20, result);
  idQuat::ToAngularVelocity((idQuat *)this, result: v3->mat);
  return this;
}


// ========================================================================
// ?ToString@idMat3@@QBAPBDH@Z
// EA  : 0x82F375E0
// RVA : 0x00F375E0
// PDB : w:\tech5\shared\idlib\math\matrix.cpp
// ========================================================================

const char *__fastcall idMat3::ToString(idMat3 *this, int precision)
{
  return idStr::FloatArrayToString(array: (const float *)this, length: 9, precision);
}


// ========================================================================
// ?InverseSelf@idMat4@@QAA_NXZ
// EA  : 0x82F375F0
// RVA : 0x00F375F0
// PDB : w:\tech5\shared\idlib\math\matrix.cpp
// ========================================================================

int __fastcall idMat4::InverseSelf(idMat4 *this)
{
  double z; // fp10
  double y; // fp9
  double x; // fp8
  double w; // fp7
  double v5; // fp0
  double v6; // fp28
  double v7; // fp12
  double v8; // fp27
  double v9; // fp26
  double v10; // fp25
  double v12; // fp24
  double v13; // fp22
  double v14; // fp18
  double v15; // fp4
  double v16; // fp31
  double v17; // fp30
  double v18; // fp6
  double v19; // fp3
  double v20; // fp25
  double v21; // fp23
  double v22; // fp1
  double v23; // fp5
  double v24; // fp21
  double v25; // fp2
  double v26; // fp29
  float v27; // [sp+0h] [-C0h]
  float v28; // [sp+4h] [-BCh]
  float v29; // [sp+8h] [-B8h]
  float v30; // [sp+Ch] [-B4h]
  float v31; // [sp+10h] [-B0h]
  float v32; // [sp+14h] [-ACh]
  double v33; // [sp+18h] [-A8h]

  z = this->mat[2].z;
  y = this->mat[2].y;
  x = this->mat[2].x;
  w = this->mat[2].w;
  v5 = this->mat[3].x;
  v6 = (float)((float)(this->mat[1].w * this->mat[0].x) - (float)(this->mat[0].w * this->mat[1].x));
  v7 = this->mat[3].z;
  v8 = (float)((float)(this->mat[1].w * this->mat[0].z) - (float)(this->mat[0].w * this->mat[1].z));
  v28 = (float)(this->mat[0].x * this->mat[1].y) - (float)(this->mat[0].y * this->mat[1].x);
  v9 = (float)((float)(this->mat[1].z * this->mat[0].y) - (float)(this->mat[0].z * this->mat[1].y));
  v27 = (float)(this->mat[1].z * this->mat[0].x) - (float)(this->mat[0].z * this->mat[1].x);
  v29 = (float)(this->mat[2].w
              * (float)((float)(this->mat[1].z * this->mat[0].y) - (float)(this->mat[0].z * this->mat[1].y)))
      + (float)((float)(this->mat[2].y
                      * (float)((float)(this->mat[1].w * this->mat[0].z) - (float)(this->mat[0].w * this->mat[1].z)))
              - (float)(this->mat[2].z
                      * (float)((float)(this->mat[1].w * this->mat[0].y) - (float)(this->mat[0].w * this->mat[1].y))));
  v31 = (float)(this->mat[2].w * v27)
      + (float)((float)(this->mat[2].x
                      * (float)((float)(this->mat[1].w * this->mat[0].z) - (float)(this->mat[0].w * this->mat[1].z)))
              - (float)(this->mat[2].z
                      * (float)((float)(this->mat[1].w * this->mat[0].x) - (float)(this->mat[0].w * this->mat[1].x))));
  v30 = (float)(this->mat[2].w * v28)
      + (float)((float)(this->mat[2].x
                      * (float)((float)(this->mat[1].w * this->mat[0].y) - (float)(this->mat[0].w * this->mat[1].y)))
              - (float)(this->mat[2].y
                      * (float)((float)(this->mat[1].w * this->mat[0].x) - (float)(this->mat[0].w * this->mat[1].x))));
  v32 = (float)(this->mat[2].z * v28)
      + (float)((float)(this->mat[2].x
                      * (float)((float)(this->mat[1].z * this->mat[0].y) - (float)(this->mat[0].z * this->mat[1].y)))
              - (float)(this->mat[2].y * v27));
  v10 = (float)((float)(this->mat[3].w * v32)
              - (float)((float)(this->mat[3].z * v30)
                      - (float)((float)(this->mat[3].y * v31) - (float)(this->mat[3].x * v29))));
  if ( __fabs(v10) < 9.9999998e-15 )
    return 0;
  v33 = this->mat[3].w;
  v12 = (float)((float)(this->mat[3].w * this->mat[0].x) - (float)(this->mat[3].x * this->mat[0].w));
  v13 = (float)((float)(this->mat[3].w * this->mat[0].y) - (float)(this->mat[3].y * this->mat[0].w));
  v14 = (float)((float)(this->mat[3].z * this->mat[0].x) - (float)(this->mat[3].x * this->mat[0].z));
  v16 = (float)((float)(this->mat[3].z * this->mat[0].y) - (float)(this->mat[3].y * this->mat[0].z));
  v17 = (float)((float)(this->mat[2].x
                      * (float)((float)(this->mat[3].w * this->mat[0].z) - (float)(this->mat[3].z * this->mat[0].w)))
              - (float)(this->mat[2].z
                      * (float)((float)(this->mat[3].w * this->mat[0].x) - (float)(this->mat[3].x * this->mat[0].w))));
  v18 = (float)((float)(this->mat[3].y * this->mat[0].x) - (float)(this->mat[3].x * this->mat[0].y));
  v19 = (float)-(float)((float)(this->mat[2].w
                              * (float)((float)(this->mat[3].y * this->mat[1].x)
                                      - (float)(this->mat[3].x * this->mat[1].y)))
                      + (float)((float)(this->mat[2].x
                                      * (float)((float)(this->mat[3].w * this->mat[1].y)
                                              - (float)(this->mat[3].y * this->mat[1].w)))
                              - (float)(this->mat[2].y
                                      * (float)((float)(this->mat[3].w * this->mat[1].x)
                                              - (float)(this->mat[3].x * this->mat[1].w)))));
  v21 = (float)((float)(this->mat[2].z
                      * (float)((float)(this->mat[3].y * this->mat[1].x) - (float)(this->mat[3].x * this->mat[1].y)))
              + (float)((float)(this->mat[2].x
                              * (float)((float)(this->mat[3].z * this->mat[1].y)
                                      - (float)(this->mat[3].y * this->mat[1].z)))
                      - (float)(this->mat[2].y
                              * (float)((float)(this->mat[3].z * this->mat[1].x)
                                      - (float)(this->mat[3].x * this->mat[1].z)))))
      * (1.0
       / v10);
  v22 = (float)-(float)((float)(this->mat[2].w
                              * (float)((float)(this->mat[3].z * this->mat[1].y)
                                      - (float)(this->mat[3].y * this->mat[1].z)))
                      + (float)((float)(this->mat[2].y
                                      * (float)((float)(this->mat[3].w * this->mat[1].z)
                                              - (float)(this->mat[3].z * this->mat[1].w)))
                              - (float)(this->mat[2].z
                                      * (float)((float)(this->mat[3].w * this->mat[1].y)
                                              - (float)(this->mat[3].y * this->mat[1].w)))))
      * (1.0
       / v10);
  v23 = (float)((float)(this->mat[3].x
                      * (float)((float)(this->mat[1].z * this->mat[0].y) - (float)(this->mat[0].z * this->mat[1].y)))
              - (float)(this->mat[3].y * v27));
  v24 = (float)((float)(this->mat[2].w
                      * (float)((float)(this->mat[3].z * this->mat[0].y) - (float)(this->mat[3].y * this->mat[0].z)))
              + (float)((float)(this->mat[2].y
                              * (float)((float)(this->mat[3].w * this->mat[0].z)
                                      - (float)(this->mat[3].z * this->mat[0].w)))
                      - (float)(this->mat[2].z
                              * (float)((float)(this->mat[3].w * this->mat[0].y)
                                      - (float)(this->mat[3].y * this->mat[0].w)))))
      * (1.0
       / v10);
  v15 = 1.0 / v10;
  v20 = (float)((float)(this->mat[2].w
                      * (float)((float)(this->mat[3].z * this->mat[1].x) - (float)(this->mat[3].x * this->mat[1].z)))
              + (float)((float)(this->mat[2].x
                              * (float)((float)(this->mat[3].w * this->mat[1].z)
                                      - (float)(this->mat[3].z * this->mat[1].w)))
                      - (float)(this->mat[2].z
                              * (float)((float)(this->mat[3].w * this->mat[1].x)
                                      - (float)(this->mat[3].x * this->mat[1].w)))));
  v25 = (float)((float)(this->mat[3].y
                      * (float)((float)(this->mat[1].w * this->mat[0].z) - (float)(this->mat[0].w * this->mat[1].z)))
              - (float)(this->mat[3].z
                      * (float)((float)(this->mat[1].w * this->mat[0].y) - (float)(this->mat[0].w * this->mat[1].y))));
  v26 = (float)((float)(this->mat[3].x
                      * (float)((float)(this->mat[1].w * this->mat[0].y) - (float)(this->mat[0].w * this->mat[1].y)))
              - (float)(this->mat[3].y
                      * (float)((float)(this->mat[1].w * this->mat[0].x) - (float)(this->mat[0].w * this->mat[1].x))));
  this->mat[3].x = v21;
  this->mat[2].x = v19 * v15;
  this->mat[1].x = v20 * v15;
  this->mat[0].y = v24;
  this->mat[0].x = v22;
  this->mat[1].y = -(float)((float)((float)w * (float)v14) + (float)v17) * v15;
  this->mat[2].y = (float)((float)((float)w * (float)v18)
                         + (float)((float)((float)x * (float)v13) - (float)((float)y * (float)v12)))
                 * v15;
  this->mat[1].w = v31 * v15;
  this->mat[3].w = v32 * v15;
  this->mat[2].z = (float)((float)((float)v33 * v28) + (float)v26) * v15;
  this->mat[0].z = (float)((float)((float)v33 * (float)v9) + (float)v25) * v15;
  this->mat[3].y = -(float)((float)((float)z * (float)v18)
                          + (float)((float)((float)x * (float)v16) - (float)((float)y * (float)v14)))
                 * v15;
  this->mat[3].z = -(float)((float)((float)v7 * v28) + (float)v23) * v15;
  this->mat[0].w = -v29 * v15;
  this->mat[2].w = -v30 * v15;
  this->mat[1].z = -(float)((float)((float)v33 * v27)
                          + (float)((float)((float)v5 * (float)v8) - (float)((float)v7 * (float)v6)))
                 * v15;
  return 1;
}


// ========================================================================
// `dynamic initializer for 'mat5_zero''
// EA  : 0x83395908
// RVA : 0x01395908
// PDB : w:\tech5\shared\idlib\math\matrix.cpp
// ========================================================================

void _dynamic_initializer_for__mat5_zero__()
{
  char *p_back_chain; // r10
  float *p_w; // r9
  int v2; // ctr
  char *v3; // r10
  float *p_t; // r9
  int i; // ctr
  char *v6; // r10
  float *v7; // r9
  int j; // ctr
  char *v9; // r10
  float *v10; // r9
  int k; // ctr
  float *v12; // r10
  float *v13; // r11
  int m; // ctr
  char back_chain; // [sp+0h] [-A4h] BYREF
  float v16; // [sp+4h] [-A0h]
  float v17; // [sp+8h] [-9Ch]
  float v18; // [sp+Ch] [-98h]
  float v19; // [sp+10h] [-94h]
  float v20; // [sp+14h] [-90h]
  char v21; // [sp+20h] [-84h] BYREF
  float v22; // [sp+24h] [-80h]
  float v23; // [sp+28h] [-7Ch]
  float v24; // [sp+2Ch] [-78h]
  float v25; // [sp+30h] [-74h]
  float v26; // [sp+34h] [-70h]
  char v27; // [sp+40h] [-64h] BYREF
  float v28; // [sp+44h] [-60h]
  float v29; // [sp+48h] [-5Ch]
  float v30; // [sp+4Ch] [-58h]
  float v31; // [sp+50h] [-54h]
  float v32; // [sp+54h] [-50h]
  char v33; // [sp+60h] [-44h] BYREF
  float v34; // [sp+64h] [-40h]
  float v35; // [sp+68h] [-3Ch]
  float v36; // [sp+6Ch] [-38h]
  float v37; // [sp+70h] [-34h]
  float v38; // [sp+74h] [-30h]
  float v39[9]; // [sp+80h] [-24h] BYREF

  p_back_chain = &back_chain;
  p_w = &mat4_zero.mat[3].w;
  v39[1] = 0.0;
  v39[2] = 0.0;
  v2 = 5;
  v39[3] = 0.0;
  v39[4] = 0.0;
  v39[5] = 0.0;
  v34 = 0.0;
  v35 = 0.0;
  v36 = 0.0;
  v37 = 0.0;
  v38 = 0.0;
  v28 = 0.0;
  v29 = 0.0;
  v30 = 0.0;
  v31 = 0.0;
  v32 = 0.0;
  v22 = 0.0;
  v23 = 0.0;
  v24 = 0.0;
  v25 = 0.0;
  v26 = 0.0;
  v16 = 0.0;
  v17 = 0.0;
  v18 = 0.0;
  v19 = 0.0;
  v20 = 0.0;
  do
  {
    p_back_chain += 4;
    *++p_w = *(float *)p_back_chain;
    --v2;
  }
  while ( v2 != 0 );
  v3 = &v21;
  p_t = &mat5_zero.mat[0].t;
  for ( i = 5; i != 0; --i )
  {
    v3 += 4;
    *++p_t = *(float *)v3;
  }
  v6 = &v27;
  v7 = &mat5_zero.mat[1].t;
  for ( j = 5; j != 0; --j )
  {
    v6 += 4;
    *++v7 = *(float *)v6;
  }
  v9 = &v33;
  v10 = &mat5_zero.mat[2].t;
  for ( k = 5; k != 0; --k )
  {
    v9 += 4;
    *++v10 = *(float *)v9;
  }
  v12 = &mat5_zero.mat[3].t;
  v13 = v39;
  for ( m = 5; m != 0; --m )
    *++v12 = *++v13;
}


// ========================================================================
// `dynamic initializer for 'mat5_identity''
// EA  : 0x83395A10
// RVA : 0x01395A10
// PDB : w:\tech5\shared\idlib\math\matrix.cpp
// ========================================================================

void _dynamic_initializer_for__mat5_identity__()
{
  char *p_back_chain; // r10
  _DWORD *v1; // r9
  int v2; // ctr
  char *v3; // r10
  float *p_t; // r9
  int i; // ctr
  char *v6; // r10
  float *v7; // r9
  int j; // ctr
  char *v9; // r10
  float *v10; // r9
  int k; // ctr
  float *v12; // r10
  float *v13; // r11
  int m; // ctr
  char back_chain; // [sp+0h] [-A4h] BYREF
  float v16; // [sp+4h] [-A0h]
  float v17; // [sp+8h] [-9Ch]
  float v18; // [sp+Ch] [-98h]
  float v19; // [sp+10h] [-94h]
  float v20; // [sp+14h] [-90h]
  char v21; // [sp+20h] [-84h] BYREF
  float v22; // [sp+24h] [-80h]
  float v23; // [sp+28h] [-7Ch]
  float v24; // [sp+2Ch] [-78h]
  float v25; // [sp+30h] [-74h]
  float v26; // [sp+34h] [-70h]
  char v27; // [sp+40h] [-64h] BYREF
  float v28; // [sp+44h] [-60h]
  float v29; // [sp+48h] [-5Ch]
  float v30; // [sp+4Ch] [-58h]
  float v31; // [sp+50h] [-54h]
  float v32; // [sp+54h] [-50h]
  char v33; // [sp+60h] [-44h] BYREF
  float v34; // [sp+64h] [-40h]
  float v35; // [sp+68h] [-3Ch]
  float v36; // [sp+6Ch] [-38h]
  float v37; // [sp+70h] [-34h]
  float v38; // [sp+74h] [-30h]
  float v39[9]; // [sp+80h] [-24h] BYREF

  p_back_chain = &back_chain;
  v1 = &unk_8382BD6C;
  v39[1] = 0.0;
  v39[2] = 0.0;
  v2 = 5;
  v39[3] = 0.0;
  v39[4] = 0.0;
  v39[5] = 1.0;
  v34 = 0.0;
  v35 = 0.0;
  v36 = 0.0;
  v37 = 1.0;
  v38 = 0.0;
  v28 = 0.0;
  v29 = 0.0;
  v30 = 1.0;
  v31 = 0.0;
  v32 = 0.0;
  v22 = 0.0;
  v23 = 1.0;
  v24 = 0.0;
  v25 = 0.0;
  v26 = 0.0;
  v16 = 1.0;
  v17 = 0.0;
  v18 = 0.0;
  v19 = 0.0;
  v20 = 0.0;
  do
  {
    p_back_chain += 4;
    *++v1 = *(_DWORD *)p_back_chain;
    --v2;
  }
  while ( v2 != 0 );
  v3 = &v21;
  p_t = &mat5_identity.mat[0].t;
  for ( i = 5; i != 0; --i )
  {
    v3 += 4;
    *++p_t = *(float *)v3;
  }
  v6 = &v27;
  v7 = &mat5_identity.mat[1].t;
  for ( j = 5; j != 0; --j )
  {
    v6 += 4;
    *++v7 = *(float *)v6;
  }
  v9 = &v33;
  v10 = &mat5_identity.mat[2].t;
  for ( k = 5; k != 0; --k )
  {
    v9 += 4;
    *++v10 = *(float *)v9;
  }
  v12 = &mat5_identity.mat[3].t;
  v13 = v39;
  for ( m = 5; m != 0; --m )
    *++v12 = *++v13;
}


// ========================================================================
// `dynamic initializer for 'mat6_zero''
// EA  : 0x83395B20
// RVA : 0x01395B20
// PDB : w:\tech5\shared\idlib\math\matrix.cpp
// ========================================================================

void _dynamic_initializer_for__mat6_zero__()
{
  char *p_back_chain; // r10
  _DWORD *v1; // r9
  int v2; // ctr
  char *v3; // r10
  float *v4; // r9
  int i; // ctr
  char *v6; // r10
  float *v7; // r9
  int j; // ctr
  char *v9; // r10
  float *v10; // r9
  int k; // ctr
  char *v12; // r10
  float *v13; // r9
  int m; // ctr
  float *v15; // r10
  float *v16; // r11
  int n; // ctr
  char v18; // [sp+0h] [-C4h] BYREF
  float v19; // [sp+4h] [-C0h]
  float v20; // [sp+8h] [-BCh]
  float v21; // [sp+Ch] [-B8h]
  float v22; // [sp+10h] [-B4h]
  float v23; // [sp+14h] [-B0h]
  float v24; // [sp+18h] [-ACh]
  char v25; // [sp+20h] [-A4h] BYREF
  float v26; // [sp+24h] [-A0h]
  float v27; // [sp+28h] [-9Ch]
  float v28; // [sp+2Ch] [-98h]
  float v29; // [sp+30h] [-94h]
  float v30; // [sp+34h] [-90h]
  float v31; // [sp+38h] [-8Ch]
  char v32; // [sp+40h] [-84h] BYREF
  float v33; // [sp+44h] [-80h]
  float v34; // [sp+48h] [-7Ch]
  float v35; // [sp+4Ch] [-78h]
  float v36; // [sp+50h] [-74h]
  float v37; // [sp+54h] [-70h]
  float v38; // [sp+58h] [-6Ch]
  char v39; // [sp+60h] [-64h] BYREF
  float v40; // [sp+64h] [-60h]
  float v41; // [sp+68h] [-5Ch]
  float v42; // [sp+6Ch] [-58h]
  float v43; // [sp+70h] [-54h]
  float v44; // [sp+74h] [-50h]
  float v45; // [sp+78h] [-4Ch]
  char back_chain; // [sp+80h] [-44h] BYREF
  float v47; // [sp+84h] [-40h]
  float v48; // [sp+88h] [-3Ch]
  float v49; // [sp+8Ch] [-38h]
  float v50; // [sp+90h] [-34h]
  float v51; // [sp+94h] [-30h]
  float v52; // [sp+98h] [-2Ch]
  float v53[9]; // [sp+A0h] [-24h] BYREF

  p_back_chain = &back_chain;
  v1 = &unk_8382BDD4;
  v53[1] = 0.0;
  v53[2] = 0.0;
  v2 = 6;
  v53[3] = 0.0;
  v53[4] = 0.0;
  v53[5] = 0.0;
  v53[6] = 0.0;
  v40 = 0.0;
  v41 = 0.0;
  v42 = 0.0;
  v43 = 0.0;
  v44 = 0.0;
  v45 = 0.0;
  v26 = 0.0;
  v27 = 0.0;
  v28 = 0.0;
  v29 = 0.0;
  v30 = 0.0;
  v31 = 0.0;
  v19 = 0.0;
  v20 = 0.0;
  v21 = 0.0;
  v22 = 0.0;
  v23 = 0.0;
  v24 = 0.0;
  v33 = 0.0;
  v34 = 0.0;
  v35 = 0.0;
  v36 = 0.0;
  v37 = 0.0;
  v38 = 0.0;
  v47 = 0.0;
  v48 = 0.0;
  v49 = 0.0;
  v50 = 0.0;
  v51 = 0.0;
  v52 = 0.0;
  do
  {
    p_back_chain += 4;
    *++v1 = *(_DWORD *)p_back_chain;
    --v2;
  }
  while ( v2 != 0 );
  v3 = &v32;
  v4 = &mat6_zero.mat[0].p[5];
  for ( i = 6; i != 0; --i )
  {
    v3 += 4;
    *++v4 = *(float *)v3;
  }
  v6 = &v18;
  v7 = &mat6_zero.mat[1].p[5];
  for ( j = 6; j != 0; --j )
  {
    v6 += 4;
    *++v7 = *(float *)v6;
  }
  v9 = &v25;
  v10 = &mat6_zero.mat[2].p[5];
  for ( k = 6; k != 0; --k )
  {
    v9 += 4;
    *++v10 = *(float *)v9;
  }
  v12 = &v39;
  v13 = &mat6_zero.mat[3].p[5];
  for ( m = 6; m != 0; --m )
  {
    v12 += 4;
    *++v13 = *(float *)v12;
  }
  v15 = &mat6_zero.mat[4].p[5];
  v16 = v53;
  for ( n = 6; n != 0; --n )
    *++v15 = *++v16;
}


// ========================================================================
// `dynamic initializer for 'mat6_identity''
// EA  : 0x83395C70
// RVA : 0x01395C70
// PDB : w:\tech5\shared\idlib\math\matrix.cpp
// ========================================================================

void _dynamic_initializer_for__mat6_identity__()
{
  char *p_back_chain; // r10
  float *v1; // r9
  int v2; // ctr
  char *v3; // r10
  float *v4; // r9
  int i; // ctr
  char *v6; // r10
  float *v7; // r9
  int j; // ctr
  char *v9; // r10
  float *v10; // r9
  int k; // ctr
  char *v12; // r10
  float *v13; // r9
  int m; // ctr
  float *v15; // r10
  float *v16; // r11
  int n; // ctr
  char v18; // [sp+0h] [-C4h] BYREF
  float v19; // [sp+4h] [-C0h]
  float v20; // [sp+8h] [-BCh]
  float v21; // [sp+Ch] [-B8h]
  float v22; // [sp+10h] [-B4h]
  float v23; // [sp+14h] [-B0h]
  float v24; // [sp+18h] [-ACh]
  char v25; // [sp+20h] [-A4h] BYREF
  float v26; // [sp+24h] [-A0h]
  float v27; // [sp+28h] [-9Ch]
  float v28; // [sp+2Ch] [-98h]
  float v29; // [sp+30h] [-94h]
  float v30; // [sp+34h] [-90h]
  float v31; // [sp+38h] [-8Ch]
  char v32; // [sp+40h] [-84h] BYREF
  float v33; // [sp+44h] [-80h]
  float v34; // [sp+48h] [-7Ch]
  float v35; // [sp+4Ch] [-78h]
  float v36; // [sp+50h] [-74h]
  float v37; // [sp+54h] [-70h]
  float v38; // [sp+58h] [-6Ch]
  char v39; // [sp+60h] [-64h] BYREF
  float v40; // [sp+64h] [-60h]
  float v41; // [sp+68h] [-5Ch]
  float v42; // [sp+6Ch] [-58h]
  float v43; // [sp+70h] [-54h]
  float v44; // [sp+74h] [-50h]
  float v45; // [sp+78h] [-4Ch]
  char back_chain; // [sp+80h] [-44h] BYREF
  float v47; // [sp+84h] [-40h]
  float v48; // [sp+88h] [-3Ch]
  float v49; // [sp+8Ch] [-38h]
  float v50; // [sp+90h] [-34h]
  float v51; // [sp+94h] [-30h]
  float v52; // [sp+98h] [-2Ch]
  float v53[9]; // [sp+A0h] [-24h] BYREF

  p_back_chain = &back_chain;
  v1 = &mat6_zero.mat[5].p[5];
  v53[1] = 0.0;
  v53[2] = 0.0;
  v2 = 6;
  v53[3] = 0.0;
  v53[4] = 0.0;
  v53[5] = 0.0;
  v53[6] = 1.0;
  v40 = 0.0;
  v41 = 0.0;
  v42 = 0.0;
  v43 = 0.0;
  v44 = 1.0;
  v45 = 0.0;
  v26 = 0.0;
  v27 = 0.0;
  v28 = 0.0;
  v29 = 1.0;
  v30 = 0.0;
  v31 = 0.0;
  v19 = 0.0;
  v20 = 0.0;
  v21 = 1.0;
  v22 = 0.0;
  v23 = 0.0;
  v24 = 0.0;
  v33 = 0.0;
  v34 = 1.0;
  v35 = 0.0;
  v36 = 0.0;
  v37 = 0.0;
  v38 = 0.0;
  v47 = 1.0;
  v48 = 0.0;
  v49 = 0.0;
  v50 = 0.0;
  v51 = 0.0;
  v52 = 0.0;
  do
  {
    p_back_chain += 4;
    *++v1 = *(float *)p_back_chain;
    --v2;
  }
  while ( v2 != 0 );
  v3 = &v32;
  v4 = &mat6_identity.mat[0].p[5];
  for ( i = 6; i != 0; --i )
  {
    v3 += 4;
    *++v4 = *(float *)v3;
  }
  v6 = &v18;
  v7 = &mat6_identity.mat[1].p[5];
  for ( j = 6; j != 0; --j )
  {
    v6 += 4;
    *++v7 = *(float *)v6;
  }
  v9 = &v25;
  v10 = &mat6_identity.mat[2].p[5];
  for ( k = 6; k != 0; --k )
  {
    v9 += 4;
    *++v10 = *(float *)v9;
  }
  v12 = &v39;
  v13 = &mat6_identity.mat[3].p[5];
  for ( m = 6; m != 0; --m )
  {
    v12 += 4;
    *++v13 = *(float *)v12;
  }
  v15 = &mat6_identity.mat[4].p[5];
  v16 = v53;
  for ( n = 6; n != 0; --n )
    *++v15 = *++v16;
}

