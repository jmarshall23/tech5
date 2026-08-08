
// ========================================================================
// ??0idVolume_RegimeRegenerate@@QAA@XZ
// EA  : 0x82519980
// RVA : 0x00519980
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

idVolume_RegimeRegenerate *__fastcall idVolume_RegimeRegenerate::idVolume_RegimeRegenerate(
        idVolume_RegimeRegenerate *this)
{
  idVolume::idVolume(this);
  this->soundFieldActivating = nullptr;
  this->__vftable = (idVolume_RegimeRegenerate_vtbl *)&idVolume_RegimeRegenerate::`vftable';
  this->shieldHealthPerFrame = 1.0;
  this->soundFieldDeactivating = nullptr;
  this->startOff = false;
  this->baseEntity.spawnId.value = 0x1FFF;
  this->isHealing = false;
  return this;
}


// ========================================================================
// ??0idCombatVolume@@QAA@XZ
// EA  : 0x82519F00
// RVA : 0x00519F00
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

idCombatVolume *__fastcall idCombatVolume::idCombatVolume(idCombatVolume *this)
{
  idVolume::idVolume(this);
  this->__vftable = (idCombatVolume_vtbl *)&idCombatVolume::`vftable';
  this->groups.list = nullptr;
  this->groups.granularity = 0;
  this->groups.memTag = 5;
  this->groups.listStatic = 0;
  this->groups.size = 0;
  this->groups.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->groups);
  idCombatVolume::AddGroup(this, groupName: &byte_8200D768);
  return this;
}


// ========================================================================
// __unwind$573567
// EA  : 0x82519F84
// RVA : 0x00519F84
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

void _unwind_573567()
{
  int v0; // r12

  idVolume::~idVolume(this: *(idVolume **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$573568
// EA  : 0x82519FAC
// RVA : 0x00519FAC
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

void _unwind_573568()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 824));
}


// ========================================================================
// ??1idCombatVolume@@UAA@XZ
// EA  : 0x82519FE0
// RVA : 0x00519FE0
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

void __fastcall idCombatVolume::~idCombatVolume(idCombatVolume *this)
{
  idList<idVehicleState *,5> *p_groups; // r29

  this->__vftable = (idCombatVolume_vtbl *)&idCombatVolume::`vftable';
  p_groups = (idList<idVehicleState *,5> *)&this->groups;
  idList<idCombatVolumeGroup *,5>::DeleteContents(this: &this->groups);
  idList<idThread *,58>::Clear(this: p_groups);
  idVolume::~idVolume(this);
}


// ========================================================================
// __unwind$573631
// EA  : 0x8251A028
// RVA : 0x0051A028
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

void _unwind_573631()
{
  int v0; // r12

  idVolume::~idVolume(this: *(idVolume **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$573632
// EA  : 0x8251A050
// RVA : 0x0051A050
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

void _unwind_573632()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 824));
}


// ========================================================================
// ??0idVolume_LocationCalling@@QAA@XZ
// EA  : 0x8251CF50
// RVA : 0x0051CF50
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

idVolume_LocationCalling *__fastcall idVolume_LocationCalling::idVolume_LocationCalling(idVolume_LocationCalling *this)
{
  idVolume::idVolume(this);
  this->locationVo = nullptr;
  this->__vftable = (idVolume_LocationCalling_vtbl *)&idVolume_LocationCalling::`vftable';
  this->locationSs = nullptr;
  this->groupName.allocedAndFlag = 20;
  this->groupName.data = this->groupName.baseBuffer;
  this->groupName.len = 0;
  this->groupName.baseBuffer[0] = 0;
  return this;
}


// ========================================================================
// ??0idVolume_ShowGui_Leveltransition@@QAA@XZ
// EA  : 0x8253D378
// RVA : 0x0053D378
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

