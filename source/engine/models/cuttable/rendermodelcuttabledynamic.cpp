#include "models/cuttable/rendermodelcuttabledynamic.h"

#include <algorithm>
#include <cstring>
#include <new>

idRenderModelCuttableDynamic::BufferUploadCallback
    idRenderModelCuttableDynamic::bufferUploadCallback = nullptr;

idRenderModelCuttableDynamic::idRenderModelCuttableDynamic() {
    g.noShadow = 1;
    g.addAlways = 1;
    g.noGPUocclusionTest = 1;
    SetMaxSurfaces(2);

    idTriangles* geometry = new (std::nothrow) idTriangles{};
    idVertexBuffer* stMap = new (std::nothrow) idVertexBuffer{};
    if (geometry != nullptr) {
        geometry->vertexMask = 31;
        geometry->cpuVertexMask = 31;
        geometry->vertexBuffer.usage = BU_DYNAMIC;
        geometry->vertexBuffer.size = MAX_VERTICES * sizeof(idDrawVert);
        geometry->indexBuffer.usage = BU_DYNAMIC;
        geometry->indexBuffer.size = MAX_INDICES * sizeof(std::uint16_t);
    }
    if (stMap != nullptr) {
        stMap->usage = BU_DYNAMIC;
        stMap->size = MAX_VERTICES * sizeof(idVec2);
    }

    idRenderModelSurface depthSurface{};
    depthSurface.geometry = geometry;
    depthSurface.geometryIsReference = true;
    depthSurface.stMap = stMap;
    AddSurface(depthSurface);

    idRenderModelSurface renderSurface{};
    renderSurface.geometry = geometry;
    renderSurface.geometryIsReference = false;
    AddSurface(renderSurface);
    FinishSurfaces();
}

idRenderModelCuttableDynamic::~idRenderModelCuttableDynamic() {
    if (surfaces.Num() > 0 && surfaces[0].stMap != nullptr) {
        delete[] static_cast<idVec2*>(surfaces[0].stMap->apiObject);
        surfaces[0].stMap->apiObject = nullptr;
        delete surfaces[0].stMap;
        surfaces[0].stMap = nullptr;
    }
    idTriangles* geometry = surfaces.Num() > 1
        ? surfaces[1].geometry : (surfaces.Num() > 0
            ? surfaces[0].geometry : nullptr);
    if (geometry != nullptr) {
        delete[] geometry->verts;
        delete[] geometry->indexes;
        geometry->verts = nullptr;
        geometry->indexes = nullptr;
        delete geometry;
    }
    for (int index = 0; index < surfaces.Num(); ++index)
        surfaces[index].geometry = nullptr;
}

void idRenderModelCuttableDynamic::SetBufferUploadCallback(
        BufferUploadCallback callback) {
    bufferUploadCallback = callback;
}

