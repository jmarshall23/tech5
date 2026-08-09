#pragma once

#include "models/particles/jobs/particleparm.h"
#include "models/rendermodel.h"

class idDeclParticle;

class alignas(16) idRenderModelParticle : public idRenderModel {
public:
    struct stageCounts_t {
        int vertCount;
        int indexOffset;
    };

    using UpdateCallback = bool (*)(idRenderModelParticle* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);

    explicit idRenderModelParticle(
        const idDeclParticle* declaration = nullptr);
    ~idRenderModelParticle() override;

    static void SetUpdateCallback(UpdateCallback callback);
    static void DeclNameToModelName(const char* declarationName,
        idStr& modelName);
    static int EstimateVertAllocation(const idParticleStage* stage,
        int renderTime, float timeOffset, int stopTime, float deadTime,
        int lodLevel);
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;

    idList<deferredParticleGenParms_t, 5> genParms;
    particleRenderView_t* particleRenderView;
    modelParticleParms_t* modelParms;
    idList<stageCounts_t, 5> stageCounts[3];
    const idDeclParticle* particleDecl;

private:
    static UpdateCallback updateCallback;
};

static_assert(sizeof(idRenderModelParticle::stageCounts_t) == 8,
    "Recovered particle-stage count ABI changed");
