
// ========================================================================
// ??1idRotationTracker@@UAA@XZ
// EA  : 0x82B00768
// RVA : 0x00B00768
// PDB : w:\tech5\tungsten\game\ai\rotationtracker.cpp
// ========================================================================

void __fastcall idRotationTracker::~idRotationTracker(idRotationTracker *this)
{
  this->__vftable = (idRotationTracker_vtbl *)&idRotationTracker::`vftable';
}


// ========================================================================
// ??0idRotationTracker@@QAA@XZ
// EA  : 0x82B00778
// RVA : 0x00B00778
// PDB : w:\tech5\tungsten\game\ai\rotationtracker.cpp
// ========================================================================

idRotationTracker *__fastcall idRotationTracker::idRotationTracker(idRotationTracker *this, long double a2)
{
  long double v3; // fp2
  long double v4; // fp2
  long double v5; // fp2
  long double v6; // fp2

  this->__vftable = (idRotationTracker_vtbl *)&idRotationTracker::`vftable';
  this->rot = quat_identity;
  this->maxPitch.value = (float)3.1415927 * (float)0.5;
  this->maxYaw.value = (float)3.1415927 * (float)0.5;
  *(double *)&a2 = this->maxPitch.value;
  v3 = cos(x: a2);
  this->maxPitchDot = *(double *)&v3;
  *(double *)&v3 = this->maxYaw.value;
  v4 = cos(x: v3);
  this->maxYawDot = *(double *)&v4;
  *(double *)&v4 = (float)(this->maxPitch.value * (float)0.5);
  v5 = cos(x: v4);
  this->halfMaxPitchDot = *(double *)&v5;
  *(double *)&v5 = (float)(this->maxYaw.value * (float)0.5);
  v6 = cos(x: v5);
  this->halfMaxYawDot = *(double *)&v6;
  this->maxVelocity.value = 3.1415927 * (float)8.0;
  this->velocity.value = 0.0;
  this->acceleration.value = 3.1415927 * (float)8.0;
  this->deceleration.value = 3.1415927 * (float)8.0;
  this->projectWhenBehind = true;
  this->clampedYaw = false;
  this->clampedPitch = false;
  return this;
}


// ========================================================================
// ClampOnAxis
// EA  : 0x82B00900
// RVA : 0x00B00900
// PDB : w:\tech5\tungsten\game\ai\rotationtracker.cpp
// ========================================================================

void __fastcall ClampOnAxis(
        const idVec3 *rotAxis,
        const idVec3 *refAxis,
        const idVec3 *idealDir,
        double maxDot,
        double halfMaxDot,
        idQuat *rot,
        float *dot,
        float *clamped,
        float *a9,
        char *a10)
{
  float y; // r9
  float z; // r8
  double v20; // fp0
  double v21; // fp9
  double v22; // fp29
  double v23; // fp28
  double v24; // fp27
  double v25; // fp0
  char v26; // r11
  double v27; // fp0
  double x; // fp25
  double v29; // fp9
  double v30; // fp4
  double v31; // fp12
  double v32; // fp9
  double v33; // fp7
  double v34; // fp13
  double v35; // fp1
  double v36; // fp4
  double v37; // fp3
  double v38; // fp2
  double v41; // fp7
  double v42; // fp10
  double v43; // fp7
  idVec3 v44[6]; // [sp+50h] [-80h] BYREF

  y = idealDir->y;
  z = idealDir->z;
  v44[0].x = idealDir->x;
  v44[0].y = y;
  v44[0].z = z;
  idVec3::ProjectOntoPlane(this: v44, normal: rotAxis, overBounce: 1.0);
  _FP3 = (float)((float)((float)(v44[0].x * v44[0].x)
                       + (float)((float)(v44[0].z * v44[0].z) + (float)(v44[0].y * v44[0].y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f1, f3, f4, f0 }
  v20 = __frsqrte(_FP1);
  v21 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20
                                                                                      * (float)((float)((float)(v44[0].x * v44[0].x) + (float)((float)(v44[0].z * v44[0].z) + (float)(v44[0].y * v44[0].y)))
                                                                                              * (float)0.5))
                                                                              * (float)v20)
                                                                      - (float)1.5)
                                                      * (float)v20)
                                              * (float)((float)((float)(v44[0].x * v44[0].x)
                                                              + (float)((float)(v44[0].z * v44[0].z)
                                                                      + (float)(v44[0].y * v44[0].y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v20
                                                                              * (float)((float)((float)(v44[0].x * v44[0].x)
                                                                                              + (float)((float)(v44[0].z * v44[0].z) + (float)(v44[0].y * v44[0].y)))
                                                                                      * (float)0.5))
                                                                      * (float)v20)
                                                              - (float)1.5)
                                              * (float)v20))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v20
                                                      * (float)((float)((float)(v44[0].x * v44[0].x)
                                                                      + (float)((float)(v44[0].z * v44[0].z)
                                                                              + (float)(v44[0].y * v44[0].y)))
                                                              * (float)0.5))
                                              * (float)v20)
                                      - (float)1.5)
                      * (float)v20));
  v22 = (float)(v44[0].x
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v44[0].x * v44[0].x) + (float)((float)(v44[0].z * v44[0].z) + (float)(v44[0].y * v44[0].y))) * (float)0.5)) * (float)v20) - (float)1.5) * (float)v20)
                                                                                              * (float)((float)((float)(v44[0].x * v44[0].x) + (float)((float)(v44[0].z * v44[0].z) + (float)(v44[0].y * v44[0].y))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v44[0].x * v44[0].x) + (float)((float)(v44[0].z * v44[0].z) + (float)(v44[0].y * v44[0].y))) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                              * (float)v20))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v44[0].x * v44[0].x) + (float)((float)(v44[0].z * v44[0].z) + (float)(v44[0].y * v44[0].y))) * (float)0.5))
                                                                                              * (float)v20)
                                                                                      - (float)1.5)
                                                                      * (float)v20))
                                                      * (float)((float)((float)(v44[0].x * v44[0].x)
                                                                      + (float)((float)(v44[0].z * v44[0].z)
                                                                              + (float)(v44[0].y * v44[0].y)))
                                                              * (float)0.5))
                                              * (float)v21)
                                      - (float)1.5)
                      * (float)v21));
  v23 = (float)(v44[0].z
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v44[0].x * v44[0].x) + (float)((float)(v44[0].z * v44[0].z) + (float)(v44[0].y * v44[0].y))) * (float)0.5)) * (float)v20) - (float)1.5) * (float)v20)
                                                                                              * (float)((float)((float)(v44[0].x * v44[0].x) + (float)((float)(v44[0].z * v44[0].z) + (float)(v44[0].y * v44[0].y))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v44[0].x * v44[0].x) + (float)((float)(v44[0].z * v44[0].z) + (float)(v44[0].y * v44[0].y))) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                              * (float)v20))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v44[0].x * v44[0].x) + (float)((float)(v44[0].z * v44[0].z) + (float)(v44[0].y * v44[0].y))) * (float)0.5))
                                                                                              * (float)v20)
                                                                                      - (float)1.5)
                                                                      * (float)v20))
                                                      * (float)((float)((float)(v44[0].x * v44[0].x)
                                                                      + (float)((float)(v44[0].z * v44[0].z)
                                                                              + (float)(v44[0].y * v44[0].y)))
                                                              * (float)0.5))
                                              * (float)v21)
                                      - (float)1.5)
                      * (float)v21));
  v24 = (float)(v44[0].y
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v44[0].x * v44[0].x) + (float)((float)(v44[0].z * v44[0].z) + (float)(v44[0].y * v44[0].y))) * (float)0.5)) * (float)v20) - (float)1.5) * (float)v20)
                                                                                              * (float)((float)((float)(v44[0].x * v44[0].x) + (float)((float)(v44[0].z * v44[0].z) + (float)(v44[0].y * v44[0].y))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v44[0].x * v44[0].x) + (float)((float)(v44[0].z * v44[0].z) + (float)(v44[0].y * v44[0].y))) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                              * (float)v20))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v44[0].x * v44[0].x) + (float)((float)(v44[0].z * v44[0].z) + (float)(v44[0].y * v44[0].y))) * (float)0.5))
                                                                                              * (float)v20)
                                                                                      - (float)1.5)
                                                                      * (float)v20))
                                                      * (float)((float)((float)(v44[0].x * v44[0].x)
                                                                      + (float)((float)(v44[0].z * v44[0].z)
                                                                              + (float)(v44[0].y * v44[0].y)))
                                                              * (float)0.5))
                                              * (float)v21)
                                      - (float)1.5)
                      * (float)v21));
  v25 = (float)((float)(refAxis->y * (float)v24)
              + (float)((float)(refAxis->z * (float)v23)
                      + (float)(refAxis->x
                              * (float)(v44[0].x
                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v44[0].x * v44[0].x) + (float)((float)(v44[0].z * v44[0].z) + (float)(v44[0].y * v44[0].y))) * (float)0.5)) * (float)v20) - (float)1.5) * (float)v20) * (float)((float)((float)(v44[0].x * v44[0].x) + (float)((float)(v44[0].z * v44[0].z) + (float)(v44[0].y * v44[0].y))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v44[0].x * v44[0].x) + (float)((float)(v44[0].z * v44[0].z) + (float)(v44[0].y * v44[0].y))) * (float)0.5)) * (float)v20) - (float)1.5) * (float)v20)) - (float)1.5)
                                                                                      * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v44[0].x * v44[0].x) + (float)((float)(v44[0].z * v44[0].z) + (float)(v44[0].y * v44[0].y))) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                              * (float)v20))
                                                                              * (float)((float)((float)(v44[0].x * v44[0].x)
                                                                                              + (float)((float)(v44[0].z * v44[0].z) + (float)(v44[0].y * v44[0].y)))
                                                                                      * (float)0.5))
                                                                      * (float)v21)
                                                              - (float)1.5)
                                              * (float)v21)))));
  *a9 = v25;
  if ( v25 > 0.99989998 )
  {
    *(idQuat *)clamped = quat_identity;
    *a10 = 0;
    *a9 = 1.0;
    return;
  }
  if ( v25 < -0.99989998 )
  {
    if ( v25 < maxDot )
    {
      *(idQuat *)clamped = quat_identity;
      *a10 = 0;
      *a9 = -1.0;
      return;
    }
    goto LABEL_8;
  }
  if ( v25 >= maxDot )
  {
LABEL_8:
    x = refAxis->x;
    v29 = (float)((float)((float)v22 - refAxis->x) * (float)0.5);
    v30 = (float)(refAxis->z + (float)((float)((float)v23 - refAxis->z) * (float)0.5));
    v44[0].y = refAxis->y + (float)((float)((float)v24 - refAxis->y) * (float)0.5);
    v44[0].z = v30;
    v44[0].x = (float)x + (float)v29;
    idVec3::NormalizeFast(this: v44);
    v26 = 0;
    v27 = (float)((float)((float)x * v44[0].x) + (float)((float)(refAxis->z * v44[0].z) + (float)(refAxis->y * v44[0].y)));
    goto LABEL_9;
  }
  *a9 = maxDot;
  v26 = 1;
  v27 = halfMaxDot;
