#pragma once

#include "gamelib/animstack/animstacktypes.h"
#include "idlib/containers/list.h"

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

// Straightforward heap-backed allocator recovered alongside the block-pool
// implementation. Nodes remain 16-byte aligned, matching the original
// animation job assumptions.
class idMD6Allocator_New : public idMD6Allocator {
public:
    idMD6Allocator_New() = default;
    ~idMD6Allocator_New() override;

    idMD6Node* Alloc(idMD6Node::nodeType_t type) override;
    void Free(idMD6Node* node) override;
    void Condense() override;
    unsigned int Size() override;
    int NumNodes() override;
    idMD6Node* NodeForIndex(int index) override;
    const idMD6Node* NodeForIndex(int index) const override;

    idList<idMD6Node*, 19> nodes;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idMD6Allocator) == 4,
    "Recovered idMD6Allocator ABI changed");
static_assert(sizeof(idMD6Allocator_New) == 20,
    "Recovered idMD6Allocator_New ABI changed");
#endif
