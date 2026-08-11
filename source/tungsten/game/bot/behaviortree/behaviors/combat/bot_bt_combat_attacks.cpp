#include "bot_bt_combat_attacks.h"

#include <cstddef>

namespace {
idBotCombatAttackServices* g_services = nullptr;

constexpr int ACTIVE_STATE_FLAG = 1;
constexpr int MOVE_STANCE_CROUCH_VALUE = 1;
constexpr int MOVE_STANCE_RUN_VALUE = 3;
constexpr float UNBOUNDED_MOVE_TOLERANCE = 1.0e30f;

idBotAttackMoveDirection LateralDirection(const bool left) {
    return left ? BOT_ATTACK_MOVE_LEFT : BOT_ATTACK_MOVE_RIGHT;
}

idBotAttackMoveDirection AwayDirection(const bool left) {
    return left ? BOT_ATTACK_MOVE_BACK_LEFT : BOT_ATTACK_MOVE_BACK_RIGHT;
}

bool AttackIsActive(const idBot& bot) {
    return g_services->CheckStateFlag(bot, ACTIVE_STATE_FLAG);
}

bool PickStrafeDirection(idBot& bot, bool& left, const float units) {
    left = g_services->RandomPercent() > 50U;
    for (int attempt = 0; attempt < 2; ++attempt) {
        if (g_services->CanMoveInDirection(
                bot, LateralDirection(left), units)) {
            return true;
        }
        left = !left;
    }
    return false;
}

bool PickAvailableDirection(idBot& bot,
        idBotAttackMoveDirection* directions, int count,
        const float units, idBotAttackMoveDirection& selected) {
    while (count > 0) {
        const int index = static_cast<int>(
            g_services->RandomPercent() % static_cast<unsigned int>(count));
        if (g_services->CanMoveInDirection(bot, directions[index], units)) {
            selected = directions[index];
            return true;
        }
        --count;
        directions[index] = directions[count];
    }
    return false;
}

int BuildJumpDirections(const float distance,
        idBotAttackMoveDirection (&directions)[3]) {
    if (distance < 256.0f) {
        directions[0] = BOT_ATTACK_MOVE_BACK_RIGHT;
        directions[1] = BOT_ATTACK_MOVE_BACK_LEFT;
        directions[2] = BOT_ATTACK_MOVE_NORTH;
        return 3;
    }
    if (distance > 512.0f) {
        directions[0] = BOT_ATTACK_MOVE_SOUTH;
        directions[1] = BOT_ATTACK_MOVE_FORWARD_RIGHT;
        directions[2] = BOT_ATTACK_MOVE_FORWARD_LEFT;
        return 3;
    }
    directions[0] = BOT_ATTACK_MOVE_RIGHT;
    directions[1] = BOT_ATTACK_MOVE_LEFT;
    return 2;
}

void StartAttackMove(idBot& bot, const char* const name,
        const int stance, const float tolerance) {
    g_services->StartEnemyMove(bot, name, stance, tolerance);
    g_services->SetIdleStance(bot, stance);
}
} // namespace

void Tungsten_SetBotCombatAttackServices(
        idBotCombatAttackServices* const services) {
    g_services = services;
}

// Retail symbol: ??0idBotBehaviorCombat_RunAndAttackEnemy@@QAA@XZ
// EA: 0x82B38880, RVA: 0x00B38880
idBotBehaviorCombat_RunAndAttackEnemy::
idBotBehaviorCombat_RunAndAttackEnemy()
    : isDodging(false), leftyStrafer(false), lastJumpTime(0),
      lastDodgeTime(0) {
}

// Retail symbol: ?MoveSubGoal_Errored_CallBack@idBotBehaviorCombat_RunAndAttackEnemy@@UAAXPAVidBot@@HW4botMoveStatus_t@@@Z
// EA: 0x82B388D0, RVA: 0x00B388D0
void idBotBehaviorCombat_RunAndAttackEnemy::
MoveSubGoal_Errored_CallBack(idBot*, const int currentTime,
        botMoveStatus_t) {
    lastDodgeTime = currentTime;
    isDodging = false;
}

