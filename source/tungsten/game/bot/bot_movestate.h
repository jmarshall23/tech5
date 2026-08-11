#pragma once

#include "bot_movecmd.h"
#include "../../../engine/gamelib/aas2/aas2.h"
#include "../../../engine/gamelib/aas2/obstacleavoidance.h"

class idBot;
class idEntity;
struct idBotUserCommand;

enum botRelativeMoveDirection_t : int {
    BOT_MOVE_SOUTH = 0,
    BOT_MOVE_WEST = 1,
    BOT_MOVE_EAST = 2,
    BOT_MOVE_NORTH_WEST = 3,
    BOT_MOVE_NORTH_EAST = 4,
    BOT_MOVE_SOUTH_WEST = 5,
    BOT_MOVE_SOUTH_EAST = 6,
    BOT_MOVE_NORTH = 7,
    BOT_MOVE_MAX = 8
};

class idGuiListBox {
public:
    idGuiListBox() : didActionRow(-1), maxRowsToDisplay(0) {}
    idGuiListBox& DidActionRow(int actionRow);

    int didActionRow;
    int maxRowsToDisplay;
};

class idBotMoveStateServices {
public:
    virtual ~idBotMoveStateServices() = default;

    virtual int GetScaledGameTime() const = 0;
    virtual const idAAS2* GetPrimaryAAS() const = 0;
    virtual const idAAS2* GetFallbackAAS() const = 0;
    virtual bool AlwaysLoadAAS() const = 0;
    virtual int GetFreezeMovement() const = 0;
    virtual bool AllowJumping() const = 0;
    virtual float GetNormalHeight() const = 0;
    virtual idVec3 GetOwnerOrigin(const idBot& bot) const = 0;
    virtual idVec3 GetOwnerEyePosition(const idBot& bot) const = 0;
    virtual idVec3 GetOwnerAASOrigin(const idBot& bot,
        const idAAS2& aas) const = 0;
    virtual idVec3 GetOwnerGravityNormal(const idBot& bot) const = 0;
    virtual idMat3 GetOwnerViewAxis(const idBot& bot) const = 0;
    virtual float GetOwnerInternalRadiusXY(const idBot& bot) const = 0;
    virtual float GetEntityInternalRadiusXY(const idEntity& entity) const = 0;
    virtual bool IsOwnerCrouching(const idBot& bot) const = 0;
    virtual int GetOwnerAreaNum(const idBot& bot,
        const idAAS2& aas) const = 0;
    virtual int GetOwnerLastValidAreaNum(const idBot& bot,
        const idAAS2& aas) const = 0;
    virtual const idEntity* ResolveEntitySpawnId(int spawnId) const = 0;
    virtual bool TraceMoveFloor(const idBot& bot, const idAAS2& aas,
        const idVec3& start, int startAreaNum, const idVec3& end,
        idVec3& traceEnd, float& fraction) const = 0;
    virtual void AddMoveAimRequest(idBot& bot, const idVec3& point) = 0;
    virtual void DebugNoAAS(const idBot& bot) const = 0;
    virtual void UpdateMoveGUI(const idBot& bot, idGuiListBox& list,
        int ownerAreaNum, int moveAreaNum, const idVec3& destination,
        botMoveStatus_t status, const char* userName) const = 0;
    virtual bool BuildObstaclePath(const idBot& bot, const idAAS2& aas,
        int startAreaNum, idAAS2Path& path, obstaclePath_t& obstaclePath,
        idObstacleAvoidance& avoidance) = 0;
    virtual bool WalkPathToGoal(const idBot& bot, const idAAS2& aas,
        int startAreaNum, const idVec3& start, int goalAreaNum,
        const idVec3& goal, idAAS2Path& path) = 0;
    virtual bool ShouldPrintMoveUser(const idBot& bot) const = 0;
    virtual void PrintMoveUser(const char* userName) const = 0;
    virtual void FreeObstacleBuffers(idObstacleAvoidance& avoidance) = 0;
};

void Tungsten_SetBotMoveStateServices(idBotMoveStateServices* services);

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

    idBotMoveState();

    void MoveToGoalCmd_SetMoveSubGoal(const idVec3& point, float radius,
        bool stopAtPoint);
    void MoveToGoalCmd_SetStance(botMoveStance_t stance);
    void MoveToGoalCmd_SetTolerance(float tolerance);
    void StartMoveToGoal(idBotMoveCommand& moveCmd);
    bool ReachedPosition(const idVec3& point, float tolerance) const;
    bool ReachedEntity(const idEntity* entity, const idVec3& entityOrg,
        float tolerance) const;
    bool CanMoveInDir(botRelativeMoveDirection_t moveDirection,
        float moveUnits, idVec3* endPoint) const;
    void UpdateMoveState_Normal();
    void UpdateDebugInfo();
    void UpdateIdleCmds(idBotUserCommand& cmd);
    void UpdateBotGUI(idGuiListBox& infoList) const;
    bool ReachedMoveGoal() const;
    bool MoveToGoalCmd_IsReached() const;
    bool UpdateObstacleAvoidance(int startAreaNum);
    void UpdateAASRadar();
    void UpdateMoveCmds(idBotUserCommand& cmd);
    bool PathToGoal();
    void Update();

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
