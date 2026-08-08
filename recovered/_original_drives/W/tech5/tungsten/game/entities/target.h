
// ========================================================================
// ??0idTarget_ApplyExplosionImpulse@@QAA@XZ
// EA  : 0x824FA420
// RVA : 0x004FA420
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_ApplyExplosionImpulse *__fastcall idTarget_ApplyExplosionImpulse::idTarget_ApplyExplosionImpulse(
        idTarget_ApplyExplosionImpulse *this)
{
  unsigned __int64 v2; // r11

  idEntity::idEntity(this);
  this->__vftable = (idTarget_ApplyExplosionImpulse_vtbl *)&idTarget_ApplyExplosionImpulse::`vftable';
  this->impulse = 25000.0;
  this->angular.x = vec3_origin.x;
  *(float *)&v2 = vec3_origin.y;
  LODWORD(v2) = 0;
  this->angular.y = vec3_origin.y;
  this->angular.z = vec3_origin.z;
  this->radius.value = 256.0;
  this->isRadial = false;
  this->damageScale = 1.0;
  this->damageDecl = nullptr;
  this->pushPlayerScale = 4.0;
  this->explosionBoundsQuery.index = v2;
  return this;
}


// ========================================================================
// ??0idTarget_GroupMessage@@QAA@XZ
// EA  : 0x824FB288
// RVA : 0x004FB288
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_GroupMessage *__fastcall idTarget_GroupMessage::idTarget_GroupMessage(idTarget_GroupMessage *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_GroupMessage_vtbl *)&idTarget_GroupMessage::`vftable';
  idStr::idStr(this: &this->groupName, text: &byte_8200D768);
  this->message = AIGROUPMSG_MAX;
  this->entity.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// __unwind$584629
// EA  : 0x824FB2FC
// RVA : 0x004FB2FC
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

void _unwind_584629()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idTarget_RemoveItems@@QAA@XZ
// EA  : 0x824FC438
// RVA : 0x004FC438
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_RemoveItems *__fastcall idTarget_RemoveItems::idTarget_RemoveItems(idTarget_RemoveItems *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_RemoveItems_vtbl *)&idTarget_RemoveItems::`vftable';
  this->itemList.list = nullptr;
  this->itemList.granularity = 0;
  this->itemList.memTag = 5;
  this->itemList.listStatic = 0;
  this->itemList.size = 0;
  this->itemList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->itemList);
  return this;
}


// ========================================================================
// __unwind$586069
// EA  : 0x824FC4AC
// RVA : 0x004FC4AC
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

void _unwind_586069()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idTarget_UpdateVehicleKey@@QAA@XZ
// EA  : 0x824FC4E0
// RVA : 0x004FC4E0
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_UpdateVehicleKey *__fastcall idTarget_UpdateVehicleKey::idTarget_UpdateVehicleKey(
        idTarget_UpdateVehicleKey *this)
{
  idEntity::idEntity(this);
  this->keyDecl = nullptr;
  this->__vftable = (idTarget_UpdateVehicleKey_vtbl *)&idTarget_UpdateVehicleKey::`vftable';
  this->upgradeDecls.list = nullptr;
  this->upgradeDecls.granularity = 0;
  this->upgradeDecls.memTag = 5;
  this->upgradeDecls.listStatic = 0;
  this->upgradeDecls.size = 0;
  this->upgradeDecls.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->upgradeDecls);
  this->respawnVehicles = false;
  this->giveUpgrades = true;
  this->garage = GARAGE_MAX;
  this->giveMaxHealth = false;
  this->markForGarageView = false;
  return this;
}


// ========================================================================
// __unwind$586211
// EA  : 0x824FC55C
// RVA : 0x004FC55C
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

