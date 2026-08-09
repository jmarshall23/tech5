#pragma once

#include "file.h"
#include "../containers/hashindex.h"

#include <cstdint>

class idCompressor : public idFile {
public:
    ~idCompressor() override;

    virtual void Init(idFile* file, bool compress, int wordLength) = 0;
    virtual void FinishCompress() = 0;
    virtual float GetCompressionRatio() const = 0;
    virtual int GetCompressedSize() const = 0;
    virtual int GetUncompressedSize() const = 0;

    static idCompressor* AllocArithmetic();
    static idCompressor* AllocLZSS_ByteAligned();
    static idCompressor* AllocLZW();
    static idCompressor* AllocRunLength_ZeroBased();
};

class alignas(4) idCompressor_None : public idCompressor {
public:
    idCompressor_None();
    ~idCompressor_None() override;

    const char* GetName() const override;
    const char* GetFullPath() const override;
    unsigned int Read(void* buffer, unsigned int length) override;
    unsigned int Write(const void* buffer, unsigned int length) override;
    std::int64_t Length() const override;
    std::int64_t Tell() const override;
    int Seek(std::int64_t offset, fsOrigin_t origin) override;
    unsigned int Timestamp() const override;
    void Flush() override;
    void ForceFlush() override;
    void Init(idFile* backingFile, bool compressing, int wordBits) override;
    void FinishCompress() override;
    float GetCompressionRatio() const override;
    int GetCompressedSize() const override;
    int GetUncompressedSize() const override;

    idFile* file;
    bool compress;
};

class idCompressor_BitStream : public idCompressor_None {
public:
    idCompressor_BitStream();
    ~idCompressor_BitStream() override;

    unsigned int Read(void* buffer, unsigned int length) override;
    unsigned int Write(const void* buffer, unsigned int length) override;
    void Init(idFile* backingFile, bool compressing, int wordBits) override;
    void FinishCompress() override;
    float GetCompressionRatio() const override;
    int GetCompressedSize() const override;
    int GetUncompressedSize() const override;

    std::uint8_t buffer[512];
    int wordLength;
    int readTotalBytes;
    int readTotalBits;
    int readLength;
    int readByte;
    int readBit;
    const std::uint8_t* readData;
    int writeTotalBytes;
    int writeTotalBits;
    int writeLength;
    int writeByte;
    int writeBit;
    std::uint8_t* writeData;

protected:
    void InitDecompress(void* data, int length);
    int ReadBits(int numBits);
    std::uint8_t ReadAlignedByte();
    std::uint16_t ReadAlignedWord();
    void WriteBits(int value, int numBits);
    void WriteAlignedByte(std::uint8_t value);
    void WriteAlignedWord(std::uint16_t value);
};

class idCompressor_RunLength : public idCompressor_BitStream {
public:
    ~idCompressor_RunLength() override;
    unsigned int Read(void* buffer, unsigned int length) override;
    unsigned int Write(const void* buffer, unsigned int length) override;
    void Init(idFile* backingFile, bool compressing, int wordBits) override;
    void FinishCompress() override;

    int runLengthCode;
};

class idCompressor_ZRLE_ByteAligned : public idCompressor_BitStream {
public:
    ~idCompressor_ZRLE_ByteAligned() override;
    unsigned int Read(void* buffer, unsigned int length) override;
    unsigned int Write(const void* buffer, unsigned int length) override;
    void Init(idFile* backingFile, bool compressing, int wordBits) override;
    void FinishCompress() override;

    int zeroCount;
};

class idCompressor_RunLength_ZeroBased : public idCompressor_BitStream {
public:
    idCompressor_RunLength_ZeroBased();
    ~idCompressor_RunLength_ZeroBased() override;
    unsigned int Read(void* buffer, unsigned int length) override;
    unsigned int Write(const void* buffer, unsigned int length) override;
    void Init(idFile* backingFile, bool compressing, int wordBits) override;
    void FinishCompress() override;

