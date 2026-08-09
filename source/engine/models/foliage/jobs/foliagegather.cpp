#include "models/foliage/jobs/foliagegather.h"

#include <algorithm>
#include <cmath>

namespace {

std::int16_t ClampShort(const float value) {
    return static_cast<std::int16_t>((std::max)(-32768.0f,
        (std::min)(32767.0f, value)));
}

bool SphereTouchesBounds(const influenceSphere_t& sphere,
    const idBounds& bounds) {
    float distanceSquared = 0.0f;
    for (int axis = 0; axis < 3; ++axis) {
        const float coordinate = sphere.center[axis];
        if (coordinate < bounds[0][axis]) {
            const float delta = bounds[0][axis] - coordinate;
            distanceSquared += delta * delta;
        } else if (coordinate > bounds[1][axis]) {
            const float delta = coordinate - bounds[1][axis];
            distanceSquared += delta * delta;
        }
    }
    return distanceSquared <= sphere.outerRadius * sphere.outerRadius;
}

float NearestViewDistance(const foliageGather_t& gather,
    const idBounds& bounds) {
    const idVec3 center = (bounds[0] + bounds[1]) * 0.5f;
    const idVec3 extents = bounds[1] - center;
    return gather.viewDir.Dot(center - gather.viewOrg)
        - std::fabs(gather.viewDir.x * extents.x)
        - std::fabs(gather.viewDir.y * extents.y)
        - std::fabs(gather.viewDir.z * extents.z);
}

bool KeepSmallFoliage(const std::uint16_t index, const float distance,
    const foliageGather_t& gather) {
    if (distance <= gather.foliageStartFadeDist) return true;
    if (distance >= gather.foliageSmallFadeDistMax) return false;
    const std::uint32_t hash = 1664525u * index + 1013904223u;
    const float random = static_cast<float>(hash & 0x00FFFFFFu)
        / static_cast<float>(0x01000000u);
    const float threshold = gather.foliageStartFadeDist
        + random * random * random
            * (gather.foliageSmallFadeDistMax
                - gather.foliageStartFadeDist);
    return distance <= threshold;
}

void AddLeaf(const fm_leafInfo_t& leaf, foliageGather_t& gather) {
    idBounds bounds;
    if (R_CullFoliageBoundsToMVP(leaf.b, gather.mvpMatrix, bounds)) return;

    const unsigned int sphereOffset = gather.numInfluenceSphereIndices;
    if (gather.influenceSphereIndices != nullptr
        && sphereOffset < gather.maxInfluenceSphereIndices) {
        for (unsigned int index = 0;
                index < gather.influenceSphereStackSize; ++index) {
            const int sphereIndex = gather.influenceSphereStack[index];
            if (sphereIndex < 0 || gather.influenceSpheres == nullptr) continue;
            if (!SphereTouchesBounds(gather.influenceSpheres[sphereIndex],
                    bounds)) continue;
            if (gather.numInfluenceSphereIndices + 1
                >= gather.maxInfluenceSphereIndices) break;
            gather.influenceSphereIndices[
                gather.numInfluenceSphereIndices++] =
                    static_cast<std::int16_t>(sphereIndex);
        }
        if (gather.numInfluenceSphereIndices
            < gather.maxInfluenceSphereIndices) {
            gather.influenceSphereIndices[
                gather.numInfluenceSphereIndices++] = -1;
        }
    }

    const int total = leaf.numBigFoliage + leaf.numSmallFoliage;
    const float distance = NearestViewDistance(gather, bounds);
    for (int relative = 0; relative < total
            && gather.numFoliageIndices < gather.maxFoliageIndices;
            ++relative) {
        const std::uint16_t foliageIndex = static_cast<std::uint16_t>(
            leaf.foliageOffset + relative);
        if (relative < leaf.numSmallFoliage
            && !KeepSmallFoliage(foliageIndex, distance, gather)) continue;
        foliageIndex_t& output =
            gather.foliageIndices[gather.numFoliageIndices++];
        output.foliageIndex = foliageIndex;
        output.influenceSphereOffset = static_cast<std::uint16_t>(
            (std::min)(sphereOffset, 65535u));
    }
}

void GatherRecursive(const fm_subTreeTreeNodePtrs_t& pointers,
    const fm_subTreeBounds_t& bounds, foliageGather_t& gather,
    const int nodeNumber, const int nodeCount, const int leafCount,
    const int depth) {
    if (depth > nodeCount + 1) return;
    if ((nodeNumber & 0x8000) != 0) {
        const int leafIndex = nodeNumber & 0x7FFF;
        if (pointers.leafInfo != nullptr && leafIndex < leafCount)
            AddLeaf(pointers.leafInfo[leafIndex], gather);
        return;
    }
    if (pointers.treeNodes == nullptr || nodeNumber < 0
        || nodeNumber >= nodeCount) return;
    const fm_treeNode_t& node = pointers.treeNodes[nodeNumber];
    const int axis = node.planeType & 3;
    if (axis >= 3) return;
    bool front = false;
    bool back = false;
    for (int vertex = 0; vertex < 8; ++vertex) {
        const int coordinate = gather.frustumVerts[axis][vertex];
        front = front || coordinate >= node.planeDist;
        back = back || coordinate <= node.planeDist;
    }
    if (front) {
        fm_subTreeBounds_t childBounds = bounds;
        childBounds.b[0][axis] = node.planeDist;
        GatherRecursive(pointers, childBounds, gather, node.children[0],
            nodeCount, leafCount, depth + 1);
    }
    if (back) {
        fm_subTreeBounds_t childBounds = bounds;
        childBounds.b[1][axis] = node.planeDist;
        GatherRecursive(pointers, childBounds, gather, node.children[1],
            nodeCount, leafCount, depth + 1);
    }
}

} // namespace

