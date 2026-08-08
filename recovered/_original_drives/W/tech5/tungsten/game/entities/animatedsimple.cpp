
// ========================================================================
// ?Hide@idAnimatedSimple@@UAAXXZ
// EA  : 0x82BFCAB0
// RVA : 0x00BFCAB0
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void __fastcall idAnimatedSimple::Hide(idAnimatedSimple *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r3
  idLight *NextTeamEntity; // r31
  idEntity *v5; // r29
  idLight *v6; // r3

  idEntity::Hide(this);
  Physics = idEntity::GetPhysics(this);
  this->physicsContent = Physics->GetContents(this: Physics, a2: -1);
  v3 = idEntity::GetPhysics(this);
  v3->SetContents(this: v3, a2: 0, a3: -1);
  NextTeamEntity = (idLight *)idEntity::GetNextTeamEntity(this);
  if ( NextTeamEntity != nullptr )
  {
    do
    {
      v5 = idEntity::GetNextTeamEntity(this: NextTeamEntity);
      if ( idEntity::GetBindMaster(this: NextTeamEntity) == this )
      {
        NextTeamEntity->Hide_2(this: NextTeamEntity);
        if ( (unsigned __int8)idLight::IsTypeOf(c: NextTeamEntity) != 0 )
        {
          v6 = idLight::CastTo(c: NextTeamEntity);
          idLight::Off(this: v6);
        }
      }
      NextTeamEntity = (idLight *)v5;
    }
    while ( v5 != nullptr );
  }
  idAttachmentCollection::HideAttachments(this: &this->attachments);
}


// ========================================================================
// ?Hide@idAnimatedSimple@@UAAX_N@Z
// EA  : 0x82BFCB88
// RVA : 0x00BFCB88
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void __fastcall idAnimatedSimple::Hide(idAnimatedSimple *this, bool stopFx)
{
  idPhysics *Physics; // r3
  idPhysics *v4; // r3

  idEntity::Hide(this, stopFx);
  Physics = idEntity::GetPhysics(this);
  this->physicsContent = Physics->GetContents(this: Physics, a2: -1);
  v4 = idEntity::GetPhysics(this);
  v4->SetContents(this: v4, a2: 0, a3: -1);
}


// ========================================================================
// ?IsAnimating@idAnimatedSimple@@UBA_NXZ
// EA  : 0x82BFCBF8
// RVA : 0x00BFCBF8
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

BOOL __fastcall idAnimatedSimple::IsAnimating(idAnimatedSimple *this)
{
  int v2; // r30
  const idAnimStack *v3; // r3

  v2 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v3 = this->GetAnimStack(this);
  return (_cntlzw(idAnimator_Channel::IsDone(this: &this->channelAnimator, stack: v3, curTime: v2)) & 0x20) != 0;
}


// ========================================================================
// ?ModifyCrosshairInfo@idAnimatedSimple@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82BFCC78
// RVA : 0x00BFCC78
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

int __fastcall idAnimatedSimple::ModifyCrosshairInfo(
        idAnimatedSimple *this,
        const idEntity *activator,
        const idFocusTrace *ft,
        const usableState_t usable,
        idCrosshairInfo *info)
{
  info->hideCrossHairInfo = true;
  return 1;
}


// ========================================================================
// ?Event_GetAnimState@idAnimatedSimple@@QBA?AVeventInt@@XZ
// EA  : 0x82BFCC88
// RVA : 0x00BFCC88
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

idAnimatedSimple *__fastcall idAnimatedSimple::Event_GetAnimState(idAnimatedSimple *this, eventInt *result)
{
  eventInt::eventInt((eventInt *)this, i: result[1907].value);
  return this;
}


// ========================================================================
// ?Teleport@idAnimatedSimple@@UAAXABVidVec3@@ABVidAngles@@@Z
// EA  : 0x82BFCCC8
// RVA : 0x00BFCCC8
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void __fastcall idAnimatedSimple::Teleport(idAnimatedSimple *this, const idVec3 *origin, idQuat *angles)
{
  idPhysics *Physics; // r3
  idPhysics *v7; // r28
  idPhysics_vtbl *v8; // r31
  idMat3 *v9; // r3
  idPhysics *v10; // r3
  const idBounds *v11; // r3
  idAngles v12; // [sp+50h] [-60h] BYREF
  idAngles v13[6]; // [sp+60h] [-50h] BYREF

  this->orgOrigin = *origin;
  this->orgRotation = *idAngles::ToQuat(this: &v12, result: angles);
  Physics = idEntity::GetPhysics(this);
  Physics->SetOrigin(this: Physics, a2: origin, a3: -1);
  v7 = idEntity::GetPhysics(this);
  v8 = v7->__vftable;
  v9 = idAngles::ToMat3(this: v13, result: (idMat3 *)angles);
  v8->SetAxis(this: v7, a2: v9, a3: -1);
  idEntity::UpdateVisuals(this);
  v10 = idEntity::GetPhysics(this);
  v11 = v10->GetAbsBounds(this: v10, a2: -1);
  idEntity::UpdatePVSAreas(this, bounds: v11);
}


// ========================================================================
// ?UpdateModelTransform@idAnimatedSimple@@UAAXXZ
// EA  : 0x82BFCDB8
// RVA : 0x00BFCDB8
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void __fastcall idAnimatedSimple::UpdateModelTransform(idAnimatedSimple *this)
{
  idEntity::UpdateModelTransform(this);
  if ( (this->thinkFlags & 5) == 0 )
    this->UpdateAttachments(this);
}


// ========================================================================
// ?PostBind@idAnimatedSimple@@UAAXXZ
// EA  : 0x82BFCE10
// RVA : 0x00BFCE10
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void __fastcall idAnimatedSimple::PostBind(idAnimatedSimple *this)
{
  idPhysics *Physics; // r3
  float *v3; // r3
  double v4; // fp0
  idPhysics *v5; // r3
  idQuat *v6; // r3
  idQuat *v7; // r3
  double x; // fp8
  idMat3 var20; // [sp+50h] [-20h] BYREF

  if ( (*((_BYTE *)this + 5292) & 0x40) != 0 )
  {
    Physics = idEntity::GetPhysics(this);
    v3 = (float *)Physics->GetLocalOrigin(this: Physics, a2: 0);
    v4 = *v3;
    this->orgOrigin.x = *v3;
    this->orgOrigin.y = v3[1];
    this->orgOrigin.z = v3[2];
    this->nextOrigin.x = v4;
    this->nextOrigin.y = this->orgOrigin.y;
    this->nextOrigin.z = this->orgOrigin.z;
    v5 = idEntity::GetPhysics(this);
    v6 = (idQuat *)v5->GetLocalAxis(this: v5, a2: 0);
    v7 = idMat3::ToQuat(this: &var20, result: v6);
    x = v7->x;
    this->orgRotation = *v7;
    this->nextRotation.x = x;
    this->nextRotation.y = this->orgRotation.y;
    this->nextRotation.z = this->orgRotation.z;
    this->nextRotation.w = this->orgRotation.w;
  }
}


// ========================================================================
// ?IsEverUsable@idAnimatedSimple@@UBA_NPBVidEntity@@@Z
// EA  : 0x82BFCF08
// RVA : 0x00BFCF08
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

BOOL __fastcall idAnimatedSimple::IsEverUsable(idAnimatedSimple *this, const idEntity *activator)
{
  return this->displayName.index >= 0 || idEntity::IsEverUsable(this, activator);
}


// ========================================================================
// ?AnimEvent_DetachAttachment@idAnimatedSimple@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82BFCF20
// RVA : 0x00BFCF20
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

idAnimatedSimple *__fastcall idAnimatedSimple::AnimEvent_DetachAttachment(
        idAnimatedSimple *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const char *slotName)
{
  int v6; // r3
  int v7; // r11
  int v8; // r8
  int v9; // r9
  int v10; // r10
  int i; // ctr
  idHandle<int,enum invalidAttachment_t,-1> v13; // [sp+50h] [-20h] BYREF

  v6 = idDeclInventory::EquipSlotForName(name: slotName);
  if ( (((v6 >= 0) + ((unsigned int)v6 >= 0xF)) & 1) != 0 )
  {
    v7 = *(_DWORD *)&result[5272];
    v8 = -1;
    v13.value = -1;
    if ( v7 <= 0 )
      goto LABEL_9;
    v9 = *(_DWORD *)&result[5268];
    v10 = 0;
    for ( i = v7; i != 0; --i )
    {
      if ( *(_DWORD *)(v10 + v9 + 112) == v6 )
      {
        v8 = *(_DWORD *)(v10 + v9 + 108);
        v13.value = v8;
      }
      v10 += 116;
    }
    if ( v8 == -1 )
LABEL_9:
      idLib::Warning(fmt: "AnimEvent_ShowAttachment - no attachment for index '%d'.", v6);
    else
      idAttachmentCollection::DetachAttachment(this: (idAttachmentCollection *)&result[5584], handle: &v13);
  }
  else
  {
    idLib::Warning(fmt: "AnimEvent_ShowAttachment - Invalid equip slot", v6);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_ReattachAttachment@idAnimatedSimple@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82BFCFF8
// RVA : 0x00BFCFF8
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

idAnimatedSimple *__fastcall idAnimatedSimple::AnimEvent_ReattachAttachment(
        idAnimatedSimple *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const char *slotName)
{
  int v6; // r3
  int v7; // r11
  int v8; // r8
  int v9; // r9
  int v10; // r10
  int i; // ctr
  idHandle<int,enum invalidAttachment_t,-1> v13; // [sp+50h] [-20h] BYREF

  v6 = idDeclInventory::EquipSlotForName(name: slotName);
  if ( (((v6 >= 0) + ((unsigned int)v6 >= 0xF)) & 1) != 0 )
  {
    v7 = *(_DWORD *)&result[5272];
    v8 = -1;
    v13.value = -1;
    if ( v7 <= 0 )
      goto LABEL_9;
    v9 = *(_DWORD *)&result[5268];
    v10 = 0;
    for ( i = v7; i != 0; --i )
    {
      if ( *(_DWORD *)(v10 + v9 + 112) == v6 )
      {
        v8 = *(_DWORD *)(v10 + v9 + 108);
        v13.value = v8;
      }
      v10 += 116;
    }
    if ( v8 == -1 )
LABEL_9:
      idLib::Warning(fmt: "AnimEvent_ShowAttachment - no attachment for index '%d'.", v6);
    else
      idAttachmentCollection::ReattachAttachment(this: (idAttachmentCollection *)&result[5584], handle: &v13);
  }
  else
  {
    idLib::Warning(fmt: "AnimEvent_ShowAttachment - Invalid equip slot", v6);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_VoiceOver@idAnimatedSimple@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclVoiceOver@@@Z
// EA  : 0x82BFD0D0
// RVA : 0x00BFD0D0
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

idAnimatedSimple *__fastcall idAnimatedSimple::AnimEvent_VoiceOver(
        idAnimatedSimple *this,
        idAI2 *result,
        const idMD6Anim *animHandle,
        const idDeclVoiceOver *vo)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v10; // r29

  if ( vo != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
    presentable = result->presentable;
    v10 = TreeAnimatorFromPresentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: result);
      presentable = result->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    if ( v10 != nullptr )
    {
      idFaceMgr::StartVoiceOver(
        this: (idFaceMgr *)&result->afProperties.isClientAuthoritativeActive,
        owner: result,
        ta: v10,
        vo);
      if ( (result->deferredVisGrid.cells[22] & 0x80) != 0 )
        idFaceMgr::SetEnableLipSyncAnimation(
          this: (idFaceMgr *)&result->afProperties.isClientAuthoritativeActive,
          owner: result,
          enable: true);
    }
    return this;
  }
  else
  {
    idLib::Warning(fmt: "Invalid voice over decl specified for AnimEvent_VoiceOver");
    return this;
  }
}


// ========================================================================
// ?AnimEvent_StartWeaponFX@idAnimatedSimple@@QAA?AVeventVoid@@PBVidMD6Anim@@W4fxCondition_t@@@Z
// EA  : 0x82BFD180
// RVA : 0x00BFD180
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

idAnimatedSimple *__fastcall idAnimatedSimple::AnimEvent_StartWeaponFX(
        idAnimatedSimple *this,
        idEntity *result,
        const idMD6Anim *anim,
        int condition)
{
  idAttachment *v7; // r3
  idFXManager *p_fxManager; // r30
  unsigned int GameMs; // r27
  idPhysics *Physics; // r3
  const idMat3 *v11; // r26
  idPhysics *v12; // r3
  const idVec3 *v13; // r3

  v7 = idAttachmentCollection::ForIndex(this: (idAttachmentCollection *)&result[6].removeNode.next, index: 0);
  if ( v7 != nullptr && v7->presentable != nullptr )
  {
    p_fxManager = &v7->presentable->fxManager;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    Physics = idEntity::GetPhysics(this: result);
    v11 = Physics->GetAxis(this: Physics, a2: 0);
    v12 = idEntity::GetPhysics(this: result);
    v13 = v12->GetOrigin(this: v12, a2: 0);
    idFXManager::StartFX(this: p_fxManager, org: v13, axis: v11, time: GameMs, startCondition: condition, extraCond: 68);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_StopWeaponFX@idAnimatedSimple@@QAA?AVeventVoid@@PBVidMD6Anim@@W4fxCondition_t@@@Z
// EA  : 0x82BFD240
// RVA : 0x00BFD240
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

idAnimatedSimple *__fastcall idAnimatedSimple::AnimEvent_StopWeaponFX(
        idAnimatedSimple *this,
        eventVoid *result,
        const idMD6Anim *anim,
        int condition)
{
  idAttachment *v6; // r3
  idFXManager *p_fxManager; // r31
  int GameMs; // r3

  v6 = idAttachmentCollection::ForIndex(this: (idAttachmentCollection *)&result[5584], index: 0);
  if ( v6 != nullptr && v6->presentable != nullptr )
  {
    p_fxManager = &v6->presentable->fxManager;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idFXManager::StopFX(
      this: p_fxManager,
      time: GameMs,
      stopCondition: condition,
      extraCondition: FX_EXTRA_COND_WEAP_ATTACK_DEFAULT|FX_EXTRA_COND_WEAP_AMMOTYPE_0,
      immediateStop: false);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_HideModel@idAnimatedSimple@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclMD6@@@Z
// EA  : 0x82BFD2B8
// RVA : 0x00BFD2B8
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

idAnimatedSimple *__fastcall idAnimatedSimple::AnimEvent_HideModel(
        idAnimatedSimple *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const idDeclMD6 *model)
{
  if ( model != nullptr )
    idAttachmentCollection::RemoveAttachment(this: (idAttachmentCollection *)&result[5584], modelName: model->name.str);
  return this;
}


// ========================================================================
// ?AnimEvent_ShowModel@idAnimatedSimple@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclMD6@@PBD@Z
// EA  : 0x82BFD2F8
// RVA : 0x00BFD2F8
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

idAnimatedSimple *__fastcall idAnimatedSimple::AnimEvent_ShowModel(
        idAnimatedSimple *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const idDeclMD6 *model,
        const char *tag)
{
  idAttachmentCollection v7; // [sp+50h] [-20h] BYREF

  if ( model != nullptr && tag != nullptr )
    idAttachmentCollection::AddAttachment(
      this: &v7,
      result: (idHandle<int,enum invalidAttachment_t,-1> *)&result[5584],
      modelName: model->name.str,
      propName: nullptr,
      tag,
      tagInfo: nullptr,
      allowDuplicate: false);
  return this;
}


// ========================================================================
// ?AnimEvent_SetSceneModel@idAnimatedSimple@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BFD350
// RVA : 0x00BFD350
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

idAnimatedSimple *__fastcall idAnimatedSimple::AnimEvent_SetSceneModel(
        idAnimatedSimple *this,
        idAnimatedEntity *result,
        const idMD6Anim *animHandle)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idRenderModel **v6; // r3
  idRenderModel *v7; // r3

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    *((_BYTE *)&TreeAnimatorFromPresentable->g + 104) |= 4u;
    if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: result) == 0 )
    {
      v6 = (idRenderModel **)result->GetRenderModelInfo(this: result);
      if ( v6 != nullptr )
      {
        v7 = *v6;
        if ( v7 != nullptr )
          idRenderModel::CommitThisFrame(this: v7);
      }
    }
  }
  return this;
}


// ========================================================================
// ?AnimEvent_ClearSceneModel@idAnimatedSimple@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BFD3E8
// RVA : 0x00BFD3E8
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

idAnimatedSimple *__fastcall idAnimatedSimple::AnimEvent_ClearSceneModel(
        idAnimatedSimple *this,
        idAnimatedEntity *result,
        const idMD6Anim *animHandle)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idRenderModel **v6; // r3
  idRenderModel *v7; // r3

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    *((_BYTE *)&TreeAnimatorFromPresentable->g + 104) &= ~4u;
    if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: result) == 0 )
    {
      v6 = (idRenderModel **)result->GetRenderModelInfo(this: result);
      if ( v6 != nullptr )
      {
        v7 = *v6;
        if ( v7 != nullptr )
          idRenderModel::CommitThisFrame(this: v7);
      }
    }
  }
  return this;
}


