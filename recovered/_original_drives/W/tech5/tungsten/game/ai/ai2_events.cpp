
// ========================================================================
// ?Event_MoveToScenepoint@idAI2@@QAA?AVeventVoid@@PAVidScenePoint@@W4moveToScenePointFlags_t@@@Z
// EA  : 0x82A34DA8
// RVA : 0x00A34DA8
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_MoveToScenepoint(
        idAI2 *this,
        const idEntity *result,
        idScenePoint *scenePoint,
        moveToScenePointFlags_t mtspFlags)
{
  idAI2::Action_MoveToScenePoint(this, result, scenepoint: scenePoint, mtspFlags);
  return this;
}


// ========================================================================
// ?Event_MoveToPathPoint@idAI2@@QAA?AVeventVoid@@PBVidEntity@@@Z
// EA  : 0x82A34DD8
// RVA : 0x00A34DD8
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_MoveToPathPoint(idAI2 *this, const idEntity *result, const idEntity *pathPoint)
{
  idAI2::Action_MoveToPathPoint(this, result, pathPoint);
  return this;
}


// ========================================================================
// ?Event_SetAlertCycle@idAI2@@QAA?AVeventVoid@@W4alertCycle_t@@@Z
// EA  : 0x82A34E08
// RVA : 0x00A34E08
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_SetAlertCycle(idAI2 *this, const idEntity *result, alertCycle_t alertCycle)
{
  idAI2::Action_SetAlertCycle(this, result, alertCycle);
  return this;
}


// ========================================================================
// ?Event_SetCallback@idAI2@@QAA?AVeventInt@@XZ
// EA  : 0x82A34E38
// RVA : 0x00A34E38
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_SetCallback(idAI2 *this, eventInt *result)
{
  eventInt::eventInt((eventInt *)this, i: 1);
  return this;
}


// ========================================================================
// ?Event_GetCurrentAIEventClass@idAI2@@QAA?AVeventInt@@XZ
// EA  : 0x82A34E70
// RVA : 0x00A34E70
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_GetCurrentAIEventClass(idAI2 *this, eventInt *result)
{
  eventInt::eventInt((eventInt *)this, i: 0);
  return this;
}


// ========================================================================
// ?Event_GetLastAIEventClass@idAI2@@QAA?AVeventInt@@XZ
// EA  : 0x82A34EA8
// RVA : 0x00A34EA8
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_GetLastAIEventClass(idAI2 *this, eventInt *result)
{
  eventInt::eventInt((eventInt *)this, i: result[14081].value);
  return this;
}


// ========================================================================
// ?Event_GetLastAIEventOrigin@idAI2@@QAA?AVeventVector@@XZ
// EA  : 0x82A34EE8
// RVA : 0x00A34EE8
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_GetLastAIEventOrigin(idAI2 *this, eventVector *result)
{
  eventVector::eventVector((eventVector *)this, v: &result[4694].value);
  return this;
}


// ========================================================================
// ?Event_GetCurrentPlayerInteractionState@idAI2@@QAA?AVeventInt@@PBVidEntity@@@Z
// EA  : 0x82A34F20
// RVA : 0x00A34F20
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_GetCurrentPlayerInteractionState(idAI2 *this, idAI2 *result, idPlayer *ent)
{
  idPlayer *v5; // r3
  playerInteractionState_t PlayerInteractionState; // r3

  v5 = idPlayer::CastTo(c: ent);
  PlayerInteractionState = idAI2::Job_GetPlayerInteractionState(this: result, player: v5);
  eventInt::eventInt((eventInt *)this, i: PlayerInteractionState);
  return this;
}


// ========================================================================
// ?Event_JobApproach@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA  : 0x82A34F78
// RVA : 0x00A34F78
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_JobApproach(idAI2 *this, idAI2 *result, idEntity *playerEnt, bool playVO)
{
  const idDeclVoiceOver *v5; // r3

  v5 = idAI2::Job_Approach(this: result, playerEnt, playVO);
  eventDecl::eventDecl((eventDecl *)this, decl: v5);
  return this;
}


// ========================================================================
// ?Event_NonJobVO@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA  : 0x82A34FC0
// RVA : 0x00A34FC0
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_NonJobVO(idAI2 *this, eventDecl *result, idEntity *playerEnt, int playVO)
{
  idLib::Warning(fmt: "This does nothing right now!", result, playerEnt, playVO);
  eventDecl::eventDecl((eventDecl *)this, decl: nullptr);
  return this;
}


// ========================================================================
// ?Event_JobOffer@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA  : 0x82A35008
// RVA : 0x00A35008
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_JobOffer(idAI2 *this, idAI2 *result, idEntity *playerEnt, bool playVO)
{
  const idDeclVoiceOver *v5; // r3

  v5 = idAI2::Job_Offer(this: result, playerEnt, playVO);
  eventDecl::eventDecl((eventDecl *)this, decl: v5);
  return this;
}


// ========================================================================
// ?Event_JobMessageVO@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA  : 0x82A35050
// RVA : 0x00A35050
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_JobMessageVO(idAI2 *this, idAI2 *result, idEntity *playerEnt, bool playVO)
{
  const idDeclVoiceOver *v5; // r3

  v5 = idAI2::Job_MessageVO(this: result, playerEnt, playVO, checkAIType: true);
  eventDecl::eventDecl((eventDecl *)this, decl: v5);
  return this;
}


// ========================================================================
// ?Event_JobEnd@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA  : 0x82A350A0
// RVA : 0x00A350A0
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_JobEnd(idAI2 *this, idAI2 *result, idEntity *playerEnt, bool playVO)
{
  const idDeclVoiceOver *v5; // r3

  v5 = idAI2::Job_End(this: result, playerEnt, playVO);
  eventDecl::eventDecl((eventDecl *)this, decl: v5);
  return this;
}


// ========================================================================
// ?Event_JobComplete@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA  : 0x82A350E8
// RVA : 0x00A350E8
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_JobComplete(idAI2 *this, idAI2 *result, idEntity *playerEnt, bool playVO)
{
  const idDeclVoiceOver *v5; // r3

  v5 = idAI2::Job_Complete(this: result, playerEnt, playVO);
  eventDecl::eventDecl((eventDecl *)this, decl: v5);
  return this;
}


// ========================================================================
// ?Event_JobFailed@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA  : 0x82A35130
// RVA : 0x00A35130
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_JobFailed(idAI2 *this, idAI2 *result, idEntity *playerEnt, bool playVO)
{
  const idDeclVoiceOver *v5; // r3

  v5 = idAI2::Job_Failed(this: result, playerEnt, playVO);
  eventDecl::eventDecl((eventDecl *)this, decl: v5);
  return this;
}


// ========================================================================
// ?Event_JobInProgress@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA  : 0x82A35178
// RVA : 0x00A35178
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_JobInProgress(idAI2 *this, idAI2 *result, idEntity *playerEnt, bool playVO)
{
  const idDeclVoiceOver *v5; // r3

  v5 = idAI2::Job_InProgress(this: result, playerEnt, playVO);
  eventDecl::eventDecl((eventDecl *)this, decl: v5);
  return this;
}


// ========================================================================
// ?Event_AcceptedJob@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA  : 0x82A351C0
// RVA : 0x00A351C0
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_AcceptedJob(idAI2 *this, idAI2 *result, idEntity *playerEnt, bool playVO)
{
  const idDeclVoiceOver *v5; // r3

  v5 = idAI2::Job_Accepted(this: result, playerEnt, playVO);
  eventDecl::eventDecl((eventDecl *)this, decl: v5);
  return this;
}


// ========================================================================
// ?Event_DeclinedJob@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA  : 0x82A35208
// RVA : 0x00A35208
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_DeclinedJob(idAI2 *this, idAI2 *result, idEntity *playerEnt, bool playVO)
{
  const idDeclVoiceOver *v5; // r3

  v5 = idAI2::Job_Declined(this: result, playerEnt, playVO);
  eventDecl::eventDecl((eventDecl *)this, decl: v5);
  return this;
}


// ========================================================================
// ?Event_PlayerLeft@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA  : 0x82A35250
// RVA : 0x00A35250
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_PlayerLeft(idAI2 *this, idAI2 *result, idEntity *playerEnt, bool playVO)
{
  const idDeclVoiceOver *v5; // r3

  v5 = idAI2::Job_PlayerLeft(this: result, playerEnt, playVO);
  eventDecl::eventDecl((eventDecl *)this, decl: v5);
  return this;
}


// ========================================================================
// ?Event_CompleteSavedJob@idAI2@@QAA?AVeventBool@@PAVidEntity@@@Z
// EA  : 0x82A35298
// RVA : 0x00A35298
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_CompleteSavedJob(idAI2 *this, idAI2 *result, idPlayer *playerEnt)
{
  idPlayer *v5; // r4
  bool v6; // r3

  v5 = idPlayer::CastTo(c: playerEnt);
  if ( v5 == nullptr )
    idLib::Error(fmt: "Event_CompleteSavedJob: must be passed an idPlayer type entity.");
  v6 = idAI2::Job_CompleteSavedJob(this: result, player: v5);
  eventBool::eventBool((eventBool *)this, b: v6);
  return this;
}


// ========================================================================
// ?Event_AcceptSavedJob@idAI2@@QAA?AVeventBool@@PAVidEntity@@@Z
// EA  : 0x82A35308
// RVA : 0x00A35308
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_AcceptSavedJob(idAI2 *this, idAI2 *result, idPlayer *playerEnt)
{
  idPlayer *v5; // r4
  bool v6; // r3

  v5 = idPlayer::CastTo(c: playerEnt);
  if ( v5 == nullptr )
    idLib::Error(fmt: "Event_AcceptSavedJob: must be passed an idPlayer type entity.");
  v6 = idAI2::Job_AcceptSavedJob(this: result, player: v5);
  eventBool::eventBool((eventBool *)this, b: v6);
  return this;
}


// ========================================================================
// ?Event_GetDeclAIPlayerInteraction@idAI2@@QAA?AVeventDecl@@XZ
// EA  : 0x82A35378
// RVA : 0x00A35378
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_GetDeclAIPlayerInteraction(idAI2 *this, eventDecl *result)
{
  eventDecl::eventDecl((eventDecl *)this, decl: result[2777].value);
  return this;
}