// Retail symbol: ??0idBotBehaviorCombat_CircleStafeEnemy@@QAA@XZ
// EA: 0x82B388E0, RVA: 0x00B388E0
idBotBehaviorCombat_CircleStafeEnemy::idBotBehaviorCombat_CircleStafeEnemy()
    : leftyStrafer(false), behaviorFinishTime(0) {
}

// Retail symbol: ??0idBotBehaviorCombat_SideStrafeEnemy@@QAA@XZ
// EA: 0x82B38928, RVA: 0x00B38928
idBotBehaviorCombat_SideStrafeEnemy::idBotBehaviorCombat_SideStrafeEnemy()
    : jumped(false), leftyStrafer(false), shouldJump(false),
      behaviorFinishTime(0) {
}

// Retail symbol: ??0idBotBehaviorCombat_QuickSideToSideStrafeEnemy@@QAA@XZ
// EA: 0x82B38978, RVA: 0x00B38978
idBotBehaviorCombat_QuickSideToSideStrafeEnemy::
idBotBehaviorCombat_QuickSideToSideStrafeEnemy()
    : leftyStrafer(false), behaviorTime(0), strafeDirDuration(0) {
}

// Retail symbol: ??0idBotBehaviorCombat_StandGroundAttackEnemy@@QAA@XZ
// EA: 0x82B389C8, RVA: 0x00B389C8
idBotBehaviorCombat_StandGroundAttackEnemy::
idBotBehaviorCombat_StandGroundAttackEnemy()
    : backingAway(false), behaviorTime(0) {
}

// Retail symbol: ??0idBotBehaviorCombat_GrenadeAttackEnemy@@QAA@XZ
// EA: 0x82B38A10, RVA: 0x00B38A10
idBotBehaviorCombat_GrenadeAttackEnemy::
idBotBehaviorCombat_GrenadeAttackEnemy() = default;

// Retail symbol: ?MoveSubGoal_Errored_CallBack@idBotBehaviorCombat_RandomJumpAttackEnemy@@UAAXPAVidBot@@HW4botMoveStatus_t@@@Z
// EA: 0x82B38A50, RVA: 0x00B38A50
void idBotBehaviorCombat_RandomJumpAttackEnemy::
MoveSubGoal_Errored_CallBack(idBot*, int, botMoveStatus_t) {
    behaviorTime = 0;
}

// Retail symbol: ?MoveSubGoal_Started_CallBack@idBotBehaviorCombat_RandomJumpAttackEnemy@@UAAXPAVidBot@@H@Z
// EA: 0x82B38A60, RVA: 0x00B38A60
void idBotBehaviorCombat_RandomJumpAttackEnemy::
MoveSubGoal_Started_CallBack(idBot*, int) {
    isMoving = true;
    hasJumped = false;
}

// Retail symbol: ?MoveSubGoal_Reached_CallBack@idBotBehaviorCombat_RandomJumpAttackEnemy@@UAAXPAVidBot@@H@Z
// EA: 0x82B38A78, RVA: 0x00B38A78
void idBotBehaviorCombat_RandomJumpAttackEnemy::
MoveSubGoal_Reached_CallBack(idBot*, int) {
    isMoving = false;
    hasJumped = false;
}

// Retail symbol: ??0idBotBehaviorCombat_CrouchAttackEnemy@@QAA@XZ
// EA: 0x82B38A88, RVA: 0x00B38A88
idBotBehaviorCombat_CrouchAttackEnemy::
idBotBehaviorCombat_CrouchAttackEnemy()
    : backingAway(false), behaviorTime(0) {
}

// Retail symbol: ?MoveSubGoal_Reached_CallBack@idBotBehaviorCombat_CrouchAttackEnemy@@UAAXPAVidBot@@H@Z
// EA: 0x82B38AD0, RVA: 0x00B38AD0
void idBotBehaviorCombat_CrouchAttackEnemy::
MoveSubGoal_Reached_CallBack(idBot*, int) {
    backingAway = false;
}

