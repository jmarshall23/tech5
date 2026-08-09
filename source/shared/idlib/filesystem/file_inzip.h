#pragma once

#include "file.h"

class idFile_InZip : public idFile {
public:
    idFile_InZip();
    ~idFile_InZip() override;

    const char* GetName() const override { return name.c_str(); }
    const char* GetFullPath() const override { return fullPath.c_str(); }
    unsigned int Read(void* buffer, unsigned int length) override;
    unsigned int Write(const void* buffer, unsigned int length) override;
    std::int64_t Length() const override;
    std::int64_t Tell() const override;
    int Seek(std::int64_t offset, fsOrigin_t origin) override;
    unsigned int Timestamp() const override { return timeStamp; }
    void Flush() override;
    void ForceFlush() override;

    idStr name;
    idStr fullPath;
    int zipFilePos;
    int fileSize;
    void* z;
    unsigned int timeStamp;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idFile_InZip) == 88,
    "Recovered idFile_InZip ABI changed");
#endif
