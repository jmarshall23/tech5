#pragma once

#include "presentable.h"

class idDeclImpactSound;
class idDeclProjectile;
struct trace_t;

struct idBreakableFadeState {
    int fadeStartTime;
    int fadeEndTime;
    float fadeFrom;
    float fadeTo;
    bool noStippleFade;
};

class idPresentableBreakable;

class idPresentableBreakableServices {
public:
    virtual ~idPresentableBreakableServices() = default;
    virtual int GetScaledGameTime() const { return 0; }
    virtual int GetScaledFrameTime() const { return 0; }
    virtual int GetFrameNumber() const { return 0; }
    virtual float GetRealFrameTime() const { return 0.0f; }
    virtual int GetSnapshotsSerialized() const { return 0; }
    virtual bool PredictionDisabled() const { return false; }
    virtual bool IsDiscreteAnimation(idRenderModel*) const { return false; }
    virtual void MarkSerialized(idPresentableBreakable*) {}
    virtual idPresentable* ResolvePresentableIndex(int) const {
        return nullptr;
    }
    virtual idPresentable* ResolvePresentableSpawnId(std::uint32_t) const {
        return nullptr;
    }

    virtual void InitBreakablePhysics(idPresentableBreakable*,
        idRenderModel*, const idDeclImpactSound*, float) {}
    virtual void ShutdownBreakablePhysics(idPresentableBreakable*) {}
    virtual void RemoveSimulatingPhysics(idPresentableBreakable*) {}
    virtual void AddSimulatingPhysics(idPresentableBreakable*) {}
    virtual void ResetPhysics(idPresentableBreakable*, bool) {}
    virtual void UpdatePhysicsModel(idPresentableBreakable*,
        const idVec3&, const idMat3&, int) {}
    virtual void UpdatePhysicsSimulation(idPresentableBreakable*,
        const idVec3&, const idMat3&, int, int, int, float) {}
    virtual void RemoveExplosions(idPresentableBreakable*) {}
    virtual void StartExplosions(idPresentableBreakable*,
        const idVec3&, const idMat3&, int) {}
    virtual void StopExplosionFX(idPresentableBreakable*, int) {}
    virtual void AddDefaultExplosion(idPresentableBreakable*, int,
        const idVec3&) {}
    virtual void AddActivatorExplosions(idPresentableBreakable*, int,
        const idVec3&) {}
    virtual void AddPredictedExplosion(idPresentableBreakable*, int,
        const idVec3&) {}
    virtual void AddOrientedExplosion(idPresentableBreakable*, int,
        const idVec3&) {}
    virtual bool OrientBodies(idPresentableBreakable*, idPresentable*,
        int) { return false; }
    virtual void UnlinkClipModel(idClipModel*) {}
    virtual void ResetModelVisuals(idPresentableBreakable*) {}
    virtual void BeginFade(idPresentableBreakable*, idBreakableFadeState&,
        int) {}
    virtual void UpdateFade(idPresentableBreakable*, idBreakableFadeState&) {}
};

void Tungsten_SetPresentableBreakableServices(
    idPresentableBreakableServices* services);

class idPresentableBreakable : public idPresentable {
public:
    idPresentableBreakable();
    idPresentableBreakable(idEntity* entity, idRenderModel* renderModel,
        int entityNumber, const idDeclFX* fx);
    ~idPresentableBreakable() override;

    void Serialize(idSerializer& serializer) override;
    void PostSerializeRead(bool firstClientFrame) override;
    void Interpolate(int currentTime, float fraction) override;
    void SetRenderModel(idRenderModel* renderModel,
        bool inheritTransform) override;
    void GetWorldTransform(idVec3& outOrigin, idMat3& outAxis) override;
    bool ShouldLinkPresentableCollision() override;
    void StopAllFX() override;
    presentableType_t GetType() const override { return PRESENTABLE_BREAKABLE; }

    void SetInitProperties(const idDeclImpactSound* impact,
        float minimumBounceVelocity);
    void Break(const idPresentable* activator);
    void PredictHitScanHit(idPresentable* attacker, float damage,
        const idVec3& hitPosition, const idVec3& projectileDirection,
        const idDeclProjectile* projectile, trace_t* trace);
    void GibDefault(int currentTime);
    void GibWithActivator(int currentTime, const idPresentable* activator);
    void GibOrientedBodies(int currentTime, idPresentable* activator);

    int explodeFrame;
    int activatorIndex;
    int currentExplodeFrame;
    int serializeFrame;
    float pieceMinBounceVelocity;
    idVec3 localExplosionOrigin;
    int boneToOrientGibTo;
    bool broken;
    bool isRenderModelDiscreteAnimation;
    const idDeclImpactSound* impactTable;
    std::uint32_t breakableParentSpawnId;
    int brokenStartTime;
    int fadeTimeMS;
    int fadeDelayMS;
    idBreakableFadeState fade;
    bool physicsInitialized;
};