idVolume_ShowGui_Leveltransition *__fastcall idVolume_ShowGui_Leveltransition::idVolume_ShowGui_Leveltransition(
        idVolume_ShowGui_Leveltransition *this)
{
  idVolume::idVolume(this);
  this->__vftable = (idVolume_ShowGui_Leveltransition_vtbl *)&idVolume_ShowGui_Leveltransition::`vftable';
  this->showForVehicles = false;
  this->requireKeyForVehicle = false;
  this->showForPlayer = true;
  this->deactivateOnUse = true;
  this->availableJobDecl.data = this->availableJobDecl.baseBuffer;
  this->availableJobDecl.allocedAndFlag = 20;
  this->availableJobDecl.len = 0;
  this->availableJobDecl.baseBuffer[0] = 0;
  this->availableJobStatus = JOBSTATUS_COMPLETED;
  this->unAvailableJobDecl.allocedAndFlag = 20;
  this->unAvailableJobDecl.data = this->unAvailableJobDecl.baseBuffer;
  this->unAvailableJobDecl.len = 0;
  this->unAvailableJobDecl.baseBuffer[0] = 0;
  this->unAvailableJobStatus = JOBSTATUS_READYTOTURNIN;
  this->guiSpecifics.guiString2.index = -1;
  this->useSound = nullptr;
  this->showIfUnavailable = true;
  this->verifyGarageManager.spawnId.value = 0x1FFF;
  this->facingTarget.spawnId.value = 0x1FFF;
  this->traceTarget.spawnId.value = 0x1FFF;
  this->disabledUntilUntouch = false;
  return this;
}


// ========================================================================
// ??0idCombatVolumeGroup@@QAA@XZ
// EA  : 0x8253E558
// RVA : 0x0053E558
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

idCombatVolumeGroup *__fastcall idCombatVolumeGroup::idCombatVolumeGroup(idCombatVolumeGroup *this)
{
  this->combatVolume = nullptr;
  this->__vftable = (idCombatVolumeGroup_vtbl *)&idCombatVolumeGroup::`vftable';
  this->groupName.allocedAndFlag = 20;
  this->groupName.data = this->groupName.baseBuffer;
  this->groupName.len = 0;
  this->groupName.baseBuffer[0] = 0;
  this->actors.list = nullptr;
  this->actors.granularity = 0;
  this->actors.memTag = 5;
  this->actors.listStatic = 0;
  this->actors.size = 0;
  this->actors.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->actors);
  this->nextUpdateTime = 0;
  return this;
}


// ========================================================================
// __unwind$583695
// EA  : 0x8253E5D4
// RVA : 0x0053E5D4
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

void _unwind_583695()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$583696
// EA  : 0x8253E5FC
// RVA : 0x0053E5FC
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

void _unwind_583696()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// ??0idVolume_DynamicJob@@QAA@XZ
// EA  : 0x82558370
// RVA : 0x00558370
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

