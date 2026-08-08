
// ========================================================================
// ?IsAnimating@idAnimatedInteractable@@UBA_NXZ
// EA  : 0x82BFC1B8
// RVA : 0x00BFC1B8
// PDB : w:\tech5\tungsten\game\entities\animatedinteractable.cpp
// ========================================================================

BOOL __fastcall idAnimatedInteractable::IsAnimating(idAnimatedInteractable *this)
{
  return this->playing;
}


// ========================================================================
// ?IsEverUsable@idAnimatedInteractable@@UBA_NPBVidEntity@@@Z
// EA  : 0x82BFC1C0
// RVA : 0x00BFC1C0
// PDB : w:\tech5\tungsten\game\entities\animatedinteractable.cpp
// ========================================================================

int __fastcall idAnimatedInteractable::IsEverUsable(idAnimatedInteractable *this, const idEntity *activator)
{
  int result; // r3
  int value; // r11

  if ( activator == nullptr || this->playing )
    return 0;
  if ( !this->isOn )
    return 1;
  value = this->offAnim.value;
  result = 0;
  if ( value != 0xFFFF )
    return 1;
  return result;
}


// ========================================================================
// ?GetUsableState@idAnimatedInteractable@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82BFC200
// RVA : 0x00BFC200
// PDB : w:\tech5\tungsten\game\entities\animatedinteractable.cpp
// ========================================================================

int __fastcall idAnimatedInteractable::GetUsableState(
        idAnimatedInteractable *this,
        idPlayer *activator,
        const idFocusTrace *ft)
{
  if ( this->availableJobDecl.len != 0 || this->notAvailableJobDecl.len != 0 )
    return idPlayer::CastTo(c: activator) == nullptr ? 0 : 3;
  else
    return 3;
}


// ========================================================================
// ?ModifyCrosshairInfo@idAnimatedInteractable@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82BFC268
// RVA : 0x00BFC268
// PDB : w:\tech5\tungsten\game\entities\animatedinteractable.cpp
// ========================================================================

int __fastcall idAnimatedInteractable::ModifyCrosshairInfo(
        idAnimatedInteractable *this,
        idPlayer *activator,
        const idFocusTrace *ft,
        const usableState_t usable,
        idCrosshairInfo *info)
{
  idPlayer *v7; // r3
  idPlayer *v8; // r29
  bool v9; // r30
  char v10; // r27
  idJob *InventoryItemByDeclName; // r3
  idJob *v12; // r3

  v7 = idPlayer::CastTo(c: activator);
  v8 = v7;
  if ( v7 == nullptr )
    return 1;
  v9 = true;
  v10 = 1;
  info->text.index = this->displayText.index;
  if ( this->availableJobDecl.len != 0 )
  {
    v9 = false;
    InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(
                                this: &v7->jobManager,
                                jobName: this->availableJobDecl.data);
    if ( InventoryItemByDeclName != nullptr )
      v9 = InventoryItemByDeclName->status >= this->availableJobStatus;
  }
  if ( v9 )
  {
    if ( this->notAvailableJobDecl.len != 0 )
    {
      v10 = 0;
      v12 = idInventoryCollection::FindInventoryItemByDeclName(
              this: &v8->jobManager,
              jobName: this->notAvailableJobDecl.data);
      if ( v12 == nullptr || v12->status < this->notAvailableJobStatus )
        v10 = 1;
    }
    if ( v10 != 0 )
      return 1;
  }
  info->color = idColor::colorRed;
  info->colorState = CROSSHAIR_COLOR_NEGATIVE;
  info->textColorState = CROSSHAIR_TEXT_COLOR_NEGATIVE;
  return 0;
}


// ========================================================================
// ?Think@idAnimatedInteractable@@UAAXXZ
// EA  : 0x82BFC380
// RVA : 0x00BFC380
// PDB : w:\tech5\tungsten\game\entities\animatedinteractable.cpp
// ========================================================================

void __fastcall idAnimatedInteractable::Think(idAnimatedInteractable *this)
{
  idPresentable *presentable; // r3
  int GameMs; // r30
  const idAnimStack *v4; // r3
  idAnimatedInteractable_vtbl *v5; // r9
  char v6; // r8

  if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr )
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    idAnimatedEntity::UpdateFrameCommands(this);
    idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
    if ( this->playing )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v4 = this->GetAnimStack_2(this);
      if ( idAnimator_Channel::IsDone(this: &this->interactableAnimator, stack: v4, curTime: GameMs) )
      {
        v5 = this->__vftable;
        v6 = _cntlzw(this->isOn);
        this->playing = false;
        this->isOn = (v6 & 0x20) != 0;
        v5->Fire(this);
      }
    }
    idEntity::UpdateVisuals(this);
  }
}


// ========================================================================
// ??0idAnimatedInteractable@@QAA@XZ
// EA  : 0x82BFC480
// RVA : 0x00BFC480
// PDB : w:\tech5\tungsten\game\entities\animatedinteractable.cpp
// ========================================================================

