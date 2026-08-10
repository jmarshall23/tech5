#pragma once

#include "aistate.h"
#include "game/gamesys/eventarg.h"
#include "game/gamesys/eventdef.h"

class idAIActionManager;
class idFSMManager;
class idVehicleBaseFSM;

// The central finite-state-machine implementation is recovered separately.
// This source-facing base retains the fields and virtual queries used by the
// AI specialization without depending on the unsafe generated header.
class idFiniteStateMachine {
public:
    enum fsmStatus_t : int {
        FSMSTATUS_DONE = 0,
        FSMSTATUS_WORKING = 1,
        FSMSTATUS_ERROR = 2
    };

    idFiniteStateMachine()
        : actionCallerState(nullptr)
        , lastWorkTransCode(0)
        , lastFSMEventTransCode(0)
        , eventId(0)
        , eventData(nullptr)
        , curState(nullptr) {}
    virtual ~idFiniteStateMachine() = default;

    virtual idState* GetErrorState() { return nullptr; }
    virtual idState* GetDoneState() { return nullptr; }

    idState* actionCallerState;
    int lastWorkTransCode;
    int lastFSMEventTransCode;
    int eventId;
    const void* eventData;
    idState* curState;
};

class idFiniteStateMachineParams {
public:
    idFSMManager* manager = nullptr;
};

enum idAIFSMDefaultTransitionKind : int {
    AIFSM_DEFAULT_UNHANDLED_CHILD_ERROR = 0,
    AIFSM_DEFAULT_STATE_ERROR = 1
};

class idAIFSM : public idFiniteStateMachine {
public:
    idAI2* GetAI() const;
    virtual void AppendDefaultTransitions(idState* state);
    virtual void InitStates(const idFiniteStateMachineParams* params);
    virtual idEventArg* InternalCallEvent(idEventArg* result,
        const idEventDef* event, const idEventArg* args);
    virtual bool InternalRespondsTo(const idEventDef* event);
};

// Generated reflection supplies the retail transition vtables.  This common
// source-facing base supplies only the two non-behavioral abstract methods so
// each recovered Evaluate routine can be exercised independently.
class idAIFSMTransitionBase : public idAIStateTransition {
public:
    idAIFSMTransitionBase() : idAIStateTransition(0) {}

    idTypeInfo* GetType() override { return nullptr; }
    void InternalSave(idFile_String&, const char*,
        const idList<transDest_t, 5>&) override {}
};

class Shared_UnhandledError : public idAIFSMTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2*, idAIFSM*, idAIState* state,
        int currentTime) override;
};

class idStateTransition_StateError : public idAIFSMTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2*, idAIFSM* parentFSM, idAIState*,
        int currentTime) override;
};

class Shared_CanUse : public idAIFSMTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2*, idAIFSM*, idAIState*, int) override;
};

class Shared_DefaultUse : public idAIFSMTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2*, idAIFSM*, idAIState*, int) override;
};

class Shared_ChildFinished : public idAIFSMTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2*, idAIFSM*, idAIState* state,
        int currentTime) override;
};

class Shared_MoveDone : public idAIFSMTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2* ai, idAIFSM*, idAIState*,
        int currentTime) override;
};

class Shared_WorkTransCode : public idAIFSMTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2*, idAIFSM* parentFSM, idAIState*,
        int currentTime) override;
};

class Shared_FSMEventTransCode : public idAIFSMTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2*, idAIFSM* parentFSM, idAIState*,
        int currentTime) override;
};

static constexpr int AIFSM_TRANSCODE_UNHANDLED_ERROR = 3;
static constexpr int AIFSM_TRANSCODE_STATE_ERROR = 4;
static constexpr int AIFSM_TRANSCODE_START_ACTION = 7;
static constexpr int AIFSM_TRANSCODE_DEFAULT_USE = 451;
static constexpr int AIFSM_TRANSCODE_SUCCESS = 452;

// Runtime boundaries for layouts owned by the central FSM, AI action manager,
// game-local singleton, and generated reflection translation units.
bool Tungsten_AIFSMHadError(const idFiniteStateMachine& fsm);
bool Tungsten_IsAIStateChildDone(const idAIState& state);
bool Tungsten_IsAIMoveDone(const idAI2& ai, bool checkAlignment);
void Tungsten_AddAIFSMDefaultTransition(idState& state, idAIFSM& fsm,
    idAIFSMDefaultTransitionKind kind, idState* destination);
void Tungsten_InitAIFSMBase(idAIFSM& fsm,
    const idFiniteStateMachineParams* params);
idState* Tungsten_GetGlobalAIErrorState();
idState* Tungsten_GetGlobalAIDoneState();
void Tungsten_AddAIFSMState(idAIFSM& fsm, idState* state);

idAIActionManager* Tungsten_GetAIActionManager(idAI2& ai);
bool Tungsten_AIActionManagerHandlesEvent(idAIActionManager& manager,
    const idEventDef& event);
void Tungsten_SetAIActionEventTransitionCode(idAIActionManager& manager,
    int transitionCode);
void Tungsten_ProcessAIActionEvent(idAIActionManager& manager,
    idEventArg* result, const idEventDef& event, const idEventArg* args);
idFiniteStateMachine* Tungsten_GetAIActionLegsFSM(
    idAIActionManager& manager);
int Tungsten_GetAIFSMScaledGameMilliseconds();
void Tungsten_ClearAIFSMEventArg(idEventArg* result);
idEventArg* Tungsten_CallBaseFSMEvent(idFiniteStateMachine& fsm,
    idEventArg* result, const idEventDef* event, const idEventArg* args);
bool Tungsten_BaseFSMRespondsTo(const idFiniteStateMachine& fsm,
    const idEventDef* event);
