#pragma once

#include "idlib/precompiled.h"

#ifdef nullptr
#undef nullptr
#endif

#include <cstdint>

enum mtpFileMode_t {
    MTP_FS_READ = 0,
    MTP_FS_WRITE = 1,
    MTP_FS_READ_WRITE = 2,
    MTP_FS_READ_NO_BUFFERING = 3,
    MTP_FS_APPEND = 4
};

class idFile_MTP : public idFile {
public:
    idFile_MTP();
    ~idFile_MTP() override;

    const char* GetName() const override { return name.c_str(); }
    const char* GetFullPath() const override { return fullPath.c_str(); }
    int Read(void* buffer, int len) override;
    int Write(const void* buffer, int len) override;
    int Length() const override;
    ID_TIME_T Timestamp() const override { return timestamp; }
    int Tell() const override;
    int Seek(long offset, fsOrigin_t origin) override;

    bool Open(const char* filename, mtpFileMode_t openMode);
    int ReadOfs(std::int64_t offset, void* buffer, int len);
    int WriteOfs(std::int64_t offset, const void* buffer, int len);
    void SetLength(unsigned int len);
    std::uint64_t Length64() const { return length; }
    std::uint64_t Tell64() const { return position; }
    bool List(const char* directory, const char* extension,
        idList<idStr>& list);

    static void ConfigureServer(const char* host,
        unsigned short port = 2769, int writeSize = 1400,
        int timeoutMilliseconds = 1000);
    static void ShutdownTransport();

private:
    enum operation_t : unsigned short {
        OP_READ = 0,
        OP_LIST = 1,
        OP_WRITE = 2,
        OP_SET_LENGTH = 3,
        OP_OPEN = 4
    };

    static bool EnsureConnection();
    static bool SendRequest(std::uint64_t offset, unsigned int requestLength,
        operation_t operation, const char* filename);

    // BFG's idFile predates the recovered idTech 5 uniqID field.
    unsigned int uniqID;
    idStr name;
    idStr fullPath;
    std::uint64_t position;
    mtpFileMode_t mode;
    std::uint64_t length;
    unsigned int timestamp;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idFile_MTP) == 104,
    "Recovered idFile_MTP ABI changed");
#endif