// Retail symbol: ??0idBotBehaviorCombat_MeleeAttackEnemy@@QAA@XZ
// EA: 0x82B38AE0, RVA: 0x00B38AE0
idBotBehaviorCombat_MeleeAttackEnemy::
idBotBehaviorCombat_MeleeAttackEnemy() : moveBlocked(false) {
}

// Retail symbol: ?MoveSubGoal_Started_CallBack@idBotBehaviorCombat_StandGroundAttackEnemy@@UAAXPAVidBot@@H@Z
// EA: 0x82B38B28, RVA: 0x00B38B28
void idBotBehaviorCombat_StandGroundAttackEnemy::
MoveSubGoal_Started_CallBack(idBot*, int) {
    backingAway = true;
}

// Retail symbol: ?GetPriority@idBotBehaviorCombat_RunAndAttackEnemy@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B38BA0, RVA: 0x00B38BA0
behaviorPriority_t idBotBehaviorCombat_RunAndAttackEnemy::GetPriority(
        idBot* const bot, int) {
    if (bot == nullptr || g_services == nullptr) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    const float distance = g_services->GetTargetDistance(*bot);
    if (distance < 512.0f
            && (g_services->GetTargetFlags(*bot) & 0x20U) != 0U) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    return distance > 64.0f
        ? BEHAVIOR_PRIORITY_NORMAL : BEHAVIOR_PRIORITY_NULL;
}

// Retail symbol: ?Think@idBotBehaviorCombat_RunAndAttackEnemy@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B38C20, RVA: 0x00B38C20
behaviorStatus_t idBotBehaviorCombat_RunAndAttackEnemy::Think(
        idBot* const bot, int) {
    if (bot == nullptr || g_services == nullptr) {
        return BEHAVIOR_STATUS_FAILURE;
    }
    g_services->TouchTargetRecord(*bot);
    return BEHAVIOR_STATUS_RUNNING;
}

// Retail symbol: ?GetPriority@idBotBehaviorCombat_CircleStafeEnemy@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B38C98, RVA: 0x00B38C98
behaviorPriority_t idBotBehaviorCombat_CircleStafeEnemy::GetPriority(
        idBot* const bot, const int currentTime) {
    if (bot == nullptr || g_services == nullptr) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    const bool active = AttackIsActive(*bot);
    if (active && behaviorFinishTime < currentTime) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    const float distance = g_services->GetTargetDistance(*bot);
    if (distance < 64.0f || distance > 386.0f) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    if (!active && !PickStrafeDirection(*bot, leftyStrafer, 96.0f)) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    return BEHAVIOR_PRIORITY_NORMAL;
}

// Retail symbol: ?Think@idBotBehaviorCombat_CircleStafeEnemy@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B38DE8, RVA: 0x00B38DE8
behaviorStatus_t idBotBehaviorCombat_CircleStafeEnemy::Think(
        idBot* const bot, int) {
    if (bot == nullptr || g_services == nullptr) {
        return BEHAVIOR_STATUS_FAILURE;
    }
    const idBotAttackMoveDirection direction =
        LateralDirection(leftyStrafer);
    if (!g_services->CanMoveInDirection(*bot, direction, 48.0f)) {
        return BEHAVIOR_STATUS_FAILURE;
    }
    g_services->SetMoveSubGoal(*bot, direction, 48.0f, 16.0f, false);
    return BEHAVIOR_STATUS_RUNNING;
}

