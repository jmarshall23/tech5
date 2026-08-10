#pragma once

#include "../targetfilter.h"

bool Tungsten_IsProjectileAIEntityState(const idAIEntityState* entityState);
bool Tungsten_IsStaticWeaponAIEntityState(const idAIEntityState* entityState);

class idTurretFilter : public idTargetFilter {
public:
    idTurretFilter();
    ~idTurretFilter() override = default;

    bool InternalFilter(
        const idEntity* owner, const idTargetInfo* target) const override;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idTurretFilter) == 8,
    "Recovered turret target-filter ABI changed");
#endif
