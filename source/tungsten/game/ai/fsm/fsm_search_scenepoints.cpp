#include "fsm_search_scenepoints.h"

namespace {

idSearchScenePointFSM* AsSearchFSM(idAIFSM* const fsm) {
    return static_cast<idSearchScenePointFSM*>(fsm);
}

bool SearchIntervalElapsed(const int lastTime, const int currentTime) {
    return lastTime == 0
        || currentTime > lastTime + SEARCH_SCENEPOINT_SEARCH_INTERVAL;
}

bool GetPointRuntime(const idAI2& ai, idScenePoint* const point,
        idSearchScenePointRuntime& runtime) {
    return point != nullptr
        && Tungsten_GetSearchScenePointRuntime(ai, *point, runtime);
}

void FindSearchScenePoint(idSearchScenePoint_Find& state, idAI2& ai) {
    idSearchScenePointAIRuntime runtime{};
    if (!Tungsten_GetSearchScenePointAIRuntime(ai, runtime)) {
        Tungsten_SetSearchScenePointEnterFailed(state, true);
        return;
    }
    idScenePoint* const point = GetBestScenePoint(&ai,
        runtime.searchMinRange, runtime.searchMaxRange,
        runtime.suspectedEnemyPosition,
        SEARCH, LOOKFLAG_NONE);
    if (point != nullptr) {
        Tungsten_SetSearchCurrentScenePoint(ai, point);
    } else {
        Tungsten_SetSearchScenePointEnterFailed(state, true);
    }
}

void BeginMoveToEnemy(idSearchScenePoint_MoveToPos& state,
        idAI2& ai, idAIFSM& fsm, const int currentTime) {
    idSearchScenePointAIRuntime runtime{};
    if (!Tungsten_GetSearchScenePointAIRuntime(ai, runtime)
            || runtime.currentEnemy == nullptr) {
        return;
    }
    Tungsten_SetSearchAnimationSubWebCombat(ai);
    Tungsten_SetSearchWalkState(ai, 1);
    idSearchEnemyMoveCommand command{};
    command.enemy = runtime.currentEnemy;
    command.queueStandAction = runtime.crouched;
    command.offset.Zero();
    command.stopDistance = runtime.closeMinRange;
    command.arrivalMode = 2;
    Tungsten_StartSearchEnemyMoveAction(
        ai, fsm, state, currentTime, command);
    Tungsten_SetSearchAimFocusEnemy(ai, *runtime.currentEnemy, false);
    Tungsten_SetSearchFireWhenReady(ai);
}

} // namespace

idSearchScenePointStateBase::idSearchScenePointStateBase(
        const idSearchScenePointStateKind stateKind)
    : idAIState()
    , kind(stateKind)
    , enterFailed(false)
    , searchStateOpaque{} {
}

// EA: 0x82AF1E58
void idSearchScenePoint_Find::InternalInitState(
        const idFiniteStateMachine* const fsm) {
    Tungsten_AddSearchScenePointStateTransition(*this, *fsm,
        SEARCH_SP_TRANSITION_LOOK_AT_SCENEPOINT, SEARCH_SP_STATE_FIND);
    Tungsten_AddSearchScenePointStateTransition(*this, *fsm,
        SEARCH_SP_TRANSITION_MOVE_TO_SCENEPOINT, SEARCH_SP_STATE_MOVE_TO);
    Tungsten_AddSearchScenePointStateTransition(*this, *fsm,
        SEARCH_SP_TRANSITION_FIND_SCENEPOINT, SEARCH_SP_STATE_FIND);
    Tungsten_AddSearchScenePointStateTransition(*this, *fsm,
        SEARCH_SP_TRANSITION_MOVE_TO_POS, SEARCH_SP_STATE_MOVE_TO_POS);
}

// EA: 0x82AF1EE0
void idSearchScenePoint_MoveTo::InternalInitState(
        const idFiniteStateMachine* const fsm) {
    Tungsten_AddSearchScenePointStateTransition(*this, *fsm,
        SEARCH_SP_TRANSITION_LOOK_AT_SCENEPOINT, SEARCH_SP_STATE_MOVE_TO);
    Tungsten_AddSearchScenePointStateTransition(*this, *fsm,
        SEARCH_SP_TRANSITION_STAY_AT_SCENEPOINT, SEARCH_SP_STATE_STAY_AT);
    Tungsten_AddSearchScenePointStateTransition(*this, *fsm,
        SEARCH_SP_TRANSITION_FIND_SCENEPOINT, SEARCH_SP_STATE_FIND);
    Tungsten_AddSearchScenePointStateTransition(*this, *fsm,
        SEARCH_SP_TRANSITION_MOVE_TO_POS, SEARCH_SP_STATE_MOVE_TO_POS);
}

