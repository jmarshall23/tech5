#include "models/cuttable/rendermodelcuttableresource.h"

#include "idlib/filesystem/file.h"

#include <algorithm>
#include <cstring>
#include <new>

namespace {

constexpr std::uint32_t CUTTABLE_MAGIC_V5 = 0x054C4D43u;
constexpr std::uint32_t CUTTABLE_MAGIC_V6 = 0x064C4D43u;
constexpr std::uint32_t CUTTABLE_MAGIC_V7 = 0x074C4D43u;
constexpr int MAX_CUTTABLE_ELEMENTS = 1 << 24;

template<typename Type>
bool ReadValue(idFile* file, Type& value) {
    return file != nullptr && file->Read(&value, sizeof(value)) ==
        sizeof(value);
}

bool ReadBytes(idFile* file, void* data, unsigned int bytes) {
    return bytes == 0 || (file != nullptr && file->Read(data, bytes) == bytes);
}

void ReleaseFallbackBuffers(idTriangles* triangles, idVertexBuffer* stMap) {
    if (triangles != nullptr) {
        delete[] static_cast<idDrawVert*>(triangles->vertexBuffer.apiObject);
        delete[] static_cast<std::uint16_t*>(triangles->indexBuffer.apiObject);
        triangles->vertexBuffer.apiObject = nullptr;
        triangles->indexBuffer.apiObject = nullptr;
    }
    if (stMap != nullptr) {
        delete[] static_cast<idVec2*>(stMap->apiObject);
        stMap->apiObject = nullptr;
    }
}

void UploadFallbackBuffers(idTriangles* triangles,
        idVertexBuffer*& stMap, const idVec2* stData) {
    if (triangles == nullptr) return;
    ReleaseFallbackBuffers(triangles, stMap);
    idDrawVert* vertexCopy = triangles->numVerts > 0
        ? new (std::nothrow) idDrawVert[triangles->numVerts] : nullptr;
    std::uint16_t* indexCopy = triangles->numIndexes > 0
        ? new (std::nothrow) std::uint16_t[triangles->numIndexes] : nullptr;
    if (vertexCopy != nullptr)
        std::memcpy(vertexCopy, triangles->verts,
            triangles->numVerts * sizeof(idDrawVert));
    if (indexCopy != nullptr)
        std::memcpy(indexCopy, triangles->indexes,
            triangles->numIndexes * sizeof(std::uint16_t));
    triangles->vertexBuffer.apiObject = vertexCopy;
    triangles->vertexBuffer.size = triangles->numVerts * sizeof(idDrawVert);
    triangles->vertexBuffer.usage = BU_STATIC;
    triangles->indexBuffer.apiObject = indexCopy;
    triangles->indexBuffer.size =
        triangles->numIndexes * sizeof(std::uint16_t);
    triangles->indexBuffer.usage = BU_STATIC;
    if (stMap == nullptr) stMap = new (std::nothrow) idVertexBuffer{};
    if (stMap != nullptr) {
        idVec2* stCopy = stData != nullptr && triangles->numVerts > 0
            ? new (std::nothrow) idVec2[triangles->numVerts] : nullptr;
        if (stCopy != nullptr)
            std::memcpy(stCopy, stData,
                triangles->numVerts * sizeof(idVec2));
        stMap->apiObject = stCopy;
        stMap->size = triangles->numVerts * sizeof(idVec2);
        stMap->usage = BU_STATIC;
    }
}

} // namespace

idRenderModelCuttableResource::OpenBinaryCallback
    idRenderModelCuttableResource::openBinaryCallback = nullptr;
idRenderModelCuttableResource::CloseBinaryCallback
    idRenderModelCuttableResource::closeBinaryCallback = nullptr;
idRenderModelCuttableResource::TimestampCallback
    idRenderModelCuttableResource::timestampCallback = nullptr;
idRenderModelCuttableResource::MaterialResolver
    idRenderModelCuttableResource::materialResolver = nullptr;
