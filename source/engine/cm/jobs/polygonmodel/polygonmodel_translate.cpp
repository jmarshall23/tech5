#include "cm/jobs/polygonmodel/polygonmodel.h"

#include "cm/jobs/polygonmodel/polygonmodeldata.h"
#include "idlib/geometry/tracemodel.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>

namespace {

constexpr float CM_CLIP_EPSILON = 0.25f;
constexpr float CM_GEOMETRY_EPSILON = 1.0e-6f;

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

bool IsIdentity(const idMat3& axis) {
    return axis[0].x == 1.0f && axis[1].y == 1.0f
        && axis[2].z == 1.0f
        && axis[0].y == 0.0f && axis[0].z == 0.0f
        && axis[1].x == 0.0f && axis[1].z == 0.0f
        && axis[2].x == 0.0f && axis[2].y == 0.0f;
}

bool TestAndSet(std::uint8_t* bits, const int index) {
    if (bits == nullptr || index < 0) {
        return false;
    }
    const std::uint8_t mask = static_cast<std::uint8_t>(1u << (index & 7));
    std::uint8_t& value = bits[index >> 3];
    const bool old = (value & mask) != 0;
    value = static_cast<std::uint8_t>(value | mask);
    return old;
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
    bool positive = false;
    bool negative = false;
    for (int index = 0; index < polygon.numEdges; ++index) {
        const std::uint16_t reference =
            model.polygonEdges[polygon.firstEdge + index];
        const cm_edge_t& edge = model.edges[CM_EdgeIndex(reference)];
        const idVec3& start = model.vertices[
            CM_EdgeStartVertex(edge, reference)].p;
        const idVec3& end = model.vertices[
            CM_EdgeEndVertex(edge, reference)].p;
        const float side = (end - start).Cross(point - start).Dot(
            plane.Normal());
        positive |= side > CM_CLIP_EPSILON;
        negative |= side < -CM_CLIP_EPSILON;
        if (positive && negative) {
            return false;
        }
    }
    return true;
}

float Triple(const idVec3& first, const idVec3& second,
    const idVec3& third) {
    return first.Dot(second.Cross(third));
}

bool MovingSegmentIntersection(const idVec3& firstStart,
    const idVec3& firstEnd, const idVec3& movement,
    const idVec3& secondStart, const idVec3& secondEnd,
    float& fraction, float& firstScale, float& secondScale) {
    const idVec3 firstDirection = firstEnd - firstStart;
    const idVec3 secondDirection = secondEnd - secondStart;
    const idVec3 negativeSecond = -secondDirection;
    const idVec3 rhs = secondStart - firstStart;
    const float determinant = Triple(firstDirection, movement,
        negativeSecond);
    if (std::fabs(determinant) <= CM_GEOMETRY_EPSILON) {
        return false;
    }
    firstScale = Triple(rhs, movement, negativeSecond) / determinant;
    fraction = Triple(firstDirection, rhs, negativeSecond) / determinant;
    secondScale = Triple(firstDirection, movement, rhs) / determinant;
    return firstScale >= -CM_GEOMETRY_EPSILON
        && firstScale <= 1.0f + CM_GEOMETRY_EPSILON
        && secondScale >= -CM_GEOMETRY_EPSILON
        && secondScale <= 1.0f + CM_GEOMETRY_EPSILON
        && fraction >= 0.0f && fraction <= 1.0f;
}

void StoreCollision(idTraceWork& tw, const float fraction,
    const contactType_t type, const idVec3& point, idVec3 normal,
    const float planeDistance, const cm_material_t& material,
    const int modelFeature, const int trmFeature) {
    if (tw.traceResult == nullptr || fraction >= tw.fraction) {
        return;
    }
    if (normal.NormalizeFast() == 0.0f) {
        return;
    }
    tw.fraction = (std::max)(0.0f, fraction);
    trace_t& trace = *tw.traceResult;
    trace.fraction = tw.fraction;
    trace.c.type = type;
    trace.c.point = point;
    trace.c.normal = normal;
    trace.c.dist = planeDistance;
    trace.c.separation = 0.0f;
    SetMaterial(trace.c, material);
    trace.c.modelFeature = modelFeature;
    trace.c.trmFeature = trmFeature;
    trace.c.flags = 0;
    if (tw.contactsResult != nullptr) {
        idPolygonModelCollisionDetection::AddContact(&tw);
    }
}

} // namespace

