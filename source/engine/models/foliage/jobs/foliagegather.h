#pragma once

#include "idlib/math/vector.h"
#include "models/foliage/foliagemodel.h"
#include "models/transparency/jobs/influencespheredata.h"

#include <cstdint>

struct foliageIndex_t {
    std::uint16_t foliageIndex;
    std::uint16_t influenceSphereOffset;
};

struct foliageSubTreeStats_t {
    int subTreeFoliageCount;
    int pad[3];
};

struct deferredFoliageGatherParms_t {
    const foliageRenderView_t* viewData;
    const visibleInfluenceSpheres_t* visibleInfluenceSpheres;
    const fm_subTreeBounds_t* subTreeBounds;
    const fm_subTreeTreeNodes_t* subTreeTreeNodes;
    int subTreeTreeNodesSize;
    int maxFoliageHeight;
    float foliageStartFadeDist;
    float foliageSmallFadeDistMax;
    foliageSubTreeStats_t* foliageCount;
    foliageIndex_t* foliageIndices;
    unsigned int maxFoliageIndices;
    std::int16_t* influenceSphereIndices;
    unsigned int maxInfluenceSphereIndices;
    int pad[3];
};

struct foliageGather_t {
    std::int16_t frustumVerts[3][8];
    const float* mvpMatrix;
    idVec3 viewDir;
    idVec3 viewOrg;
    foliageIndex_t* foliageIndices;
    unsigned int numFoliageIndices;
    unsigned int maxFoliageIndices;
    std::int16_t* influenceSphereIndices;
    unsigned int numInfluenceSphereIndices;
    unsigned int maxInfluenceSphereIndices;
    const influenceSphere_t* influenceSpheres;
    unsigned int influenceSphereStackSize;
    int influenceSphereStack[256];
    float foliageStartFadeDist;
    float foliageSmallFadeDistMax;
};

bool R_CullFoliageBoundsToMVP(const std::int16_t bounds[2][3],
    const float* mvpMatrix, idBounds& floatBounds);
void GatherFoliageIndicesForSubTree(
    const deferredFoliageGatherParms_t* parameters,
    int& numFoliageIndices, int& numInfluenceSphereIndices);

static_assert(sizeof(foliageIndex_t) == 4,
    "Recovered foliage-index ABI changed");
static_assert(sizeof(foliageSubTreeStats_t) == 16,
    "Recovered foliage subtree-statistics ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(foliageGather_t) == 1140,
    "Recovered foliage-gather ABI changed");
static_assert(sizeof(deferredFoliageGatherParms_t) == 64,
    "Recovered deferred foliage-gather ABI changed");
#endif
