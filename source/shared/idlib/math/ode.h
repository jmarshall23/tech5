#pragma once

typedef void (*idODEDeriveFunction)(float time, const void* userData,
    const float* state, float* derivatives);

class idODE {
public:
    idODE(const int stateDimension, idODEDeriveFunction deriveFunction,
            const void* data)
        : dimension(stateDimension), derive(deriveFunction), userData(data) {}
    virtual ~idODE() = default;
    virtual float Evaluate(const float* state, float* newState,
        float time, float timeStep) = 0;

    int dimension;
    idODEDeriveFunction derive;
    const void* userData;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idODE) == 16, "Recovered idODE ABI changed");
#endif

