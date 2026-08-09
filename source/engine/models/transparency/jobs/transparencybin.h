#pragma once

#include "idlib/math/plane.h"
#include "models/transparency/jobs/transparencyvert.h"

#include <cstdint>

constexpr int TRANSPARENCY_BIN_COLUMNS = 40;
constexpr int TRANSPARENCY_BIN_ROWS = 45;
constexpr int TRANSPARENCY_BIN_COUNT =
    TRANSPARENCY_BIN_COLUMNS * TRANSPARENCY_BIN_ROWS;
constexpr int TRANSPARENCY_BIN_RING_INDICES = 126;
constexpr int TRANSPARENCY_BIN_NODE_COUNT =
    TRANSPARENCY_BIN_COUNT + 4;

struct polygon_t {
    std::uint16_t points[15];
    std::uint16_t numPoints;
};

struct bin_t {
    int numIndices;
    std::uint16_t indices[TRANSPARENCY_BIN_RING_INDICES];
};

struct node_t {
    idPlane plane;
    int children[2];
};

struct deferredTransparencyBinParms_t {
    const idTransparencyVert* verts;
    int numVerts;
    const std::uint16_t* indices;
    int numIndices;

    idVec3 viewOrigin;
    idMat3 viewAxis;
    float fovX;
    float fovY;

    bin_t* bins;
    int numBins;
    node_t* nodes;
    int numNodes;

    idTransparencyVert* tempBinVerts;
    int numBinVerts;
    int maxBinVerts;
    int* vertexRemap;

    idTransparencyVert* binVerts;
    std::uint16_t* binIndices;
    int numBinIndices;
    int maxBinIndices;
};

// Subdivides the current view into the recovered 32-by-16-pixel bin grid,
// clips each input quad into that grid, and compacts the referenced vertices.
void BinQuads(deferredTransparencyBinParms_t* parms);

static_assert(sizeof(polygon_t) == 32,
    "Recovered transparency polygon ABI changed");
static_assert(sizeof(bin_t) == 256,
    "Recovered transparency bin ABI changed");
static_assert(sizeof(node_t) == 24,
    "Recovered transparency node ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(deferredTransparencyBinParms_t) == 120,
    "Recovered transparency-bin parameters ABI changed");
#endif