void _unwind_586211()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idTarget_ChangeSeatInfo@@QAA@XZ
// EA  : 0x824FC608
// RVA : 0x004FC608
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_ChangeSeatInfo *__fastcall idTarget_ChangeSeatInfo::idTarget_ChangeSeatInfo(idTarget_ChangeSeatInfo *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_ChangeSeatInfo_vtbl *)&idTarget_ChangeSeatInfo::`vftable';
  idVehicle::seatInfo_t::seatInfo_t(this: &this->seatInfo);
  this->seatNum = 0;
  return this;
}


// ========================================================================
// __unwind$586253
// EA  : 0x824FC664
// RVA : 0x004FC664
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

void _unwind_586253()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idTarget_InventoryCheck@@QAA@XZ
// EA  : 0x824FDB78
// RVA : 0x004FDB78
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_InventoryCheck *__fastcall idTarget_InventoryCheck::idTarget_InventoryCheck(idTarget_InventoryCheck *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_InventoryCheck_vtbl *)&idTarget_InventoryCheck::`vftable';
  this->requiredItemList.granularity = 0;
  this->requiredItemList.memTag = 5;
  this->requiredItemList.listStatic = 0;
  this->requiredItemList.list = nullptr;
  this->requiredItemList.size = 0;
  this->requiredItemList.num = 0;
  *(_WORD *)&this->anyItemActivates = 1;
  this->haveItemsMessage.data = this->haveItemsMessage.baseBuffer;
  this->haveItemsMessage.allocedAndFlag = 20;
  this->haveItemsMessage.len = 0;
  this->haveItemsMessage.baseBuffer[0] = 0;
  this->dontHaveItemsMessage.allocedAndFlag = 20;
  this->dontHaveItemsMessage.data = this->dontHaveItemsMessage.baseBuffer;
  this->dontHaveItemsMessage.len = 0;
  this->dontHaveItemsMessage.baseBuffer[0] = 0;
  this->used = false;
  return this;
}


// ========================================================================
// __unwind$587514
// EA  : 0x824FDC2C
// RVA : 0x004FDC2C
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

void _unwind_587514()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idTarget_ShowGui@@QAA@XZ
// EA  : 0x824FDD58
// RVA : 0x004FDD58
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_ShowGui *__fastcall idTarget_ShowGui::idTarget_ShowGui(idTarget_ShowGui *this)
{
  idEntity::idEntity(this);
  this->gui = nullptr;
  this->__vftable = (idTarget_ShowGui_vtbl *)&idTarget_ShowGui::`vftable';
  this->guiString1.index = -1;
  this->guiString2.index = -1;
  this->guiString3.index = -1;
  this->guiImage1 = nullptr;
  this->specialCase = SHOWGUI_NORMAL;
  this->acceptTarget.spawnId.value = 0x1FFF;
  this->rejectTarget.spawnId.value = 0x1FFF;
  this->singlePurchaseItem = nullptr;
  this->board.granularity = 0;
  this->board.memTag = 5;
  this->board.listStatic = 0;
  this->board.list = nullptr;
  this->board.size = 0;
  this->board.num = 0;
  this->statIndex = 0;
  this->canUseDefaultPlayer = false;
  this->bindPlayer = false;
  this->guiQueued = false;
  this->guiActivator = nullptr;
  return this;
}


// ========================================================================
// __unwind$587644
// EA  : 0x824FDE30
// RVA : 0x004FDE30
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

void _unwind_587644()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idTarget_ChangeColor@@QAA@XZ
// EA  : 0x82501440
// RVA : 0x00501440
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_ChangeColor *__fastcall idTarget_ChangeColor::idTarget_ChangeColor(idTarget_ChangeColor *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_ChangeColor_vtbl *)&idTarget_ChangeColor::`vftable';
  this->color = idColor::colorWhite;
  return this;
}


// ========================================================================
// ??0idTarget_Job@@QAA@XZ
// EA  : 0x825014A8
// RVA : 0x005014A8
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_Job *__fastcall idTarget_Job::idTarget_Job(idTarget_Job *this)
{
  idEntity::idEntity(this);
  this->jobDecl = nullptr;
  this->completeTree = true;
  this->__vftable = (idTarget_Job_vtbl *)&idTarget_Job::`vftable';
  this->giveJob = true;
  this->markGivenJobUnknown = false;
  this->treatAsDebug = false;
  this->HACK_noitemrewards = false;
  this->HACK_nolayerchanges = false;
  this->clearJobNotesForThisJob = false;
  this->action = TARGETJOB_ACCEPTED;
  this->playerOnly = true;
  this->jobNoteOverride = nullptr;
  *(_WORD *)&this->clearJobStateFirst = 1;
  return this;
}


// ========================================================================
// ??0idTarget_LayerChange@@QAA@XZ
// EA  : 0x8251A0E8
// RVA : 0x0051A0E8
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_LayerChange *__fastcall idTarget_LayerChange::idTarget_LayerChange(idTarget_LayerChange *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_LayerChange_vtbl *)&idTarget_LayerChange::`vftable';
  this->layerChanges.list = nullptr;
  this->layerChanges.granularity = 0;
  this->layerChanges.memTag = 5;
  this->layerChanges.listStatic = 0;
  this->layerChanges.size = 0;
  this->layerChanges.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->layerChanges);
  return this;
}


