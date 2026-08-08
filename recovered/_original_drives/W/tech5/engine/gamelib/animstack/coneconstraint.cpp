
// ========================================================================
// ??0idConeConstraint_Vec3@@QAA@ABV0@@Z
// EA  : 0x826F9268
// RVA : 0x006F9268
// PDB : w:\tech5\engine\gamelib\animstack\coneconstraint.cpp
// ========================================================================

idConeConstraint_Vec3 *__fastcall idConeConstraint_Vec3::idConeConstraint_Vec3(
        idConeConstraint_Vec3 *this,
        const idConeConstraint_Vec3 *other)
{
  *this = *other;
  return this;
}


// ========================================================================
// ??0idConeConstraint_Quat@@QAA@ABV0@@Z
// EA  : 0x826F92B8
// RVA : 0x006F92B8
// PDB : w:\tech5\engine\gamelib\animstack\coneconstraint.cpp
// ========================================================================

idConeConstraint_Quat *__fastcall idConeConstraint_Quat::idConeConstraint_Quat(
        idConeConstraint_Quat *this,
        const idConeConstraint_Quat *other)
{
  *this = *other;
  return this;
}


// ========================================================================
// ??0idConeConstraint_Vec3@@QAA@ABVidVec3@@V?$idTypesafeNumber@MW4RadiansUnique_t@@@@@Z
// EA  : 0x826F9318
// RVA : 0x006F9318
// PDB : w:\tech5\engine\gamelib\animstack\coneconstraint.cpp
// ========================================================================

idConeConstraint_Vec3 *__fastcall idConeConstraint_Vec3::idConeConstraint_Vec3(
        idConeConstraint_Vec3 *this,
        const idVec3 *center_,
        const idTypesafeNumber<float,enum RadiansUnique_t> *maxAngle_,
        long double a4)
{
  long double v6; // fp2
  long double v7; // fp2
  long double v8; // fp2

  this->current = *center_;
  this->center = *center_;
  *(double *)&a4 = maxAngle_->value;
  v6 = cos(x: a4);
  this->limitAngleDot = *(double *)&v6;
  *(double *)&v6 = (float)(maxAngle_->value * (float)0.5);
  v7 = cos(x: v6);
  this->halfLimitAngleCosine = *(double *)&v7;
  *(double *)&v7 = (float)(maxAngle_->value * (float)0.5);
  v8 = sin(x: v7);
  this->halfLimitAngleSine = *(double *)&v8;
  return this;
}


// ========================================================================
// ?RotateTo@idConeConstraint_Vec3@@QAAXABVidVec3@@M@Z
// EA  : 0x826F93C8
// RVA : 0x006F93C8
// PDB : w:\tech5\engine\gamelib\animstack\coneconstraint.cpp
// ========================================================================

