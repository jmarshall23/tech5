
// ========================================================================
// ??1idPresentableProjectile@@UAA@XZ
// EA  : 0x82B8AE50
// RVA : 0x00B8AE50
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __fastcall idPresentableProjectile::~idPresentableProjectile(idPresentableProjectile *this)
{
  this->__vftable = (idPresentableProjectile_vtbl *)&idPresentableProjectile::`vftable';
  idPresentableAnimatedEntity::~idPresentableAnimatedEntity(this);
}


// ========================================================================
// ??1idPresentableProjectile_Rocket@@UAA@XZ
// EA  : 0x82B8AE68
// RVA : 0x00B8AE68
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __fastcall idPresentableProjectile_Rocket::~idPresentableProjectile_Rocket(idPresentableProjectile_Rocket *this)
{
  this->__vftable = (idPresentableProjectile_Rocket_vtbl *)&idPresentableProjectile_Rocket::`vftable';
  idPhysics_RigidBody::~idPhysics_RigidBody(this: &this->physicsObj);
  this->__vftable = (idPresentableProjectile_Rocket_vtbl *)&idPresentableProjectile::`vftable';
  idPresentableAnimatedEntity::~idPresentableAnimatedEntity(this);
}


// ========================================================================
// __unwind$488766_0
// EA  : 0x82B8AEC8
// RVA : 0x00B8AEC8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void _unwind_488766_0()
{
  int v0; // r12

  idPresentableProjectile::~idPresentableProjectile(this: *(idPresentableProjectile **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idPresentableProjectile_Grenade@@UAA@XZ
// EA  : 0x82B8AEF8
// RVA : 0x00B8AEF8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __fastcall idPresentableProjectile_Grenade::~idPresentableProjectile_Grenade(
        idPresentableProjectile_Grenade *this)
{
  this->__vftable = (idPresentableProjectile_Grenade_vtbl *)&idPresentableProjectile_Grenade::`vftable';
  idPhysics_RigidBody::~idPhysics_RigidBody(this: &this->physicsObj);
  this->__vftable = (idPresentableProjectile_Grenade_vtbl *)&idPresentableProjectile::`vftable';
  idPresentableAnimatedEntity::~idPresentableAnimatedEntity(this);
}


// ========================================================================
// __unwind$488798
// EA  : 0x82B8AF58
// RVA : 0x00B8AF58
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void _unwind_488798()
{
  int v0; // r12

  idPresentableProjectile::~idPresentableProjectile(this: *(idPresentableProjectile **)(v0 - 112 + 132));
}


// ========================================================================
// ?SetDefaults@idPresentableProjectile@@QAAXXZ
// EA  : 0x82B8B000
// RVA : 0x00B8B000
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __fastcall idPresentableProjectile::SetDefaults(idPresentableProjectile *this)
{
  this->projectileDecl = nullptr;
  this->launchTime = 0;
  this->state = ACTIVE;
  this->projectilePhysics = nullptr;
  this->playingWarningSound = false;
  this->launchOrigin = vec3_origin;
  this->launchAxis = mat3_identity;
  this->launched = false;
  this->hasQuad = false;
  this->smoothOrigin = vec3_origin;
  this->smoothAxis = mat3_identity;
}


// ========================================================================
// ?UpdateFX@idPresentableProjectile@@UAAXABVidVec3@@ABVidMat3@@AAVidFXManager@@MM@Z
// EA  : 0x82B8B100
// RVA : 0x00B8B100
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __fastcall idPresentableProjectile::UpdateFX(
        idPresentableProjectile *this,
        const idVec3 *origin,
        const idMat3 *axis,
        idFXManager *fxManager,
        double fovScale,
        double depthHack)
{
  int v7; // r28
  unsigned int GameMsPerFrame; // r29
  int GameMs; // r30
  double v10; // fp8
  double v11; // fp6
  idVec3 v12; // [sp+60h] [-60h] BYREF
  idMat3 v13[2]; // [sp+70h] [-50h] BYREF

  v7 = idAccolade::Count(this: &clientGame->gameTimeManager);
  GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idMat3::operator*(this: v13, result: &this->axis, a: &this->smoothAxis);
  v10 = (float)(this->smoothOrigin.y + this->origin.y);
  v11 = (float)(this->smoothOrigin.z + this->origin.z);
  v12.x = this->smoothOrigin.x + this->origin.x;
  v12.y = v10;
  v12.z = v11;
  idFXManager::Update(
    this: &this->fxManager,
    parentOrigin: &v12,
    parentAxis: v13,
    parentVel: &vec3_origin,
    time: GameMs,
    gameMsPerFrame: GameMsPerFrame,
    frameNum: v7,
    fovScale: 1.0,
    depthHack: 0.0);
}


// ========================================================================
// ?GetWorldTransform@idPresentableProjectile@@UAAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82B8B1D0
// RVA : 0x00B8B1D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __fastcall idPresentableProjectile::GetWorldTransform(
        idPresentableProjectile *this,
        idVec3 *outOrigin,
        idMat3 *outAxis)
{
  double v6; // fp8
  double v7; // fp6
  idVec3 v8; // [sp+50h] [-60h] BYREF
  idMat3 v9[2]; // [sp+60h] [-50h] BYREF

  idMat3::operator*(this: v9, result: &this->axis, a: &this->smoothAxis);
  v6 = (float)(this->smoothOrigin.y + this->origin.y);
  v7 = (float)(this->smoothOrigin.z + this->origin.z);
  v8.x = this->smoothOrigin.x + this->origin.x;
  v8.y = v6;
  v8.z = v7;
  idPresentable::GetWorldTransformInternal(this, inOrigin: &v8, inAxis: v9, outOrigin, outAxis);
}


// ========================================================================
// ?InternalClientLaunch@idPresentableProjectile@@UAAXPAVidPresentable@@ABVidVec3@@ABVidMat3@@ABVidProjectileTarget@@MH@Z
// EA  : 0x82B8B248
// RVA : 0x00B8B248
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __fastcall idPresentableProjectile::InternalClientLaunch(
        idPresentableProjectile *this,
        idPresentable *attacker,
        const idVec3 *start,
        const idMat3 *fireAxis,
        const idProjectileTarget *target,
        double initialSpeed,
        int startTime,
        int a8)
{
  BOOL v15; // r8

  v15 = common->IsServer(this: common);
  if ( v15 )
    ((void (__fastcall *)(idEntity *, idEntity *, const idVec3 *, const idMat3 *, const idProjectileTarget *, BOOL, int, double))this->entity->idPresentableAnimatedEntity::idPresentable::__vftable[1].SetColor_3)(
      a1: this->entity,
      a2: attacker->entity,
      a3: start,
      a4: fireAxis,
      a5: target,
      a6: v15,
      a7: a8,
      a8: initialSpeed);
}


// ========================================================================
// ?SetupClientProjectilePhysics@idPresentableProjectile@@QAAXAAVidPhysics@@ABVidClipModelInfo@@PBVidTraceModel@@MPAVidPhysicsCallbacks@@@Z
// EA  : 0x82B8B2D8
// RVA : 0x00B8B2D8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __fastcall idPresentableProjectile::SetupClientProjectilePhysics(
        idPresentableProjectile *this,
        idPhysics_RigidBody *physicsObj,
        const idClipModelInfo *clipModelInfo,
        const idTraceModel *trm,
        double overrideCollision,
        idPhysicsCallbacks *cb,
        idPhysicsCallbacks *a7)
{
  const char *v12; // r7
  const idDeclProjectile *projectileDecl; // r29
  idClipModel *MoveableClipModel; // r4
  idClipModel *v15; // r3
  __int64 v16; // r8
  __int64 v17; // r10
  __int64 v18; // r6
  unsigned int v19; // r3
  unsigned int v20; // r3
  unsigned int v21; // r3
  idPhysics *projectilePhysics; // r3
  idVec3 *p_gravity; // r4
  physicsType_t type; // r11
  idPhysics *v25; // r30
  int GameMs; // r3
  float v27[4]; // [sp+58h] [-58h] BYREF

  this->projectilePhysics = physicsObj;
  idPhysics::InitPhysics(this: physicsObj, clip_: &clientGame->clip, callbacks_: a7, entityNumber_: this->entityNumber);
  projectileDecl = this->projectileDecl;
  if ( trm != nullptr )
  {
    v15 = (idClipModel *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xD8u,
                           tag: TAG_CLIPMODEL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    if ( v15 != nullptr )
      MoveableClipModel = idClipModel::idClipModel(
                            this: v15,
                            clip: &clientGame->clip,
                            trm,
                            numTraceModels: 1,
                            material: nullptr);
    else
      MoveableClipModel = nullptr;
  }
  else
  {
    MoveableClipModel = idPresentable::CreateMoveableClipModel(
                          clipModelInfo,
                          renderModel: this->model,
                          renderModelScale: &vec3_unit,
                          barrelCollision: false,
                          overrideRadius: overrideCollision,
                          debugName: v12,
                          a7: "Presentable");
  }
  ((void (__fastcall *)(idPhysics *, idClipModel *, double))this->projectilePhysics->SetClipModel)(
    a1: this->projectilePhysics,
    a2: MoveableClipModel,
    a3: projectileDecl->notHitscanInfo.physicsProperties.density);
  this->projectilePhysics->SetContents(this: this->projectilePhysics, a2: 2048, a3: -1);
  this->projectilePhysics->SetClipMask(this: this->projectilePhysics, a2: 8462469, a3: -1);
  this->projectilePhysics->PutToRest(this: this->projectilePhysics);
  HIDWORD(v16) = 1013904223;
  HIDWORD(v17) = 1013904223;
  HIDWORD(v18) = clientGame->random.seed;
  v19 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v19;
  LODWORD(v18) = (v19 >> 10) & 0x7FFF;
  v27[0] = (float)((float)((float)v18
                         * (float)(projectileDecl->clientMaxAngularVelocity.x
                                 - projectileDecl->clientMinAngularVelocity.x))
                 * (float)0.000030518509)
         + projectileDecl->clientMinAngularVelocity.x;
  v20 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v20;
  LODWORD(v16) = (v20 >> 10) & 0x7FFF;
  v27[1] = (float)((float)((float)v16
                         * (float)(projectileDecl->clientMaxAngularVelocity.y
                                 - projectileDecl->clientMinAngularVelocity.y))
                 * (float)0.000030518509)
         + projectileDecl->clientMinAngularVelocity.y;
  v21 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v21;
  LODWORD(v17) = (v21 >> 10) & 0x7FFF;
  projectilePhysics = this->projectilePhysics;
  v27[2] = (float)((float)((float)v17
                         * (float)(projectileDecl->clientMaxAngularVelocity.z
                                 - projectileDecl->clientMinAngularVelocity.z))
                 * (float)0.000030518509)
         + projectileDecl->clientMinAngularVelocity.z;
  projectilePhysics->SetAngularVelocity(this: projectilePhysics, a2: (const idVec3 *)v27, a3: 0);
  if ( projectileDecl->notHitscanInfo.physicsProperties.noGravity )
    p_gravity = &vec3_origin;
  else
    p_gravity = &clientGame->gravity;
  this->projectilePhysics->SetGravity(this: this->projectilePhysics, a2: p_gravity);
  type = this->projectilePhysics->type;
  if ( type == PHYSICS_RIGIDBODY )
  {
    idPhysics_RigidBody::SetBouncyness(this: physicsObj, b: projectileDecl->notHitscanInfo.physicsProperties.bounciness);
    idPhysics_RigidBody::SetFriction(
      this: physicsObj,
      linear: projectileDecl->notHitscanInfo.physicsProperties.linearFriction,
      angular: projectileDecl->notHitscanInfo.physicsProperties.angularFriction,
      contact: projectileDecl->notHitscanInfo.physicsProperties.contactFriction);
    idPhysics_RigidBody::SetWaterFriction(
      this: physicsObj,
      linear: projectileDecl->notHitscanInfo.physicsProperties.linearFrictionWater,
      angular: projectileDecl->notHitscanInfo.physicsProperties.angularFrictionWater);
    physicsObj->fl.noPushMask = 111616;
  }
  else if ( type == PHYSICS_RIGIDBODY3DOF )
  {
    idPhysics_RigidBody3DOF::SetCoefficientOfRestitution(
      this: (idPhysics_RigidBody3DOF *)physicsObj,
      cor: projectileDecl->notHitscanInfo.physicsProperties.bounciness);
    idPhysics_RigidBody3DOF::SetFriction(
      this: (idPhysics_RigidBody3DOF *)physicsObj,
      linear: projectileDecl->notHitscanInfo.physicsProperties.linearFriction,
      angular: projectileDecl->notHitscanInfo.physicsProperties.angularFriction,
      contact: projectileDecl->notHitscanInfo.physicsProperties.contactFriction);
    idPhysics_RigidBody3DOF::SetWaterFriction(
      this: (idPhysics_RigidBody3DOF *)physicsObj,
      linear: projectileDecl->notHitscanInfo.physicsProperties.linearFrictionWater,
      angular: projectileDecl->notHitscanInfo.physicsProperties.angularFrictionWater);
  }
  if ( common->IsServer(this: common) )
  {
    idEntity::SetPhysics(this: this->entity, phys: this->projectilePhysics);
  }
  else
  {
    this->projectilePhysics->SetOrigin(this: this->projectilePhysics, a2: &this->origin, a3: -1);
    this->projectilePhysics->SetAxis(this: this->projectilePhysics, a2: &this->axis, a3: -1);
    this->projectilePhysics->Activate(this: this->projectilePhysics);
    v25 = this->projectilePhysics;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v25->UpdateTime(this: v25, a2: GameMs);
  }
}


// ========================================================================
// __unwind$489994_0
// EA  : 0x82B8B6B0
// RVA : 0x00B8B6B0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void _unwind_489994_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 176 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?IsDead@idPresentableProjectile@@UBA_NXZ
// EA  : 0x82B8B6E0
// RVA : 0x00B8B6E0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

BOOL __fastcall idPresentableProjectile::IsDead(idPresentableProjectile *this)
{
  return (_cntlzw(this->state - 5) & 0x20) != 0;
}


// ========================================================================
// ?IsActive@idPresentableProjectile@@QBA_NXZ
// EA  : 0x82B8B6F8
// RVA : 0x00B8B6F8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

BOOL __fastcall idPresentableProjectile::IsActive(idPresentableProjectile *this)
{
  return (_cntlzw(this->state - 1) & 0x20) != 0;
}


// ========================================================================
// ?DecayOriginAndAxisSmoothing@idPresentableProjectile@@QAAXXZ
// EA  : 0x82B8B710
// RVA : 0x00B8B710
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __fastcall idPresentableProjectile::DecayOriginAndAxisSmoothing(idPresentableProjectile *this)
{
  idVec3 *p_smoothOrigin; // r11
  double v3; // fp0
  double v4; // fp13
  double valueFloat; // fp13
  double y; // fp6
  double z; // fp5
  double v10; // fp1
  double v11; // fp8
  double v12; // fp10
  double v13; // fp9
  double v14; // fp31
  const idQuat *v15; // r29
  const idQuat *v16; // r3
  idMat3 v17; // [sp+50h] [-80h] BYREF
  idQuat v18; // [sp+80h] [-50h] BYREF

  p_smoothOrigin = &this->smoothOrigin;
  v3 = (float)((float)((float)(vec3_origin.x - this->smoothOrigin.x) * (float)(vec3_origin.x - this->smoothOrigin.x))
             + (float)((float)((float)(vec3_origin.z - this->smoothOrigin.z)
                             * (float)(vec3_origin.z - this->smoothOrigin.z))
                     + (float)((float)(vec3_origin.y - this->smoothOrigin.y)
                             * (float)(vec3_origin.y - this->smoothOrigin.y))));
  v4 = __fsqrts(v3);
  if ( v4 <= 0.0099999998 )
  {
    p_smoothOrigin->x = vec3_origin.x;
    this->smoothOrigin.y = vec3_origin.y;
    this->smoothOrigin.z = vec3_origin.z;
  }
  else
  {
    valueFloat = (float)(net_errorSmoothingDecay.valueFloat * (float)v4);
    if ( valueFloat > net_errorSmoothingMaxDecay.valueFloat )
      valueFloat = net_errorSmoothingMaxDecay.valueFloat;
    y = this->smoothOrigin.y;
    z = this->smoothOrigin.z;
    _FP4 = (float)((float)((float)((float)(vec3_origin.x - this->smoothOrigin.x)
                                 * (float)(vec3_origin.x - this->smoothOrigin.x))
                         + (float)((float)((float)(vec3_origin.z - this->smoothOrigin.z)
                                         * (float)(vec3_origin.z - this->smoothOrigin.z))
                                 + (float)((float)(vec3_origin.y - this->smoothOrigin.y)
                                         * (float)(vec3_origin.y - this->smoothOrigin.y))))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f2, f4, f0, f8 }
    v10 = __frsqrte(_FP2);
    v11 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10
                                                                                        * (float)((float)v3 * (float)0.5))
                                                                                * (float)v10)
                                                                        - (float)1.5)
                                                        * (float)v10)
                                                * (float)((float)v3 * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v10
                                                                                * (float)((float)v3 * (float)0.5))
                                                                        * (float)v10)
                                                                - (float)1.5)
                                                * (float)v10))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v10 * (float)((float)v3 * (float)0.5)) * (float)v10)
                                        - (float)1.5)
                        * (float)v10));
    v12 = (float)((float)((float)(vec3_origin.y - this->smoothOrigin.y)
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10 * (float)((float)v3 * (float)0.5)) * (float)v10) - (float)1.5) * (float)v10) * (float)((float)v3 * (float)0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v10 * (float)((float)v3 * (float)0.5)) * (float)v10) - (float)1.5) * (float)v10))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v10 * (float)((float)v3 * (float)0.5)) * (float)v10)
                                                                                                - (float)1.5)
                                                                                * (float)v10))
                                                                * (float)((float)v3 * (float)0.5))
                                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10 * (float)((float)v3 * (float)0.5)) * (float)v10) - (float)1.5) * (float)v10)
                                                                                                * (float)((float)v3 * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v10 * (float)((float)v3 * (float)0.5)) * (float)v10) - (float)1.5)
                                                                                                * (float)v10))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v10 * (float)((float)v3 * (float)0.5))
                                                                                                * (float)v10)
                                                                                        - (float)1.5)
                                                                        * (float)v10)))
                                                - (float)1.5)
                                * (float)v11))
                * (float)valueFloat);
    v13 = (float)((float)((float)(vec3_origin.z - this->smoothOrigin.z)
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10 * (float)((float)v3 * (float)0.5)) * (float)v10) - (float)1.5) * (float)v10) * (float)((float)v3 * (float)0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v10 * (float)((float)v3 * (float)0.5)) * (float)v10) - (float)1.5) * (float)v10))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v10 * (float)((float)v3 * (float)0.5)) * (float)v10)
                                                                                                - (float)1.5)
                                                                                * (float)v10))
                                                                * (float)((float)v3 * (float)0.5))
                                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10 * (float)((float)v3 * (float)0.5)) * (float)v10) - (float)1.5) * (float)v10)
                                                                                                * (float)((float)v3 * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v10 * (float)((float)v3 * (float)0.5)) * (float)v10) - (float)1.5)
                                                                                                * (float)v10))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v10 * (float)((float)v3 * (float)0.5))
                                                                                                * (float)v10)
                                                                                        - (float)1.5)
                                                                        * (float)v10)))
                                                - (float)1.5)
                                * (float)v11))
                * (float)valueFloat);
    p_smoothOrigin->x = (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10 * (float)((float)v3 * (float)0.5)) * (float)v10) - (float)1.5) * (float)v10) * (float)((float)v3 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v10 * (float)((float)v3 * (float)0.5)) * (float)v10) - (float)1.5) * (float)v10)) - (float)1.5)
                                                                                      * (float)((float)-(float)((float)((float)((float)v10 * (float)((float)v3 * (float)0.5)) * (float)v10) - (float)1.5)
                                                                                              * (float)v10))
                                                                              * (float)((float)v3 * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10 * (float)((float)v3 * (float)0.5)) * (float)v10) - (float)1.5) * (float)v10) * (float)((float)v3 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v10 * (float)((float)v3 * (float)0.5)) * (float)v10) - (float)1.5) * (float)v10))
                                                                                              - (float)1.5)
                                                                              * (float)((float)-(float)((float)((float)((float)v10 * (float)((float)v3 * (float)0.5)) * (float)v10) - (float)1.5)
                                                                                      * (float)v10)))
                                                              - (float)1.5)
                                              * (float)v11)
                                      * (float)(vec3_origin.x - this->smoothOrigin.x))
                              * (float)valueFloat)
                      + p_smoothOrigin->x;
    this->smoothOrigin.y = (float)y + (float)v12;
    this->smoothOrigin.z = (float)z + (float)v13;
  }
  v14 = net_errorSmoothingDecay.valueFloat;
  v15 = idMat3::ToQuat(this: (idMat3 *)&v17.mat[1].y, result: (idQuat *)&mat3_identity);
  v16 = idMat3::ToQuat(this: (idMat3 *)&v17.mat[2].z, result: (idQuat *)&this->smoothAxis);
  idQuat::Slerp(this: (idQuat *)&v17, from: v16, to: v15, t: v14);
  this->smoothAxis = *idQuat::ToMat3(this: &v18, result: &v17);
}


// ========================================================================
// ?SmoothFromOriginAndAxis@idPresentableProjectile@@QAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82B8B8E0
// RVA : 0x00B8B8E0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __fastcall idPresentableProjectile::SmoothFromOriginAndAxis(
        idPresentableProjectile *this,
        const idVec3 *oldOrigin,
        idMat3 *oldAxis)
{
  double v4; // fp8
  double v5; // fp6
  idMat3 *v6; // r3
  idMat3 v7; // [sp+50h] [-70h] BYREF
  idMat3 v8; // [sp+80h] [-40h] BYREF

  v4 = (float)(oldOrigin->y - this->origin.y);
  v5 = (float)(oldOrigin->z - this->origin.z);
  this->smoothOrigin.x = oldOrigin->x - this->origin.x;
  this->smoothOrigin.y = v4;
  this->smoothOrigin.z = v5;
  v6 = idMat3::Inverse(this: &v7, result: oldAxis);
  this->smoothAxis = *idMat3::operator*(this: &v8, result: v6, a: &this->axis);
}


// ========================================================================
// ?GetInitialDir@idProjectile_Rocket@@UAA?AVidVec3@@ABVidMat3@@@Z
// EA  : 0x82B8BA08
// RVA : 0x00B8BA08
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

idPresentableProjectile_Rocket *__fastcall idProjectile_Rocket::GetInitialDir(
        idPresentableProjectile_Rocket *this,
        idVec3 *result,
        const idMat3 *fireAxis)
{
  float y; // r10
  float z; // r9

  y = fireAxis->mat[0].y;
  z = fireAxis->mat[0].z;
  this->__vftable = (idPresentableProjectile_Rocket_vtbl *)LODWORD(fireAxis->mat[0].x);
  *((float *)&this->__vftable + 1) = y;
  *(float *)&this->groupMaster.idPresentableProjectile::idPresentableAnimatedEntity::idPresentable::spawnId = z;
  return this;
}


// ========================================================================
// ?GetInitialDir@idPresentableProjectile_Homing@@UAA?AVidVec3@@ABVidMat3@@@Z
// EA  : 0x82B8BA90
// RVA : 0x00B8BA90
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

idPresentableProjectile_Homing *__fastcall idPresentableProjectile_Homing::GetInitialDir(
        idPresentableProjectile_Homing *this,
        idVec3 *result,
        const idMat3 *fireAxis)
{
  float z; // r10
  float y; // r8
  double v5; // fp11
  double v6; // fp10
  double v7; // fp9
  double v10; // fp2
  double v11; // fp5
  double v12; // fp2

  if ( *(_DWORD *)(LODWORD(result[104].x) + 432) != *(_DWORD *)(LODWORD(result[104].x) + 428) )
    clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
  z = fireAxis->mat[0].z;
  y = fireAxis->mat[0].y;
  this->__vftable = (idPresentableProjectile_Homing_vtbl *)LODWORD(fireAxis->mat[0].x);
  v5 = *(float *)&this->__vftable;
  *(float *)&this->groupMaster.idPresentableProjectile_Rocket::idPresentableProjectile::idPresentableAnimatedEntity::idPresentable::spawnId = z;
  v6 = *(float *)&this->groupMaster.idPresentableProjectile_Rocket::idPresentableProjectile::idPresentableAnimatedEntity::idPresentable::spawnId;
  *((float *)&this->__vftable + 1) = y;
  v7 = *((float *)&this->__vftable + 1);
  _FP5 = (float)((float)((float)((float)v6 * (float)v6)
                       + (float)((float)((float)v5 * (float)v5)
                               + (float)(*((float *)&this->__vftable + 1) * *((float *)&this->__vftable + 1))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f13 }
  v10 = __frsqrte(_FP3);
  v11 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10
                                                                                      * (float)((float)((float)((float)v6 * (float)v6) + (float)((float)((float)v5 * (float)v5) + (float)(*((float *)&this->__vftable + 1) * *((float *)&this->__vftable + 1))))
                                                                                              * (float)0.5))
                                                                              * (float)v10)
                                                                      - (float)1.5)
                                                      * (float)v10)
                                              * (float)((float)((float)((float)v6 * (float)v6)
                                                              + (float)((float)((float)v5 * (float)v5)
                                                                      + (float)(*((float *)&this->__vftable + 1)
                                                                              * *((float *)&this->__vftable + 1))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v10
                                                                              * (float)((float)((float)((float)v6 * (float)v6)
                                                                                              + (float)((float)((float)v5 * (float)v5) + (float)(*((float *)&this->__vftable + 1) * *((float *)&this->__vftable + 1))))
                                                                                      * (float)0.5))
                                                                      * (float)v10)
                                                              - (float)1.5)
                                              * (float)v10))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v10
                                                      * (float)((float)((float)((float)v6 * (float)v6)
                                                                      + (float)((float)((float)v5 * (float)v5)
                                                                              + (float)(*((float *)&this->__vftable + 1)
                                                                                      * *((float *)&this->__vftable + 1))))
                                                              * (float)0.5))
                                              * (float)v10)
                                      - (float)1.5)
                      * (float)v10));
  v12 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10 * (float)((float)((float)((float)v6 * (float)v6) + (float)((float)((float)v5 * (float)v5) + (float)(*((float *)&this->__vftable + 1) * *((float *)&this->__vftable + 1)))) * (float)0.5)) * (float)v10) - (float)1.5)
                                                                                              * (float)v10)
                                                                                      * (float)((float)((float)((float)v6 * (float)v6) + (float)((float)((float)v5 * (float)v5) + (float)(*((float *)&this->__vftable + 1) * *((float *)&this->__vftable + 1))))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v10 * (float)((float)((float)((float)v6 * (float)v6) + (float)((float)((float)v5 * (float)v5) + (float)(*((float *)&this->__vftable + 1) * *((float *)&this->__vftable + 1)))) * (float)0.5)) * (float)v10) - (float)1.5)
                                                                                      * (float)v10))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v10
                                                                                              * (float)((float)((float)((float)v6 * (float)v6) + (float)((float)((float)v5 * (float)v5) + (float)(*((float *)&this->__vftable + 1) * *((float *)&this->__vftable + 1)))) * (float)0.5))
                                                                                      * (float)v10)
                                                                              - (float)1.5)
                                                              * (float)v10))
                                              * (float)((float)((float)((float)v6 * (float)v6)
                                                              + (float)((float)((float)v5 * (float)v5)
                                                                      + (float)(*((float *)&this->__vftable + 1)
                                                                              * *((float *)&this->__vftable + 1))))
                                                      * (float)0.5))
                                      * (float)v11)
                              - (float)1.5)
              * (float)v11);
  *(float *)&this->__vftable = (float)v5 * (float)v12;
  *((float *)&this->__vftable + 1) = (float)v7 * (float)v12;
  *(float *)&this->groupMaster.idPresentableProjectile_Rocket::idPresentableProjectile::idPresentableAnimatedEntity::idPresentable::spawnId = (float)v6 * (float)v12;
  return this;
}


// ========================================================================
// ?GetSpeedForFireAxis@idPresentableProjectile_Grenade@@QBAMPBVidPresentable@@ABVidMat3@@@Z
// EA  : 0x82B8BBC8
// RVA : 0x00B8BBC8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

float __fastcall idPresentableProjectile_Grenade::GetSpeedForFireAxis(
        idPresentableProjectile_Grenade *this,
        const idPresentable *attacker,
        const idMat3 *fireAxis)
{
  float y; // r8
  float z; // r7
  double v7; // fp29
  double v8; // fp28
  double v9; // fp27
  idEntity *entity; // r3
  idPhysics *Physics; // r3
  float *v12; // r3
  long double v13; // fp2
  double v14; // fp0
  double v15; // fp1
  double v16; // fp13
  const idDeclProjectile *projectileDecl; // r11
  double v18; // fp12
  double v19; // fp1
  idVec3 v21; // [sp+50h] [-60h] BYREF
  idVec3 v22; // [sp+60h] [-50h] BYREF

  y = fireAxis->mat[0].y;
  z = fireAxis->mat[0].z;
  v22.x = fireAxis->mat[0].x;
  v7 = 0.0;
  v21.x = 0.0;
  v8 = 0.0;
  v21.y = 0.0;
  v9 = 1.0;
  v21.z = 1.0;
  v22.y = y;
  v22.z = z;
  if ( attacker != nullptr )
  {
    entity = attacker->entity;
    if ( entity != nullptr )
    {
      Physics = idEntity::GetPhysics(this: entity);
      v12 = (float *)Physics->GetGravityNormal(this: Physics);
      v7 = *v12;
      v8 = v12[1];
      v9 = v12[2];
      v21.x = *v12;
      v21.y = v8;
      v21.z = v9;
    }
  }
  idVec3::ProjectOntoPlane(this: &v22, normal: &v21, overBounce: 1.0);
  *(double *)&v13 = (float)((float)(fireAxis->mat[0].x * v22.x)
                          + (float)((float)(fireAxis->mat[0].z * v22.z) + (float)(fireAxis->mat[0].y * v22.y)));
  if ( (float)((float)(fireAxis->mat[0].y * (float)v8)
             + (float)((float)(fireAxis->mat[0].z * (float)v9) + (float)(fireAxis->mat[0].x * (float)v7))) <= 0.0 )
  {
    v15 = idMath::ACos(a: v13);
    v14 = 90.0;
    v16 = (float)((float)((float)v15 * idMath::M_RAD2DEG) + (float)90.0);
    if ( v16 >= 90.0 )
    {
      v14 = 135.0;
      if ( v16 <= 135.0 )
        v14 = (float)((float)((float)v15 * idMath::M_RAD2DEG) + (float)90.0);
    }
  }
  else
  {
    *(double *)&v13 = (float)((float)1.0
                            - (float)((float)(fireAxis->mat[0].x * v22.x)
                                    + (float)((float)(fireAxis->mat[0].z * v22.z) + (float)(fireAxis->mat[0].y * v22.y))));
    v14 = (float)(idMath::ACos(a: v13) * idMath::M_RAD2DEG);
  }
  projectileDecl = this->projectileDecl;
  if ( v14 >= 75.0 )
  {
    v18 = (float)((float)(projectileDecl->notHitscanInfo.grenadeInfo.maxSpeed
                        - projectileDecl->notHitscanInfo.grenadeInfo.minSpeed)
                * (float)0.33000001);
    v19 = (float)((float)((float)((float)((float)((float)v14 - (float)75.0) * (float)0.016666668)
                                * (float)((float)(projectileDecl->notHitscanInfo.grenadeInfo.maxSpeed
                                                - projectileDecl->notHitscanInfo.grenadeInfo.minSpeed)
                                        - (float)v18))
                        + (float)v18)
                + projectileDecl->notHitscanInfo.grenadeInfo.minSpeed);
  }
  else
  {
    v19 = (float)((float)((float)((float)v14 * (float)0.013333334)
                        * (float)((float)(projectileDecl->notHitscanInfo.grenadeInfo.maxSpeed
                                        - projectileDecl->notHitscanInfo.grenadeInfo.minSpeed)
                                * (float)0.33000001))
                + projectileDecl->notHitscanInfo.grenadeInfo.minSpeed);
  }
  return *((float *)&v19 + 1);
}


// ========================================================================
// ?SmoothFromLaunchOriginAxis@idPresentableProjectile@@QAAXXZ
// EA  : 0x82B8BD80
// RVA : 0x00B8BD80
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __fastcall idPresentableProjectile::SmoothFromLaunchOriginAxis(idPresentableProjectile *this)
{
  idPresentableProjectile::SmoothFromOriginAndAxis(this, oldOrigin: &this->launchOrigin, oldAxis: &this->launchAxis);
}


// ========================================================================
// ?ClientThink@idPresentableProjectile@@UAAXHM_N@Z
// EA  : 0x82B8BD90
// RVA : 0x00B8BD90
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __fastcall idPresentableProjectile::ClientThink(
        idPresentableProjectile *this,
        int curTime,
        double fraction,
        bool predict)
{
  int v5; // r5
  idFXManager *v6; // r4
  idClientGame *v7; // r11

  idPresentableAnimatedEntity::ClientThink(this, curTime, fraction, predict);
  idPresentableProjectile::DecayOriginAndAxisSmoothing(this);
  if ( this->index >= 0x2000 )
  {
    if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - this->launchTime > 1000 * cg_predictProjectileExpire.valueInteger )
    {
      idLib::Printf(fmt: "Predicted projectile expired before server version spawned\n");
      this->queueForDelete = true;
    }
    idPresentable::UpdateFX(this, fovScale: 1.0, depthHack: 0.0, fxManager: v6, a5: v5, a6: &this->fxManager);
  }
  if ( g_projectileDebug.valueInteger != 0 )
  {
    if ( this->hidden )
    {
      v7 = clientGame;
    }
    else
    {
      v7 = clientGame;
      if ( this->index >= 0x2000 )
      {
        ((void (__fastcall *)(double))clientGame->renderWorld->DebugCircle)(a1: 5.0);
        return;
      }
    }
    ((void (__fastcall *)(double))v7->renderWorld->DebugCircle)(a1: 5.0);
  }
}


// ========================================================================
// ?AdjustStartToCollision@idPresentableProjectile@@QAA_NPAVidPresentable@@AAVidVec3@@V3@@Z
// EA  : 0x82B8BF18
// RVA : 0x00B8BF18
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

int __fastcall idPresentableProjectile::AdjustStartToCollision(
        idPresentableProjectile *this,
        idPresentable *attacker,
        __int64 direction)
{
  idVec3 *v4; // r31
  idPresentableActor *v5; // r3
  const int *v6; // r30
  int v7; // r3
  float v8; // r8
  float v9; // r7
  float v10; // r6
  double x; // fp13
  double y; // fp0
  double v13; // fp3
  double v14; // fp31
  double v15; // fp30
  double v16; // fp29
  int v17; // r8
  double v19; // fp7
  double v20; // fp6
  double v21; // fp5
  double z; // fp3
  __int64 v23; // r9
  double v24; // fp10
  double v25; // fp8
  double v26; // fp13
  double v27; // fp12
  double v28; // fp11
  double v29; // fp10
  double v32; // fp4
  double v33; // fp5
  double v34; // fp31
  double v35; // fp9
  int v36; // r8
  double v37; // fp7
  double v38; // fp13
  double v39; // fp12
  idVec3 v40; // [sp+50h] [-1B0h] BYREF
  idVec3 v41; // [sp+60h] [-1A0h] BYREF
  idVec3 v42; // [sp+70h] [-190h] BYREF
  float v43[4]; // [sp+80h] [-180h] BYREF
  idVec3 v44; // [sp+90h] [-170h] BYREF
  float v45[4]; // [sp+A0h] [-160h] BYREF
  idVec3 v46; // [sp+B0h] [-150h] BYREF
  idVec3 v47; // [sp+C0h] [-140h] BYREF
  float v48[4]; // [sp+D0h] [-130h] BYREF
  float v49[4]; // [sp+E0h] [-120h] BYREF
  float v50[4]; // [sp+F0h] [-110h] BYREF
  float v51[4]; // [sp+100h] [-100h] BYREF
  float v52[4]; // [sp+110h] [-F0h] BYREF
  trace_t v53; // [sp+120h] [-E0h] BYREF
  float v55; // [sp+238h] [+38h]

  v4 = (idVec3 *)HIDWORD(direction);
  v55 = *((float *)&direction + 1);
  if ( attacker == nullptr )
    return 0;
  v5 = attacker->GetActorInterface_2(this: attacker);
  v6 = (const int *)v5;
  if ( v5 == nullptr )
    return 0;
  if ( g_tempProjectileTest.valueInteger != 0 )
  {
    idPresentableAnimatedEntity::GetEyePos(this: v5, eyePos: &v40);
    if ( g_debugWeapon.valueInteger != 0 )
      ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, idVec3 *, double))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorBlue,
        a3: &v40,
        a4: v4,
        a5: 2.5);
    if ( !idClip::TracePoint(
            this: &clientGame->clip,
            result: &v53,
            start: &v40,
            end: v4,
            clipMask: 8462469,
            passEntityNumber: v6[45]) )
      return 0;
    if ( g_debugWeapon.valueInteger != 0 )
    {
      v48[0] = v53.endpos.x;
      v48[1] = v53.endpos.y;
      v48[2] = v53.endpos.z;
      v48[3] = 1.0;
      clientGame->renderWorld->DebugSphere(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: (const idSphere *)v48,
        a4: 12,
        a5: 2500,
        a6: true);
      idLib::Warning(
        fmt: "had to move start position of projectile due to collision conflicts: %s",
        this->model->name.str);
    }
    v7 = (*(int (__fastcall **)(const int *))(*v6 + 104))(a1: v6);
    if ( v7 != 0 )
    {
      v8 = *(float *)(v7 + 46548);
      v9 = *(float *)(v7 + 46544);
      v42.z = 0.0;
      v10 = *(float *)(v7 + 46552);
      v41.y = v8;
      v41.x = v9;
      v42.y = v9 * (float)-1.0;
      v41.z = v10;
      v42.x = v8;
      idVec3::NormalizeFast(this: &v42);
      x = v40.x;
      y = v40.y;
      v13 = (float)((float)((float)(v42.z * (float)0.0)
                          + (float)((float)(v42.y * (float)(v4->y - v40.y)) + (float)((float)(v4->x - v40.x) * v42.x)))
                  * (float)-1.0);
      v14 = (float)(v42.x
                  * (float)((float)((float)(v42.z * (float)0.0)
                                  + (float)((float)(v42.y * (float)(v4->y - v40.y))
                                          + (float)((float)(v4->x - v40.x) * v42.x)))
                          * (float)-1.0));
      v15 = (float)(v42.y
                  * (float)((float)((float)(v42.z * (float)0.0)
                                  + (float)((float)(v42.y * (float)(v4->y - v40.y))
                                          + (float)((float)(v4->x - v40.x) * v42.x)))
                          * (float)-1.0));
      v16 = (float)(v42.z
                  * (float)((float)((float)(v42.z * (float)0.0)
                                  + (float)((float)(v42.y * (float)(v4->y - v40.y))
                                          + (float)((float)(v4->x - v40.x) * v42.x)))
                          * (float)-1.0));
      if ( g_debugWeapon.valueInteger != 0 )
      {
        v45[0] = (float)(v42.x
                       * (float)((float)((float)(v42.z * (float)0.0)
                                       + (float)((float)(v42.y * (float)(v4->y - v40.y))
                                               + (float)((float)(v4->x - v40.x) * v42.x)))
                               * (float)-1.0))
               + v40.x;
        v45[1] = (float)(v42.y * (float)v13) + v40.y;
        v45[2] = (float)(v42.z * (float)v13) + v40.z;
        ((void (__fastcall *)(idRenderWorld *, idColor *, float *, idVec3 *, double))clientGame->renderWorld->DebugArrow)(
          a1: clientGame->renderWorld,
          a2: &idColor::colorCyan,
          a3: v45,
          a4: v4,
          a5: 2.5);
        y = v40.y;
        x = v40.x;
      }
      v17 = v6[45];
      v46.x = (float)v14 + (float)x;
      v46.y = (float)v15 + (float)y;
      v46.z = (float)v16 + v40.z;
      if ( !idClip::TracePoint(
              this: &clientGame->clip,
              result: &v53,
              start: &v46,
              end: v4,
              clipMask: 8462469,
              passEntityNumber: v17) )
      {
        if ( g_debugWeapon.valueInteger != 0 )
          idLib::Warning(fmt: "nevermind, decided that it is valid after all");
        return 0;
      }
    }
    v19 = (float)(v40.y - v4->y);
    v20 = (float)(v40.z - v4->z);
    v41.x = v40.x - v4->x;
    v41.y = v19;
    v41.z = v20;
    idVec3::NormalizeFast(this: &v41);
    v21 = v53.endpos.x;
    z = v53.endpos.z;
    LODWORD(v23) = g_projectileAdjustStart.valueInteger;
    *(_QWORD *)&v42.x = v23;
    v24 = (float)(v41.x * (float)v23);
    v25 = (float)(v41.z * (float)v23);
    v26 = (float)((float)(v41.y * (float)v23) + v53.endpos.y);
    v4->y = (float)(v41.y * (float)v23) + v53.endpos.y;
    v4->x = (float)v24 + (float)v21;
    v4->z = (float)v25 + (float)z;
    if ( g_debugWeapon.valueInteger != 0 )
    {
      v50[1] = v26;
      v50[3] = 1.0;
      v50[2] = (float)v25 + (float)z;
      v50[0] = (float)v24 + (float)v21;
      clientGame->renderWorld->DebugSphere(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorYellow,
        a3: (const idSphere *)v50,
        a4: 12,
        a5: 2500,
        a6: true);
    }
    return 1;
  }
  else
  {
    idPresentableAnimatedEntity::GetEyePos(this: v5, eyePos: &v44);
    v27 = v4->y;
    v28 = v4->z;
    v29 = v4->x;
    _FP7 = (float)((float)((float)((float)(v4->x - v44.x) * (float)(v4->x - v44.x))
                         + (float)((float)((float)(v4->z - v44.z) * (float)(v4->z - v44.z))
                                 + (float)((float)(v4->y - v44.y) * (float)(v4->y - v44.y))))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f5, f7, f8, f13 }
    v32 = __frsqrte(_FP5);
    v33 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v32
                                                                                        * (float)((float)((float)((float)(v4->x - v44.x) * (float)(v4->x - v44.x)) + (float)((float)((float)(v4->z - v44.z) * (float)(v4->z - v44.z)) + (float)((float)(v4->y - v44.y) * (float)(v4->y - v44.y))))
                                                                                                * (float)0.5))
                                                                                * (float)v32)
                                                                        - (float)1.5)
                                                        * (float)v32)
                                                * (float)((float)((float)((float)(v4->x - v44.x) * (float)(v4->x - v44.x))
                                                                + (float)((float)((float)(v4->z - v44.z)
                                                                                * (float)(v4->z - v44.z))
                                                                        + (float)((float)(v4->y - v44.y)
                                                                                * (float)(v4->y - v44.y))))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v32
                                                                                * (float)((float)((float)((float)(v4->x - v44.x) * (float)(v4->x - v44.x))
                                                                                                + (float)((float)((float)(v4->z - v44.z) * (float)(v4->z - v44.z)) + (float)((float)(v4->y - v44.y) * (float)(v4->y - v44.y))))
                                                                                        * (float)0.5))
                                                                        * (float)v32)
                                                                - (float)1.5)
                                                * (float)v32))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v32
                                                        * (float)((float)((float)((float)(v4->x - v44.x)
                                                                                * (float)(v4->x - v44.x))
                                                                        + (float)((float)((float)(v4->z - v44.z)
                                                                                        * (float)(v4->z - v44.z))
                                                                                + (float)((float)(v4->y - v44.y)
                                                                                        * (float)(v4->y - v44.y))))
                                                                * (float)0.5))
                                                * (float)v32)
                                        - (float)1.5)
                        * (float)v32));
    v34 = (float)((float)((float)-(float)((float)((float)((float)v33
                                                        * (float)((float)((float)((float)(v4->x - v44.x)
                                                                                * (float)(v4->x - v44.x))
                                                                        + (float)((float)((float)(v4->z - v44.z)
                                                                                        * (float)(v4->z - v44.z))
                                                                                + (float)((float)(v4->y - v44.y)
                                                                                        * (float)(v4->y - v44.y))))
                                                                * (float)0.5))
                                                * (float)v33)
                                        - (float)1.5)
                        * (float)v33)
                * (float)((float)((float)(v4->x - v44.x) * (float)(v4->x - v44.x))
                        + (float)((float)((float)(v4->z - v44.z) * (float)(v4->z - v44.z))
                                + (float)((float)(v4->y - v44.y) * (float)(v4->y - v44.y)))));
    if ( g_debugWeapon.valueInteger != 0 )
    {
      v52[0] = 0.0;
      v52[1] = 0.0;
      v52[3] = 1.0;
      v52[2] = 1.0;
      v43[1] = (float)v27 - (float)(*((float *)&direction + 1) * (float)v34);
      v43[0] = (float)v29 - (float)(*(float *)&direction * (float)v34);
      v43[2] = (float)v28 - (float)(v55 * (float)v34);
      ((void (__fastcall *)(idRenderWorld *, float *, float *, idVec3 *, double))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: v52,
        a3: v43,
        a4: v4,
        a5: 2.5);
    }
    v35 = v4->z;
    v36 = v6[45];
    v37 = (float)(v4->y - (float)(*((float *)&direction + 1) * (float)v34));
    v47.x = v4->x - (float)(*(float *)&direction * (float)v34);
    v47.y = v37;
    v47.z = (float)v35 - (float)(v55 * (float)v34);
    if ( !idClip::TracePoint(
            this: &clientGame->clip,
            result: &v53,
            start: &v47,
            end: v4,
            clipMask: 8462469,
            passEntityNumber: v36) )
      return 0;
    if ( g_debugWeapon.valueInteger != 0 )
    {
      v49[0] = v53.endpos.x;
      v51[0] = 1.0;
      v51[1] = 0.0;
      v49[3] = 5.0;
      v51[2] = 0.0;
      v51[3] = 1.0;
      v49[1] = v53.endpos.y;
      v49[2] = v53.endpos.z;
      clientGame->renderWorld->DebugSphere(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)v51,
        a3: (const idSphere *)v49,
        a4: 12,
        a5: 2500,
        a6: true);
      idLib::Warning(
        fmt: "had to move start position of projectile due to collision conflicts: %s",
        this->model->name.str);
    }
    v38 = v53.endpos.y;
    v39 = v53.endpos.z;
    v4->x = v53.endpos.x;
    v4->y = v38;
    v4->z = v39;
    return 1;
  }
}


// ========================================================================
// ?InternalClientLaunch@idPresentableProjectile_Rocket@@UAAXPAVidPresentable@@ABVidVec3@@ABVidMat3@@ABVidProjectileTarget@@MH@Z
// EA  : 0x82B8C528
// RVA : 0x00B8C528
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __fastcall idPresentableProjectile_Rocket::InternalClientLaunch(
        idPresentableProjectile_Rocket *this,
        idPresentable *attacker,
        const idVec3 *start,
        idMat3 *fireAxis,
        int _target,
        double initialSpeed,
        int startTime)
{
  const idDeclProjectile *projectileDecl; // r11
  float *v9; // r30
  signed int thrustDelayVariance; // r11
  unsigned int seed; // r8
  unsigned int v13; // r4
  int v14; // r3
  double v17; // fp2
  double v18; // fp5
  double v19; // fp2
  double v20; // fp12
  double v21; // fp13
  double v22; // fp11
  double speed; // fp0
  const idDeclProjectile *v24; // r11
  idPhysics *projectilePhysics; // r3
  const idSoundShader *breakAwaySnd; // r5
  float v27; // [sp+50h] [-30h] BYREF
  float v28; // [sp+54h] [-2Ch]
  float v29; // [sp+58h] [-28h]

  projectileDecl = this->projectileDecl;
  v9 = (float *)fireAxis;
  this->calcThrustDelay = projectileDecl->notHitscanInfo.thrustDelay;
  thrustDelayVariance = projectileDecl->notHitscanInfo.thrustDelayVariance;
  if ( thrustDelayVariance > 0 )
  {
    seed = clientGame->random.seed;
    __twllei(thrustDelayVariance, 0);
    v13 = 1664525 * seed + 1013904223;
    clientGame->random.seed = v13;
    v14 = (v13 >> 10) & 0x7FFF;
    startTime = __ROL4__(v14, 1) - 1;
    _target = v14 / thrustDelayVariance * thrustDelayVariance;
    fireAxis = (idMat3 *)(thrustDelayVariance & ~startTime);
    __twlgei((unsigned int)fireAxis, 0xFFFFFFFF);
    this->calcThrustDelay += v14 % thrustDelayVariance;
  }
  ((void (__fastcall *)(float *, idPresentableProjectile_Rocket *, float *, idMat3 *, int, int))this->GetInitialDir)(
    a1: &v27,
    a2: this,
    a3: v9,
    a4: fireAxis,
    a5: _target,
    a6: startTime);
  _FP5 = (float)((float)((float)(v27 * v27) + (float)((float)(v29 * v29) + (float)(v28 * v28)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f12 }
  v17 = __frsqrte(_FP3);
  v18 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                      * (float)((float)((float)(v27 * v27) + (float)((float)(v29 * v29) + (float)(v28 * v28)))
                                                                                              * (float)0.5))
                                                                              * (float)v17)
                                                                      - (float)1.5)
                                                      * (float)v17)
                                              * (float)((float)((float)(v27 * v27)
                                                              + (float)((float)(v29 * v29) + (float)(v28 * v28)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v17
                                                                              * (float)((float)((float)(v27 * v27)
                                                                                              + (float)((float)(v29 * v29) + (float)(v28 * v28)))
                                                                                      * (float)0.5))
                                                                      * (float)v17)
                                                              - (float)1.5)
                                              * (float)v17))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v17
                                                      * (float)((float)((float)(v27 * v27)
                                                                      + (float)((float)(v29 * v29) + (float)(v28 * v28)))
                                                              * (float)0.5))
                                              * (float)v17)
                                      - (float)1.5)
                      * (float)v17));
  v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)((float)((float)(v27 * v27) + (float)((float)(v29 * v29) + (float)(v28 * v28))) * (float)0.5)) * (float)v17) - (float)1.5)
                                                                                              * (float)v17)
                                                                                      * (float)((float)((float)(v27 * v27) + (float)((float)(v29 * v29) + (float)(v28 * v28)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)((float)(v27 * v27) + (float)((float)(v29 * v29) + (float)(v28 * v28))) * (float)0.5)) * (float)v17) - (float)1.5)
                                                                                      * (float)v17))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v17
                                                                                              * (float)((float)((float)(v27 * v27) + (float)((float)(v29 * v29) + (float)(v28 * v28))) * (float)0.5))
                                                                                      * (float)v17)
                                                                              - (float)1.5)
                                                              * (float)v17))
                                              * (float)((float)((float)(v27 * v27)
                                                              + (float)((float)(v29 * v29) + (float)(v28 * v28)))
                                                      * (float)0.5))
                                      * (float)v18)
                              - (float)1.5)
              * (float)v18);
  v20 = (float)(v27 * (float)v19);
  v27 = v27 * (float)v19;
  v21 = (float)(v28 * (float)v19);
  v28 = v28 * (float)v19;
  v22 = (float)(v29 * (float)v19);
  v29 = v29 * (float)v19;
  if ( initialSpeed == -1.0 )
    speed = this->projectileDecl->notHitscanInfo.speed;
  else
    speed = initialSpeed;
  this->intitialFireAxis.mat[0].x = *v9;
  this->intitialFireAxis.mat[0].y = v9[1];
  this->intitialFireAxis.mat[0].z = v9[2];
  this->intitialFireAxis.mat[1].x = v9[3];
  this->intitialFireAxis.mat[1].y = v9[4];
  this->intitialFireAxis.mat[1].z = v9[5];
  this->intitialFireAxis.mat[2].x = v9[6];
  this->intitialFireAxis.mat[2].y = v9[7];
  this->intitialFireAxis.mat[2].z = v9[8];
  v24 = this->projectileDecl;
  v27 = (float)speed * (float)v20;
  projectilePhysics = this->projectilePhysics;
  v28 = (float)speed * (float)v21;
  v29 = (float)v22 * (float)speed;
  this->goalSpeed = v24->notHitscanInfo.speed;
  projectilePhysics->SetLinearVelocity(this: projectilePhysics, a2: (const idVec3 *)&v27, a3: 0);
  breakAwaySnd = this->projectileDecl->notHitscanInfo.breakAwaySnd;
  if ( breakAwaySnd != nullptr )
    idPresentable::StartSoundShader(
      this,
      channel: SND_CHANNEL_ANY,
      shader: breakAwaySnd,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0);
}


// ========================================================================
// ?ClientThink@idPresentableProjectile_Grenade@@UAAXHM_N@Z
// EA  : 0x82B8C758
// RVA : 0x00B8C758
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __fastcall idPresentableProjectile_Grenade::ClientThink(
        idPresentableProjectile_Grenade *this,
        int curTime,
        double fraction,
        bool predict)
{
  idPhysics *projectilePhysics; // r28
  int GameMs; // r29
  int GameMsPerFrame; // r3
  const idVec3 *v8; // r3
  float *v9; // r3

  idPresentableProjectile::ClientThink(this, curTime, fraction, predict);
  if ( this->index >= 0x2000 )
  {
    if ( g_projectileClientDontMove.valueInteger == 0 )
    {
      projectilePhysics = this->projectilePhysics;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      projectilePhysics->Evaluate(this: projectilePhysics, a2: GameMsPerFrame, a3: GameMs);
    }
    v8 = this->projectilePhysics->GetOrigin(this: this->projectilePhysics, a2: 0);
    this->origin.x = v8->x;
    this->origin.y = v8->y;
    this->origin.z = v8->z;
    v9 = (float *)this->projectilePhysics->GetAxis(this: this->projectilePhysics, a2: 0);
    this->axis.mat[0].x = *v9;
    this->axis.mat[0].y = v9[1];
    this->axis.mat[0].z = v9[2];
    this->axis.mat[1].x = v9[3];
    this->axis.mat[1].y = v9[4];
    this->axis.mat[1].z = v9[5];
    this->axis.mat[2].x = v9[6];
    this->axis.mat[2].y = v9[7];
    this->axis.mat[2].z = v9[8];
    this->Present(this);
  }
}


// ========================================================================
// ?ClientThink@idPresentableProjectile_Homing@@UAAXHM_N@Z
// EA  : 0x82B8C890
// RVA : 0x00B8C890
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

// attributes: thunk
void __fastcall idPresentableProjectile_Homing::ClientThink(
        idPresentableProjectile_Homing *this,
        int curTime,
        double fraction,
        bool predict)
{
  idPresentableProjectile_Grenade::ClientThink((idPresentableProjectile_Grenade *)this, curTime, fraction, predict);
}


// ========================================================================
// ?InternalClientLaunch@idPresentableProjectile_Grenade@@UAAXPAVidPresentable@@ABVidVec3@@ABVidMat3@@ABVidProjectileTarget@@MH@Z
// EA  : 0x82B8C898
// RVA : 0x00B8C898
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __fastcall idPresentableProjectile_Grenade::InternalClientLaunch(
        idPresentableProjectile_Grenade *this,
        idPresentable *attacker,
        const idVec3 *start,
        const idMat3 *fireAxis,
        const idProjectileTarget *_target,
        double initialSpeed,
        int startTime,
        int a8)
{
  double SpeedForFireAxis; // fp1
  double v16; // fp10
  double v17; // fp9
  const idVec3 *v18; // r4
  double v19; // fp10
  double v20; // fp9
  BOOL v21; // r8
  float v22[4]; // [sp+50h] [-60h] BYREF
  float v23[4]; // [sp+60h] [-50h] BYREF

  if ( initialSpeed == -1.0 )
  {
    SpeedForFireAxis = idPresentableProjectile_Grenade::GetSpeedForFireAxis(this, attacker, fireAxis);
    v16 = (float)(fireAxis->mat[0].y * (float)SpeedForFireAxis);
    v17 = (float)(fireAxis->mat[0].z * (float)SpeedForFireAxis);
    v22[0] = fireAxis->mat[0].x * (float)SpeedForFireAxis;
    v22[1] = v16;
    v18 = (const idVec3 *)v22;
    v22[2] = v17;
  }
  else
  {
    v18 = (const idVec3 *)v23;
    v19 = (float)(fireAxis->mat[0].y * (float)initialSpeed);
    v20 = (float)(fireAxis->mat[0].z * (float)initialSpeed);
    v23[0] = fireAxis->mat[0].x * (float)initialSpeed;
    v23[1] = v19;
    v23[2] = v20;
  }
  this->projectilePhysics->SetLinearVelocity(this: this->projectilePhysics, a2: v18, a3: 0);
  v21 = common->IsServer(this: common);
  if ( v21 )
    ((void (__fastcall *)(idEntity *, idPresentable *, const idVec3 *, const idMat3 *, const idProjectileTarget *, BOOL, int, double))this->entity->idPresentableProjectile::idPresentableAnimatedEntity::idPresentable::__vftable[1].SetColor_5)(
      a1: this->entity,
      a2: attacker,
      a3: start,
      a4: fireAxis,
      a5: _target,
      a6: v21,
      a7: a8,
      a8: initialSpeed);
}


// ========================================================================
// ?ClientLaunch@idPresentableProjectile@@QAAXPAVidPresentable@@ABVidVec3@@ABVidMat3@@ABVidProjectileTarget@@MHH@Z
// EA  : 0x82B8C9A8
// RVA : 0x00B8C9A8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __fastcall idPresentableProjectile::ClientLaunch(
        idPresentableProjectile *this,
        idPresentable *attacker_,
        const idVec3 *start,
        const idMat3 *fireAxis,
        const idProjectileTarget *target,
        double initialSpeed,
        int startTime,
        int launchTime_,
        int a9)
{
  bool v9; // r26
  bool adjustStartForCollision; // r23
  idPresentablePlayer *v17; // r22
  idPhysics *projectilePhysics; // r27
  idPresentable *v19; // r25
  idPresentable *Control; // r3
  idPresentable *v21; // r3
  int entityNumber; // r25
  float y; // r10
  char v24; // r24
  float z; // r9
  const idDeclProjectile *projectileDecl; // r11
  const idSoundShader *flySound; // r5
  float *v28; // r3
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // r7
  float *v30; // r3
  idPhysics *v31; // r29
  int launchTime; // r28
  const idMat3 *v33; // r27
  const idVec3 *v34; // r3
  idPhysics *v35; // r29
  int v36; // r28
  const idMat3 *v37; // r27
  const idVec3 *v38; // r3
  idEntity *entity; // r3
  idProjectile_Rocket *v40; // r3
  _DWORD v41[6]; // [sp+50h] [-90h] BYREF

  v9 = true;
  adjustStartForCollision = this->projectileDecl->notHitscanInfo.adjustStartForCollision;
  this->launchTime = a9;
  this->launchOrigin = *start;
  this->launchAxis = *fireAxis;
  this->launched = true;
  if ( attacker_ != nullptr )
    this->attacker.spawnId = attacker_->spawnId;
  else
    this->attacker.spawnId = 0;
  this->state = ACTIVE;
  this->Show(this);
  if ( attacker_ != nullptr )
    v17 = attacker_->GetPlayerInterface_2(this: attacker_);
  else
    v17 = nullptr;
  projectilePhysics = this->projectilePhysics;
  if ( attacker_ != nullptr )
  {
    v19 = attacker_;
    if ( v17 != nullptr )
    {
      v19 = v17;
      if ( idPresentablePlayer::GetControl(this: v17) != nullptr )
      {
        Control = idPresentablePlayer::GetControl(this: v17);
        if ( Control->GetVehicleInterface(this: Control) != nullptr )
        {
          v21 = idPresentablePlayer::GetControl(this: v17);
          v19 = (idPresentable *)v21->GetVehicleInterface(this: v21);
        }
      }
    }
    entityNumber = v19->entityNumber;
    projectilePhysics->GetClipModel(this: projectilePhysics, a2: 0)->ownerNumber = entityNumber;
  }
  y = start->y;
  v24 = 0;
  z = start->z;
  v41[0] = LODWORD(start->x);
  *(float *)&v41[1] = y;
  *(float *)&v41[2] = z;
  if ( attacker_ != nullptr && adjustStartForCollision )
  {
    if ( common->IsMultiplayer(this: common) )
      v9 = !common->IsClient(this: common);
    if ( v9 )
      v24 = idPresentableProjectile::AdjustStartToCollision(
              this,
              attacker: attacker_,
              direction: *(_QWORD *)&fireAxis->mat[0].x);
  }
  projectilePhysics->SetOrigin(this: projectilePhysics, a2: (const idVec3 *)v41, a3: -1);
  projectilePhysics->SetAxis(this: projectilePhysics, a2: fireAxis, a3: -1);
  ((void (__fastcall *)(idPresentableProjectile *, idPresentable *, const idVec3 *, const idMat3 *, const idProjectileTarget *, double))this->InternalClientLaunch)(
    a1: this,
    a2: attacker_,
    a3: start,
    a4: fireAxis,
    a5: target,
    a6: initialSpeed);
  if ( this->projectileDecl->notHitscanInfo.inheritParentSpeed && common->IsServer(this: common) )
    ((void (__fastcall *)(idEntity *, idEntity *, const idMat3 *))this->entity->idPresentableAnimatedEntity::idPresentable::__vftable[1].SetColor_4)(
      a1: this->entity,
      a2: attacker_->entity,
      a3: fireAxis);
  projectileDecl = this->projectileDecl;
  if ( (!projectileDecl->notHitscanInfo.grenadeInfo.cookable || v17 == nullptr) && projectileDecl != nullptr )
  {
    flySound = projectileDecl->notHitscanInfo.flySound;
    if ( flySound != nullptr )
      idPresentable::StartSoundShader(
        this,
        channel: SND_CHANNEL_BODY,
        shader: flySound,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0);
  }
  v28 = (float *)projectilePhysics->GetOrigin(this: projectilePhysics, a2: 0);
  GetAxis = projectilePhysics->GetAxis;
  this->origin.x = *v28;
  this->origin.y = v28[1];
  this->origin.z = v28[2];
  v30 = (float *)GetAxis(this: projectilePhysics, a2: 0);
  this->axis.mat[0].x = *v30;
  this->axis.mat[0].y = v30[1];
  this->axis.mat[0].z = v30[2];
  this->axis.mat[1].x = v30[3];
  this->axis.mat[1].y = v30[4];
  this->axis.mat[1].z = v30[5];
  this->axis.mat[2].x = v30[6];
  this->axis.mat[2].y = v30[7];
  this->axis.mat[2].z = v30[8];
  v31 = this->projectilePhysics;
  launchTime = this->launchTime;
  v33 = v31->GetAxis(this: v31, a2: 0);
  v34 = v31->GetOrigin(this: v31, a2: 0);
  idFXManager::StartFX(this: &this->fxManager, org: v34, axis: v33, time: launchTime, startCondition: 86);
  v35 = this->projectilePhysics;
  v36 = this->launchTime;
  v37 = v35->GetAxis(this: v35, a2: 0);
  v38 = v35->GetOrigin(this: v35, a2: 0);
  idFXManager::StartFX(this: &this->fxManager, org: v38, axis: v37, time: v36, startCondition: 87);
  this->hideDuringFirstSSInterval = false;
  if ( v24 != 0 )
  {
    entity = this->entity;
    if ( entity != nullptr
      && (unsigned __int8)idClass::IsType(this: entity, superclass: &idProjectile_Rocket::Type) != 0 )
    {
      v40 = idProjectile_Rocket::CastTo(c: (idProjectile_Rocket *)this->entity);
      v40->Explode(this: v40, a2: nullptr, a3: nullptr);
    }
  }
}


// ========================================================================
// ?InternalClientLaunch@idPresentableProjectile_Homing@@UAAXPAVidPresentable@@ABVidVec3@@ABVidMat3@@ABVidProjectileTarget@@MH@Z
// EA  : 0x82B8CE68
// RVA : 0x00B8CE68
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __fastcall idPresentableProjectile_Homing::InternalClientLaunch(
        idPresentableProjectile_Homing *this,
        idPresentable *attacker,
        const idVec3 *start,
        idMat3 *fireAxis,
        const idProjectileTarget *_target,
        double initialSpeed,
        int startTime)
{
  idPresentable *v9; // r3
  const idEntity *entity; // r4
  idPhysics *projectilePhysics; // r3

  idPresentableProjectile_Rocket::InternalClientLaunch(
    this,
    attacker,
    start,
    fireAxis,
    (int)_target,
    initialSpeed,
    startTime);
  if ( common->IsServer(this: common) && _target->type == TARGET_PRESENTABLE )
  {
    v9 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&_target->presentable);
    if ( v9 != nullptr )
    {
      entity = v9->entity;
      if ( entity != nullptr )
        idProjectile_Homing::NotifyEntityAboutHoming_FromPresentable(
          this: (idProjectile_Homing *)this->entity,
          ent: entity,
          addNew: true);
    }
  }
  if ( this->projectileDecl->notHitscanInfo.homingInfo.attackStyle == GUIDED_RPG )
  {
    this->homingState = ACQUIRING|FLYOUT;
  }
  else if ( _target->type != TARGET_NONE )
  {
    projectilePhysics = this->projectilePhysics;
    this->homingState = LAUNCHING;
    projectilePhysics->SetGravity(this: projectilePhysics, a2: &gameLocal->clientGame.gravity);
  }
  this->target.type = _target->type;
  this->target.pos.x = _target->pos.x;
  this->target.pos.y = _target->pos.y;
  this->target.pos.z = _target->pos.z;
  this->target.presentable.spawnId = _target->presentable.spawnId;
}


// ========================================================================
// ?Init@idPresentableProjectile@@QAAXXZ
// EA  : 0x82B8CF80
// RVA : 0x00B8CF80
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __fastcall idPresentableProjectile::Init(idPresentableProjectile *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  const idDeclFX *fxDeclQuad; // r4
  unsigned __int64 v5; // r6
  const char *v6; // r7
  idPLogScope v7[8]; // [sp+50h] [-40h] BYREF

  if ( this->projectileDecl != nullptr )
  {
    RD_EventBegin(name: "idPresentableProjectile::Init - fxManager.Init");
    LODWORD(v2) = "idPresentableProjectile::Init - fxManager.Init";
    HIDWORD(v2) = 2;
    idPLogScope::idPLogScope(this: v7, pl: &pLog, gMask: v2, label: v3);
    if ( this->hasQuad && (fxDeclQuad = this->projectileDecl->fxDeclQuad) != nullptr )
      this->InitFXMgr(this, a2: fxDeclQuad);
    else
      this->InitFXMgr(this, a2: this->projectileDecl->fxDecl);
    idPLogScope::~idPLogScope(this: v7);
    RD_EventEnd();
    RD_EventBegin(name: "idProjectile::Spawn - fxManager.StartFx");
    LODWORD(v5) = "idProjectile::Spawn - fxManager.StartFx";
    HIDWORD(v5) = 2;
    idPLogScope::idPLogScope(this: v7, pl: &pLog, gMask: v5, label: v6);
    this->StartFX(this, a2: FX_NONE, a3: FX_EXTRA_COND_NONE);
    idPLogScope::~idPLogScope(this: v7);
    RD_EventEnd();
  }
  this->launchTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
}


// ========================================================================
// __unwind$492424
// EA  : 0x82B8D094
// RVA : 0x00B8D094
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void _unwind_492424()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$492425
// EA  : 0x82B8D0BC
// RVA : 0x00B8D0BC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void _unwind_492425()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$492426
// EA  : 0x82B8D0E4
// RVA : 0x00B8D0E4
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void _unwind_492426()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 89));
}


// ========================================================================
// __unwind$492427
// EA  : 0x82B8D10C
// RVA : 0x00B8D10C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void _unwind_492427()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?Serialize@idPresentableProjectile@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B8D138
// RVA : 0x00B8D138
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __fastcall idPresentableProjectile::Serialize(idPresentableProjectile *this, idSerializer *ser)
{
  const idDeclProjectile **p_projectileDecl; // r25
  bool v5; // r24
  idBitMsg *msg; // r3
  idVec3 *p_launchOrigin; // r26
  idBitMsg *v8; // r3
  idVec3 *v9; // r4
  __int64 v10; // r8
  idMat3 *p_launchAxis; // r28
  idBitMsg *v12; // r3
  bool launched; // r29
  bool v14; // r30
  bool hasQuad; // r30
  idBitMsg *v16; // r3
  const idDeclProjectile *v17; // r11
  const idSoundShader *flySound; // r5
  idBitMsg *v19; // r3
  unsigned int v20; // r10
  projectileState_t state; // r30

  p_projectileDecl = &this->projectileDecl;
  idPresentableAnimatedEntity::Serialize(this, ser);
  v5 = (_cntlzw((unsigned int)this->projectileDecl) & 0x20) != 0;
  idSerializer::Serialize<idDeclProjectile>(this: ser, decl: &this->projectileDecl);
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->attacker.spawnId, numBits: 32);
  else
    this->attacker.spawnId = idBitMsg::ReadBits(this: msg, numBits: 32);
  p_launchOrigin = &this->launchOrigin;
  v8 = ser->msg;
  v9 = &this->launchOrigin;
  if ( ser->writing )
    idBitMsg::WriteQuantizedVector<idVec3,32768,17>(this: v8, v: v9);
  else
    idBitMsg::ReadQuantizedVector<idVec3,32768,17>(this: v8, v: v9);
  p_launchAxis = &this->launchAxis;
  idSerializer::SerializeQ(this: ser, axis: (idQuat *)&this->launchAxis, bits: 15, a4: v10);
  v12 = ser->msg;
  launched = this->launched;
  v14 = launched;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v12, value: this->launched, numBits: 1);
  else
    v14 = (_cntlzw(idBitMsg::ReadBits(this: v12, numBits: 1) - 1) & 0x20) != 0;
  this->launched = v14;
  hasQuad = this->hasQuad;
  v16 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v16, value: this->hasQuad, numBits: 1);
  else
    hasQuad = (_cntlzw(idBitMsg::ReadBits(this: v16, numBits: 1) - 1) & 0x20) != 0;
  v17 = *p_projectileDecl;
  this->hasQuad = hasQuad;
  if ( v17 != nullptr && v5 )
    idPresentableProjectile::Init(this);
  if ( !ser->writing && !launched && this->launched && !this->becameReplicated )
  {
    this->origins[0].x = p_launchOrigin->x;
    this->origins[0].y = this->launchOrigin.y;
    this->origins[0].z = this->launchOrigin.z;
    this->axes[0].mat[0].x = p_launchAxis->mat[0].x;
    this->axes[0].mat[0].y = this->launchAxis.mat[0].y;
    this->axes[0].mat[0].z = this->launchAxis.mat[0].z;
    this->axes[0].mat[1].x = this->launchAxis.mat[1].x;
    this->axes[0].mat[1].y = this->launchAxis.mat[1].y;
    this->axes[0].mat[1].z = this->launchAxis.mat[1].z;
    this->axes[0].mat[2].x = this->launchAxis.mat[2].x;
    this->axes[0].mat[2].y = this->launchAxis.mat[2].y;
    this->axes[0].mat[2].z = this->launchAxis.mat[2].z;
    if ( *p_projectileDecl != nullptr )
    {
      flySound = (*p_projectileDecl)->notHitscanInfo.flySound;
      if ( flySound != nullptr )
        idPresentable::StartSoundShader(
          this,
          channel: SND_CHANNEL_BODY,
          shader: flySound,
          soundShaderFlags: (soundShaderFlags_t)0,
          peerMask: 0);
    }
    this->origin.x = p_launchOrigin->x;
    this->origin.y = this->launchOrigin.y;
    this->origin.z = this->launchOrigin.z;
    this->axis.mat[0].x = p_launchAxis->mat[0].x;
    this->axis.mat[0].y = this->launchAxis.mat[0].y;
    this->axis.mat[0].z = this->launchAxis.mat[0].z;
    this->axis.mat[1].x = this->launchAxis.mat[1].x;
    this->axis.mat[1].y = this->launchAxis.mat[1].y;
    this->axis.mat[1].z = this->launchAxis.mat[1].z;
    this->axis.mat[2].x = this->launchAxis.mat[2].x;
    this->axis.mat[2].y = this->launchAxis.mat[2].y;
    this->axis.mat[2].z = this->launchAxis.mat[2].z;
    if ( g_projectileDebug.valueInteger != 0 )
      clientGame->renderWorld->DebugAxis_2(
        this: clientGame->renderWorld,
        a2: &this->launchOrigin,
        a3: &this->launchAxis,
        a4: 5000,
        a5: false);
  }
  idFXManager::Serialize(this: &this->fxManager, ser);
  v19 = ser->msg;
  v20 = _cntlzw(5u);
  state = this->state;
  if ( ser->writing )
  {
    idBitMsg::WriteBits(this: v19, value: this->state, numBits: 32 - v20);
    this->state = state;
  }
  else
  {
    this->state = idBitMsg::ReadBits(this: v19, numBits: 32 - v20);
  }
}


// ========================================================================
// ??0idPresentableProjectile@@QAA@PAVidProjectile@@PAVidRenderModel@@PAVidAnimStack@@@Z
// EA  : 0x82B8D438
// RVA : 0x00B8D438
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

idPresentableProjectile *__fastcall idPresentableProjectile::idPresentableProjectile(
        idPresentableProjectile *this,
        idProjectile *ent,
        idRenderModel *renderModel_,
        idAnimStack *animStack_)
{
  idPresentableProjectile *v6; // r3

  idPresentableAnimatedEntity::idPresentableAnimatedEntity(
    this,
    ent,
    renderModel_,
    animStack_,
    entityNumber_: 0x1FFF,
    fxDecl_: nullptr,
    useSphereModel_: false);
  this->__vftable = (idPresentableProjectile_vtbl *)&idPresentableProjectile::`vftable';
  this->attacker.spawnId = 0;
  idPresentableProjectile::SetDefaults(this);
  this->projectileDecl = ent->projectileDecl;
  idPresentableProjectile::Init(this: v6);
  return this;
}


