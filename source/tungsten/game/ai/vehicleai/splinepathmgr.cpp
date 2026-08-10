#include "splinepathmgr.h"

#include <algorithm>
#include <cmath>

namespace {

float AngleDelta(const float destination, const float source) {
    float delta = std::fmod(destination - source, 360.0f);
    if (delta < 0.0f) {
        delta += 360.0f;
    }
    if (delta > 180.0f) {
        delta -= 360.0f;
    }
    return delta;
}

bool SameText(const char* const left, const char* const right) {
    return idStr::Cmp(left, right) == 0;
}

idVehicleAI* FindAdjacentVehicleAI(idVehicleAI* const current,
        const bool moveForward) {
    const int count = Tungsten_GetVehicleAICount();
    if (count <= 0) {
        return current;
    }

    int currentIndex = -1;
    for (int index = 0; index < count; ++index) {
        if (Tungsten_GetVehicleAI(index) == current) {
            currentIndex = index;
            break;
        }
    }

    if (currentIndex < 0) {
        currentIndex = moveForward ? count - 1 : 0;
    }
    for (int offset = 1; offset <= count; ++offset) {
        int index = moveForward
            ? (currentIndex + offset) % count
            : (currentIndex - offset + count * 2) % count;
        idVehicleAI* const candidate = Tungsten_GetVehicleAI(index);
        if (candidate == current || (candidate != nullptr
                && Tungsten_IsVehicleAIValid(*candidate))) {
            return candidate;
        }
    }
    return current;
}

void AppendFloat(idStr& text, const float value) {
    idStr number;
    number.Format("%g", value);
    text.Append(number);
}

idStr BuildObstacleFlags(const int flags) {
    if (flags == 0) {
        return idStr("None");
    }
    idStr result;
    if ((flags & 1) != 0) result.Append(" FRONT");
    if ((flags & 2) != 0) result.Append(" RIGHT");
    if ((flags & 4) != 0) result.Append(" LEFT");
    if ((flags & 8) != 0) result.Append(" REAR");
    return result;
}

idStr BuildSpeedFlags(const idAISplineVehicleStats& stats) {
    if (stats.speedFlags == 0) {
        return idStr("None");
    }
    idStr result;
    if ((stats.speedFlags & 1) != 0) {
        result.Append(" STOP DISTANCE .");
    }
    if ((stats.speedFlags & 2) != 0) {
        result.Append(" DECEL DISTANCE .");
    }
    if ((stats.speedFlags & 4) != 0) {
        result.Append(" MOVE DISTANCE .");
    }
    if ((stats.speedFlags & 8) != 0) {
        result.Append(" TURN SPEED . ");
        AppendFloat(result, stats.turnSpeedRatio);
    }
    if ((stats.speedFlags & 0x10) != 0) {
        result.Append(" CURVE SPEED");
    }
    if ((stats.speedFlags & 0x20) != 0) {
        result.Append(" FRONT OBSTRUCTION");
    }
    return result;
}

idStr BuildSteerFlags(const int flags) {
    idStr result;
    if ((flags & 1) != 0) {
        result.Append(" OPPOSITE");
    }
    if ((flags & 2) != 0) {
        if (flags != 2) {
            result.Append(" +");
        }
        result.Append(" NARROW PATH");
    }
    return result;
}

float DegreesFromCosine(const float cosine) {
    const float clamped = (std::max)(-1.0f, (std::min)(1.0f, cosine));
    return std::acos(clamped) * 57.29577951308232f;
}

bool BoundsIntersectPlayerCube(const idAISplineNavSpline& spline,
        const idVec3& playerOrigin) {
    constexpr float radius = 1000.0f;
    return spline.boundsMaxs.x >= playerOrigin.x - radius
        && spline.boundsMaxs.y >= playerOrigin.y - radius
        && spline.boundsMaxs.z >= playerOrigin.z - radius
        && spline.boundsMins.x <= playerOrigin.x + radius
        && spline.boundsMins.y <= playerOrigin.y + radius
        && spline.boundsMins.z <= playerOrigin.z + radius;
}

} // namespace

