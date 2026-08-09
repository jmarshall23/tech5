#pragma once

#include "extrapolate.h"

#include <cmath>

enum XUI_INTERPOLATE : int {
    XUI_INTERPOLATE_LINEAR = 0,
    XUI_INTERPOLATE_NONE = 1,
    XUI_INTERPOLATE_EASE = 2
};

class idInterpolateParms {
public:
    int accelTimeMs;
    int decelTimeMs;
    int durationMs;
};

template<class T>
class idInterpolate {
public:
    float startTime;
    float duration;
    T startValue;
    T endValue;
    mutable float currentTime;
    mutable T currentValue;

    idInterpolate()
        : startTime(0.0f), duration(0.0f), startValue(T()), endValue(T()),
          currentTime(-1.0f), currentValue(startValue) {
    }

    void Init(const float newStartTime, const float newDuration,
            const T& newStartValue, const T& newEndValue) {
        startTime = newStartTime;
        duration = newDuration;
        startValue = newStartValue;
        endValue = newEndValue;
        currentTime = -1.0f;
        currentValue = startValue;
    }

    T GetCurrentValue(const float time) const {
        if (time == currentTime) return currentValue;
        currentTime = time;
        const float delta = time - startTime;
        if ((duration >= 0.0f && delta <= 0.0f)
                || (duration < 0.0f && delta >= 0.0f)) {
            currentValue = startValue;
        } else if ((duration >= 0.0f && delta >= duration)
                || (duration < 0.0f && delta <= duration)) {
            currentValue = endValue;
        } else {
            currentValue = startValue + (endValue - startValue) * (delta / duration);
        }
        return currentValue;
    }

    T GetCurrentValueEaseOut(const float time) const {
        const float delta = time - startTime;
        if (duration <= 0.0f || delta <= 0.0f) return startValue;
        if (delta >= duration) return endValue;
        const float fraction = std::sin((delta / duration) * 1.57079632679489661923f);
        currentTime = time;
        currentValue = startValue + (endValue - startValue) * fraction;
        return currentValue;
    }

    bool IsDone(const float time) const {
        return duration >= 0.0f ? time >= startTime + duration
                                : time <= startTime + duration;
    }
    void SetStartTime(const float value) { startTime = value; currentTime = -1.0f; }
    void SetDuration(const float value) { duration = value; currentTime = -1.0f; }
    void SetStartValue(const T& value) { startValue = value; currentTime = -1.0f; }
    void SetEndValue(const T& value) { endValue = value; currentTime = -1.0f; }
    float GetStartTime() const { return startTime; }
    float GetEndTime() const { return startTime + duration; }
    float GetDuration() const { return duration; }
    const T& GetStartValue() const { return startValue; }
    const T& GetEndValue() const { return endValue; }
};

template<class T>
class idInterpolateAccelDecelLinear {
public:
    float startTime;
    float accelTime;
    float linearTime;
    float decelTime;
    T startValue;
    T endValue;
    mutable idExtrapolate<T> extrapolate;

    idInterpolateAccelDecelLinear()
        : startTime(0.0f), accelTime(0.0f), linearTime(0.0f), decelTime(0.0f),
          startValue(T()), endValue(T()), extrapolate() {
    }

    void Init(const float newStartTime, float newAccelTime, float newDecelTime,
            const float duration, const T& newStartValue, const T& newEndValue) {
        startTime = newStartTime;
        accelTime = newAccelTime;
        decelTime = newDecelTime;
        startValue = newStartValue;
        endValue = newEndValue;
        if (duration <= 0.0f) {
            linearTime = 0.0f;
            extrapolate.Init(startTime, 0.0f, startValue, T(), T(), EXTRAPOLATION_NONE);
            return;
        }
        if (accelTime + decelTime > duration) {
            const float sum = accelTime + decelTime;
            accelTime = sum > 0.0f ? accelTime * duration / sum : 0.0f;
            decelTime = duration - accelTime;
        }
        linearTime = duration - accelTime - decelTime;
        const float effectiveTime = 0.5f * (accelTime + decelTime) + linearTime;
        const T phaseSpeed = (endValue - startValue) * (1000.0f / effectiveTime);
        extrapolation_t phase = EXTRAPOLATION_ACCELLINEAR;
        float phaseDuration = accelTime;
        if (accelTime == 0.0f) {
            phase = linearTime == 0.0f
                ? EXTRAPOLATION_DECELLINEAR : EXTRAPOLATION_LINEAR;
            phaseDuration = linearTime == 0.0f ? decelTime : linearTime;
        }
        extrapolate.Init(startTime, phaseDuration, startValue, T(), phaseSpeed, phase);
    }

