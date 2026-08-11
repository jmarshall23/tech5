#include "idlib/geometry/tracemodel.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <malloc.h>
#include <new>

void* idTraceModel::operator new(const std::size_t size) {
    void* const memory = _aligned_malloc(size, 128);
    if (memory == nullptr) {
        throw std::bad_alloc();
    }
    return memory;
}

void idTraceModel::operator delete(void* const memory) {
    if (memory != nullptr) {
        _aligned_free(memory);
    }
}

void idTraceModel::ClearUnused() {
    std::memset(vertsX + numVerts, 0,
        sizeof(float) * (32 - numVerts));
    std::memset(vertsY + numVerts, 0,
        sizeof(float) * (32 - numVerts));
    std::memset(vertsZ + numVerts, 0,
        sizeof(float) * (32 - numVerts));
    std::memset(edgeNormalX + numEdges, 0,
        sizeof(float) * (32 - numEdges));
    std::memset(edgeNormalY + numEdges, 0,
        sizeof(float) * (32 - numEdges));
    std::memset(edgeNormalZ + numEdges, 0,
        sizeof(float) * (32 - numEdges));
    std::memset(polyPlaneX + numPolys, 0,
        sizeof(float) * (16 - numPolys));
    std::memset(polyPlaneY + numPolys, 0,
        sizeof(float) * (16 - numPolys));
    std::memset(polyPlaneZ + numPolys, 0,
        sizeof(float) * (16 - numPolys));
    std::memset(polyPlaneW + numPolys, 0,
        sizeof(float) * (16 - numPolys));
    std::memset(edges + numEdges, 0,
        sizeof(traceModelEdge_t) * (32 - numEdges));
    std::memset(numPolyEdges + numPolys, 0,
        sizeof(unsigned int) * (16 - numPolys));
    std::memset(polyEdges + numPolys, 0,
        sizeof(polyEdges[0]) * (16 - numPolys));
    maxPolyEdges = 0;
    for (unsigned int polygon = 0; polygon < numPolys; ++polygon) {
        maxPolyEdges = (std::max)(maxPolyEdges, numPolyEdges[polygon]);
        const std::uint8_t fill = numPolyEdges[polygon] > 0
            ? polyEdges[polygon][numPolyEdges[polygon] - 1]
            : 0;
        for (unsigned int edge = numPolyEdges[polygon]; edge < 16; ++edge) {
            polyEdges[polygon][edge] = fill;
        }
    }
}

int idTraceModel::GenerateEdgeNormals() {
    std::memset(edgeNormalX, 0, sizeof(edgeNormalX));
    std::memset(edgeNormalY, 0, sizeof(edgeNormalY));
    std::memset(edgeNormalZ, 0, sizeof(edgeNormalZ));
    for (unsigned int polygon = 0; polygon < numPolys; ++polygon) {
        for (unsigned int edge = 0; edge < numPolyEdges[polygon]; ++edge) {
            const unsigned int edgeIndex = polyEdges[polygon][edge] & 0x7F;
            if (edgeIndex >= numEdges) {
                continue;
            }
            edgeNormalX[edgeIndex] += polyPlaneX[polygon];
            edgeNormalY[edgeIndex] += polyPlaneY[polygon];
            edgeNormalZ[edgeIndex] += polyPlaneZ[polygon];
        }
    }
    for (unsigned int edge = 0; edge < numEdges; ++edge) {
        idVec3 normal(edgeNormalX[edge], edgeNormalY[edge],
            edgeNormalZ[edge]);
        normal.NormalizeFast();
        edgeNormalX[edge] = normal.x;
        edgeNormalY[edge] = normal.y;
        edgeNormalZ[edge] = normal.z;
    }
    return 1;
}

bool idTraceModel::IsClosedSurface() const {
    unsigned int edgeUseCounts[32]{};
    for (unsigned int polygon = 0; polygon < numPolys; ++polygon) {
        for (unsigned int edge = 0; edge < numPolyEdges[polygon]; ++edge) {
            const unsigned int edgeIndex = polyEdges[polygon][edge] & 0x7Fu;
            if (edgeIndex < 32) {
                ++edgeUseCounts[edgeIndex];
            }
        }
    }
    for (unsigned int edge = 0; edge < numEdges; ++edge) {
        if (edgeUseCounts[edge] != 2) {
            return false;
        }
    }
    return true;
}

