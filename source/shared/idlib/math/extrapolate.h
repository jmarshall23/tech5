#pragma once

#include "vector.h"

#include <cmath>

enum extrapolation_t : int {
    EXTRAPOLATION_NONE = 0x01,
    EXTRAPOLATION_LINEAR = 0x02,
    EXTRAPOLATION_ACCELLINEAR = 0x04,
    EXTRAPOLATION_DECELLINEAR = 0x08,
    EXTRAPOLATION_ACCELSINE = 0x10,
    EXTRAPOLATION_DECELSINE = 0x20,
    EXTRAPOLATION_NOSTOP = 0x40
};

template<class T>
class idExtrapolate {
public:
    extrapolation_t extrapolationType;
    float startTime;
    float duration;
    T startValue;
    T baseSpeed;
    T speed;
    mutable float currentTime;
    mutable T currentValue;

    idExtrapolate()
        : extrapolationType(EXTRAPOLATION_NONE), startTime(0.0f), duration(0.0f),
          startValue(T()), baseSpeed(T()), speed(T()), currentTime(-1.0f),
          currentValue(startValue) {
    }

    void Init(const float newStartTime, const float newDuration,
            const T& newStartValue, const T& newBaseSpeed, const T& newSpeed,
            const extrapolation_t newType) {
        extrapolationType = newType;
        startTime = newStartTime;
        duration = newDuration;
        startValue = newStartValue;
        baseSpeed = newBaseSpeed;
        speed = newSpeed;
        currentTime = -1.0f;
        currentValue = startValue;
    }

    T GetCurrentValue(float time) const {
        if (time == currentTime) return currentValue;
        currentTime = time;
        if (time < startTime) {
            currentValue = startValue;
            return currentValue;
        }

        const int type = static_cast<int>(extrapolationType) & ~EXTRAPOLATION_NOSTOP;
        if (duration == 0.0f
                && type != EXTRAPOLATION_NONE && type != EXTRAPOLATION_LINEAR) {
            currentValue = startValue;
            return currentValue;
        }
        if ((static_cast<int>(extrapolationType) & EXTRAPOLATION_NOSTOP) == 0
                && time > startTime + duration) {
            time = startTime + duration;
        }

        const float elapsed = time - startTime;
        const float elapsedSeconds = elapsed * 0.001f;
        const float fraction = duration != 0.0f ? elapsed / duration : 0.0f;
        switch (type) {
        case EXTRAPOLATION_NONE:
            currentValue = startValue + baseSpeed * elapsedSeconds;
            break;
        case EXTRAPOLATION_LINEAR:
            currentValue = startValue + (baseSpeed + speed) * elapsedSeconds;
            break;
        case EXTRAPOLATION_ACCELLINEAR:
            currentValue = startValue + baseSpeed * elapsedSeconds
                + speed * (0.5f * fraction * fraction * duration * 0.001f);
            break;
        case EXTRAPOLATION_DECELLINEAR:
            currentValue = startValue + baseSpeed * elapsedSeconds
                + speed * ((-0.5f * fraction * fraction + fraction)
                    * duration * 0.001f);
            break;
        case EXTRAPOLATION_ACCELSINE:
            currentValue = startValue + baseSpeed * elapsedSeconds
                + speed * ((1.0f - std::cos(fraction * HALF_PI))
                    * duration * SQRT_HALF * 0.001f);
            break;
        case EXTRAPOLATION_DECELSINE:
            currentValue = startValue + baseSpeed * elapsedSeconds
                + speed * (std::sin(fraction * HALF_PI)
                    * duration * SQRT_HALF * 0.001f);
            break;
        default:
            currentValue = startValue;
            break;
        }
        return currentValue;
    }

    T GetCurrentSpeed(const float time) const {
        if (time < startTime) return T();
        const int type = static_cast<int>(extrapolationType) & ~EXTRAPOLATION_NOSTOP;
        if (duration == 0.0f
                && type != EXTRAPOLATION_NONE && type != EXTRAPOLATION_LINEAR) {
            return T();
        }
        if ((static_cast<int>(extrapolationType) & EXTRAPOLATION_NOSTOP) == 0
                && time > startTime + duration) {
            return T();
        }
        const float fraction = duration != 0.0f
            ? (time - startTime) / duration : 0.0f;
        switch (type) {
        case EXTRAPOLATION_LINEAR: return baseSpeed + speed;
        case EXTRAPOLATION_ACCELLINEAR: return baseSpeed + speed * fraction;
        case EXTRAPOLATION_DECELLINEAR: return baseSpeed + speed * (1.0f - fraction);
        case EXTRAPOLATION_ACCELSINE:
            return baseSpeed + speed * std::sin(fraction * HALF_PI);
        case EXTRAPOLATION_DECELSINE:
            return baseSpeed + speed * std::cos(fraction * HALF_PI);
        case EXTRAPOLATION_NONE:
        default: return baseSpeed;
        }
    }

    bool IsDone(const float time) const {
        return (static_cast<int>(extrapolationType) & EXTRAPOLATION_NOSTOP) == 0
            && time >= startTime + duration;
    }

    void SetStartTime(const float value) { startTime = value; currentTime = -1.0f; }
    void SetStartValue(const T& value) { startValue = value; currentTime = -1.0f; }
    float GetStartTime() const { return startTime; }
    float GetEndTime() const { return startTime + duration; }
    float GetDuration() const { return duration; }
    const T& GetStartValue() const { return startValue; }
    const T& GetBaseSpeed() const { return baseSpeed; }
    const T& GetSpeed() const { return speed; }

private:
    static constexpr float HALF_PI = 1.57079632679489661923f;
    static constexpr float SQRT_HALF = 0.70710678118654752440f;
};

static_assert(sizeof(idExtrapolate<float>) == 32,
    "Recovered idExtrapolate<float> ABI changed");
static_assert(sizeof(idExtrapolate<idVec3>) == 64,
    "Recovered idExtrapolate<idVec3> ABI changed");
static_assert(sizeof(idExtrapolate<idAngles>) == 64,
    "Recovered idExtrapolate<idAngles> ABI changed");
static_assert(sizeof(idExtrapolate<idQuat>) == 80,
    "Recovered idExtrapolate<idQuat> ABI changed");
