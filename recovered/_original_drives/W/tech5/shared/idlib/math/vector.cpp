
// ========================================================================
// ?ToString@idVec2@@QBAPBDH@Z
// EA  : 0x82F3B850
// RVA : 0x00F3B850
// PDB : w:\tech5\shared\idlib\math\vector.cpp
// ========================================================================

const char *__fastcall idVec2::ToString(idVec2 *this, int precision)
{
  return idStr::FloatArrayToString(array: &this->x, length: 2, precision);
}


// ========================================================================
// ?ToYaw@idVec3@@QBAMXZ
// EA  : 0x82F3B860
// RVA : 0x00F3B860
// PDB : w:\tech5\shared\idlib\math\vector.cpp
// ========================================================================

float __fastcall idVec3::ToYaw(idVec3 *this, double a2, double a3, long double a4)
{
  long double v4; // fp2
  double v5; // fp1
  long double v6; // fp2

  *((double *)&v4 + 1) = this->x;
  if ( __fabs(*((double *)&v4 + 1)) > idMath::FLT_SMALLEST_NON_DENORMAL
    || __fabs(this->y) > idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    *(double *)&v4 = this->y;
    v6 = atan2(v: v4, u: a4);
    v5 = (float)(idMath::M_RAD2DEG * (float)*(double *)&v6);
    if ( v5 < 0.0 )
      v5 = (float)((float)v5 + (float)360.0);
  }
  else
  {
    v5 = 0.0;
  }
  return *((float *)&v5 + 1);
}


// ========================================================================
// ?ToPitch@idVec3@@QBAMXZ
// EA  : 0x82F3B8F0
// RVA : 0x00F3B8F0
// PDB : w:\tech5\shared\idlib\math\vector.cpp
// ========================================================================

float __fastcall idVec3::ToPitch(idVec3 *this, double a2, double a3, long double a4)
{
  double v4; // fp0
  long double v7; // fp2
  long double v8; // fp2
  double v9; // fp12

  v4 = (float)((float)(this->x * this->x) + (float)(this->y * this->y));
  if ( __fabs(v4) > idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    *(double *)&v7 = this->z;
    *((double *)&v7 + 1) = __fsqrts(v4);
    v8 = atan2(v: v7, u: a4);
    v9 = (float)*(double *)&v8;
    _FP1 = (float)((float)-v9 * idMath::M_RAD2DEG);
    if ( _FP1 < 0.0 )
      _FP1 = (float)((float)((float)-v9 * idMath::M_RAD2DEG) + (float)360.0);
  }
  else
  {
    _FP12 = this->z;
    __asm { fsel      f1, f12, f0, f13 }
  }
  return *((float *)&_FP1 + 1);
}


// ========================================================================
// ?ToAngles@idVec3@@QBA?AVidAngles@@XZ
// EA  : 0x82F3B998
// RVA : 0x00F3B998
// PDB : w:\tech5\shared\idlib\math\vector.cpp
// ========================================================================

idVec3 *__fastcall idVec3::ToAngles(idVec3 *this, idAngles *result, double a3, double a4, long double a5)
{
  double v7; // fp28
  double v9; // fp31
  double v10; // fp30
  long double v12; // fp2
  long double v13; // fp4
  long double v14; // fp2
  long double v15; // fp2
  long double v16; // fp2
  double v17; // fp13

  v7 = (float)((float)(result->pitch * result->pitch) + (float)(result->yaw * result->yaw));
  if ( __fabs(v7) > idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    *(double *)&v12 = result->yaw;
    *((double *)&v12 + 1) = result->pitch;
    v14 = atan2(v: v12, u: a5);
    v9 = 0.0;
    v10 = (float)(idMath::M_RAD2DEG * (float)*(double *)&v14);
    if ( v10 < 0.0 )
      v10 = (float)((float)(idMath::M_RAD2DEG * (float)*(double *)&v14) + (float)360.0);
    *(double *)&v15 = result->roll;
    *((double *)&v15 + 1) = __fsqrts(v7);
    v16 = atan2(v: v15, u: v13);
    v17 = (float)*(double *)&v16;
    _FP0 = (float)((float)-v17 * idMath::M_RAD2DEG);
    if ( _FP0 < 0.0 )
      _FP0 = (float)((float)((float)-v17 * idMath::M_RAD2DEG) + (float)360.0);
  }
  else
  {
    _FP12 = result->roll;
    v9 = 0.0;
    v10 = 0.0;
    __asm { fsel      f0, f12, f0, f13 }
  }
  this->x = _FP0;
  this->y = v10;
  this->z = v9;
  return this;
}


