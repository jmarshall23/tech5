#include "models/flares/rendermodelflare.h"

#include "decls/declflare.h"
#include "idlib/filesystem/file.h"
#include "network/serializer.h"

#include <algorithm>
#include <cstdint>
#include <cstring>

namespace {

constexpr int kMaximumFlareSurfaces = 20;
constexpr int kMaximumQuadsPerFrame = 256;

const idVec3 kQuadPoints[4] = {
    idVec3(-1.0f, -1.0f, 0.0f),
    idVec3( 1.0f, -1.0f, 0.0f),
    idVec3( 1.0f,  1.0f, 0.0f),
    idVec3(-1.0f,  1.0f, 0.0f)
};

const std::uint16_t kQuadIndexes[6] = { 0, 1, 2, 0, 2, 3 };

void InitializeQuad(idTriangles& triangles) {
    std::memset(&triangles, 0, sizeof(triangles));
    triangles.numVerts = 4;
    triangles.numIndexes = 6;
    triangles.vertexMask = triangles.cpuVertexMask = 0x1Fu;
    triangles.allowGpuHosting = true;
    triangles.verts = new idDrawVert[4];
    triangles.indexes = new std::uint16_t[6];
    std::memcpy(triangles.indexes, kQuadIndexes, sizeof(kQuadIndexes));
    for (int index = 0; index < 4; ++index) {
        idDrawVert& vertex = triangles.verts[index];
        std::memset(&vertex, 0, sizeof(vertex));
        vertex.xyz = kQuadPoints[index];
        vertex.st.Set((index == 1 || index == 2) ? 1.0f : 0.0f,
            index >= 2 ? 1.0f : 0.0f);
        vertex.SetNormal(idVec3(0.0f, 0.0f, 1.0f));
        vertex.SetTangent(idVec3(1.0f, 0.0f, 0.0f));
        vertex.SetBiTangent(idVec3(0.0f, 1.0f, 0.0f));
        std::memset(vertex.color, 255, sizeof(vertex.color));
    }
    triangles.bounds[0] = kQuadPoints[0];
    triangles.bounds[1] = kQuadPoints[2];
}

void FreeOwnedGeometry(idList<idRenderModelSurface, 85>& surfaces) {
    for (int index = 0; index < surfaces.Num(); ++index) {
        idTriangles* geometry = surfaces[index].geometry;
        if (geometry == nullptr || surfaces[index].geometryIsReference)
            continue;
        delete[] geometry->verts;
        delete[] geometry->indexes;
        delete geometry;
        surfaces[index].geometry = nullptr;
    }
    surfaces.Clear();
}

bool WriteExact(idFile* file, const void* data, unsigned int size) {
    return file != nullptr && file->Write(data, size) == size;
}

bool ReadExact(idFile* file, void* data, unsigned int size) {
    return file != nullptr && file->Read(data, size) == size;
}

} // namespace

idRenderModelFlare::UpdateCallback idRenderModelFlare::updateCallback = nullptr;
idRenderModelFlare::DeclarationResolver
    idRenderModelFlare::declarationResolver = nullptr;
idRenderModelFlare::SnapshotDeclarationCallback
    idRenderModelFlare::snapshotDeclarationCallback = nullptr;
int idRenderModelFlare::mappedBufferIndex = 0;
int idRenderModelFlare::vertOffset = 0;
bool idRenderModelFlare::initialized = false;

idRenderModelFlare::idRenderModelFlare(const idDeclFlare* declaration)
    : flareDecl(declaration), quadModelIndex(-1), isSunFlare(false) {
    if (!initialized) Init();
    SetName(declaration != nullptr ? declaration->GetName() : "_flare");
    g.noInteractions = 1;
    g.noShadow = 1;
    g.addAlways = 1;
    g.mvpIsIdentity = 1;
    SetMaxSurfaces(kMaximumFlareSurfaces);
    for (int index = 0; index < kMaximumFlareSurfaces; ++index) {
        idTriangles* geometry = new idTriangles;
        InitializeQuad(*geometry);
        geometry->numVerts = 0;
        geometry->numIndexes = 0;
        idRenderModelSurface surface{};
        surface.material = declaration != nullptr &&
                index < declaration->subflares.Num()
            ? declaration->subflares[index].mtr : nullptr;
        surface.geometry = geometry;
        surface.geometryIsReference = false;
        AddSurface(surface);
    }
}