// ========================================================================
// __unwind$573668
// EA  : 0x8251A15C
// RVA : 0x0051A15C
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

void _unwind_573668()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idTarget_ModifyGroup@@QAA@XZ
// EA  : 0x8251D2A0
// RVA : 0x0051D2A0
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_ModifyGroup *__fastcall idTarget_ModifyGroup::idTarget_ModifyGroup(idTarget_ModifyGroup *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_ModifyGroup_vtbl *)&idTarget_ModifyGroup::`vftable';
  this->groupName.len = 0;
  this->groupName.allocedAndFlag = 20;
  this->groupName.data = this->groupName.baseBuffer;
  this->groupName.baseBuffer[0] = 0;
  idEncounterState::idEncounterState(this: &this->ownGroupAlertState);
  idEncounterState::idEncounterState(this: &this->otherGroupAlertState);
  return this;
}


// ========================================================================
// __unwind$527790
// EA  : 0x8251D31C
// RVA : 0x0051D31C
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

void _unwind_527790()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$527791
// EA  : 0x8251D344
// RVA : 0x0051D344
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

void _unwind_527791()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 800));
}


// ========================================================================
// __unwind$527792
// EA  : 0x8251D370
// RVA : 0x0051D370
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

void _unwind_527792()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 112 + 132) + 832));
}


// ========================================================================
// ??0idTarget_InhibitControl@@QAA@XZ
// EA  : 0x8251D480
// RVA : 0x0051D480
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_InhibitControl *__fastcall idTarget_InhibitControl::idTarget_InhibitControl(idTarget_InhibitControl *this)
{
  idEntity::idEntity(this);
  this->inhibit = INHIBIT_CONTROL;
  this->__vftable = (idTarget_InhibitControl_vtbl *)&idTarget_InhibitControl::`vftable';
  this->delay = 0.0;
  this->toggleOnActivate = false;
  this->duration = 0.0;
  this->activated = true;
  return this;
}


// ========================================================================
// ??0idTarget_CoopObjectiveTracker@@QAA@XZ
// EA  : 0x8251D4E0
// RVA : 0x0051D4E0
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_CoopObjectiveTracker *__fastcall idTarget_CoopObjectiveTracker::idTarget_CoopObjectiveTracker(
        idTarget_CoopObjectiveTracker *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_CoopObjectiveTracker_vtbl *)&idTarget_CoopObjectiveTracker::`vftable';
  this->text.index = -1;
  this->bonus = 0;
  this->parTime = 0.0;
  this->displayTime = true;
  this->bTracking = false;
  return this;
}


// ========================================================================
// ??0idTarget_HideShowMesh@@QAA@XZ
// EA  : 0x8251D548
// RVA : 0x0051D548
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_HideShowMesh *__fastcall idTarget_HideShowMesh::idTarget_HideShowMesh(idTarget_HideShowMesh *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_HideShowMesh_vtbl *)&idTarget_HideShowMesh::`vftable';
  this->meshName.len = 0;
  this->meshName.allocedAndFlag = 20;
  this->meshName.data = this->meshName.baseBuffer;
  this->meshName.baseBuffer[0] = 0;
  this->hide = true;
  return this;
}


