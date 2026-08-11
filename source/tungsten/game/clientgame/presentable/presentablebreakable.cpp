#include "presentablebreakable.h"

namespace {

idPresentableBreakableServices defaultBreakableServices;
idPresentableBreakableServices* breakableServices = &defaultBreakableServices;

idVec3 BreakableZeroVector() {
    return idVec3(0.0f, 0.0f, 0.0f);
}

idMat3 BreakableIdentityMatrix() {
    return idMat3(1.0f);
}

} // namespace

void Tungsten_SetPresentableBreakableServices(
        idPresentableBreakableServices* services) {
    breakableServices = services != nullptr ? services
                                            : &defaultBreakableServices;
}

idPresentableBreakable::idPresentableBreakable()
    : explodeFrame(0)
    , activatorIndex(0)
    , currentExplodeFrame(0)
    , serializeFrame(0)
    , pieceMinBounceVelocity(1.0f)
    , localExplosionOrigin(BreakableZeroVector())
    , boneToOrientGibTo(-2)
    , broken(false)
    , isRenderModelDiscreteAnimation(false)
    , impactTable(nullptr)
    , breakableParentSpawnId(0)
    , brokenStartTime(0)
    , fadeTimeMS(0)
    , fadeDelayMS(0)
    , physicsInitialized(false) {
    fade = {0, 0, 0.0f, 0.0f, false};
    clipModelDynamic = true;
}

idPresentableBreakable::idPresentableBreakable(idEntity* newEntity,
        idRenderModel* renderModel, int newEntityNumber,
        const idDeclFX* declaration)
    : idPresentable(newEntity, renderModel, newEntityNumber, declaration)
    , explodeFrame(0)
    , activatorIndex(0)
    , currentExplodeFrame(0)
    , serializeFrame(0)
    , pieceMinBounceVelocity(1.0f)
    , localExplosionOrigin(BreakableZeroVector())
    , boneToOrientGibTo(-2)
    , broken(false)
    , isRenderModelDiscreteAnimation(
        breakableServices->IsDiscreteAnimation(renderModel))
    , impactTable(nullptr)
    , breakableParentSpawnId(0)
    , brokenStartTime(0)
    , fadeTimeMS(0)
    , fadeDelayMS(0)
    , physicsInitialized(false) {
    fade = {0, 0, 0.0f, 0.0f, false};
    clipModelDynamic = true;
}

idPresentableBreakable::~idPresentableBreakable() {
    breakableServices->RemoveSimulatingPhysics(this);
    if (physicsInitialized) {
        breakableServices->ShutdownBreakablePhysics(this);
        physicsInitialized = false;
    }
}

void idPresentableBreakable::SetInitProperties(
        const idDeclImpactSound* impact, float minimumBounceVelocity) {
    impactTable = impact;
    pieceMinBounceVelocity = minimumBounceVelocity;
}

void idPresentableBreakable::GibDefault(int currentTime) {
    breakableServices->ResetPhysics(this, false);
    breakableServices->UpdatePhysicsModel(this, origin, axis,
        breakableServices->GetScaledFrameTime());
    breakableServices->AddDefaultExplosion(this, currentTime,
        BreakableZeroVector());
    if (clipModel != nullptr) {
        breakableServices->UnlinkClipModel(clipModel);
    }
}

void idPresentableBreakable::GetWorldTransform(idVec3& outOrigin,
        idMat3& outAxis) {
    if (isRenderModelDiscreteAnimation) {
        outOrigin = BreakableZeroVector();
        outAxis = BreakableIdentityMatrix();
    } else {
        idPresentable::GetWorldTransform(outOrigin, outAxis);
    }
}

bool idPresentableBreakable::ShouldLinkPresentableCollision() {
    return !hidden && !broken;
}

void idPresentableBreakable::Break(const idPresentable* activator) {
    activatorIndex = activator != nullptr ? activator->index + 1 : 0;
    explodeFrame = (explodeFrame + 1) & 31;
    currentExplodeFrame = explodeFrame;
    broken = true;
    breakableServices->MarkSerialized(this);
}