// EA: 0x82AF1F80
void idSearchScenePoint_MoveToPos::InternalInitState(
        const idFiniteStateMachine* const fsm) {
    Tungsten_AddSearchScenePointStateTransition(*this, *fsm,
        SEARCH_SP_TRANSITION_LOOK_AT_SCENEPOINT, SEARCH_SP_STATE_STAY_AT);
    Tungsten_AddSearchScenePointStateTransition(*this, *fsm,
        SEARCH_SP_TRANSITION_FIND_SCENEPOINT, SEARCH_SP_STATE_FIND);
    Tungsten_AddSearchScenePointStateTransition(*this, *fsm,
        SEARCH_SP_TRANSITION_MOVE_TO_POS, SEARCH_SP_STATE_MOVE_TO_POS);
}

// EA: 0x82AF2000
void idSearchScenePointFSM::InitStates(
        const idFiniteStateMachineParams* const params) {
    Tungsten_InitializeSearchScenePointFSMStates(*this, params);
    Tungsten_AddSearchScenePointFSMState(*this, stateSearchSPFind);
    Tungsten_AddSearchScenePointFSMState(*this, stateSearchSPMoveTo);
    Tungsten_AddSearchScenePointFSMState(*this, stateSearchSPStayAt);
    Tungsten_AddSearchScenePointFSMState(*this, stateSearchSPMoveToPos);
}

// EA: 0x82AF2090
idAIStateTransition::aiTransCode_t
SearchScenePoint_Shall_MoveToScenePoint::Evaluate(
        idAI2* const ai, idAIFSM* const parentFSM,
        idAIState*, int) {
    idSearchScenePointAIRuntime aiRuntime{};
    idSearchScenePointRuntime pointRuntime{};
    idSearchScenePointFSM* const fsm = AsSearchFSM(parentFSM);
    if (!Tungsten_GetSearchScenePointAIRuntime(*ai, aiRuntime)
            || !GetPointRuntime(*ai, aiRuntime.currentScenePoint,
                pointRuntime)
            || !pointRuntime.isSearch || fsm == nullptr
            || fsm->stayTime != -1) {
        return 0;
    }
    if (aiRuntime.suspectedEnemyPosition.valid
            && pointRuntime.suspectedPositionInArc) {
        return TRANSCODE_SEARCH_SCENEPOINT;
    }
    Tungsten_UpdateSearchScenePointHistory(
        *ai, *aiRuntime.currentScenePoint);
    Tungsten_ReleaseSearchScenePoint(
        *aiRuntime.currentScenePoint, *ai);
    Tungsten_SetSearchCurrentScenePoint(*ai, nullptr);
    return 0;
}

// EA: 0x82AF2170
idAIStateTransition::aiTransCode_t
SearchScenePoint_Shall_MoveToPos::Evaluate(
        idAI2* const ai, idAIFSM*, idAIState*, int) {
    idSearchScenePointAIRuntime aiRuntime{};
    idSearchScenePointRuntime pointRuntime{};
    if (!Tungsten_GetSearchScenePointAIRuntime(*ai, aiRuntime)) {
        return 0;
    }
    const bool hasSearchPoint = GetPointRuntime(*ai,
        aiRuntime.currentScenePoint, pointRuntime)
        && pointRuntime.isSearch;
    if (hasSearchPoint) {
        return 0;
    }
    if (aiRuntime.moveStatus == 0) {
        return TRANSCODE_SEARCH_SCENEPOINT;
    }
    if (aiRuntime.moveStatus != 1) {
        Tungsten_RestoreSearchIdleAnimation(*ai);
        Tungsten_StopSearchMovement(*ai, 0);
    }
    return 0;
}

// EA: 0x82AF2288
void idSearchScenePoint_Find::AIState_EnterState(
        idAI2* const ai, idAIFSM*, int) {
    FindSearchScenePoint(*this, *ai);
}