// ========================================================================
// ?Event_GetPlayerInteractionApproachRadius@idAI2@@QAA?AVeventFloat@@XZ
// EA  : 0x82A353B0
// RVA : 0x00A353B0
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_GetPlayerInteractionApproachRadius(idAI2 *this, eventFloat *result)
{
  float value; // r11
  double v4; // fp1

  value = result[2777].value;
  if ( value == 0.0 )
    v4 = 0.0;
  else
    v4 = *(float *)(LODWORD(value) + 64);
  eventFloat::eventFloat((eventFloat *)this, f: v4);
  return this;
}


// ========================================================================
// ?Event_GetPlayerInteractionDepartureRadius@idAI2@@QAA?AVeventFloat@@XZ
// EA  : 0x82A35400
// RVA : 0x00A35400
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_GetPlayerInteractionDepartureRadius(idAI2 *this, eventFloat *result)
{
  float value; // r11
  double v4; // fp1

  value = result[2777].value;
  if ( value == 0.0 )
    v4 = 0.0;
  else
    v4 = *(float *)(LODWORD(value) + 68);
  eventFloat::eventFloat((eventFloat *)this, f: v4);
  return this;
}


// ========================================================================
// ?Event_UpdateGroupAmbush@idAI2@@QAA?AVeventVoid@@ABVidVec3@@@Z
// EA  : 0x82A35490
// RVA : 0x00A35490
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_UpdateGroupAmbush(idAI2 *this, idAI2 *result, const idVec3 *pos)
{
  idEncounterGroup *EncounterGroup; // r3

  EncounterGroup = idAI2::GetEncounterGroup(this: result);
  if ( EncounterGroup != nullptr )
    idEncounterGroup::UpdateGroupAmbush(this: EncounterGroup, groupMember: result, enemyPos: pos);
  return this;
}


// ========================================================================
// ?Event_KillAI@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A354D0
// RVA : 0x00A354D0
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_KillAI(idAI2 *this, idAI2 *result)
{
  *((_BYTE *)&result->aiVolatile.death + 1760) |= 0x80u;
  idAI2::StartDeathSystem(this: result);
  return this;
}


// ========================================================================
// ?Event_AnimWeb_Wait@idAI2@@QAA?AVeventVoid@@HHHH@Z
// EA  : 0x82A35510
// RVA : 0x00A35510
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_AnimWeb_Wait(
        idAI2 *this,
        eventVoid *result,
        __int16 webHandle,
        __int16 subWebIndex,
        __int16 stateIndex,
        const int eventParm)
{
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v8; // r29
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v9; // r28
  const idHandle<short,enum invalidAnimWebHandle_t,-1> *v10; // r27
  idAnimWebCmdCtx *v11; // r3
  idAIMoveState *v12; // r31

  v8 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)stateIndex;
  v9 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)subWebIndex;
  v10 = (const idHandle<short,enum invalidAnimWebHandle_t,-1> *)webHandle;
  v11 = (idAnimWebCmdCtx *)(*(int (__fastcall **)(eventVoid *))(*(_DWORD *)result + 212))(a1: result);
  idAnimWebCmdCtx::ProcessEvent(this: v11, eventType: AWEVT_WAIT, webHandle: v10, swi: v9, si: v8);
  v12 = (idAIMoveState *)&result[12196];
  if ( v12->IsPlayingTraversalAnim(this: v12) )
    idAIMoveState::FinishPlayingTraversalAnim(this: v12);
  return this;
}


// ========================================================================
// ?Event_AnimWeb_StartDeltaCorrection@idAI2@@QAA?AVeventVoid@@HHHH@Z
// EA  : 0x82A35590
// RVA : 0x00A35590
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_AnimWeb_StartDeltaCorrection(
        idAI2 *this,
        eventVoid *result,
        __int16 webHandle,
        __int16 subWebIndex,
        __int16 stateIndex,
        const int eventParm)
{
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v7; // r30
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v8; // r29
  const idHandle<short,enum invalidAnimWebHandle_t,-1> *v9; // r28
  idAnimWebCmdCtx *v10; // r3

  v7 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)stateIndex;
  v8 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)subWebIndex;
  v9 = (const idHandle<short,enum invalidAnimWebHandle_t,-1> *)webHandle;
  v10 = (idAnimWebCmdCtx *)(*(int (__fastcall **)(eventVoid *))(*(_DWORD *)result + 212))(a1: result);
  idAnimWebCmdCtx::ProcessEvent(this: v10, eventType: AWEVT_DELTACORRECT, webHandle: v9, swi: v8, si: v7);
  return this;
}


// ========================================================================
// ?Event_AnimWeb_BeginAnim@idAI2@@QAA?AVeventVoid@@HHHH@Z
// EA  : 0x82A355E0
// RVA : 0x00A355E0
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_AnimWeb_BeginAnim(
        idAI2 *this,
        eventVoid *result,
        const int webHandle,
        const int subWebIndex,
        const int stateIndex,
        const int eventParm)
{
  *(_DWORD *)&result[58688] = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  *(_DWORD *)&result[58692] = eventParm;
  return this;
}


// ========================================================================
// ?Event_AnimWeb_ReloadRightFinished@idAI2@@QAA?AVeventVoid@@HHHH@Z
// EA  : 0x82A35638
// RVA : 0x00A35638
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_AnimWeb_ReloadRightFinished(
        idAI2 *this,
        idActor *result,
        const int webHandle,
        const int subWebIndex,
        const int stateIndex,
        const int eventParm)
{
  idWeapon *EquippedWeapon; // r3

  EquippedWeapon = idActor::GetEquippedWeapon(this: result, slot: EQUIP_RIGHT_HAND);
  if ( EquippedWeapon != nullptr )
    idWeapon::SetFireState(this: EquippedWeapon, fs: FIRESTATE_IDLE);
  return this;
}


// ========================================================================
// ?Event_AnimWeb_EnableFireFromCover@idAI2@@QAA?AVeventVoid@@HHHH@Z
// EA  : 0x82A35680
// RVA : 0x00A35680
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_AnimWeb_EnableFireFromCover(
        idAI2 *this,
        idActor *result,
        const int webHandle,
        const int subWebIndex,
        const int stateIndex,
        const int eventParm)
{
  const idWeapon *EquippedWeapon; // r4

  EquippedWeapon = idActor::GetEquippedWeapon(this: result, slot: EQUIP_RIGHT_HAND);
  if ( EquippedWeapon != nullptr )
    idAIFireControl::ClearInhibitFire(
      this: (idAIFireControl *)result[3].animStack.rememberedNodes.staticList[10],
      weapon: EquippedWeapon);
  return this;
}


// ========================================================================
// ?Event_RelinquishControl@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A356E0
// RVA : 0x00A356E0
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_RelinquishControl(idAI2 *this, idAI2 *result)
{
  idAI2::RelinquishControl(this: result);
  return this;
}


// ========================================================================
// ?Event_DropWeapons@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A35718
// RVA : 0x00A35718
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_DropWeapons(idAI2 *this, eventVoid *result)
{
  (*(void (__fastcall **)(eventVoid *, int))(*(_DWORD *)result + 728))(a1: result, a2: 2);
  (*(void (__fastcall **)(eventVoid *, int))(*(_DWORD *)result + 728))(a1: result, a2: 1);
  return this;
}


// ========================================================================
// ?Event_TurnOffLaserSight@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A35780
// RVA : 0x00A35780
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_TurnOffLaserSight(idAI2 *this, eventVoid *result)
{
  idWeapon *v3; // r3

  v3 = (idWeapon *)(*(int (__fastcall **)(eventVoid *))(*(_DWORD *)result + 704))(a1: result);
  if ( v3 != nullptr )
    idWeapon::HideLaserSight(this: v3);
  return this;
}


// ========================================================================
// ?Event_TurnOnLaserSight@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A357D0
// RVA : 0x00A357D0
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_TurnOnLaserSight(idAI2 *this, eventVoid *result)
{
  int v3; // r3

  v3 = (*(int (__fastcall **)(eventVoid *))(*(_DWORD *)result + 704))(a1: result);
  if ( v3 != 0 && (*(_BYTE *)(v3 + 452) & 2) != 0 )
    idWeapon::ShowLaserSight(this: (idWeapon *)v3);
  return this;
}


// ========================================================================
// ?Event_Path@idAI2@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82A35830
// RVA : 0x00A35830
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_Path(idAI2 *this, eventVoid *result, idInfoPath *newPath)
{
  idInfoPath *v6; // r4
  idAIFSM *v7; // r3
  idAIFSM *v8; // r31
  int GameMs; // r3

  if ( (*(unsigned __int8 (__fastcall **)(eventVoid *))(*(_DWORD *)result + 508))(a1: result) == 0
    && (*(unsigned __int8 (__fastcall **)(eventVoid *))(*(_DWORD *)result + 512))(a1: result) == 0 )
  {
    v6 = idInfoPath::CastTo(c: newPath);
    if ( v6 != nullptr )
    {
      idAIMemory::SetCurrentPath(this: (idAIMemory *)&result[57996], path: v6);
      v7 = (idAIFSM *)(*(int (__fastcall **)(eventVoid *, idTypeInfo *))(*(_DWORD *)&result[21428] + 36))(
                        a1: result + 21428,
                        a2: &idAlertCycleFSM::Type);
      v8 = idAIFSM::CastTo(c: v7);
      if ( v8 != nullptr )
      {
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idFiniteStateMachine::Restart(this: v8, curTime: GameMs);
      }
    }
  }
  return this;
}


// ========================================================================
// ?Event_StartVoiceOver@idAI2@@QAA?AVeventBool@@PAVidEntity@@PBVidDeclVoiceOver@@_N@Z
// EA  : 0x82A35908
// RVA : 0x00A35908
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_StartVoiceOver(
        idAI2 *this,
        idAI2 *result,
        idEntity *talkingTo,
        const idDeclVoiceOver *vo,
        const bool playInCombat)
{
  if ( vo != nullptr && vo->GetDeclInfo(this: vo) == &idDeclVoiceOver::resourceList )
  {
    if ( (!result->IsDead(this: result) || result->IsDying(this: result))
      && (playInCombat || !idAI2::IsFSMActive(this: result, fsmType: &idCombatFSM::Type))
      && idAIVoiceController::PlayVoiceOver(
           this: &result->aiVolatile.voiceController,
           ai: result,
           vo,
           priority: AIVOICEPRIORITY_HIGH,
           samePriorityInterupts: false) != VC_MAX )
    {
      eventBool::eventBool((eventBool *)this, b: true);
      return this;
    }
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idAI2::Event_StartVoiceOver",
      decl: vo,
      declInfo: &idDeclVoiceOver::resourceList);
  }
  eventBool::eventBool((eventBool *)this, b: false);
  return this;
}


