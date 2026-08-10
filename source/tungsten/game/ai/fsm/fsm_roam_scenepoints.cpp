#include "fsm_roam_scenepoints.h"

namespace {

idRoamScenePointFSM* AsRoamFSM(idAIFSM* const fsm) {
    return static_cast<idRoamScenePointFSM*>(fsm);
}

bool SearchIntervalElapsed(const int lastSearchTime,
        const int currentTime) {
    return lastSearchTime == 0
        || currentTime > lastSearchTime + ROAM_SCENEPOINT_SEARCH_INTERVAL;
}

bool GetPointRuntime(const idAI2& ai, idScenePoint* const point,
        idRoamScenePointRuntime& runtime) {
    return point != nullptr
        && Tungsten_GetRoamScenePointRuntime(ai, *point, runtime);
}

void FindRoamScenePoint(idRoamScenePoint_Find& state, idAI2& ai,
        idRoamScenePointFSM* const fsm) {
    idRoamAIRuntime runtime{};
    if (Tungsten_GetRoamAIRuntime(ai, runtime) && runtime.hasPlayer) {
        const idAIPos focus(runtime.playerOrigin);
        idScenePoint* const point = GetBestScenePoint(&ai,
            runtime.roamMinRange, runtime.roamMaxRange, focus,
            ROAM, LOOKFLAG_NONE);
        if (point != nullptr) {
            if (fsm != nullptr) {
                fsm->stayTime = -1;
            }
            Tungsten_SetRoamCurrentScenePoint(ai, point);
            return;
        }
    }

    Tungsten_SetRoamEnterFailed(state, true);
    Tungsten_RestoreRoamIdleAnimation(ai);
}

void SelectRoamLookPoint(idAI2& ai, idRoamScenePointFSM* const fsm,
        idScenePoint& point, const idRoamScenePointRuntime& pointRuntime,
        const int currentTime) {
    Tungsten_SetRoamCurrentLookScenePoint(ai, &point);
    Tungsten_ActivateRoamScenePoint(point, ai, currentTime);
    const int durationMilliseconds =
        static_cast<int>(pointRuntime.duration * 1000.0f);
    if (fsm != nullptr && durationMilliseconds >= 0) {
        fsm->lookTime = currentTime + durationMilliseconds;
    }
    Tungsten_SetRoamLookFocus(ai, point, false);
}

} // namespace

idRoamScenePointStateBase::idRoamScenePointStateBase(
        const idRoamScenePointStateKind stateKind)
    : idAIState()
    , kind(stateKind)
    , enterFailed(false)
    , roamStateOpaque{} {
}

// EA: 0x82AED8F0
void idRoamScenePoint_Idle::InternalInitState(
        const idFiniteStateMachine* const fsm) {
    Tungsten_AddRoamStateTransition(*this, *fsm,
        ROAM_TRANSITION_LOOK_AT_SCENEPOINT, ROAM_STATE_IDLE);
}

// EA: 0x82AED908
void idRoamScenePoint_Find::InternalInitState(
        const idFiniteStateMachine* const fsm) {
    Tungsten_AddRoamStateTransition(*this, *fsm,
        ROAM_TRANSITION_LOOK_AT_SCENEPOINT, ROAM_STATE_FIND);
    Tungsten_AddRoamStateTransition(*this, *fsm,
        ROAM_TRANSITION_MOVE_TO_SCENEPOINT, ROAM_STATE_MOVE_TO);
    Tungsten_AddRoamStateTransition(*this, *fsm,
        ROAM_TRANSITION_IDLE, ROAM_STATE_IDLE);
    Tungsten_AddRoamStateTransition(*this, *fsm,
        ROAM_TRANSITION_FIND_SCENEPOINT, ROAM_STATE_FIND);
}

// EA: 0x82AED990
void idRoamScenePoint_MoveTo::InternalInitState(
        const idFiniteStateMachine* const fsm) {
    Tungsten_AddRoamStateTransition(*this, *fsm,
        ROAM_TRANSITION_LOOK_AT_SCENEPOINT, ROAM_STATE_MOVE_TO);
    Tungsten_AddRoamStateTransition(*this, *fsm,
        ROAM_TRANSITION_STAY_AT_SCENEPOINT, ROAM_STATE_STAY_AT);
    Tungsten_AddRoamStateTransition(*this, *fsm,
        ROAM_TRANSITION_FIND_SCENEPOINT, ROAM_STATE_FIND);
}

