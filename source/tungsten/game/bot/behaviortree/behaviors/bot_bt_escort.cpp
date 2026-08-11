#include "bot_bt_escort.h"

namespace {
idBotEscortServices* g_services = nullptr;
}

void Tungsten_SetBotEscortServices(idBotEscortServices* const services) {
    g_services = services;
}

// Retail symbol: ??0idBotBehaviorEscort@@QAA@XZ
// EA: 0x82B37C38, RVA: 0x00B37C38
idBotBehaviorEscort::idBotBehaviorEscort()
    : reachedMate(false), avoidingMate(false), timeReachedMate(0),
      timeInMatesCrossHair(0), timeMateHasBeenCrouched(0),
      currentMoveTolerance(128.0f) {
}

// Retail symbol: ?MoveGoal_Reached_CallBack@idBotBehaviorEscort@@UAAXPAVidBot@@H@Z
// EA: 0x82B37CD8, RVA: 0x00B37CD8
void idBotBehaviorEscort::MoveGoal_Reached_CallBack(idBot*,
        const int currentTime) {
    if (!reachedMate) {
        timeReachedMate = currentTime;
        reachedMate = true;
        currentMoveTolerance = 386.0f;
    }
    avoidingMate = false;
}

// Retail symbol: ?MoveSubGoal_Reached_CallBack@idBotBehaviorEscort@@UAAXPAVidBot@@H@Z
// EA: 0x82B37D18, RVA: 0x00B37D18
void idBotBehaviorEscort::MoveSubGoal_Reached_CallBack(idBot* const bot,
        const int currentTime) {
    MoveGoal_Reached_CallBack(bot, currentTime);
}

// Retail symbol: ?MoveSubGoal_Errored_CallBack@idBotBehaviorEscort@@UAAXPAVidBot@@HW4botMoveStatus_t@@@Z
// EA: 0x82B37D28, RVA: 0x00B37D28
void idBotBehaviorEscort::MoveSubGoal_Errored_CallBack(
        idBot*, int, botMoveStatus_t) {
    avoidingMate = false;
}

// Retail symbol: ?MoveGoal_Started_CallBack@idBotBehaviorEscort@@UAAXPAVidBot@@H@Z
// EA: 0x82B37D38, RVA: 0x00B37D38
void idBotBehaviorEscort::MoveGoal_Started_CallBack(idBot*, int) {
    reachedMate = false;
    timeReachedMate = 0;
    avoidingMate = false;
    currentMoveTolerance = 128.0f;
}

// Retail symbol: ?MoveSubGoal_Started_CallBack@idBotBehaviorEscort@@UAAXPAVidBot@@H@Z
// EA: 0x82B37D58, RVA: 0x00B37D58
void idBotBehaviorEscort::MoveSubGoal_Started_CallBack(idBot*, int) {
    reachedMate = false;
    timeReachedMate = 0;
    avoidingMate = true;
    timeInMatesCrossHair = 0;
}

// Retail symbol: ?GetPriority@idBotBehaviorEscort@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B37D78, RVA: 0x00B37D78
behaviorPriority_t idBotBehaviorEscort::GetPriority(
        idBot* const bot, int) {
    return bot != nullptr && g_services != nullptr
        && g_services->HasEscortGoal(*bot)
        && g_services->IsTeammateValid(*bot)
        ? BEHAVIOR_PRIORITY_NORMAL : BEHAVIOR_PRIORITY_NULL;
}

// Retail symbol: ?Enter@idBotBehaviorEscort@@UAAXPAVidBot@@H@Z
// EA: 0x82B37DF8, RVA: 0x00B37DF8
void idBotBehaviorEscort::Enter(idBot* const bot, int) {
    reachedMate = false;
    timeReachedMate = 0;
    currentMoveTolerance = 128.0f;
    timeMateHasBeenCrouched = 0;
    timeInMatesCrossHair = 0;
    avoidingMate = false;
    if (bot != nullptr && g_services != nullptr) {
        g_services->SetMoveStance(*bot, BOT_ESCORT_STANCE_RUN);
        g_services->StartEscortMove(*bot, currentMoveTolerance);
    }
}