// ========================================================================
// ?Event_StartInteractionVoiceOver@idAI2@@QAA?AVeventBool@@PAVidEntity@@PBVidDeclVoiceOver@@_N@Z
// EA  : 0x82A35A20
// RVA : 0x00A35A20
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_StartInteractionVoiceOver(
        idAI2 *this,
        idAI2 *result,
        idEntity *talkingTo,
        const idDeclVoiceOver *vo,
        const bool playInCombat)
{
  if ( vo != nullptr && vo->GetDeclInfo(this: vo) == &idDeclVoiceOver::resourceList )
  {
    if ( (!result->IsDead(this: result) || result->IsDying(this: result))
      && (playInCombat || !idAI2::IsFSMActive(this: result, fsmType: &idCombatFSM::Type))
      && idGameLocal::PlayInteractVoiceOver(this: gameLocal, ai: result, vo, priority: AIVOICEPRIORITY_HIGH) != VC_MAX )
    {
      eventBool::eventBool((eventBool *)this, b: true);
      return this;
    }
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idAI2::Event_StartInteractionVoiceOver",
      decl: vo,
      declInfo: &idDeclVoiceOver::resourceList);
  }
  eventBool::eventBool((eventBool *)this, b: false);
  return this;
}


// ========================================================================
// ?Event_IsVoiceOverPlaying@idAI2@@QAA?AVeventBool@@PBVidDeclVoiceOver@@@Z
// EA  : 0x82A35B38
// RVA : 0x00A35B38
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_IsVoiceOverPlaying(idAI2 *this, eventBool *result, const idDeclVoiceOver *vo)
{
  eventBool::eventBool((eventBool *)this, b: (_cntlzw((unsigned int)vo - *(_DWORD *)&result[59356].value) & 0x20) != 0);
  return this;
}


// ========================================================================
// ?Event_GetPlayingVoiceOver@idAI2@@QAA?AVeventDecl@@XZ
// EA  : 0x82A35B80
// RVA : 0x00A35B80
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_GetPlayingVoiceOver(idAI2 *this, eventDecl *result)
{
  eventDecl::eventDecl((eventDecl *)this, decl: result[14839].value);
  return this;
}


// ========================================================================
// ?Event_SetInteracting@idAI2@@QAA?AVeventVoid@@_N@Z
// EA  : 0x82A35BC0
// RVA : 0x00A35BC0
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_SetInteracting(idAI2 *this, idAI2 *result, bool interacting)
{
  idAI2::SetInteracting(this: result, b: interacting);
  return this;
}


// ========================================================================
// ?Event_SetJobOfferPlayed@idAI2@@QAA?AVeventBool@@PBVidDeclAIPlayerInteraction@@PAVidEntity@@H@Z
// EA  : 0x82A35BF8
// RVA : 0x00A35BF8
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_SetJobOfferPlayed(
        idAI2 *this,
        eventBool *result,
        const idDeclAIPlayerInteraction *decl,
        idPlayer *playerEnt,
        int interactionIndex)
{
  idPlayer *v9; // r3

  if ( decl != nullptr && decl->GetDeclInfo(this: decl) == &idDeclAIPlayerInteraction::resourceList )
  {
    v9 = idPlayer::CastTo(c: playerEnt);
    if ( v9 == nullptr )
      idLib::Error(fmt: "Event_SetJobOfferPlayed: must be passed an idPlayer type entity.");
    idJobManager::SetJobOfferPlayed(
      this: &v9->jobManager,
      interactionDecl: decl,
      interactionNumber: interactionIndex,
      played: true);
    eventBool::eventBool((eventBool *)this, b: true);
    return this;
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idAI2::Event_SetJobOfferPlayed",
      decl,
      declInfo: &idDeclAIPlayerInteraction::resourceList);
    eventBool::eventBool((eventBool *)this, b: false);
    return this;
  }
}


// ========================================================================
// ?Event_SetFocus@idAI2@@QAA?AVeventVoid@@PBVidEntity@@_N1W4aimPoint_t@@@Z
// EA  : 0x82A35CB8
// RVA : 0x00A35CB8
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_SetFocus(
        idAI2 *this,
        idAI2 *result,
        const idEntity *ent,
        const bool aiming,
        bool keepFocusInView,
        aimPoint_t aimPoint)
{
  if ( aiming )
  {
    if ( ent != nullptr )
      idAI2::SetAimFocusEntity(this: result, ent, keepFocusInView, aimPoint, timeout: -1);
    else
      idAI2::ClearAimFocus(this: result);
  }
  else if ( ent != nullptr )
  {
    idAI2::SetLookFocusEntity(this: result, ent, keepFocusInView, aimPoint, timeout: -1);
  }
  else
  {
    idAI2::ClearLookFocus(this: result);
  }
  return this;
}


// ========================================================================
// ?Event_ClearLookFocus@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A35D38
// RVA : 0x00A35D38
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_ClearLookFocus(idAI2 *this, idAI2 *result)
{
  idAI2::ClearLookFocus(this: result);
  return this;
}


// ========================================================================
// ?Event_ClearAimFocus@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A35D70
// RVA : 0x00A35D70
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_ClearAimFocus(idAI2 *this, idAI2 *result)
{
  idAI2::ClearAimFocus(this: result);
  return this;
}


// ========================================================================
// ?Event_EnableAutoFocus@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A35DA8
// RVA : 0x00A35DA8
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_EnableAutoFocus(idAI2 *this, idAI2 *result, const idMD6Anim *anim)
{
  idAI2::SetEnableAutoFocus(this: result, enable: true);
  return this;
}


// ========================================================================
// ?Event_GetPlayerInteractionName@idAI2@@QAA?AVeventString@@PBVidDeclAIPlayerInteraction@@H@Z
// EA  : 0x82A35DE0
// RVA : 0x00A35DE0
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_GetPlayerInteractionName(
        idAI2 *this,
        eventString *result,
        const idDeclAIPlayerInteraction *decl,
        int index)
{
  if ( decl != nullptr && decl->GetDeclInfo(this: decl) == &idDeclAIPlayerInteraction::resourceList )
  {
    if ( index >= 0 && index < decl->interactList.num )
    {
      eventString::eventString((eventString *)this, s: decl->interactList.list[index].interactName.data);
      return this;
    }
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idAI2::Event_GetPlayerInteractionName",
      decl,
      declInfo: &idDeclAIPlayerInteraction::resourceList);
  }
  eventString::eventString((eventString *)this);
  return this;
}


// ========================================================================
// ?Event_GetPlayerInteractionJobDecl@idAI2@@QAA?AVeventDecl@@PBVidDeclAIPlayerInteraction@@H@Z
// EA  : 0x82A35E88
// RVA : 0x00A35E88
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_GetPlayerInteractionJobDecl(
        idAI2 *this,
        eventDecl *result,
        const idDeclAIPlayerInteraction *decl,
        int interactionIndex)
{
  idAI2 *v7; // r3

  if ( decl != nullptr && decl->GetDeclInfo(this: decl) == &idDeclAIPlayerInteraction::resourceList )
  {
    v7 = this;
    if ( interactionIndex >= 0 && decl->interactList.num > interactionIndex )
    {
      eventDecl::eventDecl((eventDecl *)this, decl: decl->interactList.list[interactionIndex].interactionJob);
      return this;
    }
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idAI2::Event_GetPlayerInteractionJobDecl",
      decl,
      declInfo: &idDeclAIPlayerInteraction::resourceList);
    v7 = this;
  }
  eventDecl::eventDecl(this: (eventDecl *)v7);
  return this;
}


// ========================================================================
// ?Event_BeginPlayerInteractionIndex@idAI2@@QAA?AVeventVoid@@H@Z
// EA  : 0x82A35F30
// RVA : 0x00A35F30
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_BeginPlayerInteractionIndex(idAI2 *this, idAI2 *result, int index)
{
  const idDeclAIPlayerInteraction *playerInteraction; // r11

  playerInteraction = result->aiEditable.interactions.playerInteraction;
  if ( playerInteraction != nullptr && index >= 0 && index < playerInteraction->interactList.num )
  {
    result->aiVolatile.memory.currentPlayerInteraction = index;
    idAI2::SetCurrentPlayerInteraction(this: result, interaction: &playerInteraction->interactList.list[index]);
  }
  return this;
}


// ========================================================================
// ?Event_SetRemoveHealthWhenDamaged@idAI2@@QAA?AVeventVoid@@_N@Z
// EA  : 0x82A35FA0
// RVA : 0x00A35FA0
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idAI2::Event_SetRemoveHealthWhenDamaged@<r4>(
        idAI2 *this@<r3>,
        int result@<r4>,
        const bool removeHealth@<r5>)
{
  *(_BYTE *)(result + 11056) = (4 * removeHealth) & 4 | *(_BYTE *)(result + 11056) & 0xFB;
  return result;
}


// ========================================================================
// ?Event_SetEventOverloadEnableFlag@idAI2@@QAA?AVeventVoid@@H@Z
// EA  : 0x82A35FB8
// RVA : 0x00A35FB8
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idAI2::Event_SetEventOverloadEnableFlag@<r4>(idAI2 *this@<r3>, int result@<r4>, int flags@<r5>)
{
  *(_DWORD *)(result + 32912) |= flags;
  return result;
}


// ========================================================================
// ?Event_ClearEventOverloadEnableFlag@idAI2@@QAA?AVeventVoid@@H@Z
// EA  : 0x82A35FD0
// RVA : 0x00A35FD0
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idAI2::Event_ClearEventOverloadEnableFlag@<r4>(idAI2 *this@<r3>, int result@<r4>, int flags@<r5>)
{
  *(_DWORD *)(result + 32912) &= ~flags;
  return result;
}


