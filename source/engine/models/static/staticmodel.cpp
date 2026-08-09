#include "models/static/staticmodel.h"

#include "idlib/filesystem/file.h"
#include "idlib/filesystem/filesystem.h"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <new>

namespace {

constexpr unsigned int STATIC_MODEL_MAGIC = 457985346u;
constexpr int MAX_STATIC_ELEMENTS = 1 << 24;

bool ReadExact(idFile* file, void* data, const unsigned int size) {
    return size == 0 || (file != nullptr && file->Read(data, size) == size);
}

bool WriteExact(idFile* file, const void* data, const unsigned int size) {
    return size == 0 || (file != nullptr && file->Write(data, size) == size);
}

int VertexSizeFromMask(const unsigned int mask) {
    return ((mask & 0x1000u) != 0 ? 12 : 0) +
        ((mask & 0x40u) != 0 ? -4 : 0) +
        ((mask & 0x20u) != 0 ? -4 : 0) +
        ((mask & 0x1u) != 0 ? 12 : 0) + ((mask >> 9) & 4u) +
        ((mask >> 2) & 4u) + ((mask >> 1) & 4u) +
        ((4u * mask) & 8u) + (mask & 4u);
}

void ClearBounds(idBounds& bounds) {
    bounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    bounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
}

void AddBounds(idBounds& destination, const idBounds& source) {
    for (int axis = 0; axis < 3; ++axis) {
        destination[0][axis] = (std::min)(destination[0][axis],
            source[0][axis]);
        destination[1][axis] = (std::max)(destination[1][axis],
            source[1][axis]);
    }
}

void DeleteGeometry(idTriangles* geometry,
        idStaticModel::BufferReleaseCallback releaseCallback) {
    if (geometry == nullptr) return;
    if (releaseCallback != nullptr) releaseCallback(geometry);
    delete[] geometry->verts;
    delete[] geometry->indexes;
    if (geometry->vertexBuffer.apiObject != geometry->verts)
        delete[] static_cast<unsigned char*>(geometry->vertexBuffer.apiObject);
    if (geometry->indexBuffer.apiObject != geometry->indexes)
        delete[] static_cast<unsigned char*>(geometry->indexBuffer.apiObject);
    geometry->verts = nullptr;
    geometry->indexes = nullptr;
    geometry->vertexBuffer.apiObject = nullptr;
    geometry->indexBuffer.apiObject = nullptr;
    delete geometry;
}

idTriangles* CopyGeometry(const idTriangles* source) {
    if (source == nullptr) return nullptr;
    idTriangles* destination = new (std::nothrow) idTriangles{};
    if (destination == nullptr) return nullptr;
    destination->bounds = source->bounds;
    destination->generateNormals = source->generateNormals;
    destination->numIndexes = source->numIndexes;
    destination->numVerts = source->numVerts;
    destination->detailOffset = source->detailOffset;
    destination->allowGpuHosting = source->allowGpuHosting;
    destination->vsb = source->vsb;
    destination->cpuVertexMask = 0x1Fu;
    destination->vertexMask = 0x1Fu;
    const idDrawVert* vertices = source->verts;
    if (vertices == nullptr && source->vertexMask == 0x1Fu)
        vertices = static_cast<const idDrawVert*>(
            source->vertexBuffer.apiObject);
    const std::uint16_t* indexes = source->indexes != nullptr
        ? source->indexes : static_cast<const std::uint16_t*>(
            source->indexBuffer.apiObject);
    if (source->numVerts > 0 && vertices != nullptr) {
        destination->verts = new idDrawVert[source->numVerts];
        std::memcpy(destination->verts, vertices,
            source->numVerts * sizeof(idDrawVert));
    }
    if (source->numIndexes > 0 && indexes != nullptr) {
        destination->indexes = new std::uint16_t[source->numIndexes];
        std::memcpy(destination->indexes, indexes,
            source->numIndexes * sizeof(std::uint16_t));
    }
    return destination;
}

void FillCubeVertices(idDrawVert* vertices, const float low,
        const float high) {
    const idVec3 positions[8] = {
        {low, low, low}, {high, low, low}, {high, high, low},
        {low, high, low}, {low, low, high}, {high, low, high},
        {high, high, high}, {low, high, high}
    };
    for (int index = 0; index < 8; ++index) {
        std::memset(&vertices[index], 0, sizeof(vertices[index]));
        vertices[index].xyz = positions[index];
        vertices[index].st.Set((index & 1) ? 1.0f : 0.0f,
            (index & 2) ? 1.0f : 0.0f);
        vertices[index].SetNormal(idVec3(0.0f, 0.0f, 1.0f));
        vertices[index].SetTangent(idVec3(1.0f, 0.0f, 0.0f));
        vertices[index].tangent[3] = 255;
        std::memset(vertices[index].color, 255, 4);
    }
}

} // namespace

