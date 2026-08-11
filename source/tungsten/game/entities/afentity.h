#pragma once

#include "idlib/containers/list.h"
#include "idlib/math/angles.h"
#include "idlib/math/matrix.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

class idAFEntity_Dummy;
class idAFEntity_Generic;
class idDeclAF;
class idDeclDamage;
class idDeclGore;
class idEntity;
struct trace_t;

struct idAFDamageParameters {
    float radius = 0.0f;
    float ragdollImpulseMagnitude = 0.0f;
    float maximumDamage = 0.0f;
};

struct idAFTraceParameters {
    bool valid = false;
    int entityId = -1;
    int joint = -1;
    idVec3 point{0.0f, 0.0f, 0.0f};
    idVec3 normal{0.0f, 0.0f, 1.0f};
    idVec3 direction{0.0f, 0.0f, 0.0f};
};

class idAFEntityServices {
public:
    virtual ~idAFEntityServices() = default;
    virtual int GetGameMilliseconds() const { return 0; }
    virtual void ShowAFEditor() {}
    virtual void UpdateAFEditor() {}
    virtual void ShutdownGenericAF(idAFEntity_Generic&) {}
    virtual void InitializeGenericAnimator(idAFEntity_Generic&) {}
    virtual bool LoadGenericAF(
        idAFEntity_Generic&, const idDeclAF*, bool) { return false; }
    virtual void SyncGenericAF(idAFEntity_Generic&, int) {}
    virtual void RunGenericPhysics(idAFEntity_Generic&) {}
    virtual bool IsGenericAFAtRest(const idAFEntity_Generic&) const {
        return false;
    }
    virtual void SetGenericThinkActive(idAFEntity_Generic&, bool) {}
    virtual void UpdateGenericAnimation(idAFEntity_Generic&) {}
    virtual void ShowGeneric(idAFEntity_Generic&) {}
    virtual void ActivateGenericAF(idAFEntity_Generic&) {}
    virtual void SetGenericVelocity(
        idAFEntity_Generic&, const idVec3&, bool) {}
    virtual void PostGenericVelocity(
        idAFEntity_Generic&, const idVec3&, bool, float) {}
    virtual void SetGenericTestFlags(idAFEntity_Generic&) {}
    virtual void UpdateGenericVisuals(idAFEntity_Generic&) {}

    virtual void ShutdownDummy(idAFEntity_Dummy&) {}
    virtual bool IsDummyAFActive(const idAFEntity_Dummy&) const {
        return false;
    }
    virtual bool InitializeDummyAF(idAFEntity_Dummy&) { return false; }
    virtual void StartDummyRagdoll(idAFEntity_Dummy&, int) {}
    virtual bool IsDummyAtRest(const idAFEntity_Dummy&) const {
        return false;
    }
    virtual void ActivateDummyPhysics(idAFEntity_Dummy&) {}
    virtual void ConfigureDummyRagdollCollision(idAFEntity_Dummy&) {}
    virtual void ResetDummyPhysics(idAFEntity_Dummy&) {}
    virtual void InitializeDummyGore(
        idAFEntity_Dummy&, const idDeclGore*) {}
    virtual void UpdateDummyPVSAreas(idAFEntity_Dummy&) {}
    virtual void PlayDummyIdleAnimation(idAFEntity_Dummy&, int) {}
    virtual void PlayDummyDeathAnimation(idAFEntity_Dummy&, int) {}
    virtual void DisableTargetTurrets(idAFEntity_Dummy&) {}
    virtual idVec3 GetEntityOrigin(const idEntity*) const {
        return idVec3(0.0f, 0.0f, 0.0f);
    }
    virtual idAFDamageParameters GetDamageParameters(
        const idDeclDamage*) const { return {}; }
    virtual idAFTraceParameters GetTraceParameters(
        const trace_t*) const { return {}; }
    virtual void ApplyDummyRagdollImpulse(idAFEntity_Dummy&,
        idEntity*, int, const idVec3&, const idVec3&) {}
    virtual void RecordDummyKill(idEntity*, idAFEntity_Dummy&,
        idEntity*, const idDeclDamage*) {}
    virtual void IncrementEntityKillCount(idEntity*) {}
    virtual void AddDummyGore(idAFEntity_Dummy&, int,
        const idDeclDamage*, float, const idAFTraceParameters&) {}
    virtual bool UpdateDummyDormancy(idAFEntity_Dummy&) { return false; }
    virtual void SyncDummyAF(idAFEntity_Dummy&, int) {}
    virtual void RunDummyPhysics(idAFEntity_Dummy&) {}
    virtual void UpdateDummyTurret(idAFEntity_Dummy&, int) {}
    virtual void UpdateDummyAnimation(idAFEntity_Dummy&) {}
    virtual void UpdateDummyGore(idAFEntity_Dummy&) {}
};

class idAFEntity_Generic {
public:
    idAFEntity_Generic();
    virtual ~idAFEntity_Generic();

    static void SetServices(idAFEntityServices* services);
    static idAFEntityServices& Services();

    virtual void ShowEditingDialog();
    virtual void UpdateEditingDialog();
    void InitTestAF();
    virtual void Think();
    virtual void OnActivate(idEntity* activator);
    bool LoadAF(const idDeclAF* decl);
    void Spawn();

    idStr name;
    int entityNumber;
    idVec3 spawnPosition;
    idMat3 spawnOrientation;
    const idDeclAF* articulatedFigure;
    bool keepRunningPhysics;
    bool noDrop;
    idVec3 initVelocity;
    idVec3 initAVelocity;
    float initVelocityDelay;
    float initAVelocityDelay;
};

class idAFEntity_Dummy {
public:
    idAFEntity_Dummy();
    virtual ~idAFEntity_Dummy();

    void StartRagdoll();
    virtual void OnActivate(idEntity* activator);
    void Spawn();
    virtual void Reset();
    void ForceStartRagdoll(idEntity* inflictor,
        const idDeclDamage* damageDef, float damageScale,
        const idVec3& direction, trace_t* trace);
    float Damage(idEntity* inflictor, idEntity* attacker,
        const idDeclDamage* damageDef, float damageScale,
        const idVec3& direction, trace_t* trace);
    virtual void Think();
    bool TakesDamage() const { return takesDamage; }

    idStr name;
    int entityNumber;
    idVec3 spawnPosition;
    idMat3 spawnOrientation;
    int idleAnimHandle;
    int deathAnimHandle;
    bool takesDamage;
    bool isEnemyOfPlayer;
    bool useSphereModels;
    bool playedDeathAnim;
    bool hasRagDolledYet;
    idList<idStr, 5> radiusDamageJointNames;
    int numHitsToKill;
    const idDeclGore* goreDef;
};