// ========================================================================
// ?ToAngles180@idVec3@@QBA?AVidAngles@@M@Z
// EA  : 0x82F3BA88
// RVA : 0x00F3BA88
// PDB : w:\tech5\shared\idlib\math\vector.cpp
// ========================================================================

idVec3 *__fastcall idVec3::ToAngles180(idVec3 *this, idAngles *result, double epsilon, double a4, long double a5)
{
  double v7; // fp31
  double v9; // fp31
  long double v11; // fp2
  long double v12; // fp2
  long double v13; // fp4
  long double v14; // fp2

  v7 = (float)((float)(result->pitch * result->pitch) + (float)(result->yaw * result->yaw));
  if ( __fabs(v7) > epsilon )
  {
    *(double *)&v11 = result->yaw;
    *((double *)&v11 + 1) = result->pitch;
    v12 = atan2(v: v11, u: a5);
    *((double *)&v12 + 1) = __fsqrts(v7);
    v9 = (float)(idMath::M_RAD2DEG * (float)*(double *)&v12);
    *(double *)&v12 = result->roll;
    v14 = atan2(v: v12, u: v13);
    _FP0 = (float)((float)-(float)*(double *)&v14 * idMath::M_RAD2DEG);
  }
  else
  {
    _FP12 = result->roll;
    v9 = 0.0;
    __asm { fsel      f0, f12, f0, f13 }
  }
  this->x = _FP0;
  this->y = v9;
  this->z = 0.0;
  return this;
}


// ========================================================================
// ?ToMat3@idVec3@@QBA?AVidMat3@@XZ
// EA  : 0x82F3BB40
// RVA : 0x00F3BB40
// PDB : w:\tech5\shared\idlib\math\vector.cpp
// ========================================================================

