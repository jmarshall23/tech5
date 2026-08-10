#pragma once

#include "statetransition.h"

class idAI2;
class idAIFSM;
class idAIState;
class idFiniteStateMachine;
class idTypeInfo;

class idState {
public:
    idState() : childFSM(nullptr) {}
    virtual ~idState() = default;

    idFiniteStateMachine* childFSM;
};

// AI-specialized transition base. The first Evaluate overload is the generic
// FSM entry point; it resolves the AI owner and dispatches to the typed
// transition implementation exactly as the retail adapter did.
class idAIStateTransition : public idStateTransition {
public:
    using aiTransCode_t = int;
    static constexpr aiTransCode_t TRANSCODE_START_ACTION = 0x7;
    static constexpr aiTransCode_t TRANSCODE_MOVE_FAILED = 0x9;

    explicit idAIStateTransition(int transitionFlags = 0)
        : idStateTransition(transitionFlags) {}

    int Evaluate(idFiniteStateMachine* parentFSM, idState* state,
        int currentTime) override;
    virtual aiTransCode_t Evaluate(idAI2* ai, idAIFSM* parentFSM,
        idAIState* state, int currentTime) = 0;

    static const char* NameForTransitionCode(aiTransCode_t transitionCode);
};

// Static transitions serialize their already-resolved destination table.
// Concrete generated transitions still provide GetType and typed Evaluate.
class idAIStateTransitionStatic : public idAIStateTransition {
public:
    explicit idAIStateTransitionStatic(int transitionFlags = 0)
        : idAIStateTransition(transitionFlags) {}

    void InternalSave(idFile_String& file, const char* indent,
        const idList<transDest_t, 5>& destinations) override;
};

// Source-facing AI state adapter. The general idState storage is recovered in
// state.cpp; this class retains the child-FSM link used by the two queue
// helpers so the recovered behavior is directly executable in isolation.
class idAIState : public idState {
public:
    idAIState() = default;
    virtual ~idAIState() = default;

    virtual bool AIState_CanUse(idAI2* ai, idAIFSM* parentFSM,
        int currentTime) = 0;
    virtual void AIState_EnterState(idAI2* ai, idAIFSM* parentFSM,
        int currentTime) = 0;
    virtual void AIState_ExitState(idAI2* ai, idAIFSM* parentFSM,
        int currentTime) = 0;
    virtual void AIState_Work(idAI2* ai, idAIFSM* parentFSM,
        int currentTime) = 0;
    virtual void AIState_ReenterState(idAI2* ai, idAIFSM* parentFSM,
        int transitionCode, int currentTime) = 0;
    virtual bool AIState_IsWaiting(idAI2* ai, idAIFSM* parentFSM,
        int currentTime) = 0;

    virtual bool InternalCanUse(idFiniteStateMachine* fsm,
        int currentTime);
    virtual void InternalEnterState(idFiniteStateMachine* fsm,
        int currentTime);
    virtual void InternalExitState(idFiniteStateMachine* fsm,
        int currentTime);
    virtual void InternalWork(idFiniteStateMachine* fsm,
        int currentTime);
    virtual void InternalReenterState(idFiniteStateMachine* fsm,
        int transitionCode, int currentTime);
    virtual bool InternalIsStateWaiting(idFiniteStateMachine* fsm,
        int currentTime);

    void StartQueuedActions(idAI2* ai, idAIFSM* parentFSM,
        int currentTime);
    void ClearQueuedActions(idAI2* ai, idAIFSM* parentFSM,
        int currentTime);

    idFiniteStateMachine* GetChildFSM() const { return childFSM; }
};

// Runtime boundary for the still-unrecovered central FSM, reflection, and
// embedded action-manager layouts.
idAI2* Tungsten_GetAIFSMOwner(idFiniteStateMachine& fsm);
const char* Tungsten_GetAITransitionCodeName(int transitionCode);
const char* Tungsten_GetAIStateTypeClassname(const idTypeInfo* type);
void Tungsten_AppendAIStateText(idFile_String& file, const char* text);
idFiniteStateMachine* Tungsten_GetAILegsActionFSM(idAI2& ai);
void Tungsten_StartAILegsQueuedActions(idFiniteStateMachine& legsFSM);
void Tungsten_ClearAILegsQueuedActions(idFiniteStateMachine& legsFSM);
void Tungsten_ExitAIChildStates(idFiniteStateMachine& childFSM,
    idAIFSM& parentFSM, int currentTime);
void Tungsten_SetAIStateChildFSM(idState& state,
    idAIFSM& parentFSM, idFiniteStateMachine* childFSM);
