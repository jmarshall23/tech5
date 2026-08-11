#pragma once

#include "bot_bt_combat.h"
#include "../../bot_movecmd.h"

enum idBotEscortStance : int {
    BOT_ESCORT_STANCE_CROUCH = 1,
    BOT_ESCORT_STANCE_RUN = 3,
    BOT_ESCORT_STANCE_SPRINT = 4
};

class idBotEscortServices {
public:
    virtual ~idBotEscortServices() = default;
    virtual bool HasEscortGoal(const idBot&) const = 0;
    virtual bool IsTeammateValid(const idBot&) const = 0;
    virtual bool IsTeammateDead(const idBot&) const = 0;
    virtual float GetTeammateDistance(const idBot&) const = 0;
    virtual bool IsTeammateCrouched(const idBot&) const = 0;
    virtual bool HasEnemy(const idBot&) const = 0;
    virtual bool IsInTeammateCrosshair(const idBot&) const = 0;
    virtual bool TeammateRequestsSpace(const idBot&) const = 0;
    virtual void StartEscortMove(idBot&, float tolerance) = 0;
    virtual void SetMoveTolerance(idBot&, float tolerance) = 0;
    virtual void SetMoveStance(idBot&, idBotEscortStance) = 0;
    virtual void RequestAvoidance(idBot&, float distance,
        float anchorRadius) = 0;
    virtual void AimAtEnemy(idBot&) = 0;
    virtual void AimAtTeammate(idBot&) = 0;
    virtual void RequestPrimaryWeapon(idBot&) = 0;
    virtual void ResetGoal(idBot&) = 0;
};

void Tungsten_SetBotEscortServices(idBotEscortServices* services);

class idBotBehaviorEscort : public idBehaviorAction {
public:
    idBotBehaviorEscort();

    void MoveGoal_Reached_CallBack(idBot* bot, int currentTime) override;
    void MoveSubGoal_Reached_CallBack(idBot* bot, int currentTime) override;
    void MoveSubGoal_Errored_CallBack(idBot* bot, int currentTime,
        botMoveStatus_t moveStatus) override;
    void MoveGoal_Started_CallBack(idBot* bot, int currentTime) override;
    void MoveSubGoal_Started_CallBack(idBot* bot, int currentTime) override;
    behaviorPriority_t GetPriority(idBot* bot, int currentTime) override;
    void Enter(idBot* bot, int currentTime) override;
    behaviorStatus_t Update_ReachedTeammateBehavior(idBot* bot,
        int currentTime);
    behaviorStatus_t Update_MovingToTeammateBehavior(idBot* bot,
        int currentTime);
    behaviorStatus_t Think(idBot* bot, int currentTime) override;
    const char* GetClassName() const override { return "idBotBehaviorEscort"; }

    bool HasReachedMate() const { return reachedMate; }
    bool IsAvoidingMate() const { return avoidingMate; }
    int GetTimeReachedMate() const { return timeReachedMate; }
    float GetMoveTolerance() const { return currentMoveTolerance; }

private:
    bool reachedMate;
    bool avoidingMate;
    int timeReachedMate;
    int timeInMatesCrossHair;
    int timeMateHasBeenCrouched;
    float currentMoveTolerance;
};