LABEL_9:
  *a10 = v26;
  v31 = refAxis->z;
  v32 = refAxis->x;
  v33 = refAxis->y;
  v34 = idMath::FLT_SMALLEST_NON_DENORMAL;
  clamped[3] = v27;
  v35 = __fsqrts(__fabs((float)-(float)((float)((float)v27 * (float)v27) - (float)1.0)));
  v36 = (float)((float)((float)v32 * (float)v23) - (float)((float)v31 * (float)v22));
  v37 = (float)((float)((float)v33 * (float)v22) - (float)((float)v32 * (float)v24));
  v38 = (float)((float)((float)v31 * (float)v24) - (float)((float)v33 * (float)v23));
  _FP10 = (float)((float)((float)((float)v38 * (float)v38)
                        + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36)))
                - (float)v34);
  __asm { fsel      f8, f10, f11, f13 }
  v41 = __frsqrte(_FP8);
  v42 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41
                                                                                      * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36)))
                                                                                              * (float)0.5))
                                                                              * (float)v41)
                                                                      - (float)1.5)
                                                      * (float)v41)
                                              * (float)((float)((float)((float)v38 * (float)v38)
                                                              + (float)((float)((float)v37 * (float)v37)
                                                                      + (float)((float)v36 * (float)v36)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v41
                                                                              * (float)((float)((float)((float)v38 * (float)v38)
                                                                                              + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36)))
                                                                                      * (float)0.5))
                                                                      * (float)v41)
                                                              - (float)1.5)
                                              * (float)v41))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v41
                                                      * (float)((float)((float)((float)v38 * (float)v38)
                                                                      + (float)((float)((float)v37 * (float)v37)
                                                                              + (float)((float)v36 * (float)v36)))
                                                              * (float)0.5))
                                              * (float)v41)
                                      - (float)1.5)
                      * (float)v41));
  v43 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36))) * (float)0.5)) * (float)v41) - (float)1.5)
                                                                                              * (float)v41)
                                                                                      * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36))) * (float)0.5)) * (float)v41) - (float)1.5)
                                                                                      * (float)v41))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v41
                                                                                              * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36))) * (float)0.5))
                                                                                      * (float)v41)
                                                                              - (float)1.5)
                                                              * (float)v41))
                                              * (float)((float)((float)((float)v38 * (float)v38)
                                                              + (float)((float)((float)v37 * (float)v37)
                                                                      + (float)((float)v36 * (float)v36)))
                                                      * (float)0.5))
                                      * (float)v42)
                              - (float)1.5)
              * (float)v42);
  *clamped = (float)v35 * (float)((float)v38 * (float)v43);
  clamped[1] = (float)((float)((float)((float)v32 * (float)v23) - (float)((float)v31 * (float)v22)) * (float)v43)
             * (float)v35;
  clamped[2] = (float)((float)v37 * (float)v43) * (float)v35;
}


// ========================================================================
// ScaleForDot
// EA  : 0x82B00BD8
// RVA : 0x00B00BD8
// PDB : w:\tech5\tungsten\game\ai\rotationtracker.cpp
// ========================================================================

