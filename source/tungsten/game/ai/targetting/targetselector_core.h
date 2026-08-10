#pragma once

#include "../../../../shared/idlib/math/vector.h"
#include "targetinfo.h"

class idEntity;

bool Tungsten_IsDeadAIEntityState(const idAIEntityState* entityState);
bool Tungsten_IsVisibleAIEntityState(const idAIEntityState* entityState);
int Tungsten_GetAIAwareness(const idAIEntityState* entityState);
float Tungsten_FloatForTargetAttitude(int attitude);

class idTargetSelector {
public:
    virtual ~idTargetSelector() = default;
    virtual float GetWeight(
        const idEntity* owner, const idTargetInfo* target) const = 0;

    // FindBestTarget takes a const selector in the retail signature but caches
    // the owner's current forward direction before invoking GetWeight.
    mutable idVec3 ownerDir;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idTargetSelector) == 16,
    "Recovered target-selector ABI changed");
#endif
