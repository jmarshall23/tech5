
// ========================================================================
// ?GetUsableState@idProp_Zipline@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82D58A48
// RVA : 0x00D58A48
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

usableState_t __fastcall idProp_Zipline::GetUsableState(
        idProp_Zipline *this,
        idPlayer *activator,
        const idFocusTrace *ft)
{
  usableState_t result; // r3

  if ( idPlayer::CastTo(c: activator) == nullptr )
    return USABLE_NOT_USABLE;
  result = USABLE_PROP;
  if ( this->state != ZIPLINE_READY )
    return USABLE_NOT_USABLE;
  return result;
}


// ========================================================================
// ?ModifyCrosshairInfo@idProp_Zipline@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82D58A98
// RVA : 0x00D58A98
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

int __fastcall idProp_Zipline::ModifyCrosshairInfo(
        idProp_Zipline *this,
        const idEntity *activator,
        const idFocusTrace *ft,
        const usableState_t usable,
        idCrosshairInfo *info)
{
  if ( this->state == ZIPLINE_READY )
    return 1;
  info->colorState = CROSSHAIR_COLOR_NEGATIVE;
  return 0;
}


// ========================================================================
// ?OnActivate@idAnimatedInteractable@@UAAXPAVidEntity@@@Z
// EA  : 0x82D58AC0
// RVA : 0x00D58AC0
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idAnimatedInteractable::OnActivate(idAnimatedInteractable *this, idEntity *activator)
{
  this->Use(this, a2: activator, a3: USABLE_PROP);
}


// ========================================================================
// ?WaitForUp@idProp_Zipline@@IAAXXZ
// EA  : 0x82D58C18
// RVA : 0x00D58C18
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::WaitForUp(idProp_Zipline *this)
{
  unsigned int GameMs; // r3
  unsigned int v3; // r11

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v3 = this->waitingStartTime + this->ziplineTimings.waitTime;
  if ( (((((GameMs ^ v3) & 0x80000000) == 0) + (v3 >= GameMs)) & 1) != 0 )
    this->nextState = ZIPLINE_MOVE_UP;
}


// ========================================================================
// ?Up@idProp_Zipline@@IAAXXZ
// EA  : 0x82D58C88
// RVA : 0x00D58C88
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::Up(idProp_Zipline *this)
{
  if ( this->startTime + this->currentMoveTime < idGameTimeManager::GetGameMs(
                                                   this: &clientGame->gameTimeManager,
                                                   type: GAMETIME_SCALED) )
    this->nextState = ZIPLINE_READY;
}


// ========================================================================
// ?StopFX@idProp_Zipline@@AAAXXZ
// EA  : 0x82D58CE8
// RVA : 0x00D58CE8
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::StopFX(idProp_Zipline *this)
{
  idPresentable *presentable; // r30
  int v3; // r3

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v3 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idFXManager::StopAllFX(this: &presentable->fxManager, time: v3, immediateStop: true);
  this->ziplineFXParams.currentSpeedFX = 0;
}


// ========================================================================
// ?GetCurrentVelocity@idProp_Zipline@@QBAXAAVidVec3@@@Z
// EA  : 0x82D58D60
// RVA : 0x00D58D60
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::GetCurrentVelocity(idProp_Zipline *this, idVec3 *vel)
{
  idPhysics *Physics; // r3
  float *v5; // r3
  double v6; // fp7
  double v7; // fp6
  idClientGame *v8; // r11
  double y; // fp1
  double z; // fp12
  __int64 v11; // [sp+50h] [-20h]

  if ( this->ziplinePhysicsParams.usePhysicsDescent )
  {
    *vel = this->ziplinePhysicsParams.curVel;
  }
  else
  {
    Physics = idEntity::GetPhysics(this);
    v5 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v6 = (float)(v5[1] - this->prevHandlePos.y);
    v7 = (float)(v5[2] - this->prevHandlePos.z);
    vel->x = *v5 - this->prevHandlePos.x;
    vel->y = v6;
    v8 = clientGame;
    vel->z = v7;
    v11 = __PAIR64__(
            &off_82040000,
            idGameTimeManager::GetGameMsPerFrame(this: &v8->gameTimeManager, type: GAMETIME_SCALED));
    y = vel->y;
    z = vel->z;
    vel->x = vel->x * (float)((float)1.0 / (float)((float)v11 * (float)0.001));
    vel->y = (float)y * (float)((float)1.0 / (float)((float)v11 * (float)0.001));
    vel->z = (float)z * (float)((float)1.0 / (float)((float)v11 * (float)0.001));
  }
}


// ========================================================================
// ?GetCurrentSpeed@idProp_Zipline@@QBAMXZ
// EA  : 0x82D58E70
// RVA : 0x00D58E70
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

float __fastcall idProp_Zipline::GetCurrentSpeed(idProp_Zipline *this)
{
  double curSpeed; // fp1
  double v5; // fp6
  double v6; // fp12
  idVec3 v8; // [sp+50h] [-20h] BYREF

  if ( this->ziplinePhysicsParams.usePhysicsDescent )
  {
    curSpeed = this->ziplinePhysicsParams.curSpeed;
  }
  else
  {
    idProp_Zipline::GetCurrentVelocity(this, vel: &v8);
    _FP9 = (float)((float)((float)(v8.y * v8.y) + (float)((float)(v8.z * v8.z) + (float)(v8.x * v8.x)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f7, f9, f11, f13 }
    v5 = __frsqrte(_FP7);
    v6 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5
                                                                                       * (float)((float)((float)(v8.y * v8.y) + (float)((float)(v8.z * v8.z) + (float)(v8.x * v8.x)))
                                                                                               * (float)0.5))
                                                                               * (float)v5)
                                                                       - (float)1.5)
                                                       * (float)v5)
                                               * (float)((float)((float)(v8.y * v8.y)
                                                               + (float)((float)(v8.z * v8.z) + (float)(v8.x * v8.x)))
                                                       * (float)0.5))
                                       * (float)((float)-(float)((float)((float)((float)v5
                                                                               * (float)((float)((float)(v8.y * v8.y)
                                                                                               + (float)((float)(v8.z * v8.z) + (float)(v8.x * v8.x)))
                                                                                       * (float)0.5))
                                                                       * (float)v5)
                                                               - (float)1.5)
                                               * (float)v5))
                               - (float)1.5)
               * (float)((float)-(float)((float)((float)((float)v5
                                                       * (float)((float)((float)(v8.y * v8.y)
                                                                       + (float)((float)(v8.z * v8.z)
                                                                               + (float)(v8.x * v8.x)))
                                                               * (float)0.5))
                                               * (float)v5)
                                       - (float)1.5)
                       * (float)v5));
    curSpeed = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)(v8.y * v8.y) + (float)((float)(v8.z * v8.z) + (float)(v8.x * v8.x))) * (float)0.5)) * (float)v5) - (float)1.5) * (float)v5) * (float)((float)((float)(v8.y * v8.y) + (float)((float)(v8.z * v8.z) + (float)(v8.x * v8.x))) * (float)0.5))
                                                                                             * (float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)(v8.y * v8.y) + (float)((float)(v8.z * v8.z) + (float)(v8.x * v8.x))) * (float)0.5)) * (float)v5) - (float)1.5) * (float)v5))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)(v8.y * v8.y) + (float)((float)(v8.z * v8.z) + (float)(v8.x * v8.x))) * (float)0.5)) * (float)v5)
                                                                                             - (float)1.5)
                                                                             * (float)v5))
                                                             * (float)((float)((float)(v8.y * v8.y)
                                                                             + (float)((float)(v8.z * v8.z)
                                                                                     + (float)(v8.x * v8.x)))
                                                                     * (float)0.5))
                                                     * (float)v6)
                                             - (float)1.5)
                             * (float)v6)
                     * (float)((float)(v8.y * v8.y) + (float)((float)(v8.z * v8.z) + (float)(v8.x * v8.x))));
    if ( this->state == ZIPLINE_MOVE_DOWN )
      curSpeed = -curSpeed;
  }
  return *((float *)&curSpeed + 1);
}


// ========================================================================
// ?GetCurrentSplineTime@idProp_Zipline@@IBAMM@Z
// EA  : 0x82D59070
// RVA : 0x00D59070
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

float __fastcall idProp_Zipline::GetCurrentSplineTime(idProp_Zipline *this, double dist)
{
  double curDist; // fp0
  double v4; // fp1
  bool v5; // zf
  idProp_Zipline::ziplineState_t state; // r11
  idCurve_Spline<idVec3> *currentDrawnSpline; // r3
  __int64 v8; // r10
  float *v9; // r7

  curDist = dist;
  v5 = dist >= 0.0;
  v4 = 0.0;
  if ( !v5 )
    curDist = this->ziplinePhysicsParams.curDist;
  state = this->state;
  if ( (unsigned int)state <= ZIPLINE_MOVE_UP )
  {
    switch ( state )
    {
      case ZIPLINE_ANIMATE_TO_ATTACH:
      case ZIPLINE_READY:
LABEL_9:
        if ( this->ziplinePhysicsParams.usePhysicsDescent
          && (currentDrawnSpline = this->currentDrawnSpline)->values.num > 0 )
        {
          v4 = idCurve<idVec3>::EstimateTimeForLength(this: currentDrawnSpline, length: curDist, epsilon: 0.1);
        }
        else
        {
          v4 = *this->currentDrawnSpline->times.list;
        }
        return *((float *)&v4 + 1);
      case ZIPLINE_MOVE_DOWN:
        if ( !this->ziplinePhysicsParams.usePhysicsDescent )
        {
LABEL_18:
          LODWORD(v8) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v4 = (float)v8;
          v9 = &this->currentDrawnSpline->times.list[this->currentDrawnSpline->values.num];
          if ( v4 > *(v9 - 1) )
            v4 = *(v9 - 1);
          return *((float *)&v4 + 1);
        }
        break;
      case ZIPLINE_WAIT_FOR_UP:
        if ( !this->ziplinePhysicsParams.usePhysicsDescent )
        {
          v4 = this->currentDrawnSpline->times.list[this->currentDrawnSpline->values.num - 1];
          return *((float *)&v4 + 1);
        }
        break;
      case ZIPLINE_START_ATTACH:
        goto LABEL_9;
      default:
        goto LABEL_18;
    }
    v4 = idCurve<idVec3>::EstimateTimeForLength(this: this->currentDrawnSpline, length: curDist, epsilon: 0.1);
  }
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?UpdateFX@idProp_Zipline@@EAAXXZ
// EA  : 0x82D59228
// RVA : 0x00D59228
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::UpdateFX(idProp_Zipline *this)
{
  double CurrentSpeed; // fp1
  double fxSpeedLudicrous; // fp11
  int v4; // r26
  double fxSpeedFast; // fp12
  double fxSpeedMed; // fp13
  double fxSpeedSlow; // fp0
  int GameMs; // r3
  idPresentable *presentable; // r11
  int v10; // r29
  idPhysics *Physics; // r29
  idPhysics *v12; // r30
  int v13; // r28
  idPresentable *v14; // r27
  const idMat3 *v15; // r29
  const idVec3 *v16; // r3
  idPhysics *v17; // r3
  int v18; // r3
  char *v19; // r10
  _DWORD *v20; // r11
  int i; // ctr
  idVec3 *v22; // r11
  float y; // r9
  float z; // r8
  idPhysics *v25; // r30
  idPresentable *v26; // r31
  int v27; // r29
  unsigned int v28; // r28
  int v29; // r27
  const idVec3 *v30; // r3
  idVec3 v31; // [sp+60h] [-A0h] BYREF
  idVec3 v32; // [sp+70h] [-90h] BYREF
  float v33[3]; // [sp+80h] [-80h] BYREF
  char v34; // [sp+8Ch] [-74h] BYREF
  idMat3 v35; // [sp+90h] [-70h] BYREF

  if ( this->GetFXDecl(this) != nullptr
    && gameLocal->spawnIds.ptr[this->ownerEntity.spawnId.value & 0x1FFF] == this->ownerEntity.spawnId.value >> 13 )
  {
    CurrentSpeed = idProp_Zipline::GetCurrentSpeed(this);
    fxSpeedLudicrous = this->ziplineFXParams.fxSpeedLudicrous;
    if ( CurrentSpeed >= -fxSpeedLudicrous )
    {
      fxSpeedFast = this->ziplineFXParams.fxSpeedFast;
      if ( CurrentSpeed >= -fxSpeedFast )
      {
        fxSpeedMed = this->ziplineFXParams.fxSpeedMed;
        if ( CurrentSpeed >= -fxSpeedMed )
        {
          fxSpeedSlow = this->ziplineFXParams.fxSpeedSlow;
          if ( CurrentSpeed >= -fxSpeedSlow )
          {
            if ( CurrentSpeed >= fxSpeedSlow )
            {
              if ( CurrentSpeed >= fxSpeedMed )
              {
                if ( CurrentSpeed >= fxSpeedFast )
                {
                  v4 = 120;
                  if ( CurrentSpeed >= fxSpeedLudicrous )
                    v4 = 121;
                }
                else
                {
                  v4 = 119;
                }
              }
              else
              {
                v4 = 118;
              }
            }
            else
            {
              v4 = 0;
            }
          }
          else
          {
            v4 = 122;
          }
        }
        else
        {
          v4 = 123;
        }
      }
      else
      {
        v4 = 124;
      }
    }
    else
    {
      v4 = 125;
    }
    if ( v4 != this->ziplineFXParams.currentSpeedFX )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      presentable = this->presentable;
      v10 = GameMs;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        presentable = this->presentable;
      }
      idFXManager::StopFX(
        this: &presentable->fxManager,
        time: v10,
        stopCondition: this->ziplineFXParams.currentSpeedFX,
        immediateStop: false);
      Physics = idEntity::GetPhysics(this);
      v12 = idEntity::GetPhysics(this);
      v13 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      if ( this->presentable == nullptr )
        idEntity::InitPresentableInternal(this);
      v14 = this->presentable;
      v15 = Physics->GetAxis(this: Physics, a2: 0);
      v16 = v12->GetOrigin(this: v12, a2: 0);
      idFXManager::StartFX(this: &v14->fxManager, org: v16, axis: v15, time: v13, startCondition: v4);
      this->ziplineFXParams.currentSpeedFX = v4;
    }
    idProp_Zipline::GetCurrentVelocity(this, vel: &v32);
    v17 = idEntity::GetPhysics(this);
    v18 = (int)v17->GetAxis(this: v17, a2: 0);
    v19 = &v34;
    v20 = (_DWORD *)(v18 - 4);
    for ( i = 9; i != 0; --i )
    {
      ++v20;
      v19 += 4;
      *(_DWORD *)v19 = *v20;
    }
    if ( idProp_Zipline::GetCurrentSpeed(this) < 0.0 )
    {
      v22 = (idVec3 *)v33;
      v33[0] = -v32.x;
      v33[1] = -v32.y;
      v33[2] = -v32.z;
    }
    else
    {
      v22 = &v32;
    }
    y = v22->y;
    z = v22->z;
    v31.x = v22->x;
    v31.y = y;
    v31.z = z;
    idVec3::NormalizeFast(this: &v31);
    v35.mat[0].x = v31.x;
    v35.mat[0].y = v31.y;
    v35.mat[0].z = v31.z;
    v35.mat[1].z = (float)(v31.x * (float)0.0) - (float)(v31.y * (float)0.0);
    v35.mat[1].x = v31.y - (float)(v31.z * (float)0.0);
    v35.mat[1].y = (float)(v31.z * (float)0.0) - v31.x;
    v25 = idEntity::GetPhysics(this);
    if ( this->presentable == nullptr )
      idEntity::InitPresentableInternal(this);
    v26 = this->presentable;
    v27 = gameLocal->GetGameFrame(this: gameLocal);
    v28 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    v29 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v30 = v25->GetOrigin(this: v25, a2: 0);
    idFXManager::Update(
      this: &v26->fxManager,
      parentOrigin: v30,
      parentAxis: &v35,
      parentVel: &v32,
      time: v29,
      gameMsPerFrame: v28,
      frameNum: v27,
      fovScale: 1.0,
      depthHack: 0.0);
  }
}


