#include "models/particles/jobs/particlestage.h"

#include "models/particles/jobs/staticparticlemodeldata.h"

#include <algorithm>
#include <cmath>
#include <cstring>

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
    CalculateBounds(nullptr);
}

void idParticleStage::SetMaterial(const idMaterial* material) {
    systemProperties.material = material;
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
    maxParticleLife = (std::max)(0.0f,
        systemProperties.particleLife.GetMaxParmVal(tables));
    maxDeadTime = (std::max)(0.0f,
        systemProperties.deadTime.GetMaxParmVal(tables));
    cycleMsec = static_cast<int>((maxParticleLife + maxDeadTime) * 1000.0f);
    bunchTime = systemProperties.emissionTime > 0.0f
        ? systemProperties.emissionTime : maxParticleLife;

    idVec3 distributionExtent;
    idVec3 offsetExtent;
    idVec3 accelerationExtent;
    float maximumSpeed = 0.0f;
    for (int axis = 0; axis < 3; ++axis) {
        distributionExtent[axis] = std::fabs(
            distribution.size[axis].GetMaxParmVal(tables));
        offsetExtent[axis] = std::fabs(
            offset.offset[axis].GetMaxParmVal(tables))
            + std::fabs(spawnLocation.spawnLocation[axis]
                .GetMaxParmVal(tables));
        maximumSpeed = (std::max)(maximumSpeed,
            std::fabs(speed.speed[axis].GetMaxParmVal(tables)));
        accelerationExtent[axis] = std::fabs(
            acceleration.acceleration[axis].GetMaxParmVal(tables));
    }

    const float gravityExtent = std::fabs(
        gravity.gravity.GetMaxParmVal(tables));
    const float travel = maximumSpeed * maxParticleLife
        + 0.5f * (std::max)({ accelerationExtent.x,
            accelerationExtent.y, accelerationExtent.z, gravityExtent })
            * maxParticleLife * maxParticleLife;
    const float particleSize = (std::max)({
        std::fabs(size.size[0].GetMaxParmVal(tables)),
        std::fabs(size.size[1].GetMaxParmVal(tables)),
        std::fabs(size.size[2].GetMaxParmVal(tables)) });
    const float expansion = particleSize
        + std::fabs(systemProperties.boundsExpansion) + travel;

    for (int axis = 0; axis < 3; ++axis) {
        const float extent = distributionExtent[axis]
            + offsetExtent[axis] + expansion;
        bounds[0][axis] = -extent;
        bounds[1][axis] = extent;
    }

    if (staticVerts != nullptr && numStaticVerts > 0) {
        for (int vertex = 0; vertex < numStaticVerts; ++vertex) {
            for (int axis = 0; axis < 3; ++axis) {
                bounds[0][axis] = (std::min)(bounds[0][axis],
                    staticVerts[vertex].xyz[axis] - expansion);
                bounds[1][axis] = (std::max)(bounds[1][axis],
                    staticVerts[vertex].xyz[axis] + expansion);
            }
        }
    }
}