// Retail symbol: ??0idAISplinePathMgr@@QAA@XZ
// EA: 0x82B05DB8, RVA: 0x00B05DB8
idAISplinePathMgr::idAISplinePathMgr()
    : updatetime(0.0f)
    , nextRecalcTime(0)
    , trackerPool(0)
    , usedTrackers(0)
    , null_splineTracker()
    , tempNavSpline()
    , dormancyList(0)
    , navSplineType(NAV_SPLINE_TYPE_VEHICLE_AI)
    , tempNavSplinePathName("tempVehAISplinePath")
    , trackPickups(false)
    , numVehiclePickups(0)
    , debugTracker(nullptr)
    , currentViewAngles(0.0f, 0.0f, 0.0f)
    , lastCarAngles(0.0f, 0.0f, 0.0f)
    , wildSpinTime(0)
    , viewAnglesDeltaPerc(0.0f)
    , lastDrawTime(0)
    , navSplinePathTimerTicks(0)
    , navSplinePathCount(0)
    , navSplinePathCount2(0)
    , navSplineTrackerTimerTicks(0)
    , navSplineTrackerCount(0)
    , navSplineClosestPosTimerTicks(0)
    , navSplineClosestPosCount(0)
    , navSplineClosestPosSectionTimerTicks(0)
    , navSplineClosestPosSectionCount(0) {
}

// Retail symbol: ?CycleFollow@idAISplinePathMgr@@AAAXXZ
// EA: 0x82B04FC8, RVA: 0x00B04FC8
void idAISplinePathMgr::CycleFollow() {
    idAISplineRuntimeOptions options;
    Tungsten_GetAISplineRuntimeOptions(options);
    if (SameText(options.follow.c_str(), "any")
        || SameText(options.follow.c_str(), "1")) {
        if (Tungsten_GetVehicleAICount() > 0) {
            idVehicleAI* const first = Tungsten_GetVehicleAI(0);
            if (first != nullptr) {
                Tungsten_SetAISplineFollowName(
                    Tungsten_GetVehicleAIName(*first));
            }
        }
        return;
    }

    if (!options.next && !options.previous) {
        return;
    }
    idVehicleAI* const current =
        Tungsten_FindVehicleAI(options.follow.c_str());
    if (current == nullptr) {
        Tungsten_SetAISplineFollowName("any");
        return;
    }

    idVehicleAI* selected = current;
    if (options.next) {
        Tungsten_ClearAISplineNext();
        selected = FindAdjacentVehicleAI(current, true);
    } else {
        Tungsten_ClearAISplinePrevious();
        selected = FindAdjacentVehicleAI(current, false);
    }
    if (selected != nullptr) {
        Tungsten_SetAISplineFollowName(Tungsten_GetVehicleAIName(*selected));
    }
}

// Retail symbol: ?UpdateTrackersPeriodic@idAISplinePathMgr@@AAAXAAV?$idList@H$04@@H_N@Z
// EA: 0x82B052F8, RVA: 0x00B052F8
void idAISplinePathMgr::UpdateTrackersPeriodic(
        const idList<int, 5>& indexList, int frequencyInFrames,
        const bool fastUpdateOthers) {
    if (usedTrackers.Num() <= 0 || indexList.Num() <= 0
        || frequencyInFrames <= 0) {
        return;
    }
    frequencyInFrames = (std::min)(frequencyInFrames, indexList.Num());
    const int updateCount = indexList.Num() / frequencyInFrames;
    if (updateCount <= 0) {
        return;
    }
    const int start = (Tungsten_GetAISplineGameFrame()
        % indexList.Num()) / updateCount * updateCount;

    const int first = fastUpdateOthers ? 0 : start;
    const int last = fastUpdateOthers
        ? indexList.Num() : (std::min)(indexList.Num(), start + updateCount);
    for (int listIndex = first; listIndex < last; ++listIndex) {
        const int usedIndex = indexList[listIndex];
        if (usedIndex < 0 || usedIndex >= usedTrackers.Num()) {
            continue;
        }
        const int trackerIndex = usedTrackers[usedIndex];
        if (trackerIndex < 0 || trackerIndex >= trackerPool.Num()) {
            continue;
        }
        idAISplineTracker& tracker = trackerPool[trackerIndex];
        if (tracker.owner == nullptr
            || tracker.pathPosition.navSpline == nullptr) {
            continue;
        }
        idVec3 position;
        if (!Tungsten_GetAISplineEntityOrigin(*tracker.owner, position)) {
            continue;
        }
        Tungsten_SetAISplineTrackerWorldPosition(tracker, position);
        const bool fullUpdate = listIndex >= start
            && listIndex < start + updateCount;
        Tungsten_UpdateAISplineTracker(tracker,
            fastUpdateOthers ? fullUpdate : true);
    }
}

