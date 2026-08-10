#pragma once

#include "aifsm.h"
#include "game/gametooldefs.h"
#include "idlib/math/vector.h"

enum aiDirection_t : int {
    AIDIR_FRONT = 0,
    AIDIR_FRONT_LEFT = 1,
    AIDIR_LEFT = 2,
    AIDIR_BEHIND_LEFT = 3,
    AIDIR_BEHIND = 4,
    AIDIR_BEHIND_RIGHT = 5,
    AIDIR_RIGHT = 6,
    AIDIR_FRONT_RIGHT = 7,
    AIDIR_MAX = 8
};

enum idMeleeTransitionCode : int {
    TRANSCODE_COMBAT_MELEE_DONE = 0x2A,
    TRANSCODE_MELEE_ATTACK = 0x15E,
    TRANSCODE_MELEE_REPOSITION = 0x15F,
    TRANSCODE_MELEE_ATTACK_DONE = 0x160,
    TRANSCODE_MELEE_TARGET_OUT_OF_RANGE = 0x161,
    TRANSCODE_MELEE_REPOSITION_DONE = 0x162,
    TRANSCODE_MELEE_REPOSITION_FAILED = 0x163,
    TRANSCODE_MELEE_NO_TARGET = 0x164
};

enum idMeleeStateKind : int {
    MELEE_STATE_DEFAULT = 0,
    MELEE_STATE_ATTACK = 1,
    MELEE_STATE_REPOSITION = 2,
    MELEE_STATE_DONE = 3
};

enum idMeleeTransitionKind : int {
    MELEE_TRANSITION_NO_TARGET = 0,
    MELEE_TRANSITION_TARGET_OUT_OF_RANGE = 1,
    MELEE_TRANSITION_REPOSITION = 2,
    MELEE_TRANSITION_ATTACK = 3,
    MELEE_TRANSITION_ATTACK_DONE = 4,
    MELEE_TRANSITION_REPOSITION_FAILED = 5,
    MELEE_TRANSITION_REPOSITION_DONE = 6
};

struct idMeleeBehaviorRuntime {
    bool meleeEnabled;
    int validCloseMeleeTypes;
    int nextDodgeTime;
    int nextCloseMeleeTime;
    int meleeDodgeChance;
    bool hasAngryRage;
    bool wantsAngryRage;
    int minimumCloseMeleeInterval;
    int maximumCloseMeleeInterval;
    int minimumMeleeDodgeInterval;
    int maximumMeleeDodgeInterval;
    int angryRageAfterMissingChance;
    bool crouching;
    idVec3 origin;
    idVec3 velocity;
};

struct idMeleeTargetRuntime {
    bool valid;
    bool dead;
    idVec3 origin;
    idVec3 velocity;
    aiDirection_t direction;
    int preferredMask;
    aiMelee_t selectedType;
    bool selectedTypeInRange;
    bool allTypesInRange;
};

class idMeleeStateBase : public idAIState {
public:
    explicit idMeleeStateBase(idMeleeStateKind stateKind);

    bool AIState_CanUse(idAI2*, idAIFSM*, int) override { return true; }
    void AIState_EnterState(idAI2*, idAIFSM*, int) override {}
    void AIState_ExitState(idAI2*, idAIFSM*, int) override {}
    void AIState_Work(idAI2*, idAIFSM*, int) override {}
    void AIState_ReenterState(idAI2*, idAIFSM*, int, int) override {}
    bool AIState_IsWaiting(idAI2*, idAIFSM*, int) override { return false; }

    idMeleeStateKind kind;
    bool enterFailed;
    unsigned char meleeStateOpaque[15];
};

class idMelee_Default : public idMeleeStateBase {
public:
    idMelee_Default() : idMeleeStateBase(MELEE_STATE_DEFAULT) {}
    void InternalInitState(const idFiniteStateMachine* fsm);
    void AIState_EnterState(idAI2* ai, idAIFSM*, int) override;
};

class idMelee_Attack : public idMeleeStateBase {
public:
    idMelee_Attack() : idMeleeStateBase(MELEE_STATE_ATTACK) {}
    void InternalInitState(const idFiniteStateMachine* fsm);
    void AIState_EnterState(idAI2* ai, idAIFSM* fsm, int currentTime) override;
};

