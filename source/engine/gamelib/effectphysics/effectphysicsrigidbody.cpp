#include "gamelib/effectphysics/effectphysicsrigidbody.h"

#include "cm/jobs/collisionresults.h"
#include "gamelib/physics/physics.h"

#include <algorithm>
#include <cmath>

namespace {

constexpr float kRadToDeg = 57.29577951308232f;
constexpr float kVelocityEpsilon = 1.0e-8f;

idMat3 WorldInverseInertia(const idMat3& orientation,
    const idMat3& inverseInertiaTensor) {
    return orientation * inverseInertiaTensor * orientation.Transpose();
}

idVec3 PointVelocity(const idEffectPhysicsRigidBody::effectRBState_t& state,
    const idEffectPhysicsProperties& properties, const idVec3& point) {
    const idVec3 linearVelocity =
        state.linearMomentum * properties.inverseMass;
    const idVec3 angularVelocity =
        WorldInverseInertia(state.orientation,
            properties.inverseInertiaTensor) * state.angularMomentum;
    return linearVelocity + angularVelocity.Cross(point - state.position);
}

} // namespace

idEffectPhysicsRigidBody::idEffectPhysicsRigidBody()
    : properties(nullptr)
    , currentState{}
    , SPObject()
    , active(false)
    , settled(false) {
}

idEffectPhysicsRigidBody::~idEffectPhysicsRigidBody() {
    if (properties != nullptr && properties->broadPhase != nullptr) {
        properties->broadPhase->RemoveObject(&SPObject);
    }
    properties = nullptr;
    active = false;
}

void idEffectPhysicsRigidBody::Setup(
    const idEffectPhysicsProperties* const props) {
    if (properties != nullptr && properties->broadPhase != nullptr) {
        properties->broadPhase->RemoveObject(&SPObject);
    }

    properties = props;
    currentState.position.Zero();
    currentState.orientation = idMat3(1.0f);
    currentState.linearMomentum.Zero();
    currentState.angularMomentum.Zero();
    currentState.externalForce.Zero();
    currentState.externalTorque.Zero();
    active = false;
    settled = false;

    if (props == nullptr) {
        SPObject.traceModelIndex = -1;
        return;
    }
    SPObject.traceModelIndex = props->traceModelIndex;
    SPObject.motion.worldCollisionOnly = props->worldCollisionOnly;
    SPObject.clipMask = props->clipMask;
    if (props->broadPhase != nullptr) {
        props->broadPhase->AddObject(&SPObject, currentState.position,
            currentState.orientation, nullptr);
    }
}

void idEffectPhysicsRigidBody::CapVelocity(
    const float deltaTime, effectRBState_t& current) const {
    (void)deltaTime;
    if (properties == nullptr) {
        return;
    }

    const idVec3 linearVelocity =
        current.linearMomentum * properties->inverseMass;
    const float linearSpeed = linearVelocity.Length();
    if (properties->maxLinearVelocity > 0.0f &&
        linearSpeed > properties->maxLinearVelocity) {
        current.linearMomentum = current.linearMomentum *
            (properties->maxLinearVelocity / linearSpeed);
    }

    const idVec3 angularVelocity =
        WorldInverseInertia(current.orientation,
            properties->inverseInertiaTensor) * current.angularMomentum;
    const float angularSpeed = angularVelocity.Length();
    if (properties->maxAngularVelocity > 0.0f &&
        angularSpeed > properties->maxAngularVelocity) {
        current.angularMomentum = current.angularMomentum *
            (properties->maxAngularVelocity / angularSpeed);
    }
}

void idEffectPhysicsRigidBody::CollisionImpulse(trace_t& collision,
    const impactInfo_t& impact, const float extraMomentumDecay,
    effectRBState_t& state, idVec3& normalVelocity, idVec3& impulse) const {
    normalVelocity.Zero();
    impulse.Zero();
    if (properties == nullptr) {
        return;
    }

    idVec3 normal = collision.c.normal;
    if (normal.NormalizeFast() <= kVelocityEpsilon) {
        return;
    }

    const idVec3 bodyVelocity =
        PointVelocity(state, *properties, collision.c.point);
    const idVec3 relativeVelocity = bodyVelocity - impact.velocity;
    const float velocityIntoSurface = relativeVelocity.Dot(normal);
    normalVelocity = normal * velocityIntoSurface;
    if (velocityIntoSurface >= 0.0f) {
        return;
    }

    const idVec3 arm = collision.c.point - state.position;
    const idVec3 cross = arm.Cross(normal);
    const idVec3 inertiaCross =
        WorldInverseInertia(state.orientation,
            properties->inverseInertiaTensor) * cross;
    const float denominator = properties->inverseMass + impact.invMass +
        normal.Dot(inertiaCross.Cross(arm));
    if (denominator <= kVelocityEpsilon) {
        return;
    }

    const float restitution = (std::max)(0.0f, properties->bouncyness);
    float magnitude = -(1.0f + restitution) * velocityIntoSurface /
        denominator;
    magnitude *= (std::max)(0.0f, 1.0f - extraMomentumDecay);
    impulse = normal * magnitude;

    // The recovered path applies Coulomb contact friction after the normal
    // impulse.  Preserve that behavior without the original VMX shortcuts.
    idVec3 tangent = relativeVelocity - normal * velocityIntoSurface;
    const float tangentSpeed = tangent.NormalizeFast();
    if (tangentSpeed > kVelocityEpsilon && properties->contactFriction > 0.0f) {
        const float frictionMagnitude = (std::min)(
            tangentSpeed / (properties->inverseMass + impact.invMass +
                kVelocityEpsilon),
            magnitude * properties->contactFriction);
        impulse = impulse - tangent * frictionMagnitude;
    }

    state.linearMomentum = state.linearMomentum + impulse;
    state.angularMomentum = state.angularMomentum + arm.Cross(impulse);
}

