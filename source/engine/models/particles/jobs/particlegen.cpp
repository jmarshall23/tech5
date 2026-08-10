#include "models/particles/jobs/particlegen.h"

#include "idlib/lookuptable.h"
#include "models/particles/jobs/particlestage.h"
#include "models/transparency/jobs/transparencyvert.h"

#include <algorithm>
#include <cmath>
#include <cstring>

namespace {

constexpr float kPi = 3.14159265358979323846f;
constexpr float kDegreesToRadians = kPi / 180.0f;

float Clamp01(const float value) {
    return (std::max)(0.0f, (std::min)(1.0f, value));
}

idVec3 TransformVector(const idMat3& axis, const idVec3& value) {
    return idVec3(
        axis[0].x * value.x + axis[1].x * value.y + axis[2].x * value.z,
        axis[0].y * value.x + axis[1].y * value.y + axis[2].y * value.z,
        axis[0].z * value.x + axis[1].z * value.y + axis[2].z * value.z);
}

idMat3 RotationMatrix(const idVec3& rawAxis, const float angle) {
    idVec3 axis = rawAxis;
    if (axis.NormalizeFast() == 0.0f) {
        return idMat3(1.0f);
    }
    const float sine = std::sin(angle);
    const float cosine = std::cos(angle);
    const float oneMinusCosine = 1.0f - cosine;
    return idMat3(
        cosine + axis.x * axis.x * oneMinusCosine,
        axis.x * axis.y * oneMinusCosine - axis.z * sine,
        axis.x * axis.z * oneMinusCosine + axis.y * sine,
        axis.y * axis.x * oneMinusCosine + axis.z * sine,
        cosine + axis.y * axis.y * oneMinusCosine,
        axis.y * axis.z * oneMinusCosine - axis.x * sine,
        axis.z * axis.x * oneMinusCosine - axis.y * sine,
        axis.z * axis.y * oneMinusCosine + axis.x * sine,
        cosine + axis.z * axis.z * oneMinusCosine);
}

idVec3 RandomUnitVector(idRandom2& random) {
    idVec3 value;
    do {
        value.Set(random.CRandomFloat(), random.CRandomFloat(),
            random.CRandomFloat());
    } while (value.LengthSqr() <= 1.0e-12f || value.LengthSqr() > 1.0f);
    value.NormalizeFast();
    return value;
}

float Evaluate(const idParticleParm& parm, const particleInput_t& input,
    particleGen_t& particle) {
    return parm.Compute(input.tables, particle.frac, particle.random);
}

std::uint8_t ToColorByte(const float value) {
    return static_cast<std::uint8_t>(
        Clamp01(value) * 255.0f + 0.5f);
}

void SetTexCoord(idTransparencyVert& vertex, const float s, const float t) {
    const int packedS = static_cast<int>(std::floor(
        (Clamp01(s) - 0.5f) * 65534.0f + 0.5f));
    const int packedT = static_cast<int>(std::floor(
        (Clamp01(t) - 0.5f) * 65534.0f + 0.5f));
    vertex.st[0] = static_cast<std::int16_t>((std::max)(-32768,
        (std::min)(32767, packedS)));
    vertex.st[1] = static_cast<std::int16_t>((std::max)(-32768,
        (std::min)(32767, packedT)));
    vertex.st1[0] = vertex.st[0];
    vertex.st1[1] = vertex.st[1];
}

void InitializeVertex(idTransparencyVert& vertex, const idVec3& position,
    const idVec4& color) {
    vertex.xyz = position;
    vertex.normal[0] = 128;
    vertex.normal[1] = 128;
    vertex.normal[2] = 255;
    vertex.normal[3] = 255;
    vertex.tangent[0] = 255;
    vertex.tangent[1] = 128;
    vertex.tangent[2] = 128;
    vertex.tangent[3] = 255;
    vertex.color[0] = ToColorByte(color.x);
    vertex.color[1] = ToColorByte(color.y);
    vertex.color[2] = ToColorByte(color.z);
    vertex.color[3] = ToColorByte(color.w);
}

struct textureAnimationState_t {
    float scaleS;
    float scaleT;
    float biasS;
    float biasT;
    float nextBiasS;
    float nextBiasT;
    std::uint8_t blend;
    bool flipS;
    bool flipT;
};

textureAnimationState_t ComputeTextureAnimation(
    const particleInput_t& input, particleGen_t& particle) {
    const idParticleStage& stage = *input.stage;
    const int columns = (std::max)(1,
        static_cast<int>(stage.texAnimation.numColumns));
    const int rows = (std::max)(1,
        static_cast<int>(stage.texAnimation.numRows));
    const int row = stage.texAnimation.useRandomRow
        ? particle.random.RandomInt(rows) : -1;
    const int usableFrames = stage.texAnimation.useRandomRow
        ? columns : columns * rows;
    int startFrame = stage.texAnimation.startFrame;
    if (startFrame < 0) startFrame = particle.random.RandomInt(usableFrames);

    const float rate = Evaluate(stage.texAnimation.rate, input, particle);
    float framePosition = static_cast<float>(startFrame);
    switch (stage.texAnimation.type) {
    case PANIM_TYPE_CYLE_RATE:
        framePosition += particle.totalAge * rate;
        break;
    case PANIM_TYPE_SINGLE_CYCLE_RATE:
        framePosition += (stage.texAnimation.rate.calcType
            == PARTICLE_CALC_GENERIC ? particle.frac * rate : rate);
        framePosition = (std::min)(framePosition,
            static_cast<float>(usableFrames - 1));
        break;
    case PANIM_TYPE_SINGLE_CYCLE:
    default:
        framePosition += particle.frac
            * static_cast<float>((std::max)(0, usableFrames - 1));
        break;
    }

    int frame = static_cast<int>(std::floor(framePosition));
    const float blendFraction = framePosition - std::floor(framePosition);
    if (stage.texAnimation.type == PANIM_TYPE_CYLE_RATE) {
        frame %= usableFrames;
        if (frame < 0) frame += usableFrames;
    } else {
        frame = (std::max)(0, (std::min)(usableFrames - 1, frame));
    }
    int nextFrame = frame + 1;
    if (nextFrame >= usableFrames) {
        nextFrame = stage.texAnimation.type == PANIM_TYPE_CYLE_RATE ? 0 : frame;
    }

    int frameRow = row;
    int nextRow = row;
    int frameColumn = frame;
    int nextColumn = nextFrame;
    if (!stage.texAnimation.useRandomRow) {
        frameRow = frame / columns;
        nextRow = nextFrame / columns;
        frameColumn = frame % columns;
        nextColumn = nextFrame % columns;
    } else {
        frameColumn %= columns;
        nextColumn %= columns;
    }

    textureAnimationState_t result{};
    result.scaleS = 1.0f / static_cast<float>(columns);
    result.scaleT = 1.0f / static_cast<float>(rows);
    result.biasS = frameColumn * result.scaleS;
    result.biasT = frameRow * result.scaleT;
    result.nextBiasS = nextColumn * result.scaleS;
    result.nextBiasT = nextRow * result.scaleT;
    result.blend = stage.texAnimation.useFrameBlending
        ? ToColorByte(blendFraction) : 0;
    const bool oddParticle = (particle.index & 1) != 0;
    result.flipS = stage.systemProperties.textureFlipS
            == PTEXTURE_FLIP_ALWAYS
        || (stage.systemProperties.textureFlipS == PTEXTURE_FLIP_RANDOM
            && oddParticle);
    result.flipT = stage.systemProperties.textureFlipT
            == PTEXTURE_FLIP_ALWAYS
        || (stage.systemProperties.textureFlipT == PTEXTURE_FLIP_RANDOM
            && oddParticle);
    return result;
}

void ApplyTextureAtlas(const particleInput_t& input, float& s, float& t) {
    const idParticleStage& stage = *input.stage;
    if (!stage.usesTransSortAtlas) return;
    const float width = input.view != nullptr
        ? static_cast<float>((std::max)(1,
            static_cast<int>(input.view->atlasWidth))) : 1.0f;
    const float height = input.view != nullptr
        ? static_cast<float>((std::max)(1,
            static_cast<int>(input.view->atlasHeight))) : 1.0f;
    const float scaleS = (std::max)(1.0e-6f, stage.atlasScaleBias.x);
    const float scaleT = (std::max)(1.0e-6f, stage.atlasScaleBias.y);
    s = (std::max)(0.5f / (width * scaleS),
        (std::min)(1.0f - 0.5f / (width * scaleS), s));
    t = (std::max)(0.5f / (height * scaleT),
        (std::min)(1.0f - 0.5f / (height * scaleT), t));
    s = s * stage.atlasScaleBias.x + stage.atlasScaleBias.z;
    t = t * stage.atlasScaleBias.y + stage.atlasScaleBias.w;
}

void ParticleTexCoord(const particleInput_t& input,
    const textureAnimationState_t& animation, const idVec2& source,
    idTransparencyVert& vertex) {
    const float sourceS = animation.flipS ? 1.0f - source.x : source.x;
    const float sourceT = animation.flipT ? 1.0f - source.y : source.y;
    float s = animation.biasS + sourceS * animation.scaleS;
    float t = animation.biasT + sourceT * animation.scaleT;
    float nextS = animation.nextBiasS + sourceS * animation.scaleS;
    float nextT = animation.nextBiasT + sourceT * animation.scaleT;
    ApplyTextureAtlas(input, s, t);
    ApplyTextureAtlas(input, nextS, nextT);
    SetTexCoord(vertex, s, t);
    idTransparencyVert next{};
    SetTexCoord(next, nextS, nextT);
    vertex.st1[0] = next.st[0];
    vertex.st1[1] = next.st[1];
    vertex.tangent[0] = ToColorByte(source.x);
    vertex.tangent[1] = ToColorByte(source.y);
    vertex.tangent[2] = animation.blend;
}

void ParticleTexCoords(const particleInput_t& input, particleGen_t& particle,
    idTransparencyVert* verts, const idVec2* sourceTexCoords,
    const int vertexCount) {
    const textureAnimationState_t animation =
        ComputeTextureAnimation(input, particle);
    for (int index = 0; index < vertexCount; ++index) {
        ParticleTexCoord(input, animation, sourceTexCoords[index],
            verts[index]);
    }
}

unsigned int ParticleSeed(const int diversity, const int particleIndex,
        const int cycle, const bool randomOnCycle) {
    unsigned int seed = static_cast<unsigned int>(diversity) & 0x7FFFu;
    seed ^= static_cast<unsigned int>(particleIndex + 1) * 0x9E3779B9u;
    if (randomOnCycle)
        seed ^= static_cast<unsigned int>(cycle + 1) * 0x85EBCA6Bu;
    return seed;
}

void AverageStageDepths(const deferredParticleGenParms_t* parms,
        const int firstVertex, const int endVertex) {
    if (parms == nullptr || parms->quadDepth == nullptr ||
            endVertex <= firstVertex) return;
    const int firstQuad = firstVertex / 4;
    const int numQuads = (endVertex - firstVertex) / 4;
    if (numQuads <= 0) return;
    float total = 0.0f;
    for (int index = 0; index < numQuads; ++index)
        total += parms->quadDepth[firstQuad + index];
    const float average = total / static_cast<float>(numQuads);
    for (int index = 0; index < numQuads; ++index)
        parms->quadDepth[firstQuad + index] = average;
}

int GenerateModelStage(const deferredParticleGenParms_t* parms,
    const idParticleStage& stage, const particleInput_t& baseInput,
    const int diversity, const int stageTimeMilliseconds,
    const int renderTimeMilliseconds, const int stopTime,
    const int cycleMilliseconds, int vertOffset) {
    if (parms == nullptr || parms->verts == nullptr
        || vertOffset >= parms->maxVertsToGen || stage.hidden ||
        stage.systemProperties.material == nullptr || cycleMilliseconds <= 0) {
        return 0;
    }

    particleInput_t input = baseInput;
    input.stage = &stage;
    input.tables = parms->tables;
    input.view = parms->renderView;
    input.staticVerts = stage.staticVerts != nullptr
        ? stage.staticVerts : parms->staticVerts;
    input.stageAxis = ParticleStageAxis(&stage, diversity);
    input.influenceSpheres = nullptr;
    input.numInfluenceSpheres = 0;
    input.totalParticles = (std::max)(1, baseInput.totalParticles);

    int generated = 0;
    const int spawnWindow = static_cast<int>((std::max)(0.0f,
        stage.systemProperties.spawnBunching * stage.bunchTime) * 1000.0f);
    for (int order = 0; order < input.totalParticles; ++order) {
        const int index = stage.systemProperties.sortType ==
                PSORT_TYPE_NEWEST_TO_OLDEST
            ? input.totalParticles - 1 - order : order;
        const int particleTime = stageTimeMilliseconds -
            index * spawnWindow / input.totalParticles;
        if (particleTime < 0) continue;
        const int cycle = particleTime / cycleMilliseconds;
        if (stage.systemProperties.cycles > 0 &&
                cycle >= stage.systemProperties.cycles) continue;
        const int cycleAgeMilliseconds = particleTime % cycleMilliseconds;
        if (stopTime != 0 &&
                renderTimeMilliseconds - cycleAgeMilliseconds >= stopTime)
            continue;

        particleGen_t particle;
        particle.index = index;
        particle.random.SetSeed(ParticleSeed(diversity, index, cycle,
            stage.systemProperties.randomOnCycle));
        const float indexFraction = static_cast<float>(index) /
            static_cast<float>(input.totalParticles);
        particle.particleLife = (std::max)(0.001f,
            stage.systemProperties.particleLife.Compute(parms->tables,
                indexFraction, particle.random));
        particle.originalRandom = particle.random;
        particle.cycleAge = cycleAgeMilliseconds * 0.001f;
        particle.totalAge = particleTime * 0.001f;
        if (particle.cycleAge > particle.particleLife) continue;
        particle.frac = particle.cycleAge / particle.particleLife;
        particle.parmVal = stage.systemProperties.useSysTime != 0.0f
            ? renderTimeMilliseconds * 0.001f *
                stage.systemProperties.useSysTime
            : Clamp01(particle.frac);

        const int vertsPerParticle = stage.NumVertsPerParticle();
        if (vertOffset + generated + vertsPerParticle
            > parms->maxVertsToGen) {
            break;
        }
        particleOutput_t output = {
            parms->verts + vertOffset + generated,
            parms->quadDepth != nullptr
                ? parms->quadDepth + (vertOffset + generated) / 4
                : nullptr
        };
        generated += CreateParticle(input, particle, output);
    }
    if (stage.systemProperties.sortType == PSORT_TYPE_NEWEST_TO_OLDEST ||
            stage.systemProperties.sortType == PSORT_TYPE_OLDEST_TO_NEWEST)
        AverageStageDepths(parms, vertOffset, vertOffset + generated);
    return generated;
}

} // namespace

