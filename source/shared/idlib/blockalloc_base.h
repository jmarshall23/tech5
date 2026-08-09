#pragma once

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <malloc.h>
#include <new>

// Fixed block allocator reconstructed from the repeated PDB specializations
// and the AllocNewBlock/Alloc/Free/Shutdown bodies in the Hex-Rays dump.
template<class T, int blockSize, int memTag = 0>
class idBlockAlloc {
public:
    static_assert(blockSize > 0, "idBlockAlloc requires a positive block size");

    static constexpr std::size_t ELEMENT_SIZE =
        sizeof(T) > sizeof(void*) ? sizeof(T) : sizeof(void*);

    union element_t {
        T* data;
        element_t* next;
        alignas(T) unsigned char buffer[ELEMENT_SIZE];

        element_t() {}
        ~element_t() {}
    };

    class idBlock {
    public:
        element_t elements[blockSize];
        idBlock* next;
        element_t* free;
        int freeCount;

        idBlock() : next(nullptr), free(nullptr), freeCount(0) {}
    };

    idBlock* blocks;
    element_t* free;
    int total;
    int active;
    bool allowAllocs;
    bool clearAllocs;

    explicit idBlockAlloc(const bool clear = false)
        : blocks(nullptr), free(nullptr), total(0), active(0),
          allowAllocs(true), clearAllocs(clear) {
    }

    ~idBlockAlloc() {
        Shutdown();
    }

    idBlockAlloc(const idBlockAlloc&) = delete;
    idBlockAlloc& operator=(const idBlockAlloc&) = delete;

    std::size_t Allocated() const {
        return static_cast<std::size_t>(total) * sizeof(T);
    }

    std::size_t Size() const {
        return sizeof(*this) + Allocated();
    }

    void Shutdown() {
        while (blocks != nullptr) {
            idBlock* const block = blocks;
            blocks = block->next;
            block->~idBlock();
            _aligned_free(block);
        }
        blocks = nullptr;
        free = nullptr;
        active = 0;
        total = 0;
    }

    void SetFixedBlocks(const int numBlocks) {
        const int count = numBlocks > 0 ? numBlocks : 0;
        while (total < count * blockSize && AllocNewBlock()) {
        }
        allowAllocs = false;
    }

    void SetAllocAllowed(const bool allowed) {
        allowAllocs = allowed;
    }

    void SetClear(const bool clear) {
        clearAllocs = clear;
    }

    void FreeEmptyBlocks() {
        for (idBlock* block = blocks; block != nullptr; block = block->next) {
            block->free = nullptr;
            block->freeCount = 0;
        }

        element_t* element = free;
        while (element != nullptr) {
            element_t* const next = element->next;
            const std::uintptr_t address = reinterpret_cast<std::uintptr_t>(element);
            for (idBlock* block = blocks; block != nullptr; block = block->next) {
                const std::uintptr_t begin =
                    reinterpret_cast<std::uintptr_t>(&block->elements[0]);
                const std::uintptr_t end =
                    reinterpret_cast<std::uintptr_t>(&block->elements[blockSize]);
                if (address >= begin && address < end) {
                    element->next = block->free;
                    block->free = element;
                    ++block->freeCount;
                    break;
                }
            }
            element = next;
        }

        free = nullptr;
        idBlock** link = &blocks;
        while (*link != nullptr) {
            idBlock* const block = *link;
            if (block->freeCount == blockSize) {
                *link = block->next;
                total -= blockSize;
                block->~idBlock();
                _aligned_free(block);
                continue;
            }
            element_t* blockFree = block->free;
            while (blockFree != nullptr) {
                element_t* const next = blockFree->next;
                blockFree->next = free;
                free = blockFree;
                blockFree = next;
            }
            link = &block->next;
        }
    }

    T* Alloc() {
        if (free == nullptr && (!allowAllocs || !AllocNewBlock())) {
            return nullptr;
        }

        element_t* const element = free;
        free = element->next;
        ++active;
        if (clearAllocs) {
            std::memset(element->buffer, 0, sizeof(element->buffer));
        }
        return new (element->buffer) T();
    }

    void Free(T* value) {
        if (value == nullptr) {
            return;
        }
        value->~T();
        element_t* const element = reinterpret_cast<element_t*>(value);
        element->next = free;
        free = element;
        --active;
    }

    int GetTotalCount() const { return total; }
    int GetAllocCount() const { return active; }
    int GetFreeCount() const { return total - active; }

private:
    bool AllocNewBlock() {
        constexpr std::size_t alignment = alignof(T) > 16 ? alignof(T) : 16;
        void* const memory = _aligned_malloc(sizeof(idBlock), alignment);
        if (memory == nullptr) {
            return false;
        }

        idBlock* const block = new (memory) idBlock();
        block->next = blocks;
        blocks = block;
        for (int index = 0; index < blockSize; ++index) {
            block->elements[index].next = free;
            free = &block->elements[index];
        }
        total += blockSize;
        return true;
    }
};

template<class Object, class Key>
class idBTreeNode;

template<class Object, class Key, int maxChildren>
class idBTree;

// The recovered idDynamicBlock specializations all have this four-field,
// sixteen-byte Win32 layout. A negative size marks the first block in a base
// allocation; membership in the free tree marks whether a block is free.
template<class T, int memTag = 0>
class idDynamicBlock {
public:
    int size;
    idDynamicBlock* prev;
    idDynamicBlock* next;
    idBTreeNode<idDynamicBlock<T, memTag>, int>* node;

    T* GetMemory() {
        return reinterpret_cast<T*>(this + 1);
    }

    const T* GetMemory() const {
        return reinterpret_cast<const T*>(this + 1);
    }

    int GetSize() const {
        return size < 0 ? -size : size;
    }

    void SetSize(const int newSize, const bool isBaseBlock) {
        size = isBaseBlock ? -newSize : newSize;
    }

    bool IsBaseBlock() const {
        return size < 0;
    }
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idDynamicBlock<unsigned char, 0>) == 16,
    "Recovered idDynamicBlock ABI changed");
#endif
