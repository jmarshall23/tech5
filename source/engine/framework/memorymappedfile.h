#pragma once

#include <cstdint>

class idFile;

#ifndef ID_TEMP_ARRAY_RECOVERED_DEFINED
#define ID_TEMP_ARRAY_RECOVERED_DEFINED
template<class T>
class idTempArray {
public:
    idTempArray() : buffer(nullptr), num(0) {}
    explicit idTempArray(unsigned int count)
        : buffer(count != 0 ? new T[count]() : nullptr), num(count) {}
    ~idTempArray() { delete[] buffer; }
    idTempArray(const idTempArray&) = delete;
    idTempArray& operator=(const idTempArray&) = delete;

    T& operator[](unsigned int index) { return buffer[index]; }
    const T& operator[](unsigned int index) const { return buffer[index]; }

    T* buffer;
    unsigned int num;
};
#endif

class alignas(8) idMemoryMappedFile {
public:
    static constexpr std::int64_t PAGE_SIZE = 0x10000;

    enum pageState_t : int {
        PGST_UNCOMITTED = 0,
        PGST_READING = 1,
        PGST_FULL = 2
    };
    struct mmPage_t {
        void* dest;
        bool completion;
        pageState_t state;
    };
    struct fileRange_t {
        std::int64_t fileOffset;
        std::int64_t length;
    };

    idMemoryMappedFile(idFile& sourceFile, std::int64_t fileOffset,
        std::int64_t length);
    ~idMemoryMappedFile();

    void CommitPage(int pageNum);
    void DecommitPage(int pageNum);
    void Print() const;
    bool IsBlockFullyCommitted(std::int64_t fileOffset,
        std::int64_t length) const;
    void CommitBlock(std::int64_t fileOffset, std::int64_t length);
    void DecommitBlock(std::int64_t fileOffset, std::int64_t length);
    const unsigned char* PointerForFileBlock(std::int64_t fileOffset,
        std::int64_t length);
    bool SetBatchState(const fileRange_t* ranges, int numRanges);

    idFile* file;
    const std::int64_t alignedFileOffset;
    const std::int64_t alignedLength;
    unsigned char* const virtualBase;
    idTempArray<mmPage_t> pages;
};

void RegisterMemoryMappedFileCommands();