idMat3 ParticleStageAxis(const idParticleStage* stage,
    const int diversity) {
    if (stage == nullptr) {
        return idMat3(1.0f);
    }
    idRandom2 random(static_cast<unsigned int>((diversity << 10) & 0x7C00));
    idMat3 result(1.0f);
    const idVec3 rotationAxes[2] = {
        idVec3(0.0f, 1.0f, 0.0f), idVec3(0.0f, 0.0f, 1.0f)
    };
    for (int index = 0; index < 2; ++index) {
        const float range = std::fabs(stage->direction.angleOffsetRange[index]);
        const float angle = stage->direction.angleOffsetStart[index]
            + random.CRandomFloat() * range;
        if (std::fabs(angle) > 1.0e-7f) {
            result *= RotationMatrix(rotationAxes[index],
                angle * kDegreesToRadians);
        }
    }
    return result;
}

idVec3 ParticleOrigin(const particleInput_t& input,
    particleGen_t& particle, idVec3* velocity) {
    const idParticleStage& stage = *input.stage;
    idVec3 distributionSize;
    idVec3 spawnOffset;
    idVec3 localOffset;
    for (int axis = 0; axis < 3; ++axis) {
        distributionSize[axis] = Evaluate(stage.distribution.size[axis],
            input, particle) * input.distribScale[axis];
        spawnOffset[axis] = Evaluate(stage.spawnLocation.spawnLocation[axis],
            input, particle);
        localOffset[axis] = Evaluate(stage.offset.offset[axis], input,
            particle);
    }

    idVec3 distributed(0.0f, 0.0f, 0.0f);
    switch (stage.distribution.type) {
    case PDIST_CYLINDER:
    case PDIST_CYLINDER_SURFACE: {
        const float angle = particle.random.RandomFloat() * 2.0f * kPi;
        const float radius = stage.distribution.type == PDIST_CYLINDER_SURFACE
            ? 1.0f : std::sqrt(particle.random.RandomFloat());
        distributed.Set(std::cos(angle) * radius * distributionSize.x,
            std::sin(angle) * radius * distributionSize.y,
            particle.random.CRandomFloat() * distributionSize.z);
        break;
    }
    case PDIST_SPHERE:
    case PDIST_SPHERE_SURFACE: {
        idVec3 direction = RandomUnitVector(particle.random);
        const float radius = stage.distribution.type == PDIST_SPHERE_SURFACE
            ? 1.0f : std::cbrt(particle.random.RandomFloat());
        distributed.Set(direction.x * radius * distributionSize.x,
            direction.y * radius * distributionSize.y,
            direction.z * radius * distributionSize.z);
        break;
    }
    case PDIST_RECT_SURFACE: {
        distributed.Set(particle.random.CRandomFloat() * distributionSize.x,
            particle.random.CRandomFloat() * distributionSize.y,
            particle.random.CRandomFloat() * distributionSize.z);
        const int face = particle.random.RandomInt(3);
        distributed[face] = (particle.random.RandomInt(2) == 0 ? -1.0f : 1.0f)
            * distributionSize[face];
        break;
    }
    case PDIST_RECT:
    default:
        distributed.Set(particle.random.CRandomFloat() * distributionSize.x,
            particle.random.CRandomFloat() * distributionSize.y,
            particle.random.CRandomFloat() * distributionSize.z);
        break;
    }

    idVec3 direction;
    if (stage.direction.type == PDIR_OUTWARD) {
        direction = distributed;
        if (direction.NormalizeFast() == 0.0f) direction.Set(0.0f, 0.0f, 1.0f);
    } else if (stage.direction.type == PDIR_SPEED) {
        direction = input.localVelocity;
        if (direction.NormalizeFast() == 0.0f) direction.Set(0.0f, 0.0f, 1.0f);
    } else {
        const float coneAngle = stage.direction.parms[0]
            * kDegreesToRadians;
        const float azimuth = particle.random.RandomFloat() * 2.0f * kPi;
        const float polar = particle.random.RandomFloat() * coneAngle;
        direction.Set(std::sin(polar) * std::cos(azimuth),
            std::sin(polar) * std::sin(azimuth), std::cos(polar));
        direction = TransformVector(stage.direction.coneAxis, direction);
    }
    direction = TransformVector(input.stageAxis, direction);

    idVec3 particleVelocity;
    idVec3 localTravel;
    for (int axis = 0; axis < 3; ++axis) {
        const idParticleParm& speedParm = stage.speed.speed[axis];
        const float speedValue = Evaluate(speedParm, input, particle);
        particleVelocity[axis] = direction[axis] * speedValue
            + input.localVelocity[axis];
        if (speedParm.calcType == PARTICLE_CALC_PARAMETRIC_INTEGRATE
                || speedParm.calcType
                    == PARTICLE_CALC_PARAMETRIC_INTEGRATE_MINMAX) {
            localTravel[axis] = direction[axis] * speedValue
                * particle.particleLife + input.localVelocity[axis]
                * particle.cycleAge;
        } else {
            localTravel[axis] = particleVelocity[axis] * particle.cycleAge;
        }
        const float friction = std::fabs(Evaluate(
            stage.friction.friction[axis], input, particle));
        localTravel[axis] /= 1.0f + friction * particle.cycleAge;
    }
    const float age = particle.cycleAge;
    idVec3 position = distributed + spawnOffset + localOffset + localTravel;
    idVec3 worldTravel(0.0f, 0.0f, 0.0f);
    for (int axis = 0; axis < 3; ++axis) {
        const float acceleration = Evaluate(
            stage.acceleration.acceleration[axis], input, particle);
        if (stage.acceleration.world) {
            worldTravel[axis] += 0.5f * acceleration * age * age;
        } else {
            position[axis] += 0.5f * acceleration * age * age;
        }
        position[axis] += input.wind[axis]
            * Evaluate(stage.systemProperties.windBias, input, particle)
            * age;
    }
    const float gravityTravel = 0.5f
        * Evaluate(stage.gravity.gravity, input, particle) * age * age;
    if (stage.gravity.world) worldTravel.z -= gravityTravel;
    else position.z -= gravityTravel;

    switch (stage.customPath.type) {
    case PPATH_HELIX: {
        const float radius = Evaluate(stage.customPath.parms[0], input,
            particle);
        const float turns = Evaluate(stage.customPath.parms[1], input,
            particle);
        const float angle = turns * age * 2.0f * kPi;
        position.x += std::cos(angle) * radius;
        position.y += std::sin(angle) * radius;
        break;
    }
    case PPATH_ORBIT: {
        const float radius = Evaluate(stage.customPath.parms[0], input,
            particle);
        const float rate = Evaluate(stage.customPath.parms[1], input,
            particle);
        const float angle = rate * age * 2.0f * kPi;
        position.x += std::cos(angle) * radius;
        position.y += std::sin(angle) * radius;
        break;
    }
    case PPATH_FLIES:
        position = position + RandomUnitVector(particle.random)
            * Evaluate(stage.customPath.parms[0], input, particle);
        break;
    case PPATH_DRIP:
        position.z -= Evaluate(stage.customPath.parms[0], input, particle)
            * age * age;
        break;
    default:
        break;
    }

    if (velocity != nullptr) {
        *velocity = TransformVector(input.globalAxis, particleVelocity);
    }
    return input.globalOrigin + TransformVector(input.globalAxis, position)
        + worldTravel;
}

