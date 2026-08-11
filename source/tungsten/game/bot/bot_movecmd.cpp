#include "bot_movecmd.h"

#include "behaviortree/behaviortree.h"

namespace {
idBotMoveCommandServices* g_moveCommandServices = nullptr;
constexpr int INVALID_ENTITY_SPAWN_ID = 0x1FFF;
} // namespace

void Tungsten_SetBotMoveCommandServices(
        idBotMoveCommandServices* const services) {
    g_moveCommandServices = services;
}

// Retail symbol: ??1idBotMoveCommand@@UAA@XZ
// EA: 0x82B41430, RVA: 0x00B41430
idBotMoveCommand::~idBotMoveCommand() = default;

// Retail symbol: ?GetMoveGoalType@idBotMoveCommand@@QBA?AW4botMoveGoalType_t@@XZ
// EA: 0x82B41440, RVA: 0x00B41440
botMoveGoalType_t idBotMoveCommand::GetMoveGoalType() const {
    return moveSubGoal.active ? MOVE_GOAL_TYPE_POSITION : moveGoalType;
}

// Retail symbol: ?GetMoveStopAtPoint@idBotMoveCommand@@QBA_NXZ
// EA: 0x82B41460, RVA: 0x00B41460
bool idBotMoveCommand::GetMoveStopAtPoint() const {
    return moveSubGoal.active ? moveSubGoal.stopAtPoint : moveStopAtPoint;
}

// Retail symbol: ?ReachedMoveGoalCallBack@idBotMoveCommand@@QAAXPAVidBot@@H@Z
// EA: 0x82B41480, RVA: 0x00B41480
void idBotMoveCommand::ReachedMoveGoalCallBack(
        idBot* const bot, const int curTime) {
    if (moveCallBackState != nullptr) {
        moveCallBackState->MoveGoal_Reached_CallBack(bot, curTime);
    }
}

// Retail symbol: ?ErroredMoveGoalCallBack@idBotMoveCommand@@QAAXPAVidBot@@HW4botMoveStatus_t@@@Z
// EA: 0x82B414A8, RVA: 0x00B414A8
void idBotMoveCommand::ErroredMoveGoalCallBack(idBot* const bot,
        const int curTime, const botMoveStatus_t moveStatusCode) {
    if (moveCallBackState == nullptr) {
        return;
    }
    if (moveSubGoal.active) {
        moveCallBackState->MoveSubGoal_Errored_CallBack(
            bot, curTime, moveStatusCode);
    }
    moveCallBackState->MoveGoal_Errored_CallBack(
        bot, curTime, moveStatusCode);
}

// Retail symbol: ?StartedMoveGoalCallBack@idBotMoveCommand@@QAAXPAVidBot@@H@Z
// EA: 0x82B41518, RVA: 0x00B41518
void idBotMoveCommand::StartedMoveGoalCallBack(
        idBot* const bot, const int curTime) {
    if (moveCallBackState != nullptr && !moveSubGoal.active) {
        moveCallBackState->MoveGoal_Started_CallBack(bot, curTime);
    }
}

// Retail symbol: ?SetMoveGoalPosition@idBotMoveCommand@@QAAXABVidVec3@@@Z
// EA: 0x82B415A0, RVA: 0x00B415A0
void idBotMoveCommand::SetMoveGoalPosition(const idVec3& goalPos) {
    moveGoalType = MOVE_GOAL_TYPE_POSITION;
    moveGoalPosition = goalPos;
}

// Retail symbol: ?SetMoveSubGoal@idBotMoveCommand@@QAAXABVidVec3@@M_N@Z
// EA: 0x82B415C8, RVA: 0x00B415C8
void idBotMoveCommand::SetMoveSubGoal(const idVec3& point,
        const float radius, const bool stopAtPoint) {
    moveSubGoal.active = true;
    moveSubGoal.firstRun = true;
    moveSubGoal.point = point;
    moveSubGoal.stopAtPoint = stopAtPoint;
    moveSubGoal.radius = radius;
}

