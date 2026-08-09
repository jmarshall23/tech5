#include "aas2file/aas2debugareamodelgenerator.h"

#include "aas2file/aas2debugareamodeldata.h"
#include "idlib/filesystem/file.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/hashing/murmur.h"

#include <algorithm>
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

bool WriteExact(idFile& file, const void* data, const unsigned int bytes) {
    return bytes == 0 || file.Write(data, bytes) == bytes;
}

} // namespace

bool idAAS2DebugAreaModelGenerator::WriteToBinary(
        const char* const uniqueIdName, const char* const fileName,
        const std::uint32_t sourceTimestamp,
        const idAAS2DebugAreaModelData& data) {
    char binaryPath[256] = {};
    fileSystem->FixLongFilename("generated",
        idAAS2DebugAreaModelData::BINARY_FILE_EXTENSION, fileName,
        binaryPath, sizeof(binaryPath));
    const char* const sourceName = fileName != nullptr ? fileName : "";
    const char* const uniqueName = uniqueIdName != nullptr ? uniqueIdName : "";
    const std::uint16_t sourceLength = static_cast<std::uint16_t>(
        (std::min)(std::size_t(255), std::strlen(sourceName)));
    const std::uint16_t uniqueLength = static_cast<std::uint16_t>(
        (std::min)(std::size_t(255), std::strlen(uniqueName)));

    std::uint64_t payloadSize = 8u + data.vertices.Num() * 12ull;
    for (int area = 0; area < data.areas.Num(); ++area) {
        payloadSize += 4 + data.areas[area].tris.Num() * 12ull;
    }
    if (payloadSize > static_cast<std::uint64_t>(UINT_MAX)) return false;

    idFile_Memory payload;
    const int vertexCount = data.vertices.Num();
    const int areaCount = data.areas.Num();
    if (!WriteExact(payload, &vertexCount, 4)
        || !WriteExact(payload, data.vertices.Ptr(), vertexCount * 12u)
        || !WriteExact(payload, &areaCount, 4)) return false;
    for (int area = 0; area < areaCount; ++area) {
        const int triangleCount = data.areas[area].tris.Num();
        if (!WriteExact(payload, &triangleCount, 4)
            || !WriteExact(payload, data.areas[area].tris.Ptr(),
                triangleCount * 12u)) return false;
    }

    idFileLocal file(fileSystem->OpenFileWrite(binaryPath, FSPATH_BASE));
    if (file.file == nullptr) return false;
    DebugResourceHeader header{};
    header.headerVersionHi = 1;
    header.headerVersionLo = 1;
    header.resourceId = DEBUG_AAS_RESOURCE_ID;
    header.versionHi = idAAS2DebugAreaModelData::BINARY_VERSION_HI;
    header.versionLo = idAAS2DebugAreaModelData::BINARY_VERSION_LO;
    header.sourceTimestamp = sourceTimestamp;
    header.sourceFileNameLen = sourceLength;
    header.uniqueIdNameLen = uniqueLength;
    // The recovered writer stores RESOURCEPLATFORM_360.  This is the PC
    // port's equivalent resource and therefore advertises Windows (0).
    header.platform = 0;
    header.uniqueId = 0;
    header.hash = MurMur64_HashData(payload.GetDataPtr(),
        static_cast<int>(payload.Length()), 0);
    header.dataOffset = (sizeof(header) + sourceLength + uniqueLength + 15u)
        & ~std::uint64_t(15u);
    header.totalSize = header.dataOffset + payloadSize;

    if (!WriteExact(*file.file, &header, sizeof(header))
        || !WriteExact(*file.file, sourceName, sourceLength)
        || !WriteExact(*file.file, uniqueName, uniqueLength)) return false;
    const std::uint8_t zeroBytes[16] = {};
    const std::uint64_t writtenHeaderBytes =
        sizeof(header) + sourceLength + uniqueLength;
    const unsigned int padding = static_cast<unsigned int>(
        header.dataOffset - writtenHeaderBytes);
    if (!WriteExact(*file.file, zeroBytes, padding)
        || !WriteExact(*file.file, payload.GetDataPtr(),
            static_cast<unsigned int>(payload.Length()))) {
        return false;
    }
    return true;
}
