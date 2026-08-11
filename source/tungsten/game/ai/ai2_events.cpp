#include "ai2.h"

namespace {

void DispatchEvent(idAI2& ai, idAI2EventCall& call) {
    if (ai.core.services != nullptr) {
        ai.core.services->DispatchAIEvent(ai, call);
    }
}

eventDecl DeclResult(const idDecl* declaration) {
    eventDecl result{};
    result.value = declaration;
    return result;
}

eventDecl DeclResult(const idAI2EventCall& call) {
    return DeclResult(call.declResult);
}

void PackAnimWebEvent(idAI2EventCall& call, const int webHandle,
        const int subWebIndex, const int stateIndex,
        const int eventParameter) {
    call.integers[0] = webHandle;
    call.integers[1] = subWebIndex;
    call.integers[2] = stateIndex;
    call.integers[3] = eventParameter;
}

eventDecl DispatchJobEvent(idAI2& ai, const char* operation,
        idEntity* const player, const bool playVoiceOver) {
    idAI2EventCall call(operation);
    call.inputs[0] = player;
    call.booleans[0] = playVoiceOver;
    DispatchEvent(ai, call);
    return DeclResult(call);
}

} // namespace

// Retail symbol: ?Event_MoveToScenepoint@idAI2@@QAA?AVeventVoid@@PAVidScenePoint@@W4moveToScenePointFlags_t@@@Z
// EA: 0x82A34DA8, RVA: 0x00A34DA8
eventVoid idAI2::Event_MoveToScenepoint(idScenePoint* const scenePoint,
        const moveToScenePointFlags_t flags) {
    return Action_MoveToScenePoint(
        reinterpret_cast<const idEntity*>(scenePoint), flags);
}

// Retail symbol: ?Event_MoveToPathPoint@idAI2@@QAA?AVeventVoid@@PBVidEntity@@@Z
// EA: 0x82A34DD8, RVA: 0x00A34DD8
eventVoid idAI2::Event_MoveToPathPoint(const idEntity* const pathPoint) {
    return Action_MoveToPathPoint(pathPoint);
}

// Retail symbol: ?Event_SetAlertCycle@idAI2@@QAA?AVeventVoid@@W4alertCycle_t@@@Z
// EA: 0x82A34E08, RVA: 0x00A34E08
eventVoid idAI2::Event_SetAlertCycle(const alertCycle_t alertCycle) {
    return Action_SetAlertCycle(alertCycle);
}

// Retail symbol: ?Event_SetCallback@idAI2@@QAA?AVeventInt@@XZ
// EA: 0x82A34E38, RVA: 0x00A34E38
eventInt idAI2::Event_SetCallback() {
    return eventInt(1);
}

// Retail symbol: ?Event_GetCurrentAIEventClass@idAI2@@QAA?AVeventInt@@XZ
// EA: 0x82A34E70, RVA: 0x00A34E70
eventInt idAI2::Event_GetCurrentAIEventClass() {
    return eventInt(0);
}

// Retail symbol: ?Event_GetLastAIEventClass@idAI2@@QAA?AVeventInt@@XZ
// EA: 0x82A34EA8, RVA: 0x00A34EA8
eventInt idAI2::Event_GetLastAIEventClass() {
    idAI2EventCall call("Event_GetLastAIEventClass");
    DispatchEvent(*this, call);
    return eventInt(call.intResult);
}

// Retail symbol: ?Event_GetLastAIEventOrigin@idAI2@@QAA?AVeventVector@@XZ
// EA: 0x82A34EE8, RVA: 0x00A34EE8
eventVector idAI2::Event_GetLastAIEventOrigin() {
    idAI2EventCall call("Event_GetLastAIEventOrigin");
    DispatchEvent(*this, call);
    return eventVector(call.vectorResult);
}

// Retail symbol: ?Event_GetCurrentPlayerInteractionState@idAI2@@QAA?AVeventInt@@PBVidEntity@@@Z
// EA: 0x82A34F20, RVA: 0x00A34F20
eventInt idAI2::Event_GetCurrentPlayerInteractionState(
        const idEntity* const entity) {
    idAI2EventCall call("Event_GetCurrentPlayerInteractionState");
    call.inputs[0] = entity;
    DispatchEvent(*this, call);
    return eventInt(call.intResult);
}

