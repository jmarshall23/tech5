#include "decay.h"

#include <cmath>

idParametricDecay::idParametricDecay()
    : delta(0.0f)
    , linear(0.0f)
    , t0(0.0f)
    , tdelta(0.0f)
    , lambda(0.0f) {
}

void idParametricDecay::Init(
    const float newDelta,
    const float newLinear,
    const float newT0,
    const float newTDelta,
    const float newLambda
) {
    delta = newDelta;
    linear = newLinear;
    t0 = newT0;
    tdelta = newTDelta;
    lambda = newLambda;
}

void idParametricDecay::SetTZero(const float newT0) {
    t0 = newT0;
}

void idParametricDecay::SetDelta(const float newDelta) {
    delta = newDelta;
}

float idParametricDecay::Evaluate(const float t) const {
    if (t < t0) {
        return delta;
    }

    const float elapsed = t - t0;
    if (elapsed > tdelta) {
        return 0.0f;
    }

    const float normalizedTime = elapsed / tdelta;
    const float exponential = std::pow(
        0.5f,
        elapsed / (lambda * tdelta)
    );
    return ((1.0f - linear) * exponential
        + (1.0f - normalizedTime) * linear) * delta;
}

