#include "fsm_idletrackfriendly.h"

namespace {

idIdleTrackFriendlyFSM* AsIdleTrackFriendlyFSM(idAIFSM* const fsm) {
    return static_cast<idIdleTrackFriendlyFSM*>(fsm);
}

const idIdleTrackFriendlyFSM* AsIdleTrackFriendlyFSM(
        const idAIFSM* const fsm) {
    return static_cast<const idIdleTrackFriendlyFSM*>(fsm);
}

} // namespace

// Retail symbol:
// ?InternalInitState@idIdleTrackFriendly_Default@@UAAXPBVidFiniteStateMachine@@@Z
// EA: 0x82AD4360, RVA: 0x00AD4360
void idIdleTrackFriendly_Default::InternalInitState(
        const idFiniteStateMachine* const fsm) {
    if (fsm == nullptr) {
        return;
    }
    Tungsten_AddIdleTrackFriendlyTransition(*this, *fsm, false,
        ITF_TRANSITION_NO_TARGET, ITF_DESTINATION_DONE);
    Tungsten_AddIdleTrackFriendlyTransition(*this, *fsm, false,
        ITF_TRANSITION_TRACK, ITF_DESTINATION_TRACK);
    Tungsten_AddIdleTrackFriendlyTransition(*this, *fsm, true,
        ITF_TRANSITION_PLAYER_APPROACHING, ITF_DESTINATION_END_TRACK);
}

// Retail symbol:
// ?InternalInitState@idIdleTrackFriendly_Track@@UAAXPBVidFiniteStateMachine@@@Z
// EA: 0x82AD43E0, RVA: 0x00AD43E0
void idIdleTrackFriendly_Track::InternalInitState(
        const idFiniteStateMachine* const fsm) {
    if (fsm == nullptr) {
        return;
    }
    Tungsten_AddIdleTrackFriendlyTransition(*this, *fsm, false,
        ITF_TRANSITION_END_TRACK, ITF_DESTINATION_END_TRACK);
    Tungsten_AddIdleTrackFriendlyTransition(*this, *fsm, true,
        ITF_TRANSITION_PLAYER_APPROACHING, ITF_DESTINATION_END_TRACK);
}

// Retail symbol:
// ?Evaluate@ITF_Finished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA: 0x82AD4430, RVA: 0x00AD4430
idAIStateTransition::aiTransCode_t ITF_Finished::Evaluate(
        idAI2*, idAIFSM*, idAIState*, int) {
    return TRANSCODE_ITF_FINISHED;
}

// Retail symbol:
// ?InternalInitState@idIdleTrackFriendly_EndTrack@@UAAXPBVidFiniteStateMachine@@@Z
// EA: 0x82AD4438, RVA: 0x00AD4438
void idIdleTrackFriendly_EndTrack::InternalInitState(
        const idFiniteStateMachine* const fsm) {
    if (fsm == nullptr) {
        return;
    }
    Tungsten_AddIdleTrackFriendlyTransition(*this, *fsm, false,
        ITF_TRANSITION_FINISHED, ITF_DESTINATION_DONE);
}

// Retail symbol:
// ?InitStates@idIdleTrackFriendlyFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA: 0x82AD4450, RVA: 0x00AD4450
void idIdleTrackFriendlyFSM::InitStates(
        const idFiniteStateMachineParams* const params) {
    idAIFSM::InitStates(params);
    Tungsten_AddAIFSMState(*this, &stateDefault);
    Tungsten_AddAIFSMState(*this, &stateTrack);
    Tungsten_AddAIFSMState(*this, &stateEndTrack);
}

// Retail symbol: ??1idIdleTrackFriendlyFSM@@UAA@XZ
// EA: 0x82AD44D0, RVA: 0x00AD44D0
idIdleTrackFriendlyFSM::~idIdleTrackFriendlyFSM() = default;

// Retail symbol:
// ?AIState_EnterState@idIdleTrackFriendly_Default@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA: 0x82AD45C0, RVA: 0x00AD45C0
void idIdleTrackFriendly_Default::AIState_EnterState(
        idAI2* const ai, idAIFSM* const parentFSM, int) {
    if (ai == nullptr || parentFSM == nullptr) {
        return;
    }
    idIdleTrackFriendlyFSM& fsm = *AsIdleTrackFriendlyFSM(parentFSM);
    fsm.oldEnableHeadTracking = Tungsten_GetIdleTrackHeadTracking(*ai);
    fsm.oldEnableAutoFocus = Tungsten_GetIdleTrackAutoFocus(*ai);
    Tungsten_SetIdleTrackOverride(*ai, true);
    fsm.startStateIndex = Tungsten_GetIdleTrackCurrentAnimState(*ai);
    fsm.idleStateIndex = Tungsten_GetIdleTrackIdleAnimState(*ai);
}

// Retail symbol: ??0idIdleTrackFriendlyFSM@@QAA@XZ
// EA: 0x82AD46A8, RVA: 0x00AD46A8
idIdleTrackFriendlyFSM::idIdleTrackFriendlyFSM()
    : idAIFSM()
    , stateDefault()
    , stateTrack()
    , stateEndTrack()
    , targetSpawnId(ITF_INVALID_TARGET_SPAWN_ID)
    , idleStateIndex(ITF_INVALID_ANIM_STATE)
    , startStateIndex(ITF_INVALID_ANIM_STATE)
    , oldEnableHeadTracking(false)
    , oldEnableAutoFocus(false) {
    Tungsten_InitIdleTrackFriendlyFSMRuntime(*this,
        "FSM_IdleTrackFriendly");
    Tungsten_SetIdleTrackFriendlyDefaultState(*this, stateDefault);
}

