
// ========================================================================
// ?GetMagnetRange@idVehicle_Car@@QBAMXZ
// EA  : 0x82D3C6F8
// RVA : 0x00D3C6F8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

float __fastcall idVehicle_Car::GetMagnetRange(idVehicle_Car *this)
{
  double magnetRange; // fp1

  magnetRange = this->magnetRange;
  return *((float *)&magnetRange + 1);
}


// ========================================================================
// ?PingAttack@idVehicle_Car@@QAAXXZ
// EA  : 0x82D3C700
// RVA : 0x00D3C700
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::PingAttack(idVehicle_Car *this)
{
  this->attackOverTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + 1000;
}


// ========================================================================
// ?AddQuickUseActive@idVehicle_Car@@QAAXW4vehicleQuickUse_t@@H@Z
// EA  : 0x82D3C750
// RVA : 0x00D3C750
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::AddQuickUseActive(idVehicle_Car *this, unsigned int t, int timeMS)
{
  if ( t <= 0xA )
  {
    ++this->vquInfo[t].numActive;
    if ( timeMS <= 0 )
      this->vquInfo[t].deactivateTime = 0;
    else
      this->vquInfo[t].deactivateTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + timeMS;
  }
}


// ========================================================================
// ?RemoveQuickUseActive@idVehicle_Car@@QAAXW4vehicleQuickUse_t@@@Z
// EA  : 0x82D3C7E0
// RVA : 0x00D3C7E0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::RemoveQuickUseActive(idVehicle_Car *this, unsigned int t)
{
  __int32 v2; // r11
  idVehicle_Car_vtbl *v3; // r10

  if ( t <= 0xA )
  {
    v2 = 8 * (t + 2124);
    v3 = (idVehicle_Car_vtbl *)(*(char **)((char *)&this->__vftable + v2) - 1);
    *(idVehicle_Car_vtbl **)((char *)&this->__vftable + v2) = v3;
    if ( (int)v3 < 0 )
      *(idVehicle_Car_vtbl **)((char *)&this->__vftable + v2) = nullptr;
  }
}


// ========================================================================
// ?CanActivateQuickUse@idVehicle_Car@@QAA_NW4vehicleQuickUse_t@@@Z
// EA  : 0x82D3C818
// RVA : 0x00D3C818
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

unsigned int __fastcall idVehicle_Car::CanActivateQuickUse(idVehicle_Car *this, unsigned int t)
{
  char *v4; // r29
  int v5; // r10
  int v6; // r9
  float *p_frictionOverrideFront; // r11
  int i; // ctr
  int v9; // r7

  if ( t > 0xA )
    return 0;
  v4 = (char *)this + 8 * t;
  if ( *((int *)v4 + 4249) > 0 )
  {
    if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) < *((_DWORD *)v4 + 4249) )
      return 0;
    --this->vquInfo[t].numActive;
  }
  if ( this->vquInfo[t].numActive >= 1 )
    return 0;
  v5 = 0;
  v6 = 0;
  p_frictionOverrideFront = &this->frictionOverrideFront;
  for ( i = 5; i != 0; --i )
  {
    v9 = *((_DWORD *)p_frictionOverrideFront + 2);
    p_frictionOverrideFront += 4;
    v5 += v9;
    v6 += *(_DWORD *)p_frictionOverrideFront;
  }
  return ((unsigned int)(v6 + v5 + this->vquInfo[10].numActive) <= 3)
       + ((unsigned int)(v6 + v5 + this->vquInfo[10].numActive) >> 31);
}


// ========================================================================
// ?Hide@idVehicle_Car@@UAAXXZ
// EA  : 0x82D3CCD8
// RVA : 0x00D3CCD8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::Hide(idVehicle_Car *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  int GameMs; // r3
  idPresentable *v5; // r11
  int v6; // r28
  int v7; // r3
  int v8; // r3
  idPresentable *v9; // r11
  int v10; // r31
  idPresentableVehicle *v11; // r3
  idFXManager *PredictedFXMgr; // r3
  idPresentable *v13; // r3
  idPresentableVehicle *v14; // r3

  idVehicle::Hide(this);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v3 = 0;
  idImpactManager::StopImpacts(this: (idImpactManager *)(v3 + 12504));
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v5 = this->presentable;
  v6 = GameMs;
  if ( v5 != nullptr )
    v7 = (int)v5->GetVehicleInterface(this: this->presentable);
  else
    v7 = 0;
  idFXManager::StopAllFX(this: (idFXManager *)(v7 + 288), time: v6, immediateStop: true);
  v8 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v9 = this->presentable;
  v10 = v8;
  if ( v9 != nullptr )
    v11 = v9->GetVehicleInterface(this: this->presentable);
  else
    v11 = nullptr;
  PredictedFXMgr = idPresentableVehicle::GetPredictedFXMgr(this: v11);
  idFXManager::StopAllFX(this: PredictedFXMgr, time: v10, immediateStop: true);
  v13 = this->presentable;
  if ( v13 != nullptr )
  {
    v14 = v13->GetVehicleInterface(this: v13);
    idPresentableVehicle::KillEngineSounds(this: v14);
  }
  else
  {
    idPresentableVehicle::KillEngineSounds(this: nullptr);
  }
}


// ========================================================================
// ?ResetBoostPower@idVehicle_Car@@QAAXXZ
// EA  : 0x82D3CDF8
// RVA : 0x00D3CDF8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::ResetBoostPower(idVehicle_Car *this)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    v2 = presentable->GetVehicleInterface(this: presentable);
    idPresentableVehicle::ResetBoostPower(this: v2);
  }
  else
  {
    idPresentableVehicle::ResetBoostPower(this: nullptr);
  }
}


// ========================================================================
// ?DormantEnd@idVehicle_Car@@UAAXH@Z
// EA  : 0x82D3CE50
// RVA : 0x00D3CE50
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::DormantEnd(idVehicle_Car *this, int timeDormant)
{
  idPhysics *Physics; // r3

  idEntity::DormantEnd(this, timeDormant);
  if ( gameLocal->world->mapType == MAPTYPE_OUTDOOR )
  {
    Physics = idEntity::GetPhysics(this);
    Physics->SetLinearVelocity(this: Physics, a2: &vec3_origin, a3: 0);
  }
}


// ========================================================================
// ?OverrideFriction@idVehicle_Car@@QAAXHMM@Z
// EA  : 0x82D3CEC0
// RVA : 0x00D3CEC0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::OverrideFriction(
        idVehicle_Car *this,
        int time,
        double frontFriction,
        double rearFriction)
{
  int GameMs; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->frictionOverrideFront = frontFriction;
  this->frictionOverrideRear = rearFriction;
  this->frictionOverrideTime = GameMs + time;
}


// ========================================================================
// ?WeaponControl@idVehicle_Car@@QAAXXZ
// EA  : 0x82D3CF38
// RVA : 0x00D3CF38
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::WeaponControl(idVehicle_Car *this)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v3; // r3
  __int64 v4; // r8
  idPresentable *v5; // r3
  idPresentableVehicle *v6; // r3
  usercmd_t v7; // [sp+50h] [-A0h] BYREF
  usercmd_t v8; // [sp+90h] [-60h] BYREF

  presentable = this->presentable;
  memset(&v8, 0, 9);
  v8.pos[2] = 0.0;
  v8.pos[1] = 0.0;
  v8.pos[0] = 0.0;
  v7.pos[2] = 0.0;
  v7.pos[1] = 0.0;
  memset(v8.angles, 0, 10);
  v7.pos[0] = 0.0;
  v8.yaw = 0;
  v8.pitch = 0;
  v8.roll = 0;
  v8.predictionStateBits = 0;
  memset(&v8.serverGameTime, 0, 18);
  *((_BYTE *)&v8 + 9) &= 0x3Fu;
  memset(&v7, 0, 9);
  memset(v7.angles, 0, 10);
  *((_BYTE *)&v7 + 9) &= 0x3Fu;
  v7.yaw = 0;
  v7.pitch = 0;
  v7.roll = 0;
  v7.predictionStateBits = 0;
  memset(&v7.serverGameTime, 0, 18);
  if ( presentable != nullptr )
    v3 = presentable->GetVehicleInterface(this: presentable);
  else
    v3 = nullptr;
  if ( (unsigned __int8)idPresentableVehicle::GetUserCommand(this: v3, seat: 1, previous: &v8, current: &v7) != 0 )
  {
    idVehicle::CheckImpulseServerOnly(this, seat: 1, prevcmd: &v8, usercmd: &v7);
    v5 = this->presentable;
    if ( v5 != nullptr )
      v6 = v5->GetVehicleInterface(this: v5);
    else
      v6 = nullptr;
    idPresentableVehicle::UpdateCrosshair(this: v6, seat: SEAT_GUNNER, prevcmd: &v8, usercmd: v4);
  }
}


// ========================================================================
// ?SetIsReversing@idVehicle_Car@@QAAX_N@Z
// EA  : 0x82D3D0E0
// RVA : 0x00D3D0E0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::SetIsReversing(idVehicle_Car *this, bool bl)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    presentable->GetVehicleInterface(this: presentable)->reversing = bl;
  else
    MEMORY[0x2E67] = bl;
  this->vehicleAnimator.isReversing = bl;
}


// ========================================================================
// ?Event_SetDisableEngine@idVehicle_Car@@QAA?AVeventVoid@@M@Z
// EA  : 0x82D3D148
// RVA : 0x00D3D148
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

idVehicle_Car *__fastcall idVehicle_Car::Event_SetDisableEngine(
        idVehicle_Car *this,
        idVehicle *result,
        double disabled)
{
  idPresentable *presentable; // r3
  int v6; // r3
  idPresentable *v7; // r3
  int v9; // r11
  idPresentable *v10; // r3
  int v11; // r3

  presentable = result->presentable;
  if ( disabled <= 0.0 )
  {
    if ( presentable != nullptr )
      v9 = (int)presentable->GetVehicleInterface(this: presentable);
    else
      v9 = 0;
    *(_BYTE *)(v9 + 20444) = 0;
    if ( idVehicle::GetDriver(this: result) != nullptr )
    {
      v10 = result->presentable;
      if ( v10 != nullptr )
        v11 = (int)v10->GetVehicleInterface(this: v10);
      else
        v11 = 0;
      *(_BYTE *)(v11 + 11877) = 1;
      result[1].bindInfo.bindAnim.baseBuffer[12] = 0;
    }
    return this;
  }
  else
  {
    if ( presentable != nullptr )
      v6 = (int)presentable->GetVehicleInterface(this: presentable);
    else
      v6 = 0;
    *(_BYTE *)(v6 + 20444) = 1;
    v7 = result->presentable;
    if ( v7 != nullptr )
      v7->GetVehicleInterface(this: v7)->engineRunning = false;
    else
      MEMORY[0x2E65] = 0;
    return this;
  }
}


// ========================================================================
// ?DriveControl@idVehicle_Car@@QAAXXZ
// EA  : 0x82D3D258
// RVA : 0x00D3D258
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::DriveControl(idVehicle_Car *this)
{
  idPlayer *Driver; // r3
  idPlayer *v3; // r29
  idPresentable *presentable; // r3
  idPresentableVehicle *v5; // r3
  __int64 v6; // r8
  idEntity *Gunner; // r3
  idPresentable *v8; // r3
  idPresentableVehicle *v9; // r3
  __int64 v10; // r8
  idPresentable *v11; // r3
  idPresentableVehicle *v12; // r3
  __int64 v13; // r8
  idPresentable *v14; // r3
  idPresentableVehicle *v15; // r3
  idPresentable *v16; // r3
  idPresentablePlayer *v17; // r29
  idPresentable *v18; // r3
  idPresentableVehicle *v19; // r3
  idPresentable *v20; // r3
  int v21; // r3
  char v22; // r11
  idPresentable *v23; // r3
  usercmd_t v24; // [sp+50h] [-120h] BYREF
  usercmd_t v25; // [sp+90h] [-E0h] BYREF
  usercmd_t v26; // [sp+D0h] [-A0h] BYREF
  usercmd_t v27; // [sp+110h] [-60h] BYREF

  Driver = (idPlayer *)idVehicle::GetDriver(this);
  v3 = idPlayer::CastTo(c: Driver);
  if ( g_stopTime.valueInteger != 0 )
  {
    presentable = this->presentable;
    memset(&v24, 0, 9);
    v24.pos[2] = 0.0;
    v24.pos[1] = 0.0;
    v24.pos[0] = 0.0;
    v25.pos[2] = 0.0;
    v25.pos[1] = 0.0;
    memset(v24.angles, 0, 10);
    v25.pos[0] = 0.0;
    v24.yaw = 0;
    v24.pitch = 0;
    v24.roll = 0;
    v24.predictionStateBits = 0;
    memset(&v24.serverGameTime, 0, 18);
    *((_BYTE *)&v24 + 9) &= 0x3Fu;
    memset(&v25, 0, 9);
    memset(v25.angles, 0, 10);
    *((_BYTE *)&v25 + 9) &= 0x3Fu;
    v25.yaw = 0;
    v25.pitch = 0;
    v25.roll = 0;
    v25.predictionStateBits = 0;
    memset(&v25.serverGameTime, 0, 18);
    if ( presentable != nullptr )
      v5 = presentable->GetVehicleInterface(this: presentable);
    else
      v5 = nullptr;
    if ( (unsigned __int8)idPresentableVehicle::GetUserCommand(this: v5, seat: 0, previous: &v24, current: &v25) != 0 )
    {
      if ( idVehicle::GetGunner(this) == nullptr
        || (Gunner = idVehicle::GetGunner(this),
            (unsigned __int8)idClass::IsType(this: Gunner, superclass: &idPlayer::Type) == 0) )
      {
        v8 = this->presentable;
        if ( v8 != nullptr )
        {
          v9 = v8->GetVehicleInterface(this: v8);
          idPresentableVehicle::UpdateCrosshair(this: v9, seat: SEAT_DRIVER, prevcmd: &v24, usercmd: v10);
        }
        else
        {
          idPresentableVehicle::UpdateCrosshair(this: nullptr, seat: SEAT_DRIVER, prevcmd: &v24, usercmd: v6);
        }
      }
    }
  }
  else
  {
    if ( g_freeCam.valueInteger == 1 )
      return;
    usercmd_t::usercmd_t(this: &v27);
    usercmd_t::usercmd_t(this: &v26);
    v11 = this->presentable;
    if ( v11 != nullptr )
      v12 = v11->GetVehicleInterface(this: v11);
    else
      v12 = nullptr;
    if ( (unsigned __int8)idPresentableVehicle::GetUserCommand(this: v12, seat: 0, previous: &v27, current: &v26) != 0 )
    {
      idVehicle::CheckImpulseServerOnly(this, seat: 0, prevcmd: &v27, usercmd: &v26);
      if ( idVehicle::GetDriver(this) == nullptr )
        return;
      if ( idVehicle::GetGunner(this) == nullptr )
      {
        v14 = this->presentable;
        if ( v14 != nullptr )
          v15 = v14->GetVehicleInterface(this: v14);
        else
          v15 = nullptr;
        idPresentableVehicle::UpdateCrosshair(this: v15, seat: SEAT_DRIVER, prevcmd: &v27, usercmd: v13);
      }
    }
    v16 = v3->presentable;
    if ( v16 != nullptr )
      v17 = v16->GetPlayerInterface_2(this: v16);
    else
      v17 = nullptr;
    v18 = this->presentable;
    if ( v18 != nullptr )
      v19 = v18->GetVehicleInterface(this: v18);
    else
      v19 = nullptr;
    idPresentableVehicle::DriveControl(this: v19, player: v17);
    v20 = this->presentable;
    if ( v20 != nullptr )
      v21 = (int)v20->GetVehicleInterface(this: v20);
    else
      v21 = 0;
    v22 = *(_BYTE *)(v21 + 11878);
    v23 = this->presentable;
    this->vehicleAnimator.accelerating = v22;
    if ( v23 != nullptr )
      this->vehicleAnimator.handBraking = v23->GetVehicleInterface(this: v23)->handBraking;
    else
      this->vehicleAnimator.handBraking = MEMORY[0x2E6B];
  }
}


// ========================================================================
// ?RechargeBoost@idVehicle_Car@@QAAXXZ
// EA  : 0x82D3D5C8
// RVA : 0x00D3D5C8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::RechargeBoost(idVehicle_Car *this)
{
  int GameMs; // r3
  idPresentable *presentable; // r11
  unsigned int v4; // r31
  idPresentableVehicle *v5; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  presentable = this->presentable;
  v4 = GameMs;
  if ( presentable != nullptr )
    v5 = presentable->GetVehicleInterface(this: presentable);
  else
    v5 = nullptr;
  idPresentableVehicle::RechargeBoost(this: v5, time: v4);
}


// ========================================================================
// ?GetBoostPower@idVehicle_Car@@QBAMXZ
// EA  : 0x82D3D640
// RVA : 0x00D3D640
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

float __fastcall idVehicle_Car::GetBoostPower(idVehicle_Car *this)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v2; // r3
  double BoostPower; // fp1

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    v2 = presentable->GetVehicleInterface(this: presentable);
    BoostPower = idPresentableVehicle::GetBoostPower(this: v2);
  }
  else
  {
    BoostPower = idPresentableVehicle::GetBoostPower(this: nullptr);
  }
  return *((float *)&BoostPower + 1);
}


// ========================================================================
// ?BoostForce@idVehicle_Car@@QAAXM@Z
// EA  : 0x82D3D698
// RVA : 0x00D3D698
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::BoostForce(idVehicle_Car *this, double f)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v4; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = presentable->GetVehicleInterface(this: presentable);
  else
    v4 = nullptr;
  idPresentableVehicle::BoostForce(this: v4, f);
}


// ========================================================================
// ?ShowTireWobble@idVehicle_Car@@QAA_NXZ
// EA  : 0x82D3D6F0
// RVA : 0x00D3D6F0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

BOOL __fastcall idVehicle_Car::ShowTireWobble(idVehicle_Car *this)
{
  double v3; // fp31

  if ( vehicle_tireWobbleTest.valueFloat > 0.0 )
    return true;
  v3 = ((double (__fastcall *)(idVehicle_Car *))this->GetHealth)(a1: this);
  return v3 < (float)(this->GetMaxHealth(this) * (float)0.34999999);
}


// ========================================================================
// ?Collide@idVehicle_Car@@UAA?AW4collide_t@@HAAUtrace_t@@ABVidVec3@@@Z
// EA  : 0x82D3D790
// RVA : 0x00D3D790
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

int __fastcall idVehicle_Car::Collide(idVehicle_Car *this, int physId, trace_t *collision, const idVec3 *velocity)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v9; // r3

  if ( veh_ignoreCollide.valueInteger != 0 )
    return 0;
  presentable = this->presentable;
  if ( presentable != nullptr )
    v9 = presentable->GetVehicleInterface(this: presentable);
  else
    v9 = nullptr;
  return idPresentableVehicle::Collide(this: v9, physId, collision, velocity);
}


// ========================================================================
// ?Contact@idVehicle_Car@@UAA?AW4collide_t@@HAAUcontactInfo_t@@@Z
// EA  : 0x82D3D808
// RVA : 0x00D3D808
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

int __fastcall idVehicle_Car::Contact(idVehicle_Car *this, const int physId, contactInfo_t *contact)
{
  idPhysics *PhysicsForId; // r3
  idPhysics *v6; // r30
  int v7; // r9
  idVehicle_Car *v8; // r31
  idPhysics *v10; // r3
  double v13; // fp4
  double v14; // fp7
  physicsType_t type; // r11
  idPresentable *presentable; // r3
  int v17; // r3
  idPhysics *v18; // r3
  double valueFloat; // fp31
  float *v20; // r3
  idPhysics *Physics; // r3
  idVec3 *(__fastcall *GetLinearVelocity)(idPhysics *, idVec3 *, int); // r10
  double z; // fp29
  double y; // fp31
  double x; // fp30
  idPhysics *v26; // r3
  int v27; // r3
  float v28; // r6
  float v29; // r5
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // r11
  int v31; // r3
  float v32; // r7
  float v33; // r6
  idVec3 *(__fastcall *v34)(idPhysics *, idVec3 *, int); // r11
  float *v35; // r3
  double v36; // fp28
  double v37; // fp27
  double v38; // fp24
  double v39; // fp23
  idPhysics *v40; // r3
  float *v41; // r3
  double v42; // fp3
  double v43; // fp2
  double v44; // fp13
  double v45; // fp12
  double v46; // fp13
  double v47; // fp0
  double v48; // fp12
  double v49; // fp11
  idVec3 v50; // [sp+50h] [-D0h] BYREF
  idVec3 v51; // [sp+60h] [-C0h] BYREF
  float v52; // [sp+70h] [-B0h]
  float v53; // [sp+74h] [-ACh]
  float v54; // [sp+78h] [-A8h]
  float v55; // [sp+80h] [-A0h]
  float v56; // [sp+84h] [-9Ch]
  float v57; // [sp+88h] [-98h]
  idVec3 v58; // [sp+90h] [-90h] BYREF
  idVec3 v59[7]; // [sp+A0h] [-80h] BYREF

  PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: contact->physicsId);
  v6 = PhysicsForId;
  if ( PhysicsForId != nullptr )
  {
    v7 = PhysicsForId->entityNumber + 21563;
    v8 = *((idVehicle_Car **)&gameLocal->__vftable + v7);
    if ( v8 == nullptr || (unsigned __int8)idVehicle::IsTypeOf(c: *((idClass **)&gameLocal->__vftable + v7)) != 0 )
    {
      if ( idVehicle_Car::CastTo(c: v8) != nullptr )
        contact->flags |= 8u;
      if ( vehicle_extraCollision.valueInteger != 0 )
      {
        Physics = idEntity::GetPhysics(this);
        Physics->GetLinearVelocity(this: (idPhysics *)v59, result: (idVec3 *)Physics, a3: 0);
        GetLinearVelocity = v6->GetLinearVelocity;
        v51 = v59[0];
        GetLinearVelocity(this: (idPhysics *)&v58, result: (idVec3 *)v6, a3: 0);
        idVec3::NormalizeFast(this: &v51);
        idVec3::NormalizeFast(this: &v58);
        z = v51.z;
        y = v51.y;
        x = v51.x;
        if ( idMath::ACos16(a: (float)((float)(v58.x * v51.x) + (float)((float)(v51.y * v58.y) + (float)(v51.z * v58.z)))) < (double)idMath::ONEFOURTH_PI )
        {
          v26 = idEntity::GetPhysics(this);
          v27 = (int)v26->GetOrigin(this: v26, a2: 0);
          v28 = *(float *)(v27 + 4);
          v29 = *(float *)(v27 + 8);
          GetOrigin = v6->GetOrigin;
          v52 = *(float *)v27;
          v53 = v28;
          v54 = v29;
          v31 = (int)GetOrigin(this: v6, a2: 0);
          v32 = *(float *)(v31 + 4);
          v33 = *(float *)(v31 + 8);
          v34 = v6->GetLinearVelocity;
          v55 = *(float *)v31;
          v56 = v32;
          v57 = v33;
          v35 = (float *)v34(this: (idPhysics *)&v51, result: (idVec3 *)v6, a3: 0);
          v36 = (float)(v55 - v52);
          v37 = (float)(v56 - v53);
          v38 = (float)((float)(v55 + (float)(*v35 * (float)0.1)) - v52);
          v39 = (float)((float)(v56 + (float)(v35[1] * (float)0.1)) - v53);
          v40 = idEntity::GetPhysics(this);
          v41 = (float *)v40->GetGravityNormal(this: v40);
          v42 = v41[2];
          v43 = v41[1];
          v44 = (float)(v41[1] * (float)z);
          v45 = (float)(*v41 * (float)y);
          v51.y = (float)(*v41 * (float)z) - (float)(v41[2] * (float)x);
          v51.x = (float)((float)v42 * (float)y) - (float)v44;
          v51.z = (float)((float)v43 * (float)x) - (float)v45;
          idVec3::NormalizeFast(this: &v51);
          if ( (float)((float)((float)v39 * (float)v39) + (float)((float)v38 * (float)v38)) > (double)(float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36)) )
          {
            v48 = (float)((float)((float)((float)v36 * (float)x)
                                + (float)((float)((float)v37 * (float)y) + (float)((float)(v57 - v54) * (float)z)))
                        * (float)x);
            v49 = (float)((float)y
                        * (float)((float)((float)v36 * (float)x)
                                + (float)((float)((float)v37 * (float)y) + (float)((float)(v57 - v54) * (float)z))));
            v47 = (float)(v51.y
                        * (float)((float)((float)v36 * v51.x)
                                + (float)((float)((float)(v57 - v54) * v51.z) + (float)((float)v37 * v51.y))));
            v46 = (float)((float)((float)((float)v36 * v51.x)
                                + (float)((float)((float)(v57 - v54) * v51.z) + (float)((float)v37 * v51.y)))
                        * v51.x);
            if ( (float)((float)((float)v49 * (float)v49) + (float)((float)v48 * (float)v48)) > (double)(float)((float)((float)v47 * (float)v47) + (float)((float)v46 * (float)v46)) )
            {
              v6->ApplyImpulse(this: v6, a2: contact->bodyId, a3: &contact->point, a4: v59);
              return 2;
            }
          }
        }
      }
    }
    else
    {
      if ( (unsigned __int8)idProp_Moveable::IsTypeOf(c: v8) != 0 || (unsigned __int8)idBreakable::IsTypeOf(c: v8) != 0 )
      {
        v10 = idEntity::GetPhysics(this);
        v10->GetLinearVelocity(this: (idPhysics *)&v50, result: (idVec3 *)v10, a3: 0);
        _FP7 = (float)((float)((float)(v50.z * v50.z) + (float)((float)(v50.y * v50.y) + (float)(v50.x * v50.x)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f5, f7, f8, f13 }
        v13 = __frsqrte(_FP5);
        v14 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13
                                                                                            * (float)((float)((float)(v50.z * v50.z) + (float)((float)(v50.y * v50.y) + (float)(v50.x * v50.x))) * (float)0.5))
                                                                                    * (float)v13)
                                                                            - (float)1.5)
                                                            * (float)v13)
                                                    * (float)((float)((float)(v50.z * v50.z)
                                                                    + (float)((float)(v50.y * v50.y)
                                                                            + (float)(v50.x * v50.x)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v13
                                                                                    * (float)((float)((float)(v50.z * v50.z) + (float)((float)(v50.y * v50.y) + (float)(v50.x * v50.x)))
                                                                                            * (float)0.5))
                                                                            * (float)v13)
                                                                    - (float)1.5)
                                                    * (float)v13))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v13
                                                            * (float)((float)((float)(v50.z * v50.z)
                                                                            + (float)((float)(v50.y * v50.y)
                                                                                    + (float)(v50.x * v50.x)))
                                                                    * (float)0.5))
                                                    * (float)v13)
                                            - (float)1.5)
                            * (float)v13));
        v50.z = (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13 * (float)((float)((float)(v50.z * v50.z) + (float)((float)(v50.y * v50.y) + (float)(v50.x * v50.x))) * (float)0.5)) * (float)v13) - (float)1.5) * (float)v13) * (float)((float)((float)(v50.z * v50.z) + (float)((float)(v50.y * v50.y) + (float)(v50.x * v50.x))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)((float)(v50.z * v50.z) + (float)((float)(v50.y * v50.y) + (float)(v50.x * v50.x))) * (float)0.5)) * (float)v13) - (float)1.5) * (float)v13))
                                                                                              - (float)1.5)
                                                                              * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)((float)(v50.z * v50.z) + (float)((float)(v50.y * v50.y) + (float)(v50.x * v50.x))) * (float)0.5)) * (float)v13) - (float)1.5)
                                                                                      * (float)v13))
                                                                      * (float)((float)((float)(v50.z * v50.z)
                                                                                      + (float)((float)(v50.y * v50.y)
                                                                                              + (float)(v50.x * v50.x)))
                                                                              * (float)0.5))
                                                              * (float)v14)
                                                      - (float)1.5)
                                      * (float)v14)
                              * (float)((float)(v50.z * v50.z) + (float)((float)(v50.y * v50.y) + (float)(v50.x * v50.x))))
                      * (float)0.25)
              + v50.z;
        idVec3::NormalizeFast(this: &v50);
        v50.x = v50.x * vehicle_contactMoveableForce.valueFloat;
        v50.y = v50.y * vehicle_contactMoveableForce.valueFloat;
        v50.z = vehicle_contactMoveableForce.valueFloat * v50.z;
        v8->ApplyImpulseFromEntity(this: v8, a2: this, a3: 0, a4: &contact->point, a5: &v50);
      }
      else if ( (unsigned __int8)idPlayer::IsTypeOf(c: v8) != 0 || (unsigned __int8)idAI2::IsTypeOf(c: v8) != 0 )
      {
        return 2;
      }
      type = v6->type;
      if ( type == PHYSICS_STATICMULTI )
      {
        if ( v8->IsDead(this: v8) )
          return 2;
        presentable = this->presentable;
        v17 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
        if ( *(_DWORD *)(v17 + 17752) == 0 )
          return 2;
      }
      else if ( type == PHYSICS_RIGIDBODY || type == PHYSICS_AI || type == PHYSICS_AF )
      {
        v18 = idEntity::GetPhysics(this);
        valueFloat = vehicle_ignoreCollisionVelocity.valueFloat;
        v20 = (float *)v18->GetLinearVelocity(this: (idPhysics *)v59, result: (idVec3 *)v18, a3: 0);
        if ( (float)((float)(v20[2] * v20[2]) + (float)((float)(*v20 * *v20) + (float)(v20[1] * v20[1]))) > (double)(float)((float)valueFloat * (float)valueFloat) )
          return 2;
      }
    }
  }
  return 0;
}


// ========================================================================
// ?Event_StartEngine@idVehicle_Car@@QAA?AVeventVoid@@M@Z
// EA  : 0x82D3DD78
// RVA : 0x00D3DD78
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

idVehicle_Car *__fastcall idVehicle_Car::Event_StartEngine(idVehicle_Car *this, eventVoid *result, double start)
{
  int v4; // r3

  v4 = *(_DWORD *)&result[488];
  if ( v4 != 0 )
    *(_BYTE *)((*(int (__fastcall **)(int))(*(_DWORD *)v4 + 76))(a1: v4) + 11877) = start != 0.0;
  else
    MEMORY[0x2E65] = start != 0.0;
  return this;
}


// ========================================================================
// ?UpdateDriverViewAngles@idVehicle_Car@@UAAXABVusercmd_t@@0@Z
// EA  : 0x82D3DDF8
// RVA : 0x00D3DDF8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::UpdateDriverViewAngles(
        idVehicle_Car *this,
        const usercmd_t *prevcmd,
        const usercmd_t *usercmd)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v6; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v6 = presentable->GetVehicleInterface(this: presentable);
  else
    v6 = nullptr;
  idPresentableVehicle::UpdateDriverViewAngles(this: v6, prevcmd, usercmd);
}


// ========================================================================
// ?AllocPresentable@idVehicle_Car@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82D3DE68
// RVA : 0x00D3DE68
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