idVolume_DynamicJob *__fastcall idVolume_DynamicJob::idVolume_DynamicJob(idVolume_DynamicJob *this)
{
  idVolume::idVolume(this);
  this->jobDecl = nullptr;
  this->checkForTouch = true;
  this->__vftable = (idVolume_DynamicJob_vtbl *)&idVolume_DynamicJob::`vftable';
  this->checkForUntouch = true;
  this->initialTargetList.list = nullptr;
  this->initialTargetList.granularity = 0;
  this->initialTargetList.memTag = 5;
  this->initialTargetList.listStatic = 0;
  this->initialTargetList.size = 0;
  this->initialTargetList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->initialTargetList);
  this->leaveTargetList.list = nullptr;
  this->leaveTargetList.granularity = 0;
  this->leaveTargetList.memTag = 5;
  this->leaveTargetList.listStatic = 0;
  this->leaveTargetList.size = 0;
  this->leaveTargetList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->leaveTargetList);
  this->reactivateTargetList.list = nullptr;
  this->reactivateTargetList.granularity = 0;
  this->reactivateTargetList.memTag = 5;
  this->reactivateTargetList.listStatic = 0;
  this->reactivateTargetList.size = 0;
  this->reactivateTargetList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->reactivateTargetList);
  this->hasBeenActivated = false;
  return this;
}


// ========================================================================
// __unwind$568356
// EA  : 0x82558420
// RVA : 0x00558420
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

void _unwind_568356()
{
  int v0; // r12

  idVolume::~idVolume(this: *(idVolume **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$568357
// EA  : 0x82558448
// RVA : 0x00558448
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

void _unwind_568357()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 832));
}


// ========================================================================
// __unwind$568358
// EA  : 0x82558474
// RVA : 0x00558474
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

void _unwind_568358()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 848));
}


// ========================================================================
// ??0idCombatVolumeGroup@@QAA@PAVidCombatVolume@@ABVidStr@@@Z
// EA  : 0x82D4A770
// RVA : 0x00D4A770
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

idCombatVolumeGroup *__fastcall idCombatVolumeGroup::idCombatVolumeGroup(
        idCombatVolumeGroup *this,
        idCombatVolume *rgn,
        const idStr *name)
{
  this->combatVolume = rgn;
  this->__vftable = (idCombatVolumeGroup_vtbl *)&idCombatVolumeGroup::`vftable';
  idStr::idStr(this: &this->groupName, text: name);
  this->actors.list = nullptr;
  this->actors.granularity = 0;
  this->actors.memTag = 5;
  this->actors.listStatic = 0;
  this->actors.size = 0;
  this->actors.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->actors);
  this->nextUpdateTime = 0;
  return this;
}


// ========================================================================
// __unwind$497214
// EA  : 0x82D4A7DC
// RVA : 0x00D4A7DC
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

void _unwind_497214()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$497215
// EA  : 0x82D4A804
// RVA : 0x00D4A804
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

void _unwind_497215()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// ?RemoveActor@idCombatVolumeGroup@@QAAXPAVidActor@@@Z
// EA  : 0x82D4B108
// RVA : 0x00D4B108
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

void __fastcall idCombatVolumeGroup::RemoveActor(idCombatVolumeGroup *this, idActor *actor)
{
  int v2; // [sp+50h] [-10h] BYREF

  if ( actor != nullptr )
    v2 = (gameLocal->spawnIds.ptr[actor->entityNumber] << 13) | actor->entityNumber;
  else
    v2 = 0x1FFF;
  idList<idEntityPtr<idActor>,5>::RemoveFast(this: (idList<int,5> *)&this->actors, obj: &v2);
}


// ========================================================================
// ?AddActor@idCombatVolumeGroup@@QAAXPAVidActor@@@Z
// EA  : 0x82D4B6F0
// RVA : 0x00D4B6F0
// PDB : w:\tech5\tungsten\game\entities\volume.h
// ========================================================================

void __fastcall idCombatVolumeGroup::AddActor(idCombatVolumeGroup *this, idActor *actor)
{
  int v2; // r7
  idList<idEntityPtr<idEntity>,58> *p_actors; // r3
  int v4; // r10
  int num; // r9
  int v6; // r11
  idEntityPtr<idEntity> v7; // [sp+50h] [-10h] BYREF

  if ( actor != nullptr )
    v2 = (gameLocal->spawnIds.ptr[actor->entityNumber] << 13) | actor->entityNumber;
  else
    v2 = 0x1FFF;
  p_actors = (idList<idEntityPtr<idEntity>,58> *)&this->actors;
  v7.spawnId.value = v2;
  v4 = 0;
  num = p_actors->num;
  if ( num <= 0 )
    goto LABEL_10;
  v6 = 0;
  while ( p_actors->list[v6].spawnId.value != v2 )
  {
    ++v4;
    ++v6;
    if ( v4 >= num )
      goto LABEL_10;
  }
  if ( v4 < 0 )
LABEL_10:
    idList<idEntityPtr<idEntity>,58>::Append(this: p_actors, obj: &v7);
}

