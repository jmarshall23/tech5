#include "bot_tracemanager.h"

#include <algorithm>

namespace {
idBotTraceManagerServices* g_traceManagerServices = nullptr;
constexpr int BOT_VISIBILITY_CLIP_MASK = 8462469;
}

void Tungsten_SetBotTraceManagerServices(
        idBotTraceManagerServices* const services) {
    g_traceManagerServices = services;
}

// Retail symbol: ?QueueVisTrace@idBotTraceManager@@AAA?AW4queueTraceResults_t@@HH@Z
// EA: 0x82B49FA8, RVA: 0x00B49FA8
queueTraceResults_t idBotTraceManager::QueueVisTrace(
        const unsigned int sourceIndex, const unsigned int targetIndex) {
    if (numActiveTraces >= 8) return QUEUE_TRACE_FULL;
    if (sourceIndex >= 32 || targetIndex >= 32 ||
            g_traceManagerServices == nullptr) {
        return QUEUE_TRACE_SKIPPED;
    }
    const idEntity* const source =
        g_traceManagerServices->ResolveEntitySpawnId(
            entityData[sourceIndex].ent.GetSpawnId());
    const idEntity* const target =
        g_traceManagerServices->ResolveEntitySpawnId(
            entityData[targetIndex].ent.GetSpawnId());
    if (source == nullptr || target == nullptr) return QUEUE_TRACE_SKIPPED;

    traceWorkData_t& work = traceWorkData[numActiveTraces++];
    work.srcIndex = static_cast<int>(sourceIndex);
    work.targetIndex = static_cast<int>(targetIndex);
    work.clipQuery = g_traceManagerServices->SubmitVisibilityTrace(
        g_traceManagerServices->GetEyePosition(*source),
        g_traceManagerServices->GetEyePosition(*target),
        BOT_VISIBILITY_CLIP_MASK, "BotVisCast");
    return QUEUE_TRACE_SUBMITTED;
}

// Retail symbol: ?DebugDraw@idBotTraceManager@@AAAXH@Z
// EA: 0x82B4A0F0, RVA: 0x00B4A0F0
void idBotTraceManager::DebugDraw(const int currentTime) {
    if (g_traceManagerServices == nullptr) return;
    for (int sourceIndex = 0; sourceIndex < 6; ++sourceIndex) {
        const idEntity* const source =
            g_traceManagerServices->ResolveEntitySpawnId(
                entityData[sourceIndex].ent.GetSpawnId());
        if (source == nullptr) continue;
        g_traceManagerServices->DebugDrawEntity(*source,
            entityData[sourceIndex].lastUpdateTime, currentTime);
        for (int targetIndex = 0; targetIndex < 32; ++targetIndex) {
            const idEntity* const target =
                g_traceManagerServices->ResolveEntitySpawnId(
                    entityData[targetIndex].ent.GetSpawnId());
            if (target == nullptr) continue;
            const perceptionData_t& perception =
                perceptionTable[sourceIndex][targetIndex];
            g_traceManagerServices->DebugDrawPerception(*source, *target,
                perception.lastSeenTime == perception.lastUpdateTime,
                perception.lastUpdateTime, currentTime);
        }
    }
}

// Retail symbol: ?GetIndexForEntity@idBotTraceManager@@ABAHPBVidEntity@@@Z
// EA: 0x82B4A3B0, RVA: 0x00B4A3B0
int idBotTraceManager::GetIndexForEntity(
        const idEntity* const entity) const {
    if (entity == nullptr || g_traceManagerServices == nullptr) return -1;
    if (g_traceManagerServices->IsPlayer(*entity)) {
        return g_traceManagerServices->GetEntityNumber(*entity);
    }
    for (int index = 0; index < 32; ++index) {
        if (g_traceManagerServices->ResolveEntitySpawnId(
                entityData[index].ent.GetSpawnId()) == entity) {
            return index;
        }
    }
    return -1;
}