idRenderModelCuttableResource::BufferUploadCallback
    idRenderModelCuttableResource::bufferUploadCallback = nullptr;
idRenderModelCuttableResource::BufferReleaseCallback
    idRenderModelCuttableResource::bufferReleaseCallback = nullptr;
idRenderModelCuttableResource::DepthMaterialCallback
    idRenderModelCuttableResource::depthMaterialCallback = nullptr;

idRenderModelCuttableResource::idRenderModelCuttableResource()
    : sourceMaterial(nullptr), material(nullptr), triangles(nullptr),
      stData(nullptr), stMap(nullptr), timestamp(~0u) {
}

idRenderModelCuttableResource::~idRenderModelCuttableResource() {
    FreeData();
}

void idRenderModelCuttableResource::SetFileCallbacks(
        OpenBinaryCallback open, CloseBinaryCallback close,
        TimestampCallback timestamp_) {
    openBinaryCallback = open;
    closeBinaryCallback = close;
    timestampCallback = timestamp_;
}

void idRenderModelCuttableResource::SetMaterialResolver(
        MaterialResolver resolver) {
    materialResolver = resolver;
}

void idRenderModelCuttableResource::SetBufferCallbacks(
        BufferUploadCallback upload, BufferReleaseCallback release) {
    bufferUploadCallback = upload;
    bufferReleaseCallback = release;
}

void idRenderModelCuttableResource::SetDepthMaterialCallback(
        DepthMaterialCallback callback) {
    depthMaterialCallback = callback;
}

void idRenderModelCuttableResource::FreeCPUData() {
    if (triangles != nullptr) {
        delete[] triangles->verts;
        delete[] triangles->indexes;
        triangles->verts = nullptr;
        triangles->indexes = nullptr;
    }
    delete[] stData;
    stData = nullptr;
}

void idRenderModelCuttableResource::FreeData() {
    if (bufferReleaseCallback != nullptr)
        bufferReleaseCallback(triangles, stMap);
    else ReleaseFallbackBuffers(triangles, stMap);
    delete stMap;
    stMap = nullptr;
    FreeCPUData();
    delete triangles;
    triangles = nullptr;
    sourceMaterial = nullptr;
    material = nullptr;
    timestamp = ~0u;
    contourBound.Clear();
    triangleInterpolator.Clear();
}