idPresentableVehicle *__fastcall idVehicle_Car::AllocPresentable(idVehicle_Car *this, idTreeAnimator *renderModel_)
{
  idPresentableVehicle *v4; // r29
  int entityNumber; // r27
  const idDeclVehicleProps *vehicleProps; // r25
  idAnimStack *v7; // r3
  idPresentableVehicle *result; // r3

  v4 = (idPresentableVehicle *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x5040u,
                                 tag: TAG_PRESENTABLE,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
  {
    entityNumber = this->entityNumber;
    vehicleProps = this->vehicleProps;
    v7 = this->GetAnimStack_2(this);
    result = idPresentableVehicle::idPresentableVehicle(
               this: v4,
               ent: this,
               renderModel_,
               animStack_: v7,
               animator_: &this->vehicleAnimator,
               vehicleProps_: vehicleProps,
               physicsCB_: &this->physicsCallbacks,
               entityNumber_: entityNumber);
  }
  else
  {
    result = nullptr;
  }
  result->showExhaust = false;
  return result;
}


// ========================================================================
// __unwind$495257
// EA  : 0x82D3DF18
// RVA : 0x00D3DF18
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void _unwind_495257()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?GetNumWheelsOnGround@idVehicle_Car@@QBAHXZ
// EA  : 0x82D3DF48
// RVA : 0x00D3DF48
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

int __fastcall idVehicle_Car::GetNumWheelsOnGround(idVehicle_Car *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return presentable->GetVehicleInterface(this: presentable)->numWheelsOnGround;
  else
    return MEMORY[0x4558];
}


// ========================================================================
// ?AddToPlayerCarList@idVehicle_Car@@QAAXXZ
// EA  : 0x82D3DFA0
// RVA : 0x00D3DFA0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::AddToPlayerCarList(idVehicle_Car *this)
{
  int v2; // r9
  idLinkList<idVehicle_Car> *head; // r10
  idLinkList<idVehicle_Car> *i; // r11
  idLinkList<idVehicle_Car> *next; // r11
  idEventReceiver *owner; // r3
  idLinkList<idVehicle_Car> *v7; // r9

  v2 = 0;
  head = gameLocal->playerRCCars.head;
  for ( i = head->next; i != head; ++v2 )
    i = i->next;
  if ( v2 >= vehicle_maxRCCarDrops.valueInteger )
  {
    next = gameLocal->playerRCCars.next;
    if ( next == nullptr || next == gameLocal->playerRCCars.head )
      owner = nullptr;
    else
      owner = next->owner;
    idEventReceiver::PostEventMS(this: owner, ev: &EV_Remove, time: 0);
  }
  this->droppedByPlayer = true;
  v7 = gameLocal->playerRCCars.head;
  this->rcControlNode.prev->next = this->rcControlNode.next;
  this->rcControlNode.next->prev = this->rcControlNode.prev;
  this->rcControlNode.prev = &this->rcControlNode;
  this->rcControlNode.head = &this->rcControlNode;
  this->rcControlNode.next = v7;
  this->rcControlNode.prev = v7->prev;
  v7->prev = &this->rcControlNode;
  this->rcControlNode.prev->next = &this->rcControlNode;
  this->rcControlNode.head = v7->head;
  this->rcControlNode.owner = this;
}


// ========================================================================
// ?UseAiProperties@idVehicle_Car@@UAAX_N@Z
// EA  : 0x82D3E090
// RVA : 0x00D3E090
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::UseAiProperties(idVehicle_Car *this, bool b)
{
  int v3; // r27
  int v4; // r26
  idVehicle_Car::aiProperties_t *p_aiProperties; // r28
  int v6; // r24
  const idDeclTable **i; // r25
  idPresentable *presentable; // r3
  int v9; // r3
  const idDeclTable *v10; // r29
  const idDeclTable *v11; // r31
  idPresentable *v12; // r3
  int v13; // r3
  double x; // fp0
  int v15; // r10
  char v16; // r11
  idPresentable *v17; // r11
  idRenderModel *model; // r11
  double y; // fp13
  double z; // fp12
  double v21; // fp11
  idPresentable *v22; // r3
  int v23; // r3
  float *v24; // r11
  idPresentable *v25; // r3
  int v26; // r3
  idPresentable *v27; // r11
  int v28; // r3
  const idDeclTable *v29; // r11
  idPresentable *v30; // r3
  idPresentableVehicle *v31; // r3
  double MaxSpeed; // fp1
  idPresentable *v33; // r3
  int v34; // r3
  idPresentable *v35; // r11
  float *v36; // r11
  idPresentable *v37; // r3
  int v38; // r3
  idPresentable *v39; // r3
  int v40; // r3
  idPresentable *v41; // r3
  int v42; // r3
  idPresentable *v43; // r3
  float *v44; // r3
  idPresentable *v45; // r3
  int v46; // r28
  idPresentable *v47; // r3
  int v48; // r3
  idPresentable *v49; // r3
  char *v50; // r31
  int v51; // r3
  int v52; // r10
  int v53; // r7
  idPresentable *v54; // r3
  idRenderModel *v55; // r29
  int v56; // r3
  float *v57; // r11
  double v58; // fp9
  double v59; // fp8
  idPresentable *v60; // r3
  int v61; // r3
  int v62; // r11
  float *v63; // r11
  idPresentable *v64; // r3
  int v65; // r3
  idPresentable *v66; // r3
  int v67; // r3
  idPresentable *v68; // r3
  int v69; // r3
  idPresentable *v70; // r3
  float *v71; // r3
  idPresentable *v72; // r3

  v3 = 0;
  v4 = 0;
  if ( b )
  {
    p_aiProperties = &this->aiProperties;
    v6 = 0;
    for ( i = this->aiProperties.friction_longitudinal; ; ++i )
    {
      presentable = this->presentable;
      v9 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
      if ( v6 >= *(_DWORD *)(v9 + 16492) )
        break;
      if ( i[6] != nullptr )
        v10 = i[6];
      else
        v10 = *(const idDeclTable **)((char *)&this->vehicleProps->wheels.list->friction_lateral + v4);
      v11 = *i;
      if ( *i == nullptr )
        v11 = *(const idDeclTable **)((char *)&this->vehicleProps->wheels.list->friction_longitudinal + v4);
      v12 = this->presentable;
      if ( v12 != nullptr )
        v13 = (int)v12->GetVehicleInterface(this: v12);
      else
        v13 = 0;
      x = p_aiProperties->cgLocation.x;
      v15 = *(_DWORD *)(*(_DWORD *)(v13 + 16488) + v3 + 4);
      *(_DWORD *)(v15 + 496) = v10;
      *(_DWORD *)(v15 + 492) = v11;
      if ( x != -1.0 || p_aiProperties->cgLocation.y != -1.0 || (v16 = 1, p_aiProperties->cgLocation.z != -1.0) )
        v16 = 0;
      if ( v16 == 0 )
      {
        v17 = this->presentable;
        if ( v17 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v17 = this->presentable;
        }
        model = v17->model;
        y = p_aiProperties->cgLocation.y;
        z = p_aiProperties->cgLocation.z;
        v21 = model->g.scale.z;
        this->baseCOG.x = p_aiProperties->cgLocation.x * model->g.scale.z;
        this->baseCOG.y = (float)y * (float)v21;
        this->baseCOG.z = (float)z * (float)v21;
        v22 = this->presentable;
        if ( v22 != nullptr )
          v23 = (int)v22->GetVehicleInterface(this: v22);
        else
          v23 = 0;
        v24 = *(float **)(*(_DWORD *)(v23 + 16488) + v3 + 4);
        v24[131] = this->baseCOG.x;
        v24[132] = this->baseCOG.y;
        v24[133] = this->baseCOG.z;
      }
      ++v6;
      v4 += 64;
      v3 += 12;
    }
    v25 = this->presentable;
    if ( v25 != nullptr )
      v26 = (int)v25->GetVehicleInterface(this: v25);
    else
      v26 = 0;
    v27 = this->presentable;
    this->savedProperties.brakeForce = *(float *)(v26 + 17452);
    if ( v27 != nullptr )
      v28 = (int)v27->GetVehicleInterface(this: v27);
    else
      v28 = 0;
    v29 = *(const idDeclTable **)(v28 + 17424);
    v30 = this->presentable;
    this->savedProperties.motorTorque = v29;
    if ( v30 != nullptr )
      v31 = v30->GetVehicleInterface(this: v30);
    else
      v31 = nullptr;
    MaxSpeed = idPresentableVehicle::GetMaxSpeed(this: v31);
    v33 = this->presentable;
    this->savedProperties.maxSpeed = MaxSpeed;
    if ( v33 != nullptr )
      v34 = (int)v33->GetVehicleInterface(this: v33);
    else
      v34 = 0;
    v35 = this->presentable;
    this->savedProperties.steerSpeed = *(float *)(v34 + 17448);
    if ( v35 != nullptr )
      v36 = (float *)v35->GetVehicleInterface(this: v35);
    else
      v36 = nullptr;
    v37 = this->presentable;
    this->savedProperties.stickControl.angularScale[0] = v36[4357];
    this->savedProperties.stickControl.angularScale[1] = v36[4358];
    this->savedProperties.stickControl.velocityScale[0] = v36[4359];
    this->savedProperties.stickControl.velocityScale[1] = v36[4360];
    if ( v37 != nullptr )
      v38 = (int)v37->GetVehicleInterface(this: v37);
    else
      v38 = 0;
    *(float *)(v38 + 17452) = this->aiProperties.brakeForce;
    v39 = this->presentable;
    if ( v39 != nullptr )
      v40 = (int)v39->GetVehicleInterface(this: v39);
    else
      v40 = 0;
    *(_DWORD *)(v40 + 17424) = this->aiProperties.motorTorque;
    v41 = this->presentable;
    if ( v41 != nullptr )
      v42 = (int)v41->GetVehicleInterface(this: v41);
    else
      v42 = 0;
    *(float *)(v42 + 17888) = this->aiProperties.maxSpeed;
    v43 = this->presentable;
    if ( v43 != nullptr )
      v44 = (float *)v43->GetVehicleInterface(this: v43);
    else
      v44 = nullptr;
    v44[4357] = this->aiProperties.stickControl.angularScale[0];
    v44[4358] = this->aiProperties.stickControl.angularScale[1];
    v44[4359] = this->aiProperties.stickControl.velocityScale[0];
    v44[4360] = this->aiProperties.stickControl.velocityScale[1];
    v45 = this->presentable;
    if ( v45 != nullptr )
      v45->GetVehicleInterface(this: v45)->maxSteerSpeed = this->aiProperties.steerSpeed;
    else
      MEMORY[0x4428] = this->aiProperties.steerSpeed;
    this->savedPropertiesUpdated = true;
  }
  else
  {
    v46 = 0;
    while ( 1 )
    {
      v47 = this->presentable;
      v48 = v47 != nullptr ? (int)v47->GetVehicleInterface(this: v47) : 0;
      if ( v4 >= *(_DWORD *)(v48 + 16492) )
        break;
      v49 = this->presentable;
      v50 = (char *)this->vehicleProps->wheels.list + v3;
      if ( v49 != nullptr )
        v51 = (int)v49->GetVehicleInterface(this: v49);
      else
        v51 = 0;
      v52 = *((_DWORD *)v50 + 11);
      v53 = *(_DWORD *)(*(_DWORD *)(v51 + 16488) + v46 + 4);
      *(_DWORD *)(v53 + 496) = *((_DWORD *)v50 + 12);
      *(_DWORD *)(v53 + 492) = v52;
      v54 = this->presentable;
      if ( v54 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v54 = this->presentable;
      }
      v55 = v54->model;
      if ( v54 != nullptr )
        v56 = (int)v54->GetVehicleInterface(this: v54);
      else
        v56 = 0;
      v57 = *(float **)(v56 + 11628);
      v58 = (float)(v57[79] * v55->g.scale.z);
      v59 = (float)(v57[78] * v55->g.scale.z);
      this->baseCOG.x = v57[77] * v55->g.scale.z;
      this->baseCOG.z = v58;
      this->baseCOG.y = v59;
      v60 = this->presentable;
      if ( v60 != nullptr )
        v61 = (int)v60->GetVehicleInterface(this: v60);
      else
        v61 = 0;
      ++v4;
      v62 = *(_DWORD *)(v61 + 16488) + v46;
      v3 += 64;
      v46 += 12;
      v63 = *(float **)(v62 + 4);
      v63[131] = this->baseCOG.x;
      v63[132] = this->baseCOG.y;
      v63[133] = this->baseCOG.z;
    }
    if ( this->savedPropertiesUpdated )
    {
      v64 = this->presentable;
      if ( v64 != nullptr )
        v65 = (int)v64->GetVehicleInterface(this: v64);
      else
        v65 = 0;
      *(float *)(v65 + 17452) = this->savedProperties.brakeForce;
      v66 = this->presentable;
      if ( v66 != nullptr )
        v67 = (int)v66->GetVehicleInterface(this: v66);
      else
        v67 = 0;
      *(_DWORD *)(v67 + 17424) = this->savedProperties.motorTorque;
      v68 = this->presentable;
      if ( v68 != nullptr )
        v69 = (int)v68->GetVehicleInterface(this: v68);
      else
        v69 = 0;
      *(float *)(v69 + 17888) = this->savedProperties.maxSpeed;
      v70 = this->presentable;
      if ( v70 != nullptr )
        v71 = (float *)v70->GetVehicleInterface(this: v70);
      else
        v71 = nullptr;
      v71[4357] = this->savedProperties.stickControl.angularScale[0];
      v71[4358] = this->savedProperties.stickControl.angularScale[1];
      v71[4359] = this->savedProperties.stickControl.velocityScale[0];
      v71[4360] = this->savedProperties.stickControl.velocityScale[1];
      v72 = this->presentable;
      if ( v72 != nullptr )
        v72->GetVehicleInterface(this: v72)->maxSteerSpeed = this->savedProperties.steerSpeed;
      else
        MEMORY[0x4428] = this->savedProperties.steerSpeed;
    }
  }
}


// ========================================================================
// ?ProcessLastUserCmd@idVehicle_Car@@QAAXXZ
// EA  : 0x82D3E6F0
// RVA : 0x00D3E6F0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::ProcessLastUserCmd(idVehicle_Car *this)
{
  idEntity *Driver; // r3
  int v3; // r11
  char v4; // r11
  bool v5; // zf
  idPresentable *presentable; // r3
  idPresentableVehicle *v7; // r3

  if ( idVehicle::GetDriver(this) != nullptr )
  {
    Driver = idVehicle::GetDriver(this);
    v3 = *(_DWORD *)(Driver->GetType(this: Driver) + 36);
    if ( v3 < idPlayer::Type.typeNum || (v5 = v3 <= idPlayer::Type.lastChild, v4 = 1, !v5) )
      v4 = 0;
    if ( v4 != 0 )
    {
      idVehicle_Car::DriveControl(this);
      if ( common->IsMultiplayer(this: common) )
      {
        presentable = this->presentable;
        if ( presentable != nullptr )
          v7 = presentable->GetVehicleInterface(this: presentable);
        else
          v7 = nullptr;
        idPresentableVehicle::EvaluateClientFire(this: v7);
      }
    }
  }
}


// ========================================================================
// ?SetGhostMode@idVehicle_Car@@QAAX_NH@Z
// EA  : 0x82D3E7C8
// RVA : 0x00D3E7C8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::SetGhostMode(idVehicle_Car *this, bool bl, int time)
{
  int v5; // r31
  idPresentable *presentable; // r3
  int v7; // r3
  idPresentable *v8; // r3
  int v9; // r3
  idAFBody *Body; // r3
  idAFBody::afBodyFlags_t fl; // r11
  int v12; // r30
  int i; // r31
  idPresentable *v14; // r3
  int v15; // r3
  idPresentable *v16; // r3
  int v17; // r3
  int v18; // r11
  idPhysics *Physics; // r3
  idPhysics *v20; // r3
  idClipModel *v21; // r3
  int v22; // r11
  idPresentable *v23; // r11
  int valueInteger; // r31
  idRenderModel *model; // r10
  idPresentable *v26; // r3
  int v27; // r3
  idPresentable *v28; // r3
  int v29; // r3
  idAFBody *v30; // r3
  idAFBody::afBodyFlags_t v31; // r11
  int v32; // r30
  int j; // r31
  idPresentable *v34; // r3
  int v35; // r3
  idPresentable *v36; // r3
  int v37; // r3
  int v38; // r11
  idPhysics *v39; // r3
  idPhysics *v40; // r3
  idClipModel *v41; // r3
  idPresentable *v42; // r11
  idPresentable *v43; // r11
  idRenderModel *v44; // r10

  v5 = 0;
  if ( bl )
  {
    while ( 1 )
    {
      presentable = this->presentable;
      v7 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
      if ( v5 >= (int)XAUDIO2::CX2SubmixVoice::ProcessingStage(this: (XAUDIO2::CX2SubmixVoice *)(v7 + 16512)) )
        break;
      v8 = this->presentable;
      if ( v8 != nullptr )
        v9 = (int)v8->GetVehicleInterface(this: v8);
      else
        v9 = 0;
      Body = idPhysics_AF::GetBody(this: (idPhysics_AF *)(v9 + 16512), id: v5);
      if ( Body != nullptr )
      {
        fl = Body->fl;
        Body->clipMask = 33;
        Body->fl = (idAFBody::afBodyFlags_t)(*(_BYTE *)&fl | 0x80);
      }
      ++v5;
    }
    v12 = 0;
    for ( i = 0; ; i += 12 )
    {
      v14 = this->presentable;
      v15 = v14 != nullptr ? (int)v14->GetVehicleInterface(this: v14) : 0;
      if ( v12 >= *(_DWORD *)(v15 + 16492) )
        break;
      v16 = this->presentable;
      if ( v16 != nullptr )
        v17 = (int)v16->GetVehicleInterface(this: v16);
      else
        v17 = 0;
      ++v12;
      v18 = *(_DWORD *)(v17 + 16488) + i;
      *(_DWORD *)(*(_DWORD *)(v18 + 4) + 520) = 33;
    }
    this->vehicleAnimator.clipMask = 33;
    if ( idEntity::GetPhysics(this) != nullptr )
    {
      Physics = idEntity::GetPhysics(this);
      if ( Physics->GetClipModel(this: Physics, a2: 0) != nullptr )
      {
        v20 = idEntity::GetPhysics(this);
        v21 = v20->GetClipModel(this: v20, a2: 0);
        idClipModel::SetContents(this: v21, newContents: 131712);
      }
    }
    if ( time == -1 )
      v22 = 0;
    else
      v22 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + time;
    this->ghostEndTime = v22;
    if ( vehicle_ghostRespawnEffect.valueInteger == 2 )
    {
      v23 = this->presentable;
      valueInteger = vehicle_ghostHighlight.valueInteger;
      if ( v23 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v23 = this->presentable;
      }
      model = v23->model;
      v23->highlightColor = valueInteger;
      model->g.highlightColor = valueInteger;
    }
  }
  else
  {
    while ( 1 )
    {
      v26 = this->presentable;
      v27 = v26 != nullptr ? (int)v26->GetVehicleInterface(this: v26) : 0;
      if ( v5 >= (int)XAUDIO2::CX2SubmixVoice::ProcessingStage(this: (XAUDIO2::CX2SubmixVoice *)(v27 + 16512)) )
        break;
      v28 = this->presentable;
      if ( v28 != nullptr )
        v29 = (int)v28->GetVehicleInterface(this: v28);
      else
        v29 = 0;
      v30 = idPhysics_AF::GetBody(this: (idPhysics_AF *)(v29 + 16512), id: v5);
      if ( v30 != nullptr )
      {
        v31 = v30->fl;
        v30->clipMask = 107553;
        v30->fl = (idAFBody::afBodyFlags_t)(*(_BYTE *)&v31 | 0x80);
      }
      ++v5;
    }
    v32 = 0;
    for ( j = 0; ; j += 12 )
    {
      v34 = this->presentable;
      v35 = v34 != nullptr ? (int)v34->GetVehicleInterface(this: v34) : 0;
      if ( v32 >= *(_DWORD *)(v35 + 16492) )
        break;
      v36 = this->presentable;
      if ( v36 != nullptr )
        v37 = (int)v36->GetVehicleInterface(this: v36);
      else
        v37 = 0;
      ++v32;
      v38 = *(_DWORD *)(v37 + 16488) + j;
      *(_DWORD *)(*(_DWORD *)(v38 + 4) + 520) = 107553;
    }
    this->vehicleAnimator.clipMask = 107553;
    if ( idEntity::GetPhysics(this) != nullptr )
    {
      v39 = idEntity::GetPhysics(this);
      if ( v39->GetClipModel(this: v39, a2: 0) != nullptr )
      {
        v40 = idEntity::GetPhysics(this);
        v41 = v40->GetClipModel(this: v40, a2: 0);
        idClipModel::SetContents(this: v41, newContents: 197120);
      }
    }
    v42 = this->presentable;
    this->ghostEndTime = -1;
    if ( v42 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v42 = this->presentable;
    }
    idRenderModel::SetModelFade(this: v42->model, v: 1.0);
    if ( vehicle_ghostRespawnEffect.valueInteger == 2 )
    {
      v43 = this->presentable;
      if ( v43 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v43 = this->presentable;
      }
      v44 = v43->model;
      v43->highlightColor = HIGHLIGHT_COLOR_NONE;
      v44->g.highlightColor = HIGHLIGHT_COLOR_NONE;
    }
  }
}


// ========================================================================
// ?HandleSpikePit@idVehicle_Car@@QAAXXZ
// EA  : 0x82D3EBA8
// RVA : 0x00D3EBA8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::HandleSpikePit(idVehicle_Car *this)
{
  int (*GetGameMs)(void); // ctr
  int v3; // r10
  idGameLocal *v4; // r3
  idEntityPtr<idEntity> *LastCollision; // r3
  idVehicle_Car *v6; // r3
  idVehicle_Car *v7; // r29
  _DWORD *v8; // r28
  idPhysics *Physics; // r28
  idPhysics *v10; // r27
  float *v11; // r28
  float *v12; // r3
  double v13; // fp9
  double v14; // fp7
  idPhysics *v15; // r3
  float *v16; // r3
  long double v17; // fp2
  double v18; // fp31
  long double v19; // fp2
  char v20; // r27
  char v21; // r26
  int v22; // r3
  int NumSpikesNearPos; // r25
  bool v24; // r5
  idPhysics *v25; // r30
  idPhysics *v26; // r28
  float *v27; // r30
  float *v28; // r3
  double v29; // fp31
  double v30; // fp30
  double v31; // fp29
  idPhysics *v32; // r3
  float *v33; // r3
  idPhysics *v34; // r30
  idPhysics *v35; // r28
  float *v36; // r30
  float *v37; // r3
  double v38; // fp31
  double v39; // fp30
  double v40; // fp29
  idPhysics *v41; // r3
  float *v42; // r3
  idPhysics *v43; // r3
  idPhysics *v44; // r3
  float *v45; // r3
  int v46; // r4
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  _DWORD *v48; // r3
  int v49; // r9
  int v50; // r8
  double v51; // fp0
  double v52; // fp31
  idPhysics *v53; // r3
  idVehicleAI *Driver; // r3
  idVehicleAI *v55; // r3
  double v56; // fp31
  idVehicle_Car_vtbl *v57; // r30
  const idDeclDamage *spikeDamage; // r28
  idEntity *v59; // r3
  idInventoryItem *v60; // [sp+50h] [-A0h] BYREF
  idInventoryItem *v61; // [sp+54h] [-9Ch] BYREF
  idVec3 v62; // [sp+58h] [-98h] BYREF
  idVec3 v63; // [sp+68h] [-88h] BYREF
  _DWORD v64[4]; // [sp+78h] [-78h] BYREF
  float v65[4]; // [sp+88h] [-68h] BYREF

  if ( !this->canBePitted )
  {
    GetGameMs = (int (*)(void))gameLocal->GetGameMs;
LABEL_48:
    this->pitStartTime = GetGameMs();
    return;
  }
  if ( idVehicle::VehicleAiIsOccupant(this) == nullptr )
    goto LABEL_46;
  v3 = *(_DWORD *)(idVehicle::GetLastCollision(this) + 12);
  v4 = gameLocal;
  if ( gameLocal->spawnIds.ptr[v3 & 0x1FFF] != v3 >> 13 )
  {
LABEL_47:
    GetGameMs = (int (*)(void))v4->GetGameMs;
    goto LABEL_48;
  }
  LastCollision = (idEntityPtr<idEntity> *)idVehicle::GetLastCollision(this);
  v6 = (idVehicle_Car *)idEntityPtr<idEntity const>::operator->(this: LastCollision + 3);
  v7 = idVehicle_Car::CastTo(c: v6);
  if ( v7 == nullptr )
    goto LABEL_46;
  if ( idVehicle_Car::GetNumWheelsOnGround(this) < 3 )
    goto LABEL_46;
  if ( idVehicle_Car::GetNumWheelsOnGround(this: v7) < 3 )
    goto LABEL_46;
  if ( idVehicle::PlayerIsOccupant(this: v7) == nullptr )
    goto LABEL_46;
  v8 = (_DWORD *)idVehicle::GetLastCollision(this);
  if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - *v8 > 200 )
    goto LABEL_46;
  Physics = idEntity::GetPhysics(this: v7);
  v10 = idEntity::GetPhysics(this);
  v11 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v12 = (float *)v10->GetOrigin(this: v10, a2: 0);
  v13 = (float)(v12[2] - v11[2]);
  v14 = (float)(v12[1] - v11[1]);
  v62.x = *v12 - *v11;
  v62.z = v13;
  v62.y = v14;
  idVec3::NormalizeFast(this: &v62);
  v15 = idEntity::GetPhysics(this);
  v16 = (float *)v15->GetAxis(this: v15, a2: 0);
  *((double *)&v17 + 1) = v16[4];
  *(double *)&v17 = (float)(idMath::M_DEG2RAD * (float)35.0);
  v18 = (float)((float)(v16[3] * v62.x) + (float)((float)(v16[5] * v62.z) + (float)(v16[4] * v62.y)));
  v19 = cos(x: v17);
  if ( __fabs(v18) < (float)*(double *)&v19 )
  {
LABEL_46:
    v4 = gameLocal;
    goto LABEL_47;
  }
  v60 = nullptr;
  v20 = 0;
  v61 = nullptr;
  v21 = 0;
  v22 = idVehicle::GetLastCollision(this);
  NumSpikesNearPos = idVehicle::GetNumSpikesNearPos(
                       this: *(idVehicle **)(v22 + 20),
                       pos: *(idVec3 **)(v22 + 24),
                       spike1: (idInventoryItem **)__ROL4__(*(_DWORD *)(v22 + 28), 32),
                       spike2: (idJob **)&v60,
                       a5: (idJob **)&v61);
  if ( idVehicle::GetCurrentSpeedInMPH(this: v7) >= 90.0 )
  {
    if ( NumSpikesNearPos == 2 )
    {
      v25 = idEntity::GetPhysics(this: v7);
      v26 = idEntity::GetPhysics(this);
      v27 = (float *)v25->GetOrigin(this: v25, a2: 0);
      v28 = (float *)v26->GetOrigin(this: v26, a2: 0);
      v29 = (float)(*v28 - *v27);
      v30 = (float)(v28[1] - v27[1]);
      v31 = (float)(v28[2] - v27[2]);
      v32 = idEntity::GetPhysics(this: v7);
      v33 = (float *)v32->GetAxis(this: v32, a2: 0);
      if ( (float)((float)(*v33 * (float)v29) + (float)((float)(v33[1] * (float)v30) + (float)(v33[2] * (float)v31))) >= 25.0 )
        NumSpikesNearPos = 1;
      else
        v20 = 1;
    }
    if ( v20 == 0 && NumSpikesNearPos >= 1 )
    {
      v34 = idEntity::GetPhysics(this: v7);
      v35 = idEntity::GetPhysics(this);
      v36 = (float *)v34->GetOrigin(this: v34, a2: 0);
      v37 = (float *)v35->GetOrigin(this: v35, a2: 0);
      v38 = (float)(*v37 - *v36);
      v39 = (float)(v37[1] - v36[1]);
      v40 = (float)(v37[2] - v36[2]);
      v41 = idEntity::GetPhysics(this: v7);
      v42 = (float *)v41->GetAxis(this: v41, a2: 0);
      if ( (float)((float)(*v42 * (float)v38) + (float)((float)(v42[2] * (float)v40) + (float)(v42[1] * (float)v39))) < 400.0 )
        v20 = 1;
    }
    if ( v20 != 0 )
    {
      if ( v60 != nullptr )
        idVehicle::ApplyArmorSave(this: v7, item: v60, damage: 10000.0, throwItem: v24, a5: 1u);
      if ( v61 != nullptr )
        idVehicle::ApplyArmorSave(this: v7, item: v61, damage: 10000.0, throwItem: v24, a5: 1u);
    }
  }
  if ( v20 == 0 && idVehicle::GetCurrentSpeedInMPH(this: v7) >= 60.0 )
  {
    v43 = idEntity::GetPhysics(this);
    v43->GetLinearVelocity(this: (idPhysics *)&v63, result: (idVec3 *)v43, a3: 0);
    idVec3::NormalizeFast(this: &v63);
    v44 = idEntity::GetPhysics(this);
    v45 = (float *)v44->GetAxis(this: v44, a2: 0);
    if ( (float)((float)(*v45 * v63.x) + (float)((float)(v45[1] * v63.y) + (float)(v45[2] * v63.z))) <= 0.86602497 )
    {
      v46 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - this->pitStartTime;
      if ( v46 > 500 )
      {
        v20 = 1;
        v21 = 1;
        idLib::Printf(fmt: "time: %d\n", v46);
      }
    }
  }
  if ( v20 != 0 )
  {
    this->pitLastEntity = v7;
    this->pitStartTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr )
    {
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
      if ( idRenderModel::IsRendered(this: TreeAnimatorFromPresentable) )
      {
        v48 = (_DWORD *)idVehicle::GetLastCollision(this);
        v49 = v48[6];
        v50 = v48[7];
        v64[0] = v48[5];
        v64[1] = v49;
        v64[2] = v50;
        v51 = (float)(idVehicle::GetCurrentSpeedInMPH(this) * (float)0.014285714);
        if ( v51 >= 0.0 )
        {
          if ( v51 > 1.0 )
            v51 = 1.0;
        }
        else
        {
          v51 = 0.0;
        }
        v52 = (float)((float)(vehicle_pitPower.valueFloat * (float)1000000.0) * (float)v51);
        if ( v21 == 0 )
          v52 = (float)((float)((float)(vehicle_pitPower.valueFloat * (float)1000000.0) * (float)v51) * (float)0.34999999);
        v53 = idEntity::GetPhysics(this);
        v65[0] = 0.0;
        v65[1] = 0.0;
        v65[2] = v52;
        v53->ApplyImpulse(this: v53, a2: 0, a3: (const idVec3 *)v64, a4: (const idVec3 *)v65);
        Driver = (idVehicleAI *)idVehicle::GetDriver(this);
        v55 = idVehicleAI::CastTo(c: Driver);
        if ( v55 != nullptr )
          idVehicleAI::SetNoControl(this: v55, timeMS: 1000, velocitySqr: 250000.0);
      }
    }
  }
  if ( NumSpikesNearPos > 0 )
  {
    if ( NumSpikesNearPos == 1 )
      v56 = 1.0;
    else
      v56 = 2.0;
    v57 = this->__vftable;
    spikeDamage = this->damages.spikeDamage;
    v59 = idVehicle::GetDriver(this: v7);
    ((void (__fastcall *)(idVehicle_Car *, idVehicle_Car *, idEntity *, const idDeclDamage *, double))v57->Damage)(
      a1: this,
      a2: v7,
      a3: v59,
      a4: spikeDamage,
      a5: v56);
  }
}


// ========================================================================
// ?GetEffectsDef@idVehicle_Car@@AAAABVidVehicleEffectsDef@@XZ
// EA  : 0x82D3F2A8
// RVA : 0x00D3F2A8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

const idVehicleEffectsDef *__fastcall idVehicle_Car::GetEffectsDef(idVehicle_Car *this)
{
  const idDeclVehicleProps *vehicleProps; // r11

  vehicleProps = this->vehicleProps;
  if ( vehicleProps != nullptr )
    return &vehicleProps->effects;
  if ( (_S21_0 & 1) == 0 )
  {
    _S21_0 |= 1u;
    idVehicleEffectsDef::idVehicleEffectsDef(this: &fakeEffects);
  }
  idLib::Warning(fmt: "idVehicle_Car::GetEffectsDef: GetVehicleProps() == NULL");
  return &fakeEffects;
}


// ========================================================================
// ??0idVehicle_Car@@QAA@XZ
// EA  : 0x82D3F3A0
// RVA : 0x00D3F3A0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

idVehicle_Car *__fastcall idVehicle_Car::idVehicle_Car(idVehicle_Car *this)
{
  int v2; // ctr
  float *p_previousCompression; // r11
  const idDeclEntityDef **p_healthItem; // r11
  int i; // ctr
  char *v6; // r10
  int v7; // ctr

  idVehicle::idVehicle(this);
  this->__vftable = (idVehicle_Car_vtbl *)&idVehicle_Car::`vftable';
  this->voiceOverNameString.index = -1;
  idVehicle_Car::aiProperties_t::aiProperties_t(this: &this->aiProperties);
  idVehicle_Car::aiProperties_t::aiProperties_t(this: &this->savedProperties);
  this->enterTarget.spawnId.value = 0x1FFF;
  this->soundState.engineRunning = false;
  this->soundState.nextZoomTime = 0;
  this->soundState.nextBackfireTime = 0;
  this->soundState.nextBurpTime = 0;
  this->soundState.isCruising = false;
  this->soundState.fadeMusicTime = 0;
  this->damages.vehicle = nullptr;
  this->damages.runOver = nullptr;
  this->damages.world = nullptr;
  this->damages.prop = nullptr;
  this->damages.explode = nullptr;
  this->damages.fire = nullptr;
  this->damages.rcbombDecl = nullptr;
  this->damages.rcbombSplashDecl = nullptr;
  this->damages.spikeDamage = nullptr;
  this->damages.collisionDeathDecl = nullptr;
  this->vehicleSoundEventDecl = nullptr;
  this->explosionEventDecl = nullptr;
  this->cinimaticViewPoint.spawnId.value = 0x1FFF;
  this->specialDeathAttacker.spawnId.value = 0x1FFF;
  this->callOnCollision.allocedAndFlag = 20;
  this->callOnCollision.data = this->callOnCollision.baseBuffer;
  this->callOnCollision.len = 0;
  this->callOnCollision.baseBuffer[0] = 0;
  idVehicle_Megabooster::idVehicle_Megabooster(this: &this->boostpad);
  this->hitList.list = nullptr;
  this->hitList.granularity = 0;
  this->hitList.memTag = 5;
  this->hitList.listStatic = 0;
  this->hitList.size = 0;
  this->hitList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->hitList);
  this->controllingPlayer.spawnId.value = 0x1FFF;
  this->rcControlNode.head = &this->rcControlNode;
  this->rcControlNode.owner = nullptr;
  this->rcControlNode.next = &this->rcControlNode;
  this->rcControlNode.prev = &this->rcControlNode;
  this->magnetRange = vehicle_tractorRange.valueFloat;
  this->baseCOG.z = 0.0;
  this->baseCOG.y = 0.0;
  this->baseCOG.x = 0.0;
  this->dropItemsWhenKilled = true;
  this->hideSteeringWheel = false;
  this->boostItem = nullptr;
  this->rcBombDropItem = nullptr;
  this->savedPropertiesUpdated = false;
  v2 = 6;
  this->ghostEndTime = -1;
  p_previousCompression = &this->previousCompression;
  this->ghostCollision = false;
  this->lastOrigin = vec3_origin;
  this->frictionOverrideTime = 0;
  this->frictionOverrideFront = -1.0;
  this->pitStartTime = 0;
  this->frictionOverrideRear = -1.0;
  this->pitLastEntity = nullptr;
  this->previousCompression = 0.0;
  this->damageSandwichFunTime[0] = 0;
  this->damageSandwichFunTime[1] = 0;
  do
  {
    *++p_previousCompression = 0.0;
    --v2;
  }
  while ( v2 != 0 );
  p_healthItem = &this->healthItem;
  for ( i = 10; i != 0; --i )
    *++p_healthItem = nullptr;
  this->canBePitted = true;
  this->specialDeathActive = false;
  v6 = &this->callOnCollision.baseBuffer[16];
  this->specialDeathStartTime = 0;
  this->destroyed = false;
  this->specialDeathCollision = false;
  this->specialDeath = DEATH_INSTANT;
  v7 = 6;
  this->forceInstantDeath = false;
  this->playerWasOccupant = false;
  this->attackOverTime = 0;
  this->cinimaticViewPoint.spawnId.value = 0x1FFF;
  this->reducedRCFadeBack = false;
  this->savedSurfaceType = -1;
  this->vehicleType = VEHICLE_TYPE_NONE;
  do
  {
    v6 += 4;
    *(_DWORD *)v6 = 0;
    --v7;
  }
  while ( v7 != 0 );
  this->boostlevel = 1;
  this->movePlayerToVehicle = 0;
  this->boostItem = nullptr;
  this->ammoItem = nullptr;
  this->healthItem = nullptr;
  this->cameraBreath = ang_zero;
  this->cameraBreathPrev = ang_zero;
  this->cameraBreathNextUpdate = 0;
  memset(Dst: this->vquInfo, Val: 0, Size: sizeof(this->vquInfo));
  this->lastThinkHealth = 0.0;
  this->droppedByPlayer = false;
  this->isWasteland2 = false;
  this->constantCollisionScale = 1.0;
  return this;
}


// ========================================================================
// __unwind$498242
// EA  : 0x82D3F68C
// RVA : 0x00D3F68C
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void _unwind_498242()
{
  int v0; // r12

  idVehicle::~idVehicle(this: *(idVehicle **)(v0 - 176 + 196));
}


// ========================================================================
// __unwind$498243
// EA  : 0x82D3F6B4
// RVA : 0x00D3F6B4
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void _unwind_498243()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 176 + 196) + 17252));
}


// ========================================================================
// __unwind$498244
// EA  : 0x82D3F6E0
// RVA : 0x00D3F6E0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void _unwind_498244()
{
  int v0; // r12

  idVehicle_Megabooster::~idVehicle_Megabooster(this: (idVehicle_Megabooster *)(*(_DWORD *)(v0 - 176 + 196) + 17312));
}


// ========================================================================
// ??1idVehicle_Car@@UAA@XZ
// EA  : 0x82D3F810
// RVA : 0x00D3F810
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::~idVehicle_Car(idVehicle_Car *this)
{
  this->__vftable = (idVehicle_Car_vtbl *)&idVehicle_Car::`vftable';
  if ( this->droppedByPlayer )
  {
    this->rcControlNode.prev->next = this->rcControlNode.next;
    this->rcControlNode.next->prev = this->rcControlNode.prev;
    this->rcControlNode.next = &this->rcControlNode;
    this->rcControlNode.prev = &this->rcControlNode;
    this->rcControlNode.head = &this->rcControlNode;
  }
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->rcControlNode);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->hitList);
  idVehicle_Megabooster::~idVehicle_Megabooster(this: &this->boostpad);
  idStr::FreeData(this: &this->callOnCollision);
  idVehicle::~idVehicle(this);
}


// ========================================================================
// __unwind$498859
// EA  : 0x82D3F8B0
// RVA : 0x00D3F8B0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void _unwind_498859()
{
  int v0; // r12

  idVehicle::~idVehicle(this: *(idVehicle **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$498860
// EA  : 0x82D3F8D8
// RVA : 0x00D3F8D8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void _unwind_498860()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 17252));
}


// ========================================================================
// __unwind$498861
// EA  : 0x82D3F904
// RVA : 0x00D3F904
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void _unwind_498861()
{
  int v0; // r12

  idVehicle_Megabooster::~idVehicle_Megabooster(this: (idVehicle_Megabooster *)(*(_DWORD *)(v0 - 112 + 132) + 17312));
}


// ========================================================================
// ?Respawn@idVehicle_Car@@UAAXXZ
// EA  : 0x82D3F930
// RVA : 0x00D3F930
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::Respawn(idVehicle_Car *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  idPresentable *v4; // r3
  idPresentableVehicle *v5; // r3

  idVehicle::Respawn(this);
  presentable = this->presentable;
  this->specialDeathActive = false;
  this->specialDeathStartTime = 0;
  this->destroyed = false;
  this->specialDeathCollision = false;
  this->specialDeath = DEATH_INSTANT;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v3 = 0;
  *(_DWORD *)(v3 + 20420) = 0;
  *(_DWORD *)(v3 + 20416) = 0;
  v4 = this->presentable;
  if ( v4 != nullptr )
    v5 = v4->GetVehicleInterface(this: v4);
  else
    v5 = nullptr;
  idPresentableVehicle::Respawn(this: v5);
  idVehicle_Car::SetGhostMode(this, bl: this->ghostCollision, time: -1);
}


// ========================================================================
// ?Event_SetEnterTarget@idVehicle_Car@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82D3F9E0
// RVA : 0x00D3F9E0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idVehicle_Car::Event_SetEnterTarget@<r4>(
        idVehicle_Car *this@<r3>,
        int result@<r4>,
        idEntity *target@<r5>)
{
  if ( target != nullptr )
    *(_DWORD *)(result + 17080) = (gameLocal->spawnIds.ptr[target->entityNumber] << 13) | target->entityNumber;
  else
    *(_DWORD *)(result + 17080) = 0x1FFF;
  return result;
}


// ========================================================================
// ?Event_RemoveEnterTarget@idVehicle_Car@@QAA?AVeventVoid@@XZ
// EA  : 0x82D3FA20
// RVA : 0x00D3FA20
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idVehicle_Car::Event_RemoveEnterTarget(idVehicle_Car *this)
{
  __int64 result; // r4 OVERLAPPED

  *(_DWORD *)(result + 17080) = 0x1FFF;
  return result;
}


// ========================================================================
// ?ApplyCollisionDamage@idVehicle_Car@@QAAXXZ
// EA  : 0x82D3FA90
// RVA : 0x00D3FA90
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::ApplyCollisionDamage(idVehicle_Car *this)
{
  bool v2; // r28
  int value; // r7
  idEntity *v4; // r3
  idVehicle_Car_vtbl *v5; // r30
  const idDeclDamage *v6; // r29
  idEntity *Driver; // r3
  int v8; // r9
  idEntity *v9; // r3
  idEntity *v10; // r30
  idVehicle_Car_vtbl *v11; // r29
  const idDeclDamage *CollisionDamage; // r3

  v2 = this->TakesDamage(this);
  *(_BYTE *)&this->flags |= 2u;
  value = this->collisionDamageAttacker.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v4 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v4) != nullptr )
  {
    v8 = this->collisionDamageAttacker.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13 && (v9 = gameLocal->entities.ptr[v8 & 0x1FFF]) != nullptr )
      v10 = idEntity::CastTo(c: v9);
    else
      v10 = nullptr;
    v11 = this->__vftable;
    CollisionDamage = idVehicle::GetCollisionDamage(this);
    ((void (__fastcall *)(idVehicle_Car *, _DWORD, idEntity *, const idDeclDamage *, double))v11->Damage)(
      a1: this,
      a2: 0,
      a3: v10,
      a4: CollisionDamage,
      a5: 1.0);
  }
  else
  {
    v5 = this->__vftable;
    v6 = idVehicle::GetCollisionDamage(this);
    Driver = idVehicle::GetDriver(this);
    ((void (__fastcall *)(idVehicle_Car *, _DWORD, idEntity *, const idDeclDamage *, double))v5->Damage)(
      a1: this,
      a2: 0,
      a3: Driver,
      a4: v6,
      a5: 1.0);
  }
  idVehicle::SetCollisionDamage(this, decl: nullptr, delayMS: 0, attacker: nullptr);
  *(_BYTE *)&this->flags = (2 * v2) & 2 | *(_BYTE *)&this->flags & 0xFD;
}


// ========================================================================
// ?ExtraCollisionReactions@idVehicle_Car@@QAAXPAVidEntity@@AAUtrace_t@@@Z
// EA  : 0x82D3FBE0
// RVA : 0x00D3FBE0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::ExtraCollisionReactions(idVehicle_Car *this, idEntity *otherEntity, trace_t *collision)
{
  idPhysics *Physics; // r28
  idPhysics *v7; // r27
  float *v8; // r28
  float *v9; // r3
  double collisionVerticalImpulse; // fp10
  double v11; // fp8
  double v12; // fp4
  double v15; // fp3
  double v16; // fp3
  double v17; // fp9
  double v18; // fp8
  double v19; // fp7
  idPhysics *v20; // r3
  float v21[4]; // [sp+60h] [-190h] BYREF
  idScriptFunction v22; // [sp+70h] [-180h] BYREF

  if ( this->collisionImpulse != 0.0 || this->collisionVerticalImpulse != 0.0 )
  {
    Physics = idEntity::GetPhysics(this: otherEntity);
    v7 = idEntity::GetPhysics(this);
    v8 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v9 = (float *)v7->GetOrigin(this: v7, a2: 0);
    collisionVerticalImpulse = this->collisionVerticalImpulse;
    v11 = (float)(v9[1] - v8[1]);
    v12 = (float)(v9[2] - v8[2]);
    _FP9 = (float)((float)((float)((float)v12 * (float)v12)
                         + (float)((float)((float)(*v9 - *v8) * (float)(*v9 - *v8)) + (float)((float)v11 * (float)v11)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f5, f9, f1, f13 }
    v15 = __frsqrte(_FP5);
    v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                        * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)(*v9 - *v8) * (float)(*v9 - *v8)) + (float)((float)v11 * (float)v11)))
                                                                                                * (float)0.5))
                                                                                * (float)v15)
                                                                        - (float)1.5)
                                                        * (float)v15)
                                                * (float)((float)((float)((float)v12 * (float)v12)
                                                                + (float)((float)((float)(*v9 - *v8) * (float)(*v9 - *v8))
                                                                        + (float)((float)v11 * (float)v11)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v15
                                                                                * (float)((float)((float)((float)v12 * (float)v12)
                                                                                                + (float)((float)((float)(*v9 - *v8) * (float)(*v9 - *v8)) + (float)((float)v11 * (float)v11)))
                                                                                        * (float)0.5))
                                                                        * (float)v15)
                                                                - (float)1.5)
                                                * (float)v15))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v15
                                                        * (float)((float)((float)((float)v12 * (float)v12)
                                                                        + (float)((float)((float)(*v9 - *v8)
                                                                                        * (float)(*v9 - *v8))
                                                                                + (float)((float)v11 * (float)v11)))
                                                                * (float)0.5))
                                                * (float)v15)
                                        - (float)1.5)
                        * (float)v15));
    v17 = (float)((float)((float)-(float)((float)((float)((float)v16
                                                        * (float)((float)((float)((float)v12 * (float)v12)
                                                                        + (float)((float)((float)(*v9 - *v8)
                                                                                        * (float)(*v9 - *v8))
                                                                                + (float)((float)v11 * (float)v11)))
                                                                * (float)0.5))
                                                * (float)v16)
                                        - (float)1.5)
                        * (float)v16)
                * (float)v11);
    v19 = (float)(this->collisionImpulse
                * (float)((float)((float)-(float)((float)((float)((float)v16
                                                                * (float)((float)((float)((float)v12 * (float)v12)
                                                                                + (float)((float)((float)(*v9 - *v8)
                                                                                                * (float)(*v9 - *v8))
                                                                                        + (float)((float)v11 * (float)v11)))
                                                                        * (float)0.5))
                                                        * (float)v16)
                                                - (float)1.5)
                                * (float)v16)
                        * (float)(*v9 - *v8)));
    v18 = (float)((float)((float)((float)-(float)((float)((float)((float)v16
                                                                * (float)((float)((float)((float)v12 * (float)v12)
                                                                                + (float)((float)((float)(*v9 - *v8)
                                                                                                * (float)(*v9 - *v8))
                                                                                        + (float)((float)v11 * (float)v11)))
                                                                        * (float)0.5))
                                                        * (float)v16)
                                                - (float)1.5)
                                * (float)v16)
                        * (float)v12)
                * this->collisionImpulse);
    v21[1] = (float)v17 * this->collisionImpulse;
    v21[0] = v19;
    v21[2] = (float)collisionVerticalImpulse + (float)v18;
    v20 = idEntity::GetPhysics(this);
    v20->ApplyImpulse(this: v20, a2: 0, a3: &collision->c.point, a4: (const idVec3 *)v21);
    this->collisionImpulse = 0.0;
    this->collisionVerticalImpulse = 0.0;
  }
  if ( this->callOnCollision.len != 0 )
  {
    idScriptFunction::idScriptFunction(this: &v22);
    idScriptFunction::SetFunction(
      this: &v22,
      ent: this,
      functionName: this->callOnCollision.data,
      returnType: ev_void,
      numParms: 2,
      8,
      "activatedEntity",
      8);
    idScriptFunction::SetArg_Entity(this: &v22, argNum: 0, ent: this);
    idScriptFunction::SetArg_Entity(this: &v22, argNum: 1, ent: otherEntity);
    idScriptFunction::CallFunction(this: &v22, defer: true);
  }
  if ( idVehicle::GetCollisionDamage(this) != nullptr )
    idVehicle_Car::ApplyCollisionDamage(this);
}


