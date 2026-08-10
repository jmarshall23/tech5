#pragma once

#include "../targetselector_core.h"
#include "game/entities/entityptr.h"

const idEntity* Tungsten_GetAIEntity(const idAIEntityState* entityState);
bool Tungsten_IsDeadEntity(const idEntity* entity);
bool Tungsten_IsPlayerEntity(const idEntity* entity);
idVec3 Tungsten_GetEntityOrigin(const idEntity* entity);
const idEntity* Tungsten_ResolveEntitySpawnId(int spawnId);
bool Tungsten_IsTurretTargetDebugEnabled();
void Tungsten_DebugTurretTargetWeight(const idEntity* owner,
    const idEntity* target, float distanceWeight, float visibilityWeight,
    float lastTargetWeight, float lastAttackerWeight, float finalWeight);

class idTurretTargetSelector : public idTargetSelector {
public:
    ~idTurretTargetSelector() override = default;
    float GetWeight(
        const idEntity* owner, const idTargetInfo* target) const override;

    idEntityPtr<idEntity> lastTarget;
    idEntityPtr<idEntity> lastAttacker;
    float maxTargetDistance;
    float minTargetDistance;
    idVec3 forwardSearchDir;
    float maxSearchAngle;
    bool trackOnlyPlayer;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idTurretTargetSelector) == 52,
    "Recovered turret target-selector ABI changed");
#endif