// Retail symbol: ?Update_ReachedTeammateBehavior@idBotBehaviorEscort@@QAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B37F10, RVA: 0x00B37F10
behaviorStatus_t idBotBehaviorEscort::Update_ReachedTeammateBehavior(
        idBot* const bot, const int currentTime) {
    if (bot == nullptr || g_services == nullptr) {
        return BEHAVIOR_STATUS_FAILURE;
    }
    const float distance = g_services->GetTeammateDistance(*bot);
    g_services->SetMoveStance(*bot, BOT_ESCORT_STANCE_RUN);
    if (g_services->IsTeammateCrouched(*bot)) {
        if (timeMateHasBeenCrouched == 0) {
            timeMateHasBeenCrouched = currentTime;
        }
        if (timeMateHasBeenCrouched + 900 < currentTime) {
            g_services->SetMoveStance(*bot, BOT_ESCORT_STANCE_CROUCH);
        }
    } else {
        timeMateHasBeenCrouched = 0;
    }
    if (distance <= 64.0f) {
        g_services->RequestAvoidance(*bot, 48.0f, 0.0f);
    } else if (g_services->IsInTeammateCrosshair(*bot)) {
        if (timeInMatesCrossHair == 0) {
            timeInMatesCrossHair = currentTime;
        }
        if (timeInMatesCrossHair + 1200 < currentTime
                || g_services->TeammateRequestsSpace(*bot)) {
            g_services->RequestAvoidance(
                *bot, 64.0f, currentMoveTolerance);
        }
    } else {
        timeInMatesCrossHair = 0;
    }
    if (g_services->HasEnemy(*bot)) {
        g_services->AimAtEnemy(*bot);
        g_services->RequestPrimaryWeapon(*bot);
    } else if (timeReachedMate + 2500 > currentTime) {
        g_services->AimAtTeammate(*bot);
    }
    return BEHAVIOR_STATUS_RUNNING;
}

// Retail symbol: ?Update_MovingToTeammateBehavior@idBotBehaviorEscort@@QAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B38370, RVA: 0x00B38370
behaviorStatus_t idBotBehaviorEscort::Update_MovingToTeammateBehavior(
        idBot* const bot, int) {
    if (bot == nullptr || g_services == nullptr) {
        return BEHAVIOR_STATUS_FAILURE;
    }
    const float distance = g_services->GetTeammateDistance(*bot);
    bool sprinting = false;
    g_services->SetMoveStance(*bot, BOT_ESCORT_STANCE_RUN);
    if (distance > 768.0f) {
        sprinting = true;
        g_services->SetMoveStance(*bot, BOT_ESCORT_STANCE_SPRINT);
    } else if (distance < 512.0f
            && g_services->IsTeammateCrouched(*bot)) {
        g_services->SetMoveStance(*bot, BOT_ESCORT_STANCE_CROUCH);
    }
    if (g_services->HasEnemy(*bot) && !sprinting) {
        g_services->AimAtEnemy(*bot);
        g_services->RequestPrimaryWeapon(*bot);
    } else if (avoidingMate) {
        g_services->AimAtTeammate(*bot);
    }
    return BEHAVIOR_STATUS_RUNNING;
}

// Retail symbol: ?Think@idBotBehaviorEscort@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B38570, RVA: 0x00B38570
behaviorStatus_t idBotBehaviorEscort::Think(idBot* const bot,
        const int currentTime) {
    if (bot == nullptr || g_services == nullptr
            || !g_services->IsTeammateValid(*bot)
            || g_services->IsTeammateDead(*bot)) {
        if (bot != nullptr && g_services != nullptr) {
            g_services->ResetGoal(*bot);
        }
        return BEHAVIOR_STATUS_FAILURE;
    }
    const behaviorStatus_t status = reachedMate
        ? Update_ReachedTeammateBehavior(bot, currentTime)
        : Update_MovingToTeammateBehavior(bot, currentTime);
    g_services->SetMoveTolerance(*bot, currentMoveTolerance);
    return status;
}