void idTraceModel::TestConvexity() {
    isConvex = true;
    for (unsigned int polygon = 0; polygon < numPolys; ++polygon) {
        for (unsigned int vertex = 0; vertex < numVerts; ++vertex) {
            const float distance =
                vertsX[vertex] * polyPlaneX[polygon]
                + vertsY[vertex] * polyPlaneY[polygon]
                + vertsZ[vertex] * polyPlaneZ[polygon]
                + polyPlaneW[polygon];
            if (distance > 0.01f) {
                isConvex = false;
                return;
            }
        }
    }
}

void idTraceModel::CalculateInsetSphereRadius() {
    const float lower = (std::min)(std::fabs(bounds[0].x),
        (std::min)(std::fabs(bounds[0].y), std::fabs(bounds[0].z)));
    const float upper = (std::min)(std::fabs(bounds[1].x),
        (std::min)(std::fabs(bounds[1].y), std::fabs(bounds[1].z)));
    radius = (std::min)(lower, upper);
}

void idTraceModel::InitBox() {
    type = TRM_BOX;
    numVerts = 8;
    numEdges = 12;
    numPolys = 6;
    maxPolyEdges = 4;

    const std::uint16_t edgeVertices[12][2] = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0},
        {4, 5}, {5, 6}, {6, 7}, {7, 4},
        {0, 4}, {1, 5}, {2, 6}, {3, 7}};
    std::memcpy(edges, edgeVertices, sizeof(edgeVertices));

    const std::uint8_t boxPolygonEdges[6][4] = {
        {0x83, 0x82, 0x81, 0x80},
        {4, 5, 6, 7},
        {0, 9, 0x84, 0x88},
        {1, 10, 0x85, 0x89},
        {2, 11, 0x86, 0x8A},
        {3, 8, 0x87, 0x8B}};
    for (int polygon = 0; polygon < 6; ++polygon) {
        numPolyEdges[polygon] = 4;
        std::memcpy(polyEdges[polygon], boxPolygonEdges[polygon], 4);
    }
    const idVec3 normals[6] = {
        idVec3(0.0f, 0.0f, -1.0f), idVec3(0.0f, 0.0f, 1.0f),
        idVec3(0.0f, -1.0f, 0.0f), idVec3(1.0f, 0.0f, 0.0f),
        idVec3(0.0f, 1.0f, 0.0f), idVec3(-1.0f, 0.0f, 0.0f)};
    for (int polygon = 0; polygon < 6; ++polygon) {
        polyPlaneX[polygon] = normals[polygon].x;
        polyPlaneY[polygon] = normals[polygon].y;
        polyPlaneZ[polygon] = normals[polygon].z;
        polyPlaneW[polygon] = 0.0f;
    }
    isConvex = true;
    GenerateEdgeNormals();
    ClearUnused();
}

void idTraceModel::SetupBox(const idBounds& boxBounds) {
    if (type != TRM_BOX) {
        InitBox();
    }
    offset = (boxBounds[0] + boxBounds[1]) * 0.5f;
    const idVec3 vertices[8] = {
        idVec3(boxBounds[0].x, boxBounds[0].y, boxBounds[0].z),
        idVec3(boxBounds[1].x, boxBounds[0].y, boxBounds[0].z),
        idVec3(boxBounds[1].x, boxBounds[1].y, boxBounds[0].z),
        idVec3(boxBounds[0].x, boxBounds[1].y, boxBounds[0].z),
        idVec3(boxBounds[0].x, boxBounds[0].y, boxBounds[1].z),
        idVec3(boxBounds[1].x, boxBounds[0].y, boxBounds[1].z),
        idVec3(boxBounds[1].x, boxBounds[1].y, boxBounds[1].z),
        idVec3(boxBounds[0].x, boxBounds[1].y, boxBounds[1].z)};
    for (int vertex = 0; vertex < 8; ++vertex) {
        vertsX[vertex] = vertices[vertex].x;
        vertsY[vertex] = vertices[vertex].y;
        vertsZ[vertex] = vertices[vertex].z;
    }
    polyPlaneW[0] = boxBounds[0].z;
    polyPlaneW[1] = -boxBounds[1].z;
    polyPlaneW[2] = boxBounds[0].y;
    polyPlaneW[3] = -boxBounds[1].x;
    polyPlaneW[4] = -boxBounds[1].y;
    polyPlaneW[5] = boxBounds[0].x;
    bounds = boxBounds;
    CalculateInsetSphereRadius();
}

