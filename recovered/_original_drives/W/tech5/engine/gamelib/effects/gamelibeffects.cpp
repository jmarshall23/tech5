
// ========================================================================
// ?Update@idGameLibEffects@@QAA_NHHH@Z
// EA  : 0x82712F38
// RVA : 0x00712F38
// PDB : w:\tech5\engine\gamelib\effects\gamelibeffects.cpp
// ========================================================================

int __fastcall idGameLibEffects::Update(idGameLibEffects *this, int currTime, int gameMsPerFrame, int serverCurrTime)
{
  idRenderModelBeam *beamModel; // r3

  if ( !this->initialized )
    return 0;
  idDeferredDecalManager::Update(this: &this->deferredDecalManager, time: currTime);
  if ( this->effectsModel != nullptr )
    idRenderModelEffects::Update(this: this->effectsModel, newTime: currTime, gameMsPerFrame);
  beamModel = this->beamModel;
  if ( beamModel != nullptr )
    idRenderModelBeam::Update(this: beamModel, currTime);
  idWeaponTraceManager::Update(this: &this->weaponTraceManager);
  idImpactManager::Update(
    this: &this->weaponImpactManager,
    parentOrigin: &vec3_origin,
    parentAxis: &mat3_identity,
    localTime: currTime,
    serverTime: serverCurrTime);
  idImpactManager::Update(
    this: &this->impactManager,
    parentOrigin: &vec3_origin,
    parentAxis: &mat3_identity,
    localTime: currTime,
    serverTime: serverCurrTime);
  return 1;
}


// ========================================================================
// ?Shutdown@idGameLibEffects@@QAAXXZ
// EA  : 0x82713010
// RVA : 0x00713010
// PDB : w:\tech5\engine\gamelib\effects\gamelibeffects.cpp
// ========================================================================

void __fastcall idGameLibEffects::Shutdown(idGameLibEffects *this)
{
  idRenderModelEffects *effectsModel; // r3
  idRenderModelBeam *beamModel; // r3

  this->initialized = false;
  idEffectsModelManager::Shutdown(this: &this->effectsModelManager);
  idDeferredDecalManager::Shutdown(this: &this->deferredDecalManager);
  idRibbonModelManager::Shutdown(this: &this->ribbonModelManager);
  idWeaponTraceManager::Init(this: &this->weaponTraceManager);
  idFXModelRecycler::Shutdown(this: &this->fxModelRecycler);
  idImpactManager::Shutdown(this: &this->weaponImpactManager);
  idImpactManager::Shutdown(this: &this->impactManager);
  effectsModel = this->effectsModel;
  if ( this->effectsModel != nullptr )
  {
    effectsModel->unlinked = true;
    effectsModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: effectsModel);
    this->effectsModel = nullptr;
  }
  beamModel = this->beamModel;
  if ( beamModel != nullptr )
  {
    beamModel->unlinked = true;
    beamModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: beamModel);
    this->beamModel = nullptr;
  }
}


// ========================================================================
// ?Init@idGameLibEffects@@QAAXPAVidRenderWorld@@PAVidClip@@MH@Z
// EA  : 0x827130A8
// RVA : 0x007130A8
// PDB : w:\tech5\engine\gamelib\effects\gamelibeffects.cpp
// ========================================================================

void __fastcall idGameLibEffects::Init(
        idGameLibEffects *this,
        idRenderWorld *rw,
        idClip *clip,
        double diversity,
        const int localPlayerIndex)
{
  idRenderModelEffects *v9; // r3
  idRenderModelDecal *v10; // r3
  idRenderModelBeam *v11; // r3
  int v12; // r5
  int v13; // r5

  if ( this->initialized )
    idGameLibEffects::Shutdown(this);
  v9 = (idRenderModelEffects *)rw->AllocRenderModel(this: rw, a2: "_smoke", a3: 1, a4: -1);
  this->effectsModel = v9;
  idRenderModel::CommitThisFrame(this: v9);
  v10 = rw->DecalModel(this: rw);
  this->decalModel = v10;
  idRenderModel::CommitThisFrame(this: v10);
  v11 = (idRenderModelBeam *)rw->AllocRenderModel(this: rw, a2: "_beam", a3: 1, a4: -1);
  this->beamModel = v11;
  idRenderModel::CommitThisFrame(this: v11);
  idEffectsModelManager::Init(this: &this->effectsModelManager);
  idDeferredDecalManager::Init(this: &this->deferredDecalManager, clip_: clip, decalModel_: this->decalModel);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->ribbonModelManager);
  idWeaponTraceManager::Init(this: &this->weaponTraceManager);
  idFXModelRecycler::Init(this: &this->fxModelRecycler);
  idImpactManager::Init(
    this: &this->weaponImpactManager,
    effectsModelManager_: &this->effectsModelManager,
    diversity,
    maxImpacts: v12,
    playerIndex: 64);
  idImpactManager::Init(
    this: &this->impactManager,
    effectsModelManager_: &this->effectsModelManager,
    diversity,
    maxImpacts: v13,
    playerIndex: 32);
  this->initialized = true;
}