// ========================================================================
// ?Event_ShowAttachments@idAnimatedSimple@@QAA?AVeventVoid@@_N@Z
// EA  : 0x82BFD488
// RVA : 0x00BFD488
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

idAnimatedSimple *__fastcall idAnimatedSimple::Event_ShowAttachments(
        idAnimatedSimple *this,
        eventVoid *result,
        bool show)
{
  idAttachmentCollection *v4; // r3

  v4 = (idAttachmentCollection *)&result[5584];
  if ( show )
    idAttachmentCollection::ShowAttachments(this: v4, hideVehicleAttachments: false);
  else
    idAttachmentCollection::HideAttachments(this: v4);
  return this;
}


// ========================================================================
// ?Event_StartVoiceOver@idAnimatedSimple@@QAA?AVeventBool@@PAVidEntity@@PBVidDeclVoiceOver@@_N@Z
// EA  : 0x82BFD4D8
// RVA : 0x00BFD4D8
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

idAnimatedSimple *__fastcall idAnimatedSimple::Event_StartVoiceOver(
        idAnimatedSimple *this,
        idAI2 *result,
        idEntity *talkingTo,
        const idDeclVoiceOver *vo,
        const bool playInCombat)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r5

  if ( vo == nullptr || vo->GetDeclInfo(this: vo) != &idDeclVoiceOver::resourceList )
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idAnimatedSimple::Event_StartVoiceOver",
      decl: vo,
      declInfo: &idDeclVoiceOver::resourceList);
LABEL_9:
    eventBool::eventBool((eventBool *)this, b: false);
    return this;
  }
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  if ( TreeAnimatorFromPresentable == nullptr
    || (unsigned __int8)idFaceMgr::StartVoiceOver(
                          this: (idFaceMgr *)&result->afProperties.isClientAuthoritativeActive,
                          owner: result,
                          ta: TreeAnimatorFromPresentable,
                          vo) == 0 )
  {
    goto LABEL_9;
  }
  if ( (result->deferredVisGrid.cells[22] & 0x80) != 0 )
    idFaceMgr::SetEnableLipSyncAnimation(
      this: (idFaceMgr *)&result->afProperties.isClientAuthoritativeActive,
      owner: result,
      enable: true);
  eventBool::eventBool((eventBool *)this, b: true);
  return this;
}


// ========================================================================
// ?Event_IsVoiceOverPlaying@idAnimatedSimple@@QAA?AVeventBool@@PBVidDeclVoiceOver@@@Z
// EA  : 0x82BFD5B8
// RVA : 0x00BFD5B8
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

idAnimatedSimple *__fastcall idAnimatedSimple::Event_IsVoiceOverPlaying(
        idAnimatedSimple *this,
        eventBool *result,
        const idDeclVoiceOver *vo)
{
  eventBool::eventBool((eventBool *)this, b: (_cntlzw((unsigned int)vo - *(_DWORD *)&result[5692].value) & 0x20) != 0);
  return this;
}


// ========================================================================
// ??0idASDebugGUI@@QAA@XZ
// EA  : 0x82BFD5F8
// RVA : 0x00BFD5F8
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

idASDebugGUI *__fastcall idASDebugGUI::idASDebugGUI(idASDebugGUI *this)
{
  this->guiModel = nullptr;
  this->font = (const idFont *)idResourceList::Load(
                                 this: &idFont::resourceList,
                                 name: "arial_black",
                                 makeDefault: true,
                                 skipStaleCheck: false);
  return this;
}


// ========================================================================
// ??1idASDebugGUI@@QAA@XZ
// EA  : 0x82BFD650
// RVA : 0x00BFD650
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void __fastcall idASDebugGUI::~idASDebugGUI(idAnimationGUI *this)
{
  idRenderModelGui *guiModel; // r3

  guiModel = this->guiModel;
  if ( guiModel != nullptr )
  {
    guiModel->unlinked = true;
    guiModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: guiModel);
  }
  this->font = nullptr;
}


// ========================================================================
// ?Spawn@idAnimatedSimple@@QAAXXZ
// EA  : 0x82BFD6A8
// RVA : 0x00BFD6A8
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void __fastcall idAnimatedSimple::Spawn(idAnimatedSimple *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v5; // r20
  const idDeclMD6 *decl; // r24
  idPhysics *v7; // r3
  unsigned __int8 v8; // r29
  idGameTimeManager *v9; // r3
  idAnimStack *v10; // r3
  const char *v11; // r6
  idAnimStack *v12; // r5
  idGameTimeManager *v13; // r3
  unsigned int facialOptions; // r11
  int modelCaps; // r10
  const char *str; // r26
  bool v17; // r25
  bool v18; // r27
  idGameTimeManager *v19; // r3
  int v20; // r25
  int v21; // r28
  idAnimatedSimple::attachment_t *v22; // r29
  const idDeclEntityDef *entityDef; // r5
  idAnimatedSimple::attachment_t *v24; // r26
  const idAttachment *v25; // r3
  idEntityPtr<idEntity> *p_entity; // r3
  const char *data; // r29
  idEntity *v28; // r3
  idEntity *v29; // r5
  const char *v30; // r6
  idAnimatedSimple::attachment_t *v31; // r29
  const idDeclMD6 *md6; // r10
  const char *v33; // r6
  idAnimatedSimple::attachment_t *v34; // r29
  idAnimatedSimple::attachment_t *v35; // r27
  const idDeclInventory *itemDef; // r5
  const char *v37; // r6
  idAnimatedSimple::attachment_t *v38; // r29
  int v39; // r27
  int v40; // r28
  const idDeclMD6 *v41; // r4
  idAnimatedSimple::animEntry_t *v42; // r29
  double x; // fp0
  double z; // fp11
  double y; // fp10
  idQuat *v46; // r3
  double v47; // fp8
  idPresentable *presentable; // r11
  int v49; // [sp+8h] [-1D8h]
  bool v50; // [sp+Bh] [-1D5h]
  int v51; // [sp+Ch] [-1D4h]
  bool v52; // [sp+Fh] [-1D1h]
  int v53; // [sp+10h] [-1D0h]
  bool v54; // [sp+13h] [-1CDh]
  int v55; // [sp+14h] [-1CCh]
  bool v56; // [sp+17h] [-1C9h]
  int v57; // [sp+18h] [-1C8h]
  int v58; // [sp+18h] [-1C8h]
  int v59; // [sp+1Ch] [-1C4h]
  int v60; // [sp+1Ch] [-1C4h]
  int v61; // [sp+20h] [-1C0h]
  int v62; // [sp+20h] [-1C0h]
  int v63; // [sp+24h] [-1BCh]
  int v64; // [sp+24h] [-1BCh]
  int v65; // [sp+28h] [-1B8h]
  int v66; // [sp+28h] [-1B8h]
  int v67; // [sp+2Ch] [-1B4h]
  int v68; // [sp+2Ch] [-1B4h]
  int v69; // [sp+30h] [-1B0h]
  int v70; // [sp+30h] [-1B0h]
  int v71; // [sp+34h] [-1ACh]
  int v72; // [sp+34h] [-1ACh]
  int v73; // [sp+38h] [-1A8h]
  int v74; // [sp+38h] [-1A8h]
  int v75; // [sp+3Ch] [-1A4h]
  int v76; // [sp+3Ch] [-1A4h]
  int v77; // [sp+40h] [-1A0h]
  int v78; // [sp+40h] [-1A0h]
  int v79; // [sp+44h] [-19Ch]
  int v80; // [sp+44h] [-19Ch]
  int v81; // [sp+48h] [-198h]
  int v82; // [sp+48h] [-198h]
  int v83; // [sp+4Ch] [-194h]
  int v84; // [sp+4Ch] [-194h]
  int v85; // [sp+50h] [-190h]
  int v86; // [sp+50h] [-190h]
  int v87; // [sp+58h] [-188h]
  int v88; // [sp+58h] [-188h]
  int v89; // [sp+60h] [-180h]
  int v90; // [sp+68h] [-178h]
  int num; // [sp+70h] [-170h]
  idAttachmentCollection v92; // [sp+74h] [-16Ch] BYREF
  idAttachmentCollection v93[2]; // [sp+88h] [-158h] BYREF
  int v94; // [sp+B4h] [-12Ch]
  int v95; // [sp+B8h] [-128h]
  int v96; // [sp+BCh] [-124h]
  int v97; // [sp+C0h] [-120h]
  float v98; // [sp+C4h] [-11Ch]
  idAnimatorParms_Base v99; // [sp+D0h] [-110h] BYREF
  idMat3 v100[2]; // [sp+110h] [-D0h] BYREF

  this->attachments.parent = this;
  Physics = idEntity::GetPhysics(this);
  this->physicsContent = Physics->GetContents(this: Physics, a2: -1) | 0x200000;
  v3 = idEntity::GetPhysics(this);
  v3->SetContents(this: v3, a2: this->physicsContent, a3: -1);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  v5 = TreeAnimatorFromPresentable;
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    decl = TreeAnimatorFromPresentable->decl;
    if ( decl != nullptr )
    {
      if ( (*((_BYTE *)this + 5292) & 4) != 0 )
        *((_BYTE *)&TreeAnimatorFromPresentable->g + 104) |= 4u;
      if ( this->clipModelInfo.type <= (unsigned int)CLIPMODEL_CUSTOM
        || this->clipModelInfo.overrideClipMaterial != nullptr )
      {
        v93[0].attachments.size = (int)this->GetAnimStack_2(this);
        idStr::idStr(this: (idStr *)&v93[0].attachments.granularity, text: "base");
        v8 = 1;
        v95 = 0;
        v94 = 1;
        v96 = 0;
        v98 = 0.0;
        v97 = 0;
        v9 = gameLocal->GetGameTimeManager(this: gameLocal);
        idAnimator_Base::Init(
          this: &this->channelAnimator,
          gametimeManager: v9,
          parms: (const idAnimatorParms_Base *)&v93[0].attachments.size);
        v10 = this->GetAnimStack_2(this);
        idAnimatorParms_Pause::idAnimatorParms_Pause(
          this: (idAnimatorParms_Pause *)&v100[0].mat[1].y,
          anim_: nullptr,
          startFrame_: 0.0,
          normalizedStartFrame_: -1.0,
          animStack_: v12,
          name_: v11,
          blendOp_: v10,
          originBlend_: "paused",
          weightGroup_: BOP_LERP,
          filterGroup_: ORIGINBLEND_BRANCH,
          alpha_: 1.0,
          a12: v49,
          a13: v51,
          a14: v53,
          a15: v55,
          a16: v57,
          a17: v59,
          a18: v61,
          a19: v63,
          a20: v65,
          a21: v67,
          a22: v69,
          a23: v71,
          a24: v73,
          a25: v75,
          a26: v77,
          a27: v79,
          a28: v81,
          a29: v83,
          a30: v85,
          a31: MD6_WEIGHTGROUP_ALL,
          a32: v87,
          a33: MD6_WEIGHTGROUP_ALL);
        v13 = gameLocal->GetGameTimeManager(this: gameLocal);
        idAnimator_Base::Init(
          this: &this->pausedAnimator,
          gametimeManager: v13,
          parms: (const idAnimatorParms_Base *)&v100[0].mat[1].y);
        facialOptions = (unsigned __int8)this->facialOptions;
        if ( (facialOptions & 4) != 0 )
        {
          modelCaps = decl->modelCaps;
          str = decl->name.str;
          if ( facialOptions >> 7 == 0 || (v17 = true, (modelCaps & 1) == 0) )
            v17 = false;
          if ( (facialOptions & 0x20) == 0 || (v18 = true, (modelCaps & 2) == 0) )
            v18 = false;
          if ( !v18 || (facialOptions & 0x10) == 0 || (modelCaps & 2) == 0 )
            v8 = 0;
          if ( facialOptions >> 7 != 0 && !v17 )
            idLib::Warning(
              fmt: "idAnimatedSimple '%s' has lipsync enabled but the model '%s' does not support it, disabling",
              this->name.data,
              decl->name.str);
          if ( (*(_BYTE *)&this->facialOptions & 0x20) != 0 && !v18 )
            idLib::Warning(
              fmt: "idAnimatedSimple '%s' has facesetup eyetracking enabled but the model '%s' does not support it, disabling",
              this->name.data,
              str);
          if ( (*(_BYTE *)&this->facialOptions & 0x10) != 0 && v8 == 0 )
            idLib::Warning(
              fmt: "idAnimatedSimple '%s' has blinking enabled but the model '%s' does not support it (require facesetup), disabling",
              this->name.data,
              str);
          idFaceMgr::Init(
            this: &this->faceMgr,
            owner: this,
            ta: v5,
            mood: MOOD_NONE,
            voiceChannel: SND_CHANNEL_VOICE,
            enableMoodAnimation: false,
            enableLipSyncAnimation: v17,
            enableGestureAnimation: false,
            enableEyeTracking: v50,
            useFaceSetupEyeTracking_: v52,
            enableBlinking: v54,
            enableLidDeformation: v56,
            a13: v58,
            a14: v60,
            a15: v62,
            a16: v64,
            a17: v66,
            a18: v68,
            a19: v70,
            a20: v72,
            a21: v74,
            a22: v76,
            a23: v78,
            a24: v80,
            a25: v82,
            a26: v84,
            a27: v86,
            a28: (*(_BYTE *)&this->facialOptions & 0x40) != 0,
            a29: v88,
            a30: v18,
            a31: v89,
            a32: v8,
            a33: v90,
            a34: (*(_BYTE *)&this->facialOptions & 8) != 0);
        }
        if ( (*(_BYTE *)&this->facialOptions & 2) != 0 && (decl->modelCaps & 2) != 0 )
        {
          v99.animStack = this->GetAnimStack_2(this);
          idStr::idStr(this: &v99.name, text: "facetracks");
          v99.alpha = 1.0;
          v99.originBlend = ORIGINBLEND_BRANCH;
          v99.blendOp = BOP_ADD_RIGHT;
          v99.weightGroup = MD6_WEIGHTGROUP_FACE;
          v99.filterGroup = MD6_WEIGHTGROUP_FACE;
          v19 = gameLocal->GetGameTimeManager(this: gameLocal);
          idAnimator_Base::Init(this: &this->faceAnimator, gametimeManager: v19, parms: &v99);
          idStr::FreeData(this: &v99.name);
        }
        if ( (*((_BYTE *)this + 5292) & 0x80) != 0 )
          idTreeAnimator::SetOriginDeltaLookAhead(this: v5, lookAhead: true);
        num = this->startingAttachments.num;
        if ( num != 0 )
        {
          v20 = 0;
          if ( num > 0 )
          {
            v21 = 0;
            do
            {
              v22 = &this->startingAttachments.list[v21];
              if ( v22->tag.len != 0 )
                v22->equipSlot = idDeclInventory::EquipSlotForName(name: v22->tag.data);
              entityDef = v22->entityDef;
              if ( entityDef != nullptr )
              {
                v24 = &this->startingAttachments.list[v21];
                v24->attachHandle = (idHandle<int,enum invalidAttachment_t,-1>)idAttachmentCollection::AddAttachment(
                                                                                 this: v93,
                                                                                 result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
                                                                                 entityDef,
                                                                                 tag: v22->tag.data,
                                                                                 forceReplicationFlags: -1)->value;
                v25 = idAttachmentCollection::Get(
                        this: &this->attachments,
                        handle: &this->startingAttachments.list[v21].attachHandle);
                if ( v25 != nullptr && v25->handle.value != -1 )
                {
                  p_entity = &v25->entity;
                  if ( gameLocal->spawnIds.ptr[p_entity->spawnId.value & 0x1FFF] == p_entity->spawnId.value >> 13
                    && v22->entityName.len != 0 )
                  {
                    data = v22->entityName.data;
                    v28 = idEntityPtr<idEntity const>::operator->(this: p_entity);
                    idEntity::SetName(this: v28, newName: data);
                  }
                }
              }
              else if ( v22->entityName.len != 0 )
              {
                v29 = gameLocal->FindEntity(this: gameLocal, a2: v22->entityName.data);
                if ( v29 != nullptr )
                {
                  v30 = v22->tag.data;
                  v31 = &this->startingAttachments.list[v21];
                  v31->attachHandle = (idHandle<int,enum invalidAttachment_t,-1>)idAttachmentCollection::AddAttachment(
                                                                                   this: (idAttachmentCollection *)&v92.attachments.granularity,
                                                                                   result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
                                                                                   ent: v29,
                                                                                   tag: v30)->value;
                }
                else
                {
                  idLib::Warning(fmt: "Could not find entity '%s' to attach.", v22->entityName.data);
                }
              }
              else
              {
                md6 = v22->md6;
                if ( md6 != nullptr )
                {
                  v33 = v22->tag.data;
                  v34 = &this->startingAttachments.list[v21];
                  v34->attachHandle = (idHandle<int,enum invalidAttachment_t,-1>)idAttachmentCollection::AddAttachment(
                                                                                   this: (idAttachmentCollection *)&v92.parent,
                                                                                   result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
                                                                                   modelName: md6->name.str,
                                                                                   tag: v33)->value;
                }
                else if ( v22->lwoName.len != 0 )
                {
                  v35 = &this->startingAttachments.list[v21];
                  v35->attachHandle = (idHandle<int,enum invalidAttachment_t,-1>)idAttachmentCollection::AddAttachment(
                                                                                   this: (idAttachmentCollection *)&v92.attachments.size,
                                                                                   result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
                                                                                   modelName: v22->lwoName.data,
                                                                                   tag: v22->tag.data)->value;
                }
                else
                {
                  itemDef = v22->itemDef;
                  if ( itemDef != nullptr )
                  {
                    v37 = v22->tag.data;
                    v38 = &this->startingAttachments.list[v21];
                    v38->attachHandle = (idHandle<int,enum invalidAttachment_t,-1>)idAttachmentCollection::AddAttachment(
                                                                                     this: &v92,
                                                                                     result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
                                                                                     decl: itemDef,
                                                                                     tagName: v37,
                                                                                     fxAttachInfo: nullptr)->value;
                  }
                  else
                  {
                    idLib::Warning(fmt: "No valid attachment specified for '%s'", this->name.data);
                  }
                }
              }
              ++v20;
              ++v21;
            }
            while ( v20 < this->startingAttachments.num );
          }
        }
        v39 = 0;
        if ( this->animList.num > 0 )
        {
          v40 = 0;
          do
          {
            if ( idStr::Cmp(s1: this->animList.list[v40].animation.data, s2: &byte_8200D768) != 0 )
            {
              v41 = v5->decl;
              v42 = &this->animList.list[v40];
              v92.attachments.list = (idAttachment *)v42;
              idDeclMD6::StrongLoadAlias(
                this: (idDeclMD6 *)&v92.attachments.num,
                result: v41,
                aliasName: v42->animation.data);
              v42->animationHandle.value = HIWORD(v92.attachments.num);
            }
            ++v39;
            ++v40;
          }
          while ( v39 < this->animList.num );
        }
        x = this->spawnPosition.x;
        this->orgOrigin.x = this->spawnPosition.x;
        this->orgOrigin.y = this->spawnPosition.y;
        z = this->spawnPosition.z;
        v92.attachments.list = (idAttachment *)&this->spawnPosition;
        this->orgOrigin.z = z;
        this->nextOrigin.x = x;
        y = this->orgOrigin.y;
        v92.attachments.list = (idAttachment *)&this->nextOrigin;
        this->nextOrigin.y = y;
        this->nextOrigin.z = this->orgOrigin.z;
        v46 = idMat3::ToQuat(this: v100, result: (idQuat *)&this->spawnOrientation);
        v92.attachments.list = (idAttachment *)&this->nextRotation;
        v47 = v46->x;
        this->orgRotation = *v46;
        this->nextRotation.x = v47;
        this->nextRotation.y = this->orgRotation.y;
        this->nextRotation.z = this->orgRotation.z;
        this->nextRotation.w = this->orgRotation.w;
        idEntity::BecomeActive(this, flags: 1);
        if ( (*((_BYTE *)this + 5292) & 2) != 0 )
        {
          presentable = this->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            presentable = this->presentable;
          }
          presentable->model->useDeferredPosition = false;
        }
        idStr::FreeData(this: (idStr *)&v100[0].mat[1].z);
        idStr::FreeData(this: (idStr *)&v93[0].attachments.granularity);
      }
      else
      {
        idLib::Warning(
          fmt: "idAnimatedSimple '%s' has primitive clipmodel (boundbox/box/cone/cylinder) but doesn't specify overridemateria"
          "l, this is not a valid state. Removing entity.",
          this->name.data);
        v7 = idEntity::GetPhysics(this);
        ((void (__fastcall *)(idPhysics *, _DWORD, double))v7->SetClipModel)(a1: v7, a2: 0, a3: 0.0);
        idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
      }
    }
    else
    {
      idLib::Warning(fmt: "idAnimatedSimple '%s' does not have a valid decl specified", this->name.data);
    }
  }
  else if ( (*((_BYTE *)this + 5292) & 8) == 0 )
  {
    idLib::Warning(fmt: "No MD6 model on func/animatedsimple '%s'", this->name.data);
  }
}


