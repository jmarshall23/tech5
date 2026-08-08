
// ========================================================================
// ?Spawn@idMultiplayerTrigger@@QAAXXZ
// EA  : 0x82C950F8
// RVA : 0x00C950F8
// PDB : w:\tech5\tungsten\game\entities\multiplayertrigger.cpp
// ========================================================================

void __fastcall idMultiplayerTrigger::Spawn(idMultiplayerTrigger *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r3

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0x4000, a3: -1);
  v3 = idEntity::GetPhysics(this);
  v3->EnableClip(this: v3);
}


// ========================================================================
// ?Spawn@idTrigger_BoostPad@@QAAXXZ
// EA  : 0x82C95158
// RVA : 0x00C95158
// PDB : w:\tech5\tungsten\game\entities\multiplayertrigger.cpp
// ========================================================================

void __fastcall idTrigger_BoostPad::Spawn(idMultiplayerTrigger_BoostPad *this)
{
  if ( this->fxDecl != nullptr )
    idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ??0idMultiplayerTrigger@@QAA@XZ
// EA  : 0x82C95170
// RVA : 0x00C95170
// PDB : w:\tech5\tungsten\game\entities\multiplayertrigger.cpp
// ========================================================================

idMultiplayerTrigger *__fastcall idMultiplayerTrigger::idMultiplayerTrigger(idMultiplayerTrigger *this)
{
  idTrigger::idTrigger(this);
  this->__vftable = (idMultiplayerTrigger_vtbl *)&idMultiplayerTrigger::`vftable';
  return this;
}


// ========================================================================
// ?AllocPresentable@idMultiplayerTrigger_BoostPad@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82C951B8
// RVA : 0x00C951B8
// PDB : w:\tech5\tungsten\game\entities\multiplayertrigger.cpp
// ========================================================================

idPresentableMultiplayerTrigger *__fastcall idMultiplayerTrigger_BoostPad::AllocPresentable(
        idMultiplayerTrigger_BoostPad *this,
        idTreeAnimator *renderModel_)
{
  idMultiplayerTriggerStrategy_BoostPad *v4; // r3
  idMultiplayerTriggerStrategy_BoostPad *v5; // r11
  idPresentableMultiplayerTrigger *v6; // r3

  v4 = (idMultiplayerTriggerStrategy_BoostPad *)idMem::AllocWithLocation(
                                                  this: &mem,
                                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                  size: 0x50u,
                                                  tag: TAG_NEW,
                                                  zeroBuffer: false,
                                                  align: ALIGN_16,
                                                  heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v5 = idMultiplayerTriggerStrategy_BoostPad::idMultiplayerTriggerStrategy_BoostPad(this: v4);
  else
    v5 = nullptr;
  this->strategy = v5;
  v6 = (idPresentableMultiplayerTrigger *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                            size: 0x4D8u,
                                            tag: TAG_PRESENTABLE,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
  if ( v6 != nullptr )
    return idPresentableMultiplayerTrigger::idPresentableMultiplayerTrigger(
             this: v6,
             ent: this,
             renderModel_,
             entityNumber_: this->entityNumber,
             fxDecl_: this->fxDecl,
             strategy_: this->strategy);
  else
    return nullptr;
}


// ========================================================================
// __unwind$487776
// EA  : 0x82C95274
// RVA : 0x00C95274
// PDB : w:\tech5\tungsten\game\entities\multiplayertrigger.cpp
// ========================================================================

void __fastcall _unwind_487776(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// __unwind$487777
// EA  : 0x82C9529C
// RVA : 0x00C9529C
// PDB : w:\tech5\tungsten\game\entities\multiplayertrigger.cpp
// ========================================================================

void _unwind_487777()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ??0idMultiplayerTrigger_BoostPad@@QAA@XZ
// EA  : 0x82C95310
// RVA : 0x00C95310
// PDB : w:\tech5\tungsten\game\entities\multiplayertrigger.cpp
// ========================================================================

idMultiplayerTrigger_BoostPad *__fastcall idMultiplayerTrigger_BoostPad::idMultiplayerTrigger_BoostPad(
        idMultiplayerTrigger_BoostPad *this)
{
  idTrigger::idTrigger(this);
  this->fxDecl = nullptr;
  this->__vftable = (idMultiplayerTrigger_BoostPad_vtbl *)&idMultiplayerTrigger_BoostPad::`vftable';
  this->fxInfo.spawnId.value = 0x1FFF;
  this->acceleration = 5000000.0;
  this->time = 1000;
  this->strategy = nullptr;
  return this;
}


// ========================================================================
// ?GetFXOrigin@idTrigger_BoostPad@@QBAABVidVec3@@XZ
// EA  : 0x82C95378
// RVA : 0x00C95378
// PDB : w:\tech5\tungsten\game\entities\multiplayertrigger.cpp
// ========================================================================

const idVec3 *__fastcall idTrigger_BoostPad::GetFXOrigin(idMultiplayerTrigger_BoostPad *this)
{
  int value; // r10
  idInfo *v2; // r3
  idPhysics *Physics; // r3

  value = this->fxInfo.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v2 = (idInfo *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v2 != nullptr )
      this = (idMultiplayerTrigger_BoostPad *)idInfo::CastTo(c: v2);
    else
      this = nullptr;
  }
  Physics = idEntity::GetPhysics(this);
  return Physics->GetOrigin(this: Physics, a2: 0);
}


// ========================================================================
// ?Think@idMultiplayerTrigger_BoostPad@@UAAXXZ
// EA  : 0x82C95408
// RVA : 0x00C95408
// PDB : w:\tech5\tungsten\game\entities\multiplayertrigger.cpp
// ========================================================================

void __fastcall idMultiplayerTrigger_BoostPad::Think(idMultiplayerTrigger_BoostPad *this)
{
  idPresentable *presentable; // r3
  idEntity *Target; // r3
  idPhysics *Physics; // r3
  float *v5; // r3
  idMultiplayerTriggerStrategy_BoostPad *strategy; // r11
  idPresentable *v7; // r31
  int GameMs; // r3

  idEntity::RunPhysics(this);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  if ( presentable->GetMultiplayerTriggerInterface(this: presentable) != nullptr && this->strategy != nullptr )
  {
    this->strategy->fxOrigin = *idTrigger_BoostPad::GetFXOrigin(this);
    this->strategy->fxAxis = *idMultiplayerTrigger_BoostPad::GetFXAxis(this);
    this->strategy->acceleration = this->acceleration;
    this->strategy->time = this->time;
    Target = idEntity::GetTarget(this, i: 0);
    this->strategy->hasTarget = Target != nullptr;
    if ( Target != nullptr )
    {
      Physics = idEntity::GetPhysics(this: Target);
      v5 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      strategy = this->strategy;
      strategy->targetOrigin.x = *v5;
      strategy->targetOrigin.y = v5[1];
      strategy->targetOrigin.z = v5[2];
    }
  }
  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
  v7 = this->presentable;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v7->ServerThink(this: v7, a2: GameMs);
}

