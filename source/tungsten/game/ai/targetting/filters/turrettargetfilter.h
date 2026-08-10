#pragma once

#include "../targetfilter.h"
#include "turretfilter.h"

bool Tungsten_IsDeadVehicleAIEntityState(const idAIEntityState* entityState);

class idTurretTargetFilter : public idTargetFilter {
public:
    explicit idTurretTargetFilter(aiAwareness_t minimumAwareness);
    ~idTurretTargetFilter() override = default;

    bool InternalFilter(
        const idEntity* owner, const idTargetInfo* target) const override;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idTurretTargetFilter) == 8,
    "Recovered turret-target filter ABI changed");
#endif
