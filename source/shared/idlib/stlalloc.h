#pragma once

#include <cstddef>
#include <limits>
#include <new>
#include <utility>

// Layout recovered from tungsten.exe.h.  The allocator itself is stateless;
// the PC port uses the process allocator until idLib's heap routing is active.
struct testAlloc_t {
    void* ptr;
    int size;
    bool mapHeap;
};

template<typename type>
class idSTLAllocator {
public:
    using value_type = type;
    using pointer = type*;
    using const_pointer = const type*;
    using reference = type&;
    using const_reference = const type&;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    template<typename otherType>
    struct rebind {
        using other = idSTLAllocator<otherType>;
    };

    idSTLAllocator() noexcept = default;

    template<typename otherType>
    idSTLAllocator(const idSTLAllocator<otherType>&) noexcept {
    }

    pointer allocate(const size_type count, const void* = nullptr) {
        if (count > max_size()) {
            throw std::bad_alloc();
        }
        return static_cast<pointer>(::operator new(count * sizeof(type)));
    }

    void deallocate(pointer address, size_type) noexcept {
        ::operator delete(address);
    }

    template<typename objectType, typename... argsType>
    void construct(objectType* address, argsType&&... args) {
        ::new (static_cast<void*>(address)) objectType(
            std::forward<argsType>(args)...);
    }

    template<typename objectType>
    void destroy(objectType* address) {
        address->~objectType();
    }

    size_type max_size() const noexcept {
        return (std::numeric_limits<size_type>::max)() / sizeof(type);
    }
};

template<typename lhsType, typename rhsType>
inline bool operator==(const idSTLAllocator<lhsType>&,
    const idSTLAllocator<rhsType>&) noexcept {
    return true;
}

template<typename lhsType, typename rhsType>
inline bool operator!=(const idSTLAllocator<lhsType>&,
    const idSTLAllocator<rhsType>&) noexcept {
    return false;
}

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(testAlloc_t) == 12, "Recovered testAlloc_t ABI changed");
#endif

