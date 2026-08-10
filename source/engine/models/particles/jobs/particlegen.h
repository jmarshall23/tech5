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
    int totalParticles;
    idMat3 modelAxis;
    idMat3 globalAxis;
    idVec3 globalOrigin;
    idVec3 localVelocity;
    idVec3 localViewLeft;
    idVec3 localViewUp;
    idVec3 localViewOrg;
    float fade;
    float alphaScaleOverride;
    float shadow;
    idVec3 distribScale;
    float sizeScale;
    idVec4 entityColor;
    idMat3 stageAxis;
    idVec3 wind;
    const influenceSphere_t* influenceSpheres;
    int numInfluenceSpheres;
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
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(particleInput_t) == 252,
    "Recovered particle-input ABI changed");
#endif
