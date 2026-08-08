
// ========================================================================
// ?Init@idEffectPhysicsBoxFountain@@QAAXPAVidClip@@PAVidTraceModelCache@@H@Z
// EA  : 0x826FA480
// RVA : 0x006FA480
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsboxfountain.cpp
// ========================================================================

void __fastcall idEffectPhysicsBoxFountain::Init(
        idEffectPhysicsBoxFountain *this,
        idClip *clip,
        idTraceModelCache *tmc,
        int entNum)
{
  int v6; // r3
  idBounds v7; // [sp+50h] [-640h] BYREF
  idTraceModel v8; // [sp+70h] [-620h] BYREF

  idEffectPhysicsBroadPhase::Init(this: &this->broadPhase, clip, tmc);
  v7.b[0].x = -16.0;
  v7.b[0].y = -16.0;
  v7.b[0].z = -16.0;
  v7.b[1].x = 16.0;
  v7.b[1].y = 16.0;
  v7.b[1].z = 16.0;
  idTraceModel::InitBox(this: &v8);
  idTraceModel::SetupBox(this: &v8, boxBounds: &v7);
  v6 = idTraceModelCache::AllocTraceModel(this: this->broadPhase.traceModelCache, trm: &v8, material: nullptr);
  idEffectPhysicsProperties::Setup(
    this: &this->properties,
    broadPhase: &this->broadPhase,
    traceModelIndex: v6,
    mass: 10.0);
  this->startOrigin.x = 0.0;
  this->startOrigin.y = 0.0;
  this->startOrigin.z = 64.0;
  this->spawnOrigin.x = 0.0;
  this->spawnOrigin.y = 0.0;
  this->spawnOrigin.z = 160.0;
  idEffectPhysicsBroadPhase::AddObject(
    this: &this->broadPhase,
    object: &this->spawnObject,
    origin: &this->spawnOrigin,
    axis: &mat3_identity,
    bounds: &v7);
  this->spawnObject.entityNum = entNum;
}


// ========================================================================
// ??1idEffectPhysicsBoxFountain@@QAA@XZ
// EA  : 0x826FA580
// RVA : 0x006FA580
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsboxfountain.cpp
// ========================================================================

void __fastcall idEffectPhysicsBoxFountain::~idEffectPhysicsBoxFountain(idEffectPhysicsBoxFountain *this)
{
  idRenderModelManyBoxes *manyBoxes; // r3

  manyBoxes = this->manyBoxes;
  if ( manyBoxes != nullptr )
  {
    manyBoxes->unlinked = true;
    manyBoxes->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: manyBoxes);
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->spawnObject.overlap);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->rigidBodies);
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->properties);
  idEffectPhysicsBroadPhase::~idEffectPhysicsBroadPhase(this: &this->broadPhase);
}


// ========================================================================
// __unwind$246559
// EA  : 0x826FA5FC
// RVA : 0x006FA5FC
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsboxfountain.cpp
// ========================================================================

void _unwind_246559()
{
  int v0; // r12

  idEffectPhysicsBroadPhase::~idEffectPhysicsBroadPhase(this: *(idEffectPhysicsBroadPhase **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$246560
// EA  : 0x826FA624
// RVA : 0x006FA624
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsboxfountain.cpp
// ========================================================================

void _unwind_246560()
{
  int v0; // r12

  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}


// ========================================================================
// __unwind$246561
// EA  : 0x826FA650
// RVA : 0x006FA650
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsboxfountain.cpp
// ========================================================================

void _unwind_246561()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 232));
}


// ========================================================================
// __unwind$246562
// EA  : 0x826FA67C
// RVA : 0x006FA67C
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsboxfountain.cpp
// ========================================================================

void _unwind_246562()
{
  int v0; // r12

  idSPObject::~idSPObject(this: (idSPObject *)(*(_DWORD *)(v0 - 112 + 132) + 288));
}


// ========================================================================
// ??0idEffectPhysicsBoxFountain@@QAA@XZ
// EA  : 0x826FA7D0
// RVA : 0x006FA7D0
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsboxfountain.cpp
// ========================================================================

idEffectPhysicsBoxFountain *__fastcall idEffectPhysicsBoxFountain::idEffectPhysicsBoxFountain(
        idEffectPhysicsBoxFountain *this)
{
  idEffectPhysicsBroadPhase::idEffectPhysicsBroadPhase(this: &this->broadPhase);
  idEffectPhysicsProperties::idEffectPhysicsProperties(this: &this->properties);
  this->rigidBodies.list = nullptr;
  this->rigidBodies.granularity = 0;
  this->rigidBodies.memTag = 59;
  this->rigidBodies.listStatic = 0;
  this->rigidBodies.size = 0;
  this->rigidBodies.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->rigidBodies);
  idSPObject::idSPObject(this: &this->spawnObject);
  this->random.seed = 0;
  this->manyBoxes = nullptr;
  this->lastFireTime = 0;
  this->currentFireRigidBody = 0;
  this->startOrigin.z = 0.0;
  this->startOrigin.y = 0.0;
  this->startOrigin.x = 0.0;
  this->spawnOrigin.z = 0.0;
  this->spawnOrigin.y = 0.0;
  this->spawnOrigin.x = 0.0;
  return this;
}


// ========================================================================
// __unwind$246773
// EA  : 0x826FA878
// RVA : 0x006FA878
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsboxfountain.cpp
// ========================================================================

void _unwind_246773()
{
  int v0; // r12

  idEffectPhysicsBroadPhase::~idEffectPhysicsBroadPhase(this: *(idEffectPhysicsBroadPhase **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$246774
// EA  : 0x826FA8A0
// RVA : 0x006FA8A0
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsboxfountain.cpp
// ========================================================================

void _unwind_246774()
{
  int v0; // r12

  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)(*(_DWORD *)(v0 - 128 + 148) + 72));
}


// ========================================================================
// __unwind$246775_0
// EA  : 0x826FA8CC
// RVA : 0x006FA8CC
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsboxfountain.cpp
// ========================================================================

void _unwind_246775_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 232));
}


// ========================================================================
// `dynamic initializer for 'g_effectPhysicsBoxFountain''
// EA  : 0x8333F4D8
// RVA : 0x0133F4D8
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsboxfountain.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_effectPhysicsBoxFountain__()
{
  idCVar::idCVar(
    this: &g_effectPhysicsBoxFountain,
    name: "g_effectPhysicsBoxFountain",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_effectPhysicsBoxFountain__);
}


// ========================================================================
// `dynamic initializer for 'g_effectPhysicsRespawnTime''
// EA  : 0x8333F530
// RVA : 0x0133F530
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsboxfountain.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_effectPhysicsRespawnTime__()
{
  idCVar::idCVar(
    this: &g_effectPhysicsRespawnTime,
    name: "g_effectPhysicsRespawnTime",
    value: "200",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_effectPhysicsRespawnTime__);
}