// ========================================================================
// ?GetSoundDef@idVehicle_Car@@ABAABVidVehicleSoundDef@@XZ
// EA  : 0x82D3FDE8
// RVA : 0x00D3FDE8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

const idVehicleSoundDef *__fastcall idVehicle_Car::GetSoundDef(idVehicle_Car *this)
{
  const idDeclVehicleProps *vehicleProps; // r11

  vehicleProps = this->vehicleProps;
  if ( vehicleProps != nullptr )
    return &vehicleProps->sounds;
  if ( (_S20_2 & 1) == 0 )
  {
    _S20_2 |= 1u;
    idVehicleSoundDef::idVehicleSoundDef(this: &fakeSounds_0);
    atexit(func: (void (__fastcall *)())_idVehicle_Car::GetSoundDef_::_5_::_dynamic_atexit_destructor_for__fakeSounds__);
  }
  idLib::Warning(fmt: " idVehicle_Car::GetSoundDef: GetVehicleProps() == NULL");
  return &fakeSounds_0;
}


// ========================================================================
// __unwind$499537
// EA  : 0x82D3FE78
// RVA : 0x00D3FE78
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void _unwind_499537()
{
  _S20_2 &= ~1u;
}


// ========================================================================
// ?UpdateSounds@idVehicle_Car@@QAAXXZ
// EA  : 0x82D3FE98
// RVA : 0x00D3FE98
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::UpdateSounds(idVehicle_Car *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  int v4; // r8
  __int128 v5; // r5
  double v6; // fp0
  double v7; // fp31
  long double v8; // fp2
  const idVehicleSoundDef *SoundDef; // r3
  double v10; // fp1
  const idSoundShader *combatMusic2; // r30
  long double v12; // fp2
  double v13; // fp31
  double v14; // fp30
  int max_low; // r10
  int granularity_low; // r9
  double v17; // fp1
  char v18; // r30
  idPresentable *v19; // r3
  int v20; // r3
  idPhysics *Physics; // r30
  int GameMs; // r29
  idPhysics *v23; // r3
  idAIEventManager *p_aiEventManager; // r30
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v26; // r3
  idAIEventManager v27; // [sp+50h] [-1A0h] BYREF
  int v28; // [sp+C4h] [-12Ch]
  soundShaderParms_t v29; // [sp+100h] [-F0h] BYREF

  if ( idVehicle::PlayerIsOccupant(this) == nullptr )
    goto LABEL_47;
  presentable = this->presentable;
  v3 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
  if ( *(_BYTE *)(v3 + 20444) != 0 )
    goto LABEL_47;
  if ( !this->soundState.isCruising )
    goto LABEL_10;
  if ( this->attackOverTime > 0 )
  {
    this->soundState.isCruising = false;
    this->soundState.fadeMusicTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + 2000;
    goto LABEL_12;
  }
  if ( !this->soundState.isCruising )
  {
LABEL_10:
    if ( this->attackOverTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
    {
      this->soundState.isCruising = true;
      v4 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + 2000;
      this->attackOverTime = 0;
      this->soundState.fadeMusicTime = v4;
    }
  }
LABEL_12:
  if ( this->soundState.fadeMusicTime >= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
  {
    *(_QWORD *)((char *)&v5 + 4) = ((__int64 (__fastcall *)(idGameLocal *, int))gameLocal->GetGameMs)(
                                     a1: gameLocal,
                                     a2: 1);
    LODWORD(v5) = this->soundState.fadeMusicTime - DWORD1(v5);
    *(_QWORD *)&v27.eventList.list = v5;
    v6 = (float)((float)(__int64)v5 * (float)0.00050000002);
    if ( v6 >= 0.0 )
    {
      if ( v6 > 1.0 )
        v6 = 1.0;
    }
    else
    {
      v6 = 0.0;
    }
    v7 = (float)((float)1.0 - (float)v6);
    if ( !this->soundState.isCruising )
      v7 = (float)((float)1.0 - (float)((float)1.0 - (float)v6));
    if ( vehicle_playNonCombatMusic.valueInteger != 0 && idVehicle_Car::GetSoundDef(this)->nonCombatMusic != nullptr )
    {
      if ( v7 == 0.0 )
      {
        if ( this->soundState.isCruising )
        {
          soundShaderParms_t::Clear(this: &v29);
          v29.soundShaderFlags = 0;
          SoundDef = idVehicle_Car::GetSoundDef(this);
          idEntity::StartSoundShader(
            this,
            channel: SND_CHANNEL_MUSIC1,
            shader: SoundDef->nonCombatMusic,
            parms: &v29,
            peerMask: 0xFFu);
        }
        else
        {
          idEntity::StopSound(this, channel: SND_CHANNEL_MUSIC1, peerMask: 0xFFu);
        }
      }
      *(double *)&v8 = (float)((float)v7 * (float)0.5);
      if ( *(double *)&v8 > 0.0 )
      {
        if ( *(double *)&v8 < 1.0 )
          v10 = LinearToDB(linear: v8);
        else
          v10 = 0.0;
      }
      else
      {
        v10 = -100.0;
      }
      idEntity::SetSoundVolume(this, channel: SND_CHANNEL_MUSIC1, volume: v10);
    }
    if ( idVehicle_Car::GetSoundDef(this)->combatMusic != nullptr )
    {
      if ( this->isWasteland2 )
        combatMusic2 = idVehicle_Car::GetSoundDef(this)->combatMusic2;
      else
        combatMusic2 = idVehicle_Car::GetSoundDef(this)->combatMusic;
      v13 = (float)((float)1.0 - (float)v7);
      if ( v13 == 0.0 )
      {
        if ( this->soundState.isCruising )
        {
          idEntity::StopSound(this, channel: SND_CHANNEL_MUSIC2, peerMask: 0xFFu);
        }
        else
        {
          soundShaderParms_t::Clear(this: (soundShaderParms_t *)&v27.eventHash);
          soundShaderParms_t::Clear(this: (soundShaderParms_t *)&v27.eventHash);
          v28 = 55;
          idEntity::StartSoundShader(
            this,
            channel: SND_CHANNEL_MUSIC2,
            shader: combatMusic2,
            parms: (const soundShaderParms_t *)&v27.eventHash,
            peerMask: 0xFFu);
        }
      }
      v14 = 0.0;
      if ( combatMusic2 != nullptr )
      {
        max_low = SLODWORD(combatMusic2->parms.volume.max);
        granularity_low = LODWORD(combatMusic2->parms.volume.granularity);
        v27.eventList.list = (idAIEvent **)LODWORD(combatMusic2->parms.volume.min);
        v27.eventList.num = max_low;
        v27.eventList.size = granularity_low;
        v14 = (float)((float)((float)(*(float *)&max_low + *(float *)&v27.eventList.list) * (float)0.5) * (float)v13);
      }
      if ( v13 > 0.0 )
      {
        if ( v13 < 1.0 )
        {
          *(double *)&v12 = v13;
          v17 = LinearToDB(linear: v12);
        }
        else
        {
          v17 = 0.0;
        }
      }
      else
      {
        v17 = -100.0;
      }
      idEntity::SetSoundVolume(this, channel: SND_CHANNEL_MUSIC2, volume: (float)((float)v17 + (float)v14));
    }
  }
LABEL_47:
  v18 = 0;
  if ( this->vehicleProps->hasEngineIdle
    || ((v19 = this->presentable) == nullptr ? (v20 = 0) : (v20 = (int)v19->GetVehicleInterface(this: v19)),
        *(float *)(v20 + 11888) > 0.0) )
  {
    if ( gameLocal->GetGameFrame(this: gameLocal) % 30 == 0 )
      v18 = 1;
  }
  if ( v18 != 0 )
  {
    Physics = idEntity::GetPhysics(this);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v23 = Physics;
    GetOrigin = Physics->GetOrigin;
    p_aiEventManager = &gameLocal->aiEventManager;
    v26 = GetOrigin(this: v23, a2: 0);
    idAIEventManager::AddEvent(
      this: &v27,
      result: p_aiEventManager,
      eventDecl: this->vehicleSoundEventDecl,
      curTime: GameMs,
      originator: this,
      instigator: this,
      origin: v26,
      delay: 0);
  }
}


// ========================================================================
// ?DestroyVehicle@idVehicle_Car@@QAAXPAVidEntity@@_N@Z
// EA  : 0x82D40308
// RVA : 0x00D40308
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::DestroyVehicle(idVehicle_Car *this, idEntity *attacker, bool preventItemDrop)
{
  idPlayer *v6; // r20
  __int64 v7; // r10
  double v8; // fp13
  unsigned int v9; // r4
  double v10; // fp0
  const idDeclEntityDef *healthItem; // r4
  idPhysics *Physics; // r29
  int GameMs; // r28
  idPhysics *v14; // r3
  idAIEventManager *p_aiEventManager; // r29
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v17; // r3
  idList<idEntityPtr<idEntity>,5> *v18; // r3
  idList<idEntityPtr<idEntity>,5> *v19; // r28
  int v20; // r25
  int v21; // r29
  int value; // r9
  idEntity *v23; // r3
  idEntity *v24; // r3
  idEntity *v25; // r30
  idEventArg *v26; // r3
  idPhysics *v27; // r3
  double valueFloat; // fp31
  double v31; // fp2
  double v32; // fp5
  double v33; // fp2
  idPhysics *v34; // r30
  idPhysics *v35; // r29
  idPhysics *v36; // r3
  idBreakableManager *p_breakableManager; // r30
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // ctr
  const idMat3 *v39; // r28
  const idVec3 *v40; // r29
  const idVehicleEffectsDef *EffectsDef; // r3
  idBreakable *v42; // r3
  idEntity *v43; // r30
  idPresentable *presentable; // r3
  idPresentable *v45; // r29
  idPresentable *v46; // r30
  unsigned int *p_spawnId; // r11
  int v48; // r30
  idPresentable *v49; // r3
  int v50; // r3
  idVehicle_Car_vtbl *v51; // r30
  idPhysics *v52; // r3
  idPhysics *v53; // r3
  const idVehicleSoundDef *SoundDef; // r3
  idPresentable *v55; // r3
  int v56; // r3
  int v57; // r11
  int v58; // r10
  int v59; // r8
  idPresentable *v60; // r3
  idPresentablePlayer *v61; // r3
  idPresentableVehicle *v62; // r30
  idThirdPersonCrosshair *Crosshair; // r3
  const idVehicleSoundDef *v64; // r3
  idPresentable *v65; // r3
  int v66; // r3
  BOOL specialDeathActive; // r11
  idAIEventManager v68; // [sp+70h] [-110h] BYREF
  idEventArg v69; // [sp+C0h] [-C0h] BYREF
  idEventReceiver v70[2]; // [sp+E0h] [-A0h] BYREF

  v6 = idVehicle::PlayerIsOccupant(this);
  if ( !common->IsMultiplayer(this: common) && this->dropItemsWhenKilled && !preventItemDrop )
  {
    HIDWORD(v7) = "DistToTarget: %f dist: %f \n";
    v8 = ammoThreshold;
    v9 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v9;
    LODWORD(v7) = (v9 >> 10) & 0x7FFF;
    *(_QWORD *)&v68.eventList.list = v7;
    v10 = (float)((float)v7 * (float)0.000030518509);
    if ( v10 < v8 )
    {
      if ( v10 < boostThreshold )
      {
        if ( v10 < healthThreshold )
          goto LABEL_11;
        healthItem = this->healthItem;
      }
      else
      {
        healthItem = this->boostItem;
      }
    }
    else
    {
      healthItem = this->ammoItem;
    }
    idVehicle::DropItem(this, def: healthItem);
  }
LABEL_11:
  if ( attacker != nullptr )
  {
    Physics = idEntity::GetPhysics(this);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v14 = Physics;
    GetOrigin = Physics->GetOrigin;
    p_aiEventManager = &gameLocal->aiEventManager;
    v17 = GetOrigin(this: v14, a2: 0);
    idAIEventManager::AddEvent(
      this: &v68,
      result: p_aiEventManager,
      eventDecl: this->explosionEventDecl,
      curTime: GameMs,
      originator: this,
      instigator: attacker,
      origin: v17,
      delay: 0);
  }
  v18 = this->GetTriggerTouchList_2(this);
  v19 = v18;
  if ( v18 != nullptr )
  {
    v20 = 0;
    if ( v18->num > 0 )
    {
      v21 = 0;
      do
      {
        value = v19->list[v21].spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v23 = gameLocal->entities.ptr[value & 0x1FFF];
          if ( v23 != nullptr )
          {
            v24 = idEntity::CastTo(c: v23);
            v25 = v24;
            if ( v24 != nullptr
              && (v24->RespondsTo(this: v24, a2: &EV_Touch)
               || (unsigned __int8)idEntity::HasSignal(this: v25, signalnum: SIG_TOUCH) != 0) )
            {
              idEntity::Signal(this: v25, signalnum: SIG_TOUCH);
              HIBYTE(v68.receivers.list) = 105;
              v68.receivers.num = 0;
              v26 = idEventArg::idEventArg(this: &v69, data: this);
              idEventReceiver::ProcessEvent(
                this: v70,
                result: (idEventArg *)v25,
                ev: *(const idEventDef **)&v26->type,
                arg1: (const idEventArg *)LODWORD(v26->value.v[1]),
                arg2: (const idEventArg *)LODWORD(v26->value.v[2]));
            }
          }
        }
        ++v20;
        ++v21;
      }
      while ( v20 < v19->num );
    }
  }
  idVehicle::RemoveAIEvents(this);
  if ( vehicle_simpleDeath.valueInteger == 0 && idVehicle_Car::GetEffectsDef(this)->breakable != nullptr )
  {
    v27 = idEntity::GetPhysics(this);
    v27->GetLinearVelocity(this: (idPhysics *)&v68.eventList.size, result: (idVec3 *)v27, a3: 0);
    valueFloat = vehicle_breakableFadeOut.valueFloat;
    _FP5 = (float)((float)((float)(*(float *)&v68.eventList.size * *(float *)&v68.eventList.size)
                         + (float)((float)(*(float *)&v68.eventHash.hash * *(float *)&v68.eventHash.hash)
                                 + (float)(*(float *)&v68.eventList.granularity * *(float *)&v68.eventList.granularity)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f3, f5, f6, f12 }
    v31 = __frsqrte(_FP3);
    v32 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31
                                                                                        * (float)((float)((float)(*(float *)&v68.eventList.size * *(float *)&v68.eventList.size) + (float)((float)(*(float *)&v68.eventHash.hash * *(float *)&v68.eventHash.hash) + (float)(*(float *)&v68.eventList.granularity * *(float *)&v68.eventList.granularity)))
                                                                                                * (float)0.5))
                                                                                * (float)v31)
                                                                        - (float)1.5)
                                                        * (float)v31)
                                                * (float)((float)((float)(*(float *)&v68.eventList.size
                                                                        * *(float *)&v68.eventList.size)
                                                                + (float)((float)(*(float *)&v68.eventHash.hash
                                                                                * *(float *)&v68.eventHash.hash)
                                                                        + (float)(*(float *)&v68.eventList.granularity
                                                                                * *(float *)&v68.eventList.granularity)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v31
                                                                                * (float)((float)((float)(*(float *)&v68.eventList.size * *(float *)&v68.eventList.size)
                                                                                                + (float)((float)(*(float *)&v68.eventHash.hash * *(float *)&v68.eventHash.hash) + (float)(*(float *)&v68.eventList.granularity * *(float *)&v68.eventList.granularity)))
                                                                                        * (float)0.5))
                                                                        * (float)v31)
                                                                - (float)1.5)
                                                * (float)v31))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v31
                                                        * (float)((float)((float)(*(float *)&v68.eventList.size
                                                                                * *(float *)&v68.eventList.size)
                                                                        + (float)((float)(*(float *)&v68.eventHash.hash
                                                                                        * *(float *)&v68.eventHash.hash)
                                                                                + (float)(*(float *)&v68.eventList.granularity
                                                                                        * *(float *)&v68.eventList.granularity)))
                                                                * (float)0.5))
                                                * (float)v31)
                                        - (float)1.5)
                        * (float)v31));
    v33 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)(*(float *)&v68.eventList.size * *(float *)&v68.eventList.size) + (float)((float)(*(float *)&v68.eventHash.hash * *(float *)&v68.eventHash.hash) + (float)(*(float *)&v68.eventList.granularity * *(float *)&v68.eventList.granularity))) * (float)0.5)) * (float)v31) - (float)1.5)
                                                                                                * (float)v31)
                                                                                        * (float)((float)((float)(*(float *)&v68.eventList.size * *(float *)&v68.eventList.size) + (float)((float)(*(float *)&v68.eventHash.hash * *(float *)&v68.eventHash.hash) + (float)(*(float *)&v68.eventList.granularity * *(float *)&v68.eventList.granularity)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)(*(float *)&v68.eventList.size * *(float *)&v68.eventList.size) + (float)((float)(*(float *)&v68.eventHash.hash * *(float *)&v68.eventHash.hash) + (float)(*(float *)&v68.eventList.granularity * *(float *)&v68.eventList.granularity))) * (float)0.5)) * (float)v31) - (float)1.5)
                                                                                        * (float)v31))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v31
                                                                                                * (float)((float)((float)(*(float *)&v68.eventList.size * *(float *)&v68.eventList.size) + (float)((float)(*(float *)&v68.eventHash.hash * *(float *)&v68.eventHash.hash) + (float)(*(float *)&v68.eventList.granularity * *(float *)&v68.eventList.granularity))) * (float)0.5))
                                                                                        * (float)v31)
                                                                                - (float)1.5)
                                                                * (float)v31))
                                                * (float)((float)((float)(*(float *)&v68.eventList.size
                                                                        * *(float *)&v68.eventList.size)
                                                                + (float)((float)(*(float *)&v68.eventHash.hash
                                                                                * *(float *)&v68.eventHash.hash)
                                                                        + (float)(*(float *)&v68.eventList.granularity
                                                                                * *(float *)&v68.eventList.granularity)))
                                                        * (float)0.5))
                                        * (float)v32)
                                - (float)1.5)
                * (float)v32);
    *(float *)&v68.eventList.granularity = *(float *)&v68.eventList.granularity * (float)v33;
    *(float *)&v68.eventList.size = *(float *)&v68.eventList.size * (float)v33;
    *(float *)&v68.eventHash.hash = *(float *)&v68.eventHash.hash * (float)v33;
    v34 = idEntity::GetPhysics(this);
    v35 = idEntity::GetPhysics(this);
    v36 = v34;
    GetAxis = v34->GetAxis;
    p_breakableManager = &gameLocal->breakableManager;
    v39 = GetAxis(this: v36, a2: 0);
    v40 = v35->GetOrigin(this: v35, a2: 0);
    EffectsDef = idVehicle_Car::GetEffectsDef(this);
    v42 = idBreakableManager::UseBreakable(
            this: p_breakableManager,
            decl: EffectsDef->breakable,
            origin: v40,
            axis: v39,
            dir: (const idVec3 *)&v68.eventList.size,
            pos: nullptr,
            impulse: 0.0,
            fadeTime: valueFloat);
    v43 = v42;
    if ( v42 != nullptr )
    {
      presentable = v42->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: v43);
        presentable = v43->presentable;
      }
      if ( presentable->GetBreakableInterface(this: presentable) != nullptr )
      {
        if ( v43->presentable == nullptr )
          idEntity::InitPresentableInternal(this: v43);
        v45 = v43->presentable;
        v46 = this->presentable;
        if ( v46 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v46 = this->presentable;
        }
        p_spawnId = &v45->GetBreakableInterface(this: v45)->breakableParent.spawnId;
        if ( v46 != nullptr )
          *p_spawnId = v46->spawnId;
        else
          *p_spawnId = 0;
      }
    }
  }
  v48 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v49 = this->presentable;
  if ( v49 != nullptr )
    v50 = (int)v49->GetVehicleInterface(this: v49);
  else
    v50 = 0;
  *(_DWORD *)(v50 + 20436) = v48;
  idVehicle::ClearWeaponFX(this);
  idVehicle::ClearDamageFX(this);
  if ( vehicle_playerNoDie.valueInteger != 0 && v6 != nullptr )
  {
    v51 = this->__vftable;
    this->GetMaxHealth(this);
    ((void (__fastcall *)(idVehicle_Car *))v51->SetHealth)(a1: this);
    v52 = idEntity::GetPhysics(this);
    *(float *)&v68.eventHash.hashSize = 0.0;
    *(float *)&v68.eventHash.indexSize = 0.0;
    *(float *)&v68.eventHash.granularity = 600.0;
    v52->SetLinearVelocity(this: v52, a2: (const idVec3 *)&v68.eventHash.hashSize, a3: 0);
    v53 = idEntity::GetPhysics(this);
    v53->SetAngularVelocity(this: v53, a2: &vec3_origin, a3: 0);
    idEntity::StopSound(this, channel: SND_CHANNEL_ANY, peerMask: 0xFFu);
    SoundDef = idVehicle_Car::GetSoundDef(this);
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_EXPLODE,
      shader: SoundDef->explode,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
    this->soundState.engineRunning = false;
    this->soundState.isCruising = true;
  }
  else
  {
    v55 = this->presentable;
    if ( v55 != nullptr )
      v56 = (int)v55->GetVehicleInterface(this: v55);
    else
      v56 = 0;
    v57 = 0;
    if ( *(int *)(v56 + 16492) > 0 )
    {
      v58 = 0;
      do
      {
        ++v57;
        v59 = *(_DWORD *)(v56 + 16488) + v58;
        v58 += 12;
        *(float *)(v59 + 8) = 0.0;
      }
      while ( v57 < *(_DWORD *)(v56 + 16492) );
    }
    this->Hide_2(this);
    idEntity::StopSound(this, channel: SND_CHANNEL_ANY, peerMask: 0xFFu);
    v60 = this->presentable;
    if ( v60 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v60 = this->presentable;
    }
    v61 = (idPresentablePlayer *)v60->GetVehicleInterface(this: v60);
    v62 = (idPresentableVehicle *)v61;
    if ( v61 != nullptr )
    {
      idPresentablePlayer::StopSound(this: v61, channel: SND_CHANNEL_ANY, peerMask: 0);
      Crosshair = idPresentableVehicle::GetCrosshair(this: v62);
      idThirdPersonCrosshair::ClearTarget(this: Crosshair);
    }
    v64 = idVehicle_Car::GetSoundDef(this);
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_EXPLODE,
      shader: v64->explode,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
    v65 = this->presentable;
    if ( v65 != nullptr )
      v66 = (int)v65->GetVehicleInterface(this: v65);
    else
      v66 = 0;
    *(_BYTE *)(v66 + 11877) = 0;
    specialDeathActive = this->specialDeathActive;
    this->soundState.engineRunning = false;
    if ( specialDeathActive && this->removeWhenDead )
      idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
    this->specialDeathActive = false;
    this->specialDeathStartTime = 0;
    this->destroyed = true;
  }
}


// ========================================================================
// ?ThrowAttachedItem@idVehicle_Car@@UAAPAVidEntity@@PAVidInventoryItem@@@Z
// EA  : 0x82D40A60
// RVA : 0x00D40A60
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

idProp_Moveable *__fastcall idVehicle_Car::ThrowAttachedItem(idVehicle_Car *this, idInventoryItem *item)
{
  int v4; // r26
  idEntity *Driver; // r3
  idPlayer *v6; // r3
  idPresentable *presentable; // r11
  idPresentable *v8; // r27
  idPresentable *v9; // r28
  int GameMs; // r3
  idPresentable *v11; // r11
  unsigned int v12; // r29
  int v13; // r30
  const idVehicleEffectsDef *EffectsDef; // r3
  idProp_Moveable *v15; // r30
  const idSoundShader *attachmentCollision; // r11
  idProp_Moveable *result; // r3
  idProp_Moveable *v18; // r29
  int v19; // [sp+8h] [-E8h]
  const idColor *v20; // [sp+Ch] [-E4h]
  int v21; // [sp+10h] [-E0h]
  int v22; // [sp+14h] [-DCh]
  int v23; // [sp+18h] [-D8h]
  int v24; // [sp+1Ch] [-D4h]
  int v25; // [sp+20h] [-D0h]
  int v26; // [sp+24h] [-CCh]
  int v27; // [sp+28h] [-C8h]
  int v28; // [sp+2Ch] [-C4h]
  int v29; // [sp+30h] [-C0h]
  int v30; // [sp+34h] [-BCh]
  int v31; // [sp+38h] [-B8h]
  int v32; // [sp+3Ch] [-B4h]
  int v33; // [sp+40h] [-B0h]
  int v34; // [sp+44h] [-ACh]
  int v35; // [sp+48h] [-A8h]
  int v36; // [sp+4Ch] [-A4h]
  int v37; // [sp+50h] [-A0h]
  int v38; // [sp+58h] [-98h]
  int v39; // [sp+5Ch] [-94h]
  int v40; // [sp+60h] [-90h]
  int v41; // [sp+68h] [-88h]
  idVec3 v42; // [sp+70h] [-80h] BYREF
  idMat3 v43[3]; // [sp+80h] [-70h] BYREF

  if ( idVehicle_Car::GetEffectsDef(this)->particleAttachmentLost != nullptr )
  {
    idVehicle::GetDetachableWorldTransform(this, declInventory: item->decl, worldOrigin: &v42, worldAxis: v43);
    v4 = 0;
    if ( idVehicle::GetDriver(this) != nullptr )
    {
      Driver = idVehicle::GetDriver(this);
      if ( (unsigned __int8)idPlayer::IsTypeOf(c: Driver) != 0 )
      {
        v6 = (idPlayer *)idVehicle::GetDriver(this);
        if ( idPlayer::CastTo(c: v6) != nullptr )
          v4 = -1;
      }
    }
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    v8 = presentable;
    if ( presentable != nullptr )
    {
      v9 = presentable;
    }
    else
    {
      idEntity::InitPresentableInternal(this);
      v9 = this->presentable;
    }
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v11 = this->presentable;
    v12 = GameMs;
    if ( v11 != nullptr )
      v13 = (int)v11->GetVehicleInterface(this: this->presentable);
    else
      v13 = 0;
    EffectsDef = idVehicle_Car::GetEffectsDef(this);
    idImpactManager::UseImpact(
      this: (idImpactManager *)(v13 + 12504),
      org: &v42,
      axis: v43,
      prt: (const idMaterial *)EffectsDef->particleAttachmentLost,
      startTime: v12,
      bindToParent: true,
      parentOrg: &v9->origin,
      parentAxis: &v8->axis,
      distSqr: 0.0,
      playerIndex: v19,
      color: v20,
      numCycles: v21,
      a13: v22,
      a14: v23,
      a15: v24,
      a16: v25,
      a17: v26,
      a18: v27,
      a19: v28,
      a20: v29,
      a21: v30,
      a22: v31,
      a23: v32,
      a24: v33,
      a25: v34,
      a26: v35,
      a27: v36,
      a28: v37,
      a29: v4,
      a30: v38,
      a31: v39,
      a32: v40,
      a33: &idColor::colorWhite.r,
      a34: v41,
      a35: 1);
  }
  v15 = idVehicle::ThrowAttachedItem(this, item);
  attachmentCollision = idVehicle_Car::GetSoundDef(this)->attachmentCollision;
  result = v15;
  if ( attachmentCollision != nullptr )
  {
    v18 = idProp_Moveable::CastTo(c: v15);
    if ( v18 != nullptr )
      v18->sound_bounce = idVehicle_Car::GetSoundDef(this)->attachmentCollision;
    return v15;
  }
  return result;
}


// ========================================================================
// ?Spawn@idVehicle_Car@@QAAXXZ
// EA  : 0x82D40D88
// RVA : 0x00D40D88
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::Spawn(idVehicle_Car *this)
{
  const idGameSpawnInfo *v2; // r3
  idPresentable *presentable; // r3
  float *v4; // r3
  const idDeclTable *turnspeed; // r9
  idPresentable *v6; // r3
  int entityNumber; // r28
  const idDeclVehicleProps *vehicleProps; // r27
  idClip *p_clip; // r29
  idRenderModel *RenderModelFromPresentable; // r26
  idAnimStack *v11; // r24
  idGameTimeManager *v12; // r3
  int v13; // r10
  int v14; // r27
  int v15; // r29
  idVehicleSoundDef::gear_t *v16; // r28
  idPhysics *Physics; // r3
  idBreakableManager *p_breakableManager; // r29
  const idVec3 *v19; // r28
  const idVehicleEffectsDef *EffectsDef; // r3
  idPresentable *v21; // r11
  idDeclSkins *v22; // r27
  char *data; // r28
  idPresentable *v24; // r29
  idPhysics *v25; // r3
  idBounds *v26; // r3
  int v27; // [sp+8h] [-C8h]
  int v28; // [sp+Ch] [-C4h]
  int v29; // [sp+10h] [-C0h]
  int v30; // [sp+14h] [-BCh]
  int v31; // [sp+18h] [-B8h]
  int v32; // [sp+1Ch] [-B4h]
  int v33; // [sp+20h] [-B0h]
  int v34; // [sp+24h] [-ACh]
  idStr v35[3]; // [sp+60h] [-70h] BYREF

  this->aiProperties.health = this->GetMaxHealth(this);
  v2 = gameLocal->GetGameSpawnInfo(this: gameLocal);
  idStr::idStr(this: v35, text: &v2->mapName);
  idStr::StripTrailingOnce(this: v35, string: ".map");
  this->isWasteland2 = idStr::StripTrailingOnce(this: v35, string: "wasteland2");
  idVehicle_Car::aiProperties_t::operator=(this: &this->savedProperties, __that: &this->aiProperties);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = (float *)presentable->GetVehicleInterface(this: presentable);
  else
    v4 = nullptr;
  turnspeed = this->aiProperties.turnspeed;
  this->savedProperties.stickControl.angularScale[0] = v4[4357];
  this->savedProperties.stickControl.angularScale[1] = v4[4358];
  this->savedProperties.stickControl.velocityScale[0] = v4[4359];
  this->savedProperties.stickControl.velocityScale[1] = v4[4360];
  if ( turnspeed == nullptr )
  {
    idLib::Warning(fmt: "%s doesn't have aiProperties.turnspeed set", this->name.data);
    this->aiProperties.turnspeed = (const idDeclTable *)idDeclInfo::FindWithInheritance(
                                                          this: &idDeclTable::resourceList,
                                                          name: "vehicle/ai/default/turnspeed",
                                                          makeDefault: true);
  }
  if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr )
  {
    if ( this->vehicleProps != nullptr )
    {
      v6 = this->presentable;
      if ( v6 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v6 = this->presentable;
      }
      idPresentable::UpdateModelTransform(this: v6);
      entityNumber = this->entityNumber;
      vehicleProps = this->vehicleProps;
      p_clip = &clientGame->clip;
      RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
      v11 = this->GetAnimStack_2(this);
      v12 = gameLocal->GetGameTimeManager(this: gameLocal);
      idAnimator_VehicleCar::InitVehicleAnimator(
        this: &this->vehicleAnimator,
        game: v12,
        vehicleProps_: vehicleProps,
        animStack_: v11,
        renderModel_: RenderModelFromPresentable,
        entityNum_: entityNumber,
        clip_: p_clip,
        a8: v13,
        a9: v27,
        a10: v28,
        a11: v29,
        a12: v30,
        a13: v31,
        a14: v32,
        a15: v33,
        a16: v34);
      idVehicle::InitEventAnimator(this);
      v14 = 0;
      this->baseCOG = *idVehicle_Car::GetCgLocation(this);
      if ( idVehicle_Car::GetSoundDef(this)->gears.num - 1 > 0 )
      {
        v15 = 0;
        do
        {
          v16 = &idVehicle_Car::GetSoundDef(this)->gears.list[v15];
          if ( v16[1].maxSpeed < (double)idVehicle_Car::GetSoundDef(this)->gears.list[v15].maxSpeed )
            idLib::Warning(fmt: " idVehicle_Car::Spawn: Vehicle gears out of order for '%s'", this->name.data);
          ++v14;
          ++v15;
        }
        while ( v14 < idVehicle_Car::GetSoundDef(this)->gears.num - 1 );
      }
      if ( vehicle_simpleDeath.valueInteger == 0 && idVehicle_Car::GetEffectsDef(this)->breakable != nullptr )
      {
        Physics = idEntity::GetPhysics(this);
        p_breakableManager = &gameLocal->breakableManager;
        v19 = Physics->GetOrigin(this: Physics, a2: 0);
        EffectsDef = idVehicle_Car::GetEffectsDef(this);
        idBreakableManager::AddBreakable(this: p_breakableManager, decl: EffectsDef->breakable, origin: v19);
      }
      idEntity::BecomeActive(this, flags: 1);
      if ( this->normalSkin.len != 0 )
      {
        v21 = this->presentable;
        if ( v21 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v21 = this->presentable;
        }
        v22 = v21->model->GetSkins(this: v21->model);
        if ( v22 != nullptr )
        {
          data = this->normalSkin.data;
          if ( this->presentable == nullptr )
            idEntity::InitPresentableInternal(this);
          v24 = this->presentable;
          v24->model->g.customSkin = idDeclSkins::IndexForSkin(this: v22, name: data);
        }
      }
      idVehicle_Car::SetGhostMode(this, bl: this->ghostCollision, time: -1);
      *(_BYTE *)&this->flags |= 0x40u;
      v25 = idEntity::GetPhysics(this);
      v26 = (idBounds *)v25->GetAbsBounds(this: v25, a2: -1);
      idEntity::UpdatePVSAreas(this, bounds: v26);
    }
    else
    {
      idLib::Warning(fmt: "Missing vehicle props for '%s'", this->name.data);
    }
  }
  else
  {
    idLib::Warning(fmt: "No animated model is specified for '%s'", this->name.data);
  }
  idStr::FreeData(this: v35);
}


