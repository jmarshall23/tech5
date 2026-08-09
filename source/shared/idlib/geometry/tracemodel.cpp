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
