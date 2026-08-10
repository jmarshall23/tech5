#include "friendlytargetfilter.h"

// Retail symbol:
// ?InternalFilter@idFriendlyTargetFilter@@MBA_NPBVidEntity@@ABVidTargetInfo@@@Z
// EA: 0x82B02058, RVA: 0x00B02058
bool idFriendlyTargetFilter::InternalFilter(
        const idEntity* const owner, const idTargetInfo* const target) const {
    (void)owner;
    return target->es != nullptr
        && !Tungsten_IsProjectileAIEntityState(target->es)
        && Tungsten_IsActorAIEntityState(target->es)
        && !Tungsten_IsDeadAIEntityState(target->es)
        && target->attitude > 3;
}

// Retail symbol: ??0idFriendlyTargetFilter@@QAA@W4aiAwareness_t@@@Z
// EA: 0x82B02100, RVA: 0x00B02100
idFriendlyTargetFilter::idFriendlyTargetFilter(
        const aiAwareness_t minimumAwareness) {
    minAwareness = minimumAwareness;
}

// Retail symbol: ??0idFriendlyDeadTargetFilter@@QAA@W4aiAwareness_t@@@Z
// EA: 0x82B02118, RVA: 0x00B02118
idFriendlyDeadTargetFilter::idFriendlyDeadTargetFilter(
        const aiAwareness_t minimumAwareness) {
    minAwareness = minimumAwareness;
}

// Retail symbol:
// ?InternalFilter@idFriendlyDeadTargetFilter@@MBA_NPBVidEntity@@ABVidTargetInfo@@@Z
// EA: 0x82B02130, RVA: 0x00B02130
bool idFriendlyDeadTargetFilter::InternalFilter(
        const idEntity* const owner, const idTargetInfo* const target) const {
    (void)owner;
    if (target->es == nullptr) {
        return false;
    }
    const int entityType = Tungsten_GetAIEntityType(target->es);
    return entityType != 3 && target->attitude > 3
        && (entityType == 0 || entityType == 1)
        && Tungsten_IsDeadAIEntityState(target->es);
}
