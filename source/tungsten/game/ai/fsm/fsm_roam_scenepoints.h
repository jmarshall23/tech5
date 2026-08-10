#pragma once

#include "aifsm.h"
#include "scenepoint_common.h"

class idScenePoint;

static constexpr int TRANSCODE_ROAM_SCENEPOINT = 0x1C8;
static constexpr int ROAM_SCENEPOINT_INDEFINITE_TIME = 666;
static constexpr int ROAM_SCENEPOINT_SEARCH_INTERVAL = 2000;
static constexpr unsigned int ROAM_SCENEPOINT_ENABLED = 0x08u;
static constexpr int ROAM_SCENEPOINT_SCRIPTED = 0x01;
static constexpr int ROAM_SCENEPOINT_RUN = 0x02;
static constexpr int ROAM_LOOKFLAG_RELAXED = 0x01;

enum idRoamScenePointStateKind : int {
    ROAM_STATE_IDLE = 0,
    ROAM_STATE_FIND,
    ROAM_STATE_MOVE_TO,
    ROAM_STATE_STAY_AT,
    ROAM_STATE_SHARED_WAIT_FOR_ANIMATION,
    ROAM_STATE_SHARED_FINISHED,
    ROAM_STATE_DONE
};

enum idRoamScenePointTransitionKind : int {
    ROAM_TRANSITION_LOOK_AT_SCENEPOINT = 0,
    ROAM_TRANSITION_MOVE_TO_SCENEPOINT,
    ROAM_TRANSITION_IDLE,
    ROAM_TRANSITION_FIND_SCENEPOINT,
    ROAM_TRANSITION_STAY_AT_SCENEPOINT,
    ROAM_TRANSITION_SHARED_FINISHED
};

struct idRoamAIRuntime {
    bool usesRoamScenePoints;
    bool usesLookScenePoints;
    bool hasOverrideRoamScenePoint;
    bool hasScenePointVolumes;
    bool hasSquadLeader;
    bool awareOfEnemy;
    bool hasPlayer;
    idVec3 playerOrigin;
    idVec3 aiOrigin;
    float roamMinRange;
    float roamMaxRange;
    float lookMinRange;
    float lookMaxRange;
    int lastScenePointSearchTime;
    int lastLookScenePointSearchTime;
    int moveStatus;
    idScenePoint* currentScenePoint;
    idScenePoint* currentLookScenePoint;
};

struct idRoamScenePointRuntime {
    bool isRoam;
    bool isLook;
    scenePointType_t type;
    unsigned int flags;
    int scriptFlags;
    float duration;
    float radius;
    int lookFlags;
    bool dirtyScenePoint;
    bool dirtyLookScenePoint;
    bool inArc;
    idScenePoint* nextLookScenePoint;
    const char* name;
    const char* scenePointAnimation;
};

struct idRoamMoveCommand {
    idScenePoint* scenePoint;
    bool useScenePoint;
    idVec3 offset;
    bool durationIsZero;
    float arrivalRadius;
    int arrivalMode;
    int moveFlags;
};

class idRoamScenePointStateBase : public idAIState {
public:
    explicit idRoamScenePointStateBase(idRoamScenePointStateKind kind);

    bool AIState_CanUse(idAI2*, idAIFSM*, int) override { return true; }
    void AIState_EnterState(idAI2*, idAIFSM*, int) override {}
    void AIState_ExitState(idAI2*, idAIFSM*, int) override {}
    void AIState_Work(idAI2*, idAIFSM*, int) override {}
    void AIState_ReenterState(idAI2*, idAIFSM*, int, int) override {}
    bool AIState_IsWaiting(idAI2*, idAIFSM*, int) override { return false; }

    idRoamScenePointStateKind kind;
    bool enterFailed;
    unsigned char roamStateOpaque[15];
};

