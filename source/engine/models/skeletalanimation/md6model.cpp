#include "models/skeletalanimation/md6model.h"

#include "idlib/filesystem/file.h"
#include "idlib/filesystem/filesystem.h"
#include "models/skeletalanimation/md6anim.h"
#include "models/skeletalanimation/md6modelgenerator.h"

#include <cstdio>
#include <cstring>
#include <new>

namespace {

constexpr unsigned int MD6_MODEL_MAGIC = 557206861u;
constexpr int MAX_MODEL_ELEMENTS = 1 << 20;

int Pad8(const int value) { return (value + 7) & ~7; }

bool ReadExact(idFile* file, void* data, const unsigned int bytes) {
    return bytes == 0 || (file != nullptr && file->Read(data, bytes) == bytes);
}

bool WriteExact(idFile* file, const void* data, const unsigned int bytes) {
    return bytes == 0 || (file != nullptr && file->Write(data, bytes) == bytes);
}

const idDrawVert* StandardVertices(const idTriangles& triangles) {
    return triangles.verts != nullptr ? triangles.verts
        : static_cast<const idDrawVert*>(triangles.vertexBuffer.apiObject);
}

const std::uint16_t* StandardIndexes(const idTriangles& triangles) {
    return triangles.indexes != nullptr ? triangles.indexes
        : static_cast<const std::uint16_t*>(triangles.indexBuffer.apiObject);
}

bool HasExtension(const char* fileName, const char* extension) {
    if (fileName == nullptr || extension == nullptr) return false;
    const char* dot = std::strrchr(fileName, '.');
    return dot != nullptr && idStr::Icmp(dot + 1, extension) == 0;
}

} // namespace

idTypedResourceList<idMD6Model> idMD6Model::resourceList("model");
idMD6Model::SkeletonResolver idMD6Model::skeletonResolverCallback = nullptr;
idMD6Model::SkeletonNameCallback idMD6Model::skeletonNameCallback = nullptr;
idMD6Model::MaterialResolver idMD6Model::materialResolverCallback = nullptr;
idMD6Model::MaterialNameCallback idMD6Model::materialNameCallback = nullptr;
idMD6Model::ChecksumCallback idMD6Model::checksumCallback = nullptr;
idMD6Model::SourceSurfaceRemapCallback
    idMD6Model::sourceSurfaceRemapCallback = nullptr;
idMD6Model::GenerateCallback idMD6Model::generateCallback = nullptr;
idMD6Model::UserChannelNameCallback
    idMD6Model::userChannelNameCallback = nullptr;

idMD6Model::idMD6Model()
    : timestamp(~0u), skelTimestamp(~0u), remapForSkinning(true),
      skinChecksum(0), morphSkin(-1), numMeshesBeforeSplitting(0),
      skeleton(nullptr), minBoundsExpansion(0.0f, 0.0f, 0.0f),
      maxBoundsExpansion(0.0f, 0.0f, 0.0f) {
    defaultBounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    defaultBounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
}

idMD6Model::~idMD6Model() { FreeData(); }

idResourceList* idMD6Model::GetResourceList() { return &resourceList; }

void idMD6Model::SetResourceCallbacks(SkeletonResolver skeletonResolver,
        SkeletonNameCallback skeletonName, MaterialResolver materialResolver,
        MaterialNameCallback materialName, ChecksumCallback checksum,
        SourceSurfaceRemapCallback remap, GenerateCallback generator,
        UserChannelNameCallback userChannelName) {
    skeletonResolverCallback = skeletonResolver;
    skeletonNameCallback = skeletonName;
    materialResolverCallback = materialResolver;
    materialNameCallback = materialName;
    checksumCallback = checksum;
    sourceSurfaceRemapCallback = remap;
    generateCallback = generator;
    userChannelNameCallback = userChannelName;
    idMD6Mesh::SetMaterialCallbacks(materialResolver, materialName);
}

void idMD6Model::FreeData() {
    for (int index = 0; index < meshes.Num(); ++index) delete meshes[index];
    meshes.ClearFree();
    jointRemap.ClearFree();
    sourceSurfaces.ClearFree();
    materials.ClearFree();
    skeleton = nullptr;
    skinChecksum = 0;
    morphSkin = -1;
    numMeshesBeforeSplitting = 0;
}