// Retail symbol: ?GetPriority@idBotBehaviorCombat_SideStrafeEnemy@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B38E70, RVA: 0x00B38E70
behaviorPriority_t idBotBehaviorCombat_SideStrafeEnemy::GetPriority(
        idBot* const bot, const int currentTime) {
    if (bot == nullptr || g_services == nullptr) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    if (AttackIsActive(*bot)) {
        return behaviorFinishTime >= currentTime
            ? BEHAVIOR_PRIORITY_NORMAL : BEHAVIOR_PRIORITY_NULL;
    }
    const float distance = g_services->GetTargetDistance(*bot);
    if (distance < 192.0f || distance > 768.0f
            || !PickStrafeDirection(*bot, leftyStrafer, 96.0f)) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    return BEHAVIOR_PRIORITY_NORMAL;
}

// Retail symbol: ?Think@idBotBehaviorCombat_SideStrafeEnemy@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B38FC0, RVA: 0x00B38FC0
behaviorStatus_t idBotBehaviorCombat_SideStrafeEnemy::Think(
        idBot* const bot, int) {
    if (bot == nullptr || g_services == nullptr) {
        return BEHAVIOR_STATUS_FAILURE;
    }
    idBotAttackMoveDirection direction;
    float units;
    if (g_services->GetTargetDistance(*bot) > 128.0f) {
        if (shouldJump && !jumped && g_services->RandomPercent() < 15U) {
            g_services->RequestJump(*bot);
            jumped = true;
        }
        direction = LateralDirection(leftyStrafer);
        units = 48.0f;
        if (!g_services->CanMoveInDirection(*bot, direction, units)) {
            return BEHAVIOR_STATUS_FAILURE;
        }
    } else {
        units = 64.0f;
        bool side = leftyStrafer;
        int attempt = 0;
        for (; attempt < 2; ++attempt) {
            direction = AwayDirection(side);
            if (g_services->CanMoveInDirection(*bot, direction, units)) {
                break;
            }
            side = !side;
        }
        if (attempt == 2) {
            return BEHAVIOR_STATUS_FAILURE;
        }
    }
    g_services->SetMoveSubGoal(*bot, direction, units, 16.0f, false);
    return BEHAVIOR_STATUS_RUNNING;
}

// Retail symbol: ?GetPriority@idBotBehaviorCombat_QuickSideToSideStrafeEnemy@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B39120, RVA: 0x00B39120
behaviorPriority_t
idBotBehaviorCombat_QuickSideToSideStrafeEnemy::GetPriority(
        idBot* const bot, const int currentTime) {
    if (bot == nullptr || g_services == nullptr) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    const bool active = AttackIsActive(*bot);
    if (active && behaviorTime < currentTime) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    const float distance = g_services->GetTargetDistance(*bot);
    if (distance < 192.0f || distance > 768.0f) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    if (!active && !PickStrafeDirection(*bot, leftyStrafer, 144.0f)) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    return BEHAVIOR_PRIORITY_NORMAL;
}

// Retail symbol: ?Think@idBotBehaviorCombat_QuickSideToSideStrafeEnemy@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B39270, RVA: 0x00B39270
behaviorStatus_t idBotBehaviorCombat_QuickSideToSideStrafeEnemy::Think(
        idBot* const bot, const int currentTime) {
    if (bot == nullptr || g_services == nullptr) {
        return BEHAVIOR_STATUS_FAILURE;
    }
    const float distance = g_services->GetTargetDistance(*bot);
    idBotAttackMoveDirection direction;
    float units;
    if (distance > 256.0f) {
        units = 48.0f;
        if (strafeDirDuration < currentTime) {
            leftyStrafer = !leftyStrafer;
            direction = LateralDirection(leftyStrafer);
            if (g_services->CanMoveInDirection(*bot, direction, units)) {
                strafeDirDuration = currentTime + 700;
                g_services->SetMoveSubGoal(
                    *bot, direction, units, 16.0f, false);
                return BEHAVIOR_STATUS_RUNNING;
            }
        }
        direction = LateralDirection(leftyStrafer);
    } else {
        units = 64.0f;
        direction = AwayDirection(leftyStrafer);
    }
    if (!g_services->CanMoveInDirection(*bot, direction, units)) {
        return BEHAVIOR_STATUS_FAILURE;
    }
    g_services->SetMoveSubGoal(*bot, direction, units, 16.0f, false);
    return BEHAVIOR_STATUS_RUNNING;
}

