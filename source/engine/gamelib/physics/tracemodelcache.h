#pragma once

#include "idlib/blockalloc_base.h"
#include "idlib/containers/hashindex.h"
#include "idlib/containers/list.h"
#include "idlib/geometry/tracemodel.h"
#include "idlib/text/str.h"

class idCollisionModel;
class idMaterial;

struct traceModelWater_t {
    idVec3 xyz;
    float weight;
};

// Reconstructed from PDB local types 14116/14121. Methods are introduced as
// their authoritative bodies are activated.
class idTraceModelCache {
public:
    struct trmCache_t {
        idTraceModel *trm;
        int refCount;
        float volume;
        idVec3 centerOfMass;
        idMat3 inertiaTensor;
        const idMaterial *material;
        idCollisionModel *collisionModel;
        bool hasWater;
        idList<traceModelWater_t, 54> waterPoints;

        // Materialized in the authoritative tracemodelcache.h dump.
        trmCache_t()
            : trm(nullptr), refCount(1), volume(0.0f), centerOfMass(),
              inertiaTensor(), material(nullptr), collisionModel(nullptr),
              hasWater(false), waterPoints(0) {
            centerOfMass.Zero();
            inertiaTensor[0].Zero();
            inertiaTensor[1].Zero();
            inertiaTensor[2].Zero();
        }
    };

    // Materialized in the authoritative tracemodelcache.h dump.
    idTraceModelCache()
        : mapName(), cacheAllocator(false), cache(0),
          hash(1024, 1024, TAG_HASHINDEX) {
    }

    int AllocTraceModel(const idTraceModel& traceModel,
        const idMaterial* material);
    void FreeTraceModel(int traceModelIndex);
    int CopyTraceModel(int traceModelIndex);
    void ClearTraceModelCache();

    const trmCache_t* GetEntry(const int traceModelIndex) const {
        return traceModelIndex >= 0 && traceModelIndex < cache.Num()
            ? cache[traceModelIndex]
            : nullptr;
    }

    trmCache_t* GetEntry(const int traceModelIndex) {
        return traceModelIndex >= 0 && traceModelIndex < cache.Num()
            ? cache[traceModelIndex]
            : nullptr;
    }

    void GetMassProperties(int traceModelIndex, float density, float& mass,
        idVec3& center, idMat3& inertia) const {
        const trmCache_t* const entry = GetEntry(traceModelIndex);
        if (entry == nullptr) {
            mass = 0.0f;
            center.Zero();
            inertia = idMat3(1.0f);
            return;
        }
        mass = entry->volume * density;
        center = entry->centerOfMass;
        inertia = entry->inertiaTensor;
        for (int row = 0; row < 3; ++row) {
            for (int column = 0; column < 3; ++column) {
                inertia[row][column] *= density;
            }
        }
    }

    idStr mapName;
    idBlockAlloc<trmCache_t, 64, 13> cacheAllocator;
    idList<trmCache_t *, 13> cache;
    idHashIndex hash;

private:
    void SetupWaterPoints(trmCache_t* entry);
};

static_assert(sizeof(traceModelWater_t) == 16,
    "Recovered traceModelWater_t ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idTraceModelCache::trmCache_t) == 88,
    "Recovered trace-model cache entry ABI changed");
static_assert(sizeof(idTraceModelCache) == 100,
    "Recovered idTraceModelCache ABI changed");
#endif