void __fastcall idConeConstraint_Vec3::RotateTo(idConeConstraint_Vec3 *this, const idVec3 *dir, double lerpRate)
{
  double x; // fp0
  double z; // fp12
  idVec3 *p_center; // r30
  double halfLimitAngleCosine; // fp2
  double halfLimitAngleSine; // fp1
  double v10; // fp4
  double v11; // fp3
  double v12; // fp0
  double v15; // fp6
  double v16; // fp7
  double v17; // fp6
  double y; // fp13
  double v19; // fp9
  double v20; // fp7
  double v21; // fp4
  double v22; // fp3
  double v23; // fp2
  double v24; // fp1
  double v25; // fp13
  double v26; // fp10
  double v29; // fp7
  double v30; // fp6
  double v31; // fp10
  double v32; // fp7
  idVec3 v33; // [sp+50h] [-70h] BYREF
  idMat3 v34; // [sp+60h] [-60h] BYREF

  x = dir->x;
  z = dir->z;
  p_center = &this->center;
  if ( (float)((float)(this->center.z * dir->z)
             + (float)((float)(this->center.y * dir->y) + (float)(this->center.x * dir->x))) >= (double)this->limitAngleDot )
  {
    y = dir->y;
  }
  else
  {
    halfLimitAngleCosine = this->halfLimitAngleCosine;
    halfLimitAngleSine = this->halfLimitAngleSine;
    v10 = (float)((float)(this->center.z * dir->y) - (float)(this->center.y * dir->z));
    v11 = (float)((float)(this->center.x * dir->z) - (float)(this->center.z * dir->x));
    v12 = (float)((float)(this->center.y * dir->x) - (float)(this->center.x * dir->y));
    _FP9 = (float)((float)((float)((float)v11 * (float)v11)
                         + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f7, f9, f10, f12 }
    v15 = __frsqrte(_FP7);
    v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                        * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10)))
                                                                                                * (float)0.5))
                                                                                * (float)v15)
                                                                        - (float)1.5)
                                                        * (float)v15)
                                                * (float)((float)((float)((float)v11 * (float)v11)
                                                                + (float)((float)((float)v12 * (float)v12)
                                                                        + (float)((float)v10 * (float)v10)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v15
                                                                                * (float)((float)((float)((float)v11 * (float)v11)
                                                                                                + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10)))
                                                                                        * (float)0.5))
                                                                        * (float)v15)
                                                                - (float)1.5)
                                                * (float)v15))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v15
                                                        * (float)((float)((float)((float)v11 * (float)v11)
                                                                        + (float)((float)((float)v12 * (float)v12)
                                                                                + (float)((float)v10 * (float)v10)))
                                                                * (float)0.5))
                                                * (float)v15)
                                        - (float)1.5)
                        * (float)v15));
    v17 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                                * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5))
                                                                                        * (float)v15)
                                                                                - (float)1.5)
                                                                * (float)v15)
                                                        * (float)((float)((float)((float)v11 * (float)v11)
                                                                        + (float)((float)((float)v12 * (float)v12)
                                                                                + (float)((float)v10 * (float)v10)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v15
                                                                                        * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10)))
                                                                                                * (float)0.5))
                                                                                * (float)v15)
                                                                        - (float)1.5)
                                                        * (float)v15))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v15
                                                                * (float)((float)((float)((float)v11 * (float)v11)
                                                                                + (float)((float)((float)v12 * (float)v12)
                                                                                        + (float)((float)v10 * (float)v10)))
                                                                        * (float)0.5))
                                                        * (float)v15)
                                                - (float)1.5)
                                * (float)v15))
                * (float)((float)((float)((float)v11 * (float)v11)
                                + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10)))
                        * (float)0.5));
    v33.x = (float)((float)(this->center.z * dir->y) - (float)(this->center.y * dir->z))
          * (float)((float)-(float)((float)((float)v17 * (float)v16) - (float)1.5) * (float)v16);
    v33.y = (float)((float)-(float)((float)((float)v17 * (float)v16) - (float)1.5) * (float)v16) * (float)v11;
    v33.z = (float)v12 * (float)((float)-(float)((float)((float)v17 * (float)v16) - (float)1.5) * (float)v16);
    idMat3::idMat3(this: &v34, axis: &v33, sineHalfAngle: halfLimitAngleSine, cosineHalfAngle: halfLimitAngleCosine);
    x = (float)((float)(p_center->x * v34.mat[0].x)
              + (float)((float)(p_center->z * v34.mat[2].x) + (float)(p_center->y * v34.mat[1].x)));
    y = (float)((float)(p_center->x * v34.mat[0].y)
              + (float)((float)(p_center->z * v34.mat[2].y) + (float)(p_center->y * v34.mat[1].y)));
    z = (float)((float)(p_center->x * v34.mat[0].z)
              + (float)((float)(p_center->z * v34.mat[2].z) + (float)(p_center->y * v34.mat[1].z)));
  }
  v19 = this->current.z;
  v20 = this->current.x;
  v21 = (float)((float)((float)z - this->current.z) * (float)lerpRate);
  v22 = (float)((float)((float)x - this->current.x) * (float)lerpRate);
  v23 = (float)(this->current.y + (float)((float)((float)y - this->current.y) * (float)lerpRate));
  this->current.y = this->current.y + (float)((float)((float)y - this->current.y) * (float)lerpRate);
  v24 = (float)((float)v19 + (float)v21);
  this->current.z = (float)v19 + (float)v21;
  v25 = (float)((float)v20 + (float)v22);
  this->current.x = (float)v20 + (float)v22;
  v26 = (float)((float)((float)((float)v20 + (float)v22) * (float)((float)v20 + (float)v22))
              + (float)((float)((float)((float)v19 + (float)v21) * (float)((float)v19 + (float)v21))
                      + (float)((float)v23 * (float)v23)));
  _FP9 = (float)((float)((float)((float)((float)v20 + (float)v22) * (float)((float)v20 + (float)v22))
                       + (float)((float)((float)((float)v19 + (float)v21) * (float)((float)v19 + (float)v21))
                               + (float)((float)v23 * (float)v23)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f8, f9, f10, f0 }
  v29 = (float)((float)v26 * (float)0.5);
  v30 = __frsqrte(_FP8);
  v31 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30
                                                                                      * (float)((float)v26 * (float)0.5))
                                                                              * (float)v30)
                                                                      - (float)1.5)
                                                      * (float)v30)
                                              * (float)((float)v26 * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v30
                                                                              * (float)((float)v26 * (float)0.5))
                                                                      * (float)v30)
                                                              - (float)1.5)
                                              * (float)v30))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)v26 * (float)0.5)) * (float)v30)
                                      - (float)1.5)
                      * (float)v30));
  v32 = (float)((float)-(float)((float)((float)((float)v31 * (float)v29) * (float)v31) - (float)1.5) * (float)v31);
  this->current.x = (float)v25 * (float)v32;
  this->current.y = (float)v23 * (float)v32;
  this->current.z = (float)v24 * (float)v32;
}