void idTraceModel::SetupBox(const float size) {
    idBounds boxBounds;
    const float halfSize = size * 0.5f;
    boxBounds[0].Set(-halfSize, -halfSize, -halfSize);
    boxBounds[1].Set(halfSize, halfSize, halfSize);
    SetupBox(boxBounds);
}

// Retail: 0x82F28F40 ?SetupPolygon@idTraceModel@@QAAXPBVidVec3@@H@Z
void idTraceModel::SetupPolygon(const idVec3* const vertices,
        int count) {
    if (vertices == nullptr || count < 3) {
        type = TRM_INVALID;
        numVerts = numEdges = numPolys = maxPolyEdges = 0;
        offset.Zero();
        bounds[0].Zero();
        bounds[1].Zero();
        isConvex = false;
        ClearUnused();
        return;
    }
    // A polygon volume uses three edges per input vertex.  The retail code
    // falls back to ten vertices when the caller exceeds the 32-edge store.
    if (count * 3 > 32) {
        count = 10;
    }

    type = TRM_POLYGON;
    numVerts = static_cast<unsigned int>(count);
    numEdges = static_cast<unsigned int>(count);
    numPolys = 2;
    maxPolyEdges = static_cast<unsigned int>(count);
    numPolyEdges[0] = static_cast<unsigned int>(count);
    numPolyEdges[1] = static_cast<unsigned int>(count);

    idVec3 normal = (vertices[1] - vertices[0]).Cross(
        vertices[2] - vertices[0]);
    if (normal.NormalizeFast() == 0.0f) {
        normal.Set(0.0f, 0.0f, 1.0f);
    }
    polyPlaneX[0] = normal.x;
    polyPlaneY[0] = normal.y;
    polyPlaneZ[0] = normal.z;
    polyPlaneW[0] = -normal.Dot(vertices[0]);
    polyPlaneX[1] = -normal.x;
    polyPlaneY[1] = -normal.y;
    polyPlaneZ[1] = -normal.z;
    polyPlaneW[1] = normal.Dot(vertices[0]);

    bounds[0] = vertices[0];
    bounds[1] = vertices[0];
    offset.Zero();
    for (int index = 0; index < count; ++index) {
        const int next = (index + 1) % count;
        vertsX[index] = vertices[index].x;
        vertsY[index] = vertices[index].y;
        vertsZ[index] = vertices[index].z;
        edges[index].v[0] = static_cast<std::uint16_t>(index);
        edges[index].v[1] = static_cast<std::uint16_t>(next);
        polyEdges[0][index] = static_cast<std::uint8_t>(index);
        polyEdges[1][index] = static_cast<std::uint8_t>(
            0x80 | (count - index - 1));
        bounds[0].x = (std::min)(bounds[0].x, vertices[index].x);
        bounds[0].y = (std::min)(bounds[0].y, vertices[index].y);
        bounds[0].z = (std::min)(bounds[0].z, vertices[index].z);
        bounds[1].x = (std::max)(bounds[1].x, vertices[index].x);
        bounds[1].y = (std::max)(bounds[1].y, vertices[index].y);
        bounds[1].z = (std::max)(bounds[1].z, vertices[index].z);
        offset = offset + vertices[index];
    }
    offset = offset * (1.0f / static_cast<float>(count));
    CalculateInsetSphereRadius();
    isConvex = false;
    GenerateEdgeNormals();
    ClearUnused();
}

