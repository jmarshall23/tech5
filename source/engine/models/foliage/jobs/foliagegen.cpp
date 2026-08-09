#include "models/foliage/jobs/foliagegen.h"

#include <algorithm>
#include <cmath>
#include <cstring>

namespace {

float Random01(const unsigned int seed) {
    const std::uint32_t hash = seed * 1664525u + 1013904223u;
    return static_cast<float>(hash & 0x00FFFFFFu)
        / static_cast<float>(0x01000000u);
}

idVec3 Normalize(const idVec3& vector, const idVec3& fallback) {
    const float lengthSquared = vector.LengthSqr();
    return lengthSquared > 1.0e-20f
        ? vector * (1.0f / std::sqrt(lengthSquared)) : fallback;
}

idVec3 RotateAroundAxis(const idVec3& vector, const idVec3& axis,
    const float angle) {
    const float cosine = std::cos(angle);
    const float sine = std::sin(angle);
    return vector * cosine + axis.Cross(vector) * sine
        + axis * (axis.Dot(vector) * (1.0f - cosine));
}

void EncodeDirection(const idVec3& input, std::uint8_t output[4]) {
    const idVec3 direction = Normalize(input, idVec3(0.0f, 0.0f, 1.0f));
    for (int axis = 0; axis < 3; ++axis) {
        output[axis] = static_cast<std::uint8_t>((std::max)(0.0f,
            (std::min)(255.0f,
                (direction[axis] + 1.0f) * 127.5f + 0.5f)));
    }
    output[3] = 255;
}

std::int16_t PackTexture(const float value) {
    return static_cast<std::int16_t>((std::max)(-32767.0f,
        (std::min)(32767.0f, (value - 0.5f) * 65534.0f)));
}

idVec3 DecodeUp(const fm_foliage_t& foliage) {
    return Normalize(idVec3(
        static_cast<float>(foliage.upVec[0]) * (2.0f / 255.0f) - 1.0f,
        static_cast<float>(foliage.upVec[1]) * (2.0f / 255.0f) - 1.0f,
        static_cast<float>(foliage.upVec[2]) * (2.0f / 255.0f) - 1.0f),
        idVec3(0.0f, 0.0f, 1.0f));
}

} // namespace

void CalculateFoliageBounds(const std::int16_t xyz[3],
    const float uniformSizeScale, const float quadWidth,
    const float quadHeight, const float widthVariance,
    const float heightVariance, const idVec3& upVector, idBounds& bounds) {
    const unsigned int seed = static_cast<unsigned int>(
        static_cast<std::uint16_t>(xyz[0]))
        ^ (static_cast<unsigned int>(static_cast<std::uint16_t>(xyz[1])) << 8)
        ^ (static_cast<unsigned int>(static_cast<std::uint16_t>(xyz[2])) << 16);
    const float width = (std::max)(0.0f, quadWidth
        * (1.0f + (Random01(seed) * 2.0f - 1.0f) * widthVariance)
        * uniformSizeScale);
    const float height = (std::max)(0.0f, quadHeight
        * (1.0f + (Random01(seed + 1) * 2.0f - 1.0f) * heightVariance)
        * uniformSizeScale);
    const idVec3 origin(static_cast<float>(xyz[0]),
        static_cast<float>(xyz[1]), static_cast<float>(xyz[2]));
    const idVec3 up = Normalize(upVector, idVec3(0.0f, 0.0f, 1.0f));
    const idVec3 top = origin + up * height;
    const float radius = width * 0.5f;
    for (int axis = 0; axis < 3; ++axis) {
        bounds[0][axis] = (std::min)(origin[axis], top[axis]) - radius;
        bounds[1][axis] = (std::max)(origin[axis], top[axis]) + radius;
    }
}

void CalculateFoliageBounds(const fm_foliage_t* const foliage,
    const fm_attribute_t* const attribute, idBounds& bounds) {
    bounds[0].Zero(); bounds[1].Zero();
    if (foliage == nullptr || attribute == nullptr) return;
    CalculateFoliageBounds(foliage->xyz,
        foliage->uniformSizeScale * 0.01f,
        static_cast<float>(attribute->quadWidth),
        static_cast<float>(attribute->quadHeight),
        attribute->widthVariance * 0.01f,
        attribute->heightVariance * 0.01f, DecodeUp(*foliage), bounds);
}

int GetFoliageOffsetForSubTree(
    const foliageSubTreeStats_t* const foliageCounts,
    const int subTreeIndex) {
    if (foliageCounts == nullptr) return 0;
    int offset = 0;
    for (int index = 0; index < subTreeIndex; ++index)
        offset += foliageCounts[index].subTreeFoliageCount;
    return offset;
}

int GetFoliageTotalCount(
    const foliageSubTreeStats_t* const foliageCounts) {
    if (foliageCounts == nullptr) return 0;
    int total = 0;
    for (int index = 0; index < 65536
            && foliageCounts[index].subTreeFoliageCount != -1; ++index)
        total += foliageCounts[index].subTreeFoliageCount;
    return total;
}