// ========================================================================
// ?UpdatePhysicsDescent@idProp_Zipline@@AAAXXZ
// EA  : 0x82D595D8
// RVA : 0x00D595D8
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::UpdatePhysicsDescent(idProp_Zipline *this)
{
  int GameMsPerFrame; // r3
  idProp_Zipline::ziplinePhysicsState_t state; // r11
  double v4; // fp29
  idCurve_Spline<idVec3> *currentDrawnSpline; // r30
  idCurve_Spline<idVec3>_vtbl *v6; // r29
  __int64 v9; // r7
  double v10; // fp1
  int accelerationTimeRemaining; // r11
  double v12; // fp31
  int v13; // r3
  double v14; // fp0
  double maxSpeed; // fp0
  double curSpeed; // fp13
  double v20; // fp11
  double v21; // fp8
  double currentDrawnSplineLength; // fp13
  double brakingDecel; // fp10
  double v24; // fp0
  double v27; // fp11
  double v28; // fp0
  idVec3 v32; // [sp+58h] [-48h] BYREF

  if ( this->ziplinePhysicsParams.state == ZIPLINE_PHYSICS_DONE )
    return;
  GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  state = this->ziplinePhysicsParams.state;
  v4 = (float)((float)__SPAIR64__(&off_82040000, GameMsPerFrame) * (float)0.001);
  if ( state == ZIPLINE_PHYSICS_ACCEL )
  {
    currentDrawnSpline = this->currentDrawnSpline;
    v6 = currentDrawnSpline->__vftable;
    _FP10 = (float)((float)(this->ziplinePhysicsParams.curDist + zipline_physicsDescentLookahead.valueFloat)
                  - this->currentDrawnSplineLength);
    __asm { fsel      f1, f10, f12, f11# length }
    LODWORD(v9) = (int)idCurve<idVec3>::EstimateTimeForLength(this: currentDrawnSpline, length: _FP1, epsilon: 0.1);
    v6->GetCurrentFirstDerivative(
      this: (struct idCurve_Spline<idVec3> *)&v32,
      result: (idVec3 *)currentDrawnSpline,
      a3: (float)v9);
    v10 = idVec3::NormalizeFast(this: &v32);
    accelerationTimeRemaining = this->ziplinePhysicsParams.accelerationTimeRemaining;
    v12 = -(float)((float)__fabs(this->ziplinePhysicsParams.gravity) * v32.z);
    if ( accelerationTimeRemaining != 0 )
    {
      v12 = (float)(this->ziplinePhysicsParams.acceleration + (float)v12);
      if ( accelerationTimeRemaining > 0 )
      {
        v13 = ((int (__fastcall *)(idGameLocal *, int, double))gameLocal->GetGameMsPerFrame)(
                a1: gameLocal,
                a2: 1,
                a3: v10);
        this->ziplinePhysicsParams.accelerationTimeRemaining = ((this->ziplinePhysicsParams.accelerationTimeRemaining == v13)
                                                              + ((unsigned int)(this->ziplinePhysicsParams.accelerationTimeRemaining
                                                                              - v13) >> 31)
                                                              - 1)
                                                             & (this->ziplinePhysicsParams.accelerationTimeRemaining
                                                              - v13);
      }
    }
    v14 = (float)((float)((float)v12 * (float)v4) + this->ziplinePhysicsParams.curSpeed);
    this->ziplinePhysicsParams.curSpeed = (float)((float)v12 * (float)v4) + this->ziplinePhysicsParams.curSpeed;
    if ( v14 <= 0.0 )
    {
      if ( v14 >= 0.0 )
      {
LABEL_11:
        maxSpeed = this->ziplinePhysicsParams.maxSpeed;
        if ( maxSpeed > 0.0 )
        {
          curSpeed = this->ziplinePhysicsParams.curSpeed;
          if ( curSpeed >= -maxSpeed )
          {
            if ( curSpeed <= maxSpeed )
              maxSpeed = this->ziplinePhysicsParams.curSpeed;
          }
          else
          {
            maxSpeed = -maxSpeed;
          }
          this->ziplinePhysicsParams.curSpeed = maxSpeed;
        }
        v20 = (float)(v32.x * this->ziplinePhysicsParams.curSpeed);
        v21 = (float)(v32.y * this->ziplinePhysicsParams.curSpeed);
        this->ziplinePhysicsParams.curVel.z = this->ziplinePhysicsParams.curSpeed * v32.z;
        this->ziplinePhysicsParams.curVel.x = v20;
        this->ziplinePhysicsParams.curVel.y = v21;
        currentDrawnSplineLength = this->currentDrawnSplineLength;
        brakingDecel = this->ziplinePhysicsParams.brakingDecel;
        v24 = this->ziplinePhysicsParams.curSpeed;
        _FP5 = (float)((float)((float)(this->ziplinePhysicsParams.curSpeed * (float)v4)
                             + this->ziplinePhysicsParams.curDist)
                     - this->currentDrawnSplineLength);
        this->ziplinePhysicsParams.curDist = (float)(this->ziplinePhysicsParams.curSpeed * (float)v4)
                                           + this->ziplinePhysicsParams.curDist;
        __asm { fsel      f12, f5, f13, f6 }
        this->ziplinePhysicsParams.curDist = _FP12;
        if ( brakingDecel != 0.0 )
        {
          if ( v24 < 0.0 )
            v27 = _FP12;
          else
            v27 = (float)((float)((float)currentDrawnSplineLength - this->ziplinePathParams.endDist) - (float)_FP12);
          if ( v27 <= (float)((float)((float)((float)v24 / (float)__fabs(brakingDecel)) * (float)v24) * (float)0.5) )
            this->ziplinePhysicsParams.state = ZIPLINE_PHYSICS_DECEL;
        }
        goto LABEL_30;
      }
      _FP11 = (float)((float)((float)__fabs(this->ziplinePhysicsParams.friction) * (float)v4) + (float)v14);
      __asm { fsel      f10, f11, f30, f11 }
    }
    else
    {
      _FP11 = (float)-(float)((float)((float)__fabs(this->ziplinePhysicsParams.friction) * (float)v4) - (float)v14);
      __asm { fsel      f10, f11, f11, f30 }
    }
    this->ziplinePhysicsParams.curSpeed = _FP10;
    goto LABEL_11;
  }
  if ( state == ZIPLINE_PHYSICS_DECEL )
  {
    v28 = this->ziplinePhysicsParams.curSpeed;
    if ( v28 <= 0.0 )
    {
      if ( v28 >= 0.0 )
      {
LABEL_29:
        this->ziplinePhysicsParams.curDist = (float)(this->ziplinePhysicsParams.curSpeed
                                                   * (float)((float)__SPAIR64__(&off_82040000, GameMsPerFrame)
                                                           * (float)0.001))
                                           + this->ziplinePhysicsParams.curDist;
        goto LABEL_30;
      }
      _FP10 = (float)((float)((float)((float)__fabs(this->ziplinePhysicsParams.brakingDecel)
                                    * (float)((float)__SPAIR64__(&off_82040000, GameMsPerFrame) * (float)0.001))
                            + this->ziplinePhysicsParams.curSpeed)
                    - (float)-200.0);
      __asm { fsel      f9, f10, f13, f11 }
    }
    else
    {
      _FP10 = (float)((float)-(float)((float)((float)__fabs(this->ziplinePhysicsParams.brakingDecel)
                                            * (float)((float)__SPAIR64__(&off_82040000, GameMsPerFrame) * (float)0.001))
                                    - this->ziplinePhysicsParams.curSpeed)
                    - (float)200.0);
      __asm { fsel      f9, f10, f11, f13 }
    }
    this->ziplinePhysicsParams.curSpeed = _FP9;
    goto LABEL_29;
  }
LABEL_30:
  if ( this->ziplinePhysicsParams.curDist >= (double)(float)(this->currentDrawnSplineLength
                                                           - this->ziplinePathParams.endDist)
    && this->ziplinePhysicsParams.curSpeed >= 0.0 )
  {
    this->ziplinePhysicsParams.curDist = this->currentDrawnSplineLength - this->ziplinePathParams.endDist;
LABEL_36:
    this->ziplinePhysicsParams.state = ZIPLINE_PHYSICS_DONE;
    return;
  }
  if ( this->ziplinePhysicsParams.curDist <= 0.0 && this->ziplinePhysicsParams.curSpeed < 0.0 )
  {
    this->ziplinePhysicsParams.curDist = 0.0;
    goto LABEL_36;
  }
}


// ========================================================================
// ?UpdateCurrentDrawnSpline@idProp_Zipline@@AAAXM@Z
// EA  : 0x82D59918
// RVA : 0x00D59918
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idProp_Zipline::UpdateCurrentDrawnSpline(idProp_Zipline *this, double percentComplete)
{
  __int64 v3; // r7 OVERLAPPED
  double v5; // fp24
  char *v6; // r10
  double v7; // fp23
  double v8; // fp22
  int *v9; // r31
  int v10; // r11
  double v11; // fp9
  double v12; // fp7
  double v15; // fp1
  double v16; // fp4
  double v17; // fp1
  double v18; // fp27
  double v19; // fp26
  double v20; // fp25
  double v21; // fp11
  double v24; // fp6
  double v25; // fp12
  double v26; // fp24
  double v27; // fp23
  double v28; // fp22
  double v29; // fp21
  double v30; // fp1
  double v31; // fp29
  double v32; // fp20
  double v33; // fp1
  double v34; // fp24
  double v35; // fp23
  double v36; // fp22
  double v37; // fp1
  int currentMoveTime; // r8
  long double v39; // fp2
  long double v40; // fp4
  double v41; // fp30
  double v42; // fp19
  double v43; // fp18
  long double v44; // fp2
  double v45; // fp25
  __int64 v46; // r11
  double v47; // fp26
  double v48; // fp29
  int v49; // r25
  double v50; // fp28
  double v51; // fp27
  int v52; // r29
  int v53; // r23
  int v54; // r24
  float *v55; // r11
  double v56; // fp12
  double v57; // fp7
  double v58; // fp11
  double v59; // fp10
  double v60; // fp12
  double v61; // fp5
  idCurve_Spline<idVec3> *currentDrawnSpline; // r11
  idCurve_Spline<idVec3> *v63; // r9
  float *p_x; // r11
  double v65; // fp0
  double v66; // fp13
  double v67; // fp12
  int valueInteger; // r11
  float *v69; // r11
  double v70; // fp8
  double v71; // fp6
  float *v72; // r11
  double v73; // fp11
  double v74; // fp7
  double v75; // fp5
  double curDist; // fp0
  __int64 v77; // [sp+50h] [-130h]
  float v78; // [sp+58h] [-128h] BYREF
  float v79; // [sp+5Ch] [-124h]
  float v80; // [sp+60h] [-120h]
  float v81[4]; // [sp+68h] [-118h] BYREF
  float v82[34]; // [sp+78h] [-108h] BYREF

  HIDWORD(v3) = 0x82000000;
  v5 = 0.0;
  v6 = (char *)this + 20 * this->currentZipline;
  v7 = 0.0;
  v8 = 0.0;
  v9 = (int *)(v6 + 5852);
  if ( zipline_enableOscillation.valueInteger != 0 )
  {
    v10 = 24 * *((_DWORD *)v6 + 1464) + *v9;
    v11 = (float)(*(float *)(v10 - 24) - *(float *)*v9);
    v12 = (float)(*(float *)(v10 - 20) - *(float *)(*v9 + 4));
    _FP4 = (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f2, f4, f5, f13 }
    v15 = __frsqrte(_FP2);
    v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                        * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))
                                                                                                * (float)0.5))
                                                                                * (float)v15)
                                                                        - (float)1.5)
                                                        * (float)v15)
                                                * (float)((float)((float)((float)v12 * (float)v12)
                                                                + (float)((float)v11 * (float)v11))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v15
                                                                                * (float)((float)((float)((float)v12 * (float)v12)
                                                                                                + (float)((float)v11 * (float)v11))
                                                                                        * (float)0.5))
                                                                        * (float)v15)
                                                                - (float)1.5)
                                                * (float)v15))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v15
                                                        * (float)((float)((float)((float)v12 * (float)v12)
                                                                        + (float)((float)v11 * (float)v11))
                                                                * (float)0.5))
                                                * (float)v15)
                                        - (float)1.5)
                        * (float)v15));
    v17 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                                * (float)v15)
                                                                                        * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                        * (float)v15))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v15
                                                                                                * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)) * (float)0.5))
                                                                                        * (float)v15)
                                                                                - (float)1.5)
                                                                * (float)v15))
                                                * (float)((float)((float)((float)v12 * (float)v12)
                                                                + (float)((float)v11 * (float)v11))
                                                        * (float)0.5))
                                        * (float)v16)
                                - (float)1.5)
                * (float)v16);
    v18 = (float)((float)v17 * (float)(*(float *)(v10 - 20) - *(float *)(*v9 + 4)));
    v19 = (float)((float)v17 * (float)(*(float *)(v10 - 24) - *(float *)*v9));
    v20 = (float)((float)v17 * (float)0.0);
    v21 = -v19;
    _FP9 = (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f7, f9, f10, f13 }
    v24 = __frsqrte(_FP7);
    v25 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24
                                                                                        * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18))
                                                                                                * (float)0.5))
                                                                                * (float)v24)
                                                                        - (float)1.5)
                                                        * (float)v24)
                                                * (float)((float)((float)((float)v21 * (float)v21)
                                                                + (float)((float)v18 * (float)v18))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v24
                                                                                * (float)((float)((float)((float)v21 * (float)v21)
                                                                                                + (float)((float)v18 * (float)v18))
                                                                                        * (float)0.5))
                                                                        * (float)v24)
                                                                - (float)1.5)
                                                * (float)v24))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v24
                                                        * (float)((float)((float)((float)v21 * (float)v21)
                                                                        + (float)((float)v18 * (float)v18))
                                                                * (float)0.5))
                                                * (float)v24)
                                        - (float)1.5)
                        * (float)v24));
    v26 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18)) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24)
                                                                                                * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18)) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18)) * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                                * (float)v24))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18)) * (float)0.5))
                                                                                                * (float)v24)
                                                                                        - (float)1.5)
                                                                        * (float)v24))
                                                        * (float)((float)((float)((float)v21 * (float)v21)
                                                                        + (float)((float)v18 * (float)v18))
                                                                * (float)0.5))
                                                * (float)v25)
                                        - (float)1.5)
                        * (float)v25)
                * (float)v18);
    v27 = (float)((float)v21
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18)) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24)
                                                                                                * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18)) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18)) * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                                * (float)v24))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18)) * (float)0.5))
                                                                                                * (float)v24)
                                                                                        - (float)1.5)
                                                                        * (float)v24))
                                                        * (float)((float)((float)((float)v21 * (float)v21)
                                                                        + (float)((float)v18 * (float)v18))
                                                                * (float)0.5))
                                                * (float)v25)
                                        - (float)1.5)
                        * (float)v25));
    v28 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18)) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24)
                                                                                                * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18)) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18)) * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                                * (float)v24))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18)) * (float)0.5))
                                                                                                * (float)v24)
                                                                                        - (float)1.5)
                                                                        * (float)v24))
                                                        * (float)((float)((float)((float)v21 * (float)v21)
                                                                        + (float)((float)v18 * (float)v18))
                                                                * (float)0.5))
                                                * (float)v25)
                                        - (float)1.5)
                        * (float)v25)
                * (float)0.0);
    v77 = __PAIR64__(
            &off_82040000,
            idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED));
    v29 = (float)((float)((float)v77 * 0.001) * idMath::TWO_PI);
    v30 = idMath::Sin16(a: (float)(this->ziplineOscillationParams.upFreq
                                 * (float)((float)((float)v77 * 0.001) * idMath::TWO_PI)));
    v31 = (float)((float)v30 * this->ziplineOscillationParams.upMag);
    v32 = (float)((float)((float)v30 * this->ziplineOscillationParams.upMag) * (float)0.0);
    v33 = idMath::Sin16(a: (float)(this->ziplineOscillationParams.rtFreq * (float)v29));
    v34 = (float)((float)((float)v33 * this->ziplineOscillationParams.rtMag) * (float)v26);
    v35 = (float)((float)v27 * (float)((float)v33 * this->ziplineOscillationParams.rtMag));
    v36 = (float)((float)v28 * (float)((float)v33 * this->ziplineOscillationParams.rtMag));
    v37 = idMath::Sin16(a: (float)(this->ziplineOscillationParams.fwdFreq * (float)v29));
    v5 = (float)((float)((float)((float)((float)v37 * this->ziplineOscillationParams.fwdMag) * (float)v19) + (float)v34)
               + (float)v32);
    v7 = (float)((float)((float)((float)((float)v37 * this->ziplineOscillationParams.fwdMag) * (float)v18) + (float)v35)
               + (float)v32);
    v8 = (float)((float)((float)((float)v20 * (float)((float)v37 * this->ziplineOscillationParams.fwdMag)) + (float)v36)
               + (float)v31);
  }
  currentMoveTime = this->currentMoveTime;
  LODWORD(v3) = v9[1];
  *((double *)&v39 + 1) = this->ziplinePathParams.splineLerpingPower;
  *((double *)&v40 + 1) = (float)*(__int64 *)((char *)&v3 - 4);
  v41 = 0.0;
  *(double *)&v39 = __fabs((float)((float)((float)percentComplete - (float)0.5) * (float)2.0));
  *(double *)&v40 = (float)((float)v3 - (float)1.0);
  v42 = (float)(idMath::TWO_PI / (float)((float)v3 - (float)1.0));
  v43 = (float)((float)*(__int64 *)((char *)&v3 - 4) / (float)((float)v3 - (float)1.0));
  v44 = pow(x: v39, y: v40);
  v45 = (float)*(double *)&v44;
  LODWORD(v46) = this->startTime;
  v47 = (float)v46;
  this->currentDrawnSpline->SetNumValues(this: this->currentDrawnSpline, a2: v9[1]);
  this->currentDrawnSplineLength = 0.0;
  v48 = 0.0;
  v49 = 0;
  v50 = 0.0;
  v51 = 0.0;
  if ( v9[1] > 0 )
  {
    v52 = 0;
    v53 = 0;
    v54 = 0;
    do
    {
      v55 = (float *)(*v9 + v52);
      v56 = (float)(v55[4] * (float)v45);
      v57 = v55[1];
      v58 = (float)(v55[2] + (float)(v55[5] * (float)v45));
      v59 = (float)(*v55 + (float)(v55[3] * (float)v45));
      v80 = v55[2] + (float)(v55[5] * (float)v45);
      v78 = v59;
      v60 = (float)((float)v57 + (float)v56);
      v79 = v60;
      if ( zipline_enableOscillation.valueInteger != 0 )
      {
        v61 = __fabs((float)(3.1415927 - (float)v41));
        v78 = (float)((float)((float)((float)((float)v61
                                            * (float)((float)(idMath::ONE_OVER_PI * idMath::ONE_OVER_PI) * (float)-4.0))
                                    + (float)(idMath::ONE_OVER_PI * (float)4.0))
                            * (float)(3.1415927 - (float)v41))
                    * (float)v5)
            + (float)v59;
        v79 = (float)((float)v7
                    * (float)((float)((float)((float)v61
                                            * (float)((float)(idMath::ONE_OVER_PI * idMath::ONE_OVER_PI) * (float)-4.0))
                                    + (float)(idMath::ONE_OVER_PI * (float)4.0))
                            * (float)(3.1415927 - (float)v41)))
            + (float)v60;
        v80 = (float)((float)v8
                    * (float)((float)((float)((float)v61
                                            * (float)((float)(idMath::ONE_OVER_PI * idMath::ONE_OVER_PI) * (float)-4.0))
                                    + (float)(idMath::ONE_OVER_PI * (float)4.0))
                            * (float)(3.1415927 - (float)v41)))
            + (float)v58;
      }
      currentDrawnSpline = this->currentDrawnSpline;
      currentDrawnSpline->times.list[v54] = v47;
      currentDrawnSpline->changed = true;
      v63 = this->currentDrawnSpline;
      p_x = &v63->values.list[v53].x;
      *p_x = v78;
      p_x[1] = v79;
      p_x[2] = v80;
      v63->changed = true;
      v65 = v80;
      v66 = v79;
      v67 = v78;
      if ( v49 > 0 )
        this->currentDrawnSplineLength = (float)__fsqrts((float)((float)((float)(v79 - (float)v50)
                                                                       * (float)(v79 - (float)v50))
                                                               + (float)((float)((float)(v78 - (float)v48)
                                                                               * (float)(v78 - (float)v48))
                                                                       + (float)((float)(v80 - (float)v51)
                                                                               * (float)(v80 - (float)v51)))))
                                       + this->currentDrawnSplineLength;
      valueInteger = zipline_debugSplines.valueInteger;
      v48 = v67;
      v50 = v66;
      v51 = v65;
      if ( zipline_debugSplines.valueInteger != 0 )
      {
        if ( zipline_debugSplines.valueInteger == 1 || zipline_debugSplines.valueInteger == 2 )
        {
          clientGame->renderWorld->DebugPoint(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)&idColor::colorRed,
            a3: (const idVec3 *)(*v9 + v52),
            a4: 0,
            a5: false);
          valueInteger = zipline_debugSplines.valueInteger;
        }
        if ( valueInteger == 1 || valueInteger == 3 )
        {
          v69 = (float *)(*v9 + v52);
          v70 = (float)(v69[5] + v69[2]);
          v71 = (float)(v69[4] + v69[1]);
          v81[0] = v69[3] + *v69;
          v81[2] = v70;
          v81[1] = v71;
          clientGame->renderWorld->DebugPoint(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)&idColor::colorGreen,
            a3: (const idVec3 *)v81,
            a4: 0,
            a5: false);
          valueInteger = zipline_debugSplines.valueInteger;
        }
        if ( valueInteger == 1 || valueInteger == 4 )
        {
          v72 = (float *)(*v9 + v52);
          v73 = (float)(v72[4] * (float)v45);
          v74 = v72[1];
          v75 = (float)(v72[2] + (float)(v72[5] * (float)v45));
          v82[0] = *v72 + (float)(v72[3] * (float)v45);
          v82[2] = v75;
          v82[1] = (float)v74 + (float)v73;
          clientGame->renderWorld->DebugPoint(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)&idColor::colorBlue,
            a3: (const idVec3 *)v82,
            a4: 0,
            a5: false);
          valueInteger = zipline_debugSplines.valueInteger;
        }
        if ( valueInteger == 1 || valueInteger == 5 )
          clientGame->renderWorld->DebugPoint(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)&idColor::colorBlue,
            a3: (const idVec3 *)&v78,
            a4: 0,
            a5: false);
      }
      ++v49;
      ++v54;
      v47 = (float)((float)v47 + (float)v43);
      ++v53;
      v41 = (float)((float)v41 + (float)v42);
      v52 += 24;
    }
    while ( v49 < v9[1] );
  }
  curDist = this->ziplinePhysicsParams.curDist;
  if ( curDist >= 0.0 )
  {
    if ( curDist <= this->currentDrawnSplineLength )
      this->ziplinePhysicsParams.curDist = this->ziplinePhysicsParams.curDist;
    else
      this->ziplinePhysicsParams.curDist = this->currentDrawnSplineLength;
  }
  else
  {
    this->ziplinePhysicsParams.curDist = 0.0;
  }
}


// ========================================================================
// ?UpdateCableModel@idProp_Zipline@@AAAXXZ
// EA  : 0x82D59F20
// RVA : 0x00D59F20
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::UpdateCableModel(idProp_Zipline *this)
{
  double CurrentSplineTime; // fp1
  int v3; // r6
  bool v4; // r5

  CurrentSplineTime = idProp_Zipline::GetCurrentSplineTime(
                        this,
                        dist: (float)(this->slackSpring.p1.x * this->ziplinePhysicsParams.curDist));
  idRenderModelZipline::SetSpline(
    this: this->cableModel,
    spline: this->currentDrawnSpline,
    time: CurrentSplineTime,
    fractionBeforeLerp: this->ziplinePathParams.tautFraction,
    downDirection: v4,
    a6: v3,
    a7: (_cntlzw(this->state - 3) & 0x20) != 0);
  idRenderModel::CommitThisFrame(this: this->cableModel);
}


// ========================================================================
// ??1idProp_Zipline@@UAA@XZ
// EA  : 0x82D59FD0
// RVA : 0x00D59FD0
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::~idProp_Zipline(idProp_Zipline *this)
{
  idCurve_Spline<idVec3> *currentDrawnSpline; // r3

  this->__vftable = (idProp_Zipline_vtbl *)&idProp_Zipline::`vftable';
  currentDrawnSpline = this->currentDrawnSpline;
  if ( currentDrawnSpline != nullptr )
  {
    ((void (__fastcall *)(idCurve_Spline<idVec3> *, int))currentDrawnSpline->dtr_idCurve<idVec3>)(
      a1: currentDrawnSpline,
      a2: 1);
    this->currentDrawnSpline = nullptr;
  }
  `eh vector destructor iterator'(
    ptr: this->ziplines,
    size: 0x14u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  idProp_Usable::~idProp_Usable(this);
}


// ========================================================================
// __unwind$494752
// EA  : 0x82D5A060
// RVA : 0x00D5A060
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_494752()
{
  int v0; // r12

  idProp_Usable::~idProp_Usable(this: *(idProp_Usable **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$494753
// EA  : 0x82D5A088
// RVA : 0x00D5A088
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_494753()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 5852),
    size: 0x14u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// ?UpdatePhysicsObject@idProp_Zipline@@QAAXXZ
// EA  : 0x82D5A0C8
// RVA : 0x00D5A0C8
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::UpdatePhysicsObject(idProp_Zipline *this)
{
  __int64 v2; // r9
  double v3; // fp31
  idPhysics *Physics; // r3
  double v7; // fp3
  double v8; // fp6
  double v9; // fp3
  idPhysics *v10; // r3
  idCurve_Spline<idVec3> *currentDrawnSpline; // r4
  __int64 v12; // r6
  double v13; // fp31
  idPhysics *v14; // r3
  idClipModel *v15; // r3
  idMat3 v16; // [sp+58h] [-B8h] BYREF
  idVec3 v17[2]; // [sp+88h] [-88h] BYREF
  idMat3 v18; // [sp+A0h] [-70h] BYREF
  idMat3 v19; // [sp+D0h] [-40h] BYREF

  LODWORD(v2) = (int)idProp_Zipline::GetCurrentSplineTime(this, dist: -1.0);
  v3 = (float)v2;
  ((void (__fastcall *)(float *, double))this->currentDrawnSpline->GetCurrentValue)(a1: &v16.mat[1].y, a2: v3);
  Physics = idEntity::GetPhysics(this);
  Physics->SetOrigin(this: Physics, a2: (const idVec3 *)&v16.mat[1].y, a3: -1);
  ((void (__fastcall *)(idMat3 *, double))this->currentDrawnSpline->GetCurrentFirstDerivative)(a1: &v16, a2: v3);
  _FP6 = (float)((float)((float)(v16.mat[0].x * v16.mat[0].x) + (float)(v16.mat[0].y * v16.mat[0].y))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f4, f6, f7, f12 }
  v7 = __frsqrte(_FP4);
  v8 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v7
                                                                                     * (float)((float)((float)(v16.mat[0].x * v16.mat[0].x) + (float)(v16.mat[0].y * v16.mat[0].y))
                                                                                             * (float)0.5))
                                                                             * (float)v7)
                                                                     - (float)1.5)
                                                     * (float)v7)
                                             * (float)((float)((float)(v16.mat[0].x * v16.mat[0].x)
                                                             + (float)(v16.mat[0].y * v16.mat[0].y))
                                                     * (float)0.5))
                                     * (float)((float)-(float)((float)((float)((float)v7
                                                                             * (float)((float)((float)(v16.mat[0].x * v16.mat[0].x)
                                                                                             + (float)(v16.mat[0].y * v16.mat[0].y))
                                                                                     * (float)0.5))
                                                                     * (float)v7)
                                                             - (float)1.5)
                                             * (float)v7))
                             - (float)1.5)
             * (float)((float)-(float)((float)((float)((float)v7
                                                     * (float)((float)((float)(v16.mat[0].x * v16.mat[0].x)
                                                                     + (float)(v16.mat[0].y * v16.mat[0].y))
                                                             * (float)0.5))
                                             * (float)v7)
                                     - (float)1.5)
                     * (float)v7));
  v9 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v7 * (float)((float)((float)(v16.mat[0].x * v16.mat[0].x) + (float)(v16.mat[0].y * v16.mat[0].y)) * (float)0.5)) * (float)v7) - (float)1.5)
                                                                                             * (float)v7)
                                                                                     * (float)((float)((float)(v16.mat[0].x * v16.mat[0].x) + (float)(v16.mat[0].y * v16.mat[0].y))
                                                                                             * (float)0.5))
                                                                             * (float)((float)-(float)((float)((float)((float)v7 * (float)((float)((float)(v16.mat[0].x * v16.mat[0].x) + (float)(v16.mat[0].y * v16.mat[0].y)) * (float)0.5)) * (float)v7) - (float)1.5)
                                                                                     * (float)v7))
                                                                     - (float)1.5)
                                                     * (float)((float)-(float)((float)((float)((float)v7
                                                                                             * (float)((float)((float)(v16.mat[0].x * v16.mat[0].x) + (float)(v16.mat[0].y * v16.mat[0].y)) * (float)0.5))
                                                                                     * (float)v7)
                                                                             - (float)1.5)
                                                             * (float)v7))
                                             * (float)((float)((float)(v16.mat[0].x * v16.mat[0].x)
                                                             + (float)(v16.mat[0].y * v16.mat[0].y))
                                                     * (float)0.5))
                                     * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v7 * (float)((float)((float)(v16.mat[0].x * v16.mat[0].x) + (float)(v16.mat[0].y * v16.mat[0].y)) * (float)0.5)) * (float)v7) - (float)1.5)
                                                                                     * (float)v7)
                                                                             * (float)((float)((float)(v16.mat[0].x * v16.mat[0].x)
                                                                                             + (float)(v16.mat[0].y * v16.mat[0].y))
                                                                                     * (float)0.5))
                                                                     * (float)((float)-(float)((float)((float)((float)v7 * (float)((float)((float)(v16.mat[0].x * v16.mat[0].x) + (float)(v16.mat[0].y * v16.mat[0].y)) * (float)0.5)) * (float)v7)
                                                                                             - (float)1.5)
                                                                             * (float)v7))
                                                             - (float)1.5)
                                             * (float)((float)-(float)((float)((float)((float)v7
                                                                                     * (float)((float)((float)(v16.mat[0].x * v16.mat[0].x) + (float)(v16.mat[0].y * v16.mat[0].y))
                                                                                             * (float)0.5))
                                                                             * (float)v7)
                                                                     - (float)1.5)
                                                     * (float)v7)))
                             - (float)1.5)
             * (float)v8);
  v16.mat[0].x = v16.mat[0].x * (float)v9;
  v16.mat[0].y = (float)v9 * v16.mat[0].y;
  v16.mat[0].z = (float)v9 * (float)0.0;
  idVec3::ToMat3(this: v19.mat, result: &v16);
  v10 = idEntity::GetPhysics(this);
  v10->SetAxis(this: v10, a2: &v19, a3: -1);
  currentDrawnSpline = this->currentDrawnSpline;
  HIDWORD(v12) = currentDrawnSpline->GetCurrentValue;
  LODWORD(v12) = (int)*currentDrawnSpline->times.list;
  v13 = (float)v12;
  ((void (__fastcall *)(idVec3 *, double))HIDWORD(v12))(a1: v17, a2: v13);
  ((void (__fastcall *)(float *, double))this->currentDrawnSpline->GetCurrentFirstDerivative)(
    a1: &v16.mat[2].z,
    a2: v13);
  idVec3::ToMat3(this: v18.mat, result: (idMat3 *)&v16.mat[2].z);
  idMat3::RotateSelf(this: &v18, axis: &v18.mat[1], angle: idMath::HALF_PI);
  v14 = idEntity::GetPhysics(this);
  v15 = v14->GetClipModel(this: v14, a2: 0);
  idClipModel::SetLinkedPosition(this: v15, newOrigin: v17, newAxis: &v18);
  if ( zipline_debugSplines.valueInteger != 0 )
    clientGame->renderWorld->DebugPoint(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorYellow,
      a3: (const idVec3 *)&v16.mat[1].y,
      a4: 3000,
      a5: false);
}


