#include "targetfilter.h"

// Retail symbol: ?Filter@idTargetFilter@@QBA_NPBVidEntity@@ABVidTargetInfo@@@Z
// EA: 0x82B03F58, RVA: 0x00B03F58
bool idTargetFilter::Filter(
        const idEntity* const owner, const idTargetInfo& target) const {
    const idAIEntityState* const entityState = target.es;
    if (entityState == nullptr
        || Tungsten_GetAIAwareness(entityState) < minAwareness) {
        return false;
    }

    const idEntity* const entity = Tungsten_GetAIEntity(entityState);
    if (entity == nullptr || Tungsten_IsSpectatingPlayerEntity(entity)
        || Tungsten_IsDeadTurretEntity(entity)
        || Tungsten_IsDeadVehicleMountedTurretEntity(entity)
        || Tungsten_IsHiddenFakeEnemyEntity(entity)) {
        return false;
    }

    const idEntity* const turretOwner =
        Tungsten_GetCaptureTheFlagTurretOwner(owner);
    if (turretOwner != nullptr
        && (entity == turretOwner
            || Tungsten_GetVehicleDriver(entity) == turretOwner)) {
        return false;
    }
    return InternalFilter(owner, &target);
}
