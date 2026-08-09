#pragma once

#include "blockalloc_base.h"
#include "containers/btree.h"

#include <algorithm>
#include <cstdlib>

// Variable-size allocator reconstructed from the recovered PDB layout and the
// Hex-Rays AllocInternal/ResizeInternal/FreeInternal/linking bodies.
template<class T, int baseBlockSize, int minBlockSize, int memTag = 0>
class idDynamicBlockAlloc {
public:
    using block_t = idDynamicBlock<T, memTag>;
    using tree_t = idBTree<block_t, int, 4>;

    block_t* firstBlock;
    block_t* lastBlock;
    tree_t freeTree;
    bool allowAllocs;
    bool clearAllocs;
    int numBaseBlocks;
    int baseBlockMemory;
    int numUsedBlocks;
    int usedBlockMemory;
    int numFreeBlocks;
    int freeBlockMemory;
    int numAllocs;
    int numResizes;
    int numFrees;

    idDynamicBlockAlloc() {
        Init();
    }

    ~idDynamicBlockAlloc() {
        Shutdown();
    }

    idDynamicBlockAlloc(const idDynamicBlockAlloc&) = delete;
    idDynamicBlockAlloc& operator=(const idDynamicBlockAlloc&) = delete;

    void Init() {
        firstBlock = nullptr;
        lastBlock = nullptr;
        freeTree.Init();
        allowAllocs = true;
        clearAllocs = false;
        numBaseBlocks = 0;
        baseBlockMemory = 0;
        numUsedBlocks = 0;
        usedBlockMemory = 0;
        numFreeBlocks = 0;
        freeBlockMemory = 0;
        numAllocs = 0;
        numResizes = 0;
        numFrees = 0;
    }

    void Shutdown() {
        for (block_t* block = firstBlock; block != nullptr; block = block->next) {
            if (block->node == nullptr) {
                FreeInternal(block);
            }
        }
        while (firstBlock != nullptr) {
            block_t* const block = firstBlock;
            firstBlock = block->next;
            _aligned_free(block);
        }
        freeTree.Shutdown();
        lastBlock = nullptr;
        allowAllocs = true;
        numBaseBlocks = 0;
        baseBlockMemory = 0;
        numUsedBlocks = 0;
        usedBlockMemory = 0;
        numFreeBlocks = 0;
        freeBlockMemory = 0;
        numAllocs = 0;
        numResizes = 0;
        numFrees = 0;
    }

    void SetFixedBlocks(const int numBlocks) {
        const int count = numBlocks > 0 ? numBlocks : 0;
        while (numBaseBlocks < count) {
            block_t* const block = AllocBaseBlock(baseBlockSize);
            if (block == nullptr) {
                break;
            }
            LinkFreeInternal(block);
        }
        allowAllocs = false;
    }

    void SetAllocAllowed(const bool allowed) { allowAllocs = allowed; }
    void SetClear(const bool clear) { clearAllocs = clear; }

    void FreeEmptyBaseBlocks() {
        block_t* block = firstBlock;
        while (block != nullptr) {
            block_t* const next = block->next;
            if (block->IsBaseBlock() && block->node != nullptr
                    && (next == nullptr || next->IsBaseBlock())) {
                UnlinkFreeInternal(block);
                if (block->prev != nullptr) block->prev->next = next;
                else firstBlock = next;
                if (next != nullptr) next->prev = block->prev;
                else lastBlock = block->prev;
                --numBaseBlocks;
                baseBlockMemory -= block->GetSize() + static_cast<int>(sizeof(block_t));
                _aligned_free(block);
            }
            block = next;
        }
    }

    T* Alloc(const int num) {
        ++numAllocs;
        if (num <= 0) return nullptr;
        block_t* block = AllocInternal(num);
        if (block == nullptr) return nullptr;
        block = ResizeInternal(block, num);
        if (block == nullptr) return nullptr;
        ++numUsedBlocks;
        usedBlockMemory += block->GetSize();
        if (clearAllocs) std::memset(block->GetMemory(), 0, num);
        return block->GetMemory();
    }

    T* Resize(T* ptr, const int num) {
        ++numResizes;
        if (ptr == nullptr) return Alloc(num);
        if (num <= 0) {
            Free(ptr);
            return nullptr;
        }
        block_t* const oldBlock = reinterpret_cast<block_t*>(ptr) - 1;
        const int oldSize = oldBlock->GetSize();
        block_t* const newBlock = ResizeInternal(oldBlock, num);
        if (newBlock == nullptr) return nullptr;
        usedBlockMemory += newBlock->GetSize() - oldSize;
        return newBlock->GetMemory();
    }

    void Free(T* ptr) {
        ++numFrees;
        if (ptr == nullptr) return;
        block_t* const block = reinterpret_cast<block_t*>(ptr) - 1;
        --numUsedBlocks;
        usedBlockMemory -= block->GetSize();
        FreeInternal(block);
    }

    const char* CheckMemory(const T* ptr) const {
        if (ptr == nullptr) return "null pointer";
        const block_t* const candidate = reinterpret_cast<const block_t*>(ptr) - 1;
        for (const block_t* block = firstBlock; block != nullptr; block = block->next) {
            if (block == candidate) return block->node == nullptr ? nullptr : "memory is free";
        }
        return "memory was not allocated by this allocator";
    }

