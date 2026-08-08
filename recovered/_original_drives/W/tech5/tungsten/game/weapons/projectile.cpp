
// ========================================================================
// ?DeactivatePhysics@idProjectile@@UAAXH@Z
// EA  : 0x82ECEE60
// RVA : 0x00ECEE60
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

// attributes: thunk
void __fastcall idProjectile::DeactivatePhysics(idProjectile *this, int physId)
{
  idEntity::DeactivatePhysics(this, physId);
}


// ========================================================================
// ?Collide@idProjectile@@UAA?AW4collide_t@@HAAUtrace_t@@ABVidVec3@@@Z
// EA  : 0x82ECEE68
// RVA : 0x00ECEE68
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

int __fastcall idProjectile::Collide(
        idProjectile *this,
        const int physId,
        trace_t *collision,
        const idVec3 *velocity,
        __int64 a5,
        __int64 a6)
{
  LODWORD(a6) = collision->c.surfaceFlags & 1;
  if ( (_DWORD)a6 != 0 )
  {
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0, a4: (int)velocity, a5, a6);
    return 1;
  }
  else
  {
    ++this->collisionCount;
    return idLobbyBackend360::StartArbitration(pexcept: (_exception *)this);
  }
}


// ========================================================================
// ?ApplyWaterSplashEffects@idProjectile_Rocket@@MAAXHHW4surfTypes_t@@W4splashState_t@idPhysicsCallbacks@@@Z
// EA  : 0x82ECEEC8
// RVA : 0x00ECEEC8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Rocket::ApplyWaterSplashEffects(
        idProjectile_Rocket *this,
        const int physId,
        const int bodyId,
        surfTypes_t surfOverride,
        idPhysicsCallbacks::splashState_t splashState)
{
  this->isInWater = true;
}


// ========================================================================
// ?Use@idProjectile_Arrow@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82ECEED8
// RVA : 0x00ECEED8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

int __fastcall idProjectile_Arrow::Use(idProjectile_Arrow *this, idPlayer *activator, const usableState_t usable)
{
  idPlayer *v4; // r30
  idPhysics *Physics; // r3
  const idVec3 *v6; // r3

  v4 = idPlayer::CastTo(c: activator);
  if ( v4 == nullptr )
    return 0;
  Physics = idEntity::GetPhysics(this);
  v6 = Physics->GetOrigin(this: Physics, a2: 0);
  return idPlayer::PickupItems(this: v4, inventoryDecl: this->inventoryItem, location: v6);
}


// ========================================================================
// ?Spawn@idProjectile_EventPulser@@QAAXXZ
// EA  : 0x82ECEF50
// RVA : 0x00ECEF50
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_EventPulser::Spawn(idProjectile_EventPulser *this)
{
  if ( this->eventClassDecl == nullptr )
    idLib::Warning(fmt: "Event Pulser spawned without a valid eventClassDecl");
}


// ========================================================================
// ??0idProjectile@@QAA@XZ
// EA  : 0x82ECF2C0
// RVA : 0x00ECF2C0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

idProjectile *__fastcall idProjectile::idProjectile(idProjectile *this)
{
  int v2; // ctr
  float *p_y; // r10
  float *p_z; // r9

  idAnimatedEntity::idAnimatedEntity(this);
  this->causesDirectDamage = true;
  this->__vftable = (idProjectile_vtbl *)&idProjectile::`vftable';
  idAnimator_Channel::idAnimator_Channel(this: &this->propAnimator);
  *(_WORD *)&this->alignToVelocity = 1;
  this->startHidden = false;
  this->projectileDecl = nullptr;
  this->touchTriggers = false;
  this->adjustStartForCollision = false;
  this->rotationOffset.pitch = 0.0;
  this->rotationOffset.yaw = 0.0;
  this->rotationOffset.roll = 0.0;
  v2 = 9;
  this->rotationSpeed.pitch = 0.0;
  p_y = &mat2_identity.mat[1].y;
  this->rotationSpeed.yaw = 0.0;
  this->rotationSpeed.roll = 0.0;
  this->collisionZapsRotation = false;
  this->minAngularVelocity.x = 0.0;
  this->minAngularVelocity.y = 0.0;
  this->minAngularVelocity.z = 0.0;
  this->maxAngularVelocity.x = 0.0;
  this->maxAngularVelocity.y = 0.0;
  this->maxAngularVelocity.z = 0.0;
  this->collisionCount = 0;
  this->electricDischarged = false;
  this->acceleration = 100.0;
  this->aiEventHandle.value = -1;
  p_z = &this->lastVel.z;
  this->lastVel = vec3_origin;
  do
  {
    *++p_z = *++p_y;
    --v2;
  }
  while ( v2 != 0 );
  this->launchWeapon = nullptr;
  this->fadeStartTime = 0;
  this->fadeEndTime = 0;
  this->weaponStatsTag = 0;
  this->startInfluenceTrail = -1;
  this->surfTypeLastHit = 0;
  this->damageScale = 1.0;
  this->surfNormalLastHit = vec3_up;
  idEntity::SetClipReplicationFlags(this, dynamicClipReplication: true, dynamicClipReplicationAxis: true);
  return this;
}


// ========================================================================
// __unwind$493747
// EA  : 0x82ECF440
// RVA : 0x00ECF440
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_493747()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$493748_0
// EA  : 0x82ECF468
// RVA : 0x00ECF468
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_493748_0()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 144 + 164) + 5204));
}


// ========================================================================
// ?AllocPresentable@idProjectile@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82ECF4C0
// RVA : 0x00ECF4C0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

idPresentableProjectile *__fastcall idProjectile::AllocPresentable(idProjectile *this, idRenderModel *renderModel_)
{
  idPresentableProjectile *v4; // r29
  idAnimStack *v5; // r3

  v4 = (idPresentableProjectile *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x580u,
                                    tag: TAG_PRESENTABLE,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  if ( v4 == nullptr )
    return nullptr;
  v5 = this->GetAnimStack_2(this);
  return idPresentableProjectile::idPresentableProjectile(this: v4, ent: this, renderModel_, animStack_: v5);
}


// ========================================================================
// __unwind$494046_0
// EA  : 0x82ECF548
// RVA : 0x00ECF548
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_494046_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?GetModelTransform@idProjectile@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82ECF578
// RVA : 0x00ECF578
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile::GetModelTransform(idProjectile *this, idVec3 *modelOrigin, idMat3 *modelAxis)
{
  idPhysics *Physics; // r3
  double v6; // fp0
  double v7; // fp13
  float *v8; // r3
  double v9; // fp13
  BOOL collisionZapsRotation; // r8
  double v11; // fp12
  double v12; // fp11
  double v13; // fp10
  double v14; // fp9
  double v15; // fp8
  double v16; // fp7
  double v17; // fp6
  double v18; // fp28
  double v19; // fp31
  double v20; // fp27
  __int64 v21; // r10
  const idMat3 *v22; // r3
  float *v23; // r3
  double v24; // fp10
  double v25; // fp9
  double v26; // fp8
  double v27; // fp31
  double v28; // fp30
  double v29; // fp29
  double v30; // fp7
  double v31; // fp6
  double v32; // fp5
  __int64 v33; // r8
  double v34; // fp4
  const idMat3 *v35; // r3
  __int64 v36; // r7
  double v37; // fp11
  const idMat3 *v38; // r3
  double y; // fp3
  double z; // fp0
  float pitch; // [sp+50h] [-130h]
  float yaw; // [sp+54h] [-12Ch]
  float roll; // [sp+58h] [-128h]
  idMat3 v44; // [sp+60h] [-120h] BYREF
  float v45; // [sp+88h] [-F8h] BYREF
  float v46; // [sp+8Ch] [-F4h]
  float v47; // [sp+90h] [-F0h]
  idRotation v48; // [sp+A0h] [-E0h] BYREF
  idMat3 v49[2]; // [sp+F0h] [-90h] BYREF

  idAnimatedEntity::GetModelTransform(this, modelOrigin, modelAxis);
  if ( this->alignToVelocity )
  {
    Physics = idEntity::GetPhysics(this);
    Physics->GetLinearVelocity(this: (idPhysics *)&v45, result: (idVec3 *)Physics, a3: 0);
    if ( !idEntity::IsBound(this) )
    {
      v6 = v47;
      v7 = v46;
      if ( (float)((float)(v45 * v45) + (float)((float)(v46 * v46) + (float)(v47 * v47))) > 0.1 )
      {
        this->lastVel.x = v45;
        this->lastVel.y = v7;
        this->lastVel.z = v6;
      }
    }
    if ( (float)((float)(this->lastVel.z * this->lastVel.z)
               + (float)((float)(this->lastVel.x * this->lastVel.x) + (float)(this->lastVel.y * this->lastVel.y))) >= 0.1 )
    {
      idVec3::NormalizeFast(this: &this->lastVel);
      v8 = (float *)idVec3::ToMat3(this: v44.mat, result: (idMat3 *)&this->lastVel);
      v9 = v8[1];
      collisionZapsRotation = this->collisionZapsRotation;
      v11 = v8[2];
      v12 = v8[3];
      v13 = v8[4];
      v14 = v8[5];
      pitch = this->rotationSpeed.pitch;
      v15 = v8[6];
      yaw = this->rotationSpeed.yaw;
      v16 = v8[7];
      roll = this->rotationSpeed.roll;
      v17 = v8[8];
      v44.mat[0].x = *v8;
      v44.mat[0].y = v9;
      v44.mat[0].z = v11;
      v44.mat[1].x = v12;
      v44.mat[1].y = v13;
      v44.mat[1].z = v14;
      v44.mat[2].x = v15;
      v44.mat[2].y = v16;
      v44.mat[2].z = v17;
      if ( collisionZapsRotation && this->collisionCount > 0 )
      {
        v18 = 0.0;
        v19 = 0.0;
        v20 = 0.0;
      }
      else
      {
        v20 = roll;
        v19 = yaw;
        v18 = pitch;
      }
      LODWORD(v21) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idRotation::idRotation(
        this: &v48,
        rotationOrigin: &vec3_origin,
        rotationVec: &v44.mat[2],
        rotationAngle: (float)((float)((float)v21 * (float)v19) + this->rotationOffset.yaw));
      v22 = idRotation::ToMat3(this: &v48);
      v23 = (float *)idMat3::operator*(this: v49, result: &v44, a: v22);
      v24 = *v23;
      v25 = v23[1];
      v26 = v23[2];
      v27 = v23[3];
      v28 = v23[4];
      v29 = v23[5];
      v30 = v23[6];
      v31 = v23[7];
      v32 = v23[8];
      v44.mat[1].x = v23[3];
      v44.mat[1].y = v28;
      v44.mat[1].z = v29;
      v44.mat[0].x = v24;
      v44.mat[0].y = v25;
      v44.mat[0].z = v26;
      v44.mat[2].x = v30;
      v44.mat[2].y = v31;
      v44.mat[2].z = v32;
      LODWORD(v33) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v34 = this->rotationOffset.pitch;
      v48.origin.x = vec3_origin.x;
      v48.origin.y = vec3_origin.y;
      v48.axisValid = false;
      v48.origin.z = vec3_origin.z;
      v48.vec.x = v27;
      v48.vec.y = v28;
      v48.vec.z = v29;
      v48.angle = (float)((float)v33 * (float)v18) + (float)v34;
      v35 = idRotation::ToMat3(this: &v48);
      idMat3::operator*=(this: &v44, a: v35);
      LODWORD(v36) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v37 = this->rotationOffset.roll;
      v48.axisValid = false;
      v48.origin.y = vec3_origin.y;
      v48.origin.x = vec3_origin.x;
      v48.origin.z = vec3_origin.z;
      v48.vec.x = v44.mat[0].x;
      v48.vec.y = v44.mat[0].y;
      v48.vec.z = v44.mat[0].z;
      v48.angle = (float)((float)v36 * (float)v20) + (float)v37;
      v38 = idRotation::ToMat3(this: &v48);
      idMat3::operator*=(this: &v44, a: v38);
      modelAxis->mat[0].x = v44.mat[0].x;
      y = v44.mat[0].y;
      z = v44.mat[0].z;
      modelAxis->mat[1].x = v44.mat[1].x;
      modelAxis->mat[0].y = y;
      modelAxis->mat[0].z = z;
      modelAxis->mat[1].y = v44.mat[1].y;
      modelAxis->mat[1].z = v44.mat[1].z;
      modelAxis->mat[2] = v44.mat[2];
      this->lastModelAxis.mat[0].x = modelAxis->mat[0].x;
      this->lastModelAxis.mat[0].y = modelAxis->mat[0].y;
      this->lastModelAxis.mat[0].z = modelAxis->mat[0].z;
      this->lastModelAxis.mat[1].x = modelAxis->mat[1].x;
      this->lastModelAxis.mat[1].y = modelAxis->mat[1].y;
      this->lastModelAxis.mat[1].z = modelAxis->mat[1].z;
      this->lastModelAxis.mat[2].x = modelAxis->mat[2].x;
      this->lastModelAxis.mat[2].y = modelAxis->mat[2].y;
      this->lastModelAxis.mat[2].z = modelAxis->mat[2].z;
    }
  }
}


// ========================================================================
// ?QueueToSimulate@idProjectile@@QAAXH@Z
// EA  : 0x82ECF930
// RVA : 0x00ECF930
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile::QueueToSimulate(idProjectile *this, int startTime, int a3, int a4, int a5)
{
  int v7; // r9
  idProjectile::simulatedProjectile_t *v8; // r11
  int v9; // r9
  int valueInteger; // r11
  int v11; // r3

  v7 = 0;
  v8 = idProjectile::projectilesToSimulate;
  while ( v8->projectile != nullptr )
  {
    ++v8;
    ++v7;
    if ( (int)v8 >= (int)&g_projectileHomingGroundCheck )
    {
      idLib::Warning(fmt: "Unable to simulate more projectiles this frame", startTime, a3, a4, a5);
      return;
    }
  }
  v9 = v7;
  idProjectile::projectilesToSimulate[v9].projectile = this;
  valueInteger = g_projectileDebug.valueInteger;
  idProjectile::projectilesToSimulate[v9].startTime = startTime;
  if ( valueInteger != 0 )
  {
    v11 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idLib::Printf(fmt: "Simulating projectile %d. Approx %d delay.\n", this->entityNumber, v11 - startTime);
  }
}


// ========================================================================
// ?SimulateProjectileFrame@idProjectile@@UAAXHH@Z
// EA  : 0x82ECF9F8
// RVA : 0x00ECF9F8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile::SimulateProjectileFrame(idProjectile *this, int msec, int endTime)
{
  idPhysics *Physics; // r3
  int v7; // r3
  float v8; // r7
  float v9; // r6
  idPhysics *v10; // r3
  idPhysics *v11; // r29
  idPresentable *presentable; // r3
  float *v13; // r31
  float *v14; // r3
  idPhysics *v15; // r3
  idPresentable *v16; // r11
  idPhysics *v17; // r29
  float *v18; // r31
  float *v19; // r3
  idPhysics *v20; // r3
  float *v21; // r3
  idPhysics *v22; // r3
  idRenderWorld *renderWorld; // r31
  idRenderWorld_vtbl *v24; // r30
  int v25; // r3
  double v26; // [sp+20h] [-60h]
  float v27; // [sp+50h] [-30h] BYREF
  float v28; // [sp+54h] [-2Ch]
  float v29; // [sp+58h] [-28h]

  Physics = idEntity::GetPhysics(this);
  v7 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v8 = *(float *)(v7 + 4);
  v9 = *(float *)(v7 + 8);
  v27 = *(float *)v7;
  v28 = v8;
  v29 = v9;
  v10 = idEntity::GetPhysics(this);
  v10->Evaluate(this: v10, a2: msec, a3: endTime);
  v11 = idEntity::GetPhysics(this);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v13 = (float *)presentable->GetProjectileInterface(this: presentable);
  else
    v13 = nullptr;
  v14 = (float *)v11->GetOrigin(this: v11, a2: 0);
  v13[30] = *v14;
  v13[31] = v14[1];
  v13[32] = v14[2];
  v15 = idEntity::GetPhysics(this);
  v16 = this->presentable;
  v17 = v15;
  if ( v16 != nullptr )
    v18 = (float *)v16->GetProjectileInterface(this: this->presentable);
  else
    v18 = nullptr;
  v19 = (float *)v17->GetAxis(this: v17, a2: 0);
  v18[33] = *v19;
  v18[34] = v19[1];
  v18[35] = v19[2];
  v18[36] = v19[3];
  v18[37] = v19[4];
  v18[38] = v19[5];
  v18[39] = v19[6];
  v18[40] = v19[7];
  v18[41] = v19[8];
  if ( g_projectileDebug.valueInteger != 0 )
  {
    v20 = idEntity::GetPhysics(this);
    v21 = (float *)v20->GetOrigin(this: v20, a2: 0);
    v26 = __fsqrts((float)((float)((float)(*v21 - v27) * (float)(*v21 - v27))
                         + (float)((float)((float)(v21[2] - v29) * (float)(v21[2] - v29))
                                 + (float)((float)(v21[1] - v28) * (float)(v21[1] - v28)))));
    idLib::Printf(fmt: "Simulated projectile %d. Delta: %.2f \n", HIDWORD(v26), v26);
    v22 = idEntity::GetPhysics(this);
    renderWorld = clientGame->renderWorld;
    v24 = renderWorld->__vftable;
    v25 = (int)v22->GetOrigin(this: v22, a2: 0);
    v24->DebugLine(
      this: renderWorld,
      a2: (const idVec4 *)&idColor::colorYellow,
      a3: (const idVec3 *)&v27,
      a4: (const idVec3 *)v25,
      a5: 5000,
      a6: false);
  }
}


// ========================================================================
// ?PostSimulate@idProjectile@@UAAXH@Z
// EA  : 0x82ECFC48
// RVA : 0x00ECFC48
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile::PostSimulate(idProjectile *this, int endTime)
{
  idPresentable *presentable; // r3
  idPresentableProjectile *v3; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    v3 = (idPresentableProjectile *)((int (__fastcall *)(idPresentable *, int))presentable->GetProjectileInterface)(
                                      a1: presentable,
                                      a2: endTime);
    idPresentableProjectile::SmoothFromLaunchOriginAxis(this: v3);
  }
  else
  {
    idPresentableProjectile::SmoothFromLaunchOriginAxis(this: nullptr);
  }
}


// ========================================================================
// ?JobSync@idProjectile@@UAAXXZ
// EA  : 0x82ECFCA0
// RVA : 0x00ECFCA0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile::JobSync(idProjectile *this)
{
  idAnimStack *v2; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *treeAnimator; // r30
  int GameMs; // r3

  if ( this->GetAnimStack_2(this) != nullptr )
  {
    v2 = this->GetAnimStack_2(this);
    presentable = this->presentable;
    treeAnimator = v2->treeAnimator;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    if ( treeAnimator != nullptr )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idTreeAnimator::SyncJoints(this: treeAnimator, time: GameMs);
    }
  }
}


// ========================================================================
// ?RemoveAIEvents@idProjectile@@UAAXXZ
// EA  : 0x82ECFD50
// RVA : 0x00ECFD50
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile::RemoveAIEvents(idProjectile *this)
{
  idHandle<int,enum invalidAIEvent_t,-1> *p_aiEventHandle; // r31

  p_aiEventHandle = &this->aiEventHandle;
  if ( this->aiEventHandle.value != -1 )
  {
    idAIEventManager::RemoveEvent(this: &gameLocal->aiEventManager, handle: &this->aiEventHandle);
    p_aiEventHandle->value = -1;
  }
}


// ========================================================================
// ?IsDead@idProjectile@@UBA_NXZ
// EA  : 0x82ECFDA8
// RVA : 0x00ECFDA8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

BOOL __fastcall idProjectile::IsDead(idProjectile *this)
{
  idPresentable *presentable; // r3
  int v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v2 = (int)presentable->GetProjectileInterface(this: presentable);
  else
    v2 = 0;
  return (_cntlzw(*(_DWORD *)(v2 + 1252) - 5) & 0x20) != 0;
}


// ========================================================================
// ?IsStuck@idProjectile@@QBA_NXZ
// EA  : 0x82ECFDF8
// RVA : 0x00ECFDF8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

BOOL __fastcall idProjectile::IsStuck(idProjectile *this)
{
  idPresentable *presentable; // r3
  int v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v2 = (int)presentable->GetProjectileInterface(this: presentable);
  else
    v2 = 0;
  return (_cntlzw(*(_DWORD *)(v2 + 1252) - 3) & 0x20) != 0;
}


// ========================================================================
// ?BecomeUnstuck@idProjectile@@UAAXXZ
// EA  : 0x82ECFE48
// RVA : 0x00ECFE48
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile::BecomeUnstuck(idProjectile *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  int GameMs; // r3
  idPresentable *v5; // r11
  int v6; // r30
  idPhysics *Physics; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetProjectileInterface(this: presentable);
  else
    v3 = 0;
  *(_DWORD *)(v3 + 1252) = 2;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v5 = this->presentable;
  v6 = GameMs;
  if ( v5 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v5 = this->presentable;
  }
  idFXManager::StopFX(this: &v5->fxManager, time: v6, stopCondition: 89, immediateStop: false);
  Physics = idEntity::GetPhysics(this);
  Physics->SetGravity(this: Physics, a2: &gameLocal->clientGame.gravity);
}


// ========================================================================
// ?AttachToJoint@idProjectile@@UAA_NPAVidEntity@@V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82ECFF18
// RVA : 0x00ECFF18
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

BOOL __fastcall idProjectile::AttachToJoint(
        idProjectile *this,
        idAnimatedEntity *ent,
        idIndex<short,enum invalidJointIndex_t> *jointIndex)
{
  idPhysics *Physics; // r3
  int list; // r29
  idAnimatedEntity *v8; // r3
  idAnimatedEntity *v9; // r31
  idList<idAttachment,5> *v10; // r3
  idAttachmentCollection v12[2]; // [sp+50h] [-30h] BYREF

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 2048, a3: -1);
  list = -1;
  v8 = idAnimatedEntity::CastTo(c: ent);
  v9 = v8;
  if ( v8 != nullptr && v8->GetAttachments_2(this: v8) != nullptr && (__int16)jointIndex != -1 )
  {
    v10 = (idList<idAttachment,5> *)v9->GetAttachments_2(this: v9);
    list = (int)idAttachmentCollection::AddAttachment(this: v12, result: v10, ent: this, jointIndex)->attachments.list;
  }
  return list != -1;
}


// ========================================================================
// ?AttachToTag@idProjectile@@UAA_NPAVidEntity@@UtagData_t@@@Z
// EA  : 0x82ECFFC8
// RVA : 0x00ECFFC8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
BOOL __fastcall idProjectile::AttachToTag(
        idProjectile *this,
        idAnimatedEntity *ent,
        __int64 tagData,
        __int64 a4,
        int a5,
        int a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13)
{
  idPhysics *Physics; // r3
  int list; // r28
  idAnimatedEntity *v17; // r3
  idAnimatedEntity *v18; // r31
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v21; // r30
  idAttachmentCollection *v22; // r3
  idAttachmentCollection v24[2]; // [sp+50h] [-30h] BYREF

  a10 = *(__int64 *)((char *)&tagData + 4);
  a11 = tagData;
  a12 = *(__int64 *)((char *)&a4 + 4);
  a13 = a4;
  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 2048, a3: -1);
  list = -1;
  v17 = idAnimatedEntity::CastTo(c: ent);
  v18 = v17;
  if ( v17 != nullptr && v17->GetAttachments_2(this: v17) != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v18);
    presentable = v18->presentable;
    v21 = TreeAnimatorFromPresentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: v18);
      presentable = v18->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    if ( v21 != nullptr )
    {
      v22 = v18->GetAttachments_2(this: v18);
      list = (int)idAttachmentCollection::AddAttachment(
                    this: v24,
                    result: v22,
                    ent: this,
                    tagData: (const tagData_t *)&a10)->attachments.list;
    }
  }
  return list != -1;
}


// ========================================================================
// ?GetMaxDamageRadius@idProjectile@@QBAMXZ
// EA  : 0x82ED00B0
// RVA : 0x00ED00B0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

float __fastcall idProjectile::GetMaxDamageRadius(idProjectile *this)
{
  const idDeclProjectile *projectileDecl; // r11
  const idDeclDamage *splashDamageDecl; // r10
  const idDeclDamage *damageDecl; // r11

  projectileDecl = this->projectileDecl;
  splashDamageDecl = projectileDecl->splashDamageDecl;
  damageDecl = projectileDecl->damageDecl;
  if ( splashDamageDecl != nullptr )
  {
    if ( damageDecl != nullptr )
    {
      _FP12 = (float)(splashDamageDecl->radius - damageDecl->radius);
      __asm { fsel      f1, f12, f13, f0 }
    }
    else
    {
      _FP1 = splashDamageDecl->radius;
    }
  }
  else if ( damageDecl != nullptr )
  {
    _FP1 = damageDecl->radius;
  }
  else
  {
    _FP1 = 0.0;
  }
  return *((float *)&_FP1 + 1);
}


// ========================================================================
// ?PointInsideDamageRadius@idProjectile@@UBA_NABVidVec3@@M@Z
// EA  : 0x82ED0108
// RVA : 0x00ED0108
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

BOOL __fastcall idProjectile::PointInsideDamageRadius(idProjectile *this, const idVec3 *point, double fudgeDistance)
{
  const idDeclProjectile *projectileDecl; // r10
  const idDeclDamage *splashDamageDecl; // r11
  const idDeclDamage *damageDecl; // r10
  idPhysics *Physics; // r3
  float *v11; // r3
  double v12; // fp9
  double v13; // fp5

  projectileDecl = this->projectileDecl;
  splashDamageDecl = projectileDecl->splashDamageDecl;
  damageDecl = projectileDecl->damageDecl;
  if ( splashDamageDecl != nullptr )
  {
    if ( damageDecl != nullptr )
    {
      _FP12 = (float)(splashDamageDecl->radius - damageDecl->radius);
      __asm { fsel      f31, f12, f13, f0 }
    }
    else
    {
      _FP31 = splashDamageDecl->radius;
    }
  }
  else if ( damageDecl != nullptr )
  {
    _FP31 = damageDecl->radius;
  }
  else
  {
    _FP31 = 0.0;
  }
  Physics = idEntity::GetPhysics(this);
  v11 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v12 = (float)(v11[2] - point->z);
  v13 = (float)(v11[1] - point->y);
  return __fsqrts((float)((float)((float)v13 * (float)v13)
                        + (float)((float)((float)(*v11 - point->x) * (float)(*v11 - point->x))
                                + (float)((float)v12 * (float)v12)))) <= (float)((float)_FP31 + (float)fudgeDistance);
}


// ========================================================================
// ?Event_FadeOut@idProjectile@@AAA?AVeventVoid@@M@Z
// EA  : 0x82ED01F8
// RVA : 0x00ED01F8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

idProjectile *__fastcall idProjectile::Event_FadeOut(idProjectile *this, idEntity *result, double time)
{
  int GameMs; // r11
  idPresentable *presentable; // r3
  int v8; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  presentable = result->presentable;
  LODWORD(result[6].defaultPhysicsObj.current.localOrigin.z) = GameMs;
  LODWORD(result[6].defaultPhysicsObj.current.localAxis.mat[0].x) = (int)(float)((float)1000.0 * (float)time) + GameMs;
  if ( presentable != nullptr )
    v8 = (int)presentable->GetProjectileInterface(this: presentable);
  else
    v8 = 0;
  *(_DWORD *)(v8 + 1252) = 4;
  idEntity::BecomeActive(this: result, flags: 1);
  return this;
}


// ========================================================================
// ?Event_StopFX@idProjectile@@AAA?AVeventVoid@@W4fxCondition_t@@@Z
// EA  : 0x82ED02B8
// RVA : 0x00ED02B8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

idProjectile *__fastcall idProjectile::Event_StopFX(idProjectile *this, idEntity *result, int condition)
{
  int GameMs; // r3
  idPresentable *presentable; // r11
  int v8; // r28

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  presentable = result->presentable;
  v8 = GameMs;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  idFXManager::StopFX(this: &presentable->fxManager, time: v8, stopCondition: condition, immediateStop: false);
  idEntity::BecomeActive(this: result, flags: 1);
  return this;
}


// ========================================================================
// ?SetWeaponStatsTag@idProjectile@@QAAXUweaponStatsTag_t@@@Z
// EA  : 0x82ED0330
// RVA : 0x00ED0330
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile::SetWeaponStatsTag(idProjectile *this, weaponStatsTag_t *tag)
{
  weaponStatsTag_t weaponStatsTag; // r11
  char v3; // r11
  bool v4; // zf

  weaponStatsTag = this->weaponStatsTag;
  if ( (*(_DWORD *)&weaponStatsTag & 0xFC000000) != 0
    || (*(_DWORD *)&weaponStatsTag & 0x3C00000) != 0
    || (v4 = (*(_DWORD *)&weaponStatsTag & 0x3FFFFF) == 0, v3 = 1, !v4) )
  {
    v3 = 0;
  }
  if ( v3 != 0 )
    this->weaponStatsTag = (weaponStatsTag_t)tag;
}


// ========================================================================
// ?InternalModifyLaunchVelocity@idProjectile@@MAAXPAVidEntity@@ABVidMat3@@@Z
// EA  : 0x82ED0378
// RVA : 0x00ED0378
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile::InternalModifyLaunchVelocity(
        idProjectile *this,
        idEntity *attacker_,
        const idMat3 *fireAxis)
{
  idEntity *BindMaster; // r3
  idPhysics *Physics; // r3
  idVec3 *v6; // r11
  float y; // r9
  float z; // r8
  idPhysics *v9; // r3
  float *v10; // r3
  idPhysics *v11; // r3
  float x; // [sp+50h] [-30h] BYREF
  float v13; // [sp+54h] [-2Ch]
  float v14; // [sp+58h] [-28h]
  _BYTE v15[16]; // [sp+60h] [-20h] BYREF

  if ( attacker_ != nullptr )
  {
    BindMaster = idEntity::GetBindMaster(this: attacker_);
    if ( BindMaster != nullptr )
    {
      Physics = idEntity::GetPhysics(this: BindMaster);
      if ( Physics != nullptr )
        v6 = Physics->GetLinearVelocity(this: (idPhysics *)v15, result: (idVec3 *)Physics, a3: 0);
      else
        v6 = &vec3_origin;
      y = v6->y;
      z = v6->z;
      x = v6->x;
      v13 = y;
      v14 = z;
      v9 = idEntity::GetPhysics(this);
      v10 = (float *)v9->GetLinearVelocity(this: (idPhysics *)v15, result: (idVec3 *)v9, a3: 0);
      x = *v10 + x;
      v13 = v10[1] + v13;
      v14 = v10[2] + v14;
      v11 = idEntity::GetPhysics(this);
      v11->SetLinearVelocity(this: v11, a2: (const idVec3 *)&x, a3: 0);
    }
  }
}


// ========================================================================
// ?RandomVectorInCone@idProjectile@@SAXABVidVec3@@MAAVidMat3@@@Z
// EA  : 0x82ED0488
// RVA : 0x00ED0488
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile::RandomVectorInCone(idMat3 *normal, double maxDegrees, idMat3 *result, idMat3 *a4)
{
  idMat3 *v7; // r3
  idClientGame *v8; // r11
  __int64 v9; // r7
  int v10; // r4
  double y; // fp30
  double z; // fp28
  const idMat3 *v13; // r3
  __int64 v14; // r7
  unsigned int v15; // r4
  double x; // fp1
  double v17; // fp29
  double v18; // fp28
  const idMat3 *v19; // r3
  idRotation v20; // [sp+60h] [-140h] BYREF
  idRotation v21; // [sp+B0h] [-F0h] BYREF
  idVec3 v22[6]; // [sp+100h] [-A0h] BYREF

  v7 = idVec3::ToMat3(this: v22, result: normal);
  a4->mat[0].x = v7->mat[0].x;
  a4->mat[0].y = v7->mat[0].y;
  v8 = clientGame;
  a4->mat[0].z = v7->mat[0].z;
  a4->mat[1] = v7->mat[1];
  a4->mat[2] = v7->mat[2];
  HIDWORD(v9) = off_822F0000;
  v10 = 1664525 * v8->random.seed;
  v8->random.seed = v10 + 1013904223;
  v21.axisValid = false;
  LODWORD(v9) = ((unsigned int)(v10 + 1013904223) >> 10) & 0x7FFF;
  y = normal->mat[0].y;
  z = normal->mat[0].z;
  v21.vec.x = normal->mat[0].x;
  v21.origin.x = vec3_origin.x;
  v21.vec.z = z;
  v21.vec.y = y;
  v21.origin.y = vec3_origin.y;
  v21.origin.z = vec3_origin.z;
  v21.axis.mat[0].x = mat3_identity.mat[0].x;
  v21.axis.mat[0].y = mat3_identity.mat[0].y;
  v21.axis.mat[0].z = mat3_identity.mat[0].z;
  v21.axis.mat[1].x = mat3_identity.mat[1].x;
  v21.axis.mat[1].y = mat3_identity.mat[1].y;
  v21.axis.mat[1].z = mat3_identity.mat[1].z;
  v21.axis.mat[2].x = mat3_identity.mat[2].x;
  v21.axis.mat[2].y = mat3_identity.mat[2].y;
  v21.axis.mat[2].z = mat3_identity.mat[2].z;
  v21.angle = (float)v9 * (float)0.010986663;
  v13 = idRotation::ToMat3(this: &v21);
  idMat3::operator*=(this: a4, a: v13);
  HIDWORD(v14) = "plode - unlink clip";
  v15 = 1664525 * clientGame->random.seed;
  clientGame->random.seed = v15 + 1013904223;
  v20.axisValid = false;
  LODWORD(v14) = ((v15 + 1013904223) >> 10) & 0x7FFF;
  x = a4->mat[1].x;
  v17 = a4->mat[1].y;
  v18 = a4->mat[1].z;
  v20.origin.x = vec3_origin.x;
  v20.origin.y = vec3_origin.y;
  v20.origin.z = vec3_origin.z;
  v20.axis.mat[0].x = mat3_identity.mat[0].x;
  v20.vec.x = x;
  v20.vec.y = v17;
  v20.vec.z = v18;
  v20.axis.mat[0].y = mat3_identity.mat[0].y;
  v20.axis.mat[0].z = mat3_identity.mat[0].z;
  v20.axis.mat[1].x = mat3_identity.mat[1].x;
  v20.axis.mat[1].y = mat3_identity.mat[1].y;
  v20.axis.mat[1].z = mat3_identity.mat[1].z;
  v20.axis.mat[2].x = mat3_identity.mat[2].x;
  v20.axis.mat[2].y = mat3_identity.mat[2].y;
  v20.axis.mat[2].z = mat3_identity.mat[2].z;
  v20.angle = (float)((float)v14 * (float)maxDegrees) * (float)0.000030518509;
  v19 = idRotation::ToMat3(this: &v20);
  idMat3::operator*=(this: a4, a: v19);
}


// ========================================================================
// ?EnableInfluenceTrail@idProjectile@@QAAXVidEntityInfluenceTrail@@@Z
// EA  : 0x82ED06D8
// RVA : 0x00ED06D8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idProjectile::EnableInfluenceTrail(
        idProjectile *this,
        idEntityInfluenceTrail *trailInfo,
        __int64 a3,
        idPresentable *a4,
        const idSoundShader *a5,
        int a6,
        int a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13)
{
  int v13; // r3
  int v14; // r31
  __int64 v15; // r5 OVERLAPPED

  a11 = *(_QWORD *)&trailInfo;
  v14 = v13;
  HIDWORD(v15) = *(_DWORD *)(v13 + 488);
  a12 = *(__int64 *)((char *)&a3 + 4);
  a13 = a3;
  if ( HIDWORD(v15) != 0 )
  {
    idInfluenceTrailManager::Enable(
      this: &clientGame->influenceTrailManager,
      presentable: (idPresentable *)HIDWORD(v15),
      trail: (const idEntityInfluenceTrail *)&a11,
      sndFoliage: nullptr,
      a5: a4,
      a6: a5);
    *(_DWORD *)(v14 + 5448) = idClientGame::GetPlayerGameTime(this: clientGame);
  }
}


// ========================================================================
// ?InternalLaunch@idProjectile_DragonBreath@@MAAXPAVidEntity@@ABVidVec3@@ABVidMat3@@ABVidProjectileTarget@@MH@Z
// EA  : 0x82ED0748
// RVA : 0x00ED0748
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_DragonBreath::InternalLaunch(
        idProjectile_Dagger *this,
        idEntity *attacker,
        const idVec3 *start,
        const idMat3 *fireAxis,
        const idProjectileTarget *target,
        double initialSpeed,
        int startTime)
{
  double speed; // fp0
  idPhysics_RigidBody_vtbl *v8; // r11
  double v9; // fp9
  double v10; // fp8
  float v11[6]; // [sp+50h] [-20h] BYREF

  speed = initialSpeed;
  if ( initialSpeed == -1.0 )
    speed = this->projectileDecl->notHitscanInfo.speed;
  v8 = this->physicsObj.idProjectile_Arrow::__vftable;
  v9 = (float)(fireAxis->mat[0].y * (float)speed);
  v10 = (float)(fireAxis->mat[0].z * (float)speed);
  v11[0] = fireAxis->mat[0].x * (float)speed;
  v11[1] = v9;
  v11[2] = v10;
  ((void (__fastcall *)(idPhysics_RigidBody *, float *, _DWORD, const idMat3 *, const idProjectileTarget *, const int))v8->SetLinearVelocity)(
    a1: &this->physicsObj,
    a2: v11,
    a3: 0,
    a4: fireAxis,
    a5: target,
    a6: startTime);
}


// ========================================================================
// ?Collide@idProjectile_DragonBreath@@UAA?AW4collide_t@@HAAUtrace_t@@ABVidVec3@@@Z
// EA  : 0x82ED07C0
// RVA : 0x00ED07C0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

int __fastcall idProjectile_DragonBreath::Collide(
        idProjectile_DragonBreath *this,
        const int physId,
        trace_t *collision,
        const idVec3 *velocity,
        __int64 a5,
        __int64 a6)
{
  int started; // r29

  LODWORD(a6) = collision->c.surfaceFlags & 1;
  if ( (_DWORD)a6 != 0 )
  {
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0, a4: (int)velocity, a5, a6);
    started = 1;
  }
  else
  {
    ++this->collisionCount;
    started = idLobbyBackend360::StartArbitration(pexcept: (_exception *)this);
  }
  this->Explode(this, a2: gameLocal->entities.ptr[collision->c.entityNum], a3: collision);
  return started;
}


// ========================================================================
// ?AllocPresentable@idProjectile_Rocket@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82ED0860
// RVA : 0x00ED0860
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

idPresentableProjectile_Rocket *__fastcall idProjectile_Rocket::AllocPresentable(
        idProjectile_Rocket *this,
        idRenderModel *renderModel_)
{
  idPresentableProjectile_Rocket *v4; // r29
  idAnimStack *v5; // r3

  v4 = (idPresentableProjectile_Rocket *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                           size: 0x7F8u,
                                           tag: TAG_PRESENTABLE,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
  if ( v4 == nullptr )
    return nullptr;
  v5 = this->GetAnimStack_2(this);
  return idPresentableProjectile_Rocket::idPresentableProjectile_Rocket(
           this: v4,
           ent: this,
           renderModel_,
           animStack_: v5);
}


// ========================================================================
// __unwind$495508
// EA  : 0x82ED08E8
// RVA : 0x00ED08E8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_495508()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?DeactivatePhysics@idProjectile_Rocket@@UAAXH@Z
// EA  : 0x82ED0918
// RVA : 0x00ED0918
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Rocket::DeactivatePhysics(idProjectile_Rocket *this, int physId)
{
  idPresentable *presentable; // r3
  int v5; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetProjectileInterface(this: presentable);
  else
    v5 = 0;
  if ( *(_DWORD *)(v5 + 1252) != 5 )
    this->Explode(this, a2: nullptr, a3: nullptr);
  idEntity::DeactivatePhysics(this, physId);
}


// ========================================================================
// ?AllocPresentable@idProjectile_Homing@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82ED09B0
// RVA : 0x00ED09B0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

idPresentableProjectile_Homing *__fastcall idProjectile_Homing::AllocPresentable(
        idProjectile_Homing *this,
        idRenderModel *renderModel_)
{
  idPresentableProjectile_Homing *v4; // r29
  idAnimStack *v5; // r3

  v4 = (idPresentableProjectile_Homing *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                           size: 0x810u,
                                           tag: TAG_PRESENTABLE,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
  if ( v4 == nullptr )
    return nullptr;
  v5 = this->GetAnimStack_2(this);
  return idPresentableProjectile_Homing::idPresentableProjectile_Homing(
           this: v4,
           ent: this,
           renderModel_,
           animStack_: v5);
}


// ========================================================================
// __unwind$495579_0
// EA  : 0x82ED0A38
// RVA : 0x00ED0A38
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_495579_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?GetInitialDir@idProjectile_Homing@@UAA?AVidVec3@@ABVidMat3@@@Z
// EA  : 0x82ED0A68
// RVA : 0x00ED0A68
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

idProjectile_Homing *__fastcall idProjectile_Homing::GetInitialDir(
        idProjectile_Homing *this,
        idEntity *result,
        const idMat3 *fireAxis)
{
  float v4; // r3
  int v7; // r3

  v4 = *(float *)&result->presentable;
  if ( v4 == 0.0 )
  {
    idEntity::InitPresentableInternal(this: result);
    v4 = *(float *)&result->presentable;
  }
  v7 = (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(v4) + 116))(a1: COERCE_DOUBLE(LODWORD(v4)));
  (*(void (__fastcall **)(idProjectile_Homing *, int, const idMat3 *))(*(_DWORD *)v7 + 352))(
    a1: this,
    a2: v7,
    a3: fireAxis);
  return this;
}


// ========================================================================
// ?Spawn@idProjectile_Rocket@@QAAXXZ
// EA  : 0x82ED0AD8
// RVA : 0x00ED0AD8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Rocket::Spawn(idProjectile_Arrow *this, int a2, int a3, int a4, idPhysicsCallbacks *a5)
{
  idPresentable *presentable; // r3
  idPresentableProjectile *v7; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v7 = presentable->GetProjectileInterface(this: presentable);
  else
    v7 = nullptr;
  idPresentableProjectile::SetupClientProjectilePhysics(
    this: v7,
    physicsObj: &this->physicsObj,
    clipModelInfo: &this->clipModelInfo,
    trm: nullptr,
    overrideCollision: -1.0,
    cb: a5,
    a7: &this->physicsCallbacks);
}


// ========================================================================
// ?ShouldRemoveOnCollision@idProjectile_Arrow@@UAA_NABUtrace_t@@M@Z
// EA  : 0x82ED0B40
// RVA : 0x00ED0B40
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

int __fastcall idProjectile_Arrow::ShouldRemoveOnCollision(
        idProjectile_Arrow *this,
        const trace_t *collision,
        double damageDone)
{
  int (__fastcall ***v3)(double); // r7
  int v4; // r11
  char v5; // r11
  bool v6; // zf
  int result; // r3

  v3 = (int (__fastcall ***)(double))gameLocal->entities.ptr[collision->c.entityNum];
  if ( v3 == nullptr )
    return 0;
  v4 = *(_DWORD *)((**v3)(a1: damageDone) + 36);
  if ( v4 < idPlayer::Type.typeNum || (v6 = v4 <= idPlayer::Type.lastChild, v5 = 1, !v6) )
    v5 = 0;
  result = 1;
  if ( v5 == 0 )
    return 0;
  return result;
}


// ========================================================================
// ?ShouldBreak@idProjectile_Arrow@@QAA_NXZ
// EA  : 0x82ED0BD0
// RVA : 0x00ED0BD0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

int __fastcall idProjectile_Arrow::ShouldBreak(idProjectile_Arrow *this)
{
  unsigned int v2; // r4

  if ( this->forceStick )
    return 0;
  v2 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v2;
  return ((((this->breakChance ^ (((v2 >> 10) & 0x7FFF) % 0x64)) & 0x80000000) == 0)
        + (((v2 >> 10) & 0x7FFF) % 0x64 >= this->breakChance))
       & 1;
}


// ========================================================================
// ?IsEverUsable@idProjectile_Arrow@@UBA_NPBVidEntity@@@Z
// EA  : 0x82ED0C50
// RVA : 0x00ED0C50
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

int __fastcall idProjectile_Arrow::IsEverUsable(idProjectile_Arrow *this, const idEntity *activator)
{
  idPresentable *presentable; // r3
  int v4; // r3
  idPresentable *v5; // r3
  int v6; // r3
  unsigned __int8 v7; // r11

  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = ((int (__fastcall *)(idPresentable *, const idEntity *))presentable->GetProjectileInterface)(
           a1: presentable,
           a2: activator);
  else
    v4 = 0;
  if ( *(_DWORD *)(v4 + 1252) != 3 || this->forceStick )
  {
    v5 = this->presentable;
    v6 = v5 != nullptr ? (int)v5->GetProjectileInterface(this: v5) : 0;
    if ( *(_DWORD *)(v6 + 1252) != 2 )
      return 0;
  }
  v7 = 1;
  if ( this->inventoryItem == nullptr )
    return 0;
  return v7;
}


// ========================================================================
// ?Spawn@idProjectile_Dagger@@QAAXXZ
// EA  : 0x82ED0D00
// RVA : 0x00ED0D00
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Dagger::Spawn(idProjectile_Dagger *this)
{
  idPhysics *Physics; // r3
  idBreakableManager *p_breakableManager; // r30
  const idVec3 *v4; // r3

  if ( this->breakable != nullptr )
  {
    Physics = idEntity::GetPhysics(this);
    p_breakableManager = &gameLocal->breakableManager;
    v4 = Physics->GetOrigin(this: Physics, a2: 0);
    idBreakableManager::AddBreakable(this: p_breakableManager, decl: this->breakable, origin: v4);
  }
}


// ========================================================================
// ?ShouldStickOnCollision@idProjectile_Dagger@@UAA_NABUtrace_t@@@Z
// EA  : 0x82ED0D78
// RVA : 0x00ED0D78
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

int __fastcall idProjectile_Dagger::ShouldStickOnCollision(idProjectile_Dagger *this, const trace_t *collision)
{
  double v4; // fp31
  int v5; // r9
  idClass *v6; // r30
  idPhysics *Physics; // r3
  double v8; // fp30
  unsigned int v9; // r4
  double v10; // fp0
  char *v11; // r10
  float *p_z; // r11
  int i; // ctr
  double y; // fp13
  double z; // fp12
  double x; // fp11
  long double v17; // fp2
  char *v18; // r10
  float *v19; // r11
  int v20; // ctr
  float *v21; // r10
  float *v22; // r11
  int j; // ctr
  double v24; // fp8
  double v25; // fp7
  double v26; // fp6
  double v27; // fp5
  double v28; // fp4
  double v29; // fp3
  double v30; // fp2
  idVec3 v32; // [sp+50h] [-E0h] BYREF
  idMat3 v33; // [sp+60h] [-D0h] BYREF
  idVec3 v34; // [sp+88h] [-A8h] BYREF
  idTypesafeNumber<float,enum RadiansUnique_t> v35; // [sp+94h] [-9Ch] BYREF
  char v36; // [sp+9Ch] [-94h] BYREF
  float v37; // [sp+A0h] [-90h]
  float v38; // [sp+A4h] [-8Ch]
  float v39; // [sp+A8h] [-88h]
  float v40; // [sp+B8h] [-78h]
  float v41; // [sp+BCh] [-74h]
  float v42; // [sp+C0h] [-70h]
  float v43[13]; // [sp+CCh] [-64h] BYREF

  v4 = 1.0;
  if ( collision->fraction >= 1.0 )
    return 0;
  v5 = collision->c.entityNum + 21563;
  v6 = *((idClass **)&gameLocal->__vftable + v5);
  if ( v6 == nullptr )
    return 0;
  if ( (unsigned __int8)idWaterEntity::IsTypeOf(c: *((idClass **)&gameLocal->__vftable + v5)) != 0 )
    return 0;
  if ( (unsigned __int8)idVehicle::IsTypeOf(c: v6) != 0 )
    return 0;
  Physics = idEntity::GetPhysics(this);
  Physics->GetLinearVelocity(this: (idPhysics *)&v32, result: (idVec3 *)Physics, a3: 0);
  idVec3::NormalizeFast(this: &v32);
  v8 = (float)((float)(collision->c.normal.x * (float)-v32.x)
             + (float)((float)(collision->c.normal.z * (float)-v32.z) + (float)(collision->c.normal.y * (float)-v32.y)));
  if ( (unsigned __int8)idAI2::IsTypeOf(c: v6) == 0 )
  {
    if ( v8 < this->reflectionCosine )
      return 0;
    v9 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v9;
    if ( (signed int)(((v9 >> 10) & 0x7FFF) % 0x64) > this->stickChance )
      return 0;
  }
  if ( this->zUp )
    v10 = 1.0;
  else
    v10 = -1.0;
  v11 = &v36;
  p_z = &this->lastVel.z;
  for ( i = 9; i != 0; --i )
  {
    ++p_z;
    v11 += 4;
    *(float *)v11 = *p_z;
  }
  y = v32.y;
  z = v32.z;
  x = v32.x;
  *(double *)&v17 = 0.75;
  *((double *)&v17 + 1) = (float)((float)(v42 * (float)(v32.z * (float)v10)) + (float)(v41 * (float)(v32.y * (float)v10)));
  if ( (float)((float)(v40 * (float)((float)v10 * v32.x))
             + (float)((float)(v42 * (float)(v32.z * (float)v10)) + (float)(v41 * (float)(v32.y * (float)v10)))) < 0.75 )
  {
    v33.mat[2].z = 1.0;
    v33.mat[1].y = 1.0;
    v18 = &v36;
    v19 = &this->lastVel.z;
    v33.mat[1].z = 0.0;
    v20 = 9;
    v33.mat[2].y = 0.0;
    v33.mat[2].x = 0.0;
    v33.mat[1].x = 0.0;
    do
    {
      ++v19;
      v18 += 4;
      *(float *)v18 = *v19;
      --v20;
    }
    while ( v20 != 0 );
    v21 = v43;
    v22 = &this->lastVel.z;
    v33.mat[0].x = v37;
    v34 = v32;
    v33.mat[0].y = v38;
    v33.mat[0].z = v39;
    for ( j = 9; j != 0; --j )
      *++v21 = *++v22;
    if ( (float)((float)(v43[4] * (float)x) + (float)((float)(v43[6] * (float)z) + (float)(v43[5] * (float)y))) <= 0.0 )
      v4 = -1.0;
    v35.value = idMath::ACos(a: v17) * (float)v4;
    idVec3::RotateSelf(this: &v34, axis: v33.mat, angle: &v35);
    v33.mat[2].x = v34.x;
    v33.mat[2].y = v34.y;
    v33.mat[2].z = v34.z;
    idMat3::OrthoNormalizeSelf(this: &v33, prio1: 2, prio2: 0);
    this->lastModelAxis.mat[0].x = v33.mat[0].x;
    v24 = v33.mat[0].y;
    v25 = v33.mat[0].z;
    this->lastModelAxis.mat[1].x = v33.mat[1].x;
    v26 = v33.mat[1].y;
    this->lastModelAxis.mat[0].y = v24;
    this->lastModelAxis.mat[0].z = v25;
    v27 = v33.mat[1].z;
    this->lastModelAxis.mat[1].y = v26;
    v28 = v33.mat[2].x;
    this->lastModelAxis.mat[1].z = v27;
    v29 = v33.mat[2].y;
    this->lastModelAxis.mat[2].x = v28;
    v30 = v33.mat[2].z;
    this->lastModelAxis.mat[2].y = v29;
    this->lastModelAxis.mat[2].z = v30;
  }
  return 1;
}


// ========================================================================
// ?ModifyCrosshairInfo@idProjectile_Dagger@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82ED10B0
// RVA : 0x00ED10B0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

int __fastcall idProjectile_Dagger::ModifyCrosshairInfo(
        idProjectile_Dagger *this,
        const idEntity *activator,
        const idFocusTrace *ft,
        const usableState_t usable,
        idCrosshairInfo *info)
{
  const idDeclInventory *inventoryItem; // r11

  inventoryItem = this->inventoryItem;
  if ( inventoryItem == nullptr )
    return 0;
  info->icons.list->material = inventoryItem->icon;
  return 1;
}


// ========================================================================
// ?Spawn@idProjectile_Grenade@@QAAXXZ
// EA  : 0x82ED10D8
// RVA : 0x00ED10D8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Grenade::Spawn(idProjectile_Grenade *this, int a2, int a3, int a4, idPhysicsCallbacks *a5)
{
  idPresentable *presentable; // r3
  idPresentableProjectile *v7; // r3
  const idVec3 *v8; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v7 = presentable->GetProjectileInterface(this: presentable);
  else
    v7 = nullptr;
  idPresentableProjectile::SetupClientProjectilePhysics(
    this: v7,
    physicsObj: (idPhysics_RigidBody *)&this->physicsObj,
    clipModelInfo: &this->clipModelInfo,
    trm: nullptr,
    overrideCollision: -1.0,
    cb: a5,
    a7: &this->physicsCallbacks);
  v8 = this->physicsObj.GetGravityNormal(this: &this->physicsObj);
  this->lastCollisionNormal.x = v8->x;
  this->lastCollisionNormal.y = v8->y;
  this->lastCollisionNormal.z = v8->z;
}


// ========================================================================
// ?PlayBounceSound@idProjectile_Grenade@@IAAXABVidVec3@@ABUtrace_t@@@Z
// EA  : 0x82ED1178
// RVA : 0x00ED1178
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Grenade::PlayBounceSound(
        idProjectile_Grenade *this,
        const idVec3 *vel,
        const trace_t *collision)
{
  float x; // r9
  float y; // r7
  double v8; // fp4
  double v9; // fp4
  double v10; // fp5
  double v11; // fp4
  idEntity *powerSourceToMoveTo; // r11
  float z; // [sp+58h] [-18h]

  x = vel->x;
  y = vel->y;
  z = vel->z;
  _FP1 = (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(y * y))) - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f5, f1, f2, f13 }
  v8 = __frsqrte(_FP5);
  v9 = (float)((float)-(float)((float)((float)((float)v8
                                             * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(y * y)))
                                                     * (float)0.5))
                                     * (float)v8)
                             - (float)1.5)
             * (float)v8);
  v10 = (float)((float)-(float)((float)((float)((float)v9
                                              * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(y * y)))
                                                      * (float)0.5))
                                      * (float)v9)
                              - (float)1.5)
              * (float)v9);
  v11 = (float)((float)((float)-(float)((float)((float)((float)v9
                                                      * (float)((float)((float)(x * x)
                                                                      + (float)((float)(z * z) + (float)(y * y)))
                                                              * (float)0.5))
                                              * (float)v9)
                                      - (float)1.5)
                      * (float)v9)
              * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(y * y))) * (float)0.5));
  if ( (float)((float)((float)(collision->c.normal.x
                             * (float)(x
                                     * (float)((float)-(float)((float)((float)v11 * (float)v10) - (float)1.5)
                                             * (float)v10)))
                     + (float)((float)(collision->c.normal.z
                                     * (float)(z
                                             * (float)((float)-(float)((float)((float)v11 * (float)v10) - (float)1.5)
                                                     * (float)v10)))
                             + (float)(collision->c.normal.y
                                     * (float)(y
                                             * (float)((float)-(float)((float)((float)v11 * (float)v10) - (float)1.5)
                                                     * (float)v10)))))
             * (float)((float)((float)-(float)((float)((float)v11 * (float)v10) - (float)1.5) * (float)v10)
                     * (float)((float)(x * x) + (float)((float)(z * z) + (float)(y * y))))) < -100.0 )
  {
    powerSourceToMoveTo = this->powerSourceToMoveTo;
    if ( powerSourceToMoveTo == nullptr || collision->c.entityNum != powerSourceToMoveTo->entityNumber )
    {
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_BODY2,
        shader: this->projectileDecl->notHitscanInfo.grenadeInfo.bounceSound,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
      this->nextBounceTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                           + 250;
    }
  }
}


// ========================================================================
// ?ApplyWaterSplashEffects@idProjectile_Grenade@@UAAXHHW4surfTypes_t@@W4splashState_t@idPhysicsCallbacks@@@Z
// EA  : 0x82ED12B8
// RVA : 0x00ED12B8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Grenade::ApplyWaterSplashEffects(
        idProjectile_Grenade *this,
        int physId,
        const int bodyId,
        surfTypes_t surfOverride,
        idPhysicsCallbacks::splashState_t splashState)
{
  idMat3 *p_splashVelocity; // r31
  char v7; // r11
  idPhysics *Physics; // r3
  float *v9; // r3
  double v10; // fp12
  double v11; // fp11
  idPhysics *v12; // r3
  const idDeclProjectile *projectileDecl; // r11
  unsigned __int16 value; // r29
  const idDeclProjectileImpactEffect *impactEffectTable; // r28
  const idMat3 *v16; // r3
  const idPresentable *v17; // [sp+8h] [-A8h]
  idPresentable *v18; // [sp+Ch] [-A4h]
  idIndex<short,enum invalidJointIndex_t> *v19; // [sp+10h] [-A0h]
  int v20; // [sp+14h] [-9Ch]
  int v21; // [sp+18h] [-98h]
  int v22; // [sp+1Ch] [-94h]
  int v23; // [sp+20h] [-90h]
  int v24; // [sp+24h] [-8Ch]
  int v25; // [sp+28h] [-88h]
  int v26; // [sp+2Ch] [-84h]
  int v27; // [sp+30h] [-80h]
  int v28; // [sp+34h] [-7Ch]
  int v29; // [sp+38h] [-78h]
  int v30; // [sp+3Ch] [-74h]
  int v31; // [sp+40h] [-70h]
  int v32; // [sp+44h] [-6Ch]
  int v33; // [sp+48h] [-68h]
  int v34; // [sp+4Ch] [-64h]
  int v35; // [sp+50h] [-60h]
  int v36; // [sp+58h] [-58h]
  int v37; // [sp+60h] [-50h]
  char v38; // [sp+70h] [-40h] BYREF

  if ( idPhysics::GetPhysicsForId(physicsId_: physId) != nullptr )
  {
    this->isInWater = true;
    p_splashVelocity = (idMat3 *)&this->splashVelocity;
    if ( this->splashVelocity.x != vec3_origin.x
      || this->splashVelocity.y != vec3_origin.y
      || (v7 = 1, this->splashVelocity.z != vec3_origin.z) )
    {
      v7 = 0;
    }
    if ( v7 != 0 )
    {
      Physics = idEntity::GetPhysics(this);
      v9 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v38, result: (idVec3 *)Physics, a3: 0);
      v10 = v9[1];
      v11 = v9[2];
      p_splashVelocity->mat[0].x = *v9 * (float)-1.0;
      this->splashVelocity.y = (float)v10 * (float)-1.0;
      this->splashVelocity.z = (float)v11 * (float)-1.0;
    }
    idVec3::NormalizeFast(this: &this->splashVelocity);
    if ( this->projectileDecl->impactEffectTable != nullptr )
    {
      v12 = idEntity::GetPhysics(this);
      projectileDecl = this->projectileDecl;
      value = NULL_JOINT_INDEX.value;
      impactEffectTable = projectileDecl->impactEffectTable;
      v16 = (const idMat3 *)v12->GetOrigin(this: v12, a2: 0);
      idClientGame::ImpactEffect(
        this: clientGame,
        point: v16,
        normal: p_splashVelocity,
        color: &idColor::colorWhite,
        effect: &impactEffectTable->liquidEffect,
        skipParticle: false,
        noDecals: false,
        noSounds: false,
        owner: v17,
        entity: v18,
        jointId: v19,
        a12: v20,
        a13: v21,
        a14: v22,
        a15: v23,
        a16: v24,
        a17: v25,
        a18: v26,
        a19: v27,
        a20: v28,
        a21: v29,
        a22: v30,
        a23: v31,
        a24: v32,
        a25: v33,
        a26: v34,
        a27: v35,
        a28: 0,
        a29: v36,
        a30: 0,
        a31: v37,
        a32: value);
      p_splashVelocity->mat[0] = vec3_origin;
    }
  }
}


// ========================================================================
// ?Damage@idProjectile_Grenade@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82ED1428
// RVA : 0x00ED1428
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

float __fastcall idProjectile_Grenade::Damage(
        idProjectile_Grenade *this,
        idEntity *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace,
        trace_t *a8)
{
  idPresentable *presentable; // r3
  int v12; // r3
  double v13; // fp1

  presentable = this->presentable;
  if ( presentable != nullptr )
    v12 = (int)presentable->GetProjectileInterface(this: presentable);
  else
    v12 = 0;
  if ( *(_DWORD *)(v12 + 1252) != 5 )
    this->Explode(this, a2: inflictor, a3: a8);
  v13 = 0.0;
  return *((float *)&v13 + 1);
}


// ========================================================================
// ?RemoveAIEvents@idProjectile_Grenade@@UAAXXZ
// EA  : 0x82ED14B0
// RVA : 0x00ED14B0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Grenade::RemoveAIEvents(idProjectile_Grenade *this)
{
  idHandle<int,enum invalidAIEvent_t,-1> *p_aiEventHandle; // r31

  p_aiEventHandle = &this->aiEventHandle;
  if ( this->aiEventHandle.value != -1 )
  {
    idAIEventManager::RemoveEvent(this: &gameLocal->aiEventManager, handle: &this->aiEventHandle);
    p_aiEventHandle->value = -1;
  }
  if ( this->playerEventHandle.value != -1 )
  {
    idAIEventManager::RemoveEvent(this: &gameLocal->aiEventManager, handle: &this->playerEventHandle);
    this->playerEventHandle.value = -1;
  }
}


// ========================================================================
// ?AllocPresentable@idProjectile_Grenade@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82ED1528
// RVA : 0x00ED1528
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

idPresentableProjectile_Grenade *__fastcall idProjectile_Grenade::AllocPresentable(
        idProjectile_Grenade *this,
        idRenderModel *renderModel_)
{
  idPresentableProjectile_Grenade *v4; // r29
  idAnimStack *v5; // r3

  v4 = (idPresentableProjectile_Grenade *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                            size: 0x7F0u,
                                            tag: TAG_PRESENTABLE,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
  if ( v4 == nullptr )
    return nullptr;
  v5 = this->GetAnimStack_2(this);
  return idPresentableProjectile_Grenade::idPresentableProjectile_Grenade(
           this: v4,
           ent: this,
           renderModel_,
           animStack_: v5);
}


// ========================================================================
// __unwind$496393_0
// EA  : 0x82ED15B0
// RVA : 0x00ED15B0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_496393_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?Attach@idProjectile@@UAA_NPAVidEntity@@ABUtrace_t@@@Z
// EA  : 0x82ED15E0
// RVA : 0x00ED15E0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

BOOL __fastcall idProjectile::Attach(idProjectile *this, idAnimatedEntity *ent, const trace_t *trace)
{
  idPhysics *Physics; // r3
  idAnimatedEntity *v7; // r3
  idAnimatedEntity *v8; // r30
  idPhysics *v9; // r3
  double z; // fp6
  double v11; // fp3
  double v12; // fp1
  int trmFeature; // r11
  idIndex<short,enum invalidJointIndex_t> *v14; // r31
  idList<idAttachment,5> *v15; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idIndex<short,enum invalidJointIndex_t> *v19; // r28
  const idIndex<short,enum invalidJointIndex_t> *v20; // r31
  idPhysics *v21; // r27
  idPhysics *v22; // r26
  float *v23; // r27
  float *v24; // r3
  double v25; // fp9
  double v26; // fp7
  double v27; // fp6
  idAttachmentCollection *v28; // r3
  idPhysics *v29; // r30
  idPhysics *v30; // r28
  float *v31; // r3
  double v32; // fp10
  double v33; // fp4
  double v34; // fp5
  double y; // fp9
  double v36; // fp2
  double v37; // fp2
  double v40; // fp4
  double v41; // fp4
  double v42; // fp7
  double v43; // fp6
  idAttachmentCollection v44; // [sp+50h] [-90h] BYREF
  float v45[6]; // [sp+68h] [-78h] BYREF
  tagData_t v46; // [sp+80h] [-60h] BYREF

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 2048, a3: -1);
  v7 = idAnimatedEntity::CastTo(c: ent);
  v8 = v7;
  if ( v7 != nullptr && v7->GetAttachments_2(this: v7) != nullptr )
  {
    if ( trace->c.type == CONTACT_SPHERE )
    {
      v9 = idEntity::GetPhysics(this);
      z = trace->c.point.z;
      v11 = (float)(trace->c.normal.z * (float)(trace->c.separation * (float)0.5));
      v12 = (float)(trace->c.point.y - (float)(trace->c.normal.y * (float)(trace->c.separation * (float)0.5)));
      *(float *)&v44.attachments.size = trace->c.point.x
                                      - (float)((float)(trace->c.separation * (float)0.5) * trace->c.normal.x);
      *(float *)&v44.attachments.granularity = v12;
      *(float *)&v44.parent = (float)z - (float)v11;
      v9->SetOrigin(this: v9, a2: (const idVec3 *)&v44.attachments.size, a3: -1);
    }
    if ( trace->c.type == CONTACT_SPHERE )
      trmFeature = trace->c.trmFeature;
    else
      LOWORD(trmFeature) = -1;
    v14 = (idIndex<short,enum invalidJointIndex_t> *)(__int16)trmFeature;
    if ( (__int16)trmFeature != -1 )
    {
      v15 = (idList<idAttachment,5> *)v8->GetAttachments_2(this: v8);
      return idAttachmentCollection::AddAttachment(this: &v44, result: v15, ent: this, jointIndex: v14)->attachments.list != (idAttachment *)-1;
    }
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v8);
    presentable = v8->presentable;
    v19 = (idIndex<short,enum invalidJointIndex_t> *)TreeAnimatorFromPresentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: v8);
      presentable = v8->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    if ( v19 != nullptr )
    {
      v20 = (const idIndex<short,enum invalidJointIndex_t> *)HIWORD(idTreeAnimator::GetJointIndex(
                                                                      this: (idTreeAnimator *)&v44,
                                                                      result: v19,
                                                                      jointName: "origin")->__vftable);
      if ( v20 != (const idIndex<short,enum invalidJointIndex_t> *)0xFFFF )
      {
        v46.parentJoint.value = -1;
        v46.trans.x = 0.0;
        v46.trans.y = 0.0;
        v46.trans.z = 0.0;
        v46.rot.x = 0.0;
        v46.rot.y = 0.0;
        v46.rot.z = 0.0;
        v46.rot.w = 0.0;
        v21 = idEntity::GetPhysics(this: ent);
        v22 = idEntity::GetPhysics(this);
        v23 = (float *)v21->GetOrigin(this: v21, a2: 0);
        v24 = (float *)v22->GetOrigin(this: v22, a2: 0);
        v25 = (float)(*v24 - *v23);
        v26 = (float)(v24[1] - v23[1]);
        v27 = (float)(v24[2] - v23[2]);
        v46.rot.x = 0.0;
        v46.rot.y = 0.0;
        v46.rot.z = 0.0;
        v46.rot.w = 1.0;
        v46.trans.x = v25;
        v46.trans.y = v26;
        v46.trans.z = v27;
        v46.parentJoint.value = HIWORD(idTreeAnimator::GetJointHandle(
                                         this: (idTreeAnimator *)&v44,
                                         result: (idHandle<unsigned short,enum invalidJointHandle_t,65535> *)v19,
                                         jointIndex: v20)->__vftable);
        v28 = v8->GetAttachments_2(this: v8);
        return idAttachmentCollection::AddAttachment(this: &v44, result: v28, ent: this, tagData: &v46)->attachments.list != (idAttachment *)-1;
      }
      idLib::Warning(fmt: "idProjectile::Attach - attach failed!");
    }
    return false;
  }
  else
  {
    v29 = idEntity::GetPhysics(this);
    v30 = idEntity::GetPhysics(this);
    v31 = (float *)v29->GetOrigin(this: v29, a2: 0);
    v32 = trace->c.point.z;
    v33 = (float)(v31[2] - trace->c.point.z);
    v34 = (float)(*v31 - trace->c.point.x);
    y = trace->c.point.y;
    v36 = (float)(v31[1] - trace->c.point.y);
    v37 = (float)((float)((float)v34 * (float)v34)
                + (float)((float)((float)v36 * (float)v36) + (float)((float)v33 * (float)v33)));
    _FP1 = (float)((float)v37 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f5, f1, f2, f13 }
    v40 = __frsqrte(_FP5);
    v41 = (float)((float)-(float)((float)((float)((float)v40 * (float)((float)v37 * (float)0.5)) * (float)v40)
                                - (float)1.5)
                * (float)v40);
    v42 = (float)(trace->c.normal.y
                * (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41 * (float)((float)v37 * (float)0.5)) * (float)v41)
                                                                                                - (float)1.5)
                                                                                * (float)v41)
                                                                        * (float)((float)v37 * (float)0.5))
                                                                * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)v37 * (float)0.5))
                                                                                                * (float)v41)
                                                                                        - (float)1.5)
                                                                        * (float)v41))
                                                        - (float)1.5)
                                        * (float)((float)-(float)((float)((float)((float)v41
                                                                                * (float)((float)v37 * (float)0.5))
                                                                        * (float)v41)
                                                                - (float)1.5)
                                                * (float)v41))
                                * (float)v37)
                        * (float)0.25));
    v43 = (float)(trace->c.normal.z
                * (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41 * (float)((float)v37 * (float)0.5)) * (float)v41)
                                                                                                - (float)1.5)
                                                                                * (float)v41)
                                                                        * (float)((float)v37 * (float)0.5))
                                                                * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)v37 * (float)0.5))
                                                                                                * (float)v41)
                                                                                        - (float)1.5)
                                                                        * (float)v41))
                                                        - (float)1.5)
                                        * (float)((float)-(float)((float)((float)((float)v41
                                                                                * (float)((float)v37 * (float)0.5))
                                                                        * (float)v41)
                                                                - (float)1.5)
                                                * (float)v41))
                                * (float)v37)
                        * (float)0.25));
    v45[0] = trace->c.point.x
           + (float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41 * (float)((float)v37 * (float)0.5)) * (float)v41) - (float)1.5)
                                                                                   * (float)v41)
                                                                           * (float)((float)v37 * (float)0.5))
                                                                   * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)v37 * (float)0.5)) * (float)v41)
                                                                                           - (float)1.5)
                                                                           * (float)v41))
                                                           - (float)1.5)
                                           * (float)((float)-(float)((float)((float)((float)v41
                                                                                   * (float)((float)v37 * (float)0.5))
                                                                           * (float)v41)
                                                                   - (float)1.5)
                                                   * (float)v41))
                                   * (float)v37)
                           * (float)0.25)
                   * trace->c.normal.x);
    v45[1] = (float)y + (float)v42;
    v45[2] = (float)v32 + (float)v43;
    v30->SetOrigin(this: v30, a2: (const idVec3 *)v45, a3: -1);
    idEntity::Bind(this, master: (idWorldspawn *)ent, orientated: true);
    return false;
  }
}


// ========================================================================
// ?Spawn@idProjectile_StickyBomb@@QAAXXZ
// EA  : 0x82ED19F8
// RVA : 0x00ED19F8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_StickyBomb::Spawn(idProjectile_StickyBomb *this)
{
  idPhysicsCallbacks *v2; // r7
  idPresentable *presentable; // r3
  idPresentableProjectile *v4; // r3
  const idTraceModel *v5; // r6
  float *p_z; // r10
  int v7; // ctr
  idSysMutex *p_viewNoteMutex; // r11
  idPresentable *v9; // r3
  idGameTimeManager *v10; // r3
  idRenderModel *RenderModelFromPresentable; // r3
  idTreeAnimator *v12; // r30
  idAnimStack *v13; // r3
  idBounds v14; // [sp+50h] [-680h] BYREF
  idAnimatorParms_Base v15; // [sp+70h] [-660h] BYREF
  idTraceModel v16; // [sp+B0h] [-620h] BYREF

  if ( common->IsMultiplayer(this: common) )
  {
    presentable = this->presentable;
    if ( presentable != nullptr )
      v4 = presentable->GetProjectileInterface(this: presentable);
    else
      v4 = nullptr;
    v5 = nullptr;
  }
  else
  {
    memset(&v16.type, 0, 20);
    p_z = &v16.offset.z;
    v7 = 6;
    p_viewNoteMutex = &analysisClient.viewNoteMutex;
    v16.offset.x = 0.0;
    v16.offset.y = 0.0;
    v16.offset.z = 0.0;
    do
    {
      ++p_viewNoteMutex;
      *++p_z = *(float *)&p_viewNoteMutex->handle;
      --v7;
    }
    while ( v7 != 0 );
    v16.radius = 0.0;
    v14.b[0].z = 0.0;
    v16.isConvex = false;
    v16.pad[2] = 0;
    v16.pad[1] = 0;
    v16.pad[0] = 0;
    v14.b[0].x = -20.0;
    v14.b[0].y = -20.0;
    v14.b[1].x = 20.0;
    v14.b[1].y = 20.0;
    v14.b[1].z = 30.0;
    idTraceModel::SetupBox(this: &v16, boxBounds: &v14);
    v9 = this->presentable;
    if ( v9 != nullptr )
      v4 = v9->GetProjectileInterface(this: v9);
    else
      v4 = nullptr;
    v5 = &v16;
  }
  idPresentableProjectile::SetupClientProjectilePhysics(
    this: v4,
    physicsObj: &this->physicsObj,
    clipModelInfo: &this->clipModelInfo,
    trm: v5,
    overrideCollision: -1.0,
    cb: v2,
    a7: &this->physicsCallbacks);
  v15.animStack = this->GetAnimStack_2(this);
  idStr::idStr(this: &v15.name, text: "all");
  memset(&v15.originBlend, 0, 12);
  v15.blendOp = BOP_LERP;
  v15.alpha = 1.0;
  v10 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_Base::Init(this: &this->animator, gametimeManager: v10, parms: &v15);
  RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
  v12 = (idTreeAnimator *)_RTDynamicCast(
                            inptr: RenderModelFromPresentable,
                            VfDelta: 0,
                            SrcType: &idRenderModel `RTTI Type Descriptor',
                            TargetType: &idTreeAnimator `RTTI Type Descriptor',
                            isReference: 0);
  if ( v12 != nullptr )
  {
    v13 = this->GetAnimStack_2(this);
    idAnimStack::Init(this: v13, treeAnimator: v12);
  }
  idStr::FreeData(this: &v15.name);
}


// ========================================================================
// __unwind$497203
// EA  : 0x82ED1C0C
// RVA : 0x00ED1C0C
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_497203()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 1744 + 112));
}


// ========================================================================
// ?UpdateElectricBoltEffect@idProjectile_Arrow@@UAAXXZ
// EA  : 0x82ED1C38
// RVA : 0x00ED1C38
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Arrow::UpdateElectricBoltEffect(idProjectile_Arrow *this)
{
  idList<idElectricBolt *,5> *p_electricShocks; // r30
  idElectricBolt *v3; // r31
  int num; // r11
  int v5; // r11
  bool v6; // zf
  int v7; // r10
  idElectricBolt **v8; // r9
  int v9; // r11
  int v10; // r11
  int v11; // r10
  idEntityPtr<idEntity> *v12; // r9
  int v13; // r27
  int v14; // r30
  idGameLocal *v15; // r10
  idEntityPtr<idEntity> *v16; // r11
  idEntity *v17; // r3
  idEntity *v18; // r3
  idPhysics *Physics; // r3
  float *v20; // r3
  idEntityPtr<idEntity> *list; // r11
  double v22; // fp6
  double v23; // fp4
  int value; // r9
  idEntity *v25; // r3
  idAI2 *v26; // r3
  idAI2 *v27; // r3
  idAI2 *v28; // r31
  int v29; // r3
  char v30; // r11
  int v31; // r3
  float *v32; // r3
  double v33; // fp6
  double v34; // fp4
  idPhysics *v35; // r24
  int GameMs; // r3
  idElectricBolt **v37; // r31
  int v38; // r23
  double v39; // fp30
  const idVec3 *v40; // r3
  int v41; // r30
  int v42; // r31
  int v43; // r3
  idVec3 v44; // [sp+50h] [-70h] BYREF

  if ( this->electricPulseTime + this->startElectricTime >= idGameTimeManager::GetGameMs(
                                                              this: &clientGame->gameTimeManager,
                                                              type: GAMETIME_SCALED) )
  {
    if ( this->nextShockTime < idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
    {
      v13 = 0;
      if ( this->electricShocks.num > 0 )
      {
        v14 = 0;
        v15 = gameLocal;
        do
        {
          v16 = &this->electricTarget.list[v14];
          if ( v15->spawnIds.ptr[v16->spawnId.value & 0x1FFF] == v16->spawnId.value >> 13 )
          {
            v17 = v15->entities.ptr[v16->spawnId.value & 0x1FFF];
            if ( v17 != nullptr )
              v18 = idEntity::CastTo(c: v17);
            else
              v18 = nullptr;
            Physics = idEntity::GetPhysics(this: v18);
            v20 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
            list = this->electricTarget.list;
            v22 = (float)(v20[3] + *v20);
            v23 = (float)((float)(v20[1] + v20[4]) * (float)0.5);
            v44.z = (float)(v20[2] + v20[5]) * (float)0.5;
            v44.y = v23;
            v44.x = (float)v22 * (float)0.5;
            value = list[v14].spawnId.value;
            if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
              && (v25 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
            {
              v26 = (idAI2 *)idEntity::CastTo(c: v25);
            }
            else
            {
              v26 = nullptr;
            }
            v27 = idAI2::CastTo(c: v26);
            v28 = v27;
            if ( v27 != nullptr )
            {
              v29 = (int)v27->GetAF_2(this: v27);
              if ( *(_BYTE *)(v29 + 267) != 0 || (v30 = 0, *(_BYTE *)(v29 + 268) != 0) )
                v30 = 1;
              if ( v30 != 0 )
              {
                v31 = (int)v28->GetAF_2(this: v28);
                v32 = (float *)(*(int (__fastcall **)(int, int))(*(_DWORD *)(v31 + 288) + 44))(a1: v31 + 288, a2: -1);
                v33 = (float)(v32[5] + v32[2]);
                v34 = (float)((float)(v32[4] + v32[1]) * (float)0.5);
                v44.x = (float)(v32[3] + *v32) * (float)0.5;
                v44.y = v34;
                v44.z = (float)v33 * (float)0.5;
              }
            }
            if ( idEntity::GetPhysics(this) != nullptr )
            {
              v35 = idEntity::GetPhysics(this);
              GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
              v37 = this->electricShocks.list;
              v38 = GameMs;
              v39 = RandomFloat();
              v40 = v35->GetOrigin(this: v35, a2: 0);
              idElectricBolt::StartElectricBolt(
                this: v37[v14],
                _startTime: v38,
                _startPos: v40,
                _endPos: &v44,
                _diversity: v39);
            }
            this->nextShockTime = this->electricShockDelay
                                + idGameTimeManager::GetGameMs(
                                    this: &clientGame->gameTimeManager,
                                    type: GAMETIME_SCALED);
            v15 = gameLocal;
          }
          ++v13;
          ++v14;
        }
        while ( v13 < this->electricShocks.num );
      }
      this->nextShockTime = this->electricShockDelay
                          + idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    }
  }
  else if ( this->electricShocks.num > 0 )
  {
    p_electricShocks = &this->electricShocks;
    do
    {
      idMD6Alias::~idMD6Alias(this: *(idMD6Alias **)p_electricShocks->list);
      v3 = *p_electricShocks->list;
      if ( v3 != nullptr )
      {
        idElectricBolt::~idElectricBolt(this: *p_electricShocks->list);
        idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
      }
      num = this->electricShocks.num;
      if ( num > 0 )
      {
        this->electricShocks.num = num - 1;
        v6 = num - 1 <= 0;
        v5 = 0;
        if ( !v6 )
        {
          v7 = 0;
          do
          {
            ++v5;
            v8 = &p_electricShocks->list[v7++];
            *v8 = v8[1];
          }
          while ( v5 < this->electricShocks.num );
        }
      }
      v9 = this->electricTarget.num;
      if ( v9 > 0 )
      {
        this->electricTarget.num = v9 - 1;
        v6 = v9 - 1 <= 0;
        v10 = 0;
        if ( !v6 )
        {
          v11 = 0;
          do
          {
            ++v10;
            v12 = &this->electricTarget.list[v11++];
            v12->spawnId.value = v12[1].spawnId.value;
          }
          while ( v10 < this->electricTarget.num );
        }
      }
    }
    while ( this->electricShocks.num > 0 );
  }
  v41 = 0;
  if ( this->electricShocks.num > 0 )
  {
    v42 = 0;
    do
    {
      v43 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idElectricBolt::Update(this: this->electricShocks.list[v42], currTime: v43);
      ++v41;
      ++v42;
    }
    while ( v41 < this->electricShocks.num );
  }
}


// ========================================================================
// ?Attach@idProjectile_Dagger@@UAA_NPAVidEntity@@ABUtrace_t@@@Z
// EA  : 0x82ED2078
// RVA : 0x00ED2078
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

int __fastcall idProjectile_Dagger::Attach(idProjectile_Dagger *this, idActor *ent, const trace_t *trace)
{
  idPhysics *Physics; // r3
  idActor *v7; // r25
  idAnimatedEntity *v8; // r3
  idAnimatedEntity *v9; // r30
  int trmFeature; // r11
  idIndex<short,enum invalidJointIndex_t> *v11; // r28
  idList<idAttachment,5> *v12; // r3
  idAttachmentCollection *v13; // r3
  __int16 *p_granularity; // r10
  float *p_z; // r11
  int i; // ctr
  double v17; // fp31
  double v18; // fp30
  double v19; // fp29
  idPhysics *v20; // r3
  double v21; // fp4
  double v22; // fp3
  idPhysics *v23; // r3
  int *v24; // r9
  float *v25; // r10
  int j; // ctr
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idIndex<short,enum invalidJointIndex_t> *v29; // r27
  const idIndex<short,enum invalidJointIndex_t> *v30; // r28
  idPhysics *v31; // r26
  idPhysics *v32; // r24
  float *v33; // r26
  float *v34; // r3
  double v35; // fp9
  double v36; // fp7
  double v37; // fp6
  idAttachmentCollection *v38; // r3
  __int16 *v40; // r10
  float *v41; // r11
  int k; // ctr
  double v43; // fp31
  double v44; // fp30
  double v45; // fp29
  idPhysics *v46; // r3
  double v47; // fp3
  idPhysics *v48; // r3
  int *v49; // r9
  float *v50; // r10
  int m; // ctr
  idAttachmentCollection v52; // [sp+50h] [-140h] BYREF
  float v53; // [sp+64h] [-12Ch]
  float v54; // [sp+68h] [-128h]
  float v55; // [sp+6Ch] [-124h]
  float v56; // [sp+70h] [-120h]
  float v57; // [sp+74h] [-11Ch]
  float v58; // [sp+78h] [-118h]
  float v59; // [sp+7Ch] [-114h]
  float v60; // [sp+80h] [-110h]
  tagData_t v61; // [sp+90h] [-100h] BYREF
  float v62[4]; // [sp+B0h] [-E0h] BYREF
  float v63[3]; // [sp+C0h] [-D0h] BYREF
  int v64; // [sp+CCh] [-C4h] BYREF
  idMat3 v65; // [sp+D0h] [-C0h] BYREF
  int v66; // [sp+FCh] [-94h] BYREF
  idMat3 v67; // [sp+100h] [-90h] BYREF

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 2048, a3: -1);
  v7 = idActor::CastTo(c: ent);
  v8 = idAnimatedEntity::CastTo(c: ent);
  v9 = v8;
  if ( v8 != nullptr && v8->GetAttachments_2(this: v8) != nullptr )
  {
    if ( trace->c.type == CONTACT_SPHERE )
      trmFeature = trace->c.trmFeature;
    else
      LOWORD(trmFeature) = -1;
    v11 = (idIndex<short,enum invalidJointIndex_t> *)(__int16)trmFeature;
    if ( (__int16)trmFeature == -1 )
    {
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v9);
      presentable = v9->presentable;
      v29 = (idIndex<short,enum invalidJointIndex_t> *)TreeAnimatorFromPresentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: v9);
        presentable = v9->presentable;
      }
      idPresentable::UpdateModelTransform(this: presentable);
      if ( v29 == nullptr )
        return 0;
      v30 = (const idIndex<short,enum invalidJointIndex_t> *)HIWORD(idTreeAnimator::GetJointIndex(
                                                                      this: (idTreeAnimator *)&v52,
                                                                      result: v29,
                                                                      jointName: "origin")->__vftable);
      if ( v30 == (const idIndex<short,enum invalidJointIndex_t> *)0xFFFF )
      {
        idLib::Warning(fmt: "idProjectile::Attach - attach failed!");
        return 0;
      }
      v61.parentJoint.value = -1;
      v61.trans.x = 0.0;
      v61.trans.y = 0.0;
      v61.trans.z = 0.0;
      v61.rot.x = 0.0;
      v61.rot.y = 0.0;
      v61.rot.z = 0.0;
      v61.rot.w = 0.0;
      v31 = idEntity::GetPhysics(this: ent);
      v32 = idEntity::GetPhysics(this);
      v33 = (float *)v31->GetOrigin(this: v31, a2: 0);
      v34 = (float *)v32->GetOrigin(this: v32, a2: 0);
      v35 = (float)(*v34 - *v33);
      v36 = (float)(v34[1] - v33[1]);
      v37 = (float)(v34[2] - v33[2]);
      v61.rot.x = 0.0;
      v61.rot.y = 0.0;
      v61.rot.z = 0.0;
      v61.rot.w = 1.0;
      v61.trans.x = v35;
      v61.trans.y = v36;
      v61.trans.z = v37;
      v61.parentJoint.value = HIWORD(idTreeAnimator::GetJointHandle(
                                       this: (idTreeAnimator *)&v52,
                                       result: (idHandle<unsigned short,enum invalidJointHandle_t,65535> *)v29,
                                       jointIndex: v30)->__vftable);
      v38 = v9->GetAttachments_2(this: v9);
      v13 = idAttachmentCollection::AddAttachment(this: &v52, result: v38, ent: this, tagData: &v61);
    }
    else
    {
      v12 = (idList<idAttachment,5> *)v9->GetAttachments_2(this: v9);
      v13 = idAttachmentCollection::AddAttachment(this: &v52, result: v12, ent: this, jointIndex: v11);
    }
    if ( v13->attachments.list != (idAttachment *)-1 )
    {
      p_granularity = &v52.attachments.granularity;
      p_z = &this->lastVel.z;
      for ( i = 9; i != 0; --i )
      {
        ++p_z;
        p_granularity += 2;
        *(float *)p_granularity = *p_z;
      }
      v17 = (float)((float)(this->originOffset.x * *(float *)&v52.parent)
                  + (float)((float)(this->originOffset.z * v58) + (float)(this->originOffset.y * v55)));
      v18 = (float)((float)(this->originOffset.y * v56)
                  + (float)((float)(this->originOffset.x * v53) + (float)(this->originOffset.z * v59)));
      v19 = (float)((float)(this->originOffset.y * v57)
                  + (float)((float)(this->originOffset.x * v54) + (float)(this->originOffset.z * v60)));
      v20 = idEntity::GetPhysics(this);
      v21 = (float)(trace->c.point.y + (float)v18);
      v22 = (float)(trace->c.point.z + (float)v19);
      v63[0] = trace->c.point.x + (float)v17;
      v63[1] = v21;
      v63[2] = v22;
      v20->SetOrigin(this: v20, a2: (const idVec3 *)v63, a3: -1);
      v23 = idEntity::GetPhysics(this);
      v24 = &v64;
      v25 = &this->lastVel.z;
      for ( j = 9; j != 0; --j )
        *++v24 = *(_DWORD *)++v25;
      v23->SetAxis(this: v23, a2: &v65, a3: -1);
      goto LABEL_26;
    }
    return 0;
  }
  v40 = &v52.attachments.granularity;
  v41 = &this->lastVel.z;
  for ( k = 9; k != 0; --k )
  {
    ++v41;
    v40 += 2;
    *(float *)v40 = *v41;
  }
  v43 = (float)((float)(this->originOffset.x * v53)
              + (float)((float)(this->originOffset.z * v59) + (float)(this->originOffset.y * v56)));
  v44 = (float)((float)(this->originOffset.y * v55)
              + (float)((float)(this->originOffset.x * *(float *)&v52.parent) + (float)(this->originOffset.z * v58)));
  v45 = (float)((float)(this->originOffset.x * v54)
              + (float)((float)(this->originOffset.z * v60) + (float)(this->originOffset.y * v57)));
  v46 = idEntity::GetPhysics(this);
  v62[0] = trace->c.point.x + (float)v44;
  v47 = (float)(trace->c.point.z + (float)v45);
  v62[1] = trace->c.point.y + (float)v43;
  v62[2] = v47;
  v46->SetOrigin(this: v46, a2: (const idVec3 *)v62, a3: -1);
  v48 = idEntity::GetPhysics(this);
  v49 = &v66;
  v50 = &this->lastVel.z;
  for ( m = 9; m != 0; --m )
    *++v49 = *(_DWORD *)++v50;
  v48->SetAxis(this: v48, a2: &v67, a3: -1);
  idEntity::Bind(this, master: (idWorldspawn *)ent, orientated: true);
LABEL_26:
  if ( v7 != nullptr )
    idActor::SetAttachedLoot(this: v7, object: this);
  return 1;
}


// ========================================================================
// ?Contact@idProjectile_Arrow@@UAA?AW4collide_t@@HAAUcontactInfo_t@@@Z
// EA  : 0x82ED2500
// RVA : 0x00ED2500
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

int __fastcall idProjectile_Arrow::Contact(idProjectile_Dagger *this, int physId, contactInfo_t *contact)
{
  double y; // fp13
  double z; // fp12
  float *v8; // r3
  idPhysics *Physics; // r3
  idProjectile_Dagger_vtbl *v10; // r31
  int v11; // r3
  float v13[13]; // [sp+50h] [-E0h] BYREF
  contactInfo_t v14; // [sp+84h] [-ACh] BYREF
  char v15; // [sp+D0h] [-60h] BYREF
  idVec3 v16[6]; // [sp+E0h] [-50h] BYREF

  contactInfo_t::operator=(this: &v14, __that: contact);
  y = contact->point.y;
  z = contact->point.z;
  v13[1] = contact->point.x;
  v13[2] = y;
  v13[3] = z;
  v8 = (float *)idVec3::ToMat3(this: v16, result: (idMat3 *)&contact->normal);
  v13[4] = *v8;
  v13[5] = v8[1];
  v13[6] = v8[2];
  v13[7] = v8[3];
  v13[8] = v8[4];
  v13[9] = v8[5];
  v13[10] = v8[6];
  v13[11] = v8[7];
  v13[12] = v8[8];
  v13[0] = 0.0;
  Physics = idEntity::GetPhysics(this);
  v10 = this->__vftable;
  v11 = (int)Physics->GetLinearVelocity(this: (idPhysics *)&v15, result: (idVec3 *)Physics, a3: 0);
  return v10->Collide(this, a2: physId, a3: (trace_t *)v13, a4: (const idVec3 *)v11);
}


// ========================================================================
// ?StartDetonationTimer@idProjectile_Grenade@@QAAXH@Z
// EA  : 0x82ED25F0
// RVA : 0x00ED25F0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Grenade::StartDetonationTimer(idProjectile_Grenade *this, int startTime)
{
  unsigned int v2; // r5
  __int128 v3; // r11
  __int64 v4; // r6
  double v5; // fp9
  int back_chain_4; // [sp+4h] [-Ch]

  if ( this->detonationTime < 0 && this->projectileDecl->notHitscanInfo.grenadeInfo.maxDetonationDelay >= 0 )
  {
    v2 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v2;
    DWORD1(v3) = v2;
    DWORD2(v3) = this->projectileDecl;
    LODWORD(v4) = (v2 >> 10) & 0x7FFF;
    HIDWORD(v4) = *(_DWORD *)(DWORD2(v3) + 392);
    LODWORD(v3) = HIDWORD(v4);
    v5 = (double)(__int64)v3;
    DWORD2(v3) = *(_DWORD *)(DWORD2(v3) + 388);
    this->startDetonationTime = startTime;
    back_chain_4 = (int)(float)((float)((float)((float)((float)v5 - (float)*(__int64 *)((char *)&v3 + 4)) * (float)v4)
                                      * (float)0.000030518509)
                              + (float)*(__int64 *)((char *)&v3 + 4));
    this->detonationTime = back_chain_4 + startTime;
    this->detonationDelay = back_chain_4;
  }
}


// ========================================================================
// ?DeactivatePhysics@idProjectile_Grenade@@UAAXH@Z
// EA  : 0x82ED26B0
// RVA : 0x00ED26B0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Grenade::DeactivatePhysics(idProjectile_Grenade *this, int physId)
{
  int v4; // r3
  idEntity *v5; // r3

  v4 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idProjectile_Grenade::StartDetonationTimer(this, startTime: v4);
  idEntity::DeactivatePhysics(this: v5, physId);
}


// ========================================================================
// ?Event_Touch@idProjectile_BouncyBomb@@AAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82ED2718
// RVA : 0x00ED2718
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

idProjectile_BouncyBomb *__fastcall idProjectile_BouncyBomb::Event_Touch(
        idProjectile_BouncyBomb *this,
        eventVoid *result,
        idVehicle *other,
        int clipModelId)
{
  idEntity *Driver; // r28
  idVehicle *v8; // r3

  if ( *(_BYTE *)&result[5480] != 0 && (unsigned __int8)idVehicle::IsTypeOf(c: other) != 0 )
  {
    Driver = nullptr;
    v8 = idVehicle::CastTo(c: other);
    if ( v8 != nullptr )
      Driver = idVehicle::GetDriver(this: v8);
    if ( proj_ExplodeOnSelf.valueInteger != 0
      || other != idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)&result[6136])
      && Driver != idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)&result[6136]) )
    {
      (*(void (__fastcall **)(eventVoid *, idVehicle *, _DWORD))(*(_DWORD *)result + 672))(a1: result, a2: other, a3: 0);
    }
  }
  return this;
}


// ========================================================================
// ?SetAttacker@idProjectile@@QAAXPAVidEntity@@@Z
// EA  : 0x82ED2928
// RVA : 0x00ED2928
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile::SetAttacker(idProjectile *this, idEntity *a)
{
  idPresentable *presentable; // r3
  idPresentable *v5; // r31
  idPresentable *v6; // r3
  int v7; // r3
  unsigned int spawnId; // r11

  if ( a != nullptr )
  {
    presentable = this->presentable;
    if ( presentable != nullptr && presentable->GetProjectileInterface(this: presentable) != nullptr )
    {
      if ( a->presentable == nullptr )
        idEntity::InitPresentableInternal(this: a);
      v5 = a->presentable;
      v6 = this->presentable;
      if ( v6 != nullptr )
        v7 = (int)v6->GetProjectileInterface(this: v6);
      else
        v7 = 0;
      spawnId = 0;
      if ( v5 != nullptr )
        spawnId = v5->spawnId;
      *(_DWORD *)(v7 + 1260) = spawnId;
    }
    this->AttachAIEvents(this);
  }
}


// ========================================================================
// ?AttachToJoint@idProjectile_Rocket@@UAA_NPAVidEntity@@V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82ED29F8
// RVA : 0x00ED29F8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

int __fastcall idProjectile_Rocket::AttachToJoint(
        idProjectile_Rocket *this,
        idAnimatedEntity *ent,
        idIndex<short,enum invalidJointIndex_t> *jointIndex)
{
  int v5; // r3
  idPresentable *presentable; // r11
  double startJetSpeed; // fp31

  if ( idProjectile::AttachToJoint(this, ent, jointIndex) )
  {
    if ( ent != nullptr )
      this->attachedToEnt.spawnId.value = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
    else
      this->attachedToEnt.spawnId.value = 0x1FFF;
    v5 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idProjectile::SetLaunchTime(this, time: v5);
    presentable = this->presentable;
    startJetSpeed = this->startJetSpeed;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    presentable->GetProjectileRocketInterface(this: presentable)->goalSpeed = startJetSpeed;
  }
  return 0;
}


// ========================================================================
// ?AttachToTag@idProjectile_Rocket@@UAA_NPAVidEntity@@UtagData_t@@@Z
// EA  : 0x82ED2AD8
// RVA : 0x00ED2AD8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

int __fastcall idProjectile_Rocket::AttachToTag(
        idProjectile_Rocket *this,
        idAnimatedEntity *ent,
        __int64 tagData,
        __int64 a4,
        int a5,
        int a6)
{
  int v8; // r3
  idPresentable *presentable; // r11
  double startJetSpeed; // fp31
  __int64 v12; // [sp+8h] [-68h]
  __int64 v13; // [sp+10h] [-60h]
  __int64 v14; // [sp+18h] [-58h]
  __int64 v15; // [sp+20h] [-50h]
  __int64 v16; // [sp+28h] [-48h]
  __int64 v17; // [sp+30h] [-40h]
  __int64 v18; // [sp+38h] [-38h]

  if ( idProjectile::AttachToTag(
         this,
         ent,
         tagData,
         a4,
         a5,
         a6,
         a7: v12,
         a8: v13,
         a9: v14,
         a10: v15,
         a11: v16,
         a12: v17,
         a13: v18) )
  {
    if ( ent != nullptr )
      this->attachedToEnt.spawnId.value = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
    else
      this->attachedToEnt.spawnId.value = 0x1FFF;
    v8 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idProjectile::SetLaunchTime(this, time: v8);
    presentable = this->presentable;
    startJetSpeed = this->startJetSpeed;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    presentable->GetProjectileRocketInterface(this: presentable)->goalSpeed = startJetSpeed;
  }
  return 0;
}


// ========================================================================
// ?RocketConstraint@idProjectile_Rocket@@QAA_NPAVidAI2@@AAV?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82ED2BC0
// RVA : 0x00ED2BC0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

int __fastcall idProjectile_Rocket::RocketConstraint(
        idProjectile_Rocket *this,
        idAI2 *ai,
        idIndex<short,enum invalidJointIndex_t> *joint)
{
  char *data; // r26
  int v7; // r3
  __int64 v8; // r8
  __int64 v9; // r10
  va *v10; // r3
  idStr *v11; // r26
  idIndex<short,enum invalidJointIndex_t> *value; // r27
  idAnimator_AF *v13; // r3
  int v14; // r27
  idAnimator_AF *v15; // r3
  idPhysics *Physics; // r27
  idPhysics *v17; // r26
  idPhysics_AF *p_physicsObj; // r25
  idPhysics *v19; // r3
  idPhysics_AF_vtbl *v20; // r27
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // ctr
  int v22; // r24
  int v23; // r3
  idPhysics *v24; // r3
  double v25; // fp31
  idPhysics *v26; // r3
  int v27; // r3
  int v29; // [sp+8h] [-10E8h]
  int v30; // [sp+Ch] [-10E4h]
  int v31; // [sp+10h] [-10E0h]
  int v32; // [sp+14h] [-10DCh]
  int v33; // [sp+18h] [-10D8h]
  int v34; // [sp+1Ch] [-10D4h]
  idVec3 v35; // [sp+58h] [-1098h] BYREF
  float v36[6]; // [sp+68h] [-1088h] BYREF
  idStr v37; // [sp+80h] [-1070h] BYREF
  va v38; // [sp+A0h] [-1050h] BYREF

  if ( ai->GetAF_2(this: ai) == nullptr || ai->GetAF_2(this: ai) == (idAnimator_AF *)-288 )
  {
    if ( ai->GetAF_2(this: ai) == nullptr )
      idLib::Warning(fmt: "RocketConstraint called on AI %s but it has no AF", ai->name.data);
    if ( ai->GetAF_2(this: ai) == (idAnimator_AF *)-288 )
      idLib::Warning(fmt: "RocketConstraint called on AI %s but it's AF has no physics", ai->name.data);
    return 0;
  }
  else
  {
    data = this->constraintName.data;
    v7 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    LODWORD(v8) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
    v10 = va::va(
            this: &v38,
            fmt: "%s_%i",
            a3: __SPAIR64__((unsigned int)data, v7),
            a4: v8,
            a5: v9,
            a6: v29,
            a7: v30,
            a8: v31,
            a9: v32,
            a10: v33,
            a11: v34);
    v11 = idStr::idStr(this: &v37, text: v10);
    value = (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)joint->value;
    v13 = ai->GetAF_2(this: ai);
    v14 = idAnimator_AF::BodyForJoint(this: v13, joint: value);
    v15 = ai->GetAF_2(this: ai);
    idAnimator_AF::AddDynamicBindConstraint(this: v15, bodyIndex: v14, constraintName: v11);
    this->constraintTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idEntity::Bind(this: ai, master: (idWorldspawn *)this, orientated: true);
    Physics = idEntity::GetPhysics(this);
    v17 = idEntity::GetPhysics(this);
    p_physicsObj = &ai->GetAF_2(this: ai)->physicsObj;
    v19 = Physics;
    GetAxis = Physics->GetAxis;
    v20 = p_physicsObj->__vftable;
    v22 = (int)GetAxis(this: v19, a2: 0);
    v23 = (int)v17->GetOrigin(this: v17, a2: 0);
    v20->SetMaster(this: p_physicsObj, a2: true, a3: (const idVec3 *)v23, a4: (const idMat3 *)v22, a5: BIND_ORIENTED);
    v24 = idEntity::GetPhysics(this);
    v24->GetLinearVelocity(this: (idPhysics *)&v35, result: (idVec3 *)v24, a3: 0);
    v25 = idVec3::NormalizeFast(this: &v35);
    if ( idProjectile_Rocket::GetGoalSpeed(this) > 1000.0 )
      idProjectile_Rocket::SetGoalSpeed(this, value: 1000.0);
    v26 = idEntity::GetPhysics(this);
    v36[0] = v35.x * (float)((float)v25 * (float)0.25);
    v36[1] = v35.y * (float)((float)v25 * (float)0.25);
    v36[2] = v35.z * (float)((float)v25 * (float)0.25);
    v26->SetLinearVelocity(this: v26, a2: (const idVec3 *)v36, a3: 0);
    v27 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idProjectile::SetLaunchTime(this, time: v27);
    this->stuckOnActor.spawnId.value = (gameLocal->spawnIds.ptr[ai->entityNumber] << 13) | ai->entityNumber;
    return 1;
  }
}


// ========================================================================
// __unwind$499002
// EA  : 0x82ED2EC8
// RVA : 0x00ED2EC8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_499002()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 4336 + 80));
}


// ========================================================================
// ?NotifyEntityAboutHoming@idProjectile_Homing@@AAAXPBVidEntity@@_N@Z
// EA  : 0x82ED2EF0
// RVA : 0x00ED2EF0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Homing::NotifyEntityAboutHoming(
        idProjectile_Homing *this,
        const idEntity *ent,
        bool addNew)
{
  idEntity *v3; // r10
  int value; // r8
  idEntity *v5; // r3
  idEntity *v6; // r3
  int v7; // r10
  idEntityPtr<idEntity> *p_notifiedEntity; // r31
  idEntity *v9; // r3
  idEntity *v10; // r3

  if ( addNew )
  {
    if ( ent != nullptr )
    {
      v3 = gameLocal->entities.ptr[ent->entityNumber];
      if ( v3 != nullptr )
        this->notifiedEntity.spawnId.value = (gameLocal->spawnIds.ptr[v3->entityNumber] << 13) | v3->entityNumber;
      else
        this->notifiedEntity.spawnId.value = 0x1FFF;
      value = this->notifiedEntity.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v6 = idEntity::CastTo(c: v5);
        v6->AddProjectileLock(this: v6);
      }
      else
      {
        (*(void (**)(void))(MEMORY[0] + 324))();
      }
      return;
    }
    if ( addNew )
      return;
  }
  v7 = this->notifiedEntity.spawnId.value;
  p_notifiedEntity = &this->notifiedEntity;
  if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] == v7 >> 13 )
  {
    v9 = gameLocal->entities.ptr[v7 & 0x1FFF];
    if ( v9 != nullptr && idEntity::CastTo(c: v9) != nullptr )
    {
      v10 = idEntityPtr<idEntity const>::operator->(this: p_notifiedEntity);
      v10->RemoveProjectileLock(this: v10);
      p_notifiedEntity->spawnId.value = 0x1FFF;
    }
  }
}


// ========================================================================
// ?NotifyEntityAboutHoming_FromPresentable@idProjectile_Homing@@QAAXPBVidEntity@@_N@Z
// EA  : 0x82ED3070
// RVA : 0x00ED3070
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

// attributes: thunk
void __fastcall idProjectile_Homing::NotifyEntityAboutHoming_FromPresentable(
        idProjectile_Homing *this,
        const idEntity *ent,
        bool addNew)
{
  idProjectile_Homing::NotifyEntityAboutHoming(this, ent, addNew);
}


// ========================================================================
// ?InternalLaunch@idProjectile_StickyBomb@@MAAXPAVidEntity@@ABVidVec3@@ABVidMat3@@ABVidProjectileTarget@@MH@Z
// EA  : 0x82ED3078
// RVA : 0x00ED3078
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_StickyBomb::InternalLaunch(
        idProjectile_StickyBomb *this,
        idVehicle *attacker_,
        const idVec3 *start,
        const idMat3 *fireAxis,
        const idProjectileTarget *target,
        double initialSpeed,
        const int startTime)
{
  idPhysics *Physics; // r3
  idPhysics *v10; // r3
  idPhysics *v11; // r3
  int GameMs; // r3
  BOOL useTeamColor; // r10
  gameTeam_t Team; // r3
  idVehicle *v15; // r29
  idPlayer *v16; // r30
  idPlayer *Driver; // r3
  idPresentable *presentable; // r3
  idPresentable *v19; // r3
  int v20; // r3
  idPresentable *v21; // r11
  int v22; // r30
  idPresentable *v23; // r3
  int v24; // r3
  int v25; // r30
  const idAnimStack *v26; // r3
  const blendParms_t *v27; // r7
  blendParms_t v28[4]; // [sp+60h] [-50h] BYREF

  if ( attacker_ != nullptr )
  {
    Physics = idEntity::GetPhysics(this);
    Physics->GetClipModel(this: Physics, a2: 0)->ownerNumber = 0x1FFF;
    this->ignoreEntity.spawnId.value = (gameLocal->spawnIds.ptr[attacker_->entityNumber] << 13)
                                     | attacker_->entityNumber;
    this->ignoreTimeout = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) + 1000;
    this->armed = false;
    v10 = idEntity::GetPhysics(this);
    v10->SetClipMask(this: v10, a2: 1, a3: -1);
    if ( idEntity::GetPhysics(this)->type == PHYSICS_RIGIDBODY )
    {
      v11 = idEntity::GetPhysics(this);
      HIBYTE(v11[5].entityNumber) |= 0xC0u;
    }
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    useTeamColor = this->useTeamColor;
    this->explodeTimer = GameMs - (int)(float)(this->explodeDelayTime * (float)-1000.0);
    if ( useTeamColor )
    {
      Team = idEntity::GetTeam(this: attacker_);
      idEntity::SetTeam(this, team: Team);
      v15 = idVehicle::CastTo(c: attacker_);
      v16 = idPlayer::CastTo(c: (idPlayer *)attacker_);
      if ( v15 != nullptr )
      {
        Driver = (idPlayer *)idVehicle::GetDriver(this: v15);
        v16 = idPlayer::CastTo(c: Driver);
      }
      if ( v16 != nullptr )
      {
        presentable = v16->presentable;
        if ( presentable != nullptr && presentable->GetPlayerInterface_2(this: presentable) != nullptr )
        {
          v19 = v16->presentable;
          if ( v19 != nullptr )
            v20 = (int)v19->GetPlayerInterface_2(this: v19);
          else
            v20 = 0;
          v21 = this->presentable;
          v22 = *(_DWORD *)(v20 + 180);
          if ( v21 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v21 = this->presentable;
          }
          idPresentable::SetOwnerPlayerIndex(this: v21, value: v22);
        }
      }
    }
    idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
    if ( this->projectileDecl->notHitscanInfo.grenadeInfo.warningSound != nullptr
      && !idEntity::IsPlayingSound(this, channel: SND_CHANNEL_BODY3) )
    {
      v23 = this->presentable;
      if ( v23 != nullptr )
        v24 = (int)v23->GetProjectileInterface(this: v23);
      else
        v24 = 0;
      *(_BYTE *)(v24 + 1264) = 1;
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_BODY3,
        shader: this->projectileDecl->notHitscanInfo.grenadeInfo.warningSound,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
    }
    blendParms_t::blendParms_t(this: v28);
    blendParms_t::SetDuration(this: v28, frame: 5);
    v25 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v26 = this->GetAnimStack_2(this);
    idAnimator_Channel::PlayAnim(
      this: &this->animator,
      stack: v26,
      ah: &this->animHandle,
      curTime: v25,
      rateScale: 1.0,
      blendParms: v27,
      blendOutDurationMS_: v28,
      leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
      a9: nullptr);
    idEntity::BecomeActive(this, flags: 1);
    idEntity::BecomeActive(this, flags: 4);
    idEntity::UpdateVisuals(this);
  }
}


// ========================================================================
// ?ShouldStickOnCollision@idProjectile_Arrow@@UAA_NABUtrace_t@@@Z
// EA  : 0x82ED3358
// RVA : 0x00ED3358
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

int __fastcall idProjectile_Arrow::ShouldStickOnCollision(idProjectile_Arrow *this, const trace_t *collision)
{
  int v4; // r9
  idAI2 *v5; // r31
  idPhysics *Physics; // r3
  float *v7; // r3
  idAI2 *v8; // r31
  const idPresentable *Attacker; // r30
  idFaction *v10; // r3
  idRelationship::attitude_t AttitudeTowards; // r3
  int result; // r3
  unsigned int v13; // r4

  if ( collision->fraction >= 1.0 )
    return 0;
  v4 = collision->c.entityNum + 21563;
  v5 = *((idAI2 **)&gameLocal->__vftable + v4);
  if ( v5 == nullptr
    || (unsigned __int8)idWaterEntity::IsTypeOf(c: *((idClass **)&gameLocal->__vftable + v4)) != 0
    || (unsigned __int8)idVehicle::IsTypeOf(c: v5) != 0
    || (unsigned __int8)idPlayer::IsTypeOf(c: v5) != 0
    || (unsigned __int8)idProp_Breakable::IsTypeOf(c: v5) != 0
    || (unsigned __int8)idBreakable::IsTypeOf(c: v5) != 0
    || (unsigned __int8)idDamageableEntity::IsTypeOf(c: v5) != 0
    || (unsigned __int8)idDrone::IsTypeOf(c: v5) != 0
    || (unsigned __int8)idTurret::IsTypeOf(c: v5) != 0 )
  {
    return 0;
  }
  if ( !this->forceStick
    && ((unsigned __int8)idWorldspawn::IsTypeOf(c: v5) != 0 || (unsigned __int8)idStaticEntity::IsTypeOf(c: v5) != 0) )
  {
    Physics = idEntity::GetPhysics(this);
    v7 = (float *)Physics->GetAxis(this: Physics, a2: 0);
    if ( (float)((float)(collision->c.normal.x * (float)-*v7)
               + (float)((float)(collision->c.normal.z * (float)-v7[2]) + (float)(collision->c.normal.y * (float)-v7[1]))) < (double)this->reflectionCosine )
      return 0;
  }
  if ( (unsigned __int8)idAI2::IsTypeOf(c: v5) != 0 )
  {
    v8 = idAI2::CastTo(c: v5);
    Attacker = idProjectile::GetAttacker(this);
    v10 = v8->GetFaction(this: v8);
    AttitudeTowards = idFaction::GetAttitudeTowards(this: v10, otherPres: Attacker);
    return ((AttitudeTowards >= ATTITUDE_DESPISE) + ((unsigned int)AttitudeTowards >= ATTITUDE_NEUTRAL)) & 1;
  }
  if ( this->forceStick )
    return 1;
  v13 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v13;
  result = 1;
  if ( (signed int)(((v13 >> 10) & 0x7FFF) % 0x64) > this->stickChance )
    return 0;
  return result;
}


// ========================================================================
// ?InternalLaunch_FromPresentable@idProjectile_BouncyBomb@@UAAXPAVidPresentable@@ABVidVec3@@ABVidMat3@@ABVidProjectileTarget@@MH@Z
// EA  : 0x82ED35B8
// RVA : 0x00ED35B8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_BouncyBomb::InternalLaunch_FromPresentable(
        idProjectile_BouncyBomb *this,
        idPresentable *attacker,
        const idVec3 *start,
        const idMat3 *fireAxis,
        const idProjectileTarget *target,
        double initialSpeed,
        int startTime,
        int a8)
{
  idPhysics *Physics; // r3
  idPhysics *v12; // r3
  idPhysics *v13; // r3
  idEntity *entity; // r11
  idPhysics *v15; // r3
  char v16; // [sp+50h] [-30h] BYREF

  idEntity::BecomeActive(this, flags: 1);
  if ( this->projectileDecl->notHitscanInfo.grenadeInfo.countDownOnThrow )
    idProjectile_Grenade::StartDetonationTimer(this, startTime: a8);
  Physics = idEntity::GetPhysics(this);
  Physics->GetClipModel(this: Physics, a2: 0)->ownerNumber = 0x1FFF;
  v12 = idEntity::GetPhysics(this);
  v12->SetClipMask(this: v12, a2: 1, a3: -1);
  v13 = idEntity::GetPhysics(this);
  v13->SetContents(this: v13, a2: 0x4000, a3: -1);
  entity = attacker->entity;
  if ( entity != nullptr )
    this->ignoreEntity.spawnId.value = (gameLocal->spawnIds.ptr[entity->entityNumber] << 13) | entity->entityNumber;
  v15 = idEntity::GetPhysics(this);
  v15->GetLinearVelocity(this: (idPhysics *)&v16, result: (idVec3 *)v15, a3: 0);
}


// ========================================================================
// ?AttachAIEvents@idProjectile@@UAAXXZ
// EA  : 0x82ED3778
// RVA : 0x00ED3778
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile::AttachAIEvents(idProjectile *this)
{
  idHandle<int,enum invalidAIEvent_t,-1> *p_aiEventHandle; // r30
  idPhysics *Physics; // r3
  idPresentable *presentable; // r11
  idPhysics *v5; // r28
  idPresentableProjectile *v6; // r3
  const idEntity *AttackerEntity; // r26
  int GameMs; // r27
  const idDeclProjectile *projectileDecl; // r25
  idAIEventManager *p_aiEventManager; // r29
  const idVec3 *v11; // r3
  idAIEventManager *v12; // r3
  bool v13; // cr58
  idAIEventManager v14; // [sp+50h] [-50h] BYREF

  p_aiEventHandle = &this->aiEventHandle;
  if ( this->aiEventHandle.value != -1 )
  {
    idAIEventManager::RemoveEvent(this: &gameLocal->aiEventManager, handle: &this->aiEventHandle);
    p_aiEventHandle->value = -1;
  }
  if ( this->projectileDecl->aiEventDecl != nullptr )
  {
    Physics = idEntity::GetPhysics(this);
    presentable = this->presentable;
    v5 = Physics;
    if ( presentable != nullptr )
      v6 = presentable->GetProjectileInterface(this: this->presentable);
    else
      v6 = nullptr;
    AttackerEntity = idPresentableProjectile::GetAttackerEntity(this: v6);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    projectileDecl = this->projectileDecl;
    p_aiEventManager = &gameLocal->aiEventManager;
    v11 = v5->GetOrigin(this: v5, a2: 0);
    v12 = idAIEventManager::AddEvent(
            this: &v14,
            result: p_aiEventManager,
            eventDecl: projectileDecl->aiEventDecl,
            curTime: GameMs,
            originator: this,
            instigator: AttackerEntity,
            origin: v11,
            delay: 0);
    v13 = v12->eventList.list == (idAIEvent **)-1;
    p_aiEventHandle->value = (int)v12->eventList.list;
    if ( v13 )
      idLib::Warning(fmt: "Wrong aiEventDecl specified in projectile def '%s'", this->projectileDecl->name.str);
  }
}


// ========================================================================
// ?GetFaction@idProjectile@@UAAPAVidFaction@@XZ
// EA  : 0x82ED3898
// RVA : 0x00ED3898
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

idFaction *__fastcall idProjectile::GetFaction(idProjectile *this)
{
  idPresentable *presentable; // r3
  idPresentableProjectile *v3; // r3
  idFaction *result; // r3
  idPresentable *v5; // r3
  idPresentableProjectile *v6; // r3
  idEntity *AttackerEntity; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = presentable->GetProjectileInterface(this: presentable);
  else
    v3 = nullptr;
  result = (idFaction *)idPresentableProjectile::GetAttackerEntity(this: v3);
  if ( result != nullptr )
  {
    v5 = this->presentable;
    if ( v5 != nullptr )
      v6 = v5->GetProjectileInterface(this: v5);
    else
      v6 = nullptr;
    AttackerEntity = idPresentableProjectile::GetAttackerEntity(this: v6);
    return AttackerEntity->GetFaction(this: AttackerEntity);
  }
  return result;
}


// ========================================================================
// ?Collide@idProjectile_Rocket@@UAA?AW4collide_t@@HAAUtrace_t@@ABVidVec3@@@Z
// EA  : 0x82ED3940
// RVA : 0x00ED3940
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

int __fastcall idProjectile_Rocket::Collide(
        idProjectile_Rocket *this,
        const int physId,
        trace_t *collision,
        const idVec3 *velocity,
        __int64 a5,
        __int64 a6)
{
  idAI2 *v9; // r29
  idEntityPtr<idEntity> *p_stuckOnActor; // r25
  idGameLocal *v11; // r27
  int v12; // r26
  idAI2_vtbl *v13; // r27
  const idDeclDamage *damageDecl; // r26
  idEntity *AttackerEntity; // r3
  idAI2_vtbl *v16; // r27
  idEntity *v17; // r10
  const idDeclProjectile *projectileDecl; // r29
  const idPresentable *Attacker; // r3
  _BYTE v20[80]; // [sp+50h] [-A0h] BYREF
  idIndex<short,enum invalidJointIndex_t> v21[40]; // [sp+A0h] [-50h] BYREF

  LODWORD(a6) = collision->c.surfaceFlags & 1;
  if ( (_DWORD)a6 != 0 )
  {
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0, a4: (int)velocity, a5, a6);
    return 1;
  }
  if ( this->allowConstraint
    && (unsigned __int8)idAI2::IsTypeOf(c: gameLocal->entities.ptr[collision->c.entityNum]) != 0 )
  {
    v9 = idAI2::CastTo(c: (idAI2 *)gameLocal->entities.ptr[collision->c.entityNum]);
    if ( (*((_BYTE *)&v9->aiEditable.behaviors.decl->damageBehaviors + 85) & 0x80) != 0
      && g_projectileImpale.valueInteger != 0 )
    {
      p_stuckOnActor = &this->stuckOnActor;
      if ( idEntityPtr<idEntity const>::operator->(this: &this->stuckOnActor) != nullptr )
      {
        v11 = gameLocal;
        v12 = 4 * (collision->c.entityNum + 21563);
        if ( idEntityPtr<idEntity const>::operator->(this: &this->stuckOnActor) == *(idEntity **)((char *)&v11->__vftable
                                                                                                + v12) )
          return 2;
      }
      if ( idEntityPtr<idEntity const>::operator->(this: &this->stuckOnActor) == nullptr )
      {
        v13 = v9->__vftable;
        damageDecl = this->projectileDecl->damageDecl;
        AttackerEntity = idProjectile::GetAttackerEntity(this);
        ((void (__fastcall *)(idAI2 *, idProjectile_Rocket *, idEntity *, const idDeclDamage *, double))v13->Damage)(
          a1: v9,
          a2: this,
          a3: AttackerEntity,
          a4: damageDecl,
          a5: 1000.0);
        v16 = v9->__vftable;
        memcpy(Dst: v20, Src: &collision->endAxis.mat[2].z, Size: sizeof(v20));
        ((void (__fastcall *)(idIndex<short,enum invalidJointIndex_t> *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v16->GetJointIndexFromTrace)(
          a1: v21,
          a2: LODWORD(collision->fraction),
          a3: LODWORD(collision->endpos.y),
          a4: LODWORD(collision->endAxis.mat[0].x),
          a5: LODWORD(collision->endAxis.mat[0].z),
          a6: LODWORD(collision->endAxis.mat[1].y),
          a7: LODWORD(collision->endAxis.mat[2].x),
          a8: LODWORD(collision->endAxis.mat[2].y));
        if ( (unsigned __int8)idProjectile_Rocket::RocketConstraint(this, ai: v9, joint: v21) != 0 )
        {
          v17 = gameLocal->entities.ptr[collision->c.entityNum];
          if ( v17 == nullptr )
          {
            p_stuckOnActor->spawnId.value = 0x1FFF;
            return 2;
          }
          p_stuckOnActor->spawnId.value = (gameLocal->spawnIds.ptr[v17->entityNumber] << 13) | v17->entityNumber;
          return 2;
        }
      }
    }
  }
  projectileDecl = this->projectileDecl;
  Attacker = idProjectile::GetAttacker(this);
  idClientGame::ProjectileImpact(
    this: clientGame,
    trace: collision,
    attacker: Attacker,
    projDef: projectileDecl,
    tracerFired: false,
    noDecals: false,
    noSounds: false);
  this->Explode(this, a2: gameLocal->entities.ptr[collision->c.entityNum], a3: collision);
  return 1;
}


// ========================================================================
// ?Collide@idProjectile_Homing@@UAA?AW4collide_t@@HAAUtrace_t@@ABVidVec3@@@Z
// EA  : 0x82ED3BA0
// RVA : 0x00ED3BA0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

collide_t __fastcall idProjectile_Homing::Collide(
        idProjectile_Homing *this,
        const int physId,
        trace_t *collision,
        const idVec3 *velocity,
        __int64 a5,
        __int64 a6)
{
  collide_t result; // r3
  idAI2 *v9; // r28
  idAI2_vtbl *v10; // r27
  const idDeclDamage *damageDecl; // r26
  idEntity *AttackerEntity; // r3
  idEntity *v13; // r10
  idProjectile_Homing_vtbl *v14; // r9

  LODWORD(a6) = collision->c.surfaceFlags & 1;
  if ( (_DWORD)a6 != 0 )
  {
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0, a4: (int)velocity, a5, a6);
    return COLLIDE_STOP_SIMULATION;
  }
  else if ( (unsigned __int8)idAI2::IsTypeOf(c: gameLocal->entities.ptr[collision->c.entityNum]) != 0
         && (unsigned __int8)idProjectile_Rocket::IsActorStuckOn(
                               this,
                               ent: gameLocal->entities.ptr[collision->c.entityNum]) != 0
         && (v9 = idAI2::CastTo(c: (idAI2 *)gameLocal->entities.ptr[collision->c.entityNum]))->actorConstants.actorClass == ACTORCLASS_MUTANT )
  {
    v10 = v9->__vftable;
    damageDecl = this->projectileDecl->damageDecl;
    AttackerEntity = idProjectile::GetAttackerEntity(this);
    ((void (__fastcall *)(idAI2 *, idProjectile_Homing *, idEntity *, const idDeclDamage *, double))v10->Damage)(
      a1: v9,
      a2: this,
      a3: AttackerEntity,
      a4: damageDecl,
      a5: 10.0);
    v13 = gameLocal->entities.ptr[collision->c.entityNum];
    result = COLLIDE_IGNORE_COLLISION;
    if ( v13 != nullptr )
      this->stuckOnActor.spawnId.value = (gameLocal->spawnIds.ptr[v13->entityNumber] << 13) | v13->entityNumber;
    else
      this->stuckOnActor.spawnId.value = 0x1FFF;
  }
  else
  {
    v14 = this->__vftable;
    this->numSubMunitions = 0;
    v14->Explode(this, a2: gameLocal->entities.ptr[collision->c.entityNum], a3: collision);
    return COLLIDE_IGNORE_COLLISION;
  }
  return result;
}


// ========================================================================
// ?SetProjectileTarget@idProjectile_Homing@@QAAXVidProjectileTarget@@@Z
// EA  : 0x82ED3D30
// RVA : 0x00ED3D30
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idProjectile_Homing::SetProjectileTarget(
        idProjectile_Homing *this,
        const idProjectileTarget *newTarget,
        unsigned int a3,
        unsigned int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14)
{
  idProjectile_Homing *v14; // r3
  idProjectile_Homing *v15; // r31
  idPresentable *presentable; // r3
  idPresentable *v17; // r3
  idPresentablePtr<idPresentable> *v18; // r3
  idPresentable *v19; // r3

  a12 = *(_QWORD *)&newTarget;
  a13 = a3;
  v15 = v14;
  a14 = a4;
  idProjectile_Homing::NotifyEntityAboutHoming(this: v14, ent: nullptr, addNew: false);
  idProjectile_Homing::SetTarget(this: v15, target_: (const idProjectileTarget *)&a12);
  presentable = v15->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: v15);
    presentable = v15->presentable;
  }
  if ( presentable->GetProjectileHomingInterface(this: presentable)->target.type == TARGET_PRESENTABLE )
  {
    v17 = v15->presentable;
    if ( v17 == nullptr )
    {
      idEntity::InitPresentableInternal(this: v15);
      v17 = v15->presentable;
    }
    v18 = (idPresentablePtr<idPresentable> *)v17->GetProjectileHomingInterface(this: v17);
    if ( v18[511].spawnId == 1 )
      v19 = idPresentablePtr<idPresentableProjectile>::operator->(this: v18 + 515);
    else
      v19 = nullptr;
    idProjectile_Homing::NotifyEntityAboutHoming(this: v15, ent: v19->entity, addNew: true);
  }
}


// ========================================================================
// ?IsFriendly@idProjectile_StickyBomb@@IAA_NPAVidEntity@@@Z
// EA  : 0x82ED3E08
// RVA : 0x00ED3E08
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

int __fastcall idProjectile_StickyBomb::IsFriendly(idProjectile_StickyBomb *this, idEntity *ent)
{
  idPresentable *presentable; // r3
  idPresentableProjectile *v5; // r3
  idEntity *AttackerEntity; // r3
  gameTeam_t Team; // r31
  gameTeam_t v8; // r3
  unsigned __int8 v9; // r11

  if ( ent == nullptr )
    return 0;
  presentable = this->presentable;
  v5 = presentable != nullptr ? presentable->GetProjectileInterface(this: presentable) : nullptr;
  if ( idPresentableProjectile::GetAttackerEntity(this: v5) == nullptr )
    return 0;
  AttackerEntity = idProjectile::GetAttackerEntity(this);
  Team = idEntity::GetTeam(this: AttackerEntity);
  v8 = idEntity::GetTeam(this: ent);
  if ( Team == TEAM_NONE )
    return 0;
  v9 = 1;
  if ( Team != v8 )
    return 0;
  return v9;
}


// ========================================================================
// ?InternalLaunch_FromPresentable@idProjectile_Grenade@@UAAXPAVidPresentable@@ABVidVec3@@ABVidMat3@@ABVidProjectileTarget@@MH@Z
// EA  : 0x82ED3EB0
// RVA : 0x00ED3EB0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Grenade::InternalLaunch_FromPresentable(
        idProjectile_Grenade *this,
        idPresentable *attacker,
        const idVec3 *start,
        const idMat3 *fireAxis,
        const idProjectileTarget *target,
        double initialSpeed,
        int startTime,
        int a8)
{
  idPresentablePlayer *v11; // r3
  idPhysics *Physics; // r3
  idEntity *AttackerEntity; // r3
  idPlayer *v14; // r3
  idPlayer *v15; // r3
  idPhysics *v16; // r3
  double v19; // fp2
  double v20; // fp3
  double v21; // fp2
  double v22; // fp0
  double v23; // fp13
  double v24; // fp12
  char v25; // r11
  idPhysics *v26; // r3
  idPhysics *v27; // r3
  int v28; // r30
  idPhysics *v29; // r29
  idPhysics *v30; // r28
  idPhysics *v31; // r27
  idPhysics *v32; // r3
  int entityNumber; // r28
  double v34; // fp31
  double v35; // fp30
  double v36; // fp29
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  float *v38; // r3
  double v39; // fp8
  double v40; // fp6
  idClipModel *v41; // r29
  const idVec3 *v42; // r3
  double x; // fp4
  double y; // fp3
  double z; // fp2
  int v46; // [sp+8h] [-1A8h]
  bool v47; // [sp+Fh] [-1A1h]
  const char *v48; // [sp+10h] [-1A0h]
  int v49; // [sp+14h] [-19Ch]
  int v50; // [sp+18h] [-198h]
  int v51; // [sp+1Ch] [-194h]
  int v52; // [sp+20h] [-190h]
  int v53; // [sp+24h] [-18Ch]
  int v54; // [sp+28h] [-188h]
  int v55; // [sp+2Ch] [-184h]
  int v56; // [sp+30h] [-180h]
  int v57; // [sp+34h] [-17Ch]
  int v58; // [sp+38h] [-178h]
  int v59; // [sp+3Ch] [-174h]
  int v60; // [sp+40h] [-170h]
  int v61; // [sp+44h] [-16Ch]
  int v62; // [sp+48h] [-168h]
  int v63; // [sp+4Ch] [-164h]
  int v64; // [sp+50h] [-160h]
  int v65; // [sp+58h] [-158h]
  int v66; // [sp+60h] [-150h]
  float v67; // [sp+70h] [-140h] BYREF
  float v68; // [sp+74h] [-13Ch]
  float v69; // [sp+78h] [-138h]
  idVec3 v70; // [sp+80h] [-130h] BYREF
  char v71; // [sp+90h] [-120h] BYREF
  idVec3 v72[2]; // [sp+98h] [-118h] BYREF
  idMat3 v73; // [sp+B0h] [-100h] BYREF
  trace_t v74; // [sp+E0h] [-D0h] BYREF

  idEntity::BecomeActive(this, flags: 1);
  if ( this->projectileDecl->notHitscanInfo.grenadeInfo.countDownOnThrow )
    idProjectile_Grenade::StartDetonationTimer(this, startTime: a8);
  if ( !this->isSubMunition && attacker != nullptr && attacker->GetPlayerInterface_2(this: attacker) != nullptr )
  {
    v11 = attacker->GetPlayerInterface_2(this: attacker);
    if ( (unsigned __int8)idHandsItem::GetMuzzlePosition(
                            this: &v11->hands.leftItem,
                            hands: &v11->hands,
                            origin: v72,
                            axis: &v73) != 0 )
    {
      Physics = idEntity::GetPhysics(this);
      Physics->SetAxis(this: Physics, a2: &v73, a3: -1);
    }
    if ( this->projectileDecl->notHitscanInfo.followDeployableRules )
    {
      AttackerEntity = idProjectile::GetAttackerEntity(this);
      if ( (unsigned __int8)idClass::IsType(this: AttackerEntity, superclass: &idPlayer::Type) != 0 )
      {
        v14 = (idPlayer *)idProjectile::GetAttackerEntity(this);
        v15 = idPlayer::CastTo(c: v14);
        idPlayer::AddDroppableInfo(this: v15, ent: this);
      }
    }
  }
  v16 = idEntity::GetPhysics(this);
  v16->GetLinearVelocity(this: (idPhysics *)&v67, result: (idVec3 *)v16, a3: 0);
  _FP5 = (float)((float)((float)(v69 * v69) + (float)((float)(v68 * v68) + (float)(v67 * v67)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f12 }
  v19 = __frsqrte(_FP3);
  v20 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                      * (float)((float)((float)(v69 * v69) + (float)((float)(v68 * v68) + (float)(v67 * v67)))
                                                                                              * (float)0.5))
                                                                              * (float)v19)
                                                                      - (float)1.5)
                                                      * (float)v19)
                                              * (float)((float)((float)(v69 * v69)
                                                              + (float)((float)(v68 * v68) + (float)(v67 * v67)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v19
                                                                              * (float)((float)((float)(v69 * v69)
                                                                                              + (float)((float)(v68 * v68) + (float)(v67 * v67)))
                                                                                      * (float)0.5))
                                                                      * (float)v19)
                                                              - (float)1.5)
                                              * (float)v19))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v19
                                                      * (float)((float)((float)(v69 * v69)
                                                                      + (float)((float)(v68 * v68) + (float)(v67 * v67)))
                                                              * (float)0.5))
                                              * (float)v19)
                                      - (float)1.5)
                      * (float)v19));
  v21 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                              * (float)((float)((float)(v69 * v69) + (float)((float)(v68 * v68) + (float)(v67 * v67))) * (float)0.5))
                                                                                      * (float)v19)
                                                                              - (float)1.5)
                                                              * (float)v19)
                                                      * (float)((float)((float)(v69 * v69)
                                                                      + (float)((float)(v68 * v68) + (float)(v67 * v67)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v19
                                                                                      * (float)((float)((float)(v69 * v69) + (float)((float)(v68 * v68) + (float)(v67 * v67)))
                                                                                              * (float)0.5))
                                                                              * (float)v19)
                                                                      - (float)1.5)
                                                      * (float)v19))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v19
                                                              * (float)((float)((float)(v69 * v69)
                                                                              + (float)((float)(v68 * v68)
                                                                                      + (float)(v67 * v67)))
                                                                      * (float)0.5))
                                                      * (float)v19)
                                              - (float)1.5)
                              * (float)v19))
              * (float)((float)((float)(v69 * v69) + (float)((float)(v68 * v68) + (float)(v67 * v67))) * (float)0.5));
  v22 = (float)(v67 * (float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5) * (float)v20));
  v67 = v67 * (float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5) * (float)v20);
  v23 = (float)(v68 * (float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5) * (float)v20));
  v68 = v68 * (float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5) * (float)v20);
  v24 = (float)((float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5) * (float)v20) * v69);
  v69 = (float)((float)-(float)((float)((float)v21 * (float)v20) - (float)1.5) * (float)v20) * v69;
  if ( v22 != vec3_origin.x || v23 != vec3_origin.y || (v25 = 1, v24 != vec3_origin.z) )
    v25 = 0;
  if ( v25 != 0 )
  {
    v67 = 0.0;
    v68 = 0.0;
    v69 = -1.0;
  }
  v26 = idEntity::GetPhysics(this);
  if ( v26->GetClipMask(this: v26, a2: -1) != 0 )
  {
    v27 = idEntity::GetPhysics(this);
    v28 = v27->GetClipMask(this: v27, a2: -1);
  }
  else
  {
    v28 = 8495233;
  }
  v29 = idEntity::GetPhysics(this);
  v30 = idEntity::GetPhysics(this);
  v31 = idEntity::GetPhysics(this);
  v32 = v30;
  v34 = (float)(v67 * (float)20.0);
  v35 = (float)(v68 * (float)20.0);
  v36 = (float)(v69 * (float)20.0);
  GetOrigin = v30->GetOrigin;
  entityNumber = this->entityNumber;
  v38 = (float *)GetOrigin(this: v32, a2: 0);
  v39 = (float)(v38[2] + (float)v36);
  v40 = (float)(v38[1] + (float)v35);
  v70.x = *v38 + (float)v34;
  v70.z = v39;
  v70.y = v40;
  v41 = v29->GetClipModel(this: v29, a2: 0);
  v42 = v31->GetOrigin(this: v31, a2: 0);
  idClip::Translation(
    this: (idClip *)&v71,
    result: &clientGame->clip,
    a3: &v74,
    start: v42,
    end: &v70,
    clipModel: v41,
    startAxis: &mat3_identity,
    clipMask: v28,
    passEntityNumber: v46,
    moveClipModel: v47,
    userName: v48,
    a12: v49,
    a13: v50,
    a14: v51,
    a15: v52,
    a16: v53,
    a17: v54,
    a18: v55,
    a19: v56,
    a20: v57,
    a21: v58,
    a22: v59,
    a23: v60,
    a24: v61,
    a25: v62,
    a26: v63,
    a27: v64,
    a28: entityNumber,
    a29: v65,
    a30: false,
    a31: v66,
    a32: (int)"w:\\tech5\\tungsten\\game\\weapons\\Projectile.cpp(3344) : Translation");
  x = v74.c.normal.x;
  y = v74.c.normal.y;
  z = v74.c.normal.z;
  this->surfTypeLastHit = v74.c.surfaceType;
  this->surfNormalLastHit.x = x;
  this->surfNormalLastHit.y = y;
  this->surfNormalLastHit.z = z;
}


// ========================================================================
// ?AttachAIEvents@idProjectile_Grenade@@UAAXXZ
// EA  : 0x82ED4250
// RVA : 0x00ED4250
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Grenade::AttachAIEvents(idProjectile_Grenade *this)
{
  idHandle<int,enum invalidAIEvent_t,-1> *p_playerEventHandle; // r30
  idPhysics *Physics; // r3
  idPresentable *presentable; // r11
  idPhysics *v5; // r28
  idPresentableProjectile *v6; // r3
  const idEntity *AttackerEntity; // r26
  int GameMs; // r27
  const idDeclProjectile *projectileDecl; // r25
  idAIEventManager *p_aiEventManager; // r29
  const idVec3 *v11; // r3
  idAIEventManager *v12; // r3
  bool v13; // cr58
  idAIEventManager v14; // [sp+50h] [-50h] BYREF

  p_playerEventHandle = &this->playerEventHandle;
  idProjectile::AttachAIEvents(this);
  if ( this->playerEventHandle.value != -1 )
  {
    idAIEventManager::RemoveEvent(this: &gameLocal->aiEventManager, handle: &this->playerEventHandle);
    p_playerEventHandle->value = -1;
  }
  if ( this->projectileDecl->playerAIEventDecl != nullptr )
  {
    Physics = idEntity::GetPhysics(this);
    presentable = this->presentable;
    v5 = Physics;
    if ( presentable != nullptr )
      v6 = presentable->GetProjectileInterface(this: this->presentable);
    else
      v6 = nullptr;
    AttackerEntity = idPresentableProjectile::GetAttackerEntity(this: v6);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    projectileDecl = this->projectileDecl;
    p_aiEventManager = &gameLocal->aiEventManager;
    v11 = v5->GetOrigin(this: v5, a2: 0);
    v12 = idAIEventManager::AddEvent(
            this: &v14,
            result: p_aiEventManager,
            eventDecl: projectileDecl->playerAIEventDecl,
            curTime: GameMs,
            originator: this,
            instigator: AttackerEntity,
            origin: v11,
            delay: 0);
    v13 = v12->eventList.list == (idAIEvent **)-1;
    p_playerEventHandle->value = (int)v12->eventList.list;
    if ( v13 )
      idLib::Warning(
        fmt: "Wrong playerAIEventDecl specified in projectile def '%s'",
        this->projectileDecl->idProjectile::name.str);
  }
}


// ========================================================================
// ?Event_Touch@idProjectile_StickyBomb@@AAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82ED4378
// RVA : 0x00ED4378
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

idProjectile_StickyBomb *__fastcall idProjectile_StickyBomb::Event_Touch(
        idProjectile_StickyBomb *this,
        idProjectile_StickyBomb *result,
        idEntity *ent,
        int clipModelId)
{
  int value; // r10
  idEntity *v8; // r3
  idEntity *v9; // r3

  if ( (unsigned __int8)idVehicle::IsTypeOf(c: ent) != 0 || (unsigned __int8)idAI2::IsTypeOf(c: ent) != 0 )
  {
    value = result->ignoreEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v9 = idEntity::CastTo(c: v8);
    }
    else
    {
      v9 = nullptr;
    }
    if ( ent == v9
      && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < result->ignoreTimeout )
    {
      result->ignoreTimeout = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                            + 250;
      return this;
    }
    if ( result->friendlyCanTrigger || (unsigned __int8)idProjectile_StickyBomb::IsFriendly(this: result, ent) == 0 )
      result->Explode(this: result, a2: ent, a3: nullptr);
  }
  return this;
}


// ========================================================================
// ?Spawn@idProjectile@@QAAXXZ
// EA  : 0x82ED44A8
// RVA : 0x00ED44A8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile::Spawn(idProjectile *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  const idSoundShader *v4; // r8
  idPresentable *v5; // r7
  idPLog **p_pLog; // r10
  float *p_trailFadeOutTime; // r11
  int i; // ctr
  idPresentable *presentable; // r4
  idPLogScope v10; // [sp+58h] [-48h] BYREF
  idEntityInfluenceTrail v11[2]; // [sp+60h] [-40h] BYREF

  RD_EventBegin(name: "idProjectile::Spawn");
  LODWORD(v2) = "idProjectile::Spawn";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v10, pl: &pLog, gMask: v2, label: v3);
  p_pLog = &v10.pLog;
  p_trailFadeOutTime = &this->projectileDecl->impactInfluence.trailFadeOutTime;
  for ( i = 6; i != 0; --i )
    *++p_pLog = *(idPLog **)++p_trailFadeOutTime;
  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    idInfluenceTrailManager::Enable(
      this: &clientGame->influenceTrailManager,
      presentable,
      trail: v11,
      sndFoliage: nullptr,
      a5: v5,
      a6: v4);
    this->startInfluenceTrail = idClientGame::GetPlayerGameTime(this: clientGame);
  }
  if ( this->startHidden )
    this->Hide_2(this);
  idPLogScope::~idPLogScope(this: &v10);
  RD_EventEnd();
}


// ========================================================================
// __unwind$500878
// EA  : 0x82ED4570
// RVA : 0x00ED4570
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_500878()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 120));
}


// ========================================================================
// __unwind$500879
// EA  : 0x82ED4598
// RVA : 0x00ED4598
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_500879()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 88));
}


// ========================================================================
// ?StartFlySound@idProjectile@@QAAXXZ
// EA  : 0x82ED45C8
// RVA : 0x00ED45C8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile::StartFlySound(idProjectile *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  const idSoundShader *flySound; // r10
  const idDeclProjectile *projectileDecl; // [sp+50h] [-40h]
  idPLogScope v6[7]; // [sp+58h] [-38h] BYREF

  RD_EventBegin(name: "idProjectile::StartFlySound");
  LODWORD(v2) = "idProjectile::StartFlySound";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v6, pl: &pLog, gMask: v2, label: v3);
  projectileDecl = this->projectileDecl;
  if ( projectileDecl != nullptr )
  {
    flySound = projectileDecl->notHitscanInfo.flySound;
    if ( flySound != nullptr )
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_BODY,
        shader: flySound,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
  }
  idPLogScope::~idPLogScope(this: v6);
  RD_EventEnd();
}


// ========================================================================
// __unwind$500937
// EA  : 0x82ED4654
// RVA : 0x00ED4654
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_500937()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 96));
}


// ========================================================================
// __unwind$500938
// EA  : 0x82ED467C
// RVA : 0x00ED467C
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_500938()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 88));
}


// ========================================================================
// ?DoDirectDamage@idProjectile@@IAAMPAVidEntity@@ABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82ED46B0
// RVA : 0x00ED46B0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

float __fastcall idProjectile::DoDirectDamage(idProjectile *this, idEntity *ent, const idVec3 *dir, trace_t *trace)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  const idDeclDamage *damageDecl; // r28
  double v9; // fp31
  idEntity_vtbl *v10; // r25
  double damageScale; // fp31
  idEntity *AttackerEntity; // r3
  double v13; // fp1
  double v14; // fp1
  double v15; // fp1
  idPLogScope v17[2]; // [sp+50h] [-60h] BYREF

  RD_EventBegin(name: "idProjectile::DoDirectDamage");
  LODWORD(v6) = "idProjectile::DoDirectDamage";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: v17, pl: &pLog, gMask: v6, label: v7);
  damageDecl = this->projectileDecl->damageDecl;
  v9 = 0.0;
  if ( ent != nullptr && damageDecl != nullptr )
  {
    v10 = ent->__vftable;
    if ( this->causesDirectDamage )
    {
      damageScale = this->damageScale;
      AttackerEntity = idProjectile::GetAttackerEntity(this);
      v13 = damageScale;
    }
    else
    {
      AttackerEntity = idProjectile::GetAttackerEntity(this);
      v13 = 0.0;
    }
    v14 = ((double (__fastcall *)(idEntity *, idProjectile *, idEntity *, const idDeclDamage *, double))v10->Damage)(
            a1: ent,
            a2: this,
            a3: AttackerEntity,
            a4: damageDecl,
            a5: v13);
    v9 = v14;
    if ( v14 > 0.0 )
      idGameLocal::WeaponFiredResult(
        this: gameLocal,
        tag: *(weaponStatsTag_t **)&this->weaponStatsTag,
        target: ent,
        damage: v14);
  }
  idPLogScope::~idPLogScope(this: v17);
  RD_EventEnd();
  v15 = v9;
  return *((float *)&v15 + 1);
}


// ========================================================================
// __unwind$501392
// EA  : 0x82ED47BC
// RVA : 0x00ED47BC
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_501392()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 88));
}


// ========================================================================
// __unwind$501393
// EA  : 0x82ED47E4
// RVA : 0x00ED47E4
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_501393()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 80));
}


// ========================================================================
// ?DoDamage@idProjectile@@IAAMPAVidEntity@@ABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82ED4818
// RVA : 0x00ED4818
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

float __fastcall idProjectile::DoDamage(idProjectile *this, idWaterEntity *ent, const idVec3 *dir, trace_t *trace)
{
  unsigned __int64 v8; // r6
  const char *v9; // r7
  double v10; // fp31
  const idDeclDamage *splashDamageDecl; // r28
  idPhysics *Physics; // r3
  idPresentable *presentable; // r11
  idPhysics *v14; // r29
  idPresentableProjectile *v15; // r3
  idPlayer *AttackerEntity; // r25
  double damageScale; // fp30
  const idVec3 *v18; // r3
  __int64 v19; // r10
  int v20; // r8
  const idDeclDamage *electricDamageDecl; // r29
  idWaterEntity *v22; // r3
  bool v23; // zf
  idPhysics *v24; // r3
  const idBounds *v25; // r3
  idWaterEntity *v26; // r3
  idPhysics *v27; // r3
  double v28; // fp1
  idPLogScope v30[2]; // [sp+50h] [-80h] BYREF
  int v31[8]; // [sp+60h] [-70h] BYREF

  RD_EventBegin(name: "idProjectile::DoDamage");
  LODWORD(v8) = "idProjectile::DoDamage";
  HIDWORD(v8) = 2;
  idPLogScope::idPLogScope(this: v30, pl: &pLog, gMask: v8, label: v9);
  v10 = idProjectile::DoDirectDamage(this, ent, dir, trace);
  splashDamageDecl = this->projectileDecl->splashDamageDecl;
  if ( splashDamageDecl != nullptr )
  {
    Physics = idEntity::GetPhysics(this);
    presentable = this->presentable;
    v14 = Physics;
    if ( presentable != nullptr )
      v15 = presentable->GetProjectileInterface(this: this->presentable);
    else
      v15 = nullptr;
    AttackerEntity = (idPlayer *)idPresentableProjectile::GetAttackerEntity(this: v15);
    damageScale = this->damageScale;
    v18 = v14->GetOrigin(this: v14, a2: 0);
    idGameLocal::RadiusDamage(
      this: gameLocal,
      origin: v18,
      inflictor: this,
      attacker: AttackerEntity,
      damageDef: splashDamageDecl,
      dmgPower: damageScale,
      a7: v20,
      a8: v19);
  }
  electricDamageDecl = this->projectileDecl->electricDamageDecl;
  if ( electricDamageDecl != nullptr && !this->electricDischarged )
  {
    v23 = (unsigned __int8)idWaterEntity::IsTypeOf(c: ent) != 0;
    v22 = ent;
    if ( !v23 )
    {
      v24 = idEntity::GetPhysics(this: ent);
      v25 = v24->GetAbsBounds(this: v24, a2: -1);
      if ( idClip::GetEntitiesTouchingBounds(
             this: &clientGame->clip,
             bounds: v25,
             clipMask: 4,
             entityList: v31,
             maxCount: 4) <= 0 )
      {
LABEL_13:
        v27 = idEntity::GetPhysics(this);
        v27->GetOrigin(this: v27, a2: 0);
        goto LABEL_14;
      }
      v22 = (idWaterEntity *)gameLocal->entities.ptr[v31[0]];
    }
    v26 = idWaterEntity::CastTo(c: v22);
    if ( v26 != nullptr )
      v26->damageDecl = electricDamageDecl;
    goto LABEL_13;
  }
LABEL_14:
  idPLogScope::~idPLogScope(this: v30);
  RD_EventEnd();
  v28 = v10;
  return *((float *)&v28 + 1);
}


// ========================================================================
// __unwind$501431_0
// EA  : 0x82ED49E0
// RVA : 0x00ED49E0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_501431_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 112));
}


// ========================================================================
// __unwind$501432_0
// EA  : 0x82ED4A08
// RVA : 0x00ED4A08
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_501432_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 80));
}


// ========================================================================
// ?Explode@idProjectile@@UAAXPAVidEntity@@PAUtrace_t@@@Z
// EA  : 0x82ED4A38
// RVA : 0x00ED4A38
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idProjectile::Explode(idProjectile *this, idWaterEntity *ent, trace_t *trace)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int v8; // r10
  int v9; // r9
  const idSoundShader *v10; // r8
  idPresentable *v11; // r7
  idPresentable *presentable; // r3
  int v13; // r3
  idPresentable *v14; // r4
  unsigned __int64 v15; // r6
  const char *v16; // r7
  idPhysics *Physics; // r26
  int GameMs; // r25
  idPhysics *v19; // r3
  const idDeclProjectile *projectileDecl; // r20
  idAIEventManager *p_aiEventManager; // r26
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v23; // r19
  const idEntity *AttackerEntity; // r3
  weaponStatsTag_t weaponStatsTag; // r11
  char v26; // r11
  bool v27; // zf
  idPhysics *v28; // r3
  const idVec3 *v29; // r3
  unsigned __int64 v30; // r6
  const char *v31; // r7
  weaponStatsTag_t v32; // r11
  char v33; // r11
  idPresentable *v34; // r3
  int v35; // r3
  unsigned __int64 v36; // r6
  const char *v37; // r7
  idPhysics *v38; // r3
  char v39; // r25
  int v40; // r26
  double x; // fp0
  idAIEvent **p_normal; // r11
  double y; // fp13
  double z; // fp12
  idPhysics *v45; // r29
  int v46; // r27
  idPresentable *v47; // r28
  const idVec3 *v48; // r3
  idPhysics *v49; // r29
  int v50; // r27
  idPresentable *v51; // r28
  const idVec3 *v52; // r3
  int v53; // r3
  idPresentable *v54; // r11
  int v55; // r29
  idPhysics *v56; // r3
  idPresentable *v57; // r11
  idPhysics *v58; // r29
  const idDeclDamage *damageDecl; // r28
  idPresentableProjectile *v60; // r3
  const idEntity *v61; // r3
  const idDeclProjectile *v62; // r10
  const idDeclDamage *splashDamageDecl; // r11
  const idDeclDamage *v64; // r10
  idGameLocal *SpawnId; // r10
  idPhysics *v68; // r3
  const idDeclDamage *v69; // r29
  const idVec3 *(__fastcall *v70)(idPhysics *, int); // ctr
  const idVec3 *v71; // r27
  idWeaponTraceManager *WeaponTraceMgr; // r3
  const idSpawnId *v73; // r5
  __int128 v74; // r7 OVERLAPPED
  int v75; // r8
  __int64 v76; // r10
  __int64 v77; // r10
  __int64 v78; // r8
  int v79; // r6
  __int64 v80; // [sp+8h] [-138h]
  __int64 v81; // [sp+8h] [-138h]
  __int64 v82; // [sp+10h] [-130h]
  __int64 v83; // [sp+10h] [-130h]
  __int64 v84; // [sp+18h] [-128h]
  __int64 v85; // [sp+18h] [-128h]
  __int64 v86; // [sp+20h] [-120h]
  __int64 v87; // [sp+20h] [-120h]
  __int64 v88; // [sp+28h] [-118h]
  __int64 v89; // [sp+28h] [-118h]
  __int64 v90; // [sp+30h] [-110h]
  __int64 v91; // [sp+30h] [-110h]
  __int64 v92; // [sp+38h] [-108h]
  __int64 v93; // [sp+40h] [-100h]
  int v94; // [sp+50h] [-F0h] BYREF
  idAIEventManager v95; // [sp+54h] [-ECh] BYREF

  RD_EventBegin(name: "idProjectile::Explode");
  LODWORD(v6) = "idProjectile::Explode";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v95.eventList.num, pl: &pLog, gMask: v6, label: v7);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v13 = (int)presentable->GetProjectileInterface(this: presentable);
  else
    v13 = 0;
  if ( *(_DWORD *)(v13 + 1252) == 5 )
  {
    idPLogScope::~idPLogScope(this: (idPLogScope *)&v95.eventList.num);
  }
  else
  {
    v14 = this->presentable;
    if ( v14 != nullptr )
    {
      v95.eventList.list = (idAIEvent **)this->presentable;
      idInfluenceTrailManager::FreeInfluenceTrail(this: &clientGame->influenceTrailManager, presentable: v14);
      this->startInfluenceTrail = -1;
    }
    idProjectile::EnableInfluenceTrail(
      this: (idProjectile *)LODWORD(this->projectileDecl->impactInfluence.innerRadius),
      trailInfo: (idEntityInfluenceTrail *)LODWORD(this->projectileDecl->impactInfluence.angle),
      a3: *(_QWORD *)&this->projectileDecl->impactInfluence.trailFadeInTime,
      a4: v11,
      a5: v10,
      a6: v9,
      a7: v8,
      a8: v80,
      a9: v82,
      a10: v84,
      a11: v86,
      a12: v88,
      a13: v90);
    v94 = 0;
    RD_EventBegin(name: "idProjectile::Explode - 1");
    LODWORD(v15) = "idProjectile::Explode - 1";
    HIDWORD(v15) = 2;
    idPLogScope::idPLogScope(this: (idPLogScope *)&v95.eventList.granularity, pl: &pLog, gMask: v15, label: v16);
    idProjectile::SetState(this, state: EXPLODED);
    this->RemoveAIEvents(this);
    idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
    if ( this->explosionEvent )
    {
      Physics = idEntity::GetPhysics(this);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v19 = Physics;
      projectileDecl = this->projectileDecl;
      GetOrigin = Physics->GetOrigin;
      p_aiEventManager = &gameLocal->aiEventManager;
      v23 = GetOrigin(this: v19, a2: 0);
      AttackerEntity = idProjectile::GetAttackerEntity(this);
      idAIEventManager::AddEvent(
        this: &v95,
        result: p_aiEventManager,
        eventDecl: projectileDecl->explodeAIEventDecl,
        curTime: GameMs,
        originator: this,
        instigator: AttackerEntity,
        origin: v23,
        delay: 0);
    }
    weaponStatsTag = this->weaponStatsTag;
    if ( (*(_DWORD *)&weaponStatsTag & 0xFC000000) != 0
      || (*(_DWORD *)&weaponStatsTag & 0x3C00000) != 0
      || (v27 = (*(_DWORD *)&weaponStatsTag & 0x3FFFFF) == 0, v26 = 0, !v27) )
    {
      v26 = 1;
    }
    if ( v26 != 0 )
      idGameLocal::SetCurrentStatsDamage(
        this: gameLocal,
        tag: *(weaponStatsTag_t **)&this->weaponStatsTag,
        delayedCount: &v94);
    idPLogScope::~idPLogScope(this: (idPLogScope *)&v95.eventList.granularity);
    RD_EventEnd();
    v28 = idEntity::GetPhysics(this);
    v29 = (const idVec3 *)v28->GetAxis(this: v28, a2: 0);
    idProjectile::DoDamage(this, ent, dir: v29, trace);
    RD_EventBegin(name: "idProjectile::Explode - 2");
    LODWORD(v30) = "idProjectile::Explode - 2";
    HIDWORD(v30) = 2;
    idPLogScope::idPLogScope(this: (idPLogScope *)&v95.eventHash.indexChain, pl: &pLog, gMask: v30, label: v31);
    v32 = this->weaponStatsTag;
    if ( (*(_DWORD *)&v32 & 0xFC000000) != 0
      || (*(_DWORD *)&v32 & 0x3C00000) != 0
      || (v27 = (*(_DWORD *)&v32 & 0x3FFFFF) == 0, v33 = 0, !v27) )
    {
      v33 = 1;
    }
    if ( v33 != 0 )
    {
      idGameLocal::ClearCurrentStatsDamage(this: gameLocal);
      idGameLocal::WeaponFiredDone(
        this: gameLocal,
        tag: *(weaponStatsTag_t **)&this->weaponStatsTag,
        carryoverCount: v94);
    }
    v34 = this->presentable;
    if ( v34 != nullptr )
      v35 = (int)v34->GetProjectileInterface(this: v34);
    else
      v35 = 0;
    if ( *(_BYTE *)(v35 + 1264) != 0 )
      idEntity::StopSound(this, channel: SND_CHANNEL_BODY3, peerMask: 0xFFu);
    idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_DAMAGE,
      shader: this->projectileDecl->notHitscanInfo.explodeSound,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
    RD_EventBegin(name: "idProjectile::Explode - unlink clip");
    LODWORD(v36) = "idProjectile::Explode - unlink clip";
    HIDWORD(v36) = 2;
    idPLogScope::idPLogScope(this: (idPLogScope *)&v95.eventList.granularity, pl: &pLog, gMask: v36, label: v37);
    v38 = idEntity::GetPhysics(this);
    v38->UnlinkClip(this: v38);
    idPLogScope::~idPLogScope(this: (idPLogScope *)&v95.eventList.granularity);
    RD_EventEnd();
    this->Hide_2(this);
    v39 = 1;
    switch ( this->surfTypeLastHit )
    {
      case 0:
      case 0xE:
      case 0x15:
      case 0x17:
      case 0x18:
      case 0x1A:
      case 0x1B:
      case 0x1C:
      case 0x21:
        v40 = 91;
        break;
      case 1:
      case 0x11:
      case 0x12:
      case 0x13:
      case 0x16:
      case 0x20:
        v40 = 100;
        break;
      case 2:
      case 0xB:
      case 0xD:
      case 0x10:
        v40 = 99;
        break;
      case 4:
      case 5:
        v40 = 98;
        break;
      case 6:
        v40 = 97;
        break;
      case 7:
        v40 = 96;
        break;
      case 8:
      case 0xF:
        v40 = 95;
        break;
      case 9:
        v40 = 102;
        break;
      case 0xA:
      case 0xC:
        v40 = 94;
        break;
      case 0x14:
        v40 = 93;
        break;
      case 0x19:
        v40 = 92;
        break;
      default:
        v40 = 101;
        v39 = 0;
        break;
    }
    if ( trace != nullptr )
    {
      x = trace->c.normal.x;
      p_normal = (idAIEvent **)&trace->c.normal;
      y = trace->c.normal.y;
      z = trace->c.normal.z;
    }
    else
    {
      x = this->surfNormalLastHit.x;
      p_normal = (idAIEvent **)&this->surfNormalLastHit;
      y = this->surfNormalLastHit.y;
      z = this->surfNormalLastHit.z;
    }
    *(float *)&v95.eventHash.hashMask = z;
    *(float *)&v95.eventHash.granularity = y;
    *(float *)&v95.eventHash.indexSize = x;
    v95.eventList.list = p_normal;
    idVec3::ToMat3(this: (idVec3 *)&v95.eventPools.granularity, result: (idMat3 *)&v95.eventHash.indexSize);
    v45 = idEntity::GetPhysics(this);
    v46 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    if ( this->presentable == nullptr )
      idEntity::InitPresentableInternal(this);
    v47 = this->presentable;
    v48 = v45->GetOrigin(this: v45, a2: 0);
    idFXManager::StartFX(
      this: &v47->fxManager,
      org: v48,
      axis: (const idMat3 *)&v95.eventPools.granularity,
      time: v46,
      startCondition: v40);
    if ( v39 != 0 )
    {
      v49 = idEntity::GetPhysics(this);
      v50 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      if ( this->presentable == nullptr )
        idEntity::InitPresentableInternal(this);
      v51 = this->presentable;
      v52 = v49->GetOrigin(this: v49, a2: 0);
      idFXManager::StartFX(
        this: &v51->fxManager,
        org: v52,
        axis: (const idMat3 *)&v95.eventPools.granularity,
        time: v50,
        startCondition: 90);
    }
    v53 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v54 = this->presentable;
    v55 = v53;
    if ( v54 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v54 = this->presentable;
    }
    idFXManager::StopFX(this: &v54->fxManager, time: v55, stopCondition: 90, immediateStop: false);
    v56 = idEntity::GetPhysics(this);
    v57 = this->presentable;
    v58 = v56;
    damageDecl = this->projectileDecl->damageDecl;
    if ( v57 != nullptr )
      v60 = v57->GetProjectileInterface(this: this->presentable);
    else
      v60 = nullptr;
    v61 = idPresentableProjectile::GetAttackerEntity(this: v60);
    v62 = this->projectileDecl;
    splashDamageDecl = v62->splashDamageDecl;
    v64 = v62->damageDecl;
    if ( splashDamageDecl != nullptr )
    {
      if ( v64 != nullptr )
      {
        _FP12 = (float)(splashDamageDecl->radius - v64->radius);
        __asm { fsel      f31, f12, f13, f0 }
      }
      else
      {
        _FP31 = splashDamageDecl->radius;
      }
    }
    else if ( v64 != nullptr )
    {
      _FP31 = v64->radius;
    }
    else
    {
      _FP31 = 0.0;
    }
    SpawnId = idGameLocal::GetSpawnId(this: (idGameLocal *)&v95, result: (idSpawnId *)gameLocal, ent: v61);
    v68 = v58;
    v70 = v58->GetOrigin;
    v69 = (const idDeclDamage *)SpawnId->__vftable;
    v71 = v70(this: v68, a2: 0);
    WeaponTraceMgr = idClientGame::GetWeaponTraceMgr(this: clientGame);
    idWeaponTraceManager::AddExplosion(
      this: WeaponTraceMgr,
      origin: v71,
      radius: _FP31,
      attacker: v73,
      damage: v69,
      a6: damageDecl);
    v95.receivers.list = nullptr;
    HIBYTE(v95.eventHash.memTag) = 105;
    DWORD1(v74) = v95.eventHash.memTag;
    *((_QWORD *)&v74 + 1) = *(_QWORD *)&v95.receivers.num;
    v75 = __ROL4__(*(_DWORD *)&v95.receivers.granularity, 32);
    idEventReceiver::PostEventMS(
      this,
      ev: &EV_StopFX,
      arg1: *(__int64 *)((char *)&v74 + 4),
      a4: *(__int64 *)((char *)&v74 - 4),
      a5: v76,
      a6: v81,
      a7: v83,
      a8: v85,
      a9: v87,
      a10: v89,
      a11: v91,
      a12: v92,
      a13: v93);
    LODWORD(v77) = &s_memTag[218];
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 3500, a4: v79, a5: v78, a6: v77);
    idPLogScope::~idPLogScope(this: (idPLogScope *)&v95.eventHash.indexChain);
    RD_EventEnd();
    idPLogScope::~idPLogScope(this: (idPLogScope *)&v95.eventList.num);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$501629
// EA  : 0x82ED518C
// RVA : 0x00ED518C
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_501629()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 320 + 196));
}


// ========================================================================
// __unwind$501630
// EA  : 0x82ED51B4
// RVA : 0x00ED51B4
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_501630()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 320 + 88));
}


// ========================================================================
// __unwind$501631
// EA  : 0x82ED51DC
// RVA : 0x00ED51DC
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_501631()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 320 + 197));
}


// ========================================================================
// __unwind$501632
// EA  : 0x82ED5204
// RVA : 0x00ED5204
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_501632()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 320 + 96));
}


// ========================================================================
// __unwind$501633
// EA  : 0x82ED522C
// RVA : 0x00ED522C
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_501633()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 320 + 198));
}


// ========================================================================
// __unwind$501634
// EA  : 0x82ED5254
// RVA : 0x00ED5254
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_501634()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 320 + 104));
}


// ========================================================================
// __unwind$501635
// EA  : 0x82ED527C
// RVA : 0x00ED527C
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_501635()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 320 + 199));
}


// ========================================================================
// __unwind$501636
// EA  : 0x82ED52A4
// RVA : 0x00ED52A4
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_501636()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 320 + 96));
}


// ========================================================================
// ?Detach@idProjectile@@IAAXXZ
// EA  : 0x82ED52D8
// RVA : 0x00ED52D8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile::Detach(idProjectile *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idEntity *BindMaster; // r3
  idAttachmentCollection *v5; // r3
  idPLogScope v6[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "idProjectile_Grenade::Detach");
  LODWORD(v2) = "idProjectile_Grenade::Detach";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v6, pl: &pLog, gMask: v2, label: v3);
  BindMaster = idEntity::GetBindMaster(this);
  if ( BindMaster != nullptr )
  {
    v5 = BindMaster->GetAttachments_2(this: BindMaster);
    if ( v5 != nullptr )
      idAttachmentCollection::RemoveAttachment(this: v5, ent: this);
    else
      idEntity::Unbind(this);
  }
  idPLogScope::~idPLogScope(this: v6);
  RD_EventEnd();
}


// ========================================================================
// __unwind$502054
// EA  : 0x82ED5378
// RVA : 0x00ED5378
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_502054()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$502055
// EA  : 0x82ED53A0
// RVA : 0x00ED53A0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_502055()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?Launch@idProjectile@@QAAXPAVidEntity@@ABVidVec3@@ABVidMat3@@ABVidProjectileTarget@@MHH@Z
// EA  : 0x82ED53D0
// RVA : 0x00ED53D0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile::Launch(
        idProjectile *this,
        idEntity *attacker_,
        const idVec3 *start,
        const idMat3 *fireAxis,
        const idProjectileTarget *target,
        double initialSpeed,
        const int startTime,
        int launchTimeOverride,
        int GameMs)
{
  unsigned __int64 v17; // r6
  const char *v18; // r7
  idPresentable *presentable; // r3
  int v20; // r8
  idPresentable *v21; // r29
  idPresentable *v22; // r3
  idPresentableProjectile *v23; // r3
  int v24; // r10
  int v25; // r9
  int v26; // r8
  int v27; // r7
  idPresentable *v28; // r11
  idPhysics *Physics; // r29
  idPresentable *v30; // r30
  int v31; // r3
  int v32; // r10
  int v33; // r9
  int v34; // r8
  int v35; // r7
  int v36; // r6
  int v37; // r5
  int v38; // [sp+8h] [-B8h]
  int v39; // [sp+Ch] [-B4h]
  int v40; // [sp+10h] [-B0h]
  int v41; // [sp+14h] [-ACh]
  int v42; // [sp+18h] [-A8h]
  idPresentable *v43; // [sp+1Ch] [-A4h]
  idPLogScope v44[3]; // [sp+50h] [-70h] BYREF

  RD_EventBegin(name: "idProjectile::Launch");
  LODWORD(v17) = "idProjectile::Launch";
  HIDWORD(v17) = 2;
  idPLogScope::idPLogScope(this: v44, pl: &pLog, gMask: v17, label: v18);
  if ( attacker_ != nullptr )
  {
    this->Show(this);
    idProjectile::SetAttacker(this, a: attacker_);
    presentable = this->presentable;
    if ( presentable != nullptr && presentable->GetProjectileInterface(this: presentable) != nullptr )
    {
      if ( GameMs <= 0 )
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      if ( attacker_->presentable == nullptr )
        idEntity::InitPresentableInternal(this: attacker_);
      v21 = attacker_->presentable;
      v22 = this->presentable;
      if ( v22 != nullptr )
        v23 = v22->GetProjectileInterface(this: v22);
      else
        v23 = nullptr;
      idPresentableProjectile::ClientLaunch(
        this: v23,
        attacker_: v21,
        start,
        fireAxis,
        target,
        initialSpeed,
        startTime: v20,
        launchTime_: launchTimeOverride,
        a9: GameMs);
      v28 = this->presentable;
      if ( v28 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v28 = this->presentable;
      }
      idPresentable::SetClipModelInfo(
        this: v28,
        clipModelInfo_: &this->clipModelInfo,
        clipModelSpawnPos_: &this->spawnPosition,
        clipModelSpawnAxis_: &this->spawnOrientation,
        a5: v27,
        a6: v26,
        a7: v25,
        a8: v24,
        a9: v38,
        a10: v39,
        a11: v40,
        a12: v41,
        a13: v42,
        a14: v43);
      Physics = idEntity::GetPhysics(this);
      if ( this->presentable == nullptr )
        idEntity::InitPresentableInternal(this);
      v30 = this->presentable;
      v31 = Physics->GetContents(this: Physics, a2: -1);
      idPresentable::SetClipModelContents(
        this: v30,
        newContents: v31,
        a3: v37,
        a4: v36,
        a5: v35,
        a6: v34,
        a7: v33,
        a8: v32);
    }
  }
  idPLogScope::~idPLogScope(this: v44);
  RD_EventEnd();
}


// ========================================================================
// __unwind$502100
// EA  : 0x82ED5594
// RVA : 0x00ED5594
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_502100()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 88));
}


// ========================================================================
// __unwind$502101
// EA  : 0x82ED55BC
// RVA : 0x00ED55BC
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_502101()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 80));
}


// ========================================================================
// ?UpdateAnimation@idProjectile@@IAAXXZ
// EA  : 0x82ED55F0
// RVA : 0x00ED55F0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile::UpdateAnimation(idProjectile *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idAnimStack *v4; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *treeAnimator; // r29
  unsigned __int64 v7; // r6
  const char *v8; // r7
  idGameTimeManager *p_gameTimeManager; // r26
  idGameTimeManager *v10; // r25
  int GameMsPerFrame; // r24
  int PreviousGameMs; // r27
  int GameMs; // r29
  idParallelJobList *parallelJobList; // r23
  idAnimStack *v15; // r3
  unsigned __int64 v16; // r6
  const char *v17; // r7
  float *v18; // [sp+8h] [-D8h]
  float *v19; // [sp+Ch] [-D4h]
  float *v20; // [sp+10h] [-D0h]
  idPLogScope v21; // [sp+78h] [-68h] BYREF
  idPLogScope v22[12]; // [sp+80h] [-60h] BYREF

  if ( this->GetAnimStack_2(this) != nullptr )
  {
    RD_EventBegin(name: "idProjectile::UpdateAnimation");
    LODWORD(v2) = "idProjectile::UpdateAnimation";
    HIDWORD(v2) = 2;
    idPLogScope::idPLogScope(this: &v21, pl: &pLog, gMask: v2, label: v3);
    idAnimatedEntity::UpdateFrameCommands(this);
    this->UpdateModelTransform(this);
    v4 = this->GetAnimStack_2(this);
    presentable = this->presentable;
    treeAnimator = v4->treeAnimator;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    if ( treeAnimator != nullptr )
    {
      if ( (this->thinkFlags & 4) != 0 )
      {
        RD_EventBegin(name: "idProjectile::UpdateAnimation::BlendStack");
        LODWORD(v7) = "idProjectile::UpdateAnimation::BlendStack";
        HIDWORD(v7) = 2;
        idPLogScope::idPLogScope(this: v22, pl: &pLog, gMask: v7, label: v8);
        p_gameTimeManager = &clientGame->gameTimeManager;
        v10 = (idGameTimeManager *)(timeManager.gameTimePerFrame.value * timeManager.gameHz);
        GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        PreviousGameMs = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        parallelJobList = gameLocal->parallelJobList;
        v15 = this->GetAnimStack_2(this);
        idAnimStack::BlendStackInternal(
          this: v15,
          currentTime: GameMs,
          previousTime: PreviousGameMs,
          gameMsPerFrame: GameMsPerFrame,
          ticksPerSec: v10,
          game: p_gameTimeManager,
          parallelJobList,
          localR: nullptr,
          localS: v18,
          localT: v19,
          localU: v20);
        idPLogScope::~idPLogScope(this: v22);
        RD_EventEnd();
        idEntity::UpdateVisuals(this);
        RD_EventBegin(name: "idProjectile::UpdateAnimation::UpdateAttachments");
        LODWORD(v16) = "idProjectile::UpdateAnimation::UpdateAttachments";
        HIDWORD(v16) = 2;
        idPLogScope::idPLogScope(this: v22, pl: &pLog, gMask: v16, label: v17);
        this->UpdateAttachments(this);
        idPLogScope::~idPLogScope(this: v22);
        RD_EventEnd();
      }
      else
      {
        idEntity::UpdateVisuals(this);
        idTreeAnimator::ClearJointMods(this: treeAnimator);
      }
    }
    idPLogScope::~idPLogScope(this: &v21);
    RD_EventEnd();
  }
}


// ========================================================================
// __unwind$502201
// EA  : 0x82ED5820
// RVA : 0x00ED5820
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_502201()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 136));
}


// ========================================================================
// __unwind$502202
// EA  : 0x82ED5848
// RVA : 0x00ED5848
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_502202()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 120));
}


// ========================================================================
// __unwind$502203
// EA  : 0x82ED5870
// RVA : 0x00ED5870
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_502203()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 137));
}


// ========================================================================
// __unwind$502204
// EA  : 0x82ED5898
// RVA : 0x00ED5898
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_502204()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 128));
}


// ========================================================================
// __unwind$502205
// EA  : 0x82ED58C0
// RVA : 0x00ED58C0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_502205()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 138));
}


// ========================================================================
// __unwind$502206
// EA  : 0x82ED58E8
// RVA : 0x00ED58E8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_502206()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 128));
}


// ========================================================================
// ?Explode@idProjectile_Rocket@@UAAXPAVidEntity@@PAUtrace_t@@@Z
// EA  : 0x82ED5910
// RVA : 0x00ED5910
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Rocket::Explode(idProjectile_Rocket *this, idWaterEntity *ent, trace_t *trace)
{
  int value; // r10
  idEntity *v7; // r3
  int v8; // r9
  idEntity *v9; // r3
  idEntity *v10; // r3
  int v11; // r9
  idEntity *v12; // r3
  idAI2 *v13; // r3
  idAI2 *v14; // r29
  const idDeclProjectile *projectileDecl; // r26
  idAI2_vtbl *v16; // r30
  const idDeclDamage *splashDamageDecl; // r26
  idEntity *AttackerEntity; // r3
  idClipQuery *p_deferredSurfTrace; // r30
  idClientGame *v20; // r29
  __int128 v21; // r11
  double x; // fp0
  double y; // fp13
  double z; // fp12
  char v25; // [sp+50h] [-D0h] BYREF
  trace_t v26; // [sp+60h] [-C0h] BYREF

  value = this->stuckOnActor.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v7 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v7 != nullptr && idEntity::CastTo(c: v7) != nullptr )
    {
      v8 = this->stuckOnActor.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13 && (v9 = gameLocal->entities.ptr[v8 & 0x1FFF]) != nullptr )
        v10 = idEntity::CastTo(c: v9);
      else
        v10 = nullptr;
      if ( (unsigned __int8)idAI2::IsTypeOf(c: v10) != 0 )
      {
        v11 = this->stuckOnActor.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v11 & 0x1FFF] == v11 >> 13
          && (v12 = gameLocal->entities.ptr[v11 & 0x1FFF]) != nullptr )
        {
          v13 = (idAI2 *)idEntity::CastTo(c: v12);
        }
        else
        {
          v13 = nullptr;
        }
        v14 = idAI2::CastTo(c: v13);
        projectileDecl = this->projectileDecl;
        v16 = v14->__vftable;
        idEntity::GetLinearVelocity(this: (idEntity *)&v25, result: this);
        splashDamageDecl = projectileDecl->splashDamageDecl;
        AttackerEntity = idProjectile::GetAttackerEntity(this);
        ((void (__fastcall *)(idAI2 *, idProjectile_Rocket *, idEntity *, const idDeclDamage *, double))v16->Damage)(
          a1: v14,
          a2: this,
          a3: AttackerEntity,
          a4: splashDamageDecl,
          a5: 100.0);
      }
    }
  }
  p_deferredSurfTrace = &this->deferredSurfTrace;
  v20 = clientGame;
  if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &this->deferredSurfTrace) != 0 )
  {
    *((idClipQuery *)&v21 + 1) = (idClipQuery)p_deferredSurfTrace->index;
    DWORD1(v21) = &consoleFont[21088];
    p_deferredSurfTrace->index = *(unsigned __int64 *)((char *)&v21 + 4);
    idCollisionModelManager::GetContentsResult(
      this: collisionModelManager,
      result: &v26,
      query: &v20->clip.collisionQueries[v21 & 0xFFF].query,
      peek: false);
    x = v26.c.normal.x;
    this->surfTypeLastHit = v26.c.surfaceType;
    y = v26.c.normal.y;
    z = v26.c.normal.z;
    this->surfNormalLastHit.x = x;
    this->surfNormalLastHit.y = y;
    this->surfNormalLastHit.z = z;
  }
  if ( this->isInWater )
    this->surfTypeLastHit = 6;
  idProjectile::Explode(this, ent, trace);
}


// ========================================================================
// ?DisperseSubmunitions@idProjectile_Homing@@AAAXPAVidEntity@@@Z
// EA  : 0x82ED5B10
// RVA : 0x00ED5B10
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idProjectile_Homing::DisperseSubmunitions(idProjectile_Homing *this, idEntity *ent)
{
  unsigned __int64 v3; // r6
  const char *v4; // r7
  __int128 v5; // r7 OVERLAPPED
  int v6; // r8
  __int64 v7; // r10
  __int64 v8; // r8
  int v9; // r6
  idPhysics *Physics; // r3
  const idVec3 *v11; // r3
  float y; // r7
  float z; // r6
  idPhysics *v14; // r3
  idMat3 *v15; // r4
  int numSubMunitions; // r11
  int v17; // r20
  double v18; // fp25
  double v19; // fp22
  double v20; // fp21
  double v21; // fp20
  double v22; // fp27
  double v23; // fp28
  double x; // fp29
  double v25; // fp10
  double v26; // fp9
  idPresentable *Attacker; // r3
  weaponStatsTag_t weaponStatsTag; // r11
  BOOL randomSubMunitions; // r10
  idClientGame *v30; // r30
  signed int num; // r11
  const idDeclProjectile *v32; // r8
  unsigned int seed; // r10
  signed int v34; // r6
  signed int v35; // r10
  const idDeclProjectile **list; // r9
  idFinishFireResults *v37; // r11
  int i; // ctr
  int v39; // r28
  idPresentablePtr<idPresentableProjectile> *projectiles; // r29
  int v41; // r30
  idPresentable *PresentableByIndex; // r11
  double v45; // fp3
  double v46; // fp6
  double v47; // fp3
  unsigned int v48; // r6
  __int64 v49; // r4
  int v50; // r30
  idPresentable *v51; // r3
  int v52; // r29
  idPresentablePtr<idPresentableProjectile> *v53; // r30
  int v54; // r28
  idPresentable *v55; // r10
  float v56; // r3
  __int64 v57; // r9
  unsigned int v58; // r6
  double v59; // fp11
  idPLog *pLog; // r29
  idPLog::logEntry_t *v61; // r30
  int v62; // r3
  __int64 totalTicks; // r11
  __int64 v64; // r9
  __int64 v65; // [sp+8h] [-BA8h]
  __int64 v66; // [sp+10h] [-BA0h]
  __int64 v67; // [sp+18h] [-B98h]
  __int64 v68; // [sp+20h] [-B90h]
  __int64 v69; // [sp+28h] [-B88h]
  __int64 v70; // [sp+30h] [-B80h]
  __int64 v71; // [sp+38h] [-B78h]
  __int64 v72; // [sp+40h] [-B70h]
  float v73; // [sp+50h] [-B60h] BYREF
  float v74; // [sp+54h] [-B5Ch]
  float v75; // [sp+58h] [-B58h]
  __int64 v76; // [sp+60h] [-B50h]
  __int64 v77; // [sp+68h] [-B48h]
  int v78; // [sp+70h] [-B40h]
  idPLogScope v79; // [sp+78h] [-B38h] BYREF
  idMat3 v80; // [sp+80h] [-B30h] BYREF
  float v81[4]; // [sp+A8h] [-B08h] BYREF
  _QWORD v82[3]; // [sp+B8h] [-AF8h] BYREF
  idFireParms v83; // [sp+D0h] [-AE0h] BYREF
  idFinishFireResults v84; // [sp+170h] [-A40h] BYREF
  idTestFireResults v85; // [sp+1C0h] [-9F0h] BYREF

  RD_EventBegin(name: "idProjectile_Grenade::DisperseSubmunitions");
  LODWORD(v3) = "idProjectile_Grenade::DisperseSubmunitions";
  HIDWORD(v3) = 2;
  idPLogScope::idPLogScope(this: &v79, pl: &::pLog, gMask: v3, label: v4);
  if ( (-this->subMunitionProjectileList.num & ~this->subMunitionProjectileList.num) < 0 )
  {
    Physics = idEntity::GetPhysics(this);
    v11 = Physics->GetOrigin(this: Physics, a2: 0);
    y = v11->y;
    z = v11->z;
    *(float *)&v76 = v11->x;
    *((float *)&v76 + 1) = y;
    *(float *)&v77 = z;
    v14 = idEntity::GetPhysics(this);
    ((void (__fastcall *)(float *))v14->GetLinearVelocity)(a1: v81);
    numSubMunitions = this->numSubMunitions;
    v17 = 0;
    v18 = __fsqrts((float)((float)(v81[0] * v81[0]) + (float)((float)(v81[1] * v81[1]) + (float)(v81[2] * v81[2]))));
    if ( numSubMunitions > 0 )
    {
      v19 = *(float *)&v77;
      v20 = *((float *)&v76 + 1);
      v21 = *(float *)&v76;
      v22 = v80.mat[0].z;
      v23 = v80.mat[0].y;
      x = v80.mat[0].x;
      do
      {
        if ( this->pairedSubMunitionVels && (v17 & 1) != 0 )
        {
          v25 = (float)(this->coneDirection.y * (float)2.0);
          v26 = (float)(this->coneDirection.x * (float)2.0);
          v80.mat[0].z = (float)(this->coneDirection.z * (float)2.0) - (float)v22;
          v80.mat[0].y = (float)v25 - (float)v23;
          v80.mat[0].x = (float)v26 - (float)x;
          idMat3::OrthoNormalizeSelf(this: &v80);
        }
        else
        {
          idProjectile::RandomVectorInCone(
            normal: (idMat3 *)&this->coneDirection,
            maxDegrees: this->subMunitionMaxAngle,
            result: v15,
            a4: &v80);
        }
        idFireParms::idFireParms(this: &v83);
        Attacker = idProjectile::GetAttacker(this);
        if ( Attacker != nullptr )
          v83.attacker.spawnId = Attacker->spawnId;
        else
          v83.attacker.spawnId = 0;
        weaponStatsTag = this->weaponStatsTag;
        x = v80.mat[0].x;
        randomSubMunitions = this->randomSubMunitions;
        v23 = v80.mat[0].y;
        v22 = v80.mat[0].z;
        v30 = clientGame;
        v83.target.spawnId = 0;
        v83.wepDef = nullptr;
        v83.tag = weaponStatsTag;
        v83.start.x = v21;
        v83.start.y = v20;
        v83.start.z = v19;
        v83.fireAxis.mat[0].x = v80.mat[0].x;
        v83.fireAxis.mat[0].y = v80.mat[0].y;
        v83.fireAxis.mat[0].z = v80.mat[0].z;
        v83.fireAxis.mat[1].x = v80.mat[1].x;
        v83.fireAxis.mat[1].y = v80.mat[1].y;
        v83.fireAxis.mat[1].z = v80.mat[1].z;
        v83.fireAxis.mat[2].x = v80.mat[2].x;
        v83.fireAxis.mat[2].y = v80.mat[2].y;
        v83.fireAxis.mat[2].z = v80.mat[2].z;
        if ( randomSubMunitions )
        {
          num = this->subMunitionProjectileList.num;
          if ( num != 0 )
          {
            seed = clientGame->random.seed;
            __twllei(num, 0);
            clientGame->random.seed = 1664525 * seed + 1013904223;
            v30 = clientGame;
            v34 = ((1664525 * seed + 1013904223) >> 10) & 0x7FFF;
            __twlgei(num & ~(__ROL4__(v34, 1) - 1), 0xFFFFFFFF);
            v32 = this->subMunitionProjectileList.list[v34 % num];
          }
          else
          {
            v32 = *this->subMunitionProjectileList.list;
          }
          v83.projDef = v32;
        }
        else
        {
          v35 = this->subMunitionProjectileList.num;
          list = this->subMunitionProjectileList.list;
          __twllei(v35, 0);
          __twlgei(v35 & ~(__ROL4__(v17, 1) - 1), 0xFFFFFFFF);
          v83.projDef = list[v17 % v35];
        }
        memset(&v85, 0, sizeof(v85));
        v37 = &v84;
        v84.numProjectiles = 0;
        for ( i = 16; i != 0; --i )
        {
          v37 = (idFinishFireResults *)((char *)v37 + 4);
          v37->numProjectiles = 0;
        }
        idClientGame::TestFire(this: v30, fp: &v83, tfr: &v85);
        idGameLocal::FinishFire(this: gameLocal, fp: &v83, tfr: &v85, ffr: &v84);
        if ( v83.projDef->notHitscanInfo.grenadeInfo.inheritParentSpeed )
        {
          v39 = 0;
          if ( v84.numProjectiles > 0 )
          {
            projectiles = v84.projectiles;
            do
            {
              v41 = projectiles->spawnId & 0x3FFF;
              if ( projectiles->spawnId == 0
                || !idClientGame::IsPresentableIndexValid(this: clientGame, index: projectiles->spawnId & 0x3FFF)
                || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v41))->spawnId != projectiles->spawnId )
              {
                PresentableByIndex = nullptr;
              }
              (*(void (__fastcall **)(float *))(*(_DWORD *)LODWORD(PresentableByIndex[1].axes[0].mat[1].x) + 88))(a1: &v73);
              _FP6 = (float)((float)((float)(v73 * v73) + (float)((float)(v75 * v75) + (float)(v74 * v74)))
                           - idMath::FLT_SMALLEST_NON_DENORMAL);
              __asm { fsel      f4, f6, f7, f13 }
              v45 = __frsqrte(_FP4);
              v46 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v45
                                                                                                  * (float)((float)((float)(v73 * v73) + (float)((float)(v75 * v75) + (float)(v74 * v74))) * (float)0.5))
                                                                                          * (float)v45)
                                                                                  - (float)1.5)
                                                                  * (float)v45)
                                                          * (float)((float)((float)(v73 * v73)
                                                                          + (float)((float)(v75 * v75)
                                                                                  + (float)(v74 * v74)))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v45
                                                                                          * (float)((float)((float)(v73 * v73) + (float)((float)(v75 * v75) + (float)(v74 * v74)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v45)
                                                                          - (float)1.5)
                                                          * (float)v45))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v45
                                                                  * (float)((float)((float)(v73 * v73)
                                                                                  + (float)((float)(v75 * v75)
                                                                                          + (float)(v74 * v74)))
                                                                          * (float)0.5))
                                                          * (float)v45)
                                                  - (float)1.5)
                                  * (float)v45));
              v47 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v45 * (float)((float)((float)(v73 * v73) + (float)((float)(v75 * v75) + (float)(v74 * v74))) * (float)0.5)) * (float)v45) - (float)1.5) * (float)v45)
                                                                                                  * (float)((float)((float)(v73 * v73) + (float)((float)(v75 * v75) + (float)(v74 * v74))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v45 * (float)((float)((float)(v73 * v73) + (float)((float)(v75 * v75) + (float)(v74 * v74))) * (float)0.5)) * (float)v45) - (float)1.5)
                                                                                                  * (float)v45))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v45 * (float)((float)((float)(v73 * v73) + (float)((float)(v75 * v75) + (float)(v74 * v74))) * (float)0.5))
                                                                                                  * (float)v45)
                                                                                          - (float)1.5)
                                                                          * (float)v45))
                                                          * (float)((float)((float)(v73 * v73)
                                                                          + (float)((float)(v75 * v75)
                                                                                  + (float)(v74 * v74)))
                                                                  * (float)0.5))
                                                  * (float)v46)
                                          - (float)1.5)
                          * (float)v46);
              v74 = v74 * (float)v47;
              v73 = v73 * (float)v47;
              v75 = v75 * (float)v47;
              v48 = 1664525 * clientGame->random.seed + 1013904223;
              clientGame->random.seed = v48;
              HIDWORD(v49) = (idPresentablePtr<idPresentableProjectile>)projectiles->spawnId;
              LODWORD(v49) = (v48 >> 10) & 0x7FFF;
              v50 = projectiles->spawnId & 0x3FFF;
              v82[2] = v49;
              v73 = (float)((float)((float)v49 * (float)v18) * (float)0.000030518509) * v73;
              v74 = v74 * (float)((float)((float)v49 * (float)v18) * (float)0.000030518509);
              v75 = v75 * (float)((float)((float)v49 * (float)v18) * (float)0.000030518509);
              if ( HIDWORD(v49) == 0
                || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v50)
                || (v51 = idClientGame::GetPresentableByIndex(this: clientGame, index: v50))->spawnId != projectiles->spawnId )
              {
                v51 = nullptr;
              }
              (*(void (__fastcall **)(_DWORD, float *, _DWORD))(*(_DWORD *)LODWORD(v51[1].axes[0].mat[1].x) + 80))(
                a1: LODWORD(v51[1].axes[0].mat[1].x),
                a2: &v73,
                a3: 0);
              ++v39;
              ++projectiles;
            }
            while ( v39 < v84.numProjectiles );
          }
        }
        else
        {
          v52 = 0;
          if ( v84.numProjectiles > 0 )
          {
            v53 = v84.projectiles;
            do
            {
              v54 = v53->spawnId & 0x3FFF;
              if ( v53->spawnId == 0
                || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v53->spawnId & 0x3FFF)
                || (v55 = idClientGame::GetPresentableByIndex(this: clientGame, index: v54))->spawnId != v53->spawnId )
              {
                v55 = nullptr;
              }
              v56 = v55[1].axes[0].mat[1].x;
              HIDWORD(v57) = clientGame->random.seed;
              v58 = 1664525 * clientGame->random.seed + 1013904223;
              v59 = (float)((float)(v83.projDef->notHitscanInfo.speed * (float)0.25) - (float)1.0);
              clientGame->random.seed = v58;
              LODWORD(v57) = (v58 >> 10) & 0x7FFF;
              v76 = v57;
              *(float *)&v82[1] = (float)v22
                                * (float)((float)((float)((float)v57 * (float)v59) * (float)0.000030518509) + (float)1.0);
              *((float *)v82 + 1) = (float)v23
                                  * (float)((float)((float)((float)v57 * (float)v59) * (float)0.000030518509)
                                          + (float)1.0);
              *(float *)v82 = (float)x
                            * (float)((float)((float)((float)v57 * (float)v59) * (float)0.000030518509) + (float)1.0);
              (*(void (__fastcall **)(double, _QWORD *, _DWORD))(*(_DWORD *)LODWORD(v56) + 80))(
                a1: COERCE_DOUBLE(LODWORD(v56)),
                a2: v82,
                a3: 0);
              ++v52;
              ++v53;
            }
            while ( v52 < v84.numProjectiles );
          }
        }
        if ( v83.targetList.listStatic == 0 || v83.targetList.listStatic == 2 )
        {
          v15 = (idMat3 *)v83.targetList.list;
          if ( v83.targetList.list != nullptr )
            idMem::Free(this: &mem, ptr: v83.targetList.list, align: ALIGN_16);
          v83.targetList.list = nullptr;
          v83.targetList.size = 0;
        }
        numSubMunitions = this->numSubMunitions;
        ++v17;
        v83.targetList.num = 0;
      }
      while ( v17 < numSubMunitions );
    }
    idGameLocal::WeaponFiredDone(
      this: gameLocal,
      tag: *(weaponStatsTag_t **)&this->weaponStatsTag,
      carryoverCount: numSubMunitions + 1);
    if ( v79.logIndex >= 0 )
    {
      pLog = v79.pLog;
      v61 = &v79.pLog->logEntries.list[v79.logIndex];
      v62 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v61->totalTicks;
      HIDWORD(totalTicks) = v61->parent;
      LODWORD(v64) = v62 - totalTicks;
      v61->totalTicks = v64;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
  }
  else
  {
    HIBYTE(v76) = 105;
    LODWORD(v76) = 0;
    DWORD1(v5) = HIDWORD(v76);
    *((_QWORD *)&v5 + 1) = v77;
    v6 = __ROL4__(v78, 32);
    idEventReceiver::PostEventMS(
      this,
      ev: &EV_StopFX,
      arg1: *(__int64 *)((char *)&v5 + 4),
      a4: *(__int64 *)((char *)&v5 - 4),
      a5: 105,
      a6: v65,
      a7: v66,
      a8: v67,
      a9: v68,
      a10: v69,
      a11: v70,
      a12: v71,
      a13: v72);
    LODWORD(v7) = &s_memTag[218];
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 3500, a4: v9, a5: v8, a6: v7);
    idPLogScope::~idPLogScope(this: &v79);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$502568
// EA  : 0x82ED6234
// RVA : 0x00ED6234
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_502568()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 2992 + 2756));
}


// ========================================================================
// __unwind$502569
// EA  : 0x82ED625C
// RVA : 0x00ED625C
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_502569()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 2992 + 120));
}


// ========================================================================
// __unwind$502570
// EA  : 0x82ED6284
// RVA : 0x00ED6284
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_502570()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 2992 + 208));
}


// ========================================================================
// ?Break@idProjectile_Arrow@@UAAXPAVidEntity@@PAUtrace_t@@@Z
// EA  : 0x82ED62B8
// RVA : 0x00ED62B8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Arrow::Break(idProjectile_Arrow *this, idEntity *ent, trace_t *trace)
{
  idPresentable *presentable; // r3
  int v5; // r3
  unsigned __int64 v6; // r6
  const char *v7; // r7
  idPhysics *Physics; // r3
  __int64 v9; // r10
  __int64 v10; // r8
  int v11; // r6
  idPLogScope v12[6]; // [sp+50h] [-30h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetProjectileInterface(this: presentable);
  else
    v5 = 0;
  if ( *(_BYTE *)(v5 + 1264) != 0 )
    idEntity::StopSound(this, channel: SND_CHANNEL_BODY3, peerMask: 0xFFu);
  idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
  RD_EventBegin(name: "idProjectile_Arrow::Break - unlink clip");
  LODWORD(v6) = "idProjectile_Arrow::Break - unlink clip";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: v12, pl: &pLog, gMask: v6, label: v7);
  Physics = idEntity::GetPhysics(this);
  Physics->UnlinkClip(this: Physics);
  idPLogScope::~idPLogScope(this: v12);
  RD_EventEnd();
  this->Hide_2(this);
  idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 3500, a4: v11, a5: v10, a6: v9);
}


// ========================================================================
// __unwind$503082
// EA  : 0x82ED6398
// RVA : 0x00ED6398
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_503082()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$503083
// EA  : 0x82ED63C0
// RVA : 0x00ED63C0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_503083()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?AddElectricBoltEffect@idProjectile_Arrow@@UAA_NPAVidEntity@@@Z
// EA  : 0x82ED63F0
// RVA : 0x00ED63F0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

int __fastcall idProjectile_Arrow::AddElectricBoltEffect(idProjectile_Arrow *this, idEntity *target)
{
  int value; // r10
  idEntity *v5; // r3
  idEntity *v6; // r3
  int num; // r29
  idElectricBolt *v8; // r3
  idElectricBolt *v9; // r29
  const idDeclElectricBolt *electricBoltSystem; // r27
  idRenderModelBeam *NumContacts; // r3
  idEntityPtr<idEntity> v13[16]; // [sp+50h] [-40h] BYREF

  if ( (unsigned __int8)idAI2::IsTypeOf(c: target) == 0 )
    return 0;
  value = this->stuckIn.spawnId.value;
  v13[0].spawnId.value = (int)&this->stuckIn;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = idEntity::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  if ( target == v6 || idProjectile::GetState(this) != STUCK )
    return 0;
  num = this->electricTarget.num;
  v13[0].spawnId.value = target != nullptr
                       ? (gameLocal->spawnIds.ptr[target->entityNumber] << 13) | target->entityNumber
                       : 0x1FFF;
  if ( idList<idEntityPtr<idEntity>,5>::AddUnique(this: (idList<idEntityPtr<idAI2>,5> *)&this->electricTarget, obj: v13) < num )
    return 0;
  v8 = (idElectricBolt *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x320u,
                           tag: TAG_PARTICLE,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v13[0].spawnId.value = (int)v8;
  if ( v8 != nullptr )
    v9 = idElectricBolt::idElectricBolt(this: v8);
  else
    v9 = nullptr;
  electricBoltSystem = this->electricBoltSystem;
  v13[0].spawnId.value = (int)v9;
  NumContacts = (idRenderModelBeam *)idPhysics_DynamicBase::GetNumContacts(this: (idAnimator_ChannelWeight *)clientGame);
  idElectricBolt::Init(this: v9, _beamModel: NumContacts, _eboltDecl: electricBoltSystem);
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->electricShocks,
    obj: (encounterGroupRole_t *)v13);
  this->startElectricTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idEntity::BecomeActive(this, flags: 1);
  return 1;
}


// ========================================================================
// __unwind$503145
// EA  : 0x82ED6584
// RVA : 0x00ED6584
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_503145()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_PARTICLE);
}


// ========================================================================
// ?CheckDoDamage@idProjectile_Arrow@@QAAMPAVidEntity@@ABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82ED65B0
// RVA : 0x00ED65B0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

float __fastcall idProjectile_Arrow::CheckDoDamage(
        idProjectile_Arrow *this,
        idWaterEntity *ent,
        const idVec3 *dir,
        trace_t *trace)
{
  const idDeclDamage *splashDamageDecl; // r11
  double v9; // fp1

  splashDamageDecl = this->projectileDecl->splashDamageDecl;
  if ( splashDamageDecl == nullptr
    || (splashDamageDecl->damageTypes & 0x400) != 0x400
    || (unsigned __int8)idWaterEntity::IsTypeOf(c: ent) != 0
    || (unsigned __int8)idActor::IsTypeOf(c: ent) != 0 )
  {
    v9 = idProjectile::DoDamage(this, ent, dir, trace);
  }
  else
  {
    v9 = idProjectile::DoDirectDamage(this, ent, dir, trace);
  }
  return *((float *)&v9 + 1);
}


// ========================================================================
// ?Collide@idProjectile_Dagger@@UAA?AW4collide_t@@HAAUtrace_t@@ABVidVec3@@@Z
// EA  : 0x82ED6650
// RVA : 0x00ED6650
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idProjectile_Dagger::Collide(
        idProjectile_Dagger *this,
        const int physId,
        trace_t *collision,
        const idVec3 *velocity)
{
  idPresentable *presentable; // r3
  int v8; // r3
  __int64 v9; // r8
  int v10; // r6
  __int64 v11; // r10
  weaponStatsTag_t weaponStatsTag; // r4
  idWaterEntity *v13; // r28
  char v14; // r11
  idPhysics *Physics; // r29
  int GameMs; // r26
  idPhysics *v17; // r3
  const idDeclProjectile *projectileDecl; // r25
  idAIEventManager *p_aiEventManager; // r29
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v21; // r20
  const idEntity *AttackerEntity; // r3
  const idPresentable *Attacker; // r3
  idPhysics *v24; // r3
  const idVec3 *v25; // r3
  double v26; // fp1
  weaponStatsTag_t v27; // r11
  double v28; // fp29
  char v29; // r11
  bool v30; // zf
  double x; // fp13
  double y; // fp12
  double z; // fp11
  double v34; // fp6
  double v35; // fp7
  double v36; // fp4
  double v37; // fp5
  double v38; // fp3
  double v39; // fp1
  double v40; // fp2
  double v41; // fp0
  const idDeclProjectile *v42; // r25
  idPhysics_RigidBody *p_physicsObj; // r26
  idProjectile_Dagger_vtbl *v44; // r11
  char v45; // r25
  idPhysics *v46; // r3
  idPhysics *v47; // r3
  __int128 v48; // r7 OVERLAPPED
  int v49; // r8
  __int64 v50; // r10
  double v53; // fp2
  double v54; // fp7
  double v55; // fp4
  int v56; // r3
  idPresentable *v57; // r11
  int v58; // r30
  idPhysics_RigidBody *v59; // r3
  idPhysics_RigidBody_vtbl *v60; // r31
  int v61; // r3
  int surfaceType; // r11
  int *v64; // r10
  float *p_z; // r11
  int i; // ctr
  double v67; // fp31
  double v68; // fp30
  double v69; // fp29
  idPhysics *v70; // r3
  double v71; // fp4
  double v72; // fp3
  idPhysics *v73; // r3
  __int16 *p_granularity; // r9
  float *v75; // r10
  int j; // ctr
  __int64 v77; // [sp+8h] [-1E8h]
  __int64 v78; // [sp+8h] [-1E8h]
  __int64 v79; // [sp+10h] [-1E0h]
  __int64 v80; // [sp+10h] [-1E0h]
  __int64 v81; // [sp+18h] [-1D8h]
  __int64 v82; // [sp+18h] [-1D8h]
  __int64 v83; // [sp+20h] [-1D0h]
  __int64 v84; // [sp+20h] [-1D0h]
  __int64 v85; // [sp+28h] [-1C8h]
  __int64 v86; // [sp+28h] [-1C8h]
  __int64 v87; // [sp+30h] [-1C0h]
  __int64 v88; // [sp+30h] [-1C0h]
  __int64 v89; // [sp+38h] [-1B8h]
  __int64 v90; // [sp+38h] [-1B8h]
  __int64 v91; // [sp+40h] [-1B0h]
  __int64 v92; // [sp+40h] [-1B0h]
  int v93[3]; // [sp+50h] [-1A0h] BYREF
  int v94; // [sp+5Ch] [-194h] BYREF
  __int64 v95; // [sp+60h] [-190h] BYREF
  __int64 v96; // [sp+68h] [-188h]
  float v97; // [sp+70h] [-180h]
  float v98; // [sp+74h] [-17Ch]
  float v99; // [sp+78h] [-178h]
  float v100; // [sp+7Ch] [-174h]
  float v101; // [sp+80h] [-170h]
  float v102[4]; // [sp+88h] [-168h] BYREF
  float v103[4]; // [sp+98h] [-158h] BYREF
  float v104[4]; // [sp+A8h] [-148h] BYREF
  float v105[4]; // [sp+B8h] [-138h] BYREF
  float v106[4]; // [sp+C8h] [-128h] BYREF
  float v107[4]; // [sp+D8h] [-118h] BYREF
  float v108[6]; // [sp+E8h] [-108h] BYREF
  float v109[4]; // [sp+100h] [-F0h] BYREF
  float v110[4]; // [sp+110h] [-E0h] BYREF
  float v111[4]; // [sp+120h] [-D0h] BYREF
  idAIEventManager v112; // [sp+130h] [-C0h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    v8 = (int)presentable->GetProjectileInterface(this: presentable);
  else
    v8 = 0;
  if ( *(_DWORD *)(v8 + 1252) != 1 )
    return 0;
  idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
  LODWORD(v11) = collision->c.surfaceFlags & 1;
  if ( (_DWORD)v11 != 0 )
  {
LABEL_25:
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0, a4: v10, a5: v9, a6: v11);
    return 1;
  }
  weaponStatsTag = this->weaponStatsTag;
  v13 = (idWaterEntity *)gameLocal->entities.ptr[collision->c.entityNum];
  v93[0] = 0;
  if ( (*(_DWORD *)&weaponStatsTag & 0xFC000000) != 0
    || (*(_DWORD *)&weaponStatsTag & 0x3C00000) != 0
    || (v14 = 0, (*(_DWORD *)&weaponStatsTag & 0x3FFFFF) != 0) )
  {
    v14 = 1;
  }
  if ( v14 != 0 )
    idGameLocal::SetCurrentStatsDamage(this: gameLocal, tag: *(weaponStatsTag_t **)&weaponStatsTag, delayedCount: v93);
  Physics = idEntity::GetPhysics(this);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v17 = Physics;
  projectileDecl = this->projectileDecl;
  GetOrigin = Physics->GetOrigin;
  p_aiEventManager = &gameLocal->aiEventManager;
  v21 = GetOrigin(this: v17, a2: 0);
  AttackerEntity = idProjectile::GetAttackerEntity(this);
  idAIEventManager::AddEvent(
    this: &v112,
    result: p_aiEventManager,
    eventDecl: projectileDecl->collideAIEventDecl,
    curTime: GameMs,
    originator: this,
    instigator: AttackerEntity,
    origin: v21,
    delay: 500);
  Attacker = idProjectile::GetAttacker(this);
  idClientGame::ProjectileImpact(
    this: clientGame,
    trace: collision,
    attacker: Attacker,
    projDef: this->projectileDecl,
    tracerFired: false,
    noDecals: false,
    noSounds: false);
  v24 = idEntity::GetPhysics(this);
  v25 = (const idVec3 *)v24->GetAxis(this: v24, a2: 0);
  v26 = idProjectile_Arrow::CheckDoDamage(this, ent: v13, dir: v25, trace: collision);
  v27 = this->weaponStatsTag;
  v28 = v26;
  if ( (*(_DWORD *)&v27 & 0xFC000000) != 0
    || (*(_DWORD *)&v27 & 0x3C00000) != 0
    || (v30 = (*(_DWORD *)&v27 & 0x3FFFFF) == 0, v29 = 0, !v30) )
  {
    v29 = 1;
  }
  if ( v29 != 0 )
  {
    idGameLocal::ClearCurrentStatsDamage(this: gameLocal);
    idGameLocal::WeaponFiredDone(
      this: gameLocal,
      tag: *(weaponStatsTag_t **)&this->weaponStatsTag,
      carryoverCount: v93[0]);
  }
  if ( g_debugWeapon.valueInteger != 0 )
  {
    if ( collision->fraction >= 1.0 )
    {
      idLib::Warning(fmt: "idProjectile_Arrow got Collide with collision.fraction >= 1.0f");
    }
    else
    {
      x = collision->c.point.x;
      y = collision->c.point.y;
      z = collision->c.point.z;
      v109[0] = 1.0;
      v109[3] = 1.0;
      v109[1] = 0.0;
      v109[2] = 0.0;
      v107[0] = (float)x + (float)4.0;
      v107[1] = y;
      v107[2] = z;
      v104[0] = (float)x - (float)4.0;
      v104[1] = y;
      v104[2] = z;
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)v109,
        a3: (const idVec3 *)v104,
        a4: (const idVec3 *)v107,
        a5: 5000,
        a6: true);
      v34 = (float)(collision->c.point.y + (float)4.0);
      v35 = collision->c.point.x;
      v36 = (float)(collision->c.point.y - (float)4.0);
      v37 = collision->c.point.z;
      v111[0] = 1.0;
      v111[1] = 0.0;
      v111[2] = 0.0;
      v111[3] = 1.0;
      v106[0] = v35;
      v106[1] = v34;
      v106[2] = v37;
      v108[0] = v35;
      v108[1] = v36;
      v108[2] = v37;
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)v111,
        a3: (const idVec3 *)v108,
        a4: (const idVec3 *)v106,
        a5: 5000,
        a6: true);
      v38 = collision->c.point.z;
      v39 = (float)(collision->c.point.z + (float)4.0);
      v110[0] = 1.0;
      v110[3] = 1.0;
      v40 = collision->c.point.x;
      v41 = collision->c.point.y;
      v110[1] = 0.0;
      v110[2] = 0.0;
      v102[0] = v40;
      v102[1] = v41;
      v102[2] = v39;
      v105[0] = v40;
      v105[1] = v41;
      v105[2] = (float)v38 - (float)4.0;
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)v110,
        a3: (const idVec3 *)v105,
        a4: (const idVec3 *)v102,
        a5: 5000,
        a6: true);
    }
  }
  v42 = this->projectileDecl;
  p_physicsObj = &this->physicsObj;
  idPhysics_RigidBody::SetFriction(
    this: &this->physicsObj,
    linear: v42->notHitscanInfo.physicsProperties.linearFriction,
    angular: v42->notHitscanInfo.physicsProperties.angularFriction,
    contact: v42->notHitscanInfo.physicsProperties.contactFriction);
  idPhysics_RigidBody::SetWaterFriction(
    this: &this->physicsObj,
    linear: v42->notHitscanInfo.physicsProperties.linearFrictionWater,
    angular: v42->notHitscanInfo.physicsProperties.angularFrictionWater);
  v44 = this->__vftable;
  if ( !v42->notHitscanInfo.explodeOnImpact )
  {
    HIDWORD(v11) = v44->ShouldRemoveOnCollision(this, a2: collision, a3: v28);
    if ( HIDWORD(v11) != 0 )
      goto LABEL_25;
    v45 = 0;
    if ( !this->alignToVelocity )
      goto LABEL_39;
    this->alignToVelocity = false;
    if ( idEntity::GetPhysics(this) != nullptr )
    {
      v46 = idEntity::GetPhysics(this);
      if ( v46->GetClipModel(this: v46, a2: 0) != nullptr )
      {
        v47 = idEntity::GetPhysics(this);
        v47->GetClipModel(this: v47, a2: 0)->ownerNumber = 0x1FFF;
      }
    }
    HIBYTE(v95) = 105;
    LODWORD(v95) = 89;
    DWORD1(v48) = HIDWORD(v95);
    *((_QWORD *)&v48 + 1) = v96;
    v49 = __ROL4__(LODWORD(v97), 32);
    idEventReceiver::PostEventMS(
      this,
      ev: &EV_StopFX,
      arg1: *(__int64 *)((char *)&v48 + 4),
      a4: *(__int64 *)((char *)&v48 - 4),
      a5: 0x5900000069LL,
      a6: v77,
      a7: v79,
      a8: v81,
      a9: v83,
      a10: v85,
      a11: v87,
      a12: v89,
      a13: v91);
    if ( this->inventoryItem == nullptr )
    {
      LODWORD(v50) = &v95;
      *((float *)&v95 + 1) = 1.0;
      HIBYTE(v95) = 102;
      HIDWORD(v50) = &idTarget_SoundDuck::Type.node;
      idEventReceiver::PostEventMS(
        this,
        ev: &EV_FadeOut,
        arg1: v95,
        a4: __SPAIR64__(v96, __ROL4__(LODWORD(v97), 32)),
        a5: v50,
        a6: v78,
        a7: v80,
        a8: v82,
        a9: v84,
        a10: v86,
        a11: v88,
        a12: v90,
        a13: v92);
    }
    _FP5 = (float)((float)((float)(velocity->z * velocity->z)
                         + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f3, f5, f6, f13 }
    v53 = __frsqrte(_FP3);
    v54 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v53
                                                                                        * (float)((float)((float)(velocity->z * velocity->z) + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y)))
                                                                                                * (float)0.5))
                                                                                * (float)v53)
                                                                        - (float)1.5)
                                                        * (float)v53)
                                                * (float)((float)((float)(velocity->z * velocity->z)
                                                                + (float)((float)(velocity->x * velocity->x)
                                                                        + (float)(velocity->y * velocity->y)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v53
                                                                                * (float)((float)((float)(velocity->z * velocity->z)
                                                                                                + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y)))
                                                                                        * (float)0.5))
                                                                        * (float)v53)
                                                                - (float)1.5)
                                                * (float)v53))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v53
                                                        * (float)((float)((float)(velocity->z * velocity->z)
                                                                        + (float)((float)(velocity->x * velocity->x)
                                                                                + (float)(velocity->y * velocity->y)))
                                                                * (float)0.5))
                                                * (float)v53)
                                        - (float)1.5)
                        * (float)v53));
    v55 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v53 * (float)((float)((float)(velocity->z * velocity->z) + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y))) * (float)0.5)) * (float)v53) - (float)1.5)
                                                                                        * (float)v53)
                                                                                * (float)((float)((float)(velocity->z * velocity->z)
                                                                                                + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y)))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v53 * (float)((float)((float)(velocity->z * velocity->z) + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y))) * (float)0.5)) * (float)v53)
                                                                                                - (float)1.5)
                                                                                * (float)v53))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v53
                                                                                        * (float)((float)((float)(velocity->z * velocity->z) + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y)))
                                                                                                * (float)0.5))
                                                                                * (float)v53)
                                                                        - (float)1.5)
                                                        * (float)v53))
                                        * (float)((float)((float)(velocity->z * velocity->z)
                                                        + (float)((float)(velocity->x * velocity->x)
                                                                + (float)(velocity->y * velocity->y)))
                                                * (float)0.5))
                                * (float)v54)
                        - (float)1.5);
    if ( (float)((float)((float)v55
                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v53 * (float)((float)((float)(velocity->z * velocity->z) + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y))) * (float)0.5))
                                                                                               * (float)v53)
                                                                                       - (float)1.5)
                                                                       * (float)v53)
                                                               * (float)((float)((float)(velocity->z * velocity->z)
                                                                               + (float)((float)(velocity->x
                                                                                               * velocity->x)
                                                                                       + (float)(velocity->y
                                                                                               * velocity->y)))
                                                                       * (float)0.5))
                                                       * (float)((float)-(float)((float)((float)((float)v53
                                                                                               * (float)((float)((float)(velocity->z * velocity->z) + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y))) * (float)0.5))
                                                                                       * (float)v53)
                                                                               - (float)1.5)
                                                               * (float)v53))
                                               - (float)1.5)
                               * (float)((float)-(float)((float)((float)((float)v53
                                                                       * (float)((float)((float)(velocity->z
                                                                                               * velocity->z)
                                                                                       + (float)((float)(velocity->x * velocity->x)
                                                                                               + (float)(velocity->y * velocity->y)))
                                                                               * (float)0.5))
                                                               * (float)v53)
                                                       - (float)1.5)
                                       * (float)v53)))
               * (float)((float)(velocity->z * velocity->z)
                       + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y)))) < 850.0
      || !this->ShouldStickOnCollision(this, a2: collision) )
    {
      goto LABEL_39;
    }
    v45 = 1;
    if ( (unsigned __int8)idWorldspawn::IsTypeOf(c: v13) != 0 || (unsigned __int8)idStaticEntity::IsTypeOf(c: v13) != 0 )
    {
      surfaceType = collision->c.surfaceType;
      if ( surfaceType != 1 && surfaceType != 2 && surfaceType != 16 )
      {
        v64 = &v94;
        p_z = &this->lastVel.z;
        for ( i = 9; i != 0; --i )
          *++v64 = *(_DWORD *)++p_z;
        v67 = (float)((float)(this->originOffset.x * *(float *)&v95)
                    + (float)((float)(v99 * this->originOffset.z) + (float)(*((float *)&v96 + 1) * this->originOffset.y)));
        v68 = (float)((float)(v97 * this->originOffset.y)
                    + (float)((float)(*((float *)&v95 + 1) * this->originOffset.x) + (float)(v100 * this->originOffset.z)));
        v69 = (float)((float)(v98 * this->originOffset.y)
                    + (float)((float)(*(float *)&v96 * this->originOffset.x) + (float)(v101 * this->originOffset.z)));
        v70 = idEntity::GetPhysics(this);
        v71 = (float)(collision->c.point.y + (float)v68);
        v72 = (float)(collision->c.point.z + (float)v69);
        v103[0] = collision->c.point.x + (float)v67;
        v103[1] = v71;
        v103[2] = v72;
        v70->SetOrigin(this: v70, a2: (const idVec3 *)v103, a3: -1);
        v73 = idEntity::GetPhysics(this);
        p_granularity = &v112.eventList.granularity;
        v75 = &this->lastVel.z;
        for ( j = 9; j != 0; --j )
        {
          ++v75;
          p_granularity += 2;
          *(float *)p_granularity = *v75;
        }
        v73->SetAxis(this: v73, a2: (const idMat3 *)&v112.eventHash, a3: -1);
        goto LABEL_39;
      }
    }
    else
    {
      if ( this->Attach(this, a2: v13, a3: collision) )
      {
LABEL_39:
        if ( v45 != 0 )
        {
          idProjectile::SetState(this, state: STUCK);
          return 1;
        }
        idProjectile::SetState(this, state: BOUNCING);
        v56 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v57 = this->presentable;
        v58 = v56;
        if ( v57 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v57 = this->presentable;
        }
        idFXManager::StopFX(this: &v57->fxManager, time: v58, stopCondition: 89, immediateStop: false);
        p_physicsObj->SetGravity(this: &this->physicsObj, a2: &gameLocal->clientGame.gravity);
        v59 = &this->physicsObj;
        v60 = p_physicsObj->__vftable;
        v61 = p_physicsObj->GetClipMask(this: v59, a2: -1);
        v60->SetClipMask(this: p_physicsObj, a2: v61 & 0xFFFFFF7F, a3: -1);
        return 0;
      }
      idLib::Warning(fmt: " arrow stick failed ");
    }
    v45 = 0;
    goto LABEL_39;
  }
  v44->Explode(this, a2: v13, a3: collision);
  return 1;
}


// ========================================================================
// ?Explode@idProjectile_Dagger@@UAAXPAVidEntity@@PAUtrace_t@@@Z
// EA  : 0x82ED6E68
// RVA : 0x00ED6E68
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Dagger::Explode(idProjectile_Dagger *this, idWaterEntity *ent, trace_t *trace)
{
  double x; // fp0
  double y; // fp13
  double v8; // fp11
  double v9; // fp10
  double z; // fp9
  double v11; // fp12
  idPhysics *Physics; // r3
  float *v13; // r3
  idPhysics *v14; // r29
  idPhysics *v15; // r26
  idPhysics *v16; // r25
  idPhysics *v17; // r24
  float *v18; // r3
  double v19; // fp29
  double v22; // fp6
  double v23; // fp13
  double v24; // fp11
  double v25; // fp28
  float *v26; // r3
  idBreakableManager *p_breakableManager; // r29
  double v28; // fp27
  double v31; // fp2
  double v32; // fp9
  double v33; // fp7
  double v34; // fp31
  const idMat3 *v35; // r26
  const idVec3 *v36; // r3
  unsigned __int64 v37; // r6
  const char *v38; // r7
  idPresentable *presentable; // r3
  int v40; // r3
  idPresentable *v41; // r3
  int v42; // r3
  unsigned __int64 v43; // r6
  const char *v44; // r7
  idPhysics *v45; // r3
  idPLogScope v46[2]; // [sp+50h] [-B0h] BYREF
  idPLogScope v47[2]; // [sp+60h] [-A0h] BYREF
  idVec3 v48; // [sp+70h] [-90h] BYREF
  idVec3 v49; // [sp+80h] [-80h] BYREF

  if ( this->breakable != nullptr )
  {
    if ( trace != nullptr )
    {
      x = trace->endpos.x;
      y = trace->endpos.y;
      v8 = trace->c.normal.x;
      v46[0].logIndex = (int)&trace->endpos;
      v9 = trace->c.normal.y;
      v46[0].logIndex = (int)&trace->c.normal;
      z = trace->c.normal.z;
      v11 = trace->endpos.z;
      v49.x = x;
      v49.y = y;
      v48.x = v8;
      v48.y = v9;
      v48.z = z;
    }
    else
    {
      Physics = idEntity::GetPhysics(this);
      v13 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v49.x = *v13;
      v49.y = v13[1];
      v11 = v13[2];
      v48.x = 0.0;
      v48.y = 0.0;
      v48.z = -1.0;
    }
    v49.z = v11;
    v14 = idEntity::GetPhysics(this);
    v15 = idEntity::GetPhysics(this);
    v16 = idEntity::GetPhysics(this);
    v17 = idEntity::GetPhysics(this);
    v18 = (float *)v15->GetLinearVelocity(this: (idPhysics *)v47, result: (idVec3 *)v15, a3: 0);
    v19 = (float)((float)(v18[2] * v18[2]) + (float)((float)(*v18 * *v18) + (float)(v18[1] * v18[1])));
    _FP9 = (float)((float)((float)(v18[2] * v18[2]) + (float)((float)(*v18 * *v18) + (float)(v18[1] * v18[1])))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f7, f9, f29, f0 }
    v22 = __frsqrte(_FP7);
    v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                        * (float)((float)((float)(v18[2] * v18[2]) + (float)((float)(*v18 * *v18) + (float)(v18[1] * v18[1])))
                                                                                                * (float)0.5))
                                                                                * (float)v22)
                                                                        - (float)1.5)
                                                        * (float)v22)
                                                * (float)((float)((float)(v18[2] * v18[2])
                                                                + (float)((float)(*v18 * *v18) + (float)(v18[1] * v18[1])))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v22
                                                                                * (float)((float)((float)(v18[2] * v18[2])
                                                                                                + (float)((float)(*v18 * *v18) + (float)(v18[1] * v18[1])))
                                                                                        * (float)0.5))
                                                                        * (float)v22)
                                                                - (float)1.5)
                                                * (float)v22))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v22
                                                        * (float)((float)((float)(v18[2] * v18[2])
                                                                        + (float)((float)(*v18 * *v18)
                                                                                + (float)(v18[1] * v18[1])))
                                                                * (float)0.5))
                                                * (float)v22)
                                        - (float)1.5)
                        * (float)v22));
    v24 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(v18[2] * v18[2]) + (float)((float)(*v18 * *v18) + (float)(v18[1] * v18[1]))) * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                        * (float)v22)
                                                                                * (float)((float)((float)(v18[2] * v18[2])
                                                                                                + (float)((float)(*v18 * *v18) + (float)(v18[1] * v18[1])))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(v18[2] * v18[2]) + (float)((float)(*v18 * *v18) + (float)(v18[1] * v18[1]))) * (float)0.5)) * (float)v22)
                                                                                                - (float)1.5)
                                                                                * (float)v22))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v22
                                                                                        * (float)((float)((float)(v18[2] * v18[2]) + (float)((float)(*v18 * *v18) + (float)(v18[1] * v18[1])))
                                                                                                * (float)0.5))
                                                                                * (float)v22)
                                                                        - (float)1.5)
                                                        * (float)v22))
                                        * (float)((float)((float)(v18[2] * v18[2])
                                                        + (float)((float)(*v18 * *v18) + (float)(v18[1] * v18[1])))
                                                * (float)0.5))
                                * (float)v23)
                        - (float)1.5);
    v25 = (float)((float)v24
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                                * (float)((float)((float)(v18[2] * v18[2]) + (float)((float)(*v18 * *v18) + (float)(v18[1] * v18[1]))) * (float)0.5))
                                                                                        * (float)v22)
                                                                                - (float)1.5)
                                                                * (float)v22)
                                                        * (float)((float)((float)(v18[2] * v18[2])
                                                                        + (float)((float)(*v18 * *v18)
                                                                                + (float)(v18[1] * v18[1])))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v22
                                                                                        * (float)((float)((float)(v18[2] * v18[2]) + (float)((float)(*v18 * *v18) + (float)(v18[1] * v18[1])))
                                                                                                * (float)0.5))
                                                                                * (float)v22)
                                                                        - (float)1.5)
                                                        * (float)v22))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v22
                                                                * (float)((float)((float)(v18[2] * v18[2])
                                                                                + (float)((float)(*v18 * *v18)
                                                                                        + (float)(v18[1] * v18[1])))
                                                                        * (float)0.5))
                                                        * (float)v22)
                                                - (float)1.5)
                                * (float)v22)));
    v26 = (float *)v14->GetAngularVelocity(this: (idPhysics *)v46, result: (idVec3 *)v14, a3: 0);
    p_breakableManager = &gameLocal->breakableManager;
    v28 = (float)((float)(v26[2] * v26[2]) + (float)((float)(*v26 * *v26) + (float)(v26[1] * v26[1])));
    _FP5 = (float)((float)((float)(v26[2] * v26[2]) + (float)((float)(*v26 * *v26) + (float)(v26[1] * v26[1])))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f3, f5, f27, f0 }
    v31 = __frsqrte(_FP3);
    v32 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31
                                                                                        * (float)((float)((float)(v26[2] * v26[2]) + (float)((float)(*v26 * *v26) + (float)(v26[1] * v26[1])))
                                                                                                * (float)0.5))
                                                                                * (float)v31)
                                                                        - (float)1.5)
                                                        * (float)v31)
                                                * (float)((float)((float)(v26[2] * v26[2])
                                                                + (float)((float)(*v26 * *v26) + (float)(v26[1] * v26[1])))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v31
                                                                                * (float)((float)((float)(v26[2] * v26[2])
                                                                                                + (float)((float)(*v26 * *v26) + (float)(v26[1] * v26[1])))
                                                                                        * (float)0.5))
                                                                        * (float)v31)
                                                                - (float)1.5)
                                                * (float)v31))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v31
                                                        * (float)((float)((float)(v26[2] * v26[2])
                                                                        + (float)((float)(*v26 * *v26)
                                                                                + (float)(v26[1] * v26[1])))
                                                                * (float)0.5))
                                                * (float)v31)
                                        - (float)1.5)
                        * (float)v31));
    v33 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)(v26[2] * v26[2]) + (float)((float)(*v26 * *v26) + (float)(v26[1] * v26[1]))) * (float)0.5)) * (float)v31) - (float)1.5)
                                                                                        * (float)v31)
                                                                                * (float)((float)((float)(v26[2] * v26[2])
                                                                                                + (float)((float)(*v26 * *v26) + (float)(v26[1] * v26[1])))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)(v26[2] * v26[2]) + (float)((float)(*v26 * *v26) + (float)(v26[1] * v26[1]))) * (float)0.5)) * (float)v31)
                                                                                                - (float)1.5)
                                                                                * (float)v31))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v31
                                                                                        * (float)((float)((float)(v26[2] * v26[2]) + (float)((float)(*v26 * *v26) + (float)(v26[1] * v26[1])))
                                                                                                * (float)0.5))
                                                                                * (float)v31)
                                                                        - (float)1.5)
                                                        * (float)v31))
                                        * (float)((float)((float)(v26[2] * v26[2])
                                                        + (float)((float)(*v26 * *v26) + (float)(v26[1] * v26[1])))
                                                * (float)0.5))
                                * (float)v32)
                        - (float)1.5);
    v34 = (float)((float)v33
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31
                                                                                                * (float)((float)((float)(v26[2] * v26[2]) + (float)((float)(*v26 * *v26) + (float)(v26[1] * v26[1]))) * (float)0.5))
                                                                                        * (float)v31)
                                                                                - (float)1.5)
                                                                * (float)v31)
                                                        * (float)((float)((float)(v26[2] * v26[2])
                                                                        + (float)((float)(*v26 * *v26)
                                                                                + (float)(v26[1] * v26[1])))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v31
                                                                                        * (float)((float)((float)(v26[2] * v26[2]) + (float)((float)(*v26 * *v26) + (float)(v26[1] * v26[1])))
                                                                                                * (float)0.5))
                                                                                * (float)v31)
                                                                        - (float)1.5)
                                                        * (float)v31))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v31
                                                                * (float)((float)((float)(v26[2] * v26[2])
                                                                                + (float)((float)(*v26 * *v26)
                                                                                        + (float)(v26[1] * v26[1])))
                                                                        * (float)0.5))
                                                        * (float)v31)
                                                - (float)1.5)
                                * (float)v31)));
    v35 = v16->GetAxis(this: v16, a2: 0);
    v36 = v17->GetOrigin(this: v17, a2: 0);
    idBreakableManager::UseBreakable(
      this: p_breakableManager,
      decl: this->breakable,
      origin: v36,
      axis: v35,
      dir: &v48,
      pos: &v49,
      impulse: (float)((float)((float)v34 * (float)v28) + (float)((float)v25 * (float)v19)),
      fadeTime: 10.0);
  }
  RD_EventBegin(name: "idProjectile_Dagger::Explode");
  LODWORD(v37) = "idProjectile_Dagger::Explode";
  HIDWORD(v37) = 2;
  idPLogScope::idPLogScope(this: v46, pl: &pLog, gMask: v37, label: v38);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v40 = (int)presentable->GetProjectileInterface(this: presentable);
  else
    v40 = 0;
  if ( *(_DWORD *)(v40 + 1252) == 5 )
  {
    idPLogScope::~idPLogScope(this: v46);
  }
  else
  {
    v41 = this->presentable;
    if ( v41 != nullptr )
      v42 = (int)v41->GetProjectileInterface(this: v41);
    else
      v42 = 0;
    if ( *(_BYTE *)(v42 + 1264) != 0 )
      idEntity::StopSound(this, channel: SND_CHANNEL_BODY3, peerMask: 0xFFu);
    idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
    RD_EventBegin(name: "idProjectile_Dagger::Explode - unlink clip");
    LODWORD(v43) = "idProjectile_Dagger::Explode - unlink clip";
    HIDWORD(v43) = 2;
    idPLogScope::idPLogScope(this: v47, pl: &pLog, gMask: v43, label: v44);
    v45 = idEntity::GetPhysics(this);
    v45->UnlinkClip(this: v45);
    idPLogScope::~idPLogScope(this: v47);
    RD_EventEnd();
    this->Hide_2(this);
    idProjectile::Explode(this, ent, trace);
    idPLogScope::~idPLogScope(this: v46);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$503728
// EA  : 0x82ED7208
// RVA : 0x00ED7208
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_503728()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 140));
}


// ========================================================================
// __unwind$503729
// EA  : 0x82ED7230
// RVA : 0x00ED7230
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_503729()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 80));
}


// ========================================================================
// __unwind$503730
// EA  : 0x82ED7258
// RVA : 0x00ED7258
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_503730()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 141));
}


// ========================================================================
// __unwind$503731
// EA  : 0x82ED7280
// RVA : 0x00ED7280
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_503731()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 96));
}


// ========================================================================
// ?Collide@idProjectile_Grenade@@UAA?AW4collide_t@@HAAUtrace_t@@ABVidVec3@@@Z
// EA  : 0x82ED72A8
// RVA : 0x00ED72A8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idProjectile_Grenade::Collide(
        idProjectile_Grenade *this,
        int physId,
        trace_t *collision,
        const idVec3 *velocity,
        __int64 a5,
        __int64 a6)
{
  int detonationTime; // r10
  int v12; // r3
  int v13; // r10
  idEntity *v14; // r30
  idEventArg *v15; // r3
  __int128 v16; // r7 OVERLAPPED
  int v17; // r8
  idEntity *powerSourceToMoveTo; // r3
  idPhysics *Physics; // r28
  idPhysics *v20; // r3
  float *v21; // r24
  float *v22; // r3
  double v23; // fp6
  double v24; // fp5
  double v25; // fp4
  idPhysics_RigidBody3DOF *p_physicsObj; // r31
  idProjectile_Grenade_vtbl *v27; // r11
  __int64 v28; // r10
  __int64 v29; // r8
  idProjectile_Grenade *v30; // r3
  int v31; // r3
  idProjectile *v32; // r3
  idPhysics_RigidBody3DOF *v33; // r31
  idPlayer *AttackerEntity; // r3
  idPlayer *v35; // r4
  idPhysics *v36; // r3
  float *v37; // r3
  idPhysics_RigidBody3DOF_vtbl *v38; // r29
  int v39; // r3
  idPhysics *v40; // r30
  idPhysics *v41; // r29
  float *v42; // r3
  double v43; // fp10
  double v44; // fp9
  idPhysics *v45; // r30
  idPhysics *v46; // r31
  float *v47; // r3
  double v48; // fp3
  double v49; // fp1
  idEntity *v50; // r30
  idPhysics *v51; // r3
  const idVec3 *v52; // r3
  int GameMs; // r3
  __int64 v54; // [sp+8h] [-138h]
  __int64 v55; // [sp+10h] [-130h]
  __int64 v56; // [sp+18h] [-128h]
  __int64 v57; // [sp+20h] [-120h]
  __int64 v58; // [sp+28h] [-118h]
  __int64 v59; // [sp+30h] [-110h]
  __int64 v60; // [sp+38h] [-108h]
  __int64 v61; // [sp+40h] [-100h]
  __int64 v62; // [sp+48h] [-F8h]
  __int64 v63; // [sp+50h] [-F0h]
  __int64 v64; // [sp+58h] [-E8h]
  float v65[4]; // [sp+70h] [-D0h] BYREF
  float v66[4]; // [sp+80h] [-C0h] BYREF
  char v67; // [sp+90h] [-B0h] BYREF
  int bodyId; // [sp+94h] [-ACh]
  __int64 v69; // [sp+98h] [-A8h]
  idEventArg v70; // [sp+B0h] [-90h] BYREF
  idEventReceiver v71[2]; // [sp+D0h] [-70h] BYREF

  this->lastCollisionNormal = collision->c.normal;
  LODWORD(a6) = collision->c.surfaceFlags & 1;
  if ( (_DWORD)a6 != 0 )
  {
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0, a4: (int)velocity, a5, a6);
    return 1;
  }
  detonationTime = this->detonationTime;
  ++this->numBounces;
  if ( detonationTime < 0 )
  {
    v12 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idProjectile_Grenade::StartDetonationTimer(this, startTime: v12);
  }
  v13 = collision->c.entityNum + 21563;
  v14 = *((idEntity **)&gameLocal->__vftable + v13);
  if ( v14 != nullptr )
  {
    idEntity::Signal(this: *((idEntity **)&gameLocal->__vftable + v13), signalnum: SIG_TOUCH);
    if ( v14->RespondsTo(this: v14, a2: &EV_Touch) )
    {
      bodyId = collision->c.bodyId;
      v67 = 105;
      v15 = idEventArg::idEventArg(this: &v70, data: this);
      *(_QWORD *)((char *)&v16 + 4) = *(_QWORD *)&v15->type;
      v17 = __ROL4__(LODWORD(v15->value.q[3]), 32);
      *((_QWORD *)&v16 + 1) = *(_QWORD *)&v15->value.q[1];
      idEventReceiver::ProcessEvent(
        this: v71,
        result: v14,
        arg1: *(__int64 *)((char *)&v16 + 4),
        arg2: *(__int64 *)((char *)&v16 - 4),
        a5: v69,
        a6: v54,
        a7: v55,
        a8: v56,
        a9: v57,
        a10: v58,
        a11: v59,
        a12: v60,
        a13: v61,
        a14: v62,
        a15: v63,
        a16: v64);
    }
  }
  powerSourceToMoveTo = this->powerSourceToMoveTo;
  if ( powerSourceToMoveTo != nullptr )
  {
    Physics = idEntity::GetPhysics(this: powerSourceToMoveTo);
    v20 = idEntity::GetPhysics(this);
    v21 = (float *)v20->GetOrigin(this: v20, a2: 0);
    v22 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
    v23 = (float)(v21[1] - (float)((float)(v22[4] + v22[1]) * (float)0.5));
    v24 = (float)(v21[2] - (float)((float)(v22[5] + v22[2]) * (float)0.5));
    v25 = (float)(*v21 - (float)((float)(v22[3] + *v22) * (float)0.5));
    if ( (float)((float)((float)v25 * (float)v25)
               + (float)((float)((float)v24 * (float)v24) + (float)((float)v23 * (float)v23))) <= (double)(float)(g_projectileEMPstick.valueFloat * g_projectileEMPstick.valueFloat) )
    {
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_ANY,
        shader: this->empStuckToSound,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
      idProjectile::SetState(this, state: STUCK);
      return 1;
    }
  }
  if ( this->explodeOnImpact )
  {
    this->Explode(this, a2: v14, a3: collision);
    p_physicsObj = &this->physicsObj;
    p_physicsObj->SetContents(this: p_physicsObj, a2: 0, a3: -1);
    p_physicsObj->SetClipMask(this: p_physicsObj, a2: 0, a3: -1);
    return 0;
  }
  if ( this->stickOnImpact )
  {
    if ( (unsigned __int8)idWorldspawn::IsTypeOf(c: v14) != 0 || (unsigned __int8)idStaticEntity::IsTypeOf(c: v14) != 0 )
    {
      v30 = this;
    }
    else
    {
      v27 = this->__vftable;
      if ( !this->stickToActors )
      {
        v27->Explode(this, a2: v14, a3: collision);
LABEL_22:
        idProjectile_Grenade::PlayBounceSound(this, vel: velocity, collision);
        v33 = &this->physicsObj;
        v33->SetContents(this: v33, a2: 0, a3: -1);
        v33->SetClipMask(this: v33, a2: 0, a3: -1);
        return 1;
      }
      HIDWORD(v28) = v27->Attach(this, a2: v14, a3: collision);
      v30 = this;
      if ( HIDWORD(v28) == 0 )
        return idProjectile::Collide(this: v30, physId, collision, velocity, a5: v29, a6: v28);
    }
    idEntity::BecomeActive(this: v30, flags: 1);
    v31 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idProjectile_Grenade::StartDetonationTimer(this, startTime: v31);
    idProjectile::SetState(this: v32, state: STUCK);
    goto LABEL_22;
  }
  if ( (!this->explodeOnActors
     || (unsigned __int8)idActor::IsTypeOf(c: v14) == 0
     || (unsigned __int8)idPlayer::IsTypeOf(c: v14) != 0)
    && (!this->explodeOnVehicles || (unsigned __int8)idVehicle::IsTypeOf(c: v14) == 0)
    || v14 == nullptr
    || v14->IsDead(this: v14) )
  {
    if ( (unsigned __int8)idWaterEntity::IsTypeOf(c: v14) != 0 )
    {
      v36 = idEntity::GetPhysics(this);
      v37 = (float *)v36->GetLinearVelocity(this: (idPhysics *)&v67, result: (idVec3 *)v36, a3: 0);
      this->splashVelocity.x = *v37;
      this->splashVelocity.y = v37[1];
      this->splashVelocity.z = v37[2];
      this->physicsObj.SetClipMask(this: &this->physicsObj, a2: 8495233, a3: -1);
      v38 = this->physicsObj.__vftable;
      v39 = v38->GetContents(this: &this->physicsObj, a2: -1);
      v38->SetContents(this: &this->physicsObj, a2: v39 | 1, a3: -1);
      v40 = idEntity::GetPhysics(this);
      v41 = idEntity::GetPhysics(this);
      v42 = (float *)v40->GetLinearVelocity(this: (idPhysics *)&v67, result: (idVec3 *)v40, a3: 0);
      v43 = v42[1];
      v44 = *v42;
      v65[2] = v42[2] * (float)0.25;
      v65[1] = (float)v43 * (float)0.25;
      v65[0] = (float)v44 * (float)0.25;
      v41->SetLinearVelocity(this: v41, a2: (const idVec3 *)v65, a3: 0);
      v45 = idEntity::GetPhysics(this);
      v46 = idEntity::GetPhysics(this);
      v47 = (float *)v45->GetAngularVelocity(this: (idPhysics *)&v67, result: (idVec3 *)v45, a3: 0);
      v48 = (float)(v47[2] * (float)0.25);
      v49 = (float)(v47[1] * (float)0.25);
      v66[0] = *v47 * (float)0.25;
      v66[2] = v48;
      v66[1] = v49;
      v46->SetAngularVelocity(this: v46, a2: (const idVec3 *)v66, a3: 0);
      return 2;
    }
    v50 = gameLocal->entities.ptr[collision->c.entityNum];
    v51 = idEntity::GetPhysics(this);
    v52 = (const idVec3 *)v51->GetAxis(this: v51, a2: 0);
    idProjectile::DoDirectDamage(this, ent: v50, dir: v52, trace: collision);
    if ( this->projectileDecl->notHitscanInfo.grenadeInfo.bounceSound != nullptr )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      LODWORD(v28) = this->nextBounceTime;
      if ( GameMs >= (int)v28 )
        idProjectile_Grenade::PlayBounceSound(this, vel: velocity, collision);
    }
    v30 = this;
    return idProjectile::Collide(this: v30, physId, collision, velocity, a5: v29, a6: v28);
  }
  this->Explode(this, a2: v14, a3: collision);
  this->physicsObj.SetContents(this: &this->physicsObj, a2: 0, a3: -1);
  this->physicsObj.SetClipMask(this: &this->physicsObj, a2: 0, a3: -1);
  AttackerEntity = (idPlayer *)idProjectile::GetAttackerEntity(this);
  v35 = idPlayer::CastTo(c: AttackerEntity);
  if ( v35 != nullptr && this->numBounces == 1 )
    idRageMetrics::WeaponFiredResult_DirectHit(
      this: clientGame->rageMetrics,
      player: (idVehicle *)v35,
      decl: this->projectileDecl);
  return 1;
}


// ========================================================================
// ?DisperseSubmunitions@idProjectile_Grenade@@AAAXPAVidEntity@@@Z
// EA  : 0x82ED79F0
// RVA : 0x00ED79F0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idProjectile_Grenade::DisperseSubmunitions(idProjectile_Grenade *this, idEntity *ent)
{
  unsigned __int64 v3; // r6
  const char *v4; // r7
  __int128 v5; // r7 OVERLAPPED
  int v6; // r8
  __int64 v7; // r10
  __int64 v8; // r8
  int v9; // r6
  idPhysics *Physics; // r3
  double v11; // fp31
  double v12; // fp30
  double v13; // fp29
  float *v14; // r3
  double v15; // fp24
  double v16; // fp23
  double v17; // fp22
  idPhysics *v18; // r3
  idMat3 *v19; // r4
  float y; // r7
  float z; // r6
  int numBounces; // r5
  double v23; // fp30
  idPhysics *v24; // r3
  float *v25; // r3
  double v26; // fp0
  double v27; // fp13
  double v28; // fp11
  double v29; // fp10
  double v31; // fp6
  double v33; // fp4
  double v34; // fp12
  double v35; // fp11
  double v36; // fp6
  int numSubMunitions; // r11
  int v38; // r24
  double v39; // fp25
  double v40; // fp26
  double v41; // fp27
  idPresentable *Attacker; // r3
  weaponStatsTag_t weaponStatsTag; // r11
  BOOL randomSubMunitions; // r10
  idClientGame *v45; // r30
  signed int num; // r11
  const idDeclProjectile *v47; // r8
  unsigned int seed; // r10
  signed int v49; // r6
  signed int v50; // r10
  const idDeclProjectile **list; // r9
  idFinishFireResults *v52; // r11
  int i; // ctr
  int v54; // r27
  idPresentablePtr<idPresentableProjectile> *projectiles; // r29
  int v56; // r30
  idPresentable *PresentableByIndex; // r3
  int v58; // r30
  bool v59; // cr58
  double v62; // fp4
  double v63; // fp8
  double v64; // fp6
  double v65; // fp3
  double v66; // fp2
  idPresentable *v67; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v69; // r30
  int v70; // r3
  __int64 totalTicks; // r11
  __int64 v72; // r9
  __int64 v73; // [sp+8h] [-B68h]
  __int64 v74; // [sp+10h] [-B60h]
  __int64 v75; // [sp+18h] [-B58h]
  __int64 v76; // [sp+20h] [-B50h]
  __int64 v77; // [sp+28h] [-B48h]
  __int64 v78; // [sp+30h] [-B40h]
  __int64 v79; // [sp+38h] [-B38h]
  __int64 v80; // [sp+40h] [-B30h]
  idMat3 v81; // [sp+50h] [-B20h] BYREF
  float v82; // [sp+74h] [-AFCh]
  __int64 v83; // [sp+78h] [-AF8h]
  float v84; // [sp+80h] [-AF0h]
  float v85; // [sp+84h] [-AECh]
  float v86; // [sp+88h] [-AE8h]
  float v87; // [sp+8Ch] [-AE4h]
  float v88; // [sp+90h] [-AE0h]
  idPLogScope v89; // [sp+98h] [-AD8h] BYREF
  float v90[4]; // [sp+A0h] [-AD0h] BYREF
  idFireParms v91; // [sp+B0h] [-AC0h] BYREF
  idFinishFireResults v92; // [sp+150h] [-A20h] BYREF
  idTestFireResults v93; // [sp+1A0h] [-9D0h] BYREF

  RD_EventBegin(name: "idProjectile_Grenade::DisperseSubmunitions");
  LODWORD(v3) = "idProjectile_Grenade::DisperseSubmunitions";
  HIDWORD(v3) = 2;
  idPLogScope::idPLogScope(this: &v89, pl: &::pLog, gMask: v3, label: v4);
  if ( (-this->subMunitionProjectileList.num & ~this->subMunitionProjectileList.num) < 0 )
  {
    Physics = idEntity::GetPhysics(this);
    v11 = (float)(this->lastCollisionNormal.x * (float)8.0);
    v12 = (float)(this->lastCollisionNormal.z * (float)8.0);
    v13 = (float)(this->lastCollisionNormal.y * (float)8.0);
    v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v15 = (float)(v14[2] + (float)v12);
    v16 = (float)(v14[1] + (float)v13);
    v17 = (float)(*v14 + (float)v11);
    v18 = idEntity::GetPhysics(this);
    v18->GetLinearVelocity(this: (idPhysics *)v90, result: (idVec3 *)v18, a3: 0);
    y = this->lastCollisionNormal.y;
    z = this->lastCollisionNormal.z;
    numBounces = this->numBounces;
    v81.mat[0].x = this->lastCollisionNormal.x;
    v81.mat[0].y = y;
    v81.mat[0].z = z;
    v23 = __fsqrts((float)((float)(v90[0] * v90[0]) + (float)((float)(v90[1] * v90[1]) + (float)(v90[2] * v90[2]))));
    if ( numBounces == 0
      || ((LODWORD(this->lastCollisionNormal.z)
         | LODWORD(this->lastCollisionNormal.x)
         | LODWORD(this->lastCollisionNormal.y))
        & 0x7FFFFFFF) == 0 )
    {
      v24 = idEntity::GetPhysics(this);
      v25 = (float *)v24->GetLinearVelocity(this: (idPhysics *)&v81.mat[2].z, result: (idVec3 *)v24, a3: 0);
      v26 = *v25;
      v81.mat[0].x = *v25;
      v27 = v25[1];
      v28 = (float)(v25[1] * v25[1]);
      v81.mat[0].y = v25[1];
      v29 = v25[2];
      _FP7 = (float)((float)((float)((float)v26 * (float)v26) + (float)((float)(v25[2] * v25[2]) + (float)v28))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      v31 = (float)((float)((float)((float)v26 * (float)v26) + (float)((float)(v25[2] * v25[2]) + (float)v28))
                  * (float)0.5);
      __asm { fsel      f5, f7, f8, f12 }
      v33 = __frsqrte(_FP5);
      v34 = (float)((float)-(float)((float)((float)((float)v33
                                                  * (float)((float)((float)((float)v26 * (float)v26)
                                                                  + (float)((float)(v25[2] * v25[2]) + (float)v28))
                                                          * (float)0.5))
                                          * (float)v33)
                                  - (float)1.5)
                  * (float)v33);
      v35 = (float)((float)((float)-(float)((float)((float)((float)v33
                                                          * (float)((float)((float)((float)v26 * (float)v26)
                                                                          + (float)((float)(v25[2] * v25[2]) + (float)v28))
                                                                  * (float)0.5))
                                                  * (float)v33)
                                          - (float)1.5)
                          * (float)v33)
                  * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)(v25[2] * v25[2]) + (float)v28))
                          * (float)0.5));
      v36 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)v35 * (float)v34) - (float)1.5)
                                                  * (float)v34)
                                          * (float)v31)
                                  * (float)((float)-(float)((float)((float)v35 * (float)v34) - (float)1.5) * (float)v34))
                          - (float)1.5);
      v81.mat[0].x = (float)((float)v36
                           * (float)((float)-(float)((float)((float)v35 * (float)v34) - (float)1.5) * (float)v34))
                   * (float)v26;
      v81.mat[0].y = (float)v27
                   * (float)((float)v36
                           * (float)((float)-(float)((float)((float)v35 * (float)v34) - (float)1.5) * (float)v34));
      v81.mat[0].z = (float)v29
                   * (float)((float)v36
                           * (float)((float)-(float)((float)((float)v35 * (float)v34) - (float)1.5) * (float)v34));
    }
    numSubMunitions = this->numSubMunitions;
    v38 = 0;
    if ( numSubMunitions > 0 )
    {
      v39 = *(float *)&v83;
      v40 = v82;
      v41 = v81.mat[2].z;
      do
      {
        if ( this->pairedSubMunitionVels && (v38 & 1) != 0 )
        {
          *(float *)&v83 = (float)(v81.mat[0].z * (float)2.0) - (float)v39;
          v82 = (float)(v81.mat[0].y * (float)2.0) - (float)v40;
          v81.mat[2].z = (float)(v81.mat[0].x * (float)2.0) - (float)v41;
          idMat3::OrthoNormalizeSelf(this: (idMat3 *)&v81.mat[2].z);
        }
        else
        {
          idProjectile::RandomVectorInCone(
            normal: &v81,
            maxDegrees: this->subMunitionMaxAngle,
            result: v19,
            a4: (idMat3 *)&v81.mat[2].z);
        }
        idFireParms::idFireParms(this: &v91);
        Attacker = idProjectile::GetAttacker(this);
        if ( Attacker != nullptr )
          v91.attacker.spawnId = Attacker->spawnId;
        else
          v91.attacker.spawnId = 0;
        weaponStatsTag = this->weaponStatsTag;
        v41 = v81.mat[2].z;
        randomSubMunitions = this->randomSubMunitions;
        v40 = v82;
        v39 = *(float *)&v83;
        v45 = clientGame;
        v91.target.spawnId = 0;
        v91.wepDef = nullptr;
        v91.tag = weaponStatsTag;
        v91.start.x = v17;
        v91.start.y = v16;
        v91.start.z = v15;
        v91.fireAxis.mat[0].x = v81.mat[2].z;
        v91.fireAxis.mat[0].y = v82;
        v91.fireAxis.mat[0].z = *(float *)&v83;
        v91.fireAxis.mat[1].x = *((float *)&v83 + 1);
        v91.fireAxis.mat[1].y = v84;
        v91.fireAxis.mat[1].z = v85;
        v91.fireAxis.mat[2].x = v86;
        v91.fireAxis.mat[2].y = v87;
        v91.fireAxis.mat[2].z = v88;
        if ( randomSubMunitions )
        {
          num = this->subMunitionProjectileList.num;
          if ( num != 0 )
          {
            seed = clientGame->random.seed;
            __twllei(num, 0);
            clientGame->random.seed = 1664525 * seed + 1013904223;
            v49 = ((1664525 * seed + 1013904223) >> 10) & 0x7FFF;
            __twlgei(num & ~(__ROL4__(v49, 1) - 1), 0xFFFFFFFF);
            v45 = clientGame;
            v47 = this->subMunitionProjectileList.list[v49 % num];
          }
          else
          {
            v47 = *this->subMunitionProjectileList.list;
          }
          v91.projDef = v47;
        }
        else
        {
          v50 = this->subMunitionProjectileList.num;
          list = this->subMunitionProjectileList.list;
          __twllei(v50, 0);
          __twlgei(v50 & ~(__ROL4__(v38, 1) - 1), 0xFFFFFFFF);
          v91.projDef = list[v38 % v50];
        }
        memset(&v93, 0, sizeof(v93));
        v52 = &v92;
        v92.numProjectiles = 0;
        for ( i = 16; i != 0; --i )
        {
          v52 = (idFinishFireResults *)((char *)v52 + 4);
          v52->numProjectiles = 0;
        }
        idClientGame::TestFire(this: v45, fp: &v91, tfr: &v93);
        idGameLocal::FinishFire(this: gameLocal, fp: &v91, tfr: &v93, ffr: &v92);
        if ( v91.projDef->notHitscanInfo.grenadeInfo.inheritParentSpeed )
        {
          v54 = 0;
          if ( v92.numProjectiles > 0 )
          {
            projectiles = v92.projectiles;
            do
            {
              v56 = projectiles->spawnId & 0x3FFF;
              if ( projectiles->spawnId == 0
                || !idClientGame::IsPresentableIndexValid(this: clientGame, index: projectiles->spawnId & 0x3FFF)
                || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v56))->spawnId != projectiles->spawnId )
              {
                PresentableByIndex = nullptr;
              }
              (*(void (__fastcall **)(float *))(*(_DWORD *)LODWORD(PresentableByIndex[1].axes[0].mat[1].x) + 88))(a1: &v81.mat[1].y);
              v58 = projectiles->spawnId & 0x3FFF;
              v59 = projectiles->spawnId == 0;
              _FP7 = (float)((float)((float)(v81.mat[1].y * v81.mat[1].y)
                                   + (float)((float)(v81.mat[2].x * v81.mat[2].x) + (float)(v81.mat[1].z * v81.mat[1].z)))
                           - idMath::FLT_SMALLEST_NON_DENORMAL);
              __asm { fsel      f5, f7, f8, f13 }
              v62 = __frsqrte(_FP5);
              v63 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v62
                                                                                                  * (float)((float)((float)(v81.mat[1].y * v81.mat[1].y) + (float)((float)(v81.mat[2].x * v81.mat[2].x) + (float)(v81.mat[1].z * v81.mat[1].z))) * (float)0.5))
                                                                                          * (float)v62)
                                                                                  - (float)1.5)
                                                                  * (float)v62)
                                                          * (float)((float)((float)(v81.mat[1].y * v81.mat[1].y)
                                                                          + (float)((float)(v81.mat[2].x * v81.mat[2].x)
                                                                                  + (float)(v81.mat[1].z * v81.mat[1].z)))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v62
                                                                                          * (float)((float)((float)(v81.mat[1].y * v81.mat[1].y) + (float)((float)(v81.mat[2].x * v81.mat[2].x) + (float)(v81.mat[1].z * v81.mat[1].z)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v62)
                                                                          - (float)1.5)
                                                          * (float)v62))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v62
                                                                  * (float)((float)((float)(v81.mat[1].y * v81.mat[1].y)
                                                                                  + (float)((float)(v81.mat[2].x
                                                                                                  * v81.mat[2].x)
                                                                                          + (float)(v81.mat[1].z
                                                                                                  * v81.mat[1].z)))
                                                                          * (float)0.5))
                                                          * (float)v62)
                                                  - (float)1.5)
                                  * (float)v62));
              v64 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v62 * (float)((float)((float)(v81.mat[1].y * v81.mat[1].y) + (float)((float)(v81.mat[2].x * v81.mat[2].x) + (float)(v81.mat[1].z * v81.mat[1].z))) * (float)0.5)) * (float)v62) - (float)1.5)
                                                                                                  * (float)v62)
                                                                                          * (float)((float)((float)(v81.mat[1].y * v81.mat[1].y) + (float)((float)(v81.mat[2].x * v81.mat[2].x) + (float)(v81.mat[1].z * v81.mat[1].z)))
                                                                                                  * (float)0.5))
                                                                                  * (float)((float)-(float)((float)((float)((float)v62 * (float)((float)((float)(v81.mat[1].y * v81.mat[1].y) + (float)((float)(v81.mat[2].x * v81.mat[2].x) + (float)(v81.mat[1].z * v81.mat[1].z))) * (float)0.5)) * (float)v62) - (float)1.5)
                                                                                          * (float)v62))
                                                                          - (float)1.5)
                                                          * (float)((float)-(float)((float)((float)((float)v62
                                                                                                  * (float)((float)((float)(v81.mat[1].y * v81.mat[1].y) + (float)((float)(v81.mat[2].x * v81.mat[2].x) + (float)(v81.mat[1].z * v81.mat[1].z))) * (float)0.5))
                                                                                          * (float)v62)
                                                                                  - (float)1.5)
                                                                  * (float)v62))
                                                  * (float)((float)((float)(v81.mat[1].y * v81.mat[1].y)
                                                                  + (float)((float)(v81.mat[2].x * v81.mat[2].x)
                                                                          + (float)(v81.mat[1].z * v81.mat[1].z)))
                                                          * (float)0.5))
                                          * (float)v63)
                                  - (float)1.5);
              v65 = (float)(v81.mat[1].z
                          * (float)((float)v64
                                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v62 * (float)((float)((float)(v81.mat[1].y * v81.mat[1].y) + (float)((float)(v81.mat[2].x * v81.mat[2].x) + (float)(v81.mat[1].z * v81.mat[1].z))) * (float)0.5)) * (float)v62)
                                                                                                  - (float)1.5)
                                                                                  * (float)v62)
                                                                          * (float)((float)((float)(v81.mat[1].y
                                                                                                  * v81.mat[1].y)
                                                                                          + (float)((float)(v81.mat[2].x * v81.mat[2].x)
                                                                                                  + (float)(v81.mat[1].z * v81.mat[1].z)))
                                                                                  * (float)0.5))
                                                                  * (float)((float)-(float)((float)((float)((float)v62 * (float)((float)((float)(v81.mat[1].y * v81.mat[1].y) + (float)((float)(v81.mat[2].x * v81.mat[2].x) + (float)(v81.mat[1].z * v81.mat[1].z))) * (float)0.5))
                                                                                                  * (float)v62)
                                                                                          - (float)1.5)
                                                                          * (float)v62))
                                                          - (float)1.5)
                                          * (float)((float)-(float)((float)((float)((float)v62
                                                                                  * (float)((float)((float)(v81.mat[1].y * v81.mat[1].y)
                                                                                                  + (float)((float)(v81.mat[2].x * v81.mat[2].x) + (float)(v81.mat[1].z * v81.mat[1].z)))
                                                                                          * (float)0.5))
                                                                          * (float)v62)
                                                                  - (float)1.5)
                                                  * (float)v62))));
              v66 = (float)(v81.mat[2].x
                          * (float)((float)v64
                                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v62 * (float)((float)((float)(v81.mat[1].y * v81.mat[1].y) + (float)((float)(v81.mat[2].x * v81.mat[2].x) + (float)(v81.mat[1].z * v81.mat[1].z))) * (float)0.5)) * (float)v62)
                                                                                                  - (float)1.5)
                                                                                  * (float)v62)
                                                                          * (float)((float)((float)(v81.mat[1].y
                                                                                                  * v81.mat[1].y)
                                                                                          + (float)((float)(v81.mat[2].x * v81.mat[2].x)
                                                                                                  + (float)(v81.mat[1].z * v81.mat[1].z)))
                                                                                  * (float)0.5))
                                                                  * (float)((float)-(float)((float)((float)((float)v62 * (float)((float)((float)(v81.mat[1].y * v81.mat[1].y) + (float)((float)(v81.mat[2].x * v81.mat[2].x) + (float)(v81.mat[1].z * v81.mat[1].z))) * (float)0.5))
                                                                                                  * (float)v62)
                                                                                          - (float)1.5)
                                                                          * (float)v62))
                                                          - (float)1.5)
                                          * (float)((float)-(float)((float)((float)((float)v62
                                                                                  * (float)((float)((float)(v81.mat[1].y * v81.mat[1].y)
                                                                                                  + (float)((float)(v81.mat[2].x * v81.mat[2].x) + (float)(v81.mat[1].z * v81.mat[1].z)))
                                                                                          * (float)0.5))
                                                                          * (float)v62)
                                                                  - (float)1.5)
                                                  * (float)v62))));
              v81.mat[1].y = (float)(v81.mat[1].y
                                   * (float)((float)v64
                                           * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v62 * (float)((float)((float)(v81.mat[1].y * v81.mat[1].y) + (float)((float)(v81.mat[2].x * v81.mat[2].x) + (float)(v81.mat[1].z * v81.mat[1].z))) * (float)0.5)) * (float)v62) - (float)1.5)
                                                                                           * (float)v62)
                                                                                   * (float)((float)((float)(v81.mat[1].y * v81.mat[1].y) + (float)((float)(v81.mat[2].x * v81.mat[2].x) + (float)(v81.mat[1].z * v81.mat[1].z)))
                                                                                           * (float)0.5))
                                                                           * (float)((float)-(float)((float)((float)((float)v62 * (float)((float)((float)(v81.mat[1].y * v81.mat[1].y) + (float)((float)(v81.mat[2].x * v81.mat[2].x) + (float)(v81.mat[1].z * v81.mat[1].z))) * (float)0.5)) * (float)v62) - (float)1.5)
                                                                                   * (float)v62))
                                                                   - (float)1.5)
                                                   * (float)((float)-(float)((float)((float)((float)v62
                                                                                           * (float)((float)((float)(v81.mat[1].y * v81.mat[1].y) + (float)((float)(v81.mat[2].x * v81.mat[2].x) + (float)(v81.mat[1].z * v81.mat[1].z))) * (float)0.5))
                                                                                   * (float)v62)
                                                                           - (float)1.5)
                                                           * (float)v62))))
                           * (float)v23;
              v81.mat[1].z = (float)v65 * (float)v23;
              v81.mat[2].x = (float)v66 * (float)v23;
              if ( v59
                || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v58)
                || (v67 = idClientGame::GetPresentableByIndex(this: clientGame, index: v58))->spawnId != projectiles->spawnId )
              {
                v67 = nullptr;
              }
              (*(void (__fastcall **)(_DWORD, float *, _DWORD))(*(_DWORD *)LODWORD(v67[1].axes[0].mat[1].x) + 80))(
                a1: LODWORD(v67[1].axes[0].mat[1].x),
                a2: &v81.mat[1].y,
                a3: 0);
              ++v54;
              ++projectiles;
            }
            while ( v54 < v92.numProjectiles );
          }
        }
        if ( v91.targetList.listStatic == 0 || v91.targetList.listStatic == 2 )
        {
          v19 = (idMat3 *)v91.targetList.list;
          if ( v91.targetList.list != nullptr )
            idMem::Free(this: &mem, ptr: v91.targetList.list, align: ALIGN_16);
          v91.targetList.list = nullptr;
          v91.targetList.size = 0;
        }
        numSubMunitions = this->numSubMunitions;
        ++v38;
        v91.targetList.num = 0;
      }
      while ( v38 < numSubMunitions );
    }
    idGameLocal::WeaponFiredDone(
      this: gameLocal,
      tag: *(weaponStatsTag_t **)&this->weaponStatsTag,
      carryoverCount: numSubMunitions + 1);
    if ( v89.logIndex >= 0 )
    {
      pLog = v89.pLog;
      v69 = &v89.pLog->logEntries.list[v89.logIndex];
      v70 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v69->totalTicks;
      HIDWORD(totalTicks) = v69->parent;
      LODWORD(v72) = v70 - totalTicks;
      v69->totalTicks = v72;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
  }
  else
  {
    HIBYTE(v81.mat[2].z) = 105;
    v82 = 0.0;
    DWORD1(v5) = LODWORD(v81.mat[2].z);
    *((_QWORD *)&v5 + 1) = v83;
    v6 = __ROL4__(LODWORD(v84), 32);
    idEventReceiver::PostEventMS(
      this,
      ev: &EV_StopFX,
      arg1: *(__int64 *)((char *)&v5 + 4),
      a4: *(__int64 *)((char *)&v5 - 4),
      a5: 105,
      a6: v73,
      a7: v74,
      a8: v75,
      a9: v76,
      a10: v77,
      a11: v78,
      a12: v79,
      a13: v80);
    LODWORD(v7) = &s_memTag[218];
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 3500, a4: v9, a5: v8, a6: v7);
    idPLogScope::~idPLogScope(this: &v89);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$504132_0
// EA  : 0x82ED80B4
// RVA : 0x00ED80B4
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_504132_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 2928 + 2724));
}


// ========================================================================
// __unwind$504133
// EA  : 0x82ED80DC
// RVA : 0x00ED80DC
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_504133()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 2928 + 152));
}


// ========================================================================
// __unwind$504134
// EA  : 0x82ED8104
// RVA : 0x00ED8104
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_504134()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 2928 + 176));
}


// ========================================================================
// ??1idProjectile@@UAA@XZ
// EA  : 0x82ED8138
// RVA : 0x00ED8138
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile::~idProjectile(idProjectile *this)
{
  idHandle<int,enum invalidAIEvent_t,-1> *p_aiEventHandle; // r29
  idPresentable *presentable; // r4
  idProjectile::simulatedProjectile_t *v4; // r11
  int i; // ctr

  this->__vftable = (idProjectile_vtbl *)&idProjectile::`vftable';
  p_aiEventHandle = &this->aiEventHandle;
  if ( this->aiEventHandle.value != -1 )
  {
    idAIEventManager::RemoveEvent(this: &gameLocal->aiEventManager, handle: &this->aiEventHandle);
    p_aiEventHandle->value = -1;
  }
  idEntity::RestorePhysics(this, phys: nullptr);
  idProjectile::Detach(this);
  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    idInfluenceTrailManager::FreeInfluenceTrail(this: &clientGame->influenceTrailManager, presentable);
    this->startInfluenceTrail = -1;
  }
  v4 = idProjectile::projectilesToSimulate;
  for ( i = 16; i != 0; --i )
  {
    if ( v4->projectile == this )
      v4->projectile = nullptr;
    ++v4;
  }
  idAnimator_Channel::~idAnimator_Channel(this: &this->propAnimator);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$504600
// EA  : 0x82ED820C
// RVA : 0x00ED820C
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_504600()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$504601
// EA  : 0x82ED8234
// RVA : 0x00ED8234
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_504601()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 128 + 148) + 5204));
}


// ========================================================================
// ?Think@idProjectile@@UAAXXZ
// EA  : 0x82ED8268
// RVA : 0x00ED8268
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile::Think(idProjectile *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPresentable *presentable; // r3
  int v5; // r3
  idPhysics *Physics; // r3
  const idVec3 *v7; // r3
  float y; // r7
  float z; // r6
  idPhysics *v10; // r3
  idRenderWorld_vtbl *v11; // r29
  int v12; // r3
  idPhysics *v13; // r29
  idPhysics *v14; // r25
  const idDeclDamage *damageDecl; // r24
  idGameLocal *SpawnId; // r23
  const idEntity *AttackerEntity; // r3
  idGameLocal *v18; // r9
  const idDeclDamage *v19; // r27
  idPhysics *v20; // r3
  const idSpawnId *v21; // r29
  const idBounds *(__fastcall *GetBounds)(idPhysics *, int); // ctr
  idBounds *v23; // r3
  double Radius; // fp29
  const idVec3 *v25; // r25
  idWeaponTraceManager *WeaponTraceMgr; // r3
  const idSpawnId *v27; // r5
  __int64 v28; // r10
  __int64 v29; // r8
  int v30; // r6
  idPresentable *v31; // r11
  idPresentable *v32; // r11
  __int128 v33; // r9
  double v34; // fp0
  idPresentable *v35; // r11
  double v36; // fp29
  idPresentable *v37; // r3
  idPresentable *v38; // r3
  int v39; // r3
  __int64 v40; // r7
  double v41; // fp29
  double v42; // fp28
  double v43; // fp27
  idPhysics *v44; // r27
  int GameMs; // r29
  float *v46; // r3
  idPresentable *v47; // r11
  double v48; // fp8
  double v49; // fp6
  int v50; // r6
  const idVec3 *v51; // r5
  const idHandle<int,enum invalidInfluenceTrail_t,-1> *p_influenceHandle; // r4
  idInfluenceTrailManager *p_influenceTrailManager; // r3
  idPhysics *v54; // r29
  int v55; // r27
  idPresentable *v56; // r28
  idPhysics *v57; // r3
  idInfluenceTrailManager *v58; // r29
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  idPresentable *v60; // r3
  idPresentable *v61; // r3
  idPresentableProjectile *v62; // r3
  idPresentable *v63; // r3
  int v64; // r3
  idPresentable *v65; // r3
  float *v66; // r3
  float *v67; // r5
  double v68; // fp9
  double v69; // fp8
  double v70; // fp7
  idRenderWorld *renderWorld; // r3
  void (__fastcall *DebugCircle)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const float, const int, const int, const bool); // r7
  int v73; // [sp+50h] [-100h] BYREF
  _DWORD v74[3]; // [sp+54h] [-FCh] BYREF
  _QWORD v75[2]; // [sp+60h] [-F0h] BYREF
  idPLogScope v76; // [sp+70h] [-E0h] BYREF
  float v77[4]; // [sp+78h] [-D8h] BYREF
  float v78[4]; // [sp+88h] [-C8h] BYREF
  float v79[4]; // [sp+98h] [-B8h] BYREF
  float v80[6]; // [sp+A8h] [-A8h] BYREF
  float v81[16]; // [sp+C0h] [-90h] BYREF

  RD_EventBegin(name: "idProjectile::Think");
  LODWORD(v2) = "idProjectile::Think";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v76, pl: &pLog, gMask: v2, label: v3);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetProjectileInterface(this: presentable);
  else
    v5 = 0;
  if ( (unsigned int)(*(_DWORD *)(v5 + 1252) - 1) <= 4 )
  {
    if ( *(_DWORD *)(v5 + 1252) == 2 )
    {
      idEntity::RunPhysics(this);
      goto LABEL_38;
    }
    if ( *(_DWORD *)(v5 + 1252) != 3 )
    {
      if ( *(_DWORD *)(v5 + 1252) != 4 )
      {
        if ( *(_DWORD *)(v5 + 1252) == 1 )
        {
          Physics = idEntity::GetPhysics(this);
          v7 = Physics->GetOrigin(this: Physics, a2: 0);
          y = v7->y;
          z = v7->z;
          *(float *)v75 = v7->x;
          *((float *)v75 + 1) = y;
          *(float *)&v75[1] = z;
          idEntity::RunPhysics(this);
          if ( g_debugWeapon.valueInteger != 0 )
          {
            v10 = idEntity::GetPhysics(this);
            v81[0] = 0.0;
            v81[1] = 1.0;
            v81[2] = 0.0;
            v81[3] = 1.0;
            v11 = clientGame->renderWorld->__vftable;
            v12 = (int)v10->GetOrigin(this: v10, a2: 0);
            v11->DebugLine(
              this: clientGame->renderWorld,
              a2: (const idVec4 *)v81,
              a3: (const idVec3 *)v75,
              a4: (const idVec3 *)v12,
              a5: 10000,
              a6: true);
          }
          if ( this->touchTriggers && this->collisionCount <= 0 )
            idEntity::TouchTriggers(this);
          v13 = idEntity::GetPhysics(this);
          v14 = idEntity::GetPhysics(this);
          damageDecl = this->projectileDecl->damageDecl;
          SpawnId = idGameLocal::GetSpawnId(this: (idGameLocal *)&v73, result: (idSpawnId *)gameLocal, ent: this);
          AttackerEntity = idProjectile::GetAttackerEntity(this);
          v18 = idGameLocal::GetSpawnId(this: (idGameLocal *)v74, result: (idSpawnId *)gameLocal, ent: AttackerEntity);
          v19 = (const idDeclDamage *)SpawnId->__vftable;
          v20 = v13;
          GetBounds = v13->GetBounds;
          v21 = (const idSpawnId *)v18->__vftable;
          v23 = (idBounds *)GetBounds(this: v20, a2: -1);
          Radius = idBounds::GetRadius(this: v23);
          v25 = v14->GetOrigin(this: v14, a2: 0);
          WeaponTraceMgr = idClientGame::GetWeaponTraceMgr(this: clientGame);
          idWeaponTraceManager::AddProjectile(
            this: WeaponTraceMgr,
            origin: v25,
            radius: Radius,
            attacker: v27,
            projectile: v21,
            damage: v19,
            a7: damageDecl);
        }
        else
        {
          idEntity::UpdateVisuals(this);
        }
        goto LABEL_38;
      }
      if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) <= this->fadeEndTime )
      {
        LODWORD(v33) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        DWORD2(v33) = this->fadeStartTime;
        DWORD1(v33) = this->fadeEndTime;
        v75[0] = v33;
        *(_QWORD *)&v74[1] = *(_QWORD *)&v33;
        v34 = (float)((float)((float)(__int64)v33 - (float)*(__int64 *)((char *)&v33 + 4))
                    / (float)((float)*(__int64 *)&v33 - (float)*(__int64 *)((char *)&v33 + 4)));
        if ( v34 >= 0.0 )
        {
          if ( v34 > 1.0 )
            v34 = 1.0;
        }
        else
        {
          v34 = 0.0;
        }
        v35 = this->presentable;
        v36 = (float)((float)1.0 - (float)v34);
        if ( v35 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v35 = this->presentable;
        }
        if ( v35->model != nullptr )
        {
          if ( v35 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v35 = this->presentable;
          }
          idPresentable::SetParm(this: v35, parm: rp->coverage, scalar: v36);
          v32 = this->presentable;
          if ( v32 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v32 = this->presentable;
          }
          goto LABEL_24;
        }
      }
      else
      {
        idProjectile::SetState(this, state: EXPLODED);
        idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 2500, a4: v30, a5: v29, a6: v28);
        v31 = this->presentable;
        if ( v31 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v31 = this->presentable;
        }
        if ( v31->model != nullptr )
        {
          if ( v31 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v31 = this->presentable;
          }
          idPresentable::SetParm(this: v31, parm: rp->coverage, scalar: 0.0);
          v32 = this->presentable;
          if ( v32 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v32 = this->presentable;
          }
LABEL_24:
          v32->Present(this: v32);
        }
      }
    }
  }
LABEL_38:
  v37 = this->presentable;
  if ( v37 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v37 = this->presentable;
  }
  v37->UpdateFX_3(this: v37, a2: 1.0, a3: 0.0);
  this->UpdateElectricBoltEffect(this);
  v38 = this->presentable;
  if ( v38 != nullptr )
    v39 = (int)v38->GetProjectileInterface(this: v38);
  else
    v39 = 0;
  if ( *(_DWORD *)(v39 + 1252) == 5 )
  {
    LODWORD(v40) = idClientGame::GetPlayerGameTime(this: clientGame) - this->startInfluenceTrail;
    v75[0] = v40;
    v41 = (float)((float)v40 * vec3_up.z);
    v42 = (float)((float)v40 * vec3_up.y);
    v43 = (float)((float)v40 * vec3_up.x);
    v44 = idEntity::GetPhysics(this);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v46 = (float *)v44->GetOrigin(this: v44, a2: 0);
    v47 = this->presentable;
    v48 = (float)(v46[2] + (float)v41);
    v49 = (float)(v46[1] + (float)v42);
    v77[0] = *v46 + (float)v43;
    v77[2] = v48;
    v77[1] = v49;
    if ( v47 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v47 = this->presentable;
    }
    v50 = GameMs;
    v51 = (const idVec3 *)v77;
    p_influenceHandle = &v47->influenceHandle;
    p_influenceTrailManager = &clientGame->influenceTrailManager;
  }
  else
  {
    v54 = idEntity::GetPhysics(this);
    v55 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    if ( this->presentable == nullptr )
      idEntity::InitPresentableInternal(this);
    v56 = this->presentable;
    v57 = v54;
    GetOrigin = v54->GetOrigin;
    v58 = &clientGame->influenceTrailManager;
    v51 = GetOrigin(this: v57, a2: 0);
    p_influenceHandle = &v56->influenceHandle;
    p_influenceTrailManager = v58;
    v50 = v55;
  }
  idInfluenceTrailManager::UpdatePosition(
    this: p_influenceTrailManager,
    trail: p_influenceHandle,
    position: v51,
    time: v50);
  idProjectile::UpdateAnimation(this);
  v60 = this->presentable;
  if ( v60 != nullptr && v60->GetProjectileInterface(this: v60) != nullptr )
  {
    v61 = this->presentable;
    v62 = v61 != nullptr ? v61->GetProjectileInterface(this: v61) : nullptr;
    idPresentableProjectile::DecayOriginAndAxisSmoothing(this: v62);
    if ( g_projectileDebug.valueInteger != 0 )
    {
      v63 = this->presentable;
      v78[0] = 0.0;
      v78[1] = 0.0;
      v78[2] = 1.0;
      if ( v63 != nullptr )
        v64 = (int)v63->GetProjectileInterface(this: v63);
      else
        v64 = 0;
      ((void (__fastcall *)(idRenderWorld *, idColor *, int, float *, double))clientGame->renderWorld->DebugCircle)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorYellow,
        a3: v64 + 120,
        a4: v78,
        a5: 5.0);
      v65 = this->presentable;
      v79[0] = 0.0;
      v79[1] = 0.0;
      v79[2] = 1.0;
      if ( v65 != nullptr )
        v66 = (float *)v65->GetProjectileInterface(this: v65);
      else
        v66 = nullptr;
      v67 = v66 + 30;
      v68 = v66[30];
      v69 = (float)(v66[331] + v66[31]);
      v70 = v66[330];
      v80[2] = v66[332] + v66[32];
      v74[0] = v66 + 330;
      v80[0] = (float)v68 + (float)v70;
      v80[1] = v69;
      renderWorld = clientGame->renderWorld;
      DebugCircle = renderWorld->DebugCircle;
      v74[0] = v67;
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))DebugCircle)(
        a1: renderWorld,
        a2: &idColor::colorPurple,
        a3: v80,
        a4: v79,
        a5: 5.0);
    }
  }
  idPLogScope::~idPLogScope(this: &v76);
  RD_EventEnd();
}


// ========================================================================
// __unwind$504678
// EA  : 0x82ED89D4
// RVA : 0x00ED89D4
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_504678()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 336 + 208));
}


// ========================================================================
// __unwind$504679
// EA  : 0x82ED89FC
// RVA : 0x00ED89FC
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_504679()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 336 + 112));
}


// ========================================================================
// ??0idProjectile_DragonBreath@@QAA@XZ
// EA  : 0x82ED8A30
// RVA : 0x00ED8A30
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

idProjectile_DragonBreath *__fastcall idProjectile_DragonBreath::idProjectile_DragonBreath(
        idProjectile_DragonBreath *this)
{
  idProjectile::idProjectile(this);
  this->__vftable = (idProjectile_DragonBreath_vtbl *)&idProjectile_DragonBreath::`vftable';
  idPhysics_RigidBody::idPhysics_RigidBody(this: &this->physicsObj);
  this->explosionTime = 200;
  return this;
}


// ========================================================================
// __unwind$505046
// EA  : 0x82ED8A8C
// RVA : 0x00ED8A8C
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_505046()
{
  int v0; // r12

  idProjectile::~idProjectile(this: *(idProjectile **)(v0 - 112 + 132));
}


// ========================================================================
// ?Think@idProjectile_DragonBreath@@MAAXXZ
// EA  : 0x82ED8B30
// RVA : 0x00ED8B30
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_DragonBreath::Think(idProjectile_DragonBreath *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  int v4; // r30
  idProjectile_DragonBreath_vtbl *v5; // r10

  idProjectile::Think(this);
  if ( this->explosionTime > 0 )
  {
    presentable = this->presentable;
    if ( presentable != nullptr )
      v3 = (int)presentable->GetProjectileInterface(this: presentable);
    else
      v3 = 0;
    v4 = *(_DWORD *)(v3 + 1368);
    if ( v4 + this->explosionTime <= idGameTimeManager::GetGameMs(
                                       this: &clientGame->gameTimeManager,
                                       type: GAMETIME_SCALED) )
    {
      v5 = this->__vftable;
      this->surfTypeLastHit = -1;
      v5->Explode(this, a2: nullptr, a3: nullptr);
    }
  }
}


// ========================================================================
// ??0idProjectile_Rocket@@QAA@XZ
// EA  : 0x82ED8BF0
// RVA : 0x00ED8BF0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

idProjectile_Rocket *__fastcall idProjectile_Rocket::idProjectile_Rocket(idProjectile_Rocket *this)
{
  idProjectile::idProjectile(this);
  this->__vftable = (idProjectile_Rocket_vtbl *)&idProjectile_Rocket::`vftable';
  idPhysics_RigidBody::idPhysics_RigidBody(this: &this->physicsObj);
  this->explosionTime = -1;
  this->stuckOnActor.spawnId.value = 0x1FFF;
  this->allowConstraint = true;
  this->randomAngle = 5.0;
  this->attachedToEnt.spawnId.value = 0x1FFF;
  this->startJetSpeed = 2000.0;
  this->constraintName.allocedAndFlag = 20;
  this->constraintName.data = this->constraintName.baseBuffer;
  this->constraintName.len = 0;
  this->constraintName.baseBuffer[0] = 0;
  this->constraintTime = 0;
  this->deferredSurfTrace.index = 0xFFFFD8F000000000uLL;
  this->primNoiseAngleMax = 0.15000001;
  this->isInWater = false;
  this->secNoiseAngleMax = 2.0;
  this->primNoiseAngleMinTime = 500;
  this->primNoiseAngleTarget = 0.0;
  this->primNoiseAngleMaxTime = 1500;
  this->secNoiseAngleTarget = 0.0;
  this->secNoiseAngleMinTime = 500;
  this->secNoiseAngleMaxTime = 1500;
  this->primNoiseAngleTime = -10000;
  this->primNoiseAngleStartTime = -10000;
  this->secNoiseAngleTime = -10000;
  this->secNoiseAngleStartTime = -10000;
  return this;
}


// ========================================================================
// __unwind$505134
// EA  : 0x82ED8D10
// RVA : 0x00ED8D10
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_505134()
{
  int v0; // r12

  idProjectile::~idProjectile(this: *(idProjectile **)(v0 - 112 + 132));
}


// ========================================================================
// ?Think@idProjectile_Rocket@@UAAXXZ
// EA  : 0x82ED8DE8
// RVA : 0x00ED8DE8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Rocket::Think(idProjectile_Rocket *this)
{
  int value; // r6
  idEntity *v3; // r3
  idPresentable *presentable; // r3
  int v5; // r3
  double acceleration; // fp31
  double v7; // fp27
  int GameMs; // r30
  idPresentable *v9; // r3
  __int64 v10; // r6
  double v11; // fp31
  idPhysics *Physics; // r29
  idPhysics *v13; // r3
  int v14; // r9
  idPhysics *v15; // r27
  idEntity *v16; // r3
  idEntity *v17; // r30
  idPresentable *v18; // r3
  double goalSpeed; // fp31
  float *v20; // r3
  double v21; // fp12
  double v22; // fp10
  idEntity_vtbl *v23; // r29
  int v24; // r3
  idPresentable *v25; // r3
  int v26; // r3
  int v27; // r29
  int calcThrustDelay; // r30
  idPhysics *v29; // r3
  double v30; // fp1
  idPresentable *v31; // r3
  double v32; // fp31
  int v33; // r3
  char *v34; // r10
  _DWORD *v35; // r11
  int i; // ctr
  double v37; // fp12
  double v38; // fp11
  unsigned int v39; // r7
  __int64 v40; // r5
  int v41; // r3
  __int128 v42; // r7
  long double v43; // fp2
  long double v44; // fp2
  double primNoiseAngleMax; // fp13
  unsigned int v46; // r7
  __int64 v47; // r5
  double v48; // fp1
  int v49; // r3
  int primNoiseAngleStartTime; // r11
  __int128 v51; // r8
  __int64 v52; // fp11
  long double v53; // fp2
  long double v54; // fp2
  idPhysics *v55; // r3
  int v56; // r9
  idEntity *v57; // r3
  int v58; // r9
  idEntity *v59; // r3
  idEntity *v60; // r3
  int v61; // r9
  idEntity *v62; // r3
  idAI2 *v63; // r3
  idAI2 *v64; // r30
  idPhysics *v65; // r3
  double v66; // fp31
  idMat3 *v67; // r4
  idPhysics *v68; // r3
  idPhysics *v69; // r3
  double v72; // fp3
  double v73; // fp6
  double v74; // fp3
  idPhysics *v75; // r3
  idPhysics *v76; // r3
  int v77; // r30
  idPhysics *v78; // r29
  idPhysics *v79; // r27
  idPhysics *v80; // r25
  int entityNumber; // r24
  double v82; // fp31
  double v83; // fp30
  double v84; // fp29
  float *v85; // r3
  double v86; // fp8
  double v87; // fp6
  idClipModel *v88; // r29
  const idVec3 *v89; // r3
  unsigned __int64 v90; // r6
  idPresentable *v91; // r3
  int v92; // r3
  int v93; // r30
  int v94; // [sp+8h] [-1A8h]
  bool v95; // [sp+Fh] [-1A1h]
  const char *v96; // [sp+10h] [-1A0h]
  int v97; // [sp+14h] [-19Ch]
  int v98; // [sp+18h] [-198h]
  int v99; // [sp+1Ch] [-194h]
  int v100; // [sp+20h] [-190h]
  int v101; // [sp+24h] [-18Ch]
  int v102; // [sp+28h] [-188h]
  int v103; // [sp+2Ch] [-184h]
  int v104; // [sp+30h] [-180h]
  int v105; // [sp+34h] [-17Ch]
  int v106; // [sp+38h] [-178h]
  int v107; // [sp+3Ch] [-174h]
  int v108; // [sp+40h] [-170h]
  int v109; // [sp+44h] [-16Ch]
  int v110; // [sp+48h] [-168h]
  int v111; // [sp+4Ch] [-164h]
  int v112; // [sp+50h] [-160h]
  int v113; // [sp+58h] [-158h]
  int v114; // [sp+60h] [-150h]
  __int64 v115; // [sp+70h] [-140h] BYREF
  float v116; // [sp+78h] [-138h] BYREF
  float v117; // [sp+7Ch] [-134h]
  float v118; // [sp+80h] [-130h]
  idVec3 v119; // [sp+88h] [-128h] BYREF
  idMat3 v120; // [sp+98h] [-118h] BYREF
  float v121; // [sp+BCh] [-F4h]
  float v122; // [sp+C0h] [-F0h]
  float v123[5]; // [sp+C8h] [-E8h] BYREF
  char v124; // [sp+DCh] [-D4h] BYREF
  idMat3 v125; // [sp+E0h] [-D0h] BYREF
  idMat3 v126; // [sp+110h] [-A0h] BYREF

  idProjectile::Think(this);
  value = this->attachedToEnt.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v3) != nullptr )
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    v5 = (int)presentable->GetProjectileRocketInterface(this: presentable);
    acceleration = this->acceleration;
    v7 = *(float *)(v5 + 2036);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    LODWORD(v10) = GameMs
                 - idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v9 = this->presentable;
    v115 = v10;
    v11 = (float)((float)((float)((float)v10 * (float)0.001) * (float)acceleration) + (float)v7);
    if ( v9 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v9 = this->presentable;
    }
    v9->GetProjectileRocketInterface(this: v9)->goalSpeed = v11;
    Physics = idEntity::GetPhysics(this);
    v13 = idEntity::GetPhysics(this);
    v14 = this->attachedToEnt.spawnId.value;
    v15 = v13;
    if ( gameLocal->spawnIds.ptr[v14 & 0x1FFF] == v14 >> 13 && (v16 = gameLocal->entities.ptr[v14 & 0x1FFF]) != nullptr )
      v17 = idEntity::CastTo(c: v16);
    else
      v17 = nullptr;
    v18 = this->presentable;
    if ( v18 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v18 = this->presentable;
    }
    goalSpeed = v18->GetProjectileRocketInterface(this: v18)->goalSpeed;
    v20 = (float *)Physics->GetAxis(this: Physics, a2: 0);
    v21 = (float)(v20[2] * (float)goalSpeed);
    v22 = (float)(v20[1] * (float)goalSpeed);
    v123[0] = *v20 * (float)goalSpeed;
    v123[2] = v21;
    v123[1] = v22;
    v23 = v17->__vftable;
    v24 = (int)v15->GetOrigin(this: v15, a2: 0);
    v23->ApplyImpulseFromEntity(this: v17, a2: this, a3: 0, a4: (const idVec3 *)v24, a5: (const idVec3 *)v123);
  }
  else
  {
    v25 = this->presentable;
    if ( v25 != nullptr )
      v26 = (int)v25->GetProjectileInterface(this: v25);
    else
      v26 = 0;
    v27 = *(_DWORD *)(v26 + 1368);
    if ( this->presentable == nullptr )
      idEntity::InitPresentableInternal(this);
    calcThrustDelay = this->presentable->GetProjectileRocketInterface(this: this->presentable)->calcThrustDelay;
    if ( calcThrustDelay + v27 <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
    {
      v29 = idEntity::GetPhysics(this);
      v29->GetLinearVelocity(this: (idPhysics *)&v120.mat[1].y, result: (idVec3 *)v29, a3: 0);
      v30 = idVec3::NormalizeFast(this: (idVec3 *)&v120.mat[1].y);
      v31 = this->presentable;
      v32 = v30;
      if ( v31 != nullptr )
        v33 = (int)v31->GetProjectileInterface(this: v31);
      else
        v33 = 0;
      v34 = &v124;
      v35 = (_DWORD *)(v33 + 1368);
      for ( i = 9; i != 0; --i )
      {
        ++v35;
        v34 += 4;
        *(_DWORD *)v34 = *v35;
      }
      if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->secNoiseAngleTime + this->secNoiseAngleStartTime )
      {
        this->secNoiseAngleTime = idRandom2::RandomInt(
                                    this: &clientGame->random,
                                    min: this->secNoiseAngleMinTime,
                                    max: this->secNoiseAngleMaxTime);
        this->secNoiseAngleStartTime = idGameTimeManager::GetGameMs(
                                         this: &clientGame->gameTimeManager,
                                         type: GAMETIME_SCALED);
        v37 = -this->secNoiseAngleMax;
        v38 = (float)(this->secNoiseAngleMax - (float)v37);
        v39 = 1664525 * clientGame->random.seed + 1013904223;
        clientGame->random.seed = v39;
        LODWORD(v40) = (v39 >> 10) & 0x7FFF;
        v115 = v40;
        this->secNoiseAngleTarget = (float)((float)((float)v40 * (float)v38) * (float)0.000030518509) + (float)v37;
      }
      if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < this->secNoiseAngleTime + this->secNoiseAngleStartTime )
      {
        v41 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        LODWORD(v42) = this->secNoiseAngleTime;
        DWORD2(v42) = v41 - this->secNoiseAngleStartTime;
        v115 = *(_QWORD *)((char *)&v42 + 4);
        *(double *)&v43 = (float)((float)((float)((float)*(__int64 *)((char *)&v42 + 4) / (float)(__int64)v42)
                                        * idMath::HALF_PI)
                                + (float)(idMath::ONEFOURTH_PI + idMath::HALF_PI));
        v44 = sin(x: v43);
        idMat3::RotateSelf(
          this: &v125,
          axis: v125.mat,
          angle: (float)((float)((float)((float)*(double *)&v44 + (float)1.0) * (float)0.5) * this->secNoiseAngleTarget));
      }
      if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->primNoiseAngleTime + this->primNoiseAngleStartTime )
      {
        this->primNoiseAngleTime = idRandom2::RandomInt(
                                     this: &clientGame->random,
                                     min: this->primNoiseAngleMinTime,
                                     max: this->primNoiseAngleMaxTime);
        this->primNoiseAngleStartTime = idGameTimeManager::GetGameMs(
                                          this: &clientGame->gameTimeManager,
                                          type: GAMETIME_SCALED);
        primNoiseAngleMax = this->primNoiseAngleMax;
        v46 = 1664525 * clientGame->random.seed + 1013904223;
        clientGame->random.seed = v46;
        LODWORD(v47) = (v46 >> 10) & 0x7FFF;
        v115 = v47;
        this->primNoiseAngleTarget = (float)((float)v47 * (float)primNoiseAngleMax) * (float)0.000030518509;
      }
      v119 = *(idVec3 *)&v120.mat[1].y;
      if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < this->primNoiseAngleTime + this->primNoiseAngleStartTime )
      {
        if ( v32 < idProjectile_Rocket::GetGoalSpeed(this) )
        {
          v32 = (float)(this->acceleration + (float)v32);
          v48 = idProjectile_Rocket::GetGoalSpeed(this);
          if ( v32 >= 0.0 )
          {
            if ( v32 > v48 )
              v32 = v48;
          }
          else
          {
            v32 = 0.0;
          }
        }
        v49 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        primNoiseAngleStartTime = this->primNoiseAngleStartTime;
        LODWORD(v51) = this->primNoiseAngleTime;
        v119.x = v125.mat[0].x;
        v119.y = v125.mat[0].y;
        v119.z = v125.mat[0].z;
        DWORD1(v51) = &si_vector_decode_cat_0[184];
        v52 = v51;
        DWORD2(v51) = v49 - primNoiseAngleStartTime;
        v115 = *(_QWORD *)((char *)&v51 + 4);
        *(double *)&v53 = (float)((float)((float)*(__int64 *)((char *)&v51 + 4) / (float)v52) * idMath::TWO_PI);
        v54 = sin(x: v53);
        *(float *)&v115 = this->primNoiseAngleTarget * (float)*(double *)&v54;
        idVec3::RotateSelf(
          this: &v119,
          axis: &v125.mat[2],
          angle: (idTypesafeNumber<float,enum RadiansUnique_t> *)&v115);
      }
      v119.x = v119.x * (float)v32;
      v119.y = v119.y * (float)v32;
      v119.z = v119.z * (float)v32;
      v55 = idEntity::GetPhysics(this);
      v55->SetLinearVelocity(this: v55, a2: &v119, a3: 0);
    }
  }
  v56 = this->stuckOnActor.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v56 & 0x1FFF] == v56 >> 13 )
  {
    v57 = gameLocal->entities.ptr[v56 & 0x1FFF];
    if ( v57 != nullptr && idEntity::CastTo(c: v57) != nullptr )
    {
      v58 = this->stuckOnActor.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v58 & 0x1FFF] == v58 >> 13
        && (v59 = gameLocal->entities.ptr[v58 & 0x1FFF]) != nullptr )
      {
        v60 = idEntity::CastTo(c: v59);
      }
      else
      {
        v60 = nullptr;
      }
      if ( (unsigned __int8)idAI2::IsTypeOf(c: v60) != 0 )
      {
        v61 = this->stuckOnActor.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v61 & 0x1FFF] == v61 >> 13
          && (v62 = gameLocal->entities.ptr[v61 & 0x1FFF]) != nullptr )
        {
          v63 = (idAI2 *)idEntity::CastTo(c: v62);
        }
        else
        {
          v63 = nullptr;
        }
        v64 = idAI2::CastTo(c: v63);
        if ( v64->GetAF_2(this: v64) != nullptr && v64->GetAF_2(this: v64) != (idAnimator_AF *)-288 )
        {
          v65 = idEntity::GetPhysics(this);
          v65->GetLinearVelocity(this: (idPhysics *)&v120, result: (idVec3 *)v65, a3: 0);
          v66 = idVec3::NormalizeFast(this: v120.mat);
          idProjectile::RandomVectorInCone(normal: &v120, maxDegrees: this->randomAngle, result: v67, a4: &v126);
          v120.mat[0].x = v126.mat[0].x * (float)v66;
          v120.mat[0].y = v126.mat[0].y * (float)v66;
          v120.mat[0].z = v126.mat[0].z * (float)v66;
          v68 = idEntity::GetPhysics(this);
          v68->SetLinearVelocity(this: v68, a2: v120.mat, a3: 0);
        }
      }
    }
  }
  v69 = idEntity::GetPhysics(this);
  v69->GetLinearVelocity(this: (idPhysics *)&v116, result: (idVec3 *)v69, a3: 0);
  _FP6 = (float)((float)((float)(v116 * v116) + (float)((float)(v118 * v118) + (float)(v117 * v117)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f4, f6, f7, f12 }
  v72 = __frsqrte(_FP4);
  v73 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v72
                                                                                      * (float)((float)((float)(v116 * v116) + (float)((float)(v118 * v118) + (float)(v117 * v117)))
                                                                                              * (float)0.5))
                                                                              * (float)v72)
                                                                      - (float)1.5)
                                                      * (float)v72)
                                              * (float)((float)((float)(v116 * v116)
                                                              + (float)((float)(v118 * v118) + (float)(v117 * v117)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v72
                                                                              * (float)((float)((float)(v116 * v116)
                                                                                              + (float)((float)(v118 * v118) + (float)(v117 * v117)))
                                                                                      * (float)0.5))
                                                                      * (float)v72)
                                                              - (float)1.5)
                                              * (float)v72))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v72
                                                      * (float)((float)((float)(v116 * v116)
                                                                      + (float)((float)(v118 * v118)
                                                                              + (float)(v117 * v117)))
                                                              * (float)0.5))
                                              * (float)v72)
                                      - (float)1.5)
                      * (float)v72));
  v74 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v72 * (float)((float)((float)(v116 * v116) + (float)((float)(v118 * v118) + (float)(v117 * v117))) * (float)0.5)) * (float)v72) - (float)1.5)
                                                                                              * (float)v72)
                                                                                      * (float)((float)((float)(v116 * v116) + (float)((float)(v118 * v118) + (float)(v117 * v117)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v72 * (float)((float)((float)(v116 * v116) + (float)((float)(v118 * v118) + (float)(v117 * v117))) * (float)0.5)) * (float)v72) - (float)1.5)
                                                                                      * (float)v72))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v72
                                                                                              * (float)((float)((float)(v116 * v116) + (float)((float)(v118 * v118) + (float)(v117 * v117))) * (float)0.5))
                                                                                      * (float)v72)
                                                                              - (float)1.5)
                                                              * (float)v72))
                                              * (float)((float)((float)(v116 * v116)
                                                              + (float)((float)(v118 * v118) + (float)(v117 * v117)))
                                                      * (float)0.5))
                                      * (float)v73)
                              - (float)1.5)
              * (float)v73);
  v116 = v116 * (float)v74;
  v117 = v117 * (float)v74;
  v118 = v118 * (float)v74;
  if ( ((LODWORD(v117) | LODWORD(v118) | LODWORD(v116)) & 0x7FFFFFFF) == 0 )
  {
    v116 = 1.0;
    v117 = 0.0;
    v118 = 0.0;
  }
  v75 = idEntity::GetPhysics(this);
  if ( v75->GetClipMask(this: v75, a2: -1) != 0 )
  {
    v76 = idEntity::GetPhysics(this);
    v77 = v76->GetClipMask(this: v76, a2: -1);
  }
  else
  {
    v77 = 8495233;
  }
  v78 = idEntity::GetPhysics(this);
  v79 = idEntity::GetPhysics(this);
  v80 = idEntity::GetPhysics(this);
  entityNumber = this->entityNumber;
  v82 = (float)(v116 * g_projectileRocketImpactDistance.valueFloat);
  v83 = (float)(v117 * g_projectileRocketImpactDistance.valueFloat);
  v84 = (float)(v118 * g_projectileRocketImpactDistance.valueFloat);
  v85 = (float *)v79->GetOrigin(this: v79, a2: 0);
  v86 = (float)(v85[2] + (float)v84);
  v87 = (float)(v85[1] + (float)v83);
  v120.mat[2].z = *v85 + (float)v82;
  v122 = v86;
  v121 = v87;
  v88 = v78->GetClipModel(this: v78, a2: 0);
  v89 = v80->GetOrigin(this: v80, a2: 0);
  v90 = *(_QWORD *)&idClip::Translation(
                      this: (idClip *)&v115,
                      result: &clientGame->clip,
                      a3: nullptr,
                      start: v89,
                      end: (const idVec3 *)&v120.mat[2].z,
                      clipModel: v88,
                      startAxis: &mat3_identity,
                      clipMask: v77,
                      passEntityNumber: v94,
                      moveClipModel: v95,
                      userName: v96,
                      a12: v97,
                      a13: v98,
                      a14: v99,
                      a15: v100,
                      a16: v101,
                      a17: v102,
                      a18: v103,
                      a19: v104,
                      a20: v105,
                      a21: v106,
                      a22: v107,
                      a23: v108,
                      a24: v109,
                      a25: v110,
                      a26: v111,
                      a27: v112,
                      a28: entityNumber,
                      a29: v113,
                      a30: false,
                      a31: v114,
                      a32: (int)"w:\\tech5\\tungsten\\game\\weapons\\Projectile.cpp(1466) : Translation")->world;
  HIDWORD(v90) = this->explosionTime;
  this->deferredSurfTrace.index = v90;
  if ( SHIDWORD(v90) > 0 )
  {
    v91 = this->presentable;
    if ( v91 != nullptr )
      v92 = (int)v91->GetProjectileInterface(this: v91);
    else
      v92 = 0;
    v93 = *(_DWORD *)(v92 + 1368);
    if ( v93 + this->explosionTime <= idGameTimeManager::GetGameMs(
                                        this: &clientGame->gameTimeManager,
                                        type: GAMETIME_SCALED) )
      this->Explode(this, a2: nullptr, a3: nullptr);
  }
}


// ========================================================================
// ??0idProjectile_Homing@@QAA@XZ
// EA  : 0x82ED98A0
// RVA : 0x00ED98A0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

idProjectile_Homing *__fastcall idProjectile_Homing::idProjectile_Homing(idProjectile_Homing *this)
{
  unsigned __int64 v1; // r29

  idProjectile_Rocket::idProjectile_Rocket(this);
  LODWORD(v1) = 0;
  this->useMidpoint = false;
  this->maxTurnRadius = 60.0;
  this->__vftable = (idProjectile_Homing_vtbl *)&idProjectile_Homing::`vftable';
  this->acquireRange = 2048.0;
  this->maxTrackAngle = 170.0;
  this->sinAmplitudeStart = 0.2;
  this->proximityExplosion = 0.0;
  this->numSubMunitions = 0;
  this->desigeredHeight = 1.0e30;
  this->subMunitionProjectileList.list = nullptr;
  this->subMunitionProjectileList.granularity = 0;
  this->subMunitionProjectileList.memTag = 5;
  this->subMunitionProjectileList.listStatic = 0;
  this->subMunitionProjectileList.size = 0;
  this->subMunitionProjectileList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->subMunitionProjectileList);
  this->subMunitionMaxAngle = 0.0;
  this->randomSubMunitions = false;
  this->pairedSubMunitionVels = false;
  this->coneDirection = vec3_origin;
  this->notifiedEntity.spawnId.value = 0x1FFF;
  this->explodeNearTargetPosition = false;
  this->groudTrace.index = v1;
  return this;
}


// ========================================================================
// __unwind$506066
// EA  : 0x82ED99A0
// RVA : 0x00ED99A0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_506066()
{
  int v0; // r12

  idProjectile_Rocket::~idProjectile_Rocket(this: *(idProjectile_Rocket **)(v0 - 128 + 148));
}


// ========================================================================
// ?Think@idProjectile_Homing@@UAAXXZ
// EA  : 0x82ED99C8
// RVA : 0x00ED99C8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idProjectile_Homing::Think(idProjectile_Homing *this)
{
  unsigned __int64 v1; // r22
  idPresentable *presentable; // r3
  idEntity *entity; // r30
  idPresentablePtr<idPresentable> *v5; // r3
  idPresentablePtr<idPresentable> *v6; // r25
  idPresentable *v7; // r3
  idLobbyBase *v8; // r3
  idEntity *AttackerEntity; // r3
  idPhysics *Physics; // r3
  int v11; // r3
  const idDeclProjectile *projectileDecl; // r8
  float v13; // r5
  double heightLimit; // fp0
  float v15; // r11
  idPresentable *v16; // r3
  int GameMs; // r27
  int ThrustDelay; // r26
  idPhysics *v19; // r3
  const idVec3 *v20; // r3
  idPhysics *v21; // r3
  idPhysics *v22; // r3
  float *v23; // r3
  double v24; // fp10
  double v25; // fp4
  double z; // fp13
  const idDeclProjectile *v27; // r11
  idPhysics *v28; // r3
  float *v29; // r3
  idPhysics *v30; // r3
  double v33; // fp1
  double v34; // fp27
  int v35; // r3
  double v36; // fp6
  double v37; // fp2
  idPhysics *v38; // r3
  float *v39; // r3
  idPhysics *v40; // r3
  idVec3 *v41; // r3
  double v42; // fp1
  idPhysics *v43; // r3
  idPresentable *v44; // r3
  idPhysics *v45; // r3
  const idVec3 *v46; // r3
  idPhysics *v47; // r3
  idPhysics *v48; // r3
  float *v49; // r3
  double v50; // fp10
  double v51; // fp4
  double v52; // fp13
  const idDeclProjectile *v53; // r11
  double desigeredHeight; // fp0
  idPhysics *v55; // r3
  float *v56; // r3
  idPhysics *v57; // r3
  float *v58; // r3
  idPhysics *v59; // r3
  idVec3 *v60; // r3
  double v61; // fp1
  idPhysics *v62; // r3
  idPhysics *v63; // r3
  double proximityExplosion; // fp29
  float *v65; // r3
  double v66; // fp4
  double y; // fp28
  double v68; // fp27
  double x; // fp29
  double v70; // fp5
  double v71; // fp3
  double v72; // fp2
  double v73; // fp13
  double v74; // fp12
  idPhysics *v75; // r3
  int v76; // r3
  idPhysics *v77; // r3
  double v78; // fp26
  float *v79; // r3
  double v80; // fp1
  double v81; // fp13
  double v82; // fp12
  idPhysics *v83; // r3
  float *v84; // r3
  double v85; // fp6
  double v86; // fp4
  idPresentable *v87; // r3
  const idVec3 *v88; // r3
  idPhysics *v89; // r3
  float *v90; // r3
  idPhysics *v91; // r30
  idPhysics *v92; // r27
  float *v93; // r3
  double v96; // fp6
  double v97; // fp9
  double v98; // fp7
  double v99; // fp6
  double v100; // fp2
  idPresentable *v101; // r3
  idPresentable *v102; // r3
  idPresentable *v103; // r3
  const idVec3 *v104; // r3
  idPhysics *v105; // r3
  float *v106; // r3
  BOOL explodeNearTargetPosition; // r9
  double v108; // fp8
  double v109; // fp5
  double v111; // fp3
  double v113; // fp1
  double v114; // fp8
  double v115; // fp25
  idPhysics *v116; // r3
  double v117; // fp29
  double v118; // fp28
  double v119; // fp27
  long double v120; // fp2
  long double v121; // fp2
  double v122; // fp30
  double maxTrackAngle; // fp0
  idPhysics *v124; // r3
  float *v125; // r3
  double v126; // fp26
  double v127; // fp1
  double v128; // fp0
  double v129; // fp30
  double GoalSpeed; // fp1
  double sinAmplitudeStart; // fp0
  idClientGame *v132; // r9
  double v133; // fp11
  __int64 v134; // r6
  double v135; // fp9
  double v136; // fp8
  unsigned int v137; // r3
  double v138; // fp5
  unsigned int v139; // r9
  __int64 v140; // r7 OVERLAPPED
  double v141; // fp0
  double v142; // fp12
  double v143; // fp13
  double v144; // fp11
  idClientGame *v145; // r29
  idClipQuery *p_groudTrace; // r30
  unsigned __int64 index; // r11
  char v148; // r30
  idPresentable *v149; // r3
  int entityNumber; // r11
  int valueInteger; // r30
  idRenderWorld *v152; // r3
  double v153; // fp11
  double v154; // fp10
  double v155; // fp1
  int v156; // r30
  double v157; // fp30
  double v158; // fp29
  double v159; // fp28
  idPhysics *v160; // r3
  float *v161; // r3
  double v162; // fp8
  double v163; // fp6
  idPhysics *v164; // r3
  int v165; // r3
  idRenderWorld *v166; // r30
  idPhysics *v167; // r3
  float *v168; // r3
  idRenderWorld *v169; // r30
  double v170; // fp30
  double v171; // fp29
  double v172; // fp28
  idPhysics *v173; // r3
  float *v174; // r3
  double v175; // fp7
  double v176; // fp6
  idPhysics *v177; // r3
  double v178; // fp31
  double v179; // fp30
  double v180; // fp29
  float *v181; // r3
  double v182; // fp10
  double v183; // fp9
  int v184; // r30
  double v185; // fp31
  idClipModel *clip8x8; // r29
  double v187; // fp30
  double v188; // fp28
  double v189; // fp29
  double v190; // fp27
  double v191; // fp25
  idPhysics *v192; // r3
  float *v193; // r3
  double v194; // fp6
  double v195; // fp4
  idPhysics *v196; // r3
  const idVec3 *v197; // r3
  idRenderWorld *v198; // r30
  double v199; // fp31
  double v200; // fp30
  double v201; // fp29
  idPhysics *v202; // r3
  float *v203; // r3
  double v204; // fp12
  double v205; // fp10
  idPhysics *v206; // r3
  int v207; // r3
  idPhysics *v208; // r3
  idRenderWorld *v209; // r30
  double v210; // fp31
  double v211; // fp30
  double v212; // fp29
  idPhysics *v213; // r3
  float *v214; // r3
  double v215; // fp8
  double v216; // fp6
  idPhysics *v217; // r3
  int v218; // r3
  __int64 v219; // [sp+8h] [-2D8h]
  __int64 v220; // [sp+10h] [-2D0h]
  __int64 v221; // [sp+18h] [-2C8h]
  __int64 v222; // [sp+20h] [-2C0h]
  __int64 v223; // [sp+28h] [-2B8h]
  __int64 v224; // [sp+30h] [-2B0h]
  int v225; // [sp+38h] [-2A8h]
  int v226; // [sp+3Ch] [-2A4h]
  int v227; // [sp+40h] [-2A0h]
  int v228; // [sp+44h] [-29Ch]
  int v229; // [sp+48h] [-298h]
  int v230; // [sp+4Ch] [-294h]
  int v231; // [sp+50h] [-290h]
  int v232; // [sp+58h] [-288h]
  int v233; // [sp+60h] [-280h]
  idVec3 v234; // [sp+70h] [-270h] BYREF
  idVec3 v235; // [sp+80h] [-260h] BYREF
  idVec3 v236; // [sp+90h] [-250h] BYREF
  idVec3 v237; // [sp+A0h] [-240h] BYREF
  idVec3 v238; // [sp+B0h] [-230h] BYREF
  idProjectileTarget v239; // [sp+C0h] [-220h] BYREF
  float v240[4]; // [sp+D8h] [-208h] BYREF
  float v241[4]; // [sp+E8h] [-1F8h] BYREF
  float v242[4]; // [sp+F8h] [-1E8h] BYREF
  float v243[4]; // [sp+108h] [-1D8h] BYREF
  idVec3 v244; // [sp+118h] [-1C8h] BYREF
  float v245[4]; // [sp+130h] [-1B0h] BYREF
  float v246[4]; // [sp+140h] [-1A0h] BYREF
  float v247[4]; // [sp+150h] [-190h] BYREF
  idVec3 v248; // [sp+160h] [-180h] BYREF
  idRotation v249; // [sp+170h] [-170h] BYREF
  trace_t v250; // [sp+1C0h] [-120h] BYREF

  idProjectile_Rocket::Think(this);
  presentable = this->presentable;
  LODWORD(v1) = 0;
  entity = nullptr;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v5 = (idPresentablePtr<idPresentable> *)presentable->GetProjectileHomingInterface(this: presentable);
  v6 = v5 + 511;
  if ( v5[511].spawnId == 1 )
  {
    v7 = idPresentablePtr<idPresentableProjectile>::operator->(this: v5 + 515);
    if ( v7 == nullptr || v7->entity == nullptr )
    {
      v239.presentable.spawnId = 0;
      *(_QWORD *)&v239.type = LODWORD(vec3_origin.x);
      *(_QWORD *)&v239.pos.y = *(_QWORD *)&vec3_origin.y;
      idProjectile_Homing::SetTarget(this, target_: &v239);
    }
  }
  if ( common->IsMultiplayer(this: common) )
  {
    v8 = session->GetActingGameStateLobbyBase(this: session);
    if ( v8->GetMatchParms(this: v8)->gameType == 2
      && this->projectileDecl->notHitscanInfo.homingInfo.attackStyle == CLUSTER_BOMB )
    {
      if ( v6->spawnId != 0 )
        goto LABEL_14;
      if ( idProjectile_Homing::GetHomingState(this) == ACQUIRING )
      {
        AttackerEntity = idProjectile::GetAttackerEntity(this);
        Physics = idEntity::GetPhysics(this: AttackerEntity);
        v11 = (int)Physics->GetOrigin(this: Physics, a2: 0);
        projectileDecl = this->projectileDecl;
        v239.type = TARGET_POINT;
        v13 = *(float *)v11;
        heightLimit = projectileDecl->notHitscanInfo.homingInfo.heightLimit;
        v15 = *(float *)(v11 + 8);
        v239.pos.y = *(float *)(v11 + 4);
        v239.pos.x = v13;
        v237.z = (float)heightLimit + v15;
        v239.pos.z = v237.z;
        idProjectile_Homing::SetProjectileTarget(
          this: (idProjectile_Homing *)2,
          newTarget: (const idProjectileTarget *)LODWORD(v239.pos.y),
          a3: LODWORD(v237.z),
          a4: 0,
          a5: 2,
          a6: (int)projectileDecl,
          a7: SLODWORD(v237.z),
          a8: SLODWORD(v239.pos.y),
          a9: v219,
          a10: v220,
          a11: v221,
          a12: v222,
          a13: v223,
          a14: v224);
        idProjectile_Homing::SetHomingState(this, newState: LAUNCHING);
      }
    }
  }
  if ( v6->spawnId == 0 )
    return;
LABEL_14:
  v16 = this->presentable;
  if ( v16 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v16 = this->presentable;
  }
  if ( v16->GetProjectileHomingInterface(this: v16)->homingState == LAUNCHING )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    ThrustDelay = idProjectile_Rocket::GetThrustDelay(this);
    if ( GameMs > ThrustDelay + idProjectile::GetLaunchTime(this) )
    {
      if ( v6->spawnId == 1 )
      {
        entity = idPresentablePtr<idPresentableProjectile>::operator->(this: v6 + 4)->entity;
        v19 = idEntity::GetPhysics(this: entity);
        v20 = v19->GetOrigin(this: v19, a2: 0);
      }
      else
      {
        v20 = idProjectileTarget::operator idVec3 const &(this: (idProjectileTarget *)v6);
      }
      v234.x = v20->x;
      v234.y = v20->y;
      v234.z = v20->z;
      v21 = idEntity::GetPhysics(this);
      v21->SetGravity(this: v21, a2: &vec3_origin);
      if ( this->useMidpoint )
      {
        v22 = idEntity::GetPhysics(this);
        v23 = (float *)v22->GetOrigin(this: v22, a2: 0);
        v24 = (float)(v23[2] + v234.z);
        v25 = (float)((float)(v23[1] + v234.y) * (float)0.5);
        v238.x = (float)(*v23 + v234.x) * (float)0.5;
        v238.y = v25;
        z = (float)((float)v24 * (float)0.5);
      }
      else
      {
        z = v234.z;
        v238.x = v234.x;
        v238.y = v234.y;
      }
      v238.z = z;
      v27 = this->projectileDecl;
      if ( v27->notHitscanInfo.homingInfo.heightLimit <= 0.0 )
      {
        v28 = idEntity::GetPhysics(this);
        v29 = (float *)v28->GetOrigin(this: v28, a2: 0);
        v234.x = v234.x - *v29;
        v234.y = v234.y - v29[1];
        v234.z = v234.z - v29[2];
        v30 = idEntity::GetPhysics(this);
        _FP3 = (float)((float)((float)(v234.x * v234.x) + (float)((float)(v234.z * v234.z) + (float)(v234.y * v234.y)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f2, f3, f29, f0 }
        v33 = __frsqrte(_FP2);
        v34 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v33
                                                                                            * (float)((float)((float)(v234.x * v234.x) + (float)((float)(v234.z * v234.z) + (float)(v234.y * v234.y))) * (float)0.5))
                                                                                    * (float)v33)
                                                                            - (float)1.5)
                                                            * (float)v33)
                                                    * (float)((float)((float)(v234.x * v234.x)
                                                                    + (float)((float)(v234.z * v234.z)
                                                                            + (float)(v234.y * v234.y)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v33
                                                                                    * (float)((float)((float)(v234.x * v234.x) + (float)((float)(v234.z * v234.z) + (float)(v234.y * v234.y)))
                                                                                            * (float)0.5))
                                                                            * (float)v33)
                                                                    - (float)1.5)
                                                    * (float)v33))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v33
                                                            * (float)((float)((float)(v234.x * v234.x)
                                                                            + (float)((float)(v234.z * v234.z)
                                                                                    + (float)(v234.y * v234.y)))
                                                                    * (float)0.5))
                                                    * (float)v33)
                                            - (float)1.5)
                            * (float)v33));
        v35 = (int)v30->GetOrigin(this: v30, a2: 0);
        v36 = v238.z;
        v37 = (float)((float)((float)((float)((float)-(float)((float)((float)((float)v34
                                                                            * (float)((float)((float)(v234.x * v234.x)
                                                                                            + (float)((float)(v234.z * v234.z) + (float)(v234.y * v234.y)))
                                                                                    * (float)0.5))
                                                                    * (float)v34)
                                                            - (float)1.5)
                                            * (float)v34)
                                    * (float)((float)(v234.x * v234.x)
                                            + (float)((float)(v234.z * v234.z) + (float)(v234.y * v234.y))))
                            * (float)0.5)
                    + *(float *)(v35 + 8));
        this->desigeredHeight = (float)((float)((float)((float)-(float)((float)((float)((float)v34
                                                                                      * (float)((float)((float)(v234.x * v234.x) + (float)((float)(v234.z * v234.z) + (float)(v234.y * v234.y)))
                                                                                              * (float)0.5))
                                                                              * (float)v34)
                                                                      - (float)1.5)
                                                      * (float)v34)
                                              * (float)((float)(v234.x * v234.x)
                                                      + (float)((float)(v234.z * v234.z) + (float)(v234.y * v234.y))))
                                      * (float)0.5)
                              + *(float *)(v35 + 8);
        v238.z = (float)((float)v37 * (float)0.5) + (float)v36;
      }
      else
      {
        v238.z = v27->notHitscanInfo.homingInfo.heightLimit + (float)z;
      }
      v38 = idEntity::GetPhysics(this);
      v39 = (float *)v38->GetOrigin(this: v38, a2: 0);
      v238.x = v238.x - *v39;
      v238.y = v238.y - v39[1];
      v238.z = v238.z - v39[2];
      idVec3::NormalizeFast(this: &v238);
      v40 = idEntity::GetPhysics(this);
      v41 = v40->GetLinearVelocity(this: (idPhysics *)&v248, result: (idVec3 *)v40, a3: 0);
      v42 = idVec3::NormalizeFast(this: v41);
      v238.x = (float)v42 * v238.x;
      v238.y = (float)v42 * v238.y;
      v238.z = (float)v42 * v238.z;
      v43 = idEntity::GetPhysics(this);
      v43->SetLinearVelocity(this: v43, a2: &v238, a3: 0);
      this->alignToVelocity = true;
      idProjectile_Homing::SetHomingState(this, newState: FLYOUT);
    }
  }
  v44 = this->presentable;
  if ( v44 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v44 = this->presentable;
  }
  if ( v44->GetProjectileHomingInterface(this: v44)->homingState == FLYOUT && idProjectile::GetState(this) != EXPLODED )
  {
    if ( v6->spawnId == 1 )
    {
      entity = idPresentablePtr<idPresentableProjectile>::operator->(this: v6 + 4)->entity;
      v45 = idEntity::GetPhysics(this: entity);
      v46 = v45->GetOrigin(this: v45, a2: 0);
    }
    else
    {
      v46 = idProjectileTarget::operator idVec3 const &(this: (idProjectileTarget *)v6);
    }
    v234.x = v46->x;
    v234.y = v46->y;
    v234.z = v46->z;
    v47 = idEntity::GetPhysics(this);
    v47->GetLinearVelocity(this: (idPhysics *)&v248, result: (idVec3 *)v47, a3: 0);
    idVec3::NormalizeFast(this: &v248);
    if ( this->useMidpoint )
    {
      v48 = idEntity::GetPhysics(this);
      v49 = (float *)v48->GetOrigin(this: v48, a2: 0);
      v50 = (float)(v49[2] + v234.z);
      v51 = (float)((float)(v49[1] + v234.y) * (float)0.5);
      v236.x = (float)(*v49 + v234.x) * (float)0.5;
      v236.y = v51;
      v52 = (float)((float)v50 * (float)0.5);
    }
    else
    {
      v52 = v234.z;
      v236.x = v234.x;
      v236.y = v234.y;
    }
    v236.z = v52;
    v53 = this->projectileDecl;
    if ( v53->notHitscanInfo.homingInfo.heightLimit <= 0.0 )
      desigeredHeight = this->desigeredHeight;
    else
      desigeredHeight = (float)(v53->notHitscanInfo.homingInfo.heightLimit + (float)v52);
    v236.z = desigeredHeight;
    v237 = v236;
    v55 = idEntity::GetPhysics(this);
    v56 = (float *)v55->GetOrigin(this: v55, a2: 0);
    v236.x = v236.x - *v56;
    v236.y = v236.y - v56[1];
    v236.z = v236.z - v56[2];
    idVec3::NormalizeFast(this: &v236);
    v57 = idEntity::GetPhysics(this);
    v58 = (float *)v57->GetOrigin(this: v57, a2: 0);
    v234.x = v234.x - *v58;
    v234.y = v234.y - v58[1];
    v234.z = v234.z - v58[2];
    idVec3::NormalizeFast(this: &v234);
    v59 = idEntity::GetPhysics(this);
    v60 = v59->GetLinearVelocity(this: (idPhysics *)&v239, result: (idVec3 *)v59, a3: 0);
    v61 = idVec3::NormalizeFast(this: v60);
    v236.x = (float)v61 * v236.x;
    v236.y = (float)v61 * v236.y;
    v236.z = (float)v61 * v236.z;
    v62 = idEntity::GetPhysics(this);
    v62->SetLinearVelocity(this: v62, a2: &v236, a3: 0);
    v63 = idEntity::GetPhysics(this);
    proximityExplosion = this->proximityExplosion;
    v65 = (float *)v63->GetAbsBounds(this: v63, a2: 0);
    v66 = (float)((float)proximityExplosion * (float)proximityExplosion);
    y = v237.y;
    v68 = v237.z;
    x = v237.x;
    v70 = (float)((float)((float)(v65[4] + v65[1]) * (float)0.5) - v237.y);
    v71 = (float)((float)((float)(v65[5] + v65[2]) * (float)0.5) - v237.z);
    v72 = (float)((float)((float)(v65[3] + *v65) * (float)0.5) - v237.x);
    if ( (float)((float)((float)v72 * (float)v72)
               + (float)((float)((float)v71 * (float)v71) + (float)((float)v70 * (float)v70))) <= v66
      && this->projectileDecl->notHitscanInfo.homingInfo.attackStyle == CLUSTER_BOMB )
    {
      v73 = v234.x;
      v74 = v234.z;
      this->coneDirection.y = v234.y;
      this->coneDirection.x = v73;
      this->coneDirection.z = v74;
      this->Explode(this, a2: nullptr, a3: nullptr);
      return;
    }
    v75 = idEntity::GetPhysics(this);
    v76 = (int)v75->GetAbsBounds(this: v75, a2: 0);
    if ( (float)((float)(*(float *)(v76 + 20) + *(float *)(v76 + 8)) * (float)0.5) >= (double)this->desigeredHeight
      || (v77 = idEntity::GetPhysics(this),
          v78 = this->proximityExplosion,
          v79 = (float *)v77->GetAbsBounds(this: v77, a2: 0),
          v80 = (float)((float)((float)(v79[5] + v79[2]) * (float)0.5) - (float)v68),
          v81 = (float)((float)((float)(v79[3] + *v79) * (float)0.5) - (float)x),
          (float)((float)((float)(v82 = (float)((float)((float)(v79[4] + v79[1]) * (float)0.5) - (float)y)) * (float)v82)
                + (float)((float)((float)v81 * (float)v81) + (float)((float)v80 * (float)v80))) <= (double)(float)((float)v78 * (float)v78)) )
    {
      idProjectile_Homing::SetHomingState(this, newState: ACQUIRING|FLYOUT);
      if ( v6->spawnId == 1 )
      {
        v83 = idEntity::GetPhysics(this: entity);
        v84 = (float *)v83->GetAbsBounds(this: v83, a2: 0);
        v85 = (float)(v84[5] + v84[2]);
        v86 = (float)((float)(v84[3] + *v84) * (float)0.5);
        v234.y = (float)(v84[4] + v84[1]) * (float)0.5;
        v234.x = v86;
        v234.z = (float)v85 * (float)0.5;
        if ( v6->spawnId == 1 )
        {
          v87 = idPresentablePtr<idPresentableProjectile>::operator->(this: v6 + 4);
          idProjectile_Homing::NotifyEntityAboutHoming(this, ent: v87->entity, addNew: true);
        }
        else
        {
          idProjectile_Homing::NotifyEntityAboutHoming(this, ent: MEMORY[0x448], addNew: true);
        }
      }
      else
      {
        v88 = idProjectileTarget::operator idVec3 const &(this: (idProjectileTarget *)v6);
        v234.x = v88->x;
        v234.y = v88->y;
        v234.z = v88->z;
      }
      v89 = idEntity::GetPhysics(this);
      v90 = (float *)v89->GetOrigin(this: v89, a2: 0);
      v234.x = v234.x - *v90;
      v234.y = v234.y - v90[1];
      v234.z = v234.z - v90[2];
      idVec3::NormalizeFast(this: &v234);
      v91 = idEntity::GetPhysics(this);
      v92 = idEntity::GetPhysics(this);
      v93 = (float *)v91->GetLinearVelocity(this: (idPhysics *)&v239, result: (idVec3 *)v91, a3: 0);
      _FP9 = (float)((float)((float)(v93[2] * v93[2]) + (float)((float)(*v93 * *v93) + (float)(v93[1] * v93[1])))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f7, f9, f10, f0 }
      v96 = __frsqrte(_FP7);
      v97 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v96
                                                                                          * (float)((float)((float)(v93[2] * v93[2]) + (float)((float)(*v93 * *v93) + (float)(v93[1] * v93[1])))
                                                                                                  * (float)0.5))
                                                                                  * (float)v96)
                                                                          - (float)1.5)
                                                          * (float)v96)
                                                  * (float)((float)((float)(v93[2] * v93[2])
                                                                  + (float)((float)(*v93 * *v93)
                                                                          + (float)(v93[1] * v93[1])))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v96
                                                                                  * (float)((float)((float)(v93[2] * v93[2])
                                                                                                  + (float)((float)(*v93 * *v93) + (float)(v93[1] * v93[1])))
                                                                                          * (float)0.5))
                                                                          * (float)v96)
                                                                  - (float)1.5)
                                                  * (float)v96))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v96
                                                          * (float)((float)((float)(v93[2] * v93[2])
                                                                          + (float)((float)(*v93 * *v93)
                                                                                  + (float)(v93[1] * v93[1])))
                                                                  * (float)0.5))
                                                  * (float)v96)
                                          - (float)1.5)
                          * (float)v96));
      v98 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v96 * (float)((float)((float)(v93[2] * v93[2]) + (float)((float)(*v93 * *v93) + (float)(v93[1] * v93[1]))) * (float)0.5)) * (float)v96) - (float)1.5)
                                                                                          * (float)v96)
                                                                                  * (float)((float)((float)(v93[2] * v93[2])
                                                                                                  + (float)((float)(*v93 * *v93) + (float)(v93[1] * v93[1])))
                                                                                          * (float)0.5))
                                                                          * (float)((float)-(float)((float)((float)((float)v96 * (float)((float)((float)(v93[2] * v93[2]) + (float)((float)(*v93 * *v93) + (float)(v93[1] * v93[1]))) * (float)0.5)) * (float)v96)
                                                                                                  - (float)1.5)
                                                                                  * (float)v96))
                                                                  - (float)1.5)
                                                  * (float)((float)-(float)((float)((float)((float)v96
                                                                                          * (float)((float)((float)(v93[2] * v93[2]) + (float)((float)(*v93 * *v93) + (float)(v93[1] * v93[1])))
                                                                                                  * (float)0.5))
                                                                                  * (float)v96)
                                                                          - (float)1.5)
                                                          * (float)v96))
                                          * (float)((float)((float)(v93[2] * v93[2])
                                                          + (float)((float)(*v93 * *v93) + (float)(v93[1] * v93[1])))
                                                  * (float)0.5))
                                  * (float)v97)
                          - (float)1.5);
      v99 = (float)((float)v98
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v96
                                                                                                  * (float)((float)((float)(v93[2] * v93[2]) + (float)((float)(*v93 * *v93) + (float)(v93[1] * v93[1]))) * (float)0.5))
                                                                                          * (float)v96)
                                                                                  - (float)1.5)
                                                                  * (float)v96)
                                                          * (float)((float)((float)(v93[2] * v93[2])
                                                                          + (float)((float)(*v93 * *v93)
                                                                                  + (float)(v93[1] * v93[1])))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v96
                                                                                          * (float)((float)((float)(v93[2] * v93[2]) + (float)((float)(*v93 * *v93) + (float)(v93[1] * v93[1])))
                                                                                                  * (float)0.5))
                                                                                  * (float)v96)
                                                                          - (float)1.5)
                                                          * (float)v96))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v96
                                                                  * (float)((float)((float)(v93[2] * v93[2])
                                                                                  + (float)((float)(*v93 * *v93)
                                                                                          + (float)(v93[1] * v93[1])))
                                                                          * (float)0.5))
                                                          * (float)v96)
                                                  - (float)1.5)
                                  * (float)v96)));
      v100 = (float)((float)v99
                   * (float)((float)(v93[2] * v93[2]) + (float)((float)(*v93 * *v93) + (float)(v93[1] * v93[1]))));
      v243[0] = (float)((float)v99
                      * (float)((float)(v93[2] * v93[2]) + (float)((float)(*v93 * *v93) + (float)(v93[1] * v93[1]))))
              * v234.x;
      v243[1] = (float)v100 * v234.y;
      v243[2] = (float)v100 * v234.z;
      v92->SetLinearVelocity(this: v92, a2: (const idVec3 *)v243, a3: 0);
    }
  }
  v101 = this->presentable;
  if ( v101 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v101 = this->presentable;
  }
  if ( v101->GetProjectileHomingInterface(this: v101)->homingState == ACQUIRING
    || idProjectile_Homing::GetHomingState(this) == (ACQUIRING|FLYOUT)
    && v6->spawnId == 1
    && idProjectileTarget::operator==(this: (idProjectileTarget *)v6, p: nullptr) )
  {
    idProjectile_Homing::SetHomingState(this, newState: ACQUIRING);
  }
  v102 = this->presentable;
  if ( v102 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v102 = this->presentable;
  }
  if ( v102->GetProjectileHomingInterface(this: v102)->homingState == (ACQUIRING|FLYOUT)
    && idProjectile::GetState(this) != EXPLODED
    && this->alignToVelocity )
  {
    if ( v6->spawnId == 1 )
    {
      v103 = idPresentablePtr<idPresentableProjectile>::operator->(this: v6 + 4);
      v103->entity->GetAimPoint(this: v103->entity, a2: AIMPOINT_BEST, a3: &v234);
    }
    else
    {
      v104 = idProjectileTarget::operator idVec3 const &(this: (idProjectileTarget *)v6);
      v234.x = v104->x;
      v234.y = v104->y;
      v234.z = v104->z;
    }
    v105 = idEntity::GetPhysics(this);
    v106 = (float *)v105->GetOrigin(this: v105, a2: 0);
    explodeNearTargetPosition = this->explodeNearTargetPosition;
    v234.x = v234.x - *v106;
    v108 = (float)((float)(v234.y - v106[1]) * (float)(v234.y - v106[1]));
    v234.y = v234.y - v106[1];
    v109 = (float)((float)(v234.x * v234.x)
                 + (float)((float)((float)(v234.z - v106[2]) * (float)(v234.z - v106[2])) + (float)v108));
    _FP4 = (float)((float)((float)(v234.x * v234.x)
                         + (float)((float)((float)(v234.z - v106[2]) * (float)(v234.z - v106[2])) + (float)v108))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v111 = (float)((float)((float)(v234.x * v234.x)
                         + (float)((float)((float)(v234.z - v106[2]) * (float)(v234.z - v106[2])) + (float)v108))
                 * (float)0.5);
    __asm { fsel      f2, f4, f5, f0 }
    v113 = __frsqrte(_FP2);
    v114 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v113
                                                                                         * (float)((float)((float)(v234.x * v234.x) + (float)((float)((float)(v234.z - v106[2]) * (float)(v234.z - v106[2])) + (float)v108))
                                                                                                 * (float)0.5))
                                                                                 * (float)v113)
                                                                         - (float)1.5)
                                                         * (float)v113)
                                                 * (float)((float)((float)(v234.x * v234.x)
                                                                 + (float)((float)((float)(v234.z - v106[2])
                                                                                 * (float)(v234.z - v106[2]))
                                                                         + (float)v108))
                                                         * (float)0.5))
                                         * (float)((float)-(float)((float)((float)((float)v113
                                                                                 * (float)((float)((float)(v234.x * v234.x)
                                                                                                 + (float)((float)((float)(v234.z - v106[2]) * (float)(v234.z - v106[2])) + (float)v108))
                                                                                         * (float)0.5))
                                                                         * (float)v113)
                                                                 - (float)1.5)
                                                 * (float)v113))
                                 - (float)1.5)
                 * (float)((float)-(float)((float)((float)((float)v113
                                                         * (float)((float)((float)(v234.x * v234.x)
                                                                         + (float)((float)((float)(v234.z - v106[2])
                                                                                         * (float)(v234.z - v106[2]))
                                                                                 + (float)v108))
                                                                 * (float)0.5))
                                                 * (float)v113)
                                         - (float)1.5)
                         * (float)v113));
    v234.z = v234.z - v106[2];
    v115 = (float)((float)((float)-(float)((float)((float)((float)v114 * (float)v111) * (float)v114) - (float)1.5)
                         * (float)v114)
                 * (float)v109);
    if ( explodeNearTargetPosition && v115 <= 100.0 )
    {
      this->Explode(this, a2: nullptr, a3: nullptr);
      return;
    }
    v116 = idEntity::GetPhysics(this);
    v116->GetLinearVelocity(this: (idPhysics *)&v235, result: (idVec3 *)v116, a3: 0);
    idVec3::NormalizeFast(this: &v234);
    idVec3::NormalizeFast(this: &v235);
    v117 = (float)((float)(v235.x * v234.y) - (float)(v234.x * v235.y));
    v118 = (float)((float)(v235.y * v234.z) - (float)(v235.z * v234.y));
    v119 = (float)((float)(v234.x * v235.z) - (float)(v235.x * v234.z));
    *(double *)&v120 = __fsqrts((float)((float)((float)((float)(v234.x * v235.z) - (float)(v235.x * v234.z))
                                              * (float)((float)(v234.x * v235.z) - (float)(v235.x * v234.z)))
                                      + (float)((float)((float)((float)(v235.y * v234.z) - (float)(v235.z * v234.y))
                                                      * (float)((float)(v235.y * v234.z) - (float)(v235.z * v234.y)))
                                              + (float)((float)((float)(v235.x * v234.y) - (float)(v234.x * v235.y))
                                                      * (float)((float)(v235.x * v234.y) - (float)(v234.x * v235.y))))));
    v121 = asin(x: v120);
    v122 = (float)((float)*(double *)&v121 * idMath::M_RAD2DEG);
    if ( (float)((float)(v235.x * v234.x) + (float)((float)(v235.z * v234.z) + (float)(v235.y * v234.y))) < 0.0 )
    {
      if ( v122 < 0.0 )
        v122 = (float)((float)((float)*(double *)&v121 * idMath::M_RAD2DEG) - (float)180.0);
      else
        v122 = (float)((float)((float)*(double *)&v121 * idMath::M_RAD2DEG) + (float)180.0);
    }
    maxTrackAngle = this->maxTrackAngle;
    if ( maxTrackAngle > 0.0 && __fabs(v122) > maxTrackAngle )
      idProjectile_Homing::SetHomingState(this, newState: ACQUIRING);
    v124 = idEntity::GetPhysics(this);
    v125 = (float *)v124->GetLinearVelocity(this: (idPhysics *)&v239, result: (idVec3 *)v124, a3: 0);
    v126 = __fsqrts((float)((float)(v125[2] * v125[2]) + (float)((float)(*v125 * *v125) + (float)(v125[1] * v125[1]))));
    v127 = ((double (*)(void))gameLocal->GetRealSecPerFrame)();
    v128 = (float)((float)v127 * (float)((float)(this->maxTurnRadius * (float)3.1415927) * (float)2.0));
    if ( v122 >= -v128 )
    {
      if ( v122 > v128 )
        v122 = (float)((float)v127 * (float)((float)(this->maxTurnRadius * (float)3.1415927) * (float)2.0));
    }
    else
    {
      v122 = -v128;
    }
    v249.axisValid = false;
    v249.origin.x = vec3_origin.x;
    v249.origin.y = vec3_origin.y;
    v249.origin.z = vec3_origin.z;
    v249.vec.x = v118;
    v249.vec.y = v119;
    v249.vec.z = v117;
    v249.angle = -v122;
    idRotation::RotatePoint(this: &v249, point: &v235);
    if ( v126 < idProjectile_Rocket::GetGoalSpeed(this) )
    {
      v129 = (float)(this->acceleration + (float)v126);
      GoalSpeed = idProjectile_Rocket::GetGoalSpeed(this);
      if ( v129 >= v126 )
      {
        if ( v129 <= GoalSpeed )
          v126 = v129;
        else
          v126 = GoalSpeed;
      }
    }
    sinAmplitudeStart = this->sinAmplitudeStart;
    if ( sinAmplitudeStart <= 0.0 || v115 <= 110.0 )
      goto LABEL_94;
    v132 = clientGame;
    v133 = (float)(this->sinAmplitudeStart * (float)0.5);
    HIDWORD(v134) = 1013904223;
    clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
    v135 = (float)((float)sinAmplitudeStart * (float)0.25);
    v136 = (float)((float)((float)sinAmplitudeStart * (float)0.25) * (float)0.5);
    LODWORD(v134) = (v132->random.seed >> 10) & 0x7FFF;
    v137 = 1664525 * clientGame->random.seed;
    v138 = (float)v134;
    clientGame->random.seed = v137 + 1013904223;
    HIDWORD(v140) = ((v137 + 1013904223) >> 10) & 0x7FFF;
    *(_QWORD *)&v237.x = *(__int64 *)((char *)&v140 + 4);
    v139 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v139;
    LODWORD(v140) = (v139 >> 10) & 0x7FFF;
    *(_QWORD *)&v237.x = v140;
    v142 = (float)((float)((float)((float)*(__int64 *)((char *)&v140 + 4) * (float)sinAmplitudeStart)
                         * (float)0.000030518509)
                 - (float)v133);
    v143 = (float)((float)((float)((float)v140 * (float)((float)sinAmplitudeStart * (float)0.25)) * (float)0.000030518509)
                 - (float)((float)((float)sinAmplitudeStart * (float)0.25) * (float)0.5));
    v141 = (float)((float)((float)((float)v138 * (float)sinAmplitudeStart) * (float)0.000030518509)
                 - (float)((float)sinAmplitudeStart * (float)0.5));
    if ( v115 >= 320.0 )
    {
      if ( v115 <= 1100.0 )
      {
LABEL_93:
        v235.x = v235.x + (float)v141;
        v235.y = (float)v142 + v235.y;
        v235.z = (float)v143 + v235.z;
        idVec3::NormalizeFast(this: &v235);
LABEL_94:
        if ( this->projectileDecl->notHitscanInfo.homingInfo.attackStyle == GUIDED_RPG )
        {
          v145 = clientGame;
          p_groudTrace = &this->groudTrace;
          if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &this->groudTrace) != 0 )
          {
            index = p_groudTrace->index;
            p_groudTrace->index = v1;
            idCollisionModelManager::GetContentsResult(
              this: collisionModelManager,
              result: &v250,
              query: &v145->clip.collisionQueries[index & 0xFFF].query,
              peek: false);
            if ( v250.fraction < 1.0 )
            {
              v148 = 1;
              if ( v6->spawnId == 1 )
              {
                v149 = idPresentablePtr<idPresentableProjectile>::operator->(this: v6 + 4);
                v148 = v149->entityNumber != v250.c.entityNum;
              }
              if ( idProjectile::GetAttacker(this) != nullptr )
              {
                entityNumber = idProjectile::GetAttacker(this)->entityNumber;
                v148 = entityNumber == v250.c.entityNum ? 0 : v148;
              }
              if ( v148 != 0 )
              {
                valueInteger = g_projectileHomingGroundCheckDebug.valueInteger;
                if ( g_projectileHomingGroundCheckDebug.valueInteger != 0 )
                {
                  idLib::Printf(fmt: "hit something move up a bit entity: %i\n", v250.c.entityNum);
                  v152 = common->RW(this: common);
                  v245[2] = v250.endpos.z;
                  v245[0] = v250.endpos.x;
                  v245[1] = v250.endpos.y;
                  v245[3] = 5.0;
                  v152->DebugSphere(
                    this: v152,
                    a2: (const idVec4 *)&idColor::colorRed,
                    a3: (const idSphere *)v245,
                    a4: 12,
                    a5: 5000,
                    a6: false);
                  valueInteger = g_projectileHomingGroundCheckDebug.valueInteger;
                }
                v153 = (float)((float)((float)((float)(v250.c.normal.y * v235.y)
                                             + (float)((float)(v250.c.normal.x * v235.x)
                                                     + (float)(v250.c.normal.z * v235.z)))
                                     * v250.c.normal.z)
                             * g_projectileHomingGroundReflection.valueFloat);
                v154 = (float)(v235.x
                             - (float)((float)(v250.c.normal.x
                                             * (float)((float)(v250.c.normal.y * v235.y)
                                                     + (float)((float)(v250.c.normal.x * v235.x)
                                                             + (float)(v250.c.normal.z * v235.z))))
                                     * g_projectileHomingGroundReflection.valueFloat));
                v235.y = v235.y
                       - (float)((float)((float)((float)(v250.c.normal.y * v235.y)
                                               + (float)((float)(v250.c.normal.x * v235.x)
                                                       + (float)(v250.c.normal.z * v235.z)))
                                       * v250.c.normal.y)
                               * g_projectileHomingGroundReflection.valueFloat);
                v235.x = v154;
                v235.z = v235.z - (float)v153;
                v155 = idVec3::NormalizeFast(this: &v235);
                if ( valueInteger != 0 )
                {
                  v156 = ((int (__fastcall *)(idCommon *, double))common->RW)(a1: common, a2: v155);
                  v157 = (float)(v235.x * g_projectileHomingGroundCheck.valueFloat);
                  v158 = (float)(v235.y * g_projectileHomingGroundCheck.valueFloat);
                  v159 = (float)(v235.z * g_projectileHomingGroundCheck.valueFloat);
                  v160 = idEntity::GetPhysics(this);
                  v161 = (float *)v160->GetOrigin(this: v160, a2: 0);
                  v162 = (float)(v161[2] + (float)v159);
                  v163 = (float)(v161[1] + (float)v158);
                  v241[0] = *v161 + (float)v157;
                  v241[2] = v162;
                  v241[1] = v163;
                  v164 = idEntity::GetPhysics(this);
                  v165 = (int)v164->GetOrigin(this: v164, a2: 0);
                  (*(void (__fastcall **)(int, idColor *, int, float *, int, _DWORD))(*(_DWORD *)v156 + 176))(
                    a1: v156,
                    a2: &idColor::colorCyan,
                    a3: v165,
                    a4: v241,
                    a5: 5000,
                    a6: 0);
                  v166 = common->RW(this: common);
                  v167 = idEntity::GetPhysics(this);
                  v168 = (float *)v167->GetOrigin(this: v167, a2: 0);
                  v247[0] = *v168;
                  v247[1] = v168[1];
                  v247[2] = v168[2];
                  v247[3] = 1.0;
                  v166->DebugSphere(
                    this: v166,
                    a2: (const idVec4 *)&idColor::colorGreen,
                    a3: (const idSphere *)v247,
                    a4: 12,
                    a5: 5000,
                    a6: false);
                  v169 = common->RW(this: common);
                  v170 = (float)(v235.x * g_projectileHomingGroundCheck.valueFloat);
                  v171 = (float)(v235.y * g_projectileHomingGroundCheck.valueFloat);
                  v172 = (float)(v235.z * g_projectileHomingGroundCheck.valueFloat);
                  v173 = idEntity::GetPhysics(this);
                  v174 = (float *)v173->GetOrigin(this: v173, a2: 0);
                  v175 = (float)(*v174 + (float)v170);
                  v176 = (float)(v174[1] + (float)v171);
                  v246[2] = v174[2] + (float)v172;
                  v246[3] = 1.0;
                  v246[0] = v175;
                  v246[1] = v176;
                  v169->DebugSphere(
                    this: v169,
                    a2: (const idVec4 *)&idColor::colorYellow,
                    a3: (const idSphere *)v246,
                    a4: 12,
                    a5: 5000,
                    a6: false);
                }
              }
            }
          }
        }
        v177 = idEntity::GetPhysics(this);
        v178 = (float)(vec3_up.x * (float)-1.0);
        v179 = (float)(vec3_up.y * (float)-1.0);
        v180 = (float)(vec3_up.z * (float)-1.0);
        v181 = (float *)v177->GetAxis(this: v177, a2: 0);
        v182 = (float)(v181[1] + (float)v179);
        v183 = (float)(v181[2] + (float)v180);
        v237.x = *v181 + (float)v178;
        v237.y = v182;
        v237.z = v183;
        idVec3::NormalizeFast(this: &v237);
        v184 = this->entityNumber;
        v185 = v237.x;
        clip8x8 = clientGame->clip.clip8x8;
        v187 = v237.y;
        v188 = (float)(v237.x * g_projectileHomingGroundCheck.valueFloat);
        v189 = v237.z;
        v190 = (float)(v237.y * g_projectileHomingGroundCheck.valueFloat);
        v191 = (float)(v237.z * g_projectileHomingGroundCheck.valueFloat);
        v192 = idEntity::GetPhysics(this);
        v193 = (float *)v192->GetOrigin(this: v192, a2: 0);
        v194 = (float)(v193[2] + (float)v191);
        v195 = (float)(v193[1] + (float)v190);
        v244.x = *v193 + (float)v188;
        v244.z = v194;
        v244.y = v195;
        v196 = idEntity::GetPhysics(this);
        v197 = v196->GetOrigin(this: v196, a2: 0);
        this->groudTrace.index = *(_QWORD *)&idClip::Translation(
                                               this: (idClip *)&v237,
                                               result: &clientGame->clip,
                                               a3: nullptr,
                                               start: v197,
                                               end: &v244,
                                               clipModel: clip8x8,
                                               startAxis: &mat3_identity,
                                               clipMask: 1,
                                               passEntityNumber: SHIDWORD(v219),
                                               moveClipModel: v219,
                                               userName: (const char *)HIDWORD(v220),
                                               a12: v220,
                                               a13: SHIDWORD(v221),
                                               a14: v221,
                                               a15: SHIDWORD(v222),
                                               a16: v222,
                                               a17: SHIDWORD(v223),
                                               a18: v223,
                                               a19: SHIDWORD(v224),
                                               a20: v224,
                                               a21: v225,
                                               a22: v226,
                                               a23: v227,
                                               a24: v228,
                                               a25: v229,
                                               a26: v230,
                                               a27: v231,
                                               a28: v184,
                                               a29: v232,
                                               a30: false,
                                               a31: v233,
                                               a32: (int)"w:\\tech5\\tungsten\\game\\weapons\\Projectile.cpp(1992) : Translation")->world;
        if ( g_projectileHomingGroundCheckDebug.valueInteger != 0 )
        {
          v198 = common->RW(this: common);
          v199 = (float)((float)v185 * g_projectileHomingGroundCheck.valueFloat);
          v200 = (float)((float)v187 * g_projectileHomingGroundCheck.valueFloat);
          v201 = (float)((float)v189 * g_projectileHomingGroundCheck.valueFloat);
          v202 = idEntity::GetPhysics(this);
          v203 = (float *)v202->GetOrigin(this: v202, a2: 0);
          v204 = (float)(v203[2] + (float)v201);
          v205 = (float)(v203[1] + (float)v200);
          v240[0] = *v203 + (float)v199;
          v240[2] = v204;
          v240[1] = v205;
          v206 = idEntity::GetPhysics(this);
          v207 = (int)v206->GetOrigin(this: v206, a2: 0);
          v198->DebugLine(
            this: v198,
            a2: (const idVec4 *)&idColor::colorRed,
            a3: (const idVec3 *)v207,
            a4: (const idVec3 *)v240,
            a5: 0,
            a6: false);
        }
        v235.x = v235.x * (float)v126;
        v235.y = (float)v126 * v235.y;
        v235.z = (float)v126 * v235.z;
        v208 = idEntity::GetPhysics(this);
        v208->SetLinearVelocity(this: v208, a2: &v235, a3: 0);
        if ( g_projectileHomingGroundCheckDebug.valueInteger != 0 )
        {
          v209 = common->RW(this: common);
          v210 = (float)(v235.x * g_projectileHomingGroundCheck.valueFloat);
          v211 = (float)(v235.y * g_projectileHomingGroundCheck.valueFloat);
          v212 = (float)(v235.z * g_projectileHomingGroundCheck.valueFloat);
          v213 = idEntity::GetPhysics(this);
          v214 = (float *)v213->GetOrigin(this: v213, a2: 0);
          v215 = (float)(v214[2] + (float)v212);
          v216 = (float)(v214[1] + (float)v211);
          v242[0] = (float)v210 + *v214;
          v242[2] = v215;
          v242[1] = v216;
          v217 = idEntity::GetPhysics(this);
          v218 = (int)v217->GetOrigin(this: v217, a2: 0);
          v209->DebugLine(
            this: v209,
            a2: (const idVec4 *)&idColor::colorBlue,
            a3: (const idVec3 *)v218,
            a4: (const idVec3 *)v242,
            a5: 0,
            a6: false);
        }
        return;
      }
      v144 = 1.3;
    }
    else
    {
      v144 = 0.34999999;
    }
    v143 = (float)((float)((float)((float)((float)v140 * (float)v135) * (float)0.000030518509) - (float)v136)
                 * (float)v144);
    v142 = (float)((float)v142 * (float)v144);
    v141 = (float)((float)v141 * (float)v144);
    goto LABEL_93;
  }
}


// ========================================================================
// ?Explode@idProjectile_Homing@@UAAXPAVidEntity@@PAUtrace_t@@@Z
// EA  : 0x82EDB140
// RVA : 0x00EDB140
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Homing::Explode(idProjectile_Homing *this, idEntity *ent, trace_t *trace)
{
  idPresentable *presentable; // r3
  int v7; // r3
  int value; // r10
  idEntity *v9; // r3
  unsigned __int64 index; // r29
  idClientGame *v11; // r30
  double x; // fp0
  double y; // fp13
  double z; // fp12
  idClipQuery v15; // [sp+50h] [-C0h] BYREF
  trace_t v16; // [sp+60h] [-B0h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    v7 = (int)presentable->GetProjectileInterface(this: presentable);
  else
    v7 = 0;
  if ( *(_DWORD *)(v7 + 1252) != 5 )
  {
    if ( this->numSubMunitions > 0 )
      idProjectile_Homing::DisperseSubmunitions(this, ent);
    value = this->notifiedEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v9 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v9 != nullptr && idEntity::CastTo(c: v9) != nullptr )
        idProjectile_Homing::NotifyEntityAboutHoming(this, ent: nullptr, addNew: false);
    }
    index = this->deferredSurfTrace.index;
    v15.index = index;
    v11 = clientGame;
    if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &v15) != 0 )
    {
      idCollisionModelManager::GetContentsResult(
        this: collisionModelManager,
        result: &v16,
        query: &v11->clip.collisionQueries[index & 0xFFF].query,
        peek: false);
      x = v16.c.normal.x;
      y = v16.c.normal.y;
      z = v16.c.normal.z;
      this->surfTypeLastHit = v16.c.surfaceType;
      this->surfNormalLastHit.x = x;
      this->surfNormalLastHit.y = y;
      this->surfNormalLastHit.z = z;
    }
    idProjectile::Explode(this, ent: (idWaterEntity *)HIDWORD(index), trace);
  }
}


// ========================================================================
// ??1idProjectile_Homing@@UAA@XZ
// EA  : 0x82EDB290
// RVA : 0x00EDB290
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Homing::~idProjectile_Homing(idProjectile_Homing *this)
{
  int value; // r9
  idEntityPtr<idEntity> *p_notifiedEntity; // r30
  idEntity *v4; // r3
  idEntity *v5; // r3
  idEntity *v6; // r4

  this->__vftable = (idProjectile_Homing_vtbl *)&idProjectile_Homing::`vftable';
  value = this->notifiedEntity.spawnId.value;
  p_notifiedEntity = &this->notifiedEntity;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v4 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v4 != nullptr && idEntity::CastTo(c: v4) != nullptr )
    {
      if ( gameLocal->spawnIds.ptr[p_notifiedEntity->spawnId.value & 0x1FFF] == p_notifiedEntity->spawnId.value >> 13
        && (v5 = gameLocal->entities.ptr[p_notifiedEntity->spawnId.value & 0x1FFF]) != nullptr )
      {
        v6 = idEntity::CastTo(c: v5);
      }
      else
      {
        v6 = nullptr;
      }
      idProjectile_Homing::NotifyEntityAboutHoming(this, ent: v6, addNew: false);
    }
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->subMunitionProjectileList);
  idProjectile_Rocket::~idProjectile_Rocket(this);
}


// ========================================================================
// __unwind$507674
// EA  : 0x82EDB374
// RVA : 0x00EDB374
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_507674()
{
  int v0; // r12

  idProjectile_Rocket::~idProjectile_Rocket(this: *(idProjectile_Rocket **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$507675
// EA  : 0x82EDB39C
// RVA : 0x00EDB39C
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_507675()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 6256));
}


// ========================================================================
// ??0idProjectile_StickyBomb@@QAA@XZ
// EA  : 0x82EDB3D0
// RVA : 0x00EDB3D0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

idProjectile_StickyBomb *__fastcall idProjectile_StickyBomb::idProjectile_StickyBomb(idProjectile_StickyBomb *this)
{
  idProjectile::idProjectile(this);
  this->__vftable = (idProjectile_StickyBomb_vtbl *)&idProjectile_StickyBomb::`vftable';
  this->animHandle.value = -1;
  idAnimator_Channel::idAnimator_Channel(this: &this->animator);
  *(_WORD *)&this->useTeamColor = 1;
  this->explodeDelayTime = 20.0;
  this->ignoreEntity.spawnId.value = 0x1FFF;
  this->ignoreTimeout = 0;
  this->explodeTimer = 0;
  this->armed = false;
  idPhysics_RigidBody::idPhysics_RigidBody(this: &this->physicsObj);
  this->mpTriggerHalfWidth = 75.0;
  this->mpTriggerHeight = 75.0;
  return this;
}


// ========================================================================
// __unwind$507761
// EA  : 0x82EDB484
// RVA : 0x00EDB484
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_507761()
{
  int v0; // r12

  idProjectile::~idProjectile(this: *(idProjectile **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$507762
// EA  : 0x82EDB4AC
// RVA : 0x00EDB4AC
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_507762()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 5476));
}


// ========================================================================
// ?Think@idProjectile_StickyBomb@@UAAXXZ
// EA  : 0x82EDB590
// RVA : 0x00EDB590
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_StickyBomb::Think(idProjectile_StickyBomb *this)
{
  idPresentable *presentable; // r3
  idClipModel *v3; // r29
  int v4; // r3
  idPhysics *Physics; // r3
  const idVec3 *v6; // r3
  float x; // r6
  float y; // r5
  float z; // r4
  float *p_z; // r10
  idSysMutex *p_viewNoteMutex; // r11
  int v12; // ctr
  double mpTriggerHalfWidth; // fp13
  double mpTriggerHeight; // fp12
  idClipModel *v15; // r3
  idPhysics *v16; // r3
  idPhysics *v17; // r3
  idPhysics *v18; // r3
  idPhysics *v19; // r3
  _DWORD v20[6]; // [sp+58h] [-668h] BYREF
  idBounds v21; // [sp+70h] [-650h] BYREF
  idTraceModel v22; // [sp+90h] [-630h] BYREF

  presentable = this->presentable;
  v3 = nullptr;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetProjectileInterface(this: presentable);
  else
    v4 = 0;
  if ( *(_DWORD *)(v4 + 1252) == 1
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > this->explodeTimer )
  {
    this->Explode(this, a2: nullptr, a3: nullptr);
  }
  idProjectile::Think(this);
  if ( !this->armed )
  {
    if ( common->IsMultiplayer(this: common) )
    {
      if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > this->ignoreTimeout )
      {
        Physics = idEntity::GetPhysics(this);
        v6 = Physics->GetOrigin(this: Physics, a2: 0);
        x = v6->x;
        y = v6->y;
        z = v6->z;
        memset(&v22.type, 0, 20);
        p_z = &v22.offset.z;
        p_viewNoteMutex = &analysisClient.viewNoteMutex;
        v22.offset.x = 0.0;
        v22.offset.y = 0.0;
        v12 = 6;
        v22.offset.z = 0.0;
        *(float *)v20 = x;
        *(float *)&v20[1] = y;
        *(float *)&v20[2] = z;
        do
        {
          ++p_viewNoteMutex;
          *++p_z = *(float *)&p_viewNoteMutex->handle;
          --v12;
        }
        while ( v12 != 0 );
        mpTriggerHalfWidth = this->mpTriggerHalfWidth;
        v22.isConvex = false;
        mpTriggerHeight = this->mpTriggerHeight;
        v22.radius = 0.0;
        v22.pad[2] = 0;
        v21.b[0].z = 0.0;
        v22.pad[1] = 0;
        v21.b[1].y = mpTriggerHalfWidth;
        v22.pad[0] = 0;
        v21.b[1].z = mpTriggerHeight;
        v21.b[0].y = -mpTriggerHalfWidth;
        v21.b[1].x = mpTriggerHalfWidth;
        v21.b[0].x = v21.b[0].y;
        idTraceModel::SetupBox(this: &v22, boxBounds: &v21);
        v15 = (idClipModel *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0xD8u,
                               tag: TAG_CLIPMODEL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
        if ( v15 != nullptr )
          v3 = idClipModel::idClipModel(
                 this: v15,
                 clip: &clientGame->clip,
                 trm: &v22,
                 numTraceModels: 1,
                 material: nullptr);
        v16 = idEntity::GetPhysics(this);
        ((void (__fastcall *)(idPhysics *, idClipModel *, double))v16->SetClipModel)(
          a1: v16,
          a2: v3,
          a3: this->projectileDecl->notHitscanInfo.physicsProperties.density);
        v17 = idEntity::GetPhysics(this);
        v17->SetOrigin(this: v17, a2: (const idVec3 *)v20, a3: -1);
        idEntity::BecomeInactive(this, flags: 2);
        v18 = idEntity::GetPhysics(this);
        v18->SetContents(this: v18, a2: 0x4000, a3: -1);
        this->armed = true;
      }
    }
    else
    {
      v19 = idEntity::GetPhysics(this);
      v19->SetContents(this: v19, a2: 0x4000, a3: -1);
      this->armed = true;
    }
  }
}


// ========================================================================
// __unwind$507842
// EA  : 0x82EDB840
// RVA : 0x00EDB840
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_507842()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1728 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ??0idProjectile_Arrow@@QAA@XZ
// EA  : 0x82EDB878
// RVA : 0x00EDB878
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

idProjectile_Arrow *__fastcall idProjectile_Arrow::idProjectile_Arrow(idProjectile_Arrow *this)
{
  idProjectile::idProjectile(this);
  this->__vftable = (idProjectile_Arrow_vtbl *)&idProjectile_Arrow::`vftable';
  idPhysics_RigidBody::idPhysics_RigidBody(this: &this->physicsObj);
  this->inventoryItem = nullptr;
  this->stickChance = 75;
  this->breakable = nullptr;
  this->reflectionCosine = 0.75;
  this->breakChance = 25;
  this->electricBoltSystem = nullptr;
  this->electricShocks.list = nullptr;
  this->electricShocks.granularity = 0;
  this->electricShocks.memTag = 5;
  this->electricShocks.listStatic = 0;
  this->electricShocks.size = 0;
  this->electricShocks.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->electricShocks);
  this->electricTarget.list = nullptr;
  this->electricTarget.granularity = 0;
  this->electricTarget.memTag = 5;
  this->electricTarget.listStatic = 0;
  this->electricTarget.size = 0;
  this->electricTarget.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->electricTarget);
  this->stuckIn.spawnId.value = 0x1FFF;
  this->startElectricTime = 0;
  this->nextShockTime = 0;
  this->forceStick = false;
  this->electricPulseTime = 1000;
  this->electricShockDelay = 100;
  return this;
}


// ========================================================================
// __unwind$507971_0
// EA  : 0x82EDB950
// RVA : 0x00EDB950
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_507971_0()
{
  int v0; // r12

  idProjectile::~idProjectile(this: *(idProjectile **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$507972_0
// EA  : 0x82EDB978
// RVA : 0x00EDB978
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_507972_0()
{
  int v0; // r12

  idPhysics_RigidBody::~idPhysics_RigidBody(this: (idPhysics_RigidBody *)(*(_DWORD *)(v0 - 128 + 148) + 5472));
}


// ========================================================================
// __unwind$507973_0
// EA  : 0x82EDB9A4
// RVA : 0x00EDB9A4
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_507973_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 6120));
}


// ========================================================================
// ??1idProjectile_Arrow@@UAA@XZ
// EA  : 0x82EDB9F0
// RVA : 0x00EDB9F0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Arrow::~idProjectile_Arrow(idProjectile_Arrow *this)
{
  idList<idElectricBolt *,5> *p_electricShocks; // r30
  idElectricBolt *v3; // r29
  int num; // r11
  int v5; // r11
  bool v6; // zf
  int v7; // r10
  idElectricBolt **v8; // r9

  this->__vftable = (idProjectile_Arrow_vtbl *)&idProjectile_Arrow::`vftable';
  if ( this->electricShocks.num > 0 )
  {
    p_electricShocks = &this->electricShocks;
    do
    {
      idMD6Alias::~idMD6Alias(this: *(idMD6Alias **)p_electricShocks->list);
      v3 = *p_electricShocks->list;
      if ( v3 != nullptr )
      {
        idElectricBolt::~idElectricBolt(this: *p_electricShocks->list);
        idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
      }
      num = p_electricShocks->num;
      if ( num > 0 )
      {
        p_electricShocks->num = num - 1;
        v6 = num - 1 <= 0;
        v5 = 0;
        if ( !v6 )
        {
          v7 = 0;
          do
          {
            ++v5;
            v8 = &p_electricShocks->list[v7++];
            *v8 = v8[1];
          }
          while ( v5 < p_electricShocks->num );
        }
      }
    }
    while ( this->electricShocks.num > 0 );
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->electricTarget);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->electricShocks);
  idPhysics_RigidBody::~idPhysics_RigidBody(this: &this->physicsObj);
  idProjectile::~idProjectile(this);
}


// ========================================================================
// __unwind$508041_0
// EA  : 0x82EDBAD8
// RVA : 0x00EDBAD8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_508041_0()
{
  int v0; // r12

  idProjectile::~idProjectile(this: *(idProjectile **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$508042_0
// EA  : 0x82EDBB00
// RVA : 0x00EDBB00
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_508042_0()
{
  int v0; // r12

  idPhysics_RigidBody::~idPhysics_RigidBody(this: (idPhysics_RigidBody *)(*(_DWORD *)(v0 - 128 + 148) + 5472));
}


// ========================================================================
// __unwind$508043_0
// EA  : 0x82EDBB2C
// RVA : 0x00EDBB2C
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_508043_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 6120));
}


// ========================================================================
// __unwind$508044_0
// EA  : 0x82EDBB58
// RVA : 0x00EDBB58
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_508044_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 6136));
}


// ========================================================================
// ?Collide@idProjectile_Arrow@@UAA?AW4collide_t@@HAAUtrace_t@@ABVidVec3@@@Z
// EA  : 0x82EDBB88
// RVA : 0x00EDBB88
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idProjectile_Arrow::Collide(
        idProjectile_Arrow *this,
        const int physId,
        trace_t *collision,
        const idVec3 *velocity)
{
  idPresentable *presentable; // r3
  int v8; // r3
  __int64 v9; // r8
  int v10; // r6
  __int64 v11; // r10
  idProjectile_Arrow *v12; // r3
  weaponStatsTag_t weaponStatsTag; // r4
  idWaterEntity *v15; // r24
  char v16; // r11
  idPhysics *Physics; // r29
  int GameMs; // r27
  idPhysics *v19; // r3
  const idDeclProjectile *projectileDecl; // r26
  idAIEventManager *p_aiEventManager; // r29
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v23; // r25
  const idEntity *AttackerEntity; // r3
  const idPresentable *Attacker; // r3
  idPhysics *v26; // r3
  const idVec3 *v27; // r3
  double v28; // fp1
  weaponStatsTag_t v29; // r11
  double v30; // fp29
  char v31; // r11
  bool v32; // zf
  double x; // fp13
  double y; // fp12
  double z; // fp11
  double v36; // fp6
  double v37; // fp7
  double v38; // fp4
  double v39; // fp5
  double v40; // fp3
  double v41; // fp1
  double v42; // fp2
  double v43; // fp0
  const idDeclProjectile *v44; // r29
  idPhysics_RigidBody *p_physicsObj; // r26
  idProjectile_Arrow_vtbl *v46; // r11
  idPhysics *v47; // r3
  idPhysics *v48; // r3
  __int128 v49; // r7 OVERLAPPED
  int v50; // r8
  char v51; // r27
  double v54; // fp3
  double v55; // fp9
  double v56; // fp6
  idActor *v57; // r3
  idPhysics *v58; // r21
  idPhysics *v59; // r20
  float *v60; // r3
  double v61; // fp7
  double v62; // fp11
  double v63; // fp5
  double v64; // fp3
  double v65; // fp6
  double v67; // fp4
  double v69; // fp0
  double v70; // fp0
  double v71; // fp7
  double v72; // fp5
  __int64 v73; // r10
  __int128 v74; // r7 OVERLAPPED
  int v75; // r8
  int v76; // r3
  idPresentable *v77; // r11
  int v78; // r30
  idPhysics_RigidBody *v79; // r3
  idPhysics_RigidBody_vtbl *v80; // r31
  int v81; // r3
  __int64 v82; // [sp+8h] [-198h]
  __int64 v83; // [sp+8h] [-198h]
  __int64 v84; // [sp+10h] [-190h]
  __int64 v85; // [sp+10h] [-190h]
  __int64 v86; // [sp+18h] [-188h]
  __int64 v87; // [sp+18h] [-188h]
  __int64 v88; // [sp+20h] [-180h]
  __int64 v89; // [sp+20h] [-180h]
  __int64 v90; // [sp+28h] [-178h]
  __int64 v91; // [sp+28h] [-178h]
  __int64 v92; // [sp+30h] [-170h]
  __int64 v93; // [sp+30h] [-170h]
  __int64 v94; // [sp+38h] [-168h]
  __int64 v95; // [sp+38h] [-168h]
  __int64 v96; // [sp+40h] [-160h]
  __int64 v97; // [sp+40h] [-160h]
  int v98; // [sp+50h] [-150h] BYREF
  float v99[4]; // [sp+58h] [-148h] BYREF
  float v100[4]; // [sp+68h] [-138h] BYREF
  float v101[4]; // [sp+78h] [-128h] BYREF
  float v102[4]; // [sp+88h] [-118h] BYREF
  float v103[4]; // [sp+98h] [-108h] BYREF
  float v104[4]; // [sp+A8h] [-F8h] BYREF
  float v105[6]; // [sp+B8h] [-E8h] BYREF
  float v106[4]; // [sp+D0h] [-D0h] BYREF
  float v107[4]; // [sp+E0h] [-C0h] BYREF
  float v108[4]; // [sp+F0h] [-B0h] BYREF
  int v109; // [sp+100h] [-A0h] BYREF
  float v110; // [sp+104h] [-9Ch]
  __int64 v111; // [sp+108h] [-98h]
  int v112; // [sp+110h] [-90h]
  idAIEventManager v113; // [sp+114h] [-8Ch] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    v8 = (int)presentable->GetProjectileInterface(this: presentable);
  else
    v8 = 0;
  if ( *(_DWORD *)(v8 + 1252) == 1 )
  {
    idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
    LODWORD(v11) = collision->c.surfaceFlags & 1;
    if ( (_DWORD)v11 != 0 )
    {
      v12 = this;
      goto LABEL_7;
    }
    weaponStatsTag = this->weaponStatsTag;
    v15 = (idWaterEntity *)gameLocal->entities.ptr[collision->c.entityNum];
    v98 = 0;
    if ( (*(_DWORD *)&weaponStatsTag & 0xFC000000) != 0
      || (*(_DWORD *)&weaponStatsTag & 0x3C00000) != 0
      || (v16 = 0, (*(_DWORD *)&weaponStatsTag & 0x3FFFFF) != 0) )
    {
      v16 = 1;
    }
    if ( v16 != 0 )
      idGameLocal::SetCurrentStatsDamage(
        this: gameLocal,
        tag: *(weaponStatsTag_t **)&weaponStatsTag,
        delayedCount: &v98);
    Physics = idEntity::GetPhysics(this);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v19 = Physics;
    projectileDecl = this->projectileDecl;
    GetOrigin = Physics->GetOrigin;
    p_aiEventManager = &gameLocal->aiEventManager;
    v23 = GetOrigin(this: v19, a2: 0);
    AttackerEntity = idProjectile::GetAttackerEntity(this);
    idAIEventManager::AddEvent(
      this: &v113,
      result: p_aiEventManager,
      eventDecl: projectileDecl->collideAIEventDecl,
      curTime: GameMs,
      originator: this,
      instigator: AttackerEntity,
      origin: v23,
      delay: 500);
    Attacker = idProjectile::GetAttacker(this);
    idClientGame::ProjectileImpact(
      this: clientGame,
      trace: collision,
      attacker: Attacker,
      projDef: this->projectileDecl,
      tracerFired: false,
      noDecals: false,
      noSounds: false);
    v26 = idEntity::GetPhysics(this);
    v27 = (const idVec3 *)v26->GetAxis(this: v26, a2: 0);
    v28 = idProjectile_Arrow::CheckDoDamage(this, ent: v15, dir: v27, trace: collision);
    v29 = this->weaponStatsTag;
    v30 = v28;
    if ( (*(_DWORD *)&v29 & 0xFC000000) != 0
      || (*(_DWORD *)&v29 & 0x3C00000) != 0
      || (v32 = (*(_DWORD *)&v29 & 0x3FFFFF) == 0, v31 = 0, !v32) )
    {
      v31 = 1;
    }
    if ( v31 != 0 )
    {
      idGameLocal::ClearCurrentStatsDamage(this: gameLocal);
      idGameLocal::WeaponFiredDone(
        this: gameLocal,
        tag: *(weaponStatsTag_t **)&this->weaponStatsTag,
        carryoverCount: v98);
    }
    if ( g_debugWeapon.valueInteger != 0 )
    {
      if ( collision->fraction >= 1.0 )
      {
        idLib::Warning(fmt: "idProjectile_Arrow got Collide with collision.fraction >= 1.0f");
      }
      else
      {
        x = collision->c.point.x;
        y = collision->c.point.y;
        z = collision->c.point.z;
        v106[0] = 1.0;
        v106[3] = 1.0;
        v106[1] = 0.0;
        v106[2] = 0.0;
        v101[0] = (float)x + (float)4.0;
        v101[1] = y;
        v101[2] = z;
        v105[0] = (float)x - (float)4.0;
        v105[1] = y;
        v105[2] = z;
        clientGame->renderWorld->DebugLine(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)v106,
          a3: (const idVec3 *)v105,
          a4: (const idVec3 *)v101,
          a5: 5000,
          a6: true);
        v36 = (float)(collision->c.point.y + (float)4.0);
        v37 = collision->c.point.x;
        v38 = (float)(collision->c.point.y - (float)4.0);
        v39 = collision->c.point.z;
        v107[0] = 1.0;
        v107[1] = 0.0;
        v107[2] = 0.0;
        v107[3] = 1.0;
        v103[0] = v37;
        v103[1] = v36;
        v103[2] = v39;
        v104[0] = v37;
        v104[1] = v38;
        v104[2] = v39;
        clientGame->renderWorld->DebugLine(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)v107,
          a3: (const idVec3 *)v104,
          a4: (const idVec3 *)v103,
          a5: 5000,
          a6: true);
        v40 = collision->c.point.z;
        v41 = (float)(collision->c.point.z + (float)4.0);
        v108[0] = 1.0;
        v108[3] = 1.0;
        v42 = collision->c.point.x;
        v43 = collision->c.point.y;
        v108[1] = 0.0;
        v108[2] = 0.0;
        v99[0] = v42;
        v99[1] = v43;
        v99[2] = v41;
        v100[0] = v42;
        v100[1] = v43;
        v100[2] = (float)v40 - (float)4.0;
        clientGame->renderWorld->DebugLine(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)v108,
          a3: (const idVec3 *)v100,
          a4: (const idVec3 *)v99,
          a5: 5000,
          a6: true);
      }
    }
    v44 = this->projectileDecl;
    if ( v44->electricDamageDecl != nullptr )
      this->electricDischarged = true;
    p_physicsObj = &this->physicsObj;
    idPhysics_RigidBody::SetFriction(
      this: &this->physicsObj,
      linear: v44->notHitscanInfo.physicsProperties.linearFriction,
      angular: v44->notHitscanInfo.physicsProperties.angularFriction,
      contact: v44->notHitscanInfo.physicsProperties.contactFriction);
    idPhysics_RigidBody::SetWaterFriction(
      this: &this->physicsObj,
      linear: v44->notHitscanInfo.physicsProperties.linearFrictionWater,
      angular: v44->notHitscanInfo.physicsProperties.angularFrictionWater);
    v46 = this->__vftable;
    if ( v44->notHitscanInfo.explodeOnImpact )
    {
      v46->Explode(this, a2: v15, a3: collision);
      return 1;
    }
    HIDWORD(v11) = v46->ShouldRemoveOnCollision(this, a2: collision, a3: v30);
    v12 = this;
    if ( HIDWORD(v11) != 0 )
    {
LABEL_7:
      idEventReceiver::PostEventMS(this: v12, ev: &EV_Remove, time: 0, a4: v10, a5: v9, a6: v11);
      return 1;
    }
    this->alignToVelocity = false;
    if ( idEntity::GetPhysics(this) != nullptr )
    {
      v47 = idEntity::GetPhysics(this);
      if ( v47->GetClipModel(this: v47, a2: 0) != nullptr )
      {
        v48 = idEntity::GetPhysics(this);
        v48->GetClipModel(this: v48, a2: 0)->ownerNumber = 0x1FFF;
      }
    }
    HIBYTE(v109) = 105;
    LODWORD(v110) = 89;
    DWORD1(v49) = v109;
    *((_QWORD *)&v49 + 1) = v111;
    v50 = __ROL4__(v112, 32);
    idEventReceiver::PostEventMS(
      this,
      ev: &EV_StopFX,
      arg1: *(__int64 *)((char *)&v49 + 4),
      a4: *(__int64 *)((char *)&v49 - 4),
      a5: 0x5900000069LL,
      a6: v82,
      a7: v84,
      a8: v86,
      a9: v88,
      a10: v90,
      a11: v92,
      a12: v94,
      a13: v96);
    v51 = 0;
    _FP6 = (float)((float)((float)(velocity->z * velocity->z)
                         + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f4, f6, f7, f0 }
    v54 = __frsqrte(_FP4);
    v55 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v54
                                                                                        * (float)((float)((float)(velocity->z * velocity->z) + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y)))
                                                                                                * (float)0.5))
                                                                                * (float)v54)
                                                                        - (float)1.5)
                                                        * (float)v54)
                                                * (float)((float)((float)(velocity->z * velocity->z)
                                                                + (float)((float)(velocity->x * velocity->x)
                                                                        + (float)(velocity->y * velocity->y)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v54
                                                                                * (float)((float)((float)(velocity->z * velocity->z)
                                                                                                + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y)))
                                                                                        * (float)0.5))
                                                                        * (float)v54)
                                                                - (float)1.5)
                                                * (float)v54))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v54
                                                        * (float)((float)((float)(velocity->z * velocity->z)
                                                                        + (float)((float)(velocity->x * velocity->x)
                                                                                + (float)(velocity->y * velocity->y)))
                                                                * (float)0.5))
                                                * (float)v54)
                                        - (float)1.5)
                        * (float)v54));
    v56 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v54 * (float)((float)((float)(velocity->z * velocity->z) + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y))) * (float)0.5)) * (float)v54) - (float)1.5)
                                                                                        * (float)v54)
                                                                                * (float)((float)((float)(velocity->z * velocity->z)
                                                                                                + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y)))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v54 * (float)((float)((float)(velocity->z * velocity->z) + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y))) * (float)0.5)) * (float)v54)
                                                                                                - (float)1.5)
                                                                                * (float)v54))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v54
                                                                                        * (float)((float)((float)(velocity->z * velocity->z) + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y)))
                                                                                                * (float)0.5))
                                                                                * (float)v54)
                                                                        - (float)1.5)
                                                        * (float)v54))
                                        * (float)((float)((float)(velocity->z * velocity->z)
                                                        + (float)((float)(velocity->x * velocity->x)
                                                                + (float)(velocity->y * velocity->y)))
                                                * (float)0.5))
                                * (float)v55)
                        - (float)1.5);
    if ( (float)((float)((float)v56
                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v54 * (float)((float)((float)(velocity->z * velocity->z) + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y))) * (float)0.5))
                                                                                               * (float)v54)
                                                                                       - (float)1.5)
                                                                       * (float)v54)
                                                               * (float)((float)((float)(velocity->z * velocity->z)
                                                                               + (float)((float)(velocity->x
                                                                                               * velocity->x)
                                                                                       + (float)(velocity->y
                                                                                               * velocity->y)))
                                                                       * (float)0.5))
                                                       * (float)((float)-(float)((float)((float)((float)v54
                                                                                               * (float)((float)((float)(velocity->z * velocity->z) + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y))) * (float)0.5))
                                                                                       * (float)v54)
                                                                               - (float)1.5)
                                                               * (float)v54))
                                               - (float)1.5)
                               * (float)((float)-(float)((float)((float)((float)v54
                                                                       * (float)((float)((float)(velocity->z
                                                                                               * velocity->z)
                                                                                       + (float)((float)(velocity->x * velocity->x)
                                                                                               + (float)(velocity->y * velocity->y)))
                                                                               * (float)0.5))
                                                               * (float)v54)
                                                       - (float)1.5)
                                       * (float)v54)))
               * (float)((float)(velocity->z * velocity->z)
                       + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y)))) >= 850.0
      && this->ShouldStickOnCollision(this, a2: collision) )
    {
      v51 = 1;
      idProjectile::SetState(this, state: STUCK);
      if ( (unsigned __int8)idWorldspawn::IsTypeOf(c: v15) != 0
        || (unsigned __int8)idStaticEntity::IsTypeOf(c: v15) != 0 )
      {
        v58 = idEntity::GetPhysics(this);
        v59 = idEntity::GetPhysics(this);
        v60 = (float *)v58->GetOrigin(this: v58, a2: 0);
        v61 = (float)(v60[1] - collision->c.point.y);
        v62 = collision->c.point.z;
        v63 = (float)(v60[2] - collision->c.point.z);
        v64 = (float)(*v60 - collision->c.point.x);
        v65 = (float)((float)((float)v64 * (float)v64)
                    + (float)((float)((float)v63 * (float)v63) + (float)((float)v61 * (float)v61)));
        v67 = (float)((float)((float)((float)v64 * (float)v64)
                            + (float)((float)((float)v63 * (float)v63) + (float)((float)v61 * (float)v61)))
                    * (float)0.5);
        _FP5 = (float)((float)((float)((float)v64 * (float)v64)
                             + (float)((float)((float)v63 * (float)v63) + (float)((float)v61 * (float)v61)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f3, f5, f6, f0 }
        v69 = __frsqrte(_FP3);
        v70 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v69 * (float)v67) * (float)v69) - (float)1.5) * (float)v69) * (float)v67)
                                                                                            * (float)((float)-(float)((float)((float)((float)v69 * (float)v67) * (float)v69) - (float)1.5) * (float)v69))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v69 * (float)v67) * (float)v69)
                                                                                            - (float)1.5)
                                                                            * (float)v69))
                                                            * (float)v67)
                                                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v69 * (float)v67) * (float)v69) - (float)1.5) * (float)v69)
                                                                                            * (float)v67)
                                                                                    * (float)((float)-(float)((float)((float)((float)v69 * (float)v67) * (float)v69) - (float)1.5)
                                                                                            * (float)v69))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v69 * (float)v67)
                                                                                            * (float)v69)
                                                                                    - (float)1.5)
                                                                    * (float)v69)))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v69 * (float)v67) * (float)v69)
                                                                                            - (float)1.5)
                                                                            * (float)v69)
                                                                    * (float)v67)
                                                            * (float)((float)-(float)((float)((float)((float)v69 * (float)v67)
                                                                                            * (float)v69)
                                                                                    - (float)1.5)
                                                                    * (float)v69))
                                                    - (float)1.5)
                                    * (float)((float)-(float)((float)((float)((float)v69 * (float)v67) * (float)v69)
                                                            - (float)1.5)
                                            * (float)v69)))
                    * (float)v65);
        v71 = (float)(collision->c.normal.z * (float)((float)v70 * (float)0.25));
        v72 = (float)(collision->c.point.y + (float)(collision->c.normal.y * (float)((float)v70 * (float)0.25)));
        v102[0] = collision->c.point.x + (float)(collision->c.normal.x * (float)((float)v70 * (float)0.25));
        v102[1] = v72;
        v102[2] = (float)v62 + (float)v71;
        v59->SetOrigin(this: v59, a2: (const idVec3 *)v102, a3: -1);
      }
      else if ( this->Attach(this, a2: v15, a3: collision) )
      {
        v57 = idActor::CastTo(c: (idActor *)v15);
        if ( v57 != nullptr )
          idActor::SetLooted(this: v57, b: false);
      }
      else
      {
        idLib::Warning(fmt: " arrow stick failed ");
        v51 = 0;
      }
    }
    v110 = 1.0;
    LODWORD(v73) = &v109;
    HIBYTE(v109) = 102;
    HIDWORD(v73) = &idTarget_SoundDuck::Type.node;
    DWORD1(v74) = v109;
    *((_QWORD *)&v74 + 1) = v111;
    v75 = __ROL4__(v112, 32);
    idEventReceiver::PostEventMS(
      this,
      ev: &EV_FadeOut,
      arg1: *(__int64 *)((char *)&v74 + 4),
      a4: *(__int64 *)((char *)&v74 - 4),
      a5: v73,
      a6: v83,
      a7: v85,
      a8: v87,
      a9: v89,
      a10: v91,
      a11: v93,
      a12: v95,
      a13: v97);
    if ( (unsigned __int8)idProjectile_Arrow::ShouldBreak(this) != 0 )
      this->Break(this, a2: v15, a3: collision);
    if ( v51 != 0 )
      return 1;
    idProjectile::SetState(this, state: BOUNCING);
    v76 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v77 = this->presentable;
    v78 = v76;
    if ( v77 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v77 = this->presentable;
    }
    idFXManager::StopFX(this: &v77->fxManager, time: v78, stopCondition: 89, immediateStop: false);
    p_physicsObj->SetGravity(this: &this->physicsObj, a2: &gameLocal->clientGame.gravity);
    v79 = &this->physicsObj;
    v80 = p_physicsObj->__vftable;
    v81 = p_physicsObj->GetClipMask(this: v79, a2: -1);
    v80->SetClipMask(this: p_physicsObj, a2: v81 & 0xFFFFFF7F, a3: -1);
  }
  return 0;
}


// ========================================================================
// ??0idProjectile_Dagger@@QAA@XZ
// EA  : 0x82EDC3D8
// RVA : 0x00EDC3D8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

idProjectile_Dagger *__fastcall idProjectile_Dagger::idProjectile_Dagger(idProjectile_Dagger *this)
{
  idProjectile_Arrow::idProjectile_Arrow(this);
  this->__vftable = (idProjectile_Dagger_vtbl *)&idProjectile_Dagger::`vftable';
  this->zUp = true;
  this->originOffset.x = 0.0;
  this->originOffset.y = 0.0;
  this->originOffset.z = 0.0;
  return this;
}


// ========================================================================
// ??0idProjectile_Grenade@@QAA@XZ
// EA  : 0x82EDC438
// RVA : 0x00EDC438
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

idProjectile_Grenade *__fastcall idProjectile_Grenade::idProjectile_Grenade(idProjectile_Grenade *this)
{
  int v2; // ctr
  int *p_nextBounceTime; // r8
  float *p_y; // r9

  idProjectile::idProjectile(this);
  this->explodeOnVehicles = false;
  this->attractToPowerDist = 300.0;
  this->startDetonationTime = -1;
  this->__vftable = (idProjectile_Grenade_vtbl *)&idProjectile_Grenade::`vftable';
  this->detonationTime = -1;
  this->stickOnImpact = false;
  this->stickToActors = false;
  this->explodeOnActors = false;
  this->explodeOnImpact = false;
  this->numSubMunitions = 0;
  this->subMunitionProjectileList.list = nullptr;
  this->subMunitionProjectileList.granularity = 0;
  this->subMunitionProjectileList.memTag = 5;
  this->subMunitionProjectileList.listStatic = 0;
  this->subMunitionProjectileList.size = 0;
  this->subMunitionProjectileList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->subMunitionProjectileList);
  this->randomSubMunitions = false;
  *(_WORD *)&this->pairedSubMunitionVels = 0;
  this->icon = nullptr;
  this->subMunitionMaxAngle = 90.0;
  idPhysics_RigidBody3DOF::idPhysics_RigidBody3DOF(this: &this->physicsObj);
  v2 = 9;
  p_nextBounceTime = &this->nextBounceTime;
  p_y = &mat2_identity.mat[1].y;
  this->lastCollisionNormal = vec3_origin;
  this->nextBounceTime = 0;
  do
  {
    *++p_nextBounceTime = *(_DWORD *)++p_y;
    --v2;
  }
  while ( v2 != 0 );
  this->numBounces = 0;
  this->playerEventHandle.value = -1;
  this->splashVelocity = vec3_origin;
  this->deferredSurfTrace.index = 0xFFFFFFFF00000000uLL;
  this->isInWater = false;
  *(_QWORD *)&this->empStuckToSound = 0;
  this->powerSourceToMoveTo = nullptr;
  this->causesDirectDamage = false;
  return this;
}


// ========================================================================
// __unwind$508554
// EA  : 0x82EDC57C
// RVA : 0x00EDC57C
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_508554()
{
  int v0; // r12

  idProjectile::~idProjectile(this: *(idProjectile **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$508555
// EA  : 0x82EDC5A4
// RVA : 0x00EDC5A4
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_508555()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5496));
}


// ========================================================================
// ??1idProjectile_Grenade@@UAA@XZ
// EA  : 0x82EDC5D8
// RVA : 0x00EDC5D8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Grenade::~idProjectile_Grenade(idProjectile_Grenade *this)
{
  this->__vftable = (idProjectile_Grenade_vtbl *)&idProjectile_Grenade::`vftable';
  idProjectile_Grenade::RemoveAIEvents(this);
  idProjectile::Detach(this);
  idPhysics_RigidBody3DOF::~idPhysics_RigidBody3DOF(this: &this->physicsObj);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->subMunitionProjectileList);
  idProjectile::~idProjectile(this);
}


// ========================================================================
// __unwind$508595
// EA  : 0x82EDC640
// RVA : 0x00EDC640
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_508595()
{
  int v0; // r12

  idProjectile::~idProjectile(this: *(idProjectile **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$508596
// EA  : 0x82EDC668
// RVA : 0x00EDC668
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_508596()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 5496));
}


// ========================================================================
// __unwind$508597
// EA  : 0x82EDC694
// RVA : 0x00EDC694
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_508597()
{
  int v0; // r12

  idPhysics_RigidBody3DOF::~idPhysics_RigidBody3DOF(this: (idPhysics_RigidBody3DOF *)(*(_DWORD *)(v0 - 112 + 132) + 5528));
}


// ========================================================================
// ?Think@idProjectile_Grenade@@UAAXXZ
// EA  : 0x82EDC6C8
// RVA : 0x00EDC6C8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Grenade::Think(idProjectile_Grenade *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPresentable *presentable; // r3
  int v5; // r3
  idPresentable *v6; // r3
  int v7; // r3
  idPresentable *v8; // r3
  int v9; // r3
  const idDeclProjectile *projectileDecl; // r11
  idSoundShader *warningSound; // r10
  int v12; // r29
  idPresentable *v13; // r3
  int v14; // r3
  idRegimeTile *v15; // r3
  idEntity *powerSourceToMoveTo; // r3
  idPhysics *Physics; // r26
  idPhysics *v18; // r3
  float *v19; // r25
  float *v20; // r3
  double v21; // fp8
  double v22; // fp7
  double v23; // fp6
  double v26; // fp13
  double v27; // fp3
  double v28; // fp29
  double v29; // fp28
  double v30; // fp27
  idPhysics *v31; // r3
  const idDeclProjectile *v32; // r6
  double v33; // fp12
  idPhysics *v34; // r3
  double v37; // fp3
  double v38; // fp6
  double v39; // fp5
  double v40; // fp3
  double v41; // fp13
  double v42; // fp12
  double v43; // fp0
  char v44; // r11
  idPhysics *v45; // r3
  idPhysics *v46; // r3
  int v47; // r29
  idPhysics *v48; // r26
  idPhysics *v49; // r25
  idPhysics *v50; // r24
  int entityNumber; // r23
  double v52; // fp31
  double v53; // fp30
  double v54; // fp29
  float *v55; // r3
  double v56; // fp8
  double v57; // fp6
  idClipModel *v58; // r26
  const idVec3 *v59; // r3
  int v60; // [sp+8h] [-138h]
  bool v61; // [sp+Fh] [-131h]
  const char *v62; // [sp+10h] [-130h]
  int v63; // [sp+14h] [-12Ch]
  int v64; // [sp+18h] [-128h]
  int v65; // [sp+1Ch] [-124h]
  int v66; // [sp+20h] [-120h]
  int v67; // [sp+24h] [-11Ch]
  int v68; // [sp+28h] [-118h]
  int v69; // [sp+2Ch] [-114h]
  int v70; // [sp+30h] [-110h]
  int v71; // [sp+34h] [-10Ch]
  int v72; // [sp+38h] [-108h]
  int v73; // [sp+3Ch] [-104h]
  int v74; // [sp+40h] [-100h]
  int v75; // [sp+44h] [-FCh]
  int v76; // [sp+48h] [-F8h]
  int v77; // [sp+4Ch] [-F4h]
  int v78; // [sp+50h] [-F0h]
  int v79; // [sp+58h] [-E8h]
  int v80; // [sp+60h] [-E0h]
  const idDeclProjectile *v81; // [sp+70h] [-D0h] BYREF
  idPLogScope v82; // [sp+78h] [-C8h] BYREF
  float v83; // [sp+80h] [-C0h] BYREF
  float v84; // [sp+84h] [-BCh]
  float v85; // [sp+88h] [-B8h]
  float v86[4]; // [sp+90h] [-B0h] BYREF
  idVec3 v87; // [sp+A0h] [-A0h] BYREF
  idList<idVehicleState *,5> v88[4]; // [sp+B0h] [-90h] BYREF

  RD_EventBegin(name: "idProjectile_Grenade::Think");
  LODWORD(v2) = "idProjectile_Grenade::Think";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v82, pl: &pLog, gMask: v2, label: v3);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetProjectileInterface(this: presentable);
  else
    v5 = 0;
  if ( *(_DWORD *)(v5 + 1252) == 1
    || ((v6 = this->presentable) == nullptr ? (v7 = 0) : (v7 = (int)v6->GetProjectileInterface(this: v6)),
        *(_DWORD *)(v7 + 1252) == 3) )
  {
    if ( this->detonationTime < 0
      || this->detonationTime > idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
    {
      v8 = this->presentable;
      if ( v8 != nullptr )
        v9 = (int)v8->GetProjectileInterface(this: v8);
      else
        v9 = 0;
      if ( *(_BYTE *)(v9 + 1264) == 0 && this->detonationTime >= 0 )
      {
        projectileDecl = this->projectileDecl;
        warningSound = projectileDecl->notHitscanInfo.grenadeInfo.warningSound;
        v81 = projectileDecl;
        if ( warningSound != nullptr )
        {
          v81 = projectileDecl;
          v12 = this->detonationTime - idSoundShader::GetMaxLength(this: warningSound);
          if ( v12 <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
          {
            v13 = this->presentable;
            if ( v13 != nullptr )
              v14 = (int)v13->GetProjectileInterface(this: v13);
            else
              v14 = 0;
            *(_BYTE *)(v14 + 1264) = 1;
            idEntity::StartSoundShader(
              this,
              channel: SND_CHANNEL_BODY3,
              shader: this->projectileDecl->notHitscanInfo.grenadeInfo.warningSound,
              soundShaderFlags: (soundShaderFlags_t)0,
              peerMask: 0xFFu);
          }
        }
      }
    }
    else
    {
      this->Explode(this, a2: nullptr, a3: nullptr);
    }
  }
  memset(v88, 0, 14);
  v88[0].memTag = 5;
  v88[0].listStatic = 0;
  idList<idThread *,58>::Clear(this: v88);
  v15 = idRegimeTile::CastTo(c: (idRegimeTile *)this->powerSourceToMoveTo);
  if ( v15 != nullptr && !v15->powered )
  {
    this->powerSourceToMoveTo = nullptr;
    if ( idProjectile::GetState(this) != ACTIVE )
      idProjectile::SetState(this, state: ACTIVE);
  }
  powerSourceToMoveTo = this->powerSourceToMoveTo;
  if ( powerSourceToMoveTo != nullptr )
  {
    Physics = idEntity::GetPhysics(this: powerSourceToMoveTo);
    v18 = idEntity::GetPhysics(this);
    v19 = (float *)v18->GetOrigin(this: v18, a2: 0);
    v20 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
    v21 = (float)((float)((float)(v20[1] + v20[4]) * (float)0.5) - v19[1]);
    v22 = (float)((float)((float)(*v20 + v20[3]) * (float)0.5) - *v19);
    v23 = (float)((float)((float)(v20[2] + v20[5]) * (float)0.5) - v19[2]);
    _FP2 = (float)((float)((float)((float)v23 * (float)v23)
                         + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f0, f2, f3, f0 }
    v26 = __frsqrte(_FP0);
    v27 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v26
                                                                                        * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21)))
                                                                                                * (float)0.5))
                                                                                * (float)v26)
                                                                        - (float)1.5)
                                                        * (float)v26)
                                                * (float)((float)((float)((float)v23 * (float)v23)
                                                                + (float)((float)((float)v22 * (float)v22)
                                                                        + (float)((float)v21 * (float)v21)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v26
                                                                                * (float)((float)((float)((float)v23 * (float)v23)
                                                                                                + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21)))
                                                                                        * (float)0.5))
                                                                        * (float)v26)
                                                                - (float)1.5)
                                                * (float)v26))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v26
                                                        * (float)((float)((float)((float)v23 * (float)v23)
                                                                        + (float)((float)((float)v22 * (float)v22)
                                                                                + (float)((float)v21 * (float)v21)))
                                                                * (float)0.5))
                                                * (float)v26)
                                        - (float)1.5)
                        * (float)v26));
    v28 = (float)((float)v22
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v26 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)v26) - (float)1.5) * (float)v26)
                                                                                                * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v26 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)v26) - (float)1.5)
                                                                                                * (float)v26))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v26 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))) * (float)0.5))
                                                                                                * (float)v26)
                                                                                        - (float)1.5)
                                                                        * (float)v26))
                                                        * (float)((float)((float)((float)v23 * (float)v23)
                                                                        + (float)((float)((float)v22 * (float)v22)
                                                                                + (float)((float)v21 * (float)v21)))
                                                                * (float)0.5))
                                                * (float)v27)
                                        - (float)1.5)
                        * (float)v27));
    v29 = (float)((float)v21
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v26 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)v26) - (float)1.5) * (float)v26)
                                                                                                * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v26 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)v26) - (float)1.5)
                                                                                                * (float)v26))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v26 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))) * (float)0.5))
                                                                                                * (float)v26)
                                                                                        - (float)1.5)
                                                                        * (float)v26))
                                                        * (float)((float)((float)((float)v23 * (float)v23)
                                                                        + (float)((float)((float)v22 * (float)v22)
                                                                                + (float)((float)v21 * (float)v21)))
                                                                * (float)0.5))
                                                * (float)v27)
                                        - (float)1.5)
                        * (float)v27));
    v30 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v26 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)v26) - (float)1.5) * (float)v26)
                                                                                                * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v26 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)v26) - (float)1.5)
                                                                                                * (float)v26))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v26 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))) * (float)0.5))
                                                                                                * (float)v26)
                                                                                        - (float)1.5)
                                                                        * (float)v26))
                                                        * (float)((float)((float)((float)v23 * (float)v23)
                                                                        + (float)((float)((float)v22 * (float)v22)
                                                                                + (float)((float)v21 * (float)v21)))
                                                                * (float)0.5))
                                                * (float)v27)
                                        - (float)1.5)
                        * (float)v27)
                * (float)v23);
    v31 = idEntity::GetPhysics(this);
    v32 = this->projectileDecl;
    v33 = (float)(v32->notHitscanInfo.speed * (float)1.5);
    v86[2] = (float)v30 * (float)(v32->notHitscanInfo.speed * (float)1.5);
    v86[1] = (float)v29 * (float)v33;
    v86[0] = (float)v33 * (float)v28;
    v31->SetLinearVelocity(this: v31, a2: (const idVec3 *)v86, a3: 0);
  }
  v34 = idEntity::GetPhysics(this);
  v34->GetLinearVelocity(this: (idPhysics *)&v83, result: (idVec3 *)v34, a3: 0);
  _FP6 = (float)((float)((float)(v84 * v84) + (float)((float)(v83 * v83) + (float)(v85 * v85)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f4, f6, f7, f13 }
  v37 = __frsqrte(_FP4);
  v38 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v37
                                                                                      * (float)((float)((float)(v84 * v84) + (float)((float)(v83 * v83) + (float)(v85 * v85)))
                                                                                              * (float)0.5))
                                                                              * (float)v37)
                                                                      - (float)1.5)
                                                      * (float)v37)
                                              * (float)((float)((float)(v84 * v84)
                                                              + (float)((float)(v83 * v83) + (float)(v85 * v85)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v37
                                                                              * (float)((float)((float)(v84 * v84)
                                                                                              + (float)((float)(v83 * v83) + (float)(v85 * v85)))
                                                                                      * (float)0.5))
                                                                      * (float)v37)
                                                              - (float)1.5)
                                              * (float)v37))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v37
                                                      * (float)((float)((float)(v84 * v84)
                                                                      + (float)((float)(v83 * v83) + (float)(v85 * v85)))
                                                              * (float)0.5))
                                              * (float)v37)
                                      - (float)1.5)
                      * (float)v37));
  v39 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v37
                                                                                              * (float)((float)((float)(v84 * v84) + (float)((float)(v83 * v83) + (float)(v85 * v85))) * (float)0.5))
                                                                                      * (float)v37)
                                                                              - (float)1.5)
                                                              * (float)v37)
                                                      * (float)((float)((float)(v84 * v84)
                                                                      + (float)((float)(v83 * v83) + (float)(v85 * v85)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v37
                                                                                      * (float)((float)((float)(v84 * v84) + (float)((float)(v83 * v83) + (float)(v85 * v85)))
                                                                                              * (float)0.5))
                                                                              * (float)v37)
                                                                      - (float)1.5)
                                                      * (float)v37))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v37
                                                              * (float)((float)((float)(v84 * v84)
                                                                              + (float)((float)(v83 * v83)
                                                                                      + (float)(v85 * v85)))
                                                                      * (float)0.5))
                                                      * (float)v37)
                                              - (float)1.5)
                              * (float)v37))
              * (float)((float)((float)(v84 * v84) + (float)((float)(v83 * v83) + (float)(v85 * v85))) * (float)0.5));
  v40 = (float)((float)-(float)((float)((float)v39
                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v37 * (float)((float)((float)(v84 * v84) + (float)((float)(v83 * v83) + (float)(v85 * v85))) * (float)0.5)) * (float)v37) - (float)1.5)
                                                                                      * (float)v37)
                                                                              * (float)((float)((float)(v84 * v84)
                                                                                              + (float)((float)(v83 * v83) + (float)(v85 * v85)))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v37 * (float)((float)((float)(v84 * v84) + (float)((float)(v83 * v83) + (float)(v85 * v85))) * (float)0.5)) * (float)v37)
                                                                                              - (float)1.5)
                                                                              * (float)v37))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v37
                                                                                      * (float)((float)((float)(v84 * v84) + (float)((float)(v83 * v83) + (float)(v85 * v85)))
                                                                                              * (float)0.5))
                                                                              * (float)v37)
                                                                      - (float)1.5)
                                                      * (float)v37)))
                              - (float)1.5)
              * (float)v38);
  v41 = (float)(v83 * (float)v40);
  v83 = v83 * (float)v40;
  v42 = (float)(v84 * (float)v40);
  v84 = v84 * (float)v40;
  v43 = (float)(v85 * (float)v40);
  v85 = v85 * (float)v40;
  if ( v41 != vec3_origin.x || v42 != vec3_origin.y || (v44 = 1, v43 != vec3_origin.z) )
    v44 = 0;
  if ( v44 != 0 )
  {
    v83 = 0.0;
    v84 = 0.0;
    v85 = -1.0;
  }
  v45 = idEntity::GetPhysics(this);
  if ( v45->GetClipMask(this: v45, a2: -1) != 0 )
  {
    v46 = idEntity::GetPhysics(this);
    v47 = v46->GetClipMask(this: v46, a2: -1);
  }
  else
  {
    v47 = 8495233;
  }
  v48 = idEntity::GetPhysics(this);
  v49 = idEntity::GetPhysics(this);
  v50 = idEntity::GetPhysics(this);
  entityNumber = this->entityNumber;
  v52 = (float)(v85 * g_projectileImpactDistance.valueFloat);
  v53 = (float)(v84 * g_projectileImpactDistance.valueFloat);
  v54 = (float)(v83 * g_projectileImpactDistance.valueFloat);
  v55 = (float *)v49->GetOrigin(this: v49, a2: 0);
  v56 = (float)(v55[2] + (float)v52);
  v57 = (float)(v55[1] + (float)v53);
  v87.x = *v55 + (float)v54;
  v87.z = v56;
  v87.y = v57;
  v58 = v48->GetClipModel(this: v48, a2: 0);
  v59 = v50->GetOrigin(this: v50, a2: 0);
  this->deferredSurfTrace.index = *(_QWORD *)&idClip::Translation(
                                                this: (idClip *)&v81,
                                                result: &clientGame->clip,
                                                a3: nullptr,
                                                start: v59,
                                                end: &v87,
                                                clipModel: v58,
                                                startAxis: &mat3_identity,
                                                clipMask: v47,
                                                passEntityNumber: v60,
                                                moveClipModel: v61,
                                                userName: v62,
                                                a12: v63,
                                                a13: v64,
                                                a14: v65,
                                                a15: v66,
                                                a16: v67,
                                                a17: v68,
                                                a18: v69,
                                                a19: v70,
                                                a20: v71,
                                                a21: v72,
                                                a22: v73,
                                                a23: v74,
                                                a24: v75,
                                                a25: v76,
                                                a26: v77,
                                                a27: v78,
                                                a28: entityNumber,
                                                a29: v79,
                                                a30: false,
                                                a31: v80,
                                                a32: (int)"w:\\tech5\\tungsten\\game\\weapons\\Projectile.cpp(3444) : Translation")->world;
  idProjectile::Think(this);
  idList<idThread *,58>::Clear(this: v88);
  idPLogScope::~idPLogScope(this: &v82);
  RD_EventEnd();
}


// ========================================================================
// __unwind$508635
// EA  : 0x82EDCCA4
// RVA : 0x00EDCCA4
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_508635()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 320 + 192));
}


// ========================================================================
// __unwind$508636
// EA  : 0x82EDCCCC
// RVA : 0x00EDCCCC
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_508636()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 320 + 120));
}


// ========================================================================
// __unwind$508637
// EA  : 0x82EDCCF4
// RVA : 0x00EDCCF4
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_508637()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 320 + 176));
}


// ========================================================================
// ?Explode@idProjectile_Grenade@@UAAXPAVidEntity@@PAUtrace_t@@@Z
// EA  : 0x82EDCD28
// RVA : 0x00EDCD28
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_Grenade::Explode(idProjectile_Grenade *this, idWaterEntity *ent, trace_t *trace)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  idPresentable *presentable; // r3
  int v9; // r3
  idPresentable *v10; // r3
  int v11; // r3
  idClipQuery *p_deferredSurfTrace; // r29
  idClip *p_clip; // r28
  __int128 v14; // r11
  double x; // fp0
  double y; // fp13
  double z; // fp12
  idEntity *AttackerEntity; // r3
  idPlayer *v19; // r3
  idPlayer *v20; // r3
  idPLogScope v21; // [sp+58h] [-C8h] BYREF
  trace_t v22; // [sp+60h] [-C0h] BYREF

  RD_EventBegin(name: "idProjectile_Grenade::Explode");
  LODWORD(v6) = "idProjectile_Grenade::Explode";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: &v21, pl: &pLog, gMask: v6, label: v7);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v9 = (int)presentable->GetProjectileInterface(this: presentable);
  else
    v9 = 0;
  if ( *(_BYTE *)(v9 + 1316) != 0 )
  {
    v10 = this->presentable;
    if ( v10 != nullptr )
      v11 = (int)v10->GetProjectileInterface(this: v10);
    else
      v11 = 0;
    if ( *(_DWORD *)(v11 + 1252) != 5 )
    {
      if ( this->numSubMunitions > 0 )
        idProjectile_Grenade::DisperseSubmunitions(this, ent);
      idProjectile::Detach(this);
    }
    p_deferredSurfTrace = &this->deferredSurfTrace;
    p_clip = &clientGame->clip;
    if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &this->deferredSurfTrace) != 0 )
    {
      LODWORD(v14) = 0;
      *(idClipQuery *)((char *)&v14 + 4) = (idClipQuery)p_deferredSurfTrace->index;
      p_deferredSurfTrace->index = v14;
      idCollisionModelManager::GetContentsResult(
        this: collisionModelManager,
        result: &v22,
        query: &p_clip->collisionQueries[WORD5(v14) & 0xFFF].query,
        peek: false);
      x = v22.c.normal.x;
      y = v22.c.normal.y;
      this->surfTypeLastHit = v22.c.surfaceType;
      z = v22.c.normal.z;
      this->surfNormalLastHit.x = x;
      this->surfNormalLastHit.y = y;
      this->surfNormalLastHit.z = z;
    }
    if ( this->isInWater )
      this->surfTypeLastHit = 6;
    if ( this->projectileDecl->notHitscanInfo.followDeployableRules )
    {
      AttackerEntity = idProjectile::GetAttackerEntity(this);
      if ( (unsigned __int8)idClass::IsType(this: AttackerEntity, superclass: &idPlayer::Type) != 0 )
      {
        v19 = (idPlayer *)idProjectile::GetAttackerEntity(this);
        v20 = idPlayer::CastTo(c: v19);
        idPlayer::RemoveDroppableInfo(this: v20, ent: this);
      }
    }
    idProjectile::Explode(this, ent, trace);
    idPLogScope::~idPLogScope(this: &v21);
  }
  else
  {
    idPLogScope::~idPLogScope(this: &v21);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$509026
// EA  : 0x82EDCF04
// RVA : 0x00EDCF04
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_509026()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 288 + 224));
}


// ========================================================================
// __unwind$509027
// EA  : 0x82EDCF2C
// RVA : 0x00EDCF2C
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _unwind_509027()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 288 + 88));
}


// ========================================================================
// ??0idProjectile_BouncyBomb@@QAA@XZ
// EA  : 0x82EDCF58
// RVA : 0x00EDCF58
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

idProjectile_BouncyBomb *__fastcall idProjectile_BouncyBomb::idProjectile_BouncyBomb(idProjectile_BouncyBomb *this)
{
  idProjectile_Grenade::idProjectile_Grenade(this);
  this->__vftable = (idProjectile_BouncyBomb_vtbl *)&idProjectile_BouncyBomb::`vftable';
  this->ignoreEntity.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// ??0idProjectile_EventPulser@@QAA@XZ
// EA  : 0x82EDCFA0
// RVA : 0x00EDCFA0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

idProjectile_EventPulser *__fastcall idProjectile_EventPulser::idProjectile_EventPulser(idProjectile_EventPulser *this)
{
  idProjectile_Grenade::idProjectile_Grenade(this);
  this->toFactionDecl = nullptr;
  this->__vftable = (idProjectile_EventPulser_vtbl *)&idProjectile_EventPulser::`vftable';
  this->pulseIntervalMS = 90;
  this->eventClassDecl = nullptr;
  this->targetFactionDecl = nullptr;
  this->startPulseSound = nullptr;
  this->pulseEffectDuration = 1000;
  this->nextPulseTime = 0;
  return this;
}


// ========================================================================
// ?Think@idProjectile_EventPulser@@UAAXXZ
// EA  : 0x82EDD008
// RVA : 0x00EDD008
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_EventPulser::Think(idProjectile_EventPulser *this)
{
  idPhysics *Physics; // r3
  int GameMs; // r3
  int nextPulseTime; // r11
  idPhysics *v5; // r28
  int v6; // r27
  idPhysics *v7; // r3
  idAIEventManager *p_aiEventManager; // r28
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v10; // r26
  const idEntity *AttackerEntity; // r3
  idPhysics *v12; // r28
  idPhysics *v13; // r30
  int v14; // r29
  idPresentable *presentable; // r31
  const idMat3 *v16; // r28
  const idVec3 *v17; // r3
  char v18; // [sp+50h] [-40h] BYREF

  idProjectile_Grenade::Think(this);
  if ( this->eventClassDecl != nullptr )
  {
    Physics = idEntity::GetPhysics(this);
    if ( Physics->IsAtRest(this: Physics) )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      nextPulseTime = this->nextPulseTime;
      if ( GameMs >= nextPulseTime )
      {
        if ( nextPulseTime == 0 )
        {
          this->FirstTrigger(this);
          idEntity::StartSoundShader(
            this,
            channel: SND_CHANNEL_BODY,
            shader: this->startPulseSound,
            soundShaderFlags: (soundShaderFlags_t)0,
            peerMask: 0xFFu);
        }
        this->nextPulseTime = this->pulseIntervalMS
                            + idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v5 = idEntity::GetPhysics(this);
        v6 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v7 = v5;
        GetOrigin = v5->GetOrigin;
        p_aiEventManager = &gameLocal->aiEventManager;
        v10 = GetOrigin(this: v7, a2: 0);
        AttackerEntity = idProjectile::GetAttackerEntity(this);
        idAIEventManager::AddEvent(
          this: (idAIEventManager *)&v18,
          result: p_aiEventManager,
          eventDecl: this->eventClassDecl,
          curTime: v6,
          originator: this,
          instigator: AttackerEntity,
          origin: v10,
          delay: 0);
      }
      v12 = idEntity::GetPhysics(this);
      v13 = idEntity::GetPhysics(this);
      v14 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      if ( this->presentable == nullptr )
        idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
      v16 = v12->GetAxis(this: v12, a2: 0);
      v17 = v13->GetOrigin(this: v13, a2: 0);
      idFXManager::StartFX(this: &presentable->fxManager, org: v17, axis: v16, time: v14, startCondition: 87);
    }
  }
}


// ========================================================================
// ?Explode@idProjectile_EventPulser@@UAAXPAVidEntity@@PAUtrace_t@@@Z
// EA  : 0x82EDD1E8
// RVA : 0x00EDD1E8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __fastcall idProjectile_EventPulser::Explode(idProjectile_EventPulser *this, idWaterEntity *ent, trace_t *trace)
{
  idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
  idProjectile_Grenade::Explode(this, ent, trace);
}


// ========================================================================
// `dynamic initializer for 'g_trajectoryTimestep''
// EA  : 0x83393878
// RVA : 0x01393878
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_trajectoryTimestep__()
{
  idCVar::idCVar(
    this: &g_trajectoryTimestep,
    name: "g_trajectoryTimestep",
    value: "16",
    flags: 4,
    description: "time in milliseconds for each timestep during trajectory simulation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_trajectoryTimestep__);
}


// ========================================================================
// `dynamic initializer for 'g_tempProjectileTest''
// EA  : 0x833938D0
// RVA : 0x013938D0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_tempProjectileTest__()
{
  idCVar::idCVar(
    this: &g_tempProjectileTest,
    name: "g_tempProjectileTest",
    value: "1",
    flags: 1,
    description: "if true we try the new system for detecting throwing through geometry",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_tempProjectileTest__);
}


// ========================================================================
// `dynamic initializer for 'g_projectileImpactDistance''
// EA  : 0x83393928
// RVA : 0x01393928
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_projectileImpactDistance__()
{
  idCVar::idCVar(
    this: &g_projectileImpactDistance,
    name: "g_projectileImpactDistance",
    value: "1.0",
    flags: 4,
    description: "how far we should test to see what surf type the explosion would hit",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_projectileImpactDistance__);
}


// ========================================================================
// `dynamic initializer for 'g_projectileRocketImpactDistance''
// EA  : 0x83393980
// RVA : 0x01393980
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_projectileRocketImpactDistance__()
{
  idCVar::idCVar(
    this: &g_projectileRocketImpactDistance,
    name: "g_projectileRocketImpactDistance",
    value: "100.0",
    flags: 4,
    description: "how far we should test to see what surf type the rocket explosion would hit",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_projectileRocketImpactDistance__);
}


// ========================================================================
// `dynamic initializer for 'g_projectileAdjustStart''
// EA  : 0x833939D8
// RVA : 0x013939D8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_projectileAdjustStart__()
{
  idCVar::idCVar(
    this: &g_projectileAdjustStart,
    name: "g_projectileAdjustStart",
    value: "6",
    flags: 2,
    description: "the offset dir from the trace point",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_projectileAdjustStart__);
}


// ========================================================================
// `dynamic initializer for 'g_projectileImpale''
// EA  : 0x83393A30
// RVA : 0x01393A30
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_projectileImpale__()
{
  idCVar::idCVar(
    this: &g_projectileImpale,
    name: "g_projectileImpale",
    value: "0",
    flags: 1,
    description: "to allow rockets to impale AI on contact",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_projectileImpale__);
}


// ========================================================================
// `dynamic initializer for 'idProjectile::projectilesToSimulate''
// EA  : 0x83393A88
// RVA : 0x01393A88
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void _dynamic_initializer_for__idProjectile::projectilesToSimulate__()
{
  int v0; // ctr
  idCVar **p_next; // r11

  v0 = 16;
  p_next = &g_projectileImpale.next;
  do
  {
    p_next[1] = nullptr;
    p_next += 2;
    *p_next = nullptr;
    --v0;
  }
  while ( v0 != 0 );
}


// ========================================================================
// `dynamic initializer for 'g_projectileHomingGroundCheck''
// EA  : 0x83393AB0
// RVA : 0x01393AB0
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_projectileHomingGroundCheck__()
{
  idCVar::idCVar(
    this: &g_projectileHomingGroundCheck,
    name: "g_projectileHomingGroundCheck",
    value: "50.0",
    flags: 4,
    description: "how far off the ground the rocket should be",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_projectileHomingGroundCheck__);
}


// ========================================================================
// `dynamic initializer for 'g_projectileHomingGroundReflection''
// EA  : 0x83393B08
// RVA : 0x01393B08
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_projectileHomingGroundReflection__()
{
  idCVar::idCVar(
    this: &g_projectileHomingGroundReflection,
    name: "g_projectileHomingGroundReflection",
    value: "1.0",
    flags: 4,
    description: "how far off the ground the rocket should be",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_projectileHomingGroundReflection__);
}


// ========================================================================
// `dynamic initializer for 'g_projectileHomingGroundCheckDebug''
// EA  : 0x83393B60
// RVA : 0x01393B60
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_projectileHomingGroundCheckDebug__()
{
  idCVar::idCVar(
    this: &g_projectileHomingGroundCheckDebug,
    name: "g_projectileHomingGroundCheckDebug",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_projectileHomingGroundCheckDebug__);
}


// ========================================================================
// `dynamic initializer for 'g_projectileEMPpull''
// EA  : 0x83393BB8
// RVA : 0x01393BB8
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_projectileEMPpull__()
{
  idCVar::idCVar(
    this: &g_projectileEMPpull,
    name: "g_projectileEMPpull",
    value: "36.0",
    flags: 4,
    description: "how close an emp grenade must be to a power source to get pulled to it",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_projectileEMPpull__);
}


// ========================================================================
// `dynamic initializer for 'g_projectileEMPstick''
// EA  : 0x83393C10
// RVA : 0x01393C10
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_projectileEMPstick__()
{
  idCVar::idCVar(
    this: &g_projectileEMPstick,
    name: "g_projectileEMPstick",
    value: "35.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_projectileEMPstick__);
}


// ========================================================================
// `dynamic initializer for 'proj_ExplodeOnSelf''
// EA  : 0x83393C68
// RVA : 0x01393C68
// PDB : w:\tech5\tungsten\game\weapons\projectile.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__proj_ExplodeOnSelf__()
{
  idCVar::idCVar(
    this: &proj_ExplodeOnSelf,
    name: "proj_ExplodeOnSelf",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__proj_ExplodeOnSelf__);
}