// Retail symbol: ?SetMoveGoalEntity@idBotMoveCommand@@QAAXPBVidEntity@@W4botMoveEntityType_t@@@Z
// EA: 0x82B415F8, RVA: 0x00B415F8
void idBotMoveCommand::SetMoveGoalEntity(const idEntity* const goalEnt,
        const botMoveEntityType_t entityType) {
    moveGoalType = MOVE_GOAL_TYPE_ENTITY;
    moveGoalEntity.SetSpawnId(goalEnt != nullptr
            && g_moveCommandServices != nullptr
        ? g_moveCommandServices->GetEntitySpawnId(goalEnt)
        : INVALID_ENTITY_SPAWN_ID);
    moveEntityType = entityType;
}

// Retail symbol: ?UpdateMoveEntity@idBotMoveCommand@@QAAXPBVidBot@@@Z
// EA: 0x82B41648, RVA: 0x00B41648
void idBotMoveCommand::UpdateMoveEntity(const idBot* const bot) {
    if (bot == nullptr || g_moveCommandServices == nullptr) {
        moveGoalEntity.Invalidate();
        return;
    }
    int spawnId = INVALID_ENTITY_SPAWN_ID;
    if (moveEntityType == MOVE_ENTITY_TYPE_ENEMY) {
        spawnId = g_moveCommandServices->GetBotGoalEnemySpawnId(*bot);
    } else if (moveEntityType == MOVE_ENTITY_TYPE_GOAL_ENTITY) {
        spawnId = g_moveCommandServices->GetBotGoalEntitySpawnId(*bot);
    } else {
        return;
    }
    const idEntity* const entity =
        g_moveCommandServices->ResolveEntitySpawnId(spawnId);
    moveGoalEntity.SetSpawnId(entity != nullptr
        ? g_moveCommandServices->GetEntitySpawnId(entity)
        : INVALID_ENTITY_SPAWN_ID);
}

// Retail symbol: ??0idBotMoveCommand@@QAA@PBDPAVidBehaviorAction@@@Z
// EA: 0x82B41750, RVA: 0x00B41750
idBotMoveCommand::idBotMoveCommand(const char* const userName,
        idBehaviorAction* const callBackState)
    : moveUserName(userName), moveStopAtPoint(true), moveAreaNum(0),
      moveFlags(), moveStance(MOVE_STANCE_NONE),
      moveGoalType(MOVE_GOAL_TYPE_NONE),
      moveEntityType(MOVE_ENTITY_TYPE_NONE), moveTolerance(0.0f),
      moveGoalPosition(0.0f, 0.0f, 0.0f),
      moveDestination(0.0f, 0.0f, 0.0f), moveGoalEntity(),
      moveCallBackState(callBackState), moveDestinationTolerance(0.0f),
      moveSubGoal{ false, true, true, idVec3(0.0f, 0.0f, 0.0f), 0.0f } {
    moveFlags.flags = 0U;
}

idBotMoveCommand& idBotMoveCommand::operator=(
        const idBotMoveCommand& src) {
    if (this == &src) {
        return *this;
    }
    moveUserName = src.moveUserName;
    moveStopAtPoint = src.moveStopAtPoint;
    moveAreaNum = src.moveAreaNum;
    moveFlags = src.moveFlags;
    moveStance = src.moveStance;
    moveGoalType = src.moveGoalType;
    moveEntityType = src.moveEntityType;
    moveTolerance = src.moveTolerance;
    moveGoalPosition = src.moveGoalPosition;
    moveDestination.Zero();
    moveGoalEntity = src.moveGoalEntity;
    moveCallBackState = src.moveCallBackState;
    moveSubGoal.active = src.moveSubGoal.active;
    moveSubGoal.point = src.moveSubGoal.point;
    moveSubGoal.radius = src.moveSubGoal.radius;
    return *this;
}

