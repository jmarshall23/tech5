#include "gamelib/effects/weapontracemanager.h"

idWeaponTraceManager::idWeaponTraceManager()
    : weaponTraces{}
    , currentDeferred(0) {
    Init();
}

void idWeaponTraceManager::Init() {
    weaponTraces[0].Clear();
    weaponTraces[1].Clear();
    currentDeferred = 0;
}

void idWeaponTraceManager::Update() {
    currentDeferred ^= 1;
    weaponTraces[currentDeferred].Clear();
}

void idWeaponTraceManager::AddTrace(const idVec3& start,
    const idVec3& end, const idSpawnId attacker,
    const idDeclDamage* const damage) {
    idStaticList<weaponTrace_t, 6>& traces = weaponTraces[currentDeferred];
    if (traces.Num() >= traces.Max()) {
        return;
    }
    weaponTrace_t* const trace = traces.Alloc();
    trace->start = start;
    trace->end = end;
    trace->impactPoint = end;
    trace->dir.Zero();
    trace->attacker = attacker;
    trace->projectile.Invalidate();
    trace->damageDecl = damage;
    trace->radius = 0.0f;
    trace->weaponTraceType = weaponTrace_t::WEAPON_TRACE_BULLET;
}

void idWeaponTraceManager::AddExplosion(const idVec3& origin,
    const float radius, const idSpawnId attacker,
    const idDeclDamage* const damage) {
    idStaticList<weaponTrace_t, 6>& traces = weaponTraces[currentDeferred];
    if (traces.Num() >= traces.Max()) {
        return;
    }
    weaponTrace_t* const trace = traces.Alloc();
    trace->start = origin;
    trace->end = origin;
    trace->impactPoint = origin;
    trace->dir.Zero();
    trace->attacker = attacker;
    trace->projectile.Invalidate();
    trace->damageDecl = damage;
    trace->radius = radius;
    trace->weaponTraceType = weaponTrace_t::WEAPON_TRACE_EXPLOSION;
}

void idWeaponTraceManager::AddProjectile(const idVec3& origin,
    const float radius, const idSpawnId attacker,
    const idSpawnId projectile, const idDeclDamage* const damage) {
    idStaticList<weaponTrace_t, 6>& traces = weaponTraces[currentDeferred];
    if (traces.Num() >= traces.Max()) {
        return;
    }
    weaponTrace_t* const trace = traces.Alloc();
    trace->start = origin;
    trace->end = origin;
    trace->impactPoint = origin;
    trace->dir.Zero();
    trace->attacker = attacker;
    trace->projectile = projectile;
    trace->damageDecl = damage;
    trace->radius = radius;
    trace->weaponTraceType = weaponTrace_t::WEAPON_TRACE_PROJECTILE;
}

int idWeaponTraceManager::GetCollisions(const idBounds& bounds,
    idList<weaponTrace_t, 5>& outTraces) {
    outTraces.Clear();
    const idStaticList<weaponTrace_t, 6>& traces =
        weaponTraces[currentDeferred ^ 1];

    for (int index = 0; index < traces.Num(); ++index) {
        const weaponTrace_t& source = traces[index];
        weaponTrace_t result = source;
        switch (source.weaponTraceType) {
        case weaponTrace_t::WEAPON_TRACE_BULLET: {
            result.dir = source.end - source.start;
            float scale = 0.0f;
            if (!bounds.RayIntersection(source.start, result.dir, scale) ||
                scale < 0.0f || scale >= 1.0f) {
                continue;
            }
            result.dir.NormalizeFast();
            result.radius = 0.0f;
            break;
        }
        case weaponTrace_t::WEAPON_TRACE_EXPLOSION:
            if (!bounds.SphereIntersection(source.start, source.radius)) {
                continue;
            }
            result.end = (bounds[0] + bounds[1]) * 0.5f;
            result.impactPoint = result.end;
            result.dir = result.end - result.start;
            result.dir.NormalizeFast();
            break;
        case weaponTrace_t::WEAPON_TRACE_PROJECTILE:
            if (!bounds.SphereIntersection(source.start, source.radius)) {
                continue;
            }
            result.end = result.start;
            result.impactPoint = result.start;
            result.dir.Zero();
            break;
        default:
            continue;
        }
        outTraces.Append(result);
    }
    return outTraces.Num();
}
