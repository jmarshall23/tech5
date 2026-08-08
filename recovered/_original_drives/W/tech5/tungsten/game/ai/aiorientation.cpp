
// ========================================================================
// ?UpdateStatic@idAIOrientation@@QAAXXZ
// EA  : 0x82A5EA88
// RVA : 0x00A5EA88
// PDB : w:\tech5\tungsten\game\ai\aiorientation.cpp
// ========================================================================

void __fastcall idAIOrientation::UpdateStatic(idAIOrientation *this)
{
  unsigned __int8 currentTurnDir; // r11

  currentTurnDir = this->currentTurnDir;
  this->currentTurnDir = 0;
  this->previousTurnDir = currentTurnDir;
}


// ========================================================================
// ??0idAIOrientation@@QAA@MM@Z
// EA  : 0x82A5EAA0
// RVA : 0x00A5EAA0
// PDB : w:\tech5\tungsten\game\ai\aiorientation.cpp
// ========================================================================

idAIOrientation *__fastcall idAIOrientation::idAIOrientation(idAIOrientation *this, double minRate, double maxRate)
{
  float *p_z; // r10
  float *p_y; // r11
  int v5; // ctr

  p_z = &this->idealDir.z;
  p_y = &mat2_identity.mat[1].y;
  this->idealDir.x = 1.0;
  this->idealDir.y = 0.0;
  v5 = 9;
  this->idealDir.z = 0.0;
  do
  {
    *++p_z = *++p_y;
    --v5;
  }
  while ( v5 != 0 );
  this->lastTurnDelta = 0.0;
  this->lastTurnRate = 0.0;
  this->turnVelocity = 0.0;
  this->currentTurnDir = 0;
  this->previousTurnDir = 0;
  this->tolerance = 0.99984771;
  return this;
}


// ========================================================================
// ?Init@idAIOrientation@@QAAXABVidMat3@@@Z
// EA  : 0x82A5EB08
// RVA : 0x00A5EB08
// PDB : w:\tech5\tungsten\game\ai\aiorientation.cpp
// ========================================================================

void __fastcall idAIOrientation::Init(idAIOrientation *this, const idMat3 *axis)
{
  double z; // fp3

  this->axis = *axis;
  this->idealDir.x = axis->mat[0].x;
  this->idealDir.y = axis->mat[0].y;
  z = axis->mat[0].z;
  this->currentTurnDir = 0;
  this->previousTurnDir = 0;
  this->idealDir.z = z;
  this->lastTurnRate = 0.0;
  this->lastTurnDelta = 0.0;
  this->turnVelocity = 0.0;
}


// ========================================================================
// ?SetIdealDir@idAIOrientation@@QAAXPAVidAI2@@ABVidVec3@@@Z
// EA  : 0x82A5EB90
// RVA : 0x00A5EB90
// PDB : w:\tech5\tungsten\game\ai\aiorientation.cpp
// ========================================================================

void __fastcall idAIOrientation::SetIdealDir(idAIOrientation *this, idAI2 *ai, const idVec3 *dir)
{
  float y; // r10
  float z; // r9
  idPhysics *Physics; // r3
  const idVec3 *v7; // r3
  double x; // fp10
  double v9; // fp0
  double v10; // fp11
  double v11; // fp12
  double v12; // fp0
  double v15; // fp7
  double v16; // fp0
  idVec3 v17; // [sp+50h] [-20h] BYREF

  y = dir->y;
  z = dir->z;
  v17.x = dir->x;
  v17.y = y;
  v17.z = z;
  Physics = idEntity::GetPhysics(this: ai);
  v7 = Physics->GetGravityNormal(this: Physics);
  idVec3::ProjectOntoPlane(this: &v17, normal: v7, overBounce: 1.0);
  x = v17.x;
  v9 = idMath::FLT_SMALLEST_NON_DENORMAL;
  if ( __fabs(v17.x) <= idMath::FLT_SMALLEST_NON_DENORMAL )
    x = 0.0;
  v10 = v17.y;
  if ( __fabs(v17.y) <= v9 )
    v10 = 0.0;
  v11 = v17.z;
  if ( __fabs(v17.z) <= v9 )
    v11 = 0.0;
  v12 = (float)((float)((float)x * (float)x)
              + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10)));
  if ( v12 > 0.001 )
  {
    this->idealDir.x = x;
    this->idealDir.y = v10;
    this->idealDir.z = v11;
    _FP13 = (float)((float)((float)((float)x * (float)x)
                          + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10)))
                  - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f9, f13, f0, f9 }
    v15 = __frsqrte(_FP9);
    v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                        * (float)((float)v12 * (float)0.5))
                                                                                * (float)v15)
                                                                        - (float)1.5)
                                                        * (float)v15)
                                                * (float)((float)v12 * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v15
                                                                                * (float)((float)v12 * (float)0.5))
                                                                        * (float)v15)
                                                                - (float)1.5)
                                                * (float)v15))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)v12 * (float)0.5)) * (float)v15)
                                        - (float)1.5)
                        * (float)v15));
    this->idealDir.x = (float)((float)-(float)((float)((float)((float)v16
                                                             * (float)((float)((float)((float)x * (float)x)
                                                                             + (float)((float)((float)v11 * (float)v11)
                                                                                     + (float)((float)v10 * (float)v10)))
                                                                     * (float)0.5))
                                                     * (float)v16)
                                             - (float)1.5)
                             * (float)v16)
                     * (float)x;
    this->idealDir.y = (float)((float)-(float)((float)((float)((float)v16
                                                             * (float)((float)((float)((float)x * (float)x)
                                                                             + (float)((float)((float)v11 * (float)v11)
                                                                                     + (float)((float)v10 * (float)v10)))
                                                                     * (float)0.5))
                                                     * (float)v16)
                                             - (float)1.5)
                             * (float)v16)
                     * (float)v10;
    this->idealDir.z = (float)v11
                     * (float)((float)-(float)((float)((float)((float)v16
                                                             * (float)((float)((float)((float)x * (float)x)
                                                                             + (float)((float)((float)v11 * (float)v11)
                                                                                     + (float)((float)v10 * (float)v10)))
                                                                     * (float)0.5))
                                                     * (float)v16)
                                             - (float)1.5)
                             * (float)v16);
  }
}


// ========================================================================
// ?SetIdealDirTowards@idAIOrientation@@QAAXPAVidAI2@@ABVidVec3@@@Z
// EA  : 0x82A5ECD8
// RVA : 0x00A5ECD8
// PDB : w:\tech5\tungsten\game\ai\aiorientation.cpp
// ========================================================================

