#include "rotationtracker.h"

#include <algorithm>
#include <cmath>

namespace {

constexpr float kPi = 3.14159265358979323846f;
constexpr float kDegreesToRadians = kPi / 180.0f;
constexpr float kRadiansToDegrees = 180.0f / kPi;

float ClampUnit(const float value) {
    return (std::max)(-1.0f, (std::min)(1.0f, value));
}

idQuat Multiply(const idQuat& lhs, const idQuat& rhs) {
    return idQuat(
        lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y,
        lhs.w * rhs.y - lhs.x * rhs.z + lhs.y * rhs.w + lhs.z * rhs.x,
        lhs.w * rhs.z + lhs.x * rhs.y - lhs.y * rhs.x + lhs.z * rhs.w,
        lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z);
}

idQuat RotationFromForward(idVec3 forward) {
    if (forward.NormalizeFast() == 0.0f) {
        return idQuat(0.0f, 0.0f, 0.0f, 1.0f);
    }
    const idVec3 base(1.0f, 0.0f, 0.0f);
    const float dot = ClampUnit(base.Dot(forward));
    if (dot < -0.9999f) {
        return idQuat(0.0f, 0.0f, 1.0f, 0.0f);
    }
    const idVec3 cross = base.Cross(forward);
    idQuat result(cross.x, cross.y, cross.z, 1.0f + dot);
    result.Normalize();
    return result;
}

idVec3 ConstrainDirection(const idVec3& input,
        const idMat3& referenceAxis, const float maximumPitch,
        const float maximumYaw, const bool projectWhenBehind,
        bool& clampedPitch, bool& clampedYaw) {
    idVec3 direction = input;
    if (direction.NormalizeFast() == 0.0f) {
        direction = referenceAxis[0];
    }

    float localForward = direction.Dot(referenceAxis[0]);
    float localSide = direction.Dot(referenceAxis[1]);
    const float localUp = direction.Dot(referenceAxis[2]);
    if (projectWhenBehind && localForward < 0.0f) {
        localForward = 0.0f;
        if (std::fabs(localSide) < 1.0e-6f) {
            localSide = 1.0f;
        }
    }

    const float horizontalLength =
        std::sqrt(localForward * localForward + localSide * localSide);
    const float rawYaw = std::atan2(localSide, localForward);
    const float rawPitch = std::atan2(localUp, horizontalLength);
    const float yaw = (std::max)(-maximumYaw,
        (std::min)(maximumYaw, rawYaw));
    const float pitch = (std::max)(-maximumPitch,
        (std::min)(maximumPitch, rawPitch));
    clampedYaw = yaw != rawYaw;
    clampedPitch = pitch != rawPitch;

    const float cosPitch = std::cos(pitch);
    idVec3 result = referenceAxis[0] * (cosPitch * std::cos(yaw))
        + referenceAxis[1] * (cosPitch * std::sin(yaw))
        + referenceAxis[2] * std::sin(pitch);
    result.NormalizeFast();
    return result;
}

} // namespace

// Retail helper: ClampOnAxis, EA: 0x82B00900, RVA: 0x00B00900.
// The helper projects onto the rotation plane, identifies the limit, and
// produces the half-angle quaternion used by the two-axis clamp.
void ClampOnAxis(const idVec3& rotationAxis,
        const idVec3& referenceDirection, const idVec3& idealDirection,
        const float maximumDot, const float halfMaximumDot,
        idQuat& clampedRotation, float& currentDot, bool& wasClamped) {
    idVec3 projected = idealDirection
        - rotationAxis * idealDirection.Dot(rotationAxis);
    if (projected.NormalizeFast() == 0.0f) {
        clampedRotation = idQuat(0.0f, 0.0f, 0.0f, 1.0f);
        currentDot = 1.0f;
        wasClamped = false;
        return;
    }
    currentDot = ClampUnit(projected.Dot(referenceDirection));
    wasClamped = currentDot < maximumDot;
    const float halfDot = wasClamped
        ? halfMaximumDot
        : std::sqrt((std::max)(0.0f, (1.0f + currentDot) * 0.5f));
    idVec3 axis = referenceDirection.Cross(projected);
    if (axis.NormalizeFast() == 0.0f) {
        axis = rotationAxis;
    }
    const float sine = std::sqrt((std::max)(0.0f,
        1.0f - halfDot * halfDot));
    clampedRotation = idQuat(
        axis.x * sine, axis.y * sine, axis.z * sine, halfDot);
}

