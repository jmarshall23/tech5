#pragma once

#include "../../../shared/idlib/math/vector.h"

template<typename type, int capacity>
class idCircularBuffer {
public:
    static_assert(capacity > 0, "idCircularBuffer requires storage");

    idCircularBuffer()
        : buffer{}
        , num(0)
        , head(0) {
    }

    int Add(const type& object) {
        const int index = (num + head) % capacity;
        buffer[index] = object;
        ++num;
        if (num >= capacity) {
            num = capacity;
            head = (head + 1) % capacity;
        }
        return index;
    }

    type buffer[capacity];
    int num;
    int head;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idCircularBuffer<idVec3, 5>) == 68,
    "Recovered five-vector circular-buffer ABI changed");
#endif

// The unrelated engine-owned allocation helper shared this PDB header.
class CircularBuffer {
public:
    unsigned int size;
    void** buffer;
    void* unalignedPointer;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(CircularBuffer) == 12,
    "Recovered allocation circular-buffer ABI changed");
#endif