void GetFoliageOffsetAndCountForJob(const int numJobs,
    const int jobIndex, const int totalCount, int& jobOffset,
    int& jobCount) {
    if (numJobs <= 0 || jobIndex < 0 || jobIndex >= numJobs) {
        jobOffset = jobCount = 0;
        return;
    }
    jobOffset = jobIndex * totalCount / numJobs;
    jobCount = (jobIndex + 1) * totalCount / numJobs - jobOffset;
}

int BuildFoliageQuad(idTransparencyVert* const vertices,
    float* const quadDepth, const unsigned int foliageIndex,
    const fm_foliage_t* const foliage,
    const fm_attribute_t* const attribute,
    const foliageRenderView_t* const viewData,
    const influenceSphere_t* const influenceSpheres,
    const std::int16_t* const influenceSphereIndices,
    const float foliageStartFadeDist, const float,
    const float foliageBigFadeDistMax) {
    if (vertices == nullptr || foliage == nullptr || attribute == nullptr
        || viewData == nullptr) return 0;

    const float scale = foliage->uniformSizeScale * 0.01f;
    const float width = attribute->quadWidth * scale
        * (1.0f + (Random01(foliageIndex) * 2.0f - 1.0f)
            * attribute->widthVariance * 0.01f);
    const float height = attribute->quadHeight * scale
        * (1.0f + (Random01(foliageIndex + 1) * 2.0f - 1.0f)
            * attribute->heightVariance * 0.01f);
    const idVec3 origin(static_cast<float>(foliage->xyz[0]),
        static_cast<float>(foliage->xyz[1]),
        static_cast<float>(foliage->xyz[2]));
    idVec3 up = DecodeUp(*foliage);
    idVec3 right = viewData->viewLeft - up * up.Dot(viewData->viewLeft);
    right = Normalize(right, Normalize(up.Cross(idVec3(1.0f, 0.0f, 0.0f)),
        idVec3(0.0f, 1.0f, 0.0f)));
    const float yawAngles[4] = {0.0f, 1.57079632679f,
        2.09439510239f, 4.18879020479f};
    if (foliage->shapeType < 4)
        right = RotateAroundAxis(right, up, yawAngles[foliage->shapeType]);

    idVec3 top = origin + up * height;
    if (influenceSpheres != nullptr && influenceSphereIndices != nullptr) {
        for (int listIndex = 0; listIndex < 256
                && influenceSphereIndices[listIndex] >= 0; ++listIndex) {
            const influenceSphere_t& sphere =
                influenceSpheres[influenceSphereIndices[listIndex]];
            const idVec3 delta = top - sphere.center;
            const float distanceSquared = delta.LengthSqr();
            if (sphere.outerRadius <= 0.0f
                || distanceSquared >= sphere.outerRadius*sphere.outerRadius)
                continue;
            const float distance = std::sqrt((std::max)(0.0f,
                distanceSquared));
            const float range = (std::max)(0.001f,
                sphere.outerRadius - sphere.innerRadius);
            const float strength = (std::max)(0.0f,
                (std::min)(1.0f,
                    (sphere.outerRadius - distance) / range));
            top = top + Normalize(delta, right)
                * (sphere.angle * strength * height);
        }
        up = Normalize(top - origin, up);
    }

    const idVec3 halfRight = right * (width * 0.5f);
    const idVec3 positions[4] = {
        origin - halfRight, origin + halfRight,
        top + halfRight, top - halfRight
    };
    const bool flip = attribute->flipHoriz != 0
        && Random01(foliageIndex + 2) >= 0.5f;
    const float baseS[4] = {flip ? 1.0f : 0.0f, flip ? 0.0f : 1.0f,
        flip ? 0.0f : 1.0f, flip ? 1.0f : 0.0f};
    const float baseT[4] = {1.0f, 1.0f, 0.0f, 0.0f};
    const idVec3 normal = Normalize(right.Cross(up), viewData->viewFwd);
    const float distance = viewData->viewFwd.Dot(
        (origin + top) * 0.5f - viewData->viewOrg);
    float alpha = 1.0f;
    if (foliageBigFadeDistMax > foliageStartFadeDist
        && distance > foliageStartFadeDist) {
        alpha = 1.0f - (distance - foliageStartFadeDist)
            / (foliageBigFadeDistMax - foliageStartFadeDist);
    }
    alpha = (std::max)(0.0f, (std::min)(1.0f, alpha));
    for (int index = 0; index < 4; ++index) {
        idTransparencyVert& output = vertices[index];
        std::memset(&output, 0, sizeof(output));
        output.xyz = positions[index];
        float s = attribute->sortScaleBias[2]
            + baseS[index] * attribute->sortScaleBias[0];
        float t = attribute->sortScaleBias[3]
            + baseT[index] * attribute->sortScaleBias[1];
        if (viewData->atlasWidth != 0)
            s += (baseS[index] == 0.0f ? 0.5f : -0.5f)
                / viewData->atlasWidth;
        if (viewData->atlasHeight != 0)
            t += (baseT[index] == 0.0f ? 0.5f : -0.5f)
                / viewData->atlasHeight;
        output.st[0] = PackTexture(s);
        output.st[1] = PackTexture(t);
        output.st1[0] = static_cast<std::int16_t>(
            attribute->swayMagnitude * 128);
        output.st1[1] = static_cast<std::int16_t>(foliageIndex & 0x7FFF);
        EncodeDirection(normal, output.normal);
        EncodeDirection(right, output.tangent);
        output.color[0] = foliage->color[0];
        output.color[1] = foliage->color[1];
        output.color[2] = foliage->color[2];
        output.color[3] = static_cast<std::uint8_t>(alpha * 255.0f + 0.5f);
    }
    if (quadDepth != nullptr) *quadDepth = distance;
    return 4;
}