void idEffectPhysicsRigidBody::ApplyImpulse(const idVec3& point,
    const idVec3& impulse) {
    settled = false;
    currentState.linearMomentum = currentState.linearMomentum + impulse;
    // The Xbox dump spells this as impulse x (point-position), which is the
    // negative of the conventional r x J ordering.
    currentState.angularMomentum = currentState.angularMomentum +
        impulse.Cross(point - currentState.position);
}

void idEffectPhysicsRigidBody::Evolve(const float deltaTime,
    const effectRBState_t& current, effectRBDelta_t& delta) const {
    delta.translation.Zero();
    delta.rotation = idRotation();
    delta.linearForce.Zero();
    delta.angularForce.Zero();
    if (properties == nullptr) {
        return;
    }

    const idVec3 linearVelocity =
        current.linearMomentum * properties->inverseMass;
    const idVec3 angularVelocity =
        WorldInverseInertia(current.orientation,
            properties->inverseInertiaTensor) * current.angularMomentum;

    delta.translation = linearVelocity * deltaTime;
    idVec3 rotationAxis = angularVelocity;
    const float angularSpeed = rotationAxis.NormalizeFast();
    if (angularSpeed <= kVelocityEpsilon) {
        rotationAxis.Set(0.0f, 0.0f, 1.0f);
    }
    delta.rotation = idRotation(current.position, rotationAxis,
        -angularSpeed * deltaTime * kRadToDeg);

    const idVec3 totalForce = current.externalForce +
        properties->gravityVector * properties->mass -
        linearVelocity * properties->linearFriction;
    const idVec3 totalTorque = current.externalTorque -
        angularVelocity * properties->angularFriction;
    delta.linearForce = totalForce * deltaTime;
    delta.angularForce = totalTorque * deltaTime;
}

void idEffectPhysicsRigidBody::Update(const float deltaTime,
    const float extraMomentumDecay, idEffectPhysicsCollision& collision) {
    collision.Clear();
    if (!active || settled || properties == nullptr ||
        properties->broadPhase == nullptr || deltaTime <= 0.0f) {
        return;
    }

    bool testForSettling = false;
    trace_t trace{};
    if (SPObject.query.offset != 0 &&
        properties->broadPhase->GetMotionResult(&trace, &SPObject)) {
        currentState.position = SPObject.origin;
        currentState.orientation = SPObject.axis;
        if (trace.fraction < 1.0f) {
            impactInfo_t impact{};
            impact.invInertiaTensor = idMat3(1.0f);
            idVec3 impulse;
            CollisionImpulse(trace, impact, extraMomentumDecay,
                currentState, collision.collisionNormalVelocity, impulse);
            collision.collisionPoint = trace.c.point;
            collision.collisionSurfaceType = trace.c.surfaceType;

            const float horizontalSpeed = std::sqrt(
                currentState.linearMomentum.x * currentState.linearMomentum.x +
                currentState.linearMomentum.y * currentState.linearMomentum.y);
            if (horizontalSpeed <= 10.0f &&
                currentState.linearMomentum.z < 0.0f) {
                testForSettling = horizontalSpeed >= 2.0f;
                settled = horizontalSpeed < 2.0f;
            }
        }
    }

    CapVelocity(deltaTime, currentState);
    effectRBDelta_t delta;
    Evolve(deltaTime, currentState, delta);
    properties->broadPhase->ApplyMotion(
        &SPObject, delta.translation, delta.rotation);

    if (testForSettling &&
        delta.translation.x * delta.translation.x +
            delta.translation.y * delta.translation.y < 1.0e-4f) {
        settled = true;
    }

    if (settled) {
        SPObject.motion.valid = false;
        currentState.linearMomentum.Zero();
        currentState.angularMomentum.Zero();
        collision.Clear();
    } else {
        currentState.linearMomentum =
            currentState.linearMomentum + delta.linearForce;
        currentState.angularMomentum =
            currentState.angularMomentum + delta.angularForce;
    }
    currentState.externalForce.Zero();
    currentState.externalTorque.Zero();
}
