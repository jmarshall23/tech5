#include "gamelib/animstack/coneconstraint.h"

#include <cmath>

namespace {

idQuat Multiply(const idQuat& lhs, const idQuat& rhs) {
    return idQuat(
        lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y,
        lhs.w * rhs.y + lhs.y * rhs.w + lhs.z * rhs.x - lhs.x * rhs.z,
        lhs.w * rhs.z + lhs.z * rhs.w + lhs.x * rhs.y - lhs.y * rhs.x,
        lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z);
}

idVec3 ToForward(const idQuat& quaternion) {
    return idVec3(
        1.0f - 2.0f * (quaternion.y * quaternion.y
            + quaternion.z * quaternion.z),
        2.0f * (quaternion.x * quaternion.y
            - quaternion.w * quaternion.z),
        2.0f * (quaternion.w * quaternion.y
            + quaternion.x * quaternion.z));
}

idVec3 ConstrainDirection(
    const idVec3& center,
    const idVec3& direction,
    const float limitAngleDot,
    const float halfLimitAngleCosine,
    const float halfLimitAngleSine) {
    const float dot = center.Dot(direction);
    if (dot >= limitAngleDot) {
        return direction;
    }

    idVec3 tangent = direction - center * dot;
    if (tangent.NormalizeFast() == 0.0f) {
        return center;
    }

    const float sine = 2.0f * halfLimitAngleSine
        * halfLimitAngleCosine;
    return center * limitAngleDot + tangent * sine;
}

} // namespace

idConeConstraint_Vec3::idConeConstraint_Vec3(
    const idConeConstraint_Vec3& other) = default;

idConeConstraint_Quat::idConeConstraint_Quat(
    const idConeConstraint_Quat& other) = default;

idConeConstraint_Vec3::idConeConstraint_Vec3(
    const idVec3& center_,
    const radians_t maxAngle_)
    : current(center_)
    , center(center_)
    , limitAngleDot(std::cos(maxAngle_.value))
    , halfLimitAngleCosine(std::cos(maxAngle_.value * 0.5f))
    , halfLimitAngleSine(std::sin(maxAngle_.value * 0.5f)) {
}

void idConeConstraint_Vec3::RotateTo(
    const idVec3& dir,
    const float lerpRate) {
    const idVec3 target = ConstrainDirection(
        center,
        dir,
        limitAngleDot,
        halfLimitAngleCosine,
        halfLimitAngleSine);

    current = current + (target - current) * lerpRate;
    current.NormalizeFast();
}

idConeConstraint_Quat::idConeConstraint_Quat(
    const idQuat& center_,
    const radians_t maxAngle_)
    : current(center_)
    , center(center_)
    , limitAngleDot(std::cos(maxAngle_.value))
    , halfLimitAngleCosine(std::cos(maxAngle_.value * 0.5f))
    , halfLimitAngleSine(std::sin(maxAngle_.value * 0.5f)) {
}

void idConeConstraint_Quat::RotateTo(
    const idVec3& dir,
    const float lerpRate) {
    const idVec3 forward = ToForward(current);
    const float forwardDot = dir.Dot(forward);

    if (forwardDot > -1.0f && forwardDot < 1.0f) {
        idVec3 blendedForward = forward
            + (dir - forward) * (lerpRate * 0.5f);
        blendedForward.NormalizeFast();

        const float rotationDot = blendedForward.Dot(forward);
        const float rotationSine = rotationDot < 1.0f
            ? std::sqrt(1.0f - rotationDot * rotationDot)
            : 0.0f;
        idVec3 rotationAxis = blendedForward.Cross(forward);
        rotationAxis.NormalizeFast();

        const idQuat rotation(
            rotationAxis.x * rotationSine,
            rotationAxis.y * rotationSine,
            rotationAxis.z * rotationSine,
            rotationDot);
        current = Multiply(current, rotation);
        current.Normalize();
    }

    const idVec3 centerForward = ToForward(center);
    const idVec3 currentForward = ToForward(current);
    if (centerForward.Dot(currentForward) < limitAngleDot) {
        idVec3 rotationAxis = currentForward.Cross(centerForward);
        rotationAxis.NormalizeFast();

        const idQuat rotation(
            rotationAxis.x * halfLimitAngleSine,
            rotationAxis.y * halfLimitAngleSine,
            rotationAxis.z * halfLimitAngleSine,
            halfLimitAngleCosine);
        current = Multiply(center, rotation);
        current.Normalize();
    }
}