bool idMD6Model::GetJointsForAnimFrame(idJointMat* joints,
        const idMD6Anim* animation, const int frame, const idVec3& offset,
        const bool removeOriginOffset) const {
    return skeleton != nullptr && skeleton->GetJointsForAnimFrame(joints,
        animation, frame, offset, removeOriginOffset);
}

bool idMD6Model::GetJointsForAnimTime(idJointMat* joints,
        const idMD6Anim* animation, const int timeMS, const idVec3& offset,
        const bool removeOriginOffset) const {
    return skeleton != nullptr && skeleton->GetJointsForAnimTime(joints,
        animation, timeMS, offset, removeOriginOffset);
}

bool idMD6Model::GetUserChannelsForAnimFrame(float* channels,
        const unsigned int channelsSize, const idMD6Anim* animation,
        const float frame) const {
    return skeleton != nullptr && skeleton->GetUserChannelsForAnimFrame(
        channels, channelsSize, animation, frame);
}

const char* idMD6Model::GetUserChannelName(
        const md6UserChannelIndex_t index) const {
    if (skeleton == nullptr || userChannelNameCallback == nullptr) return "";
    return userChannelNameCallback(skeleton->GetUserChannelHandle(
        static_cast<int>(index)));
}

bool idMD6Model::WriteBinary(const char* fileName) const {
    if (fileSystem == nullptr || fileName == nullptr || skeleton == nullptr ||
            skeleton->data == nullptr || jointRemap.Num() !=
            Pad8(skeleton->data->numJoints)) return false;
    idFileLocal file(fileSystem->OpenFileWrite(fileName, FSPATH_BASE));
    if (file.file == nullptr) return false;
    const char* skeletonName = skeletonNameCallback != nullptr
        ? skeletonNameCallback(skeleton) : skeleton->GetName();
    if (!WriteExact(file.file, &MD6_MODEL_MAGIC, sizeof(MD6_MODEL_MAGIC)) ||
            !WriteExact(file.file, &timestamp, sizeof(timestamp)) ||
            !WriteExact(file.file, &skelTimestamp, sizeof(skelTimestamp)) ||
            file->WriteString(skeletonName != nullptr ? skeletonName : "") <= 0 ||
            !WriteExact(file.file, &minBoundsExpansion,
                sizeof(minBoundsExpansion)) ||
            !WriteExact(file.file, &maxBoundsExpansion,
                sizeof(maxBoundsExpansion)) ||
            !WriteExact(file.file, &remapForSkinning,
                sizeof(remapForSkinning)) ||
            file->WriteString(morphSkinName) <= 0 ||
            !WriteExact(file.file, jointRemap.Ptr(), jointRemap.Num()) ||
            !WriteExact(file.file, &defaultBounds, sizeof(defaultBounds)))
        return false;

    const int meshCount = meshes.Num();
    if (!WriteExact(file.file, &meshCount, sizeof(meshCount))) return false;
    for (int index = 0; index < meshCount; ++index) {
        if (meshes[index] == nullptr) return false;
        meshes[index]->WriteMesh_Binary(file.file);
    }
    const int surfaceCount = sourceSurfaces.Num();
    if (!WriteExact(file.file, &surfaceCount, sizeof(surfaceCount))) return false;
    for (int index = 0; index < surfaceCount; ++index) {
        const sourceSurface_t& surface = sourceSurfaces[index];
        const char* materialName = materialNameCallback != nullptr &&
                surface.mtr != nullptr ? materialNameCallback(surface.mtr) : "";
        if (file->WriteString(materialName != nullptr ? materialName : "") <= 0 ||
                !WriteExact(file.file, &surface.mtrChecksum,
                    sizeof(surface.mtrChecksum)) ||
                !WriteExact(file.file, &surface.renderSurface,
                    sizeof(surface.renderSurface)) ||
                !WriteExact(file.file, &surface.firstVertex,
                    sizeof(surface.firstVertex)) ||
                !WriteExact(file.file, &surface.lastVertex,
                    sizeof(surface.lastVertex))) return false;
    }
    return WriteExact(file.file, &MD6_MODEL_MAGIC, sizeof(MD6_MODEL_MAGIC));
}

