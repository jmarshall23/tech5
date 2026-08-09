#include "models/skeletalanimation/md6mesh.h"

#include "idlib/filesystem/file.h"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <new>

namespace {

constexpr unsigned int MD6_MESH_STSET_MAGIC = 0x21364D4Du;
constexpr int MAX_MESH_ELEMENTS = 1 << 24;

template<typename Type>
bool ReadValue(idFile* file, Type& value) {
    return file != nullptr && file->Read(&value, sizeof(value)) ==
        sizeof(value);
}

template<typename Type>
bool WriteValue(idFile* file, const Type& value) {
    return file != nullptr && file->Write(&value, sizeof(value)) ==
        sizeof(value);
}

bool ReadBytes(idFile* file, void* data, unsigned int bytes) {
    return bytes == 0 || (file != nullptr && file->Read(data, bytes) == bytes);
}

bool WriteBytes(idFile* file, const void* data, unsigned int bytes) {
    return bytes == 0 || (file != nullptr && file->Write(data, bytes) == bytes);
}

} // namespace

idMD6Mesh::MaterialResolver idMD6Mesh::materialResolver = nullptr;
idMD6Mesh::MaterialNameCallback idMD6Mesh::materialNameCallback = nullptr;
idMD6Mesh::BufferUploadCallback idMD6Mesh::bufferUploadCallback = nullptr;
idMD6Mesh::BufferReleaseCallback idMD6Mesh::bufferReleaseCallback = nullptr;

std::uint8_t CompressWeightsToByte(const std::uint8_t weights[4]) {
    if (weights == nullptr) return 0;
    const int second = std::clamp(15 - static_cast<int>(
        weights[1] * (2.0f / 17.0f) + 0.5f), 0, 15);
    const int third = std::clamp(3 - static_cast<int>(
        weights[2] * (3.0f / 85.0f) + 0.5f), 0, 3);
    const int fourth = std::clamp(3 - static_cast<int>(
        weights[3] * (4.0f / 85.0f) + 0.5f), 0, 3);
    return static_cast<std::uint8_t>((second << 4) | (third << 2) | fourth);
}

idMD6Mesh::idMD6Mesh()
    : material(nullptr), discrete(false), allowSkinRemapping(false),
      numTexCoordSets(0), numVerts(0), numTris(0), jointOffset(0),
      numJoints(0), hashST(0), tris(new (std::nothrow) idTriangles{}) {
    bounds[0].Zero();
    bounds[1].Zero();
    if (tris != nullptr) {
        tris->vertexMask = 31;
        tris->cpuVertexMask = 31;
    }
}

idMD6Mesh::~idMD6Mesh() { Free(); }

void idMD6Mesh::SetMaterialCallbacks(MaterialResolver resolver,
        MaterialNameCallback nameCallback) {
    materialResolver = resolver;
    materialNameCallback = nameCallback;
}

const char* idMD6Mesh::MaterialName(const idMaterial* material) {
    const char* result = materialNameCallback != nullptr && material != nullptr
        ? materialNameCallback(material) : "";
    return result != nullptr ? result : "";
}

void idMD6Mesh::SetBufferCallbacks(BufferUploadCallback upload,
        BufferReleaseCallback release) {
    bufferUploadCallback = upload;
    bufferReleaseCallback = release;
}

unsigned int idMD6Mesh::Memory() const {
    unsigned int bytes = sizeof(*this) +
        vertexes.NumAllocated() * sizeof(vert_t) +
        indexes.NumAllocated() * sizeof(std::uint16_t) +
        morphMap.NumAllocated() + skinRemaps.NumAllocated() * sizeof(skinRemap_t) +
        stSets.NumAllocated() * sizeof(stset_t);
    for (int index = 0; index < stSets.Num(); ++index)
        bytes += stSets[index].st.NumAllocated() * sizeof(idVec2);
    if (tris != nullptr) {
        bytes += sizeof(*tris) + tris->numVerts * sizeof(idDrawVert) +
            tris->numIndexes * sizeof(std::uint16_t);
    }
    return bytes;
}

