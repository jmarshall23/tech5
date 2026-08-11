#include "game/entities/animatedsimplephysics.h"

namespace {
idAnimatedSimplePhysicsServices defaultAnimatedSimplePhysicsServices;
idAnimatedSimplePhysicsServices* animatedSimplePhysicsServices =
    &defaultAnimatedSimplePhysicsServices;
}

void idAnimatedSimplePhysics::SetPhysicsServices(
        idAnimatedSimplePhysicsServices* const services) {
    animatedSimplePhysicsServices = services == nullptr
        ? &defaultAnimatedSimplePhysicsServices : services;
}

idAnimatedSimplePhysicsServices&
idAnimatedSimplePhysics::PhysicsServices() {
    return *animatedSimplePhysicsServices;
}

// Retail: 0x82C00C88 ?Hide@idAnimatedSimplePhysics@@UAAXXZ
void idAnimatedSimplePhysics::Hide() {
    const bool relaxed = PhysicsServices().UseRelaxedChatter(*this);
    idAnimatedSimple::Hide();
    if (!relaxed) {
        PhysicsServices().SetPhysicsThinkActive(*this, false);
        for (int index = 0; index < collisionParts.Num(); ++index) {
            if (collisionParts[index].presentable != nullptr) {
                PhysicsServices().SetPieceVisible(
                    *this, collisionParts[index], false);
            }
        }
        PhysicsServices().LinkMainClip(*this, false);
    }
}

// Retail: 0x82C00D38 ?Show@idAnimatedSimplePhysics@@UAAXXZ
void idAnimatedSimplePhysics::Show() {
    const bool relaxed = PhysicsServices().UseRelaxedChatter(*this);
    idAnimatedSimple::Show();
    if (relaxed) {
        PhysicsServices().SetPhysicsThinkActive(*this, true);
        for (int index = 0; index < collisionParts.Num(); ++index) {
            if (collisionParts[index].presentable != nullptr) {
                PhysicsServices().SetPieceVisible(
                    *this, collisionParts[index], true);
            }
        }
        PhysicsServices().LinkMainClip(*this, true);
    }
}

// Retail: 0x82C00DE8 ??0idAnimPhysicsPiece@@QAA@XZ
idAnimPhysicsPiece::idAnimPhysicsPiece()
    : clipModel()
    , joint()
    , entity(nullptr)
    , isObstacle(false)
    , jointIndex()
    , presentable(nullptr) {
}

// Retail: 0x82C00E30 ?UpdateCollisionParts@idAnimatedSimplePhysics@@...
void idAnimatedSimplePhysics::UpdateCollisionParts(
        idBounds& bounds, const bool push) {
    bounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    bounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
    if (!SimpleServices().HasTreeAnimator(*this)) {
        return;
    }
    for (int index = 0; index < collisionParts.Num(); ++index) {
        idAnimPhysicsPiece& piece = collisionParts[index];
        if (piece.presentable == nullptr) {
            continue;
        }
        idVec3 origin(0.0f, 0.0f, 0.0f);
        idMat3 axis(1.0f);
        if (!PhysicsServices().GetPieceTransform(
                *this, piece, origin, axis)) {
            PhysicsServices().GetOwnerTransform(*this, origin, axis);
        }
        PhysicsServices().MoveCollisionPiece(
            *this, piece, origin, axis, push, crush, bounds);
    }
}

// Retail: 0x82C01300 ?Spawn@idAnimatedSimplePhysics@@QAAXXZ
void idAnimatedSimplePhysics::Spawn() {
    for (int index = 0; index < collisionParts.Num(); ++index) {
        idAnimPhysicsPiece& piece = collisionParts[index];
        piece.jointIndex = piece.joint.IsEmpty()
            ? idJointIndex()
            : PhysicsServices().ResolveJoint(*this, piece.joint.c_str());
        piece.presentable = PhysicsServices().CreatePresentable(*this, piece);
    }
    idBounds bounds;
    UpdateCollisionParts(bounds, false);
}

// Retail: 0x82C014A8 ?Think@idAnimatedSimplePhysics@@UAAXXZ
void idAnimatedSimplePhysics::Think() {
    idAnimatedSimple::Think();
    idBounds bounds;
    UpdateCollisionParts(bounds, true);
}

// Retail: 0x82C01558 ??0idAnimatedSimplePhysics@@QAA@XZ
idAnimatedSimplePhysics::idAnimatedSimplePhysics()
    : idAnimatedSimple()
    , crush(false)
    , collisionParts(16) {
}

// Retail: 0x82C01600 ??1idAnimatedSimplePhysics@@UAA@XZ
idAnimatedSimplePhysics::~idAnimatedSimplePhysics() {
    for (int index = 0; index < collisionParts.Num(); ++index) {
        if (collisionParts[index].presentable != nullptr) {
            PhysicsServices().DestroyPresentable(
                *this, collisionParts[index].presentable);
            collisionParts[index].presentable = nullptr;
        }
    }
}
