#pragma once

#include "idlib/containers/list.h"
#include "idlib/text/str.h"

#include <cstdint>

class idFile;
class idFile_Memory;
class idFile_Stat;
class idGame;
struct idGameSpawnInfo;

class idResourceManager {
public:
    virtual ~idResourceManager();
    virtual void Init() = 0;
    virtual void Init2(bool toolsMode) = 0;
    virtual void Shutdown() = 0;
    virtual void CancelToTerminate() = 0;
    virtual void CloseOpenFileHandles() = 0;
    virtual bool ReOpenFileHandles() = 0;
    virtual void StartupComplete() = 0;
    virtual void SetFileHook() = 0;
    virtual void ReleaseFileHook() = 0;
    virtual bool AllocGameWithResourceFile(idGame**, const idGameSpawnInfo*,
        idFile*, const char*) = 0;
    virtual idFile_Memory* LoadCacheFile(const char*) = 0;
    virtual idFile_Memory* LoadPatchFile(const char*) = 0;
    virtual idFile_Stat* StatCacheFile(const char*) = 0;
    virtual idFile_Stat* StatPatchFile(const char*) = 0;
    virtual bool GetCacheFileInfo(const char*, std::int64_t*, unsigned int*,
        unsigned int*, unsigned int*, bool) = 0;
    virtual bool GetPatchFileInfo(const char*, std::int64_t*, unsigned int*,
        unsigned int*, unsigned int*, int*) = 0;
    virtual idFile* GetCacheFile() = 0;
    virtual idFile* GetPatchFile(int) = 0;
    virtual idFile* GetStreamFile() = 0;
    virtual idFile* GetCachedStreamFile() = 0;
    virtual idFile* GetLocalizedStreamFile() = 0;
    virtual bool IsResourceFile(idFile*) = 0;
    virtual void SetResourceFilePlatform(unsigned int) = 0;
    virtual unsigned int GetBuildPlatforms() = 0;
    virtual void BeginEntity(const char*, const idList<idStr, 5>*) = 0;
    virtual void EndEntity() = 0;
    virtual const idList<idStr, 5>* GetLanguages() = 0;
    virtual bool ExcludeImage(const char*) = 0;
    virtual bool ExcludeFont(const char*) = 0;
    virtual int GetCurrentDiscNumber() = 0;
};

extern idResourceManager* resourceManager;
