
// ========================================================================
// ?GetSoundTransform@idAnimated_AnimWeb@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C017A0
// RVA : 0x00C017A0
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void __fastcall idAnimated_AnimWeb::GetSoundTransform(idAnimated_AnimWeb *this, idVec3 *soundOrigin, idMat3 *soundAxis)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v8; // r30

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v8 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v8 != nullptr && (unsigned __int16)this->soundJointIndex.value < 0x8000u )
    idTreeAnimator::GetWorldSpaceJointTransform(
      this: v8,
      pose: DRIVER_MODEL,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->soundJointIndex.value,
      origin: soundOrigin,
      axis: soundAxis);
  else
    idEntity::GetSoundTransform(this, soundOrigin, soundAxis);
}


// ========================================================================
// ?ChangeAnimWebState@idAnimated_AnimWeb@@UAA?AW4awPathResult_t@@PBD@Z
// EA  : 0x82C01838
// RVA : 0x00C01838
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

awPathResult_t __fastcall idAnimated_AnimWeb::ChangeAnimWebState(idAnimated_AnimWeb *this, const char *animRef)
{
  awPathResult_t v5; // r30
  idStr v6; // [sp+50h] [-60h] BYREF
  idStr v7[2]; // [sp+70h] [-40h] BYREF

  v7[0].len = 0;
  v7[0].allocedAndFlag = 20;
  v7[0].data = v7[0].baseBuffer;
  v7[0].baseBuffer[0] = 0;
  v6.allocedAndFlag = 20;
  v6.data = v6.baseBuffer;
  v6.len = 0;
  v6.baseBuffer[0] = 0;
  if ( (unsigned __int8)idAnimator_AnimWeb::DecomposeAnimRef(
                          this: &this->animWeb,
                          animRef,
                          subWebName: v7,
                          stateName: &v6) != 0 )
  {
    v5 = this->ChangeAnimWebState(this, a2: v7[0].data, a3: v6.data);
    idStr::FreeData(this: &v6);
    idStr::FreeData(this: v7);
    return v5;
  }
  else
  {
    idLib::Warning(fmt: "idAnimatedAnimWeb::Spawn - '%s' has an invalid anim ref '%s'", this->name.data, animRef);
    idStr::FreeData(this: &v6);
    idStr::FreeData(this: v7);
    return AWPATH_FAILED;
  }
}


// ========================================================================
// __unwind$490191_0
// EA  : 0x82C01904
// RVA : 0x00C01904
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_490191_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$490192
// EA  : 0x82C0192C
// RVA : 0x00C0192C
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_490192()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?ChangeAnimWebState@idAnimated_AnimWeb@@UAA?AW4awPathResult_t@@PBD0@Z
// EA  : 0x82C01958
// RVA : 0x00C01958
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

awPathResult_t __fastcall idAnimated_AnimWeb::ChangeAnimWebState(
        idAnimated_AnimWeb *this,
        const char *subWebName,
        const char *stateName)
{
  awPathResult_t result; // r3

  result = idAnimator_AnimWeb::ChangeState(
             this: &this->animWeb,
             subWebName,
             stateName,
             interruptPath_: INTR_PATH_YES,
             interruptBlend_: INTR_BLEND_NO,
             blendEventMask_: 0);
  if ( result != AWPATH_OK && result != AWPATH_ALREADY_THERE )
  {
    idLib::Warning(
      fmt: "idAnimatedAnimWeb::Spawn - '%s' failed to path to node '%s:%s'",
      this->name.data,
      subWebName,
      stateName);
    return AWPATH_FAILED;
  }
  return result;
}


// ========================================================================
// ?ChangeAnimWebStateVia@idAnimated_AnimWeb@@UAA?AW4awPathResult_t@@PBD0@Z
// EA  : 0x82C019C0
// RVA : 0x00C019C0
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

awPathResult_t __fastcall idAnimated_AnimWeb::ChangeAnimWebStateVia(
        idAnimated_AnimWeb *this,
        const char *viaAnimRef,
        const char *destAnimRef)
{
  idAnimator_AnimWeb *p_animWeb; // r28
  awPathResult_t v8; // r30
  idStr v9; // [sp+50h] [-C0h] BYREF
  idStr v10; // [sp+70h] [-A0h] BYREF
  idStr v11; // [sp+90h] [-80h] BYREF
  idStr v12[3]; // [sp+B0h] [-60h] BYREF

  v10.len = 0;
  v10.allocedAndFlag = 20;
  v10.data = v10.baseBuffer;
  v10.baseBuffer[0] = 0;
  v9.allocedAndFlag = 20;
  v9.len = 0;
  v9.data = v9.baseBuffer;
  v9.baseBuffer[0] = 0;
  p_animWeb = &this->animWeb;
  if ( (unsigned __int8)idAnimator_AnimWeb::DecomposeAnimRef(
                          this: &this->animWeb,
                          animRef: destAnimRef,
                          subWebName: &v10,
                          stateName: &v9) != 0 )
  {
    v12[0].allocedAndFlag = 20;
    v12[0].len = 0;
    v12[0].data = v12[0].baseBuffer;
    v12[0].baseBuffer[0] = 0;
    v11.allocedAndFlag = 20;
    v11.data = v11.baseBuffer;
    v11.len = 0;
    v11.baseBuffer[0] = 0;
    if ( (unsigned __int8)idAnimator_AnimWeb::DecomposeAnimRef(
                            this: p_animWeb,
                            animRef: viaAnimRef,
                            subWebName: v12,
                            stateName: &v11) != 0 )
    {
      v8 = this->ChangeAnimWebStateVia(this, a2: v12[0].data, a3: v11.data, a4: v10.data, a5: v9.data);
      idStr::FreeData(this: &v11);
      idStr::FreeData(this: v12);
      idStr::FreeData(this: &v9);
      idStr::FreeData(this: &v10);
      return v8;
    }
    else
    {
      idLib::Warning(fmt: "idAnimatedAnimWeb::Spawn - '%s' has an invalid anim ref '%s'", this->name.data, viaAnimRef);
      idStr::FreeData(this: &v11);
      idStr::FreeData(this: v12);
      idStr::FreeData(this: &v9);
      idStr::FreeData(this: &v10);
      return AWPATH_FAILED;
    }
  }
  else
  {
    idLib::Warning(fmt: "idAnimatedAnimWeb::Spawn - '%s' has an invalid anim ref '%s'", this->name.data, destAnimRef);
    idStr::FreeData(this: &v9);
    idStr::FreeData(this: &v10);
    return AWPATH_FAILED;
  }
}


// ========================================================================
// __unwind$490321
// EA  : 0x82C01B34
// RVA : 0x00C01B34
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_490321()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 112));
}


// ========================================================================
// __unwind$490322
// EA  : 0x82C01B5C
// RVA : 0x00C01B5C
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_490322()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 80));
}


// ========================================================================
// __unwind$490323
// EA  : 0x82C01B84
// RVA : 0x00C01B84
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_490323()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 176));
}


// ========================================================================
// __unwind$490324
// EA  : 0x82C01BAC
// RVA : 0x00C01BAC
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_490324()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 144));
}


// ========================================================================
// ?ForceAnimWebState@idAnimated_AnimWeb@@UAA?AW4awPathResult_t@@PBD@Z
// EA  : 0x82C01BE0
// RVA : 0x00C01BE0
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

int __fastcall idAnimated_AnimWeb::ForceAnimWebState(idAnimated_AnimWeb *this, const char *state)
{
  idAnimator_AnimWeb *p_animWeb; // r28
  int v6; // r3
  int v7; // r30
  blendParms_t v8; // [sp+50h] [-90h] BYREF
  idStr v9; // [sp+70h] [-70h] BYREF
  idStr v10[2]; // [sp+90h] [-50h] BYREF

  v10[0].len = 0;
  v10[0].allocedAndFlag = 20;
  v10[0].data = v10[0].baseBuffer;
  v10[0].baseBuffer[0] = 0;
  v9.allocedAndFlag = 20;
  v9.data = v9.baseBuffer;
  v9.len = 0;
  v9.baseBuffer[0] = 0;
  p_animWeb = &this->animWeb;
  if ( (unsigned __int8)idAnimator_AnimWeb::DecomposeAnimRef(
                          this: &this->animWeb,
                          animRef: state,
                          subWebName: v10,
                          stateName: &v9) != 0 )
  {
    blendParms_t::blendParms_t(this: &v8);
    blendParms_t::SetDestStartFrame(this: &v8, frame: 1);
    blendParms_t::SetDuration(this: &v8, frame: 3);
    v6 = idAnimator_AnimWeb::ForceState(
           this: p_animWeb,
           subWebName: v10[0].data,
           stateName: v9.data,
           blendParms: &v8,
           blendEventMask_: 0);
    v7 = v6;
    if ( v6 == 1 || v6 == 2 )
    {
      idStr::FreeData(this: &v9);
    }
    else
    {
      idLib::Warning(fmt: "idAnimated_AnimWeb: failed to force state");
      idStr::FreeData(this: &v9);
    }
    idStr::FreeData(this: v10);
    return v7;
  }
  else
  {
    idLib::Warning(fmt: "idAnimatedAnimWeb::Spawn - '%s' has an invalid anim ref '%s'", this->name.data, state);
    idStr::FreeData(this: &v9);
    idStr::FreeData(this: v10);
    return 0;
  }
}


// ========================================================================
// __unwind$490542
// EA  : 0x82C01CF4
// RVA : 0x00C01CF4
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_490542()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 144));
}


// ========================================================================
// __unwind$490543
// EA  : 0x82C01D1C
// RVA : 0x00C01D1C
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_490543()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// ?ChangeAnimWebStateVia@idAnimated_AnimWeb@@UAA?AW4awPathResult_t@@PBD000@Z
// EA  : 0x82C01D48
// RVA : 0x00C01D48
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

int __fastcall idAnimated_AnimWeb::ChangeAnimWebStateVia(
        idAnimated_AnimWeb *this,
        const char *viaSubWebName,
        const char *viaStateName,
        const char *destSubWebName,
        const char *destStateName)
{
  int v9; // r3
  int v10; // r31

  v9 = idAnimator_AnimWeb::ChangeStateVia(
         this: &this->animWeb,
         subWebName: destSubWebName,
         stateName: destStateName,
         viaSubWebName,
         viaStateName,
         interruptPath_: INTR_PATH_YES,
         interruptBlend_: INTR_BLEND_NO,
         blendEventMask_: 0);
  v10 = v9;
  if ( v9 != 1 && v9 != 2 )
    idLib::Warning(
      fmt: "idAnimatedAnimWeb::Spawn - '%s' failed to path thru node '%s' to node '%s:%s'",
      this->name.data,
      viaSubWebName,
      viaStateName,
      destSubWebName);
  return v10;
}


// ========================================================================
// ?Event_ChangeAnimState@idAnimated_AnimWeb@@QAA?AVeventVoid@@PBD0@Z
// EA  : 0x82C01DC8
// RVA : 0x00C01DC8
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

idAnimated_AnimWeb *__fastcall idAnimated_AnimWeb::Event_ChangeAnimState(
        idAnimated_AnimWeb *this,
        eventVoid *result,
        const char *destSubWebName,
        const char *destStateName)
{
  (*(void (__fastcall **)(eventVoid *, const char *, const char *))(*(_DWORD *)result + 192))(
    a1: result,
    a2: destSubWebName,
    a3: destStateName);
  return this;
}


// ========================================================================
// ?Event_ChangeAnimStateVia@idAnimated_AnimWeb@@QAA?AVeventVoid@@PBD000@Z
// EA  : 0x82C01E18
// RVA : 0x00C01E18
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

idAnimated_AnimWeb *__fastcall idAnimated_AnimWeb::Event_ChangeAnimStateVia(
        idAnimated_AnimWeb *this,
        eventVoid *result,
        const char *destSubWebName,
        const char *destStateName,
        const char *viaSubWebName,
        const char *viaStateName)
{
  (*(void (__fastcall **)(eventVoid *, const char *, const char *, const char *, const char *))(*(_DWORD *)result + 204))(
    a1: result,
    a2: destSubWebName,
    a3: destStateName,
    a4: viaSubWebName,
    a5: viaStateName);
  return this;
}


// ========================================================================
// ?Event_ForceAnimState@idAnimated_AnimWeb@@QAA?AVeventVoid@@PBD0H@Z
// EA  : 0x82C01E70
// RVA : 0x00C01E70
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

idAnimated_AnimWeb *__fastcall idAnimated_AnimWeb::Event_ForceAnimState(
        idAnimated_AnimWeb *this,
        eventVoid *result,
        const char *destSubWebName,
        const char *destStateName,
        unsigned int blendDurationMS)
{
  blendParms_t v11[4]; // [sp+50h] [-50h] BYREF

  blendParms_t::blendParms_t(this: v11);
  blendParms_t::SetDurationMS(this: v11, ms: blendDurationMS);
  idAnimator_AnimWeb::ForceState(
    this: (idAnimator_AnimWeb *)&result[5348],
    subWebName: destSubWebName,
    stateName: destStateName,
    blendParms: v11,
    blendEventMask_: 0);
  return this;
}


// ========================================================================
// ?Event_StartVoiceOver@idAnimated_AnimWeb@@QAA?AVeventBool@@PAVidEntity@@PBVidDeclVoiceOver@@_N@Z
// EA  : 0x82C01EC8
// RVA : 0x00C01EC8
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