// Retail symbol: ?GetDebugAiView@idAISplinePathMgr@@QAA_NAAVidVec3@@AAVidMat3@@AAM@Z
// EA: 0x82B05560, RVA: 0x00B05560
bool idAISplinePathMgr::GetDebugAiView(
        idVec3& origin, idMat3& axis, float& fovX) {
    (void)fovX;
    idAISplineRuntimeOptions options;
    Tungsten_GetAISplineRuntimeOptions(options);
    idVehicleAI* const vehicleAI =
        Tungsten_FindVehicleAI(options.follow.c_str());
    if (vehicleAI == nullptr) {
        return false;
    }

    idAISplineDebugCameraState state;
    if (!Tungsten_GetAISplineDebugCameraState(*vehicleAI, state)) {
        return false;
    }
    const int elapsed = state.forceFrameStep
        ? state.frameMilliseconds : state.scaledTime - lastDrawTime;
    if (elapsed == 0 || state.frameMilliseconds == 0) {
        return false;
    }
    const float frameScale = static_cast<float>(elapsed)
        / static_cast<float>(state.frameMilliseconds);
    lastDrawTime = state.scaledTime;

    idAngles desired;
    if (state.freeCamera) {
        desired = state.freeAngles;
    } else {
        desired.pitch = state.vehicleAngles.pitch
            + state.placementPitch + state.cameraPitch;
        desired.yaw = state.vehicleAngles.yaw + state.cameraYaw;
        desired.roll = 0.0f;
    }

    const bool wild = std::fabs(AngleDelta(
            state.vehicleAngles.yaw, lastCarAngles.yaw)) >= state.wildYaw
        || std::fabs(AngleDelta(state.vehicleAngles.pitch,
            lastCarAngles.pitch)) >= state.wildPitch
        || std::fabs(AngleDelta(state.vehicleAngles.roll,
            lastCarAngles.roll)) >= state.wildRoll;
    if (wild) {
        wildSpinTime += 2 * state.frameMilliseconds
            * static_cast<int>(frameScale);
        wildSpinTime = (std::min)(wildSpinTime, state.scaledTime + 1000);
    } else {
        if (wildSpinTime > state.scaledTime) {
            viewAnglesDeltaPerc = 0.01f;
        } else {
            if (viewAnglesDeltaPerc < 0.1f) {
                viewAnglesDeltaPerc = (std::min)(0.1f,
                    viewAnglesDeltaPerc + state.recoverRate * frameScale);
            }
            wildSpinTime = state.scaledTime;
        }
        currentViewAngles.yaw += viewAnglesDeltaPerc
            * AngleDelta(desired.yaw, currentViewAngles.yaw) * frameScale;
        currentViewAngles.pitch += viewAnglesDeltaPerc
            * AngleDelta(desired.pitch, currentViewAngles.pitch) * frameScale;
        currentViewAngles.Normalize180();
    }
    lastCarAngles = state.vehicleAngles;

    origin = state.vehicleOrigin;
    origin.z += state.cameraHeight + 8.0f;
    idAngles cameraAngles = currentViewAngles;
    cameraAngles.pitch = (std::max)(cameraAngles.pitch, state.minimumPitch);
    axis = cameraAngles.ToMat3();

    constexpr float degreesToRadians = 0.01745329251994329577f;
    const float placementRadians = state.placementYaw * degreesToRadians;
    origin = origin - axis[0]
        * (std::cos(placementRadians) * state.cameraRange);
    origin = origin + axis[1]
        * (std::sin(placementRadians) * state.cameraRange);

    idAISplineCameraTrace trace;
    Tungsten_TraceAISplineCamera(state.vehicleOrigin, origin, trace);
    if (trace.fraction != 1.0f && !trace.startSolid) {
        origin = trace.endPosition;
        origin.z += (1.0f - trace.fraction) * 32.0f;
        Tungsten_TraceAISplineCamera(state.vehicleOrigin, origin, trace);
        origin = trace.endPosition;
    }

    const idVec3 lookTarget = state.vehicleOrigin
        + currentViewAngles.ToForward() * 512.0f
        + idVec3(0.0f, 0.0f, state.cameraHeight);
    axis[0] = lookTarget - origin;
    axis[2] = state.gravityNormal;
    axis[1] = axis[0].Cross(axis[2]);
    axis.OrthoNormalizeSelf();
    return true;
}