// ========================================================================
// __unwind$492706
// EA  : 0x82B8D4A0
// RVA : 0x00B8D4A0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void _unwind_492706()
{
  int v0; // r12

  idPresentableAnimatedEntity::~idPresentableAnimatedEntity(this: *(idPresentableAnimatedEntity **)(v0 - 128 + 148));
}


// ========================================================================
// ??0idPresentableProjectile@@QAA@PBVidDeclProjectile@@PAVidRenderModel@@PAVidAnimStack@@@Z
// EA  : 0x82B8D4D0
// RVA : 0x00B8D4D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

idPresentableProjectile *__fastcall idPresentableProjectile::idPresentableProjectile(
        idPresentableProjectile *this,
        const idDeclProjectile *decl,
        idRenderModel *renderModel_,
        idAnimStack *animStack_)
{
  idPresentableProjectile *v6; // r3

  idPresentableAnimatedEntity::idPresentableAnimatedEntity(
    this,
    ent: nullptr,
    renderModel_,
    animStack_,
    entityNumber_: 0x1FFF,
    fxDecl_: nullptr,
    useSphereModel_: false);
  this->__vftable = (idPresentableProjectile_vtbl *)&idPresentableProjectile::`vftable';
  this->attacker.spawnId = 0;
  idPresentableProjectile::SetDefaults(this);
  this->projectileDecl = decl;
  idPresentableProjectile::Init(this: v6);
  return this;
}


// ========================================================================
// __unwind$492736
// EA  : 0x82B8D538
// RVA : 0x00B8D538
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void _unwind_492736()
{
  int v0; // r12

  idPresentableAnimatedEntity::~idPresentableAnimatedEntity(this: *(idPresentableAnimatedEntity **)(v0 - 128 + 148));
}


// ========================================================================
// ??0idPresentableProjectile_Rocket@@QAA@PAVidProjectile_Rocket@@PAVidRenderModel@@PAVidAnimStack@@@Z
// EA  : 0x82B8D568
// RVA : 0x00B8D568
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

idPresentableProjectile_Rocket *__fastcall idPresentableProjectile_Rocket::idPresentableProjectile_Rocket(
        idPresentableProjectile_Rocket *this,
        idProjectile_Rocket *ent,
        idRenderModel *renderModel_,
        idAnimStack *animStack_)
{
  idPresentableProjectile::idPresentableProjectile(this, ent, renderModel_, animStack_);
  this->__vftable = (idPresentableProjectile_Rocket_vtbl *)&idPresentableProjectile_Rocket::`vftable';
  idPhysics_RigidBody::idPhysics_RigidBody(this: &this->physicsObj);
  this->calcThrustDelay = 0;
  this->goalSpeed = 0.0;
  return this;
}


