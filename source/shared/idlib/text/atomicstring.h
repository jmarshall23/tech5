#pragma once

#include <cstdint>

struct atomicStringBlock_t {
    atomicStringBlock_t* nextBlock;
    int bufferBytes;
    int usedBytes;
};

class idAtomicStringManager {
public:
    idAtomicStringManager();

    const char* MakeAtomic(const char* text);
    void MarkStatic();
    void FreeDynamic();

private:
    struct Entry;
    Entry* hashTable[65536];
    Entry* hashTableAtMarkStatic[65536];
    atomicStringBlock_t* blocks;
    atomicStringBlock_t* blocksAtMarkStatic;
    int usedBytesAtMarkStatic;

    friend class idAtomicString;
};

class idAtomicString {
public:
    idAtomicString();
    explicit idAtomicString(const char* text);

    void Set(const char* text);
    const char* c_str() const { return str; }
    bool IsEmpty() const { return str[0] == '\0'; }

    bool operator==(const idAtomicString& other) const { return str == other.str; }
    bool operator!=(const idAtomicString& other) const { return str != other.str; }
    bool operator==(const char* text) const;

    static void MarkStatic();
    static void FreeDynamic();

private:
    const char* str;
};

extern idAtomicStringManager atomicStringManager;

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(atomicStringBlock_t) == 12,
    "Recovered atomicStringBlock_t ABI changed");
static_assert(sizeof(idAtomicString) == 4,
    "Recovered idAtomicString ABI changed");
#endif
