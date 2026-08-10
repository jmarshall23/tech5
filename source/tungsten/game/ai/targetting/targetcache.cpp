#include "targetcache.h"

// Retail symbol: ?RemoveBySpawnId@idTargetCache@@QAAXABVidSpawnId@@@Z
// EA: 0x82B038A8, RVA: 0x00B038A8
void idTargetCache::RemoveBySpawnId(const idSpawnId& spawnId) {
    for (int index = 0; index < targets.Num(); ++index) {
        const idAIEntityState* const entityState = targets[index].es;
        if (entityState != nullptr
                && Tungsten_TargetCacheSpawnIdMatches(
                    *entityState, spawnId)) {
            targets.RemoveIndexFast(index);
            return;
        }
    }
}

// Retail symbol: ??0idTargetCache@@QAA@XZ
// EA: 0x82B03AF0, RVA: 0x00B03AF0
idTargetCache::idTargetCache()
    : targets()
    , curFrame(-1) {
}

// Retail symbol: ?Clear@idTargetCache@@QAAXXZ
// EA: 0x82B03BF8, RVA: 0x00B03BF8
void idTargetCache::Clear() {
    targets.Clear();
    curFrame = -1;
}

// Retail symbol:
// ?Init@idTargetCache@@QAAXPBUaiLatchedState_t@@ABVidAIWorldState@@@Z
// EA: 0x82B03CD8, RVA: 0x00B03CD8
void idTargetCache::Init(const aiLatchedState_t* const ownerState,
        const idAIWorldState& worldState) {
    curFrame = Tungsten_GetTargetCacheFrame();
    if (ownerState == nullptr) {
        return;
    }

    const int entityCount =
        Tungsten_GetTargetCacheWorldEntityCount(worldState);
    for (int index = 0; index < entityCount; ++index) {
        const idAIEntityState* const entityState =
            Tungsten_GetTargetCacheWorldEntityState(worldState, index);
        if (entityState == nullptr
                || Tungsten_GetTargetCacheHighestAwareness(*entityState) == 0) {
            continue;
        }
        idTargetInfo* const targetInfo = targets.Alloc();
        if (targetInfo == nullptr) {
            break;
        }
        targetInfo->Cache(ownerState, entityState);
    }
}

// Retail symbol:
// ?Update@idTargetCache@@QAAXPBUaiLatchedState_t@@ABVidAIWorldState@@ABVidSpawnId@@@Z
// EA: 0x82B03E58, RVA: 0x00B03E58
void idTargetCache::Update(const aiLatchedState_t* const ownerState,
        const idAIWorldState& worldState,
        const idSpawnId& targetSpawnId) {
    const idAIEntityState* const entityState =
        Tungsten_FindTargetCacheWorldState(worldState, targetSpawnId);
    if (entityState == nullptr) {
        return;
    }

    for (int index = 0; index < targets.Num(); ++index) {
        // Retail assumes every populated cache entry has a state.
        if (Tungsten_TargetCacheSpawnIdMatches(
                *targets[index].es, targetSpawnId)) {
            targets[index].Cache(ownerState, entityState);
            return;
        }
    }

    idTargetInfo* const targetInfo = targets.Alloc();
    if (targetInfo != nullptr) {
        targetInfo->Cache(ownerState, entityState);
    }
}