// ========================================================================
// ??0idTarget_JobTriggered@@QAA@XZ
// EA  : 0x8253D710
// RVA : 0x0053D710
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_JobTriggered *__fastcall idTarget_JobTriggered::idTarget_JobTriggered(idTarget_JobTriggered *this)
{
  idEntity::idEntity(this);
  this->jobDecl = nullptr;
  this->__vftable = (idTarget_JobTriggered_vtbl *)&idTarget_JobTriggered::`vftable';
  this->jobStatus = JOBSTATUS_COMPLETED;
  this->triggerType = JOBTRIGGEREDTYPE_EQUAL;
  this->triggerTime = JOBTRIGGEREDTIME_IMMEDIATE;
  *(_WORD *)&this->ignoreDebug = 1;
  this->jobBoardHack.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// ??0idTarget_ShowTargetHealth@@QAA@XZ
// EA  : 0x8253D7E0
// RVA : 0x0053D7E0
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_ShowTargetHealth *__fastcall idTarget_ShowTargetHealth::idTarget_ShowTargetHealth(
        idTarget_ShowTargetHealth *this)
{
  idEntity::idEntity(this);
  this->isShowing = false;
  this->__vftable = (idTarget_ShowTargetHealth_vtbl *)&idTarget_ShowTargetHealth::`vftable';
  this->healthTarget.spawnId.value = 0x1FFF;
  this->trackedTargets.list = nullptr;
  this->trackedTargets.granularity = 0;
  this->trackedTargets.memTag = 5;
  this->trackedTargets.listStatic = 0;
  this->trackedTargets.size = 0;
  this->trackedTargets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->trackedTargets);
  this->turretGunnerFlag = false;
  return this;
}


// ========================================================================
// __unwind$582664
// EA  : 0x8253D854
// RVA : 0x0053D854
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

void _unwind_582664()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// ??0idTarget_Damage@@QAA@XZ
// EA  : 0x825411E0
// RVA : 0x005411E0
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_Damage *__fastcall idTarget_Damage::idTarget_Damage(idTarget_Damage *this)
{
  idEntity::idEntity(this);
  this->damageDecl = nullptr;
  this->__vftable = (idTarget_Damage_vtbl *)&idTarget_Damage::`vftable';
  this->damageDir.pitch = 0.0;
  this->damageDir.yaw = 0.0;
  this->damageDir.roll = 0.0;
  this->damageActivator = false;
  this->radiusDamage = 0.0;
  this->damagePlayer = false;
  return this;
}


// ========================================================================
// ??0idTarget_EnableGroup@@QAA@XZ
// EA  : 0x82541248
// RVA : 0x00541248
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_EnableGroup *__fastcall idTarget_EnableGroup::idTarget_EnableGroup(idTarget_EnableGroup *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_EnableGroup_vtbl *)&idTarget_EnableGroup::`vftable';
  this->groupName.len = 0;
  this->groupName.allocedAndFlag = 20;
  this->groupName.data = this->groupName.baseBuffer;
  this->groupName.baseBuffer[0] = 0;
  this->enable = true;
  return this;
}


// ========================================================================
// ??0idTarget_PlayAnim@@QAA@XZ
// EA  : 0x825412B0
// RVA : 0x005412B0
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_PlayAnim *__fastcall idTarget_PlayAnim::idTarget_PlayAnim(idTarget_PlayAnim *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_PlayAnim_vtbl *)&idTarget_PlayAnim::`vftable';
  this->animation.len = 0;
  this->animation.allocedAndFlag = 20;
  this->animation.data = this->animation.baseBuffer;
  this->animation.baseBuffer[0] = 0;
  this->blendTime = 0;
  this->loopAnimation = false;
  return this;
}


// ========================================================================
// ??0idTarget_ApplyImpulse@@QAA@XZ
// EA  : 0x82541318
// RVA : 0x00541318
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_ApplyImpulse *__fastcall idTarget_ApplyImpulse::idTarget_ApplyImpulse(idTarget_ApplyImpulse *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_ApplyImpulse_vtbl *)&idTarget_ApplyImpulse::`vftable';
  this->impulse = 500.0;
  this->angular = vec3_origin;
  this->breakableRadius = 256.0;
  this->breakableImpulse = 1000000.0;
  this->breakableFalloff = 0.2;
  this->breakableAngular = 40.0;
  this->breakableDelay = 0.0;
  this->breakableDuration = 10.0;
  return this;
}


