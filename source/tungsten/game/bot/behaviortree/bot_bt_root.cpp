#include "bot_bt_root.h"

namespace {
idBotRootServices* g_services = nullptr;
}

void Tungsten_SetBotRootServices(idBotRootServices* const services) {
    g_services = services;
}

// Retail symbol: ??0idBotBehaviorHighLevel@@QAA@XZ
// EA: 0x82B3D658, RVA: 0x00B3D658
idBotBehaviorHighLevel::idBotBehaviorHighLevel() = default;

// Retail symbol: ??0idBotBehaviorLowLevel@@QAA@XZ
// EA: 0x82B3D698, RVA: 0x00B3D698
idBotBehaviorLowLevel::idBotBehaviorLowLevel() = default;

// Retail symbol: ??0idBotBehaviorMain@@QAA@XZ
// EA: 0x82B3D6D8, RVA: 0x00B3D6D8
idBotBehaviorMain::idBotBehaviorMain() = default;

// Retail symbol: ??0idBotBehaviorDead@@QAA@XZ
// EA: 0x82B3D718, RVA: 0x00B3D718
idBotBehaviorDead::idBotBehaviorDead() : tauntTime(0.0f) {
}

// Retail symbol: ??0idBotBehaviorRoot@@QAA@XZ
// EA: 0x82B3D760, RVA: 0x00B3D760
idBotBehaviorRoot::idBotBehaviorRoot() = default;

// Retail symbol: ??0idBotBehaviorTree@@QAA@XZ
// EA: 0x82B3D7A0, RVA: 0x00B3D7A0
idBotBehaviorTree::idBotBehaviorTree() = default;

// Retail symbol: ?Init@idBotBehaviorHighLevel@@UAAXPAVidBot@@H@Z
// EA: 0x82B3DA58, RVA: 0x00B3DA58
void idBotBehaviorHighLevel::Init(idBot*, int) {
    AppendState(nullptr, new idBotBehaviorReact());
    AppendState(nullptr, new idBotBehaviorBehave());
}

// Retail symbol: ?Init@idBotBehaviorMain@@UAAXPAVidBot@@H@Z
// EA: 0x82B3DB70, RVA: 0x00B3DB70
void idBotBehaviorMain::Init(idBot*, int) {
    AppendState(nullptr, new idBotBehaviorHighLevel());
}

// Retail symbol: ?GetPriority@idBotBehaviorMain@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B3DC18, RVA: 0x00B3DC18
behaviorPriority_t idBotBehaviorMain::GetPriority(idBot* const bot, int) {
    return bot != nullptr && g_services != nullptr
            && g_services->GetHealth(*bot) > 0.0f
        ? BEHAVIOR_PRIORITY_NORMAL : BEHAVIOR_PRIORITY_NULL;
}

// Retail symbol: ?GetPriority@idBotBehaviorDead@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B3DC68, RVA: 0x00B3DC68
behaviorPriority_t idBotBehaviorDead::GetPriority(idBot* const bot, int) {
    return bot != nullptr && g_services != nullptr
            && g_services->GetHealth(*bot) <= 0.0f
        ? BEHAVIOR_PRIORITY_NORMAL : BEHAVIOR_PRIORITY_NULL;
}

// Retail symbol: ?Enter@idBotBehaviorDead@@UAAXPAVidBot@@H@Z
// EA: 0x82B3DCB8, RVA: 0x00B3DCB8
void idBotBehaviorDead::Enter(idBot*, const int currentTime) {
    tauntTime = g_services != nullptr
            && g_services->RandomPercent() < 80U
        ? static_cast<float>(currentTime + 150) : 0.0f;
}

// Retail symbol: ?Think@idBotBehaviorDead@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B3DD40, RVA: 0x00B3DD40
behaviorStatus_t idBotBehaviorDead::Think(
        idBot* const bot, const int currentTime) {
    if (tauntTime > 0.0f && tauntTime < static_cast<float>(currentTime)) {
        tauntTime = 0.0f;
    }
    if (bot != nullptr && g_services != nullptr
            && g_services->RandomPercent() > 98U) {
        g_services->SetUserCommandButtons(*bot, 4U);
    }
    return BEHAVIOR_STATUS_RUNNING;
}

// Retail symbol: ?Init@idBotBehaviorRoot@@UAAXPAVidBot@@H@Z
// EA: 0x82B3DDE0, RVA: 0x00B3DDE0
void idBotBehaviorRoot::Init(idBot*, int) {
    AppendState(nullptr, new idBotBehaviorDead());
    AppendState(nullptr, new idBotBehaviorMain());
}

// Retail symbol: ?Init@idBotBehaviorTree@@UAAXPAVidBot@@H@Z
// EA: 0x82B3DF28, RVA: 0x00B3DF28
void idBotBehaviorTree::Init(idBot*, int) {
    AppendState(this, new idBotBehaviorRoot());
}
