#include "bot_bt_highlevel.h"

#include "behaviors/bot_bt_combat.h"
#include "behaviors/bot_bt_escort.h"
#include "behaviors/bot_bt_roam.h"

namespace {
idBotHighLevelServices* g_services = nullptr;
}

void Tungsten_SetBotHighLevelServices(
        idBotHighLevelServices* const services) {
    g_services = services;
}

// Retail symbol: ??0idBotBehaviorCombat@@QAA@XZ
// EA: 0x82B3CEE8, RVA: 0x00B3CEE8
idBotBehaviorCombat::idBotBehaviorCombat() = default;

// Retail symbol: ??0idBotBehaviorAlert@@QAA@XZ
// EA: 0x82B3CF28, RVA: 0x00B3CF28
idBotBehaviorAlert::idBotBehaviorAlert() = default;

// Retail symbol: ??0idBotBehaviorBehave@@QAA@XZ
// EA: 0x82B3CF68, RVA: 0x00B3CF68
idBotBehaviorBehave::idBotBehaviorBehave() = default;

// Retail symbol: ??0idBotBehaviorReact@@QAA@XZ
// EA: 0x82B3CFA8, RVA: 0x00B3CFA8
idBotBehaviorReact::idBotBehaviorReact() = default;

// Retail symbol: ?Init@idBotBehaviorCombat@@UAAXPAVidBot@@H@Z
// EA: 0x82B3D190, RVA: 0x00B3D190
void idBotBehaviorCombat::Init(idBot*, int) {
    AppendState(nullptr, new idBotBehaviorCombat_TargetVis());
    AppendState(nullptr, new idBotBehaviorCombat_NonVisTarget());
}

// Retail symbol: ?Init@idBotBehaviorAlert@@UAAXPAVidBot@@H@Z
// EA: 0x82B3D2A8, RVA: 0x00B3D2A8
void idBotBehaviorAlert::Init(idBot*, int) {
    AppendState(nullptr, new idBotBehaviorEscort());
    AppendState(nullptr, new idBotBehaviorRoam());
}

// Retail symbol: ?Init@idBotBehaviorBehave@@UAAXPAVidBot@@H@Z
// EA: 0x82B3D3C0, RVA: 0x00B3D3C0
void idBotBehaviorBehave::Init(idBot*, int) {
    AppendState(nullptr, new idBotBehaviorCombat());
    AppendState(nullptr, new idBotBehaviorAlert());
}

// Retail symbol: ?Init@idBotBehaviorReact@@UAAXPAVidBot@@H@Z
// EA: 0x82B3D4F8, RVA: 0x00B3D4F8
void idBotBehaviorReact::Init(idBot*, int) {
    AppendState(nullptr, new idBehaviorTemp());
}

// Retail symbol: ?GetPriority@idBotBehaviorCombat@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B3D5A0, RVA: 0x00B3D5A0
behaviorPriority_t idBotBehaviorCombat::GetPriority(
        idBot* const bot, int) {
    if (bot == nullptr || g_services == nullptr
            || !g_services->HasValidEnemyTarget(*bot)) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    return g_services->GetEnemyDistance(*bot)
            <= g_services->GetCombatMaximumRange(*bot)
        ? BEHAVIOR_PRIORITY_HIGH : BEHAVIOR_PRIORITY_NULL;
}
