#include "wanderingaim.h"

#include "aidefs.h"

#include <cmath>

idWanderingAimRuntime::idWanderingAimRuntime()
    : effectiveWeapon(nullptr)
    , maxDivergence(0.0f)
    , convergeRate(0.0f)
    , wanderScale(0.0f)
    , wanderDuration(0)
    , lastFireGraceDuration(0)
    , settledDuration(0)
    , lastFireTime(0)
    , blockedShots(0)
    , gravityNormal(0.0f, 0.0f, -1.0f)
    , inCombat(false)
    , accuratelyAiming(false)
    , blindFiring(false) {
}

idWanderingAim::idWanderingAim()
    : error(0.0f, 0.0f, 0.0f)
    , lastTime(0)
    , convergeTime(0) {
}

// Retail symbol: ?ConvergeTo@idWanderingAim@@AAAXMABVidVec3@@@Z
// EA: 0x82B2BB78, RVA: 0x00B2BB78
void idWanderingAim::ConvergeTo(
        const float rate, const idVec3& destination) {
    const idVec3 delta = destination - error;
    const float distance = delta.Length();
    if (distance <= rate || distance == 0.0f) {
        error = destination;
        return;
    }
    error = error + delta * (rate / distance);
}

// Retail symbol: ?AddWeaponFireKickbackImpulse@idWanderingAim@@QAAXPBVidAI2@@PBVidWeapon@@@Z
// EA: 0x82B2BC50, RVA: 0x00B2BC50
void idWanderingAim::AddWeaponFireKickbackImpulse(
        const idAI2* const ai, const idWeapon* const weapon) {
    if (ai == nullptr || weapon == nullptr) {
        return;
    }
    const float kickback = Tungsten_GetWanderingAimKickback(*ai, *weapon);
    error.z += RandomFloat(-1.0f, 1.0f) * kickback;
    error.y += RandomFloat(-1.0f, 1.0f) * kickback;
    error.x += RandomFloat(-1.0f, 1.0f) * kickback;
}

// Retail symbol: ?SmoothWander@idWanderingAim@@AAAXMM@Z
// EA: 0x82B2BD90, RVA: 0x00B2BD90
void idWanderingAim::SmoothWander(
        const float scale, const float maximumDivergence) {
    const float time = static_cast<float>(
        Tungsten_GetWanderingAimGameMilliseconds());
    idVec3 increment(
        std::cos(time * 0.001f) * scale,
        std::cos(time * 0.0042300001f) * scale,
        0.0f);
    if (error.Dot(increment) < 0.0f) {
        increment = increment * 0.19999999f;
    }
    error = error + increment;
    const float length = error.Length();
    if (length > maximumDivergence && length > 0.0f) {
        error = error * (maximumDivergence / length);
    }
}

// Retail symbol: ?GetEffectiveWeapon@idWanderingAim@@AAAPAVidWeapon@@PBVidAI2@@@Z
// EA: 0x82B2BF30, RVA: 0x00B2BF30
const idWeapon* idWanderingAim::GetEffectiveWeapon(
        const idAI2* const ai) const {
    if (ai == nullptr) {
        return nullptr;
    }
    idWanderingAimRuntime runtime;
    return Tungsten_GetWanderingAimRuntime(*ai, runtime)
        ? runtime.effectiveWeapon : nullptr;
}

// Retail symbol: ?Diverge@idWanderingAim@@QAAXPBVidAI2@@@Z
// EA: 0x82B2BFE0, RVA: 0x00B2BFE0
void idWanderingAim::Diverge(const idAI2* const ai) {
    if (ai == nullptr || GetEffectiveWeapon(ai) == nullptr) {
        return;
    }
    idWanderingAimRuntime runtime;
    if (!Tungsten_GetWanderingAimRuntime(*ai, runtime)) {
        return;
    }
    lastTime = Tungsten_GetWanderingAimGameMilliseconds();
    SmoothWander(runtime.maxDivergence, runtime.maxDivergence);
}

// Retail symbol: ?Update@idWanderingAim@@QAAXPBVidAI2@@ABVidVec3@@1MAAV3@_N@Z
// EA: 0x82B2C050, RVA: 0x00B2C050
void idWanderingAim::Update(const idAI2* const ai,
        const idVec3& eyePosition, const idVec3& directionToTarget,
        const float distanceToTarget, idVec3& newFocusPoint,
        const bool showDebug) {
    newFocusPoint = eyePosition + directionToTarget * distanceToTarget;
    if (ai == nullptr) {
        return;
    }
    idWanderingAimRuntime runtime;
    if (!Tungsten_GetWanderingAimRuntime(*ai, runtime)
        || runtime.effectiveWeapon == nullptr) {
        return;
    }
    if (!runtime.inCombat) {
        error.Zero();
        return;
    }

    const int currentTime = Tungsten_GetWanderingAimGameMilliseconds();
    int debugState = 0;
    if (!runtime.blindFiring
        && (runtime.accuratelyAiming
            || currentTime - runtime.lastFireTime
                < runtime.lastFireGraceDuration)) {
        if (currentTime - lastTime > runtime.wanderDuration) {
            ConvergeTo(runtime.convergeRate, idVec3(0.0f, 0.0f, 0.0f));
            debugState = 2;
        }
    } else if (!runtime.blindFiring && runtime.blockedShots > 0) {
        ConvergeTo(runtime.convergeRate, idVec3(0.0f, 0.0f, 0.0f));
        debugState = 2;
    } else {
        SmoothWander(runtime.wanderScale, runtime.maxDivergence);
        lastTime = currentTime;
        debugState = runtime.blindFiring ? 1 : 0;
    }

    convergeTime = error.LengthSqr() != 0.0f ? 0
        : convergeTime + Tungsten_GetWanderingAimGameMillisecondsPerFrame();
    idVec3 gravity = runtime.gravityNormal;
    if (gravity.NormalizeFast() == 0.0f) {
        gravity.Set(0.0f, 0.0f, -1.0f);
    }
    idVec3 lateral = gravity.Cross(directionToTarget);
    lateral.NormalizeFast();
    newFocusPoint = newFocusPoint
        + (lateral * error.x + gravity * error.y) * distanceToTarget;

    if (showDebug) {
        if (runtime.accuratelyAiming && error.LengthSqr() != 0.0f) {
            debugState = 3;
        } else if (runtime.accuratelyAiming
            && convergeTime >= runtime.settledDuration) {
            debugState = 4;
        }
        Tungsten_DebugWanderingAim(eyePosition, newFocusPoint, debugState);
    }
}
