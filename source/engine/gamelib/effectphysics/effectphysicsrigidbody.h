#pragma once

#include "gamelib/effectphysics/effectphysicsproperties.h"
#include "idlib/math/rotation.h"

struct impactInfo_t;
struct trace_t;

// Recovered type 14579.  This record is intentionally independent of the
// renderer/game declaration layer so effect physics can be used by emitters.
struct idEffectPhysicsCollision {
    idVec3 collisionPoint;
    idVec3 collisionNormalVelocity;
    int collisionSurfaceType;

    void Clear() {
        collisionPoint.Zero();
        collisionNormalVelocity.Zero();
        collisionSurfaceType = 0;
    }
};

class alignas(8) idEffectPhysicsRigidBody {
public:
    struct effectRBState_t {
        idVec3 position;
        idMat3 orientation;
        idVec3 linearMomentum;
        idVec3 angularMomentum;
        idVec3 externalForce;
        idVec3 externalTorque;
    };

    struct effectRBDelta_t {
        idVec3 translation;
        idRotation rotation;
        idVec3 linearForce;
        idVec3 angularForce;
    };

    idEffectPhysicsRigidBody();
    ~idEffectPhysicsRigidBody();

    void Setup(const idEffectPhysicsProperties* props);
    void ApplyImpulse(const idVec3& point, const idVec3& impulse);
    void Update(float deltaTime, float extraMomentumDecay,
        idEffectPhysicsCollision& collision);

    void SetPosition(const idVec3& position, const idMat3& orientation) {
        currentState.position = position;
        currentState.orientation = orientation;
        if (properties != nullptr && properties->broadPhase != nullptr) {
            properties->broadPhase->SetObjectPosition(
                &SPObject, position, orientation, nullptr);
        }
    }
    void SetLinearMomentum(const idVec3& momentum) {
        currentState.linearMomentum = momentum;
    }
    void SetAngularMomentum(const idVec3& momentum) {
        currentState.angularMomentum = momentum;
    }
    void AddForce(const idVec3& force) {
        currentState.externalForce = currentState.externalForce + force;
    }
    void AddTorque(const idVec3& torque) {
        currentState.externalTorque = currentState.externalTorque + torque;
    }
    void Activate() { active = true; settled = false; }
    void PutToRest() { settled = true; SPObject.motion.valid = false; }

    const idEffectPhysicsProperties* properties;
    effectRBState_t currentState;
    idSPObject SPObject;
    bool active;
    bool settled;

private:
    void CapVelocity(float deltaTime, effectRBState_t& current) const;
    void CollisionImpulse(trace_t& collision, const impactInfo_t& impact,
        float extraMomentumDecay, effectRBState_t& state,
        idVec3& normalVelocity, idVec3& impulse) const;
    void Evolve(float deltaTime, const effectRBState_t& current,
        effectRBDelta_t& delta) const;
};

static_assert(sizeof(idEffectPhysicsCollision) == 28,
    "Recovered idEffectPhysicsCollision ABI changed");
static_assert(sizeof(idEffectPhysicsRigidBody::effectRBState_t) == 96,
    "Recovered effectRBState_t ABI changed");
static_assert(sizeof(idEffectPhysicsRigidBody::effectRBDelta_t) == 104,
    "Recovered effectRBDelta_t ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idEffectPhysicsRigidBody) == 272,
    "Recovered idEffectPhysicsRigidBody ABI changed");
#endif