// Retail symbol: ?GetPriority@idBotBehaviorCombat_StandGroundAttackEnemy@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B393A8, RVA: 0x00B393A8
behaviorPriority_t
idBotBehaviorCombat_StandGroundAttackEnemy::GetPriority(
        idBot* const bot, const int currentTime) {
    if (bot == nullptr || g_services == nullptr) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    if (AttackIsActive(*bot) && behaviorTime < currentTime) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    return g_services->GetTargetDistance(*bot) <= 768.0f
        ? BEHAVIOR_PRIORITY_NORMAL : BEHAVIOR_PRIORITY_NULL;
}

// Retail symbol: ??0idBotBehaviorCombat_RandomJumpAttackEnemy@@QAA@XZ
// EA: 0x82B39420, RVA: 0x00B39420
idBotBehaviorCombat_RandomJumpAttackEnemy::
idBotBehaviorCombat_RandomJumpAttackEnemy()
    : hasJumped(false), isMoving(false), jumpDir(BOT_ATTACK_MOVE_MAX),
      behaviorTime(0), stateUseCooldownTime(3500), lastStateRunTime(0) {
}

// Retail symbol: ?GetPriority@idBotBehaviorCombat_CrouchAttackEnemy@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B394E0, RVA: 0x00B394E0
behaviorPriority_t idBotBehaviorCombat_CrouchAttackEnemy::GetPriority(
        idBot* const bot, const int currentTime) {
    if (bot == nullptr || g_services == nullptr) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    const float distance = g_services->GetTargetDistance(*bot);
    if (AttackIsActive(*bot)) {
        if (behaviorTime < currentTime || distance < 128.0f) {
            return BEHAVIOR_PRIORITY_NULL;
        }
    } else if (distance < 386.0f) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    return (g_services->GetTargetFlags(*bot) & 0x20U) != 0U
        ? BEHAVIOR_PRIORITY_NORMAL : BEHAVIOR_PRIORITY_NULL;
}

// Retail symbol: ?Think@idBotBehaviorCombat_StandGroundAttackEnemy@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B39580, RVA: 0x00B39580
behaviorStatus_t idBotBehaviorCombat_StandGroundAttackEnemy::Think(
        idBot* const bot, int) {
    if (bot == nullptr || g_services == nullptr) {
        return BEHAVIOR_STATUS_FAILURE;
    }
    if (!backingAway && g_services->GetTargetDistance(*bot) < 386.0f) {
        const idBotAttackMoveDirection directions[] = {
            BOT_ATTACK_MOVE_SOUTH,
            BOT_ATTACK_MOVE_BACK_RIGHT,
            BOT_ATTACK_MOVE_BACK_LEFT
        };
        int index = 0;
        for (; index < 3; ++index) {
            if (g_services->CanMoveInDirection(
                    *bot, directions[index], 64.0f)) {
                g_services->SetMoveSubGoal(
                    *bot, directions[index], 64.0f, 16.0f, false);
                break;
            }
        }
        if (index == 3) {
            return BEHAVIOR_STATUS_FAILURE;
        }
    }
    return BEHAVIOR_STATUS_RUNNING;
}

// Retail symbol: ?GetPriority@idBotBehaviorCombat_MeleeAttackEnemy@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B39628, RVA: 0x00B39628
behaviorPriority_t idBotBehaviorCombat_MeleeAttackEnemy::GetPriority(
        idBot* const bot, int) {
    if (bot == nullptr || g_services == nullptr) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    return !AttackIsActive(*bot) || !moveBlocked
        ? BEHAVIOR_PRIORITY_NORMAL : BEHAVIOR_PRIORITY_NULL;
}