idRenderModelFlare::~idRenderModelFlare() {
    FreeOwnedGeometry(surfaces);
}

void idRenderModelFlare::Init() {
    mappedBufferIndex = 0;
    vertOffset = 0;
    initialized = true;
}

void idRenderModelFlare::Shutdown() {
    mappedBufferIndex = 0;
    vertOffset = 0;
    initialized = false;
}

void idRenderModelFlare::StartFrame() {
    mappedBufferIndex ^= 1;
    vertOffset = 0;
}

void idRenderModelFlare::EndFrame() {
}

void idRenderModelFlare::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

void idRenderModelFlare::SetDeclarationPersistenceCallbacks(
        DeclarationResolver resolver,
        SnapshotDeclarationCallback snapshotCallback) {
    declarationResolver = resolver;
    snapshotDeclarationCallback = snapshotCallback;
}

void idRenderModelFlare::Save(idFile* file) {
    idRenderModel::Save(file);
    if (file == nullptr) return;
    file->WriteString(flareDecl != nullptr ? flareDecl->GetName() : "");
    const std::uint8_t sun = isSunFlare ? 1u : 0u;
    WriteExact(file, &sun, sizeof(sun));
    WriteExact(file, &quadModelIndex, sizeof(quadModelIndex));
}

bool idRenderModelFlare::Load(idFile* file) {
    if (!idRenderModel::Load(file)) return false;
    idStr declarationName;
    if (file->ReadString(declarationName) == 0) return false;
    const idDeclFlare* loadedDeclaration = nullptr;
    if (declarationName.Length() != 0) {
        if (declarationResolver == nullptr ||
                (loadedDeclaration = declarationResolver(
                    declarationName.c_str(), true)) == nullptr) {
            return false;
        }
    }
    std::uint8_t sun = 0;
    int loadedQuadModelIndex = -1;
    if (!ReadExact(file, &sun, sizeof(sun)) ||
            !ReadExact(file, &loadedQuadModelIndex,
                sizeof(loadedQuadModelIndex))) {
        return false;
    }
    SetFlareDeclaration(loadedDeclaration);
    quadModelIndex = loadedQuadModelIndex;
    SetSunFlare(sun != 0);
    return true;
}

void idRenderModelFlare::SerializeSnapshot(idSerializer* serializer,
        bool serializeParmBlock) {
    idRenderModel::SerializeSnapshot(serializer, serializeParmBlock);
    if (serializer == nullptr) return;
    if (snapshotDeclarationCallback != nullptr) {
        snapshotDeclarationCallback(serializer, flareDecl);
    } else {
        idStr name = flareDecl != nullptr ? flareDecl->GetName() : "";
        serializer->SerializeString(name);
        if (serializer->IsReading()) {
            flareDecl = name.Length() != 0 && declarationResolver != nullptr
                ? declarationResolver(name.c_str(), true) : nullptr;
        }
    }
    isSunFlare = serializer->SerializeBoolNonRef(isSunFlare);
    g.mvpIsSunFlare = isSunFlare ? 1 : 0;
}

bool idRenderModelFlare::UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView, idRenderModelUpdateTools* tools) {
    if (updateCallback == nullptr) return false;
    const bool updated = updateCallback(this, currentView, nextView, tools);
    if (updated) {
        int activeSurfaces = 0;
        for (int index = 0; index < surfaces.Num(); ++index) {
            if (surfaces[index].geometry != nullptr &&
                    surfaces[index].geometry->numIndexes > 0) {
                ++activeSurfaces;
            }
        }
        vertOffset = (std::min)(kMaximumQuadsPerFrame,
            vertOffset + activeSurfaces * 4);
        CommitThisFrame();
    }
    return updated;
}

void idRenderModelFlare::SetFlareDeclaration(
        const idDeclFlare* declaration) {
    flareDecl = declaration;
    for (int index = 0; index < surfaces.Num(); ++index) {
        surfaces[index].material = declaration != nullptr &&
                index < declaration->subflares.Num()
            ? declaration->subflares[index].mtr : nullptr;
    }
}

void idRenderModelFlare::SetSunFlare(bool enabled) {
    isSunFlare = enabled;
    g.mvpIsSunFlare = enabled ? 1 : 0;
}

idRenderModelFlareOcclusionQuad::UpdateCallback
    idRenderModelFlareOcclusionQuad::updateCallback = nullptr;
