#include "models/discreteanimation/discreteanimationmodeldata.h"

#include "idlib/filesystem/file.h"
#include "idlib/filesystem/filesystem.h"

#include <cstdint>
#include <cstring>
#include <limits>
#include <new>
#include <string>

namespace {

constexpr std::uint32_t DISCRETE_ANIMATION_MODEL_MAGIC = 0x044C4D44u;
constexpr std::uint32_t MAX_DISCRETE_ITEMS = 1u << 20;
constexpr std::uint32_t MAX_DISCRETE_SURFACES = 1u << 16;
constexpr std::uint32_t MAX_DISCRETE_STRING = 4096u;

bool BuildGeneratedName(const char* modelName, char (&path)[256]) {
    return fileSystem != nullptr && fileSystem->FixLongFilename("generated",
        "dmodel", modelName, path, static_cast<int>(sizeof(path)));
}

bool ReadExact(idFile* file, void* data, std::uint64_t byteCount) {
    if (file == nullptr || byteCount >
            (std::numeric_limits<unsigned int>::max)()) {
        return false;
    }
    if (byteCount == 0) {
        return true;
    }
    const std::int64_t remaining = file->Length() - file->Tell();
    return remaining >= 0 &&
        static_cast<std::uint64_t>(remaining) >= byteCount &&
        file->Read(data, static_cast<unsigned int>(byteCount)) == byteCount;
}

bool WriteExact(idFile* file, const void* data, std::uint64_t byteCount) {
    return file != nullptr && byteCount <=
            (std::numeric_limits<unsigned int>::max)() &&
        (byteCount == 0 || file->Write(data,
            static_cast<unsigned int>(byteCount)) == byteCount);
}

bool ReadString(idFile* file, std::string& text) {
    std::uint32_t length = 0;
    if (!ReadExact(file, &length, sizeof(length)) ||
        length > MAX_DISCRETE_STRING) {
        return false;
    }
    text.resize(length);
    return ReadExact(file, length != 0 ? &text[0] : nullptr, length);
}

bool WriteString(idFile* file, const char* text) {
    const char* const safeText = text != nullptr ? text : "";
    const std::size_t length = std::strlen(safeText);
    if (length > MAX_DISCRETE_STRING) {
        return false;
    }
    const std::uint32_t storedLength = static_cast<std::uint32_t>(length);
    return WriteExact(file, &storedLength, sizeof(storedLength)) &&
        WriteExact(file, safeText, storedLength);
}

void DeleteSurface(idDiscreteAnimationModelSurface* surface) {
    if (surface == nullptr) {
        return;
    }
    if (surface->triangles != nullptr) {
        delete[] surface->triangles->verts;
        delete[] surface->triangles->indexes;
        delete surface->triangles;
    }
    delete surface;
}

bool ReadCount(idFile* file, std::uint32_t limit, std::uint32_t& count) {
    return ReadExact(file, &count, sizeof(count)) && count <= limit;
}

} // namespace

idTypedResourceList<idDiscreteAnimationModelData>
    idDiscreteAnimationModelData::resourceList("discreteAnimation");
idDiscreteAnimationModelData::MaterialResolver
    idDiscreteAnimationModelData::materialResolver = nullptr;
idDiscreteAnimationModelData::MaterialNameResolver
    idDiscreteAnimationModelData::materialNameResolver = nullptr;
idDiscreteAnimationModelData::MaterialChecksumResolver
    idDiscreteAnimationModelData::materialChecksumResolver = nullptr;
idDiscreteAnimationModelData::CollisionModelResolver
    idDiscreteAnimationModelData::collisionModelResolver = nullptr;
idDiscreteAnimationModelData::CollisionModelNameResolver
    idDiscreteAnimationModelData::collisionModelNameResolver = nullptr;
idDiscreteAnimationModelData::GenerateCallback
    idDiscreteAnimationModelData::generateCallback = nullptr;
idDiscreteAnimationModelData::SurfaceRemapCallback
    idDiscreteAnimationModelData::surfaceRemapCallback = nullptr;