class idRoamScenePoint_Idle : public idRoamScenePointStateBase {
public:
    idRoamScenePoint_Idle() : idRoamScenePointStateBase(ROAM_STATE_IDLE) {}
    void InternalInitState(const idFiniteStateMachine* fsm);
};

class idRoamScenePoint_Find : public idRoamScenePointStateBase {
public:
    idRoamScenePoint_Find() : idRoamScenePointStateBase(ROAM_STATE_FIND) {}
    void InternalInitState(const idFiniteStateMachine* fsm);
    void AIState_EnterState(idAI2* ai, idAIFSM* fsm, int currentTime) override;
    void AIState_ReenterState(idAI2* ai, idAIFSM* fsm,
        int transitionCode, int currentTime) override;
};

class idRoamScenePoint_MoveTo : public idRoamScenePointStateBase {
public:
    idRoamScenePoint_MoveTo()
        : idRoamScenePointStateBase(ROAM_STATE_MOVE_TO) {}
    void InternalInitState(const idFiniteStateMachine* fsm);
    void AIState_EnterState(idAI2* ai, idAIFSM* fsm, int currentTime) override;
    void AIState_ExitState(idAI2* ai, idAIFSM* fsm, int currentTime) override;
};

class idRoamScenePoint_StayAt : public idRoamScenePointStateBase {
public:
    idRoamScenePoint_StayAt()
        : idRoamScenePointStateBase(ROAM_STATE_STAY_AT) {}
    void InternalInitState(const idFiniteStateMachine* fsm);
    void AIState_EnterState(idAI2* ai, idAIFSM* fsm, int currentTime) override;
};

class idRoamScenePoint_SharedWaitForAnimation
        : public idRoamScenePointStateBase {
public:
    idRoamScenePoint_SharedWaitForAnimation()
        : idRoamScenePointStateBase(
            ROAM_STATE_SHARED_WAIT_FOR_ANIMATION) {}
    void InternalInitState(const idFiniteStateMachine* fsm);
};

class idRoamScenePoint_SharedFinished
        : public idRoamScenePointStateBase {
public:
    idRoamScenePoint_SharedFinished()
        : idRoamScenePointStateBase(ROAM_STATE_SHARED_FINISHED) {}
    void InternalInitState(const idFiniteStateMachine* fsm);
};

class idRoamScenePointTransitionBase : public idAIStateTransitionStatic {
public:
    idRoamScenePointTransitionBase() : idAIStateTransitionStatic(0) {}
    idTypeInfo* GetType() override { return nullptr; }
};

class RoamScenePoint_Shall_Idle : public idRoamScenePointTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2* ai, idAIFSM*, idAIState*, int) override;
};
class RoamScenePoint_Shall_MoveToScenePoint
        : public idRoamScenePointTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2* ai, idAIFSM* parentFSM,
        idAIState*, int) override;
};
class RoamScenePoint_Shall_FindScenePoint
        : public idRoamScenePointTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2* ai, idAIFSM* parentFSM,
        idAIState*, int currentTime) override;
};
class RoamScenePoint_Shall_StayAtScenePoint
        : public idRoamScenePointTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2* ai, idAIFSM*, idAIState*,
        int currentTime) override;
};
class RoamScenePoint_Shall_LookAtScenePoint
        : public idRoamScenePointTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2* ai, idAIFSM* parentFSM,
        idAIState*, int currentTime) override;
};

class idRoamScenePointFSM : public idAIFSM {
public:
    idRoamScenePointFSM();
    ~idRoamScenePointFSM() override;
    void InitStates(const idFiniteStateMachineParams* params) override;
    bool CanUse(idFiniteStateMachine* fsm, int currentTime) const;

