
// ========================================================================
// ?DormantBegin@idDamageableEntity@@EAAXXZ
// EA  : 0x82C1C290
// RVA : 0x00C1C290
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __fastcall idDamageableEntity::DormantBegin(idDamageableEntity *this)
{
  idEntity::DormantBegin(this);
  if ( this->resetWhenDormant && this->state == DEAD || this->state == DEAD )
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
}


// ========================================================================
// ?GetModelTransform@idDamageableEntity@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C1C2F8
// RVA : 0x00C1C2F8
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

// attributes: thunk
void __fastcall idDamageableEntity::GetModelTransform(idDamageableEntity *this, idVec3 *modelOrigin, idMat3 *modelAxis)
{
  idEntity::GetModelTransform(this, modelOrigin, modelAxis);
}


// ========================================================================
// ?Collide@idDamageableEntity@@UAA?AW4collide_t@@HAAUtrace_t@@ABVidVec3@@@Z
// EA  : 0x82C1C300
// RVA : 0x00C1C300
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

int __fastcall idDamageableEntity::Collide(
        idDamageableEntity *this,
        const int physId,
        trace_t *collision,
        const idVec3 *velocity)
{
  this->lastBump = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  return idLobbyBackend360::StartArbitration(pexcept: (_exception *)this);
}


// ========================================================================
// ?IsTargetLockable@idDamageableEntity@@UBA_NPBVidDeclAmmo@@@Z
// EA  : 0x82C1C358
// RVA : 0x00C1C358
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

int __fastcall idDamageableEntity::IsTargetLockable(idDamageableEntity *this, const idDeclAmmo *ammo)
{
  idDamageableEntity::breakState_t state; // r11
  unsigned __int8 v4; // r11
  idDamageableEntity::breakState_t v5; // r11
  bool v6; // zf

  if ( ((unsigned __int8 (__fastcall *)(idCommon *, const idDeclAmmo *))common->IsMultiplayer)(a1: common, a2: ammo) != 0 )
  {
    if ( !this->targetable )
      return 0;
    state = this->state;
    return state == READY_TO_BREAK || state == BREAKING;
  }
  v5 = this->state;
  if ( v5 == READY_TO_BREAK )
    return 1;
  v6 = v5 != BREAKING;
  v4 = 0;
  if ( !v6 )
    return 1;
  return v4;
}


