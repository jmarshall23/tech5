#include "cm/jobs/polygonmodel/polygonmodel.h"

#include "cm/jobs/polygonmodel/polygonmodeldata.h"
#include "idlib/geometry/tracemodel.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>

namespace {

idVec3 Vec3(const idVec4& value) {
    return idVec3(value.x, value.y, value.z);
}

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

bool PointInsidePolygon(const cm_subModelPtrs_t& model,
    const cm_polygon_t& polygon, const idPlane& plane, const idVec3& point) {
    bool positive = false;
    bool negative = false;
    for (int edgeNumber = 0; edgeNumber < polygon.numEdges; ++edgeNumber) {
        const std::uint16_t reference = model.polygonEdges[
            polygon.firstEdge + edgeNumber];
        const cm_edge_t& edge = model.edges[CM_EdgeIndex(reference)];
        const idVec3& start = model.vertices[
            CM_EdgeStartVertex(edge, reference)].p;
        const idVec3& end = model.vertices[
            CM_EdgeEndVertex(edge, reference)].p;
        const float side = (end - start).Cross(point - start).Dot(
            plane.Normal());
        positive |= side > 0.01f;
        negative |= side < -0.01f;
        if (positive && negative) {
            return false;
        }
    }
    return true;
}

void ClosestSegmentPoints(const idVec3& p1, const idVec3& q1,
    const idVec3& p2, const idVec3& q2, idVec3& first, idVec3& second) {
    const idVec3 d1 = q1 - p1;
    const idVec3 d2 = q2 - p2;
    const idVec3 r = p1 - p2;
    const float a = d1.Dot(d1);
    const float e = d2.Dot(d2);
    const float f = d2.Dot(r);
    float s = 0.0f;
    float t = 0.0f;
    if (a <= 1.0e-12f && e <= 1.0e-12f) {
        first = p1;
        second = p2;
        return;
    }
    if (a <= 1.0e-12f) {
        t = (std::max)(0.0f, (std::min)(1.0f, f / e));
    } else {
        const float c = d1.Dot(r);
        if (e <= 1.0e-12f) {
            s = (std::max)(0.0f, (std::min)(1.0f, -c / a));
        } else {
            const float b = d1.Dot(d2);
            const float denominator = a * e - b * b;
            if (denominator != 0.0f) {
                s = (std::max)(0.0f, (std::min)(1.0f,
                    (b * f - c * e) / denominator));
            }
            t = (b * s + f) / e;
            if (t < 0.0f) {
                t = 0.0f;
                s = (std::max)(0.0f, (std::min)(1.0f, -c / a));
            } else if (t > 1.0f) {
                t = 1.0f;
                s = (std::max)(0.0f,
                    (std::min)(1.0f, (b - c) / a));
            }
        }
    }
    first = p1 + d1 * s;
    second = p2 + d2 * t;
}

void SetMaterial(contactInfo_t& contact, const cm_material_t& material) {
    contact.contentFlags = material.contentFlags;
    contact.surfaceFlags = material.surfaceFlags;
    contact.surfaceType = material.surfaceType;
    contact.surfaceColor[0] = material.surfaceColor[0];
    contact.surfaceColor[1] = material.surfaceColor[1];
    contact.surfaceColor[2] = material.surfaceColor[2];
}

void AppendContact(idTraceWork& tw, const contactType_t type,
    const idVec3& point, idVec3 normal, const float separation,
    const cm_material_t& material, const int modelFeature,
    const int trmFeature) {
    if (tw.contactsResult == nullptr || tw.contactsResult->numContacts >= 12) {
        return;
    }
    if (normal.NormalizeFast() == 0.0f) {
        normal.Set(0.0f, 0.0f, 1.0f);
    }
    contactInfo_t& contact =
        tw.contactsResult->contacts[tw.contactsResult->numContacts++];
    std::memset(&contact, 0, sizeof(contact));
    contact.type = type;
    contact.point = point;
    contact.normal = normal;
    contact.dist = normal.Dot(point);
    contact.separation = separation;
    SetMaterial(contact, material);
    contact.modelFeature = modelFeature;
    contact.trmFeature = trmFeature;
}

} // namespace