// ========================================================================
// ??0idConeConstraint_Quat@@QAA@ABVidQuat@@V?$idTypesafeNumber@MW4RadiansUnique_t@@@@@Z
// EA  : 0x826F95E0
// RVA : 0x006F95E0
// PDB : w:\tech5\engine\gamelib\animstack\coneconstraint.cpp
// ========================================================================

idConeConstraint_Quat *__fastcall idConeConstraint_Quat::idConeConstraint_Quat(
        idConeConstraint_Quat *this,
        const idQuat *center_,
        const idTypesafeNumber<float,enum RadiansUnique_t> *maxAngle_,
        long double a4)
{
  long double v6; // fp2
  long double v7; // fp2
  long double v8; // fp2

  this->current = *center_;
  this->center = *center_;
  *(double *)&a4 = maxAngle_->value;
  v6 = cos(x: a4);
  this->limitAngleDot = *(double *)&v6;
  *(double *)&v6 = (float)(maxAngle_->value * (float)0.5);
  v7 = cos(x: v6);
  this->halfLimitAngleCosine = *(double *)&v7;
  *(double *)&v7 = (float)(maxAngle_->value * (float)0.5);
  v8 = sin(x: v7);
  this->halfLimitAngleSine = *(double *)&v8;
  return this;
}


// ========================================================================
// ?RotateTo@idConeConstraint_Quat@@QAAXABVidVec3@@M@Z
// EA  : 0x826F96A8
// RVA : 0x006F96A8
// PDB : w:\tech5\engine\gamelib\animstack\coneconstraint.cpp
// ========================================================================