// Retail symbol: ?ShowVehicleAiStats@idAISplinePathMgr@@AAAXXZ
// EA: 0x82B05FB8, RVA: 0x00B05FB8
void idAISplinePathMgr::ShowVehicleAiStats() {
    idAISplineRuntimeOptions options;
    Tungsten_GetAISplineRuntimeOptions(options);
    idVehicleAI* const vehicleAI =
        Tungsten_FindVehicleAI(options.follow.c_str());
    if (vehicleAI == nullptr || options.stats == 0) {
        return;
    }

    idAISplineVehicleStats stats;
    Tungsten_GetAISplineVehicleStats(*vehicleAI, stats);
    if (!SameText(options.follow.c_str(), stats.name.c_str())) {
        if (stats.ownerName.IsEmpty()
            || !SameText(options.follow.c_str(), stats.ownerName.c_str())) {
            return;
        }
        Tungsten_SetAISplineFollowName(stats.name.c_str());
    }

    const idStr obstacleFlags = BuildObstacleFlags(stats.obstacleFlags);
    const idStr speedFlags = BuildSpeedFlags(stats);
    const idStr steerFlags = BuildSteerFlags(stats.steerFlags);
    Tungsten_PrintAISplineDebugHUD("\n^3-- VEHICLE AI STATS --\n");
    Tungsten_PrintAISplineDebugHUD("^7 name: ^5%s\n", stats.name.c_str());
    if (!stats.valid) {
        Tungsten_PrintAISplineDebugHUD("^7owner: ** INVALID **\n");
        return;
    }

    Tungsten_PrintAISplineDebugHUD("^7  num: ^5%d\n", stats.entityNumber);
    Tungsten_PrintAISplineDebugHUD("^7owner: %s\n",
        stats.ownerName.IsEmpty() ? "none" : stats.ownerName.c_str());
    Tungsten_PrintAISplineDebugHUD("^7     Steering: ^2% 6.1f %s\n",
        stats.desiredSteering, steerFlags.c_str());
    Tungsten_PrintAISplineDebugHUD("^7      Braking:     ^2% 1d\n",
        stats.desiredBraking);
    Tungsten_PrintAISplineDebugHUD("^7  Speed Limit: ^2% 6.0f\n",
        stats.speedLimit);
    Tungsten_PrintAISplineDebugHUD("^7Desired Speed: ^2% 6.0f ( %s )\n",
        stats.desiredSpeed, speedFlags.c_str());
    Tungsten_PrintAISplineDebugHUD("^7 Actual Speed: ^2% 6.0f\n",
        stats.actualSpeed);
    Tungsten_PrintAISplineDebugHUD("^7   Right Dist: ^2% 6.0f\n",
        stats.rightDistance);
    Tungsten_PrintAISplineDebugHUD("^7  Spline Pos: ^2% 6.0f\n",
        stats.splineDistance);
    Tungsten_PrintAISplineDebugHUD("^7Spline Obstcl: ^2%s\n",
        obstacleFlags.c_str());
    Tungsten_PrintAISplineDebugHUD("^7 id Obstacles: ^2%s\n",
        stats.idObstacles.c_str());
    Tungsten_PrintAISplineDebugHUD(
        "^7  Is Dormant?: ^2%s   ^7( AI Specific? ^2%s^7 )\n",
        stats.dormant ? "Yes" : "No",
        stats.aiSpecificDormancy ? "Yes" : "No");
    if (stats.hasVehicleCar) {
        Tungsten_PrintAISplineDebugHUD("\n^7       Health: ^2%3.1f\n",
            stats.health);
    }

    static const char* const difficultyNames[] = {
        "DIFFICULTY_LOW", "DIFFICULTY_MED", "DIFFICULTY_HIGH"
    };
    if (stats.difficultyLevel >= 0 && stats.difficultyLevel <= 2) {
        Tungsten_PrintAISplineDebugHUD("\n^7DIFFICULTY: ^2%s\n",
            difficultyNames[stats.difficultyLevel]);
        Tungsten_PrintAISplineDebugHUD("^7    Attack: ^2%f\n",
            stats.difficultyAttackScale);
        Tungsten_PrintAISplineDebugHUD("^7  DmgGiven: ^2%f\n",
            stats.difficultyDamageScale);
        Tungsten_PrintAISplineDebugHUD("^7     Speed: ^2%f\n",
            stats.difficultySpeedRate);
        Tungsten_PrintAISplineDebugHUD("^7  Accuracy: ^2%f\n",
            stats.difficultyAccuracy);
        Tungsten_PrintAISplineDebugHUD("^7  DmgTaken: ^2%f\n",
            stats.difficultyDamageTakenScale);
    }

    static const char* const avoidanceNames[] = {
        "OAT_INIT", "OAT_GENERAL", "OAT_RACE", "OAT_NONE"
    };
    const int avoidanceIndex = stats.avoidanceType >= 0
            && stats.avoidanceType < 4 ? stats.avoidanceType : 3;
    Tungsten_PrintAISplineDebugHUD("\n^7CONTROL VARS\n");
    Tungsten_PrintAISplineDebugHUD("^7          Speed Limit: ^2%f\n",
        stats.speedLimit);
    Tungsten_PrintAISplineDebugHUD("^7        Stop Distance: ^2%f\n",
        stats.stopDistance);
    Tungsten_PrintAISplineDebugHUD("^7        Move Distance: ^2%f\n",
        stats.moveDistance);
    Tungsten_PrintAISplineDebugHUD("^7       Decel Distance: ^2%f\n",
        stats.decelDistance);
    Tungsten_PrintAISplineDebugHUD("^7       Max Curve Speed: ^2%f\n",
        stats.maxCurveSpeed);
    Tungsten_PrintAISplineDebugHUD("^7       Max Curve Angle: ^2%f\n",
        DegreesFromCosine(stats.maxCurveCosine));
    Tungsten_PrintAISplineDebugHUD("^7       Max Step Angle: ^2%f\n",
        DegreesFromCosine(stats.maxStepCosine));
    Tungsten_PrintAISplineDebugHUD("^7       Avoidance Type: ^2%s\n",
        avoidanceNames[avoidanceIndex]);
    Tungsten_PrintAISplineDebugHUD("^7     Power Turn Speed: ^2%f\n",
        stats.powerTurnSpeed);
    Tungsten_PrintAISplineDebugHUD("^7      Power Turn Time: ^2%f\n",
        stats.powerTurnTime);
    Tungsten_PrintAISplineDebugHUD("^7Stop Power Turn Speed: ^2%f\n",
        stats.stopPowerTurnSpeed);
    Tungsten_PrintAISplineDebugHUD("^7   Traversal Step Size: ^2%f\n",
        stats.traversalStepSize);
    Tungsten_PrintAISplineDebugHUD("^7         Backup Speed: ^2%f\n",
        stats.backupSpeed);
    Tungsten_PrintAISplineDebugHUD("\n^7Decision State: ^2%s\n",
        stats.decisionState.c_str());
    Tungsten_PrintAISplineDebugHUD("^7Movement State: ^2%s\n",
        stats.movementState.c_str());
    Tungsten_PrintAISplineDebugHUD("^7  Attack State: ^2%s\n",
        stats.attackState.c_str());
    Tungsten_PrintAISplineDebugHUD("^7         Enemy: ^2%s\n",
        stats.enemyName.IsEmpty() ? "---" : stats.enemyName.c_str());
    Tungsten_PrintAISplineDebugHUD("\n^7 Command State: ^2%s\n",
        stats.commandState.c_str());
    if (!stats.hasPathToGoal) {
        Tungsten_PrintAISplineDebugHUD(
            "\nDist To Goal: ^1*** NO PATH TO GOAL ***\n");
    } else {
        Tungsten_PrintAISplineDebugHUD(
            "\nDist To Goal: ^2% 5.0f    ( % 5.0f )\n",
            stats.distanceToGoal, stats.pathDistanceToGoal);
    }
    if (options.disablePathing) {
        Tungsten_PrintAISplineDebugHUD("^2 *** PATHING DISABLED ***\n");
    } else {
        for (int index = 0; index < stats.path.Num(); ++index) {
            Tungsten_PrintAISplineDebugHUD("^2%s  -  % 6.0f\n",
                stats.path[index].name.c_str(),
                stats.path[index].distance);
        }
    }
}

