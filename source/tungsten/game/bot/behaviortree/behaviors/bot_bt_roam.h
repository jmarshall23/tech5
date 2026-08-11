#pragma once

#include "bot_bt_combat.h"

class idBotRoamServices {
public:
    virtual ~idBotRoamServices() = default;
    virtual bool CheckStateFlag(const idBot&, int flag) const = 0;
    virtual bool HasRoamGoal(const idBot&) const = 0;
    virtual bool IsRoamGoalPositionZero(const idBot&) const = 0;
    virtual void ResetGoal(idBot&) = 0;
    virtual void StartRoamMove(idBot&, const char* userName,
        int moveStance, float moveTolerance) = 0;
    virtual void SetIdleStance(idBot&, int moveStance) = 0;
};

void Tungsten_SetBotRoamServices(idBotRoamServices* services);

class idBotBehaviorRoam : public idBehaviorAction {
public:
    idBotBehaviorRoam();

    void MoveGoal_Reached_CallBack(idBot* bot, int currentTime) override;
    behaviorPriority_t GetPriority(idBot* bot, int currentTime) override;
    void Enter(idBot* bot, int currentTime) override;
    const char* GetClassName() const override { return "idBotBehaviorRoam"; }

    bool IsMoveStuck() const { return moveStuck; }
    void SetMoveStuck(bool value) { moveStuck = value; }

private:
    bool moveStuck;
};
