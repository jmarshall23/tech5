#pragma once

#include "idlib/sys/sys_threading.h"

#include <cstdint>

class idFile;

enum sflDrive_t : int {
    SFL_OPTICAL_DRIVE = 0,
    SFL_HARD_DRIVE = 1,
    SFL_CONTROL = 2,
    SFL_NUM_DRIVES = 3
};

enum sflIO_t : int {
    SFL_IDLE = 0,
    SFL_READ = 1,
    SFL_WRITE = 2
};

struct alignas(8) sflEntry_t {
    std::int64_t microseconds;
    sflDrive_t drive;
    sflIO_t io;
    const idFile* file;
    std::int64_t offset;
    std::int64_t length;
    int priority;
};

class idStreamFileLog {
public:
    idStreamFileLog();
    ~idStreamFileLog();

    void Enable(int entryCapacity);
    void Disable();
    void NoteFrame();
    void NoteCacheLineRequest(const idFile& file, int fileLine, int priority);
    void BeginIO(sflDrive_t drive, sflIO_t io, const idFile& file,
        std::int64_t offset, std::int64_t length, int priority);
    void EndIO(sflDrive_t drive);
    void Report() const;

    int numEntries;
    int maxEntries;
    sflEntry_t* entries;
    idSysMutex mutex;
    sflIO_t driveState[SFL_NUM_DRIVES];
    sflEntry_t* currentEntry[SFL_NUM_DRIVES];
};

extern idStreamFileLog streamFileLog;

void RegisterStreamFileLogCommands();

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(sflEntry_t) == 48, "Recovered sflEntry_t ABI changed");
#endif