// Retail symbol: ?DrawWaypoints@idAISplinePathMgr@@AAAXXZ
// EA: 0x82B06F68, RVA: 0x00B06F68
void idAISplinePathMgr::DrawWaypoints() {
    const int waypointCount = Tungsten_GetAISplineWaypointCount();
    for (int waypointIndex = 0;
            waypointIndex < waypointCount; ++waypointIndex) {
        if (!Tungsten_IsAISplineWaypoint(waypointIndex)) {
            continue;
        }
        idAISplinePathPosition waypointPosition;
        if (!Tungsten_GetAISplineWaypointPosition(
                waypointIndex, waypointPosition)) {
            continue;
        }
        const int targetCount =
            Tungsten_GetAISplineWaypointTargetCount(waypointIndex);
        for (int targetIndex = 0; targetIndex < targetCount; ++targetIndex) {
            idAISplinePathPosition targetPosition;
            if (Tungsten_GetAISplineWaypointTargetPosition(
                    waypointIndex, targetIndex, targetPosition)) {
                Tungsten_DrawAISplineWaypointArrow(
                    Tungsten_GetAISplinePositionWorldPoint(
                        waypointPosition, false),
                    Tungsten_GetAISplinePositionWorldPoint(
                        targetPosition, false));
            }
        }
        if (waypointPosition.navSpline != nullptr) {
            const idVec3 world = Tungsten_GetAISplinePositionWorldPoint(
                waypointPosition, false);
            Tungsten_DrawAISplineWaypointSphere(world, 20.0f);
            Tungsten_DrawAISplineWaypointArrow(world,
                Tungsten_GetAISplinePositionWorldPoint(
                    waypointPosition, true));
        }
    }
}