float EvaluateIntegratedAngle(const idParticleParm& parm,
    const particleInput_t& input, particleGen_t& particle) {
    const float value = Evaluate(parm, input, particle);
    return parm.calcType == PARTICLE_CALC_PARAMETRIC_INTEGRATE
            || parm.calcType == PARTICLE_CALC_PARAMETRIC_INTEGRATE_MINMAX
        ? value * particle.particleLife : value;
}

idVec4 ComputeParticleColor(const particleInput_t& input,
    particleGen_t& particle) {
    const idParticleStage& stage = *input.stage;
    float lifeFade = input.fade;
    float colorBlend = 0.0f;
    if (particle.frac < stage.colorAttributes.fadeInFraction
            && stage.colorAttributes.fadeInFraction > 0.0f) {
        const float fraction = particle.frac
            / stage.colorAttributes.fadeInFraction;
        lifeFade *= fraction;
        colorBlend = (std::max)(colorBlend, 1.0f - fraction);
    }
    const float remaining = 1.0f - particle.frac;
    if (remaining < stage.colorAttributes.fadeOutFraction
            && stage.colorAttributes.fadeOutFraction > 0.0f) {
        const float fraction = remaining
            / stage.colorAttributes.fadeOutFraction;
        lifeFade *= fraction;
        colorBlend = (std::max)(colorBlend, 1.0f - fraction);
    }
    if (stage.colorAttributes.fadeIndexFraction > 0.0f
            && input.totalParticles > 1) {
        const float indexFraction = static_cast<float>(particle.index)
            / static_cast<float>(input.totalParticles - 1);
        if (indexFraction > 1.0f - stage.colorAttributes.fadeIndexFraction) {
            lifeFade *= (1.0f - indexFraction)
                / stage.colorAttributes.fadeIndexFraction;
        }
    }

    const float brightness = Evaluate(stage.colorAttributes.brightness,
        input, particle);
    const float shadow = stage.colorAttributes.useGlobalShadows
        ? (std::max)(stage.colorAttributes.minShadowVal, input.shadow) : 1.0f;
    idVec4 result;
    for (int component = 0; component < 4; ++component) {
        const float base = Evaluate(stage.colorAttributes.baseColor[component],
            input, particle);
        const float faded = base + (stage.colorAttributes.fadeColor[component]
            - base) * Clamp01(colorBlend);
        const float entity = 1.0f + (input.entityColor[component] - 1.0f)
            * Clamp01(stage.colorAttributes.entityColorBlendVal);
        result[component] = faded * entity * brightness;
    }
    result.x *= shadow;
    result.y *= shadow;
    result.z *= shadow;
    result.w *= Clamp01(lifeFade) * input.alphaScaleOverride;
    return result;
}

