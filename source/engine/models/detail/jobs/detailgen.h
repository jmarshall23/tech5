#pragma once

#include "models/detail/detailmodeldata.h"
#include "models/detail/jobs/detailgather.h"
#include "models/rendermodel.h"

struct detailPalette_t {
    const detailPaletteEntry_t* entry;
    const detailPaletteVert_t* verts;
    const std::uint16_t* indices;
};

struct deferredDetailGenParms_t {
    const detailRenderView_t* viewData;
    const dm_subTreeBounds_t* subTreeBounds;
    const dm_subTreeData_t* subTreeData;
    int subTreeDataSize;
    const std::uint16_t* detailIndices;
    int maxDetailIndices;
    int numJobsForIndices;
    int jobIndexForIndices;
    const detailSubTreeStats_t* detailCountsList;
    int detailCountsIndex;
    const detailPaletteEntry_t* paletteEntries;
    int paletteEntriesSize;
    const detailPaletteVert_t* paletteVerts;
    int paletteVertsSize;
    const std::uint16_t* paletteIndices;
    int paletteIndicesSize;
    int numVertsAllocated;
    idDrawVert* verts;
    std::uint16_t* indices;
    detailGenTotals_t* totalsUsed;
};

void CalculateDetailBounds(const dm_detail_t* detail,
    const idDetailPaletteData* data, idBounds& bounds);
void GetDetailTotalCount(const detailSubTreeStats_t* detailCounts,
    detailGenTotals_t* totals);
void GetDetailOffsetsForSubTree(
    const detailSubTreeStats_t* detailCounts, int subTreeIndex,
    int& vertexOffset, int& indexOffset);
void BuildDetailModel(const detailPalette_t& palette,
    idDrawVert* vertices, std::uint16_t* indices, int indexOffset,
    const dm_detail_t* detail, const dm_attribute_t* attribute,
    detailGenTotals_t& totals);
int GenDetailForSubTree(const deferredDetailGenParms_t* parameters,
    const std::uint16_t* detailIndices, int numDetails,
    int vertexBufferOffset, int indexBufferOffset, int indexOffset,
    detailGenTotals_t& totals);
void DetailGatherJob(const deferredDetailGatherParms_t* parameters);
void DetailGenJob(const deferredDetailGenParms_t* parameters);

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(deferredDetailGenParms_t) == 80,
    "Recovered deferred detail-generation ABI changed");
#endif
