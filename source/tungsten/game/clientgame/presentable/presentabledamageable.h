#pragma once

#include "presentable.h"

class idDamageableEntity;
class idDeclImpactSound;

class idPresentableDamageable;

class idPresentableDamageableServices {
public:
    virtual ~idPresentableDamageableServices() = default;
    virtual int GetScaledGameTime() const { return 0; }
    virtual int GetScaledFrameTime() const { return 0; }
    virtual int GetFrameNumber() const { return 0; }
    virtual float GetRealFrameTime() const { return 0.0f; }
    virtual bool IsDiscreteAnimation(idRenderModel*) const { return false; }
    virtual void InitBreakablePhysics(idPresentableDamageable*,
        idRenderModel*, const idDeclImpactSound*, float) {}
    virtual void ShutdownBreakablePhysics(idPresentableDamageable*) {}
    virtual void RemoveSimulatingPhysics(idPresentableDamageable*) {}
    virtual void AddSimulatingPhysics(idPresentableDamageable*) {}
    virtual void StartExplosions(idPresentableDamageable*,
        const idVec3&, const idMat3&, int) {}
    virtual void ActivateAllNow(idPresentableDamageable*,
        const idVec3&, const idMat3&) {}
    virtual void UpdateSimulation(idPresentableDamageable*,
        const idVec3&, const idMat3&, int, int, int, float) {}
    virtual void UpdateModel(idPresentableDamageable*,
        const idVec3&, const idMat3&, int) {}
    virtual void AddRayImpact(idPresentableDamageable*, int,
        const idVec3&, const idMat3&, const idVec3&, const idVec3&) {}
};

void Tungsten_SetPresentableDamageableServices(
    idPresentableDamageableServices* services);

class idPresentableDamageable : public idPresentable {
public:
    struct rayBufferItem_t {
        idVec3 start;
        idVec3 end;
    };

    idPresentableDamageable();
    idPresentableDamageable(idDamageableEntity* entity,
        idRenderModel* renderModel);
    ~idPresentableDamageable() override;

    void Present() override;
    void Serialize(idSerializer& serializer) override;
    void Interpolate(int currentTime, float fraction) override;
    void GetWorldTransform(idVec3& outOrigin, idMat3& outAxis) override;
    presentableType_t GetType() const override { return PRESENTABLE_DAMAGEABLE; }
    idPresentableDamageable* GetDamageableInterface() { return this; }

    void SetInitProperties(const idDeclImpactSound* impact,
        float minimumBounceVelocity);
    void StartExplosions();
    void ActivateAllNow();
    void AddRayImpact(const idVec3& start, const idVec3& end);

    rayBufferItem_t rayImpactBuffer[10];
    int rayImpactBufferPos;
    int explosionFrame;
    int activateAllNowFrame;
    int currentExplosionFrame;
    int currentActivateAllNowFrame;
    float pieceMinBounceVelocity;
    const idDeclImpactSound* impactTable;
    bool physicsInitialized;
};