// ========================================================================
// __unwind$492762
// EA  : 0x82B8D5D0
// RVA : 0x00B8D5D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void _unwind_492762()
{
  int v0; // r12

  idPresentableProjectile::~idPresentableProjectile(this: *(idPresentableProjectile **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idPresentableProjectile_Rocket@@QAA@PBVidDeclProjectile@@PAVidRenderModel@@PAVidAnimStack@@@Z
// EA  : 0x82B8D600
// RVA : 0x00B8D600
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

idPresentableProjectile_Rocket *__fastcall idPresentableProjectile_Rocket::idPresentableProjectile_Rocket(
        idPresentableProjectile_Rocket *this,
        const idDeclProjectile *decl,
        idRenderModel *renderModel_,
        idAnimStack *animStack_)
{
  __int64 v5; // r29
  idClipModelInfo v7[2]; // [sp+50h] [-60h] BYREF

  HIDWORD(v5) = &this->physicsObj;
  idPresentableProjectile::idPresentableProjectile(this, decl, renderModel_, animStack_);
  this->__vftable = (idPresentableProjectile_Rocket_vtbl *)&idPresentableProjectile_Rocket::`vftable';
  idPhysics_RigidBody::idPhysics_RigidBody(this: &this->physicsObj);
  LODWORD(v5) = 0;
  this->calcThrustDelay = 0;
  this->goalSpeed = 0.0;
  v7[0].clipModelName.str = &byte_8200D768;
  idClipModelInfo::Clear(this: v7);
  *(_QWORD *)&v7[0].offset.x = v5;
  *(_QWORD *)&v7[0].offset.z = v5;
  *(_QWORD *)&v7[0].clipModelName.str = v5;
  v7[0].overrideClipMaterial = nullptr;
  v7[0].size.x = 5.0;
  v7[0].type = CLIPMODEL_BOX;
  v7[0].size.y = 5.0;
  v7[0].size.z = 5.0;
  idPresentableProjectile::SetupClientProjectilePhysics(
    this,
    physicsObj: &this->physicsObj,
    clipModelInfo: v7,
    trm: nullptr,
    overrideCollision: -1.0,
    cb: (idPhysicsCallbacks *)v7,
    a7: &fakbCBStopWhenCollide);
  return this;
}


// ========================================================================
// __unwind$492783
// EA  : 0x82B8D6C4
// RVA : 0x00B8D6C4
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void _unwind_492783()
{
  int v0; // r12

  idPresentableProjectile::~idPresentableProjectile(this: *(idPresentableProjectile **)(v0 - 176 + 196));
}


// ========================================================================
// __unwind$492784
// EA  : 0x82B8D6EC
// RVA : 0x00B8D6EC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void _unwind_492784()
{
  int v0; // r12

  idPhysics_RigidBody::~idPhysics_RigidBody(this: (idPhysics_RigidBody *)(*(_DWORD *)(v0 - 176 + 196) + 1408));
}


// ========================================================================
// ??0idPresentableProjectile_Homing@@QAA@PAVidProjectile_Homing@@PAVidRenderModel@@PAVidAnimStack@@@Z
// EA  : 0x82B8D718
// RVA : 0x00B8D718
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

idPresentableProjectile_Homing *__fastcall idPresentableProjectile_Homing::idPresentableProjectile_Homing(
        idPresentableProjectile_Homing *this,
        idProjectile_Homing *ent,
        idRenderModel *renderModel_,
        idAnimStack *animStack_)
{
  idPresentableProjectile_Rocket::idPresentableProjectile_Rocket(this, ent, renderModel_, animStack_);
  this->__vftable = (idPresentableProjectile_Homing_vtbl *)&idPresentableProjectile_Homing::`vftable';
  this->target.type = TARGET_NONE;
  this->target.pos = vec3_origin;
  this->target.presentable.spawnId = 0;
  this->homingState = ACQUIRING;
  return this;
}


// ========================================================================
// ??0idPresentableProjectile_Homing@@QAA@PBVidDeclProjectile@@PAVidRenderModel@@PAVidAnimStack@@@Z
// EA  : 0x82B8D790
// RVA : 0x00B8D790
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

idPresentableProjectile_Homing *__fastcall idPresentableProjectile_Homing::idPresentableProjectile_Homing(
        idPresentableProjectile_Homing *this,
        const idDeclProjectile *decl,
        idRenderModel *renderModel_,
        idAnimStack *animStack_)
{
  idPresentableProjectile_Rocket::idPresentableProjectile_Rocket(this, decl, renderModel_, animStack_);
  this->__vftable = (idPresentableProjectile_Homing_vtbl *)&idPresentableProjectile_Homing::`vftable';
  this->target.type = TARGET_NONE;
  this->target.pos = vec3_origin;
  this->target.presentable.spawnId = 0;
  this->homingState = ACQUIRING;
  return this;
}


// ========================================================================
// ??0idPresentableProjectile_Grenade@@QAA@PAVidProjectile_Grenade@@PAVidRenderModel@@PAVidAnimStack@@@Z
// EA  : 0x82B8D810
// RVA : 0x00B8D810
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

idPresentableProjectile_Grenade *__fastcall idPresentableProjectile_Grenade::idPresentableProjectile_Grenade(
        idPresentableProjectile_Grenade *this,
        idProjectile_Grenade *ent,
        idRenderModel *renderModel_,
        idAnimStack *animStack_)
{
  idPresentableProjectile::idPresentableProjectile(this, ent, renderModel_, animStack_);
  this->__vftable = (idPresentableProjectile_Grenade_vtbl *)&idPresentableProjectile_Grenade::`vftable';
  idPhysics_RigidBody::idPhysics_RigidBody(this: &this->physicsObj);
  return this;
}


// ========================================================================
// __unwind$492927
// EA  : 0x82B8D864
// RVA : 0x00B8D864
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void _unwind_492927()
{
  int v0; // r12

  idPresentableProjectile::~idPresentableProjectile(this: *(idPresentableProjectile **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idPresentableProjectile_Grenade@@QAA@PBVidDeclProjectile@@PAVidRenderModel@@PAVidAnimStack@@@Z
// EA  : 0x82B8D898
// RVA : 0x00B8D898
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

idPresentableProjectile_Grenade *__fastcall idPresentableProjectile_Grenade::idPresentableProjectile_Grenade(
        idPresentableProjectile_Grenade *this,
        const idDeclProjectile *decl,
        idRenderModel *renderModel_,
        idAnimStack *animStack_)
{
  __int64 v5; // r11
  idClipModelInfo v7; // [sp+50h] [-50h] BYREF

  idPresentableProjectile::idPresentableProjectile(this, decl, renderModel_, animStack_);
  this->__vftable = (idPresentableProjectile_Grenade_vtbl *)&idPresentableProjectile_Grenade::`vftable';
  idPhysics_RigidBody::idPhysics_RigidBody(this: &this->physicsObj);
  v7.clipModelName.str = &byte_8200D768;
  idClipModelInfo::Clear(this: &v7);
  LODWORD(v5) = 0;
  HIDWORD(v5) = &joystick.joyAxis[0][2];
  *(_QWORD *)&v7.offset.x = v5;
  *(_QWORD *)&v7.offset.z = v5;
  *(_QWORD *)&v7.clipModelName.str = v5;
  v7.overrideClipMaterial = nullptr;
  v7.size.x = 5.0;
  v7.type = CLIPMODEL_BOX;
  v7.size.y = 5.0;
  v7.size.z = 5.0;
  idPresentableProjectile::SetupClientProjectilePhysics(
    this,
    physicsObj: &this->physicsObj,
    clipModelInfo: &v7,
    trm: nullptr,
    overrideCollision: -1.0,
    cb: (idPhysicsCallbacks *)&v7,
    a7: &fakeCB_1);
  this->projectilePhysics->SetClipMask(this: this->projectilePhysics, a2: 8463621, a3: -1);
  return this;
}


// ========================================================================
// __unwind$492948
// EA  : 0x82B8D96C
// RVA : 0x00B8D96C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void _unwind_492948()
{
  int v0; // r12

  idPresentableProjectile::~idPresentableProjectile(this: *(idPresentableProjectile **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$492949
// EA  : 0x82B8D994
// RVA : 0x00B8D994
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void _unwind_492949()
{
  int v0; // r12

  idPhysics_RigidBody::~idPhysics_RigidBody(this: (idPhysics_RigidBody *)(*(_DWORD *)(v0 - 160 + 180) + 1408));
}


// ========================================================================
// `dynamic initializer for 'g_projectileDebug''
// EA  : 0x8336E8A8
// RVA : 0x0136E8A8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_projectileDebug__()
{
  idCVar::idCVar(
    this: &g_projectileDebug,
    name: "g_projectileDebug",
    value: "0",
    flags: 1,
    description: "Debug projectiles",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_projectileDebug__);
}


// ========================================================================
// `dynamic initializer for 'g_projectileClientDontMove''
// EA  : 0x8336E900
// RVA : 0x0136E900
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_projectileClientDontMove__()
{
  idCVar::idCVar(
    this: &g_projectileClientDontMove,
    name: "g_projectileClientDontMove",
    value: "0",
    flags: 1,
    description: "Debug projectiles",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_projectileClientDontMove__);
}