// Retail helper: ScaleForDot, EA: 0x82B00BD8, RVA: 0x00B00BD8.
float ScaleForDot(const float currentDot, const float maximumDot,
        const float minimumClamp) {
    const float range = 1.0f - maximumDot;
    const float distance = 1.0f - currentDot;
    if (distance >= range || std::fabs(range) <= 1.17549435e-38f) {
        return 0.0f;
    }
    return (std::max)(minimumClamp,
        (std::min)(1.0f, 1.0f - distance / range));
}

// Retail symbol: ??1idRotationTracker@@UAA@XZ
// EA: 0x82B00768, RVA: 0x00B00768
idRotationTracker::~idRotationTracker() = default;

// Retail symbol: ??0idRotationTracker@@QAA@XZ
// EA: 0x82B00778, RVA: 0x00B00778
idRotationTracker::idRotationTracker()
    : rot(0.0f, 0.0f, 0.0f, 1.0f)
    , maxPitch(kPi * 0.5f)
    , maxYaw(kPi * 0.5f)
    , maxPitchDot(0.0f)
    , maxYawDot(0.0f)
    , halfMaxPitchDot(std::cos(kPi * 0.25f))
    , halfMaxYawDot(std::cos(kPi * 0.25f))
    , maxVelocity(kPi * 8.0f)
    , velocity(0.0f)
    , acceleration(kPi * 8.0f)
    , deceleration(kPi * 8.0f)
    , projectWhenBehind(true)
    , clampedYaw(false)
    , clampedPitch(false) {
}

// Retail symbol:
// ?GetWorldSpaceDir@idRotationTracker@@QBAXABVidMat3@@AAVidVec3@@@Z
// EA: 0x82B00C48, RVA: 0x00B00C48
void idRotationTracker::GetWorldSpaceDir(
        const idMat3&, idVec3& result) const {
    result = rot.ToForward();
}

// Retail symbol:
// ?GetWorldSpaceAxis@idRotationTracker@@QBAXABVidMat3@@AAV2@@Z
// EA: 0x82B00C98, RVA: 0x00B00C98
void idRotationTracker::GetWorldSpaceAxis(
        const idMat3&, idMat3& result) const {
    result = rot.ToMat3();
}

// Retail symbol:
// ?GetConstraints@idRotationTracker@@QBAXAAVidRotationTrackerRange@@@Z
// EA: 0x82B00D18, RVA: 0x00B00D18
void idRotationTracker::GetConstraints(
        idRotationTrackerRange& range) const {
    range.minPitch = -maxPitch.value * kRadiansToDegrees;
    range.maxPitch = maxPitch.value * kRadiansToDegrees;
    range.minYaw = -maxYaw.value * kRadiansToDegrees;
    range.maxYaw = maxYaw.value * kRadiansToDegrees;
}

// Retail symbol:
// ?SetConstraints@idRotationTracker@@QAAXV?$idTypesafeNumber@MW4RadiansUnique_t@@@@0@Z
// EA: 0x82B00D70, RVA: 0x00B00D70
void idRotationTracker::SetConstraints(
        const radians_t newMaxPitch, const radians_t newMaxYaw) {
    maxPitch = newMaxPitch;
    maxYaw = newMaxYaw;
    maxPitchDot = std::cos(maxPitch.value);
    maxYawDot = std::cos(maxYaw.value);
    halfMaxPitchDot = std::cos(maxPitch.value * 0.5f);
    halfMaxYawDot = std::cos(maxYaw.value * 0.5f);
}

