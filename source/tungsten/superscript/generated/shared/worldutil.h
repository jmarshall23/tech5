#pragma once

#include "superscript/sys/ssobject_core.h"

// Source-visible portion of the generated world utility.  Generated
// reflection wrappers are tracked separately from worldutil.cpp's source
// routine and will be filled in by the generated-code recovery pass.
class ssWorldUtil : public idSuperScriptObject {
public:
    void Init() override;

    ssEntity world;
    ssEntity player1;
    ssEntity player2;
    ssEntity player3;
    ssEntity player4;
    ssEntity player5;
    ssEntity player6;
    ssEntity player7;
    ssEntity player8;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(ssWorldUtil) == 44,
    "Recovered ssWorldUtil ABI changed");
#endif
