#include "models/particles/rendermodeleffects.h"

#include "models/particles/declparticle.h"
#include "models/particles/jobs/particlestage.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <new>
#include <vector>

idRenderModelEffects::UpdateCallback idRenderModelEffects::updateCallback =
    nullptr;

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
    g.noInteractions = 1;
    g.noShadow = 1;

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

void idRenderModelEffects::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
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
            (std::max)(0.0f, travelDistance / effectiveSpeed * 1000.0f)));
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
    const int packedDiversity = static_cast<int>((std::max)(0.0f,
        (std::min)(1.0f, diversity)) * 65535.0f);
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
        parms.shadow = 1.0f;
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
            const int step = (std::max)(1, gameMillisecondsPerFrame);
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
    return updateCallback != nullptr
        ? updateCallback(this, currentView, nextView, tools)
        : false;
}