// ========================================================================
// __unwind$500067
// EA  : 0x82D41158
// RVA : 0x00D41158
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void _unwind_500067()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// ?Think@idVehicle_Car@@UAAXXZ
// EA  : 0x82D41188
// RVA : 0x00D41188
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::Think(idVehicle_Car *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  unsigned int LastError; // r3
  int v5; // r9
  int v6; // r8
  int v7; // r7
  int v8; // r6
  int v9; // r5
  int v10; // r4
  double ArmoredHealth; // fp1
  int num; // r11
  int v13; // r26
  int v14; // r28
  idVehicle_Car::vehicleHitData_t *v15; // r29
  int v16; // r10
  idPlayer *v17; // r3
  idEntity *v18; // r29
  idPhysics *Physics; // r28
  idPhysics *v20; // r27
  idPhysics_vtbl *v21; // r29
  int v22; // r3
  bool v23; // r4
  char v24; // r3
  idPresentable *presentable; // r11
  idCVar *v26; // r9
  double valueFloat; // fp31
  int ghostEndTime; // r29
  idPhysics *v29; // r3
  int v30; // r3
  int *v31; // r10
  _DWORD *v32; // r11
  int i; // ctr
  idPhysics *v34; // r3
  const idMat3 *v35; // r3
  idPhysics *v36; // r3
  float *v37; // r3
  int EntitiesTouchingBounds; // r27
  int v39; // r28
  idGameLocal *v40; // r3
  int *v41; // r29
  int v42; // r10
  idPhysics *v43; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *v45; // r3
  idPresentableVehicle *v46; // r3
  char v47; // r22
  idEntity *Driver; // r3
  idPlayer *v49; // r21
  idPlayer *v50; // r27
  idPresentable *v51; // r3
  idPresentableVehicle *v52; // r3
  idPresentable *v53; // r3
  int v54; // r3
  idFocusTracker *v55; // r29
  idPresentable *v56; // r3
  int v57; // r3
  idPresentable *v58; // r11
  const idVec3 *v59; // r28
  int v60; // r3
  idPresentable *v61; // r3
  int v62; // r3
  _DWORD *v63; // r28
  int v64; // r27
  int v65; // r29
  int v66; // r10
  double frictionOverrideRear; // fp0
  idPresentable *v68; // r3
  int v69; // r3
  idPresentable *v70; // r3
  int v71; // r3
  _DWORD *v72; // r28
  int v73; // r27
  int v74; // r29
  idPresentable *v75; // r3
  int v76; // r3
  int v77; // r11
  idPlayer *Gunner; // r3
  idPlayer *v79; // r3
  idActor *v80; // r27
  idPresentable *v81; // r3
  int v82; // r3
  idFocusTracker *v83; // r29
  idPresentable *v84; // r3
  int v85; // r3
  idPresentable *v86; // r11
  const idVec3 *v87; // r28
  int v88; // r3
  int v89; // r11
  char v90; // r11
  bool v91; // zf
  idPresentable *v92; // r3
  idPresentableVehicle *v93; // r3
  idPresentable *v94; // r3
  idPresentableVehicle *v95; // r3
  idPresentable *v96; // r3
  idPresentableVehicle *v97; // r3
  idPresentable *v98; // r3
  idPresentableVehicle *v99; // r3
  idPresentable *v100; // r3
  idPresentableVehicle *v101; // r3
  idPhysics *v102; // r3
  idBounds *v103; // r3
  idPresentable *v104; // r3
  int v105; // r3
  idPresentable *v106; // r3
  int v107; // r3
  idPresentable *v108; // r3
  int v109; // r3
  double v110; // fp0
  idPresentable *v111; // r3
  int v112; // r3
  idPresentable *v113; // r3
  idPresentable *v114; // r3
  int v115; // r3
  idPresentable *v116; // r3
  int v117; // r29
  int GameMs; // r3
  specialDeath_t specialDeath; // r11
  idPhysics *v120; // r3
  float *v121; // r3
  idEntity *v122; // r3
  int value; // r9
  idEntity *v124; // r3
  idEntity *v125; // r4
  idPresentable *v126; // r3
  idPresentableVehicle *v127; // r3
  idPlayer *v128; // r3
  idPlayer *v129; // r28
  int v130; // r29
  __int64 v131; // r11
  double v132; // fp13
  __int64 v133; // r8
  unsigned int v134; // r4
  double v135; // fp13
  unsigned int v136; // r4
  float pitch; // r6
  float yaw; // r5
  float v139; // r4
  float roll; // r9
  double v141; // fp1
  double v142; // fp5
  idPresentable *v143; // r3
  idVec3 *v144; // r3
  idPlayer *v145; // r3
  idPlayer *v146; // r29
  idPresentable *v147; // r3
  int v148; // r3
  double v149; // fp1
  double v150; // fp13
  double v151; // fp29
  idPresentable *v152; // r3
  float *v153; // r11
  idPresentable *v154; // r3
  double v155; // fp31
  double v156; // fp30
  double v157; // fp29
  double v158; // fp28
  double v159; // fp26
  double v160; // fp27
  float *v161; // r3
  idPhysics *v162; // r3
  float *v163; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v165; // r30
  int v166; // r3
  __int64 totalTicks; // r11
  __int64 v168; // r9
  int v169; // [sp+8h] [-258h]
  int v170; // [sp+Ch] [-254h]
  int v171; // [sp+10h] [-250h]
  idVehicle *v172; // [sp+14h] [-24Ch]
  float v173; // [sp+50h] [-210h]
  int v174; // [sp+5Ch] [-204h] BYREF
  idBounds v175; // [sp+60h] [-200h] BYREF
  float v176; // [sp+78h] [-1E8h] BYREF
  float v177; // [sp+7Ch] [-1E4h]
  float v178; // [sp+80h] [-1E0h]
  idPLogScope v179; // [sp+88h] [-1D8h] BYREF
  usercmd_t v180; // [sp+90h] [-1D0h] BYREF
  usercmd_t v181; // [sp+D0h] [-190h] BYREF
  int v182[46]; // [sp+110h] [-150h] BYREF

  RD_EventBegin(name: "idVehicle_Car::Think()");
  LODWORD(v2) = "idVehicle_Car::Think()";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v179, pl: &::pLog, gMask: v2, label: v3);
  if ( (unsigned __int8)idEntity::UpdateDormant(this) != 0 )
  {
    idPLogScope::~idPLogScope(this: &v179);
    goto LABEL_211;
  }
  if ( g_recordVehicleTrace.valueInteger == 1 )
  {
    LastError = GetLastError();
    idLib::Printf(fmt: "BeginTraceRecording: error %d\n", LastError);
  }
  ArmoredHealth = idVehicle::GetArmoredHealth(this);
  num = this->hitList.num;
  this->lastThinkHealth = ArmoredHealth;
  v13 = 0;
  if ( num > 0 )
  {
    v14 = 0;
    do
    {
      v15 = &this->hitList.list[v14];
      if ( v15->nextCollisionTime >= idGameTimeManager::GetGameMs(
                                       this: &clientGame->gameTimeManager,
                                       type: GAMETIME_SCALED) )
      {
        ++v13;
        ++v14;
      }
      else
      {
        idList<idSWF::orphanedSprite_t,72>::RemoveIndex(
          this: (idList<idSWF::orphanedSprite_t,72> *)&this->hitList,
          index: v13);
      }
    }
    while ( v13 < this->hitList.num );
  }
  v16 = this->thinkFlags & 1;
  if ( v16 != 0 )
  {
    if ( this->movePlayerToVehicle > 0 )
    {
      v17 = idVehicle::PlayerIsOccupant(this);
      v18 = v17;
      if ( v17 != nullptr )
      {
        if ( idPlayer::GetControl(this: v17) == this )
        {
          Physics = idEntity::GetPhysics(this);
          v20 = idEntity::GetPhysics(this: v18);
          v21 = v20->__vftable;
          v22 = (int)Physics->GetOrigin(this: Physics, a2: 0);
          v21->SetOrigin(this: v20, a2: (const idVec3 *)v22, a3: -1);
        }
        --this->movePlayerToVehicle;
      }
      else
      {
        this->movePlayerToVehicle = 0;
      }
    }
    idVehicle::Think(
      this,
      a2: v10,
      a3: v9,
      a4: v8,
      a5: v7,
      a6: v6,
      a7: v5,
      a8: v16,
      a9: v169,
      a10: v170,
      a11: v171,
      a12: v172);
    if ( idVehicle_Car::GetNumWheelsOnGround(this) > 0 && idVehicle::GetCollisionDamage(this) != nullptr )
      idVehicle_Car::ApplyCollisionDamage(this);
    if ( idVehicle::PlayerIsOccupant(this) != nullptr && vehicle_ghostTime.valueFloat != 0.0 )
    {
      idVehicle_Car::SetGhostMode(this, bl: true, time: (int)(float)(vehicle_ghostTime.valueFloat * (float)1000.0));
      idCVar::SetFloat(this: &vehicle_ghostTime, newValue: 0.0, force: v23);
    }
    if ( this->ghostEndTime > 0 )
    {
      if ( vehicle_ghostRespawnEffect.valueInteger == 1 )
      {
        v24 = idAccolade::Count(this: &clientGame->gameTimeManager);
        presentable = this->presentable;
        if ( (v24 & 8) != 0 )
          v26 = &vehicle_ghostFadeMin;
        else
          v26 = &vehicle_ghostFadeMax;
        valueFloat = v26->valueFloat;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          presentable = this->presentable;
        }
        idRenderModel::SetModelFade(this: presentable->model, v: valueFloat);
      }
      ghostEndTime = this->ghostEndTime;
      if ( ghostEndTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
      {
        v29 = idEntity::GetPhysics(this);
        v30 = (int)v29->GetBounds(this: v29, a2: -1);
        v31 = &v174;
        v32 = (_DWORD *)(v30 - 4);
        for ( i = 6; i != 0; --i )
          *++v31 = *++v32;
        v175.b[0].x = v175.b[0].x - (float)1.5;
        v175.b[0].y = v175.b[0].y - (float)1.5;
        v175.b[0].z = v175.b[0].z - (float)1.5;
        v175.b[1].x = v175.b[1].x + (float)1.5;
        v175.b[1].y = v175.b[1].y + (float)1.5;
        v175.b[1].z = v175.b[1].z + (float)1.5;
        v34 = idEntity::GetPhysics(this);
        v35 = v34->GetAxis(this: v34, a2: 0);
        idBounds::FromTransformedBounds(this: &v175, bounds: &v175, origin: &vec3_origin, axis: v35);
        v36 = idEntity::GetPhysics(this);
        v37 = (float *)v36->GetOrigin(this: v36, a2: 0);
        v175.b[0].x = *v37 + v175.b[0].x;
        v175.b[0].y = v37[1] + v175.b[0].y;
        v175.b[0].z = v37[2] + v175.b[0].z;
        v175.b[1].x = *v37 + v175.b[1].x;
        v175.b[1].y = v37[1] + v175.b[1].y;
        v175.b[1].z = v37[2] + v175.b[1].z;
        EntitiesTouchingBounds = idClip::GetEntitiesTouchingBounds(
                                   this: &clientGame->clip,
                                   bounds: &v175,
                                   clipMask: -1,
                                   entityList: v182,
                                   maxCount: 32);
        v39 = 0;
        if ( EntitiesTouchingBounds <= 0 )
        {
LABEL_42:
          v40 = gameLocal;
        }
        else
        {
          v40 = gameLocal;
          v41 = v182;
          do
          {
            v42 = 4 * (*v41 + 21563);
            if ( *(idVehicle_Car **)((char *)&v40->__vftable + v42) != this )
            {
              v43 = idEntity::GetPhysics(this: *(idEntity **)((char *)&v40->__vftable + v42));
              if ( (v43->GetContents(this: v43, a2: -1) & 0x30200) != 0 )
                goto LABEL_42;
              v40 = gameLocal;
            }
            ++v39;
            ++v41;
          }
          while ( v39 < EntitiesTouchingBounds );
        }
        if ( v39 == EntitiesTouchingBounds )
          idVehicle_Car::SetGhostMode(this, bl: false, time: -1);
        else
          this->ghostEndTime = v40->GetGameMs(this: v40, a2: GAMETIME_SCALED) + 500;
      }
    }
    if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr )
    {
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
      idTreeAnimator::ClearJointMods(this: TreeAnimatorFromPresentable);
    }
    v45 = this->presentable;
    if ( v45 != nullptr )
      v46 = v45->GetVehicleInterface(this: v45);
    else
      v46 = nullptr;
    idPresentableVehicle::UpdateCurrentMPH(this: v46);
    v47 = 0;
    Driver = idVehicle::GetDriver(this);
    v49 = (idPlayer *)Driver;
    if ( Driver != nullptr )
    {
      if ( (unsigned __int8)idClass::IsType(this: Driver, superclass: &idPlayer::Type) != 0 )
      {
        v50 = idPlayer::CastTo(c: v49);
        if ( idPlayer::IsLocallyControlled(this: v50) )
          idVehicle_Car::DriveControl(this);
        usercmd_t::usercmd_t(this: &v181);
        usercmd_t::usercmd_t(this: &v180);
        v51 = this->presentable;
        if ( v51 != nullptr )
          v52 = v51->GetVehicleInterface(this: v51);
        else
          v52 = nullptr;
        if ( (unsigned __int8)idPresentableVehicle::GetUserCommand(this: v52, seat: 1, previous: &v181, current: &v180) != 0
          && ((((*((_BYTE *)&v180 + 9) & 0x80) != 0 ? 0 : v180.buttons) & 0x2000000) != 0
           || (((*((_BYTE *)&v181 + 9) & 0x80) != 0 ? 0 : v181.buttons) & 0x2000000) != 0) )
        {
          v47 = 1;
        }
        v53 = v50->presentable;
        if ( v53 != nullptr )
          v54 = (int)v53->GetPlayerInterface_2(this: v53);
        else
          v54 = 0;
        v55 = (idFocusTracker *)(v54 + 47160);
        if ( gameLocal->spawnIds.ptr[*(_DWORD *)(v54 + 47244) & 0x1FFF] == *(int *)(v54 + 47244) >> 13 )
        {
          v56 = v50->presentable;
          if ( v56 != nullptr )
            v57 = (int)v56->GetPlayerInterface_2(this: v56);
          else
            v57 = 0;
          v58 = v50->presentable;
          v59 = (const idVec3 *)(v57 + 46532);
          if ( v58 != nullptr )
            v60 = (int)v58->GetPlayerInterface_2(this: v50->presentable);
          else
            v60 = 0;
          idFocusTracker::UpdateFocus(
            this: v55,
            owner: v50,
            viewPos: v59,
            viewAxis: (const idMat3 *)(v60 + 46544),
            passEntityOverride: nullptr);
        }
        goto LABEL_102;
      }
      if ( (unsigned __int8)idClass::IsType(this: v49, superclass: &idVehicleAI::Type) != 0 )
      {
        v61 = this->presentable;
        if ( v61 != nullptr )
          v62 = (int)v61->GetVehicleInterface(this: v61);
        else
          v62 = 0;
        v63 = (_DWORD *)(v62 + 16488);
        v64 = 0;
        if ( *(int *)(v62 + 16492) > 0 )
        {
          v65 = 0;
          do
          {
            if ( this->frictionOverrideTime > 0 )
            {
              if ( this->frictionOverrideTime <= idGameTimeManager::GetGameMs(
                                                   this: &clientGame->gameTimeManager,
                                                   type: GAMETIME_SCALED) )
              {
                this->frictionOverrideTime = 0;
              }
              else
              {
                v66 = *(_DWORD *)(v65 + *v63 + 4);
                if ( v64 >= 2 )
                  frictionOverrideRear = this->frictionOverrideRear;
                else
                  frictionOverrideRear = this->frictionOverrideFront;
                *(float *)(v66 + 500) = frictionOverrideRear;
                *(float *)(v66 + 504) = frictionOverrideRear;
              }
            }
            ++v64;
            v65 += 12;
          }
          while ( v64 < v63[1] );
        }
        goto LABEL_102;
      }
      if ( (unsigned __int8)idClass::IsType(this: v49, superclass: &idVehicleAI::Type) == 0
        || (v49->thinkFlags & 1) != 0 )
      {
        goto LABEL_102;
      }
    }
    idVehicle_Car::SetBraking(this, bl: true);
    idVehicle_Car::SetAccelerating(this, bl: false);
    idVehicle_Car::SetIsReversing(this, bl: false);
    idVehicle_Car::SetBoosting(this, bl: false);
    idVehicle_Car::ResetBoostPower(this);
    v68 = this->presentable;
    if ( v68 != nullptr )
      v69 = (int)v68->GetVehicleInterface(this: v68);
    else
      v69 = 0;
    *(_BYTE *)(v69 + 17816) = 1;
    v70 = this->presentable;
    if ( v70 != nullptr )
      v71 = (int)v70->GetVehicleInterface(this: v70);
    else
      v71 = 0;
    v72 = (_DWORD *)(v71 + 16488);
    v73 = 0;
    if ( *(int *)(v71 + 16492) > 0 )
    {
      v74 = 0;
      do
      {
        *(_BYTE *)(*(_DWORD *)(v74 + *v72 + 4) + 540) = 1;
        *(float *)(*(_DWORD *)(v74 + *v72 + 4) + 548) = 0.0;
        v75 = this->presentable;
        if ( v75 != nullptr )
          v76 = (int)v75->GetVehicleInterface(this: v75);
        else
          v76 = 0;
        ++v73;
        v77 = v74 + *v72;
        v74 += 12;
        *(float *)(*(_DWORD *)(v77 + 4) + 544) = *(float *)(v76 + 17452) * (float)0.5;
      }
      while ( v73 < v72[1] );
    }
LABEL_102:
    Gunner = (idPlayer *)idVehicle::GetGunner(this);
    v79 = idPlayer::CastTo(c: Gunner);
    v80 = v79;
    if ( v79 != nullptr )
    {
      v81 = v79->presentable;
      v82 = v81 != nullptr ? (int)v81->GetPlayerInterface_2(this: v81) : 0;
      v83 = (idFocusTracker *)(v82 + 47160);
      if ( gameLocal->spawnIds.ptr[*(_DWORD *)(v82 + 47244) & 0x1FFF] == *(int *)(v82 + 47244) >> 13 )
      {
        v84 = v80->presentable;
        if ( v84 != nullptr )
          v85 = (int)v84->GetPlayerInterface_2(this: v84);
        else
          v85 = 0;
        v86 = v80->presentable;
        v87 = (const idVec3 *)(v85 + 46532);
        if ( v86 != nullptr )
          v88 = (int)v86->GetPlayerInterface_2(this: v80->presentable);
        else
          v88 = 0;
        idFocusTracker::UpdateFocus(
          this: v83,
          owner: v80,
          viewPos: v87,
          viewAxis: (const idMat3 *)(v88 + 46544),
          passEntityOverride: nullptr);
      }
    }
    if ( v47 == 0 )
      idVehicle_Car::WeaponControl(this);
    if ( v49 == nullptr )
      goto LABEL_121;
    v89 = *(_DWORD *)(v49->GetType(this: v49) + 36);
    if ( v89 < idPlayer::Type.typeNum || (v91 = v89 <= idPlayer::Type.lastChild, v90 = 1, !v91) )
      v90 = 0;
    if ( v90 == 0 )
    {
LABEL_121:
      v92 = this->presentable;
      if ( v92 != nullptr )
        v93 = v92->GetVehicleInterface(this: v92);
      else
        v93 = nullptr;
      if ( idPresentableVehicle::UseSteerControl(this: v93) )
      {
        v94 = this->presentable;
        if ( v94 != nullptr )
          v95 = v94->GetVehicleInterface(this: v94);
        else
          v95 = nullptr;
        idPresentableVehicle::ArcadeSteering(this: v95);
      }
      v96 = this->presentable;
      if ( v96 != nullptr )
        v97 = v96->GetVehicleInterface(this: v96);
      else
        v97 = nullptr;
      idPresentableVehicle::AutoRollOver(this: v97);
    }
    v98 = this->presentable;
    if ( v98 != nullptr )
      v99 = v98->GetVehicleInterface(this: v98);
    else
      v99 = nullptr;
    idPresentableVehicle::AdjustCg(this: v99);
    idVehicle_Car::HandleSpikePit(this);
    v100 = this->presentable;
    if ( v100 != nullptr )
      v101 = v100->GetVehicleInterface(this: v100);
    else
      v101 = nullptr;
    idPresentableVehicle::UpdateRemoteSimulationParms_Server(this: v101);
    idEntity::RunPhysics(this);
    v102 = idEntity::GetPhysics(this);
    v103 = (idBounds *)v102->GetAbsBounds(this: v102, a2: -1);
    idEntity::UpdatePVSAreas(this, bounds: v103);
    v104 = this->presentable;
    if ( v104 != nullptr )
      v105 = (int)v104->GetVehicleInterface(this: v104);
    else
      v105 = 0;
    idLight::SetColor(this: (idPhysics_AF *)(v105 + 16512), linear: &vec3_origin);
    v106 = this->presentable;
    if ( v106 != nullptr )
      v107 = (int)v106->GetVehicleInterface(this: v106);
    else
      v107 = 0;
    idPhysics_AF::SetAuxAngularVelocity(this: (idPhysics_AF *)(v107 + 16512), angular: &vec3_origin);
    idVehicle::CheckThrowOccupant(this);
    idEntity::TouchTriggers(this);
    v108 = this->presentable;
    if ( v108 != nullptr )
      v109 = (int)v108->GetVehicleInterface(this: v108);
    else
      v109 = 0;
    v110 = *(float *)(v109 + 17444);
    this->vehicleAnimator.steerAngle = *(float *)(v109 + 17444);
    this->vehicleAnimator.lastSteerAngle = v110;
    this->vehicleAnimator.newSteerAngle = v110;
    if ( (unsigned __int8)idVehicle::CheckForUseInVolume(this) == 0 )
      idVehicle::UpdateWeapons(this);
    idVehicle_Car::UpdateSounds(this);
    idVehicle::UpdateDetachableItems(this);
    if ( this->hideSteeringWheel && v49 != nullptr )
    {
      v111 = this->presentable;
      if ( v111 != nullptr )
        v112 = (int)v111->GetVehicleInterface(this: v111);
      else
        v112 = 0;
      idVehicle::CollapseJointByIndex(
        this,
        jointIndex: (idIndex<short,enum invalidJointIndex_t> *)*(unsigned __int16 *)(*(_DWORD *)(v112 + 11624) + 110),
        bl: true);
      v113 = this->presentable;
      if ( v113 != nullptr )
        v113->GetVehicleInterface(this: v113)->animator->rotateSteeringWheel = false;
      else
        *(_BYTE *)(MEMORY[0x2D68] + 108) = 0;
    }
    else
    {
      v114 = this->presentable;
      if ( v114 != nullptr )
        v115 = (int)v114->GetVehicleInterface(this: v114);
      else
        v115 = 0;
      *(_BYTE *)(*(_DWORD *)(v115 + 11624) + 108) = 1;
    }
    v116 = this->presentable;
    if ( v116 != nullptr )
      v117 = (int)v116->GetVehicleInterface(this: v116);
    else
      v117 = 0;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    (*(void (__fastcall **)(int, int))(*(_DWORD *)v117 + 52))(a1: v117, a2: GameMs);
    if ( this->specialDeathActive )
    {
      specialDeath = this->specialDeath;
      if ( specialDeath == DEATH_IMPULSE_1 )
      {
        if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
           - this->specialDeathStartTime > vehicle_special_death_minMS.valueInteger )
        {
LABEL_170:
          v120 = idEntity::GetPhysics(this);
          v121 = (float *)v120->GetLinearVelocity(this: (idPhysics *)&v176, result: (idVec3 *)v120, a3: 0);
          if ( (float)((float)(v121[2] * v121[2]) + (float)((float)(*v121 * *v121) + (float)(v121[1] * v121[1]))) < 10000.0 )
          {
            v122 = idEntityPtr<idEntity const>::operator->(this: &this->specialDeathAttacker);
            idVehicle_Car::DestroyVehicle(this, attacker: v122, preventItemDrop: false);
          }
        }
      }
      else if ( specialDeath == DEATH_PULL_FROM_CAMERA )
      {
        goto LABEL_170;
      }
    }
    if ( this->specialDeathCollision )
    {
      value = this->specialDeathAttacker.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v124 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v125 = idEntity::CastTo(c: v124);
      }
      else
      {
        v125 = nullptr;
      }
      idVehicle_Car::DestroyVehicle(this, attacker: v125, preventItemDrop: false);
    }
    v126 = this->presentable;
    if ( v126 != nullptr )
      v127 = v126->GetVehicleInterface(this: v126);
    else
      v127 = nullptr;
    idPresentableVehicle::UpdateExhaust(this: v127);
    idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
    if ( vehicle_cam_breath_enable.valueInteger != 0 )
    {
      v128 = idVehicle::PlayerIsOccupant(this);
      v129 = v128;
      if ( v128 != nullptr && (unsigned __int8)idVehicle::IsPassenger(this, player: v128) == 0 )
      {
        if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > this->cameraBreathNextUpdate )
        {
          v130 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          this->cameraBreathNextUpdate = idRandom2::RandomInt(
                                           this: &clientGame->random,
                                           min: vehicle_cam_breath_min_freq.valueInteger,
                                           max: vehicle_cam_breath_max_freq.valueInteger)
                                       + v130;
          HIDWORD(v131) = 1013904223;
          v132 = vehicle_cam_breath_ang.valueFloat;
          HIDWORD(v133) = clientGame->random.seed;
          v134 = 1664525 * clientGame->random.seed + 1013904223;
          clientGame->random.seed = v134;
          LODWORD(v133) = (v134 >> 10) & 0x7FFF;
          this->cameraBreath.pitch = (float)((float)v133 * (float)v132) * (float)0.000030518509;
          v135 = vehicle_cam_breath_ang.valueFloat;
          v136 = 1664525 * clientGame->random.seed + 1013904223;
          clientGame->random.seed = v136;
          this->cameraBreath.roll = 0.0;
          LODWORD(v131) = (v136 >> 10) & 0x7FFF;
          this->cameraBreath.yaw = (float)((float)v131 * (float)v135) * (float)0.000030518509;
        }
        pitch = this->cameraBreathPrev.pitch;
        yaw = this->cameraBreath.yaw;
        roll = this->cameraBreathPrev.roll;
        v173 = this->cameraBreath.pitch;
        v177 = this->cameraBreathPrev.yaw;
        v139 = v177;
        v176 = pitch;
        v178 = roll;
        v141 = (float)((float)(v173 - pitch) * vehicle_cam_breath_lerp.valueFloat);
        v142 = (float)((float)(yaw - v177) * vehicle_cam_breath_lerp.valueFloat);
        this->cameraBreathPrev.roll = (float)((float)(this->cameraBreath.roll - roll)
                                            * vehicle_cam_breath_lerp.valueFloat)
                                    + roll;
        this->cameraBreathPrev.pitch = pitch + (float)v141;
        this->cameraBreathPrev.yaw = (float)v142 + v139;
        v143 = v129->presentable;
        if ( v143 != nullptr )
          v144 = (idVec3 *)v143->GetPlayerInterface_2(this: v143);
        else
          v144 = nullptr;
        v144[1587] = vec3_origin;
        v144[1588].x = this->cameraBreathPrev.pitch;
        v144[1588].y = this->cameraBreathPrev.yaw;
        v144[1588].z = this->cameraBreathPrev.roll;
      }
    }
    if ( vehicle_headBobEnable.valueInteger != 0 )
    {
      v145 = idVehicle::PlayerIsOccupant(this);
      v146 = v145;
      if ( v145 != nullptr && (unsigned __int8)idVehicle::IsPassenger(this, player: v145) != 0 )
      {
        v147 = this->presentable;
        if ( v147 != nullptr )
          v148 = (int)v147->GetVehicleInterface(this: v147);
        else
          v148 = 0;
        v149 = *(float *)(v148 + 11932);
        if ( this->previousCompression == 0.0 )
          this->previousCompression = *(float *)(v148 + 11932);
        v150 = (float)((float)v149 - this->previousCompression);
        this->previousCompression = v149;
        v151 = (float)((float)v150 / (float)v149);
        if ( vehicle_headBobDebug.valueInteger != 0 )
          idLib::Printf(fmt: (const char *)HIDWORD(v149), LODWORD(v149), LODWORD(v151));
        v152 = v146->presentable;
        if ( v152 != nullptr )
          v153 = (float *)v152->GetPlayerInterface_2(this: v152);
        else
          v153 = nullptr;
        v154 = v146->presentable;
        v155 = v153[4764];
        v156 = v153[4765];
        v158 = (float)(v153[4762] + (float)(vehicle_headBobLerpSpeed.valueFloat * (float)(v153[4762] - v153[4762])));
        v159 = (float)((float)(vehicle_headBobLerpSpeed.valueFloat * (float)(v153[4761] - v153[4761])) + v153[4761]);
        v160 = (float)(v153[4763]
                     + (float)(vehicle_headBobLerpSpeed.valueFloat
                             * (float)((float)((float)((float)v151 * vehicle_maximumHeadPositionDelta.valueFloat)
                                             + v153[4763])
                                     - v153[4763])));
        v157 = v153[4766];
        if ( v154 != nullptr )
          v161 = (float *)v154->GetPlayerInterface_2(this: v154);
        else
          v161 = nullptr;
        v161[4761] = v159;
        v161[4762] = v158;
        v161[4763] = v160;
        v161[4764] = v155;
        v161[4765] = v156;
        v161[4766] = v157;
      }
    }
  }
  v162 = idEntity::GetPhysics(this);
  v163 = (float *)v162->GetOrigin(this: v162, a2: 0);
  this->lastOrigin.x = *v163;
  this->lastOrigin.y = v163[1];
  this->lastOrigin.z = v163[2];
  if ( g_recordVehicleTrace.valueInteger > 0 )
    idCVar::SetInteger(this: &g_recordVehicleTrace, newValue: g_recordVehicleTrace.valueInteger - 1, force: true);
  if ( v179.logIndex >= 0 )
  {
    pLog = v179.pLog;
    v165 = &v179.pLog->logEntries.list[v179.logIndex];
    v166 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v165->totalTicks;
    HIDWORD(totalTicks) = v165->parent;
    LODWORD(v168) = v166 - totalTicks;
    v165->totalTicks = v168;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
LABEL_211:
  RD_EventEnd();
}


// ========================================================================
// __unwind$500266
// EA  : 0x82D42478
// RVA : 0x00D42478
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void _unwind_500266()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 608 + 400));
}


// ========================================================================
// __unwind$500267
// EA  : 0x82D424A0
// RVA : 0x00D424A0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void _unwind_500267()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 608 + 136));
}


// ========================================================================
// ?EnterVehicle@idVehicle_Car@@UAA_NPAVidEntity@@W4vehicleSeat_t@@@Z
// EA  : 0x82D424C8
// RVA : 0x00D424C8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

int __fastcall idVehicle_Car::EnterVehicle(idVehicle_Car *this, idPlayer *other, int wantSeat)
{
  BOOL v6; // r4
  int value; // r10
  idEntity *v8; // r3
  int v9; // r9
  idEntity *v10; // r3
  idEntity *v11; // r3
  idPresentable *presentable; // r3
  int v13; // r3
  const idVehicleSoundDef *SoundDef; // r3
  idVehicleKey *playerKey; // r8
  int v16; // r9
  int v17; // r10
  const idDeclVehicleUpgrade *v18; // r11
  int stage; // r11
  int baseBoostUpgrade; // r11
  idPresentable *v21; // r3
  idPresentableVehicle *v22; // r3
  int boostlevel; // r11
  idPresentable *v24; // r3
  double valueFloat; // fp31
  idPresentableVehicle *v26; // r3
  double v27; // fp1
  idPresentable *v28; // r3
  double v29; // fp31
  double v30; // fp0
  idPresentable *v31; // r3
  idPresentable *v32; // r3
  idPresentableVehicle *v33; // r3
  idPresentable *v34; // r3
  idPresentableVehicle *v35; // r3
  idPlayer *v36; // r5

  if ( (unsigned __int8)idVehicle::EnterVehicle(this, other, wantSeat) == 0 )
    return 0;
  this->previousCompression = 0.0;
  if ( idVehicle::GetOccupantNum(this, entity: other) == 0 )
  {
    if ( (unsigned __int8)idVehicleAI::IsTypeOf(c: other) != 0 || (v6 = false, vehicle_useAiProps.valueInteger != 0) )
      v6 = true;
    this->UseAiProperties(this, a2: v6);
  }
  value = this->enterTarget.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v8 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v8 != nullptr && idEntity::CastTo(c: v8) != nullptr )
    {
      v9 = this->enterTarget.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13 && (v10 = gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr )
        v11 = idEntity::CastTo(c: v10);
      else
        v11 = nullptr;
      idEntity::Activate(this: v11, activator: other);
    }
  }
  if ( idVehicle::GetDriver(this) != nullptr )
  {
    presentable = this->presentable;
    v13 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
    if ( *(_BYTE *)(v13 + 20444) == 0 )
    {
      idVehicle_Car::SetEngineRunning(this, bl: true);
      this->attackOverTime = 0;
      this->soundState.isCruising = false;
    }
  }
  if ( (unsigned __int8)idActor::IsTypeOf(c: other) != 0 )
    idActor::CastTo(c: other);
  if ( idVehicle_Car::GetSoundDef(this)->enterVehicle != nullptr )
  {
    SoundDef = idVehicle_Car::GetSoundDef(this);
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_DOOR,
      shader: SoundDef->enterVehicle,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
  }
  playerKey = this->playerKey;
  if ( playerKey != nullptr )
  {
    v16 = 0;
    if ( playerKey->equippedUpgrades.num > 0 )
    {
      v17 = 0;
      do
      {
        v18 = playerKey->equippedUpgrades.list[v17];
        if ( v18->upgradeType == UPGRADE_BOOSTER )
        {
          stage = v18->stage;
          if ( stage > this->boostlevel )
            this->boostlevel = stage;
        }
        ++v16;
        ++v17;
      }
      while ( v16 < this->playerKey->equippedUpgrades.num );
    }
  }
  if ( vehicle_boostUpgrade.valueInteger != 0 )
    this->boostlevel = vehicle_boostUpgrade.valueInteger;
  baseBoostUpgrade = this->vehicleProps->baseBoostUpgrade;
  if ( this->boostlevel < baseBoostUpgrade )
    this->boostlevel = baseBoostUpgrade;
  v21 = this->presentable;
  if ( v21 != nullptr )
    v22 = v21->GetVehicleInterface(this: v21);
  else
    v22 = nullptr;
  idPresentableVehicle::SetBoostDuration(this: v22, val: 0.0);
  boostlevel = this->boostlevel;
  switch ( boostlevel )
  {
    case 1:
      v24 = this->presentable;
      valueFloat = vehicle_boostDuration.valueFloat;
      if ( v24 != nullptr )
      {
        v26 = v24->GetVehicleInterface(this: v24);
        v27 = valueFloat;
      }
      else
      {
        v26 = nullptr;
        v27 = vehicle_boostDuration.valueFloat;
      }
      goto LABEL_55;
    case 2:
      v28 = this->presentable;
      v29 = vehicle_boostDuration.valueFloat;
      if ( v28 != nullptr )
        v26 = v28->GetVehicleInterface(this: v28);
      else
        v26 = nullptr;
      v30 = 2.0;
LABEL_54:
      v27 = (float)((float)v29 + (float)v30);
LABEL_55:
      idPresentableVehicle::SetBoostDuration(this: v26, val: v27);
      break;
    case 3:
      v31 = this->presentable;
      v29 = vehicle_boostDuration.valueFloat;
      if ( v31 != nullptr )
        v26 = v31->GetVehicleInterface(this: v31);
      else
        v26 = nullptr;
      v30 = 4.0;
      goto LABEL_54;
    default:
      break;
  }
  v32 = this->presentable;
  if ( v32 != nullptr )
    v33 = v32->GetVehicleInterface(this: v32);
  else
    v33 = nullptr;
  idPresentableVehicle::StopBoost(this: v33);
  v34 = this->presentable;
  if ( v34 != nullptr )
    v35 = v34->GetVehicleInterface(this: v34);
  else
    v35 = nullptr;
  idPresentableVehicle::ResetDriverView(this: v35);
  v36 = idPlayer::CastTo(c: other);
  if ( v36 != nullptr )
  {
    idRageMetrics::EnterVehicle(this: clientGame->rageMetrics, car: this, player: v36);
    this->movePlayerToVehicle = 2;
    this->playerWasOccupant = true;
  }
  return 1;
}


// ========================================================================
// ?ExitVehicle@idVehicle_Car@@UAA_NH_N0@Z
// EA  : 0x82D428D8
// RVA : 0x00D428D8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

int __fastcall idVehicle_Car::ExitVehicle(idVehicle_Car *this, unsigned int occupant, bool force, bool thrown)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v9; // r3
  idEntity *OccupantAsEntity; // r25
  idPlayer *v12; // r24
  idThirdPersonCrosshair *Crosshair; // r3
  int v14; // r27
  int v15; // r29
  int v16; // r28
  idPresentable *v17; // r3
  int v18; // r3
  idPresentable *v19; // r3
  idWheelDef *v20; // r30
  int v21; // r3
  const idDeclTable *friction_longitudinal; // r10
  int v23; // r7
  idPresentable *v24; // r3
  idRenderModel *model; // r30
  int v26; // r3
  float *v27; // r11
  idPresentable *v28; // r3
  double v29; // fp31
  double v30; // fp30
  double v31; // fp29
  int v32; // r3
  int v33; // r11
  float *v34; // r11
  const idVehicleSoundDef *SoundDef; // r3
  idPresentable *v36; // r3
  idPresentablePlayer *v37; // r3

  if ( !force )
  {
    presentable = this->presentable;
    v9 = presentable != nullptr ? presentable->GetVehicleInterface(this: presentable) : nullptr;
    if ( idPresentableVehicle::GetCrosshair(this: v9)->firing )
      return 0;
  }
  OccupantAsEntity = idVehicle::GetOccupantAsEntity(this, index: occupant);
  v12 = idVehicle::PlayerIsOccupant(this);
  if ( (unsigned __int8)idVehicle::ExitVehicle(this, occupant, force, thrown) == 0 )
    return 0;
  if ( idVehicle::GetDriver(this) == nullptr )
  {
    idVehicle_Car::SetEngineRunning(this, bl: false);
    idVehicle::ClearWeaponFX(this);
    idVehicle_Car::StopBoostFX(this);
    idVehicle_Car::StopBlurFX(this);
  }
  if ( idVehicle::GetNumActiveOccupants(this) == 0 )
  {
    Crosshair = idVehicle::GetCrosshair(this);
    idThirdPersonCrosshair::ClearTarget(this: Crosshair);
  }
  if ( vehicle_useAiProps.valueInteger != 0 )
  {
    v14 = 0;
    v15 = 0;
    v16 = 0;
    while ( 1 )
    {
      v17 = this->presentable;
      v18 = v17 != nullptr ? (int)v17->GetVehicleInterface(this: v17) : 0;
      if ( v14 >= *(_DWORD *)(v18 + 16492) )
        break;
      v19 = this->presentable;
      v20 = &this->vehicleProps->wheels.list[v16];
      if ( v19 != nullptr )
        v21 = (int)v19->GetVehicleInterface(this: v19);
      else
        v21 = 0;
      friction_longitudinal = v20->friction_longitudinal;
      v23 = *(_DWORD *)(*(_DWORD *)(v21 + 16488) + v15 + 4);
      *(_DWORD *)(v23 + 496) = v20->friction_lateral;
      *(_DWORD *)(v23 + 492) = friction_longitudinal;
      v24 = this->presentable;
      if ( v24 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v24 = this->presentable;
      }
      model = v24->model;
      if ( v24 != nullptr )
        v26 = (int)v24->GetVehicleInterface(this: v24);
      else
        v26 = 0;
      v27 = *(float **)(v26 + 11628);
      v28 = this->presentable;
      v29 = (float)(v27[77] * model->g.scale.z);
      v30 = (float)(v27[78] * model->g.scale.z);
      v31 = (float)(v27[79] * model->g.scale.z);
      if ( v28 != nullptr )
        v32 = (int)v28->GetVehicleInterface(this: v28);
      else
        v32 = 0;
      ++v14;
      ++v16;
      v33 = *(_DWORD *)(v32 + 16488) + v15;
      v15 += 12;
      v34 = *(float **)(v33 + 4);
      v34[131] = v29;
      v34[132] = v30;
      v34[133] = v31;
    }
  }
  if ( (unsigned __int8)idVehicleAI::IsTypeOf(c: OccupantAsEntity) != 0 && occupant == 0 )
    this->UseAiProperties(this, a2: false);
  idEntity::StopSound(this, channel: SND_CHANNEL_MUSIC1, peerMask: 0xFFu);
  idEntity::StopSound(this, channel: SND_CHANNEL_MUSIC2, peerMask: 0xFFu);
  if ( idVehicle_Car::GetSoundDef(this)->exitVehicle != nullptr )
  {
    SoundDef = idVehicle_Car::GetSoundDef(this);
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_DOOR,
      shader: SoundDef->exitVehicle,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
  }
  if ( v12 != nullptr )
  {
    v36 = v12->presentable;
    if ( v36 != nullptr )
      v37 = v36->GetPlayerInterface_2(this: v36);
    else
      v37 = nullptr;
    idPresentablePlayer::SetServerOverridePos(this: v37, teleport: false, extra: 0);
  }
  return 1;
}


// ========================================================================
// ?PlayZoomSound@idVehicle_Car@@QAAXXZ
// EA  : 0x82D42C08
// RVA : 0x00D42C08
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::PlayZoomSound(idVehicle_Car *this)
{
  const idVehicleSoundDef *SoundDef; // r3

  if ( idVehicle_Car::GetSoundDef(this)->zooming != nullptr
    && this->soundState.nextZoomTime < idGameTimeManager::GetGameMs(
                                         this: &clientGame->gameTimeManager,
                                         type: GAMETIME_SCALED) )
  {
    SoundDef = idVehicle_Car::GetSoundDef(this);
    this->soundState.nextZoomTime = idEntity::StartSoundShader(
                                      this,
                                      channel: SND_CHANNEL_WEAPON_2,
                                      shader: SoundDef->zooming,
                                      soundShaderFlags: (soundShaderFlags_t)0,
                                      peerMask: 0xFFu);
    this->soundState.nextZoomTime += idGameTimeManager::GetGameMs(
                                       this: &clientGame->gameTimeManager,
                                       type: GAMETIME_SCALED);
  }
}


// ========================================================================
// ?ZoomIn@idVehicle_Car@@UAA_NXZ
// EA  : 0x82D42C98
// RVA : 0x00D42C98
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

int __fastcall idVehicle_Car::ZoomIn(idVehicle_Car *this)
{
  if ( !idVehicle::ZoomIn(this) )
    return 0;
  idVehicle_Car::PlayZoomSound(this);
  return 1;
}


// ========================================================================
// ?ZoomOut@idVehicle_Car@@UAA_NXZ
// EA  : 0x82D42CF8
// RVA : 0x00D42CF8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

int __fastcall idVehicle_Car::ZoomOut(idVehicle_Car *this)
{
  if ( !idVehicle::ZoomOut(this) )
    return 0;
  idVehicle_Car::PlayZoomSound(this);
  return 1;
}


// ========================================================================
// ?AddCollisionFromOther@idVehicle_Car@@QAAXPAV1@@Z
// EA  : 0x82D42D58
// RVA : 0x00D42D58
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __fastcall idVehicle_Car::AddCollisionFromOther(idVehicle_Car *this, idVehicle_Car *other)
{
  char v4; // r24
  int v5; // r30
  int v6; // r29
  int value; // r9
  idVehicle_Car *v8; // r3
  idVehicle_Car *v9; // r3
  idVehicle_Car::vehicleHitData_t v10; // [sp+50h] [-60h] BYREF

  v4 = 0;
  v5 = 0;
  if ( this->hitList.num > 0 )
  {
    v6 = 0;
    while ( 1 )
    {
      value = this->hitList.list[v6].otherCar.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v8 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v9 = idVehicle_Car::CastTo(c: v8);
      }
      else
      {
        v9 = nullptr;
      }
      if ( v9 == other )
        break;
      ++v5;
      ++v6;
      if ( v5 >= this->hitList.num )
        goto LABEL_11;
    }
    v4 = 1;
    this->hitList.list[v5].nextCollisionTime = vehicle_online_nextCollisionTime.valueInteger
                                             + idGameTimeManager::GetGameMs(
                                                 this: &clientGame->gameTimeManager,
                                                 type: GAMETIME_SCALED);
  }