idTypedResourceList<idStaticModel> idStaticModel::resourceList("model");
idStaticModel::MaterialResolver idStaticModel::materialResolverCallback = nullptr;
idStaticModel::MaterialNameCallback idStaticModel::materialNameCallback = nullptr;
idStaticModel::MaterialChecksumCallback
    idStaticModel::materialChecksumCallback = nullptr;
idStaticModel::GenerateCallback idStaticModel::generateCallback = nullptr;
idStaticModel::BufferUpdateCallback idStaticModel::bufferUpdateCallback = nullptr;
idStaticModel::BufferReleaseCallback idStaticModel::bufferReleaseCallback = nullptr;
idStaticModel::SourceSurfaceRemapCallback
    idStaticModel::sourceSurfaceRemapCallback = nullptr;
idStaticModel::MaterialTraitsCallback idStaticModel::materialTraitsCallback =
    nullptr;

idStaticModel::idStaticModel()
    : pristine(false), isReloadable(false), binaryTimeStamp(~0u),
      sourceTimeStamp(~0u), reloadCount(0), modelIsAutosprite(false),
      usesTransparencySort(false), referencePosition(0.0f, 0.0f, 0.0f),
      sharedSurfaces(false), modelLoadFlags(MODELLOADFLAGS_DEFAULT) {
    binaryFileName[0] = '\0';
    referenceBounds[0].Zero();
    referenceBounds[1].Zero();
}

idStaticModel::~idStaticModel() {
    FreeSurfaces();
}

idResourceList* idStaticModel::GetResourceList() { return &resourceList; }

void idStaticModel::SetCallbacks(MaterialResolver materialResolver,
        MaterialNameCallback materialName,
        MaterialChecksumCallback materialChecksum, GenerateCallback generator,
        BufferUpdateCallback updateBuffers, BufferReleaseCallback releaseBuffers,
        SourceSurfaceRemapCallback remapSurfaces) {
    materialResolverCallback = materialResolver;
    materialNameCallback = materialName;
    materialChecksumCallback = materialChecksum;
    generateCallback = generator;
    bufferUpdateCallback = updateBuffers;
    bufferReleaseCallback = releaseBuffers;
    sourceSurfaceRemapCallback = remapSurfaces;
}

void idStaticModel::SetMaterialTraitsCallback(
        MaterialTraitsCallback callback) {
    materialTraitsCallback = callback;
}

const idMaterial* idStaticModel::ResolveMaterial(const char* name) {
    return materialResolverCallback != nullptr
        ? materialResolverCallback(name != nullptr ? name : "") : nullptr;
}

const char* idStaticModel::MaterialName(const idMaterial* material) {
    const char* result = materialNameCallback != nullptr && material != nullptr
        ? materialNameCallback(material) : "";
    return result != nullptr ? result : "";
}

int idStaticModel::MaterialChecksum(const idMaterial* material) {
    return materialChecksumCallback != nullptr && material != nullptr
        ? materialChecksumCallback(material) : 0;
}

void idStaticModel::FreeSurfaces() {
    ++reloadCount;
    if (!sharedSurfaces) {
        for (int index = 0; index < surfaces.Num(); ++index) {
            idStaticModelSurface& surface = surfaces[index];
            if (!surface.geometryIsReference)
                DeleteGeometry(surface.geometry, bufferReleaseCallback);
            surface.geometry = nullptr;
        }
    }
    surfaces.ClearFree();
    sourceSurfaces.ClearFree();
    materials.ClearFree();
    sharedSurfaces = false;
}

