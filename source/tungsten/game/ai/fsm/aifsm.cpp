#include "aifsm.h"
#include "../vehicleai/vehiclefsm.h"

// Retail symbol:
// ?Evaluate@Shared_UnhandledError@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA: 0x82AB1080, RVA: 0x00AB1080
idAIStateTransition::aiTransCode_t Shared_UnhandledError::Evaluate(
        idAI2*, idAIFSM*, idAIState* const state, int) {
    if (state == nullptr || state->GetChildFSM() == nullptr) {
        return 0;
    }
    return Tungsten_AIFSMHadError(*state->GetChildFSM())
        ? AIFSM_TRANSCODE_UNHANDLED_ERROR : 0;
}

// Retail symbol:
// ?Evaluate@idStateTransition_StateError@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA: 0x82AB10C8, RVA: 0x00AB10C8
idAIStateTransition::aiTransCode_t idStateTransition_StateError::Evaluate(
        idAI2*, idAIFSM* const parentFSM, idAIState*, int) {
    return parentFSM != nullptr && Tungsten_AIFSMHadError(*parentFSM)
        ? AIFSM_TRANSCODE_STATE_ERROR : 0;
}

// Retail symbol: ?GetAI@idAIFSM@@QBAPAVidAI2@@XZ
// EA: 0x82AB1100, RVA: 0x00AB1100
idAI2* idAIFSM::GetAI() const {
    return Tungsten_GetAIFSMOwner(
        const_cast<idAIFSM&>(*this));
}

// Retail symbol: ?AppendDefaultTransitions@idAIFSM@@UAAXPAVidState@@@Z
// EA: 0x82AB1108, RVA: 0x00AB1108
void idAIFSM::AppendDefaultTransitions(idState* const state) {
    if (state == nullptr || state == GetErrorState()
            || state == GetDoneState()) {
        return;
    }

    idState* const errorState = GetErrorState();
    Tungsten_AddAIFSMDefaultTransition(*state, *this,
        AIFSM_DEFAULT_UNHANDLED_CHILD_ERROR, errorState);
    Tungsten_AddAIFSMDefaultTransition(*state, *this,
        AIFSM_DEFAULT_STATE_ERROR, errorState);
}

// Retail symbol:
// ?Evaluate@Shared_CanUse@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA: 0x82AB1190, RVA: 0x00AB1190
idAIStateTransition::aiTransCode_t Shared_CanUse::Evaluate(
        idAI2*, idAIFSM*, idAIState*, int) {
    return AIFSM_TRANSCODE_SUCCESS;
}

// Retail symbol:
// ?Evaluate@Shared_DefaultUse@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA: 0x82AB1198, RVA: 0x00AB1198
idAIStateTransition::aiTransCode_t Shared_DefaultUse::Evaluate(
        idAI2*, idAIFSM*, idAIState*, int) {
    return AIFSM_TRANSCODE_DEFAULT_USE;
}

// Retail symbol:
// ?Evaluate@Shared_ChildFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA: 0x82AB11A0, RVA: 0x00AB11A0
idAIStateTransition::aiTransCode_t Shared_ChildFinished::Evaluate(
        idAI2*, idAIFSM*, idAIState* const state, int) {
    return state != nullptr && Tungsten_IsAIStateChildDone(*state)
        ? AIFSM_TRANSCODE_SUCCESS : 0;
}

// Retail symbol:
// ?Evaluate@Shared_MoveDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA: 0x82AB11D8, RVA: 0x00AB11D8
idAIStateTransition::aiTransCode_t Shared_MoveDone::Evaluate(
        idAI2* const ai, idAIFSM*, idAIState*, int) {
    return ai != nullptr && Tungsten_IsAIMoveDone(*ai, false)
        ? AIFSM_TRANSCODE_SUCCESS : 0;
}

