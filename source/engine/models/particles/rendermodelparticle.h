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
    using ViewExtractor = bool (*)(const idRenderView* currentView,
        const idRenderView* nextView, particleRenderView_t& particleView,
        idVec3& currentViewOrigin);
    using ModelParmsEvaluator = bool (*)(idRenderModelParticle* model,
        const idRenderView* currentView, const idRenderView* nextView,
        modelParticleParms_t& parms);
    using VisibleSpheresResolver = const visibleInfluenceSpheres_t* (*)();
    using ParticleJobSubmitCallback = bool (*)(
        const deferredParticleGenParms_t* parms,
        idRenderModelUpdateTools* tools);
    using BufferReferenceCallback = void (*)(idTriangles* geometry,
        int frameBufferIndex, int firstVertex, int firstIndex);
    using DistributionVolumeCallback = void (*)(
        const idRenderModelParticle* model, int stageIndex,
        int distributionType, const idVec3& center,
        const idVec3& extents, const idMat3& axis);

    explicit idRenderModelParticle(
        const idDeclParticle* declaration = nullptr);
    ~idRenderModelParticle() override;

    static void SetUpdateCallback(UpdateCallback callback);
    static void SetRuntimeCallbacks(ViewExtractor viewExtractor,
        ModelParmsEvaluator modelParmsEvaluator,
        VisibleSpheresResolver visibleSpheresResolver,
        ParticleJobSubmitCallback particleJobSubmit,
        BufferReferenceCallback bufferReference,
        DistributionVolumeCallback distributionVolume);
    static void DeclNameToModelName(const char* declarationName,
        idStr& modelName);
    static int EstimateVertAllocation(const idParticleStage* stage,
        int renderTime, float timeOffset, int stopTime, float deadTime,
        int lodLevel);
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;
    void DrawDistributionVolumes() const;

    idList<deferredParticleGenParms_t, 5> genParms;
    particleRenderView_t* particleRenderView;
    modelParticleParms_t* modelParms;
    idList<stageCounts_t, 5> stageCounts[3];
    const idDeclParticle* particleDecl;

private:
    static UpdateCallback updateCallback;
    static ViewExtractor viewExtractor;
    static ModelParmsEvaluator modelParmsEvaluator;
    static VisibleSpheresResolver visibleSpheresResolver;
    static ParticleJobSubmitCallback particleJobSubmitCallback;
    static BufferReferenceCallback bufferReferenceCallback;
    static DistributionVolumeCallback distributionVolumeCallback;
};

static_assert(sizeof(idRenderModelParticle::stageCounts_t) == 8,
    "Recovered particle-stage count ABI changed");
