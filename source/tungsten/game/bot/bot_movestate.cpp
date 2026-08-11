#include "bot_movestate.h"

#include "bot.h"

#include <algorithm>
#include <cmath>

namespace {
idBotMoveStateServices* g_moveStateServices = nullptr;

signed char ClampMove(const float value) {
    const int integer = static_cast<int>(value);
    return static_cast<signed char>((std::max)(-128, (std::min)(127, integer)));
}

idVec3 ProjectOntoPlane(const idVec3& vector, const idVec3& normal) {
    return vector - normal * vector.Dot(normal);
}
} // namespace

void Tungsten_SetBotMoveStateServices(
        idBotMoveStateServices* const services) {
    g_moveStateServices = services;
}

// Standalone recovery definitions for the embedded engine-owned value. The
// complete engine implementation can replace these when that target is linked.
idObstacleAvoidance::idObstacleAvoidance()
    : buffers(nullptr), lastDir(), lastCorner(), lastUpdateTime(-1) {
}

idObstacleAvoidance::~idObstacleAvoidance() {
    if (g_moveStateServices != nullptr) {
        g_moveStateServices->FreeObstacleBuffers(*this);
    }
}

// Header retail symbol: ??0botPathInfo_t@idBotMoveState@@QAA@XZ
// EA: 0x82B42870, RVA: 0x00B42870
idBotMoveState::botPathInfo_t::botPathInfo_t()
    : hasPath(false), hasClearPath(false), nextMovePointIsGoal(false),
      radarValid(false), nextMovePoint(0.0f, 0.0f, 0.0f), aas(nullptr),
      path(), obstacleAvoidanceInfo(), obstacleAvoidance() {
}

// Retail symbol: ??1idBotMoveState@@UAA@XZ
// EA: 0x82B41CC8, RVA: 0x00B41CC8
idBotMoveState::~idBotMoveState() {
    pathInfo.aas = nullptr;
    owner = nullptr;
}

// Retail symbol: ?MoveToGoalCmd_SetMoveSubGoal@idBotMoveState@@QAAXABVidVec3@@M_N@Z
// EA: 0x82B41DA0, RVA: 0x00B41DA0
void idBotMoveState::MoveToGoalCmd_SetMoveSubGoal(const idVec3& point,
        const float radius, const bool stopAtPoint) {
    currentMoveCmd.SetMoveSubGoal(point, radius, stopAtPoint);
}

// Retail symbol: ?ReachedPosition@idBotMoveState@@QBA_NABVidVec3@@M@Z
// EA: 0x82B41E08, RVA: 0x00B41E08
bool idBotMoveState::ReachedPosition(const idVec3& point,
        const float tolerance) const {
    if (owner == nullptr || g_moveStateServices == nullptr) {
        return false;
    }
    const idVec3 origin = g_moveStateServices->GetOwnerOrigin(*owner);
    const float deltaX = point.x - origin.x;
    const float deltaY = point.y - origin.y;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY) <= tolerance
        && std::fabs(point.z - origin.z)
            <= g_moveStateServices->GetNormalHeight();
}

// Retail symbol: ?ReachedEntity@idBotMoveState@@QBA_NPBVidEntity@@ABVidVec3@@M@Z
// EA: 0x82B41F08, RVA: 0x00B41F08
bool idBotMoveState::ReachedEntity(const idEntity* const entity,
        const idVec3& entityOrg, float tolerance) const {
    if (entity != nullptr && owner != nullptr
            && g_moveStateServices != nullptr) {
        tolerance += g_moveStateServices->GetOwnerInternalRadiusXY(*owner)
            + g_moveStateServices->GetEntityInternalRadiusXY(*entity);
    }
    return ReachedPosition(entityOrg, tolerance);
}