// Retail symbol: ?Event_JobApproach@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA: 0x82A34F78, RVA: 0x00A34F78
eventDecl idAI2::Event_JobApproach(idEntity* const player,
        const bool playVoiceOver) {
    return DispatchJobEvent(*this, "Event_JobApproach",
        player, playVoiceOver);
}

// Retail symbol: ?Event_NonJobVO@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA: 0x82A34FC0, RVA: 0x00A34FC0
eventDecl idAI2::Event_NonJobVO(idEntity*, bool) {
    return DeclResult(nullptr);
}

// Retail symbol: ?Event_JobOffer@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA: 0x82A35008, RVA: 0x00A35008
eventDecl idAI2::Event_JobOffer(idEntity* const player,
        const bool playVoiceOver) {
    return DispatchJobEvent(*this, "Event_JobOffer",
        player, playVoiceOver);
}

// Retail symbol: ?Event_JobMessageVO@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA: 0x82A35050, RVA: 0x00A35050
eventDecl idAI2::Event_JobMessageVO(idEntity* const player,
        const bool playVoiceOver) {
    return DispatchJobEvent(*this, "Event_JobMessageVO",
        player, playVoiceOver);
}

// Retail symbol: ?Event_JobEnd@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA: 0x82A350A0, RVA: 0x00A350A0
eventDecl idAI2::Event_JobEnd(idEntity* const player,
        const bool playVoiceOver) {
    return DispatchJobEvent(*this, "Event_JobEnd",
        player, playVoiceOver);
}

// Retail symbol: ?Event_JobComplete@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA: 0x82A350E8, RVA: 0x00A350E8
eventDecl idAI2::Event_JobComplete(idEntity* const player,
        const bool playVoiceOver) {
    return DispatchJobEvent(*this, "Event_JobComplete",
        player, playVoiceOver);
}

// Retail symbol: ?Event_JobFailed@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA: 0x82A35130, RVA: 0x00A35130
eventDecl idAI2::Event_JobFailed(idEntity* const player,
        const bool playVoiceOver) {
    return DispatchJobEvent(*this, "Event_JobFailed",
        player, playVoiceOver);
}

// Retail symbol: ?Event_JobInProgress@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA: 0x82A35178, RVA: 0x00A35178
eventDecl idAI2::Event_JobInProgress(idEntity* const player,
        const bool playVoiceOver) {
    return DispatchJobEvent(*this, "Event_JobInProgress",
        player, playVoiceOver);
}

// Retail symbol: ?Event_AcceptedJob@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA: 0x82A351C0, RVA: 0x00A351C0
eventDecl idAI2::Event_AcceptedJob(idEntity* const player,
        const bool playVoiceOver) {
    return DispatchJobEvent(*this, "Event_AcceptedJob",
        player, playVoiceOver);
}

// Retail symbol: ?Event_DeclinedJob@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA: 0x82A35208, RVA: 0x00A35208
eventDecl idAI2::Event_DeclinedJob(idEntity* const player,
        const bool playVoiceOver) {
    return DispatchJobEvent(*this, "Event_DeclinedJob",
        player, playVoiceOver);
}

// Retail symbol: ?Event_PlayerLeft@idAI2@@QAA?AVeventDecl@@PAVidEntity@@_N@Z
// EA: 0x82A35250, RVA: 0x00A35250
eventDecl idAI2::Event_PlayerLeft(idEntity* const player,
        const bool playVoiceOver) {
    return DispatchJobEvent(*this, "Event_PlayerLeft",
        player, playVoiceOver);
}

// Retail symbol: ?Event_CompleteSavedJob@idAI2@@QAA?AVeventBool@@PAVidEntity@@@Z
// EA: 0x82A35298, RVA: 0x00A35298
eventBool idAI2::Event_CompleteSavedJob(idEntity* const player) {
    idAI2EventCall call("Event_CompleteSavedJob");
    call.inputs[0] = player;
    DispatchEvent(*this, call);
    return eventBool(call.boolResult);
}

