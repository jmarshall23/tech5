#include "hashindex.h"

#include <cstdlib>

void idHashIndex::InternalInit(const int initialHashSize,
        const int initialIndexSize) {
    hash = nullptr;
    indexChain = nullptr;
    hashSize = (std::max)(initialHashSize, 1);
    indexSize = (std::max)(initialIndexSize, 1);
    granularity = 1024;
    hashMask = hashSize - 1;
    lookupMask = 0;
}

void idHashIndex::Free() {
    delete[] hash;
    delete[] indexChain;
    hash = nullptr;
    indexChain = nullptr;
    lookupMask = 0;
}

void idHashIndex::Allocate(int newHashSize, int newIndexSize) {
    delete[] hash;
    delete[] indexChain;
    hash = nullptr;
    indexChain = nullptr;
    newHashSize = NextPowerOfTwo((std::max)(newHashSize, 1));
    newIndexSize = (std::max)(newIndexSize, 1);
    hashSize = newHashSize;
    indexSize = newIndexSize;
    hashMask = hashSize - 1;
    lookupMask = 0;
    hash = new (std::nothrow) int[hashSize];
    indexChain = new (std::nothrow) int[indexSize];
    if (hash == nullptr || indexChain == nullptr) {
        delete[] hash;
        delete[] indexChain;
        hash = nullptr;
        indexChain = nullptr;
        return;
    }
    std::fill(hash, hash + hashSize, -1);
    std::fill(indexChain, indexChain + indexSize, -1);
    lookupMask = -1;
}

void idHashIndex::ResizeIndex(const int requestedIndexSize) {
    if (requestedIndexSize <= indexSize) return;
    const int step = granularity > 0 ? granularity : 1024;
    const int newIndexSize = ((requestedIndexSize + step - 1) / step) * step;
    if (indexChain == nullptr) {
        indexSize = newIndexSize;
        return;
    }
    int* const oldChain = indexChain;
    indexChain = new (std::nothrow) int[newIndexSize];
    if (indexChain == nullptr) {
        indexChain = oldChain;
        return;
    }
    std::copy(oldChain, oldChain + indexSize, indexChain);
    std::fill(indexChain + indexSize, indexChain + newIndexSize, -1);
    delete[] oldChain;
    indexSize = newIndexSize;
}

int idHashIndex::GetSpread() const {
    if (hash == nullptr || hashSize <= 0) return 100;
    int* counts = new (std::nothrow) int[hashSize];
    if (counts == nullptr) return 100;
    int total = 0;
    for (int bucket = 0; bucket < hashSize; ++bucket) {
        counts[bucket] = 0;
        for (int index = hash[bucket]; index >= 0;
                index = indexChain[index]) ++counts[bucket];
        total += counts[bucket];
    }
    if (total <= 1) {
        delete[] counts;
        return 100;
    }
    const int average = total / hashSize;
    int error = 0;
    for (int bucket = 0; bucket < hashSize; ++bucket) {
        const int difference = std::abs(counts[bucket] - average);
        if (difference > 1) error += difference - 1;
    }
    delete[] counts;
    return 100 - 100 * error / total;
}
