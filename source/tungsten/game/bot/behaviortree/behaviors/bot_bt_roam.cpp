#include "bot_bt_roam.h"

namespace {
idBotRoamServices* g_services = nullptr;

constexpr int ROAM_GOAL_FLAG = 128;
constexpr int ACTIVE_STATE_FLAG = 1;
constexpr int ROAM_MOVE_STANCE_RUN = 3;
constexpr float ROAM_MOVE_TOLERANCE = 32.0f;
}

void Tungsten_SetBotRoamServices(idBotRoamServices* const services) {
    g_services = services;
}

// Retail symbol: ??0idBotBehaviorRoam@@QAA@XZ
// EA: 0x82B38648, RVA: 0x00B38648
idBotBehaviorRoam::idBotBehaviorRoam() : moveStuck(false) {
}

// Retail symbol: ?MoveGoal_Reached_CallBack@idBotBehaviorRoam@@UAAXPAVidBot@@H@Z
// EA: 0x82B386D0, RVA: 0x00B386D0
void idBotBehaviorRoam::MoveGoal_Reached_CallBack(
        idBot* const bot, int) {
    if (bot != nullptr && g_services != nullptr) {
        g_services->ResetGoal(*bot);
    }
}

// Retail symbol: ?GetPriority@idBotBehaviorRoam@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B38740, RVA: 0x00B38740
behaviorPriority_t idBotBehaviorRoam::GetPriority(
        idBot* const bot, int) {
    if (bot == nullptr || g_services == nullptr) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    if (g_services->CheckStateFlag(*bot, ACTIVE_STATE_FLAG) && moveStuck) {
        g_services->ResetGoal(*bot);
        return BEHAVIOR_PRIORITY_NULL;
    }
    if (!g_services->HasRoamGoal(*bot)
            || g_services->IsRoamGoalPositionZero(*bot)) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    return BEHAVIOR_PRIORITY_NORMAL;
}

// Retail symbol: ?Enter@idBotBehaviorRoam@@UAAXPAVidBot@@H@Z
// EA: 0x82B387E0, RVA: 0x00B387E0
void idBotBehaviorRoam::Enter(idBot* const bot, int) {
    if (bot != nullptr && g_services != nullptr) {
        g_services->StartRoamMove(*bot, "MoveToRoamGoal",
            ROAM_MOVE_STANCE_RUN, ROAM_MOVE_TOLERANCE);
        g_services->SetIdleStance(*bot, ROAM_MOVE_STANCE_RUN);
    }
    moveStuck = false;
}
