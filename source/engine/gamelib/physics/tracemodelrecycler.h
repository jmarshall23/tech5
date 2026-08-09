#pragma once

#include "idlib/blockalloc_base.h"
#include "idlib/containers/hashindex.h"
#include "idlib/containers/list.h"
#include "idlib/containers/staticlist.h"
#include "idlib/geometry/tracemodel.h"
#include "idlib/text/atomicstring.h"

#include <cstdint>

struct idRecycledTraceModel {
    idTraceModel* trm;
    int index;

    idRecycledTraceModel() : trm(nullptr), index(-1) {}
};

class idTraceModelRecycler {
public:
    // Materialized in the authoritative tracemodelrecycler.h dump.
    idTraceModelRecycler() : allocator(false), allocated(0), free{} {}
    ~idTraceModelRecycler();

    void Shutdown();
    idRecycledTraceModel* GetTraceModel();
    void RecycleTraceModel(idRecycledTraceModel* recycledTrm, bool defer);
    void UpdateDeferredFreed();

    idBlockAlloc<idRecycledTraceModel, 64, 13> allocator;
    idList<idRecycledTraceModel*, 13> allocated;
    idList<idRecycledTraceModel*, 13> free[3];
};

class idDeclParticle;
class idRenderModel;
class idRenderModelParticle;

class idFXModelRecycler {
public:
    struct fxPrtModel_t {
        idRenderModelParticle* pmodel;
        const idDeclParticle* pDecl;
    };

    struct fxStaticModel_t {
        idRenderModel* rmodel;
        idAtomicString modelName;
    };

    idStaticList<fxPrtModel_t, 256> fxPrtModels;
    idHashIndex activePrtModelHash;
    idHashIndex inactivePrtModelHash;
    idStaticList<fxStaticModel_t, 64> fxStaticModels;
    idHashIndex activeStaticModelHash;
    idHashIndex inactiveStaticModelHash;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idRecycledTraceModel) == 8,
    "Recovered idRecycledTraceModel ABI changed");
static_assert(sizeof(idTraceModelRecycler) == 84,
    "Recovered idTraceModelRecycler ABI changed");
static_assert(sizeof(idFXModelRecycler::fxPrtModel_t) == 8,
    "Recovered FX particle recycler entry ABI changed");
static_assert(sizeof(idFXModelRecycler::fxStaticModel_t) == 8,
    "Recovered FX static recycler entry ABI changed");
#endif