// ========================================================================
// ?Event_SetEventOverloadDisableFlag@idAI2@@QAA?AVeventVoid@@H@Z
// EA  : 0x82A35FE8
// RVA : 0x00A35FE8
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idAI2::Event_SetEventOverloadDisableFlag@<r4>(idAI2 *this@<r3>, int result@<r4>, int flags@<r5>)
{
  *(_DWORD *)(result + 32916) |= flags;
  return result;
}


// ========================================================================
// ?Event_ClearEventOverloadDisableFlag@idAI2@@QAA?AVeventVoid@@H@Z
// EA  : 0x82A36000
// RVA : 0x00A36000
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idAI2::Event_ClearEventOverloadDisableFlag@<r4>(idAI2 *this@<r3>, int result@<r4>, int flags@<r5>)
{
  *(_DWORD *)(result + 32916) &= ~flags;
  return result;
}


// ========================================================================
// ?Event_SetBehaviorDecl@idAI2@@QAA?AVeventVoid@@PBVidDeclAIBehavior@@@Z
// EA  : 0x82A36018
// RVA : 0x00A36018
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_SetBehaviorDecl(idAI2 *this, eventVoid *result, const idDeclAIBehavior *declBehavior)
{
  if ( declBehavior != nullptr && declBehavior->GetDeclInfo(this: declBehavior) == &idDeclAIBehavior::resourceList )
  {
    *(_DWORD *)&result[11400] = declBehavior;
    return this;
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idAI2::Event_SetBehaviorDecl",
      decl: declBehavior,
      declInfo: &idDeclAIBehavior::resourceList);
    return this;
  }
}


// ========================================================================
// ?Event_ShouldTurnTo@idAI2@@QAA?AVeventInt@@PBVidEntity@@MMM@Z
// EA  : 0x82A36090
// RVA : 0x00A36090
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_ShouldTurnTo(
        idAI2 *this,
        idAI2 *result,
        idEntity *entity,
        double leftDotThreshold,
        double rightDotThreshold,
        double offsetDegrees)
{
  idPhysics *Physics; // r28
  idPhysics *v13; // r29
  float *v14; // r28
  float *v15; // r3
  double v16; // fp11
  double v17; // fp10
  double v19; // fp2
  double v21; // fp12
  double v22; // fp10
  double v23; // fp3
  double v24; // fp2
  double v25; // fp30
  double v26; // fp29
  double v27; // fp28
  idAIOrientation *BodyOrientation; // r3
  char *v29; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  idPhysics *v32; // r3
  float *v33; // r3
  double v34; // fp13
  double v35; // fp12
  double v36; // fp11
  const idMat3 *v37; // r3
  double v38; // fp0
  double v39; // fp13
  int v40; // r4
  char v42; // [sp+5Ch] [-E4h] BYREF
  idMat3 v43; // [sp+60h] [-E0h] BYREF
  idRotation v44; // [sp+90h] [-B0h] BYREF

  Physics = idEntity::GetPhysics(this: result);
  v13 = idEntity::GetPhysics(this: entity);
  v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v15 = (float *)v13->GetOrigin(this: v13, a2: 0);
  v16 = (float)(v15[1] - v14[1]);
  v17 = (float)(v15[2] - v14[2]);
  _FP3 = (float)((float)((float)((float)(*v15 - *v14) * (float)(*v15 - *v14))
                       + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v19 = (float)((float)((float)((float)(*v15 - *v14) * (float)(*v15 - *v14))
                      + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)))
              * (float)0.5);
  __asm { fsel      f1, f3, f4, f12 }
  v21 = __frsqrte(_FP1);
  v22 = (float)((float)v21
              * (float)((float)((float)((float)(*v15 - *v14) * (float)(*v15 - *v14))
                              + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)))
                      * (float)0.5));
  v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v22 * (float)v21) - (float)1.5)
                                                      * (float)v21)
                                              * (float)v19)
                                      * (float)((float)-(float)((float)((float)v22 * (float)v21) - (float)1.5)
                                              * (float)v21))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)v22 * (float)v21) - (float)1.5) * (float)v21));
  v24 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v22 * (float)v21)
                                                                              - (float)1.5)
                                                              * (float)v21)
                                                      * (float)v19)
                                              * (float)((float)-(float)((float)((float)v22 * (float)v21) - (float)1.5)
                                                      * (float)v21))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)v22 * (float)v21) - (float)1.5) * (float)v21))
              * (float)v19);
  v25 = (float)((float)((float)-(float)((float)((float)v24 * (float)v23) - (float)1.5) * (float)v23)
              * (float)(*v15 - *v14));
  v26 = (float)((float)(v15[1] - v14[1])
              * (float)((float)-(float)((float)((float)v24 * (float)v23) - (float)1.5) * (float)v23));
  v27 = (float)((float)(v15[2] - v14[2])
              * (float)((float)-(float)((float)((float)v24 * (float)v23) - (float)1.5) * (float)v23));
  BodyOrientation = idAI2::GetBodyOrientation(this: result);
  v29 = &v42;
  p_z = (_DWORD *)&BodyOrientation->idealDir.z;
  for ( i = 9; i != 0; --i )
  {
    ++p_z;
    v29 += 4;
    *(_DWORD *)v29 = *p_z;
  }
  if ( offsetDegrees != 0.0 )
  {
    v32 = idEntity::GetPhysics(this: result);
    v33 = (float *)v32->GetGravityNormal(this: v32);
    v34 = *v33;
    v35 = v33[1];
    v36 = v33[2];
    v44.angle = offsetDegrees;
    v44.axisValid = false;
    v44.origin.x = vec3_origin.x;
    v44.origin.y = vec3_origin.y;
    v44.origin.z = vec3_origin.z;
    v44.axis.mat[0].x = mat3_identity.mat[0].x;
    v44.axis.mat[0].y = mat3_identity.mat[0].y;
    v44.axis.mat[0].z = mat3_identity.mat[0].z;
    v44.axis.mat[1].x = mat3_identity.mat[1].x;
    v44.axis.mat[1].y = mat3_identity.mat[1].y;
    v44.axis.mat[1].z = mat3_identity.mat[1].z;
    v44.axis.mat[2].x = mat3_identity.mat[2].x;
    v44.axis.mat[2].y = mat3_identity.mat[2].y;
    v44.axis.mat[2].z = mat3_identity.mat[2].z;
    v44.vec.x = (float)v34 * (float)-1.0;
    v44.vec.y = (float)v35 * (float)-1.0;
    v44.vec.z = (float)v36 * (float)-1.0;
    v37 = idRotation::ToMat3(this: &v44);
    idMat3::operator*=(this: &v43, a: v37);
  }
  v38 = (float)((float)(v43.mat[1].x * (float)v25)
              + (float)((float)(v43.mat[1].y * (float)v26) + (float)(v43.mat[1].z * (float)v27)));
  v39 = (float)((float)(v43.mat[0].x * (float)v25)
              + (float)((float)(v43.mat[0].y * (float)v26) + (float)(v43.mat[0].z * (float)v27)));
  if ( v38 < 0.0 || v39 >= leftDotThreshold )
  {
    if ( v38 >= 0.0 || (v40 = 2, v39 >= rightDotThreshold) )
      v40 = 0;
  }
  else
  {
    v40 = 1;
  }
  eventInt::eventInt((eventInt *)this, i: v40);
  return this;
}


// ========================================================================
// ?Event_IsEntityVisible@idAI2@@QAA?AVeventBool@@PBVidEntity@@@Z
// EA  : 0x82A36348
// RVA : 0x00A36348
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_IsEntityVisible(idAI2 *this, eventBool *result, const idEntity *entity)
{
  idAIEntityState *v4; // r3
  bool v5; // r4

  v4 = idAIWorldState::StateForEntity(this: (idAIWorldState *)&result[14064], ent: entity);
  v5 = v4 != nullptr && idAIEntityState::IsVisible(this: v4);
  eventBool::eventBool((eventBool *)this, b: v5);
  return this;
}


// ========================================================================
// ?LocationCallingHelper@idAI2@@QAAXPBVidEntity@@@Z
// EA  : 0x82A363A8
// RVA : 0x00A363A8
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

void __fastcall idAI2::LocationCallingHelper(idAI2 *this, idEntity *ent)
{
  idPhysics *Physics; // r3
  idAIEntityState *v5; // r3
  idPhysics *v6; // r3
  idPhysics *v7; // r29
  int GameMs; // r3
  const idDeclAIBehaviorEvents *declBehaviorEvents; // r28
  int v10; // r27
  idPhysics *v11; // r3
  idHandle<int,enum invalidAIEvent_t,-1> *p_aiEventManager; // r29
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v14; // r3
  char v15; // [sp+50h] [-40h] BYREF

  if ( ent != nullptr )
  {
    Physics = idEntity::GetPhysics(this: ent);
    Physics->GetOrigin(this: Physics, a2: 0);
    v5 = idAIWorldState::StateForEntity(this: &this->aiVolatile.world.worldState, ent);
    if ( v5 != nullptr )
      aiSenseState_t::GetConfirmedPhysicalSafe(this: v5->senses.ptr[v5->lastSense]);
    v6 = idEntity::GetPhysics(this);
    v6->GetOrigin(this: v6, a2: 0);
    if ( this->aiEditable.behaviors.declBehaviorEvents != nullptr )
    {
      v7 = idEntity::GetPhysics(this);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      declBehaviorEvents = this->aiEditable.behaviors.declBehaviorEvents;
      v10 = GameMs;
      v11 = v7;
      GetOrigin = v7->GetOrigin;
      p_aiEventManager = (idHandle<int,enum invalidAIEvent_t,-1> *)&gameLocal->aiEventManager;
      v14 = GetOrigin(this: v11, a2: 0);
      idAIEventManager::AddEvent(
        this: (idAIEventManager *)&v15,
        result: p_aiEventManager,
        eventDecl: declBehaviorEvents->enemySightedVoiceEventDecl,
        curTime: v10,
        originator: this,
        instigator: ent,
        origin: v14,
        delay: 500);
    }
  }
}


