#pragma once

#include "cm/collisiontypes.h"
#include "cm/jobs/collisionquery.h"
#include "idlib/math/mat3x4.h"
#include "idlib/math/pluecker.h"

#include <cstddef>
#include <cstdint>

class idTraceModel;

struct cm_sideCache_t {
    std::uint32_t side;
};

struct cm_trmVertex_t {
    idBoundsShort bounds;
    int pad;
};

struct cm_trmEdge_t {
    idBoundsShort bounds;
    std::uint16_t vertexNum[2];
};

struct cm_trmPolygon_t {
    idPlane plane;
    idBoundsShort bounds;
    std::uint32_t numEdges;
    std::uint8_t edges[16];
    std::uint32_t vertexSideMask;
    std::uint32_t vertexSideBits;
    std::uint32_t pad[2];
};

struct idModelCheckCounts {
    std::uint8_t baseCheckCounts[928];
    std::uint8_t checkCount;
    std::uint8_t* vertexCheckCounts;
    std::uint8_t* edgeCheckCounts;
    std::uint8_t* polygonCheckCounts;
    std::uint8_t* polytopeCheckCounts;

    void SetupForSubModel(const cm_subModelData_t* subModelData);
};

struct idTraceWork {
    cm_trmVertex_t verts[32];
    cm_trmEdge_t edges[32];
    cm_trmPolygon_t polys[16];
    idVec4 vertexPosition[32];
    idVec4 vertexEndPosition[32];
    idPluecker vertexPluecker[32];
    idPluecker edgePluecker[32];
    idPluecker edgeZAxisPluecker[32];
    idVec4 edgeNormal[32];
    std::uint8_t vertIsUsed[32];
    std::uint8_t edgeIsUsed[32];
    std::uint8_t polyIsUsed[16];
    std::uint32_t numVerts;
    std::uint32_t numEdges;
    std::uint32_t numPolys;
    int contents;
    idVec4 start;
    idVec4 end;
    idVec4 dir;
    idVec4 negDir;
    idMat3x4 trmTransform;
    idVec4 trmBoundsMin;
    idVec4 trmBoundsMax;
    idVec4 trmExtents;
    idVec4 traceBoundsMin;
    idVec4 traceBoundsMax;
    idBoundsShort traceBoundsShort;
    int pad;
    idPlane heartPlane1;
    idPlane heartPlane2;
    float maxDistFromHeartPlane1;
    float maxDistFromHeartPlane2;
    float fraction;
    int subModelNum;
    float angle;
    float negAngle;
    float maxTan;
    float initialTan;
    idVec4 origin;
    idVec4 axis;
    idMat3x4 ZAxisTransform;
    idMat3x4 endTransform;
    float contactDepth;
    traceType_t traceType;
    bool isConvex;
    bool quickExit;
    cm_sideCache_t polygonSideCache;
    cm_sideCache_t polygonEdgeSideCache[20];
    cm_sideCache_t polygonVertexSideCache[20];
    idPluecker polygonEdgePlueckerCache[16];
    idPluecker polygonVertexPlueckerCache[16];
    std::uint8_t subModelDataForBounds[768];
    idModelCheckCounts modelCheckCounts;
    cm_subModelPtrs_t subModelPtrs;
    trace_t* traceResult;
    contactsResult_t* contactsResult;
    clipResult_t* clipResult;
    trace_t tempTraceResult;
    int profile[5];

    void Init();
};

class idPolygonModelCollisionDetection {
public:
    static void SetupSubModelPtrsFromData(cm_subModelPtrs_t& pointers,
        const cm_subModelData_t* data);
    static idTraceWork* AllocTraceWork();
    static int GetTraceWorkSPUSize();

    static cm_subModelData_t* SetupSubModelForBounds(cm_subModelData_t* data,
        int size, const idBounds& bounds);
    static bool TestStuckInSubModelBounds(idTraceWork* tw,
        const idBounds& subModelBounds);
    static idVec3 LocalExtentsFromUnTransformedBounds(
        const idBounds& globalBounds, const idVec3& globalStart,
        const idVec3& globalEnd, const idMat3& modelAxis);
    static void TraceThroughSubModelTree(idTraceWork* tw);
    static void TraceThroughSubModel(idTraceWork* tw,
        const cm_subModelData_t* subModelData, int subModelNum);
    static unsigned int GetSubModelsForTrace(const cm_polygonModel_t& model,
        const idVec3& start, const idVec3& end, const idVec3& extents,
        int* subModelNums);
    static void TraceThroughModel(idTraceWork* tw,
        const cm_polygonModel_t& model);

    static bool TestTrmVertsInPolytope(idTraceWork* tw, int polytopeNum);
    static bool TestTrmInPolygon(idTraceWork* tw, int polygonNum);
    static void StartContents(idTraceWork* tw, trace_t* result,
        const idVec3& start, const idTraceModel* trm,
        const idMat3& trmAxis, int contentMask,
        const idVec3& modelOrigin, const idMat3& modelAxis);
    static void StartContentsPoint(idTraceWork* tw, trace_t* result,
        const idVec3& start, int contentMask,
        const idVec3& modelOrigin, const idMat3& modelAxis);
    static void FinishContents(idTraceWork* tw, const idVec3& modelOrigin,
        const idMat3& modelAxis, int modelEntityNum, int modelPhysicsId,
        int modelBodyId, int selfId, int modelContentsOverride);