void StoreQuadDepth(const particleInput_t& input, const idVec3& center,
    float* depth) {
    if (depth != nullptr && input.view != nullptr) {
        *depth = input.view->viewFwd.Dot(center - input.view->viewOrg);
    }
}

void InitializeQuad(idTransparencyVert* verts, const idVec3 corners[4],
    const idVec4& color) {
    for (int vertex = 0; vertex < 4; ++vertex) {
        InitializeVertex(verts[vertex], corners[vertex], color);
    }
}

void BuildQuadAxes(const particleInput_t& input, particleGen_t& particle,
    const idVec3& origin, const idVec3& velocity, idVec3& left,
    idVec3& up) {
    const idParticleStage& stage = *input.stage;
    left = input.localViewLeft;
    up = input.localViewUp;
    const idMat3 worldAxis(1.0f);
    const idMat3& fixedAxis = stage.orientation.world
        ? worldAxis : input.globalAxis;
    if (stage.orientation.type == POR_X) {
        left = TransformVector(fixedAxis, idVec3(0.0f, 1.0f, 0.0f));
        up = TransformVector(fixedAxis, idVec3(0.0f, 0.0f, 1.0f));
    } else if (stage.orientation.type == POR_Y) {
        left = TransformVector(fixedAxis, idVec3(1.0f, 0.0f, 0.0f));
        up = TransformVector(fixedAxis, idVec3(0.0f, 0.0f, 1.0f));
    } else if (stage.orientation.type == POR_Z) {
        left = TransformVector(fixedAxis, idVec3(1.0f, 0.0f, 0.0f));
        up = TransformVector(fixedAxis, idVec3(0.0f, 1.0f, 0.0f));
    } else if (stage.orientation.type == POR_XYZ) {
        const int plane = particle.index % 3;
        if (plane == 0) {
            left = TransformVector(fixedAxis, idVec3(0.0f, 1.0f, 0.0f));
            up = TransformVector(fixedAxis, idVec3(0.0f, 0.0f, 1.0f));
        } else if (plane == 1) {
            left = TransformVector(fixedAxis, idVec3(1.0f, 0.0f, 0.0f));
            up = TransformVector(fixedAxis, idVec3(0.0f, 0.0f, 1.0f));
        } else {
            left = TransformVector(fixedAxis, idVec3(1.0f, 0.0f, 0.0f));
            up = TransformVector(fixedAxis, idVec3(0.0f, 1.0f, 0.0f));
        }
    } else if (stage.orientation.type == POR_AIMED
            || stage.orientation.type == POR_TRAIL) {
        idVec3 forward = velocity;
        if (forward.NormalizeFast() == 0.0f) forward.Set(0.0f, 0.0f, 1.0f);
        left = forward.Cross(input.localViewOrg - origin);
        if (left.NormalizeFast() == 0.0f) left = input.localViewLeft;
        up = left.Cross(forward);
        if (up.NormalizeFast() == 0.0f) up = input.localViewUp;
    }
}