bool R_CullFoliageBoundsToMVP(const std::int16_t bounds[2][3],
    const float* const mvpMatrix, idBounds& floatBounds) {
    for (int side = 0; side < 2; ++side)
        for (int axis = 0; axis < 3; ++axis)
            floatBounds[side][axis] = static_cast<float>(bounds[side][axis]);
    if (mvpMatrix == nullptr) return false;
    unsigned int mask = 0;
    for (int xSide = 0; xSide < 2; ++xSide)
        for (int ySide = 0; ySide < 2; ++ySide)
            for (int zSide = 0; zSide < 2; ++zSide) {
                const float x = floatBounds[xSide].x;
                const float y = floatBounds[ySide].y;
                const float z = floatBounds[zSide].z;
                const float cx = x*mvpMatrix[0] + y*mvpMatrix[1]
                    + z*mvpMatrix[2] + mvpMatrix[3];
                const float cy = x*mvpMatrix[4] + y*mvpMatrix[5]
                    + z*mvpMatrix[6] + mvpMatrix[7];
                const float cz = x*mvpMatrix[8] + y*mvpMatrix[9]
                    + z*mvpMatrix[10] + mvpMatrix[11];
                const float cw = x*mvpMatrix[12] + y*mvpMatrix[13]
                    + z*mvpMatrix[14] + mvpMatrix[15];
                if (cx > -cw) mask |= 1; if (cx < cw) mask |= 2;
                if (cy > -cw) mask |= 4; if (cy < cw) mask |= 8;
                if (cz > -cw) mask |= 16; if (cz < cw) mask |= 32;
            }
    return mask != 63;
}

