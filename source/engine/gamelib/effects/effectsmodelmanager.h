#pragma once

#include "idlib/containers/hashindex.h"
#include "idlib/containers/staticlist.h"

class idDeclParticle;
class idRenderModelParticle;

class idEffectsModelManager {
public:
    struct fxPrtModel_t {
        idRenderModelParticle* pmodel;
        const idDeclParticle* pDecl;
    };

    idEffectsModelManager();
    ~idEffectsModelManager();

    void Init();
    void Shutdown();
    idRenderModelParticle* GetNextParticleEffectModel(
        const idDeclParticle* particleDecl);
    void RecycleParticleFxModel(const idDeclParticle* particleDecl,
        idRenderModelParticle* model);

    idStaticList<fxPrtModel_t, 400> fxPrtModels;
    idHashIndex activePrtModelHash;
    idHashIndex inactivePrtModelHash;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idEffectsModelManager::fxPrtModel_t) == 8,
    "Recovered particle-model record ABI changed");
static_assert(sizeof(idEffectsModelManager) == 3280,
    "Recovered idEffectsModelManager ABI changed");
#endif