void idPresentableBreakable::PredictHitScanHit(idPresentable*, float,
        const idVec3& hitPosition, const idVec3& projectileDirection,
        const idDeclProjectile*, trace_t* trace) {
    if (trace == nullptr || broken || breakableServices->PredictionDisabled()) {
        return;
    }

    idVec3 direction = projectileDirection;
    direction.NormalizeFast();
    constexpr float CHARACTER_OFFSET = 4.0f;
    const idVec3 worldImpact = hitPosition - direction * CHARACTER_OFFSET;
    localExplosionOrigin = axis.Transpose() * (worldImpact - origin);
    breakableServices->ResetPhysics(this, false);
    breakableServices->UpdatePhysicsModel(this, origin, axis,
        breakableServices->GetScaledFrameTime());
    breakableServices->AddPredictedExplosion(this,
        breakableServices->GetScaledGameTime(), localExplosionOrigin);
    breakableServices->StartExplosions(this, origin, axis,
        breakableServices->GetScaledGameTime());
    broken = true;
    if (clipModel != nullptr) {
        breakableServices->UnlinkClipModel(clipModel);
    }
}

void idPresentableBreakable::StopAllFX() {
    idPresentable::StopAllFX();
    breakableServices->StopExplosionFX(this,
        breakableServices->GetScaledGameTime());
}

void idPresentableBreakable::SetRenderModel(idRenderModel* renderModel,
        bool inheritTransform) {
    idPresentable::SetRenderModel(renderModel, inheritTransform);
    isRenderModelDiscreteAnimation =
        breakableServices->IsDiscreteAnimation(model);
}

void idPresentableBreakable::GibWithActivator(int currentTime,
        const idPresentable* activator) {
    breakableServices->ResetPhysics(this, false);
    breakableServices->UpdatePhysicsModel(this, origin, axis,
        breakableServices->GetScaledFrameTime());
    breakableServices->RemoveExplosions(this);
    idVec3 offset = activator != nullptr
        ? activator->origin - origin : BreakableZeroVector();
    offset.z += 32.0f;
    breakableServices->AddActivatorExplosions(this, currentTime, offset);
    if (clipModel != nullptr) {
        breakableServices->UnlinkClipModel(clipModel);
    }
}

void idPresentableBreakable::PostSerializeRead(bool firstClientFrame) {
    idPresentable::PostSerializeRead(firstClientFrame);
    idPresentable* resolvedParent = breakableParentSpawnId != 0
        ? breakableServices->ResolvePresentableSpawnId(breakableParentSpawnId)
        : nullptr;
    if (resolvedParent != nullptr
            && resolvedParent->spawnId == breakableParentSpawnId) {
        origin = resolvedParent->origin;
        axis = resolvedParent->axis;
    }
}

void idPresentableBreakable::Serialize(idSerializer& serializer) {
    idRenderModel* oldModel = model;
    idPresentable::Serialize(serializer);
    if (serializer.IsReading() && oldModel != model && model != nullptr) {
        fade = {0, 0, 0.0f, 0.0f, false};
        breakableServices->ResetModelVisuals(this);
        breakableServices->InitBreakablePhysics(this, model, impactTable,
            pieceMinBounceVelocity * pieceMinBounceVelocity);
        physicsInitialized = true;
        breakableServices->UpdatePhysicsModel(this, origin, axis,
            breakableServices->GetScaledFrameTime());
        Hide(true);
    }

    serializer.Serialize(explodeFrame);
    serializer.Serialize(activatorIndex);
    serializer.SerializeQ<512, 8>(localExplosionOrigin);
    serializer.Serialize(boneToOrientGibTo);
    serializer.Serialize(breakableParentSpawnId);
    serializer.SerializePacked(fadeTimeMS);
    serializer.SerializePacked(fadeDelayMS);

    if (serializer.IsReading()
            && breakableServices->GetSnapshotsSerialized() < 10) {
        currentExplodeFrame = explodeFrame;
    }
    if (serializer.IsReading() && currentExplodeFrame != explodeFrame) {
        broken = false;
        fade = {0, 0, 0.0f, 0.0f, false};
    }
    ++serializeFrame;
}

