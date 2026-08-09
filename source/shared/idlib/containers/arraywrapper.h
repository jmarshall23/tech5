#pragma once

#include <cassert>

template<typename type>
class idArrayWrapper {
public:
    type* ptr;
    int numElements;

    idArrayWrapper()
        : ptr(nullptr)
        , numElements(0) {
    }

    idArrayWrapper(type* elements, const int count)
        : ptr(elements)
        , numElements(count) {
    }

    int Num() const {
        return numElements;
    }

    type* Ptr() { return ptr; }
    const type* Ptr() const { return ptr; }

    type& operator[](const int index) {
        assert(index >= 0 && index < numElements);
        return ptr[index];
    }

    const type& operator[](const int index) const {
        assert(index >= 0 && index < numElements);
        return ptr[index];
    }
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idArrayWrapper<float>) == 8,
    "Recovered idArrayWrapper ABI changed");
#endif

