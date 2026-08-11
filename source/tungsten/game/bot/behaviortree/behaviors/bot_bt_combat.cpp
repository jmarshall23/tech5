#include "bot_bt_combat.h"
#include "combat/bot_bt_combat_attacks.h"

namespace {
idBotCombatServices* g_services = nullptr;

behaviorPriority_t CategoryPriority(idBot* const bot,
        const idBotCombatWeaponCategory category) {
    return bot != nullptr && g_services != nullptr
        && g_services->GetWeaponCategory(*bot) == category
        ? BEHAVIOR_PRIORITY_NORMAL : BEHAVIOR_PRIORITY_NULL;
}

behaviorStatus_t Aim(idBotCombatBehaviorKind kind, idBot* bot) {
    if (bot != nullptr && g_services != nullptr) {
        g_services->AddAimRequest(kind, *bot);
    }
    return BEHAVIOR_STATUS_RUNNING;
}
} // namespace

void Tungsten_SetBotCombatServices(idBotCombatServices* const services) {
    g_services = services;
}

// Retail symbol: ??0idBotBehaviorCombat_TargetVis@@QAA@XZ
// EA: 0x82B36448, RVA: 0x00B36448
idBotBehaviorCombat_TargetVis::idBotBehaviorCombat_TargetVis() = default;

// Retail symbol: ?GetPriority@idBotBehaviorCombat_TargetVis@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B36488, RVA: 0x00B36488
behaviorPriority_t idBotBehaviorCombat_TargetVis::GetPriority(
        idBot* const bot, const int currentTime) {
    if (bot == nullptr || g_services == nullptr) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    return currentTime < g_services->GetTargetLastVisibleTime(*bot) + 2500
        ? BEHAVIOR_PRIORITY_NORMAL : BEHAVIOR_PRIORITY_NULL;
}

// Retail symbol: ??0idBotBehaviorCombat_TargetVis_CloseRange@@QAA@XZ
// EA: 0x82B364E0, RVA: 0x00B364E0
idBotBehaviorCombat_TargetVis_CloseRange::
idBotBehaviorCombat_TargetVis_CloseRange() = default;

// Retail symbol: ?GetPriority@idBotBehaviorCombat_TargetVis_CloseRange@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B36520, RVA: 0x00B36520
behaviorPriority_t idBotBehaviorCombat_TargetVis_CloseRange::GetPriority(
        idBot* const bot, int) {
    return bot != nullptr && g_services != nullptr
        && g_services->GetTargetDistance(*bot) <= 512.0f
        ? BEHAVIOR_PRIORITY_NORMAL : BEHAVIOR_PRIORITY_NULL;
}

// Retail symbol: ?Think@idBotBehaviorCombat_TargetVis_CloseRange@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B36568, RVA: 0x00B36568
behaviorStatus_t idBotBehaviorCombat_TargetVis_CloseRange::Think(
        idBot* const bot, int) {
    if (bot != nullptr && g_services != nullptr) {
        g_services->AddWeaponRequest(BOT_COMBAT_CLOSE_RANGE, *bot);
    }
    return BEHAVIOR_STATUS_RUNNING;
}

// Retail symbol: ??0idBotBehaviorCombat_TargetVis_CloseRange_Melee@@QAA@XZ
// EA: 0x82B365A8, RVA: 0x00B365A8
idBotBehaviorCombat_TargetVis_CloseRange_Melee::
idBotBehaviorCombat_TargetVis_CloseRange_Melee() = default;

// Retail symbol: ?GetPriority@idBotBehaviorCombat_TargetVis_CloseRange_Melee@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B365E8, RVA: 0x00B365E8
behaviorPriority_t idBotBehaviorCombat_TargetVis_CloseRange_Melee::
GetPriority(idBot* const bot, int) {
    return CategoryPriority(bot, BOT_WEAPON_CATEGORY_MELEE);
}

// Retail symbol: ??0idBotBehaviorCombat_TargetVis_CloseRange_SMG@@QAA@XZ
// EA: 0x82B36608, RVA: 0x00B36608
idBotBehaviorCombat_TargetVis_CloseRange_SMG::
idBotBehaviorCombat_TargetVis_CloseRange_SMG() = default;

