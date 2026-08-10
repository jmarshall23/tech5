#pragma once

#include "idlib/containers/list.h"
#include "idlib/typesafenumber.h"

enum gameTimeUnique_t : int;

struct idJobTimerIteration;

class idJobTimerManager {
public:
    bool active;
    idList<idJobTimerIteration, 5> iterations;
};

// PDB ordinal 17372.  The retail implementation accepts only positive rates
// and truncates 1000 / hertz to the integer game tick used by the framework.
class idTimeManager {
public:
    idTimeManager() : gameHz(60), gameTimePerFrame(16) {}
    void SetGameHz(int hertz);

    int gameHz;
    idTypesafeNumber<int, gameTimeUnique_t> gameTimePerFrame;
};

extern idTimeManager timeManager;

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idTimeManager) == 8, "Recovered idTimeManager ABI changed");
#endif