int GenerateQuadVerts(const particleInput_t& input, particleGen_t& particle,
    particleOutput_t& output, const idVec3& origin, const idVec3& velocity) {
    const idParticleStage& stage = *input.stage;
    idVec3 left;
    idVec3 up;
    BuildQuadAxes(input, particle, origin, velocity, left, up);

    const float width = std::fabs(Evaluate(stage.size.size[0], input,
        particle) * input.sizeScale);
    const float heightValue = std::fabs(Evaluate(stage.size.size[1], input,
        particle) * input.sizeScale);
    const float aspect = std::fabs(Evaluate(stage.size.aspectRatio, input,
        particle));
    const float height = heightValue * (aspect > 1.0e-6f ? aspect : 1.0f);
    const float angle = EvaluateIntegratedAngle(
        stage.initialRotation.initialAngle[0], input, particle)
        + EvaluateIntegratedAngle(stage.rotation.rotation[0], input,
            particle);
    if (std::fabs(angle) > 1.0e-6f) {
        const float sine = std::sin(angle * kDegreesToRadians);
        const float cosine = std::cos(angle * kDegreesToRadians);
        const idVec3 oldLeft = left;
        left = oldLeft * cosine + up * sine;
        up = up * cosine - oldLeft * sine;
    }
    left = left * width;
    up = up * height;
    const idVec3 pivot = left * stage.pivot.pivotOffset.x
        + up * stage.pivot.pivotOffset.y;
    const idVec3 corners[4] = {
        origin - left - up + pivot,
        origin + left - up + pivot,
        origin + left + up + pivot,
        origin - left + up + pivot
    };
    InitializeQuad(output.verts, corners, particle.vertColor);
    const idVec2 texCoords[4] = {
        idVec2(0.0f, 0.0f), idVec2(1.0f, 0.0f),
        idVec2(1.0f, 1.0f), idVec2(0.0f, 1.0f)
    };
    ParticleTexCoords(input, particle, output.verts, texCoords, 4);
    StoreQuadDepth(input, origin, output.quadDepth);
    return 4;
}