idAnimated_AnimWeb *__fastcall idAnimated_AnimWeb::Event_StartVoiceOver(
        idAnimated_AnimWeb *this,
        idAI2 *result,
        idEntity *talkingTo,
        const idDeclVoiceOver *vo,
        const bool playInCombat)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  char started; // r3
  bool v10; // r4

  if ( vo == nullptr )
  {
    idLib::Warning(fmt: "Invalid play voice over decl specified for Event_StartVoiceOver");
LABEL_6:
    v10 = false;
    goto LABEL_7;
  }
  if ( result->deferredVisGrid.cells[18] == 0 )
    goto LABEL_6;
  if ( result->afProperties.physicsObj.limitLcpEpsilon.duration == 0 )
    goto LABEL_6;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  started = idFaceMgr::StartVoiceOver(
              this: (idFaceMgr *)result->afProperties.physicsObj.limitLcpEpsilon.duration,
              owner: result,
              ta: TreeAnimatorFromPresentable,
              vo);
  v10 = true;
  if ( started == 0 )
    goto LABEL_6;
LABEL_7:
  eventBool::eventBool((eventBool *)this, b: v10);
  return this;
}


// ========================================================================
// ?AnimEvent_VoiceOver@idAnimated_AnimWeb@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclVoiceOver@@@Z
// EA  : 0x82C01F58
// RVA : 0x00C01F58
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

idAnimated_AnimWeb *__fastcall idAnimated_AnimWeb::AnimEvent_VoiceOver(
        idAnimated_AnimWeb *this,
        idAI2 *result,
        const idMD6Anim *animHandle,
        const idDeclVoiceOver *vo)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3

  if ( vo != nullptr )
  {
    if ( result->deferredVisGrid.cells[18] != 0 && result->afProperties.physicsObj.limitLcpEpsilon.duration != 0 )
    {
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
      idFaceMgr::StartVoiceOver(
        this: (idFaceMgr *)result->afProperties.physicsObj.limitLcpEpsilon.duration,
        owner: result,
        ta: TreeAnimatorFromPresentable,
        vo);
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
// ?AnimEvent_HolsterItem@idAnimated_AnimWeb@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82C01FD0
// RVA : 0x00C01FD0
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

idAnimated_AnimWeb *__fastcall idAnimated_AnimWeb::AnimEvent_HolsterItem(
        idAnimated_AnimWeb *this,
        idAnimatedEntity *result,
        const idMD6Anim *animHandle,
        const char *slotName)
{
  int v7; // r3
  int v8; // r28
  int v10; // r26
  const idAttachment *v11; // r31
  const idDeclMD6 *decl; // r10
  idPropsCollection *p_props; // r29
  const char *str; // r31
  const idDeclParticle *particleFx; // r11
  const char *v16; // r4
  equipSlot_t v17; // r31
  const tagData_t *Tag; // r3
  idHandle<int,enum invalidAttachment_t,-1> v19[20]; // [sp+50h] [-50h] BYREF

  v7 = idDeclInventory::EquipSlotForName(name: slotName);
  v8 = v7;
  if ( v7 >= 15 )
  {
    idLib::Warning(fmt: "Unknown equip slot '%s'", slotName);
    return this;
  }
  v10 = 4 * (v7 + 1566);
  v19[0] = *(idHandle<int,enum invalidAttachment_t,-1> *)((char *)&result->__vftable + v10);
  if ( v19[0].value == -1 )
  {
    idLib::Warning(fmt: "Tried to holster from slot '%s' while slot is empty.", slotName);
    return this;
  }
  v11 = idAttachmentCollection::Get(this: (idAttachmentCollection *)&result[1].animStack.skipSerialization, handle: v19);
  if ( v11 == nullptr )
  {
    idLib::Warning(fmt: "Failed to get attachment.");
    return this;
  }
  decl = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result)->decl;
  p_props = &decl->props;
  if ( v11->presentable != nullptr )
  {
    str = v11->presentable->model->name.str;
  }
  else
  {
    particleFx = v11->particleFx;
    if ( particleFx == nullptr )
    {
LABEL_12:
      idLib::Warning(fmt: "Could not find prop name for attachment.");
      return this;
    }
    str = particleFx->name.str;
  }
  if ( str == nullptr )
    goto LABEL_12;
  if ( idPropsCollection::FindPropIndex(this: &decl->props, propName: str) >= 0 )
  {
    v16 = str;
    v17 = equipToHolsterSlot[v8];
    Tag = idPropsCollection::GetTag(this: p_props, propName: v16, tagName: idDeclInventory::equipSlotTagNames[v17]);
    idAttachmentCollection::RebindAttachment(
      this: (idAttachmentCollection *)&result[1].animStack.skipSerialization,
      handle: v19,
      tagData: Tag);
    *(idHandle<int,enum invalidAttachment_t,-1> *)&result[1].animStack.branchMemory[4 * v17 + 10] = v19[0];
    *(idAnimatedEntity_vtbl **)((char *)&result->__vftable + v10) = (idAnimatedEntity_vtbl *)-1;
    return this;
  }
  else
  {
    idLib::Warning(fmt: "Could not find prop info for attachment.");
    return this;
  }
}


// ========================================================================
// ?AnimEvent_EquipItem@idAnimated_AnimWeb@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82C02168
// RVA : 0x00C02168
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

idAnimated_AnimWeb *__fastcall idAnimated_AnimWeb::AnimEvent_EquipItem(
        idAnimated_AnimWeb *this,
        idAnimatedEntity *result,
        const idMD6Anim *animHandle,
        const char *slotName)
{
  int v7; // r3
  int v8; // r28
  int v10; // r26
  const idAttachment *v11; // r31
  const idDeclMD6 *decl; // r10
  idPropsCollection *p_props; // r29
  const char *str; // r31
  const idDeclParticle *particleFx; // r11
  const char *v16; // r4
  equipSlot_t v17; // r31
  const tagData_t *Tag; // r3
  idHandle<int,enum invalidAttachment_t,-1> v19[20]; // [sp+50h] [-50h] BYREF

  v7 = idDeclInventory::EquipSlotForName(name: slotName);
  v8 = v7;
  if ( v7 >= 15 )
  {
    idLib::Warning(fmt: "Unknown equip slot '%s'", slotName);
    return this;
  }
  v10 = 4 * (v7 + 1566);
  v19[0] = *(idHandle<int,enum invalidAttachment_t,-1> *)((char *)&result->__vftable + v10);
  if ( v19[0].value == -1 )
  {
    idLib::Warning(fmt: "Tried to holster from slot '%s' while slot is empty.", slotName);
    return this;
  }
  v11 = idAttachmentCollection::Get(this: (idAttachmentCollection *)&result[1].animStack.skipSerialization, handle: v19);
  if ( v11 == nullptr )
  {
    idLib::Warning(fmt: "Failed to get attachment.");
    return this;
  }
  decl = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result)->decl;
  p_props = &decl->props;
  if ( v11->presentable != nullptr )
  {
    str = v11->presentable->model->name.str;
  }
  else
  {
    particleFx = v11->particleFx;
    if ( particleFx == nullptr )
    {
LABEL_12:
      idLib::Warning(fmt: "Could not find prop name for attachment.");
      return this;
    }
    str = particleFx->name.str;
  }
  if ( str == nullptr )
    goto LABEL_12;
  if ( idPropsCollection::FindPropIndex(this: &decl->props, propName: str) >= 0 )
  {
    v16 = str;
    v17 = holsterToEquipSlot[v8];
    Tag = idPropsCollection::GetTag(this: p_props, propName: v16, tagName: idDeclInventory::equipSlotTagNames[v17]);
    idAttachmentCollection::RebindAttachment(
      this: (idAttachmentCollection *)&result[1].animStack.skipSerialization,
      handle: v19,
      tagData: Tag);
    *(idHandle<int,enum invalidAttachment_t,-1> *)&result[1].animStack.branchMemory[4 * v17 + 10] = v19[0];
    *(idAnimatedEntity_vtbl **)((char *)&result->__vftable + v10) = (idAnimatedEntity_vtbl *)-1;
    return this;
  }
  else
  {
    idLib::Warning(fmt: "Could not find prop info for attachment.");
    return this;
  }
}


// ========================================================================
// ?AnimEvent_ItemStartFX@idAnimated_AnimWeb@@QAA?AVeventVoid@@PBVidMD6Anim@@PBDW4fxCondition_t@@@Z
// EA  : 0x82C02300
// RVA : 0x00C02300
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

idAnimated_AnimWeb *__fastcall idAnimated_AnimWeb::AnimEvent_ItemStartFX(
        idAnimated_AnimWeb *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const char *slotName,
        fxCondition_t condition)
{
  int v9; // r3
  const idAttachment *v11; // r3
  idPresentable *presentable; // r3
  idHandle<int,enum invalidAttachment_t,-1> v13; // [sp+50h] [-30h] BYREF

  v9 = idDeclInventory::EquipSlotForName(name: slotName);
  if ( v9 < 15 )
  {
    v13.value = *(_DWORD *)&result[4 * v9 + 6264];
    if ( v13.value == -1 )
    {
      idLib::Warning(fmt: "Tried to holster from slot '%s' while slot is empty.", slotName);
      return this;
    }
    else
    {
      v11 = idAttachmentCollection::Get(this: (idAttachmentCollection *)&result[6244], handle: &v13);
      if ( v11 != nullptr )
      {
        presentable = v11->presentable;
        if ( presentable != nullptr )
          presentable->StartFX(this: presentable, a2: condition, a3: FX_EXTRA_COND_NONE);
        return this;
      }
      else
      {
        idLib::Warning(fmt: "Failed to get attachment.");
        return this;
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "Unknown equip slot '%s'", slotName);
    return this;
  }
}


// ========================================================================
// ?AnimEvent_ItemStopFX@idAnimated_AnimWeb@@QAA?AVeventVoid@@PBVidMD6Anim@@PBDW4fxCondition_t@@@Z
// EA  : 0x82C023D8
// RVA : 0x00C023D8
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

idAnimated_AnimWeb *__fastcall idAnimated_AnimWeb::AnimEvent_ItemStopFX(
        idAnimated_AnimWeb *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const char *slotName,
        int condition)
{
  int v9; // r3
  const idAttachment *v11; // r3
  idPresentable *presentable; // r3
  idHandle<int,enum invalidAttachment_t,-1> v13; // [sp+50h] [-30h] BYREF

  v9 = idDeclInventory::EquipSlotForName(name: slotName);
  if ( v9 < 15 )
  {
    v13.value = *(_DWORD *)&result[4 * v9 + 6264];
    if ( v13.value == -1 )
    {
      idLib::Warning(fmt: "Tried to holster from slot '%s' while slot is empty.", slotName);
      return this;
    }
    else
    {
      v11 = idAttachmentCollection::Get(this: (idAttachmentCollection *)&result[6244], handle: &v13);
      if ( v11 != nullptr )
      {
        presentable = v11->presentable;
        if ( presentable != nullptr )
          idPresentable::StopFX(this: presentable, condition, extraCondition: FX_EXTRA_COND_NONE);
        return this;
      }
      else
      {
        idLib::Warning(fmt: "Failed to get attachment.");
        return this;
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "Unknown equip slot '%s'", slotName);
    return this;
  }
}


// ========================================================================
// ?Hide@idAnimated_AnimWeb@@UAAXXZ
// EA  : 0x82C024A8
// RVA : 0x00C024A8
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void __fastcall idAnimated_AnimWeb::Hide(idAnimated_AnimWeb *this)
{
  int v2; // r30
  int v3; // r31

  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: this) == 0 )
  {
    idAttachmentCollection::HideAttachments(this: &this->attachments);
    v2 = 0;
    if ( this->collisionPieces.num > 0 )
    {
      v3 = 0;
      do
      {
        this->collisionPieces.list[v3].physicsObj.DisableClip(this: &this->collisionPieces.list[v3].physicsObj);
        ++v2;
        ++v3;
      }
      while ( v2 < this->collisionPieces.num );
    }
    idEntity::BecomeInactive(this, flags: 7);
  }
  idEntity::Hide(this);
}


// ========================================================================
// ?Show@idAnimated_AnimWeb@@UAAXXZ
// EA  : 0x82C02530
// RVA : 0x00C02530
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void __fastcall idAnimated_AnimWeb::Show(idAnimated_AnimWeb *this)
{
  int v2; // r30
  int v3; // r31

  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: this) != 0 )
  {
    idAttachmentCollection::ShowAttachments(this: &this->attachments, hideVehicleAttachments: false);
    v2 = 0;
    if ( this->collisionPieces.num > 0 )
    {
      v3 = 0;
      do
      {
        this->collisionPieces.list[v3].physicsObj.EnableClip(this: &this->collisionPieces.list[v3].physicsObj);
        ++v2;
        ++v3;
      }
      while ( v2 < this->collisionPieces.num );
    }
    idEntity::BecomeActive(this, flags: 1);
  }
  idEntity::Show(this);
}


// ========================================================================
// ?AnimEvent_HideFFFKnife@idAnimated_AnimWeb@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD1@Z
// EA  : 0x82C025C0
// RVA : 0x00C025C0
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

idAnimated_AnimWeb *__fastcall idAnimated_AnimWeb::AnimEvent_HideFFFKnife(
        idAnimated_AnimWeb *this,
        idAnimatedEntity *result,
        const idMD6Anim *animHandle,
        const char *modelName,
        const char *jointName)
{
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r3
  idHandle<int,enum invalidAttachment_t,-1> *p_skipSerialization; // r31
  unsigned __int16 v12; // [sp+50h] [-30h] BYREF
  idAttachmentCollection v13[2]; // [sp+54h] [-2Ch] BYREF

  TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v12, result: TreeAnimatorFromPresentable, jointName);
  if ( v12 == 0xFFFF )
  {
    idLib::Warning(fmt: "Event_HideAttachment - Invalid joint index.");
    return this;
  }
  else
  {
    p_skipSerialization = (idHandle<int,enum invalidAttachment_t,-1> *)&result[1].animStack.skipSerialization;
    idAttachmentCollection::FindAttachment(
      this: v13,
      result: p_skipSerialization,
      modelName,
      jointIndex: (idIndex<short,enum invalidJointIndex_t> *)v12);
    if ( v13[0].attachments.list == (idAttachment *)-1 )
      idLib::Warning(fmt: "Event_HideAttachment - Invalid attachment handle.");
    else
      idAttachmentCollection::HideAttachment(
        this: (idAttachmentCollection *)p_skipSerialization,
        handle: (const idHandle<int,enum invalidAttachment_t,-1> *)v13,
        ignoreShowAll: false);
    return this;
  }
}


