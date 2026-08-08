
// ========================================================================
// ??1idAnimWeb_TurretGunner@@UAA@XZ
// EA  : 0x82CFFF18
// RVA : 0x00CFFF18
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void __fastcall idAnimWeb_TurretGunner::~idAnimWeb_TurretGunner(idAnimWeb_TurretGunner *this)
{
  this->__vftable = (idAnimWeb_TurretGunner_vtbl *)&idAnimWeb_TurretGunner::`vftable';
  idAnimator_AnimWeb::~idAnimator_AnimWeb(this);
}


// ========================================================================
// ?OnActivate@idTurretGunner@@UAAXPAVidEntity@@@Z
// EA  : 0x82CFFF28
// RVA : 0x00CFFF28
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void __fastcall idTurretGunner::OnActivate(idTurretGunner *this, idEntity *activator)
{
  idVehicleMountedTurret *BindMaster; // r3
  idVehicleMountedTurret *v3; // r3
  idVehicleMountedTurret *v4; // r31

  BindMaster = (idVehicleMountedTurret *)idEntity::GetBindMaster(this);
  v3 = idVehicleMountedTurret::CastTo(c: BindMaster);
  v4 = v3;
  if ( v3 != nullptr && idVehicleMountedTurret::GetSeatState(this: v3) == SEATSTATE_LOWERED )
    idVehicleMountedTurret::RaiseSeat(this: v4);
}


// ========================================================================
// ?GetVisibilityPoint@idTurretGunner@@UBAXW4visPoint_t@@AAVidVec3@@@Z
// EA  : 0x82CFFF78
// RVA : 0x00CFFF78
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void __fastcall idTurretGunner::GetVisibilityPoint(idTurretGunner *this, const visPoint_t type, idVec3 *pos)
{
  ((void (__fastcall *)(idTurretGunner *, int))this->GetAimPoint)(a1: this, a2: 1);
  pos->z = pos->z + (float)10.0;
}


// ========================================================================
// ?InternalTriggerEvent@idAnimWebAI@@MAAXPBVidDeclAnimWebNode@@W4animWebEvent_t@@ABV?$idHandle@FW4invalidAnimWebHandle_t@@$0?0@@HH@Z
// EA  : 0x82D00030
// RVA : 0x00D00030
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void __fastcall idAnimWebAI::InternalTriggerEvent(
        idAnimWebAI *this,
        const idDeclAnimWebNode *node,
        const animWebEvent_t eventType,
        const idHandle<short,enum invalidAnimWebHandle_t,-1> *webHandle,
        int eventNum,
        const int eventParm)
{
  const idEventDef *EventCommand; // r30
  __int16 value; // r10
  __int16 v12; // r9
  __int16 v13; // r7
  _BYTE v14[20]; // [sp+70h] [-F0h] BYREF
  _BYTE v15[20]; // [sp+90h] [-D0h] BYREF
  _DWORD v16[5]; // [sp+B0h] [-B0h] BYREF
  _DWORD v17[5]; // [sp+D0h] [-90h] BYREF
  char v18; // [sp+F0h] [-70h]
  int v19; // [sp+F4h] [-6Ch]
  const idEventArg *v20; // [sp+F8h] [-68h]
  int v21; // [sp+110h] [-50h]
  int v22; // [sp+114h] [-4Ch]
  const idEventArg *v23; // [sp+118h] [-48h]
  const idEventArg *v24; // [sp+11Ch] [-44h]
  int v25; // [sp+120h] [-40h]

  EventCommand = idEventDef::GetEventCommand(eventnum: eventNum);
  if ( EventCommand != nullptr )
  {
    v16[1] = eventParm;
    value = node->states.stateIndex[0].value;
    HIBYTE(v16[0]) = 105;
    v12 = node->subWebIndex.value;
    v13 = webHandle->value;
    HIBYTE(v17[0]) = 105;
    v17[1] = value;
    v18 = 105;
    v19 = v12;
    HIBYTE(v21) = 105;
    v22 = v13;
    memcpy(Dst: v15, Src: v16, Size: sizeof(v15));
    memcpy(Dst: v14, Src: v17, Size: sizeof(v14));
    idEventReceiver::PostEventMS(
      this: this->ai,
      ev: EventCommand,
      time: v21,
      arg1: v23,
      arg2: v24,
      arg3: (const idEventArg *)__ROL4__(v25, 32),
      arg4: v20);
  }
}


// ========================================================================
// ?PullTrigger@idTurretGunner@@AAA_NXZ
// EA  : 0x82D00100
// RVA : 0x00D00100
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

BOOL __fastcall idTurretGunner::PullTrigger(idTurretGunner *this)
{
  idTurretGunner::triggerPhaseOn_t pullTriggerPhase; // r11
  int GameMs; // r3

  pullTriggerPhase = this->pullTriggerPhase;
  if ( pullTriggerPhase == TRIGGERPHASE_IDLE )
  {
    this->pullTriggerPhase = TRIGGERPHASE_START_PULL;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    pullTriggerPhase = this->pullTriggerPhase;
    this->pullTriggerPhaseEndTime = TRIGGER_PHASE_TIME[pullTriggerPhase] + GameMs;
  }
  return (_cntlzw(pullTriggerPhase - 3) & 0x20) != 0;
}


// ========================================================================
// ?UpdateAnimationControllers@idTurretGunner@@UAA_NXZ
// EA  : 0x82D00180
// RVA : 0x00D00180
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

int __fastcall idTurretGunner::UpdateAnimationControllers(idTurretGunner *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3

  idLobbyBackend360::StartArbitration(pexcept: (_exception *)this);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  idFaceMgr::Update(
    this: &this->faceMgr,
    owner: (idAI2 *)this,
    ta: TreeAnimatorFromPresentable,
    focusPoint: &this->gunnerAimPoint);
  return 1;
}


// ========================================================================
// ?LowerSeat@idTurretGunner@@QAAXXZ
// EA  : 0x82D001D8
// RVA : 0x00D001D8
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void __fastcall idTurretGunner::LowerSeat(idTurretGunner *this)
{
  idTurretGunner *v1; // r31
  unsigned __int16 v2; // [sp+50h] [-20h] BYREF
  unsigned __int16 v3; // [sp+52h] [-1Eh] BYREF

  v1 = this;
  idDeclAnimWeb::GetSubWebIndexForName(
    this: (idDeclAnimWeb *)&v3,
    result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->animWeb.decl,
    subWebName: "gunner");
  idDeclAnimWeb::GetStateIndexForName(
    this: (idDeclAnimWeb *)&v2,
    result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v1->animWeb.decl,
    name: "lowered");
  v1 = (idTurretGunner *)((char *)v1 + 5404);
  idAnimator_AnimWeb::ChangeState(
    this: (idAnimator_AnimWeb *)v1,
    subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v3,
    stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v2,
    interruptPath_: INTR_PATH_YES,
    interruptBlend_: INTR_BLEND_NO,
    blendEventMask_: 0);
  idAnimator_AnimWeb::SetEvent(
    this: (idAnimator_AnimWeb *)v1,
    eventType: ANIMWEB_EVENT_END_BLEND_IN,
    subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v3,
    stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v2,
    eventDef: &EV_AnimWeb_Lowered,
    priority: PRIORITY_LOW);
}


// ========================================================================
// ?Event_AnimWeb_Raised@idTurretGunner@@QAA?AVeventVoid@@HHHH@Z
// EA  : 0x82D00268
// RVA : 0x00D00268
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idTurretGunner::Event_AnimWeb_Raised@<r4>(
        idTurretGunner *this@<r3>,
        int result@<r4>,
        const int webHandle@<r5>,
        const int subWebIndex@<r6>,
        const int stateIndex@<r7>,
        const int eventParm@<r8>)
{
  *(_BYTE *)(result + 5389) = 1;
  return result;
}


// ========================================================================
// ?Event_AnimWeb_Lowered@idTurretGunner@@QAA?AVeventVoid@@HHHH@Z
// EA  : 0x82D00278
// RVA : 0x00D00278
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idTurretGunner::Event_AnimWeb_Lowered@<r4>(
        idTurretGunner *this@<r3>,
        int result@<r4>,
        const int webHandle@<r5>,
        const int subWebIndex@<r6>,
        const int stateIndex@<r7>,
        const int eventParm@<r8>)
{
  *(_BYTE *)(result + 5389) = 0;
  return result;
}


// ========================================================================
// ?AnimEvent_VoiceOver@idTurretGunner@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclVoiceOver@@@Z
// EA  : 0x82D00288
// RVA : 0x00D00288
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

idTurretGunner *__fastcall idTurretGunner::AnimEvent_VoiceOver(
        idTurretGunner *this,
        idAI2 *result,
        const idMD6Anim *animHandle,
        const idDeclVoiceOver *vo)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3

  if ( vo != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
    idFaceMgr::StartVoiceOver(
      this: (idFaceMgr *)&result->afProperties.physicsObj.errorReductionMax,
      owner: result,
      ta: TreeAnimatorFromPresentable,
      vo);
  }
  else
  {
    idLib::Warning(fmt: "Invalid voice over decl specified for AnimEvent_VoiceOver");
  }
  return this;
}


// ========================================================================
// ?GetEncounterGroup@idTurretGunner@@CAPAVidEncounterGroup@@PBD@Z
// EA  : 0x82D002E8
// RVA : 0x00D002E8
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void __fastcall idTurretGunner::GetEncounterGroup(const char *handleName)
{
  idEncounterGroupManager *p_encounterGroupManager; // r31
  idEncounterGroupManager *v2; // r3
  char v3; // [sp+50h] [-20h] BYREF

  p_encounterGroupManager = &gameLocal->encounterGroupManager;
  v2 = idEncounterGroupManager::HandleForName(
         this: (idEncounterGroupManager *)&v3,
         result: p_encounterGroupManager,
         groupName: handleName);
  if ( idEncounterGroupManager::GroupForHandle(
         this: p_encounterGroupManager,
         handle: (const idHandle<short,enum invalidEncounterGroup_t,-1> *)v2) == nullptr )
    idLib::Error(fmt: "Be sure to create an encounter group manager for the turret gunner.");
}


// ========================================================================
// ?SetLaunchMinionTime@idTurretGunner@@AAAXXZ
// EA  : 0x82D00350
// RVA : 0x00D00350
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void __fastcall idTurretGunner::SetLaunchMinionTime(idTurretGunner *this)
{
  idEncounterGroupManager *p_encounterGroupManager; // r30
  idEncounterGroupManager *v3; // r3
  idEncounterGroup *v4; // r3
  int GameMs; // r28
  char v6; // [sp+50h] [-30h] BYREF

  p_encounterGroupManager = &gameLocal->encounterGroupManager;
  v3 = idEncounterGroupManager::HandleForName(
         this: (idEncounterGroupManager *)&v6,
         result: p_encounterGroupManager,
         groupName: "turret_spawner");
  v4 = idEncounterGroupManager::GroupForHandle(
         this: p_encounterGroupManager,
         handle: (const idHandle<short,enum invalidEncounterGroup_t,-1> *)v3);
  if ( v4 == nullptr )
    idLib::Error(fmt: "Be sure to create an encounter group manager for the turret gunner.");
  if ( idEncounterGroup::NumLivingMembers(this: v4) != 0 )
  {
    this->launchMinionTime = 0;
  }
  else if ( this->launchMinionTime == 0 )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->launchMinionTime = GetRandomIntervalBySeconds(
                               minSecs: (float)(this->spawnerControlGroup->minTriggerDownDuration - this->minMinionHeadStartTime),
                               maxSecs: (float)(this->spawnerControlGroup->maxTriggerDownDuration - this->minMinionHeadStartTime))
                           + GameMs;
    if ( this->launchMinionTime < idGameTimeManager::GetGameMs(
                                    this: &clientGame->gameTimeManager,
                                    type: GAMETIME_SCALED)
                                + 3000 )
      this->launchMinionTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                             + 3000;
  }
}


// ========================================================================
// ?GetAimPoint@idTurretGunner@@UBAXW4aimPoint_t@@AAVidVec3@@@Z
// EA  : 0x82D00450
// RVA : 0x00D00450
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void __fastcall idTurretGunner::GetAimPoint(idTurretGunner *this, const aimPoint_t type, idVec3 *pos)
{
  idPhysics *Physics; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v8; // r29
  idIndex<short,enum invalidJointIndex_t> *decl; // r4
  unsigned __int16 v10; // [sp+50h] [-60h] BYREF
  idMat3 v11[2]; // [sp+60h] [-50h] BYREF

  Physics = idEntity::GetPhysics(this);
  *pos = *Physics->GetOrigin(this: Physics, a2: 0);
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
    decl = (idIndex<short,enum invalidJointIndex_t> *)v8->decl;
    if ( decl != nullptr )
    {
      idDeclMD6::GetJointIndex(this: (idDeclMD6 *)&v10, result: decl, jointName: "head");
      if ( v10 != 0xFFFF )
        idTreeAnimator::GetWorldSpaceJointTransform(
          this: v8,
          pose: DRIVER_MODEL,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)v10,
          origin: pos,
          axis: v11);
    }
  }
}


// ========================================================================
// ?GetCombatStage@idTurretGunner@@CAPBVidCombatStage@@PBD@Z
// EA  : 0x82D00510
// RVA : 0x00D00510
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void __fastcall idTurretGunner::GetCombatStage(const char *handleName)
{
  idEncounterGroupManager *p_encounterGroupManager; // r31
  idEncounterGroupManager *v2; // r3
  idEncounterGroup *v3; // r3
  char v4; // [sp+50h] [-20h] BYREF

  p_encounterGroupManager = &gameLocal->encounterGroupManager;
  v2 = idEncounterGroupManager::HandleForName(
         this: (idEncounterGroupManager *)&v4,
         result: p_encounterGroupManager,
         groupName: handleName);
  v3 = idEncounterGroupManager::GroupForHandle(
         this: p_encounterGroupManager,
         handle: (const idHandle<short,enum invalidEncounterGroup_t,-1> *)v2);
  if ( v3 == nullptr )
    idLib::Error(fmt: "Be sure to create an encounter group manager for the turret gunner.");
  if ( v3->combatStages.num <= 0 || v3->combatStages.list == nullptr )
    idLib::Error(fmt: "There must be a combat stage in the turret gunner's entity spawner.");
}


// ========================================================================
// ?GetTurretSpawnerControlGroup@idTurretGunner@@CAPAVidTurretSpawnerControlGroup@@PAVidEncounterGroup@@@Z
// EA  : 0x82D00628
// RVA : 0x00D00628
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void __fastcall idTurretGunner::GetTurretSpawnerControlGroup(idEncounterGroup *encounterGroup)
{
  idCombatStage *list; // r11
  int value; // r11
  int v3; // r31
  int v4; // r30
  idAIHintGroup *v5; // r3
  idAIHintGroup *v6; // r3
  idTurretSpawnerControlGroup *v7; // r3

  if ( encounterGroup->combatStages.num <= 0 || (list = encounterGroup->combatStages.list) == nullptr )
    idLib::Error(fmt: "There must be a combat stage in the turret gunner's entity spawner.");
  value = list->hintGroup.spawnId.value;
  v3 = value & 0x1FFF;
  v4 = value >> 13;
  if ( gameLocal->spawnIds.ptr[v3] != value >> 13
    || (v5 = (idAIHintGroup *)gameLocal->entities.ptr[v3]) == nullptr
    || idAIHintGroup::CastTo(c: v5) == nullptr )
  {
    idLib::Error(fmt: "The turret gunner's combat stage is missing an entity.");
  }
  if ( gameLocal->spawnIds.ptr[v3] == v4 && (v6 = (idAIHintGroup *)gameLocal->entities.ptr[v3]) != nullptr )
    v7 = (idTurretSpawnerControlGroup *)idAIHintGroup::CastTo(c: v6);
  else
    v7 = nullptr;
  if ( idTurretSpawnerControlGroup::CastTo(c: v7) == nullptr )
    idLib::Error(fmt: "The turret gunner's entity spawner is not an idTurretSpawnerControlGroup.");
}


// ========================================================================
// ?GetTurretSpawnerControlGroup@idTurretGunner@@CAPAVidTurretSpawnerControlGroup@@PBD@Z
// EA  : 0x82D00708
// RVA : 0x00D00708
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void __fastcall idTurretGunner::GetTurretSpawnerControlGroup(const char *handleName)
{
  idEncounterGroupManager *p_encounterGroupManager; // r31
  idEncounterGroupManager *v2; // r3
  idEncounterGroup *v3; // r3
  char v4; // [sp+50h] [-20h] BYREF

  p_encounterGroupManager = &gameLocal->encounterGroupManager;
  v2 = idEncounterGroupManager::HandleForName(
         this: (idEncounterGroupManager *)&v4,
         result: p_encounterGroupManager,
         groupName: handleName);
  v3 = idEncounterGroupManager::GroupForHandle(
         this: p_encounterGroupManager,
         handle: (const idHandle<short,enum invalidEncounterGroup_t,-1> *)v2);
  if ( v3 == nullptr )
    idLib::Error(fmt: "Be sure to create an encounter group manager for the turret gunner.");
  idTurretGunner::GetTurretSpawnerControlGroup(encounterGroup: v3);
}


// ========================================================================
// ??0idTurretGunner@@QAA@XZ
// EA  : 0x82D00778
// RVA : 0x00D00778
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

idTurretGunner *__fastcall idTurretGunner::idTurretGunner(idTurretGunner *this)
{
  idAnimatedEntity::idAnimatedEntity(this);
  this->webDecl = nullptr;
  this->__vftable = (idTurretGunner_vtbl *)&idTurretGunner::`vftable';
  this->minMinionHeadStartTime = 2.0;
  this->declTrackingParms = nullptr;
  this->maxMinionHeadStartTime = 3.0;
  idFaction::idFaction(this: &this->faction);
  this->aiPortrait = nullptr;
  this->radiusDamageJointNames.granularity = 0;
  this->radiusDamageJointNames.memTag = 5;
  this->radiusDamageJointNames.listStatic = 0;
  this->radiusDamageJointNames.list = nullptr;
  this->radiusDamageJointNames.size = 0;
  this->radiusDamageJointNames.num = 0;
  this->goreDef = nullptr;
  idGoreComponent::idGoreComponent(this: &this->goreComponent);
  this->spawnerControlGroup = nullptr;
  this->isGunnerInitialized = false;
  this->canFire = false;
  this->gunnerAimPoint.x = 0.0;
  this->gunnerAimPoint.y = 0.0;
  this->gunnerAimPoint.z = 0.0;
  idAnimator_AnimWeb::idAnimator_AnimWeb(this: &this->animWeb);
  this->animWeb.gunner = nullptr;
  this->animWeb.__vftable = (idAnimWeb_TurretGunner_vtbl *)&idAnimWeb_TurretGunner::`vftable';
  idAnimator_Channel::idAnimator_Channel(this: &this->painAnimator);
  idFaceMgr::idFaceMgr(this: &this->faceMgr);
  idAIWorldState::idAIWorldState(this: &this->worldState);
  this->enemy.spawnId.value = 0x1FFF;
  this->oldNumKilled = 0;
  this->randomLivingMinion.spawnId.value = 0x1FFF;
  this->numSkippedPinatas = 0;
  this->pinataMinion.spawnId.value = 0x1FFF;
  this->maxHealth = 0.0;
  this->health = 0.0;
  this->forgivePinataMinionTime = 0;
  this->currTriggerDownAdjust = 0.0;
  this->didBonusDamageForThisTaunt = false;
  this->currFireIntervalAdjust = 0.0;
  this->nextFireTime = 0;
  this->pullTriggerTime = 0;
  this->releaseTriggerTime = 0;
  this->launchInitialMinionTime = 0;
  this->launchMinionTime = 0;
  this->minionEscalationLevel = 0;
  this->overheatTime = 0;
  this->currentFiringPhaseOn = FIRINGPHASE_SHOOTING_AT_PLAYER;
  this->endPhaseTime = 0;
  this->pullTriggerPhase = TRIGGERPHASE_IDLE;
  this->pullTriggerPhaseEndTime = 0;
  this->closestFireHint.spawnId.value = 0x1FFF;
  this->anticipatedFireHint.spawnId.value = 0x1FFF;
  this->otherFireHintsList.list = nullptr;
  this->otherFireHintsList.granularity = 0;
  this->otherFireHintsList.memTag = 5;
  this->otherFireHintsList.listStatic = 0;
  this->otherFireHintsList.size = 0;
  this->otherFireHintsList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->otherFireHintsList);
  this->otherFireHintOn = 0;
  this->lastFireHintUsed.spawnId.value = 0x1FFF;
  this->currentSuppressionFireHint.spawnId.value = 0x1FFF;
  this->startStrafeTime = 0;
  this->endStrafeTime = 0;
  this->thisStrafeTime = 0;
  this->startStrafePoint.x = 0.0;
  this->startStrafePoint.y = 0.0;
  this->startStrafePoint.z = 0.0;
  this->endStrafePoint.x = 0.0;
  this->endStrafePoint.y = 0.0;
  this->endStrafePoint.z = 0.0;
  return this;
}


// ========================================================================
// __unwind$491334
// EA  : 0x82D00968
// RVA : 0x00D00968
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_491334()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$491335
// EA  : 0x82D00990
// RVA : 0x00D00990
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_491335()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 144 + 164) + 5216));
}


// ========================================================================
// __unwind$491336
// EA  : 0x82D009BC
// RVA : 0x00D009BC
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_491336()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 144 + 164) + 5240));
}


// ========================================================================
// __unwind$491337
// EA  : 0x82D009E8
// RVA : 0x00D009E8
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_491337()
{
  int v0; // r12

  idGoreComponent::~idGoreComponent(this: (idGoreComponent *)(*(_DWORD *)(v0 - 144 + 164) + 5264));
}


// ========================================================================
// __unwind$491338
// EA  : 0x82D00A14
// RVA : 0x00D00A14
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_491338()
{
  int v0; // r12

  idAnimWeb_TurretGunner::~idAnimWeb_TurretGunner(this: (idAnimWeb_TurretGunner *)(*(_DWORD *)(v0 - 144 + 164) + 5404));
}


// ========================================================================
// __unwind$491339
// EA  : 0x82D00A40
// RVA : 0x00D00A40
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_491339()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 144 + 164) + 6056));
}


// ========================================================================
// __unwind$491340
// EA  : 0x82D00A6C
// RVA : 0x00D00A6C
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_491340()
{
  int v0; // r12

  idFaceMgr::~idFaceMgr(this: (idFaceMgr *)(*(_DWORD *)(v0 - 144 + 164) + 6152));
}


// ========================================================================
// __unwind$491341
// EA  : 0x82D00A98
// RVA : 0x00D00A98
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_491341()
{
  int v0; // r12

  idAIWorldState::~idAIWorldState(this: (idAIWorldState *)(*(_DWORD *)(v0 - 144 + 164) + 8096));
}


// ========================================================================
// ??1idTurretGunner@@UAA@XZ
// EA  : 0x82D00B30
// RVA : 0x00D00B30
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void __fastcall idTurretGunner::~idTurretGunner(idTurretGunner *this)
{
  int v2; // r4
  idList<idEntityPtr<idEntity>,58> *p_aiWorldStateUsers; // r3
  int num; // r10
  int v5; // r11
  idStr *list; // r3
  int entityNumber; // [sp+50h] [-30h]

  this->__vftable = (idTurretGunner_vtbl *)&idTurretGunner::`vftable';
  v2 = 0;
  entityNumber = this->entityNumber;
  p_aiWorldStateUsers = (idList<idEntityPtr<idEntity>,58> *)&gameLocal->aiWorldStateUsers;
  num = gameLocal->aiWorldStateUsers.num;
  if ( num > 0 )
  {
    v5 = 0;
    while ( p_aiWorldStateUsers->list[v5].spawnId.value != ((gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber) )
    {
      ++v2;
      ++v5;
      if ( v2 >= num )
        goto LABEL_8;
    }
    if ( v2 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_aiWorldStateUsers, index: v2);
  }
LABEL_8:
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->otherFireHintsList);
  idAIWorldState::~idAIWorldState(this: &this->worldState);
  idFaceMgr::~idFaceMgr(this: &this->faceMgr);
  idAnimator_Channel::~idAnimator_Channel(this: &this->painAnimator);
  this->animWeb.__vftable = (idAnimWeb_TurretGunner_vtbl *)&idAnimWeb_TurretGunner::`vftable';
  idAnimator_AnimWeb::~idAnimator_AnimWeb(this: &this->animWeb);
  idGoreComponent::~idGoreComponent(this: &this->goreComponent);
  if ( this->radiusDamageJointNames.listStatic == 0 || this->radiusDamageJointNames.listStatic == 2 )
  {
    list = this->radiusDamageJointNames.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->radiusDamageJointNames.size);
    this->radiusDamageJointNames.list = nullptr;
    this->radiusDamageJointNames.size = 0;
  }
  this->radiusDamageJointNames.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->faction.relationships);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$492063_0
// EA  : 0x82D00C58
// RVA : 0x00D00C58
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_492063_0()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$492064_1
// EA  : 0x82D00C80
// RVA : 0x00D00C80
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_492064_1()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 128 + 148) + 5216));
}


// ========================================================================
// __unwind$492065_0
// EA  : 0x82D00CAC
// RVA : 0x00D00CAC
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_492065_0()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 128 + 148) + 5240));
}


// ========================================================================
// __unwind$492066
// EA  : 0x82D00CD8
// RVA : 0x00D00CD8
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_492066()
{
  int v0; // r12

  idGoreComponent::~idGoreComponent(this: (idGoreComponent *)(*(_DWORD *)(v0 - 128 + 148) + 5264));
}


// ========================================================================
// __unwind$492067_0
// EA  : 0x82D00D04
// RVA : 0x00D00D04
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_492067_0()
{
  int v0; // r12

  idAnimWeb_TurretGunner::~idAnimWeb_TurretGunner(this: (idAnimWeb_TurretGunner *)(*(_DWORD *)(v0 - 128 + 148) + 5404));
}


// ========================================================================
// __unwind$492068_0
// EA  : 0x82D00D30
// RVA : 0x00D00D30
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_492068_0()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 128 + 148) + 6056));
}


// ========================================================================
// __unwind$492069_0
// EA  : 0x82D00D5C
// RVA : 0x00D00D5C
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_492069_0()
{
  int v0; // r12

  idFaceMgr::~idFaceMgr(this: (idFaceMgr *)(*(_DWORD *)(v0 - 128 + 148) + 6152));
}


// ========================================================================
// __unwind$492070
// EA  : 0x82D00D88
// RVA : 0x00D00D88
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_492070()
{
  int v0; // r12

  idAIWorldState::~idAIWorldState(this: (idAIWorldState *)(*(_DWORD *)(v0 - 128 + 148) + 8096));
}


// ========================================================================
// ?DormantBegin@idTurretGunner@@UAAXXZ
// EA  : 0x82D00DB8
// RVA : 0x00D00DB8
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void __fastcall idTurretGunner::DormantBegin(idTurretGunner *this)
{
  int v1; // r8
  int v2; // r4
  idList<idEntityPtr<idEntity>,58> *p_aiWorldStateUsers; // r3
  int num; // r10
  int i; // r11

  if ( this != nullptr )
    v1 = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
  else
    v1 = 0x1FFF;
  v2 = 0;
  p_aiWorldStateUsers = (idList<idEntityPtr<idEntity>,58> *)&gameLocal->aiWorldStateUsers;
  num = gameLocal->aiWorldStateUsers.num;
  if ( num > 0 )
  {
    for ( i = 0; p_aiWorldStateUsers->list[i].spawnId.value != v1; ++i )
    {
      if ( ++v2 >= num )
        return;
    }
    if ( v2 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_aiWorldStateUsers, index: v2);
  }
}


// ========================================================================
// ?LaunchMinionNow@idTurretGunner@@AAA_N_N@Z
// EA  : 0x82D00E38
// RVA : 0x00D00E38
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

int __fastcall idTurretGunner::LaunchMinionNow(idTurretGunner *this, bool launchHookGuy)
{
  const char *v3; // r3
  idEncounterGroup *v4; // r3
  idEncounterGroup *v5; // r30
  int launchMinionTime; // r11
  int launchInitialMinionTime; // r11
  int pullTriggerTime; // r11
  idTurretSpawnerControlGroup *v10; // r3
  int GameMs; // r30

  if ( launchHookGuy )
    v3 = "hook_guys_turret_spawner";
  else
    v3 = "turret_spawner";
  idTurretGunner::GetEncounterGroup(handleName: v3);
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  if ( idEncounterGroup::NumLivingMembers(this: v4) >= this->spawnerControlGroup->maxLivingMinions )
  {
    launchMinionTime = this->launchMinionTime;
    if ( launchMinionTime != 0 )
      this->launchMinionTime = launchMinionTime + 1000;
    launchInitialMinionTime = this->launchInitialMinionTime;
    if ( launchInitialMinionTime != 0 )
      this->launchInitialMinionTime = launchInitialMinionTime + 1000;
    pullTriggerTime = this->pullTriggerTime;
    if ( pullTriggerTime != 0 )
      this->pullTriggerTime = pullTriggerTime + 1000;
    return 0;
  }
  idTurretGunner::GetTurretSpawnerControlGroup(encounterGroup: v5);
  idTurretSpawnerControlGroup::SpawnNow(this: v10, hint: -1);
  this->launchMinionTime = 0;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->releaseTriggerTime = GetRandomIntervalBySeconds(
                               minSecs: this->minMinionHeadStartTime,
                               maxSecs: this->maxMinionHeadStartTime)
                           + GameMs;
  return 1;
}


// ========================================================================
// ?ReleaseTrigger@idTurretGunner@@AAAXXZ
// EA  : 0x82D00F40
// RVA : 0x00D00F40
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void __fastcall idTurretGunner::ReleaseTrigger(idTurretGunner *this)
{
  idVehicleMountedTurret *BindMaster; // r3
  idVehicleMountedTurret *v3; // r3
  idTurretGunner::triggerPhaseOn_t pullTriggerPhase; // r11
  int v5; // r3

  this->releaseTriggerTime = 0;
  BindMaster = (idVehicleMountedTurret *)idEntity::GetBindMaster(this);
  v3 = idVehicleMountedTurret::CastTo(c: BindMaster);
  idVehicleMountedTurret::ReleaseTrigger(this: v3);
  pullTriggerPhase = this->pullTriggerPhase;
  if ( pullTriggerPhase >= TRIGGERPHASE_START_PULL && pullTriggerPhase <= TRIGGERPHASE_FIRING )
  {
    if ( pullTriggerPhase == TRIGGERPHASE_START_PULL )
    {
      this->pullTriggerPhase = TRIGGERPHASE_IDLE;
    }
    else
    {
      idTurretGunner::GetTurretSpawnerControlGroup(handleName: "turret_spawner");
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_ENGINE_IDLE,
        shader: *(const idSoundShader **)(v5 + 848),
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
      this->pullTriggerPhase = TRIGGERPHASE_WINDING_DOWN;
      this->pullTriggerPhaseEndTime = TRIGGER_PHASE_TIME[this->pullTriggerPhase]
                                    + idGameTimeManager::GetGameMs(
                                        this: &clientGame->gameTimeManager,
                                        type: GAMETIME_SCALED);
    }
  }
}


// ========================================================================
// ?RaiseSeat@idTurretGunner@@QAAXXZ
// EA  : 0x82D01010
// RVA : 0x00D01010
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void __fastcall idTurretGunner::RaiseSeat(idTurretGunner *this)
{
  int GameMs; // r30
  unsigned __int16 v3; // [sp+50h] [-20h] BYREF
  unsigned __int16 v4; // [sp+52h] [-1Eh] BYREF

  idDeclAnimWeb::GetSubWebIndexForName(
    this: (idDeclAnimWeb *)&v4,
    result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->animWeb.decl,
    subWebName: "gunner");
  idDeclAnimWeb::GetStateIndexForName(
    this: (idDeclAnimWeb *)&v3,
    result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this->animWeb.decl,
    name: "idle");
  idAnimator_AnimWeb::ChangeState(
    this: &this->animWeb,
    subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v4,
    stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v3,
    interruptPath_: INTR_PATH_YES,
    interruptBlend_: INTR_BLEND_NO,
    blendEventMask_: 0);
  idAnimator_AnimWeb::SetEvent(
    this: &this->animWeb,
    eventType: ANIMWEB_EVENT_END_BLEND_IN,
    subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v4,
    stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v3,
    eventDef: &EV_AnimWeb_Raised,
    priority: PRIORITY_LOW);
  idTurretGunner::LaunchMinionNow(this, launchHookGuy: false);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->launchInitialMinionTime = GetRandomIntervalBySeconds(minSecs: 8.0, maxSecs: 12.0) + GameMs;
}


// ========================================================================
// ?Killed@idTurretGunner@@QAAXXZ
// EA  : 0x82D010F0
// RVA : 0x00D010F0
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void __fastcall idTurretGunner::Killed(idTurretGunner *this)
{
  idEncounterGroupManager *p_encounterGroupManager; // r29
  idEncounterGroupManager *v3; // r3
  idEncounterGroup *v4; // r3
  int v5; // r3
  int v6; // r9
  idEntity *v7; // r3
  idEntity *v8; // r3
  char v9; // [sp+50h] [-30h] BYREF

  this->canFire = false;
  this->health = 0.0;
  idAnimator_AnimWeb::ChangeState(
    this: &this->animWeb,
    subWebName: "gunner",
    stateName: "death",
    interruptPath_: INTR_PATH_YES,
    interruptBlend_: INTR_BLEND_YES,
    blendEventMask_: 0);
  idTurretGunner::ReleaseTrigger(this);
  p_encounterGroupManager = &gameLocal->encounterGroupManager;
  v3 = idEncounterGroupManager::HandleForName(
         this: (idEncounterGroupManager *)&v9,
         result: p_encounterGroupManager,
         groupName: "turret_spawner");
  v4 = idEncounterGroupManager::GroupForHandle(
         this: p_encounterGroupManager,
         handle: (const idHandle<short,enum invalidEncounterGroup_t,-1> *)v3);
  if ( v4 == nullptr )
    idLib::Error(fmt: "Be sure to create an encounter group manager for the turret gunner.");
  idTurretGunner::GetTurretSpawnerControlGroup(encounterGroup: v4);
  v6 = *(_DWORD *)(v5 + 852);
  if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13 )
  {
    v7 = gameLocal->entities.ptr[v6 & 0x1FFF];
    if ( v7 != nullptr )
    {
      v8 = idEntity::CastTo(c: v7);
      if ( v8 != nullptr )
        idEntity::Activate(this: v8, activator: this);
    }
  }
}


// ========================================================================
// ?Damage@idTurretGunner@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82D01248
// RVA : 0x00D01248
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

float __fastcall idTurretGunner::Damage(
        idTurretGunner *this,
        idEntity *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        const idVec3 *trace,
        int a8)
{
  double v14; // fp1
  double v15; // fp30
  BOOL didBonusDamageForThisTaunt; // r11
  const char *CurStateName; // r3
  double health; // fp0
  double bonusDamageWhenTaunting; // fp13
  const idIndex<short,enum invalidJointIndex_t> *v20; // r6
  idAIGameState *p_aiGameState; // r28
  const idEntityPtr<idAI2> *v22; // r27
  const idEntityPtr<idAI2> *v23; // r29
  const idSpawnId *v24; // r3
  idEntityPtr<idAI2> *v25; // r3
  const idSpawnId *v26; // r8
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v29; // r27
  int v30; // r11
  const idDeclMD6 *decl; // r11
  idJointGroupCollection *p_jointGroupCollection; // r4
  const idDeclMD6 *v33; // r11
  const idJointGroup *JointGroup; // r29
  int GameMs; // r29
  const idAnimStack *v36; // r3
  const blendParms_t *v37; // r7
  double v38; // fp1
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v40; // [sp+50h] [-D0h] BYREF
  idJointGroupCollection _54; // [sp+54h] [-CCh] BYREF

  v14 = idDeclDamage::DamageAmount(this: damageDef);
  v15 = (float)((float)v14 * (float)damageScale);
  if ( this->health > 0.0 )
  {
    didBonusDamageForThisTaunt = this->didBonusDamageForThisTaunt;
    this->health = this->health - (float)((float)v14 * (float)damageScale);
    if ( !didBonusDamageForThisTaunt )
    {
      CurStateName = idAnimator_AnimWeb::GetCurStateName(this: &this->animWeb);
      idStr::idStr(this: (idStr *)&_54.jointGroupsByType[3].granularity, text: CurStateName);
      if ( idStr::Cmp(s1: (const char *)_54.jointGroupsByType[4].list, s2: "taunt") == 0
        || idStr::Cmp(s1: (const char *)_54.jointGroupsByType[4].list, s2: "shoutorders") == 0 )
      {
        health = this->health;
        bonusDamageWhenTaunting = this->spawnerControlGroup->bonusDamageWhenTaunting;
        this->didBonusDamageForThisTaunt = true;
        this->health = (float)health - (float)bonusDamageWhenTaunting;
      }
      idStr::FreeData(this: (idStr *)&_54.jointGroupsByType[3].granularity);
    }
    if ( this->health > 0.0 )
    {
      p_aiGameState = &gameLocal->aiGameState;
      v22 = (const idEntityPtr<idAI2> *)idSpawnId::idSpawnId(this: (idSpawnId *)&_54, ent: this);
      v23 = (const idEntityPtr<idAI2> *)idSpawnId::idSpawnId(this: (idSpawnId *)&_54.jointGroups.num, ent: attacker);
      v24 = idSpawnId::idSpawnId(this: (idSpawnId *)&_54.jointGroups.size, ent: this);
      v25 = (idEntityPtr<idAI2> *)idAILogic::idAILogic(this: (idAILogic *)&_54.jointGroups.granularity, _spawnId: v24);
      idAIWorldState::AddEntityState(
        this: &this->worldState,
        gameState: p_aiGameState,
        owner: v25,
        entId: v23,
        stimulusType: AISTIMULUS_DAMAGE,
        stimulusAmount: 1.0,
        sourceId: v26,
        a8: v22);
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
      presentable = this->presentable;
      v29 = TreeAnimatorFromPresentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        presentable = this->presentable;
      }
      idPresentable::UpdateModelTransform(this: presentable);
      if ( a8 != 0 )
      {
        if ( *(_DWORD *)(a8 + 52) == 4 )
          v30 = *(_DWORD *)(a8 + 104);
        else
          LOWORD(v30) = -1;
        v20 = (const idIndex<short,enum invalidJointIndex_t> *)(__int16)v30;
        if ( (__int16)v30 != -1 )
        {
          decl = v29->decl;
          p_jointGroupCollection = &decl->jointGroupCollection;
          if ( decl == nullptr )
            p_jointGroupCollection = nullptr;
          idJointGroupCollection::GetJointGroupHandle(
            this: &_54,
            result: p_jointGroupCollection,
            type: 2,
            jointIndex: v20);
          v33 = v29->decl;
          if ( v33 != nullptr && v33 != (const idDeclMD6 *)-144 )
          {
            JointGroup = idJointGroupCollection::GetJointGroup(
                           this: &v33->jointGroupCollection,
                           handle: (const idHandle<int,enum invalidJointGroupHandle,0> *)&_54);
            if ( JointGroup != nullptr )
            {
              *(_DWORD *)&_54.jointGroupsByType[1].granularity = 0;
              HIBYTE(_54.jointGroupsByType[2].size) = 0;
              _54.jointGroupsByType[2].num = 20;
              _54.jointGroupsByType[2].list = (idJointGroup **)&_54.jointGroupsByType[2].size;
              idStr::operator=(this: (idStr *)&_54.jointGroupsByType[1].granularity, text: "hands/pain/twitch/");
              idStr::Append(this: (idStr *)&_54.jointGroupsByType[1].granularity, text: (char *)damageDirectionNames[1]);
              idStr::operator+=(this: (idStr *)&_54.jointGroupsByType[1].granularity, a: 47);
              idStr::Append(
                this: (idStr *)&_54.jointGroupsByType[1].granularity,
                text: (char *)JointGroup->groupName.str);
              idDeclMD6::FindAliasHandle(
                this: (idDeclMD6 *)&v40,
                result: v29->decl,
                aliasName: (const char *)_54.jointGroupsByType[2].list);
              if ( v40.value != 0xFFFF )
              {
                blendParms_t::blendParms_t(this: (blendParms_t *)&_54.jointGroups.granularity);
                blendParms_t::SetDurationMS(this: (blendParms_t *)&_54.jointGroups.granularity, ms: 0x32u);
                GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                v36 = this->GetAnimStack_2(this);
                idAnimator_Channel::PlayAnim(
                  this: &this->painAnimator,
                  stack: v36,
                  ah: &v40,
                  curTime: GameMs,
                  rateScale: 1.0,
                  blendParms: v37,
                  blendOutDurationMS_: (blendParms_t *)&_54.jointGroups.granularity,
                  leafStarted: (idMD6LeafPlay **)0x32,
                  a9: nullptr);
              }
              idStr::FreeData(this: (idStr *)&_54.jointGroupsByType[1].granularity);
            }
          }
        }
      }
    }
    else
    {
      idTurretGunner::Killed(this);
    }
    if ( damageDef != nullptr && a8 != 0 && *(_DWORD *)(a8 + 52) == 4 )
      idGoreComponent::AddDamage(
        this: &this->goreComponent,
        hitJoint: (idIndex<short,enum invalidJointIndex_t> *)(__int16)*(_DWORD *)(a8 + 104),
        damageDecl: damageDef,
        damage: (float)(damageDef->maxDamage * (float)2.0),
        impulse: (const idVec3 *)v20,
        pos: trace,
        normal: (const idVec3 *)(a8 + 4),
        damageGroup: (const idDamageGroup *)(a8 + 68),
        a9: 0);
  }
  v38 = v15;
  return *((float *)&v38 + 1);
}


// ========================================================================
// __unwind$492565
// EA  : 0x82D01588
// RVA : 0x00D01588
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_492565()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 160));
}


// ========================================================================
// __unwind$492566
// EA  : 0x82D015B0
// RVA : 0x00D015B0
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_492566()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 128));
}


// ========================================================================
// ?DormantEnd@idTurretGunner@@UAAXH@Z
// EA  : 0x82D015D8
// RVA : 0x00D015D8
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void __fastcall idTurretGunner::DormantEnd(idTurretGunner *this, const int timeDormant)
{
  int v2; // r7
  int v3; // r10
  idList<idEntityPtr<idEntity>,58> *p_aiWorldStateUsers; // r3
  int num; // r9
  int v6; // r11
  idEntityPtr<idEntity> v7; // [sp+50h] [-10h] BYREF

  if ( this != nullptr )
    v2 = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
  else
    v2 = 0x1FFF;
  v7.spawnId.value = v2;
  v3 = 0;
  p_aiWorldStateUsers = (idList<idEntityPtr<idEntity>,58> *)&gameLocal->aiWorldStateUsers;
  num = gameLocal->aiWorldStateUsers.num;
  if ( num <= 0 )
    goto LABEL_10;
  v6 = 0;
  while ( p_aiWorldStateUsers->list[v6].spawnId.value != v2 )
  {
    ++v3;
    ++v6;
    if ( v3 >= num )
      goto LABEL_10;
  }
  if ( v3 < 0 )
LABEL_10:
    idList<idEntityPtr<idEntity>,58>::Append(this: p_aiWorldStateUsers, obj: &v7);
}


// ========================================================================
// ?Spawn@idTurretGunner@@QAAXXZ
// EA  : 0x82D01680
// RVA : 0x00D01680
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void __fastcall idTurretGunner::Spawn(idTurretGunner *this)
{
  int v2; // r7
  idList<idEntityPtr<idEntity>,58> *p_aiWorldStateUsers; // r3
  int v4; // r10
  int num; // r9
  int v6; // r11
  idRenderModel *RenderModelFromPresentable; // r3
  idTreeAnimator *v8; // r27
  char *data; // r28
  int v10; // r25
  const idDeclAnimWeb *webDecl; // r24
  idAnimStack *v12; // r3
  idGameTimeManager *v13; // r3
  idAnimStack *v14; // r3
  idGameTimeManager *v15; // r3
  idPhysics *Physics; // r3
  idPresentable *presentable; // r3
  idPresentableAnimatedEntity *v18; // r4
  const char *v19; // [sp+8h] [-198h]
  bool v20; // [sp+Bh] [-195h]
  const char *v21; // [sp+Ch] [-194h]
  bool v22; // [sp+Fh] [-191h]
  int v23; // [sp+10h] [-190h]
  bool v24; // [sp+13h] [-18Dh]
  int v25; // [sp+14h] [-18Ch]
  bool v26; // [sp+17h] [-189h]
  int v27; // [sp+18h] [-188h]
  int v28; // [sp+18h] [-188h]
  int v29; // [sp+1Ch] [-184h]
  int v30; // [sp+1Ch] [-184h]
  int v31; // [sp+20h] [-180h]
  int v32; // [sp+20h] [-180h]
  int v33; // [sp+24h] [-17Ch]
  int v34; // [sp+24h] [-17Ch]
  int v35; // [sp+28h] [-178h]
  int v36; // [sp+28h] [-178h]
  int v37; // [sp+2Ch] [-174h]
  int v38; // [sp+2Ch] [-174h]
  int v39; // [sp+30h] [-170h]
  int v40; // [sp+30h] [-170h]
  int v41; // [sp+34h] [-16Ch]
  int v42; // [sp+34h] [-16Ch]
  int v43; // [sp+38h] [-168h]
  int v44; // [sp+38h] [-168h]
  int v45; // [sp+3Ch] [-164h]
  int v46; // [sp+3Ch] [-164h]
  int v47; // [sp+40h] [-160h]
  int v48; // [sp+40h] [-160h]
  int v49; // [sp+44h] [-15Ch]
  int v50; // [sp+44h] [-15Ch]
  int v51; // [sp+48h] [-158h]
  int v52; // [sp+48h] [-158h]
  int v53; // [sp+4Ch] [-154h]
  int v54; // [sp+4Ch] [-154h]
  int v55; // [sp+50h] [-150h]
  int v56; // [sp+50h] [-150h]
  int v57; // [sp+58h] [-148h]
  int v58; // [sp+58h] [-148h]
  int v59; // [sp+60h] [-140h]
  int v60; // [sp+60h] [-140h]
  int v61; // [sp+68h] [-138h]
  int v62; // [sp+68h] [-138h]
  idEntityPtr<idEntity> v63; // [sp+70h] [-130h] BYREF
  idAnimatorParms_Base v64; // [sp+80h] [-120h] BYREF
  idAnimatorParms_AnimWeb v65; // [sp+C0h] [-E0h] BYREF

  if ( this != nullptr )
    v2 = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
  else
    v2 = 0x1FFF;
  v63.spawnId.value = v2;
  p_aiWorldStateUsers = (idList<idEntityPtr<idEntity>,58> *)&gameLocal->aiWorldStateUsers;
  v4 = 0;
  num = gameLocal->aiWorldStateUsers.num;
  if ( num <= 0 )
    goto LABEL_10;
  v6 = 0;
  while ( p_aiWorldStateUsers->list[v6].spawnId.value != v2 )
  {
    ++v4;
    ++v6;
    if ( v4 >= num )
      goto LABEL_10;
  }
  if ( v4 < 0 )
LABEL_10:
    idList<idEntityPtr<idEntity>,58>::Append(this: p_aiWorldStateUsers, obj: &v63);
  if ( this->GetFaction(this) == nullptr )
    idLib::Error(fmt: "%s - turrent gunner has no faction set", this->name.data);
  RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
  v8 = (idTreeAnimator *)_RTDynamicCast(
                           inptr: RenderModelFromPresentable,
                           VfDelta: 0,
                           SrcType: &idRenderModel `RTTI Type Descriptor',
                           TargetType: &idTreeAnimator `RTTI Type Descriptor',
                           isReference: 0);
  if ( v8 == nullptr )
    idLib::Error(fmt: "%s - model is not a tree animator", this->name.data);
  data = this->name.data;
  v10 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  webDecl = this->webDecl;
  v12 = this->GetAnimStack_2(this);
  idAnimatorParms_AnimWeb::idAnimatorParms_AnimWeb(
    this: &v65,
    animStack_: v12,
    name_: data,
    blendOp_: BOP_LERP,
    originBlend_: ORIGINBLEND_BRANCH,
    weightGroup_: MD6_WEIGHTGROUP_ALL,
    filterGroup_: MD6_WEIGHTGROUP_ALL,
    alpha_: 1.0,
    webDecl_: (const idDeclAnimWeb *)"lowered",
    initialSubWebName_: v19,
    initialStateName_: v21,
    curTime_: v23,
    a13: v25,
    a14: v27,
    a15: v29,
    a16: v31,
    a17: v33,
    a18: v35,
    a19: v37,
    a20: v39,
    a21: v41,
    a22: v43,
    a23: v45,
    a24: v47,
    a25: v49,
    a26: v51,
    a27: v53,
    a28: v55,
    a29: webDecl,
    a30: v57,
    a31: "gunner",
    a32: v59,
    a33: "lowered",
    a34: v61,
    a35: v10);
  v13 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_Base::Init(this: &this->animWeb, gametimeManager: v13, parms: &v65);
  v14 = this->GetAnimStack_2(this);
  idAnimator_Base::SetEnabled(this: &this->animWeb, animStack: v14, enabled: true);
  this->animWeb.gunner = this;
  v64.animStack = this->GetAnimStack_2(this);
  idStr::idStr(this: &v64.name, text: "pain");
  v64.alpha = 1.0;
  memset(&v64.originBlend, 0, 12);
  v64.blendOp = BOP_ADD_RIGHT;
  v15 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_Base::Init(this: &this->painAnimator, gametimeManager: v15, parms: &v64);
  idFaceMgr::Init(
    this: &this->faceMgr,
    owner: this,
    ta: v8,
    mood: MOOD_NONE,
    voiceChannel: SND_CHANNEL_VOICE,
    enableMoodAnimation: true,
    enableLipSyncAnimation: true,
    enableGestureAnimation: true,
    enableEyeTracking: v20,
    useFaceSetupEyeTracking_: v22,
    enableBlinking: v24,
    enableLidDeformation: v26,
    a13: v28,
    a14: v30,
    a15: v32,
    a16: v34,
    a17: v36,
    a18: v38,
    a19: v40,
    a20: v42,
    a21: v44,
    a22: v46,
    a23: v48,
    a24: v50,
    a25: v52,
    a26: v54,
    a27: v56,
    a28: 0,
    a29: v58,
    a30: false,
    a31: v60,
    a32: 0,
    a33: v62,
    a34: 0);
  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 640, a3: -1);
  idEntity::BecomeActive(this, flags: 5);
  idAnimatedEntity::SetRadiusDamageJointIndices(this, jointNames: &this->radiusDamageJointNames);
  presentable = this->presentable;
  *(_BYTE *)&this->flags |= 2u;
  if ( presentable != nullptr )
    v18 = presentable->GetAnimatedEntityInterface(this: presentable);
  else
    v18 = nullptr;
  idGoreComponent::Init(this: &this->goreComponent, inPresentable: v18, inGoreDecl: this->goreDef);
  idStr::FreeData(this: &v64.name);
  idAnimatorParms_AnimWeb::~idAnimatorParms_AnimWeb(this: &v65);
}


// ========================================================================
// $LN79
// EA  : 0x82D01994
// RVA : 0x00D01994
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _LN79()
{
  int v0; // r12

  idAnimatorParms_AnimWeb::~idAnimatorParms_AnimWeb(this: (idAnimatorParms_AnimWeb *)(v0 - 416 + 192));
}


// ========================================================================
// __unwind$492896
// EA  : 0x82D019BC
// RVA : 0x00D019BC
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_492896()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 416 + 128));
}


// ========================================================================
// ?Think_CanFire@idTurretGunner@@AAAXXZ
// EA  : 0x82D019F0
// RVA : 0x00D019F0
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void __fastcall idTurretGunner::Think_CanFire(idTurretGunner *this)
{
  idVehicleMountedTurret *BindMaster; // r3
  idResourceList *v3; // r3
  double health; // fp0
  idVehicleMountedTurret *resourceListPtr; // r24
  idEncounterGroup *v6; // r3
  idEncounterGroup *v7; // r28
  int GameMs; // r3
  int launchMinionTime; // r11
  int v10; // r3
  int v11; // r29
  idEntityPtr<idEntity> *p_randomLivingMinion; // r29
  idAI2 *RandomLiveMember; // r3
  idEntityPtr<idEntity> *entityNumber; // r11
  int v15; // r29
  int numSkippedPinatas; // r11
  int v17; // r29
  int RandomInterval; // r3
  int releaseTriggerTime; // r11
  int value; // r11
  idEntityPtr<idEntity> *p_enemy; // r28
  char v22; // r29
  idFaction *v23; // r26
  const idEntity *v24; // r3
  const idSpawnId *v25; // r23
  const idSpawnId *v26; // r3
  bool v27; // r9
  bool v28; // r8
  idAIEntityState **v29; // r11
  idEntity *Entity; // r3
  int v31; // r9
  idEntity *v32; // r3
  int v33; // r29
  const idEntity *v34; // r3
  idAIEntityState *v35; // r28
  double currentHeat; // fp13
  idDeclAnimWeb_vtbl **p_otherFireHintsList; // r27
  idEntityPtr<idAICombatHint> *p_closestFireHint; // r28
  int v39; // r3
  double v40; // fp0
  double v41; // fp13
  double v42; // fp12
  idCombatStage *v43; // r3
  idCombatStage *v44; // r29
  idPhysics *v45; // r3
  const idVec3 *v46; // r3
  idDeclSource *y_low; // r6
  idDeclAnimWebNode **z_low; // r5
  idAICombatHint_SuppressionFirePoint *ClosestHintNodePtrByDot; // r29
  idAICombatHint_SuppressionFirePoint *v50; // r3
  int v51; // r26
  int i; // r23
  int j; // r29
  idAICombatHint *v54; // r3
  idAICombatHint_SuppressionFirePoint *v55; // r3
  idAICombatHint_SuppressionFirePoint *v56; // r3
  idAICombatHint_SuppressionFirePoint *v57; // r3
  idDeclAnimWeb_vtbl *v58; // r11
  int v59; // r11
  void (__fastcall *v60)(struct idDeclAnimWeb *); // r10
  int v61; // r3
  int v62; // r10
  int v63; // r11
  const char *CurStateName; // r3
  double currTriggerDownAdjust; // fp29
  double v66; // fp1
  int v67; // r29
  idAI2 *v68; // r3
  idAI2 *v69; // r28
  idEntity *v70; // r3
  idPhysics *Physics; // r3
  float *v72; // r3
  double v73; // fp31
  double v74; // fp30
  double v75; // fp29
  int v76; // r29
  idGameTimeManager *p_gameTimeManager; // r3
  bool v78; // zf
  int v79; // r3
  int endStrafeTime; // r11
  double v81; // fp1
  __int128 v82; // r7
  double v83; // fp0
  double v84; // fp10
  double v85; // fp12
  double v86; // fp2
  idEntityPtr<idAICombatHint> *v87; // r27
  const char *v88; // r11
  int num; // r29
  int v90; // r28
  int v91; // r26
  idAICombatHint *v92; // r3
  idAICombatHint_SuppressionFirePoint *Target; // r3
  idAICombatHint_SuppressionFirePoint *v94; // r3
  idAICombatHint_SuppressionFirePoint *v95; // r3
  float v96; // r11
  float x; // r10
  float y; // r9
  double v99; // fp9
  double z; // fp12
  idAICombatHint *v101; // r3
  idPhysics *v102; // r3
  float *v103; // r3
  double v104; // fp11
  int RandomIntervalBySeconds; // r3
  int startStrafeTime; // r11
  double v107; // fp13
  double v108; // fp12
  int v109; // r3
  idTurretGunner::firingPhaseOn_t currentFiringPhaseOn; // r9
  idEntityPtr<idAICombatHint> *p_currentSuppressionFireHint; // r29
  int v112; // r11
  idAICombatHint *v113; // r3
  idPhysics *v114; // r3
  int v115; // r3
  double v116; // fp0
  double v117; // fp13
  double v118; // fp12
  int v119; // r11
  double v120; // fp12
  double v121; // fp10
  double v122; // fp0
  double v123; // fp13
  idVehicleMountedTurret *v124; // r3
  idVehicleMountedTurret *v125; // r3
  idTurretGunner::triggerPhaseOn_t pullTriggerPhase; // r11
  int v127; // r3
  const char *v128; // r3
  double v129; // fp13
  double v130; // fp12
  int v131; // [sp+8h] [-248h]
  int v132; // [sp+Ch] [-244h]
  int v133; // [sp+10h] [-240h]
  int v134; // [sp+14h] [-23Ch]
  int v135; // [sp+18h] [-238h]
  int v136; // [sp+1Ch] [-234h]
  int v137; // [sp+20h] [-230h]
  int v138; // [sp+24h] [-22Ch]
  int v139; // [sp+28h] [-228h]
  int v140; // [sp+2Ch] [-224h]
  int v141; // [sp+30h] [-220h]
  int v142; // [sp+34h] [-21Ch]
  int v143; // [sp+38h] [-218h]
  int v144; // [sp+3Ch] [-214h]
  int v145; // [sp+40h] [-210h]
  int v146; // [sp+44h] [-20Ch]
  int v147; // [sp+48h] [-208h]
  int v148; // [sp+4Ch] [-204h]
  int v149; // [sp+50h] [-200h]
  idDeclAnimWeb v150; // [sp+60h] [-1F0h] BYREF
  const char *v151; // [sp+174h] [-DCh]

  *(float *)&v150.states.size = -1.0;
  *(float *)&v150.states.granularity = 0.25;
  *(float *)&v150.models.list = 1.5;
  *(float *)&v150.models.num = 0.5;
  *(float *)&v150.models.size = 0.5;
  *(float *)&v150.models.granularity = 0.5;
  *(float *)&v150.programaticallyDefined = -1.0;
  *(float *)&v150.declSource = 0.5;
  *(float *)&v150.nodes.list = 2.5;
  *(float *)&v150.nodes.num = 2.0;
  *(float *)&v150.nodes.size = 1.5;
  *(float *)&v150.nodes.granularity = 4.0;
  BindMaster = (idVehicleMountedTurret *)idEntity::GetBindMaster(this);
  v3 = (idResourceList *)idVehicleMountedTurret::CastTo(c: BindMaster);
  health = this->health;
  resourceListPtr = (idVehicleMountedTurret *)v3;
  v150.resourceListPtr = v3;
  if ( health <= 0.0 )
    return;
  idTurretGunner::GetEncounterGroup(handleName: "turret_spawner");
  v7 = v6;
  if ( v6 == nullptr )
    return;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  launchMinionTime = this->launchMinionTime;
  if ( GameMs >= launchMinionTime
    && launchMinionTime != 0
    && (unsigned __int8)idTurretGunner::LaunchMinionNow(this, launchHookGuy: false) != 0 )
  {
    this->launchMinionTime = 0;
  }
  v10 = idEncounterGroup::NumDeadMembers(this: v7);
  v11 = v10;
  if ( v10 == this->oldNumKilled )
  {
    p_randomLivingMinion = &this->randomLivingMinion;
    if ( idEntityPtr<idEntity const>::operator->(this: &this->randomLivingMinion) != nullptr )
      goto LABEL_25;
    RandomLiveMember = idEncounterGroup::GetRandomLiveMember(this: v7);
    if ( RandomLiveMember == nullptr )
    {
      p_randomLivingMinion->spawnId.value = 0x1FFF;
      goto LABEL_25;
    }
    entityNumber = (idEntityPtr<idEntity> *)RandomLiveMember->entityNumber;
    p_randomLivingMinion->spawnId.value = (*((_DWORD *)&gameLocal->__vftable + (_DWORD)entityNumber + 29755) << 13)
                                        | (unsigned int)entityNumber;
  }
  else
  {
    this->oldNumKilled = v10;
    if ( idVehicleMountedTurret::GetTriggerState(this: resourceListPtr) != TRIGGERSTATE_RELEASED
      || this->pullTriggerPhase != TRIGGERPHASE_IDLE )
    {
      if ( idEntityPtr<idEntity const>::operator->(this: &this->randomLivingMinion) != nullptr
        && idEntityPtr<idEntity const>::operator->(this: &this->pinataMinion) == nullptr )
      {
        numSkippedPinatas = this->numSkippedPinatas;
        if ( numSkippedPinatas == 0
          || RandomInt(max: 2 * (numSkippedPinatas + 5) + v11) < 10
          || (v17 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED),
              RandomInterval = GetRandomInterval(_min: 1500, _max: 3000),
              releaseTriggerTime = this->releaseTriggerTime,
              this->forgivePinataMinionTime = RandomInterval + v17,
              releaseTriggerTime != 0)
          && RandomInterval + v17 > releaseTriggerTime )
        {
          ++this->numSkippedPinatas;
        }
        else
        {
          value = this->randomLivingMinion.spawnId.value;
          v150.__vftable = (idDeclAnimWeb_vtbl *)&this->pinataMinion;
          this->pinataMinion.spawnId.value = value;
          this->numSkippedPinatas = 0;
        }
      }
    }
    else
    {
      idDeclAnimWeb::GetSubWebIndexForName(
        this: (idDeclAnimWeb *)&v150.name,
        result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->animWeb.decl,
        subWebName: "gunner");
      idDeclAnimWeb::GetStateIndexForName(
        this: &v150,
        result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this->animWeb.decl,
        name: "taunt");
      idDeclAnimWeb::GetStateIndexForName(
        this: (idDeclAnimWeb *)&v150.trackedMemory,
        result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this->animWeb.decl,
        name: "idle");
      idAnimator_AnimWeb::ChangeStateVia(
        this: &this->animWeb,
        subWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v150.name.str),
        stateIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v150.trackedMemory),
        _viaSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v150.name.str),
        _viaStateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v150.__vftable),
        interruptPath_: INTR_PATH_YES,
        interruptBlend_: INTR_BLEND_NO,
        blendEventMask_: 0);
      idAnimator_AnimWeb::SetEvent(
        this: &this->animWeb,
        eventType: ANIMWEB_EVENT_END_BLEND_IN,
        subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v150.name.str),
        stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v150.trackedMemory),
        eventDef: &EV_AnimWeb_Raised,
        priority: PRIORITY_LOW);
      this->didBonusDamageForThisTaunt = false;
      v15 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      this->nextFireTime = GetRandomIntervalBySeconds(
                             minSecs: this->spawnerControlGroup->minPostTauntWaitToFire,
                             maxSecs: this->spawnerControlGroup->maxPostTauntWaitToFire)
                         + v15;
    }
    entityNumber = &this->randomLivingMinion;
    this->randomLivingMinion.spawnId.value = 0x1FFF;
  }
  v150.__vftable = (idDeclAnimWeb_vtbl *)entityNumber;
LABEL_25:
  if ( idAccolade::Count(this: &clientGame->gameTimeManager) > 0 )
  {
    idTargetCache::Clear(this: &this->worldState.targetCache);
    p_enemy = &this->enemy;
    v22 = _cntlzw((unsigned int)idEntityPtr<idEntity const>::operator->(this: &this->enemy));
    v23 = this->GetFaction(this);
    v24 = idEntityPtr<idEntity const>::operator->(this: &this->enemy);
    v25 = idSpawnId::idSpawnId(this: (idSpawnId *)&v150, ent: v24);
    v26 = idSpawnId::idSpawnId(this: (idSpawnId *)&v150.name, ent: this);
    idAILogic::idAILogic(
      this: (idAILogic *)&v150.settings.editPos.z,
      spawnId_: v26,
      curEnemyId_: v25,
      encounterGroup_: nullptr,
      faction_: v23,
      combatTimeoutInterval_: -1.0,
      searchTimeoutInterval_: -1.0,
      isRelaxed_: v28,
      isSearching_: v27,
      a10: (v22 & 0x20) != 0,
      a11: v131,
      a12: v132,
      a13: v133,
      a14: v134,
      a15: v135,
      a16: v136,
      a17: v137,
      a18: v138,
      a19: v139,
      a20: v140,
      a21: v141,
      a22: v142,
      a23: v143,
      a24: v144,
      a25: v145,
      a26: v146,
      a27: v147,
      a28: v148,
      a29: v149,
      a30: false);
    idAIWorldState::ResolveDeferredQueries(
      this: &this->worldState,
      gameState: &gameLocal->aiGameState,
      aiOwner: (idAILogic *)&v150.settings.editPos.z);
    idAIWorldState::Update(
      this: &this->worldState,
      gameState: &gameLocal->aiGameState,
      aiOwner: (idAILogic *)&v150.settings.editPos.z,
      trackingParms: this->declTrackingParms->parms.list);
    idEnemyTargetFilter::idEnemyTargetFilter(this: (idEnemyTargetFilter *)&v150.subWebs, minAwareness_: AIAWARE_LOST);
    v150.edges.size = (int)&idEnemyTargetSelector::`vftable';
    idTargetList::idTargetList(this: (idTargetList *)&v150.scalars.size, targetCache_: &this->worldState.targetCache);
    if ( idTargetList::FindBestTarget(
           this: (idTargetList *)&v150.scalars.size,
           owner: (idAI2 *)this,
           filter: (idTargetFilter *)&v150.subWebs,
           selector: (const idTargetSelector *)&v150.edges.size) >= 0
      && *(int *)&v150.expandSubWebLinks >= 0 )
    {
      v29 = (idAIEntityState **)(52
                               * *(_DWORD *)(4 * *(_DWORD *)&v150.expandSubWebLinks
                                           + *(_DWORD *)&v150.scalars.granularity)
                               + *(_DWORD *)v150.scalars.size);
      if ( v29 != nullptr )
      {
        Entity = idAIEntityState::GetEntity(this: *v29);
        if ( Entity != nullptr )
        {
          v150.__vftable = (idDeclAnimWeb_vtbl *)Entity->entityNumber;
          p_enemy->spawnId.value = (*((_DWORD *)&gameLocal->__vftable + (int)&v150.__vftable[464].FreeData + 3) << 13)
                                 | (int)v150.__vftable;
        }
        else
        {
          p_enemy->spawnId.value = 0x1FFF;
        }
      }
    }
    idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)&v150.scalars.size);
    v150.edges.size = (int)&idTargetSelector::`vftable';
    v150.subWebs.list = (idDeclAnimWeb::idSubWebInfo *)&idTargetFilter::`vftable';
  }
  v31 = this->enemy.spawnId.value;
  v150.__vftable = (idDeclAnimWeb_vtbl *)&this->enemy;
  if ( gameLocal->spawnIds.ptr[v31 & 0x1FFF] == v31 >> 13
    && (v32 = gameLocal->entities.ptr[v31 & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v32) != nullptr )
  {
    v34 = idEntityPtr<idEntity const>::operator->(this: &this->enemy);
    v35 = idAIWorldState::StateForEntity(this: &this->worldState, ent: v34);
    if ( v35 == nullptr )
      idLib::Error(fmt: "Cannot get entity state for the turret gunner's enemy.");
    idAIEntityState::GetAimPoint(
      this: v35,
      sense: (const aiSense_t)v35->lastSense,
      aimPoint: AIMPOINT_BEST,
      point: (idVec3 *)((char *)&v150.idResource + 32));
    currentHeat = resourceListPtr->currentHeat;
    resourceListPtr->safeFireMode = true;
    if ( currentHeat < 100.0 )
    {
      if ( (unsigned __int8)idAIEntityState::IsVisible(this: v35) != 0 )
      {
        if ( idTurretGunner::PullTrigger(this) )
        {
          this->currentFiringPhaseOn = FIRINGPHASE_SHOOTING_AT_PLAYER;
          if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) / 250 % 2 != 0 )
            idAIEntityState::GetAimPoint(
              this: v35,
              sense: (const aiSense_t)v35->lastSense,
              aimPoint: AIMPOINT_HEAD,
              point: (idVec3 *)((char *)&v150.idResource + 32));
          *((float *)&v150.idResource + 8) = RandomFloat(min: -2.0, max: 2.0) + *((float *)&v150.idResource + 8);
          *(float *)&v150.textSource = RandomFloat(min: -2.0, max: 2.0) + *(float *)&v150.textSource;
          *(float *)&v150.textLength = RandomFloat(min: -2.0, max: 2.0) + *(float *)&v150.textLength;
        }
        this->launchMinionTime = 0;
        this->launchInitialMinionTime = 0;
      }
      else if ( this->currentFiringPhaseOn != FIRINGPHASE_SHOOTING_AT_PLAYER )
      {
        if ( idVehicleMountedTurret::GetTriggerState(this: resourceListPtr) != TRIGGERSTATE_RELEASED
          || this->pullTriggerTime != 0 )
        {
          if ( idEntityPtr<idEntity const>::operator->(this: &this->pinataMinion) != nullptr )
          {
            resourceListPtr->safeFireMode = false;
            idTurretGunner::PullTrigger(this);
            v68 = (idAI2 *)idEntityPtr<idEntity const>::operator->(this: &this->pinataMinion);
            v69 = idAI2::CastTo(c: v68);
            v70 = idEntityPtr<idEntity const>::operator->(this: &this->pinataMinion);
            Physics = idEntity::GetPhysics(this: v70);
            v72 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
            v73 = *v72;
            v74 = v72[1];
            v75 = v72[2];
            v69->GetEyePos(this: v69, a2: (idVec3 *)&v150.subWebs.size);
            *(float *)&v150.textLength = (float)((float)v75 * (float)0.2)
                                       + (float)(*(float *)&v150.states.list * (float)0.80000001);
            *(float *)&v150.textSource = (float)((float)v74 * (float)0.2)
                                       + (float)(*(float *)&v150.subWebs.granularity * (float)0.80000001);
            *((float *)&v150.idResource + 8) = (float)((float)v73 * (float)0.2)
                                             + (float)(*(float *)&v150.subWebs.size * (float)0.80000001);
            if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->forgivePinataMinionTime )
            {
              v150.resourceListPtr = (idResourceList *)&this->pinataMinion;
              this->pinataMinion.spawnId.value = 0x1FFF;
            }
          }
          else if ( this->releaseTriggerTime != 0
                 && this->releaseTriggerTime <= idGameTimeManager::GetGameMs(
                                                  this: &clientGame->gameTimeManager,
                                                  type: GAMETIME_SCALED) )
          {
            idTurretGunner::ReleaseTrigger(this);
            idDeclAnimWeb::GetSubWebIndexForName(
              this: (idDeclAnimWeb *)&v150.trackedMemory,
              result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->animWeb.decl,
              subWebName: "gunner");
            idDeclAnimWeb::GetStateIndexForName(
              this: &v150,
              result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this->animWeb.decl,
              name: "shoutorders");
            idDeclAnimWeb::GetStateIndexForName(
              this: (idDeclAnimWeb *)&v150.name,
              result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this->animWeb.decl,
              name: "idle");
            idAnimator_AnimWeb::ChangeStateVia(
              this: &this->animWeb,
              subWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v150.trackedMemory),
              stateIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v150.name.str),
              _viaSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v150.trackedMemory),
              _viaStateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v150.__vftable),
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_NO,
              blendEventMask_: 0);
            idAnimator_AnimWeb::SetEvent(
              this: &this->animWeb,
              eventType: ANIMWEB_EVENT_END_BLEND_IN,
              subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v150.trackedMemory),
              stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v150.name.str),
              eventDef: &EV_AnimWeb_Raised,
              priority: PRIORITY_LOW);
            this->didBonusDamageForThisTaunt = false;
            v76 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            this->nextFireTime = GetRandomIntervalBySeconds(
                                   minSecs: (float)(this->spawnerControlGroup->minFireInterval * this->currFireIntervalAdjust),
                                   maxSecs: (float)(this->spawnerControlGroup->maxFireInterval * this->currFireIntervalAdjust))
                               + v76;
          }
          else if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->endPhaseTime )
          {
            this->startStrafeTime = idGameTimeManager::GetGameMs(
                                      this: &clientGame->gameTimeManager,
                                      type: GAMETIME_SCALED);
            this->thisStrafeTime = GetRandomIntervalBySeconds(minSecs: 0.1, maxSecs: 0.15000001);
            v109 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            currentFiringPhaseOn = this->currentFiringPhaseOn;
            this->endStrafeTime = this->thisStrafeTime + v109;
            p_currentSuppressionFireHint = &this->currentSuppressionFireHint;
            this->endPhaseTime = GetRandomIntervalBySeconds(
                                   minSecs: *((float *)&v150.states.size + currentFiringPhaseOn),
                                   maxSecs: *((float *)&v150.programaticallyDefined + currentFiringPhaseOn))
                               + this->endStrafeTime;
            this->currentSuppressionFireHint.spawnId.value = 0x1FFF;
            v150.resourceListPtr = (idResourceList *)&this->currentSuppressionFireHint;
            if ( idEntityPtr<idAICombatHint>::operator->(this: &this->closestFireHint) != nullptr )
            {
              v112 = this->closestFireHint.spawnId.value;
              v150.resourceListPtr = (idResourceList *)&this->currentSuppressionFireHint;
              p_currentSuppressionFireHint->spawnId.value = v112;
              if ( idEntityPtr<idAICombatHint>::operator->(this: &this->currentSuppressionFireHint) != nullptr )
              {
                v113 = idEntityPtr<idAICombatHint>::operator->(this: &this->currentSuppressionFireHint);
                v114 = idEntity::GetPhysics(this: v113);
                v115 = (int)v114->GetOrigin(this: v114, a2: 0);
                v116 = *(float *)v115;
                *((float *)&v150.idResource + 8) = *(float *)v115;
                v117 = *(float *)(v115 + 4);
                v150.textSource = *(char **)(v115 + 4);
                v150.resourceListPtr = (idResourceList *)&this->startStrafePoint;
                v118 = *(float *)(v115 + 8);
                this->startStrafePoint.x = v116;
                v150.resourceListPtr = (idResourceList *)&this->lastFireHintUsed;
                this->startStrafePoint.y = v117;
                this->startStrafePoint.z = v118;
                this->endStrafePoint.x = v116;
                this->endStrafePoint.y = v117;
                this->endStrafePoint.z = v118;
                v119 = p_currentSuppressionFireHint->spawnId.value;
                *(float *)&v150.textLength = v118;
                this->lastFireHintUsed.spawnId.value = v119;
              }
              else
              {
                v120 = *(float *)&v150.textLength;
                v121 = (float)(*(float *)&v150.textLength - 10.0);
                v122 = *(float *)&v150.textSource;
                v123 = *((float *)&v150.idResource + 8);
                this->startStrafePoint.y = *(float *)&v150.textSource;
                this->startStrafePoint.x = v123;
                this->startStrafePoint.z = (float)v120 + (float)20.0;
                this->endStrafePoint.z = v121;
                this->endStrafePoint.x = v123;
                this->endStrafePoint.y = v122;
                v150.resourceListPtr = (idResourceList *)&this->lastFireHintUsed;
                this->lastFireHintUsed = (idEntityPtr<idAICombatHint>)p_currentSuppressionFireHint->spawnId.value;
              }
            }
          }
          else
          {
            idTurretGunner::SetLaunchMinionTime(this);
            if ( this->pullTriggerTime != 0
              && this->pullTriggerTime <= idGameTimeManager::GetGameMs(
                                            this: &clientGame->gameTimeManager,
                                            type: GAMETIME_SCALED)
              && idTurretGunner::PullTrigger(this) )
            {
              this->pullTriggerTime = 0;
            }
            if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->endStrafeTime )
            {
              v87 = &this->currentSuppressionFireHint;
              if ( idEntityPtr<idAICombatHint>::operator->(this: &this->currentSuppressionFireHint) != nullptr )
              {
                v88 = (const char *)v87->spawnId.value;
                v87->spawnId.value = 0x1FFF;
                v150.resourceListPtr = (idResourceList *)&this->currentSuppressionFireHint;
                v150.name.str = v88;
                num = idEntityPtr<idAICombatHint>::operator->(this: (idEntityPtr<idAICombatHint> *)&v150.name)->targets.num;
                if ( num > 0 )
                {
                  v90 = 2 * num;
                  if ( 2 * num > 0 )
                  {
                    while ( 1 )
                    {
                      v91 = RandomInt(max: num);
                      v92 = idEntityPtr<idAICombatHint>::operator->(this: (idEntityPtr<idAICombatHint> *)&v150.name);
                      Target = (idAICombatHint_SuppressionFirePoint *)idEntity::GetTarget(this: v92, i: v91);
                      v94 = idAICombatHint_SuppressionFirePoint::CastTo(c: Target);
                      if ( v94 != nullptr )
                      {
                        v150.resourceListPtr = (idResourceList *)v94->entityNumber;
                        v150.__vftable = (idDeclAnimWeb_vtbl *)((*((_DWORD *)&gameLocal->__vftable
                                                                 + (int)&v150.resourceListPtr[28].hashTable[125]
                                                                 + 3) << 13)
                                                              | (int)v150.resourceListPtr);
                      }
                      else
                      {
                        v150.__vftable = (idDeclAnimWeb_vtbl *)0x1FFF;
                      }
                      if ( idEntityPtr<idAICombatHint_SuppressionFirePoint>::operator->(this: (idEntityPtr<idAICombatHint_SuppressionFirePoint> *)&v150) != nullptr
                        && idEntityPtr<idAICombatHint_SuppressionFirePoint>::operator->(this: (idEntityPtr<idAICombatHint_SuppressionFirePoint> *)&v150)->groupPriority == 0 )
                      {
                        break;
                      }
                      if ( --v90 <= 0 )
                        goto LABEL_122;
                    }
                    v95 = idEntityPtr<idAICombatHint_SuppressionFirePoint>::operator->(this: (idEntityPtr<idAICombatHint_SuppressionFirePoint> *)&v150);
                    if ( v95 != nullptr )
                    {
                      v150.resourceListPtr = (idResourceList *)v95->entityNumber;
                      v87->spawnId.value = (*((_DWORD *)&gameLocal->__vftable
                                            + (int)&v150.resourceListPtr[28].hashTable[125]
                                            + 3) << 13)
                                         | (int)v150.resourceListPtr;
                    }
                    else
                    {
                      v87->spawnId.value = 0x1FFF;
                    }
                  }
                }
              }
LABEL_122:
              if ( idEntityPtr<idAICombatHint>::operator->(this: &this->currentSuppressionFireHint) != nullptr )
              {
                this->startStrafePoint.x = this->endStrafePoint.x;
                this->startStrafePoint.y = this->endStrafePoint.y;
                v150.resourceListPtr = (idResourceList *)&this->endStrafePoint;
                z = this->endStrafePoint.z;
                v150.resourceListPtr = (idResourceList *)&this->startStrafePoint;
                this->startStrafePoint.z = z;
                v101 = idEntityPtr<idAICombatHint>::operator->(this: &this->currentSuppressionFireHint);
                v102 = idEntity::GetPhysics(this: v101);
                v103 = (float *)v102->GetOrigin(this: v102, a2: 0);
                v104 = *v103;
                v150.resourceListPtr = (idResourceList *)&this->endStrafePoint;
                this->endStrafePoint.x = v104;
                this->endStrafePoint.y = v103[1];
                this->endStrafePoint.z = v103[2];
              }
              else
              {
                v96 = this->startStrafePoint.z;
                x = this->startStrafePoint.x;
                this->startStrafePoint.x = this->endStrafePoint.x;
                y = this->startStrafePoint.y;
                this->startStrafePoint.y = this->endStrafePoint.y;
                *(float *)&v150.networkID = v96;
                *(float *)&v150.resourceListPtr = x;
                *(float *)&v150.resourceError = y;
                this->startStrafePoint.z = this->endStrafePoint.z;
                v99 = *(float *)&v150.resourceError;
                v150.resourceListPtr = (idResourceList *)&this->startStrafePoint;
                this->endStrafePoint.x = x;
                this->endStrafePoint.y = v99;
                this->endStrafePoint.z = v96;
              }
              this->startStrafeTime = idGameTimeManager::GetGameMs(
                                        this: &clientGame->gameTimeManager,
                                        type: GAMETIME_SCALED);
              RandomIntervalBySeconds = GetRandomIntervalBySeconds(minSecs: 0.5, maxSecs: 0.75);
              startStrafeTime = this->startStrafeTime;
              this->thisStrafeTime = RandomIntervalBySeconds;
              v150.resourceListPtr = (idResourceList *)&this->startStrafePoint;
              this->endStrafeTime = RandomIntervalBySeconds + startStrafeTime;
              v107 = this->startStrafePoint.y;
              v108 = this->startStrafePoint.z;
              *((float *)&v150.idResource + 8) = this->startStrafePoint.x;
              *(float *)&v150.textLength = v108;
              *(float *)&v150.textSource = v107;
            }
            else
            {
              v78 = idVehicleMountedTurret::GetTriggerState(this: resourceListPtr) != TRIGGERSTATE_PULLED;
              p_gameTimeManager = &clientGame->gameTimeManager;
              if ( v78 )
              {
                this->endStrafeTime = this->thisStrafeTime
                                    + idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
              }
              else
              {
                v79 = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
                endStrafeTime = this->endStrafeTime;
                v81 = (float)(this->startStrafePoint.x - this->endStrafePoint.x);
                LODWORD(v82) = endStrafeTime - v79;
                v83 = this->endStrafePoint.x;
                DWORD2(v82) = endStrafeTime - this->startStrafeTime;
                v84 = this->endStrafePoint.z;
                *(_QWORD *)&v150.resourceListPtr = v82;
                v85 = (float)(this->startStrafePoint.y - this->endStrafePoint.y);
                v86 = this->endStrafePoint.y;
                DWORD1(v82) = &this->startStrafePoint;
                *(float *)&v150.textLength = (float)v84
                                           + (float)((float)(this->startStrafePoint.z - (float)v84)
                                                   * (float)((float)(__int64)v82 / (float)*(__int64 *)((char *)&v82 + 4)));
                v150.resourceListPtr = (idResourceList *)&this->startStrafePoint;
                *(float *)&v150.textSource = (float)v86
                                           + (float)((float)v85
                                                   * (float)((float)(__int64)v82 / (float)*(__int64 *)((char *)&v82 + 4)));
                *((float *)&v150.idResource + 8) = (float)((float)v81
                                                         * (float)((float)(__int64)v82
                                                                 / (float)*(__int64 *)((char *)&v82 + 4)))
                                                 + (float)v83;
              }
            }
          }
        }
        else if ( this->nextFireTime <= idGameTimeManager::GetGameMs(
                                          this: &clientGame->gameTimeManager,
                                          type: GAMETIME_SCALED) )
        {
          currTriggerDownAdjust = this->currTriggerDownAdjust;
          if ( currTriggerDownAdjust <= RandomFloat(min: 0.1, max: 0.40000001) )
          {
            v66 = RandomFloat(min: 0.5, max: 0.89999998);
            this->currTriggerDownAdjust = v66;
            this->currFireIntervalAdjust = (float)1.0 / (float)v66;
          }
          else
          {
            this->currTriggerDownAdjust = this->currTriggerDownAdjust * (float)0.85000002;
            this->currFireIntervalAdjust = RandomFloat(min: 1.0, max: 1.3) * this->currFireIntervalAdjust;
          }
          this->currentSuppressionFireHint.spawnId.value = 0x1FFF;
          v150.resourceListPtr = (idResourceList *)&this->currentSuppressionFireHint;
          this->endPhaseTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v67 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          this->pullTriggerTime = GetRandomIntervalBySeconds(minSecs: 0.1, maxSecs: 0.15000001) + v67;
        }
      }
      else if ( idTurretGunner::PullTrigger(this) )
      {
        this->currentSuppressionFireHint.spawnId.value = 0x1FFF;
        p_otherFireHintsList = (idDeclAnimWeb_vtbl **)&this->otherFireHintsList;
        this->closestFireHint.spawnId.value = 0x1FFF;
        p_closestFireHint = &this->closestFireHint;
        this->anticipatedFireHint.spawnId.value = 0x1FFF;
        v150.__vftable = (idDeclAnimWeb_vtbl *)&this->currentSuppressionFireHint;
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->otherFireHintsList);
        this->lastFireHintUsed.spawnId.value = 0x1FFF;
        this->pullTriggerTime = 0;
        this->releaseTriggerTime = 0;
        v150.__vftable = (idDeclAnimWeb_vtbl *)&this->lastFireHintUsed;
        idTurretGunner::SetLaunchMinionTime(this);
        this->currentFiringPhaseOn = FIRINGPHASE_SHOOTING_AT_PLAYERS_LAST_POSITION;
        this->currTriggerDownAdjust = 0.80000001;
        this->currFireIntervalAdjust = 1.3;
        v39 = GetRandomIntervalBySeconds(minSecs: 0.25, maxSecs: 0.5);
        v40 = *((float *)&v150.idResource + 8);
        v41 = *(float *)&v150.textSource;
        v42 = *(float *)&v150.textLength;
        this->endPhaseTime = v39 + this->startStrafeTime;
        this->startStrafePoint.x = v40;
        this->startStrafePoint.y = v41;
        this->startStrafePoint.z = v42;
        this->endStrafePoint.x = v40;
        this->endStrafePoint.y = v41;
        v150.__vftable = (idDeclAnimWeb_vtbl *)&this->endStrafePoint;
        this->endStrafePoint.z = v42;
        idTurretGunner::GetCombatStage(handleName: "turret_suppression_fire");
        v44 = v43;
        v45 = idEntity::GetPhysics(this);
        v46 = v45->GetOrigin(this: v45, a2: 0);
        y_low = (idDeclSource *)LODWORD(v46->y);
        z_low = (idDeclAnimWebNode **)LODWORD(v46->z);
        *(float *)&v150.programaticallyDefined = v46->x;
        v150.declSource = y_low;
        v150.nodes.list = z_low;
        if ( idCombatStage::GetNumHintNodes(this: v44, hintType: 7u) == nullptr )
          idCombatStage::CategorizeHintGroupCombatNodes(this: v44);
        ClosestHintNodePtrByDot = (idAICombatHint_SuppressionFirePoint *)idCombatStage::GetClosestHintNodePtrByDot(
                                                                           this: v44,
                                                                           hintType: 7u,
                                                                           startPos: (const idVec3 *)&v150.programaticallyDefined,
                                                                           endPos: (const idVec3 *)((char *)&v150.idResource + 32));
        v50 = idAICombatHint_SuppressionFirePoint::CastTo(c: ClosestHintNodePtrByDot);
        if ( v50 != nullptr )
        {
          v150.__vftable = (idDeclAnimWeb_vtbl *)v50->entityNumber;
          p_closestFireHint->spawnId.value = (*((_DWORD *)&gameLocal->__vftable + (int)&v150.__vftable[464].FreeData + 3) << 13)
                                           | (int)v150.__vftable;
        }
        else
        {
          p_closestFireHint->spawnId.value = 0x1FFF;
        }
        if ( idEntityPtr<idAICombatHint>::operator->(this: &this->closestFireHint) == nullptr )
        {
          if ( ClosestHintNodePtrByDot == nullptr )
            idLib::Error(fmt: "There is a problem with one of the 'turret_suppression_fire' targets.");
          idLib::Error(fmt: "One of the 'turret_suppression_fire' targets is not an idAICombatHint_SuppressionFirePoint.");
        }
        v51 = idEntityPtr<idAICombatHint>::operator->(this: &this->closestFireHint)->targets.num;
        for ( i = 3; i > 0; --i )
        {
          for ( j = 0; j < v51; ++j )
          {
            v54 = idEntityPtr<idAICombatHint>::operator->(this: &this->closestFireHint);
            v55 = (idAICombatHint_SuppressionFirePoint *)idEntity::GetTarget(this: v54, i: j);
            v56 = idAICombatHint_SuppressionFirePoint::CastTo(c: v55);
            if ( v56 != nullptr && v56->groupPriority == i )
            {
              v57 = idAICombatHint_SuppressionFirePoint::CastTo(c: v56);
              if ( v57 != nullptr )
              {
                v150.__vftable = (idDeclAnimWeb_vtbl *)v57->entityNumber;
                v150.__vftable = (idDeclAnimWeb_vtbl *)((int)v150.__vftable
                                                      | (*((_DWORD *)&gameLocal->__vftable
                                                         + (int)&v150.__vftable[464].FreeData
                                                         + 3) << 13));
              }
              else
              {
                v150.__vftable = (idDeclAnimWeb_vtbl *)0x1FFF;
              }
              idList<idEntityPtr<idEntity>,58>::Insert(
                this: &this->otherFireHintsList,
                obj: (const idEntityPtr<idAICombatHint> *)&v150,
                index: 0);
            }
          }
          if ( idEntityPtr<idAICombatHint>::operator->(this: &this->anticipatedFireHint) == nullptr
            && this->otherFireHintsList.num == 1 )
          {
            v58 = *p_otherFireHintsList;
            v150.__vftable = (idDeclAnimWeb_vtbl *)&this->anticipatedFireHint;
            this->anticipatedFireHint.spawnId.value = (int)v58->dtr_idResource;
            v59 = this->otherFireHintsList.num;
            if ( v59 > 0 )
            {
              this->otherFireHintsList.num = v59 - 1;
              if ( v59 != 1 )
              {
                v60 = *((void (__fastcall **)(struct idDeclAnimWeb *))*p_otherFireHintsList + v59 - 1);
                v150.__vftable = *p_otherFireHintsList;
                v150.dtr_idResource = v60;
              }
            }
          }
        }
        v61 = RandomInt(max: this->otherFireHintsList.num);
        v62 = this->otherFireHintsList.num;
        v63 = 0;
        for ( this->otherFireHintOn = v61; v63 < v62; ++v63 )
          ;
        resourceListPtr = (idVehicleMountedTurret *)v150.resourceListPtr;
      }
    }
    else if ( this->overheatTime > 0 )
    {
      if ( this->overheatTime < idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
      {
        this->overheatTime = 0;
        resourceListPtr->currentHeat = 0.0;
      }
    }
    else
    {
      idTurretGunner::ReleaseTrigger(this);
      idDeclAnimWeb::GetSubWebIndexForName(
        this: (idDeclAnimWeb *)&v150.trackedMemory,
        result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->animWeb.decl,
        subWebName: "gunner");
      idDeclAnimWeb::GetStateIndexForName(
        this: &v150,
        result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this->animWeb.decl,
        name: "rage");
      idDeclAnimWeb::GetStateIndexForName(
        this: (idDeclAnimWeb *)&v150.name,
        result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this->animWeb.decl,
        name: "idle");
      idAnimator_AnimWeb::ChangeStateVia(
        this: &this->animWeb,
        subWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v150.trackedMemory),
        stateIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v150.name.str),
        _viaSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v150.trackedMemory),
        _viaStateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v150.__vftable),
        interruptPath_: INTR_PATH_YES,
        interruptBlend_: INTR_BLEND_NO,
        blendEventMask_: 0);
      idAnimator_AnimWeb::SetEvent(
        this: &this->animWeb,
        eventType: ANIMWEB_EVENT_END_BLEND_IN,
        subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v150.trackedMemory),
        stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v150.name.str),
        eventDef: &EV_AnimWeb_Raised,
        priority: PRIORITY_LOW);
      this->didBonusDamageForThisTaunt = false;
      this->overheatTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                         + 5000;
    }
    if ( this->pullTriggerPhaseEndTime != 0
      && this->pullTriggerPhaseEndTime <= idGameTimeManager::GetGameMs(
                                            this: &clientGame->gameTimeManager,
                                            type: GAMETIME_SCALED) )
    {
      CurStateName = idAnimator_AnimWeb::GetCurStateName(this: &this->animWeb);
      idStr::idStr(this: (idStr *)&v150.edgeCache.size, text: CurStateName);
      if ( idStr::Cmp(s1: *(const char **)&v150.edgeCache.granularity, s2: "idle") != 0
        && idStr::Cmp(s1: *(const char **)&v150.edgeCache.granularity, s2: "firing") != 0 )
      {
        idTurretGunner::ReleaseTrigger(this);
      }
      else
      {
        v124 = (idVehicleMountedTurret *)idEntity::GetBindMaster(this);
        v125 = idVehicleMountedTurret::CastTo(c: v124);
        pullTriggerPhase = this->pullTriggerPhase;
        if ( pullTriggerPhase == TRIGGERPHASE_START_PULL )
        {
          if ( idVehicleMountedTurret::GetTriggerState(this: v125) == TRIGGERSTATE_RELEASED )
          {
            idDeclAnimWeb::GetSubWebIndexForName(
              this: (idDeclAnimWeb *)&v150.trackedMemory,
              result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->animWeb.decl,
              subWebName: "gunner");
            idDeclAnimWeb::GetStateIndexForName(
              this: (idDeclAnimWeb *)&v150.name,
              result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this->animWeb.decl,
              name: "firing");
            idAnimator_AnimWeb::ChangeState(
              this: &this->animWeb,
              subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v150.trackedMemory),
              stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v150.name.str),
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_NO,
              blendEventMask_: 0);
            idAnimator_AnimWeb::SetEvent(
              this: &this->animWeb,
              eventType: ANIMWEB_EVENT_END_BLEND_IN,
              subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v150.trackedMemory),
              stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v150.name.str),
              eventDef: &EV_AnimWeb_Raised,
              priority: PRIORITY_LOW);
            if ( idStr::Cmp(s1: *(const char **)&v150.edgeCache.granularity, s2: "firing") == 0 )
            {
              idTurretGunner::GetTurretSpawnerControlGroup(handleName: "turret_spawner");
              idEntity::StartSoundShader(
                this,
                channel: SND_CHANNEL_ENGINE_IDLE,
                shader: *(const idSoundShader **)(v127 + 844),
                soundShaderFlags: (soundShaderFlags_t)0,
                peerMask: 0xFFu);
              this->pullTriggerPhase = TRIGGERPHASE_WINDING_UP;
              this->pullTriggerPhaseEndTime = TRIGGER_PHASE_TIME[this->pullTriggerPhase]
                                            + idGameTimeManager::GetGameMs(
                                                this: &clientGame->gameTimeManager,
                                                type: GAMETIME_SCALED);
            }
          }
        }
        else if ( pullTriggerPhase == TRIGGERPHASE_WINDING_UP )
        {
          idVehicleMountedTurret::PullTrigger(this: v125);
          this->pullTriggerPhaseEndTime = 0;
          this->pullTriggerPhase = TRIGGERPHASE_FIRING;
        }
        else
        {
          this->pullTriggerPhase = TRIGGERPHASE_IDLE;
          this->pullTriggerPhaseEndTime = 0;
        }
        if ( TRIGGER_PHASE_TIME[this->pullTriggerPhase] != 0 )
          this->pullTriggerPhaseEndTime = TRIGGER_PHASE_TIME[this->pullTriggerPhase]
                                        + idGameTimeManager::GetGameMs(
                                            this: &clientGame->gameTimeManager,
                                            type: GAMETIME_SCALED);
      }
      idStr::FreeData(this: (idStr *)&v150.edgeCache.size);
    }
    v128 = idAnimator_AnimWeb::GetCurStateName(this: &this->animWeb);
    idStr::idStr(this: (idStr *)&v150.settings.subWebBlend, text: v128);
    if ( idStr::Cmp(s1: v151, s2: "firing") == 0 )
      idVehicleMountedTurret::SetTargetPos(
        this: resourceListPtr,
        targetPos: (const idVec3 *)((char *)&v150.idResource + 32));
    v129 = *(float *)&v150.textSource;
    v130 = *(float *)&v150.textLength;
    v150.resourceListPtr = (idResourceList *)&this->gunnerAimPoint;
    this->gunnerAimPoint.x = *((float *)&v150.idResource + 8);
    this->gunnerAimPoint.y = v129;
    this->gunnerAimPoint.z = v130;
    idStr::FreeData(this: (idStr *)&v150.settings.subWebBlend);
  }
  else if ( this->launchInitialMinionTime != 0
         && this->launchInitialMinionTime <= idGameTimeManager::GetGameMs(
                                               this: &clientGame->gameTimeManager,
                                               type: GAMETIME_SCALED)
         && (unsigned __int8)idTurretGunner::LaunchMinionNow(this, launchHookGuy: false) != 0 )
  {
    v33 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->launchInitialMinionTime = GetRandomIntervalBySeconds(minSecs: 8.0, maxSecs: 12.0) + v33;
  }
}


