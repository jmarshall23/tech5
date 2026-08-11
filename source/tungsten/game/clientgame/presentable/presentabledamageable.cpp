#include "presentabledamageable.h"

namespace {

idPresentableDamageableServices defaultDamageableServices;
idPresentableDamageableServices* damageableServices =
    &defaultDamageableServices;

idVec3 DamageableZeroVector() {
    return idVec3(0.0f, 0.0f, 0.0f);
}

idMat3 DamageableIdentityMatrix() {
    return idMat3(1.0f);
}

} // namespace

void Tungsten_SetPresentableDamageableServices(
        idPresentableDamageableServices* services) {
    damageableServices = services != nullptr ? services
                                             : &defaultDamageableServices;
}

idPresentableDamageable::idPresentableDamageable()
    : rayImpactBufferPos(0)
    , explosionFrame(0)
    , activateAllNowFrame(0)
    , currentExplosionFrame(0)
    , currentActivateAllNowFrame(0)
    , pieceMinBounceVelocity(1.0f)
    , impactTable(nullptr)
    , physicsInitialized(false) {
    for (rayBufferItem_t& item : rayImpactBuffer) {
        item.start = DamageableZeroVector();
        item.end = DamageableZeroVector();
    }
    clipModelDynamic = true;
    clipModelDynamicAxis = true;
}

idPresentableDamageable::idPresentableDamageable(
        idDamageableEntity* damageableEntity, idRenderModel* renderModel)
    : idPresentable(reinterpret_cast<idEntity*>(damageableEntity),
        renderModel, ENTITYNUM_NONE, nullptr)
    , rayImpactBufferPos(0)
    , explosionFrame(0)
    , activateAllNowFrame(0)
    , currentExplosionFrame(0)
    , currentActivateAllNowFrame(0)
    , pieceMinBounceVelocity(1.0f)
    , impactTable(nullptr)
    , physicsInitialized(false) {
    for (rayBufferItem_t& item : rayImpactBuffer) {
        item.start = DamageableZeroVector();
        item.end = DamageableZeroVector();
    }
    clipModelDynamic = true;
    clipModelDynamicAxis = true;
}

idPresentableDamageable::~idPresentableDamageable() {
    damageableServices->RemoveSimulatingPhysics(this);
    if (physicsInitialized) {
        damageableServices->ShutdownBreakablePhysics(this);
        physicsInitialized = false;
    }
}

void idPresentableDamageable::SetInitProperties(
        const idDeclImpactSound* impact, float minimumBounceVelocity) {
    impactTable = impact;
    pieceMinBounceVelocity = minimumBounceVelocity;
}

void idPresentableDamageable::Present() {
    idPresentable::Present();
}

void idPresentableDamageable::StartExplosions() {
    explosionFrame = (explosionFrame + 1) & 15;
    currentExplosionFrame = explosionFrame;
}

void idPresentableDamageable::ActivateAllNow() {
    activateAllNowFrame = (activateAllNowFrame + 1) & 15;
    currentActivateAllNowFrame = activateAllNowFrame;
}

void idPresentableDamageable::Interpolate(int currentTime,
        float fraction) {
    idPresentable::Interpolate(currentTime, fraction);
    if (!damageableServices->IsDiscreteAnimation(model)) {
        return;
    }
    if (currentExplosionFrame != explosionFrame) {
        SetLocalClipModelContents(0);
        damageableServices->StartExplosions(this, origin, axis, currentTime);
        currentExplosionFrame = explosionFrame;
    }
    if (currentActivateAllNowFrame != activateAllNowFrame) {
        SetLocalClipModelContents(0);
        damageableServices->ActivateAllNow(this, origin, axis);
        currentActivateAllNowFrame = activateAllNowFrame;
    }
    if (!hidden) {
        damageableServices->UpdateSimulation(this, origin, axis,
            damageableServices->GetScaledGameTime(),
            damageableServices->GetScaledFrameTime(),
            damageableServices->GetFrameNumber(),
            damageableServices->GetRealFrameTime());
        damageableServices->UpdateModel(this, origin, axis,
            damageableServices->GetScaledFrameTime());
        damageableServices->AddSimulatingPhysics(this);
    }
}

void idPresentableDamageable::GetWorldTransform(idVec3& outOrigin,
        idMat3& outAxis) {
    if (damageableServices->IsDiscreteAnimation(model)) {
        outOrigin = DamageableZeroVector();
        outAxis = DamageableIdentityMatrix();
    } else {
        idPresentable::GetWorldTransform(outOrigin, outAxis);
    }
}

void idPresentableDamageable::AddRayImpact(const idVec3& start,
        const idVec3& end) {
    rayImpactBuffer[rayImpactBufferPos].start = start;
    rayImpactBuffer[rayImpactBufferPos].end = end;
    rayImpactBufferPos = (rayImpactBufferPos + 1) % 10;
}

void idPresentableDamageable::Serialize(idSerializer& serializer) {
    idRenderModel* oldModel = model;
    idPresentable::Serialize(serializer);
    if (serializer.IsReading() && oldModel != model
            && damageableServices->IsDiscreteAnimation(model)) {
        damageableServices->InitBreakablePhysics(this, model, impactTable,
            pieceMinBounceVelocity * pieceMinBounceVelocity);
        physicsInitialized = true;
        damageableServices->UpdateModel(this, origin, axis,
            damageableServices->GetScaledFrameTime());
    }

    int incomingBufferPosition = rayImpactBufferPos;
    serializer.Serialize(incomingBufferPosition);
    serializer.Serialize(explosionFrame);
    serializer.Serialize(activateAllNowFrame);
    for (rayBufferItem_t& item : rayImpactBuffer) {
        serializer.Serialize(item.start);
        serializer.Serialize(item.end);
    }

    if (serializer.IsReading()
            && damageableServices->IsDiscreteAnimation(model)
            && rayImpactBufferPos != incomingBufferPosition) {
        while (rayImpactBufferPos != incomingBufferPosition) {
            const rayBufferItem_t& item = rayImpactBuffer[rayImpactBufferPos];
            damageableServices->AddRayImpact(this,
                damageableServices->GetScaledGameTime(), origin, axis,
                item.start, item.end);
            rayImpactBufferPos = (rayImpactBufferPos + 1) % 10;
        }
    }
    rayImpactBufferPos = incomingBufferPosition;
}