// Retail symbol: ?Event_AcceptSavedJob@idAI2@@QAA?AVeventBool@@PAVidEntity@@@Z
// EA: 0x82A35308, RVA: 0x00A35308
eventBool idAI2::Event_AcceptSavedJob(idEntity* const player) {
    idAI2EventCall call("Event_AcceptSavedJob");
    call.inputs[0] = player;
    DispatchEvent(*this, call);
    return eventBool(call.boolResult);
}

// Retail symbol: ?Event_GetDeclAIPlayerInteraction@idAI2@@QAA?AVeventDecl@@XZ
// EA: 0x82A35378, RVA: 0x00A35378
eventDecl idAI2::Event_GetDeclAIPlayerInteraction() {
    idAI2EventCall call("Event_GetDeclAIPlayerInteraction");
    DispatchEvent(*this, call);
    return DeclResult(call);
}

// Retail symbol: ?Event_GetPlayerInteractionApproachRadius@idAI2@@QAA?AVeventFloat@@XZ
// EA: 0x82A353B0, RVA: 0x00A353B0
eventFloat idAI2::Event_GetPlayerInteractionApproachRadius() {
    idAI2EventCall call("Event_GetPlayerInteractionApproachRadius");
    call.floatResult = core.interactionApproachRadius;
    DispatchEvent(*this, call);
    return eventFloat(call.floatResult);
}

// Retail symbol: ?Event_GetPlayerInteractionDepartureRadius@idAI2@@QAA?AVeventFloat@@XZ
// EA: 0x82A35400, RVA: 0x00A35400
eventFloat idAI2::Event_GetPlayerInteractionDepartureRadius() {
    idAI2EventCall call("Event_GetPlayerInteractionDepartureRadius");
    DispatchEvent(*this, call);
    return eventFloat(call.floatResult);
}

