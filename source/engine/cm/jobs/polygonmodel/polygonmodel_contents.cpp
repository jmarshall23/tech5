#include "cm/jobs/polygonmodel/polygonmodel.h"

#include "cm/jobs/polygonmodel/polygonmodeldata.h"
#include "idlib/geometry/tracemodel.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>

namespace {

constexpr float CM_BOUNDS_EPSILON = 1.0f;
constexpr float CM_PLANE_EPSILON = 0.0001f;

idVec3 Vec3(const idVec4& value) {
    return idVec3(value.x, value.y, value.z);
}

void SetVec4(idVec4& target, const idVec3& value, const float w = 0.0f) {
    target.Set(value.x, value.y, value.z, w);
}

idVec3 ModelToWorldVector(const idMat3& axis, const idVec3& value) {
    return idVec3(
        axis[0].x * value.x + axis[1].x * value.y + axis[2].x * value.z,
        axis[0].y * value.x + axis[1].y * value.y + axis[2].y * value.z,
        axis[0].z * value.x + axis[1].z * value.y + axis[2].z * value.z);
}

idVec3 WorldToModelVector(const idMat3& axis, const idVec3& value) {
    return idVec3(axis[0].Dot(value), axis[1].Dot(value),
        axis[2].Dot(value));
}

idVec3 TraceModelToWorldVector(const idMat3& axis, const idVec3& value) {
    return ModelToWorldVector(axis, value);
}

bool IsIdentity(const idMat3& axis) {
    return axis[0].x == 1.0f && axis[1].y == 1.0f
        && axis[2].z == 1.0f
        && axis[0].y == 0.0f && axis[0].z == 0.0f
        && axis[1].x == 0.0f && axis[1].z == 0.0f
        && axis[2].x == 0.0f && axis[2].y == 0.0f;
}

bool BoundsIntersect(const idBoundsShort& lhs, const idBoundsShort& rhs) {
    return lhs.IntersectsBounds(rhs);
}

bool TestAndSet(std::uint8_t* bits, const int index) {
    if (bits == nullptr || index < 0) {
        return false;
    }
    const std::uint8_t mask = static_cast<std::uint8_t>(1u << (index & 7));
    std::uint8_t& value = bits[index >> 3];
    const bool wasSet = (value & mask) != 0;
    value = static_cast<std::uint8_t>(value | mask);
    return wasSet;
}

void SetMaterial(contactInfo_t& contact, const cm_material_t& material) {
    contact.contentFlags = material.contentFlags;
    contact.surfaceFlags = material.surfaceFlags;
    contact.surfaceType = material.surfaceType;
    contact.surfaceColor[0] = material.surfaceColor[0];
    contact.surfaceColor[1] = material.surfaceColor[1];
    contact.surfaceColor[2] = material.surfaceColor[2];
}

bool PointInsidePolygon(const cm_subModelPtrs_t& model,
    const cm_polygon_t& polygon, const idPlane& plane, const idVec3& point) {
    bool hasPositive = false;
    bool hasNegative = false;
    const idVec3 normal = plane.Normal();
    for (int edgeNumber = 0; edgeNumber < polygon.numEdges; ++edgeNumber) {
        const std::uint16_t edgeReference =
            model.polygonEdges[polygon.firstEdge + edgeNumber];
        const cm_edge_t& edge = model.edges[CM_EdgeIndex(edgeReference)];
        const idVec3& start = model.vertices[
            CM_EdgeStartVertex(edge, edgeReference)].p;
        const idVec3& end = model.vertices[
            CM_EdgeEndVertex(edge, edgeReference)].p;
        const float side = (end - start).Cross(point - start).Dot(normal);
        hasPositive |= side > CM_PLANE_EPSILON;
        hasNegative |= side < -CM_PLANE_EPSILON;
        if (hasPositive && hasNegative) {
            return false;
        }
    }
    return true;
}

bool PointInsideTraceModel(const idTraceWork& tw, const idVec3& point,
    int& nearestPolygon) {
    float nearestDistance = -std::numeric_limits<float>::max();
    nearestPolygon = 0;
    for (unsigned int polygonNumber = 0;
         polygonNumber < tw.numPolys; ++polygonNumber) {
        const float distance = tw.polys[polygonNumber].plane.Distance(point);
        if (distance >= 0.0f) {
            return false;
        }
        if (distance > nearestDistance) {
            nearestDistance = distance;
            nearestPolygon = static_cast<int>(polygonNumber);
        }
    }
    return tw.numPolys != 0;
}

void MakeTraceBounds(idTraceWork& tw, const idVec3& minimum,
    const idVec3& maximum, const bool padBounds) {
    const float padding = padBounds ? CM_BOUNDS_EPSILON : 0.0f;
    tw.traceBoundsMin.Set(minimum.x - padding, minimum.y - padding,
        minimum.z - padding, 0.0f);
    tw.traceBoundsMax.Set(maximum.x + padding, maximum.y + padding,
        maximum.z + padding, 0.0f);
    idBounds quantized;
    quantized[0].Set(std::floor(tw.traceBoundsMin.x) - 1.0f,
        std::floor(tw.traceBoundsMin.y) - 1.0f,
        std::floor(tw.traceBoundsMin.z) - 1.0f);
    quantized[1].Set(std::ceil(tw.traceBoundsMax.x) + 1.0f,
        std::ceil(tw.traceBoundsMax.y) + 1.0f,
        std::ceil(tw.traceBoundsMax.z) + 1.0f);
    tw.traceBoundsShort.SetBounds(quantized);
}

void SetPolygonContact(idTraceWork& tw, const cm_polygon_t& polygon,
    const int polygonNum, const int trmVertex, const idVec3& point,
    const idPlane& plane) {
    trace_t& trace = *tw.traceResult;
    trace.fraction = 0.0f;
    trace.c.type = CONTACT_TRMVERTEX;
    trace.c.point = point;
    trace.c.normal = plane.Normal();
    trace.c.dist = plane.Dist();
    trace.c.separation = 0.0f;
    SetMaterial(trace.c, tw.subModelPtrs.materials[polygon.material]);
    trace.c.modelFeature = ((tw.subModelNum << 16) & 0x1FFF0000)
        | 0x60000000 | polygonNum;
    trace.c.trmFeature = trmVertex;
    trace.c.flags = 0;
}

} // namespace