    T GetCurrentValue(const float time) const {
        SetPhase(time);
        return extrapolate.GetCurrentValue(time);
    }
    T GetCurrentSpeed(const float time) const {
        SetPhase(time);
        return extrapolate.GetCurrentSpeed(time);
    }
    bool IsDone(const float time) const {
        return time >= startTime + accelTime + linearTime + decelTime;
    }
    float GetStartTime() const { return startTime; }
    float GetEndTime() const { return startTime + accelTime + linearTime + decelTime; }
    float GetDuration() const { return accelTime + linearTime + decelTime; }
    void SetStartTime(const float value) { startTime = value; extrapolate.currentTime = -1.0f; }
    void SetStartValue(const T& value) { startValue = value; extrapolate.currentTime = -1.0f; }
    void SetEndValue(const T& value) { endValue = value; extrapolate.currentTime = -1.0f; }

private:
    void SetPhase(const float time) const {
        const float elapsed = time - startTime;
        const T zero = T();
        const T phaseSpeed = extrapolate.speed;
        if (elapsed < accelTime) {
            if ((static_cast<int>(extrapolate.extrapolationType) & ~EXTRAPOLATION_NOSTOP)
                    != EXTRAPOLATION_ACCELLINEAR) {
                extrapolate.Init(startTime, accelTime, startValue, zero,
                    phaseSpeed, EXTRAPOLATION_ACCELLINEAR);
            }
        } else if (elapsed < accelTime + linearTime) {
            if ((static_cast<int>(extrapolate.extrapolationType) & ~EXTRAPOLATION_NOSTOP)
                    != EXTRAPOLATION_LINEAR) {
                const T phaseStart = startValue
                    + phaseSpeed * (accelTime * 0.0005f);
                extrapolate.Init(startTime + accelTime, linearTime, phaseStart,
                    zero, phaseSpeed, EXTRAPOLATION_LINEAR);
            }
        } else if ((static_cast<int>(extrapolate.extrapolationType)
                & ~EXTRAPOLATION_NOSTOP) != EXTRAPOLATION_DECELLINEAR) {
            const T phaseStart = endValue
                - phaseSpeed * (decelTime * 0.0005f);
            extrapolate.Init(startTime + accelTime + linearTime, decelTime,
                phaseStart, zero, phaseSpeed, EXTRAPOLATION_DECELLINEAR);
        }
    }
};

template<class T>
class idInterpolateAccelDecelSine {
public:
    float startTime;
    float accelTime;
    float linearTime;
    float decelTime;
    T startValue;
    T endValue;
    mutable idExtrapolate<T> extrapolate;

    idInterpolateAccelDecelSine()
        : startTime(0.0f), accelTime(0.0f), linearTime(0.0f), decelTime(0.0f),
          startValue(T()), endValue(T()), extrapolate() {
    }

    void Init(const float newStartTime, float newAccelTime, float newDecelTime,
            const float duration, const T& newStartValue, const T& newEndValue) {
        startTime = newStartTime;
        accelTime = newAccelTime;
        decelTime = newDecelTime;
        startValue = newStartValue;
        endValue = newEndValue;
        if (duration <= 0.0f) {
            linearTime = 0.0f;
            extrapolate.Init(startTime, 0.0f, startValue, T(), T(), EXTRAPOLATION_NONE);
            return;
        }
        if (accelTime + decelTime > duration) {
            const float sum = accelTime + decelTime;
            accelTime = sum > 0.0f ? accelTime * duration / sum : 0.0f;
            decelTime = duration - accelTime;
        }
        linearTime = duration - accelTime - decelTime;
        const float effectiveTime = 0.70710678118654752440f
            * (accelTime + decelTime) + linearTime;
        const T phaseSpeed = (endValue - startValue) * (1000.0f / effectiveTime);
        extrapolation_t phase = EXTRAPOLATION_ACCELSINE;
        float phaseDuration = accelTime;
        if (accelTime == 0.0f) {
            phase = linearTime == 0.0f
                ? EXTRAPOLATION_DECELSINE : EXTRAPOLATION_LINEAR;
            phaseDuration = linearTime == 0.0f ? decelTime : linearTime;
        }
        extrapolate.Init(startTime, phaseDuration, startValue, T(), phaseSpeed, phase);
    }

