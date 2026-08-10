#pragma once

#include "aifsm.h"

class idEntity;
class idPlayer;

enum idIdleTrackFriendlyTransitionKind : int {
    ITF_TRANSITION_NO_TARGET = 0,
    ITF_TRANSITION_TRACK,
    ITF_TRANSITION_PLAYER_APPROACHING,
    ITF_TRANSITION_END_TRACK,
    ITF_TRANSITION_FINISHED
};

enum idIdleTrackFriendlyDestination : int {
    ITF_DESTINATION_DONE = 0,
    ITF_DESTINATION_TRACK,
    ITF_DESTINATION_END_TRACK
};

static constexpr int TRANSCODE_ITF_TRACK = 0x1BC;
static constexpr int TRANSCODE_ITF_NO_TARGET = 0x1BD;
static constexpr int TRANSCODE_ITF_ENDTRACK = 0x1BE;
static constexpr int TRANSCODE_ITF_FINISHED = 0x1BF;
static constexpr int TRANSCODE_ITF_PLAYER_APPROACHING = 0x1C0;
static constexpr int ITF_PLAYER_APPROACH_EVENT_ID = 0x200000;
static constexpr unsigned int ITF_INVALID_TARGET_SPAWN_ID = 0x1FFF;
static constexpr short ITF_INVALID_ANIM_STATE = -1;
static constexpr int ITF_AIMPOINT_HEAD = 1;

// Header-defined retail no-op/default state methods are represented once here;
// the nontrivial out-of-line state routines remain on their concrete classes.
class idIdleTrackFriendlyStateBase : public idAIState {
public:
    bool AIState_CanUse(idAI2*, idAIFSM*, int) override { return true; }
    void AIState_EnterState(idAI2*, idAIFSM*, int) override {}
    void AIState_ExitState(idAI2*, idAIFSM*, int) override {}
    void AIState_Work(idAI2*, idAIFSM*, int) override {}
    void AIState_ReenterState(idAI2*, idAIFSM*, int, int) override {}
    bool AIState_IsWaiting(idAI2*, idAIFSM*, int) override { return false; }
};

class idIdleTrackFriendly_Default : public idIdleTrackFriendlyStateBase {
public:
    void InternalInitState(const idFiniteStateMachine* fsm);
    void AIState_EnterState(idAI2* ai, idAIFSM* fsm,
        int currentTime) override;
};

class idIdleTrackFriendly_Track : public idIdleTrackFriendlyStateBase {
public:
    void InternalInitState(const idFiniteStateMachine* fsm);
    void AIState_Work(idAI2* ai, idAIFSM* fsm,
        int currentTime) override;
};

class idIdleTrackFriendly_EndTrack : public idIdleTrackFriendlyStateBase {
public:
    void InternalInitState(const idFiniteStateMachine* fsm);
    void AIState_EnterState(idAI2* ai, idAIFSM* fsm,
        int currentTime) override;
};

class idIdleTrackFriendlyFSM : public idAIFSM {
public:
    idIdleTrackFriendlyFSM();
    ~idIdleTrackFriendlyFSM() override;

    void InitStates(const idFiniteStateMachineParams* params) override;

    idIdleTrackFriendly_Default stateDefault;
    idIdleTrackFriendly_Track stateTrack;
    idIdleTrackFriendly_EndTrack stateEndTrack;
    unsigned int targetSpawnId;
    short idleStateIndex;
    short startStateIndex;
    bool oldEnableHeadTracking;
    bool oldEnableAutoFocus;
};

class ITF_Finished : public idAIFSMTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2*, idAIFSM*, idAIState*, int) override;
};
class ITF_PlayerApproaching : public idAIFSMTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2*, idAIFSM*, idAIState*, int) override;
};
class ITF_NoTarget : public idAIFSMTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2*, idAIFSM*, idAIState*, int) override;
};
class ITF_Track : public idAIFSMTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2*, idAIFSM*, idAIState*, int) override;
};
class ITF_EndTrack : public idAIFSMTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2*, idAIFSM*, idAIState*, int) override;
};

// Runtime boundaries for generated transition RTTI, entity spawn tables,
// animation-web state lookup, AI focus flags, and player-interaction policy.
void Tungsten_AddIdleTrackFriendlyTransition(idAIState& state,
    const idFiniteStateMachine& fsm, bool eventTransition,
    idIdleTrackFriendlyTransitionKind transition,
    idIdleTrackFriendlyDestination destination);
void Tungsten_InitIdleTrackFriendlyFSMRuntime(idIdleTrackFriendlyFSM& fsm,
    const char* name);
void Tungsten_SetIdleTrackFriendlyDefaultState(idIdleTrackFriendlyFSM& fsm,
    idAIState& state);
bool Tungsten_GetIdleTrackHeadTracking(const idAI2& ai);
bool Tungsten_GetIdleTrackAutoFocus(const idAI2& ai);
void Tungsten_SetIdleTrackOverride(idAI2& ai, bool enabled);
short Tungsten_GetIdleTrackCurrentAnimState(const idAI2& ai);
short Tungsten_GetIdleTrackIdleAnimState(const idAI2& ai);
const idEntity* Tungsten_ResolveIdleTrackTarget(unsigned int spawnId);
bool Tungsten_GetIdleTrackSphereOriginator(const void* eventData,
    unsigned int& spawnId);
const idPlayer* Tungsten_ResolveIdleTrackPlayer(unsigned int spawnId);
bool Tungsten_IdleTrackPlayerApproaching(const idAI2& ai,
    const idPlayer* player);
bool Tungsten_CanIdleTrackFriendlyTarget(const idAI2& ai,
    const idEntity* target);
void Tungsten_SetIdleTrackHeadTracking(idAI2& ai, bool enabled);
void Tungsten_SetIdleTrackAutoFocus(idAI2& ai, bool enabled);
void Tungsten_SetIdleTrackLookFocus(idAI2& ai, const idEntity* target,
    bool keepFocusInView, int aimPoint, int timeout);
void Tungsten_ClearIdleTrackLookFocus(idAI2& ai);
