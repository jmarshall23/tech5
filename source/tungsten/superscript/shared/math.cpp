#include "math.h"

#include <cmath>

const float math::TWO_PI = 6.28318530717958647692f;
const float math::ONE_OVER_TWO_PI = 1.0f / math::TWO_PI;

// Retail symbol: ?AngToVectors@math@@SAXABVssVector@@PAV2@11@Z
// EA: 0x82EEB6C8, RVA: 0x00EEB6C8
// Original PDB source: w:\tech5\tungsten\superscript\shared\math.cpp
void math::AngToVectors(
    const ssVector& angles,
    ssVector* const forward,
    ssVector* const right,
    ssVector* const up
) {
    // Preserve the conversion constant materialized by the retail code.
    constexpr float kDegreesToRadians = 0.017452778f;

    const float pitch = angles.x * kDegreesToRadians;
    const float yaw = angles.y * kDegreesToRadians;
    const float roll = angles.z * kDegreesToRadians;

    const float sinPitch = std::sin(pitch);
    const float cosPitch = std::cos(pitch);
    const float sinYaw = std::sin(yaw);
    const float cosYaw = std::cos(yaw);
    const float sinRoll = std::sin(roll);
    const float cosRoll = std::cos(roll);

    if (forward != nullptr) {
        forward->x = cosPitch * cosYaw;
        forward->y = cosPitch * sinYaw;
        forward->z = -sinPitch;
    }

    if (right != nullptr) {
        right->x = cosRoll * sinYaw - sinRoll * sinPitch * cosYaw;
        right->y = -sinRoll * sinPitch * sinYaw - cosRoll * cosYaw;
        right->z = -sinRoll * cosPitch;
    }

    if (up != nullptr) {
        up->x = cosRoll * sinPitch * cosYaw + sinRoll * sinYaw;
        up->y = cosRoll * sinPitch * sinYaw - sinRoll * cosYaw;
        up->z = cosRoll * cosPitch;
    }
}