void __fastcall idConeConstraint_Quat::RotateTo(idConeConstraint_Quat *this, const idVec3 *dir, double lerpRate)
{
  double z; // fp13
  double y; // fp12
  double x; // fp30
  double v9; // fp29
  double v10; // fp28
  double v11; // fp11
  double v12; // fp0
  double v13; // fp12
  double v14; // fp31
  double v15; // fp27
  double v16; // fp13
  double v17; // fp12
  double v18; // fp3
  double v19; // fp4
  double v20; // fp2
  double v21; // fp7
  double v22; // fp6
  double v23; // fp5
  idVec3 *v24; // r3
  double v25; // fp13
  double v26; // fp12
  double v27; // fp10
  double v28; // fp2
  double v29; // fp28
  double v30; // fp11
  double v31; // fp8
  double v32; // fp9
  double v35; // fp10
  double v36; // fp7
  double v37; // fp13
  double v38; // fp12
  double v39; // fp11
  double v40; // fp10
  double v41; // fp9
  double v42; // fp12
  double v43; // fp8
  double v44; // fp7
  idQuat v45; // [sp+50h] [-80h] BYREF
  idQuat v46; // [sp+60h] [-70h] BYREF
  idQuat v47; // [sp+70h] [-60h] BYREF

  idQuat::ToForward(this: &v46, result: (idVec3 *)this);
  z = dir->z;
  y = dir->y;
  x = v46.x;
  v9 = v46.z;
  v10 = v46.y;
  v11 = (float)((float)(dir->y * v46.y) + (float)((float)(dir->z * v46.z) + (float)(dir->x * v46.x)));
  if ( v11 > -1.0 && v11 < 1.0 )
  {
    v45.x = (float)((float)(dir->x - v46.x) * (float)((float)lerpRate * (float)0.5)) + v46.x;
    v45.y = (float)((float)((float)y - v46.y) * (float)((float)lerpRate * (float)0.5)) + v46.y;
    v45.z = (float)((float)((float)z - v46.z) * (float)((float)lerpRate * (float)0.5)) + v46.z;
    idVec3::NormalizeFast(this: (idVec3 *)&v45);
    v12 = v45.y;
    v13 = v45.x;
    v14 = (float)((float)(v45.x * (float)x) + (float)((float)(v45.z * (float)v9) + (float)(v45.y * (float)v10)));
    if ( v14 < 1.0 )
      v15 = __fsqrts((float)-(float)((float)((float)v14 * (float)v14) - (float)1.0));
    else
      v15 = 0.0;
    v45.x = (float)(v45.y * (float)v9) - (float)(v45.z * (float)v10);
    v45.y = (float)(v45.z * (float)x) - (float)((float)v9 * (float)v13);
    v45.z = (float)((float)v13 * (float)v10) - (float)((float)v12 * (float)x);
    idVec3::NormalizeFast(this: (idVec3 *)&v45);
    v16 = (float)(v45.x * (float)v15);
    v17 = (float)(v45.z * (float)v15);
    v18 = this->current.z;
    v19 = this->current.x;
    v20 = this->current.y;
    v21 = (float)((float)(this->current.y * (float)v14)
                + (float)((float)(this->current.w * (float)(v45.y * (float)v15))
                        + (float)(this->current.z * (float)(v45.x * (float)v15))));
    v22 = (float)((float)(this->current.z * (float)v14)
                + (float)((float)(this->current.x * (float)(v45.y * (float)v15))
                        + (float)(this->current.w * (float)(v45.z * (float)v15))));
    v23 = (float)-(float)((float)(this->current.y * (float)(v45.y * (float)v15))
                        - (float)((float)(this->current.w * (float)v14)
                                - (float)(this->current.x * (float)(v45.x * (float)v15))));
    this->current.x = -(float)((float)(this->current.z * (float)(v45.y * (float)v15))
                             - (float)((float)(this->current.x * (float)v14)
                                     + (float)((float)(this->current.y * (float)(v45.z * (float)v15))
                                             + (float)(this->current.w * (float)(v45.x * (float)v15)))));
    this->current.y = -(float)((float)((float)v19 * (float)v17) - (float)v21);
    this->current.z = -(float)((float)((float)v20 * (float)v16) - (float)v22);
    this->current.w = -(float)((float)((float)v18 * (float)v17) - (float)v23);
    idQuat::Normalize(this: &this->current);
  }
  idQuat::ToForward(this: &v47, result: (idVec3 *)&this->center);
  v24 = idQuat::ToForward(this: &v45, result: (idVec3 *)this);
  v25 = v24->x;
  v46.x = v25;
  v26 = v24->y;
  v27 = (float)(v47.y * v24->y);
  v46.y = v24->y;
  if ( (float)((float)(v47.x * (float)v25) + (float)((float)(v47.z * v24->z) + (float)v27)) < (double)this->limitAngleDot )
  {
    v28 = this->center.y;
    v29 = this->center.z;
    v30 = (float)((float)(v24->z * v47.x) - (float)(v47.z * (float)v25));
    v31 = (float)((float)(v47.z * (float)v26) - (float)(v47.y * v24->z));
    v32 = (float)((float)(v47.y * (float)v25) - (float)(v47.x * (float)v26));
    _FP4 = (float)((float)((float)((float)v31 * (float)v31)
                         + (float)((float)((float)v32 * (float)v32) + (float)((float)v30 * (float)v30)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f12, f4, f5, f10 }
    v35 = __frsqrte(_FP12);
    v36 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v35
                                                                                        * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v32 * (float)v32) + (float)((float)v30 * (float)v30)))
                                                                                                * (float)0.5))
                                                                                * (float)v35)
                                                                        - (float)1.5)
                                                        * (float)v35)
                                                * (float)((float)((float)((float)v31 * (float)v31)
                                                                + (float)((float)((float)v32 * (float)v32)
                                                                        + (float)((float)v30 * (float)v30)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v35
                                                                                * (float)((float)((float)((float)v31 * (float)v31)
                                                                                                + (float)((float)((float)v32 * (float)v32) + (float)((float)v30 * (float)v30)))
                                                                                        * (float)0.5))
                                                                        * (float)v35)
                                                                - (float)1.5)
                                                * (float)v35))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v35
                                                        * (float)((float)((float)((float)v31 * (float)v31)
                                                                        + (float)((float)((float)v32 * (float)v32)
                                                                                + (float)((float)v30 * (float)v30)))
                                                                * (float)0.5))
                                                * (float)v35)
                                        - (float)1.5)
                        * (float)v35));
    v37 = (float)((float)v30
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v35 * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v32 * (float)v32) + (float)((float)v30 * (float)v30))) * (float)0.5)) * (float)v35) - (float)1.5) * (float)v35)
                                                                                                * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v32 * (float)v32) + (float)((float)v30 * (float)v30))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v35 * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v32 * (float)v32) + (float)((float)v30 * (float)v30))) * (float)0.5)) * (float)v35) - (float)1.5)
                                                                                                * (float)v35))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v35 * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v32 * (float)v32) + (float)((float)v30 * (float)v30))) * (float)0.5))
                                                                                                * (float)v35)
                                                                                        - (float)1.5)
                                                                        * (float)v35))
                                                        * (float)((float)((float)((float)v31 * (float)v31)
                                                                        + (float)((float)((float)v32 * (float)v32)
                                                                                + (float)((float)v30 * (float)v30)))
                                                                * (float)0.5))
                                                * (float)v36)
                                        - (float)1.5)
                        * (float)v36));
    v38 = (float)((float)v32
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v35 * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v32 * (float)v32) + (float)((float)v30 * (float)v30))) * (float)0.5)) * (float)v35) - (float)1.5) * (float)v35)
                                                                                                * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v32 * (float)v32) + (float)((float)v30 * (float)v30))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v35 * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v32 * (float)v32) + (float)((float)v30 * (float)v30))) * (float)0.5)) * (float)v35) - (float)1.5)
                                                                                                * (float)v35))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v35 * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v32 * (float)v32) + (float)((float)v30 * (float)v30))) * (float)0.5))
                                                                                                * (float)v35)
                                                                                        - (float)1.5)
                                                                        * (float)v35))
                                                        * (float)((float)((float)((float)v31 * (float)v31)
                                                                        + (float)((float)((float)v32 * (float)v32)
                                                                                + (float)((float)v30 * (float)v30)))
                                                                * (float)0.5))
                                                * (float)v36)
                                        - (float)1.5)
                        * (float)v36));
    v39 = (float)(this->halfLimitAngleSine
                * (float)((float)v31
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v35 * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v32 * (float)v32) + (float)((float)v30 * (float)v30))) * (float)0.5)) * (float)v35) - (float)1.5) * (float)v35) * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v32 * (float)v32) + (float)((float)v30 * (float)v30))) * (float)0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v35 * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v32 * (float)v32) + (float)((float)v30 * (float)v30))) * (float)0.5)) * (float)v35) - (float)1.5) * (float)v35))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v35 * (float)((float)((float)((float)v31 * (float)v31) + (float)((float)((float)v32 * (float)v32) + (float)((float)v30 * (float)v30))) * (float)0.5)) * (float)v35)
                                                                                                - (float)1.5)
                                                                                * (float)v35))
                                                                * (float)((float)((float)((float)v31 * (float)v31)
                                                                                + (float)((float)((float)v32 * (float)v32)
                                                                                        + (float)((float)v30 * (float)v30)))
                                                                        * (float)0.5))
                                                        * (float)v36)
                                                - (float)1.5)
                                * (float)v36)));
    v40 = (float)((float)v37 * this->halfLimitAngleSine);
    v41 = (float)((float)v38 * this->halfLimitAngleSine);
    v43 = (float)((float)(this->center.w * (float)((float)v38 * this->halfLimitAngleSine))
                + (float)((float)(this->center.z * this->halfLimitAngleCosine)
                        + (float)(this->center.x * (float)((float)v37 * this->halfLimitAngleSine))));
    v44 = (float)((float)(this->center.w * (float)v39)
                + (float)((float)(this->center.x * this->halfLimitAngleCosine)
                        + (float)(this->center.y * (float)((float)v38 * this->halfLimitAngleSine))));
    v42 = (float)-(float)((float)(this->center.y * (float)((float)v37 * this->halfLimitAngleSine))
                        - (float)((float)(this->center.w * this->halfLimitAngleCosine)
                                - (float)(this->center.x * (float)v39)));
    this->current.y = -(float)((float)(this->center.x * (float)v41)
                             - (float)((float)(this->center.z * (float)v39)
                                     + (float)((float)(this->center.w * (float)((float)v37 * this->halfLimitAngleSine))
                                             + (float)(this->center.y * this->halfLimitAngleCosine))));
    this->current.w = -(float)((float)((float)v29 * (float)v41) - (float)v42);
    this->current.z = -(float)((float)((float)v28 * (float)v39) - (float)v43);
    this->current.x = -(float)((float)((float)v29 * (float)v40) - (float)v44);
    idQuat::Normalize(this: &this->current);
  }
}