// ========================================================================
// ?Use@idProp_Zipline@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82D5A318
// RVA : 0x00D5A318
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

int __fastcall idProp_Zipline::Use(idProp_Zipline *this, idPlayer *user, __int32 usable)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPlayer *v8; // r3
  idEntity *v9; // r30
  idPresentable *presentable; // r3
  int v11; // r3
  idPresentable *v12; // r3
  int v13; // r3
  double startDist; // fp0
  int accelerationTime; // r10
  int GameMs; // r3
  int downMoveTime; // r10
  const idSoundShader *sndAttach; // r5
  idMat3 v19; // [sp+50h] [-60h] BYREF

  if ( this->state != ZIPLINE_READY )
    return 0;
  if ( (unsigned __int16)this->eyeJoint.value == 0xFFFF )
  {
    idLib::Warning(fmt: "No Eye joint in idProp_Zipline");
    return 0;
  }
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( (unsigned __int8)idTreeAnimator::GetWorldSpaceJointTransform(
                          this: TreeAnimatorFromPresentable,
                          pose: DRIVER_MODEL,
                          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->eyeJoint.value,
                          origin: &this->attachOrigin,
                          axis: &v19) == 0 )
  {
    idLib::Warning(fmt: "No Tag position in idProp_Zipline::Use");
    return 0;
  }
  if ( user != nullptr )
    this->ownerEntity.spawnId.value = (gameLocal->spawnIds.ptr[user->entityNumber] << 13) | user->entityNumber;
  else
    this->ownerEntity.spawnId.value = 0x1FFF;
  v8 = idPlayer::CastTo(c: user);
  v9 = v8;
  if ( v8 != nullptr )
  {
    if ( zipline_attachPlayer.valueInteger != 0 )
    {
      this->nextState = ZIPLINE_START_ATTACH;
      idPlayer::AddControl(this: v8, entity: this);
      idEntity::Bind(this: user, master: (idWorldspawn *)this, orientated: true);
      idEntity::StopSound(this: v9, channel: SND_CHANNEL_ANY, peerMask: 0xFFu);
      presentable = v9->presentable;
      if ( presentable != nullptr )
        v11 = (int)presentable->GetPlayerInterface_2(this: presentable);
      else
        v11 = 0;
      if ( *(_DWORD *)(v11 + 43684) != 0 )
      {
        v12 = v9->presentable;
        if ( v12 != nullptr )
        {
          v13 = (int)v12->GetPlayerInterface_2(this: v12);
          idHands::DropThrowable(this: (idHands *)(v13 + 37616));
        }
        else
        {
          idHands::DropThrowable(this: (idHands *)0x92F0);
        }
      }
      goto LABEL_21;
    }
    this->ownerEntity.spawnId.value = 0x1FFF;
  }
  startDist = this->ziplinePathParams.startDist;
  this->ziplinePhysicsParams.curSpeed = 0.0;
  this->ziplinePhysicsParams.curDist = startDist;
  this->ziplinePhysicsParams.curVel.z = 0.0;
  this->ziplinePhysicsParams.curVel.y = 0.0;
  this->ziplinePhysicsParams.curVel.x = 0.0;
  accelerationTime = this->ziplinePhysicsParams.accelerationTime;
  this->ziplinePathParams.startDist = 0.0;
  this->ziplinePhysicsParams.state = ZIPLINE_PHYSICS_ACCEL;
  this->ziplinePhysicsParams.accelerationTimeRemaining = accelerationTime;
  this->nextState = ZIPLINE_MOVE_DOWN;
LABEL_21:
  this->speedNextState = ZIPLINE_STARTED;
  this->anglesOffset.roll = 0.0;
  this->anglesOffset.yaw = 0.0;
  this->anglesOffset.pitch = 0.0;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  downMoveTime = this->ziplineTimings.downMoveTime;
  sndAttach = this->ziplineSounds.sndAttach;
  this->startTime = GameMs;
  this->currentZipline = 0;
  this->currentMoveTime = downMoveTime;
  if ( sndAttach != nullptr )
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_ITEM,
      shader: sndAttach,
      soundShaderFlags: (soundShaderFlags_t)(this->soundFlags | 0x400),
      peerMask: 0xFFu);
  idEntity::BecomeActive(this, flags: 1);
  idProp_Usable::Use(this, activator: user, usable);
  return 1;
}


// ========================================================================
// ?StartAttach@idProp_Zipline@@IAAXXZ
// EA  : 0x82D5A580
// RVA : 0x00D5A580
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::StartAttach(idProp_Zipline *this)
{
  int v2; // r11
  int v3; // r10
  int value; // r7
  idEntity *v5; // r3
  idPlayer *v6; // r3
  idPlayer *v7; // r3
  _DWORD *v8; // r28
  idPresentable *presentable; // r3
  int v10; // r3
  int v11; // r3
  int v12; // r3
  int v13; // r3
  int v14; // r3
  int v15; // r9
  idGameLocal *v16; // r11
  idSplinePath *v17; // r3
  idSplinePath *v18; // r3
  int v19; // r9
  float *p_x; // r30
  idSplinePath *v21; // r3
  idSplinePath *v22; // r3
  float *v23; // r11
  double v24; // fp10
  double v25; // fp8
  double v26; // fp6
  double v29; // fp12
  double v30; // fp2
  int v31; // r3
  idQuat *v32; // r11
  int v33; // r3
  int v34; // r3
  float *v35; // r3
  float *v36; // r3
  double v37; // fp4
  double v38; // fp3
  idQuat *v39; // r3
  int accelerationTime; // r7
  double startDist; // fp13
  idMat3 v42[3]; // [sp+50h] [-80h] BYREF

  v2 = this->ziplineTimings.attachAnimationTime
     + idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v3 = this->ziplineTimings.downMoveTime - this->ziplineTimings.dropOffTime;
  this->animationDoneTime = v2;
  this->dropOffStartTime = v3 + v2;
  this->attachStartTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  value = this->ownerEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = (idPlayer *)idEntity::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  v7 = idPlayer::CastTo(c: v6);
  v8 = &v7->__vftable;
  if ( v7 != nullptr )
  {
    presentable = v7->presentable;
    if ( presentable != nullptr )
      v10 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v10 = 0;
    if ( v10 != -37616 )
    {
      v11 = v8[122];
      if ( v11 != 0 )
        v12 = (*(int (__fastcall **)(int))(*(_DWORD *)v11 + 104))(a1: v11);
      else
        v12 = 0;
      idHands::Hide(this: (idHands *)(v12 + 37616), hideReason: HAND_HIDE_GENERIC);
      v13 = v8[122];
      if ( v13 != 0 )
        v14 = (*(int (__fastcall **)(int))(*(_DWORD *)v13 + 104))(a1: v13);
      else
        v14 = 0;
      *(_BYTE *)(v14 + 40605) = 1;
    }
    v15 = this->ziplinePathParams.travelPath.spawnId.value;
    v16 = gameLocal;
    if ( gameLocal->spawnIds.ptr[v15 & 0x1FFF] == v15 >> 13
      && (v17 = (idSplinePath *)gameLocal->entities.ptr[v15 & 0x1FFF]) != nullptr )
    {
      v18 = idSplinePath::CastTo(c: v17);
      v16 = gameLocal;
    }
    else
    {
      v18 = nullptr;
    }
    v19 = this->ziplinePathParams.travelPath.spawnId.value;
    p_x = &v18->controlPoints.list->x;
    if ( v16->spawnIds.ptr[v19 & 0x1FFF] == v19 >> 13
      && (v21 = (idSplinePath *)v16->entities.ptr[v19 & 0x1FFF]) != nullptr )
    {
      v22 = idSplinePath::CastTo(c: v21);
    }
    else
    {
      v22 = nullptr;
    }
    v23 = &v22->controlPoints.list->x;
    v24 = (float)(v23[4] - p_x[1]);
    v25 = (float)(v23[3] - *p_x);
    v26 = (float)(v23[5] - p_x[2]);
    _FP2 = (float)((float)((float)((float)v26 * (float)v26)
                         + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f13, f2, f3, f13 }
    v29 = __frsqrte(_FP13);
    v30 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v29
                                                                                        * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))
                                                                                                * (float)0.5))
                                                                                * (float)v29)
                                                                        - (float)1.5)
                                                        * (float)v29)
                                                * (float)((float)((float)((float)v26 * (float)v26)
                                                                + (float)((float)((float)v25 * (float)v25)
                                                                        + (float)((float)v24 * (float)v24)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v29
                                                                                * (float)((float)((float)((float)v26 * (float)v26)
                                                                                                + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))
                                                                                        * (float)0.5))
                                                                        * (float)v29)
                                                                - (float)1.5)
                                                * (float)v29))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v29
                                                        * (float)((float)((float)((float)v26 * (float)v26)
                                                                        + (float)((float)((float)v25 * (float)v25)
                                                                                + (float)((float)v24 * (float)v24)))
                                                                * (float)0.5))
                                                * (float)v29)
                                        - (float)1.5)
                        * (float)v29));
    v42[0].mat[0].y = (float)v24
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v29 * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5)) * (float)v29) - (float)1.5) * (float)v29) * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v29 * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5)) * (float)v29) - (float)1.5) * (float)v29))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v29 * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5)) * (float)v29)
                                                                                            - (float)1.5)
                                                                            * (float)v29))
                                                            * (float)((float)((float)((float)v26 * (float)v26)
                                                                            + (float)((float)((float)v25 * (float)v25)
                                                                                    + (float)((float)v24 * (float)v24)))
                                                                    * (float)0.5))
                                                    * (float)v30)
                                            - (float)1.5)
                            * (float)v30);
    v42[0].mat[0].x = (float)v25
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v29 * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5)) * (float)v29) - (float)1.5) * (float)v29) * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v29 * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5)) * (float)v29) - (float)1.5) * (float)v29))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v29 * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5)) * (float)v29)
                                                                                            - (float)1.5)
                                                                            * (float)v29))
                                                            * (float)((float)((float)((float)v26 * (float)v26)
                                                                            + (float)((float)((float)v25 * (float)v25)
                                                                                    + (float)((float)v24 * (float)v24)))
                                                                    * (float)0.5))
                                                    * (float)v30)
                                            - (float)1.5)
                            * (float)v30);
    v42[0].mat[0].z = (float)v26
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v29 * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5)) * (float)v29) - (float)1.5) * (float)v29) * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v29 * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5)) * (float)v29) - (float)1.5) * (float)v29))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v29 * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5)) * (float)v29)
                                                                                            - (float)1.5)
                                                                            * (float)v29))
                                                            * (float)((float)((float)((float)v26 * (float)v26)
                                                                            + (float)((float)((float)v25 * (float)v25)
                                                                                    + (float)((float)v24 * (float)v24)))
                                                                    * (float)0.5))
                                                    * (float)v30)
                                            - (float)1.5)
                            * (float)v30);
    v31 = v8[122];
    if ( v31 != 0 )
      v32 = (idQuat *)(*(int (__fastcall **)(int))(*(_DWORD *)v31 + 104))(a1: v31);
    else
      v32 = nullptr;
    this->initialPlayerRot = *idMat3::ToQuat(this: (idMat3 *)&v42[0].mat[1].y, result: v32 + 2909);
    v33 = v8[122];
    if ( v33 != 0 )
      v34 = (*(int (__fastcall **)(int))(*(_DWORD *)v33 + 104))(a1: v33);
    else
      v34 = 0;
    v35 = (float *)(*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)(v34 + 36264) + 64))(a1: v34 + 36264, a2: 0);
    this->initialPlayerPos.x = *v35;
    this->initialPlayerPos.y = v35[1];
    this->initialPlayerPos.z = v35[2];
    v36 = (float *)(*(int (__fastcall **)(float *, _DWORD *))(*v8 + 672))(a1: &v42[0].mat[1].y, a2: v8);
    v37 = (float)(this->attachOrigin.y - v36[1]);
    v38 = (float)(this->attachOrigin.z - v36[2]);
    this->destPlayerPos.x = this->attachOrigin.x - *v36;
    this->destPlayerPos.y = v37;
    this->destPlayerPos.z = v38;
    v39 = (idQuat *)idVec3::ToMat3(this: (idVec3 *)&v42[0].mat[2].z, result: v42);
    this->destPlayerRot = *idMat3::ToQuat(this: (idMat3 *)&v42[0].mat[1].y, result: v39);
  }
  this->nextState = ZIPLINE_ANIMATE_TO_ATTACH;
  this->ziplinePhysicsParams.curSpeed = 0.0;
  this->ziplinePhysicsParams.curVel = vec3_origin;
  this->ziplinePhysicsParams.state = ZIPLINE_PHYSICS_ACCEL;
  accelerationTime = this->ziplinePhysicsParams.accelerationTime;
  startDist = this->ziplinePathParams.startDist;
  this->ziplinePathParams.startDist = 0.0;
  this->ziplinePhysicsParams.curDist = startDist;
  this->ziplinePhysicsParams.accelerationTimeRemaining = accelerationTime;
}


// ========================================================================
// ?AnimateToAttach@idProp_Zipline@@IAAXXZ
// EA  : 0x82D5A988
// RVA : 0x00D5A988
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::AnimateToAttach(idProp_Zipline *this)
{
  int value; // r10
  idEntity *v3; // r3
  idPlayer *v4; // r3
  idPlayer *v5; // r29
  __int128 v6; // r9
  long double v7; // fp4
  long double v8; // fp2
  long double v9; // fp2
  double v10; // fp30
  float z; // r8
  float y; // r6
  float v13; // r5
  float x; // r9
  idPhysics *Physics; // r3
  idPhysics *v16; // r3
  idEventArg *v17; // r26
  idAngles *p_prevViewAngles; // r3
  int valueInteger; // r31
  const char *v20; // r3
  _BYTE v21[20]; // [sp+70h] [-120h] BYREF
  _BYTE v22[20]; // [sp+90h] [-100h] BYREF
  _QWORD v23[4]; // [sp+B0h] [-E0h] BYREF
  _BYTE v24[24]; // [sp+D0h] [-C0h] BYREF
  float v25[6]; // [sp+E8h] [-A8h] BYREF
  idQuat v26; // [sp+100h] [-90h] BYREF
  int v27; // [sp+110h] [-80h]
  char *v28; // [sp+114h] [-7Ch]
  const idEventArg *v29; // [sp+118h] [-78h]
  idEventArg v30; // [sp+130h] [-60h] BYREF

  value = this->ownerEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v4 = (idPlayer *)idEntity::CastTo(c: v3);
  }
  else
  {
    v4 = nullptr;
  }
  v5 = idPlayer::CastTo(c: v4);
  if ( v5 != nullptr )
  {
    LODWORD(v6) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    DWORD2(v6) = this->startTime;
    DWORD1(v6) = this->ziplineTimings.attachAnimationTime;
    *(_QWORD *)v24 = v6;
    v23[0] = *(_QWORD *)&v6;
    *(double *)&v8 = (float)((float)((float)(__int64)v6 - (float)*(__int64 *)((char *)&v6 + 4)) / (float)*(__int64 *)&v6);
    if ( *(double *)&v8 >= 0.0 )
    {
      if ( *(double *)&v8 > 1.0 )
        *(double *)&v8 = 1.0;
    }
    else
    {
      *(double *)&v8 = 0.0;
    }
    *((_QWORD *)&v8 + 1) = 0x4000000000000000LL;
    v9 = pow(x: v8, y: v7);
    v10 = (float)*(double *)&v9;
    idQuat::Slerp(this: &v26, from: &this->initialPlayerRot, to: &this->destPlayerRot, t: v10);
    z = this->initialPlayerPos.z;
    y = this->destPlayerPos.y;
    v13 = this->initialPlayerPos.y;
    x = this->initialPlayerPos.x;
    *(float *)&v24[8] = this->destPlayerPos.z;
    *(float *)&v23[1] = z;
    *(float *)&v24[4] = y;
    *((float *)v23 + 1) = v13;
    *(float *)v24 = this->destPlayerPos.x;
    *(float *)v23 = x;
    v25[0] = (float)((float)(*(float *)v24 - x) * (float)v10) + x;
    v25[1] = (float)((float)(y - v13) * (float)v10) + v13;
    v25[2] = (float)((float)(*(float *)&v24[8] - z) * (float)v10) + z;
    this->prevViewAngles = *idQuat::ToAngles(this: (idQuat *)v24, result: (idAngles *)&v26);
    idPlayer::SetViewAngles(this: v5, angles: &this->prevViewAngles, force: true);
    Physics = idEntity::GetPhysics(this: v5);
    Physics->SetOrigin(this: Physics, a2: (const idVec3 *)v25, a3: -1);
  }
  if ( this->animationDoneTime < idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
  {
    if ( v5 != nullptr )
    {
      v16 = idEntity::GetPhysics(this: v5);
      v16->SetOrigin(this: v16, a2: &this->destPlayerPos, a3: -1);
      this->prevPlayerPos.x = this->destPlayerPos.x;
      this->prevPlayerPos.y = this->destPlayerPos.y;
      this->prevPlayerPos.z = this->destPlayerPos.z;
      *(float *)&v24[4] = 1.0;
      HIBYTE(v23[0]) = 115;
      LODWORD(v23[0]) = "origin";
      v28 = &byte_8200D768;
      v24[0] = 102;
      HIBYTE(v27) = 115;
      v17 = idEventArg::idEventArg(this: &v30, data: this);
      memcpy(Dst: v22, Src: v24, Size: sizeof(v22));
      memcpy(Dst: v21, Src: v23, Size: sizeof(v21));
      idEventReceiver::PostEventMS(
        this: v5,
        ev: &EV_BindToJoint,
        time: *(_DWORD *)&v17->type,
        arg1: (const idEventArg *)LODWORD(v17->value.v[1]),
        arg2: (const idEventArg *)LODWORD(v17->value.v[2]),
        arg3: (const idEventArg *)__ROL4__(v27, 32),
        arg4: v29);
      if ( this->ziplineViewParams.hideHandleWithPlayer )
        this->Hide_2(this);
    }
    this->nextState = ZIPLINE_MOVE_DOWN;
    this->speedNextState = ZIPLINE_STARTED;
  }
  p_prevViewAngles = &this->prevViewAngles;
  valueInteger = zipline_debug.valueInteger;
  v20 = idVec3::ToString(this: p_prevViewAngles, precision: 2);
  idLib::PrintfIf(condition: (_cntlzw(valueInteger - 2) & 0x20) != 0, fmt: "prevViewAngles: %s\n", v20);
}


// ========================================================================
// ?UpdateSounds@idProp_Zipline@@AAAXXZ
// EA  : 0x82D5ACF0
// RVA : 0x00D5ACF0
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::UpdateSounds(idProp_Zipline *this)
{
  idProp_Zipline::ziplinePhysicsState_t state; // r11
  idProp_Zipline::ziplineSpeedState_t v3; // r11
  idProp_Zipline::ziplineSpeedState_t speedNextState; // r11
  double v5; // fp30
  const idSoundShader *sndStart; // r5
  int accelTime; // r11
  const idSoundShader *sndAccel; // r5
  idProp_Zipline::ziplineState_t v9; // r11
  const idSoundShader *sndMoveDown; // r5
  const idSoundShader *sndWind; // r5
  int decelTime; // r11
  const idSoundShader *sndDecel; // r5
  idSoundEmitter *SoundEmitter; // r3
  __int64 v15; // r10
  const idSoundShader *sndStop; // r5
  idProp_Zipline::ziplineSpeedState_t v17; // r11
  double CurrentSpeed; // fp29
  double v19; // fp0
  double v20; // fp0
  double v21; // fp0
  bool v22; // r4
  double maxSpeed; // fp0
  const idDeclTable *sndWindVolumeTable; // r11
  double v25; // fp31
  double v26; // fp29
  const idDeclTable *sndWindPitchTable; // r11
  int value; // r10
  idEntity *v29; // r3
  int v30; // r9
  idEntity *v31; // r3
  idPlayer *v32; // r3
  int v33; // r4
  idPlayer *v34; // r3
  idPresentable *presentable; // r3
  int v36; // r3

  if ( (unsigned int)(this->state - 2) <= 3 )
  {
    if ( this->state != ZIPLINE_READY )
    {
      if ( this->state == ZIPLINE_MOVE_DOWN )
      {
        if ( this->ziplinePhysicsParams.usePhysicsDescent )
        {
          state = this->ziplinePhysicsParams.state;
          if ( state != ZIPLINE_PHYSICS_ACCEL )
          {
            if ( state != ZIPLINE_PHYSICS_DECEL )
            {
LABEL_11:
              v3 = ZIPLINE_CONSTANT_VEL;
              goto LABEL_18;
            }
            v3 = ZIPLINE_DECEL;
          }
          else
          {
            v3 = ZIPLINE_ACCEL;
          }
LABEL_18:
          this->speedNextState = v3;
          goto LABEL_19;
        }
LABEL_12:
        if ( this->ziplineTimings.accelTime + this->startTime > idGameTimeManager::GetGameMs(
                                                                  this: &clientGame->gameTimeManager,
                                                                  type: GAMETIME_SCALED) )
        {
          v3 = ZIPLINE_ACCEL;
          goto LABEL_18;
        }
        if ( this->ziplineTimings.decelTime > 0
          && this->currentMoveTime - this->ziplineTimings.decelTime + this->startTime < idGameTimeManager::GetGameMs(
                                                                                          this: &clientGame->gameTimeManager,
                                                                                          type: GAMETIME_SCALED) )
        {
          v3 = ZIPLINE_DECEL;
          goto LABEL_18;
        }
        goto LABEL_11;
      }
      if ( this->state != ZIPLINE_WAIT_FOR_UP )
        goto LABEL_12;
    }
    v3 = ZIPLINE_STOPPED;
    goto LABEL_18;
  }
LABEL_19:
  speedNextState = this->speedNextState;
  v5 = 0.0;
  if ( speedNextState == this->speedState )
    goto LABEL_46;
  this->speedStateDuration = 0;
  this->speedStateTimeLeft = 0;
  if ( (unsigned int)speedNextState > ZIPLINE_STOPPED )
    goto LABEL_46;
  switch ( speedNextState )
  {
    case ZIPLINE_ACCEL:
      accelTime = this->ziplineTimings.accelTime;
      if ( accelTime > 0 )
      {
        sndAccel = this->ziplineSounds.sndAccel;
        this->speedStateDuration = accelTime;
        this->speedStateTimeLeft = accelTime;
        if ( sndAccel != nullptr )
          idEntity::StartSoundShader(
            this,
            channel: SND_CHANNEL_BODY2,
            shader: sndAccel,
            soundShaderFlags: SSF_PLAY_ONCE,
            peerMask: 0xFFu);
      }
      v9 = this->state;
      if ( v9 == ZIPLINE_MOVE_DOWN )
      {
        sndMoveDown = this->ziplineSounds.sndMoveDown;
      }
      else
      {
        if ( v9 != ZIPLINE_MOVE_UP )
        {
LABEL_36:
          sndWind = this->ziplineSounds.sndWind;
          if ( sndWind != nullptr )
            idEntity::StartSoundShader(
              this,
              channel: SND_CHANNEL_WIND,
              shader: sndWind,
              soundShaderFlags: SSF_LOOPING|SSF_PLAY_ONCE,
              peerMask: 0);
          break;
        }
        sndMoveDown = this->ziplineSounds.sndMoveUp;
      }
      if ( sndMoveDown != nullptr )
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_BODY,
          shader: sndMoveDown,
          soundShaderFlags: SSF_LOOPING|SSF_PLAY_ONCE,
          peerMask: 0xFFu);
      goto LABEL_36;
    case ZIPLINE_CONSTANT_VEL:
      goto LABEL_45;
    case ZIPLINE_DECEL:
      decelTime = this->ziplineTimings.decelTime;
      sndDecel = this->ziplineSounds.sndDecel;
      this->speedStateDuration = decelTime;
      this->speedStateTimeLeft = decelTime;
      if ( sndDecel != nullptr )
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_BODY2,
          shader: sndDecel,
          soundShaderFlags: SSF_PLAY_ONCE,
          peerMask: 0xFFu);
      if ( idEntity::GetSoundEmitter(this, alloc: false) != nullptr )
      {
        SoundEmitter = idEntity::GetSoundEmitter(this, alloc: false);
        HIDWORD(v15) = &unk_82390000;
        LODWORD(v15) = this->ziplineTimings.decelTime;
        ((void (__fastcall *)(idSoundEmitter *, int, double, double, double))SoundEmitter->FadeSound)(
          a1: SoundEmitter,
          a2: 3,
          a3: -60.0,
          a4: (float)((float)v15 * (float)0.001),
          a5: 0.0);
      }
      break;
    case ZIPLINE_STARTED:
      sndStart = this->ziplineSounds.sndStart;
      if ( sndStart != nullptr )
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_BODY3,
          shader: sndStart,
          soundShaderFlags: SSF_PLAY_ONCE,
          peerMask: 0xFFu);
      break;
    default:
      sndStop = this->ziplineSounds.sndStop;
      if ( sndStop != nullptr )
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_BODY3,
          shader: sndStop,
          soundShaderFlags: SSF_PLAY_ONCE,
          peerMask: 0xFFu);
      idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
      if ( this->ziplineTimings.decelTime > 0 )