// ========================================================================
// ??1idDamageableEntity@@UAA@XZ
// EA  : 0x82C1C3F8
// RVA : 0x00C1C3F8
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __fastcall idDamageableEntity::~idDamageableEntity(idDamageableEntity *this)
{
  idPhysics *Physics; // r3
  idPhysics *physicsObj; // r3

  this->__vftable = (idDamageableEntity_vtbl *)&idDamageableEntity::`vftable';
  idClientGame::RemoveSimulatingEffectPhysics(
    this: clientGame,
    broadPhase: &this->debrisEmitter.piecePhysics.broadPhase);
  idClientGame::RemoveSimulatingEffectPhysics(this: clientGame, broadPhase: &this->breakablePhysics.broadPhase);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->breakablePhysics);
  if ( idEntity::GetPhysics(this) != nullptr )
  {
    Physics = idEntity::GetPhysics(this);
    Physics->UnlinkClip(this: Physics);
  }
  physicsObj = this->physicsObj;
  if ( physicsObj != nullptr )
  {
    ((void (__fastcall *)(idPhysics *, int))physicsObj->dtr_idPhysics)(a1: physicsObj, a2: 1);
    this->physicsObj = nullptr;
  }
  idEffectPhysicsPieceEmitter::~idEffectPhysicsPieceEmitter(this: &this->debrisEmitter.piecePhysics);
  idEffectPhysicsBreakable::~idEffectPhysicsBreakable(this: &this->breakablePhysics);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$488856
// EA  : 0x82C1C4B8
// RVA : 0x00C1C4B8
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void _unwind_488856()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$488857_0
// EA  : 0x82C1C4E0
// RVA : 0x00C1C4E0
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void _unwind_488857_0()
{
  int v0; // r12

  idEffectPhysicsBreakable::~idEffectPhysicsBreakable(this: (idEffectPhysicsBreakable *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                       + 820));
}


// ========================================================================
// __unwind$488858_1
// EA  : 0x82C1C50C
// RVA : 0x00C1C50C
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void _unwind_488858_1()
{
  int v0; // r12

  idEffectPhysicsDebrisEmitter::~idEffectPhysicsDebrisEmitter(this: (idEffectPhysicsDebrisEmitter *)(*(_DWORD *)(v0 - 128 + 148) + 1204));
}


// ========================================================================
// ?AllocPresentable@idDamageableEntity@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82C1C5B8
// RVA : 0x00C1C5B8
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

idPresentableDamageable *__fastcall idDamageableEntity::AllocPresentable(
        idDamageableEntity *this,
        idTreeAnimator *renderModel_)
{
  idPresentableDamageable *v4; // r3
  idPresentableDamageable *v5; // r29

  v4 = (idPresentableDamageable *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x6E0u,
                                    tag: TAG_PRESENTABLE,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v5 = idPresentableDamageable::idPresentableDamageable(this: v4, ent: this, renderModel_);
  else
    v5 = nullptr;
  idPresentableDamageable::SetInitProperties(
    this: v5,
    impactTable_: this->impactSoundTable,
    pieceMinBounceVelocity_: this->pieceMinBounceVelocity);
  return v5;
}


// ========================================================================
// __unwind$489136
// EA  : 0x82C1C638
// RVA : 0x00C1C638
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void _unwind_489136()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?SetupRigidBodyPhysics@idDamageableEntity@@AAAXXZ
// EA  : 0x82C1C670
// RVA : 0x00C1C670
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __fastcall idDamageableEntity::SetupRigidBodyPhysics(idDamageableEntity *this)
{
  idPhysics *physicsObj; // r3
  idPhysics_RigidBody *v3; // r3
  idPhysics_RigidBody *v4; // r30
  idPhysics_RigidBody_vtbl *v5; // r28
  double density; // fp31
  idClipModel *MoveableClipModel; // r3
  idRenderModelDiscreteAnimation *breakableModel; // r11
  float *declBreakable; // r28
  double v10; // fp3
  double v11; // fp2
  double v12; // fp1
  void (__fastcall *SetClipMask)(struct idPhysics_RigidBody *, int, int); // r8

  if ( this->physicsObj != nullptr )
  {
    idEntity::SetPhysics(this, phys: nullptr);
    physicsObj = this->physicsObj;
    if ( physicsObj != nullptr )
      ((void (__fastcall *)(idPhysics *, int))physicsObj->dtr_idPhysics)(a1: physicsObj, a2: 1);
  }
  v3 = (idPhysics_RigidBody *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                size: 0x270u,
                                tag: TAG_NEW,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idPhysics_RigidBody::idPhysics_RigidBody(this: v3);
  else
    v4 = nullptr;
  this->physicsObj = v4;
  idPhysics::InitPhysics(
    this: v4,
    clip_: &clientGame->clip,
    callbacks_: &this->physicsCallbacks,
    entityNumber_: this->entityNumber);
  v5 = v4->__vftable;
  density = this->density;
  MoveableClipModel = idEntity::CreateMoveableClipModel(
                        this,
                        barrelCollision: this->barrelCollision,
                        overrideRadius: -1.0);
  ((void (__fastcall *)(idPhysics_RigidBody *, idClipModel *, double))v5->SetClipModel)(
    a1: v4,
    a2: MoveableClipModel,
    a3: density);
  v4->SetContents(this: v4, a2: 139584, a3: -1);
  v4->PutToRest(this: v4);
  breakableModel = this->breakableModel;
  if ( breakableModel != nullptr )
  {
    declBreakable = (float *)breakableModel->declBreakable;
    idPhysics_RigidBody::SetBouncyness(this: v4, b: declBreakable[21]);
    v10 = declBreakable[18];
    v11 = declBreakable[17];
    v12 = declBreakable[16];
  }
  else
  {
    idPhysics_RigidBody::SetBouncyness(this: v4, b: 0.30000001);
    v11 = 0.60000002;
    v10 = 0.5;
    v12 = 0.60000002;
  }
  idPhysics_RigidBody::SetFriction(this: v4, linear: v12, angular: v11, contact: v10);
  idEntity::SetPhysics(this, phys: v4);
  if ( this->moveable )
  {
    SetClipMask = v4->SetClipMask;
    *((_BYTE *)&v4->fl + 4) |= 0xC0u;
    SetClipMask(this: v4, a2: 37953, a3: -1);
  }
  else
  {
    v4->SetClipMask(this: v4, a2: 1, a3: -1);
  }
}


// ========================================================================
// __unwind$489165_1
// EA  : 0x82C1C848
// RVA : 0x00C1C848
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __fastcall _unwind_489165_1(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?ThrowDebris@idDamageableEntity@@AAAXABVidVec3@@00H@Z
// EA  : 0x82C1C870
// RVA : 0x00C1C870
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __fastcall idDamageableEntity::ThrowDebris(
        idDamageableEntity *this,
        const idVec3 *pos,
        const idVec3 *hitvel,
        const idVec3 *normal,
        unsigned int count)
{
  __int64 v8; // r8
  unsigned int v9; // r3
  int GameMs; // r3
  int v11; // [sp+8h] [-98h]
  __int64 v12; // [sp+10h] [-90h]
  __int64 v13; // [sp+18h] [-88h]
  __int64 v14; // [sp+20h] [-80h]
  __int64 v15; // [sp+28h] [-78h]
  __int64 v16; // [sp+30h] [-70h]
  __int64 v17; // [sp+38h] [-68h]
  __int64 v18; // [sp+40h] [-60h]
  __int64 v19; // [sp+48h] [-58h]
  __int64 v20; // [sp+50h] [-50h]
  int v21; // [sp+58h] [-48h]
  __int64 v22; // [sp+60h] [-40h]

  if ( this->breakableDebris != nullptr )
  {
    HIDWORD(v8) = &unk_82150000;
    v9 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v9;
    LODWORD(v8) = (v9 >> 10) & 0x7FFF;
    if ( (float)((float)v8 * (float)0.000030518509) > 0.75 )
    {
      *(float *)&v22 = hitvel->x * (float)0.25;
      *((float *)&v22 + 1) = hitvel->y * (float)0.25;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idEffectPhysicsDebrisEmitter::EmitDebris(
        this: (idEffectPhysicsDebrisEmitter *)LODWORD(pos->x),
        velocity: v22,
        count: *(_QWORD *)&normal->x,
        currentTime: __SPAIR64__(__ROL4__(LODWORD(normal->z), 32), count),
        a5: v11,
        a6: v12,
        a7: v13,
        a8: v14,
        a9: v15,
        a10: v16,
        a11: v17,
        a12: v18,
        a13: v19,
        a14: v20,
        a15: v21,
        a16: GameMs,
        a17: SHIDWORD(v22),
        a18: v22);
    }
  }
}


// ========================================================================
// ?StartExplosions@idDamageableEntity@@AAAXXZ
// EA  : 0x82C1C980
// RVA : 0x00C1C980
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __fastcall idDamageableEntity::StartExplosions(idDamageableEntity *this)
{
  idPhysics *Physics; // r30
  idPhysics *v3; // r29
  int GameMs; // r28
  const idMat3 *v5; // r30
  const idVec3 *v6; // r3
  idPresentable *presentable; // r11
  idPresentableDamageable *v8; // r3

  if ( !this->explosionsStarted )
  {
    this->ActivateTargets(this, a2: this);
    Physics = idEntity::GetPhysics(this);
    v3 = idEntity::GetPhysics(this);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v5 = Physics->GetAxis(this: Physics, a2: 0);
    v6 = v3->GetOrigin(this: v3, a2: 0);
    idEffectPhysicsBreakable::StartExplosions(this: &this->breakablePhysics, origin: v6, axis: v5, currentTime: GameMs);
    presentable = this->presentable;
    this->explosionsStarted = true;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    v8 = presentable->GetDamageableInterface(this: presentable);
    idPresentableDamageable::StartExplosions(this: v8);
  }
  if ( this->state == BREAKING )
    this->state = BROKEN;
}


// ========================================================================
// ?ReorientSwap@idDamageableEntity@@AAAXABVidVec3@@@Z
// EA  : 0x82C1CA80
// RVA : 0x00C1CA80
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __fastcall idDamageableEntity::ReorientSwap(idDamageableEntity *this, const idVec3 *spot)
{
  idPhysics *Physics; // r3
  float *v5; // r3
  double v6; // fp11
  idPhysics *v7; // r30
  idPhysics *v8; // r29
  idPhysics_vtbl *v9; // r31
  const idMat3 *v10; // r30
  idMat3 *v11; // r3
  idMat3 *v12; // r3
  idMat3 v13; // [sp+50h] [-90h] BYREF
  idMat3 v14[2]; // [sp+90h] [-50h] BYREF

  if ( this->reorientOnSwap && ((LODWORD(spot->z) | LODWORD(spot->y) | LODWORD(spot->x)) & 0x7FFFFFFF) != 0 )
  {
    Physics = idEntity::GetPhysics(this);
    v5 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v6 = v5[1];
    v13.mat[0].x = spot->x - *v5;
    v13.mat[0].y = spot->y - (float)v6;
    v13.mat[0].z = 0.0;
    if ( (LODWORD(v13.mat[0].y) & 0x7FFFFFFF | COERCE_UNSIGNED_INT(fabs(0.0)) | LODWORD(v13.mat[0].x) & 0x7FFFFFFF) != 0 )
    {
      idVec3::NormalizeFast(this: v13.mat);
      v7 = idEntity::GetPhysics(this);
      v8 = idEntity::GetPhysics(this);
      v9 = v8->__vftable;
      v10 = v7->GetAxis(this: v7, a2: 0);
      v11 = idVec3::ToMat3(this: (idVec3 *)&v13.mat[1].y, result: &v13);
      v12 = idMat3::operator*(this: v14, result: v11, a: v10);
      v9->SetAxis(this: v8, a2: v12, a3: -1);
    }
  }
}


// ========================================================================
// ?ActivateAll@idDamageableEntity@@AAAXXZ
// EA  : 0x82C1CBA0
// RVA : 0x00C1CBA0
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __fastcall idDamageableEntity::ActivateAll(idDamageableEntity *this)
{
  idPhysics *Physics; // r30
  idPhysics *v3; // r29
  int v4; // r30
  const idVec3 *v5; // r3
  __int64 v6; // r6
  idPresentable *presentable; // r3
  idPresentableDamageable *v8; // r3
  idPhysics *v9; // r29
  idPhysics *v10; // r27
  __int64 v11; // r9
  unsigned int v12; // r5
  double v13; // fp31
  int GameMsPerFrame; // r26
  int GameMs; // r30
  const idVec3 *v16; // r29
  const idMat3 *v17; // r28
  const idDeclParticle *destroyParticle; // r31
  idRenderModelEffects *MergeBranch; // r3
  const idVec3 *v20; // r7
  int v21; // [sp+8h] [-A8h]
  int v22; // [sp+Ch] [-A4h]
  int v23; // [sp+10h] [-A0h]
  int v24; // [sp+14h] [-9Ch]
  int v25; // [sp+18h] [-98h]
  int v26; // [sp+1Ch] [-94h]
  int v27; // [sp+20h] [-90h]
  int v28; // [sp+24h] [-8Ch]
  int v29; // [sp+28h] [-88h]
  int v30; // [sp+2Ch] [-84h]
  int v31; // [sp+30h] [-80h]
  int v32; // [sp+34h] [-7Ch]
  int v33; // [sp+38h] [-78h]
  int v34; // [sp+3Ch] [-74h]
  int v35; // [sp+40h] [-70h]
  int v36; // [sp+44h] [-6Ch]
  int v37; // [sp+48h] [-68h]
  int v38; // [sp+4Ch] [-64h]
  int v39; // [sp+50h] [-60h]
  unsigned int v40; // [sp+60h] [-50h] BYREF
  __int64 v41; // [sp+68h] [-48h]

  Physics = idEntity::GetPhysics(this);
  v3 = idEntity::GetPhysics(this);
  v4 = (int)Physics->GetAxis(this: Physics, a2: 0);
  v5 = v3->GetOrigin(this: v3, a2: 0);
  HIDWORD(v6) = v4;
  if ( (unsigned __int8)idEffectPhysicsBreakable::ActivateAllNow(this: &this->breakablePhysics, origin: v5, axis: v6) != 0 )
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    v8 = presentable->GetDamageableInterface(this: presentable);
    idPresentableDamageable::ActivateAllNow(this: v8);
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_ANY,
      shader: this->sndCrumble,
      soundShaderFlags: 0,
      peerMask: 0xFFu);
    if ( this->destroyParticle != nullptr )
    {
      v40 = -1;
      v9 = idEntity::GetPhysics(this);
      v10 = idEntity::GetPhysics(this);
      HIDWORD(v11) = 1664525;
      v12 = 1664525 * clientGame->random.seed;
      clientGame->random.seed = v12 + 1013904223;
      LODWORD(v11) = ((v12 + 1013904223) >> 10) & 0x7FFF;
      v41 = v11;
      v13 = (float)((float)v11 * (float)0.000030518509);
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v16 = (const idVec3 *)v9->GetAxis(this: v9, a2: 0);
      v17 = (const idMat3 *)v10->GetOrigin(this: v10, a2: 0);
      destroyParticle = this->destroyParticle;
      MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
      idRenderModelEffects::AddParticles(
        this: MergeBranch,
        particle: destroyParticle,
        systemStartTime: GameMs,
        gameMsPerFrame: GameMsPerFrame,
        diversity: v13,
        origin: v20,
        axis: v17,
        velocity: v16,
        color: &vec3_origin.x,
        a10: v21,
        a11: v22,
        a12: v23,
        a13: v24,
        a14: v25,
        a15: v26,
        a16: v27,
        a17: v28,
        a18: v29,
        a19: v30,
        a20: v31,
        a21: v32,
        a22: v33,
        a23: v34,
        a24: v35,
        a25: v36,
        a26: v37,
        a27: v38,
        a28: v39,
        a29: &v40);
    }
  }
}


// ========================================================================
// ?UpdateBreakableSim@idDamageableEntity@@AAAXXZ
// EA  : 0x82C1CD80
// RVA : 0x00C1CD80
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __fastcall idDamageableEntity::UpdateBreakableSim(idDamageableEntity *this)
{
  idDamageableEntity *v1; // r30
  idPhysics *Physics; // r3
  const idVec3 *v3; // r29
  idPhysics *v4; // r3
  const idMat3 *v5; // r27
  idGameTimeManager *p_gameTimeManager; // r26
  int v7; // r25
  const char *GameMsPerFrame; // r24
  int GameMs; // r23
  double RealMsPerFrame; // fp1
  int v11; // r3

  v1 = this;
  Physics = idEntity::GetPhysics(this);
  v3 = Physics->GetOrigin(this: Physics, a2: 0);
  v4 = idEntity::GetPhysics(this: v1);
  v5 = v4->GetAxis(this: v4, a2: 0);
  p_gameTimeManager = &clientGame->gameTimeManager;
  v7 = idAccolade::Count(this: &clientGame->gameTimeManager);
  GameMsPerFrame = (const char *)idGameTimeManager::GetGameMsPerFrame(
                                   this: &clientGame->gameTimeManager,
                                   type: GAMETIME_SCALED);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v1 = (idDamageableEntity *)((char *)v1 + 820);
  RealMsPerFrame = idGameTimeManager::GetRealMsPerFrame(this: p_gameTimeManager, type: GAMETIME_SCALED);
  idEffectPhysicsBreakable::UpdateSimulation(
    this: (idEffectPhysicsBreakable *)v1,
    origin: v3,
    axis: v5,
    currentTime: GameMs,
    gameMsPerFrame: GameMsPerFrame,
    frameNum: v7,
    msPerFrame: RealMsPerFrame,
    dampening: 0.0);
  v11 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idEffectPhysicsBreakable::UpdateModel(this: (idEffectPhysicsBreakable *)v1, origin: v3, axis: v5, gameMsPerFrame: v11);
}


// ========================================================================
// ?Event_Kill@idDamageableEntity@@AAA?AVeventVoid@@XZ
// EA  : 0x82C1CE78
// RVA : 0x00C1CE78
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

idDamageableEntity *__fastcall idDamageableEntity::Event_Kill(idDamageableEntity *this, eventVoid *result)
{
  if ( *(float *)&result[800] > 0.0 && gameLocal->damageSuicide != nullptr )
    (*(void (__fastcall **)(eventVoid *, eventVoid *, eventVoid *))(*(_DWORD *)result + 312))(
      a1: result,
      a2: result,
      a3: result);
  return this;
}


// ========================================================================
// ??0idDamageableEntity@@QAA@XZ
// EA  : 0x82C1CF00
// RVA : 0x00C1CF00
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

idDamageableEntity *__fastcall idDamageableEntity::idDamageableEntity(idDamageableEntity *this)
{
  idEntity::idEntity(this);
  this->physicsObj = nullptr;
  this->__vftable = (idDamageableEntity_vtbl *)&idDamageableEntity::`vftable';
  this->health = 20.0;
  this->initialModel = nullptr;
  this->healthMax = 20.0;
  this->useRigidBody = true;
  this->useStaticMulti = false;
  idEffectPhysicsBreakable::idEffectPhysicsBreakable(this: &this->breakablePhysics);
  this->sndBreak = nullptr;
  this->sndCrumble = nullptr;
  this->impactSoundTable = nullptr;
  this->armorValue = 0;
  this->radiusDamageKills = false;
  this->reorientOnSwap = false;
  this->pieceMinBounceVelocity = 40.0;
  this->fadeTime = 3000;
  this->destructionPercent = 0.85000002;
  this->maxSimulationTime = 14000;
  this->noClipPercent = 0.64999998;
  this->fadeParticle = nullptr;
  this->resistPercent = 0.60000002;
  this->swapParticle = nullptr;
  this->secondBlastScale = 0.0;
  this->destroyParticle = nullptr;
  this->density = 0.003;
  this->collideIgnoreImpulse = 3500;
  this->hitsTaken = 0;
  this->breakableTime = 0;
  this->explosionsStarted = false;
  this->moveable = false;
  this->barrelCollision = false;
  this->targetable = false;
  this->deadClipModel = nullptr;
  this->breakableDebris = nullptr;
  idEffectPhysicsDebrisEmitter::idEffectPhysicsDebrisEmitter(this: &this->debrisEmitter);
  this->debrisScale.x = 1.0;
  this->debrisScale.y = 1.0;
  this->debrisScale.z = 1.0;
  this->staticVehicleCollisions = false;
  this->state = UNBREAKABLE;
  this->breakableModel = nullptr;
  this->renderModel = nullptr;
  this->fadeStartTime = 0;
  this->fadeEndTime = 0;
  this->lastBump = 0;
  this->resetWhenDormant = false;
  this->breakImmediately = false;
  this->playerOwner.spawnId.value = 0x1FFF;
  *(_BYTE *)&this->flags |= 0x42u;
  return this;
}


// ========================================================================
// __unwind$489496
// EA  : 0x82C1D06C
// RVA : 0x00C1D06C
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void _unwind_489496()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489497
// EA  : 0x82C1D094
// RVA : 0x00C1D094
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void _unwind_489497()
{
  int v0; // r12

  idEffectPhysicsBreakable::~idEffectPhysicsBreakable(this: (idEffectPhysicsBreakable *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                       + 820));
}


