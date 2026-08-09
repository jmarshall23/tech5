#pragma once

#include "idlib/containers/list.h"

class idDeclRenderParm;
class idDeclRenderProg;
class idImage;

enum threadId_t : int {
    THREAD_INVALID = 0,
    THREAD_MAIN = 1,
    THREAD_RENDERER = 2
};

struct expOp_t {
    unsigned short type;
    short parmIndexDest;
    short parmIndexA;
    short parmIndexB;
};

union parmValue_t {
    float value[4];
    const idImage* image;
    const idDeclRenderProg* program;
    const char* string;
    int swizzle[4];
};

class alignas(4) idParmBlock {
public:
    explicit idParmBlock(threadId_t ownerThread = THREAD_MAIN)
        : ops(16), constants(16), thread(ownerThread), usingTempOps(false) {}

    idList<expOp_t, 56> ops;
    idList<parmValue_t, 56> constants;
    threadId_t thread;
    bool usingTempOps;
};

template<int capacity>
class idStaticParmBlock : public idParmBlock {
public:
    expOp_t staticOps[capacity];
    alignas(16) parmValue_t staticConstants[capacity];
};

static_assert(sizeof(expOp_t) == 8, "Recovered parm operation ABI changed");
static_assert(sizeof(parmValue_t) == 16,
    "Recovered parm value ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idParmBlock) == 40,
    "Recovered parameter-block ABI changed");
#endif
