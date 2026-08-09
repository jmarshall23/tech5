#pragma once

#include "../bv/bounds.h"
#include "../text/strstatic.h"

#include <cstdarg>
#include <cstdint>
#include <cstdio>

enum fsPath_t : int {
    FSPATH_BASE = 0,
    FSPATH_CACHE = 1,
    FSPATH_SAVE = 2,
    FSPATH_INSTALL = 3
};

enum fsDevice_t : int {
    FS_DEVICE_HARD_DISK_DRIVE = 0,
    FS_DEVICE_OPTICAL_DISK_DRIVE = 1,
    FS_DEVICE_SOLID_STATE_DRIVE = 2,
    FS_DEVICE_NETWORK = 3,
    FS_DEVICE_MEMORY = 4
};

enum fsOrigin_t : int {
    FS_SEEK_CUR = 0,
    FS_SEEK_END = 1,
    FS_SEEK_SET = 2
};

enum fsMode_t : int {
    FS_READ = 0,
    FS_WRITE = 1,
    FS_READ_WRITE = 2,
    FS_READ_NO_BUFFERING = 3,
    FS_APPEND = 4
};

enum fsLock_t : int {
    FS_LOCK_SHARED = 0,
    FS_LOCK_EXCLUSIVE = 1
};

class idFile {
public:
    idFile();
    virtual ~idFile() = default;

    virtual const char* GetName() const { return ""; }
    virtual const char* GetFullPath() const { return GetName(); }
    virtual unsigned int Read(void*, unsigned int) { return 0; }
    virtual unsigned int Write(const void*, unsigned int) { return 0; }
    virtual unsigned int ReadOfs(std::int64_t offset, void* data,
        unsigned int length);
    virtual unsigned int WriteOfs(std::int64_t offset, const void* data,
        unsigned int length);
    virtual bool Lock(std::int64_t, unsigned int, fsLock_t) { return false; }
    virtual bool Unlock(std::int64_t, unsigned int) { return false; }
    virtual std::int64_t Length() const { return 0; }
    virtual void SetLength(unsigned int) {}
    virtual std::int64_t Tell() const { return 0; }
    virtual int Seek(std::int64_t, fsOrigin_t) { return -1; }
    virtual unsigned int Printf(const char* format, ...);
    virtual unsigned int VPrintf(const char* format, char* arguments);
    virtual unsigned int WriteFloatString(const char* format, ...);
    virtual unsigned int Timestamp() const { return 0; }
    virtual void Flush() {}
    virtual void ForceFlush() {}
    virtual int GetSectorSize() const { return 1; }
    virtual fsDevice_t GetDevice() const { return FS_DEVICE_MEMORY; }
    virtual bool IsOSNative() const { return false; }

    template<class type_t>
    unsigned int ReadLittle(type_t& value) {
        return Read(&value, static_cast<unsigned int>(sizeof(value)));
    }

    template<class type_t>
    unsigned int WriteLittle(const type_t& value) {
        return Write(&value, static_cast<unsigned int>(sizeof(value)));
    }

    unsigned int ReadString(idStr& string);
    unsigned int WriteString(const idStr& string);
    unsigned int WriteString(const char* string);

    unsigned int uniqID;
};

class idFile_Memory : public idFile {
public:
    idFile_Memory();
    explicit idFile_Memory(const char* fileName);
    ~idFile_Memory() override;

    const char* GetName() const override { return name.c_str(); }
    const char* GetFullPath() const override { return name.c_str(); }
    unsigned int Read(void* data, unsigned int length) override;
    unsigned int Write(const void* data, unsigned int length) override;
    unsigned int ReadOfs(std::int64_t offset, void* data,
        unsigned int length) override;
    unsigned int WriteOfs(std::int64_t offset, const void* data,
        unsigned int length) override;
    std::int64_t Length() const override { return fileSize; }
    void SetLength(unsigned int length) override;
    std::int64_t Tell() const override;
    int Seek(std::int64_t offset, fsOrigin_t origin) override;
    unsigned int Timestamp() const override { return timestamp; }
    fsDevice_t GetDevice() const override { return FS_DEVICE_MEMORY; }
    virtual void Clear(bool freeMemory = true);

    void SetReadOnlyData(const char* data, unsigned int length);
    void SetWritableData(char* data, unsigned int length);
    void SetMaxLength(unsigned int length);
    void MakeReadOnly();
    void MakeWritable();
    const char* GetDataPtr() const { return filePtr; }
    char* GetDataPtr() { return filePtr; }

    idStrStatic<260> name;
    int mode;
    unsigned int maxSize;
    unsigned int fileSize;
    unsigned int allocated;
    unsigned int timestamp;
    char* filePtr;
    char* curPtr;
    bool ownsData;
};

class idFile_Stat : public idFile {
public:
    idFile_Stat(const char* name = "", std::int64_t size = 0,
        unsigned int time = 0)
        : fileName(name), fileSize(size), fileTimestamp(time) {}
    const char* GetName() const override { return fileName.c_str(); }
    const char* GetFullPath() const override { return fileName.c_str(); }
    unsigned int Read(void* data, unsigned int length) override;
    unsigned int Write(const void* data, unsigned int length) override;
    unsigned int ReadOfs(std::int64_t offset, void* data,
        unsigned int length) override;
    unsigned int WriteOfs(std::int64_t offset, const void* data,
        unsigned int length) override;
    std::int64_t Length() const override { return fileSize; }
    void SetLength(unsigned int length) override;
    int Seek(std::int64_t offset, fsOrigin_t origin) override;
    unsigned int Timestamp() const override { return fileTimestamp; }

    idStr fileName;
    std::int64_t fileSize;
    unsigned int fileTimestamp;
};

class idFile_String : public idFile_Memory {
public:
    using idFile_Memory::idFile_Memory;
};

class idFileLocal {
public:
    explicit idFileLocal(idFile* filePointer = nullptr) : file(filePointer) {}
    ~idFileLocal() { delete file; }
    idFile* operator->() { return file; }
    const idFile* operator->() const { return file; }
    idFile* Release() { idFile* result = file; file = nullptr; return result; }

    idFile* file;
};

using HFILE = int;
using _HFILE = void*;

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idFile) == 8, "Recovered idFile ABI changed");
static_assert(sizeof(idFile_Memory) == 332,
    "Recovered idFile_Memory ABI changed");
static_assert(sizeof(idFile_Stat) == 56, "Recovered idFile_Stat ABI changed");
static_assert(sizeof(idFileLocal) == 4, "Recovered idFileLocal ABI changed");
#endif
