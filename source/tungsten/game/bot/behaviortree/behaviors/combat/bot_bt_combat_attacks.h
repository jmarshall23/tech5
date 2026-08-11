#pragma once

#include "../bot_bt_combat.h"
#include "../../../bot_movecmd.h"

enum idBotAttackMoveDirection : int {
    BOT_ATTACK_MOVE_NORTH = 0,
    BOT_ATTACK_MOVE_LEFT = 1,
    BOT_ATTACK_MOVE_RIGHT = 2,
    BOT_ATTACK_MOVE_FORWARD_RIGHT = 3,
    BOT_ATTACK_MOVE_SOUTH = 4,
    BOT_ATTACK_MOVE_BACK_LEFT = 5,
    BOT_ATTACK_MOVE_BACK_RIGHT = 6,
    BOT_ATTACK_MOVE_FORWARD_LEFT = 7,
    BOT_ATTACK_MOVE_MAX = 8
};

class idBotCombatAttackServices {
public:
    virtual ~idBotCombatAttackServices() = default;
    virtual bool CheckStateFlag(const idBot&, int flag) const = 0;
    virtual float GetTargetDistance(const idBot&) const = 0;
    virtual unsigned int GetTargetFlags(const idBot&) const = 0;
    virtual unsigned int RandomPercent() = 0;
    virtual bool CanMoveInDirection(idBot&, idBotAttackMoveDirection,
        float units) = 0;
    virtual void SetMoveSubGoal(idBot&, idBotAttackMoveDirection,
        float units, float radius, bool stopAtPoint) = 0;
    virtual void RequestJump(idBot&) = 0;
    virtual void StartEnemyMove(idBot&, const char* userName,
        int moveStance, float moveTolerance) = 0;
    virtual void SetIdleStance(idBot&, int moveStance) = 0;
    virtual void TouchTargetRecord(idBot&) = 0;
};

void Tungsten_SetBotCombatAttackServices(
    idBotCombatAttackServices* services);

class idBotBehaviorCombat_RunAndAttackEnemy : public idBehaviorAction {
public:
    idBotBehaviorCombat_RunAndAttackEnemy();
    void MoveSubGoal_Errored_CallBack(idBot*, int currentTime,
        botMoveStatus_t);
    behaviorPriority_t GetPriority(idBot*, int currentTime);
    behaviorStatus_t Think(idBot*, int currentTime);
    void Enter(idBot*, int currentTime);

    bool IsDodging() const { return isDodging; }
    bool IsLeftStrafer() const { return leftyStrafer; }
    int GetLastJumpTime() const { return lastJumpTime; }
    int GetLastDodgeTime() const { return lastDodgeTime; }
private:
    bool isDodging;
    bool leftyStrafer;
    int lastJumpTime;
    int lastDodgeTime;
};

class idBotBehaviorCombat_CircleStafeEnemy : public idBehaviorAction {
public:
    idBotBehaviorCombat_CircleStafeEnemy();
    behaviorPriority_t GetPriority(idBot*, int currentTime);
    behaviorStatus_t Think(idBot*, int currentTime);
    void Enter(idBot*, int currentTime);
    bool IsLeftStrafer() const { return leftyStrafer; }
    int GetBehaviorFinishTime() const { return behaviorFinishTime; }
private:
    bool leftyStrafer;
    int behaviorFinishTime;
};

class idBotBehaviorCombat_SideStrafeEnemy : public idBehaviorAction {
public:
    idBotBehaviorCombat_SideStrafeEnemy();
    behaviorPriority_t GetPriority(idBot*, int currentTime);
    behaviorStatus_t Think(idBot*, int currentTime);
    void Enter(idBot*, int currentTime);
    bool HasJumped() const { return jumped; }
    bool ShouldJump() const { return shouldJump; }
    int GetBehaviorFinishTime() const { return behaviorFinishTime; }
private:
    bool jumped;
    bool leftyStrafer;
    bool shouldJump;
    int behaviorFinishTime;
};

class idBotBehaviorCombat_QuickSideToSideStrafeEnemy : public idBehaviorAction {
public:
    idBotBehaviorCombat_QuickSideToSideStrafeEnemy();
    behaviorPriority_t GetPriority(idBot*, int currentTime);
    behaviorStatus_t Think(idBot*, int currentTime);
    void Enter(idBot*, int currentTime);
    int GetBehaviorTime() const { return behaviorTime; }
    int GetStrafeDirectionDeadline() const { return strafeDirDuration; }
private:
    bool leftyStrafer;
    int behaviorTime;
    int strafeDirDuration;
};

class idBotBehaviorCombat_StandGroundAttackEnemy : public idBehaviorAction {
public:
    idBotBehaviorCombat_StandGroundAttackEnemy();
    void MoveSubGoal_Started_CallBack(idBot*, int currentTime);
    behaviorPriority_t GetPriority(idBot*, int currentTime);
    behaviorStatus_t Think(idBot*, int currentTime);
    void Enter(idBot*, int currentTime);
    bool IsBackingAway() const { return backingAway; }
    int GetBehaviorTime() const { return behaviorTime; }
private:
    bool backingAway;
    int behaviorTime;
};

class idBotBehaviorCombat_GrenadeAttackEnemy : public idBehaviorAction {
public:
    idBotBehaviorCombat_GrenadeAttackEnemy();
};

class idBotBehaviorCombat_RandomJumpAttackEnemy : public idBehaviorAction {
public:
    idBotBehaviorCombat_RandomJumpAttackEnemy();
    void MoveSubGoal_Errored_CallBack(idBot*, int currentTime,
        botMoveStatus_t);
    void MoveSubGoal_Started_CallBack(idBot*, int currentTime);
    void MoveSubGoal_Reached_CallBack(idBot*, int currentTime);
    behaviorPriority_t GetPriority(idBot*, int currentTime);
    behaviorStatus_t Think(idBot*, int currentTime);
    void Enter(idBot*, int currentTime);

    bool HasJumped() const { return hasJumped; }
    bool IsMoving() const { return isMoving; }
    idBotAttackMoveDirection GetJumpDirection() const { return jumpDir; }
    int GetBehaviorTime() const { return behaviorTime; }
    int GetStateUseCooldownTime() const { return stateUseCooldownTime; }
    void SetLastStateRunTime(int value) { lastStateRunTime = value; }
private:
    bool hasJumped;
    bool isMoving;
    idBotAttackMoveDirection jumpDir;
    int behaviorTime;
    int stateUseCooldownTime;
    int lastStateRunTime;
};

class idBotBehaviorCombat_CrouchAttackEnemy : public idBehaviorAction {
public:
    idBotBehaviorCombat_CrouchAttackEnemy();
    void MoveSubGoal_Reached_CallBack(idBot*, int currentTime);
    behaviorPriority_t GetPriority(idBot*, int currentTime);
    void Enter(idBot*, int currentTime);
    bool IsBackingAway() const { return backingAway; }
    int GetBehaviorTime() const { return behaviorTime; }
private:
    bool backingAway;
    int behaviorTime;
};

class idBotBehaviorCombat_MeleeAttackEnemy : public idBehaviorAction {
public:
    idBotBehaviorCombat_MeleeAttackEnemy();
    behaviorPriority_t GetPriority(idBot*, int currentTime);
    void Enter(idBot*, int currentTime);
    bool IsMoveBlocked() const { return moveBlocked; }
    void SetMoveBlocked(bool value) { moveBlocked = value; }
private:
    bool moveBlocked;
};
