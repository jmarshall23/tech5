#include "gamelib/effects/electricbolt.h"

#include <algorithm>
#include <cmath>
#include <cstdint>

bool GameLib_GetElectricBoltParameters(const idDeclElectricBolt* decl,
    idElectricBoltParameters& parameters);
void GameLib_SubmitElectricBolt(idRenderModelBeam* beamModel,
    const idMaterial* material, const segment_t* segments, int numSegments,
    int currentTime, int startTime, float startWidth, float endWidth,
    const idVec4& color, float brightness, bool applyGradient,
    int revealTime, int branchLevel);

namespace {

struct BoltRandom {
    explicit BoltRandom(const std::uint32_t seed) : state(seed) {}

    float Unit() {
        state = state * 1664525u + 1013904223u;
        return static_cast<float>((state >> 8) & 0x00FFFFFFu) *
            (1.0f / 16777216.0f);
    }

    float Centered() { return Unit() * 2.0f - 1.0f; }
    std::uint32_t state;
};

idVec3 SafePerpendicular(const idVec3& direction, BoltRandom& random) {
    idVec3 reference = std::fabs(direction.z) < 0.75f
        ? idVec3(0.0f, 0.0f, 1.0f)
        : idVec3(0.0f, 1.0f, 0.0f);
    idVec3 side = direction.Cross(reference);
    if (side.NormalizeFast() == 0.0f) {
        side = idVec3(1.0f, 0.0f, 0.0f);
    }
    idVec3 up = direction.Cross(side);
    up.NormalizeFast();
    idVec3 result = side * random.Centered() + up * random.Centered();
    if (result.NormalizeFast() == 0.0f) {
        return side;
    }
    return result;
}

void SubdivideBolt_r(const idVec3& startPos, const idVec3& endPos,
    boltStats_t& stats, BoltRandom& random, int subdivisionLevel,
    int branchLevel, int numSubdivisions, float deviation,
    idStaticList<segment_t, 128>& segments) {
    if (segments.Num() >= segments.Max()) {
        return;
    }

    const idVec3 delta = endPos - startPos;
    const float length = delta.Length();
    if (subdivisionLevel >= numSubdivisions || length <= 0.001f) {
        segment_t segment{};
        segment.startPos = startPos;
        segment.endPos = endPos;
        segment.lengthFrac = length * stats.invTotalLength;
        segments.Append(segment);
        ++stats.numNodes;
        return;
    }

    idVec3 direction = delta;
    direction.NormalizeFast();
    const float falloff = 1.0f / static_cast<float>(1 << subdivisionLevel);
    const idVec3 offset = SafePerpendicular(direction, random) *
        (deviation * falloff * random.Centered());
    const idVec3 middle = (startPos + endPos) * 0.5f + offset;
    SubdivideBolt_r(startPos, middle, stats, random,
        subdivisionLevel + 1, branchLevel, numSubdivisions, deviation,
        segments);
    SubdivideBolt_r(middle, endPos, stats, random,
        subdivisionLevel + 1, branchLevel, numSubdivisions, deviation,
        segments);
}

void GenerateBranch(const idVec3& origin, const idVec3& parentDirection,
    boltStats_t& stats, BoltRandom& random,
    const idElectricBoltParameters& parameters, int branchLevel,
    int currentTime, idRenderModelBeam* beamModel) {
    if (branchLevel > parameters.maxBranchLevels) {
        return;
    }

    const float minimumLength = (std::min)(parameters.branchLength.x,
        parameters.branchLength.y);
    const float maximumLength = (std::max)(parameters.branchLength.x,
        parameters.branchLength.y);
    const float branchLength = minimumLength +
        (maximumLength - minimumLength) * random.Unit();
    const float angleScale = std::sin(parameters.maxBranchAngle *
        0.01745329251994329577f * random.Unit());
    idVec3 direction = parentDirection +
        SafePerpendicular(parentDirection, random) * angleScale;
    direction.NormalizeFast();

    idStaticList<segment_t, 128> branchSegments;
    SubdivideBolt_r(origin, origin + direction * branchLength, stats, random,
        0, branchLevel, (std::max)(0, parameters.branchSubdivisions),
        parameters.maxBranchDeviation, branchSegments);
    if (branchSegments.Num() == 0) {
        return;
    }

    const idMaterial* material = parameters.useBranchOverride &&
        parameters.branchMaterial != nullptr
        ? parameters.branchMaterial : parameters.material;
    float branchStartWidth = parameters.branchStartWidth;
    float branchEndWidth = parameters.branchEndWidth;
    if (parameters.useBranchOverride && parameters.branchWidth > 0) {
        branchStartWidth = static_cast<float>(parameters.branchWidth);
        branchEndWidth = 0.0f;
    }
    GameLib_SubmitElectricBolt(beamModel, material, branchSegments.Ptr(),
        branchSegments.Num(), currentTime, stats.boltStartTime,
        branchStartWidth, branchEndWidth, parameters.color,
        parameters.brightness, parameters.applyGradient,
        parameters.revealTime, branchLevel);
    ++stats.numBranches;
}

} // namespace

