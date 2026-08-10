#include "models/particles/rendermodeleffects.h"

#include "models/particles/declparticle.h"
#include "models/particles/jobs/particlegen.h"
#include "models/particles/jobs/particlestage.h"
#include "models/transparency/rendermodeltransparency.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <new>
#include <vector>

namespace {

constexpr int MAX_EFFECT_FRAME_VERTS = 8192;
constexpr int MAX_EFFECT_FRAME_INDICES = 12288;

struct effectFrameStorage_t {
    std::vector<idDrawVert> vertices[2];
    std::vector<std::uint16_t> indices;
    int mappedBufferIndex = 0;
    int vertOffset = 0;
    int indexOffset = 0;
    bool initialized = false;
};

effectFrameStorage_t effectFrameStorage;

idVec3 Normalize(const idVec3& value, const idVec3& fallback) {
    const float lengthSquared = value.LengthSqr();
    return lengthSquared > 1.0e-20f
        ? value * (1.0f / std::sqrt(lengthSquared)) : fallback;
}

void InitializeEffectVertex(idDrawVert& vertex, const idVec3& position,
        const float s, const float t, const idVec3& normal,
        const idVec3& tangent, const std::uint8_t alpha = 255) {
    std::memset(&vertex, 0, sizeof(vertex));
    vertex.xyz = position;
    vertex.st.Set(s, t);
    vertex.SetNormal(normal);
    vertex.SetTangent(tangent);
    vertex.SetBiTangent(normal.Cross(tangent));
    vertex.color[0] = 255;
    vertex.color[1] = 255;
    vertex.color[2] = 255;
    vertex.color[3] = alpha;
}

bool AllocateEffectGeometry(const int numVertices, const int numIndices,
        int& firstVertex, int& firstIndex) {
    if (!effectFrameStorage.initialized || numVertices <= 0 ||
        numIndices <= 0 ||
        effectFrameStorage.vertOffset + numVertices >
            MAX_EFFECT_FRAME_VERTS ||
        effectFrameStorage.indexOffset + numIndices >
            MAX_EFFECT_FRAME_INDICES) {
        return false;
    }
    firstVertex = effectFrameStorage.vertOffset;
    firstIndex = effectFrameStorage.indexOffset;
    effectFrameStorage.vertOffset += numVertices;
    effectFrameStorage.indexOffset += numIndices;
    return true;
}

void WriteQuadIndices(std::uint16_t* const output,
        const int relativeVertex) {
    const std::uint16_t base = static_cast<std::uint16_t>(relativeVertex);
    output[0] = base;
    output[1] = static_cast<std::uint16_t>(base + 2);
    output[2] = static_cast<std::uint16_t>(base + 3);
    output[3] = base;
    output[4] = static_cast<std::uint16_t>(base + 3);
    output[5] = static_cast<std::uint16_t>(base + 1);
}

} // namespace

idRenderModelEffects::UpdateCallback idRenderModelEffects::updateCallback =
    nullptr;
idRenderModelEffects::ViewExtractor idRenderModelEffects::viewExtractor =
    nullptr;
idRenderModelEffects::VisibleSpheresResolver
    idRenderModelEffects::visibleSpheresResolver = nullptr;
idRenderModelEffects::ParticleJobSubmitCallback
    idRenderModelEffects::particleJobSubmitCallback = nullptr;
idRenderModelEffects::BufferReferenceCallback
    idRenderModelEffects::bufferReferenceCallback = nullptr;
idRenderModelEffects::ShadowSampleCallback
    idRenderModelEffects::shadowSampleCallback = nullptr;
int idRenderModelEffects::particleTrailTimeStep = 0;