void idStaticModel::AddSurface(const idStaticModelSurface& surface) {
    surfaces.Append(surface);
}

int idStaticModel::CPUMemory() const {
    int total = sizeof(*this) + surfaces.MemoryUsed() +
        sourceSurfaces.MemoryUsed() + materials.MemoryUsed();
    for (int index = 0; index < surfaces.Num(); ++index) {
        const idTriangles* geometry = surfaces[index].geometry;
        if (geometry == nullptr) continue;
        total += sizeof(*geometry);
        if (geometry->verts != nullptr)
            total += geometry->numVerts * static_cast<int>(sizeof(idDrawVert));
        if (geometry->indexes != nullptr)
            total += geometry->numIndexes *
                static_cast<int>(sizeof(std::uint16_t));
    }
    return total;
}

int idStaticModel::GPUMemory() const {
    int total = 0;
    for (int index = 0; index < surfaces.Num(); ++index) {
        const idTriangles* geometry = surfaces[index].geometry;
        if (geometry != nullptr)
            total += geometry->vertexBuffer.size + geometry->indexBuffer.size;
    }
    return total;
}

void idStaticModel::UpdateBuffers() {
    if (bufferUpdateCallback == nullptr) return;
    for (int index = 0; index < surfaces.Num(); ++index)
        if (surfaces[index].geometry != nullptr)
            bufferUpdateCallback(surfaces[index].geometry);
}

void idStaticModel::FreeCPUData() {
    for (int index = 0; index < surfaces.Num(); ++index) {
        idTriangles* geometry = surfaces[index].geometry;
        if (geometry == nullptr || geometry->vertexBuffer.apiObject == nullptr ||
            geometry->indexBuffer.apiObject == nullptr) continue;
        delete[] geometry->verts;
        delete[] geometry->indexes;
        geometry->verts = nullptr;
        geometry->indexes = nullptr;
    }
}

void idStaticModel::RemapSourceSurfaces() {
    materials.Clear();
    if (sourceSurfaceRemapCallback != nullptr) {
        sourceSurfaceRemapCallback(this);
        return;
    }
    for (int index = 0; index < surfaces.Num(); ++index) {
        const idMaterial* material = surfaces[index].material;
        if (material != nullptr) materials.AddUnique(material);
    }
}

void idStaticModel::FinishStaticModel(bool) {
    ClearBounds(referenceBounds);
    bool found = false;
    for (int index = 0; index < surfaces.Num(); ++index) {
        const idTriangles* geometry = surfaces[index].geometry;
        if (geometry == nullptr || geometry->numVerts <= 0) continue;
        AddBounds(referenceBounds, geometry->bounds);
        found = true;
    }
    if (!found) {
        referenceBounds[0].Zero();
        referenceBounds[1].Zero();
    }
    referencePosition = (referenceBounds[0] + referenceBounds[1]) * 0.5f;
    if (sourceSurfaces.Num() == 0) {
        sourceSurfaces.SetNum(surfaces.Num());
        for (int index = 0; index < surfaces.Num(); ++index) {
            sourceSurface_t source{};
            source.mtr = surfaces[index].material;
            source.mtrChecksum = materialChecksumCallback != nullptr &&
                    source.mtr != nullptr
                ? materialChecksumCallback(source.mtr) : 0;
            source.renderSurface = index;
            source.firstVertex = 0;
            source.lastVertex = surfaces[index].geometry != nullptr
                ? surfaces[index].geometry->numVerts - 1 : -1;
            sourceSurfaces[index] = source;
        }
    }
    RemapSourceSurfaces();
}

