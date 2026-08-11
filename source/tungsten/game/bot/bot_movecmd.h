#pragma once

#include "../entities/entityptr.h"
#include "../../../shared/idlib/containers/bitflag.h"
#include "../../../shared/idlib/math/vector.h"

class idAAS2;
class idBehaviorAction;
class idBot;
class idEntity;

class idBotMoveCommandServices {
public:
    virtual ~idBotMoveCommandServices() = default;

    virtual int GetScaledGameTime() const = 0;
    virtual int GetEntitySpawnId(const idEntity* entity) const = 0;
    virtual const idEntity* ResolveEntitySpawnId(int spawnId) const = 0;
    virtual int GetBotGoalEnemySpawnId(const idBot& bot) const = 0;
    virtual int GetBotGoalEntitySpawnId(const idBot& bot) const = 0;
    virtual idVec3 GetBotGoalPosition(const idBot& bot) const = 0;
    virtual idVec3 GetEntityOrigin(const idEntity& entity) const = 0;
    virtual bool GetActorArea(const idEntity& entity, const idAAS2& aas,
        int& areaNum) const = 0;
    virtual int GetActorLastValidArea(const idEntity& entity,
        const idAAS2& aas) const = 0;
    virtual idVec3 GetActorLastValidOrigin(const idEntity& entity,
        const idAAS2& aas) const = 0;
    virtual int FindReachableArea(const idAAS2& aas,
        const idVec3& point) const = 0;
    virtual void PushPointIntoArea(const idAAS2& aas, int areaNum,
        idVec3& point) const = 0;
    virtual bool IsMoveGoalReached(const idBot& bot) const = 0;
};

void Tungsten_SetBotMoveCommandServices(
    idBotMoveCommandServices* services);

enum botMoveStance_t : int {
    MOVE_STANCE_NONE = 0,
    MOVE_STANCE_CROUCH = 1,
    MOVE_STANCE_WALK = 2,
    MOVE_STANCE_RUN = 3,
    MOVE_STANCE_SPRINT = 4
};

enum botMoveGoalType_t : int {
    MOVE_GOAL_TYPE_NONE = 0,
    MOVE_GOAL_TYPE_ENTITY = 1,
    MOVE_GOAL_TYPE_POSITION = 2
};

enum botMoveEntityType_t : int {
    MOVE_ENTITY_TYPE_NONE = 0,
    MOVE_ENTITY_TYPE_ENEMY = 1,
    MOVE_ENTITY_TYPE_GOAL_ENTITY = 2
};

enum botMoveStatus_t : int {
    MOVE_STATUS_NONE = 0,
    MOVE_STATUS_DONE = 1,
    MOVE_STATUS_CANCELLED = 2,
    MOVE_STATUS_PENDING = 3,
    MOVE_STATUS_MOVING = 4,
    MOVE_STATUS_START_ERROR_CODES = 5,
    MOVE_STATUS_GOAL_UNREACHABLE = 6,
    MOVE_STATUS_GOAL_UNREACHABLE_OUTSIDE_TOLERANCE = 7,
    MOVE_STATUS_INVALID_GOAL = 8,
    MOVE_STATUS_OWNER_OFF_MESH = 9,
    MOVE_STATUS_GOAL_OFF_MESH = 10,
    MOVE_STATUS_NO_CLEAR_PATH = 11,
    MOVE_STATUS_INVALID_HANDLE = 12
};

enum updateMoveDestCode_t : int {
    UPDATE_MOVE_DEST_OK = 0,
    UPDATE_MOVE_DEST_INVALID_GOAL = 1,
    UPDATE_MOVE_DEST_NO_AAS = 2,
    UPDATE_MOVE_DEST_NO_AREA = 3
};

class idBotMoveCommand {
public:
    struct moveSubGoal_t {
        bool active;
        bool stopAtPoint;
        bool firstRun;
        idVec3 point;
        float radius;
    };

    idBotMoveCommand(const char* userName, idBehaviorAction* callBackState);
    virtual ~idBotMoveCommand();

    idBotMoveCommand& operator=(const idBotMoveCommand& src);

    botMoveGoalType_t GetMoveGoalType() const;
    bool GetMoveStopAtPoint() const;
    void SetMoveGoalPosition(const idVec3& goalPos);
    void SetMoveSubGoal(const idVec3& point, float radius, bool stopAtPoint);

    // These declarations retain the recovered interface while their entity,
    // behavior-tree, and AAS dependencies remain in the raw ledger.
    void ReachedMoveGoalCallBack(idBot* bot, int curTime);
    void ErroredMoveGoalCallBack(idBot* bot, int curTime,
        botMoveStatus_t moveStatusCode);
    void StartedMoveGoalCallBack(idBot* bot, int curTime);
    void SetMoveGoalEntity(const idEntity* goalEnt,
        botMoveEntityType_t entityType);
    void UpdateMoveEntity(const idBot* bot);
    updateMoveDestCode_t UpdateMoveDestination(const idAAS2* aas, idBot* bot);

    const char* moveUserName;
    bool moveStopAtPoint;
    int moveAreaNum;
    idBitFlag32 moveFlags;
    botMoveStance_t moveStance;
    botMoveGoalType_t moveGoalType;
    botMoveEntityType_t moveEntityType;
    float moveTolerance;
    idVec3 moveGoalPosition;
    idVec3 moveDestination;
    idEntityPtr<const idEntity> moveGoalEntity;
    idBehaviorAction* moveCallBackState;
    float moveDestinationTolerance;
    moveSubGoal_t moveSubGoal;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idBotMoveCommand::moveSubGoal_t) == 20,
    "Recovered bot move sub-goal ABI changed");
static_assert(sizeof(idBotMoveCommand) == 92,
    "Recovered bot move command ABI changed");
#endif
