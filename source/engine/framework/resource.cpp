#include "framework/resource.h"

#include "framework/resourcelist.h"
#include "idlib/filesystem/file.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/hashing/murmur.h"
#include "idlib/lib_print.h"
#include "idlib/text/str.h"

#include <algorithm>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <limits>

idResource::idResource()
    : trackedMemory(0), name("unnamed"), nextOnHashChain(nullptr),
      resourceListPtr(nullptr), resourceError(nullptr), networkID(-1),
      staleCount(0), resourceFlags(0), pad{} {
}

idResource::~idResource() {
    if ((resourceFlags & 0x40u) != 0) {
        idLibPrint::FatalError("Resource deleted with staticResource set: %s",
            name.c_str());
    }
    if (resourceListPtr != nullptr) {
        resourceListPtr->Remove(this);
    }
    idResourceList::UnRegisterNetworkResource(this);
    ClearResourceError();
}

void idResource::LoadResource() {
    const idResourceList* const list = GetResourceList();
    idLibPrint::FatalError("idResource::Load() for %s not implemented.\n",
        list != nullptr ? list->GetResourceTypeName() : "resource");
}

bool idResource::ReloadIfStale() {
    return false;
}

void idResource::WriteResourceFile() {
    const idResourceList* const list = GetResourceList();
    idLibPrint::FatalError(
        "resource type '%s' has not implemented WriteResourceFile()",
        list != nullptr ? list->GetResourceTypeName() : "resource");
}

idResourceList* idResource::GetResourceList() {
    return resourceListPtr;
}

void idResource::Print() {
    const idResourceList* const list = GetResourceList();
    const char* const typeName =
        list != nullptr ? list->GetResourceTypeName() : "resource";
    if (resourceError != nullptr) {
        idLibPrint::Printf("%s:%s:%s\n", typeName, name.c_str(),
            resourceError);
    } else {
        idLibPrint::Printf("%s:%s\n", typeName, name.c_str());
    }
}

void idResource::List() {
    Print();
}

void idResource::SetName(const char* const newName) {
    idStr canonicalName(newName);
    canonicalName.MakeNameCanonical();
    if (idStr::Cmp(canonicalName.c_str(), name.c_str()) != 0) {
        name.Set(canonicalName.c_str());
    }
}

void idResource::SetResourceError(const char* const format, ...) {
    ClearResourceError();
    if (format == nullptr) {
        return;
    }
    char text[2048];
    va_list arguments;
    va_start(arguments, format);
    const int count = std::vsnprintf(text, sizeof(text), format, arguments);
    va_end(arguments);
    text[sizeof(text) - 1] = '\0';
    idAtomicString interned(text);
    resourceError = interned.c_str();
    idLibPrint::Warning("%s", resourceError);
}

void idResource::ClearResourceError() {
    resourceError = nullptr;
}

void idResource::Load() {
    ClearResourceError();
    LoadResource();
}

const char* idResource::GetResourceTypeName() const {
    idResourceList* const list =
        const_cast<idResource*>(this)->GetResourceList();
    return list != nullptr ? list->GetResourceTypeName() : "resource";
}

const char* idResource::GetLocalizedName(const char* const sourceLanguage,
        const char* const destLanguage, const char* const inName,
        char* const outName, const int sizeOfOutName) {
    if (sourceLanguage == nullptr || destLanguage == nullptr
        || inName == nullptr || outName == nullptr || sizeOfOutName <= 0) {
        return inName;
    }

    const char* match = std::strstr(inName, sourceLanguage);
    if (match == nullptr || match == inName) {
        return inName;
    }
    const std::size_t sourceLength = std::strlen(sourceLanguage);
    const char before = match[-1];
    const char after = match[sourceLength];
    if ((before != '/' && before != '\\')
        || (after != '/' && after != '\\')) {
        return inName;
    }

    const std::size_t prefixLength = static_cast<std::size_t>(match - inName);
    const std::size_t destinationLength = std::strlen(destLanguage);
    const char* const suffix = match + sourceLength;
    const std::size_t suffixLength = std::strlen(suffix);
    if (prefixLength + destinationLength + suffixLength + 1
        > static_cast<std::size_t>(sizeOfOutName)) {
        return inName;
    }
    std::memcpy(outName, inName, prefixLength);
    std::memcpy(outName + prefixLength, destLanguage, destinationLength);
    std::memcpy(outName + prefixLength + destinationLength, suffix,
        suffixLength + 1);
    return outName;
}