// EA: 0x82AEDA10
void idRoamScenePoint_StayAt::InternalInitState(
        const idFiniteStateMachine* const fsm) {
    Tungsten_AddRoamStateTransition(*this, *fsm,
        ROAM_TRANSITION_LOOK_AT_SCENEPOINT, ROAM_STATE_STAY_AT);
    Tungsten_AddRoamStateTransition(*this, *fsm,
        ROAM_TRANSITION_FIND_SCENEPOINT, ROAM_STATE_FIND);
}

// EA: 0x82AEDA78
void idRoamScenePoint_SharedWaitForAnimation::InternalInitState(
        const idFiniteStateMachine* const fsm) {
    Tungsten_AddRoamStateTransition(*this, *fsm,
        ROAM_TRANSITION_SHARED_FINISHED, ROAM_STATE_SHARED_FINISHED);
}

// EA: 0x82AEDA90
void idRoamScenePoint_SharedFinished::InternalInitState(
        const idFiniteStateMachine* const fsm) {
    Tungsten_AddRoamStateTransition(*this, *fsm,
        ROAM_TRANSITION_IDLE, ROAM_STATE_IDLE);
}

// EA: 0x82AEDAA8
void idRoamScenePointFSM::InitStates(
        const idFiniteStateMachineParams* const params) {
    Tungsten_InitializeRoamFSMStates(*this, params);
    Tungsten_AddRoamFSMState(*this, stateRoamSPIdle);
    Tungsten_AddRoamFSMState(*this, stateRoamSPFind);
    Tungsten_AddRoamFSMState(*this, stateRoamSPMoveTo);
    Tungsten_AddRoamFSMState(*this, stateRoamSPStayAt);
    Tungsten_AddRoamFSMState(*this, stateRoamSPSharedFinished);
    Tungsten_AddRoamFSMState(*this, stateRoamSPSharedWaitForAnimation);
}

// EA: 0x82AEDB68
idAIStateTransition::aiTransCode_t RoamScenePoint_Shall_Idle::Evaluate(
        idAI2* const ai, idAIFSM*, idAIState*, int) {
    idRoamAIRuntime runtime{};
    return Tungsten_GetRoamAIRuntime(*ai, runtime)
            && runtime.usesRoamScenePoints
        ? 0 : TRANSCODE_ROAM_SCENEPOINT;
}

// EA: 0x82AEDB80
idAIStateTransition::aiTransCode_t
RoamScenePoint_Shall_MoveToScenePoint::Evaluate(
        idAI2* const ai, idAIFSM* const parentFSM, idAIState*, int) {
    idRoamAIRuntime aiRuntime{};
    idRoamScenePointRuntime pointRuntime{};
    if (!Tungsten_GetRoamAIRuntime(*ai, aiRuntime)
            || !GetPointRuntime(*ai, aiRuntime.currentScenePoint,
                pointRuntime)
            || !pointRuntime.isRoam) {
        return 0;
    }
    idRoamScenePointFSM* const fsm = AsRoamFSM(parentFSM);
    return fsm != nullptr && fsm->stayTime == -1
        ? TRANSCODE_ROAM_SCENEPOINT : 0;
}

// EA: 0x82AEDC00
void idRoamScenePoint_Find::AIState_EnterState(
        idAI2* const ai, idAIFSM* const fsm, int) {
    FindRoamScenePoint(*this, *ai, AsRoamFSM(fsm));
}

// EA: 0x82AEDD60
void idRoamScenePoint_Find::AIState_ReenterState(
        idAI2* const ai, idAIFSM* const fsm, int, int) {
    idRoamAIRuntime aiRuntime{};
    idRoamScenePointRuntime pointRuntime{};
    const bool hasRoamPoint = Tungsten_GetRoamAIRuntime(*ai, aiRuntime)
        && GetPointRuntime(*ai, aiRuntime.currentScenePoint, pointRuntime)
        && pointRuntime.isRoam;
    if (!hasRoamPoint) {
        FindRoamScenePoint(*this, *ai, AsRoamFSM(fsm));
    }
}

