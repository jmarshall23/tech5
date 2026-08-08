
// ========================================================================
// ?ReachedPoint@idAIMoveState@@UBA_NABVidVec3@@M@Z
// EA  : 0x82A55018
// RVA : 0x00A55018
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

int __fastcall idAIMoveState::ReachedPoint(idAIMoveState *this, const idVec3 *point, double tolerance)
{
  idPhysics *Physics; // r3
  idAIMoveState_vtbl *v7; // r31
  int v8; // r3

  Physics = idEntity::GetPhysics(this: this->ai);
  v7 = this->__vftable;
  v8 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  return ((int (__fastcall *)(idAIMoveState *, const idVec3 *, int, double))v7->PointInMovementRange)(
           a1: this,
           a2: point,
           a3: v8,
           a4: tolerance);
}


// ========================================================================
// ?EndTurn@idAIMoveState@@QAAXXZ
// EA  : 0x82A55080
// RVA : 0x00A55080
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __fastcall idAIMoveState::EndTurn(idAIMoveState *this)
{
  this->turnFramesRemaining = 0;
  this->turnRateScale = 1.0;
}


// ========================================================================
// ?GetDestinationTraversal@idAIMoveState@@UBAPBUaas2Traversal_t@@XZ
// EA  : 0x82A55098
// RVA : 0x00A55098
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

const aas2Traversal_t *__fastcall idAIMoveState::GetDestinationTraversal(idAIMoveState *this)
{
  const idAAS2 *v3; // r3

  if ( this->lastPath.traversalIndex <= 0 )
    return nullptr;
  v3 = this->ai->GetAAS(this: this->ai);
  return v3->GetTraversal(this: (idAAS2 *)v3, a2: this->lastPath.traversalIndex);
}


// ========================================================================
// ?SetMoveStatus@idAIMoveState@@QAA?AW4aiMoveStatus_t@@W42@@Z
// EA  : 0x82A55110
// RVA : 0x00A55110
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

int __fastcall idAIMoveState::SetMoveStatus(idAIMoveState *this, int status)
{
  int GameMs; // [sp+50h] [-20h] BYREF

  this->moveStatus = status;
  if ( status >= 2 && status < 12 )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->MoveFailed(
      this,
      a2: this->moveParms.moveReason,
      a3: (const aiMoveStatus_t)status,
      a4: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)&GameMs);
  }
  return status;
}


// ========================================================================
// ?Init@idAIMoveState@@QAAXPAVidAI2@@@Z
// EA  : 0x82A55198
// RVA : 0x00A55198
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __fastcall idAIMoveState::Init(idAIMoveState *this, idAI2 *ai)
{
  this->ai = ai;
  this->lastUpdateMS = -1;
  idAIOrientation::SetAxis(this: &this->moveOrientation, axis: &ai->actorVolatile.modelInfo.modelAxis);
}


// ========================================================================
// ?Stop@idAIMoveState@@QAA?AW4aiMoveStatus_t@@W42@@Z
// EA  : 0x82A551B0
// RVA : 0x00A551B0
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

int __fastcall idAIMoveState::Stop(idAIMoveState *this, int newStatus)
{
  idPhysics *Physics; // r3
  idEventArg *AlertCycleFSM; // r3
  idPhysics *v6; // r3
  float *v7; // r3
  double v9; // fp0
  idEventReceiver v10[2]; // [sp+50h] [-30h] BYREF

  idAIMoveState::SetMoveStatus(this, status: newStatus);
  if ( newStatus == 11 )
  {
    this->ai->aiVolatile.debugging.errorFlags |= 8u;
    if ( idEntity::GetPhysics(this: this->ai)->type == PHYSICS_AI )
    {
      Physics = idEntity::GetPhysics(this: this->ai);
      if ( ((HIDWORD(Physics[12].residencyQuery.index) | (int)Physics[12].callbacks | (int)Physics[12].clip) & 0x7FFFFFFF) != 0 )
      {
        AlertCycleFSM = (idEventArg *)idAI2::GetAlertCycleFSM(this: this->ai);
        idEventReceiver::ProcessEvent(this: v10, result: AlertCycleFSM, ev: &FSM_Stuck);
      }
    }
  }
  v6 = idEntity::GetPhysics(this: this->ai);
  v7 = (float *)v6->GetOrigin(this: v6, a2: 0);
  v9 = *v7;
  this->finalPoint.x = *v7;
  this->finalPoint.y = v7[1];
  this->finalPoint.z = v7[2];
  this->nextPoint.x = v9;
  this->nextPoint.y = this->finalPoint.y;
  this->nextPoint.z = this->finalPoint.z;
  *((_BYTE *)this + 352) &= ~0x20u;
  return newStatus;
}


// ========================================================================
// ?PointReachableAreaNum@idAIMoveState@@ABAHABVidVec3@@M@Z
// EA  : 0x82A55388
// RVA : 0x00A55388
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

const idAAS2 *__fastcall idAIMoveState::PointReachableAreaNum(
        idAIMoveState *this,
        const idVec3 *point,
        double boundsScale)
{
  const idAAS2 *result; // r3
  const idAAS2 *v5; // r31
  idAAS2_vtbl *v6; // r26
  int v7; // r3
  char v8; // [sp+50h] [-50h] BYREF

  result = this->ai->GetAAS(this: this->ai);
  v5 = result;
  if ( result != nullptr )
  {
    v6 = result->__vftable;
    v7 = (int)result->DefaultSearchBounds(this: (idAAS2 *)&v8, (idBounds *)result);
    return (const idAAS2 *)v6->PointReachableAreaNum(
                             this: (idAAS2 *)v5,
                             a2: nullptr,
                             a3: point,
                             a4: (const idBounds *)v7,
                             a5: 2,
                             a6: 1);
  }
  return result;
}


// ========================================================================
// ?PointReachable@idAIMoveState@@QBA_NABVidVec3@@@Z
// EA  : 0x82A55420
// RVA : 0x00A55420
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

const idAAS2 *__fastcall idAIMoveState::PointReachable(idAIMoveState *this, const idVec3 *point)
{
  const idAAS2 *result; // r3
  const idAAS2 *v4; // r31
  idAAS2_vtbl *v5; // r26
  int v6; // r3
  char v7; // [sp+50h] [-50h] BYREF

  result = this->ai->GetAAS(this: this->ai);
  v4 = result;
  if ( result != nullptr )
  {
    v5 = result->__vftable;
    v6 = (int)result->DefaultSearchBounds(this: (idAAS2 *)&v7, (idBounds *)result);
    return (const idAAS2 *)(v5->PointReachableAreaNum(
                              this: (idAAS2 *)v4,
                              a2: nullptr,
                              a3: point,
                              a4: (const idBounds *)v6,
                              a5: 2,
                              a6: 1) != 0);
  }
  return result;
}


// ========================================================================
// ?PointInMovementRange@idAIMoveState@@UBA_NABVidVec3@@0MAAM@Z
// EA  : 0x82A554B0
// RVA : 0x00A554B0
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

BOOL __fastcall idAIMoveState::PointInMovementRange(
        idAIMoveState *this,
        const idVec3 *dest,
        const idVec3 *curPos,
        double range,
        float *dist,
        float *a6)
{
  idAI2 *ai; // r3
  double v8; // fp30
  double v10; // fp29
  double v12; // fp28
  idPhysics *Physics; // r3
  const idVec3 *v14; // r31
  double v15; // fp30
  idPhysics *v16; // r3
  int v17; // r3
  double v19; // fp9
  idVec3 v20; // [sp+50h] [-50h] BYREF

  ai = this->ai;
  v8 = (float)(dest->x - curPos->x);
  v10 = (float)(dest->y - curPos->y);
  v12 = (float)(dest->z - curPos->z);
  v20.x = dest->x - curPos->x;
  v20.y = v10;
  v20.z = v12;
  Physics = idEntity::GetPhysics(this: ai);
  v14 = Physics->GetGravityNormal(this: Physics);
  v15 = (float)((float)(v14->x * (float)v8) + (float)((float)(v14->z * (float)v12) + (float)(v14->y * (float)v10)));
  v16 = idEntity::GetPhysics(this: this->ai);
  v17 = (int)v16->GetBounds(this: v16, a2: -1);
  if ( __fabs(v15) > (float)(*(float *)(v17 + 20) - *(float *)(v17 + 8)) )
    return false;
  idVec3::ProjectOntoPlane(this: &v20, normal: v14, overBounce: 1.0);
  v19 = __fsqrts((float)((float)(v20.y * v20.y) + (float)((float)(v20.x * v20.x) + (float)(v20.z * v20.z))));
  *a6 = v19;
  return v19 <= range;
}


// ========================================================================
// ?WillReachPoint@idAIMoveState@@UBA_NABVidVec3@@M_N@Z
// EA  : 0x82A555D8
// RVA : 0x00A555D8
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

int __fastcall idAIMoveState::WillReachPoint(
        idAIMoveState *this,
        const idVec3 *point,
        double timeSeconds,
        bool isFinalPoint,
        char a5)
{
  idPhysics *Physics; // r3
  int v10; // r29
  idPhysics *v11; // r3
  double goalTolerance; // fp1
  double v13; // fp0
  double v14; // fp13
  float v16; // [sp+58h] [-48h] BYREF
  float v17; // [sp+5Ch] [-44h]
  float v18; // [sp+60h] [-40h]

  Physics = idEntity::GetPhysics(this: this->ai);
  v10 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v11 = idEntity::GetPhysics(this: this->ai);
  v11->GetLinearVelocity(this: (idPhysics *)&v16, result: (idVec3 *)v11, a3: 0);
  if ( a5 != 0 )
    goalTolerance = this->moveParms.goalTolerance;
  else
    goalTolerance = this->moveParms.intermediateTolerance;
  v13 = __fsqrts((float)((float)(v16 * v16) + (float)((float)(v17 * v17) + (float)(v18 * v18))));
  if ( v13 >= 0.000099999997 )
  {
    v14 = (float)((float)(this->moveOrientation.axis.mat[0].x * this->moveOrientation.idealDir.x)
                + (float)((float)(this->moveOrientation.axis.mat[0].z * this->moveOrientation.idealDir.z)
                        + (float)(this->moveOrientation.axis.mat[0].y * this->moveOrientation.idealDir.y)));
    if ( v14 < 0.99989998 && v14 > -0.99989998 )
      return 0;
    goalTolerance = (float)((float)((float)v13 * (float)timeSeconds) + (float)goalTolerance);
  }
  return ((int (__fastcall *)(idAIMoveState *, const idVec3 *, int, double))this->PointInMovementRange)(
           a1: this,
           a2: point,
           a3: v10,
           a4: goalTolerance);
}


// ========================================================================
// ?GetReachedEntityDist@idAIMoveState@@UBAMPBVidEntity@@M@Z
// EA  : 0x82A55708
// RVA : 0x00A55708
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

float __fastcall idAIMoveState::GetReachedEntityDist(idAIMoveState *this, idEntity *ent, double tolerance)
{
  idPhysics *Physics; // r3
  int v6; // r3
  char *v7; // r10
  _DWORD *v8; // r11
  int i; // ctr
  double Radius; // fp30
  idPhysics *v11; // r3
  int v12; // r3
  char *v13; // r10
  _DWORD *v14; // r11
  int j; // ctr
  double v16; // fp1
  char v18; // [sp+4Ch] [-64h] BYREF
  idBounds v19; // [sp+50h] [-60h] BYREF
  char v20; // [sp+6Ch] [-44h] BYREF
  idBounds v21; // [sp+70h] [-40h] BYREF

  Physics = idEntity::GetPhysics(this: this->ai);
  v6 = (int)Physics->GetBounds(this: Physics, a2: -1);
  v7 = &v18;
  v8 = (_DWORD *)(v6 - 4);
  for ( i = 6; i != 0; --i )
  {
    ++v8;
    v7 += 4;
    *(_DWORD *)v7 = *v8;
  }
  v19.b[0].z = 0.0;
  v19.b[1].z = 0.0;
  Radius = idBounds::GetRadius(this: &v19);
  v11 = idEntity::GetPhysics(this: ent);
  v12 = (int)v11->GetBounds(this: v11, a2: -1);
  v13 = &v20;
  v14 = (_DWORD *)(v12 - 4);
  for ( j = 6; j != 0; --j )
  {
    ++v14;
    v13 += 4;
    *(_DWORD *)v13 = *v14;
  }
  v21.b[0].z = 0.0;
  v21.b[1].z = 0.0;
  v16 = (float)((float)(idBounds::GetRadius(this: &v21) + (float)Radius) + (float)tolerance);
  return *((float *)&v16 + 1);
}


// ========================================================================
// ?ReachedEntity@idAIMoveState@@UBA_NPBVidEntity@@M@Z
// EA  : 0x82A557F0
// RVA : 0x00A557F0
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

int __fastcall idAIMoveState::ReachedEntity(idAIMoveState *this, idScenePoint *ent, double tolerance)
{
  idPhysics *Physics; // r3
  float *v7; // r29
  idPhysics *v8; // r3
  float *v9; // r3
  double v10; // fp8
  double v11; // fp6
  double v12; // fp3
  double v14; // fp1
  double v16; // fp12
  double v17; // fp8
  double v18; // fp31
  idScenePoint *v19; // r3
  unsigned __int8 v20; // r11
  double v23; // fp1

  Physics = idEntity::GetPhysics(this: this->ai);
  v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v8 = idEntity::GetPhysics(this: ent);
  v9 = (float *)v8->GetOrigin(this: v8, a2: 0);
  v10 = (float)(v7[2] - v9[2]);
  v11 = (float)(v7[1] - v9[1]);
  v12 = (float)((float)((float)v11 * (float)v11)
              + (float)((float)((float)v10 * (float)v10) + (float)((float)(*v7 - *v9) * (float)(*v7 - *v9))));
  _FP2 = (float)((float)((float)((float)v11 * (float)v11)
                       + (float)((float)((float)v10 * (float)v10) + (float)((float)(*v7 - *v9) * (float)(*v7 - *v9))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v14 = (float)((float)((float)((float)v11 * (float)v11)
                      + (float)((float)((float)v10 * (float)v10) + (float)((float)(*v7 - *v9) * (float)(*v7 - *v9))))
              * (float)0.5);
  __asm { fsel      f13, f2, f3, f13 }
  v16 = __frsqrte(_FP13);
  v17 = (float)((float)-(float)((float)((float)((float)v16
                                              * (float)((float)((float)((float)v11 * (float)v11)
                                                              + (float)((float)((float)v10 * (float)v10)
                                                                      + (float)((float)(*v7 - *v9) * (float)(*v7 - *v9))))
                                                      * (float)0.5))
                                      * (float)v16)
                              - (float)1.5)
              * (float)v16);
  v18 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)v14)
                                                                                      * (float)v17)
                                                                              - (float)1.5)
                                                              * (float)v17)
                                                      * (float)v14)
                                              * (float)((float)-(float)((float)((float)((float)v17 * (float)v14)
                                                                              * (float)v17)
                                                                      - (float)1.5)
                                                      * (float)v17))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v17 * (float)v14) * (float)v17) - (float)1.5)
                              * (float)v17))
              * (float)v12);
  v19 = idScenePoint::CastTo(c: ent);
  if ( v19 != nullptr )
  {
    v20 = 1;
    _FP12 = (float)(v19->radius - (float)8.0);
    __asm { fsel      f11, f12, f13, f0 }
    if ( v18 > _FP11 )
      return 0;
  }
  else
  {
    v23 = ((double (__fastcall *)(idAIMoveState *, idScenePoint *, double))this->GetReachedEntityDist)(
            a1: this,
            a2: ent,
            a3: tolerance);
    v20 = 1;
    if ( v18 >= v23 )
      return 0;
  }
  return v20;
}


// ========================================================================
// ?WillReachEntity@idAIMoveState@@UBA_NPBVidEntity@@MM@Z
// EA  : 0x82A55948
// RVA : 0x00A55948
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

BOOL __fastcall idAIMoveState::WillReachEntity(
        idAIMoveState *this,
        idEntity *ent,
        double timeSeconds,
        double tolerance)
{
  idPhysics *Physics; // r3
  float *v9; // r29
  idPhysics *v10; // r3
  float *v11; // r3
  double v12; // fp29
  double v13; // fp28
  double v14; // fp27
  idPhysics *v15; // r3
  float v17; // [sp+50h] [-60h] BYREF
  float v18; // [sp+54h] [-5Ch]
  float v19; // [sp+58h] [-58h]

  Physics = idEntity::GetPhysics(this: this->ai);
  v9 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v10 = idEntity::GetPhysics(this: ent);
  v11 = (float *)v10->GetOrigin(this: v10, a2: 0);
  v12 = (float)(*v9 - *v11);
  v13 = (float)(v9[1] - v11[1]);
  v14 = (float)(v9[2] - v11[2]);
  v15 = idEntity::GetPhysics(this: this->ai);
  v15->GetLinearVelocity(this: (idPhysics *)&v17, result: (idVec3 *)v15, a3: 0);
  return (float)-(float)((float)((float)__fsqrts((float)((float)(v17 * v17)
                                                       + (float)((float)(v18 * v18) + (float)(v19 * v19))))
                               * (float)timeSeconds)
                       - (float)__fsqrts((float)((float)((float)v13 * (float)v13)
                                               + (float)((float)((float)v14 * (float)v14)
                                                       + (float)((float)v12 * (float)v12))))) < ((double (__fastcall *)(idAIMoveState *, idEntity *, double))this->GetReachedEntityDist)(
                                                                                                  a1: this,
                                                                                                  a2: ent,
                                                                                                  a3: tolerance);
}


// ========================================================================
// ?SetMovementModeForReal@idAIMoveState@@QAAXW4aiMovementMode_t@@@Z
// EA  : 0x82A55A68
// RVA : 0x00A55A68
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __fastcall idAIMoveState::SetMovementModeForReal(idAIMoveState *this, aiMovementMode_t mode)
{
  idAI2 *ai; // r31
  idPresentable *presentable; // r11

  ai = this->ai;
  this->movementMode = mode;
  presentable = ai->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: ai);
    presentable = ai->presentable;
  }
  presentable->model->useDeferredPosition = -11 - ((this->movementMode == AIMOVEMODE_PERFECTORIGIN) - 12);
}


// ========================================================================
// ?BeginTurn@idAIMoveState@@QAAXABVidQuat@@ABV?$idTypesafeNumber@HW4gameTimeUnique_t@@@@@Z
// EA  : 0x82A55AD0
// RVA : 0x00A55AD0
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __fastcall idAIMoveState::BeginTurn(
        idAIMoveState *this,
        idAngles *rotDelta,
        const idTypesafeNumber<int,enum gameTimeUnique_t> *totalTurnTime)
{
  idAIOrientation *BodyOrientation; // r28
  idAIOrientation *v7; // r3
  double v8; // fp31
  long double v9; // fp2
  double v10; // fp1
  double y; // fp13
  double v12; // fp0
  double v13; // fp0
  signed int v14; // r3
  int v15; // r11
  idGameLocal *v16; // r3
  int (__fastcall *GetGameMsPerFrame)(struct idGameLocal *, const gameTimeType_t); // r11
  unsigned int v18; // r10
  signed int v19; // r3
  int value; // r9
  int v21; // r7
  unsigned int v22; // r4
  int turnFramesRemaining; // r11
  idQuat v24; // [sp+50h] [-40h] BYREF

  BodyOrientation = idAI2::GetBodyOrientation(this: this->ai);
  v7 = idAI2::GetBodyOrientation(this: this->ai);
  v8 = (float)((float)(BodyOrientation->axis.mat[0].x * v7->idealDir.x)
             + (float)((float)(BodyOrientation->axis.mat[0].z * v7->idealDir.z)
                     + (float)(BodyOrientation->axis.mat[0].y * v7->idealDir.y)));
  idQuat::ToAngles(this: &v24, result: rotDelta);
  *(double *)&v9 = v8;
  v10 = idMath::ACos(a: v9);
  y = v24.y;
  v12 = (float)((float)v10 * idMath::M_RAD2DEG);
  this->actualTurnAngle = (float)v10 * idMath::M_RAD2DEG;
  if ( y == 0.0 )
    v13 = 1.0;
  else
    v13 = __fabs((float)((float)v12 / (float)y));
  this->turnRateScale = v13;
  v14 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
  v15 = __ROL4__(totalTurnTime->value, 1);
  this->turnFramesRemaining = totalTurnTime->value / v14;
  __twllei(v14, 0);
  v18 = v14 & ~(v15 - 1);
  v16 = gameLocal;
  GetGameMsPerFrame = gameLocal->GetGameMsPerFrame;
  __twlgei(v18, 0xFFFFFFFF);
  v19 = GetGameMsPerFrame(this: v16, a2: GAMETIME_SCALED);
  value = totalTurnTime->value;
  v21 = totalTurnTime->value / v19 * v19;
  v22 = v19 & ~(__ROL4__(totalTurnTime->value, 1) - 1);
  __twllei(v19, 0);
  __twlgei(v22, 0xFFFFFFFF);
  if ( value != v21 )
    ++this->turnFramesRemaining;
  turnFramesRemaining = this->turnFramesRemaining;
  this->accumulatedTurnAngle = 0.0;
  this->totalTurnFrames = turnFramesRemaining;
}


// ========================================================================
// ?BeginTurn@idAIMoveState@@QAAXABVidVec3@@ABVidQuat@@ABV?$idTypesafeNumber@HW4gameTimeUnique_t@@@@@Z
// EA  : 0x82A55C20
// RVA : 0x00A55C20
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __fastcall idAIMoveState::BeginTurn(
        idAIMoveState *this,
        const idVec3 *idealDir,
        idAngles *rotDelta,
        const idTypesafeNumber<int,enum gameTimeUnique_t> *totalTurnTime)
{
  idAI2 *ai; // r27
  idAIOrientation *BodyOrientation; // r3

  ai = this->ai;
  BodyOrientation = idAI2::GetBodyOrientation(this: ai);
  idAIOrientation::SetIdealDir(this: BodyOrientation, ai, dir: idealDir);
  idAIMoveState::BeginTurn(this, rotDelta, totalTurnTime);
}


// ========================================================================
// ?GetMovementDelta@idAIMoveState@@ABAXABVidMat3@@0AAVidVec3@@1@Z
// EA  : 0x82A55C70
// RVA : 0x00A55C70
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __fastcall idAIMoveState::GetMovementDelta(
        idAIMoveState *this,
        const idMat3 *oldAxis,
        const idMat3 *curAxis,
        idVec3 *localDelta,
        idVec3 *worldDelta)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idAI2 *ai; // r28
  idTreeAnimator *v11; // r27
  idPresentable *presentable; // r11
  double z; // fp0
  double y; // fp1
  double v15; // fp10
  double v16; // fp9
  double v17; // fp12
  int LastOriginDeltaTime; // r30
  int valueInteger; // r31
  idPhysics *Physics; // r29
  idRenderWorld *v21; // r3
  __int64 v22; // r8
  __int64 v23; // r6
  idRenderWorld *v24; // r28
  __int64 v25; // r10
  va *v26; // r30
  idRenderWorld_vtbl *v27; // r27
  int v28; // r3
  int v29; // r6
  int v30; // [sp+8h] [-10D8h]
  int v31; // [sp+Ch] [-10D4h]
  int v32; // [sp+10h] [-10D0h]
  int v33; // [sp+14h] [-10CCh]
  int v34; // [sp+18h] [-10C8h]
  int v35; // [sp+1Ch] [-10C4h]
  float v36[4]; // [sp+60h] [-1080h] BYREF
  idMat3 v37; // [sp+70h] [-1070h] BYREF
  va v38; // [sp+A0h] [-1040h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->ai);
  ai = this->ai;
  v11 = TreeAnimatorFromPresentable;
  presentable = ai->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: this->ai);
    presentable = ai->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v11 != nullptr )
  {
    idTreeAnimator::GetLastOriginDeltas(this: v11, rot: &v37, trans: localDelta);
    z = localDelta->z;
    y = curAxis->mat[2].y;
    v15 = (float)((float)(curAxis->mat[0].y * localDelta->x) + (float)(curAxis->mat[1].y * localDelta->y));
    v16 = (float)((float)(curAxis->mat[0].z * localDelta->x) + (float)(curAxis->mat[1].z * localDelta->y));
    v17 = curAxis->mat[2].z;
    worldDelta->x = (float)(curAxis->mat[0].x * localDelta->x)
                  + (float)((float)(curAxis->mat[1].x * localDelta->y) + (float)(curAxis->mat[2].x * localDelta->z));
    worldDelta->y = (float)((float)y * (float)z) + (float)v15;
    worldDelta->z = (float)((float)v17 * (float)z) + (float)v16;
    if ( ai_debugDeltas.valueInteger > 0 && ai_debugLevel.valueInteger > 0 )
    {
      LastOriginDeltaTime = idTreeAnimator::GetLastOriginDeltaTime(this: v11);
      valueInteger = ai_debugDeltas.valueInteger;
      Physics = idEntity::GetPhysics(this: this->ai);
      v21 = gameLocal->GetRenderWorld(this: gameLocal);
      LODWORD(v22) = 0x82000000;
      HIDWORD(v22) = 0x82000000;
      LODWORD(v23) = 0x82000000;
      v24 = v21;
      HIDWORD(v23) = LastOriginDeltaTime;
      v36[0] = 0.5;
      v36[1] = 0.5;
      v36[2] = 0.5;
      v36[3] = 1.0;
      v26 = va::va(
              this: &v38,
              fmt: "%d",
              a3: v23,
              a4: v22,
              a5: v25,
              a6: v30,
              a7: v31,
              a8: v32,
              a9: v33,
              a10: v34,
              a11: v35);
      v27 = v24->__vftable;
      v28 = (int)Physics->GetOrigin(this: Physics, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, va *, int, int, float *, int, int, int, double))v27->DebugText)(
        a1: v24,
        a2: v26,
        a3: v28,
        a4: v29,
        a5: v36,
        a6: 1,
        a7: 1000 * valueInteger - 1000,
        a8: 1,
        a9: 0.025);
    }
  }
}


// ========================================================================
// ?GetMovementDeltaSpeed@idAIMoveState@@ABAMABVidMat3@@0@Z
// EA  : 0x82A55E30
// RVA : 0x00A55E30
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

float __fastcall idAIMoveState::GetMovementDeltaSpeed(
        idAIMoveState *this,
        const idMat3 *oldAxis,
        const idMat3 *curAxis)
{
  double v3; // fp1
  idVec3 v5; // [sp+50h] [-30h] BYREF
  idVec3 v6; // [sp+60h] [-20h] BYREF

  idAIMoveState::GetMovementDelta(this, oldAxis, curAxis, localDelta: &v6, worldDelta: &v5);
  *(_QWORD *)&v5.x = __PAIR64__(
                       &unk_82390000,
                       idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED));
  v3 = (float)((float)__fsqrts((float)((float)(v6.z * v6.z) + (float)((float)(v6.y * v6.y) + (float)(v6.x * v6.x))))
             / (float)((float)*(__int64 *)&v5.x * (float)0.001));
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?ResetStuck@idAIMoveState@@QAAXXZ
// EA  : 0x82A55EB0
// RVA : 0x00A55EB0
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __fastcall idAIMoveState::ResetStuck(idAIMoveState *this)
{
  idPhysics *Physics; // r3
  idAI2 *ai; // r7

  Physics = idEntity::GetPhysics(this: this->ai);
  this->stuckRefPoint = *Physics->GetOrigin(this: Physics, a2: 0);
  ai = this->ai;
  ai->patch1.unclippedOffset.z = 0.0;
  ai->patch1.unclippedOffset.y = 0.0;
  ai->patch1.unclippedOffset.x = 0.0;
  this->accumulatedDeltaLen = 0.0;
  this->stuckTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->numZeroVelocityFrames = 0;
}


// ========================================================================
// ?UpdateStuck@idAIMoveState@@AAAXXZ
// EA  : 0x82A55F58
// RVA : 0x00A55F58
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __fastcall idAIMoveState::UpdateStuck(idAIMoveState *this)
{
  idPhysics *Physics; // r3
  float *v3; // r30
  idPhysics *v4; // r3
  double v5; // fp3
  double v6; // fp1
  __int64 v7; // r10
  double v8; // fp10
  double v9; // fp4
  double v10; // fp3
  float v11; // [sp+58h] [-28h] BYREF
  float v12; // [sp+5Ch] [-24h]
  float v13; // [sp+60h] [-20h]

  Physics = idEntity::GetPhysics(this: this->ai);
  v3 = (float *)Physics->GetGravityNormal(this: Physics);
  v4 = idEntity::GetPhysics(this: this->ai);
  v4->GetLinearVelocity(this: (idPhysics *)&v11, result: (idVec3 *)v4, a3: 0);
  v5 = (float)(v3[2] * (float)((float)(v3[1] * v12) + (float)((float)(v3[2] * v13) + (float)(*v3 * v11))));
  v6 = (float)(v12 - (float)(v3[1] * (float)((float)(v3[1] * v12) + (float)((float)(v3[2] * v13) + (float)(*v3 * v11)))));
  v11 = v11 - (float)(*v3 * (float)((float)(v3[1] * v12) + (float)((float)(v3[2] * v13) + (float)(*v3 * v11))));
  v12 = v6;
  v13 = v13 - (float)v5;
  LODWORD(v7) = gameLocal->GetGameHz(this: gameLocal, a2: GAMETIME_SCALED);
  v8 = (float)v7;
  HIDWORD(v7) = this->ai;
  v11 = v11 * (float)((float)1.0 / (float)v8);
  v12 = v12 * (float)((float)1.0 / (float)v8);
  v13 = v13 * (float)((float)1.0 / (float)v8);
  v9 = *(float *)(HIDWORD(v7) + 61768);
  v10 = *(float *)(HIDWORD(v7) + 61772);
  *(float *)(HIDWORD(v7) + 61764) = *(float *)(HIDWORD(v7) + 61764) + v11;
  *(float *)(HIDWORD(v7) + 61768) = (float)v9 + v12;
  *(float *)(HIDWORD(v7) + 61772) = (float)v10 + v13;
  this->accumulatedDeltaLen = (float)__fsqrts((float)((float)(v11 * v11)
                                                    + (float)((float)(v13 * v13) + (float)(v12 * v12))))
                            + this->accumulatedDeltaLen;
}


// ========================================================================
// ?CheckStuck@idAIMoveState@@AAA_NXZ
// EA  : 0x82A560D8
// RVA : 0x00A560D8
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

int __fastcall idAIMoveState::CheckStuck(idAIMoveState *this)
{
  idPhysics *Physics; // r3
  int v3; // r3
  idPhysics *v5; // r3
  int v6; // r3
  idPhysics *v7; // r3
  float *v8; // r29
  idPhysics *v9; // r3
  float *v10; // r3
  idAI2 *ai; // r11
  double v12; // fp3
  double v13; // fp2
  double v14; // fp1
  idPhysics *v15; // r3
  int v16; // r3
  idPhysics *v17; // r3
  int v18; // r3
  idPhysics *v19; // r3
  int v20; // r3

  if ( ai_checkStuck.valueInteger == 0 )
  {
    idAIMoveState::ResetStuck(this);
    if ( ai_debugStuck.valueInteger != 0 )
    {
      Physics = idEntity::GetPhysics(this: this->ai);
      v3 = (int)Physics->GetOrigin(this: Physics, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, const char *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: "disabled",
        a3: v3,
        a4: clientGame->renderWorld->DebugText,
        a5: &idColor::colorRed,
        a6: 1,
        a7: 250,
        a8: 0,
        a9: 0.2);
      return 0;
    }
    return 0;
  }
  if ( this->moveStatus != AIMOVESTATUS_MOVING || this->IsPlayingTraversalAnim(this) )
  {
    idAIMoveState::ResetStuck(this);
    if ( ai_debugStuck.valueInteger != 0 )
    {
      v19 = idEntity::GetPhysics(this: this->ai);
      v20 = (int)v19->GetOrigin(this: v19, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, const char *, int, idRenderWorld_vtbl *, idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: "traversal or stopped",
        a3: v20,
        a4: clientGame->renderWorld->__vftable,
        a5: &idColor::colorGreen,
        a6: 1,
        a7: 250,
        a8: 0,
        a9: 0.2);
    }
    return 0;
  }
  if ( this->numZeroVelocityFrames > ai_zeroVelocityFramesBeforeStuck.valueInteger )
  {
    if ( ai_debugStuck.valueInteger != 0 )
    {
      v5 = idEntity::GetPhysics(this: this->ai);
      v6 = (int)v5->GetOrigin(this: v5, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, const char *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: "zero vel",
        a3: v6,
        a4: clientGame->renderWorld->DebugText,
        a5: &idColor::colorLtGrey,
        a6: 1,
        a7: 250,
        a8: 0,
        a9: 0.2);
    }
    return 1;
  }
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - this->stuckTime < 500 )
    return 0;
  v7 = idEntity::GetPhysics(this: this->ai);
  v8 = (float *)v7->GetGravityNormal(this: v7);
  v9 = idEntity::GetPhysics(this: this->ai);
  v10 = (float *)v9->GetOrigin(this: v9, a2: 0);
  ai = this->ai;
  v12 = (float)(ai->patch1.unclippedOffset.y
              - (float)((float)(v10[1] - this->stuckRefPoint.y)
                      - (float)(v8[1]
                              * (float)((float)(*v8 * (float)(*v10 - this->stuckRefPoint.x))
                                      + (float)((float)(v8[1] * (float)(v10[1] - this->stuckRefPoint.y))
                                              + (float)(v8[2] * (float)(v10[2] - this->stuckRefPoint.z)))))));
  v13 = (float)(ai->patch1.unclippedOffset.z
              - (float)((float)(v10[2] - this->stuckRefPoint.z)
                      - (float)(v8[2]
                              * (float)((float)(*v8 * (float)(*v10 - this->stuckRefPoint.x))
                                      + (float)((float)(v8[1] * (float)(v10[1] - this->stuckRefPoint.y))
                                              + (float)(v8[2] * (float)(v10[2] - this->stuckRefPoint.z)))))));
  v14 = (float)(ai->patch1.unclippedOffset.x
              - (float)((float)(*v10 - this->stuckRefPoint.x)
                      - (float)(*v8
                              * (float)((float)(*v8 * (float)(*v10 - this->stuckRefPoint.x))
                                      + (float)((float)(v8[1] * (float)(v10[1] - this->stuckRefPoint.y))
                                              + (float)(v8[2] * (float)(v10[2] - this->stuckRefPoint.z)))))));
  if ( __fsqrts((float)((float)((float)v14 * (float)v14)
                      + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12)))) <= (float)(gameLocal->aiStuckDistanceFraction * this->accumulatedDeltaLen) )
  {
    idAIMoveState::ResetStuck(this);
    if ( ai_debugStuck.valueInteger != 0 )
    {
      v17 = idEntity::GetPhysics(this: this->ai);
      v18 = (int)v17->GetOrigin(this: v17, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, const char *, int, idRenderWorld_vtbl *, idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: "delta",
        a3: v18,
        a4: clientGame->renderWorld->__vftable,
        a5: &idColor::colorOrange,
        a6: 1,
        a7: 250,
        a8: 0,
        a9: 0.2);
      return 0;
    }
    return 0;
  }
  idLib::Warning(fmt: "idAIMoveState::CheckStuck - ai %s was stuck", ai->name.data);
  if ( ai_debugStuck.valueInteger != 0 )
  {
    v15 = idEntity::GetPhysics(this: this->ai);
    v16 = (int)v15->GetOrigin(this: v15, a2: 0);
    ((void (__fastcall *)(idRenderWorld *, const char *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
      a1: clientGame->renderWorld,
      a2: "stuck",
      a3: v16,
      a4: clientGame->renderWorld->DebugText,
      a5: &idColor::colorRed,
      a6: 1,
      a7: 250,
      a8: 0,
      a9: 0.2);
  }
  idAIMoveState::ResetStuck(this);
  return 1;
}


// ========================================================================
// ?StartLerp@idAIMoveState@@QAAXABVidVec3@@HH@Z
// EA  : 0x82A56520
// RVA : 0x00A56520
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __fastcall idAIMoveState::StartLerp(
        idAIMoveState *this,
        const idVec3 *dest,
        const int lerpDurationMS,
        int lerpAxisFlags_)
{
  this->lerpAxisFlags = lerpAxisFlags_;
  this->endLerpTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + lerpDurationMS;
  this->lerpDest = *dest;
  this->lerpDelta.x = 0.0;
  this->lerpDelta.y = 0.0;
  this->lerpDelta.z = 0.0;
}


// ========================================================================
// ?StartLerpToPoint@idAIMoveState@@QAA_NABVidVec3@@MMHH@Z
// EA  : 0x82A56598
// RVA : 0x00A56598
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

int __fastcall idAIMoveState::StartLerpToPoint(
        idAIMoveState *this,
        const idVec3 *dest,
        double tolerance,
        double maxLerpDist,
        const int lerpDurationMS,
        const int lerpAxisFlags_,
        int a7,
        int a8)
{
  idAI2 *ai; // r3
  idPhysics *Physics; // r3
  idAIMoveState_vtbl *v16; // r27
  int v17; // r3
  float v19; // [sp+50h] [-50h]

  ai = this->ai;
  v19 = 0.0;
  Physics = idEntity::GetPhysics(this: ai);
  v16 = this->__vftable;
  v17 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  if ( ((unsigned __int8 (__fastcall *)(idAIMoveState *, const idVec3 *, int, double))v16->PointInMovementRange)(
         a1: this,
         a2: dest,
         a3: v17,
         a4: maxLerpDist) == 0 )
    return 0;
  if ( v19 > tolerance )
    idAIMoveState::StartLerp(this, dest, lerpDurationMS: a7, lerpAxisFlags_: a8);
  return 1;
}


// ========================================================================
// ?AlignToNextPoint@idAIMoveState@@QAA_NXZ
// EA  : 0x82A56668
// RVA : 0x00A56668
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

int __fastcall idAIMoveState::AlignToNextPoint(idAIMoveState *this)
{
  aiMoveStatus_t moveStatus; // r10
  idPhysics *Physics; // r28
  double v6; // fp1
  double v7; // fp1
  double v8; // fp7
  double v9; // fp28
  double v10; // fp5
  double x; // fp0
  double y; // fp13
  double z; // fp12
  double w; // fp11
  double v15; // fp31
  double v16; // fp30
  double v17; // fp29
  double v18; // fp0
  double v19; // fp12
  double v20; // fp9
  float *v21; // r3
  double v22; // fp10
  double v23; // fp8
  double valueFloat; // fp0
  double v25; // fp31
  double v26; // fp31
  __int64 v27; // r6
  idAI2 *v28; // r30
  idAIOrientation *v29; // r3
  const idMat3 *v30; // r30
  idAIOrientation *v31; // r3
  idAIOrientation *BodyOrientation; // r27
  idAIOrientation *v34; // r3
  double v35; // fp1
  idAI2 *ai; // r27
  double v37; // fp31
  idAIOrientation *v38; // r3
  __int64 v39; // r7
  double v40; // fp30
  const idVec3 *v41; // r30
  idAIOrientation *v42; // r3
  float v43; // [sp+58h] [-B8h] BYREF
  float v44; // [sp+5Ch] [-B4h]
  float v45; // [sp+60h] [-B0h]
  idQuat v46; // [sp+68h] [-A8h] BYREF
  idMat3 v47[2]; // [sp+80h] [-90h] BYREF

  moveStatus = this->moveStatus;
  *((_BYTE *)this + 352) &= ~0x20u;
  if ( moveStatus == AIMOVESTATUS_OBSTRUCTED )
    return 0;
  Physics = idEntity::GetPhysics(this: this->ai);
  Physics->GetLinearVelocity(this: (idPhysics *)&v43, result: (idVec3 *)Physics, a3: 0);
  _FP4 = (float)((float)((float)(v43 * v43) + (float)((float)(v45 * v45) + (float)(v44 * v44)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f4, f5, f12 }
  v6 = __frsqrte(_FP2);
  v7 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6
                                                                                     * (float)((float)((float)(v43 * v43) + (float)((float)(v45 * v45) + (float)(v44 * v44)))
                                                                                             * (float)0.5))
                                                                             * (float)v6)
                                                                     - (float)1.5)
                                                     * (float)v6)
                                             * (float)((float)((float)(v43 * v43)
                                                             + (float)((float)(v45 * v45) + (float)(v44 * v44)))
                                                     * (float)0.5))
                                     * (float)((float)-(float)((float)((float)((float)v6
                                                                             * (float)((float)((float)(v43 * v43)
                                                                                             + (float)((float)(v45 * v45) + (float)(v44 * v44)))
                                                                                     * (float)0.5))
                                                                     * (float)v6)
                                                             - (float)1.5)
                                             * (float)v6))
                             - (float)1.5)
             * (float)((float)-(float)((float)((float)((float)v6
                                                     * (float)((float)((float)(v43 * v43)
                                                                     + (float)((float)(v45 * v45) + (float)(v44 * v44)))
                                                             * (float)0.5))
                                             * (float)v6)
                                     - (float)1.5)
                     * (float)v6));
  v8 = (float)((float)-(float)((float)((float)((float)v7
                                             * (float)((float)((float)(v43 * v43)
                                                             + (float)((float)(v45 * v45) + (float)(v44 * v44)))
                                                     * (float)0.5))
                                     * (float)v7)
                             - (float)1.5)
             * (float)v7);
  v9 = (float)((float)((float)-(float)((float)((float)((float)v7
                                                     * (float)((float)((float)(v43 * v43)
                                                                     + (float)((float)(v45 * v45) + (float)(v44 * v44)))
                                                             * (float)0.5))
                                             * (float)v7)
                                     - (float)1.5)
                     * (float)v7)
             * (float)((float)(v43 * v43) + (float)((float)(v45 * v45) + (float)(v44 * v44))));
  v10 = (float)(v44
              * (float)((float)-(float)((float)((float)((float)v7
                                                      * (float)((float)((float)(v43 * v43)
                                                                      + (float)((float)(v45 * v45) + (float)(v44 * v44)))
                                                              * (float)0.5))
                                              * (float)v7)
                                      - (float)1.5)
                      * (float)v7));
  v43 = v43
      * (float)((float)-(float)((float)((float)((float)v7
                                              * (float)((float)((float)(v43 * v43)
                                                              + (float)((float)(v45 * v45) + (float)(v44 * v44)))
                                                      * (float)0.5))
                                      * (float)v7)
                              - (float)1.5)
              * (float)v7);
  v44 = v10;
  v45 = v45 * (float)v8;
  if ( v9 < 0.000099999997 )
    return 0;
  if ( (*((_BYTE *)this + 352) & 0x80) == 0 )
  {
    if ( (this->moveParms.flags & 1) != 0 )
    {
      x = this->moveParms.goalOrientation.x;
      y = this->moveParms.goalOrientation.y;
      z = this->moveParms.goalOrientation.z;
      w = this->moveParms.goalOrientation.w;
      v15 = this->finalPoint.x;
      v16 = this->finalPoint.y;
      v17 = this->finalPoint.z;
      goto LABEL_7;
    }
    return 0;
  }
  x = this->traversalOrientation.x;
  y = this->traversalOrientation.y;
  z = this->traversalOrientation.z;
  w = this->traversalOrientation.w;
  v15 = this->traversalStartPoint.x;
  v16 = this->traversalStartPoint.y;
  v17 = this->traversalStartPoint.z;
LABEL_7:
  v47[0].mat[0].x = x;
  v18 = this->nextPoint.y;
  v47[0].mat[0].y = y;
  v47[0].mat[0].z = z;
  v19 = this->nextPoint.z;
  v47[0].mat[1].x = w;
  v20 = (float)(this->nextPoint.x - (float)v15);
  if ( (float)((float)((float)v20 * (float)v20)
             + (float)((float)((float)((float)v19 - (float)v17) * (float)((float)v19 - (float)v17))
                     + (float)((float)((float)v18 - (float)v16) * (float)((float)v18 - (float)v16)))) > (double)(float)(this->moveParms.goalTolerance * this->moveParms.goalTolerance) )
    return 0;
  v21 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v22 = (float)((float)v16 - v21[1]);
  v23 = (float)((float)v17 - v21[2]);
  valueFloat = ai_alignToPointDist.valueFloat;
  v25 = (float)((float)__fsqrts((float)((float)((float)((float)v15 - *v21) * (float)((float)v15 - *v21))
                                      + (float)((float)((float)v23 * (float)v23) + (float)((float)v22 * (float)v22))))
              - this->moveParms.goalTolerance);
  if ( ai_alignToPointDist.valueFloat <= 0.0 )
    valueFloat = this->ai->aiEditable.behaviors.decl->movementBehaviors.alignToPointDistance;
  if ( v25 > valueFloat )
    return 0;
  *((_BYTE *)this + 352) |= 0x20u;
  idQuat::ToForward(this: &v46, result: v47[0].mat);
  v26 = (float)((float)((float)v25 / (float)v9) * (float)0.89999998);
  LODWORD(v27) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
  if ( v26 > (float)((float)v27 * (float)0.001) )
  {
    BodyOrientation = idAI2::GetBodyOrientation(this: this->ai);
    v34 = idAI2::GetBodyOrientation(this: this->ai);
    v35 = idAIOrientation::CalcTurnRateForTime(
            this: v34,
            rotationAxis: &BodyOrientation->axis.mat[2],
            destDir: (const idVec3 *)&v46,
            timeSeconds: v26);
    ai = this->ai;
    v37 = v35;
    v38 = idAI2::GetBodyOrientation(this: ai);
    idAIOrientation::SetIdealDir(this: v38, ai, dir: (const idVec3 *)&v46);
    LODWORD(v39) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    v40 = (float)((float)v39 * (float)0.001);
    v41 = Physics->GetGravityNormal(this: Physics);
    v42 = idAI2::GetBodyOrientation(this: this->ai);
    idAIOrientation::UpdateAxis(this: v42, normal: v41, turnRate: v37, timeSeconds: v40);
  }
  else
  {
    v28 = this->ai;
    v29 = idAI2::GetBodyOrientation(this: v28);
    idAIOrientation::SetIdealDir(this: v29, ai: v28, dir: (const idVec3 *)&v46);
    v30 = idQuat::ToMat3(this: (idQuat *)&v47[0].mat[1].y, result: v47);
    v31 = idAI2::GetBodyOrientation(this: this->ai);
    idAIOrientation::SetAxis(this: v31, axis: v30);
  }
  return 1;
}


// ========================================================================
// ?IsLineInNavGraph@idAIMoveState@@UBA_NABVidVec3@@0PAV2@@Z
// EA  : 0x82A569F8
// RVA : 0x00A569F8
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

BOOL __fastcall idAIMoveState::IsLineInNavGraph(
        idAIMoveState *this,
        const idVec3 *start,
        const idVec3 *end,
        idVec3 *outTraceEndpoint)
{
  idAI2 *ai; // r3
  const idAAS2 *v9; // r3
  const idAASPosition *AASPosition; // r29
  int v11; // r6
  double v12; // fp13
  double v13; // fp12
  float v15; // [sp+60h] [-90h] BYREF
  float v16; // [sp+64h] [-8Ch]
  float v17; // [sp+68h] [-88h]
  float v18; // [sp+6Ch] [-84h]
  int v19; // [sp+70h] [-80h]
  int v20; // [sp+74h] [-7Ch]
  int v21; // [sp+78h] [-78h]
  float v22; // [sp+7Ch] [-74h]
  float v23; // [sp+80h] [-70h]
  float v24; // [sp+84h] [-6Ch]
  int v25; // [sp+88h] [-68h]
  int v26; // [sp+8Ch] [-64h]
  float v27; // [sp+90h] [-60h]
  float v28; // [sp+94h] [-5Ch]
  float v29; // [sp+98h] [-58h]
  int v30; // [sp+9Ch] [-54h]
  int v31; // [sp+A0h] [-50h]
  int v32; // [sp+A4h] [-4Ch]
  int v33; // [sp+A8h] [-48h]
  int v34; // [sp+ACh] [-44h]
  int v35; // [sp+B0h] [-40h]

  ai = this->ai;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v15 = 0.0;
  v25 = 0;
  v16 = 0.0;
  v26 = 0;
  v17 = 0.0;
  v30 = 0;
  v18 = 0.0;
  v31 = 0;
  v22 = 0.0;
  v32 = 0;
  v23 = 0.0;
  v33 = 0;
  v24 = 0.0;
  v34 = 0;
  v27 = 0.0;
  v35 = 0;
  v28 = 0.0;
  v29 = 0.0;
  v9 = ai->GetAAS(this: ai);
  AASPosition = idActor::GetAASPosition(this: this->ai, aas: v9);
  v11 = AASPosition->aas->PointAreaNum(this: (idAAS2 *)AASPosition->aas, a2: nullptr, a3: start);
  ((void (__fastcall *)(const idAAS2 *, float *, const idVec3 *, int, const idVec3 *, int, _DWORD, _DWORD))AASPosition->aas->TraceFloor)(
    a1: AASPosition->aas,
    a2: &v15,
    a3: start,
    a4: v11,
    a5: end,
    a6: 40,
    a7: 0,
    a8: 0);
  if ( outTraceEndpoint != nullptr )
  {
    v12 = v17;
    v13 = v18;
    outTraceEndpoint->x = v16;
    outTraceEndpoint->y = v12;
    outTraceEndpoint->z = v13;
  }
  return v15 == 1.0;
}


// ========================================================================
// ??0idObstacleInfo@@QAA@XZ
// EA  : 0x82A56B38
// RVA : 0x00A56B38
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

idObstacleInfo *__fastcall idObstacleInfo::idObstacleInfo(idObstacleInfo *this)
{
  this->firstObstacle.spawnId.value = 0x1FFF;
  this->startObstacle.spawnId.value = 0x1FFF;
  this->endObstacle.spawnId.value = 0x1FFF;
  this->startPos.x = 0.0;
  this->startPos.y = 0.0;
  this->startPos.z = 0.0;
  this->endPos.x = 0.0;
  this->endPos.y = 0.0;
  this->endPos.z = 0.0;
  this->updatedTime = 0;
  this->newDest.x = 0.0;
  this->newDest.y = 0.0;
  this->newDest.z = 0.0;
  this->length = 0.0;
  this->ignore.spawnId.value = 0x1FFF;
  this->obstacleEntity.spawnId.value = 0x1FFF;
  this->obstacleEntityThreshold = 0.0;
  this->moveFrustrationThreshold = 0.0;
  this->minFrustratedTime = 0;
  this->maxFrustratedTime = 0;
  this->nextFrustratedAllowTime = 0;
  this->frustrationOverTime = 0;
  this->wallCorners[0] = vec3_origin;
  this->wallCorners[1] = vec3_origin;
  return this;
}


// ========================================================================
// ?StartPerfectOrigin@idAIMoveState@@QAAXABVidQuat@@ABVidVec3@@HV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x82A56BE0
// RVA : 0x00A56BE0
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __fastcall idAIMoveState::StartPerfectOrigin(
        idAIMoveState *this,
        const idQuat *idealAxis,
        const idVec3 *idealPos,
        int lerpTimeMs,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *swi,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *si)
{
  idAI2 *ai; // r28
  __int16 v11; // r26
  __int16 v12; // r25
  double z; // fp7

  ai = this->ai;
  this->movementMode = AIMOVEMODE_PERFECTORIGIN;
  v11 = (__int16)swi;
  v12 = (__int16)si;
  if ( ai->presentable == nullptr )
    idEntity::InitPresentableInternal(this: ai);
  ai->presentable->model->useDeferredPosition = HIBYTE(this->movementMode)
                                              - 11
                                              - (HIBYTE(this->movementMode)
                                               - 12
                                               + (this->movementMode == AIMOVEMODE_PERFECTORIGIN));
  this->startPerfectMovementTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  this->perfectMovementDuration = lerpTimeMs;
  this->perfectOriginRotation.x = idealAxis->x;
  this->perfectOriginRotation.y = idealAxis->y;
  this->perfectOriginRotation.z = idealAxis->z;
  this->perfectOriginRotation.w = idealAxis->w;
  this->perfectOriginPosition.x = idealPos->x;
  this->perfectOriginPosition.y = idealPos->y;
  this->perfectOriginPosition.z = idealPos->z;
  this->perfectGotInitial = false;
  z = this->perfectOriginPosition.z;
  this->perfectMovementSwi.value = v11;
  this->perfectMovementSi.value = v12;
  this->perfectOriginPosition.z = (float)0.00000011920929 + (float)z;
}


// ========================================================================
// ?StartPerfectDestination@idAIMoveState@@QAAXABVidQuat@@ABVidVec3@@HV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x82A56CD0
// RVA : 0x00A56CD0
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __fastcall idAIMoveState::StartPerfectDestination(
        idAIMoveState *this,
        idVec3 *idealAxis,
        const idVec3 *idealPos,
        int lerpTimeMs,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *swi,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *si)
{
  idAI2 *ai; // r26
  idQuat *v13; // r3
  double v14; // fp6
  double v15; // fp5
  double y; // fp3
  double x; // fp4
  double z; // fp2
  double v19; // fp13
  double v20; // fp11
  double v21; // fp7
  double v22; // fp6
  double v23; // fp5
  idVec3 v24; // [sp+50h] [-70h] BYREF
  idQuat v25; // [sp+60h] [-60h] BYREF
  idQuat v26; // [sp+70h] [-50h] BYREF

  ai = this->ai;
  this->movementMode = AIMOVEMODE_PERFECTORIGIN;
  if ( ai->presentable == nullptr )
    idEntity::InitPresentableInternal(this: ai);
  ai->presentable->model->useDeferredPosition = HIBYTE(this->movementMode)
                                              - 11
                                              - (HIBYTE(this->movementMode)
                                               - 12
                                               + (this->movementMode == AIMOVEMODE_PERFECTORIGIN));
  this->startPerfectMovementTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  this->perfectMovementDuration = lerpTimeMs;
  this->perfectMovementSwi.value = (__int16)swi;
  this->perfectMovementSi.value = (__int16)si;
  idAnimator_AnimWeb::GetNodeTotalMovement(
    this: (idAnimator_AnimWeb *)&this->ai->aiVolatile.animation,
    modelIndex: nullptr,
    swi,
    si,
    translation: &v24,
    rotation: &v26);
  v13 = idQuat::operator*(this: &v25, result: idealAxis, a: &v24);
  v14 = (float)(idealPos->y - v13->y);
  v15 = (float)(idealPos->z - v13->z);
  this->perfectOriginPosition.x = idealPos->x - v13->x;
  this->perfectOriginPosition.y = v14;
  this->perfectOriginPosition.z = v15;
  y = idealAxis->y;
  x = idealAxis->x;
  z = idealAxis->z;
  v19 = v26.x;
  v20 = v26.z;
  v21 = (float)((float)(idealAxis->z * v26.x) + (float)((float)(idealAxis[1].x * v26.y) + (float)(idealAxis->y * v26.w)));
  v22 = (float)((float)(idealAxis[1].x * v26.z) + (float)((float)(idealAxis->z * v26.w) + (float)(idealAxis->x * v26.y)));
  v23 = (float)-(float)((float)(idealAxis->y * v26.y)
                      - (float)((float)(idealAxis[1].x * v26.w) - (float)(idealAxis->x * v26.x)));
  this->perfectOriginRotation.x = -(float)((float)(idealAxis->z * v26.y)
                                         - (float)((float)(idealAxis->y * v26.z)
                                                 + (float)((float)(idealAxis->x * v26.w)
                                                         + (float)(idealAxis[1].x * v26.x))));
  this->perfectOriginRotation.y = -(float)((float)((float)x * (float)v20) - (float)v21);
  this->perfectOriginRotation.z = -(float)((float)((float)y * (float)v19) - (float)v22);
  this->perfectOriginRotation.w = -(float)((float)((float)z * (float)v20) - (float)v23);
  this->perfectOriginPosition.z = this->perfectOriginPosition.z + (float)0.00000011920929;
}


// ========================================================================
// ?UpdateMovement_PerfectOrigin@idAIMoveState@@AAAXHM@Z
// EA  : 0x82A56E58
// RVA : 0x00A56E58
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAIMoveState::UpdateMovement_PerfectOrigin(idAIMoveState *this, int timeMS, double timeSeconds)
{
  idPhysics *Physics; // r30
  idTreeAnimator *TreeAnimatorFromPresentable; // r28
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *p_animation; // r29
  float *v8; // r3
  __int64 v9; // r7
  int v10; // r2 OVERLAPPED
  int startPerfectMovementTime; // r11
  float v12; // r8
  int v13; // r3
  float v14; // r11
  float v15; // r10
  double v16; // fp11
  float v17; // r29
  double v18; // fp25
  double v19; // fp27
  double v20; // fp26
  double w; // fp31
  double z; // fp30
  double y; // fp29
  double x; // fp28
  bool v25; // cr57
  idQuat *v26; // r3
  double v27; // fp0
  double v28; // fp13
  double v29; // fp12
  double v30; // fp5
  double v31; // fp2
  double v32; // fp11
  idQuat *v33; // r3
  double v34; // fp0
  double v35; // fp4
  double v36; // fp2
  float *v37; // r3
  double v38; // fp31
  double v39; // fp30
  double v40; // fp29
  __int64 v41; // r10
  idAIOrientation *BodyOrientation; // r3
  idAI2 *ai; // r31
  idAIOrientation *v44; // r3
  _BYTE v45[16]; // [sp+50h] [-120h] BYREF
  idQuat v46; // [sp+60h] [-110h] BYREF
  idMat3 v47; // [sp+70h] [-100h] BYREF
  float v48; // [sp+94h] [-DCh]
  float v49; // [sp+98h] [-D8h]
  float v50[4]; // [sp+A0h] [-D0h] BYREF
  idQuat v51; // [sp+B0h] [-C0h] BYREF
  idMat3 v52[3]; // [sp+C0h] [-B0h] BYREF

  if ( idEntity::GetPhysics(this: this->ai)->type == PHYSICS_AI )
  {
    Physics = idEntity::GetPhysics(this: this->ai);
    Physics[13].clip = (idClip *)1;
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->ai);
    p_animation = (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)&this->ai->aiVolatile.animation;
    if ( HIWORD(idAnimator_AnimWeb::GetCurSubWebIndex(this: (idAnimator_AnimWeb *)v45, result: p_animation)->__vftable) == (unsigned __int16)this->perfectMovementSwi.value
      && HIWORD(idAnimator_AnimWeb::GetCurStateIndex(
                  this: (idAnimator_AnimWeb *)v45,
                  result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)p_animation)->__vftable) == (unsigned __int16)this->perfectMovementSi.value )
    {
      if ( !this->perfectGotInitial )
      {
        this->perfectGotInitial = true;
        v8 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        this->perfectInitialPosition.x = *v8;
        this->perfectInitialPosition.y = v8[1];
        this->perfectInitialPosition.z = v8[2];
        this->perfectInitialRotation = *idMat3::ToQuat(this: &v47, result: (idQuat *)&this->moveOrientation.axis);
      }
      idTreeAnimator::SetRemoveOriginRotation(this: TreeAnimatorFromPresentable, removeRotation: true);
      idTreeAnimator::SetRemoveOriginRotation(this: TreeAnimatorFromPresentable, removeRotation: true);
      startPerfectMovementTime = this->startPerfectMovementTime;
      if ( timeMS >= this->perfectMovementDuration + startPerfectMovementTime )
      {
        x = this->perfectOriginRotation.x;
        y = this->perfectOriginRotation.y;
        z = this->perfectOriginRotation.z;
        w = this->perfectOriginRotation.w;
        v19 = this->perfectOriginPosition.x;
        v20 = this->perfectOriginPosition.y;
        v18 = this->perfectOriginPosition.z;
        v51.x = this->perfectOriginRotation.x;
        v51.y = y;
        v51.z = z;
        v51.w = w;
      }
      else
      {
        v12 = this->perfectOriginPosition.y;
        LODWORD(v9) = this->perfectMovementDuration;
        v13 = timeMS - startPerfectMovementTime;
        v14 = this->perfectInitialPosition.x;
        v15 = this->perfectInitialPosition.y;
        v46.x = this->perfectOriginPosition.x;
        *(_QWORD *)&v47.mat[0].x = *(_QWORD *)(&v10 - 1);
        v16 = v46.x;
        *(_QWORD *)&v46.x = v9;
        v17 = this->perfectInitialPosition.z;
        v46.z = this->perfectOriginPosition.z;
        v18 = (float)((float)((float)(v46.z - v17) * (float)((float)*(__int64 *)(&v10 - 1) / (float)v9)) + v17);
        v46.z = v17;
        v19 = (float)((float)((float)((float)v16 - v14) * (float)((float)*(__int64 *)(&v10 - 1) / (float)v9)) + v14);
        v20 = (float)((float)((float)(v12 - v15) * (float)((float)*(__int64 *)(&v10 - 1) / (float)v9)) + v15);
        idQuat::Slerp(
          this: &v51,
          from: &this->perfectInitialRotation,
          to: &this->perfectOriginRotation,
          t: (float)((float)*(__int64 *)(&v10 - 1) / (float)v9));
        w = v51.w;
        z = v51.z;
        y = v51.y;
        x = v51.x;
      }
      v25 = timeMS > this->startPerfectMovementTime;
      *(idVec3 *)&v47.mat[1].y = vec3_origin;
      v52[0].mat[0].x = quat_identity.x;
      v52[0].mat[0].y = quat_identity.y;
      v52[0].mat[0].z = quat_identity.z;
      v52[0].mat[1].x = quat_identity.w;
      if ( v25 )
      {
        idTreeAnimator::GetTotalOriginTransform(
          this: TreeAnimatorFromPresentable,
          rot: (idQuat *)v52,
          trans: (idVec3 *)&v47.mat[1].y);
        w = v51.w;
        z = v51.z;
        y = v51.y;
        x = v51.x;
      }
      v26 = idQuat::Inverse(this: &v46, result: (idQuat *)v52);
      v27 = v26->x;
      v52[0].mat[0].x = v26->x;
      v28 = v26->y;
      v52[0].mat[0].y = v26->y;
      v29 = v26->z;
      v52[0].mat[0].z = v26->z;
      v30 = (float)((float)((float)v28 * (float)w) + (float)(v26->w * (float)y));
      v31 = (float)((float)((float)v29 * (float)w) + (float)(v26->w * (float)z));
      v32 = (float)-(float)((float)((float)v28 * (float)y)
                          - (float)((float)(v26->w * (float)w) - (float)((float)v27 * (float)x)));
      v52[0].mat[0].x = -(float)((float)((float)v29 * (float)y)
                               - (float)((float)(v26->w * (float)x)
                                       + (float)((float)((float)v28 * (float)z) + (float)((float)w * (float)v27))));
      v52[0].mat[1].x = -(float)((float)((float)v29 * (float)z) - (float)v32);
      v52[0].mat[0].y = -(float)((float)((float)z * (float)v27) - (float)((float)((float)v29 * (float)x) + (float)v30));
      v52[0].mat[0].z = -(float)((float)((float)v28 * (float)x) - (float)((float)((float)y * (float)v27) + (float)v31));
      v33 = idQuat::operator*(this: (idQuat *)&v47, result: (idVec3 *)&v51, a: (const idVec3 *)&v47.mat[1].y);
      v34 = v33->x;
      v47.mat[1].y = v33->x;
      v35 = (float)(v33->y + (float)v20);
      v47.mat[1].z = v33->y;
      v36 = (float)(v33->z + (float)v18);
      v47.mat[1].y = (float)v34 + (float)v19;
      v47.mat[1].z = v35;
      v47.mat[2].x = v36;
      idQuat::ToMat3(this: (idQuat *)&v52[0].mat[1].y, result: v52);
      v37 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v38 = (float)(v47.mat[1].y - *v37);
      v39 = (float)(v47.mat[1].z - v37[1]);
      v40 = (float)(v47.mat[2].x - v37[2]);
      LODWORD(v41) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
      *(_QWORD *)&v47.mat[0].x = v41;
      v49 = (float)v40 * (float)((float)960.0 / (float)v41);
      v47.mat[2].z = (float)v38 * (float)((float)960.0 / (float)v41);
      v48 = (float)v39 * (float)((float)960.0 / (float)v41);
      Physics->SetLinearVelocity(this: Physics, a2: (const idVec3 *)&v47.mat[2].z, a3: 0);
      idRenderModel::SetAxis(this: TreeAnimatorFromPresentable, a: (idMat3 *)&v52[0].mat[1].y);
      idRenderModel::CommitThisFrame(this: TreeAnimatorFromPresentable);
      idAIOrientation::SetAxis(this: &this->moveOrientation, axis: (idMat3 *)&v52[0].mat[1].y);
      idAIOrientation::SetIdealDir(this: &this->moveOrientation, ai: this->ai, dir: (const idVec3 *)&v52[0].mat[1].y);
      BodyOrientation = idAI2::GetBodyOrientation(this: this->ai);
      idAIOrientation::SetAxis(this: BodyOrientation, axis: (idMat3 *)&v52[0].mat[1].y);
      ai = this->ai;
      v44 = idAI2::GetBodyOrientation(this: ai);
      idAIOrientation::SetIdealDir(this: v44, ai, dir: (const idVec3 *)&v52[0].mat[1].y);
    }
    else
    {
      v50[0] = 0.0;
      v50[1] = 0.0;
      v50[2] = 0.0;
      Physics->SetLinearVelocity(this: Physics, a2: (const idVec3 *)v50, a3: 0);
    }
  }
  else
  {
    idAIMoveState::Stop(this, newStatus: 0);
  }
}


// ========================================================================
// ?UpdateMovement_Player@idAIMoveState@@AAAXM@Z
// EA  : 0x82A57330
// RVA : 0x00A57330
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __fastcall idAIMoveState::UpdateMovement_Player(idAIMoveState *this, double timeSeconds)
{
  idPhysics *Physics; // r3
  const idVec3 *v5; // r3

  idAIMoveState::ResetStuck(this);
  Physics = idEntity::GetPhysics(this: this->ai);
  v5 = Physics->GetGravityNormal(this: Physics);
  idAIOrientation::UpdateAxis(this: &this->moveOrientation, normal: v5, turnRate: 720.0, timeSeconds);
}


// ========================================================================
// ?UpdateDirection@idAIMoveState@@AAA?AW4turnDirection_t@@M@Z
// EA  : 0x82A57398
// RVA : 0x00A57398
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

turnDirection_t __fastcall idAIMoveState::UpdateDirection(idAIMoveState *this, double timeSeconds)
{
  idAIOrientation *p_moveOrientation; // r30
  idAIOrientation *BodyOrientation; // r3
  double v6; // fp30
  idPhysics *Physics; // r3
  float *v8; // r3
  idAI2 *ai; // r3
  double v10; // fp9
  double v11; // fp7
  double v12; // fp6
  idPhysics *v13; // r3
  const idVec3 *v14; // r3
  double v15; // fp31
  double v18; // fp9
  double v19; // fp2
  double v20; // fp28
  double v21; // fp27
  double v22; // fp26
  idPhysics *v23; // r3
  float *v24; // r3
  long double v25; // fp2
  double v26; // fp1
  idPhysics *v27; // r3
  idPhysics *v28; // r3
  const idVec3 *v29; // r28
  idPhysics *v30; // r3
  const idVec3 *v31; // r3
  idAI2 *v32; // r11
  double v33; // fp0
  idVec3 v35; // [sp+50h] [-80h] BYREF
  idVec3 v36[6]; // [sp+60h] [-70h] BYREF

  if ( this->moveStatus == AIMOVESTATUS_MOVING )
  {
    p_moveOrientation = &this->moveOrientation;
    idAIOrientation::SetIdealDirTowards(this: &this->moveOrientation, ai: this->ai, point: &this->nextPoint);
  }
  else
  {
    BodyOrientation = idAI2::GetBodyOrientation(this: this->ai);
    p_moveOrientation = &this->moveOrientation;
    idAIOrientation::SetIdealDir(this: &this->moveOrientation, ai: this->ai, dir: &BodyOrientation->idealDir);
  }
  v6 = idAI2::CalcMovementTurnRate(
         this: this->ai,
         idealDir: &p_moveOrientation->idealDir,
         curDir: this->moveOrientation.axis.mat);
  Physics = idEntity::GetPhysics(this: this->ai);
  v8 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v10 = (float)(this->nextPoint.x - *v8);
  v11 = (float)(this->nextPoint.y - v8[1]);
  v12 = (float)(this->nextPoint.z - v8[2]);
  ai = this->ai;
  v35.x = v10;
  v35.y = v11;
  v35.z = v12;
  v13 = idEntity::GetPhysics(this: ai);
  v14 = v13->GetGravityNormal(this: v13);
  v15 = 1.0;
  idVec3::ProjectOntoPlane(this: &v35, normal: v14, overBounce: 1.0);
  _FP2 = (float)((float)((float)(v35.x * v35.x) + (float)((float)(v35.z * v35.z) + (float)(v35.y * v35.y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f13, f2, f3, f13 }
  v18 = __frsqrte(_FP13);
  v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18
                                                                                      * (float)((float)((float)(v35.x * v35.x) + (float)((float)(v35.z * v35.z) + (float)(v35.y * v35.y)))
                                                                                              * (float)0.5))
                                                                              * (float)v18)
                                                                      - (float)1.5)
                                                      * (float)v18)
                                              * (float)((float)((float)(v35.x * v35.x)
                                                              + (float)((float)(v35.z * v35.z) + (float)(v35.y * v35.y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v18
                                                                              * (float)((float)((float)(v35.x * v35.x)
                                                                                              + (float)((float)(v35.z * v35.z) + (float)(v35.y * v35.y)))
                                                                                      * (float)0.5))
                                                                      * (float)v18)
                                                              - (float)1.5)
                                              * (float)v18))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v18
                                                      * (float)((float)((float)(v35.x * v35.x)
                                                                      + (float)((float)(v35.z * v35.z)
                                                                              + (float)(v35.y * v35.y)))
                                                              * (float)0.5))
                                              * (float)v18)
                                      - (float)1.5)
                      * (float)v18));
  v20 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v35.x * v35.x) + (float)((float)(v35.z * v35.z) + (float)(v35.y * v35.y))) * (float)0.5)) * (float)v18) - (float)1.5) * (float)v18)
                                                                                              * (float)((float)((float)(v35.x * v35.x) + (float)((float)(v35.z * v35.z) + (float)(v35.y * v35.y))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v35.x * v35.x) + (float)((float)(v35.z * v35.z) + (float)(v35.y * v35.y))) * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                              * (float)v18))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v35.x * v35.x) + (float)((float)(v35.z * v35.z) + (float)(v35.y * v35.y))) * (float)0.5))
                                                                                              * (float)v18)
                                                                                      - (float)1.5)
                                                                      * (float)v18))
                                                      * (float)((float)((float)(v35.x * v35.x)
                                                                      + (float)((float)(v35.z * v35.z)
                                                                              + (float)(v35.y * v35.y)))
                                                              * (float)0.5))
                                              * (float)v19)
                                      - (float)1.5)
                      * (float)v19)
              * v35.x);
  v21 = (float)(v35.y
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v35.x * v35.x) + (float)((float)(v35.z * v35.z) + (float)(v35.y * v35.y))) * (float)0.5)) * (float)v18) - (float)1.5) * (float)v18)
                                                                                              * (float)((float)((float)(v35.x * v35.x) + (float)((float)(v35.z * v35.z) + (float)(v35.y * v35.y))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v35.x * v35.x) + (float)((float)(v35.z * v35.z) + (float)(v35.y * v35.y))) * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                              * (float)v18))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v35.x * v35.x) + (float)((float)(v35.z * v35.z) + (float)(v35.y * v35.y))) * (float)0.5))
                                                                                              * (float)v18)
                                                                                      - (float)1.5)
                                                                      * (float)v18))
                                                      * (float)((float)((float)(v35.x * v35.x)
                                                                      + (float)((float)(v35.z * v35.z)
                                                                              + (float)(v35.y * v35.y)))
                                                              * (float)0.5))
                                              * (float)v19)
                                      - (float)1.5)
                      * (float)v19));
  v22 = (float)(v35.z
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v35.x * v35.x) + (float)((float)(v35.z * v35.z) + (float)(v35.y * v35.y))) * (float)0.5)) * (float)v18) - (float)1.5) * (float)v18)
                                                                                              * (float)((float)((float)(v35.x * v35.x) + (float)((float)(v35.z * v35.z) + (float)(v35.y * v35.y))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v35.x * v35.x) + (float)((float)(v35.z * v35.z) + (float)(v35.y * v35.y))) * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                              * (float)v18))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v35.x * v35.x) + (float)((float)(v35.z * v35.z) + (float)(v35.y * v35.y))) * (float)0.5))
                                                                                              * (float)v18)
                                                                                      - (float)1.5)
                                                                      * (float)v18))
                                                      * (float)((float)((float)(v35.x * v35.x)
                                                                      + (float)((float)(v35.z * v35.z)
                                                                              + (float)(v35.y * v35.y)))
                                                              * (float)0.5))
                                              * (float)v19)
                                      - (float)1.5)
                      * (float)v19));
  v23 = idEntity::GetPhysics(this: this->ai);
  v24 = (float *)v23->GetAxis(this: v23, a2: 0);
  *(double *)&v25 = (float)((float)(v24[3] * (float)v20)
                          + (float)((float)(v24[5] * (float)v22) + (float)(v24[4] * (float)v21)));
  v26 = idMath::ACos(a: v25);
  if ( (float)((float)v26 * idMath::M_RAD2DEG) < (double)ai_turndecayAng.valueFloat )
    v6 = (float)((float)((float)(ai_turndecay.valueFloat / ai_turndecayAng.valueFloat)
                       * (float)((float)v26 * idMath::M_RAD2DEG))
               * (float)v6);
  v27 = idEntity::GetPhysics(this: this->ai);
  v27->GetLinearVelocity(this: (idPhysics *)v36, result: (idVec3 *)v27, a3: 0);
  v28 = idEntity::GetPhysics(this: this->ai);
  v29 = v28->GetOrigin(this: v28, a2: 0);
  v30 = idEntity::GetPhysics(this: this->ai);
  v31 = v30->GetGravityNormal(this: v30);
  v32 = this->ai;
  v33 = __fsqrts((float)((float)(v36[0].x * v36[0].x)
                       + (float)((float)(v36[0].y * v36[0].y) + (float)(v36[0].z * v36[0].z))));
  if ( v33 > v32->aiConstants.movement.moveSpeed.maxRange )
    v15 = (float)((float)v33 / v32->aiConstants.movement.moveSpeed.maxRange);
  if ( v33 < 10.0 )
    v6 = 1000.0;
  idAIOrientation::Update(
    this: p_moveOrientation,
    vel: v36,
    origin: v29,
    dest: &this->nextPoint,
    gravityDir: v31,
    turnRate: v6,
    maxTurnRate: (float)(v32->aiConstants.movement.moveTurnRate.maxRange * (float)v15),
    timeSeconds);
  return this->moveOrientation.currentTurnDir;
}


// ========================================================================
// ?PushEntityIfClose@idAIMoveState@@ABA_NPBVidEntity@@@Z
// EA  : 0x82A57658
// RVA : 0x00A57658
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

int __fastcall idAIMoveState::PushEntityIfClose(idAIMoveState *this, idPlayerControlled *otherEntity)
{
  idActor *v5; // r30
  double v6; // fp31
  idPhysics *Physics; // r16
  idPhysics *v8; // r17
  int v9; // r3
  float v10; // r6
  float v11; // r5
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // r11
  int v13; // r3
  float v14; // r8
  float v15; // r7
  idAI2 *ai; // r10
  float *extendedClipModel; // r11
  double x; // fp27
  double y; // fp28
  double z; // fp26
  double v21; // fp0
  double v22; // fp21
  idPhysics *v23; // r3
  double v24; // fp1
  const idAAS2 *v25; // r23
  double v26; // fp30
  double v27; // fp25
  double v28; // fp24
  double v29; // fp23
  int AreaNum; // r20
  float *v31; // r27
  const idAASPosition *AASPosition; // r3
  idRenderWorld_vtbl *v33; // r11
  double v34; // fp29
  double v35; // fp30
  const idVec3 *v36; // r3
  idVec3 *NearestPerpendicular; // r3
  double v38; // fp10
  double v39; // fp1
  double v40; // fp0
  double v41; // fp13
  idVec3 v42; // [sp+60h] [-220h] BYREF
  idVec3 v43; // [sp+70h] [-210h] BYREF
  float v44; // [sp+80h] [-200h] BYREF
  float v45; // [sp+84h] [-1FCh]
  float v46; // [sp+88h] [-1F8h]
  float v47; // [sp+90h] [-1F0h] BYREF
  float v48; // [sp+94h] [-1ECh]
  float v49; // [sp+98h] [-1E8h]
  idVec3 v50; // [sp+A0h] [-1E0h] BYREF
  idRotation v51; // [sp+B0h] [-1D0h] BYREF
  float v52; // [sp+F4h] [-18Ch]
  int v53; // [sp+F8h] [-188h]
  int v54; // [sp+FCh] [-184h]
  float v55; // [sp+100h] [-180h]
  float v56; // [sp+104h] [-17Ch]
  float v57; // [sp+108h] [-178h]
  int v58; // [sp+10Ch] [-174h]
  int v59; // [sp+110h] [-170h]
  int v60; // [sp+114h] [-16Ch]
  int v61; // [sp+118h] [-168h]
  int v62; // [sp+11Ch] [-164h]
  int v63; // [sp+120h] [-160h]
  idVec3 v64[2]; // [sp+128h] [-158h] BYREF
  idRotation v65[2]; // [sp+140h] [-140h] BYREF

  if ( idPlayerControlled::CastTo(c: otherEntity) != nullptr )
    return 0;
  v5 = idActor::CastTo(c: (idActor *)otherEntity);
  if ( v5->IsDead(this: v5) )
    return 0;
  v6 = 8100.0;
  if ( idAI2::CastTo(c: (idAI2 *)otherEntity) != nullptr )
    v6 = 3025.0;
  Physics = idEntity::GetPhysics(this: this->ai);
  v8 = idEntity::GetPhysics(this: otherEntity);
  v9 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v10 = *(float *)(v9 + 4);
  v11 = *(float *)(v9 + 8);
  GetOrigin = v8->GetOrigin;
  v50.x = *(float *)v9;
  v50.y = v10;
  v50.z = v11;
  v13 = (int)GetOrigin(this: v8, a2: 0);
  v14 = *(float *)(v13 + 4);
  v15 = *(float *)(v13 + 8);
  ai = this->ai;
  v44 = *(float *)v13;
  v45 = v14;
  v46 = v15;
  extendedClipModel = (float *)ai->aiVolatile.physics.extendedClipModel;
  if ( extendedClipModel != nullptr )
  {
    x = extendedClipModel[8];
    y = extendedClipModel[9];
    z = extendedClipModel[10];
  }
  else
  {
    z = v50.z;
    y = v50.y;
    x = v50.x;
  }
  v21 = (float)((float)((float)(v44 - (float)x) * (float)(v44 - (float)x))
              + (float)((float)(v45 - (float)y) * (float)(v45 - (float)y)));
  if ( v21 < v6 )
  {
    v22 = __fsqrts(v21);
    v23 = idEntity::GetPhysics(this: otherEntity);
    v23->GetLinearVelocity(this: (idPhysics *)&v42, result: (idVec3 *)v23, a3: 0);
    if ( v22 < 60.0 )
    {
      v43.x = (float)x - v44;
      v43.y = (float)y - v45;
      v43.z = (float)z - v46;
      if ( v22 < 55.0 )
      {
        v50.x = v44 - (float)x;
        v50.y = v45 - (float)y;
        v50.z = v46 - (float)z;
        v24 = idVec3::NormalizeFast(this: &v50);
        v25 = (const idAAS2 *)((int (__fastcall *)(idAI2 *, double))this->ai->GetAAS)(a1: this->ai, a2: v24);
        v26 = -1.0;
        v27 = 0.0;
        v28 = 0.0;
        v29 = 0.0;
        AreaNum = idActor::GetAreaNum(this: v5, aas: v25);
        v31 = (float *)ANGLES_TO_TRY;
        do
        {
          if ( v26 >= 1.0 )
            break;
          idRotation::idRotation(this: v65, rotationOrigin: &vec3_origin, rotationVec: &vec3_up, rotationAngle: *v31);
          idRotation::operator*(this: &v51, result: v65, v: &v50);
          v51.axis.mat[0].y = 0.0;
          v51.axis.mat[0].z = 0.0;
          memset(&v51.axis.mat[1].z, 0, 12);
          v51.axis.mat[1].x = 0.0;
          v51.axis.mat[1].y = 0.0;
          v51.axis.mat[2].z = 0.0;
          v53 = 0;
          *(float *)&v51.axisValid = 0.0;
          v54 = 0;
          v52 = 0.0;
          v58 = 0;
          v55 = 0.0;
          v59 = 0;
          v56 = 0.0;
          v57 = 0.0;
          v47 = (float)(v51.origin.x * (float)65.0) + (float)x;
          v48 = (float)(v51.origin.y * (float)65.0) + (float)y;
          v60 = 0;
          v49 = (float)(v51.origin.z * (float)65.0) + (float)z;
          v61 = 0;
          v62 = 0;
          v63 = 0;
          AASPosition = idActor::GetAASPosition(this: this->ai, aas: v25);
          ((void (__fastcall *)(const idAAS2 *, float *, float *, int, float *, int, _DWORD, _DWORD))AASPosition->aas->TraceFloor)(
            a1: AASPosition->aas,
            a2: &v51.axis.mat[0].y,
            a3: &v44,
            a4: AreaNum,
            a5: &v47,
            a6: 40,
            a7: 0,
            a8: 0);
          if ( v51.axis.mat[0].y > v26 )
          {
            v27 = v47;
            v26 = v51.axis.mat[0].y;
            v28 = v48;
            v29 = v49;
          }
          if ( ai_debugPushPlayer.valueInteger != 0 )
          {
            v33 = clientGame->renderWorld->__vftable;
            if ( v51.axis.mat[0].y >= 1.0 )
            {
              ((void (__fastcall *)(double))v33->DebugArrow)(a1: 16.0);
            }
            else
            {
              ((void (*)(void))v33->DebugLine)();
              v51.vec.z = (float)((float)(v48 - v45) * v51.axis.mat[0].y) + v45;
              v51.angle = (float)((float)(v49 - v46) * v51.axis.mat[0].y) + v46;
              v51.vec.y = (float)((float)(v47 - v44) * v51.axis.mat[0].y) + v44;
              clientGame->renderWorld->DebugPoint(
                this: clientGame->renderWorld,
                a2: (const idVec4 *)&idColor::colorWhite,
                a3: (const idVec3 *)&v51.vec.y,
                a4: 16,
                a5: false);
            }
          }
          ++v31;
        }
        while ( (int)v31 < (int)&_real_453d1000 );
        v43.x = (float)v27 - v44;
        v43.y = (float)v28 - v45;
        v43.z = (float)v29 - v46;
        idVec3::NormalizeFast(this: &v43);
        v34 = (float)((float)(v43.y * v42.y) + (float)((float)(v43.x * v42.x) + (float)(v43.z * v42.z)));
        v35 = __fsqrts((float)((float)(v42.y * v42.y) + (float)((float)(v42.x * v42.x) + (float)(v42.z * v42.z))));
        if ( v34 < 0.0 && v35 > idMath::FLT_SMALLEST_NON_DENORMAL )
        {
          v36 = v8->GetGravityNormal(this: v8);
          NearestPerpendicular = idGeometry::FindNearestPerpendicular(
                                   result: &v51.origin,
                                   input: &v43,
                                   up: v36,
                                   hint: &v42);
          v42.x = NearestPerpendicular->x;
          v42.y = NearestPerpendicular->y;
          v38 = NearestPerpendicular->z;
          v42.x = (float)((float)((float)((float)v34 / (float)v35) + (float)1.0) * (float)v35) * v42.x;
          v42.y = v42.y * (float)((float)((float)((float)v34 / (float)v35) + (float)1.0) * (float)v35);
          v42.z = (float)v38 * (float)((float)((float)((float)v34 / (float)v35) + (float)1.0) * (float)v35);
        }
        Physics->GetLinearVelocity(this: (idPhysics *)v64, result: (idVec3 *)Physics, a3: 0);
        v39 = idVec3::NormalizeFast(this: v64);
        if ( v22 >= 45.0 )
        {
          v40 = 25.0;
          if ( v39 > 6.0 )
          {
            if ( v39 < 60.0 )
              v41 = (float)((float)((float)((float)v39 - (float)6.0) * (float)0.37037036) + (float)5.0);
            else
              v41 = 25.0;
          }
          else
          {
            v41 = 5.0;
          }
          if ( v22 > 45.0 )
            v40 = (float)((float)((float)((float)((float)v41 - (float)25.0) * (float)((float)v22 - (float)45.0))
                                * (float)0.1)
                        + (float)25.0);
        }
        else if ( v22 > 30.0 )
        {
          v40 = (float)-(float)((float)((float)((float)v22 - (float)30.0) * (float)1.6666666) - (float)50.0);
        }
        else
        {
          v40 = 50.0;
        }
        v42.z = (float)(v43.z * (float)v40) + v42.z;
        v42.y = (float)(v43.y * (float)v40) + v42.y;
        v42.x = (float)((float)v40 * v43.x) + v42.x;
        ((void (__fastcall *)(idPhysics *, idVec3 *, _DWORD, double))v8->SetLinearVelocity)(
          a1: v8,
          a2: &v42,
          a3: 0,
          a4: v39);
      }
      if ( v8->type == PHYSICS_PLAYER )
      {
        idVec3::NormalizeFast(this: &v43);
        *(idVec3 *)&v8[25].collisionResidency = v43;
        *((float *)&v8[25].residencyQuery.index + 1) = 1.0;
      }
    }
  }
  return 1;
}


// ========================================================================
// ?RecentlyFailedMove@idAIMoveState@@UAA_NW4aiMoveReason_t@@V?$idTypesafeNumber@HW4gameTimeUnique_t@@@@@Z
// EA  : 0x82A57D18
// RVA : 0x00A57D18
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

int __fastcall idAIMoveState::RecentlyFailedMove(
        idAIMoveState *this,
        const aiMoveReason_t reason,
        const idTypesafeNumber<int,enum gameTimeUnique_t> *timeout)
{
  int v6; // r26
  moveFailureInfo_t *list; // r11
  int i; // r31
  int GameMs; // r3

  v6 = 0;
  if ( this->moveFailures.num <= 0 )
    return 0;
  list = this->moveFailures.list;
  for ( i = 0; ; ++i )
  {
    if ( list[i].moveReason == reason )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      list = this->moveFailures.list;
      if ( list[i].failureTime.value + timeout->value >= GameMs )
        break;
    }
    if ( ++v6 >= this->moveFailures.num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?GetDestinationSector@idAIMoveState@@QBA?AW4destinationSector_t@1@ABVidVec3@@@Z
// EA  : 0x82A57DB8
// RVA : 0x00A57DB8
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

idAIMoveState::destinationSector_t __fastcall idAIMoveState::GetDestinationSector(
        idAIMoveState *this,
        const idVec3 *destination)
{
  idAI2 *ai; // r30
  idAIMoveState::destinationSector_t result; // r3
  float *presentable; // r31
  idAI2 *v7; // r30
  float *v8; // r11
  double v9; // fp12
  double v10; // fp9
  idAI2 *v11; // r30
  double v12; // fp6
  double v13; // fp0
  float *v14; // r31
  double v17; // fp11
  double v18; // fp2
  double v19; // fp11
  double v20; // fp29
  double v21; // fp28
  double v22; // fp27
  idAI2 *v23; // r30
  float *v24; // r11
  double v25; // fp11
  double v26; // fp8
  double v27; // fp5
  double v30; // fp10
  double v31; // fp1
  double v32; // fp26
  double v33; // fp25
  double v34; // fp24
  idPhysics *Physics; // r3
  float *v36; // r3
  double v37; // fp7
  double v38; // fp5
  double v41; // fp8
  double v42; // fp12
  double v43; // fp9
  double v44; // fp8
  bool v45; // r10

  ai = this->ai;
  if ( ai == nullptr )
    return SECTOR_INVALID;
  presentable = (float *)ai->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: this->ai);
    presentable = (float *)ai->presentable;
  }
  v7 = this->ai;
  v8 = (float *)v7->presentable;
  if ( v8 == nullptr )
  {
    idEntity::InitPresentableInternal(this: this->ai);
    v8 = (float *)v7->presentable;
  }
  v9 = (float)(v8[34] + presentable[37]);
  v10 = (float)(v8[35] + presentable[38]);
  v11 = this->ai;
  v12 = (float)(v8[33] + presentable[36]);
  v13 = idMath::FLT_SMALLEST_NON_DENORMAL;
  _FP2 = (float)((float)((float)((float)v12 * (float)v12)
                       + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f13, f2, f3, f0 }
  v17 = __frsqrte(_FP13);
  v18 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                      * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
                                                                                              * (float)0.5))
                                                                              * (float)v17)
                                                                      - (float)1.5)
                                                      * (float)v17)
                                              * (float)((float)((float)((float)v12 * (float)v12)
                                                              + (float)((float)((float)v10 * (float)v10)
                                                                      + (float)((float)v9 * (float)v9)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v17
                                                                              * (float)((float)((float)((float)v12 * (float)v12)
                                                                                              + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
                                                                                      * (float)0.5))
                                                                      * (float)v17)
                                                              - (float)1.5)
                                              * (float)v17))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v17
                                                      * (float)((float)((float)((float)v12 * (float)v12)
                                                                      + (float)((float)((float)v10 * (float)v10)
                                                                              + (float)((float)v9 * (float)v9)))
                                                              * (float)0.5))
                                              * (float)v17)
                                      - (float)1.5)
                      * (float)v17));
  v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)v17) - (float)1.5)
                                                                                              * (float)v17)
                                                                                      * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)v17) - (float)1.5)
                                                                                      * (float)v17))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v17
                                                                                              * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5))
                                                                                      * (float)v17)
                                                                              - (float)1.5)
                                                              * (float)v17))
                                              * (float)((float)((float)((float)v12 * (float)v12)
                                                              + (float)((float)((float)v10 * (float)v10)
                                                                      + (float)((float)v9 * (float)v9)))
                                                      * (float)0.5))
                                      * (float)v18)
                              - (float)1.5)
              * (float)v18);
  v20 = (float)((float)v19 * (float)(v8[33] + presentable[36]));
  v21 = (float)((float)(v8[34] + presentable[37]) * (float)v19);
  v22 = (float)((float)(v8[35] + presentable[38]) * (float)v19);
  v14 = (float *)v11->presentable;
  if ( v14 == nullptr )
  {
    idEntity::InitPresentableInternal(this: this->ai);
    v13 = idMath::FLT_SMALLEST_NON_DENORMAL;
    v14 = (float *)v11->presentable;
  }
  v23 = this->ai;
  v24 = (float *)v23->presentable;
  if ( v24 == nullptr )
  {
    idEntity::InitPresentableInternal(this: this->ai);
    v24 = (float *)v23->presentable;
    v13 = idMath::FLT_SMALLEST_NON_DENORMAL;
  }
  v25 = (float)(v24[37] - v14[34]);
  v26 = (float)(v24[38] - v14[35]);
  v27 = (float)(v24[36] - v14[33]);
  _FP1 = (float)((float)((float)((float)v27 * (float)v27)
                       + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)))
               - (float)v13);
  __asm { fsel      f12, f1, f2, f0 }
  v30 = __frsqrte(_FP12);
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
  v32 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5)) * (float)v30) - (float)1.5) * (float)v30)
                                                                                              * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5)) * (float)v30) - (float)1.5)
                                                                                              * (float)v30))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5))
                                                                                              * (float)v30)
                                                                                      - (float)1.5)
                                                                      * (float)v30))
                                                      * (float)((float)((float)((float)v27 * (float)v27)
                                                                      + (float)((float)((float)v26 * (float)v26)
                                                                              + (float)((float)v25 * (float)v25)))
                                                              * (float)0.5))
                                              * (float)v31)
                                      - (float)1.5)
                      * (float)v31)
              * (float)v27);
  v33 = (float)((float)v25
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5)) * (float)v30) - (float)1.5) * (float)v30)
                                                                                              * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5)) * (float)v30) - (float)1.5)
                                                                                              * (float)v30))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5))
                                                                                              * (float)v30)
                                                                                      - (float)1.5)
                                                                      * (float)v30))
                                                      * (float)((float)((float)((float)v27 * (float)v27)
                                                                      + (float)((float)((float)v26 * (float)v26)
                                                                              + (float)((float)v25 * (float)v25)))
                                                              * (float)0.5))
                                              * (float)v31)
                                      - (float)1.5)
                      * (float)v31));
  v34 = (float)((float)v26
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5)) * (float)v30) - (float)1.5) * (float)v30)
                                                                                              * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5)) * (float)v30) - (float)1.5)
                                                                                              * (float)v30))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5))
                                                                                              * (float)v30)
                                                                                      - (float)1.5)
                                                                      * (float)v30))
                                                      * (float)((float)((float)((float)v27 * (float)v27)
                                                                      + (float)((float)((float)v26 * (float)v26)
                                                                              + (float)((float)v25 * (float)v25)))
                                                              * (float)0.5))
                                              * (float)v31)
                                      - (float)1.5)
                      * (float)v31));
  Physics = idEntity::GetPhysics(this: this->ai);
  v36 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v37 = (float)(destination->y - v36[1]);
  v38 = (float)(destination->z - v36[2]);
  _FP12 = (float)((float)((float)((float)(destination->x - *v36) * (float)(destination->x - *v36))
                        + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f9, f12, f13, f0 }
  v41 = __frsqrte(_FP9);
  v42 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41
                                                                                      * (float)((float)((float)((float)(destination->x - *v36) * (float)(destination->x - *v36)) + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37)))
                                                                                              * (float)0.5))
                                                                              * (float)v41)
                                                                      - (float)1.5)
                                                      * (float)v41)
                                              * (float)((float)((float)((float)(destination->x - *v36)
                                                                      * (float)(destination->x - *v36))
                                                              + (float)((float)((float)v38 * (float)v38)
                                                                      + (float)((float)v37 * (float)v37)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v41
                                                                              * (float)((float)((float)((float)(destination->x - *v36) * (float)(destination->x - *v36))
                                                                                              + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37)))
                                                                                      * (float)0.5))
                                                                      * (float)v41)
                                                              - (float)1.5)
                                              * (float)v41))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v41
                                                      * (float)((float)((float)((float)(destination->x - *v36)
                                                                              * (float)(destination->x - *v36))
                                                                      + (float)((float)((float)v38 * (float)v38)
                                                                              + (float)((float)v37 * (float)v37)))
                                                              * (float)0.5))
                                              * (float)v41)
                                      - (float)1.5)
                      * (float)v41));
  v43 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)(destination->x - *v36) * (float)(destination->x - *v36)) + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37))) * (float)0.5)) * (float)v41) - (float)1.5)
                                                                                      * (float)v41)
                                                                              * (float)((float)((float)((float)(destination->x - *v36) * (float)(destination->x - *v36))
                                                                                              + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37)))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)(destination->x - *v36) * (float)(destination->x - *v36)) + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37))) * (float)0.5)) * (float)v41)
                                                                                              - (float)1.5)
                                                                              * (float)v41))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v41
                                                                                      * (float)((float)((float)((float)(destination->x - *v36) * (float)(destination->x - *v36)) + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37)))
                                                                                              * (float)0.5))
                                                                              * (float)v41)
                                                                      - (float)1.5)
                                                      * (float)v41))
                                      * (float)((float)((float)((float)(destination->x - *v36)
                                                              * (float)(destination->x - *v36))
                                                      + (float)((float)((float)v38 * (float)v38)
                                                              + (float)((float)v37 * (float)v37)))
                                              * (float)0.5))
                              * (float)v42)
                      - (float)1.5);
  v44 = (float)((float)v43
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41
                                                                                              * (float)((float)((float)((float)(destination->x - *v36) * (float)(destination->x - *v36)) + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37))) * (float)0.5))
                                                                                      * (float)v41)
                                                                              - (float)1.5)
                                                              * (float)v41)
                                                      * (float)((float)((float)((float)(destination->x - *v36)
                                                                              * (float)(destination->x - *v36))
                                                                      + (float)((float)((float)v38 * (float)v38)
                                                                              + (float)((float)v37 * (float)v37)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v41
                                                                                      * (float)((float)((float)((float)(destination->x - *v36) * (float)(destination->x - *v36)) + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37)))
                                                                                              * (float)0.5))
                                                                              * (float)v41)
                                                                      - (float)1.5)
                                                      * (float)v41))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v41
                                                              * (float)((float)((float)((float)(destination->x - *v36)
                                                                                      * (float)(destination->x - *v36))
                                                                              + (float)((float)((float)v38 * (float)v38)
                                                                                      + (float)((float)v37 * (float)v37)))
                                                                      * (float)0.5))
                                                      * (float)v41)
                                              - (float)1.5)
                              * (float)v41)));
  v45 = (float)((float)((float)((float)(destination->x - *v36) * (float)v44) * (float)v32)
              + (float)((float)((float)((float)(destination->z - v36[2]) * (float)v44) * (float)v34)
                      + (float)((float)((float)(destination->y - v36[1]) * (float)v44) * (float)v33))) >= 0.0;
  if ( (float)((float)((float)((float)(destination->x - *v36) * (float)v44) * (float)v20)
             + (float)((float)((float)((float)(destination->z - v36[2]) * (float)v44) * (float)v22)
                     + (float)((float)((float)(destination->y - v36[1]) * (float)v44) * (float)v21))) < 0.0 )
  {
    result = SECTOR_RIGHT;
    if ( v45 )
      return SECTOR_BACKWARD;
  }
  else if ( (float)((float)((float)((float)(destination->x - *v36) * (float)v44) * (float)v32)
                  + (float)((float)((float)((float)(destination->z - v36[2]) * (float)v44) * (float)v34)
                          + (float)((float)((float)(destination->y - v36[1]) * (float)v44) * (float)v33))) >= 0.0 )
  {
    return SECTOR_LEFT;
  }
  else
  {
    return SECTOR_FORWARD;
  }
  return result;
}


// ========================================================================
// ?GetDestinationDirection@idAIMoveState@@QBA?AW4destinationSector_t@1@ABVidVec3@@@Z
// EA  : 0x82A580C0
// RVA : 0x00A580C0
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

idAIMoveState::destinationSector_t __fastcall idAIMoveState::GetDestinationDirection(
        idAIMoveState *this,
        const idVec3 *direction)
{
  idAI2 *ai; // r30
  idAIMoveState::destinationSector_t result; // r3
  float *presentable; // r31
  idAI2 *v7; // r30
  float *v8; // r11
  double v9; // fp12
  double v10; // fp9
  idAI2 *v11; // r31
  double v12; // fp6
  double v13; // fp0
  double v16; // fp11
  double v17; // fp2
  double v18; // fp11
  double v19; // fp29
  double v20; // fp28
  double v21; // fp27
  float *v22; // r29
  idAI2 *v23; // r31
  float *v24; // r11
  double v25; // fp9
  double v26; // fp6
  double v27; // fp3
  double v30; // fp2
  double v31; // fp1
  double v32; // fp5
  double v33; // fp4
  double v34; // fp3

  ai = this->ai;
  if ( ai == nullptr )
    return SECTOR_INVALID;
  presentable = (float *)ai->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: this->ai);
    presentable = (float *)ai->presentable;
  }
  v7 = this->ai;
  v8 = (float *)v7->presentable;
  if ( v8 == nullptr )
  {
    idEntity::InitPresentableInternal(this: this->ai);
    v8 = (float *)v7->presentable;
  }
  v9 = (float)(v8[34] + presentable[37]);
  v10 = (float)(v8[35] + presentable[38]);
  v12 = (float)(v8[33] + presentable[36]);
  v13 = idMath::FLT_SMALLEST_NON_DENORMAL;
  _FP2 = (float)((float)((float)((float)v12 * (float)v12)
                       + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f13, f2, f3, f0 }
  v16 = __frsqrte(_FP13);
  v17 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16
                                                                                      * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
                                                                                              * (float)0.5))
                                                                              * (float)v16)
                                                                      - (float)1.5)
                                                      * (float)v16)
                                              * (float)((float)((float)((float)v12 * (float)v12)
                                                              + (float)((float)((float)v10 * (float)v10)
                                                                      + (float)((float)v9 * (float)v9)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v16
                                                                              * (float)((float)((float)((float)v12 * (float)v12)
                                                                                              + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
                                                                                      * (float)0.5))
                                                                      * (float)v16)
                                                              - (float)1.5)
                                              * (float)v16))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v16
                                                      * (float)((float)((float)((float)v12 * (float)v12)
                                                                      + (float)((float)((float)v10 * (float)v10)
                                                                              + (float)((float)v9 * (float)v9)))
                                                              * (float)0.5))
                                              * (float)v16)
                                      - (float)1.5)
                      * (float)v16));
  v18 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                              * (float)v16)
                                                                                      * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                      * (float)v16))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v16
                                                                                              * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5))
                                                                                      * (float)v16)
                                                                              - (float)1.5)
                                                              * (float)v16))
                                              * (float)((float)((float)((float)v12 * (float)v12)
                                                              + (float)((float)((float)v10 * (float)v10)
                                                                      + (float)((float)v9 * (float)v9)))
                                                      * (float)0.5))
                                      * (float)v17)
                              - (float)1.5)
              * (float)v17);
  v19 = (float)((float)v18 * (float)(v8[33] + presentable[36]));
  v20 = (float)((float)(v8[34] + presentable[37]) * (float)v18);
  v21 = (float)((float)(v8[35] + presentable[38]) * (float)v18);
  v11 = this->ai;
  if ( v11->presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: this->ai);
    v13 = idMath::FLT_SMALLEST_NON_DENORMAL;
  }
  v22 = (float *)v11->presentable;
  v23 = this->ai;
  v24 = (float *)v23->presentable;
  if ( v24 == nullptr )
  {
    idEntity::InitPresentableInternal(this: this->ai);
    v24 = (float *)v23->presentable;
    v13 = idMath::FLT_SMALLEST_NON_DENORMAL;
  }
  v25 = (float)(v24[37] - v22[34]);
  v26 = (float)(v24[38] - v22[35]);
  v27 = (float)(v24[36] - v22[33]);
  _FP7 = (float)((float)((float)((float)v27 * (float)v27)
                       + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)))
               - (float)v13);
  __asm { fsel      f4, f7, f8, f0 }
  v30 = __frsqrte(_FP4);
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
  v32 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5)) * (float)v30) - (float)1.5) * (float)v30)
                                                                                              * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5)) * (float)v30) - (float)1.5)
                                                                                              * (float)v30))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5))
                                                                                              * (float)v30)
                                                                                      - (float)1.5)
                                                                      * (float)v30))
                                                      * (float)((float)((float)((float)v27 * (float)v27)
                                                                      + (float)((float)((float)v26 * (float)v26)
                                                                              + (float)((float)v25 * (float)v25)))
                                                              * (float)0.5))
                                              * (float)v31)
                                      - (float)1.5)
                      * (float)v31)
              * (float)v27);
  v33 = (float)((float)v25
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5)) * (float)v30) - (float)1.5) * (float)v30)
                                                                                              * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5)) * (float)v30) - (float)1.5)
                                                                                              * (float)v30))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5))
                                                                                              * (float)v30)
                                                                                      - (float)1.5)
                                                                      * (float)v30))
                                                      * (float)((float)((float)((float)v27 * (float)v27)
                                                                      + (float)((float)((float)v26 * (float)v26)
                                                                              + (float)((float)v25 * (float)v25)))
                                                              * (float)0.5))
                                              * (float)v31)
                                      - (float)1.5)
                      * (float)v31));
  v34 = (float)((float)v26
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5)) * (float)v30) - (float)1.5) * (float)v30)
                                                                                              * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5)) * (float)v30) - (float)1.5)
                                                                                              * (float)v30))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5))
                                                                                              * (float)v30)
                                                                                      - (float)1.5)
                                                                      * (float)v30))
                                                      * (float)((float)((float)((float)v27 * (float)v27)
                                                                      + (float)((float)((float)v26 * (float)v26)
                                                                              + (float)((float)v25 * (float)v25)))
                                                              * (float)0.5))
                                              * (float)v31)
                                      - (float)1.5)
                      * (float)v31));
  if ( (float)((float)(direction->x * (float)v19)
             + (float)((float)(direction->z * (float)v21) + (float)(direction->y * (float)v20))) < 0.0 )
  {
    result = SECTOR_RIGHT;
    if ( (float)((float)(direction->z * (float)v34)
               + (float)((float)(direction->y * (float)v33) + (float)(direction->x * (float)v32))) >= 0.0 )
      return SECTOR_BACKWARD;
  }
  else if ( (float)((float)(direction->z * (float)v34)
                  + (float)((float)(direction->y * (float)v33) + (float)(direction->x * (float)v32))) >= 0.0 )
  {
    return SECTOR_LEFT;
  }
  else
  {
    return SECTOR_FORWARD;
  }
  return result;
}


// ========================================================================
// ?Reset@idObstacleInfo@@QAAXXZ
// EA  : 0x82A58458
// RVA : 0x00A58458
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __fastcall idObstacleInfo::Reset(idObstacleInfo *this)
{
  idVec3 *p_normal; // r3

  this->startPos.x = vec3_origin.x;
  this->startPos.y = vec3_origin.y;
  p_normal = &clientGame->deferredFireManager.deferredFireBuffers[0][1].fireResults.traces[0].c.normal;
  this->startPos.z = vec3_origin.z;
  this->endPos = vec3_origin;
  this->updatedTime = idGameTimeManager::GetGameMs(this: (idGameTimeManager *)&p_normal[-1686].z, type: GAMETIME_SCALED)
                    + 49;
  this->newDest = vec3_origin;
  this->firstObstacle.spawnId.value = 0x1FFF;
  this->length = 0.0;
  this->startObstacle.spawnId.value = 0x1FFF;
  this->endObstacle.spawnId.value = 0x1FFF;
  this->ignore.spawnId.value = 0x1FFF;
  this->wallCorners[0] = vec3_origin;
  this->wallCorners[1] = vec3_origin;
  this->obstacleEntity.spawnId.value = 0x1FFF;
  this->obstacleEntityThreshold = 0.0;
}


// ========================================================================
// ?UpdateMovement_Static@idAIMoveState@@AAAXM@Z
// EA  : 0x82A58538
// RVA : 0x00A58538
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __fastcall idAIMoveState::UpdateMovement_Static(idAIMoveState *this, double timeSeconds)
{
  idPhysics *Physics; // r3

  idAIMoveState::ResetStuck(this);
  Physics = idEntity::GetPhysics(this: this->ai);
  Physics->PutToRest(this: Physics);
  idAIMoveState::UpdateDirection(this, timeSeconds);
}


// ========================================================================
// ?UpdateMovement_Walking@idAIMoveState@@AAAXM@Z
// EA  : 0x82A585A0
// RVA : 0x00A585A0
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __fastcall idAIMoveState::UpdateMovement_Walking(idAIMoveState *this, double timeSeconds)
{
  idPhysics *Physics; // r25
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idAI2 *ai; // r29
  idTreeAnimator *v7; // r28
  idPresentable *presentable; // r11
  int v9; // r3
  idMat3 *p_deferredAxis; // r11
  float v11; // r8
  int v12; // r7
  int *v13; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  aiVelocityType_t velocityType; // r11
  double valueFloat; // fp31
  const idVec3 *v19; // r3
  double v20; // fp0
  idVec3 *p_nextPoint; // r29
  const idAAS2 *v25; // r27
  int v26; // r28
  float y; // r5
  float z; // r4
  const idVec3 *(__fastcall *GetGravityNormal)(idPhysics *); // r11
  const idVec3 *v30; // r3
  float v31; // r8
  float v32; // r7
  const idVec3 *(__fastcall *v33)(idPhysics *); // r6
  const idVec3 *v34; // r3
  double v35; // fp28
  double x; // fp27
  double v37; // fp26
  double v38; // fp24
  __int64 v39; // r10
  double v40; // fp2
  idAI2 *v41; // r21
  idAIOrientation *BodyOrientation; // r3
  idAIOrientation *v43; // r3
  double v44; // fp0
  char v45; // r3
  double v46; // fp9
  idLegsFSM *ActionFSM; // r3
  idAIAction *v48; // r3
  idRenderWorld *v49; // r3
  idRenderWorld *v50; // r3
  idRenderWorld *v51; // r3
  idRenderWorld *v52; // r3
  aiArrivalAction_t arrivalAction; // r11
  double v54; // fp0
  double v56; // fp10
  double v57; // fp9
  idPhysics_vtbl *v58; // r10
  __int64 v59; // r9
  double v60; // fp31
  double v61; // fp30
  double v62; // fp29
  idVec3 v63; // [sp+50h] [-1E0h] BYREF
  const char *v64; // [sp+5Ch] [-1D4h] BYREF
  float v65; // [sp+60h] [-1D0h] BYREF
  float v66; // [sp+64h] [-1CCh]
  float v67; // [sp+68h] [-1C8h]
  idBounds v68; // [sp+70h] [-1C0h] BYREF
  float v69; // [sp+88h] [-1A8h] BYREF
  float v70; // [sp+8Ch] [-1A4h]
  int v71; // [sp+90h] [-1A0h]
  idVec3 v72; // [sp+98h] [-198h] BYREF
  int v73; // [sp+ACh] [-184h] BYREF
  idMat3 v74; // [sp+B0h] [-180h] BYREF
  float v75[6]; // [sp+D8h] [-158h] BYREF
  float v76[4]; // [sp+F0h] [-140h] BYREF
  idStr v77; // [sp+100h] [-130h] BYREF
  idMat3 v78; // [sp+120h] [-110h] BYREF
  idBox v79[2]; // [sp+150h] [-E0h] BYREF

  idAIMoveState::UpdateDirection(this, timeSeconds);
  if ( idEntity::GetPhysics(this: this->ai)->type == PHYSICS_AI )
  {
    Physics = idEntity::GetPhysics(this: this->ai);
    if ( ai_debugMove.valueInteger > 0 && ai_debugLevel.valueInteger > 0 )
    {
      v74.mat[2].z = 1.0;
      v74.mat[1].y = 1.0;
      v74.mat[0].x = 1.0;
      v74.mat[1].z = 0.0;
      v74.mat[0].z = 0.0;
      v68.b[0].x = -4.0;
      v68.b[0].y = -4.0;
      v68.b[0].z = -4.0;
      v68.b[1].x = 4.0;
      v68.b[1].y = 4.0;
      v68.b[1].z = 4.0;
      v74.mat[0].y = 0.0;
      v74.mat[2].y = 0.0;
      v74.mat[2].x = 0.0;
      v74.mat[1].x = 0.0;
      idBox::idBox(this: v79, bounds: &v68, origin: &this->finalPoint, axis: &v74);
      v76[0] = 1.0;
      v76[1] = 0.0;
      v76[2] = 0.0;
      v76[3] = 1.0;
      clientGame->renderWorld->DebugBox(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)v76,
        a3: v79,
        a4: 0,
        a5: false);
    }
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->ai);
    ai = this->ai;
    v7 = TreeAnimatorFromPresentable;
    presentable = ai->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: this->ai);
      presentable = ai->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    v9 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    p_deferredAxis = &v7->deferredAxis;
    v11 = *(float *)(v9 + 4);
    v12 = *(_DWORD *)(v9 + 8);
    v69 = *(float *)v9;
    v70 = v11;
    v71 = v12;
    if ( !v7->useDeferredPosition )
      p_deferredAxis = &v7->g.axis;
    v13 = &v73;
    p_z = (_DWORD *)&p_deferredAxis[-1].mat[2].z;
    for ( i = 9; i != 0; --i )
      *++v13 = *++p_z;
    if ( BYTE2(Physics[9].clip) != 0 )
    {
      velocityType = this->velocityType;
      if ( velocityType == AIVELOCITY_ANIMDELTA )
      {
        _FP31 = ai_forceMoveSpeed.valueFloat;
        if ( ai_forceMoveSpeed.valueFloat <= 0.0 )
          _FP31 = idAIMoveState::GetMovementDeltaSpeed(this, oldAxis: &v74, curAxis: &v74);
      }
      else
      {
        valueFloat = ai_forceMoveSpeed.valueFloat;
        if ( ai_forceMoveSpeed.valueFloat <= 0.0 )
        {
          if ( velocityType == AIVELOCITY_ANIMSPEED )
            valueFloat = idAIMoveState::GetMovementDeltaSpeed(this, oldAxis: &v74, curAxis: &v74);
          else
            valueFloat = this->maxMoveSpeed;
        }
        Physics->GetLinearVelocity(this: (idPhysics *)&v72, result: (idVec3 *)Physics, a3: 0);
        v19 = Physics->GetGravityNormal(this: Physics);
        idVec3::ProjectOntoPlane(this: &v72, normal: v19, overBounce: 1.0);
        v20 = __fsqrts((float)((float)(v72.z * v72.z) + (float)((float)(v72.x * v72.x) + (float)(v72.y * v72.y))));
        if ( this->moveStatus == AIMOVESTATUS_MOVING || this->moveParms.arrivalAction == AIARRIVAL_CONTINUE )
        {
          if ( v20 <= valueFloat )
          {
            _FP11 = (float)((float)((float)(this->accelRate * (float)timeSeconds) + (float)v20) - (float)valueFloat);
            __asm { fsel      f31, f11, f31, f12 }
          }
          else
          {
            _FP11 = (float)((float)-(float)((float)(this->decelRate * (float)timeSeconds) - (float)v20)
                          - (float)valueFloat);
            __asm { fsel      f31, f11, f12, f31 }
          }
        }
        else
        {
          _FP12 = (float)-(float)((float)(this->decelRate * (float)timeSeconds) - (float)v20);
          __asm { fsel      f31, f12, f12, f29 }
        }
      }
      p_nextPoint = &this->nextPoint;
      if ( ((unsigned __int8 (__fastcall *)(idAIMoveState *, idVec3 *, double))this->WillReachPoint)(
             a1: this,
             a2: &this->nextPoint,
             a3: timeSeconds) != 0 )
      {
        if ( (*((_BYTE *)this + 352) & 0x10) == 0
          && (unsigned __int16)this->lastPath.reachIndex.value < 0x8000u
          && this->lastPath.traversalIndex > 0 )
        {
          v25 = this->ai->GetAAS(this: this->ai);
          v26 = (int)v25->GetTraversal(this: v25, a2: this->lastPath.traversalIndex);
          y = this->lastPath.traversalStart.y;
          z = this->lastPath.traversalStart.z;
          GetGravityNormal = Physics->GetGravityNormal;
          v63.x = this->lastPath.traversalStart.x;
          v63.y = y;
          v63.z = z;
          v30 = GetGravityNormal(this: Physics);
          idVec3::ProjectOntoPlane(this: &v63, normal: v30, overBounce: 1.0);
          v31 = this->nextPoint.y;
          v32 = this->nextPoint.z;
          v33 = Physics->GetGravityNormal;
          v68.b[0].x = p_nextPoint->x;
          v68.b[0].y = v31;
          v68.b[0].z = v32;
          v34 = v33(this: Physics);
          idVec3::ProjectOntoPlane(this: v68.b, normal: v34, overBounce: 1.0);
          v35 = v63.y;
          x = v63.x;
          v37 = v63.z;
          v38 = (float)((float)((float)(v68.b[0].z - v63.z) * (float)(v68.b[0].z - v63.z))
                      + (float)((float)((float)(v68.b[0].x - v63.x) * (float)(v68.b[0].x - v63.x))
                              + (float)((float)(v68.b[0].y - v63.y) * (float)(v68.b[0].y - v63.y))));
          LODWORD(v39) = gameLocal->GetGameHz(this: gameLocal, a2: GAMETIME_SCALED);
          *(_QWORD *)&v63.x = v39;
          v40 = (float)((float)((float)1.0 / (float)v39) * (float)_FP31);
          if ( v38 <= (float)((float)v40 * (float)v40) )
          {
            idQuat::ToMat3(this: (idQuat *)&v78, result: (idMat3 *)&this->traversalOrientation);
            v41 = this->ai;
            BodyOrientation = idAI2::GetBodyOrientation(this: v41);
            idAIOrientation::SetIdealDir(this: BodyOrientation, ai: v41, dir: v78.mat);
            v43 = idAI2::GetBodyOrientation(this: this->ai);
            idAIOrientation::SetAxis(this: v43, axis: &v78);
            this->traversalStartPoint.x = x;
            this->traversalStartPoint.y = v35;
            this->traversalStartPoint.z = v37;
            v44 = this->lastPath.traversalEnd.x;
            LODWORD(v63.x) = &this->traversalStartPoint;
            this->traversalEndPoint.x = v44;
            this->traversalEndPoint.y = this->lastPath.traversalEnd.y;
            this->traversalEndPoint.z = this->lastPath.traversalEnd.z;
            v45 = *((_BYTE *)this + 352) & 0x4F;
            LODWORD(v63.x) = v26 + 12;
            *((_BYTE *)this + 352) = v45 | 0x10;
            p_nextPoint->x = *(float *)(v26 + 12);
            this->nextPoint.y = *(float *)(v26 + 16);
            v46 = *(float *)(v26 + 20);
            v77.allocedAndFlag = 20;
            this->nextPoint.z = v46;
            this->lastPath.reachIndex.value = -1;
            v77.data = v77.baseBuffer;
            v77.len = 0;
            v77.baseBuffer[0] = 0;
            if ( (*(_DWORD *)(v26 + 52) & 8) != 0 )
              idStr::operator=(this: &v77, text: "$subweb:run");
            v64 = nullptr;
            v25->GetAASAnim(
              this: (idAAS2 *)v25,
              a2: (const idIndex<short,enum invalidAASAnimIndex_t> *)*(unsigned __int16 *)(v26 + 36),
              a3: (const aas2AnimName_t **)&v64);
            idAI2::WaitForTraversal(
              this: this->ai,
              priority: PRIORITY_LOW,
              traversalAnimRef: v64,
              destAnimRef: v77.data,
              ev: ANIMWEB_EVENT_START_BLEND_IN);
            ActionFSM = idAI2::GetActionFSM(this: this->ai);
            v48 = idAIAction::CastTo(c: (idAIAction *)ActionFSM->curState);
            if ( v48 != nullptr )
              v48->tempUninterruptible = true;
            if ( ai_debugTraversals.valueInteger != 0 && ai_debugLevel.valueInteger > 0 )
            {
              v49 = gameLocal->GetRenderWorld(this: gameLocal);
              v49->DebugPoint(
                this: v49,
                a2: (const idVec4 *)&idColor::colorPink,
                a3: (const idVec3 *)&v69,
                a4: 10000,
                a5: true);
              v50 = gameLocal->GetRenderWorld(this: gameLocal);
              v50->DebugPoint(
                this: v50,
                a2: (const idVec4 *)&idColor::colorMagenta,
                a3: &this->lastPath.moveGoal,
                a4: 10000,
                a5: true);
              v51 = gameLocal->GetRenderWorld(this: gameLocal);
              v51->DebugPoint(
                this: v51,
                a2: (const idVec4 *)&idColor::colorGreen,
                a3: &this->nextPoint,
                a4: 10000,
                a5: true);
              v52 = gameLocal->GetRenderWorld(this: gameLocal);
              v52->DebugPoint(
                this: v52,
                a2: (const idVec4 *)&idColor::colorBlue,
                a3: &this->lastPath.traversalStart,
                a4: 10000,
                a5: true);
            }
            idStr::FreeData(this: &v77);
          }
        }
        arrivalAction = this->moveParms.arrivalAction;
        v54 = __fsqrts((float)((float)((float)(this->nextPoint.y - v70) * (float)(this->nextPoint.y - v70))
                             + (float)((float)(p_nextPoint->x - v69) * (float)(p_nextPoint->x - v69))));
        if ( arrivalAction == AIARRIVAL_CONTINUE || v54 <= 0.0 )
        {
          if ( arrivalAction == AIARRIVAL_STOP )
            _FP31 = 0.0;
        }
        else
        {
          _FP12 = (float)(this->maxMoveSpeed - (float)((float)v54 / (float)timeSeconds));
          __asm { fsel      f31, f12, f0, f13 }
        }
      }
      v56 = (float)(this->moveOrientation.axis.mat[0].y * (float)_FP31);
      v57 = (float)(this->moveOrientation.axis.mat[0].z * (float)_FP31);
      v75[0] = this->moveOrientation.axis.mat[0].x * (float)_FP31;
      v75[1] = v56;
      v75[2] = v57;
      v58 = Physics->__vftable;
      LODWORD(v63.x) = &this->moveOrientation.axis;
      v58->SetLinearVelocity(this: Physics, a2: (const idVec3 *)v75, a3: 0);
      *((_BYTE *)this + 352) |= 0x40u;
    }
    else
    {
      Physics->Activate(this: Physics);
      *((_BYTE *)this + 352) &= ~0x40u;
    }
    if ( ((LODWORD(this->lerpDelta.z) | LODWORD(this->lerpDelta.x) | LODWORD(this->lerpDelta.y)) & 0x7FFFFFFF) != 0 )
    {
      LODWORD(v59) = gameLocal->GetGameHz(this: gameLocal, a2: GAMETIME_SCALED);
      HIDWORD(v59) = Physics->__vftable;
      v60 = (float)((float)v59 * this->lerpDelta.x);
      *(_QWORD *)&v63.x = v59;
      v61 = (float)((float)v59 * this->lerpDelta.y);
      v62 = (float)((float)v59 * this->lerpDelta.z);
      (*(void (__fastcall **)(float *, idPhysics *, _DWORD))(HIDWORD(v59) + 88))(a1: &v65, a2: Physics, a3: 0);
      v67 = v67 + (float)v62;
      v65 = v65 + (float)v60;
      v66 = v66 + (float)v61;
      Physics->SetLinearVelocity(this: Physics, a2: (const idVec3 *)&v65, a3: 0);
    }
    idAIMoveState::UpdateStuck(this);
    Physics[13].clip = nullptr;
    if ( !this->IsPlayingTraversalAnim(this) && (unsigned __int8)idAIMoveState::CheckStuck(this) != 0 )
      idAIMoveState::Stop(this, newStatus: 11);
  }
}


// ========================================================================
// __unwind$496972
// EA  : 0x82A58E60
// RVA : 0x00A58E60
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void _unwind_496972()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 560 + 256));
}


// ========================================================================
// ?UpdateMovement_Anim@idAIMoveState@@AAAXM@Z
// EA  : 0x82A58E88
// RVA : 0x00A58E88
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAIMoveState::UpdateMovement_Anim(idAIMoveState *this, double timeSeconds)
{
  int v4; // r4
  idAI2 *ai; // r11
  int GameMs; // r3
  idAI2 *v7; // r11
  int i; // r30
  idPlayerControlled *Player; // r3
  idPhysics *Physics; // r26
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idAI2 *v12; // r30
  idTreeAnimator *v13; // r29
  idPresentable *presentable; // r11
  idMat3 *p_deferredAxis; // r11
  float *v16; // r10
  _DWORD *p_z; // r11
  int j; // ctr
  int v19; // r3
  float v20; // r10
  float v21; // r9
  int LastOriginDeltaTime; // r27
  int valueInteger; // r30
  idPhysics *v24; // r21
  idRenderWorld *v25; // r3
  idRenderWorld *v26; // r20
  const char *v27; // r3
  __int64 v28; // r8
  __int64 v29; // r10
  va *v30; // r27
  idRenderWorld_vtbl *v31; // r19
  int v32; // r3
  int v33; // r6
  double v34; // fp31
  double v35; // fp30
  double v36; // fp29
  char v37; // r27
  int v38; // r3
  int lastBlendTime; // r11
  signed int v40; // r30
  double v41; // fp31
  __int64 v42; // r6 OVERLAPPED
  int v43; // r3
  __int64 v44; // r8
  int turnFramesRemaining; // r11
  double v46; // fp29
  int totalTurnFrames; // r10
  double v48; // fp0
  double v49; // fp30
  __int64 v50; // r9
  int v51; // r7
  double v52; // fp30
  double v53; // fp0
  int v54; // r3
  __int64 v55; // r9
  const idVec3 *v56; // r30
  idAIOrientation *v57; // r3
  int v58; // r9
  idAIOrientation *BodyOrientation; // r3
  turnDirection_t v60; // r5
  turnDirection_t v61; // r5
  idRenderWorld *renderWorld; // r29
  idRenderWorld_vtbl *v63; // r27
  int v64; // r3
  double z; // fp12
  idRenderWorld *v66; // r29
  idRenderWorld_vtbl *v67; // r26
  int v68; // r3
  idRenderWorld *v69; // r30
  idRenderWorld_vtbl *v70; // r29
  int v71; // r3
  int v72; // [sp+8h] [-1268h]
  int v73; // [sp+Ch] [-1264h]
  int v74; // [sp+10h] [-1260h]
  int v75; // [sp+14h] [-125Ch]
  int v76; // [sp+18h] [-1258h]
  int v77; // [sp+1Ch] [-1254h]
  __int64 v78; // [sp+60h] [-1210h]
  idAngles v79; // [sp+68h] [-1208h] BYREF
  idVec3 v80; // [sp+78h] [-11F8h] BYREF
  __int64 v81; // [sp+88h] [-11E8h]
  idVec3 v82; // [sp+90h] [-11E0h] BYREF
  float v83[4]; // [sp+A0h] [-11D0h] BYREF
  float v84[4]; // [sp+B0h] [-11C0h] BYREF
  float v85[3]; // [sp+C0h] [-11B0h] BYREF
  float v86; // [sp+CCh] [-11A4h] BYREF
  idMat3 v87; // [sp+D0h] [-11A0h] BYREF
  idMat3 v88; // [sp+100h] [-1170h] BYREF
  idMat3 v89[2]; // [sp+128h] [-1148h] BYREF
  idMat3 v90; // [sp+170h] [-1100h] BYREF
  idMat3 v91; // [sp+1A0h] [-10D0h] BYREF
  va v92; // [sp+1D0h] [-10A0h] BYREF

  if ( idEntity::GetPhysics(this: this->ai)->type != PHYSICS_AI )
  {
    v4 = 0;
LABEL_44:
    idAIMoveState::Stop(this, newStatus: v4);
    return;
  }
  ai = this->ai;
  if ( ai->aiEditable.movement.movePushStatus != AIMOVEPUSHSTATUS_PUSH_NONE )
  {
    if ( ai->aiVolatile.physics.movePushEndTime != 0
      && (GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED),
          v7 = this->ai,
          GameMs >= v7->aiVolatile.physics.movePushEndTime) )
    {
      idAI2::SetMovePushStatus(this: v7, newStatus: AIMOVEPUSHSTATUS_PUSH_NONE, frameCount: 0);
    }
    else
    {
      for ( i = 0; i < 6; ++i )
      {
        if ( idGameLocal::GetPlayer(this: gameLocal, i) != nullptr )
        {
          Player = (idPlayerControlled *)idGameLocal::GetPlayer(this: gameLocal, i);
          idAIMoveState::PushEntityIfClose(this, otherEntity: Player);
        }
      }
    }
  }
  Physics = idEntity::GetPhysics(this: this->ai);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->ai);
  v12 = this->ai;
  v13 = TreeAnimatorFromPresentable;
  presentable = v12->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: this->ai);
    presentable = v12->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  idTreeAnimator::SetRemoveOriginRotation(this: v13, removeRotation: true);
  idTreeAnimator::SetRemoveOriginRotation(this: v13, removeRotation: true);
  p_deferredAxis = &v13->deferredAxis;
  if ( !v13->useDeferredPosition )
    p_deferredAxis = &v13->g.axis;
  v16 = &v86;
  p_z = (_DWORD *)&p_deferredAxis[-1].mat[2].z;
  for ( j = 9; j != 0; --j )
    *++v16 = *(float *)++p_z;
  v19 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v20 = *(float *)(v19 + 4);
  v21 = *(float *)(v19 + 8);
  v80.x = *(float *)v19;
  v80.y = v20;
  v80.z = v21;
  idTreeAnimator::ApplyOriginDeltas(
    this: v13,
    axis: &v87,
    origin: &v80,
    outAxis: &v90,
    outOrigin: &v82,
    extraScale: &this->translationScale);
  v79.pitch = v82.x - v80.x;
  v79.yaw = v82.y - v80.y;
  v79.roll = v82.z - v80.z;
  v88.mat[0].x = v87.mat[0].x;
  v88.mat[0].y = v87.mat[1].x;
  v88.mat[0].z = v87.mat[2].x;
  v88.mat[1].x = v87.mat[0].y;
  v88.mat[1].y = v87.mat[1].y;
  v88.mat[1].z = v87.mat[2].y;
  v88.mat[2].x = v87.mat[0].z;
  v88.mat[2].y = v87.mat[1].z;
  v88.mat[2].z = v87.mat[2].z;
  idMat3::operator*(this: &v91, result: &v88, a: &v90);
  idMat3::ToAngles(this: v89, result: (idAngles *)&v91);
  if ( ai_debugDeltas.valueInteger > 0 && ai_debugLevel.valueInteger > 0 )
  {
    LastOriginDeltaTime = idTreeAnimator::GetLastOriginDeltaTime(this: v13);
    valueInteger = ai_debugDeltas.valueInteger;
    v24 = idEntity::GetPhysics(this: this->ai);
    v25 = gameLocal->GetRenderWorld(this: gameLocal);
    v86 = 1.0;
    v26 = v25;
    v85[0] = 0.5;
    v85[1] = 0.5;
    v85[2] = 0.5;
    v27 = idVec3::ToString(this: &v79, precision: 4);
    HIDWORD(v28) = "1 - formation cover, such as behind regime shield units";
    v30 = va::va(
            this: &v92,
            fmt: "%d %s",
            a3: __SPAIR64__(LastOriginDeltaTime, (unsigned int)v27),
            a4: v28,
            a5: v29,
            a6: v72,
            a7: v73,
            a8: v74,
            a9: v75,
            a10: v76,
            a11: v77);
    v31 = v26->__vftable;
    v32 = (int)v24->GetOrigin(this: v24, a2: 0);
    ((void (__fastcall *)(idRenderWorld *, va *, int, int, float *, int, int, int, double))v31->DebugText)(
      a1: v26,
      a2: v30,
      a3: v32,
      a4: v33,
      a5: v85,
      a6: 1,
      a7: 1000 * valueInteger - 1000,
      a8: 1,
      a9: 0.025);
  }
  Physics[13].clip = (idClip *)(this->movementMode == AIMOVEMODE_ANIM);
  v34 = (float)(v79.pitch + this->lerpDelta.x);
  v35 = (float)(this->lerpDelta.y + v79.yaw);
  v36 = (float)(this->lerpDelta.z + v79.roll);
  v78 = __PAIR64__(&unk_82150000, gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED));
  v84[0] = (float)v34 * (float)((float)1000.0 / (float)v78);
  v84[1] = (float)v35 * (float)((float)1000.0 / (float)v78);
  v84[2] = (float)v36 * (float)((float)1000.0 / (float)v78);
  Physics->SetLinearVelocity(this: Physics, a2: (const idVec3 *)v84, a3: 0);
  idAIMoveState::UpdateStuck(this);
  if ( v89[0].mat[0].y <= 0.001 )
    v37 = v89[0].mat[0].y < -0.001;
  else
    v37 = 2;
  v38 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  lastBlendTime = v13->lastBlendTime;
  v40 = v38 - lastBlendTime;
  if ( v38 == lastBlendTime )
  {
    idAIMoveState::ResetStuck(this);
    return;
  }
  v41 = __fabs((float)(this->turnRateScale * v89[0].mat[0].y));
  v43 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
  LODWORD(v44) = v43 / v40;
  HIDWORD(v44) = __ROL4__(v43, 1) - 1;
  turnFramesRemaining = this->turnFramesRemaining;
  __twllei(v40, 0);
  __twlgei(v40 & ~HIDWORD(v44), 0xFFFFFFFF);
  v46 = (float)((float)v44 * (float)v41);
  if ( turnFramesRemaining <= 0 || (totalTurnFrames = this->totalTurnFrames) <= 0 )
  {
    idRenderModel::SetAxis(this: v13, a: &v90);
    idRenderModel::CommitThisFrame(this: v13);
    BodyOrientation = idAI2::GetBodyOrientation(this: this->ai);
    idAIOrientation::UpdateFromAnim(this: BodyOrientation, axis: &v90, turnRate: v46, turnDir: v60, updateIdeal: v37);
  }
  else
  {
    v48 = (float)((float)v41 + this->accumulatedTurnAngle);
    this->accumulatedTurnAngle = (float)v41 + this->accumulatedTurnAngle;
    v49 = (float)((float)v44 * (float)v41);
    if ( ai_errorCorrectTurns.valueInteger != 0 && v41 > 0.0 )
    {
      HIDWORD(v50) = totalTurnFrames - turnFramesRemaining;
      LODWORD(v50) = totalTurnFrames;
      v51 = totalTurnFrames - turnFramesRemaining;
      LODWORD(v42) = turnFramesRemaining;
      v52 = (float)((float)((float)(this->actualTurnAngle - (float)v48) / (float)v42)
                  * (float)((float)*(__int64 *)((char *)&v42 - 4) / (float)v50));
      v53 = (float)((float)v48
                  + (float)((float)((float)(this->actualTurnAngle - (float)v48) / (float)v42)
                          * (float)((float)*(__int64 *)((char *)&v42 - 4) / (float)v50)));
      v81 = *(__int64 *)((char *)&v42 - 4);
      this->accumulatedTurnAngle = v53;
      v54 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
      LODWORD(v55) = v54 / v40;
      HIDWORD(v55) = __ROL4__(v54, 1) - 1;
      v81 = v55;
      __twllei(v40, 0);
      __twlgei(v40 & ~HIDWORD(v55), 0xFFFFFFFF);
      v49 = __fabs((float)((float)v55 * (float)((float)v52 + (float)v41)));
    }
    v56 = Physics->GetGravityNormal(this: Physics);
    v57 = idAI2::GetBodyOrientation(this: this->ai);
    idAIOrientation::UpdateAxis(this: v57, normal: v56, turnRate: v49, timeSeconds);
    v58 = this->turnFramesRemaining;
    this->turnFramesRemaining = v58 - 1;
    if ( v58 - 1 <= 0 )
    {
      this->turnRateScale = 1.0;
      this->turnFramesRemaining = 0;
    }
  }
  if ( (float)((float)(v79.yaw * v79.yaw) + (float)((float)(v79.pitch * v79.pitch) + (float)(v79.roll * v79.roll))) > 0.0099999998 )
  {
    idVec3::ToMat3(this: &v89[0].mat[2], result: (idMat3 *)&v79);
    idAIOrientation::UpdateFromAnim(
      this: &this->moveOrientation,
      axis: (const idMat3 *)&v89[0].mat[2],
      turnRate: v46,
      turnDir: v61,
      updateIdeal: v37);
    idAIOrientation::SetAxis(this: &this->moveOrientation, axis: (const idMat3 *)&v89[0].mat[2]);
    idAIOrientation::SetIdealDir(this: &this->moveOrientation, ai: this->ai, dir: &v89[0].mat[2]);
  }
  if ( ai_debugMove.valueInteger != 0 && ai_debugLevel.valueInteger > 0 )
  {
    renderWorld = clientGame->renderWorld;
    v63 = renderWorld->__vftable;
    v64 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    v63->DebugPoint(
      this: renderWorld,
      a2: (const idVec4 *)&idColor::colorGreen,
      a3: &this->finalPoint,
      a4: v64,
      a5: false);
    z = this->finalPoint.z;
    v83[0] = this->finalPoint.x;
    v83[1] = this->finalPoint.y;
    v83[2] = (float)z - (float)128.0;
    v66 = clientGame->renderWorld;
    v67 = v66->__vftable;
    v68 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    v67->DebugLine(
      this: v66,
      a2: (const idVec4 *)&idColor::colorGreen,
      a3: &this->finalPoint,
      a4: (const idVec3 *)v83,
      a5: v68,
      a6: false);
    v69 = clientGame->renderWorld;
    v70 = v69->__vftable;
    v71 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    v70->DebugPoint(this: v69, a2: (const idVec4 *)&idColor::colorOrange, a3: &this->nextPoint, a4: v71, a5: false);
  }
  if ( !this->IsPlayingTraversalAnim(this) && (unsigned __int8)idAIMoveState::CheckStuck(this) != 0 )
  {
    v4 = 11;
    goto LABEL_44;
  }
}


// ========================================================================
// ?GetGoalEntity@idAIMoveState@@QBAPBVidEntity@@XZ
// EA  : 0x82A59698
// RVA : 0x00A59698
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

const idEntity *__fastcall idAIMoveState::GetGoalEntity(idAIMoveState *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->moveParms.goalEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??0idAIMoveState@@QAA@XZ
// EA  : 0x82A597A0
// RVA : 0x00A597A0
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

idAIMoveState *__fastcall idAIMoveState::idAIMoveState(idAIMoveState *this)
{
  char v2; // r6

  this->ai = nullptr;
  this->__vftable = (idAIMoveState_vtbl *)&idAIMoveState::`vftable';
  this->lastUpdateMS = -1;
  idAIMoveParms::idAIMoveParms(this: &this->moveParms);
  this->velocityType = AIVELOCITY_SPEED;
  this->moveStatus = AIMOVESTATUS_DONE;
  this->movementMode = AIMOVEMODE_GROUND;
  this->nextPoint.x = 0.0;
  this->nextPoint.y = 0.0;
  this->nextPoint.z = 0.0;
  this->maxMoveSpeed = 80.0;
  this->accelRate = 640.0;
  this->decelRate = 1280.0;
  idObstacleInfo::idObstacleInfo(this: &this->obstacleInfo);
  idAIOrientation::idAIOrientation(this: &this->moveOrientation, minRate: 90.0, maxRate: 720.0);
  this->finalPoint.x = 0.0;
  this->finalPoint.y = 0.0;
  this->finalPoint.z = 0.0;
  this->lastFinalPoint.x = 0.0;
  this->lastFinalPoint.y = 0.0;
  this->lastFinalPoint.z = 0.0;
  v2 = *((_BYTE *)this + 352);
  this->traversalOrientation = quat_identity;
  *((_BYTE *)this + 352) = v2 & 7;
  idAAS2Path::idAAS2Path(this: &this->lastPath);
  this->stuckRefPoint.x = 0.0;
  this->stuckRefPoint.y = 0.0;
  this->stuckRefPoint.z = 0.0;
  this->stuckTime = 0;
  this->accumulatedDeltaLen = 0.0;
  this->numZeroVelocityFrames = 0;
  this->actualTurnAngle = 0.0;
  this->startMoveFrame = -1;
  this->lastTravelTime = -1;
  this->turnRateScale = 1.0;
  this->lastMoveTime = -1;
  this->accumulatedTurnAngle = 0.0;
  this->lastAreaNum = 0;
  this->turnFramesRemaining = 0;
  this->totalTurnFrames = 0;
  idObstacleAvoidance::idObstacleAvoidance(this: &this->oa);
  this->lerpAxisFlags = 0;
  this->endLerpTime = -1;
  this->lerpDest.x = 0.0;
  this->lerpDest.y = 0.0;
  this->lerpDest.z = 0.0;
  this->lerpDelta.x = 0.0;
  this->lerpDelta.y = 0.0;
  this->lerpDelta.z = 0.0;
  this->perfectGotInitial = false;
  this->perfectInitialRotation = quat_identity;
  this->perfectInitialPosition = vec3_origin;
  this->perfectOriginRotation = quat_identity;
  this->perfectOriginPosition = vec3_origin;
  this->perfectMovementDuration = 0;
  this->startPerfectMovementTime = 0;
  this->perfectMovementSwi.value = 0;
  this->perfectMovementSi.value = 0;
  this->traversalStartPoint.x = 0.0;
  this->traversalStartPoint.y = 0.0;
  this->traversalStartPoint.z = 0.0;
  this->traversalEndPoint.x = 0.0;
  this->traversalEndPoint.y = 0.0;
  this->traversalEndPoint.z = 0.0;
  this->traversalAnimToPlay = ANIMOVERRIDE_NONE;
  this->remainingTransitionFrames = 0;
  this->translationScale.x = 1.0;
  this->translationScale.y = 1.0;
  this->translationScale.z = 1.0;
  this->moveFailures.size = 2;
  this->moveFailures.num = 0;
  this->moveFailures.granularity = 1;
  this->moveFailures.list = this->moveFailures.staticList;
  this->moveFailures.memTag = 5;
  this->moveFailures.listStatic = 1;
  this->moveFailures.staticList[0].moveReason = 37;
  this->moveFailures.staticList[0].moveStatus = 0;
  this->moveFailures.staticList[0].failureTime.value = -1;
  this->moveFailures.staticList[0].pad[0] = 0;
  this->moveFailures.staticList[0].pad[1] = 0;
  this->moveFailures.staticList[1].moveReason = 37;
  this->moveFailures.staticList[1].moveStatus = 0;
  this->moveFailures.staticList[1].failureTime.value = -1;
  this->moveFailures.staticList[1].pad[0] = 0;
  this->moveFailures.staticList[1].pad[1] = 0;
  memset(Dst: &this->lastPath, Val: 0, Size: sizeof(this->lastPath));
  return this;
}


// ========================================================================
// ?UpdateMovement@idAIMoveState@@QAAXH@Z
// EA  : 0x82A59A48
// RVA : 0x00A59A48
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __fastcall idAIMoveState::UpdateMovement(
        idAIMoveState *this,
        const int timeMS,
        int a3,
        int a4,
        int a5,
        __int64 a6)
{
  int lastUpdateMS; // r11
  double v9; // fp13
  int v10; // r30
  double v11; // fp27
  idPhysics *Physics; // r3
  float *v13; // r3
  double v14; // fp30
  double v15; // fp29
  double v16; // fp28
  signed int v17; // r3
  __int64 v18; // r11
  int lerpAxisFlags; // r10
  double v20; // fp31
  double x; // fp0
  double y; // fp0
  double z; // fp0
  idPhysics *v24; // r29
  idPhysics *v25; // r27
  int valueInteger; // r30
  float *v27; // r3
  double v28; // fp10
  double v29; // fp9
  idRenderWorld_vtbl *v30; // r29
  int v31; // r3
  aiMovementMode_t movementMode; // r30
  idPlayerControlled *BindMaster; // r29
  idPhysics *v34; // r3
  idPhysics_Actor *v35; // r30
  idAIOrientation *BodyOrientation; // r3
  double MasterDeltaYaw; // fp1
  idAIOrientation *v38; // r3
  char *v39; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  const idMat3 *v42; // r3
  idAIOrientation *v43; // r3
  idFiniteStateMachine *AlertCycleFSM; // r3
  idVec3 v45; // [sp+50h] [-110h] BYREF
  float v46[3]; // [sp+60h] [-100h] BYREF
  char v47; // [sp+6Ch] [-F4h] BYREF
  idMat3 v48; // [sp+70h] [-F0h] BYREF
  idVec3 v49[2]; // [sp+98h] [-C8h] BYREF
  idRotation v50; // [sp+B0h] [-B0h] BYREF

  lastUpdateMS = this->lastUpdateMS;
  if ( lastUpdateMS >= 0 )
  {
    LODWORD(a6) = timeMS - lastUpdateMS;
    *(_QWORD *)&v45.x = a6;
    v9 = (double)a6;
  }
  else
  {
    *(_QWORD *)&v45.x = __PAIR64__(&unk_82390000, gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED));
    v9 = (double)*(__int64 *)&v45.x;
  }
  v10 = this->endLerpTime - timeMS;
  v11 = (float)((float)v9 * (float)0.001);
  if ( v10 <= 0 )
  {
    v20 = 0.0;
    this->lerpDelta.x = 0.0;
    this->lerpDelta.y = 0.0;
    this->lerpDelta.z = 0.0;
  }
  else
  {
    Physics = idEntity::GetPhysics(this: this->ai);
    v13 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v14 = (float)(this->lerpDest.x - *v13);
    v15 = (float)(this->lerpDest.y - v13[1]);
    v16 = (float)(this->lerpDest.z - v13[2]);
    v17 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    __twllei(v17, 0);
    LODWORD(v18) = v10 / v17;
    __twlgei(v17 & ~(__ROL4__(v10, 1) - 1), 0xFFFFFFFF);
    if ( v10 / v17 != 0 )
    {
      HIDWORD(v18) = 0x82000000;
      *(_QWORD *)&v45.x = v18;
      this->lerpDelta.x = (float)((float)1.0 / (float)v18) * (float)v14;
      this->lerpDelta.y = (float)v15 * (float)((float)1.0 / (float)v18);
      this->lerpDelta.z = (float)v16 * (float)((float)1.0 / (float)v18);
    }
    else
    {
      this->lerpDelta.x = v14;
      this->lerpDelta.y = v15;
      this->lerpDelta.z = v16;
    }
    lerpAxisFlags = this->lerpAxisFlags;
    v20 = 0.0;
    if ( (lerpAxisFlags & 1) != 0 )
      x = this->lerpDelta.x;
    else
      x = 0.0;
    this->lerpDelta.x = x;
    if ( (lerpAxisFlags & 2) != 0 )
      y = this->lerpDelta.y;
    else
      y = 0.0;
    this->lerpDelta.y = y;
    if ( (lerpAxisFlags & 4) != 0 )
      z = this->lerpDelta.z;
    else
      z = 0.0;
    this->lerpDelta.z = z;
    if ( ai_debugLerp.valueInteger != 0 )
    {
      v24 = idEntity::GetPhysics(this: this->ai);
      v25 = idEntity::GetPhysics(this: this->ai);
      valueInteger = ai_debugLerp.valueInteger;
      v27 = (float *)v24->GetOrigin(this: v24, a2: 0);
      v28 = (float)(v27[1] + (float)v15);
      v29 = (float)(*v27 + (float)v14);
      v46[2] = v27[2] + (float)v16;
      v46[0] = v29;
      v46[1] = v28;
      v30 = clientGame->renderWorld->__vftable;
      v31 = (int)v25->GetOrigin(this: v25, a2: 0);
      v30->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorLtGrey,
        a3: (const idVec3 *)v31,
        a4: (const idVec3 *)v46,
        a5: 5000 * valueInteger - 5000,
        a6: false);
    }
  }
  movementMode = this->movementMode;
  BindMaster = (idPlayerControlled *)idEntity::GetBindMaster(this: this->ai);
  if ( BindMaster != nullptr )
    movementMode = AIMOVEMODE_BOUND;
  switch ( movementMode )
  {
    case AIMOVEMODE_STATIC:
      idAIMoveState::UpdateMovement_Static(this, timeSeconds: v11);
      this->lastUpdateMS = timeMS;
      break;
    case AIMOVEMODE_GROUND:
      idAIMoveState::UpdateMovement_Walking(this, timeSeconds: v11);
      this->lastUpdateMS = timeMS;
      break;
    case AIMOVEMODE_AIR:
      idAIMoveState::ResetStuck(this);
      idAIMoveState::UpdateDirection(this, timeSeconds: v11);
      this->lastUpdateMS = timeMS;
      break;
    case AIMOVEMODE_DROP:
      idAIMoveState::ResetStuck(this);
      idEntity::GetPhysics(this: this->ai)[13].clip = (idClip *)2;
      AlertCycleFSM = idAI2::GetAlertCycleFSM(this: this->ai);
      idFiniteStateMachine::ForceUpdate(this: AlertCycleFSM);
      this->lastUpdateMS = timeMS;
      break;
    case AIMOVEMODE_ANIM:
    case AIMOVEMODE_ANIM_TURN:
    case AIMOVEMODE_ANIM_GRAVITY:
    case AIMOVEMODE_ANIM_DRIVEN:
      idAIMoveState::UpdateMovement_Anim(this, timeSeconds: v11);
      this->lastUpdateMS = timeMS;
      break;
    case AIMOVEMODE_PLAYER:
      idAIMoveState::UpdateMovement_Player(this, timeSeconds: v11);
      this->lastUpdateMS = timeMS;
      break;
    case AIMOVEMODE_BOUND:
      v34 = idEntity::GetPhysics(this: this->ai);
      v35 = (idPhysics_Actor *)v34;
      if ( v34 == nullptr || v34->type != PHYSICS_AI )
        goto LABEL_38;
      if ( idPlayerControlled::CastTo(c: BindMaster) != nullptr )
      {
        idEntity::GetMasterPosition(this: this->ai, masterOrigin: v49, masterAxis: &v48);
        BodyOrientation = idAI2::GetBodyOrientation(this: this->ai);
        idAIOrientation::SetAxis(this: BodyOrientation, axis: &v48);
        this->lastUpdateMS = timeMS;
      }
      else
      {
        MasterDeltaYaw = idPhysics_Actor::GetMasterDeltaYaw(this: v35);
        if ( MasterDeltaYaw == v20 )
          goto LABEL_38;
        v45.x = v20;
        v45.y = v20;
        v45.z = -1.0;
        idRotation::idRotation(
          this: &v50,
          rotationOrigin: &vec3_origin,
          rotationVec: &v45,
          rotationAngle: MasterDeltaYaw);
        v38 = idAI2::GetBodyOrientation(this: this->ai);
        v39 = &v47;
        p_z = (_DWORD *)&v38->idealDir.z;
        for ( i = 9; i != 0; --i )
        {
          ++p_z;
          v39 += 4;
          *(_DWORD *)v39 = *p_z;
        }
        v42 = idRotation::ToMat3(this: &v50);
        idMat3::operator*=(this: &v48, a: v42);
        v43 = idAI2::GetBodyOrientation(this: this->ai);
        idAIOrientation::SetAxis(this: v43, axis: &v48);
        this->lastUpdateMS = timeMS;
      }
      break;
    case AIMOVEMODE_PERFECTORIGIN:
      idAIMoveState::UpdateMovement_PerfectOrigin(this, timeMS, timeSeconds: v11);
      goto LABEL_38;
    default:
LABEL_38:
      this->lastUpdateMS = timeMS;
      break;
  }
}


// ========================================================================
// ?PathToPoint@idAIMoveState@@QBA_NAAUidAAS2Path@@HABVidVec3@@H1AAH@Z
// EA  : 0x82A5A0E8
// RVA : 0x00A5A0E8
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

int __fastcall idAIMoveState::PathToPoint(
        idAIMoveState *this,
        idAAS2Path *path,
        int myAreaNum,
        const idVec3 *myPos,
        int goalAreaNum,
        const idVec3 *goalPos,
        int *totalTravelTime)
{
  unsigned __int64 v14; // r6
  const char *v15; // r7
  const idAAS2 *v16; // r26
  const idAAS2 *v18; // r3
  idAI2 *ai; // r9
  const idAAS2 *v20; // r19
  int travelFlags; // r18
  idAAS2_vtbl *v22; // r24
  int entityNumber; // r17
  int v24; // r30
  unsigned __int64 v25; // r6
  const char *v26; // r7
  idPLogScope v27; // [sp+68h] [-A8h] BYREF
  idPLogScope v28[20]; // [sp+70h] [-A0h] BYREF

  RD_EventBegin(name: "idAIMoveState::PathToPoint");
  LODWORD(v14) = "idAIMoveState::PathToPoint";
  HIDWORD(v14) = 6;
  idPLogScope::idPLogScope(this: &v27, pl: &pLog, gMask: v14, label: v15);
  v16 = this->ai->GetAAS(this: this->ai);
  if ( v16 != nullptr && myAreaNum != 0 && goalAreaNum != 0 )
  {
    if ( ai_showPath.valueInteger == -1 || ai_showPath.valueInteger == this->ai->entityNumber )
    {
      v18 = this->ai->GetAAS(this: this->ai);
      ai = this->ai;
      v20 = v18;
      travelFlags = ai->aiVolatile.aas.travelFlags;
      v22 = v18->__vftable;
      entityNumber = ai->entityNumber;
      gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
      gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      ((void (__fastcall *)(const idAAS2 *, int, const idVec3 *, int, const idVec3 *, int, unsigned int, int))v22->ShowWalkPath)(
        a1: v20,
        a2: myAreaNum,
        a3: myPos,
        a4: goalAreaNum,
        a5: goalPos,
        a6: travelFlags,
        a7: travelFlags & 0xFE78C83F,
        a8: entityNumber);
      clientGame->renderWorld->DebugPoint(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorCyan,
        a3: goalPos,
        a4: 1000,
        a5: false);
    }
    if ( this->movementMode == AIMOVEMODE_AIR )
    {
      v24 = 0;
    }
    else
    {
      RD_EventBegin(name: "idAAS2Local::WalkPathToGoal");
      LODWORD(v25) = "idAAS2Local::WalkPathToGoal";
      HIDWORD(v25) = 6;
      idPLogScope::idPLogScope(this: v28, pl: &pLog, gMask: v25, label: v26);
      v24 = ((int (__fastcall *)(const idAAS2 *, idAAS2Path *, const int, const idVec3 *, const int, const idVec3 *, int, unsigned int))v16->WalkPathToGoal)(
              a1: v16,
              a2: path,
              a3: myAreaNum,
              a4: myPos,
              a5: goalAreaNum,
              a6: goalPos,
              a7: this->ai->aiVolatile.aas.travelFlags,
              a8: this->ai->aiVolatile.aas.travelFlags & 0xFE78C83F);
      idPLogScope::~idPLogScope(this: v28);
      RD_EventEnd();
    }
    *totalTravelTime = 10 * path->travelTime;
    idPLogScope::~idPLogScope(this: &v27);
    RD_EventEnd();
    return v24;
  }
  else
  {
    idPLogScope::~idPLogScope(this: &v27);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$498357
// EA  : 0x82A5A360
// RVA : 0x00A5A360
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void _unwind_498357()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 272 + 120));
}


// ========================================================================
// __unwind$498358
// EA  : 0x82A5A388
// RVA : 0x00A5A388
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void _unwind_498358()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 272 + 104));
}


// ========================================================================
// __unwind$498359
// EA  : 0x82A5A3B0
// RVA : 0x00A5A3B0
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void _unwind_498359()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 272 + 121));
}


// ========================================================================
// __unwind$498360
// EA  : 0x82A5A3D8
// RVA : 0x00A5A3D8
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void _unwind_498360()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 272 + 112));
}


// ========================================================================
// ?PathAroundObstacles@idAIMoveState@@ABA_NABVidVec3@@0PBUobstacleRoute_t@@PBVidEntity@@AAV2@AAVidObstacleInfo@@@Z
// EA  : 0x82A5A408
// RVA : 0x00A5A408
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

int __fastcall idAIMoveState::PathAroundObstacles(
        idAIMoveState *this,
        const idVec3 *startPos,
        const idVec3 *destination,
        const obstacleRoute_t *obstacleRoute,
        idAI2 *ignore,
        idVec3 *newPos,
        idObstacleInfo *obstacleInfo)
{
  unsigned __int64 v7; // r28
  const idVec3 *v8; // r26
  idVec3 *v9; // r29
  idObstacleInfo *v10; // r24
  unsigned __int64 v11; // r6
  const char *v12; // r7
  double v13; // fp28
  int v14; // r20
  float z; // r16
  float v16; // r30
  float r; // r27
  float g; // r25
  float b; // r23
  float v20; // r28
  float v21; // r22
  float v22; // r29
  float v23; // r24
  float waterLevel; // r5
  float v25; // r17
  float v26; // r3
  float v27; // r21
  float v28; // r8
  float v29; // r20
  float v30; // r18
  float v31; // r6
  float v32; // r14
  unsigned int v33; // r16
  float v34; // r17
  float v35; // r4
  float v36; // r9
  float v37; // r15
  float v38; // r26
  idPhysicsCallbacks *callbacks; // r10
  float v40; // r5
  float v41; // r7
  float v42; // r10
  float v43; // r10
  float v44; // r10
  __int64 v45; // r28
  float v46; // r14
  float v47; // r15
  float v48; // r18
  float v49; // r10
  float v50; // r8
  float v51; // r24
  float v52; // r23
  float v53; // r22
  float v54; // r10
  float v55; // r9
  float v56; // r10
  float v57; // r9
  float v58; // r29
  float v59; // r25
  float v60; // r11
  float v61; // r19
  float v62; // r22
  idPhysicsCallbacks *v63; // r23
  int v64; // r21
  float v65; // r9
  float y; // r24
  float v67; // r29
  float v68; // r25
  float v69; // r6
  float v70; // r10
  float v71; // r5
  idPhysics::residency_t collisionResidency; // r7
  float v73; // r5
  float v74; // r3
  float v75; // r10
  float v76; // r8
  float v77; // r7
  float v78; // r5
  float v79; // r4
  float v80; // r3
  float v81; // r9
  float v82; // r7
  idEntity *v83; // r3
  double v84; // fp30
  double v85; // fp29
  double v86; // fp26
  double v87; // fp25
  unsigned int v88; // r25
  idPhysics *Physics; // r3
  float *v90; // r3
  idEntity *v91; // r3
  double v92; // fp12
  double v93; // fp10
  double v94; // fp9
  idPhysics *v95; // r3
  int v96; // r3
  const idVec4 *v97; // r30
  idPhysics *v98; // r3
  float *v99; // r3
  idEntity *v100; // r3
  double v101; // fp7
  double v102; // fp6
  double v103; // fp5
  idPhysics *v104; // r3
  int v105; // r3
  idPhysics *v106; // r3
  float *v107; // r3
  idEntity *v108; // r3
  double v109; // fp2
  double v110; // fp0
  double v111; // fp13
  idPhysics *v112; // r3
  int v113; // r3
  int v114; // r3
  int v115; // r14
  const idAAS2 *v116; // r30
  double valueFloat; // fp0
  double v118; // fp25
  int v119; // r10
  const idVec3 *Origin; // r3
  int v121; // r9
  float v122; // r7
  float v123; // r6
  const idVec3 *v124; // r3
  char v125; // r11
  idActor *v126; // r3
  idAASPosition *AASPosition; // r3
  int AreaNum; // r3
  double v129; // fp0
  double v130; // fp13
  double v131; // fp12
  double x; // fp11
  double v133; // fp10
  double v134; // fp9
  idPhysics *v135; // r18
  int *v136; // r3
  int v137; // r6
  int v138; // r11
  idVec3 *(__fastcall *GetLinearVelocity)(idPhysics *, idVec3 *, int); // r10
  double v140; // fp12
  double v141; // fp0
  double v142; // fp13
  double v143; // fp14
  double v144; // fp26
  idAI2 *v145; // r3
  double v148; // fp3
  double v149; // fp6
  double v150; // fp3
  double DefaultSpeedByCurrentWalkState; // fp1
  idPhysics_vtbl *v152; // r8
  float *v153; // r3
  double v154; // fp31
  double v155; // fp30
  double v156; // fp29
  float *v157; // r3
  double v158; // fp2
  double v159; // fp1
  double v160; // fp31
  double v161; // fp13
  const idAAS2Settings *(__fastcall *GetSettings)(idAAS2 *); // ctr
  obstacleVertex_t *VertexArray; // r29
  idAASPosition *v164; // r3
  idAAS2 v165; // r26
  int v166; // r3
  float v167; // r5
  int v168; // r6
  double v169; // fp23
  double v170; // fp31
  _BYTE *v171; // r15
  int v172; // r30
  int v173; // r8
  idAI2 *v174; // r25
  const idEntity *v175; // r4
  idActor *v176; // r3
  float *v177; // r3
  double v178; // fp13
  double v179; // fp12
  physicsType_t type; // r10
  double v181; // fp13
  double v182; // fp11
  double v183; // fp19
  idVec3 *v184; // r26
  double v185; // fp30
  double v186; // fp29
  double v187; // fp28
  float *v188; // r3
  double v189; // fp9
  double v190; // fp7
  const idSpawnId **v191; // r3
  idDrone *v192; // r3
  const idSpawnId **v193; // r3
  float v194; // r7
  _DWORD *v195; // r10
  float v196; // r6
  _DWORD *v197; // r11
  int v198; // ctr
  int *v199; // r10
  _DWORD *v200; // r11
  int i; // ctr
  const idSpawnId **SpawnId; // r3
  char v203; // r30
  double v204; // fp31
  double v205; // fp30
  double v206; // fp29
  unsigned int v207; // r5
  float *OriginHistory; // r3
  float v209; // r11
  float v210; // r10
  double v211; // fp28
  double v212; // fp31
  double v213; // fp30
  int v214; // r7
  int v215; // r6
  float v216; // r9
  int v217; // r8
  double v218; // fp22
  double v219; // fp21
  double v220; // fp24
  char v221; // r23
  double v222; // fp29
  double v223; // fp27
  int v224; // r11
  float v225; // r10
  float v226; // r9
  idEntity *v227; // r3
  idPhysics *v228; // r3
  int v229; // r3
  float v230; // r11
  int v231; // r9
  unsigned int v232; // r8
  float v233; // r7
  unsigned int v234; // r6
  double v235; // fp28
  double v236; // fp30
  double v237; // fp31
  double v238; // fp26
  int GameMs; // r3
  int frustrationOverTime; // r11
  int v241; // r3
  int v242; // r11
  double v243; // fp0
  double v244; // fp13
  float *v245; // r3
  double v246; // fp31
  double v247; // fp7
  double v248; // fp6
  double v249; // fp5
  double v250; // fp0
  double v251; // fp4
  double v252; // fp3
  double v253; // fp2
  double v254; // fp25
  double v255; // fp13
  double v256; // fp26
  double v257; // fp12
  double v258; // fp23
  double v259; // fp11
  double v260; // fp29
  double v261; // fp27
  idPhysics *v262; // r3
  float *v263; // r3
  double v264; // fp5
  double v265; // fp4
  double v266; // fp2
  double v267; // fp1
  double v268; // fp31
  int y_low; // r11
  double v270; // fp0
  float v271; // r11
  float v272; // r9
  float *v273; // r3
  double v274; // fp8
  double v275; // fp5
  double v276; // fp6
  double v277; // fp2
  double v278; // fp9
  double v279; // fp7
  double v280; // fp3
  double v281; // fp4
  double v282; // fp10
  double v283; // fp29
  double v284; // fp11
  const idSpawnId **v285; // r3
  int v286; // r11
  int v287; // r11
  float v288; // r30
  bool v289; // zf
  idPhysics *v290; // r3
  int v291; // r3
  idPhysics *v292; // r3
  int v293; // r3
  int v294; // r30
  idPhysics *v295; // r29
  double v296; // fp31
  const idVec3 *v297; // r30
  const idBounds *v298; // r29
  int v299; // r3
  bool PathAroundObstacles; // r26
  double v301; // fp13
  double v302; // fp12
  double v303; // fp11
  double v304; // fp10
  int *v305; // r29
  int v306; // r23
  int v307; // r3
  int *v308; // r29
  int v309; // r23
  int v310; // r3
  int *v311; // r29
  int v312; // r23
  int v313; // r3
  idEntity *v314; // r3
  idEntity *v315; // r3
  idEntity *v316; // r3
  idEntityPtr<idEntity const > *p_endObstacle; // r10
  double v318; // fp3
  idGameLocal *v319; // r9
  float *v320; // r11
  double v321; // fp0
  double v322; // fp13
  double v323; // fp12
  int value; // r8
  idEntity *v325; // r3
  idEntity *v326; // r3
  idEntity *v327; // r29
  int v328; // r10
  __int64 v329; // r6
  idEntity *v330; // r3
  idEntity *v331; // r3
  int v332; // r8
  double v333; // fp1
  float v335; // r29
  int v336; // r30
  int v337; // r3
  __int64 v338; // r11
  __int64 v339; // r9
  int v340; // r11
  idPhysics *v341; // r3
  int v342; // r3
  idPhysics *v343; // r3
  idPhysics *v344; // r3
  float *v345; // r3
  idEntity *v346; // r3
  double v347; // fp9
  double v348; // fp7
  double v349; // fp6
  idPhysics *v350; // r3
  int v351; // r3
  idPhysics *v352; // r3
  int v353; // r3
  float v354; // r29
  int v355; // r30
  int v356; // r3
  __int64 v357; // r11
  __int64 v358; // r9
  obstacleTraceSet_t *v359; // [sp+8h] [-1888h]
  int v360; // [sp+Ch] [-1884h]
  int v361; // [sp+10h] [-1880h]
  int v362; // [sp+14h] [-187Ch]
  int v363; // [sp+18h] [-1878h]
  int v364; // [sp+1Ch] [-1874h]
  int v365; // [sp+20h] [-1870h]
  int v366; // [sp+24h] [-186Ch]
  int v367; // [sp+28h] [-1868h]
  int v368; // [sp+2Ch] [-1864h]
  int v369; // [sp+30h] [-1860h]
  int v370; // [sp+34h] [-185Ch]
  int v371; // [sp+38h] [-1858h]
  int v372; // [sp+3Ch] [-1854h]
  int v373; // [sp+40h] [-1850h]
  int v374; // [sp+44h] [-184Ch]
  int v375; // [sp+48h] [-1848h]
  int v376; // [sp+4Ch] [-1844h]
  int v377; // [sp+50h] [-1840h]
  int v378; // [sp+58h] [-1838h]
  int v379; // [sp+60h] [-1830h]
  int v380; // [sp+68h] [-1828h]
  float v381; // [sp+70h] [-1820h]
  int v382; // [sp+70h] [-1820h]
  int v383; // [sp+70h] [-1820h]
  float v384; // [sp+74h] [-181Ch]
  float v385; // [sp+74h] [-181Ch]
  float v386; // [sp+78h] [-1818h]
  float v387; // [sp+80h] [-1810h] BYREF
  float v388; // [sp+84h] [-180Ch]
  float v389; // [sp+88h] [-1808h]
  float v390; // [sp+8Ch] [-1804h]
  float v391; // [sp+90h] [-1800h]
  float v392; // [sp+94h] [-17FCh]
  float v393; // [sp+98h] [-17F8h]
  float v394; // [sp+9Ch] [-17F4h] BYREF
  float v395; // [sp+A0h] [-17F0h] BYREF
  float v396; // [sp+A4h] [-17ECh]
  int v397; // [sp+A8h] [-17E8h]
  float v398; // [sp+ACh] [-17E4h]
  float v399; // [sp+B0h] [-17E0h] BYREF
  __int64 v400; // [sp+B8h] [-17D8h]
  float v401; // [sp+C0h] [-17D0h]
  float v402; // [sp+C4h] [-17CCh] BYREF
  float a; // [sp+C8h] [-17C8h]
  idVec3 v404; // [sp+D0h] [-17C0h] BYREF
  float v405; // [sp+DCh] [-17B4h]
  float v406; // [sp+E0h] [-17B0h]
  int v407; // [sp+E4h] [-17ACh]
  float v408; // [sp+E8h] [-17A8h]
  float v409; // [sp+ECh] [-17A4h]
  float v410; // [sp+F0h] [-17A0h]
  float v411; // [sp+F4h] [-179Ch]
  float v412; // [sp+F8h] [-1798h] BYREF
  idPhysics_Actor v413; // [sp+100h] [-1790h] BYREF
  float v414; // [sp+2C8h] [-15C8h]
  idVec3 v415; // [sp+2D0h] [-15C0h] BYREF
  float v416[4]; // [sp+2E0h] [-15B0h] BYREF
  idVec3 v417; // [sp+2F0h] [-15A0h] BYREF
  int v418; // [sp+2FCh] [-1594h] BYREF
  idBounds v419; // [sp+300h] [-1590h] BYREF
  idPhysics_Actor v420; // [sp+318h] [-1578h] BYREF
  float v421; // [sp+638h] [-1258h]
  float v422; // [sp+63Ch] [-1254h]
  float v423; // [sp+640h] [-1250h]
  float v424; // [sp+644h] [-124Ch]
  int v425; // [sp+654h] [-123Ch]
  int v426; // [sp+664h] [-122Ch]
  float v427; // [sp+668h] [-1228h]
  float v428; // [sp+66Ch] [-1224h]
  float v429; // [sp+670h] [-1220h]
  int v430; // [sp+674h] [-121Ch]
  float v431; // [sp+67Ch] [-1214h]
  float v432; // [sp+694h] [-11FCh]
  float v433; // [sp+698h] [-11F8h]
  float v434; // [sp+69Ch] [-11F4h]
  float v435; // [sp+6A0h] [-11F0h]
  float v436; // [sp+6A4h] [-11ECh]
  float v437; // [sp+6A8h] [-11E8h]
  idVec3 v438[4]; // [sp+730h] [-1160h] BYREF
  _BYTE v439[304]; // [sp+760h] [-1130h] BYREF

  v7 = __PAIR64__((unsigned int)startPos, (unsigned int)this);
  v8 = destination;
  v9 = newPos;
  v10 = obstacleInfo;
  RD_EventBegin(name: "idAIMoveState::PathAroundObstacles");
  LODWORD(v11) = "idAIMoveState::PathAroundObstacles";
  HIDWORD(v11) = 2;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v413.gravityNormal, pl: &pLog, gMask: v11, label: v12);
  LODWORD(v413.waterLevel) = &idColor::colorPurple;
  LODWORD(v413.originHistory[0].y) = &idColor::colorCyan;
  HIDWORD(v400) = &idColor::colorMagenta;
  v13 = 8.0;
  *(float *)&v413.clipMask = 8.0;
  v14 = -2088894464;
  *((_DWORD *)&v413.waterViscosity + 1) = &idColor::colorYellow;
  LODWORD(v413.masterDeltaYaw) = &idColor::colorBlue;
  v407 = -2088894464;
  z = COERCE_FLOAT(&idColor::colorRed);
  v413.contactPhysicsIds.list = (int *)&idColor::colorMdGrey;
  *((_DWORD *)&v413.collisionResidency + 1) = &idColor::colorGreen;
  LODWORD(v413.gravityNormal.z) = &idColor::colorRed;
  if ( ai_showMovementTrails.valueInteger != 0 )
  {
    v16 = COERCE_FLOAT(DEBUG_COLORS);
    v398 = COERCE_FLOAT(DEBUG_COLORS);
    if ( (_S18_3 & 1) == 0 )
    {
      r = idColor::colorRed.r;
      g = idColor::colorRed.g;
      b = idColor::colorRed.b;
      v413.gravityVector.y = idColor::colorRed.a;
      v20 = idColor::colorWhite.r;
      v413.callbacks = (idPhysicsCallbacks *)LODWORD(idColor::colorGreen.r);
      v391 = COERCE_FLOAT(&aAvSsobjectVCom[20]);
      a = idColor::colorBlack.a;
      v408 = idColor::colorGreen.g;
      v21 = idColor::colorYellow.g;
      *(float *)&v413.residencyQuery.index = idColor::colorWhite.g;
      v22 = idColor::colorWhite.b;
      v395 = idColor::colorGreen.a;
      v402 = idColor::colorGreen.b;
      LODWORD(v413.residencyQuery.index) = LODWORD(idColor::colorWhite.a);
      v23 = idColor::colorBlue.b;
      v394 = idColor::colorBlue.r;
      v399 = idColor::colorBlue.g;
      *(float *)&v397 = COERCE_FLOAT(&idColor::colorOrange);
      v392 = idColor::colorBlue.a;
      v406 = idColor::colorMagenta.b;
      _S18_3 |= 1u;
      DEBUG_COLORS[0].x = idColor::colorBlack.r;
      waterLevel = v413.waterLevel;
      v396 = idColor::colorRed.g;
      v411 = idColor::colorYellow.b;
      v405 = idColor::colorYellow.a;
      v409 = idColor::colorMagenta.r;
      v410 = idColor::colorMagenta.g;
      DEBUG_COLORS[0].y = idColor::colorBlack.g;
      DEBUG_COLORS[0].z = idColor::colorBlack.b;
      v401 = COERCE_FLOAT(&DEBUG_COLORS[8]);
      v16 = v398;
      v413.collisionResidency = LODWORD(idColor::colorBrown.r);
      v393 = idColor::colorPink.r;
      v390 = *(float *)&v413.contactPhysicsIds.list;
      v25 = *(float *)(LODWORD(v413.waterLevel) + 4);
      v412 = idColor::colorBrown.g;
      v26 = idColor::colorBrown.b;
      v27 = idColor::colorCyan.r;
      v384 = idColor::colorBrown.a;
      v28 = idColor::colorMagenta.a;
      v401 = idColor::colorYellow.r;
      v397 = LODWORD(v398) + 224;
      LODWORD(v398) += 208;
      DEBUG_COLORS[0].w = idColor::colorBlack.a;
      v396 = v25;
      v391 = idColor::colorPink.g;
      v29 = idColor::colorCyan.g;
      v30 = idColor::colorCyan.b;
      *(float *)(LODWORD(v16) + 20) = idColor::colorWhite.g;
      v31 = idColor::colorOrange.g;
      v32 = idColor::colorOrange.b;
      v33 = *(_DWORD *)LODWORD(waterLevel);
      v34 = *(float *)(LODWORD(waterLevel) + 8);
      *(_DWORD *)(LODWORD(v16) + 28) = v413.residencyQuery.index;
      v35 = idColor::colorPink.b;
      v36 = idColor::colorCyan.a;
      v37 = idColor::colorOrange.r;
      v38 = idColor::colorOrange.a;
      *(float *)(LODWORD(v16) + 44) = v413.gravityVector.y;
      callbacks = v413.callbacks;
      v40 = *(float *)(LODWORD(waterLevel) + 12);
      v41 = idColor::colorPink.a;
      *(float *)(LODWORD(v16) + 16) = v20;
      *(float *)(LODWORD(v16) + 24) = v22;
      *(_DWORD *)(LODWORD(v16) + 48) = callbacks;
      v42 = v408;
      *(float *)(LODWORD(v16) + 32) = r;
      *(float *)(LODWORD(v16) + 36) = g;
      *(float *)(LODWORD(v16) + 40) = b;
      *(float *)(LODWORD(v16) + 72) = v23;
      *(float *)(LODWORD(v16) + 52) = v42;
      *(float *)(LODWORD(v16) + 56) = v402;
      *(float *)(LODWORD(v16) + 60) = v395;
      *(float *)(LODWORD(v16) + 64) = v394;
      v43 = v399;
      v399 = v27;
      *(float *)(LODWORD(v16) + 68) = v43;
      v44 = v392;
      v392 = v28;
      *(float *)(LODWORD(v16) + 76) = v44;
      *(float *)&v45 = v392;
      v395 = v30;
      v413.gravityVector.y = v32;
      v46 = v410;
      v413.residencyQuery.index = __PAIR64__(v33, LODWORD(v38));
      v410 = v392;
      v408 = v37;
      v47 = v409;
      v394 = v29;
      v409 = v399;
      v48 = v405;
      *(float *)(LODWORD(v16) + 84) = v21;
      v405 = v29;
      v402 = v36;
      v14 = v407;
      *(float *)&v413.callbacks = v31;
      v49 = v390;
      v50 = idColor::colorLtGrey.r;
      v51 = *(float *)LODWORD(v390);
      v407 = LODWORD(v395);
      v52 = *(float *)(LODWORD(v390) + 4);
      v53 = *(float *)(LODWORD(v390) + 8);
      *(float *)(LODWORD(v16) + 104) = v406;
      v54 = *(float *)(LODWORD(v49) + 12);
      v55 = idColor::colorDkGrey.r;
      *(float *)(LODWORD(v16) + 108) = v410;
      LODWORD(v45) = this;
      v395 = v54;
      v56 = v402;
      v402 = v55;
      *(float *)(LODWORD(v16) + 112) = v409;
      v57 = idColor::colorDkGrey.g;
      z = v413.gravityNormal.z;
      v58 = idColor::colorLtGrey.b;
      v59 = idColor::colorLtGrey.a;
      v60 = idColor::colorLtGrey.g;
      v394 = v53;
      v399 = v52;
      *(_QWORD *)&v413.gravityNormal.z = v45;
      *(float *)(LODWORD(v16) + 116) = v405;
      v61 = v411;
      v62 = v408;
      v63 = v413.callbacks;
      v64 = v407;
      v408 = v57;
      v65 = idColor::colorDkGrey.b;
      v392 = v51;
      v381 = v59;
      v411 = v58;
      y = v413.gravityVector.y;
      v67 = *(float *)&v413.residencyQuery.index;
      v68 = *((float *)&v413.residencyQuery.index + 1);
      v69 = idColor::colorDkGrey.a;
      v8 = destination;
      *(float *)(LODWORD(v16) + 80) = v401;
      *(float *)(LODWORD(v16) + 88) = v61;
      *(float *)(LODWORD(v16) + 92) = v48;
      *(float *)(LODWORD(v16) + 96) = v47;
      *(float *)(LODWORD(v16) + 100) = v46;
      *(_DWORD *)(LODWORD(v16) + 120) = v64;
      *(float *)(LODWORD(v16) + 124) = v56;
      *(float *)(LODWORD(v16) + 128) = v62;
      *(_DWORD *)(LODWORD(v16) + 132) = v63;
      *(float *)(LODWORD(v16) + 156) = v40;
      v70 = v396;
      v71 = v393;
      *(float *)(LODWORD(v16) + 168) = v35;
      *(float *)(LODWORD(v16) + 172) = v41;
      *(float *)(LODWORD(v16) + 184) = v26;
      *(float *)(LODWORD(v16) + 148) = v70;
      *(float *)(LODWORD(v16) + 160) = v71;
      collisionResidency = v413.collisionResidency;
      v73 = v412;
      v74 = v411;
      *(float *)(LODWORD(v16) + 164) = v391;
      *(_DWORD *)(LODWORD(v16) + 176) = collisionResidency;
      *(float *)(LODWORD(v16) + 180) = v73;
      *(float *)(LODWORD(v16) + 188) = v384;
      *(float *)(LODWORD(v16) + 192) = v50;
      *(float *)(LODWORD(v16) + 196) = v60;
      *(float *)(LODWORD(v16) + 200) = v74;
      v75 = v392;
      v76 = v399;
      v77 = v394;
      v78 = v395;
      v79 = v402;
      v80 = v408;
      *(float *)(LODWORD(v16) + 136) = y;
      *(float *)(LODWORD(v16) + 144) = v67;
      v9 = newPos;
      v10 = obstacleInfo;
      v7 = *(_QWORD *)&v413.gravityNormal.z;
      *(float *)(LODWORD(v16) + 140) = v68;
      *(float *)(LODWORD(v16) + 152) = v34;
      *(float *)(LODWORD(v16) + 204) = v381;
      *(float *)(LODWORD(v16) + 208) = v75;
      *(float *)(LODWORD(v16) + 212) = v76;
      *(float *)(LODWORD(v16) + 216) = v77;
      *(float *)(LODWORD(v16) + 220) = v78;
      *(float *)(LODWORD(v16) + 224) = v79;
      *(float *)(LODWORD(v16) + 228) = v80;
      *(float *)(LODWORD(v16) + 232) = v65;
      *(float *)(LODWORD(v16) + 236) = v69;
    }
    v81 = *(float *)(v7 + 248);
    v82 = *(float *)(v7 + 252);
    v83 = *(idEntity **)(v7 + 4);
    v404.x = *(float *)(v7 + 244);
    v404.y = v81;
    v404.z = v82;
    v84 = v81;
    v85 = v82;
    v86 = (float)(v81 * (float)100.0);
    v87 = (float)(v82 * (float)100.0);
    v88 = v83->entityNumber % 0xFu;
    Physics = idEntity::GetPhysics(this: v83);
    v90 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v92 = (float)(v90[2] + (float)v87);
    v93 = (float)(v90[1] + (float)v86);
    v94 = (float)((float)(v404.x * (float)100.0) + *v90);
    v91 = *(idEntity **)(v7 + 4);
    v413.yawHistory[10] = v94;
    v413.yawHistory[12] = v92;
    v413.yawHistory[11] = v93;
    v95 = idEntity::GetPhysics(this: v91);
    v96 = (int)v95->GetOrigin(this: v95, a2: 0);
    v97 = (const idVec4 *)(16 * v88 + LODWORD(v16));
    (*(void (__fastcall **)(_DWORD, const idVec4 *, int, float *, double))(**(_DWORD **)(*(_DWORD *)(v14 + 17592) + 4)
                                                                         + 180))(
      a1: *(_DWORD *)(*(_DWORD *)(v14 + 17592) + 4),
      a2: v97,
      a3: v96,
      a4: &v413.yawHistory[10],
      a5: 8.0);
    v98 = idEntity::GetPhysics(this: *(idEntity **)(v7 + 4));
    v99 = (float *)v98->GetOrigin(this: v98, a2: 0);
    v101 = v99[1];
    v102 = (float)(v99[2] + (float)48.0);
    v103 = *v99;
    v100 = *(idEntity **)(v7 + 4);
    v413.yawHistory[2] = v103;
    v413.yawHistory[3] = v101;
    v413.yawHistory[4] = v102;
    v104 = idEntity::GetPhysics(this: v100);
    v105 = (int)v104->GetOrigin(this: v104, a2: 0);
    (*(void (__fastcall **)(_DWORD, const idVec4 *, int, float *, int, _DWORD))(**(_DWORD **)(*(_DWORD *)(v14 + 17592)
                                                                                            + 4)
                                                                              + 176))(
      a1: *(_DWORD *)(*(_DWORD *)(v14 + 17592) + 4),
      a2: v97,
      a3: v105,
      a4: &v413.yawHistory[2],
      a5: 16,
      a6: 0);
    v106 = idEntity::GetPhysics(this: *(idEntity **)(v7 + 4));
    v107 = (float *)v106->GetOrigin(this: v106, a2: 0);
    v109 = (float)(v107[2] + (float)((float)v85 * (float)2.0));
    v110 = (float)(v107[1] + (float)((float)v84 * (float)2.0));
    v111 = (float)((float)(v404.x * (float)2.0) + *v107);
    v108 = *(idEntity **)(v7 + 4);
    v416[0] = v111;
    v416[2] = v109;
    v416[1] = v110;
    v112 = idEntity::GetPhysics(this: v108);
    v113 = (int)v112->GetOrigin(this: v112, a2: 0);
    (*(void (__fastcall **)(_DWORD, const idVec4 *, int, float *, int, int))(**(_DWORD **)(*(_DWORD *)(v14 + 17592) + 4)
                                                                           + 176))(
      a1: *(_DWORD *)(*(_DWORD *)(v14 + 17592) + 4),
      a2: v97,
      a3: v113,
      a4: v416,
      a5: 60000,
      a6: 1);
  }
  v9->x = v8->x;
  v9->y = v8->y;
  v9->z = v8->z;
  if ( ai_avoidObstacles.valueInteger == 0 )
  {
    idPLogScope::~idPLogScope(this: (idPLogScope *)&v413.gravityNormal);
LABEL_151:
    RD_EventEnd();
    return 1;
  }
  v114 = (*(int (__fastcall **)(_DWORD))(**(_DWORD **)(v7 + 4) + 552))(a1: *(_DWORD *)(v7 + 4));
  v115 = 0;
  memset(&v420.contacts.granularity, 0, 12);
  v116 = (const idAAS2 *)v114;
  *(float *)&v420.contactPhysicsIds.size = 0.0;
  *(float *)&v420.contactPhysicsIds.granularity = 0.0;
  v420.waterLevel = 0.0;
  v420.waterViscosity = 0.0;
  obstacleRoute_t::Clear(this: (obstacleRoute_t *)&v420.contacts.granularity);
  valueFloat = ai_cornerCircleRadius.valueFloat;
  if ( ai_cornerCircleRadius.valueFloat <= 0.0 )
    valueFloat = *(float *)(*(_DWORD *)(*(_DWORD *)(v7 + 4) + 11400) + 316);
  v386 = valueFloat;
  v118 = 16.0;
  *(float *)&v397 = 16.0;
  if ( ai_useObstacleRoute.valueInteger != 0 )
  {
    v119 = *(_DWORD *)(v7 + 4);
    LODWORD(v391) = 1300;
    if ( idAICover::IsValid(this: (idAICover *)(v119 + 58196)) )
    {
      Origin = idAICover::GetOrigin(this: (idAICover *)(*(_DWORD *)(v7 + 4) + 58196));
      v121 = *(_DWORD *)(v7 + 4);
      v122 = Origin->y;
      v123 = Origin->z;
      v404.x = Origin->x;
      v404.y = v122;
      v404.z = v123;
      v124 = idAICover::GetOrigin(this: (idAICover *)(v121 + 58196));
      if ( *(float *)(v7 + 312) != v124->x
        || *(float *)(v7 + 316) != v124->y
        || (v125 = 1, *(float *)(v7 + 320) != v124->z) )
      {
        v125 = 0;
      }
      if ( v125 != 0
        && (float)((float)((float)(v10->wallCorners[1].z - v404.z) * (float)(v10->wallCorners[1].z - v404.z))
                 + (float)((float)((float)(v10->wallCorners[1].x - v404.x) * (float)(v10->wallCorners[1].x - v404.x))
                         + (float)((float)(v10->wallCorners[1].y - v404.y) * (float)(v10->wallCorners[1].y - v404.y)))) < 16.0
        && (float)((float)((float)(v10->wallCorners[0].z - v404.z) * (float)(v10->wallCorners[0].z - v404.z))
                 + (float)((float)((float)(v10->wallCorners[0].x - v404.x) * (float)(v10->wallCorners[0].x - v404.x))
                         + (float)((float)(v10->wallCorners[0].y - v404.y) * (float)(v10->wallCorners[0].y - v404.y)))) > 16.0 )
      {
        v386 = ai_minCornerCircleRadius.valueFloat;
      }
    }
    obstacleRoute_t::operator=(this: (obstacleRoute_t *)&v420.contacts.granularity, __that: obstacleRoute);
  }
  else
  {
    v126 = *(idActor **)(v7 + 4);
    *(_DWORD *)&v420.contacts.granularity = 1;
    LODWORD(v391) = 1297;
    AASPosition = (idAASPosition *)idActor::GetAASPosition(this: v126, aas: v116);
    AreaNum = idAASPosition::GetAreaNum(this: AASPosition);
    v129 = *(float *)HIDWORD(v7);
    v130 = *(float *)(HIDWORD(v7) + 4);
    *((_DWORD *)&v420.waterViscosity + 1) = AreaNum;
    v131 = *(float *)(HIDWORD(v7) + 8);
    x = v8->x;
    v133 = v8->y;
    v134 = v8->z;
    *(float *)v420.clipModels = v129;
    *(float *)&v420.clipModels[1] = v130;
    *(float *)v420.clipMasks = v131;
    *(float *)&v420.clipMasks[1] = x;
    v420.clipModelAxis.mat[0].x = v133;
    v420.clipModelAxis.mat[0].y = v134;
  }
  v135 = idEntity::GetPhysics(this: *(idEntity **)(v7 + 4));
  v136 = (int *)v135->GetOrigin(this: v135, a2: 0);
  v137 = v136[1];
  v138 = v136[2];
  GetLinearVelocity = v135->GetLinearVelocity;
  v413.contactPhysicsIds.num = *v136;
  v413.contactPhysicsIds.size = v137;
  *(_DWORD *)&v413.contactPhysicsIds.granularity = v138;
  GetLinearVelocity(this: (idPhysics *)&v413.entityNumber, result: (idVec3 *)v135, a3: 0);
  v140 = *(float *)&v413.nextInHash;
  v141 = *(float *)&v413.entityNumber;
  v142 = *(float *)&v413.clip;
  v143 = *(float *)&v413.contactPhysicsIds.size;
  v144 = *(float *)&v413.contactPhysicsIds.num;
  if ( (float)((float)(*(float *)&v413.clip * *(float *)&v413.clip)
             + (float)((float)(*(float *)&v413.entityNumber * *(float *)&v413.entityNumber)
                     + (float)(*(float *)&v413.nextInHash * *(float *)&v413.nextInHash))) < 1.0 )
  {
    v140 = (float)(v8->y - *(float *)&v413.contactPhysicsIds.size);
    v142 = (float)(v8->z - *(float *)&v413.contactPhysicsIds.granularity);
    v141 = (float)(v8->x - *(float *)&v413.contactPhysicsIds.num);
  }
  v145 = *(idAI2 **)(v7 + 4);
  v392 = 1.5;
  _FP6 = (float)((float)((float)((float)v142 * (float)v142)
                       + (float)((float)((float)v141 * (float)v141) + (float)((float)v140 * (float)v140)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f4, f6, f7, f11 }
  v148 = __frsqrte(_FP4);
  v149 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v148
                                                                                       * (float)((float)((float)((float)v142 * (float)v142) + (float)((float)((float)v141 * (float)v141) + (float)((float)v140 * (float)v140)))
                                                                                               * (float)0.5))
                                                                               * (float)v148)
                                                                       - (float)1.5)
                                                       * (float)v148)
                                               * (float)((float)((float)((float)v142 * (float)v142)
                                                               + (float)((float)((float)v141 * (float)v141)
                                                                       + (float)((float)v140 * (float)v140)))
                                                       * (float)0.5))
                                       * (float)((float)-(float)((float)((float)((float)v148
                                                                               * (float)((float)((float)((float)v142 * (float)v142)
                                                                                               + (float)((float)((float)v141 * (float)v141) + (float)((float)v140 * (float)v140)))
                                                                                       * (float)0.5))
                                                                       * (float)v148)
                                                               - (float)1.5)
                                               * (float)v148))
                               - (float)1.5)
               * (float)((float)-(float)((float)((float)((float)v148
                                                       * (float)((float)((float)((float)v142 * (float)v142)
                                                                       + (float)((float)((float)v141 * (float)v141)
                                                                               + (float)((float)v140 * (float)v140)))
                                                               * (float)0.5))
                                               * (float)v148)
                                       - (float)1.5)
                       * (float)v148));
  v150 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v148 * (float)((float)((float)((float)v142 * (float)v142) + (float)((float)((float)v141 * (float)v141) + (float)((float)v140 * (float)v140))) * (float)0.5)) * (float)v148) - (float)1.5)
                                                                                               * (float)v148)
                                                                                       * (float)((float)((float)((float)v142 * (float)v142) + (float)((float)((float)v141 * (float)v141) + (float)((float)v140 * (float)v140)))
                                                                                               * (float)0.5))
                                                                               * (float)((float)-(float)((float)((float)((float)v148 * (float)((float)((float)((float)v142 * (float)v142) + (float)((float)((float)v141 * (float)v141) + (float)((float)v140 * (float)v140))) * (float)0.5)) * (float)v148) - (float)1.5)
                                                                                       * (float)v148))
                                                                       - (float)1.5)
                                                       * (float)((float)-(float)((float)((float)((float)v148
                                                                                               * (float)((float)((float)((float)v142 * (float)v142) + (float)((float)((float)v141 * (float)v141) + (float)((float)v140 * (float)v140))) * (float)0.5))
                                                                                       * (float)v148)
                                                                               - (float)1.5)
                                                               * (float)v148))
                                               * (float)((float)((float)((float)v142 * (float)v142)
                                                               + (float)((float)((float)v141 * (float)v141)
                                                                       + (float)((float)v140 * (float)v140)))
                                                       * (float)0.5))
                                       * (float)v149)
                               - (float)1.5)
               * (float)v149);
  *(float *)&v413.entityNumber = (float)v150 * (float)v141;
  *(float *)&v413.nextInHash = (float)v150 * (float)v140;
  *(float *)&v413.clip = (float)v150 * (float)v142;
  DefaultSpeedByCurrentWalkState = idAI2::GetDefaultSpeedByCurrentWalkState(this: v145);
  v152 = v135->__vftable;
  v409 = DefaultSpeedByCurrentWalkState;
  v153 = (float *)v152->GetGravityNormal(this: v135);
  v154 = -v153[2];
  v155 = -v153[1];
  v156 = -*v153;
  v157 = (float *)v135->GetAbsBounds(this: v135, a2: -1);
  v158 = __fabs((float)((float)(v157[5] - (float)((float)(v157[5] + v157[2]) * (float)0.5)) * (float)v154));
  v159 = __fabs((float)((float)(v157[4] - (float)((float)(v157[4] + v157[1]) * (float)0.5)) * (float)v155));
  v160 = (float)((float)((float)((float)(v157[5] + v157[2]) * (float)0.5) * (float)v154)
               + (float)((float)((float)((float)(v157[3] + *v157) * (float)0.5) * (float)v156)
                       + (float)((float)((float)(v157[4] + v157[1]) * (float)0.5) * (float)v155)));
  v161 = __fabs((float)((float)(v157[3] - (float)((float)(v157[3] + *v157) * (float)0.5)) * (float)v156));
  GetSettings = v116->GetSettings;
  v413.gravityNormal.z = (float)((float)((float)v158 + (float)v161) + (float)v159) + (float)v160;
  v385 = GetSettings(this: (idAAS2 *)v116)->maxStepHeight
       + (float)((float)v160 - (float)((float)((float)v158 + (float)v161) + (float)v159));
  LODWORD(v413.gravityVector.x) = 1024;
  idObstacleAvoidance::AllocBuffers(this: (idObstacleAvoidance *)(v7 + 852));
  VertexArray = idObstacleAvoidance::GetVertexArray(this: (idObstacleAvoidance *)(v7 + 852));
  HIDWORD(v7) = idObstacleAvoidance::GetEdgeArray(this: (idObstacleAvoidance *)(v7 + 852));
  LODWORD(v413.waterViscosity) = idObstacleAvoidance::GetMaxVertices(this: (idObstacleAvoidance *)(v7 + 852));
  v413.clipModels[0] = (idClipModel *)idObstacleAvoidance::GetMaxEdges(this: (idObstacleAvoidance *)(v7 + 852));
  v164 = (idAASPosition *)idActor::GetAASPosition(this: *(idActor **)(v7 + 4), aas: v116);
  v165.__vftable = v116->__vftable;
  v166 = idAASPosition::GetAreaNum(this: v164);
  ((void (__fastcall *)(const idAAS2 *, int, int, obstacleVertex_t *, float *, _DWORD, idClipModel **, _BYTE *))v165.GetObstaclePVSObstacles)(
    a1: v116,
    a2: v166,
    a3: 515,
    a4: VertexArray,
    a5: &v413.waterViscosity,
    a6: HIDWORD(v7),
    a7: v413.clipModels,
    a8: v439);
  idObstacleAvoidance::SetNumVertices(this: (idObstacleAvoidance *)(v7 + 852), num: SLODWORD(v413.waterViscosity));
  idObstacleAvoidance::SetNumEdges(this: (idObstacleAvoidance *)(v7 + 852), num: (int)v413.clipModels[0]);
  v167 = v413.gravityVector.x;
  v10->obstacleEntity.spawnId.value = 0x1FFF;
  v10->obstacleEntityThreshold = 0.0;
  v168 = *(_DWORD *)(v7 + 4);
  LODWORD(v412) = &v10->obstacleEntity;
  v393 = COERCE_FLOAT(&ai_debugCam);
  a = COERCE_FLOAT(&ai_debugReactionBasedMovement);
  v407 = *(_DWORD *)(v168 + 11400);
  if ( SLODWORD(v167) > 0 )
  {
    v169 = 1.1;
    v170 = 0.25;
    v171 = v439;
    v411 = 4.0;
    v405 = 3.0;
    v396 = 0.94999999;
    v401 = 150.0;
    v398 = 1.1;
    v410 = -1.0;
    v390 = 0.25;
    v406 = 1000000.0;
    while ( 1 )
    {
      v172 = *(_DWORD *)v171;
      v173 = 4 * (*(_DWORD *)(*(_DWORD *)v171 + 12) + 21563);
      v174 = *(idAI2 **)((char *)&gameLocal->__vftable + v173);
      if ( v174 != ignore )
      {
        if ( idEntity::IsBoundTo(this: *(idEntity **)((char *)&gameLocal->__vftable + v173), master: ignore) )
          goto LABEL_109;
        v175 = *(const idEntity **)(v7 + 4);
        if ( v174 == v175 )
          goto LABEL_109;
        if ( idEntity::IsBoundTo(this: v174, master: v175) )
          goto LABEL_109;
        v176 = idActor::CastTo(c: v174);
        if ( v176 != nullptr && v176->IsDead(this: v176) )
          goto LABEL_109;
        v177 = (float *)v135->GetGravityNormal(this: v135);
        v178 = v177[1];
        v179 = -v177[2];
        v415.x = -*v177;
        v415.z = v179;
        v415.y = -v178;
        idBounds::AxisProjection(
          this: (idBounds *)(v172 + 104),
          dir: &v415,
          min: (float *)&v413.collisionResidency,
          max: &v412);
        if ( v412 < (double)v385 || *(float *)&v413.collisionResidency > (double)v413.gravityNormal.z )
          goto LABEL_109;
        type = idEntity::GetPhysics(this: v174)->type;
        if ( type == PHYSICS_PLAYER )
        {
          if ( (*(_BYTE *)(*(_DWORD *)(v7 + 4) + 61225) & 0x80) == 0 )
            goto LABEL_109;
          if ( v407 != 0 && (*(_BYTE *)(v407 + 325) & 0x80) != 0 )
            goto LABEL_110;
        }
        else if ( type != PHYSICS_AI )
        {
          v192 = idDrone::CastTo(c: (idDrone *)v174);
          if ( v192 != nullptr )
          {
            v194 = *(float *)(v172 + 36);
            v195 = (_DWORD *)&v420.residencyQuery.index + 1;
            v196 = *(float *)(v172 + 40);
            v197 = (_DWORD *)(v172 + 40);
            v413.originHistory[6].x = *(float *)(v172 + 32);
            v198 = 9;
            v413.originHistory[6].y = v194;
            v413.originHistory[6].z = v196;
            do
            {
              *++v195 = *++v197;
              --v198;
            }
            while ( v198 != 0 );
            v199 = &v418;
            v200 = (_DWORD *)(v172 + 76);
            for ( i = 6; i != 0; --i )
              *++v199 = *++v200;
            idDrone::HandleObstacleAvoidance(
              this: v192,
              ai: *(const idAI2 **)(v7 + 4),
              bounds: &v419,
              origin: &v413.originHistory[6],
              otherAxis: (idMat3 *)&v420.collisionResidency);
            SpawnId = (const idSpawnId **)idGameLocal::GetSpawnId(
                                            this: (idGameLocal *)&v394,
                                            result: (idSpawnId *)gameLocal,
                                            ent: v174);
            idObstacleAvoidance::AddObstacle(
              this: (idObstacleAvoidance *)(v7 + 852),
              bounds: &v419,
              origin: &v413.originHistory[6],
              axis: (const idMat3 *)&v420.collisionResidency,
              id: *SpawnId,
              soft: v174->clipModelInfo.softObstacle);
          }
          else
          {
            v193 = (const idSpawnId **)idGameLocal::GetSpawnId(
                                         this: (idGameLocal *)&v399,
                                         result: (idSpawnId *)gameLocal,
                                         ent: v174);
            idObstacleAvoidance::AddObstacle(
              this: (idObstacleAvoidance *)(v7 + 852),
              bounds: (const idBounds *)(v172 + 80),
              origin: (const idVec3 *)(v172 + 32),
              axis: (const idMat3 *)(v172 + 44),
              id: *v193,
              soft: v174->clipModelInfo.softObstacle);
          }
          goto LABEL_110;
        }
        v382 = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 11104);
        if ( v382 == 3 || v382 == 1 && type == PHYSICS_AI || v382 == 2 && type == PHYSICS_PLAYER )
        {
          idAIMoveState::PushEntityIfClose(this: (idAIMoveState *)v7, otherEntity: (idPlayerControlled *)v174);
          goto LABEL_110;
        }
        v181 = (float)(*(float *)(v172 + 36) - (float)v143);
        v182 = (float)(*(float *)(v172 + 32) - (float)v144);
        v183 = __fsqrts((float)((float)((float)v182 * (float)v182) + (float)((float)v181 * (float)v181)));
        if ( v183 >= v406 )
          goto LABEL_109;
        v184 = (idVec3 *)idEntity::GetPhysics(this: v174);
        HIDWORD(v7) = idAI2::CastTo(c: v174);
        if ( HIDWORD(v7) != 0 )
        {
          if ( (LOWORD(v391) & 0x400) == 0 )
          {
            v203 = 0;
            idPhysics_Actor::GetVelocityHistory(this: &v413, result: v184, timeBack: 350);
            v204 = (float)(*(float *)&v413.type * (float)0.35000002);
            v205 = (float)(*((float *)&v413.__vftable + 1) * (float)0.35000002);
            v206 = (float)(*(float *)&v413.__vftable * (float)0.35000002);
            OriginHistory = (float *)idPhysics_Actor::GetOriginHistory(
                                       this: (idPhysics_Actor *)&v420.entityNumber,
                                       result: v184,
                                       timeBack: 350);
            v209 = v10->wallCorners[0].x;
            v210 = v10->wallCorners[0].y;
            v211 = (float)(OriginHistory[2] + (float)v204);
            v212 = (float)(*OriginHistory + (float)v206);
            v213 = (float)(OriginHistory[1] + (float)v205);
            v387 = *OriginHistory + (float)v206;
            v389 = v211;
            v413.originHistory[2].x = v209;
            v413.originHistory[2].y = v210;
            v388 = v213;
            v214 = *(_DWORD *)(HIDWORD(v7) + 12396);
            v215 = *(_DWORD *)(HIDWORD(v7) + 12388);
            v216 = v10->wallCorners[0].z;
            v217 = *(_DWORD *)(HIDWORD(v7) + 12392);
            v218 = (float)((float)v211 - *(float *)&v413.contactPhysicsIds.granularity);
            v413.originHistory[1].y = 0.0;
            v219 = (float)((float)v212 - (float)v144);
            *(float *)&v413.wasHistoryInitialized = (float)v212 - (float)v144;
            v220 = (float)((float)v213 - (float)v143);
            v413.originHistory[0].x = (float)v211 - *(float *)&v413.contactPhysicsIds.granularity;
            *(float *)&v413.lastHistorySaveTime = (float)v213 - (float)v143;
            v221 = 0;
            v413.originHistory[2].z = v216;
            v413.contacts.size = v217;
            v413.contacts.num = v215;
            v222 = (float)(v210 - (float)v143);
            v413.originHistory[1].x = v210 - (float)v143;
            v223 = (float)(v209 - (float)v144);
            v413.originHistory[0].z = v209 - (float)v144;
            *(_DWORD *)&v413.contacts.granularity = v214;
            if ( (float)((float)(*(float *)&v413.__vftable * *(float *)&v413.__vftable)
                       + (float)((float)(*((float *)&v413.__vftable + 1) * *((float *)&v413.__vftable + 1))
                               + (float)(*(float *)&v413.type * *(float *)&v413.type))) <= 0.1 )
              goto LABEL_91;
            v224 = *(_DWORD *)(LODWORD(a) + 32);
            if ( v224 > 0 )
            {
              if ( v224 == 2 )
                goto LABEL_59;
              if ( *(_DWORD *)(LODWORD(v393) + 32) != 0 )
              {
                if ( *(idEntity **)(v7 + 4) == idGameLocal::GetDebugEntity(this: gameLocal) )
                {
LABEL_59:
                  v225 = *(float *)(v7 + 316);
                  v226 = *(float *)(v7 + 320);
                  v227 = *(idEntity **)(v7 + 4);
                  v413.originHistory[15].y = *(float *)(v7 + 312);
                  v413.originHistory[15].z = v225;
                  v413.yawHistory[0] = v226;
                  v228 = idEntity::GetPhysics(this: v227);
                  v229 = (int)v228->GetOrigin(this: v228, a2: 0);
                  (*(void (__fastcall **)(_DWORD, _DWORD, int, idVec3 *, double))(**(_DWORD **)(*(_DWORD *)(v14 + 17592)
                                                                                              + 4)
                                                                                + 180))(
                    a1: *(_DWORD *)(*(_DWORD *)(v14 + 17592) + 4),
                    a2: *((_DWORD *)&v413.collisionResidency + 1),
                    a3: v229,
                    a4: v10->wallCorners,
                    a5: v118);
                  (*(void (__fastcall **)(_DWORD, _DWORD, idVec3 *, idVec3 *, double))(**(_DWORD **)(*(_DWORD *)(v14 + 17592) + 4)
                                                                                     + 180))(
                    a1: *(_DWORD *)(*(_DWORD *)(v14 + 17592) + 4),
                    a2: *((_DWORD *)&v413.waterViscosity + 1),
                    a3: v10->wallCorners,
                    a4: &v10->wallCorners[1],
                    a5: v118);
                  (*(void (__fastcall **)(_DWORD, double, idVec3 *, float *, double))(**(_DWORD **)(*(_DWORD *)(v14 + 17592)
                                                                                                  + 4)
                                                                                    + 180))(
                    a1: *(_DWORD *)(*(_DWORD *)(v14 + 17592) + 4),
                    a2: COERCE_DOUBLE(LODWORD(z)),
                    a3: &v10->wallCorners[1],
                    a4: &v413.originHistory[15].y,
                    a5: v118);
                }
                v212 = v387;
                v213 = v388;
              }
            }
            v383 = *(_DWORD *)(HIDWORD(v7) + 11104);
            if ( v383 == 1 || v383 == 3 )
              goto LABEL_73;
            v230 = *(float *)(HIDWORD(v7) + 12388);
            v231 = *(_DWORD *)(v7 + 4);
            v232 = *(_DWORD *)(HIDWORD(v7) + 492);
            v233 = *(float *)(HIDWORD(v7) + 12396);
            v413.originHistory[5].x = *(float *)(HIDWORD(v7) + 12392);
            v413.originHistory[4].z = v230;
            v234 = *(_DWORD *)(v231 + 492);
            v207 = v234 - v232;
            v413.originHistory[5].y = v233;
            v203 = ((((v232 ^ v234) & 0x80000000) == 0) + (v234 >= v232)) & 1;
            v235 = __fsqrts((float)((float)((float)v223 * (float)v223) + (float)((float)v222 * (float)v222)));
            v236 = (float)(v413.originHistory[5].x - (float)v213);
            v237 = (float)(v230 - (float)v212);
            v238 = __fsqrts((float)((float)((float)v237 * (float)v237) + (float)((float)v236 * (float)v236)));
            if ( v235 <= 0.1 || v238 <= 0.1 )
              goto LABEL_74;
            GameMs = idGameTimeManager::GetGameMs(
                       this: (idGameTimeManager *)(*(_DWORD *)(v14 + 17592) + 504064),
                       type: GAMETIME_SCALED);
            frustrationOverTime = v10->frustrationOverTime;
            if ( GameMs < frustrationOverTime && frustrationOverTime < *(_DWORD *)(HIDWORD(v7) + 12436) )
            {
              v203 = 1;
              goto LABEL_74;
            }
            v241 = idGameTimeManager::GetGameMs(
                     this: (idGameTimeManager *)(*(_DWORD *)(v14 + 17592) + 504064),
                     type: GAMETIME_SCALED);
            v242 = *(_DWORD *)(HIDWORD(v7) + 12436);
            if ( v241 < v242 && v242 < v10->frustrationOverTime )
              goto LABEL_73;
            v243 = (float)((float)((float)((float)((float)v223 * (float)v219) + (float)((float)v220 * (float)v222))
                                 + (float)((float)v218 * (float)0.0))
                         / (float)v235);
            v244 = (float)((float)((float)((float)((float)((float)v237 * (float)v219)
                                                 + (float)((float)v236 * (float)v220))
                                         + (float)((float)v218 * (float)0.0))
                                 / (float)v238)
                         * v410);
            if ( v243 < v244 )
            {
              v203 = 1;
              goto LABEL_74;
            }
            if ( v243 > v244 )
LABEL_73:
              v203 = 0;
LABEL_74:
            v245 = (float *)(*(int (__fastcall **)(idVec3 *, _DWORD, unsigned int))(LODWORD(v184->x) + 64))(
                              a1: v184,
                              a2: 0,
                              a3: v207);
            v387 = *v245;
            v388 = v245[1];
            v389 = v245[2];
            v246 = idAI2::GetDefaultSpeedByCurrentWalkState(this: (idAI2 *)HIDWORD(v7));
            idVec3::Truncate(this: (idVec3 *)&v413, length: v246);
            v247 = v387;
            v248 = v389;
            v249 = v388;
            v250 = (float)((float)v183 / (float)((float)v246 + v409));
            if ( v203 != 0 )
            {
              v251 = (float)((float)((float)((float)v183 / (float)((float)v246 + v409)) * *(float *)&v413.__vftable)
                           * (float)0.5);
              v252 = (float)((float)(*(float *)&v413.type * (float)((float)v183 / (float)((float)v246 + v409)))
                           * (float)0.5);
              v253 = (float)((float)(*((float *)&v413.__vftable + 1) * (float)((float)v183 / (float)((float)v246 + v409)))
                           * (float)0.5);
            }
            else
            {
              v251 = (float)((float)((float)((float)v183 / (float)((float)v246 + v409)) * *(float *)&v413.__vftable)
                           * (float)v169);
              v252 = (float)((float)(*(float *)&v413.type * (float)((float)v183 / (float)((float)v246 + v409)))
                           * (float)v169);
              v253 = (float)((float)(*((float *)&v413.__vftable + 1) * (float)((float)v183 / (float)((float)v246 + v409)))
                           * (float)v169);
            }
            v213 = (float)(v388 + (float)v253);
            v388 = v388 + (float)v253;
            v211 = (float)(v389 + (float)v252);
            v389 = v389 + (float)v252;
            v212 = (float)(v387 + (float)v251);
            v387 = v387 + (float)v251;
            if ( v203 != 0 )
            {
LABEL_91:
              v258 = *(float *)&v413.contacts.granularity;
              v254 = *(float *)&v413.contacts.size;
              v256 = *(float *)&v413.contacts.num;
            }
            else
            {
              v254 = *(float *)&v413.contacts.size;
              v255 = (float)(*(float *)&v413.contacts.size - (float)((float)v249 + (float)v253));
              v256 = *(float *)&v413.contacts.num;
              v257 = (float)(*(float *)&v413.contacts.num - (float)((float)v247 + (float)v251));
              v258 = *(float *)&v413.contacts.granularity;
              v259 = (float)(*(float *)&v413.contacts.granularity - (float)((float)v248 + (float)v252));
              v260 = (float)((float)v250 * v401);
              v261 = __fsqrts((float)((float)((float)v259 * (float)v259)
                                    + (float)((float)((float)v257 * (float)v257) + (float)((float)v255 * (float)v255))));
              v262 = idEntity::GetPhysics(this: *(idEntity **)(v7 + 4));
              v263 = (float *)v262->GetOrigin(this: v262, a2: 0);
              v264 = v10->wallCorners[0].y;
              v265 = v10->wallCorners[0].x;
              v266 = v263[1];
              v267 = *v263;
              v413.clipModelAxis.mat[2].z = v10->wallCorners[0].z - v263[2];
              v413.clipModelAxis.mat[2].y = (float)v264 - (float)v266;
              v413.clipModelAxis.mat[2].x = (float)v265 - (float)v267;
              idVec3::NormalizeFast(this: &v413.clipModelAxis.mat[2]);
              if ( (float)((float)(*(float *)&v413.entityNumber * v413.clipModelAxis.mat[2].x)
                         + (float)((float)(v413.clipModelAxis.mat[2].y * *(float *)&v413.nextInHash)
                                 + (float)(v413.clipModelAxis.mat[2].z * *(float *)&v413.clip))) < (double)v396 )
                v260 = (float)((float)((float)((float)(v396
                                                     - (float)((float)(*(float *)&v413.entityNumber
                                                                     * v413.clipModelAxis.mat[2].x)
                                                             + (float)((float)(v413.clipModelAxis.mat[2].y
                                                                             * *(float *)&v413.nextInHash)
                                                                     + (float)(v413.clipModelAxis.mat[2].z
                                                                             * *(float *)&v413.clip))))
                                             * v405)
                                     + (float)1.0)
                             * (float)v260);
              v211 = v389;
              v213 = v388;
              v212 = v387;
              if ( v261 > v260 )
              {
                v258 = (float)((float)(v389 * (float)((float)1.0 - (float)((float)v260 / (float)v261)))
                             + (float)((float)v258 * (float)((float)v260 / (float)v261)));
                v254 = (float)((float)(v388 * (float)((float)1.0 - (float)((float)v260 / (float)v261)))
                             + (float)((float)v254 * (float)((float)v260 / (float)v261)));
                v256 = (float)((float)(v387 * (float)((float)1.0 - (float)((float)v260 / (float)v261)))
                             + (float)((float)v256 * (float)((float)v260 / (float)v261)));
              }
              if ( v183 < v401 )
              {
                v221 = 1;
                if ( *(_BYTE *)(*(_DWORD *)(v7 + 4) + 13954) != 0 )
                {
                  if ( idGameTimeManager::GetGameMs(
                         this: (idGameTimeManager *)(*(_DWORD *)(v14 + 17592) + 504064),
                         type: GAMETIME_SCALED) < v10->updatedTime )
                    goto LABEL_90;
                  if ( (float)((float)(*(float *)&v413.entityNumber * (float)v219)
                             + (float)((float)(*(float *)&v413.nextInHash * (float)v220)
                                     + (float)(*(float *)&v413.clip * (float)v218))) <= 0.0 )
                    goto LABEL_90;
                  v413.invMass = *(float *)&v413.wasHistoryInitialized;
                  *(_DWORD *)&v413.hasMaster = v413.lastHistorySaveTime;
                  v413.masterYaw = v413.originHistory[0].x;
                  v413.clipModelAxis.mat[0].z = v413.originHistory[0].z;
                  v413.clipModelAxis.mat[1].x = v413.originHistory[1].x;
                  v413.clipModelAxis.mat[1].y = v413.originHistory[1].y;
                  v268 = idVec3::NormalizeFast(this: (idVec3 *)&v413.invMass);
                  idVec3::NormalizeFast(this: (idVec3 *)&v413.clipModelAxis.mat[0].z);
                  y_low = LODWORD(v10->newDest.y);
                  v413.clipMasks[0] = LODWORD(v10->newDest.x);
                  v413.clipModelAxis.mat[0].x = 0.0;
                  v413.clipMasks[1] = y_low;
                  idVec3::NormalizeFast(this: (idVec3 *)v413.clipMasks);
                  if ( (float)((float)(v413.clipModelAxis.mat[0].z * *(float *)v413.clipMasks)
                             + (float)((float)(*(float *)&v413.clipMasks[1] * v413.clipModelAxis.mat[1].x)
                                     + (float)(v413.clipModelAxis.mat[1].y * v413.clipModelAxis.mat[0].x))) >= (double)(float)((float)(v413.invMass * *(float *)v413.clipMasks) + (float)((float)(*(float *)&v413.hasMaster * *(float *)&v413.clipMasks[1]) + (float)(v413.masterYaw * v413.clipModelAxis.mat[0].x)))
                    || v268 <= 0.1
                    || (v270 = (float)((float)((float)(v413.invMass * v413.clipModelAxis.mat[0].z)
                                             + (float)((float)(*(float *)&v413.hasMaster * v413.clipModelAxis.mat[1].x)
                                                     + (float)(v413.masterYaw * v413.clipModelAxis.mat[1].y)))
                                     / (float)v268)) <= v10->obstacleEntityThreshold )
                  {
LABEL_90:
                    v211 = v389;
                    v213 = v388;
                    v212 = v387;
                  }
                  else
                  {
                    v211 = v389;
                    v213 = v388;
                    v212 = v387;
                    v10->obstacleEntity.spawnId.value = (gameLocal->spawnIds.ptr[*(_DWORD *)(HIDWORD(v7) + 492)] << 13)
                                                      | *(_DWORD *)(HIDWORD(v7) + 492);
                    v10->obstacleEntityThreshold = v270;
                  }
                }
              }
            }
            if ( v221 == 0 )
            {
              v271 = *(float *)(HIDWORD(v7) + 12388);
              v404.z = 0.0;
              v272 = *(float *)(HIDWORD(v7) + 12396);
              v413.originHistory[3].z = *(float *)(HIDWORD(v7) + 12392);
              v413.originHistory[3].y = v271;
              v404.y = v413.originHistory[3].z - (float)v213;
              v413.originHistory[4].x = v272;
              v404.x = v271 - (float)v212;
              if ( idVec3::NormalizeFast(this: &v404) <= 0.1 )
              {
                v256 = v212;
                v254 = v213;
                v258 = v211;
              }
              else
              {
                v258 = (float)((float)v211 + (float)(v404.z * v411));
                v254 = (float)((float)v213 + (float)(v404.y * v411));
                v256 = (float)((float)v212 + (float)(v404.x * v411));
              }
            }
            v413.originHistory[8].x = 0.0;
            v413.originHistory[7].y = (float)v256 - (float)v212;
            v413.originHistory[7].z = (float)v254 - (float)v213;
            if ( idVec3::NormalizeFast(this: (idVec3 *)&v413.originHistory[7].y) <= (double)idMath::FLT_SMALLEST_NON_DENORMAL )
            {
              v282 = 1.0;
              v278 = 1.0;
              v274 = 1.0;
              v279 = 0.0;
              v276 = 0.0;
              v275 = 0.0;
              v281 = 0.0;
              v280 = 0.0;
              v277 = 0.0;
            }
            else
            {
              v273 = (float *)idVec3::ToMat3(this: v438, result: (idMat3 *)&v413.originHistory[7].y);
              v211 = v389;
              v213 = v388;
              v212 = v387;
              v274 = *v273;
              v275 = v273[1];
              v276 = v273[2];
              v277 = v273[3];
              v278 = v273[4];
              v279 = v273[5];
              v280 = v273[6];
              v281 = v273[7];
              v282 = v273[8];
            }
            v283 = *(float *)(HIDWORD(v7) + 10344);
            v284 = __fsqrts((float)((float)((float)((float)v256 - (float)v212) * (float)((float)v256 - (float)v212))
                                  + (float)((float)((float)v254 - (float)v213) * (float)((float)v254 - (float)v213))));
            if ( v203 == 0 )
              v283 = (float)(*(float *)(HIDWORD(v7) + 10344) * v392);
            v413.originHistory[8].z = (float)((float)v256 + (float)v212) * (float)0.5;
            v413.originHistory[9].x = (float)((float)v254 + (float)v213) * (float)0.5;
            v413.originHistory[9].y = (float)((float)v258 + (float)v211) * (float)0.5;
            v413.originHistory[10].x = v283;
            v413.originHistory[10].y = v283;
            v413.originHistory[10].z = v274;
            v413.originHistory[11].x = v275;
            v413.originHistory[11].y = v276;
            v413.originHistory[11].z = v277;
            v413.originHistory[12].x = v278;
            v413.originHistory[12].y = v279;
            v413.originHistory[12].z = v280;
            v413.originHistory[13].x = v281;
            v413.originHistory[13].y = v282;
            v413.originHistory[9].z = (float)((float)v284 * (float)0.5) + (float)v283;
            v285 = (const idSpawnId **)idGameLocal::GetSpawnId(
                                         this: (idGameLocal *)&v402,
                                         result: (idSpawnId *)gameLocal,
                                         ent: v174);
            idObstacleAvoidance::AddObstacle(
              this: (idObstacleAvoidance *)(v7 + 852),
              box: (const idBox *)&v413.originHistory[8].z,
              id: *v285,
              soft: v174->clipModelInfo.softObstacle);
            v286 = *(_DWORD *)(LODWORD(a) + 32);
            if ( v286 > 0
              && (v286 > 1
               || *(_DWORD *)(LODWORD(v393) + 32) != 0
               && *(idEntity **)(v7 + 4) == idGameLocal::GetDebugEntity(this: gameLocal)) )
            {
              v287 = *(_DWORD *)(v14 + 17592);
              v413.originHistory[9].z = v413.originHistory[9].z + (float)v283;
              v413.originHistory[10].x = v413.originHistory[10].x + (float)v283;
              v413.originHistory[10].y = v413.originHistory[10].y + (float)v283;
              (*(void (__fastcall **)(_DWORD, double, float *, int, int))(**(_DWORD **)(v287 + 4) + 228))(
                a1: *(_DWORD *)(v287 + 4),
                a2: COERCE_DOUBLE(LODWORD(z)),
                a3: &v413.originHistory[8].z,
                a4: v221 == 0 ? 16 : 250,
                a5: 1);
              v289 = v203 != 0;
              v288 = *((float *)&v413.collisionResidency + 1);
              if ( !v289 )
                v288 = z;
              v290 = idEntity::GetPhysics(this: *(idEntity **)(v7 + 4));
              v291 = (int)v290->GetOrigin(this: v290, a2: 0);
              (*(void (__fastcall **)(_DWORD, double, int, float *, double))(**(_DWORD **)(*(_DWORD *)(v14 + 17592) + 4)
                                                                           + 180))(
                a1: *(_DWORD *)(*(_DWORD *)(v14 + 17592) + 4),
                a2: COERCE_DOUBLE(LODWORD(v288)),
                a3: v291,
                a4: &v387,
                a5: *(float *)&v413.clipMask);
              if ( *(_DWORD *)(LODWORD(a) + 32) == 1 )
              {
                v292 = idEntity::GetPhysics(this: (idEntity *)HIDWORD(v7));
                v293 = (int)v292->GetOrigin(this: v292, a2: 0);
                (*(void (__fastcall **)(_DWORD, int *, float *, int, double))(**(_DWORD **)(*(_DWORD *)(v14 + 17592) + 4)
                                                                            + 180))(
                  a1: *(_DWORD *)(*(_DWORD *)(v14 + 17592) + 4),
                  a2: v413.contactPhysicsIds.list,
                  a3: &v387,
                  a4: v293,
                  a5: *(float *)&v413.clipMask);
              }
            }
          }
LABEL_109:
          v170 = v390;
          v169 = v398;
          v144 = *(float *)&v413.contactPhysicsIds.num;
          v118 = *(float *)&v397;
          goto LABEL_110;
        }
        idPhysics_Actor::GetVelocityHistory(
          this: (idPhysics_Actor *)&v413.originHistory[14],
          result: v184,
          timeBack: 250);
        v185 = (float)(v413.originHistory[14].z * (float)v170);
        v186 = (float)(v413.originHistory[14].y * (float)v170);
        v187 = (float)(v413.originHistory[14].x * (float)v170);
        v188 = (float *)idPhysics_Actor::GetOriginHistory(this: &v420, result: v184, timeBack: 250);
        v189 = (float)(v188[2] + (float)v185);
        v190 = (float)(v188[1] + (float)v186);
        v417.x = *v188 + (float)v187;
        v417.z = v189;
        v417.y = v190;
        v191 = (const idSpawnId **)idGameLocal::GetSpawnId(
                                     this: (idGameLocal *)&v395,
                                     result: (idSpawnId *)gameLocal,
                                     ent: v174);
        idObstacleAvoidance::AddObstacle(
          this: (idObstacleAvoidance *)(v7 + 852),
          bounds: (const idBounds *)(v172 + 80),
          origin: &v417,
          axis: (const idMat3 *)(v172 + 44),
          id: *v191,
          soft: v174->clipModelInfo.softObstacle);
      }
LABEL_110:
      ++v115;
      v171 += 4;
      if ( v115 >= SLODWORD(v413.gravityVector.x) )
      {
        v13 = *(float *)&v413.clipMask;
        break;
      }
    }
  }
  obstaclePath_t::obstaclePath_t(this: (obstaclePath_t *)&v420.yawHistory[8]);
  v294 = (*(int (__fastcall **)(_DWORD))(**(_DWORD **)(v7 + 4) + 552))(a1: *(_DWORD *)(v7 + 4));
  v295 = idEntity::GetPhysics(this: *(idEntity **)(v7 + 4));
  v296 = *(float *)(*(_DWORD *)(v7 + 4) + 10564);
  v297 = (const idVec3 *)((*(int (__fastcall **)(int))(*(_DWORD *)v294 + 20))(a1: v294) + 136);
  v298 = v295->GetBounds(this: v295, a2: -1);
  HIDWORD(v7) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
  v299 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  PathAroundObstacles = idObstacleAvoidance::FindPathAroundObstacles(
                          this: (idObstacleAvoidance *)(v7 + 852),
                          path: (obstaclePath_t *)&v420.yawHistory[8],
                          time: v299,
                          gameMsPerFrame: SHIDWORD(v7),
                          bbox: v298,
                          gravity: v297,
                          obstacleRadius: v296,
                          frameMoveDist: v118,
                          cornerCircleRadius: v386,
                          flags: 0,
                          route: (const obstacleRoute_t *)&v420.contacts.granularity,
                          traceSet: v359,
                          a13: v360,
                          a14: v361,
                          a15: v362,
                          a16: v363,
                          a17: v364,
                          a18: v365,
                          a19: v366,
                          a20: v367,
                          a21: v368,
                          a22: v369,
                          a23: v370,
                          a24: v371,
                          a25: v372,
                          a26: v373,
                          a27: v374,
                          a28: v375,
                          a29: v376,
                          a30: v377,
                          a31: (int)&v413.gravityVector,
                          a32: v378,
                          a33: SLODWORD(v391),
                          a34: v379,
                          a35: (const obstacleRoute_t *)&v420.contacts.granularity,
                          a36: v380,
                          a37: nullptr);
  v10->startPos.x = startPos->x;
  v10->startPos.y = startPos->y;
  v10->startPos.z = startPos->z;
  v10->endPos.x = destination->x;
  v10->endPos.y = destination->y;
  v10->endPos.z = destination->z;
  if ( ignore != nullptr )
    v10->ignore.spawnId.value = (gameLocal->spawnIds.ptr[ignore->entityNumber] << 13) | ignore->entityNumber;
  else
    v10->ignore.spawnId.value = 0x1FFF;
  v301 = v433;
  v302 = v434;
  v303 = v437;
  v304 = v435;
  v10->wallCorners[0].x = v432;
  v10->wallCorners[0].y = v301;
  v10->wallCorners[0].z = v302;
  v10->wallCorners[1].z = v303;
  v10->wallCorners[1].x = v304;
  v10->wallCorners[1].y = v436;
  if ( ai_debugMove.valueInteger != 0 && ai_debugLevel.valueInteger > 0 )
  {
    v305 = *(int **)(*(_DWORD *)(v14 + 17592) + 4);
    v306 = *v305;
    v307 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    (*(void (__fastcall **)(int *, _DWORD, const idVec3 *, int, _DWORD))(v306 + 256))(
      a1: v305,
      a2: LODWORD(v413.masterDeltaYaw),
      a3: startPos,
      a4: v307,
      a5: 0);
    v308 = *(int **)(*(_DWORD *)(v14 + 17592) + 4);
    v309 = *v308;
    v310 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    (*(void (__fastcall **)(int *, _DWORD, float *, int, _DWORD))(v309 + 256))(
      a1: v308,
      a2: LODWORD(v413.waterLevel),
      a3: &v420.yawHistory[8],
      a4: v310,
      a5: 0);
    v311 = *(int **)(*(_DWORD *)(v14 + 17592) + 4);
    v312 = *v311;
    v313 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    (*(void (__fastcall **)(int *, _DWORD, float *, int, _DWORD))(v312 + 256))(
      a1: v311,
      a2: HIDWORD(v400),
      a3: &v420.yawHistory[11],
      a4: v313,
      a5: 0);
  }
  v314 = gameLocal->GetEntityForSpawnId_2(this: gameLocal, a2: v425);
  if ( v314 != nullptr )
  {
    HIDWORD(v400) = v314->entityNumber;
    v10->firstObstacle.spawnId.value = (gameLocal->spawnIds.ptr[HIDWORD(v400)] << 13) | HIDWORD(v400);
  }
  else
  {
    v10->firstObstacle.spawnId.value = 0x1FFF;
  }
  v315 = gameLocal->GetEntityForSpawnId_2(this: gameLocal, a2: v426);
  if ( v315 != nullptr )
  {
    HIDWORD(v400) = v315->entityNumber;
    v10->startObstacle.spawnId.value = (gameLocal->spawnIds.ptr[HIDWORD(v400)] << 13) | HIDWORD(v400);
  }
  else
  {
    v10->startObstacle.spawnId.value = 0x1FFF;
  }
  v316 = gameLocal->GetEntityForSpawnId_2(this: gameLocal, a2: v430);
  p_endObstacle = &v10->endObstacle;
  if ( v316 != nullptr )
  {
    HIDWORD(v400) = v316->entityNumber;
    p_endObstacle->spawnId.value = (gameLocal->spawnIds.ptr[HIDWORD(v400)] << 13) | HIDWORD(v400);
  }
  else
  {
    p_endObstacle->spawnId.value = 0x1FFF;
  }
  v10->length = v431;
  v318 = (float)((float)((float)(v423 * startPos->z) + (float)((float)(startPos->y * v422) + (float)(startPos->x * v421)))
               + v424);
  v319 = gameLocal;
  HIDWORD(v400) = &v10->newDest;
  v320 = &v420.yawHistory[3 * (v318 > -0.0099999998) + 8];
  v321 = *v320;
  v322 = v320[1];
  v323 = v320[2];
  newPos->x = *v320;
  newPos->y = v322;
  newPos->z = v323;
  v10->newDest.x = v321;
  v10->newDest.y = newPos->y;
  v10->newDest.z = newPos->z;
  value = p_endObstacle->spawnId.value;
  if ( v319->spawnIds.ptr[p_endObstacle->spawnId.value & 0x1FFF] == p_endObstacle->spawnId.value >> 13 )
  {
    HIDWORD(v400) = &v10->endObstacle;
    if ( v319->spawnIds.ptr[value & 0x1FFF] == value >> 13 && (v325 = v319->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v326 = idEntity::CastTo(c: v325);
      v319 = gameLocal;
      v327 = v326;
    }
    else
    {
      v327 = nullptr;
    }
    v328 = *(_DWORD *)(v7 + 40);
    HIDWORD(v329) = 4 * ((v328 & 0x1FFF) + 29755);
    HIDWORD(v400) = v7 + 40;
    if ( *(idGameLocal_vtbl **)((char *)&v319->__vftable + HIDWORD(v329)) == (idGameLocal_vtbl *)(v328 >> 13)
      && (v330 = v319->entities.ptr[v328 & 0x1FFF]) != nullptr )
    {
      v331 = idEntity::CastTo(c: v330);
      v319 = gameLocal;
    }
    else
    {
      v331 = nullptr;
    }
    if ( v327 != v331 )
    {
      v332 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v7 + 4) + 11400) + 1028);
      LODWORD(v329) = v332 * v332;
      v333 = (float)((float)((float)(v429 - startPos->z) * (float)(v429 - startPos->z))
                   + (float)((float)((float)(v427 - startPos->x) * (float)(v427 - startPos->x))
                           + (float)((float)(v428 - startPos->y) * (float)(v428 - startPos->y))));
      v400 = v329;
      if ( v333 < (float)v329 )
      {
        idPLogScope::~idPLogScope(this: (idPLogScope *)&v413.gravityNormal);
        RD_EventEnd();
        return 0;
      }
    }
  }
  if ( PathAroundObstacles )
  {
    v340 = *(_DWORD *)(LODWORD(a) + 32);
    if ( v340 > 1
      || v340 == 1
      && *(_DWORD *)(LODWORD(v393) + 32) != 0
      && *(idEntity **)(v7 + 4) == idGameLocal::GetDebugEntity(this: v319) )
    {
      v341 = idEntity::GetPhysics(this: *(idEntity **)(v7 + 4));
      v342 = (int)v341->GetOrigin(this: v341, a2: 0);
      (*(void (__fastcall **)(_DWORD, _DWORD, int, idVec3 *, double))(**(_DWORD **)(*(_DWORD *)(v14 + 17592) + 4) + 180))(
        a1: *(_DWORD *)(*(_DWORD *)(v14 + 17592) + 4),
        a2: LODWORD(v413.originHistory[0].y),
        a3: v342,
        a4: &v10->newDest,
        a5: v13);
      v343 = idEntity::GetPhysics(this: *(idEntity **)(v7 + 4));
      v343->GetLinearVelocity(this: (idPhysics_Actor *)&v413.yawHistory[6], result: (idVec3 *)v343, a3: 0);
      v344 = idEntity::GetPhysics(this: *(idEntity **)(v7 + 4));
      v345 = (float *)v344->GetOrigin(this: v344, a2: 0);
      v347 = (float)(v345[2] + v413.yawHistory[8]);
      v348 = (float)(v345[1] + v413.yawHistory[7]);
      v349 = (float)(*v345 + v413.yawHistory[6]);
      v346 = *(idEntity **)(v7 + 4);
      v413.yawHistory[14] = v349;
      v414 = v347;
      v413.yawHistory[15] = v348;
      v350 = idEntity::GetPhysics(this: v346);
      v351 = (int)v350->GetOrigin(this: v350, a2: 0);
      (*(void (__fastcall **)(_DWORD, _DWORD, int, float *, double))(**(_DWORD **)(*(_DWORD *)(v14 + 17592) + 4) + 180))(
        a1: *(_DWORD *)(*(_DWORD *)(v14 + 17592) + 4),
        a2: *((_DWORD *)&v413.collisionResidency + 1),
        a3: v351,
        a4: &v413.yawHistory[14],
        a5: v13);
      v352 = idEntity::GetPhysics(this: *(idEntity **)(v7 + 4));
      v353 = (int)v352->GetOrigin(this: v352, a2: 0);
      (*(void (__fastcall **)(_DWORD, _DWORD, int, idVec3 *, double))(**(_DWORD **)(*(_DWORD *)(v14 + 17592) + 4) + 180))(
        a1: *(_DWORD *)(*(_DWORD *)(v14 + 17592) + 4),
        a2: *((_DWORD *)&v413.waterViscosity + 1),
        a3: v353,
        a4: v10->wallCorners,
        a5: v13);
    }
    if ( v413.gravityNormal.x >= 0.0 )
    {
      v354 = v413.gravityNormal.y;
      v355 = *(_DWORD *)(LODWORD(v413.gravityNormal.y) + 16) + 16 * LODWORD(v413.gravityNormal.x);
      v356 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v357 = *(_QWORD *)(v355 + 8);
      HIDWORD(v357) = *(_DWORD *)(v355 + 4);
      LODWORD(v358) = v356 - v357;
      *(_QWORD *)(v355 + 8) = v358;
      *(_DWORD *)(LODWORD(v354) + 32) = HIDWORD(v357);
    }
    goto LABEL_151;
  }
  if ( v413.gravityNormal.x >= 0.0 )
  {
    v335 = v413.gravityNormal.y;
    v336 = *(_DWORD *)(LODWORD(v413.gravityNormal.y) + 16) + 16 * LODWORD(v413.gravityNormal.x);
    v337 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v338 = *(_QWORD *)(v336 + 8);
    HIDWORD(v338) = *(_DWORD *)(v336 + 4);
    LODWORD(v339) = v337 - v338;
    *(_QWORD *)(v336 + 8) = v339;
    *(_DWORD *)(LODWORD(v335) + 32) = HIDWORD(v338);
  }
  RD_EventEnd();
  return 0;
}


// ========================================================================
// __unwind$498515
// EA  : 0x82A5C670
// RVA : 0x00A5C670
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void _unwind_498515()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 6288 + 5984));
}


// ========================================================================
// __unwind$498516
// EA  : 0x82A5C698
// RVA : 0x00A5C698
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void _unwind_498516()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 6288 + 320));
}


// ========================================================================
// ?InternalTestMoveToPoint@idAIMoveState@@ABA?AW4aiMoveStatus_t@@ABVidAIMoveParms@@AAVidVec3@@11AAH2AAUidAAS2Path@@@Z
// EA  : 0x82A5C740
// RVA : 0x00A5C740
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

int __fastcall idAIMoveState::InternalTestMoveToPoint(
        idAIMoveState *this,
        const idAIMoveParms *parms,
        idVec3 *aasStartingPoint,
        idVec3 *aasFinalPoint,
        idVec3 *nextPoint,
        int *totalTravelTime,
        int *startAreaNum,
        idAAS2Path *localPath)
{
  unsigned __int64 v16; // r6
  const char *v17; // r7
  idPhysics *Physics; // r3
  const idVec3 *v19; // r27
  const aiPhysicalState_t *RelevantGoalOrigin; // r3
  float y; // r6
  float z; // r5
  double x; // fp0
  const idAAS2 *v24; // r26
  const idAAS2 *v25; // r22
  const idAAS2 *v27; // r4
  idPLogScope v28; // [sp+58h] [-88h] BYREF
  idVec3 v29; // [sp+60h] [-80h] BYREF

  RD_EventBegin(name: "idAIMoveState::InternalTestMoveToPoint");
  LODWORD(v16) = "idAIMoveState::InternalTestMoveToPoint";
  HIDWORD(v16) = 6;
  idPLogScope::idPLogScope(this: &v28, pl: &pLog, gMask: v16, label: v17);
  Physics = idEntity::GetPhysics(this: this->ai);
  v19 = Physics->GetOrigin(this: Physics, a2: 0);
  RelevantGoalOrigin = idAIMoveParms::GetRelevantGoalOrigin(this: parms, ai: this->ai);
  y = RelevantGoalOrigin->origin.y;
  z = RelevantGoalOrigin->origin.z;
  v29.x = RelevantGoalOrigin->origin.x;
  x = v29.x;
  v29.y = y;
  v29.z = z;
  *aasStartingPoint = *v19;
  aasFinalPoint->x = x;
  aasFinalPoint->y = y;
  aasFinalPoint->z = z;
  nextPoint->x = x;
  nextPoint->y = y;
  nextPoint->z = z;
  *startAreaNum = 0;
  *totalTravelTime = 0;
  v24 = this->ai->GetAAS(this: this->ai);
  if ( v24 == nullptr || ai_testPaths.valueInteger != 0 )
  {
    idPLogScope::~idPLogScope(this: &v28);
    RD_EventEnd();
    return 3;
  }
  else
  {
    v25 = idAIMoveState::PointReachableAreaNum(this, point: &v29, boundsScale: 1.0);
    if ( v25 != nullptr )
    {
      v27 = idAIMoveState::PointReachableAreaNum(this, point: v19, boundsScale: 1.0);
      *startAreaNum = (int)v27;
      if ( v27 != nullptr )
      {
        v24->PushPointIntoAreaNum(this: (idAAS2 *)v24, a2: (int)v27, a3: aasStartingPoint);
        v24->PushPointIntoAreaNum(this: (idAAS2 *)v24, a2: (int)v25, a3: aasFinalPoint);
        if ( this->ReachedPoint(this, a2: aasFinalPoint, a3: this->moveParms.goalTolerance) )
        {
          idPLogScope::~idPLogScope(this: &v28);
          RD_EventEnd();
          return 0;
        }
        else if ( (unsigned __int8)idAIMoveState::PathToPoint(
                                     this,
                                     path: localPath,
                                     myAreaNum: *startAreaNum,
                                     myPos: aasStartingPoint,
                                     goalAreaNum: (int)v25,
                                     goalPos: aasFinalPoint,
                                     totalTravelTime) != 0 )
        {
          nextPoint->x = localPath->moveGoal.x;
          nextPoint->y = localPath->moveGoal.y;
          nextPoint->z = localPath->moveGoal.z;
          idPLogScope::~idPLogScope(this: &v28);
          RD_EventEnd();
          return 1;
        }
        else
        {
          idPLogScope::~idPLogScope(this: &v28);
          RD_EventEnd();
          return 7;
        }
      }
      else
      {
        idPLogScope::~idPLogScope(this: &v28);
        RD_EventEnd();
        return 6;
      }
    }
    else
    {
      idPLogScope::~idPLogScope(this: &v28);
      RD_EventEnd();
      return 5;
    }
  }
}


// ========================================================================
// __unwind$500574
// EA  : 0x82A5C9C8
// RVA : 0x00A5C9C8
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void _unwind_500574()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 108));
}


// ========================================================================
// __unwind$500575
// EA  : 0x82A5C9F0
// RVA : 0x00A5C9F0
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void _unwind_500575()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 88));
}


// ========================================================================
// ?TestMove@idAIMoveState@@UBA?AW4aiMoveStatus_t@@ABVidAIMoveParms@@AAVidVec3@@1AAH@Z
// EA  : 0x82A5CA18
// RVA : 0x00A5CA18
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

int __fastcall idAIMoveState::TestMove(
        idAIMoveState *this,
        const idAIMoveParms *parms,
        idVec3 *aasFinalPoint,
        idVec3 *nextPoint,
        int *totalTravelTime)
{
  int value; // r10
  idEntity *v11; // r3
  int v12; // r9
  double goalTolerance; // fp31
  idEntity *v14; // r3
  idEntity *v15; // r4
  int v17; // [sp+50h] [-220h] BYREF
  idVec3 v18[2]; // [sp+58h] [-218h] BYREF
  idAAS2Path v19; // [sp+70h] [-200h] BYREF

  value = parms->goalEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v11 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v11 != nullptr && idEntity::CastTo(c: v11) != nullptr )
    {
      v12 = parms->goalEntity.spawnId.value;
      goalTolerance = parms->goalTolerance;
      if ( gameLocal->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13
        && (v14 = gameLocal->entities.ptr[v12 & 0x1FFF]) != nullptr )
      {
        v15 = idEntity::CastTo(c: v14);
      }
      else
      {
        v15 = nullptr;
      }
      if ( this->ReachedEntity(this, a2: v15, a3: goalTolerance) )
        return 0;
    }
  }
  idAAS2Path::idAAS2Path(this: &v19);
  return idAIMoveState::InternalTestMoveToPoint(
           this,
           parms,
           aasStartingPoint: v18,
           aasFinalPoint,
           nextPoint,
           totalTravelTime,
           startAreaNum: &v17,
           localPath: &v19);
}


// ========================================================================
// ?ContinueMove@idAIMoveState@@QAA?AW4aiMoveStatus_t@@AAH@Z
// EA  : 0x82A5CB48
// RVA : 0x00A5CB48
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

int __fastcall idAIMoveState::ContinueMove(idAIMoveState *this, int *totalTravelTime)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  aiMoveStatus_t moveStatus; // r30
  __int32 v8; // r30
  idAIMoveState_vtbl *v9; // r29
  double goalTolerance; // fp31
  const idEntity *GoalEntity; // r3
  const idEntity *ActionEntity; // r3
  idSpawnId *SpawnId; // r3
  int v14; // r30
  idAIMoveState_vtbl *v15; // r29
  double v16; // fp31
  const aiPhysicalState_t *RelevantGoalOrigin; // r3
  int v18; // r30
  unsigned int v19; // r3
  int v20; // r17
  __int16 v21; // r27
  double v22; // fp0
  double v23; // fp13
  double v24; // fp12
  double v25; // fp11
  int flags; // r11
  idVec3 *p_modelAnimStates; // r3
  double y; // fp10
  int v29; // r30
  char v30; // r11
  idMat3 *v31; // r29
  idAI2 *ai; // r3
  bool v33; // r11
  idAIOrientation *BodyOrientation; // r3
  double v35; // fp6
  double v36; // fp1
  double v37; // fp1
  idAI2 *v38; // r3
  int v39; // r30
  double v40; // fp0
  idAnimator_AnimWeb_vtbl *v41; // r11
  double v42; // fp13
  idVec3 *p_finalPoint; // r28
  double v44; // fp12
  float x; // r9
  int y_low; // r8
  double v47; // fp7
  int z_low; // r7
  double v49; // fp6
  idAI2 *v50; // r29
  idPresentable *presentable; // r11
  idAI2 *v52; // r3
  idAI2::idAIVolatile::idAIAnimationInfo *p_animation; // r24
  idPhysics *v54; // r3
  float *v55; // r3
  double v56; // fp0
  double v57; // fp13
  double v58; // fp12
  double v59; // fp10
  double v60; // fp0
  double v61; // fp7
  double v62; // fp30
  double v63; // fp1
  idAI2 *v64; // r29
  idPresentable *v65; // r11
  idAI2 *v66; // r3
  double v67; // fp12
  double v68; // fp11
  double v69; // fp31
  bool v70; // r29
  BOOL v71; // r23
  double v72; // fp13
  idAI2 *v73; // r29
  idPresentable *v74; // r11
  idMat3 *p_axis; // r11
  int v76; // r9
  int v77; // r8
  idAIMoveState::destinationSector_t DestinationDirection; // r29
  const char *v79; // r4
  char *v80; // r4
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *v81; // r28
  idAnimator_AnimWeb *CurSubWebIndex; // r3
  int v83; // r28
  idAnimator_AnimWeb *v84; // r3
  const char *v85; // r4
  idDeclAnimWeb *StateIndexForName; // r3
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *v87; // r29
  idAnimator_AnimWeb *v88; // r3
  idAnimator_AnimWeb *v89; // r3
  int v90; // r3
  idAnimator_AnimWeb *v91; // r3
  aiMoveStatus_t v92; // r30
  const idScenePoint *GoalScenePoint; // r3
  double v94; // fp13
  int value; // r10
  int v96; // r29
  char v97; // r26
  __int16 v98; // r27
  idAIMoveState::destinationSector_t DestinationSector; // r3
  idAIMoveState::destinationSector_t v100; // r29
  const char *v101; // r4
  char *v102; // r4
  const char *CurStateName; // r3
  int v104; // r29
  idDeclAnimWebNode *v105; // r3
  const idDeclAnimWebNode::idModelInfo *v106; // r3
  __int64 v107; // r11
  int v108; // r3
  const idDeclAnimWeb *decl; // r29
  char *SubWebName; // r26
  char *StateName; // r6
  const idAAS2 *v112; // r3
  const idAAS2 *v113; // r29
  const aas2Reachability_t *v114; // r26
  __int64 v115; // r4
  __int64 v116; // r9
  __int16 v117; // r9
  __int64 v118; // r11
  __int16 v119; // r6
  idAI2 *v120; // r3
  __int64 v121; // fp13
  double v122; // fp30
  double v123; // fp31
  double v124; // fp29
  idPhysics *Physics; // r3
  float *v126; // r3
  double v127; // fp3
  double v128; // fp2
  double v129; // fp1
  idQuat *v130; // r3
  int valueInteger; // r10
  int v132; // r26
  idRenderWorld *v133; // r3
  idRenderWorld *v134; // r3
  double v135; // fp12
  double v136; // fp11
  idRenderWorld *v137; // r3
  idRenderWorld *v138; // r3
  int v139; // r26
  idRenderWorld_vtbl *v140; // r29
  int v141; // r3
  idRenderWorld_vtbl *v142; // r29
  int v143; // r3
  double z; // fp12
  double v145; // fp11
  idRenderWorld_vtbl *v146; // r29
  int v147; // r3
  idMat3 *v148; // r3
  double v149; // fp11
  double v150; // fp13
  double v151; // fp12
  double v152; // fp7
  double v153; // fp6
  idRenderWorld_vtbl *v154; // r29
  char v155; // r11
  __int64 v156; // r6
  __int64 v157; // r10
  __int64 v158; // r8
  va *v159; // r3
  int v160; // r30
  int v161; // [sp+8h] [-1268h]
  int v162; // [sp+Ch] [-1264h]
  int v163; // [sp+10h] [-1260h]
  int v164; // [sp+14h] [-125Ch]
  int v165; // [sp+18h] [-1258h]
  int v166; // [sp+1Ch] [-1254h]
  idAnimator_AnimWeb v167[6]; // [sp+60h] [-1210h] BYREF

  RD_EventBegin(name: "idAIMoveState::ContinueMove");
  LODWORD(v4) = "idAIMoveState::ContinueMove";
  HIDWORD(v4) = 6;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v167[0].serializeProps.animStack, pl: &pLog, gMask: v4, label: v5);
  if ( ai_enableMovement.valueInteger == 0
    || (this->lastMoveTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED),
        this->IsPlayingTraversalAnim(this)) )
  {
    moveStatus = this->moveStatus;
    idPLogScope::~idPLogScope(this: (idPLogScope *)&v167[0].serializeProps.animStack);
    RD_EventEnd();
    return moveStatus;
  }
  if ( this->curSmoothAnimType != SMOOTH_ANIM_INVALID )
  {
    idAIMoveState::ResetStuck(this);
    if ( this->curSmoothAnimType == SMOOTH_ANIM_STOP )
    {
      if ( idAI2::AnimEventReceived(this: this->ai, priority: PRIORITY_LOW) )
        v8 = idAIMoveState::Stop(this, newStatus: 0);
      else
        v8 = this->moveStatus;
      idPLogScope::~idPLogScope(this: (idPLogScope *)&v167[0].serializeProps.animStack);
      RD_EventEnd();
      return v8;
    }
  }
  if ( idAIMoveParms::MovingToEntity(this: &this->moveParms) )
  {
    if ( idAIMoveParms::GetGoalEntity(this: &this->moveParms) == nullptr
      || (v9 = this->__vftable,
          goalTolerance = this->moveParms.goalTolerance,
          GoalEntity = idAIMoveParms::GetGoalEntity(this: &this->moveParms),
          v9->ReachedEntity(this, a2: GoalEntity, a3: goalTolerance)) )
    {
      ActionEntity = idAIMemory::GetActionEntity(this: &this->ai->aiVolatile.memory);
      SpawnId = idGameLocal::GetSpawnId(this: (idGameLocal *)v167, result: (idSpawnId *)gameLocal, ent: ActionEntity);
      idEntity::SendNotify_OnReachGoal(this: this->ai, goalEntity: SpawnId->value);
      v14 = idAIMoveState::Stop(this, newStatus: 0);
      idPLogScope::~idPLogScope(this: (idPLogScope *)&v167[0].serializeProps.animStack);
      RD_EventEnd();
      return v14;
    }
  }
  else
  {
    v15 = this->__vftable;
    v16 = this->moveParms.goalTolerance;
    RelevantGoalOrigin = idAIMoveParms::GetRelevantGoalOrigin(this: &this->moveParms, ai: this->ai);
    if ( v15->ReachedPoint(this, a2: &RelevantGoalOrigin->origin, a3: v16) )
    {
      idEntity::SendNotify_OnReachGoal(this: this->ai, goalEntity: 0);
      v18 = idAIMoveState::Stop(this, newStatus: 0);
      idPLogScope::~idPLogScope(this: (idPLogScope *)&v167[0].serializeProps.animStack);
      RD_EventEnd();
      return v18;
    }
  }
  *((_BYTE *)this + 352) &= ~0x80u;
  v19 = idAIMoveState::InternalTestMoveToPoint(
          this,
          parms: &this->moveParms,
          aasStartingPoint: (idVec3 *)&v167[0].curPath.path[28],
          aasFinalPoint: (idVec3 *)&v167[0].curNodeIndex,
          nextPoint: (idVec3 *)&v167[0].initialActiveSubWebs,
          totalTravelTime,
          startAreaNum: (int *)v167,
          localPath: &this->lastPath);
  v20 = v19;
  v21 = -1;
  if ( v19 == 6 )
  {
    this->lastPath.type = 0;
    v22 = *(float *)&v167[0].destStateIndices.stateIndex[1].value;
    v23 = *(float *)&v167[0].curNodeIndex.value;
    v24 = *(float *)&v167[0].destSubWebIndex.value;
    this->lastPath.moveGoal.x = *(float *)&v167[0].curNodeIndex.value;
    this->lastPath.moveGoal.y = v24;
    this->lastPath.moveGoal.z = v22;
    this->lastPath.moveAreaNum = 0;
    this->lastPath.firstEdge.toAreaNum = 0;
    this->lastPath.firstEdge.edgeNum = 0;
    this->lastPath.firstEdge.edgePoint.z = 0.0;
    this->lastPath.firstEdge.edgePoint.y = 0.0;
    this->lastPath.firstEdge.edgePoint.x = 0.0;
    this->lastPath.reachIndex.value = -1;
    this->lastPath.travelTime = 1;
    v25 = *(float *)&v167[0].curPath.num;
    this->lastPath.traversalIndex = 0;
    this->lastPath.traversalStart.z = 0.0;
    this->lastPath.traversalStart.y = 0.0;
    this->lastPath.traversalStart.x = 0.0;
    this->lastPath.traversalEnd.z = 0.0;
    this->lastPath.traversalEnd.y = 0.0;
    v167[0].serializeProps.serializedTrees[0] = (idMD6Branch *)&this->lastPath.obstacleGoal;
    this->lastPath.traversalEnd.x = 0.0;
    this->lastPath.dependencyIndex.value = -1;
    *(float *)&v167[0].initialActiveSubWebs.list = v23;
    *(float *)&v167[0].initialActiveSubWebs.num = v24;
    *(float *)&v167[0].initialActiveSubWebs.size = v22;
    this->lastPath.obstacleGoal.x = v23;
    this->lastPath.obstacleGoal.y = v24;
    this->lastPath.obstacleGoal.z = v22;
    if ( v22 > v25 )
      v25 = v22;
    flags = this->moveParms.flags;
    this->lastPath.pathMaxHeight = v25;
    this->lastPath.obstacleRoute.numAreas = 0;
    p_modelAnimStates = (idVec3 *)&v167[0].modelAnimStates;
    if ( (flags & 1) != 0 )
    {
      p_modelAnimStates = idQuat::ToForward(
                            this: (idQuat *)&v167[0].modelAnimStates,
                            result: (idVec3 *)&this->moveParms.goalOrientation);
      v22 = *(float *)&v167[0].destStateIndices.stateIndex[1].value;
      v24 = *(float *)&v167[0].destSubWebIndex.value;
      v23 = *(float *)&v167[0].curNodeIndex.value;
    }
    else
    {
      *(float *)&v167[0].modelAnimStates.num = 0.0;
      *(float *)&v167[0].modelAnimStates.size = 0.0;
      *(float *)&v167[0].modelAnimStates.list = 1.0;
    }
    this->lastPath.obstacleRoute.endAlignDir.x = p_modelAnimStates->x;
    y = p_modelAnimStates->y;
    v167[0].serializeProps.serializedTrees[0] = (idMD6Branch *)&this->lastPath.obstacleRoute.endAlignDir;
    this->lastPath.obstacleRoute.endAlignDir.y = y;
    this->lastPath.obstacleRoute.endAlignDir.z = p_modelAnimStates->z;
    this->lastPath.obstacleRoute.endTurnRadius = 0.0;
  }
  else
  {
    if ( v19 >= 2 )
    {
      v29 = idAIMoveState::Stop(this, newStatus: v19);
      idPLogScope::~idPLogScope(this: (idPLogScope *)&v167[0].serializeProps.animStack);
      RD_EventEnd();
      return v29;
    }
    v22 = *(float *)&v167[0].destStateIndices.stateIndex[1].value;
    v24 = *(float *)&v167[0].destSubWebIndex.value;
    v23 = *(float *)&v167[0].curNodeIndex.value;
  }
  if ( *(float *)&v167[0].initialActiveSubWebs.list != v23
    || *(float *)&v167[0].initialActiveSubWebs.num != v24
    || (v30 = 1, *(float *)&v167[0].initialActiveSubWebs.size != v22) )
  {
    v30 = 0;
  }
  if ( v30 != 0 && (this->moveParms.flags & 1) != 0 )
  {
    v31 = idQuat::ToMat3(
            this: (idQuat *)&v167[0].scalars.granularity,
            result: (idMat3 *)&this->moveParms.goalOrientation);
    ai = this->ai;
    v33 = ai_useTurningCircles.valueInteger > 0
       && (ai_useTurningCircles.valueInteger > 1 || (*((_BYTE *)ai->aiEditable.behaviors.decl + 85) & 4) != 0);
    if ( v33 || ai_showTurningCircles.valueInteger != 0 )
    {
      BodyOrientation = idAI2::GetBodyOrientation(this: ai);
      v35 = (float)((float)(BodyOrientation->axis.mat[0].x * v31->mat[0].x)
                  + (float)((float)(BodyOrientation->axis.mat[0].z * v31->mat[0].z)
                          + (float)(BodyOrientation->axis.mat[0].y * v31->mat[0].y)));
      v167[0].serializeProps.serializedTrees[0] = (idMD6Branch *)&BodyOrientation->axis;
      if ( v35 < ai_turningCircleAlignmentTolerance.valueFloat )
      {
        v36 = idAI2::CalcMovementTurnRate(
                this: this->ai,
                idealDir: &this->moveOrientation.idealDir,
                curDir: this->moveOrientation.axis.mat);
        v37 = idAI2::CalcTurnRadius(this: this->ai, speed: this->maxMoveSpeed, turnRate: v36);
        this->lastPath.obstacleRoute.endAlignDir.x = v31->mat[0].x;
        this->lastPath.obstacleRoute.endAlignDir.y = v31->mat[0].y;
        v167[0].serializeProps.serializedTrees[0] = (idMD6Branch *)&this->lastPath.obstacleRoute.endAlignDir;
        this->lastPath.obstacleRoute.endAlignDir.z = v31->mat[0].z;
        this->lastPath.obstacleRoute.endTurnRadius = v37;
      }
    }
  }
  if ( v20 != 6 )
  {
    v38 = (idAI2 *)idAIMoveParms::GetGoalEntity(this: &this->moveParms);
    if ( (unsigned __int8)idAIMoveState::PathAroundObstacles(
                            this,
                            startPos: (const idVec3 *)&v167[0].curPath.path[28],
                            destination: (const idVec3 *)&v167[0].initialActiveSubWebs,
                            obstacleRoute: &this->lastPath.obstacleRoute,
                            ignore: v38,
                            newPos: (idVec3 *)&v167[0].initialActiveSubWebs,
                            obstacleInfo: &this->obstacleInfo) == 0 )
    {
      v39 = idAIMoveState::Stop(this, newStatus: 8);
      idPLogScope::~idPLogScope(this: (idPLogScope *)&v167[0].serializeProps.animStack);
      RD_EventEnd();
      return v39;
    }
  }
  if ( this->ReachedPoint(this, a2: (const idVec3 *)&v167[0].curNodeIndex, a3: this->moveParms.goalTolerance) )
  {
LABEL_160:
    v160 = idAIMoveState::Stop(this, newStatus: 0);
    idPLogScope::~idPLogScope(this: (idPLogScope *)&v167[0].serializeProps.animStack);
    RD_EventEnd();
    return v160;
  }
  v40 = *(float *)&v167[0].curNodeIndex.value;
  v41 = v167[0].__vftable;
  v42 = *(float *)&v167[0].destSubWebIndex.value;
  p_finalPoint = &this->finalPoint;
  v44 = *(float *)&v167[0].destStateIndices.stateIndex[1].value;
  this->finalPoint.x = *(float *)&v167[0].curNodeIndex.value;
  this->finalPoint.y = v42;
  this->finalPoint.z = v44;
  this->lastFinalPoint.x = v40;
  v167[0].__vftable = (idAnimator_AnimWeb_vtbl *)&this->nextPoint;
  this->lastFinalPoint.y = this->finalPoint.y;
  v167[0].__vftable = (idAnimator_AnimWeb_vtbl *)&this->lastFinalPoint;
  this->lastFinalPoint.z = this->finalPoint.z;
  x = this->nextPoint.x;
  y_low = LODWORD(this->nextPoint.y);
  v47 = *(float *)&v167[0].initialActiveSubWebs.num;
  z_low = LODWORD(this->nextPoint.z);
  v49 = *(float *)&v167[0].initialActiveSubWebs.size;
  this->nextPoint.x = *(float *)&v167[0].initialActiveSubWebs.list;
  *(float *)&v167[0].modelAnimStates.list = x;
  this->nextPoint.y = v47;
  v167[0].modelAnimStates.num = y_low;
  this->nextPoint.z = v49;
  v50 = this->ai;
  this->lastAreaNum = (int)v41;
  this->lastTravelTime = *totalTravelTime;
  presentable = v50->presentable;
  v167[0].modelAnimStates.size = z_low;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: v50);
    presentable = v50->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  v52 = this->ai;
  p_animation = &v52->aiVolatile.animation;
  if ( (this->moveParms.flags & 0x40) == 0 )
  {
LABEL_92:
    if ( gameLocal->GetGameFrame(this: gameLocal) - this->startMoveFrame < 1 || (*((_BYTE *)this + 352) & 8) != 0 )
      goto LABEL_136;
    value = this->moveParms.destSubWeb.value;
    if ( value < 0 || (unsigned __int16)this->moveParms.destState.value >= 0x8000u )
    {
      decl = this->ai->aiVolatile.animation.animWebAnimator.ptr[0].decl;
      if ( decl != nullptr )
      {
        v167[0].interruptPath = INTR_PATH_NO;
        HIBYTE(v167[0].prevNodeStartTime) = 0;
        v167[0].nodeStartTime = 20;
        v167[0].interruptBlend = (interruptBlend_t)&v167[0].prevNodeStartTime;
        if ( value < 0 )
          SubWebName = "<invalid>";
        else
          SubWebName = (char *)idDeclAnimWeb::GetSubWebName(
                                 this: decl,
                                 index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->moveParms.destSubWeb.value);
        if ( (unsigned __int16)this->moveParms.destState.value >= 0x8000u )
          StateName = "<invalid>";
        else
          StateName = (char *)idDeclAnimWeb::GetStateName(
                                this: decl,
                                index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->moveParms.destState.value);
        idAnimWebPath::SetPath(
          this: (idAnimWebPath *)&v167[0].interruptPath,
          webName: (char *)decl->name.str,
          subWebName: SubWebName,
          stateName: StateName);
        idLib::Warning(
          fmt: "ContinueMove - '%s' has invalid dest node '%s' for move. No movement anim will play.",
          this->ai->name.data,
          (const char *)v167[0].interruptBlend);
        idStr::FreeData(this: (idStr *)&v167[0].interruptPath);
      }
LABEL_136:
      v112 = this->ai->GetAAS(this: this->ai);
      v113 = v112;
      if ( v112 != nullptr
        && (unsigned __int16)this->lastPath.reachIndex.value < 0x8000u
        && this->lastPath.traversalIndex > 0 )
      {
        v114 = v112->GetReachability(
                 this: v112,
                 a2: (const idIndex<short,enum invalidReachability_t> *)(unsigned __int16)this->lastPath.reachIndex.value);
        HIDWORD(v115) = v113->GetTraversal(this: v113, a2: this->lastPath.traversalIndex);
        if ( (v114->travelFlags & 0x1870000) != 0 )
        {
          HIDWORD(v116) = HIDWORD(v115) + 24;
          v117 = *(_WORD *)(HIDWORD(v115) + 28);
          HIDWORD(v118) = byte_821B0000;
          LODWORD(v115) = *(__int16 *)(HIDWORD(v115) + 26);
          v167[0].__vftable = (idAnimator_AnimWeb_vtbl *)(HIDWORD(v115) + 24);
          v119 = *(_WORD *)(HIDWORD(v115) + 24);
          LODWORD(v118) = v117;
          *(_QWORD *)&v167[0].__vftable = v115;
          LODWORD(v116) = v119;
          *(_QWORD *)v167[0].serializeProps.serializedTrees = v118;
          v121 = v115;
          v120 = this->ai;
          *(_QWORD *)&v167[0].__vftable = v116;
          v122 = (float)((float)v121 * (float)0.000030518509);
          v123 = (float)((float)v118 * (float)0.000030518509);
          v124 = (float)((float)v116 * (float)0.000030518509);
          Physics = idEntity::GetPhysics(this: v120);
          v126 = (float *)Physics->GetGravityNormal(this: Physics);
          v127 = v126[1];
          v128 = v126[2];
          v129 = (float)(*v126 * (float)-1.0);
          *(float *)&v167[0].pathableSubWebNodeLists.staticList[7] = v124;
          *(float *)&v167[0].pathableSubWebNodeLists.staticList[8] = v122;
          *(float *)&v167[0].pathableSubWebNodeLists.staticList[9] = v123;
          *(float *)&v167[0].pathableSubWebNodeLists.staticList[14] = (float)v127 * (float)-1.0;
          *(float *)&v167[0].pathableSubWebNodeLists.staticList[15] = (float)v128 * (float)-1.0;
          *(float *)&v167[0].pathableSubWebNodeLists.staticList[13] = v129;
          *(float *)&v167[0].pathableSubWebNodeLists.staticList[11] = (float)((float)v124
                                                                            * *(float *)&v167[0].pathableSubWebNodeLists.staticList[15])
                                                                    - (float)((float)v129 * (float)v123);
          *(float *)&v167[0].pathableSubWebNodeLists.staticList[12] = (float)((float)v129 * (float)v122)
                                                                    - (float)(*(float *)&v167[0].pathableSubWebNodeLists.staticList[14]
                                                                            * (float)v124);
          *(float *)&v167[0].pathableSubWebNodeLists.staticList[10] = (float)(*(float *)&v167[0].pathableSubWebNodeLists.staticList[14]
                                                                            * (float)v123)
                                                                    - (float)((float)v122
                                                                            * *(float *)&v167[0].pathableSubWebNodeLists.staticList[15]);
          idMat3::OrthoNormalizeSelf(this: (idMat3 *)&v167[0].pathableSubWebNodeLists.staticList[7]);
          v130 = idMat3::ToQuat(
                   this: (idMat3 *)&v167[0].initialActiveSubWebs,
                   result: (idQuat *)&v167[0].pathableSubWebNodeLists.staticList[7]);
          this->traversalOrientation.x = v130->x;
          this->traversalOrientation.y = v130->y;
          this->traversalOrientation.z = v130->z;
          v167[0].__vftable = (idAnimator_AnimWeb_vtbl *)&this->lastPath.traversalStart;
          this->traversalOrientation.w = v130->w;
          v167[0].__vftable = (idAnimator_AnimWeb_vtbl *)&this->traversalStartPoint;
          this->traversalStartPoint.x = this->lastPath.traversalStart.x;
          this->traversalStartPoint.y = this->lastPath.traversalStart.y;
          this->traversalStartPoint.z = this->lastPath.traversalStart.z;
          *((_BYTE *)this + 352) |= 0x80u;
          if ( ai_debugTraversals.valueInteger != 0 )
          {
            valueInteger = ai_debugLevel.valueInteger;
            if ( ai_debugLevel.valueInteger <= 0 )
            {
LABEL_144:
              if ( ai_debugMove.valueInteger != 0 && valueInteger > 0 )
              {
                v139 = ((__PAIR64__((unsigned int)valueInteger >> 31, 1) - (unsigned int)valueInteger) >> 32) & 0xBB8;
                v140 = clientGame->renderWorld->__vftable;
                v141 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
                v140->DebugPoint(
                  this: clientGame->renderWorld,
                  a2: (const idVec4 *)&idColor::colorOrange,
                  a3: &this->nextPoint,
                  a4: v141,
                  a5: false);
                v142 = clientGame->renderWorld->__vftable;
                v143 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
                v142->DebugPoint(
                  this: clientGame->renderWorld,
                  a2: (const idVec4 *)&idColor::colorGreen,
                  a3: &this->finalPoint,
                  a4: v143,
                  a5: false);
                z = this->finalPoint.z;
                v145 = this->finalPoint.y;
                *(float *)&v167[0].pathableSubWebNodeLists.staticList[3] = p_finalPoint->x;
                *(float *)&v167[0].pathableSubWebNodeLists.staticList[4] = v145;
                v167[0].__vftable = (idAnimator_AnimWeb_vtbl *)&this->finalPoint;
                *(float *)&v167[0].pathableSubWebNodeLists.staticList[5] = (float)z - (float)128.0;
                v146 = clientGame->renderWorld->__vftable;
                v147 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
                v146->DebugLine(
                  this: clientGame->renderWorld,
                  a2: (const idVec4 *)&idColor::colorGreen,
                  a3: &this->finalPoint,
                  a4: (const idVec3 *)&v167[0].pathableSubWebNodeLists.staticList[3],
                  a5: v147,
                  a6: false);
                if ( (this->moveParms.flags & 1) != 0 )
                {
                  v148 = idQuat::ToMat3(
                           this: (idQuat *)&v167[0].scalars.granularity,
                           result: (idMat3 *)&this->moveParms.goalOrientation);
                  v149 = this->finalPoint.y;
                  v150 = p_finalPoint->x;
                  v151 = this->finalPoint.z;
                  v167[0].__vftable = (idAnimator_AnimWeb_vtbl *)&this->finalPoint;
                  v152 = (float)(v148->mat[0].x * (float)64.0);
                  v153 = (float)(v148->mat[0].z * (float)64.0);
                  *(float *)&v167[0].curPath.path[2].value = (float)v149 + (float)(v148->mat[0].y * (float)64.0);
                  *(float *)&v167[0].curPath.path[0].value = (float)v152 + (float)v150;
                  *(float *)&v167[0].curPath.path[4].value = (float)v151 + (float)v153;
                  v154 = clientGame->renderWorld->__vftable;
                  gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
                  ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, idAnimWebRoute *, double))v154->DebugArrow)(
                    a1: clientGame->renderWorld,
                    a2: &idColor::colorGreen,
                    a3: &this->finalPoint,
                    a4: &v167[0].curPath,
                    a5: 4.0);
                }
                if ( *(float *)&v167[0].modelAnimStates.list != this->nextPoint.x
                  || *(float *)&v167[0].modelAnimStates.num != this->nextPoint.y
                  || (v155 = 1, *(float *)&v167[0].modelAnimStates.size != this->nextPoint.z) )
                {
                  v155 = 0;
                }
                if ( v155 == 0 && ai_debugLevel.valueInteger > 2 )
                {
                  HIDWORD(v156) = idGameTimeManager::GetGameMs(
                                    this: &clientGame->gameTimeManager,
                                    type: GAMETIME_SCALED);
                  v159 = va::va(
                           this: (va *)v167[0].eventHandler.events,
                           fmt: "%d",
                           a3: v156,
                           a4: v158,
                           a5: v157,
                           a6: v161,
                           a7: v162,
                           a8: v163,
                           a9: v164,
                           a10: v165,
                           a11: v166);
                  ((void (__fastcall *)(idRenderWorld *, va *, idVec3 *, idRenderWorld_vtbl *, idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
                    a1: clientGame->renderWorld,
                    a2: v159,
                    a3: &this->nextPoint,
                    a4: clientGame->renderWorld->__vftable,
                    a5: &idColor::colorWhite,
                    a6: 1,
                    a7: v139,
                    a8: 0,
                    a9: 0.2);
                }
              }
              if ( v20 == 6 )
                v20 = 1;
              if ( this->moveStatus != AIMOVESTATUS_MOVING )
                idAIMoveState::ResetStuck(this);
              if ( v20 != 0 )
              {
                this->moveStatus = AIMOVESTATUS_MOVING;
                idPLogScope::~idPLogScope(this: (idPLogScope *)&v167[0].serializeProps.animStack);
                RD_EventEnd();
                return 1;
              }
              goto LABEL_160;
            }
            v132 = 1000 * ai_debugTraversals.valueInteger - 1000;
            v133 = gameLocal->GetRenderWorld(this: gameLocal);
            v133->DebugPoint(
              this: v133,
              a2: (const idVec4 *)&idColor::colorGreen,
              a3: &this->lastPath.traversalStart,
              a4: v132,
              a5: true);
            v134 = gameLocal->GetRenderWorld(this: gameLocal);
            v135 = this->lastPath.traversalStart.y;
            v136 = this->lastPath.traversalStart.x;
            *(float *)&v167[0].pathableSubWebNodeLists.staticList[1] = this->lastPath.traversalStart.z
                                                                     + (float)((float)v123 * (float)32.0);
            v167[0].__vftable = (idAnimator_AnimWeb_vtbl *)&this->lastPath.traversalStart;
            *(float *)v167[0].pathableSubWebNodeLists.staticList = (float)v135 + (float)((float)v122 * (float)32.0);
            *(float *)&v167[0].pathableSubWebNodeLists.granularity = (float)((float)v124 * (float)32.0) + (float)v136;
            ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, __int16 *, double))v134->DebugArrow)(
              a1: v134,
              a2: &idColor::colorGreen,
              a3: &this->lastPath.traversalStart,
              a4: &v167[0].pathableSubWebNodeLists.granularity,
              a5: 4.0);
            v137 = gameLocal->GetRenderWorld(this: gameLocal);
            v137->DebugPoint(
              this: v137,
              a2: (const idVec4 *)&idColor::colorRed,
              a3: &this->lastPath.moveGoal,
              a4: v132,
              a5: true);
            v138 = gameLocal->GetRenderWorld(this: gameLocal);
            v138->DebugAxis_2(
              this: v138,
              a2: &this->lastPath.traversalStart,
              a3: (const idMat3 *)&v167[0].pathableSubWebNodeLists.staticList[7],
              a4: v132,
              a5: false);
          }
        }
      }
      valueInteger = ai_debugLevel.valueInteger;
      goto LABEL_144;
    }
    v96 = -1;
    v97 = 0;
    if ( (this->moveParms.flags & 0x40) == 0 )
    {
LABEL_120:
      if ( v97 != 0 )
      {
        idAIMoveState::SetMovementModeForReal(this, mode: AIMOVEMODE_ANIM);
        v104 = idAnimator_AnimWeb::ChangeStateVia(
                 this: (idAnimator_AnimWeb *)p_animation,
                 subWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->moveParms.destSubWeb.value,
                 stateIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->moveParms.destState.value,
                 _viaSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->moveParms.destSubWeb.value,
                 _viaStateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v96,
                 interruptPath_: INTR_PATH_YES,
                 interruptBlend_: INTR_BLEND_NO,
                 blendEventMask_: 0);
        if ( v21 != -1 )
        {
          v105 = p_animation->animWebAnimator.ptr[0].decl->nodes.list[v21];
          if ( v105 != nullptr )
          {
            v106 = idDeclAnimWebNode::NumAnims(this: v105, modelIndex: nullptr);
            LODWORD(v107) = idRandom2::RandomInt(this: &clientGame->random, max: (int)v106);
            *(_QWORD *)&v167[0].__vftable = v107;
            p_animation->animWebAnimator.ptr[0].select01 = (float)v107;
          }
        }
      }
      else
      {
        v104 = idAnimator_AnimWeb::ChangeState(
                 this: (idAnimator_AnimWeb *)p_animation,
                 subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->moveParms.destSubWeb.value,
                 stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->moveParms.destState.value,
                 interruptPath_: INTR_PATH_YES,
                 interruptBlend_: INTR_BLEND_NO,
                 blendEventMask_: 0);
      }
      if ( v104 == 1 )
      {
        *((_BYTE *)this + 352) |= 8u;
        v108 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        idAnimator_AnimWeb::StartPath(this: (idAnimator_AnimWeb *)p_animation, curTime: v108);
      }
      else
      {
        this->curSmoothAnimType = SMOOTH_ANIM_INVALID;
      }
      goto LABEL_136;
    }
    idAnimator_AnimWeb::GetCurStateIndex(
      this: (idAnimator_AnimWeb *)(&v167[0].serializeProps.createdThroughSerialization + 2),
      result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)p_animation);
    v98 = this->moveParms.destState.value;
    DestinationSector = idAIMoveState::GetDestinationSector(this, destination: &this->nextPoint);
    *(_DWORD *)&v167[0].viaSubWebIndex.value = 0;
    HIBYTE(v167[0].otherSubWebIndex.value) = 0;
    *(_DWORD *)&v167[0].viaStateIndices.stateIndex[3].value = 20;
    v100 = DestinationSector;
    *(_DWORD *)&v167[0].viaStateIndices.stateIndex[1].value = &v167[0].otherSubWebIndex;
    if ( *((__int16 *)&v167[0].serializeProps.createdThroughSerialization + 1) == v98 )
    {
      CurStateName = idAnimator_AnimWeb::GetCurStateName(this: (idAnimator_AnimWeb *)p_animation);
      idStr::operator=(this: (idStr *)&v167[0].viaSubWebIndex, text: CurStateName);
      this->curSmoothAnimType = SMOOTH_ANIM_TURN;
      switch ( v100 )
      {
        case SECTOR_BACKWARD:
          v102 = "_turn_180";
          break;
        case SECTOR_LEFT:
          v102 = "_turn_left90";
          break;
        case SECTOR_RIGHT:
          v102 = "_turn_right90";
          break;
        default:
          goto LABEL_116;
      }
    }
    else
    {
      if ( this->ai->GetWalkState(this: this->ai) == WALKSTATE_WALKING )
        v101 = "walk";
      else
        v101 = "run";
      idStr::operator=(this: (idStr *)&v167[0].viaSubWebIndex, text: v101);
      this->curSmoothAnimType = SMOOTH_ANIM_START;
      if ( (unsigned int)(v100 - 1) > 3 )
        goto LABEL_116;
      switch ( v100 )
      {
        case SECTOR_BACKWARD:
          v102 = "_start_180";
          break;
        case SECTOR_LEFT:
          v102 = "_start_left90";
          break;
        case SECTOR_FORWARD:
          v102 = "_start_forward";
          break;
        default:
          v102 = "_start_right90";
          break;
      }
    }
    idStr::Append(this: (idStr *)&v167[0].viaSubWebIndex, text: v102);
LABEL_116:
    v96 = HIWORD(idDeclAnimWeb::GetStateIndexForName(
                   this: (idDeclAnimWeb *)v167,
                   result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)p_animation->animWebAnimator.ptr[0].decl,
                   name: *(const char **)&v167[0].viaStateIndices.stateIndex[1].value)->__vftable);
    v21 = HIWORD(idDeclAnimWeb::FindNodeIndex(
                   this: (idDeclAnimWeb *)&v167[0].serializeProps,
                   result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)p_animation->animWebAnimator.ptr[0].decl,
                   subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->moveParms.destSubWeb.value,
                   stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v96)->__vftable);
    if ( v21 >= 0 && *((__int16 *)&v167[0].serializeProps.createdThroughSerialization + 1) != (__int16)v96 )
      v97 = 1;
    idStr::FreeData(this: (idStr *)&v167[0].viaSubWebIndex);
    goto LABEL_120;
  }
  v167[0].__vftable = (idAnimator_AnimWeb_vtbl *)this->ai;
  v54 = idEntity::GetPhysics(this: v52);
  v55 = (float *)v54->GetOrigin(this: v54, a2: 0);
  v56 = this->finalPoint.y;
  v57 = p_finalPoint->x;
  v58 = this->finalPoint.z;
  v167[0].__vftable = (idAnimator_AnimWeb_vtbl *)&this->finalPoint;
  v59 = (float)((float)v56 - v55[1]);
  v60 = (float)((float)v57 - *v55);
  v61 = (float)((float)v58 - v55[2]);
  *(float *)&v167[0].initialActiveSubWebs.list = (float)v57 - *v55;
  *(float *)&v167[0].initialActiveSubWebs.num = v59;
  *(float *)&v167[0].initialActiveSubWebs.size = v61;
  v62 = (float)((float)((float)v61 * (float)v61)
              + (float)((float)((float)v60 * (float)v60) + (float)((float)v59 * (float)v59)));
  v63 = idVec3::NormalizeFast(this: (idVec3 *)&v167[0].initialActiveSubWebs);
  v64 = this->ai;
  v65 = v64->presentable;
  if ( v65 == nullptr )
  {
    idEntity::InitPresentableInternal(this: this->ai);
    v65 = v64->presentable;
  }
  v66 = this->ai;
  v67 = (float)(v65->axis.mat[0].y * *(float *)&v167[0].initialActiveSubWebs.num);
  v68 = v65->axis.mat[0].z;
  v167[0].__vftable = (idAnimator_AnimWeb_vtbl *)&v65->axis;
  v69 = (float)((float)(*(float *)&v167[0].initialActiveSubWebs.list * v65->axis.mat[0].x)
              + (float)((float)((float)v68 * *(float *)&v167[0].initialActiveSubWebs.size) + (float)v67));
  v70 = (_cntlzw(((int (__fastcall *)(idAI2 *, double))v66->GetWalkState)(a1: v66, a2: v63) - 1) & 0x20) != 0;
  v167[0].__vftable = (idAnimator_AnimWeb_vtbl *)this->moveParms.arrivalAction;
  if ( v167[0].__vftable != (idAnimator_AnimWeb_vtbl *)2 )
  {
    if ( v167[0].__vftable == (idAnimator_AnimWeb_vtbl *)1 )
    {
      GoalScenePoint = idAIMoveParms::GetGoalScenePoint(this: &this->moveParms);
      if ( GoalScenePoint != nullptr && GoalScenePoint->relatedScenePoints.num > 0 )
      {
        if ( v70 )
          v94 = 14400.0;
        else
          v94 = 40000.0;
        if ( v69 >= 0.99000001 && v62 <= v94 )
          goto LABEL_160;
      }
      else
      {
        this->moveParms.arrivalAction = AIARRIVAL_STOP;
      }
    }
    goto LABEL_92;
  }
  v71 = v70;
  if ( v70 )
    v72 = 14400.0;
  else
    v72 = 40000.0;
  if ( v69 < 0.99000001 || v62 > v72 )
    goto LABEL_92;
  if ( idAIMoveParms::GetGoalScenePoint(this: &this->moveParms) != nullptr )
    v73 = (idAI2 *)idAIMoveParms::GetGoalScenePoint(this: &this->moveParms);
  else
    v73 = this->ai;
  v74 = v73->presentable;
  if ( v74 == nullptr )
  {
    idEntity::InitPresentableInternal(this: v73);
    v74 = v73->presentable;
  }
  p_axis = &v74->axis;
  v76 = LODWORD(p_axis->mat[0].y);
  v77 = LODWORD(p_axis->mat[0].z);
  v167[0].modelAnimStates.list = (idAnimator_AnimWeb::idModelAnimState *)LODWORD(p_axis->mat[0].x);
  v167[0].modelAnimStates.num = v76;
  v167[0].modelAnimStates.size = v77;
  DestinationDirection = idAIMoveState::GetDestinationDirection(
                           this,
                           direction: (const idVec3 *)&v167[0].modelAnimStates);
  v79 = "walk";
  if ( !v71 )
    v79 = "run";
  idStr::idStr(this: (idStr *)&v167[0].curPath.path[12], text: v79);
  if ( (unsigned int)(DestinationDirection - 1) <= 3 )
  {
    switch ( DestinationDirection )
    {
      case SECTOR_BACKWARD:
        v80 = "_stop_180";
        break;
      case SECTOR_LEFT:
        v80 = "_stop_left90";
        break;
      case SECTOR_FORWARD:
        v80 = "_stop_forward";
        break;
      default:
        v80 = "_stop_right90";
        break;
    }
    idStr::Append(this: (idStr *)&v167[0].curPath.path[12], text: v80);
  }
  idDeclAnimWeb::GetStateIndexForName(
    this: (idDeclAnimWeb *)&v167[0].weightGroup,
    result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)p_animation->animWebAnimator.ptr[0].decl,
    name: *(const char **)&v167[0].curPath.path[14].value);
  v81 = (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)p_animation->animWebAnimator.ptr[0].decl;
  CurSubWebIndex = idAnimator_AnimWeb::GetCurSubWebIndex(
                     this: (idAnimator_AnimWeb *)&v167[0].serializeProps,
                     result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)p_animation);
  idDeclAnimWeb::FindNodeIndex(
    this: (idDeclAnimWeb *)&v167[0].serializeProps.createdThroughSerialization,
    result: v81,
    subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(CurSubWebIndex->__vftable),
    stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v167[0].weightGroup));
  v83 = 0;
  if ( *(__int16 *)&v167[0].serializeProps.createdThroughSerialization >= 0 )
  {
    v84 = idAnimator_AnimWeb::GetCurSubWebIndex(
            this: (idAnimator_AnimWeb *)&v167[0].serializeProps,
            result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)p_animation);
    v83 = idAnimator_AnimWeb::ChangeState(
            this: (idAnimator_AnimWeb *)p_animation,
            subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v84->__vftable),
            stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v167[0].weightGroup),
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_NO,
            blendEventMask_: 0);
    if ( v83 == 1 )
      goto LABEL_80;
  }
  if ( DestinationDirection != SECTOR_FORWARD )
  {
    v85 = "walk";
    if ( !v71 )
      v85 = "run";
    idStr::operator=(this: (idStr *)&v167[0].curPath.path[12], text: v85);
    idStr::Append(this: (idStr *)&v167[0].curPath.path[12], text: "_stop_forward");
    StateIndexForName = idDeclAnimWeb::GetStateIndexForName(
                          this: (idDeclAnimWeb *)&v167[0].serializeProps,
                          result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)p_animation->animWebAnimator.ptr[0].decl,
                          name: *(const char **)&v167[0].curPath.path[14].value);
    v87 = (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)p_animation->animWebAnimator.ptr[0].decl;
    HIWORD(v167[0].weightGroup) = HIWORD(StateIndexForName->__vftable);
    v88 = idAnimator_AnimWeb::GetCurSubWebIndex(
            this: v167,
            result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)p_animation);
    *(_WORD *)&v167[0].serializeProps.createdThroughSerialization = HIWORD(idDeclAnimWeb::FindNodeIndex(
                                                                             this: (idDeclAnimWeb *)&v167[0].serializeProps,
                                                                             result: v87,
                                                                             subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v88->__vftable),
                                                                             stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v167[0].weightGroup))->__vftable);
    if ( *(__int16 *)&v167[0].serializeProps.createdThroughSerialization >= 0 )
    {
      v89 = idAnimator_AnimWeb::GetCurSubWebIndex(
              this: v167,
              result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)p_animation);
      v83 = idAnimator_AnimWeb::ChangeState(
              this: (idAnimator_AnimWeb *)p_animation,
              subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v89->__vftable),
              stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v167[0].weightGroup),
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_NO,
              blendEventMask_: 0);
    }
  }
  if ( v83 == 1 )
  {
LABEL_80:
    idAIMoveState::SetMovementModeForReal(this, mode: AIMOVEMODE_ANIM);
    v90 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idAnimator_AnimWeb::StartPath(this: (idAnimator_AnimWeb *)p_animation, curTime: v90);
    v91 = idAnimator_AnimWeb::GetCurSubWebIndex(
            this: v167,
            result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)p_animation);
    idAI2::SetAnimWebEvent(
      this: this->ai,
      web: AIANIMWEB_BODY,
      priority: PRIORITY_LOW,
      swi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v91->__vftable),
      si: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v167[0].weightGroup),
      eventType: ANIMWEB_EVENT_DEST_CLAMPED,
      eventDef: &EV_AnimWeb_Wait);
    this->curSmoothAnimType = SMOOTH_ANIM_STOP;
  }
  v92 = this->moveStatus;
  idStr::FreeData(this: (idStr *)&v167[0].curPath.path[12]);
  idPLogScope::~idPLogScope(this: (idPLogScope *)&v167[0].serializeProps.animStack);
  RD_EventEnd();
  return v92;
}


// ========================================================================
// __unwind$500827
// EA  : 0x82A5E060
// RVA : 0x00A5E060
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void _unwind_500827()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 4720 + 4544));
}


// ========================================================================
// __unwind$500828
// EA  : 0x82A5E088
// RVA : 0x00A5E088
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void _unwind_500828()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 4720 + 120));
}


// ========================================================================
// __unwind$500829
// EA  : 0x82A5E0B0
// RVA : 0x00A5E0B0
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void _unwind_500829()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4720 + 320));
}


// ========================================================================
// __unwind$500831
// EA  : 0x82A5E0D8
// RVA : 0x00A5E0D8
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void _unwind_500831()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4720 + 192));
}


// ========================================================================
// __unwind$500830
// EA  : 0x82A5E100
// RVA : 0x00A5E100
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void _unwind_500830()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4720 + 368));
}


// ========================================================================
// ?FinishPlayingTraversalAnim@idAIMoveState@@QAAXXZ
// EA  : 0x82A5E128
// RVA : 0x00A5E128
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __fastcall idAIMoveState::FinishPlayingTraversalAnim(idAIMoveState *this)
{
  idAI2 *ai; // r3
  char v3; // r10
  aiMovementMode_t DefaultMovementMode; // r3
  idAI2 *v5; // r30
  idPresentable *presentable; // r11
  idPhysics *Physics; // r3
  float *v8; // r3
  idAI2 *v9; // r3
  double v10; // fp31
  double v11; // fp30
  double v12; // fp29
  idPhysics *v13; // r3
  float *v14; // r3
  double v15; // fp3
  double v16; // fp2
  double z; // fp11
  double x; // fp10
  double v19; // fp0
  double v22; // fp6
  double v23; // fp13
  double v24; // fp7
  idAI2 *v25; // r30
  idPresentable *v26; // r11
  char *v27; // r10
  idPresentable *p_z; // r11
  int i; // ctr
  double v32; // fp4
  double v33; // fp8
  double v34; // fp5
  double v35; // fp0
  double v36; // fp13
  idAI2 *v37; // r30
  idAIOrientation *BodyOrientation; // r3
  idAIOrientation *v39; // r3
  idLegsFSM *ActionFSM; // r3
  idAIAction *v41; // r3
  int v42; // [sp+50h] [-D0h] BYREF
  idVec3 v43[2]; // [sp+58h] [-C8h] BYREF
  idMat3 v44; // [sp+70h] [-B0h] BYREF
  char v45; // [sp+9Ch] [-84h] BYREF
  idMat3 v46[2]; // [sp+A0h] [-80h] BYREF

  v3 = *((_BYTE *)this + 352);
  ai = this->ai;
  this->traversalAnimToPlay = ANIMOVERRIDE_NONE;
  *((_BYTE *)this + 352) = v3 & 0xEF;
  DefaultMovementMode = idAI2::GetDefaultMovementMode(this: ai);
  v5 = this->ai;
  this->movementMode = DefaultMovementMode;
  presentable = v5->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: v5);
    presentable = v5->presentable;
  }
  presentable->model->useDeferredPosition = -11 - ((this->movementMode == AIMOVEMODE_PERFECTORIGIN) - 12);
  idAI2::SetWorldCollision(this: this->ai, collideWithWorld: true);
  idAIMoveState::ContinueMove(this, totalTravelTime: &v42);
  Physics = idEntity::GetPhysics(this: this->ai);
  v8 = (float *)Physics->GetGravityNormal(this: Physics);
  v10 = (float)(*v8 * (float)-1.0);
  v11 = (float)(v8[1] * (float)-1.0);
  v12 = (float)(v8[2] * (float)-1.0);
  v9 = this->ai;
  v43[0].x = v10;
  v43[0].y = v11;
  v43[0].z = v12;
  v13 = idEntity::GetPhysics(this: v9);
  v14 = (float *)v13->GetOrigin(this: v13, a2: 0);
  v15 = (float)(this->nextPoint.y - v14[1]);
  v16 = (float)(this->nextPoint.z - v14[2]);
  v44.mat[0].x = this->nextPoint.x - *v14;
  v44.mat[0].y = v15;
  v44.mat[0].z = v16;
  idVec3::ProjectOntoPlane(this: v44.mat, normal: v43, overBounce: 1.0);
  z = v44.mat[0].z;
  x = v44.mat[0].x;
  v19 = (float)((float)(v44.mat[0].x * v44.mat[0].x)
              + (float)((float)(v44.mat[0].z * v44.mat[0].z) + (float)(v44.mat[0].y * v44.mat[0].y)));
  if ( v19 > 0.0 )
  {
    _FP8 = (float)((float)((float)(v44.mat[0].x * v44.mat[0].x)
                         + (float)((float)(v44.mat[0].z * v44.mat[0].z) + (float)(v44.mat[0].y * v44.mat[0].y)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v44.mat[2].x = v10;
    v44.mat[2].y = v11;
    v44.mat[2].z = v12;
    __asm { fsel      f7, f8, f0, f13 }
    v22 = __frsqrte(_FP7);
    v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                        * (float)((float)v19 * (float)0.5))
                                                                                * (float)v22)
                                                                        - (float)1.5)
                                                        * (float)v22)
                                                * (float)((float)v19 * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v22
                                                                                * (float)((float)v19 * (float)0.5))
                                                                        * (float)v22)
                                                                - (float)1.5)
                                                * (float)v22))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22)
                                        - (float)1.5)
                        * (float)v22));
    v24 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                                * (float)v22)
                                                                                        * (float)((float)v19 * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                        * (float)v22))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v22
                                                                                                * (float)((float)v19 * (float)0.5))
                                                                                        * (float)v22)
                                                                                - (float)1.5)
                                                                * (float)v22))
                                                * (float)((float)v19 * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                        * (float)v22)
                                                                                * (float)((float)v19 * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22)
                                                                                                - (float)1.5)
                                                                                * (float)v22))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v22
                                                                                        * (float)((float)v19 * (float)0.5))
                                                                                * (float)v22)
                                                                        - (float)1.5)
                                                        * (float)v22)))
                                - (float)1.5)
                * (float)v23);
    v44.mat[0].y = v44.mat[0].y
                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22)
                                                                                                 * (float)((float)v19 * (float)0.5))
                                                                                         * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                                 * (float)v22))
                                                                                 - (float)1.5)
                                                                 * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5))
                                                                                                 * (float)v22)
                                                                                         - (float)1.5)
                                                                         * (float)v22))
                                                         * (float)((float)v19 * (float)0.5))
                                                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                                 * (float)v22)
                                                                                         * (float)((float)v19
                                                                                                 * (float)0.5))
                                                                                 * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                         * (float)v22))
                                                                         - (float)1.5)
                                                         * (float)((float)-(float)((float)((float)((float)v22
                                                                                                 * (float)((float)v19 * (float)0.5))
                                                                                         * (float)v22)
                                                                                 - (float)1.5)
                                                                 * (float)v22)))
                                         - (float)1.5)
                         * (float)v23);
    v44.mat[0].x = v44.mat[0].x
                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22)
                                                                                                 * (float)((float)v19 * (float)0.5))
                                                                                         * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                                 * (float)v22))
                                                                                 - (float)1.5)
                                                                 * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5))
                                                                                                 * (float)v22)
                                                                                         - (float)1.5)
                                                                         * (float)v22))
                                                         * (float)((float)v19 * (float)0.5))
                                                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                                 * (float)v22)
                                                                                         * (float)((float)v19
                                                                                                 * (float)0.5))
                                                                                 * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                         * (float)v22))
                                                                         - (float)1.5)
                                                         * (float)((float)-(float)((float)((float)((float)v22
                                                                                                 * (float)((float)v19 * (float)0.5))
                                                                                         * (float)v22)
                                                                                 - (float)1.5)
                                                                 * (float)v22)))
                                         - (float)1.5)
                         * (float)v23);
    v44.mat[0].z = v44.mat[0].z
                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22)
                                                                                                 * (float)((float)v19 * (float)0.5))
                                                                                         * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                                 * (float)v22))
                                                                                 - (float)1.5)
                                                                 * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5))
                                                                                                 * (float)v22)
                                                                                         - (float)1.5)
                                                                         * (float)v22))
                                                         * (float)((float)v19 * (float)0.5))
                                                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                                 * (float)v22)
                                                                                         * (float)((float)v19
                                                                                                 * (float)0.5))
                                                                                 * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                         * (float)v22))
                                                                         - (float)1.5)
                                                         * (float)((float)-(float)((float)((float)((float)v22
                                                                                                 * (float)((float)v19 * (float)0.5))
                                                                                         * (float)v22)
                                                                                 - (float)1.5)
                                                                 * (float)v22)))
                                         - (float)1.5)
                         * (float)v23);
    v44.mat[1].x = (float)((float)((float)z
                                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22) * (float)((float)v19 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22))
                                                                                                 - (float)1.5)
                                                                                 * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                         * (float)v22))
                                                                         * (float)((float)v19 * (float)0.5))
                                                                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22) * (float)((float)v19 * (float)0.5))
                                                                                                 * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22))
                                                                                         - (float)1.5)
                                                                         * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22)
                                                                                                 - (float)1.5)
                                                                                 * (float)v22)))
                                                         - (float)1.5)
                                         * (float)v23))
                         * (float)v11)
                 - (float)(v44.mat[0].y * (float)v12);
    v44.mat[1].z = (float)(v44.mat[0].y * (float)v10)
                 - (float)((float)((float)x
                                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22) * (float)((float)v19 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22))
                                                                                                 - (float)1.5)
                                                                                 * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                         * (float)v22))
                                                                         * (float)((float)v19 * (float)0.5))
                                                                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22) * (float)((float)v19 * (float)0.5))
                                                                                                 * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22))
                                                                                         - (float)1.5)
                                                                         * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22)
                                                                                                 - (float)1.5)
                                                                                 * (float)v22)))
                                                         - (float)1.5)
                                         * (float)v23))
                         * (float)v11);
    v44.mat[1].y = (float)((float)((float)x * (float)v24) * (float)v12)
                 - (float)((float)((float)z * (float)v24) * (float)v10);
    idMat3::OrthoNormalizeSelf(this: &v44);
    idAIOrientation::SetIdealDir(this: &this->moveOrientation, ai: this->ai, dir: v44.mat);
    idAIOrientation::SetAxis(this: &this->moveOrientation, axis: &v44);
  }
  v25 = this->ai;
  v26 = v25->presentable;
  if ( v26 == nullptr )
  {
    idEntity::InitPresentableInternal(this: this->ai);
    v26 = v25->presentable;
  }
  v27 = &v45;
  p_z = (idPresentable *)&v26->origin.z;
  for ( i = 9; i != 0; --i )
  {
    p_z = (idPresentable *)((char *)p_z + 4);
    v27 += 4;
    *(_DWORD *)v27 = p_z->__vftable;
  }
  idVec3::ProjectOntoPlane(this: v46[0].mat, normal: v43, overBounce: 1.0);
  v46[0].mat[2].x = v10;
  v46[0].mat[2].y = v11;
  v46[0].mat[2].z = v12;
  _FP7 = (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z)
                       + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x) + (float)(v46[0].mat[0].y * v46[0].mat[0].y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f5, f7, f8, f0 }
  v32 = __frsqrte(_FP5);
  v33 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v32
                                                                                      * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z) + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x) + (float)(v46[0].mat[0].y * v46[0].mat[0].y)))
                                                                                              * (float)0.5))
                                                                              * (float)v32)
                                                                      - (float)1.5)
                                                      * (float)v32)
                                              * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z)
                                                              + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x)
                                                                      + (float)(v46[0].mat[0].y * v46[0].mat[0].y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v32
                                                                              * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z)
                                                                                              + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x) + (float)(v46[0].mat[0].y * v46[0].mat[0].y)))
                                                                                      * (float)0.5))
                                                                      * (float)v32)
                                                              - (float)1.5)
                                              * (float)v32))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v32
                                                      * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z)
                                                                      + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x)
                                                                              + (float)(v46[0].mat[0].y * v46[0].mat[0].y)))
                                                              * (float)0.5))
                                              * (float)v32)
                                      - (float)1.5)
                      * (float)v32));
  v34 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z) + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x) + (float)(v46[0].mat[0].y * v46[0].mat[0].y))) * (float)0.5)) * (float)v32) - (float)1.5)
                                                                                              * (float)v32)
                                                                                      * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z) + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x) + (float)(v46[0].mat[0].y * v46[0].mat[0].y)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z) + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x) + (float)(v46[0].mat[0].y * v46[0].mat[0].y))) * (float)0.5)) * (float)v32) - (float)1.5)
                                                                                      * (float)v32))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v32
                                                                                              * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z) + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x) + (float)(v46[0].mat[0].y * v46[0].mat[0].y))) * (float)0.5))
                                                                                      * (float)v32)
                                                                              - (float)1.5)
                                                              * (float)v32))
                                              * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z)
                                                              + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x)
                                                                      + (float)(v46[0].mat[0].y * v46[0].mat[0].y)))
                                                      * (float)0.5))
                                      * (float)v33)
                              - (float)1.5)
              * (float)v33);
  v35 = (float)(v46[0].mat[0].x
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z) + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x) + (float)(v46[0].mat[0].y * v46[0].mat[0].y))) * (float)0.5)) * (float)v32) - (float)1.5) * (float)v32)
                                                                                              * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z) + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x) + (float)(v46[0].mat[0].y * v46[0].mat[0].y))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z) + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x) + (float)(v46[0].mat[0].y * v46[0].mat[0].y))) * (float)0.5)) * (float)v32) - (float)1.5)
                                                                                              * (float)v32))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z) + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x) + (float)(v46[0].mat[0].y * v46[0].mat[0].y))) * (float)0.5))
                                                                                              * (float)v32)
                                                                                      - (float)1.5)
                                                                      * (float)v32))
                                                      * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z)
                                                                      + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x)
                                                                              + (float)(v46[0].mat[0].y * v46[0].mat[0].y)))
                                                              * (float)0.5))
                                              * (float)v33)
                                      - (float)1.5)
                      * (float)v33));
  v36 = (float)(v46[0].mat[0].y
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z) + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x) + (float)(v46[0].mat[0].y * v46[0].mat[0].y))) * (float)0.5)) * (float)v32) - (float)1.5) * (float)v32)
                                                                                              * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z) + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x) + (float)(v46[0].mat[0].y * v46[0].mat[0].y))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z) + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x) + (float)(v46[0].mat[0].y * v46[0].mat[0].y))) * (float)0.5)) * (float)v32) - (float)1.5)
                                                                                              * (float)v32))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z) + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x) + (float)(v46[0].mat[0].y * v46[0].mat[0].y))) * (float)0.5))
                                                                                              * (float)v32)
                                                                                      - (float)1.5)
                                                                      * (float)v32))
                                                      * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z)
                                                                      + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x)
                                                                              + (float)(v46[0].mat[0].y * v46[0].mat[0].y)))
                                                              * (float)0.5))
                                              * (float)v33)
                                      - (float)1.5)
                      * (float)v33));
  v46[0].mat[0].y = v46[0].mat[0].y
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z) + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x) + (float)(v46[0].mat[0].y * v46[0].mat[0].y))) * (float)0.5)) * (float)v32) - (float)1.5) * (float)v32)
                                                                                                  * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z) + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x) + (float)(v46[0].mat[0].y * v46[0].mat[0].y))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z) + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x) + (float)(v46[0].mat[0].y * v46[0].mat[0].y))) * (float)0.5)) * (float)v32) - (float)1.5)
                                                                                                  * (float)v32))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z) + (float)((float)(v46[0].mat[0].x * v46[0].mat[0].x) + (float)(v46[0].mat[0].y * v46[0].mat[0].y))) * (float)0.5))
                                                                                                  * (float)v32)
                                                                                          - (float)1.5)
                                                                          * (float)v32))
                                                          * (float)((float)((float)(v46[0].mat[0].z * v46[0].mat[0].z)
                                                                          + (float)((float)(v46[0].mat[0].x
                                                                                          * v46[0].mat[0].x)
                                                                                  + (float)(v46[0].mat[0].y
                                                                                          * v46[0].mat[0].y)))
                                                                  * (float)0.5))
                                                  * (float)v33)
                                          - (float)1.5)
                          * (float)v33);
  v46[0].mat[0].x = v35;
  v46[0].mat[0].z = v46[0].mat[0].z * (float)v34;
  v46[0].mat[1].z = (float)((float)v36 * (float)v10) - (float)((float)v35 * (float)v11);
  v46[0].mat[1].x = (float)(v46[0].mat[0].z * (float)v11) - (float)((float)v36 * (float)v12);
  v46[0].mat[1].y = (float)((float)v35 * (float)v12) - (float)(v46[0].mat[0].z * (float)v10);
  idMat3::OrthoNormalizeSelf(this: v46);
  v37 = this->ai;
  BodyOrientation = idAI2::GetBodyOrientation(this: v37);
  idAIOrientation::SetIdealDir(this: BodyOrientation, ai: v37, dir: v46[0].mat);
  v39 = idAI2::GetBodyOrientation(this: this->ai);
  idAIOrientation::SetAxis(this: v39, axis: v46);
  ActionFSM = idAI2::GetActionFSM(this: this->ai);
  v41 = idAIAction::CastTo(c: (idAIAction *)ActionFSM->curState);
  if ( v41 != nullptr )
    v41->tempUninterruptible = false;
}


// ========================================================================
// ?MoveFailed@idAIMoveState@@UAAXW4aiMoveReason_t@@W4aiMoveStatus_t@@V?$idTypesafeNumber@HW4gameTimeUnique_t@@@@@Z
// EA  : 0x82A5E488
// RVA : 0x00A5E488
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __fastcall idAIMoveState::MoveFailed(
        idAIMoveState *this,
        const aiMoveReason_t reason,
        const aiMoveStatus_t status,
        const idTypesafeNumber<int,enum gameTimeUnique_t> *time)
{
  unsigned __int8 v5; // r29
  unsigned __int8 v6; // r28
  int v8; // r30
  int num; // r11
  int v10; // r9
  int v11; // r7
  int v12; // r10
  int v13; // ctr
  moveFailureInfo_t *list; // r11
  int value; // r11
  moveFailureInfo_t *v16; // r11

  v5 = reason;
  v6 = status;
  v8 = -1;
  this->ai->aiVolatile.memory.movementFailedTime = idGameTimeManager::GetGameMs(
                                                     this: &clientGame->gameTimeManager,
                                                     type: GAMETIME_SCALED);
  num = this->moveFailures.num;
  if ( num >= this->moveFailures.size )
  {
    v10 = 0;
    v11 = 0x7FFFFFFF;
    if ( num > 0 )
    {
      v12 = 0;
      v13 = this->moveFailures.num;
      list = this->moveFailures.list;
      do
      {
        value = list->failureTime.value;
        if ( value < v11 )
        {
          v11 = value;
          v8 = v10;
        }
        ++v12;
        ++v10;
        list = &this->moveFailures.list[v12];
        --v13;
      }
      while ( v13 != 0 );
    }
  }
  else
  {
    v8 = this->moveFailures.num;
    idList<moveFailureInfo_t,5>::Alloc(this: &this->moveFailures);
  }
  v16 = &this->moveFailures.list[v8];
  v16->moveReason = v5;
  v16->moveStatus = v6;
  v16->failureTime = (idTypesafeNumber<int,enum gameTimeUnique_t>)time->value;
}


// ========================================================================
// ?StartMove@idAIMoveState@@QAA?AW4aiMoveStatus_t@@ABVidAIMoveParms@@@Z
// EA  : 0x82A5E560
// RVA : 0x00A5E560
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

int __fastcall idAIMoveState::StartMove(idAIMoveState *this, const idAIMoveParms *parms)
{
  int v4; // r3
  int lastMoveTime; // r24
  int v6; // r26
  int v7; // r3
  char v8; // r7
  idPhysics *Physics; // r23
  const aiPhysicalState_t *RelevantGoalOrigin; // r22
  const idVec3 *v11; // r3
  int value; // r9
  idScenePoint *v13; // r3
  int v14; // r9
  idScenePoint *v15; // r3
  idScenePoint *v16; // r3
  int v17; // r5
  aiMovePushStatus_t v18; // r4
  int v19; // r4
  idAIMemory *p_memory; // r30
  idAI2 *v21; // r3
  idPhysics *v22; // r30
  idEntity *GoalEntity; // r3
  idPhysics *v24; // r29
  float *v25; // r30
  float *v26; // r3
  idAI2 *ai; // r3
  double v28; // fp0
  double v29; // fp13
  double v30; // fp12
  double v31; // fp30
  idPhysics *v32; // r3
  const idVec3 *v33; // r3
  double v34; // fp5
  idPhysics *v35; // r3
  float *v36; // r3
  double v37; // fp9
  double v38; // fp4
  double v39; // fp0
  double v40; // fp13
  double v41; // fp9
  idPhysics *v42; // r3
  float *v43; // r30
  const idVec3 *v44; // r3
  idAI2 *v45; // r3
  double v46; // fp9
  double v47; // fp7
  double v48; // fp6
  idPhysics *v49; // r3
  const idVec3 *v50; // r3
  idPhysics *v51; // r3
  float *v52; // r3
  int v54; // [sp+50h] [-A0h] BYREF
  idVec3 v55; // [sp+58h] [-98h] BYREF
  idVec3 v56; // [sp+68h] [-88h] BYREF
  idVec3 v57; // [sp+78h] [-78h] BYREF

  v4 = this->GetMoveStatus(this);
  lastMoveTime = this->lastMoveTime;
  v6 = v4;
  v7 = gameLocal->GetGameFrame(this: gameLocal);
  v8 = *((_BYTE *)this + 352);
  this->startMoveFrame = v7;
  this->numZeroVelocityFrames = 0;
  this->traversalAnimToPlay = ANIMOVERRIDE_NONE;
  this->endLerpTime = -1;
  *((_BYTE *)this + 352) = v8 & 0x47;
  idAIMoveParms::operator=(this: &this->moveParms, __that: parms);
  this->curSmoothAnimType = SMOOTH_ANIM_INVALID;
  if ( ai_pointTolerance.valueFloat >= 0.0 )
  {
    this->moveParms.intermediateTolerance = ai_pointTolerance.valueFloat;
    this->moveParms.goalTolerance = ai_pointTolerance.valueFloat;
  }
  idObstacleInfo::Reset(this: &this->obstacleInfo);
  Physics = idEntity::GetPhysics(this: this->ai);
  RelevantGoalOrigin = idAIMoveParms::GetRelevantGoalOrigin(this: &this->moveParms, ai: this->ai);
  v11 = Physics->GetOrigin(this: Physics, a2: 0);
  idObstacleAvoidance::Restart(this: &this->oa, start: v11, goal: &RelevantGoalOrigin->origin);
  value = parms->goalScenePoint.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v13 = (idScenePoint *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idScenePoint::CastTo(c: v13) != nullptr
    && ((v14 = parms->goalScenePoint.spawnId.value, gameLocal->spawnIds.ptr[v14 & 0x1FFF] != v14 >> 13)
     || (v15 = (idScenePoint *)gameLocal->entities.ptr[v14 & 0x1FFF]) == nullptr
      ? (v16 = nullptr)
      : (v16 = idScenePoint::CastTo(c: v15)),
        (v16->scriptFlags & 1) != 0) )
  {
    v17 = 666;
    v18 = AIMOVEPUSHSTATUS_PUSH_PLAYERS;
  }
  else
  {
    v17 = 0;
    v18 = AIMOVEPUSHSTATUS_PUSH_NONE;
  }
  idAI2::SetMovePushStatus(this: this->ai, newStatus: v18, frameCount: v17);
  v19 = idAIMoveState::ContinueMove(this, totalTravelTime: &v54);
  if ( v19 == 1 )
  {
    this->ai->aiVolatile.memory.movementMaxDuration = 1000000000;
    p_memory = &this->ai->aiVolatile.memory;
    p_memory->movementStartTime = ((int (__fastcall *)(idGameLocal *))gameLocal->GetGameMs)(a1: gameLocal);
    p_memory->movementFailedTime = -1;
    if ( v6 != 1 && gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - lastMoveTime > 100 )
    {
      if ( idAIMoveParms::MovingToEntity(this: &this->moveParms)
        && (*((_BYTE *)(v21 = this->ai)->aiEditable.behaviors.decl + 196) & 1) != 0 )
      {
        v22 = idEntity::GetPhysics(this: v21);
        GoalEntity = (idEntity *)idAIMoveParms::GetGoalEntity(this: &this->moveParms);
        v24 = idEntity::GetPhysics(this: GoalEntity);
        v25 = (float *)v22->GetOrigin(this: v22, a2: 0);
        v26 = (float *)v24->GetOrigin(this: v24, a2: 0);
        v28 = (float)(v26[1] - v25[1]);
        v29 = (float)(v26[2] - v25[2]);
        v30 = (float)(*v26 - *v25);
        ai = this->ai;
        v56.y = v28;
        v56.z = v29;
        v56.x = v30;
        v31 = (float)((float)((float)v30 * (float)v30)
                    + (float)((float)((float)v29 * (float)v29) + (float)((float)v28 * (float)v28)));
        v32 = idEntity::GetPhysics(this: ai);
        v33 = v32->GetGravityNormal(this: v32);
        idVec3::ProjectOntoPlane(this: &v56, normal: v33, overBounce: 1.0);
        idVec3::NormalizeFast(this: &v56);
        v34 = (float)((float)(UNITS_PER_INCH_4 * (float)20.0) * (float)12.0);
        if ( v31 > (float)((float)v34 * (float)v34) )
        {
          v35 = idEntity::GetPhysics(this: this->ai);
          v36 = (float *)v35->GetGravityNormal(this: v35);
          v37 = v36[2];
          v38 = (float)(v36[1] * v56.z);
          v39 = (float)((float)(*v36 * v56.z) - (float)(v36[2] * v56.x));
          v40 = (float)((float)(v36[1] * v56.x) - (float)(*v36 * v56.y));
          v57.z = (float)(v36[1] * v56.x) - (float)(*v36 * v56.y);
          v57.y = v39;
          v41 = (float)((float)((float)v37 * v56.y) - (float)v38);
          v57.x = v41;
          if ( (float)((float)((float)v41 * v56.x) + (float)((float)(v56.z * (float)v40) + (float)(v56.y * (float)v39))) < 0.0 )
          {
            v57.x = -v41;
            v57.y = -v39;
            v57.z = -v40;
          }
          idAIOrientation::SetAxis(this: &this->moveOrientation, ai: this->ai, dir: &v57);
          idAIOrientation::SetIdealDir(this: &this->moveOrientation, ai: this->ai, dir: &v57);
        }
      }
      else
      {
        v42 = idEntity::GetPhysics(this: this->ai);
        v43 = (float *)v42->GetOrigin(this: v42, a2: 0);
        v44 = this->GetNextPoint(this);
        v46 = (float)(v44->z - v43[2]);
        v47 = (float)(v44->y - v43[1]);
        v48 = (float)(v44->x - *v43);
        v45 = this->ai;
        v55.x = v48;
        v55.z = v46;
        v55.y = v47;
        v49 = idEntity::GetPhysics(this: v45);
        v50 = v49->GetGravityNormal(this: v49);
        idVec3::ProjectOntoPlane(this: &v55, normal: v50, overBounce: 1.0);
        idVec3::NormalizeFast(this: &v55);
        if ( (float)((float)(v55.x * v55.x) + (float)((float)(v55.z * v55.z) + (float)(v55.y * v55.y))) < 0.0000010000001 )
        {
          v51 = idEntity::GetPhysics(this: this->ai);
          v52 = (float *)v51->GetAxis(this: v51, a2: 0);
          v55.x = *v52;
          v55.y = v52[1];
          v55.z = v52[2];
        }
        idAIOrientation::SetAxis(this: &this->moveOrientation, ai: this->ai, dir: &v55);
      }
    }
    idAI2::ClearErrorFlags(this: this->ai, flags: 60);
    v19 = 1;
  }
  return idAIMoveState::SetMoveStatus(this, status: v19);
}


// ========================================================================
// `dynamic initializer for 'ai_debugMove''
// EA  : 0x833671A8
// RVA : 0x013671A8
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugMove__()
{
  idCVar::idCVar(
    this: &ai_debugMove,
    name: "ai_debugMove",
    value: "0",
    flags: 2,
    description: "draws movement information for monsters",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugMove__);
}


// ========================================================================
// `dynamic initializer for 'ai_testPaths''
// EA  : 0x83367200
// RVA : 0x01367200
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_testPaths__()
{
  idCVar::idCVar(
    this: &ai_testPaths,
    name: "ai_testPaths",
    value: "0",
    flags: 1,
    description: "set to 1 to use info_paths instead of AAS.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_testPaths__);
}


// ========================================================================
// `dynamic initializer for 'ai_showPath''
// EA  : 0x83367258
// RVA : 0x01367258
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_showPath__()
{
  idCVar::idCVar(
    this: &ai_showPath,
    name: "ai_showPath",
    value: "0",
    flags: 2,
    description: "set to entity number to show AAS path, or -1 to show all paths.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_showPath__);
}


// ========================================================================
// `dynamic initializer for 'ai_avoidObstacles''
// EA  : 0x833672B0
// RVA : 0x013672B0
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_avoidObstacles__()
{
  idCVar::idCVar(
    this: &ai_avoidObstacles,
    name: "ai_avoidObstacles",
    value: "1",
    flags: 1,
    description: "set to 1 to have AI use obstacle avoidance.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_avoidObstacles__);
}


// ========================================================================
// `dynamic initializer for 'ai_useObstacleRoute''
// EA  : 0x83367308
// RVA : 0x01367308
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_useObstacleRoute__()
{
  idCVar::idCVar(
    this: &ai_useObstacleRoute,
    name: "ai_useObstacleRoute",
    value: "1",
    flags: 1,
    description: "set to 1 to have AI use obstacle route.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_useObstacleRoute__);
}


// ========================================================================
// `dynamic initializer for 'ai_forceMoveSpeed''
// EA  : 0x83367360
// RVA : 0x01367360
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_forceMoveSpeed__()
{
  idCVar::idCVar(
    this: &ai_forceMoveSpeed,
    name: "ai_forceMoveSpeed",
    value: "0",
    flags: 4,
    description: "if > 0, force AI movement speeds to this value.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_forceMoveSpeed__);
}


// ========================================================================
// `dynamic initializer for 'ai_turndecay''
// EA  : 0x833673B8
// RVA : 0x013673B8
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_turndecay__()
{
  idCVar::idCVar(
    this: &ai_turndecay,
    name: "ai_turndecay",
    value: "1",
    flags: 4,
    description: "if true, ramp turn rate down as angle between current and ideal direction decreases",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_turndecay__);
}


// ========================================================================
// `dynamic initializer for 'ai_turndecayAng''
// EA  : 0x83367410
// RVA : 0x01367410
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_turndecayAng__()
{
  idCVar::idCVar(
    this: &ai_turndecayAng,
    name: "ai_turndecayAng",
    value: "0",
    flags: 4,
    description: "angle delta must be less than this to decay turn rate",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_turndecayAng__);
}


// ========================================================================
// `dynamic initializer for 'ai_pointTolerance''
// EA  : 0x83367468
// RVA : 0x01367468
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_pointTolerance__()
{
  idCVar::idCVar(
    this: &ai_pointTolerance,
    name: "ai_pointTolerance",
    value: "-1.0f",
    flags: 4,
    description: "the AI must be within this distance of a destination point to consider it reached",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_pointTolerance__);
}


// ========================================================================
// `dynamic initializer for 'ai_useTurningCircles''
// EA  : 0x833674C0
// RVA : 0x013674C0
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_useTurningCircles__()
{
  idCVar::idCVar(
    this: &ai_useTurningCircles,
    name: "ai_useTurningCircles",
    value: "1",
    flags: 2,
    description: "0 = never use turning cirlces\n"
    "1 = use turning circle tangent points if AI's behaviors allow\n"
    "2 = to use turning circles always",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_useTurningCircles__);
}


// ========================================================================
// `dynamic initializer for 'ai_showTurningCircles''
// EA  : 0x83367518
// RVA : 0x01367518
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_showTurningCircles__()
{
  idCVar::idCVar(
    this: &ai_showTurningCircles,
    name: "ai_showTurningCircles",
    value: "0",
    flags: 1,
    description: "true to show turning circle debug info",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_showTurningCircles__);
}


// ========================================================================
// `dynamic initializer for 'ai_turningCircleDebugTime''
// EA  : 0x83367570
// RVA : 0x01367570
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_turningCircleDebugTime__()
{
  idCVar::idCVar(
    this: &ai_turningCircleDebugTime,
    name: "ai_turningCircleDebugTime",
    value: "1",
    flags: 2,
    description: "time in millseconds that turning circle debug lines will persist",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_turningCircleDebugTime__);
}


// ========================================================================
// `dynamic initializer for 'ai_turningCircleAlignmentTolerance''
// EA  : 0x833675C8
// RVA : 0x013675C8
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_turningCircleAlignmentTolerance__()
{
  idCVar::idCVar(
    this: &ai_turningCircleAlignmentTolerance,
    name: "ai_turningCircleAlignmentTolerance",
    value: "0.998629535f",
    flags: 4,
    description: "dot product of AI facing dir vs. end point alignment must be < this to use a turning circle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_turningCircleAlignmentTolerance__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugLerp''
// EA  : 0x83367620
// RVA : 0x01367620
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugLerp__()
{
  idCVar::idCVar(
    this: &ai_debugLerp,
    name: "ai_debugLerp",
    value: "0",
    flags: 2,
    description: "1 = debug movement lerps, 2 = debug movement lerps and show debug info for longer",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugLerp__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugDeltas''
// EA  : 0x83367678
// RVA : 0x01367678
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugDeltas__()
{
  idCVar::idCVar(
    this: &ai_debugDeltas,
    name: "ai_debugDeltas",
    value: "0",
    flags: 2,
    description: "1 = show info for AI animation deltas",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugDeltas__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugReactionBasedMovement''
// EA  : 0x833676D0
// RVA : 0x013676D0
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugReactionBasedMovement__()
{
  idCVar::idCVar(
    this: &ai_debugReactionBasedMovement,
    name: "ai_debugReactionBasedMovement",
    value: "0",
    flags: 2,
    description: "set to 1 for movement obstacles for current ai, 2 for movement for all ai's.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugReactionBasedMovement__);
}


// ========================================================================
// `dynamic initializer for 'ai_checkStuck''
// EA  : 0x83367728
// RVA : 0x01367728
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_checkStuck__()
{
  idCVar::idCVar(
    this: &ai_checkStuck,
    name: "ai_checkStuck",
    value: "1",
    flags: 1,
    description: "set to 0 to skip stuck checks",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_checkStuck__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugStuck''
// EA  : 0x83367780
// RVA : 0x01367780
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugStuck__()
{
  idCVar::idCVar(
    this: &ai_debugStuck,
    name: "ai_debugStuck",
    value: "0",
    flags: 1,
    description: "set to 1 to show check stuck conditions",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugStuck__);
}


// ========================================================================
// `dynamic initializer for 'ai_errorCorrectTurns''
// EA  : 0x833677D8
// RVA : 0x013677D8
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_errorCorrectTurns__()
{
  idCVar::idCVar(
    this: &ai_errorCorrectTurns,
    name: "ai_errorCorrectTurns",
    value: "1",
    flags: 1,
    description: "1 = add addtional turn velocity to turning animations to correct for delta errors error",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_errorCorrectTurns__);
}


// ========================================================================
// `dynamic initializer for 'ai_showMovementTrails''
// EA  : 0x83367830
// RVA : 0x01367830
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_showMovementTrails__()
{
  idCVar::idCVar(
    this: &ai_showMovementTrails,
    name: "ai_showMovementTrails",
    value: "0",
    flags: 2,
    description: "set to 1 to show movement for ai's so you can look for odd paths over time.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_showMovementTrails__);
}


// ========================================================================
// `dynamic initializer for 'ai_cornerCircleRadius''
// EA  : 0x83367888
// RVA : 0x01367888
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_cornerCircleRadius__()
{
  idCVar::idCVar(
    this: &ai_cornerCircleRadius,
    name: "ai_cornerCircleRadius",
    value: "0.0f",
    flags: 4,
    description: "normal distance to circle around corners",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_cornerCircleRadius__);
}


// ========================================================================
// `dynamic initializer for 'ai_minCornerCircleRadius''
// EA  : 0x833678E0
// RVA : 0x013678E0
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_minCornerCircleRadius__()
{
  idCVar::idCVar(
    this: &ai_minCornerCircleRadius,
    name: "ai_minCornerCircleRadius",
    value: "4.0f",
    flags: 4,
    description: "mininim distance to circle around corners",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_minCornerCircleRadius__);
}


// ========================================================================
// `dynamic initializer for 'ai_zeroVelocityFramesBeforeStuck''
// EA  : 0x83367938
// RVA : 0x01367938
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_zeroVelocityFramesBeforeStuck__()
{
  idCVar::idCVar(
    this: &ai_zeroVelocityFramesBeforeStuck,
    name: "ai_zeroVelocityFramesBeforeStuck",
    value: "60",
    flags: 2,
    description: "number of frames with no velocity before ai is considered stuck",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_zeroVelocityFramesBeforeStuck__);
}


// ========================================================================
// `dynamic initializer for 'ai_useStartTransitions''
// EA  : 0x83367990
// RVA : 0x01367990
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_useStartTransitions__()
{
  idCVar::idCVar(
    this: &ai_useStartTransitions,
    name: "ai_useStartTransitions",
    value: "1",
    flags: 1,
    description: "1 = use transitions from stop to moving if they exist",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_useStartTransitions__);
}


// ========================================================================
// `dynamic initializer for 'ai_useStopTransitions''
// EA  : 0x833679E8
// RVA : 0x013679E8
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_useStopTransitions__()
{
  idCVar::idCVar(
    this: &ai_useStopTransitions,
    name: "ai_useStopTransitions",
    value: "0",
    flags: 1,
    description: "1 = use transitions from moving to stopped if they exist",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_useStopTransitions__);
}


// ========================================================================
// `dynamic initializer for 'ai_allowTranstionOvershoot''
// EA  : 0x83367A40
// RVA : 0x01367A40
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_allowTranstionOvershoot__()
{
  idCVar::idCVar(
    this: &ai_allowTranstionOvershoot,
    name: "ai_allowTranstionOvershoot",
    value: "1",
    flags: 1,
    description: "1 = allow AI to play transition that translates farther than the destination",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_allowTranstionOvershoot__);
}


// ========================================================================
// `dynamic initializer for 'ai_alignToPointDist''
// EA  : 0x83367A98
// RVA : 0x01367A98
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_alignToPointDist__()
{
  idCVar::idCVar(
    this: &ai_alignToPointDist,
    name: "ai_alignToPointDist",
    value: "-1.0f",
    flags: 4,
    description: "if > 0 AI will orient to destination point over this distance, if they have a straight path to the dest",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_alignToPointDist__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugPushPlayer''
// EA  : 0x83367AF0
// RVA : 0x01367AF0
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugPushPlayer__()
{
  idCVar::idCVar(
    this: &ai_debugPushPlayer,
    name: "ai_debugPushPlayer",
    value: "0",
    flags: 1,
    description: "1 = show debug push lines to see which way ais are pushing the player.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugPushPlayer__);
}


// ========================================================================
// `dynamic initializer for 'ai_forceMicrotransitions''
// EA  : 0x83367B48
// RVA : 0x01367B48
// PDB : w:\tech5\tungsten\game\ai\aimovestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_forceMicrotransitions__()
{
  idCVar::idCVar(
    this: &ai_forceMicrotransitions,
    name: "ai_forceMicrotransitions",
    value: "0",
    flags: 1,
    description: "1 = only use microtransitions",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_forceMicrotransitions__);
}

