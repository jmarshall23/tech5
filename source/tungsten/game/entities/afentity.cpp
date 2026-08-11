#include "game/entities/afentity.h"

#include "idlib/lib_print.h"

namespace {
idAFEntityServices defaultAFEntityServices;
idAFEntityServices* activeAFEntityServices = &defaultAFEntityServices;
}

void idAFEntity_Generic::SetServices(idAFEntityServices* services) {
    activeAFEntityServices = services == nullptr
        ? &defaultAFEntityServices : services;
}

idAFEntityServices& idAFEntity_Generic::Services() {
    return *activeAFEntityServices;
}

// EA 0x82BECF68
idAFEntity_Generic::~idAFEntity_Generic() {
    Services().ShutdownGenericAF(*this);
}

// EA 0x82BECFE8
void idAFEntity_Generic::ShowEditingDialog() {
    Services().ShowAFEditor();
}

// EA 0x82BED008
void idAFEntity_Generic::UpdateEditingDialog() {
    Services().UpdateAFEditor();
}

// EA 0x82BED030
idAFEntity_Generic::idAFEntity_Generic()
    : name(),
      entityNumber(-1),
      spawnPosition(0.0f, 0.0f, 0.0f),
      spawnOrientation(1.0f),
      articulatedFigure(nullptr),
      keepRunningPhysics(false),
      noDrop(false),
      initVelocity(0.0f, 0.0f, 0.0f),
      initAVelocity(0.0f, 0.0f, 0.0f),
      initVelocityDelay(0.0f),
      initAVelocityDelay(0.0f) {}

// EA 0x82BED150
void idAFEntity_Generic::InitTestAF() {
    keepRunningPhysics = true;
    Services().SetGenericTestFlags(*this);
}

// EA 0x82BED168
void idAFEntity_Generic::Think() {
    Services().SyncGenericAF(*this, Services().GetGameMilliseconds());
    Services().RunGenericPhysics(*this);
    Services().SetGenericThinkActive(
        *this, !Services().IsGenericAFAtRest(*this));
    Services().UpdateGenericAnimation(*this);
    if (keepRunningPhysics) {
        Services().SetGenericThinkActive(*this, true);
    }
}

// EA 0x82BED230
void idAFEntity_Generic::OnActivate(idEntity*) {
    Services().ShowGeneric(*this);
    Services().ActivateGenericAF(*this);
    if (initVelocityDelay == 0.0f) {
        Services().SetGenericVelocity(*this, initVelocity, false);
    } else {
        Services().PostGenericVelocity(
            *this, initVelocity, false, initVelocityDelay);
    }
    if (initAVelocityDelay == 0.0f) {
        Services().SetGenericVelocity(*this, initAVelocity, true);
    } else {
        Services().PostGenericVelocity(
            *this, initAVelocity, true, initAVelocityDelay);
    }
}

// EA 0x82BED370
void idAFEntity_Dummy::StartRagdoll() {
    if (!idAFEntity_Generic::Services().IsDummyAFActive(*this)) {
        idAFEntity_Generic::Services().StartDummyRagdoll(
            *this, idAFEntity_Generic::Services().GetGameMilliseconds());
        idAFEntity_Generic::Services().ConfigureDummyRagdollCollision(*this);
    }
    if (idAFEntity_Generic::Services().IsDummyAtRest(*this)) {
        idAFEntity_Generic::Services().ActivateDummyPhysics(*this);
    }
}

// EA 0x82BED8F8
void idAFEntity_Dummy::OnActivate(idEntity*) {
    if (!idAFEntity_Generic::Services().IsDummyAFActive(*this)) {
        StartRagdoll();
    }
}

// EA 0x82BEDAF8
bool idAFEntity_Generic::LoadAF(const idDeclAF* decl) {
    articulatedFigure = decl;
    if (Services().LoadGenericAF(*this, decl, noDrop)) {
        return true;
    }
    idLibPrint::Warning(
        "idAFEntity_Generic::Spawn: Couldn't load articulated figure on entity '%s'",
        name.c_str());
    return false;
}

// EA 0x82BEDC88
void idAFEntity_Dummy::Spawn() {
    if (!idAFEntity_Generic::Services().InitializeDummyAF(*this)) {
        idLibPrint::Warning(
            "idAFEntity_Dummy::Spawn: Couldn't load articulated figure on entity '%s'",
            name.c_str());
        return;
    }
    Reset();
    if (goreDef != nullptr) {
        idAFEntity_Generic::Services().InitializeDummyGore(*this, goreDef);
    }
    idAFEntity_Generic::Services().UpdateDummyPVSAreas(*this);
}

// EA 0x82BEDF30
void idAFEntity_Dummy::Reset() {
    playedDeathAnim = false;
    hasRagDolledYet = false;
    idAFEntity_Generic::Services().ResetDummyPhysics(*this);
    if (idleAnimHandle >= 0) {
        idAFEntity_Generic::Services().PlayDummyIdleAnimation(
            *this, idAFEntity_Generic::Services().GetGameMilliseconds());
    }
    idAFEntity_Generic::Services().ActivateDummyPhysics(*this);
}