// ========================================================================
// ?SetupStaticMultiPhysics@idDamageableEntity@@AAAXXZ
// EA  : 0x82C1D128
// RVA : 0x00C1D128
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __fastcall idDamageableEntity::SetupStaticMultiPhysics(idDamageableEntity *this)
{
  idRenderModel *RenderModelFromPresentable; // r3
  idRenderModelDiscreteAnimation *v3; // r26
  idPhysics *physicsObj; // r3
  idPhysics_StaticMulti *v5; // r3
  idPhysics_StaticMulti *v6; // r3
  int v7; // r29
  int num; // r23
  float *p_z; // r10
  int v10; // ctr
  idSysMutex *p_viewNoteMutex; // r11
  idClipModel *v12; // r3
  idClipModel *v13; // r4
  float *v26; // r10
  int v27; // ctr
  idSysMutex *v28; // r11
  idClipModel *v29; // r3
  idClipModel *v30; // r4
  idBounds v31; // [sp+50h] [-CE0h] BYREF
  void *v32; // [sp+68h] [-CC8h]
  idVec3 v33; // [sp+70h] [-CC0h] BYREF
  idMat3 v34; // [sp+80h] [-CB0h] BYREF
  idTraceModel v35; // [sp+B0h] [-C80h] BYREF
  idTraceModel v36; // [sp+6B0h] [-680h] BYREF

  RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
  v3 = (idRenderModelDiscreteAnimation *)_RTDynamicCast(
                                           inptr: RenderModelFromPresentable,
                                           VfDelta: 0,
                                           SrcType: &idRenderModel `RTTI Type Descriptor',
                                           TargetType: &idRenderModelDiscreteAnimation `RTTI Type Descriptor',
                                           isReference: 0);
  if ( v3 != nullptr )
  {
    if ( this->physicsObj != nullptr )
    {
      idEntity::SetPhysics(this, phys: nullptr);
      physicsObj = this->physicsObj;
      if ( physicsObj != nullptr )
        ((void (__fastcall *)(idPhysics *, int))physicsObj->dtr_idPhysics)(a1: physicsObj, a2: 1);
    }
    v5 = (idPhysics_StaticMulti *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                    size: 0x98u,
                                    tag: TAG_NEW,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
    v32 = v5;
    if ( v5 != nullptr )
      v6 = idPhysics_StaticMulti::idPhysics_StaticMulti(this: v5);
    else
      v6 = nullptr;
    this->physicsObj = v6;
    idPhysics::InitPhysics(
      this: v6,
      clip_: &clientGame->clip,
      callbacks_: &this->physicsCallbacks,
      entityNumber_: this->entityNumber);
    v7 = 0;
    v31.b[0].z = 1.0e30;
    v31.b[0].y = 1.0e30;
    v31.b[0].x = 1.0e30;
    v31.b[1].z = -1.0e30;
    v31.b[1].y = v31.b[1].z;
    v31.b[1].x = v31.b[1].z;
    num = v3->transforms.num;
    if ( num > 0 )
    {
      do
      {
        v35.offset.x = 0.0;
        p_z = &v35.offset.z;
        v35.offset.y = 0.0;
        v35.offset.z = 0.0;
        memset(&v35.type, 0, 20);
        v10 = 6;
        p_viewNoteMutex = &analysisClient.viewNoteMutex;
        do
        {
          ++p_viewNoteMutex;
          *++p_z = *(float *)&p_viewNoteMutex->handle;
          --v10;
        }
        while ( v10 != 0 );
        v35.radius = 0.0;
        v35.isConvex = false;
        v35.pad[2] = 0;
        v35.pad[1] = 0;
        v35.pad[0] = 0;
        idRenderModelDiscreteAnimation::GetPieceTraceModel(this: v3, index: v7, traceModel: &v35);
        idRenderModelDiscreteAnimation::GetPiecePosition(this: v3, index: v7, position: &v33, orientation: &v34);
        idTraceModel::Rotate(this: &v35, rotation: &v34);
        idTraceModel::Translate(this: &v35, translation: &v33);
        v12 = (idClipModel *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0xD8u,
                               tag: TAG_CLIPMODEL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
        v32 = v12;
        if ( v12 != nullptr )
          v13 = idClipModel::idClipModel(
                  this: v12,
                  clip: &clientGame->clip,
                  trm: &v35,
                  numTraceModels: 1,
                  material: this->clipModelInfo.overrideClipMaterial);
        else
          v13 = nullptr;
        ((void (__fastcall *)(idPhysics *, idClipModel *, double))this->physicsObj->SetClipModel)(
          a1: this->physicsObj,
          a2: v13,
          a3: this->density);
        this->physicsObj->SetContents(this: this->physicsObj, a2: 0x2000, a3: v7++);
        _FP2 = (float)(v31.b[0].x - v35.bounds.b[0].x);
        _FP1 = (float)(v31.b[0].y - v35.bounds.b[0].y);
        _FP30 = (float)(v31.b[0].z - v35.bounds.b[0].z);
        _FP29 = (float)(v35.bounds.b[1].x - v31.b[1].x);
        _FP28 = (float)(v35.bounds.b[1].y - v31.b[1].y);
        _FP27 = (float)(v35.bounds.b[1].z - v31.b[1].z);
        __asm { fsel      f0, f2, f13, f0 }
        v31.b[0].x = _FP0;
        __asm { fsel      f13, f1, f11, f12 }
        v31.b[0].y = _FP13;
        __asm { fsel      f12, f30, f9, f10 }
        v31.b[0].z = _FP12;
        __asm { fsel      f11, f29, f8, f7 }
        v31.b[1].x = _FP11;
        __asm { fsel      f10, f28, f6, f5 }
        v31.b[1].y = _FP10;
        __asm { fsel      f9, f27, f4, f3 }
        v31.b[1].z = _FP9;
      }
      while ( v7 < num );
    }
    v36.offset.x = 0.0;
    v26 = &v36.offset.z;
    v36.offset.y = 0.0;
    v36.offset.z = 0.0;
    memset(&v36.type, 0, 20);
    v27 = 6;
    v28 = &analysisClient.viewNoteMutex;
    do
    {
      ++v28;
      *++v26 = *(float *)&v28->handle;
      --v27;
    }
    while ( v27 != 0 );
    v36.radius = 0.0;
    v36.isConvex = false;
    v36.pad[2] = 0;
    v36.pad[1] = 0;
    v36.pad[0] = 0;
    idTraceModel::SetupBox(this: &v36, boxBounds: &v31);
    v29 = (idClipModel *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xD8u,
                           tag: TAG_CLIPMODEL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    v32 = v29;
    if ( v29 != nullptr )
      v30 = idClipModel::idClipModel(
              this: v29,
              clip: &clientGame->clip,
              trm: &v36,
              numTraceModels: 1,
              material: nullptr);
    else
      v30 = nullptr;
    ((void (__fastcall *)(idPhysics *, idClipModel *, double))this->physicsObj->SetClipModel)(
      a1: this->physicsObj,
      a2: v30,
      a3: this->density);
    this->physicsObj->SetContents(this: this->physicsObj, a2: 0x20000, a3: num);
    this->physicsObj->PutToRest(this: this->physicsObj);
    idEntity::SetPhysics(this, phys: this->physicsObj);
  }
}


// ========================================================================
// __unwind$489588
// EA  : 0x82C1D50C
// RVA : 0x00C1D50C
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __fastcall _unwind_489588(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 3376 + 104), tag: a2);
}


// ========================================================================
// __unwind$489589_0
// EA  : 0x82C1D534
// RVA : 0x00C1D534
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void _unwind_489589_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 3376 + 104), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$489590
// EA  : 0x82C1D560
// RVA : 0x00C1D560
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void _unwind_489590()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 3376 + 104), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?AllSettled@idDamageableEntity@@AAA_NXZ
// EA  : 0x82C1D590
// RVA : 0x00C1D590
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

