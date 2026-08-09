#include "models/detail/jobs/detailgather.h"

#include <algorithm>
#include <cstring>

namespace {

std::int16_t ClampShort(const float value) {
    return static_cast<std::int16_t>((std::max)(-32768.0f,
        (std::min)(32767.0f, value)));
}

void AddLeaf(const int encodedLeaf, const int detailCount,
    const std::uint32_t encodedCounts, const dm_subTreeBounds_t& bounds,
    detailGather_t& gather) {
    if (detailCount <= 0
        || R_CullDetailBoundsToMVP(bounds, gather.maxDetailHeight,
            gather.mvpMatrix)) {
        return;
    }
    const unsigned int available = gather.maxDetailIndices
        > gather.numDetailIndices
        ? gather.maxDetailIndices - gather.numDetailIndices : 0;
    const unsigned int toWrite = (std::min)(available,
        static_cast<unsigned int>(detailCount));
    std::uint16_t detailIndex = static_cast<std::uint16_t>(
        encodedLeaf & 0x7FFF);
    for (unsigned int index = 0; index < toWrite; ++index) {
        gather.detailIndices[gather.numDetailIndices++] = detailIndex++;
    }
    gather.vertCount += encodedCounts & 0xFFFFu;
    gather.indexCount += encodedCounts >> 16;
}

void GatherRecursive(dm_subTreeTreeNodePtrs_t& pointers,
    const dm_subTreeBounds_t& bounds, detailGather_t& gather,
    const int nodeNumber, const int detailCount,
    const std::uint32_t encodedCounts, const int depth) {
    if (depth > 32768) return;
    if ((nodeNumber & 0x8000) != 0) {
        AddLeaf(nodeNumber, detailCount, encodedCounts, bounds, gather);
        return;
    }
    if (pointers.treeNodes == nullptr || nodeNumber < 0) return;

    const dm_treeNode_t& node = pointers.treeNodes[nodeNumber];
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
        dm_subTreeBounds_t frontBounds = bounds;
        frontBounds.b[0][axis] = node.planeDist;
        GatherRecursive(pointers, frontBounds, gather, node.children[0],
            (node.planeType >> 2) & 0x7F, node.counts[0], depth + 1);
    }
    if (back) {
        dm_subTreeBounds_t backBounds = bounds;
        backBounds.b[1][axis] = node.planeDist;
        GatherRecursive(pointers, backBounds, gather, node.children[1],
            node.planeType >> 9, node.counts[1], depth + 1);
    }
}

} // namespace

bool R_CullDetailBoundsToMVP(const dm_subTreeBounds_t& bounds,
    const int maxDetailHeight, const float* const mvpMatrix) {
    if (mvpMatrix == nullptr) return false;
    unsigned int clipMask = 0;
    for (int xSide = 0; xSide < 2; ++xSide) {
        const float x = static_cast<float>(bounds.b[xSide][0]);
        for (int ySide = 0; ySide < 2; ++ySide) {
            const float y = static_cast<float>(bounds.b[ySide][1]);
            for (int zSide = 0; zSide < 2; ++zSide) {
                float z = static_cast<float>(bounds.b[zSide][2]);
                if (zSide != 0) z += static_cast<float>(maxDetailHeight);
                const float clipX = x * mvpMatrix[0] + y * mvpMatrix[1]
                    + z * mvpMatrix[2] + mvpMatrix[3];
                const float clipY = x * mvpMatrix[4] + y * mvpMatrix[5]
                    + z * mvpMatrix[6] + mvpMatrix[7];
                const float clipZ = x * mvpMatrix[8] + y * mvpMatrix[9]
                    + z * mvpMatrix[10] + mvpMatrix[11];
                const float clipW = x * mvpMatrix[12] + y * mvpMatrix[13]
                    + z * mvpMatrix[14] + mvpMatrix[15];
                if (clipX > -clipW) clipMask |= 1u;
                if (clipX < clipW) clipMask |= 2u;
                if (clipY > -clipW) clipMask |= 4u;
                if (clipY < clipW) clipMask |= 8u;
                if (clipZ > -clipW) clipMask |= 16u;
                if (clipZ < clipW) clipMask |= 32u;
            }
        }
    }
    return clipMask != 63u;
}

void GetDetailRenderListForView(dm_subTreeTreeNodePtrs_t& subTreePointers,
    const dm_subTreeBounds_t& bounds, detailGather_t& gather,
    const int nodeNumber) {
    GatherRecursive(subTreePointers, bounds, gather, nodeNumber, 0, 0, 0);
}

void GatherDetailIndicesForSubTree(
    const deferredDetailGatherParms_t* const parameters,
    int& numDetailIndices) {
    numDetailIndices = 0;
    if (parameters == nullptr || parameters->detailCount == nullptr) return;
    *parameters->detailCount = detailSubTreeStats_t{0, 0, 0, 0};
    if (parameters->viewData == nullptr
        || parameters->subTreeBounds == nullptr
        || parameters->subTreeTreeNodes == nullptr
        || parameters->subTreeTreeNodesSize
            < static_cast<int>(sizeof(dm_subTreeTreeNodes_t))
        || parameters->subTreeTreeNodes->numTreeNodes <= 0
        || parameters->detailIndices == nullptr
        || parameters->maxDetailIndices == 0) {
        return;
    }

    detailGather_t gather{};
    gather.maxDetailHeight = parameters->maxDetailHeight;
    gather.mvpMatrix = parameters->viewData->mvpMatrix.m;
    gather.detailIndices = parameters->detailIndices;
    gather.maxDetailIndices = parameters->maxDetailIndices;

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
                        * (distance * parameters->viewData->fov[0]
                            * leftSign)
                    + parameters->viewData->viewUp
                        * (distance * parameters->viewData->fov[1]
                            * upSign);
            }
        }
    }
    for (int vertex = 0; vertex < 8; ++vertex) {
        for (int axis = 0; axis < 3; ++axis) {
            gather.frustumVerts[axis][vertex] =
                ClampShort(corners[vertex][axis]);
        }
    }

    dm_subTreeTreeNodePtrs_t pointers{};
    SetupSubTreePtrsFromTreeNodes(pointers,
        parameters->subTreeTreeNodes);
    const std::uint8_t* const nodesEnd =
        reinterpret_cast<const std::uint8_t*>(pointers.treeNodes)
        + static_cast<std::uint64_t>(
            parameters->subTreeTreeNodes->numTreeNodes)
            * sizeof(dm_treeNode_t);
    const std::uint8_t* const bufferEnd =
        reinterpret_cast<const std::uint8_t*>(
            parameters->subTreeTreeNodes)
        + parameters->subTreeTreeNodesSize;
    if (reinterpret_cast<const std::uint8_t*>(pointers.treeNodes)
            < reinterpret_cast<const std::uint8_t*>(
                parameters->subTreeTreeNodes)
        || nodesEnd > bufferEnd) {
        return;
    }

    GetDetailRenderListForView(pointers, *parameters->subTreeBounds,
        gather, 0);
    parameters->detailCount->subTreeDetailCount =
        static_cast<int>(gather.numDetailIndices);
    parameters->detailCount->vertCount =
        static_cast<int>(gather.vertCount);
    parameters->detailCount->indexCount =
        static_cast<int>(gather.indexCount);
    numDetailIndices = static_cast<int>(gather.numDetailIndices);
}
