#include "models/discreteanimation/rendermodelmanyboxes.h"

#include <cstring>
#include <algorithm>
#include <cmath>

namespace {

idVec3 Normalize(const idVec3& value) {
    const float lengthSquared = value.LengthSqr();
    return lengthSquared > 1.0e-30f
        ? value * (1.0f / std::sqrt(lengthSquared))
        : idVec3(0.0f, 0.0f, 1.0f);
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

} // namespace

void CreateDrawVertNormal(std::uint8_t (&encoded)[4],
        const idVec3& normal) {
    for (int component = 0; component < 3; ++component) {
        const int value = static_cast<int>(
            (normal[component] + 1.0f) * 127.5f + 0.5f);
        encoded[component] = static_cast<std::uint8_t>((std::max)(0,
            (std::min)(255, value)));
    }
    encoded[3] = 0;
}

idRenderModelManyBoxes::UpdateCallback idRenderModelManyBoxes::updateCallback =
    nullptr;

idRenderModelManyBoxes::idRenderModelManyBoxes()
    : gameTime(0), material(nullptr) {
    std::memset(vertexBuffers, 0, sizeof(vertexBuffers));
    std::memset(&triangles, 0, sizeof(triangles));
    std::memset(&indexBuffer, 0, sizeof(indexBuffer));
    g.addAlways = 1;
    g.noShadow = 1;
}

idRenderModelManyBoxes::~idRenderModelManyBoxes() {
    delete[] triangles.verts;
    delete[] triangles.indexes;
    triangles.verts = nullptr;
    triangles.indexes = nullptr;
}

void idRenderModelManyBoxes::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

bool idRenderModelManyBoxes::UpdateInView(const idRenderView* currentView,
    const idRenderView* nextView, idRenderModelUpdateTools* tools) {
    return updateCallback != nullptr
        ? updateCallback(this, currentView, nextView, tools)
        : false;
}

bool idRenderModelManyBoxes::CommitSubclass() {
    surfaces.Clear();
    delete[] triangles.verts;
    delete[] triangles.indexes;
    triangles.verts = nullptr;
    triangles.indexes = nullptr;
    // The original double-buffered vertex allocation held 24,576 vertices,
    // or 1,024 boxes at 24 vertices per box.
    const int boxCount = (std::min)(boxes.Num(), 1024);
    triangles.numVerts = boxCount * 24;
    triangles.numIndexes = boxCount * 36;
    triangles.vertexMask = triangles.cpuVertexMask = 0x1Fu;
    triangles.allowGpuHosting = true;
    triangles.verts = triangles.numVerts > 0
        ? new idDrawVert[triangles.numVerts] : nullptr;
    triangles.indexes = triangles.numIndexes > 0
        ? new std::uint16_t[triangles.numIndexes] : nullptr;
    ClearBounds(triangles.bounds);

    const int faceAxis[6] = {0, 0, 1, 1, 2, 2};
    const float faceSign[6] = {1.0f, -1.0f, 1.0f, -1.0f,
        1.0f, -1.0f};
    const int uAxis[6] = {1, 1, 0, 0, 0, 0};
    const int vAxis[6] = {2, 2, 2, 2, 1, 1};
    const float corners[4][2] = {
        {-1.0f, -1.0f}, {1.0f, -1.0f},
        {1.0f, 1.0f}, {-1.0f, 1.0f}
    };
    const std::uint16_t quadIndexes[6] = {0, 1, 2, 0, 2, 3};
    for (int boxIndex = 0; boxIndex < boxCount; ++boxIndex) {
        const box_t& box = boxes[boxIndex];
        for (int face = 0; face < 6; ++face) {
            const int vertexBase = boxIndex * 24 + face * 4;
            const int indexBase = boxIndex * 36 + face * 6;
            const idVec3 normal = Normalize(box.orientation[faceAxis[face]] *
                faceSign[face]);
            const idVec3 tangent = Normalize(box.orientation[uAxis[face]]);
            idVec3 bitangent = Normalize(box.orientation[vAxis[face]]);
            if (normal.Dot(tangent.Cross(bitangent)) < 0.0f)
                bitangent = -bitangent;
            const idVec3 center = box.position +
                box.orientation[faceAxis[face]] *
                    (faceSign[face] * box.radius);
            for (int corner = 0; corner < 4; ++corner) {
                idDrawVert& vertex = triangles.verts[vertexBase + corner];
                std::memset(&vertex, 0, sizeof(vertex));
                vertex.xyz = center + box.orientation[uAxis[face]] *
                    (corners[corner][0] * box.radius) +
                    box.orientation[vAxis[face]] *
                    (corners[corner][1] * box.radius);
                vertex.st.Set(corners[corner][0] > 0.0f ? 1.0f : 0.0f,
                    corners[corner][1] > 0.0f ? 1.0f : 0.0f);
                vertex.SetNormal(normal);
                vertex.SetTangent(tangent);
                vertex.SetBiTangent(bitangent);
                std::memset(vertex.color, 255, sizeof(vertex.color));
                AddPoint(triangles.bounds, vertex.xyz);
            }
            for (int index = 0; index < 6; ++index)
                triangles.indexes[indexBase + index] =
                    static_cast<std::uint16_t>(vertexBase +
                        quadIndexes[index]);
        }
    }
    if (boxCount == 0) {
        triangles.bounds[0].Zero();
        triangles.bounds[1].Zero();
    }
    idRenderModelSurface surface{};
    surface.material = material;
    surface.geometry = &triangles;
    surface.geometryIsReference = true;
    surfaces.Append(surface);
    referenceBounds = triangles.bounds;
    return false;
}