// Retail symbol:
// ?Evaluate@ITF_PlayerApproaching@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA: 0x82AD48A8, RVA: 0x00AD48A8
idAIStateTransition::aiTransCode_t ITF_PlayerApproaching::Evaluate(
        idAI2* const ai, idAIFSM* const parentFSM, idAIState*, int) {
    if (ai == nullptr || parentFSM == nullptr
            || parentFSM->eventId != ITF_PLAYER_APPROACH_EVENT_ID) {
        return 0;
    }

    unsigned int originatorSpawnId = ITF_INVALID_TARGET_SPAWN_ID;
    if (!Tungsten_GetIdleTrackSphereOriginator(
            parentFSM->eventData, originatorSpawnId)) {
        return 0;
    }
    const idPlayer* const player =
        Tungsten_ResolveIdleTrackPlayer(originatorSpawnId);
    return Tungsten_IdleTrackPlayerApproaching(*ai, player)
        ? TRANSCODE_ITF_PLAYER_APPROACHING : 0;
}

// Retail symbol:
// ?Evaluate@ITF_NoTarget@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA: 0x82AD4968, RVA: 0x00AD4968
idAIStateTransition::aiTransCode_t ITF_NoTarget::Evaluate(
        idAI2*, idAIFSM* const parentFSM, idAIState*, int) {
    if (parentFSM == nullptr) {
        return TRANSCODE_ITF_NO_TARGET;
    }
    const idIdleTrackFriendlyFSM& fsm =
        *AsIdleTrackFriendlyFSM(parentFSM);
    return Tungsten_ResolveIdleTrackTarget(fsm.targetSpawnId) == nullptr
        ? TRANSCODE_ITF_NO_TARGET : 0;
}

// Retail symbol:
// ?Evaluate@ITF_Track@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA: 0x82AD49E8, RVA: 0x00AD49E8
idAIStateTransition::aiTransCode_t ITF_Track::Evaluate(
        idAI2*, idAIFSM* const parentFSM, idAIState*, int) {
    if (parentFSM == nullptr) {
        return 0;
    }
    const idIdleTrackFriendlyFSM& fsm =
        *AsIdleTrackFriendlyFSM(parentFSM);
    return Tungsten_ResolveIdleTrackTarget(fsm.targetSpawnId) != nullptr
        ? TRANSCODE_ITF_TRACK : 0;
}

// Retail symbol:
// ?Evaluate@ITF_EndTrack@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA: 0x82AD4A58, RVA: 0x00AD4A58
idAIStateTransition::aiTransCode_t ITF_EndTrack::Evaluate(
        idAI2* const ai, idAIFSM* const parentFSM, idAIState*, int) {
    if (ai == nullptr || parentFSM == nullptr) {
        return TRANSCODE_ITF_ENDTRACK;
    }
    const idIdleTrackFriendlyFSM& fsm =
        *AsIdleTrackFriendlyFSM(parentFSM);
    const idEntity* const target =
        Tungsten_ResolveIdleTrackTarget(fsm.targetSpawnId);
    return Tungsten_CanIdleTrackFriendlyTarget(*ai, target)
        ? 0 : TRANSCODE_ITF_ENDTRACK;
}

// Retail symbol:
// ?AIState_Work@idIdleTrackFriendly_Track@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA: 0x82AD4AE8, RVA: 0x00AD4AE8
void idIdleTrackFriendly_Track::AIState_Work(
        idAI2* const ai, idAIFSM* const parentFSM, int) {
    if (ai == nullptr || parentFSM == nullptr) {
        return;
    }
    idIdleTrackFriendlyFSM& fsm = *AsIdleTrackFriendlyFSM(parentFSM);
    if (fsm.idleStateIndex == ITF_INVALID_ANIM_STATE) {
        return;
    }

    const short currentState = Tungsten_GetIdleTrackCurrentAnimState(*ai);
    if (currentState == fsm.startStateIndex
            && fsm.startStateIndex != fsm.idleStateIndex) {
        return;
    }

    fsm.idleStateIndex = ITF_INVALID_ANIM_STATE;
    Tungsten_SetIdleTrackHeadTracking(*ai, true);
    Tungsten_SetIdleTrackAutoFocus(*ai, false);
    const idEntity* const target =
        Tungsten_ResolveIdleTrackTarget(fsm.targetSpawnId);
    Tungsten_SetIdleTrackLookFocus(
        *ai, target, false, ITF_AIMPOINT_HEAD, -1);
}

// Retail symbol:
// ?AIState_EnterState@idIdleTrackFriendly_EndTrack@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA: 0x82AD4BE0, RVA: 0x00AD4BE0
void idIdleTrackFriendly_EndTrack::AIState_EnterState(
        idAI2* const ai, idAIFSM* const parentFSM, int) {
    if (ai == nullptr || parentFSM == nullptr) {
        return;
    }
    idIdleTrackFriendlyFSM& fsm = *AsIdleTrackFriendlyFSM(parentFSM);
    fsm.targetSpawnId = ITF_INVALID_TARGET_SPAWN_ID;
    Tungsten_SetIdleTrackHeadTracking(*ai, fsm.oldEnableHeadTracking);
    Tungsten_SetIdleTrackAutoFocus(*ai, fsm.oldEnableAutoFocus);
    Tungsten_SetIdleTrackOverride(*ai, false);
    Tungsten_ClearIdleTrackLookFocus(*ai);
}