void __fastcall idAIOrientation::SetIdealDirTowards(idAIOrientation *this, idAI2 *ai, const idVec3 *point)
{
  idPhysics *Physics; // r3
  float *v7; // r3
  double v8; // fp7
  double v9; // fp6
  idVec3 v10; // [sp+50h] [-30h] BYREF

  Physics = idEntity::GetPhysics(this: ai);
  v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v8 = (float)(point->y - v7[1]);
  v9 = (float)(point->z - v7[2]);
  v10.x = point->x - *v7;
  v10.y = v8;
  v10.z = v9;
  idAIOrientation::SetIdealDir(this, ai, dir: &v10);
}


// ========================================================================
// ?UpdateFromAnim@idAIOrientation@@QAAXABVidMat3@@MW4turnDirection_t@@_N@Z
// EA  : 0x82A5ED58
// RVA : 0x00A5ED58
// PDB : w:\tech5\tungsten\game\ai\aiorientation.cpp
// ========================================================================

void __fastcall idAIOrientation::UpdateFromAnim(
        idAIOrientation *this,
        const idMat3 *axis,
        double turnRate,
        const turnDirection_t turnDir,
        unsigned __int8 updateIdeal,
        char a6)
{
  unsigned __int8 currentTurnDir; // r9

  currentTurnDir = this->currentTurnDir;
  this->lastTurnRate = turnRate;
  this->currentTurnDir = updateIdeal;
  this->previousTurnDir = currentTurnDir;
  this->lastTurnDelta = 0.0;
  this->axis = *axis;
  if ( a6 != 0 )
  {
    this->idealDir.x = axis->mat[0].x;
    this->idealDir.y = axis->mat[0].y;
    this->idealDir.z = axis->mat[0].z;
  }
}


// ========================================================================
// ?CalculateTurnDirection@idAIOrientation@@QBA?AW4turnDirection_t@@ABVidVec3@@@Z
// EA  : 0x82A5EDE8
// RVA : 0x00A5EDE8
// PDB : w:\tech5\tungsten\game\ai\aiorientation.cpp
// ========================================================================

turnDirection_t __fastcall idAIOrientation::CalculateTurnDirection(idAIOrientation *this, const idVec3 *normal)
{
  float y; // r9
  float z; // r8
  turnDirection_t result; // r3
  double v9; // fp2
  double v10; // fp2
  double v11; // fp2
  double v12; // fp2
  double v13; // fp10
  double v14; // fp6
  double v15; // fp5
  double v18; // fp12
  double v19; // fp9
  double v20; // fp13
  double v21; // fp11
  idVec3 v22; // [sp+50h] [-40h] BYREF

  y = this->axis.mat[0].y;
  z = this->axis.mat[0].z;
  v22.x = this->axis.mat[0].x;
  v22.y = y;
  v22.z = z;
  idVec3::ProjectOntoPlane(this: &v22, normal, overBounce: 1.0);
  result = TURN_LEFT;
  _FP31 = (float)((float)((float)(v22.z * v22.z) + (float)((float)(v22.y * v22.y) + (float)(v22.x * v22.x)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f31, f2, f13 }
  v9 = __frsqrte(_FP2);
  v10 = (float)((float)-(float)((float)((float)((float)v9
                                              * (float)((float)((float)(v22.z * v22.z)
                                                              + (float)((float)(v22.y * v22.y) + (float)(v22.x * v22.x)))
                                                      * (float)0.5))
                                      * (float)v9)
                              - (float)1.5)
              * (float)v9);
  v11 = (float)((float)-(float)((float)((float)((float)v10
                                              * (float)((float)((float)(v22.z * v22.z)
                                                              + (float)((float)(v22.y * v22.y) + (float)(v22.x * v22.x)))
                                                      * (float)0.5))
                                      * (float)v10)
                              - (float)1.5)
              * (float)v10);
  v12 = (float)((float)-(float)((float)((float)((float)v11
                                              * (float)((float)((float)(v22.z * v22.z)
                                                              + (float)((float)(v22.y * v22.y) + (float)(v22.x * v22.x)))
                                                      * (float)0.5))
                                      * (float)v11)
                              - (float)1.5)
              * (float)v11);
  v13 = (float)((float)(normal->x * (float)((float)v12 * v22.z)) - (float)(normal->z * (float)(v22.x * (float)v12)));
  v14 = (float)((float)(normal->y * (float)(v22.x * (float)v12)) - (float)(normal->x * (float)(v22.y * (float)v12)));
  v15 = (float)((float)(normal->z * (float)(v22.y * (float)v12)) - (float)(normal->y * (float)((float)v12 * v22.z)));
  _FP7 = (float)((float)((float)((float)v15 * (float)v15)
                       + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f13, f7, f11, f13 }
  v18 = __frsqrte(_FP13);
  v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18
                                                                                      * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)))
                                                                                              * (float)0.5))
                                                                              * (float)v18)
                                                                      - (float)1.5)
                                                      * (float)v18)
                                              * (float)((float)((float)((float)v15 * (float)v15)
                                                              + (float)((float)((float)v14 * (float)v14)
                                                                      + (float)((float)v13 * (float)v13)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v18
                                                                              * (float)((float)((float)((float)v15 * (float)v15)
                                                                                              + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)))
                                                                                      * (float)0.5))
                                                                      * (float)v18)
                                                              - (float)1.5)
                                              * (float)v18))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v18
                                                      * (float)((float)((float)((float)v15 * (float)v15)
                                                                      + (float)((float)((float)v14 * (float)v14)
                                                                              + (float)((float)v13 * (float)v13)))
                                                              * (float)0.5))
                                              * (float)v18)
                                      - (float)1.5)
                      * (float)v18));
  v20 = (float)((float)v13
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5)) * (float)v18) - (float)1.5) * (float)v18)
                                                                                              * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                              * (float)v18))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5))
                                                                                              * (float)v18)
                                                                                      - (float)1.5)
                                                                      * (float)v18))
                                                      * (float)((float)((float)((float)v15 * (float)v15)
                                                                      + (float)((float)((float)v14 * (float)v14)
                                                                              + (float)((float)v13 * (float)v13)))
                                                              * (float)0.5))
                                              * (float)v19)
                                      - (float)1.5)
                      * (float)v19));
  v21 = (float)((float)v15
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5)) * (float)v18) - (float)1.5) * (float)v18)
                                                                                              * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                              * (float)v18))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5))
                                                                                              * (float)v18)
                                                                                      - (float)1.5)
                                                                      * (float)v18))
                                                      * (float)((float)((float)((float)v15 * (float)v15)
                                                                      + (float)((float)((float)v14 * (float)v14)
                                                                              + (float)((float)v13 * (float)v13)))
                                                              * (float)0.5))
                                              * (float)v19)
                                      - (float)1.5)
                      * (float)v19));
  if ( (float)((float)(this->idealDir.x * (float)v21)
             + (float)((float)(this->idealDir.z
                             * (float)((float)v14
                                     * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5)) * (float)v18) - (float)1.5) * (float)v18) * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5)) * (float)v18) - (float)1.5) * (float)v18)) - (float)1.5)
                                                                                     * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                             * (float)v18))
                                                                             * (float)((float)((float)((float)v15 * (float)v15)
                                                                                             + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)))
                                                                                     * (float)0.5))
                                                                     * (float)v19)
                                                             - (float)1.5)
                                             * (float)v19)))
                     + (float)(this->idealDir.y * (float)v20))) < 0.0 )
    return TURN_RIGHT;
  return result;
}


