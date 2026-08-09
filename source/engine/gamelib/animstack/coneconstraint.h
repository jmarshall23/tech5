#pragma once

#include "idlib/math/quat.h"
#include "idlib/math/radians.h"

// Reconstructed from the recovered coneconstraint.h declarations and the
// six authoritative functions in animstack/coneconstraint.cpp.
class idConeConstraint_Quat {
public:
    idConeConstraint_Quat(const idConeConstraint_Quat& other);
    idConeConstraint_Quat(const idQuat& center_, radians_t maxAngle_);

    void RotateTo(const idVec3& dir, float lerpRate);

    idQuat current;
    idQuat center;
    float limitAngleDot;
    float halfLimitAngleCosine;
    float halfLimitAngleSine;
};

class idConeConstraint_Vec3 {
public:
    idConeConstraint_Vec3(const idConeConstraint_Vec3& other);
    idConeConstraint_Vec3(const idVec3& center_, radians_t maxAngle_);

    void RotateTo(const idVec3& dir, float lerpRate);

    idVec3 current;
    idVec3 center;
    float limitAngleDot;
    float halfLimitAngleCosine;
    float halfLimitAngleSine;
};

// The matrix form has declaration/layout evidence but no materialized methods
// in this translation unit.
class idConeConstraint_Mat3 {
public:
    idMat3 current;
    idMat3 center;
    float limitAngleDot;
    float halfLimitAngleCosine;
    float halfLimitAngleSine;
};

// The fourth recovered logical type is a test entity derived from idEntity.
// Its full base-class boundary belongs to the later game-entity recovery, so
// retain the real owner name without inventing a substitute base class here.
class idTest_ConeConstraint;

static_assert(sizeof(idConeConstraint_Quat) == 44,
    "Recovered idConeConstraint_Quat ABI changed");
static_assert(sizeof(idConeConstraint_Vec3) == 36,
    "Recovered idConeConstraint_Vec3 ABI changed");
static_assert(sizeof(idConeConstraint_Mat3) == 84,
    "Recovered idConeConstraint_Mat3 ABI changed");
