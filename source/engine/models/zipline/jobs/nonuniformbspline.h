#pragma once

#include "idlib/math/vector.h"

#include <algorithm>
#include <cmath>

// Fixed-capacity non-uniform B-spline used by the zipline generation jobs.
// Keeping the knots inline preserves the recovered console layout while the
// implementation below is ordinary scalar C++ and has no VMX dependency.
template<class type_t>
class idNonUniformBSpline {
public:
    enum boundary_t : int {
        FREE = 0,
        CLAMPED = 1,
        CLOSED = 2
    };

    static constexpr int MAX_KNOTS = 512;
    static constexpr int MAX_ORDER = 16;

    idNonUniformBSpline()
        : numKnots(0)
        , boundaryType(CLAMPED)
        , closeTime(0.0f)
        , order(4) {
    }

    void Clear() {
        numKnots = 0;
    }

    int AddValue(float time, const type_t& value) {
        if (numKnots >= MAX_KNOTS) {
            return -1;
        }

        const int index = numKnots++;
        times[index] = time;
        values[index] = value;
        return index;
    }

    int GetNumValues() const {
        return numKnots;
    }

    void SetBoundaryType(boundary_t type) {
        boundaryType = type;
    }

    boundary_t GetBoundaryType() const {
        return boundaryType;
    }

    void SetCloseTime(float time) {
        closeTime = time;
    }

    float GetCloseTime() const {
        return closeTime;
    }

    void SetOrder(int newOrder) {
        order = std::max(1, std::min(newOrder, MAX_ORDER));
    }

    int GetOrder() const {
        return order;
    }

    float ClampedTime(float time) const {
        if (numKnots == 0) {
            return time;
        }

        if (boundaryType == CLAMPED) {
            if (time < times[0]) {
                return times[0];
            }
            if (time >= times[numKnots - 1]) {
                return times[numKnots - 1];
            }
            return time;
        }

        if (boundaryType == CLOSED) {
            const float period = times[numKnots - 1] + closeTime;
            if (period > 0.0f) {
                return time - std::floor(time / period) * period;
            }
        }

        return time;
    }

    int IndexForTime(float time) const {
        int count = numKnots;
        int offset = 0;

        while (count > 0) {
            const int half = count >> 1;
            const int middle = offset + half;
            if (time == times[middle]) {
                return middle;
            }
            count -= half;
            if (time <= times[middle]) {
                count = half;
            } else {
                offset = middle;
                if (half == 0) {
                    return offset + 1;
                }
            }
        }

        return offset;
    }

    type_t ValueForIndex(int index) const {
        if (numKnots == 0) {
            return type_t();
        }
        if (numKnots == 1) {
            return values[0];
        }
        if (index >= 0 && index < numKnots) {
            return values[index];
        }

        if (boundaryType == CLOSED) {
            int wrapped = index % numKnots;
            if (wrapped < 0) {
                wrapped += numKnots;
            }
            return values[wrapped];
        }

        if (boundaryType != FREE) {
            return index < 0 ? values[0] : values[numKnots - 1];
        }

        if (index < 0) {
            return values[0] + (values[1] - values[0]) *
                static_cast<float>(index);
        }

        const int last = numKnots - 1;
        return values[last] + (values[last] - values[last - 1]) *
            static_cast<float>(index - last);
    }

    float TimeForIndex(int index) const {
        if (numKnots == 0) {
            return 0.0f;
        }
        if (numKnots == 1) {
            return times[0];
        }
        if (index >= 0 && index < numKnots) {
            return times[index];
        }

        const int last = numKnots - 1;
        if (boundaryType == CLOSED) {
            const float period = times[last] + closeTime;
            int wrapped = index % numKnots;
            int cycle = index / numKnots;
            if (wrapped < 0) {
                wrapped += numKnots;
                --cycle;
            }
            return times[wrapped] + static_cast<float>(cycle) * period;
        }

        if (index < 0) {
            return times[0] + static_cast<float>(index) *
                (times[1] - times[0]);
        }

        return times[last] + static_cast<float>(index - last) *
            (times[last] - times[last - 1]);
    }

    void Basis(int index, int basisOrder, float time, float* basisValues) const {
        if (basisValues == nullptr || basisOrder <= 0) {
            return;
        }

        basisValues[basisOrder - 1] = 1.0f;
        for (int currentOrder = 2; currentOrder <= basisOrder;
             ++currentOrder) {
            int knotIndex = index - currentOrder + 1;
            basisValues[basisOrder - currentOrder] = 0.0f;

            for (int valueIndex = basisOrder - currentOrder + 1;
                 valueIndex < basisOrder; ++valueIndex) {
                ++knotIndex;
                const float left = TimeForIndex(knotIndex);
                const float right = TimeForIndex(
                    knotIndex + currentOrder - 1);
                const float denominator = right - left;
                const float fraction = denominator != 0.0f
                    ? (time - left) / denominator
                    : 0.0f;

                basisValues[valueIndex - 1] +=
                    (1.0f - fraction) * basisValues[valueIndex];
                basisValues[valueIndex] *= fraction;
            }
        }
    }

    type_t GetCurrentValue(float time) const {
        if (numKnots == 0) {
            return type_t();
        }
        if (numKnots == 1) {
            return values[0];
        }

        const int effectiveOrder = std::max(1, std::min(order, MAX_ORDER));
        float basisValues[MAX_ORDER] = {};
        const float sampleTime = ClampedTime(time);
        const int knotIndex = IndexForTime(sampleTime);
        Basis(knotIndex - 1, effectiveOrder, sampleTime, basisValues);

        type_t result = ValueForIndex(0) * 0.0f;
        for (int basisIndex = 0; basisIndex < effectiveOrder; ++basisIndex) {
            result = result + ValueForIndex(
                knotIndex + basisIndex - (effectiveOrder >> 1)) *
                basisValues[basisIndex];
        }
        return result;
    }

    float times[MAX_KNOTS];
    type_t values[MAX_KNOTS];
    int numKnots;
    boundary_t boundaryType;
    float closeTime;
    int order;
};

static_assert(sizeof(idNonUniformBSpline<idVec3>) == 8208,
    "Recovered idNonUniformBSpline<idVec3> ABI changed");
