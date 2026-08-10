#pragma once

#include "entity.h"
#include "vector.h"

class idRenderModel;

class idTraceOpts {
public:
    float radius;
    bool skipInvisible;
    bool skipTranslucent;
    bool skipDynamic;
    bool twoSided;
    idRenderModel* skipModel;
};

int Tungsten_TraceSuperScriptPoints(const ssVector& start,
    const ssVector& end, int contentMask, int ignoredSpawnId);
void Tungsten_GetSuperScriptTraceResults(int clipQueryId, float& hitFraction,
    ssVector& hitNormal, int& hitSpawnId);

class ssTrace {
public:
    ssTrace(ssVector start, ssVector end, int contentMask, ssEntity ignoreEnt);

    void Resolve();

    ssVector startPos;
    ssVector endPos;
    ssVector rayDir;
    int contentMask;
    ssEntity ignoreEnt;
    float length;
    int clipQueryId;
    bool resolved;
    ssEntity hitEnt;
    ssVector hitPos;
    ssVector hitNormal;
    float hitFraction;
    float hitLength;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idTraceOpts) == 12,
    "Recovered idTraceOpts ABI changed");
static_assert(sizeof(ssTrace) == 92, "Recovered ssTrace ABI changed");
#endif
