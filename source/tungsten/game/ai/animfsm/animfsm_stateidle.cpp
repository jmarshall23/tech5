#include "animfsm_stateidle.h"

#include <cmath>

namespace {

bool DirectionRequiresTurn(idVec3 direction, idVec3 up,
        idVec3 forward, const float maximumAngleRadians) {
    if (up.NormalizeFast() == 0.0f) {
        up.Set(0.0f, 0.0f, 1.0f);
    }
    direction = direction - up * direction.Dot(up);
    forward = forward - up * forward.Dot(up);
    if (direction.NormalizeFast() == 0.0f
        || forward.NormalizeFast() == 0.0f) {
        return false;
    }
    return forward.Dot(direction) < std::cos(maximumAngleRadians);
}

} // namespace

// Retail symbol:
// ?Enter@idAnimStateIdleGround@@UAAXPAVidAI2@@PAVidAnimBaseFSM@@@Z
// EA: 0x82A7F198, RVA: 0x00A7F198
void idAnimStateIdleGround::Enter(idAI2*, idAnimBaseFSM* const fsm) {
    if (fsm != nullptr) {
        Tungsten_ClearAnimFSMDestination(*fsm);
    }
    subState = 0;
}

// Retail symbol: ??0idAnimStateIdleGround@@QAA@XZ
// EA: 0x82A7F1E0, RVA: 0x00A7F1E0
idAnimStateIdleGround::idAnimStateIdleGround()
    : idAIStateLite() {
    subState = 0;
}

// Retail symbol:
// ?Exit@idAnimStateIdleGround@@UAAXPAVidAI2@@PAVidAnimBaseFSM@@@Z
// EA: 0x82A7F260, RVA: 0x00A7F260
void idAnimStateIdleGround::Exit(idAI2*, idAnimBaseFSM* const fsm) {
    if (fsm != nullptr) {
        Tungsten_SetAnimFSMStompMoveOrientation(*fsm, true);
    }
}

// Retail symbol:
// ?CheckForStationaryTurn@idAnimStateIdleGround@@IAA_NPAVidAI2@@PAVidAnimBaseFSM@@@Z
// EA: 0x82A7F2E0, RVA: 0x00A7F2E0
bool idAnimStateIdleGround::CheckForStationaryTurn(
        idAI2* const ai, idAnimBaseFSM* const fsm) {
    if (ai == nullptr || fsm == nullptr) {
        return false;
    }
    idStationaryTurnRuntime runtime;
    if (!Tungsten_GetStationaryTurnRuntime(*ai, *fsm, runtime)
        || !runtime.overrideAllowsTurn || !runtime.validTurnType
        || !runtime.turnToFocus || !runtime.allowTurns
        || runtime.suppressBodyRotation || !runtime.bodyRotationEnabled
        || !runtime.postureAllowed || !runtime.hasFocus
        || runtime.duckRunIndex) {
        return false;
    }
    if (!DirectionRequiresTurn(runtime.focusDirection, runtime.bodyUp,
            runtime.bodyForward, runtime.maximumAngleRadians)
        || !runtime.transitionAvailable) {
        return false;
    }

    idVec3 desiredDirection = runtime.focusDirection;
    if (runtime.predictTurns && runtime.hasPredictionTarget) {
        if (!DirectionRequiresTurn(runtime.predictedFocusDirection,
                runtime.bodyUp, runtime.bodyForward,
                runtime.maximumAngleRadians)
            || !runtime.predictedTransitionAvailable) {
            return false;
        }
        desiredDirection = runtime.predictedFocusDirection;
    }
    desiredDirection = desiredDirection
        - runtime.bodyUp * desiredDirection.Dot(runtime.bodyUp);
    desiredDirection.NormalizeFast();
    Tungsten_StartStationaryTurn(
        *ai, *fsm, desiredDirection, runtime.selectionIndex);
    return true;
}

// Retail symbol:
// ?Work@idAnimStateIdleGround@@UAAHPAVidAI2@@PAVidAnimBaseFSM@@@Z
// EA: 0x82A7F848, RVA: 0x00A7F848
int idAnimStateIdleGround::Work(
        idAI2* const ai, idAnimBaseFSM* const fsm) {
    if (ai == nullptr || fsm == nullptr) {
        return 1;
    }
    idIdleAnimWorkRuntime runtime;
    if (!Tungsten_GetIdleAnimWorkRuntime(*ai, *fsm, runtime)) {
        return 1;
    }
    if (runtime.hasActiveMove && !runtime.moveDone) {
        return 5;
    }
    if (runtime.enableIdlePump
        && !CheckForStationaryTurn(ai, fsm)
        && !runtime.destinationMatchesIdle) {
        Tungsten_TransitionAnimFSMToIdle(*ai, *fsm);
    }
    return 1;
}