idMat3 *__fastcall idVec3::ToMat3(idVec3 *this, idMat3 *result)
{
  double v2; // fp13
  double v3; // fp0
  double y; // fp11
  double v8; // fp5
  double z; // fp10
  double v11; // fp8
  double v12; // fp7
  double v13; // fp3
  double v14; // fp10
  double v16; // fp5
  double v17; // fp2
  double v19; // fp10
  double v20; // fp13
  double v21; // fp9
  double v22; // fp9
  double v23; // fp1
  double v24; // fp13
  double v25; // fp8
  double x; // fp11
  double v27; // fp6
  double v28; // fp5

  v2 = idMath::FLT_SMALLEST_NON_DENORMAL;
  v3 = (float)((float)(result->mat[0].x * result->mat[0].x) + (float)(result->mat[0].y * result->mat[0].y));
  if ( __fabs(v3) > idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    this->x = result->mat[0].x;
    _FP12 = (float)((float)v3 - (float)v2);
    y = result->mat[0].y;
    v8 = (float)(result->mat[0].y * result->mat[0].y);
    this->y = result->mat[0].y;
    __asm { fsel      f9, f12, f0, f13 }
    z = result->mat[0].z;
    this->z = result->mat[0].z;
    v11 = z;
    v12 = __frsqrte(_FP9);
    v13 = (float)v12;
    v14 = (float)((float)((float)z * (float)z) + (float)((float)(this->x * this->x) + (float)v8));
    v16 = (float)((float)v14 * (float)0.5);
    v17 = (float)-(float)((float)((float)((float)v12 * (float)((float)v3 * (float)0.5)) * (float)v12) - (float)1.5);
    _FP7 = (float)((float)v14 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f13, f7, f10, f12 }
    v19 = __frsqrte(_FP13);
    v20 = (float)((float)-(float)((float)((float)((float)((float)v17 * (float)v13) * (float)((float)v3 * (float)0.5))
                                        * (float)((float)v17 * (float)v13))
                                - (float)1.5)
                * (float)((float)v17 * (float)v13));
    v21 = (float)((float)-(float)((float)((float)((float)v19 * (float)v16) * (float)v19) - (float)1.5) * (float)v19);
    v22 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)v16)
                                                                                * (float)v21)
                                                                        - (float)1.5)
                                                        * (float)v21)
                                                * (float)v16)
                                        * (float)((float)-(float)((float)((float)((float)v21 * (float)v16) * (float)v21)
                                                                - (float)1.5)
                                                * (float)v21))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v21 * (float)v16) * (float)v21) - (float)1.5)
                        * (float)v21));
    this->x = this->x * (float)v22;
    this->z = (float)v11 * (float)v22;
    this->y = (float)y * (float)v22;
    v23 = -(float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)v3 * (float)0.5)) * (float)v20)
                                         - (float)1.5)
                         * (float)v20)
                 * result->mat[0].y);
    *((float *)this + 3) = v23;
    v24 = (float)(result->mat[0].x
                * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)v3 * (float)0.5)) * (float)v20)
                                        - (float)1.5)
                        * (float)v20));
    *((float *)this + 4) = v24;
    *((float *)this + 5) = 0.0;
    v25 = this->y;
    x = this->x;
    v27 = (float)((float)v23 * this->y);
    v28 = (float)((float)v24 * this->z);
    *((float *)this + 7) = (float)((float)v23 * this->z) - (float)(this->x * (float)0.0);
    *((float *)this + 8) = (float)((float)x * (float)v24) - (float)v27;
    *((float *)this + 6) = (float)((float)0.0 * (float)v25) - (float)v28;
  }
  else
  {
    this->x = 0.0;
    this->y = 0.0;
    _FP11 = result->mat[0].z;
    __asm { fsel      f10, f11, f13, f12 }
    this->z = _FP10;
    *((float *)this + 3) = 1.0;
    *((float *)this + 4) = 0.0;
    *((float *)this + 5) = 0.0;
    *((float *)this + 6) = 0.0;
    *((float *)this + 7) = _FP10;
    *((float *)this + 8) = 0.0;
  }
  return (idMat3 *)this;
}


// ========================================================================
// ?ToZAxis@idVec3@@QBA?AVidMat3@@XZ
// EA  : 0x82F3BCE0
// RVA : 0x00F3BCE0
// PDB : w:\tech5\shared\idlib\math\vector.cpp
// ========================================================================