void idPolygonModelCollisionDetection::TranslationSetup(idTraceWork* const tw,
    const idVec3& start, const idVec3& end, const idVec3& offset,
    const idMat3& trmAxis, const idVec3& modelOrigin,
    const idMat3& modelAxis) {
    const idVec3 startCenter = WorldToModelVector(modelAxis,
        start + ModelToWorldVector(trmAxis, offset) - modelOrigin);
    const idVec3 endCenter = WorldToModelVector(modelAxis,
        end + ModelToWorldVector(trmAxis, offset) - modelOrigin);
    SetVec4(tw->start, startCenter);
    SetVec4(tw->end, endCenter);
    SetVec4(tw->dir, endCenter - startCenter);
    SetVec4(tw->negDir, startCenter - endCenter);
}

void idPolygonModelCollisionDetection::TranslationUsedPrimitives(
    idTraceWork* const tw, const idVec3&, const idVec3&,
    const idTraceModel& trm, const idMat3&) {
    std::memset(tw->vertIsUsed, 0, sizeof(tw->vertIsUsed));
    std::memset(tw->edgeIsUsed, 0, sizeof(tw->edgeIsUsed));
    std::memset(tw->polyIsUsed, 0, sizeof(tw->polyIsUsed));
    for (unsigned int index = 0; index < (std::min)(trm.numVerts, 32u); ++index) {
        tw->vertIsUsed[index] = 1;
    }
    for (unsigned int index = 0; index < (std::min)(trm.numEdges, 32u); ++index) {
        tw->edgeIsUsed[index] = 1;
    }
    for (unsigned int index = 0; index < (std::min)(trm.numPolys, 16u); ++index) {
        tw->polyIsUsed[index] = 1;
    }
}

void idPolygonModelCollisionDetection::TranslationHeartPlanes(
    idTraceWork* const tw) {
    idVec3 direction = Vec3(tw->dir);
    if (direction.NormalizeFast() == 0.0f) {
        tw->heartPlane1 = idPlane(1.0f, 0.0f, 0.0f, -tw->start.x);
        tw->heartPlane2 = idPlane(0.0f, 1.0f, 0.0f, -tw->start.y);
        return;
    }
    idVec3 reference = std::fabs(direction.z) < 0.9f
        ? idVec3(0.0f, 0.0f, 1.0f) : idVec3(0.0f, 1.0f, 0.0f);
    idVec3 first = direction.Cross(reference);
    first.NormalizeFast();
    idVec3 second = direction.Cross(first);
    second.NormalizeFast();
    tw->heartPlane1 = idPlane(first, first.Dot(Vec3(tw->start)));
    tw->heartPlane2 = idPlane(second, second.Dot(Vec3(tw->start)));
    tw->maxDistFromHeartPlane1 = 0.0f;
    tw->maxDistFromHeartPlane2 = 0.0f;
    for (unsigned int index = 0; index < tw->numVerts; ++index) {
        tw->maxDistFromHeartPlane1 = (std::max)(
            tw->maxDistFromHeartPlane1,
            std::fabs(tw->heartPlane1.Distance(Vec3(tw->vertexPosition[index]))));
        tw->maxDistFromHeartPlane2 = (std::max)(
            tw->maxDistFromHeartPlane2,
            std::fabs(tw->heartPlane2.Distance(Vec3(tw->vertexPosition[index]))));
    }
}

