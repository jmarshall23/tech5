#include "aidamageinfo.h"

namespace {

constexpr int INVALID_SPAWN_ID = 0x1FFF;

idVec3 AverageImpulses(const idStaticList<idDamageImpulse, 8>& impulses,
        const bool useImpactDirection) {
    idVec3 average(0.0f, 0.0f, 0.0f);
    for (int index = 0; index < impulses.Num(); ++index) {
        const idVec3& value = useImpactDirection
            ? impulses[index].impactDir : impulses[index].impactPoint;
        average.x += value.x;
        average.y += value.y;
        average.z += value.z;
    }

    // The recovered source assumes these queries are made after at least one
    // impulse has been recorded. Retain that arithmetic instead of silently
    // changing its empty-list behavior.
    const float inverseCount = 1.0f / static_cast<float>(impulses.Num());
    average.x *= inverseCount;
    average.y *= inverseCount;
    average.z *= inverseCount;
    return average;
}

} // namespace

idAIDamageInfo::idAIDamageInfo()
    : impulses()
    , inflictor()
    , attacker()
    , recentDamagers()
    , jointIndex()
    , deathImpulseIdx(-1)
    , frameDamage(0.0f)
    , frameArmorDamage(0.0f)
    , recentUnscaledDamage(0.0f)
    , recentBodyDamage(0.0f)
    , lastBloodSprayTime(-1)
    , mostDamagedIndex(-1)
    , shouldPain(false)
    , injuryDamageGroup()
    , injuryGoreLevelIndex(0) {
    for (int index = 0; index < recentDamagers.Max(); ++index) {
        recentDamagers.staticList[index].spawnId.value = INVALID_SPAWN_ID;
        recentDamagers.staticList[index].recentDamage = 0.0f;
    }
}

bool idAIDamageInfo::Stunned() const {
    for (int index = 0; index < impulses.Num(); ++index) {
        const idDeclDamage* const damageDecl = impulses[index].damageDecl;
        if (damageDecl != nullptr && Tungsten_AIDamageDeclStuns(*damageDecl)) {
            return true;
        }
    }
    return false;
}

idVec3 idAIDamageInfo::GetAverageImpactPoint() const {
    return AverageImpulses(impulses, false);
}

idVec3 idAIDamageInfo::GetAverageImpactDir() const {
    idVec3 average = AverageImpulses(impulses, true);
    average.NormalizeFast();
    return average;
}

const idDamageImpulse* idAIDamageInfo::GetDeathImpulse() const {
    return deathImpulseIdx >= 0 ? &impulses[deathImpulseIdx] : nullptr;
}

idEntity* idAIDamageInfo::GetInflictor() const {
    return const_cast<idEntity*>(
        Tungsten_ResolveEntitySpawnId(inflictor.GetSpawnId()));
}

idEntity* idAIDamageInfo::GetAttacker() const {
    return const_cast<idEntity*>(
        Tungsten_ResolveEntitySpawnId(attacker.GetSpawnId()));
}

void idAIDamageInfo::DecayRecentDamagers() {
    for (int index = 0; index < recentDamagers.Num(); ++index) {
        recentDamager_t& damager = recentDamagers[index];
        if (damager.recentDamage >= 0.01f) {
            damager.recentDamage *= 0.99f;
        } else {
            recentDamagers.RemoveIndexFast(index);
            --index;
        }
    }
}

float idAIDamageInfo::GetRecentDamage(const idEntity* const entity) const {
    const int spawnId = Tungsten_GetEntitySpawnId(entity);
    for (int index = 0; index < recentDamagers.Num(); ++index) {
        if (recentDamagers[index].spawnId.value == spawnId) {
            return recentDamagers[index].recentDamage;
        }
    }
    return 0.0f;
}

void idAIDamageInfo::EndFrame() {
    impulses.Clear();
    inflictor.Invalidate();
    attacker.Invalidate();
    jointIndex.Invalidate();
    deathImpulseIdx = -1;
    frameDamage = 0.0f;
    frameArmorDamage = 0.0f;

    recentUnscaledDamage *= 0.95f;
    if (recentUnscaledDamage < 0.01f) {
        recentUnscaledDamage = 0.0f;
    }
    recentBodyDamage *= 0.95f;
    if (recentBodyDamage < 0.01f) {
        recentBodyDamage = 0.0f;
    }

    DecayRecentDamagers();
    shouldPain = false;
}

void idAIDamageInfo::AddRecentDamage(
        const idEntity* const entity, const float damage) {
    const int spawnId = Tungsten_GetEntitySpawnId(entity);
    int replacementIndex = 0;

    for (int index = 0; index < recentDamagers.Num(); ++index) {
        recentDamager_t& damager = recentDamagers[index];
        if (damager.spawnId.value == spawnId) {
            damager.recentDamage += damage;
            return;
        }
        if (damager.recentDamage > -1.0f) {
            replacementIndex = index;
        }
    }

    recentDamager_t damager;
    damager.spawnId.value = spawnId;
    damager.recentDamage = damage;
    if (recentDamagers.Num() >= recentDamagers.Max()) {
        recentDamagers[replacementIndex] = damager;
    } else {
        recentDamagers.Append(damager);
    }
}

void idAIDamageInfo::Update(idAI2*, idEntity* const inflictorEntity,
        idEntity* const attackerEntity,
        const idDeclDamage* const damageDecl, const float damage,
        const float unscaledDamage, const float, const float armorDamage,
        const idVec3& impactPoint, const idVec3& impactDir,
        const idJointIndex impactJoint, const bool killed,
        const bool armorPoppedOff, const bool forceInjured) {
    idDamageImpulse* impulse;
    if (impulses.Num() >= impulses.NumAllocated()) {
        impulse = &impulses[impulses.Num() - 1];
    } else {
        impulse = impulses.Alloc();
    }

    frameDamage += damage;
    frameArmorDamage += armorDamage;
    recentUnscaledDamage += unscaledDamage;
    recentBodyDamage += damage;

    impulse->damageDecl = damageDecl;
    impulse->impactDir = impactDir;
    impulse->impactPoint = impactPoint;
    impulse->jointIndex = impactJoint;
    impulse->damage = damage;
    impulse->armorPoppedOff = armorPoppedOff;
    impulse->forceInjured = forceInjured;

    if (attackerEntity != nullptr) {
        AddRecentDamage(attackerEntity, damage);
    }

    jointIndex = impactJoint;
    if (deathImpulseIdx < 0) {
        inflictor.SetSpawnId(inflictorEntity != nullptr
            ? Tungsten_GetEntitySpawnId(inflictorEntity) : INVALID_SPAWN_ID);
        attacker.SetSpawnId(attackerEntity != nullptr
            ? Tungsten_GetEntitySpawnId(attackerEntity) : INVALID_SPAWN_ID);
        if (killed) {
            deathImpulseIdx = impulses.Num() - 1;
        }
    }
}
