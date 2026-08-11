#include "clothcomponent.h"

// EA 0x82BB5208: idRibbonManager's zeroing constructor is materialized once
// in engine/gamelib/effects/ribbonmanager.cpp. Keeping that canonical external
// definition avoids a duplicate symbol when GameLib and tungsten_game link.

namespace {

idClothComponentServices defaultClothServices;
idClothComponentServices* clothServices = &defaultClothServices;

} // namespace

void Tungsten_SetClothComponentServices(idClothComponentServices* services) {
    clothServices = services != nullptr ? services : &defaultClothServices;
}

idClothComponent::idClothComponent()
    : clothDecl(nullptr), gibEntity(nullptr), animatedEntity(nullptr),
      clothSim(nullptr), isDetached(false) {}

// EA 0x82BB5228
idClothComponent::~idClothComponent() {
    if (clothSim != nullptr) clothServices->FreeCloth(clothSim);
    clothSim = nullptr;
}

// EA 0x82BB5270
void idClothComponent::Init(idAnimatedEntity* owner) {
    if (clothDecl == nullptr || !clothServices->HasClothModel(clothDecl)) {
        return;
    }
    idTreeAnimator* animator = clothServices->GetTreeAnimator(owner);
    if (owner == nullptr || animator == nullptr
            || !clothServices->AnimatorMatchesCloth(animator, clothDecl)) {
        return;
    }
    animatedEntity = owner;
    clothSim = clothServices->ReserveCloth(clothDecl);
    if (clothSim == nullptr) return;
    idVec3 entityOrigin;
    idMat3 entityAxis(1.0f);
    if (clothServices->GetEntityTransform(animatedEntity, entityOrigin,
            entityAxis)) {
        clothServices->SetClothTransform(clothSim, entityOrigin,
            entityAxis, true);
        if (gibEntity != nullptr) {
            clothServices->RegisterBreakable(gibEntity, entityOrigin);
        }
    }
}

// EA 0x82BB53E0
void idClothComponent::Update() {
    if (clothSim == nullptr) return;
    const idVec3 testWind = clothServices->GetTestWind();
    if (testWind.LengthSqr() > 0.0f) {
        clothServices->SetWind(clothSim, testWind);
    }
    idTreeAnimator* animator = clothServices->GetTreeAnimator(animatedEntity);
    if (isDetached) {
        const int jointCount = clothServices->GetJointCount(animator);
        for (int joint = 1; joint < jointCount; ++joint) {
            clothServices->HideJoint(animator, joint);
        }
    } else {
        clothServices->UpdateJoints(animator, clothSim);
        if (clothServices->IsDetached(clothSim)) {
            isDetached = true;
            if (gibEntity != nullptr) {
                idVec3 detachOrigin;
                idMat3 detachAxis(1.0f);
                if (clothServices->GetClothTransform(clothSim,
                        detachOrigin, detachAxis)) {
                    const idMat3 breakableAxis(
                        detachAxis[2].x, detachAxis[2].y, detachAxis[2].z,
                        detachAxis[0].x, detachAxis[0].y, detachAxis[0].z,
                        detachAxis[1].x, detachAxis[1].y, detachAxis[1].z);
                    clothServices->UseBreakable(gibEntity, detachOrigin,
                        breakableAxis);
                }
            }
        }
    }
    clothServices->UpdateWeaponTraces(clothSim);
    clothServices->RunCloth(clothSim);
    if (clothServices->DebugEnabled()) clothServices->DebugDraw(clothSim);
}