    unsigned char roamFSMBaseOpaque[80];
    idRoamScenePoint_Idle stateRoamSPIdle;
    idRoamScenePoint_Find stateRoamSPFind;
    idRoamScenePoint_MoveTo stateRoamSPMoveTo;
    idRoamScenePoint_StayAt stateRoamSPStayAt;
    idRoamScenePoint_SharedWaitForAnimation
        stateRoamSPSharedWaitForAnimation;
    idRoamScenePoint_SharedFinished stateRoamSPSharedFinished;
    int stayTime;
    int lookTime;
};

bool Tungsten_GetRoamAIRuntime(const idAI2& ai, idRoamAIRuntime& runtime);
bool Tungsten_GetRoamScenePointRuntime(const idAI2& ai,
    const idScenePoint& point, idRoamScenePointRuntime& runtime);
idAI2* Tungsten_GetRoamFSMOwner(idFiniteStateMachine& fsm);
void Tungsten_SetRoamEnterFailed(idRoamScenePointStateBase& state,
    bool failed);
void Tungsten_SetRoamCurrentScenePoint(idAI2& ai, idScenePoint* point);
void Tungsten_SetRoamCurrentLookScenePoint(idAI2& ai, idScenePoint* point);
bool Tungsten_RequestRoamScenePoint(idScenePoint& point, idAI2& ai,
    int currentTime);
void Tungsten_ReleaseRoamScenePoint(idScenePoint& point, idAI2& ai);
void Tungsten_ActivateRoamScenePoint(idScenePoint& point, idAI2& ai,
    int currentTime);
void Tungsten_ClearRoamScenePointHistory(idAI2& ai);
void Tungsten_UpdateRoamScenePointHistory(idAI2& ai,
    idScenePoint& point);
void Tungsten_UpdateRoamLookScenePointHistory(idAI2& ai,
    idScenePoint& point);
void Tungsten_DisableUnreachableRoamScenePoint(idScenePoint& point,
    idAI2& ai, int retryTime, int moveStatus, bool scripted);
void Tungsten_RestoreRoamIdleAnimation(idAI2& ai);
void Tungsten_SetRoamAnimationSubWebRelaxed(idAI2& ai);
void Tungsten_SetRoamWalkState(idAI2& ai, int walkState);
void Tungsten_SetRoamHeadTracking(idAI2& ai, bool enabled);
void Tungsten_ClearRoamAimFocus(idAI2& ai);
void Tungsten_EndRoamActionScript(idAI2& ai);
void Tungsten_StartRoamMoveAction(idAI2& ai, idAIFSM& fsm,
    idRoamScenePoint_MoveTo& state, const idRoamMoveCommand& command);
void Tungsten_StopRoamMovement(idAI2& ai, int newStatus);
void Tungsten_SetRoamLookFocus(idAI2& ai, idScenePoint& point,
    bool keepFocusInView);
void Tungsten_ClearRoamLookFocus(idAI2& ai);
int Tungsten_PlayRoamAnimWebPath(idAI2& ai, const char* path,
    bool forceTransition);
void Tungsten_WarnRoamAnimationFailure(const idAI2& ai,
    const idScenePoint& point);
void Tungsten_InitializeRoamFSMRuntime(idRoamScenePointFSM& fsm,
    const char* name);
void Tungsten_InitializeRoamFSMStates(idRoamScenePointFSM& fsm,
    const idFiniteStateMachineParams* params);
void Tungsten_AddRoamFSMState(idRoamScenePointFSM& fsm,
    idRoamScenePointStateBase& state);
void Tungsten_SetRoamFSMDefaultState(idRoamScenePointFSM& fsm,
    idRoamScenePointStateBase& state);
void Tungsten_AddRoamStateTransition(idRoamScenePointStateBase& state,
    const idFiniteStateMachine& fsm,
    idRoamScenePointTransitionKind transition,
    idRoamScenePointStateKind destination);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idRoamScenePointStateBase) == 28,
    "Recovered roam scene-point state ABI changed");
static_assert(sizeof(idRoamScenePointFSM) == 284,
    "Recovered idRoamScenePointFSM ABI changed");
#endif