idRenderModelEffects::idRenderModelEffects()
    : particles(nullptr), particleTrails(nullptr), tracers(nullptr),
      decals(nullptr), decalVerts(nullptr), gameTime(0), deltaTime(0),
      latchedTime(0), numSortedParticleStages(0),
      particleRenderView(nullptr), particleGenParms(nullptr),
      triangles(nullptr) {
    std::memset(particleRange, 0, sizeof(particleRange));
    std::memset(particleTrailRange, 0, sizeof(particleTrailRange));
    std::memset(tracerRange, 0, sizeof(tracerRange));
    std::memset(decalRange, 0, sizeof(decalRange));
    std::memset(lastLatchedParticleRange, 0,
        sizeof(lastLatchedParticleRange));
    std::memset(latchedParticleRange, 0, sizeof(latchedParticleRange));
    std::memset(latchedTracerRange, 0, sizeof(latchedTracerRange));
    std::memset(latchedDecalRange, 0, sizeof(latchedDecalRange));
    std::memset(sortedParticleStages, 0, sizeof(sortedParticleStages));
    g.noShadow = 1;
    g.addAlways = 1;

    particles = new (std::nothrow)
        effectParticleParms_t[MAX_EFFECT_PARTICLES]();
    particleTrails = new (std::nothrow)
        particleTrailParms_t[MAX_PARTICLE_TRAILS]();
    tracers = new (std::nothrow) tracerParms_t[MAX_TRACERS]();
    decals = new (std::nothrow) decalParms_t[MAX_DECALS]();
    decalVerts = new (std::nothrow) decalVerts_t[MAX_DECALS]();
    particleRenderView = new (std::nothrow) particleRenderView_t();
    particleGenParms = new (std::nothrow)
        deferredParticleGenParms_t[MAX_PARTICLE_GEN_PARMS]();
    triangles = new (std::nothrow) idTriangles[MAX_EFFECT_TRIANGLES]();
    if (triangles != nullptr) {
        for (int i = 0; i < MAX_EFFECT_TRIANGLES; ++i) {
            triangles[i].bounds[0].Set(-99999.0f, -99999.0f, -99999.0f);
            triangles[i].bounds[1].Set(99999.0f, 99999.0f, 99999.0f);
        }
    }
}

idRenderModelEffects::~idRenderModelEffects() {
    delete[] particles;
    delete[] particleTrails;
    delete[] tracers;
    delete[] decals;
    delete[] decalVerts;
    delete particleRenderView;
    delete[] particleGenParms;
    delete[] triangles;
}

void idRenderModelEffects::Init() {
    if (effectFrameStorage.initialized) return;
    for (std::vector<idDrawVert>& vertices :
            effectFrameStorage.vertices) {
        vertices.resize(MAX_EFFECT_FRAME_VERTS);
        std::memset(vertices.data(), 0,
            vertices.size() * sizeof(vertices[0]));
    }
    effectFrameStorage.indices.resize(MAX_EFFECT_FRAME_INDICES);
    effectFrameStorage.mappedBufferIndex = 0;
    effectFrameStorage.vertOffset = 0;
    effectFrameStorage.indexOffset = 0;
    effectFrameStorage.initialized = true;
}

void idRenderModelEffects::Shutdown() {
    for (std::vector<idDrawVert>& vertices :
            effectFrameStorage.vertices) {
        vertices.clear();
        vertices.shrink_to_fit();
    }
    effectFrameStorage.indices.clear();
    effectFrameStorage.indices.shrink_to_fit();
    effectFrameStorage.vertOffset = 0;
    effectFrameStorage.indexOffset = 0;
    effectFrameStorage.initialized = false;
}

void idRenderModelEffects::StartFrame() {
    Init();
    effectFrameStorage.mappedBufferIndex =
        (effectFrameStorage.mappedBufferIndex + 1) & 1;
    effectFrameStorage.vertOffset = 0;
    effectFrameStorage.indexOffset = 0;
}

void idRenderModelEffects::EndFrame() {
    // The portable backing store remains mapped.  A renderer integration
    // can upload/reference it through bufferReferenceCallback.
}

void idRenderModelEffects::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

void idRenderModelEffects::SetRuntimeCallbacks(
        const ViewExtractor extractor,
        const VisibleSpheresResolver spheresResolver,
        const ParticleJobSubmitCallback jobSubmit,
        const BufferReferenceCallback bufferReference,
        const ShadowSampleCallback shadowSample) {
    viewExtractor = extractor;
    visibleSpheresResolver = spheresResolver;
    particleJobSubmitCallback = jobSubmit;
    bufferReferenceCallback = bufferReference;
    shadowSampleCallback = shadowSample;
}

void idRenderModelEffects::SetParticleTrailTimeStep(
        const int milliseconds) {
    particleTrailTimeStep = milliseconds;
}