LABEL_11:
  if ( v4 == 0 )
  {
    if ( other != nullptr )
      v10.otherCar.spawnId.value = (gameLocal->spawnIds.ptr[other->entityNumber] << 13) | other->entityNumber;
    else
      v10.otherCar.spawnId.value = 0x1FFF;
    v10.nextCollisionTime = vehicle_online_nextCollisionTime.valueInteger
                          + idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idList<idVehicle_Car::vehicleHitData_t,5>::Append(this: &this->hitList, obj: &v10);
  }
}


// ========================================================================
// ?Damage@idVehicle_Car@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82D42EA8
// RVA : 0x00D42EA8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idVehicle_Car::Damage(
        idVehicle_Car *this,
        idEntity *inflictor,
        idPlayer *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        const idVec3 *trace,
        int a8)
{
  int valueInteger; // r11
  double v16; // fp1
  idPresentable *presentable; // r3
  int v18; // r3
  double v19; // fp1
  int v20; // r11
  idPlayer *v21; // r3
  idPlayer *v22; // r19
  idLobbyBase *v23; // r3
  idLobbyBase *v24; // r3
  gameTeam_t Team; // r31
  idPresentable *v26; // r26
  double v27; // fp31
  double v28; // fp29
  double v29; // fp31
  idLobbyBase *v30; // r3
  idPresentable *v31; // r3
  int v32; // r3
  double maxArmoredHealth; // fp30
  double v34; // fp0
  int v35; // r31
  int ViolentRollStartTime; // r31
  idPhysics *Physics; // r3
  float *v38; // r3
  double v41; // fp3
  double v42; // fp8
  double v43; // fp5
  double v44; // fp3
  double v45; // fp0
  double v46; // fp30
  int v47; // r11
  const idVec3 *gameType; // r7
  idPhysics *v49; // r31
  long double v50; // fp2
  long double v51; // fp2
  double v52; // fp30
  float *v53; // r3
  idLobbyBase *v54; // r3
  double valueFloat; // fp0
  int v56; // r11
  idLobbyBase *v57; // r3
  double v58; // fp24
  double v59; // fp31
  double v60; // fp0
  double v61; // fp31
  idEntity *v62; // r3
  idPhysics *v63; // r3
  int v64; // r3
  float v65; // r9
  idPresentable *v66; // r11
  idPresentableVehicle *v67; // r3
  int v68; // r9
  __int128 v69; // r7 OVERLAPPED
  int v70; // r8
  idPhysics *v71; // r3
  __int64 v72; // r5
  idCVar *v73; // r10
  double v74; // fp11
  unsigned int v75; // r7
  specialDeath_t specialDeath; // r11
  double v77; // fp31
  double z; // fp30
  double x; // fp29
  double y; // fp28
  double v81; // fp22
  double v82; // fp21
  double v83; // fp20
  idPhysics *v84; // r3
  __int128 v85; // r10
  unsigned int v86; // r6
  double v87; // fp6
  double v88; // fp26
  double v89; // fp22
  double v90; // fp21
  double v91; // fp20
  double v92; // fp19
  double v93; // fp18
  float *v94; // r3
  double v95; // fp7
  double v96; // fp5
  double v97; // fp4
  idPhysics *v98; // r3
  idPresentable *v99; // r3
  int v100; // r3
  idPhysics *v101; // r29
  idPhysics *v102; // r27
  int GameMs; // r25
  idPresentable *v104; // r26
  const idMat3 *v105; // r29
  const idVec3 *v106; // r3
  int v107; // r7
  idPhysics *v108; // r29
  idPhysics *v109; // r27
  int v110; // r3
  idPresentable *v111; // r11
  int v112; // r29
  int v113; // r3
  __int128 v114; // r10
  unsigned int v115; // r6
  unsigned int v116; // r6
  double v117; // fp8
  double v118; // fp1
  double v119; // fp0
  __int64 v120; // r5
  unsigned int v121; // r7
  int v122; // r29
  idEntity *Driver; // r3
  idPlayer *v124; // r3
  idPresentable *v125; // r11
  idPresentable *v126; // r30
  idPresentable *v127; // r31
  unsigned int v128; // r27
  const idMaterial *particleShotDamage; // r26
  idImpactManager *ImpactMgr; // r3
  idPresentable *v131; // r3
  int v132; // r3
  int *v133; // r27
  int v134; // r6
  int v135; // r7
  int v136; // r11
  double v137; // fp0
  int v138; // r5
  int v139; // r8
  _DWORD *v140; // r9
  float *v141; // r10
  double v142; // fp9
  double v143; // fp7
  double v144; // fp5
  float *v145; // r10
  double v146; // fp9
  double v147; // fp7
  double v148; // fp5
  float *v149; // r10
  double v150; // fp9
  double v151; // fp7
  double v152; // fp5
  float *v153; // r10
  double v154; // fp9
  double v155; // fp7
  double v156; // fp5
  int v157; // r9
  int v158; // ctr
  float *v159; // r10
  double v160; // fp9
  double v161; // fp7
  double v162; // fp5
  double damage; // fp0
  int v164; // r30
  int v165; // r31
  double v166; // fp0
  int v167; // r11
  idLobbyBase *v168; // r3
  idPresentable *v169; // r3
  int v170; // r3
  int v172; // [sp+8h] [-1F8h]
  const idColor *v173; // [sp+Ch] [-1F4h]
  int v174; // [sp+10h] [-1F0h]
  int v175; // [sp+14h] [-1ECh]
  double v176; // [sp+18h] [-1E8h]
  double v177; // [sp+20h] [-1E0h]
  int v178; // [sp+28h] [-1D8h]
  int v179; // [sp+2Ch] [-1D4h]
  int v180; // [sp+30h] [-1D0h]
  int v181; // [sp+34h] [-1CCh]
  int v182; // [sp+38h] [-1C8h]
  int v183; // [sp+3Ch] [-1C4h]
  int v184; // [sp+40h] [-1C0h]
  int v185; // [sp+44h] [-1BCh]
  int v186; // [sp+48h] [-1B8h]
  int v187; // [sp+4Ch] [-1B4h]
  int v188; // [sp+50h] [-1B0h]
  int v189; // [sp+54h] [-1ACh]
  int v190; // [sp+58h] [-1A8h]
  int v191; // [sp+5Ch] [-1A4h]
  int v192; // [sp+60h] [-1A0h]
  idPresentableVehicle *v193; // [sp+68h] [-198h]
  int v194; // [sp+6Ch] [-194h]
  idVec3 v195; // [sp+70h] [-190h] BYREF
  idVec3 v196; // [sp+80h] [-180h] BYREF
  idVec3 v197; // [sp+90h] [-170h] BYREF
  float v198[4]; // [sp+A0h] [-160h] BYREF
  float v199[4]; // [sp+B0h] [-150h] BYREF
  idVec3 v200; // [sp+C0h] [-140h] BYREF
  idMat3 v201[4]; // [sp+D0h] [-130h] BYREF

  valueInteger = vehicle_god.valueInteger;
  if ( vehicle_god.valueInteger != 1 )
    goto LABEL_5;
  if ( idVehicle::PlayerIsOccupant(this) == nullptr )
  {
    valueInteger = vehicle_god.valueInteger;
LABEL_5:
    if ( valueInteger == 2 || damageDef == nullptr )
      goto LABEL_3;
    if ( damageDef == this->damages.vehicle )
    {
      presentable = this->presentable;
      v18 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
      if ( *(_BYTE *)(v18 + 20500) != 0 )
        goto LABEL_3;
    }
    v19 = ((double (__fastcall *)(idVehicle_Car *))this->GetHealth)(a1: this);
    if ( (unsigned __int8)idMath::IsValid(f: v19) == 0 )
      this->SetHealth(this, a2: 1.0);
    if ( ((double (__fastcall *)(idVehicle_Car *))this->GetHealth)(a1: this) <= 0.0 )
    {
LABEL_15:
      v16 = 0.0;
      return *((float *)&v16 + 1);
    }
    v20 = vehicle_showDamageValues.valueInteger;
    if ( vehicle_showDamageValues.valueInteger == 1 )
    {
      if ( idVehicle::PlayerIsOccupant(this) != nullptr )
      {
LABEL_20:
        if ( inflictor != nullptr || attacker != nullptr )
          idLib::Printf(fmt: "\n================== DAMAGE ===========================\n\n");
LABEL_23:
        v21 = idVehicle::PlayerIsOccupant(this);
        v22 = v21;
        if ( attacker != nullptr && v21 != nullptr && attacker != v21 && attacker != (idPlayer *)this )
        {
          v23 = session->GetActingGameStateLobbyBase(this: session);
          if ( (v23->GetMatchParms(this: v23)->matchFlags & 4) == 0 )
          {
            v24 = session->GetActingGameStateLobbyBase(this: session);
            if ( !v24->GetMatchParms(this: v24)->allowFriendlyFire )
            {
              Team = idEntity::GetTeam(this: attacker);
              if ( idEntity::GetTeam(this) == Team && idEntity::GetTeam(this) != TEAM_NONE )
                goto LABEL_15;
            }
          }
        }
        v26 = nullptr;
        if ( attacker != nullptr && attacker->presentable != nullptr )
          v26 = attacker->presentable;
        v27 = damageScale;
        v28 = 0.0;
        if ( v22 != nullptr )
        {
          if ( idPlayer::GetGodMode(this: v22) )
          {
            v27 = 0.0;
          }
          else if ( g_damageSave.valueInteger != 0 )
          {
            v29 = ((double (__fastcall *)(idVehicle_Car *))this->GetHealth)(a1: this);
            v27 = (float)((float)v29 / this->GetMaxHealth(this));
          }
          v27 = (float)(vehicle_damageScale_player.valueFloat * (float)v27);
          if ( common->IsMultiplayer(this: common) )
          {
            v30 = session->GetActingGameStateLobbyBase(this: session);
            if ( v30->GetMatchParms(this: v30)->gameType == 2 )
            {
              v31 = this->presentable;
              if ( v31 != nullptr )
                v32 = (int)v31->GetVehicleInterface(this: v31);
              else
                v32 = 0;
              v27 = (float)(*(float *)(v32 + 17948) * (float)v27);
            }
          }
          maxArmoredHealth = this->maxArmoredHealth;
          v34 = (float)(idVehicle::GetArmoredHealth(this) / (float)maxArmoredHealth);
          if ( v34 >= 0.0 )
          {
            if ( v34 > 1.0 )
              v34 = 1.0;
          }
          else
          {
            v34 = 0.0;
          }
          v28 = (float)((float)v34 * (float)100.0);
        }
        if ( v22 == attacker )
          v27 = (float)(damageDef->selfDamageScale * (float)v27);
        if ( !common->IsMultiplayer(this: common) )
        {
          v35 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          if ( v35 - idVehicle_Car::GetViolentRollStartTime(this) >= 500 )
          {
            ViolentRollStartTime = idVehicle_Car::GetViolentRollStartTime(this);
            if ( ViolentRollStartTime > idVehicle_Car::GetViolentRollStopTime(this) )
            {
              Physics = idEntity::GetPhysics(this);
              v38 = (float *)Physics->GetAngularVelocity(this: (idPhysics *)&v197, result: (idVec3 *)Physics, a3: 0);
              _FP6 = (float)((float)((float)(v38[2] * v38[2]) + (float)((float)(*v38 * *v38) + (float)(v38[1] * v38[1])))
                           - idMath::FLT_SMALLEST_NON_DENORMAL);
              __asm { fsel      f4, f6, f7, f13 }
              v41 = __frsqrte(_FP4);
              v42 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41
                                                                                                  * (float)((float)((float)(v38[2] * v38[2]) + (float)((float)(*v38 * *v38) + (float)(v38[1] * v38[1]))) * (float)0.5))
                                                                                          * (float)v41)
                                                                                  - (float)1.5)
                                                                  * (float)v41)
                                                          * (float)((float)((float)(v38[2] * v38[2])
                                                                          + (float)((float)(*v38 * *v38)
                                                                                  + (float)(v38[1] * v38[1])))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v41
                                                                                          * (float)((float)((float)(v38[2] * v38[2]) + (float)((float)(*v38 * *v38) + (float)(v38[1] * v38[1])))
                                                                                                  * (float)0.5))
                                                                                  * (float)v41)
                                                                          - (float)1.5)
                                                          * (float)v41))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v41
                                                                  * (float)((float)((float)(v38[2] * v38[2])
                                                                                  + (float)((float)(*v38 * *v38)
                                                                                          + (float)(v38[1] * v38[1])))
                                                                          * (float)0.5))
                                                          * (float)v41)
                                                  - (float)1.5)
                                  * (float)v41));
              v43 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)(v38[2] * v38[2]) + (float)((float)(*v38 * *v38) + (float)(v38[1] * v38[1]))) * (float)0.5)) * (float)v41) - (float)1.5)
                                                                                                  * (float)v41)
                                                                                          * (float)((float)((float)(v38[2] * v38[2]) + (float)((float)(*v38 * *v38) + (float)(v38[1] * v38[1])))
                                                                                                  * (float)0.5))
                                                                                  * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)(v38[2] * v38[2]) + (float)((float)(*v38 * *v38) + (float)(v38[1] * v38[1]))) * (float)0.5)) * (float)v41) - (float)1.5)
                                                                                          * (float)v41))
                                                                          - (float)1.5)
                                                          * (float)((float)-(float)((float)((float)((float)v41
                                                                                                  * (float)((float)((float)(v38[2] * v38[2]) + (float)((float)(*v38 * *v38) + (float)(v38[1] * v38[1]))) * (float)0.5))
                                                                                          * (float)v41)
                                                                                  - (float)1.5)
                                                                  * (float)v41))
                                                  * (float)((float)((float)(v38[2] * v38[2])
                                                                  + (float)((float)(*v38 * *v38)
                                                                          + (float)(v38[1] * v38[1])))
                                                          * (float)0.5))
                                          * (float)v42)
                                  - (float)1.5);
              v44 = (float)((float)((float)v43
                                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)(v38[2] * v38[2]) + (float)((float)(*v38 * *v38) + (float)(v38[1] * v38[1]))) * (float)0.5)) * (float)v41)
                                                                                                  - (float)1.5)
                                                                                  * (float)v41)
                                                                          * (float)((float)((float)(v38[2] * v38[2])
                                                                                          + (float)((float)(*v38 * *v38)
                                                                                                  + (float)(v38[1] * v38[1])))
                                                                                  * (float)0.5))
                                                                  * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)(v38[2] * v38[2]) + (float)((float)(*v38 * *v38) + (float)(v38[1] * v38[1]))) * (float)0.5))
                                                                                                  * (float)v41)
                                                                                          - (float)1.5)
                                                                          * (float)v41))
                                                          - (float)1.5)
                                          * (float)((float)-(float)((float)((float)((float)v41
                                                                                  * (float)((float)((float)(v38[2] * v38[2])
                                                                                                  + (float)((float)(*v38 * *v38) + (float)(v38[1] * v38[1])))
                                                                                          * (float)0.5))
                                                                          * (float)v41)
                                                                  - (float)1.5)
                                                  * (float)v41)))
                          * (float)((float)(v38[2] * v38[2]) + (float)((float)(*v38 * *v38) + (float)(v38[1] * v38[1]))));
              v45 = (float)((float)v44 * (float)0.5);
              if ( v45 >= 1.0 )
              {
                v46 = 10.0;
                if ( v45 <= 10.0 )
                  v46 = (float)((float)v44 * (float)0.5);
              }
              else
              {
                v46 = 1.0;
              }
              if ( v22 != nullptr )
                v27 = (float)((float)(vehicle_damageScale_violentRoll_player.valueFloat * (float)v46) * (float)v27);
              else
                v27 = (float)((float)(vehicle_damageScale_violentRoll_ai.valueFloat * (float)v46) * (float)v27);
              v47 = vehicle_showDamageValues.valueInteger;
              if ( vehicle_showDamageValues.valueInteger == 1 )
              {
                if ( idVehicle::PlayerIsOccupant(this) != nullptr )
                {
LABEL_66:
                  v177 = (float)(vehicle_damageScale_violentRoll_player.valueFloat * (float)v46);
                  v176 = v27;
                  idLib::Printf(fmt: "DAMAGE: %f    [ ** Violent Roll **   angularDamageScale: %f ]\n", v27, v177);
                  goto LABEL_67;
                }
                v47 = vehicle_showDamageValues.valueInteger;
              }
              if ( v47 == 2 )
                goto LABEL_66;
            }
          }
        }
LABEL_67:
        if ( common->IsMultiplayer(this: common) )
          goto LABEL_83;
        v49 = idEntity::GetPhysics(this);
        *(double *)&v50 = (float)(vehicle_damagescale_overturned_angle.valueFloat * idMath::M_DEG2RAD);
        v51 = cos(x: v50);
        v52 = (float)*(double *)&v51;
        v53 = (float *)v49->GetAxis(this: v49, a2: 0);
        if ( (float)((float)(v53[6] * vec3_up.x) + (float)((float)(v53[7] * vec3_up.y) + (float)(v53[8] * vec3_up.z))) > -v52 )
          goto LABEL_83;
        if ( v22 != nullptr )
        {
          if ( common->IsMultiplayer(this: common)
            && (v54 = session->GetActingGameStateLobbyBase(this: session),
                (gameType = (const idVec3 *)v54->GetMatchParms(this: v54)->gameType) == (const idVec3 *)2) )
          {
            valueFloat = vehicle_online_damagescale_overturned_player.valueFloat;
          }
          else
          {
            valueFloat = vehicle_damagescale_overturned_player.valueFloat;
          }
        }
        else
        {
          valueFloat = vehicle_damagescale_overturned_ai.valueFloat;
        }
        v56 = vehicle_showDamageValues.valueInteger;
        v27 = (float)((float)valueFloat * (float)v27);
        if ( vehicle_showDamageValues.valueInteger == 1 )
        {
          if ( idVehicle::PlayerIsOccupant(this) != nullptr )
          {
LABEL_79:
            if ( common->IsMultiplayer(this: common)
              && (v57 = session->GetActingGameStateLobbyBase(this: session), v57->GetMatchParms(this: v57)->gameType == 2) )
            {
              v176 = v27;
              v177 = vehicle_online_damagescale_overturned_player.valueFloat;
              idLib::Printf(
                fmt: "DAMAGE: %f    [ ** Overturned **   scale: %f ]\n",
                v27,
                vehicle_online_damagescale_overturned_player.valueFloat);
            }
            else
            {
              v177 = vehicle_damagescale_overturned_player.valueFloat;
              v176 = v27;
              idLib::Printf(
                fmt: "DAMAGE: %f    [ ** Overturned **   scale: %f ]\n",
                v27,
                vehicle_damagescale_overturned_player.valueFloat);
            }
LABEL_83:
            v58 = idVehicle::Damage(
                    this,
                    inflictor,
                    attacker,
                    damageDef,
                    damageScale: v27,
                    dir: gameType,
                    trace,
                    (trace_t *)a8);
            if ( common->IsMultiplayer(this: common) && v22 != nullptr )
            {
              v59 = this->maxArmoredHealth;
              v60 = (float)(idVehicle::GetArmoredHealth(this) / (float)v59);
              if ( v60 >= 0.0 )
              {
                if ( v60 > 2.0 )
                  v60 = 2.0;
              }
              else
              {
                v60 = 0.0;
              }
              v61 = (float)((float)v60 * (float)100.0);
              if ( attacker != nullptr )
              {
                v62 = inflictor;
                if ( inflictor == nullptr )
                  v62 = attacker;
                v63 = idEntity::GetPhysics(this: v62);
                v64 = (int)v63->GetOrigin(this: v63, a2: 0);
                v65 = *(float *)(v64 + 4);
                v66 = this->presentable;
                v197.x = *(float *)v64;
                v197.y = v65;
                if ( v66 != nullptr )
                  v67 = v66->GetVehicleInterface(this: v66);
                else
                  v67 = nullptr;
                v68 = (char *)this->damages.vehicle - (char *)damageDef;
                DWORD1(v69) = LODWORD(v197.y);
                v70 = __ROL4__(LODWORD(trace->z), 32);
                *((_QWORD *)&v69 + 1) = *(_QWORD *)&trace->x;
                LOBYTE(v194) = (_cntlzw(v68) & 0x20) != 0;
                idPresentableVehicle::RecordClientDamageInfo(
                  this: v67,
                  impactPoint: *(__int64 *)((char *)&v69 + 4),
                  attacker: *(__int64 *)((char *)&v69 - 4),
                  damageScale,
                  damage: 0.0,
                  startHealth: v28,
                  endHealth: v61,
                  predicted: v68,
                  a9: (unsigned __int8)v194,
                  a10: v172,
                  a11: (int)v173,
                  a12: v174,
                  a13: v175,
                  a14: SHIDWORD(v176),
                  a15: SLODWORD(v176),
                  a16: SHIDWORD(v177),
                  a17: SLODWORD(v177),
                  a18: v178,
                  a19: v179,
                  a20: v180,
                  a21: v181,
                  a22: v182,
                  a23: v183,
                  a24: v184,
                  a25: v185,
                  a26: v186,
                  a27: v187,
                  a28: v188,
                  a29: v189,
                  a30: v190,
                  a31: v191,
                  a32: v192,
                  a33: (int)v26,
                  a34: v193,
                  a35: v194,
                  a36: SLOBYTE(v195.x));
              }
            }
            if ( ((double (__fastcall *)(idVehicle_Car *))this->GetHealth)(a1: this) <= 0.0 )
            {
              if ( attacker != nullptr )
                this->specialDeathAttacker.spawnId.value = (gameLocal->spawnIds.ptr[attacker->entityNumber] << 13)
                                                         | attacker->entityNumber;
              else
                this->specialDeathAttacker.spawnId.value = 0x1FFF;
              this->specialDeath = DEATH_IMPULSE_1;
              if ( damageDef->specialDeathType == DEATH_PULL_FROM_CAMERA || common->IsMultiplayer(this: common) )
                this->specialDeath = damageDef->specialDeathType;
              v71 = idEntity::GetPhysics(this);
              v71->GetLinearVelocity(this: (idPhysics *)&v196, result: (idVec3 *)v71, a3: 0);
              if ( this->specialDeath == DEATH_IMPULSE_1 && vehicle_always_special_death.valueInteger == 0 )
              {
                v73 = common->IsMultiplayer(this: common)
                    ? &vehicle_special_death_chance_mp
                    : &vehicle_special_death_chance;
                v74 = v73->valueFloat;
                if ( (float)((float)(v196.z * v196.z) + (float)((float)(v196.x * v196.x) + (float)(v196.y * v196.y))) < 1115136.0
                  || (v75 = 1664525 * clientGame->random.seed + 1013904223,
                      clientGame->random.seed = v75,
                      LODWORD(v72) = (v75 >> 10) & 0x7FFF,
                      *(_QWORD *)&v195.x = v72,
                      (float)((float)v72 * (float)0.000030518509) >= v74) )
                {
                  this->specialDeath = DEATH_INSTANT;
                }
              }
              if ( this->forceInstantDeath || (specialDeath = this->specialDeath) == DEATH_INSTANT )
              {
                idVehicle_Car::DestroyVehicle(this, attacker, preventItemDrop: false);
                if ( vehicle_playerNoDie.valueInteger != 0 && v22 != nullptr )
                {
LABEL_193:
                  v16 = v58;
                  return *((float *)&v16 + 1);
                }
              }
              else if ( specialDeath == DEATH_IMPULSE_1 )
              {
                v195 = v196;
                v77 = idVec3::NormalizeFast(this: &v195);
                if ( v77 > 1000.0 )
                  v77 = 1000.0;
                z = v195.z;
                x = v195.x;
                y = v195.y;
                v81 = (float)((float)(vec3_up.z * v195.y) - (float)(vec3_up.y * v195.z));
                v82 = (float)((float)(v195.z * vec3_up.x) - (float)(vec3_up.z * v195.x));
                v83 = (float)((float)(vec3_up.y * v195.x) - (float)(v195.y * vec3_up.x));
                v84 = idEntity::GetPhysics(this);
                DWORD1(v85) = clientGame->random.seed;
                v86 = 1664525 * clientGame->random.seed + 1013904223;
                clientGame->random.seed = v86;
                DWORD2(v85) = (v86 >> 10) & 0x7FFF;
                *(_QWORD *)&v195.x = *(_QWORD *)((char *)&v85 + 4);
                HIDWORD(v85) = 1664525 * clientGame->random.seed;
                v87 = (float)*(__int64 *)((char *)&v85 + 4);
                clientGame->random.seed = HIDWORD(v85) + 1013904223;
                DWORD2(v85) = v84->__vftable;
                LODWORD(v85) = ((unsigned int)(HIDWORD(v85) + 1013904223) >> 10) & 0x7FFF;
                *(_QWORD *)&v195.x = v85;
                v88 = (float)((float)v81
                            * (float)((float)((float)((float)v87 * (float)0.000061037019) - (float)1.0) * (float)100.0));
                v89 = (float)((float)v82
                            * (float)((float)((float)((float)v87 * (float)0.000061037019) - (float)1.0) * (float)100.0));
                v90 = (float)((float)v83
                            * (float)((float)((float)((float)v87 * (float)0.000061037019) - (float)1.0) * (float)100.0));
                v91 = (float)((float)((float)((float)((float)((float)(__int64)v85 * (float)0.000061037019) - (float)1.0)
                                            + (float)1.0)
                                    * (float)75.0)
                            * (float)x);
                v92 = (float)((float)y
                            * (float)((float)((float)((float)((float)(__int64)v85 * (float)0.000061037019) - (float)1.0)
                                            + (float)1.0)
                                    * (float)75.0));
                v93 = (float)((float)z
                            * (float)((float)((float)((float)((float)(__int64)v85 * (float)0.000061037019) - (float)1.0)
                                            + (float)1.0)
                                    * (float)75.0));
                v94 = (float *)(*(int (__fastcall **)(idPhysics *, _DWORD))(DWORD2(v85) + 64))(a1: v84, a2: 0);
                v95 = (float)(*v94 + (float)v91);
                v96 = (float)(v94[1] + (float)v92);
                v97 = (float)(v94[2] + (float)v93);
                v198[0] = vehicle_death_impulse.valueFloat * (float)((float)x * (float)v77);
                v198[1] = vehicle_death_impulse.valueFloat * (float)((float)y * (float)v77);
                v199[0] = (float)v95 + (float)v88;
                v199[1] = (float)v96 + (float)v89;
                v199[2] = (float)v97 + (float)v90;
                v198[2] = vehicle_death_impulse.valueFloat * (float)((float)((float)z * (float)v77) + (float)v77);
                v98 = idEntity::GetPhysics(this);
                v98->ApplyImpulse(this: v98, a2: 0, a3: (const idVec3 *)v199, a4: (const idVec3 *)v198);
                v99 = this->presentable;
                if ( v99 != nullptr )
                  v100 = (int)v99->GetVehicleInterface(this: v99);
                else
                  v100 = 0;
                if ( *(int *)(v100 + 17752) <= 0 )
                {
                  v108 = idEntity::GetPhysics(this);
                  v109 = idEntity::GetPhysics(this);
                  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                  if ( this->presentable == nullptr )
                    idEntity::InitPresentableInternal(this);
                  v104 = this->presentable;
                  v105 = v108->GetAxis(this: v108, a2: 0);
                  v106 = v109->GetOrigin(this: v109, a2: 0);
                  v107 = 49;
                }
                else
                {
                  v101 = idEntity::GetPhysics(this);
                  v102 = idEntity::GetPhysics(this);
                  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                  if ( this->presentable == nullptr )
                    idEntity::InitPresentableInternal(this);
                  v104 = this->presentable;
                  v105 = v101->GetAxis(this: v101, a2: 0);
                  v106 = v102->GetOrigin(this: v102, a2: 0);
                  v107 = 47;
                }
                idFXManager::StartFX(this: &v104->fxManager, org: v106, axis: v105, time: GameMs, startCondition: v107);
                v110 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                v111 = this->presentable;
                v112 = v110;
                if ( v111 != nullptr )
                  v113 = (int)v111->GetVehicleInterface(this: this->presentable);
                else
                  v113 = 0;
                *(_DWORD *)(v113 + 15656) = v112;
                this->specialDeathActive = true;
                this->specialDeathStartTime = idGameTimeManager::GetGameMs(
                                                this: &clientGame->gameTimeManager,
                                                type: GAMETIME_SCALED);
              }
              else if ( specialDeath == DEATH_PULL_FROM_CAMERA )
              {
                this->specialDeathActive = true;
                this->specialDeathStartTime = idGameTimeManager::GetGameMs(
                                                this: &clientGame->gameTimeManager,
                                                type: GAMETIME_SCALED);
              }
            }
            if ( a8 != 0 && *(_DWORD *)(a8 + 120) == 0 )
            {
              DWORD1(v114) = clientGame->random.seed;
              v115 = 1664525 * clientGame->random.seed + 1013904223;
              clientGame->random.seed = v115;
              DWORD2(v114) = (v115 >> 10) & 0x7FFF;
              *(_QWORD *)&v195.x = *(_QWORD *)((char *)&v114 + 4);
              v116 = 1664525 * clientGame->random.seed + 1013904223;
              v117 = (float)*(__int64 *)((char *)&v114 + 4);
              DWORD1(v114) = clientGame->random.seed;
              clientGame->random.seed = v116;
              DWORD2(v114) = (v116 >> 10) & 0x7FFF;
              *(_QWORD *)&v195.x = *(_QWORD *)((char *)&v114 + 4);
              HIDWORD(v114) = 1664525 * clientGame->random.seed;
              clientGame->random.seed = HIDWORD(v114) + 1013904223;
              LODWORD(v114) = ((unsigned int)(HIDWORD(v114) + 1013904223) >> 10) & 0x7FFF;
              *(_QWORD *)&v195.x = v114;
              v197.z = (float)((float)((float)v117 * (float)0.000030518509) * (float)4.0) - (float)2.0;
              v197.y = (float)((float)((float)*(__int64 *)((char *)&v114 + 4) * (float)0.000030518509) * (float)4.0)
                     - (float)2.0;
              v197.x = (float)((float)(__int64)v114 * (float)0.00012207404) - (float)2.0;
              idVec3::ProjectOntoPlane(this: &v197, normal: (const idVec3 *)(a8 + 68), overBounce: 1.0);
              v118 = (float)(*(float *)(a8 + 60) + v197.y);
              v119 = (float)(*(float *)(a8 + 64) + v197.z);
              v200.x = v197.x + *(float *)(a8 + 56);
              v200.y = v118;
              v200.z = v119;
              if ( idVehicle_Car::GetEffectsDef(this)->particleShotDamage != nullptr )
              {
                v121 = 1664525 * clientGame->random.seed + 1013904223;
                clientGame->random.seed = v121;
                LODWORD(v120) = (v121 >> 10) & 0x7FFF;
                *(_QWORD *)&v195.x = v120;
                if ( (float)((float)v120 * (float)0.000030518509) >= 0.75 )
                {
                  idVec3::ToZAxis(this: v201[0].mat, result: (idMat3 *)(a8 + 68));
                  v122 = 0;
                  if ( idVehicle::GetDriver(this) != nullptr )
                  {
                    Driver = idVehicle::GetDriver(this);
                    if ( (unsigned __int8)idPlayer::IsTypeOf(c: Driver) != 0 )
                    {
                      v124 = (idPlayer *)idVehicle::GetDriver(this);
                      if ( idPlayer::CastTo(c: v124) != nullptr )
                        v122 = -1;
                    }
                  }
                  v125 = this->presentable;
                  if ( v125 == nullptr )
                  {
                    idEntity::InitPresentableInternal(this);
                    v125 = this->presentable;
                  }
                  v126 = v125;
                  if ( v125 != nullptr )
                  {
                    v127 = v125;
                  }
                  else
                  {
                    idEntity::InitPresentableInternal(this);
                    v127 = this->presentable;
                  }
                  v128 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                  particleShotDamage = (const idMaterial *)idVehicle_Car::GetEffectsDef(this)->particleShotDamage;
                  ImpactMgr = (idImpactManager *)idVehicle_Car::GetImpactMgr(this);
                  idImpactManager::UseImpact(
                    this: ImpactMgr,
                    org: &v200,
                    axis: v201,
                    prt: particleShotDamage,
                    startTime: v128,
                    bindToParent: true,
                    parentOrg: &v127->origin,
                    parentAxis: &v126->axis,
                    distSqr: 0.0,
                    playerIndex: v172,
                    color: v173,
                    numCycles: v174,
                    a13: v175,
                    a14: SHIDWORD(v176),
                    a15: SLODWORD(v176),
                    a16: SHIDWORD(v177),
                    a17: SLODWORD(v177),
                    a18: v178,
                    a19: v179,
                    a20: v180,
                    a21: v181,
                    a22: v182,
                    a23: v183,
                    a24: v184,
                    a25: v185,
                    a26: v186,
                    a27: v187,
                    a28: v188,
                    a29: v122,
                    a30: v190,
                    a31: v191,
                    a32: v192,
                    a33: &idColor::colorWhite.r,
                    a34: (int)v193,
                    a35: 1);
                }
              }
            }
            v131 = this->presentable;
            if ( v131 != nullptr )
              v132 = (int)v131->GetVehicleInterface(this: v131);
            else
              v132 = 0;
            v133 = (int *)(v132 + 16488);
            if ( a8 != 0 )
            {
              v134 = *(_DWORD *)(v132 + 16492);
              v135 = -1;
              v136 = 0;
              v137 = 1.0e30;
              if ( v134 >= 4 )
              {
                v138 = *v133;
                v139 = 0;
                do
                {
                  v140 = (_DWORD *)(v138 + v139);
                  v141 = *(float **)(v138 + v139 + 4);
                  v142 = (float)(v141[142] - *(float *)(a8 + 60));
                  v143 = (float)(v141[143] - *(float *)(a8 + 64));
                  v144 = (float)(v141[141] - *(float *)(a8 + 56));
                  if ( (float)((float)((float)v144 * (float)v144)
                             + (float)((float)((float)v143 * (float)v143) + (float)((float)v142 * (float)v142))) < v137 )
                  {
                    v137 = (float)((float)((float)v144 * (float)v144)
                                 + (float)((float)((float)v143 * (float)v143) + (float)((float)v142 * (float)v142)));
                    v135 = v136;
                  }
                  v145 = (float *)v140[4];
                  v146 = (float)(v145[142] - *(float *)(a8 + 60));
                  v147 = (float)(v145[143] - *(float *)(a8 + 64));
                  v148 = (float)(v145[141] - *(float *)(a8 + 56));
                  if ( (float)((float)((float)v148 * (float)v148)
                             + (float)((float)((float)v147 * (float)v147) + (float)((float)v146 * (float)v146))) < v137 )
                  {
                    v137 = (float)((float)((float)v148 * (float)v148)
                                 + (float)((float)((float)v147 * (float)v147) + (float)((float)v146 * (float)v146)));
                    v135 = v136 + 1;
                  }
                  v149 = (float *)v140[7];
                  v150 = (float)(v149[142] - *(float *)(a8 + 60));
                  v151 = (float)(v149[143] - *(float *)(a8 + 64));
                  v152 = (float)(v149[141] - *(float *)(a8 + 56));
                  if ( (float)((float)((float)v152 * (float)v152)
                             + (float)((float)((float)v151 * (float)v151) + (float)((float)v150 * (float)v150))) < v137 )
                  {
                    v137 = (float)((float)((float)v152 * (float)v152)
                                 + (float)((float)((float)v151 * (float)v151) + (float)((float)v150 * (float)v150)));
                    v135 = v136 + 2;
                  }
                  v153 = (float *)v140[10];
                  v154 = (float)(v153[142] - *(float *)(a8 + 60));
                  v155 = (float)(v153[143] - *(float *)(a8 + 64));
                  v156 = (float)(v153[141] - *(float *)(a8 + 56));
                  if ( (float)((float)((float)v156 * (float)v156)
                             + (float)((float)((float)v155 * (float)v155) + (float)((float)v154 * (float)v154))) < v137 )
                  {
                    v137 = (float)((float)((float)v156 * (float)v156)
                                 + (float)((float)((float)v155 * (float)v155) + (float)((float)v154 * (float)v154)));
                    v135 = v136 + 3;
                  }
                  v136 += 4;
                  v139 += 48;
                }
                while ( v136 < v134 - 3 );
              }
              if ( v136 < v134 )
              {
                v157 = 12 * v136;
                v158 = v134 - v136;
                do
                {
                  v159 = *(float **)(*v133 + v157 + 4);
                  v160 = (float)(v159[142] - *(float *)(a8 + 60));
                  v161 = (float)(v159[143] - *(float *)(a8 + 64));
                  v162 = (float)(v159[141] - *(float *)(a8 + 56));
                  if ( (float)((float)((float)v162 * (float)v162)
                             + (float)((float)((float)v161 * (float)v161) + (float)((float)v160 * (float)v160))) < v137 )
                  {
                    v137 = (float)((float)((float)v162 * (float)v162)
                                 + (float)((float)((float)v161 * (float)v161) + (float)((float)v160 * (float)v160)));
                    v135 = v136;
                  }
                  ++v136;
                  v157 += 12;
                  --v158;
                }
                while ( v158 != 0 );
              }
              damage = this->lastDamage.damage;
              if ( v135 < 2 )
              {
                damage = (float)(this->lastDamage.damage * (float)0.75);
                v135 += 2;
              }
              *(float *)(12 * v135 + *v133 + 8) = (float)damage + *(float *)(12 * v135 + *v133 + 8);
            }
            if ( idVehicle_Car::ShowTireWobble(this) )
            {
              v164 = 0;
              if ( v133[1] > 0 )
              {
                v165 = 0;
                do
                {
                  v166 = (float)(*(float *)(*v133 + v165 + 8) / this->maxArmoredHealth);
                  if ( v166 >= 0.0 )
                  {
                    if ( v166 > 1.0 )
                      v166 = 1.0;
                  }
                  else
                  {
                    v166 = 0.0;
                  }
                  idAnimator_VehicleCar::SetTireWobble(
                    this: &this->vehicleAnimator,
                    wheelIndex: v164++,
                    wobbleFrac_: v166);
                  v165 += 12;
                }
                while ( v164 < v133[1] );
              }
            }
            v167 = vehicle_showDamageValues.valueInteger;
            if ( vehicle_showDamageValues.valueInteger == 1 )
            {
              if ( idVehicle::PlayerIsOccupant(this) != nullptr )
                goto LABEL_183;
              v167 = vehicle_showDamageValues.valueInteger;
            }
            if ( v167 != 2 )
            {
LABEL_186:
              if ( common->IsMultiplayer(this: common) )
              {
                v168 = session->GetActingGameStateLobbyBase(this: session);
                if ( v168->GetMatchParms(this: v168)->gameType == 2 )
                {
                  v169 = this->presentable;
                  if ( v169 != nullptr )
                    v170 = (int)v169->GetVehicleInterface(this: v169);
                  else
                    v170 = 0;
                  if ( *(float *)(v170 + 17948) != 1.0 )
                    idRageMetrics::AddDuraBumpSP(this: clientGame->rageMetrics, car: this, damage: v58);
                }
              }
              goto LABEL_193;
            }
LABEL_183:
            if ( inflictor != nullptr || attacker != nullptr )
              idLib::Printf(fmt: "\n=====================================================\n");
            goto LABEL_186;
          }
          v56 = vehicle_showDamageValues.valueInteger;
        }
        if ( v56 != 2 )
          goto LABEL_83;
        goto LABEL_79;
      }
      v20 = vehicle_showDamageValues.valueInteger;
    }
    if ( v20 != 2 )
      goto LABEL_23;
    goto LABEL_20;
  }
