#pragma once

#include "models/foliage/jobs/foliagegather.h"
#include "models/transparency/jobs/transparencyvert.h"

struct deferredFoliageGenParms_t {
    const foliageRenderView_t* viewData;
    const visibleInfluenceSpheres_t* visibleInfluenceSpheres;
    const std::int16_t* influenceSphereIndices;
    int maxInfluenceSphereIndices;
    const fm_subTreeBounds_t* subTreeBounds;
    const fm_subTreeData_t* subTreeData;
    int subTreeDataSize;
    const foliageIndex_t* foliageIndices;
    int maxFoliageIndices;
    int numJobsForIndices;
    int jobIndexForIndices;
    const foliageSubTreeStats_t* foliageCountsList;
    int foliageCountsIndex;
    float foliageStartFadeDist;
    float foliageSmallFadeDistMax;
    float foliageBigFadeDistMax;
    int numVertsAllocated;
    idTransparencyVert* verts;
    float* quadDepths;
    int* quadsUsed;
};

void CalculateFoliageBounds(const std::int16_t xyz[3],
    float uniformSizeScale, float quadWidth, float quadHeight,
    float widthVariance, float heightVariance, const idVec3& upVector,
    idBounds& bounds);
void CalculateFoliageBounds(const fm_foliage_t* foliage,
    const fm_attribute_t* attribute, idBounds& bounds);
int GetFoliageOffsetForSubTree(
    const foliageSubTreeStats_t* foliageCounts, int subTreeIndex);
int GetFoliageTotalCount(const foliageSubTreeStats_t* foliageCounts);
void GetFoliageOffsetAndCountForJob(int numJobs, int jobIndex,
    int totalCount, int& jobOffset, int& jobCount);
int BuildFoliageQuad(idTransparencyVert* vertices, float* quadDepth,
    unsigned int foliageIndex, const fm_foliage_t* foliage,
    const fm_attribute_t* attribute, const foliageRenderView_t* viewData,
    const influenceSphere_t* influenceSpheres,
    const std::int16_t* influenceSphereIndices,
    float foliageStartFadeDist, float foliageSmallFadeDistMax,
    float foliageBigFadeDistMax);
int GenFoliageForSubTree(const deferredFoliageGenParms_t* parameters,
    const foliageIndex_t* foliageIndices, int numFoliage,
    int vertexOffset);
void FoliageGatherJob(const deferredFoliageGatherParms_t* parameters);
void FoliageGenJob(const deferredFoliageGenParms_t* parameters);

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(deferredFoliageGenParms_t) == 80,
    "Recovered deferred foliage-generation ABI changed");
#endif
