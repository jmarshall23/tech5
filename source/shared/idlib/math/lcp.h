#pragma once

class idMatX;
class idVecX;
class idCmdArgs;

class idLCP {
public:
    virtual ~idLCP() = default;
    virtual bool Solve(const idMatX* matrix, idVecX* result,
        const idVecX* constants, const idVecX* lower,
        const idVecX* upper, const int* boxIndex,
        const float* ignored = nullptr) = 0;
    virtual void SetMaxIterations(const int maximum) { maxIterations = maximum; }
    virtual int GetMaxIterations() { return maxIterations; }

    static idLCP* AllocSymmetric();
    static void Test_f(const idCmdArgs& args);

    int maxIterations;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idLCP) == 8, "Recovered idLCP ABI changed");
#endif