// Retail symbol: ?CanMoveInDir@idBotMoveState@@QBA_NW4botRelativeMoveDirection_t@@MPAVidVec3@@@Z
// EA: 0x82B41FA8, RVA: 0x00B41FA8
bool idBotMoveState::CanMoveInDir(
        const botRelativeMoveDirection_t moveDirection,
        const float moveUnits, idVec3* const endPoint) const {
    if (pathInfo.aas == nullptr || owner == nullptr
            || g_moveStateServices == nullptr
            || moveDirection < BOT_MOVE_SOUTH
            || moveDirection >= BOT_MOVE_MAX) {
        return false;
    }
    const idVec3 start = g_moveStateServices->GetOwnerAASOrigin(
        *owner, *pathInfo.aas);
    if (pathInfo.radarValid && moveDirection != BOT_MOVE_NORTH
            && moveUnits <= 256.0f) {
        idVec3 direction =
            pathInfo.obstacleAvoidanceInfo.radar[moveDirection].direction;
        if (direction.NormalizeFast() < moveUnits) {
            return false;
        }
        if (endPoint != nullptr) {
            *endPoint = start + direction * moveUnits;
        }
        return true;
    }

    const idMat3 axis = g_moveStateServices->GetOwnerViewAxis(*owner);
    const idVec3& forward = axis[0];
    const idVec3& right = axis[1];
    idVec3 direction;
    switch (moveDirection) {
        case BOT_MOVE_SOUTH: direction = -forward; break;
        case BOT_MOVE_WEST: direction = right; break;
        case BOT_MOVE_EAST: direction = -right; break;
        case BOT_MOVE_NORTH_WEST: direction = forward + right; break;
        case BOT_MOVE_NORTH_EAST: direction = forward - right; break;
        case BOT_MOVE_SOUTH_WEST: direction = -forward + right; break;
        case BOT_MOVE_SOUTH_EAST: direction = -forward - right; break;
        case BOT_MOVE_NORTH: direction = forward; break;
        default: return false;
    }
    const idVec3 desiredEnd = start + direction * moveUnits;
    idVec3 traceEnd = desiredEnd;
    float fraction = 0.0f;
    int areaNum = g_moveStateServices->GetOwnerAreaNum(
        *owner, *pathInfo.aas);
    const bool traced = g_moveStateServices->TraceMoveFloor(*owner,
        *pathInfo.aas, start, areaNum, desiredEnd, traceEnd, fraction);
    if (endPoint != nullptr) {
        *endPoint = traceEnd;
    }
    return traced && fraction >= 1.0f;
}

// Retail symbol: ?MoveToGoalCmd_SetStance@idBotMoveState@@QAAXW4botMoveStance_t@@@Z
// EA: 0x82B424F0, RVA: 0x00B424F0
void idBotMoveState::MoveToGoalCmd_SetStance(
        const botMoveStance_t stance) {
    currentMoveCmd.moveStance = stance;
}

// Retail symbol: ?MoveToGoalCmd_SetTolerance@idBotMoveState@@QAAXM@Z
// EA: 0x82B424F8, RVA: 0x00B424F8
void idBotMoveState::MoveToGoalCmd_SetTolerance(const float tolerance) {
    currentMoveCmd.moveTolerance = tolerance;
}

// Retail symbol: ?DidActionRow@idGuiListBox@@QAAAAV1@H@Z
// EA: 0x82B42500, RVA: 0x00B42500
idGuiListBox& idGuiListBox::DidActionRow(const int actionRow) {
    didActionRow = actionRow;
    return *this;
}

// Retail symbol: ?UpdateMoveState_Normal@idBotMoveState@@AAAXXZ
// EA: 0x82B42508, RVA: 0x00B42508
void idBotMoveState::UpdateMoveState_Normal() {
    currentMoveStance = currentMoveCmd.moveStance;
    currentMoveFlags = currentMoveCmd.moveFlags;
    if (owner == nullptr || g_moveStateServices == nullptr) {
        return;
    }
    idVec3 aimPoint = pathInfo.nextMovePoint;
    const idVec3 eye = g_moveStateServices->GetOwnerEyePosition(*owner);
    if (aimPoint.z - eye.z < 100.0f) {
        aimPoint.z = eye.z;
    }
    g_moveStateServices->AddMoveAimRequest(*owner, aimPoint);
}

// Retail symbol: ?UpdateDebugInfo@idBotMoveState@@AAAXXZ
// EA: 0x82B425D0, RVA: 0x00B425D0
void idBotMoveState::UpdateDebugInfo() {
    if (pathInfo.aas == nullptr && owner != nullptr
            && g_moveStateServices != nullptr) {
        g_moveStateServices->DebugNoAAS(*owner);
    }
}

