#include "models/detail/jobs/detailgen.h"

#include <algorithm>
#include <cmath>
#include <cstring>

namespace {

struct expandedQuat_t { float x, y, z, w; };

expandedQuat_t ExpandQuaternion(const idCQuat& compressed) {
    const float sum = compressed.x * compressed.x
        + compressed.y * compressed.y + compressed.z * compressed.z;
    return expandedQuat_t{compressed.x, compressed.y, compressed.z,
        std::sqrt(std::fabs(1.0f - sum))};
}

idVec3 Rotate(const expandedQuat_t& q, const idVec3& point) {
    const idVec3 vector(q.x, q.y, q.z);
    const idVec3 twiceCross = vector.Cross(point) * 2.0f;
    return point + twiceCross * q.w + vector.Cross(twiceCross);
}

bool RangeInside(const int offset, const int count, const int stride,
    const int bufferSize) {
    return offset >= 0 && count >= 0 && stride >= 0 && bufferSize >= 0
        && static_cast<std::uint64_t>(offset)
            + static_cast<std::uint64_t>(count)
                * static_cast<std::uint64_t>(stride)
            <= static_cast<std::uint64_t>(bufferSize);
}

} // namespace

void CalculateDetailBounds(const dm_detail_t* const detail,
    const idDetailPaletteData* const data, idBounds& bounds) {
    bounds[0].Zero();
    bounds[1].Zero();
    if (detail == nullptr || data == nullptr) return;
    const expandedQuat_t rotation = ExpandQuaternion(detail->rotation);
    const float scale = static_cast<float>(detail->uniformSizeScale) * 0.01f;
    const idVec3 origin(static_cast<float>(detail->xyz[0]),
        static_cast<float>(detail->xyz[1]),
        static_cast<float>(detail->xyz[2]));
    bool initialized = false;
    for (int corner = 0; corner < 8; ++corner) {
        idVec3 point(
            data->bounds[(corner >> 0) & 1].x,
            data->bounds[(corner >> 1) & 1].y,
            data->bounds[(corner >> 2) & 1].z);
        point = origin + Rotate(rotation, point) * scale;
        if (!initialized) {
            bounds[0] = bounds[1] = point;
            initialized = true;
        } else {
            for (int axis = 0; axis < 3; ++axis) {
                bounds[0][axis] = (std::min)(bounds[0][axis], point[axis]);
                bounds[1][axis] = (std::max)(bounds[1][axis], point[axis]);
            }
        }
    }
}

void GetDetailTotalCount(const detailSubTreeStats_t* const detailCounts,
    detailGenTotals_t* const totals) {
    if (totals == nullptr) return;
    *totals = detailGenTotals_t{0, 0, {0, 0}};
    if (detailCounts == nullptr) return;
    for (int index = 0; index < 65536
            && detailCounts[index].subTreeDetailCount != -1; ++index) {
        totals->totalVerts += detailCounts[index].vertCount;
        totals->totalIndices += detailCounts[index].indexCount;
    }
}

void GetDetailOffsetsForSubTree(
    const detailSubTreeStats_t* const detailCounts,
    const int subTreeIndex, int& vertexOffset, int& indexOffset) {
    vertexOffset = 0;
    indexOffset = 0;
    if (detailCounts == nullptr) return;
    for (int index = 0; index < subTreeIndex; ++index) {
        vertexOffset += detailCounts[index].vertCount;
        indexOffset += detailCounts[index].indexCount;
    }
}

void BuildDetailModel(const detailPalette_t& palette,
    idDrawVert* const vertices, std::uint16_t* const indices,
    const int indexOffset, const dm_detail_t* const detail,
    const dm_attribute_t*, detailGenTotals_t& totals) {
    if (palette.entry == nullptr || palette.verts == nullptr
        || palette.indices == nullptr || vertices == nullptr
        || indices == nullptr || detail == nullptr) return;

    const detailPaletteEntry_t& entry = *palette.entry;
    for (int index = 0; index < entry.numIndices; ++index) {
        indices[totals.totalIndices + index] = static_cast<std::uint16_t>(
            palette.indices[entry.indexOffset + index]
            + indexOffset + totals.totalVerts);
    }

    const expandedQuat_t rotation = ExpandQuaternion(detail->rotation);
    const float scale = static_cast<float>(detail->uniformSizeScale) * 0.01f;
    const idVec3 origin(static_cast<float>(detail->xyz[0]),
        static_cast<float>(detail->xyz[1]),
        static_cast<float>(detail->xyz[2]));
    for (int index = 0; index < entry.numVerts; ++index) {
        const detailPaletteVert_t& packed =
            palette.verts[entry.vertOffset + index];
        idDrawVert& output = vertices[totals.totalVerts + index];
        std::memset(&output, 0, sizeof(output));
        const idVec3 local(static_cast<float>(packed.xyz[0]),
            static_cast<float>(packed.xyz[1]),
            static_cast<float>(packed.xyz[2]));
        output.xyz = origin + Rotate(rotation, local) * scale;
        output.st.Set(static_cast<float>(packed.st[0]) / 65535.0f,
            static_cast<float>(packed.st[1]) / 65535.0f);
        output.color[0] = detail->color[0];
        output.color[1] = detail->color[1];
        output.color[2] = detail->color[2];
        output.color[3] = 255;
    }
    totals.totalVerts += entry.numVerts;
    totals.totalIndices += entry.numIndices;
}