// ========================================================================
// ?CalcTurnRateForTime@idAIOrientation@@QBAMABVidVec3@@0M@Z
// EA  : 0x82A5EF70
// RVA : 0x00A5EF70
// PDB : w:\tech5\tungsten\game\ai\aiorientation.cpp
// ========================================================================

float __fastcall idAIOrientation::CalcTurnRateForTime(
        idAIOrientation *this,
        const idVec3 *rotationAxis,
        const idVec3 *destDir,
        double timeSeconds)
{
  double v6; // fp1
  float y; // r9
  float z; // r8
  double v11; // fp9
  double v12; // fp2
  double v13; // fp9
  long double v14; // fp2
  idVec3 v16; // [sp+50h] [-30h] BYREF

  if ( timeSeconds >= 0.000099999997 )
  {
    y = destDir->y;
    z = destDir->z;
    v16.x = destDir->x;
    v16.y = y;
    v16.z = z;
    idVec3::ProjectOntoPlane(this: &v16, normal: rotationAxis, overBounce: 1.0);
    _FP2 = (float)((float)((float)(v16.y * v16.y) + (float)((float)(v16.z * v16.z) + (float)(v16.x * v16.x)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f13, f2, f3, f13 }
    v11 = __frsqrte(_FP13);
    v12 = (float)((float)-(float)((float)((float)((float)v11
                                                * (float)((float)((float)(v16.y * v16.y)
                                                                + (float)((float)(v16.z * v16.z) + (float)(v16.x * v16.x)))
                                                        * (float)0.5))
                                        * (float)v11)
                                - (float)1.5)
                * (float)v11);
    v13 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11
                                                                                * (float)((float)((float)(v16.y * v16.y)
                                                                                                + (float)((float)(v16.z * v16.z) + (float)(v16.x * v16.x)))
                                                                                        * (float)0.5))
                                                                        * (float)v11)
                                                                - (float)1.5)
                                                * (float)v11)
                                        * (float)((float)((float)(v16.y * v16.y)
                                                        + (float)((float)(v16.z * v16.z) + (float)(v16.x * v16.x)))
                                                * (float)0.5))
                                * (float)((float)-(float)((float)((float)((float)v11
                                                                        * (float)((float)((float)(v16.y * v16.y)
                                                                                        + (float)((float)(v16.z * v16.z)
                                                                                                + (float)(v16.x * v16.x)))
                                                                                * (float)0.5))
                                                                * (float)v11)
                                                        - (float)1.5)
                                        * (float)v11))
                        - (float)1.5);
    *((double *)&v14 + 1) = (float)((float)-(float)((float)((float)((float)((float)v13 * (float)v12)
                                                                  * (float)((float)((float)(v16.y * v16.y)
                                                                                  + (float)((float)(v16.z * v16.z)
                                                                                          + (float)(v16.x * v16.x)))
                                                                          * (float)0.5))
                                                          * (float)((float)v13 * (float)v12))
                                                  - (float)1.5)
                                  * (float)((float)v13 * (float)v12));
    *(double *)&v14 = (float)((float)(this->axis.mat[0].x * (float)(v16.x * (float)*((double *)&v14 + 1)))
                            + (float)((float)(this->axis.mat[0].z * (float)(v16.z * (float)*((double *)&v14 + 1)))
                                    + (float)(this->axis.mat[0].y * (float)((float)*((double *)&v14 + 1) * v16.y))));
    v6 = (float)((float)(idMath::ACos(a: v14) * idMath::M_RAD2DEG) / (float)timeSeconds);
  }
  else
  {
    v6 = 0.0;
  }
  return *((float *)&v6 + 1);
}


// ========================================================================
// ?IsAligned@idAIOrientation@@QBA_NXZ
// EA  : 0x82A5F088
// RVA : 0x00A5F088
// PDB : w:\tech5\tungsten\game\ai\aiorientation.cpp
// ========================================================================

BOOL __fastcall idAIOrientation::IsAligned(idAIOrientation *this)
{
  return (float)((float)(this->axis.mat[0].x * this->idealDir.x)
               + (float)((float)(this->axis.mat[0].z * this->idealDir.z)
                       + (float)(this->axis.mat[0].y * this->idealDir.y))) > (double)this->tolerance;
}


// ========================================================================
// ?IsAligned@idAIOrientation@@QBA_NABVidVec3@@M@Z
// EA  : 0x82A5F0C8
// RVA : 0x00A5F0C8
// PDB : w:\tech5\tungsten\game\ai\aiorientation.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
BOOL __fastcall idAIOrientation::IsAligned(idAIOrientation *this, const idVec3 *testIdeal, double degrees)
{
  long double v3; // fp2
  double v4; // fp31
  long double v5; // fp2

  *(double *)&v3 = (float)(idMath::M_DEG2RAD * (float)degrees);
  v4 = (float)((float)(this->axis.mat[0].x * testIdeal->x)
             + (float)((float)(this->axis.mat[0].z * testIdeal->z) + (float)(this->axis.mat[0].y * testIdeal->y)));
  v5 = cos(x: v3);
  return v4 > (float)*(double *)&v5;
}


// ========================================================================
// ?SetAxis@idAIOrientation@@QAAXABVidVec3@@0@Z
// EA  : 0x82A5F138
// RVA : 0x00A5F138
// PDB : w:\tech5\tungsten\game\ai\aiorientation.cpp
// ========================================================================

