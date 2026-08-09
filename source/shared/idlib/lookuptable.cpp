#include "lookuptable.h"

#include <algorithm>
#include <cmath>

namespace {

int PositiveModulo(const int value, const int modulus) {
    const int remainder = value % modulus;
    return remainder < 0 ? remainder + modulus : remainder;
}

int FloorDivide(const int value, const int divisor) {
    int quotient = value / divisor;
    if (value < 0 && value % divisor != 0) {
        --quotient;
    }
    return quotient;
}

} // namespace

void idCatmullRomSpline<float>::Sort() {
    for (int end = numKnots - 1; end > 0; --end) {
        int maximumIndex = 0;
        for (int index = 1; index <= end; ++index) {
            if (times[index] > times[maximumIndex]) {
                maximumIndex = index;
            }
        }
        std::swap(times[maximumIndex], times[end]);
        std::swap(values[maximumIndex], values[end]);
    }
    changed = true;
}

void idCatmullRomSpline<float>::Normalize(const float totalTime) {
    if (numKnots < 1 || times[numKnots - 1] == 0.0f) {
        return;
    }

    const float scale = totalTime / times[numKnots - 1];
    for (int index = 0; index < numKnots; ++index) {
        times[index] *= scale;
    }
    changed = true;
}

float idCatmullRomSpline<float>::ClampedTime(const float time) const {
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
        if (period == 0.0f) {
            return times[0];
        }
        return time - std::floor(time / period) * period;
    }

    return time;
}

int idCatmullRomSpline<float>::IndexForTime(
    const float time,
    const bool fastSearch
) const {
    if (fastSearch && currentIndex >= 0 && currentIndex <= numKnots) {
        if (currentIndex == 0) {
            if (time <= times[0]) {
                return 0;
            }
        } else if (currentIndex == numKnots) {
            if (time > times[numKnots - 1]) {
                return currentIndex;
            }
        } else if (time > times[currentIndex - 1]
            && time <= times[currentIndex]) {
            return currentIndex;
        } else if (currentIndex + 1 <= numKnots
            && time > times[currentIndex]
            && (currentIndex + 1 == numKnots
                || time <= times[currentIndex + 1])) {
            ++currentIndex;
            return currentIndex;
        }
    }

    int low = 0;
    int high = numKnots;
    while (low < high) {
        const int middle = low + (high - low) / 2;
        if (time <= times[middle]) {
            high = middle;
        } else {
            low = middle + 1;
        }
    }

    if (fastSearch) {
        currentIndex = low;
    }
    return low;
}

float idCatmullRomSpline<float>::TimeForIndex(const int index) const {
    const int lastIndex = numKnots - 1;
    if (index >= 0 && index <= lastIndex) {
        return times[index];
    }

    if (boundaryType == CLOSED) {
        const float period = times[lastIndex] + closeTime;
        const int cycle = FloorDivide(index, numKnots);
        return static_cast<float>(cycle) * period
            + times[PositiveModulo(index, numKnots)];
    }

    if (index < 0) {
        return times[0]
            + static_cast<float>(index) * (times[1] - times[0]);
    }
    return times[lastIndex]
        + static_cast<float>(index - lastIndex)
            * (times[lastIndex] - times[lastIndex - 1]);
}

float idCatmullRomSpline<float>::ValueForIndex(const int index) const {
    const int lastIndex = numKnots - 1;
    if (index >= 0 && index <= lastIndex) {
        return values[index];
    }

    if (boundaryType == CLOSED) {
        return values[PositiveModulo(index, numKnots)];
    }
    if (boundaryType == CLAMPED) {
        return index < 0 ? values[0] : values[lastIndex];
    }

    if (index < 0) {
        return values[0]
            + static_cast<float>(index) * (values[1] - values[0]);
    }
    return values[lastIndex]
        + static_cast<float>(index - lastIndex)
            * (values[lastIndex] - values[lastIndex - 1]);
}

void idCatmullRomSpline<float>::Basis(
    const int index,
    const float time,
    float basisValues[4]
) const {
    const float intervalStart = TimeForIndex(index);
    const float intervalEnd = TimeForIndex(index + 1);
    const float intervalLength = intervalEnd - intervalStart;
    const float s = intervalLength == 0.0f
        ? 0.0f
        : (time - intervalStart) / intervalLength;

    basisValues[0] = 0.5f * (((2.0f - s) * s - 1.0f) * s);
    basisValues[1] = 0.5f * ((((3.0f * s - 5.0f) * s) * s) + 2.0f);
    basisValues[2] = 0.5f * ((((4.0f - 3.0f * s) * s + 1.0f) * s));
    basisValues[3] = 0.5f * ((s - 1.0f) * s * s);
}