bool idPolygonModelCollisionDetection::TestTrmVertsInPolytope(
    idTraceWork* const tw, const int polytopeNum) {
    if (TestAndSet(tw->modelCheckCounts.polytopeCheckCounts, polytopeNum)) {
        return false;
    }

    const cm_polytope_t& polytope = tw->subModelPtrs.polytopes[polytopeNum];
    const cm_material_t& material =
        tw->subModelPtrs.materials[polytope.material];
    if ((material.contentFlags & tw->contents) == 0
        || !BoundsIntersect(tw->traceBoundsShort, polytope.bounds)) {
        return false;
    }

    for (unsigned int vertexNumber = 0;
         vertexNumber < tw->numVerts; ++vertexNumber) {
        const idVec3 vertex = Vec3(tw->vertexPosition[vertexNumber]);
        float nearestDistance = -std::numeric_limits<float>::max();
        int nearestPlane = 0;
        bool inside = true;
        for (int planeNumber = 0;
             planeNumber < polytope.numPlanes; ++planeNumber) {
            const idPlane& plane = tw->subModelPtrs.polytopePlanes[
                polytope.firstPlane + planeNumber];
            const float distance = plane.Distance(vertex);
            if (distance >= 0.0f) {
                inside = false;
                break;
            }
            if (distance > nearestDistance) {
                nearestDistance = distance;
                nearestPlane = planeNumber;
            }
        }
        if (!inside) {
            continue;
        }

        trace_t& trace = *tw->traceResult;
        const idPlane& plane = tw->subModelPtrs.polytopePlanes[
            polytope.firstPlane + nearestPlane];
        trace.fraction = 0.0f;
        trace.c.type = CONTACT_TRMVERTEX;
        trace.c.normal = plane.Normal();
        trace.c.dist = plane.Dist();
        trace.c.separation = 0.0f;
        trace.c.point = vertex;
        SetMaterial(trace.c, material);
        trace.c.modelFeature = 0x80000000
            | ((tw->subModelNum << 16) & 0x1FFF0000) | polytopeNum;
        trace.c.trmFeature = static_cast<int>(vertexNumber);
        trace.c.flags = 0;
        return true;
    }
    return false;
}

