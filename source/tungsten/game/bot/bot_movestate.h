#pragma once

#include "bot_movecmd.h"
#include "../../../engine/gamelib/aas2/aas2.h"
#include "../../../engine/gamelib/aas2/obstacleavoidance.h"

class idBot;

class idBotMoveState {
public:
    enum botMoveStates_t : int {
        MOVE_STATE_NONE = 0,
        MOVE_STATE_NORMAL = 1,
        MOVE_STATE_MAX = 2
    };

    struct botPathInfo_t {
        botPathInfo_t();

        bool hasPath;
        bool hasClearPath;
        bool nextMovePointIsGoal;
        bool radarValid;
        idVec3 nextMovePoint;
        const idAAS2* aas;
        idAAS2Path path;
        obstaclePath_t obstacleAvoidanceInfo;
        idObstacleAvoidance obstacleAvoidance;
    };

    virtual ~idBotMoveState();

    void MoveToGoalCmd_SetMoveSubGoal(const idVec3& point, float radius,
        bool stopAtPoint);
    void MoveToGoalCmd_SetStance(botMoveStance_t stance);
    void MoveToGoalCmd_SetTolerance(float tolerance);
    void StartMoveToGoal(idBotMoveCommand& moveCmd);

    idBot* owner;
    idBotMoveCommand currentMoveCmd;
    idBitFlag32 currentMoveFlags;
    botMoveStance_t idleStance;
    botMoveStance_t currentMoveStance;
    botMoveStatus_t currentMoveStatus;
    botMoveStates_t currentMoveState;
    botPathInfo_t pathInfo;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idBotMoveState::botPathInfo_t) == 1116,
    "Recovered bot path-info ABI changed");
static_assert(sizeof(idBotMoveState) == 1236,
    "Recovered bot move-state ABI changed");
#endif
