#include "presentablepusher.h"

namespace {

idPresentablePusherServices defaultPusherServices;
idPresentablePusherServices* pusherServices = &defaultPusherServices;

bool OriginsEqual(const idVec3& first, const idVec3& second) {
    return first.x == second.x && first.y == second.y
        && first.z == second.z;
}

} // namespace

void Tungsten_SetPresentablePusherServices(
        idPresentablePusherServices* services) {
    pusherServices = services != nullptr ? services : &defaultPusherServices;
}

// EA 0x82B8E0C8
idPresentablePusher::~idPresentablePusher() {
    if (physicsObj != nullptr) {
        pusherServices->DestroyParametricPhysics(physicsObj);
        physicsObj = nullptr;
    }
}

// EA 0x82B8E148
void idPresentablePusher::DisableClip(bool disable) {
    if (physicsInit) {
        pusherServices->EnablePhysicsClip(physicsObj, !disable);
    }
}

// EA 0x82B8E1F8
idPresentablePusher::idPresentablePusher(idEntity* owner,
        idRenderModel* renderModel)
    : idPresentable(owner, renderModel,
        pusherServices->GetEntityNumber(owner), nullptr),
      physicsObj(pusherServices->CreateParametricPhysics()),
      physicsInit(false), pushEnabled(false) {
}

// EA 0x82B8E288
void idPresentablePusher::InitPhysics(idPhysicsCallbacks* callbacks,
        bool isObstacle) {
    if (physicsObj == nullptr) {
        physicsObj = pusherServices->CreateParametricPhysics();
    }
    clipModelPhysID = pusherServices->InitializePhysics(*this, physicsObj,
        callbacks, clipModel, entityNumber, clipModelContents, isObstacle);
    physicsInit = true;
    if (pusherServices->IsClient() && model != nullptr) {
        pusherServices->SetDeferredModelPosition(model, true);
    }
}

// EA 0x82B8E390
void idPresentablePusher::Serialize(idSerializer& serializer) {
    idPresentable::Serialize(serializer);
    serializer.Serialize(pushEnabled);
    if (serializer.IsReading() && !physicsInit) {
        InitPhysics(nullptr, false);
        pusherServices->Present(*this);
    }
}

// EA 0x82B8E430
void idPresentablePusher::UpdateClientCollision(
        const idVec3& oldOrigin, const idMat3& oldAxis,
        const idVec3& newOrigin, const idMat3& newAxis) {
    const int deltaTime = pusherServices->GetServerGameTime()
        - pusherServices->GetPreviousServerGameTime();
    const bool canPush = !pusherServices->PushDisabled() && pushEnabled
        && physicsInit && clipModel != nullptr && clipModelDynamic
        && !OriginsEqual(oldOrigin, newOrigin);
    if (canPush) {
        pusherServices->EnablePhysicsClip(physicsObj, true);
        pusherServices->ClipPush(*this, physicsObj, oldOrigin, oldAxis,
            newOrigin, newAxis);
        const idMat3& linkAxis = clipModelDynamicAxis ? axis : newAxis;
        pusherServices->LinkDynamicClip(clipModel, entityNumber,
            clipModelPhysID, newOrigin, linkAxis);
        pusherServices->UpdatePushedObjects(deltaTime);
        if (deltaTime != 0) {
            pusherServices->ForceUpdateSpatialVelocity(physicsObj,
                newOrigin, newAxis, oldOrigin, oldAxis, deltaTime);
        }
    } else {
        idPresentable::UpdateClientCollision(oldOrigin, oldAxis,
            newOrigin, newAxis);
    }
    pusherServices->SetPhysicsTransform(physicsObj, newOrigin, newAxis);
}