bool idPolygonModelCollisionDetection::TestTrmInPolygon(
    idTraceWork* const tw, const int polygonNum) {
    if (TestAndSet(tw->modelCheckCounts.polygonCheckCounts, polygonNum)) {
        return false;
    }

    const cm_polygon_t& polygon = tw->subModelPtrs.polygons[polygonNum];
    const cm_material_t& material =
        tw->subModelPtrs.materials[polygon.material];
    if ((material.contentFlags & tw->contents) == 0
        || !BoundsIntersect(tw->traceBoundsShort, polygon.bounds)) {
        return false;
    }

    idPlane polygonPlane;
    CM_GetPolygonPlane(tw->subModelPtrs, polygon, polygonPlane);
    bool hasFront = false;
    bool hasBack = false;
    for (unsigned int vertexNumber = 0;
         vertexNumber < tw->numVerts; ++vertexNumber) {
        const float distance = polygonPlane.Distance(
            Vec3(tw->vertexPosition[vertexNumber]));
        hasFront |= distance > CM_PLANE_EPSILON;
        hasBack |= distance < -CM_PLANE_EPSILON;
    }
    if (!hasBack) {
        if (tw->subModelPtrs.isConvex != 0) {
            // The recovered convex early-out terminates the whole submodel as
            // soon as one separating polygon plane is found.
            tw->quickExit = true;
            return true;
        }
        return false;
    }

    // The authoritative Pluecker tests find the same geometric event: a trace
    // edge crosses the model polygon.  The PC scalar path spells it directly.
    for (unsigned int edgeNumber = 0; edgeNumber < tw->numEdges; ++edgeNumber) {
        const int first = tw->edges[edgeNumber].vertexNum[0];
        const int second = tw->edges[edgeNumber].vertexNum[1];
        const idVec3 firstPoint = Vec3(tw->vertexPosition[first]);
        const idVec3 secondPoint = Vec3(tw->vertexPosition[second]);
        const float firstDistance = polygonPlane.Distance(firstPoint);
        const float secondDistance = polygonPlane.Distance(secondPoint);
        if ((firstDistance < 0.0f) == (secondDistance < 0.0f)) {
            continue;
        }
        const float denominator = firstDistance - secondDistance;
        if (std::fabs(denominator) <= CM_PLANE_EPSILON) {
            continue;
        }
        const float fraction = firstDistance / denominator;
        const idVec3 point = firstPoint + (secondPoint - firstPoint) * fraction;
        if (PointInsidePolygon(tw->subModelPtrs, polygon,
                polygonPlane, point)) {
            const int featureVertex = firstDistance < 0.0f ? first : second;
            SetPolygonContact(*tw, polygon, polygonNum, featureVertex,
                Vec3(tw->vertexPosition[featureVertex]), polygonPlane);
            return true;
        }
    }

    // A model vertex can be embedded in the trace model without an edge-plane
    // crossing (the second recovered contents case).
    for (int edgeNumber = 0; edgeNumber < polygon.numEdges; ++edgeNumber) {
        const std::uint16_t edgeReference =
            tw->subModelPtrs.polygonEdges[polygon.firstEdge + edgeNumber];
        const cm_edge_t& edge =
            tw->subModelPtrs.edges[CM_EdgeIndex(edgeReference)];
        const int vertexNumber = CM_EdgeStartVertex(edge, edgeReference);
        if (TestAndSet(tw->modelCheckCounts.vertexCheckCounts, vertexNumber)) {
            continue;
        }
        const idVec3& point = tw->subModelPtrs.vertices[vertexNumber].p;
        int tracePolygon = 0;
        if (!PointInsideTraceModel(*tw, point, tracePolygon)) {
            continue;
        }

        trace_t& trace = *tw->traceResult;
        const idPlane& plane = tw->polys[tracePolygon].plane;
        trace.fraction = 0.0f;
        trace.c.type = CONTACT_MODELVERTEX;
        trace.c.point = point;
        trace.c.normal = -plane.Normal();
        trace.c.dist = plane.d;
        trace.c.separation = 0.0f;
        SetMaterial(trace.c, material);
        trace.c.modelFeature = ((tw->subModelNum << 16) & 0x1FFF0000)
            | 0x20000000 | vertexNumber;
        trace.c.trmFeature = tracePolygon;
        trace.c.flags = 0;
        return true;
    }
    return false;
}