// EA: 0x82AF2300
void idSearchScenePoint_Find::AIState_ReenterState(
        idAI2* const ai, idAIFSM*, int, int) {
    idSearchScenePointAIRuntime runtime{};
    if (!Tungsten_GetSearchScenePointAIRuntime(*ai, runtime)
            || runtime.currentScenePoint == nullptr) {
        FindSearchScenePoint(*this, *ai);
    }
}

// EA: 0x82AF2380
void idSearchScenePoint_MoveTo::AIState_EnterState(
        idAI2* const ai, idAIFSM* const fsm, int) {
    idSearchScenePointAIRuntime aiRuntime{};
    idSearchScenePointRuntime pointRuntime{};
    if (Tungsten_GetSearchScenePointAIRuntime(*ai, aiRuntime)
            && GetPointRuntime(*ai, aiRuntime.currentScenePoint,
                pointRuntime)
            && pointRuntime.isSearch
            && aiRuntime.suspectedEnemyPosition.valid
            && pointRuntime.suspectedPositionInArc) {
        Tungsten_SetSearchAnimationSubWebCombat(*ai);
        Tungsten_SetSearchWalkState(*ai, 1);
        Tungsten_SetSearchHeadTracking(*ai, true);
        Tungsten_EndSearchActionScript(*ai);
        if (fsm != nullptr) {
            fsm->actionCallerState = this;
        }
        idSearchPointMoveCommand command{};
        command.scenePoint = aiRuntime.currentScenePoint;
        command.useScenePoint = false;
        command.offset.Zero();
        command.durationIsZero = pointRuntime.duration == 0.0f;
        command.arrivalRadius = pointRuntime.radius * 0.5f;
        command.arrivalMode = command.durationIsZero ? 2 : 1;
        command.moveFlags = 35;
        Tungsten_StartSearchPointMoveAction(
            *ai, *fsm, *this, command);
        return;
    }
    Tungsten_SetSearchScenePointEnterFailed(*this, true);
    if (aiRuntime.currentScenePoint != nullptr) {
        Tungsten_UpdateSearchScenePointHistory(
            *ai, *aiRuntime.currentScenePoint);
        Tungsten_ReleaseSearchScenePoint(
            *aiRuntime.currentScenePoint, *ai);
        Tungsten_SetSearchCurrentScenePoint(*ai, nullptr);
    }
}

// EA: 0x82AF2618
void idSearchScenePoint_StayAt::AIState_ExitState(
        idAI2* const ai, idAIFSM* const fsm,
        const int currentTime) {
    idSearchScenePointAIRuntime aiRuntime{};
    idSearchScenePointRuntime pointRuntime{};
    if (Tungsten_GetSearchScenePointAIRuntime(*ai, aiRuntime)
            && GetPointRuntime(*ai, aiRuntime.currentScenePoint,
                pointRuntime)
            && pointRuntime.isSearch) {
        Tungsten_UpdateSearchScenePointHistory(
            *ai, *aiRuntime.currentScenePoint);
        Tungsten_ReleaseSearchScenePoint(
            *aiRuntime.currentScenePoint, *ai);
        Tungsten_SetSearchCurrentScenePoint(*ai, nullptr);
    }
    Tungsten_SetSearchAnimationSubWebCombat(*ai);
    if (aiRuntime.crouched && fsm != nullptr) {
        Tungsten_QueueSearchStandAction(
            *ai, *fsm, *this, currentTime);
    }
    Tungsten_SetSearchHeadTracking(*ai, true);
    Tungsten_ClearSearchAimFocus(*ai);
    Tungsten_ClearSearchLookFocus(*ai);
}

// EA: 0x82AF2720
idSearchScenePointFSM::idSearchScenePointFSM()
    : idAIFSM()
    , searchFSMBaseOpaque{}
    , stateSearchSPFind()
    , stateSearchSPMoveTo()
    , stateSearchSPStayAt()
    , stateSearchSPMoveToPos()
    , stayTime(-1)
    , lookTime(-1) {
    Tungsten_InitializeSearchScenePointFSMRuntime(
        *this, "FSM_SearchScenePoint");
    Tungsten_SetSearchScenePointFSMDefaultState(
        *this, stateSearchSPFind);
}