// ========================================================================
// ??1idGameLibEffects@@QAA@XZ
// EA  : 0x827131E8
// RVA : 0x007131E8
// PDB : w:\tech5\engine\gamelib\effects\gamelibeffects.cpp
// ========================================================================

void __fastcall idGameLibEffects::~idGameLibEffects(idGameLibEffects *this)
{
  this->effectsModel = nullptr;
  this->decalModel = nullptr;
  this->beamModel = nullptr;
  idImpactManager::~idImpactManager(this: &this->impactManager);
  idImpactManager::~idImpactManager(this: &this->weaponImpactManager);
  idFXModelRecycler::~idFXModelRecycler(this: &this->fxModelRecycler);
  `eh vector destructor iterator'(
    ptr: &this->weaponTraceManager,
    size: 0x1A8u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  idRibbonModelManager::~idRibbonModelManager(this: &this->ribbonModelManager);
  `eh vector destructor iterator'(
    ptr: &this->deferredDecalManager,
    size: 0x40u,
    count: 16,
    pDtor: (void (__fastcall *)(void *))idPhysics_StaticMulti::UpdateTime);
  idEffectsModelManager::~idEffectsModelManager(this: &this->effectsModelManager);
}


// ========================================================================
// __unwind$245571
// EA  : 0x82713288
// RVA : 0x00713288
// PDB : w:\tech5\engine\gamelib\effects\gamelibeffects.cpp
// ========================================================================

void _unwind_245571()
{
  int v0; // r12

  idEffectsModelManager::~idEffectsModelManager(this: (idEffectsModelManager *)(*(_DWORD *)(v0 - 112 + 132) + 12));
}


// ========================================================================
// __unwind$245572
// EA  : 0x827132B4
// RVA : 0x007132B4
// PDB : w:\tech5\engine\gamelib\effects\gamelibeffects.cpp
// ========================================================================

void _unwind_245572()
{
  int v0; // r12

  idDeferredDecalManager::~idDeferredDecalManager(this: (idDeferredDecalManager *)(*(_DWORD *)(v0 - 112 + 132) + 3296));
}


// ========================================================================
// __unwind$245573
// EA  : 0x827132E0
// RVA : 0x007132E0
// PDB : w:\tech5\engine\gamelib\effects\gamelibeffects.cpp
// ========================================================================

void _unwind_245573()
{
  int v0; // r12

  idRibbonModelManager::~idRibbonModelManager(this: (idRibbonModelManager *)(*(_DWORD *)(v0 - 112 + 132) + 4336));
}


// ========================================================================
// __unwind$245574
// EA  : 0x8271330C
// RVA : 0x0071330C
// PDB : w:\tech5\engine\gamelib\effects\gamelibeffects.cpp
// ========================================================================

void _unwind_245574()
{
  int v0; // r12

  idWeaponTraceManager::~idWeaponTraceManager(this: (idWeaponTraceManager *)(*(_DWORD *)(v0 - 112 + 132) + 4688));
}


// ========================================================================
// __unwind$245575
// EA  : 0x82713338
// RVA : 0x00713338
// PDB : w:\tech5\engine\gamelib\effects\gamelibeffects.cpp
// ========================================================================

void _unwind_245575()
{
  int v0; // r12

  idFXModelRecycler::~idFXModelRecycler(this: (idFXModelRecycler *)(*(_DWORD *)(v0 - 112 + 132) + 5540));
}


