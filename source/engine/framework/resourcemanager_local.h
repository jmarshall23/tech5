#pragma once

#include "framework/resourcemanager.h"

#include "idlib/containers/hashindex.h"
#include "idlib/containers/staticlist.h"
#include "idlib/text/atomicstring.h"
#include "idlib/text/strstatic.h"

class idResource;
class idResourceList;
class idResourceAnnotation;

struct idPlatformStreamData {
    char lang[16];
    unsigned int streamAlignment;
    unsigned int streamLength;
    void* streamData;
};

struct idResourceFileEntry {
    int resourceIndex;
    idResourceList* resourceList;
    idStrStatic<32> typeName;
    idStrStatic<256> resourceName;
    idStrStatic<256> filename;
    unsigned int offset;
    int compressedLength;
    int uncompressedLength;
    idStaticList<idPlatformStreamData, 16> stream;
    char lang[16];
    int useBits;
};

struct idResourceCacheEntry {
    idAtomicString filename;
    unsigned int offset;
    unsigned int streamOffset;
    int compressedLength;
    int uncompressedLength;
};

class alignas(4) idResourceManagerLocal : public idResourceManager {
public:
    idResourceManagerLocal();
    ~idResourceManagerLocal() override;

    void Init() override;
    void Init2(bool toolsMode) override;
    void Shutdown() override;
    void CancelToTerminate() override;
    void CloseOpenFileHandles() override;
    bool ReOpenFileHandles() override;
    void StartupComplete() override;
    void SetFileHook() override;
    void ReleaseFileHook() override;
    bool AllocGameWithResourceFile(idGame**, const idGameSpawnInfo*, idFile*,
        const char*) override;
    idFile_Memory* LoadCacheFile(const char*) override;
    idFile_Memory* LoadPatchFile(const char*) override;
    idFile_Stat* StatCacheFile(const char*) override;
    idFile_Stat* StatPatchFile(const char*) override;
    bool GetCacheFileInfo(const char*, std::int64_t*, unsigned int*,
        unsigned int*, unsigned int*, bool) override;
    bool GetPatchFileInfo(const char*, std::int64_t*, unsigned int*,
        unsigned int*, unsigned int*, int*) override;
    idFile* GetCacheFile() override;
    idFile* GetPatchFile(int) override;
    idFile* GetStreamFile() override;
    idFile* GetCachedStreamFile() override;
    idFile* GetLocalizedStreamFile() override;
    bool IsResourceFile(idFile*) override;
    void SetResourceFilePlatform(unsigned int) override;
    unsigned int GetBuildPlatforms() override;
    void BeginEntity(const char*, const idList<idStr, 5>*) override;
    void EndEntity() override;
    const idList<idStr, 5>* GetLanguages() override;
    bool ExcludeImage(const char*) override;
    bool ExcludeFont(const char*) override;
    int GetCurrentDiscNumber() override;

    idFile* resourceFile;
    idFile* streamFile;
    idFile* localizedStreamFile;
    idFile* cachedStreamFile;
    idStaticList<idFile*, 32> patchFiles;
    unsigned int tableOffset;
    unsigned int tableLength;
    unsigned int resourceMagic;
    idResourceAnnotation* currentSortedResource;
    idResource* currentResource;
    idList<idResourceFileEntry, 99> writtenResourceTable;
    idList<idResourceFileEntry, 99> fileTable;
    int fileTableResource;
    idList<idResourceCacheEntry, 99> cacheTable;
    idHashIndex cacheHash;
    idList<idResourceCacheEntry, 99> patchTable;
    idHashIndex patchHash;
    unsigned int filePlatformBits;
    unsigned int buildPlatforms;
    int lastUPacifierMsec;
    idList<idStr, 5> languages;
    bool denyFonts;
    volatile bool cancelToTerminate;
};