void idPolygonModelCollisionDetection::TranslationVerts(idTraceWork* const tw,
    const idTraceModel&) {
    const idVec3 direction = Vec3(tw->dir);
    for (unsigned int index = 0; index < tw->numVerts; ++index) {
        SetVec4(tw->vertexEndPosition[index],
            Vec3(tw->vertexPosition[index]) + direction);
        tw->vertexPluecker[index].FromLine(
            Vec3(tw->vertexPosition[index]),
            Vec3(tw->vertexEndPosition[index]));
    }
}

void idPolygonModelCollisionDetection::TranslationEdges(idTraceWork* const tw,
    const idTraceModel&) {
    for (unsigned int index = 0; index < tw->numEdges; ++index) {
        const idVec3 first = Vec3(tw->vertexPosition[
            tw->edges[index].vertexNum[0]]);
        const idVec3 second = Vec3(tw->vertexPosition[
            tw->edges[index].vertexNum[1]]);
        tw->edgePluecker[index].FromLine(first, second);
        idVec3 normal = (second - first).Cross(Vec3(tw->dir));
        normal.NormalizeFast();
        SetVec4(tw->edgeNormal[index], normal);
    }
}

void idPolygonModelCollisionDetection::TranslationPolys(idTraceWork* const tw,
    const idTraceModel&) {
    for (unsigned int index = 0; index < tw->numPolys; ++index) {
        tw->polyIsUsed[index] = tw->polys[index].numEdges != 0;
    }
}

void idPolygonModelCollisionDetection::TranslationBounds(idTraceWork* const tw) {
    idVec3 minimum(std::numeric_limits<float>::max(),
        std::numeric_limits<float>::max(),
        std::numeric_limits<float>::max());
    idVec3 maximum(-std::numeric_limits<float>::max(),
        -std::numeric_limits<float>::max(),
        -std::numeric_limits<float>::max());
    for (unsigned int index = 0; index < tw->numVerts; ++index) {
        const idVec3 points[2] = { Vec3(tw->vertexPosition[index]),
            Vec3(tw->vertexEndPosition[index]) };
        for (const idVec3& point : points) {
            minimum.x = (std::min)(minimum.x, point.x);
            minimum.y = (std::min)(minimum.y, point.y);
            minimum.z = (std::min)(minimum.z, point.z);
            maximum.x = (std::max)(maximum.x, point.x);
            maximum.y = (std::max)(maximum.y, point.y);
            maximum.z = (std::max)(maximum.z, point.z);
        }
    }
    tw->traceBoundsMin.Set(minimum.x - 1.0f, minimum.y - 1.0f,
        minimum.z - 1.0f, 0.0f);
    tw->traceBoundsMax.Set(maximum.x + 1.0f, maximum.y + 1.0f,
        maximum.z + 1.0f, 0.0f);
    idBounds quantized;
    quantized[0].Set(std::floor(minimum.x) - 1.0f,
        std::floor(minimum.y) - 1.0f, std::floor(minimum.z) - 1.0f);
    quantized[1].Set(std::ceil(maximum.x) + 1.0f,
        std::ceil(maximum.y) + 1.0f, std::ceil(maximum.z) + 1.0f);
    tw->traceBoundsShort.SetBounds(quantized);
}

void idPolygonModelCollisionDetection::TranslationUpdateBounds(
    idTraceWork* const tw) {
    const idVec3 start = Vec3(tw->start);
    const idVec3 partialEnd = start + Vec3(tw->dir) * tw->fraction;
    tw->end.x = partialEnd.x;
    tw->end.y = partialEnd.y;
    tw->end.z = partialEnd.z;
    TranslationBounds(tw);
}