// Retail symbol: ?Update@idBotTraceManager@@QAAXH@Z
// EA: 0x82B4A4A8, RVA: 0x00B4A4A8
void idBotTraceManager::Update(const int currentTime) {
    if (playerUpdateIndexes.Num() < 2 ||
            g_traceManagerServices == nullptr) {
        return;
    }
    if (g_traceManagerServices->IsDebugEnabled()) DebugDraw(currentTime);

    for (traceWorkData_t& work : traceWorkData) {
        if (work.clipQuery.index == 0 ||
                !g_traceManagerServices->IsTraceComplete(work.clipQuery)) {
            continue;
        }
        const bool visible =
            g_traceManagerServices->GetTraceFraction(work.clipQuery) == 1.0f;
        work.clipQuery.index = 0;
        if (work.srcIndex < 0 || work.srcIndex >= 6 ||
                work.targetIndex < 0 || work.targetIndex >= 32) {
            continue;
        }
        perceptionData_t& forward =
            perceptionTable[work.srcIndex][work.targetIndex];
        if (visible) forward.lastSeenTime = currentTime;
        forward.lastUpdateTime = currentTime;
        if (work.targetIndex < 6) {
            perceptionData_t& reverse =
                perceptionTable[work.targetIndex][work.srcIndex];
            if (visible) reverse.lastSeenTime = currentTime;
            reverse.lastUpdateTime = currentTime;
        }
    }

    numActiveTraces = 0;
    if (curEntDataIndex != -1) {
        if (g_traceManagerServices->ResolveEntitySpawnId(
                entityData[curEntDataIndex].ent.GetSpawnId()) == nullptr) {
            curEntDataIndex = -1;
        } else {
            curTraceIndex = 0;
            for (; curTraceIndex < 32; ++curTraceIndex) {
                if (curTraceIndex != curEntDataIndex &&
                        g_traceManagerServices->ResolveEntitySpawnId(
                            entityData[curTraceIndex].ent.GetSpawnId()) !=
                            nullptr &&
                        QueueVisTrace(curEntDataIndex, curTraceIndex) ==
                            QUEUE_TRACE_FULL) {
                    return;
                }
            }
            entityData[curEntDataIndex].lastUpdateTime = currentTime;
        }
    }

    for (int first = 0; first < playerUpdateIndexes.Num(); ++first) {
        for (int second = first + 1;
                second < playerUpdateIndexes.Num(); ++second) {
            if (entityData[playerUpdateIndexes[first]].lastUpdateTime >
                    entityData[playerUpdateIndexes[second]].lastUpdateTime) {
                std::swap(playerUpdateIndexes[first],
                    playerUpdateIndexes[second]);
            }
        }
    }

    for (int player = 0; player < playerUpdateIndexes.Num(); ++player) {
        curEntDataIndex = playerUpdateIndexes[player];
        curTraceIndex = 0;
        for (; curTraceIndex < 32; ++curTraceIndex) {
            if (curTraceIndex == curEntDataIndex ||
                    entityData[curTraceIndex].lastUpdateTime == currentTime ||
                    g_traceManagerServices->ResolveEntitySpawnId(
                        entityData[curTraceIndex].ent.GetSpawnId()) == nullptr) {
                continue;
            }
            if (QueueVisTrace(curEntDataIndex, curTraceIndex) ==
                    QUEUE_TRACE_FULL) {
                return;
            }
        }
        entityData[curEntDataIndex].lastUpdateTime = currentTime;
        curEntDataIndex = -1;
    }
}