// Retail symbol: ?SetupWaypoints@idAISplinePathMgr@@QAAXXZ
// EA: 0x82B07238, RVA: 0x00B07238
void idAISplinePathMgr::SetupWaypoints() {
    if ((Tungsten_GetAISplineGameFlags() & 2) != 0) {
        return;
    }
    const int waypointCount = Tungsten_GetAISplineWaypointCount();
    for (int waypointIndex = 0;
            waypointIndex < waypointCount; ++waypointIndex) {
        if (!Tungsten_IsAISplineWaypoint(waypointIndex)) {
            continue;
        }
        idVec3 origin;
        if (!Tungsten_GetAISplineWaypointOrigin(waypointIndex, origin)) {
            continue;
        }

        idAISplineNavSpline* selectedSpline = nullptr;
        const int targetCount =
            Tungsten_GetAISplineWaypointTargetCount(waypointIndex);
        for (int targetIndex = 0; targetIndex < targetCount; ++targetIndex) {
            idStr pathName;
            if (!Tungsten_GetAISplineWaypointTargetPathName(
                    waypointIndex, targetIndex, pathName)) {
                continue;
            }
            idAISplineNavSpline* const candidate =
                Tungsten_FindAISplineNavSpline(pathName.c_str(), true);
            if (candidate != nullptr && candidate->hasSplinePath
                && candidate->type == navSplineType) {
                selectedSpline = candidate;
                break;
            }
        }

        if (targetCount > 0 && selectedSpline == nullptr) {
            const idAISplinePathPosition coarse =
                Tungsten_GetClosestAISplinePathPosition(
                    origin, nullptr, 1000.0f, 0.1f);
            selectedSpline = coarse.navSpline;
        }
        if (selectedSpline != nullptr && !selectedSpline->hasSplinePath) {
            Tungsten_WarnUnassociatedAISplineWaypoint(
                Tungsten_GetAISplineWaypointName(waypointIndex));
            continue;
        }
        const idAISplinePathPosition position =
            Tungsten_GetClosestAISplinePathPosition(
                origin, selectedSpline, 1000.0f, 0.01f);
        Tungsten_SetAISplineWaypointPosition(waypointIndex, position);
    }
}

// Retail symbol: ?SpecialSetup@idAISplinePathMgr@@UAAXXZ
// EA: 0x82B07610, RVA: 0x00B07610
void idAISplinePathMgr::SpecialSetup() {
    SetupWaypoints();
    tempNavSpline.type = NAV_SPLINE_TYPE_VEHICLE_AI;
    tempNavSpline.name = tempNavSplinePathName;
    null_splineTracker.owner = nullptr;
    null_splineTracker.navSplineType = NAV_SPLINE_TYPE_VEHICLE_AI;
    null_splineTracker.pathPosition.navSpline = &tempNavSpline;
}