LABEL_3:
  v16 = 0.0;
  return *((float *)&v16 + 1);
}


// ========================================================================
// ?HandleCollisionServerOnly@idVehicle_Car@@QAA_NPAVidEntity@@HAAUtrace_t@@ABVidVec3@@@Z
// EA  : 0x82D44250
// RVA : 0x00D44250
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

int __fastcall idVehicle_Car::HandleCollisionServerOnly(
        idVehicle_Car *this,
        idVehicle_Car *otherEnt,
        const int physId,
        trace_t *collision,
        const idVec3 *velocity)
{
  idPresentable *presentable; // r3
  int v9; // r3
  double v10; // fp26
  double v11; // fp0
  double v12; // fp28
  idLobbyBase *v13; // r3
  idCVar *v14; // r10
  double valueFloat; // fp27
  idPhysics *Physics; // r3
  double x; // fp8
  double z; // fp7
  double y; // fp5
  double v20; // fp21
  double v23; // fp1
  double v24; // fp1
  double v25; // fp9
  double v26; // fp13
  double v27; // fp12
  double v28; // fp30
  double v29; // fp27
  idPlayer *v30; // r24
  long double v31; // fp2
  int valueInteger; // r11
  idVehicle_Car *v33; // r26
  idLobbyBase *v34; // r3
  int v35; // r27
  int v36; // r28
  int value; // r9
  idVehicle_Car *v38; // r3
  idVehicle_Car *v39; // r3
  idVehicle_Car::vehicleHitData_t *v40; // r29
  int v41; // r11
  idPhysics *v42; // r29
  idPhysics *v43; // r28
  double v44; // fp30
  unsigned __int8 ApproxSpeed; // r3
  double v46; // fp30
  double v47; // fp28
  idPhysics *v48; // r3
  double v51; // fp4
  double v52; // fp8
  double v53; // fp6
  double v54; // fp5
  idPhysics *v55; // r3
  __int64 v56; // r10
  idPresentable *v57; // r3
  double v60; // fp5
  double v61; // fp9
  double v62; // fp7
  double v63; // fp6
  int v64; // r3
  idPresentable *v65; // r3
  double v66; // fp30
  int v67; // r3
  double v68; // fp29
  idPhysics *v69; // r3
  double v70; // fp27
  idPhysics *v71; // r3
  double v72; // fp1
  double v73; // fp7
  double v74; // fp5
  double v75; // fp9
  double v76; // fp8
  double v77; // fp6
  double v78; // fp13
  double v79; // fp2
  double v82; // fp4
  double v83; // fp6
  double v84; // fp4
  double v85; // fp8
  double v86; // fp6
  double v87; // fp0
  double v88; // fp9
  double v89; // fp26
  double v90; // fp27
  double v91; // fp12
  double v92; // fp2
  double v93; // fp28
  int v94; // r11
  double v95; // fp30
  double v96; // fp29
  double v97; // fp25
  double v98; // fp23
  const idDeclDamage *vehicle; // r11
  const char *data; // r4
  idVehicle_Car_vtbl *v101; // r28
  const idDeclDamage *v102; // r25
  idEntity *Driver; // r3
  double v104; // fp1
  idVehicle_Car_vtbl *v105; // r28
  double v106; // fp29
  const idDeclDamage *v107; // r25
  idEntity *v108; // r3
  double v109; // fp1
  idPresentable *v110; // r3
  double v111; // fp28
  int v112; // r3
  idPhysics *v113; // r29
  idPhysics *v114; // r28
  float *v115; // r29
  float *v116; // r3
  double v117; // fp9
  double v118; // fp0
  double v119; // fp6
  double v121; // fp11
  double v123; // fp9
  double v124; // fp13
  double v125; // fp11
  double v126; // fp30
  double v127; // fp29
  double v128; // fp28
  idPhysics *v129; // r3
  idPresentable *v130; // r3
  double v133; // fp1
  double v134; // fp10
  double v135; // fp9
  double v136; // fp27
  double v137; // fp26
  double v138; // fp25
  int v139; // r3
  int v140; // r9
  idEntity *v141; // r3
  idEntity *v142; // r3
  _DWORD *LastCollision; // r29
  idPresentable *v144; // r3
  float *v145; // r3
  double v146; // fp12
  double v147; // fp10
  double v148; // fp8
  double v149; // fp0
  double v150; // fp11
  double v152; // fp9
  double v154; // fp7
  double v155; // fp11
  double v156; // fp4
  double v157; // fp30
  double v158; // fp0
  double v159; // fp29
  idPlayer *v160; // r3
  idPlayer *v161; // r29
  idVehicleAI *v162; // r3
  idVehicleAI *v163; // r3
  idLobbyBase *v164; // r3
  idCVar *v165; // r10
  idPresentable *v166; // r3
  int v167; // r3
  double v168; // fp30
  idLobbyBase *v169; // r3
  gameTeam_t Team; // r27
  idInventoryItem *BestArmorForDamage; // r3
  __int64 v172; // r7
  int (__fastcall *GetGameMs)(struct idGameLocal *, const gameTimeType_t); // ctr
  int v174; // r29
  __int64 v175; // r11
  idVehicle_Car_vtbl *v176; // r28
  const idDeclDamage *v177; // r27
  idEntity *v178; // r3
  double v179; // fp1
  idVehicle_Car_vtbl *v180; // r28
  const idDeclDamage *v181; // r27
  idEntity *v182; // r3
  double v183; // fp0
  idPhysics *v184; // r3
  float *v185; // r3
  const idDeclDamage *runOver; // r28
  double v189; // fp4
  double v190; // fp10
  double v191; // fp7
  double v192; // fp30
  idEntity_vtbl *v193; // r29
  idEntity *v194; // r3
  idAI2 *v195; // r29
  idPhysics *v196; // r28
  idPhysics *v197; // r27
  double v198; // fp30
  float *v199; // r3
  double v200; // fp11
  double v201; // fp13
  double v202; // fp8
  double v203; // fp5
  double v205; // fp3
  double v207; // fp1
  double v208; // fp13
  unsigned int v209; // r4
  idPhysics *v210; // r3
  float *v211; // r3
  double v212; // fp10
  double v213; // fp13
  double v214; // fp9
  double v215; // fp6
  idPhysics *v216; // r3
  idPhysics *v217; // r3
  double v218; // fp1
  double v219; // fp12
  double v220; // fp11
  void (__fastcall *ApplyImpulseFromEntity)(idEntity *, const idEntity *, const int, const idVec3 *, const idVec3 *); // r11
  const idDeclDamage *v222; // r28
  idEntity_vtbl *v223; // r27
  idEntity *v224; // r5
  idPhysics *v225; // r3
  float *v226; // r3
  long double v227; // fp2
  double v228; // fp30
  long double v229; // fp2
  int ViolentRollStartTime; // r29
  int ViolentRollStopTime; // r3
  int v232; // r11
  double v233; // fp1
  idEntity_vtbl *v234; // r28
  const idDeclDamage *v235; // r27
  idEntity *v236; // r5
  idDamageableEntity *v237; // r22
  idBreakable *v238; // r29
  int v239; // r3
  double v240; // fp1
  idDamageableEntity_vtbl *v241; // r28
  const idDeclDamage *v242; // r27
  double v243; // fp31
  idEntity *v244; // r3
  idBreakable_vtbl *v246; // r27
  const idDeclDamage *v247; // r26
  idEntity *v248; // r3
  const idDeclDamage *v249; // r29
  idVehicle_Car_vtbl *v250; // r28
  idEntity *v251; // r3
  double v252; // fp1
  idVehicle_Car_vtbl *v253; // r27
  idEntity *v254; // r3
  idPhysics *v255; // r29
  idPhysics *v256; // r28
  double v257; // fp30
  float *v258; // r3
  double v259; // fp0
  double v260; // fp13
  double v261; // fp12
  void (__fastcall *v262)(idEntity *, const idEntity *, const int, const idVec3 *, const idVec3 *); // ctr
  double v263; // fp9
  double v265; // fp7
  double v267; // fp5
  double v268; // fp1
  double v269; // fp13
  void (__fastcall *v270)(idEntity *, const idEntity *, const int, const idVec3 *, const idVec3 *); // r8
  idPhysics *v271; // r3
  int v272; // r3
  int *v273; // r10
  _DWORD *v274; // r11
  int i; // ctr
  int EntitiesTouchingBounds; // r3
  int *v277; // r24
  int j; // r23
  idAI2 *v279; // r29
  const idDeclDamage *v280; // r26
  idAI2_vtbl *v281; // r27
  idEntity *v282; // r3
  idPhysics *v283; // r28
  idPhysics *v284; // r27
  double v285; // fp28
  float *v286; // r3
  double v287; // fp12
  double v288; // fp13
  double v289; // fp9
  double v290; // fp6
  double v292; // fp4
  double v294; // fp2
  double v295; // fp13
  idDamageableEntity_vtbl *v296; // r28
  const idDeclDamage *v297; // r27
  idEntity *v298; // r5
  int v299; // r11
  idPresentable *v300; // r3
  int v301; // r3
  idEntity *v302; // r3
  int v303; // r11
  char v304; // r11
  bool v305; // zf
  idPhysics *v306; // r3
  idPresentable *v307; // r11
  idPhysics *v308; // r28
  float *v309; // r29
  float *v310; // r3
  double v311; // fp13
  double v312; // fp12
  double v313; // fp11
  double v314; // fp9
  double v315; // fp7
  double v316; // fp5
  double v318; // fp13
  double v320; // fp11
  double v321; // fp1
  double v322; // fp13
  double v323; // fp31
  double v324; // fp30
  double v325; // fp29
  idPhysics *v326; // r3
  float *v327; // r3
  int (*v328)(void); // ctr
  int v329; // r11
  double v330; // [sp+18h] [-238h]
  double v331; // [sp+18h] [-238h]
  double v332; // [sp+20h] [-230h]
  __int64 v333; // [sp+50h] [-200h] BYREF
  float v334; // [sp+58h] [-1F8h]
  idVehicle_Car::vehicleHitData_t v335; // [sp+60h] [-1F0h] BYREF
  float v336; // [sp+68h] [-1E8h]
  float v337; // [sp+70h] [-1E0h] BYREF
  float v338; // [sp+74h] [-1DCh]
  float v339; // [sp+78h] [-1D8h]
  float v340; // [sp+80h] [-1D0h] BYREF
  float v341; // [sp+84h] [-1CCh]
  float v342; // [sp+88h] [-1C8h]
  float v343; // [sp+90h] [-1C0h] BYREF
  float v344; // [sp+94h] [-1BCh]
  float v345; // [sp+98h] [-1B8h]
  idVec3 v346; // [sp+A0h] [-1B0h] BYREF
  idVec3 v347; // [sp+B0h] [-1A0h] BYREF
  int v348; // [sp+BCh] [-194h] BYREF
  idBounds v349; // [sp+C0h] [-190h] BYREF
  float v350[4]; // [sp+D8h] [-178h] BYREF
  float v351[4]; // [sp+E8h] [-168h] BYREF
  idVec3 v352; // [sp+F8h] [-158h] BYREF
  idList<enum encounterGroupRole_t,5> v353; // [sp+110h] [-140h] BYREF
  int v354[13]; // [sp+120h] [-130h] BYREF
  idVehicle_Car::vehicleHitData_t v355; // [sp+154h] [-FCh]
  float v356; // [sp+15Ch] [-F4h]

  idVehicle_Car::ExtraCollisionReactions(this, otherEntity: otherEnt, collision);
  if ( this->specialDeathActive
    && this->specialDeath == DEATH_IMPULSE_1
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
     - this->specialDeathStartTime > vehicle_special_death_minMS.valueInteger )
  {
    this->specialDeathCollision = true;
  }
  presentable = this->presentable;
  if ( presentable != nullptr )
    v9 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v9 = 0;
  v10 = *(float *)(v9 + 17864);
  v11 = (float)(*(float *)(v9 + 17864) * (float)0.0125);
  v12 = (float)((float)v11 * (float)v11);
  if ( common->IsMultiplayer(this: common)
    && (v13 = session->GetActingGameStateLobbyBase(this: session), v13->GetMatchParms(this: v13)->gameType == 2) )
  {
    v14 = &vehicle_online_damageScale_base;
  }
  else
  {
    v14 = &vehicle_damageScale_base;
  }
  valueFloat = v14->valueFloat;
  Physics = idEntity::GetPhysics(this);
  Physics->GetLinearVelocity(this: (idPhysics *)&v337, result: (idVec3 *)Physics, a3: 0);
  x = collision->c.normal.x;
  z = collision->c.normal.z;
  y = collision->c.normal.y;
  v20 = 0.0;
  _FP4 = (float)((float)((float)(v337 * v337) + (float)((float)(v339 * v339) + (float)(v338 * v338)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f4, f6, f13 }
  v23 = __frsqrte(_FP2);
  v24 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23
                                                                                      * (float)((float)((float)(v337 * v337) + (float)((float)(v339 * v339) + (float)(v338 * v338)))
                                                                                              * (float)0.5))
                                                                              * (float)v23)
                                                                      - (float)1.5)
                                                      * (float)v23)
                                              * (float)((float)((float)(v337 * v337)
                                                              + (float)((float)(v339 * v339) + (float)(v338 * v338)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v23
                                                                              * (float)((float)((float)(v337 * v337)
                                                                                              + (float)((float)(v339 * v339) + (float)(v338 * v338)))
                                                                                      * (float)0.5))
                                                                      * (float)v23)
                                                              - (float)1.5)
                                              * (float)v23))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v23
                                                      * (float)((float)((float)(v337 * v337)
                                                                      + (float)((float)(v339 * v339)
                                                                              + (float)(v338 * v338)))
                                                              * (float)0.5))
                                              * (float)v23)
                                      - (float)1.5)
                      * (float)v23));
  v25 = (float)((float)-(float)((float)((float)((float)v24
                                              * (float)((float)((float)(v337 * v337)
                                                              + (float)((float)(v339 * v339) + (float)(v338 * v338)))
                                                      * (float)0.5))
                                      * (float)v24)
                              - (float)1.5)
              * (float)v24);
  v26 = (float)(v337
              * (float)((float)-(float)((float)((float)((float)v24
                                                      * (float)((float)((float)(v337 * v337)
                                                                      + (float)((float)(v339 * v339)
                                                                              + (float)(v338 * v338)))
                                                              * (float)0.5))
                                              * (float)v24)
                                      - (float)1.5)
                      * (float)v24));
  v27 = (float)((float)((float)-(float)((float)((float)((float)v24
                                                      * (float)((float)((float)(v337 * v337)
                                                                      + (float)((float)(v339 * v339)
                                                                              + (float)(v338 * v338)))
                                                              * (float)0.5))
                                              * (float)v24)
                                      - (float)1.5)
                      * (float)v24)
              * v339);
  v337 = v337
       * (float)((float)-(float)((float)((float)((float)v24
                                               * (float)((float)((float)(v337 * v337)
                                                               + (float)((float)(v339 * v339) + (float)(v338 * v338)))
                                                       * (float)0.5))
                                       * (float)v24)
                               - (float)1.5)
               * (float)v24);
  v339 = v27;
  v338 = (float)v25 * v338;
  v28 = __fabs((float)((float)(v338 * (float)y)
                     + (float)((float)((float)v27 * (float)z) + (float)((float)v26 * (float)x))));
  v29 = (float)((float)((float)((float)v28 * (float)v28) * (float)valueFloat) * (float)v12);
  v30 = idVehicle::PlayerIsOccupant(this);
  valueInteger = vehicle_showDamageValues.valueInteger;
  if ( vehicle_showDamageValues.valueInteger != 1 )
  {
LABEL_15:
    if ( valueInteger != 2 )
      goto LABEL_17;
    goto LABEL_16;
  }
  if ( idVehicle::PlayerIsOccupant(this) == nullptr )
  {
    valueInteger = vehicle_showDamageValues.valueInteger;
    goto LABEL_15;
  }
LABEL_16:
  *(double *)&v31 = v28;
  v332 = (float)((float)90.0 - (float)(idMath::ACos(a: v31) * idMath::M_RAD2DEG));
  idLib::Printf(
    fmt: "DAMAGE: %f     [ impact angle: %f    impact scale: %f    mph: %f    mph scale: %f ]\n",
    v29,
    v332,
    (float)((float)v28 * (float)v28),
    v10,
    v12);
LABEL_17:
  if ( (unsigned __int8)idVehicle_Car::IsTypeOf(c: otherEnt) != 0 )
  {
    v33 = idVehicle_Car::CastTo(c: otherEnt);
    if ( common->IsMultiplayer(this: common)
      && (v34 = session->GetActingGameStateLobbyBase(this: session), v34->GetMatchParms(this: v34)->gameType == 2) )
    {
      v35 = 0;
      if ( this->hitList.num > 0 )
      {
        v36 = 0;
        do
        {
          value = this->hitList.list[v36].otherCar.spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
            && (v38 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v39 = idVehicle_Car::CastTo(c: v38);
          }
          else
          {
            v39 = nullptr;
          }
          if ( v39 == v33 )
          {
            v40 = &this->hitList.list[v36];
            if ( v40->nextCollisionTime > idGameTimeManager::GetGameMs(
                                            this: &clientGame->gameTimeManager,
                                            type: GAMETIME_SCALED) )
              return 1;
          }
          ++v35;
          ++v36;
        }
        while ( v35 < this->hitList.num );
      }
      v41 = vehicle_DMG.valueInteger;
      if ( vehicle_DMG.valueInteger != 0 )
      {
        if ( v30 != nullptr )
        {
          idLib::Printf(fmt: "====START====\n");
          idLib::Printf(fmt: "player:\t%s\n", v30->name.data);
          v41 = vehicle_DMG.valueInteger;
        }
        if ( v41 != 0 && v30 != nullptr )
        {
          idLib::Printf(fmt: "Inputs:\n");
          v42 = idEntity::GetPhysics(this: v33);
          v43 = idEntity::GetPhysics(this);
          v44 = ((double (__fastcall *)(idPhysics *, int))v42->GetMass)(a1: v42, a2: -1);
          v330 = ((double (__fastcall *)(idPhysics *, int))v43->GetMass)(a1: v43, a2: -1);
          idLib::Printf(fmt: (const char *)HIDWORD(v330), HIDWORD(v44), LODWORD(v44), v330, v44);
          LOBYTE(v42) = idVehicle_Car::GetApproxSpeed(this: v33);
          ApproxSpeed = idVehicle_Car::GetApproxSpeed(this);
          idLib::Printf(fmt: "Speed: %d \tOther Speed: %d\n", ApproxSpeed, (unsigned __int8)v42);
          v46 = ((double (__fastcall *)(idVehicle_Car *))v33->GetMaxSpeed)(a1: v33);
          v331 = ((double (__fastcall *)(idVehicle_Car *))this->GetMaxSpeed)(a1: this);
          idLib::Printf(fmt: "MaxSpeed: %f \tOther MaxSpeed: %f\n", v331, v46);
          idLib::Printf(fmt: "Health: %f \tOther Health: %f\n", this->lastThinkHealth, v33->lastThinkHealth);
        }
      }
      v47 = (float)(vehicle_online_mph_dmg_upperBound.valueFloat - vehicle_online_mph_dmg_lowerBound.valueFloat);
      v48 = idEntity::GetPhysics(this);
      v48->GetLinearVelocity(this: (idPhysics *)&v340, result: (idVec3 *)v48, a3: 0);
      _FP7 = (float)((float)((float)(v340 * v340) + (float)((float)(v342 * v342) + (float)(v341 * v341)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f5, f7, f8, f13 }
      v51 = __frsqrte(_FP5);
      v52 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v51
                                                                                          * (float)((float)((float)(v340 * v340) + (float)((float)(v342 * v342) + (float)(v341 * v341)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v51)
                                                                          - (float)1.5)
                                                          * (float)v51)
                                                  * (float)((float)((float)(v340 * v340)
                                                                  + (float)((float)(v342 * v342) + (float)(v341 * v341)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v51
                                                                                  * (float)((float)((float)(v340 * v340)
                                                                                                  + (float)((float)(v342 * v342) + (float)(v341 * v341)))
                                                                                          * (float)0.5))
                                                                          * (float)v51)
                                                                  - (float)1.5)
                                                  * (float)v51))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v51
                                                          * (float)((float)((float)(v340 * v340)
                                                                          + (float)((float)(v342 * v342)
                                                                                  + (float)(v341 * v341)))
                                                                  * (float)0.5))
                                                  * (float)v51)
                                          - (float)1.5)
                          * (float)v51));
      v53 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v51 * (float)((float)((float)(v340 * v340) + (float)((float)(v342 * v342) + (float)(v341 * v341))) * (float)0.5)) * (float)v51) - (float)1.5)
                                                                                          * (float)v51)
                                                                                  * (float)((float)((float)(v340 * v340)
                                                                                                  + (float)((float)(v342 * v342) + (float)(v341 * v341)))
                                                                                          * (float)0.5))
                                                                          * (float)((float)-(float)((float)((float)((float)v51 * (float)((float)((float)(v340 * v340) + (float)((float)(v342 * v342) + (float)(v341 * v341))) * (float)0.5)) * (float)v51)
                                                                                                  - (float)1.5)
                                                                                  * (float)v51))
                                                                  - (float)1.5)
                                                  * (float)((float)-(float)((float)((float)((float)v51
                                                                                          * (float)((float)((float)(v340 * v340) + (float)((float)(v342 * v342) + (float)(v341 * v341)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v51)
                                                                          - (float)1.5)
                                                          * (float)v51))
                                          * (float)((float)((float)(v340 * v340)
                                                          + (float)((float)(v342 * v342) + (float)(v341 * v341)))
                                                  * (float)0.5))
                                  * (float)v52)
                          - (float)1.5);
      v54 = (float)((float)v53
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v51
                                                                                                  * (float)((float)((float)(v340 * v340) + (float)((float)(v342 * v342) + (float)(v341 * v341))) * (float)0.5))
                                                                                          * (float)v51)
                                                                                  - (float)1.5)
                                                                  * (float)v51)
                                                          * (float)((float)((float)(v340 * v340)
                                                                          + (float)((float)(v342 * v342)
                                                                                  + (float)(v341 * v341)))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v51
                                                                                          * (float)((float)((float)(v340 * v340) + (float)((float)(v342 * v342) + (float)(v341 * v341)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v51)
                                                                          - (float)1.5)
                                                          * (float)v51))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v51
                                                                  * (float)((float)((float)(v340 * v340)
                                                                                  + (float)((float)(v342 * v342)
                                                                                          + (float)(v341 * v341)))
                                                                          * (float)0.5))
                                                          * (float)v51)
                                                  - (float)1.5)
                                  * (float)v51)));
      v340 = v340
           * (float)((float)v53
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v51 * (float)((float)((float)(v340 * v340) + (float)((float)(v342 * v342) + (float)(v341 * v341))) * (float)0.5))
                                                                                           * (float)v51)
                                                                                   - (float)1.5)
                                                                   * (float)v51)
                                                           * (float)((float)((float)(v340 * v340)
                                                                           + (float)((float)(v342 * v342)
                                                                                   + (float)(v341 * v341)))
                                                                   * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)((float)v51
                                                                                           * (float)((float)((float)(v340 * v340) + (float)((float)(v342 * v342) + (float)(v341 * v341))) * (float)0.5))
                                                                                   * (float)v51)
                                                                           - (float)1.5)
                                                           * (float)v51))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)((float)v51
                                                                   * (float)((float)((float)(v340 * v340)
                                                                                   + (float)((float)(v342 * v342)
                                                                                           + (float)(v341 * v341)))
                                                                           * (float)0.5))
                                                           * (float)v51)
                                                   - (float)1.5)
                                   * (float)v51)));
      v341 = v341 * (float)v54;
      v342 = v342 * (float)v54;
      v55 = idEntity::GetPhysics(this: v33);
      ((void (__fastcall *)(float *))v55->GetLinearVelocity)(a1: &v343);
      v57 = this->presentable;
      _FP8 = (float)((float)((float)(v343 * v343) + (float)((float)(v345 * v345) + (float)(v344 * v344)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f6, f8, f9, f13 }
      v60 = __frsqrte(_FP6);
      v61 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60
                                                                                          * (float)((float)((float)(v343 * v343) + (float)((float)(v345 * v345) + (float)(v344 * v344)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v60)
                                                                          - (float)1.5)
                                                          * (float)v60)
                                                  * (float)((float)((float)(v343 * v343)
                                                                  + (float)((float)(v345 * v345) + (float)(v344 * v344)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v60
                                                                                  * (float)((float)((float)(v343 * v343)
                                                                                                  + (float)((float)(v345 * v345) + (float)(v344 * v344)))
                                                                                          * (float)0.5))
                                                                          * (float)v60)
                                                                  - (float)1.5)
                                                  * (float)v60))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v60
                                                          * (float)((float)((float)(v343 * v343)
                                                                          + (float)((float)(v345 * v345)
                                                                                  + (float)(v344 * v344)))
                                                                  * (float)0.5))
                                                  * (float)v60)
                                          - (float)1.5)
                          * (float)v60));
      v62 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)(v343 * v343) + (float)((float)(v345 * v345) + (float)(v344 * v344))) * (float)0.5)) * (float)v60) - (float)1.5)
                                                                                          * (float)v60)
                                                                                  * (float)((float)((float)(v343 * v343)
                                                                                                  + (float)((float)(v345 * v345) + (float)(v344 * v344)))
                                                                                          * (float)0.5))
                                                                          * (float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)(v343 * v343) + (float)((float)(v345 * v345) + (float)(v344 * v344))) * (float)0.5)) * (float)v60)
                                                                                                  - (float)1.5)
                                                                                  * (float)v60))
                                                                  - (float)1.5)
                                                  * (float)((float)-(float)((float)((float)((float)v60
                                                                                          * (float)((float)((float)(v343 * v343) + (float)((float)(v345 * v345) + (float)(v344 * v344)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v60)
                                                                          - (float)1.5)
                                                          * (float)v60))
                                          * (float)((float)((float)(v343 * v343)
                                                          + (float)((float)(v345 * v345) + (float)(v344 * v344)))
                                                  * (float)0.5))
                                  * (float)v61)
                          - (float)1.5);
      v63 = (float)((float)v62
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60
                                                                                                  * (float)((float)((float)(v343 * v343) + (float)((float)(v345 * v345) + (float)(v344 * v344))) * (float)0.5))
                                                                                          * (float)v60)
                                                                                  - (float)1.5)
                                                                  * (float)v60)
                                                          * (float)((float)((float)(v343 * v343)
                                                                          + (float)((float)(v345 * v345)
                                                                                  + (float)(v344 * v344)))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v60
                                                                                          * (float)((float)((float)(v343 * v343) + (float)((float)(v345 * v345) + (float)(v344 * v344)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v60)
                                                                          - (float)1.5)
                                                          * (float)v60))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v60
                                                                  * (float)((float)((float)(v343 * v343)
                                                                                  + (float)((float)(v345 * v345)
                                                                                          + (float)(v344 * v344)))
                                                                          * (float)0.5))
                                                          * (float)v60)
                                                  - (float)1.5)
                                  * (float)v60)));
      v343 = v343
           * (float)((float)v62
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)(v343 * v343) + (float)((float)(v345 * v345) + (float)(v344 * v344))) * (float)0.5))
                                                                                           * (float)v60)
                                                                                   - (float)1.5)
                                                                   * (float)v60)
                                                           * (float)((float)((float)(v343 * v343)
                                                                           + (float)((float)(v345 * v345)
                                                                                   + (float)(v344 * v344)))
                                                                   * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)((float)v60
                                                                                           * (float)((float)((float)(v343 * v343) + (float)((float)(v345 * v345) + (float)(v344 * v344))) * (float)0.5))
                                                                                   * (float)v60)
                                                                           - (float)1.5)
                                                           * (float)v60))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)((float)v60
                                                                   * (float)((float)((float)(v343 * v343)
                                                                                   + (float)((float)(v345 * v345)
                                                                                           + (float)(v344 * v344)))
                                                                           * (float)0.5))
                                                           * (float)v60)
                                                   - (float)1.5)
                                   * (float)v60)));
      v344 = v344 * (float)v63;
      v345 = v345 * (float)v63;
      if ( v57 != nullptr )
        v64 = (int)v57->GetVehicleInterface(this: v57);
      else
        v64 = 0;
      LODWORD(v56) = *(unsigned __int8 *)(v64 + 20512);
      v65 = v33->presentable;
      v333 = v56;
      v66 = (float)v56;
      if ( v65 != nullptr )
        v67 = (int)v65->GetVehicleInterface(this: v65);
      else
        v67 = 0;
      LODWORD(v56) = *(unsigned __int8 *)(v67 + 20512);
      v333 = v56;
      v68 = (float)v56;
      v69 = idEntity::GetPhysics(this);
      v70 = ((double (__fastcall *)(idPhysics *, int))v69->GetMass)(a1: v69, a2: -1);
      v71 = idEntity::GetPhysics(this: v33);
      v72 = ((double (__fastcall *)(idPhysics *, int))v71->GetMass)(a1: v71, a2: -1);
      v73 = (float)((float)v72 + (float)v70);
      if ( v73 <= 0.0 )
        v74 = 0.0;
      else
        v74 = (float)((float)v70 / (float)((float)v72 + (float)v70));
      v75 = (float)((float)(v341 * (float)v66) - (float)(v344 * (float)v68));
      v76 = (float)((float)(v342 * (float)v66) - (float)(v345 * (float)v68));
      v77 = (float)((float)(v340 * (float)v66) - (float)(v343 * (float)v68));
      v78 = (float)((float)((float)v66 - vehicle_online_mph_dmg_lowerBound.valueFloat) * (float)((float)1.0 / (float)v47));
      v79 = (float)((float)((float)v77 * (float)v77)
                  + (float)((float)((float)v76 * (float)v76) + (float)((float)v75 * (float)v75)));
      _FP9 = (float)((float)((float)((float)v77 * (float)v77)
                           + (float)((float)((float)v76 * (float)v76) + (float)((float)v75 * (float)v75)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f6, f9, f2, f0 }
      v82 = __frsqrte(_FP6);
      v83 = (float)((float)-(float)((float)((float)((float)v82 * (float)((float)v79 * (float)0.5)) * (float)v82)
                                  - (float)1.5)
                  * (float)v82);
      v84 = (float)((float)((float)-(float)((float)((float)((float)v82 * (float)((float)v79 * (float)0.5)) * (float)v82)
                                          - (float)1.5)
                          * (float)v82)
                  * (float)((float)v79 * (float)0.5));
      v85 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v84 * (float)v83)
                                                                                  - (float)1.5)
                                                                  * (float)v83)
                                                          * (float)((float)v79 * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)v84 * (float)v83) - (float)1.5)
                                                          * (float)v83))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)v84 * (float)v83) - (float)1.5) * (float)v83))
                  * (float)v79);
      if ( v78 >= 0.0 )
      {
        if ( v78 > 1.0 )
          v78 = 1.0;
      }
      else
      {
        v78 = 0.0;
      }
      if ( v85 <= 0.0 )
        v86 = 0.0;
      else
        v86 = (float)((float)v66
                    / (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v84 * (float)v83)
                                                                                            - (float)1.5)
                                                                            * (float)v83)
                                                                    * (float)((float)v79 * (float)0.5))
                                                            * (float)((float)-(float)((float)((float)v84 * (float)v83)
                                                                                    - (float)1.5)
                                                                    * (float)v83))
                                                    - (float)1.5)
                                    * (float)((float)-(float)((float)((float)v84 * (float)v83) - (float)1.5) * (float)v83))
                            * (float)v79));
      v87 = (float)((float)((float)v68 - vehicle_online_mph_dmg_lowerBound.valueFloat) * (float)((float)1.0 / (float)v47));
      if ( v87 >= 0.0 )
      {
        if ( v87 > 1.0 )
          v87 = 1.0;
      }
      else
      {
        v87 = 0.0;
      }
      if ( v85 <= 0.0 )
        v89 = 0.0;
      else
        v89 = (float)((float)v68 / (float)v85);
      if ( v73 <= 0.0 )
        v90 = 0.0;
      else
        v90 = (float)((float)v72 / (float)((float)v72 + (float)v70));
      v91 = (float)((float)((float)((float)v90 * (float)v89) * (float)(vehicle_online_mph_damage.valueFloat * (float)v85))
                  + (float)((float)((float)(vehicle_online_mph_damage.valueFloat * (float)v85) * (float)v86) * (float)v74));
      if ( v91 <= 0.0 )
      {
        v92 = 0.0;
      }
      else
      {
        v88 = (float)((float)((float)(vehicle_online_mph_damage.valueFloat * (float)v85) * (float)v86) * (float)v74);
        v92 = (float)((float)v88
                    / (float)((float)((float)((float)v90 * (float)v89)
                                    * (float)(vehicle_online_mph_damage.valueFloat * (float)v85))
                            + (float)v88));
      }
      if ( v91 <= 0.0 )
        v93 = 0.0;
      else
        v93 = (float)((float)((float)((float)v90 * (float)v89)
                            * (float)(vehicle_online_mph_damage.valueFloat * (float)v85))
                    / (float)((float)((float)((float)v90 * (float)v89)
                                    * (float)(vehicle_online_mph_damage.valueFloat * (float)v85))
                            + (float)((float)((float)(vehicle_online_mph_damage.valueFloat * (float)v85) * (float)v86)
                                    * (float)v74)));
      v94 = vehicle_DMG.valueInteger;
      v95 = (float)((float)((float)v92 * (float)(vehicle_online_mph_damage.valueFloat * (float)v85)) * (float)v78);
      v96 = (float)((float)((float)v93 * (float)v87) * (float)(vehicle_online_mph_damage.valueFloat * (float)v85));
      if ( vehicle_DMG.valueInteger != 0 )
      {
        if ( v30 != nullptr )
        {
          v97 = v85;
          v98 = (float)(vehicle_online_mph_damage.valueFloat * (float)v85);
          idLib::Printf(
            fmt: "DAMAGE GIVEN: %f (%f%%)\n"
            "\t base damage: %f \n"
            "\t total speed: %f \n"
            "\t mass bonus: %f \n"
            "\t speed bonus: %f\n"
            "\t \n",
            (float)((float)((float)v92 * (float)(vehicle_online_mph_damage.valueFloat * (float)v85)) * (float)v78),
            v92,
            v98,
            v85,
            v74,
            v86);
          idLib::Printf(
            fmt: (const char *)HIDWORD(v96),
            LODWORD(v96),
            LODWORD(v93),
            HIDWORD(v97),
            LODWORD(v97),
            LODWORD(v90),
            LODWORD(v89),
            v96,
            v93,
            v98,
            v97,
            v90,
            v89);
          v94 = vehicle_DMG.valueInteger;
        }
        if ( v94 != 0 && v30 != nullptr )
        {
          vehicle = this->damages.vehicle;
          if ( vehicle != nullptr )
            data = vehicle->damageName.data;
          else
            data = "NULL";
          idLib::Printf(fmt: "damages.vehicle.damageName = %s\n", data);
        }
      }
      v101 = this->__vftable;
      v102 = this->damages.vehicle;
      Driver = idVehicle::GetDriver(this: v33);
      v104 = ((double (__fastcall *)(idVehicle_Car *, idVehicle_Car *, idEntity *, const idDeclDamage *, double))v101->Damage)(
               a1: this,
               a2: v33,
               a3: Driver,
               a4: v102,
               a5: v96);
      v105 = v33->__vftable;
      v106 = v104;
      v107 = this->damages.vehicle;
      v20 = v104;
      v108 = idVehicle::GetDriver(this);
      v109 = ((double (__fastcall *)(idVehicle_Car *, idVehicle_Car *, idEntity *, const idDeclDamage *, double))v105->Damage)(
               a1: v33,
               a2: this,
               a3: v108,
               a4: v107,
               a5: v95);
      v110 = v33->presentable;
      v111 = v109;
      if ( v110 != nullptr )
        v112 = (int)v110->GetVehicleInterface(this: v110);
      else
        v112 = 0;
      *(float *)(v112 + 20324) = v95;
      if ( vehicle_DMG.valueInteger != 0 && v30 != nullptr )
        idLib::Printf(fmt: "DAMAGE given result: %f, DAMAGE taken result: %f\n", v111, v106);
      HIDWORD(v333) = (gameLocal->spawnIds.ptr[v33->entityNumber] << 13) | v33->entityNumber;
      LODWORD(v333) = vehicle_online_nextCollisionTime.valueInteger
                    + idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idList<idVehicle_Car::vehicleHitData_t,5>::Append(
        this: &this->hitList,
        obj: (const idVehicle_Car::vehicleHitData_t *)&v333);
      idVehicle_Car::AddCollisionFromOther(this: v33, other: this);
    }
    else
    {
      v113 = idEntity::GetPhysics(this);
      v114 = idEntity::GetPhysics(this: v33);
      v115 = (float *)v113->GetOrigin(this: v113, a2: 0);
      v116 = (float *)v114->GetOrigin(this: v114, a2: 0);
      v117 = (float)(v116[1] - v115[1]);
      v118 = (float)(*v116 - *v115);
      v119 = (float)(v116[2] - v115[2]);
      *((float *)&v333 + 1) = v116[1] - v115[1];
      v334 = v119;
      *(float *)&v333 = v118;
      v335 = (idVehicle_Car::vehicleHitData_t)v333;
      v336 = v334;
      _FP12 = (float)((float)((float)((float)v119 * (float)v119)
                            + (float)((float)((float)v118 * (float)v118) + (float)((float)v117 * (float)v117)))
                    - idMath::FLT_SMALLEST_NON_DENORMAL);
      v121 = (float)((float)((float)((float)v119 * (float)v119)
                           + (float)((float)((float)v118 * (float)v118) + (float)((float)v117 * (float)v117)))
                   * (float)0.5);
      __asm { fsel      f10, f12, f1, f13 }
      v123 = __frsqrte(_FP10);
      v124 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v123 * (float)v121)
                                                                                   * (float)v123)
                                                                           - (float)1.5)
                                                           * (float)v123)
                                                   * (float)v121)
                                           * (float)((float)-(float)((float)((float)((float)v123 * (float)v121)
                                                                           * (float)v123)
                                                                   - (float)1.5)
                                                   * (float)v123))
                                   - (float)1.5)
                   * (float)((float)-(float)((float)((float)((float)v123 * (float)v121) * (float)v123) - (float)1.5)
                           * (float)v123));
      v125 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v123 * (float)v121) * (float)v123) - (float)1.5)
                                                                                           * (float)v123)
                                                                                   * (float)v121)
                                                                           * (float)((float)-(float)((float)((float)((float)v123 * (float)v121) * (float)v123) - (float)1.5)
                                                                                   * (float)v123))
                                                                   - (float)1.5)
                                                   * (float)((float)-(float)((float)((float)((float)v123 * (float)v121)
                                                                                   * (float)v123)
                                                                           - (float)1.5)
                                                           * (float)v123))
                                           * (float)v121)
                                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v123 * (float)v121) * (float)v123) - (float)1.5)
                                                                                   * (float)v123)
                                                                           * (float)v121)
                                                                   * (float)((float)-(float)((float)((float)((float)v123 * (float)v121) * (float)v123)
                                                                                           - (float)1.5)
                                                                           * (float)v123))
                                                           - (float)1.5)
                                           * (float)((float)-(float)((float)((float)((float)v123 * (float)v121)
                                                                           * (float)v123)
                                                                   - (float)1.5)
                                                   * (float)v123)))
                           - (float)1.5);
      v126 = (float)((float)((float)v125 * (float)v124) * (float)v118);
      v127 = (float)(*((float *)&v333 + 1) * (float)((float)v125 * (float)v124));
      v128 = (float)(v334 * (float)((float)v125 * (float)v124));
      v129 = idEntity::GetPhysics(this: v33);
      v129->GetImpactInfo(this: v129, a2: collision->c.bodyId, a3: &collision->c.point, a4: (impactInfo_t *)v354);
      v335 = v355;
      v336 = v356;
      v130 = this->presentable;
      _FP4 = (float)((float)((float)(v356 * v356)
                           + (float)((float)(*(float *)&v355.otherCar.spawnId.value
                                           * *(float *)&v355.otherCar.spawnId.value)
                                   + (float)(*(float *)&v355.nextCollisionTime * *(float *)&v355.nextCollisionTime)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f2, f4, f6, f0 }
      v133 = __frsqrte(_FP2);
      v134 = (float)((float)-(float)((float)((float)((float)v133
                                                   * (float)((float)((float)(v356 * v356)
                                                                   + (float)((float)(*(float *)&v355.otherCar.spawnId.value
                                                                                   * *(float *)&v355.otherCar.spawnId.value)
                                                                           + (float)(*(float *)&v355.nextCollisionTime
                                                                                   * *(float *)&v355.nextCollisionTime)))
                                                           * (float)0.5))
                                           * (float)v133)
                                   - (float)1.5)
                   * (float)v133);
      v135 = (float)((float)((float)-(float)((float)((float)((float)v133
                                                           * (float)((float)((float)(v356 * v356)
                                                                           + (float)((float)(*(float *)&v355.otherCar.spawnId.value
                                                                                           * *(float *)&v355.otherCar.spawnId.value)
                                                                                   + (float)(*(float *)&v355.nextCollisionTime
                                                                                           * *(float *)&v355.nextCollisionTime)))
                                                                   * (float)0.5))
                                                   * (float)v133)
                                           - (float)1.5)
                           * (float)v133)
                   * (float)((float)((float)(v356 * v356)
                                   + (float)((float)(*(float *)&v355.otherCar.spawnId.value
                                                   * *(float *)&v355.otherCar.spawnId.value)
                                           + (float)(*(float *)&v355.nextCollisionTime
                                                   * *(float *)&v355.nextCollisionTime)))
                           * (float)0.5));
      v136 = (float)(*(float *)&v355.otherCar.spawnId.value
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v135 * (float)v134)
                                                                                   - (float)1.5)
                                                                   * (float)v134)
                                                           * (float)((float)((float)(v356 * v356)
                                                                           + (float)((float)(*(float *)&v355.otherCar.spawnId.value
                                                                                           * *(float *)&v355.otherCar.spawnId.value)
                                                                                   + (float)(*(float *)&v355.nextCollisionTime
                                                                                           * *(float *)&v355.nextCollisionTime)))
                                                                   * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)v135 * (float)v134)
                                                                           - (float)1.5)
                                                           * (float)v134))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)v135 * (float)v134) - (float)1.5) * (float)v134)));
      v137 = (float)(*(float *)&v355.nextCollisionTime
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v135 * (float)v134)
                                                                                   - (float)1.5)
                                                                   * (float)v134)
                                                           * (float)((float)((float)(v356 * v356)
                                                                           + (float)((float)(*(float *)&v355.otherCar.spawnId.value
                                                                                           * *(float *)&v355.otherCar.spawnId.value)
                                                                                   + (float)(*(float *)&v355.nextCollisionTime
                                                                                           * *(float *)&v355.nextCollisionTime)))
                                                                   * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)v135 * (float)v134)
                                                                           - (float)1.5)
                                                           * (float)v134))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)v135 * (float)v134) - (float)1.5) * (float)v134)));
      v138 = (float)(v356
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v135 * (float)v134)
                                                                                   - (float)1.5)
                                                                   * (float)v134)
                                                           * (float)((float)((float)(v356 * v356)
                                                                           + (float)((float)(*(float *)&v355.otherCar.spawnId.value
                                                                                           * *(float *)&v355.otherCar.spawnId.value)
                                                                                   + (float)(*(float *)&v355.nextCollisionTime
                                                                                           * *(float *)&v355.nextCollisionTime)))
                                                                   * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)v135 * (float)v134)
                                                                           - (float)1.5)
                                                           * (float)v134))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)v135 * (float)v134) - (float)1.5) * (float)v134)));
      if ( v130 != nullptr )
        v139 = (int)v130->GetVehicleInterface(this: v130);
      else
        v139 = 0;
      v140 = *(_DWORD *)(v139 + 20284);
      HIDWORD(v333) = v139 + 20284;
      if ( gameLocal->spawnIds.ptr[v140 & 0x1FFF] == v140 >> 13
        && (v141 = gameLocal->entities.ptr[v140 & 0x1FFF]) != nullptr )
      {
        v142 = idEntity::CastTo(c: v141);
      }
      else
      {
        v142 = nullptr;
      }
      if ( v142 != otherEnt
        || (LastCollision = (_DWORD *)idVehicle::GetLastCollision(this),
            gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - *LastCollision > 200) )
      {
        this->constantCollisionScale = 1.0;
      }
      v144 = this->presentable;
      if ( v144 != nullptr )
        v145 = (float *)v144->GetVehicleInterface(this: v144);
      else
        v145 = nullptr;
      v146 = -v145[4353];
      v147 = -v145[4352];
      v148 = -v145[4354];
      HIDWORD(v333) = v145 + 4352;
      v149 = (float)((float)(v337 * (float)v126) + (float)((float)((float)v128 * v339) + (float)((float)v127 * v338)));
      v150 = (float)((float)((float)v148 * (float)v148)
                   + (float)((float)((float)v147 * (float)v147) + (float)((float)v146 * (float)v146)));
      v152 = (float)((float)((float)((float)v148 * (float)v148)
                           + (float)((float)((float)v147 * (float)v147) + (float)((float)v146 * (float)v146)))
                   * (float)0.5);
      _FP10 = (float)((float)((float)((float)v148 * (float)v148)
                            + (float)((float)((float)v147 * (float)v147) + (float)((float)v146 * (float)v146)))
                    - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f8, f10, f11, f13 }
      v154 = __frsqrte(_FP8);
      v155 = (float)((float)(this->constantCollisionScale
                           * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v154 * (float)v152) * (float)v154) - (float)1.5) * (float)v154) * (float)v152) * (float)((float)-(float)((float)((float)((float)v154 * (float)v152) * (float)v154) - (float)1.5) * (float)v154))
                                                                                           - (float)1.5)
                                                                           * (float)((float)-(float)((float)((float)((float)v154 * (float)v152) * (float)v154) - (float)1.5)
                                                                                   * (float)v154))
                                                                   * (float)v152)
                                                           * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v154 * (float)v152) * (float)v154) - (float)1.5) * (float)v154) * (float)v152)
                                                                                           * (float)((float)-(float)((float)((float)((float)v154 * (float)v152) * (float)v154) - (float)1.5) * (float)v154))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v154 * (float)v152) * (float)v154)
                                                                                           - (float)1.5)
                                                                           * (float)v154)))
                                                   - (float)1.5)
                                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v154 * (float)v152) * (float)v154) - (float)1.5)
                                                                                   * (float)v154)
                                                                           * (float)v152)
                                                                   * (float)((float)-(float)((float)((float)((float)v154 * (float)v152) * (float)v154)
                                                                                           - (float)1.5)
                                                                           * (float)v154))
                                                           - (float)1.5)
                                           * (float)((float)-(float)((float)((float)((float)v154 * (float)v152)
                                                                           * (float)v154)
                                                                   - (float)1.5)
                                                   * (float)v154))))
                   * (float)v150);
      if ( v149 < 0.0 )
        v149 = 0.0;
      v156 = (float)((float)((float)-v126 * (float)v136) + (float)((float)v137 * (float)-v127));
      v157 = (float)((float)((float)(vehicle_damageGiven_frac.valueFloat * (float)v149) * (float)v155)
                   * (float)0.000099999997);
      v158 = (float)((float)((float)v138 * (float)-v128) + (float)v156);
      if ( v158 < 0.0 )
        v158 = 0.050000001;
      v159 = (float)((float)((float)(vehicle_damageTaken_frac.valueFloat * (float)v158) * (float)v155)
                   * (float)0.000099999997);
      v160 = (idPlayer *)idVehicle::GetDriver(this);
      v161 = idPlayer::CastTo(c: v160);
      v162 = (idVehicleAI *)idVehicle::GetDriver(this: v33);
      v163 = idVehicleAI::CastTo(c: v162);
      if ( v161 != nullptr && v163 != nullptr )
        v157 = (float)(vehicle_damageScale_playerHitsAi.valueFloat * (float)v157);
      if ( (unsigned __int8)idVehicle_Car::IsBoosting(this) != 0 )
      {
        if ( common->IsMultiplayer(this: common)
          && (v164 = session->GetActingGameStateLobbyBase(this: session), v164->GetMatchParms(this: v164)->gameType == 2) )
        {
          v165 = &vehicle_online_damageScale_playerBoostCollision;
        }
        else
        {
          v165 = &vehicle_damageScale_playerBoostCollision;
        }
        v157 = (float)(v165->valueFloat * (float)v157);
      }
      v166 = this->presentable;
      if ( v166 != nullptr )
        v167 = (int)v166->GetVehicleInterface(this: v166);
      else
        v167 = 0;
      v168 = (float)(*(float *)(v167 + 18920) * (float)v157);
      if ( common->IsMultiplayer(this: common) )
      {
        v169 = session->GetActingGameStateLobbyBase(this: session);
        if ( v169->GetMatchParms(this: v169)->gameType == 2 )
        {
          Team = idEntity::GetTeam(this: v33);
          if ( idEntity::GetTeam(this) == Team && idEntity::GetTeam(this) != TEAM_NONE )
            v168 = (float)(vehicle_online_damageScale_friendlyCollision.valueFloat * (float)v168);
        }
      }
      if ( this->damages.vehicle != nullptr )
      {
        idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)&v353);
        BestArmorForDamage = idVehicle::GetBestArmorForDamage(
                               this,
                               point: (idVec3 *)LODWORD(collision->c.point.y),
                               armorList: (idList<idInventoryItem *,5> *)__ROL4__(LODWORD(collision->c.point.z), 32),
                               a4: &v353);
        if ( BestArmorForDamage != nullptr
          && (!BestArmorForDamage->decl->vehicleArmor ? nullptr : BestArmorForDamage->decl) != nullptr )
        {
          v168 = (float)(*(float *)&(!BestArmorForDamage->decl->vehicleArmor
                                   ? (const idDeclInventory *)504
                                   : &BestArmorForDamage->decl[1])->__vftable
                       * (float)v168);
        }
        if ( v161 == nullptr )
        {
          LODWORD(v172) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->damageSandwichFunTime[0];
          v333 = v172;
          GetGameMs = gameLocal->GetGameMs;
          LODWORD(v333) = (int)__fabs((float)v172);
          v174 = v333;
          LODWORD(v175) = GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->damageSandwichFunTime[1];
          LODWORD(v333) = (int)__fabs((float)v175);
          if ( v174 <= 500 && (int)v333 <= 500 )
            v20 = (float)(vehicle_damageScale_aiSandwich.valueFloat * (float)0.0);
        }
        v176 = this->__vftable;
        v177 = this->damages.vehicle;
        v178 = idVehicle::GetDriver(this: v33);
        v179 = ((double (__fastcall *)(idVehicle_Car *, idVehicle_Car *, idEntity *, const idDeclDamage *, double))v176->Damage)(
                 a1: this,
                 a2: v33,
                 a3: v178,
                 a4: v177,
                 a5: v159);
        v180 = v33->__vftable;
        v20 = (float)((float)v179 + (float)v20);
        v181 = this->damages.vehicle;
        v182 = idVehicle::GetDriver(this);
        ((void (__fastcall *)(idVehicle_Car *, idVehicle_Car *, idEntity *, const idDeclDamage *, double))v180->Damage)(
          a1: v33,
          a2: this,
          a3: v182,
          a4: v181,
          a5: v168);
        *(float *)(idVehicle::GetLastCollision(this: v33) + 52) = v168;
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v353);
      }
      v183 = (float)(this->constantCollisionScale * (float)0.5);
      if ( v183 >= 0.0099999998 )
      {
        if ( v183 > 1.0 )
          v183 = 1.0;
        this->constantCollisionScale = v183;
      }
      else
      {
        this->constantCollisionScale = 0.0099999998;
      }
    }
