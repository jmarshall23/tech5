#pragma once

#include "../../../../shared/idlib/math/vector.h"

struct aiLatchedState_t;
class idAIEntityState;

class idTargetInfo {
public:
    idTargetInfo();

    // Requires the AI sense-state, entity, health, and faction tables; retained
    // as a raw declaration until those dependencies are recovered.
    void Cache(const aiLatchedState_t* ownerState,
        const idAIEntityState* entityState);

    const idAIEntityState* es;
    float distSqr;
    float distTo;
    idVec3 delta;
    idVec3 faceDir;
    idVec3 dirTo;
    char attitude;
    unsigned char healthRatio;
};

const idVec3& Tungsten_GetTargetInfoOwnerOrigin(
    const aiLatchedState_t& ownerState);
const idVec3& Tungsten_GetTargetInfoConfirmedOrigin(
    const idAIEntityState& entityState);
const idVec3& Tungsten_GetTargetInfoConfirmedViewForward(
    const idAIEntityState& entityState);
bool Tungsten_TargetInfoHasEntity(const idAIEntityState& entityState);
int Tungsten_GetTargetInfoHealthRatio(const idAIEntityState& entityState);
bool Tungsten_GetTargetInfoAttitude(const aiLatchedState_t& ownerState,
    const idAIEntityState& entityState, char& attitude);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idTargetInfo) == 52,
    "Recovered AI target-info ABI changed");
#endif
