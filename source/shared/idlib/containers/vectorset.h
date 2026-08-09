#pragma once

#include "hashindex.h"
#include "list.h"
#include "../math/vector.h"

#include <cassert>
#include <cmath>
#include <cstddef>

template<class T, int dimension>
class idVectorSubset {
public:
    idHashIndex hash;
    T mins;
    T maxs;
    int boxHashSize;
    float boxInvSize[dimension];
    float boxHalfSize[dimension];

    idVectorSubset() : hash(0, 0, TAG_HASHINDEX), boxHashSize(16) {
        hash.Allocate(IntegerPower(boxHashSize, dimension), 128);
        for (int index = 0; index < dimension; ++index) {
            boxInvSize[index] = 0.0f;
            boxHalfSize[index] = 0.0f;
        }
    }

    idVectorSubset(const T& boundsMins, const T& boundsMaxs,
            const int hashSize, const int initialSize)
        : hash(0, 0, TAG_HASHINDEX), boxHashSize(16) {
        Init(boundsMins, boundsMaxs, hashSize, initialSize);
    }

    std::size_t Allocated() const { return hash.Allocated(); }
    std::size_t Size() const { return sizeof(*this) + Allocated(); }

    void Init(const T& boundsMins, const T& boundsMaxs,
            const int newBoxHashSize, const int initialSize) {
        boxHashSize = newBoxHashSize > 0 ? newBoxHashSize : 1;
        hash.Allocate(IntegerPower(boxHashSize, dimension),
            initialSize > 0 ? initialSize : 1);
        mins = boundsMins;
        maxs = boundsMaxs;
        for (int index = 0; index < dimension; ++index) {
            const float boxSize = (maxs[index] - mins[index])
                / static_cast<float>(boxHashSize);
            boxInvSize[index] = boxSize != 0.0f ? 1.0f / boxSize : 0.0f;
            boxHalfSize[index] = boxSize * 0.5f;
        }
    }

    void Clear() { hash.Clear(); }

    int FindVector(const T* vectorList, const int vectorNum,
            const float epsilon) {
        const T& vector = vectorList[vectorNum];
        int partialHashKey[dimension];
        for (int component = 0; component < dimension; ++component) {
            assert(epsilon <= boxHalfSize[component]);
            partialHashKey[component] = static_cast<int>(
                (vector[component] - mins[component] - boxHalfSize[component])
                * boxInvSize[component]);
        }

        for (int corner = 0; corner < (1 << dimension); ++corner) {
            int hashKey = 0;
            for (int component = 0; component < dimension; ++component) {
                hashKey *= boxHashSize;
                hashKey += partialHashKey[component] + ((corner >> component) & 1);
            }
            for (int candidate = hash.First(hashKey); candidate >= 0;
                    candidate = hash.Next(candidate)) {
                int component = 0;
                for (; component < dimension; ++component) {
                    if (std::fabs(vectorList[candidate][component]
                            - vector[component]) > epsilon) break;
                }
                if (component == dimension) return candidate;
            }
        }

        hash.Add(HashKey(vector), vectorNum);
        return vectorNum;
    }

private:
    static int IntegerPower(const int base, const int exponent) {
        int result = 1;
        for (int index = 0; index < exponent; ++index) result *= base;
        return result;
    }

    int HashKey(const T& vector) const {
        int key = 0;
        for (int component = 0; component < dimension; ++component) {
            key *= boxHashSize;
            key += static_cast<int>((vector[component] - mins[component])
                * boxInvSize[component]);
        }
        return key;
    }
};

template<class T, int dimension>
class idVectorSet : public idList<T, 44> {
public:
    idHashIndex hash;
    T mins;
    T maxs;
    int boxHashSize;
    float boxInvSize[dimension];
    float boxHalfSize[dimension];

    idVectorSet() : idList<T, 44>(), hash(0, 0, TAG_HASHINDEX), boxHashSize(16) {
        hash.Allocate(IntegerPower(boxHashSize, dimension), 128);
        for (int index = 0; index < dimension; ++index) {
            boxInvSize[index] = 0.0f;
            boxHalfSize[index] = 0.0f;
        }
    }

    idVectorSet(const T& boundsMins, const T& boundsMaxs,
            const int hashSize, const int initialSize)
        : idVectorSet() {
        Init(boundsMins, boundsMaxs, hashSize, initialSize);
    }

    std::size_t Allocated() const {
        return static_cast<std::size_t>(this->MemoryUsed()) + hash.Allocated();
    }
    std::size_t Size() const { return sizeof(*this) + Allocated(); }

    void Init(const T& boundsMins, const T& boundsMaxs,
            const int newBoxHashSize, const int initialSize) {
        this->ClearFree();
        this->PreAllocate(initialSize);
        boxHashSize = newBoxHashSize > 0 ? newBoxHashSize : 1;
        hash.Allocate(IntegerPower(boxHashSize, dimension),
            initialSize > 0 ? initialSize : 1);
        mins = boundsMins;
        maxs = boundsMaxs;
        for (int index = 0; index < dimension; ++index) {
            const float boxSize = (maxs[index] - mins[index])
                / static_cast<float>(boxHashSize);
            boxInvSize[index] = boxSize != 0.0f ? 1.0f / boxSize : 0.0f;
            boxHalfSize[index] = boxSize * 0.5f;
        }
    }

    void ResizeIndex(const int newSize) {
        this->Resize(newSize);
        hash.ResizeIndex(newSize);
    }

    void Clear() {
        idList<T, 44>::Clear();
        hash.Clear();
    }

    int FindVector(const T& vector, const float epsilon) {
        int partialHashKey[dimension];
        for (int component = 0; component < dimension; ++component) {
            assert(epsilon <= boxHalfSize[component]);
            partialHashKey[component] = static_cast<int>(
                (vector[component] - mins[component] - boxHalfSize[component])
                * boxInvSize[component]);
        }
        for (int corner = 0; corner < (1 << dimension); ++corner) {
            int hashKey = 0;
            for (int component = 0; component < dimension; ++component) {
                hashKey *= boxHashSize;
                hashKey += partialHashKey[component] + ((corner >> component) & 1);
            }
            for (int candidate = hash.First(hashKey); candidate >= 0;
                    candidate = hash.Next(candidate)) {
                int component = 0;
                for (; component < dimension; ++component) {
                    if (std::fabs((*this)[candidate][component]
                            - vector[component]) > epsilon) break;
                }
                if (component == dimension) return candidate;
            }
        }
        const int index = this->Num();
        hash.Add(HashKey(vector), index);
        this->Append(vector);
        return index;
    }

private:
    static int IntegerPower(const int base, const int exponent) {
        int result = 1;
        for (int index = 0; index < exponent; ++index) result *= base;
        return result;
    }

    int HashKey(const T& vector) const {
        int key = 0;
        for (int component = 0; component < dimension; ++component) {
            key *= boxHashSize;
            key += static_cast<int>((vector[component] - mins[component])
                * boxInvSize[component]);
        }
        return key;
    }
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idVectorSubset<idVec3, 3>) == 84,
    "Recovered idVectorSubset<idVec3,3> ABI changed");
static_assert(sizeof(idVectorSubset<idVec2, 2>) == 68,
    "Recovered idVectorSubset<idVec2,2> ABI changed");
static_assert(sizeof(idVectorSet<idVec3, 3>) == 100,
    "Recovered idVectorSet<idVec3,3> ABI changed");
#endif
