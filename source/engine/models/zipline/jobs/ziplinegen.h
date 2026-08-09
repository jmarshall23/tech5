#pragma once

#include "idlib/geometry/drawvert.h"
#include "models/zipline/jobs/nonuniformbspline.h"

#include <cstdint>

struct sweptPoint_t {
    idVec3 pos;
    idVec3 tangent;
    float s;
};

struct zipLineGenParms_t {
    const idNonUniformBSpline<idVec3>* controlSpline;
    int splineTessellationDistance;
    int splineMaxSubdivisions;
    int cableSubdivisions;
    float cableDiameter;
    const sweptPoint_t* sweptPoints;
    float time;
    float fractionBeforeLerp;
    bool downDirection;
    int maxVertices;
    int maxIndices;
    idDrawVert* vertices;
    std::uint16_t* indices;
    int* numVertices;
    int* numIndices;
};

void GenZipline(const zipLineGenParms_t* parms);

static_assert(sizeof(sweptPoint_t) == 28,
    "Recovered swept-point ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(zipLineGenParms_t) == 60,
    "Recovered zip-line generation parameters ABI changed");
#endif