idMat3 *__fastcall idVec3::ToZAxis(idVec3 *this, idMat3 *result)
{
  double v2; // fp13
  double v3; // fp0
  double z; // fp10
  double v9; // fp7
  double v10; // fp6
  double v11; // fp3
  double v12; // fp10
  double v14; // fp4
  double v15; // fp5
  double v17; // fp13
  double v18; // fp12
  double v19; // fp10
  double v20; // fp9
  double v21; // fp1
  double v22; // fp13
  double v23; // fp12
  double v24; // fp4
  double v25; // fp2
  double v26; // fp11
  double v27; // fp0
  double v28; // fp9
  double v29; // fp8

  v2 = idMath::FLT_SMALLEST_NON_DENORMAL;
  v3 = (float)((float)(result->mat[0].x * result->mat[0].x) + (float)(result->mat[0].y * result->mat[0].y));
  if ( __fabs(v3) > idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    *((float *)this + 6) = result->mat[0].x;
    _FP11 = (float)((float)v3 - (float)v2);
    *((float *)this + 7) = result->mat[0].y;
    z = result->mat[0].z;
    __asm { fsel      f9, f11, f0, f13 }
    *((float *)this + 8) = result->mat[0].z;
    v9 = z;
    v10 = *((float *)this + 7);
    v11 = __frsqrte(_FP9);
    _FP9 = (float)((float)((float)((float)z * (float)z)
                         + (float)((float)(*((float *)this + 6) * *((float *)this + 6))
                                 + (float)(*((float *)this + 7) * *((float *)this + 7))))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v14 = (float)((float)v11 * (float)((float)v3 * (float)0.5));
    v15 = (float)((float)((float)((float)z * (float)z)
                        + (float)((float)(*((float *)this + 6) * *((float *)this + 6))
                                + (float)(*((float *)this + 7) * *((float *)this + 7))))
                * (float)0.5);
    v12 = (float)v11;
    __asm { fsel      f3, f9, f1, f12 }
    v17 = __frsqrte(_FP3);
    v18 = (float)((float)-(float)((float)((float)v14 * (float)v12) - (float)1.5) * (float)v12);
    v20 = (float)((float)((float)-(float)((float)((float)v14 * (float)v12) - (float)1.5) * (float)v12)
                * (float)((float)v3 * (float)0.5));
    v19 = (float)v17;
    v21 = (float)-(float)((float)((float)((float)v17 * (float)v15) * (float)v17) - (float)1.5);
    v22 = (float)((float)-(float)((float)((float)v20 * (float)v18) - (float)1.5) * (float)v18);
    v23 = (float)((float)v21 * (float)v19);
    *((float *)this + 6) = *((float *)this + 6)
                         * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23 * (float)v15)
                                                                                                 * (float)v23)
                                                                                         - (float)1.5)
                                                                         * (float)v23)
                                                                 * (float)v15)
                                                         * (float)((float)-(float)((float)((float)((float)v23
                                                                                                 * (float)v15)
                                                                                         * (float)v23)
                                                                                 - (float)1.5)
                                                                 * (float)v23))
                                                 - (float)1.5)
                                 * (float)((float)-(float)((float)((float)((float)v23 * (float)v15) * (float)v23)
                                                         - (float)1.5)
                                         * (float)v23));
    *((float *)this + 7) = (float)v10
                         * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23 * (float)v15)
                                                                                                 * (float)v23)
                                                                                         - (float)1.5)
                                                                         * (float)v23)
                                                                 * (float)v15)
                                                         * (float)((float)-(float)((float)((float)((float)v23
                                                                                                 * (float)v15)
                                                                                         * (float)v23)
                                                                                 - (float)1.5)
                                                                 * (float)v23))
                                                 - (float)1.5)
                                 * (float)((float)-(float)((float)((float)((float)v23 * (float)v15) * (float)v23)
                                                         - (float)1.5)
                                         * (float)v23));
    *((float *)this + 8) = (float)v9
                         * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23 * (float)v15)
                                                                                                 * (float)v23)
                                                                                         - (float)1.5)
                                                                         * (float)v23)
                                                                 * (float)v15)
                                                         * (float)((float)-(float)((float)((float)((float)v23
                                                                                                 * (float)v15)
                                                                                         * (float)v23)
                                                                                 - (float)1.5)
                                                                 * (float)v23))
                                                 - (float)1.5)
                                 * (float)((float)-(float)((float)((float)((float)v23 * (float)v15) * (float)v23)
                                                         - (float)1.5)
                                         * (float)v23));
    v24 = -(float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)v3 * (float)0.5)) * (float)v22)
                                         - (float)1.5)
                         * (float)v22)
                 * result->mat[0].y);
    this->x = v24;
    v25 = (float)(result->mat[0].x
                * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v3 * (float)0.5)) * (float)v22)
                                        - (float)1.5)
                        * (float)v22));
    this->y = result->mat[0].x
            * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v3 * (float)0.5)) * (float)v22)
                                    - (float)1.5)
                    * (float)v22);
    this->z = 0.0;
    v26 = *((float *)this + 7);
    v27 = *((float *)this + 6);
    v28 = (float)((float)v24 * *((float *)this + 7));
    v29 = (float)((float)v25 * *((float *)this + 8));
    *((float *)this + 4) = (float)((float)v24 * *((float *)this + 8)) - (float)(*((float *)this + 6) * (float)0.0);
    *((float *)this + 5) = (float)((float)v27 * (float)v25) - (float)v28;
    *((float *)this + 3) = (float)((float)0.0 * (float)v26) - (float)v29;
  }
  else
  {
    *((float *)this + 7) = 0.0;
    *((float *)this + 6) = 0.0;
    _FP11 = result->mat[0].z;
    __asm { fsel      f10, f11, f13, f12 }
    *((float *)this + 8) = _FP10;
    this->x = 1.0;
    this->y = 0.0;
    this->z = 0.0;
    *((float *)this + 3) = 0.0;
    *((float *)this + 4) = _FP10;
    *((float *)this + 5) = 0.0;
  }
  return (idMat3 *)this;
}


