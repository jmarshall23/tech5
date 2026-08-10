#include "framework/fileresource.h"

#include "idlib/filesystem/filesystem.h"

#include <cstdlib>
#include <cstring>

idTypedResourceList<idFileResource> idFileResource::resourceList("file");

idFileResource::idFileResource()
    : timestamp(static_cast<unsigned int>(-1)), length(0), data(nullptr) {
}

idFileResource::~idFileResource() {
    FreeData();
}

void idFileResource::FreeData() {
    std::free(data);
    data = nullptr;
    length = 0;
    timestamp = static_cast<unsigned int>(-1);
}

void idFileResource::LoadResource() {
    FreeData();
    if (fileSystem == nullptr) {
        SetResourceError("filesystem is not initialized");
        return;
    }
    void* fileData = nullptr;
    unsigned int fileTimestamp = 0;
    const int fileLength = fileSystem->ReadFile(GetName(), &fileData,
        &fileTimestamp);
    if (fileLength < 0 || fileData == nullptr) {
        SetResourceError("file not found: %s", GetName());
        return;
    }
    if (fileLength > 0) {
        data = std::malloc(static_cast<std::size_t>(fileLength));
        if (data == nullptr) {
            fileSystem->FreeFile(fileData);
            SetResourceError("out of memory reading %s", GetName());
            return;
        }
        std::memcpy(data, fileData, static_cast<std::size_t>(fileLength));
    }
    fileSystem->FreeFile(fileData);
    length = static_cast<unsigned int>(fileLength);
    timestamp = fileTimestamp;
}

idResourceList* idFileResource::GetResourceList() {
    return &resourceList;
}

idFile_Memory* idFileResource::GetFileReadOnly() {
    if (data == nullptr && length == 0) {
        LoadResource();
    }
    idFile_Memory* result = new idFile_Memory(GetName());
    result->SetReadOnlyData(static_cast<const char*>(data), length);
    return result;
}

bool idFileResource::FileExists(const char* const fileName) {
    return fileSystem != nullptr && fileName != nullptr
        && fileSystem->FileExists(fileName);
}