// Retail: 0x82F29298 ?ExtendPolygonToVolume@idTraceModel@@AAAXABVidVec3@@@Z
void idTraceModel::ExtendPolygonToVolume(const idVec3& direction) {
    const int count = static_cast<int>(numVerts);
    if (type != TRM_POLYGON || count < 3 || count * 3 > 32
            || count + 2 > 16) {
        return;
    }

    type = TRM_POLYGONVOLUME;
    numVerts = static_cast<unsigned int>(count * 2);
    numEdges = static_cast<unsigned int>(count * 3);
    numPolys = static_cast<unsigned int>(count + 2);

    bounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    bounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
    for (int index = 0; index < count; ++index) {
        const int next = (index + 1) % count;
        const idVec3 lower(vertsX[index], vertsY[index], vertsZ[index]);
        const idVec3 upper = lower + direction;
        vertsX[count + index] = upper.x;
        vertsY[count + index] = upper.y;
        vertsZ[count + index] = upper.z;

        edges[count + index].v[0] =
            static_cast<std::uint16_t>(count + index);
        edges[count + index].v[1] =
            static_cast<std::uint16_t>(count + next);
        edges[2 * count + index].v[0] =
            static_cast<std::uint16_t>(index);
        edges[2 * count + index].v[1] =
            static_cast<std::uint16_t>(count + index);

        polyEdges[1][index] = static_cast<std::uint8_t>(
            0x80 | (2 * count - index - 1));
        const int side = index + 2;
        numPolyEdges[side] = 4;
        polyEdges[side][0] = static_cast<std::uint8_t>(0x80 | index);
        polyEdges[side][1] = static_cast<std::uint8_t>(2 * count + index);
        polyEdges[side][2] = static_cast<std::uint8_t>(count + index);
        polyEdges[side][3] = static_cast<std::uint8_t>(
            0x80 | (2 * count + next));

        const idVec3 nextLower(vertsX[next], vertsY[next], vertsZ[next]);
        idVec3 sideNormal = direction.Cross(nextLower - lower);
        sideNormal.NormalizeFast();
        polyPlaneX[side] = sideNormal.x;
        polyPlaneY[side] = sideNormal.y;
        polyPlaneZ[side] = sideNormal.z;
        polyPlaneW[side] = -sideNormal.Dot(lower);

        const idVec3 points[2] = {lower, upper};
        for (const idVec3& point : points) {
            bounds[0].x = (std::min)(bounds[0].x, point.x);
            bounds[0].y = (std::min)(bounds[0].y, point.y);
            bounds[0].z = (std::min)(bounds[0].z, point.z);
            bounds[1].x = (std::max)(bounds[1].x, point.x);
            bounds[1].y = (std::max)(bounds[1].y, point.y);
            bounds[1].z = (std::max)(bounds[1].z, point.z);
        }
    }
    polyPlaneW[1] = -(polyPlaneX[1] * vertsX[count]
        + polyPlaneY[1] * vertsY[count]
        + polyPlaneZ[1] * vertsZ[count]);
    CalculateInsetSphereRadius();
    isConvex = true;
    GenerateEdgeNormals();
    ClearUnused();
}

// Retail: 0x82F296B8 ?SetupPolygonVolume@idTraceModel@@QAAXPBVidVec3@@HABV2@@Z
void idTraceModel::SetupPolygonVolume(const idVec3* const vertices,
        const int count, const idVec3& direction) {
    SetupPolygon(vertices, count);
    ExtendPolygonToVolume(direction);
}

void idTraceModel::Translate(const idVec3& translation) {
    for (unsigned int vertex = 0; vertex < numVerts; ++vertex) {
        vertsX[vertex] += translation.x;
        vertsY[vertex] += translation.y;
        vertsZ[vertex] += translation.z;
    }
    for (unsigned int polygon = 0; polygon < numPolys; ++polygon) {
        polyPlaneW[polygon] -= translation.x * polyPlaneX[polygon]
            + translation.y * polyPlaneY[polygon]
            + translation.z * polyPlaneZ[polygon];
    }
    offset = offset + translation;
    bounds[0] = bounds[0] + translation;
    bounds[1] = bounds[1] + translation;
}

bool idTraceModel::Compare(const idTraceModel& other) const {
    if (type != other.type || numVerts != other.numVerts
            || numEdges != other.numEdges || numPolys != other.numPolys) {
        return false;
    }
    for (int axis = 0; axis < 3; ++axis) {
        if (bounds[0][axis] != other.bounds[0][axis]
                || bounds[1][axis] != other.bounds[1][axis]
                || offset[axis] != other.offset[axis]) {
            return false;
        }
    }
    // For the primitive models the recovered implementation treats the type,
    // extents and offset as the complete identity.
    if (type < TRM_BONE || type > TRM_CUSTOM) {
        return true;
    }
    for (unsigned int vertex = 0; vertex < numVerts; ++vertex) {
        if (vertsX[vertex] != other.vertsX[vertex]
                || vertsY[vertex] != other.vertsY[vertex]
                || vertsZ[vertex] != other.vertsZ[vertex]) {
            return false;
        }
    }
    return true;
}