// EA 0x82BEE2D8
void idAFEntity_Dummy::ForceStartRagdoll(idEntity* inflictor,
        const idDeclDamage* damageDef, const float,
        const idVec3&, trace_t* trace) {
    StartRagdoll();
    idAFTraceParameters traceInfo =
        idAFEntity_Generic::Services().GetTraceParameters(trace);
    const idVec3 point = traceInfo.valid
        ? traceInfo.point
        : idAFEntity_Generic::Services().GetEntityOrigin(
            inflictor == nullptr ? reinterpret_cast<idEntity*>(this)
                                 : inflictor);
    if (TakesDamage()) {
        idAFEntity_Generic::Services().DisableTargetTurrets(*this);
    }
    const idAFDamageParameters damage =
        idAFEntity_Generic::Services().GetDamageParameters(damageDef);
    if (damage.radius <= 0.0f) {
        idAFEntity_Generic::Services().ApplyDummyRagdollImpulse(*this,
            inflictor, traceInfo.valid ? traceInfo.entityId : -1, point,
            traceInfo.direction * damage.ragdollImpulseMagnitude);
    }
}

// EA 0x82BEE550
void idAFEntity_Generic::Spawn() {
    Services().InitializeGenericAnimator(*this);
    if (articulatedFigure != nullptr) {
        LoadAF(articulatedFigure);
    }
    Services().UpdateGenericVisuals(*this);
}

// EA 0x82BEE648
idAFEntity_Dummy::idAFEntity_Dummy()
    : name(),
      entityNumber(-1),
      spawnPosition(0.0f, 0.0f, 0.0f),
      spawnOrientation(1.0f),
      idleAnimHandle(-1),
      deathAnimHandle(-1),
      takesDamage(true),
      isEnemyOfPlayer(false),
      useSphereModels(false),
      playedDeathAnim(false),
      hasRagDolledYet(false),
      radiusDamageJointNames(0),
      numHitsToKill(1),
      goreDef(nullptr) {}

// EA 0x82BEE880
idAFEntity_Dummy::~idAFEntity_Dummy() {
    idAFEntity_Generic::Services().ShutdownDummy(*this);
    radiusDamageJointNames.Clear();
}

// EA 0x82BEEA50
float idAFEntity_Dummy::Damage(idEntity* inflictor, idEntity* attacker,
        const idDeclDamage* damageDef, const float damageScale,
        const idVec3& direction, trace_t* trace) {
    if (!takesDamage) return 0.0f;
    --numHitsToKill;
    if (numHitsToKill <= 0) {
        if (isEnemyOfPlayer && !hasRagDolledYet) {
            hasRagDolledYet = true;
            idAFEntity_Generic::Services().IncrementEntityKillCount(attacker);
            idAFEntity_Generic::Services().IncrementEntityKillCount(inflictor);
            idAFEntity_Generic::Services().RecordDummyKill(
                attacker, *this, inflictor, damageDef);
        }
        if (deathAnimHandle < 0 || playedDeathAnim) {
            if (!playedDeathAnim) {
                ForceStartRagdoll(inflictor, damageDef,
                    damageScale, direction, trace);
            }
        } else {
            idAFEntity_Generic::Services().PlayDummyDeathAnimation(
                *this, idAFEntity_Generic::Services().GetGameMilliseconds());
            playedDeathAnim = true;
        }
    }
    const idAFTraceParameters traceInfo =
        idAFEntity_Generic::Services().GetTraceParameters(trace);
    if (damageDef != nullptr && traceInfo.valid) {
        const idAFDamageParameters damage =
            idAFEntity_Generic::Services().GetDamageParameters(damageDef);
        idAFEntity_Generic::Services().AddDummyGore(
            *this, traceInfo.joint, damageDef,
            damage.maximumDamage * 2.0f, traceInfo);
    }
    return 0.0f;
}

// EA 0x82BEEC78
void idAFEntity_Dummy::Think() {
    if (idAFEntity_Generic::Services().UpdateDummyDormancy(*this)) return;
    const int time = idAFEntity_Generic::Services().GetGameMilliseconds();
    idAFEntity_Generic::Services().SyncDummyAF(*this, time);
    idAFEntity_Generic::Services().RunDummyPhysics(*this);
    if (!idAFEntity_Generic::Services().IsDummyAFActive(*this)) {
        idAFEntity_Generic::Services().UpdateDummyTurret(*this, time);
    }
    idAFEntity_Generic::Services().UpdateDummyAnimation(*this);
    idAFEntity_Generic::Services().UpdateDummyGore(*this);
    idAFEntity_Generic::Services().UpdateDummyPVSAreas(*this);
}
