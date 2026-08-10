#pragma once

#include "targetinfo.h"
#include "../../../../shared/idlib/containers/staticlist.h"

class idAIWorldState;
class idSpawnId;

class idTargetCache {
public:
    idTargetCache();
    void Clear();
    void Init(const aiLatchedState_t* ownerState,
        const idAIWorldState& worldState);
    void Update(const aiLatchedState_t* ownerState,
        const idAIWorldState& worldState, const idSpawnId& targetSpawnId);
    void RemoveBySpawnId(const idSpawnId& spawnId);

    idStaticList<idTargetInfo, 8> targets;
    int curFrame;
};

// The world-state containers and spawn handle are owned by the still-raw
// game-state layer. These seams retain target-cache behavior without guessing
// those layouts from the decompiler's byte offsets.
int Tungsten_GetTargetCacheFrame();
int Tungsten_GetTargetCacheWorldEntityCount(
    const idAIWorldState& worldState);
const idAIEntityState* Tungsten_GetTargetCacheWorldEntityState(
    const idAIWorldState& worldState, int index);
int Tungsten_GetTargetCacheHighestAwareness(
    const idAIEntityState& entityState);
const idAIEntityState* Tungsten_FindTargetCacheWorldState(
    const idAIWorldState& worldState, const idSpawnId& spawnId);
bool Tungsten_TargetCacheSpawnIdMatches(
    const idAIEntityState& entityState, const idSpawnId& spawnId);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idTargetCache) == 436,
    "Recovered AI target-cache ABI changed");
#endif
