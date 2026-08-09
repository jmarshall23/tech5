#pragma once

#include "idlib/text/str.h"

// Exact member order recovered as IDA local type 13110.
class idUniqueWarning {
public:
    idStr message;
    unsigned int count;

    idUniqueWarning()
        : count(0) {
    }
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idUniqueWarning) == 36,
    "Recovered idUniqueWarning ABI changed");
#endif