    static void TranslationSetup(idTraceWork* tw, const idVec3& start,
        const idVec3& end, const idVec3& offset, const idMat3& trmAxis,
        const idVec3& modelOrigin, const idMat3& modelAxis);
    static void TranslationUsedPrimitives(idTraceWork* tw,
        const idVec3& start, const idVec3& end, const idTraceModel& trm,
        const idMat3& trmAxis);
    static void TranslationHeartPlanes(idTraceWork* tw);
    static void TranslationVerts(idTraceWork* tw, const idTraceModel& trm);
    static void TranslationEdges(idTraceWork* tw, const idTraceModel& trm);
    static void TranslationPolys(idTraceWork* tw, const idTraceModel& trm);
    static void TranslationBounds(idTraceWork* tw);
    static void TranslationUpdateBounds(idTraceWork* tw);
    static void TranslationPlueckerCache(idTraceWork* tw,
        const cm_polygon_t& polygon);
    static void TranslationEdgePlueckerCache(idTraceWork* tw,
        const cm_polygon_t& polygon);
    static void TranslationSideCache(const idPluecker* pluecker,
        const std::uint8_t* used, unsigned int count,
        const idPluecker* plueckerCache, cm_sideCache_t* sideCache,
        unsigned int cacheSize);
    static void TranslationPolygonSideCache(idTraceWork* tw,
        const cm_polygon_t& polygon);
    static void AddContact(idTraceWork* tw);
    static float TranslateEdgeThroughEdge(const idPluecker& first,
        const idPluecker& second, const idVec3& direction);
    static int TranslateTrmEdgesThroughPolygon(idTraceWork* tw,
        const cm_polygon_t& polygon);
    static float TranslatePointThroughPlane(const idPlane& plane,
        const idVec3& start, const idVec3& end);
    static int TranslateTrmVertsThroughPolygon(idTraceWork* tw,
        const cm_polygon_t& polygon, const idPlane& polygonPlane);
    static int TranslatePolygonVertsThroughTrm(idTraceWork* tw,
        const cm_polygon_t& polygon);
    static int TranslateTrmThroughPolygon(idTraceWork* tw, int polygonNum);
    static int TranslatePointThroughPolygon(idTraceWork* tw, int polygonNum);
    static int StartTranslation(idTraceWork* tw, trace_t* result,
        contactsResult_t* contacts, const idVec3& start, const idVec3& end,
        const idTraceModel* trm, const idMat3& trmAxis, int contentMask,
        const idVec3& modelOrigin, const idMat3& modelAxis);
    static int StartTranslationPoint(idTraceWork* tw, trace_t* result,
        const idVec3& start, const idVec3& end, int contentMask,
        const idVec3& modelOrigin, const idMat3& modelAxis);
    static void FinishTranslation(idTraceWork* tw, const idVec3& start,
        const idVec3& end, const idVec3& modelOrigin,
        const idMat3& modelAxis, int modelEntityNum, int modelPhysicsId,
        int modelBodyId, int selfId, int modelContentsOverride);

    static int ClipInPlace(idVec5* points, int numPoints,
        const idPlane& plane, float epsilon, bool keepOn);
    static bool ClipPolygonWithTrm(idTraceWork* tw, int polygonNum);
    static void StartClip(idTraceWork* tw, clipResult_t* result,
        const idVec3& start, const idTraceModel& trm,
        const idMat3& trmAxis, int contentMask,
        const idVec3& modelOrigin, const idMat3& modelAxis);
    static void FinishClip(idTraceWork* tw, int firstClipVert,
        const idVec3& modelOrigin, const idMat3& modelAxis);

    static void TestTrmEdgeInContactWithPolygon(idTraceWork* tw,
        const cm_polygon_t& polygon, int trmEdgeNum);
    static void TestTrmVertexInContactWithPolygon(idTraceWork* tw,
        const cm_polygon_t& polygon, const idPlane& polygonPlane,
        int trmVertNum);
    static void TestVertexInContactWithTrmPolygon(idTraceWork* tw,
        const cm_trmPolygon_t& trmPolygon, const cm_polygon_t& polygon,
        const cm_vertex_t& vertex);
    static bool TestTrmInContactWithPolygon(idTraceWork* tw,
        int polygonNum);
    static void StartContacts(idTraceWork* tw, contactsResult_t* result,
        const idVec3& start, const idVec3& direction, float depth,
        const idTraceModel& trm, const idMat3& trmAxis, int contentMask,
        const idVec3& modelOrigin, const idMat3& modelAxis);
    static void FinishContacts(idTraceWork* tw, int firstContact,
        const idVec3& modelOrigin, const idMat3& modelAxis,
        int modelEntityNum, int modelPhysicsId, int modelBodyId, int selfId,
        int modelContentsOverride);