bool idMD6Model::LoadBinary(const char* fileName, const bool explicitFile) {
    if (fileSystem == nullptr || fileName == nullptr) return false;
    idFileLocal file(fileSystem->OpenFileRead(fileName, true, false));
    unsigned int magic = 0, newTimestamp = 0, newSkeletonTimestamp = 0;
    idStr skeletonName, newMorphSkin;
    idVec3 newMinExpansion, newMaxExpansion;
    bool newRemap = true;
    if (file.file == nullptr ||
            !ReadExact(file.file, &magic, sizeof(magic)) ||
            magic != MD6_MODEL_MAGIC ||
            !ReadExact(file.file, &newTimestamp, sizeof(newTimestamp)) ||
            (!explicitFile && fileSystem->GetTimestamp(GetName(), false) !=
                newTimestamp) ||
            !ReadExact(file.file, &newSkeletonTimestamp,
                sizeof(newSkeletonTimestamp)) ||
            file->ReadString(skeletonName) <= 0 ||
            (!explicitFile && fileSystem->GetTimestamp(
                skeletonName.c_str(), false) != newSkeletonTimestamp) ||
            !ReadExact(file.file, &newMinExpansion,
                sizeof(newMinExpansion)) ||
            !ReadExact(file.file, &newMaxExpansion,
                sizeof(newMaxExpansion)) ||
            !ReadExact(file.file, &newRemap, sizeof(newRemap)) ||
            file->ReadString(newMorphSkin) <= 0) return false;

    const idMD6Skel* newSkeleton = skeletonResolverCallback != nullptr
        ? skeletonResolverCallback(skeletonName.c_str())
        : static_cast<const idMD6Skel*>(idMD6Skel::resourceList.Load(
            skeletonName.c_str(), true, false));
    if (newSkeleton == nullptr || newSkeleton->data == nullptr) return false;

    idList<unsigned char, 19> newJointRemap;
    const int remapCount = Pad8(newSkeleton->data->numJoints);
    if (!newJointRemap.SetNum(remapCount) ||
            !ReadExact(file.file, newJointRemap.Ptr(), remapCount)) return false;
    idBounds newBounds;
    int meshCount = 0;
    if (!ReadExact(file.file, &newBounds, sizeof(newBounds)) ||
            !ReadExact(file.file, &meshCount, sizeof(meshCount)) ||
            meshCount < 0 || meshCount > MAX_MODEL_ELEMENTS) return false;

    idList<idMD6Mesh*, 19> newMeshes;
    if (!newMeshes.SetNum(meshCount)) return false;
    for (int index = 0; index < meshCount; ++index) newMeshes[index] = nullptr;
    for (int index = 0; index < meshCount; ++index) {
        newMeshes[index] = new (std::nothrow) idMD6Mesh;
        if (newMeshes[index] == nullptr ||
                !newMeshes[index]->LoadMesh_Binary(file.file, magic)) {
            for (int cleanup = 0; cleanup < meshCount; ++cleanup)
                delete newMeshes[cleanup];
            return false;
        }
    }

    int surfaceCount = 0;
    if (!ReadExact(file.file, &surfaceCount, sizeof(surfaceCount)) ||
            surfaceCount < 0 || surfaceCount > MAX_MODEL_ELEMENTS) {
        for (int index = 0; index < meshCount; ++index) delete newMeshes[index];
        return false;
    }
    idList<sourceSurface_t, 5> newSurfaces;
    if (!newSurfaces.SetNum(surfaceCount)) {
        for (int index = 0; index < meshCount; ++index) delete newMeshes[index];
        return false;
    }
    for (int index = 0; index < surfaceCount; ++index) {
        idStr materialName;
        sourceSurface_t surface{};
        if (file->ReadString(materialName) <= 0 ||
                !ReadExact(file.file, &surface.mtrChecksum,
                    sizeof(surface.mtrChecksum)) ||
                !ReadExact(file.file, &surface.renderSurface,
                    sizeof(surface.renderSurface)) ||
                !ReadExact(file.file, &surface.firstVertex,
                    sizeof(surface.firstVertex)) ||
                !ReadExact(file.file, &surface.lastVertex,
                    sizeof(surface.lastVertex))) {
            for (int cleanup = 0; cleanup < meshCount; ++cleanup)
                delete newMeshes[cleanup];
            return false;
        }
        surface.mtr = materialResolverCallback != nullptr &&
                materialName.Length() > 0
            ? materialResolverCallback(materialName.c_str()) : nullptr;
        newSurfaces[index] = surface;
    }
    unsigned int trailingMagic = 0;
    if (!ReadExact(file.file, &trailingMagic, sizeof(trailingMagic)) ||
            trailingMagic != MD6_MODEL_MAGIC) {
        for (int index = 0; index < meshCount; ++index) delete newMeshes[index];
        return false;
    }

    FreeData();
    meshes.Swap(newMeshes);
    jointRemap.Swap(newJointRemap);
    sourceSurfaces.Swap(newSurfaces);
    skeleton = newSkeleton;
    timestamp = newTimestamp;
    skelTimestamp = newSkeletonTimestamp;
    defaultBounds = newBounds;
    remapForSkinning = newRemap;
    morphSkinName = newMorphSkin;
    minBoundsExpansion = newMinExpansion;
    maxBoundsExpansion = newMaxExpansion;
    numMeshesBeforeSplitting = meshes.Num();
    return true;
}

