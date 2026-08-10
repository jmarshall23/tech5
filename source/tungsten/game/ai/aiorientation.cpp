#include "aiorientation.h"

#include <algorithm>
#include <cmath>

namespace {

constexpr float kDefaultTolerance = 0.99984771f;
constexpr float kDirectionLengthSqrMinimum = 0.001f;
constexpr float kTimeMinimum = 0.0001f;
constexpr float kSmallestNonDenormal = 1.17549435e-38f;
constexpr float kRadiansToDegrees = 57.29577951308232f;
constexpr float kDegreesToRadians = 0.017453292519943295f;

float ClampUnit(const float value) {
    return (std::max)(-1.0f, (std::min)(1.0f, value));
}

idVec3 ProjectOntoPlane(const idVec3& vector, const idVec3& normal) {
    return vector - normal * vector.Dot(normal);
}

idVec3 NormalizedProjection(
        const idVec3& vector, const idVec3& normal) {
    idVec3 projected = ProjectOntoPlane(vector, normal);
    projected.NormalizeFast();
    return projected;
}

idVec3 RotateAroundUp(const idVec3& vector,
        const idVec3& gravityDirection, const float degrees) {
    idVec3 up = -gravityDirection;
    if (up.NormalizeFast() == 0.0f) {
        return vector;
    }
    const float radians = degrees * kDegreesToRadians;
    const float sine = std::sin(radians);
    const float cosine = std::cos(radians);
    return vector * cosine + up.Cross(vector) * sine
        + up * (up.Dot(vector) * (1.0f - cosine));
}

void FixDenormals(idMat3& matrix) {
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            if (std::fabs(matrix[row][column]) <= kSmallestNonDenormal) {
                matrix[row][column] = 0.0f;
            }
        }
    }
}

void RotateOrientation(idMat3& orientation,
        const idVec3& gravityDirection, const float degrees,
        const bool normalize) {
    for (int axisIndex = 0; axisIndex < 3; ++axisIndex) {
        orientation[axisIndex] = RotateAroundUp(
            orientation[axisIndex], gravityDirection, degrees);
    }
    FixDenormals(orientation);
    if (normalize) {
        orientation.OrthoNormalizeSelf();
    }
}

turnDirection_t DirectionForSign(const float sign) {
    return sign > 0.0f ? TURN_LEFT : TURN_RIGHT;
}

} // namespace

// Retail symbol: ?UpdateStatic@idAIOrientation@@QAAXXZ
// EA: 0x82A5EA88, RVA: 0x00A5EA88
void idAIOrientation::UpdateStatic() {
    previousTurnDir = currentTurnDir;
    currentTurnDir = TURN_NONE;
}

// Retail symbol: ??0idAIOrientation@@QAA@MM@Z
// EA: 0x82A5EAA0, RVA: 0x00A5EAA0
idAIOrientation::idAIOrientation(
        const float minimumTurnRate, const float maximumTurnRate)
    : idealDir(1.0f, 0.0f, 0.0f)
    , axis(1.0f)
    , lastTurnDelta(0.0f)
    , lastTurnRate(0.0f)
    , tolerance(kDefaultTolerance)
    , currentTurnDir(TURN_NONE)
    , previousTurnDir(TURN_NONE)
    , turnVelocity(0.0f) {
    (void)minimumTurnRate;
    (void)maximumTurnRate;
}

// Retail symbol: ?Init@idAIOrientation@@QAAXABVidMat3@@@Z
// EA: 0x82A5EB08, RVA: 0x00A5EB08
void idAIOrientation::Init(const idMat3& initialAxis) {
    axis = initialAxis;
    idealDir = axis[0];
    currentTurnDir = TURN_NONE;
    previousTurnDir = TURN_NONE;
    lastTurnRate = 0.0f;
    lastTurnDelta = 0.0f;
    turnVelocity = 0.0f;
}

// Retail symbol: ?SetIdealDir@idAIOrientation@@QAAXPAVidAI2@@ABVidVec3@@@Z
// EA: 0x82A5EB90, RVA: 0x00A5EB90
void idAIOrientation::SetIdealDir(
        idAI2* ai, const idVec3& direction) {
    if (ai == nullptr) {
        return;
    }
    idVec3 origin;
    idVec3 gravityNormal;
    if (!Tungsten_GetAIOrientationPhysics(*ai, origin, gravityNormal)) {
        return;
    }

    idVec3 projected = ProjectOntoPlane(direction, gravityNormal);
    for (int component = 0; component < 3; ++component) {
        if (std::fabs(projected[component]) <= kSmallestNonDenormal) {
            projected[component] = 0.0f;
        }
    }
    if (projected.LengthSqr() > kDirectionLengthSqrMinimum) {
        projected.NormalizeFast();
        idealDir = projected;
    }
}

