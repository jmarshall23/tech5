#pragma once

#include "file.h"
#include "../containers/list.h"

#include <cstdint>

class idNfsClient;

#pragma pack(push, 4)
class idFile_Nfs : public idFile {
public:
    idFile_Nfs();
    ~idFile_Nfs() override;

    const char* GetName() const override { return fullPath.c_str(); }
    const char* GetFullPath() const override { return fullPath.c_str(); }
    unsigned int Read(void* buffer, unsigned int len) override;
    unsigned int Write(const void* buffer, unsigned int len) override;
    unsigned int ReadOfs(std::int64_t offset, void* buffer,
        unsigned int len) override;
    unsigned int WriteOfs(std::int64_t offset, const void* buffer,
        unsigned int len) override;
    std::int64_t Length() const override;
    unsigned int Timestamp() const override { return timeStamp; }
    std::int64_t Tell() const override;
    int Seek(std::int64_t offset, fsOrigin_t origin) override;
    void Flush() override;
    void ForceFlush() override;

    bool Open(const char* path, fsMode_t openMode, bool create = false,
        bool createPath = false);
    void SetLength(unsigned int len) override;
    bool SetLength64(std::uint64_t len);
    std::uint64_t Length64() const { return size; }
    std::uint64_t Tell64() const { return position; }
    int Seek64(std::int64_t offset, fsOrigin_t origin);
    bool IsReadOnly() const { return ro; }

    static bool Mount(const char* alias, const char* windowsRoot,
        bool readOnly = false);
    static void UnmountAll();
    static bool CreateOsPath(const char* path);
    static int ListFiles(const char* path, const char* extension,
        idList<idStr>& list);
    static bool RemoveFile(const char* path);
    static bool RenameFile(const char* oldPath, const char* newPath);

    class NfsInternalFh {
    public:
        std::uint32_t pad[38];
    };

private:

    bool openRemote;
    NfsInternalFh fh;
    idStr fullPath;
    fsMode_t mode;
    std::uint64_t position;
    std::uint64_t size;
    unsigned int timeStamp;
    bool demandSeek;
    idNfsClient* nfsClient;
    bool ro;
};
#pragma pack(pop)

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idFile_Nfs) == 232,
    "Recovered idFile_Nfs ABI changed");
#endif
