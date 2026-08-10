#pragma once

#include "../entities/entityptr.h"

class idEntity;

struct idEncounterState {
    enum groupStates_t : int {
        DEFAULT = 0,
        NOTHING = 1,
        COMBAT = 2,
        AMBUSH = 3,
        SEARCH = 4,
        FLEE = 5
    };

    idEncounterState();

    groupStates_t state;
    idEntityPtr<idEntity> target;
};

static_assert(sizeof(idEncounterState) == 8,
    "Recovered encounter state ABI changed");
