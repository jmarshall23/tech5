#pragma once

#include "../../../shared/idlib/containers/staticlist.h"

class idProp_Spawnable;

class idSpawnablePropManager {
public:
    struct spawnables_t {
        spawnables_t();

        idStaticList<idProp_Spawnable*, 4> entity;
        int next;
    };

    idStaticList<spawnables_t, 8> spawnable;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idSpawnablePropManager::spawnables_t) == 36,
    "Recovered spawnable-prop bucket ABI changed");
#endif
