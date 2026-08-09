#include "models/detail/detailmodel.h"

#include "idlib/filesystem/file.h"
#include "idlib/filesystem/filesystem.h"
#include "models/detail/decldetail.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>
#include <new>

namespace {

constexpr std::uint32_t DETAIL_BINARY_MAGIC = 1145394179u;
constexpr int MAX_DETAIL_ELEMENTS = 1 << 24;

template<typename type_t>
bool ReadExact(idFile* file, type_t& value) {
    return file != nullptr
        && file->Read(&value, static_cast<unsigned int>(sizeof(value)))
            == sizeof(value);
}

bool ReadBytes(idFile* file, void* data, const int byteCount) {
    return byteCount >= 0 && (byteCount == 0
        || (data != nullptr && file != nullptr
            && file->Read(data, static_cast<unsigned int>(byteCount))
                == static_cast<unsigned int>(byteCount)));
}

std::int16_t ClampShort(const float value) {
    return static_cast<std::int16_t>((std::max)(-32768.0f,
        (std::min)(32767.0f, value)));
}

bool ValidCount(const int count) {
    return count >= 0 && count <= MAX_DETAIL_ELEMENTS;
}

} // namespace

idTypedResourceList<idDetailModel> idDetailModel::resourceList("detailModel");
idStaticList<detailPaletteEntry_t, 128> idDetailModel::paletteEntries;
idStaticList<detailPaletteVert_t, 1024> idDetailModel::paletteVerts;
idStaticList<std::uint16_t, 4096> idDetailModel::paletteIndices;

idDetailModel::idDetailModel()
    : detailModelData{0, 0, nullptr, nullptr}, stats{0, 0, 0} {
}

idDetailModel::~idDetailModel() {
    FreeData();
}

idResourceList* idDetailModel::GetResourceList() {
    return &resourceList;
}

void idDetailModel::FreeData() {
    if (detailModelData.subTrees != nullptr) {
        for (int index = 0; index < detailModelData.numSubTrees; ++index) {
            delete[] reinterpret_cast<std::uint8_t*>(
                detailModelData.subTrees[index].data);
            delete[] reinterpret_cast<std::uint8_t*>(
                detailModelData.subTrees[index].treeNodes);
        }
    }
    delete[] detailModelData.subTrees;
    delete[] detailModelData.treeNodes;
    detailModelData = dm_model_t{0, 0, nullptr, nullptr};
    sharedAttributes.ClearFree();
    stats = dm_modelStats_t{0, 0, 0};
}

void idDetailModel::GetDetailSubTreesForViewRecursive(
    const dm_model_t& model, const std::int16_t frustumVertices[3][8],
    int* const subTreeNumbers, int& numSubTrees, int nodeNumber,
    const int recursionDepth) {
    if (subTreeNumbers == nullptr || recursionDepth > model.numTreeNodes + 1
        || numSubTrees >= model.numSubTrees) {
        return;
    }
    if ((nodeNumber & 0x8000) != 0) {
        const int subTree = nodeNumber & 0x7FFF;
        if (subTree < model.numSubTrees) subTreeNumbers[numSubTrees++] = subTree;
        return;
    }
    if (nodeNumber < 0 || nodeNumber >= model.numTreeNodes
        || model.treeNodes == nullptr) {
        return;
    }

    const dm_treeNode_t& node = model.treeNodes[nodeNumber];
    const int axis = node.planeType < 3 ? node.planeType : 2;
    bool front = false;
    bool back = false;
    for (int vertex = 0; vertex < 8; ++vertex) {
        const int coordinate = frustumVertices[axis][vertex];
        front = front || coordinate >= node.planeDist;
        back = back || coordinate <= node.planeDist;
    }
    if (front) {
        GetDetailSubTreesForViewRecursive(model, frustumVertices,
            subTreeNumbers, numSubTrees, node.children[0],
            recursionDepth + 1);
    }
    if (back) {
        GetDetailSubTreesForViewRecursive(model, frustumVertices,
            subTreeNumbers, numSubTrees, node.children[1],
            recursionDepth + 1);
    }
}

