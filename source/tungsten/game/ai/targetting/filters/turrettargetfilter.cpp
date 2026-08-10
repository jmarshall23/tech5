#include "turrettargetfilter.h"

// Retail symbol:
// ?InternalFilter@idTurretTargetFilter@@MBA_NPBVidEntity@@ABVidTargetInfo@@@Z
// EA: 0x82B02278, RVA: 0x00B02278
bool idTurretTargetFilter::InternalFilter(
        const idEntity* const owner, const idTargetInfo* const target) const {
    (void)owner;
    return target->es != nullptr
        && !Tungsten_IsProjectileAIEntityState(target->es)
        && !Tungsten_IsDeadVehicleAIEntityState(target->es)
        && target->attitude < 2;
}

// Retail symbol: ??0idTurretTargetFilter@@QAA@W4aiAwareness_t@@@Z
// EA: 0x82B02330, RVA: 0x00B02330
idTurretTargetFilter::idTurretTargetFilter(
        const aiAwareness_t minimumAwareness) {
    minAwareness = minimumAwareness;
}
