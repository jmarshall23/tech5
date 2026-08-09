#pragma once

#include "idlib/math/random.h"
#include "idlib/math/vector.h"
#include "models/particles/jobs/particleparm.h"

class idLookupTable;
class idParticleStage;
class idTransparencyVert;

struct particleGen_t {
    particleGen_t()
        : index(0), cycleAge(0.0f), totalAge(0.0f), particleLife(0.0f),
          frac(0.0f), parmVal(0.0f), random(0), originalRandom(0),
          vertColor(0.0f, 0.0f, 0.0f, 0.0f) {}

    int index;
    float cycleAge;
    float totalAge;
    float particleLife;
    float frac;
    float parmVal;
    idRandom2 random;
    idRandom2 originalRandom;
    idVec4 vertColor;
};

struct particleInput_t {
    const idParticleStage* stage;
    const idLookupTable* tables;
    const particleRenderView_t* view;
    const idDrawVert* staticVerts;
    idVec3 globalOrigin;
    idMat3 globalAxis;
    idMat3 stageAxis;
    idVec3 localViewOrg;
    idVec3 localViewLeft;
    idVec3 localViewUp;
    idVec3 localVelocity;
    idVec3 distribScale;
    idVec3 wind;
    idVec4 entityColor;
    float sizeScale;
    float fade;
    float shadow;
    float alphaScaleOverride;
    int totalParticles;
};

struct particleOutput_t {
    idTransparencyVert* verts;
    float* quadDepth;
};

idMat3 ParticleStageAxis(const idParticleStage* stage, int diversity);
idVec3 ParticleOrigin(const particleInput_t& input, particleGen_t& particle,
    idVec3* velocity = nullptr);
int CreateParticle(const particleInput_t& input, particleGen_t& particle,
    particleOutput_t& output);
int GenParticleStage(const deferredParticleGenParms_t* parms, int index,
    int vertOffset);
int GenEffectStage(const deferredParticleGenParms_t* parms, int index,
    int vertOffset);
void ParticleGenJob(const deferredParticleGenParms_t* parms);

static_assert(sizeof(particleGen_t) == 48,
    "Recovered particle-generator ABI changed");
