#pragma once

#include "cm/collisiontypes.h"
#include "idlib/containers/list.h"
#include "idlib/geometry/winding.h"
#include "idlib/text/str.h"

class idCollisionModelLocal;
class idCollisionGridState;
class idDeclMD6;
class idDrawVert;
class idGenGridModel;
class idMapBrush;
class idMapFile;
class idMapModel;
class idMapPatch;
class idMaterial;
class idRenderModel;
class idStaticModel;
class idSurface_Patch;
class idTraceModel;
class idLexer;

struct cm_buildPolygonRef_t;
struct cm_buildPolytopeRef_t;

struct cm_buildVertex_t {
    idVec3 p;
    std::uint16_t st[2];
    int checkCount;
    int index;
};

struct cm_buildEdge_t {
    int vertexNum[2];
    idVec3 normal;
    std::uint8_t internal;
    std::uint8_t numUsers;
    std::uint16_t pad;
    int checkCount;
    int index;
};

struct cm_buildMaterial_t {
    int contentFlags;
    int surfaceFlags;
    int surfaceType;
    int checkCount;
    int index;
};

struct cm_collisionSphereDesc_t {
    std::uint8_t joint;
    std::uint8_t surfaceType;
    std::uint16_t pad;
    idVec3 offset;
    float radius;
};

struct cm_sphereBuildSource_t {
    const char* name;
    std::uint32_t timeStamp;
    idBounds bounds;
    int contents;
    int numModelJoints;
    const cm_collisionSphereDesc_t* spheres;
    int numSpheres;
};

using cm_declMD6SphereExtractor_t = bool (*)(const idDeclMD6*,
    cm_sphereBuildSource_t&);

struct cm_materialBuildInfo_t {
    int contents;
    int surfaceFlags;
    int surfaceType;
    bool discrete;
};

struct cm_modelSurfaceBuildSource_t {
    const idDrawVert* vertices;
    int numVertices;
    const std::uint16_t* indices;
    int numIndices;
    const idMaterial* material;
};

struct cm_modelBuildSource_t {
    const char* name;
    std::uint32_t timeStamp;
    const cm_modelSurfaceBuildSource_t* surfaces;
    int numSurfaces;
};

using cm_materialBuildInfoExtractor_t = bool (*)(const idMaterial*,
    cm_materialBuildInfo_t&);
using cm_materialResolver_t = const idMaterial* (*)(const char*);
using cm_renderModelBuildExtractor_t = bool (*)(const idRenderModel*,
    cm_modelBuildSource_t&);
using cm_staticModelBuildExtractor_t = bool (*)(const idStaticModel*,
    cm_modelBuildSource_t&);
using cm_mapFileBuildCallback_t = void (*)(const idMapFile*, bool, bool);

bool CM_GetMaterialBuildInfo(const idMaterial* material,
    cm_materialBuildInfo_t& info);

struct cm_buildNodeStats_t {
    int numNodes;
    int numPrimitiveIndices;
    int numMaterials;
    int numPolygons;
    int numPolygonEdges;
    int numEdges;
    int numVertices;
    int numPolytopes;
    int numPolytopePlanes;
    int lastNumPolygonEdges;
    int totalMemory;
    bool canCreateSubModel;
    std::uint8_t pad[3];
};

struct cm_buildNode_t {
    int planeType;
    float planeDist;
    idBounds bounds;
    cm_buildNode_t* parent;
    cm_buildNode_t* children[2];
    cm_buildPolygonRef_t* polygons;
    cm_buildPolytopeRef_t* polytopes;
    cm_buildNodeStats_t stats;
};

struct cm_buildPolygonRef_t {
    int polygonNum;
    cm_buildPolygonRef_t* next;
};

struct cm_buildPolytopeRef_t {
    int polytopeNum;
    cm_buildPolytopeRef_t* next;
};

struct cm_buildNodeBlock_t {
    int size;
    cm_buildNode_t* nextNode;
    cm_buildNodeBlock_t* next;
};

struct cm_buildPolygonRefBlock_t {
    int size;
    cm_buildPolygonRef_t* nextRef;
    cm_buildPolygonRefBlock_t* next;
};

