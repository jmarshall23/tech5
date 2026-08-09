#include "gamelib/animstack/animweb/animwebutils.h"

#include <algorithm>
#include <cmath>

float LerpToWithScale(const float current, const float destination,
        const float scale) {
    const float delta = destination - current;
    return delta <= -0.000001f || delta >= 0.000001f
        ? current + delta * scale
        : destination;
}

float LerpToWithRate(const float current, const float destination,
        const float absoluteRate) {
    if (current < destination) {
        const float next = current + absoluteRate;
        if (next < current) {
            return current;
        }
        return next > destination ? destination : next;
    }
    if (current > destination) {
        const float next = current - absoluteRate;
        if (next > current) {
            return current;
        }
        return next < destination ? destination : next;
    }
    return current;
}

namespace {

void SetSync8(const float angle, const bool reverse, float& index1,
        float& index2, float& blend) {
    constexpr float inverse45 = 1.0f / 45.0f;
    const int sector = static_cast<int>(angle * inverse45);
    const float fraction = (angle - static_cast<float>(sector) * 45.0f)
        * inverse45;

    const int first = reverse ? 7 - sector : sector;
    index1 = static_cast<float>(first);
    index2 = static_cast<float>((first + 1) & 7);
    blend = reverse ? 1.0f - fraction : fraction;
}

} // namespace

bool UpdateWalkBlend(const idVec3& velocity, const idMat3& axis,
        const float lerpScale, float& blendBack, float& blendRight,
        float& blendAngle, float& sync8Index1, float& sync8Index2,
        float& sync8BlendAngle) {
    const float speed = velocity.Length();
    if (speed <= 0.1f) {
        return false;
    }

    const float inverseSpeed = 1.0f / speed;
    const float forward = (std::max)(-1.0f, (std::min)(1.0f,
        velocity.Dot(axis[0]) * inverseSpeed));
    const float right = (std::max)(-1.0f, (std::min)(1.0f,
        velocity.Dot(axis[1]) * inverseSpeed));
    constexpr float radiansToDegrees = 57.29577951308232f;
    const float angle = std::acos(forward) * radiansToDegrees;
    const float forwardAmount = forward < 0.0f
        ? (angle - 90.0f) / 90.0f
        : 1.0f - angle / 90.0f;

    blendBack = LerpToWithScale(blendBack, forward < 0.0f ? 1.0f : 0.0f,
        lerpScale);
    blendRight = LerpToWithScale(blendRight, right < 0.0f ? 1.0f : 0.0f,
        lerpScale);
    blendAngle = LerpToWithScale(blendAngle, 1.0f - forwardAmount,
        lerpScale);
    SetSync8(angle, right >= 0.0f, sync8Index1, sync8Index2,
        sync8BlendAngle);
    return true;
}

bool UpdateWalkBlendFromAngle(const float angle, const float lerpScale,
        float& blendBack, float& blendRight, float& blendAngle,
        float& sync8Index1, float& sync8Index2, float& sync8BlendAngle) {
    const bool forward = angle > -90.0f && angle < 90.0f;
    const bool positive = angle > 0.0f && angle < 180.0f;
    const float absoluteAngle = std::fabs(angle);
    const float forwardAmount = forward
        ? 1.0f - absoluteAngle / 90.0f
        : (absoluteAngle - 90.0f) / 90.0f;

    blendBack = LerpToWithScale(blendBack, forward ? 0.0f : 1.0f,
        lerpScale);
    blendRight = LerpToWithScale(blendRight, positive ? 0.0f : 1.0f,
        lerpScale);
    blendAngle = LerpToWithScale(blendAngle, 1.0f - forwardAmount,
        lerpScale);
    SetSync8(absoluteAngle, positive, sync8Index1, sync8Index2,
        sync8BlendAngle);
    return true;
}
