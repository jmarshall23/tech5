#pragma once

#include "framework/resource.h"
#include "framework/resourcelist.h"
#include "idlib/containers/list.h"
#include "idlib/geometry/rendermatrix.h"

#include <cstdint>

class idDeclFoliage;
class idRenderWorldLocal;

struct fm_treeNode_t {
    std::uint16_t planeType;
    std::int16_t planeDist;
    std::uint16_t children[2];
};
struct fm_subTreeBounds_t { std::int16_t b[2][4]; };
struct fm_subTreeTreeNodes_t {
    int numTreeNodes;
    int treeNodeOffset;
    int numLeafInfo;
    int leafInfoOffset;
};
struct fm_subTreeData_t {
    int numFoliage;
    int foliageOffset;
    int numAttributes;
    int attributeOffset;
};
struct fm_subTree_t {
    fm_subTreeBounds_t bounds;
    std::uint16_t maxFoliageHeight;
    std::uint16_t totalTreeNodeSize;
    int totalDataSize;
    fm_subTreeTreeNodes_t* treeNodes;
    fm_subTreeData_t* data;
};
struct fm_foliage_t {
    std::int16_t xyz[3];
    std::uint8_t attribIdx;
    std::uint8_t uniformSizeScale;
    std::uint8_t color[3];
    std::uint8_t shapeType;
    std::uint8_t upVec[3];
    std::uint8_t pad;
};
struct fm_attribute_t {
    float sortScaleBias[4];
    std::uint16_t declIdx;
    std::uint16_t quadWidth;
    std::uint16_t quadHeight;
    std::uint8_t widthVariance;
    std::uint8_t heightVariance;
    std::uint8_t flipHoriz;
    std::uint8_t shape;
    std::uint8_t swayMagnitude;
    std::uint8_t pad0;
    int pad;
};
struct fm_leafInfo_t {
    std::int16_t b[2][3];
    std::uint16_t foliageOffset;
    std::uint8_t numBigFoliage;
    std::uint8_t numSmallFoliage;
};
struct fm_subTreeDataPtrs_t {
    fm_foliage_t* foliage;
    fm_attribute_t* attributes;
};
struct fm_subTreeTreeNodePtrs_t {
    fm_treeNode_t* treeNodes;
    fm_leafInfo_t* leafInfo;
};

struct foliageRenderView_t {
    float time;
    float nearDist;
    float farDist;
    float fov[2];
    idVec3 viewOrg;
    idVec3 viewFwd;
    idVec3 viewLeft;
    idVec3 viewUp;
    idRenderMatrix mvpMatrix;
    std::uint16_t atlasWidth;
    std::uint16_t atlasHeight;
    int pad[2];
};

inline void SetupFoliageSubTreeDataPointers(
    fm_subTreeDataPtrs_t& pointers, const fm_subTreeData_t* subTree) {
    if (subTree == nullptr) {
        pointers.foliage = nullptr;
        pointers.attributes = nullptr;
        return;
    }
    std::uint8_t* const base = reinterpret_cast<std::uint8_t*>(
        const_cast<fm_subTreeData_t*>(subTree));
    pointers.foliage = reinterpret_cast<fm_foliage_t*>(
        base + subTree->foliageOffset);
    pointers.attributes = reinterpret_cast<fm_attribute_t*>(
        base + subTree->attributeOffset);
}

inline void SetupFoliageSubTreeNodePointers(
    fm_subTreeTreeNodePtrs_t& pointers,
    const fm_subTreeTreeNodes_t* subTree) {
    if (subTree == nullptr) {
        pointers.treeNodes = nullptr;
        pointers.leafInfo = nullptr;
        return;
    }
    std::uint8_t* const base = reinterpret_cast<std::uint8_t*>(
        const_cast<fm_subTreeTreeNodes_t*>(subTree));
    pointers.treeNodes = reinterpret_cast<fm_treeNode_t*>(
        base + subTree->treeNodeOffset);
    pointers.leafInfo = reinterpret_cast<fm_leafInfo_t*>(
        base + subTree->leafInfoOffset);
}

struct fm_model_t {
    int numTreeNodes;
    int numSubTrees;
    fm_treeNode_t* treeNodes;
    fm_subTree_t* subTrees;
};

struct fm_modelStats_t {
    int numFoliageNodes;
    int numTreeNodes;
    int numSubTrees;
};

class idFoliageModel : public idResource {
public:
    using AtlasResolver = bool (*)(const idDeclFoliage* declaration,
        idVec4& scaleBias);
    using WorldLoadCallback = void (*)(idRenderWorldLocal* renderWorld);

    idFoliageModel();
    ~idFoliageModel() override;

    void LoadResource() override;
    idResourceList* GetResourceList() override;
    void FreeData();
    bool LoadBinary(const char* foliageFileName);
    static int GetFoliageSubTreesForView(const fm_model_t& model,
        const foliageRenderView_t* viewData, int* subTreeNumbers);
    static void SetAtlasResolver(AtlasResolver resolver);
    static void SetWorldLoadCallback(WorldLoadCallback callback);
    static void LoadFoliageForWorld(idRenderWorldLocal* renderWorld);

    fm_model_t foliageModelData;
    idList<const idDeclFoliage*, 5> sharedAttributes;
    fm_modelStats_t stats;

    static idTypedResourceList<idFoliageModel> resourceList;

private:
    static void GetFoliageSubTreesForViewRecursive(const fm_model_t& model,
        const std::int16_t frustumVertices[3][8], int* subTreeNumbers,
        int& numSubTrees, int nodeNumber, int recursionDepth);
    void InitializeAttributes(std::uint32_t binaryMagic);
    static void SwapModelSubTrees(fm_subTreeData_t* data,
        fm_subTreeTreeNodes_t* treeNodes);
    static AtlasResolver atlasResolver;
    static WorldLoadCallback worldLoadCallback;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(fm_model_t) == 16,
    "Recovered foliage-model data ABI changed");
static_assert(sizeof(fm_modelStats_t) == 12,
    "Recovered foliage-model statistics ABI changed");
static_assert(sizeof(fm_treeNode_t) == 8,
    "Recovered foliage tree-node ABI changed");
static_assert(sizeof(fm_subTreeBounds_t) == 16,
    "Recovered foliage subtree-bounds ABI changed");
static_assert(sizeof(fm_subTreeTreeNodes_t) == 16,
    "Recovered foliage subtree tree-header ABI changed");
static_assert(sizeof(fm_subTreeData_t) == 16,
    "Recovered foliage subtree data-header ABI changed");
static_assert(sizeof(fm_foliage_t) == 16,
    "Recovered foliage placement ABI changed");
static_assert(sizeof(fm_attribute_t) == 32,
    "Recovered foliage attribute ABI changed");
static_assert(sizeof(fm_leafInfo_t) == 16,
    "Recovered foliage leaf ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(fm_subTree_t) == 32,
    "Recovered foliage subtree ABI changed");
#endif
#endif
