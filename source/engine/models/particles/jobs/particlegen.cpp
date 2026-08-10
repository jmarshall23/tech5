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

idMat3 VectorToMat3(idVec3 forward) {
    if (forward.NormalizeFast() == 0.0f) {
        return idMat3(1.0f);
    }
    idVec3 left;
    if (std::fabs(forward.x) > 0.7f) {
        const float length = std::sqrt(forward.x * forward.x
            + forward.y * forward.y);
        left.Set(-forward.y / length, forward.x / length, 0.0f);
    } else {
        const float length = std::sqrt(forward.y * forward.y
            + forward.z * forward.z);
        left.Set(0.0f, -forward.z / length, forward.y / length);
    }
    idVec3 up = forward.Cross(left);
    up.NormalizeFast();
    return idMat3(
        forward.x, forward.y, forward.z,
        left.x, left.y, left.z,
        up.x, up.y, up.z);
}

idVec3 RandomUnitVector(idRandom2& random) {
    idVec3 value(random.CRandomFloat(), random.CRandomFloat(),
        random.CRandomFloat());
    if (value.NormalizeFast() == 0.0f) {
        value.Set(0.0f, 0.0f, 1.0f);
    }
    return value;
}

void ProjectOntoSphere(idVec3& value, const float radius) {
    const float radiusSquared = radius * radius;
    const float planarSquared = value.x * value.x + value.y * value.y;
    if (planarSquared < radiusSquared * 0.5f) {
        value.z = std::sqrt((std::max)(0.0f,
            radiusSquared - planarSquared));
    } else if (planarSquared > 1.0e-30f) {
        value.z = radiusSquared * 0.5f / std::sqrt(planarSquared);
    } else {
        value.z = radius;
    }
}