bool idTraceModel::ContainsPoint(const idVec3& point) const {
    for (unsigned int polygon = 0; polygon < numPolys; ++polygon) {
        const float distance = point.x * polyPlaneX[polygon]
            + point.y * polyPlaneY[polygon]
            + point.z * polyPlaneZ[polygon]
            + polyPlaneW[polygon];
        if (distance > 0.0f) {
            return false;
        }
    }
    return true;
}

void idTraceModel::SetupCylinder(const idBounds& cylinderBounds,
        int numSides) {
    if (numSides < 3) {
        numSides = 3;
    }
    if (numSides * 2 > 32) {
        numSides = 16;
    }
    if (numSides * 3 > 32) {
        numSides = 10;
    }
    if (numSides + 2 > 16) {
        numSides = 14;
    }

    type = TRM_CYLINDER;
    numVerts = static_cast<unsigned int>(numSides * 2);
    numEdges = static_cast<unsigned int>(numSides * 3);
    numPolys = static_cast<unsigned int>(numSides + 2);
    maxPolyEdges = static_cast<unsigned int>(numSides);
    offset = (cylinderBounds[0] + cylinderBounds[1]) * 0.5f;

    const float radiusX = cylinderBounds[1].x - offset.x;
    const float radiusY = cylinderBounds[1].y - offset.y;
    constexpr float twoPi = 6.28318530717958647692f;
    for (int side = 0; side < numSides; ++side) {
        const float angle = twoPi * static_cast<float>(side)
            / static_cast<float>(numSides);
        const float x = offset.x + radiusX * std::cos(angle);
        const float y = offset.y + radiusY * std::sin(angle);
        const int next = (side + 1) % numSides;

        vertsX[side] = x;
        vertsY[side] = y;
        vertsZ[side] = cylinderBounds[0].z;
        vertsX[numSides + side] = x;
        vertsY[numSides + side] = y;
        vertsZ[numSides + side] = cylinderBounds[1].z;

        edges[side].v[0] = static_cast<std::uint16_t>(side);
        edges[side].v[1] = static_cast<std::uint16_t>(next);
        edges[numSides + side].v[0] = static_cast<std::uint16_t>(numSides + side);
        edges[numSides + side].v[1] = static_cast<std::uint16_t>(numSides + next);
        edges[2 * numSides + side].v[0] = static_cast<std::uint16_t>(side);
        edges[2 * numSides + side].v[1] = static_cast<std::uint16_t>(numSides + side);

        numPolyEdges[side] = 4;
        polyEdges[side][0] = static_cast<std::uint8_t>(side);
        polyEdges[side][1] = static_cast<std::uint8_t>(2 * numSides + next);
        polyEdges[side][2] = static_cast<std::uint8_t>(0x80 | (numSides + side));
        polyEdges[side][3] = static_cast<std::uint8_t>(0x80 | (2 * numSides + side));

        const idVec3 first(vertsX[side], vertsY[side], vertsZ[side]);
        const idVec3 second(vertsX[next], vertsY[next], vertsZ[next]);
        const idVec3 upper(vertsX[numSides + next], vertsY[numSides + next],
            vertsZ[numSides + next]);
        idVec3 normal = (second - first).Cross(upper - first);
        normal.NormalizeFast();
        polyPlaneX[side] = normal.x;
        polyPlaneY[side] = normal.y;
        polyPlaneZ[side] = normal.z;
        polyPlaneW[side] = -normal.Dot(first);
    }

    const int lowerPolygon = numSides;
    const int upperPolygon = numSides + 1;
    numPolyEdges[lowerPolygon] = static_cast<unsigned int>(numSides);
    numPolyEdges[upperPolygon] = static_cast<unsigned int>(numSides);
    for (int side = 0; side < numSides; ++side) {
        polyEdges[lowerPolygon][side] = static_cast<std::uint8_t>(
            0x80 | (numSides - side - 1));
        polyEdges[upperPolygon][side] = static_cast<std::uint8_t>(
            numSides + side);
    }
    polyPlaneX[lowerPolygon] = 0.0f;
    polyPlaneY[lowerPolygon] = 0.0f;
    polyPlaneZ[lowerPolygon] = -1.0f;
    polyPlaneW[lowerPolygon] = cylinderBounds[0].z;
    polyPlaneX[upperPolygon] = 0.0f;
    polyPlaneY[upperPolygon] = 0.0f;
    polyPlaneZ[upperPolygon] = 1.0f;
    polyPlaneW[upperPolygon] = -cylinderBounds[1].z;

    bounds = cylinderBounds;
    isConvex = true;
    CalculateInsetSphereRadius();
    GenerateEdgeNormals();
    ClearUnused();
}

