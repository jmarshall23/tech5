#include "cm/jobs/polygonmodel/polygonmodel.h"

#include "cm/jobs/polygonmodel/polygonmodeldata.h"
#include "idlib/geometry/tracemodel.h"

#include <algorithm>
#include <cmath>
#include <cstring>

namespace {

idVec3 ModelToWorldVector(const idMat3& axis, const idVec3& value) {
    return idVec3(
        axis[0].x * value.x + axis[1].x * value.y + axis[2].x * value.z,
        axis[0].y * value.x + axis[1].y * value.y + axis[2].y * value.z,
        axis[0].z * value.x + axis[1].z * value.y + axis[2].z * value.z);
}

bool TestAndSet(std::uint8_t* bits, const int index) {
    if (bits == nullptr) {
        return false;
    }
    const std::uint8_t mask = static_cast<std::uint8_t>(1u << (index & 7));
    std::uint8_t& value = bits[index >> 3];
    const bool old = (value & mask) != 0;
    value = static_cast<std::uint8_t>(value | mask);
    return old;
}

} // namespace

int idPolygonModelCollisionDetection::ClipInPlace(idVec5* const points,
    const int numPoints, const idPlane& plane, const float epsilon,
    const bool keepOn) {
    if (points == nullptr || numPoints <= 0) {
        return 0;
    }
    idVec5 clipped[64];
    int clippedCount = 0;
    idVec5 previous = points[numPoints - 1];
    float previousDistance = plane.a * previous.x + plane.b * previous.y
        + plane.c * previous.z + plane.d;
    bool previousInside = keepOn
        ? previousDistance <= epsilon : previousDistance < -epsilon;
    for (int index = 0; index < numPoints; ++index) {
        const idVec5 current = points[index];
        const float currentDistance = plane.a * current.x
            + plane.b * current.y + plane.c * current.z + plane.d;
        const bool currentInside = keepOn
            ? currentDistance <= epsilon : currentDistance < -epsilon;
        if (currentInside != previousInside && clippedCount < 64) {
            const float denominator = previousDistance - currentDistance;
            const float fraction = std::fabs(denominator) > 1.0e-20f
                ? previousDistance / denominator : 0.0f;
            idVec5& intersection = clipped[clippedCount++];
            for (int component = 0; component < 5; ++component) {
                intersection[component] = previous[component]
                    + (current[component] - previous[component]) * fraction;
            }
        }
        if (currentInside && clippedCount < 64) {
            clipped[clippedCount++] = current;
        }
        previous = current;
        previousDistance = currentDistance;
        previousInside = currentInside;
    }
    std::memcpy(points, clipped,
        static_cast<std::size_t>(clippedCount) * sizeof(idVec5));
    return clippedCount;
}

bool idPolygonModelCollisionDetection::ClipPolygonWithTrm(
    idTraceWork* const tw, const int polygonNum) {
    if (tw->clipResult == nullptr
        || TestAndSet(tw->modelCheckCounts.polygonCheckCounts, polygonNum)) {
        return false;
    }
    const cm_polygon_t& polygon = tw->subModelPtrs.polygons[polygonNum];
    const cm_material_t& material = tw->subModelPtrs.materials[polygon.material];
    if ((material.contentFlags & tw->contents) == 0
        || !tw->traceBoundsShort.IntersectsBounds(polygon.bounds)) {
        return false;
    }

    idVec5 points[64];
    int numPoints = 0;
    for (int edgeNumber = 0;
         edgeNumber < polygon.numEdges && numPoints < 64; ++edgeNumber) {
        const std::uint16_t reference = tw->subModelPtrs.polygonEdges[
            polygon.firstEdge + edgeNumber];
        const cm_edge_t& edge = tw->subModelPtrs.edges[CM_EdgeIndex(reference)];
        const cm_vertex_t& vertex = tw->subModelPtrs.vertices[
            CM_EdgeStartVertex(edge, reference)];
        points[numPoints++] = idVec5(vertex.p.x, vertex.p.y, vertex.p.z,
            static_cast<float>(vertex.st[0]),
            static_cast<float>(vertex.st[1]));
    }
    for (unsigned int planeNumber = 0;
         planeNumber < tw->numPolys && numPoints >= 3; ++planeNumber) {
        numPoints = ClipInPlace(points, numPoints,
            tw->polys[planeNumber].plane, 0.01f, true);
    }
    if (numPoints < 3) {
        return false;
    }

    clipResult_t& result = *tw->clipResult;
    const int availableVerts = 32 - result.numVerts;
    numPoints = (std::min)(numPoints, availableVerts);
    if (numPoints < 3) {
        return true;
    }
    const int firstVertex = result.numVerts;
    for (int index = 0; index < numPoints; ++index) {
        result.verts[result.numVerts++].Set(
            points[index].x, points[index].y, points[index].z);
    }
    for (int index = 1; index + 1 < numPoints
        && result.numIndices + 3 <= 264; ++index) {
        result.indices[result.numIndices++] =
            static_cast<std::int16_t>(firstVertex);
        result.indices[result.numIndices++] =
            static_cast<std::int16_t>(firstVertex + index);
        result.indices[result.numIndices++] =
            static_cast<std::int16_t>(firstVertex + index + 1);
    }
    return result.numVerts >= 32 || result.numIndices >= 264;
}

void idPolygonModelCollisionDetection::StartClip(idTraceWork* const tw,
    clipResult_t* const result, const idVec3& start,
    const idTraceModel& trm, const idMat3& trmAxis, const int contentMask,
    const idVec3& modelOrigin, const idMat3& modelAxis) {
    StartContents(tw, &tw->tempTraceResult, start, &trm, trmAxis,
        contentMask, modelOrigin, modelAxis);
    tw->traceType = TRACE_CLIP;
    tw->traceResult = nullptr;
    tw->clipResult = result;
    tw->contactsResult = nullptr;
    result->numVerts = 0;
    result->numIndices = 0;
}

void idPolygonModelCollisionDetection::FinishClip(idTraceWork* const tw,
    const int firstClipVert, const idVec3& modelOrigin,
    const idMat3& modelAxis) {
    if (tw->clipResult == nullptr) {
        return;
    }
    clipResult_t& result = *tw->clipResult;
    for (int index = (std::max)(0, firstClipVert);
         index < result.numVerts; ++index) {
        result.verts[index] = ModelToWorldVector(modelAxis,
            result.verts[index]) + modelOrigin;
    }
}