int GenDetailForSubTree(
    const deferredDetailGenParms_t* const parameters,
    const std::uint16_t* const detailIndices, const int numDetails,
    const int vertexBufferOffset, const int indexBufferOffset,
    const int indexOffset, detailGenTotals_t& totals) {
    totals = detailGenTotals_t{0, 0, {0, 0}};
    if (parameters == nullptr || parameters->subTreeData == nullptr
        || detailIndices == nullptr || numDetails <= 0
        || parameters->verts == nullptr || parameters->indices == nullptr
        || parameters->paletteEntries == nullptr
        || parameters->paletteVerts == nullptr
        || parameters->paletteIndices == nullptr
        || parameters->subTreeDataSize
            < static_cast<int>(sizeof(dm_subTreeData_t))) return 0;

    const dm_subTreeData_t& header = *parameters->subTreeData;
    if (!RangeInside(header.detailOffset, header.numDetail,
            sizeof(dm_detail_t), parameters->subTreeDataSize)
        || !RangeInside(header.attributeOffset, header.numAttributes,
            sizeof(dm_attribute_t), parameters->subTreeDataSize)) return 0;

    dm_subTreeDataPtrs_t pointers{};
    SetupSubTreePtrsFromData(pointers, parameters->subTreeData);
    const int entryCount = parameters->paletteEntriesSize
        / static_cast<int>(sizeof(detailPaletteEntry_t));
    const int vertexCount = parameters->paletteVertsSize
        / static_cast<int>(sizeof(detailPaletteVert_t));
    const int paletteIndexCount = parameters->paletteIndicesSize
        / static_cast<int>(sizeof(std::uint16_t));

    int generated = 0;
    for (int index = 0; index < numDetails; ++index) {
        const int detailIndex = detailIndices[index];
        if (detailIndex < 0 || detailIndex >= header.numDetail) continue;
        const dm_detail_t& detail = pointers.detail[detailIndex];
        if (detail.attribIdx >= header.numAttributes) continue;
        const dm_attribute_t& attribute = pointers.attributes[detail.attribIdx];
        if (attribute.paletteIdx >= entryCount) continue;
        const detailPaletteEntry_t& entry =
            parameters->paletteEntries[attribute.paletteIdx];
        if (entry.vertOffset + entry.numVerts > vertexCount
            || entry.indexOffset + entry.numIndices > paletteIndexCount
            || vertexBufferOffset + totals.totalVerts + entry.numVerts
                > parameters->numVertsAllocated) continue;

        const detailPalette_t palette{&entry, parameters->paletteVerts,
            parameters->paletteIndices};
        BuildDetailModel(palette,
            parameters->verts + vertexBufferOffset,
            parameters->indices + indexBufferOffset, indexOffset,
            &detail, &attribute, totals);
        ++generated;
    }
    return generated;
}

void DetailGatherJob(const deferredDetailGatherParms_t* const parameters) {
    int numDetailIndices = 0;
    GatherDetailIndicesForSubTree(parameters, numDetailIndices);
}

void DetailGenJob(const deferredDetailGenParms_t* const parameters) {
    if (parameters == nullptr || parameters->detailCountsList == nullptr
        || parameters->detailCountsIndex < 0
        || parameters->totalsUsed == nullptr) return;
    if (parameters->detailCountsIndex == 0) {
        GetDetailTotalCount(parameters->detailCountsList,
            parameters->totalsUsed);
    }
    int vertexOffset = 0;
    int indexOffset = 0;
    GetDetailOffsetsForSubTree(parameters->detailCountsList,
        parameters->detailCountsIndex, vertexOffset, indexOffset);
    const detailSubTreeStats_t& counts =
        parameters->detailCountsList[parameters->detailCountsIndex];
    if (counts.subTreeDetailCount < 0
        || vertexOffset + counts.vertCount > parameters->numVertsAllocated
        || indexOffset + counts.indexCount
            > parameters->numVertsAllocated * 6) return;
    detailGenTotals_t generated{};
    GenDetailForSubTree(parameters, parameters->detailIndices,
        counts.subTreeDetailCount, vertexOffset, indexOffset,
        vertexOffset, generated);
}