// ========================================================================
// ?AnimEvent_ShowFFFKnife@idAnimated_AnimWeb@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD1@Z
// EA  : 0x82C02670
// RVA : 0x00C02670
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

idAnimated_AnimWeb *__fastcall idAnimated_AnimWeb::AnimEvent_ShowFFFKnife(
        idAnimated_AnimWeb *this,
        idAnimatedEntity *result,
        const idMD6Anim *animHandle,
        const char *modelName,
        const char *jointName)
{
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r3
  idHandle<int,enum invalidAttachment_t,-1> *p_skipSerialization; // r31
  unsigned __int16 v12; // [sp+50h] [-30h] BYREF
  idAttachmentCollection v13[2]; // [sp+54h] [-2Ch] BYREF

  TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v12, result: TreeAnimatorFromPresentable, jointName);
  if ( v12 == 0xFFFF )
  {
    idLib::Warning(fmt: "Event_HideAttachment - Invalid joint index.");
    return this;
  }
  else
  {
    p_skipSerialization = (idHandle<int,enum invalidAttachment_t,-1> *)&result[1].animStack.skipSerialization;
    idAttachmentCollection::FindAttachment(
      this: v13,
      result: p_skipSerialization,
      modelName,
      jointIndex: (idIndex<short,enum invalidJointIndex_t> *)v12);
    if ( v13[0].attachments.list == (idAttachment *)-1 )
      idLib::Warning(fmt: "Event_ShowAttachment - Invalid attachment handle.");
    else
      idAttachmentCollection::ShowAttachment(
        this: (idAttachmentCollection *)p_skipSerialization,
        handle: (const idHandle<int,enum invalidAttachment_t,-1> *)v13);
    return this;
  }
}


// ========================================================================
// ?AnimEvent_DamagePlayer@idAnimated_AnimWeb@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclDamage@@HM@Z
// EA  : 0x82C02718
// RVA : 0x00C02718
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

idAnimated_AnimWeb *__fastcall idAnimated_AnimWeb::AnimEvent_DamagePlayer(
        idAnimated_AnimWeb *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const idDeclDamage *damage,
        int playerNumber,
        double percentLifeLeft)
{
  idPlayer *Player; // r3
  _DWORD *v10; // r31
  idTungstenHealth *p_playerHealth; // r30
  double v12; // fp31
  double v13; // fp31
  int v14; // r3
  int v15; // r3
  idView *v16; // r31
  idVec3 v18; // [sp+50h] [-80h] BYREF
  idVec3 v19; // [sp+60h] [-70h] BYREF
  idMat3 v20; // [sp+70h] [-60h] BYREF

  Player = idGameLocal::GetPlayer(this: gameLocal, i: playerNumber);
  v10 = &Player->__vftable;
  if ( Player != nullptr )
  {
    p_playerHealth = &Player->playerHealth;
    v12 = (float)(Player->playerHealth.GetMaxBaseHealth_Impl(this: &Player->playerHealth) * (float)percentLifeLeft);
    if ( v12 < ((double (__fastcall *)(idTungstenHealth *))*(_DWORD *)(v10[3042] + 60))(a1: p_playerHealth) )
    {
      v13 = __fabs((float)((float)v12 - p_playerHealth->GetCurBaseHealth_Impl(this: p_playerHealth)));
      (*(void (__fastcall **)(_DWORD *, idWorldspawn *, _DWORD, const idDeclDamage *, int, idVec3 *, _DWORD, double))(*v10 + 312))(
        a1: v10,
        a2: gameLocal->world,
        a3: 0,
        a4: damage,
        a5: 0x20000,
        a6: &vec3_origin,
        a7: 0,
        a8: v13);
      v14 = v10[122];
      if ( v14 != 0 )
        v15 = (*(int (__fastcall **)(int))(*(_DWORD *)v14 + 104))(a1: v14);
      else
        v15 = 0;
      v16 = (idView *)(v15 + 16224);
      idView::GetViewPos(this: (idView *)(v15 + 16224), origin: &v19, axis: &v20);
      v18.x = v20.mat[0].x * (float)-1.0;
      v18.y = v20.mat[0].y * (float)-1.0;
      v18.z = v20.mat[0].z * (float)-1.0;
      idView::DamageImpulse(
        this: v16,
        localKickDir: &v18,
        inflictorOrg: &v19,
        damageDef: damage,
        impulseDamageScale: v13);
    }
  }
  return this;
}


// ========================================================================
// ?AnimEvent_PlayerControllerShake@idAnimated_AnimWeb@@QAA?AVeventVoid@@PBVidMD6Anim@@HHHH@Z
// EA  : 0x82C02870
// RVA : 0x00C02870
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

idAnimated_AnimWeb *__fastcall idAnimated_AnimWeb::AnimEvent_PlayerControllerShake(
        idAnimated_AnimWeb *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        unsigned int highMag,
        int highTime,
        unsigned int lowMag,
        int lowTime)
{
  __int64 v11; // r10
  int v12; // r4
  idPlayer *Player; // r3
  idPresentable *presentable; // r3
  int v15; // r3

  Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
  if ( Player != nullptr )
  {
    presentable = Player->presentable;
    if ( presentable != nullptr )
      v15 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v15 = 0;
    LODWORD(v11) = lowMag;
    idView::SetControllerShake(
      this: (idView *)(v15 + 16224),
      highMagnitude: (float)__SPAIR64__(lowMag, highMag),
      highDuration: v12,
      lowMagnitude: (float)v11,
      lowDuration: highTime);
  }
  return this;
}


// ========================================================================
// ?UpdateCollisionPieces@idAnimated_AnimWeb@@AAAXAAVidBounds@@_N@Z
// EA  : 0x82C02910
// RVA : 0x00C02910
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void __fastcall idAnimated_AnimWeb::UpdateCollisionPieces(idAnimated_AnimWeb *this, idBounds *bounds, const bool push)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v8; // r21
  int v9; // r22
  int i; // r26
  idAnimated_AnimWeb::collisionPiece_t *v11; // r28
  int curStage; // r11
  int v13; // r11
  idAnimated_AnimWeb::collisionPieceStage_t *list; // r10
  char *v15; // r29
  idPhysics_Static *v16; // r30
  float *v17; // r3
  double v18; // fp10
  double v19; // fp0
  double v20; // fp7
  double v21; // fp1
  idMat3 *v22; // r29
  const idVec3 *v23; // r3
  int v24; // r3
  const idDeclDamage *pushDamage; // r6
  const idBounds *v26; // r3
  idPresentable *v27; // r11
  idPhysics_Static *p_physicsObj; // r30
  idPresentable *v29; // r11
  float *v30; // r3
  double y; // fp13
  double z; // fp12
  double x; // fp11
  double v35; // fp10
  double v36; // fp7
  idVec3 v48; // [sp+50h] [-150h] BYREF
  idVec3 v49; // [sp+60h] [-140h] BYREF
  idMat3 v50; // [sp+70h] [-130h] BYREF
  trace_t v51; // [sp+A0h] [-100h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v8 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v8 != nullptr )
  {
    v9 = 0;
    bounds->b[0].z = 1.0e30;
    bounds->b[0].y = 1.0e30;
    bounds->b[0].x = 1.0e30;
    bounds->b[1].z = -1.0e30;
    bounds->b[1].y = -1.0e30;
    bounds->b[1].x = -1.0e30;
    if ( this->collisionPieces.num > 0 )
    {
      for ( i = 0; ; ++i )
      {
        v11 = &this->collisionPieces.list[i];
        curStage = v11->curStage;
        if ( v11->stages.num > curStage )
        {
          v13 = curStage << 7;
          list = this->collisionPieces.list[i].stages.list;
          v15 = (char *)list + v13;
          if ( *(unsigned __int16 *)((char *)&list->jointIndex.value + v13) >= 0x8000u
            || (unsigned __int8)idTreeAnimator::GetWorldSpaceAttachmentTransform(
                                  this: v8,
                                  jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)*(unsigned __int16 *)((char *)&list->jointIndex.value + v13),
                                  translationOffset: (const idVec3 *)(v15 + 116),
                                  rotationOffset: (idMat3 *)(v15 + 100),
                                  origin: &v48,
                                  axis: &v50) == 0 )
          {
            v27 = this->presentable;
            if ( v27 == nullptr )
            {
              idEntity::InitPresentableInternal(this);
              v27 = this->presentable;
            }
            p_physicsObj = &v11->physicsObj;
            v11->physicsObj.SetOrigin(this: &v11->physicsObj, a2: &v27->origin, a3: -1);
            v29 = this->presentable;
            if ( v29 == nullptr )
            {
              idEntity::InitPresentableInternal(this);
              v29 = this->presentable;
            }
            p_physicsObj->SetAxis(this: &v11->physicsObj, a2: &v29->axis, a3: -1);
            v30 = (float *)p_physicsObj->GetAbsBounds(this: &v11->physicsObj, a2: -1);
            _FP8 = (float)(bounds->b[0].x - *v30);
            y = bounds->b[0].y;
            z = bounds->b[0].z;
            x = bounds->b[1].x;
            v35 = bounds->b[1].y;
            v36 = bounds->b[1].z;
            __asm { fsel      f6, f8, f9, f0 }
            bounds->b[0].x = _FP6;
            _FP4 = (float)((float)y - v30[1]);
            __asm { fsel      f3, f4, f5, f13 }
            bounds->b[0].y = _FP3;
            _FP1 = (float)((float)z - v30[2]);
            __asm { fsel      f0, f1, f2, f12 }
            bounds->b[0].z = _FP0;
            _FP12 = (float)(v30[3] - (float)x);
            __asm { fsel      f11, f12, f13, f11 }
            bounds->b[1].x = _FP11;
            _FP8 = (float)(v30[4] - (float)v35);
            __asm { fsel      f6, f8, f9, f10 }
            bounds->b[1].y = _FP6;
            _FP4 = (float)(v30[5] - (float)v36);
            __asm { fsel      f3, f4, f5, f7 }
            bounds->b[1].z = _FP3;
            goto LABEL_31;
          }
          v16 = &v11->physicsObj;
          v17 = (float *)v11->physicsObj.GetOrigin(this: &v11->physicsObj, a2: 0);
          v18 = (float)(v48.y - v17[1]);
          v19 = (float)(v48.x - *v17);
          v20 = (float)(v48.z - v17[2]);
          v49.y = v48.y - v17[1];
          v49.x = v19;
          v49.z = v20;
          if ( (float)((float)((float)v20 * (float)v20)
                     + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) > 0.000001 )
            break;
        }
LABEL_31:
        if ( ++v9 >= this->collisionPieces.num )
          return;
      }
      v21 = idVec3::NormalizeFast(this: &v49);
      if ( push && (v15[89] != 0 || v15[90] != 0) && (this->pushDamage != nullptr || this->crushDamage != nullptr) )
      {
        idPush::InitSavingPushedPhysicsObjectState(this: &clientGame->push);
        v22 = (idMat3 *)v16->GetAxis(this: &v11->physicsObj, a2: 0);
        v23 = v16->GetOrigin(this: &v11->physicsObj, a2: 0);
        v21 = idPush::ClipPush(
                this: &clientGame->push,
                results: &v51,
                pusher: &v11->physicsObj,
                flags: v11->pushFlags,
                oldOrigin: v23,
                oldAxis: v22,
                newOrigin: &v48,
                newAxis: &v50);
        if ( v51.fraction != 1.0 && v51.c.entityNum != 8190 )
        {
          if ( this->crushDamage == nullptr )
          {
            if ( this->pushDamage == nullptr )
              goto LABEL_25;
            v24 = ((int (__fastcall *)(idGameLocal *, double))gameLocal->GetEntity)(a1: gameLocal, a2: v21);
            if ( v24 == 0 )
              goto LABEL_25;
            pushDamage = this->pushDamage;
            goto LABEL_23;
          }
          v24 = ((int (__fastcall *)(idGameLocal *, double))gameLocal->GetEntity)(a1: gameLocal, a2: v21);
          if ( v24 != 0 )
          {
            pushDamage = this->crushDamage;
LABEL_23:
            if ( pushDamage != nullptr )
              (*(void (__fastcall **)(int, idAnimated_AnimWeb *, idAnimated_AnimWeb *, double))(*(_DWORD *)v24 + 312))(
                a1: v24,
                a2: this,
                a3: this,
                a4: 1.0);
          }
        }
      }
LABEL_25:
      ((void (__fastcall *)(idPhysics_Static *, idVec3 *, int, double))v16->SetOrigin)(
        a1: &v11->physicsObj,
        a2: &v48,
        a3: -1,
        a4: v21);
      v16->SetAxis(this: &v11->physicsObj, a2: &v50, a3: -1);
      v26 = v16->GetAbsBounds(this: &v11->physicsObj, a2: -1);
      idBounds::AddBounds(this: bounds, a: v26);
      goto LABEL_31;
    }
  }
}