int __fastcall idDamageableEntity::AllSettled(idDamageableEntity *this)
{
  int num; // r9
  int v2; // r10
  int i; // r11

  num = this->breakablePhysics.rigidBodies.num;
  v2 = 0;
  if ( num <= 0 )
    return 1;
  for ( i = 0; this->breakablePhysics.rigidBodies.list[i]->settled; ++i )
  {
    if ( ++v2 >= num )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?DeactivatePhysics@idDamageableEntity@@UAAXH@Z
// EA  : 0x82C1D5D8
// RVA : 0x00C1D5D8
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __fastcall idDamageableEntity::DeactivatePhysics(idDamageableEntity *this, const int physId)
{
  int num; // r9
  char v4; // r7
  int v5; // r10
  int v6; // r11
  idPhysics *Physics; // r3

  num = this->breakablePhysics.rigidBodies.num;
  v4 = 0;
  v5 = 0;
  if ( num > 0 )
  {
    v6 = 0;
    while ( !this->breakablePhysics.rigidBodies.list[v6]->active )
    {
      ++v5;
      ++v6;
      if ( v5 >= num )
        goto LABEL_7;
    }
    v4 = 1;
  }
LABEL_7:
  if ( v4 == 0 )
  {
    Physics = idEntity::GetPhysics(this);
    Physics->PutToRest(this: Physics);
    if ( this->state != DEAD )
      idEntity::BecomeInactive(this, flags: 2);
  }
}


// ========================================================================
// ?CheckDamagedPieces@idDamageableEntity@@AAAXXZ
// EA  : 0x82C1D680
// RVA : 0x00C1D680
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __fastcall idDamageableEntity::CheckDamagedPieces(idDamageableEntity *this)
{
  int num; // r11
  int v3; // r29
  int hitsTaken; // r28
  int v5; // r30
  idPhysics *Physics; // r3
  idPhysics *v7; // r3
  idPhysics *v8; // r30
  idPhysics *v9; // r29
  const idMat3 *v10; // r30
  const idVec3 *v11; // r3
  idRenderModel *RenderModelFromPresentable; // r3
  int v13; // r30
  float z; // [sp+58h] [-38h]

  if ( this->state != BREAKABLE )
  {
    num = this->breakablePhysics.rigidBodies.num;
    v3 = 0;
    hitsTaken = this->hitsTaken;
    v5 = 0;
    this->hitsTaken = 0;
    if ( num > 0 )
    {
      do
      {
        if ( this->breakablePhysics.rigidBodies.list[v3]->active )
        {
          Physics = idEntity::GetPhysics(this);
          Physics->SetContents(this: Physics, a2: 0, a3: v5);
          ++this->hitsTaken;
        }
        ++v5;
        ++v3;
      }
      while ( v5 < this->breakablePhysics.rigidBodies.num );
    }
    if ( this->hitsTaken >= 0 )
    {
      v7 = idEntity::GetPhysics(this);
      z = v7->GetAbsBounds(this: v7, a2: -1)->b[0].z;
      v8 = idEntity::GetPhysics(this);
      v9 = idEntity::GetPhysics(this);
      v10 = v8->GetAxis(this: v8, a2: 0);
      v11 = v9->GetOrigin(this: v9, a2: 0);
      if ( (unsigned __int8)idEffectPhysicsBreakable::ActivateFloatingPieces(
                              this: &this->breakablePhysics,
                              origin: v11,
                              axis: v10,
                              floor: z) != 0 )
        idDamageableEntity::CheckDamagedPieces(this);
    }
    if ( this->hitsTaken > hitsTaken )
    {
      idEntity::BecomeActive(this, flags: 2);
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_CRASH,
        shader: this->sndBreak,
        soundShaderFlags: 0,
        peerMask: 0xFFu);
      RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
      v13 = *((_DWORD *)_RTDynamicCast(
                          inptr: RenderModelFromPresentable,
                          VfDelta: 0,
                          SrcType: &idRenderModel `RTTI Type Descriptor',
                          TargetType: &idRenderModelDiscreteAnimation `RTTI Type Descriptor',
                          isReference: 0)
            + 509);
      this->breakableTime = (int)(float)(*(float *)(v13 + 108) * (float)1000.0)
                          + idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    }
  }
}


// ========================================================================
// ?SetOrigin@idDamageableEntity@@UAAXABVidVec3@@@Z
// EA  : 0x82C1D860
// RVA : 0x00C1D860
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __fastcall idDamageableEntity::SetOrigin(idDamageableEntity *this, const idVec3 *org)
{
  idEntity::SetOrigin(this, org);
  idDamageableEntity::UpdateBreakableSim(this);
}


// ========================================================================
// ?SetAxis@idDamageableEntity@@UAAXABVidMat3@@@Z
// EA  : 0x82C1D898
// RVA : 0x00C1D898
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __fastcall idDamageableEntity::SetAxis(idDamageableEntity *this, const idMat3 *axis)
{
  idEntity::SetAxis(this, axis);
  idDamageableEntity::UpdateBreakableSim(this);
}


// ========================================================================
// ?SetBreakableModel@idDamageableEntity@@AAAXXZ
// EA  : 0x82C1D8D8
// RVA : 0x00C1D8D8
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __fastcall idDamageableEntity::SetBreakableModel(idDamageableEntity *this)
{
  idRenderModelDiscreteAnimation *breakableModel; // r29
  BOOL moveable; // r11
  idPresentable *presentable; // r11
  const idBounds *p_referenceBounds; // r29
  idClip *p_clip; // r27
  int entityNumber; // r26
  idPhysics *Physics; // r3
  idClipModel *v9; // r3
  idClipModel *v10; // r29
  idPhysics *v11; // r3
  idPhysics *v12; // r3
  idPhysics *v13; // r3
  idPhysics *v14; // r3
  idPresentable *v15; // r11
  idPresentable *v16; // r11
  idPresentable *v17; // r11
  idTraceModel v18; // [sp+60h] [-640h] BYREF

  if ( this->state != BREAKABLE )
    return;
  breakableModel = this->breakableModel;
  if ( idEntity::GetRenderModelFromPresentable(this) != breakableModel )
    this->SetModel(this, a2: breakableModel);
  moveable = this->moveable;
  this->state = READY_TO_BREAK;
  if ( moveable )
  {
LABEL_14:
    idDamageableEntity::SetupRigidBodyPhysics(this);
    goto LABEL_15;
  }
  if ( !this->useStaticMulti )
  {
    if ( !this->useRigidBody )
    {
      presentable = this->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        presentable = this->presentable;
      }
      p_referenceBounds = &presentable->model->referenceBounds;
      idTraceModel::InitBox(this: &v18);
      idTraceModel::SetupBox(this: &v18, boxBounds: p_referenceBounds);
      p_clip = &clientGame->clip;
      entityNumber = this->entityNumber;
      Physics = idEntity::GetPhysics(this);
      idPhysics::InitPhysics(
        this: Physics,
        clip_: p_clip,
        callbacks_: &this->physicsCallbacks,
        entityNumber_: entityNumber);
      v9 = (idClipModel *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0xD8u,
                            tag: TAG_CLIPMODEL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
      if ( v9 != nullptr )
        v10 = idClipModel::idClipModel(
                this: v9,
                clip: &clientGame->clip,
                trm: &v18,
                numTraceModels: 1,
                material: nullptr);
      else
        v10 = nullptr;
      v11 = idEntity::GetPhysics(this);
      ((void (__fastcall *)(idPhysics *, idClipModel *, double))v11->SetClipModel)(a1: v11, a2: v10, a3: this->density);
      v12 = idEntity::GetPhysics(this);
      v12->SetContents(this: v12, a2: 139584, a3: -1);
      v13 = idEntity::GetPhysics(this);
      v13->SetClipMask(this: v13, a2: 1, a3: -1);
      v14 = idEntity::GetPhysics(this);
      this->DeactivatePhysics(this, a2: v14->physicsId);
      goto LABEL_15;
    }
    goto LABEL_14;
  }
  idDamageableEntity::SetupStaticMultiPhysics(this);
LABEL_15:
  v15 = this->presentable;
  if ( v15 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v15 = this->presentable;
  }
  v15->origin = vec3_origin;
  v16 = this->presentable;
  if ( v16 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v16 = this->presentable;
  }
  v16->axis = mat3_identity;
  v17 = this->presentable;
  if ( v17 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v17 = this->presentable;
  }
  v17->Present(this: v17);
}


// ========================================================================
// __unwind$489982
// EA  : 0x82C1DBA4
// RVA : 0x00C1DBA4
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void _unwind_489982()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1696 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?BreakBreakable@idDamageableEntity@@AAA_NABVidVec3@@@Z
// EA  : 0x82C1DBD0
// RVA : 0x00C1DBD0
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

int __fastcall idDamageableEntity::BreakBreakable(
        idDamageableEntity *this,
        const idVec3 *source,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        float a35,
        float a36,
        float a37,
        float a38,
        float a39,
        float a40,
        int a41,
        int a42,
        float x,
        float a44,
        float a45,
        int a46,
        int a47,
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        idClipModel *a63)
{
  __int64 v63; // r4
  int v64; // r31
  const idVec3 *v65; // r26
  idPhysics *Physics; // r3
  int v67; // r3
  int *v68; // r10
  _DWORD *v69; // r11
  int i; // ctr
  const char *ClipModelsTouchingBounds; // r3
  idClipModel **v72; // r30
  const char *j; // r29
  idPhysics *PhysicsForId; // r3
  physicsType_t type; // r10
  idPhysicsCallbacks *callbacks; // r27
  idPhysics *v77; // r3
  idVec3 *v79; // r11
  int v80; // r11
  int GameMsPerFrame; // r3
  idPhysics *v82; // r3
  void (__fastcall ***v83)(_DWORD, int); // r3
  idPhysics *v84; // r3
  int v85; // r3
  int *v86; // r10
  _DWORD *v87; // r11
  int k; // ctr
  idPhysics *v89; // r3
  const idVec3 *v90; // r3
  float y; // r7
  float z; // r6
  idPhysics *v93; // r3
  idPhysics *v94; // r3
  int v95; // r11
  int v96; // r11

  v63 = ((__int64 (*)(void))RtlCheckStack12)();
  v64 = HIDWORD(v63);
  v65 = (const idVec3 *)v63;
  if ( *(float *)(HIDWORD(v63) + 800) < (double)(float)(*(float *)(HIDWORD(v63) + 1172) * *(float *)(HIDWORD(v63) + 804)) )
  {
    Physics = idEntity::GetPhysics(this: (idEntity *)HIDWORD(v63));
    v67 = (int)Physics->GetAbsBounds(this: Physics, a2: -1);
    v68 = &a34;
    v69 = (_DWORD *)(v67 - 4);
    for ( i = 6; i != 0; --i )
      *++v68 = *++v69;
    a35 = a35 - (float)16.0;
    a36 = a36 - (float)16.0;
    a37 = a37 - (float)16.0;
    a38 = a38 + (float)16.0;
    a39 = a39 + (float)16.0;
    a40 = a40 + (float)16.0;
    ClipModelsTouchingBounds = idClip::GetClipModelsTouchingBounds(
                                 this: &clientGame->clip,
                                 bounds: (const idBounds *)&a35,
                                 clipMask: -1,
                                 clipModelList: &a63,
                                 maxCount: (const char *)0x2000);
    if ( (int)ClipModelsTouchingBounds > 0 )
    {
      v72 = &a63;
      for ( j = ClipModelsTouchingBounds; j != nullptr; --j )
      {
        PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: (*v72)->physicsId);
        if ( PhysicsForId != nullptr )
        {
          type = PhysicsForId->type;
          if ( type != PHYSICS_STATIC && type != PHYSICS_STATICMULTI )
          {
            callbacks = PhysicsForId->callbacks;
            v77 = idEntity::GetPhysics(this: (idEntity *)v64);
            callbacks->ActivatePhysics(this: callbacks, a2: v77->physicsId);
          }
        }
        ++v72;
      }
    }
    if ( *(_BYTE *)(v64 + 1193) != 0 && idEntity::GetPhysics(this: (idEntity *)v64)->type == PHYSICS_RIGIDBODY )
    {
      if ( *(float *)(v64 + 800) > 0.0 )
        return 0;
      if ( *(_DWORD *)(v64 + 1684) == 1 )
      {
        (*(void (__fastcall **)(int, _DWORD))(*(_DWORD *)v64 + 88))(a1: v64, a2: *(_DWORD *)(v64 + 1688));
        v79 = *(idVec3 **)(v64 + 488);
        *(_DWORD *)(v64 + 1684) = 2;
        if ( v79 == nullptr )
        {
          idEntity::InitPresentableInternal(this: (idEntity *)v64);
          v79 = *(idVec3 **)(v64 + 488);
        }
        v79[10] = vec3_origin;
        v80 = *(_DWORD *)(v64 + 488);
        if ( v80 == 0 )
        {
          idEntity::InitPresentableInternal(this: (idEntity *)v64);
          v80 = *(_DWORD *)(v64 + 488);
        }
        *(idMat3 *)(v80 + 132) = mat3_identity;
      }
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idEffectPhysicsBreakable::UpdateModel(
        this: (idEffectPhysicsBreakable *)(v64 + 820),
        origin: &vec3_origin,
        axis: &mat3_identity,
        gameMsPerFrame: GameMsPerFrame);
      v82 = idEntity::GetPhysics(this: (idEntity *)v64);
      v82->UnlinkClip(this: v82);
      if ( *(_DWORD *)(v64 + 808) != 0 )
      {
        idEntity::SetPhysics(this: (idEntity *)v64, phys: nullptr);
        v83 = *(void (__fastcall ****)(_DWORD, int))(v64 + 808);
        if ( v83 != nullptr )
          (**v83)(a1: v83, a2: 1);
        *(_DWORD *)(v64 + 808) = 0;
      }
      if ( *(_BYTE *)(v64 + 817) != 0 )
      {
        v84 = idEntity::GetPhysics(this: (idEntity *)v64);
        v85 = (int)v84->GetAxis(this: v84, a2: 0);
        v86 = &a50;
        v87 = (_DWORD *)(v85 - 4);
        for ( k = 9; k != 0; --k )
          *++v86 = *++v87;
        v89 = idEntity::GetPhysics(this: (idEntity *)v64);
        v90 = v89->GetOrigin(this: v89, a2: 0);
        y = v90->y;
        z = v90->z;
        x = v90->x;
        a44 = y;
        a45 = z;
        idDamageableEntity::SetupStaticMultiPhysics(this: (idDamageableEntity *)v64);
        v93 = idEntity::GetPhysics(this: (idEntity *)v64);
        v93->SetOrigin(this: v93, a2: (const idVec3 *)&x, a3: -1);
        v94 = idEntity::GetPhysics(this: (idEntity *)v64);
        v94->SetAxis(this: v94, a2: (const idMat3 *)&a51, a3: -1);
      }
    }
    v95 = *(_DWORD *)(v64 + 1684);
    if ( v95 == 1 )
    {
      idDamageableEntity::SetBreakableModel(this: (idDamageableEntity *)v64);
    }
    else if ( v95 == 0 && *(_DWORD *)(v64 + 1692) != 0 && *(float *)(v64 + 800) <= 0.0 )
    {
      (*(void (__fastcall **)(int))(*(_DWORD *)v64 + 88))(a1: v64);
      *(_DWORD *)(v64 + 1692) = 0;
      idDamageableEntity::ReorientSwap(this: (idDamageableEntity *)v64, spot: v65);
    }
    v96 = *(_DWORD *)(v64 + 1684);
    if ( v96 == 2 || v96 == 3 && *(float *)(v64 + 800) <= 0.0 )
    {
      idEntity::BecomeActive(this: (idEntity *)v64, flags: 2);
      *(_DWORD *)(v64 + 1684) = 3;
      idDamageableEntity::ActivateAll(this: (idDamageableEntity *)v64);
      if ( *(float *)(v64 + 800) <= 0.0 )
      {
        idDamageableEntity::StartExplosions(this: (idDamageableEntity *)v64);
        idEntity::ForceDormancy(this: (idEntity *)v64, dormant: false, durationMS: 30000);
        idEventReceiver::ProcessEvent(
          this: (idEventReceiver *)&x,
          result: (idEventArg *)v64,
          ev: &EV_NotifyProgressionOwner);
      }
    }
    else if ( v96 == 4 )
    {
      idEntity::BecomeActive(this: (idEntity *)v64, flags: 2);
      return 1;
    }
  }
  return 1;
}