// ========================================================================
// __unwind$490281
// EA  : 0x82BFDE90
// RVA : 0x00BFDE90
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_490281()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 480 + 144));
}


// ========================================================================
// __unwind$490282
// EA  : 0x82BFDEB8
// RVA : 0x00BFDEB8
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_490282()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 480 + 288));
}


// ========================================================================
// __unwind$490283_0
// EA  : 0x82BFDEE0
// RVA : 0x00BFDEE0
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_490283_0()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 480 + 208));
}


// ========================================================================
// ?LeaveState@idAnimatedSimple@@AAAXH@Z
// EA  : 0x82BFDF08
// RVA : 0x00BFDF08
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void __fastcall idAnimatedSimple::LeaveState(idAnimatedSimple *this, const int iState)
{
  idAnimatedSimple::animEntry_t *v3; // r29
  idPhysics *Physics; // r3
  float *v5; // r3
  idPhysics *v6; // r3
  idQuat *v7; // r3
  int v8; // r27
  int v9; // r30
  int value; // r9
  idEntity *v11; // r3
  idEntity *v12; // r31
  idEventArg *v13; // r3
  idMat3 v14[2]; // [sp+50h] [-60h] BYREF

  v3 = &this->animList.list[iState];
  if ( (*((_BYTE *)v3 + 124) & 0x10) != 0 )
  {
    Physics = idEntity::GetPhysics(this);
    v5 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    this->nextOrigin.x = *v5;
    this->nextOrigin.y = v5[1];
    this->nextOrigin.z = v5[2];
    v6 = idEntity::GetPhysics(this);
    v7 = (idQuat *)v6->GetAxis(this: v6, a2: 0);
    this->nextRotation = *idMat3::ToQuat(this: v14, result: v7);
  }
  v8 = 0;
  if ( v3->triggerLeave.num > 0 )
  {
    v9 = 0;
    do
    {
      value = v3->triggerLeave.list[v9].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v11 = gameLocal->entities.ptr[value & 0x1FFF];
        if ( v11 != nullptr )
        {
          v12 = idEntity::CastTo(c: v11);
          if ( v12 != nullptr )
          {
            v13 = idEventArg::idEventArg(this: (idEventArg *)v14, data: this);
            idEventReceiver::PostEventMS(
              this: v12,
              ev: &EV_Activate,
              time: *(_DWORD *)&v13->type,
              arg1: (const idEventArg *)LODWORD(v13->value.v[1]));
          }
        }
      }
      ++v8;
      ++v9;
    }
    while ( v8 < v3->triggerLeave.num );
  }
}


