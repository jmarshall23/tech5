#pragma once

#include "presentable.h"

class idPresentableArmorPiece;

struct idArmorFadeState {
    int fadeStartTime;
    int fadeEndTime;
    float fadeFrom;
    float fadeTo;
    bool noStippleFade;
};

class idArmorPiecePhysicsCallback {
public:
    idArmorPiecePhysicsCallback() : self(nullptr) {}
    virtual ~idArmorPiecePhysicsCallback() = default;
    virtual const char* GetName() const;
    virtual void ApplyImpulse(int physicsId, int bodyId,
        const idVec3& point, const idVec3& impulse);
    virtual void ApplyForce(int physicsId, int bodyId,
        const idVec3& point, const idVec3& force);
    virtual void ActivatePhysics(int physicsId);
    virtual void DeactivatePhysics(int physicsId);

    idPresentableArmorPiece* self;
};

class idPresentableArmorPieceServices {
public:
    virtual ~idPresentableArmorPieceServices() = default;
    virtual int GetScaledGameTime() const { return 0; }
    virtual int GetScaledFrameTime() const { return 0; }
    virtual void InitRigidBody(idPresentableArmorPiece*,
        idArmorPiecePhysicsCallback*, float, float, float, float,
        float, int, int) {}
    virtual void ShutdownRigidBody(idPresentableArmorPiece*) {}
    virtual void ApplyImpulse(idPresentableArmorPiece*, int,
        const idVec3&, const idVec3&) {}
    virtual void ApplyForce(idPresentableArmorPiece*, int,
        const idVec3&, const idVec3&) {}
    virtual void Activate(idPresentableArmorPiece*) {}
    virtual void PutToRest(idPresentableArmorPiece*) {}
    virtual void Evaluate(idPresentableArmorPiece*, int, int) {}
    virtual void GetTransform(idPresentableArmorPiece*, idVec3&,
        idMat3&) const {}
    virtual bool IsAtRest(idPresentableArmorPiece*) const { return false; }
    virtual void BeginFade(idPresentableArmorPiece*, idArmorFadeState&,
        float, float, int, bool) {}
    virtual void UpdateFade(idPresentableArmorPiece*, idArmorFadeState&) {}
};

void Tungsten_SetPresentableArmorPieceServices(
    idPresentableArmorPieceServices* services);

class idPresentableArmorPiece : public idPresentable {
public:
    idPresentableArmorPiece();
    idPresentableArmorPiece(idRenderModel* renderModel,
        const idVec3& origin, const idMat3& axis, int entityNumber);
    ~idPresentableArmorPiece() override;

    void ClientThink(int currentTime, float fraction, bool predict) override;
    idPresentableArmorPiece* GetArmorInterface() { return this; }
    void InitArmorDefaults();

    idArmorPiecePhysicsCallback physicsCallback;
    idArmorFadeState fade;
    float fadeTime;
    bool removeWhenAtRest;
    bool physicsInitialized;
};