const char* idResource::GetLocalizedName(const char* const inName,
        char* const outName, const int sizeOfOutName) {
    // The 360 binary read sys_lang here. Until the PC cvar owner installs its
    // language, English is the authoritative neutral/default path.
    return GetLocalizedName("english", "english", inName, outName,
        sizeOfOutName);
}

bool idResource::WriteBinaryHeader(idFile* const file,
        const resourceHeader_t& inputHeader, const void* const data,
        const int dataLength, const char* const uniqueIdName,
        const char* const sourceFileName) {
    if (file == nullptr || dataLength < 0
        || (dataLength != 0 && data == nullptr)) {
        return false;
    }

    const char* const safeUniqueName = uniqueIdName != nullptr
        ? uniqueIdName : "";
    const char* const safeSourceName = sourceFileName != nullptr
        ? sourceFileName : "";
    const std::size_t sourceLength = std::strlen(safeSourceName);
    const std::size_t uniqueLength = std::strlen(safeUniqueName);
    if (sourceLength > std::numeric_limits<std::uint16_t>::max()
        || uniqueLength > std::numeric_limits<std::uint16_t>::max()) {
        return false;
    }

    resourceHeader_t header = inputHeader;
    header.sourceFileNameLen = static_cast<std::uint16_t>(sourceLength);
    header.uniqueIdNameLen = static_cast<std::uint16_t>(uniqueLength);
    header.platform = resourceHeader_t::RESOURCEPLATFORM_WINDOWS;
    std::memset(header.pad, 0, sizeof(header.pad));
    const std::uint64_t unalignedOffset = sizeof(resourceHeader_t)
        + sourceLength + uniqueLength;
    header.dataOffset = (unalignedOffset + 15u) & ~std::uint64_t(15u);
    header.hash = MurMur64_HashData(data, dataLength, 0);
    header.totalSize = header.dataOffset + static_cast<unsigned int>(dataLength);

    unsigned int written = 0;
    written += file->Write(&header.headerVersionHi, 2);
    written += file->Write(&header.headerVersionLo, 2);
    written += file->Write(&header.resourceId, 4);
    written += file->Write(&header.versionHi, 2);
    written += file->Write(&header.versionLo, 2);
    written += file->Write(&header.sourceTimestamp, 4);
    written += file->Write(&header.sourceFileNameLen, 2);
    written += file->Write(&header.uniqueIdNameLen, 2);
    written += file->Write(&header.platform, 1);
    written += file->Write(header.pad, 3);
    written += file->Write(&header.uniqueId, 8);
    written += file->Write(&header.hash, 8);
    written += file->Write(&header.dataOffset, 8);
    written += file->Write(&header.totalSize, 8);
    if (written != sizeof(resourceHeader_t)) {
        return false;
    }

    written += file->Write(safeSourceName, header.sourceFileNameLen);
    written += file->Write(safeUniqueName, header.uniqueIdNameLen);
    static const unsigned char zeroBytes[16] = {};
    const unsigned int padding = static_cast<unsigned int>(
        header.dataOffset - unalignedOffset);
    written += file->Write(zeroBytes, padding);
    return written == header.dataOffset;
}

bool idResource::WriteBinary(const char* const uniqueIdName,
        const char* const sourceFileName, const char* const fileExtension,
        const resourceHeader_t& header, const void* const data,
        const unsigned int dataLength) {
    if (fileSystem == nullptr || uniqueIdName == nullptr
        || fileExtension == nullptr) {
        return false;
    }
    char relativePath[260] = {};
    if (!fileSystem->FixLongFilename("generated", fileExtension,
            uniqueIdName, relativePath, sizeof(relativePath))) {
        return false;
    }
    idFile_Memory memory(relativePath);
    if (!WriteBinaryHeader(&memory, header, data,
            static_cast<int>(dataLength), uniqueIdName, sourceFileName)
        || memory.Write(data, dataLength) != dataLength) {
        return false;
    }
    return fileSystem->WriteFile(relativePath, memory.GetDataPtr(),
        static_cast<unsigned int>(memory.Length()), FSPATH_BASE)
        == static_cast<unsigned int>(memory.Length());
}