int idDetailModel::GetDetailSubTreesForView(const dm_model_t& model,
    const detailRenderView_t* const viewData, int* const subTreeNumbers) {
    if (viewData == nullptr || subTreeNumbers == nullptr
        || model.numSubTrees <= 0) {
        return 0;
    }
    if (model.numTreeNodes == 0) {
        subTreeNumbers[0] = 0;
        return 1;
    }

    idVec3 corners[8];
    const float distances[2] = {viewData->nearDist, viewData->farDist};
    int output = 0;
    for (int distanceIndex = 0; distanceIndex < 2; ++distanceIndex) {
        const float distance = distances[distanceIndex];
        for (int vertical = 0; vertical < 2; ++vertical) {
            const float upSign = vertical == 0 ? 1.0f : -1.0f;
            for (int horizontal = 0; horizontal < 2; ++horizontal) {
                const float leftSign = horizontal == 0 ? 1.0f : -1.0f;
                corners[output++] = viewData->viewOrg
                    + viewData->viewFwd * distance
                    + viewData->viewLeft
                        * (distance * viewData->fov[0] * leftSign)
                    + viewData->viewUp
                        * (distance * viewData->fov[1] * upSign);
            }
        }
    }

    std::int16_t frustumVertices[3][8];
    for (int vertex = 0; vertex < 8; ++vertex) {
        for (int axis = 0; axis < 3; ++axis) {
            frustumVertices[axis][vertex] = ClampShort(corners[vertex][axis]);
        }
    }
    int count = 0;
    GetDetailSubTreesForViewRecursive(model, frustumVertices,
        subTreeNumbers, count, 0, 0);
    return count;
}