// Retail symbol: ?RemoveEntity@idBotTraceManager@@QAAXPBVidEntity@@@Z
// EA: 0x82B4A9C0, RVA: 0x00B4A9C0
void idBotTraceManager::RemoveEntity(const idEntity* const entity) {
    if (entity == nullptr || g_traceManagerServices == nullptr) return;
    if (g_traceManagerServices->IsPlayer(*entity)) {
        const int entityNumber =
            g_traceManagerServices->GetEntityNumber(*entity);
        if (entityNumber >= 0 && entityNumber < 32) {
            entityData[entityNumber].ent.Invalidate();
            playerUpdateIndexes.RemoveIndexFast(
                playerUpdateIndexes.FindIndex(entityNumber));
        }
        return;
    }
    for (int index = 6; index < 32; ++index) {
        if (g_traceManagerServices->ResolveEntitySpawnId(
                entityData[index].ent.GetSpawnId()) == entity) {
            entityData[index].ent.Invalidate();
            return;
        }
    }
}

// Retail symbol: ?IsVisible@idBotTraceManager@@QAA_NPBVidEntity@@0H@Z
// EA: 0x82B4AB58, RVA: 0x00B4AB58
bool idBotTraceManager::IsVisible(const idEntity* const entity,
        const idEntity* const otherEntity, const int timeDelta) const {
    const int sourceIndex = GetIndexForEntity(entity);
    const int targetIndex = GetIndexForEntity(otherEntity);
    return sourceIndex != -1 && targetIndex != -1 && sourceIndex < 6 &&
        timeDelta >= perceptionTable[sourceIndex][targetIndex].lastUpdateTime -
            perceptionTable[sourceIndex][targetIndex].lastSeenTime;
}

// Retail symbol: ??0idBotTraceManager@@QAA@XZ
// EA: 0x82B4ABE0, RVA: 0x00B4ABE0
idBotTraceManager::idBotTraceManager()
    : curEntDataIndex(-1), curTraceIndex(0), numActiveTraces(0),
      perceptionTable(), entityData(), traceWorkData(),
      playerUpdateIndexes() {
    for (entityData_t& data : entityData) {
        data.lastUpdateTime = 0;
        data.ent.Invalidate();
    }
    for (traceWorkData_t& work : traceWorkData) {
        work.srcIndex = -1;
        work.targetIndex = -1;
        work.clipQuery.index = 0;
    }
    for (auto& source : perceptionTable) {
        for (perceptionData_t& data : source) {
            data.lastSeenTime = 0;
            data.lastUpdateTime = 0;
        }
    }
}

// Retail symbol: ??1idBotTraceManager@@QAA@XZ
// EA: 0x82B4ACD8, RVA: 0x00B4ACD8
idBotTraceManager::~idBotTraceManager() {
    for (entityData_t& data : entityData) data.ent.Invalidate();
    for (traceWorkData_t& work : traceWorkData) work.clipQuery.index = 0;
    playerUpdateIndexes.Clear();
}

// Retail symbol: ?AddEntity@idBotTraceManager@@QAAXPBVidEntity@@@Z
// EA: 0x82B4AD20, RVA: 0x00B4AD20
void idBotTraceManager::AddEntity(const idEntity* const entity) {
    if (entity == nullptr || g_traceManagerServices == nullptr) return;
    if (g_traceManagerServices->IsPlayer(*entity)) {
        const int entityNumber =
            g_traceManagerServices->GetEntityNumber(*entity);
        if (entityNumber < 0 || entityNumber >= 32) return;
        entityData[entityNumber].ent.SetSpawnId(
            g_traceManagerServices->GetEntitySpawnId(entity));
        if (entityNumber < 6) {
            for (int target = 0; target < 32; ++target) {
                perceptionTable[entityNumber][target].lastSeenTime = 0;
            }
        }
        playerUpdateIndexes.AddUnique(entityNumber);
        return;
    }

    for (int index = 6; index < 32; ++index) {
        if (g_traceManagerServices->ResolveEntitySpawnId(
                entityData[index].ent.GetSpawnId()) == nullptr) {
            entityData[index].ent.SetSpawnId(
                g_traceManagerServices->GetEntitySpawnId(entity));
            return;
        }
    }
}