idAnimatedInteractable *__fastcall idAnimatedInteractable::idAnimatedInteractable(idAnimatedInteractable *this)
{
  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idAnimatedInteractable_vtbl *)&idAnimatedInteractable::`vftable';
  this->usedByEntity.spawnId.value = 0x1FFF;
  idAnimator_Channel::idAnimator_Channel(this: &this->interactableAnimator);
  this->onAnim.value = -1;
  this->offAnim.value = -1;
  this->availableJobDecl.allocedAndFlag = 20;
  this->availableJobDecl.data = this->availableJobDecl.baseBuffer;
  this->availableJobDecl.len = 0;
  this->availableJobDecl.baseBuffer[0] = 0;
  this->availableJobStatus = JOBSTATUS_ACCEPTED;
  this->notAvailableJobDecl.allocedAndFlag = 20;
  this->notAvailableJobDecl.data = this->notAvailableJobDecl.baseBuffer;
  this->notAvailableJobDecl.len = 0;
  this->notAvailableJobDecl.baseBuffer[0] = 0;
  this->notAvailableJobStatus = JOBSTATUS_COMPLETED;
  this->displayText.index = -1;
  this->isOn = false;
  this->playing = false;
  return this;
}


// ========================================================================
// __unwind$487998_0
// EA  : 0x82BFC56C
// RVA : 0x00BFC56C
// PDB : w:\tech5\tungsten\game\entities\animatedinteractable.cpp
// ========================================================================

void _unwind_487998_0()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?Fire@idAnimatedInteractable@@UAAXXZ
// EA  : 0x82BFC6D8
// RVA : 0x00BFC6D8
// PDB : w:\tech5\tungsten\game\entities\animatedinteractable.cpp
// ========================================================================

void __fastcall idAnimatedInteractable::Fire(idAnimatedInteractable *this)
{
  int value; // r10
  idEntity *v3; // r3
  idEntity *v4; // r4

  value = this->usedByEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v4 = idEntity::CastTo(c: v3);
  }
  else
  {
    v4 = nullptr;
  }
  this->ActivateTargets(this, a2: v4);
  idEntity::BecomeInactive(this, flags: 1);
}


// ========================================================================
// ?Spawn@idAnimatedInteractable@@QAAXXZ
// EA  : 0x82BFC778
// RVA : 0x00BFC778
// PDB : w:\tech5\tungsten\game\entities\animatedinteractable.cpp
// ========================================================================

void __fastcall idAnimatedInteractable::Spawn(idAnimatedInteractable *this)
{
  idPhysics *Physics; // r3
  char *data; // r29
  const idTreeAnimator *TreeAnimatorFromPresentable; // r3
  char *v5; // r29
  const idTreeAnimator *v6; // r3
  idGameTimeManager *v7; // r3
  idAnimatorParms_Base v8; // [sp+50h] [-60h] BYREF

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 131073, a3: -1);
  idEntity::BecomeInactive(this, flags: 1);
  data = this->name.data;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  gameAnimTools->VerifyStrongAliasRefs(
    this: gameAnimTools,
    a2: TreeAnimatorFromPresentable,
    a3: &this->onAnim,
    a4: data);
  v5 = this->name.data;
  v6 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  gameAnimTools->VerifyStrongAliasRefs(this: gameAnimTools, a2: v6, a3: &this->offAnim, a4: v5);
  v8.animStack = this->GetAnimStack_2(this);
  idStr::idStr(this: &v8.name, text: "all");
  memset(&v8.originBlend, 0, 12);
  v8.blendOp = BOP_LERP;
  v8.alpha = 1.0;
  v7 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_Base::Init(this: &this->interactableAnimator, gametimeManager: v7, parms: &v8);
  idEntity::BecomeActive(this, flags: 4);
  idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
  idEntity::BecomeInactive(this, flags: 4);
  idStr::FreeData(this: &v8.name);
}


// ========================================================================
// __unwind$488457_0
// EA  : 0x82BFC8C0
// RVA : 0x00BFC8C0
// PDB : w:\tech5\tungsten\game\entities\animatedinteractable.cpp
// ========================================================================

void _unwind_488457_0()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 176 + 80));
}


// ========================================================================
// ?Use@idAnimatedInteractable@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82BFC8E8
// RVA : 0x00BFC8E8
// PDB : w:\tech5\tungsten\game\entities\animatedinteractable.cpp
// ========================================================================

int __fastcall idAnimatedInteractable::Use(
        idAnimatedInteractable *this,
        idEntity *activator,
        const usableState_t usable)
{
  int result; // r3
  idPresentable *presentable; // r3
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *p_offAnim; // r30
  int GameMs; // r28
  const idAnimStack *v9; // r3
  const blendParms_t *v10; // r7
  const char *v11; // r4
  blendParms_t v12[3]; // [sp+50h] [-40h] BYREF

  if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr )
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    blendParms_t::blendParms_t(this: v12);
    p_offAnim = &this->offAnim;
    if ( !this->isOn )
      p_offAnim = &this->onAnim;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v9 = this->GetAnimStack_2(this);
    if ( (unsigned __int8)idAnimator_Channel::PlayAnim(
                            this: &this->interactableAnimator,
                            stack: v9,
                            ah: p_offAnim,
                            curTime: GameMs,
                            rateScale: 1.0,
                            blendParms: v10,
                            blendOutDurationMS_: v12,
                            leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
                            a9: nullptr) != 0 )
    {
      idEntity::BecomeActive(this, flags: 4);
      idEntity::BecomeActive(this, flags: 1);
      this->playing = true;
      result = 1;
      if ( activator != nullptr )
        this->usedByEntity.spawnId.value = (gameLocal->spawnIds.ptr[activator->entityNumber] << 13)
                                         | activator->entityNumber;
      else
        this->usedByEntity.spawnId.value = 0x1FFF;
    }
    else
    {
      if ( this->isOn )
        v11 = "offAnim";
      else
        v11 = "onAnim";
      idLib::Warning(fmt: "Could not PlayAnim %s in idAnimatedInteractable::Use", v11);
      if ( activator != nullptr )
        this->usedByEntity.spawnId.value = (gameLocal->spawnIds.ptr[activator->entityNumber] << 13)
                                         | activator->entityNumber;
      else
        this->usedByEntity.spawnId.value = 0x1FFF;
      this->Fire(this);
      return 1;
    }
  }
  else
  {
    idLib::Warning(fmt: "Tree Animator is NULL in idAnimatedInteractable::Use");
    return 0;
  }
  return result;
}

