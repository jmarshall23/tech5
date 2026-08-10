#include "models/particles/jobs/staticparticlemodeldata.h"

#include "idlib/filesystem/file.h"
#include "idlib/filesystem/filesystem.h"

#include <algorithm>
#include <cstring>
#include <limits>
#include <new>

namespace {

constexpr std::uint32_t STATICPARTICLE_MODEL_MAGIC = 21777744u;
constexpr int MAX_STATIC_PARTICLE_VERTS = 128;

bool BuildGeneratedName(const char* modelName, char (&path)[256]) {
    return fileSystem != nullptr && fileSystem->FixLongFilename("generated",
        "pmodel", modelName, path, static_cast<int>(sizeof(path)));
}

bool FindOppositeSharedEdge(const std::uint16_t first[3],
    const std::uint16_t second[3], std::uint16_t quad[4]) {
    for (int firstEdge = 0; firstEdge < 3; ++firstEdge) {
        const std::uint16_t u = first[firstEdge];
        const std::uint16_t v = first[(firstEdge + 1) % 3];
        const std::uint16_t uniqueFirst = first[(firstEdge + 2) % 3];
        for (int secondEdge = 0; secondEdge < 3; ++secondEdge) {
            if (second[secondEdge] != v
                    || second[(secondEdge + 1) % 3] != u) {
                continue;
            }
            const std::uint16_t uniqueSecond =
                second[(secondEdge + 2) % 3];
            // Preserve the renderer's CreateQuads ordering.  The slightly
            // asymmetric cases are intentional: static particle geometry
            // consumes the four vertices directly rather than rebuilding
            // triangle indexes from them.
            if (firstEdge == 0) {
                quad[0] = u;
                quad[1] = uniqueSecond;
                quad[2] = uniqueFirst;
                quad[3] = v;
            } else if (firstEdge == 1) {
                quad[0] = v;
                quad[1] = uniqueFirst;
                quad[2] = uniqueSecond;
                quad[3] = u;
            } else {
                quad[0] = v;
                quad[1] = uniqueFirst;
                quad[2] = uniqueSecond;
                quad[3] = u;
            }
            return true;
        }
    }
    return false;
}

} // namespace

idTypedResourceList<idStaticParticleModelData>
    idStaticParticleModelData::resourceList("staticParticleModel");
idStaticParticleModelData::GeometryLoader
    idStaticParticleModelData::geometryLoader = nullptr;

idStaticParticleModelData::idStaticParticleModelData()
    : timestamp((std::numeric_limits<unsigned int>::max)()),
      staticVerts(nullptr), numStaticVerts(0) {
}

idStaticParticleModelData::~idStaticParticleModelData() {
    FreeData();
}

void idStaticParticleModelData::SetGeometryLoader(GeometryLoader loader) {
    geometryLoader = loader;
}

idResourceList* idStaticParticleModelData::GetResourceList() {
    return &resourceList;
}

void idStaticParticleModelData::FreeData() {
    delete[] staticVerts;
    staticVerts = nullptr;
    numStaticVerts = 0;
    timestamp = (std::numeric_limits<unsigned int>::max)();
}

bool idStaticParticleModelData::ReloadIfStale() {
    if (fileSystem == nullptr) return false;
    if (fileSystem->GetTimestamp(GetName(), false) == timestamp) return false;
    char generatedPath[256] = {};
    if (BuildGeneratedName(GetName(), generatedPath)) {
        fileSystem->RemoveFile(generatedPath, FSPATH_BASE);
    }
    LoadResource();
    return true;
}

bool idStaticParticleModelData::WriteBinary(const char* fileName) const {
    if (fileSystem == nullptr || fileName == nullptr
            || numStaticVerts < 0 || numStaticVerts > MAX_STATIC_PARTICLE_VERTS
            || (numStaticVerts != 0 && staticVerts == nullptr)) {
        return false;
    }
    idFileLocal file(fileSystem->OpenFileWrite(fileName, FSPATH_BASE));
    if (file.file == nullptr) return false;
    const std::uint32_t count = static_cast<std::uint32_t>(numStaticVerts);
    return file->Write(&STATICPARTICLE_MODEL_MAGIC,
               sizeof(STATICPARTICLE_MODEL_MAGIC))
            == sizeof(STATICPARTICLE_MODEL_MAGIC)
        && file->Write(&timestamp, sizeof(timestamp)) == sizeof(timestamp)
        && file->Write(&count, sizeof(count)) == sizeof(count)
        && file->Write(staticVerts,
               count * static_cast<unsigned int>(sizeof(idDrawVert)))
            == count * static_cast<unsigned int>(sizeof(idDrawVert));
}