// ========================================================================
// ?Event_SpawnLootBox@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A364B0
// RVA : 0x00A364B0
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_SpawnLootBox(idAI2 *this, eventVoid *result)
{
  idEntity *v4; // r30
  int v5; // r28
  int v6; // r3
  int entityNumber; // r27
  int v8; // r26
  double v9; // fp30
  double v10; // fp29
  double v11; // fp28
  float *v12; // r3
  double v13; // fp4
  double v14; // fp3
  float *v15; // r3
  double v16; // fp7
  double v17; // fp5
  idVec3 v19; // [sp+50h] [-100h] BYREF
  idVec3 v20; // [sp+60h] [-F0h] BYREF
  trace_t v21; // [sp+70h] [-E0h] BYREF

  if ( (*(_BYTE *)&result[11056] & 2) != 0 && (*(_BYTE *)&result[20984] & 0x10) == 0 )
  {
    v4 = gameLocal->SpawnEntityFromDef(
           this: gameLocal,
           a2: *(_DWORD *)(*(_DWORD *)&result[11400] + 180),
           a3: -1,
           a4: -1,
           a5: -1);
    if ( v4 != nullptr )
    {
      v5 = (*(int (__fastcall **)(eventVoid *))(*(_DWORD *)result + 224))(a1: result) + 288;
      v6 = (*(int (__fastcall **)(eventVoid *))(*(_DWORD *)result + 224))(a1: result);
      entityNumber = v4->entityNumber;
      v8 = v6 + 288;
      v9 = (float)(vec3_up.x * (float)-256.0);
      v10 = (float)(vec3_up.y * (float)-256.0);
      v11 = (float)(vec3_up.z * (float)-256.0);
      v12 = (float *)(*(int (__fastcall **)(int, int))(*(_DWORD *)v5 + 44))(a1: v5, a2: -1);
      v13 = (float)((float)(v12[4] + v12[1]) * (float)0.5);
      v14 = (float)((float)(v12[5] + v12[2]) * (float)0.5);
      v20.x = (float)((float)(v12[3] + *v12) * (float)0.5) + (float)v9;
      v20.y = (float)v13 + (float)v10;
      v20.z = (float)v14 + (float)v11;
      v15 = (float *)(*(int (__fastcall **)(int, int))(*(_DWORD *)v8 + 44))(a1: v8, a2: -1);
      v16 = (float)(v15[1] + v15[4]);
      v17 = (float)(v15[3] + *v15);
      v19.z = (float)(v15[2] + v15[5]) * (float)0.5;
      v19.y = (float)v16 * (float)0.5;
      v19.x = (float)v17 * (float)0.5;
      idClip::TracePoint(
        this: &clientGame->clip,
        result: &v21,
        start: &v19,
        end: &v20,
        clipMask: 1,
        passEntityNumber: entityNumber);
      idEntity::SetOrigin(this: v4, org: &v21.endpos);
      *(_BYTE *)&result[20984] |= 0x10u;
    }
  }
  return this;
}


// ========================================================================
// ?Event_RemoveBody@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A36690
// RVA : 0x00A36690
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_RemoveBody(idAI2 *this, idActor *result)
{
  __int64 v4; // r6
  unsigned int v5; // r10
  char v7; // r25
  int v8; // r3
  char v9; // r11
  int (*GetOrigin)(void); // ctr
  float *v11; // r29
  int v12; // r30
  idPlayer *Player; // r3
  idPlayer *v14; // r31
  idPhysics *Physics; // r3
  float *v16; // r3
  double v17; // fp30
  double v18; // fp29
  double v19; // fp28
  double v20; // fp31
  double v23; // fp8
  double v24; // fp0
  double v25; // fp6
  double v26; // fp5
  __int64 v27; // r6
  unsigned int v28; // r10
  int value; // r9
  idGameLocal *v30; // r11
  idEntity *v31; // r3
  int v32; // r9
  idEntity *v33; // r3
  idEntity *v34; // r3
  int v35; // r9
  idEntity *v36; // r3
  int v37; // r9
  idEntity *v38; // r3
  idEntity *v39; // r3
  char v40; // [sp+58h] [-C8h] BYREF
  float v41[26]; // [sp+70h] [-B0h] BYREF

  if ( idActor::HasLootableItems(this: result) )
  {
    HIDWORD(v4) = clientGame->random.seed;
    v5 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v5 + 1013904223;
    LODWORD(v4) = ((v5 + 1013904223) >> 10) & 0x7FFF;
    idEventReceiver::PostEventSec(
      this: result,
      ev: &EV_RemoveBody,
      time: (float)((float)((float)v4 * (float)0.00045777764) + (float)15.0));
    return this;
  }
  else
  {
    v7 = 0;
    v8 = (int)result->GetAF_2(this: result);
    if ( *(_BYTE *)(v8 + 267) != 0 || (v9 = 0, *(_BYTE *)(v8 + 268) != 0) )
      v9 = 1;
    if ( v9 != 0 )
      GetOrigin = (int (*)(void))result->GetAF_2(this: result)->physicsObj.GetOrigin;
    else
      GetOrigin = (int (*)(void))idEntity::GetPhysics(this: result)->GetOrigin;
    v11 = (float *)GetOrigin();
    v12 = 0;
    while ( 1 )
    {
      Player = idGameLocal::GetPlayer(this: gameLocal, i: v12);
      v14 = Player;
      if ( Player != nullptr )
      {
        Physics = idEntity::GetPhysics(this: Player);
        v16 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v17 = (float)(v11[1] - v16[1]);
        v18 = (float)(v11[2] - v16[2]);
        v19 = (float)(*v11 - *v16);
        v20 = (float)((float)((float)(*v11 - *v16) * (float)(*v11 - *v16))
                    + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)));
        if ( v20 < 65536.0 )
          break;
        v14->GetViewTransform(this: v14, a2: (idVec3 *)&v40, a3: (idMat3 *)v41);
        _FP12 = (float)((float)v20 - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f11, f12, f31, f0 }
        v23 = __frsqrte(_FP11);
        v24 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23
                                                                                            * (float)((float)v20 * (float)0.5))
                                                                                    * (float)v23)
                                                                            - (float)1.5)
                                                            * (float)v23)
                                                    * (float)((float)v20 * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v23
                                                                                    * (float)((float)v20 * (float)0.5))
                                                                            * (float)v23)
                                                                    - (float)1.5)
                                                    * (float)v23))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v23 * (float)((float)v20 * (float)0.5)) * (float)v23)
                                            - (float)1.5)
                            * (float)v23));
        v25 = (float)((float)v18
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23 * (float)((float)v20 * (float)0.5)) * (float)v23) - (float)1.5) * (float)v23) * (float)((float)v20 * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v23 * (float)((float)v20 * (float)0.5)) * (float)v23) - (float)1.5) * (float)v23))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v23 * (float)((float)v20 * (float)0.5)) * (float)v23)
                                                                                            - (float)1.5)
                                                                            * (float)v23))
                                                            * (float)((float)v20 * (float)0.5))
                                                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23 * (float)((float)v20 * (float)0.5)) * (float)v23) - (float)1.5) * (float)v23)
                                                                                            * (float)((float)v20 * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v23 * (float)((float)v20 * (float)0.5)) * (float)v23) - (float)1.5)
                                                                                            * (float)v23))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v23 * (float)((float)v20 * (float)0.5))
                                                                                            * (float)v23)
                                                                                    - (float)1.5)
                                                                    * (float)v23)))
                                            - (float)1.5)
                            * (float)v24));
        v26 = (float)((float)v19
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23 * (float)((float)v20 * (float)0.5)) * (float)v23) - (float)1.5) * (float)v23) * (float)((float)v20 * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v23 * (float)((float)v20 * (float)0.5)) * (float)v23) - (float)1.5) * (float)v23))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v23 * (float)((float)v20 * (float)0.5)) * (float)v23)
                                                                                            - (float)1.5)
                                                                            * (float)v23))
                                                            * (float)((float)v20 * (float)0.5))
                                                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23 * (float)((float)v20 * (float)0.5)) * (float)v23) - (float)1.5) * (float)v23)
                                                                                            * (float)((float)v20 * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v23 * (float)((float)v20 * (float)0.5)) * (float)v23) - (float)1.5)
                                                                                            * (float)v23))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v23 * (float)((float)v20 * (float)0.5))
                                                                                            * (float)v23)
                                                                                    - (float)1.5)
                                                                    * (float)v23)))
                                            - (float)1.5)
                            * (float)v24));
        if ( (float)((float)(v41[0] * (float)v26)
                   + (float)((float)(v41[2] * (float)v25)
                           + (float)(v41[1]
                                   * (float)((float)v17
                                           * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23 * (float)((float)v20 * (float)0.5)) * (float)v23) - (float)1.5) * (float)v23) * (float)((float)v20 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v23 * (float)((float)v20 * (float)0.5)) * (float)v23) - (float)1.5) * (float)v23)) - (float)1.5)
                                                                                           * (float)((float)-(float)((float)((float)((float)v23 * (float)((float)v20 * (float)0.5)) * (float)v23) - (float)1.5) * (float)v23))
                                                                                   * (float)((float)v20 * (float)0.5))
                                                                           * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23 * (float)((float)v20 * (float)0.5)) * (float)v23) - (float)1.5) * (float)v23) * (float)((float)v20 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v23 * (float)((float)v20 * (float)0.5)) * (float)v23) - (float)1.5) * (float)v23)) - (float)1.5)
                                                                                   * (float)((float)-(float)((float)((float)((float)v23 * (float)((float)v20 * (float)0.5)) * (float)v23) - (float)1.5)
                                                                                           * (float)v23)))
                                                                   - (float)1.5)
                                                   * (float)v24))))) > 0.0 )
          break;
      }
      if ( ++v12 >= 6 )
        goto LABEL_16;
    }
    v7 = 1;
