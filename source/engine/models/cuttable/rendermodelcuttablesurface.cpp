#include "models/cuttable/rendermodelcuttablesurface.h"

#include "idlib/filesystem/file.h"
#include "models/cuttable/earcliptriangulate.h"

idRenderModelCuttableSurface::UpdateCallback
    idRenderModelCuttableSurface::updateCallback = nullptr;
idRenderModelCuttableSurface::ResourceResolver
    idRenderModelCuttableSurface::resourceResolver = nullptr;

idRenderModelCuttableSurface::idRenderModelCuttableSurface()
    : modelResource(nullptr), triangleInterpolator(nullptr), bufferIndex(0) {
    g.noShadow = 1;
    g.addAlways = 1;
}

idRenderModelCuttableSurface::idRenderModelCuttableSurface(
        const char* modelName)
    : idRenderModelCuttableSurface() {
    SetName(modelName != nullptr ? modelName : "");
    LoadModel(modelName);
}

void idRenderModelCuttableSurface::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

void idRenderModelCuttableSurface::SetResourceResolver(
        ResourceResolver resolver) {
    resourceResolver = resolver;
}

void idRenderModelCuttableSurface::Save(idFile* file) {
    idRenderModel::Save(file);
    if (file != nullptr) file->Write(&bufferIndex, sizeof(bufferIndex));
}

bool idRenderModelCuttableSurface::Load(idFile* file) {
    return file != nullptr &&
        file->Read(&bufferIndex, sizeof(bufferIndex)) == sizeof(bufferIndex);
}

bool idRenderModelCuttableSurface::LoadModel(const char* modelName) {
    modelResource = resourceResolver != nullptr && modelName != nullptr
        ? resourceResolver(modelName) : nullptr;
    triangleInterpolator = modelResource != nullptr
        ? &modelResource->triangleInterpolator : nullptr;
    if (modelResource == nullptr) return false;
    modelResource->BuildSurface(this);
    FinishSurfaces();
    return true;
}

int idRenderModelCuttableSurface::UpdateGeometry(int newBufferIndex,
        const idVertexBuffer& vertexBuffer,
        const idVertexBuffer& stBuffer,
        const idIndexBuffer& indexBuffer,
        int numVertices, int numIndices) {
    const int previous = bufferIndex;
    bufferIndex = newBufferIndex;
    for (int index = 0; index < surfaces.Num(); ++index) {
        idRenderModelSurface& surface = surfaces[index];
        if (surface.geometry == nullptr) continue;
        surface.geometry->verts = nullptr;
        surface.geometry->indexes = nullptr;
        surface.geometry->vertexBuffer = vertexBuffer;
        surface.geometry->indexBuffer = indexBuffer;
        surface.geometry->numVerts = numVertices;
        surface.geometry->numIndexes = numIndices;
        if (surface.stMap != nullptr) *surface.stMap = stBuffer;
    }
    return previous;
}

void idRenderModelCuttableSurface::BuildGeometry(const Contour* outer,
        const Contour* inner, idList<idDrawVert, 5>& vertices,
        idList<idVec2, 5>& originalST,
        idList<std::uint16_t, 5>& indices) const {
    vertices.Clear();
    originalST.Clear();
    indices.Clear();
    if (outer == nullptr || triangleInterpolator == nullptr) return;

    idEarClipTriangulate triangulator;
    triangulator.SetOuterFromContour(outer);
    for (const Contour* hole = inner; hole != nullptr; hole = hole->next)
        triangulator.AddInnerFromContour(hole);
    triangulator.Triangulate();
    idList<idVec2, 5> positions;
    idList<std::uint16_t, 5> frontIndices;
    triangulator.BuildGeometry(triangleInterpolator->refNormal,
        positions, frontIndices);
    if (positions.Num() > 0x7FFF) return;

    for (int index = 0; index < positions.Num(); ++index) {
        idDrawVert vertex{};
        idVec2 sourceST;
        if (!triangleInterpolator->Interpolate(positions[index], vertex,
                sourceST)) continue;
        vertices.Append(vertex);
        originalST.Append(sourceST);
    }
    const int frontVertexCount = vertices.Num();
    if (frontVertexCount != positions.Num()) {
        vertices.Clear(); originalST.Clear(); indices.Clear(); return;
    }
    for (int index = 0; index < frontVertexCount; ++index) {
        idDrawVert back = vertices[index];
        const idVec3 bitangent = back.GetBiTangent();
        back.SetNormal(-back.GetNormal());
        back.SetTangent(-back.GetTangent());
        back.SetBiTangent(-bitangent);
        vertices.Append(back);
        originalST.Append(originalST[index]);
    }
    for (int index = 0; index + 2 < frontIndices.Num(); index += 3) {
        indices.Append(frontIndices[index]);
        indices.Append(frontIndices[index + 1]);
        indices.Append(frontIndices[index + 2]);
        indices.Append(static_cast<std::uint16_t>(
            frontIndices[index] + frontVertexCount));
        indices.Append(static_cast<std::uint16_t>(
            frontIndices[index + 2] + frontVertexCount));
        indices.Append(static_cast<std::uint16_t>(
            frontIndices[index + 1] + frontVertexCount));
    }
}

bool idRenderModelCuttableSurface::UpdateInView(
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools) {
    return updateCallback != nullptr
        ? updateCallback(this, currentView, nextView, tools)
        : false;
}
