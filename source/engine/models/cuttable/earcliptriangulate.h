#pragma once

#include "models/cuttable/contourinfo.h"

#include "idlib/containers/hashindex.h"
#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/math/vectori.h"

#include <cstdint>

class idEarClipTriangulate {
public:
    struct Vertex_t {
        std::int16_t index;
        std::int16_t prevVertex;
        std::int16_t nextVertex;
        std::int16_t prevEar;
        std::int16_t nextEar;
        union SharedIndex {
            std::int16_t convex;
            std::int16_t reflex;
            std::int16_t value;
        } prevShared;
        SharedIndex nextShared;
        std::uint16_t freeBits : 14;
        std::uint16_t isEar : 1;
        std::uint16_t isConvex : 1;
    };

    struct alignas(4) Contour_t {
        idList<std::int16_t, 5> indices;
        float valueMax;
        std::int16_t indexMax;

        Contour_t() : indices(), valueMax(0.0f), indexMax(-1) {}
    };

    class IndexMap {
    public:
        idHashIndex hashIndex;
        idList<std::int16_t, 5> indices;
    };

    idEarClipTriangulate();
    ~idEarClipTriangulate();

    void SetOuterFromPoints(const idList<idVec2, 5>& points);
    void SetOuterFromPoints(const idList<idVec2i, 5>& points);
    void SetOuterFromContour(const Contour* contour);
    void AddInnerFromPoints(const idList<idVec2, 5>& points);
    void AddInnerFromPoints(const idList<idVec2i, 5>& points);
    void AddInnerFromContour(const Contour* contour);
    void Triangulate();
    void BuildGeometry(const idVec3& normal, idList<idVec2, 5>& outputPositions,
        idList<std::uint16_t, 5>& outputIndices) const;

    static bool IsClockwise(const idList<idVec2, 5>& points);

    idList<idVec2, 5> positions;
    idList<Vertex_t, 5> vertices;
    idList<Contour_t*, 5> contours;
    idList<std::int16_t, 5> indices;
    idList<std::int16_t, 5> triangles;
    IndexMap indexMap;
    int headConvex;
    int tailConvex;
    int headReflex;
    int tailReflex;
    int headEar;
    int tailEar;
    int maxIndex;

private:
    void ClearContours();
    void SetContour(const idList<idVec2, 5>& points, bool outer);
    void Process();
    void RemapIndices();
    void RemoveZeroAreas();
    void CreateVertices();
    void CreateSimplePolygon();
    void CombineContours(const Contour_t* contour,
        const idList<std::int16_t, 5>& source,
        idList<std::int16_t, 5>& destination);
    void RemoveReflex(int index);
    bool UpdateEar(int vertexIndex);
    int TriangleQuery(const idVec2& point, const idVec2& v0,
        const idVec2& v1, const idVec2& v2) const;
    static int LineTest(const idVec2& point, const idVec2& v0,
        const idVec2& v1);
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idEarClipTriangulate::Vertex_t) == 16,
    "Recovered ear-clip vertex ABI changed");
static_assert(sizeof(idEarClipTriangulate::Contour_t) == 24,
    "Recovered ear-clip contour ABI changed");
static_assert(sizeof(idEarClipTriangulate) == 156,
    "Recovered idEarClipTriangulate ABI changed");
#endif