void idPolygonModelCollisionDetection::TranslationPlueckerCache(
    idTraceWork* const tw, const cm_polygon_t& polygon) {
    for (int index = 0; index < polygon.numEdges && index < 16; ++index) {
        const std::uint16_t reference = tw->subModelPtrs.polygonEdges[
            polygon.firstEdge + index];
        const cm_edge_t& edge = tw->subModelPtrs.edges[CM_EdgeIndex(reference)];
        tw->polygonEdgePlueckerCache[index].FromLine(
            tw->subModelPtrs.vertices[CM_EdgeStartVertex(edge, reference)].p,
            tw->subModelPtrs.vertices[CM_EdgeEndVertex(edge, reference)].p);
    }
}

void idPolygonModelCollisionDetection::TranslationEdgePlueckerCache(
    idTraceWork* const tw, const cm_polygon_t& polygon) {
    TranslationPlueckerCache(tw, polygon);
}

void idPolygonModelCollisionDetection::TranslationSideCache(
    const idPluecker* const pluecker, const std::uint8_t* const used,
    const unsigned int count, const idPluecker* const plueckerCache,
    cm_sideCache_t* const sideCache, const unsigned int cacheSize) {
    for (unsigned int cacheIndex = 0; cacheIndex < cacheSize; ++cacheIndex) {
        std::uint32_t sides = 0;
        for (unsigned int index = 0; index < count && index < 32; ++index) {
            if ((used == nullptr || used[index] != 0)
                && pluecker[index] * plueckerCache[cacheIndex] < 0.0f) {
                sides |= 1u << index;
            }
        }
        sideCache[cacheIndex].side = sides;
    }
}

void idPolygonModelCollisionDetection::TranslationPolygonSideCache(
    idTraceWork* const tw, const cm_polygon_t& polygon) {
    TranslationPlueckerCache(tw, polygon);
    TranslationSideCache(tw->edgePluecker, tw->edgeIsUsed, tw->numEdges,
        tw->polygonEdgePlueckerCache, tw->polygonEdgeSideCache,
        (std::min)(static_cast<unsigned int>(polygon.numEdges), 20u));
}

void idPolygonModelCollisionDetection::AddContact(idTraceWork* const tw) {
    if (tw->contactsResult == nullptr || tw->traceResult == nullptr
        || tw->contactsResult->numContacts >= 12) {
        return;
    }
    tw->contactsResult->contacts[tw->contactsResult->numContacts++] =
        tw->traceResult->c;
}

float idPolygonModelCollisionDetection::TranslateEdgeThroughEdge(
    const idPluecker& first, const idPluecker& second,
    const idVec3& direction) {
    idVec3 firstStart;
    idVec3 firstEnd;
    idVec3 secondStart;
    idVec3 secondEnd;
    if (!first.ToLine(firstStart, firstEnd)
        || !second.ToLine(secondStart, secondEnd)) {
        return 1.0f;
    }
    float fraction;
    float firstScale;
    float secondScale;
    if (!MovingSegmentIntersection(firstStart, firstEnd, direction,
            secondStart, secondEnd, fraction, firstScale, secondScale)) {
        return 1.0f;
    }
    return fraction;
}

