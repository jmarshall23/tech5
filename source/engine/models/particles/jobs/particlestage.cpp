#include "models/particles/jobs/particlestage.h"

#include "models/particles/jobs/particlegen.h"
#include "models/particles/jobs/staticparticlemodeldata.h"

#include <algorithm>
#include <cmath>
#include <cstring>

idParticleStage::MaterialTraitsCallback
    idParticleStage::materialTraitsCallback = nullptr;
idParticleStage::DefaultMaterialCallback
    idParticleStage::defaultMaterialCallback = nullptr;

idParticleStage::idParticleStage() {
    Default();
}

void idParticleStage::Default(const idLookupTable*) {
    std::memset(this, 0, sizeof(*this));

    staticData = nullptr;
    staticVerts = nullptr;
    numStaticVerts = 0;
    atlasScaleBias.Set(1.0f, 1.0f, 0.0f, 0.0f);

    systemProperties.totalParticles = 20;
    systemProperties.diversity = 0;
    systemProperties.cycles = 0;
    SetParticleParmAsConstant(&systemProperties.particleLife, 1.5f);
    systemProperties.timeOffset = 0.0f;
    SetParticleParmAsConstant(&systemProperties.deadTime, 0.0f);
    systemProperties.useSysTime = 0.0f;
    systemProperties.spawnBunching = 1.0f;
    systemProperties.emissionTime = 0.0f;
    systemProperties.textureFlipS = PTEXTURE_FLIP_NONE;
    systemProperties.textureFlipT = PTEXTURE_FLIP_NONE;
    SetParticleParmAsConstant(&systemProperties.windBias, 0.0f);
    systemProperties.sortType = PSORT_TYPE_NONE;
    systemProperties.boundsExpansion = 0.0f;
    systemProperties.randomOnCycle = true;
    SetMaterial(defaultMaterialCallback != nullptr
        ? defaultMaterialCallback() : nullptr);

    distribution.type = PDIST_RECT;
    for (int axis = 0; axis < 3; ++axis) {
        SetParticleParmAsConstant(&distribution.size[axis], 0.0f);
    }
    distribution.random = true;

    orientation.type = POR_VIEW;
    orientation.numTrails = 0;
    orientation.segmentLength = 0.0f;
    orientation.viewFade = 1.0f;
    orientation.orientToVelOnly = false;
    orientation.world = false;
    orientation.aimedSafeQuad = false;
    orientation.aimedSafeQuadAlign = 1.0f;
    orientation.depthOffset = 0.0f;

    direction.type = PDIR_CONE;
    direction.parms[0] = 90.0f;
    direction.coneAxis = idMat3(1.0f);
    for (int axis = 0; axis < 3; ++axis) {
        SetParticleParmAsIntegrate(&speed.speed[axis], 0.0f, 0.0f, 0.0f);
        SetParticleParmAsConstant(&acceleration.acceleration[axis], 0.0f);
        SetParticleParmAsConstant(&friction.friction[axis], 0.0f);
        SetParticleParmAsConstant(&offset.offset[axis], 0.0f);
        SetParticleParmAsConstant(&spawnLocation.spawnLocation[axis], 0.0f);
        SetParticleParmAsIntegrate(&rotation.rotation[axis], 0.0f, 0.0f,
            0.0f);
        SetParticleParmAsMinMax(&initialRotation.initialAngle[axis],
            -360.0f, 360.0f);
        SetParticleParmAsEval(&size.size[axis], 4.0f, 4.0f, 0.0f);
    }
    acceleration.world = false;
    SetParticleParmAsConstant(&gravity.gravity, 0.0f);
    gravity.world = false;

    for (int component = 0; component < 4; ++component) {
        SetParticleParmAsConstant(&colorAttributes.baseColor[component],
            1.0f);
    }
    colorAttributes.fadeColor.Set(0.0f, 0.0f, 0.0f, 0.0f);
    colorAttributes.fadeInFraction = 0.1f;
    colorAttributes.fadeOutFraction = 0.25f;
    colorAttributes.fadeIndexFraction = 0.0f;
    colorAttributes.softParticleAlphaScale = 1.0f;
    SetParticleParmAsConstant(&colorAttributes.brightness, 1.0f);
    colorAttributes.useGlobalShadows = false;
    colorAttributes.minShadowVal = 0.2f;
    colorAttributes.entityColorBlendVal = 1.0f;
    rotation.allowRotDirOverride = true;
    pivot.pivotOffset.Set(0.0f, 0.0f);
    SetParticleParmAsEval(&size.aspectRatio, 1.0f, 1.0f, 0.0f);

    texAnimation.type = PANIM_TYPE_SINGLE_CYCLE;
    texAnimation.numColumns = 1;
    texAnimation.numRows = 1;
    SetParticleParmAsConstant(&texAnimation.rate, 0.0f);
    texAnimation.startFrame = 0;
    texAnimation.useRandomRow = false;
    texAnimation.useFrameBlending = true;

    customPath.type = PPATH_STANDARD;
    for (int index = 0; index < 5; ++index) {
        SetParticleParmAsConstant(&customPath.parms[index], 0.0f);
    }
    for (int index = 0; index < 4; ++index) {
        SetParticleParmAsConstant(&genericParm.genericParm[index], 0.0f);
    }

    lodParms.sizeScale = 1.0f;
    lodParms.lerpAmount = 0.0f;
    lodParms.radius = 0;
    lodParms.totalParticles = 1;

    maxParticleLife = systemProperties.particleLife.GetMaxParmVal(nullptr);
    maxDeadTime = systemProperties.deadTime.GetMaxParmVal(nullptr);
    cycleMsec = static_cast<int>((maxParticleLife + maxDeadTime) * 1000.0f);
    bunchTime = maxParticleLife;
}