float Evaluate(const idParticleParm& parm, const particleInput_t& input,
    particleGen_t& particle) {
    return parm.Compute(input.tables, particle.parmVal, particle.random);
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
    const int usableFrames = stage.texAnimation.useRandomRow
        ? columns : columns * rows;
    int startFrame = stage.texAnimation.startFrame;
    if (startFrame < 0) {
        startFrame = usableFrames > 1
            ? particle.random.RandomInt(usableFrames) : 0;
    }

    textureAnimationState_t result{};
    result.scaleS = 1.0f / static_cast<float>(columns);
    result.scaleT = 1.0f / static_cast<float>(rows);
    if (columns > 1 || rows > 1) {
        float framePosition = static_cast<float>(startFrame);
        if (stage.texAnimation.type == PANIM_TYPE_CYLE_RATE) {
            const float rate = stage.texAnimation.rate.Compute(input.tables,
                particle.parmVal, particle.random);
            framePosition += stage.texAnimation.rate.calcType
                    == PARTICLE_CALC_GENERIC
                ? particle.totalAge * rate : rate;
        } else if (stage.texAnimation.type
                == PANIM_TYPE_SINGLE_CYCLE_RATE) {
            const float rate = stage.texAnimation.rate.Compute(input.tables,
                particle.parmVal, particle.random);
            framePosition += stage.texAnimation.rate.calcType
                    == PARTICLE_CALC_GENERIC
                ? particle.frac * rate : rate;
            framePosition = (std::min)(framePosition,
                static_cast<float>(usableFrames - 1));
        } else {
            framePosition += particle.frac
                * static_cast<float>(usableFrames);
        }

        const int unwrappedFrame = static_cast<int>(framePosition);
        const float blendFraction = framePosition
            - static_cast<float>(unwrappedFrame);
        int frame = unwrappedFrame % usableFrames;
        if (frame < 0) frame += usableFrames;
        const int nextFrame = (frame + 1) % usableFrames;
        int frameRow;
        int nextRow;
        if (stage.texAnimation.useRandomRow) {
            frameRow = rows > 1 ? particle.random.RandomInt(rows) : 0;
            nextRow = frameRow;
        } else {
            frameRow = frame / columns;
            nextRow = nextFrame / columns;
        }
        const int frameColumn = frame % columns;
        const int nextColumn = nextFrame % columns;
        result.biasS = frameColumn * result.scaleS;
        result.biasT = frameRow * result.scaleT;
        result.nextBiasS = nextColumn * result.scaleS;
        result.nextBiasT = nextRow * result.scaleT;
        result.blend = stage.texAnimation.useFrameBlending
            ? static_cast<std::uint8_t>((std::max)(0, (std::min)(255,
                static_cast<int>(blendFraction * 255.0f)))) : 0;
    } else {
        result.biasS = 0.0f;
        result.biasT = 0.0f;
        result.nextBiasS = 0.0f;
        result.nextBiasT = 0.0f;
        result.blend = 0;
    }
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
    const unsigned int cycleSeed = randomOnCycle
        ? (static_cast<unsigned int>(cycle) << 10) & 0x7C00u : 0u;
    unsigned int seed = cycleSeed
        ^ (static_cast<unsigned int>(diversity) & 0x7FFFu);
    for (int advance = 0; advance <= particleIndex; ++advance) {
        seed = 1664525u * seed + 1013904223u;
    }
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
    input.totalParticles = baseInput.totalParticles;
    if (input.totalParticles <= 0) return 0;

    int generated = 0;
    const int spawnWindow = static_cast<int>((std::max)(0.0f,
        stage.systemProperties.spawnBunching * stage.bunchTime) * 1000.0f);
    int firstParticle = 0;
    if ((stage.systemProperties.sortType == PSORT_TYPE_NEWEST_TO_OLDEST
            || stage.systemProperties.sortType
                == PSORT_TYPE_OLDEST_TO_NEWEST)
            && input.totalParticles > 1) {
        for (int candidate = 1; candidate < input.totalParticles;
                ++candidate) {
            const int candidateTime = stageTimeMilliseconds
                - candidate * spawnWindow / input.totalParticles;
            if (candidateTime >= 0
                    && stageTimeMilliseconds % cycleMilliseconds
                        < candidateTime % cycleMilliseconds) {
                firstParticle = candidate;
                break;
            }
        }
    }
    for (int order = 0; order < input.totalParticles; ++order) {
        int index = order;
        if (stage.systemProperties.sortType ==
                PSORT_TYPE_NEWEST_TO_OLDEST) {
            index = firstParticle + input.totalParticles - 1 - order;
        } else if (stage.systemProperties.sortType ==
                PSORT_TYPE_OLDEST_TO_NEWEST) {
            index = firstParticle + order;
        }
        index %= input.totalParticles;
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
    for (int axis = 0; axis < 3; ++axis) {
        distributionSize[axis] = Evaluate(stage.distribution.size[axis],
            input, particle) * input.distribScale[axis];
    }

    idVec3 distributed(0.0f, 0.0f, 0.0f);
    switch (stage.distribution.type) {
    case PDIST_CYLINDER: {
        const float angleCoordinate = stage.distribution.random
            ? particle.random.CRandomFloat() : 1.0f;
        const float heightCoordinate = stage.distribution.random
            ? particle.random.CRandomFloat() : 1.0f;
        const float angle = angleCoordinate * 2.0f * kPi;
        distributed.Set(std::cos(angle) * distributionSize.x,
            std::sin(angle) * distributionSize.y,
            heightCoordinate * distributionSize.z);
        break;
    }
    case PDIST_SPHERE: {
        idVec3 direction = stage.distribution.random
            ? RandomUnitVector(particle.random)
            : idVec3(1.0f, 1.0f, 1.0f);
        distributed.Set(direction.x * distributionSize.x,
            direction.y * distributionSize.y,
            direction.z * distributionSize.z);
        break;
    }
    case PDIST_RECT_SURFACE: {
        distributed.Set(particle.random.CRandomFloat() * distributionSize.x,
            particle.random.CRandomFloat() * distributionSize.y,
            particle.random.CRandomFloat() * distributionSize.z);
        const int face = particle.random.RandomInt(6);
        const int axis = face % 3;
        distributed[axis] = (face < 3 ? 1.0f : -1.0f)
            * distributionSize[axis];
        break;
    }
    case PDIST_CYLINDER_SURFACE: {
        const float angle = particle.random.CRandomFloat() * 2.0f * kPi;
        distributed.Set(std::cos(angle) * distributionSize.x,
            std::sin(angle) * distributionSize.y,
            particle.random.CRandomFloat() * distributionSize.z);
        break;
    }
    case PDIST_SPHERE_SURFACE: {
        const idVec3 direction = RandomUnitVector(particle.random);
        distributed.Set(direction.x * distributionSize.x,
            direction.y * distributionSize.y,
            direction.z * distributionSize.z);
        break;
    }
    case PDIST_RECT:
    default:
        if (stage.distribution.random) {
            distributed.Set(
                particle.random.CRandomFloat() * distributionSize.x,
                particle.random.CRandomFloat() * distributionSize.y,
                particle.random.CRandomFloat() * distributionSize.z);
        } else {
            distributed = distributionSize;
        }
        break;
    }

    switch (stage.customPath.type) {
    case PPATH_HELIX: {
        const float axialSpeed = Evaluate(stage.customPath.parms[4], input,
            particle);
        const float angularSpeed = Evaluate(stage.customPath.parms[3], input,
            particle);
        const float angle = particle.random.RandomFloat() * 2.0f * kPi
            + particle.cycleAge * angularSpeed;
        const float radiusX = Evaluate(stage.customPath.parms[0], input,
            particle) * input.distribScale.x;
        const float radiusY = Evaluate(stage.customPath.parms[1], input,
            particle) * input.distribScale.y;
        const float heightRange = Evaluate(stage.customPath.parms[2], input,
            particle) * input.distribScale.z;
        distributed.x += std::cos(angle) * radiusX;
        distributed.y += std::sin(angle) * radiusY;
        distributed.z += particle.random.RandomFloat() * heightRange
            + particle.cycleAge * axialSpeed;
        break;
    }
    case PPATH_FLIES: {
        const float firstRate = Evaluate(stage.customPath.parms[0], input,
            particle);
        const float secondRate = Evaluate(stage.customPath.parms[1], input,
            particle);
        const float firstScale = (std::max)(0.4f,
            particle.random.RandomFloat());
        const float secondScale = (std::max)(0.4f,
            particle.random.RandomFloat());
        const float firstAngle = particle.random.RandomFloat()
            * 2.0f * kPi + particle.cycleAge * firstScale * firstRate;
        const float secondAngle = particle.random.RandomFloat()
            * 2.0f * kPi + particle.cycleAge * secondScale * secondRate;
        const float radius = Evaluate(stage.customPath.parms[2], input,
            particle) * input.distribScale.x;
        const float sinFirst = std::sin(firstAngle);
        const float cosFirst = std::cos(firstAngle);
        const float sinSecond = std::sin(secondAngle);
        const float cosSecond = std::cos(secondAngle);
        distributed.x += sinSecond * sinFirst * radius;
        distributed.y += sinSecond * cosFirst * radius;
        distributed.z -= cosSecond * radius;
        break;
    }
    case PPATH_ORBIT: {
        const float angularSpeed = Evaluate(stage.customPath.parms[1], input,
            particle);
        const float angle = particle.random.RandomFloat() * 2.0f * kPi
            + particle.cycleAge * angularSpeed;
        const float radius = Evaluate(stage.customPath.parms[0], input,
            particle);
        idVec3 orbit(radius * std::cos(angle), radius * std::sin(angle),
            0.0f);
        ProjectOntoSphere(orbit, radius);
        distributed = distributed + orbit;
        break;
    }
    case PPATH_DRIP:
        distributed.z -= particle.cycleAge * Evaluate(
            stage.customPath.parms[0], input, particle);
        break;
    default:
        break;
    }

    const float spawnFraction = input.totalParticles > 1
        ? static_cast<float>(particle.index)
            / static_cast<float>(input.totalParticles - 1)
        : 0.0f;
    idVec3 origin = distributed;
    for (int axis = 0; axis < 3; ++axis) {
        origin[axis] += stage.spawnLocation.spawnLocation[axis].Compute(
            input.tables, spawnFraction, particle.random);
    }
    for (int axis = 0; axis < 3; ++axis) {
        origin[axis] += Evaluate(stage.offset.offset[axis], input, particle);
    }

    idVec3 speed;
    for (int axis = 0; axis < 3; ++axis) {
        const float friction = Clamp01(Evaluate(
            stage.friction.friction[axis], input, particle));
        const float speedFraction = particle.frac
            - 0.5f * particle.frac * particle.parmVal * friction;
        speed[axis] = stage.speed.speed[axis].Compute(input.tables,
            speedFraction, particle.random);
    }

    idVec3 direction;
    switch (stage.direction.type) {
    case PDIR_OUTWARD:
        direction = origin;
        direction.NormalizeFast();
        direction.z += stage.direction.parms[0];
        break;
    case PDIR_SPEED:
        direction = speed;
        direction.NormalizeFast();
        speed.x = std::fabs(speed.x);
        speed.y = std::fabs(speed.y);
        speed.z = std::fabs(speed.z);
        break;
    case PDIR_CONE:
    default: {
        const float polar = particle.random.CRandomFloat()
            * stage.direction.parms[0] * kDegreesToRadians;
        const float azimuth = particle.random.CRandomFloat() * kPi;
        const float sinPolar = std::sin(polar);
        direction.Set(std::cos(azimuth) * sinPolar,
            std::sin(azimuth) * sinPolar, std::cos(polar));
        break;
    }
    }

    idVec3 speedTravel(direction.x * speed.x, direction.y * speed.y,
        direction.z * speed.z);
    if (stage.direction.type == PDIR_CONE) {
        speedTravel = TransformVector(stage.direction.coneAxis,
            speedTravel);
    }
    speedTravel = speedTravel * particle.particleLife;

    idVec3 acceleration;
    for (int axis = 0; axis < 3; ++axis) {
        acceleration[axis] = Evaluate(
            stage.acceleration.acceleration[axis], input, particle);
    }
    if (stage.acceleration.world) {
        acceleration = TransformVector(input.modelAxis.Transpose(),
            acceleration);
    }

    idVec3 gravity(0.0f, 0.0f,
        -Evaluate(stage.gravity.gravity, input, particle));
    if (stage.gravity.world) {
        gravity = TransformVector(input.modelAxis.Transpose(), gravity);
    }
    const float windBias = Evaluate(stage.systemProperties.windBias,
        input, particle);
    const float age = particle.cycleAge;
    const idVec3 travel = speedTravel + (acceleration
        + gravity * age + input.wind * windBias) * age;
    origin = origin + travel;
    origin = TransformVector(input.stageAxis, origin);
    origin = input.globalOrigin + TransformVector(input.globalAxis, origin);

    if (stage.orientation.depthOffset > 0.0f) {
        idVec3 viewDirection = input.localViewOrg - origin;
        if (viewDirection.NormalizeFast() != 0.0f) {
            origin = origin
                + viewDirection * stage.orientation.depthOffset;
        }
    }

    if (velocity != nullptr) {
        const idVec3 orientationTravel = stage.orientation.orientToVelOnly
            ? speedTravel : travel;
        *velocity = TransformVector(input.stageAxis, orientationTravel)
            + input.localVelocity;
    }
    return origin;
}

idVec4 ComputeParticleColor(const particleInput_t& input,
    particleGen_t& particle) {
    const idParticleStage& stage = *input.stage;
    float lifeFade = 1.0f;
    if (particle.frac < stage.colorAttributes.fadeInFraction
            && stage.colorAttributes.fadeInFraction > 0.0f) {
        lifeFade = particle.frac
            / stage.colorAttributes.fadeInFraction;
    }
    const float remaining = 1.0f - particle.frac;
    if (remaining < stage.colorAttributes.fadeOutFraction
            && stage.colorAttributes.fadeOutFraction > 0.0f) {
        lifeFade *= remaining / stage.colorAttributes.fadeOutFraction;
    }
    if (stage.colorAttributes.fadeIndexFraction > 0.0f
            && input.totalParticles > 0) {
        const float indexRemaining = static_cast<float>(
            input.totalParticles - particle.index)
            / static_cast<float>(input.totalParticles);
        if (indexRemaining < stage.colorAttributes.fadeIndexFraction) {
            lifeFade *= indexRemaining
                / stage.colorAttributes.fadeIndexFraction;
        }
    }

    const float brightness = Evaluate(stage.colorAttributes.brightness,
        input, particle);
    const float shadow = (std::max)(stage.colorAttributes.minShadowVal,
        input.shadow);
    const float rgbFade = stage.alphaBlended ? 1.0f : input.fade;
    const float alphaFade = stage.alphaBlended ? input.fade : 1.0f;
    idVec4 result;
    for (int component = 0; component < 4; ++component) {
        const float base = Evaluate(stage.colorAttributes.baseColor[component],
            input, particle);
        const float faded = stage.colorAttributes.fadeColor[component]
                * (1.0f - lifeFade)
            + base * lifeFade;
        const float entity = 1.0f + (input.entityColor[component] - 1.0f)
            * stage.colorAttributes.entityColorBlendVal;
        result[component] = faded * entity;
    }
    result.x *= brightness * shadow * rgbFade;
    result.y *= brightness * shadow * rgbFade;
    result.z *= brightness * shadow * rgbFade;
    result.w *= alphaFade;
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

int GenerateQuadVerts(const particleInput_t& input, particleGen_t& particle,
    particleOutput_t& output, const idVec3& origin, const idVec3& velocity) {
    const idParticleStage& stage = *input.stage;
    (void)velocity;
    const textureAnimationState_t animation =
        ComputeTextureAnimation(input, particle);
    const float width = Evaluate(stage.size.size[0], input, particle)
        * input.sizeScale;
    const float height = Evaluate(stage.size.aspectRatio, input, particle)
        * width;

    idVec3 widthAxis;
    idVec3 heightAxis;
    if (stage.orientation.type == POR_XYZ) {
        const idAngles angles(
            Evaluate(stage.initialRotation.initialAngle[0], input, particle)
                + Evaluate(stage.rotation.rotation[0], input, particle)
                    * particle.particleLife,
            Evaluate(stage.initialRotation.initialAngle[1], input, particle)
                + Evaluate(stage.rotation.rotation[1], input, particle)
                    * particle.particleLife,
            Evaluate(stage.initialRotation.initialAngle[2], input, particle)
                + Evaluate(stage.rotation.rotation[2], input, particle)
                    * particle.particleLife);
        const idMat3 rotation = angles.ToMat3();
        widthAxis = rotation[0];
        heightAxis = rotation[1];
    } else {
        const float initial = Evaluate(
            stage.initialRotation.initialAngle[0], input, particle);
        const float rotation = Evaluate(stage.rotation.rotation[0], input,
            particle) * particle.particleLife;
        const float angle = initial
            + (((particle.index & 1) != 0
                    && stage.rotation.allowRotDirOverride)
                ? -rotation : rotation);
        const float sine = std::sin(angle * kDegreesToRadians);
        const float cosine = std::cos(angle * kDegreesToRadians);
        switch (stage.orientation.type) {
        case POR_X:
            widthAxis.Set(0.0f, cosine, sine);
            heightAxis.Set(0.0f, -sine, cosine);
            break;
        case POR_Y:
            widthAxis.Set(cosine, 0.0f, sine);
            heightAxis.Set(-sine, 0.0f, cosine);
            break;
        case POR_Z:
            widthAxis.Set(cosine, sine, 0.0f);
            heightAxis.Set(-sine, cosine, 0.0f);
            break;
        case POR_VIEW:
        default:
            widthAxis = input.localViewLeft * cosine
                + input.localViewUp * sine;
            heightAxis = input.localViewUp * cosine
                - input.localViewLeft * sine;
            break;
        }
    }

    widthAxis = TransformVector(input.globalAxis, widthAxis);
    heightAxis = TransformVector(input.globalAxis, heightAxis);
    if (stage.orientation.world) {
        const idMat3 worldToModel = input.modelAxis.Transpose();
        widthAxis = TransformVector(worldToModel, widthAxis);
        heightAxis = TransformVector(worldToModel, heightAxis);
    }
    widthAxis = widthAxis * width;
    heightAxis = heightAxis * height;
    const idVec3 pivot = widthAxis * stage.pivot.pivotOffset.x
        + heightAxis * stage.pivot.pivotOffset.y;
    const idVec3 corners[4] = {
        origin - widthAxis + heightAxis + pivot,
        origin + widthAxis + heightAxis + pivot,
        origin - widthAxis - heightAxis + pivot,
        origin + widthAxis - heightAxis + pivot
    };
    idVec4 color = particle.vertColor;
    if (stage.orientation.type != POR_VIEW
            && stage.orientation.viewFade < 1.0f) {
        idVec3 viewDirection = origin + pivot - input.localViewOrg;
        viewDirection.NormalizeFast();
        idVec3 normal = widthAxis.Cross(heightAxis);
        normal.NormalizeFast();
        const float denominator = 1.0f - stage.orientation.viewFade;
        const float blend = denominator > 1.0e-7f
            ? Clamp01((1.0f - std::fabs(normal.Dot(viewDirection))
                - stage.orientation.viewFade) / denominator)
            : 0.0f;
        for (int component = 0; component < 4; ++component) {
            const float faded = stage.colorAttributes.fadeColor[component]
                * input.entityColor[component];
            color[component] = color[component] * (1.0f - blend)
                + faded * blend;
        }
    }
    InitializeQuad(output.verts, corners, color);
    const idVec2 texCoords[4] = {
        idVec2(0.0f, 0.0f), idVec2(1.0f, 0.0f),
        idVec2(0.0f, 1.0f), idVec2(1.0f, 1.0f)
    };
    for (int vertex = 0; vertex < 4; ++vertex) {
        ParticleTexCoord(input, animation, texCoords[vertex],
            output.verts[vertex]);
    }
    StoreQuadDepth(input, origin, output.quadDepth);
    return 4;
}

int GenerateAimedVerts(const particleInput_t& input, particleGen_t& particle,
    particleOutput_t& output, const idVec3& origin, idVec3 velocity) {
    const idParticleStage& stage = *input.stage;
    const float size = Evaluate(stage.size.size[0], input, particle)
        * input.sizeScale;
    const float aspect = Evaluate(stage.size.aspectRatio, input, particle);
    velocity = TransformVector(input.globalAxis, velocity);
    if (velocity.NormalizeFast() == 0.0f) {
        velocity.Set(0.0f, 0.0f, 1.0f);
    }
    idVec3 viewDirection = origin - input.localViewOrg;
    if (viewDirection.NormalizeFast() == 0.0f) {
        viewDirection.Set(0.0f, 0.0f, 1.0f);
    }
    idVec3 side = velocity.Cross(viewDirection);
    if (side.NormalizeFast() == 0.0f) {
        side = input.localViewLeft;
        side.NormalizeFast();
    }
    if (stage.orientation.world) {
        const idMat3 worldToModel = input.modelAxis.Transpose();
        velocity = TransformVector(worldToModel, velocity);
        side = TransformVector(worldToModel, side);
    }

    idVec3 lengthVector = velocity
        * (stage.orientation.segmentLength * aspect);
    if (stage.orientation.aimedSafeQuad) {
        const idVec3 center = origin + lengthVector * 0.5f;
        idVec3 centerViewDirection = center - input.localViewOrg;
        centerViewDirection.NormalizeFast();
        float blend = std::fabs(centerViewDirection.Dot(velocity));
        if (stage.orientation.aimedSafeQuadAlign != 1.0f) {
            const float denominator = (std::max)(1.0e-6f,
                stage.orientation.aimedSafeQuadAlign - 1.0e-6f);
            blend = Clamp01((blend
                - (1.0f - stage.orientation.aimedSafeQuadAlign))
                / denominator);
        }
        const idVec3 safeLength = centerViewDirection.Cross(side)
            * (size * aspect);
        lengthVector = lengthVector * (1.0f - blend)
            + safeLength * blend;
    }
    side = side * size;
    const idVec3 end = origin + lengthVector;
    const idVec3 corners[4] = {
        end - side, end + side, origin - side, origin + side
    };
    idVec4 color = particle.vertColor;
    if (stage.orientation.viewFade < 1.0f) {
        idVec3 actualDirection = lengthVector;
        actualDirection.NormalizeFast();
        const float denominator = 1.0f - stage.orientation.viewFade;
        const float blend = denominator > 1.0e-7f
            ? Clamp01((std::fabs(actualDirection.Dot(viewDirection))
                - stage.orientation.viewFade) / denominator)
            : 0.0f;
        for (int component = 0; component < 4; ++component) {
            const float faded = stage.colorAttributes.fadeColor[component]
                * input.entityColor[component];
            color[component] = color[component] * (1.0f - blend)
                + faded * blend;
        }
    }
    InitializeQuad(output.verts, corners, color);
    const idVec2 texCoords[4] = {
        idVec2(0.0f, 0.0f), idVec2(1.0f, 0.0f),
        idVec2(0.0f, 1.0f), idVec2(1.0f, 1.0f)
    };
    ParticleTexCoords(input, particle, output.verts, texCoords, 4);
    StoreQuadDepth(input, origin + lengthVector * 0.5f,
        output.quadDepth);
    return 4;
}

int GenerateTrailVerts(const particleInput_t& input, particleGen_t& particle,
    particleOutput_t& output, const idVec3& origin) {
    const idParticleStage& stage = *input.stage;
    const int segments = (std::max)(1,
        static_cast<int>(stage.orientation.numTrails) + 1);
    const float width = Evaluate(stage.size.size[0], input, particle)
        * input.sizeScale;
    const float aspect = Evaluate(stage.size.aspectRatio, input, particle);
    const float timeStep = stage.orientation.segmentLength * aspect
        / static_cast<float>(segments);
    const idRandom2 savedRandom = particle.random;
    int generated = 0;
    idVec3 currentPoint = origin;
    for (int segment = 0; segment < segments; ++segment) {
        const float sampleAge = particle.cycleAge
            - static_cast<float>(segment + 1) * timeStep;
        if (sampleAge < 0.0f) {
            if (timeStep >= 0.0f) break;
            continue;
        }

        particleGen_t sample = particle;
        sample.random = particle.originalRandom;
        sample.cycleAge = sampleAge;
        sample.frac = Clamp01(sampleAge / sample.particleLife);
        idVec3 sampleVelocity;
        const idVec3 olderPoint = ParticleOrigin(input, sample,
            &sampleVelocity);
        idVec3 segmentVector = currentPoint - olderPoint;
        idVec3 direction = segmentVector;
        if (direction.NormalizeFast() == 0.0f) continue;
        const idVec3 midpoint = (currentPoint + olderPoint) * 0.5f;
        idVec3 viewDirection = midpoint - input.localViewOrg;
        viewDirection.NormalizeFast();
        idVec3 side = direction.Cross(viewDirection);
        if (side.NormalizeFast() == 0.0f) {
            side = input.localViewLeft;
            side.NormalizeFast();
        }
        if (stage.orientation.aimedSafeQuad) {
            float blend = std::fabs(viewDirection.Dot(direction));
            if (stage.orientation.aimedSafeQuadAlign != 1.0f) {
                const float denominator = (std::max)(1.0e-6f,
                    stage.orientation.aimedSafeQuadAlign - 1.0e-6f);
                blend = Clamp01((blend
                    - (1.0f - stage.orientation.aimedSafeQuadAlign))
                    / denominator);
            }
            const idVec3 safeSegment = viewDirection.Cross(side)
                * (aspect * width);
            segmentVector = segmentVector * (1.0f - blend)
                + safeSegment * blend;
        }
        const idVec3 adjustedStart = midpoint - segmentVector * 0.5f;
        const idVec3 adjustedEnd = midpoint + segmentVector * 0.5f;
        side = side * width;
        const idVec3 corners[4] = {
            adjustedEnd - side, adjustedEnd + side,
            adjustedStart - side, adjustedStart + side
        };
        idVec4 color = particle.vertColor;
        if (stage.orientation.viewFade < 1.0f) {
            idVec3 actualDirection = segmentVector;
            actualDirection.NormalizeFast();
            const float denominator = 1.0f - stage.orientation.viewFade;
            const float blend = denominator > 1.0e-7f
                ? Clamp01((std::fabs(actualDirection.Dot(viewDirection))
                    - stage.orientation.viewFade) / denominator)
                : 0.0f;
            for (int component = 0; component < 4; ++component) {
                const float faded = stage.colorAttributes.fadeColor[component]
                    * input.entityColor[component];
                color[component] = color[component] * (1.0f - blend)
                    + faded * blend;
            }
        }
        InitializeQuad(output.verts + generated, corners, color);
        const float t0 = static_cast<float>(segment)
            / static_cast<float>(segments);
        const float t1 = static_cast<float>(segment + 1)
            / static_cast<float>(segments);
        const idVec2 source[4] = {
            idVec2(0.0f, t0), idVec2(1.0f, t0),
            idVec2(0.0f, t1), idVec2(1.0f, t1)
        };
        const textureAnimationState_t animation =
            ComputeTextureAnimation(input, sample);
        for (int vertex = 0; vertex < 4; ++vertex) {
            ParticleTexCoord(input, animation, source[vertex],
                output.verts[generated + vertex]);
        }
        StoreQuadDepth(input, midpoint,
            output.quadDepth != nullptr
                ? output.quadDepth + generated / 4 : nullptr);
        generated += 4;
        currentPoint = olderPoint;
    }
    particle.random = savedRandom;
    return generated;
}

int GenerateStaticMeshVerts(const particleInput_t& input,
    particleGen_t& particle, particleOutput_t& output,
    const idVec3& origin) {
    const idParticleStage& stage = *input.stage;
    if (input.staticVerts == nullptr || stage.numStaticVerts <= 0) return 0;
    const textureAnimationState_t animation =
        ComputeTextureAnimation(input, particle);
    idVec3 scale;
    for (int axis = 0; axis < 3; ++axis) {
        scale[axis] = Evaluate(stage.size.size[axis], input, particle)
            * input.sizeScale;
    }
    const idAngles angles(
        Evaluate(stage.initialRotation.initialAngle[0], input, particle)
            + Evaluate(stage.rotation.rotation[0], input, particle)
                * particle.particleLife,
        Evaluate(stage.initialRotation.initialAngle[1], input, particle)
            + Evaluate(stage.rotation.rotation[1], input, particle)
                * particle.particleLife,
        Evaluate(stage.initialRotation.initialAngle[2], input, particle)
            + Evaluate(stage.rotation.rotation[2], input, particle)
                * particle.particleLife);
    idMat3 rotation = angles.ToMat3();
    if (stage.orientation.type == POR_VIEW) {
        rotation *= VectorToMat3(origin - input.localViewOrg);
    }
    rotation *= input.globalAxis;
    for (int index = 0; index < stage.numStaticVerts; ++index) {
        const idDrawVert& source = input.staticVerts[index];
        idVec3 local(source.xyz.x * scale.x, source.xyz.y * scale.y,
            source.xyz.z * scale.z);
        local = TransformVector(rotation, local);
        InitializeVertex(output.verts[index], origin + local,
            particle.vertColor);
        ParticleTexCoord(input, animation, source.st, output.verts[index]);
        output.verts[index].st1[0] = output.verts[index].st[0];
        output.verts[index].st1[1] = output.verts[index].st[1];
    }
    return stage.numStaticVerts;
}

int CreateParticle(const particleInput_t& input, particleGen_t& particle,
    particleOutput_t& output) {
    if (input.stage == nullptr || output.verts == nullptr) {
        return 0;
    }
    const idParticleStage& stage = *input.stage;
    particle.random = particle.originalRandom;
    idVec3 velocity;
    idVec3 origin = ParticleOrigin(input, particle, &velocity);
    particle.vertColor = ComputeParticleColor(input, particle);
    if (ToColorByte(particle.vertColor.x) == 0
            && ToColorByte(particle.vertColor.y) == 0
            && ToColorByte(particle.vertColor.z) == 0) {
        return 0;
    }

    idVec4 genericParm;
    for (int component = 0; component < 4; ++component) {
        genericParm[component] = Evaluate(
            stage.genericParm.genericParm[component], input, particle);
    }
    const float softParticleScale = input.alphaScaleOverride < 1.0f
        ? input.alphaScaleOverride
        : stage.colorAttributes.softParticleAlphaScale;
    const std::uint8_t softParticleByte = static_cast<std::uint8_t>(
        (std::max)(0, (std::min)(255,
            static_cast<int>(softParticleScale * 255.0f))));

    int generated = 0;
    if (stage.orientation.type == POR_TRAIL) {
        generated = GenerateTrailVerts(input, particle, output, origin);
    } else if (stage.staticData != nullptr || stage.staticVerts != nullptr) {
        generated = GenerateStaticMeshVerts(input, particle, output, origin);
    } else if (stage.orientation.type == POR_AIMED) {
        generated = GenerateAimedVerts(input, particle, output, origin,
            velocity);
    } else {
        generated = GenerateQuadVerts(input, particle, output, origin,
            velocity);
    }
    const std::uint8_t genericBytes[4] = {
        ToColorByte(genericParm.x), ToColorByte(genericParm.y),
        ToColorByte(genericParm.z), ToColorByte(genericParm.w)
    };
    for (int index = 0; index < generated; ++index) {
        std::memcpy(output.verts[index].normal, genericBytes,
            sizeof(genericBytes));
        output.verts[index].tangent[3] = softParticleByte;
    }
    return generated;
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
    input.localVelocity = model.velocity;
    input.localVelocity.NormalizeFast();
    input.distribScale = model.distribScale;
    input.wind = TransformVector(model.axis.Transpose(),
        idAngles(model.wind.x, model.wind.y, model.wind.z).ToForward() *
            model.wind.w);
    input.entityColor = model.color;
    const float lodBlend = Clamp01(static_cast<float>(model.lod) *
        stage.lodParms.lerpAmount);
    input.totalParticles = static_cast<int>(
        stage.systemProperties.totalParticles +
        (stage.lodParms.totalParticles -
            stage.systemProperties.totalParticles) * lodBlend);
    if (input.totalParticles <= 0) return 0;
    input.sizeScale = 1.0f +
        (stage.lodParms.sizeScale - 1.0f) * lodBlend;
    input.fade = model.coverage;
    input.shadow = stage.colorAttributes.useGlobalShadows
        ? model.shadow : 1.0f;
    input.alphaScaleOverride = model.alphaScaleOverride;
    if (parms->renderView != nullptr) {
        const idMat3 worldToModel = model.axis.Transpose();
        if (stage.isTransparencySorted) {
            input.globalOrigin = model.origin;
            input.globalAxis[0] = model.axis[0] * model.scale.x;
            input.globalAxis[1] = model.axis[1] * model.scale.y;
            input.globalAxis[2] = model.axis[2] * model.scale.z;
            input.localViewOrg = parms->renderView->viewOrg;
            input.localViewLeft = TransformVector(worldToModel,
                parms->renderView->viewLeft);
            input.localViewUp = TransformVector(worldToModel,
                parms->renderView->viewUp);
        } else {
            input.globalOrigin.Zero();
            input.globalAxis = idMat3(1.0f);
            input.localViewOrg = TransformVector(worldToModel,
                parms->renderView->viewOrg - model.origin);
            input.localViewLeft = TransformVector(worldToModel,
                parms->renderView->viewLeft);
            input.localViewUp = TransformVector(worldToModel,
                parms->renderView->viewUp);
        }
    } else if (stage.isTransparencySorted) {
        input.globalOrigin = model.origin;
        input.globalAxis[0] = model.axis[0] * model.scale.x;
        input.globalAxis[1] = model.axis[1] * model.scale.y;
        input.globalAxis[2] = model.axis[2] * model.scale.z;
    } else {
        input.globalOrigin.Zero();
        input.globalAxis = idMat3(1.0f);
    }
    const int renderTime = parms->renderView != nullptr
        ? parms->renderView->renderTime : 0;
    const int stageTime = static_cast<int>((renderTime * 0.001f
        - (stage.systemProperties.timeOffset + model.timeOffset))
        * 1000.0f);
    const int cycleMilliseconds = static_cast<int>((
        stage.maxParticleLife + parms->deadTime) * 1000.0f);
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
    input.localVelocity = TransformVector(effect.axis.Transpose(),
        effect.velocity);
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
    const int particlesToGenerate = (std::max)(0, effect.numParticles);
    if (particlesToGenerate == 0) return 0;
    input.totalParticles = (std::max)(1, static_cast<int>(
        stage.systemProperties.totalParticles));
    if (parms->renderView != nullptr) {
        input.localViewOrg = parms->renderView->viewOrg;
        const idMat3 worldToEffect = effect.axis.Transpose();
        input.localViewLeft = TransformVector(worldToEffect,
            parms->renderView->viewLeft);
        input.localViewUp = TransformVector(worldToEffect,
            parms->renderView->viewUp);
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
        particle.random.SetSeed(ParticleSeed(effect.diversity,
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