int idPolygonModelCollisionDetection::TranslateTrmEdgesThroughPolygon(
    idTraceWork* const tw, const cm_polygon_t& polygon) {
    const cm_material_t& material = tw->subModelPtrs.materials[polygon.material];
    const idVec3 movement = Vec3(tw->dir);
    bool collision = false;
    for (unsigned int trmEdge = 0; trmEdge < tw->numEdges; ++trmEdge) {
        const idVec3 firstStart = Vec3(tw->vertexPosition[
            tw->edges[trmEdge].vertexNum[0]]);
        const idVec3 firstEnd = Vec3(tw->vertexPosition[
            tw->edges[trmEdge].vertexNum[1]]);
        for (int modelEdgeNumber = 0;
             modelEdgeNumber < polygon.numEdges; ++modelEdgeNumber) {
            const std::uint16_t reference = tw->subModelPtrs.polygonEdges[
                polygon.firstEdge + modelEdgeNumber];
            const int modelEdge = CM_EdgeIndex(reference);
            const cm_edge_t& edge = tw->subModelPtrs.edges[modelEdge];
            const idVec3& secondStart = tw->subModelPtrs.vertices[
                CM_EdgeStartVertex(edge, reference)].p;
            const idVec3& secondEnd = tw->subModelPtrs.vertices[
                CM_EdgeEndVertex(edge, reference)].p;
            float fraction;
            float firstScale;
            float secondScale;
            if (!MovingSegmentIntersection(firstStart, firstEnd, movement,
                    secondStart, secondEnd, fraction, firstScale, secondScale)
                || fraction >= tw->fraction) {
                continue;
            }
            idVec3 normal = (firstEnd - firstStart).Cross(
                secondEnd - secondStart);
            if (normal.Dot(movement) > 0.0f) {
                normal = -normal;
            }
            const idVec3 point = secondStart
                + (secondEnd - secondStart) * secondScale;
            StoreCollision(*tw, fraction, CONTACT_EDGE, point, normal,
                normal.Dot(point), material,
                ((tw->subModelNum << 16) & 0x1FFF0000)
                    | 0x40000000 | modelEdge,
                0x40000000 | static_cast<int>(trmEdge));
            collision = true;
        }
    }
    return collision && tw->fraction <= 0.0f;
}

float idPolygonModelCollisionDetection::TranslatePointThroughPlane(
    const idPlane& plane, const idVec3& start, const idVec3& end) {
    const float startDistance = plane.Distance(start);
    const float endDistance = plane.Distance(end);
    const float denominator = startDistance - endDistance;
    if (startDistance <= 0.0f || endDistance > 0.0f
        || std::fabs(denominator) <= CM_GEOMETRY_EPSILON) {
        return 1.0f;
    }
    return (startDistance - CM_CLIP_EPSILON) / denominator;
}

int idPolygonModelCollisionDetection::TranslateTrmVertsThroughPolygon(
    idTraceWork* const tw, const cm_polygon_t& polygon,
    const idPlane& polygonPlane) {
    const cm_material_t& material = tw->subModelPtrs.materials[polygon.material];
    for (unsigned int vertexNumber = 0;
         vertexNumber < tw->numVerts; ++vertexNumber) {
        const idVec3 start = Vec3(tw->vertexPosition[vertexNumber]);
        const idVec3 end = Vec3(tw->vertexEndPosition[vertexNumber]);
        const float fraction = TranslatePointThroughPlane(
            polygonPlane, start, end);
        if (fraction < 0.0f || fraction >= tw->fraction) {
            continue;
        }
        const idVec3 point = start + (end - start) * fraction;
        if (!PointInsidePolygon(tw->subModelPtrs, polygon,
                polygonPlane, point)) {
            continue;
        }
        StoreCollision(*tw, fraction, CONTACT_TRMVERTEX, point,
            polygonPlane.Normal(), polygonPlane.Dist(), material,
            ((tw->subModelNum << 16) & 0x1FFF0000)
                | 0x60000000
                | static_cast<int>(&polygon - tw->subModelPtrs.polygons),
            static_cast<int>(vertexNumber));
    }
    return tw->fraction <= 0.0f;
}