int GenerateAimedVerts(const particleInput_t& input, particleGen_t& particle,
    particleOutput_t& output, const idVec3& origin, idVec3 velocity) {
    const idParticleStage& stage = *input.stage;
    if (velocity.NormalizeFast() == 0.0f) velocity.Set(0.0f, 0.0f, 1.0f);
    const float length = std::fabs(stage.orientation.segmentLength);
    const idVec3 tail = origin - velocity * length;
    idVec3 side = velocity.Cross(input.localViewOrg - origin);
    if (side.NormalizeFast() == 0.0f) side = input.localViewLeft;
    if (stage.orientation.aimedSafeQuad) {
        const float alignment = std::fabs(velocity.Dot(input.localViewUp));
        if (alignment > stage.orientation.aimedSafeQuadAlign) {
            side = input.localViewLeft;
            side.NormalizeFast();
        }
    }
    const float width = std::fabs(Evaluate(stage.size.size[0], input,
        particle) * input.sizeScale);
    side = side * width;
    const idVec3 corners[4] = {
        tail - side, tail + side, origin + side, origin - side
    };
    idVec4 color = particle.vertColor;
    const float facing = Clamp01(1.0f - std::fabs(velocity.Dot(
        input.view != nullptr ? input.view->viewFwd
                              : idVec3(0.0f, 0.0f, 1.0f))));
    color.w *= stage.orientation.viewFade
        + (1.0f - stage.orientation.viewFade) * facing;
    InitializeQuad(output.verts, corners, color);
    const idVec2 texCoords[4] = {
        idVec2(0.0f, 0.0f), idVec2(1.0f, 0.0f),
        idVec2(1.0f, 1.0f), idVec2(0.0f, 1.0f)
    };
    ParticleTexCoords(input, particle, output.verts, texCoords, 4);
    StoreQuadDepth(input, (origin + tail) * 0.5f, output.quadDepth);
    return 4;
}

idVec3 ParticleOriginAtAge(const particleInput_t& input,
    const particleGen_t& source, const float age, idVec3* velocity) {
    particleGen_t sample = source;
    sample.random = source.originalRandom;
    sample.cycleAge = (std::max)(0.0f, age);
    sample.frac = Clamp01(sample.cycleAge / sample.particleLife);
    sample.parmVal = sample.frac;
    return ParticleOrigin(input, sample, velocity);
}

int GenerateTrailVerts(const particleInput_t& input, particleGen_t& particle,
    particleOutput_t& output) {
    const idParticleStage& stage = *input.stage;
    const int segments = (std::max)(1,
        static_cast<int>(stage.orientation.numTrails) + 1);
    const float timeStep = (std::max)(0.0001f,
        std::fabs(stage.orientation.segmentLength));
    const float width = std::fabs(Evaluate(stage.size.size[0], input,
        particle) * input.sizeScale);
    const textureAnimationState_t animation =
        ComputeTextureAnimation(input, particle);
    int generated = 0;
    for (int segment = 0; segment < segments; ++segment) {
        const float headAge = particle.cycleAge - segment * timeStep;
        if (headAge < 0.0f && segment > 0) break;
        const float tailAge = (std::max)(0.0f, headAge - timeStep);
        idVec3 headVelocity;
        idVec3 tailVelocity;
        const idVec3 head = ParticleOriginAtAge(input, particle,
            (std::max)(0.0f, headAge), &headVelocity);
        const idVec3 tail = ParticleOriginAtAge(input, particle, tailAge,
            &tailVelocity);
        idVec3 direction = head - tail;
        if (direction.NormalizeFast() == 0.0f) {
            direction = headVelocity;
            if (direction.NormalizeFast() == 0.0f) direction.Set(0, 0, 1);
        }
        idVec3 side = direction.Cross(input.localViewOrg - head);
        if (side.NormalizeFast() == 0.0f) side = input.localViewLeft;
        side = side * width;
        const idVec3 corners[4] = {
            tail - side, tail + side, head + side, head - side
        };
        InitializeQuad(output.verts + generated, corners,
            particle.vertColor);
        const float t0 = static_cast<float>(segment)
            / static_cast<float>(segments);
        const float t1 = static_cast<float>(segment + 1)
            / static_cast<float>(segments);
        const idVec2 source[4] = {
            idVec2(0.0f, t1), idVec2(1.0f, t1),
            idVec2(1.0f, t0), idVec2(0.0f, t0)
        };
        for (int vertex = 0; vertex < 4; ++vertex) {
            ParticleTexCoord(input, animation, source[vertex],
                output.verts[generated + vertex]);
        }
        StoreQuadDepth(input, (head + tail) * 0.5f,
            output.quadDepth != nullptr
                ? output.quadDepth + generated / 4 : nullptr);
        generated += 4;
    }
    return generated;
}