// EA: 0x82AEDEF0
void idRoamScenePoint_MoveTo::AIState_EnterState(
        idAI2* const ai, idAIFSM* const fsm, int) {
    idRoamAIRuntime aiRuntime{};
    idRoamScenePointRuntime pointRuntime{};
    if (!Tungsten_GetRoamAIRuntime(*ai, aiRuntime)
            || !GetPointRuntime(*ai, aiRuntime.currentScenePoint,
                pointRuntime)
            || !pointRuntime.isRoam) {
        Tungsten_SetRoamEnterFailed(*this, true);
        return;
    }

    Tungsten_SetRoamAnimationSubWebRelaxed(*ai);
    const bool run = (pointRuntime.scriptFlags & ROAM_SCENEPOINT_SCRIPTED) != 0
        && (pointRuntime.scriptFlags & ROAM_SCENEPOINT_RUN) != 0;
    Tungsten_SetRoamWalkState(*ai, run ? 2 : 1);
    Tungsten_SetRoamHeadTracking(*ai, true);
    Tungsten_ClearRoamAimFocus(*ai);
    Tungsten_EndRoamActionScript(*ai);
    if (fsm != nullptr) {
        fsm->actionCallerState = this;
    }

    idRoamMoveCommand command{};
    command.scenePoint = aiRuntime.currentScenePoint;
    command.useScenePoint = true;
    command.offset.Zero();
    command.durationIsZero = pointRuntime.duration == 0.0f;
    command.arrivalRadius = pointRuntime.radius * 0.25f;
    command.arrivalMode = command.durationIsZero ? 2 : 1;
    command.moveFlags = 35;
    Tungsten_StartRoamMoveAction(*ai, *fsm, *this, command);
}

// EA: 0x82AEE148
void idRoamScenePoint_MoveTo::AIState_ExitState(
        idAI2* const ai, idAIFSM*, int) {
    idRoamAIRuntime aiRuntime{};
    idRoamScenePointRuntime pointRuntime{};
    const bool hasPoint = Tungsten_GetRoamAIRuntime(*ai, aiRuntime)
        && GetPointRuntime(*ai, aiRuntime.currentScenePoint, pointRuntime);
    if (!hasPoint || pointRuntime.duration != 0.0f) {
        Tungsten_RestoreRoamIdleAnimation(*ai);
        Tungsten_StopRoamMovement(*ai, 0);
    }
}

// EA: 0x82AEE250
idRoamScenePointFSM::idRoamScenePointFSM()
    : idAIFSM()
    , roamFSMBaseOpaque{}
    , stateRoamSPIdle()
    , stateRoamSPFind()
    , stateRoamSPMoveTo()
    , stateRoamSPStayAt()
    , stateRoamSPSharedWaitForAnimation()
    , stateRoamSPSharedFinished()
    , stayTime(-1)
    , lookTime(-1) {
    Tungsten_InitializeRoamFSMRuntime(*this, "FSM_roamScenePoint");
    Tungsten_SetRoamFSMDefaultState(*this, stateRoamSPFind);
}

// EA: 0x82AEE4C0
idRoamScenePointFSM::~idRoamScenePointFSM() = default;

// EA: 0x82AEE640
idAIStateTransition::aiTransCode_t
RoamScenePoint_Shall_FindScenePoint::Evaluate(
        idAI2* const ai, idAIFSM* const parentFSM, idAIState*,
        const int currentTime) {
    idRoamAIRuntime aiRuntime{};
    if (!Tungsten_GetRoamAIRuntime(*ai, aiRuntime)
            || !aiRuntime.usesRoamScenePoints) {
        return 0;
    }

    idRoamScenePointRuntime pointRuntime{};
    if (GetPointRuntime(*ai, aiRuntime.currentScenePoint, pointRuntime)
            && pointRuntime.isRoam) {
        bool valid = true;
        bool invalidScriptScenePoint = false;
        idRoamScenePointFSM* const fsm = AsRoamFSM(parentFSM);
        if ((pointRuntime.scriptFlags & ROAM_SCENEPOINT_SCRIPTED) != 0) {
            const bool scriptValid = IsScriptScenePointValid(
                ai, aiRuntime.currentScenePoint);
            invalidScriptScenePoint = !scriptValid;
            valid = pointRuntime.type == ROAM && scriptValid;
            if (valid && fsm != nullptr && pointRuntime.duration >= 0.0f
                    && fsm->stayTime >= 0) {
                valid = currentTime <= fsm->stayTime;
            }
            if (valid) {
                valid = (pointRuntime.flags & ROAM_SCENEPOINT_ENABLED) != 0;
            }
            if (valid && aiRuntime.hasOverrideRoamScenePoint) {
                valid = false;
            }
        } else {
            if (fsm != nullptr && pointRuntime.duration >= 0.0f
                    && fsm->stayTime >= 0) {
                valid = currentTime <= fsm->stayTime;
            }
            if (valid) {
                valid = (pointRuntime.flags & ROAM_SCENEPOINT_ENABLED) != 0;
            }
            if (valid && pointRuntime.dirtyScenePoint) {
                valid = false;
            }
            if (valid && !Tungsten_RequestRoamScenePoint(
                    *aiRuntime.currentScenePoint, *ai, currentTime)) {
                valid = false;
            }
            if (valid && aiRuntime.hasOverrideRoamScenePoint) {
                valid = false;
            }
        }

        if (!valid) {
            if (fsm != nullptr) {
                fsm->stayTime = -1;
            }
            if (invalidScriptScenePoint) {
                Tungsten_ClearRoamScenePointHistory(*ai);
            } else {
                Tungsten_UpdateRoamScenePointHistory(
                    *ai, *aiRuntime.currentScenePoint);
            }
            Tungsten_ReleaseRoamScenePoint(
                *aiRuntime.currentScenePoint, *ai);
            Tungsten_SetRoamCurrentScenePoint(*ai, nullptr);
            return TRANSCODE_ROAM_SCENEPOINT;
        }
        return 0;
    }

    if (aiRuntime.hasOverrideRoamScenePoint) {
        return TRANSCODE_ROAM_SCENEPOINT;
    }
    if (!aiRuntime.hasScenePointVolumes) {
        return 0;
    }
    return SearchIntervalElapsed(aiRuntime.lastScenePointSearchTime,
        currentTime) ? TRANSCODE_ROAM_SCENEPOINT : 0;
}