float idCatmullRomSpline<float>::GetCurrentValue(
    const float time,
    const bool fastSearch
) const {
    if (numKnots == 1) {
        return values[0];
    }

    const float adjustedTime = ClampedTime(time);
    const int upperIndex = IndexForTime(adjustedTime, fastSearch);
    const int basisIndex = upperIndex - 1;
    float basisValues[4];
    Basis(basisIndex, adjustedTime, basisValues);

    float result = 0.0f;
    for (int index = 0; index < 4; ++index) {
        result += ValueForIndex(basisIndex - 1 + index)
            * basisValues[index];
    }
    return result;
}

idLookupTable::idLookupTable()
    : clamp(false)
    , snap(false)
    , spline(false)
    , minimum(0.0f)
    , maximum(1.0f)
    , values{} {
    values.numKnots = 0;
    values.currentIndex = -1;
    values.changed = true;
    values.boundaryType = idCatmullRomSpline<float>::CLOSED;
    values.closeTime = 1.0f;
}

void idLookupTable::SetSnap(const bool enabled) {
    snap = enabled;
    if (spline && enabled) {
        spline = false;
    }
}

void idLookupTable::SetSpline(const bool enabled) {
    spline = enabled;
    if (enabled && snap) {
        snap = false;
    }
}

void idLookupTable::Finalize() {
    values.Sort();
    if (values.numKnots > 1 && values.times[values.numKnots - 1] > 1.0f) {
        const float totalTime = clamp
            ? static_cast<float>(values.numKnots - 1)
            : 1.0f;
        values.Normalize(totalTime);
    }
    if (values.numKnots > 0) {
        values.closeTime = 1.0f - values.times[values.numKnots - 1];
    } else {
        values.closeTime = 1.0f;
    }
    values.changed = true;
}

void idLookupTable::SetClamp(const bool enabled) {
    clamp = enabled;
    values.changed = true;
    values.boundaryType = enabled
        ? idCatmullRomSpline<float>::CLAMPED
        : idCatmullRomSpline<float>::CLOSED;
}

void idLookupTable::AddValue(const float time, const float value) {
    if (values.numKnots >= 64) {
        return;
    }

    values.times[values.numKnots] = time;
    values.values[values.numKnots] = value;
    ++values.numKnots;
    values.changed = true;
}

void idLookupTable::Clear() {
    values.numKnots = 0;
    values.currentIndex = -1;
    values.changed = true;
    minimum = 0.0f;
    maximum = 1.0f;
    clamp = false;
    snap = false;
    spline = false;
    values.boundaryType = idCatmullRomSpline<float>::CLOSED;
    values.closeTime = 1.0f;
}

int idLookupTable::NumValues() const {
    return values.numKnots;
}

void idLookupTable::NormalizeValues(const float minimumValue,
        const float maximumValue) {
    const float range = maximumValue - minimumValue;
    if (range == 0.0f) return;
    for (int index = 0; index < values.numKnots; ++index)
        values.values[index] = (values.values[index] - minimumValue) / range;
    values.changed = true;
}

void idLookupTable::SetOutputRange(const float minimumValue,
        const float maximumValue) {
    minimum = minimumValue;
    maximum = maximumValue;
}

float idLookupTable::TableLookupNormalized(
    const float time,
    const bool fastSearch
) const {
    if (values.numKnots == 0) {
        return 0.0f;
    }
    if (values.numKnots == 1) {
        return values.values[0];
    }
    if (spline) {
        return values.GetCurrentValue(time, fastSearch);
    }

    if (clamp) {
        if (time <= values.times[0]) {
            return values.values[0];
        }
        if (time >= values.times[values.numKnots - 1]) {
            return values.values[values.numKnots - 1];
        }
    }

    const float adjustedTime = values.ClampedTime(time);
    const int upperIndex = values.IndexForTime(adjustedTime, fastSearch);
    if (snap) {
        return values.ValueForIndex(upperIndex - 1);
    }

    const float lowerTime = values.TimeForIndex(upperIndex - 1);
    const float upperTime = values.TimeForIndex(upperIndex);
    if (lowerTime == upperTime) {
        return 0.0f;
    }

    const float lowerValue = values.ValueForIndex(upperIndex - 1);
    const float upperValue = values.ValueForIndex(upperIndex);
    const float fraction = (adjustedTime - lowerTime)
        / (upperTime - lowerTime);
    return lowerValue + (upperValue - lowerValue) * fraction;
}

float idLookupTable::TableLookup(
    const float time,
    const bool fastSearch
) const {
    return minimum + (maximum - minimum)
        * TableLookupNormalized(time, fastSearch);
}
