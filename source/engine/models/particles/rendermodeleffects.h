#pragma once

#include "models/particles/jobs/particleparm.h"
#include "models/rendermodel.h"

class idRenderModelEffects : public idRenderModel {
public:
    struct sortedParticleStage_t {
        const idParticleStage* stage;
        int first;
        int num;
    };

    struct deferredStage_t {
        const idMaterial* mtr;
        int vertCount;
        int indexOffset;
    };

    using UpdateCallback = bool (*)(idRenderModelEffects* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);
    using ViewExtractor = bool (*)(const idRenderView* currentView,
        const idRenderView* nextView, particleRenderView_t& particleView,
        idVec3& currentViewOrigin);
    using VisibleSpheresResolver = const visibleInfluenceSpheres_t* (*)();
    using ParticleJobSubmitCallback = bool (*)(
        const deferredParticleGenParms_t* parms,
        idRenderModelUpdateTools* tools);
    using BufferReferenceCallback = void (*)(idTriangles* geometry,
        int frameBufferIndex, int firstVertex, int firstIndex);
    using ShadowSampleCallback = float (*)(
        const idRenderModelEffects* model, const idVec3& position);

    idRenderModelEffects();
    ~idRenderModelEffects() override;

    static void Init();
    static void Shutdown();
    static void StartFrame();
    static void EndFrame();
    static void SetUpdateCallback(UpdateCallback callback);
    static void SetRuntimeCallbacks(ViewExtractor viewExtractor,
        VisibleSpheresResolver visibleSpheresResolver,
        ParticleJobSubmitCallback particleJobSubmit,
        BufferReferenceCallback bufferReference,
        ShadowSampleCallback shadowSample);
    static void SetParticleTrailTimeStep(int milliseconds);
    static int EstimateQuadAllocation(const idParticleStage* stage,
        const effectParticleParms_t* particle, int renderTime);
    bool CommitSubclass() override;
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;

    void AddDecal(const idMaterial* material,
        const idDrawVert& v0, const idDrawVert& v1,
        const idDrawVert& v2, const idDrawVert& v3,
        int startTime, int lifeTime, int fadeInEndTime,
        int fadeOutStartTime);
    void AddTracer(const idMaterial* material, const idVec3& origin,
        const idVec3& direction, const idVec3& maximumDistance,
        float speed, float length, float height, bool ensureVisual,
        float fractionInsured, float lifeTime);
    bool AddParticles(const idDeclParticle* particle, int systemStartTime,
        int gameMillisecondsPerFrame, float diversity,
        const idVec3& origin, const idMat3& axis,
        const idVec3& velocity, const unsigned int& color);
    bool AddParticleTrail(const idDeclParticle* particle,
        const idVec3& startPosition, const idVec3& direction,
        int startTime, int endTime);
    void Update(int newTime, int gameMillisecondsPerFrame);
    void SortEffectParticles();

    effectParticleParms_t* particles;
    int particleRange[2];
    particleTrailParms_t* particleTrails;
    int particleTrailRange[2];
    tracerParms_t* tracers;
    int tracerRange[2];
    decalParms_t* decals;
    decalVerts_t* decalVerts;
    int decalRange[2];
    int gameTime;
    int deltaTime;
    int latchedTime;
    int lastLatchedParticleRange[2];
    int latchedParticleRange[2];
    int latchedTracerRange[2];
    int latchedDecalRange[2];
    sortedParticleStage_t sortedParticleStages[1024];
    int numSortedParticleStages;
    particleRenderView_t* particleRenderView;
    deferredParticleGenParms_t* particleGenParms;
    idList<deferredStage_t, 5> deferredStages[3];
    idTriangles* triangles;

private:
    static constexpr int MAX_EFFECT_PARTICLES = 4096;
    static constexpr int MAX_PARTICLE_TRAILS = 32;
    static constexpr int MAX_TRACERS = 128;
    static constexpr int MAX_DECALS = 1024;
    static constexpr int MAX_PARTICLE_GEN_PARMS = 4096;
    static constexpr int MAX_EFFECT_TRIANGLES = 1024;

    static UpdateCallback updateCallback;
    static ViewExtractor viewExtractor;
    static VisibleSpheresResolver visibleSpheresResolver;
    static ParticleJobSubmitCallback particleJobSubmitCallback;
    static BufferReferenceCallback bufferReferenceCallback;
    static ShadowSampleCallback shadowSampleCallback;
    static int particleTrailTimeStep;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idRenderModelEffects::sortedParticleStage_t) == 12,
    "Recovered sorted-particle stage ABI changed");
static_assert(sizeof(idRenderModelEffects::deferredStage_t) == 12,
    "Recovered deferred-stage ABI changed");
#endif
