#pragma once

#include "presentable.h"

class idPhysics;
class idPhysicsCallbacks;
class idPresentablePusher;

class idPresentablePusherServices {
public:
    virtual ~idPresentablePusherServices() = default;
    virtual int GetEntityNumber(idEntity*) const {
        return idPresentable::ENTITYNUM_NONE;
    }
    virtual idPhysics* CreateParametricPhysics() { return nullptr; }
    virtual void DestroyParametricPhysics(idPhysics*) {}
    virtual int InitializePhysics(idPresentablePusher&, idPhysics*,
        idPhysicsCallbacks*, idClipModel*, int, int, bool) { return -1; }
    virtual void EnablePhysicsClip(idPhysics*, bool) {}
    virtual void SetDeferredModelPosition(idRenderModel*, bool) {}
    virtual bool IsClient() const { return true; }
    virtual bool PushDisabled() const { return false; }
    virtual int GetServerGameTime() const { return 0; }
    virtual int GetPreviousServerGameTime() const { return 0; }
    virtual void ClipPush(idPresentablePusher&, idPhysics*,
        const idVec3&, const idMat3&, const idVec3&, const idMat3&) {}
    virtual void LinkDynamicClip(idClipModel*, int, int,
        const idVec3&, const idMat3&) {}
    virtual void UpdatePushedObjects(int) {}
    virtual void ForceUpdateSpatialVelocity(idPhysics*, const idVec3&,
        const idMat3&, const idVec3&, const idMat3&, int) {}
    virtual void SetPhysicsTransform(idPhysics*, const idVec3&,
        const idMat3&) {}
    virtual void Present(idPresentablePusher&) {}
};

void Tungsten_SetPresentablePusherServices(
    idPresentablePusherServices* services);

class idPresentablePusher : public idPresentable {
public:
    idPresentablePusher(idEntity* owner, idRenderModel* renderModel);
    ~idPresentablePusher() override;

    void DisableClip(bool disable);
    void InitPhysics(idPhysicsCallbacks* callbacks, bool isObstacle);
    void Serialize(idSerializer& serializer) override;
    void UpdateClientCollision(const idVec3& oldOrigin,
        const idMat3& oldAxis, const idVec3& newOrigin,
        const idMat3& newAxis) override;
    idPresentablePusher* GetPusherInterface() override { return this; }

    idPhysics* physicsObj;
    bool physicsInit;
    bool pushEnabled;
};