// ========================================================================
// ?Think@idDamageableEntity@@UAAXXZ
// EA  : 0x82C1E080
// RVA : 0x00C1E080
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDamageableEntity::Think(idDamageableEntity *this)
{
  idPhysics *Physics; // r3
  const idBounds *v3; // r3
  char v4; // r22
  char v5; // r23
  idPresentable *v6; // r3
  int GameMs; // r3
  int fadeStartTime; // r11
  __int128 v9; // r7
  double v10; // fp31
  idPresentable *presentable; // r11
  int v12; // r3
  idPresentable *v13; // r11
  __int64 v14; // r10 OVERLAPPED
  int PreviousGameMs; // r29
  int num; // r11
  double v17; // fp13
  double v18; // fp7
  idPhysics *v19; // r3
  int v20; // r29
  int v21; // r28
  idPhysics *v22; // r3
  int GameMsPerFrame; // r28
  int v24; // r3
  idPresentable *v25; // r11
  int v26; // r27
  idPresentable *v27; // r29
  int v28; // r10
  int v29; // r9
  int v30; // r8
  int v31; // r7
  int v32; // r6
  int v33; // r5
  idPhysics *v34; // r29
  idPhysics *v35; // r28
  int v36; // r27
  const idMat3 *v37; // r29
  const idVec3 *v38; // r3
  idPhysics *v39; // r29
  idPhysics *v40; // r3
  __int64 v41; // r9
  idPhysics *v42; // r28
  unsigned int v43; // r6
  double v44; // fp29
  int v45; // r27
  int v46; // r23
  const idVec3 *v47; // r29
  const idMat3 *v48; // r28
  const idDeclParticle *swapParticle; // r21
  idRenderModelEffects *MergeBranch; // r3
  const idVec3 *v51; // r7
  idPhysics *v52; // r3
  int fadeTime; // r9
  int v54; // r8
  enum idAIStateTransition::aiTransCode_t (__fastcall **v55)(COMBAT_AtPlugAnim *__hidden, struct idAI2 *, struct idAIFSM *, struct idAIState *, int); // r7
  int v56; // r6
  int v57; // r5
  float *v58; // r3
  idDamageableEntity::breakState_t state; // r11
  int v60; // r3
  idPhysics *v61; // r3
  idClipModel *v62; // r3
  idPlayer *Player; // r30
  idPhysics *v64; // r28
  idPhysics *v65; // r30
  float *v66; // r28
  float *v67; // r3
  double v68; // fp10
  double v69; // fp8
  unsigned int v70; // r30
  idPhysics *v71; // r29
  idPhysics *v72; // r28
  const idMat3 *v73; // r29
  const idVec3 *v74; // r3
  int useStaticMulti; // r10
  idPhysics *v76; // r30
  idPhysics *v77; // r29
  double z; // fp31
  const idMat3 *v79; // r30
  const idVec3 *v80; // r3
  idDamageableEntity::breakState_t v81; // r11
  int v82; // [sp+8h] [-E8h]
  int v83; // [sp+Ch] [-E4h]
  int v84; // [sp+10h] [-E0h]
  int v85; // [sp+14h] [-DCh]
  int v86; // [sp+18h] [-D8h]
  idEffectPhysicsBroadPhase *v87; // [sp+1Ch] [-D4h]
  int v88; // [sp+20h] [-D0h]
  int v89; // [sp+24h] [-CCh]
  int v90; // [sp+28h] [-C8h]
  int v91; // [sp+2Ch] [-C4h]
  int v92; // [sp+30h] [-C0h]
  int v93; // [sp+34h] [-BCh]
  int v94; // [sp+38h] [-B8h]
  int v95; // [sp+3Ch] [-B4h]
  int v96; // [sp+40h] [-B0h]
  int v97; // [sp+44h] [-ACh]
  int v98; // [sp+48h] [-A8h]
  int v99; // [sp+4Ch] [-A4h]
  int v100; // [sp+50h] [-A0h]
  __int64 v101; // [sp+60h] [-90h] BYREF
  __int64 v102; // [sp+68h] [-88h] BYREF

  if ( !idEntity::UpdateDormant(this) )
  {
    idEntity::RunPhysics(this);
    this->UpdateFX(this);
    Physics = idEntity::GetPhysics(this);
    v3 = Physics->GetAbsBounds(this: Physics, a2: -1);
    idEntity::UpdatePVSAreas(this, bounds: v3);
    v4 = 0;
    v5 = 0;
    if ( this->fadeStartTime > 0
      && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->fadeStartTime )
    {
      if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < this->fadeEndTime )
      {
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        fadeStartTime = this->fadeStartTime;
        LODWORD(v9) = GameMs - fadeStartTime;
        DWORD2(v9) = this->fadeEndTime - fadeStartTime;
        v101 = *(_QWORD *)((char *)&v9 + 4);
        v10 = (float)((float)1.0 - (float)((float)(__int64)v9 / (float)*(__int64 *)((char *)&v9 + 4)));
        if ( v10 < 1.0 && this->fadeParticle != nullptr )
        {
          presentable = this->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            presentable = this->presentable;
          }
          if ( presentable->model->g.modelFade == 1.0 )
          {
            v12 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            idEffectPhysicsBreakable::EmitSmokeForEachPiece(
              this: &this->breakablePhysics,
              p: this->fadeParticle,
              time: v12);
          }
        }
        v13 = this->presentable;
        if ( v13 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v13 = this->presentable;
        }
        idRenderModel::SetModelFade(this: v13->model, v: v10);
      }
      else
      {
        v6 = this->presentable;
        if ( v6 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v6 = this->presentable;
        }
        v6->Hide(this: v6, a2: true);
        this->fadeStartTime = -1;
        idEntity::BecomeInactive(this, flags: 7);
        idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
      }
    }
    if ( (this->thinkFlags & 2) != 0 )
    {
      if ( this->state > READY_TO_BREAK )
      {
        idDamageableEntity::UpdateBreakableSim(this);
        v5 = 1;
        if ( this->state == DEAD )
        {
          if ( this->maxSimulationTime <= 0 )
          {
            v4 = 1;
          }
          else
          {
            PreviousGameMs = idGameTimeManager::GetPreviousGameMs(
                               this: &clientGame->gameTimeManager,
                               type: GAMETIME_SCALED);
            this->maxSimulationTime -= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - PreviousGameMs;
          }
        }
        else
        {
          LODWORD(v14) = this->hitsTaken;
          num = this->breakablePhysics.rigidBodies.num;
          if ( (_DWORD)v14 == num )
          {
            idDamageableEntity::StartExplosions(this);
            this->state = DEAD;
          }
          else
          {
            HIDWORD(v14) = this->breakablePhysics.rigidBodies.num;
            v17 = (float)v14;
            v18 = (float)(this->destructionPercent * (float)*(__int64 *)((char *)&v14 + 4));
            v101 = *(__int64 *)((char *)&v14 + 4);
            if ( v17 < v18 )
            {
              if ( v17 >= (float)(this->noClipPercent * (float)*(__int64 *)((char *)&v14 + 4)) )
              {
                v20 = 0;
                if ( num > 0 )
                {
                  v21 = 0;
                  do
                  {
                    if ( !this->breakablePhysics.rigidBodies.list[v21]->active )
                    {
                      v22 = idEntity::GetPhysics(this);
                      v22->SetContents(this: v22, a2: 128, a3: v20);
                    }
                    ++v20;
                    ++v21;
                  }
                  while ( v20 < this->breakablePhysics.rigidBodies.num );
                }
              }
            }
            else
            {
              this->state = DEAD;
              v19 = idEntity::GetPhysics(this);
              v19->SetContents(this: v19, a2: 0, a3: -1);
              this->hitsTaken = this->breakablePhysics.rigidBodies.num;
              idDamageableEntity::StartExplosions(this);
            }
          }
        }
      }
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v24 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v25 = this->presentable;
      v26 = v24;
      if ( v25 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v25 = this->presentable;
      }
      v27 = v25;
      if ( v25 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v25 = this->presentable;
      }
      idEffectPhysicsDebrisEmitter::Update(
        this: &this->debrisEmitter,
        origin: &v25->origin,
        axis: &v27->axis,
        drawScale3D: &this->debrisScale,
        currentTime: v26,
        gameMsPerFrame: GameMsPerFrame);
      idClientGame::AddSimulatingEffectPhysics(
        this: clientGame,
        broadPhase: &this->debrisEmitter.piecePhysics.broadPhase,
        a3: v33,
        a4: v32,
        a5: v31,
        a6: v30,
        a7: v29,
        a8: v28,
        a9: v82,
        a10: v83,
        a11: v84,
        a12: v85,
        a13: v86,
        a14: v87);
    }
    if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: this) == 0 && v5 == 0 )
    {
      if ( this->state != UNBREAKABLE )
      {
        v34 = idEntity::GetPhysics(this);
        v35 = idEntity::GetPhysics(this);
        v36 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v37 = v34->GetAxis(this: v34, a2: 0);
        v38 = v35->GetOrigin(this: v35, a2: 0);
        idEffectPhysicsBreakable::UpdateModel(
          this: &this->breakablePhysics,
          origin: v38,
          axis: v37,
          gameMsPerFrame: v36);
      }
      else
      {
        idEntity::UpdateVisuals(this);
      }
    }
    if ( this->swapParticle != nullptr
      && this->health <= 0.0
      && this->state != DEAD
      && (this->fadeStartTime == 0
       || idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < this->fadeStartTime) )
    {
      HIDWORD(v101) = -1;
      v39 = idEntity::GetPhysics(this);
      v40 = idEntity::GetPhysics(this);
      HIDWORD(v41) = 1664525;
      v42 = v40;
      v43 = 1664525 * clientGame->random.seed;
      clientGame->random.seed = v43 + 1013904223;
      LODWORD(v41) = ((v43 + 1013904223) >> 10) & 0x7FFF;
      v102 = v41;
      v44 = (float)((float)v41 * (float)0.000030518509);
      v45 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v46 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v47 = (const idVec3 *)v39->GetAxis(this: v39, a2: 0);
      v48 = (const idMat3 *)v42->GetOrigin(this: v42, a2: 0);
      swapParticle = this->swapParticle;
      MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
      idRenderModelEffects::AddParticles(
        this: MergeBranch,
        particle: swapParticle,
        systemStartTime: v46,
        gameMsPerFrame: v45,
        diversity: v44,
        origin: v51,
        axis: v48,
        velocity: v47,
        color: &vec3_origin.x,
        a10: v82,
        a11: v83,
        a12: v84,
        a13: v85,
        a14: v86,
        a15: (int)v87,
        a16: v88,
        a17: v89,
        a18: v90,
        a19: v91,
        a20: v92,
        a21: v93,
        a22: v94,
        a23: v95,
        a24: v96,
        a25: v97,
        a26: v98,
        a27: v99,
        a28: v100,
        a29: (unsigned int *)&v101);
    }
    if ( v4 != 0
      || (v52 = idEntity::GetPhysics(this),
          (float)((float)((v58 = (float *)v52->GetLinearVelocity(this: (idPhysics *)&v102, result: (idVec3 *)v52, a3: 0))[2]
                        * v58[2])
                + (float)((float)(*v58 * *v58) + (float)(v58[1] * v58[1]))) < 1.0)
      && this->health <= 0.0
      && this->lastBump > 0
      && this->fadeStartTime == 0
      && ((state = this->state) == DEAD || state == UNBREAKABLE)
      && (unsigned __int8)idDamageableEntity::AllSettled(this) != 0
      && (v60 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED),
          fadeTime = this->lastBump + 1000,
          v60 > fadeTime) )
    {
      idEntity::BecomeInactive(this, flags: 2);
      idEntity::BecomeActive(this, flags: 1);
      idEffectPhysicsPieceEmitter::Reset(this: &this->debrisEmitter.piecePhysics);
      if ( this->health <= 0.0 )
      {
        this->state = DEAD;
        v61 = idEntity::GetPhysics(this);
        v62 = v61->GetClipModel(this: v61, a2: 0);
        idClipModel::Unlink(this: v62);
        fadeTime = this->fadeTime;
        if ( fadeTime >= 0 )
        {
          this->fadeStartTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                              + 500;
          this->fadeEndTime = this->fadeTime
                            + idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                            + 500;
        }
      }
    }
    if ( g_showBreakableCollision.valueInteger != 0 )
    {
      Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
      if ( Player != nullptr )
      {
        v64 = idEntity::GetPhysics(this);
        v65 = idEntity::GetPhysics(this: Player);
        v66 = (float *)v64->GetOrigin(this: v64, a2: 0);
        v67 = (float *)v65->GetOrigin(this: v65, a2: 0);
        v55 = &off_82040000;
        v68 = (float)(v67[1] - v66[1]);
        v69 = (float)(v67[2] - v66[2]);
        if ( (float)((float)((float)(*v67 - *v66) * (float)(*v67 - *v66))
                   + (float)((float)((float)v69 * (float)v69) + (float)((float)v68 * (float)v68))) < 1000000.0 )
        {
          v70 = -1 - g_showBreakableCollision.valueInteger;
          if ( g_showBreakableCollision.valueInteger >= 0 )
            v70 = -1;
          v71 = idEntity::GetPhysics(this);
          v72 = idEntity::GetPhysics(this);
          v73 = v71->GetAxis(this: v71, a2: 0);
          v74 = v72->GetOrigin(this: v72, a2: 0);
          idEffectPhysicsBreakable::DrawCollisionModels(
            this: &this->breakablePhysics,
            single: v70,
            offset: v74,
            axis: v73);
        }
      }
    }
    useStaticMulti = (int)&g_breakableDebugIslands;
    if ( g_breakableDebugIslands.valueInteger != 0 && this->physicsObj != nullptr )
    {
      v76 = idEntity::GetPhysics(this);
      v77 = idEntity::GetPhysics(this);
      z = this->physicsObj->GetAbsBounds(this: this->physicsObj, a2: -1)->b[0].z;
      v79 = v76->GetAxis(this: v76, a2: 0);
      v80 = v77->GetOrigin(this: v77, a2: 0);
      idEffectPhysicsBreakable::ActivateFloatingPieces(this: &this->breakablePhysics, origin: v80, axis: v79, floor: z);
    }
    v81 = this->state;
    if ( v81 == BREAKING && (useStaticMulti = this->useStaticMulti) != 0 || v81 != UNBREAKABLE )
      idClientGame::AddSimulatingEffectPhysics(
        this: clientGame,
        broadPhase: &this->breakablePhysics.broadPhase,
        a3: v57,
        a4: v56,
        a5: (int)v55,
        a6: v54,
        a7: fadeTime,
        a8: useStaticMulti,
        a9: v82,
        a10: v83,
        a11: v84,
        a12: v85,
        a13: v86,
        a14: v87);
  }
}