idRenderModelFlareOcclusionQuad::AreaCallback
    idRenderModelFlareOcclusionQuad::areaCallback = nullptr;
int idRenderModelFlareOcclusionQuad::vertOffset = 0;
bool idRenderModelFlareOcclusionQuad::initialized = false;

idRenderModelFlareOcclusionQuad::idRenderModelFlareOcclusionQuad()
    : isSunFlare(false), currentIdx(0), screenSpaceArea{0.0f, 0.0f} {
    if (!initialized) Init();
    SetName("_flareOcclusionQuad");
    g.noInteractions = 1;
    g.noShadow = 1;
    g.neverOcclusionCullBounds = 1;
    idTriangles* geometry = new idTriangles;
    InitializeQuad(*geometry);
    idRenderModelSurface surface{};
    surface.geometry = geometry;
    surface.geometryIsReference = false;
    AddSurface(surface);
    referenceBounds = geometry->bounds;
}

idRenderModelFlareOcclusionQuad::~idRenderModelFlareOcclusionQuad() {
    FreeOwnedGeometry(surfaces);
}

void idRenderModelFlareOcclusionQuad::Init() {
    vertOffset = 0;
    initialized = true;
}

void idRenderModelFlareOcclusionQuad::Shutdown() {
    vertOffset = 0;
    initialized = false;
}

void idRenderModelFlareOcclusionQuad::StartFrame() {
    vertOffset = 0;
}

void idRenderModelFlareOcclusionQuad::SetUpdateCallback(
        UpdateCallback callback) {
    updateCallback = callback;
}

void idRenderModelFlareOcclusionQuad::SetAreaCallback(AreaCallback callback) {
    areaCallback = callback;
}

void idRenderModelFlareOcclusionQuad::Save(idFile* file) {
    idRenderModel::Save(file);
    if (file == nullptr) return;
    const std::uint8_t sun = isSunFlare ? 1u : 0u;
    WriteExact(file, &sun, sizeof(sun));
    WriteExact(file, &currentIdx, sizeof(currentIdx));
    WriteExact(file, screenSpaceArea, sizeof(screenSpaceArea));
}

bool idRenderModelFlareOcclusionQuad::Load(idFile* file) {
    if (!idRenderModel::Load(file)) return false;
    std::uint8_t sun = 0;
    int loadedIndex = 0;
    float loadedAreas[2] = {};
    if (!ReadExact(file, &sun, sizeof(sun)) ||
            !ReadExact(file, &loadedIndex, sizeof(loadedIndex)) ||
            !ReadExact(file, loadedAreas, sizeof(loadedAreas)) ||
            (loadedIndex != 0 && loadedIndex != 1)) {
        return false;
    }
    currentIdx = loadedIndex;
    screenSpaceArea[0] = loadedAreas[0];
    screenSpaceArea[1] = loadedAreas[1];
    SetSunFlare(sun != 0);
    return true;
}

void idRenderModelFlareOcclusionQuad::SerializeSnapshot(
        idSerializer* serializer, bool serializeParmBlock) {
    idRenderModel::SerializeSnapshot(serializer, serializeParmBlock);
    if (serializer == nullptr) return;
    isSunFlare = serializer->SerializeBoolNonRef(isSunFlare);
    g.mvpIsSunFlare = isSunFlare ? 1 : 0;
}

bool idRenderModelFlareOcclusionQuad::UpdateInView(
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools) {
    if (updateCallback != nullptr)
        return updateCallback(this, currentView, nextView, tools);
    currentIdx ^= 1;
    screenSpaceArea[currentIdx] = CalcScreenSpaceAreaForView(
        currentView, nextView);
    if (vertOffset + 4 <= kMaximumQuadsPerFrame * 4) vertOffset += 4;
    CommitThisFrame();
    return false;
}

float idRenderModelFlareOcclusionQuad::CalcScreenSpaceAreaForView(
        const idRenderView* currentView, const idRenderView* nextView) const {
    return areaCallback != nullptr
        ? (std::max)(0.0f, areaCallback(this, currentView, nextView))
        : 0.0f;
}

void idRenderModelFlareOcclusionQuad::SetSunFlare(bool enabled) {
    isSunFlare = enabled;
    g.mvpIsSunFlare = enabled ? 1 : 0;
}