void idPresentableBreakable::GibOrientedBodies(int currentTime,
        idPresentable* activator) {
    if (activator == nullptr
            || activator->GetAnimatedEntityInterface() == nullptr
            || !breakableServices->OrientBodies(this, activator,
                boneToOrientGibTo)) {
        return;
    }
    axis = axes[1];
    breakableServices->ResetPhysics(this, true);
    breakableServices->AddOrientedExplosion(this, currentTime,
        localExplosionOrigin);
    breakableServices->StartExplosions(this, origin, axis, currentTime);
    if (clipModel != nullptr) {
        breakableServices->UnlinkClipModel(clipModel);
    }
}

void idPresentableBreakable::Interpolate(int currentTime, float fraction) {
    idPresentable::Interpolate(currentTime, fraction);
    idPresentable* resolvedParent = breakableParentSpawnId != 0
        ? breakableServices->ResolvePresentableSpawnId(breakableParentSpawnId)
        : nullptr;
    if (resolvedParent != nullptr
            && resolvedParent->spawnId == breakableParentSpawnId) {
        origin = resolvedParent->origin;
        axis = resolvedParent->axis;
    }

    if (!broken && currentExplodeFrame != explodeFrame) {
        Show();
        breakableServices->RemoveExplosions(this);
        breakableServices->ResetPhysics(this, false);
        breakableServices->ResetModelVisuals(this);
        idPresentable* activator = activatorIndex > 0
            ? breakableServices->ResolvePresentableIndex(activatorIndex - 1)
            : nullptr;

        bool oriented = false;
        if (boneToOrientGibTo != -2 && activator != nullptr
                && activator->GetAnimatedEntityInterface() != nullptr) {
            oriented = breakableServices->OrientBodies(this, activator,
                boneToOrientGibTo);
            if (oriented) {
                axis = axes[1];
                breakableServices->ResetPhysics(this, true);
                breakableServices->AddOrientedExplosion(this, currentTime,
                    localExplosionOrigin);
                breakableServices->StartExplosions(this, origin, axis,
                    currentTime);
                if (clipModel != nullptr) {
                    breakableServices->UnlinkClipModel(clipModel);
                }
            }
        }
        if (!oriented) {
            if (activator != nullptr) {
                GibWithActivator(currentTime, activator);
            } else {
                GibDefault(currentTime);
            }
        }
        breakableServices->StartExplosions(this, origin, axis, currentTime);
        broken = true;
        brokenStartTime = breakableServices->GetScaledGameTime();
    }
    currentExplodeFrame = explodeFrame;

    if (hidden) {
        return;
    }
    breakableServices->UpdatePhysicsSimulation(this, origin, axis,
        currentTime, breakableServices->GetScaledFrameTime(),
        breakableServices->GetFrameNumber(),
        breakableServices->GetRealFrameTime());
    breakableServices->UpdatePhysicsModel(this, origin, axis,
        breakableServices->GetScaledFrameTime());
    breakableServices->AddSimulatingPhysics(this);

    if (brokenStartTime > 0 && fadeTimeMS > 0
            && breakableServices->GetScaledGameTime()
                >= brokenStartTime + fadeDelayMS) {
        if (fade.fadeEndTime == -1) {
            Hide(true);
        } else if (fade.fadeEndTime > 0) {
            breakableServices->UpdateFade(this, fade);
        } else {
            fade.fadeFrom = 1.0f;
            fade.fadeTo = 0.0f;
            fade.fadeStartTime = breakableServices->GetScaledGameTime();
            fade.fadeEndTime = fade.fadeStartTime + fadeTimeMS;
            fade.noStippleFade = false;
            breakableServices->BeginFade(this, fade, fadeTimeMS);
        }
    }
}