// ========================================================================
// ?ApplyRadiusDamage@idDamageableEntity@@QAAXPBVidEntity@@0PBVidDeclDamage@@ABVidVec3@@MMM@Z
// EA  : 0x82C1ECC0
// RVA : 0x00C1ECC0
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __fastcall idDamageableEntity::ApplyRadiusDamage(
        idDamageableEntity *this,
        const idEntity *inflictor,
        const idEntity *attacker,
        const idDeclDamage *damageDef,
        const idVec3 *pos,
        double damageScale,
        double radiusScale,
        double radius)
{
  __int64 v16; // r9
  double v17; // fp1
  double health; // fp0
  double v19; // fp31
  char v20; // r11
  unsigned __int8 v21; // r29
  char v22; // r11
  char v23; // r30
  int v24; // r10
  int v25; // r9
  int v26; // r7
  int v27; // r6
  int v28; // r5
  double v29; // fp8
  double v30; // fp7
  double v31; // fp6
  double v32; // fp5
  double v33; // fp4
  double v34; // fp3
  double v35; // fp2
  double v36; // fp1
  int v37; // r8
  idDamageableEntity::breakState_t state; // r11
  double valueFloat; // fp13
  double v42; // fp31
  int GameMs; // r26
  const idPhysics *Physics; // r3
  double secondBlastScale; // fp30
  int v46; // r3
  int v47; // [sp+8h] [-108h]
  bool v48; // [sp+Bh] [-105h]
  int v49; // [sp+Ch] [-104h]
  const idVec3 *v50; // [sp+Ch] [-104h]
  int v51; // [sp+10h] [-100h]
  bool v52; // [sp+13h] [-FDh]
  int v53; // [sp+14h] [-FCh]
  int v54; // [sp+14h] [-FCh]
  int v55; // [sp+18h] [-F8h]
  int v56; // [sp+18h] [-F8h]
  int v57; // [sp+1Ch] [-F4h]
  int v58; // [sp+1Ch] [-F4h]
  int v59; // [sp+20h] [-F0h]
  int v60; // [sp+20h] [-F0h]
  int v61; // [sp+24h] [-ECh]
  int v62; // [sp+24h] [-ECh]
  int v63; // [sp+28h] [-E8h]
  int v64; // [sp+28h] [-E8h]
  int v65; // [sp+2Ch] [-E4h]
  int v66; // [sp+2Ch] [-E4h]
  int v67; // [sp+30h] [-E0h]
  int v68; // [sp+30h] [-E0h]
  int v69; // [sp+34h] [-DCh]
  int v70; // [sp+34h] [-DCh]
  int v71; // [sp+38h] [-D8h]
  int v72; // [sp+38h] [-D8h]
  int v73; // [sp+3Ch] [-D4h]
  int v74; // [sp+3Ch] [-D4h]
  int v75; // [sp+40h] [-D0h]
  int v76; // [sp+40h] [-D0h]
  int v77; // [sp+44h] [-CCh]
  int v78; // [sp+44h] [-CCh]
  int v79; // [sp+48h] [-C8h]
  int v80; // [sp+48h] [-C8h]
  int v81; // [sp+4Ch] [-C4h]
  int v82; // [sp+4Ch] [-C4h]
  float v83; // [sp+50h] [-C0h]
  int v84; // [sp+50h] [-C0h]
  float v85; // [sp+54h] [-BCh]
  float v86; // [sp+58h] [-B8h]
  int v87; // [sp+58h] [-B8h]
  float v88; // [sp+5Ch] [-B4h]
  float v89; // [sp+60h] [-B0h]
  int v90; // [sp+60h] [-B0h]
  float v91; // [sp+64h] [-ACh]
  int v92; // [sp+68h] [-A8h]
  int v93; // [sp+68h] [-A8h]
  int v94; // [sp+6Ch] [-A4h]
  float v95; // [sp+70h] [-A0h]
  int v96; // [sp+70h] [-A0h]
  float v97; // [sp+74h] [-9Ch]
  int v98; // [sp+74h] [-9Ch]
  float v99; // [sp+78h] [-98h]
  int v100; // [sp+78h] [-98h]
  int v101; // [sp+7Ch] [-94h]
  int v102; // [sp+80h] [-90h]
  int v103; // [sp+80h] [-90h]
  int v104; // [sp+84h] [-8Ch]
  int v105; // [sp+88h] [-88h]
  int v106; // [sp+88h] [-88h]
  int v107; // [sp+8Ch] [-84h]
  __int64 v108; // [sp+90h] [-80h]
  int v109; // [sp+98h] [-78h]
  int v110; // [sp+9Ch] [-74h]
  int v111; // [sp+A0h] [-70h]
  int v112; // [sp+A4h] [-6Ch]
  int v113; // [sp+A8h] [-68h]
  int v114; // [sp+ACh] [-64h]
  int v115; // [sp+B0h] [-60h]
  int v116; // [sp+B4h] [-5Ch]
  int v117; // [sp+B8h] [-58h]
  int v118; // [sp+BCh] [-54h]
  idClipModel *v119; // [sp+C0h] [-50h]

  if ( damageDef != nullptr )
  {
    v17 = idDeclDamage::DamageAmount(this: damageDef);
    health = this->health;
    v19 = (float)((float)v17 * (float)damageScale);
    if ( health <= 0.0
      || !this->radiusDamageKills
      || (LODWORD(v16) = this->armorValue, v20 = 1, v108 = v16, v19 <= (float)((float)v16 * (float)0.5)) )
    {
      v20 = 0;
    }
    v21 = v20;
    if ( this->state == UNBREAKABLE || (v22 = 1, health >= (float)(this->resistPercent * this->healthMax)) )
      v22 = 0;
    v23 = v22;
    LOBYTE(v88) = v21;
    LOBYTE(v85) = v22;
    ((void (__fastcall *)(idDamageableEntity *, const idEntity *, const idEntity *, const idDeclDamage *, const idVec3 *, double, double, double))this->InternalApplyRadiusDamage)(
      a1: this,
      a2: inflictor,
      a3: attacker,
      a4: damageDef,
      a5: pos,
      a6: damageScale,
      a7: radiusScale,
      a8: radius);
    v37 = v21;
    if ( v21 != 0 )
    {
      state = this->state;
      this->health = 0.0;
      if ( state != UNBREAKABLE )
        idDamageableEntity::StartExplosions(this);
    }
    if ( v23 != 0 )
    {
      idDamageableEntity::BreakBreakable(
        this,
        source: pos,
        a3: v36,
        a4: v35,
        a5: v34,
        a6: v33,
        a7: v32,
        a8: v31,
        a9: v30,
        a10: v29,
        a11: v28,
        a12: v27,
        a13: v26,
        a14: v37,
        a15: v25,
        a16: v24,
        a17: v47,
        a18: v49,
        a19: v51,
        a20: v53,
        a21: v55,
        a22: v57,
        a23: v59,
        a24: v61,
        a25: v63,
        a26: v65,
        a27: v67,
        a28: v69,
        a29: v71,
        a30: v73,
        a31: v75,
        a32: v77,
        a33: v79,
        a34: v81,
        a35: v83,
        a36: v85,
        a37: v86,
        a38: v88,
        a39: v89,
        a40: v91,
        a41: v92,
        a42: v94,
        x: v95,
        a44: v97,
        a45: v99,
        a46: v101,
        a47: v102,
        a48: v104,
        a49: v105,
        a50: v107,
        a51: SHIDWORD(v108),
        a52: v108,
        a53: v109,
        a54: v110,
        a55: v111,
        a56: v112,
        a57: v113,
        a58: v114,
        a59: v115,
        a60: v116,
        a61: v117,
        a62: v118,
        a63: v119);
      if ( this->health > 0.0 )
      {
        valueFloat = g_damageablePowerBase.valueFloat;
      }
      else
      {
        _FP12 = (float)((float)v19 - (float)1000.0);
        __asm { fsel      f11, f12, f0, f31 }
        valueFloat = (float)((float)_FP11 + g_damageablePowerBase.valueFloat);
      }
      v42 = (float)((float)valueFloat * g_damageablePowerScale.valueFloat);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      Physics = idEntity::GetPhysics(this);
      idEffectPhysicsBreakable::AddRadiusImpact(
        this: &this->breakablePhysics,
        time: GameMs,
        physics: Physics,
        pos,
        radius,
        power: v42);
      if ( this->health <= 0.0 )
      {
        secondBlastScale = g_breakableExplosionImpulseScale.valueFloat;
        if ( g_breakableExplosionImpulseScale.valueFloat == -1.0 )
          secondBlastScale = this->secondBlastScale;
        v46 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idEffectPhysicsBreakable::AddExplosion(
          this: &this->breakablePhysics,
          particle: nullptr,
          time: v46,
          position: pos,
          radius,
          impulse: (float)((float)secondBlastScale * (float)v42),
          falloff: 0.2,
          angular: 350.0,
          delay: 500,
          duration: (const int)&vec3_origin,
          startNow: (const bool)allocationCurrent[242],
          activateAllDelay: 1,
          distTimeScaleDelay: 0.0,
          useLinear: v48,
          endLinear: v50,
          localSpace: v52,
          a17: v54,
          a18: v56,
          a19: v58,
          a20: v60,
          a21: v62,
          a22: v64,
          a23: v66,
          a24: v68,
          a25: v70,
          a26: v72,
          a27: v74,
          a28: v76,
          a29: v78,
          a30: v80,
          a31: v82,
          a32: v84,
          a33: 500,
          a34: v87,
          a35: 100,
          a36: v90,
          a37: 1,
          a38: v93,
          a39: -1,
          a40: v96,
          delay_0: v98,
          a42: v100,
          duration_0_3: false,
          a44: v103,
          a45: &vec3_origin.x,
          a46: v106,
          activateAllDelay_0_3: false);
      }
      idDamageableEntity::CheckDamagedPieces(this);
    }
  }
}


