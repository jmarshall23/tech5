#include "models/foliage/foliagemodel.h"

#include "idlib/filesystem/file.h"
#include "idlib/filesystem/filesystem.h"
#include "models/foliage/declfoliage.h"

#include <algorithm>
#include <new>

namespace {

constexpr std::uint32_t FOLIAGE_MAGIC_6 = 1179601926u;
constexpr std::uint32_t FOLIAGE_MAGIC_7 = 1179601927u;
constexpr int MAX_FOLIAGE_ELEMENTS = 1 << 24;

template<typename type_t>
bool ReadExact(idFile* file, type_t& value) {
    return file != nullptr
        && file->Read(&value, static_cast<unsigned int>(sizeof(value)))
            == sizeof(value);
}
bool ReadBytes(idFile* file, void* data, const int bytes) {
    return bytes >= 0 && (bytes == 0 || (file != nullptr && data != nullptr
        && file->Read(data, static_cast<unsigned int>(bytes))
            == static_cast<unsigned int>(bytes)));
}
bool ValidCount(const int count) {
    return count >= 0 && count <= MAX_FOLIAGE_ELEMENTS;
}
std::int16_t ClampShort(const float value) {
    return static_cast<std::int16_t>((std::max)(-32768.0f,
        (std::min)(32767.0f, value)));
}

} // namespace

idTypedResourceList<idFoliageModel>
    idFoliageModel::resourceList("foliageModel");
idFoliageModel::AtlasResolver idFoliageModel::atlasResolver = nullptr;
idFoliageModel::WorldLoadCallback idFoliageModel::worldLoadCallback = nullptr;

idFoliageModel::idFoliageModel()
    : foliageModelData{0, 0, nullptr, nullptr}, stats{0, 0, 0} {
}

idFoliageModel::~idFoliageModel() {
    FreeData();
}

void idFoliageModel::SetAtlasResolver(AtlasResolver resolver) {
    atlasResolver = resolver;
}

void idFoliageModel::SetWorldLoadCallback(WorldLoadCallback callback) {
    worldLoadCallback = callback;
}

void idFoliageModel::LoadFoliageForWorld(
        idRenderWorldLocal* renderWorld) {
    if (renderWorld != nullptr && worldLoadCallback != nullptr)
        worldLoadCallback(renderWorld);
}

idResourceList* idFoliageModel::GetResourceList() {
    return &resourceList;
}

void idFoliageModel::FreeData() {
    if (foliageModelData.subTrees != nullptr) {
        for (int index = 0; index < foliageModelData.numSubTrees; ++index) {
            delete[] reinterpret_cast<std::uint8_t*>(
                foliageModelData.subTrees[index].data);
            delete[] reinterpret_cast<std::uint8_t*>(
                foliageModelData.subTrees[index].treeNodes);
        }
    }
    delete[] foliageModelData.subTrees;
    delete[] foliageModelData.treeNodes;
    foliageModelData = fm_model_t{0, 0, nullptr, nullptr};
    sharedAttributes.ClearFree();
    stats = fm_modelStats_t{0, 0, 0};
}

void idFoliageModel::GetFoliageSubTreesForViewRecursive(
    const fm_model_t& model, const std::int16_t frustumVertices[3][8],
    int* const subTreeNumbers, int& numSubTrees, const int nodeNumber,
    const int recursionDepth) {
    if (subTreeNumbers == nullptr || recursionDepth > model.numTreeNodes + 1
        || numSubTrees >= model.numSubTrees) return;
    if ((nodeNumber & 0x8000) != 0) {
        const int subTree = nodeNumber & 0x7FFF;
        if (subTree < model.numSubTrees) subTreeNumbers[numSubTrees++] = subTree;
        return;
    }
    if (nodeNumber < 0 || nodeNumber >= model.numTreeNodes
        || model.treeNodes == nullptr) return;
    const fm_treeNode_t& node = model.treeNodes[nodeNumber];
    const int axis = node.planeType < 3 ? node.planeType : 2;
    bool front = false;
    bool back = false;
    for (int vertex = 0; vertex < 8; ++vertex) {
        const int coordinate = frustumVertices[axis][vertex];
        front = front || coordinate >= node.planeDist;
        back = back || coordinate <= node.planeDist;
    }
    if (front) GetFoliageSubTreesForViewRecursive(model, frustumVertices,
        subTreeNumbers, numSubTrees, node.children[0], recursionDepth + 1);
    if (back) GetFoliageSubTreesForViewRecursive(model, frustumVertices,
        subTreeNumbers, numSubTrees, node.children[1], recursionDepth + 1);
}