// ========================================================================
// ?ToString@idVec3@@QBAPBDH@Z
// EA  : 0x82F3BE88
// RVA : 0x00F3BE88
// PDB : w:\tech5\shared\idlib\math\vector.cpp
// ========================================================================

const char *__fastcall idVec3::ToString(idAngles *this, int precision)
{
  return idStr::FloatArrayToString(array: &this->pitch, length: 3, precision);
}


// ========================================================================
// ?ProjectSelfOntoSphere@idVec3@@QAAXM@Z
// EA  : 0x82F3BE98
// RVA : 0x00F3BE98
// PDB : w:\tech5\shared\idlib\math\vector.cpp
// ========================================================================

void __fastcall idVec3::ProjectSelfOntoSphere(idVec3 *this, double radius)
{
  double v2; // fp0

  v2 = __fsqrts((float)((float)(this->z * this->z) + (float)((float)(this->x * this->x) + (float)(this->y * this->y))));
  if ( v2 >= (float)((float)((float)radius * (float)radius) * (float)0.5) )
  {
    if ( v2 <= idMath::FLT_SMALLEST_NON_DENORMAL )
      this->z = 0.0;
    else
      this->z = (float)((float)radius * (float)radius) / (float)((float)__fsqrts(v2) * (float)2.0);
  }
  else
  {
    this->z = __fsqrts((float)((float)((float)radius * (float)radius) - (float)v2));
  }
}


// ========================================================================
// ?RotateSelf@idVec3@@QAAABV1@ABV1@V?$idTypesafeNumber@MW4DegreesUnique_t@@@@@Z
// EA  : 0x82F3BF18
// RVA : 0x00F3BF18
// PDB : w:\tech5\shared\idlib\math\vector.cpp
// ========================================================================

const idVec3 *__fastcall idVec3::RotateSelf(
        idVec3 *this,
        const idVec3 *axis,
        idTypesafeNumber<float,enum DegreesUnique_t> *angle)
{
  double v3; // fp30
  double x; // fp2
  double y; // fp1
  double z; // fp31
  double v8; // fp13
  double v10; // fp12
  idRotation v11; // [sp+50h] [-80h] BYREF
  float v12; // [sp+94h] [-3Ch]
  float v13; // [sp+98h] [-38h]
  float v14; // [sp+9Ch] [-34h]
  char v15; // [sp+A0h] [-30h]

  v3 = -angle->value;
  x = axis->x;
  y = axis->y;
  z = axis->z;
  v15 = 0;
  v11.vec.y = vec3_origin.x;
  v11.axis.mat[0].x = x;
  v11.vec.z = vec3_origin.y;
  v11.axis.mat[0].y = y;
  v11.angle = vec3_origin.z;
  v11.axis.mat[0].z = z;
  v11.axis.mat[1].x = v3;
  v11.axis.mat[1].y = mat3_identity.mat[0].x;
  v11.axis.mat[1].z = mat3_identity.mat[0].y;
  v11.axis.mat[2].x = mat3_identity.mat[0].z;
  v11.axis.mat[2].y = mat3_identity.mat[1].x;
  v11.axis.mat[2].z = mat3_identity.mat[1].y;
  *(float *)&v11.axisValid = mat3_identity.mat[1].z;
  v12 = mat3_identity.mat[2].x;
  v13 = mat3_identity.mat[2].y;
  v14 = mat3_identity.mat[2].z;
  idRotation::operator*(this: &v11, result: (idRotation *)&v11.vec.y, v: this);
  v8 = v11.origin.y;
  v10 = v11.origin.z;
  this->x = v11.origin.x;
  this->y = v8;
  this->z = v10;
  return this;
}