// Retail symbol: ?Enter@idBotBehaviorCombat_RunAndAttackEnemy@@UAAXPAVidBot@@H@Z
// EA: 0x82B39680, RVA: 0x00B39680
void idBotBehaviorCombat_RunAndAttackEnemy::Enter(
        idBot* const bot, int) {
    isDodging = false;
    lastJumpTime = 0;
    lastDodgeTime = 0;
    if (g_services == nullptr) {
        return;
    }
    leftyStrafer = g_services->RandomPercent() > 50U;
    if (bot != nullptr) {
        StartAttackMove(*bot, "RunAndAttackEnemy",
            MOVE_STANCE_RUN_VALUE, 64.0f);
    }
}

// Retail symbol: ?Enter@idBotBehaviorCombat_CircleStafeEnemy@@UAAXPAVidBot@@H@Z
// EA: 0x82B397F0, RVA: 0x00B397F0
void idBotBehaviorCombat_CircleStafeEnemy::Enter(
        idBot* const bot, const int currentTime) {
    behaviorFinishTime = currentTime + 3500;
    if (bot != nullptr && g_services != nullptr) {
        StartAttackMove(*bot, "CircleStrafeEnemy",
            MOVE_STANCE_RUN_VALUE, UNBOUNDED_MOVE_TOLERANCE);
    }
}

// Retail symbol: ?Enter@idBotBehaviorCombat_SideStrafeEnemy@@UAAXPAVidBot@@H@Z
// EA: 0x82B398F0, RVA: 0x00B398F0
void idBotBehaviorCombat_SideStrafeEnemy::Enter(
        idBot* const bot, const int currentTime) {
    behaviorFinishTime = currentTime + 3000;
    jumped = false;
    if (g_services == nullptr) {
        shouldJump = false;
        return;
    }
    shouldJump = g_services->RandomPercent() <= 15U;
    if (bot != nullptr) {
        StartAttackMove(*bot, "SideStrafeEnemy",
            MOVE_STANCE_RUN_VALUE, UNBOUNDED_MOVE_TOLERANCE);
    }
}

// Retail symbol: ?Enter@idBotBehaviorCombat_QuickSideToSideStrafeEnemy@@UAAXPAVidBot@@H@Z
// EA: 0x82B39A58, RVA: 0x00B39A58
void idBotBehaviorCombat_QuickSideToSideStrafeEnemy::Enter(
        idBot* const bot, const int currentTime) {
    behaviorTime = currentTime + 5500;
    strafeDirDuration = currentTime + 700;
    if (bot != nullptr && g_services != nullptr) {
        StartAttackMove(*bot, "QuickSideToSideStrafeEnemy",
            MOVE_STANCE_RUN_VALUE, UNBOUNDED_MOVE_TOLERANCE);
    }
}

// Retail symbol: ?Enter@idBotBehaviorCombat_StandGroundAttackEnemy@@UAAXPAVidBot@@H@Z
// EA: 0x82B39B60, RVA: 0x00B39B60
void idBotBehaviorCombat_StandGroundAttackEnemy::Enter(
        idBot* const bot, const int currentTime) {
    behaviorTime = currentTime + 700;
    backingAway = false;
    if (bot != nullptr && g_services != nullptr) {
        StartAttackMove(*bot, "StandGroundAttackEnemy",
            MOVE_STANCE_RUN_VALUE, UNBOUNDED_MOVE_TOLERANCE);
    }
}

// Retail symbol: ?Enter@idBotBehaviorCombat_RandomJumpAttackEnemy@@UAAXPAVidBot@@H@Z
// EA: 0x82B39C60, RVA: 0x00B39C60
void idBotBehaviorCombat_RandomJumpAttackEnemy::Enter(
        idBot* const bot, const int currentTime) {
    behaviorTime = currentTime + 5500;
    isMoving = false;
    hasJumped = false;
    if (bot != nullptr && g_services != nullptr) {
        StartAttackMove(*bot, "RandomJumpAttackEnemy",
            MOVE_STANCE_RUN_VALUE, UNBOUNDED_MOVE_TOLERANCE);
    }
}