int idFoliageModel::GetFoliageSubTreesForView(const fm_model_t& model,
    const foliageRenderView_t* const viewData, int* const subTreeNumbers) {
    if (viewData == nullptr || subTreeNumbers == nullptr
        || model.numSubTrees <= 0) return 0;
    if (model.numTreeNodes == 0) {
        subTreeNumbers[0] = 0;
        return 1;
    }
    idVec3 corners[8];
    const float distances[2] = {viewData->nearDist, viewData->farDist};
    int corner = 0;
    for (int distanceIndex = 0; distanceIndex < 2; ++distanceIndex) {
        const float distance = distances[distanceIndex];
        for (int vertical = 0; vertical < 2; ++vertical) {
            const float upSign = vertical == 0 ? 1.0f : -1.0f;
            for (int horizontal = 0; horizontal < 2; ++horizontal) {
                const float leftSign = horizontal == 0 ? 1.0f : -1.0f;
                corners[corner++] = viewData->viewOrg
                    + viewData->viewFwd * distance
                    + viewData->viewLeft
                        * (distance * viewData->fov[0] * leftSign)
                    + viewData->viewUp
                        * (distance * viewData->fov[1] * upSign);
            }
        }
    }
    std::int16_t packed[3][8];
    for (int vertex = 0; vertex < 8; ++vertex)
        for (int axis = 0; axis < 3; ++axis)
            packed[axis][vertex] = ClampShort(corners[vertex][axis]);
    int count = 0;
    GetFoliageSubTreesForViewRecursive(model, packed, subTreeNumbers,
        count, 0, 0);
    return count;
}

void idFoliageModel::InitializeAttributes(const std::uint32_t binaryMagic) {
    for (int subTreeIndex = 0;
            subTreeIndex < foliageModelData.numSubTrees; ++subTreeIndex) {
        fm_subTreeData_t* const data =
            foliageModelData.subTrees[subTreeIndex].data;
        fm_subTreeDataPtrs_t pointers{};
        SetupFoliageSubTreeDataPointers(pointers, data);
        for (int index = 0; index < data->numFoliage; ++index) {
            fm_foliage_t& foliage = pointers.foliage[index];
            if (foliage.attribIdx < data->numAttributes) {
                fm_attribute_t& attribute =
                    pointers.attributes[foliage.attribIdx];
                idVec4 scaleBias(1.0f, 1.0f, 0.0f, 0.0f);
                if (attribute.declIdx < sharedAttributes.Num()
                    && atlasResolver != nullptr) {
                    atlasResolver(sharedAttributes[attribute.declIdx],
                        scaleBias);
                }
                attribute.sortScaleBias[0] = scaleBias.x;
                attribute.sortScaleBias[1] = scaleBias.y;
                attribute.sortScaleBias[2] = scaleBias.z;
                attribute.sortScaleBias[3] = scaleBias.w;
            }
            if (binaryMagic <= FOLIAGE_MAGIC_6) {
                foliage.upVec[0] = 128;
                foliage.upVec[1] = 128;
                foliage.upVec[2] = 255;
            }
        }
    }
}

void idFoliageModel::SwapModelSubTrees(fm_subTreeData_t* const data,
        fm_subTreeTreeNodes_t* const treeNodes) {
    if (data == nullptr || treeNodes == nullptr) return;
    fm_subTreeDataPtrs_t pointers{};
    SetupFoliageSubTreeDataPointers(pointers, data);
    for (int index = 0; index < data->numAttributes; ++index) {
        // These bytes were transient generator state in the recovered format.
        pointers.attributes[index].flipHoriz = 0;
        pointers.attributes[index].pad = 0;
    }
}