int GenFoliageForSubTree(
    const deferredFoliageGenParms_t* const parameters,
    const foliageIndex_t* const foliageIndices, const int numFoliage,
    int vertexOffset) {
    if (parameters == nullptr || parameters->subTreeData == nullptr
        || foliageIndices == nullptr || numFoliage <= 0
        || parameters->verts == nullptr || parameters->quadDepths == nullptr
        || parameters->viewData == nullptr
        || parameters->subTreeDataSize < sizeof(fm_subTreeData_t)) return 0;
    const fm_subTreeData_t& header = *parameters->subTreeData;
    if (header.numFoliage < 0 || header.numAttributes < 0
        || header.foliageOffset < 0 || header.attributeOffset < 0
        || static_cast<std::uint64_t>(header.foliageOffset)
            + static_cast<std::uint64_t>(header.numFoliage)
                * sizeof(fm_foliage_t) > parameters->subTreeDataSize
        || static_cast<std::uint64_t>(header.attributeOffset)
            + static_cast<std::uint64_t>(header.numAttributes)
                * sizeof(fm_attribute_t) > parameters->subTreeDataSize)
        return 0;
    fm_subTreeDataPtrs_t pointers{};
    SetupFoliageSubTreeDataPointers(pointers, parameters->subTreeData);
    int generated = 0;
    for (int index = 0; index < numFoliage; ++index) {
        const foliageIndex_t& gathered = foliageIndices[index];
        if (gathered.foliageIndex >= header.numFoliage
            || vertexOffset + 4 > parameters->numVertsAllocated) continue;
        const fm_foliage_t& foliage = pointers.foliage[gathered.foliageIndex];
        if (foliage.attribIdx >= header.numAttributes) continue;
        const std::int16_t* sphereList = nullptr;
        if (parameters->influenceSphereIndices != nullptr
            && gathered.influenceSphereOffset
                < parameters->maxInfluenceSphereIndices)
            sphereList = parameters->influenceSphereIndices
                + gathered.influenceSphereOffset;
        const int written = BuildFoliageQuad(
            parameters->verts + vertexOffset,
            parameters->quadDepths + vertexOffset / 4,
            gathered.foliageIndex, &foliage,
            &pointers.attributes[foliage.attribIdx], parameters->viewData,
            parameters->visibleInfluenceSpheres != nullptr
                ? parameters->visibleInfluenceSpheres->spheres : nullptr,
            sphereList, parameters->foliageStartFadeDist,
            parameters->foliageSmallFadeDistMax,
            parameters->foliageBigFadeDistMax);
        if (written > 0) {
            vertexOffset += written;
            ++generated;
        }
    }
    return generated;
}

void FoliageGatherJob(
    const deferredFoliageGatherParms_t* const parameters) {
    int foliageCount = 0;
    int sphereIndexCount = 0;
    GatherFoliageIndicesForSubTree(parameters, foliageCount,
        sphereIndexCount);
}

void FoliageGenJob(const deferredFoliageGenParms_t* const parameters) {
    if (parameters == nullptr || parameters->foliageCountsList == nullptr
        || parameters->foliageCountsIndex < 0) return;
    if (parameters->quadsUsed != nullptr)
        *parameters->quadsUsed =
            GetFoliageTotalCount(parameters->foliageCountsList);
    const int subTreeOffset = GetFoliageOffsetForSubTree(
        parameters->foliageCountsList, parameters->foliageCountsIndex);
    int jobOffset = 0;
    int jobCount = 0;
    GetFoliageOffsetAndCountForJob(parameters->numJobsForIndices,
        parameters->jobIndexForIndices,
        parameters->foliageCountsList[
            parameters->foliageCountsIndex].subTreeFoliageCount,
        jobOffset, jobCount);
    int vertexOffset = 4 * (subTreeOffset + jobOffset);
    if (vertexOffset >= parameters->numVertsAllocated) return;
    jobCount = (std::min)(jobCount,
        (parameters->numVertsAllocated - vertexOffset) / 4);
    GenFoliageForSubTree(parameters,
        parameters->foliageIndices + jobOffset, jobCount, vertexOffset);
}