// Retail symbol: ?UpdateIdleCmds@idBotMoveState@@AAAXAAVusercmd_t@@@Z
// EA: 0x82B426C8, RVA: 0x00B426C8
void idBotMoveState::UpdateIdleCmds(idBotUserCommand& cmd) {
    if (idleStance == MOVE_STANCE_CROUCH) {
        cmd.upmove = -127;
    } else if (owner != nullptr && g_moveStateServices != nullptr
            && g_moveStateServices->IsOwnerCrouching(*owner)) {
        cmd.upmove = 127;
    }
    const bool allowJump = g_moveStateServices == nullptr
        || g_moveStateServices->AllowJumping();
    if ((currentMoveFlags.flags & 1U) != 0U) {
        if (allowJump) cmd.upmove = 127;
        currentMoveFlags.flags &= ~1U;
    } else if ((currentMoveFlags.flags & 2U) != 0U) {
        if (allowJump) cmd.upmove = 127;
        cmd.rightmove = 127;
        currentMoveFlags.flags &= ~2U;
    } else if ((currentMoveFlags.flags & 4U) != 0U) {
        if (allowJump) cmd.upmove = 127;
        cmd.rightmove = -127;
        currentMoveFlags.flags &= ~4U;
    }
}

// Retail symbol: ??0idBotMoveState@@QAA@XZ
// EA: 0x82B428F8, RVA: 0x00B428F8
idBotMoveState::idBotMoveState()
    : owner(nullptr), currentMoveCmd("Default", nullptr), currentMoveFlags(),
      idleStance(MOVE_STANCE_RUN), currentMoveStance(MOVE_STANCE_RUN),
      currentMoveStatus(MOVE_STATUS_NONE), currentMoveState(MOVE_STATE_NONE),
      pathInfo() {
    currentMoveFlags.flags = 0U;
    if (g_moveStateServices != nullptr) {
        pathInfo.aas = g_moveStateServices->GetPrimaryAAS();
        if (pathInfo.aas == nullptr && g_moveStateServices->AlwaysLoadAAS()) {
            pathInfo.aas = g_moveStateServices->GetFallbackAAS();
        }
    }
}

// Retail symbol: ?StartMoveToGoal@idBotMoveState@@QAAXAAVidBotMoveCommand@@@Z
// EA: 0x82B42A10, RVA: 0x00B42A10
void idBotMoveState::StartMoveToGoal(idBotMoveCommand& moveCmd) {
    currentMoveStatus = MOVE_STATUS_PENDING;
    currentMoveCmd = moveCmd;
}

// Retail symbol: ?UpdateBotGUI@idBotMoveState@@QBAXAAVidGuiListBox@@@Z
// EA: 0x82B42A28, RVA: 0x00B42A28
void idBotMoveState::UpdateBotGUI(idGuiListBox& infoList) const {
    if (owner == nullptr || pathInfo.aas == nullptr
            || g_moveStateServices == nullptr) {
        return;
    }
    g_moveStateServices->UpdateMoveGUI(*owner, infoList,
        g_moveStateServices->GetOwnerAreaNum(*owner, *pathInfo.aas),
        currentMoveCmd.moveAreaNum, currentMoveCmd.moveDestination,
        currentMoveStatus, currentMoveCmd.moveUserName);
}

// Retail symbol: ?ReachedMoveGoal@idBotMoveState@@ABA_NXZ
// EA: 0x82B42BE8, RVA: 0x00B42BE8
bool idBotMoveState::ReachedMoveGoal() const {
    if (g_moveStateServices != nullptr
            && g_moveStateServices->GetFreezeMovement() == 2) {
        return true;
    }
    if (currentMoveCmd.GetMoveGoalType() == MOVE_GOAL_TYPE_ENTITY) {
        const idEntity* entity = g_moveStateServices != nullptr
            ? g_moveStateServices->ResolveEntitySpawnId(
                currentMoveCmd.moveGoalEntity.GetSpawnId()) : nullptr;
        return ReachedEntity(entity, currentMoveCmd.moveDestination,
            currentMoveCmd.moveDestinationTolerance);
    }
    if (currentMoveCmd.GetMoveGoalType() == MOVE_GOAL_TYPE_POSITION) {
        return ReachedPosition(currentMoveCmd.moveDestination,
            currentMoveCmd.moveDestinationTolerance);
    }
    return false;
}

// Retail symbol: ?MoveToGoalCmd_IsReached@idBotMoveState@@QBA_NXZ
// EA: 0x82B42CF0, RVA: 0x00B42CF0
bool idBotMoveState::MoveToGoalCmd_IsReached() const {
    return ReachedMoveGoal();
}

