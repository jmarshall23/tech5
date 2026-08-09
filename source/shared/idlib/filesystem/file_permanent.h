#pragma once

#include "file.h"

class alignas(8) idFile_Permanent : public idFile {
public:
    idFile_Permanent(const char* relativePath, const char* osPath,
        fsMode_t fileMode, bool create);
    ~idFile_Permanent() override;

    const char* GetName() const override { return name.c_str(); }
    const char* GetFullPath() const override { return fullPath.c_str(); }
    unsigned int Read(void* data, unsigned int length) override;
    unsigned int Write(const void* data, unsigned int length) override;
    unsigned int ReadOfs(std::int64_t offset, void* data,
        unsigned int length) override;
    unsigned int WriteOfs(std::int64_t offset, const void* data,
        unsigned int length) override;
    bool Lock(std::int64_t offset, unsigned int length, fsLock_t lock) override;
    bool Unlock(std::int64_t offset, unsigned int length) override;
    std::int64_t Length() const override;
    void SetLength(unsigned int length) override;
    std::int64_t Tell() const override;
    int Seek(std::int64_t offset, fsOrigin_t origin) override;
    unsigned int Timestamp() const override;
    void Flush() override;
    void ForceFlush() override;
    int GetSectorSize() const override { return sectorSize; }
    fsDevice_t GetDevice() const override { return device; }
    bool IsOSNative() const override { return true; }
    bool IsOpen() const { return handle != nullptr; }

    idStr name;
    idStr fullPath;
    fsMode_t mode;
    std::int64_t fileSize;
    int sectorSize;
    fsDevice_t device;
    void* handle;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idFile_Permanent) == 104,
    "Recovered idFile_Permanent ABI changed");
#endif