void __fastcall idAIOrientation::SetAxis(idAIOrientation *this, const idVec3 *dir, const idVec3 *gravityDir)
{
  double y; // fp10
  double v4; // fp6
  double v5; // fp8
  double v6; // fp3
  double z; // fp5
  double v8; // fp12
  double v9; // fp13

  this->axis.mat[0] = *dir;
  y = gravityDir->y;
  v4 = (float)(gravityDir->x * (float)-1.0);
  v5 = (float)(gravityDir->z * (float)-1.0);
  this->axis.mat[2].z = gravityDir->z * (float)-1.0;
  this->axis.mat[2].y = (float)y * (float)-1.0;
  this->axis.mat[2].x = v4;
  v6 = this->axis.mat[0].y;
  z = this->axis.mat[0].z;
  v8 = (float)((float)v5 * this->axis.mat[0].y);
  v9 = (float)(this->axis.mat[0].x * (float)((float)y * (float)-1.0));
  this->axis.mat[1].y = (float)(this->axis.mat[0].x * (float)v5) - (float)((float)v4 * this->axis.mat[0].z);
  this->axis.mat[1].x = (float)((float)((float)y * (float)-1.0) * (float)z) - (float)v8;
  this->axis.mat[1].z = (float)((float)v4 * (float)v6) - (float)v9;
  idMat3::OrthoNormalizeSelf(this: &this->axis);
}


// ========================================================================
// ?SetAxis@idAIOrientation@@QAAXABVidMat3@@@Z
// EA  : 0x82A5F1C8
// RVA : 0x00A5F1C8
// PDB : w:\tech5\tungsten\game\ai\aiorientation.cpp
// ========================================================================

void __fastcall idAIOrientation::SetAxis(idAIOrientation *this, const idMat3 *axis)
{
  this->axis = *axis;
}


// ========================================================================
// ?UpdateAxis@idAIOrientation@@QAA?AW4turnDirection_t@@ABVidVec3@@MM@Z
// EA  : 0x82A5F218
// RVA : 0x00A5F218
// PDB : w:\tech5\tungsten\game\ai\aiorientation.cpp
// ========================================================================