    static bool EdgeIntersectsBoundsShort(const idBoundsShort& bounds,
        const idVec3& start, const idVec3& end);
    static void RotationSetup(idTraceWork* tw, const idVec3& rotationOrigin,
        const idVec3& rotationAxis, float angle, const idVec3& start,
        const idVec3& offset, const idMat3& trmAxis,
        const idVec3& modelOrigin, const idMat3& modelAxis);
    static void TransformFromOriginAxisAngle(idMat3x4& transform,
        const idVec3& origin, const idVec3& axis, float angle);
    static void TransformAxisToZAxis(idMat3x4& transform,
        const idVec3& origin, const idVec3& axis);
    static void RotationVerts(idTraceWork* tw, const idTraceModel& trm,
        idVec4* zverts);
    static void RotationEdges(idTraceWork* tw, const idTraceModel& trm,
        const idVec4* zverts);
    static void RotationPolys(idTraceWork* tw, const idTraceModel& trm);
    static void RotationBounds(idTraceWork* tw);
    static void RotationEdgePlueckerCache(idTraceWork* tw,
        const cm_polygon_t& polygon);
    static void RotationCullPolygonEdges(idTraceWork* tw,
        const cm_polygon_t& polygon);
    static int CollisionBetweenEdgeBounds(const idTraceWork& tw,
        const idVec3& firstStart, const idVec3& firstEnd,
        const idVec3& secondStart, const idVec3& secondEnd,
        float tanHalfAngle, idVec3& collisionPoint,
        idVec3& collisionNormal);
    static int RotateEdgeThroughEdge(const idPluecker& first,
        const idPluecker& second, float angle, float minTan, float maxTan,
        float& tanHalfAngle);
    static int EdgeFurthestFromEdge(const idPluecker& first,
        const idPluecker& second, float angle, float& tanHalfAngle,
        float& direction);
    static int RotateTrmEdgesThroughPolygon(idTraceWork* tw,
        const cm_polygon_t& polygon);
    static int RotatePointThroughPlane(const idVec3& point,
        const idPlane& plane, float angle, float minTan, float maxTan,
        float& tanHalfAngle);
    static int PointFurthestFromPlane(const idVec3& point,
        const idPlane& plane, float angle, float& tanHalfAngle,
        float& direction);
    static int RotatePointThroughEpsilonPlane(const idTraceWork& tw,
        const idVec3& point, const idVec3& endPoint, const idPlane& plane,
        float angle, const idVec3& rotationOrigin, float& tanHalfAngle,
        idVec3& collisionPoint, idVec3& endDirection);
    static int RotateTrmVertsThroughPolygon(idTraceWork* tw,
        const cm_polygon_t& polygon, const idPlane& polygonPlane);
    static int RotatePolygonVertsThroughTrm(idTraceWork* tw,
        const cm_polygon_t& polygon);
    static bool RotateTrmThroughPolygon(idTraceWork* tw, int polygonNum);
    static int StartRotation(idTraceWork* tw, trace_t* result,
        const idVec3& rotationOrigin, const idVec3& rotationAxis,
        float angle, const idVec3& start, const idTraceModel* trm,
        const idMat3& trmAxis, int contentMask,
        const idVec3& modelOrigin, const idMat3& modelAxis);
    static int StartRotationPoint(idTraceWork* tw, trace_t* result,
        const idVec3& rotationOrigin, const idVec3& rotationAxis,
        float angle, const idVec3& start, int contentMask,
        const idVec3& modelOrigin, const idMat3& modelAxis);
    static void FinishRotation(idTraceWork* tw,
        const idVec3& rotationOrigin, const idVec3& rotationAxis,
        float angle, const idVec3& start, const idMat3& trmAxis,
        const idVec3& modelOrigin, const idMat3& modelAxis,
        int modelEntityNum, int modelPhysicsId, int modelBodyId, int selfId,
        int modelContentsOverride);
};

float CM_TanZeroHalfPI(float angle);
float CM_ArcTanPositive(float value);
void CM_PointRotationBounds(const idVec3& origin, const idVec3& axis,
    const idVec3& start, const idVec3& end,
    idVec4& boundsMin, idVec4& boundsMax);

static_assert(sizeof(cm_sideCache_t) == 4,
    "Recovered cm_sideCache_t ABI changed");
static_assert(sizeof(cm_trmVertex_t) == 16,
    "Recovered cm_trmVertex_t ABI changed");
static_assert(sizeof(cm_trmEdge_t) == 16,
    "Recovered cm_trmEdge_t ABI changed");
static_assert(sizeof(cm_trmPolygon_t) == 64,
    "Recovered cm_trmPolygon_t ABI changed");

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idModelCheckCounts) == 948,
    "Recovered idModelCheckCounts ABI changed");
static_assert(sizeof(idTraceWork) == 9244,
    "Recovered idTraceWork ABI changed");
#endif
