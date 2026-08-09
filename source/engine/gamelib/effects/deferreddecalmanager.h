#pragma once

#include "cm/jobs/collisionquery.h"
#include "idlib/math/vector.h"

#include <cstdint>

class idClip;
class idMaterial;
class idRenderModelDecal;

#ifndef ID_CLIP_QUERY_DEFINED
#define ID_CLIP_QUERY_DEFINED
struct idClipQuery { std::uint64_t index; };
#endif

struct deferredDecalParams_t {
    const idMaterial* decalMat;
    float depth;
    idVec2 size;
    float angle;
    int lifetime;
    int fadetime;
    int fadeInEndTime;
};

class idDeferredDecalQuery {
public:
    idDeferredDecalQuery();
    void Reset();

    idClipQuery theQuery;
    deferredDecalParams_t decalParams;
    idVec3 origin;
    idVec3 normal;
};

class alignas(8) idDeferredDecalManager {
public:
    idDeferredDecalManager();

    void Init(idClip* clip_, idRenderModelDecal* decalModel_);
    void Shutdown();
    void AddDecalFromLineTrace(const deferredDecalParams_t* decalParameters,
        const idVec3& start, const idVec3& end, int clipMask);
    void AddDecalFromPoint(const deferredDecalParams_t* decalParameters,
        int time, const idVec3& origin, const idVec3& normal);
    void Update(int time);

    idDeferredDecalQuery lineQueries[16];
    int numLineQueries;
    idClip* clip;
    idRenderModelDecal* decalModel;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idClipQuery) == 8,
    "Recovered idClipQuery ABI changed");
static_assert(sizeof(deferredDecalParams_t) == 32,
    "Recovered deferred-decal parameters ABI changed");
static_assert(sizeof(idDeferredDecalQuery) == 64,
    "Recovered deferred-decal query ABI changed");
static_assert(sizeof(idDeferredDecalManager) == 1040,
    "Recovered idDeferredDecalManager ABI changed");
#endif