LABEL_45:
        idEntity::StopSound(this, channel: SND_CHANNEL_BODY2, peerMask: 0xFFu);
      break;
  }
LABEL_46:
  v17 = this->speedNextState;
  this->speedState = v17;
  if ( v17 == ZIPLINE_ACCEL || v17 == ZIPLINE_DECEL )
  {
    CurrentSpeed = idProp_Zipline::GetCurrentSpeed(this);
    v19 = (float)((float)((float)CurrentSpeed - this->ziplineSounds.sndAccelMinVolumeSpeed)
                / (float)(this->ziplineSounds.sndAccelMaxVolumeSpeed - this->ziplineSounds.sndAccelMinVolumeSpeed));
    if ( v19 >= 0.0 )
    {
      if ( v19 > 1.0 )
        v19 = 1.0;
    }
    else
    {
      v19 = 0.0;
    }
    idEntity::SetSoundVolume(
      this,
      channel: SND_CHANNEL_BODY2,
      volume: (float)((float)((float)(this->ziplineSounds.sndAccelMaxVolume - this->ziplineSounds.sndAccelMinVolume) * (float)v19)
            + this->ziplineSounds.sndAccelMinVolume));
    v20 = (float)((float)((float)CurrentSpeed - this->ziplineSounds.sndAccelMinPitchSpeed)
                / (float)(this->ziplineSounds.sndAccelMaxPitchSpeed - this->ziplineSounds.sndAccelMinPitchSpeed));
    if ( v20 >= 0.0 )
    {
      if ( v20 > 1.0 )
        v20 = 1.0;
    }
    else
    {
      v20 = 0.0;
    }
    idEntity::SetSoundPitch(
      this,
      channel: SND_CHANNEL_BODY2,
      pitch: (float)((float)((float)(this->ziplineSounds.sndAccelMaxPitch - this->ziplineSounds.sndAccelMinPitch) * (float)v20)
            + this->ziplineSounds.sndAccelMinPitch));
    v21 = (float)((float)((float)CurrentSpeed - this->ziplineSounds.sndMoveMinVolumeSpeed)
                / (float)(this->ziplineSounds.sndMoveMaxVolumeSpeed - this->ziplineSounds.sndMoveMinVolumeSpeed));
    if ( v21 >= 0.0 )
    {
      if ( v21 > 1.0 )
        v21 = 1.0;
    }
    else
    {
      v21 = 0.0;
    }
    idEntity::SetSoundVolume(
      this,
      channel: SND_CHANNEL_BODY,
      volume: (float)((float)((float)(this->ziplineSounds.sndMoveMaxVolume - this->ziplineSounds.sndMoveMinVolume) * (float)v21)
            + this->ziplineSounds.sndMoveMinVolume));
    maxSpeed = this->ziplinePhysicsParams.maxSpeed;
    if ( maxSpeed <= 0.0 )
      maxSpeed = 1000.0;
    sndWindVolumeTable = this->ziplineSounds.sndWindVolumeTable;
    v25 = (float)((float)CurrentSpeed / (float)maxSpeed);
    if ( sndWindVolumeTable != nullptr )
      v26 = idLookupTable::TableLookup(
              this: sndWindVolumeTable->table,
              time: (float)((float)CurrentSpeed / (float)maxSpeed),
              fastSearch: v22);
    else
      v26 = -60.0;
    sndWindPitchTable = this->ziplineSounds.sndWindPitchTable;
    if ( sndWindPitchTable != nullptr )
      v5 = idLookupTable::TableLookup(this: sndWindPitchTable->table, time: v25, fastSearch: v22);
    if ( this->ziplineSounds.sndWind != nullptr )
    {
      idEntity::SetSoundVolume(this, channel: SND_CHANNEL_WIND, volume: v26);
      idEntity::SetSoundPitch(this, channel: SND_CHANNEL_WIND, pitch: v5);
    }
    value = this->ownerEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v29 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v29 != nullptr && idEntity::CastTo(c: v29) != nullptr )
      {
        v30 = this->ownerEntity.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v30 & 0x1FFF] == v30 >> 13
          && (v31 = gameLocal->entities.ptr[v30 & 0x1FFF]) != nullptr )
        {
          v32 = (idPlayer *)idEntity::CastTo(c: v31);
        }
        else
        {
          v32 = nullptr;
        }
        v34 = idPlayer::CastTo(c: v32);
        if ( v34 != nullptr )
        {
          presentable = v34->presentable;
          if ( presentable != nullptr )
            v36 = (int)presentable->GetPlayerInterface_2(this: presentable);
          else
            v36 = 0;
          idView::SetControllerShake(
            this: (idView *)(v36 + 16224),
            highMagnitude: (float)((float)v25 * (float)0.25),
            highDuration: v33,
            lowMagnitude: (float)((float)v25 * (float)0.1),
            lowDuration: 1);
        }
      }
    }
  }
}


// ========================================================================
// ?ApplyCameraFx@idProp_Zipline@@QAAXXZ
// EA  : 0x82D5B260
// RVA : 0x00D5B260
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::ApplyCameraFx(idProp_Zipline *this)
{
  idProp_Zipline::ziplineSpeedState_t speedState; // r11
  int value; // r10
  idEntity *v4; // r3
  idPlayer *v5; // r3
  __int128 v6; // r11
  idPlayer *v7; // r3
  idPlayer *v8; // r29
  idPresentable *presentable; // r3
  float *v10; // r3
  idView *v11; // r30
  double v12; // fp31
  double v13; // fp12
  double v14; // fp0
  idProp_Zipline::ziplineSpeedState_t v15; // r11
  double maxFov; // fp30
  double v17; // fp1
  double v18; // fp30
  double v19; // fp29
  int valueInteger; // r31
  double v21; // [sp+20h] [-70h]

  speedState = this->speedState;
  if ( speedState != ZIPLINE_STARTED && speedState != ZIPLINE_STOPPED )
  {
    value = this->ownerEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v4 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v5 = (idPlayer *)idEntity::CastTo(c: v4);
    }
    else
    {
      v5 = nullptr;
    }
    v7 = idPlayer::CastTo(c: v5);
    v8 = v7;
    if ( v7 != nullptr )
    {
      presentable = v7->presentable;
      if ( presentable != nullptr )
        v10 = (float *)presentable->GetPlayerInterface_2(this: presentable);
      else
        v10 = nullptr;
      v11 = (idView *)(v10 + 4056);
      v12 = 0.0;
      if ( this->ziplinePhysicsParams.usePhysicsDescent )
      {
        v13 = (float)(this->ziplinePhysicsParams.curSpeed / this->ziplineViewParams.maxSpeedForFx);
        v14 = (float)((float)v13 * (float)v13);
        if ( v14 >= 0.0 )
        {
          v12 = 1.0;
          if ( v14 <= 1.0 )
            v12 = (float)((float)v13 * (float)v13);
        }
        goto LABEL_24;
      }
      v15 = this->speedState;
      if ( v15 == ZIPLINE_ACCEL )
      {
        DWORD2(v6) = this->speedStateDuration;
        if ( SDWORD2(v6) > 0 && this->speedStateTimeLeft > 0 )
        {
          DWORD1(v6) = this->speedStateTimeLeft;
          v12 = (float)(1.0 - (float)((float)*(__int64 *)&v6 / (float)*(__int64 *)((char *)&v6 + 4)));
LABEL_24:
          if ( this->ziplineViewParams.applyCameraShakeFx )
          {
            v10[4782] = v12;
            v10[4784] = this->ziplineViewParams.maxCameraShakeAngle.pitch;
            v10[4785] = this->ziplineViewParams.maxCameraShakeAngle.yaw;
            v10[4786] = this->ziplineViewParams.maxCameraShakeAngle.roll;
          }
          maxFov = this->ziplineViewParams.maxFov;
          v17 = idPlayer::DefaultFov(this: v8);
          v18 = (float)((float)((float)((float)maxFov - (float)v17) * (float)v12) + (float)v17);
          idView::CalcFOV(this: v11, base_fov: v18);
          v19 = this->ziplineViewParams.maxFov;
          valueInteger = zipline_debug.valueInteger;
          v21 = idPlayer::DefaultFov(this: v8);
          idLib::PrintfIf(
            condition: (_cntlzw(valueInteger - 1) & 0x20) != 0,
            fmt: "FOV - default: %.1f, max: %.1f, lerpAmount: %.2f, fov: %.1f\n",
            v21,
            v19,
            v12,
            v18);
          return;
        }
      }
      else if ( v15 == ZIPLINE_DECEL )
      {
        DWORD2(v6) = this->speedStateDuration;
        if ( SDWORD2(v6) > 0 )
        {
          LODWORD(v6) = this->speedStateTimeLeft;
          if ( (int)v6 > 0 )
            v12 = (float)((float)(__int64)v6 / (float)*(__int64 *)((char *)&v6 + 4));
        }
        goto LABEL_24;
      }
      v12 = 1.0;
      goto LABEL_24;
    }
  }
}


// ========================================================================
// ?RemoveCameraFx@idProp_Zipline@@QAAXXZ
// EA  : 0x82D5B4C8
// RVA : 0x00D5B4C8
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::RemoveCameraFx(idProp_Zipline *this)
{
  int value; // r10
  idEntity *v2; // r3
  idPlayer *v3; // r3
  idPlayer *v4; // r3
  idPlayer *v5; // r31
  idPresentable *presentable; // r3
  int v7; // r11
  idPlayer *v8; // r3
  idView *v9; // r31
  double v10; // fp1

  value = this->ownerEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v3 = (idPlayer *)idEntity::CastTo(c: v2);
  }
  else
  {
    v3 = nullptr;
  }
  v4 = idPlayer::CastTo(c: v3);
  v5 = v4;
  if ( v4 != nullptr )
  {
    presentable = v4->presentable;
    if ( presentable != nullptr )
      v7 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v7 = 0;
    v8 = v5;
    v9 = (idView *)(v7 + 16224);
    *(float *)(v7 + 19128) = 0.0;
    v10 = idPlayer::DefaultFov(this: v8);
    idView::CalcFOV(this: v9, base_fov: v10);
  }
}


// ========================================================================
// ?UpdateSway@idProp_Zipline@@AAAXXZ
// EA  : 0x82D5B590
// RVA : 0x00D5B590
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::UpdateSway(idProp_Zipline *this)
{
  int value; // r10
  idEntity *v3; // r3
  idPlayer *v4; // r3
  idPlayer *v5; // r3
  idPresentable *presentable; // r3
  float *v7; // r31
  int GameMs; // r3
  idProp_Zipline::ziplineSpeedState_t speedState; // r10
  float *v10; // r31
  float *v11; // r30
  double v12; // fp30
  double v13; // fp29
  double v14; // fp28
  double v15; // fp27
  double v16; // fp26
  double v17; // fp12
  double v18; // fp13
  double v19; // fp0
  double valueFloat; // fp31
  double v21; // fp13

  value = this->ownerEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v4 = (idPlayer *)idEntity::CastTo(c: v3);
  }
  else
  {
    v4 = nullptr;
  }
  v5 = idPlayer::CastTo(c: v4);
  if ( v5 != nullptr )
  {
    presentable = v5->presentable;
    if ( presentable != nullptr )
    {
      v7 = (float *)presentable->GetPlayerInterface_2(this: presentable);
      if ( v7 != nullptr )
      {
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        speedState = this->speedState;
        v11 = v7 + 4764;
        v12 = v7[4761];
        v13 = v7[4764];
        v14 = v7[4762];
        v15 = v7[4763];
        v16 = v7[4765];
        v10 = v7 + 4761;
        v17 = (float)(idMath::TWO_PI * (float)((float)__SPAIR64__(&off_82040000, GameMs) * (float)0.001));
        if ( speedState == ZIPLINE_STARTED || speedState == ZIPLINE_STOPPED )
        {
          v19 = 0.0;
        }
        else
        {
          if ( speedState == ZIPLINE_ACCEL )
          {
            v18 = 0.0;
            v19 = (float)(this->swayMult + zipline_swayIncrement.valueFloat);
            if ( v19 >= 0.0 )
            {
              v18 = 1.0;
              if ( v19 <= 1.0 )
                goto LABEL_19;
            }
          }
          else
          {
            if ( speedState != ZIPLINE_DECEL )
            {
LABEL_20:
              valueFloat = zipline_swayMag.valueFloat;
              v21 = (float)(idMath::Sin16(a: (float)(zipline_swayFreq.valueFloat * (float)v17)) * this->swayMult);
              *v10 = v12;
              v10[1] = v14;
              v10[2] = v15;
              *v11 = v13;
              v11[1] = v16;
              v11[2] = (float)v21 * (float)valueFloat;
              return;
            }
            v18 = 0.0;
            v19 = (float)(this->swayMult - zipline_swayDecrement.valueFloat);
            if ( v19 >= 0.0 )
            {
              if ( v19 > 1.0 )
                v19 = 1.0;
              goto LABEL_19;
            }
          }
          v19 = v18;
        }
LABEL_19:
        this->swayMult = v19;
        goto LABEL_20;
      }
    }
  }
}


// ========================================================================
// ?ForceCameraToCenter@idProp_Zipline@@AAAXXZ
// EA  : 0x82D5B788
// RVA : 0x00D5B788
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idProp_Zipline::ForceCameraToCenter(idProp_Zipline *this)
{
  int value; // r10
  idEntity *v3; // r3
  idPlayer *v4; // r3
  idPlayer *v5; // r3
  idPlayer *v6; // r26
  idPresentable *presentable; // r3
  int v8; // r11
  int GameMs; // r29
  idPresentable *v10; // r3
  __int64 v11; // r8
  double v12; // fp28
  int v13; // r3
  float *v14; // r3
  double x; // fp13
  double y; // fp12
  double v17; // fp30
  double v18; // fp0
  double pitch; // fp12
  double maxSpeed; // fp31
  __int64 v22; // r8 OVERLAPPED
  double v23; // fp13
  double v24; // fp0
  double v25; // fp10
  int v26; // r9
  double v27; // fp0
  double v28; // fp10
  int v29; // r9
  double v30; // fp0
  double v31; // fp12
  idGameTimeManager *p_gameTimeManager; // r3
  bool v33; // zf
  __int64 v34; // r9 OVERLAPPED
  float v35; // r7
  __int64 v36; // r6 OVERLAPPED
  double v37; // fp9
  float roll; // r4
  double v39; // fp4
  double v40; // fp2
  double maxPitch; // fp13
  double v42; // fp0
  double maxYaw; // fp13
  double yaw; // fp0
  double v45; // fp8
  double v46; // fp0
  idAngles *v47; // r30
  double v48; // fp11
  double v49; // fp11
  double v50; // fp0
  double v51; // fp10
  double z; // fp10
  double v53; // fp0
  double v54; // fp13
  float v55; // r9
  float v56; // r8
  double v57; // fp13
  double v58; // fp4
  double v59; // fp6
  double v60; // fp2
  double v61; // fp0
  double v62; // fp8
  int v63; // r31
  const char *v64; // r29
  const char *v65; // r3
  idAngles *p_prevViewAngles; // r3
  int valueInteger; // r31
  const char *v68; // r3
  float v69; // [sp+50h] [-F0h]
  float v70; // [sp+54h] [-ECh]
  float v71; // [sp+58h] [-E8h]
  idAngles v72; // [sp+60h] [-E0h] BYREF
  idAngles v73; // [sp+70h] [-D0h] BYREF
  idVec3 v74; // [sp+80h] [-C0h] BYREF
  idAngles v75; // [sp+90h] [-B0h] BYREF
  _WORD v76[30]; // [sp+A0h] [-A0h] BYREF

  value = this->ownerEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v4 = (idPlayer *)idEntity::CastTo(c: v3);
  }
  else
  {
    v4 = nullptr;
  }
  v5 = idPlayer::CastTo(c: v4);
  v6 = v5;
  if ( v5 != nullptr )
  {
    presentable = v5->presentable;
    v72 = ang_zero;
    if ( presentable != nullptr )
      v8 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v8 = 0;
    memcpy(Dst: v76, Src: (const void *)(v8 + 46312), Size: sizeof(v76));
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    LODWORD(v11) = GameMs
                 - idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v10 = v6->presentable;
    v12 = (float)((float)((float)v11 * (float)0.001) * this->ziplineViewParams.viewDegreesPerSecond);
    if ( v10 != nullptr )
      v13 = (int)v10->GetPlayerInterface_2(this: v10);
    else
      v13 = 0;
    v14 = (float *)(*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)(v13 + 36264) + 64))(a1: v13 + 36264, a2: 0);
    x = this->prevPlayerPos.x;
    y = this->prevPlayerPos.y;
    v69 = *v14;
    v17 = *v14;
    v70 = v14[1];
    v71 = v14[2];
    v18 = (float)(v71 - this->prevPlayerPos.z);
    v73.roll = v71 - this->prevPlayerPos.z;
    v73.pitch = v69 - (float)x;
    v73.yaw = v70 - (float)y;
    if ( v18 > 0.0 )
      v73.roll = 0.0;
    idVec3::ToAngles(this: &v74, result: &v73);
    pitch = v73.pitch;
    this->prevPlayerPos.x = v17;
    this->prevPlayerPos.y = v70;
    this->prevPlayerPos.z = v71;
    if ( __fabs((float)((float)pitch - vec3_origin.x)) <= 0.0099999998
      && __fabs((float)(v73.yaw - vec3_origin.y)) <= 0.0099999998
      && __fabs((float)(v73.roll - vec3_origin.z)) <= 0.0099999998 )
    {
      this->anglesOffset.pitch = 0.0;
      this->anglesOffset.roll = 0.0;
      p_prevViewAngles = &this->prevViewAngles;
      this->anglesOffset.yaw = 0.0;
      valueInteger = zipline_debug.valueInteger;
      v68 = idVec3::ToString(this: p_prevViewAngles, precision: 2);
      idLib::PrintfIf(condition: (_cntlzw(valueInteger - 2) & 0x20) != 0, fmt: "prevViewAngles: %s\n", v68);
LABEL_69:
      usercmdGen->ClearAngles(this: usercmdGen);
      return;
    }
    if ( this->ziplinePhysicsParams.maxSpeed <= 0.0 )
      maxSpeed = 1000.0;
    else
      maxSpeed = this->ziplinePhysicsParams.maxSpeed;
    if ( (float)(idProp_Zipline::GetCurrentSpeed(this) / (float)maxSpeed) > 0.1 )
    {
      v23 = -v12;
      LODWORD(v22) = v76[5];
      v24 = (float)((float)v22 * (float)0.0054931641);
      if ( v24 >= -v12 )
      {
        if ( v24 > v12 )
          v24 = v12;
      }
      else
      {
        v24 = -v12;
      }
      v25 = (float)(this->anglesOffset.pitch + (float)v24);
      v72.pitch = v24;
      v26 = v76[6];
      this->anglesOffset.pitch = v25;
      v27 = (float)((float)*(__int64 *)((char *)&v22 - 4) * (float)0.0054931641);
      if ( v27 >= v23 )
      {
        if ( v27 > v12 )
          v27 = v12;
      }
      else
      {
        v27 = -v12;
      }
      v28 = (float)((float)v27 + this->anglesOffset.yaw);
      v72.yaw = v27;
      v29 = v76[7];
      this->anglesOffset.yaw = v28;
      v30 = (float)((float)*(__int64 *)((char *)&v22 - 4) * (float)0.0054931641);
      if ( v30 >= v23 )
      {
        if ( v30 > v12 )
          v30 = v12;
      }
      else
      {
        v30 = -v12;
      }
      v31 = (float)(this->anglesOffset.roll + (float)v30);
      v72.roll = v30;
      this->anglesOffset.roll = v31;
    }
    v33 = (unsigned __int8)idAngles::Compare(this: &v72, a: &ang_zero, epsilon: 0.00000011920929) == 0;
    p_gameTimeManager = &clientGame->gameTimeManager;
    if ( v33 )
    {
      startLerpTime = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
    }
    else if ( idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED) - startLerpTime >= this->ziplineViewParams.returnToCenterTime )
    {
      this->anglesOffset.roll = 0.0;
      this->anglesOffset.yaw = 0.0;
      this->anglesOffset.pitch = 0.0;
    }
    else
    {
      LODWORD(v34) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      HIDWORD(v34) = this->ziplineViewParams.returnToCenterTime;
      v35 = this->anglesOffset.pitch;
      LODWORD(v36) = startLerpTime;
      *(_QWORD *)&v72.pitch = v34;
      v37 = (double)v36;
      *(float *)&v36 = this->anglesOffset.yaw;
      roll = this->anglesOffset.roll;
      v39 = (float)(ang_zero.yaw - *(float *)&v36);
      v72.yaw = *(float *)&v36;
      v72.pitch = v35;
      v72.roll = roll;
      v40 = (float)(ang_zero.roll - roll);
      this->anglesOffset.pitch = (float)((float)(ang_zero.pitch - v35)
                                       * (float)((float)((float)v34 - (float)v37) / (float)*(__int64 *)((char *)&v34 + 4)))
                               + v35;
      this->anglesOffset.yaw = (float)((float)v39
                                     * (float)((float)((float)v34 - (float)v37) / (float)*(__int64 *)((char *)&v34 + 4)))
                             + *(float *)&v36;
      this->anglesOffset.roll = (float)((float)v40
                                      * (float)((float)((float)v34 - (float)v37) / (float)*(__int64 *)((char *)&v34 + 4)))
                              + roll;
    }
    maxPitch = this->ziplineViewParams.maxPitch;
    v42 = this->anglesOffset.pitch;
    if ( v42 >= -maxPitch )
    {
      if ( v42 > maxPitch )
        v42 = this->ziplineViewParams.maxPitch;
    }
    else
    {
      v42 = -maxPitch;
    }
    this->anglesOffset.pitch = v42;
    maxYaw = this->ziplineViewParams.maxYaw;
    yaw = this->anglesOffset.yaw;
    if ( yaw >= -maxYaw )
    {
      if ( yaw > maxYaw )
        yaw = this->ziplineViewParams.maxYaw;
    }
    else
    {
      yaw = -maxYaw;
    }
    v45 = v74.x;
    this->anglesOffset.yaw = yaw;
    v46 = (float)((float)v45 - this->prevViewAngles.pitch);
    v47 = &this->prevViewAngles;
    if ( v46 <= 180.0 )
    {
      if ( v46 >= -180.0 )
        goto LABEL_55;
      v48 = (float)(v47->pitch - (float)360.0);
    }
    else
    {
      v48 = (float)(v47->pitch + (float)360.0);
    }
    v47->pitch = v48;