// ========================================================================
// ?RotateCopy@idVec3@@QBA?AV1@ABV1@V?$idTypesafeNumber@MW4DegreesUnique_t@@@@@Z
// EA  : 0x82F3C018
// RVA : 0x00F3C018
// PDB : w:\tech5\shared\idlib\math\vector.cpp
// ========================================================================

idVec3 *__fastcall idVec3::RotateCopy(
        idVec3 *this,
        idVec3 *result,
        const idVec3 *axis,
        idTypesafeNumber<float,enum DegreesUnique_t> *angle)
{
  double v4; // fp30
  double x; // fp2
  double y; // fp1
  double z; // fp31
  idRotation v10; // [sp+50h] [-70h] BYREF

  v4 = -angle->value;
  x = axis->x;
  y = axis->y;
  z = axis->z;
  v10.axisValid = false;
  v10.origin.x = vec3_origin.x;
  v10.vec.x = x;
  v10.origin.y = vec3_origin.y;
  v10.vec.y = y;
  v10.origin.z = vec3_origin.z;
  v10.vec.z = z;
  v10.angle = v4;
  v10.axis.mat[0].x = mat3_identity.mat[0].x;
  v10.axis.mat[0].y = mat3_identity.mat[0].y;
  v10.axis.mat[0].z = mat3_identity.mat[0].z;
  v10.axis.mat[1].x = mat3_identity.mat[1].x;
  v10.axis.mat[1].y = mat3_identity.mat[1].y;
  v10.axis.mat[1].z = mat3_identity.mat[1].z;
  v10.axis.mat[2].x = mat3_identity.mat[2].x;
  v10.axis.mat[2].y = mat3_identity.mat[2].y;
  v10.axis.mat[2].z = mat3_identity.mat[2].z;
  idRotation::operator*((idRotation *)this, result: &v10, v: result);
  return this;
}


// ========================================================================
// ?ToString@idQuat@@QBAPBDH@Z
// EA  : 0x82F3C100
// RVA : 0x00F3C100
// PDB : w:\tech5\shared\idlib\math\vector.cpp
// ========================================================================

const char *__fastcall idQuat::ToString(idQuat *this, int precision)
{
  return idStr::FloatArrayToString(array: &this->x, length: 4, precision);
}


// ========================================================================
// ?ToYaw@idVec3@@QBAMABV1@@Z
// EA  : 0x82F3C110
// RVA : 0x00F3C110
// PDB : w:\tech5\shared\idlib\math\vector.cpp
// ========================================================================

float __fastcall idVec3::ToYaw(idVec3 *this, idMat3 *up)
{
  float *v2; // r3
  float *v3; // r6
  double v4; // fp0
  long double v5; // fp4
  double v6; // fp2
  double v7; // fp1
  double v8; // fp11
  double v9; // fp9
  double v10; // fp8
  double v11; // fp1
  idVec3 v13; // [sp+50h] [-40h] BYREF
  idVec3 v14[3]; // [sp+60h] [-30h] BYREF

  v2 = (float *)idVec3::ToZAxis(this: v14, result: up);
  v4 = v3[2];
  *((double *)&v5 + 1) = v2[3];
  *(double *)&v5 = v2[6];
  v6 = *v2;
  v7 = v2[5];
  v8 = v2[8];
  v9 = (float)((float)(v2[3] * *v3) + (float)(v2[4] * v3[1]));
  v10 = (float)((float)(v2[6] * *v3) + (float)(v2[7] * v3[1]));
  v13.x = (float)(*v2 * *v3) + (float)((float)(v2[1] * v3[1]) + (float)(v2[2] * v3[2]));
  v13.y = (float)((float)v7 * (float)v4) + (float)v9;
  v13.z = (float)((float)v8 * (float)v4) + (float)v10;
  v11 = idVec3::ToYaw(this: &v13, a2: v7, a3: v6, a4: v5);
  return *((float *)&v11 + 1);
}


