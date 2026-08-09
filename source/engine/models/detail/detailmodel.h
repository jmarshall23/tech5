#pragma once

#include "framework/resource.h"
#include "framework/resourcelist.h"
#include "idlib/containers/list.h"
#include "idlib/containers/staticlist.h"
#include "idlib/geometry/rendermatrix.h"
#include "idlib/math/quat.h"

#include <cstdint>

class idDeclDetail;

struct dm_treeNode_t {
    std::uint16_t planeType;
    std::int16_t planeDist;
    std::uint16_t children[2];
    std::uint32_t counts[2];
};

struct dm_subTreeBounds_t { std::int16_t b[2][4]; };

struct dm_subTreeTreeNodes_t {
    int numTreeNodes;
    int treeNodeOffset;
    int pad[2];
};

struct dm_subTreeData_t {
    int numDetail;
    int detailOffset;
    int numAttributes;
    int attributeOffset;
};

struct dm_subTree_t {
    dm_subTreeBounds_t bounds;
    std::uint16_t maxDetailHeight;
    std::uint16_t totalTreeNodeSize;
    int totalDataSize;
    dm_subTreeTreeNodes_t* treeNodes;
    dm_subTreeData_t* data;
};

struct dm_detail_t {
    std::int16_t xyz[3];
    std::uint8_t attribIdx;
    std::uint8_t uniformSizeScale;
    std::uint8_t color[3];
    std::uint8_t pad[9];
    idCQuat rotation;
};

struct dm_attribute_t {
    std::uint16_t declIdx;
    std::uint16_t paletteIdx;
    int pad[7];
};

struct dm_subTreeTreeNodePtrs_t { dm_treeNode_t* treeNodes; };
struct dm_subTreeDataPtrs_t {
    dm_detail_t* detail;
    dm_attribute_t* attributes;
};

struct detailPaletteEntry_t {
    std::uint16_t vertOffset;
    std::uint16_t indexOffset;
    std::uint16_t numVerts;
    std::uint16_t numIndices;
};

struct detailPaletteVert_t {
    std::int16_t xyz[3];
    std::uint16_t st[2];
};

struct detailRenderView_t {
    float time;
    float nearDist;
    float farDist;
    float fov[2];
    idVec3 viewOrg;
    idVec3 viewFwd;
    idVec3 viewLeft;
    idVec3 viewUp;
    int pad[3];
    idRenderMatrix mvpMatrix;
};

inline void SetupSubTreePtrsFromTreeNodes(
    dm_subTreeTreeNodePtrs_t& pointers,
    const dm_subTreeTreeNodes_t* subTree) {
    pointers.treeNodes = subTree != nullptr
        ? reinterpret_cast<dm_treeNode_t*>(
            reinterpret_cast<std::uint8_t*>(
                const_cast<dm_subTreeTreeNodes_t*>(subTree))
            + subTree->treeNodeOffset)
        : nullptr;
}

inline void SetupSubTreePtrsFromData(dm_subTreeDataPtrs_t& pointers,
    const dm_subTreeData_t* subTree) {
    if (subTree == nullptr) {
        pointers.detail = nullptr;
        pointers.attributes = nullptr;
        return;
    }
    std::uint8_t* const base = reinterpret_cast<std::uint8_t*>(
        const_cast<dm_subTreeData_t*>(subTree));
    pointers.detail = reinterpret_cast<dm_detail_t*>(
        base + subTree->detailOffset);
    pointers.attributes = reinterpret_cast<dm_attribute_t*>(
        base + subTree->attributeOffset);
}

struct dm_model_t {
    int numTreeNodes;
    int numSubTrees;
    dm_treeNode_t* treeNodes;
    dm_subTree_t* subTrees;
};

struct dm_modelStats_t {
    int numDetailNodes;
    int numTreeNodes;
    int numSubTrees;
};

class idDetailModel : public idResource {
public:
    idDetailModel();
    ~idDetailModel() override;

    void LoadResource() override;
    idResourceList* GetResourceList() override;

    void FreeData();
    bool LoadBinary(const char* detailFileName);
    static int GetDetailSubTreesForView(const dm_model_t& model,
        const detailRenderView_t* viewData, int* subTreeNumbers);

    dm_model_t detailModelData;
    idList<const idDeclDetail*, 5> sharedAttributes;
    dm_modelStats_t stats;

    static idTypedResourceList<idDetailModel> resourceList;
    static idStaticList<detailPaletteEntry_t, 128> paletteEntries;
    static idStaticList<detailPaletteVert_t, 1024> paletteVerts;
    static idStaticList<std::uint16_t, 4096> paletteIndices;

private:
    static void GetDetailSubTreesForViewRecursive(const dm_model_t& model,
        const std::int16_t frustumVertices[3][8], int* subTreeNumbers,
        int& numSubTrees, int nodeNumber, int recursionDepth);
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(dm_model_t) == 16,
    "Recovered detail-model data ABI changed");
static_assert(sizeof(dm_modelStats_t) == 12,
    "Recovered detail-model statistics ABI changed");
static_assert(sizeof(dm_treeNode_t) == 16,
    "Recovered detail tree-node ABI changed");
static_assert(sizeof(dm_subTreeBounds_t) == 16,
    "Recovered detail subtree-bounds ABI changed");
static_assert(sizeof(dm_subTreeTreeNodes_t) == 16,
    "Recovered detail subtree tree-header ABI changed");
static_assert(sizeof(dm_subTreeData_t) == 16,
    "Recovered detail subtree data-header ABI changed");
static_assert(sizeof(dm_detail_t) == 32,
    "Recovered detail placement ABI changed");
static_assert(sizeof(dm_attribute_t) == 32,
    "Recovered detail attribute ABI changed");
static_assert(sizeof(detailPaletteEntry_t) == 8,
    "Recovered detail palette-entry ABI changed");
static_assert(sizeof(detailPaletteVert_t) == 10,
    "Recovered detail palette-vertex ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(dm_subTree_t) == 32,
    "Recovered detail subtree ABI changed");
#endif
#endif
