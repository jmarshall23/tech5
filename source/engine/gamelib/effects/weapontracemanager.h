#pragma once

#include "idlib/bv/bounds.h"
#include "idlib/containers/staticlist.h"
#include "idlib/handle.h"

class idDeclDamage;
enum invalidSpawnId_t : int;

class idSpawnId : public idHandle<int, invalidSpawnId_t, 8191> {
public:
    idSpawnId() = default;
    idSpawnId(int value) : idHandle(value) {}
};

struct weaponTrace_t {
    enum weaponTraceType_t : int {
        WEAPON_TRACE_BULLET = 0,
        WEAPON_TRACE_EXPLOSION = 1,
        WEAPON_TRACE_PROJECTILE = 2
    };

    idVec3 start;
    idVec3 end;
    idVec3 impactPoint;
    idVec3 dir;
    idSpawnId attacker;
    idSpawnId projectile;
    const idDeclDamage* damageDecl;
    float radius;
    weaponTraceType_t weaponTraceType;
};

class idWeaponTraceManager {
public:
    idWeaponTraceManager();

    void Init();
    void Update();
    void AddTrace(const idVec3& start, const idVec3& end,
        idSpawnId attacker, const idDeclDamage* damage);
    void AddExplosion(const idVec3& origin, float radius,
        idSpawnId attacker, const idDeclDamage* damage);
    void AddProjectile(const idVec3& origin, float radius,
        idSpawnId attacker, idSpawnId projectile,
        const idDeclDamage* damage);
    int GetCollisions(const idBounds& bounds,
        idList<weaponTrace_t, 5>& outTraces);

    idStaticList<weaponTrace_t, 6> weaponTraces[2];
    int currentDeferred;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idSpawnId) == 4, "Recovered idSpawnId ABI changed");
static_assert(sizeof(weaponTrace_t) == 68,
    "Recovered weapon trace ABI changed");
static_assert(sizeof(idWeaponTraceManager) == 852,
    "Recovered weapon trace manager ABI changed");
#endif
