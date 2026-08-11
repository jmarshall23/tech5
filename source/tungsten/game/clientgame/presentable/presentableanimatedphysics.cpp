#include "presentableanimatedphysics.h"

namespace {

idPresentableAnimatedPhysicsServices defaultAnimatedPhysicsServices;
idPresentableAnimatedPhysicsServices* animatedPhysicsServices =
    &defaultAnimatedPhysicsServices;
idDummyPhysicsCallback dummyPhysicsCallback;

} // namespace

void Tungsten_SetPresentableAnimatedPhysicsServices(
        idPresentableAnimatedPhysicsServices* services) {
    animatedPhysicsServices = services != nullptr ? services
                                                   : &defaultAnimatedPhysicsServices;
}

idPresentableAnimatedPhysicsServices&
Tungsten_GetPresentableAnimatedPhysicsServices() {
    return *animatedPhysicsServices;
}

const char* idDummyPhysicsCallback::GetName() const {
    return "dummyCB";
}

idPresentableAnimatedPhysics::idPresentableAnimatedPhysics()
    : physicsInit(false)
    , entityOwnerIndex(-1)
    , linked(false) {
}

idPresentableAnimatedPhysics::idPresentableAnimatedPhysics(
        idAnimatedSimplePhysics* physicsEntity, idAnimPhysicsPiece* piece)
    : idPresentable(reinterpret_cast<idEntity*>(physicsEntity), nullptr,
        animatedPhysicsServices->GetEntityNumber(physicsEntity),
        animatedPhysicsServices->GetFXDeclaration(physicsEntity))
    , clip(animatedPhysicsServices->GetClipModelName(piece))
    , physicsInit(false)
    , entityOwnerIndex(animatedPhysicsServices->GetEntityNumber(physicsEntity))
    , linked(false) {
    animatedPhysicsServices->InitPhysics(this, clip.c_str(),
        animatedPhysicsServices->IsObstacle(piece), nullptr);
    physicsInit = true;
}

idPresentableAnimatedPhysics::~idPresentableAnimatedPhysics() {
    if (physicsInit) {
        animatedPhysicsServices->ShutdownPhysics(this);
        physicsInit = false;
    }
}

void idPresentableAnimatedPhysics::Present() {
    animatedPhysicsServices->SetPhysicsTransform(this, origin, axis);
    idPresentable::Present();
}

void idPresentableAnimatedPhysics::Serialize(idSerializer& serializer) {
    const bool wasLinked = linked;
    idPresentable::Serialize(serializer);
    serializer.SerializeString(clip);
    serializer.Serialize(entityOwnerIndex);
    serializer.Serialize(linked);

    if (serializer.IsReading() && !physicsInit) {
        animatedPhysicsServices->InitPhysics(this, clip.c_str(), false,
            &dummyPhysicsCallback);
        physicsInit = true;
        Present();
    }
    if (wasLinked != linked) {
        if (linked) {
            animatedPhysicsServices->LinkPhysics(this);
        } else {
            animatedPhysicsServices->UnlinkPhysics(this);
        }
    }
}