void idTraceModel::SetupCylinder(float height, float width, int numSides) {
    idBounds cylinderBounds;
    const float halfWidth = width * 0.5f;
    const float halfHeight = height * 0.5f;
    cylinderBounds[0].Set(-halfWidth, -halfWidth, -halfHeight);
    cylinderBounds[1].Set(halfWidth, halfWidth, halfHeight);
    SetupCylinder(cylinderBounds, numSides);
}

void idTraceModel::Shrink(float amount) {
    if (amount <= 0.0f || numVerts == 0 || numPolys == 0) {
        return;
    }

    // Shrinking a convex trace model moves every supporting plane inward.
    // Project each incident vertex onto the moved half-spaces; repeating the
    // projection converges exactly for orthogonal primitives and closely for
    // the low-sided convex models used by collision traces.
    for (unsigned int vertex = 0; vertex < numVerts; ++vertex) {
        idVec3 point(vertsX[vertex], vertsY[vertex], vertsZ[vertex]);
        for (int iteration = 0; iteration < 8; ++iteration) {
            for (unsigned int polygon = 0; polygon < numPolys; ++polygon) {
                bool incident = false;
                for (unsigned int polygonEdge = 0;
                        polygonEdge < numPolyEdges[polygon]; ++polygonEdge) {
                    const std::uint8_t encoded = polyEdges[polygon][polygonEdge];
                    const unsigned int edgeIndex = encoded & 0x7Fu;
                    if (edgeIndex >= numEdges) {
                        continue;
                    }
                    if (edges[edgeIndex].v[0] == vertex
                            || edges[edgeIndex].v[1] == vertex) {
                        incident = true;
                        break;
                    }
                }
                if (!incident) {
                    continue;
                }
                const idVec3 normal(polyPlaneX[polygon], polyPlaneY[polygon],
                    polyPlaneZ[polygon]);
                const float distance = normal.Dot(point)
                    + polyPlaneW[polygon] + amount;
                point = point - normal * distance;
            }
        }
        vertsX[vertex] = point.x;
        vertsY[vertex] = point.y;
        vertsZ[vertex] = point.z;
    }
    for (unsigned int polygon = 0; polygon < numPolys; ++polygon) {
        polyPlaneW[polygon] += amount;
    }

    bounds[0].Set(vertsX[0], vertsY[0], vertsZ[0]);
    bounds[1] = bounds[0];
    for (unsigned int vertex = 1; vertex < numVerts; ++vertex) {
        bounds[0].x = (std::min)(bounds[0].x, vertsX[vertex]);
        bounds[0].y = (std::min)(bounds[0].y, vertsY[vertex]);
        bounds[0].z = (std::min)(bounds[0].z, vertsZ[vertex]);
        bounds[1].x = (std::max)(bounds[1].x, vertsX[vertex]);
        bounds[1].y = (std::max)(bounds[1].y, vertsY[vertex]);
        bounds[1].z = (std::max)(bounds[1].z, vertsZ[vertex]);
    }
    CalculateInsetSphereRadius();
    GenerateEdgeNormals();
}