// ========================================================================
// ?SetStage@idAnimated_AnimWeb@@QAAXHH_N@Z
// EA  : 0x82C02D50
// RVA : 0x00C02D50
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void __fastcall idAnimated_AnimWeb::SetStage(
        idAnimated_AnimWeb *this,
        int pieceNum,
        int stageIndex,
        const bool updateCollision)
{
  int v7; // r30
  idAnimated_AnimWeb::collisionPiece_t *v8; // r31
  idAnimated_AnimWeb::collisionPieceStage_t *v9; // r30
  idPhysics_Static_vtbl *v10; // r26
  int v11; // r3
  idPhysics_Static_vtbl *v12; // r26
  int v13; // r3
  int v14; // r11
  idBounds v15[4]; // [sp+50h] [-60h] BYREF

  if ( pieceNum < this->collisionPieces.num )
  {
    v7 = pieceNum;
    v8 = &this->collisionPieces.list[pieceNum];
    if ( stageIndex < v8->stages.num )
    {
      v8->physicsObj.UnlinkClip(this: &v8->physicsObj);
      v9 = &this->collisionPieces.list[v7].stages.list[stageIndex];
      ((void (__fastcall *)(idPhysics_Static *, idClipModel *, idPhysics_Static_vtbl *, _DWORD, _DWORD, double))v8->physicsObj.SetClipModel)(
        a1: &v8->physicsObj,
        a2: v9->clipModel,
        a3: v8->physicsObj.__vftable,
        a4: 0,
        a5: 0,
        a6: 1.0);
      v10 = v8->physicsObj.__vftable;
      v11 = idContents::ToFlags(this: &v9->clipMask);
      v10->SetClipMask(this: &v8->physicsObj, a2: v11, a3: -1);
      v12 = v8->physicsObj.__vftable;
      v13 = idContents::ToFlags(this: &v9->contents);
      v12->SetContents(this: &v8->physicsObj, a2: v13, a3: -1);
      if ( v9->crush )
      {
        v14 = 56;
      }
      else
      {
        v14 = 40;
        if ( !v9->push )
          v14 = 8;
      }
      v8->pushFlags = v14;
      v8->curStage = stageIndex;
      if ( updateCollision )
        idAnimated_AnimWeb::UpdateCollisionPieces(this, bounds: v15, push: false);
    }
    else
    {
      idLib::Warning(fmt: "idAnimated_AnimWeb::SetStage - '%s',  stageIndex out of range", this->name.data);
    }
  }
  else
  {
    idLib::Warning(fmt: "idAnimated_AnimWeb::SetStage - '%s',  pieceNum out of range", this->name.data);
  }
}


// ========================================================================
// ?AnimEvent_SetStage@idAnimated_AnimWeb@@QAA?AVeventVoid@@PBVidMD6Anim@@HH@Z
// EA  : 0x82C02EB0
// RVA : 0x00C02EB0
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

idAnimated_AnimWeb *__fastcall idAnimated_AnimWeb::AnimEvent_SetStage(
        idAnimated_AnimWeb *this,
        idAnimated_AnimWeb *result,
        const idMD6Anim *animHandle,
        int pieceIndex,
        int stageIndex)
{
  idAnimated_AnimWeb::SetStage(this: result, pieceNum: pieceIndex, stageIndex, updateCollision: true);
  return this;
}


// ========================================================================
// ?AnimEvent_TriggerAttachments@idAnimated_AnimWeb@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82C02EF0
// RVA : 0x00C02EF0
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

idAnimated_AnimWeb *__fastcall idAnimated_AnimWeb::AnimEvent_TriggerAttachments(
        idAnimated_AnimWeb *this,
        const idEntity *result,
        const idMD6Anim *animHandle)
{
  int v5; // r29
  idAttachmentCollection *p_z; // r27
  idAttachment *v7; // r3
  int value; // r9
  idAttachment *v9; // r31
  idEntity *v10; // r3
  int v11; // r9
  idEntity *v12; // r3
  idEntity *v13; // r31
  idEventArg *v14; // r3
  idEventArg v16[4]; // [sp+50h] [-60h] BYREF

  v5 = 0;
  if ( SLODWORD(result[7].defaultPhysicsObj.current.localAxis.mat[1].x) > 0 )
  {
    p_z = (idAttachmentCollection *)&result[7].defaultPhysicsObj.current.localAxis.mat[0].z;
    do
    {
      v7 = idAttachmentCollection::ForIndex(this: p_z, index: v5);
      value = v7->entity.spawnId.value;
      v9 = v7;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v10 = gameLocal->entities.ptr[value & 0x1FFF];
        if ( v10 != nullptr && idEntity::CastTo(c: v10) != nullptr )
        {
          v11 = v9->entity.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v11 & 0x1FFF] == v11 >> 13
            && (v12 = gameLocal->entities.ptr[v11 & 0x1FFF]) != nullptr )
          {
            v13 = idEntity::CastTo(c: v12);
          }
          else
          {
            v13 = nullptr;
          }
          v14 = idEventArg::idEventArg(this: v16, data: result);
          idEventReceiver::PostEventMS(
            this: v13,
            ev: &EV_Activate,
            time: *(_DWORD *)&v14->type,
            arg1: (const idEventArg *)LODWORD(v14->value.v[1]));
        }
      }
      ++v5;
    }
    while ( v5 < SLODWORD(result[7].defaultPhysicsObj.current.localAxis.mat[1].x) );
  }
  return this;
}


// ========================================================================
// ?AnimEvent_HideMesh@idAnimated_AnimWeb@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82C03010
// RVA : 0x00C03010
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

idAnimated_AnimWeb *__fastcall idAnimated_AnimWeb::AnimEvent_HideMesh(
        idAnimated_AnimWeb *this,
        idAnimatedEntity *result,
        const idMD6Anim *animHandle,
        const char *meshName)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v9; // r30
  int MeshIndex; // r30

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  presentable = result->presentable;
  v9 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v9 != nullptr )
  {
    MeshIndex = idTreeAnimator::GetMeshIndex(this: v9, meshName);
    if ( MeshIndex >= 0 )
      idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result)->meshVisibility.list[MeshIndex] = false;
  }
  return this;
}