// ========================================================================
// ?Spawn@idDamageableEntity@@QAAXXZ
// EA  : 0x82C1EF58
// RVA : 0x00C1EF58
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __fastcall idDamageableEntity::Spawn(idDamageableEntity *this)
{
  idRenderModel *v2; // r3
  idRenderModelDiscreteAnimation *v3; // r3
  idRenderModel *RenderModelFromPresentable; // r3
  idRenderModel *v5; // r29
  idRenderModelDiscreteAnimation *v6; // r3
  idDamageableEntity_vtbl *v7; // r11
  idDamageableEntity_vtbl *v8; // r10
  idDamageableEntity::breakState_t state; // r11
  idBounds *p_referenceBounds; // r29
  idPhysics *v11; // r3
  int entityNumber; // r26
  idClip *p_clip; // r25
  idPhysics *v14; // r3
  idClipModel *v15; // r3
  idClipModel *v16; // r29
  idPhysics *v17; // r3
  idPhysics *v18; // r3
  idPhysics *v19; // r3
  idPhysics *v20; // r3
  idPhysics *Physics; // r3
  idRenderModelDiscreteAnimation *breakableModel; // r29
  idSoundEmitter *SoundEmitter; // r3
  const idDeclImpactSound *impactSoundTable; // r8
  double v25; // fp13
  const idDeclBreakable *breakableDebris; // r11
  int v27; // r29
  idRenderModelEffects *MergeBranch; // r3
  int v29; // r10
  int v30; // r9
  int v31; // r8
  int v32; // r7
  idPresentable *presentable; // r3
  idPhysics *v34; // r28
  idPresentable *v35; // r27
  int v36; // r3
  int v37; // r10
  int v38; // r9
  int v39; // r8
  int v40; // r7
  int v41; // r6
  int v42; // r5
  idPresentable *v43; // r11
  int v44; // [sp+8h] [-6A8h]
  int v45; // [sp+Ch] [-6A4h]
  int v46; // [sp+10h] [-6A0h]
  int v47; // [sp+14h] [-69Ch]
  int v48; // [sp+18h] [-698h]
  idPresentable *v49; // [sp+1Ch] [-694h]
  idEffectPhysicsBreakable::breakablePieceSound_t v50; // [sp+50h] [-660h] BYREF
  idClipModel *v51; // [sp+68h] [-648h]
  idTraceModel v52; // [sp+70h] [-640h] BYREF

  if ( idEntity::GetRenderModelFromPresentable(this) != nullptr )
  {
    if ( this->initialModel != nullptr )
    {
      RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
      v5 = clientGame->renderWorld->AllocRenderModel(
             this: clientGame->renderWorld,
             a2: RenderModelFromPresentable->name.str,
             a3: 1,
             a4: -1);
      v6 = (idRenderModelDiscreteAnimation *)_RTDynamicCast(
                                               inptr: v5,
                                               VfDelta: 0,
                                               SrcType: &idRenderModel `RTTI Type Descriptor',
                                               TargetType: &idRenderModelDiscreteAnimation `RTTI Type Descriptor',
                                               isReference: 0);
      this->breakableModel = v6;
      if ( v6 != nullptr )
      {
        if ( v6->declBreakable == nullptr )
          idLib::Error(fmt: "%s does not use a breakable rendermodel decl", this->name.data);
        v8 = this->__vftable;
        this->state = BREAKABLE;
        v8->SetModel(this, a2: this->initialModel);
      }
      else
      {
        v7 = this->__vftable;
        this->renderModel = v5;
        this->state = UNBREAKABLE;
        v7->SetModel(this, a2: this->initialModel);
      }
    }
    else
    {
      v2 = idEntity::GetRenderModelFromPresentable(this);
      v3 = (idRenderModelDiscreteAnimation *)_RTDynamicCast(
                                               inptr: v2,
                                               VfDelta: 0,
                                               SrcType: &idRenderModel `RTTI Type Descriptor',
                                               TargetType: &idRenderModelDiscreteAnimation `RTTI Type Descriptor',
                                               isReference: 0);
      if ( v3 != nullptr && v3->declBreakable != nullptr )
      {
        this->breakableModel = v3;
        this->state = BREAKABLE;
        idDamageableEntity::SetBreakableModel(this);
      }
      else
      {
        this->breakableModel = nullptr;
      }
    }
  }
  state = this->state;
  if ( state != READY_TO_BREAK )
  {
    if ( this->useRigidBody || this->moveable )
    {
      Physics = idEntity::GetPhysics(this);
      ((void (__fastcall *)(idPhysics *, _DWORD, double))Physics->SetClipModel)(a1: Physics, a2: 0, a3: this->density);
      idDamageableEntity::SetupRigidBodyPhysics(this);
    }
    else if ( state != UNBREAKABLE )
    {
      p_referenceBounds = &this->breakableModel->referenceBounds;
      idTraceModel::InitBox(this: &v52);
      idTraceModel::SetupBox(this: &v52, boxBounds: p_referenceBounds);
      v11 = idEntity::GetPhysics(this);
      this->deadClipModel = v11->GetClipModel(this: v11, a2: 0);
      entityNumber = this->entityNumber;
      p_clip = &clientGame->clip;
      v14 = idEntity::GetPhysics(this);
      idPhysics::InitPhysics(this: v14, clip_: p_clip, callbacks_: &this->physicsCallbacks, entityNumber_: entityNumber);
      v15 = (idClipModel *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0xD8u,
                             tag: TAG_CLIPMODEL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      v51 = v15;
      if ( v15 != nullptr )
        v16 = idClipModel::idClipModel(
                this: v15,
                clip: &clientGame->clip,
                trm: &v52,
                numTraceModels: 1,
                material: nullptr);
      else
        v16 = nullptr;
      v17 = idEntity::GetPhysics(this);
      ((void (__fastcall *)(idPhysics *, idClipModel *, double))v17->SetClipModel)(a1: v17, a2: v16, a3: this->density);
      v18 = idEntity::GetPhysics(this);
      v18->SetContents(this: v18, a2: 139584, a3: -1);
      v19 = idEntity::GetPhysics(this);
      v19->SetClipMask(this: v19, a2: 1, a3: -1);
      v20 = idEntity::GetPhysics(this);
      this->DeactivatePhysics(this, a2: v20->physicsId);
    }
  }
  if ( this->state != UNBREAKABLE )
  {
    memset(&v50, 0, 12);
    v50.nextSoundTime = 0;
    breakableModel = this->breakableModel;
    v50.minBounceVelSqr = 0.0;
    v50.soundWorld = clientGame->soundWorld;
    SoundEmitter = idEntity::GetSoundEmitter(this, alloc: true);
    impactSoundTable = this->impactSoundTable;
    v25 = (float)(this->pieceMinBounceVelocity * this->pieceMinBounceVelocity);
    v50.emitter = SoundEmitter;
    v50.channel = SND_CHANNEL_FX;
    v50.minBounceVelSqr = v25;
    v50.impactTable = impactSoundTable;
    idEffectPhysicsBreakable::Init(
      this: &this->breakablePhysics,
      clip: &clientGame->clip,
      tmc: &clientGame->traceModelCache,
      _gameLibEffects: &clientGame->gameLibEffects,
      model_: breakableModel,
      entNum: this->entityNumber,
      _soundInfo: &v50);
  }
  breakableDebris = this->breakableDebris;
  this->healthMax = this->health;
  if ( breakableDebris != nullptr )
  {
    v27 = this->entityNumber;
    MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
    idEffectPhysicsDebrisEmitter::Init(
      this: &this->debrisEmitter,
      breakableDebris: this->breakableDebris,
      entityNumber: v27,
      clip: &clientGame->clip,
      renderModelEffects: MergeBranch);
  }
  this->SetAxis(this, a2: &this->spawnOrientation);
  this->SetOrigin(this, a2: &this->spawnPosition);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::SetClipModelInfo(
    this: presentable,
    clipModelInfo_: &this->clipModelInfo,
    clipModelSpawnPos_: &this->spawnPosition,
    clipModelSpawnAxis_: &this->spawnOrientation,
    a5: v32,
    a6: v31,
    a7: v30,
    a8: v29,
    a9: v44,
    a10: v45,
    a11: v46,
    a12: v47,
    a13: v48,
    a14: v49);
  v34 = idEntity::GetPhysics(this);
  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
  v35 = this->presentable;
  v36 = v34->GetContents(this: v34, a2: -1);
  idPresentable::SetClipModelContents(this: v35, newContents: v36, a3: v42, a4: v41, a5: v40, a6: v39, a7: v38, a8: v37);
  if ( this->clipModelInfo.type == CLIPMODEL_NONE )
  {
    v43 = this->presentable;
    if ( v43 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v43 = this->presentable;
    }
    v43->clipModelInfo.type = CLIPMODEL_BOX;
  }
}


// ========================================================================
// $LN88
// EA  : 0x82C1F3E4
// RVA : 0x00C1F3E4
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void _LN88()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1712 + 104), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?Damage@idDamageableEntity@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82C1F410
// RVA : 0x00C1F410
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