bool idStaticParticleModelData::LoadBinary(const char* fileName) {
    if (fileSystem == nullptr || fileName == nullptr) return false;
    idFileLocal file(fileSystem->OpenFileRead(fileName, true, false));
    if (file.file == nullptr || file->Length() < 12) return false;

    std::uint32_t magic = 0;
    unsigned int sourceTimestamp = 0;
    std::uint32_t count = 0;
    if (file->Read(&magic, sizeof(magic)) != sizeof(magic)
            || magic != STATICPARTICLE_MODEL_MAGIC
            || file->Read(&sourceTimestamp, sizeof(sourceTimestamp))
                != sizeof(sourceTimestamp)
            || file->Read(&count, sizeof(count)) != sizeof(count)
            || count > MAX_STATIC_PARTICLE_VERTS) {
        return false;
    }
    const std::uint64_t byteCount = static_cast<std::uint64_t>(count)
        * sizeof(idDrawVert);
    if (byteCount > static_cast<std::uint64_t>(
            (std::numeric_limits<unsigned int>::max)())
            || file->Length() - file->Tell()
                < static_cast<std::int64_t>(byteCount)) {
        return false;
    }

    idDrawVert* loaded = count != 0
        ? new (std::nothrow) idDrawVert[count] : nullptr;
    if (count != 0 && loaded == nullptr) return false;
    if (count != 0 && file->Read(loaded,
            static_cast<unsigned int>(byteCount)) != byteCount) {
        delete[] loaded;
        return false;
    }

    delete[] staticVerts;
    staticVerts = loaded;
    numStaticVerts = static_cast<int>(count);
    timestamp = sourceTimestamp;
    ClearResourceError();
    return true;
}

bool idStaticParticleModelData::GenerateFromGeometry(
    const idDrawVert* vertices, const int numVertices,
    const std::uint16_t* indexes, const int numIndexes,
    const unsigned int sourceTimestamp) {
    if (vertices == nullptr || indexes == nullptr || numVertices <= 0
            || numVertices > MAX_STATIC_PARTICLE_VERTS || numIndexes < 3
            || numIndexes % 3 != 0) {
        return false;
    }

    idList<std::uint16_t, 79> quads;
    for (int offset = 0; offset < numIndexes;) {
        std::uint16_t quad[4] = {
            indexes[offset], indexes[offset + 1], indexes[offset + 2],
            indexes[offset + 2]
        };
        if (offset + 5 < numIndexes) {
            const std::uint16_t first[3] = {
                indexes[offset], indexes[offset + 1], indexes[offset + 2]
            };
            const std::uint16_t second[3] = {
                indexes[offset + 3], indexes[offset + 4], indexes[offset + 5]
            };
            if (FindOppositeSharedEdge(first, second, quad)) offset += 6;
            else offset += 3;
        } else {
            offset += 3;
        }
        for (const std::uint16_t index : quad) {
            if (index >= numVertices || quads.Append(index) < 0) return false;
        }
        if (quads.Num() > MAX_STATIC_PARTICLE_VERTS) return false;
    }

    idDrawVert* generated = new (std::nothrow) idDrawVert[quads.Num()];
    if (generated == nullptr && quads.Num() != 0) return false;
    for (int index = 0; index < quads.Num(); ++index) {
        generated[index] = vertices[quads[index]];
    }

    delete[] staticVerts;
    staticVerts = generated;
    numStaticVerts = quads.Num();
    timestamp = sourceTimestamp;
    ClearResourceError();
    return true;
}

bool idStaticParticleModelData::Generate() {
    if (geometryLoader == nullptr) return false;
    idList<idDrawVert, 79> vertices;
    idList<std::uint16_t, 79> indexes;
    unsigned int sourceTimestamp = 0;
    return geometryLoader(GetName(), vertices, indexes, sourceTimestamp)
        && GenerateFromGeometry(vertices.Ptr(), vertices.Num(), indexes.Ptr(),
            indexes.Num(), sourceTimestamp);
}

void idStaticParticleModelData::LoadResource() {
    FreeData();
    char generatedPath[256] = {};
    if (BuildGeneratedName(GetName(), generatedPath)
            && LoadBinary(generatedPath)) {
        return;
    }
    if (Generate()) {
        if (generatedPath[0] != '\0') WriteBinary(generatedPath);
        return;
    }
    SetResourceError("Couldn't load staticparticlemodeldata '%s'", GetName());
    FreeData();
}