void idMD6Mesh::WriteMesh_Binary(idFile* file) const {
    if (file == nullptr || tris == nullptr) return;
    file->WriteString(name);
    const char* materialName = materialNameCallback != nullptr &&
            material != nullptr ? materialNameCallback(material) : "";
    file->WriteString(materialName != nullptr ? materialName : "");
    WriteValue(file, allowSkinRemapping);
    WriteValue(file, numTexCoordSets);
    WriteValue(file, numVerts);
    WriteValue(file, numTris);
    WriteValue(file, bounds);
    const idDrawVert* vertices = tris->verts != nullptr ? tris->verts
        : static_cast<const idDrawVert*>(tris->vertexBuffer.apiObject);
    const std::uint16_t* triangleIndices = tris->indexes != nullptr
        ? tris->indexes
        : static_cast<const std::uint16_t*>(tris->indexBuffer.apiObject);
    WriteBytes(file, vertices, numVerts * sizeof(idDrawVert));
    WriteBytes(file, triangleIndices, numTris * 3 * sizeof(std::uint16_t));
    WriteValue(file, jointOffset);
    WriteValue(file, numJoints);
    const int stSetCount = stSets.Num();
    WriteValue(file, stSetCount);
    for (int index = 0; index < stSetCount; ++index) {
        WriteValue(file, stSets[index].slot);
        WriteBytes(file, stSets[index].st.Ptr(),
            numVerts * sizeof(idVec2));
    }
    const std::uint8_t hasMorphMap = morphMap.Num() >= numVerts * 4 ? 1 : 0;
    WriteValue(file, hasMorphMap);
    if (hasMorphMap != 0)
        WriteBytes(file, morphMap.Ptr(), numVerts * 4);
}

bool idMD6Mesh::LoadMesh_Binary(idFile* file, unsigned int magic) {
    if (file == nullptr) return false;
    Free();
    tris = new (std::nothrow) idTriangles{};
    if (tris == nullptr) return false;
    idStr materialName;
    file->ReadString(name);
    file->ReadString(materialName);
    material = materialResolver != nullptr && materialName.Length() > 0
        ? materialResolver(materialName.c_str()) : nullptr;
    if (!ReadValue(file, allowSkinRemapping)) return false;
    if (magic == MD6_MESH_STSET_MAGIC) {
        if (!ReadValue(file, numTexCoordSets)) return false;
    } else {
        numTexCoordSets = 0;
    }
    if (!ReadValue(file, numVerts) || !ReadValue(file, numTris) ||
            numVerts < 0 || numVerts > MAX_MESH_ELEMENTS || numTris < 0 ||
            numTris > MAX_MESH_ELEMENTS / 3 || !ReadValue(file, bounds))
        return false;
    tris->numVerts = numVerts;
    tris->numIndexes = numTris * 3;
    tris->vertexMask = 31;
    tris->cpuVertexMask = 31;
    tris->bounds = bounds;
    tris->verts = numVerts > 0
        ? new (std::nothrow) idDrawVert[numVerts] : nullptr;
    tris->indexes = tris->numIndexes > 0
        ? new (std::nothrow) std::uint16_t[tris->numIndexes] : nullptr;
    if ((numVerts > 0 && tris->verts == nullptr) ||
            (tris->numIndexes > 0 && tris->indexes == nullptr) ||
            !ReadBytes(file, tris->verts, numVerts * sizeof(idDrawVert)) ||
            !ReadBytes(file, tris->indexes,
                tris->numIndexes * sizeof(std::uint16_t)) ||
            !ReadValue(file, jointOffset) || !ReadValue(file, numJoints))
        return false;

    int stSetCount = 0;
    if (magic == MD6_MESH_STSET_MAGIC) {
        if (!ReadValue(file, stSetCount) || stSetCount < 0 ||
                stSetCount > 256) return false;
    } else {
        stSetCount = std::max(0, numTexCoordSets);
    }
    stSets.SetNum(stSetCount);
    for (int index = 0; index < stSetCount; ++index) {
        stSets[index].slot = 0;
        stSets[index].vb = nullptr;
        stSets[index].st.SetNum(numVerts);
        if (!ReadValue(file, stSets[index].slot) ||
                !ReadBytes(file, stSets[index].st.Ptr(),
                    numVerts * sizeof(idVec2))) return false;
    }
    numTexCoordSets = stSetCount;

    std::uint8_t hasMorphMap = 0;
    if (!ReadValue(file, hasMorphMap)) return false;
    if (hasMorphMap != 0) {
        morphMap.SetNum(numVerts * 4);
        if (!ReadBytes(file, morphMap.Ptr(), morphMap.Num())) return false;
    }
    CreateHashST();
    return true;
}