idDiscreteAnimationModelData::BufferUpdateCallback
    idDiscreteAnimationModelData::bufferUpdateCallback = nullptr;
bool idDiscreteAnimationModelData::freeCPUDataAfterUpload = false;

idDiscreteAnimationModelData::idDiscreteAnimationModelData()
    : timestamp((std::numeric_limits<unsigned int>::max)()),
      maxRadius(0.0f), material(nullptr), baseModel(nullptr) {
    bounds.b[0].Set(0.0f, 0.0f, 0.0f);
    bounds.b[1].Set(0.0f, 0.0f, 0.0f);
}

idDiscreteAnimationModelData::~idDiscreteAnimationModelData() {
    FreeData();
}

void idDiscreteAnimationModelData::SetMaterialCallbacks(
    MaterialResolver resolver, MaterialNameResolver nameResolver,
    MaterialChecksumResolver checksumResolver) {
    materialResolver = resolver;
    materialNameResolver = nameResolver;
    materialChecksumResolver = checksumResolver;
}

void idDiscreteAnimationModelData::SetCollisionModelCallbacks(
    CollisionModelResolver resolver,
    CollisionModelNameResolver nameResolver) {
    collisionModelResolver = resolver;
    collisionModelNameResolver = nameResolver;
}

void idDiscreteAnimationModelData::SetGenerateCallback(
    GenerateCallback callback) {
    generateCallback = callback;
}

void idDiscreteAnimationModelData::SetSurfaceRemapCallback(
    SurfaceRemapCallback callback) {
    surfaceRemapCallback = callback;
}

void idDiscreteAnimationModelData::SetBufferUpdateCallback(
    BufferUpdateCallback callback) {
    bufferUpdateCallback = callback;
}

void idDiscreteAnimationModelData::SetFreeCPUDataAfterUpload(bool enabled) {
    freeCPUDataAfterUpload = enabled;
}

idResourceList* idDiscreteAnimationModelData::GetResourceList() {
    return &resourceList;
}

void idDiscreteAnimationModelData::FreeData() {
    for (int index = 0; index < surfaces.Num(); ++index) {
        DeleteSurface(surfaces[index]);
    }
    surfaces.ClearFree();
    traceModels.ClearFree();
    transforms.ClearFree();
    sourceSurfaces.ClearFree();
    timestamp = (std::numeric_limits<unsigned int>::max)();
    maxRadius = 0.0f;
    bounds.b[0].Set(0.0f, 0.0f, 0.0f);
    bounds.b[1].Set(0.0f, 0.0f, 0.0f);
    material = nullptr;
    baseModel = nullptr;
}

void idDiscreteAnimationModelData::UpdateBuffers() {
    if (bufferUpdateCallback == nullptr) {
        return;
    }
    for (int index = 0; index < surfaces.Num(); ++index) {
        if (surfaces[index] != nullptr &&
            surfaces[index]->triangles != nullptr) {
            bufferUpdateCallback(surfaces[index]->triangles);
        }
    }
}

void idDiscreteAnimationModelData::FreeCPUData() {
    for (int index = 0; index < surfaces.Num(); ++index) {
        if (surfaces[index] == nullptr ||
            surfaces[index]->triangles == nullptr) {
            continue;
        }
        delete[] surfaces[index]->triangles->verts;
        delete[] surfaces[index]->triangles->indexes;
        surfaces[index]->triangles->verts = nullptr;
        surfaces[index]->triangles->indexes = nullptr;
    }
}

void idDiscreteAnimationModelData::RemapSourceSurfaces() {
    if (surfaceRemapCallback != nullptr) {
        surfaceRemapCallback(this);
    }
}