// EA: 0x82AEE928
idAIStateTransition::aiTransCode_t
RoamScenePoint_Shall_StayAtScenePoint::Evaluate(
        idAI2* const ai, idAIFSM*, idAIState*, const int currentTime) {
    idRoamAIRuntime aiRuntime{};
    idRoamScenePointRuntime pointRuntime{};
    if (Tungsten_GetRoamAIRuntime(*ai, aiRuntime)
            && GetPointRuntime(*ai, aiRuntime.currentScenePoint,
                pointRuntime)
            && pointRuntime.isRoam) {
        if (aiRuntime.moveStatus == 0) {
            return TRANSCODE_ROAM_SCENEPOINT;
        }
        if (aiRuntime.moveStatus != 1) {
            idScenePoint* const point = aiRuntime.currentScenePoint;
            Tungsten_DisableUnreachableRoamScenePoint(*point, *ai,
                currentTime + 10000, aiRuntime.moveStatus,
                (pointRuntime.scriptFlags & ROAM_SCENEPOINT_SCRIPTED) != 0);
            Tungsten_SetRoamCurrentScenePoint(*ai, nullptr);
            Tungsten_RestoreRoamIdleAnimation(*ai);
            Tungsten_StopRoamMovement(*ai, 0);
        }
    }
    return 0;
}

// EA: 0x82AEEAC0
idAIStateTransition::aiTransCode_t
RoamScenePoint_Shall_LookAtScenePoint::Evaluate(
        idAI2* const ai, idAIFSM* const parentFSM, idAIState*,
        const int currentTime) {
    idRoamAIRuntime aiRuntime{};
    if (!Tungsten_GetRoamAIRuntime(*ai, aiRuntime)
            || !aiRuntime.usesLookScenePoints) {
        return 0;
    }

    idRoamScenePointFSM* const fsm = AsRoamFSM(parentFSM);
    idRoamScenePointRuntime lookRuntime{};
    if (GetPointRuntime(*ai, aiRuntime.currentLookScenePoint, lookRuntime)
            && lookRuntime.isLook) {
        bool valid = lookRuntime.type == LOOK
            && (lookRuntime.flags & ROAM_SCENEPOINT_ENABLED) != 0
            && (lookRuntime.lookFlags & ROAM_LOOKFLAG_RELAXED) != 0;
        if (valid && fsm != nullptr && lookRuntime.duration >= 0.0f
                && fsm->lookTime >= 0) {
            valid = currentTime <= fsm->lookTime;
        }
        if (valid && lookRuntime.dirtyLookScenePoint) {
            valid = false;
        }
        if (valid && !Tungsten_RequestRoamScenePoint(
                *aiRuntime.currentLookScenePoint, *ai, currentTime)) {
            valid = false;
        }
        if (valid && !lookRuntime.inArc) {
            valid = false;
        }
        if (!valid) {
            if (fsm != nullptr) {
                fsm->lookTime = -1;
            }
            Tungsten_ClearRoamLookFocus(*ai);
            Tungsten_UpdateRoamLookScenePointHistory(
                *ai, *aiRuntime.currentLookScenePoint);
            Tungsten_ReleaseRoamScenePoint(
                *aiRuntime.currentLookScenePoint, *ai);
            Tungsten_SetRoamCurrentLookScenePoint(*ai, nullptr);
        }
        return 0;
    }

    if (!SearchIntervalElapsed(aiRuntime.lastLookScenePointSearchTime,
            currentTime)) {
        return 0;
    }

    idRoamScenePointRuntime roamRuntime{};
    const bool hasScriptRoamPoint = GetPointRuntime(*ai,
            aiRuntime.currentScenePoint, roamRuntime)
        && roamRuntime.isRoam
        && (roamRuntime.flags & ROAM_SCENEPOINT_ENABLED) != 0
        && (roamRuntime.scriptFlags & ROAM_SCENEPOINT_SCRIPTED) != 0;

    if (aiRuntime.hasScenePointVolumes && !hasScriptRoamPoint) {
        const idAIPos focus(aiRuntime.aiOrigin);
        idScenePoint* const point = GetBestScenePoint(ai,
            aiRuntime.lookMinRange, aiRuntime.lookMaxRange, focus,
            LOOK, static_cast<scenePointLookFlags_t>(
                ROAM_LOOKFLAG_RELAXED));
        idRoamScenePointRuntime pointRuntime{};
        if (GetPointRuntime(*ai, point, pointRuntime)) {
            SelectRoamLookPoint(*ai, fsm, *point, pointRuntime,
                currentTime);
        }
        return 0;
    }

    if (hasScriptRoamPoint && roamRuntime.nextLookScenePoint != nullptr) {
        idRoamScenePointRuntime pointRuntime{};
        idScenePoint* const point = roamRuntime.nextLookScenePoint;
        if (GetPointRuntime(*ai, point, pointRuntime)
                && pointRuntime.isLook
                && (pointRuntime.scriptFlags & ROAM_SCENEPOINT_SCRIPTED) != 0
                && (pointRuntime.lookFlags & ROAM_LOOKFLAG_RELAXED) != 0
                && pointRuntime.inArc) {
            SelectRoamLookPoint(*ai, fsm, *point, pointRuntime,
                currentTime);
        }
    }
    return 0;
}

