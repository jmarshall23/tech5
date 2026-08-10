#include "framework/resourcemanager_local.h"

#include "framework/common_local.h"
#include "framework/fileresource.h"
#include "framework/framework_hooks.h"
#include "framework/gamesystem.h"
#include "idlib/filesystem/filesystem.h"

#include <cstring>
#include <mutex>

namespace {
idResourceManagerLocal resourceManagerLocal;
thread_local bool insideResourceCallback = false;
std::recursive_mutex resourceCallbackMutex;
idStr currentEntityName;

idFile_Memory* ReadWholeFile(const char* name) {
    if (fileSystem == nullptr || name == nullptr) return nullptr;
    void* bytes = nullptr;
    unsigned int timestamp = 0;
    const int length = fileSystem->ReadFile(name, &bytes, &timestamp);
    if (length < 0 || bytes == nullptr) return nullptr;
    idFile_Memory* result = new idFile_Memory(name);
    if (length > 0) result->Write(bytes, static_cast<unsigned int>(length));
    result->Seek(0, FS_SEEK_SET);
    fileSystem->FreeFile(bytes);
    return result;
}

idResourceCacheEntry* FindEntry(idList<idResourceCacheEntry, 99>& entries,
        const char* name) {
    for (int index = 0; index < entries.Num(); ++index)
        if (idStr::Icmp(entries[index].filename.c_str(), name) == 0) return &entries[index];
    return nullptr;
}

idFile* CacheFilePreCallback(const char* name) {
    if (insideResourceCallback || resourceManager == nullptr) return nullptr;
    std::lock_guard<std::recursive_mutex> lock(resourceCallbackMutex);
    insideResourceCallback = true;
    idFile* result = resourceManager->LoadCacheFile(name);
    insideResourceCallback = false;
    return result;
}

idFile* StatCacheFilePreCallback(const char* name) {
    if (insideResourceCallback || resourceManager == nullptr) return nullptr;
    std::lock_guard<std::recursive_mutex> lock(resourceCallbackMutex);
    insideResourceCallback = true;
    idFile* result = resourceManager->StatCacheFile(name);
    insideResourceCallback = false;
    return result;
}

idFile* PatchFilePreCallback(const char* name) {
    if (insideResourceCallback || resourceManager == nullptr) return nullptr;
    std::lock_guard<std::recursive_mutex> lock(resourceCallbackMutex);
    insideResourceCallback = true;
    idFile* result = resourceManager->LoadPatchFile(name);
    insideResourceCallback = false;
    return result;
}

idFile* MiscellaneousFilePreCallback(const char* name) {
    if (name == nullptr) return nullptr;
    idStr canonical(name);
    canonical.MakeNameCanonical();
    idResource* existing = idFileResource::resourceList.FindExisting(
        canonical.c_str(), false);
    if (existing != nullptr) {
        return static_cast<idFileResource*>(existing)->GetFileReadOnly();
    }
    return CacheFilePreCallback(name);
}
}

idResourceManager* resourceManager = &resourceManagerLocal;

idResourceManager::~idResourceManager() = default;

idResourceManagerLocal::idResourceManagerLocal()
    : resourceFile(nullptr), streamFile(nullptr), localizedStreamFile(nullptr),
      cachedStreamFile(nullptr), tableOffset(0), tableLength(0), resourceMagic(0),
      currentSortedResource(nullptr), currentResource(nullptr), fileTableResource(-1),
      filePlatformBits(1), buildPlatforms(1), lastUPacifierMsec(0),
      denyFonts(false), cancelToTerminate(false) {
}

idResourceManagerLocal::~idResourceManagerLocal() { Shutdown(); }
void idResourceManagerLocal::Init() { cancelToTerminate = false; }
void idResourceManagerLocal::Init2(bool) { Init(); }

void idResourceManagerLocal::Shutdown() {
    CloseOpenFileHandles();
    cacheTable.Clear(); patchTable.Clear(); fileTable.Clear();
    writtenResourceTable.Clear(); languages.Clear();
}

void idResourceManagerLocal::CancelToTerminate() { cancelToTerminate = true; }

void idResourceManagerLocal::CloseOpenFileHandles() {
    delete resourceFile; resourceFile = nullptr;
    delete streamFile; streamFile = nullptr;
    delete localizedStreamFile; localizedStreamFile = nullptr;
    delete cachedStreamFile; cachedStreamFile = nullptr;
    for (int index = 0; index < patchFiles.Num(); ++index) delete patchFiles[index];
    patchFiles.Clear();
}

