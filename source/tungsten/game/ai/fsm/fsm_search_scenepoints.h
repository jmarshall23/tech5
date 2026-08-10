#pragma once

#include "aifsm.h"
#include "scenepoint_common.h"

class idEntity;
class idScenePoint;

static constexpr int TRANSCODE_SEARCH_SCENEPOINT = 0x1C8;
static constexpr int SEARCH_SCENEPOINT_INDEFINITE_TIME = 666;
static constexpr int SEARCH_SCENEPOINT_SEARCH_INTERVAL = 2000;
static constexpr unsigned int SEARCH_SCENEPOINT_ENABLED = 0x08u;
static constexpr int SEARCH_SCENEPOINT_SCRIPTED = 0x01;
static constexpr int SEARCH_LOOKFLAG = 0x02;
static constexpr int SEARCH_FOCUS_LOOK_AROUND = 0x0C;

enum idSearchScenePointStateKind : int {
    SEARCH_SP_STATE_FIND = 0,
    SEARCH_SP_STATE_MOVE_TO,
    SEARCH_SP_STATE_STAY_AT,
    SEARCH_SP_STATE_MOVE_TO_POS
};

enum idSearchScenePointTransitionKind : int {
    SEARCH_SP_TRANSITION_LOOK_AT_SCENEPOINT = 0,
    SEARCH_SP_TRANSITION_MOVE_TO_SCENEPOINT,
    SEARCH_SP_TRANSITION_FIND_SCENEPOINT,
    SEARCH_SP_TRANSITION_MOVE_TO_POS,
    SEARCH_SP_TRANSITION_STAY_AT_SCENEPOINT
};

struct idSearchScenePointAIRuntime {
    bool usesSearchScenePoints;
    bool usesLookScenePoints;
    bool hasOverrideSearchScenePoint;
    bool hasScenePointVolumes;
    idAIPos suspectedEnemyPosition;
    idVec3 aiOrigin;
    idVec3 eyeOffset;
    float searchMinRange;
    float searchMaxRange;
    float lookMinRange;
    float lookMaxRange;
    float closeMinRange;
    float combatTimeoutInterval;
    float searchTimeoutInterval;
    bool hasEnemySenseState;
    int lastConfirmedStimTime;
    int lastScenePointSearchTime;
    int lastLookScenePointSearchTime;
    int moveStatus;
    bool crouched;
    idScenePoint* currentScenePoint;
    idScenePoint* currentLookScenePoint;
    idEntity* currentEnemy;
    float distanceSqrToEnemy;
};

struct idSearchScenePointRuntime {
    bool isSearch;
    bool isLook;
    scenePointType_t type;
    unsigned int flags;
    int scriptFlags;
    float duration;
    float radius;
    int lookFlags;
    bool dirtyScenePoint;
    bool dirtyLookScenePoint;
    bool suspectedPositionInArc;
    bool aiOriginInArc;
    idVec3 arcDirection;
};

struct idSearchPointMoveCommand {
    idScenePoint* scenePoint;
    bool useScenePoint;
    idVec3 offset;
    bool durationIsZero;
    float arrivalRadius;
    int arrivalMode;
    int moveFlags;
};

struct idSearchEnemyMoveCommand {
    idEntity* enemy;
    bool queueStandAction;
    idVec3 offset;
    float stopDistance;
    int arrivalMode;
};

class idSearchScenePointStateBase : public idAIState {
public:
    explicit idSearchScenePointStateBase(idSearchScenePointStateKind kind);

    bool AIState_CanUse(idAI2*, idAIFSM*, int) override { return true; }
    void AIState_EnterState(idAI2*, idAIFSM*, int) override {}
    void AIState_ExitState(idAI2*, idAIFSM*, int) override {}
    void AIState_Work(idAI2*, idAIFSM*, int) override {}
    void AIState_ReenterState(idAI2*, idAIFSM*, int, int) override {}
    bool AIState_IsWaiting(idAI2*, idAIFSM*, int) override { return false; }

    idSearchScenePointStateKind kind;
    bool enterFailed;
    unsigned char searchStateOpaque[15];
};

