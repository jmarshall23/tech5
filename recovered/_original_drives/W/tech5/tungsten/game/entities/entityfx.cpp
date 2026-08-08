
// ========================================================================
// ?ShowEditingDialog@idEntityFx@@UAAXXZ
// EA  : 0x82C49770
// RVA : 0x00C49770
// PDB : w:\tech5\tungsten\game\entities\entityfx.cpp
// ========================================================================

void __fastcall idEntityFx::ShowEditingDialog(idEntityFx *this)
{
  common->InitTool(this: common, a2: EDITOR_FX);
}


// ========================================================================
// ?UpdateEditingDialog@idEntityFx@@UAAXXZ
// EA  : 0x82C49790
// RVA : 0x00C49790
// PDB : w:\tech5\tungsten\game\entities\entityfx.cpp
// ========================================================================

void __fastcall idEntityFx::UpdateEditingDialog(idEntityFx *this)
{
  common->UpdateTool(this: common, a2: EDITOR_FX);
}


// ========================================================================
// ??0idEntityFx@@QAA@XZ
// EA  : 0x82C49828
// RVA : 0x00C49828
// PDB : w:\tech5\tungsten\game\entities\entityfx.cpp
// ========================================================================

idEntityFx *__fastcall idEntityFx::idEntityFx(idEntityFx *this)
{
  idDynamicEntity::idDynamicEntity(this);
  this->startOff = false;
  this->__vftable = (idEntityFx_vtbl *)&idEntityFx::`vftable';
  this->actionDelay = 0.0;
  this->cycleTrigger = false;
  this->fxEffect = nullptr;
  this->startCondition = FX_NONE;
  this->extraConditions = FX_EXTRA_COND_NONE;
  this->nextTriggerTime = -1;
  this->clipModelInfo.type = CLIPMODEL_NONE;
  return this;
}


// ========================================================================
// ?AllocPresentable@idEntityFx@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82C498A0
// RVA : 0x00C498A0
// PDB : w:\tech5\tungsten\game\entities\entityfx.cpp
// ========================================================================

idPresentable *__fastcall idEntityFx::AllocPresentable(idEntityFx *this, idRenderModel *renderModel_)
{
  idPresentable *v3; // r3

  v3 = (idPresentable *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x4B0u,
                          tag: TAG_PRESENTABLE,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    return idPresentable::idPresentable(
             this: v3,
             e: this,
             renderModel_: nullptr,
             entityNumber_: 0x1FFF,
             fxDecl_: this->fxEffect);
  else
    return nullptr;
}


// ========================================================================
// __unwind$487786
// EA  : 0x82C49924
// RVA : 0x00C49924
// PDB : w:\tech5\tungsten\game\entities\entityfx.cpp
// ========================================================================

void _unwind_487786()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?Hide@idEntityFx@@UAAXXZ
// EA  : 0x82C49950
// RVA : 0x00C49950
// PDB : w:\tech5\tungsten\game\entities\entityfx.cpp
// ========================================================================

void __fastcall idEntityFx::Hide(idEntityFx *this)
{
  const idEventArg *v2; // [sp+58h] [-28h]

  idDynamicEntity::Hide(this);
  idEventReceiver::PostEventMS(this, ev: &EV_StopFX, time: 0, arg1: v2);
  idEntity::BecomeInactive(this, flags: 1);
}


// ========================================================================
// ?Think@idEntityFx@@UAAXXZ
// EA  : 0x82C499C0
// RVA : 0x00C499C0
// PDB : w:\tech5\tungsten\game\entities\entityfx.cpp
// ========================================================================

void __fastcall idEntityFx::Think(idEntityFx *this)
{
  idPresentable *presentable; // r31
  int GameMs; // r3

  idDynamicEntity::Think(this);
  if ( (this->thinkFlags & 1) != 0 )
  {
    presentable = this->presentable;
    if ( presentable == nullptr
      || (GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED),
          (unsigned __int8)idFXManager::IsStopped(this: &presentable->fxManager, time: GameMs) != 0) )
    {
      idEntity::BecomeInactive(this, flags: 1);
    }
  }
}


// ========================================================================
// ?StartFX@idEntityFx@@QAAXW4fxCondition_t@@@Z
// EA  : 0x82C49A50
// RVA : 0x00C49A50
// PDB : w:\tech5\tungsten\game\entities\entityfx.cpp
// ========================================================================

void __fastcall idEntityFx::StartFX(idEntityFx *this, fxCondition_t condition)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  presentable->StartFX(this: presentable, a2: condition, a3: this->extraConditions);
}


// ========================================================================
// ?TestEntityDeclFx@idEntityFx@@QAAXPBVidDeclFX@@W4fxCondition_t@@@Z
// EA  : 0x82C49AB8
// RVA : 0x00C49AB8
// PDB : w:\tech5\tungsten\game\entities\entityfx.cpp
// ========================================================================

void __fastcall idEntityFx::TestEntityDeclFx(idEntityFx *this, const idDeclFX *declFx, fxCondition_t startCondition)
{
  idPresentable *presentable; // r11
  __int64 v6; // r10
  idTreeAnimator *v7; // r8
  unsigned int v8; // r4
  idPresentable *v9; // r11
  double v10; // fp31
  idPresentable *v11; // r10
  idPresentable *v12; // r3
  fxEmitterSound_t v13[3]; // [sp+50h] [-40h] BYREF

  presentable = this->presentable;
  this->fxEffect = declFx;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idFXManager::Shutdown(this: &presentable->fxManager);
  if ( this->fxEffect != nullptr )
  {
    v13[0].emitter = idEntity::GetSoundEmitter(this, alloc: true);
    HIDWORD(v6) = 1664525;
    v13[0].channel = SND_CHANNEL_FX;
    v7 = (idTreeAnimator *)&unk_822D0000;
    v8 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v8;
    v9 = this->presentable;
    LODWORD(v6) = (v8 >> 10) & 0x7FFF;
    v13[1] = (fxEmitterSound_t)v6;
    v10 = (float)((float)v6 * (float)0.000030518509);
    if ( v9 != nullptr )
    {
      v11 = v9;
    }
    else
    {
      idEntity::InitPresentableInternal(this);
      v11 = this->presentable;
    }
    idFXManager::Init(
      this: &v11->fxManager,
      declFX: this->fxEffect,
      _rw: clientGame->renderWorld,
      _soundInfo: v13,
      _gameLibEffects: &clientGame->gameLibEffects,
      diversity: v10,
      _ta: v7,
      a8: nullptr);
  }
  v12 = this->presentable;
  if ( v12 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v12 = this->presentable;
  }
  v12->StartFX(this: v12, a2: startCondition, a3: this->extraConditions);
}


// ========================================================================
// ?Spawn@idEntityFx@@QAAXXZ
// EA  : 0x82C49BE8
// RVA : 0x00C49BE8
// PDB : w:\tech5\tungsten\game\entities\entityfx.cpp
// ========================================================================

void __fastcall idEntityFx::Spawn(idEntityFx *this)
{
  idEntityFx_vtbl *v1; // r10
  idPresentable *presentable; // r11
  idVec4 v4; // [sp+50h] [-20h] BYREF

  v1 = this->__vftable;
  this->nextTriggerTime = 0;
  v1->GetColor(this, a2: &v4);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  presentable->fxManager.systemColor = v4;
  if ( this->startOff )
  {
    this->Hide_2(this);
  }
  else
  {
    idEntity::BecomeActive(this, flags: 1);
    this->UpdateModelTransform(this);
    idEntityFx::StartFX(this, condition: this->startCondition);
  }
  idEntity::UpdateVisuals(this);
}


// ========================================================================
// ?Show@idEntityFx@@UAAXXZ
// EA  : 0x82C49CC0
// RVA : 0x00C49CC0
// PDB : w:\tech5\tungsten\game\entities\entityfx.cpp
// ========================================================================

void __fastcall idEntityFx::Show(idEntityFx *this)
{
  if ( !this->startOff )
  {
    idDynamicEntity::Show(this);
    idEntity::BecomeActive(this, flags: 1);
    idEntityFx::StartFX(this, condition: this->startCondition);
  }
}


// ========================================================================
// ?OnActivate@idEntityFx@@UAAXPAVidEntity@@@Z
// EA  : 0x82C49D10
// RVA : 0x00C49D10
// PDB : w:\tech5\tungsten\game\entities\entityfx.cpp
// ========================================================================

void __fastcall idEntityFx::OnActivate(idEntityFx *this, idEntity *activator)
{
  int MaxFadeOutTime; // r5
  idPresentable *presentable; // r11
  fxCondition_t startCondition; // r29
  void (__fastcall *Show)(struct idEntityFx *); // ctr
  bool startOff; // r29
  idGameTimeManager *p_gameTimeManager; // r3
  int v9; // [sp+60h] [-40h]
  const idEventArg *v10; // [sp+68h] [-38h]

  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->nextTriggerTime )
  {
    if ( this->cycleTrigger || (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) != 0 )
    {
      idEventReceiver::CancelEvents(this, ev: &EV_Hide);
      presentable = this->presentable;
      startCondition = this->startCondition;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        presentable = this->presentable;
      }
      idPresentable::StopFX(this: presentable, condition: startCondition, extraCondition: FX_EXTRA_COND_NONE);
      Show = this->Show;
      startOff = this->startOff;
      this->startOff = false;
      Show(this);
      this->startOff = startOff;
    }
    else
    {
      HIBYTE(v9) = 105;
      idEventReceiver::PostEventMS(this, ev: &EV_StopFX, time: v9, arg1: v10);
      MaxFadeOutTime = 0;
      if ( this->fxEffect != nullptr )
        MaxFadeOutTime = idDeclFX::GetMaxFadeOutTime(this: this->fxEffect, startCondition: FX_NONE);
      idEventReceiver::PostEventMS(this, ev: &EV_Hide, time: MaxFadeOutTime);
    }
    p_gameTimeManager = &clientGame->gameTimeManager;
    if ( this->actionDelay == 0.0 )
      this->nextTriggerTime = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED) + 1;
    else
      this->nextTriggerTime = (int)(float)(this->actionDelay * (float)1000.0)
                            + idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
  }
}


// ========================================================================
// ?Event_StartFX@idEntityFx@@AAA?AVeventVoid@@W4fxCondition_t@@@Z
// EA  : 0x82C49E98
// RVA : 0x00C49E98
// PDB : w:\tech5\tungsten\game\entities\entityfx.cpp
// ========================================================================

idEntityFx *__fastcall idEntityFx::Event_StartFX(idEntityFx *this, idEntity *result, fxCondition_t condition)
{
  fxCondition_t v5; // r30
  idPresentable *presentable; // r3

  v5 = condition;
  if ( condition == FX_NONE )
    v5 = *(_DWORD *)&result[1].flags;
  presentable = result->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  presentable->StartFX(this: presentable, a2: v5, a3: (fxExtraCondition_t)result[1].targets.list);
  return this;
}


// ========================================================================
// ?Event_StopFX@idEntityFx@@AAA?AVeventVoid@@W4fxCondition_t@@@Z
// EA  : 0x82C49EF8
// RVA : 0x00C49EF8
// PDB : w:\tech5\tungsten\game\entities\entityfx.cpp
// ========================================================================

idEntityFx *__fastcall idEntityFx::Event_StopFX(idEntityFx *this, idEntity *result, fxCondition_t condition)
{
  fxCondition_t v5; // r30
  idPresentable *presentable; // r3

  v5 = condition;
  if ( condition == FX_NONE )
    v5 = *(_DWORD *)&result[1].flags;
  presentable = result->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  idPresentable::StopFX(this: presentable, condition: v5, extraCondition: FX_EXTRA_COND_NONE);
  return this;
}

