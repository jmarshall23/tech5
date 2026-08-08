#pragma once

#include <cstdint>
#include <cstdlib>
#include <cstring>

// Recovered from shared/idlib/containers/BitArray.h.  The field order is
// intentionally kept identical to the 32-bit tungsten type.
class idBitArray {
public:
    explicit idBitArray(const std::int16_t tag = 0)
        : buffer(nullptr), bits(0), memTag(tag), ownsBuffer(false) {
    }

    idBitArray(unsigned char* storage, const unsigned int numBits,
        const std::int16_t tag = 0)
        : buffer(storage), bits(numBits), memTag(tag), ownsBuffer(false) {
        Clear();
    }

    ~idBitArray() {
        Free();
    }

    idBitArray(const idBitArray&) = delete;
    idBitArray& operator=(const idBitArray&) = delete;

    bool Alloc(const unsigned int numBits) {
        Free();
        bits = numBits;
        ownsBuffer = true;
        const std::size_t bytes = ByteCount();
        if (bytes == 0) {
            return true;
        }
        buffer = static_cast<unsigned char*>(std::calloc(bytes, 1));
        if (buffer == nullptr) {
            bits = 0;
            ownsBuffer = false;
            return false;
        }
        return true;
    }

    void Clear() {
        if (buffer != nullptr) {
            std::memset(buffer, 0, ByteCount());
        }
    }

    void Set(const unsigned int bitNum) {
        if (bitNum < bits && buffer != nullptr) {
            buffer[bitNum >> 3] |= static_cast<unsigned char>(1u << (bitNum & 7));
        }
    }

    void Clear(const unsigned int bitNum) {
        if (bitNum < bits && buffer != nullptr) {
            buffer[bitNum >> 3] &= static_cast<unsigned char>(~(1u << (bitNum & 7)));
        }
    }

    void Set(const unsigned int bitNum, const bool value) {
        if (value) {
            Set(bitNum);
        } else {
            Clear(bitNum);
        }
    }

    bool Get(const unsigned int bitNum) const {
        return bitNum < bits && buffer != nullptr
            && (buffer[bitNum >> 3] & (1u << (bitNum & 7))) != 0;
    }

    unsigned int Num() const {
        return bits;
    }

private:
    unsigned char* buffer;
    unsigned int bits;
    std::int16_t memTag;
    bool ownsBuffer;

    std::size_t ByteCount() const {
        return static_cast<std::size_t>((bits + 7u) >> 3);
    }

    void Free() {
        if (buffer != nullptr && ownsBuffer) {
            std::free(buffer);
        }
        buffer = nullptr;
        bits = 0;
        ownsBuffer = false;
    }
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idBitArray) == 12, "Recovered idBitArray ABI changed");
#endif
