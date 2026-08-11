#pragma once

#include "idlib/containers/list.h"
#include "idlib/math/vector.h"

class idDeclDamage;
class idDeclImpactSound;
class idDeclParticle;
class idEntity;
class idPresentable;
class idRenderModel;
class idSoundShader;
struct trace_t;
class idBreakable;

struct idBreakableFadeState {
    int fadeStartTime = 0;
    int fadeEndTime = 0;
    float fadeFrom = 0.0f;
    float fadeTo = 0.0f;
    bool noStippleFade = false;
};

struct idBreakableExplosionParms {
    idVec3 position{0.0f, 0.0f, 0.0f};
    float radius = 0.0f;
    float impulse = 0.0f;
    float falloff = 0.0f;
    float angular = 0.0f;
    int delay = 0;
    int duration = 0;
};

class idBreakableServices {
public:
    virtual ~idBreakableServices() = default;
    virtual void Hide(idBreakable&) {}
    virtual void Show(idBreakable&) {}
    virtual void SetClipEnabled(idBreakable&, bool) {}
    virtual void SetThinkFlags(idBreakable&, int, bool) {}
    virtual int GetThinkFlags(const idBreakable&) const { return 0; }
    virtual bool Initialize(idBreakable&, int& maxSimulationTime) {
        maxSimulationTime = 0; return false;
    }
    virtual idPresentable* AllocPresentable(idBreakable&,
        idRenderModel*, const idDeclImpactSound*, float) { return nullptr; }
    virtual void GetTransform(const idBreakable&,
        idVec3& origin, idMat3& axis) const {
        origin.Zero(); axis = idMat3(1.0f);
    }
    virtual void UpdateBreakableModel(idBreakable&) {}
    virtual void ResetPhysics(idBreakable&, bool) {}
    virtual void SetCoverage(idBreakable&, float) {}
    virtual void ForceDormancy(idBreakable&, bool, int) {}
    virtual void BreakPresentable(idBreakable&, idEntity*) {}
    virtual int GetGameMilliseconds() const { return 0; }
    virtual int GetGameFrame() const { return 0; }
    virtual int GetGameMillisecondsPerFrame() const { return 16; }
    virtual float GetRealMillisecondsPerFrame() const { return 16.0f; }
    virtual void UnlinkMainClip(idBreakable&) {}
    virtual bool IsVehicle(idEntity*) const { return false; }
    virtual void ConfigureVehicleBreakExplosions(
        idBreakable&, idEntity*) {}
    virtual void ApplyBreakForce(idBreakable&, const idVec3&) {}
    virtual void PlayBreakSound(idBreakable&, const idSoundShader*) {}
    virtual void ActivateTargets(idBreakable&, idEntity*) {}
    virtual bool GetImpulseExplosion(int, idEntity*&,
        idVec3&, idBreakableExplosionParms&) const { return false; }
    virtual void AddPhysicsExplosion(idBreakable&,
        const idBreakableExplosionParms&) {}
    virtual bool TakesDamage(const idBreakable&) const { return true; }
    virtual float GetDamageAmount(const idDeclDamage*) const { return 0.0f; }
    virtual int GetDamageTypes(const idDeclDamage*) const { return 0; }
    virtual void ConfigureDamageExplosion(idBreakable&, idEntity*,
        const idDeclDamage*, const idVec3&, const trace_t*) {}
    virtual void DamageFeedback(idEntity*, idBreakable&, idEntity*,
        const idDeclDamage*, float) {}
    virtual void RemoveSimulation(idBreakable&) {}
    virtual bool UpdateDormant(idBreakable&) { return false; }
    virtual void StartExplosions(idBreakable&) {}
    virtual bool IsBound(const idBreakable&) const { return false; }
    virtual void UpdateSimulation(idBreakable&) {}
    virtual void RegisterSimulation(idBreakable&) {}
    virtual void UpdatePVSAreas(idBreakable&) {}
    virtual float RandomFloat() { return 0.0f; }
    virtual void EmitDamageParticles(idBreakable&,
        const idDeclParticle*, int, const idVec3&, float) {}
    virtual bool IsMultiplayer() const { return false; }
    virtual void SetMultiplayerFade(idBreakable&, int, int) {}
    virtual void UpdateFade(idBreakable&, idBreakableFadeState&) {}
    virtual void DebugDrawCollision(idBreakable&) {}
    virtual void Warn(const char*) {}
};

class idBreakable {
public:
    struct breakState_t {
        int healthPercent = 0;
        int smokeSystemRate = 1;
        int startTime = 0;
        const idDeclParticle* particle = nullptr;
        idVec3 offset{0.0f, 0.0f, 0.0f};
    };

    idBreakable();
    virtual ~idBreakable();

    static void SetServices(idBreakableServices* services);
    static idBreakableServices& Services();

    virtual void Hide();
    void Spawn();
    virtual idPresentable* AllocPresentable(idRenderModel* renderModel);
    virtual void PostBind();
    virtual void GetModelTransform(idVec3& origin, idMat3& axis) const;
    void Reset();
    void ResetRigidBodies();
    virtual void Show();
    virtual void ApplyImpulse(int physicsId, int bodyId,
        const idVec3& point, const idVec3& impulse);
    virtual float Damage(idEntity* inflictor, idEntity* attacker,
        const idDeclDamage* damage, float damageScale,
        const idVec3& direction, trace_t* trace);
    idVec3 AddExplosion(const idVec3& position, float impulse);
    virtual void OnActivate(idEntity* activator);
    virtual void Think();

    const idSoundShader* soundExplosion;
    const idDeclImpactSound* impactSoundTable;
    float pieceMinBounceVelocity;
    bool targetable;
    int ignoreDamageType;
    bool isPooled;
    idList<breakState_t, 5> breakState;
    idVec3 soundOffset;
    int maxSimulationTime;
    int brokenStartTime;
    int brokenFrame;
    float currentHealth;
    float health;
    bool fadeBroken;
    float fadeTime;
    float fadeDelay;
    float velocityScale;
    idBreakableFadeState fade;
    idVec3 oldOrigin;
    idVec3 velocity;

private:
    void Break(idEntity* activator);
    void ResetCommon(bool resetModel);
};