turnDirection_t __fastcall idAIOrientation::UpdateAxis(
        idAIOrientation *this,
        const idVec3 *normal,
        double turnRate,
        double timeSeconds)
{
  unsigned __int8 currentTurnDir; // r11
  idMat3 *p_axis; // r29
  float x; // r8
  float y; // r7
  double v12; // fp8
  double v13; // fp13
  double z; // fp7
  double v15; // fp6
  double tolerance; // fp5
  double v19; // fp1
  double v20; // fp1
  double v21; // fp1
  double v22; // fp1
  double v23; // fp11
  double v24; // fp10
  double v25; // fp1
  double v26; // fp12
  double v27; // fp28
  double v28; // fp3
  double v29; // fp12
  long double v30; // fp2
  double v33; // fp9
  double v34; // fp9
  double v35; // fp10
  double v36; // fp9
  double v37; // fp12
  turnDirection_t result; // r3
  double v39; // fp30
  double v42; // fp0
  double v43; // fp30
  double v44; // fp29
  const idMat3 *v45; // r3
  unsigned __int8 v46; // r11
  idVec3 v47; // [sp+50h] [-B0h] BYREF
  idRotation v48; // [sp+60h] [-A0h] BYREF

  currentTurnDir = this->currentTurnDir;
  this->currentTurnDir = 0;
  this->previousTurnDir = currentTurnDir;
  p_axis = &this->axis;
  x = this->axis.mat[0].x;
  y = this->axis.mat[0].y;
  v47.z = this->axis.mat[0].z;
  v47.y = y;
  v47.x = x;
  idVec3::ProjectOntoPlane(this: &v47, normal, overBounce: 1.0);
  v12 = this->idealDir.y;
  v13 = idMath::FLT_SMALLEST_NON_DENORMAL;
  z = this->idealDir.z;
  v15 = this->idealDir.x;
  tolerance = this->tolerance;
  _FP28 = (float)((float)((float)(v47.x * v47.x) + (float)((float)(v47.z * v47.z) + (float)(v47.y * v47.y)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f1, f28, f1, f13 }
  v19 = __frsqrte(_FP1);
  v20 = (float)((float)-(float)((float)((float)((float)v19
                                              * (float)((float)((float)(v47.x * v47.x)
                                                              + (float)((float)(v47.z * v47.z) + (float)(v47.y * v47.y)))
                                                      * (float)0.5))
                                      * (float)v19)
                              - (float)1.5)
              * (float)v19);
  v21 = (float)((float)-(float)((float)((float)((float)v20
                                              * (float)((float)((float)(v47.x * v47.x)
                                                              + (float)((float)(v47.z * v47.z) + (float)(v47.y * v47.y)))
                                                      * (float)0.5))
                                      * (float)v20)
                              - (float)1.5)
              * (float)v20);
  v22 = (float)((float)-(float)((float)((float)((float)v21
                                              * (float)((float)((float)(v47.x * v47.x)
                                                              + (float)((float)(v47.z * v47.z) + (float)(v47.y * v47.y)))
                                                      * (float)0.5))
                                      * (float)v21)
                              - (float)1.5)
              * (float)v21);
  v23 = (float)(v47.z * (float)v22);
  v24 = (float)(v47.x * (float)v22);
  v26 = (float)(normal->y * (float)(v47.z * (float)v22));
  v27 = (float)(normal->z * (float)(v47.x * (float)v22));
  v25 = (float)(v47.y * (float)v22);
  v28 = (float)((float)(normal->z * (float)v25) - (float)v26);
  *((double *)&v30 + 1) = (float)((float)(normal->x * (float)v23) - (float)v27);
  v29 = (float)((float)(normal->y * (float)v24) - (float)(normal->x * (float)v25));
  *(double *)&v30 = (float)((float)(this->idealDir.x * (float)v24)
                          + (float)((float)(this->idealDir.z * (float)v23) + (float)(this->idealDir.y * (float)v25)));
  this->lastTurnDelta = *(double *)&v30;
  _FP4 = (float)((float)((float)((float)v29 * (float)v29)
                       + (float)((float)((float)*((double *)&v30 + 1) * (float)*((double *)&v30 + 1))
                               + (float)((float)v28 * (float)v28)))
               - (float)v13);
  __asm { fsel      f10, f4, f10, f13 }
  v33 = __frsqrte(_FP10);
  v34 = (float)((float)-(float)((float)((float)((float)v33
                                              * (float)((float)((float)((float)v29 * (float)v29)
                                                              + (float)((float)((float)*((double *)&v30 + 1)
                                                                              * (float)*((double *)&v30 + 1))
                                                                      + (float)((float)v28 * (float)v28)))
                                                      * (float)0.5))
                                      * (float)v33)
                              - (float)1.5)
              * (float)v33);
  v35 = (float)((float)-(float)((float)((float)((float)v34
                                              * (float)((float)((float)((float)v29 * (float)v29)
                                                              + (float)((float)((float)*((double *)&v30 + 1)
                                                                              * (float)*((double *)&v30 + 1))
                                                                      + (float)((float)v28 * (float)v28)))
                                                      * (float)0.5))
                                      * (float)v34)
                              - (float)1.5)
              * (float)v34);
  v36 = (float)((float)((float)-(float)((float)((float)((float)v34
                                                      * (float)((float)((float)((float)v29 * (float)v29)
                                                                      + (float)((float)((float)*((double *)&v30 + 1)
                                                                                      * (float)*((double *)&v30 + 1))
                                                                              + (float)((float)v28 * (float)v28)))
                                                              * (float)0.5))
                                              * (float)v34)
                                      - (float)1.5)
                      * (float)v34)
              * (float)((float)((float)((float)v29 * (float)v29)
                              + (float)((float)((float)*((double *)&v30 + 1) * (float)*((double *)&v30 + 1))
                                      + (float)((float)v28 * (float)v28)))
                      * (float)0.5));
  v37 = (float)((float)((float)-(float)((float)((float)v36 * (float)v35) - (float)1.5) * (float)v35) * (float)v29);
  if ( *(double *)&v30 <= tolerance )
  {
    this->lastTurnRate = turnRate;
    v39 = (float)((float)turnRate * (float)timeSeconds);
    _FP9 = (float)((float)((float)v15
                         * (float)((float)v28
                                 * (float)((float)-(float)((float)((float)v36 * (float)v35) - (float)1.5) * (float)v35)))
                 + (float)((float)((float)z * (float)v37)
                         + (float)((float)v12
                                 * (float)((float)*((double *)&v30 + 1)
                                         * (float)((float)-(float)((float)((float)v36 * (float)v35) - (float)1.5)
                                                 * (float)v35)))));
    __asm { fsel      f31, f9, f31, f13 }
    v42 = (float)(idMath::ACos(a: v30) * idMath::M_RAD2DEG);
    if ( v42 >= v39 )
      v42 = v39;
    v43 = normal->y;
    v44 = normal->z;
    v48.vec.x = normal->x;
    v48.axisValid = false;
    v48.origin.x = vec3_origin.x;
    v48.vec.y = v43;
    v48.origin.y = vec3_origin.y;
    v48.vec.z = v44;
    v48.origin.z = vec3_origin.z;
    v48.angle = (float)v42 * (float)_FP31;
    v48.axis.mat[0].x = mat3_identity.mat[0].x;
    v48.axis.mat[0].y = mat3_identity.mat[0].y;
    v48.axis.mat[0].z = mat3_identity.mat[0].z;
    v48.axis.mat[1].x = mat3_identity.mat[1].x;
    v48.axis.mat[1].y = mat3_identity.mat[1].y;
    v48.axis.mat[1].z = mat3_identity.mat[1].z;
    v48.axis.mat[2].x = mat3_identity.mat[2].x;
    v48.axis.mat[2].y = mat3_identity.mat[2].y;
    v48.axis.mat[2].z = mat3_identity.mat[2].z;
    v45 = idRotation::ToMat3(this: &v48);
    idMat3::operator*=(this: p_axis, a: v45);
    idMat3::FixDenormals(this: p_axis);
    idMat3::OrthoNormalizeSelf(this: p_axis);
    v46 = 1;
    if ( _FP31 <= 0.0 )
      v46 = 2;
    this->turnVelocity = 0.0;
    this->currentTurnDir = v46;
    return v46;
  }
  else
  {
    if ( tolerance >= 0.99984771 )
      idAIOrientation::SetAxis(this, dir: &this->idealDir, gravityDir: normal);
    result = this->currentTurnDir;
    this->lastTurnRate = 0.0;
    this->lastTurnDelta = 0.0;
  }
  return result;
}


// ========================================================================
// ?UpdateBodyAxis@idAIOrientation@@QAA?AW4turnDirection_t@@ABVidVec3@@W42@MM@Z
// EA  : 0x82A5F4F8
// RVA : 0x00A5F4F8
// PDB : w:\tech5\tungsten\game\ai\aiorientation.cpp
// ========================================================================

turnDirection_t __fastcall idAIOrientation::UpdateBodyAxis(
        idAIOrientation *this,
        const idVec3 *normal,
        const turnDirection_t turnDir,
        double turnRate,
        double timeSeconds)
{
  unsigned __int8 currentTurnDir; // r11
  float x; // r8
  idMat3 *p_axis; // r30
  float y; // r7
  double v14; // fp31
  double tolerance; // fp9
  double v18; // fp3
  double v19; // fp1
  double v20; // fp7
  double v21; // fp3
  long double v22; // fp2
  turnDirection_t result; // r3
  double v24; // fp30
  double v25; // fp0
  double v26; // fp30
  double z; // fp29
  const idMat3 *v28; // r3
  unsigned __int8 v29; // r11
  idVec3 v30; // [sp+50h] [-A0h] BYREF
  idRotation v31; // [sp+60h] [-90h] BYREF

  currentTurnDir = this->currentTurnDir;
  this->currentTurnDir = 0;
  this->previousTurnDir = currentTurnDir;
  x = this->axis.mat[0].x;
  p_axis = &this->axis;
  y = this->axis.mat[0].y;
  v14 = 1.0;
  v30.z = this->axis.mat[0].z;
  v30.y = y;
  v30.x = x;
  idVec3::ProjectOntoPlane(this: &v30, normal, overBounce: 1.0);
  tolerance = this->tolerance;
  _FP1 = (float)((float)((float)(v30.x * v30.x) + (float)((float)(v30.z * v30.z) + (float)(v30.y * v30.y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f7, f1, f2, f13 }
  v18 = __frsqrte(_FP7);
  v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18
                                                                                      * (float)((float)((float)(v30.x * v30.x) + (float)((float)(v30.z * v30.z) + (float)(v30.y * v30.y)))
                                                                                              * (float)0.5))
                                                                              * (float)v18)
                                                                      - (float)1.5)
                                                      * (float)v18)
                                              * (float)((float)((float)(v30.x * v30.x)
                                                              + (float)((float)(v30.z * v30.z) + (float)(v30.y * v30.y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v18
                                                                              * (float)((float)((float)(v30.x * v30.x)
                                                                                              + (float)((float)(v30.z * v30.z) + (float)(v30.y * v30.y)))
                                                                                      * (float)0.5))
                                                                      * (float)v18)
                                                              - (float)1.5)
                                              * (float)v18))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v18
                                                      * (float)((float)((float)(v30.x * v30.x)
                                                                      + (float)((float)(v30.z * v30.z)
                                                                              + (float)(v30.y * v30.y)))
                                                              * (float)0.5))
                                              * (float)v18)
                                      - (float)1.5)
                      * (float)v18));
  v20 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v30.x * v30.x) + (float)((float)(v30.z * v30.z) + (float)(v30.y * v30.y))) * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                              * (float)v18)
                                                                                      * (float)((float)((float)(v30.x * v30.x) + (float)((float)(v30.z * v30.z) + (float)(v30.y * v30.y)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v30.x * v30.x) + (float)((float)(v30.z * v30.z) + (float)(v30.y * v30.y))) * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                      * (float)v18))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v18
                                                                                              * (float)((float)((float)(v30.x * v30.x) + (float)((float)(v30.z * v30.z) + (float)(v30.y * v30.y))) * (float)0.5))
                                                                                      * (float)v18)
                                                                              - (float)1.5)
                                                              * (float)v18))
                                              * (float)((float)((float)(v30.x * v30.x)
                                                              + (float)((float)(v30.z * v30.z) + (float)(v30.y * v30.y)))
                                                      * (float)0.5))
                                      * (float)v19)
                              - (float)1.5)
              * (float)v19);
  *((double *)&v22 + 1) = (float)(v30.z
                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v30.x * v30.x) + (float)((float)(v30.z * v30.z) + (float)(v30.y * v30.y))) * (float)0.5)) * (float)v18) - (float)1.5) * (float)v18) * (float)((float)((float)(v30.x * v30.x) + (float)((float)(v30.z * v30.z) + (float)(v30.y * v30.y))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v30.x * v30.x) + (float)((float)(v30.z * v30.z) + (float)(v30.y * v30.y))) * (float)0.5)) * (float)v18) - (float)1.5) * (float)v18))
                                                                                                - (float)1.5)
                                                                                * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v30.x * v30.x) + (float)((float)(v30.z * v30.z) + (float)(v30.y * v30.y))) * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                        * (float)v18))
                                                                        * (float)((float)((float)(v30.x * v30.x)
                                                                                        + (float)((float)(v30.z * v30.z)
                                                                                                + (float)(v30.y * v30.y)))
                                                                                * (float)0.5))
                                                                * (float)v19)
                                                        - (float)1.5)
                                        * (float)v19));
  v21 = (float)(v30.y
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v30.x * v30.x) + (float)((float)(v30.z * v30.z) + (float)(v30.y * v30.y))) * (float)0.5)) * (float)v18) - (float)1.5) * (float)v18)
                                                                                              * (float)((float)((float)(v30.x * v30.x) + (float)((float)(v30.z * v30.z) + (float)(v30.y * v30.y))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v30.x * v30.x) + (float)((float)(v30.z * v30.z) + (float)(v30.y * v30.y))) * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                              * (float)v18))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v30.x * v30.x) + (float)((float)(v30.z * v30.z) + (float)(v30.y * v30.y))) * (float)0.5))
                                                                                              * (float)v18)
                                                                                      - (float)1.5)
                                                                      * (float)v18))
                                                      * (float)((float)((float)(v30.x * v30.x)
                                                                      + (float)((float)(v30.z * v30.z)
                                                                              + (float)(v30.y * v30.y)))
                                                              * (float)0.5))
                                              * (float)v19)
                                      - (float)1.5)
                      * (float)v19));
  *(double *)&v22 = (float)((float)(this->idealDir.x * (float)(v30.x * (float)v20))
                          + (float)((float)(this->idealDir.z * (float)*((double *)&v22 + 1))
                                  + (float)(this->idealDir.y * (float)v21)));
  this->lastTurnDelta = (float)(this->idealDir.x * (float)(v30.x * (float)v20))
                      + (float)((float)(this->idealDir.z * (float)*((double *)&v22 + 1))
                              + (float)(this->idealDir.y * (float)v21));
  if ( *(double *)&v22 <= tolerance )
  {
    this->lastTurnRate = turnRate;
    if ( turnDir != TURN_LEFT )
      v14 = -1.0;
    v24 = (float)((float)turnRate * (float)timeSeconds);
    v25 = (float)(idMath::ACos(a: v22) * idMath::M_RAD2DEG);
    if ( v25 >= v24 )
      v25 = v24;
    v26 = normal->y;
    z = normal->z;
    v31.vec.x = normal->x;
    v31.axisValid = false;
    v31.origin.x = vec3_origin.x;
    v31.vec.y = v26;
    v31.origin.y = vec3_origin.y;
    v31.vec.z = z;
    v31.origin.z = vec3_origin.z;
    v31.angle = (float)v25 * (float)v14;
    v31.axis.mat[0].x = mat3_identity.mat[0].x;
    v31.axis.mat[0].y = mat3_identity.mat[0].y;
    v31.axis.mat[0].z = mat3_identity.mat[0].z;
    v31.axis.mat[1].x = mat3_identity.mat[1].x;
    v31.axis.mat[1].y = mat3_identity.mat[1].y;
    v31.axis.mat[1].z = mat3_identity.mat[1].z;
    v31.axis.mat[2].x = mat3_identity.mat[2].x;
    v31.axis.mat[2].y = mat3_identity.mat[2].y;
    v31.axis.mat[2].z = mat3_identity.mat[2].z;
    v28 = idRotation::ToMat3(this: &v31);
    idMat3::operator*=(this: p_axis, a: v28);
    idMat3::FixDenormals(this: p_axis);
    idMat3::OrthoNormalizeSelf(this: p_axis);
    v29 = 1;
    if ( v14 <= 0.0 )
      v29 = 2;
    this->currentTurnDir = v29;
    return v29;
  }
  else
  {
    if ( tolerance >= 0.99984771 )
      idAIOrientation::SetAxis(this, dir: &this->idealDir, gravityDir: normal);
    result = this->currentTurnDir;
    this->lastTurnRate = 0.0;
    this->lastTurnDelta = 0.0;
  }
  return result;
}