// EA: 0x82AF28F0
idSearchScenePointFSM::~idSearchScenePointFSM() = default;

// EA: 0x82AF2A08
bool idSearchScenePointFSM::CanUse(
        idFiniteStateMachine* const fsm,
        const int currentTime) {
    if (fsm == nullptr) {
        return false;
    }
    idAI2* const ai = Tungsten_GetSearchScenePointFSMOwner(*fsm);
    idSearchScenePointAIRuntime runtime{};
    if (ai == nullptr
            || !Tungsten_GetSearchScenePointAIRuntime(*ai, runtime)
            || runtime.combatTimeoutInterval < 0.0f
            || !runtime.hasEnemySenseState
            || runtime.lastConfirmedStimTime <= 0) {
        return false;
    }
    const int elapsed = currentTime - runtime.lastConfirmedStimTime;
    if (elapsed <= static_cast<int>(
            runtime.combatTimeoutInterval * 1000.0f)) {
        return false;
    }
    return runtime.searchTimeoutInterval < 0.0f
        || elapsed <= static_cast<int>((runtime.searchTimeoutInterval
            + runtime.combatTimeoutInterval) * 1000.0f);
}

// EA: 0x82AF2AD8
idAIStateTransition::aiTransCode_t
SearchScenePoint_Shall_FindScenePoint::Evaluate(
        idAI2* const ai, idAIFSM* const parentFSM, idAIState*,
        const int currentTime) {
    idSearchScenePointAIRuntime aiRuntime{};
    if (!Tungsten_GetSearchScenePointAIRuntime(*ai, aiRuntime)
            || !aiRuntime.usesSearchScenePoints) {
        return 0;
    }
    idSearchScenePointRuntime pointRuntime{};
    if (GetPointRuntime(*ai, aiRuntime.currentScenePoint, pointRuntime)
            && pointRuntime.isSearch) {
        bool valid = true;
        bool invalidScriptPoint = false;
        idSearchScenePointFSM* const fsm = AsSearchFSM(parentFSM);
        if ((pointRuntime.scriptFlags & SEARCH_SCENEPOINT_SCRIPTED) != 0) {
            const bool scriptValid = IsScriptScenePointValid(
                ai, aiRuntime.currentScenePoint);
            invalidScriptPoint = !scriptValid;
            valid = pointRuntime.type == SEARCH && scriptValid;
            if (valid && fsm != nullptr && pointRuntime.duration >= 0.0f
                    && fsm->stayTime >= 0) {
                valid = currentTime <= fsm->stayTime;
            }
            if (valid) {
                valid = (pointRuntime.flags & SEARCH_SCENEPOINT_ENABLED) != 0;
            }
            if (valid && aiRuntime.hasOverrideSearchScenePoint) {
                valid = false;
            }
        } else {
            if (fsm != nullptr && pointRuntime.duration >= 0.0f
                    && fsm->stayTime >= 0) {
                valid = currentTime <= fsm->stayTime;
            }
            if (valid) {
                valid = (pointRuntime.flags & SEARCH_SCENEPOINT_ENABLED) != 0;
            }
            if (valid && pointRuntime.dirtyScenePoint) {
                valid = false;
            }
            if (valid && !Tungsten_RequestSearchScenePoint(
                    *aiRuntime.currentScenePoint, *ai, currentTime)) {
                valid = false;
            }
            if (valid && aiRuntime.hasOverrideSearchScenePoint) {
                valid = false;
            }
        }
        if (!valid) {
            if (fsm != nullptr) {
                fsm->stayTime = -1;
            }
            if (invalidScriptPoint) {
                Tungsten_ClearSearchScenePointHistory(*ai);
            } else {
                Tungsten_UpdateSearchScenePointHistory(
                    *ai, *aiRuntime.currentScenePoint);
            }
            Tungsten_ReleaseSearchScenePoint(
                *aiRuntime.currentScenePoint, *ai);
            Tungsten_SetSearchCurrentScenePoint(*ai, nullptr);
            return TRANSCODE_SEARCH_SCENEPOINT;
        }
        return 0;
    }
    if (aiRuntime.hasOverrideSearchScenePoint) {
        return TRANSCODE_SEARCH_SCENEPOINT;
    }
    if (!aiRuntime.hasScenePointVolumes) {
        return 0;
    }
    return SearchIntervalElapsed(aiRuntime.lastScenePointSearchTime,
        currentTime) ? TRANSCODE_SEARCH_SCENEPOINT : 0;
}

