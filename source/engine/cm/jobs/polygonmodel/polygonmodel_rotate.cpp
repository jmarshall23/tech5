#include "cm/jobs/polygonmodel/polygonmodel.h"

#include "cm/jobs/polygonmodel/polygonmodeldata.h"
#include "idlib/geometry/tracemodel.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>

namespace {

constexpr float DEG2RAD = 0.01745329251994329577f;
constexpr float RAD2DEG = 57.295779513082320876f;
constexpr float ROTATION_EPSILON = 0.01f;

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

idVec3 RotateAroundAxis(const idVec3& point, const idVec3& origin,
    idVec3 axis, const float angleDegrees) {
    if (axis.NormalizeFast() == 0.0f || angleDegrees == 0.0f) {
        return point;
    }
    const float angle = angleDegrees * DEG2RAD;
    const float sine = std::sin(angle);
    const float cosine = std::cos(angle);
    const idVec3 relative = point - origin;
    return origin + relative * cosine + axis.Cross(relative) * sine
        + axis * (axis.Dot(relative) * (1.0f - cosine));
}

idVec3 RotateVector(const idVec3& value, idVec3 axis,
    const float angleDegrees) {
    return RotateAroundAxis(value, idVec3(0.0f, 0.0f, 0.0f),
        axis, angleDegrees);
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
        const std::uint16_t reference = model.polygonEdges[
            polygon.firstEdge + index];
        const cm_edge_t& edge = model.edges[CM_EdgeIndex(reference)];
        const idVec3& start = model.vertices[
            CM_EdgeStartVertex(edge, reference)].p;
        const idVec3& end = model.vertices[
            CM_EdgeEndVertex(edge, reference)].p;
        const float side = (end - start).Cross(point - start).Dot(
            plane.Normal());
        positive |= side > ROTATION_EPSILON;
        negative |= side < -ROTATION_EPSILON;
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
            if (std::fabs(denominator) > 1.0e-12f) {
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

void StoreRotationCollision(idTraceWork& tw, const float fraction,
    const contactType_t type, const idVec3& point, idVec3 normal,
    const float distance, const cm_material_t& material,
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
    trace.c.dist = distance;
    trace.c.separation = 0.0f;
    SetMaterial(trace.c, material);
    trace.c.modelFeature = modelFeature;
    trace.c.trmFeature = trmFeature;
    trace.c.flags = 0;
}

bool PointInsideInitialTrace(const idTraceWork& tw, const idVec3& point,
    int& nearestPlane) {
    float nearestDistance = -std::numeric_limits<float>::max();
    nearestPlane = 0;
    for (unsigned int index = 0; index < tw.numPolys; ++index) {
        const float distance = tw.polys[index].plane.Distance(point);
        if (distance > 0.0f) {
            return false;
        }
        if (distance > nearestDistance) {
            nearestDistance = distance;
            nearestPlane = static_cast<int>(index);
        }
    }
    return tw.numPolys != 0;
}

} // namespace

float CM_TanZeroHalfPI(const float angle) {
    const float clamped = (std::max)(0.0f,
        (std::min)(1.57079632679f, angle));
    return std::tan(clamped);
}

float CM_ArcTanPositive(const float value) {
    return std::atan((std::max)(0.0f, value));
}

void CM_PointRotationBounds(const idVec3& origin, const idVec3& axis,
    const idVec3& start, const idVec3& end, idVec4& boundsMin,
    idVec4& boundsMax) {
    idVec3 minimum((std::min)(start.x, end.x),
        (std::min)(start.y, end.y), (std::min)(start.z, end.z));
    idVec3 maximum((std::max)(start.x, end.x),
        (std::max)(start.y, end.y), (std::max)(start.z, end.z));
    // Include quarter turns around the recovered axis; this captures extrema
    // missed by an endpoint-only arc bound.
    for (int step = 1; step < 4; ++step) {
        const idVec3 point = RotateAroundAxis(start, origin, axis,
            static_cast<float>(step * 90));
        minimum.x = (std::min)(minimum.x, point.x);
        minimum.y = (std::min)(minimum.y, point.y);
        minimum.z = (std::min)(minimum.z, point.z);
        maximum.x = (std::max)(maximum.x, point.x);
        maximum.y = (std::max)(maximum.y, point.y);
        maximum.z = (std::max)(maximum.z, point.z);
    }
    boundsMin.Set(minimum.x, minimum.y, minimum.z, 0.0f);
    boundsMax.Set(maximum.x, maximum.y, maximum.z, 0.0f);
}

bool idPolygonModelCollisionDetection::EdgeIntersectsBoundsShort(
    const idBoundsShort& bounds, const idVec3& start, const idVec3& end) {
    return bounds.ToBounds().LineIntersection(start, end);
}

void idPolygonModelCollisionDetection::RotationSetup(idTraceWork* const tw,
    const idVec3& rotationOrigin, const idVec3& rotationAxis,
    const float angle, const idVec3& start, const idVec3& offset,
    const idMat3& trmAxis, const idVec3& modelOrigin,
    const idMat3& modelAxis) {
    const idVec3 centerWorld = start + ModelToWorldVector(trmAxis, offset);
    const idVec3 localCenter = WorldToModelVector(modelAxis,
        centerWorld - modelOrigin);
    const idVec3 localOrigin = WorldToModelVector(modelAxis,
        rotationOrigin - modelOrigin);
    idVec3 localAxis = WorldToModelVector(modelAxis, rotationAxis);
    localAxis.NormalizeFast();
    SetVec4(tw->start, localCenter);
    SetVec4(tw->origin, localOrigin);
    SetVec4(tw->axis, localAxis);
    tw->angle = angle;
    tw->negAngle = -angle;
    tw->initialTan = 0.0f;
    tw->maxTan = std::tan(std::fabs(angle) * DEG2RAD * 0.5f);
    const idVec3 endCenter = RotateAroundAxis(localCenter,
        localOrigin, localAxis, angle);
    SetVec4(tw->end, endCenter);
    SetVec4(tw->dir, endCenter - localCenter);
    SetVec4(tw->negDir, localCenter - endCenter);
}

void idPolygonModelCollisionDetection::TransformFromOriginAxisAngle(
    idMat3x4& transform, const idVec3& origin, const idVec3& axis,
    const float angle) {
    const idVec3 x = RotateVector(idVec3(1.0f, 0.0f, 0.0f), axis, angle);
    const idVec3 y = RotateVector(idVec3(0.0f, 1.0f, 0.0f), axis, angle);
    const idVec3 z = RotateVector(idVec3(0.0f, 0.0f, 1.0f), axis, angle);
    transform.mat[0] = x.x; transform.mat[1] = y.x; transform.mat[2] = z.x;
    transform.mat[4] = x.y; transform.mat[5] = y.y; transform.mat[6] = z.y;
    transform.mat[8] = x.z; transform.mat[9] = y.z; transform.mat[10] = z.z;
    const idVec3 translated = origin - RotateVector(origin, axis, angle);
    transform.mat[3] = translated.x;
    transform.mat[7] = translated.y;
    transform.mat[11] = translated.z;
}

void idPolygonModelCollisionDetection::TransformAxisToZAxis(
    idMat3x4& transform, const idVec3& origin, const idVec3& axis) {
    idVec3 z = axis;
    if (z.NormalizeFast() == 0.0f) {
        transform.Identity();
        return;
    }
    idVec3 reference = std::fabs(z.z) < 0.9f
        ? idVec3(0.0f, 0.0f, 1.0f) : idVec3(0.0f, 1.0f, 0.0f);
    idVec3 x = reference.Cross(z);
    x.NormalizeFast();
    idVec3 y = z.Cross(x);
    y.NormalizeFast();
    transform.mat[0] = x.x; transform.mat[1] = x.y; transform.mat[2] = x.z;
    transform.mat[4] = y.x; transform.mat[5] = y.y; transform.mat[6] = y.z;
    transform.mat[8] = z.x; transform.mat[9] = z.y; transform.mat[10] = z.z;
    transform.mat[3] = -x.Dot(origin);
    transform.mat[7] = -y.Dot(origin);
    transform.mat[11] = -z.Dot(origin);
}

void idPolygonModelCollisionDetection::RotationVerts(idTraceWork* const tw,
    const idTraceModel&, idVec4* const zverts) {
    for (unsigned int index = 0; index < tw->numVerts; ++index) {
        const idVec3 start = Vec3(tw->vertexPosition[index]);
        const idVec3 end = RotateAroundAxis(start, Vec3(tw->origin),
            Vec3(tw->axis), tw->angle);
        SetVec4(tw->vertexEndPosition[index], end);
        if (zverts != nullptr) {
            idVec3 transformed;
            tw->ZAxisTransform.Transform(transformed, start);
            SetVec4(zverts[index], transformed);
        }
    }
}

void idPolygonModelCollisionDetection::RotationEdges(idTraceWork* const tw,
    const idTraceModel&, const idVec4*) {
    for (unsigned int index = 0; index < tw->numEdges; ++index) {
        const idVec3 start = Vec3(tw->vertexPosition[
            tw->edges[index].vertexNum[0]]);
        const idVec3 end = Vec3(tw->vertexPosition[
            tw->edges[index].vertexNum[1]]);
        tw->edgePluecker[index].FromLine(start, end);
        tw->edgeZAxisPluecker[index] = tw->edgePluecker[index];
    }
}

void idPolygonModelCollisionDetection::RotationPolys(idTraceWork* const tw,
    const idTraceModel&) {
    for (unsigned int index = 0; index < tw->numPolys; ++index) {
        tw->polyIsUsed[index] = tw->polys[index].numEdges != 0;
    }
}

void idPolygonModelCollisionDetection::RotationBounds(idTraceWork* const tw) {
    idVec3 minimum(std::numeric_limits<float>::max(),
        std::numeric_limits<float>::max(),
        std::numeric_limits<float>::max());
    idVec3 maximum(-std::numeric_limits<float>::max(),
        -std::numeric_limits<float>::max(),
        -std::numeric_limits<float>::max());
    const int steps = (std::max)(1,
        static_cast<int>(std::ceil(std::fabs(tw->angle) / 10.0f)));
    for (unsigned int vertex = 0; vertex < tw->numVerts; ++vertex) {
        const idVec3 original = Vec3(tw->vertexPosition[vertex]);
        for (int step = 0; step <= steps; ++step) {
            const idVec3 point = RotateAroundAxis(original, Vec3(tw->origin),
                Vec3(tw->axis), tw->angle * step / steps);
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
    idBounds bounds;
    bounds[0].Set(std::floor(minimum.x) - 1.0f,
        std::floor(minimum.y) - 1.0f, std::floor(minimum.z) - 1.0f);
    bounds[1].Set(std::ceil(maximum.x) + 1.0f,
        std::ceil(maximum.y) + 1.0f, std::ceil(maximum.z) + 1.0f);
    tw->traceBoundsShort.SetBounds(bounds);
}

void idPolygonModelCollisionDetection::RotationEdgePlueckerCache(
    idTraceWork* const tw, const cm_polygon_t& polygon) {
    TranslationPlueckerCache(tw, polygon);
}

void idPolygonModelCollisionDetection::RotationCullPolygonEdges(
    idTraceWork* const tw, const cm_polygon_t& polygon) {
    for (int index = 0; index < polygon.numEdges && index < 20; ++index) {
        tw->polygonEdgeSideCache[index].side = 0;
        const idPluecker& modelEdge = tw->polygonEdgePlueckerCache[index];
        for (unsigned int trmEdge = 0; trmEdge < tw->numEdges; ++trmEdge) {
            if (tw->edgePluecker[trmEdge] * modelEdge < 0.0f) {
                tw->polygonEdgeSideCache[index].side |= 1u << trmEdge;
            }
        }
    }
}

int idPolygonModelCollisionDetection::CollisionBetweenEdgeBounds(
    const idTraceWork&, const idVec3& firstStart, const idVec3& firstEnd,
    const idVec3& secondStart, const idVec3& secondEnd, const float,
    idVec3& collisionPoint, idVec3& collisionNormal) {
    idVec3 firstPoint;
    idVec3 secondPoint;
    ClosestSegmentPoints(firstStart, firstEnd, secondStart, secondEnd,
        firstPoint, secondPoint);
    collisionNormal = firstPoint - secondPoint;
    if (collisionNormal.LengthSqr() > ROTATION_EPSILON * ROTATION_EPSILON) {
        return 0;
    }
    collisionPoint = (firstPoint + secondPoint) * 0.5f;
    if (collisionNormal.NormalizeFast() == 0.0f) {
        collisionNormal = (firstEnd - firstStart).Cross(
            secondEnd - secondStart);
        collisionNormal.NormalizeFast();
    }
    return 1;
}

int idPolygonModelCollisionDetection::RotateEdgeThroughEdge(
    const idPluecker& first, const idPluecker& second, const float angle,
    const float minTan, const float maxTan, float& tanHalfAngle) {
    idVec3 firstStart;
    idVec3 firstEnd;
    idVec3 secondStart;
    idVec3 secondEnd;
    if (!first.ToLine(firstStart, firstEnd)
        || !second.ToLine(secondStart, secondEnd)) {
        return 0;
    }
    const int steps = (std::max)(8,
        static_cast<int>(std::ceil(std::fabs(angle) / 5.0f)));
    for (int step = 0; step <= steps; ++step) {
        const float fraction = static_cast<float>(step) / steps;
        const float tangent = std::tan(std::fabs(angle) * DEG2RAD
            * fraction * 0.5f);
        if (tangent < minTan || tangent > maxTan) {
            continue;
        }
        const idVec3 rotatedStart = RotateAroundAxis(firstStart,
            idVec3(0.0f, 0.0f, 0.0f), idVec3(0.0f, 0.0f, 1.0f),
            angle * fraction);
        const idVec3 rotatedEnd = RotateAroundAxis(firstEnd,
            idVec3(0.0f, 0.0f, 0.0f), idVec3(0.0f, 0.0f, 1.0f),
            angle * fraction);
        idVec3 firstPoint;
        idVec3 secondPoint;
        ClosestSegmentPoints(rotatedStart, rotatedEnd,
            secondStart, secondEnd, firstPoint, secondPoint);
        if ((firstPoint - secondPoint).LengthSqr()
            <= ROTATION_EPSILON * ROTATION_EPSILON) {
            tanHalfAngle = tangent;
            return 1;
        }
    }
    return 0;
}

int idPolygonModelCollisionDetection::EdgeFurthestFromEdge(
    const idPluecker& first, const idPluecker& second, const float angle,
    float& tanHalfAngle, float& direction) {
    float bestDistance = -1.0f;
    idVec3 firstStart;
    idVec3 firstEnd;
    idVec3 secondStart;
    idVec3 secondEnd;
    if (!first.ToLine(firstStart, firstEnd)
        || !second.ToLine(secondStart, secondEnd)) {
        return 0;
    }
    for (int step = 0; step <= 32; ++step) {
        const float fraction = step / 32.0f;
        const idVec3 start = RotateAroundAxis(firstStart, idVec3(0, 0, 0),
            idVec3(0, 0, 1), angle * fraction);
        const idVec3 end = RotateAroundAxis(firstEnd, idVec3(0, 0, 0),
            idVec3(0, 0, 1), angle * fraction);
        idVec3 a;
        idVec3 b;
        ClosestSegmentPoints(start, end, secondStart, secondEnd, a, b);
        const float distance = (a - b).LengthSqr();
        if (distance > bestDistance) {
            bestDistance = distance;
            tanHalfAngle = std::tan(std::fabs(angle) * DEG2RAD
                * fraction * 0.5f);
        }
    }
    direction = angle < 0.0f ? -1.0f : 1.0f;
    return bestDistance >= 0.0f;
}

int idPolygonModelCollisionDetection::RotateTrmEdgesThroughPolygon(
    idTraceWork* const tw, const cm_polygon_t& polygon) {
    const cm_material_t& material = tw->subModelPtrs.materials[polygon.material];
    const int steps = (std::max)(8,
        static_cast<int>(std::ceil(std::fabs(tw->angle) / 5.0f)));
    for (unsigned int trmEdge = 0; trmEdge < tw->numEdges; ++trmEdge) {
        const idVec3 originalStart = Vec3(tw->vertexPosition[
            tw->edges[trmEdge].vertexNum[0]]);
        const idVec3 originalEnd = Vec3(tw->vertexPosition[
            tw->edges[trmEdge].vertexNum[1]]);
        for (int modelEdgeNumber = 0;
             modelEdgeNumber < polygon.numEdges; ++modelEdgeNumber) {
            const std::uint16_t reference = tw->subModelPtrs.polygonEdges[
                polygon.firstEdge + modelEdgeNumber];
            const int modelEdge = CM_EdgeIndex(reference);
            const cm_edge_t& edge = tw->subModelPtrs.edges[modelEdge];
            const idVec3& modelStart = tw->subModelPtrs.vertices[
                CM_EdgeStartVertex(edge, reference)].p;
            const idVec3& modelEnd = tw->subModelPtrs.vertices[
                CM_EdgeEndVertex(edge, reference)].p;
            for (int step = 0; step <= steps; ++step) {
                const float fraction = static_cast<float>(step) / steps;
                if (fraction >= tw->fraction) {
                    break;
                }
                const idVec3 start = RotateAroundAxis(originalStart,
                    Vec3(tw->origin), Vec3(tw->axis), tw->angle * fraction);
                const idVec3 end = RotateAroundAxis(originalEnd,
                    Vec3(tw->origin), Vec3(tw->axis), tw->angle * fraction);
                idVec3 trmPoint;
                idVec3 modelPoint;
                ClosestSegmentPoints(start, end, modelStart, modelEnd,
                    trmPoint, modelPoint);
                if ((trmPoint - modelPoint).LengthSqr()
                    > ROTATION_EPSILON * ROTATION_EPSILON) {
                    continue;
                }
                idVec3 normal = (end - start).Cross(modelEnd - modelStart);
                StoreRotationCollision(*tw, fraction, CONTACT_EDGE,
                    (trmPoint + modelPoint) * 0.5f, normal,
                    normal.Dot(modelPoint), material,
                    ((tw->subModelNum << 16) & 0x1FFF0000)
                        | 0x40000000 | modelEdge,
                    0x40000000 | static_cast<int>(trmEdge));
                break;
            }
        }
    }
    return tw->fraction <= 0.0f;
}

int idPolygonModelCollisionDetection::RotatePointThroughPlane(
    const idVec3& point, const idPlane& plane, const float angle,
    const float minTan, const float maxTan, float& tanHalfAngle) {
    const int steps = (std::max)(8,
        static_cast<int>(std::ceil(std::fabs(angle) / 5.0f)));
    float previousDistance = plane.Distance(point);
    for (int step = 1; step <= steps; ++step) {
        const float fraction = static_cast<float>(step) / steps;
        const float tangent = std::tan(std::fabs(angle) * DEG2RAD
            * fraction * 0.5f);
        const idVec3 rotated = RotateAroundAxis(point, idVec3(0, 0, 0),
            idVec3(0, 0, 1), angle * fraction);
        const float distance = plane.Distance(rotated);
        if (tangent >= minTan && tangent <= maxTan
            && previousDistance > 0.0f && distance <= 0.0f) {
            tanHalfAngle = tangent;
            return 1;
        }
        previousDistance = distance;
    }
    return 0;
}

int idPolygonModelCollisionDetection::PointFurthestFromPlane(
    const idVec3& point, const idPlane& plane, const float angle,
    float& tanHalfAngle, float& direction) {
    float bestDistance = plane.Distance(point);
    int bestStep = 0;
    for (int step = 1; step <= 64; ++step) {
        const idVec3 rotated = RotateAroundAxis(point, idVec3(0, 0, 0),
            idVec3(0, 0, 1), angle * step / 64.0f);
        const float distance = plane.Distance(rotated);
        if (distance > bestDistance) {
            bestDistance = distance;
            bestStep = step;
        }
    }
    tanHalfAngle = std::tan(std::fabs(angle) * DEG2RAD
        * bestStep / 128.0f);
    direction = angle < 0.0f ? -1.0f : 1.0f;
    return bestStep != 0;
}

int idPolygonModelCollisionDetection::RotatePointThroughEpsilonPlane(
    const idTraceWork& tw, const idVec3& point, const idVec3&,
    const idPlane& plane, const float angle, const idVec3& rotationOrigin,
    float& tanHalfAngle, idVec3& collisionPoint, idVec3& endDirection) {
    const int steps = (std::max)(8,
        static_cast<int>(std::ceil(std::fabs(angle) / 5.0f)));
    float previousDistance = plane.Distance(point) - ROTATION_EPSILON;
    for (int step = 1; step <= steps; ++step) {
        const float fraction = static_cast<float>(step) / steps;
        const idVec3 rotated = RotateAroundAxis(point, rotationOrigin,
            Vec3(tw.axis), angle * fraction);
        const float distance = plane.Distance(rotated) - ROTATION_EPSILON;
        if (previousDistance > 0.0f && distance <= 0.0f) {
            tanHalfAngle = std::tan(std::fabs(angle) * DEG2RAD
                * fraction * 0.5f);
            collisionPoint = rotated;
            endDirection = Vec3(tw.axis).Cross(rotated - rotationOrigin);
            return 1;
        }
        previousDistance = distance;
    }
    return 0;
}

int idPolygonModelCollisionDetection::RotateTrmVertsThroughPolygon(
    idTraceWork* const tw, const cm_polygon_t& polygon,
    const idPlane& polygonPlane) {
    const cm_material_t& material = tw->subModelPtrs.materials[polygon.material];
    const int polygonNum = static_cast<int>(&polygon - tw->subModelPtrs.polygons);
    const int steps = (std::max)(8,
        static_cast<int>(std::ceil(std::fabs(tw->angle) / 5.0f)));
    for (unsigned int vertex = 0; vertex < tw->numVerts; ++vertex) {
        const idVec3 original = Vec3(tw->vertexPosition[vertex]);
        idVec3 previous = original;
        float previousDistance = polygonPlane.Distance(previous);
        for (int step = 1; step <= steps; ++step) {
            const float fraction = static_cast<float>(step) / steps;
            if (fraction >= tw->fraction) {
                break;
            }
            const idVec3 current = RotateAroundAxis(original,
                Vec3(tw->origin), Vec3(tw->axis), tw->angle * fraction);
            const float distance = polygonPlane.Distance(current);
            if (previousDistance > 0.0f && distance <= 0.0f) {
                float low = static_cast<float>(step - 1) / steps;
                float high = fraction;
                idVec3 collision = current;
                for (int iteration = 0; iteration < 12; ++iteration) {
                    const float middle = (low + high) * 0.5f;
                    collision = RotateAroundAxis(original, Vec3(tw->origin),
                        Vec3(tw->axis), tw->angle * middle);
                    if (polygonPlane.Distance(collision) > 0.0f) {
                        low = middle;
                    } else {
                        high = middle;
                    }
                }
                if (PointInsidePolygon(tw->subModelPtrs, polygon,
                        polygonPlane, collision)) {
                    StoreRotationCollision(*tw, high, CONTACT_TRMVERTEX,
                        collision, polygonPlane.Normal(), polygonPlane.Dist(),
                        material, ((tw->subModelNum << 16) & 0x1FFF0000)
                            | 0x60000000 | polygonNum,
                        static_cast<int>(vertex));
                }
            }
            previous = current;
            previousDistance = distance;
        }
    }
    return tw->fraction <= 0.0f;
}

int idPolygonModelCollisionDetection::RotatePolygonVertsThroughTrm(
    idTraceWork* const tw, const cm_polygon_t& polygon) {
    if (!tw->isConvex || tw->numPolys == 0) {
        return 0;
    }
    const cm_material_t& material = tw->subModelPtrs.materials[polygon.material];
    const int steps = (std::max)(8,
        static_cast<int>(std::ceil(std::fabs(tw->angle) / 5.0f)));
    for (int edgeNumber = 0; edgeNumber < polygon.numEdges; ++edgeNumber) {
        const std::uint16_t reference = tw->subModelPtrs.polygonEdges[
            polygon.firstEdge + edgeNumber];
        const cm_edge_t& edge = tw->subModelPtrs.edges[CM_EdgeIndex(reference)];
        const int vertexNumber = CM_EdgeStartVertex(edge, reference);
        if (TestAndSet(tw->modelCheckCounts.vertexCheckCounts, vertexNumber)) {
            continue;
        }
        const idVec3& modelPoint = tw->subModelPtrs.vertices[vertexNumber].p;
        for (int step = 1; step <= steps; ++step) {
            const float fraction = static_cast<float>(step) / steps;
            if (fraction >= tw->fraction) {
                break;
            }
            // Inverse-rotate the stationary model point into the trace model's
            // initial frame, then test its recovered convex planes.
            const idVec3 localPoint = RotateAroundAxis(modelPoint,
                Vec3(tw->origin), Vec3(tw->axis), -tw->angle * fraction);
            int nearestPlane = 0;
            if (!PointInsideInitialTrace(*tw, localPoint, nearestPlane)) {
                continue;
            }
            idVec3 normal = -RotateVector(tw->polys[nearestPlane].plane.Normal(),
                Vec3(tw->axis), tw->angle * fraction);
            StoreRotationCollision(*tw, fraction, CONTACT_MODELVERTEX,
                modelPoint, normal, normal.Dot(modelPoint), material,
                ((tw->subModelNum << 16) & 0x1FFF0000)
                    | 0x20000000 | vertexNumber,
                0x60000000 | nearestPlane);
            break;
        }
    }
    return tw->fraction <= 0.0f;
}

bool idPolygonModelCollisionDetection::RotateTrmThroughPolygon(
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
    idPlane plane;
    CM_GetPolygonPlane(tw->subModelPtrs, polygon, plane);
    RotationEdgePlueckerCache(tw, polygon);
    RotationCullPolygonEdges(tw, polygon);
    if (RotateTrmVertsThroughPolygon(tw, polygon, plane)
        || RotateTrmEdgesThroughPolygon(tw, polygon)
        || RotatePolygonVertsThroughTrm(tw, polygon)) {
        return true;
    }
    return false;
}

int idPolygonModelCollisionDetection::StartRotation(idTraceWork* const tw,
    trace_t* const result, const idVec3& rotationOrigin,
    const idVec3& rotationAxis, const float angle, const idVec3& start,
    const idTraceModel* const trm, const idMat3& trmAxis,
    const int contentMask, const idVec3& modelOrigin,
    const idMat3& modelAxis) {
    if (trm == nullptr) {
        return StartRotationPoint(tw, result, rotationOrigin, rotationAxis,
            angle, start, contentMask, modelOrigin, modelAxis);
    }
    StartContents(tw, result, start, trm, trmAxis, contentMask,
        modelOrigin, modelAxis);
    tw->traceType = TRACE_ROTATION;
    tw->fraction = 1.0f;
    result->fraction = 1.0f;
    RotationSetup(tw, rotationOrigin, rotationAxis, angle, start,
        trm->offset, trmAxis, modelOrigin, modelAxis);
    TransformAxisToZAxis(tw->ZAxisTransform, Vec3(tw->origin),
        Vec3(tw->axis));
    TransformFromOriginAxisAngle(tw->endTransform, Vec3(tw->origin),
        Vec3(tw->axis), angle);
    idVec4 zverts[32];
    RotationVerts(tw, *trm, zverts);
    RotationEdges(tw, *trm, zverts);
    RotationPolys(tw, *trm);
    RotationBounds(tw);
    return angle != 0.0f;
}

int idPolygonModelCollisionDetection::StartRotationPoint(
    idTraceWork* const tw, trace_t* const result,
    const idVec3& rotationOrigin, const idVec3& rotationAxis,
    const float angle, const idVec3& start, const int contentMask,
    const idVec3& modelOrigin, const idMat3& modelAxis) {
    StartContentsPoint(tw, result, start, contentMask, modelOrigin, modelAxis);
    tw->traceType = TRACE_ROTATION_POINT;
    RotationSetup(tw, rotationOrigin, rotationAxis, angle, start,
        idVec3(0.0f, 0.0f, 0.0f), idMat3(1.0f),
        modelOrigin, modelAxis);
    tw->vertexPosition[0] = tw->start;
    tw->vertexEndPosition[0] = tw->end;
    RotationBounds(tw);
    return angle != 0.0f;
}

void idPolygonModelCollisionDetection::FinishRotation(idTraceWork* const tw,
    const idVec3& rotationOrigin, const idVec3& rotationAxis,
    const float angle, const idVec3& start, const idMat3& trmAxis,
    const idVec3& modelOrigin, const idMat3& modelAxis,
    const int modelEntityNum, const int modelPhysicsId,
    const int modelBodyId, const int selfId,
    const int modelContentsOverride) {
    if (tw->traceResult == nullptr) {
        return;
    }
    trace_t& trace = *tw->traceResult;
    trace.fraction = tw->fraction;
    trace.endpos = RotateAroundAxis(start, rotationOrigin, rotationAxis,
        angle * tw->fraction);
    for (int column = 0; column < 3; ++column) {
        trace.endAxis[column] = RotateVector(trmAxis[column], rotationAxis,
            angle * tw->fraction);
    }
    if (trace.fraction >= 1.0f) {
        return;
    }
    trace.c.normal = ModelToWorldVector(modelAxis, trace.c.normal);
    trace.c.point = ModelToWorldVector(modelAxis, trace.c.point)
        + modelOrigin;
    trace.c.dist += modelOrigin.Dot(trace.c.normal);
    trace.c.entityNum = modelEntityNum;
    trace.c.physicsId = modelPhysicsId;
    trace.c.bodyId = modelBodyId;
    trace.c.selfId = selfId;
    if (modelContentsOverride != 0 && trace.c.contentFlags != 0) {
        trace.c.contentFlags = modelContentsOverride;
    }
}
