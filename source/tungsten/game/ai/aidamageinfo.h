#pragma once

#include "../entities/entityptr.h"
#include "../../../shared/idlib/containers/staticlist.h"
#include "../../../shared/idlib/index.h"
#include "../../../shared/idlib/math/vector.h"
#include "../../../shared/idlib/text/atomicstring.h"

class idAI2;
class idActor;
class idDeclDamage;
class idEntity;

enum invalidJointIndex_t : int;
using idJointIndex = idIndex<short, invalidJointIndex_t>;

struct damageInfo_t {
    idEntityPtr<idEntity> inflictor;
    idEntityPtr<idEntity> attacker;
    const idDeclDamage* damageDef;
    float damage;
    int time;
    idEntityPtr<idActor> actor;
    int actorTime;
};

struct idDamageImpulse {
    const idDeclDamage* damageDecl;
    idVec3 impactDir;
    idVec3 impactPoint;
    idJointIndex jointIndex;
    float damage;
    bool armorPoppedOff;
    bool forceInjured;
};

class idAIDamageInfo {
public:
    struct recentDamager_t {
        idEntityPtrSpawnId spawnId;
        float recentDamage;
    };

    idAIDamageInfo();

    bool Stunned() const;
    idVec3 GetAverageImpactPoint() const;
    idVec3 GetAverageImpactDir() const;
    const idDamageImpulse* GetDeathImpulse() const;
    idEntity* GetInflictor() const;
    idEntity* GetAttacker() const;
    void DecayRecentDamagers();
    float GetRecentDamage(const idEntity* entity) const;
    void EndFrame();
    void AddRecentDamage(const idEntity* entity, float damage);
    void Update(idAI2* ai, idEntity* inflictorEntity,
        idEntity* attackerEntity, const idDeclDamage* damageDecl,
        float damage, float unscaledDamage, float damageScale,
        float armorDamage, const idVec3& impactPoint,
        const idVec3& impactDir, idJointIndex impactJoint,
        bool killed, bool armorPoppedOff, bool forceInjured);

    idStaticList<idDamageImpulse, 8> impulses;
    idEntityPtr<idEntity> inflictor;
    idEntityPtr<idEntity> attacker;
    idStaticList<recentDamager_t, 4> recentDamagers;
    idJointIndex jointIndex;
    int deathImpulseIdx;
    float frameDamage;
    float frameArmorDamage;
    float recentUnscaledDamage;
    float recentBodyDamage;
    int lastBloodSprayTime;
    int mostDamagedIndex;
    bool shouldPain;
    idAtomicString injuryDamageGroup;
    int injuryGoreLevelIndex;
};

int Tungsten_GetEntitySpawnId(const idEntity* entity);
const idEntity* Tungsten_ResolveEntitySpawnId(int spawnId);
bool Tungsten_AIDamageDeclStuns(const idDeclDamage& damageDecl);

static_assert(sizeof(idDamageImpulse) == 40,
    "Recovered AI damage-impulse ABI changed");

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAIDamageInfo) == 436,
    "Recovered AI damage-info ABI changed");
#endif