// Retail symbol: ?GetPriority@idBotBehaviorCombat_TargetVis_CloseRange_SMG@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B36648, RVA: 0x00B36648
behaviorPriority_t idBotBehaviorCombat_TargetVis_CloseRange_SMG::
GetPriority(idBot* const bot, int) {
    return CategoryPriority(bot, BOT_WEAPON_CATEGORY_SMG);
}

// Retail symbol: ??0idBotBehaviorCombat_TargetVis_CloseRange_Shotgun@@QAA@XZ
// EA: 0x82B36668, RVA: 0x00B36668
idBotBehaviorCombat_TargetVis_CloseRange_Shotgun::
idBotBehaviorCombat_TargetVis_CloseRange_Shotgun() = default;

// Retail symbol: ?GetPriority@idBotBehaviorCombat_TargetVis_CloseRange_Shotgun@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B366A8, RVA: 0x00B366A8
behaviorPriority_t idBotBehaviorCombat_TargetVis_CloseRange_Shotgun::
GetPriority(idBot* const bot, int) {
    return CategoryPriority(bot, BOT_WEAPON_CATEGORY_SHOTGUN);
}

// Retail symbol: ??0idBotBehaviorCombat_TargetVis_CloseRange_Thrown@@QAA@XZ
// EA: 0x82B366C8, RVA: 0x00B366C8
idBotBehaviorCombat_TargetVis_CloseRange_Thrown::
idBotBehaviorCombat_TargetVis_CloseRange_Thrown() = default;

// Retail symbol: ?GetPriority@idBotBehaviorCombat_TargetVis_CloseRange_Sniper@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B36708, RVA: 0x00B36708
behaviorPriority_t idBotBehaviorCombat_TargetVis_CloseRange_Sniper::
GetPriority(idBot* const bot, int) {
    // The retail body at this address explicitly checks THROW weapon category.
    return CategoryPriority(bot, BOT_WEAPON_CATEGORY_THROWN);
}

// Retail symbol: ??0idBotBehaviorCombat_TargetVis_CloseRange_Sniper@@QAA@XZ
// EA: 0x82B36728, RVA: 0x00B36728
idBotBehaviorCombat_TargetVis_CloseRange_Sniper::
idBotBehaviorCombat_TargetVis_CloseRange_Sniper() = default;

// Retail symbol: ??0idBotBehaviorCombat_TargetVis_LongRange@@QAA@XZ
// EA: 0x82B36768, RVA: 0x00B36768
idBotBehaviorCombat_TargetVis_LongRange::
idBotBehaviorCombat_TargetVis_LongRange() = default;

// Retail symbol: ?GetPriority@idBotBehaviorCombat_TargetVis_LongRange@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B367A8, RVA: 0x00B367A8
behaviorPriority_t idBotBehaviorCombat_TargetVis_LongRange::GetPriority(
        idBot* const bot, int) {
    return bot != nullptr && g_services != nullptr
        && g_services->GetTargetDistance(*bot) > 512.0f
        ? BEHAVIOR_PRIORITY_NORMAL : BEHAVIOR_PRIORITY_NULL;
}

// Retail symbol: ?Think@idBotBehaviorCombat_TargetVis_LongRange@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B367F0, RVA: 0x00B367F0
behaviorStatus_t idBotBehaviorCombat_TargetVis_LongRange::Think(
        idBot* const bot, int) {
    if (bot != nullptr && g_services != nullptr) {
        g_services->AddWeaponRequest(BOT_COMBAT_LONG_RANGE, *bot);
    }
    return BEHAVIOR_STATUS_RUNNING;
}

// Retail symbol: ??0idBotBehaviorCombat_NonVisTarget@@QAA@XZ
// EA: 0x82B36830, RVA: 0x00B36830
idBotBehaviorCombat_NonVisTarget::idBotBehaviorCombat_NonVisTarget() = default;

// Retail symbol: ?Init@idBotBehaviorCombat_TargetVis@@UAAXPAVidBot@@H@Z
// EA: 0x82B36C20, RVA: 0x00B36C20
void idBotBehaviorCombat_TargetVis::Init(idBot* bot, int currentTime) {
    AppendState(nullptr, new idBotBehaviorCombat_TargetVis_CloseRange());
    AppendState(nullptr, new idBotBehaviorCombat_TargetVis_LongRange());
    if (bot != nullptr && g_services != nullptr) {
        g_services->InitializeBehavior(
            BOT_COMBAT_TARGET_VISIBLE, *bot, currentTime);
    }
}