struct cm_buildPolytopeRefBlock_t {
    int size;
    cm_buildPolytopeRef_t* nextRef;
    cm_buildPolytopeRefBlock_t* next;
};

struct cm_buildPolygon_t {
    idPlane plane;
    idBounds bounds;
    int contents;
    int material;
    int primitiveNum;
    int numEdges;
    int firstEdge;
    int checkCount;
    int index;
};

struct cm_buildPolytope_t {
    idBounds bounds;
    int contents;
    int material;
    int primitiveNum;
    int numPlanes;
    int firstPlane;
    int checkCount;
    int index;
};

struct cm_buildModel_t {
    idStr name;
    int maxVertices;
    int numVertices;
    cm_buildVertex_t* vertices;
    int maxEdges;
    int numEdges;
    cm_buildEdge_t* edges;
    int maxPolygonEdges;
    int numPolygonEdges;
    int* polygonEdges;
    int maxPolygons;
    int numPolygons;
    cm_buildPolygon_t* polygons;
    int maxPolytopePlanes;
    int numPolytopePlanes;
    idPlane* polytopePlanes;
    int maxPolytopes;
    int numPolytopes;
    cm_buildPolytope_t* polytopes;
    int numNodes;
    cm_buildNode_t* node;
    idList<cm_buildMaterial_t, 13> materials;
    cm_buildNodeBlock_t* nodeBlocks;
    cm_buildPolygonRefBlock_t* polygonRefBlocks;
    cm_buildPolytopeRefBlock_t* polytopeRefBlocks;
    int checkCount;
    bool isWorldModel;
    std::uint8_t pad[3];
    int numPrimitives;
    int numPolytopeRefs;
    int numPolygonRefs;
    int numInternalEdges;
    int numSharpEdges;
    int numRemovedPolys;
    int numMergedPolys;
};

struct cm_windingList_t {
    int numWindings;
    idFixedWinding w[256];
    idVec3 normal;
    idBounds bounds;
    idVec3 origin;
    float radius;
    int contents;
    int primitiveNum;
};

int CM_R_CountChildren(cm_buildNode_t* node);
void CM_R_TestOptimisation(cm_buildNode_t* node,
    int& numSavedPolygonIndices, int& numSavedPolytopeIndices);
bool CM_R_InsideAllChildren(cm_buildNode_t* node,
    const idBounds& bounds);

class idCollisionModelBuilder {
public:
    class idStaticModelGeometry {
    public:
        const idStaticModel* staticModel = nullptr;
        const idMapModel* mapModel = nullptr;
        const idRenderModel* renderModel = nullptr;
        idList<int, TAG_COLLISION> primitiveGroupNumbers;
        idVec3 origin;
        idMat3 axis;
        idVec3 scale;
        const idMaterial* overrideClipMaterial = nullptr;
    };

    class idCollisionModelGeometry {
    public:
        idCollisionModelLocal* collisionModel = nullptr;
        idStr modelName;
        unsigned int fileTime = 0;
        bool isWorldEntity = false;
        bool isStreamed = false;
        bool isStreamArea = false;
        bool allowDiscrete = false;
        idVec3 streamVolumeOrigin;
        idMat3 streamVolumeAxis;
        idList<idStaticModelGeometry, TAG_COLLISION> models;
    };