bool idMD6Model::LoadFileNoRemap(const char* fileName) {
    if (fileName == nullptr || fileName[0] == '\0' || fileSystem == nullptr)
        return false;
    FreeData();
    filename = fileName;
    const bool explicitBinary = HasExtension(fileName, "bmd6model");
    char binaryName[1024];
    if (explicitBinary) {
        std::snprintf(binaryName, sizeof(binaryName), "%s", fileName);
    } else if (!fileSystem->FixLongFilename("generated", "bmd6model",
            fileName, binaryName, sizeof(binaryName))) {
        return false;
    }
    if (LoadBinary(binaryName, explicitBinary)) return true;
    if (explicitBinary) return false;
    const bool generated = generateCallback != nullptr
        ? generateCallback(this, fileName)
        : idMD6BinaryGenerator::GenerateModel(this, fileName);
    if (!generated) return false;
    if (skeleton == nullptr || skeleton->data == nullptr) return false;
    if (timestamp == ~0u)
        timestamp = fileSystem->GetTimestamp(fileName, false);
    if (skelTimestamp == ~0u)
        skelTimestamp = fileSystem->GetTimestamp(skeleton->GetName(), false);
    WriteBinary(binaryName);
    return true;
}

void idMD6Model::RemapSourceSurfaces() {
    materials.Clear();
    if (sourceSurfaceRemapCallback != nullptr) {
        sourceSurfaceRemapCallback(this);
        return;
    }
    for (int index = 0; index < sourceSurfaces.Num(); ++index) {
        const idMaterial* material = sourceSurfaces[index].mtr;
        if (material != nullptr) materials.AddUnique(material);
    }
}

void idMD6Model::LoadResource() {
    if (!LoadFileNoRemap(GetName())) {
        FreeData();
        SetResourceError("failed to load MD6 model '%s'", GetName());
        return;
    }
    ClearResourceError();
    RemapSourceSurfaces();
    for (int index = 0; index < meshes.Num(); ++index)
        if (meshes[index] != nullptr) meshes[index]->FreeLoadData();
}

bool idMD6Model::ReloadIfStale() {
    if (HasExtension(GetName(), "bmd6model") || fileSystem == nullptr)
        return false;
    bool stale = fileSystem->GetTimestamp(filename.c_str(), false) != timestamp;
    if (!stale && skeleton != nullptr)
        stale = fileSystem->GetTimestamp(skeleton->GetName(), false) !=
            skelTimestamp;
    if (!stale && checksumCallback != nullptr) {
        for (int index = 0; index < sourceSurfaces.Num(); ++index) {
            const sourceSurface_t& surface = sourceSurfaces[index];
            if (surface.mtr != nullptr && checksumCallback(surface.mtr) !=
                    static_cast<unsigned int>(surface.mtrChecksum)) {
                stale = true;
                break;
            }
        }
    }
    if (!stale) return false;
    LoadResource();
    return true;
}

