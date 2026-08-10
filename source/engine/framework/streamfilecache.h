#pragma once

#include "idlib/filesystem/file.h"
#include "idlib/sys/sys_alloc.h"
#include "idlib/sys/sys_threading.h"

#include <cstdint>

class idStreamControlThread;

enum pfcRequest_t : int {
    PFC_TEXTURE = 0,
    PFC_SOUND = 1
};

struct cacheLineRequest_t {
    idFile* file;
    int fileLine;
    int priority;
    int persistence;
};

class alignas(4) idStreamFileCache {
public:
    idStreamFileCache();
    ~idStreamFileCache();

    void Init();
    void Shutdown();
    void Flush();
    void NewFrame();
    void ServiceBink(fsDevice_t device);
    std::int64_t GetCurrentUsageLimit() const;
    void Stats();
    void SignalWork();
    void UncachedBackgroundRead(idFile* file, std::int64_t offset, int length,
        void** destination, memTag_t tag, volatile bool* completionFlag);
    void BatchUncachedBackgroundRead(idFile* file, const std::int64_t* offsets,
        const int* lengths, void*** destinations, memTag_t tag,
        volatile bool** completionFlags, int count);
    unsigned int UncachedScheduledRead(idFile& file, std::int64_t offset,
        void* destination, int length);
    void BatchFreeMemory(void** pointers, int count);
    void ProvideCacheMemory(void* memory, std::int64_t length);
    bool OutOfMemoryCallback();
    int GetAvailableMemory() const;
    void InitHDC();
    void ClearMem(bool releaseProvidedMemory);
    void ClearHDC();
    int ReadCachedData(idFile* file, std::int64_t offset, int length,
        void* destination, bool blocking, int priority, int persistence,
        pfcRequest_t requestType);
    void BatchRequestCacheLines(const cacheLineRequest_t* requests, int count);

    idSysMutex interfaceMutex;
    idStreamControlThread* controlThread;
    volatile bool cancelToTerminate;
};

extern idStreamFileCache* streamFileCache;

void RegisterStreamFileCacheCommands();

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(cacheLineRequest_t) == 16,
    "Recovered cacheLineRequest_t ABI changed");
#endif
