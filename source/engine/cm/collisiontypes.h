#pragma once

#include "idlib/bv/bounds.h"
#include "idlib/bv/boundsshort.h"
#include "idlib/math/plane.h"
#include "idlib/math/vector.h"

#include <cstdint>

enum cmType_t : int {
    CM_POLYGONMODEL = 0,
    CM_SPHEREMODEL = 1
};

enum subModelState_t : int {
    SUBMODEL_STATE_UNLOADED = 0,
    SUBMODEL_STATE_LOADED = 1,
    SUBMODEL_STATE_LOADING = 2
};

struct cm_node_t {
    int planeType;
    float planeDist;
    std::uint16_t children[2];
    std::uint16_t firstPrimitive;
    std::uint8_t numPolygons;
    std::uint8_t numPolytopes;
};

struct cm_material_t {
    int contentFlags;
    int surfaceFlags;
    int surfaceType;
    std::uint8_t surfaceColor[3];
    std::uint8_t pad;
};

struct cm_polygon_t {
    idBoundsShort bounds;
    std::uint8_t material;
    std::uint8_t numEdges;
    std::uint16_t firstEdge;
};

struct cm_edge_t {
    std::uint16_t vertexNum[2];
};

struct cm_vertex_t {
    idVec3 p;
    std::uint16_t st[2];
};

struct cm_polytope_t {
    idBoundsShort bounds;
    std::uint8_t material;
    std::uint8_t numPlanes;
    std::uint16_t firstPlane;
};

struct cm_subModelPtrs_t {
    int isConvex;
    cm_node_t* nodes;
    std::uint16_t* primitiveIndices;
    cm_material_t* materials;
    cm_polygon_t* polygons;
    std::uint16_t* polygonEdges;
    cm_edge_t* edges;
    cm_vertex_t* vertices;
    cm_polytope_t* polytopes;
    idPlane* polytopePlanes;
};

struct cm_modelTreeNode_t {
    int planeType;
    float planeDist;
    int children[2];
};

struct cm_subModelHeader_t {
    int totalSize;
    int loadedSize;
    idBounds bounds;
};

struct cm_subModelData_t {
    cm_subModelHeader_t header;
    int isConvex;
    int numNodes;
    int nodeOffset;
    int numPrimitiveIndices;
    int primitiveIndexOffset;
    int numMaterials;
    int materialOffset;
    int numPolygons;
    int polygonOffset;
    int numPolygonEdges;
    int polygonEdgeOffset;
    int numEdges;
    int edgeOffset;
    int numVertices;
    int vertexOffset;
    int numPolytopes;
    int polytopeOffset;
    int numPolytopePlanes;
    int polytopePlaneOffset;
    int pad;
};

struct cm_subModel_t {
    cm_subModelHeader_t header;
    cm_subModelData_t* data;
    int fileOffset;
    int numUsers;
    volatile std::uint8_t* state;
};

struct cm_polygonModel_t {
    int numModelTreeNodes;
    int numSubModels;
    cm_modelTreeNode_t* modelTreeNodes;
    cm_subModel_t* subModels;
    volatile std::uint8_t* subModelState;
};

struct cm_sphereModel_t {
    std::uint32_t totalSize;
    std::uint32_t timeStamp;
    idBounds bounds;
    std::uint32_t contents;
    std::uint16_t numModelJoints;
    std::uint16_t numSpheres;
    std::uint16_t jointOffset;
    std::uint16_t offsetXOffset;
    std::uint16_t offsetYOffset;
    std::uint16_t offsetZOffset;
    std::uint16_t radiusOffset;
    std::uint16_t surfTypeOffset;
};

struct cm_sphereModelPtrs_t {
    std::uint8_t* joint;
    float* offsetX;
    float* offsetY;
    float* offsetZ;
    float* radius;
    std::uint8_t* surfType;
};

struct streamAreasHeader_t {
    int totalSize;
    int numStreamAreas;
    int numStreamAreaSubModels;
    int numStreamAreaNameBytes;
};

struct streamArea_t {
    int volumeNameOffset;
    idVec3 volumeOrigin;
    idMat3 volumeAxis;
    int numSubModels;
    int subModelsOffset;
};

struct streamAreasPtrs_t {
    streamArea_t* streamAreas;
    std::uint16_t* streamAreaSubModels;
    char* streamAreaNameBytes;
};

void SetupStreamAreaPtrs(streamAreasHeader_t* header,
    streamAreasPtrs_t& pointers);
const cm_subModelData_t* AcquireSubModelData(
    const cm_subModel_t& subModel);
void ReleaseSubModelData(const cm_subModel_t& subModel,
    const cm_subModelData_t* data);

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(cm_node_t) == 16, "Recovered cm_node_t ABI changed");
static_assert(sizeof(cm_material_t) == 16,
    "Recovered cm_material_t ABI changed");
static_assert(sizeof(cm_polygon_t) == 16,
    "Recovered cm_polygon_t ABI changed");
static_assert(sizeof(cm_edge_t) == 4, "Recovered cm_edge_t ABI changed");
static_assert(sizeof(cm_vertex_t) == 16,
    "Recovered cm_vertex_t ABI changed");
static_assert(sizeof(cm_polytope_t) == 16,
    "Recovered cm_polytope_t ABI changed");
static_assert(sizeof(cm_subModelPtrs_t) == 40,
    "Recovered cm_subModelPtrs_t ABI changed");
static_assert(sizeof(cm_modelTreeNode_t) == 16,
    "Recovered cm_modelTreeNode_t ABI changed");
static_assert(sizeof(cm_subModelHeader_t) == 32,
    "Recovered cm_subModelHeader_t ABI changed");
static_assert(sizeof(cm_subModelData_t) == 112,
    "Recovered cm_subModelData_t ABI changed");
static_assert(sizeof(cm_subModel_t) == 48,
    "Recovered cm_subModel_t ABI changed");
static_assert(sizeof(cm_polygonModel_t) == 20,
    "Recovered cm_polygonModel_t ABI changed");
static_assert(sizeof(cm_sphereModel_t) == 52,
    "Recovered cm_sphereModel_t ABI changed");
static_assert(sizeof(cm_sphereModelPtrs_t) == 24,
    "Recovered cm_sphereModelPtrs_t ABI changed");
static_assert(sizeof(streamAreasHeader_t) == 16,
    "Recovered streamAreasHeader_t ABI changed");
static_assert(sizeof(streamArea_t) == 60,
    "Recovered streamArea_t ABI changed");
static_assert(sizeof(streamAreasPtrs_t) == 12,
    "Recovered streamAreasPtrs_t ABI changed");
#endif
