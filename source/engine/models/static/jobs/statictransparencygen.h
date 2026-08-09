#pragma once

#include "models/transparency/jobs/transparencyvert.h"

#include "idlib/geometry/drawvert.h"
#include "idlib/math/matrix.h"
#include "idlib/math/vector.h"

struct lightContribution_t;
struct ambientMap_t;
struct shadowMap_t;
class idRenderLightCommitted;
enum lightingModel_t : int;

#include "renderer/jobs/approximatelighting/approximatelighting.h"

struct staticTransparencyGenParms_t {
    const idDrawVert* inputVerts;
    int numInputVerts;
    float fadeStartDist;
    float fadeMaxDist;
    idVec3 origin;
    idMat3 axis;
    idVec3 viewOrg;
    idVec3 viewDir;
    idVec4 transSortScaleBias;
    approximateLighting_t lighting;
    idTransparencyVert* verts;
    float* quadDepth;
    int* quadsUsed;
};

void StaticTransparencyGenJob(const staticTransparencyGenParms_t* parms);

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(staticTransparencyGenParms_t) == 260,
    "Recovered static-transparency job parameters ABI changed");
#endif