LABEL_16:
    if ( v7 != 0 )
    {
      HIDWORD(v27) = clientGame->random.seed;
      v28 = 1664525 * clientGame->random.seed;
      clientGame->random.seed = v28 + 1013904223;
      LODWORD(v27) = ((v28 + 1013904223) >> 10) & 0x7FFF;
      idEventReceiver::PostEventSec(
        this: result,
        ev: &EV_RemoveBody,
        time: (float)((float)((float)v27 * (float)0.00045777764) + (float)15.0));
      return this;
    }
    else
    {
      idEventReceiver::PostEventMS(this: result, ev: &EV_Remove, time: 0);
      value = result->droppedItem1.spawnId.value;
      v30 = gameLocal;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v31 = gameLocal->entities.ptr[value & 0x1FFF];
        if ( v31 != nullptr )
        {
          if ( idEntity::CastTo(c: v31) != nullptr )
          {
            v32 = result->droppedItem1.spawnId.value;
            if ( gameLocal->spawnIds.ptr[v32 & 0x1FFF] == v32 >> 13
              && (v33 = gameLocal->entities.ptr[v32 & 0x1FFF]) != nullptr )
            {
              v34 = idEntity::CastTo(c: v33);
            }
            else
            {
              v34 = nullptr;
            }
            idEventReceiver::PostEventMS(this: v34, ev: &EV_Remove, time: 0);
          }
          v30 = gameLocal;
        }
      }
      v35 = result->droppedItem2.spawnId.value;
      if ( v30->spawnIds.ptr[v35 & 0x1FFF] == v35 >> 13 )
      {
        v36 = v30->entities.ptr[v35 & 0x1FFF];
        if ( v36 != nullptr && idEntity::CastTo(c: v36) != nullptr )
        {
          v37 = result->droppedItem2.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v37 & 0x1FFF] == v37 >> 13
            && (v38 = gameLocal->entities.ptr[v37 & 0x1FFF]) != nullptr )
          {
            v39 = idEntity::CastTo(c: v38);
          }
          else
          {
            v39 = nullptr;
          }
          idEventReceiver::PostEventMS(this: v39, ev: &EV_Remove, time: 0);
        }
      }
      return this;
    }
  }
}


// ========================================================================
// ?Event_AwarenessLost@idAI2@@QAA?AVeventVoid@@PAVidEntity@@HH@Z
// EA  : 0x82A36B08
// RVA : 0x00A36B08
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_AwarenessLost(
        idAI2 *this,
        idAI2 *result,
        idEntity *ent,
        const int oldAwareness,
        const int newAwareness)
{
  int value; // r8
  idEntity *v11; // r3
  idEntity *v12; // r3
  idEncounterGroup *EncounterGroup; // r3

  if ( ent != nullptr )
  {
    value = result->aiVolatile.memory.currentEnemy.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v11 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v12 = idEntity::CastTo(c: v11);
    }
    else
    {
      v12 = nullptr;
    }
    if ( v12 == ent
      && newAwareness == 1
      && idAIWorldState::StateForEntity(this: &result->aiVolatile.world.worldState, ent)->highestAwareness != 3
      && idAI2::GetEncounterGroup(this: result) != nullptr )
    {
      EncounterGroup = idAI2::GetEncounterGroup(this: result);
      idEncounterGroup::GetAnyMemberHasSeenDeadBody(this: EncounterGroup);
    }
    return this;
  }
  else
  {
    idLib::Warning(fmt: "idAI2::Event_AwarenessLost - NULL entity.");
    return this;
  }
}


// ========================================================================
// ?Event_ResetSearchPoints@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A36BE8
// RVA : 0x00A36BE8
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_ResetSearchPoints(idAI2 *this, idAI2 *result)
{
  idEncounterGroup *EncounterGroup; // r3

  EncounterGroup = idAI2::GetEncounterGroup(this: result);
  if ( EncounterGroup != nullptr )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&EncounterGroup->searchPointList);
  return this;
}


// ========================================================================
// ?EnemySightedHelper@idAI2@@QAAXPBVidEntity@@_N@Z
// EA  : 0x82A36C30
// RVA : 0x00A36C30
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

void __fastcall idAI2::EnemySightedHelper(idAI2 *this, idAI2 *ent, const bool firstSight)
{
  idAI2 *v6; // r3
  idAI2 *v7; // r30
  bool v8; // zf
  idEncounterGroup *EncounterGroup; // r3
  idEncounterGroup *v10; // r3
  idPhysics *Physics; // r3
  int *v12; // r3
  int v13; // r7
  int *v14; // r6
  idPhysics *v15; // r3
  idPhysics *v16; // r3
  float *v17; // r3
  double v18; // fp0
  idPhysics *v19; // r3
  idPresentable *presentable; // r11
  double v21; // fp30
  double v22; // fp29
  double v23; // fp28
  idPhysics *v24; // r3
  float *v25; // r3
  double v26; // fp9
  double v27; // fp7
  idPhysics *v28; // r3
  int v29; // r3
  idPhysics *v30; // r3
  int v31; // r3
  double v32; // fp29
  double v33; // fp28
  double v34; // fp31
  idPhysics *v35; // r3
  float *v36; // r3
  double v37; // fp0
  double v38; // fp12
  idPhysics *v39; // r3
  int v40; // r3
  int value; // r8
  idEntity *v42; // r3
  idProp_WeaponStatic *v43; // r3
  const idSoundShader *LocationCallingSS; // r3
  const idFaction *v45; // r3
  const char *String; // r3
  const idDeclEntityDef *entityDef; // r11
  const char *str; // r3
  idPhysics *v49; // r30
  int GameMs; // r28
  idPhysics *v51; // r3
  const idDeclAIBehaviorEvents *declBehaviorEvents; // r27
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // r9
  idHandle<int,enum invalidAIEvent_t,-1> *p_aiEventManager; // r30
  const idVec3 *v55; // r3
  idAIEventManager v56; // [sp+50h] [-A0h] BYREF

  if ( ent != nullptr )
  {
    v6 = idAI2::CastTo(c: ent);
    v8 = !firstSight;
    v7 = v6;
    if ( v8
      || idAI2::GetEncounterGroup(this) == nullptr
      || (EncounterGroup = idAI2::GetEncounterGroup(this),
          idEncounterGroup::AnyMemberHighestAlertCycle(this: EncounterGroup) > ALERTCYCLE_SEARCH)
      || (v10 = idAI2::GetEncounterGroup(this), idEncounterGroup::GetAnyMemberHasSeenDeadBody(this: v10)) )
    {
      Physics = idEntity::GetPhysics(this: ent);
      v12 = (int *)Physics->GetOrigin(this: Physics, a2: 0);
      v13 = v12[1];
      v14 = (int *)v12[2];
      v56.eventList.size = *v12;
      *(_DWORD *)&v56.eventList.granularity = v13;
      v56.eventHash.hash = v14;
      v15 = idEntity::GetPhysics(this: ent);
      ((void (__fastcall *)(int *))v15->GetLinearVelocity)(a1: &v56.receivers.size);
      idAIWorldState::StateForEntity(this: &this->aiVolatile.world.worldState, ent);
      v16 = idEntity::GetPhysics(this);
      v17 = (float *)v16->GetOrigin(this: v16, a2: 0);
      v18 = (float)(*(float *)&v56.eventList.granularity - v17[1]);
      *(float *)&v56.eventList.size = *(float *)&v56.eventList.size - *v17;
      *(float *)&v56.eventHash.hash = 0.0;
      *(float *)&v56.eventList.granularity = v18;
      if ( (float)((float)(*(float *)&v56.eventList.size * *(float *)&v56.eventList.size)
                 + (float)((float)v18 * (float)v18)) > 0.1 )
        idVec3::NormalizeFast(this: (idVec3 *)&v56.eventList.size);
      if ( this->presentable == nullptr )
        idEntity::InitPresentableInternal(this);
      v19 = idEntity::GetPhysics(this);
      v19->GetOrigin(this: v19, a2: 0);
      if ( ai_debugLevel.valueInteger != 0 && ai_debugVoice.valueInteger != 0 )
      {
        presentable = this->presentable;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          presentable = this->presentable;
        }
        v21 = (float)(presentable->axis.mat[0].x * (float)64.0);
        v22 = (float)(presentable->axis.mat[0].y * (float)64.0);
        v23 = (float)(presentable->axis.mat[0].z * (float)64.0);
        v24 = idEntity::GetPhysics(this);
        v25 = (float *)v24->GetOrigin(this: v24, a2: 0);
        v26 = (float)(v25[2] + (float)v23);
        v27 = (float)(v25[1] + (float)v22);
        *(float *)&v56.eventHash.hashSize = *v25 + (float)v21;
        *(float *)&v56.eventHash.granularity = v26;
        *(float *)&v56.eventHash.indexSize = v27;
        v28 = idEntity::GetPhysics(this);
        v29 = (int)v28->GetOrigin(this: v28, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, idColor *, int, int *, double))clientGame->renderWorld->DebugArrow)(
          a1: clientGame->renderWorld,
          a2: &idColor::colorWhite,
          a3: v29,
          a4: &v56.eventHash.hashSize,
          a5: 2.0);
        v30 = idEntity::GetPhysics(this);
        v31 = (int)v30->GetOrigin(this: v30, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, idColor *, int, idVec3 *, double))clientGame->renderWorld->DebugArrow)(
          a1: clientGame->renderWorld,
          a2: &idColor::colorYellow,
          a3: v31,
          a4: &this->aiVolatile.focus.foci.ptr[0].curFocusPoint,
          a5: 2.0);
        v32 = (float)(*(float *)&v56.eventList.size * (float)64.0);
        v33 = (float)(*(float *)&v56.eventList.granularity * (float)64.0);
        v34 = (float)(*(float *)&v56.eventHash.hash * (float)64.0);
        v35 = idEntity::GetPhysics(this);
        v36 = (float *)v35->GetOrigin(this: v35, a2: 0);
        v37 = (float)(v36[2] + (float)v34);
        v38 = (float)(v36[1] + (float)v33);
        *(float *)&v56.eventHash.lookupMask = (float)v32 + *v36;
        *(float *)&v56.receivers.list = v37;
        *(float *)&v56.eventHash.memTag = v38;
        v39 = idEntity::GetPhysics(this);
        v40 = (int)v39->GetOrigin(this: v39, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, idColor *, int, int *, double))clientGame->renderWorld->DebugArrow)(
          a1: clientGame->renderWorld,
          a2: &idColor::colorOrange,
          a3: v40,
          a4: &v56.eventHash.lookupMask,
          a5: 2.0);
      }
      if ( v7 == nullptr
        || ((value = v7->aiVolatile.memory.usedProp.spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13)
         || (v42 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
          ? (v43 = nullptr)
          : (v43 = (idProp_WeaponStatic *)idEntity::CastTo(c: v42)),
            idProp_WeaponStatic::CastTo(c: v43) == nullptr) )
      {
        if ( idEntity::GetLocationCallingVO(this: ent, caller: this) == nullptr )
        {
          if ( idEntity::GetLocationCallingSS(this: ent, caller: this) != nullptr )
          {
            LocationCallingSS = idEntity::GetLocationCallingSS(this: ent, caller: this);
            idEntity::StartSoundShader(
              this,
              channel: SND_CHANNEL_VOICE,
              shader: LocationCallingSS,
              soundShaderFlags: 0,
              peerMask: 0xFFu);
          }
          else if ( ent->GetFaction_2(this: ent) == nullptr
                 || ((v45 = ent->GetFaction_2(this: ent))->myFaction != nullptr
                   ? (String = idLocalization::GetString(inString: v45->myFaction->factionNameId.data))
                   : (String = &byte_8200D768),
                     idStr::Icmp(s1: String, s2: "muties") != 0) )
          {
            if ( idTurret::CastTo(c: (idTurret *)ent) == nullptr )
            {
              entityDef = ent->entityDef;
              if ( entityDef != nullptr )
                str = entityDef->name.str;
              else
                str = "*unknown*";
              idStr::Find(searchIn: str, searchFor: "sentrybot", casesensitive: false, start: 0, end: -1);
            }
          }
        }
      }
    }
    else if ( v7 == nullptr || v7->actorConstants.actorClass != ACTORCLASS_MUTANT )
    {
      idTurret::CastTo(c: (idTurret *)ent);
    }
    idAI2::GetVoiceController(this, vc: 1u);
    if ( this->aiEditable.behaviors.declBehaviorEvents != nullptr )
    {
      v49 = idEntity::GetPhysics(this);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v51 = v49;
      GetOrigin = v49->GetOrigin;
      declBehaviorEvents = this->aiEditable.behaviors.declBehaviorEvents;
      p_aiEventManager = (idHandle<int,enum invalidAIEvent_t,-1> *)&gameLocal->aiEventManager;
      v55 = GetOrigin(this: v51, a2: 0);
      idAIEventManager::AddEvent(
        this: &v56,
        result: p_aiEventManager,
        eventDecl: declBehaviorEvents->enemySightedVoiceEventDecl,
        curTime: GameMs,
        originator: this,
        instigator: ent,
        origin: v55,
        delay: 500);
    }
  }
}


