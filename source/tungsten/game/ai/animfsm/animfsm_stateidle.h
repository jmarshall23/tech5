#pragma once

#include "animfsm_state_core.h"
#include "idlib/math/vector.h"

class idAI2;
class idAnimBaseFSM;

struct idStationaryTurnRuntime {
    bool overrideAllowsTurn = false;
    bool validTurnType = false;
    bool turnToFocus = false;
    bool allowTurns = false;
    bool suppressBodyRotation = false;
    bool bodyRotationEnabled = false;
    bool postureAllowed = false;
    bool hasFocus = false;
    bool duckRunIndex = false;
    bool transitionAvailable = false;
    bool predictTurns = false;
    bool hasPredictionTarget = false;
    bool predictedTransitionAvailable = false;
    float maximumAngleRadians = 0.0f;
    int selectionIndex = 0;
    idVec3 bodyForward;
    idVec3 bodyUp;
    idVec3 focusDirection;
    idVec3 predictedFocusDirection;
};

struct idIdleAnimWorkRuntime {
    bool hasActiveMove = false;
    bool moveDone = true;
    bool enableIdlePump = false;
    bool destinationMatchesIdle = true;
};

class idAnimStateIdleGround : public idAIStateLite {
public:
    idAnimStateIdleGround();
    ~idAnimStateIdleGround() override = default;

    virtual void Enter(idAI2* ai, idAnimBaseFSM* fsm);
    virtual void Exit(idAI2* ai, idAnimBaseFSM* fsm);
    virtual int Work(idAI2* ai, idAnimBaseFSM* fsm);

protected:
    bool CheckForStationaryTurn(idAI2* ai, idAnimBaseFSM* fsm);
};

void Tungsten_ClearAnimFSMDestination(idAnimBaseFSM& fsm);
void Tungsten_SetAnimFSMStompMoveOrientation(
    idAnimBaseFSM& fsm, bool enabled);
bool Tungsten_GetStationaryTurnRuntime(const idAI2& ai,
    const idAnimBaseFSM& fsm, idStationaryTurnRuntime& runtime);
void Tungsten_StartStationaryTurn(idAI2& ai, idAnimBaseFSM& fsm,
    const idVec3& desiredDirection, int selectionIndex);
bool Tungsten_GetIdleAnimWorkRuntime(const idAI2& ai,
    const idAnimBaseFSM& fsm, idIdleAnimWorkRuntime& runtime);
void Tungsten_TransitionAnimFSMToIdle(idAI2& ai, idAnimBaseFSM& fsm);