// ========================================================================
// ?PlayAnim@idAnimatedSimple@@QAAXABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@_NH@Z
// EA  : 0x82BFE070
// RVA : 0x00BFE070
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void __fastcall idAnimatedSimple::PlayAnim(
        idAnimatedSimple *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *aliasHandle,
        bool loop,
        unsigned int blendTime)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r23
  idPhysics *v9; // r3
  idQuat *v10; // r3
  idVec3 *p_orgRotation; // r28
  idPhysics *v12; // r3
  float *v13; // r3
  idPhysics *Physics; // r3
  idQuat *v15; // r3
  idPhysics *v16; // r3
  int GameMs; // r30
  const idAnimStack *v18; // r3
  __int64 v19; // r8
  const idAnimStack *v20; // r3
  const idMD6Alias *Alias; // r3
  idResource *Existing; // r3
  int v23; // r10
  idQuat *trackedMemory; // r11
  idQuat *v25; // r11
  float y; // r7
  float z; // r6
  float w; // r5
  int v29; // r11
  idVec3 *v30; // r11
  double x; // fp0
  double v32; // fp13
  double v33; // fp12
  double v34; // fp11
  idQuat *v35; // r3
  double v36; // fp10
  double v37; // fp5
  double v38; // fp3
  double v39; // fp7
  double v40; // fp0
  double v41; // fp13
  double v42; // fp11
  double v43; // fp12
  float v44; // [sp+50h] [-B0h]
  float v45; // [sp+54h] [-ACh]
  idQuat v46; // [sp+60h] [-A0h] BYREF
  idQuat v47; // [sp+70h] [-90h] BYREF
  idMat3 v48[3]; // [sp+80h] [-80h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    if ( (*((_BYTE *)this + 5292) & 0x40) != 0 )
    {
      Physics = idEntity::GetPhysics(this);
      v15 = (idQuat *)Physics->GetLocalAxis(this: Physics, a2: 0);
      p_orgRotation = (idVec3 *)&this->orgRotation;
      this->orgRotation = *idMat3::ToQuat(this: v48, result: v15);
      v16 = idEntity::GetPhysics(this);
      v13 = (float *)v16->GetLocalOrigin(this: v16, a2: 0);
    }
    else
    {
      v9 = idEntity::GetPhysics(this);
      v10 = (idQuat *)v9->GetAxis(this: v9, a2: 0);
      p_orgRotation = (idVec3 *)&this->orgRotation;
      this->orgRotation = *idMat3::ToQuat(this: v48, result: v10);
      v12 = idEntity::GetPhysics(this);
      v13 = (float *)v12->GetOrigin(this: v12, a2: 0);
    }
    this->orgOrigin.x = *v13;
    this->orgOrigin.y = v13[1];
    this->orgOrigin.z = v13[2];
    this->animStartFrame = idAccolade::Count(this: &clientGame->gameTimeManager);
    this->currentLoopCount = 0;
    if ( aliasHandle->value == 0xFFFF )
    {
      idLib::Warning(
        fmt: "idAnimatedSimple '%s - could not find animation alias '%d' in decl '%s",
        this->name.data,
        0xFFFF,
        TreeAnimatorFromPresentable->name.str);
    }
    else
    {
      idEntity::BecomeActive(this, flags: 7);
      blendParms_t::blendParms_t(this: (blendParms_t *)&v48[0].mat[1].y);
      blendParms_t::SetDestStartFrame(this: (blendParms_t *)&v48[0].mat[1].y, frame: 0);
      blendParms_t::SetDuration(this: (blendParms_t *)&v48[0].mat[1].y, frame: 0);
      BYTE1(v48[0].mat[2].z) = 1;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v18 = this->GetAnimStack_2(this);
      if ( !idAnimator_Channel::IsDone(this: &this->channelAnimator, stack: v18, curTime: GameMs) )
        blendParms_t::SetDurationMS(this: (blendParms_t *)&v48[0].mat[1].y, ms: blendTime);
      v20 = this->GetAnimStack_2(this);
      if ( loop )
      {
        LODWORD(v19) = &v48[0].mat[1].y;
        idAnimator_Channel::CycleAnim(
          this: &this->channelAnimator,
          stack: v20,
          ah: aliasHandle,
          curTime: GameMs,
          rateScale: 1.0,
          leafStarted: v19,
          a7: nullptr);
      }
      else
      {
        idAnimator_Channel::PlayAnim(
          this: &this->channelAnimator,
          stack: v20,
          ah: aliasHandle,
          curTime: GameMs,
          rateScale: 1.0,
          blendParms: (const blendParms_t *)HIDWORD(v19),
          blendOutDurationMS_: (blendParms_t *)&v48[0].mat[1].y,
          leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
          a9: nullptr);
      }
      Alias = idDeclMD6::FindAlias(this: TreeAnimatorFromPresentable->decl, aliasHandle, includeInherited: true);
      if ( Alias != nullptr )
      {
        Existing = idResourceList::FindExisting(
                     this: &idMD6Anim::resourceList,
                     name: (char *)Alias->animRefs.list->str,
                     skipStaleCheck: false);
        if ( Existing != nullptr )
        {
          v23 = *((unsigned __int8 *)this + 5292) >> 7;
          if ( v23 != 0
            && (LOWORD((trackedMemory = (idQuat *)Existing[1].trackedMemory)->y) & 0x10) != 0
            && trackedMemory != nullptr )
          {
            v25 = trackedMemory + 5;
          }
          else
          {
            v25 = &quat_identity;
          }
          y = v25->y;
          z = v25->z;
          w = v25->w;
          v48[0].mat[0].x = v25->x;
          v48[0].mat[0].y = y;
          v48[0].mat[0].z = z;
          v48[0].mat[1].x = w;
          if ( v23 != 0 && (*(_WORD *)((v29 = Existing[1].trackedMemory) + 6) & 0xE) != 0 && v29 != 0 )
            v30 = (idVec3 *)(v29 + 112);
          else
            v30 = &vec3_origin;
          x = TreeAnimatorFromPresentable->g.scale.x;
          v32 = TreeAnimatorFromPresentable->g.scale.y;
          v45 = v30->y;
          v44 = v30->x;
          v46.z = TreeAnimatorFromPresentable->g.scale.z * v30->z;
          v46.y = (float)v32 * v45;
          v46.x = (float)x * v44;
          idQuat::operator*(this: &v47, result: p_orgRotation, a: (const idVec3 *)&v46);
          v33 = (float)(this->orgOrigin.y + v47.y);
          v34 = (float)(this->orgOrigin.z + v47.z);
          this->nextOrigin.x = this->orgOrigin.x + v47.x;
          this->nextOrigin.y = v33;
          this->nextOrigin.z = v34;
          v35 = idQuat::Inverse(this: &v46, result: (idQuat *)v48);
          v36 = p_orgRotation->x;
          v37 = v35->x;
          v38 = v35->z;
          v39 = p_orgRotation->z;
          v40 = v35->y;
          v41 = (float)-(float)((float)(v35->y * p_orgRotation->y)
                              - (float)((float)(v35->w * p_orgRotation[1].x) - (float)(v35->x * p_orgRotation->x)));
          v42 = (float)((float)(v35->w * p_orgRotation->z)
                      + (float)((float)(v35->x * p_orgRotation->y) + (float)(v35->z * p_orgRotation[1].x)));
          v43 = (float)((float)(v35->y * p_orgRotation[1].x)
                      + (float)((float)(v35->w * p_orgRotation->y) + (float)(v35->z * p_orgRotation->x)));
          this->nextRotation.x = -(float)((float)(v35->z * p_orgRotation->y)
                                        - (float)((float)(v35->y * p_orgRotation->z)
                                                + (float)((float)(v35->x * p_orgRotation[1].x)
                                                        + (float)(v35->w * p_orgRotation->x))));
          this->nextRotation.w = -(float)((float)((float)v38 * (float)v39) - (float)v41);
          this->nextRotation.z = -(float)((float)((float)v40 * (float)v36) - (float)v42);
          this->nextRotation.y = -(float)((float)((float)v37 * (float)v39) - (float)v43);
        }
      }
    }
  }
}


// ========================================================================
// ?PlayAnim@idAnimatedSimple@@QAAXABVidAnimAliasRef@@_NH@Z
// EA  : 0x82BFE4C0
// RVA : 0x00BFE4C0
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void __fastcall idAnimatedSimple::PlayAnim(
        idAnimatedSimple *this,
        const idAnimAliasRef *anim,
        bool loop,
        unsigned int blendTime)
{
  int num; // r11
  int v9; // r29
  int v10; // r30
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v11; // [sp+50h] [-40h] BYREF

  num = this->animList.num;
  v11.value = -1;
  v9 = 0;
  if ( num > 0 )
  {
    v10 = 0;
    while ( idStr::Cmp(s1: this->animList.list[v10].animation.data, s2: anim->data) != 0 )
    {
      ++v9;
      ++v10;
      if ( v9 >= this->animList.num )
        goto LABEL_7;
    }
    v11.value = this->animList.list[v9].animationHandle.value;
  }
LABEL_7:
  idAnimatedSimple::PlayAnim(this, aliasHandle: &v11, loop, blendTime);
}


// ========================================================================
// ?Event_PlayAnim@idAnimatedSimple@@QAA?AVeventVoid@@PBD_NH@Z
// EA  : 0x82BFE558
// RVA : 0x00BFE558
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

idAnimatedSimple *__fastcall idAnimatedSimple::Event_PlayAnim(
        idAnimatedSimple *this,
        idAnimatedSimple *result,
        const char *animName,
        bool loop,
        unsigned int blendTime)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v12[32]; // [sp+50h] [-40h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    idDeclMD6::FindAliasHandle(this: (idDeclMD6 *)v12, result: TreeAnimatorFromPresentable->decl, aliasName: animName);
    idAnimatedSimple::PlayAnim(this: result, aliasHandle: v12, loop, blendTime);
  }
  else
  {
    idLib::Warning(fmt: "Invalid MD6 model on func/animatedsimple '%s'", result->name.data);
  }
  return this;
}


// ========================================================================
// ?Damage@idAnimatedSimple@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82BFE5D8
// RVA : 0x00BFE5D8
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

float __fastcall idAnimatedSimple::Damage(
        idAnimatedSimple *this,
        idEntity *inflictor,
        idAnimatedSimple *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace)
{
  idEntityPtr<idEntity> *p_onIgnoredDamageTrigger; // r29
  idAnimatedSimple *v10; // r4
  idEventArg *v11; // r3
  char *v12; // r10
  _DWORD *v13; // r11
  int i; // ctr
  idEntity *v15; // r3
  double v16; // fp1
  double v17; // fp1
  int health; // r11
  double v19; // fp31
  int len; // r11
  idEntity *v21; // r3
  char v23; // [sp+6Ch] [-1B4h] BYREF
  __int64 v24; // [sp+78h] [-1A8h]
  idEventArg v25; // [sp+90h] [-190h] BYREF
  idScriptFunction v26; // [sp+B0h] [-170h] BYREF

  if ( !this->hitDetectionOptions.shouldGetHit || this->hitDetectionOptions.hasBeenKilled )
  {
LABEL_10:
    v16 = 0.0;
    return *((float *)&v16 + 1);
  }
  if ( (damageDef->damageTypes & ~this->hitDetectionOptions.ignoreDamageTypes) == 0 )
  {
    p_onIgnoredDamageTrigger = &this->hitDetectionOptions.onIgnoredDamageTrigger;
    if ( idEntityPtr<idEntity const>::operator->(this: &this->hitDetectionOptions.onIgnoredDamageTrigger) != nullptr )
    {
      v10 = this;
      if ( attacker != nullptr )
        v10 = attacker;
      v11 = idEventArg::idEventArg(this: &v25, data: v10);
      v12 = &v23;
      v13 = (_DWORD *)&v11[-1].value.q[3];
      for ( i = 5; i != 0; --i )
      {
        ++v13;
        v12 += 4;
        *(_DWORD *)v12 = *v13;
      }
      v15 = idEntityPtr<idEntity const>::operator->(this: p_onIgnoredDamageTrigger);
      idEventReceiver::PostEventMS(this: v15, ev: &EV_Activate, time: 0, arg1: (const idEventArg *)HIDWORD(v24));
    }
    goto LABEL_10;
  }
  v17 = idDeclDamage::DamageAmount(this: damageDef);
  health = this->hitDetectionOptions.health;
  v19 = v17;
  this->hitDetectionOptions.health = health - (int)v17;
  if ( health - (int)v17 <= 0 )
  {
    len = this->hitDetectionOptions.callWhenDead.len;
    this->hitDetectionOptions.hasBeenKilled = true;
    if ( len != 0 )
    {
      idScriptFunction::idScriptFunction(this: &v26);
      idScriptFunction::SetFunction(
        this: &v26,
        ent: this,
        functionName: this->hitDetectionOptions.callWhenDead.data,
        returnType: ev_void,
        numParms: 2,
        8,
        "activatedEntity",
        8);
      idScriptFunction::SetArg_Entity(this: &v26, argNum: 0, ent: this);
      idScriptFunction::SetArg_Entity(this: &v26, argNum: 1, ent: attacker);
      idScriptFunction::CallFunction(this: &v26, defer: true);
    }
    if ( idEntityPtr<idEntity const>::operator->(this: &this->hitDetectionOptions.callTargetWhenDead) != nullptr )
    {
      v21 = idEntityPtr<idEntity const>::operator->(this: &this->hitDetectionOptions.callTargetWhenDead);
      idEntity::Activate(this: v21, activator: this);
    }
  }
  v16 = v19;
  return *((float *)&v16 + 1);
}


// ========================================================================
// ?PauseCurrentAnim@idAnimatedSimple@@QAAX_NH0@Z
// EA  : 0x82BFE778
// RVA : 0x00BFE778
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void __fastcall idAnimatedSimple::PauseCurrentAnim(
        idAnimatedSimple *this,
        const bool pause,
        int pauseFrame,
        const bool queuePause_)
{
  idAnimator_Channel *p_channelAnimator; // r26
  idMD6LeafPlay *LastPlayedLeaf; // r3
  idMD6LeafPlay *v9; // r30
  const idMD6Anim *anim; // r27
  signed int v11; // r29
  int GameMs; // r3
  __int64 v13; // r10
  int v14; // r8
  int v15; // r7
  int v16; // r6
  int Frame; // r29
  idMD6Leaf::wrapMode_t v18; // r5
  int animData; // r11
  __int64 v20; // r11
  int currentState; // r11
  double timeScale; // fp31
  const idMD6Anim *v23; // r30
  int v24; // r28
  idGameTimeManager *p_gameTimeManager; // r3
  int v26; // r28
  const idAnimStack *v27; // r3
  __int64 v28; // r8
  idMD6Leaf::wrapMode_t v29; // r5
  int v30; // r28
  const idAnimStack *v31; // r3
  const blendParms_t *v32; // r7
  blendParms_t v33; // [sp+60h] [-60h] BYREF

  if ( pause )
  {
    p_channelAnimator = &this->channelAnimator;
    LastPlayedLeaf = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
    v9 = LastPlayedLeaf;
    if ( LastPlayedLeaf != nullptr )
    {
      anim = LastPlayedLeaf->anim;
      if ( anim != nullptr )
      {
        this->wasLooping = (_cntlzw(LastPlayedLeaf->wrapMode - 1) & 0x20) != 0;
        v11 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        Frame = (unsigned __int16)idMD6LeafPlay::GetFrame(
                                    this: v9,
                                    gameTime: GameMs,
                                    ticksPerSec: v11,
                                    a4: v16,
                                    a5: v15,
                                    a6: v14,
                                    a7: v13);
        if ( pauseFrame != -1 )
        {
          animData = (int)anim->animData;
          if ( animData != 0 )
            animData = *(unsigned __int16 *)(animData + 8);
          if ( pauseFrame < animData )
          {
            if ( queuePause_ && (Frame < pauseFrame || this->wasLooping) )
            {
              this->queuePauseFrame = pauseFrame;
              this->queuePause = true;
              return;
            }
            Frame = pauseFrame;
          }
        }
        idAnimator_Paused::SetAnim(this: &this->pausedAnimator, anim_: anim, a3: v18);
        LODWORD(v20) = Frame;
        idAnimator_Paused::SetFrame(this: &this->pausedAnimator, frame: (float)v20);
        idAnimator_Channel::ClearAnimator(this: p_channelAnimator);
        this->isPaused = true;
      }
    }
  }
  else
  {
    currentState = this->currentState;
    timeScale = 1.0;
    if ( currentState != -1 )
      timeScale = this->animList.list[currentState].timeScale;
    v23 = idFile_Stat::Timestamp(this: &this->pausedAnimator);
    if ( v23 != nullptr )
    {
      v24 = (int)idAnimator_Paused::GetFrame(this: &this->pausedAnimator);
      blendParms_t::blendParms_t(this: &v33);
      blendParms_t::SetDestStartFrame(this: &v33, frame: v24);
      p_gameTimeManager = &clientGame->gameTimeManager;
      if ( this->wasLooping )
      {
        v26 = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
        v27 = this->GetAnimStack_2(this);
        LODWORD(v28) = &v33;
        idAnimator_Channel::CycleAnim(
          this: &this->channelAnimator,
          stack: v27,
          ah: v23,
          curTime: v26,
          rateScale: timeScale,
          leafStarted: v28,
          a7: nullptr);
      }
      else
      {
        v30 = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
        v31 = this->GetAnimStack_2(this);
        idAnimator_Channel::PlayAnim(
          this: &this->channelAnimator,
          stack: v31,
          ah: v23,
          curTime: v30,
          rateScale: timeScale,
          blendParms: v32,
          blendOutDurationMS_: &v33,
          leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
          a9: nullptr);
      }
      this->isPaused = false;
      idAnimator_Paused::SetAnim(this: &this->pausedAnimator, anim_: nullptr, a3: v29);
      idEntity::BecomeActive(this, flags: 7);
    }
  }
}


// ========================================================================
// ?SetExternalTime@idAnimatedSimple@@QAAXM@Z
// EA  : 0x82BFE9F0
// RVA : 0x00BFE9F0
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void __fastcall idAnimatedSimple::SetExternalTime(idAnimatedSimple *this, double normalizedTime)
{
  int currentState; // r11
  double v3; // fp31
  __int64 v4; // r6
  idMD6LeafPlay *LastPlayedLeaf; // r3
  idMD6LeafPlay *v6; // r31
  double v7; // fp0
  int v8; // r30
  int GameMs; // r3
  __int64 v10; // [sp+50h] [-30h]

  currentState = this->currentState;
  v3 = normalizedTime;
  if ( currentState != -1 && (*((_BYTE *)&this->animList.list[currentState] + 124) & 2) != 0 )
  {
    this->externalTime = normalizedTime;
    LastPlayedLeaf = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
    v6 = LastPlayedLeaf;
    if ( LastPlayedLeaf != nullptr )
    {
      v7 = 0.0;
      if ( v3 < 0.0 || (v7 = 0.99000001, v3 > 0.99000001) )
        v3 = v7;
      LODWORD(v4) = LastPlayedLeaf->anim->animData->numFrames - 1;
      v10 = v4;
      v8 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idMD6LeafPlay::SetFloatFrame(
        this: v6,
        gameTime: GameMs,
        ticksPerSec: v8,
        targetFrame: (float)((float)v10 * (float)v3));
    }
  }
}