LABEL_192:
    v299 = vehicle_showDamageValues.valueInteger;
    if ( vehicle_showDamageValues.valueInteger == 1 )
    {
      if ( idVehicle::PlayerIsOccupant(this) != nullptr )
      {
LABEL_196:
        idLib::Printf(fmt: "\n");
LABEL_197:
        v300 = this->presentable;
        if ( v300 != nullptr )
          v301 = (int)v300->GetVehicleInterface(this: v300);
        else
          v301 = 0;
        *(float *)(v301 + 20324) = v20;
        if ( idVehicle::GetDriver(this) != nullptr )
        {
          v302 = idVehicle::GetDriver(this);
          v303 = *(_DWORD *)(v302->GetType(this: v302) + 36);
          if ( v303 < idVehicleAI::Type.typeNum || (v305 = v303 <= idVehicleAI::Type.lastChild, v304 = 1, !v305) )
            v304 = 0;
          if ( v304 != 0 )
          {
            v306 = idEntity::GetPhysics(this);
            v307 = this->presentable;
            v308 = v306;
            if ( v307 != nullptr )
              v309 = (float *)v307->GetVehicleInterface(this: this->presentable);
            else
              v309 = nullptr;
            v310 = (float *)v308->GetOrigin(this: v308, a2: 0);
            v311 = v309[5074];
            v312 = v309[5075];
            v313 = v309[5073];
            HIDWORD(v333) = v309 + 5073;
            v314 = (float)((float)v311 - v310[1]);
            v315 = (float)((float)v312 - v310[2]);
            v316 = (float)((float)v313 - *v310);
            _FP1 = (float)((float)((float)((float)((float)v313 - *v310) * (float)((float)v313 - *v310))
                                 + (float)((float)((float)v315 * (float)v315) + (float)((float)v314 * (float)v314)))
                         - idMath::FLT_SMALLEST_NON_DENORMAL);
            v318 = (float)((float)((float)((float)((float)v313 - *v310) * (float)((float)v313 - *v310))
                                 + (float)((float)((float)v315 * (float)v315) + (float)((float)v314 * (float)v314)))
                         * (float)0.5);
            __asm { fsel      f12, f1, f2, f0 }
            v320 = __frsqrte(_FP12);
            v321 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v320
                                                                                                 * (float)v318)
                                                                                         * (float)v320)
                                                                                 - (float)1.5)
                                                                 * (float)v320)
                                                         * (float)v318)
                                                 * (float)((float)-(float)((float)((float)((float)v320 * (float)v318)
                                                                                 * (float)v320)
                                                                         - (float)1.5)
                                                         * (float)v320))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)((float)v320 * (float)v318) * (float)v320) - (float)1.5)
                                 * (float)v320));
            v322 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v320 * (float)v318) * (float)v320) - (float)1.5)
                                                                                                 * (float)v320)
                                                                                         * (float)v318)
                                                                                 * (float)((float)-(float)((float)((float)((float)v320 * (float)v318) * (float)v320) - (float)1.5)
                                                                                         * (float)v320))
                                                                         - (float)1.5)
                                                         * (float)((float)-(float)((float)((float)((float)v320
                                                                                                 * (float)v318)
                                                                                         * (float)v320)
                                                                                 - (float)1.5)
                                                                 * (float)v320))
                                                 * (float)v318)
                                         * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v320 * (float)v318) * (float)v320) - (float)1.5)
                                                                                         * (float)v320)
                                                                                 * (float)v318)
                                                                         * (float)((float)-(float)((float)((float)((float)v320 * (float)v318) * (float)v320)
                                                                                                 - (float)1.5)
                                                                                 * (float)v320))
                                                                 - (float)1.5)
                                                 * (float)((float)-(float)((float)((float)((float)v320 * (float)v318)
                                                                                 * (float)v320)
                                                                         - (float)1.5)
                                                         * (float)v320)))
                                 - (float)1.5);
            v323 = (float)((float)((float)v322 * (float)v321) * (float)v316);
            v324 = (float)((float)v314 * (float)((float)v322 * (float)v321));
            v325 = (float)((float)v315 * (float)((float)v322 * (float)v321));
            v326 = idEntity::GetPhysics(this);
            v327 = (float *)v326->GetAxis(this: v326, a2: 0);
            v328 = (int (*)(void))gameLocal->GetGameMs;
            if ( (float)((float)((float)v323 * v327[3])
                       + (float)((float)(v327[5] * (float)v325) + (float)(v327[4] * (float)v324))) <= 0.0 )
              this->damageSandwichFunTime[1] = v328();
            else
              this->damageSandwichFunTime[0] = v328();
          }
        }
        v329 = vehicle_showDamageValues.valueInteger;
        if ( vehicle_showDamageValues.valueInteger == 1 )
        {
          if ( idVehicle::PlayerIsOccupant(this) != nullptr )
            goto LABEL_215;
          v329 = vehicle_showDamageValues.valueInteger;
        }
        if ( v329 != 2 )
          return 1;
LABEL_215:
        idLib::Printf(fmt: "\n=====================================================\n");
        return 1;
      }
      v299 = vehicle_showDamageValues.valueInteger;
    }
    if ( v299 != 2 )
      goto LABEL_197;
    goto LABEL_196;
  }
  if ( (unsigned __int8)idAI2::IsTypeOf(c: otherEnt) != 0 )
  {
    v184 = idEntity::GetPhysics(this);
    v185 = (float *)v184->GetLinearVelocity(this: (idPhysics *)&v335, result: (idVec3 *)v184, a3: 0);
    runOver = this->damages.runOver;
    _FP7 = (float)((float)((float)(v185[2] * v185[2]) + (float)((float)(*v185 * *v185) + (float)(v185[1] * v185[1])))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f5, f7, f8, f0 }
    v189 = __frsqrte(_FP5);
    v190 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v189
                                                                                         * (float)((float)((float)(v185[2] * v185[2]) + (float)((float)(*v185 * *v185) + (float)(v185[1] * v185[1])))
                                                                                                 * (float)0.5))
                                                                                 * (float)v189)
                                                                         - (float)1.5)
                                                         * (float)v189)
                                                 * (float)((float)((float)(v185[2] * v185[2])
                                                                 + (float)((float)(*v185 * *v185)
                                                                         + (float)(v185[1] * v185[1])))
                                                         * (float)0.5))
                                         * (float)((float)-(float)((float)((float)((float)v189
                                                                                 * (float)((float)((float)(v185[2] * v185[2])
                                                                                                 + (float)((float)(*v185 * *v185) + (float)(v185[1] * v185[1])))
                                                                                         * (float)0.5))
                                                                         * (float)v189)
                                                                 - (float)1.5)
                                                 * (float)v189))
                                 - (float)1.5)
                 * (float)((float)-(float)((float)((float)((float)v189
                                                         * (float)((float)((float)(v185[2] * v185[2])
                                                                         + (float)((float)(*v185 * *v185)
                                                                                 + (float)(v185[1] * v185[1])))
                                                                 * (float)0.5))
                                                 * (float)v189)
                                         - (float)1.5)
                         * (float)v189));
    v191 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v189 * (float)((float)((float)(v185[2] * v185[2]) + (float)((float)(*v185 * *v185) + (float)(v185[1] * v185[1]))) * (float)0.5)) * (float)v189) - (float)1.5)
                                                                                         * (float)v189)
                                                                                 * (float)((float)((float)(v185[2] * v185[2])
                                                                                                 + (float)((float)(*v185 * *v185) + (float)(v185[1] * v185[1])))
                                                                                         * (float)0.5))
                                                                         * (float)((float)-(float)((float)((float)((float)v189 * (float)((float)((float)(v185[2] * v185[2]) + (float)((float)(*v185 * *v185) + (float)(v185[1] * v185[1]))) * (float)0.5)) * (float)v189)
                                                                                                 - (float)1.5)
                                                                                 * (float)v189))
                                                                 - (float)1.5)
                                                 * (float)((float)-(float)((float)((float)((float)v189
                                                                                         * (float)((float)((float)(v185[2] * v185[2]) + (float)((float)(*v185 * *v185) + (float)(v185[1] * v185[1])))
                                                                                                 * (float)0.5))
                                                                                 * (float)v189)
                                                                         - (float)1.5)
                                                         * (float)v189))
                                         * (float)((float)((float)(v185[2] * v185[2])
                                                         + (float)((float)(*v185 * *v185) + (float)(v185[1] * v185[1])))
                                                 * (float)0.5))
                                 * (float)v190)
                         - (float)1.5);
    v192 = (float)((float)((float)((float)v191
                                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v189 * (float)((float)((float)(v185[2] * v185[2]) + (float)((float)(*v185 * *v185) + (float)(v185[1] * v185[1]))) * (float)0.5)) * (float)v189)
                                                                                                 - (float)1.5)
                                                                                 * (float)v189)
                                                                         * (float)((float)((float)(v185[2] * v185[2])
                                                                                         + (float)((float)(*v185 * *v185)
                                                                                                 + (float)(v185[1] * v185[1])))
                                                                                 * (float)0.5))
                                                                 * (float)((float)-(float)((float)((float)((float)v189 * (float)((float)((float)(v185[2] * v185[2]) + (float)((float)(*v185 * *v185) + (float)(v185[1] * v185[1]))) * (float)0.5))
                                                                                                 * (float)v189)
                                                                                         - (float)1.5)
                                                                         * (float)v189))
                                                         - (float)1.5)
                                         * (float)((float)-(float)((float)((float)((float)v189
                                                                                 * (float)((float)((float)(v185[2] * v185[2])
                                                                                                 + (float)((float)(*v185 * *v185) + (float)(v185[1] * v185[1])))
                                                                                         * (float)0.5))
                                                                         * (float)v189)
                                                                 - (float)1.5)
                                                 * (float)v189)))
                         * (float)((float)(v185[2] * v185[2])
                                 + (float)((float)(*v185 * *v185) + (float)(v185[1] * v185[1]))))
                 * (float)0.056818184);
    if ( runOver != nullptr && v192 >= this->damageAiSpeed )
    {
      v193 = (idEntity_vtbl *)otherEnt->__vftable;
      v194 = idVehicle::GetDriver(this);
      ((void (__fastcall *)(idVehicle_Car *, idVehicle_Car *, idEntity *, const idDeclDamage *, double))v193->Damage)(
        a1: otherEnt,
        a2: this,
        a3: v194,
        a4: runOver,
        a5: v192);
      v195 = idAI2::CastTo(c: (idAI2 *)otherEnt);
      v196 = idEntity::GetPhysics(this: otherEnt);
      v197 = idEntity::GetPhysics(this);
      v198 = ((double (__fastcall *)(idPhysics *, int))v196->GetMass)(a1: v196, a2: -1);
      v199 = (float *)v197->GetLinearVelocity(this: (idPhysics *)&v335, result: (idVec3 *)v197, a3: 0);
      v200 = (float)(v199[1] * (float)v198);
      v201 = (float)(*v199 * (float)v198);
      v202 = (float)(v199[2] * (float)v198);
      v347.x = *v199 * (float)v198;
      v347.y = v200;
      v203 = (float)((float)((float)v202 * (float)v202)
                   + (float)((float)((float)v201 * (float)v201) + (float)((float)v200 * (float)v200)));
      _FP4 = (float)((float)((float)((float)v202 * (float)v202)
                           + (float)((float)((float)v201 * (float)v201) + (float)((float)v200 * (float)v200)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      v205 = (float)((float)((float)((float)v202 * (float)v202)
                           + (float)((float)((float)v201 * (float)v201) + (float)((float)v200 * (float)v200)))
                   * (float)0.5);
      __asm { fsel      f2, f4, f5, f0 }
      v207 = __frsqrte(_FP2);
      v208 = (float)((float)v207
                   * (float)((float)((float)((float)v202 * (float)v202)
                                   + (float)((float)((float)v201 * (float)v201) + (float)((float)v200 * (float)v200)))
                           * (float)0.5));
      v347.z = (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v208 * (float)v207) - (float)1.5) * (float)v207) * (float)v205) * (float)((float)-(float)((float)((float)v208 * (float)v207) - (float)1.5) * (float)v207))
                                                                                             - (float)1.5)
                                                                             * (float)((float)-(float)((float)((float)v208 * (float)v207) - (float)1.5)
                                                                                     * (float)v207))
                                                                     * (float)v205)
                                                             * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v208 * (float)v207) - (float)1.5) * (float)v207) * (float)v205)
                                                                                             * (float)((float)-(float)((float)((float)v208 * (float)v207) - (float)1.5) * (float)v207))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)v208 * (float)v207)
                                                                                             - (float)1.5)
                                                                             * (float)v207)))
                                                     - (float)1.5)
                                     * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v208 * (float)v207) - (float)1.5)
                                                                                     * (float)v207)
                                                                             * (float)v205)
                                                                     * (float)((float)-(float)((float)((float)v208 * (float)v207)
                                                                                             - (float)1.5)
                                                                             * (float)v207))
                                                             - (float)1.5)
                                             * (float)((float)-(float)((float)((float)v208 * (float)v207) - (float)1.5)
                                                     * (float)v207)))
                             * (float)v203)
                     * (float)0.25)
             + (float)v202;
      v209 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v209;
      if ( (int)(((v209 >> 10) & 0x7FFF) % 0x64) < vehicle_aiThrowChance.valueInteger )
      {
        v347.x = 0.0;
        v347.y = 0.0;
        v347.z = v347.z * (float)1.5;
      }
      idAI2::ApplyFakeDamageImpulse(this: v195, impulse: &v347);
    }
    goto LABEL_192;
  }
  if ( (unsigned __int8)idPlayer::IsTypeOf(c: otherEnt) != 0 )
  {
    if ( idVehicle::GetDriver(this) != nullptr )
    {
      v210 = idEntity::GetPhysics(this);
      v211 = (float *)v210->GetOrigin(this: v210, a2: 0);
      v212 = (float)(this->lastOrigin.y - v211[1]);
      v213 = this->lastOrigin.z;
      v214 = v211[2];
      HIDWORD(v333) = &this->lastOrigin;
      v215 = (float)(this->lastOrigin.x - *v211);
      if ( (float)((float)((float)v215 * (float)v215)
                 + (float)((float)((float)((float)v213 - (float)v214) * (float)((float)v213 - (float)v214))
                         + (float)((float)v212 * (float)v212))) > 4.0 )
      {
        v216 = idEntity::GetPhysics(this);
        v216->GetLinearVelocity(this: (idPhysics *)&v335, result: (idVec3 *)v216, a3: 0);
        idLib::Printf(
          fmt: "vehicle velocity: %f %f %f\n",
          *(float *)&v335.otherCar.spawnId.value,
          *(float *)&v335.nextCollisionTime,
          v336);
        v217 = idEntity::GetPhysics(this);
        v218 = ((double (__fastcall *)(idPhysics *, int))v217->GetMass)(a1: v217, a2: -1);
        v219 = collision->endAxis.mat[0].y;
        v220 = collision->endAxis.mat[0].z;
        ApplyImpulseFromEntity = (void (__fastcall *)(idEntity *, const idEntity *, const int, const idVec3 *, const idVec3 *))otherEnt->ApplyImpulseFromEntity;
        v350[0] = (float)((float)v218 * (float)v10) * collision->endAxis.mat[0].x;
        v350[1] = (float)v219 * (float)((float)v218 * (float)v10);
        v350[2] = (float)v220 * (float)((float)v218 * (float)v10);
        ApplyImpulseFromEntity(this: otherEnt, a2: this, a3: 0, a4: &collision->endpos, a5: (const idVec3 *)v350);
        v222 = this->damages.vehicle;
        if ( v222 != nullptr )
        {
          v223 = (idEntity_vtbl *)otherEnt->__vftable;
          v224 = idVehicle::GetDriver(this);
          ((void (__fastcall *)(idVehicle_Car *, idVehicle_Car *, idEntity *, const idDeclDamage *, double))v223->Damage)(
            a1: otherEnt,
            a2: this,
            a3: v224,
            a4: v222,
            a5: v29);
        }
      }
    }
    goto LABEL_192;
  }
  if ( (unsigned __int8)idProp_Moveable::IsTypeOf(c: otherEnt) == 0
    && (unsigned __int8)idBreakable::IsTypeOf(c: otherEnt) == 0
    && (unsigned __int8)idDamageableEntity::IsTypeOf(c: otherEnt) == 0 )
  {
    if ( common->IsMultiplayer(this: common) && vehicle_online_environment_dmg.valueInteger == 0 )
      return 1;
    v225 = idEntity::GetPhysics(this);
    v226 = (float *)v225->GetAxis(this: v225, a2: 0);
    *(double *)&v227 = (float)(vehicle_damageScale_normalLanding_angle.valueFloat * idMath::M_DEG2RAD);
    v228 = (float)((float)(collision->c.normal.x * v226[6])
                 + (float)((float)(v226[8] * collision->c.normal.z) + (float)(v226[7] * collision->c.normal.y)));
    v229 = cos(x: v227);
    if ( v228 < (float)*(double *)&v229 )
      goto LABEL_159;
    ViolentRollStartTime = idVehicle_Car::GetViolentRollStartTime(this);
    ViolentRollStopTime = idVehicle_Car::GetViolentRollStopTime(this);
    v232 = vehicle_showDamageValues.valueInteger;
    if ( ViolentRollStartTime <= ViolentRollStopTime )
    {
      v29 = (float)(vehicle_damageScale_normalLanding.valueFloat * (float)v29);
      if ( vehicle_showDamageValues.valueInteger == 1 )
      {
        if ( idVehicle::PlayerIsOccupant(this) != nullptr )
        {
LABEL_153:
          *(double *)&v229 = v228;
          v233 = idMath::ACos(a: v229);
          idLib::Printf(
            fmt: "DAMAGE: %f      [ * * Vehicle Landing * * angle %f < %f     damage scale reduction -> %f ]\n",
            v29,
            (float)((float)v233 * idMath::M_RAD2DEG),
            vehicle_damageScale_normalLanding_angle.valueFloat,
            vehicle_damageScale_normalLanding.valueFloat);
          goto LABEL_159;
        }
        v232 = vehicle_showDamageValues.valueInteger;
      }
      if ( v232 != 2 )
        goto LABEL_159;
      goto LABEL_153;
    }
    if ( vehicle_showDamageValues.valueInteger == 1 )
    {
      if ( idVehicle::PlayerIsOccupant(this) != nullptr )
      {
LABEL_158:
        idLib::Printf(fmt: "[ * * Vehicle Landing * * ignored, * * Violent Roll * * ]\n");
LABEL_159:
        v20 = ((double (__fastcall *)(idVehicle_Car *, _DWORD, _DWORD, const idDeclDamage *, double, double))this->Damage)(
                a1: this,
                a2: 0,
                a3: 0,
                a4: this->damages.world,
                a5: v29,
                a6: *((double *)&v229 + 1));
        if ( (unsigned __int8)idTowerTurret::IsTypeOf(c: otherEnt) != 0 )
        {
          v234 = (idEntity_vtbl *)otherEnt->__vftable;
          v235 = this->damages.runOver;
          v236 = idVehicle::GetDriver(this);
          ((void (__fastcall *)(idVehicle_Car *, idVehicle_Car *, idEntity *, const idDeclDamage *, double))v234->Damage)(
            a1: otherEnt,
            a2: this,
            a3: v236,
            a4: v235,
            a5: (float)((float)v29 * (float)20.0));
        }
        else
        {
          ((void (__fastcall *)(idVehicle_Car *, _DWORD, _DWORD, const idDeclDamage *, double))otherEnt->Damage)(
            a1: otherEnt,
            a2: 0,
            a3: 0,
            a4: this->damages.vehicle,
            a5: v29);
        }
        goto LABEL_192;
      }
      v232 = vehicle_showDamageValues.valueInteger;
    }
    if ( v232 != 2 )
      goto LABEL_159;
    goto LABEL_158;
  }
  v237 = idDamageableEntity::CastTo(c: (idDamageableEntity *)otherEnt);
  v238 = idBreakable::CastTo(c: (idBreakable *)otherEnt);
  idEntity::GetLinearVelocity(this: (idEntity *)&v335, result: otherEnt);
  if ( v237 == nullptr || !v237->staticVehicleCollisions )
  {
    if ( v238 != nullptr )
    {
      v246 = v238->__vftable;
      v247 = this->damages.vehicle;
      v248 = idVehicle::GetDriver(this);
      ((void (__fastcall *)(idBreakable *, idVehicle_Car *, idEntity *, const idDeclDamage *, double))v246->Damage)(
        a1: v238,
        a2: this,
        a3: v248,
        a4: v247,
        a5: v29);
    }
    if ( v237 == nullptr || ((double (__fastcall *)(idDamageableEntity *))v237->GetHealth)(a1: v237) > 0.0 )
    {
      v249 = this->damages.vehicle;
      if ( v249 != nullptr )
      {
        if ( v10 <= vehicle_ignoreCollisionForceSpeed.valueFloat )
        {
          v253 = this->__vftable;
          v254 = idVehicle::GetDriver(this);
          v252 = ((double (__fastcall *)(idVehicle_Car *, idVehicle_Car *, idEntity *, const idDeclDamage *, double))v253->Damage)(
                   a1: this,
                   a2: this,
                   a3: v254,
                   a4: v249,
                   a5: (float)((float)v29 * (float)0.5));
        }
        else
        {
          v250 = this->__vftable;
          v251 = idVehicle::GetDriver(this);
          v252 = ((double (__fastcall *)(idVehicle_Car *, idVehicle_Car *, idEntity *, const idDeclDamage *, double))v250->Damage)(
                   a1: this,
                   a2: this,
                   a3: v251,
                   a4: v249,
                   a5: (float)((float)v29 * (float)0.5));
        }
        v20 = v252;
      }
    }
    v255 = idEntity::GetPhysics(this: otherEnt);
    v256 = idEntity::GetPhysics(this);
    v257 = ((double (__fastcall *)(idPhysics *, int))v255->GetMass)(a1: v255, a2: -1);
    v258 = (float *)v256->GetLinearVelocity(this: (idPhysics *)&v335, result: (idVec3 *)v256, a3: 0);
    v259 = (float)(v258[2] * (float)v257);
    v260 = (float)(v258[1] * (float)v257);
    v261 = (float)((float)v257 * *v258);
    v346.x = (float)v257 * *v258;
    v346.z = v259;
    v346.y = v260;
    if ( v237 != nullptr )
    {
      if ( ((double (__fastcall *)(idDamageableEntity *))v237->GetHealth)(a1: v237) <= 0.0 )
      {
        idVec3::NormalizeFast(this: &v346);
        v270 = (void (__fastcall *)(idEntity *, const idEntity *, const int, const idVec3 *, const idVec3 *))otherEnt->ApplyImpulseFromEntity;
        v351[0] = vehicle_towerImpulseMagnitude.valueFloat * v346.x;
        v351[1] = vehicle_towerImpulseMagnitude.valueFloat * v346.y;
        v351[2] = vehicle_towerImpulseMagnitude.valueFloat * v346.z;
        v270(this: otherEnt, a2: this, a3: 0, a4: &collision->endpos, a5: (const idVec3 *)v351);
      }
    }
    else
    {
      v262 = (void (__fastcall *)(idEntity *, const idEntity *, const int, const idVec3 *, const idVec3 *))otherEnt->ApplyImpulseFromEntity;
      v263 = (float)((float)((float)v259 * (float)v259)
                   + (float)((float)((float)v261 * (float)v261) + (float)((float)v260 * (float)v260)));
      _FP8 = (float)((float)((float)((float)v259 * (float)v259)
                           + (float)((float)((float)v261 * (float)v261) + (float)((float)v260 * (float)v260)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      v265 = (float)((float)((float)((float)v259 * (float)v259)
                           + (float)((float)((float)v261 * (float)v261) + (float)((float)v260 * (float)v260)))
                   * (float)0.5);
      __asm { fsel      f6, f8, f9, f13 }
      v267 = __frsqrte(_FP6);
      v268 = (float)((float)-(float)((float)((float)((float)v267
                                                   * (float)((float)((float)((float)v259 * (float)v259)
                                                                   + (float)((float)((float)v261 * (float)v261)
                                                                           + (float)((float)v260 * (float)v260)))
                                                           * (float)0.5))
                                           * (float)v267)
                                   - (float)1.5)
                   * (float)v267);
      v269 = (float)((float)((float)-(float)((float)((float)((float)v267
                                                           * (float)((float)((float)((float)v259 * (float)v259)
                                                                           + (float)((float)((float)v261 * (float)v261)
                                                                                   + (float)((float)v260 * (float)v260)))
                                                                   * (float)0.5))
                                                   * (float)v267)
                                           - (float)1.5)
                           * (float)v267)
                   * (float)((float)((float)((float)v259 * (float)v259)
                                   + (float)((float)((float)v261 * (float)v261) + (float)((float)v260 * (float)v260)))
                           * (float)0.5));
      v346.z = (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v269 * (float)v268)
                                                                                             - (float)1.5)
                                                                             * (float)v268)
                                                                     * (float)v265)
                                                             * (float)((float)-(float)((float)((float)v269 * (float)v268)
                                                                                     - (float)1.5)
                                                                     * (float)v268))
                                                     - (float)1.5)
                                     * (float)((float)-(float)((float)((float)v269 * (float)v268) - (float)1.5)
                                             * (float)v268))
                             * (float)v263)
                     * (float)0.25)
             + (float)v259;
      v262(this: otherEnt, a2: this, a3: 0, a4: &collision->endpos, a5: &v346);
    }
    if ( (unsigned __int8)idProp_Moveable::IsTypeOf(c: otherEnt) != 0 )
    {
      v271 = idEntity::GetPhysics(this: otherEnt);
      v272 = (int)v271->GetAbsBounds(this: v271, a2: -1);
      v273 = &v348;
      v274 = (_DWORD *)(v272 - 4);
      for ( i = 6; i != 0; --i )
        *++v273 = *++v274;
      v349.b[0].x = v349.b[0].x - (float)1.0;
      v349.b[0].y = v349.b[0].y - (float)1.0;
      v349.b[0].z = v349.b[0].z - (float)1.0;
      v349.b[1].x = v349.b[1].x + (float)1.0;
      v349.b[1].y = v349.b[1].y + (float)1.0;
      v349.b[1].z = v349.b[1].z + (float)1.0;
      EntitiesTouchingBounds = idClip::GetEntitiesTouchingBounds(
                                 this: &clientGame->clip,
                                 bounds: &v349,
                                 clipMask: 1024,
                                 entityList: v354,
                                 maxCount: 16);
      if ( EntitiesTouchingBounds > 0 )
      {
        v277 = v354;
        for ( j = EntitiesTouchingBounds; j != 0; --j )
        {
          v279 = idAI2::CastTo(c: (idAI2 *)gameLocal->entities.ptr[*v277]);
          if ( v279 != nullptr )
          {
            v280 = this->damages.runOver;
            if ( v280 != nullptr )
            {
              v281 = v279->__vftable;
              v282 = idVehicle::GetDriver(this);
              ((void (__fastcall *)(idAI2 *, idVehicle_Car *, idEntity *, const idDeclDamage *, double))v281->Damage)(
                a1: v279,
                a2: this,
                a3: v282,
                a4: v280,
                a5: 1.0);
              v283 = idEntity::GetPhysics(this: otherEnt);
              v284 = idEntity::GetPhysics(this);
              v285 = ((double (__fastcall *)(idPhysics *, int))v283->GetMass)(a1: v283, a2: -1);
              v286 = (float *)v284->GetLinearVelocity(this: (idPhysics *)&v335, result: (idVec3 *)v284, a3: 0);
              v287 = (float)(v286[1] * (float)v285);
              v288 = (float)(*v286 * (float)v285);
              v289 = (float)(v286[2] * (float)v285);
              v352.x = *v286 * (float)v285;
              v352.y = v287;
              v290 = (float)((float)((float)v289 * (float)v289)
                           + (float)((float)((float)v288 * (float)v288) + (float)((float)v287 * (float)v287)));
              _FP5 = (float)((float)((float)((float)v289 * (float)v289)
                                   + (float)((float)((float)v288 * (float)v288) + (float)((float)v287 * (float)v287)))
                           - idMath::FLT_SMALLEST_NON_DENORMAL);
              v292 = (float)((float)((float)((float)v289 * (float)v289)
                                   + (float)((float)((float)v288 * (float)v288) + (float)((float)v287 * (float)v287)))
                           * (float)0.5);
              __asm { fsel      f3, f5, f6, f0 }
              v294 = __frsqrte(_FP3);
              v295 = (float)-(float)((float)((float)((float)v294
                                                   * (float)((float)((float)((float)v289 * (float)v289)
                                                                   + (float)((float)((float)v288 * (float)v288)
                                                                           + (float)((float)v287 * (float)v287)))
                                                           * (float)0.5))
                                           * (float)v294)
                                   - (float)1.5);
              v352.z = (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)v295 * (float)v294) * (float)v292) * (float)((float)v295 * (float)v294)) - (float)1.5)
                                                                                     * (float)((float)v295 * (float)v294))
                                                                             * (float)v292)
                                                                     * (float)((float)-(float)((float)((float)((float)((float)v295 * (float)v294) * (float)v292) * (float)((float)v295 * (float)v294))
                                                                                             - (float)1.5)
                                                                             * (float)((float)v295 * (float)v294)))
                                                             - (float)1.5)
                                             * (float)((float)-(float)((float)((float)((float)((float)v295 * (float)v294)
                                                                                     * (float)v292)
                                                                             * (float)((float)v295 * (float)v294))
                                                                     - (float)1.5)
                                                     * (float)((float)v295 * (float)v294)))
                                     * (float)v290)
                             * (float)0.25)
                     + (float)v289;
              idAI2::ApplyFakeDamageImpulse(this: v279, impulse: &v352);
            }
          }
          ++v277;
        }
      }
    }
    if ( v237 != nullptr )
    {
      v296 = v237->__vftable;
      v297 = this->damages.vehicle;
      v298 = idVehicle::GetDriver(this);
      ((void (__fastcall *)(idDamageableEntity *, idVehicle_Car *, idEntity *, const idDeclDamage *, double))v296->Damage)(
        a1: v237,
        a2: this,
        a3: v298,
        a4: v297,
        a5: v29);
    }
    goto LABEL_192;
  }
  v239 = (int)v237->GetHealthComponent_2(this: v237);
  if ( v239 != 0 )
  {
    v240 = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v239 + 64))(a1: v239);
    v241 = v237->__vftable;
    v242 = this->damages.vehicle;
    v243 = (float)((float)((float)v240 * (float)0.25) + (float)1.0);
    v244 = idVehicle::GetDriver(this);
    ((void (__fastcall *)(idDamageableEntity *, idVehicle_Car *, idEntity *, const idDeclDamage *, double))v241->Damage)(
      a1: v237,
      a2: this,
      a3: v244,
      a4: v242,
      a5: v243);
  }
  return 0;
}