// EA: 0x82AEEEE0
void idRoamScenePoint_StayAt::AIState_EnterState(
        idAI2* const ai, idAIFSM* const parentFSM,
        const int currentTime) {
    idRoamAIRuntime aiRuntime{};
    idRoamScenePointRuntime pointRuntime{};
    if (!Tungsten_GetRoamAIRuntime(*ai, aiRuntime)
            || !GetPointRuntime(*ai, aiRuntime.currentScenePoint,
                pointRuntime)
            || !pointRuntime.isRoam) {
        Tungsten_SetRoamEnterFailed(*this, true);
        return;
    }

    idRoamScenePointFSM* const fsm = AsRoamFSM(parentFSM);
    if (fsm != nullptr && fsm->stayTime == -1) {
        Tungsten_ActivateRoamScenePoint(
            *aiRuntime.currentScenePoint, *ai, currentTime);
        const int durationMilliseconds =
            static_cast<int>(pointRuntime.duration * 1000.0f);
        fsm->stayTime = durationMilliseconds < 0
            ? ROAM_SCENEPOINT_INDEFINITE_TIME
            : currentTime + durationMilliseconds;
    }
    if (pointRuntime.scenePointAnimation != nullptr
            && pointRuntime.scenePointAnimation[0] != '\0'
            && Tungsten_PlayRoamAnimWebPath(*ai,
                pointRuntime.scenePointAnimation, false) != 1) {
        Tungsten_WarnRoamAnimationFailure(
            *ai, *aiRuntime.currentScenePoint);
    }
}

// EA: 0x82AEF028
bool idRoamScenePointFSM::CanUse(
        idFiniteStateMachine* const fsm, int) const {
    if (fsm == nullptr) {
        return false;
    }
    idAI2* const ai = Tungsten_GetRoamFSMOwner(*fsm);
    idRoamAIRuntime aiRuntime{};
    if (ai == nullptr || !Tungsten_GetRoamAIRuntime(*ai, aiRuntime)
            || !aiRuntime.usesRoamScenePoints) {
        return false;
    }
    if (aiRuntime.hasOverrideRoamScenePoint) {
        return true;
    }
    idRoamScenePointRuntime pointRuntime{};
    if (GetPointRuntime(*ai, aiRuntime.currentScenePoint, pointRuntime)
            && (pointRuntime.flags & ROAM_SCENEPOINT_ENABLED) != 0
            && (pointRuntime.scriptFlags & ROAM_SCENEPOINT_SCRIPTED) != 0
            && pointRuntime.type == ROAM) {
        return true;
    }
    if (aiRuntime.hasSquadLeader) {
        return false;
    }
    return !aiRuntime.awareOfEnemy;
}