void idStaticModel::MakeSimpleCube(const float low, const float high) {
    FreeSurfaces();
    idTriangles* geometry = new idTriangles{};
    geometry->numVerts = 8;
    geometry->numIndexes = 36;
    geometry->allowGpuHosting = true;
    geometry->cpuVertexMask = geometry->vertexMask = 0x1Fu;
    geometry->verts = new idDrawVert[8];
    geometry->indexes = new std::uint16_t[36]{
        0,2,1, 0,3,2, 4,5,6, 4,6,7,
        0,1,5, 0,5,4, 1,2,6, 1,6,5,
        2,3,7, 2,7,6, 3,0,4, 3,4,7
    };
    FillCubeVertices(geometry->verts, low, high);
    geometry->bounds[0].Set(low, low, low);
    geometry->bounds[1].Set(high, high, high);
    idStaticModelSurface surface;
    surface.geometry = geometry;
    AddSurface(surface);
    FinishStaticModel(false);
}

void idStaticModel::MakeExtrudeBox() { MakeSimpleCube(-8.0f, 8.0f); }

void idStaticModel::MakeDefaultModel(const float low, const float high) {
    MakeSimpleCube(low, high);
    isReloadable = false;
}

bool idStaticModel::WriteBinaryModel(const char* fileName) const {
    if (fileSystem == nullptr || fileName == nullptr) return false;
    idFileLocal file(fileSystem->OpenFileWrite(fileName, FSPATH_BASE));
    if (file.file == nullptr ||
        !WriteExact(file.file, &STATIC_MODEL_MAGIC, 4) ||
        !WriteExact(file.file, &sourceTimeStamp, 4)) return false;
    const int surfaceCount = surfaces.Num();
    if (!WriteExact(file.file, &surfaceCount, 4)) return false;
    for (int index = 0; index < surfaces.Num(); ++index) {
        const idStaticModelSurface& surface = surfaces[index];
        const idTriangles* geometry = surface.geometry;
        const char* materialName = materialNameCallback != nullptr &&
                surface.material != nullptr
            ? materialNameCallback(surface.material) : "";
        if (geometry == nullptr ||
            file->WriteString(materialName != nullptr ? materialName : "") <= 0 ||
            !WriteExact(file.file, &surface.materialNum, 4) ||
            !WriteExact(file.file, &surface.binaryModelId, 4)) return false;
        const int numVerts = geometry->numVerts;
        const int numIndexes = geometry->numIndexes;
        const unsigned int mask = geometry->verts != nullptr
            ? 0x1Fu : geometry->vertexMask;
        if (!WriteExact(file.file, &numVerts, 4) ||
            !WriteExact(file.file, &numIndexes, 4) ||
            !WriteExact(file.file, &mask, 4) ||
            !WriteExact(file.file, &geometry->vsb, sizeof(geometry->vsb)))
            return false;
        const void* vertexData = geometry->verts != nullptr
            ? static_cast<const void*>(geometry->verts)
            : geometry->vertexBuffer.apiObject;
        const unsigned int vertexBytes = numVerts *
            (mask == 0x1Fu ? sizeof(idDrawVert) : VertexSizeFromMask(mask));
        const void* indexData = geometry->indexes != nullptr
            ? static_cast<const void*>(geometry->indexes)
            : geometry->indexBuffer.apiObject;
        if ((vertexBytes > 0 && vertexData == nullptr) ||
            (numIndexes > 0 && indexData == nullptr) ||
            !WriteExact(file.file, vertexData, vertexBytes) ||
            !WriteExact(file.file, indexData,
                numIndexes * sizeof(std::uint16_t)) ||
            !WriteExact(file.file, &geometry->bounds, sizeof(idBounds)) ||
            !WriteExact(file.file, &geometry->detailOffset, 4) ||
            !WriteExact(file.file, &STATIC_MODEL_MAGIC, 4)) return false;
    }
    const int sourceCount = sourceSurfaces.Num();
    if (!WriteExact(file.file, &sourceCount, 4)) return false;
    for (int index = 0; index < sourceCount; ++index) {
        const sourceSurface_t& surface = sourceSurfaces[index];
        const char* name = materialNameCallback != nullptr &&
                surface.mtr != nullptr ? materialNameCallback(surface.mtr) : "";
        if (file->WriteString(name != nullptr ? name : "") <= 0 ||
            !WriteExact(file.file, &surface.mtrChecksum, 4) ||
            !WriteExact(file.file, &surface.renderSurface, 4) ||
            !WriteExact(file.file, &surface.firstVertex, 4) ||
            !WriteExact(file.file, &surface.lastVertex, 4)) return false;
    }
    return true;
}