// Retail symbol: ?Init@idBotBehaviorCombat_TargetVis_CloseRange@@UAAXPAVidBot@@H@Z
// EA: 0x82B36D58, RVA: 0x00B36D58
void idBotBehaviorCombat_TargetVis_CloseRange::Init(
        idBot* bot, int currentTime) {
    AppendState(nullptr,
        new idBotBehaviorCombat_TargetVis_CloseRange_Melee());
    AppendState(nullptr,
        new idBotBehaviorCombat_TargetVis_CloseRange_SMG());
    AppendState(nullptr,
        new idBotBehaviorCombat_TargetVis_CloseRange_Shotgun());
    AppendState(nullptr,
        new idBotBehaviorCombat_TargetVis_CloseRange_Thrown());
    AppendState(nullptr,
        new idBotBehaviorCombat_TargetVis_CloseRange_Sniper());
    if (bot != nullptr && g_services != nullptr) {
        g_services->InitializeBehavior(BOT_COMBAT_CLOSE_RANGE,
            *bot, currentTime);
    }
}

// Retail symbol: ?Init@idBotBehaviorCombat_TargetVis_CloseRange_Melee@@UAAXPAVidBot@@H@Z
// EA: 0x82B37010, RVA: 0x00B37010
void idBotBehaviorCombat_TargetVis_CloseRange_Melee::Init(
        idBot* bot, int currentTime) {
    AppendState(nullptr, new idBotBehaviorCombat_MeleeAttackEnemy());
    if (bot != nullptr && g_services != nullptr) {
        g_services->InitializeBehavior(BOT_COMBAT_CLOSE_MELEE,
            *bot, currentTime);
    }
}

// Retail symbol: ?Init@idBotBehaviorCombat_TargetVis_CloseRange_SMG@@UAAXPAVidBot@@H@Z
// EA: 0x82B370B0, RVA: 0x00B370B0
void idBotBehaviorCombat_TargetVis_CloseRange_SMG::Init(
        idBot* bot, int currentTime) {
    AppendState(nullptr, new idBotBehaviorCombat_CircleStafeEnemy());
    AppendState(nullptr, new idBotBehaviorCombat_SideStrafeEnemy());
    AppendState(nullptr,
        new idBotBehaviorCombat_QuickSideToSideStrafeEnemy());
    AppendState(nullptr, new idBotBehaviorCombat_RandomJumpAttackEnemy());
    AppendState(nullptr, new idBotBehaviorCombat_RunAndAttackEnemy());
    if (bot != nullptr && g_services != nullptr) {
        g_services->InitializeBehavior(BOT_COMBAT_CLOSE_SMG,
            *bot, currentTime);
    }
}

// Retail symbol: ?Init@idBotBehaviorCombat_TargetVis_CloseRange_Shotgun@@UAAXPAVidBot@@H@Z
// EA: 0x82B37318, RVA: 0x00B37318
void idBotBehaviorCombat_TargetVis_CloseRange_Shotgun::Init(
        idBot* bot, int currentTime) {
    AppendState(nullptr, new idBotBehaviorCombat_CircleStafeEnemy());
    AppendState(nullptr, new idBotBehaviorCombat_SideStrafeEnemy());
    AppendState(nullptr,
        new idBotBehaviorCombat_QuickSideToSideStrafeEnemy());
    AppendState(nullptr, new idBotBehaviorCombat_RunAndAttackEnemy());
    if (bot != nullptr && g_services != nullptr) {
        g_services->InitializeBehavior(BOT_COMBAT_CLOSE_SHOTGUN,
            *bot, currentTime);
    }
}

