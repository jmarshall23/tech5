#include "turretfilter.h"

// Retail symbol: ?InternalFilter@idTurretFilter@@MBA_NPBVidEntity@@ABVidTargetInfo@@@Z
// EA: 0x82B021F8, RVA: 0x00B021F8
bool idTurretFilter::InternalFilter(
        const idEntity* const owner, const idTargetInfo* const target) const {
    (void)owner;
    return target->es != nullptr
        && !Tungsten_IsProjectileAIEntityState(target->es)
        && Tungsten_IsStaticWeaponAIEntityState(target->es);
}

// Retail symbol: ??0idTurretFilter@@QAA@XZ
// EA: 0x82B02260, RVA: 0x00B02260
idTurretFilter::idTurretFilter() {
    minAwareness = AIAWARE_CONFIRMED;
}