bool idDiscreteAnimationModelData::WriteBinary(const char* fileName) const {
    if (fileSystem == nullptr || fileName == nullptr ||
        traceModels.Num() < 0 || transforms.Num() < 0 ||
        surfaces.Num() < 0 || sourceSurfaces.Num() < 0) {
        return false;
    }
    idFileLocal file(fileSystem->OpenFileWrite(fileName, FSPATH_BASE));
    if (file.file == nullptr) {
        return false;
    }

    const char* materialName = "";
    if (material != nullptr) {
        if (materialNameResolver == nullptr ||
            (materialName = materialNameResolver(material)) == nullptr) {
            return false;
        }
    }
    const std::uint32_t traceCount =
        static_cast<std::uint32_t>(traceModels.Num());
    const std::uint32_t transformCount =
        static_cast<std::uint32_t>(transforms.Num());
    const std::uint32_t surfaceCount =
        static_cast<std::uint32_t>(surfaces.Num());
    const std::uint32_t sourceSurfaceCount =
        static_cast<std::uint32_t>(sourceSurfaces.Num());
    if (traceCount > MAX_DISCRETE_ITEMS ||
        transformCount > MAX_DISCRETE_ITEMS ||
        surfaceCount > MAX_DISCRETE_SURFACES ||
        sourceSurfaceCount > MAX_DISCRETE_ITEMS ||
        !WriteExact(file.file, &DISCRETE_ANIMATION_MODEL_MAGIC,
            sizeof(DISCRETE_ANIMATION_MODEL_MAGIC)) ||
        !WriteExact(file.file, &timestamp, sizeof(timestamp)) ||
        !WriteExact(file.file, &maxRadius, sizeof(maxRadius)) ||
        !WriteExact(file.file, &bounds, sizeof(bounds)) ||
        !WriteString(file.file, materialName) ||
        !WriteExact(file.file, &traceCount, sizeof(traceCount)) ||
        !WriteExact(file.file, traceModels.Ptr(),
            static_cast<std::uint64_t>(traceCount) * sizeof(idTraceModel)) ||
        !WriteExact(file.file, &transformCount, sizeof(transformCount)) ||
        !WriteExact(file.file, transforms.Ptr(),
            static_cast<std::uint64_t>(transformCount) * sizeof(idJointMat)) ||
        !WriteExact(file.file, &surfaceCount, sizeof(surfaceCount))) {
        return false;
    }

    for (int index = 0; index < surfaces.Num(); ++index) {
        const idDiscreteAnimationModelSurface* surface = surfaces[index];
        if (surface == nullptr || surface->triangles == nullptr ||
            surface->triangles->numVerts < 0 ||
            surface->triangles->numIndexes < 0 ||
            (surface->triangles->numVerts != 0 &&
                surface->triangles->verts == nullptr) ||
            (surface->triangles->numIndexes != 0 &&
                surface->triangles->indexes == nullptr)) {
            return false;
        }
        const std::uint32_t vertexCount = static_cast<std::uint32_t>(
            surface->triangles->numVerts);
        const std::uint32_t indexCount = static_cast<std::uint32_t>(
            surface->triangles->numIndexes);
        if (vertexCount > MAX_DISCRETE_ITEMS ||
            indexCount > MAX_DISCRETE_ITEMS ||
            !WriteExact(file.file, &surface->jointOffset,
                sizeof(surface->jointOffset)) ||
            !WriteExact(file.file, &surface->numJoints,
                sizeof(surface->numJoints)) ||
            !WriteExact(file.file, &vertexCount, sizeof(vertexCount)) ||
            !WriteExact(file.file, &indexCount, sizeof(indexCount)) ||
            !WriteExact(file.file, surface->triangles->verts,
                static_cast<std::uint64_t>(vertexCount) *
                    sizeof(idDrawVert)) ||
            !WriteExact(file.file, surface->triangles->indexes,
                static_cast<std::uint64_t>(indexCount) *
                    sizeof(std::uint16_t))) {
            return false;
        }
    }

    if (!WriteExact(file.file, &sourceSurfaceCount,
            sizeof(sourceSurfaceCount))) {
        return false;
    }
    for (int index = 0; index < sourceSurfaces.Num(); ++index) {
        const sourceSurface_t& source = sourceSurfaces[index];
        const char* name = "";
        if (source.mtr != nullptr) {
            if (materialNameResolver == nullptr ||
                (name = materialNameResolver(source.mtr)) == nullptr) {
                return false;
            }
        }
        if (!WriteString(file.file, name) ||
            !WriteExact(file.file, &source.mtrChecksum,
                sizeof(source.mtrChecksum)) ||
            !WriteExact(file.file, &source.renderSurface,
                sizeof(source.renderSurface)) ||
            !WriteExact(file.file, &source.firstVertex,
                sizeof(source.firstVertex)) ||
            !WriteExact(file.file, &source.lastVertex,
                sizeof(source.lastVertex))) {
            return false;
        }
    }

    const std::uint32_t hasBaseModel = baseModel != nullptr ? 1u : 0u;
    if (!WriteExact(file.file, &hasBaseModel, sizeof(hasBaseModel))) {
        return false;
    }
    if (hasBaseModel != 0) {
        if (collisionModelNameResolver == nullptr) {
            return false;
        }
        return WriteString(file.file,
            collisionModelNameResolver(baseModel));
    }
    return true;
}