// ========================================================================
// ?Event_AwarenessRegained@idAI2@@QAA?AVeventVoid@@PAVidEntity@@HH@Z
// EA  : 0x82A371B8
// RVA : 0x00A371B8
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_AwarenessRegained(
        idAI2 *this,
        idAI2 *result,
        idAI2 *ent,
        const int oldAwareness,
        const int newAwareness)
{
  int value; // r8
  idEntity *v10; // r3
  idEntity *v11; // r3
  idPlayer *v12; // r31
  idFaction *v13; // r30
  const idFaction *v14; // r3
  idPlayerHud *PlayerHud; // r3

  if ( ent != nullptr )
  {
    value = result->aiVolatile.memory.currentEnemy.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v10 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v11 = idEntity::CastTo(c: v10);
    }
    else
    {
      v11 = nullptr;
    }
    if ( v11 == ent && newAwareness == 3 )
      idAI2::EnemySightedHelper(this: result, ent, firstSight: false);
  }
  v12 = idPlayer::CastTo(c: (idPlayer *)ent);
  if ( v12 != nullptr )
  {
    v13 = result->GetFaction(this: result);
    v14 = v12->GetFaction(this: v12);
    if ( idFaction::GetAttitudeTowards(this: v13, otherFaction: v14) < ATTITUDE_NEUTRAL )
    {
      PlayerHud = idPlayer::GetPlayerHud(this: v12);
      idPlayerHud::ActivateCombatHud(this: PlayerHud);
    }
  }
  return this;
}


// ========================================================================
// ?Event_FlyBack@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A372B8
// RVA : 0x00A372B8
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_FlyBack(idAI2 *this, idAI2 *result)
{
  int value; // r8
  idPlayer *v5; // r3
  const idDeclPlayerProps::playerSounds_t *ControllingPlayer; // r3
  const idSoundShader *sndPossess; // r29
  idPlayer *v8; // r3
  idPlayer *v9; // r3
  idVec3 v11; // [sp+50h] [-100h] BYREF
  char v12; // [sp+60h] [-F0h] BYREF

  if ( idAI2::IsPlayerControlled(this: result) )
  {
    value = result->aiVolatile.playerControl.player.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v5 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF];
      if ( v5 != nullptr && idPlayer::CastTo(c: v5) != nullptr )
      {
        ControllingPlayer = (const idDeclPlayerProps::playerSounds_t *)idAI2::GetControllingPlayer(this: result);
        sndPossess = idPlayer::GetPlayerSounds(this: (idPlayer *)&v12, result: ControllingPlayer)->sndPossess;
        v8 = idAI2::GetControllingPlayer(this: result);
        idEntity::StartSoundShader(
          this: v8,
          channel: SND_CHANNEL_BODY3,
          shader: sndPossess,
          soundShaderFlags: 8,
          peerMask: 0xFFu);
        v9 = idAI2::GetControllingPlayer(this: result);
        v9->GetEyePos(this: v9, a2: &v11);
        idAICamera_Control::FlyTo(this: &result->aiVolatile.playerControl.camera, endPos: &v11);
        idEventReceiver::PostEventMS(this: result, ev: &EV_RelinquishControl, time: 750);
      }
    }
  }
  return this;
}


// ========================================================================
// ?Event_GetLastAIEventOriginator@idAI2@@QAA?AVeventEntity@@XZ
// EA  : 0x82A373B0
// RVA : 0x00A373B0
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_GetLastAIEventOriginator(idAI2 *this, eventEntity *result)
{
  idEntity *value; // r8
  idEntity *v4; // r3
  idEntity *v5; // r4

  value = result[14085].value;
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
// ?Event_GetLastAIEventInstigator@idAI2@@QAA?AVeventEntity@@XZ
// EA  : 0x82A37438
// RVA : 0x00A37438
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_GetLastAIEventInstigator(idAI2 *this, eventEntity *result)
{
  idEntity *value; // r8
  idEntity *v4; // r3
  idEntity *v5; // r4

  value = result[14086].value;
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
// ?Event_GetInteractionEntity@idAI2@@QAA?AVeventEntity@@XZ
// EA  : 0x82A374C0
// RVA : 0x00A374C0
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_GetInteractionEntity(idAI2 *this, eventEntity *result)
{
  idEntity *value; // r8
  idPlayer *v4; // r3
  idPlayer *v5; // r4

  value = result[14711].value;
  if ( gameLocal->spawnIds.ptr[(unsigned __int16)value & 0x1FFF] == (int)value >> 13
    && (v4 = (idPlayer *)gameLocal->entities.ptr[(unsigned __int16)value & 0x1FFF]) != nullptr )
  {
    v5 = idPlayer::CastTo(c: v4);
  }
  else
  {
    v5 = nullptr;
  }
  eventEntity::eventEntity((eventEntity *)this, e: v5);
  return this;
}


// ========================================================================
// ?Event_PlayerTriggeredInteraction@idAI2@@QAA?AVeventBool@@PAVidEntity@@@Z
// EA  : 0x82A37548
// RVA : 0x00A37548
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_PlayerTriggeredInteraction(idAI2 *this, eventBool *result, idPlayer *playerEnt)
{
  int v5; // r8
  idPlayer *v6; // r3
  idPlayer *v7; // r3

  v5 = *(_DWORD *)&result[58864].value;
  if ( gameLocal->spawnIds.ptr[v5 & 0x1FFF] == v5 >> 13
    && (v6 = (idPlayer *)gameLocal->entities.ptr[v5 & 0x1FFF]) != nullptr )
  {
    v7 = idPlayer::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  eventBool::eventBool((eventBool *)this, b: playerEnt == v7);
  return this;
}


// ========================================================================
// ?Event_AwarenessGained@idAI2@@QAA?AVeventVoid@@PAVidEntity@@HH@Z
// EA  : 0x82A375E8
// RVA : 0x00A375E8
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_AwarenessGained(
        idAI2 *this,
        idAI2 *result,
        idAI2 *ent,
        const int oldAwareness,
        const int newAwareness)
{
  eventVoid *p_currentEnemy; // r29
  idGameLocal *v11; // r11
  int value; // r9
  idEntity *v13; // r3
  idEntity *v14; // r3
  idEntity *v15; // r3
  idEntity *v16; // r3
  idEntity *v17; // r3
  idFaction *v18; // r3
  idAIEntityState *v19; // r3
  idPlayer *v20; // r31
  idFaction *v21; // r30
  const idFaction *v22; // r3
  idPlayerHud *PlayerHud; // r3

  if ( ent != nullptr )
  {
    p_currentEnemy = (eventVoid *)&result->aiVolatile.memory.currentEnemy;
    v11 = gameLocal;
    value = result->aiVolatile.memory.currentEnemy.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v13 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v14 = idEntity::CastTo(c: v13);
      v11 = gameLocal;
    }
    else
    {
      v14 = nullptr;
    }
    if ( v14 == ent )
    {
      idAI2::UpdatePathToEnemy(this: result, force: true);
      v11 = gameLocal;
    }
    if ( v11->spawnIds.ptr[*(_DWORD *)p_currentEnemy & 0x1FFF] == *(_DWORD *)p_currentEnemy >> 13
      && (v15 = v11->entities.ptr[*(_DWORD *)p_currentEnemy & 0x1FFF]) != nullptr )
    {
      v16 = idEntity::CastTo(c: v15);
      v11 = gameLocal;
    }
    else
    {
      v16 = nullptr;
    }
    if ( v16 == ent && newAwareness == 3
      || (v11->spawnIds.ptr[*(_DWORD *)p_currentEnemy & 0x1FFF] != *(_DWORD *)p_currentEnemy >> 13
       || (v17 = v11->entities.ptr[*(_DWORD *)p_currentEnemy & 0x1FFF]) == nullptr
       || idEntity::CastTo(c: v17) == nullptr)
      && result->GetFaction(this: result) != nullptr
      && (v18 = result->GetFaction(this: result),
          idFaction::GetAttitudeTowards(this: v18, otherEnt: ent) < ATTITUDE_NEUTRAL)
      && (v19 = idAIWorldState::StateForEntity(this: &result->aiVolatile.world.worldState, ent)) != nullptr
      && v19->senses.ptr[1]->lastUnconfirmedStimTime >= 0
      && v19->lastVisible == 4 )
    {
      idAI2::EnemySightedHelper(this: result, ent, firstSight: true);
    }
    v20 = idPlayer::CastTo(c: (idPlayer *)ent);
    if ( v20 != nullptr )
    {
      v21 = result->GetFaction(this: result);
      v22 = v20->GetFaction(this: v20);
      if ( idFaction::GetAttitudeTowards(this: v21, otherFaction: v22) < ATTITUDE_NEUTRAL )
      {
        PlayerHud = idPlayer::GetPlayerHud(this: v20);
        idPlayerHud::ActivateCombatHud(this: PlayerHud);
      }
    }
    return this;
  }
  else
  {
    idLib::Warning(fmt: "idAI2::Event_AwarenessGained - NULL entity.");
    return this;
  }
}


// ========================================================================
// ?Event_Surprised@idAI2@@QAA?AVeventVoid@@H@Z
// EA  : 0x82A37810
// RVA : 0x00A37810
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_Surprised(idAI2 *this, idAI2 *result, int surprisedBySpawnId)
{
  idAI2 *v5; // r4

  v5 = (idAI2 *)gameLocal->GetEntityForSpawnId_2(this: gameLocal, a2: surprisedBySpawnId);
  if ( v5 != nullptr )
  {
    idAI2::EnemySightedHelper(this: result, ent: v5, firstSight: false);
    result->aiVolatile.memory.lastSurprisedTime = idGameTimeManager::GetGameMs(
                                                    this: &clientGame->gameTimeManager,
                                                    type: GAMETIME_SCALED);
  }
  return this;
}


// ========================================================================
// ?Event_AddAggression@idAI2@@QAA?AVeventVoid@@PBVidEntity@@MM@Z
// EA  : 0x82A378A0
// RVA : 0x00A378A0
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_AddAggression(
        idAI2 *this,
        eventVoid *result,
        const idEntity *ent,
        double aggression,
        double duration)
{
  int GameMs; // r3
  __int64 v11; // r6
  int v12; // r8

  if ( duration < 0.0 )
  {
    v12 = -1;
  }
  else
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    LODWORD(v11) = timeManager.gameTimePerFrame.value * timeManager.gameHz;
    v12 = (int)(float)((float)((float)v11 * (float)duration) + (float)__SPAIR64__(&timeManager, GameMs));
  }
  if ( ent != nullptr )
    *(_DWORD *)&result[58008] = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
  else
    *(_DWORD *)&result[58008] = 0x1FFF;
  *(float *)&result[58884] = aggression;
  *(_DWORD *)&result[58888] = v12;
  return this;
}


// ========================================================================
// ?Event_AnimWeb_StartUseTurret@idAI2@@QAA?AVeventVoid@@HHHH@Z
// EA  : 0x82A379A0
// RVA : 0x00A379A0
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_AnimWeb_StartUseTurret(
        idAI2 *this,
        eventVoid *result,
        const int webHandle,
        const int subWebIndex,
        const int stateIndex,
        const int eventParm)
{
  eventVoid *v6; // r29
  int v9; // r9
  idEntity *v10; // r3
  idProp_WeaponStatic *v11; // r3
  idProp_WeaponStatic *v12; // r30
  int GameMs; // r27
  const idAnimStack *v14; // r3

  v6 = result + 58152;
  v9 = *(_DWORD *)&result[58152];
  if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13 && (v10 = gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr )
    v11 = (idProp_WeaponStatic *)idEntity::CastTo(c: v10);
  else
    v11 = nullptr;
  v12 = idProp_WeaponStatic::CastTo(c: v11);
  if ( v12 != nullptr )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v14 = (const idAnimStack *)(*(int (__fastcall **)(eventVoid *))(*(_DWORD *)result + 184))(a1: result);
    idAnimator_Base::Start(
      this: (idAnimator_Base *)&result[33964],
      stack: v14,
      curTime: GameMs,
      blendDurationMS: 250,
      reset: true);
    if ( v12->Use(this: v12, a2: (idEntity *)result, a3: USABLE_MAX) )
    {
      *(_BYTE *)&result[11056] &= ~0x80u;
      return this;
    }
    *(_DWORD *)v6 = 0x1FFF;
  }
  return this;
}