// Retail symbol: ?Enter@idBotBehaviorCombat_CrouchAttackEnemy@@UAAXPAVidBot@@H@Z
// EA: 0x82B39D68, RVA: 0x00B39D68
void idBotBehaviorCombat_CrouchAttackEnemy::Enter(
        idBot* const bot, const int currentTime) {
    behaviorTime = currentTime + 5000;
    backingAway = false;
    if (bot != nullptr && g_services != nullptr) {
        StartAttackMove(*bot, "CrouchAttackEnemy",
            MOVE_STANCE_CROUCH_VALUE, UNBOUNDED_MOVE_TOLERANCE);
    }
}

// Retail symbol: ?Enter@idBotBehaviorCombat_MeleeAttackEnemy@@UAAXPAVidBot@@H@Z
// EA: 0x82B39E68, RVA: 0x00B39E68
void idBotBehaviorCombat_MeleeAttackEnemy::Enter(
        idBot* const bot, int) {
    moveBlocked = false;
    if (bot != nullptr && g_services != nullptr) {
        StartAttackMove(*bot, "MeleeAttackEnemy",
            MOVE_STANCE_RUN_VALUE, 16.0f);
    }
}

// Retail symbol: ?GetPriority@idBotBehaviorCombat_RandomJumpAttackEnemy@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B39F60, RVA: 0x00B39F60
behaviorPriority_t idBotBehaviorCombat_RandomJumpAttackEnemy::GetPriority(
        idBot* const bot, const int currentTime) {
    if (bot == nullptr || g_services == nullptr) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    const bool active = AttackIsActive(*bot);
    if (active && behaviorTime < currentTime) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    const float distance = g_services->GetTargetDistance(*bot);
    if (distance > 768.0f) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    if (!active) {
        if (lastStateRunTime + stateUseCooldownTime > currentTime) {
            return BEHAVIOR_PRIORITY_NULL;
        }
        idBotAttackMoveDirection directions[3];
        const int count = BuildJumpDirections(distance, directions);
        idBotAttackMoveDirection selected = BOT_ATTACK_MOVE_MAX;
        if (!PickAvailableDirection(
                *bot, directions, count, 144.0f, selected)) {
            return BEHAVIOR_PRIORITY_NULL;
        }
        jumpDir = selected;
    }
    return BEHAVIOR_PRIORITY_NORMAL;
}

// Retail symbol: ?Think@idBotBehaviorCombat_RandomJumpAttackEnemy@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B3A208, RVA: 0x00B3A208
behaviorStatus_t idBotBehaviorCombat_RandomJumpAttackEnemy::Think(
        idBot* const bot, int) {
    if (bot == nullptr || g_services == nullptr) {
        return BEHAVIOR_STATUS_FAILURE;
    }
    if (isMoving) {
        if (!hasJumped && g_services->RandomPercent() < 35U) {
            g_services->RequestJump(*bot);
            hasJumped = true;
        }
        return BEHAVIOR_STATUS_RUNNING;
    }
    if (jumpDir != BOT_ATTACK_MOVE_MAX
            && g_services->CanMoveInDirection(*bot, jumpDir, 80.0f)) {
        g_services->SetMoveSubGoal(
            *bot, jumpDir, 80.0f, 16.0f, false);
        jumpDir = BOT_ATTACK_MOVE_MAX;
        return BEHAVIOR_STATUS_RUNNING;
    }
    idBotAttackMoveDirection directions[3];
    const int count = BuildJumpDirections(
        g_services->GetTargetDistance(*bot), directions);
    idBotAttackMoveDirection selected = BOT_ATTACK_MOVE_MAX;
    if (!PickAvailableDirection(*bot, directions, count, 80.0f, selected)) {
        return BEHAVIOR_STATUS_FAILURE;
    }
    g_services->SetMoveSubGoal(
        *bot, selected, 80.0f, 16.0f, false);
    return BEHAVIOR_STATUS_RUNNING;
}