int idPolygonModelCollisionDetection::TranslatePolygonVertsThroughTrm(
    idTraceWork* const tw, const cm_polygon_t& polygon) {
    if (!tw->isConvex || tw->numPolys == 0) {
        return 0;
    }
    const cm_material_t& material = tw->subModelPtrs.materials[polygon.material];
    const idVec3 movement = Vec3(tw->dir);
    for (int edgeNumber = 0; edgeNumber < polygon.numEdges; ++edgeNumber) {
        const std::uint16_t reference = tw->subModelPtrs.polygonEdges[
            polygon.firstEdge + edgeNumber];
        const cm_edge_t& modelEdge = tw->subModelPtrs.edges[
            CM_EdgeIndex(reference)];
        const int vertexNumber = CM_EdgeStartVertex(modelEdge, reference);
        if (TestAndSet(tw->modelCheckCounts.vertexCheckCounts, vertexNumber)) {
            continue;
        }
        const idVec3& point = tw->subModelPtrs.vertices[vertexNumber].p;
        float enter = 0.0f;
        float leave = tw->fraction;
        int enterPlane = -1;
        bool possible = true;
        for (unsigned int planeNumber = 0;
             planeNumber < tw->numPolys; ++planeNumber) {
            const idPlane& plane = tw->polys[planeNumber].plane;
            const float distance = plane.Distance(point);
            const float rate = -plane.Normal().Dot(movement);
            if (std::fabs(rate) <= CM_GEOMETRY_EPSILON) {
                if (distance > 0.0f) {
                    possible = false;
                    break;
                }
                continue;
            }
            const float crossing = -distance / rate;
            if (rate < 0.0f) {
                if (crossing > enter) {
                    enter = crossing;
                    enterPlane = static_cast<int>(planeNumber);
                }
            } else {
                leave = (std::min)(leave, crossing);
            }
            if (enter > leave) {
                possible = false;
                break;
            }
        }
        if (!possible || enterPlane < 0 || enter < 0.0f
            || enter >= tw->fraction) {
            continue;
        }
        idVec3 normal = -tw->polys[enterPlane].plane.Normal();
        StoreCollision(*tw, enter, CONTACT_MODELVERTEX, point, normal,
            normal.Dot(point), material,
            ((tw->subModelNum << 16) & 0x1FFF0000)
                | 0x20000000 | vertexNumber,
            0x60000000 | enterPlane);
    }
    return tw->fraction <= 0.0f;
}

int idPolygonModelCollisionDetection::TranslateTrmThroughPolygon(
    idTraceWork* const tw, const int polygonNum) {
    if (TestAndSet(tw->modelCheckCounts.polygonCheckCounts, polygonNum)) {
        return 0;
    }
    const cm_polygon_t& polygon = tw->subModelPtrs.polygons[polygonNum];
    const cm_material_t& material = tw->subModelPtrs.materials[polygon.material];
    if ((material.contentFlags & tw->contents) == 0
        || !tw->traceBoundsShort.IntersectsBounds(polygon.bounds)) {
        return 0;
    }
    idPlane plane;
    CM_GetPolygonPlane(tw->subModelPtrs, polygon, plane);
    TranslationPolygonSideCache(tw, polygon);
    if (TranslateTrmVertsThroughPolygon(tw, polygon, plane)) {
        return 1;
    }
    if (TranslateTrmEdgesThroughPolygon(tw, polygon)) {
        return 1;
    }
    return TranslatePolygonVertsThroughTrm(tw, polygon);
}

int idPolygonModelCollisionDetection::TranslatePointThroughPolygon(
    idTraceWork* const tw, const int polygonNum) {
    if (TestAndSet(tw->modelCheckCounts.polygonCheckCounts, polygonNum)) {
        return 0;
    }
    const cm_polygon_t& polygon = tw->subModelPtrs.polygons[polygonNum];
    const cm_material_t& material = tw->subModelPtrs.materials[polygon.material];
    if ((material.contentFlags & tw->contents) == 0
        || !tw->traceBoundsShort.IntersectsBounds(polygon.bounds)) {
        return 0;
    }
    idPlane plane;
    CM_GetPolygonPlane(tw->subModelPtrs, polygon, plane);
    const idVec3 start = Vec3(tw->vertexPosition[0]);
    const idVec3 end = Vec3(tw->vertexEndPosition[0]);
    const float fraction = TranslatePointThroughPlane(plane, start, end);
    if (fraction < 0.0f || fraction >= tw->fraction) {
        return 0;
    }
    const idVec3 point = start + (end - start) * fraction;
    if (!PointInsidePolygon(tw->subModelPtrs, polygon, plane, point)) {
        return 0;
    }
    StoreCollision(*tw, fraction, CONTACT_TRMVERTEX, point,
        plane.Normal(), plane.Dist(), material,
        ((tw->subModelNum << 16) & 0x1FFF0000)
            | 0x60000000 | polygonNum, 0);
    return tw->fraction <= 0.0f;
}