void idPolygonModelCollisionDetection::TestTrmEdgeInContactWithPolygon(
    idTraceWork* const tw, const cm_polygon_t& polygon,
    const int trmEdgeNum) {
    if (trmEdgeNum < 0 || trmEdgeNum >= static_cast<int>(tw->numEdges)) {
        return;
    }
    const idVec3 trmStart = Vec3(tw->vertexPosition[
        tw->edges[trmEdgeNum].vertexNum[0]]);
    const idVec3 trmEnd = Vec3(tw->vertexPosition[
        tw->edges[trmEdgeNum].vertexNum[1]]);
    const cm_material_t& material = tw->subModelPtrs.materials[polygon.material];
    for (int edgeNumber = 0; edgeNumber < polygon.numEdges; ++edgeNumber) {
        const std::uint16_t reference = tw->subModelPtrs.polygonEdges[
            polygon.firstEdge + edgeNumber];
        const int modelEdgeNum = CM_EdgeIndex(reference);
        const cm_edge_t& edge = tw->subModelPtrs.edges[modelEdgeNum];
        const idVec3& modelStart = tw->subModelPtrs.vertices[
            CM_EdgeStartVertex(edge, reference)].p;
        const idVec3& modelEnd = tw->subModelPtrs.vertices[
            CM_EdgeEndVertex(edge, reference)].p;
        idVec3 trmPoint;
        idVec3 modelPoint;
        ClosestSegmentPoints(trmStart, trmEnd, modelStart, modelEnd,
            trmPoint, modelPoint);
        idVec3 delta = trmPoint - modelPoint;
        const float distance = delta.Length();
        if (distance > tw->contactDepth) {
            continue;
        }
        if (distance <= 1.0e-6f) {
            delta = (trmEnd - trmStart).Cross(modelEnd - modelStart);
        }
        AppendContact(*tw, CONTACT_EDGE, (trmPoint + modelPoint) * 0.5f,
            delta, distance - tw->contactDepth, material,
            ((tw->subModelNum << 16) & 0x1FFF0000)
                | 0x40000000 | modelEdgeNum,
            0x40000000 | trmEdgeNum);
    }
}

void idPolygonModelCollisionDetection::TestTrmVertexInContactWithPolygon(
    idTraceWork* const tw, const cm_polygon_t& polygon,
    const idPlane& polygonPlane, const int trmVertNum) {
    if (trmVertNum < 0 || trmVertNum >= static_cast<int>(tw->numVerts)) {
        return;
    }
    const idVec3 point = Vec3(tw->vertexPosition[trmVertNum]);
    const float distance = polygonPlane.Distance(point);
    if (std::fabs(distance) > tw->contactDepth) {
        return;
    }
    const idVec3 projected = point - polygonPlane.Normal() * distance;
    if (!PointInsidePolygon(tw->subModelPtrs, polygon,
            polygonPlane, projected)) {
        return;
    }
    const cm_material_t& material = tw->subModelPtrs.materials[polygon.material];
    AppendContact(*tw, CONTACT_TRMVERTEX, projected, polygonPlane.Normal(),
        std::fabs(distance) - tw->contactDepth, material,
        ((tw->subModelNum << 16) & 0x1FFF0000)
            | 0x60000000
            | static_cast<int>(&polygon - tw->subModelPtrs.polygons),
        trmVertNum);
}

void idPolygonModelCollisionDetection::TestVertexInContactWithTrmPolygon(
    idTraceWork* const tw, const cm_trmPolygon_t& trmPolygon,
    const cm_polygon_t& polygon, const cm_vertex_t& vertex) {
    const float distance = trmPolygon.plane.Distance(vertex.p);
    if (std::fabs(distance) > tw->contactDepth) {
        return;
    }
    const idVec3 projected = vertex.p - trmPolygon.plane.Normal() * distance;
    bool positive = false;
    bool negative = false;
    for (unsigned int edgeNumber = 0;
         edgeNumber < trmPolygon.numEdges; ++edgeNumber) {
        const int edgeIndex = trmPolygon.edges[edgeNumber] & 0x7F;
        const cm_trmEdge_t& edge = tw->edges[edgeIndex];
        const int direction = trmPolygon.edges[edgeNumber] >> 7;
        const idVec3 start = Vec3(tw->vertexPosition[edge.vertexNum[direction]]);
        const idVec3 end = Vec3(tw->vertexPosition[edge.vertexNum[direction ^ 1]]);
        const float side = (end - start).Cross(projected - start).Dot(
            trmPolygon.plane.Normal());
        positive |= side > 0.01f;
        negative |= side < -0.01f;
    }
    if (positive && negative) {
        return;
    }
    const cm_material_t& material = tw->subModelPtrs.materials[polygon.material];
    const int vertexNumber = static_cast<int>(
        &vertex - tw->subModelPtrs.vertices);
    AppendContact(*tw, CONTACT_MODELVERTEX, projected,
        -trmPolygon.plane.Normal(), std::fabs(distance) - tw->contactDepth,
        material, ((tw->subModelNum << 16) & 0x1FFF0000)
            | 0x20000000 | vertexNumber,
        0x60000000
            | static_cast<int>(&trmPolygon - tw->polys));
}

