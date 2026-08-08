#include "atomicstring.h"

#include <algorithm>
#include <cstdlib>
#include <cstring>

struct idAtomicStringManager::Entry {
    Entry* next;
    char text[1];
};

idAtomicStringManager atomicStringManager;

idAtomicStringManager::idAtomicStringManager()
    : hashTable{}, hashTableAtMarkStatic{}, blocks(nullptr),
      blocksAtMarkStatic(nullptr), usedBytesAtMarkStatic(0) {
}

const char* idAtomicStringManager::MakeAtomic(const char* source) {
    if (source == nullptr || source[0] == '\0') {
        return "";
    }

    unsigned int hash = 0;
    for (const unsigned char* cursor =
            reinterpret_cast<const unsigned char*>(source);
        *cursor != 0; ++cursor) {
        hash = 31u * hash + *cursor;
    }
    Entry*& bucket = hashTable[hash & 0xFFFFu];
    for (Entry* entry = bucket; entry != nullptr; entry = entry->next) {
        if (std::strcmp(entry->text, source) == 0) {
            return entry->text;
        }
    }

    const std::size_t textBytes = std::strlen(source) + 1;
    const std::size_t entryBytes = (sizeof(Entry*) + textBytes + 3u) & ~3u;
    if (blocks == nullptr
        || entryBytes > static_cast<std::size_t>(blocks->bufferBytes - blocks->usedBytes)) {
        const std::size_t totalBytes = std::max<std::size_t>(
            65536u, sizeof(atomicStringBlock_t) + entryBytes
        );
        atomicStringBlock_t* const block = static_cast<atomicStringBlock_t*>(
            std::malloc(totalBytes)
        );
        if (block == nullptr) {
            return "";
        }
        block->nextBlock = blocks;
        block->bufferBytes = static_cast<int>(totalBytes - sizeof(*block));
        block->usedBytes = 0;
        blocks = block;
    }

    unsigned char* const storage = reinterpret_cast<unsigned char*>(blocks + 1)
        + blocks->usedBytes;
    blocks->usedBytes += static_cast<int>(entryBytes);
    Entry* const entry = reinterpret_cast<Entry*>(storage);
    entry->next = bucket;
    std::memcpy(entry->text, source, textBytes);
    bucket = entry;
    return entry->text;
}

void idAtomicStringManager::MarkStatic() {
    std::memcpy(hashTableAtMarkStatic, hashTable, sizeof(hashTable));
    blocksAtMarkStatic = blocks;
    usedBytesAtMarkStatic = blocks == nullptr ? 0 : blocks->usedBytes;
}

void idAtomicStringManager::FreeDynamic() {
    std::memcpy(hashTable, hashTableAtMarkStatic, sizeof(hashTable));
    while (blocks != nullptr && blocks != blocksAtMarkStatic) {
        atomicStringBlock_t* const next = blocks->nextBlock;
        std::free(blocks);
        blocks = next;
    }
    if (blocks != nullptr) {
        blocks->usedBytes = usedBytesAtMarkStatic;
    }
}

idAtomicString::idAtomicString()
    : str("") {
}

idAtomicString::idAtomicString(const char* text)
    : str(atomicStringManager.MakeAtomic(text)) {
}

void idAtomicString::Set(const char* text) {
    str = atomicStringManager.MakeAtomic(text);
}

bool idAtomicString::operator==(const char* text) const {
    return std::strcmp(str, text == nullptr ? "" : text) == 0;
}

void idAtomicString::MarkStatic() {
    atomicStringManager.MarkStatic();
}

void idAtomicString::FreeDynamic() {
    atomicStringManager.FreeDynamic();
}
