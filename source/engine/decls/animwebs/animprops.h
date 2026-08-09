#pragma once

#include "gamelib/animstack/animstacktypes.h"

class idDeclMD6;

// Compact animation selection record used by recovered animweb blend nodes.
class idMD6AnimProps {
public:
    idMD6AnimProps()
        : anim(nullptr), aliasHandle(), wrap(idMD6Leaf::WRAP_CLAMP),
          rate(1.0f), tags(0) {}

    void SetAliasHandle(idAnimAliasHandle handle);
    void SetAnim(const idMD6Anim* animation);
    const idMD6Anim* SelectAnim(const idDeclMD6* modelDeclaration,
        int index) const;
    const idMD6Anim* SelectAndLoadAnim(const idDeclMD6* modelDeclaration,
        int index) const;

    const idMD6Anim* anim;
    idAnimAliasHandle aliasHandle;
    idMD6Leaf::wrapMode_t wrap;
    float rate;
    unsigned int tags;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idMD6AnimProps) == 20,
    "Recovered MD6 animation-properties ABI changed");
#endif