// Retail symbol: ?SetIdealDirTowards@idAIOrientation@@QAAXPAVidAI2@@ABVidVec3@@@Z
// EA: 0x82A5ECD8, RVA: 0x00A5ECD8
void idAIOrientation::SetIdealDirTowards(
        idAI2* ai, const idVec3& point) {
    if (ai == nullptr) {
        return;
    }
    idVec3 origin;
    idVec3 gravityNormal;
    if (!Tungsten_GetAIOrientationPhysics(*ai, origin, gravityNormal)) {
        return;
    }
    SetIdealDir(ai, point - origin);
}

// Retail symbol: ?UpdateFromAnim@idAIOrientation@@QAAXABVidMat3@@MW4turnDirection_t@@_N@Z
// EA: 0x82A5ED58, RVA: 0x00A5ED58
void idAIOrientation::UpdateFromAnim(const idMat3& newAxis,
        const float turnRate, const turnDirection_t turnDirection,
        const bool updateIdealDirection) {
    previousTurnDir = currentTurnDir;
    currentTurnDir = static_cast<unsigned char>(turnDirection);
    lastTurnRate = turnRate;
    lastTurnDelta = 0.0f;
    axis = newAxis;
    if (updateIdealDirection) {
        idealDir = axis[0];
    }
}

// Retail symbol: ?CalculateTurnDirection@idAIOrientation@@QBA?AW4turnDirection_t@@ABVidVec3@@@Z
// EA: 0x82A5EDE8, RVA: 0x00A5EDE8
turnDirection_t idAIOrientation::CalculateTurnDirection(
        const idVec3& normal) const {
    const idVec3 forward = NormalizedProjection(axis[0], normal);
    idVec3 tangent = forward.Cross(normal);
    tangent.NormalizeFast();
    return idealDir.Dot(tangent) < 0.0f ? TURN_RIGHT : TURN_LEFT;
}

// Retail symbol: ?CalcTurnRateForTime@idAIOrientation@@QBAMABVidVec3@@0M@Z
// EA: 0x82A5EF70, RVA: 0x00A5EF70
float idAIOrientation::CalcTurnRateForTime(const idVec3& rotationAxis,
        const idVec3& destinationDirection, const float timeSeconds) const {
    if (timeSeconds < kTimeMinimum) {
        return 0.0f;
    }
    const idVec3 destination =
        NormalizedProjection(destinationDirection, rotationAxis);
    const float angle = std::acos(ClampUnit(axis[0].Dot(destination)))
        * kRadiansToDegrees;
    return angle / timeSeconds;
}

// Retail symbol: ?IsAligned@idAIOrientation@@QBA_NXZ
// EA: 0x82A5F088, RVA: 0x00A5F088
bool idAIOrientation::IsAligned() const {
    return axis[0].Dot(idealDir) > tolerance;
}

// Retail symbol: ?IsAligned@idAIOrientation@@QBA_NABVidVec3@@M@Z
// EA: 0x82A5F0C8, RVA: 0x00A5F0C8
bool idAIOrientation::IsAligned(
        const idVec3& testIdeal, const float degrees) const {
    return axis[0].Dot(testIdeal) > std::cos(degrees * kDegreesToRadians);
}

// Retail symbol: ?SetAxis@idAIOrientation@@QAAXABVidVec3@@0@Z
// EA: 0x82A5F138, RVA: 0x00A5F138
void idAIOrientation::SetAxis(
        const idVec3& direction, const idVec3& gravityDirection) {
    axis[0] = direction;
    axis[2] = -gravityDirection;
    axis[1] = axis[2].Cross(axis[0]);
    axis.OrthoNormalizeSelf();
}

// Retail symbol: ?SetAxis@idAIOrientation@@QAAXABVidMat3@@@Z
// EA: 0x82A5F1C8, RVA: 0x00A5F1C8
void idAIOrientation::SetAxis(const idMat3& newAxis) {
    axis = newAxis;
}

// Retail symbol: ?UpdateAxis@idAIOrientation@@QAA?AW4turnDirection_t@@ABVidVec3@@MM@Z
// EA: 0x82A5F218, RVA: 0x00A5F218
turnDirection_t idAIOrientation::UpdateAxis(const idVec3& normal,
        const float turnRate, const float timeSeconds) {
    previousTurnDir = currentTurnDir;
    currentTurnDir = TURN_NONE;

    const idVec3 forward = NormalizedProjection(axis[0], normal);
    const float alignment = idealDir.Dot(forward);
    lastTurnDelta = alignment;
    if (alignment <= tolerance) {
        idVec3 tangent = forward.Cross(normal);
        tangent.NormalizeFast();
        const float sign = idealDir.Dot(tangent) >= 0.0f ? 1.0f : -1.0f;
        const float remainingAngle =
            std::acos(ClampUnit(alignment)) * kRadiansToDegrees;
        const float turnAngle = (std::min)(remainingAngle,
            turnRate * timeSeconds);
        RotateOrientation(axis, normal, turnAngle * sign, true);
        lastTurnRate = turnRate;
        turnVelocity = 0.0f;
        currentTurnDir = static_cast<unsigned char>(DirectionForSign(sign));
    } else {
        if (tolerance >= kDefaultTolerance) {
            SetAxis(idealDir, normal);
        }
        lastTurnRate = 0.0f;
        lastTurnDelta = 0.0f;
    }
    return static_cast<turnDirection_t>(currentTurnDir);
}