float __fastcall idDamageableEntity::Damage(
        idDamageableEntity *this,
        idWorldspawn *inflictor,
        idWorldspawn *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace,
        int a8)
{
  __int64 v15; // r9
  double v16; // fp1
  double v17; // fp1
  __int64 v18; // r10
  int v19; // r7
  int v20; // r6
  int v21; // r5
  int v22; // r3
  double v23; // fp8
  double v24; // fp7
  double v25; // fp6
  double v26; // fp5
  double v27; // fp4
  double v28; // fp3
  double v29; // fp2
  double v30; // fp1
  double v31; // fp0
  double v32; // fp0
  char v33; // r11
  int *v34; // r11
  double v35; // fp31
  idPhysics *Physics; // r23
  idPhysics *v37; // r3
  double v38; // fp9
  double v39; // fp6
  idPhysics *v40; // r22
  double v41; // fp4
  int GameMs; // r21
  const idMat3 *v43; // r23
  const idVec3 *v44; // r3
  idPresentable *presentable; // r3
  idPresentableDamageable *v46; // r3
  double v47; // fp9
  double v48; // fp6
  double v49; // fp4
  double v50; // fp9
  idPhysics *v51; // r30
  int v52; // r29
  idPhysics *v53; // r3
  idAIEventManager *p_aiEventManager; // r30
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v56; // r3
  idPhysics *v57; // r30
  idPhysics *v58; // r29
  int v59; // r27
  const idMat3 *v60; // r26
  const idVec3 *v61; // r3
  idPresentable *v62; // r11
  idPresentableDamageable *v63; // r3
  double v64; // fp10
  double v65; // fp7
  int v67; // [sp+8h] [-F8h]
  int v68; // [sp+Ch] [-F4h]
  int v69; // [sp+10h] [-F0h]
  int v70; // [sp+14h] [-ECh]
  int v71; // [sp+18h] [-E8h]
  int v72; // [sp+1Ch] [-E4h]
  int v73; // [sp+20h] [-E0h]
  int v74; // [sp+24h] [-DCh]
  int v75; // [sp+28h] [-D8h]
  int v76; // [sp+2Ch] [-D4h]
  int v77; // [sp+30h] [-D0h]
  int v78; // [sp+34h] [-CCh]
  int v79; // [sp+38h] [-C8h]
  int v80; // [sp+3Ch] [-C4h]
  int v81; // [sp+40h] [-C0h]
  int v82; // [sp+44h] [-BCh]
  int v83; // [sp+48h] [-B8h]
  int v84; // [sp+4Ch] [-B4h]
  float v85[2]; // [sp+50h] [-B0h] BYREF
  idAIEventManager v86; // [sp+58h] [-A8h] BYREF
  int v87; // [sp+A8h] [-58h]
  int v88; // [sp+ACh] [-54h]
  int v89; // [sp+B0h] [-50h]
  int v90; // [sp+B4h] [-4Ch]
  int v91; // [sp+B8h] [-48h]
  int v92; // [sp+BCh] [-44h]
  idClipModel *v93; // [sp+C0h] [-40h]

  if ( !this->TakesDamage(this) || damageDef == nullptr )
  {
    v16 = 0.0;
    return *((float *)&v16 + 1);
  }
  LODWORD(v15) = this->armorValue;
  *(_QWORD *)&v86.eventList.list = v15;
  if ( (float)v15 > 0.0 && damageDef->ignoreArmoredBreakables )
  {
    v16 = 0.0;
    return *((float *)&v16 + 1);
  }
  if ( inflictor == nullptr )
    inflictor = gameLocal->world;
  if ( attacker == nullptr )
    attacker = gameLocal->world;
  v17 = idDeclDamage::DamageAmount(this: damageDef);
  LODWORD(v18) = this->armorValue;
  *(_QWORD *)&v86.eventList.list = v18;
  v85[0] = (float)((float)v17 * (float)damageScale) - (float)v18;
  if ( v85[0] < 0.0 )
    v85[0] = 0.0;
  attacker->DamageFeedback(this: attacker, a2: this, a3: inflictor, a4: damageDef, a5: v85);
  v22 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v31 = v85[0];
  this->lastBump = v22;
  if ( v31 != 0.0 )
  {
    v32 = (float)(this->health - (float)v31);
    this->health = v32;
    if ( v32 <= 0.0 || (v33 = 0, v32 < (float)(this->resistPercent * this->healthMax)) )
      v33 = 1;
    if ( v33 != 0 )
    {
      if ( a8 != 0 )
        v34 = (int *)(a8 + 4);
      else
        v34 = (int *)&vec3_origin;
      if ( (unsigned __int8)idDamageableEntity::BreakBreakable(
                              this,
                              source: (const idVec3 *)&v86,
                              a3: v30,
                              a4: v29,
                              a5: v28,
                              a6: v27,
                              a7: v26,
                              a8: v25,
                              a9: v24,
                              a10: v23,
                              a11: v21,
                              a12: v20,
                              a13: v19,
                              a14: v34[2],
                              a15: v34[1],
                              a16: *v34,
                              a17: v67,
                              a18: v68,
                              a19: v69,
                              a20: v70,
                              a21: v71,
                              a22: v72,
                              a23: v73,
                              a24: v74,
                              a25: v75,
                              a26: v76,
                              a27: v77,
                              a28: v78,
                              a29: v79,
                              a30: v80,
                              a31: v81,
                              a32: v82,
                              a33: v83,
                              a34: v84,
                              a35: v85[0],
                              a36: v85[1],
                              a37: *(float *)v34,
                              a38: *((float *)v34 + 1),
                              a39: *((float *)v34 + 2),
                              a40: *(float *)&v86.eventList.granularity,
                              a41: (int)v86.eventHash.hash,
                              a42: (int)v86.eventHash.indexChain,
                              x: *(float *)&v86.eventHash.hashSize,
                              a44: *(float *)&v86.eventHash.indexSize,
                              a45: *(float *)&v86.eventHash.granularity,
                              a46: v86.eventHash.hashMask,
                              a47: v86.eventHash.lookupMask,
                              a48: v86.eventHash.memTag,
                              a49: (int)v86.receivers.list,
                              a50: v86.receivers.num,
                              a51: v86.receivers.size,
                              a52: *(int *)&v86.receivers.granularity,
                              a53: (int)v86.eventPools.list,
                              a54: v86.eventPools.num,
                              a55: v86.eventPools.size,
                              a56: *(int *)&v86.eventPools.granularity,
                              a57: v87,
                              a58: v88,
                              a59: v89,
                              a60: v90,
                              a61: v91,
                              a62: v92,
                              a63: v93) == 0 )
      {
LABEL_32:
        v16 = v85[0];
        return *((float *)&v16 + 1);
      }
      if ( this->state != UNBREAKABLE )
      {
        if ( a8 == 0 )
        {
          idDamageableEntity::CheckDamagedPieces(this);
          v16 = v85[0];
          return *((float *)&v16 + 1);
        }
        if ( attacker == inflictor && (unsigned __int8)idVehicle::IsTypeOf(c: inflictor) != 0 )
          goto LABEL_32;
        if ( idEntity::GetPhysics(this)->type == PHYSICS_STATICMULTI
          || idEntity::GetPhysics(this)->type == PHYSICS_RIGIDBODY )
        {
          v35 = (float)(v85[0] / (float)(this->density * (float)5000.0));
          if ( damageDef->isMelee )
            v35 = (float)((float)(v85[0] / (float)(this->density * (float)5000.0)) * (float)0.2);
          Physics = idEntity::GetPhysics(this);
          v37 = idEntity::GetPhysics(this);
          v38 = (float)(trace->endpos.y * (float)v35);
          v39 = *(float *)(a8 + 12);
          v40 = v37;
          v41 = (float)((float)(trace->endpos.x * (float)v35) + *(float *)(a8 + 8));
          *(float *)&v86.eventHash.hash = *(float *)(a8 + 4) + (float)(trace->fraction * (float)v35);
          *(float *)&v86.eventHash.indexChain = v41;
          *(float *)&v86.eventHash.hashSize = (float)v38 + (float)v39;
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v43 = Physics->GetAxis(this: Physics, a2: 0);
          v44 = v40->GetOrigin(this: v40, a2: 0);
          idEffectPhysicsBreakable::AddRayImpact(
            this: &this->breakablePhysics,
            time: GameMs,
            origin: v44,
            axis: v43,
            start: (const idVec3 *)(a8 + 4),
            end: (const idVec3 *)&v86.eventHash,
            ignoreActivePieces: false);
          presentable = this->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            presentable = this->presentable;
          }
          v46 = presentable->GetDamageableInterface(this: presentable);
          v47 = (float)(trace->endpos.y * (float)v35);
          v48 = *(float *)(a8 + 12);
          v49 = (float)((float)(trace->endpos.x * (float)v35) + *(float *)(a8 + 8));
          *(float *)&v86.eventHash.granularity = *(float *)(a8 + 4) + (float)(trace->fraction * (float)v35);
          *(float *)&v86.eventHash.hashMask = v49;
          *(float *)&v86.eventHash.lookupMask = (float)v47 + (float)v48;
          idPresentableDamageable::AddRayImpact(
            this: v46,
            start: (const idVec3 *)(a8 + 4),
            end: (const idVec3 *)&v86.eventHash.granularity);
          idDamageableEntity::CheckDamagedPieces(this);
          v50 = (float)(*(float *)(a8 + 24) * (float)(v85[0] + (float)10.0));
          *(float *)&v86.eventList.num = *(float *)(a8 + 20) * (float)(v85[0] + (float)10.0);
          *(float *)&v86.eventList.size = v50;
          *(float *)&v86.eventList.list = *(float *)(a8 + 16) * (float)(v85[0] + (float)10.0);
          idDamageableEntity::ThrowDebris(
            this,
            pos: (const idVec3 *)(a8 + 4),
            hitvel: (const idVec3 *)&v86,
            normal: (const idVec3 *)(a8 + 68),
            count: 1u);
          v51 = idEntity::GetPhysics(this);
          v52 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v53 = v51;
          GetOrigin = v51->GetOrigin;
          p_aiEventManager = &gameLocal->aiEventManager;
          v56 = GetOrigin(this: v53, a2: 0);
          idAIEventManager::AddEvent(
            this: &v86,
            result: p_aiEventManager,
            eventDecl: this->damagedAiEventDecl,
            curTime: v52,
            originator: this,
            instigator: attacker,
            origin: v56,
            delay: 400);
          goto LABEL_32;
        }
      }
    }
  }
  if ( a8 != 0 )
  {
    if ( this->state != UNBREAKABLE )
    {
      v57 = idEntity::GetPhysics(this);
      v58 = idEntity::GetPhysics(this);
      v59 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v60 = v57->GetAxis(this: v57, a2: 0);
      v61 = v58->GetOrigin(this: v58, a2: 0);
      idEffectPhysicsBreakable::AddRayImpact(
        this: &this->breakablePhysics,
        time: v59,
        origin: v61,
        axis: v60,
        start: (const idVec3 *)(a8 + 4),
        end: (const idVec3 *)(a8 + 4),
        ignoreActivePieces: false);
      v62 = this->presentable;
      if ( v62 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v62 = this->presentable;
      }
      v63 = v62->GetDamageableInterface(this: v62);
      idPresentableDamageable::AddRayImpact(this: v63, start: (const idVec3 *)(a8 + 4), end: (const idVec3 *)(a8 + 4));
    }
    v64 = *(float *)(a8 + 24);
    v65 = (float)(*(float *)(a8 + 20) * (float)(v85[0] + (float)10.0));
    *(float *)&v86.eventList.list = *(float *)(a8 + 16) * (float)(v85[0] + (float)10.0);
    *(float *)&v86.eventList.num = v65;
    *(float *)&v86.eventList.size = (float)v64 * (float)(v85[0] + (float)10.0);
    idDamageableEntity::ThrowDebris(
      this,
      pos: (const idVec3 *)(a8 + 4),
      hitvel: (const idVec3 *)&v86,
      normal: (const idVec3 *)(a8 + 68),
      count: 1u);
  }
  v16 = v85[0];
  return *((float *)&v16 + 1);
}


// ========================================================================
// `dynamic initializer for 'g_damageablePowerScale''
// EA  : 0x83375B58
// RVA : 0x01375B58
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_damageablePowerScale__()
{
  idCVar::idCVar(
    this: &g_damageablePowerScale,
    name: "g_damageablePowerScale",
    value: "8",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_damageablePowerScale__);
}


// ========================================================================
// `dynamic initializer for 'g_damageablePowerBase''
// EA  : 0x83375BB0
// RVA : 0x01375BB0
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_damageablePowerBase__()
{
  idCVar::idCVar(
    this: &g_damageablePowerBase,
    name: "g_damageablePowerBase",
    value: "600",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_damageablePowerBase__);
}


// ========================================================================
// `dynamic initializer for 'g_breakableExplosionImpulseScale''
// EA  : 0x83375C08
// RVA : 0x01375C08
// PDB : w:\tech5\tungsten\game\entities\damageableentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_breakableExplosionImpulseScale__()
{
  idCVar::idCVar(
    this: &g_breakableExplosionImpulseScale,
    name: "g_breakableExplosionImpulseScale",
    value: "-1",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_breakableExplosionImpulseScale__);
}

