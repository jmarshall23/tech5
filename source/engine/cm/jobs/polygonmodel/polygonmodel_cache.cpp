#include "cm/jobs/polygonmodel/polygonmodel.h"

#include "idlib/sys/sys_alloc.h"

#include <algorithm>
#include <cstring>
#include <new>

namespace {

std::size_t CheckCountBytes(const int count) {
    return static_cast<std::size_t>((count + 7) & ~7) >> 3;
}

template <typename T, std::size_t Count>
void ClearArray(T (&values)[Count]) {
    std::memset(values, 0, sizeof(values));
}

void ClearMatrix(idMat3x4& matrix) {
    std::fill(matrix.mat, matrix.mat + 12, 0.0f);
}

void ClearVector(idVec4& vector) {
    vector.Set(0.0f, 0.0f, 0.0f, 0.0f);
}

void ClearPlane(idPlane& plane) {
    plane.a = 0.0f;
    plane.b = 0.0f;
    plane.c = 0.0f;
    plane.d = 0.0f;
}

} // namespace

void idModelCheckCounts::SetupForSubModel(
    const cm_subModelData_t* const subModelData) {
    vertexCheckCounts = baseCheckCounts;
    edgeCheckCounts = vertexCheckCounts +
        CheckCountBytes(subModelData->numVertices);
    polygonCheckCounts = edgeCheckCounts +
        CheckCountBytes(subModelData->numEdges);
    polytopeCheckCounts = polygonCheckCounts +
        CheckCountBytes(subModelData->numPolygons);

    const std::size_t usedBytes = CheckCountBytes(subModelData->numVertices) +
        CheckCountBytes(subModelData->numEdges) +
        CheckCountBytes(subModelData->numPolygons) +
        CheckCountBytes(subModelData->numPolytopes);
    const std::size_t alignedBytes = (usedBytes + 15u) & ~std::size_t(15u);
    std::memset(baseCheckCounts, 0, alignedBytes);
}

void idTraceWork::Init() {
    numVerts = 0;
    numEdges = 0;
    numPolys = 0;
    contents = 0;
    ClearVector(start);
    ClearVector(end);
    ClearVector(dir);
    ClearVector(negDir);
    ClearMatrix(trmTransform);
    ClearVector(trmBoundsMin);
    ClearVector(trmBoundsMax);
    ClearVector(trmExtents);
    ClearVector(traceBoundsMin);
    ClearVector(traceBoundsMax);
    std::memset(&traceBoundsShort, 0, sizeof(traceBoundsShort));
    pad = 0;
    ClearPlane(heartPlane1);
    ClearPlane(heartPlane2);
    maxDistFromHeartPlane1 = 0.0f;
    maxDistFromHeartPlane2 = 0.0f;
    fraction = 0.0f;
    subModelNum = 0;
    angle = 0.0f;
    negAngle = 0.0f;
    maxTan = 0.0f;
    initialTan = 0.0f;
    ClearVector(origin);
    ClearVector(axis);
    ClearMatrix(ZAxisTransform);
    ClearMatrix(endTransform);
    contactDepth = 0.0f;
    traceType = TRACE_TRANSLATION;
    isConvex = false;
    quickExit = false;
    polygonSideCache.side = 0;

    std::memset(modelCheckCounts.baseCheckCounts, 0,
        sizeof(modelCheckCounts.baseCheckCounts));
    modelCheckCounts.checkCount = 0;
    modelCheckCounts.vertexCheckCounts = nullptr;
    modelCheckCounts.edgeCheckCounts = nullptr;
    modelCheckCounts.polygonCheckCounts = nullptr;
    modelCheckCounts.polytopeCheckCounts = nullptr;
    traceResult = nullptr;
    contactsResult = nullptr;
    clipResult = nullptr;

    ClearArray(verts);
    ClearArray(edges);
    ClearArray(polys);
    ClearArray(vertexPosition);
    ClearArray(vertexEndPosition);
    ClearArray(vertexPluecker);
    ClearArray(edgePluecker);
    ClearArray(edgeZAxisPluecker);
    ClearArray(edgeNormal);
    ClearArray(vertIsUsed);
    ClearArray(edgeIsUsed);
    ClearArray(polyIsUsed);
    ClearArray(polygonEdgeSideCache);
    ClearArray(polygonVertexSideCache);
    ClearArray(polygonEdgePlueckerCache);
    ClearArray(polygonVertexPlueckerCache);
    std::memset(&subModelPtrs, 0, sizeof(subModelPtrs));
    ClearArray(profile);
}

idTraceWork* idPolygonModelCollisionDetection::AllocTraceWork() {
    void* const memory = mem.AllocWithLocation(
        "engine/cm/jobs/polygonmodel/polygonmodel_cache.cpp : TAG_COLLISION",
        static_cast<unsigned int>(sizeof(idTraceWork)), TAG_COLLISION, false,
        ALIGN_16, HEAP_DEFAULTHEAP);
    idTraceWork* const traceWork = new (memory) idTraceWork;
    traceWork->Init();
    return traceWork;
}

int idPolygonModelCollisionDetection::GetTraceWorkSPUSize() {
    return 9244;
}