// ========================================================================
// $LN680
// EA  : 0x82D02E80
// RVA : 0x00D02E80
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _LN680()
{
  int v0; // r12

  idAvoidTargetFilter::~idAvoidTargetFilter(this: (idFriendlyDeadTargetFilter *)(v0 - 592 + 168));
}


// ========================================================================
// __unwind$493122
// EA  : 0x82D02EA8
// RVA : 0x00D02EA8
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_493122()
{
  int v0; // r12

  idEnemyTargetSelector::~idEnemyTargetSelector(this: (idNeutralTargetSelector *)(v0 - 592 + 224));
}


// ========================================================================
// __unwind$493123
// EA  : 0x82D02ED0
// RVA : 0x00D02ED0
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_493123()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 592 + 272));
}


// ========================================================================
// __unwind$493124
// EA  : 0x82D02EF8
// RVA : 0x00D02EF8
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_493124()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 592 + 240));
}


// ========================================================================
// __unwind$493125
// EA  : 0x82D02F20
// RVA : 0x00D02F20
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void _unwind_493125()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 592 + 368));
}


// ========================================================================
// ?Think@idTurretGunner@@UAAXXZ
// EA  : 0x82D02F48
// RVA : 0x00D02F48
// PDB : w:\tech5\tungsten\game\entities\turretgunner.cpp
// ========================================================================