// ========================================================================
// ?OnActivate@idTarget_AnimWebChangeState@@EAAXPAVidEntity@@@Z
// EA  : 0x82C03098
// RVA : 0x00C03098
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void __fastcall idTarget_AnimWebChangeState::OnActivate(idTarget_AnimWebChangeState *this, idEntity *activator)
{
  int v3; // r28
  int v4; // r29
  int value; // r9
  idEntity *v6; // r3
  idEntity *v7; // r31

  v3 = 0;
  if ( this->targets.num > 0 )
  {
    v4 = 0;
    do
    {
      value = this->targets.list[v4].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v7 = idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      if ( v7 != nullptr && v7->ChangeAnimWebState_2(this: v7, a2: this->destAnimRef.data) == AWPATH_FAILED )
        idLib::Warning(fmt: "'%s' - Failed to change anim web state on entity '%s'.", this->name.data, v7->name.data);
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_AnimWebChangeStateVia@@EAAXPAVidEntity@@@Z
// EA  : 0x82C03178
// RVA : 0x00C03178
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void __fastcall idTarget_AnimWebChangeStateVia::OnActivate(idTarget_AnimWebChangeStateVia *this, idEntity *activator)
{
  int v3; // r28
  int v4; // r29
  int value; // r9
  idEntity *v6; // r3
  idEntity *v7; // r31

  v3 = 0;
  if ( this->targets.num > 0 )
  {
    v4 = 0;
    do
    {
      value = this->targets.list[v4].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v7 = idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      if ( v7 != nullptr
        && v7->ChangeAnimWebStateVia_2(this: v7, a2: this->viaAnimRef.data, a3: this->destAnimRef.data) == AWPATH_FAILED )
      {
        idLib::Warning(fmt: "'%s' - Failed to change anim web state on entity '%s'.", this->name.data, v7->name.data);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_AnimWebPause@@EAAXPAVidEntity@@@Z
// EA  : 0x82C03258
// RVA : 0x00C03258
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void __fastcall idTarget_AnimWebPause::OnActivate(idTarget_AnimWebPause *this, idEntity *activator)
{
  int v3; // r29
  int v4; // r31
  int value; // r9
  idEntity *v6; // r3
  idAnimatedEntity *v7; // r3
  idAnimatedEntity *v8; // r3

  v3 = 0;
  if ( this->targets.num > 0 )
  {
    v4 = 0;
    do
    {
      value = this->targets.list[v4].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v7 = (idAnimatedEntity *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      v8 = idAnimatedEntity::CastTo(c: v7);
      if ( v8 != nullptr )
        idAnimatedEntity::PauseAnimation(this: v8);
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_AnimWebUnpause@@EAAXPAVidEntity@@@Z
// EA  : 0x82C03300
// RVA : 0x00C03300
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void __fastcall idTarget_AnimWebUnpause::OnActivate(idTarget_AnimWebUnpause *this, idEntity *activator)
{
  int v3; // r29
  int v4; // r31
  int value; // r9
  idEntity *v6; // r3
  idAnimatedEntity *v7; // r3
  idAnimatedEntity *v8; // r3

  v3 = 0;
  if ( this->targets.num > 0 )
  {
    v4 = 0;
    do
    {
      value = this->targets.list[v4].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v7 = (idAnimatedEntity *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      v8 = idAnimatedEntity::CastTo(c: v7);
      if ( v8 != nullptr )
        idAnimatedEntity::UnpauseAnimation(this: v8);
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?Think@idAnimated_AnimWeb@@UAAXXZ
// EA  : 0x82C03518
// RVA : 0x00C03518
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void __fastcall idAnimated_AnimWeb::Think(idAnimated_AnimWeb *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idTreeAnimator *TreeAnimatorFromPresentable; // r28
  idPresentable *presentable; // r3
  idAnimator_AF *v6; // r3
  idAnimator_AF *v7; // r30
  char v8; // r11
  idPhysics *Physics; // r3
  int v10; // r3
  int *p_num; // r10
  _DWORD *v12; // r11
  int i; // ctr
  idPhysics *v14; // r3
  const idVec3 *v15; // r3
  char *y_low; // r10
  int z_low; // r9
  idPhysics *v18; // r3
  idPhysics *v19; // r3
  bool v20; // r28
  int v21; // r3
  idTreeAnimator *v22; // r3
  idAttachmentCollection *v23; // r18
  int v24; // r19
  int v25; // r24
  idAttachment *v26; // r3
  idPresentable *v27; // r3
  idPresentableAnimatedEntity *v28; // r3
  idPresentable *v29; // r26
  idTreeAnimator *TreeAnimator; // r27
  const idDeclMD6 *decl; // r21
  unsigned int v32; // r26
  idMD6LeafPlay *tree; // r17
  int GameMsPerFrame; // r16
  idParallelJobList *parallelJobList; // r15
  int PreviousPlayerGameTime; // r14
  int PlayerGameTime; // r3
  idAnimEventHandler *v38; // r26
  int v39; // r16
  const char *v40; // r15
  const char *v41; // r3
  int v42; // r3
  int v43; // r7
  int num; // r3
  int v45; // r3
  idResource *nextOnHashChain; // r29
  char *v47; // r30
  int v48; // r3
  __int64 v49; // r11
  __int64 v50; // r9
  float *v51; // [sp+8h] [-1A8h]
  float *v52; // [sp+Ch] [-1A4h]
  float *v53; // [sp+10h] [-1A0h]
  int v54; // [sp+14h] [-19Ch]
  int v55; // [sp+18h] [-198h]
  int v56; // [sp+1Ch] [-194h]
  int v57; // [sp+20h] [-190h]
  int v58; // [sp+24h] [-18Ch]
  int v59; // [sp+28h] [-188h]
  int v60; // [sp+2Ch] [-184h]
  int v61; // [sp+30h] [-180h]
  int v62; // [sp+34h] [-17Ch]
  int v63; // [sp+38h] [-178h]
  int v64; // [sp+3Ch] [-174h]
  int v65; // [sp+40h] [-170h]
  int v66; // [sp+44h] [-16Ch]
  int v67; // [sp+48h] [-168h]
  int v68; // [sp+4Ch] [-164h]
  int v69; // [sp+50h] [-160h]
  int v70; // [sp+58h] [-158h]
  int v71; // [sp+60h] [-150h]
  idDeclAnimWeb v72; // [sp+70h] [-140h] BYREF

  RD_EventBegin(name: "idAnimated_AnimWeb::Think");
  LODWORD(v2) = "idAnimated_AnimWeb::Think";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v72.name, pl: &pLog, gMask: v2, label: v3);
  if ( idEntity::UpdateDormant(this) )
  {
    idPLogScope::~idPLogScope(this: (idPLogScope *)&v72.name);
  }
  else
  {
    idAnimatedEntity::UpdateFrameCommands(this);
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    v6 = this->GetAF_2(this);
    v7 = v6;
    if ( !this->applyAnimDelta )
      goto LABEL_14;
    if ( v6 == nullptr )
      goto LABEL_11;
    if ( v6->isActive || (v8 = 0, v6->isClientAuthoritativeActive) )
      v8 = 1;
    if ( v8 != 0 )
    {
LABEL_14:
      if ( v6 != nullptr )
      {
        v20 = idEntity::GetPhysics(this) != (idPhysics *)&v6->physicsObj;
        v21 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        idAnimator_AF::Sync(this: v7, time: v21, runPhysics: v20);
      }
    }
    else
    {
LABEL_11:
      Physics = idEntity::GetPhysics(this);
      v10 = (int)Physics->GetAxis(this: Physics, a2: 0);
      p_num = &v72.subWebs.num;
      v12 = (_DWORD *)(v10 - 4);
      for ( i = 9; i != 0; --i )
        *++p_num = *++v12;
      v14 = idEntity::GetPhysics(this);
      v15 = v14->GetOrigin(this: v14, a2: 0);
      y_low = (char *)LODWORD(v15->y);
      z_low = LODWORD(v15->z);
      *((_DWORD *)&v72.idResource + 8) = LODWORD(v15->x);
      *(float *)&v72.resourceListPtr = 1.0;
      *(float *)&v72.resourceError = 1.0;
      v72.textSource = y_low;
      *(float *)&v72.networkID = 1.0;
      v72.textLength = z_low;
      idTreeAnimator::ApplyOriginDeltas(
        this: TreeAnimatorFromPresentable,
        axis: (const idMat3 *)&v72.subWebs.size,
        origin: (const idVec3 *)((char *)&v72.idResource + 32),
        outAxis: (idMat3 *)&v72.edges.size,
        outOrigin: (idVec3 *)&v72.nodes,
        extraScale: (const idVec3 *)&v72.resourceListPtr);
      v18 = idEntity::GetPhysics(this);
      v18->SetAxis(this: v18, a2: (const idMat3 *)&v72.edges.size, a3: -1);
      v19 = idEntity::GetPhysics(this);
      v19->SetOrigin(this: v19, a2: (const idVec3 *)&v72.nodes, a3: -1);
    }
    idEntity::RunPhysics(this);
    if ( this->useFaceManager )
    {
      v22 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
      idFaceMgr::Update(this: this->faceMgr, owner: (idAI2 *)this, ta: v22, focusPoint: &vec3_origin);
    }
    idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
    this->UpdateFX(this);
    idEntity::UpdatePVSAreas(this);
    v23 = this->GetAttachments_2(this);
    v72.trackedMemory = v23->attachments.num;
    if ( v72.trackedMemory > 0 )
    {
      v24 = 0;
      v25 = 0;
      do
      {
        v26 = idAttachmentCollection::ForIndex(this: v23, index: v24);
        if ( (*((_BYTE *)v26 + 104) & 0x80) != 0 )
        {
          v27 = v26->presentable;
          if ( v27 != nullptr )
          {
            v28 = v27->GetAnimatedEntityInterface(this: v27);
            v29 = v28;
            if ( v28 != nullptr )
            {
              TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: v28);
              idPresentable::UpdateModelTransform(this: v29);
              if ( TreeAnimator != nullptr )
              {
                decl = TreeAnimator->decl;
                if ( decl != nullptr )
                {
                  idDeclAnimWeb::FindModelIndex(
                    this: &v72,
                    result: (const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *)this->animWeb.decl,
                    decl: TreeAnimator->decl);
                  if ( SHIWORD(v72.__vftable) >= 0 )
                  {
                    v32 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
                    tree = (idMD6LeafPlay *)this->animWeb.modelAnimStates.list[SHIWORD(v72.__vftable)].tree;
                    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(
                                       this: &clientGame->gameTimeManager,
                                       type: GAMETIME_SCALED);
                    parallelJobList = gameLocal->parallelJobList;
                    PreviousPlayerGameTime = idClientGame::GetPreviousPlayerGameTime(this: clientGame);
                    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
                    idTreeAnimator::BlendTreeInternal(
                      this: TreeAnimator,
                      currentTime: PlayerGameTime,
                      previousTime: PreviousPlayerGameTime,
                      gameMsPerFrame: GameMsPerFrame,
                      ticksPerSec: v32,
                      tree,
                      parallelJobList,
                      localR: nullptr,
                      localS: v51,
                      localT: v52,
                      localU: v53,
                      a12: v54,
                      a13: v55,
                      a14: v56,
                      a15: v57,
                      a16: v58,
                      a17: v59,
                      a18: v60,
                      a19: v61,
                      a20: v62,
                      a21: v63,
                      a22: v64,
                      a23: v65,
                      a24: v66,
                      a25: v67,
                      a26: v68,
                      a27: v69,
                      a28: nullptr,
                      a29: v70,
                      a30: nullptr,
                      a31: v71,
                      a32: nullptr);
                    v38 = &this->attachmentAnimEventHandlers.list[v25];
                    v39 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
                    v40 = (const char *)idClientGame::GetPreviousPlayerGameTime(this: clientGame);
                    v41 = (const char *)idClientGame::GetPlayerGameTime(this: clientGame);
                    idAnimEventHandler::BuildAnimEventList(
                      this: v38,
                      decl,
                      tree,
                      curTime: v41,
                      previousTime: v40,
                      ticksPerSec: v39,
                      onlyEvents: nullptr,
                      onlyNumEvents: 0);
                    idEventReceiver::ProcessAnimEvents(this, handler: &this->attachmentAnimEventHandlers.list[v25]);
                    v42 = idClientGame::GetPlayerGameTime(this: clientGame);
                    idTreeAnimator::UpdateTime(this: TreeAnimator, time: v42);
                  }
                }
              }
            }
          }
        }
        ++v24;
        ++v25;
      }
      while ( v24 < v23->attachments.num );
    }
    idAnimated_AnimWeb::UpdateCollisionPieces(this, bounds: (idBounds *)((char *)&v72.idResource + 32), push: true);
    if ( this->useAmbientAnims
      && this->animWebParms.ambientAnims.num > 0
      && gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) >= this->ambientWaitTime )
    {
      v43 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + this->ambientWait;
      num = this->animWebParms.ambientAnims.num;
      this->ambientWaitTime = v43;
      v45 = RandomInt(max: num);
      this->ChangeAnimWebStateVia_2(
        this,
        a2: this->animWebParms.ambientAnims.list[v45].data,
        a3: this->animWebParms.initialWebNode.data);
    }
    if ( (int)v72.name.str >= 0 )
    {
      nextOnHashChain = v72.nextOnHashChain;
      v47 = (char *)v72.nextOnHashChain->idDecl::idResource::resourceListPtr + 16 * (int)v72.name.str;
      v48 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v49 = *((_QWORD *)v47 + 1);
      HIDWORD(v49) = *((_DWORD *)v47 + 1);
      LODWORD(v50) = v48 - v49;
      *((_QWORD *)v47 + 1) = v50;
      *((_DWORD *)nextOnHashChain + 8) = HIDWORD(v49);
    }
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$493193_0
// EA  : 0x82C03A5C
// RVA : 0x00C03A5C
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_493193_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 432 + 276));
}


// ========================================================================
// __unwind$493194
// EA  : 0x82C03A84
// RVA : 0x00C03A84
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_493194()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 432 + 120));
}


// ========================================================================
// ?Spawn@idAnimated_AnimWeb@@QAAXXZ
// EA  : 0x82C03B78
// RVA : 0x00C03B78
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void __fastcall idAnimated_AnimWeb::Spawn(idAnimated_AnimWeb *this)
{
  idBounds *v1; // r18
  int v2; // r17
  idEntityPhysicsCallbacks *p_physicsCallbacks; // r16
  int v4; // r15
  double v5; // fp31
  double v6; // fp30
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  char *v10; // r19
  int v11; // r11
  int v12; // r11
  idIndex<short,enum invalidJointIndex_t> *v13; // r4
  char v14; // r10
  __int16 size_high; // r9
  int v16; // r27
  int v17; // r25
  int v18; // r26
  int v19; // r29
  int v20; // r28
  int v21; // r30
  int v22; // r29
  int v23; // r30
  idEventDef **v24; // r25
  const char *v25; // r29
  const char *v26; // r28
  char *data; // r27
  int v28; // r26
  const idDeclAnimWeb *webDecl; // r22
  idAnimStack *v30; // r3
  const idDeclAnimWeb *v31; // r10
  idGameTimeManager *v32; // r3
  idAnimStack *v33; // r3
  BOOL useFaceManager; // r10
  idAttachment *v35; // r3
  idFaceMgr *v36; // r3
  idAttachment *num; // r11
  idVec3 *v38; // r21
  int v39; // r26
  int v40; // r20
  const char *v41; // r23
  idQuat *v42; // r22
  const char **p_physicsObj; // r27
  idAnimated_AnimWeb::collisionPiece_t *v44; // r28
  int list; // r11
  const char *size; // r29
  const idDeclEntityDef *nextInHash; // r5
  idAttachmentCollection *p_attachments; // r30
  const idAttachment *v49; // r3
  idEntityPtr<idEntity> *p_entity; // r3
  const char *callbacks; // r30
  idEntity *v52; // r3
  idEntity *v53; // r5
  idPresentable *v54; // r4
  idInventoryItem *v55; // r3
  int v56; // r11
  int v57; // r8
  const idDeclInventory::idAttachmentInfo *v58; // r7
  int v59; // r9
  int v60; // r11
  idAnimated_AnimWeb::collisionPieceStage_t **v61; // r10
  int v62; // r11
  int v63; // r11
  int v64; // r30
  int v65; // r11
  idPresentable *v66; // r11
  idPresentable *v67; // r11
  int v68; // r8
  const tagData_t *Tag; // r29
  __int16 v70; // r11
  float *p_z; // r10
  int v72; // ctr
  _DWORD *v73; // r11
  double v74; // fp10
  double v75; // fp9
  const idBounds *v76; // r4
  int *v77; // r10
  idIndex<short,enum invalidJointIndex_t> *v78; // r11
  int i; // ctr
  idClipModel *v80; // r3
  idClipModel *v81; // r3
  idClipModel *v82; // r3
  idClipModel *v83; // r3
  const char *v84; // r29
  int v85; // r3
  idContents *p_num; // r3
  const char *v87; // r30
  int v88; // r3
  int j; // r30
  const char *v90; // [sp+8h] [-858h]
  bool v91; // [sp+Bh] [-855h]
  const char *v92; // [sp+Ch] [-854h]
  bool v93; // [sp+Fh] [-851h]
  int v94; // [sp+10h] [-850h]
  bool v95; // [sp+13h] [-84Dh]
  int v96; // [sp+14h] [-84Ch]
  bool v97; // [sp+17h] [-849h]
  int v98; // [sp+18h] [-848h]
  int v99; // [sp+18h] [-848h]
  int v100; // [sp+1Ch] [-844h]
  int v101; // [sp+1Ch] [-844h]
  int v102; // [sp+20h] [-840h]
  int v103; // [sp+20h] [-840h]
  int v104; // [sp+24h] [-83Ch]
  int v105; // [sp+24h] [-83Ch]
  int v106; // [sp+28h] [-838h]
  int v107; // [sp+28h] [-838h]
  int v108; // [sp+2Ch] [-834h]
  int v109; // [sp+2Ch] [-834h]
  int v110; // [sp+30h] [-830h]
  int v111; // [sp+30h] [-830h]
  int v112; // [sp+34h] [-82Ch]
  int v113; // [sp+34h] [-82Ch]
  int v114; // [sp+38h] [-828h]
  int v115; // [sp+38h] [-828h]
  int v116; // [sp+3Ch] [-824h]
  int v117; // [sp+3Ch] [-824h]
  int v118; // [sp+40h] [-820h]
  int v119; // [sp+40h] [-820h]
  int v120; // [sp+44h] [-81Ch]
  int v121; // [sp+44h] [-81Ch]
  int v122; // [sp+48h] [-818h]
  int v123; // [sp+48h] [-818h]
  int v124; // [sp+4Ch] [-814h]
  int v125; // [sp+4Ch] [-814h]
  int v126; // [sp+50h] [-810h]
  int v127; // [sp+50h] [-810h]
  int v128; // [sp+58h] [-808h]
  int v129; // [sp+58h] [-808h]
  int v130; // [sp+60h] [-800h]
  int v131; // [sp+60h] [-800h]
  int v132; // [sp+68h] [-7F8h]
  int v133; // [sp+68h] [-7F8h]
  idHandle<int,enum invalidAttachment_t,-1> v134; // [sp+70h] [-7F0h] BYREF
  idIndex<short,enum invalidJointIndex_t> *v135; // [sp+74h] [-7ECh]
  idAttachmentCollection v136; // [sp+78h] [-7E8h] BYREF
  float v137[6]; // [sp+90h] [-7D0h] BYREF
  idAttachmentCollection v138; // [sp+A8h] [-7B8h] BYREF
  char v139; // [sp+BCh] [-7A4h] BYREF
  idAttachmentCollection v140; // [sp+D0h] [-790h] BYREF
  const char *v141; // [sp+E4h] [-77Ch]
  int v142; // [sp+E8h] [-778h]
  char v143; // [sp+ECh] [-774h] BYREF
  int v144; // [sp+FCh] [-764h] BYREF
  idBounds v145; // [sp+100h] [-760h] BYREF
  idAnimatorParms_AnimWeb v146; // [sp+120h] [-740h] BYREF
  idTraceModel v147; // [sp+1B0h] [-6B0h] BYREF

  TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v10 = (char *)TreeAnimatorFromPresentable;
  v135 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( this->applyAnimDelta )
  {
    idTreeAnimator::SetRemoveOriginRotation(this: (idTreeAnimator *)v10, removeRotation: true);
    idTreeAnimator::SetRemoveOriginRotation(this: (idTreeAnimator *)v10, removeRotation: true);
  }
  else
  {
    idTreeAnimator::SetRemoveOriginRotation(this: (idTreeAnimator *)v10, removeRotation: false);
    idTreeAnimator::SetRemoveOriginRotation(this: (idTreeAnimator *)v10, removeRotation: false);
  }
  *((_DWORD *)v10 + 54) = 2;
  if ( this->overrideUsingDeferredPositions )
    v10[72] = 0;
  if ( this->lightFromJointPositions )
  {
    v11 = *((_DWORD *)v10 + 508);
    v12 = v11 != 0 ? *(_DWORD *)(v11 + 60) : 0;
    v13 = v12 != 0 ? *(idIndex<short,enum invalidJointIndex_t> **)(v12 + 212) : nullptr;
    if ( v13 != nullptr )
    {
      idMD6Skel::GetJointIndex(
        this: (idMD6Skel *)&v136.attachments.size,
        result: v13,
        name: this->skipJointForLighting.data);
      v14 = v10[223];
      size_high = HIWORD(v136.attachments.size);
      v10[2164] |= 0x10u;
      v10[223] = v14 | 0x40;
      *((_WORD *)v10 + 1027) = size_high;
    }
  }
  if ( this->sceneModel )
    v10[220] |= 4u;
  v16 = 0;
  v17 = *(_DWORD *)(*((_DWORD *)v10 + 508) + 60);
  if ( *(int *)(v17 + 152) > 0 )
  {
    v18 = 0;
    do
    {
      v19 = 0;
      v20 = *(_DWORD *)(v18 + *(_DWORD *)(v17 + 148));
      if ( this->hideMeshes.num > 0 )
      {
        v21 = 0;
        do
        {
          if ( idStr::Icmp(s1: *(const char **)(v20 + 4), s2: this->hideMeshes.list[v21].data) == 0 )
            *(_BYTE *)(*((_DWORD *)v10 + 509) + v16) = 0;
          ++v19;
          ++v21;
        }
        while ( v19 < this->hideMeshes.num );
      }
      v22 = 0;
      if ( this->showMeshes.num > 0 )
      {
        v23 = 0;
        do
        {
          if ( idStr::Icmp(s1: *(const char **)(v20 + 4), s2: this->showMeshes.list[v23].data) == 0 )
            *(_BYTE *)(*((_DWORD *)v10 + 509) + v16) = 1;
          ++v22;
          ++v23;
        }
        while ( v22 < this->showMeshes.num );
      }
      ++v16;
      v18 += 4;
    }
    while ( v16 < *(_DWORD *)(v17 + 152) );
  }
  v138.attachments.size = 0;
  v139 = 0;
  v138.parent = (idAnimatedEntity *)20;
  *(_DWORD *)&v138.attachments.granularity = &v139;
  v142 = 20;
  v141 = &v143;
  v140.parent = nullptr;
  v143 = 0;
  if ( (unsigned __int8)idAnimator_AnimWeb::DecomposeAnimRef(
                          this: &this->animWeb,
                          animRef: this->animWebParms.initialWebNode.data,
                          subWebName: (idStr *)&v138.attachments.size,
                          stateName: (idStr *)&v140.parent) == 0 )
  {
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
    idLib::Error(
      fmt: "idAnimated_AnimWeb::Spawn - '%s' has an invalid initial node '%s'",
      this->name.data,
      this->animWebParms.initialWebNode.data);
  }
  v24 = &idEventDef::eventDefList[3154];
  v25 = v141;
  v26 = *(const char **)&v138.attachments.granularity;
  data = this->name.data;
  v28 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  webDecl = this->animWebParms.webDecl;
  v30 = this->GetAnimStack_2(this);
  idAnimatorParms_AnimWeb::idAnimatorParms_AnimWeb(
    this: &v146,
    animStack_: v30,
    name_: data,
    blendOp_: BOP_LERP,
    originBlend_: ORIGINBLEND_BRANCH,
    weightGroup_: MD6_WEIGHTGROUP_ALL,
    filterGroup_: MD6_WEIGHTGROUP_ALL,
    alpha_: 1.0,
    webDecl_: v31,
    initialSubWebName_: v90,
    initialStateName_: v92,
    curTime_: v94,
    a13: v96,
    a14: v98,
    a15: v100,
    a16: v102,
    a17: v104,
    a18: v106,
    a19: v108,
    a20: v110,
    a21: v112,
    a22: v114,
    a23: v116,
    a24: v118,
    a25: v120,
    a26: v122,
    a27: v124,
    a28: v126,
    a29: webDecl,
    a30: v128,
    a31: v26,
    a32: v130,
    a33: v25,
    a34: v132,
    a35: v28);
  v32 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_Base::Init(this: &this->animWeb, gametimeManager: v32, parms: &v146);
  v33 = this->GetAnimStack_2(this);
  idAnimator_Base::SetEnabled(this: &this->animWeb, animStack: v33, enabled: true);
  useFaceManager = this->useFaceManager;
  *(_DWORD *)&v136.attachments.granularity = &mem;
  if ( useFaceManager )
  {
    if ( this->faceMgr == nullptr )
    {
      v35 = (idAttachment *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                              size: 0x794u,
                              tag: TAG_NEW,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
      v136.attachments.list = v35;
      if ( v35 != nullptr )
        v36 = idFaceMgr::idFaceMgr(this: (idFaceMgr *)v35);
      else
        v36 = nullptr;
      this->faceMgr = v36;
    }
    idFaceMgr::Init(
      this: this->faceMgr,
      owner: this,
      ta: (idTreeAnimator *)v10,
      mood: MOOD_NONE,
      voiceChannel: SND_CHANNEL_VOICE,
      enableMoodAnimation: true,
      enableLipSyncAnimation: true,
      enableGestureAnimation: true,
      enableEyeTracking: v91,
      useFaceSetupEyeTracking_: v93,
      enableBlinking: v95,
      enableLidDeformation: v97,
      a13: v99,
      a14: v101,
      a15: v103,
      a16: v105,
      a17: v107,
      a18: v109,
      a19: v111,
      a20: v113,
      a21: v115,
      a22: v117,
      a23: v119,
      a24: v121,
      a25: v123,
      a26: v125,
      a27: v127,
      a28: 0,
      a29: v129,
      a30: false,
      a31: v131,
      a32: 1u,
      a33: v133,
      a34: 1);
  }
  num = (idAttachment *)this->startingAttachments.num;
  this->attachments.parent = this;
  v136.attachments.list = num;
  if ( num != nullptr )
  {
    v38 = nullptr;
    v136.attachments.list = num;
    if ( (int)num > 0 )
    {
      v39 = 0;
      v40 = -1;
      v41 = "No valid attachment specified for '%s'";
      v42 = (idQuat *)"Could not find entity '%s' to attach.";
      p_physicsObj = idDeclInventory::equipSlotTagNames;
      do
      {
        v44 = (idAnimated_AnimWeb::collisionPiece_t *)((char *)this->startingAttachments.list + v39);
        list = (int)v44->stages.list;
        if ( (int)v44->stages.list <= 0 || list >= 15 )
          size = (const char *)v44->stages.size;
        else
          size = idDeclInventory::equipSlotTagNames[list];
        v134.value = -1;
        nextInHash = (const idDeclEntityDef *)v44->physicsObj.nextInHash;
        if ( nextInHash != nullptr )
        {
          p_attachments = &this->attachments;
          v134.value = idAttachmentCollection::AddAttachment(
                         this: &v136,
                         result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
                         entityDef: nextInHash,
                         tag: size,
                         forceReplicationFlags: -1)->value;
          if ( v134.value == -1 )
          {
            idLib::Error(
              fmt: "idAnimated_AnimWeb::Spawn - '%s' failed to spawn attachment entity '%s'",
              this->name.data,
              (const char *)v44->physicsObj.nextInHash->type);
            goto _LN446_0;
          }
          v49 = idAttachmentCollection::Get(this: &this->attachments, handle: &v134);
          if ( v49 != nullptr && v49->handle.value != -1 )
          {
            p_entity = &v49->entity;
            if ( gameLocal->spawnIds.ptr[p_entity->spawnId.value & 0x1FFF] == p_entity->spawnId.value >> 13
              && v44->physicsObj.clip != nullptr )
            {
              callbacks = (const char *)v44->physicsObj.callbacks;
              v52 = idEntityPtr<idEntity const>::operator->(this: p_entity);
              idEntity::SetName(this: v52, newName: callbacks);
            }
          }
        }
        else if ( v44->physicsObj.clip != nullptr )
        {
          v53 = gameLocal->FindEntity(this: gameLocal, a2: v44->physicsObj.callbacks);
          if ( v53 != nullptr )
            v134.value = idAttachmentCollection::AddAttachment(
                           this: (idAttachmentCollection *)&v136.attachments.size,
                           result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
                           ent: v53,
                           tag: size)->value;
          else
            idLib::Warning(fmt: "Could not find entity '%s' to attach.", v44->physicsObj.callbacks);
        }
        else if ( v44->physicsObj.contactPhysicsIds.num != 0 )
        {
          v54 = this->presentable;
          if ( v54 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v54 = this->presentable;
          }
          v55 = idInventoryCollection::GiveItem(
                  this: &this->inventory,
                  owner: v54,
                  decl: (const idDeclInventory *)v44->physicsObj.contactPhysicsIds.num,
                  count: 1,
                  forceCount: false,
                  canIntro: false);
          v56 = v44->physicsObj.contactPhysicsIds.size;
          if ( v56 != 0 )
          {
            v134.value = idAttachmentCollection::AddAttachment(
                           this: (idAttachmentCollection *)&v138.attachments.num,
                           result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
                           modelName: *(const char **)(v56 + 8),
                           tag: size)->value;
          }
          else if ( v55 != nullptr )
          {
            v57 = v44->physicsObj.contactPhysicsIds.num;
            if ( *(_BYTE *)(v57 + 278) == 0 )
            {
              v58 = nullptr;
              v59 = 0;
              v140.attachments.num = *(_DWORD *)(v57 + 148);
              if ( v140.attachments.num > 0 )
              {
                v60 = 0;
                while ( 1 )
                {
                  v61 = (idAnimated_AnimWeb::collisionPieceStage_t **)(*(_DWORD *)(v57 + 144) + v60);
                  if ( *v61 == v44->stages.list && v61[1] != nullptr )
                    break;
                  ++v59;
                  v60 += 40;
                  if ( v59 >= v140.attachments.num )
                    goto LABEL_73;
                }
                v58 = (const idDeclInventory::idAttachmentInfo *)(*(_DWORD *)(v57 + 144) + v60);
              }
LABEL_73:
              v134.value = idAttachmentCollection::AddAttachment(
                             this: &v138,
                             result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
                             item: v55,
                             tagName: idDeclInventory::equipSlotTagNames[(int)v44->stages.list],
                             fxAttachInfo: v58)->value;
            }
          }
        }
        else
        {
          v62 = v44->physicsObj.contactPhysicsIds.size;
          if ( v62 != 0 )
          {
            v134.value = idAttachmentCollection::AddAttachment(
                           this: &v140,
                           result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
                           modelName: *(const char **)(v62 + 8),
                           tag: size)->value;
          }
          else if ( *(_DWORD *)&v44->physicsObj.contactPhysicsIds.granularity != 0 )
          {
            v134.value = idAttachmentCollection::AddAttachment(
                           this: (idAttachmentCollection *)&v136.attachments.num,
                           result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
                           modelName: *((const char **)&v44->physicsObj + 17),
                           tag: size)->value;
          }
          else
          {
            idLib::Warning(fmt: "No valid attachment specified for '%s'", this->name.data);
          }
        }
        v63 = (int)v44->stages.list;
        if ( (int)v44->stages.list > 0 && v63 < 15 )
          this->equipSlots[v63] = v134;
        v38 = (idVec3 *)((char *)v38 + 1);
        v39 += 112;
      }
      while ( (int)v38 < this->startingAttachments.num );
    }
  }
  v64 = this->attachments.attachments.num;
  if ( v64 <= this->attachmentAnimEventHandlers.size
    || (unsigned __int8)idList<idAnimEventHandler,5>::Resize(
                          this: &this->attachmentAnimEventHandlers,
                          newsize: this->attachments.attachments.num) != 0 )
  {
    v65 = this->attachmentAnimEventHandlers.size;
    if ( v64 < v65 )
      v65 = v64;
    this->attachmentAnimEventHandlers.num = v65;
  }
  v4 = 0;
  if ( this->collisionPieces.num > 0 )
  {
    v6 = -1.0;
    v5 = 0.0;
    p_physicsCallbacks = &this->physicsCallbacks;
    v2 = 0;
    v40 = -2091122688;
    v39 = -2088894464;
    v10 = "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag";
    v1 = &bounds_zero;
    v38 = &vec3_origin;
    v42 = &quat_identity;
    do
    {
      v44 = &this->collisionPieces.list[v2];
      p_physicsObj = (const char **)&v44->physicsObj;
      idPhysics::InitPhysics(
        this: &v44->physicsObj,
        clip_: (idClip *)(*(_DWORD *)(v39 + 17592) + 10688),
        callbacks_: p_physicsCallbacks,
        entityNumber_: this->entityNumber);
      v66 = this->presentable;
      if ( v66 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v66 = this->presentable;
      }
      (*((void (__fastcall **)(const char **, idVec3 *, int))*p_physicsObj + 12))(
        a1: p_physicsObj,
        a2: &v66->origin,
        a3: -1);
      v67 = this->presentable;
      if ( v67 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v67 = this->presentable;
      }
      (*((void (__fastcall **)(const char **, idMat3 *, int))*p_physicsObj + 13))(
        a1: p_physicsObj,
        a2: &v67->axis,
        a3: -1);
      v68 = v44->stages.num;
      v41 = nullptr;
      v44->pushFlags = 0;
      v44->curStage = 0;
      if ( v68 > 0 )
      {
        v24 = nullptr;
        do
        {
          p_attachments = (idAttachmentCollection *)((char *)v24 + (unsigned int)v44->stages.list);
          if ( p_attachments->parent != nullptr )
          {
_LN446_0:
            Tag = idPropsCollection::GetTag(
                    this: (idPropsCollection *)(*(_DWORD *)&v135[1016].value + 352),
                    propName: *(const char **)(v40 - 248),
                    tagName: (const char *)p_attachments[1].attachments.list);
            if ( Tag->parentJoint.value == 0xFFFF )
            {
              idLib::Error(
                fmt: "idAnimated_AnimWeb::Spawn - '%s' has invalid tag '%s' on collision piece %d",
                this->name.data,
                (const char *)p_attachments[1].attachments.list,
                v4);
              _LN447_0();
              return;
            }
            v70 = HIWORD(idTreeAnimator::GetJointIndex(
                           this: (idTreeAnimator *)&v136,
                           result: v135,
                           jointHandle: &Tag->parentJoint)->__vftable);
            v136.attachments.num = (int)&Tag->rot;
            HIWORD(p_attachments[4].parent) = v70;
            *(float *)&p_attachments[5].parent = Tag->trans.x;
            *(float *)&p_attachments[6].attachments.list = Tag->trans.y;
            *(float *)&p_attachments[6].attachments.num = Tag->trans.z;
            *(float *)&p_attachments[5].attachments.list = Tag->rot.x;
            *(float *)&p_attachments[5].attachments.num = Tag->rot.y;
            *(float *)&p_attachments[5].attachments.size = Tag->rot.z;
            *(float *)&p_attachments[5].attachments.granularity = Tag->rot.w;
          }
          else
          {
            HIWORD(p_attachments[4].parent) = HIWORD(idTreeAnimator::GetJointIndex(
                                                       this: (idTreeAnimator *)&v136.attachments.size,
                                                       result: v135,
                                                       jointName: *(const char **)&p_attachments[2].attachments.granularity)->__vftable);
            *(float *)&p_attachments[5].attachments.list = v42->x;
            *(float *)&p_attachments[5].attachments.num = v42->y;
            *(float *)&p_attachments[5].attachments.size = v42->z;
            *(float *)&p_attachments[5].attachments.granularity = v42->w;
            *(float *)&p_attachments[5].parent = v38->x;
            *(float *)&p_attachments[6].attachments.list = v38->y;
            *(float *)&p_attachments[6].attachments.num = v38->z;
          }
          if ( HIBYTE(p_attachments[4].attachments.size) != 0 )
          {
            v147.offset.x = v5;
            p_z = &v147.offset.z;
            v147.offset.y = v5;
            v147.offset.z = v5;
            memset(&v147.type, 0, 20);
            v72 = 6;
            v73 = (_DWORD *)&v1[-1].b[1].z;
            do
            {
              *++p_z = *(float *)++v73;
              --v72;
            }
            while ( v72 != 0 );
            v147.radius = v5;
            v147.pad[1] = 0;
            v147.isConvex = false;
            v147.pad[0] = 0;
            v147.pad[2] = 0;
            if ( (float)((float)(*(float *)&p_attachments->attachments.granularity
                               * *(float *)&p_attachments->attachments.granularity)
                       + (float)((float)(*(float *)&p_attachments->attachments.num
                                       * *(float *)&p_attachments->attachments.num)
                               + (float)(*(float *)&p_attachments->attachments.size
                                       * *(float *)&p_attachments->attachments.size))) <= v5 )
            {
              v77 = &v144;
              v78 = v135 + 44;
              for ( i = 6; i != 0; --i )
              {
                v78 += 2;
                *++v77 = *(_DWORD *)&v78->value;
              }
              v76 = &v145;
            }
            else
            {
              v74 = (float)(*(float *)&p_attachments->attachments.size * (float)v6);
              v75 = (float)(*(float *)&p_attachments->attachments.granularity * (float)v6);
              v137[0] = *(float *)&p_attachments->attachments.num * (float)v6;
              v137[1] = v74;
              v76 = (const idBounds *)v137;
              v137[2] = v75;
              v137[3] = *(float *)&p_attachments->attachments.num;
              v137[4] = *(float *)&p_attachments->attachments.size;
              v137[5] = *(float *)&p_attachments->attachments.granularity;
            }
            idTraceModel::SetupBox(this: &v147, boxBounds: v76);
            v80 = (idClipModel *)idMem::AllocWithLocation(
                                   this: *(idMem **)&v136.attachments.granularity,
                                   location: v10,
                                   size: 0xD8u,
                                   tag: TAG_CLIPMODEL,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
            v136.attachments.num = (int)v80;
            if ( v80 != nullptr )
              v81 = idClipModel::idClipModel(
                      this: v80,
                      clip: (idClip *)(*(_DWORD *)(v39 + 17592) + 10688),
                      trm: &v147,
                      numTraceModels: 1,
                      material: this->clipModelInfo.overrideClipMaterial);
            else
              v81 = nullptr;
            *(_DWORD *)&p_attachments[4].attachments.granularity = v81;
          }
          else
          {
            v82 = (idClipModel *)idMem::AllocWithLocation(
                                   this: *(idMem **)&v136.attachments.granularity,
                                   location: v10,
                                   size: 0xD8u,
                                   tag: TAG_CLIPMODEL,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
            v136.attachments.num = (int)v82;
            if ( v82 != nullptr )
              v83 = idClipModel::idClipModel(
                      this: v82,
                      clip: (idClip *)(*(_DWORD *)(v39 + 17592) + 10688),
                      name: (const char *)p_attachments->attachments.list,
                      overrideClipMaterial: this->clipModelInfo.overrideClipMaterial);
            else
              v83 = nullptr;
            *(_DWORD *)&p_attachments[4].attachments.granularity = v83;
          }
          if ( (const char *)v44->curStage == v41 )
          {
            (*((void (__fastcall **)(const char **, _DWORD, double))*p_physicsObj + 1))(
              a1: p_physicsObj,
              a2: *(_DWORD *)&p_attachments[4].attachments.granularity,
              a3: 1.0);
            v84 = *p_physicsObj;
            v85 = idContents::ToFlags(this: (idContents *)&p_attachments[4]);
            (*((void (__fastcall **)(const char **, int, int))v84 + 8))(a1: p_physicsObj, a2: v85, a3: -1);
            p_num = (idContents *)&p_attachments[4].attachments.num;
            v87 = *p_physicsObj;
            v88 = idContents::ToFlags(this: p_num);
            (*((void (__fastcall **)(const char **, int, int))v87 + 6))(a1: p_physicsObj, a2: v88, a3: -1);
          }
          ++v41;
          v24 += 32;
        }
        while ( (int)v41 < v44->stages.num );
      }
      ++v4;
      ++v2;
    }
    while ( v4 < this->collisionPieces.num );
    v10 = (char *)v135;
  }
  if ( this->soundJoint.len != 0 )
    this->soundJointIndex.value = HIWORD(idTreeAnimator::GetJointIndex(
                                           this: (idTreeAnimator *)&v136,
                                           result: (idIndex<short,enum invalidJointIndex_t> *)v10,
                                           jointName: this->soundJoint.data)->__vftable);
  for ( j = 0; j < this->collisionPieces.num; ++j )
    idAnimated_AnimWeb::SetStage(this, pieceNum: j, stageIndex: 0, updateCollision: false);
  idAnimated_AnimWeb::UpdateCollisionPieces(this, bounds: &v145, push: false);
  idEntity::BecomeActive(this, flags: 5);
  idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
  idAnimated_AnimWeb::UpdateCollisionPieces(this, bounds: &v145, push: false);
  idAnimatorParms_AnimWeb::~idAnimatorParms_AnimWeb(this: &v146);
  idStr::FreeData(this: (idStr *)&v140.parent);
  idStr::FreeData(this: (idStr *)&v138.attachments.size);
}


// ========================================================================
// $LN447_0
// EA  : 0x82C04788
// RVA : 0x00C04788
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _LN447_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2144 + 176));
}


// ========================================================================
// __unwind$493626_0
// EA  : 0x82C047B0
// RVA : 0x00C047B0
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_493626_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2144 + 224));
}


// ========================================================================
// __unwind$493627_0
// EA  : 0x82C047D8
// RVA : 0x00C047D8
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_493627_0()
{
  int v0; // r12

  idAnimatorParms_AnimWeb::~idAnimatorParms_AnimWeb(this: (idAnimatorParms_AnimWeb *)(v0 - 2144 + 288));
}


// ========================================================================
// __unwind$493628_0
// EA  : 0x82C04800
// RVA : 0x00C04800
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void __fastcall _unwind_493628_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 2144 + 120), tag: a2);
}


// ========================================================================
// __unwind$493629_0
// EA  : 0x82C04828
// RVA : 0x00C04828
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_493629_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 2144 + 124), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$493630_0
// EA  : 0x82C04854
// RVA : 0x00C04854
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_493630_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 2144 + 124), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ??0idAnimated_AnimWeb@@QAA@XZ
// EA  : 0x82C048F0
// RVA : 0x00C048F0
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