int GenerateStaticMeshVerts(const particleInput_t& input,
    particleGen_t& particle, particleOutput_t& output,
    const idVec3& origin) {
    const idParticleStage& stage = *input.stage;
    if (input.staticVerts == nullptr || stage.numStaticVerts <= 0) return 0;
    idVec3 scale;
    for (int axis = 0; axis < 3; ++axis) {
        scale[axis] = Evaluate(stage.size.size[axis], input, particle)
            * input.sizeScale;
    }
    const idAngles angles(
        EvaluateIntegratedAngle(stage.initialRotation.initialAngle[0], input,
            particle) + EvaluateIntegratedAngle(stage.rotation.rotation[0],
            input, particle),
        EvaluateIntegratedAngle(stage.initialRotation.initialAngle[1], input,
            particle) + EvaluateIntegratedAngle(stage.rotation.rotation[1],
            input, particle),
        EvaluateIntegratedAngle(stage.initialRotation.initialAngle[2], input,
            particle) + EvaluateIntegratedAngle(stage.rotation.rotation[2],
            input, particle));
    const idMat3 rotation = angles.ToMat3();
    const textureAnimationState_t animation =
        ComputeTextureAnimation(input, particle);
    for (int index = 0; index < stage.numStaticVerts; ++index) {
        const idDrawVert& source = input.staticVerts[index];
        idVec3 local(source.xyz.x * scale.x, source.xyz.y * scale.y,
            source.xyz.z * scale.z);
        local = TransformVector(rotation, local);
        const idVec3 position = origin + (stage.orientation.world
            ? local : TransformVector(input.globalAxis, local));
        idVec4 color = particle.vertColor;
        for (int component = 0; component < 4; ++component) {
            color[component] *= source.color[component] * (1.0f / 255.0f);
        }
        InitializeVertex(output.verts[index], position, color);
        std::memcpy(output.verts[index].normal, source.normal,
            sizeof(source.normal));
        output.verts[index].tangent[3] = source.tangent[3];
        ParticleTexCoord(input, animation, source.st, output.verts[index]);
    }
    for (int quad = 0; quad * 4 < stage.numStaticVerts; ++quad) {
        idVec3 center(0.0f, 0.0f, 0.0f);
        const int count = (std::min)(4, stage.numStaticVerts - quad * 4);
        for (int vertex = 0; vertex < count; ++vertex) {
            center = center + output.verts[quad * 4 + vertex].xyz;
        }
        center = center * (1.0f / static_cast<float>(count));
        StoreQuadDepth(input, center, output.quadDepth != nullptr
            ? output.quadDepth + quad : nullptr);
    }
    return stage.numStaticVerts;
}

int CreateParticle(const particleInput_t& input, particleGen_t& particle,
    particleOutput_t& output) {
    if (input.stage == nullptr || output.verts == nullptr) {
        return 0;
    }
    const idParticleStage& stage = *input.stage;
    particle.vertColor = ComputeParticleColor(input, particle);
    if (stage.orientation.type == POR_TRAIL) {
        return GenerateTrailVerts(input, particle, output);
    }
    particle.random = particle.originalRandom;
    idVec3 velocity;
    idVec3 origin = ParticleOrigin(input, particle, &velocity);
    if (stage.orientation.depthOffset != 0.0f) {
        idVec3 viewDirection = input.localViewOrg - origin;
        if (viewDirection.NormalizeFast() != 0.0f) {
            origin = origin + viewDirection * stage.orientation.depthOffset;
        }
    }
    if (stage.staticData != nullptr || stage.staticVerts != nullptr) {
        return GenerateStaticMeshVerts(input, particle, output, origin);
    }
    if (stage.orientation.type == POR_AIMED) {
        return GenerateAimedVerts(input, particle, output, origin, velocity);
    }
    return GenerateQuadVerts(input, particle, output, origin, velocity);
}

int GenParticleStage(const deferredParticleGenParms_t* parms,
    const int index, const int vertOffset) {
    if (parms == nullptr || parms->stage == nullptr
        || parms->modelParticleParms == nullptr
        || index < 0 || index >= parms->numModelParticleParms) {
        return 0;
    }
    const modelParticleParms_t& model = parms->modelParticleParms[index];
    const idParticleStage& stage = *parms->stage;
    particleInput_t input{};
    input.modelAxis = model.axis;
    input.globalOrigin = model.origin;
    input.globalAxis[0] = model.axis[0] * model.scale.x;
    input.globalAxis[1] = model.axis[1] * model.scale.y;
    input.globalAxis[2] = model.axis[2] * model.scale.z;
    input.localVelocity = model.velocity;
    input.localVelocity.NormalizeFast();
    input.distribScale = model.distribScale;
    input.wind = TransformVector(model.axis,
        idAngles(model.wind.x, model.wind.y, model.wind.z).ToForward() *
            model.wind.w);
    input.entityColor = model.color;
    const float lodBlend = Clamp01(static_cast<float>(model.lod) *
        stage.lodParms.lerpAmount);
    input.totalParticles = static_cast<int>(std::floor(
        stage.systemProperties.totalParticles +
        (stage.lodParms.totalParticles -
            stage.systemProperties.totalParticles) * lodBlend + 0.5f));
    input.totalParticles = (std::max)(1, input.totalParticles);
    input.sizeScale = 1.0f +
        (stage.lodParms.sizeScale - 1.0f) * lodBlend;
    input.fade = model.coverage;
    input.shadow = stage.colorAttributes.useGlobalShadows
        ? model.shadow : 1.0f;
    input.alphaScaleOverride = model.alphaScaleOverride;
    if (parms->renderView != nullptr) {
        input.localViewOrg = parms->renderView->viewOrg;
        input.localViewLeft = parms->renderView->viewLeft;
        input.localViewUp = parms->renderView->viewUp;
    }
    const int renderTime = parms->renderView != nullptr
        ? parms->renderView->renderTime : 0;
    const int stageTime = renderTime - static_cast<int>((
        stage.systemProperties.timeOffset + model.timeOffset) * 1000.0f);
    const float deadTime = parms->deadTime > 0.0f
        ? parms->deadTime : stage.maxDeadTime;
    const int cycleMilliseconds = static_cast<int>((
        stage.maxParticleLife + deadTime) * 1000.0f);
    const int diversity = (stage.systemProperties.diversity +
        model.diversity) & 0x7FFF;
    return GenerateModelStage(parms, stage, input, diversity, stageTime,
        renderTime, model.stopTime, cycleMilliseconds, vertOffset);
}