// ========================================================================
// ?RotateSelf@idVec3@@QAAABV1@ABV1@V?$idTypesafeNumber@MW4RadiansUnique_t@@@@@Z
// EA  : 0x82F3C1A8
// RVA : 0x00F3C1A8
// PDB : w:\tech5\shared\idlib\math\vector.cpp
// ========================================================================

const idVec3 *__fastcall idVec3::RotateSelf(
        idVec3 *this,
        const idVec3 *axis,
        idTypesafeNumber<float,enum RadiansUnique_t> *angle)
{
  double v3; // fp9
  double x; // fp2
  double y; // fp1
  double z; // fp31
  double v8; // fp13
  double v10; // fp12
  idRotation v11; // [sp+50h] [-80h] BYREF
  float v12; // [sp+94h] [-3Ch]
  float v13; // [sp+98h] [-38h]
  float v14; // [sp+9Ch] [-34h]
  char v15; // [sp+A0h] [-30h]

  v3 = -angle->value;
  x = axis->x;
  y = axis->y;
  z = axis->z;
  v15 = 0;
  v11.vec.y = vec3_origin.x;
  v11.axis.mat[0].x = x;
  v11.axis.mat[0].y = y;
  v11.vec.z = vec3_origin.y;
  v11.axis.mat[0].z = z;
  v11.angle = vec3_origin.z;
  v11.axis.mat[1].y = mat3_identity.mat[0].x;
  v11.axis.mat[1].z = mat3_identity.mat[0].y;
  v11.axis.mat[2].x = mat3_identity.mat[0].z;
  v11.axis.mat[2].y = mat3_identity.mat[1].x;
  v11.axis.mat[2].z = mat3_identity.mat[1].y;
  *(float *)&v11.axisValid = mat3_identity.mat[1].z;
  v12 = mat3_identity.mat[2].x;
  v11.axis.mat[1].x = (float)v3 * idMath::M_RAD2DEG;
  v13 = mat3_identity.mat[2].y;
  v14 = mat3_identity.mat[2].z;
  idRotation::operator*(this: &v11, result: (idRotation *)&v11.vec.y, v: this);
  v8 = v11.origin.y;
  v10 = v11.origin.z;
  this->x = v11.origin.x;
  this->y = v8;
  this->z = v10;
  return this;
}


// ========================================================================
// `dynamic initializer for 'vec3_infinity''
// EA  : 0x83395DC8
// RVA : 0x01395DC8
// PDB : w:\tech5\shared\idlib\math\vector.cpp
// ========================================================================

void _dynamic_initializer_for__vec3_infinity__()
{
  vec3_infinity.x = 1.0e30;
  vec3_infinity.y = 1.0e30;
  vec3_infinity.z = 1.0e30;
}


// ========================================================================
// `dynamic initializer for 'vec6_infinity''
// EA  : 0x83395DE8
// RVA : 0x01395DE8
// PDB : w:\tech5\shared\idlib\math\vector.cpp
// ========================================================================

void _dynamic_initializer_for__vec6_infinity__()
{
  vec6_infinity.p[0] = 1.0e30;
  vec6_infinity.p[1] = 1.0e30;
  vec6_infinity.p[2] = 1.0e30;
  vec6_infinity.p[3] = 1.0e30;
  vec6_infinity.p[4] = 1.0e30;
  vec6_infinity.p[5] = 1.0e30;
}