void idParticleStage::SetMaterial(const idMaterial* material) {
    systemProperties.material = material;
    atlasScaleBias.Set(1.0f, 1.0f, 0.0f, 0.0f);
    hasEmissivePass = 0;
    usesTransSortAtlas = 0;
    isTransparencySorted = 0;
    alphaBlended = 0;
    materialTraits_t traits;
    if (material != nullptr && materialTraitsCallback != nullptr &&
            materialTraitsCallback(material, traits)) {
        atlasScaleBias = traits.atlasScaleBias;
        hasEmissivePass = traits.hasEmissivePass ? 1 : 0;
        usesTransSortAtlas = traits.usesTransSortAtlas ? 1 : 0;
        isTransparencySorted = traits.isTransparencySorted ? 1 : 0;
        alphaBlended = (traits.alphaBlended ||
            traits.isTransparencySorted) ? 1 : 0;
    }
}

void idParticleStage::SetMaterialCallbacks(
        MaterialTraitsCallback traits,
        DefaultMaterialCallback defaultMaterial) {
    materialTraitsCallback = traits;
    defaultMaterialCallback = defaultMaterial;
}

void idParticleStage::SetStaticMesh(
    const idStaticParticleModelData* data, const idDrawVert* vertices,
    int vertexCount) {
    staticData = data;
    if (data != nullptr && vertices == nullptr) {
        staticVerts = data->staticVerts;
        numStaticVerts = data->numStaticVerts;
    } else {
        staticVerts = vertices;
        numStaticVerts = vertexCount;
    }
}

int idParticleStage::NumVertsPerParticle() const {
    if (staticVerts != nullptr && numStaticVerts > 0) {
        return numStaticVerts;
    }
    if (orientation.type == POR_TRAIL) {
        return 4 * (orientation.numTrails + 1);
    }
    return 4;
}