int idPolygonModelCollisionDetection::StartTranslation(idTraceWork* const tw,
    trace_t* const result, contactsResult_t* const contacts,
    const idVec3& start, const idVec3& end, const idTraceModel* const trm,
    const idMat3& trmAxis, const int contentMask,
    const idVec3& modelOrigin, const idMat3& modelAxis) {
    if (trm == nullptr) {
        return StartTranslationPoint(tw, result, start, end, contentMask,
            modelOrigin, modelAxis);
    }
    StartContents(tw, result, start, trm, trmAxis, contentMask,
        modelOrigin, modelAxis);
    tw->traceType = contacts == nullptr
        ? TRACE_TRANSLATION : TRACE_CONTACTS_UNI_DIR;
    tw->contactsResult = contacts;
    tw->fraction = 1.0f;
    result->fraction = 1.0f;
    TranslationSetup(tw, start, end, trm->offset, trmAxis,
        modelOrigin, modelAxis);
    TranslationUsedPrimitives(tw, start, end, *trm, trmAxis);
    TranslationVerts(tw, *trm);
    TranslationEdges(tw, *trm);
    TranslationPolys(tw, *trm);
    TranslationHeartPlanes(tw);
    TranslationBounds(tw);
    return Vec3(tw->dir).LengthSqr() > 0.0f;
}

int idPolygonModelCollisionDetection::StartTranslationPoint(
    idTraceWork* const tw, trace_t* const result, const idVec3& start,
    const idVec3& end, const int contentMask, const idVec3& modelOrigin,
    const idMat3& modelAxis) {
    StartContentsPoint(tw, result, start, contentMask, modelOrigin, modelAxis);
    tw->traceType = TRACE_TRANSLATION_POINT;
    const idVec3 localEnd = WorldToModelVector(modelAxis, end - modelOrigin);
    SetVec4(tw->end, localEnd);
    SetVec4(tw->dir, localEnd - Vec3(tw->start));
    SetVec4(tw->negDir, -Vec3(tw->dir));
    tw->vertexEndPosition[0] = tw->end;
    tw->fraction = 1.0f;
    result->fraction = 1.0f;
    TranslationBounds(tw);
    return Vec3(tw->dir).LengthSqr() > 0.0f;
}

void idPolygonModelCollisionDetection::FinishTranslation(
    idTraceWork* const tw, const idVec3& start, const idVec3& end,
    const idVec3& modelOrigin, const idMat3& modelAxis,
    const int modelEntityNum, const int modelPhysicsId,
    const int modelBodyId, const int selfId,
    const int modelContentsOverride) {
    if (tw->traceResult == nullptr) {
        return;
    }
    trace_t& trace = *tw->traceResult;
    trace.fraction = tw->fraction;
    trace.endpos = start + (end - start) * tw->fraction;
    if (trace.fraction >= 1.0f) {
        return;
    }
    if (!IsIdentity(modelAxis)) {
        trace.c.normal = ModelToWorldVector(modelAxis, trace.c.normal);
        trace.c.point = ModelToWorldVector(modelAxis, trace.c.point);
    }
    trace.c.point = trace.c.point + modelOrigin;
    trace.c.dist += modelOrigin.Dot(trace.c.normal);
    trace.c.entityNum = modelEntityNum;
    trace.c.physicsId = modelPhysicsId;
    trace.c.bodyId = modelBodyId;
    trace.c.selfId = selfId;
    if (modelContentsOverride != 0 && trace.c.contentFlags != 0) {
        trace.c.contentFlags = modelContentsOverride;
    }
}
