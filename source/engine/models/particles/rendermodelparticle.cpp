#include "models/particles/rendermodelparticle.h"

#include "models/particles/declparticle.h"
#include "models/particles/jobs/particlestage.h"

#include <algorithm>
#include <cstring>
#include <new>

idRenderModelParticle::UpdateCallback
    idRenderModelParticle::updateCallback = nullptr;

idRenderModelParticle::idRenderModelParticle(
    const idDeclParticle* declaration)
    : particleRenderView(nullptr), modelParms(nullptr),
      particleDecl(declaration) {
    g.noInteractions = 1;
    g.noShadow = 1;
    g.addAlways = 1;
    g.noGPUocclusionTest = 1;

    if (particleDecl != nullptr) {
        SetName(particleDecl->GetName());
        referenceBounds = particleDecl->bounds;
        const int stageCount = particleDecl->stages.Num();
        SetMaxSurfaces(stageCount);
        for (int index = 0; index < stageCount; ++index) {
            const idParticleStage* const stage = particleDecl->stages[index];
            if (stage == nullptr) continue;
            idTriangles* const geometry = new (std::nothrow) idTriangles();
            if (geometry == nullptr) continue;
            geometry->bounds = stage->bounds;
            geometry->vertexMask = 3167;
            idRenderModelSurface surface{};
            surface.material = stage->systemProperties.material;
            surface.materialNum = index;
            surface.geometry = geometry;
            surface.geometryIsReference = false;
            AddSurface(surface);
        }

        for (int pass = 0; pass < 3; ++pass) {
            stageCounts[pass].SetNum(stageCount);
            for (int index = 0; index < stageCount; ++index) {
                stageCounts[pass][index] = stageCounts_t{0, 0};
            }
        }
        genParms.SetNum(stageCount);
        for (int index = 0; index < stageCount; ++index) {
            std::memset(&genParms[index], 0, sizeof(genParms[index]));
        }
    }

    particleRenderView = new (std::nothrow) particleRenderView_t();
    modelParms = new (std::nothrow) modelParticleParms_t();
}

idRenderModelParticle::~idRenderModelParticle() {
    delete particleRenderView;
    delete modelParms;
    for (int index = 0; index < surfaces.Num(); ++index) {
        if (!surfaces[index].geometryIsReference) {
            delete surfaces[index].geometry;
            surfaces[index].geometry = nullptr;
        }
    }
}

void idRenderModelParticle::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

void idRenderModelParticle::DeclNameToModelName(
    const char* const declarationName, idStr& modelName) {
    modelName = declarationName != nullptr ? declarationName : "";
    modelName.SetFileExtension("prt");
}

int idRenderModelParticle::EstimateVertAllocation(
    const idParticleStage* stage, const int renderTime,
    const float timeOffset, const int stopTime, const float deadTime,
    const int lodLevel) {
    if (stage == nullptr || stage->hidden || stage->cycleMsec == 0
        || stage->systemProperties.totalParticles <= 0) {
        return 0;
    }
    const float lodFraction = (std::max)(0.0f, (std::min)(1.0f,
        stage->lodParms.lerpAmount * static_cast<float>(lodLevel)));
    const int totalParticles = (std::max)(0, static_cast<int>(
        stage->systemProperties.totalParticles
        + (stage->lodParms.totalParticles
            - stage->systemProperties.totalParticles) * lodFraction));
    const int cycle = (std::max)(1, static_cast<int>(
        (stage->maxParticleLife + deadTime) * 1000.0f));
    const int particleLife = static_cast<int>(
        stage->maxParticleLife * 1000.0f);
    const int bunch = static_cast<int>(stage->systemProperties.spawnBunching
        * stage->bunchTime * 1000.0f);
    const int stageTime = renderTime - static_cast<int>(
        (stage->systemProperties.timeOffset + timeOffset) * 1000.0f);
    int vertices = 0;
    for (int index = 0; index < totalParticles; ++index) {
        const int age = stageTime
            - (bunch * index) / stage->systemProperties.totalParticles;
        if (age < 0) continue;
        const int cycleIndex = age / cycle;
        if (stage->systemProperties.cycles > 0
            && cycleIndex >= stage->systemProperties.cycles) {
            continue;
        }
        const int cycleAge = age % cycle;
        if (cycleAge <= particleLife
            && (stopTime == 0 || renderTime - cycleAge < stopTime)) {
            vertices += stage->NumVertsPerParticle();
        }
    }
    return vertices;
}

bool idRenderModelParticle::UpdateInView(const idRenderView* currentView,
    const idRenderView* nextView, idRenderModelUpdateTools* tools) {
    return updateCallback != nullptr
        ? updateCallback(this, currentView, nextView, tools)
        : false;
}