void idParticleStage::CalculateBounds(const idLookupTable* tables) {
    bounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    bounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);

    particleInput_t input{};
    input.stage = this;
    input.tables = tables;
    input.modelAxis = idMat3(1.0f);
    input.globalAxis = idMat3(1.0f);
    input.stageAxis = idMat3(1.0f);
    input.localViewLeft.Set(0.0f, 1.0f, 0.0f);
    input.localViewUp.Set(0.0f, 0.0f, 1.0f);
    input.distribScale.Set(1.0f, 1.0f, 1.0f);
    input.entityColor.Set(1.0f, 1.0f, 1.0f, 1.0f);
    input.sizeScale = 1.0f;
    input.fade = 1.0f;
    input.shadow = 1.0f;
    input.alphaScaleOverride = 1.0f;
    input.totalParticles = systemProperties.totalParticles;

    const int lifeMilliseconds = static_cast<int>(maxParticleLife * 1000.0f);
    std::uint32_t diversitySeed = 0;
    bool sampledOrigin = false;
    for (int sample = 0; sample < 100 && lifeMilliseconds > 0; ++sample) {
        particleGen_t particle;
        particle.index = systemProperties.totalParticles;
        particle.particleLife = maxParticleLife;
        particle.random.SetSeed(diversitySeed);
        particle.originalRandom = particle.random;
        diversitySeed = diversitySeed * 1664525u + 1013904223u;
        const int diversity = static_cast<int>(
            (diversitySeed >> 10) & 0x7FFFu);
        input.stageAxis = ParticleStageAxis(this, diversity);
        for (int milliseconds = 0; milliseconds < lifeMilliseconds;
                milliseconds += 16) {
            const int time = (std::min)(milliseconds,
                lifeMilliseconds - 1);
            particle.cycleAge = time * 0.001f;
            particle.totalAge = particle.cycleAge;
            particle.frac = time / static_cast<float>(lifeMilliseconds);
            particle.parmVal = particle.frac;
            const idVec3 origin = ParticleOrigin(input, particle);
            for (int axis = 0; axis < 3; ++axis) {
                bounds[0][axis] = (std::min)(bounds[0][axis], origin[axis]);
                bounds[1][axis] = (std::max)(bounds[1][axis], origin[axis]);
            }
            sampledOrigin = true;
            if (milliseconds + 16 >= lifeMilliseconds &&
                    milliseconds != lifeMilliseconds - 1) {
                milliseconds = lifeMilliseconds - 17;
            }
        }
    }
    if (!sampledOrigin) {
        bounds[0].Zero();
        bounds[1].Zero();
    }

    idVec3 maximumSize(0.0f, 0.0f, 0.0f);
    idRandom2 sizeRandom(diversitySeed);
    for (int sample = 0; sample <= 64; ++sample) {
        const float fraction = sample * (1.0f / 64.0f);
        idVec3 sampledSize;
        if (staticData != nullptr) {
            for (int axis = 0; axis < 3; ++axis) {
                sampledSize[axis] = size.size[axis].Compute(tables,
                    fraction, sizeRandom);
            }
        } else {
            float baseSize = size.size[0].Compute(tables, fraction,
                sizeRandom);
            const float aspect = size.aspectRatio.Compute(tables,
                fraction, sizeRandom);
            if (orientation.type == POR_AIMED) {
                sampledSize.Set(baseSize,
                    orientation.segmentLength * aspect, baseSize);
            } else {
                if (aspect > 1.0f) baseSize *= aspect;
                sampledSize.Set(baseSize, baseSize, baseSize);
            }
        }
        for (int axis = 0; axis < 3; ++axis) {
            maximumSize[axis] = (std::max)(maximumSize[axis],
                sampledSize[axis]);
        }
    }

    for (int axis = 0; axis < 3; ++axis) {
        const float expansion = maximumSize[axis] + 8.0f +
            systemProperties.boundsExpansion;
        bounds[0][axis] -= expansion;
        bounds[1][axis] += expansion;
    }
}