// EA: 0x82AF2DC0
idAIStateTransition::aiTransCode_t
SearchScenePoint_Shall_StayAtScenePoint::Evaluate(
        idAI2* const ai, idAIFSM*, idAIState*,
        const int currentTime) {
    idSearchScenePointAIRuntime aiRuntime{};
    idSearchScenePointRuntime pointRuntime{};
    if (!Tungsten_GetSearchScenePointAIRuntime(*ai, aiRuntime)
            || !GetPointRuntime(*ai, aiRuntime.currentScenePoint,
                pointRuntime)
            || !pointRuntime.isSearch) {
        return 0;
    }
    if (aiRuntime.suspectedEnemyPosition.valid
            && pointRuntime.suspectedPositionInArc) {
        if (aiRuntime.moveStatus == 0) {
            return TRANSCODE_SEARCH_SCENEPOINT;
        }
        if (aiRuntime.moveStatus != 1) {
            Tungsten_DisableUnreachableSearchScenePoint(
                *aiRuntime.currentScenePoint, *ai,
                currentTime + 10000, aiRuntime.moveStatus,
                (pointRuntime.scriptFlags
                    & SEARCH_SCENEPOINT_SCRIPTED) != 0);
            Tungsten_SetSearchCurrentScenePoint(*ai, nullptr);
            Tungsten_RestoreSearchIdleAnimation(*ai);
            Tungsten_StopSearchMovement(*ai, 0);
        }
        return 0;
    }
    Tungsten_UpdateSearchScenePointHistory(
        *ai, *aiRuntime.currentScenePoint);
    Tungsten_ReleaseSearchScenePoint(
        *aiRuntime.currentScenePoint, *ai);
    Tungsten_SetSearchCurrentScenePoint(*ai, nullptr);
    if (aiRuntime.moveStatus != 1) {
        Tungsten_RestoreSearchIdleAnimation(*ai);
        Tungsten_StopSearchMovement(*ai, 0);
    }
    return 0;
}

// EA: 0x82AF3050
idAIStateTransition::aiTransCode_t
SearchScenePoint_Shall_LookAtScenePoint::Evaluate(
        idAI2* const ai, idAIFSM* const parentFSM, idAIState*,
        const int currentTime) {
    idSearchScenePointAIRuntime aiRuntime{};
    if (!Tungsten_GetSearchScenePointAIRuntime(*ai, aiRuntime)
            || !aiRuntime.usesLookScenePoints) {
        return 0;
    }
    idSearchScenePointFSM* const fsm = AsSearchFSM(parentFSM);
    idSearchScenePointRuntime pointRuntime{};
    if (GetPointRuntime(*ai, aiRuntime.currentLookScenePoint,
            pointRuntime) && pointRuntime.isLook) {
        bool valid = pointRuntime.type == LOOK
            && (pointRuntime.flags & SEARCH_SCENEPOINT_ENABLED) != 0
            && (pointRuntime.lookFlags & SEARCH_LOOKFLAG) != 0;
        if (valid && fsm != nullptr && pointRuntime.duration >= 0.0f
                && fsm->lookTime >= 0) {
            valid = currentTime <= fsm->lookTime;
        }
        if (valid && pointRuntime.dirtyLookScenePoint) {
            valid = false;
        }
        if (valid && !Tungsten_RequestSearchScenePoint(
                *aiRuntime.currentLookScenePoint, *ai, currentTime)) {
            valid = false;
        }
        if (valid && !pointRuntime.aiOriginInArc) {
            valid = false;
        }
        if (!valid) {
            if (fsm != nullptr) {
                fsm->lookTime = -1;
            }
            Tungsten_ClearSearchLookFocus(*ai);
            Tungsten_UpdateSearchLookScenePointHistory(
                *ai, *aiRuntime.currentLookScenePoint);
            Tungsten_ReleaseSearchScenePoint(
                *aiRuntime.currentLookScenePoint, *ai);
            Tungsten_SetSearchCurrentLookScenePoint(*ai, nullptr);
        }
        return 0;
    }
    if (!aiRuntime.hasScenePointVolumes
            || !SearchIntervalElapsed(
                aiRuntime.lastLookScenePointSearchTime, currentTime)) {
        return 0;
    }
    const idAIPos focus(aiRuntime.aiOrigin);
    idScenePoint* const point = GetBestScenePoint(ai,
        aiRuntime.lookMinRange, aiRuntime.lookMaxRange, focus,
        LOOK, static_cast<scenePointLookFlags_t>(SEARCH_LOOKFLAG));
    if (point == nullptr
            || !GetPointRuntime(*ai, point, pointRuntime)) {
        return 0;
    }
    Tungsten_SetSearchCurrentLookScenePoint(*ai, point);
    const int durationMilliseconds =
        static_cast<int>(pointRuntime.duration * 1000.0f);
    if (fsm != nullptr && durationMilliseconds >= 0) {
        fsm->lookTime = currentTime + durationMilliseconds;
    }
    Tungsten_SetSearchLookFocus(*ai, *point, true);
    return 0;
}