idResource::resourceError_t idResource::ReadBinaryHeader(idFile* const file,
        const std::uint32_t expectedResourceId,
        const std::uint16_t expectedVersionHi,
        const std::uint16_t expectedVersionLo, resourceHeader_t& header,
        char* const sourceFileName, char* const uniqueIdName) {
    if (file == nullptr || sourceFileName == nullptr || uniqueIdName == nullptr) {
        return RESOURCE_ERROR_FATAL;
    }
    std::memset(&header, 0, sizeof(header));
    auto read = [file](void* destination, const unsigned int length) {
        return file->Read(destination, length) == length;
    };
    if (!read(&header.headerVersionHi, 2)) return RESOURCE_ERROR_TRUNCATED;
    if (header.headerVersionHi != 1) {
        return RESOURCE_ERROR_HEADER_VERSION_MISMATCH;
    }
    if (!read(&header.headerVersionLo, 2)) return RESOURCE_ERROR_TRUNCATED;
    if (header.headerVersionLo != 1) {
        return RESOURCE_ERROR_HEADER_VERSION_MISMATCH;
    }
    if (!read(&header.resourceId, 4)) return RESOURCE_ERROR_TRUNCATED;
    if (header.resourceId != expectedResourceId) return RESOURCE_ERROR_WRONG_TYPE;
    if (!read(&header.versionHi, 2)) return RESOURCE_ERROR_TRUNCATED;
    if (header.versionHi != expectedVersionHi) {
        return RESOURCE_ERROR_RESOURCE_VERSION_MISMATCH;
    }
    if (!read(&header.versionLo, 2)) return RESOURCE_ERROR_TRUNCATED;
    if (header.versionLo != expectedVersionLo) {
        return RESOURCE_ERROR_RESOURCE_VERSION_MISMATCH;
    }
    if (!read(&header.sourceTimestamp, 4)
        || !read(&header.sourceFileNameLen, 2)
        || !read(&header.uniqueIdNameLen, 2)) {
        return RESOURCE_ERROR_TRUNCATED;
    }
    if (header.sourceFileNameLen >= 256 || header.uniqueIdNameLen >= 256) {
        return RESOURCE_ERROR_INVALID_NAME;
    }
    if (!read(&header.platform, 1) || !read(header.pad, 3)
        || !read(&header.uniqueId, 8) || !read(&header.hash, 8)
        || !read(&header.dataOffset, 8) || !read(&header.totalSize, 8)) {
        return RESOURCE_ERROR_TRUNCATED;
    }
    const std::uint64_t namesEnd = sizeof(resourceHeader_t)
        + header.sourceFileNameLen + header.uniqueIdNameLen;
    if (header.dataOffset < namesEnd || header.totalSize < header.dataOffset
        || header.dataOffset - namesEnd > 15) {
        return RESOURCE_ERROR_TRUNCATED;
    }
    if (!read(sourceFileName, header.sourceFileNameLen)) {
        return RESOURCE_ERROR_TRUNCATED;
    }
    sourceFileName[header.sourceFileNameLen] = '\0';
    if (!read(uniqueIdName, header.uniqueIdNameLen)) {
        return RESOURCE_ERROR_TRUNCATED;
    }
    uniqueIdName[header.uniqueIdNameLen] = '\0';
    unsigned char padding[16];
    const unsigned int paddingLength = static_cast<unsigned int>(
        header.dataOffset - namesEnd);
    if (paddingLength != 0 && !read(padding, paddingLength)) {
        return RESOURCE_ERROR_TRUNCATED;
    }
    return RESOURCE_ERROR_NONE;
}