idAnimated_AnimWeb *__fastcall idAnimated_AnimWeb::idAnimated_AnimWeb(idAnimated_AnimWeb *this)
{
  idAnimatedEntity **p_parent; // r10
  int i; // ctr

  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idAnimated_AnimWeb_vtbl *)&idAnimated_AnimWeb::`vftable';
  this->animWebParms.webDecl = nullptr;
  this->animWebParms.initialWebNode.allocedAndFlag = 20;
  this->animWebParms.initialWebNode.len = 0;
  this->animWebParms.initialWebNode.data = this->animWebParms.initialWebNode.baseBuffer;
  this->animWebParms.initialWebNode.baseBuffer[0] = 0;
  this->animWebParms.ambientAnims.granularity = 0;
  this->animWebParms.ambientAnims.memTag = 5;
  this->animWebParms.ambientAnims.listStatic = 0;
  this->animWebParms.ambientAnims.list = nullptr;
  this->animWebParms.ambientAnims.size = 0;
  this->animWebParms.ambientAnims.num = 0;
  this->startingAttachments.granularity = 0;
  this->startingAttachments.memTag = 5;
  this->startingAttachments.listStatic = 0;
  this->startingAttachments.list = nullptr;
  this->startingAttachments.size = 0;
  this->startingAttachments.num = 0;
  this->applyAnimDelta = false;
  this->useAmbientAnims = false;
  this->ambientWaitTime = 0;
  this->ambientWait = 800;
  this->useFaceManager = false;
  this->sceneModel = false;
  this->overrideUsingDeferredPositions = false;
  this->crushDamage = nullptr;
  this->pushDamage = nullptr;
  this->soundJoint.allocedAndFlag = 20;
  this->soundJoint.data = this->soundJoint.baseBuffer;
  this->soundJoint.len = 0;
  this->soundJoint.baseBuffer[0] = 0;
  this->soundJointIndex.value = -1;
  this->collisionPieces.granularity = 0;
  this->collisionPieces.memTag = 5;
  this->collisionPieces.listStatic = 0;
  this->collisionPieces.list = nullptr;
  this->collisionPieces.size = 0;
  this->collisionPieces.num = 0;
  this->subtitleName.index = -1;
  idAnimator_AnimWeb::idAnimator_AnimWeb(this: &this->animWeb);
  `eh vector constructor iterator'(
    ptr: this->channelAnimators,
    size: 0x60u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idAnimator_Channel::idAnimator_Channel,
    pDtor: (void (__fastcall *)(void *))idAnimator_Channel::~idAnimator_Channel);
  idAnimator_Paused::idAnimator_Paused(this: &this->pausedAnimator);
  this->faceMgr = nullptr;
  idMQBuffer::idMQBuffer(this: &this->attachments);
  p_parent = &this->attachments.parent;
  for ( i = 15; i != 0; --i )
    *++p_parent = (idAnimatedEntity *)-1;
  idInventoryCollection::idInventoryCollection(this: &this->inventory);
  this->attachmentAnimEventHandlers.granularity = 0;
  this->attachmentAnimEventHandlers.memTag = 5;
  this->attachmentAnimEventHandlers.listStatic = 0;
  this->attachmentAnimEventHandlers.list = nullptr;
  this->attachmentAnimEventHandlers.size = 0;
  this->attachmentAnimEventHandlers.num = 0;
  this->lightFromJointPositions = false;
  this->skipJointForLighting.allocedAndFlag = 20;
  this->skipJointForLighting.len = 0;
  this->skipJointForLighting.data = this->skipJointForLighting.baseBuffer;
  this->skipJointForLighting.baseBuffer[0] = 0;
  this->hideMeshes.granularity = 0;
  this->hideMeshes.memTag = 5;
  this->hideMeshes.listStatic = 0;
  this->hideMeshes.list = nullptr;
  this->hideMeshes.size = 0;
  this->hideMeshes.num = 0;
  this->showMeshes.granularity = 0;
  this->showMeshes.memTag = 5;
  this->showMeshes.listStatic = 0;
  this->showMeshes.list = nullptr;
  this->showMeshes.size = 0;
  this->showMeshes.num = 0;
  *(_BYTE *)&this->flags |= 0x40u;
  return this;
}