bool idDiscreteAnimationModelData::LoadBinary(const char* fileName) {
    if (fileSystem == nullptr || fileName == nullptr) {
        return false;
    }
    idFileLocal file(fileSystem->OpenFileRead(fileName, true, false));
    if (file.file == nullptr) {
        return false;
    }

    FreeData();
    std::uint32_t magic = 0;
    std::string text;
    std::uint32_t count = 0;
    if (!ReadExact(file.file, &magic, sizeof(magic)) ||
        magic != DISCRETE_ANIMATION_MODEL_MAGIC ||
        !ReadExact(file.file, &timestamp, sizeof(timestamp)) ||
        !ReadExact(file.file, &maxRadius, sizeof(maxRadius)) ||
        !ReadExact(file.file, &bounds, sizeof(bounds)) ||
        !ReadString(file.file, text)) {
        FreeData();
        return false;
    }
    material = materialResolver != nullptr && !text.empty()
        ? materialResolver(text.c_str()) : nullptr;

    if (!ReadCount(file.file, MAX_DISCRETE_ITEMS, count) ||
        !traceModels.SetNum(static_cast<int>(count)) ||
        !ReadExact(file.file, traceModels.Ptr(),
            static_cast<std::uint64_t>(count) * sizeof(idTraceModel)) ||
        !ReadCount(file.file, MAX_DISCRETE_ITEMS, count) ||
        !transforms.SetNum(static_cast<int>(count)) ||
        !ReadExact(file.file, transforms.Ptr(),
            static_cast<std::uint64_t>(count) * sizeof(idJointMat)) ||
        !ReadCount(file.file, MAX_DISCRETE_SURFACES, count) ||
        !surfaces.SetNum(static_cast<int>(count))) {
        FreeData();
        return false;
    }
    for (int index = 0; index < surfaces.Num(); ++index) {
        surfaces[index] = nullptr;
    }

    for (int index = 0; index < surfaces.Num(); ++index) {
        idDiscreteAnimationModelSurface* surface =
            new (std::nothrow) idDiscreteAnimationModelSurface{};
        idTriangles* triangles = new (std::nothrow) idTriangles{};
        if (surface == nullptr || triangles == nullptr) {
            delete surface;
            delete triangles;
            FreeData();
            return false;
        }
        surface->triangles = triangles;
        triangles->bounds = bounds;
        surfaces[index] = surface;

        std::uint32_t vertexCount = 0;
        std::uint32_t indexCount = 0;
        if (!ReadExact(file.file, &surface->jointOffset,
                sizeof(surface->jointOffset)) ||
            !ReadExact(file.file, &surface->numJoints,
                sizeof(surface->numJoints)) ||
            !ReadCount(file.file, MAX_DISCRETE_ITEMS, vertexCount) ||
            !ReadCount(file.file, MAX_DISCRETE_ITEMS, indexCount)) {
            FreeData();
            return false;
        }
        triangles->numVerts = static_cast<int>(vertexCount);
        triangles->numIndexes = static_cast<int>(indexCount);
        triangles->verts = vertexCount != 0
            ? new (std::nothrow) idDrawVert[vertexCount] : nullptr;
        triangles->indexes = indexCount != 0
            ? new (std::nothrow) std::uint16_t[indexCount] : nullptr;
        if ((vertexCount != 0 && triangles->verts == nullptr) ||
            (indexCount != 0 && triangles->indexes == nullptr) ||
            !ReadExact(file.file, triangles->verts,
                static_cast<std::uint64_t>(vertexCount) *
                    sizeof(idDrawVert)) ||
            !ReadExact(file.file, triangles->indexes,
                static_cast<std::uint64_t>(indexCount) *
                    sizeof(std::uint16_t))) {
            FreeData();
            return false;
        }
    }

    if (!ReadCount(file.file, MAX_DISCRETE_ITEMS, count) ||
        !sourceSurfaces.SetNum(static_cast<int>(count))) {
        FreeData();
        return false;
    }
    for (int index = 0; index < sourceSurfaces.Num(); ++index) {
        sourceSurface_t& source = sourceSurfaces[index];
        if (!ReadString(file.file, text)) {
            FreeData();
            return false;
        }
        source.mtr = materialResolver != nullptr && !text.empty()
            ? materialResolver(text.c_str()) : nullptr;
        if (!ReadExact(file.file, &source.mtrChecksum,
                sizeof(source.mtrChecksum)) ||
            !ReadExact(file.file, &source.renderSurface,
                sizeof(source.renderSurface)) ||
            !ReadExact(file.file, &source.firstVertex,
                sizeof(source.firstVertex)) ||
            !ReadExact(file.file, &source.lastVertex,
                sizeof(source.lastVertex))) {
            FreeData();
            return false;
        }
    }

    std::uint32_t hasBaseModel = 0;
    if (!ReadExact(file.file, &hasBaseModel, sizeof(hasBaseModel)) ||
        hasBaseModel > 1) {
        FreeData();
        return false;
    }
    if (hasBaseModel != 0) {
        if (!ReadString(file.file, text) ||
            collisionModelResolver == nullptr ||
            (baseModel = collisionModelResolver(text.c_str())) == nullptr) {
            FreeData();
            return false;
        }
    }
    ClearResourceError();
    return true;
}

