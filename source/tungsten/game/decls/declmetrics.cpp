#include "game/decls/declmetrics.h"

#include "game/decls/declinventory.h"

#include <algorithm>

idDeclInfoTemplate<idDeclMetric> idDeclMetric::resourceList(
    "metric", "idDeclMetric", "tdef");

// EA 0x82BC8900
int idDeclMetric::GetXPValue(const int delta) const {
    return xp * delta;
}

// EA 0x82BC8968
int idDeclMetric::GetXPBonus(const int delta) const {
    for (int index = 0; index < xpBonus.Num(); ++index) {
        if (delta >= xpBonus[index].min) {
            return xpBonus[index].xp;
        }
    }
    return 0;
}

// EA 0x82BC8C38
const idDeclMetric* idDeclMetric::Find(const rageStat_t requestedStat) {
    for (int index = 0; index < resourceList.num; ++index) {
        const idDeclMetric* metric = static_cast<const idDeclMetric*>(
            resourceList.Index(index));
        if (metric != nullptr && metric->stat == requestedStat) {
            return metric;
        }
    }
    return nullptr;
}

// EA 0x82BC8C98
bool idDeclMetric::IsWeaponListed(const idDeclWeapon& weapon) const {
    return weaponDecls.FindIndex(idStr(weapon.GetName())) >= 0;
}

// EA 0x82BC8D60
idDeclMetric::idDeclMetric()
    : stat(static_cast<rageStat_t>(-1))
    , aggregate{static_cast<rageStat_t>(-1), AGGREGATE_SUM}
    , weaponDecls()
    , isWeaponStat(false)
    , xp(0)
    , xpBonus()
    , displayName() {
}

// EA 0x82BC8F40
void idDeclMetric::LoadAllDecls() {
    for (int sourceIndex = 0;
            sourceIndex < resourceList.declSources.Num(); ++sourceIndex) {
        const idDeclSource* source = resourceList.declSources[sourceIndex];
        if (source != nullptr && source->name.c_str() != nullptr) {
            resourceList.FindWithInheritance(source->name.c_str(), false);
        }
    }

    for (int metricIndex = 0;
            metricIndex < resourceList.num; ++metricIndex) {
        idDeclMetric* metric = const_cast<idDeclMetric*>(
            static_cast<const idDeclMetric*>(resourceList.Index(metricIndex)));
        if (metric == nullptr || metric->xpBonus.Ptr() == nullptr) {
            continue;
        }
        std::sort(metric->xpBonus.Ptr(),
            metric->xpBonus.Ptr() + metric->xpBonus.Num(),
            [](const rageStatXpBonus& lhs, const rageStatXpBonus& rhs) {
                return lhs.min > rhs.min;
            });
    }
}
