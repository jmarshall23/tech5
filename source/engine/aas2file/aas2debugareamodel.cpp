#include "aas2file/aas2debugareamodel.h"

#include "aas2file/aas2debugareamodelgenerator.h"
#include "framework/resourcelist.h"
#include "idlib/filesystem/filesystem.h"

idResourceList idAAS2DebugAreaModel::resourceList("aasDebugAreaModel");

idAAS2DebugAreaModel::idAAS2DebugAreaModel()
    : data(), sourceTimestamp(std::uint32_t(-1)) {
}

idAAS2DebugAreaModel::~idAAS2DebugAreaModel() = default;

idResourceList* idAAS2DebugAreaModel::GetResourceList() {
    return &resourceList;
}

void idAAS2DebugAreaModel::LoadResource() {
    data.Free();
    sourceTimestamp = std::uint32_t(-1);
    char binaryPath[256] = {};
    fileSystem->FixLongFilename("generated",
        idAAS2DebugAreaModelData::BINARY_FILE_EXTENSION, GetName(),
        binaryPath, sizeof(binaryPath));
    idStr error;
    const idResource::resourceError_t loadError =
        data.LoadBinary(binaryPath, error);
    if (loadError != idResource::RESOURCE_ERROR_NONE) {
        resourceError = "Could not load generated AAS debug area model";
    }
}

bool idAAS2DebugAreaModel::ReloadIfStale() {
    if (fileSystem->GetTimestamp(GetName(), false) == sourceTimestamp) {
        return false;
    }
    char binaryPath[256] = {};
    fileSystem->FixLongFilename("generated",
        idAAS2DebugAreaModelData::BINARY_FILE_EXTENSION, GetName(),
        binaryPath, sizeof(binaryPath));
    fileSystem->RemoveFile(binaryPath, FSPATH_BASE);
    LoadResource();
    return true;
}

void idAAS2DebugAreaModel::WriteResourceFile() {
    idAAS2DebugAreaModelGenerator::WriteToBinary(GetName(), GetName(),
        sourceTimestamp, data);
}