// Retail symbol: ?UpdateObstacleAvoidance@idBotMoveState@@AAA_NH@Z
// EA: 0x82B42D00, RVA: 0x00B42D00
bool idBotMoveState::UpdateObstacleAvoidance(const int startAreaNum) {
    return owner != nullptr && pathInfo.aas != nullptr
        && g_moveStateServices != nullptr
        && g_moveStateServices->BuildObstaclePath(*owner, *pathInfo.aas,
            startAreaNum, pathInfo.path, pathInfo.obstacleAvoidanceInfo,
            pathInfo.obstacleAvoidance);
}

// Retail symbol: ?UpdateAASRadar@idBotMoveState@@AAAXXZ
// EA: 0x82B432B8, RVA: 0x00B432B8
void idBotMoveState::UpdateAASRadar() {
    if (owner == nullptr || pathInfo.aas == nullptr
            || g_moveStateServices == nullptr) {
        return;
    }
    int areaNum = g_moveStateServices->GetOwnerAreaNum(*owner, *pathInfo.aas);
    if (areaNum == 0) {
        areaNum = g_moveStateServices->GetOwnerLastValidAreaNum(
            *owner, *pathInfo.aas);
    }
    const idVec3 origin = g_moveStateServices->GetOwnerOrigin(*owner);
    const idVec3 forward = g_moveStateServices->GetOwnerViewAxis(*owner)[0];
    pathInfo.path.obstacleRoute.areas[0].start = origin;
    pathInfo.path.obstacleRoute.areas[0].end = origin + forward;
    pathInfo.path.obstacleRoute.numAreas = 1;
    pathInfo.obstacleAvoidanceInfo.useRadarForward = true;
    pathInfo.obstacleAvoidanceInfo.radarForward = forward;
    pathInfo.radarValid = UpdateObstacleAvoidance(areaNum);
}

// Retail symbol: ?UpdateMoveCmds@idBotMoveState@@QAAXAAVusercmd_t@@@Z
// EA: 0x82B433E0, RVA: 0x00B433E0
void idBotMoveState::UpdateMoveCmds(idBotUserCommand& cmd) {
    if (currentMoveCmd.moveGoalType <= MOVE_GOAL_TYPE_NONE
            || currentMoveStatus >= MOVE_STATUS_START_ERROR_CODES
            || (g_moveStateServices != nullptr
                && g_moveStateServices->GetFreezeMovement() > 0)) {
        return;
    }
    if (currentMoveStatus == MOVE_STATUS_DONE) {
        UpdateIdleCmds(cmd);
        return;
    }
    if (owner == nullptr || g_moveStateServices == nullptr) {
        return;
    }

    const bool crouching = g_moveStateServices->IsOwnerCrouching(*owner);
    if (currentMoveStance == MOVE_STANCE_CROUCH) {
        cmd.upmove = -127;
    } else if (currentMoveStance == MOVE_STANCE_WALK
            || currentMoveStance == MOVE_STANCE_RUN) {
        if (crouching) cmd.upmove = 127;
    } else if (currentMoveStance == MOVE_STANCE_SPRINT) {
        if (crouching) cmd.upmove = 127;
        cmd.buttons |= 0x10U;
    }
    UpdateIdleCmds(cmd);

    const idVec3 origin = g_moveStateServices->GetOwnerOrigin(*owner);
    const idVec3 gravity = g_moveStateServices->GetOwnerGravityNormal(*owner);
    const idMat3 axis = g_moveStateServices->GetOwnerViewAxis(*owner);
    idVec3 forward = ProjectOntoPlane(axis[0], gravity);
    idVec3 right = ProjectOntoPlane(gravity.Cross(axis[0]), gravity);
    forward.NormalizeFast();
    right.NormalizeFast();
    idVec3 moveDirection(pathInfo.nextMovePoint.x - origin.x,
        pathInfo.nextMovePoint.y - origin.y, 0.0f);
    const float distance = moveDirection.NormalizeFast();
    const float scale = pathInfo.nextMovePointIsGoal
            && currentMoveCmd.GetMoveStopAtPoint() && distance < 64.0f
        ? 64.0f : 128.0f;
    cmd.forwardmove = ClampMove(moveDirection.Dot(forward) * scale);
    cmd.rightmove = ClampMove(moveDirection.Dot(right) * scale);
}