class idSearchScenePoint_Find : public idSearchScenePointStateBase {
public:
    idSearchScenePoint_Find()
        : idSearchScenePointStateBase(SEARCH_SP_STATE_FIND) {}
    void InternalInitState(const idFiniteStateMachine* fsm);
    void AIState_EnterState(idAI2* ai, idAIFSM* fsm,
        int currentTime) override;
    void AIState_ReenterState(idAI2* ai, idAIFSM* fsm,
        int transitionCode, int currentTime) override;
};

class idSearchScenePoint_MoveTo : public idSearchScenePointStateBase {
public:
    idSearchScenePoint_MoveTo()
        : idSearchScenePointStateBase(SEARCH_SP_STATE_MOVE_TO) {}
    void InternalInitState(const idFiniteStateMachine* fsm);
    void AIState_EnterState(idAI2* ai, idAIFSM* fsm,
        int currentTime) override;
};

class idSearchScenePoint_StayAt : public idSearchScenePointStateBase {
public:
    idSearchScenePoint_StayAt()
        : idSearchScenePointStateBase(SEARCH_SP_STATE_STAY_AT) {}
    void AIState_EnterState(idAI2* ai, idAIFSM* fsm,
        int currentTime) override;
    void AIState_ExitState(idAI2* ai, idAIFSM* fsm,
        int currentTime) override;
};

class idSearchScenePoint_MoveToPos : public idSearchScenePointStateBase {
public:
    idSearchScenePoint_MoveToPos()
        : idSearchScenePointStateBase(SEARCH_SP_STATE_MOVE_TO_POS) {}
    void InternalInitState(const idFiniteStateMachine* fsm);
    void AIState_EnterState(idAI2* ai, idAIFSM* fsm,
        int currentTime) override;
    void AIState_ReenterState(idAI2* ai, idAIFSM* fsm,
        int transitionCode, int currentTime) override;
    void AIState_Work(idAI2* ai, idAIFSM* fsm,
        int currentTime) override;
};

class idSearchScenePointTransitionBase
        : public idAIStateTransitionStatic {
public:
    idSearchScenePointTransitionBase() : idAIStateTransitionStatic(0) {}
    idTypeInfo* GetType() override { return nullptr; }
};

class SearchScenePoint_Shall_MoveToScenePoint
        : public idSearchScenePointTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2* ai, idAIFSM* parentFSM,
        idAIState*, int currentTime) override;
};
class SearchScenePoint_Shall_MoveToPos
        : public idSearchScenePointTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2* ai, idAIFSM*, idAIState*,
        int currentTime) override;
};
class SearchScenePoint_Shall_FindScenePoint
        : public idSearchScenePointTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2* ai, idAIFSM* parentFSM,
        idAIState*, int currentTime) override;
};
class SearchScenePoint_Shall_StayAtScenePoint
        : public idSearchScenePointTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2* ai, idAIFSM*, idAIState*,
        int currentTime) override;
};
class SearchScenePoint_Shall_LookAtScenePoint
        : public idSearchScenePointTransitionBase {
public:
    aiTransCode_t Evaluate(idAI2* ai, idAIFSM* parentFSM,
        idAIState*, int currentTime) override;
};

class idSearchScenePointFSM : public idAIFSM {
public:
    idSearchScenePointFSM();
    ~idSearchScenePointFSM() override;
    void InitStates(const idFiniteStateMachineParams* params) override;
    bool CanUse(idFiniteStateMachine* fsm, int currentTime);

    unsigned char searchFSMBaseOpaque[80];
    idSearchScenePoint_Find stateSearchSPFind;
    idSearchScenePoint_MoveTo stateSearchSPMoveTo;
    idSearchScenePoint_StayAt stateSearchSPStayAt;
    idSearchScenePoint_MoveToPos stateSearchSPMoveToPos;
    int stayTime;
    int lookTime;
};

bool Tungsten_GetSearchScenePointAIRuntime(const idAI2& ai,
    idSearchScenePointAIRuntime& runtime);