float __fastcall ScaleForDot(double curDot, double maxDot, double minClamp)
{
  double v3; // fp1
  double v4; // fp13
  double v5; // fp12

  v4 = (float)((float)2.0 - (float)((float)maxDot + (float)1.0));
  v5 = (float)((float)2.0 - (float)((float)curDot + (float)1.0));
  v3 = 0.0;
  if ( v5 < v4 && __fabs(v4) > idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    v3 = (float)((float)1.0 - (float)((float)v5 / (float)((float)2.0 - (float)((float)maxDot + (float)1.0))));
    if ( v3 >= minClamp )
    {
      if ( v3 > 1.0 )
        v3 = 1.0;
    }
    else
    {
      v3 = minClamp;
    }
  }
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?GetWorldSpaceDir@idRotationTracker@@QBAXABVidMat3@@AAVidVec3@@@Z
// EA  : 0x82B00C48
// RVA : 0x00B00C48
// PDB : w:\tech5\tungsten\game\ai\rotationtracker.cpp
// ========================================================================

void __fastcall idRotationTracker::GetWorldSpaceDir(idRotationTracker *this, const idMat3 *refAxis, idVec3 *wsDir)
{
  idQuat v3; // [sp+50h] [-20h] BYREF

  *wsDir = *idQuat::ToForward(this: &v3, result: (idVec3 *)&this->rot);
}


// ========================================================================
// ?GetWorldSpaceAxis@idRotationTracker@@QBAXABVidMat3@@AAV2@@Z
// EA  : 0x82B00C98
// RVA : 0x00B00C98
// PDB : w:\tech5\tungsten\game\ai\rotationtracker.cpp
// ========================================================================

void __fastcall idRotationTracker::GetWorldSpaceAxis(idRotationTracker *this, const idMat3 *refAxis, idMat3 *wsAxis)
{
  idQuat v3; // [sp+50h] [-40h] BYREF

  *wsAxis = *idQuat::ToMat3(this: &v3, result: (idMat3 *)&this->rot);
}


// ========================================================================
// ?GetConstraints@idRotationTracker@@QBAXAAVidRotationTrackerRange@@@Z
// EA  : 0x82B00D18
// RVA : 0x00B00D18
// PDB : w:\tech5\tungsten\game\ai\rotationtracker.cpp
// ========================================================================

void __fastcall idRotationTracker::GetConstraints(idRotationTracker *this, idRotationTrackerRange *range)
{
  range->minPitch = (float)(idMath::M_RAD2DEG * (float)-1.0) * this->maxPitch.value;
  range->maxPitch = this->maxPitch.value * idMath::M_RAD2DEG;
  range->minYaw = (float)(idMath::M_RAD2DEG * (float)-1.0) * this->maxYaw.value;
  range->maxYaw = this->maxYaw.value * idMath::M_RAD2DEG;
}


// ========================================================================
// ?SetConstraints@idRotationTracker@@QAAXV?$idTypesafeNumber@MW4RadiansUnique_t@@@@0@Z
// EA  : 0x82B00D70
// RVA : 0x00B00D70
// PDB : w:\tech5\tungsten\game\ai\rotationtracker.cpp
// ========================================================================

void __fastcall idRotationTracker::SetConstraints(
        idRotationTracker *this,
        const idTypesafeNumber<float,enum RadiansUnique_t> *mp,
        const idTypesafeNumber<float,enum RadiansUnique_t> *my,
        long double a4)
{
  long double v6; // fp2
  long double v7; // fp2
  long double v8; // fp2
  long double v9; // fp2

  *(double *)&a4 = mp->value;
  this->maxPitch.value = mp->value;
  v6 = cos(x: a4);
  this->maxPitchDot = *(double *)&v6;
  *(double *)&v6 = (float)(this->maxPitch.value * (float)0.5);
  v7 = cos(x: v6);
  this->halfMaxPitchDot = *(double *)&v7;
  *(double *)&v7 = my->value;
  this->maxYaw.value = my->value;
  v8 = cos(x: v7);
  this->maxYawDot = *(double *)&v8;
  *(double *)&v8 = (float)(this->maxYaw.value * (float)0.5);
  v9 = cos(x: v8);
  this->halfMaxYawDot = *(double *)&v9;
}


// ========================================================================
// ?Update@idRotationTracker@@UAAXABVidVec3@@ABVidMat3@@0M_NH@Z
// EA  : 0x82B00E08
// RVA : 0x00B00E08
// PDB : w:\tech5\tungsten\game\ai\rotationtracker.cpp
// ========================================================================

void __fastcall idRotationTracker::Update(
        idRotationTracker *this,
        const idVec3 *curPos,
        idMat3 *refAxis,
        const idVec3 *wsIdealDir,
        double timeSeconds,
        const bool aiming,
        unsigned __int8 debugLevel,
        int a8)
{
  double x; // fp7
  double v9; // fp29
  float v10; // r10
  double v11; // fp12
  double y; // fp6
  double v13; // fp28
  double z; // fp5
  float v16; // r9
  double v17; // fp27
  double v18; // fp0
  double maxYawDot; // fp2
  idVec3 *v22; // r27
  double v25; // fp1
  double v26; // fp11
  double v27; // fp4
  double v30; // fp8
  double v31; // fp10
  double v32; // fp10
  double v33; // fp8
  double v34; // fp1
  double v35; // fp0
  double v36; // fp13
  double v39; // fp11
  double v40; // fp11
  double v41; // fp12
  double v42; // fp11
  int v43; // r22
  __int64 v44; // r10
  __int64 v45; // r8
  double v46; // fp8
  double v47; // fp3
  unsigned int v48; // fp2
  double v49; // fp7
  double v50; // fp6
  double v51; // fp5
  double v52; // fp11
  double v53; // fp10
  double v54; // fp7
  double v55; // fp9
  double v58; // fp12
  double v59; // fp12
  double v60; // fp13
  double v61; // fp11
  va *v62; // r3
  idQuat *p_rot; // r28
  double v64; // fp25
  double v65; // fp13
  double v66; // fp12
  double v67; // fp11
  double v68; // fp10
  double v69; // fp9
  double v70; // fp8
  double v71; // fp7
  double v72; // fp6
  double v73; // fp5
  double v76; // fp11
  double v77; // fp1
  double v78; // fp11
  double v79; // fp7
  double v80; // fp6
  double v81; // fp5
  double v84; // fp11
  double v85; // fp1
  idQuat *v86; // r3
  char v87; // r23
  int v88; // r3
  double v89; // fp9
  __int64 v90; // r8
  double v91; // fp10
  double v92; // fp11
  double v93; // fp12
  double v94; // fp0
  double v95; // fp13
  double v96; // fp21
  double v99; // fp1
  double v100; // fp1
  double v101; // fp0
  double v102; // fp23
  double v103; // fp31
  long double v104; // fp2
  long double v105; // fp2
  double v106; // fp25
  double v107; // fp13
  double value; // fp0
  double v109; // fp31
  double v110; // fp0
  double v111; // fp12
  double v112; // fp6
  double v113; // fp4
  double v114; // fp11
  double v115; // fp3
  double v116; // fp2
  double v117; // fp1
  float *v118; // r7
  idQuat *v119; // r6
  const idMat3 *v120; // r3
  float *v121; // r7
  idQuat *v122; // r6
  long double v123; // fp2
  double v124; // fp31
  long double v125; // fp2
  const idMat3 *v126; // r3
  idQuat *v127; // r3
  double v128; // fp11
  double v129; // fp10
  double v130; // fp8
  double v131; // fp12
  double v132; // fp13
  double v133; // fp13
  double v134; // fp11
  double v135; // fp10
  double v136; // fp3
  double v137; // fp2
  double v138; // fp13
  double v139; // fp11
  double v140; // fp10
  double v141; // fp9
  double v142; // fp2
  double v143; // fp13
  double v144; // fp9
  double v145; // fp12
  double v146; // fp11
  double v147; // fp13
  double v148; // fp7
  double v149; // fp6
  double v150; // fp12
  double v151; // fp3
  double v152; // fp2
  double v153; // fp13
  double v154; // fp3
  double v155; // fp13
  BOOL clampedYaw; // r11
  double v157; // fp8
  double v158; // fp6
  double v159; // fp7
  double v160; // fp9
  double v161; // fp5
  double v162; // fp1
  double v163; // fp0
  double v164; // fp12
  int v165; // [sp+8h] [-1408h]
  int v166; // [sp+Ch] [-1404h]
  int v167; // [sp+10h] [-1400h]
  int v168; // [sp+14h] [-13FCh]
  int v169; // [sp+18h] [-13F8h]
  int v170; // [sp+1Ch] [-13F4h]
  __int64 v171; // [sp+60h] [-13B0h] BYREF
  idQuat v172; // [sp+68h] [-13A8h] BYREF
  idMat3 v173; // [sp+80h] [-1390h] BYREF
  float v174; // [sp+A4h] [-136Ch]
  float v175; // [sp+A8h] [-1368h]
  float v176; // [sp+ACh] [-1364h]
  float v177; // [sp+B0h] [-1360h]
  float v178; // [sp+B4h] [-135Ch]
  float v179; // [sp+B8h] [-1358h]
  float v180; // [sp+BCh] [-1354h]
  float v181; // [sp+C0h] [-1350h]
  float v182[4]; // [sp+C8h] [-1348h] BYREF
  float v183[4]; // [sp+D8h] [-1338h] BYREF
  float v184[4]; // [sp+E8h] [-1328h] BYREF
  float v185[4]; // [sp+F8h] [-1318h] BYREF
  float v186[4]; // [sp+108h] [-1308h] BYREF
  float v187[4]; // [sp+118h] [-12F8h] BYREF
  float v188[4]; // [sp+128h] [-12E8h] BYREF
  float v189[4]; // [sp+138h] [-12D8h] BYREF
  float v190[4]; // [sp+148h] [-12C8h] BYREF
  float v191[4]; // [sp+158h] [-12B8h] BYREF
  idVec3 v192; // [sp+168h] [-12A8h] BYREF
  float v193[4]; // [sp+178h] [-1298h] BYREF
  float v194[6]; // [sp+188h] [-1288h] BYREF
  float v195[4]; // [sp+1A0h] [-1270h] BYREF
  float v196[4]; // [sp+1B0h] [-1260h] BYREF
  float v197[4]; // [sp+1C0h] [-1250h] BYREF
  float v198[4]; // [sp+1D0h] [-1240h] BYREF
  float v199[4]; // [sp+1E0h] [-1230h] BYREF
  float v200[4]; // [sp+1F0h] [-1220h] BYREF
  float v201[4]; // [sp+200h] [-1210h] BYREF
  float v202[4]; // [sp+210h] [-1200h] BYREF
  float v203[4]; // [sp+220h] [-11F0h] BYREF
  float v204[4]; // [sp+230h] [-11E0h] BYREF
  idQuat v205; // [sp+240h] [-11D0h] BYREF
  float v206; // [sp+250h] [-11C0h]
  float v207; // [sp+254h] [-11BCh]
  float v208; // [sp+258h] [-11B8h]
  float v209; // [sp+25Ch] [-11B4h]
  float v210; // [sp+260h] [-11B0h]
  idQuat v211; // [sp+268h] [-11A8h] BYREF
  idMat3 v212; // [sp+280h] [-1190h] BYREF
  idMat3 v213; // [sp+2B0h] [-1160h] BYREF
  idQuat v214; // [sp+2E0h] [-1130h] BYREF
  float v215; // [sp+2F0h] [-1120h]
  float v216; // [sp+2F4h] [-111Ch]
  idQuat v217[3]; // [sp+310h] [-1100h] BYREF
  va v218; // [sp+340h] [-10D0h] BYREF

  x = refAxis->mat[2].x;
  v9 = wsIdealDir->x;
  v10 = wsIdealDir->x;
  v11 = (float)(refAxis->mat[2].x * wsIdealDir->x);
  y = refAxis->mat[2].y;
  v13 = wsIdealDir->y;
  z = refAxis->mat[2].z;
  v16 = wsIdealDir->y;
  v172.z = wsIdealDir->z;
  v17 = wsIdealDir->z;
  v172.x = v10;
  v18 = refAxis->mat[0].y;
  v172.y = v16;
  maxYawDot = this->maxYawDot;
  v22 = &refAxis->mat[2];
  v25 = (float)(v16
              - (float)((float)((float)((float)z * (float)v17) + (float)((float)((float)y * (float)v13) + (float)v11))
                      * (float)y));
  v26 = (float)(v172.z
              - (float)((float)((float)((float)z * (float)v17) + (float)((float)((float)y * (float)v13) + (float)v11))
                      * (float)z));
  v27 = (float)(v10
              - (float)((float)((float)((float)z * (float)v17) + (float)((float)((float)y * (float)v13) + (float)v11))
                      * (float)x));
  _FP8 = (float)((float)((float)((float)v27 * (float)v27)
                       + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f10, f8, f10, f9 }
  v30 = __frsqrte(_FP10);
  v31 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30
                                                                                      * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)))
                                                                                              * (float)0.5))
                                                                              * (float)v30)
                                                                      - (float)1.5)
                                                      * (float)v30)
                                              * (float)((float)((float)((float)v27 * (float)v27)
                                                              + (float)((float)((float)v26 * (float)v26)
                                                                      + (float)((float)v25 * (float)v25)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v30
                                                                              * (float)((float)((float)((float)v27 * (float)v27)
                                                                                              + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)))
                                                                                      * (float)0.5))
                                                                      * (float)v30)
                                                              - (float)1.5)
                                              * (float)v30))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v30
                                                      * (float)((float)((float)((float)v27 * (float)v27)
                                                                      + (float)((float)((float)v26 * (float)v26)
                                                                              + (float)((float)v25 * (float)v25)))
                                                              * (float)0.5))
                                              * (float)v30)
                                      - (float)1.5)
                      * (float)v30));
  v32 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5)) * (float)v30) - (float)1.5)
                                                                                              * (float)v30)
                                                                                      * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5)) * (float)v30) - (float)1.5)
                                                                                      * (float)v30))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v30
                                                                                              * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5))
                                                                                      * (float)v30)
                                                                              - (float)1.5)
                                                              * (float)v30))
                                              * (float)((float)((float)((float)v27 * (float)v27)
                                                              + (float)((float)((float)v26 * (float)v26)
                                                                      + (float)((float)v25 * (float)v25)))
                                                      * (float)0.5))
                                      * (float)v31)
                              - (float)1.5)
              * (float)v31);
  v33 = (float)((float)((float)((float)(v172.z
                                      - (float)((float)((float)((float)z * (float)v17)
                                                      + (float)((float)((float)y * (float)v13) + (float)v11))
                                              * (float)z))
                              * (float)v32)
                      * refAxis->mat[0].z)
              + (float)((float)((float)((float)v32
                                      * (float)(v10
                                              - (float)((float)((float)((float)z * (float)v17)
                                                              + (float)((float)((float)y * (float)v13) + (float)v11))
                                                      * (float)x)))
                              * refAxis->mat[0].x)
                      + (float)((float)((float)(v16
                                              - (float)((float)((float)((float)z * (float)v17)
                                                              + (float)((float)((float)y * (float)v13) + (float)v11))
                                                      * (float)y))
                                      * (float)v32)
                              * (float)v18)));
  if ( v33 < maxYawDot )
  {
    v34 = (float)((float)v13
                - (float)((float)((float)v18
                                * (float)((float)((float)((float)(v172.z
                                                                - (float)((float)((float)((float)z * (float)v17)
                                                                                + (float)((float)((float)y * (float)v13)
                                                                                        + (float)v11))
                                                                        * (float)z))
                                                        * (float)v32)
                                                * refAxis->mat[0].z)
                                        + (float)((float)((float)((float)v32
                                                                * (float)(v10
                                                                        - (float)((float)((float)((float)z * (float)v17)
                                                                                        + (float)((float)((float)y * (float)v13)
                                                                                                + (float)v11))
                                                                                * (float)x)))
                                                        * refAxis->mat[0].x)
                                                + (float)((float)((float)(v16
                                                                        - (float)((float)((float)((float)z * (float)v17)
                                                                                        + (float)((float)((float)y * (float)v13)
                                                                                                + (float)v11))
                                                                                * (float)y))
                                                                * (float)v32)
                                                        * (float)v18))))
                        * (float)2.0));
    v35 = (float)((float)v17
                - (float)((float)(refAxis->mat[0].z
                                * (float)((float)((float)((float)(v172.z
                                                                - (float)((float)((float)((float)z * (float)v17)
                                                                                + (float)((float)((float)y * (float)v13)
                                                                                        + (float)v11))
                                                                        * (float)z))
                                                        * (float)v32)
                                                * refAxis->mat[0].z)
                                        + (float)((float)((float)((float)v32
                                                                * (float)(v10
                                                                        - (float)((float)((float)((float)z * (float)v17)
                                                                                        + (float)((float)((float)y * (float)v13)
                                                                                                + (float)v11))
                                                                                * (float)x)))
                                                        * refAxis->mat[0].x)
                                                + (float)((float)((float)(v16
                                                                        - (float)((float)((float)((float)z * (float)v17)
                                                                                        + (float)((float)((float)y * (float)v13)
                                                                                                + (float)v11))
                                                                                * (float)y))
                                                                * (float)v32)
                                                        * (float)v18))))
                        * (float)2.0));
    v36 = (float)((float)v9 - (float)((float)(refAxis->mat[0].x * (float)v33) * (float)2.0));
    _FP4 = (float)((float)((float)((float)v36 * (float)v36)
                         + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f12, f4, f10, f9 }
    v39 = __frsqrte(_FP12);
    v40 = (float)((float)-(float)((float)((float)((float)v39
                                                * (float)((float)((float)((float)v36 * (float)v36)
                                                                + (float)((float)((float)v35 * (float)v35)
                                                                        + (float)((float)v34 * (float)v34)))
                                                        * (float)0.5))
                                        * (float)v39)
                                - (float)1.5)
                * (float)v39);
    v41 = (float)((float)-(float)((float)((float)((float)v40
                                                * (float)((float)((float)((float)v36 * (float)v36)
                                                                + (float)((float)((float)v35 * (float)v35)
                                                                        + (float)((float)v34 * (float)v34)))
                                                        * (float)0.5))
                                        * (float)v40)
                                - (float)1.5)
                * (float)v40);
    v42 = (float)((float)((float)-(float)((float)((float)((float)v40
                                                        * (float)((float)((float)((float)v36 * (float)v36)
                                                                        + (float)((float)((float)v35 * (float)v35)
                                                                                + (float)((float)v34 * (float)v34)))
                                                                * (float)0.5))
                                                * (float)v40)
                                        - (float)1.5)
                        * (float)v40)
                * (float)((float)((float)((float)v36 * (float)v36)
                                + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34)))
                        * (float)0.5));
    v9 = (float)((float)((float)v9 - (float)((float)(refAxis->mat[0].x * (float)v33) * (float)2.0))
               * (float)((float)-(float)((float)((float)v42 * (float)v41) - (float)1.5) * (float)v41));
    v13 = (float)((float)v34 * (float)((float)-(float)((float)((float)v42 * (float)v41) - (float)1.5) * (float)v41));
    v17 = (float)((float)((float)v17 - (float)((float)(refAxis->mat[0].z * (float)v33) * (float)2.0))
                * (float)((float)-(float)((float)((float)v42 * (float)v41) - (float)1.5) * (float)v41));
  }
  v43 = debugLevel;
  if ( debugLevel == 0 )
  {
    v47 = ScaleForDot(curDot: v33, maxDot: maxYawDot, minClamp: 0.25);
    v52 = (float)((float)v13
                - (float)((float)((float)((float)((float)v9 * (float)v49)
                                        + (float)((float)((float)v17 * v22->z) + (float)((float)v13 * v22->y)))
                                * (float)((float)1.0 - (float)v47))
                        * (float)v50));
    v53 = (float)((float)v17
                - (float)((float)((float)((float)((float)v9 * (float)v49)
                                        + (float)((float)((float)v17 * v22->z) + (float)((float)v13 * v22->y)))
                                * (float)((float)1.0 - (float)v47))
                        * (float)v51));
    v54 = (float)((float)v9
                - (float)((float)((float)((float)((float)v9 * (float)v49)
                                        + (float)((float)((float)v17 * v22->z) + (float)((float)v13 * v22->y)))
                                * (float)((float)1.0 - (float)v47))
                        * (float)v49));
    _FP1 = (float)((float)((float)((float)v54 * (float)v54)
                         + (float)((float)((float)v53 * (float)v53) + (float)((float)v52 * (float)v52)))
                 - (float)v55);
    __asm { fsel      f13, f1, f4, f9 }
    v58 = __frsqrte(_FP13);
    v59 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v58
                                                                                        * (float)((float)((float)((float)v54 * (float)v54) + (float)((float)((float)v53 * (float)v53) + (float)((float)v52 * (float)v52)))
                                                                                                * (float)0.5))
                                                                                * (float)v58)
                                                                        - (float)1.5)
                                                        * (float)v58)
                                                * (float)((float)((float)((float)v54 * (float)v54)
                                                                + (float)((float)((float)v53 * (float)v53)
                                                                        + (float)((float)v52 * (float)v52)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v58
                                                                                * (float)((float)((float)((float)v54 * (float)v54)
                                                                                                + (float)((float)((float)v53 * (float)v53) + (float)((float)v52 * (float)v52)))
                                                                                        * (float)0.5))
                                                                        * (float)v58)
                                                                - (float)1.5)
                                                * (float)v58))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v58
                                                        * (float)((float)((float)((float)v54 * (float)v54)
                                                                        + (float)((float)((float)v53 * (float)v53)
                                                                                + (float)((float)v52 * (float)v52)))
                                                                * (float)0.5))
                                                * (float)v58)
                                        - (float)1.5)
                        * (float)v58));
    v9 = (float)((float)((float)-(float)((float)((float)((float)v59
                                                       * (float)((float)((float)((float)v54 * (float)v54)
                                                                       + (float)((float)((float)v53 * (float)v53)
                                                                               + (float)((float)v52 * (float)v52)))
                                                               * (float)0.5))
                                               * (float)v59)
                                       - (float)1.5)
                       * (float)v59)
               * (float)v54);
    v13 = (float)((float)v52
                * (float)((float)-(float)((float)((float)((float)v59
                                                        * (float)((float)((float)((float)v54 * (float)v54)
                                                                        + (float)((float)((float)v53 * (float)v53)
                                                                                + (float)((float)v52 * (float)v52)))
                                                                * (float)0.5))
                                                * (float)v59)
                                        - (float)1.5)
                        * (float)v59));
    v17 = (float)((float)v53
                * (float)((float)-(float)((float)((float)((float)v59
                                                        * (float)((float)((float)((float)v54 * (float)v54)
                                                                        + (float)((float)((float)v53 * (float)v53)
                                                                                + (float)((float)v52 * (float)v52)))
                                                                * (float)0.5))
                                                * (float)v59)
                                        - (float)1.5)
                        * (float)v59));
    if ( a8 > 0 )
    {
      HIDWORD(v45) = LODWORD(v47);
      v60 = curPos->z;
      LODWORD(v44) = "Could not find AI state, idVS_ds_Car_Chase! ";
      v61 = curPos->y;
      v193[0] = curPos->x;
      v193[1] = v61;
      v193[2] = (float)v60 + (float)8.0;
      v62 = va::va(
              this: &v218,
              fmt: "cyd = %.2f myd = %.2f scale = %.2f",
              a3: __SPAIR64__(LODWORD(v46), v48),
              a4: v45,
              a5: v44,
              a6: v165,
              a7: v166,
              a8: v167,
              a9: v168,
              a10: v169,
              a11: v170,
              v46);
      ((void (__fastcall *)(idRenderWorld *, va *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: v62,
        a3: v193,
        a4: clientGame->renderWorld->__vftable,
        a5: &idColor::colorCyan,
        a6: 1,
        a7: 0,
        a8: 0,
        a9: 0.050000001);
    }
  }
  p_rot = &this->rot;
  idQuat::ToForward(this: &v172, result: (idVec3 *)&this->rot);
  v64 = (float)((float)(v172.x * (float)v9) + (float)((float)(v172.z * (float)v17) + (float)(v172.y * (float)v13)));
  if ( v64 <= 0.99998999 )
  {
    v87 = 0;
    v88 = gameLocal->GetGameHz(this: gameLocal, a2: GAMETIME_SCALED);
    v89 = v172.x;
    LODWORD(v90) = v88;
    v91 = v172.y;
    v171 = v90;
    v92 = v172.z;
    v93 = (float)((float)(v172.y * (float)v9) - (float)((float)v13 * v172.x));
    v94 = (float)((float)(v172.z * (float)v13) - (float)(v172.y * (float)v17));
    v95 = (float)((float)((float)v17 * v172.x) - (float)(v172.z * (float)v9));
    v96 = (float)((float)1.0 / (float)v90);
    if ( (float)((float)((float)v95 * (float)v95)
               + (float)((float)((float)v94 * (float)v94) + (float)((float)v93 * (float)v93))) <= 0.0000099999997 )
    {
      idQuat::ToMat3(this: &v214, result: (idMat3 *)&this->rot);
      v92 = v172.z;
      v91 = v172.y;
      v89 = v172.x;
      v94 = (float)((float)((float)v13 * v216) - (float)((float)v17 * v215));
      v95 = (float)((float)((float)v17 * v214.w) - (float)(v216 * (float)v9));
      v93 = (float)((float)(v215 * (float)v9) - (float)((float)v13 * v214.w));
    }
    _FP4 = (float)((float)((float)((float)v95 * (float)v95)
                         + (float)((float)((float)v94 * (float)v94) + (float)((float)v93 * (float)v93)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f2, f4, f5, f8 }
    v99 = __frsqrte(_FP2);
    v100 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v99
                                                                                         * (float)((float)((float)((float)v95 * (float)v95) + (float)((float)((float)v94 * (float)v94) + (float)((float)v93 * (float)v93)))
                                                                                                 * (float)0.5))
                                                                                 * (float)v99)
                                                                         - (float)1.5)
                                                         * (float)v99)
                                                 * (float)((float)((float)((float)v95 * (float)v95)
                                                                 + (float)((float)((float)v94 * (float)v94)
                                                                         + (float)((float)v93 * (float)v93)))
                                                         * (float)0.5))
                                         * (float)((float)-(float)((float)((float)((float)v99
                                                                                 * (float)((float)((float)((float)v95 * (float)v95)
                                                                                                 + (float)((float)((float)v94 * (float)v94) + (float)((float)v93 * (float)v93)))
                                                                                         * (float)0.5))
                                                                         * (float)v99)
                                                                 - (float)1.5)
                                                 * (float)v99))
                                 - (float)1.5)
                 * (float)((float)-(float)((float)((float)((float)v99
                                                         * (float)((float)((float)((float)v95 * (float)v95)
                                                                         + (float)((float)((float)v94 * (float)v94)
                                                                                 + (float)((float)v93 * (float)v93)))
                                                                 * (float)0.5))
                                                 * (float)v99)
                                         - (float)1.5)
                         * (float)v99));
    v192.x = (float)((float)-(float)((float)((float)((float)v100
                                                   * (float)((float)((float)((float)v95 * (float)v95)
                                                                   + (float)((float)((float)v94 * (float)v94)
                                                                           + (float)((float)v93 * (float)v93)))
                                                           * (float)0.5))
                                           * (float)v100)
                                   - (float)1.5)
                   * (float)v100)
           * (float)v94;
    v192.y = (float)v95
           * (float)((float)-(float)((float)((float)((float)v100
                                                   * (float)((float)((float)((float)v95 * (float)v95)
                                                                   + (float)((float)((float)v94 * (float)v94)
                                                                           + (float)((float)v93 * (float)v93)))
                                                           * (float)0.5))
                                           * (float)v100)
                                   - (float)1.5)
                   * (float)v100);
    v192.z = (float)v93
           * (float)((float)-(float)((float)((float)((float)v100
                                                   * (float)((float)((float)((float)v95 * (float)v95)
                                                                   + (float)((float)((float)v94 * (float)v94)
                                                                           + (float)((float)v93 * (float)v93)))
                                                           * (float)0.5))
                                           * (float)v100)
                                   - (float)1.5)
                   * (float)v100);
    if ( (float)((float)((float)((float)(v192.y * (float)v92) - (float)(v192.z * (float)v91)) * (float)v9)
               + (float)((float)((float)((float)((float)v91 * v192.x) - (float)(v192.y * (float)v89)) * (float)v17)
                       + (float)((float)((float)(v192.z * (float)v89) - (float)((float)v92 * v192.x)) * (float)v13))) <= 0.0 )
      v101 = 1.0;
    else
      v101 = -1.0;
    v102 = (float)(this->acceleration.value * (float)v101);
    v103 = idAIUtils::CalcDecelerationDistance(
             currentVel: this->velocity.value,
             decelerationRate: -this->deceleration.value);
    *(double *)&v104 = v64;
    *(double *)&v105 = idMath::ACos(a: v104);
    v106 = *(double *)&v105;
    if ( *(double *)&v105 <= v103 )
    {
      *(double *)&v105 = idAIUtils::CalcExactDecelerationRate(
                           currentVel: __fabs(this->velocity.value),
                           distance: *(double *)&v105);
      if ( this->velocity.value <= 0.0 )
        *(float *)&v171 = 1.0;
      else
        *(float *)&v171 = -1.0;
      v87 = 1;
      v102 = (float)((float)__fabs(*(double *)&v105) * *(float *)&v171);
    }
    v107 = (float)((float)((float)v102 * (float)v96) + this->velocity.value);
    this->velocity.value = (float)((float)v102 * (float)v96) + this->velocity.value;
    value = this->maxVelocity.value;
    if ( v107 >= -value )
    {
      if ( v107 <= value )
        goto LABEL_22;
    }
    else
    {
      value = -value;
    }
    this->velocity.value = value;
