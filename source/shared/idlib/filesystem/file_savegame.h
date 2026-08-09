#pragma once

#include "file.h"
#include "../sys/sys_threading.h"
#include "../text/strstatic.h"

#include <cstdint>

struct internal_state;

struct z_stream_s {
    std::uint8_t* next_in;
    unsigned int avail_in;
    unsigned int total_in;
    std::uint8_t* next_out;
    unsigned int avail_out;
    unsigned int total_out;
    char* msg;
    internal_state* state;
    void* (*zalloc)(void* opaque, unsigned int items, unsigned int size);
    void (*zfree)(void* opaque, void* address);
    void* opaque;
    int data_type;
    unsigned int adler;
    unsigned int reserved;
};

struct blockForIO_t {
    std::uint8_t* data;
    unsigned int bytes;
};

class idFile_SaveGame : public idFile_Memory {
public:
    idFile_SaveGame(const char* name, int type);
    ~idFile_SaveGame() override = default;

    int type;
    bool error;
};

class idFile_SaveGamePipelined;

class idSGFreadThread : public idSysThread {
public:
    explicit idSGFreadThread(idFile_SaveGamePipelined* file = nullptr)
        : sgf(file) {}
    ~idSGFreadThread() override;
    int Run() override;
    idFile_SaveGamePipelined* sgf;
};

class idSGFwriteThread : public idSysThread {
public:
    explicit idSGFwriteThread(idFile_SaveGamePipelined* file = nullptr)
        : sgf(file) {}
    ~idSGFwriteThread() override;
    int Run() override;
    idFile_SaveGamePipelined* sgf;
};

class idSGFdecompressThread : public idSysThread {
public:
    explicit idSGFdecompressThread(idFile_SaveGamePipelined* file = nullptr)
        : sgf(file) {}
    ~idSGFdecompressThread() override;
    int Run() override;
    idFile_SaveGamePipelined* sgf;
};

class idSGFcompressThread : public idSysThread {
public:
    explicit idSGFcompressThread(idFile_SaveGamePipelined* file = nullptr)
        : sgf(file) {}
    ~idSGFcompressThread() override;
    int Run() override;
    idFile_SaveGamePipelined* sgf;
};

class alignas(8) idFile_SaveGamePipelined : public idFile {
public:
    enum mode_t : int {
        WRITE = 0x1,
        READ = 0x2
    };

    idFile_SaveGamePipelined();
    ~idFile_SaveGamePipelined() override;

    const char* GetName() const override { return name.c_str(); }
    const char* GetFullPath() const override { return osPath.c_str(); }
    unsigned int Read(void* buffer, unsigned int length) override;
    unsigned int Write(const void* buffer, unsigned int length) override;
    std::int64_t Length() const override { return compressedLength; }
    void SetLength(unsigned int length) override { compressedLength = length; }
    std::int64_t Tell() const override;
    unsigned int Timestamp() const override { return 0; }
    void Flush() override {}
    void ForceFlush() override {}

    bool OpenForReading(const char* const fileName, bool threaded);
    bool OpenForWriting(const char* const fileName, bool threaded);
    bool NextReadBlock(blockForIO_t* block, unsigned int checksum);
    bool NextWriteBlock(blockForIO_t* block);
    void Finish();
    void Abort();

    static bool cancelToTerminate;

    std::int64_t ioPos;
    idStr name;
    idStr osPath;
    mode_t mode;
    unsigned int compressedLength;
    std::uint8_t uncompressed[524288];
    unsigned int uncompressedProducedBytes;
    unsigned int uncompressedConsumedBytes;
    std::uint8_t compressed[262144];
    unsigned int compressedProducedBytes;
    unsigned int compressedConsumedBytes;
    std::uint8_t* dataZlib;
    unsigned int bytesZlib;
    std::uint8_t* dataIO;
    unsigned int bytesIO;
    z_stream_s zStream;
    int zLibFlushType;
    bool zStreamEndHit;
    int numChecksums;
    idFile* nativeFile;
    bool nativeFileEndHit;
    bool finished;
    idSGFreadThread* readThread;
    idSGFwriteThread* writeThread;
    idSGFdecompressThread* decompressThread;
    idSGFcompressThread* compressThread;
    idSysSignal blockRequested;
    idSysSignal blockAvailable;
    idSysSignal blockFinished;
    idStrStatic<32> buildVersion;
    std::int16_t pointerSize;
    std::int16_t saveFormatVersion;

private:
    void CompressBlock();
    void DecompressBlock();
    void FlushCompressedBlock();
    void FlushUncompressedBlock();
    void PumpCompressedBlock();
    void ReadBlock();
    void WriteBlock();
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(z_stream_s) == 56, "Recovered z_stream_s ABI changed");
static_assert(sizeof(blockForIO_t) == 8,
    "Recovered blockForIO_t ABI changed");
static_assert(sizeof(idFile_SaveGame) == 340,
    "Recovered idFile_SaveGame ABI changed");
static_assert(sizeof(idSGFreadThread) == 60,
    "Recovered savegame worker ABI changed");
static_assert(sizeof(idFile_SaveGamePipelined) == 786728,
    "Recovered pipelined savegame ABI changed");
#endif