LABEL_55:
    v49 = v74.y;
    v50 = (float)(v74.y - this->prevViewAngles.yaw);
    if ( v50 <= 180.0 )
    {
      if ( v50 >= -180.0 )
        goto LABEL_60;
      v51 = (float)(this->prevViewAngles.yaw - (float)360.0);
    }
    else
    {
      v51 = (float)(this->prevViewAngles.yaw + (float)360.0);
    }
    this->prevViewAngles.yaw = v51;
LABEL_60:
    z = v74.z;
    v53 = (float)(v74.z - this->prevViewAngles.roll);
    if ( v53 <= 180.0 )
    {
      if ( v53 >= -180.0 )
      {
LABEL_65:
        v55 = this->prevViewAngles.yaw;
        v56 = this->prevViewAngles.roll;
        v72.pitch = v47->pitch;
        v72.yaw = v55;
        v72.roll = v56;
        v57 = v72.pitch;
        v58 = (float)((float)((float)z - v56) * zipline_centerLerpPower.valueFloat);
        v59 = (float)((float)((float)v45 - v72.pitch) * zipline_centerLerpPower.valueFloat);
        v60 = (float)((float)((float)((float)v49 - v55) * zipline_centerLerpPower.valueFloat) + v55);
        this->prevViewAngles.yaw = (float)((float)((float)v49 - v55) * zipline_centerLerpPower.valueFloat) + v55;
        this->prevViewAngles.roll = (float)v58 + v56;
        v47->pitch = (float)v59 + (float)v57;
        v61 = (float)(this->anglesOffset.pitch + (float)((float)v59 + (float)v57));
        v62 = (float)(this->anglesOffset.roll + (float)((float)v58 + v56));
        v75.yaw = this->anglesOffset.yaw + (float)v60;
        v75.roll = v62;
        if ( v61 > 85.0 )
          v61 = 85.0;
        v75.pitch = v61;
        idPlayer::SetViewAngles(this: v6, angles: &v75, force: true);
        v63 = zipline_debug.valueInteger;
        v64 = idVec3::ToString(this: (idAngles *)&v74, precision: 2);
        v65 = idVec3::ToString(this: v47, precision: 2);
        idLib::PrintfIf(
          condition: (_cntlzw(v63 - 2) & 0x20) != 0,
          fmt: "prevViewAngles: %s, viewAngles: %s\n",
          v65,
          v64);
        goto LABEL_69;
      }
      v54 = (float)(this->prevViewAngles.roll - (float)360.0);
    }
    else
    {
      v54 = (float)(this->prevViewAngles.roll + (float)360.0);
    }
    this->prevViewAngles.roll = v54;
    goto LABEL_65;
  }
}


// ========================================================================
// ?DetachPlayer@idProp_Zipline@@QAAX_N@Z
// EA  : 0x82D5BEA8
// RVA : 0x00D5BEA8
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::DetachPlayer(idProp_Zipline *this, bool showHands)
{
  int value; // r10
  idEntityPtr<idEntity> *p_ownerEntity; // r28
  idEntity *v6; // r3
  idPlayer *v7; // r3
  idPlayer *v8; // r31
  idPlayer *v9; // r3
  idPresentable *presentable; // r3
  int v11; // r3
  idPresentable *v12; // r3
  idAngles *v13; // r3

  value = this->ownerEntity.spawnId.value;
  p_ownerEntity = &this->ownerEntity;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = (idPlayer *)idEntity::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  v8 = idPlayer::CastTo(c: v7);
  if ( v8 != nullptr && zipline_attachPlayer.valueInteger != 0 )
  {
    if ( showHands )
    {
      v9 = (idPlayer *)idEntityPtr<idEntity const>::operator->(this: p_ownerEntity);
      if ( idPlayer::CastTo(c: v9) != nullptr )
        idEventReceiver::PostEventMS(this: v8, ev: &EV_Carry_ShowHands, time: 600);
    }
    idEntity::Unbind(this: v8);
    idPlayer::RemoveControl(this: v8, entity: this);
    presentable = v8->presentable;
    if ( presentable != nullptr )
      v11 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v11 = 0;
    idUCmdTracker::SetCmdAnglesToView(this: (idUCmdTracker *)(v11 + 45960));
    v12 = v8->presentable;
    if ( v12 != nullptr )
      v13 = (idAngles *)v12->GetPlayerInterface_2(this: v12);
    else
      v13 = nullptr;
    v13[3070] = ang_zero;
    p_ownerEntity->spawnId.value = 0x1FFF;
  }
  idProp_Zipline::StopFX(this);
}


// ========================================================================
// ??0idProp_Zipline@@QAA@XZ
// EA  : 0x82D5C100
// RVA : 0x00D5C100
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

idProp_Zipline *__fastcall idProp_Zipline::idProp_Zipline(idProp_Zipline *this)
{
  idProp_Usable::idProp_Usable(this);
  this->__vftable = (idProp_Zipline_vtbl *)&idProp_Zipline::`vftable';
  this->ziplinePathParams.startMover.spawnId.value = 0x1FFF;
  this->ziplinePathParams.endMover.spawnId.value = 0x1FFF;
  this->ziplinePathParams.endpointMoverDecl = nullptr;
  this->ziplinePathParams.splinePathDef = nullptr;
  this->ziplinePathParams.implicitTravelPath = nullptr;
  this->ziplinePathParams.implicitReversePath = nullptr;
  this->ziplinePathParams.implicitSlackPath = nullptr;
  this->ziplinePathParams.travelPath.spawnId.value = 0x1FFF;
  this->ziplinePathParams.reversePath.spawnId.value = 0x1FFF;
  this->ziplinePathParams.slackPath.spawnId.value = 0x1FFF;
  this->ziplinePathParams.cableMaterial = nullptr;
  this->ziplinePathParams.cableDivisions = 6;
  this->ziplinePathParams.unitsPerSplinePoints = 100;
  this->ziplinePathParams.travelSag = 0.0;
  this->ziplinePathParams.reverseSag = 0.0;
  this->ziplinePathParams.slackSag = 0.0;
  this->ziplinePathParams.splineLerpingPower = 1.5;
  this->ziplinePathParams.diameter = 1.0;
  this->ziplinePathParams.tautFraction = 0.5;
  this->ziplinePathParams.startDist = 0.0;
  this->ziplinePathParams.endDist = 75.0;
  idProp_Zipline::idProp_ZiplineOscillationParams::idProp_ZiplineOscillationParams(this: &this->ziplineOscillationParams);
  this->ziplineSounds.sndAccelMinVolumeSpeed = 0.0;
  this->ziplineSounds.sndAccelMaxVolume = 0.0;
  this->ziplineSounds.sndAccelMinPitchSpeed = 0.0;
  this->ziplineSounds.sndAccelMaxPitch = 0.0;
  this->ziplineSounds.sndMoveMinVolumeSpeed = 0.0;
  this->ziplineSounds.sndAccelMinVolume = -60.0;
  this->ziplineSounds.sndAccelMaxVolumeSpeed = 500.0;
  this->ziplineSounds.sndAccelMinPitch = -60.0;
  this->ziplineSounds.sndAccelMaxPitchSpeed = 500.0;
  this->ziplineSounds.sndMoveMinVolume = -60.0;
  this->ziplineSounds.sndMoveMaxVolume = 0.0;
  this->ziplineSounds.sndMoveMaxVolumeSpeed = 500.0;
  this->ziplineSounds.sndStart = nullptr;
  this->ziplineSounds.sndAccel = nullptr;
  this->ziplineSounds.sndMoveUp = nullptr;
  this->ziplineSounds.sndMoveDown = nullptr;
  this->ziplineSounds.sndWind = nullptr;
  this->ziplineSounds.sndWindVolumeTable = nullptr;
  this->ziplineSounds.sndWindPitchTable = nullptr;
  this->ziplineSounds.sndDecel = nullptr;
  this->ziplineSounds.sndStop = nullptr;
  this->ziplineSounds.sndAttach = nullptr;
  this->ziplineSounds.sndDetach = nullptr;
  this->ziplineFXParams.fxSpeedLudicrous = 400.0;
  this->ziplineFXParams.fxSpeedFast = 200.0;
  this->ziplineFXParams.currentSpeedFX = 0;
  this->ziplineFXParams.fxSpeedSlow = 50.0;
  this->ziplineFXParams.fxSpeedMed = 100.0;
  this->ziplineViewParams.applyCameraShakeFx = false;
  this->ziplineViewParams.returnToCenterTime = 3000;
  this->ziplineViewParams.viewDegreesPerSecond = 180.0;
  this->ziplineViewParams.hideHandleWithPlayer = true;
  this->ziplineViewParams.maxSpeedForFx = 1500.0;
  this->ziplineViewParams.maxFov = 85.0;
  this->ziplineViewParams.maxPitch = 45.0;
  this->ziplineViewParams.maxYaw = 45.0;
  this->ziplineViewParams.fxPower = 1.2;
  this->ziplineViewParams.maxCameraShakeAngle.pitch = 0.0099999998;
  this->ziplineViewParams.maxCameraShakeAngle.yaw = 0.0099999998;
  this->ziplineViewParams.maxCameraShakeAngle.roll = 0.0099999998;
  this->ziplineTimings.downMoveTime = 3000;
  this->ziplineTimings.upMoveTime = 3000;
  this->ziplineTimings.waitTime = 2000;
  this->ziplineTimings.dropOffTime = 500;
  this->ziplineTimings.attachAnimationTime = 500;
  this->ziplineTimings.accelTime = 500;
  this->ziplineTimings.decelTime = 500;
  this->ziplinePhysicsParams.gravity = -750.0;
  this->ziplinePhysicsParams.acceleration = 0.0;
  this->ziplinePhysicsParams.usePhysicsDescent = true;
  this->ziplinePhysicsParams.maxSpeed = 0.0;
  this->ziplinePhysicsParams.accelerationTime = 0;
  this->ziplinePhysicsParams.brakingDecel = 1500.0;
  this->ziplinePhysicsParams.friction = 100.0;
  this->ziplinePhysicsParams.curSpeed = 0.0;
  this->ziplinePhysicsParams.curDist = 0.0;
  this->ziplinePhysicsParams.curVel = vec3_origin;
  this->ziplinePhysicsParams.accelerationTimeRemaining = 0;
  this->ziplinePhysicsParams.state = ZIPLINE_PHYSICS_ACCEL;
  this->ownerEntity.spawnId.value = 0x1FFF;
  this->speedState = ZIPLINE_STOPPED;
  this->speedNextState = ZIPLINE_STOPPED;
  this->state = ZIPLINE_READY;
  this->nextState = ZIPLINE_READY;
  this->speedStateDuration = 0;
  this->speedStateTimeLeft = 0;
  this->soundFlags = 0;
  this->currentMoveTime = -1;
  this->startTime = -1;
  this->attachStartTime = -1;
  this->waitingStartTime = -1;
  this->dropOffStartTime = -1;
  this->animationDoneTime = -1;
  this->manualUpdate = false;
  this->useBufferTime = -1;
  this->eyeJoint.value = -1;
  this->swayMult = 0.0;
  `eh vector constructor iterator'(
    ptr: this->ziplines,
    size: 0x14u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idZipline::idZipline,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  this->currentDrawnSplineLength = 0.0;
  this->currentZipline = 0;
  this->currentDrawnSpline = nullptr;
  this->slackSpring.restLength = 0.0;
  this->slackSpring.k = 1.0;
  this->slackSpring.hasPMin = false;
  this->slackSpring.hasPMax = false;
  this->slackSpring.m = 1.0;
  this->slackSpring.c = 2.0;
  this->slackSpring.p0.x = 0.0;
  this->slackSpring.p1.x = 0.0;
  this->slackSpring.vel.x = 0.0;
  this->slackSpring.maxSpeed = 0.0;
  this->slackSpring.pMin.x = 0.0;
  this->slackSpring.pMax.x = 0.0;
  this->cableModel = nullptr;
  this->attachOrigin.z = 0.0;
  this->attachOrigin.y = 0.0;
  this->attachOrigin.x = 0.0;
  this->anglesOffset.roll = 0.0;
  this->anglesOffset.yaw = 0.0;
  this->anglesOffset.pitch = 0.0;
  this->initialPlayerPos.z = 0.0;
  this->initialPlayerPos.y = 0.0;
  this->initialPlayerPos.x = 0.0;
  this->initialPlayerRot.w = 0.0;
  this->initialPlayerRot.z = 0.0;
  this->initialPlayerRot.y = 0.0;
  this->initialPlayerRot.x = 0.0;
  this->destPlayerPos.z = 0.0;
  this->destPlayerPos.y = 0.0;
  this->destPlayerPos.x = 0.0;
  this->destPlayerRot.w = 0.0;
  this->destPlayerRot.z = 0.0;
  this->destPlayerRot.y = 0.0;
  this->destPlayerRot.x = 0.0;
  this->prevPlayerPos.z = 0.0;
  this->prevPlayerPos.y = 0.0;
  this->prevPlayerPos.x = 0.0;
  this->prevHandlePos.z = 0.0;
  this->prevHandlePos.y = 0.0;
  this->prevHandlePos.x = 0.0;
  this->prevViewAngles.roll = 0.0;
  this->prevViewAngles.yaw = 0.0;
  this->prevViewAngles.pitch = 0.0;
  this->ziplinePathParams.cableDivisions = 6;
  this->ziplinePathParams.unitsPerSplinePoints = 100;
  this->ziplineTimings.downMoveTime = 3000;
  this->ziplineTimings.upMoveTime = 3000;
  this->ziplinePathParams.splineLerpingPower = 1.5;
  this->ziplineTimings.waitTime = 2000;
  this->ziplinePathParams.diameter = 1.0;
  this->ziplineTimings.dropOffTime = 500;
  this->ziplinePathParams.tautFraction = 0.5;
  this->ziplineTimings.attachAnimationTime = 500;
  this->ziplinePhysicsParams.friction = 50.0;
  this->ziplineTimings.accelTime = 500;
  this->ziplinePathParams.travelSag = 0.2;
  this->ziplineTimings.decelTime = 500;
  this->ziplinePathParams.reverseSag = 0.1;
  this->ziplinePhysicsParams.usePhysicsDescent = true;
  this->ziplinePathParams.slackSag = 0.050000001;
  this->ziplinePhysicsParams.state = ZIPLINE_PHYSICS_ACCEL;
  this->ziplinePhysicsParams.curSpeed = 0.0;
  this->ziplinePhysicsParams.curDist = 0.0;
  return this;
}


// ========================================================================
// __unwind$497876
// EA  : 0x82D5C59C
// RVA : 0x00D5C59C
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_497876()
{
  int v0; // r12

  idProp_Usable::~idProp_Usable(this: *(idProp_Usable **)(v0 - 240 + 260));
}


// ========================================================================
// ?Down@idProp_Zipline@@IAAXXZ
// EA  : 0x82D5C628
// RVA : 0x00D5C628
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::Down(idProp_Zipline *this)
{
  int value; // r10
  idEntity *v3; // r3
  idPlayer *v4; // r3
  idPlayer *v5; // r27
  char v6; // r28
  unsigned int GameMs; // r3
  const idSoundShader *sndDetach; // r5
  char v9; // r11
  unsigned int v10; // r3
  unsigned int v11; // r11

  value = this->ownerEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v4 = (idPlayer *)idEntity::CastTo(c: v3);
  }
  else
  {
    v4 = nullptr;
  }
  v5 = idPlayer::CastTo(c: v4);
  if ( this->ziplinePhysicsParams.usePhysicsDescent )
  {
    v6 = (_cntlzw(this->ziplinePhysicsParams.state - 2) & 0x20) != 0;
  }
  else
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v6 = ((((GameMs ^ this->dropOffStartTime) & 0x80000000) == 0) + (this->dropOffStartTime >= GameMs)) & 1;
  }
  if ( v6 != 0 )
  {
    sndDetach = this->ziplineSounds.sndDetach;
    if ( sndDetach != nullptr )
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_ITEM,
        shader: sndDetach,
        soundShaderFlags: (soundShaderFlags_t)(this->soundFlags | 0x400),
        peerMask: 0xFFu);
    if ( v5 != nullptr )
    {
      idProp_Zipline::RemoveCameraFx(this);
      idProp_Zipline::DetachPlayer(this, showHands: true);
    }
    this->waitingStartTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->Show(this);
  }
  if ( this->ziplinePhysicsParams.usePhysicsDescent )
  {
    v9 = v6;
  }
  else
  {
    v10 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v11 = this->startTime + this->currentMoveTime;
    v9 = ((((v10 ^ v11) & 0x80000000) == 0) + (v11 >= v10)) & 1;
  }
  if ( v9 != 0 )
  {
    this->nextState = ZIPLINE_WAIT_FOR_UP;
  }
  else if ( v5 != nullptr )
  {
    idProp_Zipline::ApplyCameraFx(this);
    idProp_Zipline::ForceCameraToCenter(this);
  }
}


// ========================================================================
// ?Draw@idProp_Zipline@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82D5C7D0
// RVA : 0x00D5C7D0
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

int __fastcall idProp_Zipline::Draw(idProp_Zipline *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v5; // r3
  idPresentable *v6; // r11
  idView *v7; // r31
  int v8; // r29
  idPresentable *v9; // r3
  int v10; // r3
  double y; // fp13
  double z; // fp12
  idCommon *v13; // r3
  idVec3 v15; // [sp+50h] [-40h] BYREF

  presentable = player->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = 0;
  v6 = player->presentable;
  v7 = (idView *)(v5 + 16224);
  if ( v6 != nullptr )
    v8 = (int)v6->GetPlayerInterface_2(this: player->presentable);
  else
    v8 = 0;
  v9 = player->presentable;
  if ( v9 != nullptr )
    v10 = (int)v9->GetPlayerInterface_2(this: v9);
  else
    v10 = 0;
  idView::SetViewPos(this: v7, origin: (const idVec3 *)(v10 + 46532), axis: (const idMat3 *)(v8 + 46544));
  idProp_Zipline::GetCurrentVelocity(this, vel: &v15);
  y = v15.y;
  z = v15.z;
  v7->viewVelocity.x = v15.x;
  v7->viewVelocity.y = y;
  v13 = common;
  v7->viewVelocity.z = z;
  if ( !v13->IsGamePaused(this: v13) )
    idProp_Zipline::UpdateSway(this);
  idView::Render(this: v7);
  return 1;
}