// ========================================================================
// ?Event_PauseAnim@idAnimatedSimple@@QAA?AVeventVoid@@_NH0@Z
// EA  : 0x82BFEAF0
// RVA : 0x00BFEAF0
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

idAnimatedSimple *__fastcall idAnimatedSimple::Event_PauseAnim(
        idAnimatedSimple *this,
        idAnimatedSimple *result,
        bool pause,
        int pauseFrame,
        bool queuePause)
{
  idAnimatedSimple::PauseCurrentAnim(this: result, pause, pauseFrame, queuePause_: queuePause);
  return this;
}


// ========================================================================
// ?DrawDebugGUI@idASDebugGUI@@QAAPAVidRenderModelGui@@XZ
// EA  : 0x82BFEB38
// RVA : 0x00BFEB38
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

idRenderModelGui *__fastcall idASDebugGUI::DrawDebugGUI(idASDebugGUI *this)
{
  idPlayer *Player; // r3
  idAnimatedSimple *FocusEntity; // r3
  int v4; // r7
  unsigned __int64 v5; // r6
  idAnimatedSimple *v6; // r3
  idAnimatedSimple *v7; // r29
  idRenderModelGui *v8; // r3
  idRenderModelGui *v9; // r3
  unsigned int v10; // r27
  unsigned int v11; // r3
  const unsigned __int8 *LocalizedString; // r29
  double v13; // fp29
  __int64 v14; // r4
  double v15; // fp28
  __int64 v16; // r11
  double v17; // fp29
  __int64 v18; // r10
  double v19; // fp30
  int v20; // r6
  const char *v21; // r5
  const idVec4 *v22; // r4
  const char *v23; // r5
  const idVec4 *v24; // r4
  idStrId v26; // [sp+58h] [-568h] BYREF
  idDeviceContext v27; // [sp+60h] [-560h] BYREF

  Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
  if ( Player == nullptr )
    return nullptr;
  FocusEntity = (idAnimatedSimple *)idPlayer::GetFocusEntity(this: Player);
  v6 = idAnimatedSimple::CastTo(c: FocusEntity);
  v7 = v6;
  if ( v6 == nullptr || v6->displayName.index < 0 )
    return nullptr;
  if ( this->guiModel == nullptr )
  {
    v8 = (idRenderModelGui *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0xA410u,
                               tag: TAG_GUI_MODEL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    v9 = v8 != nullptr ? idRenderModelGui::idRenderModelGui(this: v8) : nullptr;
    this->guiModel = v9;
    if ( v9 == nullptr )
      return nullptr;
  }
  if ( this->font == nullptr )
    return nullptr;
  idRenderModelGui::Clear(
    this: (idRenderModelGui *)HIDWORD(defaultExtraGLState),
    a2: defaultExtraGLState,
    bits: v5,
    a4: v4);
  v10 = renderSystem->GetHeight(this: renderSystem);
  v11 = renderSystem->GetWidth(this: renderSystem);
  idRenderModelGui::SetViewport(this: this->guiModel, x: 0, y: 0, width: v11, height: v10);
  idDeviceContext::idDeviceContext(this: &v27, guiModel: this->guiModel);
  idDeviceContext::SetFont(this: &v27, font: this->font);
  v26.index = v7->displayName.index;
  LocalizedString = (const unsigned __int8 *)idStrId::GetLocalizedString(this: &v26);
  v13 = (float)((float)__SPAIR64__(&off_82350000, renderSystem->GetWidth(this: renderSystem)) - 128.0);
  v14 = ((__int64 (*)(void))renderSystem->GetHeight)();
  v15 = (float)((float)__SPAIR64__(&unk_82150000, HIDWORD(v14)) - (float)128.0);
  LODWORD(v16) = idDeviceContext::TextWidth(
                   this: &v27,
                   scale: 0.40000001,
                   text: (const char *)v14,
                   limit: LocalizedString,
                   a5: -1);
  v17 = (float)-(float)((float)((float)v16 * (float)0.5) - (float)((float)((float)v13 * (float)0.5) + (float)64.0));
  LODWORD(v18) = idDeviceContext::TextHeight(this: &v27, scale: 0.40000001);
  v19 = (float)((float)((float)((float)v15 + (float)64.0) - (float)64.0) - (float)v18);
  idDeviceContext::DrawTextA(
    this: &v27,
    x: (float)((float)v17 + (float)4.0),
    y: (float)((float)((float)((float)((float)v15 + (float)64.0) - (float)64.0) - (float)v18) + (float)4.0),
    scale: 0.40000001,
    color: v22,
    text: v21,
    a7: v20,
    a8: (const idVec4 *)&idColor::colorBlack,
    a9: LocalizedString);
  idDeviceContext::DrawTextA(
    this: &v27,
    x: v17,
    y: v19,
    scale: 0.40000001,
    color: v24,
    text: v23,
    a7: (int)&aAvSsobjectVCom[20],
    a8: (const idVec4 *)&idColor::colorWhite,
    a9: LocalizedString);
  return this->guiModel;
}


// ========================================================================
// __unwind$491698
// EA  : 0x82BFEDB8
// RVA : 0x00BFEDB8
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_491698()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1472 + 80), tag: TAG_GUI_MODEL);
}


// ========================================================================
// ?EnterState@idAnimatedSimple@@AAAXHH_N@Z
// EA  : 0x82BFEDE8
// RVA : 0x00BFEDE8
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void __fastcall idAnimatedSimple::EnterState(
        idAnimatedSimple *this,
        int iState,
        unsigned int blendTime,
        const bool checkPoint)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r22
  idAnimatedSimple::animEntry_t *list; // r10
  unsigned __int16 *p_value; // r27
  int v11; // r28
  int v12; // r29
  int v13; // r9
  idEntity *v14; // r3
  idEntity *v15; // r30
  idEventArg *v16; // r3
  const idMD6Alias *Alias; // r3
  float *Existing; // r3
  float *v19; // r24
  char v20; // r30
  idPresentable *presentable; // r11
  idEntity *v22; // r3
  idEntity *v23; // r3
  idPhysics *Physics; // r3
  float *v25; // r3
  idGameLocal *v26; // r10
  int v27; // r9
  idEntity *v28; // r3
  idEntity *v29; // r3
  idPhysics *v30; // r3
  idQuat *v31; // r3
  idVec3 *p_orgOrigin; // r29
  idQuat *p_orgRotation; // r30
  idPhysics *v34; // r3
  double v35; // fp3
  double v36; // fp5
  double v37; // fp13
  double v38; // fp12
  double v39; // fp1
  double v40; // fp2
  double v41; // fp3
  double v42; // fp0
  idQuat *v43; // r3
  double x; // fp11
  double v45; // fp6
  double z; // fp9
  double y; // fp8
  double v48; // fp1
  double v49; // fp0
  double v50; // fp13
  double v51; // fp12
  idPhysics *v52; // r3
  idPhysics *v53; // r30
  idPhysics_vtbl *v54; // r29
  idMat3 *v55; // r3
  idPhysics *v56; // r3
  idPhysics *v57; // r30
  idPhysics_vtbl *v58; // r29
  idMat3 *v59; // r3
  idTreeAnimator *v60; // r3
  unsigned int v61; // r4
  int GameMs; // r30
  double v63; // fp31
  idAnimStack *(__fastcall *GetAnimStack_2)(struct idAnimatedSimple *); // ctr
  const idAnimStack *v65; // r3
  __int64 v66; // r8
  const idAnimStack *v67; // r3
  const blendParms_t *v68; // r7
  int v69; // r10
  idQuat *v70; // r11
  idQuat *v71; // r11
  float v72; // r7
  float v73; // r6
  float w; // r5
  int v75; // r11
  idVec3 *v76; // r11
  double v77; // fp0
  double v78; // fp13
  double v79; // fp12
  double v80; // fp11
  idQuat *v81; // r3
  double v82; // fp5
  double v83; // fp10
  double v84; // fp3
  double v85; // fp7
  double v86; // fp0
  double v87; // fp1
  double v88; // fp11
  double v89; // fp12
  bool v90; // r4
  bool v91; // r4
  int v92; // r11
  float v93; // [sp+50h] [-160h]
  float v94; // [sp+54h] [-15Ch]
  idQuat v95; // [sp+60h] [-150h] BYREF
  float v96[4]; // [sp+70h] [-140h] BYREF
  idQuat v97; // [sp+80h] [-130h] BYREF
  blendParms_t v98; // [sp+90h] [-120h] BYREF
  idQuat v99; // [sp+B0h] [-100h] BYREF
  float v100; // [sp+C0h] [-F0h]
  float v101; // [sp+C4h] [-ECh]
  float v102; // [sp+C8h] [-E8h]
  float v103; // [sp+CCh] [-E4h]
  float v104; // [sp+D0h] [-E0h]
  float v105; // [sp+E0h] [-D0h] BYREF
  float v106; // [sp+E4h] [-CCh]
  float v107; // [sp+E8h] [-C8h]
  float v108; // [sp+ECh] [-C4h]
  float v109; // [sp+F0h] [-C0h]
  float v110; // [sp+F4h] [-BCh]
  float v111; // [sp+F8h] [-B8h]
  float v112; // [sp+FCh] [-B4h]
  float v113; // [sp+100h] [-B0h]
  idMat3 v114; // [sp+110h] [-A0h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    list = this->animList.list;
    this->currentState = iState;
    p_value = &list[iState].animationHandle.value;
    this->hasCheckedDefault = true;
    this->currentLoopCount = 0;
    v11 = 0;
    if ( *((int *)p_value + 11) > 0 )
    {
      v12 = 0;
      do
      {
        v13 = *(_DWORD *)(v12 + *((_DWORD *)p_value + 10));
        if ( gameLocal->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13 )
        {
          v14 = gameLocal->entities.ptr[v13 & 0x1FFF];
          if ( v14 != nullptr )
          {
            v15 = idEntity::CastTo(c: v14);
            if ( v15 != nullptr )
            {
              v16 = idEventArg::idEventArg(this: (idEventArg *)&v114, data: this);
              idEventReceiver::PostEventMS(
                this: v15,
                ev: &EV_Activate,
                time: *(_DWORD *)&v16->type,
                arg1: (const idEventArg *)LODWORD(v16->value.v[1]));
            }
          }
        }
        ++v11;
        v12 += 4;
      }
      while ( v11 < *((_DWORD *)p_value + 11) );
    }
    Alias = idDeclMD6::FindAlias(
              this: TreeAnimatorFromPresentable->decl,
              aliasHandle: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)p_value,
              includeInherited: true);
    if ( Alias != nullptr )
    {
      Existing = (float *)idResourceList::FindExisting(
                            this: &idMD6Anim::resourceList,
                            name: (char *)Alias->animRefs.list->str,
                            skipStaleCheck: false);
      v19 = Existing;
      if ( Existing != nullptr )
      {
        if ( (p_value[62] & 4) != 0 )
        {
          TreeAnimatorFromPresentable->g.scale.x = Existing[29];
          TreeAnimatorFromPresentable->g.scale.y = Existing[30];
          TreeAnimatorFromPresentable->g.scale.z = Existing[31];
        }
        if ( (*((_BYTE *)this + 5292) & 0x80) != 0 )
        {
          if ( (*((_BYTE *)this + 5292) & 2) != 0 || (v20 = 1, (p_value[62] & 0x10) == 0) )
            v20 = 0;
          presentable = this->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            presentable = this->presentable;
          }
          presentable->model->useDeferredPosition = v20;
        }
        this->animStartFrame = idAccolade::Count(this: &clientGame->gameTimeManager);
        if ( gameLocal->spawnIds.ptr[*((_DWORD *)p_value + 9) & 0x1FFF] == *((int *)p_value + 9) >> 13 )
        {
          v22 = gameLocal->entities.ptr[*((_DWORD *)p_value + 9) & 0x1FFF];
          if ( v22 != nullptr )
            v23 = idEntity::CastTo(c: v22);
          else
            v23 = nullptr;
          Physics = idEntity::GetPhysics(this: v23);
          v25 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
          v26 = gameLocal;
          this->orgOrigin.x = *v25;
          this->orgOrigin.y = v25[1];
          this->orgOrigin.z = v25[2];
          v27 = *((_DWORD *)p_value + 9);
          if ( v26->spawnIds.ptr[v27 & 0x1FFF] == v27 >> 13 && (v28 = v26->entities.ptr[v27 & 0x1FFF]) != nullptr )
            v29 = idEntity::CastTo(c: v28);
          else
            v29 = nullptr;
          v30 = idEntity::GetPhysics(this: v29);
          v31 = (idQuat *)v30->GetAxis(this: v30, a2: 0);
          this->orgRotation = *idMat3::ToQuat(this: &v114, result: v31);
        }
        else if ( (p_value[62] & 0x40) != 0 )
        {
          this->orgOrigin.x = v19[23];
          p_orgOrigin = &this->orgOrigin;
          this->orgOrigin.y = v19[24];
          this->orgOrigin.z = v19[25];
          this->orgRotation = *idAngles::ToQuat(this: (idAngles *)&v114, result: (idQuat *)(v19 + 26));
          p_orgRotation = &this->orgRotation;
          if ( (*((_BYTE *)this + 5292) & 0x40) != 0 )
          {
            v34 = idEntity::GetPhysics(this);
            v34->callbacks->GetMasterPosition(this: v34->callbacks, a2: (idVec3 *)v96, a3: (idMat3 *)&v105);
            v35 = (float)(this->orgOrigin.z - v96[2]);
            v36 = (float)(this->orgOrigin.y - v96[1]);
            v102 = v107;
            v103 = v110;
            v104 = v113;
            v37 = v108;
            v38 = v111;
            v99.x = v105;
            v99.y = v108;
            v99.z = v111;
            v39 = (float)(p_orgOrigin->x - v96[0]);
            v99.w = v106;
            v100 = v109;
            v40 = (float)((float)(v112 * (float)v36) + (float)(v113 * (float)v35));
            v101 = v112;
            v42 = (float)((float)(v105 * (float)v39) + (float)((float)(v106 * (float)v36) + (float)(v107 * (float)v35)));
            v41 = (float)((float)(v109 * (float)v36) + (float)(v110 * (float)v35));
            p_orgOrigin->x = v42;
            this->orgOrigin.z = (float)((float)v38 * (float)v39) + (float)v40;
            this->orgOrigin.y = (float)((float)v37 * (float)v39) + (float)v41;
            v43 = idMat3::ToQuat(this: &v114, result: &v99);
            x = p_orgRotation->x;
            v45 = v43->x;
            z = this->orgRotation.z;
            y = this->orgRotation.y;
            v48 = v43->z;
            v49 = (float)-(float)((float)(v43->y * this->orgRotation.y)
                                - (float)((float)(v43->w * this->orgRotation.w) - (float)(v43->x * this->orgRotation.x)));
            v50 = (float)((float)(v43->w * this->orgRotation.y)
                        + (float)((float)(v43->x * this->orgRotation.z) + (float)(v43->y * this->orgRotation.w)));
            v51 = (float)((float)(v43->z * this->orgRotation.w)
                        + (float)((float)(v43->w * this->orgRotation.z) + (float)(v43->y * this->orgRotation.x)));
            p_orgRotation->x = -(float)((float)(v43->y * p_orgRotation->z)
                                      - (float)((float)(v43->z * p_orgRotation->y)
                                              + (float)((float)(v43->x * p_orgRotation->w)
                                                      + (float)(v43->w * p_orgRotation->x))));
            this->orgRotation.w = -(float)((float)((float)v48 * (float)z) - (float)v49);
            this->orgRotation.y = -(float)((float)((float)v48 * (float)x) - (float)v50);
            this->orgRotation.z = -(float)((float)((float)v45 * (float)y) - (float)v51);
          }
        }
        if ( (*((_BYTE *)this + 5292) & 0x80) != 0 )
        {
          if ( (*((_BYTE *)this + 5292) & 0x40) != 0 )
          {
            v56 = idEntity::GetPhysics(this);
            v56->SetLocalOrigin(this: v56, a2: &this->orgOrigin, a3: -1);
            v57 = idEntity::GetPhysics(this);
            v58 = v57->__vftable;
            v59 = idQuat::ToMat3(this: (idQuat *)&v114, result: (idMat3 *)&this->orgRotation);
            v58->SetLocalAxis(this: v57, a2: v59, a3: -1);
          }
          else
          {
            v52 = idEntity::GetPhysics(this);
            v52->SetOrigin(this: v52, a2: &this->orgOrigin, a3: -1);
            v53 = idEntity::GetPhysics(this);
            v54 = v53->__vftable;
            v55 = idQuat::ToMat3(this: (idQuat *)&v114, result: (idMat3 *)&this->orgRotation);
            v54->SetAxis(this: v53, a2: v55, a3: -1);
          }
        }
        if ( *p_value == 0xFFFF )
        {
          v60 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
          idLib::Warning(
            fmt: "idAnimatedSimple '%s - could not find animation alias '%d' in decl '%s",
            this->name.data,
            *p_value,
            v60->name.str);
        }
        else if ( !checkPoint )
        {
          idEntity::BecomeActive(this, flags: 7);
          blendParms_t::blendParms_t(this: &v98);
          blendParms_t::SetDestStartFrame(this: &v98, frame: 0);
          v61 = blendTime;
          if ( blendTime == -1 )
            v61 = *((_DWORD *)p_value + 28);
          blendParms_t::SetDurationMS(this: &v98, ms: v61);
          v98.parms.originBlend = 1;
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v63 = *((float *)p_value + 26);
          GetAnimStack_2 = this->GetAnimStack_2;
          if ( (p_value[62] & 0x20) != 0 )
          {
            v65 = GetAnimStack_2(this);
            LODWORD(v66) = &v98;
            idAnimator_Channel::CycleAnim(
              this: &this->channelAnimator,
              stack: v65,
              ah: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)p_value,
              curTime: GameMs,
              rateScale: v63,
              leafStarted: v66,
              a7: nullptr);
          }
          else
          {
            v67 = GetAnimStack_2(this);
            idAnimator_Channel::PlayAnim(
              this: &this->channelAnimator,
              stack: v67,
              ah: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)p_value,
              curTime: GameMs,
              rateScale: v63,
              blendParms: v68,
              blendOutDurationMS_: &v98,
              leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
              a9: nullptr);
          }
          if ( (p_value[62] & 2) != 0 )
            idAnimatedSimple::SetExternalTime(this, normalizedTime: this->externalTime);
        }
        v69 = *((unsigned __int8 *)this + 5292) >> 7;
        if ( v69 != 0 && (LOWORD((v70 = *((idQuat **)v19 + 10))->y) & 0x10) != 0 && v70 != nullptr )
          v71 = v70 + 5;
        else
          v71 = &quat_identity;
        v72 = v71->y;
        v73 = v71->z;
        w = v71->w;
        v114.mat[0].x = v71->x;
        v114.mat[0].y = v72;
        v114.mat[0].z = v73;
        v114.mat[1].x = w;
        if ( v69 != 0 && (*(_WORD *)((v75 = *((_DWORD *)v19 + 10)) + 6) & 0xE) != 0 && v75 != 0 )
          v76 = (idVec3 *)(v75 + 112);
        else
          v76 = &vec3_origin;
        v77 = TreeAnimatorFromPresentable->g.scale.x;
        v78 = TreeAnimatorFromPresentable->g.scale.y;
        v94 = v76->y;
        v93 = v76->x;
        v97.z = TreeAnimatorFromPresentable->g.scale.z * v76->z;
        v97.x = (float)v77 * v93;
        v97.y = (float)v78 * v94;
        idQuat::operator*(this: &v95, result: (idVec3 *)&this->orgRotation, a: (const idVec3 *)&v97);
        v79 = (float)(this->orgOrigin.y + v95.y);
        v80 = (float)(this->orgOrigin.z + v95.z);
        this->nextOrigin.x = this->orgOrigin.x + v95.x;
        this->nextOrigin.y = v79;
        this->nextOrigin.z = v80;
        v81 = idQuat::Inverse(this: &v97, result: (idQuat *)&v114);
        v82 = v81->x;
        v83 = this->orgRotation.x;
        v84 = v81->z;
        v85 = this->orgRotation.z;
        v86 = v81->y;
        v87 = (float)((float)(v81->y * this->orgRotation.w)
                    + (float)((float)(v81->z * this->orgRotation.x) + (float)(v81->w * this->orgRotation.y)));
        v88 = (float)-(float)((float)(v81->y * this->orgRotation.y)
                            - (float)((float)(v81->w * this->orgRotation.w) - (float)(v81->x * this->orgRotation.x)));
        v89 = (float)((float)(v81->w * this->orgRotation.z)
                    + (float)((float)(v81->x * this->orgRotation.y) + (float)(v81->z * this->orgRotation.w)));
        this->nextRotation.x = -(float)((float)(v81->z * this->orgRotation.y)
                                      - (float)((float)(v81->y * this->orgRotation.z)
                                              + (float)((float)(v81->w * this->orgRotation.x)
                                                      + (float)(v81->x * this->orgRotation.w))));
        this->nextRotation.y = -(float)((float)((float)v82 * (float)v85) - (float)v87);
        this->nextRotation.w = -(float)((float)((float)v84 * (float)v85) - (float)v88);
        this->nextRotation.z = -(float)((float)((float)v86 * (float)v83) - (float)v89);
        if ( checkPoint )
        {
          if ( (*((_BYTE *)this + 5292) & 0x80) != 0 || (v90 = false, (*((_BYTE *)this + 5292) & 0x10) != 0) )
            v90 = true;
          idTreeAnimator::SetRemoveOriginRotation(this: TreeAnimatorFromPresentable, removeRotation: v90);
          if ( (*((_BYTE *)this + 5292) & 0x80) != 0 || (v91 = false, (*((_BYTE *)this + 5292) & 0x10) != 0) )
            v91 = true;
          idTreeAnimator::SetRemoveOriginRotation(this: TreeAnimatorFromPresentable, removeRotation: v91);
          v92 = *((_DWORD *)v19 + 10);
          if ( v92 != 0 )
            v92 = *(unsigned __int16 *)(v92 + 8);
          idTreeAnimator::SetFrameFromAnim(
            this: TreeAnimatorFromPresentable,
            anim: (const idMD6Anim *)v19,
            frame: v92 - 1,
            updateRenderModel: true,
            checkForOriginTranslation: false,
            translationScale: nullptr);
        }
      }
    }
  }
}


