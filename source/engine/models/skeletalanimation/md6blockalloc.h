#pragma once

#include "models/skeletalanimation/md6allocator.h"
#include "idlib/containers/list.h"

struct idMD6RecoveredBlockState {
    void* blocks;
    void* free;
    int total;
    int active;
    bool allowAllocs;
    bool clearAllocs;
};

class idMD6BlockAlloc : public idMD6Allocator {
public:
    idMD6BlockAlloc();
    ~idMD6BlockAlloc() override;
    idMD6Node* Alloc(idMD6Node::nodeType_t type) override;
    void Free(idMD6Node* node) override;
    void DeferredFree();
    void Condense() override;
    unsigned int Size() override;
    int NumNodes() override;
    idMD6Node* NodeForIndex(int index) override;
    const idMD6Node* NodeForIndex(int index) const override;

    idMD6RecoveredBlockState playLeaves;
    idMD6RecoveredBlockState pauseLeaves;
    idMD6RecoveredBlockState branches;
    idMD6RecoveredBlockState blendBranches;
    idMD6RecoveredBlockState blendAdditiveBranches;
    idMD6RecoveredBlockState fusionBranches;
    idMD6RecoveredBlockState bestLeaves;
    idMD6RecoveredBlockState tagFilters;
    idList<idMD6Node*, 18> nodes;
    idList<idMD6Node*, 18> nodesToDelete;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idMD6RecoveredBlockState) == 20,
    "Recovered MD6 block state ABI changed");
static_assert(sizeof(idMD6BlockAlloc) == 196,
    "Recovered idMD6BlockAlloc ABI changed");
#endif