// ========================================================================
// ?Update@idAIOrientation@@QAAXABVidVec3@@000MMM@Z
// EA  : 0x82A5F768
// RVA : 0x00A5F768
// PDB : w:\tech5\tungsten\game\ai\aiorientation.cpp
// ========================================================================

void __fastcall idAIOrientation::Update(
        idAIOrientation *this,
        const idVec3 *vel,
        const idVec3 *origin,
        const idVec3 *dest,
        const idVec3 *gravityDir,
        double turnRate,
        double maxTurnRate,
        double timeSeconds)
{
  float y; // r9
  float z; // r8
  idMat3 *p_axis; // r26
  double v18; // fp13
  double v19; // fp10
  double v20; // fp12
  double x; // fp11
  double v22; // fp9
  double v23; // fp6
  double v24; // fp7
  double v25; // fp8
  double v26; // fp0
  double v27; // fp5
  double tolerance; // fp10
  double v31; // fp1
  double v32; // fp2
  double v33; // fp2
  double v34; // fp13
  double v35; // fp12
  double v36; // fp4
  double v37; // fp11
  double v38; // fp9
  double v39; // fp8
  long double v40; // fp2
  double v43; // fp13
  double v44; // fp0
  double v45; // fp13
  double v46; // fp24
  double v47; // fp23
  double v48; // fp22
  double v49; // fp1
  double v50; // fp8
  double v51; // fp6
  double v52; // fp28
  double v53; // fp26
  double v54; // fp13
  double v55; // fp12
  double v57; // fp8
  double v59; // fp4
  double v60; // fp0
  double v61; // fp0
  double v64; // fp30
  double v65; // fp29
  const idMat3 *v66; // r3
  unsigned __int8 v67; // r11
  idVec3 v68; // [sp+50h] [-F0h] BYREF
  idRotation v69; // [sp+60h] [-E0h] BYREF

  y = this->axis.mat[0].y;
  z = this->axis.mat[0].z;
  p_axis = &this->axis;
  v68.x = this->axis.mat[0].x;
  v68.y = y;
  v68.z = z;
  idVec3::ProjectOntoPlane(this: &v68, normal: gravityDir, overBounce: 1.0);
  v18 = v68.y;
  v19 = (float)(v68.y * v68.y);
  v20 = v68.z;
  x = v68.x;
  v22 = gravityDir->x;
  v23 = this->idealDir.z;
  v24 = gravityDir->y;
  v25 = gravityDir->z;
  v26 = idMath::FLT_SMALLEST_NON_DENORMAL;
  v27 = this->idealDir.x;
  this->previousTurnDir = this->currentTurnDir;
  _FP1 = (float)((float)((float)((float)x * (float)x) + (float)((float)((float)v20 * (float)v20) + (float)v19))
               - (float)v26);
  __asm { fsel      f2, f1, f2, f0 }
  v31 = __frsqrte(_FP2);
  v32 = (float)((float)-(float)((float)((float)((float)v31
                                              * (float)((float)((float)((float)x * (float)x)
                                                              + (float)((float)((float)v20 * (float)v20) + (float)v19))
                                                      * (float)0.5))
                                      * (float)v31)
                              - (float)1.5)
              * (float)v31);
  v33 = (float)((float)-(float)((float)((float)((float)v32
                                              * (float)((float)((float)((float)x * (float)x)
                                                              + (float)((float)((float)v20 * (float)v20) + (float)v19))
                                                      * (float)0.5))
                                      * (float)v32)
                              - (float)1.5)
              * (float)v32);
  *((double *)&v40 + 1) = (float)((float)-(float)((float)((float)((float)v33
                                                                * (float)((float)((float)((float)x * (float)x)
                                                                                + (float)((float)((float)v20 * (float)v20)
                                                                                        + (float)v19))
                                                                        * (float)0.5))
                                                        * (float)v33)
                                                - (float)1.5)
                                * (float)v33);
  tolerance = this->tolerance;
  *(double *)&v40 = (float)((float)v18 * (float)*((double *)&v40 + 1));
  v34 = (float)((float)x * (float)*((double *)&v40 + 1));
  v35 = (float)((float)v20 * (float)*((double *)&v40 + 1));
  v36 = (float)((float)v25 * (float)((float)x * (float)*((double *)&v40 + 1)));
  v37 = (float)((float)((float)v24 * (float)((float)x * (float)*((double *)&v40 + 1)))
              - (float)((float)v22 * (float)*(double *)&v40));
  v38 = (float)((float)((float)v22 * (float)v35) - (float)v36);
  v39 = (float)((float)((float)v25 * (float)*(double *)&v40) - (float)((float)v24 * (float)v35));
  *(double *)&v40 = (float)((float)(this->idealDir.y * (float)*(double *)&v40)
                          + (float)((float)((float)v27 * (float)v34) + (float)((float)v23 * (float)v35)));
  _FP3 = (float)((float)((float)((float)v39 * (float)v39)
                       + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37)))
               - (float)v26);
  __asm { fsel      f0, f3, f4, f0 }
  v43 = __frsqrte(_FP0);
  v44 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v43
                                                                                      * (float)((float)((float)((float)v39 * (float)v39) + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37)))
                                                                                              * (float)0.5))
                                                                              * (float)v43)
                                                                      - (float)1.5)
                                                      * (float)v43)
                                              * (float)((float)((float)((float)v39 * (float)v39)
                                                              + (float)((float)((float)v38 * (float)v38)
                                                                      + (float)((float)v37 * (float)v37)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v43
                                                                              * (float)((float)((float)((float)v39 * (float)v39)
                                                                                              + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37)))
                                                                                      * (float)0.5))
                                                                      * (float)v43)
                                                              - (float)1.5)
                                              * (float)v43))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v43
                                                      * (float)((float)((float)((float)v39 * (float)v39)
                                                                      + (float)((float)((float)v38 * (float)v38)
                                                                              + (float)((float)v37 * (float)v37)))
                                                              * (float)0.5))
                                              * (float)v43)
                                      - (float)1.5)
                      * (float)v43));
  v45 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v43
                                                                                              * (float)((float)((float)((float)v39 * (float)v39) + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37))) * (float)0.5))
                                                                                      * (float)v43)
                                                                              - (float)1.5)
                                                              * (float)v43)
                                                      * (float)((float)((float)((float)v39 * (float)v39)
                                                                      + (float)((float)((float)v38 * (float)v38)
                                                                              + (float)((float)v37 * (float)v37)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v43
                                                                                      * (float)((float)((float)((float)v39 * (float)v39) + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37)))
                                                                                              * (float)0.5))
                                                                              * (float)v43)
                                                                      - (float)1.5)
                                                      * (float)v43))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v43
                                                              * (float)((float)((float)((float)v39 * (float)v39)
                                                                              + (float)((float)((float)v38 * (float)v38)
                                                                                      + (float)((float)v37 * (float)v37)))
                                                                      * (float)0.5))
                                                      * (float)v43)
                                              - (float)1.5)
                              * (float)v43))
              * (float)((float)((float)((float)v39 * (float)v39)
                              + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37)))
                      * (float)0.5));
  v46 = (float)((float)v39 * (float)((float)-(float)((float)((float)v45 * (float)v44) - (float)1.5) * (float)v44));
  v47 = (float)((float)v38 * (float)((float)-(float)((float)((float)v45 * (float)v44) - (float)1.5) * (float)v44));
  v48 = (float)((float)v37 * (float)((float)-(float)((float)((float)v45 * (float)v44) - (float)1.5) * (float)v44));
  if ( *(double *)&v40 <= tolerance )
  {
    *((double *)&v40 + 1) = (float)((float)((float)((float)v39 * (float)v39)
                                          + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37)))
                                  * (float)0.5);
    v49 = idMath::ACos(a: v40);
    v50 = (float)(dest->y - origin->y);
    v51 = (float)(dest->z - origin->z);
    v68.x = dest->x - origin->x;
    v68.y = v50;
    v68.z = v51;
    v52 = (float)((float)v49 * idMath::M_RAD2DEG);
    v53 = (float)((float)((float)v49 * idMath::M_RAD2DEG) / (float)turnRate);
    idVec3::ProjectOntoPlane(this: &v68, normal: gravityDir, overBounce: 1.0);
    v54 = idMath::FLT_SMALLEST_NON_DENORMAL;
    v55 = 9999.0;
    if ( (float)((float)(vel->z * vel->z) + (float)((float)(vel->x * vel->x) + (float)(vel->y * vel->y))) > (double)idMath::FLT_SMALLEST_NON_DENORMAL )
    {
      _FP9 = (float)((float)((float)(vel->z * vel->z) + (float)((float)(vel->x * vel->x) + (float)(vel->y * vel->y)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      v57 = (float)((float)((float)(vel->z * vel->z) + (float)((float)(vel->x * vel->x) + (float)(vel->y * vel->y)))
                  * (float)0.5);
      __asm { fsel      f6, f9, f0, f13 }
      v59 = __frsqrte(_FP6);
      v60 = (float)((float)v59
                  * (float)((float)((float)(vel->z * vel->z)
                                  + (float)((float)(vel->x * vel->x) + (float)(vel->y * vel->y)))
                          * (float)0.5));
      v55 = (float)((float)__fsqrts((float)((float)(v68.x * v68.x)
                                          + (float)((float)(v68.z * v68.z) + (float)(v68.y * v68.y))))
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v60 * (float)v59) - (float)1.5) * (float)v59)
                                                                                                  * (float)v57)
                                                                                          * (float)((float)-(float)((float)((float)v60 * (float)v59) - (float)1.5)
                                                                                                  * (float)v59))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)v60
                                                                                                  * (float)v59)
                                                                                          - (float)1.5)
                                                                          * (float)v59))
                                                          * (float)v57)
                                                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v60 * (float)v59) - (float)1.5)
                                                                                                  * (float)v59)
                                                                                          * (float)v57)
                                                                                  * (float)((float)-(float)((float)((float)v60 * (float)v59) - (float)1.5)
                                                                                          * (float)v59))
                                                                          - (float)1.5)
                                                          * (float)((float)-(float)((float)((float)v60 * (float)v59)
                                                                                  - (float)1.5)
                                                                  * (float)v59)))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v60
                                                                                                  * (float)v59)
                                                                                          - (float)1.5)
                                                                          * (float)v59)
                                                                  * (float)v57)
                                                          * (float)((float)-(float)((float)((float)v60 * (float)v59)
                                                                                  - (float)1.5)
                                                                  * (float)v59))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)v60 * (float)v59) - (float)1.5) * (float)v59))));
    }
    if ( v53 <= v55 )
    {
      this->lastTurnRate = turnRate;
    }
    else if ( v55 > v54 )
    {
      this->lastTurnRate = (float)v52 / (float)v55;
    }
    else if ( timeSeconds < v54 )
    {
      this->lastTurnRate = v52;
    }
    else
    {
      this->lastTurnRate = (float)((float)1.0 / (float)timeSeconds) * (float)v52;
    }
    v61 = (float)(this->lastTurnRate * (float)timeSeconds);
    _FP7 = (float)((float)(this->idealDir.y * (float)v47)
                 + (float)((float)(this->idealDir.x * (float)v46) + (float)(this->idealDir.z * (float)v48)));
    __asm { fsel      f31, f7, f29, f13 }
    if ( v52 < v61 )
      v61 = v52;
    v64 = gravityDir->y;
    v65 = gravityDir->z;
    v69.vec.x = gravityDir->x;
    v69.axisValid = false;
    v69.origin.x = vec3_origin.x;
    v69.vec.y = v64;
    v69.origin.y = vec3_origin.y;
    v69.vec.z = v65;
    v69.origin.z = vec3_origin.z;
    v69.angle = (float)v61 * (float)_FP31;
    v69.axis.mat[0].x = mat3_identity.mat[0].x;
    v69.axis.mat[0].y = mat3_identity.mat[0].y;
    v69.axis.mat[0].z = mat3_identity.mat[0].z;
    v69.axis.mat[1].x = mat3_identity.mat[1].x;
    v69.axis.mat[1].y = mat3_identity.mat[1].y;
    v69.axis.mat[1].z = mat3_identity.mat[1].z;
    v69.axis.mat[2].x = mat3_identity.mat[2].x;
    v69.axis.mat[2].y = mat3_identity.mat[2].y;
    v69.axis.mat[2].z = mat3_identity.mat[2].z;
    v66 = idRotation::ToMat3(this: &v69);
    idMat3::operator*=(this: p_axis, a: v66);
    idMat3::FixDenormals(this: p_axis);
    v67 = 1;
    if ( _FP31 <= 0.0 )
      v67 = 2;
    this->currentTurnDir = v67;
  }
  else
  {
    if ( tolerance >= 0.99984771 )
      idAIOrientation::SetAxis(this, dir: &this->idealDir, gravityDir);
    this->currentTurnDir = 0;
    this->lastTurnRate = 0.0;
  }
}


// ========================================================================
// ?SetAxis@idAIOrientation@@QAAXPAVidAI2@@ABVidVec3@@@Z
// EA  : 0x82A5FB58
// RVA : 0x00A5FB58
// PDB : w:\tech5\tungsten\game\ai\aiorientation.cpp
// ========================================================================

void __fastcall idAIOrientation::SetAxis(idAIOrientation *this, idAI2 *ai, const idVec3 *dir)
{
  idPhysics *Physics; // r3
  const idVec3 *v6; // r3

  Physics = idEntity::GetPhysics(this: ai);
  v6 = Physics->GetGravityNormal(this: Physics);
  idAIOrientation::SetAxis(this, dir, gravityDir: v6);
}

