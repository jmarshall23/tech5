#include "models/cuttable/triangleinterpolator.h"

#include "idlib/color.h"

#include <algorithm>
#include <cmath>
#include <cstring>

namespace {

idVec2 Project(const idVec3& point, const idVec3& left, const idVec3& down) {
    return idVec2(point.Dot(left), point.Dot(down));
}

idVec2 Subtract(const idVec2& a, const idVec2& b) {
    return idVec2(a.x - b.x, a.y - b.y);
}

float Dot(const idVec2& a, const idVec2& b) {
    return a.x * b.x + a.y * b.y;
}

std::uint32_t VertexColor(const idDrawVert& vertex) {
    return static_cast<std::uint32_t>(vertex.color[0]) |
        (static_cast<std::uint32_t>(vertex.color[1]) << 8) |
        (static_cast<std::uint32_t>(vertex.color[2]) << 16) |
        (static_cast<std::uint32_t>(vertex.color[3]) << 24);
}

void BuildNormalVectors(const idVec3& normal, idVec3& left, idVec3& down) {
    const float horizontal = normal.x * normal.x + normal.y * normal.y;
    if (horizontal > 1.0e-20f) {
        const float inverse = 1.0f / std::sqrt(horizontal);
        left.Set(-normal.y * inverse, normal.x * inverse, 0.0f);
    } else {
        left.Set(1.0f, 0.0f, 0.0f);
    }
    down = normal.Cross(left);
    down.NormalizeFast();
}

} // namespace

idTriangleInterpolator::idTriangleInterpolator()
    : triangles(), refVert(), refNormal(), refLeft(), refDown() {
    Clear();
}

void idTriangleInterpolator::Clear() {
    triangles.Clear();
    std::memset(&refVert, 0, sizeof(refVert));
    refNormal.Zero();
    refLeft.Zero();
    refDown.Zero();
}

std::uint32_t idTriangleInterpolator::InterpolateColor(
        const Triangle_t& triangle, const float u, const float v) {
    idVec4 c0;
    idVec4 c1;
    idVec4 c2;
    idColor::UnpackColor(triangle.c0, c0);
    idColor::UnpackColor(triangle.c1, c1);
    idColor::UnpackColor(triangle.c2, c2);
    const float w0 = 1.0f - u - v;
    idVec4 result;
    result.x = c0.x * w0 + c1.x * u + c2.x * v;
    result.y = c0.y * w0 + c1.y * u + c2.y * v;
    result.z = c0.z * w0 + c1.z * u + c2.z * v;
    result.w = c0.w * w0 + c1.w * u + c2.w * v;
    return idColor::PackColor(result);
}

bool idTriangleInterpolator::Interpolate(const idVec2& point,
        idDrawVert& vertex, idVec2& outputST) const {
    constexpr float epsilon = 1.1920929e-7f;
    for (int index = 0; index < triangles.Num(); ++index) {
        const Triangle_t& triangle = triangles[index];
        const idVec2 delta(point.x - triangle.xy.x,
            point.y - triangle.xy.y);
        const float d20 = Dot(delta, triangle.v0);
        const float d21 = Dot(delta, triangle.v1);
        const float u = (triangle.d11 * d20 - triangle.d01 * d21) *
            triangle.invDenom;
        const float v = (triangle.d00 * d21 - triangle.d01 * d20) *
            triangle.invDenom;
        if (u < -epsilon || v < -epsilon || u + v > 1.0f + epsilon)
            continue;

        vertex = refVert;
        const float referenceLeft = refVert.xyz.Dot(refLeft);
        const float referenceDown = refVert.xyz.Dot(refDown);
        vertex.xyz = refVert.xyz + refLeft * (point.x - referenceLeft) +
            refDown * (point.y - referenceDown);
        vertex.st.Set(
            triangle.st[0].x + triangle.st0[0].x * u + triangle.st1[0].x * v,
            triangle.st[0].y + triangle.st0[0].y * u + triangle.st1[0].y * v);
        outputST.Set(
            triangle.st[1].x + triangle.st0[1].x * u + triangle.st1[1].x * v,
            triangle.st[1].y + triangle.st0[1].y * u + triangle.st1[1].y * v);
        const std::uint32_t color = InterpolateColor(triangle, u, v);
        vertex.color[0] = static_cast<std::uint8_t>(color);
        vertex.color[1] = static_cast<std::uint8_t>(color >> 8);
        vertex.color[2] = static_cast<std::uint8_t>(color >> 16);
        vertex.color[3] = static_cast<std::uint8_t>(color >> 24);
        return true;
    }
    return false;
}

void idTriangleInterpolator::AddTriangle(const idVec3& left,
        const idVec3& down, const idDrawVert& vertex0,
        const idDrawVert& vertex1, const idDrawVert& vertex2,
        const idVec2& orgST0, const idVec2& orgST1,
        const idVec2& orgST2) {
    Triangle_t triangle{};
    const idVec2 point0 = Project(vertex0.xyz, left, down);
    const idVec2 point1 = Project(vertex1.xyz, left, down);
    const idVec2 point2 = Project(vertex2.xyz, left, down);
    triangle.xy = point0;
    triangle.v0 = Subtract(point1, point0);
    triangle.v1 = Subtract(point2, point0);
    triangle.d00 = Dot(triangle.v0, triangle.v0);
    triangle.d01 = Dot(triangle.v0, triangle.v1);
    triangle.d11 = Dot(triangle.v1, triangle.v1);
    const float denominator = triangle.d00 * triangle.d11 -
        triangle.d01 * triangle.d01;
    if (std::fabs(denominator) <= 1.0e-20f) return;
    triangle.invDenom = 1.0f / denominator;
    const float area = triangle.v0.x * triangle.v1.y -
        triangle.v0.y * triangle.v1.x;
    triangle.invArea = std::fabs(area) > 1.0e-20f ? 1.0f / area : 0.0f;

    triangle.st[0] = vertex0.st;
    triangle.st0[0] = Subtract(vertex1.st, vertex0.st);
    triangle.st1[0] = Subtract(vertex2.st, vertex0.st);
    triangle.st[1] = orgST0;
    triangle.st0[1] = Subtract(orgST1, orgST0);
    triangle.st1[1] = Subtract(orgST2, orgST0);
    triangle.c0 = VertexColor(vertex0);
    triangle.c1 = VertexColor(vertex1);
    triangle.c2 = VertexColor(vertex2);
    triangles.Append(triangle);
}

void idTriangleInterpolator::AddTriangles(const idDrawVert* const verts,
        const idVec2* const textureCoordinates,
        const std::uint16_t* const indices, const int numIndices) {
    Clear();
    if (verts == nullptr || textureCoordinates == nullptr || indices == nullptr ||
            numIndices < 3) {
        return;
    }

    const idDrawVert& first = verts[indices[0]];
    const idDrawVert& second = verts[indices[1]];
    const idDrawVert& third = verts[indices[2]];
    refNormal = (second.xyz - first.xyz).Cross(third.xyz - first.xyz);
    if (refNormal.NormalizeFast() <= 1.0e-20f) return;
    BuildNormalVectors(refNormal, refLeft, refDown);
    refVert = first;
    triangles.PreAllocate(numIndices / 3);
    for (int index = 0; index + 2 < numIndices; index += 3) {
        const std::uint16_t i0 = indices[index];
        const std::uint16_t i1 = indices[index + 1];
        const std::uint16_t i2 = indices[index + 2];
        AddTriangle(refLeft, refDown, verts[i0], verts[i1], verts[i2],
            textureCoordinates[i0], textureCoordinates[i1],
            textureCoordinates[i2]);
    }
}