// ========================================================================
// __unwind$503506
// EA  : 0x82D461A0
// RVA : 0x00D461A0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void _unwind_503506()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 592 + 272));
}


// ========================================================================
// `dynamic initializer for 'vehicle_god''
// EA  : 0x8337DD60
// RVA : 0x0137DD60
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_god__()
{
  idCVar::idCVar(
    this: &vehicle_god,
    name: "vehicle_god",
    value: "0",
    flags: 2,
    description: "1 = player vehicle takes no damage. 2 = all vehicles take no damage.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_god__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_ghostRespawnEffect''
// EA  : 0x8337DDB8
// RVA : 0x0137DDB8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_ghostRespawnEffect__()
{
  idCVar::idCVar(
    this: &vehicle_ghostRespawnEffect,
    name: "vehicle_ghostRespawnEffect",
    value: "2",
    flags: 2,
    description: "type of respawn effect",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_ghostRespawnEffect__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_ghostFadeMin''
// EA  : 0x8337DE10
// RVA : 0x0137DE10
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_ghostFadeMin__()
{
  idCVar::idCVar(
    this: &vehicle_ghostFadeMin,
    name: "vehicle_ghostFadeMin",
    value: "0.1",
    flags: 4,
    description: "ghost fade min value",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_ghostFadeMin__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_ghostFadeMax''
// EA  : 0x8337DE68
// RVA : 0x0137DE68
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_ghostFadeMax__()
{
  idCVar::idCVar(
    this: &vehicle_ghostFadeMax,
    name: "vehicle_ghostFadeMax",
    value: "1",
    flags: 4,
    description: "ghost fade max value",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_ghostFadeMax__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_ghostHighlight''
// EA  : 0x8337DEC0
// RVA : 0x0137DEC0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_ghostHighlight__()
{
  idCVar::idCVar(
    this: &vehicle_ghostHighlight,
    name: "vehicle_ghostHighlight",
    value: "5",
    flags: 2,
    description: "ghost highlight enum  0 - 4",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_ghostHighlight__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_phys_debug''
// EA  : 0x8337DF18
// RVA : 0x0137DF18
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_phys_debug__()
{
  idCVar::idCVar(
    this: &vehicle_phys_debug,
    name: "vehicle_phys_debug",
    value: "0",
    flags: 1,
    description: "shows physics debug info",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_phys_debug__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_af_debug''
// EA  : 0x8337DF70
// RVA : 0x0137DF70
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_af_debug__()
{
  idCVar::idCVar(
    this: &vehicle_af_debug,
    name: "vehicle_af_debug",
    value: "0",
    flags: 1,
    description: "shows ALIGN_TO joint info",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_af_debug__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_always_special_death''
// EA  : 0x8337DFC8
// RVA : 0x0137DFC8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_always_special_death__()
{
  idCVar::idCVar(
    this: &vehicle_always_special_death,
    name: "vehicle_always_special_death",
    value: "0",
    flags: 1,
    description: "always make vehicle deaths use the special death logic",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_always_special_death__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_special_death_chance''
// EA  : 0x8337E020
// RVA : 0x0137E020
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_special_death_chance__()
{
  idCVar::idCVar(
    this: &vehicle_special_death_chance,
    name: "vehicle_special_death_chance",
    value: "0.3",
    flags: 4,
    description: "always make vehicle deaths use the special death logic",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_special_death_chance__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_special_death_chance_mp''
// EA  : 0x8337E078
// RVA : 0x0137E078
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_special_death_chance_mp__()
{
  idCVar::idCVar(
    this: &vehicle_special_death_chance_mp,
    name: "vehicle_special_death_chance_mp",
    value: "0.0",
    flags: 4,
    description: "always make vehicle deaths use the special death logic",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_special_death_chance_mp__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_special_death_minMS''
// EA  : 0x8337E0D0
// RVA : 0x0137E0D0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_special_death_minMS__()
{
  idCVar::idCVar(
    this: &vehicle_special_death_minMS,
    name: "vehicle_special_death_minMS",
    value: "500",
    flags: 2,
    description: "always make vehicle deaths use the special death logic",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_special_death_minMS__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_pitPower''
// EA  : 0x8337E128
// RVA : 0x0137E128
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_pitPower__()
{
  idCVar::idCVar(
    this: &vehicle_pitPower,
    name: "vehicle_pitPower",
    value: "2.0",
    flags: 4,
    description: "power applied to pit maneuver",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_pitPower__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_boostMPH''
// EA  : 0x8337E180
// RVA : 0x0137E180
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_boostMPH__()
{
  idCVar::idCVar(
    this: &vehicle_boostMPH,
    name: "vehicle_boostMPH",
    value: "10",
    flags: 4,
    description: "MPH ( max ) to add when boosting",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_boostMPH__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_boostReverseMPH''
// EA  : 0x8337E1D8
// RVA : 0x0137E1D8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_boostReverseMPH__()
{
  idCVar::idCVar(
    this: &vehicle_boostReverseMPH,
    name: "vehicleReverseMPH",
    value: "50",
    flags: 4,
    description: "MPH ( max ) to subtract when boosting in reverse",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_boostReverseMPH__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_boostDuration''
// EA  : 0x8337E230
// RVA : 0x0137E230
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_boostDuration__()
{
  idCVar::idCVar(
    this: &vehicle_boostDuration,
    name: "vehicle_boostDuration",
    value: "2.0",
    flags: 4,
    description: "boost duration in seconds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_boostDuration__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_boostRecharge''
// EA  : 0x8337E288
// RVA : 0x0137E288
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_boostRecharge__()
{
  idCVar::idCVar(
    this: &vehicle_boostRecharge,
    name: "vehicle_boostRecharge",
    value: "0.5",
    flags: 4,
    description: "boost recharge in seconds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_boostRecharge__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_boostMinLevel''
// EA  : 0x8337E2E0
// RVA : 0x0137E2E0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_boostMinLevel__()
{
  idCVar::idCVar(
    this: &vehicle_boostMinLevel,
    name: "vehicle_boostMinLevel",
    value: ".19",
    flags: 4,
    description: "minimum boost power required to start a new boost ( as a percentage )",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_boostMinLevel__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_boostTorqueMultiplier''
// EA  : 0x8337E338
// RVA : 0x0137E338
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_boostTorqueMultiplier__()
{
  idCVar::idCVar(
    this: &vehicle_boostTorqueMultiplier,
    name: "vehicle_boostTorqueMultiplier",
    value: "1",
    flags: 4,
    description: "boost torque multiplier",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_boostTorqueMultiplier__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_boostPower''
// EA  : 0x8337E390
// RVA : 0x0137E390
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_boostPower__()
{
  idCVar::idCVar(
    this: &vehicle_boostPower,
    name: "vehicle_boostPower",
    value: "800000",
    flags: 4,
    description: "boost force power 100000 is very little, 1000000 is a LOT",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_boostPower__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_boostUseRatio''
// EA  : 0x8337E3E8
// RVA : 0x0137E3E8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_boostUseRatio__()
{
  idCVar::idCVar(
    this: &vehicle_boostUseRatio,
    name: "vehicle_boostUseRatio",
    value: "0",
    flags: 1,
    description: "use the current boost power as a ratio of the vehicle_boostPower",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_boostUseRatio__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_boostDelay''
// EA  : 0x8337E440
// RVA : 0x0137E440
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_boostDelay__()
{
  idCVar::idCVar(
    this: &vehicle_boostDelay,
    name: "vehicle_boostDelay",
    value: "8",
    flags: 4,
    description: "recharge delay",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_boostDelay__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_boostDrain''
// EA  : 0x8337E498
// RVA : 0x0137E498
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_boostDrain__()
{
  idCVar::idCVar(
    this: &vehicle_boostDrain,
    name: "vehicle_boostDrain",
    value: "0",
    flags: 1,
    description: "drain the boost all at once",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_boostDrain__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_boostChargeAmount''
// EA  : 0x8337E4F0
// RVA : 0x0137E4F0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_boostChargeAmount__()
{
  idCVar::idCVar(
    this: &vehicle_boostChargeAmount,
    name: "vehicle_boostChargeAmount",
    value: "0.02",
    flags: 4,
    description: "amount to recharge per vehicle_boostIncrementalRecharge",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_boostChargeAmount__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_boostIncrementalRecharge''
// EA  : 0x8337E548
// RVA : 0x0137E548
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_boostIncrementalRecharge__()
{
  idCVar::idCVar(
    this: &vehicle_boostIncrementalRecharge,
    name: "vehicle_boostIncrementalRecharge",
    value: ".1",
    flags: 4,
    description: "how often to apply vehicle_boostChargeAmount in seconds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_boostIncrementalRecharge__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_boostUpgrade''
// EA  : 0x8337E5A0
// RVA : 0x0137E5A0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_boostUpgrade__()
{
  idCVar::idCVar(
    this: &vehicle_boostUpgrade,
    name: "vehicle_boostUpgrade",
    value: "0",
    flags: 2,
    description: "force boost upgrade level, 1 - 3",
    valueMin: 0.0,
    valueMax: 3.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"DistToTarget: %f dist: %f \n",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_boostUpgrade__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_infiniteBoost''
// EA  : 0x8337E608
// RVA : 0x0137E608
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_infiniteBoost__()
{
  idCVar::idCVar(
    this: &vehicle_infiniteBoost,
    name: "vehicle_infiniteBoost",
    value: "0",
    flags: 1,
    description: "do not remove boost charge if true",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_infiniteBoost__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_extraCollision''
// EA  : 0x8337E660
// RVA : 0x0137E660
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_extraCollision__()
{
  idCVar::idCVar(
    this: &vehicle_extraCollision,
    name: "vehicle_extraCollision",
    value: "1",
    flags: 1,
    description: "adds an extra impulse to vehicle-to-vehicle collisions",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_extraCollision__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_reverseLateralScale''
// EA  : 0x8337E6B8
// RVA : 0x0137E6B8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_reverseLateralScale__()
{
  idCVar::idCVar(
    this: &vehicle_reverseLateralScale,
    name: "vehicle_reverseLateralScale",
    value: "1.5",
    flags: 4,
    description: "lateral friction scaled by this amount when reversing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_reverseLateralScale__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_reverseLongitudinalScale''
// EA  : 0x8337E710
// RVA : 0x0137E710
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_reverseLongitudinalScale__()
{
  idCVar::idCVar(
    this: &vehicle_reverseLongitudinalScale,
    name: "vehicle_reverseLongitudinalScale",
    value: "2.5",
    flags: 4,
    description: "longitudinal friction scaled by this amount when reversing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_reverseLongitudinalScale__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_maximumHeadPositionDelta''
// EA  : 0x8337E768
// RVA : 0x0137E768
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_maximumHeadPositionDelta__()
{
  idCVar::idCVar(
    this: &vehicle_maximumHeadPositionDelta,
    name: "vehicle_maximumHeadPositionDelta",
    value: "100.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_maximumHeadPositionDelta__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_headBobLerpSpeed''
// EA  : 0x8337E7C0
// RVA : 0x0137E7C0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_headBobLerpSpeed__()
{
  idCVar::idCVar(
    this: &vehicle_headBobLerpSpeed,
    name: "vehicle_headBobLerpSpeed",
    value: "0.15",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_headBobLerpSpeed__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_headBobDebug''
// EA  : 0x8337E818
// RVA : 0x0137E818
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_headBobDebug__()
{
  idCVar::idCVar(
    this: &vehicle_headBobDebug,
    name: "vehicle_headBobDebug",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_headBobDebug__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_headBobEnable''
// EA  : 0x8337E870
// RVA : 0x0137E870
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_headBobEnable__()
{
  idCVar::idCVar(
    this: &vehicle_headBobEnable,
    name: "vehicle_headBobEnable",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_headBobEnable__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_useAiProps''
// EA  : 0x8337E8C8
// RVA : 0x0137E8C8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_useAiProps__()
{
  idCVar::idCVar(
    this: &vehicle_useAiProps,
    name: "vehicle_useAiProps",
    value: "0",
    flags: 1,
    description: "Player drives using AI properties",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_useAiProps__);
}


// ========================================================================
// `dynamic initializer for 'v_pitchWarbleRPM''
// EA  : 0x8337E920
// RVA : 0x0137E920
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__v_pitchWarbleRPM__()
{
  idCVar::idCVar(
    this: &v_pitchWarbleRPM,
    name: "v_pitchWarbleRPM",
    value: "0.77",
    flags: 4,
    description: "RPM value when the pitch warbling starts (0-1)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__v_pitchWarbleRPM__);
}


// ========================================================================
// `dynamic initializer for 'v_pitchWarbleMin''
// EA  : 0x8337E978
// RVA : 0x0137E978
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__v_pitchWarbleMin__()
{
  idCVar::idCVar(
    this: &v_pitchWarbleMin,
    name: "v_pitchWarbleMin",
    value: "0",
    flags: 4,
    description: "Minimum pitch shift in semitones (may be negative)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__v_pitchWarbleMin__);
}


// ========================================================================
// `dynamic initializer for 'v_pitchWarbleMax''
// EA  : 0x8337E9D0
// RVA : 0x0137E9D0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__v_pitchWarbleMax__()
{
  idCVar::idCVar(
    this: &v_pitchWarbleMax,
    name: "v_pitchWarbleMax",
    value: "1",
    flags: 4,
    description: "Maximum pitch shift in semitones (may be negative)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__v_pitchWarbleMax__);
}


// ========================================================================
// `dynamic initializer for 'v_pitchWarbleTime''
// EA  : 0x8337EA28
// RVA : 0x0137EA28
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__v_pitchWarbleTime__()
{
  idCVar::idCVar(
    this: &v_pitchWarbleTime,
    name: "v_pitchWarbleTime",
    value: "666",
    flags: 4,
    description: "Length of a single warble in milliseconds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__v_pitchWarbleTime__);
}


// ========================================================================
// `dynamic initializer for 'v_pitchWarbleAir''
// EA  : 0x8337EA80
// RVA : 0x0137EA80
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__v_pitchWarbleAir__()
{
  idCVar::idCVar(
    this: &v_pitchWarbleAir,
    name: "v_pitchWarbleAir",
    value: "0.5",
    flags: 4,
    description: "Pitch shift when in the air",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__v_pitchWarbleAir__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_tireWobbleTest''
// EA  : 0x8337EAD8
// RVA : 0x0137EAD8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_tireWobbleTest__()
{
  idCVar::idCVar(
    this: &vehicle_tireWobbleTest,
    name: "vehicle_tireWobbleTest",
    value: "-1",
    flags: 4,
    description: "Tire wobble testing ( -1 = disabled, 1 = max damage )",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_tireWobbleTest__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_maxCgLocation''
// EA  : 0x8337EB30
// RVA : 0x0137EB30
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_maxCgLocation__()
{
  idCVar::idCVar(
    this: &vehicle_maxCgLocation,
    name: "vehicle_maxCgLocation",
    value: "0",
    flags: 4,
    description: "dynamic cg.z location, for atv",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_maxCgLocation__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_playNonCombatMusic''
// EA  : 0x8337EB88
// RVA : 0x0137EB88
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_playNonCombatMusic__()
{
  idCVar::idCVar(
    this: &vehicle_playNonCombatMusic,
    name: "vehicle_playNonCombatMusic",
    value: "0",
    flags: 1,
    description: "If true we play music when in the car in the wasteland when not in combat",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_playNonCombatMusic__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_damageScale_player''
// EA  : 0x8337EBE0
// RVA : 0x0137EBE0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_damageScale_player__()
{
  idCVar::idCVar(
    this: &vehicle_damageScale_player,
    name: "vehicle_damageScale_player",
    value: "1",
    flags: 4,
    description: "scale applied to all damage done to the player's vehicle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_damageScale_player__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_showSpeed''
// EA  : 0x8337EC38
// RVA : 0x0137EC38
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_showSpeed__()
{
  idCVar::idCVar(
    this: &vehicle_showSpeed,
    name: "vehicle_showSpeed",
    value: "0",
    flags: 1,
    description: "Show vehicle speed info.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_showSpeed__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_breakableFadeOut''
// EA  : 0x8337EC90
// RVA : 0x0137EC90
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_breakableFadeOut__()
{
  idCVar::idCVar(
    this: &vehicle_breakableFadeOut,
    name: "vehicle_breakableFadeOut",
    value: "5.0",
    flags: 4,
    description: "time ( in seconds ) for the breakable to hide after a car is destroyed.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_breakableFadeOut__);
}


// ========================================================================
// `dynamic initializer for 'veh_ignoreCollide''
// EA  : 0x8337ECE8
// RVA : 0x0137ECE8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__veh_ignoreCollide__()
{
  idCVar::idCVar(
    this: &veh_ignoreCollide,
    name: "veh_ignoreCollide",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__veh_ignoreCollide__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_maxRCCarDrops''
// EA  : 0x8337ED40
// RVA : 0x0137ED40
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_maxRCCarDrops__()
{
  idCVar::idCVar(
    this: &vehicle_maxRCCarDrops,
    name: "vehicle_maxRCCarDrops",
    value: "5",
    flags: 2,
    description: "the max number of RC cars the player can drop before they start to be removed",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_maxRCCarDrops__);
}


// ========================================================================
// `dynamic initializer for 'g_recordVehicleTrace''
// EA  : 0x8337ED98
// RVA : 0x0137ED98
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_recordVehicleTrace__()
{
  idCVar::idCVar(
    this: &g_recordVehicleTrace,
    name: "g_recordVehicleTrace",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_recordVehicleTrace__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_ghostTime''
// EA  : 0x8337EDF0
// RVA : 0x0137EDF0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_ghostTime__()
{
  idCVar::idCVar(
    this: &vehicle_ghostTime,
    name: "vehicle_ghostTime",
    value: "0",
    flags: 4,
    description: "force player vehicle to become ghosted for the time (in secs) entered",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_ghostTime__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_cam_breath_enable''
// EA  : 0x8337EE48
// RVA : 0x0137EE48
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_cam_breath_enable__()
{
  idCVar::idCVar(
    this: &vehicle_cam_breath_enable,
    name: "vehicle_cam_breath_enable",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_cam_breath_enable__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_cam_breath_ang''
// EA  : 0x8337EEA0
// RVA : 0x0137EEA0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_cam_breath_ang__()
{
  idCVar::idCVar(
    this: &vehicle_cam_breath_ang,
    name: "vehicle_cam_breath_ang",
    value: "5.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_cam_breath_ang__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_cam_breath_lerp''
// EA  : 0x8337EEF8
// RVA : 0x0137EEF8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_cam_breath_lerp__()
{
  idCVar::idCVar(
    this: &vehicle_cam_breath_lerp,
    name: "vehicle_cam_breath_lerp",
    value: "0.0035",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_cam_breath_lerp__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_cam_breath_min_freq''
// EA  : 0x8337EF50
// RVA : 0x0137EF50
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_cam_breath_min_freq__()
{
  idCVar::idCVar(
    this: &vehicle_cam_breath_min_freq,
    name: "vehicle_cam_breath_min_freq",
    value: "300",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_cam_breath_min_freq__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_cam_breath_max_freq''
// EA  : 0x8337EFA8
// RVA : 0x0137EFA8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_cam_breath_max_freq__()
{
  idCVar::idCVar(
    this: &vehicle_cam_breath_max_freq,
    name: "vehicle_cam_breath_max_freq",
    value: "800",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_cam_breath_max_freq__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_reverseBoost''
// EA  : 0x8337F000
// RVA : 0x0137F000
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_reverseBoost__()
{
  idCVar::idCVar(
    this: &vehicle_reverseBoost,
    name: "vehicle_reverseBoost",
    value: "2",
    flags: 4,
    description: "reverse boost multiplier",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_reverseBoost__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_reverseBoostTriggerTime''
// EA  : 0x8337F058
// RVA : 0x0137F058
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_reverseBoostTriggerTime__()
{
  idCVar::idCVar(
    this: &vehicle_reverseBoostTriggerTime,
    name: "vehicle_reverseBoostTriggerTime",
    value: "250",
    flags: 2,
    description: "time between trigger actions to activate reverse boost",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_reverseBoostTriggerTime__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_exhaust_velocityscale''
// EA  : 0x8337F0B0
// RVA : 0x0137F0B0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_exhaust_velocityscale__()
{
  idCVar::idCVar(
    this: &vehicle_exhaust_velocityscale,
    name: "vehicle_exhaust_velocityscale",
    value: "0.0",
    flags: 4,
    description: "amount the smoke system speed is scaled by for particle system",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_exhaust_velocityscale__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_debugSurfaceSounds''
// EA  : 0x8337F108
// RVA : 0x0137F108
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_debugSurfaceSounds__()
{
  idCVar::idCVar(
    this: &vehicle_debugSurfaceSounds,
    name: "vehicle_debugSurfaceSounds",
    value: "0",
    flags: 1,
    description: "debug surface sounds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_debugSurfaceSounds__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_angularScale''
// EA  : 0x8337F160
// RVA : 0x0137F160
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_angularScale__()
{
  idCVar::idCVar(
    this: &vehicle_angularScale,
    name: "vehicle_angularScale",
    value: "-1",
    flags: 4,
    description: "Angular force added to vehicle due to player control",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_angularScale__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_angularScale_air''
// EA  : 0x8337F1B8
// RVA : 0x0137F1B8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_angularScale_air__()
{
  idCVar::idCVar(
    this: &vehicle_angularScale_air,
    name: "vehicle_angularScale_air",
    value: "-1",
    flags: 4,
    description: "Angular force added to vehicle (in air) due to player control",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_angularScale_air__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_velocityScale''
// EA  : 0x8337F210
// RVA : 0x0137F210
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_velocityScale__()
{
  idCVar::idCVar(
    this: &vehicle_velocityScale,
    name: "vehicle_velocityScale",
    value: "-1",
    flags: 4,
    description: "Velocity force added to vehicle due to player control",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_velocityScale__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_velocityScale_air''
// EA  : 0x8337F268
// RVA : 0x0137F268
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_velocityScale_air__()
{
  idCVar::idCVar(
    this: &vehicle_velocityScale_air,
    name: "vehicle_velocityScale_air",
    value: "-1",
    flags: 4,
    description: "Velocity force added to vehicle (in air) due to player control",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_velocityScale_air__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_enhanceStickControl''
// EA  : 0x8337F2C0
// RVA : 0x0137F2C0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_enhanceStickControl__()
{
  idCVar::idCVar(
    this: &vehicle_enhanceStickControl,
    name: "vehicle_enhanceStickControl",
    value: "1",
    flags: 1,
    description: "Adds linear / angular velocity based on controller stick.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_enhanceStickControl__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_massiveCollisionForce''
// EA  : 0x8337F318
// RVA : 0x0137F318
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_massiveCollisionForce__()
{
  idCVar::idCVar(
    this: &vehicle_massiveCollisionForce,
    name: "vehicle_massiveCollisionForce",
    value: "150000",
    flags: 4,
    description: "Force considered massive",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_massiveCollisionForce__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_ignoreCollisionVelocity''
// EA  : 0x8337F370
// RVA : 0x0137F370
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_ignoreCollisionVelocity__()
{
  idCVar::idCVar(
    this: &vehicle_ignoreCollisionVelocity,
    name: "vehicle_ignoreCollisionVelocity",
    value: "650",
    flags: 4,
    description: "Minimum velocity for a vehicle to ignore a collision with a specific object type",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_ignoreCollisionVelocity__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_towerImpulseMagnitude''
// EA  : 0x8337F3C8
// RVA : 0x0137F3C8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_towerImpulseMagnitude__()
{
  idCVar::idCVar(
    this: &vehicle_towerImpulseMagnitude,
    name: "vehicle_towerImpulseMagnitude",
    value: "80",
    flags: 4,
    description: "Magnitude of impulse to apply from vehicles to towers",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_towerImpulseMagnitude__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_aiThrowChance''
// EA  : 0x8337F420
// RVA : 0x0137F420
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_aiThrowChance__()
{
  idCVar::idCVar(
    this: &vehicle_aiThrowChance,
    name: "vehicle_aiThrowChance",
    value: "20",
    flags: 2,
    description: "Change of throwing an AI struck by the player vehicle back toward the camera",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_aiThrowChance__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_ignoreCollisionForceSpeed''
// EA  : 0x8337F478
// RVA : 0x0137F478
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_ignoreCollisionForceSpeed__()
{
  idCVar::idCVar(
    this: &vehicle_ignoreCollisionForceSpeed,
    name: "vehicle_ignoreCollisionForceSpeed",
    value: "30",
    flags: 4,
    description: "Speed in MPH where to ignore collision impulses from obstacles",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_ignoreCollisionForceSpeed__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_damageScale_playerBoostCollision''
// EA  : 0x8337F4D0
// RVA : 0x0137F4D0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_damageScale_playerBoostCollision__()
{
  idCVar::idCVar(
    this: &vehicle_damageScale_playerBoostCollision,
    name: "vehicle_damageScale_playerBoostCollision",
    value: "1.1",
    flags: 4,
    description: "Additional damage applied to 'other' vehicle when boosting during collision.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_damageScale_playerBoostCollision__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_damageScale_playerHitsAi''
// EA  : 0x8337F528
// RVA : 0x0137F528
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_damageScale_playerHitsAi__()
{
  idCVar::idCVar(
    this: &vehicle_damageScale_playerHitsAi,
    name: "vehicle_damageScale_playerHitsAi",
    value: "2",
    flags: 4,
    description: "Additional damage applied to ai vehicle by player vehicle during collision.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_damageScale_playerHitsAi__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_damageScale_base''
// EA  : 0x8337F580
// RVA : 0x0137F580
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_damageScale_base__()
{
  idCVar::idCVar(
    this: &vehicle_damageScale_base,
    name: "vehicle_damageScale_base",
    value: "160",
    flags: 4,
    description: "applied to base damageScale. base damage scale = ( mph/80 ) * Square( cos( impactAngle ) )",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_damageScale_base__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_damageScale_normalLanding''
// EA  : 0x8337F5D8
// RVA : 0x0137F5D8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_damageScale_normalLanding__()
{
  idCVar::idCVar(
    this: &vehicle_damageScale_normalLanding,
    name: "vehicle_damageScale_normalLanding",
    value: "0",
    flags: 4,
    description: "applied to damage when colliding with ground on wheels (reduces damage)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_damageScale_normalLanding__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_damageScale_normalLanding_angle''
// EA  : 0x8337F630
// RVA : 0x0137F630
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_damageScale_normalLanding_angle__()
{
  idCVar::idCVar(
    this: &vehicle_damageScale_normalLanding_angle,
    name: "vehicle_damageScale_normalLanding_angle",
    value: "30",
    flags: 4,
    description: "angle that determines a 'normal' landing (minimal damage) on the ground",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_damageScale_normalLanding_angle__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_damagescale_overturned_angle''
// EA  : 0x8337F688
// RVA : 0x0137F688
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_damagescale_overturned_angle__()
{
  idCVar::idCVar(
    this: &vehicle_damagescale_overturned_angle,
    name: "vehicle_damagescale_overturned_angle",
    value: "80",
    flags: 4,
    description: "angle that determines when vehicle has overturned",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_damagescale_overturned_angle__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_showDamageValues''
// EA  : 0x8337F6E0
// RVA : 0x0137F6E0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_showDamageValues__()
{
  idCVar::idCVar(
    this: &vehicle_showDamageValues,
    name: "vehicle_showDamageValues",
    value: "0",
    flags: 2,
    description: "show damage values in console  1=only player vehicle, 2=any vehicle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_showDamageValues__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_DMG''
// EA  : 0x8337F738
// RVA : 0x0137F738
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_DMG__()
{
  idCVar::idCVar(
    this: &vehicle_DMG,
    name: "vehicle_DMG",
    value: "0",
    flags: 1,
    description: "show damage values in console",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_DMG__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_damageScale_aiSandwich''
// EA  : 0x8337F790
// RVA : 0x0137F790
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_damageScale_aiSandwich__()
{
  idCVar::idCVar(
    this: &vehicle_damageScale_aiSandwich,
    name: "vehicle_damageScale_aiSandwich",
    value: "1.25",
    flags: 4,
    description: "Damage scaled by this amount when AI is taking damage on both left/right sides",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_damageScale_aiSandwich__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_contactMoveableForce''
// EA  : 0x8337F7E8
// RVA : 0x0137F7E8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_contactMoveableForce__()
{
  idCVar::idCVar(
    this: &vehicle_contactMoveableForce,
    name: "vehicle_contactMoveableForce",
    value: "4000",
    flags: 4,
    description: "minimum force to apply to moveables to avoid getting stuck",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_contactMoveableForce__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_damageGiven_frac''
// EA  : 0x8337F840
// RVA : 0x0137F840
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_damageGiven_frac__()
{
  idCVar::idCVar(
    this: &vehicle_damageGiven_frac,
    name: "vehicle_damageGiven_frac",
    value: "1",
    flags: 4,
    description: "based on force of collision",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_damageGiven_frac__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_damageTaken_frac''
// EA  : 0x8337F898
// RVA : 0x0137F898
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_damageTaken_frac__()
{
  idCVar::idCVar(
    this: &vehicle_damageTaken_frac,
    name: "vehicle_damageTaken_frac",
    value: ".5",
    flags: 4,
    description: "base on force of collision",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_damageTaken_frac__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_online_environment_dmg''
// EA  : 0x8337F8F0
// RVA : 0x0137F8F0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_online_environment_dmg__()
{
  idCVar::idCVar(
    this: &vehicle_online_environment_dmg,
    name: "vehicle_online_environment_dmg",
    value: "0",
    flags: 1,
    description: "Enable damage vs environment",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_online_environment_dmg__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_online_nextCollisionTime''
// EA  : 0x8337F948
// RVA : 0x0137F948
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_online_nextCollisionTime__()
{
  idCVar::idCVar(
    this: &vehicle_online_nextCollisionTime,
    name: "vehicle_online_nextCollisionTime",
    value: "750",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_online_nextCollisionTime__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_online_mph_damage''
// EA  : 0x8337F9A0
// RVA : 0x0137F9A0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_online_mph_damage__()
{
  idCVar::idCVar(
    this: &vehicle_online_mph_damage,
    name: "vehicle_online_mph_damage",
    value: "11",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_online_mph_damage__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_online_damageScale_base''
// EA  : 0x8337F9F8
// RVA : 0x0137F9F8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_online_damageScale_base__()
{
  idCVar::idCVar(
    this: &vehicle_online_damageScale_base,
    name: "vehicle_online_damageScale_base",
    value: "40",
    flags: 4,
    description: "applied to base damageScale. base damage scale = ( mph/80 ) * Square( cos( impactAngle ) ) (ONLINE VERSION)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_online_damageScale_base__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_online_damageScale_playerBoostCollision''
// EA  : 0x8337FA50
// RVA : 0x0137FA50
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_online_damageScale_playerBoostCollision__()
{
  idCVar::idCVar(
    this: &vehicle_online_damageScale_playerBoostCollision,
    name: "vehicle_online_damageScale_playerBoostCollision",
    value: "2",
    flags: 4,
    description: "Additional damage applied to 'other' vehicle when boosting during collision. (ONLINE VERSION)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_online_damageScale_playerBoostCollision__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_online_damageScale_friendlyCollision''
// EA  : 0x8337FAA8
// RVA : 0x0137FAA8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_online_damageScale_friendlyCollision__()
{
  idCVar::idCVar(
    this: &vehicle_online_damageScale_friendlyCollision,
    name: "vehicle_online_damageScale_friendlyCollision",
    value: "0.20",
    flags: 4,
    description: "Damage scale applied to 'other' vehicle during collision with friendly vehicle. (ONLINE VERSION)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_online_damageScale_friendlyCollision__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_online_mph_dmg_upperBound''
// EA  : 0x8337FB00
// RVA : 0x0137FB00
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_online_mph_dmg_upperBound__()
{
  idCVar::idCVar(
    this: &vehicle_online_mph_dmg_upperBound,
    name: "vehicle_online_mph_dmg_upperBound",
    value: "80.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_online_mph_dmg_upperBound__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_online_mph_dmg_lowerBound''
// EA  : 0x8337FB58
// RVA : 0x0137FB58
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_online_mph_dmg_lowerBound__()
{
  idCVar::idCVar(
    this: &vehicle_online_mph_dmg_lowerBound,
    name: "vehicle_online_mph_dmg_lowerBound",
    value: "35.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_online_mph_dmg_lowerBound__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_playerNoDie''
// EA  : 0x8337FBB0
// RVA : 0x0137FBB0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_playerNoDie__()
{
  idCVar::idCVar(
    this: &vehicle_playerNoDie,
    name: "vehicle_playerNoDie",
    value: "0",
    flags: 1,
    description: "Player and vehicle doesn't die when out of health.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_playerNoDie__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_rcbombforce''
// EA  : 0x8337FC08
// RVA : 0x0137FC08
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_rcbombforce__()
{
  idCVar::idCVar(
    this: &vehicle_rcbombforce,
    name: "vehicle_rcbombforce",
    value: "500",
    flags: 4,
    description: "rcbomb explosion force scale",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_rcbombforce__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_damageScale_violentRoll_player''
// EA  : 0x8337FC60
// RVA : 0x0137FC60
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_damageScale_violentRoll_player__()
{
  idCVar::idCVar(
    this: &vehicle_damageScale_violentRoll_player,
    name: "vehicle_damageScale_violentRoll_player",
    value: "1",
    flags: 4,
    description: "damage applied to violent rolls (player driver)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_damageScale_violentRoll_player__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_damageScale_violentRoll_ai''
// EA  : 0x8337FCB8
// RVA : 0x0137FCB8
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_damageScale_violentRoll_ai__()
{
  idCVar::idCVar(
    this: &vehicle_damageScale_violentRoll_ai,
    name: "vehicle_damageScale_violentRoll_ai",
    value: "6",
    flags: 4,
    description: "damage applied to violent rolls (ai driver)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_damageScale_violentRoll_ai__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_damagescale_overturned_player''
// EA  : 0x8337FD10
// RVA : 0x0137FD10
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_damagescale_overturned_player__()
{
  idCVar::idCVar(
    this: &vehicle_damagescale_overturned_player,
    name: "vehicle_damagescale_overturned_player",
    value: "4",
    flags: 4,
    description: "damage scale for player's vehicle that's upside down",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_damagescale_overturned_player__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_damagescale_overturned_ai''
// EA  : 0x8337FD68
// RVA : 0x0137FD68
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_damagescale_overturned_ai__()
{
  idCVar::idCVar(
    this: &vehicle_damagescale_overturned_ai,
    name: "vehicle_damagescale_overturned_ai",
    value: "12",
    flags: 4,
    description: "damage scale for player's vehicle that's upside down",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_damagescale_overturned_ai__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_death_impulse''
// EA  : 0x8337FDC0
// RVA : 0x0137FDC0
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_death_impulse__()
{
  idCVar::idCVar(
    this: &vehicle_death_impulse,
    name: "vehicle_death_impulse",
    value: "1300",
    flags: 4,
    description: "scale for impulse death",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_death_impulse__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_online_damagescale_overturned_player''
// EA  : 0x8337FE18
// RVA : 0x0137FE18
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_online_damagescale_overturned_player__()
{
  idCVar::idCVar(
    this: &vehicle_online_damagescale_overturned_player,
    name: "vehicle_online_damagescale_overturned_player",
    value: "1",
    flags: 4,
    description: "damage scale for player's vehicle that's upside down (ONLINE VERSION)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_online_damagescale_overturned_player__);
}


// ========================================================================
// `dynamic initializer for 'rcbomb_rotationSoundEpsilon''
// EA  : 0x8337FE70
// RVA : 0x0137FE70
// PDB : w:\tech5\tungsten\game\entities\vehicle_car.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rcbomb_rotationSoundEpsilon__()
{
  idCVar::idCVar(
    this: &rcbomb_rotationSoundEpsilon,
    name: "rcbomb_rotationSoundEpsilon",
    value: "0.25",
    flags: 4,
    description: "angles must change more then this in a frame to make sound",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rcbomb_rotationSoundEpsilon__);
}