bool Tungsten_GetSearchScenePointRuntime(const idAI2& ai,
    const idScenePoint& point, idSearchScenePointRuntime& runtime);
idAI2* Tungsten_GetSearchScenePointFSMOwner(idFiniteStateMachine& fsm);
void Tungsten_SetSearchScenePointEnterFailed(
    idSearchScenePointStateBase& state, bool failed);
void Tungsten_SetSearchCurrentScenePoint(idAI2& ai, idScenePoint* point);
void Tungsten_SetSearchCurrentLookScenePoint(
    idAI2& ai, idScenePoint* point);
bool Tungsten_RequestSearchScenePoint(idScenePoint& point, idAI2& ai,
    int currentTime);
void Tungsten_ReleaseSearchScenePoint(idScenePoint& point, idAI2& ai);
void Tungsten_ActivateSearchScenePoint(idScenePoint& point, idAI2& ai,
    int currentTime);
void Tungsten_ClearSearchScenePointHistory(idAI2& ai);
void Tungsten_UpdateSearchScenePointHistory(
    idAI2& ai, idScenePoint& point);
void Tungsten_UpdateSearchLookScenePointHistory(
    idAI2& ai, idScenePoint& point);
void Tungsten_DisableUnreachableSearchScenePoint(idScenePoint& point,
    idAI2& ai, int retryTime, int moveStatus, bool scripted);
void Tungsten_RestoreSearchIdleAnimation(idAI2& ai);
void Tungsten_SetSearchAnimationSubWebCombat(idAI2& ai);
void Tungsten_SetSearchWalkState(idAI2& ai, int walkState);
void Tungsten_SetSearchHeadTracking(idAI2& ai, bool enabled);
void Tungsten_ClearSearchAimFocus(idAI2& ai);
void Tungsten_ClearSearchLookFocus(idAI2& ai);
void Tungsten_EndSearchActionScript(idAI2& ai);
void Tungsten_StartSearchPointMoveAction(idAI2& ai, idAIFSM& fsm,
    idSearchScenePoint_MoveTo& state,
    const idSearchPointMoveCommand& command);
void Tungsten_StopSearchMovement(idAI2& ai, int newStatus);
void Tungsten_QueueSearchStandAction(idAI2& ai, idAIFSM& fsm,
    idSearchScenePoint_StayAt& state, int currentTime);
void Tungsten_SetSearchLookFocus(idAI2& ai, idScenePoint& point,
    bool keepFocusInView);
void Tungsten_SetSearchIdealLookFocusPoint(idAI2& ai,
    const idVec3& point, int timeout, int focusType);
bool Tungsten_StartSearchEnemyMoveAction(idAI2& ai, idAIFSM& fsm,
    idSearchScenePoint_MoveToPos& state, int currentTime,
    const idSearchEnemyMoveCommand& command);
void Tungsten_SetSearchAimFocusEnemy(idAI2& ai, idEntity& enemy,
    bool keepFocusInView);
void Tungsten_SetSearchFireWhenReady(idAI2& ai);
void Tungsten_InitializeSearchScenePointFSMRuntime(
    idSearchScenePointFSM& fsm, const char* name);
void Tungsten_InitializeSearchScenePointFSMStates(
    idSearchScenePointFSM& fsm,
    const idFiniteStateMachineParams* params);
void Tungsten_AddSearchScenePointFSMState(idSearchScenePointFSM& fsm,
    idSearchScenePointStateBase& state);
void Tungsten_SetSearchScenePointFSMDefaultState(
    idSearchScenePointFSM& fsm, idSearchScenePointStateBase& state);
void Tungsten_AddSearchScenePointStateTransition(
    idSearchScenePointStateBase& state,
    const idFiniteStateMachine& fsm,
    idSearchScenePointTransitionKind transition,
    idSearchScenePointStateKind destination);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idSearchScenePointStateBase) == 28,
    "Recovered search scene-point state ABI changed");
static_assert(sizeof(idSearchScenePointFSM) == 228,
    "Recovered idSearchScenePointFSM ABI changed");
#endif
