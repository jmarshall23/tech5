#pragma once

#include "presentable.h"

class idAnimatedSimplePhysics;
class idAnimPhysicsPiece;

class idDummyPhysicsCallback {
public:
    virtual ~idDummyPhysicsCallback() = default;
    virtual const char* GetName() const;
};

class idPresentableAnimatedPhysics;

class idPresentableAnimatedPhysicsServices {
public:
    virtual ~idPresentableAnimatedPhysicsServices() = default;
    virtual int GetEntityNumber(idAnimatedSimplePhysics*) const { return -1; }
    virtual const idDeclFX* GetFXDeclaration(idAnimatedSimplePhysics*) const {
        return nullptr;
    }
    virtual const char* GetClipModelName(idAnimPhysicsPiece*) const {
        return "";
    }
    virtual bool IsObstacle(idAnimPhysicsPiece*) const { return false; }
    virtual void InitPhysics(idPresentableAnimatedPhysics*, const char*,
        bool, const idDummyPhysicsCallback*) {}
    virtual void ShutdownPhysics(idPresentableAnimatedPhysics*) {}
    virtual void SetPhysicsTransform(idPresentableAnimatedPhysics*,
        const idVec3&, const idMat3&) {}
    virtual void LinkPhysics(idPresentableAnimatedPhysics*) {}
    virtual void UnlinkPhysics(idPresentableAnimatedPhysics*) {}
};

void Tungsten_SetPresentableAnimatedPhysicsServices(
    idPresentableAnimatedPhysicsServices* services);
idPresentableAnimatedPhysicsServices&
Tungsten_GetPresentableAnimatedPhysicsServices();

class idPresentableAnimatedPhysics : public idPresentable {
public:
    idPresentableAnimatedPhysics();
    idPresentableAnimatedPhysics(idAnimatedSimplePhysics* entity,
        idAnimPhysicsPiece* piece);
    ~idPresentableAnimatedPhysics() override;

    void Present() override;
    void Serialize(idSerializer& serializer) override;
    void LinkCollision();
    idPresentableAnimatedEntity* GetAnimatedPhysicsInterface() {
        return reinterpret_cast<idPresentableAnimatedEntity*>(this);
    }

    idStr clip;
    bool physicsInit;
    int entityOwnerIndex;
    bool linked;
};
