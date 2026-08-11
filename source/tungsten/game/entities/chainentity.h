#pragma once

#include "entityptr.h"
#include "../../../shared/idlib/math/vector.h"
#include "../../../shared/idlib/text/str.h"

class idEntity;

// The enclosing entity runtime is still dependency-bound. These two nested
// definition records are complete PDB types and have independent constructors.
class idFuncChain {
public:
    struct binddef_t {
        binddef_t();

        idEntityPtr<idEntity> bindToObject;
        idStr bindToJoint;
        idStr bindToTag;
    };

    struct chaindef_t {
        chaindef_t();

        idVec3 startPosition;
        idVec3 endPosition;
        float extraLength;
        binddef_t startBindInfo;
        binddef_t endBindInfo;
        bool randomRotate;
        bool smoothSkinning;
        float startRotation;
    };
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idFuncChain::binddef_t) == 68,
    "Recovered chain binding definition ABI changed");
static_assert(sizeof(idFuncChain::chaindef_t) == 172,
    "Recovered chain definition ABI changed");
#endif