bool idDetailModel::LoadBinary(const char* const detailFileName) {
    if (fileSystem == nullptr || detailFileName == nullptr) return false;
    idStr binaryName(detailFileName);
    binaryName.SetFileExtension("bdetail");
    idFileLocal file(fileSystem->OpenFileRead(binaryName.c_str(), true, false));
    if (file.file == nullptr) return false;

    std::uint32_t magic = 0;
    std::uint32_t attributeCount = 0;
    if (!ReadExact(file.file, magic) || magic != DETAIL_BINARY_MAGIC
        || !ReadExact(file.file, attributeCount)
        || attributeCount > static_cast<std::uint32_t>(MAX_DETAIL_ELEMENTS)
        || !sharedAttributes.SetNum(static_cast<int>(attributeCount))) {
        return false;
    }
    for (std::uint32_t index = 0; index < attributeCount; ++index) {
        idStr name;
        file->ReadString(name);
        sharedAttributes[index] = name.Length() == 0 ? nullptr
            : static_cast<const idDeclDetail*>(
                idDeclDetail::resourceList.FindWithInheritance(
                    name.c_str(), true));
    }

    if (!ReadExact(file.file, detailModelData.numTreeNodes)
        || !ValidCount(detailModelData.numTreeNodes)) return false;
    detailModelData.treeNodes = detailModelData.numTreeNodes != 0
        ? new (std::nothrow) dm_treeNode_t[detailModelData.numTreeNodes]
        : nullptr;
    if ((detailModelData.numTreeNodes != 0
            && detailModelData.treeNodes == nullptr)
        || !ReadBytes(file.file, detailModelData.treeNodes,
            detailModelData.numTreeNodes
                * static_cast<int>(sizeof(dm_treeNode_t)))) return false;

    if (!ReadExact(file.file, detailModelData.numSubTrees)
        || !ValidCount(detailModelData.numSubTrees)) return false;
    detailModelData.subTrees = detailModelData.numSubTrees != 0
        ? new (std::nothrow) dm_subTree_t[detailModelData.numSubTrees]()
        : nullptr;
    if (detailModelData.numSubTrees != 0
        && detailModelData.subTrees == nullptr) return false;

    for (int index = 0; index < detailModelData.numSubTrees; ++index) {
        dm_subTree_t& subTree = detailModelData.subTrees[index];
        if (!ReadBytes(file.file, subTree.bounds.b[0], 8)
            || !ReadBytes(file.file, subTree.bounds.b[1], 8)
            || !ReadExact(file.file, subTree.maxDetailHeight)
            || !ReadExact(file.file, subTree.totalDataSize)
            || !ReadExact(file.file, subTree.totalTreeNodeSize)
            || subTree.totalDataSize < static_cast<int>(sizeof(dm_subTreeData_t))
            || subTree.totalTreeNodeSize < sizeof(dm_subTreeTreeNodes_t)
            || subTree.totalDataSize > MAX_DETAIL_ELEMENTS * 32
            || subTree.totalTreeNodeSize > MAX_DETAIL_ELEMENTS * 16) {
            return false;
        }
        std::uint8_t* const data = new (std::nothrow)
            std::uint8_t[subTree.totalDataSize];
        std::uint8_t* const nodes = new (std::nothrow)
            std::uint8_t[subTree.totalTreeNodeSize];
        if (data == nullptr || nodes == nullptr) {
            delete[] data;
            delete[] nodes;
            return false;
        }
        subTree.data = reinterpret_cast<dm_subTreeData_t*>(data);
        subTree.treeNodes = reinterpret_cast<dm_subTreeTreeNodes_t*>(nodes);
        if (!ReadBytes(file.file, data, subTree.totalDataSize)
            || !ReadBytes(file.file, nodes, subTree.totalTreeNodeSize)) {
            return false;
        }
        subTree.treeNodes->pad[0] = 0;
        subTree.treeNodes->pad[1] = 0;
        if (!ValidCount(subTree.data->numDetail)
            || !ValidCount(subTree.data->numAttributes)
            || !ValidCount(subTree.treeNodes->numTreeNodes)
            || subTree.data->detailOffset < 0
            || subTree.data->attributeOffset < 0
            || subTree.treeNodes->treeNodeOffset < 0
            || static_cast<std::uint64_t>(subTree.data->detailOffset)
                + static_cast<std::uint64_t>(subTree.data->numDetail)
                    * sizeof(dm_detail_t)
                > static_cast<std::uint64_t>(subTree.totalDataSize)
            || static_cast<std::uint64_t>(subTree.data->attributeOffset)
                + static_cast<std::uint64_t>(subTree.data->numAttributes)
                    * sizeof(dm_attribute_t)
                > static_cast<std::uint64_t>(subTree.totalDataSize)
            || static_cast<std::uint64_t>(
                    subTree.treeNodes->treeNodeOffset)
                + static_cast<std::uint64_t>(
                    subTree.treeNodes->numTreeNodes)
                    * sizeof(dm_treeNode_t)
                > static_cast<std::uint64_t>(subTree.totalTreeNodeSize)) {
            return false;
        }
    }

    int entryCount = 0;
    int vertexCount = 0;
    int indexCount = 0;
    if (!ReadExact(file.file, entryCount) || entryCount < 0
        || entryCount > 128 || !paletteEntries.SetNum(entryCount)
        || !ReadBytes(file.file, paletteEntries.Ptr(),
            entryCount * static_cast<int>(sizeof(detailPaletteEntry_t)))
        || !ReadExact(file.file, vertexCount) || vertexCount < 0
        || vertexCount > 1024 || !paletteVerts.SetNum(vertexCount)
        || !ReadBytes(file.file, paletteVerts.Ptr(),
            vertexCount * static_cast<int>(sizeof(detailPaletteVert_t)))
        || !ReadExact(file.file, indexCount) || indexCount < 0
        || indexCount > 4096 || !paletteIndices.SetNum(indexCount)
        || !ReadBytes(file.file, paletteIndices.Ptr(),
            indexCount * static_cast<int>(sizeof(std::uint16_t)))
        || !ReadExact(file.file, magic) || magic != DETAIL_BINARY_MAGIC) {
        return false;
    }

    int totalDetails = 0;
    for (int index = 0; index < detailModelData.numSubTrees; ++index) {
        totalDetails += detailModelData.subTrees[index].data->numDetail;
    }
    stats.numDetailNodes = totalDetails;
    stats.numTreeNodes = detailModelData.numTreeNodes;
    stats.numSubTrees = detailModelData.numSubTrees;
    ClearResourceError();
    return true;
}

void idDetailModel::LoadResource() {
    FreeData();
    if (!LoadBinary(GetName())) {
        SetResourceError("Couldn't load detailmodel '%s'", GetName());
        FreeData();
    }
}
