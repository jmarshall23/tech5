#pragma once

#include "../../../engine/decls/decltypeinfo.h"
#include "idlib/containers/list.h"
#include "idlib/langdict.h"
#include "idlib/text/str.h"

class idDeclWeapon;
enum rageStat_t : int;

enum aggregationMethod_t : int {
    AGGREGATE_MIN = 0,
    AGGREGATE_MAX = 1,
    AGGREGATE_SUM = 2,
    AGGREGATE_LAST = 3
};

struct rageStatAggregationMethod {
    rageStat_t stat;
    aggregationMethod_t method;
};

struct rageStatXpBonus {
    int min;
    int xp;
};

class idDeclMetric : public idDeclTypeInfo {
public:
    idDeclMetric();
    ~idDeclMetric() override = default;

    int GetXPValue(int delta) const;
    int GetXPBonus(int delta) const;
    static const idDeclMetric* Find(rageStat_t stat);
    bool IsWeaponListed(const idDeclWeapon& weapon) const;

    idDeclInfo* GetDeclInfo() const override { return &resourceList; }
    static void LoadAllDecls();

    rageStat_t stat;
    rageStatAggregationMethod aggregate;
    idList<idStr, 5> weaponDecls;
    bool isWeaponStat;
    int xp;
    idList<rageStatXpBonus, 5> xpBonus;
    idStrId displayName;

    static idDeclInfoTemplate<idDeclMetric> resourceList;
};

static_assert(sizeof(rageStatAggregationMethod) == 8,
    "Recovered rage-stat aggregation ABI changed");
static_assert(sizeof(rageStatXpBonus) == 8,
    "Recovered rage-stat XP bonus ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclMetric) == 120,
    "Recovered metric declaration ABI changed");
#endif