bool idRenderModelCuttableResource::LoadBinary(idFile* file,
        unsigned int fileTimestamp) {
    if (file == nullptr) return false;
    FreeData();
    std::uint32_t magic = 0;
    int contourCount = 0;
    if (!ReadValue(file, magic) || (magic != CUTTABLE_MAGIC_V5 &&
            magic != CUTTABLE_MAGIC_V6 && magic != CUTTABLE_MAGIC_V7) ||
            !ReadValue(file, contourCount) || contourCount < 0 ||
            contourCount > MAX_CUTTABLE_ELEMENTS ||
            !contourBound.SetNum(contourCount) ||
            !ReadBytes(file, contourBound.Ptr(),
                contourCount * sizeof(idVec3))) {
        FreeData();
        return false;
    }

    idStr materialName;
    idStr sourceMaterialName;
    if (file->ReadString(materialName) == 0 && materialName.Length() != 0) {
        FreeData();
        return false;
    }
    if (magic >= CUTTABLE_MAGIC_V7 &&
            file->ReadString(sourceMaterialName) == 0 &&
            sourceMaterialName.Length() != 0) {
        FreeData();
        return false;
    }

    triangles = new (std::nothrow) idTriangles{};
    if (triangles == nullptr || !ReadValue(file, triangles->numVerts) ||
            !ReadValue(file, triangles->numIndexes) ||
            triangles->numVerts < 0 || triangles->numIndexes < 0 ||
            triangles->numVerts > MAX_CUTTABLE_ELEMENTS ||
            triangles->numIndexes > MAX_CUTTABLE_ELEMENTS ||
            !ReadValue(file, triangles->vertexMask) ||
            !ReadValue(file, triangles->vsb)) {
        FreeData();
        return false;
    }
    triangles->cpuVertexMask = triangles->vertexMask;
    triangles->verts = triangles->numVerts > 0
        ? new (std::nothrow) idDrawVert[triangles->numVerts] : nullptr;
    triangles->indexes = triangles->numIndexes > 0
        ? new (std::nothrow) std::uint16_t[triangles->numIndexes] : nullptr;
    if ((triangles->numVerts > 0 && triangles->verts == nullptr) ||
            (triangles->numIndexes > 0 && triangles->indexes == nullptr) ||
            !ReadBytes(file, triangles->verts,
                triangles->numVerts * sizeof(idDrawVert)) ||
            !ReadBytes(file, triangles->indexes,
                triangles->numIndexes * sizeof(std::uint16_t)) ||
            !ReadBytes(file, &triangles->bounds, sizeof(idBounds)) ||
            !ReadValue(file, triangles->detailOffset)) {
        FreeData();
        return false;
    }
    triangles->generateNormals = false;
    triangles->allowGpuHosting = false;

    stData = triangles->numVerts > 0
        ? new (std::nothrow) idVec2[triangles->numVerts] : nullptr;
    if (triangles->numVerts > 0 && stData == nullptr) {
        FreeData();
        return false;
    }
    if (magic >= CUTTABLE_MAGIC_V6) {
        if (!ReadBytes(file, stData,
                triangles->numVerts * sizeof(idVec2))) {
            FreeData();
            return false;
        }
    } else {
        for (int index = 0; index < triangles->numVerts; ++index)
            stData[index].Zero();
    }

    material = materialResolver != nullptr && materialName.Length() > 0
        ? materialResolver(materialName.c_str()) : nullptr;
    sourceMaterial = materialResolver != nullptr &&
            sourceMaterialName.Length() > 0
        ? materialResolver(sourceMaterialName.c_str()) : nullptr;
    timestamp = fileTimestamp != 0 ? fileTimestamp : file->Timestamp();
    triangleInterpolator.AddTriangles(triangles->verts, stData,
        triangles->indexes, triangles->numIndexes);
    if (bufferUploadCallback != nullptr)
        bufferUploadCallback(triangles, stMap, stData);
    else UploadFallbackBuffers(triangles, stMap, stData);
    return true;
}

void idRenderModelCuttableResource::LoadResource() {
    if (openBinaryCallback == nullptr) return;
    unsigned int fileTimestamp = 0;
    idFile* file = openBinaryCallback(GetName(), fileTimestamp);
    if (file == nullptr) return;
    LoadBinary(file, fileTimestamp);
    if (closeBinaryCallback != nullptr) closeBinaryCallback(file);
}

bool idRenderModelCuttableResource::ReloadIfStale() {
    if (timestampCallback == nullptr) return false;
    const unsigned int currentTimestamp = timestampCallback(GetName());
    if (currentTimestamp == timestamp) return false;
    LoadResource();
    return true;
}

void idRenderModelCuttableResource::BuildDepthSurface(
        idRenderModelSurface* surface) {
    if (surface == nullptr || stMap == nullptr || sourceMaterial == nullptr)
        return;
    surface->material = depthMaterialCallback != nullptr
        ? depthMaterialCallback(this) : nullptr;
    surface->geometry = triangles;
    surface->geometryIsReference = true;
    surface->stMap = stMap;
}

void idRenderModelCuttableResource::BuildSurface(idRenderModel* model) {
    if (model == nullptr || triangles == nullptr) return;
    idRenderModelSurface depth{};
    BuildDepthSurface(&depth);
    if (depth.material != nullptr) model->AddSurface(depth);

    if (material != nullptr) {
        idRenderModelSurface render{};
        render.material = material;
        render.geometry = triangles;
        render.geometryIsReference = true;
        model->AddSurface(render);
    }
}
