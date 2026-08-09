#pragma once

#include "file.h"
#include "../containers/list.h"

#include <cstdint>

class alignas(8) idFile_MTP : public idFile {
public:
    idFile_MTP();
    ~idFile_MTP() override;

    const char* GetName() const override { return name.c_str(); }
    const char* GetFullPath() const override { return fullPath.c_str(); }
    unsigned int Read(void* buffer, unsigned int len) override;
    unsigned int Write(const void* buffer, unsigned int len) override;
    unsigned int ReadOfs(std::int64_t offset, void* buffer,
        unsigned int len) override;
    unsigned int WriteOfs(std::int64_t offset, const void* buffer,
        unsigned int len) override;
    std::int64_t Length() const override;
    unsigned int Timestamp() const override { return timestamp; }
    std::int64_t Tell() const override;
    int Seek(std::int64_t offset, fsOrigin_t origin) override;

    bool Open(const char* filename, fsMode_t openMode);
    void SetLength(unsigned int len) override;
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

    idStr name;
    idStr fullPath;
    std::uint64_t position;
    fsMode_t mode;
    std::uint64_t length;
    unsigned int timestamp;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idFile_MTP) == 104,
    "Recovered idFile_MTP ABI changed");
#endif