void idPolygonModelCollisionDetection::StartContents(idTraceWork* const tw,
    trace_t* const result, const idVec3& start, const idTraceModel* const trm,
    const idMat3& trmAxis, const int contentMask,
    const idVec3& modelOrigin, const idMat3& modelAxis) {
    std::memset(result, 0, sizeof(*result));
    result->fraction = 1.0f;
    result->endpos = start;
    result->endAxis = trmAxis;
    tw->traceResult = result;
    tw->contactsResult = nullptr;
    tw->clipResult = nullptr;
    tw->fraction = 1.0f;
    tw->contents = contentMask;
    tw->isConvex = trm->isConvex;
    tw->traceType = TRACE_CONTENTS;
    tw->quickExit = false;

    const idVec3 localStart = WorldToModelVector(modelAxis,
        start + TraceModelToWorldVector(trmAxis, trm->offset) - modelOrigin);
    SetVec4(tw->start, localStart);
    tw->end = tw->start;

    idVec3 minimum(std::numeric_limits<float>::max(),
        std::numeric_limits<float>::max(),
        std::numeric_limits<float>::max());
    idVec3 maximum(-std::numeric_limits<float>::max(),
        -std::numeric_limits<float>::max(),
        -std::numeric_limits<float>::max());
    tw->numVerts = (std::min)(trm->numVerts, 32u);
    for (unsigned int vertexNumber = 0;
         vertexNumber < tw->numVerts; ++vertexNumber) {
        const idVec3 source(trm->vertsX[vertexNumber],
            trm->vertsY[vertexNumber], trm->vertsZ[vertexNumber]);
        const idVec3 world = start + TraceModelToWorldVector(trmAxis, source);
        const idVec3 local = WorldToModelVector(modelAxis,
            world - modelOrigin);
        SetVec4(tw->vertexPosition[vertexNumber], local);
        minimum.x = (std::min)(minimum.x, local.x);
        minimum.y = (std::min)(minimum.y, local.y);
        minimum.z = (std::min)(minimum.z, local.z);
        maximum.x = (std::max)(maximum.x, local.x);
        maximum.y = (std::max)(maximum.y, local.y);
        maximum.z = (std::max)(maximum.z, local.z);
    }
    SetVec4(tw->trmBoundsMin, minimum - localStart);
    SetVec4(tw->trmBoundsMax, maximum - localStart);
    tw->trmExtents.Set(
        (std::max)(std::fabs(tw->trmBoundsMin.x),
            std::fabs(tw->trmBoundsMax.x)),
        (std::max)(std::fabs(tw->trmBoundsMin.y),
            std::fabs(tw->trmBoundsMax.y)),
        (std::max)(std::fabs(tw->trmBoundsMin.z),
            std::fabs(tw->trmBoundsMax.z)), 0.0f);

    tw->numEdges = (std::min)(trm->numEdges, 32u);
    for (unsigned int edgeNumber = 0;
         edgeNumber < tw->numEdges; ++edgeNumber) {
        tw->edges[edgeNumber].vertexNum[0] = trm->edges[edgeNumber].v[0];
        tw->edges[edgeNumber].vertexNum[1] = trm->edges[edgeNumber].v[1];
        const idVec3 first = Vec3(tw->vertexPosition[
            tw->edges[edgeNumber].vertexNum[0]]);
        const idVec3 second = Vec3(tw->vertexPosition[
            tw->edges[edgeNumber].vertexNum[1]]);
        tw->edgePluecker[edgeNumber].FromLine(first, second);
    }

    tw->numPolys = (std::min)(trm->numPolys, 16u);
    for (unsigned int polygonNumber = 0;
         polygonNumber < tw->numPolys; ++polygonNumber) {
        cm_trmPolygon_t& polygon = tw->polys[polygonNumber];
        polygon.numEdges = (std::min)(trm->numPolyEdges[polygonNumber], 16u);
        std::memcpy(polygon.edges, trm->polyEdges[polygonNumber],
            polygon.numEdges);
        const idVec3 sourceNormal(trm->polyPlaneX[polygonNumber],
            trm->polyPlaneY[polygonNumber], trm->polyPlaneZ[polygonNumber]);
        idVec3 localNormal = WorldToModelVector(modelAxis,
            TraceModelToWorldVector(trmAxis, sourceNormal));
        localNormal.NormalizeFast();
        polygon.plane.Normal() = localNormal;
        if (polygon.numEdges != 0) {
            const int edgeIndex = polygon.edges[0] & 0x7F;
            const int vertexIndex = tw->edges[edgeIndex].vertexNum[
                polygon.edges[0] >> 7];
            polygon.plane.d = -localNormal.Dot(
                Vec3(tw->vertexPosition[vertexIndex]));
        } else {
            polygon.plane.d = 0.0f;
        }
    }
    MakeTraceBounds(*tw, minimum, maximum, true);
}

