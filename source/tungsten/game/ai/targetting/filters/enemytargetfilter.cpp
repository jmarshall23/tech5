#include "enemytargetfilter.h"

// Retail symbol: ??0idEnemyTargetFilter@@QAA@W4aiAwareness_t@@@Z
// EA: 0x82B01E00, RVA: 0x00B01E00
idEnemyTargetFilter::idEnemyTargetFilter(
        const aiAwareness_t minimumAwareness) {
    minAwareness = minimumAwareness;
}

// Retail symbol:
// ?InternalFilter@idEnemyTargetFilter@@UBA_NPBVidEntity@@ABVidTargetInfo@@@Z
// EA: 0x82B01E18, RVA: 0x00B01E18
bool idEnemyTargetFilter::InternalFilter(
        const idEntity* const owner, const idTargetInfo* const target) const {
    (void)owner;
    if (target->es == nullptr) {
        return false;
    }
    const int entityType = Tungsten_GetAIEntityType(target->es);
    if (entityType == 3) {
        return false;
    }
    if (entityType == 0 || entityType == 1) {
        if (Tungsten_IsDeadAIEntityState(target->es)
            && !Tungsten_IsDyingAIEntityState(target->es)) {
            return false;
        }
    } else if (Tungsten_IsDeadAIEntityState(target->es)
        || Tungsten_IsDyingAIEntityState(target->es)) {
        return false;
    }
    return target->attitude < 2;
}

// Retail symbol: ??0idAvoidTargetFilter@@QAA@W4aiAwareness_t@@@Z
// EA: 0x82B01EE8, RVA: 0x00B01EE8
idAvoidTargetFilter::idAvoidTargetFilter(
        const aiAwareness_t minimumAwareness) {
    minAwareness = minimumAwareness;
}

// Retail symbol:
// ?InternalFilter@idAvoidTargetFilter@@UBA_NPBVidEntity@@ABVidTargetInfo@@@Z
// EA: 0x82B01F00, RVA: 0x00B01F00
bool idAvoidTargetFilter::InternalFilter(
        const idEntity* const owner, const idTargetInfo* const target) const {
    (void)owner;
    if (target->es == nullptr) {
        return false;
    }
    const int entityType = Tungsten_GetAIEntityType(target->es);
    if (entityType == 0 || entityType == 1) {
        if (Tungsten_IsDeadAIEntityState(target->es)) {
            if (!Tungsten_IsDyingAIEntityState(target->es)
                || Tungsten_GetDyingAIAlertAgeMilliseconds(target->es) > 2000) {
                return false;
            }
        }
    } else if (Tungsten_IsDeadAIEntityState(target->es)) {
        return false;
    }
    return target->attitude < 2;
}
