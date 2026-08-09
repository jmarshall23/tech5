#include "gamelib/effectphysics/effectphysicsproperties.h"

#include <algorithm>

idEffectPhysicsProperties::idEffectPhysicsProperties()
    : broadPhase(nullptr)
    , traceModelIndex(-1)
    , mass(1.0f) {
}

void idEffectPhysicsProperties::Setup(
        idEffectPhysicsBroadPhase *broadPhase_, const int traceModelIndex_,
        const float requestedMass) {
    linearFriction = 0.60000002f;
    angularFriction = 0.60000002f;
    contactFriction = 0.5f;
    linearFrictionWater = 1.0f;
    angularFrictionWater = 1.0f;
    bouncyness = 0.60000002f;
    clipMask = 1;
    gravityVector.Set(0.0f, 0.0f, -250.0f);
    worldCollisionOnly = false;
    simplePointCollision = false;
    crazyBounceChance = 0.0f;
    inverseMass = 1.0f;
    centerOfMass.Zero();
    inertiaTensor = idMat3(1.0f);
    inverseInertiaTensor = idMat3(1.0f);
    maxLinearVelocity = 5000.0f;
    stopSpeed = 10.0f;
    maxAngularVelocity = 3.1415927f * 4.0f;
    traceModelIndex = traceModelIndex_;
    broadPhase = broadPhase_;

    mass = 0.0f;
    if (broadPhase != nullptr && broadPhase->traceModelCache != nullptr) {
        broadPhase->traceModelCache->GetMassProperties(traceModelIndex, 1.0f,
            mass, centerOfMass, inertiaTensor);
    }
    if (mass <= 0.0f) {
        mass = 1.0f;
        centerOfMass.Zero();
        inertiaTensor = idMat3(1.0f);
    }

    const float massScale = requestedMass / mass;
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            inertiaTensor[row][column] *= massScale;
        }
    }
    mass = requestedMass;

    const float diagonal[3] = {
        inertiaTensor[0][0], inertiaTensor[1][1], inertiaTensor[2][2]
    };
    int minimumAxis = 0;
    if (diagonal[1] < diagonal[minimumAxis]) {
        minimumAxis = 1;
    }
    if (diagonal[2] < diagonal[minimumAxis]) {
        minimumAxis = 2;
    }

    if (diagonal[minimumAxis] > 0.0f) {
        idMat3 inertiaScale(1.0f);
        for (int axis = 0; axis < 3; ++axis) {
            inertiaScale[axis][axis] = diagonal[axis]
                / diagonal[minimumAxis];
        }
        if (inertiaScale[0][0] > 4.0f || inertiaScale[1][1] > 4.0f
                || inertiaScale[2][2] > 4.0f) {
            for (int axis = 0; axis < 3; ++axis) {
                if (axis != minimumAxis && diagonal[axis] != 0.0f) {
                    inertiaScale[axis][axis] = diagonal[minimumAxis] * 4.0f
                        / diagonal[axis];
                }
            }
            inertiaTensor *= inertiaScale;
        }
    }

    inverseMass = mass != 0.0f ? 1.0f / mass : 1.0f;
    inverseInertiaTensor = inertiaTensor;
    if (!inverseInertiaTensor.InverseSelf()) {
        inverseInertiaTensor = idMat3(1.0f);
    }
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            inverseInertiaTensor[row][column] *= 1.0f / 6.0f;
        }
    }
}
