#pragma once

#include "idlib/geometry/drawvert.h"
#include "models/water/watersurfacesim.h"

#include <cstdint>

struct deferredWaterBlockGenParms_t {
    float* currBlock;
    float* currBlockL;
    float* currBlockR;
    float* currBlockU;
    float* currBlockD;
    std::uint16_t blockLocX;
    std::uint16_t blockLocY;
    unsigned int* simulationParms;
    unsigned char* vertGradient;
    const waterDisturbanceParms_t* disturbances;
    unsigned int numDisturbances;
    float spacing;
    float speed;
    float damping;
    float timeDelta;
    idVec3 waterOrg;
    std::uint16_t gridWidth;
    std::uint16_t gridHeight;
    idDrawVert* verts;
    float* prevBlock;
};

void BlockToGridPos(int blockLocX, int blockLocY, int blockX,
    int blockY, int& gridX, int& gridY);
int GridPosToBlockLoc(int gridX, int gridY, int numBlocksX,
    int numBlocksY);
int BlockPosToBlockLoc(int blockX, int blockY, int numBlocksX);

void ApplyDisturbances(const deferredWaterBlockGenParms_t* parms);
void GenWaterSurface(const deferredWaterBlockGenParms_t* parms,
    const float* previousHeightMap);

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(deferredWaterBlockGenParms_t) == 80,
    "Recovered deferred-water block ABI changed");
#endif