void idRenderModelCuttableDynamic::UploadRenderGeometry(
        const idMaterial* material,
        const idList<idDrawVert, 5>& vertices,
        const idList<std::uint16_t, 5>& indices) {
    if (surfaces.Num() < 2 || surfaces[1].geometry == nullptr) return;
    idRenderModelSurface& surface = surfaces[1];
    idTriangles* geometry = surface.geometry;
    surface.material = material;

    const int vertexCount = std::min(vertices.Num(),
        static_cast<int>(MAX_VERTICES));
    delete[] geometry->verts;
    delete[] geometry->indexes;
    geometry->verts = vertexCount > 0
        ? new (std::nothrow) idDrawVert[vertexCount] : nullptr;
    if (vertexCount > 0 && geometry->verts == nullptr) {
        geometry->numVerts = geometry->numIndexes = 0;
        return;
    }
    if (vertexCount > 0)
        std::memcpy(geometry->verts, vertices.Ptr(),
            vertexCount * sizeof(idDrawVert));

    int validIndexCount = 0;
    const int inputIndexCount = std::min(indices.Num(),
        static_cast<int>(MAX_INDICES));
    std::uint16_t* filtered = inputIndexCount > 0
        ? new (std::nothrow) std::uint16_t[inputIndexCount] : nullptr;
    if (inputIndexCount > 0 && filtered == nullptr) {
        delete[] geometry->verts;
        geometry->verts = nullptr;
        geometry->numVerts = geometry->numIndexes = 0;
        return;
    }
    for (int index = 0; index + 2 < inputIndexCount; index += 3) {
        if (indices[index] >= vertexCount || indices[index + 1] >= vertexCount ||
                indices[index + 2] >= vertexCount) continue;
        filtered[validIndexCount++] = indices[index];
        filtered[validIndexCount++] = indices[index + 1];
        filtered[validIndexCount++] = indices[index + 2];
    }
    geometry->indexes = filtered;
    geometry->numVerts = vertexCount;
    geometry->numIndexes = validIndexCount;
    geometry->vertexBuffer.apiObject = geometry->verts;
    geometry->vertexBuffer.size = vertexCount * sizeof(idDrawVert);
    geometry->indexBuffer.apiObject = geometry->indexes;
    geometry->indexBuffer.size = validIndexCount * sizeof(std::uint16_t);

    if (vertexCount > 0) {
        geometry->bounds[0] = geometry->verts[0].xyz;
        geometry->bounds[1] = geometry->verts[0].xyz;
        for (int index = 1; index < vertexCount; ++index) {
            const idVec3& point = geometry->verts[index].xyz;
            geometry->bounds[0].x = std::min(geometry->bounds[0].x, point.x);
            geometry->bounds[0].y = std::min(geometry->bounds[0].y, point.y);
            geometry->bounds[0].z = std::min(geometry->bounds[0].z, point.z);
            geometry->bounds[1].x = std::max(geometry->bounds[1].x, point.x);
            geometry->bounds[1].y = std::max(geometry->bounds[1].y, point.y);
            geometry->bounds[1].z = std::max(geometry->bounds[1].z, point.z);
        }
    } else {
        geometry->bounds[0].Zero();
        geometry->bounds[1].Zero();
    }
    referenceBounds = geometry->bounds;
}

void idRenderModelCuttableDynamic::Upload(
        const idMaterial* renderMaterial, const idMaterial* depthMaterial,
        const idList<idDrawVert, 5>& vertices,
        const idList<idVec2, 5>& st,
        const idList<std::uint16_t, 5>& indices) {
    UploadRenderGeometry(renderMaterial, vertices, indices);
    if (surfaces.Num() < 2) return;
    idRenderModelSurface& depth = surfaces[0];
    depth.material = depthMaterial;
    const int stCount = std::min(std::min(st.Num(),
        static_cast<int>(MAX_VERTICES)),
        surfaces[1].geometry != nullptr ? surfaces[1].geometry->numVerts : 0);
    if (depth.stMap != nullptr) {
        delete[] static_cast<idVec2*>(depth.stMap->apiObject);
        idVec2* copy = stCount > 0
            ? new (std::nothrow) idVec2[stCount] : nullptr;
        if (copy != nullptr)
            std::memcpy(copy, st.Ptr(), stCount * sizeof(idVec2));
        depth.stMap->apiObject = copy;
        depth.stMap->size = stCount * sizeof(idVec2);
    }
    if (bufferUploadCallback != nullptr && surfaces[1].geometry != nullptr) {
        bufferUploadCallback(surfaces[1].geometry,
            surfaces[1].geometry->verts, surfaces[1].geometry->numVerts,
            surfaces[1].geometry->indexes,
            surfaces[1].geometry->numIndexes, depth.stMap,
            stCount > 0 ? st.Ptr() : nullptr, stCount);
    }
}

bool idRenderModelCuttableDynamic::IsValid() const {
    for (int index = 0; index < surfaces.Num(); ++index) {
        const idRenderModelSurface& surface = surfaces[index];
        if (surface.geometry != nullptr && surface.material != nullptr &&
                surface.geometry->numVerts > 0 &&
                surface.geometry->numIndexes > 0) return true;
    }
    return false;
}