// Retail symbol: ?Init@idBotBehaviorCombat_TargetVis_CloseRange_Thrown@@UAAXPAVidBot@@H@Z
// EA: 0x82B37510, RVA: 0x00B37510
void idBotBehaviorCombat_TargetVis_CloseRange_Thrown::Init(
        idBot* bot, int currentTime) {
    AppendState(nullptr, new idBotBehaviorCombat_CircleStafeEnemy());
    AppendState(nullptr, new idBotBehaviorCombat_SideStrafeEnemy());
    AppendState(nullptr, new idBotBehaviorCombat_RunAndAttackEnemy());
    if (bot != nullptr && g_services != nullptr) {
        g_services->InitializeBehavior(BOT_COMBAT_CLOSE_THROWN,
            *bot, currentTime);
    }
}

// Retail symbol: ?Init@idBotBehaviorCombat_TargetVis_CloseRange_Sniper@@UAAXPAVidBot@@H@Z
// EA: 0x82B37698, RVA: 0x00B37698
void idBotBehaviorCombat_TargetVis_CloseRange_Sniper::Init(
        idBot* bot, int currentTime) {
    AppendState(nullptr, new idBotBehaviorCombat_StandGroundAttackEnemy());
    AppendState(nullptr, new idBotBehaviorCombat_SideStrafeEnemy());
    AppendState(nullptr, new idBotBehaviorCombat_CrouchAttackEnemy());
    if (bot != nullptr && g_services != nullptr) {
        g_services->InitializeBehavior(BOT_COMBAT_CLOSE_SNIPER,
            *bot, currentTime);
    }
}

// Retail symbol: ?Init@idBotBehaviorCombat_TargetVis_LongRange@@UAAXPAVidBot@@H@Z
// EA: 0x82B37820, RVA: 0x00B37820
void idBotBehaviorCombat_TargetVis_LongRange::Init(
        idBot* bot, int currentTime) {
    AppendState(nullptr, new idBotBehaviorCombat_RunAndAttackEnemy());
    if (bot != nullptr && g_services != nullptr) {
        g_services->InitializeBehavior(BOT_COMBAT_LONG_RANGE,
            *bot, currentTime);
    }
}

// Retail symbol: ?Think@idBotBehaviorCombat_TargetVis_CloseRange_Melee@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B378B8, RVA: 0x00B378B8
behaviorStatus_t idBotBehaviorCombat_TargetVis_CloseRange_Melee::Think(
        idBot* const bot, int) { return Aim(BOT_COMBAT_CLOSE_MELEE, bot); }

// Retail symbol: ?Think@idBotBehaviorCombat_TargetVis_CloseRange_SMG@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B37950, RVA: 0x00B37950
behaviorStatus_t idBotBehaviorCombat_TargetVis_CloseRange_SMG::Think(
        idBot* const bot, int) { return Aim(BOT_COMBAT_CLOSE_SMG, bot); }

// Retail symbol: ?Think@idBotBehaviorCombat_TargetVis_CloseRange_Shotgun@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B379E8, RVA: 0x00B379E8
behaviorStatus_t idBotBehaviorCombat_TargetVis_CloseRange_Shotgun::Think(
        idBot* const bot, int) { return Aim(BOT_COMBAT_CLOSE_SHOTGUN, bot); }

// Retail symbol: ?Think@idBotBehaviorCombat_TargetVis_CloseRange_Thrown@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B37A80, RVA: 0x00B37A80
behaviorStatus_t idBotBehaviorCombat_TargetVis_CloseRange_Thrown::Think(
        idBot* const bot, int) { return Aim(BOT_COMBAT_CLOSE_THROWN, bot); }

// Retail symbol: ?Think@idBotBehaviorCombat_TargetVis_CloseRange_Sniper@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B37B18, RVA: 0x00B37B18
behaviorStatus_t idBotBehaviorCombat_TargetVis_CloseRange_Sniper::Think(
        idBot* const bot, int) { return Aim(BOT_COMBAT_CLOSE_SNIPER, bot); }

// Retail symbol: ?GetPriority@idBotBehaviorCombat_NonVisTarget@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B37BB0, RVA: 0x00B37BB0
behaviorPriority_t idBotBehaviorCombat_NonVisTarget::GetPriority(
        idBot* const bot, int) {
    if (bot != nullptr && g_services != nullptr) {
        g_services->TouchNonVisibleTargetRecord(*bot);
    }
    return BEHAVIOR_PRIORITY_NULL;
}
