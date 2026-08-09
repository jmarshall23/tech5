#pragma once

#include "models/detail/detailmodel.h"

#include <cstdint>

struct detailSubTreeStats_t {
    int subTreeDetailCount;
    int vertCount;
    int indexCount;
    int pad;
};

struct detailGenTotals_t {
    int totalVerts;
    int totalIndices;
    int pad[2];
};

struct deferredDetailGatherParms_t {
    const detailRenderView_t* viewData;
    const dm_subTreeBounds_t* subTreeBounds;
    const dm_subTreeTreeNodes_t* subTreeTreeNodes;
    int subTreeTreeNodesSize;
    int maxDetailHeight;
    detailSubTreeStats_t* detailCount;
    std::uint16_t* detailIndices;
    unsigned int maxDetailIndices;
};

struct detailGather_t {
    std::int16_t frustumVerts[3][8];
    int maxDetailHeight;
    const float* mvpMatrix;
    std::uint16_t* detailIndices;
    unsigned int maxDetailIndices;
    unsigned int numDetailIndices;
    unsigned int vertCount;
    unsigned int indexCount;
};

bool R_CullDetailBoundsToMVP(const dm_subTreeBounds_t& bounds,
    int maxDetailHeight, const float* mvpMatrix);
void GetDetailRenderListForView(dm_subTreeTreeNodePtrs_t& subTreePointers,
    const dm_subTreeBounds_t& bounds, detailGather_t& gather,
    int nodeNumber = 0);
void GatherDetailIndicesForSubTree(
    const deferredDetailGatherParms_t* parameters,
    int& numDetailIndices);

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(detailGather_t) == 76,
    "Recovered detail-gather ABI changed");
static_assert(sizeof(detailSubTreeStats_t) == 16,
    "Recovered detail subtree-statistics ABI changed");
static_assert(sizeof(detailGenTotals_t) == 16,
    "Recovered detail generation-total ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(deferredDetailGatherParms_t) == 32,
    "Recovered deferred detail-gather ABI changed");
#endif
#endif