// ========================================================================
// ?SetAnimState@idAnimatedSimple@@QAAXHH_N0@Z
// EA  : 0x82BFF680
// RVA : 0x00BFF680
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void __fastcall idAnimatedSimple::SetAnimState(
        idAnimatedSimple *this,
        int animState,
        unsigned int blendTime,
        const bool queue,
        bool checkPoint)
{
  int v6; // r30
  signed int num; // r29
  int v11; // r3
  int currentState; // r11
  int v13; // r4
  double z; // fp8
  idPhysics *v15; // r3
  idQuat *v16; // r3
  idPhysics *v17; // r3
  float *v18; // r3
  idPhysics *Physics; // r3
  idQuat *v20; // r3
  idPhysics *v21; // r3
  idMat3 v22[2]; // [sp+50h] [-50h] BYREF

  v6 = animState;
  if ( animState >= 0 || animState == -2 )
  {
    num = this->animList.num;
    if ( num > animState )
    {
      if ( animState == -2 )
      {
        v11 = idRandom2::RandomInt(this: &clientGame->random, max: this->animList.num);
        currentState = this->currentState;
        v6 = v11;
        if ( currentState != -1 && currentState == v11 )
        {
          __twllei(num, 0);
          v6 = (v11 + 1) % num;
          __twlgei(num & ~(__ROL4__(v11 + 1, 1) - 1), 0xFFFFFFFF);
        }
      }
      if ( !queue || this->currentState == -1 )
      {
        v13 = this->currentState;
        if ( v13 == -1 )
        {
          if ( (*((_BYTE *)this + 5292) & 0x40) != 0 )
          {
            Physics = idEntity::GetPhysics(this);
            v20 = (idQuat *)Physics->GetLocalAxis(this: Physics, a2: 0);
            this->orgRotation = *idMat3::ToQuat(this: v22, result: v20);
            v21 = idEntity::GetPhysics(this);
            v18 = (float *)v21->GetLocalOrigin(this: v21, a2: 0);
          }
          else
          {
            v15 = idEntity::GetPhysics(this);
            v16 = (idQuat *)v15->GetAxis(this: v15, a2: 0);
            this->orgRotation = *idMat3::ToQuat(this: v22, result: v16);
            v17 = idEntity::GetPhysics(this);
            v18 = (float *)v17->GetOrigin(this: v17, a2: 0);
          }
          this->orgOrigin.x = *v18;
          this->orgOrigin.y = v18[1];
          z = v18[2];
        }
        else
        {
          idAnimatedSimple::LeaveState(this, iState: v13);
          this->orgRotation.x = this->nextRotation.x;
          this->orgRotation.y = this->nextRotation.y;
          this->orgRotation.z = this->nextRotation.z;
          this->orgRotation.w = this->nextRotation.w;
          this->orgOrigin.x = this->nextOrigin.x;
          this->orgOrigin.y = this->nextOrigin.y;
          z = this->nextOrigin.z;
        }
        this->orgOrigin.z = z;
        idAnimatedSimple::EnterState(this, iState: v6, blendTime, checkPoint);
      }
      else
      {
        this->queuedAnimState = v6;
        this->queuedBlendTime = blendTime;
      }
    }
  }
}


// ========================================================================
// ?SetAnimStateFromAnimAliasRef@idAnimatedSimple@@QAAXAAVidAnimAliasRef@@H_N@Z
// EA  : 0x82BFF888
// RVA : 0x00BFF888
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void __fastcall idAnimatedSimple::SetAnimStateFromAnimAliasRef(
        idAnimatedSimple *this,
        idAnimAliasRef *anim,
        unsigned int blendTime,
        bool queue)
{
  int v8; // r29
  int i; // r30

  v8 = 0;
  if ( this->animList.num > 0 )
  {
    for ( i = 0; idStr::Cmp(s1: this->animList.list[i].animation.data, s2: anim->data) != 0; ++i )
    {
      if ( ++v8 >= this->animList.num )
        return;
    }
    idAnimatedSimple::SetAnimState(this, animState: v8, blendTime, queue, checkPoint: false);
  }
}


// ========================================================================
// ?GotoNextState@idAnimatedSimple@@QAAXH_N@Z
// EA  : 0x82BFF910
// RVA : 0x00BFF910
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void __fastcall idAnimatedSimple::GotoNextState(idAnimatedSimple *this, unsigned int blendTime, bool queue)
{
  idAnimatedSimple::SetAnimState(this, animState: this->currentState + 1, blendTime, queue, checkPoint: false);
}


// ========================================================================
// ?GotoPrevState@idAnimatedSimple@@QAAXH_N@Z
// EA  : 0x82BFF928
// RVA : 0x00BFF928
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void __fastcall idAnimatedSimple::GotoPrevState(idAnimatedSimple *this, unsigned int blendTime, bool queue)
{
  idAnimatedSimple::SetAnimState(this, animState: this->currentState - 1, blendTime, queue, checkPoint: false);
}


// ========================================================================
// ?Event_SetAnimState@idAnimatedSimple@@QAA?AVeventVoid@@HH_N@Z
// EA  : 0x82BFF940
// RVA : 0x00BFF940
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

idAnimatedSimple *__fastcall idAnimatedSimple::Event_SetAnimState(
        idAnimatedSimple *this,
        idAnimatedSimple *result,
        int state,
        unsigned int blendTime,
        bool queueChangeState)
{
  idAnimatedSimple::SetAnimState(this: result, animState: state, blendTime, queue: queueChangeState, checkPoint: false);
  return this;
}


// ========================================================================
// ?Show@idAnimatedSimple@@UAAXXZ
// EA  : 0x82BFF988
// RVA : 0x00BFF988
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void __fastcall idAnimatedSimple::Show(idAnimatedSimple *this)
{
  idPhysics *Physics; // r3
  idLight *NextTeamEntity; // r30
  idEntity *v4; // r29
  idLight *v5; // r3
  int num; // r11
  int v7; // r4
  int v8; // r11
  idAnimatedSimple::animEntry_t *list; // r9

  idEntity::Show(this);
  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: this->physicsContent, a3: -1);
  NextTeamEntity = (idLight *)idEntity::GetNextTeamEntity(this);
  if ( NextTeamEntity != nullptr )
  {
    do
    {
      v4 = idEntity::GetNextTeamEntity(this: NextTeamEntity);
      if ( idEntity::GetBindMaster(this: NextTeamEntity) == this )
      {
        NextTeamEntity->Show(this: NextTeamEntity);
        if ( (unsigned __int8)idLight::IsTypeOf(c: NextTeamEntity) != 0 )
        {
          v5 = idLight::CastTo(c: NextTeamEntity);
          idLight::On(this: v5);
        }
      }
      NextTeamEntity = (idLight *)v4;
    }
    while ( v4 != nullptr );
  }
  idAttachmentCollection::ShowAttachments(this: &this->attachments, hideVehicleAttachments: false);
  if ( !this->hasCheckedDefault )
  {
    num = this->animList.num;
    v7 = 0;
    this->hasCheckedDefault = true;
    if ( num > 0 )
    {
      v8 = 0;
      list = this->animList.list;
      while ( (*((_BYTE *)list + 124) & 0x80) == 0 )
      {
        ++v7;
        list = &this->animList.list[++v8];
        if ( v7 >= this->animList.num )
          return;
      }
      idAnimatedSimple::EnterState(this, iState: v7, blendTime: 0xFFFFFFFF, checkPoint: false);
    }
  }
}


