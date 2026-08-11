#include "game/effects/gameeffects.h"

// EA 0x82BE0C00
bool idSmokeEmitter::Emit(const idVec3& velocity) {
    idVec3 origin;
    idMat3 axis;
    if (ta == nullptr || tag.parentJoint == 0xFFFF ||
            !Tungsten_GetSmokeEmitterTransform(ta, tag, origin, axis)) {
        return false;
    }

    const unsigned int nextSeed =
        1664525u * Tungsten_GetClientRandomSeed() + 1013904223u;
    Tungsten_SetClientRandomSeed(nextSeed);
    const float diversity = static_cast<float>((nextSeed >> 10) & 0x7FFFu)
        * 0.000030518509f;
    return Tungsten_AddSmokeParticles(particle,
        Tungsten_GetScaledGameMilliseconds(),
        Tungsten_GetScaledGameMillisecondsPerFrame(), diversity,
        origin, axis, velocity);
}

// EA 0x82BE0D20
void idFadeHelper::Fade(const float& from, const float& to,
        const int& time, const bool noStipple) {
    fadeFrom = from;
    fadeTo = to;
    fadeStartTime = Tungsten_GetScaledGameMilliseconds();
    fadeEndTime = fadeStartTime + time;
    noStippleFade = noStipple;
}

// EA 0x82BE0D80
bool idFadeHelper::Update(idPresentable* presentable) {
    const int currentTime = Tungsten_GetScaledGameMilliseconds();
    bool active = false;
    float value;
    if (currentTime >= fadeEndTime) {
        value = fadeTo;
        fadeEndTime = -1;
    } else {
        const int duration = fadeEndTime - fadeStartTime;
        const float fraction = duration <= 0 ? 1.0f
            : static_cast<float>(currentTime - fadeStartTime) /
                static_cast<float>(duration);
        value = fadeFrom + fraction * (fadeTo - fadeFrom);
        active = true;
    }
    if (presentable != nullptr) {
        Tungsten_ApplyPresentableFade(
            presentable, value, !noStippleFade);
    }
    return active;
}
