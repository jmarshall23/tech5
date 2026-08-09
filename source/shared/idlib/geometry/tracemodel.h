#pragma once

#include "../bv/bounds.h"
#include "../math/matrix.h"

#include <cstddef>
#include <cstdint>

enum traceModel_t : int {
    TRM_INVALID = 0,
    TRM_BOX = 1,
    TRM_OCTAHEDRON = 2,
    TRM_DODECAHEDRON = 3,
    TRM_CYLINDER = 4,
    TRM_CONE = 5,
    TRM_BONE = 6,
    TRM_POLYGON = 7,
    TRM_POLYGONVOLUME = 8,
    TRM_CUSTOM = 9
};

struct traceModelEdge_t {
    std::uint16_t v[2];
};

struct polygonIntegrals_t;
struct projectionIntegrals_t;
struct volumeIntegrals_t;

class idTraceModel {
public:
    static void* operator new(std::size_t size);
    static void operator delete(void* memory);

    void SetupBox(const idBounds& bounds);
    void SetupBox(float size);
    void SetupOctahedron(const idBounds& bounds);
    void SetupDodecahedron(const idBounds& bounds);
    void SetupCylinder(const idBounds& bounds, int numSides);
    void SetupCylinder(float height, float width, int numSides);
    void SetupCone(const idBounds& bounds, int numSides);
    void SetupBone(float length, float width);
    void SetupPolygon(const idVec3* vertices, int count);
    void SetupPolygonVolume(const idVec3* vertices, int count,
        const idVec3& depth);
    void ClearUnused();
    void Translate(const idVec3& translation);
    void Rotate(const idMat3& rotation);
    void Scale(const idVec3& scale);
    void Shrink(float amount);
    void CalculateInsetSphereRadius();
    int GenerateEdgeNormals();
    void TestConvexity();
    bool Compare(const idTraceModel& other) const;
    bool ContainsPoint(const idVec3& point) const;
    bool HasFlaps() const;
    bool IsClosedSurface() const;
    void GetMassProperties(float density, float& mass,
        idVec3& centerOfMass, idMat3& inertiaTensor) const;

    float vertsX[32];
    float vertsY[32];
    float vertsZ[32];
    float edgeNormalX[32];
    float edgeNormalY[32];
    float edgeNormalZ[32];
    float polyPlaneX[16];
    float polyPlaneY[16];
    float polyPlaneZ[16];
    float polyPlaneW[16];
    std::uint8_t polyEdges[16][16];
    unsigned int numPolyEdges[16];
    traceModelEdge_t edges[32];
    traceModel_t type;
    unsigned int numVerts;
    unsigned int numEdges;
    unsigned int numPolys;
    unsigned int maxPolyEdges;
    idVec3 offset;
    idBounds bounds;
    float radius;
    bool isConvex;
    std::uint8_t pad[3];

private:
    void CalculatePolygonPlanes();
    void ExtendPolygonToVolume(const idVec3& depth);
    void InitBone();
    void InitBox();
    void InitDodecahedron();
    void InitOctahedron();
    void PolygonIntegrals(int poly, int a, int b, int c,
        polygonIntegrals_t& integrals) const;
    void ProjectionIntegrals(int poly, int a, int b,
        projectionIntegrals_t& integrals) const;
    void VolumeIntegrals(volumeIntegrals_t& integrals) const;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(traceModelEdge_t) == 4,
    "Recovered traceModelEdge_t ABI changed");
static_assert(sizeof(idTraceModel) == 1536,
    "Recovered idTraceModel ABI changed");
#endif
