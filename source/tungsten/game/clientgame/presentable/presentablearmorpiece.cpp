#include "presentablearmorpiece.h"

namespace {

idPresentableArmorPieceServices defaultArmorPieceServices;
idPresentableArmorPieceServices* armorPieceServices =
    &defaultArmorPieceServices;

} // namespace

void Tungsten_SetPresentableArmorPieceServices(
        idPresentableArmorPieceServices* services) {
    armorPieceServices = services != nullptr ? services
                                             : &defaultArmorPieceServices;
}

const char* idArmorPiecePhysicsCallback::GetName() const {
    return "Client Armor piece physics";
}

void idArmorPiecePhysicsCallback::ApplyImpulse(int, int bodyId,
        const idVec3& point, const idVec3& impulse) {
    if (self != nullptr) {
        armorPieceServices->ApplyImpulse(self, bodyId, point, impulse);
    }
}

void idArmorPiecePhysicsCallback::ApplyForce(int, int bodyId,
        const idVec3& point, const idVec3& force) {
    if (self != nullptr) {
        armorPieceServices->ApplyForce(self, bodyId, point, force);
    }
}

void idArmorPiecePhysicsCallback::ActivatePhysics(int) {
    if (self != nullptr) {
        armorPieceServices->Activate(self);
    }
}

void idArmorPiecePhysicsCallback::DeactivatePhysics(int) {
    if (self != nullptr) {
        armorPieceServices->PutToRest(self);
    }
}

idPresentableArmorPiece::idPresentableArmorPiece()
    : fadeTime(0.0f)
    , removeWhenAtRest(false)
    , physicsInitialized(false) {
    fade = {0, 0, 0.0f, 0.0f, false};
}

idPresentableArmorPiece::idPresentableArmorPiece(idRenderModel* renderModel,
        const idVec3& newOrigin, const idMat3& newAxis,
        int newEntityNumber)
    : idPresentable(nullptr, renderModel, newEntityNumber, nullptr)
    , fadeTime(0.0f)
    , removeWhenAtRest(false)
    , physicsInitialized(false) {
    fade = {0, 0, 0.0f, 0.0f, false};
    origin = newOrigin;
    axis = newAxis;
    origins[0] = origins[1] = origin;
    axes[0] = axes[1] = axis;
    InitArmorDefaults();
}

idPresentableArmorPiece::~idPresentableArmorPiece() {
    if (physicsInitialized) {
        armorPieceServices->ShutdownRigidBody(this);
        physicsInitialized = false;
    }
}

void idPresentableArmorPiece::InitArmorDefaults() {
    physicsCallback.self = this;
    removeWhenAtRest = false;
    fadeTime = 0.0f;
    armorPieceServices->InitRigidBody(this, &physicsCallback,
        0.6f, 0.6f, 0.6f, 0.05f, 0.002f, 0, 1);
    physicsInitialized = true;
    armorPieceServices->PutToRest(this);
    fade = {0, 0, 0.0f, 0.0f, false};
}

void idPresentableArmorPiece::ClientThink(int, float, bool) {
    if (fade.fadeEndTime > 0) {
        armorPieceServices->UpdateFade(this, fade);
    }
    physicsCallback.self = this;
    const int gameTime = armorPieceServices->GetScaledGameTime();
    armorPieceServices->Evaluate(this,
        armorPieceServices->GetScaledFrameTime(), gameTime);
    armorPieceServices->GetTransform(this, origin, axis);

    if (removeWhenAtRest) {
        if (fade.fadeEndTime <= 0) {
            if (fade.fadeEndTime == -1) {
                queueForDelete = true;
            } else if (armorPieceServices->IsAtRest(this)
                    && fadeTime > 0.0f && model != nullptr) {
                const int duration = static_cast<int>(fadeTime * 1000.0f);
                fade.fadeFrom = 1.0f;
                fade.fadeTo = 0.0f;
                fade.fadeStartTime = gameTime;
                fade.fadeEndTime = gameTime + duration;
                fade.noStippleFade = false;
                armorPieceServices->BeginFade(this, fade, 1.0f, 0.0f,
                    duration, false);
            }
        } else {
            armorPieceServices->UpdateFade(this, fade);
        }
    }
    Present();
}

