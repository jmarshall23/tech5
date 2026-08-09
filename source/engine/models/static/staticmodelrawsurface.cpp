#include "models/static/staticmodelrawsurface.h"

#include "models/static/staticmodel.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

namespace {

idVec3 Normalize(const idVec3& value) {
    const float lengthSquared = value.LengthSqr();
    return lengthSquared > 1.0e-30f
        ? value * (1.0f / std::sqrt(lengthSquared))
        : idVec3(0.0f, 0.0f, 1.0f);
}

idVec3 TriangleNormal(const idVec3& a, const idVec3& b,
        const idVec3& c) {
    return Normalize((b - a).Cross(c - a));
}

void ClearBounds(idBounds& bounds) {
    bounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    bounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
}

void AddPoint(idBounds& bounds, const idVec3& point) {
    for (int axis = 0; axis < 3; ++axis) {
        bounds[0][axis] = (std::min)(bounds[0][axis], point[axis]);
        bounds[1][axis] = (std::max)(bounds[1][axis], point[axis]);
    }
}

unsigned char ColorByte(const unsigned int color, const int component) {
    return static_cast<unsigned char>((color >> (component * 8)) & 0xFFu);
}

} // namespace

idRawSurface::idRawSurface()
    : material(nullptr), materialNum(0), generateNormals(false),
      normalEpsilon(0.999f), pvList(nullptr), ptvList(nullptr),
      pMorphList(nullptr) {
}

void idRawSurface::InitHash(const idList<idVec3, 5>& positions,
        const idList<idVec2, 5>& texCoords,
        const idList<idVec3, 5>& morphPositions) {
    pvList = &positions;
    ptvList = &texCoords;
    pMorphList = &morphPositions;
    vertHash.SetNum(positions.Num());
    for (int index = 0; index < vertHash.Num(); ++index)
        vertHash[index] = -1;
}

bool BuildAveragedSurfaceNormals(const idList<idVec3, 5>& vertices,
        const idList<int, 5>& indexes,
        idList<idVec3, 5>& averagedSurfaceNormals) {
    averagedSurfaceNormals.SetNum(vertices.Num());
    for (int index = 0; index < averagedSurfaceNormals.Num(); ++index)
        averagedSurfaceNormals[index].Zero();
    for (int index = 0; index + 2 < indexes.Num(); index += 3) {
        const int a = indexes[index];
        const int b = indexes[index + 1];
        const int c = indexes[index + 2];
        if (a < 0 || b < 0 || c < 0 || a >= vertices.Num() ||
            b >= vertices.Num() || c >= vertices.Num()) return false;
        const idVec3 normal = TriangleNormal(vertices[a], vertices[b],
            vertices[c]);
        averagedSurfaceNormals[a] = averagedSurfaceNormals[a] + normal;
        averagedSurfaceNormals[b] = averagedSurfaceNormals[b] + normal;
        averagedSurfaceNormals[c] = averagedSurfaceNormals[c] + normal;
    }
    for (int index = 0; index < averagedSurfaceNormals.Num(); ++index)
        averagedSurfaceNormals[index] = Normalize(averagedSurfaceNormals[index]);
    return true;
}

void idRawSurface::GenerateNormals() {
    if (pvList == nullptr) return;
    idList<int, 5> positionIndexes;
    positionIndexes.SetNum(indexes.Num());
    for (int index = 0; index < indexes.Num(); ++index) {
        const int rawIndex = indexes[index];
        if (rawIndex < 0 || rawIndex >= verts.Num()) return;
        positionIndexes[index] = verts[rawIndex].v;
    }
    idList<idVec3, 5> normals;
    if (!BuildAveragedSurfaceNormals(*pvList, positionIndexes, normals))
        return;
    for (int index = 0; index < verts.Num(); ++index) {
        if (verts[index].v >= 0 && verts[index].v < normals.Num())
            verts[index].normal = normals[verts[index].v];
    }
}

void idRawSurface::InitIndex(const int maxIndexes) {
    if (maxIndexes > 0) {
        indexes.PreAllocate(maxIndexes);
        verts.PreAllocate(maxIndexes);
    }
}