// ========================================================================
// __unwind$494369
// EA  : 0x82C04AF0
// RVA : 0x00C04AF0
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494369()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$494384_0
// EA  : 0x82C04B18
// RVA : 0x00C04B18
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494384_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 84) + 4));
}


// ========================================================================
// __unwind$494370
// EA  : 0x82C04B44
// RVA : 0x00C04B44
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494370()
{
  int v0; // r12

  idAnimated_AnimWeb::animWebParms_t::~animWebParms_t(this: (idAnimated_AnimWeb::animWebParms_t *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                                 + 5200));
}


// ========================================================================
// __unwind$494371
// EA  : 0x82C04B70
// RVA : 0x00C04B70
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494371()
{
  int v0; // r12

  idList<idAnimated_AnimWeb::attachment_t,5>::~idList<idAnimated_AnimWeb::attachment_t,5>(this: (idList<idAnimated_AnimWeb::attachment_t,5> *)(*(_DWORD *)(v0 - 144 + 164) + 5252));
}


// ========================================================================
// __unwind$494372
// EA  : 0x82C04B9C
// RVA : 0x00C04B9C
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494372()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 5292));
}


// ========================================================================
// __unwind$494373
// EA  : 0x82C04BC8
// RVA : 0x00C04BC8
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494373()
{
  int v0; // r12

  idList<idAnimated_AnimWeb::collisionPiece_t,5>::~idList<idAnimated_AnimWeb::collisionPiece_t,5>(this: (idList<idAnimated_AnimWeb::collisionPiece_t,5> *)(*(_DWORD *)(v0 - 144 + 164) + 5328));
}