// ========================================================================
// ?Event_ActionNode@idAI2@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82A37AB8
// RVA : 0x00A37AB8
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_ActionNode(idAI2 *this, idAI2 *result, idActionNode *newActionNode)
{
  idActionNode *v5; // r30
  idAIFSMManager_vtbl *v6; // r11
  idAIFSM *v7; // r3
  idAIFSM *v8; // r31
  int GameMs; // r3

  v5 = idActionNode::CastTo(c: newActionNode);
  if ( v5 != nullptr )
  {
    idAI2::LeaveActionNode(this: result, force: true);
    idActionNode::ReserveActionNode(this: v5, user: result);
    result->aiVolatile.memory.currentActionNode.spawnId.value = (gameLocal->spawnIds.ptr[v5->entityNumber] << 13)
                                                              | v5->entityNumber;
    v6 = result->aiVolatile.fsms.fsmManager.__vftable;
    result->aiVolatile.numActionNodes = 1;
    v7 = (idAIFSM *)v6->FindFSM_3(this: &result->aiVolatile.fsms.fsmManager, a2: &idAlertCycleFSM::Type);
    v8 = idAIFSM::CastTo(c: v7);
    if ( v8 != nullptr )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idFiniteStateMachine::Restart(this: v8, curTime: GameMs);
    }
  }
  return this;
}


// ========================================================================
// ?Event_Touch@idAI2@@QAA?AVeventVoid@@PBVidEntity@@H@Z
// EA  : 0x82A37B90
// RVA : 0x00A37B90
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_Touch(idAI2 *this, eventVoid *result, idActor *other, const int clipModelId)
{
  eventVoid *v7; // r9
  idAI2 *v8; // r3

  if ( idActor::CastTo(c: other) != nullptr )
    result[58384] = (eventVoid)1;
  v7 = result + 58380;
  v8 = this;
  if ( other != nullptr )
    *(_DWORD *)v7 = (gameLocal->spawnIds.ptr[other->entityNumber] << 13) | other->entityNumber;
  else
    *(_DWORD *)v7 = 0x1FFF;
  return v8;
}


// ========================================================================
// ?Event_SetInteractionEntity@idAI2@@QAA?AVeventVoid@@PBVidEntity@@@Z
// EA  : 0x82A37C18
// RVA : 0x00A37C18
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_SetInteractionEntity(idAI2 *this, eventVoid *result, idPlayer *ent)
{
  idPlayer *v5; // r3
  eventVoid *v6; // r9

  v5 = idPlayer::CastTo(c: ent);
  v6 = result + 58844;
  if ( v5 != nullptr )
    *(_DWORD *)v6 = (gameLocal->spawnIds.ptr[v5->entityNumber] << 13) | v5->entityNumber;
  else
    *(_DWORD *)v6 = 0x1FFF;
  return this;
}


// ========================================================================
// ?Event_BeginWaitForPlayerInteraction@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A37C98
// RVA : 0x00A37C98
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idAI2::Event_BeginWaitForPlayerInteraction(idAI2 *this)
{
  __int64 result; // r4 OVERLAPPED

  *(_DWORD *)(result + 58864) = 0x1FFF;
  *(_BYTE *)(result + 58868) = 1;
  return result;
}


// ========================================================================
// ?Event_GetCurrentPlayerInteractionIndex@idAI2@@QAA?AVeventInt@@PAVidPlayer@@@Z
// EA  : 0x82A37CC0
// RVA : 0x00A37CC0
// PDB : w:\tech5\tungsten\game\ai\ai2_events.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_GetCurrentPlayerInteractionIndex(idAI2 *this, idAI2 *result, idPlayer *player)
{
  eventInt *p_currentPlayerInteraction; // r26
  int currentPlayerInteraction; // r28
  const idDeclAIPlayerInteraction *decl; // r27
  const aiPlayerInteraction_t *v9; // r3
  const aiPlayerInteraction_t *Interaction; // r3
  const aiPlayerInteraction_t *v11; // r30
  idAIEntityState *v13; // r3
  eventInt *p_interactionEntity; // r9

  p_currentPlayerInteraction = (eventInt *)&result->aiVolatile.memory.currentPlayerInteraction;
  currentPlayerInteraction = result->aiVolatile.memory.currentPlayerInteraction;
  if ( currentPlayerInteraction >= 0 )
  {
    decl = result->aiVolatile.aiPlayerInteraction.decl;
    v9 = idAI2::GetCurrentPlayerInteraction(this: result);
    if ( idAIPlayerInteraction::InteractionHasExpired(
           this: &result->aiVolatile.aiPlayerInteraction,
           interaction: v9,
           player,
           interactionDecl: decl,
           interactionNumber: currentPlayerInteraction) )
    {
      idAI2::PlayerInteractionDone(this: result, playerLeft: true);
      currentPlayerInteraction = -1;
    }
  }
  Interaction = idAIPlayerInteraction::FindInteraction(
                  this: &result->aiVolatile.aiPlayerInteraction,
                  player,
                  modifyState: true,
                  debugString: nullptr);
  v11 = Interaction;
  if ( Interaction != nullptr
    && (!Interaction->activateWhenVisible
     || (*((_BYTE *)&result->aiVolatile + 49704) & 8) == 0
     || (v13 = idAIWorldState::StateForEntity(this: &result->aiVolatile.world.worldState, ent: player)) != nullptr
     && idAIEntityState::IsVisible(this: v13)) )
  {
    if ( currentPlayerInteraction < 0 )
    {
      currentPlayerInteraction = idAIPlayerInteraction::GetInteractionIndex(
                                   this: &result->aiVolatile.aiPlayerInteraction,
                                   interaction: v11);
      p_currentPlayerInteraction->value = currentPlayerInteraction;
    }
    p_interactionEntity = (eventInt *)&result->aiVolatile.memory.interactionEntity;
    if ( player != nullptr )
      p_interactionEntity->value = (gameLocal->spawnIds.ptr[player->entityNumber] << 13) | player->entityNumber;
    else
      p_interactionEntity->value = 0x1FFF;
    eventInt::eventInt((eventInt *)this, i: currentPlayerInteraction);
    return this;
  }
  else
  {
    eventInt::eventInt((eventInt *)this, i: -1);
    return this;
  }
}