int idRenderModelEffects::EstimateQuadAllocation(
    const idParticleStage* stage, const effectParticleParms_t* particle,
    const int renderTime) {
    if (stage == nullptr || particle == nullptr || stage->cycleMsec == 0
        || stage->systemProperties.totalParticles == 0) {
        return 0;
    }
    const int spawnWindow = static_cast<int>(
        stage->systemProperties.spawnBunching * stage->bunchTime * 1000.0f);
    const int earliestLiveAge = renderTime
        - static_cast<int>(stage->maxParticleLife * 1000.0f)
        - particle->startTime;
    int liveParticles = 0;
    if (spawnWindow != 0) {
        liveParticles = particle->numParticles
            - (earliestLiveAge * stage->systemProperties.totalParticles
                + spawnWindow) / spawnWindow;
        liveParticles = (std::max)(0, liveParticles);
    } else if (earliestLiveAge < 0) {
        liveParticles = particle->numParticles;
    }
    return (stage->NumVertsPerParticle() * liveParticles) / 4;
}

bool idRenderModelEffects::CommitSubclass() {
    lastLatchedParticleRange[0] = latchedParticleRange[0];
    lastLatchedParticleRange[1] = latchedParticleRange[1];
    latchedParticleRange[0] = particleRange[0];
    latchedParticleRange[1] = particleRange[1];
    latchedTracerRange[0] = tracerRange[0];
    latchedTracerRange[1] = tracerRange[1];
    latchedDecalRange[0] = decalRange[0];
    latchedDecalRange[1] = decalRange[1];
    latchedTime = gameTime;
    return false;
}

void idRenderModelEffects::AddDecal(const idMaterial* const material,
    const idDrawVert& v0, const idDrawVert& v1, const idDrawVert& v2,
    const idDrawVert& v3, const int startTime, const int lifeTime,
    const int fadeInEndTime, const int fadeOutStartTime) {
    if (decals == nullptr || decalVerts == nullptr
        || decalRange[1] - latchedDecalRange[0] >= MAX_DECALS) {
        return;
    }

    const int slot = decalRange[1]++ & (MAX_DECALS - 1);
    decalParms_t& parms = decals[slot];
    parms.mat = material;
    parms.startTime = startTime;
    parms.lifeTime = lifeTime;
    parms.fadeInEndTime = fadeInEndTime;
    parms.fadeOutStartTime = fadeOutStartTime;
    decalVerts[slot].verts[0] = v0;
    decalVerts[slot].verts[1] = v1;
    decalVerts[slot].verts[2] = v2;
    decalVerts[slot].verts[3] = v3;
    if (shadowSampleCallback != nullptr) {
        for (idDrawVert& vertex : decalVerts[slot].verts) {
            const int shadow = static_cast<int>((std::max)(0.0f,
                (std::min)(1.0f, shadowSampleCallback(this, vertex.xyz)))
                * 255.0f);
            vertex.color[0] = static_cast<std::uint8_t>(shadow);
            vertex.color[1] = static_cast<std::uint8_t>(shadow);
            vertex.color[2] = static_cast<std::uint8_t>(shadow);
        }
    }
}

void idRenderModelEffects::AddTracer(const idMaterial* const material,
    const idVec3& origin, const idVec3& direction,
    const idVec3& maximumDistance, float speed, float length,
    const float height, const bool ensureVisual,
    const float fractionInsured, const float lifeTime) {
    if (tracers == nullptr
        || tracerRange[1] - latchedTracerRange[0] >= MAX_TRACERS) {
        return;
    }

    tracerParms_t& tracer = tracers[tracerRange[1]++ & (MAX_TRACERS - 1)];
    tracer.startTime = gameTime;
    tracer.speed = speed;
    tracer.origin = origin;
    tracer.dir = direction;
    tracer.length = length;
    tracer.height = height;
    tracer.mat = material;

    const idVec3 delta = maximumDistance - origin;
    const float distance = std::sqrt(delta.x * delta.x
        + delta.y * delta.y + delta.z * delta.z);
    float travelDistance = distance - length * 0.5f;
    if (ensureVisual && fractionInsured > 0.0f
        && travelDistance < speed * fractionInsured) {
        length = distance * fractionInsured * 2.0f
            - speed * fractionInsured * 2.0f;
        if (length < 0.0f) {
            length = distance * 0.5f;
            speed = distance / fractionInsured
                - ((distance * 0.5f) / fractionInsured) * 0.5f;
        }
        tracer.length = length;
        tracer.speed = speed;
        travelDistance = fractionInsured * speed;
    }

    if (lifeTime >= 0.0f) {
        tracer.lifeTime = static_cast<int>(lifeTime);
    } else {
        const float effectiveSpeed = speed != 0.0f ? speed : 1500.0f;
        tracer.lifeTime = static_cast<int>((std::min)(3000.0f,
            travelDistance / effectiveSpeed * 1000.0f));
    }
}