// Retail symbol: ?UpdateMoveDestination@idBotMoveCommand@@QAA?AW4updateMoveDestCode_t@@PBVidAAS2@@PAVidBot@@@Z
// EA: 0x82B41838, RVA: 0x00B41838
updateMoveDestCode_t idBotMoveCommand::UpdateMoveDestination(
        const idAAS2* const aas, idBot* const bot) {
    if (aas == nullptr) {
        return UPDATE_MOVE_DEST_NO_AAS;
    }
    if (bot == nullptr || g_moveCommandServices == nullptr) {
        return UPDATE_MOVE_DEST_INVALID_GOAL;
    }

    moveAreaNum = 0;
    if (moveSubGoal.active) {
        moveDestination = moveSubGoal.point;
        moveDestinationTolerance = moveSubGoal.radius;
        moveAreaNum = g_moveCommandServices->FindReachableArea(
            *aas, moveDestination);
        if (moveAreaNum == 0) {
            return UPDATE_MOVE_DEST_NO_AREA;
        }
        g_moveCommandServices->PushPointIntoArea(
            *aas, moveAreaNum, moveDestination);
        if (!g_moveCommandServices->IsMoveGoalReached(*bot)) {
            if (moveSubGoal.firstRun) {
                moveSubGoal.firstRun = false;
                if (moveCallBackState != nullptr) {
                    moveCallBackState->MoveSubGoal_Started_CallBack(
                        bot, g_moveCommandServices->GetScaledGameTime());
                }
            }
            return UPDATE_MOVE_DEST_OK;
        }
        if (moveCallBackState != nullptr) {
            moveCallBackState->MoveSubGoal_Reached_CallBack(
                bot, g_moveCommandServices->GetScaledGameTime());
        }
        moveSubGoal.active = false;
        moveSubGoal.firstRun = false;
    }

    if (moveGoalType == MOVE_GOAL_TYPE_ENTITY) {
        UpdateMoveEntity(bot);
        const idEntity* const entity =
            g_moveCommandServices->ResolveEntitySpawnId(
                moveGoalEntity.GetSpawnId());
        if (entity == nullptr) {
            return UPDATE_MOVE_DEST_INVALID_GOAL;
        }
        moveDestination = g_moveCommandServices->GetEntityOrigin(*entity);
        moveDestinationTolerance = moveTolerance;

        int actorArea = 0;
        if (g_moveCommandServices->GetActorArea(*entity, *aas, actorArea)) {
            moveAreaNum = actorArea;
            if (moveAreaNum == 0 && (moveFlags.flags & 8U) == 0U) {
                moveAreaNum = g_moveCommandServices->GetActorLastValidArea(
                    *entity, *aas);
                moveDestination =
                    g_moveCommandServices->GetActorLastValidOrigin(
                        *entity, *aas);
            }
            if (moveAreaNum == 0) {
                return UPDATE_MOVE_DEST_NO_AREA;
            }
        } else {
            moveAreaNum = g_moveCommandServices->FindReachableArea(
                *aas, moveDestination);
            if (moveAreaNum == 0) {
                return UPDATE_MOVE_DEST_NO_AREA;
            }
        }
        g_moveCommandServices->PushPointIntoArea(
            *aas, moveAreaNum, moveDestination);
        return UPDATE_MOVE_DEST_OK;
    }

    if (moveGoalType == MOVE_GOAL_TYPE_POSITION) {
        moveDestination = g_moveCommandServices->GetBotGoalPosition(*bot);
        moveDestinationTolerance = moveTolerance;
        if (moveDestination.LengthSqr() == 0.0f) {
            return UPDATE_MOVE_DEST_INVALID_GOAL;
        }
        moveAreaNum = g_moveCommandServices->FindReachableArea(
            *aas, moveDestination);
        if (moveAreaNum == 0) {
            return UPDATE_MOVE_DEST_NO_AREA;
        }
        g_moveCommandServices->PushPointIntoArea(
            *aas, moveAreaNum, moveDestination);
    }
    return UPDATE_MOVE_DEST_OK;
}