// ========================================================================
// __unwind$494374
// EA  : 0x82C04BF4
// RVA : 0x00C04BF4
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494374()
{
  int v0; // r12

  idAnimator_AnimWeb::~idAnimator_AnimWeb(this: (idAnimator_AnimWeb *)(*(_DWORD *)(v0 - 144 + 164) + 5348));
}


// ========================================================================
// __unwind$494375
// EA  : 0x82C04C20
// RVA : 0x00C04C20
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494375()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 5996),
    size: 0x60u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idAnimator_Channel::~idAnimator_Channel);
}


// ========================================================================
// __unwind$494376
// EA  : 0x82C04C5C
// RVA : 0x00C04C5C
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494376()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 144 + 164) + 6188));
}


// ========================================================================
// __unwind$494377
// EA  : 0x82C04C88
// RVA : 0x00C04C88
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494377()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 6244));
}


// ========================================================================
// __unwind$494378
// EA  : 0x82C04CB4
// RVA : 0x00C04CB4
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494378()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 6324));
}


// ========================================================================
// __unwind$494379
// EA  : 0x82C04CE0
// RVA : 0x00C04CE0
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494379()
{
  int v0; // r12

  idList<idAnimEventHandler,5>::Clear(this: (idList<idAnimEventHandler,5> *)(*(_DWORD *)(v0 - 144 + 164) + 7124));
}


// ========================================================================
// __unwind$494380
// EA  : 0x82C04D0C
// RVA : 0x00C04D0C
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494380()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 7144));
}


// ========================================================================
// __unwind$494381
// EA  : 0x82C04D38
// RVA : 0x00C04D38
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494381()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 144 + 164) + 7176));
}


// ========================================================================
// ??1idAnimated_AnimWeb@@UAA@XZ
// EA  : 0x82C04D70
// RVA : 0x00C04D70
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void __fastcall idAnimated_AnimWeb::~idAnimated_AnimWeb(idAnimated_AnimWeb *this)
{
  idInventoryCollection *p_inventory; // r21
  int v3; // r23
  int v4; // r24
  int v5; // r25
  idAnimated_AnimWeb::collisionPiece_t *v6; // r30
  int v7; // r27
  idAnimated_AnimWeb::collisionPieceStage_t *v8; // r29
  idClipModel *clipModel; // r28
  idStr *list; // r28
  int size; // r30
  idStr *v12; // r29
  idStr *v13; // r28
  int v14; // r30
  idStr *v15; // r29
  idAnimEventHandler *v16; // r28
  int v17; // r30
  idAnimEventHandler *v18; // r29
  idAttachment *v19; // r4
  idAnimated_AnimWeb::collisionPiece_t *v20; // r28
  int v21; // r30
  idAnimated_AnimWeb::collisionPiece_t *v22; // r29
  idAnimated_AnimWeb::attachment_t *v23; // r28
  int v24; // r30
  idAnimated_AnimWeb::attachment_t *v25; // r29
  idAnimWebPath *v26; // r27
  int v27; // r30
  idAnimWebPath *v28; // r29

  this->__vftable = (idAnimated_AnimWeb_vtbl *)&idAnimated_AnimWeb::`vftable';
  p_inventory = &this->inventory;
  idInventoryCollection::FreeInventory(this: &this->inventory, owner: nullptr);
  v3 = 0;
  if ( this->collisionPieces.num > 0 )
  {
    v4 = 0;
    do
    {
      v5 = 0;
      v6 = &this->collisionPieces.list[v4];
      if ( v6->stages.num > 0 )
      {
        v7 = 0;
        do
        {
          v8 = &v6->stages.list[v7];
          if ( v8->clipModel != nullptr )
          {
            clipModel = v8->clipModel;
            if ( clipModel != v6->physicsObj.GetClipModel(this: &v6->physicsObj, a2: 0) )
            {
              idClipModel::Delete(this: clipModel);
              v8->clipModel = nullptr;
            }
          }
          ++v5;
          ++v7;
        }
        while ( v5 < v6->stages.num );
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->collisionPieces.num );
  }
  if ( this->showMeshes.listStatic == 0 || this->showMeshes.listStatic == 2 )
  {
    list = this->showMeshes.list;
    if ( list != nullptr )
    {
      size = this->showMeshes.size;
      if ( size > 0 )
      {
        v12 = this->showMeshes.list;
        do
        {
          idStr::FreeData(this: v12);
          --size;
          ++v12;
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
    this->showMeshes.list = nullptr;
    this->showMeshes.size = 0;
  }
  this->showMeshes.num = 0;
  if ( this->hideMeshes.listStatic == 0 || this->hideMeshes.listStatic == 2 )
  {
    v13 = this->hideMeshes.list;
    if ( v13 != nullptr )
    {
      v14 = this->hideMeshes.size;
      if ( v14 > 0 )
      {
        v15 = this->hideMeshes.list;
        do
        {
          idStr::FreeData(this: v15);
          --v14;
          ++v15;
        }
        while ( v14 != 0 );
      }
      idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
    }
    this->hideMeshes.list = nullptr;
    this->hideMeshes.size = 0;
  }
  this->hideMeshes.num = 0;
  idStr::FreeData(this: &this->skipJointForLighting);
  if ( this->attachmentAnimEventHandlers.listStatic == 0 || this->attachmentAnimEventHandlers.listStatic == 2 )
  {
    v16 = this->attachmentAnimEventHandlers.list;
    if ( v16 != nullptr )
    {
      v17 = this->attachmentAnimEventHandlers.size;
      if ( v17 > 0 )
      {
        v18 = this->attachmentAnimEventHandlers.list;
        do
        {
          idAnimEventHandler::~idAnimEventHandler(this: v18);
          --v17;
          ++v18;
        }
        while ( v17 != 0 );
      }
      idMem::Free(this: &mem, ptr: v16, align: ALIGN_16);
    }
    this->attachmentAnimEventHandlers.list = nullptr;
    this->attachmentAnimEventHandlers.size = 0;
  }
  this->attachmentAnimEventHandlers.num = 0;
  if ( p_inventory->inventory.listStatic == 0 || p_inventory->inventory.listStatic == 2 )
  {
    if ( p_inventory->inventory.list != nullptr )
      idMem::Free(this: &mem, ptr: p_inventory->inventory.list, align: ALIGN_16);
    p_inventory->inventory.list = nullptr;
    p_inventory->inventory.size = 0;
  }
  p_inventory->inventory.num = 0;
  if ( this->attachments.attachments.listStatic == 0 || this->attachments.attachments.listStatic == 2 )
  {
    v19 = this->attachments.attachments.list;
    if ( v19 != nullptr )
      idMem::Free(this: &mem, ptr: v19, align: ALIGN_16);
    this->attachments.attachments.list = nullptr;
    this->attachments.attachments.size = 0;
  }
  this->attachments.attachments.num = 0;
  idAnimator_Paused::~idAnimator_Paused(this: &this->pausedAnimator);
  `eh vector destructor iterator'(
    ptr: this->channelAnimators,
    size: 0x60u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idAnimator_Channel::~idAnimator_Channel);
  idAnimator_AnimWeb::~idAnimator_AnimWeb(this: &this->animWeb);
  if ( this->collisionPieces.listStatic == 0 || this->collisionPieces.listStatic == 2 )
  {
    v20 = this->collisionPieces.list;
    if ( v20 != nullptr )
    {
      v21 = this->collisionPieces.size;
      if ( v21 > 0 )
      {
        v22 = this->collisionPieces.list;
        do
        {
          idAnimated_AnimWeb::collisionPiece_t::~collisionPiece_t(this: v22);
          --v21;
          ++v22;
        }
        while ( v21 != 0 );
      }
      idMem::Free(this: &mem, ptr: v20, align: ALIGN_16);
    }
    this->collisionPieces.list = nullptr;
    this->collisionPieces.size = 0;
  }
  this->collisionPieces.num = 0;
  idStr::FreeData(this: &this->soundJoint);
  if ( this->startingAttachments.listStatic == 0 || this->startingAttachments.listStatic == 2 )
  {
    v23 = this->startingAttachments.list;
    if ( v23 != nullptr )
    {
      v24 = this->startingAttachments.size;
      if ( v24 > 0 )
      {
        v25 = this->startingAttachments.list;
        do
        {
          idAnimated_AnimWeb::attachment_t::~attachment_t(this: v25);
          --v24;
          ++v25;
        }
        while ( v24 != 0 );
      }
      idMem::Free(this: &mem, ptr: v23, align: ALIGN_16);
    }
    this->startingAttachments.list = nullptr;
    this->startingAttachments.size = 0;
  }
  this->startingAttachments.num = 0;
  if ( this->animWebParms.ambientAnims.listStatic == 0 || this->animWebParms.ambientAnims.listStatic == 2 )
  {
    v26 = this->animWebParms.ambientAnims.list;
    if ( v26 != nullptr )
    {
      v27 = this->animWebParms.ambientAnims.size;
      if ( v27 > 0 )
      {
        v28 = this->animWebParms.ambientAnims.list;
        do
        {
          idStr::FreeData(this: v28);
          --v27;
          ++v28;
        }
        while ( v27 != 0 );
      }
      idMem::Free(this: &mem, ptr: v26, align: ALIGN_16);
    }
    this->animWebParms.ambientAnims.list = nullptr;
    this->animWebParms.ambientAnims.size = 0;
  }
  this->animWebParms.ambientAnims.num = 0;
  idStr::FreeData(this: &this->animWebParms.initialWebNode);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$494928
// EA  : 0x82C0515C
// RVA : 0x00C0515C
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494928()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 192 + 212));
}


// ========================================================================
// __unwind$494929
// EA  : 0x82C05184
// RVA : 0x00C05184
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494929()
{
  int v0; // r12

  idAnimated_AnimWeb::animWebParms_t::~animWebParms_t(this: (idAnimated_AnimWeb::animWebParms_t *)(*(_DWORD *)(v0 - 192 + 212)
                                                                                                 + 5200));
}


// ========================================================================
// __unwind$494930_0
// EA  : 0x82C051B0
// RVA : 0x00C051B0
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494930_0()
{
  int v0; // r12

  idList<idAnimated_AnimWeb::attachment_t,5>::~idList<idAnimated_AnimWeb::attachment_t,5>(this: (idList<idAnimated_AnimWeb::attachment_t,5> *)(*(_DWORD *)(v0 - 192 + 212) + 5252));
}


// ========================================================================
// __unwind$494931
// EA  : 0x82C051DC
// RVA : 0x00C051DC
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494931()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 192 + 212) + 5292));
}


// ========================================================================
// __unwind$494932
// EA  : 0x82C05208
// RVA : 0x00C05208
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494932()
{
  int v0; // r12

  idList<idAnimated_AnimWeb::collisionPiece_t,5>::~idList<idAnimated_AnimWeb::collisionPiece_t,5>(this: (idList<idAnimated_AnimWeb::collisionPiece_t,5> *)(*(_DWORD *)(v0 - 192 + 212) + 5328));
}


// ========================================================================
// __unwind$494933
// EA  : 0x82C05234
// RVA : 0x00C05234
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494933()
{
  int v0; // r12

  idAnimator_AnimWeb::~idAnimator_AnimWeb(this: (idAnimator_AnimWeb *)(*(_DWORD *)(v0 - 192 + 212) + 5348));
}


// ========================================================================
// __unwind$494934
// EA  : 0x82C05260
// RVA : 0x00C05260
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494934()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 192 + 212) + 5996),
    size: 0x60u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idAnimator_Channel::~idAnimator_Channel);
}


// ========================================================================
// __unwind$494935
// EA  : 0x82C0529C
// RVA : 0x00C0529C
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494935()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 192 + 212) + 6188));
}


// ========================================================================
// __unwind$494936
// EA  : 0x82C052C8
// RVA : 0x00C052C8
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494936()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 6244));
}


// ========================================================================
// __unwind$494937
// EA  : 0x82C052F4
// RVA : 0x00C052F4
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494937()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 6324));
}


// ========================================================================
// __unwind$494938
// EA  : 0x82C05320
// RVA : 0x00C05320
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494938()
{
  int v0; // r12

  idList<idAnimEventHandler,5>::Clear(this: (idList<idAnimEventHandler,5> *)(*(_DWORD *)(v0 - 192 + 212) + 7124));
}


// ========================================================================
// __unwind$494939
// EA  : 0x82C0534C
// RVA : 0x00C0534C
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494939()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 192 + 212) + 7144));
}


// ========================================================================
// __unwind$494940
// EA  : 0x82C05378
// RVA : 0x00C05378
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494940()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 192 + 212) + 7176));
}


// ========================================================================
// __unwind$494941
// EA  : 0x82C053A4
// RVA : 0x00C053A4
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_494941()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 192 + 212) + 7192));
}


// ========================================================================
// __unwind$495410
// EA  : 0x82C053D0
// RVA : 0x00C053D0
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.cpp
// ========================================================================

void _unwind_495410()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 192 + 80) + 4));
}

