#pragma once

#include "presentable.h"
#include "presentableanimatedphysics.h"

class idDoor_Animated;
class idDoor_AnimatedPiece;

class idFakeCB : public idDummyPhysicsCallback {
public:
    const char* GetName() const override;
};

class idPresentableDoorAnimated;

class idPresentableDoorAnimatedServices {
public:
    virtual ~idPresentableDoorAnimatedServices() = default;
    virtual int GetEntityNumber(idDoor_Animated*) const { return -1; }
    virtual const idDeclFX* GetFXDeclaration(idDoor_Animated*) const {
        return nullptr;
    }
    virtual const char* GetClipModelName(idDoor_AnimatedPiece*) const {
        return "";
    }
    virtual bool IsObstacle(idDoor_AnimatedPiece*) const { return false; }
    virtual void InitPhysics(idPresentableDoorAnimated*, const char*, bool,
        const idDummyPhysicsCallback*, int, int) {}
    virtual void ShutdownPhysics(idPresentableDoorAnimated*) {}
    virtual void SetPhysicsTransform(idPresentableDoorAnimated*,
        const idVec3&, const idMat3&) {}
    virtual void LinkPhysics(idPresentableDoorAnimated*) {}
    virtual void UnlinkPhysics(idPresentableDoorAnimated*) {}
};

void Tungsten_SetPresentableDoorAnimatedServices(
    idPresentableDoorAnimatedServices* services);

class idPresentableDoorAnimated : public idPresentable {
public:
    idPresentableDoorAnimated();
    idPresentableDoorAnimated(idDoor_Animated* door,
        idDoor_AnimatedPiece* piece);
    ~idPresentableDoorAnimated() override;

    void Present() override;
    void Serialize(idSerializer& serializer) override;
    presentableType_t GetType() const override {
        return PRESENTABLE_DOOR_ANIMATED;
    }
    idPresentableDoorAnimated* GetDoorAnimatedInterface() { return this; }

    void InitPhysics(const char* clipModel, bool obstacle,
        const idDummyPhysicsCallback* callback);
    void LinkCollision();
    void UnlinkCollision();

    idStr clip;
    bool physicsInit;
    int entityOwnerIndex;
    bool linked;
};

