#pragma once

#include "idlib/containers/list.h"
#include "idlib/geometry/drawvert.h"
#include "idlib/math/vector.h"

#include <cstdint>

class alignas(16) idTriangleInterpolator {
public:
    struct Triangle_t {
        idVec2 xy;
        idVec2 st[2];
        idVec2 st0[2];
        idVec2 st1[2];
        idVec2 v0;
        idVec2 v1;
        float d00;
        float d01;
        float d11;
        float invDenom;
        float invArea;
        std::uint32_t c0;
        std::uint32_t c1;
        std::uint32_t c2;
    };

    idTriangleInterpolator();
    void Clear();
    bool Interpolate(const idVec2& point, idDrawVert& vert, idVec2& st) const;
    void AddTriangles(const idDrawVert* verts, const idVec2* st,
        const std::uint16_t* indices, int numIndices);

    idList<Triangle_t, 5> triangles;
    idDrawVert refVert;
    idVec3 refNormal;
    idVec3 refLeft;
    idVec3 refDown;

private:
    static std::uint32_t InterpolateColor(const Triangle_t& triangle,
        float u, float v);
    void AddTriangle(const idVec3& left, const idVec3& down,
        const idDrawVert& v0, const idDrawVert& v1, const idDrawVert& v2,
        const idVec2& orgST0, const idVec2& orgST1, const idVec2& orgST2);
};
