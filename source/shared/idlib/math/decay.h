#pragma once

// tungsten.exe.h type 12849.
class idParametricDecay {
public:
    idParametricDecay();

    void Init(float delta, float linear, float t0, float tdelta, float lambda);
    void SetTZero(float t0);
    void SetDelta(float delta);
    float Evaluate(float t) const;

private:
    float delta;
    float linear;
    float t0;
    float tdelta;
    float lambda;
};

static_assert(sizeof(idParametricDecay) == 20,
    "Recovered idParametricDecay layout changed");

