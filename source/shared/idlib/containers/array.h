#pragma once

#include <cassert>

// All 82 recovered instantiations are exactly a fixed C array named ptr.
template<typename type, int count>
class idArray {
public:
    static_assert(count > 0, "idArray requires a positive element count");
    type ptr[count];

    constexpr int Num() const { return count; }
    type* Ptr() { return ptr; }
    const type* Ptr() const { return ptr; }
    type& operator[](const int index) {
        assert(index >= 0 && index < count); return ptr[index];
    }
    const type& operator[](const int index) const {
        assert(index >= 0 && index < count); return ptr[index];
    }
    type* begin() { return ptr; }
    const type* begin() const { return ptr; }
    type* end() { return ptr + count; }
    const type* end() const { return ptr + count; }
};

static_assert(sizeof(idArray<int, 4>) == sizeof(int) * 4,
    "Recovered idArray ABI changed");