LABEL_22:
    v109 = (float)(this->velocity.value * (float)v96);
    if ( v109 < v106 )
    {
      if ( v109 > -v106 )
      {
LABEL_27:
        if ( a8 > 1 )
        {
          idLib::Printf(fmt: "vel = %.2f ", this->velocity.value);
          if ( v87 != 0 )
            idLib::Printf(fmt: "decelerating( %.2f )\n", v102);
          else
            idLib::Printf(fmt: "accelerating( %.2f )\n", v102);
        }
        *(float *)&v171 = v109;
        idQuat::idQuat(
          this: (idQuat *)&v173,
          axis: &v192,
          angle: (const idTypesafeNumber<float,enum RadiansUnique_t> *)&v171,
          a4: v105);
        v110 = v173.mat[0].y;
        v111 = v173.mat[0].x;
        v112 = this->rot.z;
        v113 = this->rot.y;
        v114 = v173.mat[0].z;
        v115 = (float)((float)(v173.mat[0].z * this->rot.y)
                     + (float)((float)(v173.mat[0].x * this->rot.w) + (float)(v173.mat[1].x * this->rot.x)));
        v116 = (float)((float)(v173.mat[0].z * this->rot.w)
                     + (float)((float)(v173.mat[1].x * this->rot.z) + (float)(v173.mat[0].y * this->rot.x)));
        v117 = (float)-(float)((float)(v173.mat[0].y * this->rot.y)
                             - (float)((float)(v173.mat[1].x * this->rot.w) - (float)(v173.mat[0].x * this->rot.x)));
        this->rot.y = -(float)((float)(v173.mat[0].z * this->rot.x)
                             - (float)((float)(v173.mat[1].x * this->rot.y)
                                     + (float)((float)(v173.mat[0].x * this->rot.z)
                                             + (float)(v173.mat[0].y * this->rot.w))));
        p_rot->x = -(float)((float)((float)v110 * (float)v112) - (float)v115);
        this->rot.z = -(float)((float)((float)v111 * (float)v113) - (float)v116);
        this->rot.w = -(float)((float)((float)v114 * (float)v112) - (float)v117);
        idQuat::ToForward(this: &v211, result: (idVec3 *)&this->rot);
        ClampOnAxis(
          rotAxis: v22,
          refAxis: refAxis->mat,
          idealDir: (const idVec3 *)&v211,
          maxDot: this->maxYawDot,
          halfMaxDot: this->halfMaxYawDot,
          rot: v119,
          dot: v118,
          clamped: (float *)&v213,
          a9: (float *)&v171,
          a10: (char *)&this->clampedYaw);
        v120 = idQuat::ToMat3(this: v217, result: &v213);
        idMat3::operator*(this: &v212, result: refAxis, a: v120);
        if ( v43 == 0 )
        {
          *(double *)&v123 = ScaleForDot(curDot: *(float *)&v171, maxDot: this->maxYawDot, minClamp: 0.25);
          v124 = *(double *)&v123;
          if ( *(double *)&v123 < 0.99900001 )
          {
            *(double *)&v123 = (float)((float)*(double *)&v123 * this->maxPitch.value);
            v125 = cos(x: v123);
            *(double *)&v125 = (float)((float)((float)v124 * this->maxPitch.value) * (float)0.5);
            cos(x: v125);
          }
        }
        ClampOnAxis(
          rotAxis: &v212.mat[1],
          refAxis: v212.mat,
          idealDir: (const idVec3 *)&v211,
          maxDot: this->maxPitchDot,
          halfMaxDot: this->halfMaxPitchDot,
          rot: v122,
          dot: v121,
          clamped: &v213.mat[2].z,
          a9: (float *)&v171,
          a10: (char *)&this->clampedPitch);
        v126 = idQuat::ToMat3(this: v217, result: (idMat3 *)&v213.mat[2].z);
        idMat3::operator*=(this: &v212, a: v126);
        v127 = idMat3::ToQuat(this: &v173, result: (idQuat *)&v212);
        p_rot->x = v127->x;
        this->rot.y = v127->y;
        this->rot.z = v127->z;
        this->rot.w = v127->w;
        goto LABEL_35;
      }
      v109 = -v106;
    }
    else
    {
      v109 = v106;
    }
    this->velocity.value = 0.0;
    goto LABEL_27;
  }
  v65 = v22->y;
  v66 = (float)((float)v9 * v22->y);
  v67 = v22->z;
  v68 = v22->x;
  v69 = (float)((float)v13 * v22->z);
  v70 = (float)((float)v17 * v22->x);
  v205.x = v9;
  v205.y = v13;
  v205.z = v17;
  v71 = (float)((float)((float)v13 * (float)v68) - (float)v66);
  v72 = (float)((float)((float)v17 * (float)v65) - (float)v69);
  v73 = (float)((float)((float)v9 * (float)v67) - (float)v70);
  _FP1 = (float)((float)((float)((float)v73 * (float)v73)
                       + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f12, f1, f2, f0 }
  v76 = __frsqrte(_FP12);
  v77 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v76
                                                                                      * (float)((float)((float)((float)v73 * (float)v73) + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71)))
                                                                                              * (float)0.5))
                                                                              * (float)v76)
                                                                      - (float)1.5)
                                                      * (float)v76)
                                              * (float)((float)((float)((float)v73 * (float)v73)
                                                              + (float)((float)((float)v72 * (float)v72)
                                                                      + (float)((float)v71 * (float)v71)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v76
                                                                              * (float)((float)((float)((float)v73 * (float)v73)
                                                                                              + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71)))
                                                                                      * (float)0.5))
                                                                      * (float)v76)
                                                              - (float)1.5)
                                              * (float)v76))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v76
                                                      * (float)((float)((float)((float)v73 * (float)v73)
                                                                      + (float)((float)((float)v72 * (float)v72)
                                                                              + (float)((float)v71 * (float)v71)))
                                                              * (float)0.5))
                                              * (float)v76)
                                      - (float)1.5)
                      * (float)v76));
  v78 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v76 * (float)((float)((float)((float)v73 * (float)v73) + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71))) * (float)0.5)) * (float)v76) - (float)1.5)
                                                                                              * (float)v76)
                                                                                      * (float)((float)((float)((float)v73 * (float)v73) + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v76 * (float)((float)((float)((float)v73 * (float)v73) + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71))) * (float)0.5)) * (float)v76) - (float)1.5)
                                                                                      * (float)v76))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v76
                                                                                              * (float)((float)((float)((float)v73 * (float)v73) + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71))) * (float)0.5))
                                                                                      * (float)v76)
                                                                              - (float)1.5)
                                                              * (float)v76))
                                              * (float)((float)((float)((float)v73 * (float)v73)
                                                              + (float)((float)((float)v72 * (float)v72)
                                                                      + (float)((float)v71 * (float)v71)))
                                                      * (float)0.5))
                                      * (float)v77)
                              - (float)1.5)
              * (float)v77);
  v205.w = (float)v78 * (float)((float)((float)v17 * (float)v65) - (float)v69);
  v206 = (float)v73 * (float)v78;
  v207 = (float)v71 * (float)v78;
  v79 = (float)((float)(v206 * (float)v9) - (float)((float)v13 * v205.w));
  v80 = (float)((float)((float)v13 * v207) - (float)((float)v17 * v206));
  v81 = (float)((float)((float)v17 * v205.w) - (float)(v207 * (float)v9));
  _FP1 = (float)((float)((float)((float)v81 * (float)v81)
                       + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f12, f1, f2, f0 }
  v84 = __frsqrte(_FP12);
  v85 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v84
                                                                                      * (float)((float)((float)((float)v81 * (float)v81) + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79)))
                                                                                              * (float)0.5))
                                                                              * (float)v84)
                                                                      - (float)1.5)
                                                      * (float)v84)
                                              * (float)((float)((float)((float)v81 * (float)v81)
                                                              + (float)((float)((float)v80 * (float)v80)
                                                                      + (float)((float)v79 * (float)v79)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v84
                                                                              * (float)((float)((float)((float)v81 * (float)v81)
                                                                                              + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79)))
                                                                                      * (float)0.5))
                                                                      * (float)v84)
                                                              - (float)1.5)
                                              * (float)v84))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v84
                                                      * (float)((float)((float)((float)v81 * (float)v81)
                                                                      + (float)((float)((float)v80 * (float)v80)
                                                                              + (float)((float)v79 * (float)v79)))
                                                              * (float)0.5))
                                              * (float)v84)
                                      - (float)1.5)
                      * (float)v84));
  v208 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v84 * (float)((float)((float)((float)v81 * (float)v81) + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79))) * (float)0.5)) * (float)v84) - (float)1.5)
                                                                                               * (float)v84)
                                                                                       * (float)((float)((float)((float)v81 * (float)v81) + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79)))
                                                                                               * (float)0.5))
                                                                               * (float)((float)-(float)((float)((float)((float)v84 * (float)((float)((float)((float)v81 * (float)v81) + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79))) * (float)0.5)) * (float)v84) - (float)1.5)
                                                                                       * (float)v84))
                                                                       - (float)1.5)
                                                       * (float)((float)-(float)((float)((float)((float)v84
                                                                                               * (float)((float)((float)((float)v81 * (float)v81) + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79))) * (float)0.5))
                                                                                       * (float)v84)
                                                                               - (float)1.5)
                                                               * (float)v84))
                                               * (float)((float)((float)((float)v81 * (float)v81)
                                                               + (float)((float)((float)v80 * (float)v80)
                                                                       + (float)((float)v79 * (float)v79)))
                                                       * (float)0.5))
                                       * (float)v85)
                               - (float)1.5)
               * (float)v85)
       * (float)v80;
  v209 = (float)((float)((float)v17 * v205.w) - (float)(v207 * (float)v9))
       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v84 * (float)((float)((float)((float)v81 * (float)v81) + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79))) * (float)0.5)) * (float)v84) - (float)1.5)
                                                                                               * (float)v84)
                                                                                       * (float)((float)((float)((float)v81 * (float)v81) + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79)))
                                                                                               * (float)0.5))
                                                                               * (float)((float)-(float)((float)((float)((float)v84 * (float)((float)((float)((float)v81 * (float)v81) + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79))) * (float)0.5)) * (float)v84) - (float)1.5)
                                                                                       * (float)v84))
                                                                       - (float)1.5)
                                                       * (float)((float)-(float)((float)((float)((float)v84
                                                                                               * (float)((float)((float)((float)v81 * (float)v81) + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79))) * (float)0.5))
                                                                                       * (float)v84)
                                                                               - (float)1.5)
                                                               * (float)v84))
                                               * (float)((float)((float)((float)v81 * (float)v81)
                                                               + (float)((float)((float)v80 * (float)v80)
                                                                       + (float)((float)v79 * (float)v79)))
                                                       * (float)0.5))
                                       * (float)v85)
                               - (float)1.5)
               * (float)v85);
  v210 = (float)((float)(v206 * (float)v9) - (float)((float)v13 * v205.w))
       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v84 * (float)((float)((float)((float)v81 * (float)v81) + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79))) * (float)0.5)) * (float)v84) - (float)1.5)
                                                                                               * (float)v84)
                                                                                       * (float)((float)((float)((float)v81 * (float)v81) + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79)))
                                                                                               * (float)0.5))
                                                                               * (float)((float)-(float)((float)((float)((float)v84 * (float)((float)((float)((float)v81 * (float)v81) + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79))) * (float)0.5)) * (float)v84) - (float)1.5)
                                                                                       * (float)v84))
                                                                       - (float)1.5)
                                                       * (float)((float)-(float)((float)((float)((float)v84
                                                                                               * (float)((float)((float)((float)v81 * (float)v81) + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79))) * (float)0.5))
                                                                                       * (float)v84)
                                                                               - (float)1.5)
                                                               * (float)v84))
                                               * (float)((float)((float)((float)v81 * (float)v81)
                                                               + (float)((float)((float)v80 * (float)v80)
                                                                       + (float)((float)v79 * (float)v79)))
                                                       * (float)0.5))
                                       * (float)v85)
                               - (float)1.5)
               * (float)v85);
  v86 = idMat3::ToQuat(this: &v173, result: &v205);
  p_rot->x = v86->x;
  this->rot.y = v86->y;
  this->rot.z = v86->z;
  this->rot.w = v86->w;