bool idStaticModel::ReadStaticBModel(const char* fileName) {
    if (fileSystem == nullptr || fileName == nullptr) return false;
    idFileLocal file(fileSystem->OpenFileRead(fileName, true, false));
    unsigned int magic = 0, timestamp = 0;
    int surfaceCount = 0;
    if (file.file == nullptr || !ReadExact(file.file, &magic, 4) ||
        magic != STATIC_MODEL_MAGIC || !ReadExact(file.file, &timestamp, 4) ||
        !ReadExact(file.file, &surfaceCount, 4) || surfaceCount < 0 ||
        surfaceCount > MAX_STATIC_ELEMENTS) return false;

    idList<idStaticModelSurface, 84> loadedSurfaces;
    const auto discardLoaded = [&]() {
        for (int loaded = 0; loaded < loadedSurfaces.Num(); ++loaded) {
            DeleteGeometry(loadedSurfaces[loaded].geometry,
                bufferReleaseCallback);
            loadedSurfaces[loaded].geometry = nullptr;
        }
        loadedSurfaces.Clear();
        return false;
    };
    for (int index = 0; index < surfaceCount; ++index) {
        idStr materialName;
        idStaticModelSurface surface;
        int numVerts = 0, numIndexes = 0;
        unsigned int mask = 0;
        if (file->ReadString(materialName) <= 0 ||
            !ReadExact(file.file, &surface.materialNum, 4) ||
            !ReadExact(file.file, &surface.binaryModelId, 4) ||
            !ReadExact(file.file, &numVerts, 4) ||
            !ReadExact(file.file, &numIndexes, 4) ||
            !ReadExact(file.file, &mask, 4) || numVerts < 0 ||
            numIndexes < 0 || numVerts > MAX_STATIC_ELEMENTS ||
            numIndexes > MAX_STATIC_ELEMENTS) return discardLoaded();
        idTriangles* geometry = new (std::nothrow) idTriangles{};
        if (geometry == nullptr ||
            !ReadExact(file.file, &geometry->vsb, sizeof(geometry->vsb))) {
            DeleteGeometry(geometry, bufferReleaseCallback);
            return discardLoaded();
        }
        geometry->numVerts = numVerts;
        geometry->numIndexes = numIndexes;
        geometry->vertexMask = geometry->cpuVertexMask = mask;
        geometry->allowGpuHosting = (modelLoadFlags &
            MODELLOADFLAGS_RESIDE_ON_GPU) != 0;
        const unsigned int vertexBytes = numVerts *
            (mask == 0x1Fu ? sizeof(idDrawVert) : VertexSizeFromMask(mask));
        if (mask == 0x1Fu ||
            (modelLoadFlags & MODELLOADFLAGS_RESIDE_ON_CPU) != 0) {
            geometry->verts = numVerts > 0 ? new idDrawVert[numVerts] : nullptr;
            if (mask != 0x1Fu) {
                // Retain non-standard console/packed data in the renderer
                // buffer; scalar unpacking belongs to the renderer adapter.
                delete[] geometry->verts;
                geometry->verts = nullptr;
            }
        }
        void* vertexTarget = geometry->verts;
        if (vertexTarget == nullptr && vertexBytes > 0) {
            geometry->vertexBuffer.apiObject = new unsigned char[vertexBytes];
            geometry->vertexBuffer.size = vertexBytes;
            geometry->vertexBuffer.usage = BU_STATIC;
            vertexTarget = geometry->vertexBuffer.apiObject;
        }
        geometry->indexes = numIndexes > 0
            ? new std::uint16_t[numIndexes] : nullptr;
        if (!ReadExact(file.file, vertexTarget, vertexBytes) ||
            !ReadExact(file.file, geometry->indexes,
                numIndexes * sizeof(std::uint16_t)) ||
            !ReadExact(file.file, &geometry->bounds, sizeof(idBounds)) ||
            !ReadExact(file.file, &geometry->detailOffset, 4) ||
            !ReadExact(file.file, &magic, 4) || magic != STATIC_MODEL_MAGIC) {
            DeleteGeometry(geometry, bufferReleaseCallback);
            return discardLoaded();
        }
        surface.material = materialResolverCallback != nullptr
            ? materialResolverCallback(materialName.c_str()) : nullptr;
        surface.geometry = geometry;
        loadedSurfaces.Append(surface);
    }

    int sourceCount = 0;
    if (!ReadExact(file.file, &sourceCount, 4) || sourceCount < 0 ||
        sourceCount > MAX_STATIC_ELEMENTS) return discardLoaded();
    idList<sourceSurface_t, 5> loadedSources;
    loadedSources.SetNum(sourceCount);
    for (int index = 0; index < sourceCount; ++index) {
        idStr materialName;
        sourceSurface_t source{};
        if (file->ReadString(materialName) <= 0 ||
            !ReadExact(file.file, &source.mtrChecksum, 4) ||
            !ReadExact(file.file, &source.renderSurface, 4) ||
            !ReadExact(file.file, &source.firstVertex, 4) ||
            !ReadExact(file.file, &source.lastVertex, 4))
            return discardLoaded();
        source.mtr = materialResolverCallback != nullptr
            ? materialResolverCallback(materialName.c_str()) : nullptr;
        loadedSources[index] = source;
    }

    FreeSurfaces();
    surfaces.Swap(loadedSurfaces);
    sourceSurfaces.Swap(loadedSources);
    sourceTimeStamp = timestamp != 0 && timestamp != ~0u
        ? timestamp : file->Timestamp();
    binaryTimeStamp = file->Timestamp();
    FinishStaticModel(false);
    if ((modelLoadFlags & MODELLOADFLAGS_RESIDE_ON_GPU) != 0) UpdateBuffers();
    return true;
}

