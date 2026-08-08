#pragma once

#include <cmath>

class idFader {
public:
    enum type_t {
        FADE_LINEAR = 0,
        FADE_SINE = 1,
        FADE_INVERSE_SINE = 2
    };

    idFader(const type_t fadeType = FADE_LINEAR, const float initialValue = 0.0f)
        : type(fadeType), startTime(0), duration(0),
          startValue(initialValue), endValue(initialValue) {
    }

    float GetValue(const int time) const {
        switch (type) {
            case FADE_SINE: return GetSine(time);
            case FADE_INVERSE_SINE: return GetInverseSine(time);
            default: return GetLinear(time);
        }
    }

    float GetLinear(const int time) const {
        return Interpolate(time, LinearFraction(time));
    }

    float GetSine(const int time) const {
        const float fraction = LinearFraction(time);
        const float shaped = std::sin(fraction * 1.5707963267948966f);
        return Interpolate(time, shaped);
    }

    float GetInverseSine(const int time) const {
        const float fraction = LinearFraction(time);
        const float shaped = 1.0f + std::sin(
            fraction * 1.5707963267948966f + 4.71238898038469f
        );
        return Interpolate(time, shaped);
    }

    void FadeTowards(const float newEndValue, const int time,
        const int newDuration) {
        startValue = GetValue(time);
        startTime = time;
        endValue = newEndValue;
        duration = newDuration < 0 ? 0 : newDuration;
    }

    void SetType(const type_t fadeType) {
        type = fadeType;
    }

private:
    type_t type;
    int startTime;
    int duration;
    float startValue;
    float endValue;

    float LinearFraction(const int time) const {
        if (time <= startTime) {
            return 0.0f;
        }
        if (duration <= 0) {
            return 1.0f;
        }
        if (time >= startTime + duration) {
            return 1.0f;
        }
        return static_cast<float>(time - startTime) / static_cast<float>(duration);
    }

    float Interpolate(const int time, const float fraction) const {
        if (time < startTime) {
            return startValue;
        }
        if (duration <= 0 || time >= startTime + duration) {
            return endValue;
        }
        return startValue + fraction * (endValue - startValue);
    }
};

static_assert(sizeof(idFader) == 20, "Recovered idFader ABI changed");
