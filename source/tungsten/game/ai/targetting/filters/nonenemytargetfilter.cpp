#include "nonenemytargetfilter.h"

// Retail symbol: ??0idNonEnemyTargetFilter@@QAA@W4aiAwareness_t@@@Z
// EA: 0x82B021A0, RVA: 0x00B021A0
idNonEnemyTargetFilter::idNonEnemyTargetFilter(
        const aiAwareness_t minimumAwareness) {
    minAwareness = minimumAwareness;
}

// Retail symbol:
// ?InternalFilter@idNonEnemyTargetFilter@@MBA_NPBVidEntity@@ABVidTargetInfo@@@Z
// EA: 0x82B021B8, RVA: 0x00B021B8
bool idNonEnemyTargetFilter::InternalFilter(
        const idEntity* const owner, const idTargetInfo* const target) const {
    (void)owner;
    return target->es != nullptr
        && Tungsten_GetAIEntityType(target->es) != 3
        && target->attitude >= 2;
}