// ========================================================================
// ?Think@idAnimatedSimple@@UAAXXZ
// EA  : 0x82BFFAB0
// RVA : 0x00BFFAB0
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void __fastcall idAnimatedSimple::Think(idAnimatedSimple *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v3; // r14
  bool v4; // r4
  bool v5; // r4
  int v6; // r30
  int v7; // r29
  idMD6LeafPlay *LastPlayedLeaf; // r3
  idMD6LeafPlay *v9; // r30
  signed int v10; // r29
  int GameMs; // r3
  __int64 v12; // r10
  int v13; // r8
  int v14; // r7
  int v15; // r6
  int v16; // r30
  const idAnimStack *v17; // r3
  int currentState; // r24
  int jumpToState; // r26
  unsigned int queuedBlendTime; // r22
  bool v21; // r25
  int v22; // r27
  idAnimatedSimple::animEntry_t *v23; // r30
  int v24; // r28
  int value; // r9
  idEntity *v26; // r3
  idEntity *v27; // r29
  idEventArg *v28; // r3
  int queuedAnimState; // r11
  idPhysics *v30; // r3
  idPhysics *v31; // r29
  idPhysics_vtbl *v32; // r30
  idMat3 *v33; // r3
  idPhysics *Physics; // r3
  idPhysics *v35; // r29
  idPhysics_vtbl *v36; // r30
  idMat3 *v37; // r3
  signed int num; // r11
  unsigned int seed; // r8
  unsigned int v40; // r4
  int v41; // r3
  unsigned int v42; // r5
  int v43; // r11
  idPhysics *v44; // r3
  int v45; // r3
  char *v46; // r10
  _DWORD *v47; // r11
  int i; // ctr
  idPhysics *v49; // r3
  int v50; // r3
  float v51; // r10
  float v52; // r9
  idPhysics *v53; // r3
  idPhysics *v54; // r3
  idPhysics *v55; // r3
  idPhysics *v56; // r3
  idQuat *v57; // r3
  double x; // fp31
  double y; // fp30
  double z; // fp29
  double w; // fp28
  double v62; // fp0
  double v63; // fp13
  char v64; // r11
  double v65; // fp10
  int v66; // r10
  double v67; // fp13
  double v68; // fp11
  double v69; // fp12
  double v70; // fp8
  idPhysics *v71; // r3
  double v72; // fp6
  idPhysics *v73; // r29
  idPhysics_vtbl *v74; // r30
  idMat3 *v75; // r3
  idPhysics *v76; // r3
  double v77; // fp7
  idPhysics *v78; // r29
  idPhysics_vtbl *v79; // r30
  idMat3 *v80; // r3
  idMD6LeafPlay *v81; // r3
  idMD6LeafPlay *v82; // r30
  int currentLoopCount; // r29
  signed int v84; // r28
  int v85; // r3
  signed int LoopCount; // r3
  idAnimatedSimple::animEntry_t *list; // r11
  int v88; // r10
  _DWORD *v89; // r30
  BOOL v90; // r11
  signed int v91; // r10
  int v92; // r27
  int v93; // r28
  int v94; // r9
  idEntity *v95; // r3
  idEntity *v96; // r29
  idEventArg *v97; // r3
  idVec3 v98; // [sp+50h] [-180h] BYREF
  idMat3 v99; // [sp+60h] [-170h] BYREF
  float v100; // [sp+84h] [-14Ch]
  float v101; // [sp+88h] [-148h]
  idVec3 v102; // [sp+90h] [-140h] BYREF
  float v103[4]; // [sp+A0h] [-130h] BYREF
  idVec3 v104; // [sp+B0h] [-120h] BYREF
  idMat3 v105; // [sp+C0h] [-110h] BYREF
  char v106; // [sp+ECh] [-E4h] BYREF
  idMat3 v107[2]; // [sp+F0h] [-E0h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  v3 = TreeAnimatorFromPresentable;
  if ( TreeAnimatorFromPresentable == nullptr )
  {
    idLib::Warning(fmt: "func/animatedSimple '%s' has an invalid model.", this->name.data);
    idEntity::BecomeInactive(this, flags: 7);
    return;
  }
  if ( (*((_BYTE *)this + 5292) & 0x80) != 0 || (v4 = false, (*((_BYTE *)this + 5292) & 0x10) != 0) )
    v4 = true;
  idTreeAnimator::SetRemoveOriginRotation(this: TreeAnimatorFromPresentable, removeRotation: v4);
  if ( (*((_BYTE *)this + 5292) & 0x80) != 0 || (v5 = false, (*((_BYTE *)this + 5292) & 0x10) != 0) )
    v5 = true;
  idTreeAnimator::SetRemoveOriginRotation(this: v3, removeRotation: v5);
  if ( !this->hasCheckedDefault && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: this) == 0 )
  {
    v6 = 0;
    if ( this->animList.num > 0 )
    {
      v7 = 0;
      do
      {
        if ( (*((_BYTE *)&this->animList.list[v7] + 124) & 0x80) != 0 )
          idAnimatedSimple::EnterState(this, iState: v6, blendTime: 0xFFFFFFFF, checkPoint: false);
        ++v6;
        ++v7;
      }
      while ( v6 < this->animList.num );
    }
  }
  if ( this->queuePause )
  {
    LastPlayedLeaf = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
    v9 = LastPlayedLeaf;
    if ( LastPlayedLeaf == nullptr )
      return;
    if ( LastPlayedLeaf->anim != nullptr )
    {
      v10 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      if ( (unsigned __int16)idMD6LeafPlay::GetFrame(
                               this: v9,
                               gameTime: GameMs,
                               ticksPerSec: v10,
                               a4: v15,
                               a5: v14,
                               a6: v13,
                               a7: v12) == this->queuePauseFrame )
      {
        this->queuePauseFrame = -1;
        this->queuePause = false;
        idAnimatedSimple::PauseCurrentAnim(this, pause: true, pauseFrame: -1, queuePause_: false);
      }
    }
  }
  v16 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v17 = this->GetAnimStack_2(this);
  if ( idAnimator_Channel::IsDone(this: &this->channelAnimator, stack: v17, curTime: v16, clampIgnoreExtraFrame: true) )
  {
    currentState = this->currentState;
    jumpToState = -1;
    queuedBlendTime = -1;
    v21 = false;
    if ( currentState != -1 )
    {
      v22 = 0;
      v23 = &this->animList.list[currentState];
      jumpToState = v23->jumpToState;
      v21 = (*((_BYTE *)v23 + 124) & 8) != 0;
      if ( v23->triggerAnimDone.num > 0 )
      {
        v24 = 0;
        do
        {
          value = v23->triggerAnimDone.list[v24].spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
          {
            v26 = gameLocal->entities.ptr[value & 0x1FFF];
            if ( v26 != nullptr )
            {
              v27 = idEntity::CastTo(c: v26);
              if ( v27 != nullptr )
              {
                v28 = idEventArg::idEventArg(this: (idEventArg *)&v105, data: this);
                idEventReceiver::PostEventMS(
                  this: v27,
                  ev: &EV_Activate,
                  time: *(_DWORD *)&v28->type,
                  arg1: (const idEventArg *)LODWORD(v28->value.v[1]));
              }
            }
          }
          ++v22;
          ++v24;
        }
        while ( v22 < v23->triggerAnimDone.num );
      }
      idAnimatedSimple::LeaveState(this, iState: this->currentState);
      queuedAnimState = this->queuedAnimState;
      this->currentState = -1;
      if ( queuedAnimState != -1 )
      {
        queuedBlendTime = this->queuedBlendTime;
        jumpToState = queuedAnimState;
        this->queuedAnimState = -1;
        this->queuedBlendTime = -1;
      }
    }
    if ( idFile_Stat::Timestamp(this: &this->pausedAnimator) != nullptr )
      idAnimatedEntity::Think(this);
    if ( (*((_BYTE *)this + 5292) & 0x80) != 0 && !this->isPaused )
    {
      this->orgOrigin.x = this->nextOrigin.x;
      this->orgOrigin.y = this->nextOrigin.y;
      this->orgOrigin.z = this->nextOrigin.z;
      this->orgRotation.x = this->nextRotation.x;
      this->orgRotation.y = this->nextRotation.y;
      this->orgRotation.z = this->nextRotation.z;
      this->orgRotation.w = this->nextRotation.w;
      if ( (*((_BYTE *)this + 5292) & 0x40) != 0 )
      {
        Physics = idEntity::GetPhysics(this);
        Physics->SetLocalOrigin(this: Physics, a2: &this->nextOrigin, a3: -1);
        v35 = idEntity::GetPhysics(this);
        v36 = v35->__vftable;
        v37 = idQuat::ToMat3(this: (idQuat *)v107, result: (idMat3 *)&this->nextRotation);
        v36->SetLocalAxis(this: v35, a2: v37, a3: -1);
      }
      else
      {
        v30 = idEntity::GetPhysics(this);
        v30->SetOrigin(this: v30, a2: &this->nextOrigin, a3: -1);
        v31 = idEntity::GetPhysics(this);
        v32 = v31->__vftable;
        v33 = idQuat::ToMat3(this: (idQuat *)v107, result: (idMat3 *)&this->nextRotation);
        v32->SetAxis(this: v31, a2: v33, a3: -1);
      }
    }
    if ( jumpToState == -1 )
    {
      idEntity::BecomeInactive(this, flags: 7);
      if ( v21 )
        this->Hide_2(this);
    }
    else
    {
      if ( jumpToState == -2 )
      {
        num = this->animList.num;
        if ( num != 0 )
        {
          seed = clientGame->random.seed;
          __twllei(num, 0);
          v40 = 1664525 * seed + 1013904223;
          clientGame->random.seed = v40;
          v41 = (v40 >> 10) & 0x7FFF;
          jumpToState = v41 % num;
          __twlgei(num & ~(__ROL4__(v41, 1) - 1), 0xFFFFFFFF);
        }
        else
        {
          jumpToState = 0;
        }
        if ( currentState == jumpToState )
        {
          __twllei(num, 0);
          v42 = num & ~(__ROL4__(jumpToState + 1, 1) - 1);
          jumpToState = (jumpToState + 1) % num;
          __twlgei(v42, 0xFFFFFFFF);
        }
      }
      idAnimatedSimple::EnterState(this, iState: jumpToState, blendTime: queuedBlendTime, checkPoint: false);
    }
  }
  else if ( (*((_BYTE *)this + 5292) & 0x80) != 0
         && (*((_BYTE *)this + 5292) & 0x10) == 0
         && this->animUpdatedFrame > this->animStartFrame )
  {
    idEntity::BecomeActive(this, flags: 2);
    v43 = this->currentState;
    if ( v43 == -1 || (*((_BYTE *)&this->animList.list[v43] + 124) & 0x10) == 0 )
    {
      idTreeAnimator::GetTotalOriginTransform(this: v3, rot: (idQuat *)&v99, trans: &v98);
      v57 = idQuat::Inverse(this: (idQuat *)&v105, result: (idQuat *)&v99);
      x = v57->x;
      v99.mat[0].x = v57->x;
      y = v57->y;
      v99.mat[0].y = v57->y;
      z = v57->z;
      v99.mat[0].z = v57->z;
      w = v57->w;
      v99.mat[1].x = v57->w;
      idQuat::operator*(this: (idQuat *)&v99.mat[1].y, result: (idVec3 *)&this->orgRotation, a: &v98);
      v62 = v99.mat[1].y;
      v63 = v99.mat[1].z;
      v98.x = v99.mat[1].y;
      v98.y = v99.mat[1].z;
      v98.z = v99.mat[2].x;
      if ( v99.mat[1].y != vec3_origin.x || v63 != vec3_origin.y || (v64 = 1, v99.mat[2].x != vec3_origin.z) )
        v64 = 0;
      if ( v64 == 0
        || (float)((float)((float)(v99.mat[1].y - this->prevTrans.x) * (float)(v99.mat[1].y - this->prevTrans.x))
                 + (float)((float)((float)(v99.mat[2].x - this->prevTrans.z) * (float)(v99.mat[2].x - this->prevTrans.z))
                         + (float)((float)(v99.mat[1].z - this->prevTrans.y) * (float)(v99.mat[1].z - this->prevTrans.y)))) <= 100.0 )
      {
        this->prevTrans.z = v99.mat[2].x;
        this->prevTrans.y = v63;
        this->prevTrans.x = v62;
        v65 = this->orgRotation.x;
        v66 = *((_BYTE *)this + 5292) & 0x40;
        v67 = this->orgRotation.z;
        v68 = (float)-(float)((float)((float)y * this->orgRotation.y)
                            - (float)((float)((float)w * this->orgRotation.w) - (float)((float)x * this->orgRotation.x)));
        v69 = (float)((float)((float)x * this->orgRotation.y)
                    + (float)((float)((float)z * this->orgRotation.w) + (float)((float)w * this->orgRotation.z)));
        v70 = (float)-(float)((float)((float)x * this->orgRotation.z)
                            - (float)((float)((float)y * this->orgRotation.w)
                                    + (float)((float)((float)w * this->orgRotation.y)
                                            + (float)((float)z * this->orgRotation.x))));
        v99.mat[0].x = -(float)((float)((float)z * this->orgRotation.y)
                              - (float)((float)((float)x * this->orgRotation.w)
                                      + (float)((float)((float)w * this->orgRotation.x)
                                              + (float)((float)y * this->orgRotation.z))));
        v99.mat[0].y = v70;
        v99.mat[1].x = -(float)((float)((float)z * (float)v67) - (float)v68);
        v99.mat[0].z = -(float)((float)((float)y * (float)v65) - (float)v69);
        if ( v66 != 0 )
        {
          v76 = idEntity::GetPhysics(this);
          v77 = (float)(this->orgOrigin.z + v98.z);
          v103[0] = v98.x + this->orgOrigin.x;
          v103[2] = v77;
          v103[1] = this->orgOrigin.y + v98.y;
          v76->SetLocalOrigin(this: v76, a2: (const idVec3 *)v103, a3: -1);
          v78 = idEntity::GetPhysics(this);
          v79 = v78->__vftable;
          v80 = idQuat::ToMat3(this: (idQuat *)v107, result: &v99);
          v79->SetLocalAxis(this: v78, a2: v80, a3: -1);
        }
        else
        {
          v71 = idEntity::GetPhysics(this);
          v101 = this->orgOrigin.z + v98.z;
          v72 = (float)(v98.x + this->orgOrigin.x);
          v100 = this->orgOrigin.y + v98.y;
          v99.mat[2].z = v72;
          v71->SetOrigin(this: v71, a2: (const idVec3 *)&v99.mat[2].z, a3: -1);
          v73 = idEntity::GetPhysics(this);
          v74 = v73->__vftable;
          v75 = idQuat::ToMat3(this: (idQuat *)v107, result: &v99);
          v74->SetAxis(this: v73, a2: v75, a3: -1);
        }
      }
    }
    else
    {
      v44 = idEntity::GetPhysics(this);
      v45 = (int)v44->GetAxis(this: v44, a2: 0);
      v46 = &v106;
      v47 = (_DWORD *)(v45 - 4);
      for ( i = 9; i != 0; --i )
      {
        ++v47;
        v46 += 4;
        *(_DWORD *)v46 = *v47;
      }
      v49 = idEntity::GetPhysics(this);
      v50 = (int)v49->GetOrigin(this: v49, a2: 0);
      v51 = *(float *)(v50 + 4);
      v52 = *(float *)(v50 + 8);
      v99.mat[1].y = *(float *)v50;
      v102.x = 1.0;
      v102.y = 1.0;
      v99.mat[1].z = v51;
      v102.z = 1.0;
      v99.mat[2].x = v52;
      idTreeAnimator::ApplyOriginDeltas(
        this: v3,
        axis: v107,
        origin: (const idVec3 *)&v99.mat[1].y,
        outAxis: &v105,
        outOrigin: &v104,
        extraScale: &v102);
      if ( (*((_BYTE *)this + 5292) & 0x40) != 0 )
      {
        v55 = idEntity::GetPhysics(this);
        v55->SetLocalOrigin(this: v55, a2: &v104, a3: -1);
        v56 = idEntity::GetPhysics(this);
        v56->SetLocalAxis(this: v56, a2: &v105, a3: -1);
      }
      else
      {
        v53 = idEntity::GetPhysics(this);
        v53->SetOrigin(this: v53, a2: &v104, a3: -1);
        v54 = idEntity::GetPhysics(this);
        v54->SetAxis(this: v54, a2: &v105, a3: -1);
      }
    }
    this->UpdateModelTransform(this);
  }
  v81 = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
  v82 = v81;
  if ( this->currentState != -1 && v81 != nullptr )
  {
    currentLoopCount = this->currentLoopCount;
    v84 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
    v85 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    LoopCount = idMD6LeafPlay::GetLoopCount(this: v82, gameTime: v85, ticksPerSec: v84);
    list = this->animList.list;
    v88 = this->currentState << 7;
    this->currentLoopCount = LoopCount;
    v89 = (_DWORD *)((char *)&list->animationHandle.value + v88);
    if ( currentLoopCount != LoopCount )
    {
      if ( v89[30] != 0 )
      {
        v91 = v89[29];
        __twllei(v91, 0);
        __twlgei(v91 & ~(__ROL4__(LoopCount, 1) - 1), 0xFFFFFFFF);
        v90 = (_cntlzw(LoopCount % v91) & 0x20) != 0;
      }
      else
      {
        v90 = (_cntlzw(LoopCount - v89[29]) & 0x20) != 0;
      }
      if ( v90 )
      {
        v92 = 0;
        if ( (int)v89[19] > 0 )
        {
          v93 = 0;
          do
          {
            v94 = *(_DWORD *)(v89[18] + v93);
            if ( gameLocal->spawnIds.ptr[v94 & 0x1FFF] == v94 >> 13 )
            {
              v95 = gameLocal->entities.ptr[v94 & 0x1FFF];
              if ( v95 != nullptr )
              {
                v96 = idEntity::CastTo(c: v95);
                if ( v96 != nullptr )
                {
                  v97 = idEventArg::idEventArg(this: (idEventArg *)&v105, data: this);
                  idEventReceiver::PostEventMS(
                    this: v96,
                    ev: &EV_Activate,
                    time: *(_DWORD *)&v97->type,
                    arg1: (const idEventArg *)LODWORD(v97->value.v[1]));
                }
              }
            }
            ++v92;
            v93 += 4;
          }
          while ( v92 < v89[19] );
        }
      }
    }
  }
  if ( (*(_BYTE *)&this->facialOptions & 4) != 0 )
  {
    if ( this->faceMgr.voiceOver == nullptr )
    {
      LODWORD(v99.mat[2].y) = 960;
      if ( (unsigned __int8)idFaceMgr::RecentlyPlayedVoiceOver(
                              this: &this->faceMgr,
                              threshold: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)&v99.mat[2].y) == 0
        && (*(_BYTE *)&this->facialOptions & 0x80) != 0 )
      {
        idFaceMgr::SetEnableLipSyncAnimation(this: &this->faceMgr, owner: this, enable: false);
      }
    }
    idFaceMgr::Update(this: &this->faceMgr, owner: (idAI2 *)this, ta: v3, focusPoint: &vec3_origin);
  }
  idAnimatedEntity::Think(this);
  this->animUpdatedFrame = idAccolade::Count(this: &clientGame->gameTimeManager);
}