// ========================================================================
// __unwind$245576
// EA  : 0x82713364
// RVA : 0x00713364
// PDB : w:\tech5\engine\gamelib\effects\gamelibeffects.cpp
// ========================================================================

void _unwind_245576()
{
  int v0; // r12

  idImpactManager::~idImpactManager(this: (idImpactManager *)(*(_DWORD *)(v0 - 112 + 132) + 8260));
}


// ========================================================================
// ??0idGameLibEffects@@QAA@XZ
// EA  : 0x82713398
// RVA : 0x00713398
// PDB : w:\tech5\engine\gamelib\effects\gamelibeffects.cpp
// ========================================================================

idGameLibEffects *__fastcall idGameLibEffects::idGameLibEffects(idGameLibEffects *this)
{
  this->effectsModel = nullptr;
  this->decalModel = nullptr;
  this->beamModel = nullptr;
  idEffectsModelManager::idEffectsModelManager(this: &this->effectsModelManager);
  idDeferredDecalManager::idDeferredDecalManager(this: &this->deferredDecalManager);
  idRibbonModelManager::idRibbonModelManager(this: &this->ribbonModelManager);
  idWeaponTraceManager::idWeaponTraceManager(this: &this->weaponTraceManager);
  idFXModelRecycler::idFXModelRecycler(this: &this->fxModelRecycler);
  idImpactManager::idImpactManager(this: &this->weaponImpactManager);
  idImpactManager::idImpactManager(this: &this->impactManager);
  this->initialized = false;
  return this;
}


// ========================================================================
// __unwind$245630
// EA  : 0x82713408
// RVA : 0x00713408
// PDB : w:\tech5\engine\gamelib\effects\gamelibeffects.cpp
// ========================================================================

void _unwind_245630()
{
  int v0; // r12

  idEffectsModelManager::~idEffectsModelManager(this: (idEffectsModelManager *)(*(_DWORD *)(v0 - 112 + 132) + 12));
}


// ========================================================================
// __unwind$245631
// EA  : 0x82713434
// RVA : 0x00713434
// PDB : w:\tech5\engine\gamelib\effects\gamelibeffects.cpp
// ========================================================================

void _unwind_245631()
{
  int v0; // r12

  idDeferredDecalManager::~idDeferredDecalManager(this: (idDeferredDecalManager *)(*(_DWORD *)(v0 - 112 + 132) + 3296));
}


// ========================================================================
// __unwind$245632
// EA  : 0x82713460
// RVA : 0x00713460
// PDB : w:\tech5\engine\gamelib\effects\gamelibeffects.cpp
// ========================================================================

void _unwind_245632()
{
  int v0; // r12

  idRibbonModelManager::~idRibbonModelManager(this: (idRibbonModelManager *)(*(_DWORD *)(v0 - 112 + 132) + 4336));
}


// ========================================================================
// __unwind$245633
// EA  : 0x8271348C
// RVA : 0x0071348C
// PDB : w:\tech5\engine\gamelib\effects\gamelibeffects.cpp
// ========================================================================

void _unwind_245633()
{
  int v0; // r12

  idWeaponTraceManager::~idWeaponTraceManager(this: (idWeaponTraceManager *)(*(_DWORD *)(v0 - 112 + 132) + 4688));
}


// ========================================================================
// __unwind$245634
// EA  : 0x827134B8
// RVA : 0x007134B8
// PDB : w:\tech5\engine\gamelib\effects\gamelibeffects.cpp
// ========================================================================

void _unwind_245634()
{
  int v0; // r12

  idFXModelRecycler::~idFXModelRecycler(this: (idFXModelRecycler *)(*(_DWORD *)(v0 - 112 + 132) + 5540));
}


// ========================================================================
// __unwind$245635
// EA  : 0x827134E4
// RVA : 0x007134E4
// PDB : w:\tech5\engine\gamelib\effects\gamelibeffects.cpp
// ========================================================================

void _unwind_245635()
{
  int v0; // r12

  idImpactManager::~idImpactManager(this: (idImpactManager *)(*(_DWORD *)(v0 - 112 + 132) + 8260));
}

