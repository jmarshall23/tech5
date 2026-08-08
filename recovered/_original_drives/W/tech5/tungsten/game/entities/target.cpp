
// ========================================================================
// ??0idTarget_ModifyTraversalClass@@QAA@XZ
// EA  : 0x82CCB130
// RVA : 0x00CCB130
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_ModifyTraversalClass *__fastcall idTarget_ModifyTraversalClass::idTarget_ModifyTraversalClass(
        idTarget_ModifyTraversalClass *this)
{
  idEntity::idEntity(this);
  this->action = ACTION_SET_CLASSES;
  this->__vftable = (idTarget_ModifyTraversalClass_vtbl *)&idTarget_ModifyTraversalClass::`vftable';
  this->classA = false;
  this->classB = false;
  this->classC = false;
  this->classD = false;
  this->classE = false;
  this->modifyActiveAI = false;
  return this;
}


// ========================================================================
// ?ModifyAIEditable@idTarget_ModifyTraversalClass@@ABAXAAVidAIEditable@@@Z
// EA  : 0x82CCB190
// RVA : 0x00CCB190
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ModifyTraversalClass::ModifyAIEditable(
        idTarget_ModifyTraversalClass *this,
        idAIEditable *aiEditable)
{
  idTarget_ModifyTraversalClass::modifyTraversalClassAction_t action; // r11
  bool v3; // r11
  bool v4; // r11
  bool v5; // r11
  bool v6; // r11
  bool useTraversalClassE; // r11
  bool useTraversalClassA; // r11
  bool useTraversalClassB; // r11
  bool useTraversalClassC; // r11
  bool useTraversalClassD; // r11

  action = this->action;
  if ( action != ACTION_SET_CLASSES )
  {
    if ( action == ACTION_ADD_CLASSES )
    {
      useTraversalClassA = true;
      if ( !this->classA )
        useTraversalClassA = aiEditable->movement.useTraversalClassA;
      aiEditable->movement.useTraversalClassA = useTraversalClassA;
      useTraversalClassB = true;
      if ( !this->classB )
        useTraversalClassB = aiEditable->movement.useTraversalClassB;
      aiEditable->movement.useTraversalClassB = useTraversalClassB;
      useTraversalClassC = true;
      if ( !this->classC )
        useTraversalClassC = aiEditable->movement.useTraversalClassC;
      aiEditable->movement.useTraversalClassC = useTraversalClassC;
      useTraversalClassD = true;
      if ( !this->classD )
        useTraversalClassD = aiEditable->movement.useTraversalClassD;
      aiEditable->movement.useTraversalClassD = useTraversalClassD;
      useTraversalClassE = true;
      if ( !this->classE )
        useTraversalClassE = aiEditable->movement.useTraversalClassE;
    }
    else
    {
      if ( (unsigned int)action >= (ACTION_REMOVE_CLASSES|ACTION_ADD_CLASSES) )
        return;
      v3 = false;
      if ( !this->classA )
        v3 = aiEditable->movement.useTraversalClassA;
      aiEditable->movement.useTraversalClassA = v3;
      v4 = false;
      if ( !this->classB )
        v4 = aiEditable->movement.useTraversalClassB;
      aiEditable->movement.useTraversalClassB = v4;
      v5 = false;
      if ( !this->classC )
        v5 = aiEditable->movement.useTraversalClassC;
      aiEditable->movement.useTraversalClassC = v5;
      v6 = false;
      if ( !this->classD )
        v6 = aiEditable->movement.useTraversalClassD;
      aiEditable->movement.useTraversalClassD = v6;
      useTraversalClassE = false;
      if ( !this->classE )
      {
        aiEditable->movement.useTraversalClassE = aiEditable->movement.useTraversalClassE;
        return;
      }
    }
    aiEditable->movement.useTraversalClassE = useTraversalClassE;
  }
  else
  {
    aiEditable->movement.useTraversalClassA = this->classA;
    aiEditable->movement.useTraversalClassB = this->classB;
    aiEditable->movement.useTraversalClassC = this->classC;
    aiEditable->movement.useTraversalClassD = this->classD;
    aiEditable->movement.useTraversalClassE = this->classE;
  }
}


// ========================================================================
// ?Enable@idTarget_Timer@@UAAXXZ
// EA  : 0x82CCB2D0
// RVA : 0x00CCB2D0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Timer::Enable(idTarget_Timer *this)
{
  double delay; // fp1

  if ( !this->on )
  {
    delay = this->delay;
    this->on = true;
    idEventReceiver::PostEventSec(this, ev: &EV_TimerEvent, time: delay);
  }
}


// ========================================================================
// ?Disable@idTarget_Timer@@UAAXXZ
// EA  : 0x82CCB2F8
// RVA : 0x00CCB2F8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Timer::Disable(idTarget_Timer *this)
{
  if ( this->on )
  {
    this->on = false;
    idEventReceiver::CancelEvents(this, ev: &EV_TimerEvent);
  }
}


// ========================================================================
// ??0idTarget_JobTimerGiveMoney@@QAA@XZ
// EA  : 0x82CCB320
// RVA : 0x00CCB320
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_JobTimerGiveMoney *__fastcall idTarget_JobTimerGiveMoney::idTarget_JobTimerGiveMoney(
        idTarget_JobTimerGiveMoney *this)
{
  idEntity::idEntity(this);
  this->cashAmount = 1;
  this->__vftable = (idTarget_JobTimerGiveMoney_vtbl *)&idTarget_JobTimerGiveMoney::`vftable';
  return this;
}


// ========================================================================
// ??0idTarget_GiveSpecialEvent@@QAA@XZ
// EA  : 0x82CCB368
// RVA : 0x00CCB368
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_GiveSpecialEvent *__fastcall idTarget_GiveSpecialEvent::idTarget_GiveSpecialEvent(
        idTarget_GiveSpecialEvent *this)
{
  idEntity::idEntity(this);
  this->specialEventDecl = nullptr;
  this->__vftable = (idTarget_GiveSpecialEvent_vtbl *)&idTarget_GiveSpecialEvent::`vftable';
  return this;
}


// ========================================================================
// ??0idTarget_GiveSpecialEvent_Area@@QAA@XZ
// EA  : 0x82CCB3B0
// RVA : 0x00CCB3B0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_GiveSpecialEvent_Area *__fastcall idTarget_GiveSpecialEvent_Area::idTarget_GiveSpecialEvent_Area(
        idTarget_GiveSpecialEvent_Area *this)
{
  idEntity::idEntity(this);
  this->areaDecl = nullptr;
  this->__vftable = (idTarget_GiveSpecialEvent_Area_vtbl *)&idTarget_GiveSpecialEvent_Area::`vftable';
  return this;
}


// ========================================================================
// ??0idTarget_CompleteGame@@QAA@XZ
// EA  : 0x82CCB3F8
// RVA : 0x00CCB3F8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_CompleteGame *__fastcall idTarget_CompleteGame::idTarget_CompleteGame(idTarget_CompleteGame *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_CompleteGame_vtbl *)&idTarget_CompleteGame::`vftable';
  return this;
}


// ========================================================================
// ??0idTarget_PlayerStatModifier@@QAA@XZ
// EA  : 0x82CCB438
// RVA : 0x00CCB438
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_PlayerStatModifier *__fastcall idTarget_PlayerStatModifier::idTarget_PlayerStatModifier(
        idTarget_PlayerStatModifier *this)
{
  idEntity::idEntity(this);
  this->gameStat = RAGE_STAT_INVALID;
  this->__vftable = (idTarget_PlayerStatModifier_vtbl *)&idTarget_PlayerStatModifier::`vftable';
  this->value = 0;
  return this;
}


// ========================================================================
// ??0idTarget_GameStateIntSet@@QAA@XZ
// EA  : 0x82CCB488
// RVA : 0x00CCB488
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_GameStateIntSet *__fastcall idTarget_GameStateIntSet::idTarget_GameStateIntSet(idTarget_GameStateIntSet *this)
{
  idEntity::idEntity(this);
  this->gameStateDecl = nullptr;
  this->__vftable = (idTarget_GameStateIntSet_vtbl *)&idTarget_GameStateIntSet::`vftable';
  this->gameStateValue = 1;
  return this;
}


// ========================================================================
// ??0idTarget_GameStateIntInc@@QAA@XZ
// EA  : 0x82CCB4D8
// RVA : 0x00CCB4D8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_GameStateIntInc *__fastcall idTarget_GameStateIntInc::idTarget_GameStateIntInc(idTarget_GameStateIntInc *this)
{
  idEntity::idEntity(this);
  this->gameStateDecl = nullptr;
  this->__vftable = (idTarget_GameStateIntInc_vtbl *)&idTarget_GameStateIntInc::`vftable';
  return this;
}


// ========================================================================
// ?Spawn@idTarget_LayerStateChange@@QAAXXZ
// EA  : 0x82CCB520
// RVA : 0x00CCB520
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_LayerStateChange::Spawn(idTarget_LayerStateChange *this)
{
  idTarget_PlayerCheckpoint *v2; // r3

  v2 = (idTarget_PlayerCheckpoint *)idGameLocal::SpawnEntityType(
                                      this: gameLocal,
                                      typeInfo: &idTarget_PlayerCheckpoint::Type,
                                      forceEntityNumber: -1,
                                      _model: nullptr);
  this->checkpointEnt = idTarget_PlayerCheckpoint::CastTo(c: v2);
}


// ========================================================================
// ?OnActivate@idTarget_PlayerCheckpoint@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCB570
// RVA : 0x00CCB570
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_PlayerCheckpoint::OnActivate(idTarget_PlayerCheckpoint *this, idPlayer *activator)
{
  idPlayer *v3; // r4
  const idEventArg **v4; // r3
  idEventArg v5; // [sp+50h] [-30h] BYREF

  v3 = idPlayer::CastTo(c: activator);
  if ( gameLocal != nullptr )
  {
    v4 = (const idEventArg **)idEventArg::idEventArg(this: &v5, data: v3);
    idEventReceiver::PostEventSec(this, ev: &EV_DoCheckpoint, time: this->delay, arg1: *v4);
  }
  else
  {
    idLib::Warning(fmt: "[%s] No game local", "idTarget_PlayerCheckpoint::OnActivate");
  }
}


// ========================================================================
// ??0idTarget_SetInEncounterGroup@@QAA@XZ
// EA  : 0x82CCB610
// RVA : 0x00CCB610
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_SetInEncounterGroup *__fastcall idTarget_SetInEncounterGroup::idTarget_SetInEncounterGroup(
        idTarget_SetInEncounterGroup *this)
{
  idEntity::idEntity(this);
  this->startEncounterGroup = true;
  this->__vftable = (idTarget_SetInEncounterGroup_vtbl *)&idTarget_SetInEncounterGroup::`vftable';
  return this;
}


// ========================================================================
// ??0idTarget_PlayerViewEffect@@QAA@XZ
// EA  : 0x82CCB658
// RVA : 0x00CCB658
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_PlayerViewEffect *__fastcall idTarget_PlayerViewEffect::idTarget_PlayerViewEffect(
        idTarget_PlayerViewEffect *this)
{
  idEntity::idEntity(this);
  this->time = 1000;
  this->screenEffect.width = 0.0;
  this->__vftable = (idTarget_PlayerViewEffect_vtbl *)&idTarget_PlayerViewEffect::`vftable';
  this->screenEffect.height = 0.0;
  this->viewEffectType = VIEW_FLASH;
  this->screenEffect.screenX = -1.0;
  this->canUseDefaultPlayer = false;
  this->screenEffect.screenY = -1.0;
  this->screenEffect.material = nullptr;
  this->damageEffect.startBlur = 3.0;
  this->damageEffect.endBlur = 0.0;
  this->damageEffect.startDoubleVision = 0.050000001;
  this->damageEffect.endDoubleVision = 0.0;
  return this;
}


// ========================================================================
// ?Think@idTarget_ShowGui@@UAAXXZ
// EA  : 0x82CCB6F0
// RVA : 0x00CCB6F0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ShowGui::Think(idTarget_ShowGui *this)
{
  if ( this->guiQueued && idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: this->guiActivator) != nullptr )
  {
    this->OnActivate(this, a2: this->guiActivator);
    idEntity::BecomeInactive(this, flags: 1);
    this->guiActivator = nullptr;
    this->guiQueued = false;
  }
}


// ========================================================================
// ?OnActivate@idTarget_TutorialGui@@MAAXPAVidEntity@@@Z
// EA  : 0x82CCB770
// RVA : 0x00CCB770
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_TutorialGui::OnActivate(idTarget_TutorialGui *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r3

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity != nullptr )
    idPlayer::ShowTutorialGui(this: PlayerFromEntity, decl: this->declTutorial, activatingEntity: this);
}


// ========================================================================
// ??0idTarget_PauseAnim@@QAA@XZ
// EA  : 0x82CCB7B8
// RVA : 0x00CCB7B8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_PauseAnim *__fastcall idTarget_PauseAnim::idTarget_PauseAnim(idTarget_PauseAnim *this)
{
  idEntity::idEntity(this);
  this->pauseFrame = -1;
  this->__vftable = (idTarget_PauseAnim_vtbl *)&idTarget_PauseAnim::`vftable';
  this->pause = true;
  this->queuePause = false;
  return this;
}


// ========================================================================
// ?Spawn@idTarget_PlayVideo@@QAAXXZ
// EA  : 0x82CCB810
// RVA : 0x00CCB810
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_PlayVideo::Spawn(idTarget_PlayVideo *this)
{
  if ( this->startOn )
    this->OnActivate(this, a2: nullptr);
}


// ========================================================================
// ?OnActivate@idTarget_PlayVideo@@UAAXPAVidEntity@@@Z
// EA  : 0x82CCB838
// RVA : 0x00CCB838
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_PlayVideo::OnActivate(idTarget_PlayVideo *this, idEntity *activator)
{
  videoManager->BindVideo(this: videoManager, a2: this->screenNumber, a3: this->videoFile);
  videoManager->SetVideoTime(this: videoManager, a2: this->screenNumber, a3: this->timeOffset);
  videoManager->SetLooping(this: videoManager, a2: this->screenNumber, a3: this->looping);
  videoManager->SetPaused(this: videoManager, a2: this->screenNumber, a3: this->paused);
}


// ========================================================================
// ??0idTarget_ForceDormancy@@QAA@XZ
// EA  : 0x82CCB8E0
// RVA : 0x00CCB8E0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_ForceDormancy *__fastcall idTarget_ForceDormancy::idTarget_ForceDormancy(idTarget_ForceDormancy *this)
{
  idEntity::idEntity(this);
  this->dormant = false;
  this->__vftable = (idTarget_ForceDormancy_vtbl *)&idTarget_ForceDormancy::`vftable';
  this->durationMS = 0;
  return this;
}


// ========================================================================
// ??0idTarget_MakeActivatable@@QAA@XZ
// EA  : 0x82CCB928
// RVA : 0x00CCB928
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_MakeActivatable *__fastcall idTarget_MakeActivatable::idTarget_MakeActivatable(idTarget_MakeActivatable *this)
{
  idEntity::idEntity(this);
  this->makeActivatable = true;
  this->__vftable = (idTarget_MakeActivatable_vtbl *)&idTarget_MakeActivatable::`vftable';
  return this;
}


// ========================================================================
// ??0idTarget_EnableBlink@@QAA@XZ
// EA  : 0x82CCB970
// RVA : 0x00CCB970
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_EnableBlink *__fastcall idTarget_EnableBlink::idTarget_EnableBlink(idTarget_EnableBlink *this)
{
  idEntity::idEntity(this);
  this->enableBlink = true;
  this->__vftable = (idTarget_EnableBlink_vtbl *)&idTarget_EnableBlink::`vftable';
  return this;
}


// ========================================================================
// ??0idTarget_Door@@QAA@XZ
// EA  : 0x82CCB9B8
// RVA : 0x00CCB9B8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_Door *__fastcall idTarget_Door::idTarget_Door(idTarget_Door *this)
{
  idEntity::idEntity(this);
  this->playerUsable = KEEP;
  this->__vftable = (idTarget_Door_vtbl *)&idTarget_Door::`vftable';
  this->forceUnusable = KEEP;
  this->open = KEEP;
  this->locked = KEEP;
  return this;
}


// ========================================================================
// ?OnActivate@idTarget_GameChallengeSetState@@UAAXPAVidEntity@@@Z
// EA  : 0x82CCBA08
// RVA : 0x00CCBA08
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_GameChallengeSetState::OnActivate(idTarget_GameChallengeSetState *this, idEntity *activator)
{
  gameLocal->challengeState = this->state;
}


// ========================================================================
// ??0idTarget_EnableAIEvent@@QAA@XZ
// EA  : 0x82CCBA28
// RVA : 0x00CCBA28
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_EnableAIEvent *__fastcall idTarget_EnableAIEvent::idTarget_EnableAIEvent(idTarget_EnableAIEvent *this)
{
  idEntity::idEntity(this);
  this->enableEvent = true;
  this->__vftable = (idTarget_EnableAIEvent_vtbl *)&idTarget_EnableAIEvent::`vftable';
  this->eventClassFlags = AIEVENT_NONE;
  return this;
}


// ========================================================================
// ?Spawn@idTarget_FakeEnemy@@QAAXXZ
// EA  : 0x82CCBA78
// RVA : 0x00CCBA78
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_FakeEnemy::Spawn(idTarget_FakeEnemy *this)
{
  idPhysics *Physics; // r3

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 512, a3: -1);
}


// ========================================================================
// ??0idTarget_ClearFakeEnemy@@QAA@XZ
// EA  : 0x82CCBAB0
// RVA : 0x00CCBAB0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_ClearFakeEnemy *__fastcall idTarget_ClearFakeEnemy::idTarget_ClearFakeEnemy(idTarget_ClearFakeEnemy *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_ClearFakeEnemy_vtbl *)&idTarget_ClearFakeEnemy::`vftable';
  return this;
}


// ========================================================================
// ??0idTarget_PlayVoiceOver@@QAA@XZ
// EA  : 0x82CCBAF0
// RVA : 0x00CCBAF0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_PlayVoiceOver *__fastcall idTarget_PlayVoiceOver::idTarget_PlayVoiceOver(idTarget_PlayVoiceOver *this)
{
  idEntity::idEntity(this);
  this->voiceOver = nullptr;
  this->__vftable = (idTarget_PlayVoiceOver_vtbl *)&idTarget_PlayVoiceOver::`vftable';
  this->playInCombat = true;
  return this;
}


// ========================================================================
// ?OnActivate@idTarget_RestartMapForMissionFailure@@UAAXPAVidEntity@@@Z
// EA  : 0x82CCBB40
// RVA : 0x00CCBB40
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_RestartMapForMissionFailure::OnActivate(
        idTarget_RestartMapForMissionFailure *this,
        idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r3

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity == nullptr )
  {
    idLib::Warning(fmt: "could not get player from activator on , idTarget_RestartMapForMissionFailureusing debug player ");
    PlayerFromEntity = idGameLocal::GetDebugPlayer(this: gameLocal);
  }
  idPlayer::RestartMapForMissionFailure(this: PlayerFromEntity, fadeTime: this->fadeTime);
}


// ========================================================================
// ??0idTarget_PlayerVehicleExit@@QAA@XZ
// EA  : 0x82CCBBA0
// RVA : 0x00CCBBA0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_PlayerVehicleExit *__fastcall idTarget_PlayerVehicleExit::idTarget_PlayerVehicleExit(
        idTarget_PlayerVehicleExit *this)
{
  idEntity::idEntity(this);
  this->removeAllOccupants = false;
  this->__vftable = (idTarget_PlayerVehicleExit_vtbl *)&idTarget_PlayerVehicleExit::`vftable';
  return this;
}


// ========================================================================
// ??0idTarget_PlayerOverrideFocus@@QAA@XZ
// EA  : 0x82CCBBE8
// RVA : 0x00CCBBE8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_PlayerOverrideFocus *__fastcall idTarget_PlayerOverrideFocus::idTarget_PlayerOverrideFocus(
        idTarget_PlayerOverrideFocus *this)
{
  char v2; // r8

  idEntity::idEntity(this);
  v2 = *((_BYTE *)this + 800) & 0x3F | 0x80;
  this->__vftable = (idTarget_PlayerOverrideFocus_vtbl *)&idTarget_PlayerOverrideFocus::`vftable';
  *((_BYTE *)this + 800) = v2;
  return this;
}


// ========================================================================
// ??0idTarget_UnlockSecret@@QAA@XZ
// EA  : 0x82CCBC38
// RVA : 0x00CCBC38
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_UnlockSecret *__fastcall idTarget_UnlockSecret::idTarget_UnlockSecret(idTarget_UnlockSecret *this)
{
  idEntity::idEntity(this);
  this->id = -1;
  this->__vftable = (idTarget_UnlockSecret_vtbl *)&idTarget_UnlockSecret::`vftable';
  return this;
}


// ========================================================================
// ?OnActivate@idTarget_UnlockSecret@@UAAXPAVidEntity@@@Z
// EA  : 0x82CCBC80
// RVA : 0x00CCBC80
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_UnlockSecret::OnActivate(idTarget_UnlockSecret *this, idEntity *activator)
{
  idPlayerProfileGame *v3; // r3
  int id; // r4

  v3 = (idPlayerProfileGame *)((int (__fastcall *)(idCommon *, idEntity *))common->GetProfileFromMasterLocalUser)(
                                a1: common,
                                a2: activator);
  if ( v3 != nullptr )
  {
    id = this->id;
    if ( id >= 0 )
      idPlayerProfileGame::SetSecret(this: v3, secretId: id);
  }
}


// ========================================================================
// ??0idTarget_UnlockMap@@QAA@XZ
// EA  : 0x82CCBCD8
// RVA : 0x00CCBCD8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_UnlockMap *__fastcall idTarget_UnlockMap::idTarget_UnlockMap(idTarget_UnlockMap *this)
{
  idEntity::idEntity(this);
  this->variationId = -1;
  this->__vftable = (idTarget_UnlockMap_vtbl *)&idTarget_UnlockMap::`vftable';
  return this;
}


// ========================================================================
// ?OnActivate@idTarget_UnlockMap@@UAAXPAVidEntity@@@Z
// EA  : 0x82CCBD20
// RVA : 0x00CCBD20
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_UnlockMap::OnActivate(idTarget_UnlockMap *this, idEntity *activator)
{
  idPlayerProfileGame *v3; // r3
  idPlayerProfileGame *v4; // r31
  int variationId; // r4

  v3 = (idPlayerProfileGame *)((int (__fastcall *)(idCommon *, idEntity *))common->GetProfileFromMasterLocalUser)(
                                a1: common,
                                a2: activator);
  v4 = v3;
  if ( v3 != nullptr )
  {
    variationId = this->variationId;
    if ( variationId >= 0 && !idPlayerProfileGame::GetProgress(this: v3, variationId) )
    {
      idPlayerProfileGame::SetProgress(this: v4, variationId: this->variationId);
      idPlayerProfile::SaveSettings(this: v4);
    }
  }
}


// ========================================================================
// ??0idTarget_SetHudElement@@QAA@XZ
// EA  : 0x82CCBDA8
// RVA : 0x00CCBDA8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_SetHudElement *__fastcall idTarget_SetHudElement::idTarget_SetHudElement(idTarget_SetHudElement *this)
{
  idEntity::idEntity(this);
  this->element = ELEMENT_NONE;
  this->__vftable = (idTarget_SetHudElement_vtbl *)&idTarget_SetHudElement::`vftable';
  this->show = true;
  return this;
}


// ========================================================================
// ??0idTarget_SetHelp@@QAA@XZ
// EA  : 0x82CCBDF8
// RVA : 0x00CCBDF8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_SetHelp *__fastcall idTarget_SetHelp::idTarget_SetHelp(idTarget_SetHelp *this)
{
  idEntity::idEntity(this);
  this->show = false;
  this->__vftable = (idTarget_SetHelp_vtbl *)&idTarget_SetHelp::`vftable';
  this->icon = nullptr;
  this->button = HELPBUTTON_NONE;
  return this;
}


// ========================================================================
// ??0idTarget_SetSceneModelFlag@@QAA@XZ
// EA  : 0x82CCBE48
// RVA : 0x00CCBE48
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_SetSceneModelFlag *__fastcall idTarget_SetSceneModelFlag::idTarget_SetSceneModelFlag(
        idTarget_SetSceneModelFlag *this)
{
  char v2; // r9

  idEntity::idEntity(this);
  v2 = *((_BYTE *)this + 800);
  this->__vftable = (idTarget_SetSceneModelFlag_vtbl *)&idTarget_SetSceneModelFlag::`vftable';
  *((_BYTE *)this + 800) = v2 | 0x80;
  return this;
}


// ========================================================================
// ?Spawn@idTarget_Count@@QAAXXZ
// EA  : 0x82CCBF48
// RVA : 0x00CCBF48
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Count::Spawn(idTarget_Count *this)
{
  char *data; // r30
  idScriptObject *v3; // r3

  if ( this->call.len != 0 )
  {
    data = this->call.data;
    v3 = this->GetScriptObject_2(this);
    if ( idScriptObject::GetFunction(this: v3, name: data) == nullptr
      && idProgram::FindFunction(this: &gameLocal->program, name: this->call.data) == nullptr )
    {
      idLib::Warning(
        fmt: "idTarget_Count '%s' has call to function '%s' which does not exist, removing entity",
        this->name.data,
        this->call.data);
      idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
    }
  }
  idEntity::BecomeInactive(this, flags: 1);
}


// ========================================================================
// ?Event_TargetAction@idTarget_Count@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82CCC000
// RVA : 0x00CCC000
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_Count *__fastcall idTarget_Count::Event_TargetAction(
        idTarget_Count *this,
        idEntity *result,
        idEntity *activator)
{
  const char *data; // r28
  int GameMs; // r3
  idScriptFunction v9; // [sp+60h] [-170h] BYREF

  if ( g_debugTriggers.valueInteger >= 2 )
  {
    data = result->name.data;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLib::Printf(fmt: "(%d): '%s' idTarget_relay::Activate\n", GameMs, data);
  }
  result->ActivateTargets(this: result, a2: activator);
  if ( result[1].listeningToList != nullptr )
  {
    idScriptFunction::idScriptFunction(this: &v9);
    idScriptFunction::SetFunction(
      this: &v9,
      ent: result,
      functionName: (const char *)result[1].name.len,
      returnType: ev_void,
      numParms: 2,
      8,
      "activatedEntity",
      8);
    idScriptFunction::SetArg_Entity(this: &v9, argNum: 0, ent: result);
    idScriptFunction::SetArg_Entity(this: &v9, argNum: 1, ent: activator);
    idScriptFunction::CallFunction(this: &v9, defer: true);
  }
  if ( result[1].__vftable == (idEntity_vtbl *)-1 )
    idEventReceiver::PostEventMS(this: result, ev: &EV_Remove, time: 0);
  return this;
}


// ========================================================================
// ?Spawn@idTarget_Count_Random@@QAAXXZ
// EA  : 0x82CCC118
// RVA : 0x00CCC118
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Count_Random::Spawn(idTarget_Count_Random *this)
{
  char *data; // r30
  idScriptObject *v3; // r3

  if ( this->call.len != 0 )
  {
    data = this->call.data;
    v3 = this->GetScriptObject_2(this);
    if ( idScriptObject::GetFunction(this: v3, name: data) == nullptr
      && idProgram::FindFunction(this: &gameLocal->program, name: this->call.data) == nullptr )
    {
      idLib::Warning(
        fmt: "idTarget_Count_Random '%s' has call to function '%s' which does not exist, removing entity",
        this->name.data,
        this->call.data);
      idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
    }
  }
  idEntity::BecomeInactive(this, flags: 1);
}


// ========================================================================
// ?Event_TargetAction@idTarget_Count_Random@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82CCC1D0
// RVA : 0x00CCC1D0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_Count_Random *__fastcall idTarget_Count_Random::Event_TargetAction(
        idTarget_Count_Random *this,
        idEntity *result,
        idEntity *activator)
{
  idScriptFunction v7; // [sp+60h] [-170h] BYREF

  result->ActivateTargets(this: result, a2: activator);
  if ( result[1].listeningToList != nullptr )
  {
    idScriptFunction::idScriptFunction(this: &v7);
    idScriptFunction::SetFunction(
      this: &v7,
      ent: result,
      functionName: (const char *)result[1].name.len,
      returnType: ev_void,
      numParms: 2,
      8,
      "activatedEntity",
      8);
    idScriptFunction::SetArg_Entity(this: &v7, argNum: 0, ent: result);
    idScriptFunction::SetArg_Entity(this: &v7, argNum: 1, ent: activator);
    idScriptFunction::CallFunction(this: &v7, defer: true);
  }
  if ( result[1].__vftable == (idEntity_vtbl *)-1 )
    idEventReceiver::PostEventMS(this: result, ev: &EV_Remove, time: 0);
  return this;
}


// ========================================================================
// ??0idTarget_SetGroupCombatStage@@QAA@XZ
// EA  : 0x82CCC2A0
// RVA : 0x00CCC2A0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_SetGroupCombatStage *__fastcall idTarget_SetGroupCombatStage::idTarget_SetGroupCombatStage(
        idTarget_SetGroupCombatStage *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_SetGroupCombatStage_vtbl *)&idTarget_SetGroupCombatStage::`vftable';
  this->groupName.data = this->groupName.baseBuffer;
  this->groupName.len = 0;
  this->groupName.allocedAndFlag = 20;
  this->groupName.baseBuffer[0] = 0;
  this->combatStage.allocedAndFlag = 20;
  this->combatStage.data = this->combatStage.baseBuffer;
  this->combatStage.len = 0;
  this->combatStage.baseBuffer[0] = 0;
  this->delay = 2048;
  return this;
}


// ========================================================================
// ?OnActivate@idTarget_SetGroupCombatStage@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCC3D0
// RVA : 0x00CCC3D0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_SetGroupCombatStage::OnActivate(idTarget_SetGroupCombatStage *this, idEntity *activator)
{
  idEncounterGroupManager *p_encounterGroupManager; // r30
  idEncounterGroupManager *Group; // r3
  idEncounterGroup *v5; // r3
  char v6; // [sp+50h] [-20h] BYREF

  p_encounterGroupManager = &gameLocal->encounterGroupManager;
  Group = idEncounterGroupManager::FindGroup(
            this: (idEncounterGroupManager *)&v6,
            result: p_encounterGroupManager,
            groupName: this->groupName.data);
  v5 = idEncounterGroupManager::GroupForHandle(
         this: p_encounterGroupManager,
         handle: (const idHandle<short,enum invalidEncounterGroup_t,-1> *)Group);
  if ( v5 != nullptr )
  {
    if ( (unsigned __int8)idEncounterGroup::SetPendingCombatStageByName(
                            this: v5,
                            name: &this->combatStage,
                            delay: this->delay) == 0 )
      idLib::Warning(
        fmt: "idTarget_SetGroupCombatStage: %s cannot find combat stage %s in group %s",
        this->name.data,
        this->combatStage.data,
        this->groupName.data);
  }
  else
  {
    idLib::Warning(
      fmt: "idTarget_SetGroupCombatStage: %s cannot find group name %s",
      this->name.data,
      this->groupName.data);
  }
}


// ========================================================================
// ?Spawn@idTarget_Timer@@QAAXXZ
// EA  : 0x82CCC480
// RVA : 0x00CCC480
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Timer::Spawn(idTarget_Timer *this)
{
  double wait; // fp0
  idPhysics *Physics; // r3
  char *data; // r30
  idAngles *v5; // r3
  const char *v6; // r3

  wait = this->wait;
  if ( this->random >= wait && wait >= 0.0 )
  {
    this->random = this->wait - (float)0.001;
    Physics = idEntity::GetPhysics(this);
    data = this->name.data;
    v5 = (idAngles *)Physics->GetOrigin(this: Physics, a2: 0);
    v6 = idVec3::ToString(this: v5, precision: 0);
    idLib::Warning(fmt: "idTarget_Timer '%s' at (%s) has random >= wait", data, v6);
  }
  if ( this->on )
    idEventReceiver::PostEventSec(this, ev: &EV_TimerEvent, time: this->delay);
}


// ========================================================================
// ?OnActivate@idTarget_JobTimerStart@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCC538
// RVA : 0x00CCC538
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_JobTimerStart::OnActivate(idTarget_JobTimerStart *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r3
  bool actuallyTime; // r9
  int parPrize; // r8
  int cashPerScore; // r6
  double v7; // fp12
  int v8; // [sp+8h] [-88h]
  idStrId v9[6]; // [sp+60h] [-30h] BYREF

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity != nullptr || (PlayerFromEntity = idGameLocal::GetDebugPlayer(this: gameLocal)) != nullptr )
  {
    actuallyTime = this->actuallyTime;
    parPrize = this->parPrize;
    cashPerScore = this->cashPerScore;
    v7 = (float)(this->parTime * (float)60000.0);
    v9[0] = this->phaseName;
    v9[3].index = (int)v7;
    idJobTimerManager::StartTimer(
      this: &PlayerFromEntity->jobTimerManager,
      player: PlayerFromEntity,
      name: v9,
      cashPerScore,
      parTime: (int)v7,
      parPrize,
      actuallyTime,
      continueTarget: &this->continueTarget,
      numPhases: v8);
  }
  else
  {
    idLib::Warning(fmt: "Could not find player at all for idTarget_JobTimerStart");
  }
}


// ========================================================================
// ?OnActivate@idTarget_JobTimerStop@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCC5E8
// RVA : 0x00CCC5E8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_JobTimerStop::OnActivate(idTarget_JobTimerStop *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r3

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity != nullptr || (PlayerFromEntity = idGameLocal::GetDebugPlayer(this: gameLocal)) != nullptr )
    idJobTimerManager::StopTimer(this: &PlayerFromEntity->jobTimerManager, player: PlayerFromEntity);
  else
    idLib::Warning(fmt: "Could not find player at all for idTarget_JobTimerStop");
}


// ========================================================================
// ?OnActivate@idTarget_JobTimerIncrementScore@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCC660
// RVA : 0x00CCC660
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_JobTimerIncrementScore::OnActivate(idTarget_JobTimerIncrementScore *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r3

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity != nullptr )
    idJobTimerManager::IncrementScore(this: &PlayerFromEntity->jobTimerManager);
}


// ========================================================================
// ?OnActivate@idTarget_JobTimerGiveMoney@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCC698
// RVA : 0x00CCC698
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_JobTimerGiveMoney::OnActivate(idTarget_JobTimerGiveMoney *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r3

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity != nullptr || (PlayerFromEntity = idGameLocal::GetDebugPlayer(this: gameLocal)) != nullptr )
    idJobTimerManager::GiveMoney(
      this: &PlayerFromEntity->jobTimerManager,
      cash: this->cashAmount,
      player: PlayerFromEntity);
  else
    idLib::Warning(fmt: "Could not find player at all for idTarget_JobTimerGiveMoney");
}


// ========================================================================
// ?OnActivate@idTarget_GiveSpecialEvent@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCC710
// RVA : 0x00CCC710
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_GiveSpecialEvent::OnActivate(idTarget_GiveSpecialEvent *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r3

  if ( this->specialEventDecl != nullptr )
  {
    PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
    if ( PlayerFromEntity != nullptr || (PlayerFromEntity = idGameLocal::GetDebugPlayer(this: gameLocal)) != nullptr )
      idJobManager::GiveSpecialEvent(
        this: &PlayerFromEntity->jobManager,
        specialEventDecl: this->specialEventDecl,
        fromEntity: activator);
    else
      idLib::Warning(fmt: "Could not find player at all for idTarget_GiveSpecialEvent");
  }
  else
  {
    idLib::Warning(fmt: "NULL special event decl on idTarget_GiveSpecialEvent");
  }
}


// ========================================================================
// ?OnActivate@idTarget_GiveSpecialEvent_Area@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCC798
// RVA : 0x00CCC798
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_GiveSpecialEvent_Area::OnActivate(idTarget_GiveSpecialEvent_Area *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r3

  if ( this->areaDecl != nullptr )
  {
    PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
    if ( PlayerFromEntity != nullptr || (PlayerFromEntity = idGameLocal::GetDebugPlayer(this: gameLocal)) != nullptr )
      idJobManager::GiveSpecialEventArea(this: &PlayerFromEntity->jobManager, specialEventArea: this->areaDecl);
    else
      idLib::Warning(fmt: "Could not find player at all for idTarget_GiveSpecialEvent_Area");
  }
  else
  {
    idLib::Warning(fmt: "NULL special event decl on idTarget_GiveSpecialEvent_Area");
  }
}


// ========================================================================
// ?OnActivate@idTarget_CompleteGame@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCC820
// RVA : 0x00CCC820
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_CompleteGame::OnActivate(idTarget_CompleteGame *this, idEntity *activator)
{
  const idPlayer *PlayerFromEntity; // r31
  idRageMetrics *rageMetrics; // r30
  int LowestGameDifficulty; // r3

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity != nullptr )
  {
    rageMetrics = clientGame->rageMetrics;
    LowestGameDifficulty = idGameLocal::GetLowestGameDifficulty(this: gameLocal);
    idRageMetrics::CompleteGame(this: rageMetrics, player: PlayerFromEntity, difficulty: LowestGameDifficulty);
  }
  else
  {
    idLib::Warning(fmt: "Can only be activated from player.");
  }
}


// ========================================================================
// ?OnActivate@idTarget_PlayerStatModifier@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCC8A0
// RVA : 0x00CCC8A0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_PlayerStatModifier::OnActivate(idTarget_PlayerStatModifier *this, idEntity *activator)
{
  const idPlayer *PlayerFromEntity; // r4

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity != nullptr )
    idRageMetrics::StatAddInt(
      this: clientGame->rageMetrics,
      player: PlayerFromEntity,
      stat: (const rageStat_t)this->gameStat,
      value: this->value);
  else
    idLib::Warning(fmt: "Can only be activated from player.");
}


// ========================================================================
// ?OnActivate@idTarget_GameStateIntSet@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCC920
// RVA : 0x00CCC920
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_GameStateIntSet::OnActivate(idTarget_GameStateIntSet *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r3
  const idDeclGameStateInt *gameStateDecl; // r4

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity != nullptr || (PlayerFromEntity = idGameLocal::GetDebugPlayer(this: gameLocal)) != nullptr )
  {
    gameStateDecl = this->gameStateDecl;
    if ( gameStateDecl != nullptr )
      idJobManager::SetGameStateIntValue(
        this: &PlayerFromEntity->jobManager,
        gameState: gameStateDecl,
        stateValue: this->gameStateValue);
    else
      idLib::Warning(fmt: "NULL gameStateDecl for idTarget_GameStateIntSet");
  }
  else
  {
    idLib::Warning(fmt: "Could not find player at all for idTarget_GameStateIntSet");
  }
}


// ========================================================================
// ?OnActivate@idTarget_GameStateIntInc@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCC9B0
// RVA : 0x00CCC9B0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_GameStateIntInc::OnActivate(idTarget_GameStateIntInc *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r3
  const idDeclGameStateInt *gameStateDecl; // r4
  idJobManager *p_jobManager; // r31
  int GameStateIntValue; // r3

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity != nullptr || (PlayerFromEntity = idGameLocal::GetDebugPlayer(this: gameLocal)) != nullptr )
  {
    gameStateDecl = this->gameStateDecl;
    if ( gameStateDecl != nullptr )
    {
      p_jobManager = &PlayerFromEntity->jobManager;
      GameStateIntValue = idJobManager::GetGameStateIntValue(
                            this: &PlayerFromEntity->jobManager,
                            gameState: gameStateDecl);
      idJobManager::SetGameStateIntValue(
        this: p_jobManager,
        gameState: this->gameStateDecl,
        stateValue: GameStateIntValue + 1);
    }
    else
    {
      idLib::Warning(fmt: "NULL gameStateDecl for idTarget_GameStateIntInc");
    }
  }
  else
  {
    idLib::Warning(fmt: "Could not find player at all for idTarget_GameStateIntInc");
  }
}


// ========================================================================
// ?OnActivate@idTarget_LayerChange2@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCCA50
// RVA : 0x00CCCA50
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_LayerChange2::OnActivate(idTarget_LayerChange2 *this, idPlayer *activator)
{
  idPlayer *DebugPlayer; // r30
  char *data; // r31
  int v5; // r3
  int v6; // r28
  int v7; // r31
  idTarget_LayerChange2::layerChange_t2 *v8; // r10
  const idDeclLayer *layerDecl; // r11
  idTarget_LayerChange2::targetLayerChange_t2 action; // r10

  DebugPlayer = idPlayer::CastTo(c: activator);
  if ( DebugPlayer == nullptr )
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( g_debugLayers.valueInteger != 0 )
  {
    data = this->name.data;
    v5 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idLib::Printf(fmt: "%d: '%s' changing layers:\n", v5, data);
  }
  v6 = 0;
  if ( this->layerChanges.num > 0 )
  {
    v7 = 0;
    do
    {
      v8 = &this->layerChanges.list[v7];
      layerDecl = v8->layerDecl;
      if ( v8->layerDecl != nullptr )
      {
        action = v8->action;
        if ( action != TLC_ACTIVATE )
        {
          switch ( action )
          {
            case TLC_ACTIVATE_FROM_DEACTIVE:
              idGameLayerManager::ActivateDeactiveLayer(
                this: &DebugPlayer->gameLayerManager,
                layerName: layerDecl->name.str);
              break;
            case TLC_DEACTIVATE_IN_MAP:
              idGameLayerManager::DeactivateActiveLayer(
                this: &DebugPlayer->gameLayerManager,
                layerName: layerDecl->name.str);
              break;
            case TLC_ADD_DEACTIVE_TO_PLAYER:
              idGameLayerManager::AddDeactiveLayer(this: &DebugPlayer->gameLayerManager, layerName: layerDecl->name.str);
              break;
            case TLC_REMOVE_FROM_PLAYER:
              idGameLayerManager::RemoveActiveLayer(
                this: &DebugPlayer->gameLayerManager,
                layerName: layerDecl->name.str);
              break;
            case TLC_REMOVE_FROM_GAME:
              idGameLayerManager::RemoveActiveLayerFromMap(
                this: &DebugPlayer->gameLayerManager,
                layerName: layerDecl->name.str);
              break;
            case TLC_REMOVE_MARK_ACTIVE_NEXT_MAP_LOAD:
              idGameLayerManager::RemoveLayerMarkActiveNextMapLoad(
                this: &DebugPlayer->gameLayerManager,
                layerName: layerDecl->name.str);
              break;
            case TLC_REMOVE_MARK_DEACTIVE_NEXT_MAP_LOAD:
              idGameLayerManager::RemoveLayerMarkDeactiveNextMapLoad(
                this: &DebugPlayer->gameLayerManager,
                layerName: layerDecl->name.str);
              break;
            default:
              break;
          }
        }
        else
        {
          idGameLayerManager::AddActiveLayer(this: &DebugPlayer->gameLayerManager, layerName: layerDecl->name.str);
        }
      }
      ++v6;
      ++v7;
    }
    while ( v6 < this->layerChanges.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_LayerChange@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCCBD0
// RVA : 0x00CCCBD0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_LayerChange::OnActivate(idTarget_LayerChange *this, idPlayer *activator)
{
  idPlayer *DebugPlayer; // r28
  char *data; // r31
  int v5; // r3
  int v6; // r29
  int v7; // r31
  idTarget_LayerChange::layerChange_t *v8; // r11
  const idDeclLayer *layerDecl; // r10
  idTarget_LayerChange::targetLayerChange_t action; // r11

  DebugPlayer = idPlayer::CastTo(c: activator);
  if ( DebugPlayer == nullptr )
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( g_debugLayers.valueInteger != 0 )
  {
    data = this->name.data;
    v5 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idLib::Printf(fmt: "%d: '%s' changing layers:\n", v5, data);
  }
  v6 = 0;
  if ( this->layerChanges.num > 0 )
  {
    v7 = 0;
    do
    {
      v8 = &this->layerChanges.list[v7];
      layerDecl = v8->layerDecl;
      if ( v8->layerDecl != nullptr )
      {
        action = v8->action;
        if ( action == TARGETLAYERCHANGE_ACTIVATE )
        {
          idGameLayerManager::AddActiveLayer(this: &DebugPlayer->gameLayerManager, layerName: layerDecl->name.str);
        }
        else if ( action == TARGETLAYERCHANGE_DEACTIVATE )
        {
          idGameLayerManager::RemoveActiveLayer(this: &DebugPlayer->gameLayerManager, layerName: layerDecl->name.str);
        }
      }
      ++v6;
      ++v7;
    }
    while ( v6 < this->layerChanges.num );
  }
}


// ========================================================================
// ??0idTarget_LevelTransition@@QAA@XZ
// EA  : 0x82CCCCC8
// RVA : 0x00CCCCC8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_LevelTransition *__fastcall idTarget_LevelTransition::idTarget_LevelTransition(idTarget_LevelTransition *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_LevelTransition_vtbl *)&idTarget_LevelTransition::`vftable';
  this->mapName.len = 0;
  this->mapName.allocedAndFlag = 20;
  this->mapName.data = this->mapName.baseBuffer;
  this->mapName.baseBuffer[0] = 0;
  this->spawnSpot.allocedAndFlag = 20;
  this->spawnSpot.len = 0;
  this->spawnSpot.data = this->spawnSpot.baseBuffer;
  this->spawnSpot.baseBuffer[0] = 0;
  this->spawnSpotInExistingMap.allocedAndFlag = 20;
  this->spawnSpotInExistingMap.len = 0;
  this->spawnSpotInExistingMap.data = this->spawnSpotInExistingMap.baseBuffer;
  this->spawnSpotInExistingMap.baseBuffer[0] = 0;
  this->layerOverride.allocedAndFlag = 20;
  this->layerOverride.len = 0;
  this->layerOverride.data = this->layerOverride.baseBuffer;
  this->layerOverride.baseBuffer[0] = 0;
  this->layerDeactiveOverride.allocedAndFlag = 20;
  this->layerDeactiveOverride.len = 0;
  this->layerDeactiveOverride.data = this->layerDeactiveOverride.baseBuffer;
  this->layerDeactiveOverride.baseBuffer[0] = 0;
  idStr::operator=(this: &this->spawnSpot, text: "player_start");
  this->triggered = false;
  this->garage = GARAGE_MAX;
  this->freeInventory = false;
  return this;
}


// ========================================================================
// __unwind$500195
// EA  : 0x82CCCD9C
// RVA : 0x00CCCD9C
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_500195()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$500196
// EA  : 0x82CCCDC4
// RVA : 0x00CCCDC4
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_500196()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 800));
}


// ========================================================================
// __unwind$500197
// EA  : 0x82CCCDF0
// RVA : 0x00CCCDF0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_500197()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 832));
}


// ========================================================================
// __unwind$500198
// EA  : 0x82CCCE1C
// RVA : 0x00CCCE1C
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_500198()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 864));
}


// ========================================================================
// __unwind$500199
// EA  : 0x82CCCE48
// RVA : 0x00CCCE48
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_500199()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 900));
}


// ========================================================================
// __unwind$500200
// EA  : 0x82CCCE74
// RVA : 0x00CCCE74
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_500200()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 932));
}


// ========================================================================
// ?Event_Activate@idTarget_SetSpawnSpot@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82CCCFE8
// RVA : 0x00CCCFE8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_SetSpawnSpot *__fastcall idTarget_SetSpawnSpot::Event_Activate(
        idTarget_SetSpawnSpot *this,
        eventVoid *result,
        idEntity *activator)
{
  (*(void (__fastcall **)(eventVoid *, idEntity *))(*(_DWORD *)result + 616))(a1: result, a2: activator);
  return this;
}


// ========================================================================
// ?OnActivate@idTarget_SetInEncounterGroup@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCD030
// RVA : 0x00CCD030
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_SetInEncounterGroup::OnActivate(idTarget_SetInEncounterGroup *this, idEntity *activator)
{
  gameLocal->inEncounterGroup = this->startEncounterGroup;
  this->ActivateTargets(this, a2: activator);
}


// ========================================================================
// ?ActivateOnPlayer@idTarget_PlayerViewEffect@@AAAXPAVidPlayer@@@Z
// EA  : 0x82CCD058
// RVA : 0x00CCD058
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_PlayerViewEffect::ActivateOnPlayer(
        idTarget_PlayerViewEffect *this,
        idPlayer *player,
        int a3,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  idTarget_PlayerViewEffect::viewEffectType_t viewEffectType; // r11
  idPresentable *v10; // r3
  int v11; // r3
  __int64 v12; // r10
  idPresentable *v13; // r3
  int v14; // r3
  void (__fastcall *GetColor_2)(struct idTarget_PlayerViewEffect *, idColor *); // r9
  idPresentable *presentable; // r3
  int v17; // r3
  idPresentable *v18; // r3
  int v19; // r3
  idVec4 v20; // [sp+60h] [-30h] BYREF

  viewEffectType = this->viewEffectType;
  if ( viewEffectType != VIEW_FLASH )
  {
    if ( viewEffectType == VIEW_FADE )
    {
      GetColor_2 = this->GetColor_2;
      v20.w = -1.0;
      v20.z = -1.0;
      v20.y = -1.0;
      v20.x = -1.0;
      GetColor_2(this, a2: (idColor *)&v20);
      presentable = player->presentable;
      if ( presentable != nullptr )
      {
        v17 = (int)presentable->GetPlayerInterface_2(this: presentable);
        idView::Fade(this: (idView *)(v17 + 16224), color: &v20, time: this->time);
      }
      else
      {
        idView::Fade(this: (idView *)0x3F60, color: &v20, time: this->time);
      }
    }
    else if ( viewEffectType == VIEW_DAMAGE )
    {
      v10 = player->presentable;
      if ( v10 != nullptr )
        v11 = (int)v10->GetPlayerInterface_2(this: v10);
      else
        v11 = 0;
      LODWORD(a7) = this->time;
      idView::ForceDoubleVisionValues(
        this: (idView *)(v11 + 16224),
        dblDuration: (float)a7,
        dblStart: this->damageEffect.startDoubleVision,
        dblEnd: this->damageEffect.endDoubleVision);
      v13 = player->presentable;
      if ( v13 != nullptr )
        v14 = (int)v13->GetPlayerInterface_2(this: v13);
      else
        v14 = 0;
      LODWORD(v12) = this->time;
      idView::ForceBlurValues(
        this: (idView *)(v14 + 16224),
        blurBegin: this->damageEffect.startBlur,
        blurEnd: this->damageEffect.endBlur,
        blurTime: (float)v12);
    }
  }
  else
  {
    v18 = player->presentable;
    if ( v18 != nullptr )
      v19 = (int)v18->GetPlayerInterface_2(this: v18);
    else
      v19 = 0;
    idView::Flash(this: (idView *)(v19 + 16224), color: (const idVec4 *)&idColor::colorWhite, time: this->time);
  }
}


// ========================================================================
// ?OnActivate@idTarget_PlayerWhiplash@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCD1F8
// RVA : 0x00CCD1F8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_PlayerWhiplash::OnActivate(idTarget_PlayerWhiplash *this, idEntity *activator)
{
  int i; // r25
  idPlayer *Player; // r3
  idEntity *v5; // r31
  idPresentable *presentable; // r3
  idPhysics *Physics; // r3
  float *v8; // r22
  idPhysics *v9; // r3
  float *v10; // r3
  double v11; // fp8
  double v12; // fp4
  double radius; // fp10
  double v16; // fp9
  double v17; // fp11
  double v18; // fp9
  double v19; // fp27
  double v20; // fp2
  idPresentable *v21; // r3
  int v22; // r3
  idView *v23; // r31
  double v24; // fp9
  double v25; // fp7
  double v27; // fp31
  double v29; // fp0
  double v30; // fp30
  double v31; // fp29
  double v32; // fp0
  double v33; // fp1
  double v34; // fp0
  double magnitude; // fp13
  idAngles v36; // [sp+60h] [-140h] BYREF
  idVec3 v37; // [sp+70h] [-130h] BYREF
  idVec3 v38; // [sp+80h] [-120h] BYREF
  idMat3 v39[5]; // [sp+90h] [-110h] BYREF

  for ( i = 0; i < 6; ++i )
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i);
    v5 = Player;
    if ( Player != nullptr )
    {
      presentable = Player->presentable;
      if ( presentable != nullptr && presentable->GetPlayerInterface_2(this: presentable) != nullptr )
      {
        Physics = idEntity::GetPhysics(this: v5);
        v8 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v9 = idEntity::GetPhysics(this);
        v10 = (float *)v9->GetOrigin(this: v9, a2: 0);
        v11 = (float)(v10[1] - v8[1]);
        v12 = (float)(v10[2] - v8[2]);
        radius = this->radius;
        _FP13 = (float)((float)((float)((float)v12 * (float)v12)
                              + (float)((float)((float)(*v10 - *v8) * (float)(*v10 - *v8))
                                      + (float)((float)v11 * (float)v11)))
                      - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f11, f13, f1, f0 }
        v16 = __frsqrte(_FP11);
        v17 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16
                                                                                            * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)(*v10 - *v8) * (float)(*v10 - *v8)) + (float)((float)v11 * (float)v11))) * (float)0.5))
                                                                                    * (float)v16)
                                                                            - (float)1.5)
                                                            * (float)v16)
                                                    * (float)((float)((float)((float)v12 * (float)v12)
                                                                    + (float)((float)((float)(*v10 - *v8)
                                                                                    * (float)(*v10 - *v8))
                                                                            + (float)((float)v11 * (float)v11)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v16
                                                                                    * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)(*v10 - *v8) * (float)(*v10 - *v8)) + (float)((float)v11 * (float)v11)))
                                                                                            * (float)0.5))
                                                                            * (float)v16)
                                                                    - (float)1.5)
                                                    * (float)v16))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v16
                                                            * (float)((float)((float)((float)v12 * (float)v12)
                                                                            + (float)((float)((float)(*v10 - *v8)
                                                                                            * (float)(*v10 - *v8))
                                                                                    + (float)((float)v11 * (float)v11)))
                                                                    * (float)0.5))
                                                    * (float)v16)
                                            - (float)1.5)
                            * (float)v16));
        v18 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)(*v10 - *v8) * (float)(*v10 - *v8)) + (float)((float)v11 * (float)v11))) * (float)0.5))
                                                                                            * (float)v16)
                                                                                    - (float)1.5)
                                                                    * (float)v16)
                                                            * (float)((float)((float)((float)v12 * (float)v12)
                                                                            + (float)((float)((float)(*v10 - *v8)
                                                                                            * (float)(*v10 - *v8))
                                                                                    + (float)((float)v11 * (float)v11)))
                                                                    * (float)0.5))
                                                    * (float)((float)-(float)((float)((float)((float)v16
                                                                                            * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)(*v10 - *v8) * (float)(*v10 - *v8)) + (float)((float)v11 * (float)v11))) * (float)0.5))
                                                                                    * (float)v16)
                                                                            - (float)1.5)
                                                            * (float)v16))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v16
                                                                    * (float)((float)((float)((float)v12 * (float)v12)
                                                                                    + (float)((float)((float)(*v10 - *v8) * (float)(*v10 - *v8))
                                                                                            + (float)((float)v11 * (float)v11)))
                                                                            * (float)0.5))
                                                            * (float)v16)
                                                    - (float)1.5)
                                    * (float)v16))
                    * (float)((float)((float)((float)v12 * (float)v12)
                                    + (float)((float)((float)(*v10 - *v8) * (float)(*v10 - *v8))
                                            + (float)((float)v11 * (float)v11)))
                            * (float)0.5));
        v19 = (float)((float)((float)-(float)((float)((float)v18 * (float)v17) - (float)1.5) * (float)v17)
                    * (float)((float)((float)v12 * (float)v12)
                            + (float)((float)((float)(*v10 - *v8) * (float)(*v10 - *v8))
                                    + (float)((float)v11 * (float)v11))));
        v20 = (float)((float)(v10[1] - v8[1])
                    * (float)((float)-(float)((float)((float)v18 * (float)v17) - (float)1.5) * (float)v17));
        v36.pitch = (float)(*v10 - *v8)
                  * (float)((float)-(float)((float)((float)v18 * (float)v17) - (float)1.5) * (float)v17);
        v36.yaw = v20;
        v36.roll = (float)v12 * (float)((float)-(float)((float)((float)v18 * (float)v17) - (float)1.5) * (float)v17);
        if ( v19 < radius )
        {
          if ( v19 < 0.001 )
          {
            v36.pitch = 1.0;
            v36.yaw = 0.0;
            v36.roll = 0.0;
          }
          v21 = v5->presentable;
          if ( v21 != nullptr )
            v22 = (int)v21->GetPlayerInterface_2(this: v21);
          else
            v22 = 0;
          v23 = (idView *)(v22 + 16224);
          idView::GetViewPos(this: (idView *)(v22 + 16224), origin: &v38, axis: v39);
          idMat3::InverseSelf(this: v39);
          v24 = (float)((float)(v39[0].mat[2].z * v36.roll) + (float)(v39[0].mat[0].z * v36.pitch));
          v25 = (float)((float)(v39[0].mat[1].y * v36.yaw)
                      + (float)((float)(v39[0].mat[2].y * v36.roll) + (float)(v39[0].mat[0].y * v36.pitch)));
          v36.pitch = (float)(v39[0].mat[1].x * v36.yaw)
                    + (float)((float)(v39[0].mat[2].x * v36.roll) + (float)(v39[0].mat[0].x * v36.pitch));
          v36.roll = (float)(v39[0].mat[1].z * v36.yaw) + (float)v24;
          v36.yaw = v25;
          idVec3::ToAngles(this: &v37, result: &v36);
          _FP0 = v37.y;
          if ( v37.y > 180.0 )
            _FP0 = (float)(v37.y - (float)360.0);
          v27 = 1.0;
          __asm { fsel      f28, f0, f31, f13 }
          v29 = (float)((float)_FP28 * (float)_FP0);
          if ( v29 >= 90.0 )
            v30 = (float)((float)180.0 - (float)v29);
          else
            v30 = v29;
          if ( v30 > 15.0 )
          {
            if ( v30 < (float)60.0 )
              v31 = (float)-(float)((float)((float)((float)v30 - (float)15.0) * (float)0.088888891) - 5.0);
            else
              v31 = 1.0;
          }
          else
          {
            v31 = 5.0;
          }
          if ( v29 > 70.0 )
          {
            if ( v29 < (float)110.0 )
              v27 = (float)-(float)((float)((float)((float)v29 - (float)70.0) * (float)0.037500001) - 1.0);
            else
              v27 = (float)-0.5;
          }
          v37.x = (float)(RandomFloat(min: 3.0, max: 8.0) * (float)v27) * (float)v31;
          if ( v30 > 10.0 )
          {
            v32 = 40.0;
            if ( v30 < 40.0 )
              v32 = (float)((float)((float)v30 - (float)10.0) + (float)10.0);
          }
          else
          {
            v32 = 10.0;
          }
          v37.y = (float)v32 * (float)_FP28;
          v33 = RandomFloat(min: -10.0, max: 10.0);
          v34 = (float)((float)v19 / this->radius);
          magnitude = this->magnitude;
          if ( v34 > 0.66600001 )
          {
            if ( v34 < 1.0 )
              magnitude = (float)((float)((float)((float)((float)((float)v19 / this->radius) - (float)0.66600001)
                                                * (float)-this->magnitude)
                                        * (float)2.9940121)
                                + this->magnitude);
            else
              magnitude = 0.0;
          }
          v37.z = (float)((float)magnitude * -1.0) * (float)v33;
          v37.x = (float)((float)magnitude * -1.0) * v37.x;
          v37.y = (float)((float)magnitude * -1.0) * v37.y;
          idView::AddCustomWhiplash(
            this: v23,
            angles: (const idAngles *)&v37,
            updateFrac: 1.0,
            velocityFrac: 0.0099999998,
            frictionFrac: 0.89999998,
            minVelocityLen: 0.000099999997);
        }
      }
    }
  }
}


// ========================================================================
// ?OnActivate@idTarget_Cvar@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCD600
// RVA : 0x00CCD600
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Cvar::OnActivate(idTarget_Cvar *this, idEntity *activator)
{
  int v3; // r29
  int v4; // r31
  idTarget_Cvar::keyVal_t *v5; // r11
  char *data; // r5

  v3 = 0;
  if ( this->keyVals.num > 0 )
  {
    v4 = 0;
    do
    {
      v5 = &this->keyVals.list[v4];
      if ( v5->val.len != 0 )
        data = this->keyVals.list[v4].val.data;
      else
        data = nullptr;
      cvarSystem->SetCVarString(this: cvarSystem, a2: v5->key.data, a3: data, a4: 0);
      ++v3;
      ++v4;
    }
    while ( v3 < this->keyVals.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_GiveItems@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCD688
// RVA : 0x00CCD688
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_GiveItems::OnActivate(idTarget_GiveItems *this, idEntity *activator)
{
  idJobManager *v4; // r26
  int v5; // r25
  int v6; // r28
  idTarget_GiveItems::itemListElement_t *list; // r11
  idJob *JobByDecl; // r3
  idInventoryItem *v9; // r31
  idTarget_GiveItems::itemListElement_t *v10; // r11
  int v11; // r30
  idPresentable *presentable; // r4
  idTarget_GiveItems::itemListElement_t *v13; // r31
  idPresentable *v14; // r11

  if ( activator == nullptr )
  {
    idLib::Warning(fmt: "idTarget_GiveItems: activated by NULL");
    return;
  }
  v4 = (idJobManager *)activator->GetInventory_2(this: activator);
  if ( v4 == nullptr )
  {
    idLib::Warning(fmt: "idTarget_GiveItems: no inventory on %s", activator->name.data);
    return;
  }
  v5 = 0;
  if ( this->itemList.num > 0 )
  {
    v6 = 0;
    while ( 1 )
    {
      list = this->itemList.list;
      if ( !this->addUpToCount )
        goto LABEL_15;
      JobByDecl = idJobManager::FindJobByDecl(this: v4, jobDecl: (const idDeclJob *)list[v6].item);
      v9 = (idInventoryItem *)JobByDecl;
      if ( JobByDecl == nullptr )
        break;
      v10 = this->itemList.list;
      if ( v10[v6].item == nullptr )
        break;
      v11 = v10[v6].item->count * v10[v6].count;
      if ( ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl) < v11 )
      {
        presentable = activator->presentable;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this: activator);
          presentable = activator->presentable;
        }
        idInventoryCollection::SetItemCount(
          this: (idInventoryCollection *)v4,
          owner: presentable,
          item: v9,
          count: v11,
          forceCount: true);
      }
LABEL_18:
      ++v5;
      ++v6;
      if ( v5 >= this->itemList.num )
        goto LABEL_19;
    }
    list = this->itemList.list;
LABEL_15:
    v13 = &list[v6];
    v14 = activator->presentable;
    if ( v14 == nullptr )
    {
      idEntity::InitPresentableInternal(this: activator);
      v14 = activator->presentable;
    }
    idInventoryCollection::GiveItem(
      this: (idInventoryCollection *)v4,
      owner: v14,
      decl: v13->item,
      count: v13->count,
      forceCount: false,
      canIntro: false);
    goto LABEL_18;
  }
LABEL_19:
  this->ActivateTargets(this, a2: activator);
}


// ========================================================================
// ?OnActivate@idTarget_RemoveItems@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCD810
// RVA : 0x00CCD810
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_RemoveItems::OnActivate(idTarget_RemoveItems *this, idEntity *activator)
{
  idInventoryCollection *v4; // r26
  int v5; // r28
  int v6; // r31
  idPresentable *presentable; // r11
  idTarget_RemoveItems::itemListElement_t *v8; // r30

  if ( activator != nullptr )
  {
    v4 = activator->GetInventory_2(this: activator);
    if ( v4 != nullptr )
    {
      v5 = 0;
      if ( this->itemList.num > 0 )
      {
        v6 = 0;
        do
        {
          presentable = activator->presentable;
          v8 = &this->itemList.list[v6];
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this: activator);
            presentable = activator->presentable;
          }
          idInventoryCollection::DeleteInventoryItem(this: v4, owner: presentable, decl: v8->item, count: v8->count);
          ++v5;
          ++v6;
        }
        while ( v5 < this->itemList.num );
      }
      this->ActivateTargets(this, a2: activator);
    }
    else
    {
      idLib::Warning(fmt: "idTarget_RemoveItems: no inventory on %s", activator->name.data);
    }
  }
  else
  {
    idLib::Warning(fmt: "idTarget_RemoveItems: activated by NULL");
  }
}


// ========================================================================
// ?OnActivate@idTarget_EquipItem@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCD8F8
// RVA : 0x00CCD8F8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_EquipItem::OnActivate(idTarget_EquipItem *this, idPlayer *activator)
{
  idPlayer *v4; // r3
  idPlayer *v5; // r27
  char *data; // r4
  idJobManager *v7; // r3
  idInventoryCollection *v8; // r28
  idJob *JobByDecl; // r29
  idPresentable *presentable; // r4
  idWeapon *v11; // r3
  idWeapon *v12; // r30
  idJob *v13; // r3
  idInventoryItem *v14; // r29
  int ClipSize; // r3
  idPresentable *v16; // r4
  idJob *v17; // r3
  idInventoryItem *v18; // r29
  int v19; // r3
  const idDeclAmmo *ammoDecl; // r4
  idJob *v21; // r29
  idPresentable *v22; // r4
  idPresentable *v23; // r3
  int v24; // r3
  idWeapon_vtbl *v25; // r29
  int v26; // r3
  idPresentable *v27; // r3
  equipSlot_t equipSlot; // r29
  int v29; // r3
  int v30; // r3

  v4 = idPlayer::CastTo(c: activator);
  v5 = v4;
  if ( v4 != nullptr )
  {
    if ( this->itemToEquip == nullptr )
    {
      idLib::Warning(fmt: "idTarget_EquipItem '%s' does not have itemToEquip", this->name.data);
      return;
    }
    v7 = (idJobManager *)v4->GetInventory_2(this: v4);
    v8 = (idInventoryCollection *)v7;
    if ( v7 == nullptr )
    {
      idLib::Warning(fmt: "idTarget_EquipItem '%s' no inventory on '%s'", this->name.data, activator->name.data);
      return;
    }
    JobByDecl = idJobManager::FindJobByDecl(this: v7, jobDecl: (const idDeclJob *)this->itemToEquip);
    if ( JobByDecl == nullptr )
    {
      presentable = v5->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: v5);
        presentable = v5->presentable;
      }
      idInventoryCollection::GiveItem(
        this: v8,
        owner: presentable,
        decl: this->itemToEquip,
        count: 1,
        forceCount: false,
        canIntro: false);
      JobByDecl = idJobManager::FindJobByDecl(this: (idJobManager *)v8, jobDecl: (const idDeclJob *)this->itemToEquip);
      if ( JobByDecl == nullptr )
      {
        idLib::Warning(
          fmt: "idTarget_EquipItem '%s' error giving item '%s",
          this->name.data,
          this->itemToEquip->name.str);
        return;
      }
    }
    v11 = idWeapon::CastTo(c: (idWeapon *)JobByDecl);
    v12 = v11;
    if ( v11 != nullptr )
    {
      if ( this->sniperHACK )
      {
        if ( this->ammoDecl != nullptr )
        {
          v11->ammoInClipToSave = idWeapon::AmmoInClip(this: v11, secondaryAmmo: false);
          v12->LoadAmmo(
            this: v12,
            a2: nullptr,
            a3: this->ammoDecl,
            a4: nullptr,
            a5: false,
            a6: true,
            a7: false,
            a8: false);
          v13 = idJobManager::FindJobByDecl(this: (idJobManager *)v8, jobDecl: (const idDeclJob *)this->ammoDecl);
          v14 = (idInventoryItem *)v13;
          if ( v13 != nullptr )
          {
            *(_DWORD *)&v13->seen = ((int (__fastcall *)(idJob *))v13->__vftable[2].dtr_idClass)(a1: v13);
            ClipSize = idDeclWeapon::GetClipSize(
                         this: (idDeclWeapon *)v12->decl,
                         ammoDecl: this->ammoDecl,
                         weaponUpgraded: (*((_BYTE *)v12 + 452) & 4) != 0,
                         secondary: false);
            idInventoryItem::SetCount(this: v14, amount: 250 - ClipSize);
          }
          else
          {
            v16 = v5->presentable;
            if ( v16 == nullptr )
            {
              idEntity::InitPresentableInternal(this: v5);
              v16 = v5->presentable;
            }
            idInventoryCollection::GiveItem(
              this: v8,
              owner: v16,
              decl: this->ammoDecl,
              count: 1,
              forceCount: false,
              canIntro: false);
            v17 = idJobManager::FindJobByDecl(this: (idJobManager *)v8, jobDecl: (const idDeclJob *)this->ammoDecl);
            v18 = (idInventoryItem *)v17;
            if ( v17 != nullptr )
            {
              *(_DWORD *)&v17->seen = 0;
              v19 = idDeclWeapon::GetClipSize(
                      this: (idDeclWeapon *)v12->decl,
                      ammoDecl: this->ammoDecl,
                      weaponUpgraded: (*((_BYTE *)v12 + 452) & 4) != 0,
                      secondary: false);
              idInventoryItem::SetCount(this: v18, amount: 250 - v19);
            }
          }
        }
        else
        {
          idLib::Warning(fmt: "idTarget_EquipItem '%s' No ammo decl set when sniper Hack is true", this->name.data);
        }
      }
      ammoDecl = this->ammoDecl;
      v21 = nullptr;
      if ( ammoDecl != nullptr )
      {
        v21 = idJobManager::FindJobByDecl(this: (idJobManager *)v8, jobDecl: (const idDeclJob *)ammoDecl);
        if ( v21 == nullptr )
        {
          v22 = v5->presentable;
          if ( v22 == nullptr )
          {
            idEntity::InitPresentableInternal(this: v5);
            v22 = v5->presentable;
          }
          idInventoryCollection::GiveItem(
            this: v8,
            owner: v22,
            decl: this->ammoDecl,
            count: 1,
            forceCount: false,
            canIntro: false);
          v21 = idJobManager::FindJobByDecl(this: (idJobManager *)v8, jobDecl: (const idDeclJob *)this->ammoDecl);
          if ( v21 == nullptr )
          {
            idLib::Warning(
              fmt: "idTarget_EquipItem '%s' error giving ammo, weapon '%s', ammo '%s'",
              this->name.data,
              this->itemToEquip->name.str,
              this->ammoDecl->name.str);
            return;
          }
        }
        if ( idWeapon::GetAmmoDeclIndex(this: v12, ammo: this->ammoDecl, secondaryAmmo: false) < 0 )
        {
          v21 = nullptr;
          idLib::Warning(
            fmt: "idTarget_EquipItem '%s' error, ammo type not on weapon type, weapon '%s', ammo '%s'",
            this->name.data,
            this->itemToEquip->name.str,
            this->ammoDecl->name.str);
        }
      }
      if ( idActor::GetEquippedWeapon(this: v5, slot: EQUIP_RIGHT_HAND) == v12 )
      {
        if ( v21 != nullptr )
        {
          v23 = v5->presentable;
          if ( v23 != nullptr )
            v24 = (int)v23->GetPlayerInterface_2(this: v23);
          else
            v24 = 0;
          idHands::SelectAmmo(this: (idHands *)(v24 + 37616), slot: EQUIP_RIGHT_HAND, ammoDecl: this->ammoDecl);
        }
      }
      else
      {
        if ( v21 != nullptr )
        {
          v25 = v12->__vftable;
          v26 = (int)v5->GetFXMgrForAttachment(this: v5, a2: v12);
          v25->LoadAmmo(
            this: v12,
            a2: v8,
            a3: this->ammoDecl,
            a4: (idFXManager *)v26,
            a5: false,
            a6: true,
            a7: false,
            a8: false);
        }
        v27 = v5->presentable;
        equipSlot = v12->decl->equipSlot;
        if ( this->sniperHACK )
        {
          if ( v27 != nullptr )
            v29 = (int)v27->GetPlayerInterface_2(this: v27);
          else
            v29 = 0;
          idHands::SelectWeaponInstantly(this: (idHands *)(v29 + 37616), slot: equipSlot, weapon: v12);
        }
        else
        {
          if ( v27 != nullptr )
            v30 = (int)v27->GetPlayerInterface_2(this: v27);
          else
            v30 = 0;
          idHands::SelectWeapon(
            this: (idHands *)(v30 + 37616),
            slot: equipSlot,
            weapon: v12,
            useIntroBringUp: this->useIntro);
        }
      }
      if ( this->sniperHACK )
      {
        *(_BYTE *)(idPlayer::GetPlayerHud(this: v5) + 93) = 0;
        *(_BYTE *)(idPlayer::GetPlayerHud(this: v5) + 92) = 0;
      }
    }
    else
    {
      idPlayer::EquipItem(this: v5, item: (idInventoryItem *)JobByDecl);
    }
    this->ActivateTargets(this, a2: activator);
  }
  else
  {
    data = this->name.data;
    if ( activator != nullptr )
      idLib::Warning(fmt: "idTarget_EquipItem '%s' called with non player '%s'", data, activator->name.data);
    else
      idLib::Warning(fmt: "idTarget_EquipItem '%s' called with null activator", data);
  }
}


// ========================================================================
// ?OnActivate@idTarget_EnableGroup@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCDDD0
// RVA : 0x00CCDDD0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_EnableGroup::OnActivate(idTarget_EnableGroup *this, idEntity *activate)
{
  idEncounterGroupManager *p_encounterGroupManager; // r30
  idEncounterGroup *v4; // r3
  idHandle<short,enum invalidEncounterGroup_t,-1> v5[4]; // [sp+50h] [-20h] BYREF

  p_encounterGroupManager = &gameLocal->encounterGroupManager;
  idEncounterGroupManager::FindGroup(
    this: (idEncounterGroupManager *)v5,
    result: p_encounterGroupManager,
    groupName: this->groupName.data);
  if ( (unsigned __int16)v5[0].value != 0xFFFF )
  {
    v4 = idEncounterGroupManager::GroupForHandle(this: p_encounterGroupManager, handle: v5);
    idEncounterGroup::OnGroupMessage(this: v4, msg: (aiGroupMessage_t)!this->enable, ent: nullptr);
  }
}


// ========================================================================
// ?OnActivate@idTarget_GroupExpression@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCDE58
// RVA : 0x00CCDE58
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_GroupExpression::OnActivate(idTarget_GroupExpression *this, idEntity *activator)
{
  idEncounterGroupManager *p_encounterGroupManager; // r31
  idEncounterGroup *v4; // r28
  int v5; // r31
  int v6; // r30
  idHandle<short,enum invalidEncounterGroup_t,-1> v7[24]; // [sp+50h] [-30h] BYREF

  p_encounterGroupManager = &gameLocal->encounterGroupManager;
  idEncounterGroupManager::FindGroup(
    this: (idEncounterGroupManager *)v7,
    result: p_encounterGroupManager,
    groupName: this->groupName.data);
  if ( (unsigned __int16)v7[0].value != 0xFFFF )
  {
    v4 = idEncounterGroupManager::GroupForHandle(this: p_encounterGroupManager, handle: v7);
    v5 = 0;
    if ( this->expressions.num > 0 )
    {
      v6 = 0;
      do
      {
        idEncounterGroupExpr::CheckTrigger(this: &this->expressions.list[v6], group: v4);
        ++v5;
        ++v6;
      }
      while ( v5 < this->expressions.num );
    }
  }
}


// ========================================================================
// ?OnActivate@idTarget_AIEvent@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCDEE8
// RVA : 0x00CCDEE8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_AIEvent::OnActivate(idTarget_AIEvent *this, idEntity *activator)
{
  idAIEventManager *p_aiEventManager; // r30
  idHandle<int,enum invalidAIEvent_t,-1> *p_eventHandle; // r28
  idPhysics *Physics; // r27
  int GameMs; // r26
  const idVec3 *v8; // r3
  idAIEvent *Event; // r3
  idHandle<int,enum invalidAIEvent_t,-1> v10[16]; // [sp+50h] [-40h] BYREF

  p_aiEventManager = &gameLocal->aiEventManager;
  if ( (idGameLocal *)0xFFEAB330 != gameLocal )
  {
    p_eventHandle = &this->eventHandle;
    if ( this->eventHandle.value == -1 )
    {
      if ( this->eventDecl != nullptr )
      {
        idLib::Warning(fmt: "Invalid AI event on idTarget_AIEvent '%s'", this->name.data);
      }
      else
      {
        Physics = idEntity::GetPhysics(this);
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v8 = Physics->GetOrigin(this: Physics, a2: 0);
        idAIEventManager::AddEvent(
          this: (idAIEventManager *)v10,
          result: p_aiEventManager,
          eventDecl: this->eventDecl,
          curTime: GameMs,
          originator: this,
          instigator: activator,
          origin: v8,
          delay: 0);
        if ( v10[0].value != -1 )
        {
          Event = idAIEventManager::GetEvent(this: p_aiEventManager, handle: v10);
          if ( idAIEvent::GetDuration(this: Event) == -1 )
            p_eventHandle->value = (int)v10[0];
        }
      }
    }
    else
    {
      idAIEventManager::RemoveEvent(this: &gameLocal->aiEventManager, handle: &this->eventHandle);
    }
  }
}


// ========================================================================
// ?Spawn@idTarget_InhibitControl@@QAAXXZ
// EA  : 0x82CCDFF0
// RVA : 0x00CCDFF0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_InhibitControl::Spawn(idTarget_InhibitControl *this)
{
  double duration; // fp1

  if ( this->toggleOnActivate )
  {
    duration = this->duration;
    if ( duration > 0.0 )
    {
      idLib::Warning(
        fmt: "idTarget_InhibitControl '%s' don't use toggleOnActivate at the same time as duration(%f) > 0, removing entity",
        this->name.data,
        duration);
      idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
    }
  }
}


// ========================================================================
// ?OnActivate@idTarget_InhibitControl@@UAAXPAVidEntity@@@Z
// EA  : 0x82CCE068
// RVA : 0x00CCE068
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_InhibitControl::OnActivate(idTarget_InhibitControl *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r29
  idTarget_InhibitControl::inhibitType_t inhibit; // r11
  const idEventArg *v6; // [sp+70h] [-80h]
  const idEventArg *v7; // [sp+78h] [-78h]
  const idEventArg *v8; // [sp+80h] [-70h]
  const idEventArg *v9; // [sp+90h] [-60h]
  const idEventArg *v10; // [sp+98h] [-58h]

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity != nullptr || (PlayerFromEntity = idGameLocal::GetPlayer(this: gameLocal, i: 0)) != nullptr )
  {
    if ( this->toggleOnActivate )
      this->activated = (_cntlzw(this->activated) & 0x20) != 0;
    if ( (this->inhibit & 1) != 0 )
    {
      HIBYTE(v6) = 105;
      idEventReceiver::PostEventSec(this: PlayerFromEntity, ev: &EV_InhibitControl, time: this->delay, arg1: v6);
      if ( this->duration > 0.0 )
      {
        HIBYTE(v6) = 105;
        idEventReceiver::PostEventSec(
          this: PlayerFromEntity,
          ev: &EV_InhibitControl,
          time: (float)(this->delay + this->duration),
          arg1: v6);
      }
    }
    if ( (this->inhibit & 0x90) != 0 )
    {
      idEventReceiver::PostEventSec(
        this: PlayerFromEntity,
        ev: &EV_InhibitFreeGamePlay,
        time: this->delay,
        arg1: v8,
        arg2: v10);
      if ( this->duration > 0.0 )
        idEventReceiver::PostEventSec(
          this: PlayerFromEntity,
          ev: &EV_InhibitFreeGamePlay,
          time: (float)(this->delay + this->duration),
          arg1: v8,
          arg2: v7);
    }
    if ( (this->inhibit & 2) != 0 )
    {
      HIBYTE(v9) = 105;
      idEventReceiver::PostEventSec(this: PlayerFromEntity, ev: &EV_InhibitMove, time: this->delay, arg1: v9);
      if ( this->duration > 0.0 )
      {
        HIBYTE(v9) = 105;
        idEventReceiver::PostEventSec(
          this: PlayerFromEntity,
          ev: &EV_InhibitMove,
          time: (float)(this->delay + this->duration),
          arg1: v9);
      }
    }
    inhibit = this->inhibit;
    if ( (inhibit & 4) != 0 || (inhibit & 8) != 0 )
    {
      HIBYTE(v6) = 105;
      idEventReceiver::PostEventSec(this: PlayerFromEntity, ev: &EV_InhibitLook, time: this->delay, arg1: v6, arg2: v7);
      if ( this->duration > 0.0 )
      {
        HIBYTE(v9) = 105;
        idEventReceiver::PostEventSec(
          this: PlayerFromEntity,
          ev: &EV_InhibitLook,
          time: (float)(this->delay + this->duration),
          arg1: v9,
          arg2: v10);
      }
    }
    if ( (this->inhibit & 0x20) != 0 )
    {
      HIBYTE(v9) = 105;
      idEventReceiver::PostEventSec(this: PlayerFromEntity, ev: &EV_InhibitRaiseWeapon, time: this->delay, arg1: v9);
      if ( this->duration > 0.0 )
      {
        HIBYTE(v9) = 105;
        idEventReceiver::PostEventSec(
          this: PlayerFromEntity,
          ev: &EV_InhibitRaiseWeapon,
          time: (float)(this->delay + this->duration),
          arg1: v9);
      }
    }
    if ( (this->inhibit & 0x40) != 0 )
    {
      HIBYTE(v9) = 105;
      idEventReceiver::PostEventSec(this: PlayerFromEntity, ev: &EV_InhibitChangeWeapon, time: this->delay, arg1: v9);
      if ( this->duration > 0.0 )
      {
        HIBYTE(v9) = 105;
        idEventReceiver::PostEventSec(
          this: PlayerFromEntity,
          ev: &EV_InhibitChangeWeapon,
          time: (float)(this->delay + this->duration),
          arg1: v9);
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "idTarget_InhibitControl: couldn't get a player from (%s)", activator->name.data);
  }
}


// ========================================================================
// ?OnActivate@idTarget_Achievement@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCE4A8
// RVA : 0x00CCE4A8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Achievement::OnActivate(idTarget_Achievement *this, idPlayer *activator)
{
  idPlayer *v4; // r3
  idPlayer *v5; // r31
  idPresentable *presentable; // r30
  const idDeclInventory *achievementInventory; // r28
  idInventoryCollection *v8; // r3
  triggerAchievementId_t triggerAchievementId; // r4

  v4 = idPlayer::CastTo(c: activator);
  v5 = v4;
  if ( v4 != nullptr )
  {
    if ( this->achievementInventory != nullptr && v4->GetInventory_2(this: v4) != nullptr )
    {
      presentable = v5->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: v5);
        presentable = v5->presentable;
      }
      achievementInventory = this->achievementInventory;
      v8 = v5->GetInventory_2(this: v5);
      idInventoryCollection::GiveItem(
        this: v8,
        owner: presentable,
        decl: achievementInventory,
        count: 1,
        forceCount: false,
        canIntro: false);
    }
    triggerAchievementId = this->triggerAchievementId;
    if ( triggerAchievementId != TAID_NONE )
      idAchievementManager::TriggerCompletesAchievement(this: &v5->achievementManager, taid: triggerAchievementId);
  }
  else if ( activator != nullptr )
  {
    idLib::Warning(fmt: "idTarget_Achievement activated by non-player '%s'", activator->name.data);
  }
  else
  {
    idLib::Warning(fmt: "idTarget_Achievement activated by non-player '%s'", "NULL");
  }
}


// ========================================================================
// ?OnActivate@idTarget_UpdateVehicleKey@@UAAXPAVidEntity@@@Z
// EA  : 0x82CCE598
// RVA : 0x00CCE598
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_UpdateVehicleKey::OnActivate(idTarget_UpdateVehicleKey *this, idPlayer *activator)
{
  idPlayer *v3; // r3
  idPlayer *v4; // r28
  const idDeclJob *keyDecl; // r31
  idJobManager *v6; // r3
  idVehicleKey *JobByDecl; // r3
  idVehicleKey *v8; // r25
  int v9; // r27
  int v10; // r26
  const idDeclVehicleUpgrade **list; // r11
  const idDeclInventory *v12; // r31
  idJobManager *v13; // r3
  idPresentable *presentable; // r30
  idInventoryCollection *v15; // r3
  garageList_t garage; // r11

  v3 = idPlayer::CastTo(c: activator);
  v4 = v3;
  if ( v3 != nullptr )
  {
    keyDecl = (const idDeclJob *)this->keyDecl;
    if ( keyDecl != nullptr )
    {
      v6 = (idJobManager *)v3->GetInventory_2(this: v3);
      JobByDecl = (idVehicleKey *)idJobManager::FindJobByDecl(this: v6, jobDecl: keyDecl);
      v8 = idVehicleKey::CastTo(c: JobByDecl);
      if ( v8 != nullptr )
      {
        v9 = 0;
        if ( this->upgradeDecls.num > 0 )
        {
          v10 = 0;
          do
          {
            list = this->upgradeDecls.list;
            v12 = list[v10];
            if ( v12 != nullptr )
            {
              idVehicleKey::EquipUpgrade(this: v8, upgrade: list[v10], init: false);
              if ( this->giveUpgrades )
              {
                v13 = (idJobManager *)v4->GetInventory_2(this: v4);
                if ( idJobManager::FindJobByDecl(this: v13, jobDecl: (const idDeclJob *)v12) == nullptr )
                {
                  presentable = v4->presentable;
                  if ( presentable == nullptr )
                  {
                    idEntity::InitPresentableInternal(this: v4);
                    presentable = v4->presentable;
                  }
                  v15 = v4->GetInventory_2(this: v4);
                  idInventoryCollection::GiveItem(
                    this: v15,
                    owner: presentable,
                    decl: v12,
                    count: 1,
                    forceCount: false,
                    canIntro: false);
                }
              }
            }
            else
            {
              idLib::Warning(fmt: "upgradeDecl is NULL on idTarget_UpdateVehicleKey %d", v9);
            }
            ++v9;
            ++v10;
          }
          while ( v9 < this->upgradeDecls.num );
        }
        garage = this->garage;
        if ( garage != GARAGE_MAX )
        {
          v8->vehicleGarage = garage;
          if ( this->garage != GARAGE_NONE )
            idVehicleKey::SetMinValuesForGarage(this: v8);
        }
        if ( this->markForGarageView )
          v8->shouldGarageView = this->markForGarageView;
        if ( this->giveMaxHealth )
          idVehicleKey::SetHealth(this: v8, h: v8->maxHealth);
        if ( this->respawnVehicles )
          idPlayer::SpawnVehicles(this: v4);
      }
      else
      {
        idLib::Warning(fmt: "player did not have key %s in idTarget_UpdateVehicleKey", this->keyDecl->name.str);
      }
    }
    else
    {
      idLib::Warning(fmt: "keyDecl is NULL on idTarget_UpdateVehicleKey");
    }
  }
  else
  {
    idLib::Warning(fmt: "Activator must be player to idTarget_UpdateVehicleKey");
  }
}


// ========================================================================
// ?OnActivate@idTarget_GiveJobNote@@UAAXPAVidEntity@@@Z
// EA  : 0x82CCE778
// RVA : 0x00CCE778
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_GiveJobNote::OnActivate(idTarget_GiveJobNote *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r3

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity != nullptr || (PlayerFromEntity = idGameLocal::GetDebugPlayer(this: gameLocal)) != nullptr )
  {
    idJobManager::AddJobNote(
      this: &PlayerFromEntity->jobManager,
      jobNote: this->jobNote,
      force: this->forceReset,
      updateHUD: true,
      checkForActiveJob: false);
  }
  else if ( activator != nullptr )
  {
    idLib::Warning(fmt: "idTarget_GiveJobNote activated with %s not a player", activator->name.data);
  }
  else
  {
    idLib::Warning(fmt: "idTarget_GiveJobNote activated with %s not a player", "NULL");
  }
}


// ========================================================================
// ?OnActivate@idTarget_RemoveJobNote@@UAAXPAVidEntity@@@Z
// EA  : 0x82CCE810
// RVA : 0x00CCE810
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_RemoveJobNote::OnActivate(idTarget_RemoveJobNote *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r3

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity != nullptr || (PlayerFromEntity = idGameLocal::GetDebugPlayer(this: gameLocal)) != nullptr )
  {
    idJobManager::RemoveJobNote(
      this: &PlayerFromEntity->jobManager,
      jobNoteDecl: this->jobNote,
      checkForActiveJob: false);
  }
  else if ( activator != nullptr )
  {
    idLib::Warning(fmt: "idTarget_GiveJobNote activated with %s not a player", activator->name.data);
  }
  else
  {
    idLib::Warning(fmt: "idTarget_GiveJobNote activated with %s not a player", "NULL");
  }
}


// ========================================================================
// ??0idTarget_StartSoundShader@@QAA@XZ
// EA  : 0x82CCE8A0
// RVA : 0x00CCE8A0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_StartSoundShader *__fastcall idTarget_StartSoundShader::idTarget_StartSoundShader(
        idTarget_StartSoundShader *this)
{
  idEntity::idEntity(this);
  this->voToPlay = nullptr;
  this->__vftable = (idTarget_StartSoundShader_vtbl *)&idTarget_StartSoundShader::`vftable';
  this->soundToPlay = nullptr;
  this->fromWho.index = -1;
  this->randomizeTarget = true;
  this->globalSound = false;
  return this;
}


// ========================================================================
// ?Spawn@idTarget_ForceDormancy@@QAAXXZ
// EA  : 0x82CCE900
// RVA : 0x00CCE900
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ForceDormancy::Spawn(idTarget_ForceDormancy *this)
{
  int durationMS; // r5

  durationMS = this->durationMS;
  if ( durationMS <= 0 )
    idLib::Error(fmt: "'%s' duration is invalid (%d).", this->name.data, durationMS);
}


// ========================================================================
// ?OnActivate@idTarget_Disconnect@@UAAXPAVidEntity@@@Z
// EA  : 0x82CCE920
// RVA : 0x00CCE920
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Disconnect::OnActivate(idTarget_Disconnect *this, idPlayer *activator)
{
  idPlayer *DebugPlayer; // r31
  idPresentable *presentable; // r3
  float *v5; // r3
  idPresentable *v6; // r3
  int v7; // r3
  idEventArg *v8; // r3
  idEventArg v9; // [sp+50h] [-30h] BYREF

  DebugPlayer = idPlayer::CastTo(c: activator);
  if ( DebugPlayer == nullptr )
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  presentable = DebugPlayer->presentable;
  if ( presentable != nullptr )
    v5 = (float *)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = nullptr;
  v5[4767] = 1.0;
  v5[4768] = 1.0;
  v5[4769] = 1.0;
  v5[4770] = 1.0;
  v6 = DebugPlayer->presentable;
  if ( v6 != nullptr )
    v7 = (int)v6->GetPlayerInterface_2(this: v6);
  else
    v7 = 0;
  idView::Fade(this: (idView *)(v7 + 16224), color: (const idVec4 *)&idColor::colorBlack, time: 750);
  idPlayer::SetForceInhibitControl(this: DebugPlayer, inhibit: true);
  v8 = idEventArg::idEventArg(this: &v9, data: DebugPlayer);
  idEventReceiver::PostEventMS(
    this,
    ev: &EV_DoTransition,
    time: *(_DWORD *)&v8->type,
    arg1: (const idEventArg *)LODWORD(v8->value.v[1]));
}


// ========================================================================
// ?Event_DoTransition@idTarget_Disconnect@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82CCEA28
// RVA : 0x00CCEA28
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_Disconnect *__fastcall idTarget_Disconnect::Event_DoTransition(
        idTarget_Disconnect *this,
        eventVoid *result,
        idPlayer *activator)
{
  idPlayer *DebugPlayer; // r31
  __int64 v5; // r8
  __int64 v6; // r10
  __int64 v7; // r6
  va *v8; // r3
  int v10; // [sp+8h] [-1068h]
  int v11; // [sp+Ch] [-1064h]
  int v12; // [sp+10h] [-1060h]
  int v13; // [sp+14h] [-105Ch]
  int v14; // [sp+18h] [-1058h]
  int v15; // [sp+1Ch] [-1054h]
  va v16; // [sp+50h] [-1020h] BYREF

  DebugPlayer = idPlayer::CastTo(c: activator);
  if ( DebugPlayer == nullptr )
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  idCVar::SetBool(this: &swf_waitForCredits, newValue: true, force: true);
  idPlayer::SetForceInhibitControl(this: DebugPlayer, inhibit: false);
  HIDWORD(v5) = &byte_8200D768;
  LODWORD(v6) = &byte_8200D768;
  HIDWORD(v6) = &byte_8200D768;
  LODWORD(v5) = &byte_8200D768;
  LODWORD(v7) = "outro";
  HIDWORD(v7) = 1;
  v8 = va::va(
         this: &v16,
         fmt: "nextmap %d %s \"%s\" \"%s\" \"%s\" \"%s\"\n",
         a3: v7,
         a4: v5,
         a5: v6,
         a6: v10,
         a7: v11,
         a8: v12,
         a9: v13,
         a10: v14,
         a11: v15);
  cmdSystem->AppendCommandText(this: cmdSystem, a2: v8->buffer);
  return this;
}


// ========================================================================
// ?OnActivate@idTarget_GameChallengeGameOver@@UAAXPAVidEntity@@@Z
// EA  : 0x82CCEAF0
// RVA : 0x00CCEAF0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_GameChallengeGameOver::OnActivate(idTarget_GameChallengeGameOver *this, idEntity *activator)
{
  idGameLocal::GetChallengeEntity(this: gameLocal)->bGameFailed = this->failure;
  idGameLocal::GetChallengeEntity(this: gameLocal)->gameFailedText.index = this->failureText.index;
  gameLocal->challengeState = CHALLENGE_STATE_GAME_OVER;
}


// ========================================================================
// ?OnActivate@idTarget_CoopGiveScore@@UAAXPAVidEntity@@@Z
// EA  : 0x82CCEB58
// RVA : 0x00CCEB58
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_CoopGiveScore::OnActivate(idTarget_CoopGiveScore *this, idEntity *activator)
{
  idGameChallenge_Coop *ChallengeEntity; // r3
  idGameChallenge_Coop *v4; // r3
  idGameChallenge_Coop *v5; // r31

  ChallengeEntity = (idGameChallenge_Coop *)idGameLocal::GetChallengeEntity(this: gameLocal);
  v4 = idGameChallenge_Coop::CastTo(c: ChallengeEntity);
  v5 = v4;
  if ( v4 != nullptr && v4->bObjectiveActive )
  {
    idLib::Printf(fmt: "debug score: %d\n", this->scoreAmount);
    v5->objectiveScore += this->scoreAmount;
  }
}


// ========================================================================
// ??0idTarget_Print@@QAA@XZ
// EA  : 0x82CCEBD0
// RVA : 0x00CCEBD0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_Print *__fastcall idTarget_Print::idTarget_Print(idTarget_Print *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_Print_vtbl *)&idTarget_Print::`vftable';
  this->message.len = 0;
  this->message.allocedAndFlag = 20;
  this->message.data = this->message.baseBuffer;
  this->message.baseBuffer[0] = 0;
  return this;
}


// ========================================================================
// ?Spawn@idTarget_Print@@QAAXXZ
// EA  : 0x82CCEC30
// RVA : 0x00CCEC30
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Print::Spawn(idTarget_Print *this)
{
  if ( idLib::production == PROD_PRODUCTION )
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
}


// ========================================================================
// ?OnActivate@idTarget_Print@@UAAXPAVidEntity@@@Z
// EA  : 0x82CCEC58
// RVA : 0x00CCEC58
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Print::OnActivate(idTarget_Print *this, idEntity *activator)
{
  idLib::Printf(fmt: this->message.data, activator);
}


// ========================================================================
// ?SetBulletsFly@idTarget_DummyFire@@AAAX_N@Z
// EA  : 0x82CCEC60
// RVA : 0x00CCEC60
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_DummyFire::SetBulletsFly(idTarget_DummyFire *this, bool _bBulletsFly)
{
  float *presentable; // r11
  idFXManager *v5; // r28
  float *v6; // r27
  double v7; // fp9
  double v8; // fp7
  double v9; // fp6
  BOOL bBulletsFly; // r11
  unsigned int GameMs; // r3
  int v12; // r27
  unsigned int GameMsPerFrame; // r25
  int v14; // r24
  idPhysics *Physics; // r3
  const idMat3 *v16; // r23
  idPhysics *v17; // r3
  const idVec3 *v18; // r3
  idPhysics *v19; // r3
  int v20; // r3
  idPresentable *v21; // r11
  const idVec3 *v22; // r27
  int v23; // r3
  int v24; // r27
  unsigned int v25; // r25
  int v26; // r24
  idPhysics *v27; // r3
  const idMat3 *v28; // r23
  idPhysics *v29; // r3
  const idVec3 *v30; // r3
  int v31; // r27
  unsigned int v32; // r29
  int v33; // r31
  idPhysics *v34; // r3
  const idMat3 *v35; // r25
  idPhysics *v36; // r3
  const idVec3 *v37; // r3
  idVec3 v38; // [sp+60h] [-70h] BYREF

  presentable = (float *)this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = (float *)this->presentable;
  }
  v5 = (idFXManager *)(presentable + 72);
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = (float *)this->presentable;
  }
  v6 = presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = (float *)this->presentable;
  }
  v7 = (float)(presentable[10] - v6[7]);
  v8 = (float)(presentable[9] - v6[6]);
  v9 = (float)(presentable[8] - v6[5]);
  bBulletsFly = this->bBulletsFly;
  v38.x = v9;
  v38.z = v7;
  v38.y = v8;
  if ( _bBulletsFly )
  {
    if ( !bBulletsFly )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idFXManager::StartFX(
        this: v5,
        org: &vec3_origin,
        axis: &mat3_identity,
        time: GameMs,
        startCondition: 55,
        extraCond: 68);
      v12 = idAccolade::Count(this: &clientGame->gameTimeManager);
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v14 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      Physics = idEntity::GetPhysics(this);
      v16 = Physics->GetAxis(this: Physics, a2: 0);
      v17 = idEntity::GetPhysics(this);
      v18 = v17->GetOrigin(this: v17, a2: 0);
      idFXManager::Update(
        this: v5,
        parentOrigin: v18,
        parentAxis: v16,
        parentVel: &v38,
        time: v14,
        gameMsPerFrame: GameMsPerFrame,
        frameNum: v12,
        fovScale: 1.0,
        depthHack: 0.0);
      if ( this->weapon != nullptr )
      {
        v19 = idEntity::GetPhysics(this);
        v20 = (int)v19->GetOrigin(this: v19, a2: 0);
        v21 = this->presentable;
        v22 = (const idVec3 *)v20;
        if ( v21 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v21 = this->presentable;
        }
        idWeapon::PlayFireSound(
          this: this->weapon,
          attacker: v21,
          target: nullptr,
          start: v22,
          projDef: this->projDecl,
          secondaryAmmo: false);
      }
    }
  }
  else if ( bBulletsFly )
  {
    v23 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idFXManager::StopFX(this: v5, time: v23, stopCondition: 55, immediateStop: false);
    v24 = idAccolade::Count(this: &clientGame->gameTimeManager);
    v25 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v26 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v27 = idEntity::GetPhysics(this);
    v28 = v27->GetAxis(this: v27, a2: 0);
    v29 = idEntity::GetPhysics(this);
    v30 = v29->GetOrigin(this: v29, a2: 0);
    idFXManager::Update(
      this: v5,
      parentOrigin: v30,
      parentAxis: v28,
      parentVel: &v38,
      time: v26,
      gameMsPerFrame: v25,
      frameNum: v24,
      fovScale: 1.0,
      depthHack: 0.0);
  }
  v31 = idAccolade::Count(this: &clientGame->gameTimeManager);
  v32 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v33 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v34 = idEntity::GetPhysics(this);
  v35 = v34->GetAxis(this: v34, a2: 0);
  v36 = idEntity::GetPhysics(this);
  v37 = v36->GetOrigin(this: v36, a2: 0);
  idFXManager::Update(
    this: v5,
    parentOrigin: v37,
    parentAxis: v35,
    parentVel: &v38,
    time: v33,
    gameMsPerFrame: v32,
    frameNum: v31,
    fovScale: 1.0,
    depthHack: 0.0);
  idEntity::UpdateSound(this);
  this->bBulletsFly = _bBulletsFly;
}


// ========================================================================
// ?AllocPresentable@idTarget_DummyFire@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82CCEFE0
// RVA : 0x00CCEFE0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idPresentable *__fastcall idTarget_DummyFire::AllocPresentable(idTarget_DummyFire *this, idTreeAnimator *renderModel_)
{
  const idDeclFX *effectsDecl; // r30
  const idDeclWeapon *weaponDecl; // r11
  idPresentable *v6; // r3

  if ( this->effectsDecl != nullptr )
  {
    effectsDecl = this->effectsDecl;
  }
  else
  {
    weaponDecl = this->weaponDecl;
    if ( weaponDecl != nullptr )
      effectsDecl = weaponDecl->weaponFX;
    else
      effectsDecl = nullptr;
  }
  v6 = (idPresentable *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x4B0u,
                          tag: TAG_PRESENTABLE,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v6 != nullptr )
    return idPresentable::idPresentable(this: v6, e: this, renderModel_, entityNumber_: 0x1FFF, fxDecl_: effectsDecl);
  else
    return nullptr;
}


// ========================================================================
// __unwind$501902
// EA  : 0x82CCF07C
// RVA : 0x00CCF07C
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_501902()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?Spawn@idTarget_DummyFire@@QAAXXZ
// EA  : 0x82CCF0B0
// RVA : 0x00CCF0B0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_DummyFire::Spawn(idTarget_DummyFire *this)
{
  const idDeclWeapon *weaponDecl; // r3
  int ammoIndex; // r11
  const idDeclAmmo *validAmmoDecl; // r10
  idWeapon *v5; // r3
  idWeapon *v6; // r30
  idWeapon *v7; // r3
  idPresentableWeapon *v8; // r30
  int entityNumber; // r28
  const idDeclWeapon *v10; // r27
  idTreeAnimator *RenderModelFromPresentable; // r3
  idPresentableWeapon *v12; // r30
  int v13; // r10
  int v14; // r9
  int v15; // r8
  int v16; // r7
  idPhysics *Physics; // r3
  float *v18; // r3
  idPhysics *v19; // r3
  float *v20; // r3
  int numShots; // r11
  idGameTimeManager *p_gameTimeManager; // r3
  int GameMs; // r3
  int v24; // r11
  int v25; // [sp+8h] [-88h]
  int v26; // [sp+Ch] [-84h]
  int v27; // [sp+10h] [-80h]
  int v28; // [sp+14h] [-7Ch]
  int v29; // [sp+18h] [-78h]
  idPresentable *v30; // [sp+1Ch] [-74h]

  weaponDecl = this->weaponDecl;
  if ( weaponDecl == nullptr )
  {
    idLib::Warning(fmt: "idTarget_DummyFire %s does not have a valid weaponDecl set", this->name.data);
LABEL_23:
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
    return;
  }
  ammoIndex = this->ammoIndex;
  if ( ammoIndex < 0 || ammoIndex >= weaponDecl->validAmmoClips.num )
  {
    idLib::Warning(
      fmt: "idTarget_DummyFire %s has invalid ammoIndex (%d) for weaponDecl %s",
      this->name.data,
      this->ammoIndex,
      weaponDecl->name.str);
    goto LABEL_23;
  }
  validAmmoDecl = weaponDecl->validAmmoClips.list[ammoIndex].validAmmoDecl;
  if ( validAmmoDecl == nullptr )
  {
    idLib::Warning(
      fmt: "idTarget_DummyFire %s using weaponDecl %s has NULL ammoIndex %d",
      this->name.data,
      weaponDecl->name.str,
      this->ammoIndex);
    goto LABEL_23;
  }
  if ( validAmmoDecl->projectileDecl == nullptr )
  {
    idLib::Warning(
      fmt: "idTarget_DummyFire %s using weaponDecl %s has ammoIndex %d with NULL projectileDecl",
      this->name.data,
      weaponDecl->name.str,
      this->ammoIndex);
    goto LABEL_23;
  }
  v5 = (idWeapon *)idInventoryItem::Create(decl: weaponDecl);
  v6 = v5;
  if ( v5 == nullptr )
  {
LABEL_12:
    idLib::Warning(
      fmt: "idTarget_DummyFire %s is using weaponDecl %s which isn't a valid idWeapon derivative",
      this->name.data,
      this->weaponDecl->name.str);
    goto LABEL_23;
  }
  v7 = idWeapon::CastTo(c: v5);
  this->weapon = v7;
  if ( v7 == nullptr )
  {
    ((void (__fastcall *)(idWeapon *, int))v6->dtr_idClass)(a1: v6, a2: 1);
    goto LABEL_12;
  }
  v8 = (idPresentableWeapon *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                size: 0x588u,
                                tag: TAG_NEW,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v8 != nullptr )
  {
    entityNumber = this->entityNumber;
    v10 = this->weaponDecl;
    RenderModelFromPresentable = (idTreeAnimator *)idEntity::GetRenderModelFromPresentable(this);
    v12 = idPresentableWeapon::idPresentableWeapon(
            this: v8,
            renderModel_: RenderModelFromPresentable,
            weaponDecl_: v10,
            ownerEntityNum_: entityNumber,
            animStack_: nullptr,
            ent_: nullptr,
            useSphereModel_: false);
  }
  else
  {
    v12 = nullptr;
  }
  idPresentableWeapon::SetClientWeapon(this: v12, weapon: this->weapon);
  idClientGame::AddPresentable(
    this: clientGame,
    presentable: v12,
    index: -1,
    skipReplication: false,
    a5: v16,
    a6: v15,
    a7: v14,
    a8: v13,
    a9: v25,
    a10: v26,
    a11: v27,
    a12: v28,
    a13: v29,
    a14: v30);
  Physics = idEntity::GetPhysics(this);
  v18 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v12->origin.x = *v18;
  v12->origin.y = v18[1];
  v12->origin.z = v18[2];
  v19 = idEntity::GetPhysics(this);
  v20 = (float *)v19->GetAxis(this: v19, a2: 0);
  v12->axis.mat[0].x = *v20;
  v12->axis.mat[0].y = v20[1];
  v12->axis.mat[0].z = v20[2];
  v12->axis.mat[1].x = v20[3];
  v12->axis.mat[1].y = v20[4];
  v12->axis.mat[1].z = v20[5];
  v12->axis.mat[2].x = v20[6];
  v12->axis.mat[2].y = v20[7];
  v12->axis.mat[2].z = v20[8];
  idWeapon::SetPresentableWeapon(this: this->weapon, presentableWeapon_: v12);
  numShots = this->numShots;
  if ( numShots <= 0 )
    numShots = 10;
  this->currentShotsLeft = numShots;
  p_gameTimeManager = &clientGame->gameTimeManager;
  if ( this->burstDuration > 0.0 )
  {
    GameMs = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
    v24 = (int)(float)(this->burstDuration * (float)1000.0);
  }
  else
  {
    GameMs = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
    v24 = (int)1000.0;
  }
  this->nextBurstChange = v24 + GameMs;
  this->bIsFiring = true;
  idEntity::BecomeInactive(this, flags: 1);
}


// ========================================================================
// __unwind$501929
// EA  : 0x82CCF3D4
// RVA : 0x00CCF3D4
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall _unwind_501929(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?Event_SetFireTime@idTarget_DummyFire@@QAA?AVeventVoid@@M@Z
// EA  : 0x82CCF400
// RVA : 0x00CCF400
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idTarget_DummyFire::Event_SetFireTime(idTarget_DummyFire *this, double time)
{
  __int64 result; // r4 OVERLAPPED

  *(float *)(result + 844) = time;
  return result;
}


// ========================================================================
// ?Event_SetFireDone@idTarget_DummyFire@@QAA?AVeventVoid@@XZ
// EA  : 0x82CCF408
// RVA : 0x00CCF408
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idTarget_DummyFire::Event_SetFireDone(idTarget_DummyFire *this)
{
  __int64 result; // r4 OVERLAPPED

  *(_DWORD *)(result + 916) = 0;
  return result;
}


// ========================================================================
// ?WhenShouldVehicleRespawn@idTarget_DynamicVehicleAiController@@QAAHPAVidVehicleAI@@@Z
// EA  : 0x82CCF418
// RVA : 0x00CCF418
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

unsigned int __fastcall idTarget_DynamicVehicleAiController::WhenShouldVehicleRespawn(
        idTarget_DynamicVehicleAiController *this,
        idVehicleAI *vehAI)
{
  int vehiclesKilled; // r9
  unsigned int result; // r3
  int vehiclesActive; // r10
  int numNormalVehicles; // r8
  unsigned int v7; // r3

  vehiclesKilled = this->vehiclesKilled;
  vehiclesActive = this->vehiclesActive;
  numNormalVehicles = this->numNormalVehicles;
  result = -1;
  if ( vehiclesKilled + vehiclesActive < numNormalVehicles )
  {
    v7 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v7;
    ++this->vehiclesActive;
    return ((v7 >> 10) & 0x7FFF) % 0x3E8 + 500;
  }
  return result;
}


// ========================================================================
// ?FindNextSpawnPos@idTarget_DynamicVehicleAiController@@AAAHH@Z
// EA  : 0x82CCF498
// RVA : 0x00CCF498
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

int __fastcall idTarget_DynamicVehicleAiController::FindNextSpawnPos(
        idTarget_DynamicVehicleAiController *this,
        int testIndex)
{
  float *list; // r8
  int num; // r7
  int result; // r3
  int v5; // r11
  double v6; // fp0
  double v7; // fp12
  int v8; // r9
  double v9; // fp13
  double v10; // fp13
  double v11; // fp13
  double v12; // fp13
  int v13; // r10
  int v14; // ctr
  double v15; // fp13

  list = this->splineDistances.list;
  num = this->distances.num;
  result = -1;
  v5 = 0;
  v6 = 1.0e30;
  v7 = list[testIndex];
  if ( num >= 4 )
  {
    v8 = 0;
    do
    {
      v9 = list[v8];
      if ( v9 > v7 && v9 < v6 )
      {
        v6 = list[v8];
        result = v5;
      }
      v10 = list[v8 + 1];
      if ( v10 > v7 && v10 < v6 )
      {
        v6 = list[v8 + 1];
        result = v5 + 1;
      }
      v11 = list[v8 + 2];
      if ( v11 > v7 && v11 < v6 )
      {
        v6 = list[v8 + 2];
        result = v5 + 2;
      }
      v12 = list[v8 + 3];
      if ( v12 > v7 && v12 < v6 )
      {
        v6 = list[v8 + 3];
        result = v5 + 3;
      }
      v5 += 4;
      v8 += 4;
    }
    while ( v5 < num - 3 );
  }
  if ( v5 < num )
  {
    v13 = v5;
    v14 = num - v5;
    do
    {
      v15 = list[v13];
      if ( v15 > v7 && v15 < v6 )
      {
        v6 = list[v13];
        result = v5;
      }
      ++v5;
      ++v13;
      --v14;
    }
    while ( v14 != 0 );
  }
  return result;
}


// ========================================================================
// ?OnActivate@idTarget_HideShowHands@@UAAXPAVidEntity@@@Z
// EA  : 0x82CCF598
// RVA : 0x00CCF598
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_HideShowHands::OnActivate(idTarget_HideShowHands *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r31
  idPresentable *presentable; // r3
  int v5; // r3
  idPresentable *v6; // r3
  int v7; // r3
  idPresentable *v8; // r3
  const idDeclWeapon *weaponDecl; // r28
  idJobManager *v10; // r3
  idWeapon *JobByDecl; // r3
  idWeapon *v12; // r4
  idPresentable *v13; // r3
  int v14; // r3
  idPresentable *v15; // r3
  int v16; // r3
  idPresentable *v17; // r3
  int v18; // r3
  idPresentable *v19; // r3
  int v20; // r3
  idPresentable *v21; // r3
  int v22; // r3
  idPresentable *v23; // r3
  int v24; // r3

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity != nullptr
    || this->useDebugPlayer && (PlayerFromEntity = idGameLocal::GetDebugPlayer(this: gameLocal)) != nullptr )
  {
    presentable = PlayerFromEntity->presentable;
    v5 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
    if ( v5 != -37616 )
    {
      if ( this->hideHands )
      {
        v6 = PlayerFromEntity->presentable;
        if ( v6 != nullptr )
          v7 = (int)v6->GetPlayerInterface_2(this: v6);
        else
          v7 = 0;
        idHands::Hide(this: (idHands *)(v7 + 37616), hideReason: HAND_HIDE_SPECIAL);
        v8 = PlayerFromEntity->presentable;
        if ( v8 != nullptr )
          v8->GetPlayerInterface_2(this: v8)->hands.shouldDisable = true;
        else
          MEMORY[0x9E9D] = 1;
      }
      else if ( this->weaponDecl != nullptr && PlayerFromEntity->GetInventory_2(this: PlayerFromEntity) != nullptr )
      {
        weaponDecl = this->weaponDecl;
        v10 = (idJobManager *)PlayerFromEntity->GetInventory_2(this: PlayerFromEntity);
        JobByDecl = (idWeapon *)idJobManager::FindJobByDecl(this: v10, jobDecl: (const idDeclJob *)weaponDecl);
        v12 = idWeapon::CastTo(c: JobByDecl);
        if ( v12 != nullptr )
          idPlayer::EquipItem(this: PlayerFromEntity, item: v12);
        else
          idLib::Warning(fmt: "Could not find weapon decl %s in idTarget_HideShowHands", this->weaponDecl->name.str);
        v13 = PlayerFromEntity->presentable;
        if ( v13 != nullptr )
          v14 = (int)v13->GetPlayerInterface_2(this: v13);
        else
          v14 = 0;
        idHands::Show(this: (idHands *)(v14 + 37616), hideReason: HAND_HIDE_SPECIAL);
        v15 = PlayerFromEntity->presentable;
        if ( v15 != nullptr )
          v16 = (int)v15->GetPlayerInterface_2(this: v15);
        else
          v16 = 0;
        idHands::Enable(this: (idHands *)(v16 + 37616));
        v17 = PlayerFromEntity->presentable;
        if ( v17 != nullptr )
        {
          v18 = (int)v17->GetPlayerInterface_2(this: v17);
          idHands::Reset(this: (idHands *)(v18 + 37616), doIntro: true);
        }
        else
        {
          idHands::Reset(this: (idHands *)0x92F0, doIntro: true);
        }
      }
      else
      {
        v19 = PlayerFromEntity->presentable;
        if ( v19 != nullptr )
          v20 = (int)v19->GetPlayerInterface_2(this: v19);
        else
          v20 = 0;
        idHands::Show(this: (idHands *)(v20 + 37616), hideReason: HAND_HIDE_SPECIAL);
        v21 = PlayerFromEntity->presentable;
        if ( v21 != nullptr )
          v22 = (int)v21->GetPlayerInterface_2(this: v21);
        else
          v22 = 0;
        idHands::Enable(this: (idHands *)(v22 + 37616));
        v23 = PlayerFromEntity->presentable;
        if ( v23 != nullptr )
        {
          v24 = (int)v23->GetPlayerInterface_2(this: v23);
          idHands::Reset(this: (idHands *)(v24 + 37616), doIntro: false);
        }
        else
        {
          idHands::Reset(this: (idHands *)0x92F0, doIntro: false);
        }
      }
    }
  }
}


// ========================================================================
// ?OnActivate@idTarget_PlayerCrouch@@UAAXPAVidEntity@@@Z
// EA  : 0x82CCF860
// RVA : 0x00CCF860
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_PlayerCrouch::OnActivate(idTarget_PlayerCrouch *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r30
  idPresentable *presentable; // r3
  int v5; // r3
  idPresentable *v6; // r3
  int v7; // r3

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity == nullptr )
  {
    idLib::Warning(fmt: "could not get player from activator on , idTarget_PlayerCrouch debug player ");
    PlayerFromEntity = idGameLocal::GetDebugPlayer(this: gameLocal);
  }
  presentable = PlayerFromEntity->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = 0;
  idPhysics_Player::SetCrouch(this: (idPhysics_Player *)(v5 + 36264), crouch: this->crouch);
  if ( this->instantCrouchChange )
  {
    v6 = PlayerFromEntity->presentable;
    if ( v6 != nullptr )
      v7 = (int)v6->GetPlayerInterface_2(this: v6);
    else
      v7 = 0;
    *(_BYTE *)(v7 + 45881) = *(unsigned __int8 *)(v7 + 45880) != this->crouch;
  }
}


// ========================================================================
// ?OnActivate@idTarget_PlayerVehicleExit@@UAAXPAVidEntity@@@Z
// EA  : 0x82CCF930
// RVA : 0x00CCF930
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_PlayerVehicleExit::OnActivate(idTarget_PlayerVehicleExit *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r28
  idVehicle *v4; // r3
  idVehicle *v5; // r30
  int i; // r29
  idPlayer *v7; // r31
  idPlayer *OccupantAsEntity; // r3
  idPresentable *presentable; // r3
  idPresentablePlayer *v10; // r3
  idPresentable *v11; // r3
  idPresentablePlayer *v12; // r3

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity == nullptr )
  {
    idLib::Warning(fmt: "could not get player from activator on , idTarget_PlayerVehicleExit! Using DebugPlayer instead. ");
    PlayerFromEntity = idGameLocal::GetDebugPlayer(this: gameLocal);
  }
  v4 = PlayerFromEntity->GetVehicle_2(this: PlayerFromEntity);
  v5 = v4;
  if ( v4 != nullptr )
  {
    if ( this->removeAllOccupants )
    {
      for ( i = idVehicle::GetNumActiveOccupants(this: v4) - 1; i >= 0; --i )
      {
        v7 = nullptr;
        OccupantAsEntity = (idPlayer *)idVehicle::GetOccupantAsEntity(this: v5, index: i);
        if ( OccupantAsEntity != nullptr )
          v7 = idPlayer::CastTo(c: OccupantAsEntity);
        idVehicle::AllowOccupantExitVehicle(this: v5, seat: i, bl: true);
        v5->ExitVehicle(this: v5, a2: i, a3: true, a4: false);
        if ( v7 != nullptr && v7 != PlayerFromEntity )
        {
          presentable = v7->presentable;
          if ( presentable != nullptr )
            v10 = presentable->GetPlayerInterface_2(this: presentable);
          else
            v10 = nullptr;
          idPresentablePlayer::ResetControl(this: v10);
        }
      }
    }
    else
    {
      idVehicle::AllowOccupantExitVehicle(this: v4, seat: 0, bl: true);
      v5->ExitVehicle(this: v5, a2: 0, a3: true, a4: false);
    }
    v11 = PlayerFromEntity->presentable;
    if ( v11 != nullptr )
    {
      v12 = v11->GetPlayerInterface_2(this: v11);
      idPresentablePlayer::ResetControl(this: v12);
    }
    else
    {
      idPresentablePlayer::ResetControl(this: nullptr);
    }
  }
}


// ========================================================================
// ?OnActivate@idTarget_SetWorldSpawnAIUsesCoverFalse@@UAAXPAVidEntity@@@Z
// EA  : 0x82CCFAA0
// RVA : 0x00CCFAA0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_SetWorldSpawnAIUsesCoverFalse::OnActivate(
        idTarget_SetWorldSpawnAIUsesCoverFalse *this,
        idEntity *activator)
{
  idWorldspawn *world; // r10

  if ( gameLocal != nullptr )
  {
    world = gameLocal->world;
    if ( world != nullptr )
      world->aiUsesCover = false;
  }
}


// ========================================================================
// ?Event_ModifyCount@idTarget_Conditional@@AAA?AVeventVoid@@H@Z
// EA  : 0x82CCFAD8
// RVA : 0x00CCFAD8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_Conditional *__fastcall idTarget_Conditional::Event_ModifyCount(
        idTarget_Conditional *this,
        eventVoid *result,
        int value)
{
  int v3; // r11
  unsigned int v5; // r10
  char v6; // r8
  int v7; // r9
  char v8; // r11
  bool v9; // zf
  int v10; // r11

  v3 = *(_DWORD *)&result[816];
  v5 = *(_DWORD *)&result[800];
  v6 = 0;
  v7 = v3 + value;
  *(_DWORD *)&result[816] = v3 + value;
  if ( v5 == 0 )
  {
    if ( v3 == *(_DWORD *)&result[808] )
    {
      v9 = v7 > v3;
      v8 = 1;
      if ( v9 )
        goto LABEL_13;
    }
LABEL_12:
    v8 = 0;
LABEL_13:
    v6 = v8;
    goto LABEL_14;
  }
  if ( v5 == 1 )
  {
    if ( v3 == *(_DWORD *)&result[808] )
    {
      v9 = v7 < v3;
      v8 = 1;
      if ( v9 )
        goto LABEL_13;
    }
    goto LABEL_12;
  }
  if ( v5 < 3 )
  {
    if ( v7 == *(_DWORD *)&result[808] )
    {
      v9 = v7 != v3;
      v8 = 1;
      if ( v9 )
        goto LABEL_13;
    }
    goto LABEL_12;
  }
LABEL_14:
  if ( v6 != 0 && (*(_BYTE *)&result[812] == 0 || *(_BYTE *)&result[813] == 0) )
  {
    v10 = *(_DWORD *)result;
    result[813] = (eventVoid)1;
    (*(void (__fastcall **)(eventVoid *))(v10 + 380))(a1: result);
  }
  return this;
}


// ========================================================================
// ?OnActivate@idTarget_ToggleTraversal@@UAAXPAVidEntity@@@Z
// EA  : 0x82CCFBC8
// RVA : 0x00CCFBC8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ToggleTraversal::OnActivate(idTarget_ToggleTraversal *this, idEntity *activator)
{
  idAAS2 *AAS; // r3
  int num; // r28
  idAAS2 *v5; // r29
  int v6; // r30
  idAAS2_vtbl *v7; // r11
  int v8; // r4

  AAS = idGameLocal::GetAAS(this: gameLocal, idx: this->aasType);
  num = this->targetTraversals.num;
  v5 = AAS;
  if ( num != 0 )
  {
    v6 = num;
    do
    {
      --v6;
      --num;
      v8 = this->targetTraversals.list[v6];
      v7 = v5->__vftable;
      if ( this->enable )
        v7->SetTraversalFlag(this: v5, a2: v8, a3: 1);
      else
        v7->ClearTraversalFlag(this: v5, a2: v8, a3: 1);
    }
    while ( num != 0 );
  }
}


// ========================================================================
// ?Spawn@idTarget_UnlockSecret@@QAAXXZ
// EA  : 0x82CCFC48
// RVA : 0x00CCFC48
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_UnlockSecret::Spawn(idTarget_UnlockSecret *this)
{
  int SecretForEntity; // r3

  SecretForEntity = idDeclSecrets::FindSecretForEntity(name: this->name.data);
  this->id = SecretForEntity;
  if ( SecretForEntity == -1 )
    idLib::Warning(fmt: "Secret '%s' exists in the map but doesn't have a secret declaration", this->name.data);
}


// ========================================================================
// ?Spawn@idTarget_UnlockMap@@QAAXXZ
// EA  : 0x82CCFC98
// RVA : 0x00CCFC98
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_UnlockMap::Spawn(idTarget_UnlockMap *this)
{
  const idChapterVariation *CurrentVariation; // r3
  int id; // r11

  CurrentVariation = idDeclChapter::FindCurrentVariation();
  if ( CurrentVariation != nullptr )
    id = CurrentVariation->id;
  else
    id = -1;
  this->variationId = id;
  if ( id < 0 )
    idLib::Warning(fmt: "idTarget_UnlockMap: Current map and layer combination does not exist in any chapter declaration");
}


// ========================================================================
// ?OnActivate@idTarget_NextMap@@EAAXPAVidEntity@@@Z
// EA  : 0x82CCFCF0
// RVA : 0x00CCFCF0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_NextMap::OnActivate(idTarget_NextMap *this, idPlayer *activator)
{
  idPlayer *v4; // r3
  idPlayer *v5; // r31
  idEventArg *v6; // r3
  idEventArg v7[3]; // [sp+50h] [-40h] BYREF

  v4 = idPlayer::CastTo(c: activator);
  v5 = v4;
  if ( v4 != nullptr )
  {
    if ( this->freeInventory )
      idEventReceiver::PostEventMS(this: v4, ev: &EV_RemoveAllInventoryItems, time: 800);
    v6 = idEventArg::idEventArg(this: v7, data: v5);
    idEventReceiver::PostEventMS(
      this,
      ev: &EV_DoTransition,
      time: *(_DWORD *)&v6->type,
      arg1: (const idEventArg *)LODWORD(v6->value.v[1]));
    idPlayer::PrepareForNextMap(this: v5, fadeColor: &idColor::colorBlack, fadeTo: &idColor::colorBlack, to: 750.0);
  }
  else if ( activator != nullptr )
  {
    idLib::Warning(fmt: "idTarget_NextMap: activated by non-player '%s'", activator->name.data);
  }
  else
  {
    idLib::Warning(fmt: "idTarget_NextMap: activated by non-player '%s'", "NULL");
  }
}


// ========================================================================
// ?OnActivate@idTarget_SetHudElement@@UAAXPAVidEntity@@@Z
// EA  : 0x82CCFDD0
// RVA : 0x00CCFDD0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_SetHudElement::OnActivate(idTarget_SetHudElement *this, idPlayer *activator)
{
  idPlayer *v4; // r3
  bool show; // r31

  v4 = idPlayer::CastTo(c: activator);
  if ( v4 != nullptr )
  {
    if ( this->element == ELEMENT_BOTTOMBAR )
    {
      show = this->show;
      *(_BYTE *)(idPlayer::GetPlayerHud(this: v4) + 268) = show;
    }
  }
  else if ( activator != nullptr )
  {
    idLib::Warning(fmt: "idTarget_SetHudElement: activated by non-player '%s'", activator->name.data);
  }
  else
  {
    idLib::Warning(fmt: "idTarget_SetHudElement: activated by non-player '%s'", "NULL");
  }
}


// ========================================================================
// ??0idTarget_Count@@QAA@XZ
// EA  : 0x82CCFE60
// RVA : 0x00CCFE60
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_Count *__fastcall idTarget_Count::idTarget_Count(idTarget_Count *this)
{
  idEntity::idEntity(this);
  this->delay = 0.0;
  this->__vftable = (idTarget_Count_vtbl *)&idTarget_Count::`vftable';
  this->count = 2;
  this->call.allocedAndFlag = 20;
  this->call.data = this->call.baseBuffer;
  this->call.len = 0;
  this->call.baseBuffer[0] = 0;
  this->waitInterval = 0.0;
  this->repeat = false;
  this->gameMS = false;
  this->num = 0;
  this->activateTime = -1;
  this->nextPermittedActivateTime = 0;
  this->storedActivator.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// ??0idTarget_Count_Random@@QAA@XZ
// EA  : 0x82CCFF58
// RVA : 0x00CCFF58
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_Count_Random *__fastcall idTarget_Count_Random::idTarget_Count_Random(idTarget_Count_Random *this)
{
  idEntity::idEntity(this);
  this->delay = 0.0;
  this->__vftable = (idTarget_Count_Random_vtbl *)&idTarget_Count_Random::`vftable';
  this->count = 2;
  this->call.data = this->call.baseBuffer;
  this->call.allocedAndFlag = 20;
  this->call.len = 0;
  this->call.baseBuffer[0] = 0;
  this->incrementalDelayMin = 0.0;
  this->activateTime = -1;
  this->incrementalDelayMax = 0.0;
  this->repeat = false;
  this->numToActivate = 1;
  this->incrementalActivate = false;
  this->num = 0;
  this->storedActivator.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// ??0idTarget_Timer@@QAA@XZ
// EA  : 0x82CD00D0
// RVA : 0x00CD00D0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_Timer *__fastcall idTarget_Timer::idTarget_Timer(idTarget_Timer *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_Timer_vtbl *)&idTarget_Timer::`vftable';
  this->onName.data = this->onName.baseBuffer;
  this->onName.len = 0;
  this->onName.allocedAndFlag = 20;
  this->onName.baseBuffer[0] = 0;
  this->offName.allocedAndFlag = 20;
  this->offName.data = this->offName.baseBuffer;
  this->offName.len = 0;
  this->offName.baseBuffer[0] = 0;
  this->savedActivator.spawnId.value = 0x1FFF;
  this->random = 0.0;
  this->wait = 0.0;
  this->on = false;
  this->delay = 0.0;
  return this;
}


// ========================================================================
// ?Event_TimerEvent@idTarget_Timer@@AAA?AVeventVoid@@XZ
// EA  : 0x82CD0278
// RVA : 0x00CD0278
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_Timer *__fastcall idTarget_Timer::Event_TimerEvent(idTarget_Timer *this, idEventReceiver *result)
{
  int listenerList; // r10
  idEntity *v5; // r3
  idEntity *v6; // r4
  __int64 v7; // r6
  unsigned int v8; // r10

  listenerList = (int)result[73].listenerList;
  if ( gameLocal->spawnIds.ptr[listenerList & 0x1FFF] == listenerList >> 13
    && (v5 = gameLocal->entities.ptr[listenerList & 0x1FFF]) != nullptr )
  {
    v6 = idEntity::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  result->__vftable[15].InternalRespondsTo(this: result, a2: (const idEventDef *)v6);
  if ( *(float *)&result[67].__vftable >= 0.0 )
  {
    HIDWORD(v7) = clientGame->random.seed;
    v8 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v8 + 1013904223;
    LODWORD(v7) = ((v8 + 1013904223) >> 10) & 0x7FFF;
    idEventReceiver::PostEventSec(
      this: result,
      ev: &EV_TimerEvent,
      time: (float)((float)((float)((float)((float)v7 * (float)0.000061037019) - (float)1.0)
                    * *(float *)&result[66].listeningToList)
            + *(float *)&result[67].__vftable));
  }
  return this;
}


// ========================================================================
// ??0idTarget_JobTimerStart@@QAA@XZ
// EA  : 0x82CD0390
// RVA : 0x00CD0390
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_JobTimerStart *__fastcall idTarget_JobTimerStart::idTarget_JobTimerStart(idTarget_JobTimerStart *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_JobTimerStart_vtbl *)&idTarget_JobTimerStart::`vftable';
  this->phaseName.index = -1;
  this->parTime = 2.5;
  this->cashPerScore = 5;
  this->parPrize = 1;
  this->actuallyTime = true;
  this->continueTarget.spawnId.value = 0x1FFF;
  this->numPhases = 0;
  return this;
}


// ========================================================================
// ?OnActivate@idTarget_LayerStateChange@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD0408
// RVA : 0x00CD0408
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_LayerStateChange::OnActivate(idTarget_LayerStateChange *this, idPlayer *activator)
{
  idPlayer *DebugPlayer; // r3
  idGameLayerManager *p_gameLayerManager; // r30

  DebugPlayer = idPlayer::CastTo(c: activator);
  if ( DebugPlayer == nullptr )
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  p_gameLayerManager = &DebugPlayer->gameLayerManager;
  idGameLayerManager::AddActiveLayers(this: &DebugPlayer->gameLayerManager, layerlist: &this->activateLayers);
  idGameLayerManager::ActivateDeactiveLayers(this: p_gameLayerManager, layerlist: &this->activateDeactiveLayers);
  idGameLayerManager::RemoveLayers(this: p_gameLayerManager, layerlist: &this->removeLayersFromPlayer);
  idGameLayerManager::DeactiveateActiveLayers(this: p_gameLayerManager, layerlist: &this->deactivateActiveLayers);
  idGameLayerManager::AddDeactiveLayers(this: p_gameLayerManager, layerlist: &this->addDeactiveLayersToPlayer);
  idGameLayerManager::RemoveLayersFromGame(this: p_gameLayerManager, layerlist: &this->removeLayersFromGame);
  idGameLayerManager::RemoveLayersMarkActiveNextMapLoad(
    this: p_gameLayerManager,
    layerlist: &this->removeLayersMarkActiveNextMapLoad);
  idGameLayerManager::RemoveLayersMarkDeactiveNextMapLoad(
    this: p_gameLayerManager,
    layerlist: &this->removeLayersMarkDeactiveNextMapLoad);
  idGameLayerManager::Think(this: p_gameLayerManager);
  if ( this->saveCheckpoint )
  {
    this->checkpointEnt->playerSpawnSpot.spawnId.value = this->playerSpawnSpot.spawnId.value;
    this->checkpointEnt->delay = 0.0;
    this->checkpointEnt->persistToStorage = this->persistToStorage;
    idEntity::Activate(this: this->checkpointEnt, activator);
  }
}


// ========================================================================
// ?Event_DoTransition@idTarget_LevelTransition@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82CD0558
// RVA : 0x00CD0558
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_LevelTransition *__fastcall idTarget_LevelTransition::Event_DoTransition(
        idTarget_LevelTransition *this,
        eventVoid *result,
        idPlayer *activator)
{
  idPlayer *v5; // r3
  idPlayer *v6; // r29
  __int64 v7; // r10
  int v8; // r8
  void (__fastcall **v9)(idPhysics_StaticMulti *__hidden, int); // r7
  size_t v10; // r29
  size_t v11; // r29
  __int64 v12; // r8
  va *v13; // r3
  __int64 v14; // r6
  __int64 v15; // r10
  __int64 v16; // r8
  va *v17; // r3
  int v19; // [sp+8h] [-10E8h]
  int v20; // [sp+8h] [-10E8h]
  int v21; // [sp+Ch] [-10E4h]
  int v22; // [sp+Ch] [-10E4h]
  int v23; // [sp+10h] [-10E0h]
  int v24; // [sp+10h] [-10E0h]
  int v25; // [sp+14h] [-10DCh]
  int v26; // [sp+14h] [-10DCh]
  int v27; // [sp+18h] [-10D8h]
  int v28; // [sp+18h] [-10D8h]
  int v29; // [sp+1Ch] [-10D4h]
  int v30; // [sp+1Ch] [-10D4h]
  idStr v31; // [sp+50h] [-10A0h] BYREF
  idStr v32; // [sp+70h] [-1080h] BYREF
  int v33; // [sp+90h] [-1060h]
  idStr v34; // [sp+A0h] [-1050h] BYREF
  va v35; // [sp+C0h] [-1030h] BYREF

  v5 = idPlayer::CastTo(c: activator);
  v6 = v5;
  if ( v5 != nullptr )
  {
    idPlayer::SetForceInhibitControl(this: v5, inhibit: false);
    LODWORD(v7) = v31.baseBuffer;
    v31.len = 0;
    v31.allocedAndFlag = 20;
    v31.data = v31.baseBuffer;
    v31.baseBuffer[0] = 0;
    HIDWORD(v7) = v32.baseBuffer;
    v32.allocedAndFlag = 20;
    v32.data = v32.baseBuffer;
    v32.len = 0;
    v32.baseBuffer[0] = 0;
    idGameLayerManager::GetLayerStrings(
      this: &v6->gameLayerManager,
      activeLayerString: &v31,
      deactiveLayerString: &v32,
      propagateTheNextMapLayers: 1,
      a5: v9,
      layerState: v8,
      a7: v7);
    v10 = *(_DWORD *)&result[900];
    if ( v10 != 0 || *(_DWORD *)&result[932] != 0 )
    {
      v33 = *(_DWORD *)&result[900];
      idStr::EnsureAlloced(this: &v31, amount: v10 + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: v31.data, Src: *(const void **)&result[904], Size: v10);
      v31.data[v10] = 0;
      v31.len = v10;
      v11 = *(_DWORD *)&result[932];
      idStr::EnsureAlloced(this: &v32, amount: v11 + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: v32.data, Src: *(const void **)&result[936], Size: v11);
      v32.data[v11] = 0;
      v32.len = v11;
    }
    LODWORD(v12) = *(_DWORD *)&result[868];
    HIDWORD(v12) = *(_DWORD *)&result[836];
    v13 = va::va(
            this: &v35,
            fmt: "nextmap %d %s \"%s\" \"%s\" \"%s\" \"%s\"\n",
            a3: *(unsigned int *)&result[804],
            a4: v12,
            a5: __SPAIR64__((unsigned int)v31.data, (unsigned int)v32.data),
            a6: v19,
            a7: v21,
            a8: v23,
            a9: v25,
            a10: v27,
            a11: v29);
    cmdSystem->AppendCommandText(this: cmdSystem, a2: v13->buffer);
    if ( playtest_MenuStartsRenderDemo.valueInteger != 0 && playtest_log_Any.valueInteger != 0 )
    {
      cmdSystem->AppendCommandText(this: cmdSystem, a2: "demostop\n");
      cmdSystem->AppendCommandText(this: cmdSystem, a2: "wait 1\n");
      idCVar::SetInteger(
        this: &playtest_RenderDemoCounter,
        newValue: playtest_RenderDemoCounter.valueInteger + 1,
        force: true);
      HIDWORD(v14) = playtest_RenderDemoCounter.valueInteger;
      v17 = va::va(
              this: &v35,
              fmt: "demorecord_playtest %d\n",
              a3: v14,
              a4: v16,
              a5: v15,
              a6: v20,
              a7: v22,
              a8: v24,
              a9: v26,
              a10: v28,
              a11: v30);
      idStr::idStr(this: &v34, text: v17);
      cmdSystem->AppendCommandText(this: cmdSystem, a2: v34.data);
      idStr::FreeData(this: &v34);
    }
    idStr::FreeData(this: &v32);
    idStr::FreeData(this: &v31);
  }
  else
  {
    idLib::Warning(fmt: "idTarget_LevelTransition got event do transition without a valid entity");
  }
  return this;
}


// ========================================================================
// __unwind$504855
// EA  : 0x82CD0784
// RVA : 0x00CD0784
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_504855()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4336 + 80));
}


// ========================================================================
// __unwind$504856
// EA  : 0x82CD07AC
// RVA : 0x00CD07AC
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_504856()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4336 + 112));
}


// ========================================================================
// __unwind$504857
// EA  : 0x82CD07D4
// RVA : 0x00CD07D4
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_504857()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4336 + 160));
}


// ========================================================================
// ?OnActivate@idTarget_PlayerViewEffect@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD0800
// RVA : 0x00CD0800
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_PlayerViewEffect::OnActivate(idTarget_PlayerViewEffect *this, idEntity *activator)
{
  __int64 v4; // r10
  int v5; // r8
  int v6; // r7
  int v7; // r6
  int v8; // r5
  idPlayer *PlayerFromEntity; // r3

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity != nullptr
    || this->canUseDefaultPlayer && (PlayerFromEntity = idGameLocal::GetDebugPlayer(this: gameLocal)) != nullptr )
  {
    idTarget_PlayerViewEffect::ActivateOnPlayer(this, player: PlayerFromEntity, a3: v8, a4: v7, a5: v6, a6: v5, a7: v4);
  }
  else if ( activator != nullptr )
  {
    idLib::Warning(fmt: "idTarget_PlayerViewEffect: activated by non-player '%s'", activator->name.data);
  }
  else
  {
    idLib::Warning(fmt: "idTarget_PlayerViewEffect: activated by non-player '%s'", "NULL");
  }
}


// ========================================================================
// ?OnActivate@idTarget_InventoryCheck@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD08A0
// RVA : 0x00CD08A0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_InventoryCheck::OnActivate(idTarget_InventoryCheck *this, idEntity *activator)
{
  idInventoryCollection *v4; // r23
  char v5; // r26
  char v6; // r25
  int v7; // r27
  int v8; // r28
  idTarget_InventoryCheck::requiredInventoryItem_t *v9; // r30
  idStr *v10; // r3
  idStr *p_dontHaveItemMessage; // r4
  char v12; // r10
  int v13; // r27
  int v14; // r28
  idTarget_InventoryCheck::requiredInventoryItem_t *v15; // r30
  idPresentable *presentable; // r4
  int len; // r10
  idStr *p_haveItemsMessage; // r11
  idStr *p_dontHaveItemsMessage; // r29
  size_t v20; // r30
  idStr v21; // [sp+60h] [-C0h] BYREF
  idStr v22; // [sp+80h] [-A0h] BYREF
  idStr v23[4]; // [sp+A0h] [-80h] BYREF

  if ( !this->useOnce || !this->used )
  {
    if ( activator == nullptr )
    {
      idLib::Warning(fmt: "idTarget_InventoryCheck: activated by NULL");
      return;
    }
    v4 = activator->GetInventory_2(this: activator);
    if ( v4 != nullptr )
    {
      v23[0].len = 0;
      v23[0].baseBuffer[0] = 0;
      v23[0].allocedAndFlag = 20;
      v23[0].data = v23[0].baseBuffer;
      v22.len = 0;
      v22.baseBuffer[0] = 0;
      v22.allocedAndFlag = 20;
      v22.data = v22.baseBuffer;
      v21.len = 0;
      v21.baseBuffer[0] = 0;
      v21.allocedAndFlag = 20;
      v21.data = v21.baseBuffer;
      v5 = 0;
      v6 = 1;
      v7 = 0;
      if ( this->requiredItemList.num > 0 )
      {
        v8 = 0;
        do
        {
          v9 = &this->requiredItemList.list[v8];
          if ( idInventoryCollection::FindTotalInventoryItemCount(this: v4, decl: v9->requiredItem) < v9->requiredCount )
          {
            v6 = 0;
            if ( v22.len == 0 )
            {
              v10 = &v22;
              p_dontHaveItemMessage = &this->requiredItemList.list[v8].dontHaveItemMessage;
              goto LABEL_13;
            }
          }
          else
          {
            v5 = 1;
            if ( v23[0].len == 0 )
            {
              v10 = v23;
              p_dontHaveItemMessage = &this->requiredItemList.list[v8].haveItemMessage;
LABEL_13:
              idStr::operator=(this: v10, text: p_dontHaveItemMessage);
            }
          }
          ++v7;
          ++v8;
        }
        while ( v7 < this->requiredItemList.num );
      }
      v12 = 0;
      if ( !this->anyItemActivates )
        goto LABEL_18;
      if ( v5 != 0 )
      {
LABEL_19:
        v12 = 1;
        goto LABEL_20;
      }
      if ( !this->anyItemActivates )
      {
LABEL_18:
        if ( v6 != 0 )
          goto LABEL_19;
      }
LABEL_20:
      if ( v12 != 0 )
      {
        this->ActivateTargets(this, a2: activator);
        v13 = 0;
        if ( this->requiredItemList.num > 0 )
        {
          v14 = 0;
          do
          {
            v15 = &this->requiredItemList.list[v14];
            if ( v15->deleteOnUse )
            {
              presentable = activator->presentable;
              if ( presentable == nullptr )
              {
                idEntity::InitPresentableInternal(this: activator);
                presentable = activator->presentable;
              }
              idInventoryCollection::DeleteInventoryItem(
                this: v4,
                owner: presentable,
                decl: v15->requiredItem,
                count: v15->requiredCount);
            }
            ++v13;
            ++v14;
          }
          while ( v13 < this->requiredItemList.num );
        }
        len = this->haveItemsMessage.len;
        p_haveItemsMessage = &this->haveItemsMessage;
        this->used = true;
        p_dontHaveItemsMessage = v23;
        if ( len != 0 )
          p_dontHaveItemsMessage = p_haveItemsMessage;
      }
      else
      {
        p_dontHaveItemsMessage = &this->dontHaveItemsMessage;
        if ( p_dontHaveItemsMessage->len == 0 )
          p_dontHaveItemsMessage = &v22;
      }
      v20 = p_dontHaveItemsMessage->len;
      idStr::EnsureAlloced(this: &v21, amount: p_dontHaveItemsMessage->len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: v21.data, Src: p_dontHaveItemsMessage->data, Size: v20);
      v21.data[v20] = 0;
      v21.len = v20;
      idStr::FreeData(this: &v21);
      idStr::FreeData(this: &v22);
      idStr::FreeData(this: v23);
    }
  }
}


// ========================================================================
// __unwind$505043
// EA  : 0x82CD0B48
// RVA : 0x00CD0B48
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_505043()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 160));
}


// ========================================================================
// __unwind$505044
// EA  : 0x82CD0B70
// RVA : 0x00CD0B70
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_505044()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 128));
}


// ========================================================================
// __unwind$505045
// EA  : 0x82CD0B98
// RVA : 0x00CD0B98
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_505045()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 96));
}


// ========================================================================
// ?Event_GetLastSpawned@idTarget_Spawn@@AAA?AVeventEntity@@XZ
// EA  : 0x82CD0BC0
// RVA : 0x00CD0BC0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_Spawn *__fastcall idTarget_Spawn::Event_GetLastSpawned(idTarget_Spawn *this, eventEntity *result)
{
  idEntity *value; // r10
  idEntity *v4; // r3
  idEntity *v5; // r4

  value = result[237].value;
  if ( gameLocal->spawnIds.ptr[(unsigned __int16)value & 0x1FFF] == (int)value >> 13
    && (v4 = gameLocal->entities.ptr[(unsigned __int16)value & 0x1FFF]) != nullptr )
  {
    v5 = idEntity::CastTo(c: v4);
  }
  else
  {
    v5 = nullptr;
  }
  eventEntity::eventEntity((eventEntity *)this, e: v5);
  return this;
}


// ========================================================================
// ?OnActivate@idTarget_GroupMessage@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD0C40
// RVA : 0x00CD0C40
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_GroupMessage::OnActivate(idTarget_GroupMessage *this, idEntity *activator)
{
  int value; // r11
  idEncounterGroupManager *p_encounterGroupManager; // r28
  idEntity *v6; // r3
  int v7; // r9
  idEntity *v8; // r3
  idEntity *v9; // r31
  idHandle<short,enum invalidEncounterGroup_t,-1> v10[24]; // [sp+50h] [-30h] BYREF

  value = this->entity.spawnId.value;
  p_encounterGroupManager = &gameLocal->encounterGroupManager;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v6) != nullptr )
  {
    v7 = this->entity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] == v7 >> 13 && (v8 = gameLocal->entities.ptr[v7 & 0x1FFF]) != nullptr )
      v9 = idEntity::CastTo(c: v8);
    else
      v9 = nullptr;
  }
  else
  {
    v9 = activator;
  }
  idEncounterGroupManager::FindGroup(
    this: (idEncounterGroupManager *)v10,
    result: p_encounterGroupManager,
    groupName: this->groupName.data);
  if ( (unsigned __int16)v10[0].value == 0xFFFF )
    idLib::Warning(fmt: "Unknown encounter group '%s'", this->groupName.data);
  if ( (unsigned __int8)idEncounterGroupManager::SendGroupMessage(
                          this: p_encounterGroupManager,
                          handle: v10,
                          msg: this->message,
                          ent: v9) == 0 )
    idLib::Warning(
      fmt: "Could not send message '%s' to group '%s'",
      aiGroupMessageNames[this->message],
      this->groupName.data);
}


// ========================================================================
// ?ActivateAcceptTarget@idTarget_ShowGui@@QAA_NXZ
// EA  : 0x82CD0D70
// RVA : 0x00CD0D70
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

int __fastcall idTarget_ShowGui::ActivateAcceptTarget(idTarget_ShowGui *this)
{
  int value; // r10
  idEntity *v3; // r3
  idEntity *v4; // r31
  idEventArg *v5; // r3
  idEventArg v7; // [sp+50h] [-30h] BYREF

  value = this->acceptTarget.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v3 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v3 != nullptr )
    v4 = idEntity::CastTo(c: v3);
  else
    v4 = nullptr;
  v5 = idEventArg::idEventArg(this: &v7, data: this);
  idEventReceiver::PostEventMS(
    this: v4,
    ev: &EV_Activate,
    time: *(_DWORD *)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]));
  return 1;
}


// ========================================================================
// ?ActivateRejectTarget@idTarget_ShowGui@@QAA_NXZ
// EA  : 0x82CD0E40
// RVA : 0x00CD0E40
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

int __fastcall idTarget_ShowGui::ActivateRejectTarget(idTarget_ShowGui *this)
{
  int value; // r10
  idEntity *v3; // r3
  idEntity *v4; // r31
  idEventArg *v5; // r3
  idEventArg v7; // [sp+50h] [-30h] BYREF

  value = this->rejectTarget.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v3 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v3 != nullptr )
    v4 = idEntity::CastTo(c: v3);
  else
    v4 = nullptr;
  v5 = idEventArg::idEventArg(this: &v7, data: this);
  idEventReceiver::PostEventMS(
    this: v4,
    ev: &EV_Activate,
    time: *(_DWORD *)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]));
  return 1;
}


// ========================================================================
// ?OnMakeActivatable@idTarget_DummyFire@@MAAX_N@Z
// EA  : 0x82CD0F10
// RVA : 0x00CD0F10
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_DummyFire::OnMakeActivatable(idTarget_DummyFire *this, const bool activatable)
{
  int numShots; // r11
  double burstDuration; // fp13
  idGameTimeManager *p_gameTimeManager; // r3
  int GameMs; // r3
  int v7; // r11

  if ( activatable )
  {
    idEntity::BecomeActive(this, flags: 1);
  }
  else
  {
    numShots = this->numShots;
    if ( numShots <= 0 )
      numShots = 10;
    this->currentShotsLeft = numShots;
    burstDuration = this->burstDuration;
    p_gameTimeManager = &clientGame->gameTimeManager;
    if ( burstDuration > 0.0 )
    {
      GameMs = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
      v7 = (int)(float)((float)1000.0 * this->burstDuration);
    }
    else
    {
      GameMs = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
      v7 = (int)1000.0;
    }
    this->nextBurstChange = v7 + GameMs;
    this->bIsFiring = true;
    idTarget_DummyFire::SetBulletsFly(this, _bBulletsFly: false);
    idEntity::BecomeInactive(this, flags: 1);
  }
}


// ========================================================================
// ?SetIsFiring@idTarget_DummyFire@@AAAX_N@Z
// EA  : 0x82CD1008
// RVA : 0x00CD1008
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_DummyFire::SetIsFiring(idTarget_DummyFire *this, bool _bFiring)
{
  BOOL bSlave; // r11
  int v5; // r31
  int num; // r28
  int value; // r9
  idTarget_DummyFire *v8; // r3
  idTarget_DummyFire *v9; // r3
  idTarget_DummyFire *v10; // r3

  bSlave = this->bSlave;
  this->bIsFiring = _bFiring;
  if ( !bSlave && this->slaves.num > 0 )
  {
    v5 = 0;
    num = this->slaves.num;
    do
    {
      value = this->slaves.list[v5].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v8 = (idTarget_DummyFire *)gameLocal->entities.ptr[value & 0x1FFF];
        if ( v8 != nullptr )
        {
          v9 = idTarget_DummyFire::CastTo(c: v8);
          if ( v9 != nullptr )
          {
            v10 = idTarget_DummyFire::CastTo(c: v9);
            if ( v10 != nullptr )
              v10->bIsFiring = _bFiring;
          }
        }
      }
      --num;
      ++v5;
    }
    while ( num != 0 );
  }
}


// ========================================================================
// ?GetNextMapAndLayers@idTarget_NextMap@@AAAXPAVidStr@@0_N@Z
// EA  : 0x82CD1128
// RVA : 0x00CD1128
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_NextMap::GetNextMapAndLayers(
        idTarget_NextMap *this,
        idStr *map,
        idStr *layers,
        bool setProgress)
{
  idTarget_NextMap::changeMode_t mode; // r11
  int len; // r30
  idResource *v10; // r28
  int v11; // r30
  idChapterPart *list; // r28
  idPlayerProfileGame *v13; // r3
  idPlayerProfileGame *v14; // r29
  const idChapterVariation *VariationById; // r3
  const idChapterVariation *v16; // r3
  int v17; // r30
  int v18; // r29
  int v19; // [sp+50h] [-60h] BYREF
  idResource_vtbl *v20; // [sp+54h] [-5Ch] BYREF
  idStr *p_mapName; // [sp+58h] [-58h] BYREF

  mode = this->mode;
  if ( mode == MODE_MANUAL )
  {
    len = this->mapName.len;
    p_mapName = &this->mapName;
    idStr::EnsureAlloced(this: map, amount: len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: map->data, Src: this->mapName.data, Size: len);
    map->data[len] = 0;
    map->len = len;
    idStr::operator=(this: layers, text: &byte_8200D768);
  }
  else if ( mode != MODE_AUTO )
  {
    idLib::Warning(fmt: "idTarget_NextMap '%s' has invalid mode", this->name.data);
  }
  else
  {
    if ( (unsigned __int8)idDeclChapter::FindCurrentEntry(
                            chapterIndex: (int *)&p_mapName,
                            variationIndex: (int *)&v20,
                            partIndex: &v19) == 0 )
    {
      idLib::Warning(fmt: "idTarget_NextMap '%s' couldn't find the current map", this->name.data);
      return;
    }
    v10 = idResourceList::Index(this: &idDeclChapter::resourceList, index: (int)p_mapName);
    v11 = (int)v10[3].nextOnHashChain + 28 * (_DWORD)v20;
    if ( v19 + 1 >= *(_DWORD *)(v11 + 12) )
    {
      if ( this->extraLayers.num != 0 )
        idLib::Warning(
          fmt: "idTarget_NextMap '%s' switching chapters and passing extra layers is forbidden",
          this->name.data);
      v13 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
      v14 = v13;
      if ( v13 != nullptr && setProgress )
      {
        idPlayerProfileGame::SetProgress(this: v13, variationId: *(_DWORD *)v11);
        idPlayerProfileGame::SetCompleted(this: v14, completedID: *(_DWORD *)v11);
      }
      if ( v10[2].trackedMemory == 1 )
      {
        list = (idChapterPart *)(20 * v19 + *(_DWORD *)(v11 + 8));
        if ( v14 != nullptr )
        {
          idPlayerProfileGame::GetSideMissionData(
            this: v14,
            spawnSpot: &this->spawnSpot,
            variationIndex: (int *)&v20,
            partIndex: &v19,
            layers);
          if ( (_S19_1 & 1) != 0 )
          {
            VariationById = variation;
          }
          else
          {
            _S19_1 |= 1u;
            VariationById = idDeclChapter::FindVariationById(id: v20);
            variation = VariationById;
          }
          if ( VariationById != nullptr )
          {
            if ( v19 >= VariationById->parts.num )
            {
              idLib::Warning(fmt: "idTarget_NextMap '%s' partIndex larger sideParts list", this->name.data);
              return;
            }
            idStr::operator=(this: map, text: VariationById->parts.list[v19].map.str);
          }
        }
        else
        {
          idLib::Warning(
            fmt: "idTarget_NextMap '%s' profile is null return map cant be found falling back to same map",
            this->name.data);
        }
      }
      else
      {
        v16 = idDeclChapter::FindVariationById(id: *(idResource_vtbl **)(v11 + 24));
        if ( v16 == nullptr )
        {
          idLib::Warning(
            fmt: "idTarget_NextMap '%s' couldn't find variation %d",
            this->name.data,
            *(_DWORD *)(v11 + 24));
          return;
        }
        if ( v16->parts.num == 0 )
        {
          idLib::Warning(
            fmt: "idTarget_NextMap '%s' next variation %d doesn't have any parts",
            this->name.data,
            *(_DWORD *)(v11 + 24));
          return;
        }
        list = v16->parts.list;
      }
    }
    else
    {
      list = (idChapterPart *)(20 * (v19 + 1) + *(_DWORD *)(v11 + 8));
    }
    if ( idStr::Cmp(s1: map->data, s2: &byte_8200D768) == 0 )
    {
      idStr::operator=(this: map, text: list->map.str);
      idChapterPart::GetLayersParsed(this: list, retLayers: layers);
    }
  }
  if ( this->extraLayers.num != 0 )
  {
    if ( layers->len != 0 )
      idStr::Append(this: layers, text: ",");
    idStr::Append(this: layers, text: this->extraLayers.list);
    v17 = 1;
    if ( this->extraLayers.num > 1 )
    {
      v18 = 1;
      do
      {
        idStr::Append(this: layers, text: ",");
        idStr::Append(this: layers, text: &this->extraLayers.list[v18]);
        ++v17;
        ++v18;
      }
      while ( v17 < this->extraLayers.num );
    }
  }
}


// ========================================================================
// __unwind$506031
// EA  : 0x82CD1488
// RVA : 0x00CD1488
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_506031()
{
  _S19_1 &= ~1u;
}


// ========================================================================
// ?Event_DoTransition@idTarget_NextMap@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82CD14B0
// RVA : 0x00CD14B0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_NextMap *__fastcall idTarget_NextMap::Event_DoTransition(
        idTarget_NextMap *this,
        idTarget_NextMap *result,
        idPlayer *activator)
{
  idPlayer *v5; // r3
  __int64 v6; // r10
  __int64 v7; // r8
  va *v8; // r3
  int v10; // [sp+8h] [-10A8h]
  int v11; // [sp+Ch] [-10A4h]
  int v12; // [sp+10h] [-10A0h]
  int v13; // [sp+14h] [-109Ch]
  int v14; // [sp+18h] [-1098h]
  int v15; // [sp+1Ch] [-1094h]
  idStr v16; // [sp+50h] [-1060h] BYREF
  idStr v17; // [sp+70h] [-1040h] BYREF
  va v18; // [sp+90h] [-1020h] BYREF

  v5 = idPlayer::CastTo(c: activator);
  if ( v5 != nullptr )
  {
    idPlayer::SetForceInhibitControl(this: v5, inhibit: false);
    v16.len = 0;
    v16.allocedAndFlag = 20;
    v16.data = v16.baseBuffer;
    v16.baseBuffer[0] = 0;
    v17.allocedAndFlag = 20;
    v17.data = v17.baseBuffer;
    v17.len = 0;
    v17.baseBuffer[0] = 0;
    idTarget_NextMap::GetNextMapAndLayers(this: result, map: &v16, layers: &v17, setProgress: true);
    HIDWORD(v6) = v17.data;
    LODWORD(v7) = &byte_8200D768;
    LODWORD(v6) = &byte_8200D768;
    HIDWORD(v7) = result->spawnSpot.data;
    v8 = va::va(
           this: &v18,
           fmt: "nextmap %d %s \"%s\" \"%s\" \"%s\" \"%s\"\n",
           a3: (unsigned int)v16.data,
           a4: v7,
           a5: v6,
           a6: v10,
           a7: v11,
           a8: v12,
           a9: v13,
           a10: v14,
           a11: v15);
    cmdSystem->AppendCommandText(this: cmdSystem, a2: v8->buffer);
    idStr::FreeData(this: &v17);
    idStr::FreeData(this: &v16);
  }
  else
  {
    idLib::Warning(fmt: "idTarget_NextMap got event do transition without a valid entity");
  }
  return this;
}


// ========================================================================
// __unwind$506239
// EA  : 0x82CD159C
// RVA : 0x00CD159C
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_506239()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4272 + 80));
}


// ========================================================================
// __unwind$506240
// EA  : 0x82CD15C4
// RVA : 0x00CD15C4
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_506240()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4272 + 112));
}


// ========================================================================
// ?Spawn@idTarget_SetHelp@@QAAXXZ
// EA  : 0x82CD15F0
// RVA : 0x00CD15F0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_SetHelp::Spawn(idTarget_SetHelp *this)
{
  idTarget_SetHelp::button_t button; // r11
  const char *v3; // r4
  const idMaterial *v4; // r3
  const char *v5; // r4

  button = this->button;
  if ( button > HELPBUTTON_NONE && button < HELPBUTTON_MAX )
  {
    v3 = idTarget_SetHelp::images_360[button];
    if ( v3 != nullptr )
      v4 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                 this: &idMaterial::resourceList,
                                 name: v3,
                                 makeDefault: true);
    else
      v4 = nullptr;
    this->buttonImage = v4;
    if ( idLib::production == PROD_BUILDING || com_production.valueInteger != 0 )
    {
      v5 = idTarget_SetHelp::images_ps3[this->button];
      if ( v5 != nullptr )
        idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name: v5, makeDefault: true);
    }
  }
}


// ========================================================================
// ?OnActivate@idTarget_SetHelp@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD16B8
// RVA : 0x00CD16B8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_SetHelp::OnActivate(idTarget_SetHelp *this, idPlayer *activator)
{
  idPlayer *v4; // r3
  idPresentable *presentable; // r3
  const idMaterial *icon; // r30
  const idMaterial *buttonImage; // r31
  idPresentablePlayer *v8; // r3
  int v9; // [sp+50h] [-30h]

  v4 = idPlayer::CastTo(c: activator);
  if ( v4 != nullptr )
  {
    presentable = v4->presentable;
    icon = this->icon;
    HIBYTE(v9) = this->show;
    buttonImage = this->buttonImage;
    if ( presentable != nullptr )
      v8 = presentable->GetPlayerInterface_2(this: presentable);
    else
      v8 = nullptr;
    *(_DWORD *)&v8->playerHud.helpInfo.show = v9;
    v8->playerHud.helpInfo.icon = icon;
    v8->playerHud.helpInfo.buttonImage = buttonImage;
  }
  else if ( activator != nullptr )
  {
    idLib::Warning(fmt: "idTarget_SetHelp: activated by non-player '%s'", activator->name.data);
  }
  else
  {
    idLib::Warning(fmt: "idTarget_SetHelp: activated by non-player '%s'", "NULL");
  }
}


// ========================================================================
// ?Think@idTarget_Count@@UAAXXZ
// EA  : 0x82CD1858
// RVA : 0x00CD1858
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Count::Think(idTarget_Count *this)
{
  int value; // r10
  idEntity *v3; // r3
  idEntity *v4; // r30
  char v5; // [sp+50h] [-20h] BYREF

  if ( this->activateTime >= 0
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->activateTime )
  {
    value = this->storedActivator.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v4 = idEntity::CastTo(c: v3);
    }
    else
    {
      v4 = nullptr;
    }
    this->storedActivator.spawnId.value = 0x1FFF;
    this->activateTime = -1;
    idEntity::BecomeInactive(this, flags: 1);
    idTarget_Count::Event_TargetAction(this: (idTarget_Count *)&v5, result: this, activator: v4);
  }
}


// ========================================================================
// ?OnActivate@idTarget_Count@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD1930
// RVA : 0x00CD1930
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Count::OnActivate(idTarget_Count *this, idEntity *activator)
{
  int count; // r10
  int v5; // r11
  int v6; // r29
  int v7; // r3
  __int64 v8; // r11
  int v9; // r30
  char *v10; // r29
  int v11; // r3
  int GameMs; // r29
  char *v13; // r28
  int v14; // r3
  char *data; // r31
  int v16; // r3
  char v17; // [sp+50h] [-50h] BYREF
  idTypesafeNumber<int,enum gameTimeUnique_t> v18; // [sp+58h] [-48h] BYREF
  int v19; // [sp+5Ch] [-44h]

  if ( this->count < 0 )
  {
    if ( g_debugTriggers.valueInteger != 0 )
    {
      data = this->name.data;
      v16 = idAccolade::Count(this: &clientGame->gameTimeManager);
      idLib::Printf(fmt: "%d: '%s' did not fire because count is < 0\n", v16, data);
    }
  }
  else if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < this->nextPermittedActivateTime )
  {
    if ( g_debugTriggers.valueInteger != 0 )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v13 = this->name.data;
      v14 = idAccolade::Count(this: &clientGame->gameTimeManager);
      idLib::Printf(
        fmt: "%d: '%s' did not fire because nextPermittedActivateTime = %d, game time = %d\n",
        v14,
        v13,
        this->nextPermittedActivateTime,
        GameMs);
    }
  }
  else
  {
    count = this->count;
    v5 = this->num + 1;
    this->num = v5;
    if ( v5 < count )
    {
      if ( g_debugTriggers.valueInteger != 0 )
      {
        v10 = this->name.data;
        v11 = idAccolade::Count(this: &clientGame->gameTimeManager);
        idLib::Printf(fmt: "%d: '%s' did not fire because num (%d) < count (%d)\n", v11, v10, this->num, this->count);
      }
    }
    else
    {
      if ( this->repeat )
        this->num = 0;
      else
        this->count = -1;
      if ( this->delay > 0.0 )
      {
        if ( this->activateTime < 0 )
        {
          if ( this->gameMS )
            v6 = 1000;
          else
            v6 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
          v7 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          LODWORD(v8) = v6;
          v19 = (int)(float)((float)v8 * this->delay);
          this->activateTime = v19 + v7;
          if ( activator != nullptr )
            this->storedActivator.spawnId.value = (gameLocal->spawnIds.ptr[activator->entityNumber] << 13)
                                                | activator->entityNumber;
          else
            this->storedActivator.spawnId.value = 0x1FFF;
          idEntity::BecomeActive(this, flags: 1);
        }
        else
        {
          idLib::Warning(
            fmt: "Target '%s' was re-triggered before previous trigger could activate targets. Re-trigger is ignored.",
            this->name.data);
        }
      }
      else
      {
        idTarget_Count::Event_TargetAction(this: (idTarget_Count *)&v17, result: this, activator);
      }
      if ( this->waitInterval > 0.0 )
      {
        v9 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        this->nextPermittedActivateTime = SecondsToTicks(result: &v18, seconds: this->waitInterval)->value + v9;
      }
    }
  }
}


// ========================================================================
// ?Think@idTarget_Count_Random@@UAAXXZ
// EA  : 0x82CD1BE8
// RVA : 0x00CD1BE8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Count_Random::Think(idTarget_Count_Random *this)
{
  int value; // r10
  idEntity *v3; // r3
  idEntity *v4; // r30
  char v5; // [sp+50h] [-20h] BYREF

  if ( this->activateTime >= 0
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->activateTime )
  {
    value = this->storedActivator.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v4 = idEntity::CastTo(c: v3);
    }
    else
    {
      v4 = nullptr;
    }
    this->storedActivator.spawnId.value = 0x1FFF;
    this->activateTime = -1;
    idEntity::BecomeInactive(this, flags: 1);
    idTarget_Count_Random::Event_TargetAction(this: (idTarget_Count_Random *)&v5, result: this, activator: v4);
  }
}


// ========================================================================
// ?OnActivate@idTarget_Count_Random@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD1CC0
// RVA : 0x00CD1CC0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Count_Random::OnActivate(idTarget_Count_Random *this, idEntity *activator)
{
  int count; // r10
  int v5; // r11
  int GameMs; // r3
  char v7; // [sp+50h] [-30h] BYREF
  int v9; // [sp+5Ch] [-24h]

  count = this->count;
  if ( count >= 0 )
  {
    v5 = this->num + 1;
    this->num = v5;
    if ( v5 >= count )
    {
      if ( this->repeat )
        this->num = 0;
      else
        this->count = -1;
      if ( this->delay > 0.0 )
      {
        if ( this->activateTime < 0 )
        {
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v9 = (int)(float)(this->delay * (float)-1000.0);
          this->activateTime = GameMs - v9;
          if ( activator != nullptr )
            this->storedActivator.spawnId.value = (gameLocal->spawnIds.ptr[activator->entityNumber] << 13)
                                                | activator->entityNumber;
          else
            this->storedActivator.spawnId.value = 0x1FFF;
          idEntity::BecomeActive(this, flags: 1);
        }
        else
        {
          idLib::Warning(
            fmt: "Target '%s' was re-triggered before previous trigger could activate targets. Re-trigger is ignored.",
            this->name.data);
        }
      }
      else
      {
        idTarget_Count_Random::Event_TargetAction(this: (idTarget_Count_Random *)&v7, result: this, activator);
      }
    }
  }
}


// ========================================================================
// ?ActivateTargets@idTarget_Count_Random@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD1E08
// RVA : 0x00CD1E08
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Count_Random::ActivateTargets(idTarget_Count_Random *this, idEntity *activator)
{
  int v2; // r11
  encounterGroupRole_t *list; // r21
  int v6; // r19
  int v7; // r14
  int v8; // r24
  signed int v9; // r11
  idClientGame *v10; // r10
  int v11; // r27
  idClientGame *v12; // r9
  int v13; // r3
  unsigned int v14; // r11
  char v15; // r26
  int v16; // r30
  int value; // r8
  idEntity *v18; // r3
  idEntity *v19; // r29
  int v20; // r11
  encounterGroupRole_t *v21; // r10
  idEventArg *v22; // r3
  __int64 v23; // r4
  double incrementalDelayMin; // fp13
  double v25; // fp11
  unsigned int v26; // r6
  int v27; // [sp+50h] [-F0h] BYREF
  int v28; // [sp+54h] [-ECh]
  int num; // [sp+58h] [-E8h]
  __int64 v30; // [sp+60h] [-E0h]
  idList<enum encounterGroupRole_t,5> v31; // [sp+70h] [-D0h] BYREF
  idEventArg v32; // [sp+80h] [-C0h] BYREF

  num = this->targets.num;
  v2 = num;
  if ( num > 0 )
  {
    num = this->numToActivate;
    if ( num <= 0 || (v27 = v2, num >= v2) )
      num = v2;
    memset(&v31, 0, 14);
    *(_WORD *)&v31.memTag = 1280;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v31);
    list = v31.list;
    v6 = 0;
    v7 = 0;
    if ( num <= 0 )
    {
LABEL_35:
      if ( (v31.listStatic == 0 || v31.listStatic == 2) && list != nullptr )
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
    else
    {
      v8 = v31.num;
      while ( 1 )
      {
        v9 = this->targets.num;
        v10 = clientGame;
        if ( v9 != 0 )
        {
          v12 = clientGame;
          __twllei(v9, 0);
          v12->random.seed = 1664525 * v12->random.seed + 1013904223;
          v13 = (v10->random.seed >> 10) & 0x7FFF;
          v11 = v13 % v9;
          __twlgei(v9 & ~(__ROL4__(v13, 1) - 1), 0xFFFFFFFF);
        }
        else
        {
          v11 = 0;
        }
        v14 = this->targets.num;
        v15 = 0;
        v16 = ((__PAIR64__(v14 >> 31, v11 + 1) - __PAIR64__((unsigned int)(v11 + 1) >> 31, v14)) >> 32) & (v11 + 1);
        v27 = v16;
        if ( v16 != v11 )
        {
          while ( 1 )
          {
            v27 = v14;
            if ( v16 < (int)v14
              && (value = this->targets.list[v16].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13) )
            {
              v18 = gameLocal->entities.ptr[this->targets.list[v16].spawnId.value & 0x1FFF];
              if ( v18 != nullptr )
                v19 = idEntity::CastTo(c: v18);
              else
                v19 = nullptr;
            }
            else
            {
              v19 = nullptr;
            }
            if ( v19 != nullptr )
            {
              v20 = 0;
              if ( v8 <= 0 )
                goto LABEL_25;
              v21 = list;
              while ( *v21 != v16 )
              {
                ++v20;
                ++v21;
                if ( v20 >= v8 )
                  goto LABEL_25;
              }
              if ( v20 < 0 || &list[v20] == nullptr )
              {
LABEL_25:
                if ( (*(_BYTE *)&v19->flags & 8) != 0 )
                {
                  v27 = v16;
                  idList<idAnimWebBlendTree *,5>::Append(this: &v31, obj: (encounterGroupRole_t *)&v27);
                  if ( this->incrementalActivate )
                  {
                    v22 = idEventArg::idEventArg(this: &v32, data: activator);
                    HIDWORD(v23) = idEventReceiver::PostEventMS(
                                     this: v19,
                                     ev: &EV_Activate,
                                     time: *(_DWORD *)&v22->type,
                                     arg1: (const idEventArg *)LODWORD(v22->value.v[1]));
                    incrementalDelayMin = this->incrementalDelayMin;
                    v25 = (float)(this->incrementalDelayMax - this->incrementalDelayMin);
                    v26 = 1664525 * clientGame->random.seed + 1013904223;
                    clientGame->random.seed = v26;
                    LODWORD(v23) = (v26 >> 10) & 0x7FFF;
                    v30 = v23;
                    v28 = (int)(float)((float)((float)((float)((float)v23 * (float)v25) * (float)0.000030518509)
                                             + (float)incrementalDelayMin)
                                     * (float)-1000.0);
                    v6 -= v28;
                  }
                  else
                  {
                    idEntity::Activate(this: v19, activator);
                  }
                  v8 = v31.num;
                  v15 = 1;
                  list = v31.list;
                  break;
                }
              }
            }
            v27 = this->targets.num;
            v14 = v27;
            v16 = ((__PAIR64__(v14 >> 31, v16 + 1) - __PAIR64__((unsigned int)(v16 + 1) >> 31, v14)) >> 32) & (v16 + 1);
            if ( v16 == v11 )
            {
              v27 = v16;
              break;
            }
          }
        }
        if ( v15 == 0 && v16 == v11 )
          break;
        if ( ++v7 >= num )
          goto LABEL_35;
      }
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v31);
    }
  }
}


// ========================================================================
// $M508758_0
// EA  : 0x82CD2170
// RVA : 0x00CD2170
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _M508758_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 320 + 112));
}


// ========================================================================
// ?Spawn@idTarget_ModifyTraversalClass@@QAAXXZ
// EA  : 0x82CD2198
// RVA : 0x00CD2198
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ModifyTraversalClass::Spawn(idTarget_ModifyTraversalClass *this)
{
  int v2; // r30
  int v3; // r29
  int value; // r9
  idEntity *v5; // r3

  v2 = 0;
  if ( this->targets.num > 0 )
  {
    v3 = 0;
    do
    {
      value = this->targets.list[v3].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
        || (v5 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
        || idEntity::CastTo(c: v5) == nullptr )
      {
        idLib::Warning(fmt: "%s target #%d does not exist", this->name.data, v2);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_ModifyTraversalClass@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD2248
// RVA : 0x00CD2248
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ModifyTraversalClass::OnActivate(idTarget_ModifyTraversalClass *this, idEntity *activator)
{
  int v3; // r29
  int v4; // r28
  int value; // r9
  idEntity *v6; // r3
  idAI2 *v7; // r31
  idAI2 *v8; // r3
  idAI2 *v9; // r6
  idLinkList<idEntity> *next; // r11
  idAI2 *i; // r31
  idAI2 *v12; // r3
  idAI2 *v13; // r6
  idLinkList<idEntity> *v14; // r11

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
        v7 = (idAI2 *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      if ( v7 != nullptr )
      {
        v8 = idAI2::CastTo(c: v7);
        if ( v8 != nullptr )
        {
          idTarget_ModifyTraversalClass::ModifyAIEditable(this, aiEditable: &v8->aiEditable);
          idAI2::UpdateTravelFlags(this: v9);
        }
        else
        {
          idLib::Warning(fmt: "%s target %s is not an AI", this->name.data, v7->name.data);
        }
      }
      else
      {
        idLib::Warning(fmt: "%s target #%d does not exist", this->name.data, v3);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
  if ( this->modifyActiveAI )
  {
    next = gameLocal->activeEntities.next;
    if ( next != nullptr && next != gameLocal->activeEntities.head )
    {
      for ( i = (idAI2 *)next->owner; i != nullptr; i = (idAI2 *)v14->owner )
      {
        v12 = idAI2::CastTo(c: i);
        if ( v12 != nullptr )
        {
          idTarget_ModifyTraversalClass::ModifyAIEditable(this, aiEditable: &v12->aiEditable);
          idAI2::UpdateTravelFlags(this: v13);
        }
        v14 = i->activeNode.next;
        if ( v14 == nullptr )
          break;
        if ( v14 == i->activeNode.head )
          break;
      }
    }
  }
}


// ========================================================================
// ?OnActivate@idTarget_Timer@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD23D0
// RVA : 0x00CD23D0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Timer::OnActivate(idTarget_Timer *this, idEntity *activator)
{
  if ( this->on )
  {
    if ( this->offName.len == 0
      || activator != nullptr && idStr::Icmp(s1: this->offName.data, s2: activator->name.data) == 0 )
    {
      this->on = false;
      idEventReceiver::CancelEvents(this, ev: &EV_TimerEvent);
    }
  }
  else if ( this->onName.len == 0
         || activator != nullptr && idStr::Icmp(s1: this->onName.data, s2: activator->name.data) == 0 )
  {
    this->on = true;
    if ( activator != nullptr )
      this->savedActivator.spawnId.value = (gameLocal->spawnIds.ptr[activator->entityNumber] << 13)
                                         | activator->entityNumber;
    else
      this->savedActivator.spawnId.value = 0x1FFF;
    idEventReceiver::PostEventSec(this, ev: &EV_TimerEvent, time: this->delay);
  }
}


// ========================================================================
// ?OnActivate@idTarget_Break@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD24D0
// RVA : 0x00CD24D0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Break::OnActivate(idTarget_Break *this, idEntity *activator)
{
  int v3; // r29
  int v4; // r31
  int value; // r9
  idEntity *v6; // r3
  idEntity *v7; // r3

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
      if ( v7 != nullptr )
        idEventReceiver::PostEventMS(this: v7, ev: &EV_BreakIt, time: 0);
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
  idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
}


// ========================================================================
// ?OnActivate@idTarget_Remove@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD2598
// RVA : 0x00CD2598
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Remove::OnActivate(idTarget_Remove *this, idEntity *activator)
{
  int v3; // r27
  int v4; // r28
  int value; // r9
  idEntity *v6; // r3
  idProp_Moveable *v7; // r31
  idProp_Moveable *v8; // r3
  void *v9; // r11
  bool v10; // cr58
  idDoor_Blocker *v11; // r3
  const char *v12; // r31
  idPlayer *DebugPlayer; // r3

  v3 = 0;
  if ( this->targets.num > 0 )
  {
    v4 = 0;
    while ( 1 )
    {
      value = this->targets.list[v4].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v7 = (idProp_Moveable *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      if ( v7 == nullptr )
        goto LABEL_15;
      idEventReceiver::PostEventMS(this: v7, ev: &EV_Remove, time: 0);
      if ( this->markUniquePropsRemoved )
      {
        v8 = idProp_Moveable::CastTo(c: v7);
        v9 = v8;
        if ( v8 != nullptr )
          break;
        v11 = idDoor_Blocker::CastTo(c: (idDoor_Blocker *)v7);
        v9 = v11;
        if ( v11 != nullptr )
        {
          v10 = !v11->uniquelyRemoveable;
LABEL_13:
          if ( !v10 )
          {
            v12 = *((const char **)v9 + 4);
            DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
            idGameLayerManager::AddItemMemory(this: &DebugPlayer->gameLayerManager, itemName: v12);
          }
        }
      }
LABEL_15:
      ++v3;
      ++v4;
      if ( v3 >= this->targets.num )
        goto LABEL_16;
    }
    v10 = (*((_BYTE *)v8 + 5296) & 0x80) == 0;
    goto LABEL_13;
  }
LABEL_16:
  idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
}


// ========================================================================
// ?OnActivate@idTarget_Show@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD26D0
// RVA : 0x00CD26D0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Show::OnActivate(idTarget_Show *this, idEntity *activator)
{
  int v3; // r29
  int v4; // r31
  int value; // r9
  idEntity *v6; // r3
  idEntity *v7; // r3

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
      if ( v7 != nullptr )
        v7->Show(this: v7);
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
  if ( !this->reuseable )
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
}


// ========================================================================
// ?OnActivate@idTarget_Hide@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD27A0
// RVA : 0x00CD27A0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Hide::OnActivate(idTarget_Hide *this, idEntity *activator)
{
  int v3; // r29
  int v4; // r31
  int value; // r9
  idEntity *v6; // r3
  idEntity *v7; // r3

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
      if ( v7 != nullptr )
        v7->Hide_2(this: v7);
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
  if ( !this->reuseable )
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
}


// ========================================================================
// ?OnActivate@idTarget_ChangeColor@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD2870
// RVA : 0x00CD2870
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ChangeColor::OnActivate(idTarget_ChangeColor *this, idEntity *activator)
{
  int v3; // r29
  int v4; // r30
  int value; // r9
  idEntity *v6; // r3
  idEntity *v7; // r3

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
      if ( v7 != nullptr )
        v7->SetColor_2(this: v7, a2: &this->color);
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_Use@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD2928
// RVA : 0x00CD2928
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Use::OnActivate(idTarget_Use *this, idEntity *activator)
{
  int value; // r9
  idEntity *v5; // r3
  idEntity *v6; // r3

  if ( this->targets.num > 0
    && (value = this->targets.list->spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = idEntity::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  if ( v6 != nullptr )
    v6->Use(this: v6, a2: activator, a3: this->usableState);
}


// ========================================================================
// ?OnActivate@idTarget_Job@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD29D8
// RVA : 0x00CD29D8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Job::OnActivate(idTarget_Job *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r30
  idPlayerHud *PlayerHud; // r3
  idTarget_Job::targetJob_t action; // r11
  const idDeclCameraTrigger *v7; // r10
  const idDeclJob *jobDecl; // r11
  int num; // r4
  int cameraIndex; // r3
  const idDeclJobNote *jobNoteOverride; // r4
  idPlayerHud *v12; // r3
  idList<idVehicleState *,5> *JobByDecl; // r3

  if ( resourceManager->GetBuildPlatforms(this: resourceManager) == 0 )
  {
    if ( this->jobDecl != nullptr )
    {
      PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
      if ( PlayerFromEntity != nullptr || (PlayerFromEntity = idGameLocal::GetDebugPlayer(this: gameLocal)) != nullptr )
      {
        if ( this->treatAsDebug || this->clearJobStateFirst )
        {
          PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this: PlayerFromEntity);
          idPlayerHud::SetIgnoreJobUpdates(this: PlayerHud, ignore: true);
          PlayerFromEntity->jobManager.inDebug = true;
        }
        if ( this->clearJobStateFirst )
        {
          idJobManager::ClearAllJobStatus(this: &PlayerFromEntity->jobManager);
          idJobManager::ClearPlayerInteractionMemories(this: &PlayerFromEntity->jobManager);
          idJobManager::ClearGameStateInts(this: &PlayerFromEntity->jobManager);
          idJobManager::ClearJobNotes(this: &PlayerFromEntity->jobManager);
        }
        if ( this->HACK_nolayerchanges )
          PlayerFromEntity->jobManager.hackIgnoreLayerChanges = true;
        if ( this->HACK_noitemrewards )
          PlayerFromEntity->jobManager.hackNoItemRewards = true;
        action = this->action;
        if ( action != TARGETJOB_ACCEPTED )
        {
          switch ( action )
          {
            case TARGETJOB_READYTOTURNIN:
              v7 = nullptr;
              if ( this->activateCinematicCam )
              {
                jobDecl = this->jobDecl;
                num = jobDecl->cameras.num;
                if ( num > 0 )
                {
                  cameraIndex = jobDecl->cameraIndex;
                  if ( cameraIndex == -1 )
                    cameraIndex = idRandom2::RandomInt(this: &clientGame->random, max: num);
                  v7 = this->jobDecl->cameras.list[cameraIndex];
                }
              }
              idJobManager::TriggerJobReadyToTurnInFromTarget(
                this: &PlayerFromEntity->jobManager,
                jobDecl: this->jobDecl,
                completeTree: this->completeTree,
                giveJobIfNeeded: this->giveJob,
                hideIfGiven: this->markGivenJobUnknown,
                force: false,
                activator,
                cameraTriggerDecl: v7);
              break;
            case TARGETJOB_COMPLETED:
              idJobManager::CompleteJob(
                this: &PlayerFromEntity->jobManager,
                jobDecl: this->jobDecl,
                completeTree: this->completeTree,
                giveJob: this->giveJob,
                force: false);
              break;
            case TARGETJOB_FAILED:
              idJobManager::FailJob(this: &PlayerFromEntity->jobManager, jobDecl: this->jobDecl);
              break;
            default:
              break;
          }
        }
        else
        {
          idJobManager::AcceptJob(
            this: &PlayerFromEntity->jobManager,
            jobDecl: this->jobDecl,
            completeTree: this->completeTree,
            force: false);
        }
        jobNoteOverride = this->jobNoteOverride;
        if ( jobNoteOverride != nullptr )
          idJobManager::AddJobNote(
            this: &PlayerFromEntity->jobManager,
            jobNote: jobNoteOverride,
            force: false,
            updateHUD: true,
            checkForActiveJob: false);
        if ( this->treatAsDebug || this->clearJobStateFirst )
        {
          PlayerFromEntity->jobManager.inDebug = false;
          v12 = (idPlayerHud *)idPlayer::GetPlayerHud(this: PlayerFromEntity);
          idPlayerHud::SetIgnoreJobUpdates(this: v12, ignore: false);
        }
        if ( this->HACK_noitemrewards )
          PlayerFromEntity->jobManager.hackNoItemRewards = false;
        if ( this->HACK_nolayerchanges )
          PlayerFromEntity->jobManager.hackIgnoreLayerChanges = false;
        if ( this->clearJobNotesForThisJob )
        {
          JobByDecl = (idList<idVehicleState *,5> *)idJobManager::FindJobByDecl(
                                                      this: &PlayerFromEntity->jobManager,
                                                      jobDecl: this->jobDecl);
          if ( JobByDecl != nullptr )
            idList<idThread *,58>::Clear(this: JobByDecl + 2);
        }
        this->ActivateTargets(this, a2: activator);
      }
      else
      {
        idLib::Warning(fmt: "idTarget_Job could not activate.  Player not found.");
      }
    }
    else
    {
      idLib::Warning(fmt: "target_job has no jobDecl specified!");
    }
  }
}


// ========================================================================
// ?HandleJob@idTarget_JobTriggered@@QAA_NPBVidJob@@PAVidPlayer@@_N2@Z
// EA  : 0x82CD2C80
// RVA : 0x00CD2C80
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

int __fastcall idTarget_JobTriggered::HandleJob(
        idTarget_JobTriggered *this,
        const idJob *job,
        idPlayer *player,
        bool mapLoad,
        bool debug)
{
  int value; // r11
  idEntityPtr<idProp_JobPosting> *p_jobBoardHack; // r3
  idProp_JobPosting *v11; // r3
  idTarget_JobTriggered::jobTriggeredTime_t triggerTime; // r11
  idTarget_JobTriggered::jobTriggeredType_t triggerType; // r11

  if ( debug && this->ignoreDebug )
    return 0;
  value = this->jobBoardHack.spawnId.value;
  p_jobBoardHack = &this->jobBoardHack;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    if ( !mapLoad )
    {
      v11 = idEntityPtr<idProp_JobPosting>::operator->(this: p_jobBoardHack);
      idProp_JobPosting::MarkToCheckPlayer(this: v11);
    }
    if ( job == nullptr )
      return 0;
  }
  else if ( job == nullptr )
  {
    idLib::Warning(fmt: "NULL job in idTarget_JobTriggered");
    return 0;
  }
  triggerTime = this->triggerTime;
  if ( triggerTime == JOBTRIGGEREDTIME_IMMEDIATE && mapLoad )
    return 0;
  if ( triggerTime == JOBTRIGGEREDTIME_MAPLOAD && !mapLoad || this->jobDecl != job->decl )
    return 0;
  triggerType = this->triggerType;
  if ( (unsigned int)triggerType > JOBTRIGGEREDTYPE_NOTEQUAL )
    goto LABEL_26;
  switch ( triggerType )
  {
    case JOBTRIGGEREDTYPE_GREATER_OR_EQUAL:
      if ( job->status < this->jobStatus )
        return 0;
      goto LABEL_26;
    case JOBTRIGGEREDTYPE_LESS:
      if ( job->status >= this->jobStatus )
        return 0;
      goto LABEL_26;
    case JOBTRIGGEREDTYPE_EQUAL:
      if ( job->status != this->jobStatus )
        return 0;
      goto LABEL_26;
    default:
      break;
  }
  if ( job->status == this->jobStatus )
    return 0;
LABEL_26:
  this->ActivateTargets(this, a2: player);
  if ( this->removeOnTriggered )
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
  return 1;
}


// ========================================================================
// ?Think@idTarget_FirstThinkActivate@@UAAXXZ
// EA  : 0x82CD2E30
// RVA : 0x00CD2E30
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_FirstThinkActivate::Think(idTarget_FirstThinkActivate *this)
{
  int v2; // r27
  int v3; // r28
  idGameLocal *v4; // r10
  int value; // r9
  idEntity *v6; // r3
  idEntity *v7; // r3
  idEventReceiver *v8; // r31
  idPlayer *DebugPlayer; // r3
  idEventArg *v10; // r3
  idEventArg v11[4]; // [sp+50h] [-50h] BYREF

  if ( !this->thought )
  {
    v2 = 0;
    if ( this->targets.num > 0 )
    {
      v3 = 0;
      v4 = gameLocal;
      do
      {
        if ( v2 < this->targets.num
          && (value = this->targets.list[v3].spawnId.value, v4->spawnIds.ptr[value & 0x1FFF] == value >> 13)
          && (v6 = v4->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v7 = idEntity::CastTo(c: v6);
          v4 = gameLocal;
          v8 = v7;
        }
        else
        {
          v8 = nullptr;
        }
        if ( v8 != nullptr )
        {
          DebugPlayer = idGameLocal::GetDebugPlayer(this: v4);
          v10 = idEventArg::idEventArg(this: v11, data: DebugPlayer);
          idEventReceiver::PostEventMS(
            this: v8,
            ev: &EV_Activate,
            time: *(_DWORD *)&v10->type,
            arg1: (const idEventArg *)LODWORD(v10->value.v[1]));
          v4 = gameLocal;
        }
        ++v2;
        ++v3;
      }
      while ( v2 < this->targets.num );
    }
  }
  this->thought = true;
  idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
}


// ========================================================================
// ?OnActivate@idTarget_LayerCheckpointModifier@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD2F48
// RVA : 0x00CD2F48
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_LayerCheckpointModifier::OnActivate(
        idTarget_LayerCheckpointModifier *this,
        idEntity *activator)
{
  int value; // r10
  idTarget_LayerStateChange *v4; // r3
  idTarget_LayerStateChange *v5; // r3
  bool saveCheckpoint; // r29
  int v7; // r9
  idTarget_LayerStateChange *v8; // r3
  idTarget_LayerStateChange *v9; // r3
  int v10; // r29
  int v11; // r9
  idTarget_LayerStateChange *v12; // r3
  idTarget_LayerStateChange *v13; // r3
  bool persistToStorage; // r31
  bool v15; // r31

  value = this->targetLayerStateChange.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v4 = (idTarget_LayerStateChange *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v4 != nullptr )
      v5 = idTarget_LayerStateChange::CastTo(c: v4);
    else
      v5 = nullptr;
    saveCheckpoint = this->saveCheckpoint;
    idTarget_LayerStateChange::CastTo(c: v5)->saveCheckpoint = saveCheckpoint;
    v7 = this->targetLayerStateChange.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] == v7 >> 13
      && (v8 = (idTarget_LayerStateChange *)gameLocal->entities.ptr[v7 & 0x1FFF]) != nullptr )
    {
      v9 = idTarget_LayerStateChange::CastTo(c: v8);
    }
    else
    {
      v9 = nullptr;
    }
    v10 = this->playerSpawnSpot.spawnId.value;
    idTarget_LayerStateChange::CastTo(c: v9)->playerSpawnSpot.spawnId.value = v10;
    v11 = this->targetLayerStateChange.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v11 & 0x1FFF] == v11 >> 13
      && (v12 = (idTarget_LayerStateChange *)gameLocal->entities.ptr[v11 & 0x1FFF]) != nullptr )
    {
      v13 = idTarget_LayerStateChange::CastTo(c: v12);
      persistToStorage = this->persistToStorage;
      idTarget_LayerStateChange::CastTo(c: v13)->persistToStorage = persistToStorage;
    }
    else
    {
      v15 = this->persistToStorage;
      idTarget_LayerStateChange::CastTo(c: nullptr)->persistToStorage = v15;
    }
  }
  else
  {
    idLib::Warning(fmt: "'%s' has no valid target for modification.", this->name.data);
  }
}


// ========================================================================
// ??0idTarget_PlayerCheckpoint@@QAA@XZ
// EA  : 0x82CD3090
// RVA : 0x00CD3090
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_PlayerCheckpoint *__fastcall idTarget_PlayerCheckpoint::idTarget_PlayerCheckpoint(
        idTarget_PlayerCheckpoint *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_PlayerCheckpoint_vtbl *)&idTarget_PlayerCheckpoint::`vftable';
  this->playerSpawnSpot.spawnId.value = 0x1FFF;
  this->persistToStorage = true;
  this->delay = 0.0;
  return this;
}


// ========================================================================
// ?Event_DoCheckpoint@idTarget_PlayerCheckpoint@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82CD30E8
// RVA : 0x00CD30E8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_PlayerCheckpoint *__fastcall idTarget_PlayerCheckpoint::Event_DoCheckpoint(
        idTarget_PlayerCheckpoint *this,
        eventVoid *result,
        idEntity *activator)
{
  idGameLocal *v4; // r11
  idPlayerStart *v6; // r3
  idPlayerStart *v7; // r3
  idPlayerStart *v8; // r10

  v4 = gameLocal;
  if ( gameLocal->spawnIds.ptr[*(_DWORD *)&result[800] & 0x1FFF] == *(int *)&result[800] >> 13 )
  {
    v6 = (idPlayerStart *)gameLocal->entities.ptr[*(_DWORD *)&result[800] & 0x1FFF];
    if ( v6 != nullptr )
    {
      v7 = idPlayerStart::CastTo(c: v6);
      v4 = gameLocal;
      v8 = v7;
    }
    else
    {
      v8 = nullptr;
    }
    idGameLocal::SetSpawnSpotOverride(this: v4, spawnSpot: v8->name.data);
    v4 = gameLocal;
  }
  v4->SaveGame(this: v4, a2: "AUTOSAVE", a3: *(_BYTE *)&result[804], a4: false);
  return this;
}


// ========================================================================
// ??0idTarget_SetSpawnSpot@@QAA@XZ
// EA  : 0x82CD31A0
// RVA : 0x00CD31A0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_SetSpawnSpot *__fastcall idTarget_SetSpawnSpot::idTarget_SetSpawnSpot(idTarget_SetSpawnSpot *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_SetSpawnSpot_vtbl *)&idTarget_SetSpawnSpot::`vftable';
  this->playerSpawnSpot.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// ?OnActivate@idTarget_SetSpawnSpot@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD31E8
// RVA : 0x00CD31E8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_SetSpawnSpot::OnActivate(idTarget_SetSpawnSpot *this, idPlayer *activator)
{
  idGameLocal *v3; // r11
  idPlayerStart *v4; // r3
  idPlayerStart *v5; // r3
  idPlayerStart *v6; // r10

  if ( idPlayer::CastTo(c: activator) != nullptr )
  {
    v3 = gameLocal;
    if ( gameLocal->spawnIds.ptr[this->playerSpawnSpot.spawnId.value & 0x1FFF] == this->playerSpawnSpot.spawnId.value >> 13 )
    {
      v4 = (idPlayerStart *)gameLocal->entities.ptr[this->playerSpawnSpot.spawnId.value & 0x1FFF];
      if ( v4 != nullptr )
      {
        v5 = idPlayerStart::CastTo(c: v4);
        v3 = gameLocal;
        v6 = v5;
      }
      else
      {
        v6 = nullptr;
      }
      idGameLocal::SetSpawnSpotOverride(this: v3, spawnSpot: v6->name.data);
    }
  }
  else
  {
    idLib::Warning(fmt: "[%s] No valid activation entity, a player must activate.", "idTarget_SetSpawnSpot::OnActivate");
  }
}


// ========================================================================
// ??0idTarget_GiveItems@@QAA@XZ
// EA  : 0x82CD32C0
// RVA : 0x00CD32C0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_GiveItems *__fastcall idTarget_GiveItems::idTarget_GiveItems(idTarget_GiveItems *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_GiveItems_vtbl *)&idTarget_GiveItems::`vftable';
  this->itemList.list = nullptr;
  this->itemList.granularity = 0;
  this->itemList.memTag = 5;
  this->itemList.listStatic = 0;
  this->itemList.size = 0;
  this->itemList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->itemList);
  this->addUpToCount = false;
  return this;
}


// ========================================================================
// __unwind$510357
// EA  : 0x82CD3320
// RVA : 0x00CD3320
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_510357()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?OnActivate@idTarget_Path@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD3348
// RVA : 0x00CD3348
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Path::OnActivate(idTarget_Path *this, idEntity *activator)
{
  int v3; // r28
  int v4; // r29
  int value; // r9
  idEntity *v6; // r3
  idAI2 *v7; // r3
  idAI2 *v8; // r31
  int v9; // r9
  idInfoPath *v10; // r3
  idInfoPath *v11; // r5
  char v12; // [sp+50h] [-40h] BYREF

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
        v7 = (idAI2 *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      v8 = idAI2::CastTo(c: v7);
      if ( v8 != nullptr )
      {
        v9 = this->newPath.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13
          && (v10 = (idInfoPath *)gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr )
        {
          v11 = idInfoPath::CastTo(c: v10);
        }
        else
        {
          v11 = nullptr;
        }
        idAI2::Event_Path(this: (idAI2 *)&v12, result: (eventVoid *)v8, newPath: v11);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_MoveToScenePoint@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD3440
// RVA : 0x00CD3440
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_MoveToScenePoint::OnActivate(idTarget_MoveToScenePoint *this, idEntity *activator)
{
  int v3; // r28
  int v4; // r29
  int value; // r9
  idEntity *v6; // r3
  idAI2 *v7; // r3
  idAI2 *v8; // r30
  int v9; // r9
  idScenePoint *v10; // r3
  idScenePoint *v11; // r5
  char v12; // [sp+50h] [-40h] BYREF

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
        v7 = (idAI2 *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      v8 = idAI2::CastTo(c: v7);
      if ( v8 != nullptr )
      {
        v9 = this->scenePoint.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13
          && (v10 = (idScenePoint *)gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr )
        {
          v11 = idScenePoint::CastTo(c: v10);
        }
        else
        {
          v11 = nullptr;
        }
        idAI2::Event_MoveToScenepoint(this: (idAI2 *)&v12, result: v8, scenePoint: v11, mtspFlags: this->mtspFlags);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_SetOverrideScenePoint@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD3540
// RVA : 0x00CD3540
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_SetOverrideScenePoint::OnActivate(idTarget_SetOverrideScenePoint *this, idEntity *activator)
{
  int v3; // r22
  int v4; // r23
  int value; // r9
  idEntity *v6; // r3
  idAI2 *v7; // r3
  idAI2 *v8; // r3
  idAI2 *v9; // r28
  idScenePoint *curScenePoint; // r31
  int v11; // r10
  idScenePoint *v12; // r3
  idScenePoint *v13; // r3
  int GameMs; // r3
  int v15; // r9
  idScenePoint *v16; // r3
  idScenePoint *v17; // r4
  int v18; // r9

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
        v7 = (idAI2 *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      v8 = idAI2::CastTo(c: v7);
      v9 = v8;
      if ( v8 == nullptr )
        goto LABEL_21;
      curScenePoint = v8->aiVolatile.memory.curScenePoint;
      if ( curScenePoint != nullptr )
      {
        v11 = this->scenePoint.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v11 & 0x1FFF] == v11 >> 13
          && (v12 = (idScenePoint *)gameLocal->entities.ptr[v11 & 0x1FFF]) != nullptr )
        {
          v13 = idScenePoint::CastTo(c: v12);
        }
        else
        {
          v13 = nullptr;
        }
        if ( curScenePoint == v13 )
          goto LABEL_21;
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        curScenePoint->currentUser = nullptr;
        curScenePoint->requestTime = GameMs - (int)(float)(1000.0 * (float)-5.0);
        v15 = this->scenePoint.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v15 & 0x1FFF] != v15 >> 13
          || (v16 = (idScenePoint *)gameLocal->entities.ptr[v15 & 0x1FFF]) == nullptr )
        {
LABEL_19:
          v17 = nullptr;
          goto LABEL_20;
        }
      }
      else
      {
        v18 = this->scenePoint.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v18 & 0x1FFF] != v18 >> 13 )
          goto LABEL_19;
        v16 = (idScenePoint *)gameLocal->entities.ptr[v18 & 0x1FFF];
        if ( v16 == nullptr )
          goto LABEL_19;
      }
      v17 = idScenePoint::CastTo(c: v16);
LABEL_20:
      idAIMemory::SetOverrideScenePoint(this: &v9->aiVolatile.memory, scenePoint: v17);
LABEL_21:
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_AddAggression@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD3740
// RVA : 0x00CD3740
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_AddAggression::OnActivate(idTarget_AddAggression *this, idEntity *activator)
{
  int v3; // r28
  int v4; // r29
  int value; // r9
  idEntity *v6; // r3
  idAI2 *v7; // r3
  idAI2 *v8; // r30
  __int64 v9; // r10
  idEntity *v10; // r3
  idEntity *v11; // r5
  double weight; // fp1
  char v13; // [sp+50h] [-40h] BYREF
  __int64 v14; // [sp+58h] [-38h]

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
        v7 = (idAI2 *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      v8 = idAI2::CastTo(c: v7);
      if ( v8 != nullptr )
      {
        HIDWORD(v9) = this->aggroTarget.spawnId.value;
        if ( gameLocal->spawnIds.ptr[WORD1(v9) & 0x1FFF] == SHIDWORD(v9) >> 13
          && (HIDWORD(v9) = 4 * ((WORD1(v9) & 0x1FFF) + 21563),
              (v10 = *(idEntity **)((char *)&gameLocal->__vftable + HIDWORD(v9))) != nullptr) )
        {
          v11 = idEntity::CastTo(c: v10);
        }
        else
        {
          v11 = nullptr;
        }
        weight = this->weight;
        LODWORD(v9) = this->duration;
        v14 = v9;
        idAI2::Event_AddAggression(
          this: (idAI2 *)&v13,
          result: (eventVoid *)v8,
          ent: v11,
          aggression: weight,
          duration: (float)v9);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_Damage@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD3858
// RVA : 0x00CD3858
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Damage::OnActivate(idTarget_Damage *this, idPlayer *activator)
{
  idPhysics *Physics; // r3
  const idDeclDamage *damageDecl; // r30
  const idVec3 *v6; // r3
  int v7; // r29
  int v8; // r30
  int value; // r9
  idEntity *v10; // r3
  idEntity *v11; // r3
  idPlayer *Player; // r3
  idAngles v13[2]; // [sp+50h] [-50h] BYREF

  if ( this->damageDecl == nullptr )
    idLib::Warning(fmt: "idTarget_Damage::OnActivate - No damage decl for target '%s'", this->name.data);
  if ( this->radiusDamage != 0.0 )
  {
    Physics = idEntity::GetPhysics(this);
    damageDecl = this->damageDecl;
    v6 = Physics->GetOrigin(this: Physics, a2: 0);
    idGameLocal::RadiusDamage(
      this: gameLocal,
      origin: v6,
      inflictor: this,
      attacker: activator,
      damageDef: damageDecl,
      dmgPower: 1.0);
    return;
  }
  idAngles::ToForward(this: v13, result: (idVec3 *)&this->damageDir);
  v7 = 0;
  if ( this->targets.num > 0 )
  {
    v8 = 0;
    do
    {
      value = this->targets.list[v8].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v10 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v11 = idEntity::CastTo(c: v10);
      }
      else
      {
        v11 = nullptr;
      }
      if ( v11 != nullptr )
        ((void (__fastcall *)(idEntity *, _DWORD, idPlayer *, const idDeclDamage *, double))v11->Damage)(
          a1: v11,
          a2: 0,
          a3: activator,
          a4: this->damageDecl,
          a5: 1.0);
      ++v7;
      ++v8;
    }
    while ( v7 < this->targets.num );
  }
  if ( this->damageActivator )
  {
    if ( activator != nullptr )
      ((void (__fastcall *)(idPlayer *, _DWORD, idPlayer *, const idDeclDamage *, double))activator->Damage)(
        a1: activator,
        a2: 0,
        a3: activator,
        a4: this->damageDecl,
        a5: 1.0);
    else
      idLib::Warning(fmt: "idTarget_Damage: activated by NULL");
  }
  if ( this->damagePlayer )
  {
    Player = idPlayer::CastTo(c: activator);
    if ( Player != nullptr )
    {
      if ( this->damageActivator )
        return;
      goto LABEL_23;
    }
    Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
    if ( Player != nullptr )
    {
LABEL_23:
      ((void (__fastcall *)(idPlayer *, _DWORD, idPlayer *, const idDeclDamage *, double))Player->Damage)(
        a1: Player,
        a2: 0,
        a3: activator,
        a4: this->damageDecl,
        a5: 1.0);
      return;
    }
    idLib::Warning(fmt: "idTarget_Damage::OnActivate - Could not find player! ");
  }
}


// ========================================================================
// ?OnActivate@idTarget_CollisionDamage@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD3A90
// RVA : 0x00CD3A90
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_CollisionDamage::OnActivate(idTarget_CollisionDamage *this, idVehicle_Car *activator)
{
  int v4; // r29
  int v5; // r30
  int value; // r9
  idEntity *v7; // r3
  idVehicle_Car *v8; // r3
  idVehicle_Car *v9; // r3
  idVehicle_Car *v10; // r3

  if ( this->damageDecl != nullptr )
  {
    v4 = 0;
    if ( this->targets.num > 0 )
    {
      v5 = 0;
      do
      {
        value = this->targets.list[v5].spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
          && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v8 = (idVehicle_Car *)idEntity::CastTo(c: v7);
        }
        else
        {
          v8 = nullptr;
        }
        v9 = idVehicle_Car::CastTo(c: v8);
        if ( v9 != nullptr )
          idVehicle::SetCollisionDamage(this: v9, decl: this->damageDecl, delayMS: 0, attacker: nullptr);
        ++v4;
        ++v5;
      }
      while ( v4 < this->targets.num );
    }
    v10 = idVehicle_Car::CastTo(c: activator);
    if ( v10 != nullptr )
      idVehicle::SetCollisionDamage(this: v10, decl: this->damageDecl, delayMS: 0, attacker: nullptr);
  }
  else
  {
    idLib::Warning(fmt: "idTarget_CollisionDamage::OnActivate - No damage decl for target '%s'", this->name.data);
  }
}


// ========================================================================
// ?OnActivate@idTarget_ModifyGroup@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD3B88
// RVA : 0x00CD3B88
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ModifyGroup::OnActivate(idTarget_ModifyGroup *this, idEntity *activate)
{
  idEncounterGroupManager *p_encounterGroupManager; // r30
  idEncounterGroup *v4; // r3
  idHandle<short,enum invalidEncounterGroup_t,-1> v5[4]; // [sp+50h] [-20h] BYREF

  p_encounterGroupManager = &gameLocal->encounterGroupManager;
  idEncounterGroupManager::FindGroup(
    this: (idEncounterGroupManager *)v5,
    result: p_encounterGroupManager,
    groupName: this->groupName.data);
  if ( (unsigned __int16)v5[0].value != 0xFFFF )
  {
    v4 = idEncounterGroupManager::GroupForHandle(this: p_encounterGroupManager, handle: v5);
    v4->otherGroupAlertState = this->otherGroupAlertState;
    v4->ownGroupAlertState = this->ownGroupAlertState;
  }
}


// ========================================================================
// ?OnActivate@idTarget_AICommand@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD3C10
// RVA : 0x00CD3C10
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_AICommand::OnActivate(idTarget_AICommand *this, idEntity *activator)
{
  int v3; // r21
  int i; // r23
  int value; // r9
  idEntity *v6; // r3
  idAI2 *v7; // r3
  idAI2 *v8; // r3
  idAI2 *v9; // r28
  idTarget_AICommand::aiCommandFlags_t perceptionFlag; // r11
  bool v11; // cr58
  int flags; // r11
  unsigned int v13; // r10
  int v14; // r10
  idScenePoint *v15; // r3
  idScenePoint *curScenePoint; // r31
  int v17; // r10
  idScenePoint *v18; // r3
  idScenePoint *v19; // r3
  int GameMs; // r3
  int v21; // r9
  idScenePoint *v22; // r3
  idScenePoint *v23; // r4
  int v24; // r9
  idTarget_AICommand::aiCommandFlags_t immunity; // r11
  bool v26; // cr58
  int v27; // r11
  unsigned int v28; // r10
  idTarget_AICommand::aiCommandFlags_t detectPlayerEnemy; // r11
  idPlayer *Player; // r5
  idAI2 *v31; // r3
  int v32; // r10
  idEntity *v33; // r3
  idPlayer *v34; // r31
  int v35; // r9
  idEntity *v36; // r3
  idEntity *v37; // r3
  idPhysics *Physics; // r3
  const idVec3 *v39; // r3
  char v40; // [sp+50h] [-90h] BYREF
  char v41; // [sp+51h] [-8Fh] BYREF
  int v43; // [sp+5Ch] [-84h]

  v3 = 0;
  if ( this->targets.num > 0 )
  {
    for ( i = 0; ; ++i )
    {
      value = this->targets.list[i].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v7 = (idAI2 *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      v8 = idAI2::CastTo(c: v7);
      v9 = v8;
      if ( v8 != nullptr )
        break;
      idLib::Warning(
        fmt: "idTarget_AICommand::OnActivate, trying to send AI command to NON-AI! Check this entities target list. %s ",
        this->name.data);
LABEL_48:
      if ( ++v3 >= this->targets.num )
        return;
    }
    perceptionFlag = this->perceptionFlag;
    if ( perceptionFlag != UNCHANGED )
    {
      v11 = perceptionFlag == SET;
      flags = v8->aiVolatile.perception.flags;
      v13 = flags | 1;
      if ( !v11 )
        v13 = flags & 0xFFFFFFFE;
      v8->aiVolatile.perception.flags = v13;
    }
    v14 = this->overrideScenePoint.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v14 & 0x1FFF] == v14 >> 13 )
    {
      v15 = (idScenePoint *)gameLocal->entities.ptr[v14 & 0x1FFF];
      if ( v15 != nullptr && idScenePoint::CastTo(c: v15) != nullptr )
      {
        curScenePoint = v9->aiVolatile.memory.curScenePoint;
        if ( curScenePoint == nullptr )
        {
          v24 = this->overrideScenePoint.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v24 & 0x1FFF] == v24 >> 13 )
          {
            v22 = (idScenePoint *)gameLocal->entities.ptr[v24 & 0x1FFF];
            if ( v22 != nullptr )
              goto LABEL_24;
          }
          goto LABEL_27;
        }
        v17 = this->overrideScenePoint.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v17 & 0x1FFF] == v17 >> 13
          && (v18 = (idScenePoint *)gameLocal->entities.ptr[v17 & 0x1FFF]) != nullptr )
        {
          v19 = idScenePoint::CastTo(c: v18);
        }
        else
        {
          v19 = nullptr;
        }
        if ( curScenePoint != v19 )
        {
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          curScenePoint->currentUser = nullptr;
          v43 = (int)(float)(1000.0 * (float)-5.0);
          curScenePoint->requestTime = GameMs - v43;
          v21 = this->overrideScenePoint.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v21 & 0x1FFF] == v21 >> 13 )
          {
            v22 = (idScenePoint *)gameLocal->entities.ptr[v21 & 0x1FFF];
            if ( v22 != nullptr )
            {
LABEL_24:
              v23 = idScenePoint::CastTo(c: v22);
LABEL_28:
              idAIMemory::SetOverrideScenePoint(this: &v9->aiVolatile.memory, scenePoint: v23);
              goto LABEL_29;
            }
          }
LABEL_27:
          v23 = nullptr;
          goto LABEL_28;
        }
      }
    }
LABEL_29:
    immunity = this->immunity;
    if ( immunity != UNCHANGED )
    {
      v26 = immunity == SET;
      v27 = v9->aiVolatile.script.flags;
      v28 = v27 | 0x40;
      if ( !v26 )
        v28 = v27 & 0xFFFFFFBF;
      v9->aiVolatile.script.flags = v28;
    }
    detectPlayerEnemy = this->detectPlayerEnemy;
    if ( detectPlayerEnemy == UNCHANGED )
      goto LABEL_39;
    if ( detectPlayerEnemy == SET )
    {
      Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
      if ( Player == nullptr )
      {
LABEL_39:
        v32 = this->suspectedPlayerPosEntity.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v32 & 0x1FFF] == v32 >> 13 )
        {
          v33 = gameLocal->entities.ptr[v32 & 0x1FFF];
          if ( v33 != nullptr && idEntity::CastTo(c: v33) != nullptr )
          {
            v34 = idGameLocal::GetPlayer(this: gameLocal, i: 0);
            if ( v34 != nullptr )
            {
              v35 = this->suspectedPlayerPosEntity.spawnId.value;
              if ( gameLocal->spawnIds.ptr[v35 & 0x1FFF] == v35 >> 13
                && (v36 = gameLocal->entities.ptr[v35 & 0x1FFF]) != nullptr )
              {
                v37 = idEntity::CastTo(c: v36);
              }
              else
              {
                v37 = nullptr;
              }
              Physics = idEntity::GetPhysics(this: v37);
              v39 = Physics->GetOrigin(this: Physics, a2: 0);
              idAI2::SetupFakePosition(this: v9, _pInstigator: v34, _fakePos: v39);
            }
          }
        }
        goto LABEL_48;
      }
      v31 = (idAI2 *)&v40;
    }
    else
    {
      Player = nullptr;
      v31 = (idAI2 *)&v41;
    }
    idAI2::Action_SetEnemy(this: v31, result: v9, entity: Player);
    goto LABEL_39;
  }
}


// ========================================================================
// ?ShowGenericAcceptDecline@idTarget_ShowGui@@AAA_NPAVidPlayer@@@Z
// EA  : 0x82CD3FD8
// RVA : 0x00CD3FD8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

int __fastcall idTarget_ShowGui::ShowGenericAcceptDecline(idTarget_ShowGui *this, idPlayer *player)
{
  idEntityPtr<idEntity> *v4; // r30
  int value; // r9
  idEntity *v6; // r3
  idSWFScriptFunction *v7; // r25
  idEntityPtr<idEntity> *v8; // r30
  int v9; // r9
  idEntity *v10; // r3
  idSWFScriptFunction *v11; // r8
  int index; // r11
  bool v14; // [sp+Bh] [-B5h]
  idStrId v15; // [sp+60h] [-60h] BYREF
  idStrId v16; // [sp+64h] [-5Ch] BYREF
  idEntityPtr<idEntity> *p_acceptTarget; // [sp+68h] [-58h]
  idEntityPtr<idEntity> *p_rejectTarget; // [sp+6Ch] [-54h]

  v4 = (idEntityPtr<idEntity> *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x10u,
                                  tag: TAG_SWF,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  p_acceptTarget = v4;
  if ( v4 != nullptr )
  {
    value = this->rejectTarget.spawnId.value;
    p_rejectTarget = &this->rejectTarget;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v6 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v6 != nullptr )
        v6 = idEntity::CastTo(c: v6);
    }
    else
    {
      v6 = nullptr;
    }
    v4[2].spawnId.value = (int)player;
    v4[3].spawnId.value = (int)v6;
    v4[1].spawnId.value = 0;
    v7 = (idSWFScriptFunction *)v4;
    v4->spawnId.value = (int)&`idTarget_ShowGui::ShowGenericAcceptDecline'::`3'::idSWFScriptFunction_GenericDecline::`vftable';
  }
  else
  {
    v7 = nullptr;
  }
  v8 = (idEntityPtr<idEntity> *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x10u,
                                  tag: TAG_SWF,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  p_rejectTarget = v8;
  if ( v8 != nullptr )
  {
    v9 = this->acceptTarget.spawnId.value;
    p_acceptTarget = &this->acceptTarget;
    if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13 )
    {
      v10 = gameLocal->entities.ptr[v9 & 0x1FFF];
      if ( v10 != nullptr )
        v10 = idEntity::CastTo(c: v10);
    }
    else
    {
      v10 = nullptr;
    }
    v8[2].spawnId.value = (int)player;
    v8[3].spawnId.value = (int)v10;
    v8[1].spawnId.value = 0;
    v11 = (idSWFScriptFunction *)v8;
    v8->spawnId.value = (int)&`idTarget_ShowGui::ShowGenericAcceptDecline'::`2'::idSWFScriptFunction_GenericAccept::`vftable';
  }
  else
  {
    v11 = nullptr;
  }
  index = this->guiString2.index;
  v16.index = this->guiString1.index;
  v15.index = index;
  idPlayer::ShowInfo(
    this: player,
    infoTitle: &v16,
    infoBody: &v15,
    type: GUI_PROMPT_YES_NO,
    icon: nullptr,
    acceptCallback: v11,
    cancelCallback: v7,
    large: false,
    acceptValid: v14);
  return 1;
}


// ========================================================================
// __unwind$511726
// EA  : 0x82CD4190
// RVA : 0x00CD4190
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_511726()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 192 + 104), tag: TAG_SWF);
}


// ========================================================================
// __unwind$511727
// EA  : 0x82CD41BC
// RVA : 0x00CD41BC
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_511727()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 192 + 108), tag: TAG_SWF);
}


// ========================================================================
// ?OnActivate@idTarget_ActionScript@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD41E8
// RVA : 0x00CD41E8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ActionScript::OnActivate(idTarget_ActionScript *this, idEntity *activator)
{
  int v4; // r25
  int v5; // r28
  int value; // r9
  idEntity *v7; // r3
  idAI2 *v8; // r3
  idAI2 *v9; // r31
  int v10; // r9
  idEntity *v11; // r3
  idTarget_Spawn *v12; // r3
  idTarget_Spawn *v13; // r3
  int v14; // r9
  idEntity *v15; // r3
  idAI2 *v16; // r3
  int GameMs; // r3

  v4 = 0;
  if ( this->targets.num > 0 )
  {
    v5 = 0;
    do
    {
      value = this->targets.list[v5].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v8 = (idAI2 *)idEntity::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      v9 = idAI2::CastTo(c: v8);
      if ( v9 != nullptr )
        goto LABEL_19;
      if ( v4 < this->targets.num
        && (v10 = this->targets.list[v5].spawnId.value, gameLocal->spawnIds.ptr[v10 & 0x1FFF] == v10 >> 13)
        && (v11 = gameLocal->entities.ptr[v10 & 0x1FFF]) != nullptr )
      {
        v12 = (idTarget_Spawn *)idEntity::CastTo(c: v11);
      }
      else
      {
        v12 = nullptr;
      }
      v13 = idTarget_Spawn::CastTo(c: v12);
      if ( v13 != nullptr )
      {
        v14 = v13->lastSpawned.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v14 & 0x1FFF] == v14 >> 13
          && (v15 = gameLocal->entities.ptr[v14 & 0x1FFF]) != nullptr )
        {
          v16 = (idAI2 *)idEntity::CastTo(c: v15);
        }
        else
        {
          v16 = nullptr;
        }
        v9 = idAI2::CastTo(c: v16);
        if ( v9 != nullptr )
        {
LABEL_19:
          idAI2::SetActionScript(this: v9, script: &this->actionScript, scriptExecutor: this, activator);
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          idAI2::StartActionScript(this: v9, curTime: GameMs);
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_ActionNode@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD4380
// RVA : 0x00CD4380
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ActionNode::OnActivate(idTarget_ActionNode *this, idEntity *activator)
{
  int v3; // r28
  int v4; // r29
  int value; // r9
  idEntity *v6; // r3
  idAI2 *v7; // r3
  idAI2 *v8; // r31
  int v9; // r9
  idActionNode *v10; // r3
  idActionNode *v11; // r5
  char v12; // [sp+50h] [-40h] BYREF

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
        v7 = (idAI2 *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      v8 = idAI2::CastTo(c: v7);
      if ( v8 != nullptr )
      {
        v9 = this->actionNode.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13
          && (v10 = (idActionNode *)gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr )
        {
          v11 = idActionNode::CastTo(c: v10);
        }
        else
        {
          v11 = nullptr;
        }
        idAI2::Event_ActionNode(this: (idAI2 *)&v12, result: v8, newActionNode: v11);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_ChangeAnimState@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD4478
// RVA : 0x00CD4478
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ChangeAnimState::OnActivate(idTarget_ChangeAnimState *this, idEntity *activator)
{
  int v4; // r25
  int v5; // r27
  int value; // r9
  idEntity *v7; // r3
  idAIScriptedAnimWeb *v8; // r31
  idAIScriptedAnimWeb *v9; // r3
  idAIScriptedAnimWeb *v10; // r30
  idAIScriptedAnimWeb::animState_t *p_stateInfo; // r31
  idTarget_ChangeAnimState::changeType_t changeType; // r11
  idAIScriptedAnimWeb *v13; // r3
  int v14; // r31
  char v15; // r9
  bool v16; // r30
  int v17; // r11
  signed int num; // r30
  int v19; // r3
  int currentState; // r11
  unsigned __int8 *v21; // r3
  idFirstPersonEvent *v22; // r30
  idInfoPath *v23; // r3
  idTarget_ChangeAnimState::changeType_t v24; // r11
  int v25; // r11
  signed int v26; // r30
  int v27; // r11
  unsigned int v28; // r6
  unsigned __int8 *v29; // r3
  idAnimatedSimple *v30; // r30
  idTarget_ChangeAnimState::changeType_t v31; // r11
  unsigned __int8 *v32; // r3
  idVehicle *v33; // r31
  idTarget_ChangeAnimState::changeType_t v34; // r11
  int nextState; // r4

  v4 = 0;
  if ( this->targets.num > 0 )
  {
    v5 = 0;
    do
    {
      if ( v4 < this->targets.num
        && (value = this->targets.list[v5].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
        && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v8 = (idAIScriptedAnimWeb *)idEntity::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      v9 = idAIScriptedAnimWeb::CastTo(c: v8);
      v10 = v9;
      if ( v9 != nullptr )
      {
        p_stateInfo = &v9->stateInfo;
        changeType = this->changeType;
        if ( (*((_BYTE *)this + 812) & 0x10) != 0 )
        {
          if ( changeType != CHANGETYPE_DIRECT )
          {
            idLib::Warning(
              fmt: "idTarget_ChangeAnimState::OnActivate - forceStartScriptedAnimWeb was set but not CHANGETYPE_DIRECT, setting it now");
            this->changeType = CHANGETYPE_DIRECT;
          }
LABEL_13:
          idAIScriptedAnimWeb::animState_t::SetcurrentState(this: p_stateInfo, state: this->nextState);
          if ( (*((_BYTE *)this + 812) & 0x10) != 0 )
          {
            v13 = v10;
            v14 = (int)&p_stateInfo->animWebStates->list[this->nextState];
            v15 = *(_BYTE *)(v14 + 161);
            v16 = (v15 & 0x20) != 0;
            *(_BYTE *)(v14 + 161) = v15 | 0x20;
            idAIScriptedAnimWeb::StartAIAction(this: v13, activator);
            *(_BYTE *)(v14 + 161) = (32 * v16) & 0x20 | *(_BYTE *)(v14 + 161) & 0xDF;
          }
          goto LABEL_76;
        }
        switch ( changeType )
        {
          case CHANGETYPE_DIRECT:
            goto LABEL_13;
          case CHANGETYPE_PREV:
            idAIScriptedAnimWeb::animState_t::SetcurrentState(
              this: &v9->stateInfo,
              state: v9->stateInfo.currentState - 1);
            break;
          case CHANGETYPE_NEXT:
            v17 = v9->stateInfo.currentState + 1;
            if ( p_stateInfo->animWebStates->num > v17 )
              v9->stateInfo.currentState = v17;
            break;
          case CHANGETYPE_RANDOM:
            num = p_stateInfo->animWebStates->num;
            if ( num > -2 )
            {
              v19 = idRandom2::RandomInt(this: &clientGame->random, max: p_stateInfo->animWebStates->num);
              currentState = p_stateInfo->currentState;
              if ( currentState == -1 || currentState != v19 )
                goto LABEL_48;
              __twllei(num, 0);
              __twlgei(num & ~(__ROL4__(v19 + 1, 1) - 1), 0xFFFFFFFF);
              p_stateInfo->currentState = (v19 + 1) % num;
            }
            break;
          default:
            if ( changeType == CHANGETYPE_EXIT && p_stateInfo->animWebStates->num > -3 )
              v9->stateInfo.currentState = -3;
            break;
        }
      }
      else
      {
        v21 = (unsigned __int8 *)idFirstPersonEvent::CastTo(c: (idFirstPersonEvent *)v8);
        v22 = (idFirstPersonEvent *)v21;
        if ( v21 != nullptr )
        {
          if ( (*((_BYTE *)this + 812) & 0x40) != 0
            && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v21) != 0 )
          {
            v22->Show(this: v22);
          }
          idFirstPersonEvent::SetCurrentState(this: v22, changeType: this->changeType, nextState: this->nextState);
          goto LABEL_76;
        }
        if ( this->changeType == CHANGETYPE_EXIT )
        {
          idLib::Warning(
            fmt: "idTarget_ChangeAnimState::OnActivate: Only ScriptedAnimweb and firstPersonEvents can handle CHANGETYPE_EXIT");
        }
        else
        {
          v23 = idInfoPath::CastTo(c: (idInfoPath *)v8);
          if ( v23 != nullptr )
          {
            v24 = this->changeType;
            p_stateInfo = &v23->plugAnim.stateInfo;
            switch ( v24 )
            {
              case CHANGETYPE_DIRECT:
                idAIScriptedAnimWeb::animState_t::SetcurrentState(
                  this: &v23->plugAnim.stateInfo,
                  state: this->nextState);
                break;
              case CHANGETYPE_PREV:
                idAIScriptedAnimWeb::animState_t::SetcurrentState(
                  this: &v23->plugAnim.stateInfo,
                  state: v23->plugAnim.stateInfo.currentState - 1);
                break;
              case CHANGETYPE_NEXT:
                v25 = v23->plugAnim.stateInfo.currentState + 1;
                if ( p_stateInfo->animWebStates->num > v25 )
                  v23->plugAnim.stateInfo.currentState = v25;
                break;
              case CHANGETYPE_RANDOM:
                v26 = p_stateInfo->animWebStates->num;
                if ( v26 > -2 )
                {
                  v19 = idRandom2::RandomInt(this: &clientGame->random, max: p_stateInfo->animWebStates->num);
                  v27 = p_stateInfo->currentState;
                  if ( v27 != -1 && v27 == v19 )
                  {
                    __twllei(v26, 0);
                    v28 = v26 & ~(__ROL4__(v19 + 1, 1) - 1);
                    v19 = (v19 + 1) % v26;
                    __twlgei(v28, 0xFFFFFFFF);
                  }
LABEL_48:
                  p_stateInfo->currentState = v19;
                }
                break;
              default:
                break;
            }
          }
          else
          {
            v29 = (unsigned __int8 *)idAnimatedSimple::CastTo(c: (idAnimatedSimple *)v8);
            v30 = (idAnimatedSimple *)v29;
            if ( v29 != nullptr )
            {
              if ( (*((_BYTE *)this + 812) & 0x20) != 0 )
                v29[7651] = 1;
              if ( (*((_BYTE *)this + 812) & 0x40) != 0
                && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v29) != 0 )
              {
                v30->Show(this: v30);
              }
              v31 = this->changeType;
              if ( v31 == CHANGETYPE_DIRECT )
              {
                idAnimatedSimple::SetAnimState(
                  this: v30,
                  animState: this->nextState,
                  blendTime: this->blendTime,
                  queue: *((_BYTE *)this + 812) >> 7,
                  checkPoint: (*((_BYTE *)this + 812) & 0x20) != 0);
              }
              else if ( v31 == CHANGETYPE_PREV )
              {
                idAnimatedSimple::GotoPrevState(
                  this: v30,
                  blendTime: this->blendTime,
                  queue: *((_BYTE *)this + 812) >> 7);
              }
              else if ( v31 != CHANGETYPE_NEXT )
              {
                if ( v31 == CHANGETYPE_RANDOM )
                  idAnimatedSimple::SetAnimState(
                    this: v30,
                    animState: -2,
                    blendTime: this->blendTime,
                    queue: *((_BYTE *)this + 812) >> 7,
                    checkPoint: (*((_BYTE *)this + 812) & 0x20) != 0);
              }
              else
              {
                idAnimatedSimple::GotoNextState(
                  this: v30,
                  blendTime: this->blendTime,
                  queue: *((_BYTE *)this + 812) >> 7);
              }
              goto LABEL_76;
            }
            v32 = (unsigned __int8 *)idVehicle::CastTo(c: (idVehicle *)v8);
            v33 = (idVehicle *)v32;
            if ( v32 != nullptr )
            {
              if ( (*((_BYTE *)this + 812) & 0x40) != 0
                && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v32) != 0 )
              {
                v33->Show(this: v33);
              }
              v34 = this->changeType;
              if ( v34 == CHANGETYPE_DIRECT )
              {
                nextState = this->nextState;
LABEL_75:
                idVehicle::SetAnimEventState(
                  this: v33,
                  animState: nextState,
                  blendTime: this->blendTime,
                  queue: *((_BYTE *)this + 812) >> 7);
                goto LABEL_76;
              }
              if ( v34 == CHANGETYPE_PREV )
              {
                idVehicle::GotoPrevAnimEventState(
                  this: v33,
                  blendTime: this->blendTime,
                  queue: *((_BYTE *)this + 812) >> 7);
              }
              else if ( v34 != CHANGETYPE_NEXT )
              {
                if ( v34 == CHANGETYPE_RANDOM )
                {
                  nextState = -2;
                  goto LABEL_75;
                }
              }
              else
              {
                idVehicle::GotoNextAnimEventState(
                  this: v33,
                  blendTime: this->blendTime,
                  queue: *((_BYTE *)this + 812) >> 7);
              }
            }
          }
        }
      }
LABEL_76:
      ++v4;
      ++v5;
    }
    while ( v4 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_SetAISolidState@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD49A8
// RVA : 0x00CD49A8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_SetAISolidState::OnActivate(idTarget_SetAISolidState *this, idEntity *activator)
{
  int v3; // r28
  int v4; // r29
  int value; // r9
  idEntity *v6; // r3
  idAI2 *v7; // r3
  idAI2 *v8; // r3
  idAI2 *v9; // r31
  int restoreSolidFrames; // r3

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
        v7 = (idAI2 *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      v8 = idAI2::CastTo(c: v7);
      v9 = v8;
      if ( v8 != nullptr )
      {
        idAI2::SetSolid(this: v8, isSolid: this->solid);
        restoreSolidFrames = this->restoreSolidFrames;
        if ( restoreSolidFrames != 0 )
          v9->aiVolatile.physics.restoreSolidCollisionTime = GetEndTimeByFrames(frameCount: restoreSolidFrames);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_PlayAnim@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD4A68
// RVA : 0x00CD4A68
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_PlayAnim::OnActivate(idTarget_PlayAnim *this, idEntity *activator)
{
  int v3; // r29
  int v4; // r30
  int value; // r9
  idEntity *v6; // r3
  idAnimatedSimple *v7; // r3
  idAnimatedSimple *v8; // r3

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
        v7 = (idAnimatedSimple *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      v8 = idAnimatedSimple::CastTo(c: v7);
      if ( v8 != nullptr )
        idAnimatedSimple::PlayAnim(
          this: v8,
          anim: &this->animation,
          loop: this->loopAnimation,
          blendTime: this->blendTime);
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_PauseAnim@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD4B18
// RVA : 0x00CD4B18
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_PauseAnim::OnActivate(idTarget_PauseAnim *this, idEntity *activator)
{
  int v3; // r29
  int v4; // r30
  int value; // r9
  idEntity *v6; // r3
  idAnimatedSimple *v7; // r3
  idAnimatedSimple *v8; // r3

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
        v7 = (idAnimatedSimple *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      v8 = idAnimatedSimple::CastTo(c: v7);
      if ( v8 != nullptr )
        idAnimatedSimple::PauseCurrentAnim(
          this: v8,
          pause: this->pause,
          pauseFrame: this->pauseFrame,
          queuePause_: this->queuePause);
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_SetRestrictionVolume@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD4BC8
// RVA : 0x00CD4BC8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_SetRestrictionVolume::OnActivate(idTarget_SetRestrictionVolume *this, idEntity *activator)
{
  int v3; // r27
  int v4; // r28
  int value; // r9
  idEntity *v6; // r3
  idAI2 *v7; // r3
  idAI2 *v8; // r3
  idAI2 *v9; // r31
  int v10; // r10
  idVolume_Restriction *v11; // r3
  idVolume_Restriction *v12; // r3

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
        v7 = (idAI2 *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      v8 = idAI2::CastTo(c: v7);
      v9 = v8;
      if ( v8 != nullptr )
      {
        idAIMemory::SetRestrictionVolume(this: &v8->aiVolatile.memory, volume: this->restrictionVolume.spawnId.value);
        v10 = this->restrictionVolume.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v10 & 0x1FFF] == v10 >> 13
          && (v11 = (idVolume_Restriction *)gameLocal->entities.ptr[v10 & 0x1FFF]) != nullptr )
        {
          v12 = idVolume_Restriction::CastTo(c: v11);
        }
        else
        {
          v12 = nullptr;
        }
        if ( (*(_BYTE *)&v12->flags & 8) != 0 )
        {
          if ( v9->aiVolatile.memory.curScenePoint != nullptr )
            v9->aiVolatile.memory.curScenePointDirty = true;
          if ( v9->aiVolatile.memory.curLookScenePoint != nullptr )
            v9->aiVolatile.memory.curLookScenePointDirty = true;
        }
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_ApplyImpulse@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD4D20
// RVA : 0x00CD4D20
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ApplyImpulse::OnActivate(idTarget_ApplyImpulse *this, idEntity *activator)
{
  int physicsId; // r25
  idPhysics *Physics; // r3
  int bodyId; // r24
  idPhysics *v7; // r3
  float *v8; // r3
  float v9; // r5
  double impulse; // fp0
  float v11; // r4
  float v12; // r3
  int num; // r11
  idPhysics *v14; // r3
  idEntity_vtbl *v15; // r29
  int v16; // r3
  idPhysics *v17; // r3
  idPhysics *v18; // r3
  double v19; // fp7
  double v20; // fp6
  int v21; // r27
  int v22; // r28
  int value; // r9
  idEntity *v24; // r3
  idEntity *v25; // r31
  idPhysics *v26; // r3
  idEntity_vtbl *v27; // r29
  int v28; // r3
  idPhysics *v29; // r3
  idPhysics *v30; // r3
  double v31; // fp7
  float v32[4]; // [sp+50h] [-A0h] BYREF
  float v33[4]; // [sp+60h] [-90h] BYREF
  float v34[4]; // [sp+70h] [-80h] BYREF
  float v35[4]; // [sp+80h] [-70h] BYREF
  float v36[24]; // [sp+90h] [-60h] BYREF

  physicsId = idEntity::GetPhysics(this)->physicsId;
  Physics = idEntity::GetPhysics(this: activator);
  bodyId = Physics->GetClipModel(this: Physics, a2: 0)->bodyId;
  v7 = idEntity::GetPhysics(this);
  v8 = (float *)v7->GetAxis(this: v7, a2: 0);
  v9 = v8[1];
  impulse = this->impulse;
  v11 = v8[2];
  v12 = *v8;
  num = this->targets.num;
  v32[1] = v9 * this->impulse;
  v32[2] = v11 * (float)impulse;
  v32[0] = v12 * (float)impulse;
  if ( num != 0 )
  {
    v21 = 0;
    if ( num > 0 )
    {
      v22 = 0;
      do
      {
        value = this->targets.list[v22].spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
          && (v24 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v25 = idEntity::CastTo(c: v24);
        }
        else
        {
          v25 = nullptr;
        }
        if ( v25 != nullptr )
        {
          v26 = idEntity::GetPhysics(this: v25);
          v27 = v25->__vftable;
          v28 = (int)v26->GetOrigin(this: v26, a2: 0);
          v27->ApplyImpulse(this: v25, a2: physicsId, a3: bodyId, a4: (const idVec3 *)v28, a5: (const idVec3 *)v32);
          v29 = idEntity::GetPhysics(this: v25);
          v29->GetAngularVelocity(this: (idPhysics *)v35, result: (idVec3 *)v29, a3: 0);
          v30 = idEntity::GetPhysics(this: v25);
          v31 = (float)(this->angular.y + v35[1]);
          v36[0] = this->angular.x + v35[0];
          v36[1] = v31;
          v36[2] = this->angular.z + v35[2];
          v30->SetAngularVelocity(this: v30, a2: (const idVec3 *)v36, a3: 0);
        }
        ++v21;
        ++v22;
      }
      while ( v21 < this->targets.num );
    }
  }
  else
  {
    v14 = idEntity::GetPhysics(this: activator);
    v15 = activator->__vftable;
    v16 = (int)v14->GetOrigin(this: v14, a2: 0);
    v15->ApplyImpulse(this: activator, a2: physicsId, a3: bodyId, a4: (const idVec3 *)v16, a5: (const idVec3 *)v32);
    v17 = idEntity::GetPhysics(this: activator);
    v17->GetAngularVelocity(this: (idPhysics *)v33, result: (idVec3 *)v17, a3: 0);
    v18 = idEntity::GetPhysics(this: activator);
    v19 = (float)(this->angular.y + v33[1]);
    v20 = (float)(this->angular.z + v33[2]);
    v34[0] = this->angular.x + v33[0];
    v34[1] = v19;
    v34[2] = v20;
    v18->SetAngularVelocity(this: v18, a2: (const idVec3 *)v34, a3: 0);
  }
}


// ========================================================================
// ?ApplyExplosion@idTarget_ApplyExplosionImpulse@@AAAXH@Z
// EA  : 0x82CD4FD8
// RVA : 0x00CD4FD8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ApplyExplosionImpulse::ApplyExplosion(idTarget_ApplyExplosionImpulse *this, int entNumber)
{
  idPhysics *Physics; // r3
  int v5; // r31
  int num; // r29
  int physicsId; // r25
  idPhysics *v8; // r3
  float *v9; // r3
  float v10; // r8
  float v11; // r10
  double impulse; // fp0
  int v13; // r4
  double v14; // fp31
  int v15; // r26
  idPhysics *v16; // r3
  int v17; // r3
  float *v18; // r11
  int v19; // r8
  char *v20; // r9
  int i; // ctr
  double v22; // fp0
  float *v23; // r10
  idPhysics *v24; // r31
  idPhysics *v25; // r30
  float *v26; // r31
  float *v27; // r3
  double v28; // fp9
  double v29; // fp7
  double v30; // fp11
  double v33; // fp8
  double v34; // fp10
  double v35; // fp8
  double v36; // fp1
  double v37; // fp13
  idAI2 *v38; // r30
  idPlayer *v39; // r3
  idPlayer *v40; // r31
  idAnimator_AF *v41; // r3
  idPhysics_AF *p_physicsObj; // r29
  int v43; // r31
  idAFBody *Body; // r3
  float *clipModel; // r11
  float v46; // r9
  float v47; // r8
  float v48; // r11
  void (__fastcall *ApplyImpulse)(struct idAI2 *, const int, const int, const idVec3 *, const idVec3 *); // r10
  idAnimator_AF *v50; // r3
  idPhysics_AF *v51; // r29
  char v52; // r28
  int v53; // r30
  idAFBody *v54; // r3
  float *v55; // r11
  double v56; // fp9
  double v57; // fp8
  float v58; // r10
  float v59; // r9
  float v60; // r8
  idPlayer_vtbl *v61; // r11
  double v62; // fp9
  double v63; // fp8
  idPhysics *v64; // r3
  int v65; // r3
  float v66; // r10
  float v67; // r9
  void (__fastcall *v68)(int, int, _DWORD, float *, idVec3 *); // r8
  idPhysics *v69; // r3
  idPhysics *v70; // r3
  double v71; // fp7
  double v72; // fp6
  idVec3 v73; // [sp+50h] [-C0h] BYREF
  float v74; // [sp+60h] [-B0h] BYREF
  float v75; // [sp+64h] [-ACh]
  float v76; // [sp+68h] [-A8h]
  float v77[4]; // [sp+70h] [-A0h] BYREF
  float v78[4]; // [sp+80h] [-90h] BYREF
  float v79[4]; // [sp+90h] [-80h] BYREF
  float v80[4]; // [sp+A0h] [-70h] BYREF
  _BYTE v81[24]; // [sp+B0h] [-60h] BYREF

  Physics = idEntity::GetPhysics(this);
  v5 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  num = this->targets.num;
  physicsId = idEntity::GetPhysics(this)->physicsId;
  v8 = idEntity::GetPhysics(this);
  v9 = (float *)v8->GetAxis(this: v8, a2: 0);
  v10 = *v9;
  v11 = v9[1];
  impulse = this->impulse;
  v13 = 4 * (entNumber + 21563);
  v14 = (float)(this->radius.value * this->radius.value);
  v73.z = v9[2];
  v73.y = v11 * (float)impulse;
  v73.x = v10 * (float)impulse;
  v73.z = v73.z * (float)impulse;
  v15 = *(int *)((char *)&gameLocal->__vftable + v13);
  if ( v15 != 0 )
  {
    v16 = idEntity::GetPhysics(this: *(idEntity **)((char *)&gameLocal->__vftable + v13));
    v17 = (int)v16->GetAbsBounds(this: v16, a2: -1);
    if ( num != 0 )
      goto LABEL_12;
    v18 = (float *)v5;
    v19 = v17 - v5;
    v20 = (char *)&v74 - v5;
    for ( i = 3; i != 0; --i )
    {
      v22 = *v18;
      v23 = (float *)((char *)v18 + v19);
      if ( v22 >= *(float *)((char *)v18 + v19) )
      {
        if ( v22 <= v23[3] )
          *(float *)((char *)v18 + (_DWORD)v20) = 0.0;
        else
          *(float *)((char *)v18 + (_DWORD)v20) = *v18 - v23[3];
      }
      else
      {
        *(float *)((char *)v18 + (_DWORD)v20) = *(float *)((char *)v18 + v19) - *v18;
      }
      ++v18;
    }
    if ( (float)((float)(v74 * v74) + (float)((float)(v75 * v75) + (float)(v76 * v76))) <= v14 )
    {
LABEL_12:
      if ( this->isRadial )
      {
        v24 = idEntity::GetPhysics(this);
        v25 = idEntity::GetPhysics(this: (idEntity *)v15);
        v26 = (float *)v24->GetOrigin(this: v24, a2: 0);
        v27 = (float *)v25->GetOrigin(this: v25, a2: 0);
        v28 = (float)(v27[1] - v26[1]);
        v29 = (float)(v27[2] - v26[2]);
        v30 = this->impulse;
        _FP1 = (float)((float)((float)((float)(*v27 - *v26) * (float)(*v27 - *v26))
                             + (float)((float)((float)v29 * (float)v29) + (float)((float)v28 * (float)v28)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f10, f1, f2, f13 }
        v33 = __frsqrte(_FP10);
        v34 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v33
                                                                                            * (float)((float)((float)((float)(*v27 - *v26) * (float)(*v27 - *v26)) + (float)((float)((float)v29 * (float)v29) + (float)((float)v28 * (float)v28))) * (float)0.5))
                                                                                    * (float)v33)
                                                                            - (float)1.5)
                                                            * (float)v33)
                                                    * (float)((float)((float)((float)(*v27 - *v26) * (float)(*v27 - *v26))
                                                                    + (float)((float)((float)v29 * (float)v29)
                                                                            + (float)((float)v28 * (float)v28)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v33
                                                                                    * (float)((float)((float)((float)(*v27 - *v26) * (float)(*v27 - *v26)) + (float)((float)((float)v29 * (float)v29) + (float)((float)v28 * (float)v28)))
                                                                                            * (float)0.5))
                                                                            * (float)v33)
                                                                    - (float)1.5)
                                                    * (float)v33))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v33
                                                            * (float)((float)((float)((float)(*v27 - *v26)
                                                                                    * (float)(*v27 - *v26))
                                                                            + (float)((float)((float)v29 * (float)v29)
                                                                                    + (float)((float)v28 * (float)v28)))
                                                                    * (float)0.5))
                                                    * (float)v33)
                                            - (float)1.5)
                            * (float)v33));
        v35 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v33 * (float)((float)((float)((float)(*v27 - *v26) * (float)(*v27 - *v26)) + (float)((float)((float)v29 * (float)v29) + (float)((float)v28 * (float)v28))) * (float)0.5))
                                                                                            * (float)v33)
                                                                                    - (float)1.5)
                                                                    * (float)v33)
                                                            * (float)((float)((float)((float)(*v27 - *v26)
                                                                                    * (float)(*v27 - *v26))
                                                                            + (float)((float)((float)v29 * (float)v29)
                                                                                    + (float)((float)v28 * (float)v28)))
                                                                    * (float)0.5))
                                                    * (float)((float)-(float)((float)((float)((float)v33
                                                                                            * (float)((float)((float)((float)(*v27 - *v26) * (float)(*v27 - *v26)) + (float)((float)((float)v29 * (float)v29) + (float)((float)v28 * (float)v28))) * (float)0.5))
                                                                                    * (float)v33)
                                                                            - (float)1.5)
                                                            * (float)v33))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v33
                                                                    * (float)((float)((float)((float)(*v27 - *v26)
                                                                                            * (float)(*v27 - *v26))
                                                                                    + (float)((float)((float)v29 * (float)v29)
                                                                                            + (float)((float)v28 * (float)v28)))
                                                                            * (float)0.5))
                                                            * (float)v33)
                                                    - (float)1.5)
                                    * (float)v33))
                    * (float)((float)((float)((float)(*v27 - *v26) * (float)(*v27 - *v26))
                                    + (float)((float)((float)v29 * (float)v29) + (float)((float)v28 * (float)v28)))
                            * (float)0.5));
        v36 = (float)((float)(v27[2] - v26[2])
                    * (float)((float)-(float)((float)((float)v35 * (float)v34) - (float)1.5) * (float)v34));
        v37 = (float)((float)((float)(v27[1] - v26[1])
                            * (float)((float)-(float)((float)((float)v35 * (float)v34) - (float)1.5) * (float)v34))
                    * this->impulse);
        v73.x = this->impulse
              * (float)((float)((float)-(float)((float)((float)v35 * (float)v34) - (float)1.5) * (float)v34)
                      * (float)(*v27 - *v26));
        v73.y = v37;
        v73.z = (float)v36 * (float)v30;
      }
      if ( (unsigned __int8)idProjectile::IsTypeOf(c: (idClass *)v15) == 0 && (*(_BYTE *)(v15 + 92) & 4) == 0 )
      {
        if ( this->damageDecl != nullptr
          && (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v15 + 300))(a1: v15) != 0 )
        {
          (*(void (__fastcall **)(int, _DWORD, _DWORD, const idDeclDamage *, double))(*(_DWORD *)v15 + 312))(
            a1: v15,
            a2: 0,
            a3: 0,
            a4: this->damageDecl,
            a5: this->damageScale);
        }
        v38 = idAI2::CastTo(c: (idAI2 *)v15);
        v39 = idPlayer::CastTo(c: (idPlayer *)v15);
        v40 = v39;
        if ( v38 != nullptr )
        {
          if ( v38->IsDead(this: v38) )
          {
            if ( v38->GetAF_2(this: v38)->isSyncing )
              v38->StartRagdoll(this: v38, a2: &v38->ragdollInfo);
            v41 = v38->GetAF_2(this: v38);
            if ( v41 != nullptr )
            {
              p_physicsObj = &v41->physicsObj;
              if ( v41 != (idAnimator_AF *)-288 )
              {
                v43 = idAnimator_AF::BodyForJoint(
                        this: v41,
                        joint: (idIndex<short,enum invalidJointIndex_t> *)0xFFFFFFFF);
                Body = idPhysics_AF::GetBody(this: p_physicsObj, id: v43);
                if ( Body != nullptr )
                {
                  clipModel = (float *)Body->clipModel;
                  v46 = clipModel[8];
                  v47 = clipModel[9];
                  v48 = clipModel[10];
                  ApplyImpulse = v38->ApplyImpulse;
                  v74 = v46;
                  v75 = v47;
                  v76 = v48;
                  ApplyImpulse(this: v38, a2: physicsId, a3: v43, a4: (const idVec3 *)&v74, a5: &v73);
                }
              }
            }
          }
          else
          {
            idAI2::ApplyFakeDamageImpulse(this: v38, impulse: &v73);
          }
        }
        else if ( v39 != nullptr )
        {
          v50 = v39->GetAF_2(this: v39);
          v51 = &v50->physicsObj;
          if ( v50 == nullptr )
            v51 = nullptr;
          v52 = 0;
          if ( v50 != nullptr && v51 != nullptr )
          {
            v53 = idAnimator_AF::BodyForJoint(this: v50, joint: (idIndex<short,enum invalidJointIndex_t> *)0xFFFFFFFF);
            v54 = idPhysics_AF::GetBody(this: v51, id: v53);
            if ( v54 != nullptr )
            {
              v55 = (float *)v54->clipModel;
              v56 = (float)(this->pushPlayerScale * v73.y);
              v57 = (float)(v73.z * this->pushPlayerScale);
              v58 = v55[8];
              v59 = v55[9];
              v60 = v55[10];
              v77[0] = this->pushPlayerScale * v73.x;
              v77[1] = v56;
              v77[2] = v57;
              v61 = v40->__vftable;
              v74 = v58;
              v75 = v59;
              v76 = v60;
              v61->ApplyImpulse(this: v40, a2: physicsId, a3: v53, a4: (const idVec3 *)&v74, a5: (const idVec3 *)v77);
              v52 = 1;
            }
          }
          if ( v52 == 0 )
          {
            v40->GetAimPoint(this: v40, a2: AIMPOINT_CENTER, a3: (idVec3 *)v81);
            v62 = (float)(this->pushPlayerScale * v73.y);
            v63 = (float)(v73.z * this->pushPlayerScale);
            v78[0] = this->pushPlayerScale * v73.x;
            v78[1] = v62;
            v78[2] = v63;
            v40->ApplyImpulse(this: v40, a2: physicsId, a3: 0, a4: (const idVec3 *)v81, a5: (const idVec3 *)v78);
          }
        }
        else
        {
          v64 = idEntity::GetPhysics(this: (idEntity *)v15);
          v65 = (int)v64->GetOrigin(this: v64, a2: 0);
          v66 = *(float *)(v65 + 4);
          v67 = *(float *)(v65 + 8);
          v68 = *(void (__fastcall **)(int, int, _DWORD, float *, idVec3 *))(*(_DWORD *)v15 + 264);
          v74 = *(float *)v65;
          v75 = v66;
          v76 = v67;
          v68(a1: v15, a2: physicsId, a3: 0, a4: &v74, a5: &v73);
        }
        v69 = idEntity::GetPhysics(this: (idEntity *)v15);
        v69->GetAngularVelocity(this: (idPhysics *)v79, result: (idVec3 *)v69, a3: 0);
        v70 = idEntity::GetPhysics(this: (idEntity *)v15);
        v71 = (float)(this->angular.y + v79[1]);
        v72 = (float)(this->angular.z + v79[2]);
        v80[0] = this->angular.x + v79[0];
        v80[1] = v71;
        v80[2] = v72;
        v70->SetAngularVelocity(this: v70, a2: (const idVec3 *)v80, a3: 0);
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "idTarget_ApplyExplosionImpulse - ent was NULL");
  }
}


// ========================================================================
// ?OnActivate@idTarget_Teleport@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD5608
// RVA : 0x00CD5608
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Teleport::OnActivate(idTarget_Teleport *this, idEntity *activator)
{
  idPhysics *Physics; // r28
  idPhysics *v5; // r27
  idEntity_vtbl *v6; // r29
  idAngles *v7; // r3
  idAngles *v8; // r28
  int v9; // r3
  int v10; // r27
  int v11; // r28
  int value; // r9
  idEntity *v13; // r3
  idEntity *v14; // r31
  idPhysics *v15; // r25
  idPhysics *v16; // r24
  idEntity_vtbl *v17; // r29
  idAngles *v18; // r3
  idAngles *v19; // r25
  int v20; // r3
  idMat3 v21[2]; // [sp+50h] [-60h] BYREF

  if ( this->targetActivator && activator != nullptr )
  {
    Physics = idEntity::GetPhysics(this);
    v5 = idEntity::GetPhysics(this);
    v6 = activator->__vftable;
    v7 = (idAngles *)Physics->GetAxis(this: Physics, a2: 0);
    v8 = idMat3::ToAngles(this: v21, result: v7);
    v9 = (int)v5->GetOrigin(this: v5, a2: 0);
    v6->Teleport(this: activator, a2: (const idVec3 *)v9, a3: v8);
  }
  v10 = 0;
  if ( this->targets.num > 0 )
  {
    v11 = 0;
    do
    {
      value = this->targets.list[v11].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v13 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v14 = idEntity::CastTo(c: v13);
      }
      else
      {
        v14 = nullptr;
      }
      if ( v14 != nullptr )
      {
        v15 = idEntity::GetPhysics(this);
        v16 = idEntity::GetPhysics(this);
        v17 = v14->__vftable;
        v18 = (idAngles *)v15->GetAxis(this: v15, a2: 0);
        v19 = idMat3::ToAngles(this: v21, result: v18);
        v20 = (int)v16->GetOrigin(this: v16, a2: 0);
        v17->Teleport(this: v14, a2: (const idVec3 *)v20, a3: v19);
      }
      ++v10;
      ++v11;
    }
    while ( v10 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_AssignVehicle@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD57B0
// RVA : 0x00CD57B0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_AssignVehicle::OnActivate(idTarget_AssignVehicle *this, idPlayer *activator)
{
  idPlayer *v3; // r30
  idInventoryCollection *v4; // r3
  int v5; // r10
  const idDeclVehicleUpgrade **list; // r11
  const idDeclVehicleUpgrade *v7; // r30
  int num; // r11
  int v9; // r28
  idGameLocal *v10; // r10
  int v11; // r29
  int value; // r9
  idVehicle *v13; // r3
  int listStatic; // r11
  __int16 *p_granularity; // r10
  idVehicle *p_z; // r11
  double x; // fp13
  int v18; // ctr
  double v19; // fp12
  double v20; // fp11
  double v21; // fp8
  double v22; // fp7
  double v23; // fp6
  idVehicle *v24; // r29
  idStr *v25; // r3
  idVehicle *VehicleFromKey; // r3
  idStr *v27; // r3
  float y; // [sp+5Ch] [-84h]
  idList<idDeclVehicleUpgrade const *,5> v29; // [sp+70h] [-70h] BYREF
  idStr v30; // [sp+80h] [-60h] BYREF
  float v31; // [sp+A0h] [-40h]

  v3 = idPlayer::CastTo(c: activator);
  if ( v3 != nullptr )
  {
    if ( gameLocal->world->mapType == MAPTYPE_OUTDOOR )
    {
      if ( this->keyDecl != nullptr )
      {
        idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: &v29);
        v4 = v3->GetInventory_2(this: v3);
        idInventoryCollection::GetVehicleKeys(this: v4, vehicleList: (idList<idVehicleKey *,5> *)&v29);
        v5 = 0;
        if ( v29.num <= 0 )
        {
LABEL_11:
          idLib::Warning(fmt: "key not on player in idTarget_AssignVehicle");
          idLib::Warning(fmt: "\teventually we should give them the key, but for now we are aborting");
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v29);
        }
        else
        {
          list = v29.list;
          while ( 1 )
          {
            v7 = *list;
            if ( this->keyDecl == (*list)->nextOnHashChain )
              break;
            ++v5;
            ++list;
            if ( v5 >= v29.num )
              goto LABEL_11;
          }
          v9 = 0;
          num = this->targets.num;
          if ( num <= 0 )
          {
LABEL_21:
            idLib::Warning(fmt: "no valid target for idTarget_AssignVehicle");
            listStatic = v29.listStatic;
          }
          else
          {
            v10 = gameLocal;
            v11 = 0;
            while ( 1 )
            {
              if ( v9 < num
                && (value = this->targets.list[v11].spawnId.value, v10->spawnIds.ptr[value & 0x1FFF] == value >> 13) )
              {
                v13 = (idVehicle *)v10->entities.ptr[value & 0x1FFF];
                if ( v13 != nullptr )
                {
                  v13 = (idVehicle *)idEntity::CastTo(c: v13);
                  v10 = gameLocal;
                }
              }
              else
              {
                v13 = nullptr;
              }
              if ( v13 != nullptr )
                break;
              ++v9;
              ++v11;
              num = this->targets.num;
              if ( v9 >= num )
                goto LABEL_21;
            }
            p_granularity = &v29.granularity;
            p_z = (idVehicle *)&v13->spawnPosition.z;
            x = v13->spawnPosition.x;
            y = v13->spawnPosition.y;
            *(float *)&v7->attachmentInfo.granularity = v13->spawnPosition.z;
            v18 = 9;
            *(float *)&v7->attachmentInfo.size = y;
            *(float *)&v7->attachmentInfo.num = x;
            do
            {
              p_z = (idVehicle *)((char *)p_z + 4);
              p_granularity += 2;
              *(_DWORD *)p_granularity = p_z->__vftable;
              --v18;
            }
            while ( v18 != 0 );
            v7->handsFovScale = *(float *)&v30.len;
            v19 = *(float *)&v30.data;
            v20 = *(float *)&v30.allocedAndFlag;
            v7->internalName.data = *(char **)v30.baseBuffer;
            *(float *)&v7->displayName.index = v19;
            *(float *)&v7->internalName.len = v20;
            v7->internalName.allocedAndFlag = *(int *)&v30.baseBuffer[4];
            v21 = *(float *)&v30.baseBuffer[12];
            *(float *)v7->internalName.baseBuffer = *(float *)&v30.baseBuffer[8];
            v22 = *(float *)&v30.baseBuffer[16];
            *(float *)&v7->internalName.baseBuffer[4] = v21;
            v23 = v31;
            *(float *)&v7->internalName.baseBuffer[8] = v22;
            *(float *)&v7->internalName.baseBuffer[12] = v23;
            v7->customMaterial = nullptr;
            v24 = idVehicle::CastTo(c: v13);
            if ( v24 != nullptr )
            {
              v25 = idStr::idStr(this: &v30, text: v24->name.data);
              idVehicleKey::SetVehicleEntityName(this: (idVehicleKey *)v7, vehName: v25);
              idVehicleKey::SetValuesFromVehicle(this: (idVehicleKey *)v7, vehicle: v24);
            }
            else
            {
              VehicleFromKey = idVehicleKey::GetVehicleFromKey(this: (idVehicleKey *)v7);
              if ( VehicleFromKey != nullptr )
                idEventReceiver::PostEventMS(this: VehicleFromKey, ev: &EV_Remove, time: 0);
              v27 = idStr::idStr(this: &v30, text: &byte_8200D768);
              idVehicleKey::SetVehicleEntityName(this: (idVehicleKey *)v7, vehName: v27);
            }
            listStatic = v29.listStatic;
          }
          if ( (listStatic == 0 || listStatic == 2) && v29.list != nullptr )
            idMem::Free(this: &mem, ptr: v29.list, align: ALIGN_16);
        }
      }
      else
      {
        idLib::Warning(fmt: "idTarget_AssignVehicle has NULL keyDecl");
      }
    }
    else
    {
      idLib::Warning(fmt: "idTarget_AssignVehicle should currently only be used outside");
    }
  }
  else
  {
    idLib::Warning(fmt: "idTarget_AssignVehicle: Activator must be player to idTarget_AssignVehicle");
  }
}


// ========================================================================
// __unwind$513331
// EA  : 0x82CD5ABC
// RVA : 0x00CD5ABC
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_513331()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 224 + 112));
}


// ========================================================================
// ?OnActivate@idTarget_TestPlayerState@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD5AE8
// RVA : 0x00CD5AE8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_TestPlayerState::OnActivate(idTarget_TestPlayerState *this, idPlayer *activator)
{
  idPlayer *DebugPlayer; // r18
  idPlayer *PlayerFromEntity; // r19
  unsigned __int8 v5; // r20
  char v6; // r27
  char v7; // r26
  idInventoryCollection *v8; // r29
  int v9; // r28
  int v10; // r30
  idTarget_TestPlayerState::playerState_Inventory_t *v11; // r31
  int num; // r11
  unsigned __int8 v13; // r22
  char v14; // r27
  char v15; // r28
  int v16; // r30
  int v17; // r31
  idTarget_TestPlayerState::playerState_Job_t *v18; // r11
  idJob *InventoryItemByDeclName; // r3
  missionStatus_t status; // r10
  idTarget_TestPlayerState::playerState_Job_t *v21; // r11
  int maxStatus; // r11
  unsigned __int8 v23; // r23
  char v24; // r27
  char v25; // r26
  int v26; // r28
  int v27; // r30
  idTarget_TestPlayerState::playerState_GameState_t *list; // r11
  char v29; // r31
  unsigned int GameStateIntValue; // r3
  idTarget_TestPlayerState::playerState_GameState_t *v31; // r11
  idGameStateInt::gameStateIntCompare_t comparison; // r10
  unsigned int comparisonValue; // r11
  bool v34; // xer_ca
  int v35; // r9
  unsigned int v36; // r11
  unsigned __int8 v37; // r29
  int v38; // r30
  int v39; // r31
  bool v40; // r31
  idTownGarageManager *v41; // r3
  idTownGarageManager *v42; // r3
  bool v43; // r11
  bool v44; // r7
  bool v45; // r11
  bool v46; // r8
  bool v47; // r11
  bool v48; // r9
  bool v49; // r11
  bool v50; // r10
  bool v51; // r11
  const idDeclGameStateInt *givenGameStateInt; // r4

  DebugPlayer = activator;
  if ( this->useOnce && this->used )
    return;
  if ( activator == nullptr )
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: DebugPlayer);
  if ( PlayerFromEntity == nullptr )
    PlayerFromEntity = idGameLocal::GetDebugPlayer(this: gameLocal);
  v5 = 1;
  if ( this->requiredItemList.num <= 0 )
    goto LABEL_21;
  v5 = 0;
  v6 = 0;
  v7 = 1;
  v8 = DebugPlayer->GetInventory_2(this: DebugPlayer);
  if ( v8 != nullptr )
  {
    v9 = 0;
    if ( this->requiredItemList.num > 0 )
    {
      v10 = 0;
      do
      {
        v11 = &this->requiredItemList.list[v10];
        if ( idInventoryCollection::FindTotalInventoryItemCount(this: v8, decl: v11->requiredItem) < v11->requiredCount )
          v7 = 0;
        else
          v6 = 1;
        ++v9;
        ++v10;
      }
      while ( v9 < this->requiredItemList.num );
    }
    if ( this->anyItemActivates )
    {
      if ( v6 != 0 )
        goto LABEL_20;
      if ( this->anyItemActivates )
        goto LABEL_21;
    }
    if ( v7 == 0 )
      goto LABEL_21;
LABEL_20:
    v5 = 1;
    goto LABEL_21;
  }
  idLib::Warning(fmt: "idTarget_TestPlayerState activator does not have inventory %s", DebugPlayer->name.data);
LABEL_21:
  num = this->requiredJobsList.num;
  v13 = 1;
  if ( num >= 0 )
  {
    v13 = 0;
    v14 = 0;
    v15 = 1;
    v16 = 0;
    if ( num > 0 )
    {
      v17 = 0;
      do
      {
        v18 = &this->requiredJobsList.list[v17];
        if ( v18->job.len != 0 )
        {
          InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(
                                      this: &PlayerFromEntity->jobManager,
                                      jobName: v18->job.data);
          status = JOBSTATUS_NONE;
          if ( InventoryItemByDeclName != nullptr )
            status = InventoryItemByDeclName->status;
          v21 = &this->requiredJobsList.list[v17];
          if ( status >= v21->minStatus )
          {
            maxStatus = v21->maxStatus;
            if ( maxStatus <= 0 || status <= maxStatus )
              v14 = 1;
            else
              v15 = 0;
          }
          else
          {
            v15 = 0;
          }
        }
        else
        {
          idLib::Warning(fmt: "idTarget_TestPlayerState null job decl in job test at %d", v16);
        }
        ++v16;
        ++v17;
      }
      while ( v16 < this->requiredJobsList.num );
    }
    if ( !this->anyJobActivates )
      goto LABEL_38;
    if ( v14 != 0 )
    {
LABEL_39:
      v13 = 1;
      goto LABEL_40;
    }
    if ( !this->anyJobActivates )
    {
LABEL_38:
      if ( v15 != 0 )
        goto LABEL_39;
    }
  }
LABEL_40:
  v23 = 1;
  if ( this->requiredGameStateIntList.num <= 0 )
    goto LABEL_60;
  v23 = 0;
  v24 = 0;
  v25 = 1;
  v26 = 0;
  v27 = 0;
  do
  {
    list = this->requiredGameStateIntList.list;
    if ( list[v27].gameStateInt == nullptr )
    {
      idLib::Warning(fmt: "idTrigger_TestPlayerState null game state decl at %d", v26);
      goto LABEL_54;
    }
    v29 = 0;
    GameStateIntValue = idJobManager::GetGameStateIntValue(
                          this: &PlayerFromEntity->jobManager,
                          gameState: list[v27].gameStateInt);
    v31 = &this->requiredGameStateIntList.list[v27];
    comparison = v31->comparison;
    switch ( comparison )
    {
      case GAMESTATEINT_LESS_THAN:
        comparisonValue = v31->comparisonValue;
        v34 = GameStateIntValue >= comparisonValue;
        v35 = ~(comparisonValue ^ GameStateIntValue);
LABEL_49:
        v29 = ((v35 < 0) + v34) & 1;
        break;
      case GAMESTATEINT_EQUAL:
        v29 = (_cntlzw(v31->comparisonValue - GameStateIntValue) & 0x20) != 0;
        break;
      case GAMESTATEINT_GREATER_THAN:
        v36 = v31->comparisonValue;
        v34 = v36 >= GameStateIntValue;
        v35 = ~(GameStateIntValue ^ v36);
        goto LABEL_49;
      default:
        break;
    }
    if ( v29 != 0 )
      v24 = 1;
    else
      v25 = 0;
LABEL_54:
    ++v26;
    ++v27;
  }
  while ( v26 < this->requiredGameStateIntList.num );
  if ( !this->anyGameStateIntActivate )
    goto LABEL_58;
  if ( v24 != 0 )
  {
LABEL_59:
    v23 = 1;
  }
  else if ( !this->anyGameStateIntActivate )
  {
LABEL_58:
    if ( v25 != 0 )
      goto LABEL_59;
  }
LABEL_60:
  v37 = 1;
  v38 = 0;
  if ( this->requiredDLCStateList.num > 0 )
  {
    v39 = 0;
    while ( idGameLocal::IsDLCStateActive(this: gameLocal, dlcState: this->requiredDLCStateList.list[v39]) )
    {
      ++v38;
      ++v39;
      if ( v38 >= this->requiredDLCStateList.num )
        goto LABEL_66;
    }
    v37 = 0;
  }
LABEL_66:
  v40 = true;
  if ( gameLocal->spawnIds.ptr[this->verifyGarageManager.spawnId.value & 0x1FFF] == this->verifyGarageManager.spawnId.value >> 13 )
  {
    v41 = (idTownGarageManager *)gameLocal->entities.ptr[this->verifyGarageManager.spawnId.value & 0x1FFF];
    if ( v41 != nullptr )
      v42 = idTownGarageManager::CastTo(c: v41);
    else
      v42 = nullptr;
    v40 = !__CFADD__(v42->vehicles.num - 1, -2147483647);
  }
  v43 = v37;
  if ( this->fireOnDLCStateFail )
    v43 = (_cntlzw(v37) & 0x20) != 0;
  v44 = v43;
  v45 = v5;
  if ( this->fireOnInventoryFail )
    v45 = (_cntlzw(v5) & 0x20) != 0;
  v46 = v45;
  v47 = v13;
  if ( this->fireOnJobFail )
    v47 = (_cntlzw(v13) & 0x20) != 0;
  v48 = v47;
  v49 = v23;
  if ( this->fireOnGameStateFail )
    v49 = (_cntlzw(v23) & 0x20) != 0;
  v50 = v49;
  v51 = v40;
  if ( this->fireOnGarageManagerFail )
    v51 = (_cntlzw(v40) & 0x20) != 0;
  if ( v44 && v46 && v48 && v50 && v51 )
  {
    this->ActivateTargets(this, a2: DebugPlayer);
    givenGameStateInt = this->givenGameStateInt;
    this->used = true;
    if ( givenGameStateInt != nullptr )
      idJobManager::SetGameStateIntValue(
        this: &PlayerFromEntity->jobManager,
        gameState: givenGameStateInt,
        stateValue: 1);
  }
}


// ========================================================================
// ?OnActivate@idTarget_StartSoundShader@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD6018
// RVA : 0x00CD6018
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_StartSoundShader::OnActivate(idTarget_StartSoundShader *this, idEntity *activator)
{
  soundShaderFlags_t v3; // r25
  const idDeclVoiceOver *voToPlay; // r11
  int v5; // r4
  int v6; // r28
  int v7; // r3
  idAI2 *Target; // r31
  idAI2 *v9; // r3
  idList<idEventReceiver *,5> *v10; // r10
  const idDeclVoiceOver *v11; // r11
  const idVoiceTrack *v12; // r11
  idPresentable *presentable; // r5
  const idDeclVoiceOver *v14; // r6
  int v15; // r26
  int v16; // r27
  int value; // r9
  idEntity *v18; // r3
  idEntity *v19; // r31
  const idDeclVoiceOver *v20; // r11
  const idVoiceTrack *v21; // r11
  idPresentable *v22; // r5
  const idDeclVoiceOver *v23; // r6
  signed int num; // r11
  int v25; // r11
  unsigned int seed; // r8
  unsigned int v27; // r4
  int v28; // r3
  unsigned int v29; // r6
  int v30; // r9
  idEntity *v31; // r3
  idEntity *v32; // r3
  int v33; // r30
  int v34; // r31
  int v35; // r9
  idEntity *v36; // r3
  idEntity *v37; // r3
  _BYTE v38[20]; // [sp+70h] [-D0h] BYREF
  idStrId v39[4]; // [sp+90h] [-B0h] BYREF
  _DWORD v40[5]; // [sp+A0h] [-A0h] BYREF
  idEventReceiver v41; // [sp+C0h] [-80h] BYREF
  const idEventDef *v42; // [sp+E0h] [-60h]
  int v43; // [sp+E4h] [-5Ch]
  const idEventArg *v44; // [sp+E8h] [-58h]
  const idEventArg *v45; // [sp+ECh] [-54h]
  int v46; // [sp+F0h] [-50h]

  v3 = 0;
  if ( this->globalSound )
    v3 = SSF_GLOBAL;
  voToPlay = this->voToPlay;
  if ( voToPlay != nullptr && (v5 = voToPlay->tracks.num) > 0 )
  {
    v6 = 0;
    if ( v5 > 1 )
      v6 = idRandom2::RandomInt(this: &clientGame->random, max: v5);
    if ( this->randomizeTarget )
    {
      v7 = idRandom2::RandomInt(this: &clientGame->random, max: this->targets.num);
      Target = (idAI2 *)idEntity::GetTarget(this, i: v7);
      v9 = idAI2::CastTo(c: Target);
      if ( v9 != nullptr )
      {
        idAIVoiceController::PlayVoiceOver(
          this: &v9->aiVolatile.voiceController,
          ai: v9,
          vo: this->voToPlay,
          priority: AIVOICEPRIORITY_MED,
          samePriorityInterupts: true);
      }
      else if ( Target != nullptr )
      {
        if ( Target->RespondsTo(this: Target, a2: &EV_StartVoiceOver) )
        {
          v10 = (idList<idEventReceiver *,5> *)this->voToPlay;
          HIBYTE(v40[0]) = 105;
          v40[1] = 1;
          HIBYTE(v41.__vftable) = 100;
          v41.listenerList = v10;
          HIBYTE(v42) = 105;
          v43 = 0;
          memcpy(Dst: v38, Src: v40, Size: sizeof(v38));
          idEventReceiver::ProcessEvent(
            this: &v41,
            result: (idEventArg *)Target,
            ev: v42,
            arg1: v44,
            arg2: v45,
            arg3: (const idEventArg *)__ROL4__(v46, 32));
        }
        else
        {
          v11 = this->voToPlay;
          if ( v6 < 0 || v6 >= v11->tracks.num )
            v12 = nullptr;
          else
            v12 = v11->tracks.list[v6];
          idEntity::StartSoundShader(
            this: Target,
            channel: SND_CHANNEL_MUSIC2,
            shader: v12->soundShader,
            soundShaderFlags: v3,
            peerMask: 0xFFu);
          presentable = Target->presentable;
          if ( presentable != nullptr )
          {
            v14 = this->voToPlay;
            v39[0] = this->fromWho;
            idGameLocal::PlayedVoiceOver(
              this: gameLocal,
              whoStartedMe: nullptr,
              target: presentable,
              vo: v14,
              voiceTrackIndex: v6,
              whoStartedMeText: v39);
          }
        }
      }
    }
    else
    {
      v15 = 0;
      if ( this->targets.num > 0 )
      {
        v16 = 0;
        do
        {
          value = this->targets.list[v16].spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
            && (v18 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v19 = idEntity::CastTo(c: v18);
          }
          else
          {
            v19 = nullptr;
          }
          if ( v19 != nullptr )
          {
            v20 = this->voToPlay;
            if ( v6 < 0 || v6 >= v20->tracks.num )
              v21 = nullptr;
            else
              v21 = v20->tracks.list[v6];
            idEntity::StartSoundShader(
              this: v19,
              channel: SND_CHANNEL_MUSIC2,
              shader: v21->soundShader,
              soundShaderFlags: v3,
              peerMask: 0xFFu);
            v22 = v19->presentable;
            if ( v22 != nullptr )
            {
              v23 = this->voToPlay;
              v39[0] = this->fromWho;
              idGameLocal::PlayedVoiceOver(
                this: gameLocal,
                whoStartedMe: nullptr,
                target: v22,
                vo: v23,
                voiceTrackIndex: v6,
                whoStartedMeText: v39);
            }
          }
          ++v15;
          ++v16;
        }
        while ( v15 < this->targets.num );
      }
    }
  }
  else
  {
    num = this->targets.num;
    if ( this->randomizeTarget )
    {
      if ( num != 0 )
      {
        seed = clientGame->random.seed;
        __twllei(num, 0);
        v27 = 1664525 * seed + 1013904223;
        clientGame->random.seed = v27;
        v28 = (v27 >> 10) & 0x7FFF;
        v29 = num & ~(__ROL4__(v28, 1) - 1);
        v25 = v28 % num;
        __twlgei(v29, 0xFFFFFFFF);
      }
      else
      {
        v25 = 0;
      }
      if ( v25 < this->targets.num
        && (v30 = this->targets.list[v25].spawnId.value, gameLocal->spawnIds.ptr[v30 & 0x1FFF] == v30 >> 13)
        && (v31 = gameLocal->entities.ptr[this->targets.list[v25].spawnId.value & 0x1FFF]) != nullptr )
      {
        v32 = idEntity::CastTo(c: v31);
      }
      else
      {
        v32 = nullptr;
      }
      if ( v32 != nullptr )
        idEntity::StartSoundShader(
          this: v32,
          channel: SND_CHANNEL_ANY,
          shader: this->soundToPlay,
          soundShaderFlags: v3,
          peerMask: 0xFFu);
    }
    else
    {
      v33 = 0;
      if ( num > 0 )
      {
        v34 = 0;
        do
        {
          v35 = this->targets.list[v34].spawnId.value;
          if ( gameLocal->spawnIds.ptr[v35 & 0x1FFF] == v35 >> 13
            && (v36 = gameLocal->entities.ptr[v35 & 0x1FFF]) != nullptr )
          {
            v37 = idEntity::CastTo(c: v36);
          }
          else
          {
            v37 = nullptr;
          }
          if ( v37 != nullptr )
            idEntity::StartSoundShader(
              this: v37,
              channel: SND_CHANNEL_ANY,
              shader: this->soundToPlay,
              soundShaderFlags: v3,
              peerMask: 0xFFu);
          ++v33;
          ++v34;
        }
        while ( v33 < this->targets.num );
      }
    }
  }
}


// ========================================================================
// ?OnActivate@idTarget_ForceDormancy@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD6488
// RVA : 0x00CD6488
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ForceDormancy::OnActivate(idTarget_ForceDormancy *this, idEntity *activator)
{
  int v3; // r29
  int v4; // r30
  int value; // r9
  idEntity *v6; // r3
  idEntity *v7; // r3

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
      if ( v7 != nullptr )
        idEntity::ForceDormancy(this: v7, dormant: this->dormant, durationMS: this->durationMS);
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_MakeActivatable@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD6538
// RVA : 0x00CD6538
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_MakeActivatable::OnActivate(idTarget_MakeActivatable *this, idEntity *activator)
{
  int v3; // r29
  int v4; // r30
  int value; // r9
  idEntity *v6; // r3
  idEntity *v7; // r3

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
      if ( v7 != nullptr )
        idEntity::SetIsActivatable(this: v7, activatable: this->makeActivatable);
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_EnableBlink@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD65E0
// RVA : 0x00CD65E0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_EnableBlink::OnActivate(idTarget_EnableBlink *this, idEntity *activator)
{
  int v3; // r28
  int v4; // r29
  int value; // r9
  idEntity *v6; // r3
  idCombiner *v7; // r31
  idUse *v8; // r3
  idProp_Usable *v9; // r3
  idCombiner *v10; // r3
  unsigned int enableBlink; // r11
  int v12; // [sp+50h] [-70h]

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
        v7 = (idCombiner *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      if ( v7 != nullptr )
      {
        v8 = idUse::CastTo(c: v7);
        if ( v8 != nullptr )
        {
          idUse::SetNoBlink(this: v8, noBlink_: (_cntlzw(this->enableBlink) & 0x20) != 0);
        }
        else
        {
          v9 = idProp_Usable::CastTo(c: (idProp_Usable *)v7);
          if ( v9 != nullptr )
          {
            idProp_Usable::SetNoBlink(this: v9, noBlink_: (_cntlzw(this->enableBlink) & 0x20) != 0);
          }
          else
          {
            v10 = idCombiner::CastTo(c: v7);
            enableBlink = this->enableBlink;
            if ( v10 != nullptr )
            {
              idCombiner::SetNoBlink(this: v10, noBlink_: (_cntlzw(enableBlink) & 0x20) != 0);
            }
            else
            {
              HIBYTE(v12) = 105;
              idEventReceiver::PostEventMS(
                this: v7,
                ev: &EV_SetHighlight,
                time: v12,
                arg1: (const idEventArg *)(enableBlink != 0));
            }
          }
        }
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_SetUsable@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD6740
// RVA : 0x00CD6740
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_SetUsable::OnActivate(idTarget_SetUsable *this, idEntity *activator)
{
  int v3; // r29
  int v4; // r30
  int value; // r9
  idEntity *v6; // r3
  idEntity *v7; // r3
  int v8; // [sp+50h] [-50h]
  const idEventArg *v9; // [sp+58h] [-48h]

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
      if ( v7 != nullptr )
      {
        HIBYTE(v8) = 105;
        idEventReceiver::PostEventMS(this: v7, ev: &EV_SetUsable, time: v8, arg1: v9);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_Turret_BlockCooldown@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD6818
// RVA : 0x00CD6818
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Turret_BlockCooldown::OnActivate(idTarget_Turret_BlockCooldown *this, idEntity *activator)
{
  int v3; // r29
  int v4; // r30
  int value; // r9
  idEntity *v6; // r3
  idEntity *v7; // r3
  int v8; // [sp+50h] [-50h]
  const idEventArg *v9; // [sp+58h] [-48h]

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
      if ( v7 != nullptr )
      {
        HIBYTE(v8) = 105;
        idEventReceiver::PostEventMS(this: v7, ev: &EV_SetCooldownBlocked, time: v8, arg1: v9);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_Door@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD68F0
// RVA : 0x00CD68F0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Door::OnActivate(idTarget_Door *this, idEntity *activator)
{
  int v4; // r27
  int v5; // r28
  int value; // r9
  idEntity *v7; // r3
  idDoor_Base *v8; // r3
  idDoor_Base *v9; // r3
  unsigned __int8 *v10; // r31
  idTarget_Door::setting_t locked; // r11
  idDoor_Base_vtbl *v12; // r23
  char v13; // r8
  idTarget_Door::setting_t playerUsable; // r11
  unsigned int v15; // r11
  idTarget_Door::setting_t forceUnusable; // r11
  unsigned int v17; // r11
  idTarget_Door::setting_t open; // r11
  char v19; // r3
  const idEntity *v20; // r4
  idEventArg *v21; // r3
  const idEventDef *v22; // r4
  idEventArg v23[5]; // [sp+50h] [-70h] BYREF

  v4 = 0;
  if ( this->targets.num > 0 )
  {
    v5 = 0;
    do
    {
      value = this->targets.list[v5].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v8 = (idDoor_Base *)idEntity::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      v9 = idDoor_Base::CastTo(c: v8);
      v10 = (unsigned __int8 *)v9;
      if ( v9 == nullptr )
        goto LABEL_29;
      locked = this->locked;
      if ( locked != KEEP )
      {
        if ( locked == TOGGLE )
        {
          v12 = v9->__vftable;
          v13 = _cntlzw(v9->IsLocked(this: v9));
          v12->SetLocked(this: (idDoor_Base *)v10, a2: (v13 & 0x20) != 0, a3: activator);
        }
        else
        {
          v9->SetLocked(this: v9, a2: (_cntlzw(locked - 1) & 0x20) != 0, a3: activator);
        }
      }
      playerUsable = this->playerUsable;
      if ( playerUsable != KEEP )
      {
        if ( playerUsable == TOGGLE )
          v15 = v10[5208];
        else
          v15 = playerUsable - 1;
        v10[5208] = (_cntlzw(v15) & 0x20) != 0;
      }
      forceUnusable = this->forceUnusable;
      if ( forceUnusable != KEEP )
      {
        if ( forceUnusable == TOGGLE )
          v17 = v10[5206];
        else
          v17 = forceUnusable - 1;
        v10[5206] = (_cntlzw(v17) & 0x20) != 0;
      }
      open = this->open;
      if ( open == KEEP )
        goto LABEL_29;
      if ( open == TOGGLE )
      {
        v19 = (*(int (__fastcall **)(unsigned __int8 *))(*(_DWORD *)v10 + 672))(a1: v10);
        v20 = activator;
        if ( v19 != 0 )
          goto LABEL_27;
      }
      else
      {
        v20 = activator;
        if ( open != SET_TRUE )
        {
LABEL_27:
          v21 = idEventArg::idEventArg(this: v23, data: v20);
          v22 = &EV_Close;
          goto LABEL_28;
        }
      }
      v21 = idEventArg::idEventArg(this: v23, data: v20);
      v22 = &EV_Open;
LABEL_28:
      idEventReceiver::PostEventMS(
        this: (idEventReceiver *)v10,
        ev: v22,
        time: *(_DWORD *)&v21->type,
        arg1: (const idEventArg *)v21->value.i);
LABEL_29:
      ++v4;
      ++v5;
    }
    while ( v4 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_UnlockDoor@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD6AE8
// RVA : 0x00CD6AE8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_UnlockDoor::OnActivate(idTarget_UnlockDoor *this, idEntity *activator)
{
  int v4; // r29
  int v5; // r31
  int value; // r9
  idEntity *v7; // r3
  idDoor_Base *v8; // r3
  idDoor_Base *v9; // r3

  v4 = 0;
  if ( this->targets.num > 0 )
  {
    v5 = 0;
    do
    {
      value = this->targets.list[v5].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v8 = (idDoor_Base *)idEntity::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      v9 = idDoor_Base::CastTo(c: v8);
      if ( v9 != nullptr )
        v9->SetLocked(this: v9, a2: false, a3: activator);
      ++v4;
      ++v5;
    }
    while ( v4 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_LockDoor@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD6BA8
// RVA : 0x00CD6BA8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_LockDoor::OnActivate(idTarget_LockDoor *this, idEntity *activator)
{
  int v4; // r29
  int v5; // r31
  int value; // r9
  idEntity *v7; // r3
  idDoor_Base *v8; // r3
  idDoor_Base *v9; // r3

  v4 = 0;
  if ( this->targets.num > 0 )
  {
    v5 = 0;
    do
    {
      value = this->targets.list[v5].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v8 = (idDoor_Base *)idEntity::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      v9 = idDoor_Base::CastTo(c: v8);
      if ( v9 != nullptr )
        v9->SetLocked(this: v9, a2: true, a3: activator);
      ++v4;
      ++v5;
    }
    while ( v4 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_DeactivateDoor@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD6C68
// RVA : 0x00CD6C68
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_DeactivateDoor::OnActivate(idTarget_DeactivateDoor *this, idEntity *activator)
{
  int v3; // r29
  int v4; // r31
  int value; // r9
  idEntity *v6; // r3
  idDoor_Base *v7; // r3
  idDoor_Base *v8; // r3

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
        v7 = (idDoor_Base *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      v8 = idDoor_Base::CastTo(c: v7);
      if ( v8 != nullptr )
        v8->forcedUnusable = true;
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?Think@idTarget_ShakeTrigger@@UAAXXZ
// EA  : 0x82CD6D10
// RVA : 0x00CD6D10
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ShakeTrigger::Think(idTarget_ShakeTrigger *this)
{
  int GameMs; // r3
  int num; // r11
  int v4; // r24
  int v5; // r25
  int value; // r9
  idEntity *v7; // r3
  idEntity *v8; // r29
  unsigned int seed; // r9
  unsigned int v10; // r6
  idEventArg *v11; // r3
  unsigned int v12; // [sp+54h] [-8Ch]
  idEventArg v13[6]; // [sp+60h] [-80h] BYREF

  if ( ((double (__fastcall *)(idSoundWorld *, int))clientGame->soundWorld->CurrentShakeAmplitude)(
         a1: clientGame->soundWorld,
         a2: -1) > this->shake
    && this->activateTime >= 0
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->activateTime )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    num = this->targets.num;
    v4 = 0;
    this->activateTime = (int)(float)(this->delay * (float)1000.0) + GameMs;
    if ( num > 0 )
    {
      v5 = 0;
      do
      {
        if ( v4 < this->targets.num
          && (value = this->targets.list[v5].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
          && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v8 = idEntity::CastTo(c: v7);
        }
        else
        {
          v8 = nullptr;
        }
        if ( v8 != nullptr )
        {
          v12 = (int)(float)(this->diversity * 1000.0);
          if ( v12 != 0 )
          {
            seed = clientGame->random.seed;
            __twllei(v12, 0);
            v10 = 1664525 * seed + 1013904223;
            clientGame->random.seed = v10;
            __twlgei(v12 & ~(__ROL4__((v10 >> 10) & 0x7FFF, 1) - 1), 0xFFFFFFFF);
          }
          v11 = idEventArg::idEventArg(this: v13, data: this);
          idEventReceiver::PostEventMS(
            this: v8,
            ev: &EV_Activate,
            time: *(_DWORD *)&v11->type,
            arg1: (const idEventArg *)LODWORD(v11->value.v[1]));
        }
        ++v4;
        ++v5;
      }
      while ( v4 < this->targets.num );
    }
  }
}


// ========================================================================
// ?OnActivate@idTarget_EnableAIEvent@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD6EF8
// RVA : 0x00CD6EF8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_EnableAIEvent::OnActivate(idTarget_EnableAIEvent *this, idEntity *activator)
{
  int num; // r11
  int v4; // r29
  int v5; // r30
  idGameLocal *v6; // r11
  bool v7; // zf
  int value; // r9
  idEntity *v9; // r3
  idEntity *v10; // r3
  const idEntity *v11; // r4

  num = this->targets.num;
  v4 = 0;
  if ( num > 0 )
  {
    v5 = 0;
    do
    {
      v7 = v4 >= num;
      v6 = gameLocal;
      if ( !v7
        && (value = this->targets.list[v5].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
        && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v10 = idEntity::CastTo(c: v9);
        v6 = gameLocal;
        v11 = v10;
      }
      else
      {
        v11 = nullptr;
      }
      idAIEventManager::EnableEvents(
        this: &v6->aiEventManager,
        ent: v11,
        eventClassFlags: this->eventClassFlags,
        enable: this->enableEvent);
      num = this->targets.num;
      ++v4;
      ++v5;
    }
    while ( v4 < num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_SwapFaction@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD6FB0
// RVA : 0x00CD6FB0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_SwapFaction::OnActivate(idTarget_SwapFaction *this, idEntity *activator)
{
  int num; // r27
  int v4; // r28
  int v5; // r31
  int value; // r9
  idEntity *v7; // r3
  idActor *v8; // r3
  idActor *v9; // r3
  int v10; // r9
  idEntity *v11; // r3
  idTurret *v12; // r3
  idTurret *v13; // r3
  idLinkList<idActor> *next; // r11
  idAI2 *owner; // r31
  const idDeclEntityDef *entityDef; // r11
  idFaction *v17; // r3
  idActor *v18; // r3
  const idDeclFaction *myFaction; // r4
  bool v20; // zf
  idAI2 *v21; // r3
  idLinkList<idActor> *v22; // r11
  idTarget_FakeEnemy *v23; // r3

  if ( this->targetFaction.myFaction != nullptr )
  {
    num = this->targets.num;
    if ( this->targetType.len != 0 || num == 0 )
    {
      next = gameLocal->actorEntities.next;
      if ( next != nullptr && next != gameLocal->actorEntities.head )
      {
        owner = (idAI2 *)next->owner;
        while ( owner != nullptr )
        {
          entityDef = owner->entityDef;
          if ( entityDef != nullptr
            && this->targetType.len != 0
            && idStr::Cmp(s1: entityDef->name.str, s2: this->targetType.data) == 0 )
          {
            v17 = owner->GetFaction(this: owner);
            myFaction = this->targetFaction.myFaction;
            v20 = v17->myFaction == myFaction;
            v18 = owner;
            if ( !v20 )
            {
              idActor::SetFaction(this: owner, faction: myFaction);
              v18 = owner;
            }
            idActor::SetRelationshipList(this: v18, list: &this->targetFaction.relationships);
            if ( (unsigned __int8)idAI2::IsTypeOf(c: owner) != 0 )
            {
              v21 = idAI2::CastTo(c: owner);
              idAI2::ClearAimFocus(this: v21);
            }
          }
          v22 = owner->actorNode.next;
          if ( v22 == nullptr || v22 == owner->actorNode.head )
            owner = nullptr;
          else
            owner = (idAI2 *)v22->owner;
        }
      }
    }
    else
    {
      v4 = 0;
      if ( num > 0 )
      {
        v5 = 0;
        do
        {
          if ( v4 < this->targets.num
            && (value = this->targets.list[v5].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
            && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v8 = (idActor *)idEntity::CastTo(c: v7);
          }
          else
          {
            v8 = nullptr;
          }
          v9 = idActor::CastTo(c: v8);
          if ( v9 != nullptr )
            idActor::SetFaction(this: v9, faction: this->targetFaction.myFaction);
          if ( v4 < this->targets.num
            && (v10 = this->targets.list[v5].spawnId.value, gameLocal->spawnIds.ptr[v10 & 0x1FFF] == v10 >> 13)
            && (v11 = gameLocal->entities.ptr[v10 & 0x1FFF]) != nullptr )
          {
            v12 = (idTurret *)idEntity::CastTo(c: v11);
          }
          else
          {
            v12 = nullptr;
          }
          v13 = idTurret::CastTo(c: v12);
          if ( v13 != nullptr )
            idFaction::SetDeclFaction(
              this: &v13->faction,
              faction: this->targetFaction.myFaction,
              clearRelationships: false);
          ++v4;
          ++v5;
        }
        while ( v4 < num );
      }
    }
  }
  else
  {
    idLib::Error(fmt: "'%s' has no faction decl set.\n", this->name.data);
    idTarget_FakeEnemy::Think(this: v23);
  }
}


// ========================================================================
// ?Think@idTarget_FakeEnemy@@UAAXXZ
// EA  : 0x82CD71E0
// RVA : 0x00CD71E0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_FakeEnemy::Think(idTarget_FakeEnemy *this)
{
  int activateTime; // r11
  int num; // r29
  int i; // r30
  idAI2 *Target; // r3
  idAI2 *v6; // r3

  activateTime = this->activateTime;
  if ( activateTime == 0 )
  {
LABEL_10:
    idEntity::BecomeInactive(this, flags: 1);
    return;
  }
  if ( this->lifeDuration > 0.0
    && activateTime > 0
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= (int)(float)((float)1000.0 * this->lifeDuration)
                                                                                                + this->activateTime )
  {
    num = this->targets.num;
    for ( i = 0; i < num; ++i )
    {
      Target = (idAI2 *)idEntity::GetTarget(this, i);
      v6 = idAI2::CastTo(c: Target);
      if ( v6 != nullptr )
        idAI2::ClearFakeEnemy(this: v6);
    }
    this->activateTime = 0;
    goto LABEL_10;
  }
}


// ========================================================================
// ?OnActivate@idTarget_FakeEnemy@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD72B0
// RVA : 0x00CD72B0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_FakeEnemy::OnActivate(idTarget_FakeEnemy *this, idEntity *activator)
{
  int num; // r27
  int v4; // r29
  int v5; // r30
  int value; // r9
  idEntity *v7; // r3
  idAI2 *v8; // r3
  idAI2 *v9; // r3

  num = this->targets.num;
  v4 = 0;
  if ( num > 0 )
  {
    v5 = 0;
    do
    {
      if ( v4 < this->targets.num
        && (value = this->targets.list[v5].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
        && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v8 = (idAI2 *)idEntity::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      v9 = idAI2::CastTo(c: v8);
      if ( v9 != nullptr )
        idAI2::SetFakeEnemy(this: v9, entity: this);
      ++v4;
      ++v5;
    }
    while ( v4 < num );
  }
  if ( this->lifeDuration > 0.0 )
  {
    this->activateTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idEntity::BecomeActive(this, flags: 1);
  }
}


// ========================================================================
// ?OnActivate@idTarget_ClearFakeEnemy@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD7398
// RVA : 0x00CD7398
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ClearFakeEnemy::OnActivate(idTarget_ClearFakeEnemy *this, idEntity *activator)
{
  int num; // r27
  int v4; // r29
  int v5; // r31
  int value; // r9
  idEntity *v7; // r3
  idAI2 *v8; // r3
  idAI2 *v9; // r3

  num = this->targets.num;
  v4 = 0;
  if ( num > 0 )
  {
    v5 = 0;
    do
    {
      if ( v4 < this->targets.num
        && (value = this->targets.list[v5].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
        && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v8 = (idAI2 *)idEntity::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      v9 = idAI2::CastTo(c: v8);
      if ( v9 != nullptr )
        idAI2::ClearFakeEnemy(this: v9);
      ++v4;
      ++v5;
    }
    while ( v4 < num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_PlayVoiceOver@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD7440
// RVA : 0x00CD7440
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_PlayVoiceOver::OnActivate(idTarget_PlayVoiceOver *this, idEntity *activator)
{
  int v3; // r28
  int v4; // r29
  int value; // r9
  idEntity *v6; // r3
  idEventArg *v7; // r31
  BOOL playInCombat; // r11
  const idDeclVoiceOver *voiceOver; // r10
  _BYTE v10[20]; // [sp+70h] [-100h] BYREF
  _DWORD v11[5]; // [sp+90h] [-E0h] BYREF
  const idEventDef *v12; // [sp+B0h] [-C0h]
  int v13; // [sp+B4h] [-BCh]
  const idEventArg *v14; // [sp+B8h] [-B8h]
  const idEventArg *v15; // [sp+BCh] [-B4h]
  int v16; // [sp+C0h] [-B0h]
  char v17; // [sp+D0h] [-A0h]
  const idDeclVoiceOver *v18; // [sp+D4h] [-9Ch]
  idEventReceiver v19[10]; // [sp+F0h] [-80h] BYREF

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
        v7 = (idEventArg *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      if ( v7 != nullptr
        && (*(unsigned __int8 (__fastcall **)(idEventArg *, idEventDef *))(*(_DWORD *)&v7->type + 12))(
             a1: v7,
             a2: &EV_StartVoiceOver) != 0 )
      {
        playInCombat = this->playInCombat;
        HIBYTE(v11[0]) = 105;
        voiceOver = this->voiceOver;
        v17 = 100;
        HIBYTE(v12) = 105;
        v11[1] = playInCombat;
        v13 = 0;
        v18 = voiceOver;
        memcpy(Dst: v10, Src: v11, Size: sizeof(v10));
        idEventReceiver::ProcessEvent(
          this: v19,
          result: v7,
          ev: v12,
          arg1: v14,
          arg2: v15,
          arg3: (const idEventArg *)__ROL4__(v16, 32));
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?OnActivate@idTarget_HideShowMesh@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD7588
// RVA : 0x00CD7588
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_HideShowMesh::OnActivate(idTarget_HideShowMesh *this, idEntity *activator)
{
  int v3; // r27
  int v4; // r28
  int value; // r9
  idEntity *v6; // r3
  idAnimatedEntity *v7; // r3
  idAnimatedEntity *v8; // r3
  idEntity *v9; // r31
  idTreeAnimator *TreeAnimatorFromPresentable; // r30
  idPresentable *presentable; // r3
  int MeshIndex; // r3
  bool *list; // r11

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
      v9 = v8;
      if ( v8 != nullptr )
      {
        TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v8);
        if ( TreeAnimatorFromPresentable != nullptr )
        {
          presentable = v9->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this: v9);
            presentable = v9->presentable;
          }
          idPresentable::UpdateModelTransform(this: presentable);
          MeshIndex = idTreeAnimator::GetMeshIndex(this: TreeAnimatorFromPresentable, meshName: this->meshName.data);
          if ( MeshIndex < 0 )
          {
            idLib::Warning(
              fmt: "clipMeshIndex invalid for %s on %s targeted by %s",
              this->meshName.data,
              v9->name.data,
              this->name.data);
          }
          else
          {
            list = TreeAnimatorFromPresentable->meshVisibility.list;
            list[MeshIndex] = !this->hide;
          }
        }
        else
        {
          idLib::Warning(fmt: "no tree animator on target %s on %s", v9->name.data, this->name.data);
        }
      }
      else
      {
        idLib::Warning(fmt: "non idanimatedEntity target on idTarget_HideShowMesh %s", this->name.data);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ??0idTarget_DummyFire@@QAA@XZ
// EA  : 0x82CD76F0
// RVA : 0x00CD76F0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_DummyFire *__fastcall idTarget_DummyFire::idTarget_DummyFire(idTarget_DummyFire *this)
{
  idEntity::idEntity(this);
  this->numShots = -1;
  this->arcAngle = -1.0;
  this->__vftable = (idTarget_DummyFire_vtbl *)&idTarget_DummyFire::`vftable';
  this->minRange = 0.0;
  this->weaponDecl = nullptr;
  this->maxRange = -1.0;
  this->effectsDecl = nullptr;
  this->scatter = 0.0;
  this->ammoIndex = 0;
  this->fireDuration = 10.0;
  this->shouldReset = true;
  this->burstDuration = 2.0;
  this->ignoreDeadAI = false;
  this->burstPause = 0.5;
  this->targetsInOrder = false;
  this->minTargetTime = 2.0;
  this->maxTargetTime = 4.0;
  this->slaves.list = nullptr;
  this->slaves.granularity = 0;
  this->slaves.memTag = 5;
  this->slaves.listStatic = 0;
  this->slaves.size = 0;
  this->slaves.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->slaves);
  this->weapon = nullptr;
  this->projDecl = nullptr;
  this->currentTarget.spawnId.value = 0x1FFF;
  this->bSlave = false;
  this->currentShotsLeft = 0;
  this->nextProjectileTime = 0;
  this->nextBurstChange = 0;
  this->bIsFiring = true;
  this->bBulletsFly = false;
  this->fireDurationEnd = 0;
  this->nextTargetTime = 0;
  this->nextTargetIndex = 0;
  this->fireChannel = 0;
  this->blockFlags = BLOCKED_WORLD;
  return this;
}


// ========================================================================
// __unwind$515875
// EA  : 0x82CD7808
// RVA : 0x00CD7808
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_515875()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// ?SetTargetFromMaster@idTarget_DummyFire@@AAAXPAVidEntity@@@Z
// EA  : 0x82CD7830
// RVA : 0x00CD7830
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_DummyFire::SetTargetFromMaster(idTarget_DummyFire *this, idEntity *_pTarget)
{
  int value; // r10
  idEntity *v5; // r3
  idEntity *v6; // r3
  int GameMs; // r30
  double v8; // fp1
  double burstDuration; // fp9

  value = this->currentTarget.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = idEntity::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  if ( _pTarget != v6 )
  {
    idEntity::BecomeActive(this, flags: 1);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v8 = RandomFloat();
    burstDuration = this->burstDuration;
    this->nextTargetTime = (int)(float)((float)((float)((float)(this->maxTargetTime - this->minTargetTime) * (float)v8)
                                              + this->minTargetTime)
                                      * (float)1000.0)
                         + GameMs;
    if ( burstDuration <= 0.0 )
      this->nextBurstChange = (int)1000.0 + GameMs;
    else
      this->nextBurstChange = (int)(float)(1000.0 * (float)((float)(RandomFloat() - (float)1.0) + this->burstDuration))
                            + GameMs;
    if ( _pTarget != nullptr )
      this->currentTarget.spawnId.value = (gameLocal->spawnIds.ptr[_pTarget->entityNumber] << 13)
                                        | _pTarget->entityNumber;
    else
      this->currentTarget.spawnId.value = 0x1FFF;
    this->bSlave = true;
    this->bIsFiring = true;
  }
}


// ========================================================================
// ?Event_SetFireTarget@idTarget_DummyFire@@QAA?AVeventBool@@PAVidEntity@@@Z
// EA  : 0x82CD79B0
// RVA : 0x00CD79B0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_DummyFire *__fastcall idTarget_DummyFire::Event_SetFireTarget(
        idTarget_DummyFire *this,
        eventBool *result,
        idEntity *target)
{
  bool v5; // r4

  if ( target != nullptr )
  {
    v5 = true;
    *(_DWORD *)&result[892].value = (gameLocal->spawnIds.ptr[target->entityNumber] << 13) | target->entityNumber;
  }
  else
  {
    v5 = false;
  }
  eventBool::eventBool((eventBool *)this, b: v5);
  return this;
}


// ========================================================================
// ??0idTarget_DynamicVehicleAiController@@QAA@XZ
// EA  : 0x82CD7A28
// RVA : 0x00CD7A28
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_DynamicVehicleAiController *__fastcall idTarget_DynamicVehicleAiController::idTarget_DynamicVehicleAiController(
        idTarget_DynamicVehicleAiController *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_DynamicVehicleAiController_vtbl *)&idTarget_DynamicVehicleAiController::`vftable';
  this->firstVehicles.list = nullptr;
  this->firstVehicles.granularity = 0;
  this->firstVehicles.memTag = 5;
  this->firstVehicles.listStatic = 0;
  this->firstVehicles.size = 0;
  this->firstVehicles.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->firstVehicles);
  this->specialVehicles.list = nullptr;
  this->specialVehicles.granularity = 0;
  this->specialVehicles.memTag = 5;
  this->specialVehicles.listStatic = 0;
  this->specialVehicles.size = 0;
  this->specialVehicles.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->specialVehicles);
  this->spawnPositions.list = nullptr;
  this->spawnPositions.granularity = 0;
  this->spawnPositions.memTag = 5;
  this->spawnPositions.listStatic = 0;
  this->spawnPositions.size = 0;
  this->spawnPositions.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->spawnPositions);
  this->dynamicJob = nullptr;
  this->numNormalVehicles = 0;
  this->allnormalDeadBeforSpecial = false;
  this->penaltyForSpawnBehind = 1.5;
  this->tooCloseToSpawn = 4500.0;
  this->tooFarToCheckVis = 15000.0;
  this->afterVehicles.list = nullptr;
  this->afterVehicles.granularity = 0;
  this->afterVehicles.memTag = 5;
  this->afterVehicles.listStatic = 0;
  this->afterVehicles.size = 0;
  this->afterVehicles.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->afterVehicles);
  this->numSpecialVehicles = 0;
  this->secondsTillAfterVehicles = 240;
  this->vehiclesKilled = 0;
  this->vehiclesActive = 0;
  this->player.spawnId.value = 0x1FFF;
  this->hasBeenActivated = false;
  this->isActive = false;
  this->distances.list = nullptr;
  this->distances.granularity = 0;
  this->distances.memTag = 5;
  this->distances.listStatic = 0;
  this->distances.size = 0;
  this->distances.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->distances);
  this->dots.list = nullptr;
  this->dots.granularity = 0;
  this->dots.memTag = 5;
  this->dots.listStatic = 0;
  this->dots.size = 0;
  this->dots.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->dots);
  this->splineDistances.list = nullptr;
  this->splineDistances.granularity = 0;
  this->splineDistances.memTag = 5;
  this->splineDistances.listStatic = 0;
  this->splineDistances.size = 0;
  this->splineDistances.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splineDistances);
  return this;
}


// ========================================================================
// __unwind$516199
// EA  : 0x82CD7BA0
// RVA : 0x00CD7BA0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_516199()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$516200
// EA  : 0x82CD7BC8
// RVA : 0x00CD7BC8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_516200()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 800));
}


// ========================================================================
// __unwind$516201
// EA  : 0x82CD7BF4
// RVA : 0x00CD7BF4
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_516201()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 816));
}


// ========================================================================
// __unwind$516202
// EA  : 0x82CD7C20
// RVA : 0x00CD7C20
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_516202()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 832));
}


// ========================================================================
// __unwind$516203
// EA  : 0x82CD7C4C
// RVA : 0x00CD7C4C
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_516203()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 872));
}


// ========================================================================
// __unwind$516204
// EA  : 0x82CD7C78
// RVA : 0x00CD7C78
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_516204()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 912));
}


// ========================================================================
// __unwind$516205
// EA  : 0x82CD7CA4
// RVA : 0x00CD7CA4
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_516205()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 928));
}


// ========================================================================
// ?TestSpawnPos@idTarget_DynamicVehicleAiController@@AAA_NHPAVidVehicleAI@@@Z
// EA  : 0x82CD7E80
// RVA : 0x00CD7E80
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

BOOL __fastcall idTarget_DynamicVehicleAiController::TestSpawnPos(
        idTarget_DynamicVehicleAiController *this,
        int testIndex,
        idVehicleAI *vai)
{
  idVehicle_Car *v6; // r3
  idEntity *v7; // r26
  double tooCloseToSpawn; // fp28
  double v9; // fp30
  double v10; // fp31
  double v11; // fp29
  idInfo *v12; // r3
  float y; // r6
  float z; // r5
  BOOL v15; // r25
  idEntityPtr<idPlayer> *p_player; // r31
  idPlayer *v17; // r3
  idPlayer *v18; // r3
  idVec3 *v19; // r3
  float *LastViewOrigin; // r3
  double v21; // fp12
  idPresentable *presentable; // r3
  float *v23; // r3
  idPlayer *v24; // r3
  int EntitiesTouchingBounds; // r27
  idPhysics *Physics; // r3
  int v27; // r3
  char *v28; // r10
  _DWORD *v29; // r9
  int i; // ctr
  int v31; // r29
  int *j; // r30
  int v33; // r9
  idEntity *v34; // r31
  idPhysics *v35; // r3
  int v36; // r3
  char *v37; // r10
  _DWORD *v38; // r11
  int k; // ctr
  idPhysics *v40; // r3
  float *v41; // r3
  double v42; // fp8
  double v43; // fp6
  double v44; // fp5
  double v45; // fp3
  double v46; // fp2
  int v48; // [sp+8h] [-258h]
  bool v49; // [sp+Fh] [-251h]
  const char *v50; // [sp+10h] [-250h]
  int v51; // [sp+14h] [-24Ch]
  int v52; // [sp+18h] [-248h]
  int v53; // [sp+1Ch] [-244h]
  int v54; // [sp+20h] [-240h]
  int v55; // [sp+24h] [-23Ch]
  int v56; // [sp+28h] [-238h]
  int v57; // [sp+2Ch] [-234h]
  int v58; // [sp+30h] [-230h]
  int v59; // [sp+34h] [-22Ch]
  int v60; // [sp+38h] [-228h]
  int v61; // [sp+3Ch] [-224h]
  int v62; // [sp+40h] [-220h]
  int v63; // [sp+44h] [-21Ch]
  int v64; // [sp+48h] [-218h]
  int v65; // [sp+4Ch] [-214h]
  int v66; // [sp+50h] [-210h]
  int v67; // [sp+58h] [-208h]
  int v68; // [sp+60h] [-200h]
  char v69; // [sp+6Ch] [-1F4h] BYREF
  idBounds v70; // [sp+70h] [-1F0h] BYREF
  idVec3 v71; // [sp+88h] [-1D8h] BYREF
  char v72; // [sp+9Ch] [-1C4h] BYREF
  idBounds v73; // [sp+A0h] [-1C0h] BYREF
  idVec3 v74; // [sp+B8h] [-1A8h] BYREF
  idBounds v75; // [sp+D0h] [-190h] BYREF
  trace_t v76; // [sp+F0h] [-170h] BYREF
  int v77[42]; // [sp+170h] [-F0h] BYREF

  if ( testIndex < 0 || testIndex >= this->distances.num || vai == nullptr )
    return false;
  v6 = idVehicleAI::GetVehicleCar(this: vai) != nullptr
     ? idVehicleAI::GetVehicleCar(this: vai)
     : idVehicleAI::GetPrespawnVehicleCar(this: vai);
  v7 = v6;
  if ( v6 == nullptr )
    return false;
  tooCloseToSpawn = this->tooCloseToSpawn;
  v9 = (float)(this->tooFarToCheckVis * this->tooFarToCheckVis);
  v10 = this->distances.list[testIndex];
  v11 = this->dots.list[testIndex];
  v12 = idEntityPtr<idInfo>::operator->(this: &this->spawnPositions.list[testIndex]);
  y = v12->spawnPosition.y;
  z = v12->spawnPosition.z;
  v71.x = v12->spawnPosition.x;
  v71.y = y;
  v71.z = z;
  v15 = v10 >= (float)((float)tooCloseToSpawn * (float)tooCloseToSpawn);
  if ( v10 >= (float)((float)tooCloseToSpawn * (float)tooCloseToSpawn) && v10 < v9 && v11 > 0.0 )
  {
    p_player = &this->player;
    v17 = idEntityPtr<idPlayer>::operator->(this: p_player);
    if ( v17->IsDrivingVehicle(this: v17) )
    {
      v18 = idEntityPtr<idPlayer>::operator->(this: p_player);
      v19 = (idVec3 *)v18->GetVehicle_2(this: v18);
      LastViewOrigin = (float *)idVehicle::GetLastViewOrigin(this: (idVehicle *)&v70, result: v19);
      v74.x = *LastViewOrigin;
      v74.y = LastViewOrigin[1];
      v21 = LastViewOrigin[2];
    }
    else
    {
      presentable = idEntityPtr<idPlayer>::operator->(this: p_player)->presentable;
      v23 = presentable != nullptr ? (float *)presentable->GetPlayerInterface_2(this: presentable) : nullptr;
      v74.x = v23[11633];
      v74.y = v23[11634];
      v21 = v23[11635];
    }
    v74.z = v21;
    v24 = idEntityPtr<idPlayer>::operator->(this: p_player);
    idClip::Translation(
      this: (idClip *)&v70,
      result: &clientGame->clip,
      a3: &v76,
      start: &v74,
      end: &v71,
      clipModel: nullptr,
      startAxis: &mat3_identity,
      clipMask: 1,
      passEntityNumber: v48,
      moveClipModel: v49,
      userName: v50,
      a12: v51,
      a13: v52,
      a14: v53,
      a15: v54,
      a16: v55,
      a17: v56,
      a18: v57,
      a19: v58,
      a20: v59,
      a21: v60,
      a22: v61,
      a23: v62,
      a24: v63,
      a25: v64,
      a26: v65,
      a27: v66,
      a28: v24->entityNumber,
      a29: v67,
      a30: false,
      a31: v68,
      a32: 0);
    if ( v76.fraction >= 0.99000001 )
      v15 = false;
    if ( v15 )
    {
      v75.b[0].x = v71.x - (float)1500.0;
      v75.b[0].y = v71.y - (float)1500.0;
      v75.b[0].z = v71.z - (float)1500.0;
      v75.b[1].x = v71.x + (float)1500.0;
      v75.b[1].y = v71.y + (float)1500.0;
      v75.b[1].z = v71.z + (float)1500.0;
      v70.b[0] = v71;
      EntitiesTouchingBounds = idClip::GetEntitiesTouchingBounds(
                                 this: &clientGame->clip,
                                 bounds: &v75,
                                 clipMask: 197120,
                                 entityList: v77,
                                 maxCount: 32);
      Physics = idEntity::GetPhysics(this: v7);
      v27 = (int)Physics->GetBounds(this: Physics, a2: -1);
      v28 = &v72;
      v29 = (_DWORD *)(v27 - 4);
      for ( i = 6; i != 0; --i )
      {
        ++v29;
        v28 += 4;
        *(_DWORD *)v28 = *v29;
      }
      v31 = 0;
      v73.b[0].x = v73.b[0].x + v70.b[0].x;
      v73.b[0].y = v73.b[0].y + v70.b[0].y;
      v73.b[0].z = v73.b[0].z + v70.b[0].z;
      v73.b[1].x = v73.b[1].x + v70.b[0].x;
      v73.b[1].y = v73.b[1].y + v70.b[0].y;
      v73.b[1].z = v73.b[1].z + v70.b[0].z;
      if ( EntitiesTouchingBounds > 0 )
      {
        for ( j = v77; ; ++j )
        {
          v33 = *j + 21563;
          v34 = *((idEntity **)&gameLocal->__vftable + v33);
          if ( v34 != v7 )
          {
            v35 = idEntity::GetPhysics(this: *((idEntity **)&gameLocal->__vftable + v33));
            v36 = (int)v35->GetBounds(this: v35, a2: -1);
            v37 = &v69;
            v38 = (_DWORD *)(v36 - 4);
            for ( k = 6; k != 0; --k )
            {
              ++v38;
              v37 += 4;
              *(_DWORD *)v37 = *v38;
            }
            v40 = idEntity::GetPhysics(this: v34);
            v41 = (float *)v40->GetOrigin(this: v40, a2: 0);
            v42 = v41[1];
            v43 = v41[2];
            v44 = (float)(v41[1] + v70.b[0].y);
            v45 = (float)(v41[2] + v70.b[0].z);
            v46 = (float)(*v41 + v70.b[1].x);
            v70.b[0].x = *v41 + v70.b[0].x;
            v70.b[0].y = v44;
            v70.b[0].z = v45;
            v70.b[1].x = v46;
            v70.b[1].y = (float)v42 + v70.b[1].y;
            v70.b[1].z = (float)v43 + v70.b[1].z;
            if ( (unsigned __int8)idBounds::IntersectsBounds(this: &v73, a: &v70) != 0 )
              break;
          }
          if ( ++v31 >= EntitiesTouchingBounds )
            return v15;
        }
        return false;
      }
    }
  }
  return v15;
}


// ========================================================================
// ?CalcDistancesAndDots@idTarget_DynamicVehicleAiController@@AAAHXZ
// EA  : 0x82CD82D0
// RVA : 0x00CD82D0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

int __fastcall idTarget_DynamicVehicleAiController::CalcDistancesAndDots(idTarget_DynamicVehicleAiController *this)
{
  int num; // r4
  int v3; // r4
  int v4; // r4
  int value; // r10
  idPlayer *v6; // r3
  int v8; // r9
  idPlayer *v9; // r3
  idPlayer *v10; // r3
  bool v11; // r3
  int v12; // r11
  int v13; // r8
  int v14; // r5
  idPlayer *v15; // r3
  idPlayer *v16; // r3
  idEntity *v17; // r3
  idPhysics *Physics; // r3
  float *v19; // r3
  int v20; // r7
  double v21; // fp25
  double v22; // fp24
  double v23; // fp23
  idPlayer *v24; // r3
  idPlayer *v25; // r3
  idMat3 *v26; // r3
  float *LastViewAxis; // r3
  double v28; // fp28
  double v29; // fp27
  double v30; // fp26
  idPlayer *v31; // r3
  idPlayer *v32; // r3
  idPhysics *v33; // r3
  float *v34; // r3
  int v35; // r9
  idPlayer *v36; // r3
  idPlayer *v37; // r3
  idPresentable *presentable; // r3
  float *v39; // r3
  idNavSplinePathMgr *NavSplinePathMgr; // r28
  int v41; // r23
  int v42; // r27
  double v43; // fp22
  int v44; // r31
  idGameLocal *v45; // r11
  int v46; // r9
  idInfo *v47; // r3
  idInfo *v48; // r3
  float y; // r8
  float z; // r30
  int v51; // r7
  idInfo *v52; // r3
  double v53; // fp13
  double v54; // fp9
  double v55; // fp7
  double v56; // fp31
  navSplinePath_t *ShortestPath; // r3
  double distance; // fp0
  float v59[2]; // [sp+70h] [-120h] BYREF
  float x; // [sp+78h] [-118h]
  float v61; // [sp+7Ch] [-114h]
  float v62; // [sp+80h] [-110h]
  __int64 v63; // [sp+88h] [-108h] BYREF
  int v64; // [sp+90h] [-100h]
  _DWORD v65[6]; // [sp+98h] [-F8h] BYREF
  char v66; // [sp+B0h] [-E0h] BYREF

  num = this->spawnPositions.num;
  if ( this->distances.num != num )
  {
    v59[0] = 0.0;
    idList<float,17>::SetNum(this: (idList<float,32> *)&this->distances, newNum: num, initValue: v59);
  }
  v3 = this->spawnPositions.num;
  if ( this->dots.num != v3 )
  {
    v59[0] = 0.0;
    idList<float,17>::SetNum(this: (idList<float,32> *)&this->dots, newNum: v3, initValue: v59);
  }
  v4 = this->spawnPositions.num;
  if ( this->splineDistances.num != v4 )
  {
    v59[0] = 0.0;
    idList<float,17>::SetNum(this: (idList<float,32> *)&this->splineDistances, newNum: v4, initValue: v59);
  }
  value = this->player.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idPlayer::CastTo(c: v6) != nullptr )
  {
    v8 = this->player.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13
      && (v9 = (idPlayer *)gameLocal->entities.ptr[v8 & 0x1FFF]) != nullptr )
    {
      v10 = idPlayer::CastTo(c: v9);
    }
    else
    {
      v10 = nullptr;
    }
    v11 = v10->IsDrivingVehicle(this: v10);
    v12 = this->player.spawnId.value & 0x1FFF;
    v13 = this->player.spawnId.value >> 13;
    v14 = gameLocal->spawnIds.ptr[v12];
    if ( v11 )
    {
      if ( v14 == v13 && (v15 = (idPlayer *)gameLocal->entities.ptr[v12]) != nullptr )
        v16 = idPlayer::CastTo(c: v15);
      else
        v16 = nullptr;
      v17 = v16->GetVehicle_2(this: v16);
      Physics = idEntity::GetPhysics(this: v17);
      v19 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v20 = this->player.spawnId.value;
      v21 = *v19;
      v22 = v19[1];
      v23 = v19[2];
      x = *v19;
      v61 = v22;
      v62 = v23;
      if ( gameLocal->spawnIds.ptr[v20 & 0x1FFF] == v20 >> 13
        && (v24 = (idPlayer *)gameLocal->entities.ptr[v20 & 0x1FFF]) != nullptr )
      {
        v25 = idPlayer::CastTo(c: v24);
      }
      else
      {
        v25 = nullptr;
      }
      v26 = (idMat3 *)v25->GetVehicle_2(this: v25);
      LastViewAxis = (float *)idVehicle::GetLastViewAxis(this: (idVehicle *)&v66, result: v26);
      v28 = *LastViewAxis;
      v29 = LastViewAxis[1];
      v30 = LastViewAxis[2];
    }
    else
    {
      if ( v14 == v13 && (v31 = (idPlayer *)gameLocal->entities.ptr[v12]) != nullptr )
        v32 = idPlayer::CastTo(c: v31);
      else
        v32 = nullptr;
      v33 = idEntity::GetPhysics(this: v32);
      v34 = (float *)v33->GetOrigin(this: v33, a2: 0);
      v35 = this->player.spawnId.value;
      v21 = *v34;
      v22 = v34[1];
      v23 = v34[2];
      x = *v34;
      v61 = v22;
      v62 = v23;
      if ( gameLocal->spawnIds.ptr[v35 & 0x1FFF] == v35 >> 13
        && (v36 = (idPlayer *)gameLocal->entities.ptr[v35 & 0x1FFF]) != nullptr )
      {
        v37 = idPlayer::CastTo(c: v36);
      }
      else
      {
        v37 = nullptr;
      }
      presentable = v37->presentable;
      if ( presentable != nullptr )
        v39 = (float *)presentable->GetPlayerInterface_2(this: presentable);
      else
        v39 = nullptr;
      v28 = v39[11636];
      v29 = v39[11637];
      v30 = v39[11638];
    }
    NavSplinePathMgr = idGameLocal::GetNavSplinePathMgr(this: gameLocal, splineType: NAV_SPLINE_TYPE_VEHICLE_AI);
    ((void (__fastcall *)(_DWORD *, idNavSplinePathMgr *, double, _DWORD, _DWORD, double, double))NavSplinePathMgr->GetClosestPathPosition)(
      a1: v65,
      a2: NavSplinePathMgr,
      a3: COERCE_DOUBLE(LODWORD(v61)),
      a4: __ROL4__(LODWORD(v62), 32),
      a5: 0,
      a6: 3000.0,
      a7: 0.1);
    v41 = -1;
    v42 = 0;
    v43 = 1.0e30;
    if ( this->spawnPositions.num > 0 )
    {
      v44 = 0;
      do
      {
        v45 = gameLocal;
        v46 = this->spawnPositions.list[v44].spawnId.value;
        if ( gameLocal->spawnIds.ptr[v46 & 0x1FFF] == v46 >> 13
          && (v47 = (idInfo *)gameLocal->entities.ptr[v46 & 0x1FFF]) != nullptr )
        {
          v48 = idInfo::CastTo(c: v47);
          v45 = gameLocal;
        }
        else
        {
          v48 = nullptr;
        }
        y = v48->spawnPosition.y;
        z = v48->spawnPosition.z;
        v51 = this->spawnPositions.list[v44].spawnId.value;
        x = v48->spawnPosition.x;
        v61 = y;
        v62 = z;
        if ( v45->spawnIds.ptr[v51 & 0x1FFF] == v51 >> 13 )
        {
          v52 = (idInfo *)v45->entities.ptr[v51 & 0x1FFF];
          if ( v52 != nullptr )
            idInfo::CastTo(c: v52);
        }
        ((void (__fastcall *)(__int64 *, idNavSplinePathMgr *, double, _DWORD, _DWORD, double, double))NavSplinePathMgr->GetClosestPathPosition)(
          a1: &v63,
          a2: NavSplinePathMgr,
          a3: COERCE_DOUBLE(LODWORD(v61)),
          a4: 0,
          a5: 0,
          a6: 3000.0,
          a7: 0.1);
        v53 = (float)(x - (float)v21);
        v54 = (float)(v62 - (float)v23);
        v55 = (float)((float)(v61 - (float)v22) * (float)v29);
        this->distances.list[v44] = (float)((float)(v61 - (float)v22) * (float)(v61 - (float)v22))
                                  + (float)((float)(x - (float)v21) * (float)(x - (float)v21));
        v56 = (float)((float)((float)v53 * (float)v28) + (float)((float)((float)v54 * (float)v30) + (float)v55));
        this->dots.list[v44] = (float)((float)v53 * (float)v28) + (float)((float)((float)v54 * (float)v30) + (float)v55);
        ShortestPath = idNavSplinePathMgr::GetShortestPath(
                         this: (idNavSplinePathMgr *)v65[0],
                         start: (idNavSpline *)v65[1],
                         end: (idNavSplinePosition *)__ROL4__(v65[2], 32),
                         path: (idNavSplinePosition *)v63,
                         a5: __ROL4__(v64, 32),
                         a6: nullptr);
        if ( ShortestPath != nullptr )
        {
          distance = ShortestPath->distance;
        }
        else
        {
          idLib::Warning(fmt: "NO NAV PATH! for %d", v42);
          distance = 1.0e30;
        }
        if ( v56 < 0.0 )
          distance = (float)(this->penaltyForSpawnBehind * (float)distance);
        this->splineDistances.list[v44] = distance;
        if ( v41 == -1 || distance < v43 )
        {
          v41 = v42;
          v43 = distance;
        }
        ++v42;
        ++v44;
      }
      while ( v42 < this->spawnPositions.num );
    }
    return v41;
  }
  else
  {
    idLib::Warning(fmt: "NO PLAYER idTarget_DynamicVehicleAiController::CalcDistances");
    return -1;
  }
}


// ========================================================================
// ?Event_OverrideFocus@idTarget_PlayerOverrideFocus@@QAA?AVeventVoid@@PAVidEntity@@_N@Z
// EA  : 0x82CD8838
// RVA : 0x00CD8838
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_PlayerOverrideFocus *__fastcall idTarget_PlayerOverrideFocus::Event_OverrideFocus(
        idTarget_PlayerOverrideFocus *this,
        idEntity *result,
        idEntity *activator,
        bool setFocus)
{
  idPlayer *PlayerFromEntity; // r31
  idEntity *Target; // r3
  idPresentable *presentable; // r11
  idEntity *v10; // r31
  int v11; // r3

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity != nullptr || (PlayerFromEntity = idGameLocal::GetPlayer(this: gameLocal, i: 0)) != nullptr )
  {
    if ( result->targets.num <= 0 )
      Target = nullptr;
    else
      Target = idEntity::GetTarget(this: result, i: 0);
    presentable = PlayerFromEntity->presentable;
    v10 = !setFocus ? nullptr : Target;
    if ( presentable != nullptr )
      v11 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v11 = 0;
    idFocusTracker::SetFocusOverride(this: (idFocusTracker *)(v11 + 47160), ent: v10);
  }
  return this;
}


// ========================================================================
// ?Spawn@idTarget_TimedEvents@@QAAXXZ
// EA  : 0x82CD8900
// RVA : 0x00CD8900
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_TimedEvents::Spawn(idTarget_TimedEvents *this)
{
  idTarget_TimedEvents::idTarget_TimedEvents_Event *list; // r4
  unsigned int num; // r5
  int v4; // r10
  char v5; // r27
  int v6; // r28
  int v7; // r25
  idTarget_TimedEvents::idTarget_TimedEvents_Event *v8; // r29
  const char *data; // r21
  idScriptObject *v10; // r3
  idSort_Quick<idTarget_TimedEvents::idTarget_TimedEvents_Event,idSort_QuickDefault<idTarget_TimedEvents::idTarget_TimedEvents_Event> > v11[28]; // [sp+50h] [-70h] BYREF

  idEntity::BecomeInactive(this, flags: 1);
  v11[0].__vftable = (idSort_Quick<idTarget_TimedEvents::idTarget_TimedEvents_Event,idSort_QuickDefault<idTarget_TimedEvents::idTarget_TimedEvents_Event> >_vtbl *)&idSort_QuickDefault<idTarget_TimedEvents::idTarget_TimedEvents_Event>::`vftable';
  list = this->events.list;
  if ( list != nullptr )
  {
    num = this->events.num;
    v11[1] = (idSort_Quick<idTarget_TimedEvents::idTarget_TimedEvents_Event,idSort_QuickDefault<idTarget_TimedEvents::idTarget_TimedEvents_Event> >)this->events.list;
    idSort_Quick<idTarget_TimedEvents::idTarget_TimedEvents_Event,idSort_QuickDefault<idTarget_TimedEvents::idTarget_TimedEvents_Event>>::Sort(
      this: v11,
      base: list,
      num);
  }
  v4 = this->events.num;
  v5 = 0;
  v6 = 1;
  v11[0].__vftable = (idSort_Quick<idTarget_TimedEvents::idTarget_TimedEvents_Event,idSort_QuickDefault<idTarget_TimedEvents::idTarget_TimedEvents_Event> >_vtbl *)&idSort<idTarget_TimedEvents::idTarget_TimedEvents_Event>::`vftable';
  if ( v4 > 1 )
  {
    v7 = 1;
    do
    {
      v8 = &this->events.list[v7];
      if ( v8[-1].delay > (double)v8->delay )
      {
        idLib::Warning(
          fmt: "idTarget_Timeline named '%s' event %d is out of order, events have to be sorted by their delay value.",
          this->name.data,
          v6 - 1);
        v5 = 1;
      }
      if ( v8->call.len != 0 )
      {
        data = v8->call.data;
        v10 = this->GetScriptObject_2(this);
        if ( idScriptObject::GetFunction(this: v10, name: data) == nullptr
          && idProgram::FindFunction(this: &gameLocal->program, name: v8->call.data) == nullptr )
        {
          idLib::Warning(
            fmt: "idTarget_TimedEvents '%s' has call to function '%s' in slot %d which does not exist, removing entity",
            this->name.data,
            v8->call.data,
            v6);
          v5 = 1;
        }
      }
      ++v6;
      ++v7;
    }
    while ( v6 < this->events.num );
  }
  if ( v5 != 0 )
    idLib::Error(fmt: "idTarget_Timeline has to have events in order sorted by their delay values.");
}


// ========================================================================
// $LN54_3
// EA  : 0x82CD8A50
// RVA : 0x00CD8A50
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _LN54_3()
{
  int v0; // r12

  idSort_QuickDefault<idTarget_TimedEvents::idTarget_TimedEvents_Event>::~idSort_QuickDefault<idTarget_TimedEvents::idTarget_TimedEvents_Event>(this: (idSort_QuickDefault<idTarget_TimedEvents::idTarget_TimedEvents_Event> *)(v0 - 192 + 80));
}


// ========================================================================
// ?Think@idTarget_TimedEvents@@UAAXXZ
// EA  : 0x82CD8A78
// RVA : 0x00CD8A78
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_TimedEvents::Think(idTarget_TimedEvents *this)
{
  idEntity *v1; // r25
  int value; // r10
  idEntity *v4; // r3
  int GameMs; // r3
  int nextEvent; // r11
  __int64 v7; // r5
  __int64 v8; // r3
  double v9; // fp31
  int v10; // r28
  idTarget_TimedEvents::idTarget_TimedEvents_Event *v11; // r30
  int v12; // r29
  int v13; // r9
  idEntity *v14; // r3
  idEntity *v15; // r3
  idScriptFunction v16; // [sp+70h] [-1A0h] BYREF

  if ( this->activateTime >= 0 )
  {
    value = this->storedActivator.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
      || (v4 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
      || (v1 = idEntity::CastTo(c: v4)) == nullptr )
    {
      idLib::Error(
        fmt: "idTarget_TimedEvents '%s' activator '%s' has been destroyed since entity was activated.",
        this->name.data,
        "<unknown>");
    }
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    nextEvent = this->nextEvent;
    LODWORD(v7) = GameMs - this->activateTime;
    LODWORD(v8) = timeManager.gameTimePerFrame.value * timeManager.gameHz;
    v9 = (float)((float)v7 / (float)v8);
    if ( nextEvent < this->events.num )
    {
      v10 = nextEvent;
      while ( 1 )
      {
        v11 = &this->events.list[v10];
        if ( v11->delay > v9 )
          break;
        v12 = nextEvent + 1;
        this->nextEvent = nextEvent + 1;
        v13 = v11->target.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13 )
        {
          v14 = gameLocal->entities.ptr[v13 & 0x1FFF];
          if ( v14 != nullptr )
          {
            v15 = idEntity::CastTo(c: v14);
            if ( v15 != nullptr )
              idEntity::Activate(this: v15, activator: v1);
          }
        }
        if ( v11->call.len != 0 )
        {
          idScriptFunction::idScriptFunction(this: &v16);
          idScriptFunction::SetFunction(
            this: &v16,
            ent: this,
            functionName: v11->call.data,
            returnType: ev_void,
            numParms: 2,
            8,
            "activatedEntity",
            8);
          idScriptFunction::SetArg_Entity(this: &v16, argNum: 0, ent: this);
          idScriptFunction::SetArg_Entity(this: &v16, argNum: 1, ent: v1);
          idScriptFunction::CallFunction(this: &v16, defer: true);
        }
        nextEvent = v12;
        ++v10;
        if ( v12 >= this->events.num )
          goto LABEL_18;
      }
      this->nextEvent = nextEvent;
    }
LABEL_18:
    if ( this->nextEvent == this->events.num )
    {
      if ( this->reusable )
      {
        this->activateTime = -1;
        this->nextEvent = 0;
      }
      this->storedActivator.spawnId.value = 0x1FFF;
      idEntity::BecomeInactive(this, flags: 1);
    }
  }
}


// ========================================================================
// ?OnActivate@idTarget_TimedEvents@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD8CC0
// RVA : 0x00CD8CC0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_TimedEvents::OnActivate(idTarget_TimedEvents *this, idEntity *activator)
{
  if ( this->activateTime == -1 )
  {
    if ( activator != nullptr )
      this->storedActivator.spawnId.value = (gameLocal->spawnIds.ptr[activator->entityNumber] << 13)
                                          | activator->entityNumber;
    else
      this->storedActivator.spawnId.value = 0x1FFF;
    this->activateTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idEntity::BecomeActive(this, flags: 1);
  }
  else
  {
    idLib::Warning(fmt: "idTarget_TimedEvents::OnActivate called while already activated '%s'", this->name.data);
  }
}


// ========================================================================
// ?OnActivate@idTarget_AttachItem@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD8D78
// RVA : 0x00CD8D78
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_AttachItem::OnActivate(idTarget_AttachItem *this, idEntity *activator)
{
  int num; // r11
  int v4; // r19
  int v5; // r22
  int v6; // r23
  idTarget_AttachItem::attachment_t *v7; // r28
  int v8; // r24
  int value; // r9
  idEntity *v10; // r3
  idActor *v11; // r27
  idAttachmentCollection *v12; // r30
  idActor *v13; // r3
  idAnimatedEntity *v14; // r31
  idTreeAnimator *TreeAnimatorFromPresentable; // r29
  idAnimatedSimple *v16; // r3
  idAnimatedEntity *v17; // r31
  const idDeclEntityDef *entityDef; // r5
  const idAttachment *v19; // r3
  idEntityPtr<idEntity> *p_entity; // r3
  const char *data; // r31
  idEntity *v22; // r3
  idEntity *v23; // r3
  idEntity *v24; // r31
  const idDeclMD6 *decl; // r11
  idPropsCollection *p_props; // r3
  const tagData_t *Tag; // r3
  __int16 *p_granularity; // r10
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *p_parentJoint; // r9
  int i; // ctr
  const idDeclMD6 *md6; // r11
  idAttachmentCollection v32[8]; // [sp+50h] [-A0h] BYREF

  num = this->attachments.num;
  if ( num != 0 )
  {
    v4 = 0;
    if ( num > 0 )
    {
      v5 = 0;
      do
      {
        v6 = 0;
        v7 = &this->attachments.list[v5];
        if ( this->targets.num > 0 )
        {
          v8 = 0;
          do
          {
            value = this->targets.list[v8].spawnId.value;
            if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
              && (v10 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
            {
              v11 = (idActor *)idEntity::CastTo(c: v10);
            }
            else
            {
              v11 = nullptr;
            }
            v12 = nullptr;
            v13 = idActor::CastTo(c: v11);
            v14 = v13;
            TreeAnimatorFromPresentable = nullptr;
            if ( v13 != nullptr )
            {
              v12 = v13->GetAttachments_2(this: v13);
              TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v14);
            }
            v16 = idAnimatedSimple::CastTo(c: (idAnimatedSimple *)v11);
            v17 = v16;
            if ( v16 != nullptr )
            {
              v12 = v16->GetAttachments_2(this: v16);
              TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v17);
            }
            if ( v12 != nullptr && TreeAnimatorFromPresentable != nullptr )
            {
              entityDef = v7->entityDef;
              if ( entityDef != nullptr )
              {
                idAttachmentCollection::AddAttachment(
                  this: v32,
                  result: v12,
                  entityDef,
                  tag: v7->tag.data,
                  forceReplicationFlags: -1);
                v19 = idAttachmentCollection::Get(
                        this: v12,
                        handle: (const idHandle<int,enum invalidAttachment_t,-1> *)v32);
                if ( v19->handle.value != -1 )
                {
                  p_entity = &v19->entity;
                  if ( gameLocal->spawnIds.ptr[p_entity->spawnId.value & 0x1FFF] == p_entity->spawnId.value >> 13
                    && v7->entityName.len != 0 )
                  {
                    data = v7->entityName.data;
                    v22 = idEntityPtr<idEntity const>::operator->(this: p_entity);
                    idEntity::SetName(this: v22, newName: data);
                  }
                }
              }
              else if ( v7->entityName.len != 0 )
              {
                v23 = gameLocal->FindEntity(this: gameLocal, a2: v7->entityName.data);
                v24 = v23;
                if ( v23 != nullptr )
                {
                  if ( v7->attachName.len != 0 )
                  {
                    decl = TreeAnimatorFromPresentable->decl;
                    p_props = &decl->props;
                    if ( decl == nullptr )
                      p_props = nullptr;
                    Tag = idPropsCollection::GetTag(this: p_props, propName: v7->attachName.data, tagName: v7->tag.data);
                    p_granularity = &v32[0].attachments.granularity;
                    p_parentJoint = &Tag[-1].parentJoint;
                    for ( i = 8; i != 0; --i )
                    {
                      p_parentJoint += 2;
                      p_granularity += 2;
                      *(_DWORD *)p_granularity = *(_DWORD *)&p_parentJoint->value;
                    }
                    idEntity::BindToTag(
                      this: v24,
                      master: (idWorldspawn *)v11,
                      tag: (const tagData_t *)&v32[0].parent,
                      orientated: true);
                  }
                  else
                  {
                    idAttachmentCollection::AddAttachment(
                      this: (idAttachmentCollection *)&v32[0].attachments.num,
                      result: v12,
                      ent: v23,
                      tag: v7->tag.data);
                  }
                }
                else
                {
                  idLib::Warning(fmt: "Could not find entity '%s' to attach.", v7->entityName.data);
                }
              }
              else
              {
                md6 = v7->md6;
                if ( md6 != nullptr )
                {
                  idAttachmentCollection::AddAttachment(
                    this: (idAttachmentCollection *)&v32[0].attachments.size,
                    result: &v12->attachments,
                    modelName: md6->name.str,
                    tag: v7->tag.data);
                }
                else if ( v7->lwoName.len != 0 )
                {
                  idAttachmentCollection::AddAttachment(
                    this: (idAttachmentCollection *)&v32[0].attachments.granularity,
                    result: &v12->attachments,
                    modelName: v7->lwoName.data,
                    tag: v7->tag.data);
                }
                else
                {
                  idLib::Warning(fmt: "No valid attachment specified for '%s'", this->name.data);
                }
              }
            }
            ++v6;
            ++v8;
          }
          while ( v6 < this->targets.num );
        }
        ++v4;
        ++v5;
      }
      while ( v4 < this->attachments.num );
    }
  }
}


// ========================================================================
// ?OnActivate@idTarget_ConditionalAccessor@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD9060
// RVA : 0x00CD9060
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ConditionalAccessor::OnActivate(idTarget_ConditionalAccessor *this, idEntity *activator)
{
  int num; // r28
  int v4; // r30
  int value; // r9
  idEntity *v6; // r3
  idTarget_Conditional *v7; // r3
  eventVoid *v8; // r4
  char v9; // [sp+50h] [-30h] BYREF

  num = this->targets.num;
  if ( num != 0 )
  {
    v4 = num;
    do
    {
      --num;
      --v4;
      if ( num < this->targets.num
        && (value = this->targets.list[v4].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
        && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v7 = (idTarget_Conditional *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      if ( v7 != nullptr )
      {
        v8 = (eventVoid *)idTarget_Conditional::CastTo(c: v7);
        if ( v8 != nullptr )
          idTarget_Conditional::Event_ModifyCount(this: (idTarget_Conditional *)&v9, result: v8, value: this->value);
      }
    }
    while ( num != 0 );
  }
}


// ========================================================================
// ?Spawn@idTarget_ToggleTraversal@@QAAXXZ
// EA  : 0x82CD9118
// RVA : 0x00CD9118
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ToggleTraversal::Spawn(idTarget_ToggleTraversal *this)
{
  idAAS2 *AAS; // r28
  int num; // r26
  int v4; // r29
  int value; // r9
  idEntity *v6; // r3
  idEntity *v7; // r31
  idAAS2 v8; // [sp+50h] [-50h] BYREF
  int v9; // [sp+54h] [-4Ch] BYREF

  AAS = idGameLocal::GetAAS(this: gameLocal, idx: this->aasType);
  if ( AAS != nullptr )
  {
    num = this->targets.num;
    if ( num != 0 )
    {
      v4 = num;
      do
      {
        --num;
        --v4;
        if ( num < this->targets.num
          && (value = this->targets.list[v4].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
          && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v7 = idEntity::CastTo(c: v6);
        }
        else
        {
          v7 = nullptr;
        }
        if ( v7 != nullptr && (unsigned __int8)idInfoTraversal::IsTypeOf(c: v7) != 0 )
        {
          AAS->GetAASTraversalNameIndexByName(
            this: &v8,
            result: (idIndex<short,enum invalidAASTraversalNameIndex_t> *)AAS,
            a3: v7->name.data);
          if ( SHIWORD(v8.__vftable) >= 0 )
          {
            v9 = ((int (__fastcall *)(idAAS2 *))AAS->GetAASTraversalIndexByNameIndex)(a1: AAS);
            if ( v9 != 0 )
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)&this->targetTraversals,
                obj: (encounterGroupRole_t *)&v9);
            else
              idLib::Warning(
                fmt: "idTarget_ToggleTraversal could not find traversalIndex for traversal '%s' using index %d in aas.",
                v7->name.data,
                SHIWORD(v8.__vftable));
          }
          else
          {
            idLib::Warning(fmt: "idTarget_ToggleTraversal could not find traversal '%s' in aas.", v7->name.data);
          }
        }
      }
      while ( num != 0 );
    }
  }
  else
  {
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
  }
}


// ========================================================================
// ?Spawn@idTarget_NextMap@@AAAXXZ
// EA  : 0x82CD9298
// RVA : 0x00CD9298
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_NextMap::Spawn(idTarget_NextMap *this)
{
  idStr v2; // [sp+50h] [-60h] BYREF
  idStr v3; // [sp+70h] [-40h] BYREF

  if ( (gameLocal->GetGameSpawnInfo(this: gameLocal)->gameFlags & 0x80) == 0 )
  {
    v3.len = 0;
    v3.allocedAndFlag = 20;
    v3.data = v3.baseBuffer;
    v3.baseBuffer[0] = 0;
    v2.allocedAndFlag = 20;
    v2.data = v2.baseBuffer;
    v2.len = 0;
    v2.baseBuffer[0] = 0;
    idTarget_NextMap::GetNextMapAndLayers(this, map: &v3, layers: &v2, setProgress: false);
    idLib::Printf(fmt: "idTarget_NextMap '%s': Next map is '%s' with layers '%s'\n", this->name.data, v3.data, v2.data);
    idStr::FreeData(this: &v2);
    idStr::FreeData(this: &v3);
  }
}


// ========================================================================
// __unwind$518100
// EA  : 0x82CD9360
// RVA : 0x00CD9360
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_518100()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$518101
// EA  : 0x82CD9388
// RVA : 0x00CD9388
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_518101()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?OnActivate@idTarget_SetSceneModelFlag@@UAAXPAVidEntity@@@Z
// EA  : 0x82CD93B0
// RVA : 0x00CD93B0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_SetSceneModelFlag::OnActivate(idTarget_SetSceneModelFlag *this, idEntity *activator)
{
  int num; // r25
  int v4; // r26
  int v5; // r28
  int value; // r9
  idEntity *v7; // r3
  idEntity *v8; // r30
  idPresentable *presentable; // r11
  char v10; // r11
  bool v11; // zf
  idRenderModel *RenderModelFromPresentable; // r3
  idRenderModel *v13; // r31
  char v14; // r10

  num = this->targets.num;
  v4 = 0;
  if ( num > 0 )
  {
    v5 = 0;
    do
    {
      if ( v4 < this->targets.num
        && (value = this->targets.list[v5].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
        && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v8 = idEntity::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      if ( v8 != nullptr )
      {
        presentable = v8->presentable;
        if ( presentable == nullptr || (v11 = presentable->model != nullptr, v10 = 1, !v11) )
          v10 = 0;
        if ( v10 != 0 )
        {
          RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: v8);
          v13 = RenderModelFromPresentable;
          if ( (*((_BYTE *)this + 800) & 0x80) != 0 )
            v14 = *((_BYTE *)&RenderModelFromPresentable->g + 104) | 4;
          else
            v14 = *((_BYTE *)&RenderModelFromPresentable->g + 104) & 0xFB;
          *((_BYTE *)&RenderModelFromPresentable->g + 104) = v14;
          if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)v8) == 0 )
            idRenderModel::CommitThisFrame(this: v13);
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < num );
  }
}


// ========================================================================
// ??1idTarget_JobTriggered@@UAA@XZ
// EA  : 0x82CD95E8
// RVA : 0x00CD95E8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_JobTriggered::~idTarget_JobTriggered(idTarget_JobTriggered *this)
{
  int entityNumber; // r10
  idList<idEntityPtr<idEntity>,58> *p_jobTriggeredTargets; // r3
  int v4; // r4
  int num; // r9
  int v6; // r11

  entityNumber = this->entityNumber;
  this->__vftable = (idTarget_JobTriggered_vtbl *)&idTarget_JobTriggered::`vftable';
  p_jobTriggeredTargets = (idList<idEntityPtr<idEntity>,58> *)&gameLocal->jobTriggeredTargets;
  v4 = 0;
  num = gameLocal->jobTriggeredTargets.num;
  if ( num > 0 )
  {
    v6 = 0;
    while ( p_jobTriggeredTargets->list[v6].spawnId.value != ((gameLocal->spawnIds.ptr[entityNumber] << 13)
                                                            | entityNumber) )
    {
      ++v4;
      ++v6;
      if ( v4 >= num )
        goto LABEL_8;
    }
    if ( v4 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_jobTriggeredTargets, index: v4);
  }
LABEL_8:
  idEntity::~idEntity(this);
}


// ========================================================================
// ??0idTarget_LayerCheckpointModifier@@QAA@XZ
// EA  : 0x82CD9690
// RVA : 0x00CD9690
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_LayerCheckpointModifier *__fastcall idTarget_LayerCheckpointModifier::idTarget_LayerCheckpointModifier(
        idTarget_LayerCheckpointModifier *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_LayerCheckpointModifier_vtbl *)&idTarget_LayerCheckpointModifier::`vftable';
  this->targetLayerStateChange.spawnId.value = 0x1FFF;
  this->saveCheckpoint = true;
  this->persistToStorage = true;
  this->playerSpawnSpot.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// ??0idTarget_LayerStateChange@@QAA@XZ
// EA  : 0x82CD96F0
// RVA : 0x00CD96F0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_LayerStateChange *__fastcall idTarget_LayerStateChange::idTarget_LayerStateChange(
        idTarget_LayerStateChange *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_LayerStateChange_vtbl *)&idTarget_LayerStateChange::`vftable';
  this->activateDeactiveLayers.list = nullptr;
  this->activateDeactiveLayers.granularity = 0;
  this->activateDeactiveLayers.memTag = 5;
  this->activateDeactiveLayers.listStatic = 0;
  this->activateDeactiveLayers.size = 0;
  this->activateDeactiveLayers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->activateDeactiveLayers);
  this->removeLayersFromPlayer.list = nullptr;
  this->removeLayersFromPlayer.granularity = 0;
  this->removeLayersFromPlayer.memTag = 5;
  this->removeLayersFromPlayer.listStatic = 0;
  this->removeLayersFromPlayer.size = 0;
  this->removeLayersFromPlayer.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->removeLayersFromPlayer);
  this->removeLayersFromGame.list = nullptr;
  this->removeLayersFromGame.granularity = 0;
  this->removeLayersFromGame.memTag = 5;
  this->removeLayersFromGame.listStatic = 0;
  this->removeLayersFromGame.size = 0;
  this->removeLayersFromGame.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->removeLayersFromGame);
  this->activateLayers.list = nullptr;
  this->activateLayers.granularity = 0;
  this->activateLayers.memTag = 5;
  this->activateLayers.listStatic = 0;
  this->activateLayers.size = 0;
  this->activateLayers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->activateLayers);
  this->deactivateActiveLayers.list = nullptr;
  this->deactivateActiveLayers.granularity = 0;
  this->deactivateActiveLayers.memTag = 5;
  this->deactivateActiveLayers.listStatic = 0;
  this->deactivateActiveLayers.size = 0;
  this->deactivateActiveLayers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->deactivateActiveLayers);
  this->addDeactiveLayersToPlayer.list = nullptr;
  this->addDeactiveLayersToPlayer.granularity = 0;
  this->addDeactiveLayersToPlayer.memTag = 5;
  this->addDeactiveLayersToPlayer.listStatic = 0;
  this->addDeactiveLayersToPlayer.size = 0;
  this->addDeactiveLayersToPlayer.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->addDeactiveLayersToPlayer);
  this->removeLayersMarkActiveNextMapLoad.list = nullptr;
  this->removeLayersMarkActiveNextMapLoad.granularity = 0;
  this->removeLayersMarkActiveNextMapLoad.memTag = 5;
  this->removeLayersMarkActiveNextMapLoad.listStatic = 0;
  this->removeLayersMarkActiveNextMapLoad.size = 0;
  this->removeLayersMarkActiveNextMapLoad.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->removeLayersMarkActiveNextMapLoad);
  this->removeLayersMarkDeactiveNextMapLoad.list = nullptr;
  this->removeLayersMarkDeactiveNextMapLoad.granularity = 0;
  this->removeLayersMarkDeactiveNextMapLoad.memTag = 5;
  this->removeLayersMarkDeactiveNextMapLoad.listStatic = 0;
  this->removeLayersMarkDeactiveNextMapLoad.size = 0;
  this->removeLayersMarkDeactiveNextMapLoad.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->removeLayersMarkDeactiveNextMapLoad);
  this->saveCheckpoint = true;
  this->playerSpawnSpot.spawnId.value = 0x1FFF;
  this->persistToStorage = true;
  this->orderingIndex = 0;
  this->checkpointEnt = nullptr;
  return this;
}


// ========================================================================
// __unwind$519259
// EA  : 0x82CD9850
// RVA : 0x00CD9850
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_519259()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$519260
// EA  : 0x82CD9878
// RVA : 0x00CD9878
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_519260()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 800));
}


// ========================================================================
// __unwind$519261
// EA  : 0x82CD98A4
// RVA : 0x00CD98A4
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_519261()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 816));
}


// ========================================================================
// __unwind$519262
// EA  : 0x82CD98D0
// RVA : 0x00CD98D0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_519262()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 832));
}


// ========================================================================
// __unwind$519263
// EA  : 0x82CD98FC
// RVA : 0x00CD98FC
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_519263()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 848));
}


// ========================================================================
// __unwind$519264
// EA  : 0x82CD9928
// RVA : 0x00CD9928
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_519264()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 864));
}


// ========================================================================
// __unwind$519265
// EA  : 0x82CD9954
// RVA : 0x00CD9954
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_519265()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 880));
}


// ========================================================================
// __unwind$519266
// EA  : 0x82CD9980
// RVA : 0x00CD9980
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_519266()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 896));
}


// ========================================================================
// ?OnActivate@idTarget_LevelTransition@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD9C00
// RVA : 0x00CD9C00
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_LevelTransition::OnActivate(idTarget_LevelTransition *this, idVehicle *activator)
{
  idVehicle *v4; // r29
  idPlayer *v5; // r30
  idPlayer *Driver; // r3
  garageList_t garage; // r27
  const idDeclEntityDef *entityDef; // r28
  idInventoryCollection *v9; // r3
  int v10; // r10
  const idDeclVehicleUpgrade **list; // r11
  idPlayer *Gunner; // r3
  idEventArg *v13; // r3
  idPresentable *presentable; // r3
  float *v15; // r3
  idPresentable *v16; // r3
  int v17; // r3
  idPlayerHud *PlayerHud; // r3
  idEntity *Control; // r3
  int v20; // r11
  idList<idDeclVehicleUpgrade const *,5> v21; // [sp+60h] [-70h] BYREF
  idEventArg v22[4]; // [sp+70h] [-60h] BYREF

  v4 = idVehicle::CastTo(c: activator);
  v5 = idPlayer::CastTo(c: (idPlayer *)activator);
  if ( v5 != nullptr )
    goto LABEL_20;
  if ( v4 == nullptr )
    goto LABEL_17;
  Driver = (idPlayer *)idVehicle::GetDriver(this: v4);
  v5 = idPlayer::CastTo(c: Driver);
  if ( v5 != nullptr )
  {
    garage = this->garage;
    if ( garage == GARAGE_MAX )
    {
      idLib::Warning(fmt: "Vehicle Activated %s, no garage is set", this->name.data);
      garage = GARAGE_NONE;
    }
    else if ( garage == GARAGE_NONE )
    {
      entityDef = v4->entityDef;
      idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: &v21);
      v9 = v5->GetInventory_2(this: v5);
      idInventoryCollection::GetVehicleKeys(this: v9, vehicleList: (idList<idVehicleKey *,5> *)&v21);
      v10 = 0;
      if ( v21.num > 0 )
      {
        list = v21.list;
        while ( (const idDeclEntityDef *)(*list)->nextOnHashChain[14].trackedMemory != entityDef )
        {
          ++v10;
          ++list;
          if ( v10 >= v21.num )
            goto LABEL_13;
        }
        HIBYTE((*list)->attachmentInfo.list) = 1;
      }
LABEL_13:
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v21);
    }
    idPlayer::SetVehicleInfo(this: v5, vehicle: v4, garage, markForGarageView: garage != GARAGE_NONE);
    idVehicle::TransferVehicleAmmoToPlayer(this: v4, player: v5);
    idVehicle::TransferVehicleQuickItemsToPlayer(this: v4, player: v5);
  }
  else
  {
    Gunner = (idPlayer *)idVehicle::GetGunner(this: v4);
    v5 = idPlayer::CastTo(c: Gunner);
  }
  if ( v5 != nullptr )
  {
LABEL_20:
    if ( this->freeInventory )
      idEventReceiver::PostEventMS(this: v5, ev: &EV_RemoveAllInventoryItems, time: 800);
    v13 = idEventArg::idEventArg(this: v22, data: v5);
    idEventReceiver::PostEventMS(
      this,
      ev: &EV_DoTransition,
      time: *(_DWORD *)&v13->type,
      arg1: (const idEventArg *)LODWORD(v13->value.v[1]));
    presentable = v5->presentable;
    if ( presentable != nullptr )
      v15 = (float *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v15 = nullptr;
    v15[4767] = 0.0;
    v15[4768] = 0.0;
    v15[4769] = 0.0;
    v15[4770] = 0.0;
    v16 = v5->presentable;
    if ( v16 != nullptr )
      v17 = (int)v16->GetPlayerInterface_2(this: v16);
    else
      v17 = 0;
    idView::Fade(this: (idView *)(v17 + 16224), color: (const idVec4 *)&idColor::colorBlack, time: 750);
    PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this: v5);
    idPlayerHud::SetHudState(this: PlayerHud, state: HUDSTATE_NONE);
    *((_BYTE *)v5 + 12824) |= 4u;
    idPlayer::SetForceInhibitControl(this: v5, inhibit: true);
    *(_BYTE *)&v5->flags &= ~2u;
    if ( idPlayer::GetControl(this: v5) != nullptr )
    {
      Control = idPlayer::GetControl(this: v5);
      *(_BYTE *)&Control->flags &= ~2u;
    }
    v20 = *(_DWORD *)(idPlayer::GetPlayerHud(this: v5) + 40);
    if ( v20 != 0 && *(_DWORD *)(v20 + 16) == 2 )
      idJobManager::RemoveJob(
        this: &v5->jobManager,
        jobDecl: *(const idDeclJob **)(v20 + 12),
        resetTriggeredCount: false);
  }
  else
  {
LABEL_17:
    if ( activator != nullptr )
      idLib::Warning(fmt: "idTarget_LevelTransition: activated by non-player '%s'", activator->name.data);
    else
      idLib::Warning(fmt: "idTarget_LevelTransition: activated by non-player '%s'", "NULL");
  }
}


// ========================================================================
// __unwind$519526
// EA  : 0x82CD9EE0
// RVA : 0x00CD9EE0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_519526()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 96));
}


// ========================================================================
// ?OnActivate@idTarget_Enemy@@EAAXPAVidEntity@@@Z
// EA  : 0x82CD9F08
// RVA : 0x00CD9F08
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Enemy::OnActivate(idTarget_Enemy *this, idActor *activator)
{
  idActor *v4; // r26
  int v5; // r24
  int v6; // r27
  int value; // r9
  idEntity *v8; // r3
  idAI2 *v9; // r3
  idAI2 *v10; // r3
  idAI2 *v11; // r31
  idAIGameState *p_aiGameState; // r23
  const idEntityPtr<idAI2> *v13; // r22
  const idEntityPtr<idAI2> *v14; // r21
  idEntityPtr<idAI2> *v15; // r3
  const idSpawnId *v16; // r8
  idSpawnId v17; // [sp+50h] [-A0h] BYREF
  idSpawnId v18; // [sp+54h] [-9Ch] BYREF
  idAILogic v19; // [sp+60h] [-90h] BYREF

  v4 = idActor::CastTo(c: activator);
  if ( v4 != nullptr )
  {
    v5 = 0;
    if ( this->targets.num > 0 )
    {
      v6 = 0;
      do
      {
        value = this->targets.list[v6].spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
          && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v9 = (idAI2 *)idEntity::CastTo(c: v8);
        }
        else
        {
          v9 = nullptr;
        }
        v10 = idAI2::CastTo(c: v9);
        v11 = v10;
        if ( v10 != nullptr )
        {
          p_aiGameState = &gameLocal->aiGameState;
          v13 = (const idEntityPtr<idAI2> *)idSpawnId::idSpawnId(this: &v17, ent: v10);
          v14 = (const idEntityPtr<idAI2> *)idSpawnId::idSpawnId(this: &v18, ent: v4);
          v15 = (idEntityPtr<idAI2> *)idAILogic::idAILogic(this: &v19, ai: v11);
          idAIWorldState::AddEntityState(
            this: &v11->aiVolatile.world.worldState,
            gameState: p_aiGameState,
            owner: v15,
            entId: v14,
            stimulusType: AISTIMULUS_TRIGGER,
            stimulusAmount: 1.0,
            sourceId: v16,
            a8: v13);
          v11->aiVolatile.memory.currentEnemy.spawnId.value = (gameLocal->spawnIds.ptr[v4->entityNumber] << 13)
                                                            | v4->entityNumber;
        }
        ++v5;
        ++v6;
      }
      while ( v5 < this->targets.num );
    }
  }
  else if ( activator != nullptr )
  {
    idLib::Warning(fmt: "idTarget_Enemy::OnActivate - activator '%s' is not an actor", activator->name.data);
  }
  else
  {
    idLib::Warning(fmt: "idTarget_Enemy::OnActivate - activator '%s' is not an actor", "NULL");
  }
}


// ========================================================================
// ?Spawn@idTarget_Spawn@@QAAXXZ
// EA  : 0x82CDA0A0
// RVA : 0x00CDA0A0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Spawn::Spawn(idTarget_Spawn *this)
{
  const char *v1; // r24
  int v2; // r23
  idDeclInfoTemplate<idDeclEntityDef> *v3; // r22
  const char *v4; // r21
  const char *v5; // r20
  const char *v6; // r19
  idCVar *v7; // r18
  int v8; // r17
  int num; // r10
  idMapFile *v11; // r3
  int v12; // r28
  idGameLocal *v13; // r11
  int v14; // r30
  int v15; // r26
  const char *v16; // r25
  int value; // r9
  idEntity *v18; // r3
  idEntity *v19; // r3
  const char **v20; // r31
  idDeclEntityDef *v21; // r28
  float *v22; // r11
  double v23; // fp0
  int v24; // r3
  idStr *v25; // r11
  const char *data; // r4
  const idDecl *v27; // r3
  const idDeclEntityDef *v28; // r30
  idEntity *v29; // r3
  idEntity *v30; // r27
  idPhysics *Physics; // r3
  float *v32; // r30
  float *v33; // r3
  void (__fastcall *dtr_idClass)(struct idEntity *); // r7

  num = this->targets.num;
  if ( num != this->entityDefs.num )
  {
    v11 = gameLocal->GetLevelMap(this: gameLocal);
    idLib::Error(
      fmt: "This map needs to be re-saved to set up target/spawn '%s in map %s' properly!",
      this->name.data,
      v11->name.data);
  }
  v12 = 0;
  v13 = gameLocal;
  if ( num > 0 )
  {
    v14 = 0;
    v15 = 151824;
    v16 = (const char *)&g_loadAllLayers;
    do
    {
      value = this->targets.list[v14].spawnId.value;
      if ( v13->spawnIds.ptr[value & 0x1FFF] == value >> 13 && (v18 = v13->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v19 = idEntity::CastTo(c: v18);
        v13 = gameLocal;
        v20 = (const char **)v19;
      }
      else
      {
        v20 = nullptr;
      }
      if ( v20 != nullptr )
      {
        if ( v20 == (const char **)v13->world )
        {
          idLib::Error(fmt: "Entity '%s' is targeting the worldspawn! This is bad.", this->name.data);
          goto _LN189;
        }
        if ( (v13->GetGameFlags(this: v13) & 0x80) == 0 && g_loadAllLayers.valueInteger == 0 )
        {
          idLib::Warning(
            fmt: "Entity '%s' should be placed in the 'spawn_target_layer' layer! Re-save the map to do this automatically.",
            v20[4]);
          (*((void (__fastcall **)(const char **, int))*v20 + 1))(a1: v20, a2: 1);
        }
        v13 = gameLocal;
      }
      ++v12;
      ++v14;
    }
    while ( v12 < this->targets.num );
  }
  v8 = 0;
  if ( this->entityDefs.num > 0 )
  {
    v20 = nullptr;
    v2 = 152276;
    v15 = -2110193664;
    v5 = "Failed spawning entity def '%s' from target/spawn '%s'!";
    v6 = "Missing target/spawn entityDef decl file '%s'.  Re-save the map.";
    v3 = &idDeclEntityDef::resourceList;
    v4 = ".decl";
    v16 = "'";
    v1 = "\"";
    v7 = &com_production;
    while ( 1 )
    {
      v21 = nullptr;
      if ( v7->valueInteger == 0 && !this->spawnEditable.safeSpawnFlag )
      {
        if ( idList<idStr,5>::FindIndex(
               this: (idList<idStr,5> *)((char *)v13 + v2),
               obj: (const idStr *)((char *)v20 + (unsigned int)this->entityDefs.list),
               startIndex: 0) > -1 )
        {
          idStr::Replace(this: (idStr *)((char *)v20 + (unsigned int)this->entityDefs.list + 32), old: v16, nw: v1);
          v22 = (float *)((char *)v20 + (unsigned int)this->entityDefs.list);
          v22[18] = *(float *)(v15 - 31152);
          v22[17] = *(float *)(v15 - 31152);
          v22[16] = *(float *)(v15 - 31152);
          v23 = -*(float *)(v15 - 31152);
          v22[21] = v23;
          v22[20] = v23;
          v22[19] = v23;
          goto LABEL_37;
        }
        v13 = gameLocal;
      }
      idList<idStr,5>::Append(
        this: (idList<idStr,5> *)((char *)v13 + v2),
        obj: (const idStr *)((char *)v20 + (unsigned int)this->entityDefs.list));
      v24 = idStr::Find(
              searchIn: *(const char **)((char *)v20 + (unsigned int)this->entityDefs.list + 36),
              searchFor: v4,
              casesensitive: false,
              start: 0,
              end: *(int *)((char *)v20 + (unsigned int)this->entityDefs.list + 32));
      v25 = (idStr *)((char *)v20 + (unsigned int)this->entityDefs.list);
      if ( v24 <= -1 )
      {
        idStr::Replace(this: v25 + 1, old: v16, nw: v1);
        v21 = idDeclInfoTemplate<idDeclEntityDef>::AllocDecl(this: v3);
        idResource::SetName(
          this: &v21->idDecl,
          _name: *(const char **)((char *)v20 + (unsigned int)this->entityDefs.list + 4));
        idDecl::SetText(
          this: &v21->idDecl,
          text: *(const char **)((char *)v20 + (unsigned int)this->entityDefs.list + 36),
          length: 0);
        idDecl::ReParse(this: &v21->idDecl, fromDisk: false);
        v28 = v21;
      }
      else
      {
        data = v25[1].data;
        if ( data != nullptr )
          v27 = idDeclInfo::FindWithInheritance(this: v3, name: data, makeDefault: false);
        else
          v27 = nullptr;
        v28 = (const idDeclEntityDef *)v27;
        if ( v27 == nullptr )
        {
          idLib::Warning(fmt: v6, *(const char **)((char *)v20 + (unsigned int)this->entityDefs.list + 36));
          goto LABEL_37;
        }
      }
      v29 = gameLocal->SpawnEntityFromDef(this: gameLocal, a2: v28, a3: -1, a4: -1, a5: -1);
      v30 = v29;
      if ( v29 != nullptr )
      {
        Physics = idEntity::GetPhysics(this: v29);
        v32 = (float *)((char *)v20 + (unsigned int)this->entityDefs.list);
        v33 = (float *)Physics->GetBounds(this: Physics, a2: -1);
        dtr_idClass = v30->dtr_idClass;
        v32[16] = *v33;
        v32[17] = v33[1];
        v32[18] = v33[2];
        v32[19] = v33[3];
        v32[20] = v33[4];
        v32[21] = v33[5];
        ((void (__fastcall *)(idEntity *, int))dtr_idClass)(a1: v30, a2: 1);
      }
      else
      {
        idLib::Warning(fmt: v5, v28->name.str, this->name.data);
      }
      if ( v21 != nullptr )
        ((void (__fastcall *)(idDeclEntityDef *, int))v21->dtr_idResource)(a1: v21, a2: 1);
LABEL_37:
      ++v8;
      v20 += 22;
      if ( v8 >= this->entityDefs.num )
        return;
_LN189:
      v13 = gameLocal;
    }
  }
}


// ========================================================================
// `idTarget_ShowGui::OnActivate'::`21'::idSWFScriptFunction_ShowGui_DeactivateCallback::Call
// EA  : 0x82CDA4C0
// RVA : 0x00CDA4C0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idTarget_ShowGui::OnActivate_::_21_::idSWFScriptFunction_ShowGui_DeactivateCallback::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  gameLocal->targetGuiSpecialCase = SHOWGUI_NORMAL;
  (*(void (__fastcall **)(int, int, const idSWFParmList *))(*(_DWORD *)thisObject->variables.size + 380))(
    a1: thisObject->variables.size,
    a2: thisObject->variables.num,
    a3: parms);
  if ( *(_BYTE *)(thisObject->variables.size + 857) != 0 )
    idEntity::Unbind(this: (idEntity *)thisObject->variables.num);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idTarget_ShowGui::OnActivate'::`22'::idSWFScriptFunction_ShowGui_AcceptCallback::Call
// EA  : 0x82CDA548
// RVA : 0x00CDA548
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idTarget_ShowGui::OnActivate_::_22_::idSWFScriptFunction_ShowGui_AcceptCallback::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idTarget_ShowGui::ActivateAcceptTarget(this: (idTarget_ShowGui *)thisObject->variables.size);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idTarget_ShowGui::OnActivate'::`23'::idSWFScriptFunction_ShowGui_RejectCallback::Call
// EA  : 0x82CDA588
// RVA : 0x00CDA588
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idTarget_ShowGui::OnActivate_::_23_::idSWFScriptFunction_ShowGui_RejectCallback::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idTarget_ShowGui::ActivateRejectTarget(this: (idTarget_ShowGui *)thisObject->variables.size);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idTarget_ShowGui::ShowGenericAcceptDecline'::`3'::idSWFScriptFunction_GenericDecline::Call
// EA  : 0x82CDA5C8
// RVA : 0x00CDA5C8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idTarget_ShowGui::ShowGenericAcceptDecline_::_3_::idSWFScriptFunction_GenericDecline::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idEntity *size; // r3

  size = (idEntity *)thisObject->variables.size;
  if ( size != nullptr )
    idEntity::Activate(this: size, activator: (idEntity *)thisObject->variables.num);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// ?Think@idTarget_ApplyExplosionImpulse@@EAAXXZ
// EA  : 0x82CDA610
// RVA : 0x00CDA610
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ApplyExplosionImpulse::Think(
        idTarget_ApplyExplosionImpulse *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27)
{
  const idGatherQuery *v27; // r3
  idTarget_ApplyExplosionImpulse *v28; // r29
  unsigned __int64 index; // r11
  char v30; // r11
  bool v31; // zf
  int GatheredEntities; // r3
  int v33; // r31
  int *v34; // r30

  v27 = (const idGatherQuery *)((int (*)(void))RtlCheckStack12)();
  index = v27[105].index;
  v28 = (idTarget_ApplyExplosionImpulse *)v27;
  HIDWORD(index) = *(_DWORD *)(HIDWORD(index) + 17592);
  if ( (unsigned int)index < *(_DWORD *)(HIDWORD(index) + 405348)
    || (v31 = (unsigned int)index <= *(_DWORD *)(HIDWORD(index) + 405356), v30 = 1, !v31) )
  {
    v30 = 0;
  }
  if ( v30 != 0 )
  {
    GatheredEntities = idClip::GetGatheredEntities(
                         this: (idClip *)(HIDWORD(index) + 10688),
                         query: v27 + 105,
                         entityList: &a27,
                         maxCount: 0x2000);
    if ( GatheredEntities > 0 )
    {
      v33 = GatheredEntities;
      v34 = &a26;
      do
      {
        idTarget_ApplyExplosionImpulse::ApplyExplosion(this: v28, entNumber: *++v34);
        --v33;
      }
      while ( v33 != 0 );
    }
    idEntity::BecomeInactive(this: v28, flags: 1);
  }
}


// ========================================================================
// ?OnActivate@idTarget_ApplyExplosionImpulse@@EAAXPAVidEntity@@@Z
// EA  : 0x82CDA6C8
// RVA : 0x00CDA6C8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ApplyExplosionImpulse::OnActivate(
        idTarget_ApplyExplosionImpulse *this,
        idEntity *activator,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        float a17,
        float a18,
        float a19,
        float a20,
        float a21,
        float a22,
        float a23,
        float a24,
        float a25,
        float a26,
        float a27,
        float a28,
        float a29,
        float a30,
        float a31,
        float a32,
        float a33,
        float a34,
        float a35,
        float a36,
        float a37,
        float a38,
        float a39,
        float a40,
        int a41,
        int a42,
        int a43)
{
  idTarget_ApplyExplosionImpulse *v43; // r25
  int v44; // r27
  idPhysics *Physics; // r3
  float *v46; // r3
  int num; // r10
  double value; // fp12
  double v49; // fp11
  double v50; // fp10
  double v51; // fp8
  double v52; // fp7
  double v53; // fp6
  int v54; // r23
  int v55; // r24
  int v56; // r9
  idEntity *v57; // r3
  idVolume *v58; // r31
  idVolume *v59; // r28
  idPlayerStart *v60; // r3
  int v61; // r30
  int v62; // r31
  int *v63; // r29
  int v64; // r9
  idEntity *v65; // r3
  idEntity *v66; // r3
  int v67; // r10
  idPlayer *Player; // r3
  int entityNumber; // r11
  int v70; // r31
  int *v71; // r30

  v43 = (idTarget_ApplyExplosionImpulse *)((int (*)(void))RtlCheckStack12)();
  v44 = 0;
  Physics = idEntity::GetPhysics(this: v43);
  v46 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  num = v43->targets.num;
  if ( num == 0 )
  {
    a35 = *v46;
    a36 = v46[1];
    value = v43->radius.value;
    v49 = (float)(a35 - v43->radius.value);
    v50 = (float)(a36 - v43->radius.value);
    a37 = v46[2];
    v51 = (float)(*v46 + (float)value);
    a38 = *v46;
    v52 = (float)(v46[1] + (float)value);
    a39 = v46[1];
    v53 = v46[2];
    a35 = v49;
    a36 = v50;
    a37 = a37 - (float)value;
    a38 = v51;
    a39 = v52;
    a40 = (float)v53 + (float)value;
    v43->explosionBoundsQuery.index = *(_QWORD *)&idClip::GatherTouchingBounds(
                                                    this: (idClip *)&a41,
                                                    result: (idGatherQuery *)&clientGame->clip,
                                                    bounds: (const idBounds *)&a35,
                                                    clipMask: -1,
                                                    passEntityNumber: -1,
                                                    userName: "w:\\tech5\\tungsten\\game\\entities\\Target.cpp(3918) : Touching Bounds")->world;
    idEntity::BecomeActive(this: v43, flags: 1);
    return;
  }
  v54 = 0;
  if ( num > 0 )
  {
    v55 = 0;
    while ( 1 )
    {
      if ( v54 < v43->targets.num
        && (v56 = v43->targets.list[v55].spawnId.value, gameLocal->spawnIds.ptr[v56 & 0x1FFF] == v56 >> 13)
        && (v57 = gameLocal->entities.ptr[v56 & 0x1FFF]) != nullptr )
      {
        v58 = (idVolume *)idEntity::CastTo(c: v57);
      }
      else
      {
        v58 = nullptr;
      }
      v59 = idVolume::CastTo(c: v58);
      v60 = idPlayerStart::CastTo(c: (idPlayerStart *)v58);
      if ( v59 != nullptr )
      {
        v61 = 0;
        if ( v59->touching.num > 0 )
        {
          v62 = 0;
          v63 = &a43 + v44 - 1;
          do
          {
            if ( v44 == 0x2000 )
              break;
            v64 = v59->touching.list[v62].spawnId.value;
            if ( gameLocal->spawnIds.ptr[v64 & 0x1FFF] == v64 >> 13
              && (v65 = gameLocal->entities.ptr[v64 & 0x1FFF]) != nullptr )
            {
              v66 = idEntity::CastTo(c: v65);
            }
            else
            {
              v66 = nullptr;
            }
            ++v61;
            v67 = v59->touching.num;
            ++v44;
            ++v62;
            *++v63 = v66->entityNumber;
          }
          while ( v61 < v67 );
        }
        goto LABEL_27;
      }
      if ( v60 == nullptr )
        break;
      Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
      if ( Player != nullptr )
      {
        entityNumber = Player->entityNumber;
LABEL_26:
        *(&a43 + v44++) = entityNumber;
      }
LABEL_27:
      ++v54;
      ++v55;
      if ( v54 >= v43->targets.num )
        goto LABEL_28;
    }
    if ( v58 == nullptr || v44 == 0x2000 )
      goto LABEL_27;
    entityNumber = v58->entityNumber;
    goto LABEL_26;
  }
LABEL_28:
  if ( v44 > 0 )
  {
    v70 = v44;
    v71 = &a42;
    do
    {
      idTarget_ApplyExplosionImpulse::ApplyExplosion(this: v43, entNumber: *++v71);
      --v70;
    }
    while ( v70 != 0 );
  }
}


// ========================================================================
// ??0idTarget_SwapFaction@@QAA@XZ
// EA  : 0x82CDAB50
// RVA : 0x00CDAB50
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_SwapFaction *__fastcall idTarget_SwapFaction::idTarget_SwapFaction(idTarget_SwapFaction *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_SwapFaction_vtbl *)&idTarget_SwapFaction::`vftable';
  idFaction::idFaction(this: &this->targetFaction);
  this->targetType.len = 0;
  this->targetType.allocedAndFlag = 20;
  this->targetType.data = this->targetType.baseBuffer;
  this->targetType.baseBuffer[0] = 0;
  return this;
}


// ========================================================================
// __unwind$521156
// EA  : 0x82CDABC4
// RVA : 0x00CDABC4
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_521156()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idTarget_FakeEnemy@@QAA@XZ
// EA  : 0x82CDACA8
// RVA : 0x00CDACA8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_FakeEnemy *__fastcall idTarget_FakeEnemy::idTarget_FakeEnemy(idTarget_FakeEnemy *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_FakeEnemy_vtbl *)&idTarget_FakeEnemy::`vftable';
  idFaction::idFaction(this: &this->faction);
  this->activateTime = 0;
  this->lifeDuration = -1.0;
  this->weight = 2.0;
  return this;
}


// ========================================================================
// __unwind$521261
// EA  : 0x82CDAD1C
// RVA : 0x00CDAD1C
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_521261()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idTarget_DummyFire@@UAA@XZ
// EA  : 0x82CDADD8
// RVA : 0x00CDADD8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_DummyFire::~idTarget_DummyFire(idTarget_DummyFire *this)
{
  idWeapon *weapon; // r3
  idPresentableWeapon *PresentableWeapon; // r3
  idWeapon *v4; // r3

  this->__vftable = (idTarget_DummyFire_vtbl *)&idTarget_DummyFire::`vftable';
  weapon = this->weapon;
  if ( weapon != nullptr )
  {
    PresentableWeapon = idWeapon::GetPresentableWeapon(this: weapon);
    this->weapon->presentableWeapon.spawnId = 0;
    if ( PresentableWeapon != nullptr )
      idPresentable::Delete(this: PresentableWeapon);
    v4 = this->weapon;
    if ( v4 != nullptr )
      ((void (__fastcall *)(idWeapon *, int))v4->dtr_idClass)(a1: v4, a2: 1);
    this->weapon = nullptr;
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->slaves);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$521327_0
// EA  : 0x82CDAE68
// RVA : 0x00CDAE68
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_521327_0()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$521328
// EA  : 0x82CDAE90
// RVA : 0x00CDAE90
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_521328()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 868));
}


// ========================================================================
// ?OnActivate@idTarget_DummyFire@@UAAXPAVidEntity@@@Z
// EA  : 0x82CDAEC0
// RVA : 0x00CDAEC0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_DummyFire::OnActivate(idTarget_DummyFire *this, idEntity *activator)
{
  const idDeclWeapon *weaponDecl; // r11
  const idDeclAmmo *validAmmoDecl; // r11
  int GameMs; // r3
  int v6; // r29
  int v7; // r11
  double burstDuration; // fp0
  int v9; // r11
  int num; // r11
  int v11; // r4
  idEntity *Target; // r3
  int v13; // r28
  int v14; // r27
  int value; // r9
  idTarget_DummyFire *v16; // r3
  idTarget_DummyFire *v17; // r30
  int v18; // r9
  idEntity *v19; // r3
  idEntity *v20; // r4
  int numShots; // r11

  idEntity::BecomeActive(this, flags: 1);
  if ( this->projDecl == nullptr )
  {
    weaponDecl = this->weaponDecl;
    if ( weaponDecl == nullptr )
      return;
    validAmmoDecl = weaponDecl->validAmmoClips.list[this->ammoIndex].validAmmoDecl;
    if ( validAmmoDecl == nullptr )
      return;
    this->projDecl = validAmmoDecl->projectileDecl;
  }
  if ( this->fireDurationEnd <= 0 || this->shouldReset )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v6 = GameMs;
    if ( this->fireDuration <= 0.0 )
      v7 = (int)1000.0;
    else
      v7 = (int)(float)(this->fireDuration * 1000.0);
    burstDuration = this->burstDuration;
    this->nextBurstChange = GameMs;
    this->fireDurationEnd = v7 + GameMs;
    if ( burstDuration <= 0.0 )
      this->nextBurstChange = (int)1000.0 + GameMs;
    else
      this->nextBurstChange = (int)(float)(1000.0 * (float)((float)(RandomFloat() - (float)1.0) + this->burstDuration))
                            + GameMs;
    if ( this->targets.num <= 1 )
      v9 = (int)1000.0;
    else
      v9 = (int)(float)((float)((float)((float)(this->maxTargetTime - this->minTargetTime) * RandomFloat())
                              + this->minTargetTime)
                      * 1000.0);
    this->nextTargetTime = v9 + v6;
    num = this->targets.num;
    this->nextTargetIndex = 0;
    if ( num > 0 )
    {
      if ( this->targetsInOrder )
      {
        v11 = 0;
        __twllei(num, 0);
        this->nextTargetIndex = 1 % num;
        __twlgei(num & 0xFFFFFFFE, 0xFFFFFFFF);
      }
      else
      {
        v11 = RandomInt(max: num);
      }
      Target = idEntity::GetTarget(this, i: v11);
      if ( Target != nullptr )
        this->currentTarget.spawnId.value = (gameLocal->spawnIds.ptr[Target->entityNumber] << 13) | Target->entityNumber;
      else
        this->currentTarget.spawnId.value = 0x1FFF;
    }
    if ( this->slaves.num > 0 )
    {
      v13 = 0;
      v14 = this->slaves.num;
      do
      {
        value = this->slaves.list[v13].spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v16 = (idTarget_DummyFire *)gameLocal->entities.ptr[value & 0x1FFF];
          if ( v16 != nullptr )
          {
            v17 = idTarget_DummyFire::CastTo(c: v16);
            if ( v17 != nullptr )
            {
              v18 = this->currentTarget.spawnId.value;
              if ( gameLocal->spawnIds.ptr[v18 & 0x1FFF] == v18 >> 13
                && (v19 = gameLocal->entities.ptr[v18 & 0x1FFF]) != nullptr )
              {
                v20 = idEntity::CastTo(c: v19);
              }
              else
              {
                v20 = nullptr;
              }
              idTarget_DummyFire::SetTargetFromMaster(this: v17, _pTarget: v20);
            }
          }
        }
        --v14;
        ++v13;
      }
      while ( v14 != 0 );
    }
    idTarget_DummyFire::SetIsFiring(this, _bFiring: true);
    idTarget_DummyFire::SetBulletsFly(this, _bBulletsFly: false);
    if ( this->shouldReset )
    {
      numShots = this->numShots;
      if ( numShots <= 0 )
        numShots = 10;
      this->currentShotsLeft = numShots;
    }
  }
}


// ========================================================================
// ?SwitchTarget@idTarget_DummyFire@@AAA_NXZ
// EA  : 0x82CDB1E0
// RVA : 0x00CDB1E0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

int __fastcall idTarget_DummyFire::SwitchTarget(idTarget_DummyFire *this)
{
  int GameMs; // r3
  int v3; // r30
  int value; // r9
  idEntity *v5; // r3
  idEntityPtr<idEntity> *p_currentTarget; // r26
  int v7; // r31
  int nextTargetIndex; // r3
  signed int num; // r10
  idGameLocal *v10; // r11
  int v11; // r9
  idEntity *v12; // r3
  idEntity *v13; // r3
  idGameLocal *v14; // r11
  idEntity *v15; // r3
  idEntity *v16; // r3
  idEntity *v17; // r31
  idEntity *v18; // r3
  idEntity *v19; // r3
  idTarget_DummyFire *v20; // r3
  double v21; // fp1
  double burstDuration; // fp9
  int v23; // r30
  int v24; // r28
  int v25; // r9
  idTarget_DummyFire *v26; // r3
  idTarget_DummyFire *v27; // r31
  idEntity *v28; // r3
  idEntity *v29; // r4

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v3 = GameMs;
  if ( this->bSlave )
    return 0;
  if ( GameMs < this->nextTargetTime )
  {
    value = this->currentTarget.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v5 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v5 != nullptr && idEntity::CastTo(c: v5) != nullptr )
        return 0;
    }
  }
  p_currentTarget = &this->currentTarget;
  v7 = this->currentTarget.spawnId.value;
  if ( this->targetsInOrder )
  {
    nextTargetIndex = this->nextTargetIndex;
    num = this->targets.num;
    __twllei(num, 0);
    __twlgei(num & ~(__ROL4__(nextTargetIndex + 1, 1) - 1), 0xFFFFFFFF);
    this->nextTargetIndex = (nextTargetIndex + 1) % num;
  }
  else
  {
    nextTargetIndex = RandomInt(max: this->targets.num);
  }
  v10 = gameLocal;
  if ( nextTargetIndex < this->targets.num
    && (v11 = this->targets.list[nextTargetIndex].spawnId.value, gameLocal->spawnIds.ptr[v11 & 0x1FFF] == v11 >> 13)
    && (v12 = gameLocal->entities.ptr[this->targets.list[nextTargetIndex].spawnId.value & 0x1FFF]) != nullptr )
  {
    v13 = idEntity::CastTo(c: v12);
    v10 = gameLocal;
  }
  else
  {
    v13 = nullptr;
  }
  p_currentTarget->spawnId.value = v13 != nullptr
                                 ? (v10->spawnIds.ptr[v13->entityNumber] << 13) | v13->entityNumber
                                 : 0x1FFF;
  v14 = gameLocal;
  if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] == v7 >> 13 && (v15 = gameLocal->entities.ptr[v7 & 0x1FFF]) != nullptr )
  {
    v16 = idEntity::CastTo(c: v15);
    v14 = gameLocal;
    v17 = v16;
  }
  else
  {
    v17 = nullptr;
  }
  if ( v14->spawnIds.ptr[p_currentTarget->spawnId.value & 0x1FFF] == p_currentTarget->spawnId.value >> 13
    && (v18 = v14->entities.ptr[p_currentTarget->spawnId.value & 0x1FFF]) != nullptr )
  {
    v19 = idEntity::CastTo(c: v18);
  }
  else
  {
    v19 = nullptr;
  }
  if ( v17 == v19 )
    return 0;
  v20 = (idTarget_DummyFire *)idEntityPtr<idEntity const>::operator->(this: &this->currentTarget);
  if ( idTarget_DummyFire::CastTo(c: v20) != nullptr )
    return 0;
  v21 = RandomFloat();
  burstDuration = this->burstDuration;
  this->nextTargetTime = (int)(float)((float)((float)((float)(this->maxTargetTime - this->minTargetTime) * (float)v21)
                                            + this->minTargetTime)
                                    * (float)1000.0)
                       + v3;
  if ( burstDuration <= 0.0 )
    this->nextBurstChange = (int)1000.0 + v3;
  else
    this->nextBurstChange = (int)(float)((float)((float)(RandomFloat() - (float)1.0) + this->burstDuration) * 1000.0)
                          + v3;
  if ( this->slaves.num > 0 )
  {
    v23 = 0;
    v24 = this->slaves.num;
    do
    {
      v25 = this->slaves.list[v23].spawnId.value;
      if ( gameLocal->spawnIds.ptr[v25 & 0x1FFF] == v25 >> 13 )
      {
        v26 = (idTarget_DummyFire *)gameLocal->entities.ptr[v25 & 0x1FFF];
        if ( v26 != nullptr )
        {
          v27 = idTarget_DummyFire::CastTo(c: v26);
          if ( v27 != nullptr )
          {
            if ( gameLocal->spawnIds.ptr[p_currentTarget->spawnId.value & 0x1FFF] == p_currentTarget->spawnId.value >> 13
              && (v28 = gameLocal->entities.ptr[p_currentTarget->spawnId.value & 0x1FFF]) != nullptr )
            {
              v29 = idEntity::CastTo(c: v28);
            }
            else
            {
              v29 = nullptr;
            }
            idTarget_DummyFire::SetTargetFromMaster(this: v27, _pTarget: v29);
          }
        }
      }
      --v24;
      ++v23;
    }
    while ( v24 != 0 );
  }
  idTarget_DummyFire::SetIsFiring(this, _bFiring: true);
  return 1;
}


// ========================================================================
// ?SpawnVehicle@idTarget_DynamicVehicleAiController@@AAA_NPAVidVehicleAI@@AAH@Z
// EA  : 0x82CDB5C8
// RVA : 0x00CDB5C8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

int __fastcall idTarget_DynamicVehicleAiController::SpawnVehicle(
        idTarget_DynamicVehicleAiController *this,
        idVehicleAI *vehAI,
        int *closestSpawn)
{
  int NextSpawnPos; // r3
  idGameLocal *v7; // r11
  int value; // r9
  idInfo *v9; // r3
  idInfo *v10; // r3
  float y; // r7
  int v13; // r9
  float z; // r6
  idEntityPtr<idInfo> *list; // r10
  int v16; // r5
  idInfo *v17; // r3
  idInfo *v18; // r3
  char *v19; // r10
  idInfo *p_z; // r11
  int i; // ctr
  idPhysics *Physics; // r3
  idPhysics *v23; // r3
  int v24; // r7
  idVehicle_Car *v25; // r3
  int v26; // r9
  idVehicle_Car *v27; // r3
  idVehicle_Car *v28; // r3
  idPhysics *v29; // r3
  int v30; // r9
  idVehicle_Car *v31; // r3
  idVehicle_Car *v32; // r3
  idPhysics *v33; // r3
  idEventArg *v34; // r3
  _DWORD v35[4]; // [sp+50h] [-90h] BYREF
  idEventArg v36; // [sp+60h] [-80h] BYREF
  char v37; // [sp+7Ch] [-64h] BYREF
  _BYTE v38[96]; // [sp+80h] [-60h] BYREF

  if ( idTarget_DynamicVehicleAiController::TestSpawnPos(this, testIndex: *closestSpawn, vai: vehAI) )
  {
LABEL_4:
    v7 = gameLocal;
    value = this->spawnPositions.list[*closestSpawn].spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v9 = (idInfo *)gameLocal->entities.ptr[this->spawnPositions.list[*closestSpawn].spawnId.value & 0x1FFF]) != nullptr )
    {
      v10 = idInfo::CastTo(c: v9);
      v7 = gameLocal;
    }
    else
    {
      v10 = nullptr;
    }
    y = v10->spawnPosition.y;
    v13 = *closestSpawn;
    z = v10->spawnPosition.z;
    list = this->spawnPositions.list;
    v35[0] = LODWORD(v10->spawnPosition.x);
    *(float *)&v35[1] = y;
    *(float *)&v35[2] = z;
    v16 = list[v13].spawnId.value;
    if ( v7->spawnIds.ptr[v16 & 0x1FFF] == v16 >> 13 && (v17 = (idInfo *)v7->entities.ptr[v16 & 0x1FFF]) != nullptr )
      v18 = idInfo::CastTo(c: v17);
    else
      v18 = nullptr;
    v19 = &v37;
    p_z = (idInfo *)&v18->spawnPosition.z;
    for ( i = 9; i != 0; --i )
    {
      p_z = (idInfo *)((char *)p_z + 4);
      v19 += 4;
      *(_DWORD *)v19 = p_z->__vftable;
    }
    Physics = idEntity::GetPhysics(this: vehAI);
    Physics->SetOrigin(this: Physics, a2: (const idVec3 *)v35, a3: -1);
    v23 = idEntity::GetPhysics(this: vehAI);
    v23->SetAxis(this: v23, a2: (const idMat3 *)v38, a3: -1);
    v24 = vehAI->vehicleCar.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v24 & 0x1FFF] == v24 >> 13 )
    {
      v25 = (idVehicle_Car *)gameLocal->entities.ptr[v24 & 0x1FFF];
      if ( v25 != nullptr && idVehicle_Car::CastTo(c: v25) != nullptr )
      {
        v26 = vehAI->vehicleCar.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v26 & 0x1FFF] == v26 >> 13
          && (v27 = (idVehicle_Car *)gameLocal->entities.ptr[v26 & 0x1FFF]) != nullptr )
        {
          v28 = idVehicle_Car::CastTo(c: v27);
        }
        else
        {
          v28 = nullptr;
        }
        v29 = idEntity::GetPhysics(this: v28);
        v29->SetOrigin(this: v29, a2: (const idVec3 *)v35, a3: -1);
        v30 = vehAI->vehicleCar.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v30 & 0x1FFF] == v30 >> 13
          && (v31 = (idVehicle_Car *)gameLocal->entities.ptr[v30 & 0x1FFF]) != nullptr )
        {
          v32 = idVehicle_Car::CastTo(c: v31);
        }
        else
        {
          v32 = nullptr;
        }
        v33 = idEntity::GetPhysics(this: v32);
        v33->SetAxis(this: v33, a2: (const idMat3 *)v38, a3: -1);
      }
    }
    if ( (vehAI->thinkFlags & 1) == 0 )
    {
      v34 = idEventArg::idEventArg(this: &v36, data: this);
      idEventReceiver::PostEventMS(
        this: vehAI,
        ev: &EV_Activate,
        time: *(_DWORD *)&v34->type,
        arg1: (const idEventArg *)LODWORD(v34->value.v[1]));
    }
    vehAI->ignoreEnemy = false;
    vehAI->hideWhenIdle = false;
    idVehicleAI::SetForcedRetreatState(this: vehAI, setState: false);
    vehAI->dynamicVehicleAIController = this;
    *closestSpawn = idTarget_DynamicVehicleAiController::FindNextSpawnPos(this, testIndex: *closestSpawn);
    return 1;
  }
  else
  {
    while ( 1 )
    {
      NextSpawnPos = idTarget_DynamicVehicleAiController::FindNextSpawnPos(this, testIndex: *closestSpawn);
      *closestSpawn = NextSpawnPos;
      if ( NextSpawnPos < 0 )
        break;
      if ( idTarget_DynamicVehicleAiController::TestSpawnPos(this, testIndex: NextSpawnPos, vai: vehAI) )
        goto LABEL_4;
    }
    idLib::Warning(fmt: "Ran out of spawn spots for vehicles");
    return 0;
  }
}


// ========================================================================
// ?VehicleKilled@idTarget_DynamicVehicleAiController@@QAAXPAVidVehicleAI@@@Z
// EA  : 0x82CDB8E0
// RVA : 0x00CDB8E0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_DynamicVehicleAiController::VehicleKilled(
        idTarget_DynamicVehicleAiController *this,
        idVehicleAI *vehAI)
{
  int value; // r10
  idPlayer *v5; // r3
  const idDeclJob *dynamicJob; // r11
  int num; // r4
  const idDeclCameraTrigger *v8; // r30
  int cameraIndex; // r3
  int v10; // r9
  idPlayer *v11; // r3
  idPlayer *v12; // r3
  bool v13; // r20
  bool v14; // r8
  int v15; // r9
  int numSpecialVehicles; // r7
  int v17; // r10
  int v18; // r11
  int numNormalVehicles; // r10
  int NextSpawnPos; // r29
  char *v21; // r10
  float *p_y; // r11
  int v23; // ctr
  int v24; // r4
  int v25; // r9
  idGameLocal *v26; // r11
  int v27; // r9
  idInfo *v28; // r3
  idInfo *v29; // r3
  idEntityPtr<idInfo> *list; // r10
  int v31; // r9
  idInfo *v32; // r3
  float *v33; // r3
  int v34; // r8
  idVehicleAI *v35; // r3
  idVehicleAI *v36; // r3
  int v37; // r8
  idVehicleAI *v38; // r3
  idVehicleAI *v39; // r3
  idPhysics *Physics; // r3
  int v41; // r8
  idVehicleAI *v42; // r3
  idVehicleAI *v43; // r3
  idPhysics *v44; // r3
  idGameLocal *v45; // r11
  int v46; // r8
  idVehicleAI *v47; // r3
  idVehicleAI *v48; // r3
  int v49; // r9
  idVehicle_Car *v50; // r3
  idGameLocal *v51; // r11
  int v52; // r9
  idVehicleAI *v53; // r3
  idVehicleAI *v54; // r3
  int v55; // r9
  idVehicle_Car *v56; // r3
  idVehicle_Car *v57; // r3
  idPhysics *v58; // r3
  idGameLocal *v59; // r11
  int v60; // r8
  idVehicleAI *v61; // r3
  idVehicleAI *v62; // r3
  int v63; // r9
  idVehicle_Car *v64; // r3
  idVehicle_Car *v65; // r3
  idPhysics *v66; // r3
  int v67; // r8
  idVehicleAI *v68; // r3
  idVehicleAI *v69; // r3
  int v70; // r8
  idVehicleAI *v71; // r3
  idVehicleAI *v72; // r30
  idEventArg *v73; // r3
  int v74; // r8
  idVehicleAI *v75; // r3
  idVehicleAI *v76; // r3
  int v77; // r9
  idVehicleAI *v78; // r3
  idVehicleAI *v79; // r3
  int v80; // r9
  idVehicleAI *v81; // r3
  idVehicleAI *v82; // r3
  int v83; // r9
  idVehicleAI *v84; // r3
  int v85; // r9
  idPlayer *v86; // r3
  idPlayer *v87; // r3
  BOOL allnormalDeadBeforSpecial; // r10
  int v89; // r11
  int v90; // r28
  idGameLocal *v91; // r10
  int v92; // r30
  idEntityPtr<idVehicleAI> *v93; // r11
  idVehicleAI *v94; // r3
  idVehicleAI *v95; // r3
  idVec3 v96; // [sp+50h] [-D0h] BYREF
  idEventArg v97; // [sp+60h] [-C0h] BYREF
  char v98; // [sp+7Ch] [-A4h] BYREF
  float v99[40]; // [sp+80h] [-A0h] BYREF

  value = this->player.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v5 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v5 != nullptr && idPlayer::CastTo(c: v5) != nullptr )
    {
      dynamicJob = this->dynamicJob;
      if ( dynamicJob != nullptr )
      {
        num = dynamicJob->cameras.num;
        v8 = nullptr;
        if ( num > 0 )
        {
          cameraIndex = dynamicJob->cameraIndex;
          if ( cameraIndex == -1 )
            cameraIndex = idRandom2::RandomInt(this: &clientGame->random, max: num);
          v8 = this->dynamicJob->cameras.list[cameraIndex];
        }
        v10 = this->player.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v10 & 0x1FFF] == v10 >> 13
          && (v11 = (idPlayer *)gameLocal->entities.ptr[v10 & 0x1FFF]) != nullptr )
        {
          v12 = idPlayer::CastTo(c: v11);
        }
        else
        {
          v12 = nullptr;
        }
        idJobManager::TriggerJobReadyToTurnInFromTarget(
          this: &v12->jobManager,
          jobDecl: this->dynamicJob,
          completeTree: true,
          giveJobIfNeeded: true,
          hideIfGiven: false,
          force: false,
          activator: vehAI,
          cameraTriggerDecl: v8);
      }
    }
  }
  v13 = false;
  v14 = false;
  v15 = this->vehiclesActive - 1;
  numSpecialVehicles = this->numSpecialVehicles;
  v17 = this->specialVehicles.num;
  v18 = this->vehiclesKilled + 1;
  this->vehiclesActive = v15;
  this->vehiclesKilled = v18;
  if ( numSpecialVehicles >= v17 )
  {
    v14 = v18 >= this->numNormalVehicles + v17;
  }
  else
  {
    numNormalVehicles = this->numNormalVehicles;
    if ( this->allnormalDeadBeforSpecial )
      v13 = v18 >= numNormalVehicles;
    else
      v13 = v15 + v18 >= numNormalVehicles;
  }
  if ( v13 )
  {
    NextSpawnPos = idTarget_DynamicVehicleAiController::CalcDistancesAndDots(this);
    if ( NextSpawnPos >= 0 )
    {
      do
      {
        v21 = &v98;
        p_y = &mat2_identity.mat[1].y;
        v23 = 9;
        v96 = vec3_origin;
        do
        {
          ++p_y;
          v21 += 4;
          *(float *)v21 = *p_y;
          --v23;
        }
        while ( v23 != 0 );
        v24 = this->numSpecialVehicles;
        v25 = this->specialVehicles.list[v24].spawnId.value;
        if ( gameLocal->spawnIds.ptr[v25 & 0x1FFF] == v25 >> 13 )
        {
          if ( NextSpawnPos < 0 )
          {
LABEL_38:
            idLib::Warning(fmt: "special couldn't find a spot");
            v34 = this->specialVehicles.list[this->numSpecialVehicles].spawnId.value;
            if ( gameLocal->spawnIds.ptr[v34 & 0x1FFF] == v34 >> 13
              && (v35 = (idVehicleAI *)gameLocal->entities.ptr[this->specialVehicles.list[this->numSpecialVehicles].spawnId.value
                                                             & 0x1FFF]) != nullptr )
            {
              v36 = idVehicleAI::CastTo(c: v35);
              idEventReceiver::PostEventMS(this: v36, ev: &EV_Respawn, time: 1000);
            }
            else
            {
              idEventReceiver::PostEventMS(this: nullptr, ev: &EV_Respawn, time: 1000);
            }
          }
          else
          {
            while ( !idTarget_DynamicVehicleAiController::TestSpawnPos(this, testIndex: NextSpawnPos, vai: vehAI) )
            {
              NextSpawnPos = idTarget_DynamicVehicleAiController::FindNextSpawnPos(this, testIndex: NextSpawnPos);
              if ( NextSpawnPos < 0 )
                goto LABEL_38;
            }
            v26 = gameLocal;
            v27 = this->spawnPositions.list[NextSpawnPos].spawnId.value;
            if ( gameLocal->spawnIds.ptr[v27 & 0x1FFF] == v27 >> 13
              && (v28 = (idInfo *)gameLocal->entities.ptr[this->spawnPositions.list[NextSpawnPos].spawnId.value & 0x1FFF]) != nullptr )
            {
              v29 = idInfo::CastTo(c: v28);
              v26 = gameLocal;
            }
            else
            {
              v29 = nullptr;
            }
            list = this->spawnPositions.list;
            v96.x = v29->spawnPosition.x;
            v96.y = v29->spawnPosition.y;
            v96.z = v29->spawnPosition.z;
            v31 = list[NextSpawnPos].spawnId.value;
            if ( v26->spawnIds.ptr[v31 & 0x1FFF] == v31 >> 13
              && (v32 = (idInfo *)v26->entities.ptr[v31 & 0x1FFF]) != nullptr )
            {
              v33 = (float *)idInfo::CastTo(c: v32);
              v26 = gameLocal;
            }
            else
            {
              v33 = nullptr;
            }
            v99[0] = v33[14];
            v99[1] = v33[15];
            v99[2] = v33[16];
            v99[3] = v33[17];
            v99[4] = v33[18];
            v99[5] = v33[19];
            v99[6] = v33[20];
            v99[7] = v33[21];
            v99[8] = v33[22];
            v37 = this->specialVehicles.list[this->numSpecialVehicles].spawnId.value;
            if ( v26->spawnIds.ptr[v37 & 0x1FFF] == v37 >> 13
              && (v38 = (idVehicleAI *)v26->entities.ptr[this->specialVehicles.list[this->numSpecialVehicles].spawnId.value
                                                       & 0x1FFF]) != nullptr )
            {
              v39 = idVehicleAI::CastTo(c: v38);
            }
            else
            {
              v39 = nullptr;
            }
            Physics = idEntity::GetPhysics(this: v39);
            Physics->SetOrigin(this: Physics, a2: &v96, a3: -1);
            v41 = this->specialVehicles.list[this->numSpecialVehicles].spawnId.value;
            if ( gameLocal->spawnIds.ptr[v41 & 0x1FFF] == v41 >> 13
              && (v42 = (idVehicleAI *)gameLocal->entities.ptr[this->specialVehicles.list[this->numSpecialVehicles].spawnId.value
                                                             & 0x1FFF]) != nullptr )
            {
              v43 = idVehicleAI::CastTo(c: v42);
            }
            else
            {
              v43 = nullptr;
            }
            v44 = idEntity::GetPhysics(this: v43);
            v44->SetAxis(this: v44, a2: (const idMat3 *)v99, a3: -1);
            v45 = gameLocal;
            v46 = this->specialVehicles.list[this->numSpecialVehicles].spawnId.value;
            if ( gameLocal->spawnIds.ptr[v46 & 0x1FFF] == v46 >> 13
              && (v47 = (idVehicleAI *)gameLocal->entities.ptr[this->specialVehicles.list[this->numSpecialVehicles].spawnId.value
                                                             & 0x1FFF]) != nullptr )
            {
              v48 = idVehicleAI::CastTo(c: v47);
              v45 = gameLocal;
            }
            else
            {
              v48 = nullptr;
            }
            v49 = v48->vehicleCar.spawnId.value;
            if ( v45->spawnIds.ptr[v49 & 0x1FFF] == v49 >> 13 )
            {
              v50 = (idVehicle_Car *)v45->entities.ptr[v49 & 0x1FFF];
              if ( v50 != nullptr )
              {
                if ( idVehicle_Car::CastTo(c: v50) != nullptr )
                {
                  v51 = gameLocal;
                  v52 = this->specialVehicles.list[this->numSpecialVehicles].spawnId.value;
                  if ( gameLocal->spawnIds.ptr[v52 & 0x1FFF] == v52 >> 13
                    && (v53 = (idVehicleAI *)gameLocal->entities.ptr[this->specialVehicles.list[this->numSpecialVehicles].spawnId.value
                                                                   & 0x1FFF]) != nullptr )
                  {
                    v54 = idVehicleAI::CastTo(c: v53);
                    v51 = gameLocal;
                  }
                  else
                  {
                    v54 = nullptr;
                  }
                  v55 = v54->vehicleCar.spawnId.value;
                  if ( v51->spawnIds.ptr[v55 & 0x1FFF] == v55 >> 13
                    && (v56 = (idVehicle_Car *)v51->entities.ptr[v55 & 0x1FFF]) != nullptr )
                  {
                    v57 = idVehicle_Car::CastTo(c: v56);
                  }
                  else
                  {
                    v57 = nullptr;
                  }
                  v58 = idEntity::GetPhysics(this: v57);
                  v58->SetOrigin(this: v58, a2: &v96, a3: -1);
                  v59 = gameLocal;
                  v60 = this->specialVehicles.list[this->numSpecialVehicles].spawnId.value;
                  if ( gameLocal->spawnIds.ptr[v60 & 0x1FFF] == v60 >> 13
                    && (v61 = (idVehicleAI *)gameLocal->entities.ptr[this->specialVehicles.list[this->numSpecialVehicles].spawnId.value
                                                                   & 0x1FFF]) != nullptr )
                  {
                    v62 = idVehicleAI::CastTo(c: v61);
                    v59 = gameLocal;
                  }
                  else
                  {
                    v62 = nullptr;
                  }
                  v63 = v62->vehicleCar.spawnId.value;
                  if ( v59->spawnIds.ptr[v63 & 0x1FFF] == v63 >> 13
                    && (v64 = (idVehicle_Car *)v59->entities.ptr[v63 & 0x1FFF]) != nullptr )
                  {
                    v65 = idVehicle_Car::CastTo(c: v64);
                  }
                  else
                  {
                    v65 = nullptr;
                  }
                  v66 = idEntity::GetPhysics(this: v65);
                  v66->SetAxis(this: v66, a2: (const idMat3 *)v99, a3: -1);
                }
                v45 = gameLocal;
              }
            }
            v67 = this->specialVehicles.list[this->numSpecialVehicles].spawnId.value;
            if ( v45->spawnIds.ptr[v67 & 0x1FFF] == v67 >> 13
              && (v68 = (idVehicleAI *)v45->entities.ptr[this->specialVehicles.list[this->numSpecialVehicles].spawnId.value
                                                       & 0x1FFF]) != nullptr )
            {
              v69 = idVehicleAI::CastTo(c: v68);
              v45 = gameLocal;
            }
            else
            {
              v69 = nullptr;
            }
            if ( (v69->thinkFlags & 1) == 0 )
            {
              v70 = this->specialVehicles.list[this->numSpecialVehicles].spawnId.value;
              if ( v45->spawnIds.ptr[v70 & 0x1FFF] == v70 >> 13
                && (v71 = (idVehicleAI *)v45->entities.ptr[this->specialVehicles.list[this->numSpecialVehicles].spawnId.value
                                                         & 0x1FFF]) != nullptr )
              {
                v72 = idVehicleAI::CastTo(c: v71);
              }
              else
              {
                v72 = nullptr;
              }
              v73 = idEventArg::idEventArg(this: &v97, data: this);
              idEventReceiver::PostEventMS(
                this: v72,
                ev: &EV_Activate,
                time: *(_DWORD *)&v73->type,
                arg1: (const idEventArg *)LODWORD(v73->value.v[1]));
              v45 = gameLocal;
            }
            v74 = this->specialVehicles.list[this->numSpecialVehicles].spawnId.value;
            if ( v45->spawnIds.ptr[v74 & 0x1FFF] == v74 >> 13
              && (v75 = (idVehicleAI *)v45->entities.ptr[this->specialVehicles.list[this->numSpecialVehicles].spawnId.value
                                                       & 0x1FFF]) != nullptr )
            {
              v76 = idVehicleAI::CastTo(c: v75);
            }
            else
            {
              v76 = nullptr;
            }
            v76->ignoreEnemy = false;
            v77 = this->specialVehicles.list[this->numSpecialVehicles].spawnId.value;
            if ( gameLocal->spawnIds.ptr[v77 & 0x1FFF] == v77 >> 13
              && (v78 = (idVehicleAI *)gameLocal->entities.ptr[this->specialVehicles.list[this->numSpecialVehicles].spawnId.value
                                                             & 0x1FFF]) != nullptr )
            {
              v79 = idVehicleAI::CastTo(c: v78);
            }
            else
            {
              v79 = nullptr;
            }
            v79->hideWhenIdle = false;
            v80 = this->specialVehicles.list[this->numSpecialVehicles].spawnId.value;
            if ( gameLocal->spawnIds.ptr[v80 & 0x1FFF] == v80 >> 13
              && (v81 = (idVehicleAI *)gameLocal->entities.ptr[this->specialVehicles.list[this->numSpecialVehicles].spawnId.value
                                                             & 0x1FFF]) != nullptr )
            {
              v82 = idVehicleAI::CastTo(c: v81);
            }
            else
            {
              v82 = nullptr;
            }
            idVehicleAI::SetForcedRetreatState(this: v82, setState: false);
            v83 = this->specialVehicles.list[this->numSpecialVehicles].spawnId.value;
            if ( gameLocal->spawnIds.ptr[v83 & 0x1FFF] == v83 >> 13
              && (v84 = (idVehicleAI *)gameLocal->entities.ptr[this->specialVehicles.list[this->numSpecialVehicles].spawnId.value
                                                             & 0x1FFF]) != nullptr )
            {
              idVehicleAI::CastTo(c: v84)->dynamicVehicleAIController = this;
            }
            else
            {
              MEMORY[0x7D0] = this;
            }
          }
        }
        else
        {
          idLib::Warning(fmt: "Bad Special Vehicle index data value! %d", v24);
          v85 = this->player.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v85 & 0x1FFF] == v85 >> 13
            && (v86 = (idPlayer *)gameLocal->entities.ptr[v85 & 0x1FFF]) != nullptr )
          {
            v87 = idPlayer::CastTo(c: v86);
          }
          else
          {
            v87 = nullptr;
          }
          idJobManager::TriggerJobReadyToTurnInFromTarget(
            this: &v87->jobManager,
            jobDecl: this->dynamicJob,
            completeTree: true,
            giveJobIfNeeded: true,
            hideIfGiven: false,
            force: false,
            activator: nullptr,
            cameraTriggerDecl: nullptr);
        }
        allnormalDeadBeforSpecial = this->allnormalDeadBeforSpecial;
        v89 = this->numSpecialVehicles + 1;
        this->numSpecialVehicles = v89;
        if ( allnormalDeadBeforSpecial && v89 < this->specialVehicles.num )
          NextSpawnPos = idTarget_DynamicVehicleAiController::FindNextSpawnPos(this, testIndex: NextSpawnPos);
        else
          v13 = false;
      }
      while ( v13 );
    }
    else
    {
      idLib::Warning(fmt: "idTarget_DynamicVehicleAiController::special vehicle no closest spawn");
    }
  }
  else if ( v14 )
  {
    v90 = 0;
    if ( this->afterVehicles.num > 0 )
    {
      v91 = gameLocal;
      v92 = 0;
      do
      {
        v93 = &this->afterVehicles.list[v92];
        if ( v91->spawnIds.ptr[v93->spawnId.value & 0x1FFF] == v93->spawnId.value >> 13 )
        {
          v94 = (idVehicleAI *)v91->entities.ptr[v93->spawnId.value & 0x1FFF];
          if ( v94 != nullptr )
            v95 = idVehicleAI::CastTo(c: v94);
          else
            v95 = nullptr;
          idEventReceiver::PostEventMS(this: v95, ev: &EV_Respawn, time: 1000 * this->secondsTillAfterVehicles);
          v91 = gameLocal;
        }
        ++v90;
        ++v92;
      }
      while ( v90 < this->afterVehicles.num );
    }
  }
}


// ========================================================================
// ?GetVehicleRespawnPosition@idTarget_DynamicVehicleAiController@@QAA_NPAVidVehicleAI@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82CDC370
// RVA : 0x00CDC370
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

int __fastcall idTarget_DynamicVehicleAiController::GetVehicleRespawnPosition(
        idTarget_DynamicVehicleAiController *this,
        idVehicleAI *vehAI,
        idVec3 *spawnPos,
        idMat3 *spawnAxis)
{
  int value; // r10
  idPlayer *v9; // r3
  int NextSpawnPos; // r29
  int v12; // r29

  value = this->player.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idPlayer::CastTo(c: v9) != nullptr )
  {
    NextSpawnPos = idTarget_DynamicVehicleAiController::CalcDistancesAndDots(this);
    if ( NextSpawnPos >= 0 )
    {
      while ( !idTarget_DynamicVehicleAiController::TestSpawnPos(this, testIndex: NextSpawnPos, vai: vehAI) )
      {
        NextSpawnPos = idTarget_DynamicVehicleAiController::FindNextSpawnPos(this, testIndex: NextSpawnPos);
        if ( NextSpawnPos < 0 )
        {
          idLib::Warning(fmt: "GetVehicleRespawnPosition couldn't find a spot");
          return 0;
        }
      }
      v12 = NextSpawnPos;
      *spawnPos = idEntityPtr<idInfo>::operator->(this: &this->spawnPositions.list[v12])->spawnPosition;
      *spawnAxis = idEntityPtr<idInfo>::operator->(this: &this->spawnPositions.list[v12])->spawnOrientation;
      return 1;
    }
    else
    {
      idLib::Warning(fmt: "idTarget_DynamicVehicleAiController::GetVehicleRespawnPosition no closest spawn");
      return 0;
    }
  }
  else
  {
    idLib::Warning(fmt: "idTarget_DynamicVehicleAiController::GetVehicleRespawnPosition no player");
    return 0;
  }
}


// ========================================================================
// ?OnActivate@idTarget_PlayerOverrideFocus@@UAAXPAVidEntity@@@Z
// EA  : 0x82CDC4F8
// RVA : 0x00CDC4F8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_PlayerOverrideFocus::OnActivate(idTarget_PlayerOverrideFocus *this, idEntity *activator)
{
  char v3; // [sp+50h] [-20h] BYREF

  idTarget_PlayerOverrideFocus::Event_OverrideFocus(
    this: (idTarget_PlayerOverrideFocus *)&v3,
    result: this,
    activator,
    setFocus: *((_BYTE *)this + 800) >> 7);
  if ( (*((_BYTE *)this + 800) & 0x40) != 0 )
    *((_BYTE *)this + 800) = (4 * _cntlzw(*((_BYTE *)this + 800) & 0x80)) & 0x80 | *((_BYTE *)this + 800) & 0x7F;
}


// ========================================================================
// ??0idTarget_NextMap@@QAA@XZ
// EA  : 0x82CDC560
// RVA : 0x00CDC560
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_NextMap *__fastcall idTarget_NextMap::idTarget_NextMap(idTarget_NextMap *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_NextMap_vtbl *)&idTarget_NextMap::`vftable';
  this->spawnSpot.len = 0;
  this->spawnSpot.data = this->spawnSpot.baseBuffer;
  this->spawnSpot.allocedAndFlag = 20;
  this->spawnSpot.baseBuffer[0] = 0;
  this->mapName.allocedAndFlag = 20;
  this->mapName.len = 0;
  this->mapName.data = this->mapName.baseBuffer;
  this->mapName.baseBuffer[0] = 0;
  this->extraLayers.granularity = 0;
  this->extraLayers.listStatic = 0;
  this->extraLayers.memTag = 5;
  this->extraLayers.list = nullptr;
  this->extraLayers.size = 0;
  this->extraLayers.num = 0;
  this->mode = MODE_AUTO;
  idStr::operator=(this: &this->spawnSpot, text: "player_start");
  this->freeInventory = false;
  return this;
}


// ========================================================================
// __unwind$523661
// EA  : 0x82CDC608
// RVA : 0x00CDC608
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_523661()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$523662
// EA  : 0x82CDC630
// RVA : 0x00CDC630
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_523662()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 804));
}


// ========================================================================
// __unwind$523663
// EA  : 0x82CDC65C
// RVA : 0x00CDC65C
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_523663()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 836));
}


// ========================================================================
// __unwind$523664_0
// EA  : 0x82CDC688
// RVA : 0x00CDC688
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_523664_0()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 128 + 148) + 872));
}


// ========================================================================
// ??1idTarget_ShowGui@@UAA@XZ
// EA  : 0x82CDCB50
// RVA : 0x00CDCB50
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ShowGui::~idTarget_ShowGui(idTarget_ShowGui *this)
{
  idSWF *gui; // r29
  idLeaderBoardEntry *list; // r3

  this->__vftable = (idTarget_ShowGui_vtbl *)&idTarget_ShowGui::`vftable';
  gui = this->gui;
  if ( gui != nullptr )
  {
    idSWF::~idSWF(this: this->gui);
    idMem::Free(this: &mem, ptr: gui, align: ALIGN_16);
    this->gui = nullptr;
  }
  if ( this->board.listStatic == 0 || this->board.listStatic == 2 )
  {
    list = this->board.list;
    if ( list != nullptr )
      idListArrayDelete<idLeaderBoardEntry>(ptr: &list->username, num: this->board.size);
    this->board.list = nullptr;
    this->board.size = 0;
  }
  this->board.num = 0;
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$524191
// EA  : 0x82CDCBEC
// RVA : 0x00CDCBEC
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_524191()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$524192
// EA  : 0x82CDCC14
// RVA : 0x00CDCC14
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_524192()
{
  int v0; // r12

  idList<idLeaderBoardEntry,5>::~idList<idLeaderBoardEntry,5>(this: (idList<idLeaderBoardEntry,5> *)(*(_DWORD *)(v0 - 128 + 148) + 836));
}


// ========================================================================
// ?OnActivate@idTarget_ShowGui@@MAAXPAVidEntity@@@Z
// EA  : 0x82CDCC48
// RVA : 0x00CDCC48
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ShowGui::OnActivate(idTarget_ShowGui *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r28
  idPresentable *presentable; // r3
  idPresentablePlayer *v5; // r3
  idEventArg *v6; // r3
  const idMaterial *guiImage1; // r11
  idSWFScriptFunction *v8; // r3
  idSWFScriptFunction *v9; // r4
  idSWFScriptFunction *v10; // r3
  idSWFScriptFunction *v11; // r4
  idSWFScriptFunction *v12; // r3
  idSWFScriptFunction *v13; // r4
  idStrId v14[2]; // [sp+50h] [-B0h] BYREF
  idSWFScriptVar v15; // [sp+58h] [-A8h] BYREF
  idSWFScriptVar v16; // [sp+60h] [-A0h] BYREF
  idSWFScriptVar v17; // [sp+68h] [-98h] BYREF
  idSWFScriptVar v18; // [sp+70h] [-90h] BYREF
  idSWFScriptVar v19; // [sp+78h] [-88h] BYREF
  idSWFScriptVar v20; // [sp+80h] [-80h] BYREF
  idSWFScriptVar v21; // [sp+88h] [-78h] BYREF
  idSWFScriptVar v22; // [sp+90h] [-70h] BYREF
  idSWFScriptVar v23; // [sp+98h] [-68h] BYREF
  idSWFScriptVar v24; // [sp+A0h] [-60h] BYREF
  idSWFScriptVar v25; // [sp+A8h] [-58h] BYREF
  idEventArg v26[4]; // [sp+B0h] [-50h] BYREF

  gameLocal->targetGuiSpecialCase = this->specialCase;
  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity != nullptr
    || this->canUseDefaultPlayer && (PlayerFromEntity = idGameLocal::GetDebugPlayer(this: gameLocal)) != nullptr )
  {
    if ( this->specialCase == SHOWGUI_GENERIC_ACCEPT_DECLINE )
    {
      idTarget_ShowGui::ShowGenericAcceptDecline(this, player: PlayerFromEntity);
    }
    else if ( this->gui != nullptr )
    {
      if ( idPlayer::GetInventoryGuiActive(this: PlayerFromEntity) )
        idPlayer::ForceCloseInventory(this: PlayerFromEntity);
      idPlayer::DeactivateGeneralGameGui(this: PlayerFromEntity);
      presentable = PlayerFromEntity->presentable;
      if ( presentable != nullptr )
        v5 = presentable->GetPlayerInterface_2(this: presentable);
      else
        v5 = nullptr;
      idPresentablePlayer::SetGeneralGameGui(this: v5, gui: this->gui);
      if ( this->bindPlayer )
      {
        v6 = idEventArg::idEventArg(this: v26, data: this);
        idEventReceiver::PostEventMS(
          this: PlayerFromEntity,
          ev: &EV_BindPosition,
          time: *(_DWORD *)&v6->type,
          arg1: (const idEventArg *)LODWORD(v6->value.v[1]));
      }
      v14[0] = this->guiString1;
      idSWFScriptVar::idSWFScriptVar(this: &v15, s: v14);
      idSWFScriptObject::Set(this: this->gui->globals, name: "infoTitle", value: &v15);
      idSWFScriptVar::Free(this: &v15);
      v14[0] = this->guiString2;
      idSWFScriptVar::idSWFScriptVar(this: &v16, s: v14);
      idSWFScriptObject::Set(this: this->gui->globals, name: "infoBody", value: &v16);
      idSWFScriptVar::Free(this: &v16);
      v14[0] = this->guiString1;
      idSWFScriptVar::idSWFScriptVar(this: &v17, s: v14);
      idSWFScriptObject::Set(this: this->gui->globals, name: "guiString1", value: &v17);
      idSWFScriptVar::Free(this: &v17);
      v14[0] = this->guiString2;
      idSWFScriptVar::idSWFScriptVar(this: &v18, s: v14);
      idSWFScriptObject::Set(this: this->gui->globals, name: "guiString2", value: &v18);
      idSWFScriptVar::Free(this: &v18);
      v14[0] = this->guiString3;
      idSWFScriptVar::idSWFScriptVar(this: &v19, s: v14);
      idSWFScriptObject::Set(this: this->gui->globals, name: "guiString3", value: &v19);
      idSWFScriptVar::Free(this: &v19);
      guiImage1 = this->guiImage1;
      if ( guiImage1 != nullptr )
      {
        idSWFScriptVar::idSWFScriptVar(this: &v20, s: guiImage1->name.str);
        idSWFScriptObject::Set(this: this->gui->globals, name: "guiImage1", value: &v20);
        idSWFScriptVar::Free(this: &v20);
      }
      idSWFScriptVar::idSWFScriptVar(this: &v21, i: (idSWFScriptVar::swfScriptVarValue_t *)this->specialCase);
      idSWFScriptObject::Set(this: this->gui->globals, name: "specialCase", value: &v21);
      idSWFScriptVar::Free(this: &v21);
      v8 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                    size: 0x10u,
                                    tag: TAG_NEW,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
      if ( v8 != nullptr )
      {
        v8[2].__vftable = (idSWFScriptFunction_vtbl *)PlayerFromEntity;
        v8[3].__vftable = (idSWFScriptFunction_vtbl *)this;
        v9 = v8;
        v8[1].__vftable = nullptr;
        v8->__vftable = (idSWFScriptFunction_vtbl *)&`idTarget_ShowGui::OnActivate'::`21'::idSWFScriptFunction_ShowGui_DeactivateCallback::`vftable';
      }
      else
      {
        v9 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v22, nf: v9);
      idSWFScriptObject::Set(this: this->gui->globals, name: "deactivateCallBack", value: &v22);
      idSWFScriptVar::Free(this: &v22);
      idSWFScriptVar::idSWFScriptVar(this: &v23, b: true);
      idSWFScriptObject::Set(this: this->gui->globals, name: "canAccept", value: &v23);
      idSWFScriptVar::Free(this: &v23);
      v10 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                     size: 0x10u,
                                     tag: TAG_NEW,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v10 != nullptr )
      {
        v10[2].__vftable = (idSWFScriptFunction_vtbl *)PlayerFromEntity;
        v10[3].__vftable = (idSWFScriptFunction_vtbl *)this;
        v11 = v10;
        v10[1].__vftable = nullptr;
        v10->__vftable = (idSWFScriptFunction_vtbl *)&`idTarget_ShowGui::OnActivate'::`22'::idSWFScriptFunction_ShowGui_AcceptCallback::`vftable';
      }
      else
      {
        v11 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v24, nf: v11);
      idSWFScriptObject::Set(this: this->gui->globals, name: "acceptCallback", value: &v24);
      idSWFScriptVar::Free(this: &v24);
      v12 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                     size: 0x10u,
                                     tag: TAG_NEW,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v12 != nullptr )
      {
        v12[2].__vftable = (idSWFScriptFunction_vtbl *)PlayerFromEntity;
        v12[3].__vftable = (idSWFScriptFunction_vtbl *)this;
        v13 = v12;
        v12[1].__vftable = nullptr;
        v12->__vftable = (idSWFScriptFunction_vtbl *)&`idTarget_ShowGui::OnActivate'::`23'::idSWFScriptFunction_ShowGui_RejectCallback::`vftable';
      }
      else
      {
        v13 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v25, nf: v13);
      idSWFScriptObject::Set(this: this->gui->globals, name: "cancelCallback", value: &v25);
      idSWFScriptVar::Free(this: &v25);
      idSWF::Activate(this: this->gui, b: true);
    }
  }
  else
  {
    idLib::Warning(fmt: "Could not find player to show gui");
  }
}


// ========================================================================
// __unwind$524274
// EA  : 0x82CDD088
// RVA : 0x00CDD088
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_524274()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 88));
}


// ========================================================================
// __unwind$524275
// EA  : 0x82CDD0B0
// RVA : 0x00CDD0B0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_524275()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$524276
// EA  : 0x82CDD0D8
// RVA : 0x00CDD0D8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_524276()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 104));
}


// ========================================================================
// __unwind$524277
// EA  : 0x82CDD100
// RVA : 0x00CDD100
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_524277()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 112));
}


// ========================================================================
// __unwind$524278
// EA  : 0x82CDD128
// RVA : 0x00CDD128
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_524278()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 120));
}


// ========================================================================
// __unwind$524279
// EA  : 0x82CDD150
// RVA : 0x00CDD150
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_524279()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$524280
// EA  : 0x82CDD178
// RVA : 0x00CDD178
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_524280()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 136));
}


// ========================================================================
// __unwind$524282
// EA  : 0x82CDD1A0
// RVA : 0x00CDD1A0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_524282()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 144));
}


// ========================================================================
// __unwind$524283
// EA  : 0x82CDD1C8
// RVA : 0x00CDD1C8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_524283()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 152));
}


// ========================================================================
// __unwind$524285
// EA  : 0x82CDD1F0
// RVA : 0x00CDD1F0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_524285()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 160));
}


// ========================================================================
// __unwind$524287
// EA  : 0x82CDD218
// RVA : 0x00CDD218
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_524287()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 168));
}


// ========================================================================
// ?OnActivate@idTarget_ChangeSeatInfo@@UAAXPAVidEntity@@@Z
// EA  : 0x82CDD240
// RVA : 0x00CDD240
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ChangeSeatInfo::OnActivate(idTarget_ChangeSeatInfo *this, idEntity *activator)
{
  int v3; // r28
  int v4; // r29
  int value; // r9
  idEntity *v6; // r3
  idVehicle *v7; // r3
  idVehicle *v8; // r31
  const idVehicle::seatInfo_t *v9; // r3
  idVehicle::seatInfo_t v10; // [sp+50h] [-110h] BYREF

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
        v7 = (idVehicle *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      v8 = idVehicle::CastTo(c: v7);
      if ( v8 != nullptr )
      {
        v9 = idVehicle::seatInfo_t::seatInfo_t(this: &v10, __that: &this->seatInfo);
        idVehicle::ChangeSeatInfo(this: v8, seatNum: this->seatNum, changeSeatInfo: v9);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ?Think@idTarget_DummyFire@@UAAXXZ
// EA  : 0x82CDD428
// RVA : 0x00CDD428
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_DummyFire::Think(idTarget_DummyFire *this)
{
  int GameMs; // r3
  int v3; // r29
  double v4; // fp1
  bool v5; // r4
  int num; // r11
  idPhysics *Physics; // r3
  int *v8; // r3
  int v9; // r5
  int v10; // r4
  idEntity *v11; // r3
  idPhysics *v12; // r3
  int v13; // r3
  idAI2 *v14; // r3
  idAI2 *v15; // r3
  idAI2 *v16; // r28
  idPlayer *v17; // r3
  idPlayer *v18; // r3
  idPresentable *presentable; // r11
  double v20; // fp13
  double v21; // fp4
  double v22; // fp0
  BOOL bSlave; // r11
  double minRange; // fp12
  double v25; // fp0
  double v26; // fp1
  idPhysics *v27; // r29
  long double v28; // fp2
  long double v29; // fp2
  double v30; // fp29
  float *v31; // r3
  double v32; // fp1
  double scatter; // fp4
  const idDeclProjectile *projDecl; // r11
  idFinishFireResults *v35; // r11
  int i; // ctr
  idPresentable *v37; // r11
  idWeapon *weapon; // r11
  const idDeclWeapon *weaponDecl; // r10
  idMat3 *v40; // r3
  const idDeclProjectile *v41; // r7
  int v42; // r27
  int *p_surfaceType; // r28
  idPlayer *v44; // r29
  soundChannel_t fireChannel; // r29
  const idSoundShader *lastShotSound; // r28
  idEntity *entity; // r29
  int v48; // r3
  idProjectile *v49; // r3
  idProjectile *v50; // r28
  idEntity *v51; // r3
  idPresentable *v52; // r11
  idEntity *v53; // r29
  unsigned int spawnId; // r11
  int v55; // r3
  int v56; // r8
  idAIEventManager v57; // [sp+50h] [-BA0h] BYREF
  unsigned int v58; // [sp+A0h] [-B50h]
  idFireParms v59; // [sp+B0h] [-B40h] BYREF
  idMat3 v60; // [sp+150h] [-AA0h] BYREF
  idFinishFireResults v61; // [sp+180h] [-A70h] BYREF
  soundShaderParms_t v62; // [sp+1D0h] [-A20h] BYREF
  idTestFireResults v63; // [sp+270h] [-980h] BYREF

  if ( this->projDecl == nullptr )
    return;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v3 = GameMs;
  if ( this->fireDuration <= 0.0 )
  {
    v57.eventList.num = (int)1000.0;
    this->fireDurationEnd = (int)1000.0 + GameMs;
  }
  if ( this->burstDuration <= 0.0 )
  {
    v57.eventList.num = (int)1000.0;
    this->nextBurstChange = (int)1000.0 + GameMs;
  }
  if ( this->burstPause <= 0.0 && !this->bIsFiring )
  {
    v57.eventList.num = (int)1000.0;
    this->nextBurstChange = (int)1000.0 + GameMs;
  }
  if ( GameMs > this->fireDurationEnd )
    goto LABEL_16;
  if ( this->bSlave || this->targets.num <= 1 )
  {
    v57.eventList.num = (int)1000.0;
    this->nextTargetTime = (int)1000.0 + GameMs;
  }
  else
  {
    idTarget_DummyFire::SwitchTarget(this);
  }
  if ( this->currentShotsLeft <= 0 )
  {
    if ( this->shouldReset )
    {
LABEL_17:
      idTarget_DummyFire::SetIsFiring(this, _bFiring: false);
LABEL_18:
      idTarget_DummyFire::SetBulletsFly(this, _bBulletsFly: false);
      return;
    }
LABEL_16:
    idEntity::BecomeInactive(this, flags: 1);
    goto LABEL_17;
  }
  if ( v3 >= this->nextBurstChange && !this->bSlave )
  {
    if ( this->bIsFiring )
    {
      if ( this->burstPause <= 0.0 )
      {
        v5 = false;
        v57.eventList.num = (int)1000.0;
        num = (int)1000.0;
      }
      else
      {
        v4 = RandomFloat();
        v5 = false;
        v57.eventList.num = (int)(float)((float)((float)((float)v4 - (float)1.0) + this->burstPause) * 1000.0);
        num = v57.eventList.num;
      }
    }
    else
    {
      if ( this->burstDuration <= 0.0 )
      {
        v57.eventList.num = (int)1000.0;
        num = (int)1000.0;
      }
      else
      {
        v57.eventList.num = (int)(float)((float)((float)(RandomFloat() - (float)1.0) + this->burstDuration) * 1000.0);
        num = v57.eventList.num;
      }
      v5 = true;
    }
    this->nextBurstChange = num + v3;
    idTarget_DummyFire::SetIsFiring(this, _bFiring: v5);
  }
  if ( !this->bIsFiring || this->nextProjectileTime > v3 )
    goto LABEL_18;
  this->nextProjectileTime = this->weaponDecl->firingIntervals[0] + v3;
  Physics = idEntity::GetPhysics(this);
  v8 = (int *)Physics->GetOrigin(this: Physics, a2: 0);
  v9 = v8[1];
  v10 = v8[2];
  v57.eventHash.hashSize = *v8;
  v57.eventHash.indexSize = v9;
  v57.eventHash.granularity = v10;
  if ( idEntityPtr<idEntity const>::operator->(this: &this->currentTarget) != nullptr )
  {
    v11 = idEntityPtr<idEntity const>::operator->(this: &this->currentTarget);
    v12 = idEntity::GetPhysics(this: v11);
    v13 = (int)v12->GetOrigin(this: v12, a2: 0);
    v57.eventList.size = *(int *)v13;
    *(float *)&v57.eventList.granularity = *(float *)(v13 + 4);
    v57.eventHash.hash = *(int **)(v13 + 8);
    v14 = (idAI2 *)idEntityPtr<idEntity const>::operator->(this: &this->currentTarget);
    v15 = idAI2::CastTo(c: v14);
    v16 = v15;
    if ( v15 != nullptr )
    {
      if ( this->ignoreDeadAI && v15->IsDead(this: v15) )
      {
        this->nextTargetTime = v3;
        goto LABEL_18;
      }
      v16->GetAimPoint(this: v16, a2: AIMPOINT_TORSO, a3: (idVec3 *)&v57.eventList.size);
    }
    else
    {
      v17 = (idPlayer *)idEntityPtr<idEntity const>::operator->(this: &this->currentTarget);
      v18 = idPlayer::CastTo(c: v17);
      if ( v18 != nullptr )
        v18->GetAimPoint(this: v18, a2: AIMPOINT_TORSO, a3: (idVec3 *)&v57.eventList.size);
    }
  }
  else
  {
    presentable = this->presentable;
    if ( this->maxRange > 0.0 )
    {
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        presentable = this->presentable;
      }
      v22 = (float)(*(float *)&v57.eventHash.granularity + (float)(presentable->axis.mat[0].z * this->maxRange));
      v20 = (float)(*(float *)&v57.eventHash.indexSize + (float)(presentable->axis.mat[0].y * this->maxRange));
      v21 = (float)((float)(this->maxRange * presentable->axis.mat[0].x) + *(float *)&v57.eventHash.hashSize);
      v57.eventList.list = (idAIEvent **)&presentable->axis;
    }
    else
    {
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        presentable = this->presentable;
      }
      v21 = (float)(*(float *)&v57.eventHash.hashSize + (float)(presentable->axis.mat[0].x * (float)1000.0));
      v22 = (float)(*(float *)&v57.eventHash.granularity + (float)(presentable->axis.mat[0].z * (float)1000.0));
      v20 = (float)(*(float *)&v57.eventHash.indexSize + (float)(presentable->axis.mat[0].y * (float)1000.0));
      v57.eventList.list = (idAIEvent **)&presentable->axis;
    }
    *(float *)&v57.eventList.size = v21;
    *(float *)&v57.eventList.granularity = v20;
    *(float *)&v57.eventHash.hash = v22;
  }
  bSlave = this->bSlave;
  *(float *)&v57.receivers.list = *(float *)&v57.eventHash.hash - *(float *)&v57.eventHash.granularity;
  *(float *)&v57.eventHash.lookupMask = *(float *)&v57.eventList.size - *(float *)&v57.eventHash.hashSize;
  *(float *)&v57.eventHash.memTag = *(float *)&v57.eventList.granularity - *(float *)&v57.eventHash.indexSize;
  if ( bSlave )
  {
    v26 = idVec3::NormalizeFast(this: (idVec3 *)&v57.eventHash.lookupMask);
  }
  else
  {
    minRange = this->minRange;
    if ( minRange > 0.0 || this->maxRange > minRange )
    {
      *(float *)&v57.eventList.list = this->minRange;
      v25 = (float)((float)((float)(*(float *)&v57.eventHash.hash - *(float *)&v57.eventHash.granularity)
                          * (float)(*(float *)&v57.eventHash.hash - *(float *)&v57.eventHash.granularity))
                  + (float)((float)((float)(*(float *)&v57.eventList.size - *(float *)&v57.eventHash.hashSize)
                                  * (float)(*(float *)&v57.eventList.size - *(float *)&v57.eventHash.hashSize))
                          + (float)((float)(*(float *)&v57.eventList.granularity - *(float *)&v57.eventHash.indexSize)
                                  * (float)(*(float *)&v57.eventList.granularity - *(float *)&v57.eventHash.indexSize))));
      if ( v25 < (float)((float)minRange * (float)minRange) || v25 > (float)(this->maxRange * this->maxRange) )
        goto LABEL_18;
    }
    v26 = idVec3::NormalizeFast(this: (idVec3 *)&v57.eventHash.lookupMask);
    if ( this->arcAngle > 0.0 && idEntity::GetPhysics(this) != nullptr )
    {
      v27 = idEntity::GetPhysics(this);
      *(double *)&v28 = (float)(this->arcAngle * (float)0.5);
      v29 = cos(x: v28);
      v30 = (float)*(double *)&v29;
      v31 = (float *)v27->GetAxis(this: v27, a2: 0);
      if ( (float)((float)(*v31 * *(float *)&v57.eventHash.lookupMask)
                 + (float)((float)(v31[2] * *(float *)&v57.receivers.list)
                         + (float)(v31[1] * *(float *)&v57.eventHash.memTag))) < v30 )
        goto LABEL_18;
    }
  }
  if ( this->scatter > 0.0 )
  {
    *(float *)&v57.eventList.size = (float)((float)((float)(RandomFloat() * (float)2.0) - (float)1.0) * this->scatter)
                                  + *(float *)&v57.eventList.size;
    *(float *)&v57.eventList.granularity = (float)((float)((float)(RandomFloat() * (float)2.0) - (float)1.0)
                                                 * this->scatter)
                                         + *(float *)&v57.eventList.granularity;
    v32 = RandomFloat();
    scatter = this->scatter;
    *(float *)&v57.eventHash.memTag = *(float *)&v57.eventList.granularity - *(float *)&v57.eventHash.indexSize;
    *(float *)&v57.eventHash.lookupMask = *(float *)&v57.eventList.size - *(float *)&v57.eventHash.hashSize;
    *(float *)&v57.eventHash.hash = (float)((float)((float)((float)v32 * (float)2.0) - (float)1.0) * (float)scatter)
                                  + *(float *)&v57.eventHash.hash;
    *(float *)&v57.receivers.list = *(float *)&v57.eventHash.hash - *(float *)&v57.eventHash.granularity;
    v26 = idVec3::NormalizeFast(this: (idVec3 *)&v57.eventHash.lookupMask);
  }
  projDecl = this->projDecl;
  if ( !projDecl->hitscan )
  {
    v49 = (idProjectile *)((int (__fastcall *)(idGameLocal *, const idDeclEntityDef *, int, int, int, double))gameLocal->SpawnEntityFromDef)(
                            a1: gameLocal,
                            a2: projDecl->notHitscanInfo.entityDef,
                            a3: -1,
                            a4: -1,
                            a5: -1,
                            a6: v26);
    v50 = idProjectile::CastTo(c: v49);
    if ( v50 == nullptr )
    {
      idEntity::BecomeInactive(this, flags: 1);
      goto LABEL_18;
    }
    if ( idEntityPtr<idEntity const>::operator->(this: &this->currentTarget) != nullptr )
    {
      v51 = idEntityPtr<idEntity const>::operator->(this: &this->currentTarget);
      v52 = v51->presentable;
      v53 = v51;
      if ( v52 == nullptr )
      {
        idEntity::InitPresentableInternal(this: v51);
        v52 = v53->presentable;
      }
      v57.eventPools.list = (idAIEventPool **)1;
      *(idVec3 *)&v57.eventPools.num = vec3_origin;
      if ( v52 != nullptr )
        spawnId = v52->spawnId;
      else
        spawnId = 0;
      v58 = spawnId;
      idVec3::ToMat3(this: v60.mat, result: (idMat3 *)&v57.eventHash.lookupMask);
      v55 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idProjectile::Launch(
        this: v50,
        attacker_: this,
        start: (const idVec3 *)&v57.eventHash.hashSize,
        fireAxis: &v60,
        target: (const idProjectileTarget *)&v57.eventPools,
        initialSpeed: this->projDecl->notHitscanInfo.speed,
        startTime: v56,
        launchTimeOverride: v55);
    }
    goto LABEL_103;
  }
  idFireParms::idFireParms(this: &v59);
  memset(&v63, 0, sizeof(v63));
  v35 = &v61;
  v61.numProjectiles = 0;
  for ( i = 16; i != 0; --i )
  {
    v35 = (idFinishFireResults *)((char *)v35 + 4);
    v35->numProjectiles = 0;
  }
  v37 = this->presentable;
  v59.addSpread = this->projDecl->spread;
  if ( v37 != nullptr || (idEntity::InitPresentableInternal(this), (v37 = this->presentable) != nullptr) )
    v59.attacker.spawnId = v37->spawnId;
  else
    v59.attacker.spawnId = 0;
  weapon = this->weapon;
  weaponDecl = this->weaponDecl;
  v59.start.x = *(float *)&v57.eventHash.hashSize;
  v59.start.y = *(float *)&v57.eventHash.indexSize;
  v59.start.z = *(float *)&v57.eventHash.granularity;
  v59.weapon = weapon;
  v59.wepDef = weaponDecl;
  v40 = idVec3::ToMat3(this: v60.mat, result: (idMat3 *)&v57.eventHash.lookupMask);
  v59.fireAxis.mat[0].x = v40->mat[0].x;
  v59.fireAxis.mat[0].y = v40->mat[0].y;
  v41 = this->projDecl;
  v59.fireAxis.mat[0].z = v40->mat[0].z;
  v59.fireAxis.mat[1].x = v40->mat[1].x;
  v59.fireAxis.mat[1].y = v40->mat[1].y;
  v59.fireAxis.mat[1].z = v40->mat[1].z;
  v57.eventList.list = (idAIEvent **)&v40->mat[2];
  v59.fireAxis.mat[2].x = v40->mat[2].x;
  v59.fireAxis.mat[2].y = v40->mat[2].y;
  v59.fireAxis.mat[2].z = v40->mat[2].z;
  v59.projDef = v41;
  *((_BYTE *)&v59 + 129) &= ~0x20u;
  if ( ai_debugLevel.valueInteger > 0 )
    ((void (__fastcall *)(idRenderWorld *, idColor *, int *, int *, double))clientGame->renderWorld->DebugArrow)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorRed,
      a3: &v57.eventHash.hashSize,
      a4: &v57.eventList.size,
      a5: 5.0);
  if ( (unsigned __int8)idClientGame::TestFire(this: clientGame, fp: &v59, tfr: &v63) == 0 )
  {
LABEL_91:
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v59.targetList);
LABEL_103:
    idTarget_DummyFire::SetBulletsFly(this, _bBulletsFly: true);
    if ( this->numShots >= 0 )
      --this->currentShotsLeft;
    return;
  }
  if ( this->blockFlags == BLOCKED_NONE || (v42 = 0, v63.numTraces <= 0) )
  {
LABEL_88:
    if ( idGameLocal::FinishFire(this: gameLocal, fp: &v59, tfr: &v63, ffr: &v61) )
    {
      fireChannel = this->fireChannel;
      lastShotSound = this->projDecl->lastShotSound;
      this->fireChannel = fireChannel + 1;
      soundShaderParms_t::Clear(this: &v62);
      v62.soundShaderFlags = 0;
      idEntity::StartSoundShader(this, channel: fireChannel, shader: lastShotSound, parms: &v62, peerMask: 0xFFu);
      if ( common->IsServer(this: common) )
      {
        entity = idPresentablePtr<idPresentableProjectile>::operator->(this: &v59.attacker)->entity;
        v48 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idAIEventManager::AddEvent(
          this: &v57,
          result: &gameLocal->aiEventManager,
          eventDecl: this->weaponDecl->gunfireEventDecl,
          curTime: v48,
          originator: entity,
          instigator: nullptr,
          origin: &v59.start,
          delay: 0);
      }
    }
    goto LABEL_91;
  }
  p_surfaceType = &v63.traces[0].c.surfaceType;
  while ( 1 )
  {
    if ( *((float *)p_surfaceType - 24) < 1.0 )
    {
      v44 = (idPlayer *)gameLocal->entities.ptr[p_surfaceType[3]];
      if ( v44 != nullptr
        && v44 != idEntityPtr<idEntity const>::operator->(this: &this->currentTarget)
        && ((this->blockFlags & 4) != 0 && idPlayer::CastTo(c: v44) != nullptr
         || (this->blockFlags & 8) != 0 && idVehicle::CastTo(c: (idVehicle *)v44) != nullptr
         || (this->blockFlags & 2) != 0 && idAI2::CastTo(c: (idAI2 *)v44) != nullptr
         || (this->blockFlags & 1) != 0
         && idEntityPtr<idEntity const>::operator->(this: &this->currentTarget) != nullptr
         && *p_surfaceType != 3
         && *p_surfaceType != 19) )
      {
        break;
      }
    }
    ++v42;
    p_surfaceType += 32;
    if ( v42 >= v63.numTraces )
      goto LABEL_88;
  }
  idTarget_DummyFire::SetBulletsFly(this, _bBulletsFly: false);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v59.targetList);
}


// ========================================================================
// __unwind$524703
// EA  : 0x82CDDF2C
// RVA : 0x00CDDF2C
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_524703()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 3056 + 176));
}


// ========================================================================
// ?ChangeControlState@idTarget_DynamicVehicleAiController@@QAAXPAVidEntity@@W4targetState_t@idTarget_VehicleAi@@@Z
// EA  : 0x82CDDF58
// RVA : 0x00CDDF58
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_DynamicVehicleAiController::ChangeControlState(
        idTarget_DynamicVehicleAiController *this,
        idEntity *activator,
        idTarget_VehicleAi::targetState_t newState)
{
  idPlayer *PlayerFromEntity; // r3
  idEntityPtr<idPlayer> *p_player; // r30
  idGameLocal *v7; // r11
  idPlayer *v8; // r3
  idPlayer *DebugPlayer; // r3
  const idDeclJob *dynamicJob; // r31
  idPlayer *v11; // r3
  int v12; // r30
  idGameLocal *v13; // r11
  int v14; // r31
  idEntityPtr<idVehicleAI> *v15; // r10
  idVehicleAI *v16; // r3
  idVehicleAI *v17; // r3
  int value; // r9
  idVehicleAI *v19; // r3
  idVehicleAI *v20; // r3
  int v21; // r30
  int v22; // r31
  idEntityPtr<idVehicleAI> *v23; // r10
  idVehicleAI *v24; // r3
  idVehicleAI *v25; // r3
  int v26; // r9
  idVehicleAI *v27; // r3
  idVehicleAI *v28; // r3
  const idDeclJob *v29; // r31
  idPlayer *v30; // r3
  int triggeredCount; // r31
  idPlayer *v32; // r3
  idJob *JobByDecl; // r3
  int numNormalVehicles; // r9
  int num; // r10
  signed int v36; // r11
  int v37; // r8
  int v38; // r26
  int v39; // r24
  int v40; // r27
  int v41; // r11
  bool v42; // zf
  int v43; // r29
  idGameLocal *v44; // r11
  int v45; // r31
  int v46; // r30
  idEntityPtr<idVehicleAI> *v47; // r3
  idVehicleAI *v48; // r3
  int v49; // r30
  int v50; // r31
  idEntityPtr<idVehicleAI> *v51; // r10
  idVehicleAI *v52; // r3
  idVehicleAI *v53; // r4
  int v54; // r29
  int v55; // r31
  int v56; // r30
  idEntityPtr<idVehicleAI> *v57; // r10
  idVehicleAI *v58; // r3
  idVehicleAI *v59; // r3
  int v60; // r30
  int v61; // r31
  idEntityPtr<idVehicleAI> *v62; // r10
  idVehicleAI *v63; // r3
  idVehicleAI *v64; // r4
  idGameLocal *v65; // r11
  int v66; // r29
  int v67; // r30
  idEntityPtr<idVehicleAI> *v68; // r10
  idVehicleAI *v69; // r3
  idVehicleAI *v70; // r3
  idEntityPtr<idVehicleAI> *v71; // r31
  idEventArg *v72; // r3
  char *v73; // r10
  _DWORD *v74; // r9
  int i; // ctr
  idVehicleAI *Entity; // r3
  int v77; // r9
  idVehicleAI *v78; // r3
  idVehicleAI *v79; // r3
  int v80; // r9
  idVehicleAI *v81; // r3
  idVehicleAI *v82; // r3
  int v83; // r9
  idVehicleAI *v84; // r3
  idVehicleAI *v85; // r3
  int v86; // r9
  idVehicleAI *v87; // r3
  idVehicleAI *v88; // r3
  int v89; // r29
  int v90; // r30
  idEntityPtr<idVehicleAI> *v91; // r10
  idVehicleAI *v92; // r3
  idVehicleAI *v93; // r3
  int v94; // r9
  idVehicleAI *v95; // r3
  idVehicleAI *v96; // r31
  idEventArg *v97; // r3
  int v98; // r9
  idVehicleAI *v99; // r3
  idVehicleAI *v100; // r3
  int v101; // r9
  idVehicleAI *v102; // r3
  idVehicleAI *v103; // r3
  int v104; // r9
  idVehicleAI *v105; // r3
  idVehicleAI *v106; // r3
  int v107; // r9
  idVehicleAI *v108; // r3
  idVehicleAI *v109; // r3
  int v110[3]; // [sp+50h] [-B0h] BYREF
  char v111; // [sp+5Ch] [-A4h] BYREF
  __int64 v112; // [sp+68h] [-98h]
  idEventArg v113[6]; // [sp+80h] [-80h] BYREF

  p_player = &this->player;
  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity != nullptr )
    p_player->spawnId.value = (gameLocal->spawnIds.ptr[PlayerFromEntity->entityNumber] << 13)
                            | PlayerFromEntity->entityNumber;
  else
    p_player->spawnId.value = 0x1FFF;
  v7 = gameLocal;
  if ( gameLocal->spawnIds.ptr[p_player->spawnId.value & 0x1FFF] == p_player->spawnId.value >> 13 )
  {
    v8 = (idPlayer *)gameLocal->entities.ptr[p_player->spawnId.value & 0x1FFF];
    if ( v8 != nullptr )
    {
      if ( idPlayer::CastTo(c: v8) != nullptr )
        goto LABEL_11;
      v7 = gameLocal;
    }
  }
  DebugPlayer = idGameLocal::GetDebugPlayer(this: v7);
  if ( DebugPlayer != nullptr )
    p_player->spawnId.value = (gameLocal->spawnIds.ptr[DebugPlayer->entityNumber] << 13) | DebugPlayer->entityNumber;
  else
    p_player->spawnId.value = 0x1FFF;
LABEL_11:
  if ( newState == DYNJOB_ENEMY_GONE )
  {
    if ( this->isActive )
    {
      dynamicJob = this->dynamicJob;
      if ( dynamicJob != nullptr )
      {
        v11 = idEntityPtr<idPlayer>::operator->(this: &this->player);
        idPlayer::StartRemovalOfDynamicJob(this: v11, job: dynamicJob);
      }
      v12 = 0;
      v13 = gameLocal;
      if ( this->firstVehicles.num > 0 )
      {
        v14 = 0;
        do
        {
          v15 = &this->firstVehicles.list[v14];
          if ( v13->spawnIds.ptr[v15->spawnId.value & 0x1FFF] == v15->spawnId.value >> 13 )
          {
            v16 = (idVehicleAI *)v13->entities.ptr[v15->spawnId.value & 0x1FFF];
            if ( v16 != nullptr )
              v17 = idVehicleAI::CastTo(c: v16);
            else
              v17 = nullptr;
            v17->hideWhenIdle = true;
            value = this->firstVehicles.list[v14].spawnId.value;
            if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
              && (v19 = (idVehicleAI *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
            {
              v20 = idVehicleAI::CastTo(c: v19);
            }
            else
            {
              v20 = nullptr;
            }
            idVehicleAI::SetForcedRetreatState(this: v20, setState: true);
            v13 = gameLocal;
          }
          ++v12;
          ++v14;
        }
        while ( v12 < this->firstVehicles.num );
      }
      v21 = 0;
      if ( this->numSpecialVehicles > 0 )
      {
        v22 = 0;
        do
        {
          v23 = &this->specialVehicles.list[v22];
          if ( v13->spawnIds.ptr[v23->spawnId.value & 0x1FFF] == v23->spawnId.value >> 13 )
          {
            v24 = (idVehicleAI *)v13->entities.ptr[v23->spawnId.value & 0x1FFF];
            if ( v24 != nullptr )
              v25 = idVehicleAI::CastTo(c: v24);
            else
              v25 = nullptr;
            v25->hideWhenIdle = true;
            v26 = this->specialVehicles.list[v22].spawnId.value;
            if ( gameLocal->spawnIds.ptr[v26 & 0x1FFF] == v26 >> 13
              && (v27 = (idVehicleAI *)gameLocal->entities.ptr[v26 & 0x1FFF]) != nullptr )
            {
              v28 = idVehicleAI::CastTo(c: v27);
            }
            else
            {
              v28 = nullptr;
            }
            idVehicleAI::SetForcedRetreatState(this: v28, setState: true);
            v13 = gameLocal;
          }
          ++v21;
          ++v22;
        }
        while ( v21 < this->numSpecialVehicles );
      }
    }
    this->isActive = false;
    return;
  }
  if ( newState != DYNJOB_ENEMY_RETURN && newState != DYNJOB_INIT_ACTIVATE )
    return;
  if ( this->isActive )
  {
LABEL_151:
    this->isActive = true;
    return;
  }
  v29 = this->dynamicJob;
  if ( v29 != nullptr )
  {
    v30 = idEntityPtr<idPlayer>::operator->(this: &this->player);
    idPlayer::OfferDynamicJob(this: v30, job: v29);
  }
  if ( this->hasBeenActivated )
  {
    v65 = gameLocal;
    v66 = 0;
    if ( this->firstVehicles.num > 0 )
    {
      v67 = 0;
      do
      {
        v68 = &this->firstVehicles.list[v67];
        if ( v65->spawnIds.ptr[v68->spawnId.value & 0x1FFF] == v68->spawnId.value >> 13 )
        {
          v69 = (idVehicleAI *)v65->entities.ptr[v68->spawnId.value & 0x1FFF];
          if ( v69 != nullptr )
          {
            v70 = idVehicleAI::CastTo(c: v69);
            v65 = gameLocal;
          }
          else
          {
            v70 = nullptr;
          }
          if ( (v70->thinkFlags & 1) == 0 )
          {
            v71 = &this->firstVehicles.list[v67];
            v72 = idEventArg::idEventArg(this: v113, data: this);
            v73 = &v111;
            v74 = (_DWORD *)&v72[-1].value.q[3];
            for ( i = 5; i != 0; --i )
            {
              ++v74;
              v73 += 4;
              *(_DWORD *)v73 = *v74;
            }
            Entity = idEntityPtr<idVehicleAI>::GetEntity(this: v71);
            idEventReceiver::PostEventMS(
              this: Entity,
              ev: &EV_Activate,
              time: 0,
              arg1: (const idEventArg *)HIDWORD(v112));
            v65 = gameLocal;
          }
          v77 = this->firstVehicles.list[v67].spawnId.value;
          if ( v65->spawnIds.ptr[v77 & 0x1FFF] == v77 >> 13
            && (v78 = (idVehicleAI *)v65->entities.ptr[v77 & 0x1FFF]) != nullptr )
          {
            v79 = idVehicleAI::CastTo(c: v78);
          }
          else
          {
            v79 = nullptr;
          }
          v79->ignoreEnemy = false;
          v80 = this->firstVehicles.list[v67].spawnId.value;
          if ( gameLocal->spawnIds.ptr[v80 & 0x1FFF] == v80 >> 13
            && (v81 = (idVehicleAI *)gameLocal->entities.ptr[v80 & 0x1FFF]) != nullptr )
          {
            v82 = idVehicleAI::CastTo(c: v81);
          }
          else
          {
            v82 = nullptr;
          }
          v82->hideWhenIdle = false;
          v83 = this->firstVehicles.list[v67].spawnId.value;
          if ( gameLocal->spawnIds.ptr[v83 & 0x1FFF] == v83 >> 13
            && (v84 = (idVehicleAI *)gameLocal->entities.ptr[v83 & 0x1FFF]) != nullptr )
          {
            v85 = idVehicleAI::CastTo(c: v84);
          }
          else
          {
            v85 = nullptr;
          }
          idVehicleAI::SetForcedRetreatState(this: v85, setState: false);
          v86 = this->firstVehicles.list[v67].spawnId.value;
          if ( gameLocal->spawnIds.ptr[v86 & 0x1FFF] == v86 >> 13
            && (v87 = (idVehicleAI *)gameLocal->entities.ptr[v86 & 0x1FFF]) != nullptr )
          {
            v88 = idVehicleAI::CastTo(c: v87);
          }
          else
          {
            v88 = nullptr;
          }
          v88->dynamicVehicleAIController = this;
          v65 = gameLocal;
        }
        ++v66;
        ++v67;
      }
      while ( v66 < this->firstVehicles.num );
    }
    v89 = 0;
    if ( this->numSpecialVehicles > 0 )
    {
      v90 = 0;
      do
      {
        v91 = &this->specialVehicles.list[v90];
        if ( v65->spawnIds.ptr[v91->spawnId.value & 0x1FFF] == v91->spawnId.value >> 13 )
        {
          v92 = (idVehicleAI *)v65->entities.ptr[v91->spawnId.value & 0x1FFF];
          if ( v92 != nullptr )
          {
            v93 = idVehicleAI::CastTo(c: v92);
            v65 = gameLocal;
          }
          else
          {
            v93 = nullptr;
          }
          if ( (v93->thinkFlags & 1) == 0 )
          {
            v94 = this->specialVehicles.list[v90].spawnId.value;
            if ( v65->spawnIds.ptr[v94 & 0x1FFF] == v94 >> 13
              && (v95 = (idVehicleAI *)v65->entities.ptr[v94 & 0x1FFF]) != nullptr )
            {
              v96 = idVehicleAI::CastTo(c: v95);
            }
            else
            {
              v96 = nullptr;
            }
            v97 = idEventArg::idEventArg(this: v113, data: this);
            idEventReceiver::PostEventMS(
              this: v96,
              ev: &EV_Activate,
              time: *(_DWORD *)&v97->type,
              arg1: (const idEventArg *)LODWORD(v97->value.v[1]));
            v65 = gameLocal;
          }
          v98 = this->specialVehicles.list[v90].spawnId.value;
          if ( v65->spawnIds.ptr[v98 & 0x1FFF] == v98 >> 13
            && (v99 = (idVehicleAI *)v65->entities.ptr[v98 & 0x1FFF]) != nullptr )
          {
            v100 = idVehicleAI::CastTo(c: v99);
          }
          else
          {
            v100 = nullptr;
          }
          v100->ignoreEnemy = false;
          v101 = this->specialVehicles.list[v90].spawnId.value;
          if ( gameLocal->spawnIds.ptr[v101 & 0x1FFF] == v101 >> 13
            && (v102 = (idVehicleAI *)gameLocal->entities.ptr[v101 & 0x1FFF]) != nullptr )
          {
            v103 = idVehicleAI::CastTo(c: v102);
          }
          else
          {
            v103 = nullptr;
          }
          v103->hideWhenIdle = false;
          v104 = this->specialVehicles.list[v90].spawnId.value;
          if ( gameLocal->spawnIds.ptr[v104 & 0x1FFF] == v104 >> 13
            && (v105 = (idVehicleAI *)gameLocal->entities.ptr[v104 & 0x1FFF]) != nullptr )
          {
            v106 = idVehicleAI::CastTo(c: v105);
          }
          else
          {
            v106 = nullptr;
          }
          idVehicleAI::SetForcedRetreatState(this: v106, setState: false);
          v107 = this->specialVehicles.list[v90].spawnId.value;
          if ( gameLocal->spawnIds.ptr[v107 & 0x1FFF] == v107 >> 13
            && (v108 = (idVehicleAI *)gameLocal->entities.ptr[v107 & 0x1FFF]) != nullptr )
          {
            v109 = idVehicleAI::CastTo(c: v108);
          }
          else
          {
            v109 = nullptr;
          }
          v109->dynamicVehicleAIController = this;
          v65 = gameLocal;
        }
        ++v89;
        ++v90;
      }
      while ( v89 < this->numSpecialVehicles );
    }
    goto LABEL_151;
  }
  this->hasBeenActivated = true;
  v110[0] = idTarget_DynamicVehicleAiController::CalcDistancesAndDots(this);
  if ( v110[0] < 0 )
  {
    idLib::Warning(fmt: "idTarget_DynamicVehicleAiController::ChangeControlState no closest spawn");
    return;
  }
  triggeredCount = 0;
  if ( this->dynamicJob != nullptr )
  {
    v32 = idEntityPtr<idPlayer>::operator->(this: &this->player);
    JobByDecl = idJobManager::FindJobByDecl(this: &v32->jobManager, jobDecl: this->dynamicJob);
    if ( JobByDecl != nullptr )
      triggeredCount = JobByDecl->triggeredCount;
  }
  numNormalVehicles = this->numNormalVehicles;
  num = this->firstVehicles.num;
  this->vehiclesKilled = triggeredCount;
  v36 = (((unsigned int)(numNormalVehicles - triggeredCount) >> 31) - 1) & (numNormalVehicles - triggeredCount);
  v37 = num - v36;
  v38 = v36;
  if ( v36 > num )
    v38 = num;
  v39 = 0;
  v40 = 0;
  if ( this->allnormalDeadBeforSpecial )
  {
    if ( v36 <= 0 )
    {
      v40 = triggeredCount - numNormalVehicles;
      v39 = this->specialVehicles.num - (triggeredCount - numNormalVehicles);
    }
  }
  else if ( v36 < num )
  {
    v42 = v36 > 0;
    v41 = this->specialVehicles.num;
    if ( v42 )
    {
      v39 = v37;
      if ( v37 > v41 )
        v39 = this->specialVehicles.num;
    }
    else
    {
      v40 = triggeredCount - numNormalVehicles;
      v39 = v41 - (triggeredCount - numNormalVehicles);
    }
  }
  v43 = 0;
  v44 = gameLocal;
  if ( v37 > 0 )
  {
    v45 = 0;
    v46 = v37;
    v43 = v37;
    do
    {
      v47 = &this->firstVehicles.list[v45];
      if ( v44->spawnIds.ptr[v47->spawnId.value & 0x1FFF] == v47->spawnId.value >> 13 )
      {
        v48 = idEntityPtr<idVehicleAI>::GetEntity(this: v47);
        idEventReceiver::PostEventMS(this: v48, ev: &EV_Remove, time: 0);
        v44 = gameLocal;
      }
      --v46;
      ++v45;
    }
    while ( v46 != 0 );
  }
  v49 = 0;
  if ( v38 > 0 )
  {
    v50 = v43;
    do
    {
      v51 = &this->firstVehicles.list[v50];
      if ( v44->spawnIds.ptr[v51->spawnId.value & 0x1FFF] == v51->spawnId.value >> 13 )
      {
        v52 = (idVehicleAI *)v44->entities.ptr[v51->spawnId.value & 0x1FFF];
        if ( v52 != nullptr )
          v53 = idVehicleAI::CastTo(c: v52);
        else
          v53 = nullptr;
        if ( (unsigned __int8)idTarget_DynamicVehicleAiController::SpawnVehicle(this, vehAI: v53, closestSpawn: v110) == 0 )
          return;
        ++this->vehiclesActive;
        v44 = gameLocal;
      }
      ++v49;
      ++v50;
    }
    while ( v49 < v38 );
  }
  v54 = 0;
  if ( v40 > 0 )
  {
    v55 = 0;
    v56 = v40;
    v54 = v40;
    do
    {
      v57 = &this->specialVehicles.list[v55];
      if ( v44->spawnIds.ptr[v57->spawnId.value & 0x1FFF] == v57->spawnId.value >> 13 )
      {
        v58 = (idVehicleAI *)v44->entities.ptr[v57->spawnId.value & 0x1FFF];
        if ( v58 != nullptr )
          v59 = idVehicleAI::CastTo(c: v58);
        else
          v59 = nullptr;
        idEventReceiver::PostEventMS(this: v59, ev: &EV_Remove, time: 0);
        v44 = gameLocal;
      }
      --v56;
      ++v55;
    }
    while ( v56 != 0 );
  }
  v60 = 0;
  if ( v39 <= 0 )
    goto LABEL_151;
  v61 = v54;
  do
  {
    v62 = &this->specialVehicles.list[v61];
    if ( v44->spawnIds.ptr[v62->spawnId.value & 0x1FFF] == v62->spawnId.value >> 13 )
    {
      v63 = (idVehicleAI *)v44->entities.ptr[v62->spawnId.value & 0x1FFF];
      if ( v63 != nullptr )
        v64 = idVehicleAI::CastTo(c: v63);
      else
        v64 = nullptr;
      if ( (unsigned __int8)idTarget_DynamicVehicleAiController::SpawnVehicle(this, vehAI: v64, closestSpawn: v110) == 0 )
        return;
      ++this->numSpecialVehicles;
      v44 = gameLocal;
    }
    ++v60;
    ++v61;
  }
  while ( v60 < v39 );
  this->isActive = true;
}


// ========================================================================
// ??0idTarget_TimedEvents@@QAA@XZ
// EA  : 0x82CDEAA0
// RVA : 0x00CDEAA0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_TimedEvents *__fastcall idTarget_TimedEvents::idTarget_TimedEvents(idTarget_TimedEvents *this)
{
  idEntity::idEntity(this);
  this->nextEvent = 0;
  this->__vftable = (idTarget_TimedEvents_vtbl *)&idTarget_TimedEvents::`vftable';
  this->activateTime = -1;
  this->events.granularity = 0;
  this->events.memTag = 5;
  this->events.listStatic = 0;
  this->events.list = nullptr;
  this->events.size = 0;
  this->events.num = 0;
  this->reusable = false;
  this->storedActivator.spawnId.value = 0x1FFF;
  this->storedActivatorName.allocedAndFlag = 20;
  this->storedActivatorName.data = this->storedActivatorName.baseBuffer;
  this->storedActivatorName.len = 0;
  this->storedActivatorName.baseBuffer[0] = 0;
  return this;
}


// ========================================================================
// __unwind$526582
// EA  : 0x82CDEB4C
// RVA : 0x00CDEB4C
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_526582()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?OnActivate@idTarget_ShowTargetHealth@@MAAXPAVidEntity@@@Z
// EA  : 0x82CDECA0
// RVA : 0x00CDECA0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_ShowTargetHealth::OnActivate(idTarget_ShowTargetHealth *this, idEntity *activator)
{
  idGame *v3; // r3
  idTurretGunner *v4; // r3
  idTurretGunner *v5; // r3
  int i; // r24
  idPlayer *Player; // r3
  idPlayer *v8; // r25
  int v9; // r29
  int v10; // r30
  int value; // r9
  idEntity *v12; // r3
  idEntity *v13; // r31
  idPresentable *v14; // r3
  int v15; // r3
  idPresentable *presentable; // r3
  int v17; // r3
  idEntityPtr<idAI2> v18; // [sp+50h] [-50h] BYREF

  if ( this->turretGunnerFlag )
  {
    v3 = common->Game(this: common);
    v4 = (idTurretGunner *)v3->FindEntityUsingClass(this: v3, a2: nullptr, a3: "idTurretGunner");
    v5 = idTurretGunner::CastTo(c: v4);
    if ( v5 != nullptr )
    {
      v18.spawnId.value = (gameLocal->spawnIds.ptr[v5->entityNumber] << 13) | v5->entityNumber;
      idList<idEntityPtr<idEntity>,5>::AddUnique(this: (idList<idEntityPtr<idAI2>,5> *)&this->trackedTargets, obj: &v18);
    }
  }
  for ( i = 0; i < 6; ++i )
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i);
    v8 = Player;
    if ( Player != nullptr )
    {
      if ( this->isShowing || this->trackedTargets.num <= 0 )
      {
        presentable = Player->presentable;
        if ( presentable != nullptr )
          v17 = (int)presentable->GetPlayerInterface_2(this: presentable);
        else
          v17 = 0;
        idPlayerHud::ClearWatchTargets(this: (idPlayerHud *)(v17 + 35096));
      }
      else
      {
        v9 = 0;
        v10 = 0;
        do
        {
          value = this->trackedTargets.list[v10].spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
            && (v12 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v13 = idEntity::CastTo(c: v12);
          }
          else
          {
            v13 = nullptr;
          }
          v14 = v8->presentable;
          if ( v14 != nullptr )
            v15 = (int)v14->GetPlayerInterface_2(this: v14);
          else
            v15 = 0;
          idPlayerHud::AddWatchTarget(this: (idPlayerHud *)(v15 + 35096), target: v13);
          ++v9;
          ++v10;
        }
        while ( v9 < this->trackedTargets.num );
      }
    }
  }
  this->isShowing = (_cntlzw(this->isShowing) & 0x20) != 0;
}


// ========================================================================
// ?OnActivate@idTarget_VehicleAi@@UAAXPAVidEntity@@@Z
// EA  : 0x82CDEE58
// RVA : 0x00CDEE58
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_VehicleAi::OnActivate(idTarget_VehicleAi *this, idEntity *activator)
{
  int v4; // r27
  int v5; // r29
  int value; // r9
  idEntity *v7; // r3
  idVehicleAI *v8; // r3
  idVehicleAI *v9; // r3
  idVehicleAI *v10; // r31
  idTarget_VehicleAi::targetState_t state; // r11
  idEventArg *v12; // r3
  idEventArg *v13; // r3
  int v14; // r9
  idEntity *v15; // r3
  idTarget_DynamicVehicleAiController *v16; // r3
  idTarget_DynamicVehicleAiController *v17; // r3
  idEventArg v18[5]; // [sp+50h] [-70h] BYREF

  v4 = 0;
  if ( this->targets.num > 0 )
  {
    v5 = 0;
    do
    {
      value = this->targets.list[v5].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v8 = (idVehicleAI *)idEntity::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      v9 = idVehicleAI::CastTo(c: v8);
      v10 = v9;
      if ( v9 != nullptr )
      {
        state = this->state;
        if ( state != DYNJOB_INIT_ACTIVATE )
        {
          switch ( state )
          {
            case DYNJOB_ENEMY_GONE:
              v9->hideWhenIdle = true;
              idVehicleAI::SetForcedRetreatState(this: v9, setState: true);
              break;
            case DYNJOB_ENEMY_RETURN:
              if ( (v9->thinkFlags & 1) == 0 )
              {
                v13 = idEventArg::idEventArg(this: v18, data: this);
                idEventReceiver::PostEventMS(
                  this: v10,
                  ev: &EV_Activate,
                  time: *(_DWORD *)&v13->type,
                  arg1: (const idEventArg *)LODWORD(v13->value.v[1]));
              }
              v10->ignoreEnemy = false;
              v10->hideWhenIdle = false;
              idVehicleAI::SetForcedRetreatState(this: v10, setState: false);
              break;
            case FORCE_PLAYER_ENEMY:
              v9->setup.forcePlayerEnemy = true;
              break;
            default:
              break;
          }
        }
        else
        {
          if ( (v9->thinkFlags & 1) == 0 )
          {
            v12 = idEventArg::idEventArg(this: v18, data: this);
            idEventReceiver::PostEventMS(
              this: v10,
              ev: &EV_Activate,
              time: *(_DWORD *)&v12->type,
              arg1: (const idEventArg *)LODWORD(v12->value.v[1]));
          }
          idVehicleAI::SetForcedRetreatState(this: v10, setState: false);
        }
      }
      if ( v4 < this->targets.num
        && (v14 = this->targets.list[v5].spawnId.value, gameLocal->spawnIds.ptr[v14 & 0x1FFF] == v14 >> 13)
        && (v15 = gameLocal->entities.ptr[v14 & 0x1FFF]) != nullptr )
      {
        v16 = (idTarget_DynamicVehicleAiController *)idEntity::CastTo(c: v15);
      }
      else
      {
        v16 = nullptr;
      }
      v17 = idTarget_DynamicVehicleAiController::CastTo(c: v16);
      if ( v17 != nullptr )
        idTarget_DynamicVehicleAiController::ChangeControlState(this: v17, activator, newState: this->state);
      ++v4;
      ++v5;
    }
    while ( v4 < this->targets.num );
  }
}


// ========================================================================
// ?Spawn@idTarget_JobTriggered@@QAAXXZ
// EA  : 0x82CDF0C0
// RVA : 0x00CDF0C0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_JobTriggered::Spawn(idTarget_JobTriggered *this)
{
  idEntityPtr<idAI2> *v2; // r3

  v2 = idList<idEntityPtr<idAI2>,5>::Alloc(this: (idList<idEntityPtr<idAI2>,5> *)&gameLocal->jobTriggeredTargets);
  if ( this != nullptr )
    v2->spawnId.value = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
  else
    v2->spawnId.value = 0x1FFF;
}


// ========================================================================
// ?SpawnSingleEntity@idTarget_Spawn@@QAAPAVidEntity@@ABVidVec3@@ABVidMat3@@_N@Z
// EA  : 0x82CDF208
// RVA : 0x00CDF208
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idEntity *__fastcall idTarget_Spawn::SpawnSingleEntity(
        idTarget_Spawn *this,
        const idVec3 *origin,
        const idMat3 *axis,
        bool checkSafeSpawn)
{
  unsigned __int64 v8; // r6
  const char *v9; // r7
  int logIndex; // r11
  unsigned int seed; // r7
  unsigned int v13; // r3
  idClientGame *v14; // r8
  int v15; // r7
  int v16; // r30
  int *v17; // r9
  char *v18; // r10
  int i; // ctr
  double x; // fp5
  double y; // fp3
  double z; // fp1
  int v23; // r22
  idSpawnerEntityDef *v24; // r11
  idDeclEntityDef *v25; // r23
  unsigned __int64 v26; // r6
  const char *v27; // r7
  char *data; // r4
  const idDecl *v29; // r3
  const idDeclEntityDef *v30; // r30
  unsigned __int64 v31; // r6
  const char *v32; // r7
  idGameLocal_vtbl *v33; // r27
  idTypeInfoSettings *v34; // r3
  int v35; // r30
  unsigned __int64 v36; // r6
  const char *v37; // r7
  double v38; // fp8
  idAI2 *v39; // r3
  idAI2 *v40; // r27
  int value; // r11
  idAICombatHint::combatHintClass_t combatHintClass; // r11
  int v43; // r26
  idGameLocal *v44; // r10
  int v45; // r28
  idEntityPtr<idEntity> *v46; // r11
  int v47; // r8
  idEntity *v48; // r3
  idEntity *v49; // r4
  idPLogScope v50; // [sp+50h] [-B0h] BYREF
  idPLogScope v51; // [sp+58h] [-A8h] BYREF
  idPLogScope v52; // [sp+60h] [-A0h] BYREF
  idTypeInfoSettings v53; // [sp+68h] [-98h] BYREF
  int v54; // [sp+7Ch] [-84h] BYREF
  idBounds v55; // [sp+80h] [-80h] BYREF

  RD_EventBegin(name: "idTarget_Spawn::SpawnSingleEntity");
  LODWORD(v8) = "idTarget_Spawn::SpawnSingleEntity";
  HIDWORD(v8) = 2;
  idPLogScope::idPLogScope(this: &v51, pl: &pLog, gMask: v8, label: v9);
  if ( g_traceSpawn.valueInteger > 0 )
    idCVar::SetInteger(this: &g_traceSpawn, newValue: g_traceSpawn.valueInteger - 1, force: true);
  v50.logIndex = this->entityDefs.num;
  logIndex = v50.logIndex;
  if ( v50.logIndex <= 0 )
  {
    idLib::Warning(fmt: "'%s' attempted to spawn an entity without any entityDefs defined.", this->name.data);
    idPLogScope::~idPLogScope(this: &v51);
    RD_EventEnd();
    return nullptr;
  }
  seed = clientGame->random.seed;
  __twllei(v50.logIndex, 0);
  v13 = 1664525 * seed + 1013904223;
  clientGame->random.seed = v13;
  v14 = clientGame;
  v15 = (v13 >> 10) & 0x7FFF;
  v16 = v15 % logIndex;
  __twlgei(logIndex & ~(__ROL4__(v15, 1) - 1), 0xFFFFFFFF);
  if ( checkSafeSpawn )
  {
    v17 = &v54;
    v18 = &this->entityDefs.list[v16].text.baseBuffer[16];
    for ( i = 6; i != 0; --i )
    {
      v18 += 4;
      *++v17 = *(_DWORD *)v18;
    }
    x = origin->x;
    y = origin->y;
    z = origin->z;
    v55.b[0].x = origin->x + (float)(v55.b[0].x - (float)4.0);
    v55.b[0].y = (float)y + (float)(v55.b[0].y - (float)4.0);
    v55.b[0].z = (float)z + (float)(v55.b[0].z - (float)4.0);
    v55.b[1].x = (float)x + (float)(v55.b[1].x + (float)4.0);
    v55.b[1].y = (float)y + (float)(v55.b[1].y + (float)4.0);
    v55.b[1].z = (float)z + (float)(v55.b[1].z + (float)4.0);
    if ( idClip::GetEntitiesTouchingBounds(
           this: &v14->clip,
           bounds: &v55,
           clipMask: 99840,
           entityList: &v50.logIndex,
           maxCount: 1) > 0 )
      goto LABEL_9;
  }
  v23 = v16;
  v24 = &this->entityDefs.list[v16];
  v50.logIndex = (int)&v24->text;
  v25 = nullptr;
  if ( idStr::Find(searchIn: v24->text.data, searchFor: ".decl", casesensitive: false, start: 0, end: v24->text.len) <= -1 )
  {
    RD_EventBegin(name: "idTarget_Spawn::SpawnSingleEntity - Reparse");
    LODWORD(v31) = "idTarget_Spawn::SpawnSingleEntity - Reparse";
    HIDWORD(v31) = 2;
    idPLogScope::idPLogScope(this: &v50, pl: &pLog, gMask: v31, label: v32);
    v25 = idDeclInfoTemplate<idDeclEntityDef>::AllocDecl(this: &idDeclEntityDef::resourceList);
    idResource::SetName(this: &v25->idDecl, _name: this->entityDefs.list[v23].name.data);
    idDecl::SetText(this: &v25->idDecl, text: this->entityDefs.list[v23].text.data, length: 0);
    idDecl::ReParse(this: &v25->idDecl, fromDisk: false);
    v30 = v25;
    idPLogScope::~idPLogScope(this: &v50);
  }
  else
  {
    RD_EventBegin(name: "idTarget_Spawn::SpawnSingleEntity - Find");
    LODWORD(v26) = "idTarget_Spawn::SpawnSingleEntity - Find";
    HIDWORD(v26) = 2;
    idPLogScope::idPLogScope(this: &v50, pl: &pLog, gMask: v26, label: v27);
    data = this->entityDefs.list[v23].text.data;
    if ( data != nullptr )
      v29 = idDeclInfo::FindWithInheritance(this: &idDeclEntityDef::resourceList, name: data, makeDefault: false);
    else
      v29 = nullptr;
    v30 = (const idDeclEntityDef *)v29;
    if ( v29 == nullptr )
      idLib::Warning(
        fmt: "Missing target/spawn entityDef decl file '%s'.  Re-save the map.",
        this->entityDefs.list[v23].text.data);
    idPLogScope::~idPLogScope(this: &v50);
  }
  RD_EventEnd();
  v33 = gameLocal->__vftable;
  v34 = idTypeInfoSettings::idTypeInfoSettings(this: &v53);
  v35 = (int)v33->CreateEntityFromDef(this: gameLocal, a2: v30, a3: v34);
  if ( v35 == 0 )
  {
    idLib::Warning(
      fmt: "'%s' - failed to spawn entity from '%s'.",
      this->name.data,
      this->entityDefs.list[v23].name.data);
    if ( v25 != nullptr )
      ((void (__fastcall *)(idDeclEntityDef *, int))v25->dtr_idResource)(a1: v25, a2: 1);
LABEL_9:
    idPLogScope::~idPLogScope(this: &v51);
    RD_EventEnd();
    return nullptr;
  }
  RD_EventBegin(name: "idTarget_Spawn::SpawnSingleEntity - other");
  LODWORD(v36) = "idTarget_Spawn::SpawnSingleEntity - other";
  HIDWORD(v36) = 2;
  idPLogScope::idPLogScope(this: &v52, pl: &pLog, gMask: v36, label: v37);
  idEntity::SetName(this: (idEntity *)v35, newName: &byte_8200D768);
  *(float *)(v35 + 44) = origin->x;
  *(float *)(v35 + 48) = origin->y;
  *(float *)(v35 + 52) = origin->z;
  v50.logIndex = (int)&axis->mat[1];
  *(float *)(v35 + 56) = axis->mat[0].x;
  v50.logIndex = v35 + 68;
  *(float *)(v35 + 60) = axis->mat[0].y;
  v50.logIndex = v35 + 80;
  *(float *)(v35 + 64) = axis->mat[0].z;
  v50.logIndex = v35 + 44;
  v38 = axis->mat[1].x;
  v50.logIndex = (int)&axis->mat[2];
  *(float *)(v35 + 68) = v38;
  *(float *)(v35 + 72) = axis->mat[1].y;
  *(float *)(v35 + 76) = axis->mat[1].z;
  *(float *)(v35 + 80) = axis->mat[2].x;
  *(float *)(v35 + 84) = axis->mat[2].y;
  *(float *)(v35 + 88) = axis->mat[2].z;
  v39 = idAI2::CastTo(c: (idAI2 *)v35);
  v40 = v39;
  if ( v39 != nullptr )
  {
    if ( this->spawnEditable.groupName.len != 0 )
      idStr::operator=(this: &v39->aiEditable.groupName, text: &this->spawnEditable.groupName);
    if ( idEntityPtr<idEntity const>::operator->(this: &this->spawnEditable.deathTrigger) != nullptr )
    {
      value = this->spawnEditable.deathTrigger.spawnId.value;
      v50.logIndex = (int)&v40->aiEditable.death.trigger;
      v40->aiEditable.death.trigger.spawnId.value = value;
    }
    if ( this->spawnEditable.useTraversalClassA )
      v40->aiEditable.movement.useTraversalClassA = true;
    if ( this->spawnEditable.useTraversalClassB )
      v40->aiEditable.movement.useTraversalClassB = true;
    if ( this->spawnEditable.useTraversalClassC )
      v40->aiEditable.movement.useTraversalClassC = true;
    if ( this->spawnEditable.useTraversalClassD )
      v40->aiEditable.movement.useTraversalClassD = true;
    if ( this->spawnEditable.useTraversalClassE )
      v40->aiEditable.movement.useTraversalClassE = true;
    combatHintClass = this->spawnEditable.combatHintClass;
    if ( combatHintClass != CLASS_ALL )
      v40->aiEditable.movement.combatHintClass = combatHintClass;
    if ( this->spawnEditable.actionScript.num != 0 )
      idList<idScriptAction,5>::operator=(
        this: &v40->aiEditable.spawnSettings.actionScript,
        other: &this->spawnEditable.actionScript);
    if ( this->spawnEditable.coverRadius > 0.0 )
      v40->aiEditable.cover.coverRadius = this->spawnEditable.coverRadius;
    if ( this->spawnEditable.maxEnemyCoverDistance > 0.0 )
      v40->aiEditable.cover.maxEnemyCoverDistance = this->spawnEditable.maxEnemyCoverDistance;
  }
  if ( !this->spawnEditable.copyTargets )
    idEntity::ClearTargets(this: (idEntity *)v35);
  if ( v40 != nullptr )
  {
    v43 = 0;
    if ( this->spawnEditable.additionalTargets.num > 0 )
    {
      v44 = gameLocal;
      v45 = 0;
      do
      {
        v46 = &this->spawnEditable.additionalTargets.list[v45];
        v50.logIndex = (int)v46;
        v47 = v46->spawnId.value;
        if ( v44->spawnIds.ptr[v46->spawnId.value & 0x1FFF] == v46->spawnId.value >> 13 )
        {
          v50.logIndex = (int)v46;
          if ( v44->spawnIds.ptr[v47 & 0x1FFF] == v47 >> 13 && (v48 = v44->entities.ptr[v47 & 0x1FFF]) != nullptr )
            v49 = idEntity::CastTo(c: v48);
          else
            v49 = nullptr;
          idEntity::AddTarget(this: v40, target: v49);
          v44 = gameLocal;
        }
        ++v43;
        ++v45;
      }
      while ( v43 < this->spawnEditable.additionalTargets.num );
    }
  }
  idPLogScope::~idPLogScope(this: &v52);
  RD_EventEnd();
  idEntity::SetName(this: (idEntity *)v35, newName: this->entityDefs.list[v23].name.data);
  gameLocal->SpawnEntity(this: gameLocal, a2: (idEntity *)v35, a3: -1, a4: -1, a5: -1);
  v50.logIndex = *(_DWORD *)(v35 + 492);
  this->lastSpawned.spawnId.value = (gameLocal->spawnIds.ptr[v50.logIndex] << 13) | v50.logIndex;
  idEventReceiver::PostEventMS(this: (idEventReceiver *)v35, ev: &EV_Show, time: 0);
  if ( v25 != nullptr )
    ((void (__fastcall *)(idDeclEntityDef *, int))v25->dtr_idResource)(a1: v25, a2: 1);
  idPLogScope::~idPLogScope(this: &v51);
  RD_EventEnd();
  return (idEntity *)v35;
}


// ========================================================================
// __unwind$527762
// EA  : 0x82CDF8E0
// RVA : 0x00CDF8E0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_527762()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 152));
}


// ========================================================================
// __unwind$527763
// EA  : 0x82CDF908
// RVA : 0x00CDF908
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_527763()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 88));
}


// ========================================================================
// __unwind$527764
// EA  : 0x82CDF930
// RVA : 0x00CDF930
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_527764()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 153));
}


// ========================================================================
// __unwind$527765
// EA  : 0x82CDF958
// RVA : 0x00CDF958
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_527765()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 80));
}


// ========================================================================
// __unwind$527766
// EA  : 0x82CDF980
// RVA : 0x00CDF980
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_527766()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 154));
}


// ========================================================================
// __unwind$527767
// EA  : 0x82CDF9A8
// RVA : 0x00CDF9A8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_527767()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 80));
}


// ========================================================================
// __unwind$527768
// EA  : 0x82CDF9D0
// RVA : 0x00CDF9D0
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_527768()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 155));
}


// ========================================================================
// __unwind$527769
// EA  : 0x82CDF9F8
// RVA : 0x00CDF9F8
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_527769()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 96));
}


// ========================================================================
// ?SpawnEntity@idTarget_Spawn@@AAA_NXZ
// EA  : 0x82CDFA20
// RVA : 0x00CDFA20
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

int __fastcall idTarget_Spawn::SpawnEntity(idTarget_Spawn *this)
{
  int value; // r10
  idEntity *v4; // r3
  idTarget_Spawn *v5; // r3
  int v6; // r10

  if ( this->entityDefs.num <= 0 )
  {
    idLib::Warning(fmt: "'%s' attempted to spawn an entity without any entityDefs defined.", this->name.data);
    return 0;
  }
  value = this->spawnEditable.spawnAt.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
    || (v4 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
    || (v5 = (idTarget_Spawn *)idEntity::CastTo(c: v4)) == nullptr )
  {
    v5 = this;
  }
  if ( idTarget_Spawn::SpawnSingleEntity(
         this,
         origin: &v5->spawnPosition,
         axis: &v5->spawnOrientation,
         checkSafeSpawn: this->spawnEditable.safeSpawnFlag) == nullptr )
    return 0;
  v6 = this->numPendingSpawns - 1;
  ++this->count;
  this->numPendingSpawns = v6;
  return 1;
}


// ========================================================================
// ?Event_RetrySpawn@idTarget_Spawn@@AAA?AVeventVoid@@XZ
// EA  : 0x82CDFB00
// RVA : 0x00CDFB00
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_Spawn *__fastcall idTarget_Spawn::Event_RetrySpawn(idTarget_Spawn *this, idTarget_Spawn *result)
{
  char v4; // r11
  int value; // r9
  idEntity *v6; // r3
  idTarget_Spawn *v7; // r3
  int v8; // r8

  if ( result->spawnEditable.safeSpawnFlag || result->numPendingSpawns == 1 )
  {
    idTarget_Spawn::SpawnEntity(this: result);
  }
  else
  {
    do
    {
      if ( result->entityDefs.num > 0 )
      {
        value = result->spawnEditable.spawnAt.spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
          || (v6 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
          || (v7 = (idTarget_Spawn *)idEntity::CastTo(c: v6)) == nullptr )
        {
          v7 = result;
        }
        if ( idTarget_Spawn::SpawnSingleEntity(
               this: result,
               origin: &v7->spawnPosition,
               axis: &v7->spawnOrientation,
               checkSafeSpawn: result->spawnEditable.safeSpawnFlag) != nullptr )
        {
          v4 = 1;
          v8 = result->numPendingSpawns - 1;
          ++result->count;
          result->numPendingSpawns = v8;
        }
        else
        {
          v4 = 0;
        }
      }
      else
      {
        idLib::Warning(fmt: "'%s' attempted to spawn an entity without any entityDefs defined.", result->name.data);
        v4 = 0;
      }
    }
    while ( v4 != 0 && result->numPendingSpawns > 0 );
  }
  if ( result->numPendingSpawns > 0 )
    idEventReceiver::PostEventMS(this: result, ev: &EV_RetrySpawn, time: 500);
  return this;
}


// ========================================================================
// ??0idTarget_Spawn@@QAA@XZ
// EA  : 0x82CDFD88
// RVA : 0x00CDFD88
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

idTarget_Spawn *__fastcall idTarget_Spawn::idTarget_Spawn(idTarget_Spawn *this)
{
  idEntity::idEntity(this);
  this->count = 0;
  this->__vftable = (idTarget_Spawn_vtbl *)&idTarget_Spawn::`vftable';
  this->nextSpawnTime = 0;
  this->numPendingSpawns = 0;
  idTarget_Spawn::idSpawnSettings::idSpawnSettings(this: &this->spawnEditable);
  this->entityDefs.granularity = 0;
  this->entityDefs.memTag = 5;
  this->entityDefs.listStatic = 0;
  this->entityDefs.list = nullptr;
  this->entityDefs.size = 0;
  this->entityDefs.num = 0;
  this->lastSpawned.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// __unwind$528680
// EA  : 0x82CDFE08
// RVA : 0x00CDFE08
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_528680()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$528681
// EA  : 0x82CDFE30
// RVA : 0x00CDFE30
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void _unwind_528681()
{
  int v0; // r12

  idTarget_Spawn::idSpawnSettings::~idSpawnSettings(this: (idTarget_Spawn::idSpawnSettings *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                            + 812));
}


// ========================================================================
// ?OnActivate@idTarget_Spawn@@EAAXPAVidEntity@@@Z
// EA  : 0x82CDFF88
// RVA : 0x00CDFF88
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __fastcall idTarget_Spawn::OnActivate(idTarget_Spawn *this, idEntity *activator)
{
  int count; // r9
  int maxCount; // r10
  int spawnAtOnce; // r11
  int v6; // r10
  int v7; // r10
  int GameMs; // r3
  int minSpawnInterval; // r9
  signed int v10; // r11
  int v11; // r11
  unsigned int seed; // r8
  unsigned int v13; // r4
  int v14; // r9
  unsigned int v15; // r5
  char v16; // [sp+50h] [-30h] BYREF

  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->nextSpawnTime )
  {
    count = this->count;
    maxCount = this->spawnEditable.maxCount;
    if ( count < maxCount || maxCount == 0 )
    {
      if ( this->entityDefs.num > 0 )
      {
        spawnAtOnce = this->spawnEditable.spawnAtOnce;
        if ( maxCount != 0 )
        {
          v6 = maxCount - this->numPendingSpawns - count;
          if ( spawnAtOnce > v6 )
            spawnAtOnce = v6;
        }
        if ( spawnAtOnce > 0 )
        {
          v7 = spawnAtOnce + this->numPendingSpawns;
          this->numPendingSpawns = v7;
          if ( spawnAtOnce == v7 )
            idTarget_Spawn::Event_RetrySpawn(this: (idTarget_Spawn *)&v16, result: this);
        }
      }
      else
      {
        idLib::Warning(fmt: "'%s' attempted to spawn an entity without any entityDefs defined.", this->name.data);
      }
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      minSpawnInterval = this->spawnEditable.minSpawnInterval;
      v10 = this->spawnEditable.maxSpawnInterval - minSpawnInterval;
      if ( this->spawnEditable.maxSpawnInterval == minSpawnInterval )
      {
        v11 = 0;
      }
      else
      {
        seed = clientGame->random.seed;
        __twllei(v10, 0);
        v13 = 1664525 * seed + 1013904223;
        clientGame->random.seed = v13;
        v14 = (v13 >> 10) & 0x7FFF;
        v15 = v10 & ~(__ROL4__(v14, 1) - 1);
        v11 = v14 % v10;
        __twlgei(v15, 0xFFFFFFFF);
      }
      this->nextSpawnTime = this->spawnEditable.minSpawnInterval + v11 + GameMs;
    }
  }
}


// ========================================================================
// `dynamic initializer for 'g_traceSpawn''
// EA  : 0x83379550
// RVA : 0x01379550
// PDB : w:\tech5\tungsten\game\entities\target.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_traceSpawn__()
{
  idCVar::idCVar(
    this: &g_traceSpawn,
    name: "g_traceSpawn",
    value: "0",
    flags: 2,
    description: "number of times to capture XTraces for target spawner",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_traceSpawn__);
}