void idMD6Mesh::CreateHashST() {
    if (stSets.Num() == 0) { hashST = 0; return; }
    char text[2048];
    int length = std::snprintf(text, sizeof(text), "%d", stSets.Num());
    for (int index = 0; index < stSets.Num() &&
            length > 0 && length < static_cast<int>(sizeof(text)); ++index) {
        length += std::snprintf(text + length, sizeof(text) - length,
            "_%u", static_cast<unsigned int>(stSets[index].slot));
    }
    hashST = 0;
    for (int index = 0; text[index] != '\0'; ++index)
        hashST = 31 * hashST + static_cast<unsigned char>(text[index]);
}

void idMD6Mesh::FreeLoadData() {
    if (tris == nullptr) return;
    if (bufferUploadCallback != nullptr) {
        bufferUploadCallback(this);
    } else {
        delete[] static_cast<idDrawVert*>(tris->vertexBuffer.apiObject);
        delete[] static_cast<std::uint16_t*>(tris->indexBuffer.apiObject);
        idDrawVert* vertices = numVerts > 0
            ? new (std::nothrow) idDrawVert[numVerts] : nullptr;
        std::uint16_t* triangleIndices = tris->numIndexes > 0
            ? new (std::nothrow) std::uint16_t[tris->numIndexes] : nullptr;
        if (vertices != nullptr)
            std::memcpy(vertices, tris->verts, numVerts * sizeof(idDrawVert));
        if (triangleIndices != nullptr)
            std::memcpy(triangleIndices, tris->indexes,
                tris->numIndexes * sizeof(std::uint16_t));
        tris->vertexBuffer.apiObject = vertices;
        tris->vertexBuffer.size = numVerts * sizeof(idDrawVert);
        tris->vertexBuffer.usage = BU_STATIC;
        tris->indexBuffer.apiObject = triangleIndices;
        tris->indexBuffer.size = tris->numIndexes * sizeof(std::uint16_t);
        tris->indexBuffer.usage = BU_STATIC;
        for (int index = 0; index < stSets.Num(); ++index) {
            if (stSets[index].vb == nullptr)
                stSets[index].vb = new (std::nothrow) idVertexBuffer{};
            if (stSets[index].vb == nullptr) continue;
            delete[] static_cast<idVec2*>(stSets[index].vb->apiObject);
            idVec2* copy = numVerts > 0
                ? new (std::nothrow) idVec2[numVerts] : nullptr;
            if (copy != nullptr)
                std::memcpy(copy, stSets[index].st.Ptr(),
                    numVerts * sizeof(idVec2));
            stSets[index].vb->apiObject = copy;
            stSets[index].vb->size = numVerts * sizeof(idVec2);
            stSets[index].vb->usage = BU_STATIC;
        }
    }
    vertexes.ClearFree();
    indexes.ClearFree();
    for (int index = 0; index < stSets.Num(); ++index)
        stSets[index].st.ClearFree();
    delete[] tris->verts;
    delete[] tris->indexes;
    tris->verts = nullptr;
    tris->indexes = nullptr;
}

void idMD6Mesh::Free() {
    if (bufferReleaseCallback != nullptr) {
        bufferReleaseCallback(this);
    } else if (tris != nullptr) {
        delete[] static_cast<idDrawVert*>(tris->vertexBuffer.apiObject);
        delete[] static_cast<std::uint16_t*>(tris->indexBuffer.apiObject);
    }
    if (tris != nullptr) {
        delete[] tris->verts;
        delete[] tris->indexes;
        delete tris;
        tris = nullptr;
    }
    for (int index = 0; index < stSets.Num(); ++index) {
        if (bufferReleaseCallback == nullptr && stSets[index].vb != nullptr)
            delete[] static_cast<idVec2*>(stSets[index].vb->apiObject);
        delete stSets[index].vb;
        stSets[index].vb = nullptr;
    }
    stSets.ClearFree();
    vertexes.ClearFree();
    indexes.ClearFree();
    morphMap.ClearFree();
    skinRemaps.ClearFree();
    material = nullptr;
    numVerts = numTris = numTexCoordSets = 0;
    hashST = 0;
}
