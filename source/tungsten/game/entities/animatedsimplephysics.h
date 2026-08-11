#pragma once

#include "game/entities/animatedsimple.h"

struct idAnimPhysicsPiece {
    idAnimPhysicsPiece();

    idStr clipModel;
    idStr joint;
    idEntity* entity;
    bool isObstacle;
    idJointIndex jointIndex;
    void* presentable;
};

class idAnimatedSimplePhysics;

class idAnimatedSimplePhysicsServices {
public:
    virtual ~idAnimatedSimplePhysicsServices() = default;
    virtual bool UseRelaxedChatter(
        const idAnimatedSimplePhysics&) const { return false; }
    virtual void SetPhysicsThinkActive(
        idAnimatedSimplePhysics&, bool) {}
    virtual void SetPieceVisible(
        idAnimatedSimplePhysics&, idAnimPhysicsPiece&, bool) {}
    virtual void LinkMainClip(idAnimatedSimplePhysics&, bool) {}
    virtual idJointIndex ResolveJoint(
        const idAnimatedSimplePhysics&, const char*) const { return {}; }
    virtual void* CreatePresentable(
        idAnimatedSimplePhysics&, idAnimPhysicsPiece&) { return nullptr; }
    virtual void DestroyPresentable(
        idAnimatedSimplePhysics&, void*) {}
    virtual bool GetPieceTransform(const idAnimatedSimplePhysics&,
        const idAnimPhysicsPiece&, idVec3&, idMat3&) const { return false; }
    virtual void GetOwnerTransform(const idAnimatedSimplePhysics&,
        idVec3& origin, idMat3& axis) const {
        origin.Zero(); axis = idMat3(1.0f);
    }
    virtual void MoveCollisionPiece(idAnimatedSimplePhysics&,
        idAnimPhysicsPiece&, const idVec3&, const idMat3&,
        bool, bool, idBounds&) {}
};

class idAnimatedSimplePhysics : public idAnimatedSimple {
public:
    idAnimatedSimplePhysics();
    ~idAnimatedSimplePhysics() override;

    static void SetPhysicsServices(
        idAnimatedSimplePhysicsServices* services);
    static idAnimatedSimplePhysicsServices& PhysicsServices();

    void Hide() override;
    void Show() override;
    void UpdateCollisionParts(idBounds& bounds, bool push);
    void Spawn();
    void Think() override;

    bool crush;
    idList<idAnimPhysicsPiece, 5> collisionParts;
};