bool idPolygonModelCollisionDetection::TestTrmInContactWithPolygon(
    idTraceWork* const tw, const int polygonNum) {
    if (TestAndSet(tw->modelCheckCounts.polygonCheckCounts, polygonNum)) {
        return false;
    }
    const cm_polygon_t& polygon = tw->subModelPtrs.polygons[polygonNum];
    const cm_material_t& material = tw->subModelPtrs.materials[polygon.material];
    if ((material.contentFlags & tw->contents) == 0
        || !tw->traceBoundsShort.IntersectsBounds(polygon.bounds)) {
        return false;
    }
    const int firstContact = tw->contactsResult != nullptr
        ? tw->contactsResult->numContacts : 0;
    idPlane plane;
    CM_GetPolygonPlane(tw->subModelPtrs, polygon, plane);
    for (unsigned int vertex = 0; vertex < tw->numVerts; ++vertex) {
        TestTrmVertexInContactWithPolygon(tw, polygon, plane,
            static_cast<int>(vertex));
    }
    for (unsigned int edge = 0; edge < tw->numEdges; ++edge) {
        TestTrmEdgeInContactWithPolygon(tw, polygon,
            static_cast<int>(edge));
    }
    for (int edgeNumber = 0; edgeNumber < polygon.numEdges; ++edgeNumber) {
        const std::uint16_t reference = tw->subModelPtrs.polygonEdges[
            polygon.firstEdge + edgeNumber];
        const cm_edge_t& edge = tw->subModelPtrs.edges[CM_EdgeIndex(reference)];
        const cm_vertex_t& vertex = tw->subModelPtrs.vertices[
            CM_EdgeStartVertex(edge, reference)];
        for (unsigned int trmPolygon = 0;
             trmPolygon < tw->numPolys; ++trmPolygon) {
            TestVertexInContactWithTrmPolygon(tw, tw->polys[trmPolygon],
                polygon, vertex);
        }
    }
    return tw->contactsResult != nullptr
        && (tw->contactsResult->numContacts >= 12
            || tw->contactsResult->numContacts > firstContact && tw->quickExit);
}

void idPolygonModelCollisionDetection::StartContacts(idTraceWork* const tw,
    contactsResult_t* const result, const idVec3& start,
    const idVec3& direction, const float depth, const idTraceModel& trm,
    const idMat3& trmAxis, const int contentMask,
    const idVec3& modelOrigin, const idMat3& modelAxis) {
    tw->contactDepth = (std::max)(0.0f, depth);
    if (direction.LengthSqr() > 1.0e-12f) {
        idVec3 normalizedDirection = direction;
        normalizedDirection.NormalizeFast();
        StartTranslation(tw, &tw->tempTraceResult, result, start,
            start + normalizedDirection * depth, &trm, trmAxis,
            contentMask, modelOrigin, modelAxis);
        tw->traceType = TRACE_CONTACTS_UNI_DIR;
        tw->contactDepth = depth;
        return;
    }
    StartContents(tw, &tw->tempTraceResult, start, &trm, trmAxis,
        contentMask, modelOrigin, modelAxis);
    tw->traceType = TRACE_CONTACTS_OMNI_DIR;
    tw->traceResult = &tw->tempTraceResult;
    tw->contactsResult = result;
    tw->contactDepth = depth;
    for (int axis = 0; axis < 3; ++axis) {
        tw->traceBoundsMin[axis] -= depth;
        tw->traceBoundsMax[axis] += depth;
    }
    idBounds bounds;
    bounds[0].Set(tw->traceBoundsMin.x, tw->traceBoundsMin.y,
        tw->traceBoundsMin.z);
    bounds[1].Set(tw->traceBoundsMax.x, tw->traceBoundsMax.y,
        tw->traceBoundsMax.z);
    tw->traceBoundsShort.SetBounds(bounds);
}

void idPolygonModelCollisionDetection::FinishContacts(idTraceWork* const tw,
    const int firstContact, const idVec3& modelOrigin,
    const idMat3& modelAxis, const int modelEntityNum,
    const int modelPhysicsId, const int modelBodyId, const int selfId,
    const int modelContentsOverride) {
    if (tw->contactsResult == nullptr) {
        return;
    }
    contactsResult_t& result = *tw->contactsResult;
    for (int index = (std::max)(0, firstContact);
         index < result.numContacts && index < 12; ++index) {
        contactInfo_t& contact = result.contacts[index];
        contact.normal = ModelToWorldVector(modelAxis, contact.normal);
        contact.point = ModelToWorldVector(modelAxis, contact.point)
            + modelOrigin;
        contact.dist += modelOrigin.Dot(contact.normal);
        contact.entityNum = modelEntityNum;
        contact.physicsId = modelPhysicsId;
        contact.bodyId = modelBodyId;
        contact.selfId = selfId;
        if (modelContentsOverride != 0 && contact.contentFlags != 0) {
            contact.contentFlags = modelContentsOverride;
        }
    }
}