// Retail symbol:
// ?Update@idRotationTracker@@UAAXABVidVec3@@ABVidMat3@@0M_NH@Z
// EA: 0x82B00E08, RVA: 0x00B00E08
void idRotationTracker::Update(const idVec3& rotationOrigin,
        const idMat3& referenceAxis, const idVec3& idealDirection,
        const float deltaTime, const bool force, const int debugLevel) {
    const idVec3 desiredDirection = ConstrainDirection(idealDirection,
        referenceAxis, maxPitch.value, maxYaw.value, projectWhenBehind,
        clampedPitch, clampedYaw);
    if (force || deltaTime <= 0.0f) {
        rot = RotationFromForward(desiredDirection);
        velocity = 0.0f;
    } else {
        idVec3 currentDirection = rot.ToForward();
        currentDirection.NormalizeFast();
        const float angle = std::acos(ClampUnit(
            currentDirection.Dot(desiredDirection)));
        if (angle <= 1.0e-5f) {
            rot = RotationFromForward(desiredDirection);
            velocity = 0.0f;
        } else {
            const float decelerationValue =
                (std::max)(deceleration.value, 1.0e-6f);
            const float stoppingAngle = velocity.value * velocity.value
                / (2.0f * decelerationValue);
            if (angle <= stoppingAngle) {
                velocity.value = (std::max)(0.0f,
                    velocity.value - deceleration.value * deltaTime);
            } else {
                velocity.value = (std::min)(maxVelocity.value,
                    velocity.value + acceleration.value * deltaTime);
            }
            const float step = (std::min)(angle,
                velocity.value * deltaTime);
            idVec3 turnAxis = currentDirection.Cross(desiredDirection);
            if (turnAxis.NormalizeFast() > 0.0f) {
                const float halfStep = step * 0.5f;
                const float sine = std::sin(halfStep);
                const idQuat increment(turnAxis.x * sine,
                    turnAxis.y * sine, turnAxis.z * sine,
                    std::cos(halfStep));
                rot = Multiply(increment, rot);
                rot.Normalize();
            } else {
                rot = RotationFromForward(desiredDirection);
            }
        }
    }
    if (debugLevel > 0) {
        Tungsten_DebugRotationTracker(*this, rotationOrigin,
            desiredDirection, rot.ToForward(), debugLevel);
    }
}

idAimTracker::idAimTracker()
    : idRotationTracker()
    , curParms{} {
}

// Retail symbol:
// ?Update@idAimTracker@@UAAXABVidVec3@@ABVidMat3@@0M_NH@Z
// EA: 0x82B01D58, RVA: 0x00B01D58
void idAimTracker::Update(const idVec3& rotationOrigin,
        const idMat3& referenceAxis, const idVec3& idealDirection,
        const float deltaTime, const bool force, const int debugLevel) {
    maxVelocity.value = curParms.rate.value * kDegreesToRadians;
    acceleration.value = curParms.acceleration.value * kDegreesToRadians;
    deceleration.value = curParms.deceleration.value * kDegreesToRadians;
    idRotationTracker::Update(rotationOrigin, referenceAxis,
        idealDirection, deltaTime, force, debugLevel);
}

// Retail symbol:
// ?SetConstraints@idRotationTracker@@QAAXABVidRotationTrackerRange@@@Z
// EA: 0x82B01D90, RVA: 0x00B01D90
void idRotationTracker::SetConstraints(
        const idRotationTrackerRange& range) {
    const float pitch = (std::max)(std::fabs(range.minPitch),
        std::fabs(range.maxPitch));
    const float yaw = (std::max)(std::fabs(range.minYaw),
        std::fabs(range.maxYaw));
    SetConstraints(radians_t(pitch * kDegreesToRadians),
        radians_t(yaw * kDegreesToRadians));
}