// Retail symbol: ?Event_UpdateGroupAmbush@idAI2@@QAA?AVeventVoid@@ABVidVec3@@@Z
// EA: 0x82A35490, RVA: 0x00A35490
eventVoid idAI2::Event_UpdateGroupAmbush(const idVec3& position) {
    idAI2EventCall call("Event_UpdateGroupAmbush");
    call.inputs[0] = &position;
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?Event_KillAI@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A354D0, RVA: 0x00A354D0
eventVoid idAI2::Event_KillAI() {
    core.dying = true;
    StartDeathSystem();
    return eventVoid();
}

// Retail symbol: ?Event_AnimWeb_Wait@idAI2@@QAA?AVeventVoid@@HHHH@Z
// EA: 0x82A35510, RVA: 0x00A35510
eventVoid idAI2::Event_AnimWeb_Wait(const int webHandle,
        const int subWebIndex, const int stateIndex,
        const int eventParameter) {
    idAI2EventCall call("Event_AnimWeb_Wait");
    PackAnimWebEvent(call, webHandle, subWebIndex,
        stateIndex, eventParameter);
    DispatchEvent(*this, call);
    core.playingTraversalAnimation = false;
    return eventVoid();
}

// Retail symbol: ?Event_AnimWeb_StartDeltaCorrection@idAI2@@QAA?AVeventVoid@@HHHH@Z
// EA: 0x82A35590, RVA: 0x00A35590
eventVoid idAI2::Event_AnimWeb_StartDeltaCorrection(
        const int webHandle, const int subWebIndex,
        const int stateIndex, const int eventParameter) {
    idAI2EventCall call("Event_AnimWeb_StartDeltaCorrection");
    PackAnimWebEvent(call, webHandle, subWebIndex,
        stateIndex, eventParameter);
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?Event_AnimWeb_BeginAnim@idAI2@@QAA?AVeventVoid@@HHHH@Z
// EA: 0x82A355E0, RVA: 0x00A355E0
eventVoid idAI2::Event_AnimWeb_BeginAnim(const int webHandle,
        const int subWebIndex, const int stateIndex,
        const int eventParameter) {
    idAI2EventCall call("Event_AnimWeb_BeginAnim");
    PackAnimWebEvent(call, webHandle, subWebIndex,
        stateIndex, eventParameter);
    DispatchEvent(*this, call);
    core.movementStartFrame = core.currentTime;
    core.remainingTransitionFrames = eventParameter;
    return eventVoid();
}

// Retail symbol: ?Event_AnimWeb_ReloadRightFinished@idAI2@@QAA?AVeventVoid@@HHHH@Z
// EA: 0x82A35638, RVA: 0x00A35638
eventVoid idAI2::Event_AnimWeb_ReloadRightFinished(
        const int webHandle, const int subWebIndex,
        const int stateIndex, const int eventParameter) {
    idAI2EventCall call("Event_AnimWeb_ReloadRightFinished");
    PackAnimWebEvent(call, webHandle, subWebIndex,
        stateIndex, eventParameter);
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?Event_AnimWeb_EnableFireFromCover@idAI2@@QAA?AVeventVoid@@HHHH@Z
// EA: 0x82A35680, RVA: 0x00A35680
eventVoid idAI2::Event_AnimWeb_EnableFireFromCover(
        const int webHandle, const int subWebIndex,
        const int stateIndex, const int eventParameter) {
    idAI2EventCall call("Event_AnimWeb_EnableFireFromCover");
    PackAnimWebEvent(call, webHandle, subWebIndex,
        stateIndex, eventParameter);
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?Event_RelinquishControl@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A356E0, RVA: 0x00A356E0
eventVoid idAI2::Event_RelinquishControl() {
    RelinquishControl();
    return eventVoid();
}

// Retail symbol: ?Event_DropWeapons@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A35718, RVA: 0x00A35718
eventVoid idAI2::Event_DropWeapons() {
    idAI2EventCall call("Event_DropWeapons");
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?Event_TurnOffLaserSight@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A35780, RVA: 0x00A35780
eventVoid idAI2::Event_TurnOffLaserSight() {
    idAI2EventCall call("Event_TurnOffLaserSight");
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?Event_TurnOnLaserSight@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A357D0, RVA: 0x00A357D0
eventVoid idAI2::Event_TurnOnLaserSight() {
    idAI2EventCall call("Event_TurnOnLaserSight");
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?Event_Path@idAI2@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA: 0x82A35830, RVA: 0x00A35830
eventVoid idAI2::Event_Path(idEntity* const path) {
    idAI2EventCall call("Event_Path");
    call.inputs[0] = path;
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?Event_StartVoiceOver@idAI2@@QAA?AVeventBool@@PAVidEntity@@PBVidDeclVoiceOver@@_N@Z
// EA: 0x82A35908, RVA: 0x00A35908
eventBool idAI2::Event_StartVoiceOver(idEntity* const talkingTo,
        const idDeclVoiceOver* const voiceOver,
        const bool playInCombat) {
    idAI2EventCall call("Event_StartVoiceOver");
    call.inputs[0] = talkingTo;
    call.inputs[1] = voiceOver;
    call.booleans[0] = playInCombat;
    DispatchEvent(*this, call);
    return eventBool(call.boolResult);
}

// Retail symbol: ?Event_StartInteractionVoiceOver@idAI2@@QAA?AVeventBool@@PAVidEntity@@PBVidDeclVoiceOver@@_N@Z
// EA: 0x82A35A20, RVA: 0x00A35A20
eventBool idAI2::Event_StartInteractionVoiceOver(
        idEntity* const talkingTo,
        const idDeclVoiceOver* const voiceOver,
        const bool playInCombat) {
    idAI2EventCall call("Event_StartInteractionVoiceOver");
    call.inputs[0] = talkingTo;
    call.inputs[1] = voiceOver;
    call.booleans[0] = playInCombat;
    DispatchEvent(*this, call);
    return eventBool(call.boolResult);
}

// Retail symbol: ?Event_IsVoiceOverPlaying@idAI2@@QAA?AVeventBool@@PBVidDeclVoiceOver@@@Z
// EA: 0x82A35B38, RVA: 0x00A35B38
eventBool idAI2::Event_IsVoiceOverPlaying(
        const idDeclVoiceOver* const voiceOver) {
    idAI2EventCall call("Event_IsVoiceOverPlaying");
    call.inputs[0] = voiceOver;
    DispatchEvent(*this, call);
    return eventBool(call.boolResult);
}

// Retail symbol: ?Event_GetPlayingVoiceOver@idAI2@@QAA?AVeventDecl@@XZ
// EA: 0x82A35B80, RVA: 0x00A35B80
eventDecl idAI2::Event_GetPlayingVoiceOver() {
    idAI2EventCall call("Event_GetPlayingVoiceOver");
    DispatchEvent(*this, call);
    return DeclResult(call);
}

// Retail symbol: ?Event_SetInteracting@idAI2@@QAA?AVeventVoid@@_N@Z
// EA: 0x82A35BC0, RVA: 0x00A35BC0
eventVoid idAI2::Event_SetInteracting(const bool interacting) {
    SetInteracting(interacting);
    return eventVoid();
}

// Retail symbol: ?Event_SetJobOfferPlayed@idAI2@@QAA?AVeventBool@@PBVidDeclAIPlayerInteraction@@PAVidEntity@@H@Z
// EA: 0x82A35BF8, RVA: 0x00A35BF8
eventBool idAI2::Event_SetJobOfferPlayed(
        const idDeclAIPlayerInteraction* const declaration,
        idEntity* const player, const int interactionIndex) {
    idAI2EventCall call("Event_SetJobOfferPlayed");
    call.inputs[0] = declaration;
    call.inputs[1] = player;
    call.integers[0] = interactionIndex;
    DispatchEvent(*this, call);
    return eventBool(call.boolResult);
}

// Retail symbol: ?Event_SetFocus@idAI2@@QAA?AVeventVoid@@PBVidEntity@@_N1W4aimPoint_t@@@Z
// EA: 0x82A35CB8, RVA: 0x00A35CB8
eventVoid idAI2::Event_SetFocus(const idEntity* const entity,
        const bool aiming, const bool keepFocusInView,
        const aimPoint_t aimPoint) {
    if (aiming) {
        if (entity != nullptr) {
            SetAimFocusEntity(entity, keepFocusInView, aimPoint, -1);
        } else {
            ClearAimFocus();
        }
    } else if (entity != nullptr) {
        SetLookFocusEntity(entity, keepFocusInView, aimPoint, -1);
    } else {
        ClearLookFocus();
    }
    return eventVoid();
}

// Retail symbol: ?Event_ClearLookFocus@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A35D38, RVA: 0x00A35D38
eventVoid idAI2::Event_ClearLookFocus() {
    ClearLookFocus();
    return eventVoid();
}

// Retail symbol: ?Event_ClearAimFocus@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A35D70, RVA: 0x00A35D70
eventVoid idAI2::Event_ClearAimFocus() {
    ClearAimFocus();
    return eventVoid();
}

// Retail symbol: ?Event_EnableAutoFocus@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A35DA8, RVA: 0x00A35DA8
eventVoid idAI2::Event_EnableAutoFocus() {
    SetEnableAutoFocus(true);
    return eventVoid();
}

// Retail symbol: ?Event_GetPlayerInteractionName@idAI2@@QAA?AVeventString@@PBVidDeclAIPlayerInteraction@@H@Z
// EA: 0x82A35DE0, RVA: 0x00A35DE0
eventString idAI2::Event_GetPlayerInteractionName(
        const idDeclAIPlayerInteraction* const declaration,
        const int index) {
    idAI2EventCall call("Event_GetPlayerInteractionName");
    call.inputs[0] = declaration;
    call.integers[0] = index;
    DispatchEvent(*this, call);
    return eventString(call.stringResult != nullptr
        ? call.stringResult : "");
}

// Retail symbol: ?Event_GetPlayerInteractionJobDecl@idAI2@@QAA?AVeventDecl@@PBVidDeclAIPlayerInteraction@@H@Z
// EA: 0x82A35E88, RVA: 0x00A35E88
eventDecl idAI2::Event_GetPlayerInteractionJobDecl(
        const idDeclAIPlayerInteraction* const declaration,
        const int interactionIndex) {
    idAI2EventCall call("Event_GetPlayerInteractionJobDecl");
    call.inputs[0] = declaration;
    call.integers[0] = interactionIndex;
    DispatchEvent(*this, call);
    return DeclResult(call);
}

// Retail symbol: ?Event_BeginPlayerInteractionIndex@idAI2@@QAA?AVeventVoid@@H@Z
// EA: 0x82A35F30, RVA: 0x00A35F30
eventVoid idAI2::Event_BeginPlayerInteractionIndex(const int index) {
    core.currentPlayerInteractionIndex = index;
    idAI2EventCall call("Event_BeginPlayerInteractionIndex");
    call.integers[0] = index;
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?Event_SetRemoveHealthWhenDamaged@idAI2@@QAA?AVeventVoid@@_N@Z
// EA: 0x82A35FA0, RVA: 0x00A35FA0
eventVoid idAI2::Event_SetRemoveHealthWhenDamaged(
        const bool removeHealth) {
    core.removeHealthWhenDamaged = removeHealth;
    return eventVoid();
}

// Retail symbol: ?Event_SetEventOverloadEnableFlag@idAI2@@QAA?AVeventVoid@@H@Z
// EA: 0x82A35FB8, RVA: 0x00A35FB8
eventVoid idAI2::Event_SetEventOverloadEnableFlag(const int flags) {
    core.eventOverloadEnableFlags |= flags;
    return eventVoid();
}

// Retail symbol: ?Event_ClearEventOverloadEnableFlag@idAI2@@QAA?AVeventVoid@@H@Z
// EA: 0x82A35FD0, RVA: 0x00A35FD0
eventVoid idAI2::Event_ClearEventOverloadEnableFlag(const int flags) {
    core.eventOverloadEnableFlags &= ~flags;
    return eventVoid();
}

// Retail symbol: ?Event_SetEventOverloadDisableFlag@idAI2@@QAA?AVeventVoid@@H@Z
// EA: 0x82A35FE8, RVA: 0x00A35FE8
eventVoid idAI2::Event_SetEventOverloadDisableFlag(const int flags) {
    core.eventOverloadDisableFlags |= flags;
    return eventVoid();
}

// Retail symbol: ?Event_ClearEventOverloadDisableFlag@idAI2@@QAA?AVeventVoid@@H@Z
// EA: 0x82A36000, RVA: 0x00A36000
eventVoid idAI2::Event_ClearEventOverloadDisableFlag(const int flags) {
    core.eventOverloadDisableFlags &= ~flags;
    return eventVoid();
}

// Retail symbol: ?Event_SetBehaviorDecl@idAI2@@QAA?AVeventVoid@@PBVidDeclAIBehavior@@@Z
// EA: 0x82A36018, RVA: 0x00A36018
eventVoid idAI2::Event_SetBehaviorDecl(
        const idDeclAIBehavior* const declaration) {
    idAI2EventCall call("Event_SetBehaviorDecl");
    call.inputs[0] = declaration;
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?Event_ShouldTurnTo@idAI2@@QAA?AVeventInt@@PBVidEntity@@MMM@Z
// EA: 0x82A36090, RVA: 0x00A36090
eventInt idAI2::Event_ShouldTurnTo(const idEntity* const entity,
        const float leftDotThreshold, const float rightDotThreshold,
        const float offsetDegrees) {
    idAI2EventCall call("Event_ShouldTurnTo");
    call.inputs[0] = entity;
    call.scalars[0] = leftDotThreshold;
    call.scalars[1] = rightDotThreshold;
    call.scalars[2] = offsetDegrees;
    DispatchEvent(*this, call);
    return eventInt(call.intResult);
}

// Retail symbol: ?Event_IsEntityVisible@idAI2@@QAA?AVeventBool@@PBVidEntity@@@Z
// EA: 0x82A36348, RVA: 0x00A36348
eventBool idAI2::Event_IsEntityVisible(const idEntity* const entity) {
    idAI2EventCall call("Event_IsEntityVisible");
    call.inputs[0] = entity;
    DispatchEvent(*this, call);
    return eventBool(call.boolResult);
}

// Retail symbol: ?LocationCallingHelper@idAI2@@QAAXPBVidEntity@@@Z
// EA: 0x82A363A8, RVA: 0x00A363A8
void idAI2::LocationCallingHelper(const idEntity* const entity) {
    if (entity == nullptr) {
        return;
    }
    idAI2EventCall call("LocationCallingHelper");
    call.inputs[0] = entity;
    DispatchEvent(*this, call);
}

// Retail symbol: ?Event_SpawnLootBox@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A364B0, RVA: 0x00A364B0
eventVoid idAI2::Event_SpawnLootBox() {
    idAI2EventCall call("Event_SpawnLootBox");
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?Event_RemoveBody@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A36690, RVA: 0x00A36690
eventVoid idAI2::Event_RemoveBody() {
    idAI2EventCall call("Event_RemoveBody");
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?Event_AwarenessLost@idAI2@@QAA?AVeventVoid@@PAVidEntity@@HH@Z
// EA: 0x82A36B08, RVA: 0x00A36B08
eventVoid idAI2::Event_AwarenessLost(idEntity* const entity,
        const int oldAwareness, const int newAwareness) {
    idAI2EventCall call("Event_AwarenessLost");
    call.inputs[0] = entity;
    call.integers[0] = oldAwareness;
    call.integers[1] = newAwareness;
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?Event_ResetSearchPoints@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A36BE8, RVA: 0x00A36BE8
eventVoid idAI2::Event_ResetSearchPoints() {
    idAI2EventCall call("Event_ResetSearchPoints");
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?EnemySightedHelper@idAI2@@QAAXPBVidEntity@@_N@Z
// EA: 0x82A36C30, RVA: 0x00A36C30
void idAI2::EnemySightedHelper(const idEntity* const entity,
        const bool firstSight) {
    if (entity == nullptr) {
        return;
    }
    idAI2EventCall call("EnemySightedHelper");
    call.inputs[0] = entity;
    call.booleans[0] = firstSight;
    DispatchEvent(*this, call);
}

// Retail symbol: ?Event_AwarenessRegained@idAI2@@QAA?AVeventVoid@@PAVidEntity@@HH@Z
// EA: 0x82A371B8, RVA: 0x00A371B8
eventVoid idAI2::Event_AwarenessRegained(idEntity* const entity,
        const int oldAwareness, const int newAwareness) {
    idAI2EventCall call("Event_AwarenessRegained");
    call.inputs[0] = entity;
    call.integers[0] = oldAwareness;
    call.integers[1] = newAwareness;
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?Event_FlyBack@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A372B8, RVA: 0x00A372B8
eventVoid idAI2::Event_FlyBack() {
    idAI2EventCall call("Event_FlyBack");
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?Event_GetLastAIEventOriginator@idAI2@@QAA?AVeventEntity@@XZ
// EA: 0x82A373B0, RVA: 0x00A373B0
eventEntity idAI2::Event_GetLastAIEventOriginator() {
    idAI2EventCall call("Event_GetLastAIEventOriginator");
    DispatchEvent(*this, call);
    return eventEntity(call.entityResult);
}

// Retail symbol: ?Event_GetLastAIEventInstigator@idAI2@@QAA?AVeventEntity@@XZ
// EA: 0x82A37438, RVA: 0x00A37438
eventEntity idAI2::Event_GetLastAIEventInstigator() {
    idAI2EventCall call("Event_GetLastAIEventInstigator");
    DispatchEvent(*this, call);
    return eventEntity(call.entityResult);
}

// Retail symbol: ?Event_GetInteractionEntity@idAI2@@QAA?AVeventEntity@@XZ
// EA: 0x82A374C0, RVA: 0x00A374C0
eventEntity idAI2::Event_GetInteractionEntity() {
    return eventEntity(const_cast<idEntity*>(core.interactionEntity));
}

// Retail symbol: ?Event_PlayerTriggeredInteraction@idAI2@@QAA?AVeventBool@@PAVidEntity@@@Z
// EA: 0x82A37548, RVA: 0x00A37548
eventBool idAI2::Event_PlayerTriggeredInteraction(idEntity* const player) {
    return eventBool(core.playerTriggeredInteraction == player);
}

// Retail symbol: ?Event_AwarenessGained@idAI2@@QAA?AVeventVoid@@PAVidEntity@@HH@Z
// EA: 0x82A375E8, RVA: 0x00A375E8
eventVoid idAI2::Event_AwarenessGained(idEntity* const entity,
        const int oldAwareness, const int newAwareness) {
    idAI2EventCall call("Event_AwarenessGained");
    call.inputs[0] = entity;
    call.integers[0] = oldAwareness;
    call.integers[1] = newAwareness;
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?Event_Surprised@idAI2@@QAA?AVeventVoid@@H@Z
// EA: 0x82A37810, RVA: 0x00A37810
eventVoid idAI2::Event_Surprised(const int surprisedBySpawnId) {
    idAI2EventCall call("Event_Surprised");
    call.integers[0] = surprisedBySpawnId;
    DispatchEvent(*this, call);
    if (surprisedBySpawnId != 0) {
        core.lastSurprisedTime = core.currentTime;
    }
    return eventVoid();
}

// Retail symbol: ?Event_AddAggression@idAI2@@QAA?AVeventVoid@@PBVidEntity@@MM@Z
// EA: 0x82A378A0, RVA: 0x00A378A0
eventVoid idAI2::Event_AddAggression(const idEntity* const entity,
        const float aggression, const float duration) {
    core.aggressionEntity = entity;
    core.aggressionAmount = aggression;
    core.aggressionEndTime = duration < 0.0f
        ? -1 : core.currentTime + static_cast<int>(duration * 1000.0f);
    idAI2EventCall call("Event_AddAggression");
    call.inputs[0] = entity;
    call.scalars[0] = aggression;
    call.scalars[1] = duration;
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?Event_AnimWeb_StartUseTurret@idAI2@@QAA?AVeventVoid@@HHHH@Z
// EA: 0x82A379A0, RVA: 0x00A379A0
eventVoid idAI2::Event_AnimWeb_StartUseTurret(const int webHandle,
        const int subWebIndex, const int stateIndex,
        const int eventParameter) {
    idAI2EventCall call("Event_AnimWeb_StartUseTurret");
    PackAnimWebEvent(call, webHandle, subWebIndex,
        stateIndex, eventParameter);
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?Event_ActionNode@idAI2@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA: 0x82A37AB8, RVA: 0x00A37AB8
eventVoid idAI2::Event_ActionNode(idEntity* const actionNode) {
    core.currentActionEntity = actionNode;
    idAI2EventCall call("Event_ActionNode");
    call.inputs[0] = actionNode;
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?Event_Touch@idAI2@@QAA?AVeventVoid@@PBVidEntity@@H@Z
// EA: 0x82A37B90, RVA: 0x00A37B90
eventVoid idAI2::Event_Touch(const idEntity* const other,
        const int clipModelId) {
    idAI2EventCall call("Event_Touch");
    call.inputs[0] = other;
    call.integers[0] = clipModelId;
    DispatchEvent(*this, call);
    return eventVoid();
}

// Retail symbol: ?Event_SetInteractionEntity@idAI2@@QAA?AVeventVoid@@PBVidEntity@@@Z
// EA: 0x82A37C18, RVA: 0x00A37C18
eventVoid idAI2::Event_SetInteractionEntity(
        const idEntity* const entity) {
    core.interactionEntity = entity;
    return eventVoid();
}

// Retail symbol: ?Event_BeginWaitForPlayerInteraction@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A37C98, RVA: 0x00A37C98
eventVoid idAI2::Event_BeginWaitForPlayerInteraction() {
    core.playerTriggeredInteraction = nullptr;
    core.waitForPlayerInteraction = true;
    return eventVoid();
}

// Retail symbol: ?Event_GetCurrentPlayerInteractionIndex@idAI2@@QAA?AVeventInt@@PAVidPlayer@@@Z
// EA: 0x82A37CC0, RVA: 0x00A37CC0
eventInt idAI2::Event_GetCurrentPlayerInteractionIndex(
        idPlayer* const player) {
    idAI2EventCall call("Event_GetCurrentPlayerInteractionIndex");
    call.inputs[0] = player;
    call.intResult = core.currentPlayerInteractionIndex;
    DispatchEvent(*this, call);
    core.currentPlayerInteractionIndex = call.intResult;
    return eventInt(call.intResult);
}
