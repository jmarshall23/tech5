#include "presentabledooranimated.h"

namespace {

idPresentableDoorAnimatedServices defaultDoorAnimatedServices;
idPresentableDoorAnimatedServices* doorAnimatedServices =
    &defaultDoorAnimatedServices;
idFakeCB fakeCallback;

} // namespace

void Tungsten_SetPresentableDoorAnimatedServices(
        idPresentableDoorAnimatedServices* services) {
    doorAnimatedServices = services != nullptr ? services
                                               : &defaultDoorAnimatedServices;
}

void idPresentableAnimatedPhysics::LinkCollision() {
    Tungsten_GetPresentableAnimatedPhysicsServices().LinkPhysics(this);
    linked = true;
}

const char* idFakeCB::GetName() const {
    return "fakeCB";
}

idPresentableDoorAnimated::idPresentableDoorAnimated()
    : physicsInit(false)
    , entityOwnerIndex(-1)
    , linked(false) {
}

idPresentableDoorAnimated::idPresentableDoorAnimated(
        idDoor_Animated* door, idDoor_AnimatedPiece* piece)
    : idPresentable(reinterpret_cast<idEntity*>(door), nullptr,
        doorAnimatedServices->GetEntityNumber(door),
        doorAnimatedServices->GetFXDeclaration(door))
    , clip(doorAnimatedServices->GetClipModelName(piece))
    , physicsInit(false)
    , entityOwnerIndex(doorAnimatedServices->GetEntityNumber(door))
    , linked(false) {
    InitPhysics(clip.c_str(), doorAnimatedServices->IsObstacle(piece),
        nullptr);
}

idPresentableDoorAnimated::~idPresentableDoorAnimated() {
    if (physicsInit) {
        doorAnimatedServices->ShutdownPhysics(this);
        physicsInit = false;
    }
}

void idPresentableDoorAnimated::InitPhysics(const char* clipName,
        bool obstacle, const idDummyPhysicsCallback* callback) {
    constexpr int clipMaskValue = 4194305;
    const int contents = 1 | (obstacle ? 0x20000 : 0);
    doorAnimatedServices->InitPhysics(this, clipName, obstacle, callback,
        clipMaskValue, contents);
    physicsInit = true;
}

void idPresentableDoorAnimated::LinkCollision() {
    doorAnimatedServices->LinkPhysics(this);
    linked = true;
}

void idPresentableDoorAnimated::UnlinkCollision() {
    doorAnimatedServices->UnlinkPhysics(this);
    linked = false;
}

void idPresentableDoorAnimated::Present() {
    doorAnimatedServices->SetPhysicsTransform(this, origin, axis);
    idPresentable::Present();
}

void idPresentableDoorAnimated::Serialize(idSerializer& serializer) {
    const bool wasLinked = linked;
    idPresentable::Serialize(serializer);
    serializer.SerializeString(clip);
    serializer.Serialize(entityOwnerIndex);
    serializer.Serialize(linked);

    if (serializer.IsReading() && !physicsInit) {
        InitPhysics(clip.c_str(), false, &fakeCallback);
        Present();
    }
    if (wasLinked != linked) {
        if (linked) {
            LinkCollision();
        } else {
            UnlinkCollision();
        }
    }
}