int GenEffectStage(const deferredParticleGenParms_t* parms,
    const int index, const int vertOffset) {
    if (parms == nullptr || parms->effectParticleParms == nullptr
        || index < 0 || index >= parms->numEffectParticleParms) {
        return 0;
    }
    const effectParticleParms_t& effect = parms->effectParticleParms[index];
    if (effect.stage == nullptr) return 0;
    const idParticleStage& stage = *effect.stage;
    if (stage.hidden || stage.systemProperties.material == nullptr)
        return 0;
    particleInput_t input{};
    input.modelAxis = effect.axis;
    input.globalAxis = effect.axis;
    input.localVelocity = effect.velocity;
    input.localVelocity.NormalizeFast();
    input.distribScale.Set(1.0f, 1.0f, 1.0f);
    input.wind = effect.wind;
    const float red = static_cast<float>((effect.color >> 0) & 0xFFu)
        * (1.0f / 255.0f);
    const float green = static_cast<float>((effect.color >> 8) & 0xFFu)
        * (1.0f / 255.0f);
    const float blue = static_cast<float>((effect.color >> 16) & 0xFFu)
        * (1.0f / 255.0f);
    input.entityColor.Set(red, green, blue, 1.0f);
    input.sizeScale = 1.0f;
    input.fade = 1.0f;
    input.shadow = effect.shadow;
    input.alphaScaleOverride = 1.0f;
    const int particlesToGenerate = effect.numParticles > 0
        ? effect.numParticles
        : (std::max)(1, static_cast<int>(
            stage.systemProperties.totalParticles));
    input.totalParticles = (std::max)(1, static_cast<int>(
        stage.systemProperties.totalParticles));
    if (parms->renderView != nullptr) {
        input.localViewOrg = parms->renderView->viewOrg;
        input.localViewLeft = parms->renderView->viewLeft;
        input.localViewUp = parms->renderView->viewUp;
    }
    const int renderTime = parms->renderView != nullptr
        ? parms->renderView->renderTime : effect.currTime;
    const int previousRenderTime = parms->renderView != nullptr
        ? renderTime - parms->renderView->deltaTime : renderTime;
    input.globalOrigin = effect.origin + effect.velocity *
        ((previousRenderTime - effect.currTime) * 0.001f);
    input.stage = &stage;
    input.tables = parms->tables;
    input.view = parms->renderView;
    input.staticVerts = stage.staticVerts != nullptr
        ? stage.staticVerts : parms->staticVerts;
    input.stageAxis = ParticleStageAxis(&stage,
        (stage.systemProperties.diversity + effect.diversity) & 0x7FFF);
    input.influenceSpheres = nullptr;
    input.numInfluenceSpheres = 0;

    const int spawnWindow = static_cast<int>((std::max)(0.0f,
        stage.systemProperties.spawnBunching * stage.bunchTime) * 1000.0f);
    int generated = 0;
    for (int order = 0; order < particlesToGenerate; ++order) {
        const int particleIndex = stage.systemProperties.sortType ==
                PSORT_TYPE_NEWEST_TO_OLDEST
            ? particlesToGenerate - 1 - order : order;
        const int emissionTime = effect.startTime +
            particleIndex * spawnWindow / input.totalParticles;
        const int ageMilliseconds = renderTime - emissionTime;
        if (ageMilliseconds < 0) continue;

        particleGen_t particle;
        particle.index = particleIndex;
        particle.random.SetSeed(ParticleSeed(
            stage.systemProperties.diversity + effect.diversity,
            particleIndex, 0, false));
        particle.particleLife = (std::max)(0.001f,
            stage.systemProperties.particleLife.Compute(parms->tables,
                static_cast<float>(particleIndex) /
                    static_cast<float>(input.totalParticles),
                particle.random));
        particle.originalRandom = particle.random;
        particle.cycleAge = ageMilliseconds * 0.001f;
        particle.totalAge = particle.cycleAge;
        if (particle.cycleAge >= particle.particleLife) continue;
        particle.frac = particle.cycleAge / particle.particleLife;
        particle.parmVal = Clamp01(particle.frac);

        const int vertexCount = stage.NumVertsPerParticle();
        if (vertOffset + generated + vertexCount > parms->maxVertsToGen)
            break;
        particleOutput_t output = {
            parms->verts + vertOffset + generated,
            parms->quadDepth != nullptr
                ? parms->quadDepth + (vertOffset + generated) / 4
                : nullptr
        };
        generated += CreateParticle(input, particle, output);
    }
    if (stage.systemProperties.sortType == PSORT_TYPE_NEWEST_TO_OLDEST)
        AverageStageDepths(parms, vertOffset, vertOffset + generated);
    return generated;
}

void ParticleGenJob(const deferredParticleGenParms_t* parms) {
    if (parms == nullptr) return;
    if (parms->quadsUsed != nullptr) *parms->quadsUsed = 0;
    if (parms->verts == nullptr || parms->maxVertsToGen <= 0) return;

    int generated = 0;
    for (int index = 0; index < parms->numModelParticleParms; ++index) {
        generated += GenParticleStage(parms, index, generated);
    }
    for (int index = 0; index < parms->numEffectParticleParms; ++index) {
        generated += GenEffectStage(parms, index, generated);
    }
    generated = (std::min)(generated, parms->maxVertsToGen);
    if (generated < parms->maxVertsToGen) {
        std::memset(parms->verts + generated, 0,
            static_cast<std::size_t>(parms->maxVertsToGen - generated)
                * sizeof(*parms->verts));
    }
    if (parms->quadDepth != nullptr) {
        const int usedQuads = generated / 4;
        const int maximumQuads = parms->maxVertsToGen / 4;
        for (int index = usedQuads; index < maximumQuads; ++index) {
            parms->quadDepth[index] = 0.0f;
        }
    }
    if (parms->quadsUsed != nullptr) {
        *parms->quadsUsed = generated / 4;
    }
}