void idMD6Model::WriteResourceFile() {
    if (fileSystem == nullptr || filename.Length() == 0) return;
    char binaryName[1024];
    if (fileSystem->FixLongFilename("generated", "bmd6model",
            filename.c_str(), binaryName, sizeof(binaryName)))
        WriteBinary(binaryName);
}

unsigned int idMD6Model::Memory() const {
    unsigned int bytes = sizeof(*this) +
        jointRemap.NumAllocated() * sizeof(unsigned char) +
        sourceSurfaces.NumAllocated() * sizeof(sourceSurface_t) +
        materials.NumAllocated() * sizeof(const idMaterial*);
    if (skeleton != nullptr && skeleton->data != nullptr)
        bytes += skeleton->data->size;
    for (int index = 0; index < meshes.Num(); ++index)
        if (meshes[index] != nullptr) bytes += meshes[index]->Memory();
    return bytes;
}

bool TrianglesAreEqual(const idTriangles& first, const idTriangles& second) {
    if (first.numIndexes != second.numIndexes ||
            first.numVerts != second.numVerts ||
            std::memcmp(&first.bounds, &second.bounds,
                sizeof(first.bounds)) != 0) return false;
    const std::uint16_t* firstIndexes = StandardIndexes(first);
    const std::uint16_t* secondIndexes = StandardIndexes(second);
    const idDrawVert* firstVertices = StandardVertices(first);
    const idDrawVert* secondVertices = StandardVertices(second);
    if ((first.numIndexes > 0 && (firstIndexes == nullptr ||
            secondIndexes == nullptr)) || (first.numVerts > 0 &&
            (firstVertices == nullptr || secondVertices == nullptr)))
        return false;
    return std::memcmp(firstIndexes, secondIndexes,
            first.numIndexes * sizeof(std::uint16_t)) == 0 &&
        std::memcmp(firstVertices, secondVertices,
            first.numVerts * sizeof(idDrawVert)) == 0;
}

bool idMD6Model::Equals(const idMD6Model& other) const {
    if (std::memcmp(&defaultBounds, &other.defaultBounds,
            sizeof(defaultBounds)) != 0 ||
            remapForSkinning != other.remapForSkinning ||
            std::memcmp(&minBoundsExpansion, &other.minBoundsExpansion,
                sizeof(minBoundsExpansion)) != 0 ||
            std::memcmp(&maxBoundsExpansion, &other.maxBoundsExpansion,
                sizeof(maxBoundsExpansion)) != 0 ||
            sourceSurfaces.Num() != other.sourceSurfaces.Num() ||
            meshes.Num() != other.meshes.Num()) return false;
    for (int index = 0; index < sourceSurfaces.Num(); ++index) {
        const sourceSurface_t& first = sourceSurfaces[index];
        const sourceSurface_t& second = other.sourceSurfaces[index];
        if (first.mtr != second.mtr ||
                first.renderSurface != second.renderSurface ||
                first.firstVertex != second.firstVertex ||
                first.lastVertex != second.lastVertex) return false;
    }
    for (int index = 0; index < meshes.Num(); ++index) {
        const idMD6Mesh* first = meshes[index];
        const idMD6Mesh* second = other.meshes[index];
        if (first == nullptr || second == nullptr ||
                idStr::Cmp(first->name.c_str(), second->name.c_str()) != 0 ||
                first->material != second->material ||
                first->allowSkinRemapping != second->allowSkinRemapping ||
                std::memcmp(&first->bounds, &second->bounds,
                    sizeof(first->bounds)) != 0 || first->tris == nullptr ||
                second->tris == nullptr ||
                !TrianglesAreEqual(*first->tris, *second->tris)) return false;
    }
    return true;
}

void idMD6Model::Print() {
    std::printf("%s: %d meshes, %d source surfaces, %u bytes\n", GetName(),
        meshes.Num(), sourceSurfaces.Num(), Memory());
}

void idMD6Model::List() { Print(); }