bool idResourceManagerLocal::ReOpenFileHandles() { return fileSystem != nullptr; }
void idResourceManagerLocal::StartupComplete() {
    if (fileSystem != nullptr) fileSystem->SetFilePreCallback(nullptr);
}
void idResourceManagerLocal::SetFileHook() {
    if (fileSystem != nullptr) {
        fileSystem->SetFileCacheCallback(StatCacheFilePreCallback,
            CacheFilePreCallback);
        fileSystem->SetFilePatchCallback(PatchFilePreCallback);
    }
}
void idResourceManagerLocal::ReleaseFileHook() {
    if (fileSystem != nullptr) {
        fileSystem->SetFileCacheCallback(nullptr, nullptr);
        fileSystem->SetFilePatchCallback(nullptr);
    }
}
bool idResourceManagerLocal::AllocGameWithResourceFile(idGame** const game,
        const idGameSpawnInfo* const spawnInfo, idFile* const saveFile,
        const char*) {
    if (game == nullptr || gameSystem == nullptr || cancelToTerminate) {
        return false;
    }
    commonLocal.BeginTerminationThread();
    if (fileSystem != nullptr) {
        fileSystem->SetFilePreCallback(MiscellaneousFilePreCallback);
    }
    const bool loaded = gameSystem->AllocGame(game, spawnInfo, saveFile);
    if (fileSystem != nullptr) fileSystem->SetFilePreCallback(nullptr);
    commonLocal.EndTerminationThread();
    return loaded && !cancelToTerminate;
}
idFile_Memory* idResourceManagerLocal::LoadCacheFile(const char* name) { return ReadWholeFile(name); }
idFile_Memory* idResourceManagerLocal::LoadPatchFile(const char* name) { return ReadWholeFile(name); }

idFile_Stat* idResourceManagerLocal::StatCacheFile(const char* name) {
    return fileSystem != nullptr && fileSystem->FileExists(name)
        ? new idFile_Stat(name, fileSystem->GetFileLength(name), fileSystem->GetTimestamp(name)) : nullptr;
}

idFile_Stat* idResourceManagerLocal::StatPatchFile(const char* name) { return StatCacheFile(name); }

bool idResourceManagerLocal::GetCacheFileInfo(const char* name, std::int64_t* offset,
        unsigned int* compressed, unsigned int* uncompressed,
        unsigned int* streamOffset, bool) {
    idResourceCacheEntry* entry = FindEntry(cacheTable, name);
    if (entry == nullptr) return false;
    if (offset) *offset = entry->offset;
    if (compressed) *compressed = entry->compressedLength;
    if (uncompressed) *uncompressed = entry->uncompressedLength;
    if (streamOffset) *streamOffset = entry->streamOffset;
    return true;
}

bool idResourceManagerLocal::GetPatchFileInfo(const char* name, std::int64_t* offset,
        unsigned int* compressed, unsigned int* uncompressed,
        unsigned int* streamOffset, int* patch) {
    idResourceCacheEntry* entry = FindEntry(patchTable, name);
    if (entry == nullptr) return false;
    if (offset) *offset = entry->offset;
    if (compressed) *compressed = entry->compressedLength;
    if (uncompressed) *uncompressed = entry->uncompressedLength;
    if (streamOffset) *streamOffset = entry->streamOffset;
    if (patch) *patch = 0;
    return true;
}

idFile* idResourceManagerLocal::GetCacheFile() { return resourceFile; }
idFile* idResourceManagerLocal::GetPatchFile(int index) { return index >= 0 && index < patchFiles.Num() ? patchFiles[index] : nullptr; }
idFile* idResourceManagerLocal::GetStreamFile() { return streamFile; }
idFile* idResourceManagerLocal::GetCachedStreamFile() { return cachedStreamFile; }
idFile* idResourceManagerLocal::GetLocalizedStreamFile() { return localizedStreamFile; }
bool idResourceManagerLocal::IsResourceFile(idFile* file) {
    if (file == nullptr) return false;
    if (file == resourceFile) return true;
    for (int index = 0; index < patchFiles.Num(); ++index) {
        if (patchFiles[index] == file) return true;
    }
    return false;
}
void idResourceManagerLocal::SetResourceFilePlatform(unsigned int bits) { filePlatformBits = bits; }
unsigned int idResourceManagerLocal::GetBuildPlatforms() { return buildPlatforms; }
void idResourceManagerLocal::BeginEntity(const char* const name,
        const idList<idStr, 5>* const entityLanguages) {
    currentEntityName = name != nullptr ? name : "";
    if (entityLanguages != nullptr) languages = *entityLanguages;
}
void idResourceManagerLocal::EndEntity() {
    currentResource = nullptr;
    currentSortedResource = nullptr;
    currentEntityName.Clear();
}
const idList<idStr, 5>* idResourceManagerLocal::GetLanguages() { return &languages; }
bool idResourceManagerLocal::ExcludeImage(const char* const name) {
    return frameworkHooks.excludeImage != nullptr
        && frameworkHooks.excludeImage(name);
}
bool idResourceManagerLocal::ExcludeFont(const char* const name) {
    if (frameworkHooks.excludeFont != nullptr) {
        return frameworkHooks.excludeFont(name);
    }
    return denyFonts;
}
int idResourceManagerLocal::GetCurrentDiscNumber() {
    if (frameworkHooks.currentDiscNumber != nullptr) {
        return frameworkHooks.currentDiscNumber();
    }
    if (fileSystem == nullptr) return 0;
    if (fileSystem->FileExists("virtualtextures/wellspring_coop.pages")) {
        return 3;
    }
    if (fileSystem->FileExists("virtualtextures/subway_town.pages")) {
        return 2;
    }
    return fileSystem->FileExists("virtualtextures/wellspring.pages") ? 1 : 0;
}