void idTraceModel::GetMassProperties(float density, float& mass,
        idVec3& centerOfMass, idMat3& inertiaTensor) const {
    double volume = 0.0;
    double first[3] = {};
    double second[3] = {};
    double product[3] = {}; // xy, yz, zx

    const auto vertexForEdge = [this](std::uint8_t encoded) {
        const unsigned int edgeIndex = encoded & 0x7Fu;
        const bool reversed = (encoded & 0x80u) != 0;
        const unsigned int vertex = edgeIndex < numEdges
            ? edges[edgeIndex].v[reversed ? 1 : 0] : 0;
        return idVec3(vertsX[vertex], vertsY[vertex], vertsZ[vertex]);
    };

    for (unsigned int polygon = 0; polygon < numPolys; ++polygon) {
        if (numPolyEdges[polygon] < 3) {
            continue;
        }
        const idVec3 a = vertexForEdge(polyEdges[polygon][0]);
        for (unsigned int triangle = 1;
                triangle + 1 < numPolyEdges[polygon]; ++triangle) {
            const idVec3 b = vertexForEdge(polyEdges[polygon][triangle]);
            const idVec3 c = vertexForEdge(polyEdges[polygon][triangle + 1]);
            const double tetraVolume = static_cast<double>(a.Dot(b.Cross(c))) / 6.0;
            volume += tetraVolume;
            first[0] += tetraVolume * (a.x + b.x + c.x) / 4.0;
            first[1] += tetraVolume * (a.y + b.y + c.y) / 4.0;
            first[2] += tetraVolume * (a.z + b.z + c.z) / 4.0;

            const double coordinates[3][3] = {
                { a.x, b.x, c.x }, { a.y, b.y, c.y }, { a.z, b.z, c.z }
            };
            for (int axis = 0; axis < 3; ++axis) {
                const double x = coordinates[axis][0];
                const double y = coordinates[axis][1];
                const double z = coordinates[axis][2];
                second[axis] += tetraVolume * (x * x + y * y + z * z
                    + x * y + x * z + y * z) / 10.0;
            }
            const int firstAxis[3] = { 0, 1, 2 };
            const int secondAxis[3] = { 1, 2, 0 };
            for (int pair = 0; pair < 3; ++pair) {
                const double* p = coordinates[firstAxis[pair]];
                const double* q = coordinates[secondAxis[pair]];
                product[pair] += tetraVolume * (
                    2.0 * (p[0] * q[0] + p[1] * q[1] + p[2] * q[2])
                    + p[0] * q[1] + p[1] * q[0]
                    + p[0] * q[2] + p[2] * q[0]
                    + p[1] * q[2] + p[2] * q[1]) / 20.0;
            }
        }
    }

    if (std::fabs(volume) < 1.0e-12) {
        mass = 1.0f;
        centerOfMass.Zero();
        inertiaTensor = idMat3(1.0f);
        return;
    }
    if (volume < 0.0) {
        volume = -volume;
        for (int axis = 0; axis < 3; ++axis) {
            first[axis] = -first[axis];
            second[axis] = -second[axis];
            product[axis] = -product[axis];
        }
    }

    centerOfMass.Set(static_cast<float>(first[0] / volume),
        static_cast<float>(first[1] / volume),
        static_cast<float>(first[2] / volume));
    mass = static_cast<float>(volume * density);
    const double scaledDensity = density;
    double ixx = scaledDensity * (second[1] + second[2]);
    double iyy = scaledDensity * (second[0] + second[2]);
    double izz = scaledDensity * (second[0] + second[1]);
    double ixy = -scaledDensity * product[0];
    double iyz = -scaledDensity * product[1];
    double izx = -scaledDensity * product[2];

    ixx -= mass * (centerOfMass.y * centerOfMass.y
        + centerOfMass.z * centerOfMass.z);
    iyy -= mass * (centerOfMass.x * centerOfMass.x
        + centerOfMass.z * centerOfMass.z);
    izz -= mass * (centerOfMass.x * centerOfMass.x
        + centerOfMass.y * centerOfMass.y);
    ixy += mass * centerOfMass.x * centerOfMass.y;
    iyz += mass * centerOfMass.y * centerOfMass.z;
    izx += mass * centerOfMass.z * centerOfMass.x;

    inertiaTensor = idMat3(
        static_cast<float>(ixx), static_cast<float>(ixy), static_cast<float>(izx),
        static_cast<float>(ixy), static_cast<float>(iyy), static_cast<float>(iyz),
        static_cast<float>(izx), static_cast<float>(iyz), static_cast<float>(izz));
}