    std::uint8_t buffer[32];
    int bp;
    int count;
    int runBits;
    int maxRun;

private:
    bool BitsToRead();
    bool BitsToWrite();
    int CompressBlock(const std::uint8_t* input, int length);
    int DecompressBlock(std::uint8_t* output, int length);
    void WriteRun();
};

struct idHuffmanNode {
    idHuffmanNode* left;
    idHuffmanNode* right;
    idHuffmanNode* parent;
    idHuffmanNode* next;
    idHuffmanNode* prev;
    idHuffmanNode** head;
    int weight;
    int symbol;
};

class idCompressor_Huffman : public idCompressor_None {
public:
    idCompressor_Huffman();
    ~idCompressor_Huffman() override;
    unsigned int Read(void* buffer, unsigned int length) override;
    unsigned int Write(const void* buffer, unsigned int length) override;
    void Init(idFile* backingFile, bool compressing, int wordBits) override;
    void FinishCompress() override;
    float GetCompressionRatio() const override;
    int GetCompressedSize() const override;
    int GetUncompressedSize() const override;

    std::uint8_t seq[65536];
    int bloc;
    int blocMax;
    int blocIn;
    int blocNode;
    int blocPtrs;
    int compressedSize;
    int unCompressedSize;
    idHuffmanNode* tree;
    idHuffmanNode* lhead;
    idHuffmanNode* ltail;
    idHuffmanNode* loc[257];
    idHuffmanNode** freelist;
    idHuffmanNode nodeList[768];
    idHuffmanNode* nodePtrs[768];
};

class idCompressor_Arithmetic : public idCompressor_BitStream {
public:
    struct idAcProbs {
        unsigned int low;
        unsigned int high;
    };
    struct idAcSymbol {
        unsigned int low;
        unsigned int high;
        int position;
    };

    idCompressor_Arithmetic();
    ~idCompressor_Arithmetic() override;
    unsigned int Read(void* buffer, unsigned int length) override;
    unsigned int Write(const void* buffer, unsigned int length) override;
    void Init(idFile* backingFile, bool compressing, int wordBits) override;
    void FinishCompress() override;

    idAcProbs probabilities[256];
    int symbolBuffer;
    int symbolBit;
    std::uint16_t low;
    std::uint16_t high;
    std::uint16_t code;
    unsigned int underflowBits;
    unsigned int scale;

private:
    void EncodeSymbol(idAcSymbol* symbol);
    int GetByte();
    void InitCode();
    int ProbabilityForCount(unsigned int count);
    void RemoveSymbolFromStream(idAcSymbol* symbol);
    void UpdateProbabilities(idAcSymbol* symbol);
    void WriteOverflowBits();
};

class idCompressor_LZSS : public idCompressor_BitStream {
public:
    idCompressor_LZSS();
    ~idCompressor_LZSS() override;
    unsigned int Read(void* buffer, unsigned int length) override;
    unsigned int Write(const void* buffer, unsigned int length) override;
    void Init(idFile* backingFile, bool compressing, int wordBits) override;
    void FinishCompress() override;

    virtual void CompressBlock();
    virtual void DecompressBlock();

    int offsetBits;
    int lengthBits;
    int minMatchWords;
    std::uint8_t block[32768];
    int blockSize;
    int blockIndex;
    int hashTable[1024];
    int hashNext[32768];
};

class idCompressor_LZSS_WordAligned : public idCompressor_LZSS {
public:
    ~idCompressor_LZSS_WordAligned() override;
    void CompressBlock() override;
    void DecompressBlock() override;
};

class idCompressor_LZSS_ByteAligned : public idCompressor_BitStream {
public:
    idCompressor_LZSS_ByteAligned();
    ~idCompressor_LZSS_ByteAligned() override;
    unsigned int Read(void* buffer, unsigned int length) override;
    unsigned int Write(const void* buffer, unsigned int length) override;
    void Init(idFile* backingFile, bool compressing, int wordBits) override;
    void FinishCompress() override;

