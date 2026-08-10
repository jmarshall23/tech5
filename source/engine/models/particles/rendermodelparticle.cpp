#include "models/particles/rendermodelparticle.h"

#include "models/particles/declparticle.h"
#include "models/particles/jobs/particlegen.h"
#include "models/particles/jobs/particlestage.h"
#include "models/transparency/rendermodeltransparency.h"

#include <algorithm>
#include <cstring>
#include <new>

idRenderModelParticle::UpdateCallback
    idRenderModelParticle::updateCallback = nullptr;
idRenderModelParticle::ViewExtractor
    idRenderModelParticle::viewExtractor = nullptr;
idRenderModelParticle::ModelParmsEvaluator
    idRenderModelParticle::modelParmsEvaluator = nullptr;
idRenderModelParticle::VisibleSpheresResolver
    idRenderModelParticle::visibleSpheresResolver = nullptr;
idRenderModelParticle::ParticleJobSubmitCallback
    idRenderModelParticle::particleJobSubmitCallback = nullptr;
idRenderModelParticle::BufferReferenceCallback
    idRenderModelParticle::bufferReferenceCallback = nullptr;
idRenderModelParticle::DistributionVolumeCallback
    idRenderModelParticle::distributionVolumeCallback = nullptr;

idRenderModelParticle::idRenderModelParticle(
    const idDeclParticle* declaration)
    : particleRenderView(nullptr), modelParms(nullptr),
      particleDecl(declaration) {
    g.noInteractions = 1;
    g.noShadow = 1;
    g.alwaysOcclusionCullBounds = 1;
    g.noStippleFade = 1;

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

void idRenderModelParticle::SetRuntimeCallbacks(
        const ViewExtractor extractor,
        const ModelParmsEvaluator parmsEvaluator,
        const VisibleSpheresResolver spheresResolver,
        const ParticleJobSubmitCallback jobSubmit,
        const BufferReferenceCallback bufferReference,
        const DistributionVolumeCallback distributionVolume) {
    viewExtractor = extractor;
    modelParmsEvaluator = parmsEvaluator;
    visibleSpheresResolver = spheresResolver;
    particleJobSubmitCallback = jobSubmit;
    bufferReferenceCallback = bufferReference;
    distributionVolumeCallback = distributionVolume;
}

void idRenderModelParticle::DeclNameToModelName(
    const char* const declarationName, idStr& modelName) {
    modelName = declarationName != nullptr ? declarationName : "";
    modelName.SetFileExtension("prt");
}

void idRenderModelParticle::DrawDistributionVolumes() const {
    if (distributionVolumeCallback == nullptr || particleDecl == nullptr ||
        modelParms == nullptr) {
        return;
    }
    const idLookupTable* const tables = particleDecl->GetTables();
    for (int index = 0; index < particleDecl->stages.Num(); ++index) {
        const idParticleStage* const stage = particleDecl->stages[index];
        if (stage == nullptr) continue;
        idVec3 localOffset;
        idVec3 extents;
        for (int axis = 0; axis < 3; ++axis) {
            localOffset[axis] = stage->offset.offset[axis].GetMaxParmVal(
                tables);
            extents[axis] = std::fabs(
                stage->distribution.size[axis].GetMaxParmVal(tables) *
                modelParms->distribScale[axis]);
        }
        const idVec3 center = modelParms->origin +
            modelParms->axis * localOffset;
        distributionVolumeCallback(this, index,
            static_cast<int>(stage->distribution.type), center, extents,
            modelParms->axis);
    }
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
    const int cycle = static_cast<int>(
        (stage->maxParticleLife + deadTime) * 1000.0f);
    if (cycle <= 0) return 0;
    const int particleLife = static_cast<int>(
        stage->maxParticleLife * 1000.0f);
    const int bunch = static_cast<int>(stage->systemProperties.spawnBunching
        * stage->bunchTime * 1000.0f);
    const int stageTime = static_cast<int>((renderTime * 0.001f
        - (stage->systemProperties.timeOffset + timeOffset)) * 1000.0f);
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
    if (updateCallback != nullptr) {
        return updateCallback(this, currentView, nextView, tools);
    }
    if (particleDecl == nullptr || particleRenderView == nullptr ||
        modelParms == nullptr) {
        return false;
    }

    std::memset(particleRenderView, 0, sizeof(*particleRenderView));
    particleRenderView->atlasWidth = 1;
    particleRenderView->atlasHeight = 1;
    idVec3 currentViewOrigin;
    currentViewOrigin.Zero();
    if (viewExtractor != nullptr) {
        viewExtractor(currentView, nextView, *particleRenderView,
            currentViewOrigin);
    }

    std::memset(modelParms, 0, sizeof(*modelParms));
    modelParms->coverage = 1.0f;
    modelParms->color.Set(1.0f, 1.0f, 1.0f, 1.0f);
    modelParms->wind.Set(0.0f, 0.0f, 0.0f, 0.0f);
    modelParms->distribScale.Set(1.0f, 1.0f, 1.0f);
    modelParms->origin = useDeferredPosition ? deferredOrigin : g.origin;
    modelParms->axis = useDeferredPosition ? deferredAxis : g.axis;
    modelParms->scale = g.scale;
    modelParms->shadow = 1.0f;
    modelParms->alphaScaleOverride = 1.0f;
    if (modelParmsEvaluator != nullptr) {
        modelParmsEvaluator(this, currentView, nextView, *modelParms);
    }

    const float distance = std::sqrt(
        (currentViewOrigin - modelParms->origin).LengthSqr());
    if (g.maxVisibleRange > 0.0f && g.fadeVisibilityOver > 0.0f &&
        g.maxVisibleRange > g.fadeVisibilityOver) {
        const float visibility = (std::max)(0.0f, (std::min)(1.0f,
            1.0f - (distance - g.fadeVisibilityOver) /
                (g.maxVisibleRange - g.fadeVisibilityOver)));
        modelParms->coverage *= visibility;
    } else if (g.fadeVisibilityOver < 0.0f) {
        const float range = -g.fadeVisibilityOver;
        modelParms->coverage *= (std::max)(0.0f, (std::min)(1.0f,
            (distance - range) / range));
    }

    const int currentBuffer =
        idRenderModelTransparency::GetCurrentFrameBufferIndex();
    const int displayBuffer = (currentBuffer + 2) % 3;
    idTransparencyVert* const displayVertices =
        idRenderModelTransparency::GetUnsortedVertices(displayBuffer);
    const std::uint16_t* const displayIndices =
        idRenderModelTransparency::GetUnsortedIndices();
    const int stageCount = particleDecl->stages.Num();
    for (int stageIndex = 0; stageIndex < stageCount; ++stageIndex) {
        if (stageIndex >= surfaces.Num()) break;
        idRenderModelSurface& surface = surfaces[stageIndex];
        idTriangles* const geometry = surface.geometry;
        if (geometry == nullptr) continue;
        geometry->numVerts = 0;
        geometry->numIndexes = 0;
        surface.material = nullptr;
        const idParticleStage* const stage =
            particleDecl->stages[stageIndex];
        const stageCounts_t& counts =
            stageCounts[displayBuffer][stageIndex];
        if (stage == nullptr || stage->hidden ||
            stage->isTransparencySorted ||
            stage->systemProperties.material == nullptr ||
            stage->cycleMsec == 0 || counts.vertCount <= 0) {
            continue;
        }
        const int firstVertex = (counts.indexOffset / 6) * 4;
        surface.material = stage->systemProperties.material;
        geometry->bounds = stage->bounds;
        geometry->bounds[0] = geometry->bounds[0] -
            modelParms->distribScale;
        geometry->bounds[1] = geometry->bounds[1] +
            modelParms->distribScale;
        geometry->numVerts = counts.vertCount;
        geometry->numIndexes = 6 * (counts.vertCount / 4);
        geometry->verts = reinterpret_cast<idDrawVert*>(displayVertices);
        geometry->indexes = const_cast<std::uint16_t*>(
            displayIndices + counts.indexOffset);
        if (bufferReferenceCallback != nullptr) {
            bufferReferenceCallback(geometry, displayBuffer,
                firstVertex, counts.indexOffset);
        }
    }

    const visibleInfluenceSpheres_t* const visibleSpheres =
        visibleSpheresResolver != nullptr
            ? visibleSpheresResolver() : nullptr;
    for (int stageIndex = 0; stageIndex < stageCount; ++stageIndex) {
        stageCounts[currentBuffer][stageIndex] = stageCounts_t{0, 0};
        const idParticleStage* const stage =
            particleDecl->stages[stageIndex];
        if (stage == nullptr || stage->hidden || stage->cycleMsec == 0 ||
            stage->systemProperties.material == nullptr) {
            continue;
        }
        idRandom2 random(static_cast<unsigned int>(modelParms->diversity));
        const float deadTime = stage->systemProperties.deadTime.Compute(
            particleDecl->GetTables(), 1.0f, random);
        int vertCount = EstimateVertAllocation(stage,
            particleRenderView->renderTime, modelParms->timeOffset,
            modelParms->stopTime, deadTime, modelParms->lod);
        vertCount = (std::min)(vertCount, 512);
        vertCount &= ~3;
        if (vertCount <= 0) continue;

        deferredParticleGenParms_t& generation = genParms[stageIndex];
        std::memset(&generation, 0, sizeof(generation));
        generation.renderView = particleRenderView;
        generation.modelParticleParms = modelParms;
        generation.stage = stage;
        generation.tables = particleDecl->GetTables();
        generation.staticVerts = stage->staticVerts;
        generation.visibleInfluenceSpheres = visibleSpheres;
        generation.numModelParticleParms = 1;
        generation.numTables = particleDecl->tables.Num();
        generation.staticVertsSize = stage->numStaticVerts;
        generation.deadTime = deadTime;
        generation.maxVertsToGen = vertCount;

        bool allocated = false;
        if (stage->isTransparencySorted) {
            allocated = idRenderModelTransparency::AllocateQuadSegment(
                vertCount / 4, generation.verts, generation.quadDepth,
                generation.quadsUsed, stage->hasEmissivePass != 0);
        } else {
            allocated = idRenderModelTransparency::
                AllocateUnsortedQuadSegment(vertCount / 4,
                    generation.verts,
                    stageCounts[currentBuffer][stageIndex].indexOffset,
                    stageCounts[currentBuffer][stageIndex].vertCount);
        }
        if (!allocated) continue;
        if (particleJobSubmitCallback == nullptr ||
            !particleJobSubmitCallback(&generation, tools)) {
            ParticleGenJob(&generation);
        }
    }
    return true;
}