// The authoritative generator first recursively subdivides each control
// segment, then emits probabilistic branches from the resulting nodes.
void GenerateBolt(idStaticList<segment_t, 128>& currentSegments,
    boltStats_t& stats, idRenderModelBeam* beamModel,
    const idDeclElectricBolt* eboltDecl, int currentTime, int diversity,
    int branchLevel, float maxDeviation, int maxSubdivisions) {
    idElectricBoltParameters parameters{};
    if (beamModel == nullptr || eboltDecl == nullptr ||
        !GameLib_GetElectricBoltParameters(eboltDecl, parameters)) {
        return;
    }

    BoltRandom random(static_cast<std::uint32_t>(diversity) ^
        static_cast<std::uint32_t>(stats.boltStartTime * 1103515245u));
    idStaticList<segment_t, 128> generated;
    for (int index = 0; index < currentSegments.Num(); ++index) {
        const segment_t& source = currentSegments[index];
        SubdivideBolt_r(source.startPos, source.endPos, stats, random, 0,
            branchLevel, (std::max)(0, maxSubdivisions), maxDeviation,
            generated);
    }

    if (generated.Num() == 0) {
        return;
    }
    GameLib_SubmitElectricBolt(beamModel, parameters.material,
        generated.Ptr(), generated.Num(), currentTime, stats.boltStartTime,
        parameters.startWidth, parameters.endWidth, parameters.color,
        parameters.brightness, parameters.applyGradient,
        parameters.revealTime, branchLevel);

    if (branchLevel < parameters.maxBranchLevels &&
        parameters.branchProbability > 0.0f) {
        for (int index = 0; index < generated.Num(); ++index) {
            if (random.Unit() >= parameters.branchProbability) {
                continue;
            }
            idVec3 parentDirection = generated[index].endPos -
                generated[index].startPos;
            if (parentDirection.NormalizeFast() == 0.0f) {
                continue;
            }
            GenerateBranch(generated[index].endPos, parentDirection, stats,
                random, parameters, branchLevel + 1, currentTime, beamModel);
        }
    }
}

idElectricBolt::idElectricBolt()
    : eboltDecl(nullptr)
    , beamModel(nullptr)
    , controlNodes()
    , startTime(0)
    , diversity(0) {
}

idElectricBolt::~idElectricBolt() {
    eboltDecl = nullptr;
    beamModel = nullptr;
    controlNodes.Clear();
}

void idElectricBolt::Init(idRenderModelBeam* const beamModel_,
    const idDeclElectricBolt* const eboltDecl_) {
    beamModel = beamModel_;
    eboltDecl = eboltDecl_;
}

void idElectricBolt::UpdateControlNodes(
    const idStaticList<eboltControlNode_t, 32>& newControlNodes) {
    controlNodes = newControlNodes;
}

void idElectricBolt::StartElectricBolt(const int newStartTime,
    const idVec3& startPos, const idVec3& endPos,
    const float newDiversity) {
    if (beamModel == nullptr || eboltDecl == nullptr) {
        controlNodes.Clear();
        return;
    }
    startTime = newStartTime;
    diversity = static_cast<int>(newDiversity * 32767.0f);
    controlNodes.SetNum(1);
    controlNodes[0].startPos = startPos;
    controlNodes[0].endPos = endPos;
}

void idElectricBolt::StartElectricBolt(const int newStartTime,
    const idStaticList<eboltControlNode_t, 32>& newControlNodes,
    const float newDiversity) {
    startTime = newStartTime;
    diversity = static_cast<int>(newDiversity * 32767.0f);
    controlNodes = newControlNodes;
}

void idElectricBolt::StopElectricBolt() {
    controlNodes.Clear();
}

void idElectricBolt::Update(const int currentTime) {
    if (beamModel == nullptr || eboltDecl == nullptr ||
        controlNodes.Num() == 0) {
        return;
    }

    idElectricBoltParameters parameters{};
    if (!GameLib_GetElectricBoltParameters(eboltDecl, parameters)) {
        return;
    }

    idStaticList<segment_t, 128> segments;
    float totalLength = 0.0f;
    for (int index = 0; index < controlNodes.Num(); ++index) {
        segment_t source{};
        source.startPos = controlNodes[index].startPos;
        source.endPos = controlNodes[index].endPos;
        source.lengthFrac = 1.0f;
        segments.Append(source);
        totalLength += (source.endPos - source.startPos).Length();
    }

    boltStats_t stats{};
    stats.invTotalLength = totalLength > 0.001f ? 1.0f / totalLength : 0.0f;
    stats.boltStartPos = controlNodes[0].startPos;
    stats.boltStartTime = startTime;
    GenerateBolt(segments, stats, beamModel, eboltDecl, currentTime,
        diversity, 0, parameters.maxDeviation, parameters.subdivisions);
}