bool idRenderModelEffects::AddParticles(
    const idDeclParticle* const particle, const int systemStartTime,
    const int gameMillisecondsPerFrame, const float diversity,
    const idVec3& origin, const idMat3& axis, const idVec3& velocity,
    const unsigned int& color) {
    if (particle == nullptr || particles == nullptr
        || particleRange[1] - latchedParticleRange[0]
            >= MAX_EFFECT_PARTICLES) {
        return false;
    }

    bool moreParticlesRemain = false;
    const int packedDiversity = static_cast<int>(diversity * 65535.0f);
    const float sampledShadow = shadowSampleCallback != nullptr
        ? shadowSampleCallback(this, origin) : 1.0f;
    for (int stageIndex = 0; stageIndex < particle->stages.Num();
            ++stageIndex) {
        const idParticleStage* const stage = particle->stages[stageIndex];
        if (stage == nullptr || stage->hidden || stage->cycleMsec == 0
            || stage->systemProperties.material == nullptr
            || stage->maxParticleLife <= 0.0f
            || stage->systemProperties.totalParticles <= 0) {
            continue;
        }

        const int total = stage->systemProperties.totalParticles;
        const int spawnWindow = static_cast<int>(
            stage->systemProperties.spawnBunching * stage->cycleMsec);
        const int elapsed = gameTime - systemStartTime;
        int previousParticle = -1;
        int currentParticle = -1;
        if (spawnWindow != 0 && elapsed >= 0) {
            currentParticle = (std::min)(total - 1,
                total * elapsed / spawnWindow);
            const int previousElapsed = elapsed - gameMillisecondsPerFrame;
            if (previousElapsed >= 0) {
                previousParticle = total * previousElapsed / spawnWindow;
            }
        } else if (spawnWindow == 0 && gameTime == systemStartTime) {
            currentParticle = total - 1;
        }

        if (currentParticle < 0 || previousParticle >= total) {
            continue;
        }
        if (currentParticle < total - 1) {
            moreParticlesRemain = true;
        }
        const int count = currentParticle - previousParticle;
        if (count <= 0) {
            continue;
        }
        if (particleRange[1] - latchedParticleRange[0]
            >= MAX_EFFECT_PARTICLES) {
            break;
        }

        effectParticleParms_t& parms =
            particles[particleRange[1]++ & (MAX_EFFECT_PARTICLES - 1)];
        parms.startTime = systemStartTime + static_cast<int>(
            stage->systemProperties.timeOffset * 1000.0f);
        parms.duration = static_cast<int>(stage->maxParticleLife * 1000.0f);
        parms.stage = stage;
        parms.tables = particle->GetTables();
        parms.numTables = particle->tables.Num();
        parms.diversity = packedDiversity;
        parms.origin = origin;
        parms.axis = axis;
        parms.velocity = velocity;
        parms.wind.Zero();
        parms.shadow = stage->colorAttributes.useGlobalShadows
            ? sampledShadow : 1.0f;
        parms.currTime = gameTime;
        parms.numParticles = count;
        parms.color = color;
    }
    return moreParticlesRemain;
}

bool idRenderModelEffects::AddParticleTrail(
    const idDeclParticle* const particle, const idVec3& startPosition,
    const idVec3& direction, const int startTime, const int endTime) {
    if (particle == nullptr || particleTrails == nullptr
        || endTime < startTime
        || particleTrailRange[1] - particleTrailRange[0]
            >= MAX_PARTICLE_TRAILS) {
        return false;
    }
    particleTrailParms_t& trail = particleTrails[
        particleTrailRange[1]++ & (MAX_PARTICLE_TRAILS - 1)];
    trail.startPos = startPosition;
    trail.dir = direction;
    trail.startTime = startTime;
    trail.endTime = endTime;
    trail.lastTime = startTime;
    trail.decl = particle;
    return true;
}

