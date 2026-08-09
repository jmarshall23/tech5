#include "aas2file/aas2debugareamodeldata.h"

#include "framework/resource.h"
#include "idlib/filesystem/file.h"
#include "idlib/filesystem/filesystem.h"

#include <cstring>

namespace {

constexpr std::uint32_t DEBUG_AAS_RESOURCE_ID = 0x41415344u;

#pragma pack(push, 4)
struct DebugResourceHeader {
    std::uint16_t headerVersionHi;
    std::uint16_t headerVersionLo;
    std::uint32_t resourceId;
    std::uint16_t versionHi;
    std::uint16_t versionLo;
    std::uint32_t sourceTimestamp;
    std::uint16_t sourceFileNameLen;
    std::uint16_t uniqueIdNameLen;
    std::uint8_t platform;
    std::uint8_t pad[3];
    std::uint64_t uniqueId;
    std::uint64_t hash;
    std::uint64_t dataOffset;
    std::uint64_t totalSize;
};
#pragma pack(pop)

static_assert(sizeof(DebugResourceHeader) == 56,
    "Recovered debug resource header layout changed");

idAAS2DebugAreaModelData::drawTriangleCallback_t drawTriangleCallback = nullptr;

bool ReadExact(idFile& file, void* data, const unsigned int bytes) {
    return bytes == 0 || file.Read(data, bytes) == bytes;
}

std::uint16_t ByteSwap16(const std::uint16_t value) {
    return static_cast<std::uint16_t>((value << 8) | (value >> 8));
}

std::uint32_t ByteSwap32(const std::uint32_t value) {
    return (value << 24) | ((value << 8) & 0x00FF0000u)
        | ((value >> 8) & 0x0000FF00u) | (value >> 24);
}

std::uint64_t ByteSwap64(const std::uint64_t value) {
    return (static_cast<std::uint64_t>(ByteSwap32(
                static_cast<std::uint32_t>(value))) << 32)
        | ByteSwap32(static_cast<std::uint32_t>(value >> 32));
}

void SwapHeader(DebugResourceHeader& header) {
    header.headerVersionHi = ByteSwap16(header.headerVersionHi);
    header.headerVersionLo = ByteSwap16(header.headerVersionLo);
    header.resourceId = ByteSwap32(header.resourceId);
    header.versionHi = ByteSwap16(header.versionHi);
    header.versionLo = ByteSwap16(header.versionLo);
    header.sourceTimestamp = ByteSwap32(header.sourceTimestamp);
    header.sourceFileNameLen = ByteSwap16(header.sourceFileNameLen);
    header.uniqueIdNameLen = ByteSwap16(header.uniqueIdNameLen);
    header.uniqueId = ByteSwap64(header.uniqueId);
    header.hash = ByteSwap64(header.hash);
    header.dataOffset = ByteSwap64(header.dataOffset);
    header.totalSize = ByteSwap64(header.totalSize);
}

void SwapWord(void* const pointer) {
    std::uint32_t value = 0;
    std::memcpy(&value, pointer, sizeof(value));
    value = ByteSwap32(value);
    std::memcpy(pointer, &value, sizeof(value));
}

} // namespace

idAAS2DebugAreaModelData::idAAS2DebugAreaModelData()
    : vertices(0), areas(0) {
}

idAAS2DebugAreaModelData::~idAAS2DebugAreaModelData() = default;

void idAAS2DebugAreaModelData::SetDrawTriangleCallback(
        const drawTriangleCallback_t callback) {
    drawTriangleCallback = callback;
}

void idAAS2DebugAreaModelData::Draw(idRenderWorld* const renderWorld,
        const idList<int, 5>& visibleAreas) const {
    if (renderWorld == nullptr || drawTriangleCallback == nullptr) return;
    const float color[4] = { 0.0f, 1.0f, 0.0f, 0.5f };
    for (int visibleIndex = 0; visibleIndex < visibleAreas.Num(); ++visibleIndex) {
        const int areaNum = visibleAreas[visibleIndex];
        if (areaNum < 0 || areaNum >= areas.Num()) continue;
        const debugAreaInfo_t& area = areas[areaNum];
        for (int triangleIndex = 0; triangleIndex < area.tris.Num(); ++triangleIndex) {
            const areaTri_t& triangle = area.tris[triangleIndex];
            if (triangle.v0 < 0 || triangle.v0 >= vertices.Num()
                || triangle.v1 < 0 || triangle.v1 >= vertices.Num()
                || triangle.v2 < 0 || triangle.v2 >= vertices.Num()) continue;
            drawTriangleCallback(renderWorld, vertices[triangle.v0],
                vertices[triangle.v1], vertices[triangle.v2], color);
        }
    }
}

void idAAS2DebugAreaModelData::BuildResourceNameFromAASName(
        const char* const aasName, idStr& resourceName) {
    resourceName = aasName;
    resourceName.Append(TEXT_FILE_EXTENSION);
}