// EA: 0x82AF3348
void idSearchScenePoint_StayAt::AIState_EnterState(
        idAI2* const ai, idAIFSM* const parentFSM,
        const int currentTime) {
    idSearchScenePointAIRuntime aiRuntime{};
    idSearchScenePointRuntime pointRuntime{};
    if (!Tungsten_GetSearchScenePointAIRuntime(*ai, aiRuntime)
            || !GetPointRuntime(*ai, aiRuntime.currentScenePoint,
                pointRuntime)
            || !pointRuntime.isSearch) {
        Tungsten_SetSearchScenePointEnterFailed(*this, true);
        return;
    }
    idSearchScenePointFSM* const fsm = AsSearchFSM(parentFSM);
    if (fsm != nullptr && fsm->stayTime == -1) {
        Tungsten_ActivateSearchScenePoint(
            *aiRuntime.currentScenePoint, *ai, currentTime);
        const int durationMilliseconds =
            static_cast<int>(pointRuntime.duration * 1000.0f);
        fsm->stayTime = durationMilliseconds < 0
            ? SEARCH_SCENEPOINT_INDEFINITE_TIME
            : currentTime + durationMilliseconds;
    }
    if (pointRuntime.duration != 0.0f
            && aiRuntime.currentLookScenePoint == nullptr) {
        Tungsten_SetSearchHeadTracking(*ai, true);
        Tungsten_ClearSearchAimFocus(*ai);
        Tungsten_ClearSearchLookFocus(*ai);
        const idVec3 lookPoint = aiRuntime.aiOrigin
            + aiRuntime.eyeOffset
            + pointRuntime.arcDirection * 100.0f;
        Tungsten_SetSearchIdealLookFocusPoint(
            *ai, lookPoint, 1000, SEARCH_FOCUS_LOOK_AROUND);
    }
}

// EA: 0x82AF3570
void idSearchScenePoint_MoveToPos::AIState_EnterState(
        idAI2* const ai, idAIFSM* const fsm,
        const int currentTime) {
    if (fsm != nullptr) {
        BeginMoveToEnemy(*this, *ai, *fsm, currentTime);
    }
}

// EA: 0x82AF37E0
void idSearchScenePoint_MoveToPos::AIState_ReenterState(
        idAI2* const ai, idAIFSM* const fsm, int,
        const int currentTime) {
    idSearchScenePointAIRuntime runtime{};
    if (fsm != nullptr
            && Tungsten_GetSearchScenePointAIRuntime(*ai, runtime)
            && runtime.moveStatus != 1) {
        BeginMoveToEnemy(*this, *ai, *fsm, currentTime);
    }
}

// EA: 0x82AF3A70
void idSearchScenePoint_MoveToPos::AIState_Work(
        idAI2* const ai, idAIFSM*, int) {
    idSearchScenePointAIRuntime runtime{};
    if (!Tungsten_GetSearchScenePointAIRuntime(*ai, runtime)
            || runtime.currentEnemy == nullptr) {
        return;
    }
    const float minimumRangeSqr =
        runtime.closeMinRange * runtime.closeMinRange;
    if (runtime.distanceSqrToEnemy <= minimumRangeSqr
            && runtime.moveStatus != 0) {
        Tungsten_RestoreSearchIdleAnimation(*ai);
        Tungsten_StopSearchMovement(*ai, 0);
    }
}