// ========================================================================
// ??1idInfoZiplineTarget@@UAA@XZ
// EA  : 0x82D5C8D8
// RVA : 0x00D5C8D8
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idInfoZiplineTarget::~idInfoZiplineTarget(idInfoZiplineTarget *this)
{
  int entityNumber; // r11
  int v3; // r4
  int v4; // r9
  idEntityPtr<idInfoZiplineTarget> *list; // r11

  entityNumber = this->entityNumber;
  this->__vftable = (idInfoZiplineTarget_vtbl *)&idInfoZiplineTarget::`vftable';
  v3 = 0;
  v4 = (gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber;
  if ( idInfoZiplineTarget::ziplineTargets.num > 0 )
  {
    list = idInfoZiplineTarget::ziplineTargets.list;
    while ( list->spawnId.value != v4 )
    {
      ++v3;
      ++list;
      if ( v3 >= idInfoZiplineTarget::ziplineTargets.num )
        goto LABEL_8;
    }
    if ( v3 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(
        this: (idList<idEntityPtr<idEntity>,58> *)&idInfoZiplineTarget::ziplineTargets,
        index: v3);
  }
LABEL_8:
  idEntity::~idEntity(this);
}


// ========================================================================
// ?UpdateImplicitSpline@idProp_Zipline@@AAA_NPAVidSplinePath@@M@Z
// EA  : 0x82D5C980
// RVA : 0x00D5C980
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

int __fastcall idProp_Zipline::UpdateImplicitSpline(idProp_Zipline *this, idSplinePath *splinePath, double sagPercent)
{
  int value; // r10
  idEntity *v7; // r3
  int v8; // r9
  idEntity *v9; // r3
  idEntity *v10; // r31
  idPhysics *Physics; // r3
  float *v12; // r3
  double x; // fp31
  double y; // fp30
  double z; // fp29
  idVec3 *list; // r11
  int v17; // r10
  idEntity *v18; // r3
  int v19; // r9
  idEntity *v20; // r3
  idEntity *v21; // r31
  idPhysics *v22; // r3
  float *v23; // r3
  double v24; // fp28
  double v25; // fp26
  double v26; // fp25
  idVec3 *v27; // r11
  idRenderWorld *v28; // r3
  idRenderWorld *v29; // r3
  int num; // r11
  int v31; // r30
  bool v32; // cr56
  int v33; // r11
  idVec3 *v34; // r10
  bool v35; // r11
  double v36; // fp1
  double v37; // fp6
  char v38; // r9
  bool v39; // r11
  int v40; // r9
  char v41; // r8
  bool v42; // r11
  int v43; // r9
  BOOL v44; // r8
  int v45; // r31
  int v46; // [sp+50h] [-C0h]
  idVec3 *v47; // [sp+54h] [-BCh]
  int v48; // [sp+60h] [-B0h]
  idVec3 *v49; // [sp+64h] [-ACh]
  idVec3 v50; // [sp+70h] [-A0h] BYREF
  float v51[4]; // [sp+80h] [-90h] BYREF
  float v52[22]; // [sp+90h] [-80h] BYREF

  if ( zipline_generateImplicitSplines.valueInteger == 0 )
    return 0;
  value = splinePath->anchorStart.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v7) != nullptr )
  {
    v8 = splinePath->anchorStart.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13 && (v9 = gameLocal->entities.ptr[v8 & 0x1FFF]) != nullptr )
      v10 = idEntity::CastTo(c: v9);
    else
      v10 = nullptr;
    if ( idEntity::GetPhysics(this: v10) != nullptr )
    {
      Physics = idEntity::GetPhysics(this: v10);
      v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      x = *v12;
      y = v12[1];
      z = v12[2];
    }
    else
    {
      x = v10->spawnPosition.x;
      y = v10->spawnPosition.y;
      z = v10->spawnPosition.z;
    }
  }
  else
  {
    list = splinePath->controlPoints.list;
    x = list->x;
    y = list->y;
    z = list->z;
  }
  v17 = splinePath->anchorEnd.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v17 & 0x1FFF] == v17 >> 13
    && (v18 = gameLocal->entities.ptr[v17 & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v18) != nullptr )
  {
    v19 = splinePath->anchorEnd.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v19 & 0x1FFF] == v19 >> 13 && (v20 = gameLocal->entities.ptr[v19 & 0x1FFF]) != nullptr )
      v21 = idEntity::CastTo(c: v20);
    else
      v21 = nullptr;
    if ( idEntity::GetPhysics(this: v21) != nullptr )
    {
      v22 = idEntity::GetPhysics(this: v21);
      v23 = (float *)v22->GetOrigin(this: v22, a2: 0);
      v24 = *v23;
      v25 = v23[1];
      v26 = v23[2];
    }
    else
    {
      v24 = v21->spawnPosition.x;
      v25 = v21->spawnPosition.y;
      v26 = v21->spawnPosition.z;
    }
  }
  else
  {
    v27 = &splinePath->controlPoints.list[splinePath->controlPoints.num];
    v24 = v27[-1].x;
    v25 = v27[-1].y;
    v26 = v27[-1].z;
  }
  if ( zipline_debugImplicitSplines.valueInteger != 0 )
  {
    v28 = gameLocal->GetRenderWorld(this: gameLocal);
    v51[0] = x;
    v51[1] = y;
    v51[2] = z;
    v51[3] = 30.0;
    v28->DebugSphere(
      this: v28,
      a2: (const idVec4 *)&idColor::colorRed,
      a3: (const idSphere *)v51,
      a4: 12,
      a5: 0,
      a6: true);
    v29 = gameLocal->GetRenderWorld(this: gameLocal);
    v52[0] = v24;
    v52[1] = v25;
    v52[2] = v26;
    v52[3] = 30.0;
    v29->DebugSphere(
      this: v29,
      a2: (const idVec4 *)&idColor::colorRed,
      a3: (const idSphere *)v52,
      a4: 12,
      a5: 0,
      a6: true);
  }
  num = splinePath->controlPoints.num;
  v31 = 0;
  v32 = num < 3;
  if ( num > 3 )
  {
    v31 = 1;
    do
    {
      idSplinePath::RemoveControlPoint(this: splinePath, index: 0);
      v33 = splinePath->controlPoints.num;
    }
    while ( v33 > 3 );
    v32 = v33 < 3;
  }
  if ( v32 )
  {
    v31 = 1;
    do
    {
      v50 = vec3_origin;
      idList<idAngles,5>::Append(this: &splinePath->controlPoints, obj: &v50);
    }
    while ( splinePath->controlPoints.num < 3 );
  }
  v34 = splinePath->controlPoints.list;
  v35 = false;
  v36 = __fabs((float)(v34->x - (float)x));
  v50.x = (float)((float)((float)v24 - (float)x) * (float)0.5) + (float)x;
  v50.y = (float)((float)((float)v25 - (float)y) * (float)0.5) + (float)y;
  v37 = (float)((float)__fsqrts((float)((float)((float)((float)v24 - (float)x) * (float)((float)v24 - (float)x))
                                      + (float)((float)((float)((float)v26 - (float)z) * (float)((float)v26 - (float)z))
                                              + (float)((float)((float)v25 - (float)y) * (float)((float)v25 - (float)y)))))
              * (float)sagPercent);
  v50.z = (float)((float)((float)((float)v26 - (float)z) * (float)0.5) + (float)z) + (float)-v37;
  if ( v36 <= 0.1 && __fabs((float)(v34->y - (float)y)) <= 0.1 )
    v35 = __fabs((float)(v34->z - (float)z)) <= 0.1;
  v38 = _cntlzw(v35);
  v39 = false;
  v40 = ((v38 & 0x20) != 0) | v31;
  if ( __fabs((float)(v34[1].x - (float)((float)((float)((float)v24 - (float)x) * (float)0.5) + (float)x))) <= 0.1
    && __fabs((float)(v34[1].y - (float)((float)((float)((float)v25 - (float)y) * (float)0.5) + (float)y))) <= 0.1 )
  {
    v39 = __fabs((float)(v34[1].z
                       - (float)((float)((float)((float)((float)v26 - (float)z) * (float)0.5) + (float)z) + (float)-v37))) <= 0.1;
  }
  v41 = _cntlzw(v39);
  v42 = false;
  v43 = ((v41 & 0x20) != 0) | v40;
  if ( __fabs((float)(v34[2].x - (float)v24)) <= 0.1 && __fabs((float)(v34[2].y - (float)v25)) <= 0.1 )
    v42 = __fabs((float)(v34[2].z - (float)v26)) <= 0.1;
  v44 = (_cntlzw(v42) & 0x20) != 0;
  v45 = v44 | v43;
  if ( (v44 | (unsigned __int8)v43) != 0 )
  {
    *(float *)&v46 = x;
    *(float *)&v47 = y;
    idSplinePath::SetControlPoint(this: splinePath, index: v46, point: v47);
    idSplinePath::SetControlPoint(this: splinePath, index: SLODWORD(v50.x), point: (idVec3 *)LODWORD(v50.y));
    *(float *)&v48 = v24;
    *(float *)&v49 = v25;
    idSplinePath::SetControlPoint(this: splinePath, index: v48, point: v49);
  }
  return v45;
}


// ========================================================================
// ?BuildImplicitSpline@idProp_Zipline@@AAAPAVidSplinePath@@PAVidMover@@0M@Z
// EA  : 0x82D5CF08
// RVA : 0x00D5CF08
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

idSplinePath *__fastcall idProp_Zipline::BuildImplicitSpline(
        idProp_Zipline *this,
        idMover *startMover,
        idMover *endMover,
        double sagPercent)
{
  int value; // r10
  idMover *v8; // r3
  idSplinePath *v9; // r3
  idSplinePath *v10; // r3
  idSplinePath *v11; // r31
  idPhysics *Physics; // r3
  float *v14; // r3
  double x; // fp31
  double y; // fp30
  double z; // fp29
  idPhysics *v18; // r3
  float *v19; // r3
  double v20; // fp27
  double v21; // fp26
  double v22; // fp25
  idRenderWorld *v23; // r3
  idRenderWorld *v24; // r3
  int num; // r11
  bool v26; // cr56
  int v27; // r11
  int v28; // [sp+50h] [-D0h]
  idVec3 *v29; // [sp+54h] [-CCh]
  int v30; // [sp+60h] [-C0h]
  idVec3 *v31; // [sp+64h] [-BCh]
  idVec3 v32; // [sp+70h] [-B0h] BYREF
  float v33[4]; // [sp+80h] [-A0h] BYREF
  float v34[22]; // [sp+90h] [-90h] BYREF

  if ( zipline_generateImplicitSplines.valueInteger == 0 )
    return nullptr;
  if ( this->ziplinePathParams.splinePathDef == nullptr )
    return nullptr;
  value = this->ziplinePathParams.startMover.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return nullptr;
  v8 = (idMover *)gameLocal->entities.ptr[value & 0x1FFF];
  if ( v8 == nullptr
    || idMover::CastTo(c: v8) == nullptr
    || idEntityPtr<idMover>::GetEntity(this: &this->ziplinePathParams.endMover) == nullptr )
  {
    return nullptr;
  }
  v9 = (idSplinePath *)gameLocal->SpawnEntityFromDef(
                         this: gameLocal,
                         a2: this->ziplinePathParams.splinePathDef,
                         a3: -1,
                         a4: -1,
                         a5: -1);
  v10 = idSplinePath::CastTo(c: v9);
  v11 = v10;
  if ( v10 == nullptr )
  {
    idLib::Warning(
      fmt: "%s - unable to build implicit spline using <%s>",
      "idProp_Zipline::BuildImplicitSpline",
      this->ziplinePathParams.splinePathDef->name.str);
    return nullptr;
  }
  if ( startMover != nullptr )
    v10->anchorStart.spawnId.value = (gameLocal->spawnIds.ptr[startMover->entityNumber] << 13)
                                   | startMover->entityNumber;
  else
    v10->anchorStart.spawnId.value = 0x1FFF;
  if ( idEntity::GetPhysics(this: startMover) != nullptr )
  {
    Physics = idEntity::GetPhysics(this: startMover);
    v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    x = *v14;
    y = v14[1];
    z = v14[2];
  }
  else
  {
    x = startMover->spawnPosition.x;
    y = startMover->spawnPosition.y;
    z = startMover->spawnPosition.z;
  }
  if ( endMover != nullptr )
    v11->anchorEnd.spawnId.value = (gameLocal->spawnIds.ptr[endMover->entityNumber] << 13) | endMover->entityNumber;
  else
    v11->anchorEnd.spawnId.value = 0x1FFF;
  if ( idEntity::GetPhysics(this: endMover) != nullptr )
  {
    v18 = idEntity::GetPhysics(this: endMover);
    v19 = (float *)v18->GetOrigin(this: v18, a2: 0);
    v20 = *v19;
    v21 = v19[1];
    v22 = v19[2];
  }
  else
  {
    v20 = endMover->spawnPosition.x;
    v21 = endMover->spawnPosition.y;
    v22 = endMover->spawnPosition.z;
  }
  if ( zipline_debugImplicitSplines.valueInteger != 0 )
  {
    v23 = gameLocal->GetRenderWorld(this: gameLocal);
    v33[0] = x;
    v33[1] = y;
    v33[2] = z;
    v33[3] = 30.0;
    v23->DebugSphere(
      this: v23,
      a2: (const idVec4 *)&idColor::colorRed,
      a3: (const idSphere *)v33,
      a4: 12,
      a5: 0,
      a6: true);
    v24 = gameLocal->GetRenderWorld(this: gameLocal);
    v34[0] = v20;
    v34[1] = v21;
    v34[2] = v22;
    v34[3] = 30.0;
    v24->DebugSphere(
      this: v24,
      a2: (const idVec4 *)&idColor::colorRed,
      a3: (const idSphere *)v34,
      a4: 12,
      a5: 0,
      a6: true);
  }
  num = v11->controlPoints.num;
  v26 = num < 3;
  if ( num > 3 )
  {
    do
    {
      idSplinePath::RemoveControlPoint(this: v11, index: 0);
      v27 = v11->controlPoints.num;
    }
    while ( v27 > 3 );
    v26 = v27 < 3;
  }
  if ( v26 )
  {
    do
    {
      v32 = vec3_origin;
      idList<idAngles,5>::Append(this: &v11->controlPoints, obj: &v32);
    }
    while ( v11->controlPoints.num < 3 );
  }
  *(float *)&v28 = x;
  *(float *)&v29 = y;
  idSplinePath::SetControlPoint(this: v11, index: v28, point: v29);
  idSplinePath::SetControlPoint(
    this: v11,
    index: COERCE_INT((float)((float)((float)v20 - (float)x) * (float)0.5) + (float)x),
    point: COERCE_IDVEC3_((float)((float)((float)v21 - (float)y) * (float)0.5) + (float)y));
  *(float *)&v30 = v20;
  *(float *)&v31 = v21;
  idSplinePath::SetControlPoint(this: v11, index: v30, point: v31);
  return v11;
}


// ========================================================================
// ?SetupZiplineFromSplines@idProp_Zipline@@AAAXAAVidZipline@@PAV?$idCurve_Spline@VidVec3@@@@1_N@Z
// EA  : 0x82D5D3E8
// RVA : 0x00D5D3E8
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idProp_Zipline::SetupZiplineFromSplines(
        idProp_Zipline *this,
        idList<eboltControlNode_t,5> *zipline,
        idCurve_Spline<idVec3> *spline,
        idCurve_Spline<idVec3> *slackSpline,
        bool slackDown)
{
  int v5; // r2 OVERLAPPED
  idVec3 *list; // r11
  float z; // r9
  idVec3 *v11; // r10
  __int128 v13; // r10
  int unitsPerSplinePoints; // r3
  __int64 v15; // fp12
  int z_low; // r6
  int x_low; // r5
  float y; // r11
  double v22; // fp1
  double v23; // fp2
  int v26; // r27
  double v27; // fp31
  __int64 v28; // r10
  int v29; // r7
  int v30; // r6
  int v31; // r5
  int v32; // r4
  double v33; // fp30
  int size; // r11
  int v35; // r29
  BOOL v36; // r25
  int v37; // r30
  double v38; // fp1
  idZiplinePoint *v39; // r11
  double v40; // fp9
  idZiplinePoint *v41; // r11
  double v42; // fp8
  double v43; // fp3
  idZiplinePoint *v44; // r11
  __int64 v45; // [sp+50h] [-80h] BYREF
  float v46; // [sp+58h] [-78h]
  float v47; // [sp+60h] [-70h] BYREF
  float v48; // [sp+64h] [-6Ch]
  float v49; // [sp+68h] [-68h]

  list = spline->values.list;
  z = list->z;
  v11 = &list[spline->values.num];
  DWORD1(v13) = LODWORD(list->x);
  unitsPerSplinePoints = this->ziplinePathParams.unitsPerSplinePoints;
  *(float *)&v13 = list->y;
  v45 = *(_QWORD *)(&v5 - 1);
  v15 = *(_QWORD *)(&v5 - 1);
  z_low = SLODWORD(v11[-1].z);
  v46 = z;
  x_low = SLODWORD(v11[-1].x);
  HIDWORD(v45) = DWORD1(v13);
  y = v11[-1].y;
  v49 = *(float *)&z_low;
  v47 = *(float *)&x_low;
  v48 = y;
  LODWORD(v13) = 0x82000000;
  _FP4 = (float)((float)((float)((float)(*(float *)&x_low - *((float *)&v13 + 1))
                               * (float)(*(float *)&x_low - *((float *)&v13 + 1)))
                       + (float)((float)((float)(*(float *)&z_low - z) * (float)(*(float *)&z_low - z))
                               + (float)((float)(y - *(float *)&v13) * (float)(y - *(float *)&v13))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f4, f5, f13 }
  v22 = __frsqrte(_FP2);
  v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                      * (float)((float)((float)((float)(*(float *)&x_low - *((float *)&v13 + 1)) * (float)(*(float *)&x_low - *((float *)&v13 + 1))) + (float)((float)((float)(*(float *)&z_low - z) * (float)(*(float *)&z_low - z)) + (float)((float)(y - *(float *)&v13) * (float)(y - *(float *)&v13))))
                                                                                              * (float)0.5))
                                                                              * (float)v22)
                                                                      - (float)1.5)
                                                      * (float)v22)
                                              * (float)((float)((float)((float)(*(float *)&x_low - *((float *)&v13 + 1))
                                                                      * (float)(*(float *)&x_low - *((float *)&v13 + 1)))
                                                              + (float)((float)((float)(*(float *)&z_low - z)
                                                                              * (float)(*(float *)&z_low - z))
                                                                      + (float)((float)(y - *(float *)&v13)
                                                                              * (float)(y - *(float *)&v13))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v22
                                                                              * (float)((float)((float)((float)(*(float *)&x_low - *((float *)&v13 + 1)) * (float)(*(float *)&x_low - *((float *)&v13 + 1)))
                                                                                              + (float)((float)((float)(*(float *)&z_low - z) * (float)(*(float *)&z_low - z)) + (float)((float)(y - *(float *)&v13) * (float)(y - *(float *)&v13))))
                                                                                      * (float)0.5))
                                                                      * (float)v22)
                                                              - (float)1.5)
                                              * (float)v22))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v22
                                                      * (float)((float)((float)((float)(*(float *)&x_low
                                                                                      - *((float *)&v13 + 1))
                                                                              * (float)(*(float *)&x_low
                                                                                      - *((float *)&v13 + 1)))
                                                                      + (float)((float)((float)(*(float *)&z_low - z)
                                                                                      * (float)(*(float *)&z_low - z))
                                                                              + (float)((float)(y - *(float *)&v13)
                                                                                      * (float)(y - *(float *)&v13))))
                                                              * (float)0.5))
                                              * (float)v22)
                                      - (float)1.5)
                      * (float)v22));
  _FP8 = (float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)(*(float *)&x_low - *((float *)&v13 + 1)) * (float)(*(float *)&x_low - *((float *)&v13 + 1))) + (float)((float)((float)(*(float *)&z_low - z) * (float)(*(float *)&z_low - z)) + (float)((float)(y - *(float *)&v13) * (float)(y - *(float *)&v13)))) * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22) * (float)((float)((float)((float)(*(float *)&x_low - *((float *)&v13 + 1)) * (float)(*(float *)&x_low - *((float *)&v13 + 1))) + (float)((float)((float)(*(float *)&z_low - z) * (float)(*(float *)&z_low - z)) + (float)((float)(y - *(float *)&v13) * (float)(y - *(float *)&v13)))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)(*(float *)&x_low - *((float *)&v13 + 1)) * (float)(*(float *)&x_low - *((float *)&v13 + 1))) + (float)((float)((float)(*(float *)&z_low - z) * (float)(*(float *)&z_low - z)) + (float)((float)(y - *(float *)&v13) * (float)(y - *(float *)&v13)))) * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22))
                                                                                               - (float)1.5)
                                                                               * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)(*(float *)&x_low - *((float *)&v13 + 1)) * (float)(*(float *)&x_low - *((float *)&v13 + 1))) + (float)((float)((float)(*(float *)&z_low - z) * (float)(*(float *)&z_low - z)) + (float)((float)(y - *(float *)&v13) * (float)(y - *(float *)&v13)))) * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                       * (float)v22))
                                                                       * (float)((float)((float)((float)(*(float *)&x_low - *((float *)&v13 + 1))
                                                                                               * (float)(*(float *)&x_low - *((float *)&v13 + 1)))
                                                                                       + (float)((float)((float)(*(float *)&z_low - z) * (float)(*(float *)&z_low - z))
                                                                                               + (float)((float)(y - *(float *)&v13) * (float)(y - *(float *)&v13))))
                                                                               * (float)0.5))
                                                               * (float)v23)
                                                       - (float)1.5)
                                       * (float)v23)
                               * (float)((float)((float)(*(float *)&x_low - *((float *)&v13 + 1))
                                               * (float)(*(float *)&x_low - *((float *)&v13 + 1)))
                                       + (float)((float)((float)(*(float *)&z_low - z) * (float)(*(float *)&z_low - z))
                                               + (float)((float)(y - *(float *)&v13) * (float)(y - *(float *)&v13)))))
                       / (float)v15)
               - (float)2.0);
  __asm { fsel      f7, f8, f9, f12 }
  v26 = (int)_FP7;
  DWORD2(v13) = (int)_FP7;
  v45 = *(_QWORD *)((char *)&v13 + 4);
  v27 = (float)((float)*(__int64 *)((char *)&v13 + 4) - (float)1.0);
  idCurve<idAngles>::MakeUniform(
    this: spline,
    totalTime: v27,
    a3: (int)off_82010000,
    a4: x_low,
    a5: z_low,
    a6: SHIDWORD(v13),
    a7: v13);
  idCurve<idAngles>::MakeUniform(this: slackSpline, totalTime: v27, a3: v32, a4: v31, a5: v30, a6: v29, a7: v28);
  v33 = 0.0;
  if ( v26 <= zipline->size || (unsigned __int8)idList<idTestEntity::test_t,5>::Resize(this: zipline, newsize: v26) != 0 )
  {
    size = zipline->size;
    if ( v26 < size )
      size = v26;
    zipline->num = size;
  }
  *(float *)&zipline[1].list = 0.0;
  v35 = 0;
  if ( v26 > 0 )
  {
    v36 = slackDown;
    v37 = 0;
    do
    {
      spline->GetCurrentValue(this: (struct idCurve_Spline<idVec3> *)&v45, result: (idVec3 *)spline, a3: v33);
      if ( v36 )
        v38 = v33;
      else
        v38 = (float)((float)v27 - (float)v33);
      slackSpline->GetCurrentValue(this: (struct idCurve_Spline<idVec3> *)&v47, result: (idVec3 *)slackSpline, a3: v38);
      v39 = (idZiplinePoint *)&zipline->list[v37];
      *(_QWORD *)&v39->point.x = v45;
      v39->point.z = v46;
      v40 = *(float *)&v45;
      v41 = (idZiplinePoint *)&zipline->list[v37];
      v42 = v47;
      v43 = (float)(v49 - v46);
      v41->slackDelta.y = v48 - *((float *)&v45 + 1);
      v41->slackDelta.x = (float)v42 - (float)v40;
      v41->slackDelta.z = v43;
      if ( v35 > 0 )
      {
        v44 = (idZiplinePoint *)&zipline->list[v37];
        *(float *)&zipline[1].list = __fsqrts((float)((float)((float)(*(float *)&v45 - v44[-1].point.x)
                                                            * (float)(*(float *)&v45 - v44[-1].point.x))
                                                    + (float)((float)((float)(v46 - v44[-1].point.z)
                                                                    * (float)(v46 - v44[-1].point.z))
                                                            + (float)((float)(*((float *)&v45 + 1) - v44[-1].point.y)
                                                                    * (float)(*((float *)&v45 + 1) - v44[-1].point.y)))));
      }
      ++v35;
      v33 = (float)((float)v33 + (float)((float)v27 / (float)v27));
      ++v37;
    }
    while ( v35 < v26 );
  }
}


// ========================================================================
// ?UpdateHandle@idProp_Zipline@@AAAXXZ
// EA  : 0x82D5D6C8
// RVA : 0x00D5D6C8
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::UpdateHandle(idProp_Zipline *this)
{
  idProp_Zipline::ziplineState_t state; // r11
  __int128 v4; // r6
  __int128 v6; // r8
  unsigned __int64 v8; // r6
  const char *v9; // r7
  unsigned __int64 v10; // r6
  const char *v11; // r7
  unsigned __int64 v12; // r6
  const char *v13; // r7
  idPLogScope v14[3]; // [sp+58h] [-48h] BYREF

  state = this->state;
  _FP31 = 0.0;
  if ( (unsigned int)state <= ZIPLINE_MOVE_UP )
  {
    if ( state != ZIPLINE_ANIMATE_TO_ATTACH && state != ZIPLINE_READY )
    {
      if ( state == ZIPLINE_MOVE_DOWN )
      {
        if ( this->ziplinePhysicsParams.usePhysicsDescent )
        {
          _FP31 = (float)(this->ziplinePhysicsParams.curDist / this->currentDrawnSplineLength);
        }
        else
        {
          HIDWORD(v4) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          LODWORD(v4) = this->currentMoveTime;
          DWORD2(v4) = HIDWORD(v4) - this->startTime;
          _FP7 = (float)((float)((float)*(__int64 *)((char *)&v4 + 4) / (float)(__int64)v4) - (float)1.0);
          __asm { fsel      f31, f7, f0, f8 }
        }
        goto LABEL_17;
      }
      if ( state == ZIPLINE_WAIT_FOR_UP )
      {
        if ( this->ziplinePhysicsParams.usePhysicsDescent )
          _FP31 = (float)(this->ziplinePhysicsParams.curDist / this->currentDrawnSplineLength);
        else
          _FP31 = 1.0;
        goto LABEL_17;
      }
      if ( state != ZIPLINE_START_ATTACH )
      {
        LODWORD(v6) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        *(_QWORD *)((char *)&v6 + 4) = *(_QWORD *)&this->currentMoveTime;
        v14[0] = (idPLogScope)v6;
        _FP3 = (float)((float)((float)((float)(__int64)v6 - (float)*(__int64 *)((char *)&v6 + 4))
                             / (float)*(__int64 *)&v6)
                     - (float)1.0);
        __asm { fsel      f31, f3, f0, f4 }
        goto LABEL_17;
      }
    }
    if ( this->ziplinePhysicsParams.usePhysicsDescent && this->currentDrawnSpline->values.num > 0 )
      _FP31 = (float)(this->ziplinePhysicsParams.curDist / this->currentDrawnSplineLength);
  }
LABEL_17:
  RD_EventBegin(name: "UpdateCurrentDrawnSpline");
  LODWORD(v8) = "UpdateCurrentDrawnSpline";
  HIDWORD(v8) = 2;
  idPLogScope::idPLogScope(this: v14, pl: &pLog, gMask: v8, label: v9);
  idProp_Zipline::UpdateCurrentDrawnSpline(this, percentComplete: _FP31);
  idPLogScope::~idPLogScope(this: v14);
  RD_EventEnd();
  if ( this->state == ZIPLINE_MOVE_DOWN && this->ziplinePhysicsParams.usePhysicsDescent )
  {
    RD_EventBegin(name: "UpdatePhysicsDescent");
    LODWORD(v10) = "UpdatePhysicsDescent";
    HIDWORD(v10) = 2;
    idPLogScope::idPLogScope(this: v14, pl: &pLog, gMask: v10, label: v11);
    idProp_Zipline::UpdatePhysicsDescent(this);
    idPLogScope::~idPLogScope(this: v14);
    RD_EventEnd();
  }
  RD_EventBegin(name: "UpdatePhysicsObject");
  LODWORD(v12) = "UpdatePhysicsObject";
  HIDWORD(v12) = 2;
  idPLogScope::idPLogScope(this: v14, pl: &pLog, gMask: v12, label: v13);
  idProp_Zipline::UpdatePhysicsObject(this);
  idPLogScope::~idPLogScope(this: v14);
  RD_EventEnd();
}


// ========================================================================
// __unwind$501127
// EA  : 0x82D5D930
// RVA : 0x00D5D930
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501127()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$501128
// EA  : 0x82D5D958
// RVA : 0x00D5D958
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501128()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$501129
// EA  : 0x82D5D980
// RVA : 0x00D5D980
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501129()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 97));
}


// ========================================================================
// __unwind$501130
// EA  : 0x82D5D9A8
// RVA : 0x00D5D9A8
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501130()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$501131
// EA  : 0x82D5D9D0
// RVA : 0x00D5D9D0
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501131()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 98));
}


// ========================================================================
// __unwind$501132
// EA  : 0x82D5D9F8
// RVA : 0x00D5D9F8
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501132()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 88));
}


// ========================================================================
// ?BuildZiplines@idProp_Zipline@@AAA_NXZ
// EA  : 0x82D5DA20
// RVA : 0x00D5DA20
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

int __fastcall idProp_Zipline::BuildZiplines(idProp_Zipline *this)
{
  idGameLocal *v2; // r11
  idSplinePath *implicitTravelPath; // r27
  int value; // r9
  idSplinePath *v5; // r3
  idSplinePath *v6; // r3
  idSplinePath *implicitReversePath; // r28
  int v8; // r9
  idSplinePath *v9; // r3
  idSplinePath *v10; // r3
  idSplinePath *implicitSlackPath; // r30
  int v12; // r9
  idSplinePath *v13; // r3
  char v15; // r11
  char v16; // r31
  idCurve_Spline<idVec3> *v17; // r31
  idCurve_Spline<idVec3> *v18; // r28
  idCurve_Spline<idVec3> *v19; // r30

  v2 = gameLocal;
  if ( this->ziplinePathParams.implicitTravelPath != nullptr )
  {
    implicitTravelPath = this->ziplinePathParams.implicitTravelPath;
  }
  else
  {
    value = this->ziplinePathParams.travelPath.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v5 = (idSplinePath *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v6 = idSplinePath::CastTo(c: v5);
      v2 = gameLocal;
      implicitTravelPath = v6;
    }
    else
    {
      implicitTravelPath = nullptr;
    }
  }
  if ( this->ziplinePathParams.implicitReversePath != nullptr )
  {
    implicitReversePath = this->ziplinePathParams.implicitReversePath;
  }
  else
  {
    v8 = this->ziplinePathParams.reversePath.spawnId.value;
    if ( v2->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13 && (v9 = (idSplinePath *)v2->entities.ptr[v8 & 0x1FFF]) != nullptr )
    {
      v10 = idSplinePath::CastTo(c: v9);
      v2 = gameLocal;
      implicitReversePath = v10;
    }
    else
    {
      implicitReversePath = nullptr;
    }
  }
  if ( this->ziplinePathParams.implicitSlackPath != nullptr )
  {
    implicitSlackPath = this->ziplinePathParams.implicitSlackPath;
  }
  else
  {
    v12 = this->ziplinePathParams.slackPath.spawnId.value;
    if ( v2->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13
      && (v13 = (idSplinePath *)v2->entities.ptr[v12 & 0x1FFF]) != nullptr )
    {
      implicitSlackPath = idSplinePath::CastTo(c: v13);
    }
    else
    {
      implicitSlackPath = nullptr;
    }
  }
  if ( implicitTravelPath != nullptr )
  {
    if ( implicitReversePath != nullptr )
    {
      if ( implicitSlackPath != nullptr )
      {
        if ( this->ziplines[0].points.num < 2 || (v15 = 0, this->ziplines[1].points.num < 2) )
          v15 = 1;
        v16 = v15;
        if ( idSplinePath::GetAnchorStart(this: implicitTravelPath) != nullptr
          || idSplinePath::GetAnchorEnd(this: implicitTravelPath) != nullptr )
        {
          v16 |= idProp_Zipline::UpdateImplicitSpline(
                   this,
                   splinePath: implicitTravelPath,
                   sagPercent: this->ziplinePathParams.travelSag);
        }
        if ( idSplinePath::GetAnchorStart(this: implicitReversePath) != nullptr
          || idSplinePath::GetAnchorEnd(this: implicitReversePath) != nullptr )
        {
          v16 |= idProp_Zipline::UpdateImplicitSpline(
                   this,
                   splinePath: implicitReversePath,
                   sagPercent: this->ziplinePathParams.reverseSag);
        }
        if ( idSplinePath::GetAnchorStart(this: implicitSlackPath) != nullptr
          || idSplinePath::GetAnchorEnd(this: implicitSlackPath) != nullptr )
        {
          v16 |= idProp_Zipline::UpdateImplicitSpline(
                   this,
                   splinePath: implicitSlackPath,
                   sagPercent: this->ziplinePathParams.slackSag);
        }
        if ( v16 != 0 )
        {
          v17 = idSplinePath::AllocSpline(this: implicitTravelPath);
          v18 = idSplinePath::AllocSpline(this: implicitReversePath);
          v19 = idSplinePath::AllocSpline(this: implicitSlackPath);
          idProp_Zipline::SetupZiplineFromSplines(
            this,
            zipline: (idList<eboltControlNode_t,5> *)this->ziplines,
            spline: v17,
            slackSpline: v19,
            slackDown: true);
          idProp_Zipline::SetupZiplineFromSplines(
            this,
            zipline: (idList<eboltControlNode_t,5> *)&this->ziplines[1],
            spline: v18,
            slackSpline: v19,
            slackDown: false);
          if ( v17 != nullptr )
            ((void (__fastcall *)(idCurve_Spline<idVec3> *, int))v17->dtr_idCurve<idVec3>)(a1: v17, a2: 1);
          if ( v18 != nullptr )
            ((void (__fastcall *)(idCurve_Spline<idVec3> *, int))v18->dtr_idCurve<idVec3>)(a1: v18, a2: 1);
          if ( v19 != nullptr )
            ((void (__fastcall *)(idCurve_Spline<idVec3> *, int))v19->dtr_idCurve<idVec3>)(a1: v19, a2: 1);
        }
        return 1;
      }
      else
      {
        idLib::Warning(fmt: "SlackPath not set for %s zipline", this->name.data);
        return 0;
      }
    }
    else
    {
      idLib::Warning(fmt: "ReversePath not set for %s zipline", this->name.data);
      return 0;
    }
  }
  else
  {
    idLib::Warning(fmt: "TravelPath not set for %s zipline", this->name.data);
    return 0;
  }
}


// ========================================================================
// ?Update@idProp_Zipline@@QAAXXZ
// EA  : 0x82D5DD60
// RVA : 0x00D5DD60
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::Update(idProp_Zipline *this)
{
  idPhysics *Physics; // r3
  float *v3; // r3
  double v4; // fp12
  idProp_Zipline::ziplineState_t state; // r11
  unsigned int v6; // r11
  idGameTimeManager *p_gameTimeManager; // r3
  int v8; // r3
  int v9; // r8
  const idSoundShader *sndAttach; // r5
  double curDist; // fp0
  double totalLength; // fp13
  int GameMs; // r3
  int downMoveTime; // r10
  idProp_Zipline::ziplineState_t nextState; // r11
  unsigned __int64 v16; // r6
  const char *v17; // r7
  unsigned __int64 v18; // r6
  const char *v19; // r7
  unsigned __int64 v20; // r6
  const char *v21; // r7
  unsigned __int64 v22; // r6
  const char *v23; // r7
  unsigned __int64 v24; // r6
  const char *v25; // r7
  unsigned __int64 v26; // r6
  const char *v27; // r7
  unsigned __int64 v28; // r6
  const char *v29; // r7
  unsigned __int64 v30; // r6
  const char *v31; // r7
  unsigned __int64 v32; // r6
  const char *v33; // r7
  double CurrentSplineTime; // fp1
  __int32 v35; // r6
  char v36; // r5
  unsigned __int64 v37; // r6
  const char *v38; // r7
  __int64 v39; // r3
  idPLogScope v40[10]; // [sp+50h] [-50h] BYREF

  Physics = idEntity::GetPhysics(this);
  v3 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  this->prevHandlePos.x = *v3;
  this->prevHandlePos.y = v3[1];
  v4 = v3[2];
  v40[0].logIndex = (int)&this->prevHandlePos;
  this->prevHandlePos.z = v4;
  if ( this->speedStateTimeLeft > 0 )
    this->speedStateTimeLeft -= idGameTimeManager::GetGameMsPerFrame(
                                  this: &clientGame->gameTimeManager,
                                  type: GAMETIME_SCALED);
  state = this->state;
  if ( state != this->nextState )
  {
    v6 = state - 1;
    if ( v6 <= 4 && v6 != 1 )
    {
      if ( v6 == 2 )
      {
        this->waitingStartTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v40[0].logIndex = (int)&this->ziplinePhysicsParams.curVel;
        this->ziplinePhysicsParams.curSpeed = 0.0;
        this->ziplinePhysicsParams.curVel = vec3_origin;
        this->ziplinePhysicsParams.accelerationTimeRemaining = this->ziplinePhysicsParams.accelerationTime;
      }
      else if ( v6 == 3 )
      {
        this->startTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        curDist = this->ziplinePhysicsParams.curDist;
        totalLength = this->ziplines[this->currentZipline].totalLength;
        this->currentMoveTime = this->ziplineTimings.upMoveTime;
        this->ziplinePhysicsParams.curDist = (float)totalLength - (float)curDist;
        this->currentZipline = 1;
      }
      else if ( v6 != 0 )
      {
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        downMoveTime = this->ziplineTimings.downMoveTime;
        this->startTime = GameMs;
        this->currentZipline = 0;
        this->ziplinePhysicsParams.curDist = 0.0;
        this->currentMoveTime = downMoveTime;
        idProp_Usable::SetUsable(this, b: true);
      }
      else
      {
        p_gameTimeManager = &clientGame->gameTimeManager;
        v40[0].logIndex = (int)&this->anglesOffset;
        this->anglesOffset.roll = 0.0;
        this->anglesOffset.yaw = 0.0;
        this->anglesOffset.pitch = 0.0;
        v8 = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
        v9 = this->ziplineTimings.downMoveTime;
        sndAttach = this->ziplineSounds.sndAttach;
        this->startTime = v8;
        this->currentZipline = 0;
        this->currentMoveTime = v9;
        if ( sndAttach != nullptr )
          idEntity::StartSoundShader(
            this,
            channel: SND_CHANNEL_ITEM,
            shader: sndAttach,
            soundShaderFlags: (soundShaderFlags_t)(this->soundFlags | 0x400),
            peerMask: 0xFFu);
      }
    }
  }
  nextState = this->nextState;
  this->state = nextState;
  if ( (unsigned int)nextState <= ZIPLINE_MOVE_UP )
  {
    switch ( nextState )
    {
      case ZIPLINE_ANIMATE_TO_ATTACH:
        idProp_Zipline::AnimateToAttach(this);
        break;
      case ZIPLINE_READY:
LABEL_30:
        break;
      case ZIPLINE_MOVE_DOWN:
        idProp_Zipline::Down(this);
        break;
      case ZIPLINE_WAIT_FOR_UP:
        idProp_Zipline::WaitForUp(this);
        break;
      default:
        if ( nextState != ZIPLINE_START_ATTACH )
          idProp_Zipline::Up(this);
        else
          idProp_Zipline::StartAttach(this);
        goto LABEL_30;
    }
  }
  RD_EventBegin(name: "UpdateSound");
  LODWORD(v16) = "UpdateSound";
  HIDWORD(v16) = 2;
  idPLogScope::idPLogScope(this: v40, pl: &pLog, gMask: v16, label: v17);
  idProp_Zipline::UpdateSounds(this);
  idPLogScope::~idPLogScope(this: v40);
  RD_EventEnd();
  RD_EventBegin(name: "UpdateFrameCommands");
  LODWORD(v18) = "UpdateFrameCommands";
  HIDWORD(v18) = 2;
  idPLogScope::idPLogScope(this: v40, pl: &pLog, gMask: v18, label: v19);
  idAnimatedEntity::UpdateFrameCommands(this);
  idPLogScope::~idPLogScope(this: v40);
  RD_EventEnd();
  RD_EventBegin(name: "RunPhysics");
  LODWORD(v20) = "RunPhysics";
  HIDWORD(v20) = 2;
  idPLogScope::idPLogScope(this: v40, pl: &pLog, gMask: v20, label: v21);
  idEntity::RunPhysics(this);
  idPLogScope::~idPLogScope(this: v40);
  RD_EventEnd();
  RD_EventBegin(name: "UpdateAnimation");
  LODWORD(v22) = "UpdateAnimation";
  HIDWORD(v22) = 2;
  idPLogScope::idPLogScope(this: v40, pl: &pLog, gMask: v22, label: v23);
  idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
  idPLogScope::~idPLogScope(this: v40);
  RD_EventEnd();
  RD_EventBegin(name: "UpdateDamageEffects");
  LODWORD(v24) = "UpdateDamageEffects";
  HIDWORD(v24) = 2;
  idPLogScope::idPLogScope(this: v40, pl: &pLog, gMask: v24, label: v25);
  idAnimatedEntity::UpdateDamageEffects(this);
  idPLogScope::~idPLogScope(this: v40);
  RD_EventEnd();
  RD_EventBegin(name: "BuildZiplines");
  LODWORD(v26) = "BuildZiplines";
  HIDWORD(v26) = 2;
  idPLogScope::idPLogScope(this: v40, pl: &pLog, gMask: v26, label: v27);
  if ( zipline_generateImplicitSplines.valueInteger != 0 )
    idProp_Zipline::BuildZiplines(this);
  idPLogScope::~idPLogScope(this: v40);
  RD_EventEnd();
  RD_EventBegin(name: "UpdateHandle");
  LODWORD(v28) = "UpdateHandle";
  HIDWORD(v28) = 2;
  idPLogScope::idPLogScope(this: v40, pl: &pLog, gMask: v28, label: v29);
  idProp_Zipline::UpdateHandle(this);
  idPLogScope::~idPLogScope(this: v40);
  RD_EventEnd();
  RD_EventBegin(name: "UpdateFX");
  LODWORD(v30) = "UpdateFX";
  HIDWORD(v30) = 2;
  idPLogScope::idPLogScope(this: v40, pl: &pLog, gMask: v30, label: v31);
  this->UpdateFX(this);
  idPLogScope::~idPLogScope(this: v40);
  RD_EventEnd();
  RD_EventBegin(name: "UpdateCableModel");
  LODWORD(v32) = "UpdateCableModel";
  HIDWORD(v32) = 2;
  idPLogScope::idPLogScope(this: v40, pl: &pLog, gMask: v32, label: v33);
  CurrentSplineTime = idProp_Zipline::GetCurrentSplineTime(
                        this,
                        dist: (float)(this->slackSpring.p1.x * this->ziplinePhysicsParams.curDist));
  v35 = this->state - 3;
  v36 = _cntlzw(v35);
  idRenderModelZipline::SetSpline(
    this: this->cableModel,
    spline: this->currentDrawnSpline,
    time: CurrentSplineTime,
    fractionBeforeLerp: this->ziplinePathParams.tautFraction,
    downDirection: v36,
    a6: v35,
    a7: (v36 & 0x20) != 0);
  idRenderModel::CommitThisFrame(this: this->cableModel);
  idPLogScope::~idPLogScope(this: v40);
  RD_EventEnd();
  RD_EventBegin(name: "UpdateVisuals");
  LODWORD(v37) = "UpdateVisuals";
  HIDWORD(v37) = 2;
  idPLogScope::idPLogScope(this: v40, pl: &pLog, gMask: v37, label: v38);
  idEntity::UpdateVisuals(this);
  idPLogScope::~idPLogScope(this: v40);
  RD_EventEnd();
  LODWORD(v39) = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v40[0] = (idPLogScope)v39;
  idSpring<idVec1>::Update(this: &this->slackSpring, dt: (float)((float)v39 * (float)0.001));
}


// ========================================================================
// __unwind$501419
// EA  : 0x82D5E28C
// RVA : 0x00D5E28C
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501419()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$501420
// EA  : 0x82D5E2B4
// RVA : 0x00D5E2B4
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501420()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$501421
// EA  : 0x82D5E2DC
// RVA : 0x00D5E2DC
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501421()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 89));
}


// ========================================================================
// __unwind$501422
// EA  : 0x82D5E304
// RVA : 0x00D5E304
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501422()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$501423
// EA  : 0x82D5E32C
// RVA : 0x00D5E32C
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501423()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 90));
}


// ========================================================================
// __unwind$501424
// EA  : 0x82D5E354
// RVA : 0x00D5E354
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501424()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$501425
// EA  : 0x82D5E37C
// RVA : 0x00D5E37C
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501425()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 91));
}


// ========================================================================
// __unwind$501426
// EA  : 0x82D5E3A4
// RVA : 0x00D5E3A4
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501426()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$501427_0
// EA  : 0x82D5E3CC
// RVA : 0x00D5E3CC
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501427_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 92));
}


// ========================================================================
// __unwind$501428
// EA  : 0x82D5E3F4
// RVA : 0x00D5E3F4
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501428()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$501429
// EA  : 0x82D5E41C
// RVA : 0x00D5E41C
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501429()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 93));
}


// ========================================================================
// __unwind$501430
// EA  : 0x82D5E444
// RVA : 0x00D5E444
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501430()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$501431
// EA  : 0x82D5E46C
// RVA : 0x00D5E46C
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501431()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 94));
}


// ========================================================================
// __unwind$501432
// EA  : 0x82D5E494
// RVA : 0x00D5E494
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501432()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$501433
// EA  : 0x82D5E4BC
// RVA : 0x00D5E4BC
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501433()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 95));
}


// ========================================================================
// __unwind$501434
// EA  : 0x82D5E4E4
// RVA : 0x00D5E4E4
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501434()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$501435
// EA  : 0x82D5E50C
// RVA : 0x00D5E50C
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501435()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$501436
// EA  : 0x82D5E534
// RVA : 0x00D5E534
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501436()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$501437
// EA  : 0x82D5E55C
// RVA : 0x00D5E55C
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501437()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 97));
}


// ========================================================================
// __unwind$501438
// EA  : 0x82D5E584
// RVA : 0x00D5E584
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501438()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// ?Spawn@idProp_Zipline@@QAAXXZ
// EA  : 0x82D5E5B8
// RVA : 0x00D5E5B8
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::Spawn(idProp_Zipline *this)
{
  int value; // r9
  idGameLocal *v3; // r11
  idProp_Zipline::idProp_ZiplinePathParams *p_ziplinePathParams; // r27
  idMover *v5; // r3
  idMover *v6; // r3
  idMover *v7; // r3
  idMover *v8; // r3
  int v9; // r9
  idEntityPtr<idMover> *p_endMover; // r29
  idGameLocal *v11; // r11
  idMover *v12; // r3
  idMover *v13; // r3
  idMover *v14; // r3
  idMover *v15; // r3
  idMover *Entity; // r3
  idPhysics *Physics; // r3
  float *v18; // r3
  double v19; // fp12
  double v20; // fp11
  idMover *v21; // r3
  int v22; // r9
  idGameLocal *v23; // r11
  idMover *v24; // r3
  idMover *v25; // r3
  idMover *v26; // r29
  int v27; // r9
  idMover *v28; // r3
  idMover *v29; // r4
  idGameLocal *v30; // r11
  int v31; // r9
  idMover *v32; // r3
  idMover *v33; // r3
  idMover *v34; // r29
  int v35; // r9
  idMover *v36; // r3
  idMover *v37; // r4
  idGameLocal *v38; // r11
  int v39; // r9
  idMover *v40; // r3
  idMover *v41; // r3
  idMover *v42; // r29
  int v43; // r9
  idMover *v44; // r3
  idMover *v45; // r4
  idRenderModel *v46; // r3
  idCurve_NonUniformBSpline<idVec3> *v47; // r3
  idCurve_NonUniformBSpline<idVec3> *v48; // r3
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r3
  int v50; // r10
  idPhysics *v51; // r26
  idPhysics_vtbl *v52; // r28
  idClipModel *MoveableClipModel; // r3
  idPhysics *v54; // r3
  int v55; // r7
  int num; // r11
  int GameMs; // r3
  int downMoveTime; // r11
  idPhysics *v59; // r3
  float *v60; // r3
  double fwdMagMin; // fp10
  double v62; // fp9
  __int128 v63; // r9
  unsigned int v64; // r3
  double fwdFreqMin; // fp7
  double v66; // fp6
  unsigned int v67; // r3
  double rtMagMin; // fp13
  double v69; // fp11
  unsigned int v70; // r3
  double rtFreqMin; // fp4
  double v72; // fp2
  unsigned int v73; // r3
  double upMagMin; // fp6
  double v75; // fp5
  unsigned int v76; // r4
  double upFreqMin; // fp9
  double v78; // fp8
  char flags; // r11
  __int64 v80; // r3
  __int64 v81; // [sp+50h] [-70h] BYREF
  idVec3 v82; // [sp+58h] [-68h] BYREF

  if ( this->ziplinePathParams.endpointMoverDecl != nullptr )
  {
    value = this->ziplinePathParams.startMover.spawnId.value;
    v3 = gameLocal;
    p_ziplinePathParams = &this->ziplinePathParams;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v5 = (idMover *)gameLocal->entities.ptr[value & 0x1FFF];
      if ( v5 != nullptr )
      {
        if ( idMover::CastTo(c: v5) != nullptr )
          idLib::Warning(
            fmt: "%s - zipline <%s> is spawning endpoint movers but already has a start mover specified",
            "idProp_Zipline::Spawn",
            this->name.data);
        v3 = gameLocal;
      }
    }
    v6 = (idMover *)v3->SpawnEntityFromDef(
                      this: v3,
                      a2: this->ziplinePathParams.endpointMoverDecl,
                      a3: -1,
                      a4: -1,
                      a5: -1);
    v7 = idMover::CastTo(c: v6);
    if ( v7 != nullptr )
    {
      HIDWORD(v81) = v7->entityNumber;
      p_ziplinePathParams->startMover.spawnId.value = (gameLocal->spawnIds.ptr[HIDWORD(v81)] << 13) | HIDWORD(v81);
    }
    else
    {
      p_ziplinePathParams->startMover.spawnId.value = 0x1FFF;
    }
    if ( gameLocal->spawnIds.ptr[p_ziplinePathParams->startMover.spawnId.value & 0x1FFF] != p_ziplinePathParams->startMover.spawnId.value >> 13
      || (v8 = (idMover *)gameLocal->entities.ptr[p_ziplinePathParams->startMover.spawnId.value & 0x1FFF]) == nullptr
      || idMover::CastTo(c: v8) == nullptr )
    {
      idLib::Warning(
        fmt: "%s - zipline <%s> was unable to spawn start mover from decl <%s>",
        "idProp_Zipline::Spawn",
        this->name.data,
        this->ziplinePathParams.endpointMoverDecl->name.str);
      return;
    }
    v9 = this->ziplinePathParams.endMover.spawnId.value;
    p_endMover = &this->ziplinePathParams.endMover;
    v11 = gameLocal;
    if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13 )
    {
      v12 = (idMover *)gameLocal->entities.ptr[v9 & 0x1FFF];
      if ( v12 != nullptr )
      {
        if ( idMover::CastTo(c: v12) != nullptr )
          idLib::Warning(
            fmt: "%s - zipline <%s> is spawning endpoint movers but already has an end mover specified",
            "idProp_Zipline::Spawn",
            this->name.data);
        v11 = gameLocal;
      }
    }
    v13 = (idMover *)v11->SpawnEntityFromDef(
                       this: v11,
                       a2: this->ziplinePathParams.endpointMoverDecl,
                       a3: -1,
                       a4: -1,
                       a5: -1);
    v14 = idMover::CastTo(c: v13);
    if ( v14 != nullptr )
    {
      HIDWORD(v81) = v14->entityNumber;
      p_endMover->spawnId.value = (gameLocal->spawnIds.ptr[HIDWORD(v81)] << 13) | HIDWORD(v81);
    }
    else
    {
      p_endMover->spawnId.value = 0x1FFF;
    }
    if ( gameLocal->spawnIds.ptr[p_endMover->spawnId.value & 0x1FFF] != p_endMover->spawnId.value >> 13
      || (v15 = (idMover *)gameLocal->entities.ptr[p_endMover->spawnId.value & 0x1FFF]) == nullptr
      || idMover::CastTo(c: v15) == nullptr )
    {
      idLib::Warning(
        fmt: "%s - zipline <%s> was unable to spawn end mover from decl <%s>",
        "idProp_Zipline::Spawn",
        this->name.data,
        this->ziplinePathParams.endpointMoverDecl->name.str);
      return;
    }
    Entity = idEntityPtr<idMover>::GetEntity(this: &p_ziplinePathParams->startMover);
    Physics = idEntity::GetPhysics(this: Entity);
    v18 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v19 = v18[2];
    v20 = (float)(*v18 + (float)10.0);
    v82.y = v18[1];
    v82.x = v20;
    v82.z = v19;
    v21 = idEntityPtr<idMover>::GetEntity(this: &this->ziplinePathParams.endMover);
    idEntity::SetOrigin(this: v21, org: &v82);
  }
  if ( this->ziplinePathParams.cableMaterial != nullptr )
  {
    v22 = this->ziplinePathParams.endMover.spawnId.value;
    v23 = gameLocal;
    if ( gameLocal->spawnIds.ptr[v22 & 0x1FFF] == v22 >> 13
      && (v24 = (idMover *)gameLocal->entities.ptr[v22 & 0x1FFF]) != nullptr )
    {
      v25 = idMover::CastTo(c: v24);
      v23 = gameLocal;
      v26 = v25;
    }
    else
    {
      v26 = nullptr;
    }
    v27 = this->ziplinePathParams.startMover.spawnId.value;
    if ( v23->spawnIds.ptr[v27 & 0x1FFF] == v27 >> 13 && (v28 = (idMover *)v23->entities.ptr[v27 & 0x1FFF]) != nullptr )
      v29 = idMover::CastTo(c: v28);
    else
      v29 = nullptr;
    this->ziplinePathParams.implicitTravelPath = idProp_Zipline::BuildImplicitSpline(
                                                   this,
                                                   startMover: v29,
                                                   endMover: v26,
                                                   sagPercent: this->ziplinePathParams.travelSag);
    v30 = gameLocal;
    v31 = this->ziplinePathParams.startMover.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v31 & 0x1FFF] == v31 >> 13
      && (v32 = (idMover *)gameLocal->entities.ptr[v31 & 0x1FFF]) != nullptr )
    {
      v33 = idMover::CastTo(c: v32);
      v30 = gameLocal;
      v34 = v33;
    }
    else
    {
      v34 = nullptr;
    }
    v35 = this->ziplinePathParams.endMover.spawnId.value;
    if ( v30->spawnIds.ptr[v35 & 0x1FFF] == v35 >> 13 && (v36 = (idMover *)v30->entities.ptr[v35 & 0x1FFF]) != nullptr )
      v37 = idMover::CastTo(c: v36);
    else
      v37 = nullptr;
    this->ziplinePathParams.implicitReversePath = idProp_Zipline::BuildImplicitSpline(
                                                    this,
                                                    startMover: v37,
                                                    endMover: v34,
                                                    sagPercent: this->ziplinePathParams.reverseSag);
    v38 = gameLocal;
    v39 = this->ziplinePathParams.endMover.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v39 & 0x1FFF] == v39 >> 13
      && (v40 = (idMover *)gameLocal->entities.ptr[v39 & 0x1FFF]) != nullptr )
    {
      v41 = idMover::CastTo(c: v40);
      v38 = gameLocal;
      v42 = v41;
    }
    else
    {
      v42 = nullptr;
    }
    v43 = this->ziplinePathParams.startMover.spawnId.value;
    if ( v38->spawnIds.ptr[v43 & 0x1FFF] == v43 >> 13 && (v44 = (idMover *)v38->entities.ptr[v43 & 0x1FFF]) != nullptr )
      v45 = idMover::CastTo(c: v44);
    else
      v45 = nullptr;
    this->ziplinePathParams.implicitSlackPath = idProp_Zipline::BuildImplicitSpline(
                                                  this,
                                                  startMover: v45,
                                                  endMover: v42,
                                                  sagPercent: this->ziplinePathParams.slackSag);
    if ( (unsigned __int8)idProp_Zipline::BuildZiplines(this) != 0 )
    {
      v46 = clientGame->renderWorld->AllocRenderModel(this: clientGame->renderWorld, a2: "_Zipline", a3: 1, a4: -1);
      this->cableModel = (idRenderModelZipline *)_RTDynamicCast(
                                                   inptr: v46,
                                                   VfDelta: 0,
                                                   SrcType: &idRenderModel `RTTI Type Descriptor',
                                                   TargetType: &idRenderModelZipline `RTTI Type Descriptor',
                                                   isReference: 0);
      v47 = (idCurve_NonUniformBSpline<idVec3> *)idMem::AllocWithLocation(
                                                   this: &mem,
                                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                   size: 0x38u,
                                                   tag: TAG_SPLINE,
                                                   zeroBuffer: false,
                                                   align: ALIGN_16,
                                                   heap: HEAP_DEFAULTHEAP);
      HIDWORD(v81) = v47;
      if ( v47 != nullptr )
        v48 = idCurve_NonUniformBSpline<idVec3>::idCurve_NonUniformBSpline<idVec3>(this: v47);
      else
        v48 = nullptr;
      this->currentDrawnSpline = v48;
      if ( idEntity::GetRenderModelFromPresentable(this) != nullptr )
        idEntity::GetRenderModelFromPresentable(this)->useDeferredPosition = false;
      TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
      v50 = HIWORD(idTreeAnimator::GetJointIndex(
                     this: (idTreeAnimator *)&v81,
                     result: TreeAnimatorFromPresentable,
                     jointName: "eye")->__vftable);
      this->eyeJoint.value = v50;
      if ( v50 == 0xFFFF )
        idLib::Warning(fmt: "No Eye joint in Zipline2 prop");
      v51 = idEntity::GetPhysics(this);
      v52 = v51->__vftable;
      MoveableClipModel = idEntity::CreateMoveableClipModel(this, barrelCollision: false, overrideRadius: -1.0);
      ((void (__fastcall *)(idPhysics *, idClipModel *, double))v52->SetClipModel)(
        a1: v51,
        a2: MoveableClipModel,
        a3: 1.0);
      v54 = idEntity::GetPhysics(this);
      v54->SetContents(this: v54, a2: 0x200000, a3: -1);
      num = this->ziplines[1].points.num;
      if ( this->ziplines[0].points.num > num )
        num = this->ziplines[0].points.num;
      idRenderModelZipline::BuildModel(
        this: this->cableModel,
        material: this->ziplinePathParams.cableMaterial,
        splineTessellationDistance: this->ziplinePathParams.unitsPerSplinePoints,
        splineMaxSubdivisions: 2 * num,
        cableDiameter: this->ziplinePathParams.diameter,
        cableSubdivisions: v55,
        a7: this->ziplinePathParams.cableDivisions);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      downMoveTime = this->ziplineTimings.downMoveTime;
      this->startTime = GameMs;
      this->currentZipline = 0;
      this->currentMoveTime = downMoveTime;
      idProp_Zipline::UpdateHandle(this);
      idProp_Zipline::UpdateCableModel(this);
      idEntity::BecomeActive(this, flags: 1);
      idProp_Usable::SetUsable(this, b: true);
      idProp_Zipline::UpdatePhysicsObject(this);
      v59 = idEntity::GetPhysics(this);
      v60 = (float *)v59->GetOrigin(this: v59, a2: 0);
      this->prevHandlePos.x = *v60;
      HIDWORD(v81) = &this->prevHandlePos;
      this->prevHandlePos.y = v60[1];
      this->prevHandlePos.z = v60[2];
      this->slackSpring.hasPMin = false;
      this->slackSpring.hasPMax = false;
      this->slackSpring.restLength = 0.0;
      this->slackSpring.k = 1.0;
      this->slackSpring.m = 1.0;
      this->slackSpring.c = 2.0;
      this->slackSpring.p0.x = 0.0;
      this->slackSpring.p1.x = 0.0;
      this->slackSpring.vel.x = 0.0;
      this->slackSpring.maxSpeed = 0.0;
      this->slackSpring.pMin.x = 0.0;
      this->slackSpring.pMax.x = 0.0;
      idSpring<idVec1>::SetConstants(this: &this->slackSpring, _k: 100.0, _c: -1.0);
      *(float *)&v81 = 1.0;
      this->slackSpring.p1.x = 1.0;
      this->slackSpring.p0.x = 1.0;
      fwdMagMin = this->ziplineOscillationParams.fwdMagMin;
      v62 = (float)(this->ziplineOscillationParams.fwdMagMax - this->ziplineOscillationParams.fwdMagMin);
      DWORD1(v63) = clientGame->random.seed;
      v64 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v64;
      fwdFreqMin = this->ziplineOscillationParams.fwdFreqMin;
      DWORD2(v63) = (v64 >> 10) & 0x7FFF;
      v66 = (float)(this->ziplineOscillationParams.fwdFreqMax - this->ziplineOscillationParams.fwdFreqMin);
      v81 = *(_QWORD *)((char *)&v63 + 4);
      this->ziplineOscillationParams.fwdMag = (float)((float)((float)*(__int64 *)((char *)&v63 + 4) * (float)v62)
                                                    * (float)0.000030518509)
                                            + (float)fwdMagMin;
      DWORD1(v63) = clientGame->random.seed;
      v67 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v67;
      rtMagMin = this->ziplineOscillationParams.rtMagMin;
      DWORD2(v63) = (v67 >> 10) & 0x7FFF;
      v69 = (float)(this->ziplineOscillationParams.rtMagMax - this->ziplineOscillationParams.rtMagMin);
      v81 = *(_QWORD *)((char *)&v63 + 4);
      this->ziplineOscillationParams.fwdFreq = (float)((float)((float)*(__int64 *)((char *)&v63 + 4) * (float)v66)
                                                     * (float)0.000030518509)
                                             + (float)fwdFreqMin;
      DWORD1(v63) = clientGame->random.seed;
      v70 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v70;
      rtFreqMin = this->ziplineOscillationParams.rtFreqMin;
      DWORD2(v63) = (v70 >> 10) & 0x7FFF;
      v72 = (float)(this->ziplineOscillationParams.rtFreqMax - this->ziplineOscillationParams.rtFreqMin);
      v81 = *(_QWORD *)((char *)&v63 + 4);
      this->ziplineOscillationParams.rtMag = (float)((float)((float)*(__int64 *)((char *)&v63 + 4) * (float)v69)
                                                   * (float)0.000030518509)
                                           + (float)rtMagMin;
      DWORD1(v63) = clientGame->random.seed;
      v73 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v73;
      DWORD2(v63) = (v73 >> 10) & 0x7FFF;
      upMagMin = this->ziplineOscillationParams.upMagMin;
      v75 = (float)(this->ziplineOscillationParams.upMagMax - this->ziplineOscillationParams.upMagMin);
      v81 = *(_QWORD *)((char *)&v63 + 4);
      this->ziplineOscillationParams.rtFreq = (float)((float)((float)*(__int64 *)((char *)&v63 + 4) * (float)v72)
                                                    * (float)0.000030518509)
                                            + (float)rtFreqMin;
      v76 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v76;
      LODWORD(v63) = (v76 >> 10) & 0x7FFF;
      upFreqMin = this->ziplineOscillationParams.upFreqMin;
      v78 = (float)(this->ziplineOscillationParams.upFreqMax - this->ziplineOscillationParams.upFreqMin);
      v81 = v63;
      this->ziplineOscillationParams.upMag = (float)((float)((float)(__int64)v63 * (float)v75) * (float)0.000030518509)
                                           + (float)upMagMin;
      HIDWORD(v63) = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = HIDWORD(v63);
      flags = (char)this->flags;
      LODWORD(v80) = (HIDWORD(v63) >> 10) & 0x7FFF;
      v81 = v80;
      *(_BYTE *)&this->flags = flags | 0x40;
      this->ziplineOscillationParams.upFreq = (float)((float)((float)v81 * (float)v78) * (float)0.000030518509)
                                            + (float)upFreqMin;
    }
  }
  else
  {
    idLib::Warning(fmt: "Cable material not set for %s zipline", this->name.data);
  }
}


// ========================================================================
// __unwind$501737
// EA  : 0x82D5EF00
// RVA : 0x00D5EF00
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_501737()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 192 + 80), tag: TAG_SPLINE);
}


// ========================================================================
// ?Think@idProp_Zipline@@UAAXXZ
// EA  : 0x82D5EF38
// RVA : 0x00D5EF38
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idProp_Zipline::Think(idProp_Zipline *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPLogScope v4[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "idProp_Zipline::Think");
  LODWORD(v2) = "idProp_Zipline::Think";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v4, pl: &pLog, gMask: v2, label: v3);
  if ( (unsigned __int8)idEntity::UpdateDormant(this) == 0 && !this->manualUpdate )
  {
    idProp_Zipline::Update(this);
    idEntity::UpdatePVSAreas(this);
  }
  idPLogScope::~idPLogScope(this: v4);
  RD_EventEnd();
}


// ========================================================================
// __unwind$502457
// EA  : 0x82D5EFC4
// RVA : 0x00D5EFC4
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_502457()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$502458
// EA  : 0x82D5EFEC
// RVA : 0x00D5EFEC
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void _unwind_502458()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?Spawn@idInfoZiplineTarget@@QAAXXZ
// EA  : 0x82D5F018
// RVA : 0x00D5F018
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __fastcall idInfoZiplineTarget::Spawn(idInfoZiplineTarget *this)
{
  int v1; // r8
  int v2; // r10
  idEntityPtr<idInfoZiplineTarget> *list; // r11
  idEntityPtr<idEntity> v4; // [sp+50h] [-10h] BYREF

  if ( this != nullptr )
    v1 = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
  else
    v1 = 0x1FFF;
  v4.spawnId.value = v1;
  v2 = 0;
  if ( idInfoZiplineTarget::ziplineTargets.num <= 0 )
    goto LABEL_10;
  list = idInfoZiplineTarget::ziplineTargets.list;
  while ( list->spawnId.value != v1 )
  {
    ++v2;
    ++list;
    if ( v2 >= idInfoZiplineTarget::ziplineTargets.num )
      goto LABEL_10;
  }
  if ( v2 < 0 )
LABEL_10:
    idList<idEntityPtr<idEntity>,58>::Append(
      this: (idList<idEntityPtr<idEntity>,58> *)&idInfoZiplineTarget::ziplineTargets,
      obj: &v4);
}


// ========================================================================
// `dynamic initializer for 'zipline_debug''
// EA  : 0x83380188
// RVA : 0x01380188
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__zipline_debug__()
{
  idCVar::idCVar(
    this: &zipline_debug,
    name: "zipline_debug",
    value: "0",
    flags: 2,
    description: "debug print",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__zipline_debug__);
}


// ========================================================================
// `dynamic initializer for 'zipline_debugSplines''
// EA  : 0x833801E0
// RVA : 0x013801E0
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__zipline_debugSplines__()
{
  idCVar::idCVar(
    this: &zipline_debugSplines,
    name: "zipline_debugSplines",
    value: "0",
    flags: 2,
    description: "1=draws points on all the control splines and the lerped pos between them, 2=control spline, 3=slack spline, 4=lerped spline",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__zipline_debugSplines__);
}


// ========================================================================
// `dynamic initializer for 'zipline_enableOscillation''
// EA  : 0x83380238
// RVA : 0x01380238
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__zipline_enableOscillation__()
{
  idCVar::idCVar(
    this: &zipline_enableOscillation,
    name: "zipline_enableOscillation",
    value: "1",
    flags: 1,
    description: "Allow the zipline to oscillate",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__zipline_enableOscillation__);
}


// ========================================================================
// `dynamic initializer for 'zipline_attachPlayer''
// EA  : 0x83380290
// RVA : 0x01380290
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__zipline_attachPlayer__()
{
  idCVar::idCVar(
    this: &zipline_attachPlayer,
    name: "zipline_attachPlayer",
    value: "1",
    flags: 1,
    description: "Controls whether player is attached to zipline or not",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__zipline_attachPlayer__);
}


// ========================================================================
// `dynamic initializer for 'zipline_generateImplicitSplines''
// EA  : 0x833802E8
// RVA : 0x013802E8
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__zipline_generateImplicitSplines__()
{
  idCVar::idCVar(
    this: &zipline_generateImplicitSplines,
    name: "zipline_generateImplicitSplines",
    value: "1",
    flags: 1,
    description: "Controls whether implicit spines are allowed or not",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__zipline_generateImplicitSplines__);
}


// ========================================================================
// `dynamic initializer for 'zipline_debugImplicitSplines''
// EA  : 0x83380340
// RVA : 0x01380340
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__zipline_debugImplicitSplines__()
{
  idCVar::idCVar(
    this: &zipline_debugImplicitSplines,
    name: "zipline_debugImplicitSplines",
    value: "0",
    flags: 1,
    description: "Draws debug info for implicit splines with mover endpoint(s)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__zipline_debugImplicitSplines__);
}


// ========================================================================
// `dynamic initializer for 'zipline_physicsDescentLookahead''
// EA  : 0x83380398
// RVA : 0x01380398
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__zipline_physicsDescentLookahead__()
{
  idCVar::idCVar(
    this: &zipline_physicsDescentLookahead,
    name: "zipline_physicsDescentLookahead",
    value: "10",
    flags: 4,
    description: "How far ahead on the current spline to test the slope (don't want to test on the taut part).",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__zipline_physicsDescentLookahead__);
}


// ========================================================================
// `dynamic initializer for 'zipline_nearestTimeThreshold''
// EA  : 0x833803F0
// RVA : 0x013803F0
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__zipline_nearestTimeThreshold__()
{
  idCVar::idCVar(
    this: &zipline_nearestTimeThreshold,
    name: "zipline_nearestTimeThreshold",
    value: "10",
    flags: 4,
    description: "Subdivide the spline down to subintervals of this duration for determining the nearest point to the player's use position",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__zipline_nearestTimeThreshold__);
}


// ========================================================================
// `dynamic initializer for 'zipline_debugDrawTargets''
// EA  : 0x83380448
// RVA : 0x01380448
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__zipline_debugDrawTargets__()
{
  idCVar::idCVar(
    this: &zipline_debugDrawTargets,
    name: "zipline_debugDrawTargets",
    value: "1",
    flags: 1,
    description: "Draw all the debug targets",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__zipline_debugDrawTargets__);
}


// ========================================================================
// `dynamic initializer for 'zipline_swayFreq''
// EA  : 0x833804A0
// RVA : 0x013804A0
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__zipline_swayFreq__()
{
  idCVar::idCVar(
    this: &zipline_swayFreq,
    name: "zipline_swayFreq",
    value: "0.5",
    flags: 4,
    description: "After starting to accelerate, time to get to max sway speed (s)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__zipline_swayFreq__);
}


// ========================================================================
// `dynamic initializer for 'zipline_swayMag''
// EA  : 0x833804F8
// RVA : 0x013804F8
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__zipline_swayMag__()
{
  idCVar::idCVar(
    this: &zipline_swayMag,
    name: "zipline_swayMag",
    value: "45.0",
    flags: 4,
    description: "After starting to accelerate, time to get to max sway speed (s)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__zipline_swayMag__);
}


// ========================================================================
// `dynamic initializer for 'zipline_centerLerpPower''
// EA  : 0x83380550
// RVA : 0x01380550
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__zipline_centerLerpPower__()
{
  idCVar::idCVar(
    this: &zipline_centerLerpPower,
    name: "zipline_centerLerpPower",
    value: "0.1",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__zipline_centerLerpPower__);
}


// ========================================================================
// `dynamic initializer for 'zipline_swayIncrement''
// EA  : 0x833805A8
// RVA : 0x013805A8
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__zipline_swayIncrement__()
{
  idCVar::idCVar(
    this: &zipline_swayIncrement,
    name: "zipline_swayIncrement",
    value: "0.001",
    flags: 4,
    description: "After starting to accelerate, time to get to max sway speed (s)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__zipline_swayIncrement__);
}


// ========================================================================
// `dynamic initializer for 'zipline_swayDecrement''
// EA  : 0x83380600
// RVA : 0x01380600
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__zipline_swayDecrement__()
{
  idCVar::idCVar(
    this: &zipline_swayDecrement,
    name: "zipline_swayDecrement",
    value: "0.01",
    flags: 4,
    description: "After starting to accelerate, time to get to max sway speed (s)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__zipline_swayDecrement__);
}


// ========================================================================
// `dynamic initializer for 'idInfoZiplineTarget::ziplineTargets''
// EA  : 0x83380658
// RVA : 0x01380658
// PDB : w:\tech5\tungsten\game\entities\zipline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idInfoZiplineTarget::ziplineTargets__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idInfoZiplineTarget::ziplineTargets__);
}