// Retail symbol: ?UpdateBodyAxis@idAIOrientation@@QAA?AW4turnDirection_t@@ABVidVec3@@W42@MM@Z
// EA: 0x82A5F4F8, RVA: 0x00A5F4F8
turnDirection_t idAIOrientation::UpdateBodyAxis(const idVec3& normal,
        const turnDirection_t turnDirection, const float turnRate,
        const float timeSeconds) {
    previousTurnDir = currentTurnDir;
    currentTurnDir = TURN_NONE;

    const idVec3 forward = NormalizedProjection(axis[0], normal);
    const float alignment = idealDir.Dot(forward);
    lastTurnDelta = alignment;
    if (alignment <= tolerance) {
        const float sign = turnDirection == TURN_LEFT ? 1.0f : -1.0f;
        const float remainingAngle =
            std::acos(ClampUnit(alignment)) * kRadiansToDegrees;
        const float turnAngle = (std::min)(remainingAngle,
            turnRate * timeSeconds);
        RotateOrientation(axis, normal, turnAngle * sign, true);
        lastTurnRate = turnRate;
        currentTurnDir = static_cast<unsigned char>(DirectionForSign(sign));
    } else {
        if (tolerance >= kDefaultTolerance) {
            SetAxis(idealDir, normal);
        }
        lastTurnRate = 0.0f;
        lastTurnDelta = 0.0f;
    }
    return static_cast<turnDirection_t>(currentTurnDir);
}

// Retail symbol: ?Update@idAIOrientation@@QAAXABVidVec3@@000MMM@Z
// EA: 0x82A5F768, RVA: 0x00A5F768
void idAIOrientation::Update(const idVec3& velocity,
        const idVec3& origin, const idVec3& destination,
        const idVec3& gravityDirection, const float turnRate,
        const float maximumTurnRate, const float timeSeconds) {
    (void)maximumTurnRate;
    previousTurnDir = currentTurnDir;

    const idVec3 forward = NormalizedProjection(axis[0], gravityDirection);
    const float alignment = idealDir.Dot(forward);
    if (alignment <= tolerance) {
        idVec3 tangent = forward.Cross(gravityDirection);
        tangent.NormalizeFast();
        const float sign = idealDir.Dot(tangent) >= 0.0f ? 1.0f : -1.0f;
        const float remainingAngle =
            std::acos(ClampUnit(alignment)) * kRadiansToDegrees;
        const float desiredTurnTime = remainingAngle / turnRate;
        const float speed = velocity.Length();
        const float arrivalTime = speed > kSmallestNonDenormal
            ? ProjectOntoPlane(destination - origin, gravityDirection).Length()
                / speed
            : 9999.0f;

        if (desiredTurnTime <= arrivalTime) {
            lastTurnRate = turnRate;
        } else if (arrivalTime > kSmallestNonDenormal) {
            lastTurnRate = remainingAngle / arrivalTime;
        } else if (timeSeconds < kSmallestNonDenormal) {
            lastTurnRate = remainingAngle;
        } else {
            lastTurnRate = remainingAngle / timeSeconds;
        }

        const float turnAngle = (std::min)(remainingAngle,
            lastTurnRate * timeSeconds);
        RotateOrientation(axis, gravityDirection,
            turnAngle * sign, false);
        currentTurnDir = static_cast<unsigned char>(DirectionForSign(sign));
    } else {
        if (tolerance >= kDefaultTolerance) {
            SetAxis(idealDir, gravityDirection);
        }
        currentTurnDir = TURN_NONE;
        lastTurnRate = 0.0f;
    }
}

// Retail symbol: ?SetAxis@idAIOrientation@@QAAXPAVidAI2@@ABVidVec3@@@Z
// EA: 0x82A5FB58, RVA: 0x00A5FB58
void idAIOrientation::SetAxis(idAI2* ai, const idVec3& direction) {
    if (ai == nullptr) {
        return;
    }
    idVec3 origin;
    idVec3 gravityNormal;
    if (Tungsten_GetAIOrientationPhysics(*ai, origin, gravityNormal)) {
        SetAxis(direction, gravityNormal);
    }
}
