#pragma once

#include "framework/resourcemanager_local.h"

#include "idlib/filesystem/file.h"
#include "idlib/sys/sys_threading.h"

#include <cstdint>

class idBGLRingBuffer {
public:
    explicit idBGLRingBuffer(int bufferSize);
    ~idBGLRingBuffer();
    std::int64_t CheckSpaceAndWait(std::int64_t length, int alignment);
    void Free(std::int64_t offset, int length);
    unsigned int ReadOfs(std::int64_t offset, void* data, unsigned int length);
    void WriteOfs(std::int64_t offset, const void* data, unsigned int length);

    unsigned char* buffer;
    int size;
    std::int64_t tail;
    std::int64_t commitHead;
    bool cancelToTerminate;
    idSysSignal freeSignal;
    std::int64_t lastFreeSignalTail;
    idSysSignal dataSignal;
    std::int64_t lastDataSignalHead;
    int freeWaituS;
    int numFreeWaits;
    int dataWaituS;
    int numDataWaits;
};

class idFile_RingBuffer : public idFile {
public:
    idFile_RingBuffer(const char* name, idBGLRingBuffer* ring,
        std::int64_t baseOffset, int length);
    ~idFile_RingBuffer() override;
    const char* GetName() const override;
    unsigned int Read(void* data, unsigned int length) override;
    std::int64_t Length() const override;
    std::int64_t Tell() const override;
    int Seek(std::int64_t offset, fsOrigin_t origin) override;

    idBGLRingBuffer* ringBuffer;
    idStr name;
    unsigned int fileSize;
    std::int64_t baseOffset;
    std::int64_t currOffset;
};

class idBackgroundLoader {
public:
    struct bgrEntry_t { std::int64_t ringBufferOffset; };

    idBackgroundLoader();
    ~idBackgroundLoader();
    void BeginBackgroundLoads(idFile& source,
        const idList<idResourceFileEntry, 99>& entries);
    void EndBackgroundLoads();
    idFile* GetFile(const char* resourceName);
    void SkipPastResource(const idResource* resource);
    void SpawnThreads();
    void DestroyThreads();

    idFile* resourceFile;
    const idList<idResourceFileEntry, 99>* fileTable;
    idList<bgrEntry_t, 99> bgrEntries;
    volatile int readIndex;
    volatile int decompressIndex;
    int returnedIndex;
    volatile bool cancelToTerminate;
    idSysSignal entryStartedSignal;
    idBGLRingBuffer* decompressBuffer;
};