    T GetCurrentValue(const float time) const { SetPhase(time); return extrapolate.GetCurrentValue(time); }
    T GetCurrentSpeed(const float time) const { SetPhase(time); return extrapolate.GetCurrentSpeed(time); }
    bool IsDone(const float time) const { return time >= startTime + accelTime + linearTime + decelTime; }

private:
    void SetPhase(const float time) const {
        constexpr float SQRT_HALF = 0.70710678118654752440f;
        const float elapsed = time - startTime;
        const T zero = T();
        const T phaseSpeed = extrapolate.speed;
        if (elapsed < accelTime) {
            if ((static_cast<int>(extrapolate.extrapolationType) & ~EXTRAPOLATION_NOSTOP)
                    != EXTRAPOLATION_ACCELSINE) {
                extrapolate.Init(startTime, accelTime, startValue, zero,
                    phaseSpeed, EXTRAPOLATION_ACCELSINE);
            }
        } else if (elapsed < accelTime + linearTime) {
            if ((static_cast<int>(extrapolate.extrapolationType) & ~EXTRAPOLATION_NOSTOP)
                    != EXTRAPOLATION_LINEAR) {
                const T phaseStart = startValue
                    + phaseSpeed * (accelTime * SQRT_HALF * 0.001f);
                extrapolate.Init(startTime + accelTime, linearTime, phaseStart,
                    zero, phaseSpeed, EXTRAPOLATION_LINEAR);
            }
        } else if ((static_cast<int>(extrapolate.extrapolationType)
                & ~EXTRAPOLATION_NOSTOP) != EXTRAPOLATION_DECELSINE) {
            const T phaseStart = endValue
                - phaseSpeed * (decelTime * SQRT_HALF * 0.001f);
            extrapolate.Init(startTime + accelTime + linearTime, decelTime,
                phaseStart, zero, phaseSpeed, EXTRAPOLATION_DECELSINE);
        }
    }
};

template<class T>
class idInterpolateAccelLinearEx {
public:
    float startTime;
    float duration;
    float startSpeed;
    float endSpeed;
    T startValue;
    T endValue;
    idExtrapolate<T> extrapolate;

    idInterpolateAccelLinearEx()
        : startTime(0.0f), duration(0.0f), startSpeed(0.0f), endSpeed(0.0f),
          startValue(T()), endValue(T()), extrapolate() {
    }

    void InitDuration(const float newStartTime, const float newStartSpeed,
            const float newDuration, const T& newStartValue, const T& newEndValue) {
        startTime = newStartTime;
        startSpeed = newStartSpeed;
        duration = newDuration;
        startValue = newStartValue;
        endValue = newEndValue;
        endSpeed = duration > 0.0f
            ? -2.0f * ((duration * 0.001f * startSpeed + startValue - endValue)
                / (duration * 0.001f)) + startSpeed
            : startSpeed;
        extrapolate.Init(startTime, duration, startValue, T() + startSpeed,
            T() + (endSpeed - startSpeed), EXTRAPOLATION_ACCELLINEAR);
    }

    float InitEndSpeed(const float newStartTime, const float newStartSpeed,
            const float newEndSpeed, const T& newStartValue, const T& newEndValue) {
        startTime = newStartTime;
        startSpeed = newStartSpeed;
        endSpeed = newEndSpeed;
        startValue = newStartValue;
        endValue = newEndValue;
        const float denominator = 2.0f * startSpeed + (endSpeed - startSpeed);
        duration = denominator != 0.0f
            ? static_cast<float>((endValue - startValue) / denominator) * 2000.0f
            : 0.0f;
        extrapolate.Init(startTime, duration, startValue, T() + startSpeed,
            T() + (endSpeed - startSpeed), EXTRAPOLATION_ACCELLINEAR);
        return duration;
    }

    T GetCurrentValue(const float time) const {
        if (time < startTime + duration) return extrapolate.GetCurrentValue(time);
        if (startSpeed == endSpeed) return endValue;
        return endValue + (T() + endSpeed) * ((time - startTime - duration) * 0.001f);
    }
};

static_assert(sizeof(idInterpolate<float>) == 24,
    "Recovered idInterpolate<float> ABI changed");
static_assert(sizeof(idInterpolate<idVec3>) == 48,
    "Recovered idInterpolate<idVec3> ABI changed");
static_assert(sizeof(idInterpolate<idQuat>) == 60,
    "Recovered idInterpolate<idQuat> ABI changed");
static_assert(sizeof(idInterpolateAccelDecelLinear<float>) == 56,
    "Recovered idInterpolateAccelDecelLinear<float> ABI changed");
static_assert(sizeof(idInterpolateAccelDecelLinear<idVec3>) == 104,
    "Recovered idInterpolateAccelDecelLinear<idVec3> ABI changed");
static_assert(sizeof(idInterpolateAccelDecelLinear<idQuat>) == 128,
    "Recovered idInterpolateAccelDecelLinear<idQuat> ABI changed");
static_assert(sizeof(idInterpolateAccelLinearEx<float>) == 56,
    "Recovered idInterpolateAccelLinearEx<float> ABI changed");