// Retail symbol: ?CanFindEnemy@idAISplinePathMgr@@QAA_NPAVidVehicleAI@@@Z
// EA: 0x82B07658, RVA: 0x00B07658
bool idAISplinePathMgr::CanFindEnemy(idVehicleAI* const vehicleAI) {
    const int count = dormancyList.Num();
    if (count == 0) {
        return true;
    }
    const int selectedIndex = Tungsten_GetAISplineGameFrame() % count;
    for (int index = 0; index < count; ++index) {
        if (Tungsten_ResolveAISplineVehicleSpawnId(
                dormancyList[index].spawnId) == vehicleAI) {
            return index == selectedIndex;
        }
    }
    return true;
}

// Retail symbol: ?RemoveFromDormancyList@idAISplinePathMgr@@QAAXPAVidVehicleAI@@@Z
// EA: 0x82B07760, RVA: 0x00B07760
void idAISplinePathMgr::RemoveFromDormancyList(
        idVehicleAI* const vehicleAI) {
    for (int index = 0; index < dormancyList.Num(); ++index) {
        if (Tungsten_ResolveAISplineVehicleSpawnId(
                dormancyList[index].spawnId) == vehicleAI) {
            dormancyList.RemoveIndexFast(index);
        }
    }
}

// Retail symbol: ?Update@idAISplinePathMgr@@UAAXXZ
// EA: 0x82B078A8, RVA: 0x00B078A8
void idAISplinePathMgr::Update() {
    if (!Tungsten_IsAISplineRuntimeAvailable()) {
        return;
    }
    const int initialTime = Tungsten_GetAISplineScaledTime();
    if (static_cast<float>(initialTime) == updatetime) {
        return;
    }

    idAISplineRuntimeOptions options;
    Tungsten_GetAISplineRuntimeOptions(options);
    if (options.trace == 1) {
        Tungsten_BeginAISplineTraceRecording(
            Tungsten_GetAISplineLastError());
    }
    if (options.reset) {
        Tungsten_ResetAISplineVehicles();
        Tungsten_ClearAISplineReset();
    }
    Tungsten_CleanupAISplineEntities(*this);

    if (options.debug || options.timer || options.stats != 0) {
        Tungsten_PrepareAISplineDebugHUD();
    }
    if (options.showAllPaths != 0.0f) {
        const int count = Tungsten_GetAISplineDebugPathCount();
        for (int index = 0; index < count; ++index) {
            idAISplineNavSpline path;
            Tungsten_GetAISplineDebugPath(index, path);
            const bool linked = path.hasStartNode || path.hasEndNode;
            const idVec4 color = linked
                ? idVec4(1.0f, 1.0f, 1.0f, 1.0f)
                : idVec4(0.25f, 0.25f, 0.25f, 0.25f);
            Tungsten_DrawAISplinePath(index, color, 0.0f, path.length,
                options.pathStepSize);
            Tungsten_SetAISplinePathDrawTime(index, 0);
        }
    }
    if (options.showPathBounds) {
        idVec3 playerOrigin;
        if (Tungsten_GetAISplineDebugPlayerOrigin(playerOrigin)) {
            const int count = Tungsten_GetAISplineDebugPathCount();
            for (int index = 0; index < count; ++index) {
                idAISplineNavSpline path;
                Tungsten_GetAISplineDebugPath(index, path);
                const bool nearby = BoundsIntersectPlayerCube(
                    path, playerOrigin);
                const idVec4 color = nearby
                    ? idVec4(0.5f, 0.5f, 0.5f, 1.0f)
                    : idVec4(1.0f, 1.0f, 1.0f, 1.0f);
                Tungsten_DrawAISplineBounds(index, color);
            }
        }
    }
    if (options.debug) {
        if (debugTracker == nullptr) {
            debugTracker = Tungsten_FindAISplineDebugTracker(*this);
            if (debugTracker != nullptr) {
                debugTracker->navSplineType = navSplineType;
                Tungsten_SetAISplineTrackerGoalToCurrent(
                    *debugTracker, false);
            }
        }
        if (options.position && debugTracker != nullptr) {
            Tungsten_ClearAISplinePosition();
            Tungsten_SetAISplineTrackerGoalToCurrent(*debugTracker, false);
        }
        if (debugTracker != nullptr) {
            Tungsten_DrawAISplineDebugTracker(*this, *debugTracker,
                options.pathStepSize, options.disablePathing);
        }
    }

    CycleFollow();
    if (options.stats != 0) {
        ShowVehicleAiStats();
    }
    Tungsten_CycleVehicleFollow();

    if (navSplineType != NAV_SPLINE_TYPE_QUEST) {
        idList<int, 5> vehicles;
        idList<int, 5> pickups;
        idList<int, 5> others;
        for (int usedIndex = 0;
                usedIndex < usedTrackers.Num(); ++usedIndex) {
            const int trackerIndex = usedTrackers[usedIndex];
            if (trackerIndex < 0 || trackerIndex >= trackerPool.Num()) {
                Tungsten_ReleaseAISplineTracker(*this, nullptr);
                continue;
            }
            idAISplineTracker& tracker = trackerPool[trackerIndex];
            if (tracker.owner == nullptr) {
                Tungsten_ReleaseAISplineTracker(*this, &tracker);
                continue;
            }
            switch (Tungsten_GetAISplineTrackerOwnerKind(tracker.owner)) {
                case AI_SPLINE_OWNER_VEHICLE:
                    vehicles.Append(usedIndex);
                    break;
                case AI_SPLINE_OWNER_PICKUP:
                    pickups.Append(usedIndex);
                    break;
                default:
                    others.Append(usedIndex);
                    break;
            }
        }
        numVehiclePickups = pickups.Num();
        UpdateTrackersPeriodic(vehicles, 4, true);
        UpdateTrackersPeriodic(pickups, 30, false);
        UpdateTrackersPeriodic(others, 10, false);
    } else {
        for (int usedIndex = 0;
                usedIndex < usedTrackers.Num(); ++usedIndex) {
            const int trackerIndex = usedTrackers[usedIndex];
            if (trackerIndex < 0 || trackerIndex >= trackerPool.Num()) {
                continue;
            }
            idAISplineTracker& tracker = trackerPool[trackerIndex];
            if (tracker.owner == nullptr) {
                continue;
            }
            idVec3 position;
            if (Tungsten_GetAISplineEntityOrigin(*tracker.owner, position)) {
                Tungsten_SetAISplineTrackerWorldPosition(tracker, position);
                Tungsten_UpdateAISplineTracker(tracker, true);
            }
        }
    }

    if (options.graph) {
        Tungsten_DrawAISplineGraph(*this);
    }
    if (options.waypoints) {
        DrawWaypoints();
    }
    if (options.timer) {
        Tungsten_PrintAISplineTimerStats(*this);
        navSplinePathTimerTicks = 0;
        navSplinePathCount = 0;
        navSplinePathCount2 = 0;
        navSplineTrackerTimerTicks = 0;
        navSplineTrackerCount = 0;
        navSplineClosestPosTimerTicks = 0;
        navSplineClosestPosCount = 0;
        navSplineClosestPosSectionTimerTicks = 0;
        navSplineClosestPosSectionCount = 0;
    }

    updatetime = static_cast<float>(Tungsten_GetAISplineScaledTime());
    if (nextRecalcTime < Tungsten_GetAISplineScaledTime()) {
        nextRecalcTime = Tungsten_GetAISplineScaledTime();
    }
    if (options.trace > 0) {
        Tungsten_SetAISplineTrace(options.trace - 1);
    }
}

// Retail symbol: ?AddToDormancyList@idAISplinePathMgr@@QAAXPAVidVehicleAI@@@Z
// EA: 0x82B08738, RVA: 0x00B08738
void idAISplinePathMgr::AddToDormancyList(
        idVehicleAI* const vehicleAI) {
    for (int index = 0; index < dormancyList.Num(); ++index) {
        if (Tungsten_ResolveAISplineVehicleSpawnId(
                dormancyList[index].spawnId) == vehicleAI) {
            return;
        }
    }
    idAISplineDormancyRef reference;
    reference.spawnId = Tungsten_MakeAISplineVehicleSpawnId(vehicleAI);
    dormancyList.Append(reference);
}