void idRawSurface::DuplicateMirroredVertexes() {
    if (ptvList == nullptr || ptvList->Num() == 0 || indexes.Num() < 3)
        return;
    struct Polarity { bool used[2]{}; int negativeRemap = -1; };
    std::vector<Polarity> polarity(static_cast<std::size_t>(verts.Num()));
    std::vector<bool> negative(static_cast<std::size_t>(indexes.Num() / 3));
    for (int triangle = 0; triangle < indexes.Num() / 3; ++triangle) {
        const matchVert_t& a = verts[indexes[triangle * 3]];
        const matchVert_t& b = verts[indexes[triangle * 3 + 1]];
        const matchVert_t& c = verts[indexes[triangle * 3 + 2]];
        if (a.tv < 0 || b.tv < 0 || c.tv < 0 || a.tv >= ptvList->Num() ||
            b.tv >= ptvList->Num() || c.tv >= ptvList->Num()) continue;
        const idVec2& ta = (*ptvList)[a.tv];
        const idVec2& tb = (*ptvList)[b.tv];
        const idVec2& tc = (*ptvList)[c.tv];
        negative[triangle] = (tc.y - ta.y) * (tb.x - ta.x) -
            (tc.x - ta.x) * (tb.y - ta.y) < 0.0f;
        for (int corner = 0; corner < 3; ++corner)
            polarity[indexes[triangle * 3 + corner]].used[negative[triangle]] = true;
    }
    const int originalCount = verts.Num();
    for (int index = 0; index < originalCount; ++index) {
        if (polarity[index].used[0] && polarity[index].used[1]) {
            polarity[index].negativeRemap = verts.Num();
            verts.Append(verts[index]);
        }
    }
    for (int triangle = 0; triangle < indexes.Num() / 3; ++triangle) {
        if (!negative[triangle]) continue;
        for (int corner = 0; corner < 3; ++corner) {
            int& value = indexes[triangle * 3 + corner];
            if (value >= 0 && value < originalCount &&
                polarity[value].negativeRemap >= 0)
                value = polarity[value].negativeRemap;
        }
    }
}

void idRawSurface::AddVert(const int position, const int texCoord,
        const idVec3& normal, const unsigned int color, const int morph) {
    if (position < 0 || position >= vertHash.Num()) return;
    int match = vertHash[position];
    while (match >= 0) {
        const matchVert_t& candidate = verts[match];
        if (candidate.v == position && candidate.tv == texCoord &&
            candidate.color == color && candidate.morph == morph &&
            (generateNormals || candidate.normal.Dot(normal) > normalEpsilon)) {
            indexes.Append(match);
            return;
        }
        match = candidate.next;
    }
    matchVert_t added{};
    added.next = vertHash[position];
    added.v = position;
    added.tv = texCoord;
    added.morph = morph;
    added.color = color;
    added.normal = normal;
    const int newIndex = verts.Append(added);
    vertHash[position] = newIndex;
    indexes.Append(newIndex);
}

void DeriveVertexTangents(const idList<int, 5>& indexes,
        const idList<idDrawVert, 5>& vertices,
        idList<vertexTangents_t, 5>& tangents) {
    tangents.SetNum(vertices.Num());
    for (int index = 0; index < vertices.Num(); ++index) {
        tangents[index].normal = vertices[index].GetNormal();
        tangents[index].tangents[0].Zero();
        tangents[index].tangents[1].Zero();
    }
    for (int index = 0; index + 2 < indexes.Num(); index += 3) {
        const int ia = indexes[index], ib = indexes[index + 1],
            ic = indexes[index + 2];
        if (ia < 0 || ib < 0 || ic < 0 || ia >= vertices.Num() ||
            ib >= vertices.Num() || ic >= vertices.Num()) continue;
        const idDrawVert& a = vertices[ia];
        const idDrawVert& b = vertices[ib];
        const idDrawVert& c = vertices[ic];
        const idVec3 e1 = b.xyz - a.xyz;
        const idVec3 e2 = c.xyz - a.xyz;
        const float du1 = b.st.x - a.st.x, dv1 = b.st.y - a.st.y;
        const float du2 = c.st.x - a.st.x, dv2 = c.st.y - a.st.y;
        const float determinant = du1 * dv2 - du2 * dv1;
        const float inverse = std::fabs(determinant) > 1.0e-20f
            ? 1.0f / determinant : 0.0f;
        const idVec3 tangent = (e1 * dv2 - e2 * dv1) * inverse;
        const idVec3 bitangent = (e2 * du1 - e1 * du2) * inverse;
        for (const int vertex : {ia, ib, ic}) {
            tangents[vertex].tangents[0] =
                tangents[vertex].tangents[0] + tangent;
            tangents[vertex].tangents[1] =
                tangents[vertex].tangents[1] + bitangent;
        }
    }
    for (int index = 0; index < tangents.Num(); ++index) {
        const idVec3 normal = Normalize(tangents[index].normal);
        tangents[index].normal = normal;
        tangents[index].tangents[0] = Normalize(
            tangents[index].tangents[0] - normal *
            normal.Dot(tangents[index].tangents[0]));
        tangents[index].tangents[1] = Normalize(
            tangents[index].tangents[1] - normal *
            normal.Dot(tangents[index].tangents[1]));
    }
}

