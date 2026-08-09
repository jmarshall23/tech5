#pragma once

#include "gamelib/animstack/animstacktypes.h"

class idMD6Allocator {
public:
    virtual ~idMD6Allocator();
    virtual idMD6Node* Alloc(idMD6Node::nodeType_t type) = 0;
    virtual void Free(idMD6Node* node) = 0;
    virtual void Condense() = 0;
    virtual unsigned int Size() = 0;
    virtual int NumNodes() = 0;
    virtual idMD6Node* NodeForIndex(int index) = 0;
    virtual const idMD6Node* NodeForIndex(int index) const = 0;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idMD6Allocator) == 4,
    "Recovered idMD6Allocator ABI changed");
#endif