void idAAS2DebugAreaModelData::Free() {
    vertices.Clear();
    areas.ClearFree();
}

idResource::resourceError_t idAAS2DebugAreaModelData::LoadBinary(
        const char* const binaryFileName,
        idStr& errorMessage) {
    Free();
    idFileLocal file(fileSystem->OpenFileRead(binaryFileName, true, false));
    if (file.file == nullptr) {
        errorMessage = "file not found";
        return idResource::RESOURCE_ERROR_FILE_NOT_FOUND;
    }
    DebugResourceHeader header{};
    if (!ReadExact(*file.file, &header, sizeof(header))) {
        errorMessage = "truncated resource header";
        return idResource::RESOURCE_ERROR_TRUNCATED;
    }
    const bool byteSwap = header.headerVersionHi != 1
        && ByteSwap16(header.headerVersionHi) == 1;
    if (byteSwap) SwapHeader(header);
    if (header.headerVersionHi != 1 || header.headerVersionLo != 1) {
        errorMessage = "resource header version mismatch";
        return idResource::RESOURCE_ERROR_HEADER_VERSION_MISMATCH;
    }
    if (header.resourceId != DEBUG_AAS_RESOURCE_ID) {
        errorMessage = "resource type mismatch";
        return idResource::RESOURCE_ERROR_WRONG_TYPE;
    }
    if (header.versionHi != BINARY_VERSION_HI
            || header.versionLo != BINARY_VERSION_LO) {
        errorMessage = "debug AAS resource version mismatch";
        return idResource::RESOURCE_ERROR_RESOURCE_VERSION_MISMATCH;
    }
    if (header.sourceFileNameLen >= 256 || header.uniqueIdNameLen >= 256) {
        errorMessage = "invalid resource name";
        return idResource::RESOURCE_ERROR_INVALID_NAME;
    }
    if (header.dataOffset < sizeof(header)
        || header.totalSize < header.dataOffset
        || header.totalSize > static_cast<std::uint64_t>(file.file->Length())) {
        errorMessage = "invalid debug AAS resource offsets";
        return idResource::RESOURCE_ERROR_TRUNCATED;
    }
    if (file.file->Seek(static_cast<std::int64_t>(header.dataOffset),
            FS_SEEK_SET) != 0) {
        errorMessage = "could not seek debug AAS resource data";
        return idResource::RESOURCE_ERROR_TRUNCATED;
    }
    int vertexCount = 0;
    if (!ReadExact(*file.file, &vertexCount, 4)) {
        errorMessage = "Bad number of vertices";
        return idResource::RESOURCE_ERROR_FATAL;
    }
    if (byteSwap) SwapWord(&vertexCount);
    if (vertexCount <= 0
        || !vertices.SetNum(vertexCount)
        || !ReadExact(*file.file, vertices.Ptr(), vertexCount * 12u)) {
        errorMessage = "Bad number of vertices";
        Free();
        return idResource::RESOURCE_ERROR_FATAL;
    }
    if (byteSwap) {
        for (int vertex = 0; vertex < vertexCount; ++vertex) {
            SwapWord(&vertices[vertex].x); SwapWord(&vertices[vertex].y);
            SwapWord(&vertices[vertex].z);
        }
    }
    int areaCount = 0;
    if (!ReadExact(*file.file, &areaCount, 4)) {
        errorMessage = "Bad number of areas";
        Free();
        return idResource::RESOURCE_ERROR_FATAL;
    }
    if (byteSwap) SwapWord(&areaCount);
    if (areaCount <= 0
        || !areas.SetNum(areaCount)) {
        errorMessage = "Bad number of areas";
        Free();
        return idResource::RESOURCE_ERROR_FATAL;
    }
    for (int areaNum = 0; areaNum < areaCount; ++areaNum) {
        int triangleCount = 0;
        if (!ReadExact(*file.file, &triangleCount, 4)) {
            errorMessage = "Bad number of area tris";
            Free();
            return idResource::RESOURCE_ERROR_FATAL;
        }
        if (byteSwap) SwapWord(&triangleCount);
        if (triangleCount < 0
            || !areas[areaNum].tris.SetNum(triangleCount)
            || !ReadExact(*file.file, areas[areaNum].tris.Ptr(),
                triangleCount * 12u)) {
            errorMessage = "Bad number of area tris";
            Free();
            return idResource::RESOURCE_ERROR_FATAL;
        }
        if (byteSwap) {
            for (int triangle = 0; triangle < triangleCount; ++triangle) {
                SwapWord(&areas[areaNum].tris[triangle].v0);
                SwapWord(&areas[areaNum].tris[triangle].v1);
                SwapWord(&areas[areaNum].tris[triangle].v2);
            }
        }
    }
    errorMessage.Clear();
    return idResource::RESOURCE_ERROR_NONE;
}