void GatherFoliageIndicesForSubTree(
    const deferredFoliageGatherParms_t* const parameters,
    int& numFoliageIndices, int& numInfluenceSphereIndices) {
    numFoliageIndices = 0;
    numInfluenceSphereIndices = 0;
    if (parameters == nullptr || parameters->foliageCount == nullptr) return;
    *parameters->foliageCount = foliageSubTreeStats_t{0, {0, 0, 0}};
    if (parameters->viewData == nullptr
        || parameters->subTreeBounds == nullptr
        || parameters->subTreeTreeNodes == nullptr
        || parameters->foliageIndices == nullptr
        || parameters->influenceSphereIndices == nullptr
        || parameters->subTreeTreeNodesSize
            < static_cast<int>(sizeof(fm_subTreeTreeNodes_t))) return;

    foliageGather_t gather{};
    gather.mvpMatrix = parameters->viewData->mvpMatrix.m;
    gather.viewDir = parameters->viewData->viewFwd;
    gather.viewOrg = parameters->viewData->viewOrg;
    gather.foliageIndices = parameters->foliageIndices;
    gather.maxFoliageIndices = parameters->maxFoliageIndices;
    gather.influenceSphereIndices = parameters->influenceSphereIndices;
    gather.maxInfluenceSphereIndices = parameters->maxInfluenceSphereIndices;
    gather.foliageStartFadeDist = parameters->foliageStartFadeDist;
    gather.foliageSmallFadeDistMax = parameters->foliageSmallFadeDistMax;
    if (parameters->visibleInfluenceSpheres != nullptr) {
        gather.influenceSpheres =
            parameters->visibleInfluenceSpheres->spheres;
        const int count = (std::max)(0, (std::min)(256,
            parameters->visibleInfluenceSpheres->numSpheres));
        for (int index = 0; index < count; ++index) {
            gather.influenceSphereStack[gather.influenceSphereStackSize++]
                = index;
        }
    }
    if (gather.maxInfluenceSphereIndices > 0)
        gather.influenceSphereIndices[gather.numInfluenceSphereIndices++] = -1;

    idVec3 corners[8];
    const float distances[2] = {
        parameters->viewData->nearDist, parameters->viewData->farDist
    };
    int corner = 0;
    for (int distanceIndex = 0; distanceIndex < 2; ++distanceIndex) {
        const float distance = distances[distanceIndex];
        for (int vertical = 0; vertical < 2; ++vertical) {
            const float upSign = vertical == 0 ? 1.0f : -1.0f;
            for (int horizontal = 0; horizontal < 2; ++horizontal) {
                const float leftSign = horizontal == 0 ? 1.0f : -1.0f;
                corners[corner++] = parameters->viewData->viewOrg
                    + parameters->viewData->viewFwd * distance
                    + parameters->viewData->viewLeft
                        * (distance * parameters->viewData->fov[0]*leftSign)
                    + parameters->viewData->viewUp
                        * (distance * parameters->viewData->fov[1]*upSign);
            }
        }
    }
    for (int vertex = 0; vertex < 8; ++vertex)
        for (int axis = 0; axis < 3; ++axis)
            gather.frustumVerts[axis][vertex] =
                ClampShort(corners[vertex][axis]);

    fm_subTreeTreeNodePtrs_t pointers{};
    SetupFoliageSubTreeNodePointers(pointers,
        parameters->subTreeTreeNodes);
    const auto* const base = reinterpret_cast<const std::uint8_t*>(
        parameters->subTreeTreeNodes);
    const auto* const end = base + parameters->subTreeTreeNodesSize;
    if (reinterpret_cast<const std::uint8_t*>(pointers.treeNodes) < base
        || reinterpret_cast<const std::uint8_t*>(pointers.treeNodes
            + parameters->subTreeTreeNodes->numTreeNodes) > end
        || reinterpret_cast<const std::uint8_t*>(pointers.leafInfo) < base
        || reinterpret_cast<const std::uint8_t*>(pointers.leafInfo
            + parameters->subTreeTreeNodes->numLeafInfo) > end) return;
    GatherRecursive(pointers, *parameters->subTreeBounds, gather, 0,
        parameters->subTreeTreeNodes->numTreeNodes,
        parameters->subTreeTreeNodes->numLeafInfo, 0);
    parameters->foliageCount->subTreeFoliageCount =
        static_cast<int>(gather.numFoliageIndices);
    numFoliageIndices = static_cast<int>(gather.numFoliageIndices);
    numInfluenceSphereIndices =
        static_cast<int>(gather.numInfluenceSphereIndices);
}
