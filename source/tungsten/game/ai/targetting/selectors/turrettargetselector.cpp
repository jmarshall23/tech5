#include "turrettargetselector.h"

#include <algorithm>
#include <cmath>

// Retail symbol:
// ?GetWeight@idTurretTargetSelector@@UBAMPBVidEntity@@ABVidTargetInfo@@@Z
// EA: 0x82B03428, RVA: 0x00B03428
float idTurretTargetSelector::GetWeight(
        const idEntity* const owner, const idTargetInfo* const target) const {
    if (target == nullptr || target->es == nullptr) {
        return 0.0f;
    }
    const idEntity* const targetEntity = Tungsten_GetAIEntity(target->es);
    if (targetEntity == nullptr || Tungsten_IsDeadEntity(targetEntity)) {
        return 0.0f;
    }

    if (trackOnlyPlayer) {
        return Tungsten_IsPlayerEntity(targetEntity) ? 1.0f : 0.0f;
    }

    const float distance = std::sqrt((std::max)(target->distSqr, 0.0f));
    if (distance > maxTargetDistance || distance < minTargetDistance) {
        return 0.0f;
    }

    idVec3 direction = Tungsten_GetEntityOrigin(targetEntity)
        - Tungsten_GetEntityOrigin(owner);
    direction.NormalizeFast();
    constexpr float DEG_TO_RAD = 0.01745329251994329577f;
    const float minimumDot = std::cos(maxSearchAngle * DEG_TO_RAD * 0.5f);
    if (direction.Dot(forwardSearchDir) < minimumDot) {
        return 0.0f;
    }

    const float distanceWeight = std::pow(2.0f, distance * -0.001953125f)
        * 0.89999998f + 0.1f;
    const float visibilityWeight = Tungsten_IsVisibleAIEntityState(target->es)
        ? 1.0f : 0.5f;
    const float lastTargetWeight =
        Tungsten_ResolveEntitySpawnId(lastTarget.GetSpawnId()) == targetEntity
            ? 1.0f : 0.5f;
    const float lastAttackerWeight =
        Tungsten_ResolveEntitySpawnId(lastAttacker.GetSpawnId()) == targetEntity
            ? 1.0f : 0.8f;
    const float result = distanceWeight * visibilityWeight * lastTargetWeight;

    if (Tungsten_IsTurretTargetDebugEnabled()) {
        Tungsten_DebugTurretTargetWeight(owner, targetEntity,
            distanceWeight, visibilityWeight, lastTargetWeight,
            lastAttackerWeight, result);
    }
    return result;
}
