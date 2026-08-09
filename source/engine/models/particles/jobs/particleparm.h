#pragma once

#include "idlib/math/matrix.h"
#include "idlib/math/random.h"
#include "idlib/math/vector.h"
#include "idlib/geometry/drawvert.h"
#include "models/transparency/jobs/influencespheredata.h"
#include "models/transparency/jobs/transparencyvert.h"
#include "idlib/containers/list.h"
#include "idlib/text/str.h"

#include <cstdint>

class idLookupTable;
class idDeclTable;
class idDeclParticle;
class idFile;
class idMaterial;
class idParser;
class idParticleStage;

enum particleCalcType_t : int {
    PARTICLE_CALC_NONE = 0,
    PARTICLE_CALC_CURVE_GENERIC,
    PARTICLE_CALC_GENERIC,
    PARTICLE_CALC_CURVE_MOD_CURVE,
    PARTICLE_CALC_CURVE_ADD_CURVE,
    PARTICLE_CALC_PARAMETRIC_EVAL,
    PARTICLE_CALC_PARAMETRIC_INTEGRATE,
    PARTICLE_CALC_PARAMETRIC_INTEGRATE_MINMAX,
    NUM_PARTICLE_CALC_TYPES
};

enum particleEditCalcType_t : int {
    PARTICLE_EDIT_CALC_NONE = 0,
    PARTICLE_EDIT_CALC_CONSTANT,
    PARTICLE_EDIT_CALC_MINMAX,
    PARTICLE_EDIT_CALC_CURVE,
    PARTICLE_EDIT_CALC_CURVE_SCALE_BIAS,
    PARTICLE_EDIT_CALC_CURVE_VARIANCE_MOD_CONSTANT,
    PARTICLE_EDIT_CALC_CURVE_MOD_CURVE,
    PARTICLE_EDIT_CALC_CURVE_ADD_CURVE,
    PARTICLE_EDIT_CALC_PARAMETRIC_EVAL,
    PARTICLE_EDIT_CALC_PARAMETRIC_INTEGRATE,
    PARTICLE_EDIT_CALC_PARAMETRIC_INTEGRATE_MINMAX,
    NUM_PARTICLE_EDIT_CALC_TYPES
};

class idParticleParm {
public:
    void Clear();
    void SetCalcTypeFromEditType(particleEditCalcType_t editType);
    particleEditCalcType_t GetEditCalcType() const;
    float GetMaxParmVal(const idLookupTable* tables) const;
    float Compute(const idLookupTable* tables, float fraction,
        idRandom2& random) const;

    float val0;
    float val1;
    float variance;
    std::int16_t tableIdx;
    std::int16_t table2Idx;
    particleCalcType_t calcType;
};

void SetParticleParmAsIntegrate(idParticleParm* parm, float from,
    float to, float variance);
void SetParticleParmAsEval(idParticleParm* parm, float from,
    float to, float variance);
void SetParticleParmAsConstant(idParticleParm* parm, float value,
    float variance = 0.0f);
void SetParticleParmAsMinMax(idParticleParm* parm, float minimum,
    float maximum);

int ParticleCalcNameToType(const char* name);
void ParseParticleParm(idParser* parser, idParticleParm* parm,
    idList<const idDeclTable*, 79>& tableDecls,
    idList<idLookupTable, 79>& tables);
bool WriteParticleBool(idFile* file, const char* name, bool value,
    bool defaultValue);
bool WriteParticleVec4(idFile* file, const char* name, const idVec4& value,
    const idVec4& defaultValue);
void WriteParticleParm(idFile* file, const char* name,
    const idParticleParm& parm, const idParticleParm& defaultParm,
    const idList<const idDeclTable*, 79>& tableDecls,
    const idStr& info = idStr(), const idStr& parentInfo = idStr());

struct effectParticleParms_t {
    int startTime;
    int duration;
    const idParticleStage* stage;
    const idLookupTable* tables;
    int numTables;
    int diversity;
    idVec3 origin;
    idMat3 axis;
    idVec3 velocity;
    idVec3 wind;
    float shadow;
    int currTime;
    int numParticles;
    unsigned int color;
};

struct modelParticleParms_t {
    int stopTime;
    float timeOffset;
    int diversity;
    float coverage;
    idVec4 color;
    idVec4 wind;
    idVec3 distribScale;
    idVec3 origin;
    idMat3 axis;
    idVec3 scale;
    idVec3 velocity;
    float shadow;
    float alphaScaleOverride;
    std::uint8_t lod;
    std::uint8_t pad[3];
};

struct particleTrailParms_t {
    idVec3 startPos;
    idVec3 dir;
    int startTime;
    int endTime;
    int lastTime;
    const idDeclParticle* decl;
};

struct tracerParms_t {
    int startTime;
    int lifeTime;
    float speed;
    idVec3 origin;
    idVec3 dir;
    float length;
    float height;
    const idMaterial* mat;
};

struct decalParms_t {
    const idMaterial* mat;
    int startTime;
    int lifeTime;
    int fadeInEndTime;
    int fadeOutStartTime;
};

struct decalVerts_t {
    idDrawVert verts[4];
};

struct particleRenderView_t {
    idVec3 viewOrg;
    idVec3 viewFwd;
    idVec3 viewLeft;
    idVec3 viewUp;
    int renderTime;
    int deltaTime;
    std::uint16_t atlasWidth;
    std::uint16_t atlasHeight;
    int pad;
};

struct deferredParticleGenParms_t {
    const particleRenderView_t* renderView;
    const effectParticleParms_t* effectParticleParms;
    const modelParticleParms_t* modelParticleParms;
    const idParticleStage* stage;
    const idLookupTable* tables;
    const idDrawVert* staticVerts;
    const visibleInfluenceSpheres_t* visibleInfluenceSpheres;
    int numEffectParticleParms;
    int numModelParticleParms;
    int numTables;
    int staticVertsSize;
    float deadTime;
    int maxVertsToGen;
    idTransparencyVert* verts;
    float* quadDepth;
    int* quadsUsed;
};

static_assert(sizeof(idParticleParm) == 20,
    "Recovered particle-parameter ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(effectParticleParms_t) == 112,
    "Recovered effect-particle parameters ABI changed");
static_assert(sizeof(modelParticleParms_t) == 144,
    "Recovered model-particle parameters ABI changed");
static_assert(sizeof(particleTrailParms_t) == 40,
    "Recovered particle-trail parameters ABI changed");
static_assert(sizeof(tracerParms_t) == 48,
    "Recovered tracer parameters ABI changed");
static_assert(sizeof(decalParms_t) == 20,
    "Recovered decal parameters ABI changed");
static_assert(sizeof(decalVerts_t) == 128,
    "Recovered decal-vertex ABI changed");
static_assert(sizeof(particleRenderView_t) == 64,
    "Recovered particle render-view ABI changed");
static_assert(sizeof(deferredParticleGenParms_t) == 64,
    "Recovered deferred particle-generation ABI changed");
#endif