// ========================================================================
// ??0idAnimatedSimple@@QAA@XZ
// EA  : 0x82C00680
// RVA : 0x00C00680
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

idAnimatedSimple *__fastcall idAnimatedSimple::idAnimatedSimple(idAnimatedSimple *this)
{
  float z; // r11

  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idAnimatedSimple_vtbl *)&idAnimatedSimple::`vftable';
  this->hitDetectionOptions.callTargetWhenDead.spawnId.value = 0x1FFF;
  this->hitDetectionOptions.onIgnoredDamageTrigger.spawnId.value = 0x1FFF;
  this->hitDetectionOptions.callWhenDead.allocedAndFlag = 20;
  this->hitDetectionOptions.callWhenDead.data = this->hitDetectionOptions.callWhenDead.baseBuffer;
  this->hitDetectionOptions.callWhenDead.len = 0;
  this->hitDetectionOptions.callWhenDead.baseBuffer[0] = 0;
  this->hitDetectionOptions.health = 0;
  this->hitDetectionOptions.ignoreDamageTypes = DAMAGETYPE_NONE;
  this->hitDetectionOptions.shouldGetHit = false;
  this->hitDetectionOptions.hasBeenKilled = false;
  this->animList.granularity = 0;
  this->animList.memTag = 5;
  this->animList.listStatic = 0;
  this->animList.list = nullptr;
  this->animList.size = 0;
  this->animList.num = 0;
  this->startingAttachments.granularity = 0;
  this->startingAttachments.memTag = 5;
  this->startingAttachments.listStatic = 0;
  this->startingAttachments.list = nullptr;
  this->startingAttachments.size = 0;
  this->startingAttachments.num = 0;
  *(_BYTE *)&this->facialOptions &= 1u;
  this->displayName.index = -1;
  *((_BYTE *)this + 5292) = *((_BYTE *)this + 5292) & 1 | 0x80;
  idAnimator_Channel::idAnimator_Channel(this: &this->channelAnimator);
  idAnimator_Paused::idAnimator_Paused(this: &this->pausedAnimator);
  idAnimator_FaceTracks::idAnimator_FaceTracks(this: &this->faceAnimator);
  idMQBuffer::idMQBuffer(this: &this->attachments);
  idFaceMgr::idFaceMgr(this: &this->faceMgr);
  this->orgRotation = quat_identity;
  this->orgOrigin = vec3_origin;
  this->nextRotation = quat_identity;
  this->nextOrigin = vec3_origin;
  this->prevTrans.x = vec3_origin.x;
  this->prevTrans.y = vec3_origin.y;
  z = vec3_origin.z;
  this->externalTime = 0.0;
  this->prevTrans.z = z;
  this->animStartFrame = -1;
  this->animUpdatedFrame = -1;
  this->physicsContent = 0;
  this->currentState = -1;
  this->queuedAnimState = -1;
  this->queuedBlendTime = -1;
  this->currentLoopCount = 0;
  this->queuePauseFrame = -1;
  this->queuePause = false;
  this->wasLooping = false;
  this->isPaused = false;
  this->hasCheckedDefault = false;
  return this;
}


// ========================================================================
// __unwind$493362
// EA  : 0x82C0087C
// RVA : 0x00C0087C
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_493362()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$493363
// EA  : 0x82C008A4
// RVA : 0x00C008A4
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_493363()
{
  int v0; // r12

  idAnimatedSimple::idHitDetection_t::~idHitDetection_t(this: (idTarget_TimedEvents::idTarget_TimedEvents_Event *)(*(_DWORD *)(v0 - 128 + 148) + 5200));
}


// ========================================================================
// __unwind$493364
// EA  : 0x82C008D0
// RVA : 0x00C008D0
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_493364()
{
  int v0; // r12

  idList<idAnimatedSimple::animEntry_t,5>::~idList<idAnimatedSimple::animEntry_t,5>(this: (idList<idAnimatedSimple::animEntry_t,5> *)(*(_DWORD *)(v0 - 128 + 148) + 5252));
}


// ========================================================================
// __unwind$493365
// EA  : 0x82C008FC
// RVA : 0x00C008FC
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_493365()
{
  int v0; // r12

  idList<idAnimatedSimple::attachment_t,5>::~idList<idAnimatedSimple::attachment_t,5>(this: (idList<idAnimatedSimple::attachment_t,5> *)(*(_DWORD *)(v0 - 128 + 148) + 5268));
}


// ========================================================================
// __unwind$493366
// EA  : 0x82C00928
// RVA : 0x00C00928
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_493366()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 128 + 148) + 5296));
}


// ========================================================================
// __unwind$493367
// EA  : 0x82C00954
// RVA : 0x00C00954
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_493367()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 128 + 148) + 5392));
}


// ========================================================================
// __unwind$493368
// EA  : 0x82C00980
// RVA : 0x00C00980
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_493368()
{
  int v0; // r12

  idAnimator_FaceTracks::~idAnimator_FaceTracks(this: (idAnimator_FaceTracks *)(*(_DWORD *)(v0 - 128 + 148) + 5444));
}


// ========================================================================
// __unwind$493369
// EA  : 0x82C009AC
// RVA : 0x00C009AC
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_493369()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5584));
}


// ========================================================================
// ??1idAnimatedSimple@@UAA@XZ
// EA  : 0x82C009E8
// RVA : 0x00C009E8
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void __fastcall idAnimatedSimple::~idAnimatedSimple(idAnimatedSimple *this)
{
  idAnimStack *p_animStack; // r29
  idAnimator_Channel *p_channelAnimator; // r28
  idAnimatedSimple::attachment_t *list; // r3
  idAnimatedSimple::animEntry_t *v5; // r3

  this->__vftable = (idAnimatedSimple_vtbl *)&idAnimatedSimple::`vftable';
  p_animStack = &this->animStack;
  p_channelAnimator = &this->channelAnimator;
  idAnimator_Base::Shutdown(this: &this->channelAnimator, stack: &this->animStack);
  idAnimator_Base::Shutdown(this: &this->pausedAnimator, stack: p_animStack);
  idAnimator_Base::Shutdown(this: &this->faceAnimator, stack: p_animStack);
  idAttachmentCollection::FreeAttachments(this: &this->attachments);
  idFaceMgr::~idFaceMgr(this: &this->faceMgr);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->attachments);
  idAnimator_FaceTracks::~idAnimator_FaceTracks(this: &this->faceAnimator);
  idAnimator_Paused::~idAnimator_Paused(this: &this->pausedAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: p_channelAnimator);
  if ( this->startingAttachments.listStatic == 0 || this->startingAttachments.listStatic == 2 )
  {
    list = this->startingAttachments.list;
    if ( list != nullptr )
      idListArrayDelete<idAnimatedSimple::attachment_t>(ptr: list, num: this->startingAttachments.size);
    this->startingAttachments.list = nullptr;
    this->startingAttachments.size = 0;
  }
  this->startingAttachments.num = 0;
  if ( this->animList.listStatic == 0 || this->animList.listStatic == 2 )
  {
    v5 = this->animList.list;
    if ( v5 != nullptr )
      idListArrayDelete<idAnimatedSimple::animEntry_t>(ptr: v5, num: this->animList.size);
    this->animList.list = nullptr;
    this->animList.size = 0;
  }
  this->animList.num = 0;
  idStr::FreeData(this: &this->hitDetectionOptions.callWhenDead);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$493857
// EA  : 0x82C00B00
// RVA : 0x00C00B00
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_493857()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$493858
// EA  : 0x82C00B28
// RVA : 0x00C00B28
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_493858()
{
  int v0; // r12

  idAnimatedSimple::idHitDetection_t::~idHitDetection_t(this: (idTarget_TimedEvents::idTarget_TimedEvents_Event *)(*(_DWORD *)(v0 - 144 + 164) + 5200));
}


// ========================================================================
// __unwind$493859
// EA  : 0x82C00B54
// RVA : 0x00C00B54
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_493859()
{
  int v0; // r12

  idList<idAnimatedSimple::animEntry_t,5>::~idList<idAnimatedSimple::animEntry_t,5>(this: (idList<idAnimatedSimple::animEntry_t,5> *)(*(_DWORD *)(v0 - 144 + 164) + 5252));
}


// ========================================================================
// __unwind$493860
// EA  : 0x82C00B80
// RVA : 0x00C00B80
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_493860()
{
  int v0; // r12

  idList<idAnimatedSimple::attachment_t,5>::~idList<idAnimatedSimple::attachment_t,5>(this: (idList<idAnimatedSimple::attachment_t,5> *)(*(_DWORD *)(v0 - 144 + 164) + 5268));
}


// ========================================================================
// __unwind$493861
// EA  : 0x82C00BAC
// RVA : 0x00C00BAC
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_493861()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 144 + 164) + 5296));
}


// ========================================================================
// __unwind$493862
// EA  : 0x82C00BD8
// RVA : 0x00C00BD8
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_493862()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 144 + 164) + 5392));
}


// ========================================================================
// __unwind$493863
// EA  : 0x82C00C04
// RVA : 0x00C00C04
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_493863()
{
  int v0; // r12

  idAnimator_FaceTracks::~idAnimator_FaceTracks(this: (idAnimator_FaceTracks *)(*(_DWORD *)(v0 - 144 + 164) + 5444));
}


// ========================================================================
// __unwind$493864
// EA  : 0x82C00C30
// RVA : 0x00C00C30
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_493864()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 5584));
}


// ========================================================================
// __unwind$493865
// EA  : 0x82C00C5C
// RVA : 0x00C00C5C
// PDB : w:\tech5\tungsten\game\entities\animatedsimple.cpp
// ========================================================================

void _unwind_493865()
{
  int v0; // r12

  idFaceMgr::~idFaceMgr(this: (idFaceMgr *)(*(_DWORD *)(v0 - 144 + 164) + 5604));
}

