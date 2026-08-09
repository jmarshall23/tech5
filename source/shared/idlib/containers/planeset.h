#pragma once

// Recovered IDA enum ordinal 943.  The type belongs to this header in the
// Tungsten PDB even though later idTech trees group it with plane math.
enum planeSide_t : int {
    PLANESIDE_FRONT = 0,
    PLANESIDE_BACK = 1,
    PLANESIDE_ON = 2,
    PLANESIDE_CROSS = 3
};

static_assert(sizeof(planeSide_t) == 4, "Recovered planeSide_t ABI changed");