    int GetNumBaseBlocks() const { return numBaseBlocks; }
    int GetBaseBlockMemory() const { return baseBlockMemory; }
    int GetNumUsedBlocks() const { return numUsedBlocks; }
    int GetUsedBlockMemory() const { return usedBlockMemory; }
    int GetNumFreeBlocks() const { return numFreeBlocks; }
    int GetFreeBlockMemory() const { return freeBlockMemory; }
    int GetNumEmptyBaseBlocks() const {
        int count = 0;
        for (block_t* block = firstBlock; block != nullptr; block = block->next) {
            if (block->IsBaseBlock() && block->node != nullptr
                    && (block->next == nullptr || block->next->IsBaseBlock())) {
                ++count;
            }
        }
        return count;
    }

private:
    static int AlignSize(const int num) {
        return ((num + minBlockSize - 1) / minBlockSize) * minBlockSize;
    }

    block_t* AllocBaseBlock(const int requestedPayload) {
        int bytes = std::max(requestedPayload + static_cast<int>(sizeof(block_t)),
            baseBlockSize);
        bytes = (bytes + 0xFFFF) & ~0xFFFF;
        block_t* const block = static_cast<block_t*>(_aligned_malloc(bytes, 16));
        if (block == nullptr) return nullptr;
        block->size = static_cast<int>(sizeof(block_t)) - bytes;
        block->prev = lastBlock;
        block->next = nullptr;
        block->node = nullptr;
        if (lastBlock != nullptr) lastBlock->next = block;
        else firstBlock = block;
        lastBlock = block;
        ++numBaseBlocks;
        baseBlockMemory += bytes;
        return block;
    }

    block_t* AllocInternal(const int num) {
        const int aligned = AlignSize(num);
        block_t* const reusable = freeTree.FindSmallestLargerEqual(aligned);
        if (reusable != nullptr) {
            UnlinkFreeInternal(reusable);
            return reusable;
        }
        if (!allowAllocs) return nullptr;
        return AllocBaseBlock(aligned);
    }

    block_t* ResizeInternal(block_t* block, const int num) {
        const int aligned = AlignSize(num);
        block_t* result = block;
        const int oldSize = block->GetSize();
        if (aligned > oldSize) {
            block_t* const next = block->next;
            if (next != nullptr && !next->IsBaseBlock() && next->node != nullptr
                    && oldSize + next->GetSize() + static_cast<int>(sizeof(block_t)) >= aligned) {
                UnlinkFreeInternal(next);
                const int combined = oldSize + next->GetSize()
                    + static_cast<int>(sizeof(block_t));
                block->size = block->IsBaseBlock() ? -combined : combined;
                block->next = next->next;
                if (block->next != nullptr) block->next->prev = block;
                else lastBlock = block;
            } else {
                result = AllocInternal(num);
                if (result == nullptr) return nullptr;
                result = ResizeInternal(result, num);
                if (result == nullptr) return nullptr;
                std::memcpy(result->GetMemory(), block->GetMemory(), oldSize);
                FreeInternal(block);
                return result;
            }
        }

        const int remainder = result->GetSize()
            - static_cast<int>(sizeof(block_t)) - aligned;
        if (remainder >= minBlockSize) {
            unsigned char* const splitAddress =
                reinterpret_cast<unsigned char*>(result->GetMemory()) + aligned;
            block_t* const split = reinterpret_cast<block_t*>(splitAddress);
            split->size = remainder;
            split->prev = result;
            split->next = result->next;
            split->node = nullptr;
            if (split->next != nullptr) split->next->prev = split;
            else lastBlock = split;
            const bool base = result->IsBaseBlock();
            result->next = split;
            result->size = base ? -aligned : aligned;
            FreeInternal(split);
        }
        return result;
    }

    void FreeInternal(block_t* block) {
        block_t* const next = block->next;
        if (next != nullptr && !next->IsBaseBlock() && next->node != nullptr) {
            UnlinkFreeInternal(next);
            const int combined = block->GetSize() + next->GetSize()
                + static_cast<int>(sizeof(block_t));
            block->size = block->IsBaseBlock() ? -combined : combined;
            block->next = next->next;
            if (block->next != nullptr) block->next->prev = block;
            else lastBlock = block;
        }

        block_t* const prev = block->prev;
        if (prev != nullptr && !block->IsBaseBlock() && prev->node != nullptr) {
            UnlinkFreeInternal(prev);
            const int combined = prev->GetSize() + block->GetSize()
                + static_cast<int>(sizeof(block_t));
            prev->size = prev->IsBaseBlock() ? -combined : combined;
            prev->next = block->next;
            if (prev->next != nullptr) prev->next->prev = prev;
            else lastBlock = prev;
            LinkFreeInternal(prev);
        } else {
            LinkFreeInternal(block);
        }
    }

    void LinkFreeInternal(block_t* block) {
        block->node = freeTree.Add(block, block->GetSize());
        ++numFreeBlocks;
        freeBlockMemory += block->GetSize();
    }

    void UnlinkFreeInternal(block_t* block) {
        freeTree.Remove(block->node);
        block->node = nullptr;
        --numFreeBlocks;
        freeBlockMemory -= block->GetSize();
    }
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idBlockAlloc<int, 4, 0>) == 20,
    "Recovered idBlockAlloc ABI changed");
static_assert(sizeof(idDynamicBlockAlloc<unsigned char, 1024, 16, 89>) == 72,
    "Recovered idDynamicBlockAlloc ABI changed");
#endif