void idPolygonModelCollisionDetection::StartContentsPoint(
    idTraceWork* const tw, trace_t* const result, const idVec3& start,
    const int contentMask, const idVec3& modelOrigin,
    const idMat3& modelAxis) {
    std::memset(result, 0, sizeof(*result));
    result->fraction = 1.0f;
    result->endpos = start;
    result->endAxis = idMat3(1.0f);
    tw->traceResult = result;
    tw->contactsResult = nullptr;
    tw->clipResult = nullptr;
    tw->fraction = 1.0f;
    tw->contents = contentMask;
    tw->isConvex = true;
    tw->traceType = TRACE_CONTENTS_POINT;
    tw->quickExit = false;

    const idVec3 local = WorldToModelVector(modelAxis, start - modelOrigin);
    SetVec4(tw->start, local);
    tw->end = tw->start;
    tw->numVerts = 1;
    tw->numEdges = 0;
    tw->numPolys = 0;
    tw->vertexPosition[0] = tw->start;
    tw->trmBoundsMin.Set(0.0f, 0.0f, 0.0f, 0.0f);
    tw->trmBoundsMax.Set(0.0f, 0.0f, 0.0f, 0.0f);
    tw->trmExtents.Set(0.0f, 0.0f, 0.0f, 0.0f);
    MakeTraceBounds(*tw, local, local, false);
}

void idPolygonModelCollisionDetection::FinishContents(
    idTraceWork* const tw, const idVec3& modelOrigin,
    const idMat3& modelAxis, const int modelEntityNum,
    const int modelPhysicsId, const int modelBodyId, const int selfId,
    const int modelContentsOverride) {
    if (tw->traceResult == nullptr || tw->traceResult->fraction >= 1.0f) {
        return;
    }
    contactInfo_t& contact = tw->traceResult->c;
    if (!IsIdentity(modelAxis)) {
        contact.normal = ModelToWorldVector(modelAxis, contact.normal);
        contact.point = ModelToWorldVector(modelAxis, contact.point);
    }
    contact.point = contact.point + modelOrigin;
    contact.dist += modelOrigin.Dot(contact.normal);
    contact.entityNum = modelEntityNum;
    contact.physicsId = modelPhysicsId;
    contact.bodyId = modelBodyId;
    contact.selfId = selfId;
    if (modelContentsOverride != 0 && contact.contentFlags != 0) {
        contact.contentFlags = modelContentsOverride;
    }
}
