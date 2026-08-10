#pragma once

#include "models/transparency/jobs/transparencyvert.h"

#include <cstdint>

struct transSortSegmentInfo_t {
    int segmentOffset;
    int quadsAllocated;
    int quadsUsed;
    bool emissivePass;
    std::uint8_t pad[3];
};

struct transSortResult_t {
    int numSortedQuads;
    int numCollapsedVerts;
    int numEmissiveQuads;
};

struct transSortParms_t {
    idTransparencyVert* verts;
    int numQuadsToSort;
    float* quadDepths;
    std::uint8_t* emissiveQuads;
    const transSortSegmentInfo_t* segmentInfo;
    int numSegmentAllocations;
    bool collapse;
    bool sort;
    std::uint8_t pad[2];
    std::uint16_t* indices;
    int maxIndices;
    std::uint16_t* indices2;
    int maxIndices2;
    transSortResult_t* sortResult;
};

int TransparencyTriIndGen(const transSortParms_t* parms, int quadOffset);
int TransparencyEmissiveTriIndGen(const transSortParms_t* parms,
    int quadOffset);
int TransparencySortQuads(const transSortParms_t* parms);

static_assert(sizeof(transSortSegmentInfo_t) == 16,
    "Recovered transparency-sort segment ABI changed");
static_assert(sizeof(transSortResult_t) == 12,
    "Recovered transparency-sort result ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(transSortParms_t) == 48,
    "Recovered transparency-sort parameters ABI changed");
#endif
