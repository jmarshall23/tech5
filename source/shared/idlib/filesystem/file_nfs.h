#pragma once

#include "idlib/precompiled.h"

#ifdef nullptr
#undef nullptr
#endif
#ifdef strcmp
#undef strcmp
#endif

#include <cstdint>

enum nfsFileMode_t {
    NFS_FS_READ = 0,
    NFS_FS_WRITE = 1,
    NFS_FS_READ_WRITE = 2,
    NFS_FS_READ_NO_BUFFERING = 3,
    NFS_FS_APPEND = 4
};

class idFile_Nfs : public idFile {
public:
    idFile_Nfs();
    ~idFile_Nfs() override;

    const char* GetName() const override { return fullPath.c_str(); }
    const char* GetFullPath() const override { return fullPath.c_str(); }
    int Read(void* buffer, int len) override;
    int Write(const void* buffer, int len) override;
    int Length() const override;
    ID_TIME_T Timestamp() const override { return timeStamp; }
    int Tell() const override;
    int Seek(long offset, fsOrigin_t origin) override;
    void Flush() override;
    void ForceFlush() override;

    bool Open(const char* path, nfsFileMode_t openMode, bool create = false,
        bool createPath = false);
    int ReadOfs(std::int64_t offset, void* buffer, int len);
    int WriteOfs(std::int64_t offset, const void* buffer, int len);
    void SetLength(unsigned int len);
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

private:
    struct NfsInternalFh { std::uint32_t pad[38]; };

    unsigned int uniqID;
    bool openRemote;
    unsigned char openPadding[3];
    NfsInternalFh fh;
    idStr fullPath;
    nfsFileMode_t mode;
    std::uint64_t position;
    std::uint64_t size;
    unsigned int timeStamp;
    bool demandSeek;
    unsigned char seekPadding[3];
    void* nfsClient;
    bool ro;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idFile_Nfs) == 232,
    "Recovered idFile_Nfs ABI changed");
#endif
