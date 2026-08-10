#include "idlib/geometry/surface.h"

#include <algorithm>
#include <limits>

namespace {

idVec3 RotateSurfaceVector(const idVec3& vector, const idMat3& rotation) {
    return idVec3(
        rotation[0].x * vector.x + rotation[1].x * vector.y
            + rotation[2].x * vector.z,
        rotation[0].y * vector.x + rotation[1].y * vector.y
            + rotation[2].y * vector.z,
        rotation[0].z * vector.x + rotation[1].z * vector.y
            + rotation[2].z * vector.z);
}

} // namespace

idSurface::idSurface() = default;

idSurface::~idSurface() = default;

void idSurface::TranslateSelf(const idVec3& translation) {
    for (int index = 0; index < verts.Num(); ++index) {
        verts[index].xyz = verts[index].xyz + translation;
    }
}

void idSurface::RotateSelf(const idMat3& rotation) {
    for (int index = 0; index < verts.Num(); ++index) {
        idDrawVert& vertex = verts[index];
        const idVec3 normal = RotateSurfaceVector(vertex.GetNormal(),
            rotation);
        const idVec3 tangent = RotateSurfaceVector(vertex.GetTangent(),
            rotation);
        const idVec3 bitangent = RotateSurfaceVector(vertex.GetBiTangent(),
            rotation);
        vertex.xyz = RotateSurfaceVector(vertex.xyz, rotation);
        vertex.SetNormal(normal);
        vertex.SetTangent(tangent);
        vertex.SetBiTangent(bitangent);
    }
}

void idSurface::GetBounds(idBounds& bounds) const {
    if (verts.IsEmpty()) {
        bounds[0].Zero();
        bounds[1].Zero();
        return;
    }
    const float maximum = (std::numeric_limits<float>::max)();
    bounds[0].Set(maximum, maximum, maximum);
    bounds[1].Set(-maximum, -maximum, -maximum);
    for (int index = 0; index < verts.Num(); ++index) {
        for (int axis = 0; axis < 3; ++axis) {
            bounds[0][axis] = (std::min)(bounds[0][axis],
                verts[index].xyz[axis]);
            bounds[1][axis] = (std::max)(bounds[1][axis],
                verts[index].xyz[axis]);
        }
    }
}

void idSurface::GenerateEdgeIndexes() {
    edges.Clear();
    edgeIndexes.Clear();
    if (indexes.Num() < 3) {
        return;
    }
    edgeIndexes.SetNum(indexes.Num());
    for (int triangle = 0; triangle + 2 < indexes.Num(); triangle += 3) {
        for (int side = 0; side < 3; ++side) {
            const int first = indexes[triangle + side];
            const int second = indexes[triangle + ((side + 1) % 3)];
            int edgeIndex = -1;
            bool reversed = false;
            for (int candidate = 0; candidate < edges.Num(); ++candidate) {
                if (edges[candidate].verts[0] == first
                    && edges[candidate].verts[1] == second) {
                    edgeIndex = candidate;
                    break;
                }
                if (edges[candidate].verts[0] == second
                    && edges[candidate].verts[1] == first) {
                    edgeIndex = candidate;
                    reversed = true;
                    break;
                }
            }
            if (edgeIndex < 0) {
                surfaceEdge_t edge = {{first, second}, {-1, -1}};
                edgeIndex = edges.Append(edge);
            }
            surfaceEdge_t& edge = edges[edgeIndex];
            edge.tris[reversed ? 1 : 0] = triangle / 3;
            edgeIndexes[triangle + side] = reversed
                ? -(edgeIndex + 1) : edgeIndex + 1;
        }
    }
}