// ========================================================================
// ??0idTarget_ShakeTrigger@@QAA@XZ
// EA  : 0x825413C8
// RVA : 0x005413C8
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_ShakeTrigger *__fastcall idTarget_ShakeTrigger::idTarget_ShakeTrigger(idTarget_ShakeTrigger *this)
{
  idEntity::idEntity(this);
  this->activateTime = 0;
  this->__vftable = (idTarget_ShakeTrigger_vtbl *)&idTarget_ShakeTrigger::`vftable';
  this->delay = 3.0;
  this->diversity = 0.30000001;
  this->shake = 0.001;
  return this;
}


// ========================================================================
// ??0idTarget_LayerChange2@@QAA@XZ
// EA  : 0x82558BD0
// RVA : 0x00558BD0
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_LayerChange2 *__fastcall idTarget_LayerChange2::idTarget_LayerChange2(idTarget_LayerChange2 *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_LayerChange2_vtbl *)&idTarget_LayerChange2::`vftable';
  this->layerChanges.list = nullptr;
  this->layerChanges.granularity = 0;
  this->layerChanges.memTag = 5;
  this->layerChanges.listStatic = 0;
  this->layerChanges.size = 0;
  this->layerChanges.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->layerChanges);
  return this;
}


// ========================================================================
// __unwind$569055
// EA  : 0x82558C44
// RVA : 0x00558C44
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

void _unwind_569055()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idTarget_ToggleTraversal@@QAA@XZ
// EA  : 0x82558C78
// RVA : 0x00558C78
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_ToggleTraversal *__fastcall idTarget_ToggleTraversal::idTarget_ToggleTraversal(idTarget_ToggleTraversal *this)
{
  idEntity::idEntity(this);
  this->enable = false;
  this->aasType = AAS_MONSTER48;
  this->__vftable = (idTarget_ToggleTraversal_vtbl *)&idTarget_ToggleTraversal::`vftable';
  this->targetTraversals.list = nullptr;
  this->targetTraversals.granularity = 0;
  this->targetTraversals.memTag = 5;
  this->targetTraversals.listStatic = 0;
  this->targetTraversals.size = 0;
  this->targetTraversals.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->targetTraversals);
  return this;
}


// ========================================================================
// __unwind$569373
// EA  : 0x82558CF8
// RVA : 0x00558CF8
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

void _unwind_569373()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idTarget_TestPlayerState@@QAA@XZ
// EA  : 0x82559390
// RVA : 0x00559390
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_TestPlayerState *__fastcall idTarget_TestPlayerState::idTarget_TestPlayerState(idTarget_TestPlayerState *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_TestPlayerState_vtbl *)&idTarget_TestPlayerState::`vftable';
  this->requiredItemList.list = nullptr;
  this->requiredItemList.granularity = 0;
  this->requiredItemList.memTag = 5;
  this->requiredItemList.listStatic = 0;
  this->requiredItemList.size = 0;
  this->requiredItemList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->requiredItemList);
  this->anyItemActivates = false;
  this->fireOnInventoryFail = false;
  this->requiredJobsList.granularity = 0;
  this->requiredJobsList.memTag = 5;
  this->requiredJobsList.listStatic = 0;
  this->requiredJobsList.list = nullptr;
  this->requiredJobsList.size = 0;
  this->requiredJobsList.num = 0;
  this->anyJobActivates = false;
  this->fireOnJobFail = false;
  this->requiredGameStateIntList.list = nullptr;
  this->requiredGameStateIntList.granularity = 0;
  this->requiredGameStateIntList.memTag = 5;
  this->requiredGameStateIntList.listStatic = 0;
  this->requiredGameStateIntList.size = 0;
  this->requiredGameStateIntList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->requiredGameStateIntList);
  this->anyGameStateIntActivate = false;
  this->fireOnGameStateFail = false;
  this->givenGameStateInt = nullptr;
  this->requiredDLCStateList.list = nullptr;
  this->requiredDLCStateList.granularity = 0;
  this->requiredDLCStateList.memTag = 5;
  this->requiredDLCStateList.listStatic = 0;
  this->requiredDLCStateList.size = 0;
  this->requiredDLCStateList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->requiredDLCStateList);
  this->fireOnDLCStateFail = false;
  this->verifyGarageManager.spawnId.value = 0x1FFF;
  this->fireOnGarageManagerFail = false;
  this->useOnce = true;
  this->used = false;
  return this;
}