void __fastcall idTurretGunner::Think(idTurretGunner *this)
{
  int v2; // r4
  idTurretSpawnerControlGroup *v3; // r3
  double gunnerStartingHitPoints; // fp0
  idTurretSpawnerControlGroup *spawnerControlGroup; // r11
  idGoreComponent *p_goreComponent; // r31

  if ( !this->isGunnerInitialized )
  {
    idTurretGunner::GetTurretSpawnerControlGroup(handleName: "turret_spawner");
    this->spawnerControlGroup = v3;
    gunnerStartingHitPoints = v3->gunnerStartingHitPoints;
    this->maxHealth = v3->gunnerStartingHitPoints;
    if ( gunnerStartingHitPoints < 1.0 )
    {
      idLib::Warning(fmt: "Gunner health is < 1 fix in map!");
      this->maxHealth = 1.0;
    }
    spawnerControlGroup = this->spawnerControlGroup;
    this->health = this->maxHealth;
    idAIWorldState::Init(
      this: &this->worldState,
      visibleSightTime_: spawnerControlGroup->visibleSightTime,
      friendlyVisibilityEffectsMask_: v2,
      enemyVisibilityEffectsMask_: -1,
      a5: -1);
    this->isGunnerInitialized = true;
  }
  if ( this->canFire )
    idTurretGunner::Think_CanFire(this);
  idAnimatedEntity::Think(this);
  p_goreComponent = &this->goreComponent;
  idGoreComponent::UpdateGore(this: p_goreComponent);
  idGoreComponent::CheckForGore(this: p_goreComponent);
}