bool idDiscreteAnimationModelData::Generate(
    const char* baseCollisionName) {
    return generateCallback != nullptr &&
        generateCallback(this, baseCollisionName);
}

bool idDiscreteAnimationModelData::ReloadIfStale() {
    if (fileSystem == nullptr) {
        return false;
    }
    bool stale = fileSystem->GetTimestamp(GetName(), false) != timestamp;
    if (!stale && materialChecksumResolver != nullptr) {
        for (int index = 0; index < sourceSurfaces.Num(); ++index) {
            const sourceSurface_t& source = sourceSurfaces[index];
            if (source.mtr != nullptr &&
                materialChecksumResolver(source.mtr) != source.mtrChecksum) {
                stale = true;
                break;
            }
        }
    }
    if (!stale) {
        return false;
    }
    char generatedPath[256] = {};
    if (BuildGeneratedName(GetName(), generatedPath)) {
        fileSystem->RemoveFile(generatedPath, FSPATH_BASE);
    }
    LoadResource();
    return true;
}

void idDiscreteAnimationModelData::LoadResource() {
    FreeData();
    char generatedPath[256] = {};
    const bool hasGeneratedName = BuildGeneratedName(GetName(),
        generatedPath);
    if (!hasGeneratedName || !LoadBinary(generatedPath)) {
        if (!Generate()) {
            SetResourceError(
                "Couldn't load discreteanimationmodeldata '%s'", GetName());
            FreeData();
            return;
        }
        if (hasGeneratedName) {
            WriteBinary(generatedPath);
        }
    }
    RemapSourceSurfaces();
    UpdateBuffers();
    if (freeCPUDataAfterUpload) {
        FreeCPUData();
    }
}