// Retail symbol: ?InitStates@idAIFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA: 0x82AB1218, RVA: 0x00AB1218
void idAIFSM::InitStates(const idFiniteStateMachineParams* const params) {
    Tungsten_InitAIFSMBase(*this, params);
    Tungsten_AddAIFSMState(*this, Tungsten_GetGlobalAIErrorState());
    Tungsten_AddAIFSMState(*this, Tungsten_GetGlobalAIDoneState());
}

// Retail symbol: ?GetDoneState@idVehicleBaseFSM@@UBAPAVidState@@XZ
// EA: 0x82AB1298, RVA: 0x00AB1298
idState* idVehicleBaseFSM::GetDoneState() {
    return Tungsten_GetGlobalAIDoneState();
}

// Retail symbol:
// ?InternalCallEvent@idAIFSM@@MAA?AVidEventArg@@ABVidEventDef@@PBV2@@Z
// EA: 0x82AB12B0, RVA: 0x00AB12B0
idEventArg* idAIFSM::InternalCallEvent(idEventArg* const result,
        const idEventDef* const event, const idEventArg* const args) {
    if (event == nullptr || event->type != EVENT_ACTION) {
        return Tungsten_CallBaseFSMEvent(*this, result, event, args);
    }

    idState* const callerState = actionCallerState;
    idAI2* const ai = GetAI();
    idAIActionManager* const manager = ai != nullptr
        ? Tungsten_GetAIActionManager(*ai) : nullptr;
    if (callerState == nullptr || manager == nullptr
            || !Tungsten_AIActionManagerHandlesEvent(*manager, *event)) {
        actionCallerState = nullptr;
        Tungsten_ClearAIFSMEventArg(result);
        return result;
    }

    Tungsten_SetAIActionEventTransitionCode(
        *manager, AIFSM_TRANSCODE_START_ACTION);
    Tungsten_ProcessAIActionEvent(*manager, result, *event, args);

    idFiniteStateMachine* const legsFSM =
        Tungsten_GetAIActionLegsFSM(*manager);
    idFiniteStateMachine* const previousChild = callerState->childFSM;
    if (previousChild != nullptr && previousChild != legsFSM) {
        Tungsten_ExitAIChildStates(*previousChild, *this,
            Tungsten_GetAIFSMScaledGameMilliseconds());
    }
    Tungsten_SetAIStateChildFSM(*callerState, *this, legsFSM);
    actionCallerState = nullptr;
    return result;
}

// Retail symbol: ?InternalRespondsTo@idAIFSM@@MBA_NABVidEventDef@@@Z
// EA: 0x82AB13E0, RVA: 0x00AB13E0
bool idAIFSM::InternalRespondsTo(const idEventDef* const event) {
    if (event == nullptr || event->type != EVENT_ACTION) {
        return Tungsten_BaseFSMRespondsTo(*this, event);
    }
    if (actionCallerState == nullptr) {
        return false;
    }

    idAI2* const ai = GetAI();
    idAIActionManager* const manager = ai != nullptr
        ? Tungsten_GetAIActionManager(*ai) : nullptr;
    return manager != nullptr
        && Tungsten_AIActionManagerHandlesEvent(*manager, *event);
}

// Retail symbol:
// ?Evaluate@Shared_WorkTransCode@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA: 0x82AB1470, RVA: 0x00AB1470
idAIStateTransition::aiTransCode_t Shared_WorkTransCode::Evaluate(
        idAI2*, idAIFSM* const parentFSM, idAIState*, int) {
    return parentFSM != nullptr ? parentFSM->lastWorkTransCode : 0;
}

// Retail symbol:
// ?Evaluate@Shared_FSMEventTransCode@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA: 0x82AB1478, RVA: 0x00AB1478
idAIStateTransition::aiTransCode_t Shared_FSMEventTransCode::Evaluate(
        idAI2*, idAIFSM* const parentFSM, idAIState*, int) {
    return parentFSM != nullptr ? parentFSM->lastFSMEventTransCode : 0;
}
