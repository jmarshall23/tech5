#pragma once

#include "../../../shared/idlib/containers/staticlist.h"

class idDecl;

struct weaponStats_t {
    weaponStats_t& operator+=(const weaponStats_t& stats);

    const idDecl* decl;
    int fired;
    int accHits;
    int hitEnemy;
    int killedEnemy;
    float damageEnemy;
    int headshotEnemy;
    int headshotEnemyKills;
    int hitFriendly;
    int killedFriendly;
    float damageFriendly;
    int headshotFriendly;
    int headshotFriendlyKills;
    int actorsKilled;
    int vehiclesKilled;
    int breakablesDestroyed;
    int directHit;
    int hitObject;
    int damageGeneral;
    int hitVehicle;
    int hitVehicleInAir;
};

class idLevelStats {
public:
    idLevelStats();
    void Clear();

    int damageTaken;
    int startTime;
    int endTime;
    int itemsTaken;
    idStaticList<weaponStats_t, 20> weaponStats;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(weaponStats_t) == 84,
    "Recovered per-weapon metrics ABI changed");
static_assert(sizeof(idLevelStats) == 1712,
    "Recovered level metrics ABI changed");
#endif