LABEL_35:
  if ( a8 <= 0 )
    return;
  v128 = refAxis->mat[0].y;
  v129 = refAxis->mat[0].z;
  v130 = (float)(refAxis->mat[0].x * (float)64.0);
  v131 = (float)(curPos->z + (float)16.0);
  v173.mat[2].x = curPos->z + (float)16.0;
  v195[1] = 1.0;
  v132 = curPos->y;
  v173.mat[1].y = curPos->x;
  v195[2] = 0.0;
  v173.mat[1].z = v132;
  v195[0] = 0.0;
  v195[3] = 1.0;
  v194[0] = (float)v130 + v173.mat[1].y;
  v194[1] = (float)((float)v128 * (float)64.0) + (float)v132;
  v194[2] = (float)((float)v129 * (float)64.0) + (float)v131;
  ((void (__fastcall *)(idRenderWorld *, float *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
    a1: clientGame->renderWorld,
    a2: v195,
    a3: &v173.mat[1].y,
    a4: v194,
    a5: 4.0);
  v133 = (float)(refAxis->mat[1].x * (float)64.0);
  v134 = (float)(refAxis->mat[1].y * (float)64.0);
  v135 = (float)(refAxis->mat[1].z * (float)64.0);
  v204[0] = 1.0;
  v204[1] = 0.0;
  v204[2] = 0.0;
  v204[3] = 1.0;
  v189[0] = (float)v133 + v173.mat[1].y;
  v189[1] = (float)v134 + v173.mat[1].z;
  v189[2] = (float)v135 + v173.mat[2].x;
  ((void (__fastcall *)(idRenderWorld *, float *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
    a1: clientGame->renderWorld,
    a2: v204,
    a3: &v173.mat[1].y,
    a4: v189,
    a5: 4.0);
  v136 = v22->x;
  v137 = v22->y;
  v138 = v22->z;
  v203[0] = 0.0;
  v203[1] = 0.0;
  v203[3] = 1.0;
  v185[0] = (float)((float)v136 * (float)64.0) + v173.mat[1].y;
  v203[2] = 1.0;
  v185[2] = (float)((float)v138 * (float)64.0) + v173.mat[2].x;
  v185[1] = (float)((float)v137 * (float)64.0) + v173.mat[1].z;
  ((void (__fastcall *)(idRenderWorld *, float *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
    a1: clientGame->renderWorld,
    a2: v203,
    a3: &v173.mat[1].y,
    a4: v185,
    a5: 4.0);
  idQuat::ToMat3(this: (idQuat *)&v173.mat[2].z, result: (idMat3 *)&this->rot);
  v139 = curPos->x;
  v140 = curPos->y;
  v141 = curPos->z;
  v198[1] = 1.0;
  v198[3] = 1.0;
  v198[0] = 0.75;
  v198[2] = 0.75;
  v182[0] = (float)v139 + (float)(v173.mat[2].z * (float)64.0);
  v182[1] = (float)(v174 * (float)64.0) + (float)v140;
  v182[2] = (float)(v175 * (float)64.0) + (float)v141;
  ((void (__fastcall *)(idRenderWorld *, float *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
    a1: clientGame->renderWorld,
    a2: v198,
    a3: curPos,
    a4: v182,
    a5: 4.0);
  v142 = curPos->x;
  v143 = curPos->y;
  v144 = curPos->z;
  v200[0] = 1.0;
  v200[1] = 0.75;
  v200[2] = 0.75;
  v200[3] = 1.0;
  v187[0] = (float)v142 + (float)(v176 * (float)64.0);
  v187[1] = (float)(v177 * (float)64.0) + (float)v143;
  v187[2] = (float)(v178 * (float)64.0) + (float)v144;
  ((void (__fastcall *)(idRenderWorld *, float *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
    a1: clientGame->renderWorld,
    a2: v200,
    a3: curPos,
    a4: v187,
    a5: 4.0);
  v145 = curPos->y;
  v146 = curPos->z;
  v147 = curPos->x;
  v201[3] = 1.0;
  v201[0] = 0.75;
  v201[1] = 0.75;
  v201[2] = 1.0;
  v191[1] = (float)(v180 * (float)64.0) + (float)v145;
  v191[2] = (float)(v181 * (float)64.0) + (float)v146;
  v191[0] = (float)v147 + (float)(v179 * (float)64.0);
  ((void (__fastcall *)(idRenderWorld *, float *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
    a1: clientGame->renderWorld,
    a2: v201,
    a3: curPos,
    a4: v191,
    a5: 4.0);
  v148 = wsIdealDir->z;
  v149 = wsIdealDir->x;
  v150 = curPos->y;
  v151 = curPos->z;
  v152 = curPos->x;
  v199[1] = 0.60000002;
  v199[2] = 0.60000002;
  v199[0] = 0.60000002;
  v153 = (float)(wsIdealDir->y * (float)96.0);
  v199[3] = 1.0;
  v183[2] = (float)((float)v148 * (float)96.0) + (float)v151;
  v183[1] = (float)v153 + (float)v150;
  v183[0] = (float)v152 + (float)((float)v149 * (float)96.0);
  ((void (__fastcall *)(idRenderWorld *, float *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
    a1: clientGame->renderWorld,
    a2: v199,
    a3: curPos,
    a4: v183,
    a5: 2.0);
  v197[3] = 1.0;
  v197[0] = 1.0;
  v197[1] = 0.0;
  v154 = (float)(curPos->x + (float)((float)v9 * (float)96.0));
  v155 = (float)((float)((float)v17 * (float)96.0) + curPos->z);
  v184[1] = (float)((float)v13 * (float)96.0) + curPos->y;
  v197[2] = 1.0;
  v184[0] = v154;
  v184[2] = v155;
  ((void (__fastcall *)(idRenderWorld *, float *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
    a1: clientGame->renderWorld,
    a2: v197,
    a3: curPos,
    a4: v184,
    a5: 2.0);
  if ( !this->clampedYaw )
    goto LABEL_41;
  if ( this->clampedPitch )
  {
    ((void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
      a1: clientGame->renderWorld,
      a2: "CLAMPED",
      a3: curPos,
      a4: clientGame->renderWorld->__vftable,
      a5: &idColor::colorWhite,
      a6: 1,
      a7: 0,
      a8: 0,
      a9: 0.30000001);
    goto LABEL_43;
  }
  if ( !this->clampedYaw )
  {
LABEL_41:
    if ( this->clampedPitch )
      ((void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: "CLAMPED PITCH",
        a3: curPos,
        a4: clientGame->renderWorld->__vftable,
        a5: &idColor::colorMagenta,
        a6: 1,
        a7: 0,
        a8: 0,
        a9: 0.30000001);
    goto LABEL_43;
  }
  ((void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
    a1: clientGame->renderWorld,
    a2: "CLAMPED YAW",
    a3: curPos,
    a4: clientGame->renderWorld->__vftable,
    a5: &idColor::colorYellow,
    a6: 1,
    a7: 0,
    a8: 0,
    a9: 0.30000001);
LABEL_43:
  if ( a8 > 2 )
  {
    clampedYaw = this->clampedYaw;
    v173.mat[0].x = 1.0;
    v173.mat[0].z = 0.0;
    v173.mat[1].x = 1.0;
    if ( clampedYaw )
      v173.mat[0].y = 0.0;
    else
      v173.mat[0].y = 1.0;
    v157 = curPos->z;
    v158 = curPos->y;
    v159 = curPos->x;
    v202[0] = 1.0;
    *(idVec3 *)&v213.mat[1].y = v173.mat[0];
    v202[2] = 0.0;
    v202[3] = 1.0;
    v202[1] = 1.0;
    v213.mat[2].y = v173.mat[1].x;
    v186[2] = (float)(v175 * (float)64.0) + (float)v157;
    v186[1] = (float)(v174 * (float)64.0) + (float)v158;
    v186[0] = (float)(v173.mat[2].z * (float)64.0) + (float)v159;
    clientGame->renderWorld->DebugPoint(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)v202,
      a3: (const idVec3 *)v186,
      a4: 10000,
      a5: true);
    v160 = curPos->y;
    v161 = (float)((float)(v175 * (float)64.0) + curPos->z);
    v188[0] = (float)(v173.mat[2].z * (float)64.0) + curPos->x;
    v188[2] = v161;
    v188[1] = (float)(v174 * (float)64.0) + (float)v160;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&v213.mat[1].y,
      a3: curPos,
      a4: (const idVec3 *)v188,
      a5: 10000,
      a6: true);
    v162 = curPos->x;
    v163 = curPos->y;
    v164 = curPos->z;
    v196[0] = 1.0;
    v196[1] = 0.5;
    v196[2] = 0.0;
    v196[3] = 1.0;
    v190[1] = (float)((float)v13 * (float)64.0) + (float)v163;
    v190[0] = (float)((float)v9 * (float)64.0) + (float)v162;
    v190[2] = (float)((float)v17 * (float)64.0) + (float)v164;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)v196,
      a3: curPos,
      a4: (const idVec3 *)v190,
      a5: 10000,
      a6: true);
  }
}


// ========================================================================
// ?Update@idAimTracker@@UAAXABVidVec3@@ABVidMat3@@0M_NH@Z
// EA  : 0x82B01D58
// RVA : 0x00B01D58
// PDB : w:\tech5\tungsten\game\ai\rotationtracker.cpp
// ========================================================================

void __fastcall idAimTracker::Update(
        idAimTracker *this,
        const idVec3 *curPos,
        idMat3 *referenceAxis,
        const idVec3 *idealDir,
        double timeSeconds,
        const bool aiming,
        unsigned __int8 debugLevel,
        int a8)
{
  double value; // fp12
  double v9; // fp11

  value = this->curParms.acceleration.value;
  v9 = this->curParms.deceleration.value;
  this->maxVelocity.value = idMath::M_DEG2RAD * this->curParms.rate.value;
  this->acceleration.value = idMath::M_DEG2RAD * (float)value;
  this->deceleration.value = idMath::M_DEG2RAD * (float)v9;
  idRotationTracker::Update(
    this,
    curPos,
    refAxis: referenceAxis,
    wsIdealDir: idealDir,
    timeSeconds,
    aiming,
    debugLevel,
    a8);
}


// ========================================================================
// ?SetConstraints@idRotationTracker@@QAAXABVidRotationTrackerRange@@@Z
// EA  : 0x82B01D90
// RVA : 0x00B01D90
// PDB : w:\tech5\tungsten\game\ai\rotationtracker.cpp
// ========================================================================

void __fastcall idRotationTracker::SetConstraints(idRotationTracker *this, const idRotationTrackerRange *constraints)
{
  long double v6; // fp2
  idTypesafeNumber<float,enum RadiansUnique_t> v7; // [sp+50h] [-10h] BYREF
  idTypesafeNumber<float,enum RadiansUnique_t> v8; // [sp+54h] [-Ch] BYREF

  _FP6 = (float)((float)__fabs(constraints->minPitch) - (float)__fabs(constraints->maxPitch));
  _FP5 = (float)((float)__fabs(constraints->minYaw) - (float)__fabs(constraints->maxYaw));
  __asm
  {
    fsel      f4, f6, f12, f10
    fsel      f3, f5, f8, f7
  }
  *((double *)&v6 + 1) = (float)(idMath::M_DEG2RAD * (float)_FP4);
  v7.value = idMath::M_DEG2RAD * (float)_FP4;
  *(double *)&v6 = (float)(idMath::M_DEG2RAD * (float)_FP3);
  v8.value = idMath::M_DEG2RAD * (float)_FP3;
  idRotationTracker::SetConstraints(this, mp: &v7, my: &v8, a4: v6);
}