void idRenderModelEffects::Update(const int newTime,
    const int gameMillisecondsPerFrame) {
    deltaTime = newTime - gameTime;
    gameTime = newTime;

    while (particleTrailRange[0] < particleTrailRange[1]) {
        particleTrailParms_t& trail = particleTrails[
            particleTrailRange[0] & (MAX_PARTICLE_TRAILS - 1)];
        const int end = (std::min)(gameTime, trail.endTime);
        if (trail.lastTime <= end) {
            const int span = trail.endTime - trail.startTime;
            const int step = particleTrailTimeStep > 0
                ? particleTrailTimeStep : 1;
            unsigned int color = ~0u;
            for (int sampleTime = trail.lastTime; sampleTime <= end;
                    sampleTime += step) {
                const float fraction = span > 0
                    ? static_cast<float>(sampleTime - trail.startTime)
                        / static_cast<float>(span)
                    : 0.0f;
                const idVec3 position = trail.startPos
                    + trail.dir * fraction;
                AddParticles(trail.decl, sampleTime,
                    gameMillisecondsPerFrame, 0.3f, position,
                    idMat3(1.0f), idVec3(0.0f, 0.0f, 0.0f), color);
                trail.lastTime = sampleTime + step;
            }
        }
        if (gameTime < trail.endTime) {
            break;
        }
        ++particleTrailRange[0];
    }
    particleTrailRange[0] = (std::max)(particleTrailRange[0],
        particleTrailRange[1] - MAX_PARTICLE_TRAILS);

    while (particleRange[0] < particleRange[1]) {
        const effectParticleParms_t& particle = particles[
            particleRange[0] & (MAX_EFFECT_PARTICLES - 1)];
        if (gameTime - particle.startTime <= particle.duration) break;
        ++particleRange[0];
    }
    particleRange[0] = (std::max)(particleRange[0],
        particleRange[1] - MAX_EFFECT_PARTICLES);
    while (tracerRange[0] < tracerRange[1]) {
        const tracerParms_t& tracer = tracers[
            tracerRange[0] & (MAX_TRACERS - 1)];
        if (gameTime - tracer.startTime <= tracer.lifeTime) break;
        ++tracerRange[0];
    }
    tracerRange[0] = (std::max)(tracerRange[0],
        tracerRange[1] - MAX_TRACERS);
    while (decalRange[0] < decalRange[1]) {
        const decalParms_t& decal = decals[
            decalRange[0] & (MAX_DECALS - 1)];
        if (gameTime - decal.startTime <= decal.lifeTime) break;
        ++decalRange[0];
    }
    decalRange[0] = (std::max)(decalRange[0],
        decalRange[1] - MAX_DECALS);
    CommitThisFrame();
}

void idRenderModelEffects::SortEffectParticles() {
    if (particles == nullptr || latchedParticleRange[0]
        >= latchedParticleRange[1]) {
        numSortedParticleStages = 0;
        lastLatchedParticleRange[0] = latchedParticleRange[0];
        lastLatchedParticleRange[1] = latchedParticleRange[1];
        return;
    }

    struct group_t {
        const idParticleStage* stage;
        std::vector<effectParticleParms_t> particles;
    };
    std::vector<effectParticleParms_t> expired;
    std::vector<group_t> groups;
    const int count = latchedParticleRange[1] - latchedParticleRange[0];
    expired.reserve(count);
    for (int absolute = latchedParticleRange[0];
            absolute < latchedParticleRange[1]; ++absolute) {
        const effectParticleParms_t& particle = particles[
            absolute & (MAX_EFFECT_PARTICLES - 1)];
        if (gameTime - particle.startTime > particle.duration) {
            expired.push_back(particle);
            continue;
        }
        auto found = std::find_if(groups.begin(), groups.end(),
            [&particle](const group_t& group) {
                return group.stage == particle.stage;
            });
        if (found == groups.end()) {
            if (groups.size() >= 1024) break;
            groups.push_back(group_t{particle.stage, {}});
            found = groups.end() - 1;
        }
        found->particles.push_back(particle);
    }

    int output = latchedParticleRange[0];
    for (const effectParticleParms_t& particle : expired) {
        particles[output++ & (MAX_EFFECT_PARTICLES - 1)] = particle;
    }
    numSortedParticleStages = 0;
    for (const group_t& group : groups) {
        sortedParticleStage_t& sorted =
            sortedParticleStages[numSortedParticleStages++];
        sorted.stage = group.stage;
        sorted.first = output;
        sorted.num = static_cast<int>(group.particles.size());
        for (const effectParticleParms_t& particle : group.particles) {
            particles[output++ & (MAX_EFFECT_PARTICLES - 1)] = particle;
        }
    }
    lastLatchedParticleRange[0] = latchedParticleRange[0];
    lastLatchedParticleRange[1] = latchedParticleRange[1];
}

