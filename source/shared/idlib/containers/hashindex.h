#pragma once

#include "idlib/sys/sys_alloc.h"
#include "idlib/text/str.h"

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <new>

class idHashIndex {
public:
    int* hash;
    int* indexChain;
    int hashSize;
    int indexSize;
    int granularity;
    int hashMask;
    int lookupMask;
    memTag_t memTag;

    explicit idHashIndex(const int initialHashSize = 1024,
            const int initialIndexSize = 1024,
            const memTag_t tag = TAG_IDLIST)
        : hash(nullptr), indexChain(nullptr), hashSize(0), indexSize(0),
          granularity(1024), hashMask(0), lookupMask(0), memTag(tag) {
        InternalInit(initialHashSize, initialIndexSize);
    }

    idHashIndex(const idHashIndex& other) : idHashIndex(0, 0, other.memTag) {
        *this = other;
    }
    ~idHashIndex() { Free(); }

    idHashIndex& operator=(const idHashIndex& other) {
        if (this == &other) return *this;
        Free();
        InternalInit(other.hashSize, other.indexSize);
        granularity = other.granularity;
        memTag = other.memTag;
        if (other.hash != nullptr) Allocate(other.hashSize, other.indexSize);
        if (hash != nullptr)
            std::copy(other.hash, other.hash + hashSize, hash);
        if (indexChain != nullptr && other.indexChain != nullptr)
            std::copy(other.indexChain, other.indexChain + indexSize, indexChain);
        lookupMask = other.lookupMask;
        return *this;
    }

    void InternalInit(int initialHashSize, int initialIndexSize);
    void Allocate(int newHashSize, int newIndexSize);
    void Free();

    void Clear() {
        if (hash != nullptr) std::fill(hash, hash + hashSize, -1);
        if (indexChain != nullptr) std::fill(indexChain, indexChain + indexSize, -1);
    }

    void Add(const int key, const int index) {
        if (hash == nullptr) Allocate(hashSize, indexSize);
        EnsureIndex(index);
        if (hash == nullptr || index < 0 || index >= indexSize) return;
        const int bucket = key & hashMask;
        indexChain[index] = hash[bucket];
        hash[bucket] = index;
    }

    void Remove(const int key, const int index) {
        if (hash == nullptr || index < 0 || index >= indexSize) return;
        const int bucket = key & hashMask;
        if (hash[bucket] == index) hash[bucket] = indexChain[index];
        else {
            int current = hash[bucket];
            while (current >= 0 && indexChain[current] != index)
                current = indexChain[current];
            if (current >= 0) indexChain[current] = indexChain[index];
        }
        indexChain[index] = -1;
    }

    int First(const int key) const {
        return hash == nullptr ? -1 : hash[key & hashMask & lookupMask];
    }
    int Next(const int index) const {
        return indexChain == nullptr || index < 0 || index >= indexSize
            ? -1 : indexChain[index & lookupMask];
    }

    int GenerateKeyForString(const char* text, const bool caseSensitive = true) const {
        std::uint32_t key = 5381u;
        if (text != nullptr) {
            while (*text != '\0') {
                unsigned char value = static_cast<unsigned char>(*text++);
                if (!caseSensitive) value = static_cast<unsigned char>(std::tolower(value));
                key = ((key << 5) + key) ^ value;
            }
        }
        return static_cast<int>(key & static_cast<std::uint32_t>(hashMask));
    }

    int GetSpread() const;

    std::size_t Allocated() const {
        return static_cast<std::size_t>(hashSize + indexSize) * sizeof(int);
    }

    void ResizeIndex(int newIndexSize);

private:
    static int NextPowerOfTwo(int value) {
        int result = 1;
        while (result < value) result <<= 1;
        return result;
    }
    void EnsureIndex(const int index) {
        if (hash == nullptr) Allocate(hashSize, indexSize);
        if (index < indexSize) return;
        const int step = granularity > 0 ? granularity : 1024;
        const int newSize = ((index + 1 + step - 1) / step) * step;
        int* replacement = new (std::nothrow) int[newSize];
        if (replacement == nullptr) return;
        std::fill(replacement, replacement + newSize, -1);
        if (indexChain != nullptr) {
            std::copy(indexChain, indexChain + indexSize, replacement);
            delete[] indexChain;
        }
        indexChain = replacement;
        indexSize = newSize;
    }
};

template<typename keyType, typename valueType>
class idHashNodeT {
public:
    keyType key;
    valueType value;
    idHashNodeT* next;
};

template<typename valueType>
class idHashNodeT<const char*, valueType> {
public:
    idStr key;
    valueType value;
    idHashNodeT* next;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idHashIndex) == 32, "Recovered idHashIndex ABI changed");
#endif