// Retail symbol: ?PathToGoal@idBotMoveState@@AAA_NXZ
// EA: 0x82B43830, RVA: 0x00B43830
bool idBotMoveState::PathToGoal() {
    if (pathInfo.aas == nullptr || owner == nullptr
            || g_moveStateServices == nullptr) {
        return false;
    }
    const auto setError = [this](const botMoveStatus_t status) {
        const botMoveStatus_t previous = currentMoveStatus;
        currentMoveStatus = status;
        if (previous != status) {
            currentMoveCmd.ErroredMoveGoalCallBack(owner,
                g_moveStateServices->GetScaledGameTime(), status);
        }
    };
    const int goalAreaNum = currentMoveCmd.moveAreaNum;
    if (goalAreaNum == 0) {
        setError(MOVE_STATUS_GOAL_OFF_MESH);
        return false;
    }
    int startAreaNum = g_moveStateServices->GetOwnerAreaNum(
        *owner, *pathInfo.aas);
    if (startAreaNum == 0) {
        startAreaNum = g_moveStateServices->GetOwnerLastValidAreaNum(
            *owner, *pathInfo.aas);
        if (startAreaNum == 0) {
            setError(MOVE_STATUS_OWNER_OFF_MESH);
            return false;
        }
    }
    const idVec3 start = g_moveStateServices->GetOwnerAASOrigin(
        *owner, *pathInfo.aas);
    pathInfo.hasPath = g_moveStateServices->WalkPathToGoal(*owner,
        *pathInfo.aas, startAreaNum, start, goalAreaNum,
        currentMoveCmd.moveDestination, pathInfo.path);
    if (!pathInfo.hasPath) {
        setError(MOVE_STATUS_GOAL_UNREACHABLE);
        return false;
    }
    pathInfo.hasClearPath = UpdateObstacleAvoidance(startAreaNum);
    pathInfo.radarValid = pathInfo.hasClearPath;
    if (!pathInfo.hasClearPath) {
        setError(MOVE_STATUS_NO_CLEAR_PATH);
        return false;
    }
    const float planeDistance =
        pathInfo.obstacleAvoidanceInfo.seekPosPlane.a * start.x
        + pathInfo.obstacleAvoidanceInfo.seekPosPlane.b * start.y
        + pathInfo.obstacleAvoidanceInfo.seekPosPlane.c * start.z
        + pathInfo.obstacleAvoidanceInfo.seekPosPlane.d;
    pathInfo.path.moveGoal = pathInfo.obstacleAvoidanceInfo.seekPos[
        planeDistance > -0.01f ? 1 : 0];
    pathInfo.nextMovePoint = pathInfo.path.moveGoal;
    const idVec3 delta = pathInfo.path.moveGoal
        - currentMoveCmd.moveDestination;
    pathInfo.nextMovePointIsGoal = std::fabs(delta.x) <= 0.1f
        && std::fabs(delta.y) <= 0.1f && std::fabs(delta.z) <= 0.1f;
    return true;
}

// Retail symbol: ?Update@idBotMoveState@@QAAXXZ
// EA: 0x82B43EB8, RVA: 0x00B43EB8
void idBotMoveState::Update() {
    UpdateDebugInfo();
    if (currentMoveCmd.moveGoalType <= MOVE_GOAL_TYPE_NONE) {
        return;
    }
    const int currentTime = g_moveStateServices != nullptr
        ? g_moveStateServices->GetScaledGameTime() : 0;
    if (currentMoveCmd.UpdateMoveDestination(pathInfo.aas, owner)
            != UPDATE_MOVE_DEST_OK) {
        const botMoveStatus_t previous = currentMoveStatus;
        currentMoveStatus = MOVE_STATUS_INVALID_GOAL;
        if (previous != currentMoveStatus) {
            currentMoveCmd.ErroredMoveGoalCallBack(
                owner, currentTime, currentMoveStatus);
        }
    } else if (ReachedMoveGoal()) {
        const botMoveStatus_t previous = currentMoveStatus;
        currentMoveStatus = MOVE_STATUS_DONE;
        if (previous != currentMoveStatus) {
            currentMoveCmd.ReachedMoveGoalCallBack(owner, currentTime);
        }
        UpdateAASRadar();
    } else if (PathToGoal()) {
        currentMoveState = MOVE_STATE_NORMAL;
        UpdateMoveState_Normal();
        const botMoveStatus_t previous = currentMoveStatus;
        currentMoveStatus = MOVE_STATUS_MOVING;
        if (previous != currentMoveStatus) {
            currentMoveCmd.StartedMoveGoalCallBack(owner, currentTime);
        }
        if (g_moveStateServices != nullptr
                && g_moveStateServices->ShouldPrintMoveUser(*owner)) {
            g_moveStateServices->PrintMoveUser(currentMoveCmd.moveUserName);
        }
    }
}
