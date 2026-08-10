#pragma once

#include <cstdint>
#include <cstring>

template<typename type, int handleBits>
class idHandleArray {
public:
    static_assert(handleBits > 0 && handleBits < 32,
        "idHandleArray requires index bits inside a 32-bit handle");

    idHandleArray()
        : data(new type[1u << handleBits])
        , handles(new std::uint32_t[1u << handleBits])
        , maxHandles(1u << handleBits)
        , counter(0) {
        // The retail specialization ran element construction and then cleared
        // both allocations byte-for-byte. Its only recovered element is POD.
        std::memset(data, 0, sizeof(type) * maxHandles);
        std::memset(handles, 0, sizeof(std::uint32_t) * maxHandles);
    }

    ~idHandleArray() {
        delete[] handles;
        delete[] data;
    }

    idHandleArray(const idHandleArray&) = delete;
    idHandleArray& operator=(const idHandleArray&) = delete;

    std::uint32_t Add(const type& element) {
        std::uint32_t index = 0;
        while (index < maxHandles && handles[index] != 0) {
            ++index;
        }
        if (index == maxHandles) {
            return 0;
        }

        data[index] = element;
        const std::uint32_t handle =
            (index << (32 - handleBits)) + ++counter;
        handles[index] = handle;
        return handle;
    }

    type* Get(const std::uint32_t handle) {
        if (handle == 0) {
            return nullptr;
        }
        const std::uint32_t index = handle >> (32 - handleBits);
        return index < maxHandles && handles[index] == handle
            ? &data[index]
            : nullptr;
    }

    const type* Get(const std::uint32_t handle) const {
        return const_cast<idHandleArray*>(this)->Get(handle);
    }

    bool Remove(const std::uint32_t handle) {
        if (Get(handle) == nullptr) {
            return false;
        }
        handles[handle >> (32 - handleBits)] = 0;
        return true;
    }

    type* data;
    std::uint32_t* handles;
    std::uint32_t maxHandles;
    std::uint32_t counter;
};

#if defined(_WIN32) && !defined(_WIN64)
struct idHandleArrayLayoutProbe {
    int value;
};
static_assert(sizeof(idHandleArray<idHandleArrayLayoutProbe, 2>) == 16,
    "Recovered handle-array ABI changed");
#endif
