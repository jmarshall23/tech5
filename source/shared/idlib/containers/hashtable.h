#pragma once

#include "idlib/containers/hashindex.h"

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <functional>
#include <new>

template<typename keyType>
struct idHashTableKeyOps {
    static std::uint32_t Hash(const keyType& key) {
        return static_cast<std::uint32_t>(std::hash<keyType>()(key));
    }
    static bool Equal(const keyType& stored, const keyType& key) {
        return stored == key;
    }
};

template<>
struct idHashTableKeyOps<const char*> {
    static std::uint32_t Hash(const char* key) {
        std::uint32_t hash = 2166136261u;
        if (key != nullptr) while (*key != '\0') {
            hash = (hash ^ static_cast<unsigned char>(*key++)) * 16777619u;
        }
        return hash;
    }
    static bool Equal(const idStr& stored, const char* key) {
        return idStr::Cmp(stored.c_str(), key) == 0;
    }
};

template<typename keyType, typename valueType>
class idHashTableT {
public:
    using nodeType = idHashNodeT<keyType, valueType>;

    nodeType** heads;
    int tableSize;
    int numEntries;
    int tableSizeMask;

    explicit idHashTableT(const int requestedSize = 256)
        : heads(nullptr), tableSize(NextPowerOfTwo(requestedSize)),
          numEntries(0), tableSizeMask(tableSize - 1) {
        heads = new (std::nothrow) nodeType*[tableSize];
        if (heads != nullptr) std::fill(heads, heads + tableSize, nullptr);
    }
    ~idHashTableT() { Clear(); delete[] heads; }

    idHashTableT(const idHashTableT&) = delete;
    idHashTableT& operator=(const idHashTableT&) = delete;

    int Num() const { return numEntries; }
    void Clear() {
        if (heads == nullptr) return;
        for (int bucket = 0; bucket < tableSize; ++bucket) {
            nodeType* node = heads[bucket];
            while (node != nullptr) {
                nodeType* next = node->next;
                delete node;
                node = next;
            }
            heads[bucket] = nullptr;
        }
        numEntries = 0;
    }

    bool Get(const keyType& key, valueType** value) {
        nodeType* node = FindNode(key);
        if (value != nullptr) *value = node == nullptr ? nullptr : &node->value;
        return node != nullptr;
    }
    bool Get(const keyType& key, const valueType** value) const {
        const nodeType* node = FindNode(key);
        if (value != nullptr) *value = node == nullptr ? nullptr : &node->value;
        return node != nullptr;
    }

    valueType& Set(const keyType& key, const valueType& value) {
        nodeType* node = FindNode(key);
        if (node == nullptr) {
            const int bucket = Bucket(key);
            node = new nodeType();
            node->key = key;
            node->next = heads[bucket];
            heads[bucket] = node;
            ++numEntries;
        }
        node->value = value;
        return node->value;
    }

    valueType* GetIndex(int index) {
        if (index < 0 || index >= numEntries) return nullptr;
        for (int bucket = 0; bucket < tableSize; ++bucket)
            for (nodeType* node = heads[bucket]; node != nullptr; node = node->next)
                if (index-- == 0) return &node->value;
        return nullptr;
    }

private:
    static int NextPowerOfTwo(int value) {
        int result = 1;
        while (result < (value > 0 ? value : 1)) result <<= 1;
        return result;
    }
    int Bucket(const keyType& key) const {
        return static_cast<int>(idHashTableKeyOps<keyType>::Hash(key)) & tableSizeMask;
    }
    nodeType* FindNode(const keyType& key) {
        if (heads == nullptr) return nullptr;
        for (nodeType* node = heads[Bucket(key)]; node != nullptr; node = node->next)
            if (idHashTableKeyOps<keyType>::Equal(node->key, key)) return node;
        return nullptr;
    }
    const nodeType* FindNode(const keyType& key) const {
        return const_cast<idHashTableT*>(this)->FindNode(key);
    }
};

template<typename valueType>
class idHashTable : public idHashTableT<const char*, valueType> {
public:
    using idHashTableT<const char*, valueType>::idHashTableT;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idHashTableT<int, int>) == 16,
    "Recovered idHashTableT ABI changed");
#endif