void idStaticModel::PristineLoadResource() {
    pristine = true;
    LoadResource();
}

void idStaticModel::LoadResource() {
    isReloadable = true;
    if (fileSystem == nullptr) {
        MakeDefaultModel();
        return;
    }
    const char* resourceName = GetName();
    const bool binaryName = std::strstr(resourceName, ".bmodel") != nullptr ||
        std::strstr(resourceName, ".pmodel") != nullptr;
    if (binaryName) {
        std::snprintf(binaryFileName, sizeof(binaryFileName), "%s",
            resourceName);
    } else if (!fileSystem->FixLongFilename("generated",
            pristine ? "pmodel" : "bmodel", resourceName,
            binaryFileName, sizeof(binaryFileName))) {
        MakeDefaultModel();
        return;
    }
    if ((!pristine || binaryName) && ReadStaticBModel(binaryFileName)) return;
    if (binaryName) {
        MakeDefaultModel();
        return;
    }
    sourceTimeStamp = fileSystem->GetTimestamp(resourceName, false);
    const bool generated = generateCallback != nullptr
        ? generateCallback(this, resourceName, binaryFileName)
        : GenerateStaticModel(resourceName);
    if (generated) {
        FinishStaticModel(true);
        WriteBinaryModel(binaryFileName);
        binaryTimeStamp = fileSystem->GetTimestamp(binaryFileName, false);
        return;
    }
    MakeDefaultModel();
}

bool idStaticModel::ReloadIfStale() {
    if (!isReloadable || fileSystem == nullptr) return false;
    bool stale = fileSystem->GetTimestamp(binaryFileName, false) !=
        binaryTimeStamp;
    if (!stale && std::strstr(GetName(), ".bmodel") == nullptr)
        stale = fileSystem->GetTimestamp(GetName(), false) != sourceTimeStamp;
    if (!stale) return false;
    LoadResource();
    return true;
}

void idStaticModel::WriteResourceFile() {
    WriteBinaryModel(binaryFileName);
}