// ========================================================================
// __unwind$570049
// EA  : 0x8255948C
// RVA : 0x0055948C
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

void _unwind_570049()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$570050
// EA  : 0x825594B4
// RVA : 0x005594B4
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

void _unwind_570050()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 800));
}


// ========================================================================
// __unwind$570051
// EA  : 0x825594E0
// RVA : 0x005594E0
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

void _unwind_570051()
{
  int v0; // r12

  idList<idTarget_TestPlayerState::playerState_Job_t,5>::~idList<idTarget_TestPlayerState::playerState_Job_t,5>(this: (vaiAction_t::throwAttachedItem_t *)(*(_DWORD *)(v0 - 128 + 148) + 820));
}


// ========================================================================
// __unwind$570052
// EA  : 0x8255950C
// RVA : 0x0055950C
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

void _unwind_570052()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 840));
}


// ========================================================================
// ??0idTarget_ActionScript@@QAA@XZ
// EA  : 0x82559B80
// RVA : 0x00559B80
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_ActionScript *__fastcall idTarget_ActionScript::idTarget_ActionScript(idTarget_ActionScript *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_ActionScript_vtbl *)&idTarget_ActionScript::`vftable';
  this->actionScript.granularity = 0;
  this->actionScript.memTag = 5;
  this->actionScript.listStatic = 0;
  this->actionScript.list = nullptr;
  this->actionScript.size = 0;
  this->actionScript.num = 0;
  return this;
}


// ========================================================================
// __unwind$570577
// EA  : 0x82559BF0
// RVA : 0x00559BF0
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

void _unwind_570577()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetFaction@idTarget_FakeEnemy@@UBAPBVidFaction@@XZ
// EA  : 0x82CDAD48
// RVA : 0x00CDAD48
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

const idAnimStack *__fastcall idTarget_FakeEnemy::GetFaction(idAnimatedEntity *this)
{
  return &this->animStack;
}


// ========================================================================
// ??0idSpawnSettings@idTarget_Spawn@@QAA@XZ
// EA  : 0x82CDFC38
// RVA : 0x00CDFC38
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

idTarget_Spawn::idSpawnSettings *__fastcall idTarget_Spawn::idSpawnSettings::idSpawnSettings(
        idTarget_Spawn::idSpawnSettings *this)
{
  this->minSpawnInterval = 0;
  this->maxCount = 1;
  this->spawnAtOnce = 1;
  this->maxSpawnInterval = 0;
  this->spawnAt.spawnId.value = 0x1FFF;
  this->mutantAttractorRange = 0;
  this->copyTargets = false;
  this->additionalTargets.list = nullptr;
  this->additionalTargets.granularity = 0;
  this->additionalTargets.memTag = 5;
  this->additionalTargets.listStatic = 0;
  this->additionalTargets.size = 0;
  this->additionalTargets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->additionalTargets);
  this->groupName.len = 0;
  this->groupName.allocedAndFlag = 20;
  this->groupName.data = this->groupName.baseBuffer;
  this->groupName.baseBuffer[0] = 0;
  this->deathTrigger.spawnId.value = 0x1FFF;
  this->useTraversalClassA = false;
  this->useTraversalClassB = false;
  this->useTraversalClassC = false;
  this->useTraversalClassD = false;
  this->useTraversalClassE = false;
  this->combatHintClass = CLASS_ALL;
  this->actionScript.granularity = 0;
  this->actionScript.memTag = 5;
  this->actionScript.listStatic = 0;
  this->actionScript.list = nullptr;
  this->actionScript.size = 0;
  this->actionScript.num = 0;
  this->coverRadius = 0.0;
  this->maxEnemyCoverDistance = 0.0;
  this->safeSpawnFlag = false;
  return this;
}


// ========================================================================
// __unwind$528464
// EA  : 0x82CDFD24
// RVA : 0x00CDFD24
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

void _unwind_528464()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 28));
}


// ========================================================================
// __unwind$528465
// EA  : 0x82CDFD50
// RVA : 0x00CDFD50
// PDB : w:\tech5\tungsten\game\entities\target.h
// ========================================================================

void _unwind_528465()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 44));
}