bool idRenderModelEffects::UpdateInView(const idRenderView* currentView,
    const idRenderView* nextView, idRenderModelUpdateTools* tools) {
    if (updateCallback != nullptr) {
        return updateCallback(this, currentView, nextView, tools);
    }
    Init();
    surfaces.Clear();
    if (triangles == nullptr) return false;

    idVec3 currentViewOrigin;
    currentViewOrigin.Zero();
    if (particleRenderView != nullptr) {
        std::memset(particleRenderView, 0, sizeof(*particleRenderView));
        particleRenderView->renderTime = latchedTime;
        particleRenderView->deltaTime = deltaTime;
        particleRenderView->atlasWidth = 1;
        particleRenderView->atlasHeight = 1;
        if (viewExtractor != nullptr) {
            viewExtractor(currentView, nextView, *particleRenderView,
                currentViewOrigin);
        }
    }

    auto appendSurface = [&](const idMaterial* material,
            idDrawVert* vertices, std::uint16_t* indices,
            const int firstVertex, const int numVertices,
            const int firstIndex, const int numIndices,
            const unsigned int vertexMask, const int frameBufferIndex) {
        if (surfaces.Num() >= MAX_EFFECT_TRIANGLES ||
            numVertices <= 0 || numIndices <= 0) {
            return false;
        }
        idTriangles& geometry = triangles[surfaces.Num()];
        geometry.numVerts = numVertices;
        geometry.numIndexes = numIndices;
        geometry.vertexMask = vertexMask;
        geometry.cpuVertexMask = vertexMask;
        geometry.verts = vertices;
        geometry.indexes = indices;
        geometry.allowGpuHosting = true;
        idRenderModelSurface surface{};
        surface.material = material;
        surface.materialNum = surfaces.Num();
        surface.geometry = &geometry;
        surface.geometryIsReference = true;
        AddSurface(surface);
        if (bufferReferenceCallback != nullptr) {
            bufferReferenceCallback(&geometry, frameBufferIndex,
                firstVertex, firstIndex);
        }
        return true;
    };

    const int frameBufferIndex = effectFrameStorage.mappedBufferIndex;
    std::vector<idDrawVert>& frameVertices =
        effectFrameStorage.vertices[frameBufferIndex];

    std::vector<const idMaterial*> tracerMaterials;
    for (int absolute = latchedTracerRange[0];
            absolute < latchedTracerRange[1]; ++absolute) {
        const tracerParms_t& tracer =
            tracers[absolute & (MAX_TRACERS - 1)];
        if (std::find(tracerMaterials.begin(), tracerMaterials.end(),
                tracer.mat) == tracerMaterials.end()) {
            tracerMaterials.push_back(tracer.mat);
        }
    }
    for (const idMaterial* const material : tracerMaterials) {
        const int surfaceFirstVertex = effectFrameStorage.vertOffset;
        const int surfaceFirstIndex = effectFrameStorage.indexOffset;
        int surfaceVertices = 0;
        int surfaceIndices = 0;
        for (int absolute = latchedTracerRange[0];
                absolute < latchedTracerRange[1]; ++absolute) {
            const tracerParms_t& tracer =
                tracers[absolute & (MAX_TRACERS - 1)];
            if (tracer.mat != material) continue;
            int firstVertex = 0;
            int firstIndex = 0;
            if (!AllocateEffectGeometry(8, 12, firstVertex, firstIndex))
                break;
            const float age = (std::max)(0.0f,
                static_cast<float>(latchedTime - deltaTime -
                    tracer.startTime) * 0.001f);
            const idVec3 forward = Normalize(tracer.dir,
                idVec3(1.0f, 0.0f, 0.0f));
            const idVec3 start = tracer.origin
                + tracer.dir * (age * tracer.speed);
            const idVec3 end = start + tracer.dir * tracer.length;
            const idVec3 toView = Normalize(currentViewOrigin
                - tracer.origin,
                idVec3(0.0f, 0.0f, 1.0f));
            const idVec3 side = Normalize(tracer.dir.Cross(toView),
                idVec3(0.0f, 1.0f, 0.0f)) * (tracer.height * 0.5f);
            idDrawVert* const output =
                frameVertices.data() + firstVertex;
            InitializeEffectVertex(output[0], start + side, 0.0f, 0.0f,
                toView, forward);
            InitializeEffectVertex(output[1], end + side, 1.0f, 0.0f,
                toView, forward);
            InitializeEffectVertex(output[2], start - side, 0.0f, 1.0f,
                toView, forward);
            InitializeEffectVertex(output[3], end - side, 1.0f, 1.0f,
                toView, forward);
            InitializeEffectVertex(output[4], end - side, 1.0f, 1.0f,
                -toView, forward);
            InitializeEffectVertex(output[5], end + side, 1.0f, 0.0f,
                -toView, forward);
            InitializeEffectVertex(output[6], start - side, 0.0f, 1.0f,
                -toView, forward);
            InitializeEffectVertex(output[7], start + side, 0.0f, 0.0f,
                -toView, forward);
            const int relativeVertex = firstVertex - surfaceFirstVertex;
            WriteQuadIndices(effectFrameStorage.indices.data() + firstIndex,
                relativeVertex);
            WriteQuadIndices(effectFrameStorage.indices.data() +
                firstIndex + 6, relativeVertex + 4);
            surfaceVertices += 8;
            surfaceIndices += 12;
        }
        appendSurface(material,
            frameVertices.data() + surfaceFirstVertex,
            effectFrameStorage.indices.data() + surfaceFirstIndex,
            surfaceFirstVertex, surfaceVertices, surfaceFirstIndex,
            surfaceIndices, 31, frameBufferIndex);
    }

    std::vector<const idMaterial*> decalMaterials;
    for (int absolute = latchedDecalRange[0];
            absolute < latchedDecalRange[1]; ++absolute) {
        const decalParms_t& decal = decals[absolute & (MAX_DECALS - 1)];
        if (std::find(decalMaterials.begin(), decalMaterials.end(),
                decal.mat) == decalMaterials.end()) {
            decalMaterials.push_back(decal.mat);
        }
    }
    for (const idMaterial* const material : decalMaterials) {
        const int surfaceFirstVertex = effectFrameStorage.vertOffset;
        const int surfaceFirstIndex = effectFrameStorage.indexOffset;
        int surfaceVertices = 0;
        int surfaceIndices = 0;
        for (int absolute = latchedDecalRange[0];
                absolute < latchedDecalRange[1]; ++absolute) {
            const int slot = absolute & (MAX_DECALS - 1);
            const decalParms_t& decal = decals[slot];
            if (decal.mat != material) continue;
            int firstVertex = 0;
            int firstIndex = 0;
            if (!AllocateEffectGeometry(4, 6, firstVertex, firstIndex))
                break;
            idDrawVert* const output =
                frameVertices.data() + firstVertex;
            std::memcpy(output, decalVerts[slot].verts,
                sizeof(decalVerts[slot].verts));
            const int age = latchedTime - decal.startTime;
            float visibility = 1.0f;
            if (decal.fadeInEndTime > decal.startTime &&
                latchedTime < decal.fadeInEndTime) {
                visibility = static_cast<float>(age) /
                    (decal.fadeInEndTime - decal.startTime);
            }
            const int endTime = decal.startTime + decal.lifeTime;
            if (decal.fadeOutStartTime < endTime &&
                latchedTime > decal.fadeOutStartTime) {
                visibility = (std::min)(visibility,
                    static_cast<float>(endTime - latchedTime) /
                    (endTime - decal.fadeOutStartTime));
            }
            visibility = (std::max)(0.0f, (std::min)(1.0f, visibility));
            const int visibilityByte = static_cast<int>(visibility * 255.0f);
            for (int vertex = 0; vertex < 4; ++vertex) {
                for (int channel = 0; channel < 4; ++channel) {
                    output[vertex].color[channel] =
                        static_cast<std::uint8_t>(
                            (static_cast<unsigned int>(
                                output[vertex].color[channel])
                                * visibilityByte) >> 8);
                }
            }
            WriteQuadIndices(effectFrameStorage.indices.data() + firstIndex,
                firstVertex - surfaceFirstVertex);
            surfaceVertices += 4;
            surfaceIndices += 6;
        }
        appendSurface(material,
            frameVertices.data() + surfaceFirstVertex,
            effectFrameStorage.indices.data() + surfaceFirstIndex,
            surfaceFirstVertex, surfaceVertices, surfaceFirstIndex,
            surfaceIndices, 31, frameBufferIndex);
    }

    const int transparencyBuffer =
        idRenderModelTransparency::GetCurrentFrameBufferIndex();
    const int displayBuffer = (transparencyBuffer + 2) % 3;
    idTransparencyVert* const displayVertices =
        idRenderModelTransparency::GetUnsortedVertices(displayBuffer);
    const std::uint16_t* const unsortedIndices =
        idRenderModelTransparency::GetUnsortedIndices();
    for (int index = 0; index < deferredStages[displayBuffer].Num();
            ++index) {
        const deferredStage_t& deferred =
            deferredStages[displayBuffer][index];
        const int firstVertex = (deferred.indexOffset / 6) * 4;
        appendSurface(deferred.mtr,
            reinterpret_cast<idDrawVert*>(displayVertices),
            const_cast<std::uint16_t*>(unsortedIndices +
                deferred.indexOffset), firstVertex,
            deferred.vertCount, deferred.indexOffset,
            6 * (deferred.vertCount / 4), 3167, displayBuffer);
    }
    deferredStages[displayBuffer].Clear();
    deferredStages[transparencyBuffer].Clear();

    SortEffectParticles();
    const visibleInfluenceSpheres_t* const visibleSpheres =
        visibleSpheresResolver != nullptr
            ? visibleSpheresResolver() : nullptr;
    int generationParm = 0;
    for (int group = 0; group < numSortedParticleStages &&
            generationParm < MAX_PARTICLE_GEN_PARMS; ++group) {
        const sortedParticleStage_t& sorted = sortedParticleStages[group];
        int item = 0;
        while (item < sorted.num
                && generationParm < MAX_PARTICLE_GEN_PARMS) {
            const int firstSlot = (sorted.first + item)
                & (MAX_EFFECT_PARTICLES - 1);
            effectParticleParms_t& effect = particles[firstSlot];
            effect.currTime = latchedTime;
            int numQuads = EstimateQuadAllocation(effect.stage,
                &effect, latchedTime);
            if (numQuads <= 0 || effect.stage == nullptr) {
                ++item;
                continue;
            }

            int batchCount = 1;
            while (item + batchCount < sorted.num
                    && batchCount < 145
                    && firstSlot + batchCount < MAX_EFFECT_PARTICLES) {
                effectParticleParms_t& next =
                    particles[firstSlot + batchCount];
                if (next.stage != effect.stage) break;
                next.currTime = latchedTime;
                const int nextQuads = EstimateQuadAllocation(next.stage,
                    &next, latchedTime);
                if (nextQuads <= 0 || numQuads + nextQuads > 128) break;
                numQuads += nextQuads;
                ++batchCount;
            }

            deferredParticleGenParms_t& generation =
                particleGenParms[generationParm];
            std::memset(&generation, 0, sizeof(generation));
            generation.renderView = particleRenderView;
            generation.effectParticleParms = &effect;
            generation.stage = effect.stage;
            generation.tables = effect.tables;
            generation.staticVerts = effect.stage->staticVerts;
            generation.visibleInfluenceSpheres = visibleSpheres;
            generation.numEffectParticleParms = batchCount;
            generation.numTables = effect.numTables;
            generation.staticVertsSize = effect.stage->numStaticVerts;
            generation.deadTime = effect.stage->maxDeadTime;
            generation.maxVertsToGen = numQuads * 4;

            bool allocated = false;
            if (effect.stage->isTransparencySorted) {
                allocated = idRenderModelTransparency::AllocateQuadSegment(
                    numQuads, generation.verts, generation.quadDepth,
                    generation.quadsUsed,
                    effect.stage->hasEmissivePass != 0);
            } else {
                int indexOffset = 0;
                int vertCount = 0;
                allocated = idRenderModelTransparency::
                    AllocateUnsortedQuadSegment(numQuads,
                        generation.verts, indexOffset, vertCount);
                if (allocated) {
                    deferredStage_t deferred{};
                    deferred.mtr = effect.stage->systemProperties.material;
                    deferred.vertCount = vertCount;
                    deferred.indexOffset = indexOffset;
                    deferredStages[transparencyBuffer].Append(deferred);
                }
            }
            if (allocated) {
                if (particleJobSubmitCallback == nullptr ||
                    !particleJobSubmitCallback(&generation, tools)) {
                    ParticleGenJob(&generation);
                }
                ++generationParm;
            }
            item += batchCount;
        }
    }
    return true;
}