bool idStaticModel::WriteStaticModel(const char* fileName, unsigned int,
        const idList<idStaticModelSurface, 84>& modelSurfaces,
        const fsPath_t basePath) {
    if (fileSystem == nullptr || fileName == nullptr) return false;
    idStr outputName(fileName);
    outputName.StripFileExtension();
    outputName.Append(".model");
    idFileLocal file(fileSystem->OpenFileWrite(outputName.c_str(), basePath));
    if (file.file == nullptr) return false;
    file->Printf("%d\n", modelSurfaces.Num());
    for (int surfaceIndex = 0; surfaceIndex < modelSurfaces.Num();
         ++surfaceIndex) {
        const idStaticModelSurface& surface = modelSurfaces[surfaceIndex];
        const idTriangles* geometry = surface.geometry;
        if (geometry == nullptr || geometry->verts == nullptr ||
            geometry->indexes == nullptr) continue;
        const char* material = materialNameCallback != nullptr &&
                surface.material != nullptr
            ? materialNameCallback(surface.material) : "";
        file->Printf("{\n\"%s\" %d %d\n", material != nullptr ? material : "",
            geometry->numVerts, geometry->numIndexes);
        for (int vertex = 0; vertex < geometry->numVerts; ++vertex) {
            const idDrawVert& drawVertex = geometry->verts[vertex];
            const idVec3 normal = drawVertex.GetNormal();
            file->Printf("%g %g %g %g %g %g %g %g\n",
                drawVertex.xyz.x, drawVertex.xyz.y, drawVertex.xyz.z,
                drawVertex.st.x, drawVertex.st.y,
                normal.x, normal.y, normal.z);
        }
        for (int index = 0; index < geometry->numIndexes; ++index) {
            file->Printf("%u%c", geometry->indexes[index],
                index % 20 == 19 ? '\n' : ' ');
        }
        file->Printf("\n}\n");
    }
    return true;
}

void idStaticModel::WriteStaticModel() const {
    WriteStaticModel(GetName(), sourceTimeStamp, surfaces, FSPATH_BASE);
}

void idStaticModel::Print() {
    std::printf("%s\nStatic model.\n    verts  indx material\n", GetName());
    for (int index = 0; index < surfaces.Num(); ++index) {
        const idStaticModelSurface& surface = surfaces[index];
        const idTriangles* geometry = surface.geometry;
        const char* name = materialNameCallback != nullptr &&
                surface.material != nullptr
            ? materialNameCallback(surface.material) : "<none>";
        std::printf("%2d: %5d %5d %s\n", index,
            geometry != nullptr ? geometry->numVerts : 0,
            geometry != nullptr ? geometry->numIndexes : 0,
            name != nullptr ? name : "<none>");
    }
}

void idStaticModel::List() {
    int vertices = 0, triangles = 0;
    for (int index = 0; index < surfaces.Num(); ++index) {
        if (surfaces[index].geometry == nullptr) continue;
        vertices += surfaces[index].geometry->numVerts;
        triangles += surfaces[index].geometry->numIndexes / 3;
    }
    std::printf("%8dK %6d verts %6d tris %s\n", CPUMemory() / 1024,
        vertices, triangles, GetName());
}

idStaticModel* PristineModelFromOptimizedModel(
        const idStaticModel& optimizedModel) {
    idStaticModel* result = new (std::nothrow) idStaticModel;
    if (result == nullptr) return nullptr;
    result->SetName(optimizedModel.GetName());
    result->pristine = true;
    result->isReloadable = false;
    result->sourceTimeStamp = optimizedModel.sourceTimeStamp;
    result->modelIsAutosprite = optimizedModel.modelIsAutosprite;
    result->usesTransparencySort = optimizedModel.usesTransparencySort;
    for (int index = 0; index < optimizedModel.surfaces.Num(); ++index) {
        idStaticModelSurface surface = optimizedModel.surfaces[index];
        surface.geometry = CopyGeometry(surface.geometry);
        surface.geometryIsReference = false;
        result->AddSurface(surface);
    }
    result->sourceSurfaces = optimizedModel.sourceSurfaces;
    result->FinishStaticModel(false);
    return result;
}