    int offsetBits;
    int lengthBits;
    int minMatchWords;
    std::uint8_t block[131072];
    int blockSize;
    int blockIndex;
    int hashTable[65536];
    int hashNext[131072];

private:
    void CompressBlock();
    void DecompressBlock();
    bool FindByteMatch(int start, int end, int& offset, int& length);
    int GetHashKey(int index) const;
};

class idCompressor_LZW : public idCompressor_BitStream {
public:
    struct dictionary_t {
        int k;
        int w;
    };

    idCompressor_LZW();
    ~idCompressor_LZW() override;
    unsigned int Read(void* buffer, unsigned int length) override;
    unsigned int Write(const void* buffer, unsigned int length) override;
    void Init(idFile* backingFile, bool compressing, int wordBits) override;
    void FinishCompress() override;

    dictionary_t dictionary[4096];
    idHashIndex index;
    int nextCode;
    int codeBits;
    std::uint8_t block[32768];
    int blockSize;
    int blockIndex;
    int codeWord;
    int oldCode;

protected:
    bool BumpBits();
    void DecompressBlock();
    int Lookup(int w, int k);
    int WriteChain(int code);
};

struct lzwCompressionData_t {
    std::uint8_t dictionaryK[4096];
    std::uint16_t dictionaryW[4096];
    int nextCode;
    int codeBits;
    int codeWord;
    std::uint64_t tempValue;
    int tempBits;
    int bytesWritten;
};

class alignas(8) idLZWCompressor {
public:
    void Start(std::uint8_t* streamData, int maximumSize, bool append);
    int End();
    int Read(void* output, int length, bool ignoreOverflow = false);
    int Write(const void* input, int length);
    int ReadByte(bool ignoreOverflow = false);
    void WriteByte(std::uint8_t value);
    int ReadBits(int bits);
    void WriteBits(unsigned int value, int bits);
    void Save();
    void Restore();
    bool BumpBits();
    void DecompressBlock();
    int Lookup(int w, int k);
    int WriteChain(int code);

    template<class type_t>
    unsigned int ReadAgnostic(type_t& value, bool ignoreOverflow = false) {
        return static_cast<unsigned int>(
            Read(&value, static_cast<int>(sizeof(value)), ignoreOverflow));
    }

    lzwCompressionData_t* lzwData;
    std::uint16_t hash[1024];
    std::uint16_t nextHash[4096];
    int oldCode;
    std::uint8_t* data;
    int maxSize;
    bool overflowed;
    int bytesRead;
    std::uint8_t block[32768];
    int blockSize;
    int blockIndex;
    int savedBytesWritten;
    int savedCodeWord;
    int saveCodeBits;
    std::uint64_t savedTempValue;
    int savedTempBits;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idCompressor) == 8,
    "Recovered idCompressor ABI changed");
static_assert(sizeof(idCompressor_None) == 16,
    "Recovered idCompressor_None ABI changed");
static_assert(sizeof(idCompressor_BitStream) == 580,
    "Recovered idCompressor_BitStream ABI changed");
static_assert(sizeof(idCompressor_RunLength_ZeroBased) == 628,
    "Recovered zero-run compressor ABI changed");
static_assert(sizeof(idHuffmanNode) == 32,
    "Recovered idHuffmanNode ABI changed");
static_assert(sizeof(idCompressor_Arithmetic) == 2652,
    "Recovered arithmetic compressor ABI changed");
static_assert(sizeof(idCompressor_LZSS) == 168536,
    "Recovered LZSS compressor ABI changed");
static_assert(sizeof(idCompressor_LZSS_ByteAligned) == 918104,
    "Recovered byte-aligned LZSS ABI changed");
static_assert(sizeof(idCompressor_LZW) == 66172,
    "Recovered LZW compressor ABI changed");
static_assert(sizeof(lzwCompressionData_t) == 12320,
    "Recovered LZW state ABI changed");
static_assert(sizeof(idLZWCompressor) == 43072,
    "Recovered lightweight LZW ABI changed");
#endif