    static cm_buildNode_t* AllocNode(cm_buildModel_t* model,
        int blockSize);
    static cm_buildPolygonRef_t* AllocPolygonReference(
        cm_buildModel_t* model, int blockSize);
    static cm_buildPolytopeRef_t* AllocPolytopeReference(
        cm_buildModel_t* model, int blockSize);
    static cm_buildPolygon_t* AllocPolygon(cm_buildModel_t* model,
        int numEdges);
    static cm_buildPolytope_t* AllocPolytope(cm_buildModel_t* model,
        int numPlanes);
    static void AddPolygonToNode(cm_buildModel_t* model,
        cm_buildNode_t* node, cm_buildPolygon_t* polygon);
    static void AddPolytopeToNode(cm_buildModel_t* model,
        cm_buildNode_t* node, cm_buildPolytope_t* polytope);
    static void GetPrimitiveCounts(const cm_buildNode_t* node,
        int& polygonCount, int& polytopeCount);
    static int GetNodeContents(const cm_buildModel_t* model,
        const cm_buildNode_t* node);
    static void FindSubModels_r(const cm_buildModel_t* buildModel,
        cm_buildNode_t* buildNode, int& numModelTreeNodes,
        int& numSubModels);
    static void FreeModelMemory(cm_buildModel_t* model);
    static bool PointInsidePolygon(cm_buildModel_t* model,
        cm_buildPolygon_t* polygon, const idVec3& point);
    static void RemovePolygon(cm_buildModel_t* model,
        cm_buildNode_t* node, int polygonNum);
    static bool SplitterDividesPrimitives(cm_buildModel_t* model,
        const cm_buildNode_t* node, int planeType, float planeDist);
    static void GetNodeBounds_r(const cm_buildModel_t* model,
        const cm_buildNode_t* node, idBounds& bounds);
    static void GetNodeBounds(const cm_buildModel_t* model,
        const cm_buildNode_t* node, idBounds& bounds);
    static void GetStatsFromNode(const cm_buildModel_t* buildModel,
        const cm_buildNode_t* buildNode, cm_buildNodeStats_t& stats);
    static void CreateStatsForSubTree_r(const cm_buildModel_t* buildModel,
        const cm_buildNode_t* buildNode, cm_buildNodeStats_t& stats);
    static bool TestBoundsRange(const char* modelName,
        const idBounds& bounds);
    static void SetupHash();
    static void ClearHash(const idBounds& bounds);
    static void ShutdownHash();
    static bool GetVertex(cm_buildModel_t* model, const idVec3& vertex,
        int& vertexNum);
    static bool GetEdge(cm_buildModel_t* model, const idVec3& vertex1,
        const idVec3& vertex2, int& edgeNum, int vertex1Num = -1);
    static cm_buildModel_t* AllocBuildModel();
    static int FindMaterial(cm_buildModel_t* model, int contentFlags,
        int surfaceFlags, int surfaceType);
    static bool IsStaticRenderModel(const char* fileName);
    static void CreatePolygon(cm_buildModel_t* model, idFixedWinding* winding,
        const idPlane& plane, const idMaterial* material,
        int primitiveNum);
    static void PolygonFromWinding(cm_buildModel_t* model,
        idFixedWinding* winding, const idPlane& plane,
        const idMaterial* material, int primitiveNum);
    static void FilterPolygonIntoTree_r(cm_buildModel_t* model,
        cm_buildNode_t* node, cm_buildPolygonRef_t* reference,
        cm_buildPolygon_t* polygon);
    static void FilterPolytopeIntoTree_r(cm_buildModel_t* model,
        cm_buildNode_t* node, cm_buildPolytopeRef_t* reference,
        cm_buildPolytope_t* polytope);
    static bool FindSplitter(cm_buildModel_t* model,
        const cm_buildNode_t* node, const idBounds& bounds,
        int& planeType, float& planeDist);
    static cm_buildNode_t* CreateAxialBSPTree_r(cm_buildModel_t* model,
        cm_buildNode_t* node);
    static cm_buildNode_t* CreateAxialBSPTree(cm_buildModel_t* model);
    static void AddBuildNodePrimitivesToSubModelNode(
        const cm_buildModel_t* buildModel, cm_buildNode_t* buildNode,
        cm_subModelPtrs_t& subModelPtrs, cm_subModelData_t& counts,
        cm_node_t& node);
    static void CreateSingleSubModel_r(const cm_buildModel_t* buildModel,
        cm_buildNode_t* buildNode, cm_subModelPtrs_t& subModelPtrs,
        cm_subModelData_t& counts, cm_node_t* parent);
    static void CreateNodeStats_r(const cm_buildModel_t* buildModel,
        cm_buildNode_t* buildNode);
    static void CreateSubModels_r(const cm_buildModel_t* buildModel,
        cm_buildNode_t* buildNode, idCollisionModelLocal* model,
        cm_modelTreeNode_t* parent);
    static void AddSubModelsToCollisionModel(idCollisionModelLocal* model,
        const cm_buildModel_t* buildModel);
    static int CountModelTreeNodes_r(idCollisionModelLocal* model,
        int nodeNum, idBounds& bounds);
    static void GenerateEdgeNormals_r(cm_buildModel_t* model,
        cm_buildNode_t* node);
    static bool ChoppedAwayByProcBSP_r(int nodeNum,
        idFixedWinding* winding, const idVec3& normal,
        const idVec3& origin, float radius);
    static bool ChoppedAwayByProcBSP(const idFixedWinding& winding,
        const idPlane& plane, int contents);
    static void ReplacePolygons(cm_buildModel_t* model,
        cm_buildNode_t* node, int polygonNum1, int polygonNum2,
        int newPolygonNum);
    static void FindInternalEdgesOnPolygon(cm_buildModel_t* model,
        cm_buildPolygon_t* polygon1, cm_buildPolygon_t* polygon2);
    static void FindInternalPolygonEdges(cm_buildModel_t* model,
        cm_buildNode_t* node, cm_buildPolygon_t* polygon);
    static void FindInternalEdges(cm_buildModel_t* model,
        cm_buildNode_t* node);
    static void OffsetPolygonEdges(cm_buildModel_t* model,
        cm_buildPolygon_t* polygon);
    static void OffsetPolygonEdges_r(cm_buildModel_t* model,
        cm_buildNode_t* node);
    static void ChopWindingListWithPolytope(cm_windingList_t* list,
        const cm_buildModel_t* model, const cm_buildPolytope_t* polytope);
    static void ChopWindingListWithTreePolytopes_r(
        cm_windingList_t* list, const cm_buildModel_t* model,
        const cm_buildNode_t* node);
    static cm_buildPolygon_t* TryMergePolygons(cm_buildModel_t* model,
        int polygonNum1, int polygonNum2);
    static bool MergePolygonWithTreePolygons(cm_buildModel_t* model,
        cm_buildNode_t* node, int polygonNum, bool mergePrimitives);
    static void MergeTreePolygons(cm_buildModel_t* model,
        cm_buildNode_t* node, bool mergePrimitives);
    static void SplitPolygon(cm_buildModel_t* model, int polygonNum);
    static void SplitPolygons(cm_buildModel_t* model);
    static idFixedWinding* WindingOutsidePolytopes(
        cm_buildModel_t* model, idFixedWinding* winding,
        const idPlane& plane, int contents, int primitiveNum);
    static void MergeModelTrees(idCollisionModelLocal* model);
    static void ParseProcNodes(idLexer* source);
    static void LoadProcBSP(const char* name);
    static int SetupBuildGroups(idCollisionModelGeometry& geometry);
    static void AddMapModelEstimates(
        const idStaticModelGeometry& geometry, int groupNum,
        int primitiveNum, int& numVertices, int& numEdges,
        int& numPolygons, idBounds& bounds);
    static void AddRenderModelEstimates(
        const idStaticModelGeometry& geometry, int groupNum,
        int primitiveNum, int& numVertices, int& numEdges,
        int& numPolygons, idBounds& bounds);
    static void GetMapModelBrushBounds(
        const idStaticModelGeometry& geometry, int groupNum,
        idBounds& bounds);
    static void ConvertBrushSides(cm_buildModel_t* model,
        const idMapBrush* brush, const idVec3& origin,
        const idMat3& axis, const idVec3& scale,
        const idMaterial* overrideClipMaterial, int primitiveNum);
    static void ConvertBrush(cm_buildModel_t* model,
        const idMapBrush* brush, const idVec3& origin,
        const idMat3& axis, const idVec3& scale,
        const idMaterial* overrideClipMaterial, int primitiveNum);
    static void CreatePatchPolygons(cm_buildModel_t* model,
        const idSurface_Patch* mesh, const idVec3& origin,
        const idMat3& axis, const idVec3& scale,
        const idMaterial* material, int primitiveNum);
    static void ConvertPatch(cm_buildModel_t* model,
        const idMapPatch* patch, const idVec3& origin,
        const idMat3& axis, const idVec3& scale,
        const idMaterial* overrideClipMaterial, int primitiveNum);
    static void ConvertMapModelPolytopes(cm_buildModel_t* model,
        const idStaticModelGeometry& geometry, int groupNum,
        int primitiveNum);
    static void ConvertMapModelPrimitives(cm_buildModel_t* model,
        const idStaticModelGeometry& geometry, int groupNum,
        int primitiveNum);
    static void ConvertRenderModelSurfaces(cm_buildModel_t* model,
        const idStaticModelGeometry& geometry, int groupNum,
        int primitiveNum);
    static void AddCollisionModelGeometry(idCollisionModelLocal* model,
        const idCollisionModelGeometry& geometry, int groupNum);
    static void BuildCollisionModelForGeometry(idCollisionModelLocal* model,
        idCollisionModelGeometry& geometry, const int* subModelIndices,
        int numSubModelIndices, const char* optionalModelName);
    static bool BuildForRenderModel(idCollisionModelLocal* model,
        const idRenderModel* renderModel);
    static bool BuildForStaticModel(idCollisionModelLocal* model,
        const idStaticModel* staticModel, const int* subModelIndices,
        int numSubModelIndices, const char* optionalModelName);
    static void BuildForMapFile(const idMapFile* mapFile,
        bool inlineStatic, bool mapModelOnly);
    static void CreateStreamAreas(idCollisionModelLocal* model,
        const idList<idCollisionModelGeometry, TAG_IDLIB>& geometries);
    static void SetMaterialBuildInfoExtractor(
        cm_materialBuildInfoExtractor_t extractor);
    static void SetMaterialResolver(cm_materialResolver_t resolver);
    static void SetRenderModelBuildExtractor(
        cm_renderModelBuildExtractor_t extractor);
    static void SetStaticModelBuildExtractor(
        cm_staticModelBuildExtractor_t extractor);
    static void SetMapFileBuildCallback(cm_mapFileBuildCallback_t callback);