bool idFoliageModel::LoadBinary(const char* const foliageFileName) {
    if (fileSystem == nullptr || foliageFileName == nullptr) return false;
    idStr binaryName(foliageFileName);
    binaryName.SetFileExtension("bfoliage");
    idFileLocal file(fileSystem->OpenFileRead(binaryName.c_str(), true, false));
    if (file.file == nullptr) return false;

    std::uint32_t magic = 0;
    std::uint32_t attributeCount = 0;
    if (!ReadExact(file.file, magic)
        || (magic != FOLIAGE_MAGIC_6 && magic != FOLIAGE_MAGIC_7)
        || !ReadExact(file.file, attributeCount)
        || attributeCount > MAX_FOLIAGE_ELEMENTS
        || !sharedAttributes.SetNum(static_cast<int>(attributeCount)))
        return false;
    for (std::uint32_t index = 0; index < attributeCount; ++index) {
        idStr name;
        file->ReadString(name);
        sharedAttributes[index] = name.Length() == 0 ? nullptr
            : static_cast<const idDeclFoliage*>(
                idDeclFoliage::resourceList.FindWithInheritance(
                    name.c_str(), true));
    }
    if (!ReadExact(file.file, foliageModelData.numTreeNodes)
        || !ValidCount(foliageModelData.numTreeNodes)) return false;
    foliageModelData.treeNodes = foliageModelData.numTreeNodes != 0
        ? new (std::nothrow) fm_treeNode_t[foliageModelData.numTreeNodes]
        : nullptr;
    if ((foliageModelData.numTreeNodes != 0
            && foliageModelData.treeNodes == nullptr)
        || !ReadBytes(file.file, foliageModelData.treeNodes,
            foliageModelData.numTreeNodes * sizeof(fm_treeNode_t))) return false;
    if (!ReadExact(file.file, foliageModelData.numSubTrees)
        || !ValidCount(foliageModelData.numSubTrees)) return false;
    foliageModelData.subTrees = foliageModelData.numSubTrees != 0
        ? new (std::nothrow) fm_subTree_t[foliageModelData.numSubTrees]()
        : nullptr;
    if (foliageModelData.numSubTrees != 0
        && foliageModelData.subTrees == nullptr) return false;
    for (int index = 0; index < foliageModelData.numSubTrees; ++index) {
        fm_subTree_t& subTree = foliageModelData.subTrees[index];
        if (!ReadBytes(file.file, subTree.bounds.b[0], 8)
            || !ReadBytes(file.file, subTree.bounds.b[1], 8)
            || !ReadExact(file.file, subTree.maxFoliageHeight)
            || !ReadExact(file.file, subTree.totalDataSize)
            || !ReadExact(file.file, subTree.totalTreeNodeSize)
            || subTree.totalDataSize < sizeof(fm_subTreeData_t)
            || subTree.totalTreeNodeSize < sizeof(fm_subTreeTreeNodes_t)
            || subTree.totalDataSize > MAX_FOLIAGE_ELEMENTS * 32
            || subTree.totalTreeNodeSize > MAX_FOLIAGE_ELEMENTS * 16)
            return false;
        std::uint8_t* const data = new (std::nothrow)
            std::uint8_t[subTree.totalDataSize];
        std::uint8_t* const nodes = new (std::nothrow)
            std::uint8_t[subTree.totalTreeNodeSize];
        if (data == nullptr || nodes == nullptr) {
            delete[] data; delete[] nodes; return false;
        }
        subTree.data = reinterpret_cast<fm_subTreeData_t*>(data);
        subTree.treeNodes = reinterpret_cast<fm_subTreeTreeNodes_t*>(nodes);
        if (!ReadBytes(file.file, data, subTree.totalDataSize)
            || !ReadBytes(file.file, nodes, subTree.totalTreeNodeSize)
            || !ValidCount(subTree.data->numFoliage)
            || !ValidCount(subTree.data->numAttributes)
            || !ValidCount(subTree.treeNodes->numTreeNodes)
            || !ValidCount(subTree.treeNodes->numLeafInfo)
            || subTree.data->foliageOffset < 0
            || subTree.data->attributeOffset < 0
            || subTree.treeNodes->treeNodeOffset < 0
            || subTree.treeNodes->leafInfoOffset < 0
            || static_cast<std::uint64_t>(subTree.data->foliageOffset)
                + static_cast<std::uint64_t>(subTree.data->numFoliage)
                    * sizeof(fm_foliage_t) > subTree.totalDataSize
            || static_cast<std::uint64_t>(subTree.data->attributeOffset)
                + static_cast<std::uint64_t>(subTree.data->numAttributes)
                    * sizeof(fm_attribute_t) > subTree.totalDataSize
            || static_cast<std::uint64_t>(subTree.treeNodes->treeNodeOffset)
                + static_cast<std::uint64_t>(subTree.treeNodes->numTreeNodes)
                    * sizeof(fm_treeNode_t) > subTree.totalTreeNodeSize
            || static_cast<std::uint64_t>(subTree.treeNodes->leafInfoOffset)
                + static_cast<std::uint64_t>(subTree.treeNodes->numLeafInfo)
                    * sizeof(fm_leafInfo_t) > subTree.totalTreeNodeSize)
            return false;
        SwapModelSubTrees(subTree.data, subTree.treeNodes);
    }
    std::uint32_t endMagic = 0;
    if (!ReadExact(file.file, endMagic)
        || (endMagic != FOLIAGE_MAGIC_6 && endMagic != FOLIAGE_MAGIC_7))
        return false;
    InitializeAttributes(endMagic);
    int total = 0;
    for (int index = 0; index < foliageModelData.numSubTrees; ++index)
        total += foliageModelData.subTrees[index].data->numFoliage;
    stats = fm_modelStats_t{total, foliageModelData.numTreeNodes,
        foliageModelData.numSubTrees};
    ClearResourceError();
    return true;
}

void idFoliageModel::LoadResource() {
    FreeData();
    if (!LoadBinary(GetName())) {
        SetResourceError("Couldn't load foliage '%s'", GetName());
        FreeData();
    }
}