class idMelee_Reposition : public idMeleeStateBase {
public:
    idMelee_Reposition() : idMeleeStateBase(MELEE_STATE_REPOSITION) {}
    void InternalInitState(const idFiniteStateMachine* fsm);
    void AIState_EnterState(idAI2* ai, idAIFSM* fsm, int currentTime) override;
};

class idMeleeTransitionBase : public idAIFSMTransitionBase {};

class MELEE_RepositionFailed : public idMeleeTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2*, idAIFSM*, idAIState* state, int) override;
};
class MELEE_Reposition : public idMeleeTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2* ai, idAIFSM*, idAIState*, int currentTime) override;
};
class COMBAT_MeleeDone : public idMeleeTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2*, idAIFSM*, idAIState* state, int) override;
};
class MELEE_RepositionDone : public idMeleeTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2*, idAIFSM*, idAIState* state, int) override;
};
class MELEE_NoTarget : public idMeleeTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2* ai, idAIFSM*, idAIState*, int) override;
};
class MELEE_TargetOutOfRange : public idMeleeTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2* ai, idAIFSM*, idAIState*, int) override;
};
class MELEE_Attack : public idMeleeTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2* ai, idAIFSM*, idAIState*, int) override;
};

class idMeleeFSM : public idAIFSM {
public:
    idMeleeFSM();
    ~idMeleeFSM() override;
    void InitStates(const idFiniteStateMachineParams* params) override;
    bool CanUse(idFiniteStateMachine* fsm, int currentTime) const;

    unsigned char meleeFSMBaseOpaque[80];
    idMelee_Default stateDefault;
    idMelee_Attack stateAttack;
    idMelee_Reposition stateReposition;
};

bool Tungsten_GetMeleeBehaviorRuntime(
    const idAI2& ai, idMeleeBehaviorRuntime& runtime);
bool Tungsten_GetMeleeTargetRuntime(
    const idAI2& ai, idMeleeTargetRuntime& runtime);
unsigned int Tungsten_NextMeleeRandom();
int Tungsten_GetMeleeScaledGameMilliseconds();
void Tungsten_SetMeleeNextDodgeTime(idAI2& ai, int time);
void Tungsten_SetMeleeNextCloseTime(idAI2& ai, int time);
void Tungsten_SetMeleeHeadTracking(idAI2& ai, bool enabled);
void Tungsten_SetMeleeHoldFire(idAI2& ai, bool allowReloads);
void Tungsten_SetMeleeWantAngryRageTime(
    idAI2& ai, int time, const char* reason);
void Tungsten_EndMeleeActionScript(idAI2& ai);
void Tungsten_StartMeleeAttackAction(idAI2& ai, idAIFSM& fsm,
    idMelee_Attack& state, overrideAnim_t animation);
void Tungsten_StartMeleeDodgeAction(idAI2& ai, idAIFSM& fsm,
    idMelee_Reposition& state, int dodgeDirection);
int Tungsten_GetMeleeMoveStatus(const idAI2& ai);
bool Tungsten_GetMeleeChildFSMStatus(
    const idAIState& state, int& status);
idAI2* Tungsten_GetMeleeFSMOwner(idFiniteStateMachine& fsm);
void Tungsten_InitializeMeleeFSMBase(idMeleeFSM& fsm, const char* name);
void Tungsten_InitializeMeleeFSMStates(idMeleeFSM& fsm,
    const idFiniteStateMachineParams* params);
void Tungsten_AddMeleeFSMState(idMeleeFSM& fsm, idMeleeStateBase& state);
void Tungsten_SetMeleeFSMDefaultState(idMeleeFSM& fsm, idMeleeStateBase& state);
void Tungsten_AddMeleeStateTransition(idMeleeStateBase& state,
    const idFiniteStateMachine& fsm, idMeleeTransitionKind transition,
    idMeleeStateKind destination);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idMeleeStateBase) == 28,
    "Recovered melee state ABI changed");
static_assert(sizeof(idMeleeFSM) == 192,
    "Recovered idMeleeFSM ABI changed");
#endif