void SplitTrianglesForVertexLimit(const idList<int, 5>& indexes,
        const int maxVertices, idList<idSplitResults, 5>& split) {
    split.Clear();
    if (maxVertices < 3) return;
    int cursor = 0;
    int maximumIndex = -1;
    for (int index = 0; index < indexes.Num(); ++index)
        maximumIndex = (std::max)(maximumIndex, indexes[index]);
    while (cursor + 2 < indexes.Num()) {
        idSplitResults result;
        std::vector<int> remap(static_cast<std::size_t>(maximumIndex + 1), -1);
        while (cursor + 2 < indexes.Num()) {
            int needed = 0;
            for (int corner = 0; corner < 3; ++corner) {
                const int value = indexes[cursor + corner];
                if (value < 0 || value > maximumIndex) continue;
                if (remap[value] < 0) ++needed;
            }
            if (result.vertices.Num() + needed > maxVertices &&
                result.indexes.Num() > 0) break;
            for (int corner = 0; corner < 3; ++corner) {
                const int value = indexes[cursor + corner];
                if (value < 0 || value > maximumIndex) continue;
                if (remap[value] < 0) {
                    remap[value] = result.vertices.Num();
                    result.vertices.Append(value);
                }
                result.indexes.Append(remap[value]);
            }
            cursor += 3;
        }
        if (result.indexes.Num() == 0) break;
        split.Append(result);
    }
}

void idRawSurface::MakeSurfaces(idList<idStaticModelSurface, 5>& surfaces) {
    if (indexes.Num() == 0 || pvList == nullptr) return;
    if (generateNormals) GenerateNormals();
    DuplicateMirroredVertexes();

    idList<idDrawVert, 5> drawVertices;
    drawVertices.SetNum(verts.Num());
    for (int index = 0; index < verts.Num(); ++index) {
        idDrawVert& output = drawVertices[index];
        std::memset(&output, 0, sizeof(output));
        const matchVert_t& source = verts[index];
        if (source.v >= 0 && source.v < pvList->Num())
            output.xyz = (*pvList)[source.v];
        if (ptvList != nullptr && source.tv >= 0 &&
            source.tv < ptvList->Num()) output.st = (*ptvList)[source.tv];
        output.SetNormal(source.normal);
        for (int component = 0; component < 4; ++component)
            output.color[component] = ColorByte(source.color, component);
    }
    idList<vertexTangents_t, 5> tangents;
    DeriveVertexTangents(indexes, drawVertices, tangents);
    for (int index = 0; index < drawVertices.Num(); ++index) {
        drawVertices[index].SetNormal(tangents[index].normal);
        drawVertices[index].SetTangent(tangents[index].tangents[0]);
        drawVertices[index].SetBiTangent(tangents[index].tangents[1]);
    }

    idList<idSplitResults, 5> splits;
    SplitTrianglesForVertexLimit(indexes, 0x7FFF, splits);
    for (int splitIndex = 0; splitIndex < splits.Num(); ++splitIndex) {
        const idSplitResults& split = splits[splitIndex];
        idTriangles* geometry = new idTriangles{};
        geometry->generateNormals = generateNormals;
        geometry->allowGpuHosting = true;
        geometry->cpuVertexMask = geometry->vertexMask = 0x1Fu;
        geometry->numVerts = split.vertices.Num();
        geometry->numIndexes = split.indexes.Num();
        geometry->verts = geometry->numVerts > 0
            ? new idDrawVert[geometry->numVerts] : nullptr;
        geometry->indexes = geometry->numIndexes > 0
            ? new std::uint16_t[geometry->numIndexes] : nullptr;
        ClearBounds(geometry->bounds);
        for (int index = 0; index < geometry->numVerts; ++index) {
            geometry->verts[index] = drawVertices[split.vertices[index]];
            AddPoint(geometry->bounds, geometry->verts[index].xyz);
        }
        for (int index = 0; index < geometry->numIndexes; ++index)
            geometry->indexes[index] = static_cast<std::uint16_t>(
                split.indexes[index]);
        idStaticModelSurface surface;
        surface.material = material;
        surface.materialNum = materialNum;
        surface.geometry = geometry;
        surfaces.Append(surface);
    }
}

void EmitRawSurfacesToStaticModel(idList<idRawSurface, 5>& rawSurfaces,
        idStaticModel& model) {
    for (int rawIndex = 0; rawIndex < rawSurfaces.Num(); ++rawIndex) {
        idList<idStaticModelSurface, 5> surfaces;
        rawSurfaces[rawIndex].MakeSurfaces(surfaces);
        for (int surface = 0; surface < surfaces.Num(); ++surface) {
            if (surfaces[surface].geometry != nullptr &&
                surfaces[surface].geometry->numVerts > 0)
                model.AddSurface(surfaces[surface]);
        }
    }
}