    static bool IsAnimatedRenderModel(const char* fileName);
    static bool BuildForDeclMD6(idCollisionModelLocal* model,
        const idDeclMD6* md6Decl);
    static bool BuildForSpheres(idCollisionModelLocal* model,
        const cm_sphereBuildSource_t& source);
    static void SetDeclMD6SphereExtractor(
        cm_declMD6SphereExtractor_t extractor);

    static int SetupSubModelData(cm_subModelData_t& data,
        const cm_buildNodeStats_t& stats);
    static void CalculateSubModelDataSize(cm_buildNodeStats_t& stats);
    static bool BuildForTrm(idCollisionModelLocal* model,
        const char* modelName, const idTraceModel& traceModel,
        const idMaterial* material);
    static bool BuildForGrid(idCollisionModelLocal* model,
        const char* modelName, const idGenGridModel& grid,
        const idCollisionGridState& state, const idMaterial* material);
    static bool AllocSubModelData(const cm_buildNodeStats_t& stats,
        const idBounds& bounds, cm_subModel_t& subModel,
        cm_subModelPtrs_t& pointers);
};

static_assert(sizeof(cm_buildNodeStats_t) == 48,
    "Recovered cm_buildNodeStats_t ABI changed");
static_assert(sizeof(cm_collisionSphereDesc_t) == 20,
    "Recovered collision sphere descriptor layout changed");

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(cm_buildVertex_t) == 24,
    "Recovered cm_buildVertex_t ABI changed");
static_assert(sizeof(cm_buildEdge_t) == 32,
    "Recovered cm_buildEdge_t ABI changed");
static_assert(sizeof(cm_buildMaterial_t) == 20,
    "Recovered cm_buildMaterial_t ABI changed");
static_assert(sizeof(cm_buildNode_t) == 100,
    "Recovered cm_buildNode_t ABI changed");
static_assert(sizeof(cm_buildPolygon_t) == 68,
    "Recovered cm_buildPolygon_t ABI changed");
static_assert(sizeof(cm_buildPolytope_t) == 52,
    "Recovered cm_buildPolytope_t ABI changed");
#endif
