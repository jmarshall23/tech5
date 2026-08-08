#pragma once

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <new>

template<class T>
class idRecoveredList {
public:
    explicit idRecoveredList(const int initialGranularity = 16)
        : list(nullptr), num(0), size(0),
          granularity(static_cast<std::int16_t>(initialGranularity)),
          memTag(0), listStatic(0) {
    }

    ~idRecoveredList() {
        Clear(true);
    }

    idRecoveredList(const idRecoveredList&) = delete;
    idRecoveredList& operator=(const idRecoveredList&) = delete;

    bool Reserve(const int capacity) {
        if (capacity <= size) return true;
        const int step = granularity > 0 ? granularity : 16;
        const int newSize = ((capacity + step - 1) / step) * step;
        T* const replacement = static_cast<T*>(
            std::malloc(sizeof(T) * static_cast<std::size_t>(newSize)));
        if (replacement == nullptr) return false;
        if (list != nullptr && num > 0) {
            std::memcpy(replacement, list,
                sizeof(T) * static_cast<std::size_t>(num));
        }
        std::free(list);
        list = replacement;
        size = newSize;
        return true;
    }

    T* Alloc() {
        if (!Reserve(num + 1)) return nullptr;
        T* const result = list + num++;
        std::memset(result, 0, sizeof(T));
        return result;
    }

    bool Append(const T& value) {
        T* const destination = Alloc();
        if (destination == nullptr) return false;
        *destination = value;
        return true;
    }

    void Clear(const bool freeMemory = false) {
        num = 0;
        if (freeMemory) {
            std::free(list);
            list = nullptr;
            size = 0;
        }
    }

    int Num() const { return num; }
    int Capacity() const { return size; }
    T* Ptr() { return list; }
    const T* Ptr() const { return list; }
    T& operator[](const int index) { return list[index]; }
    const T& operator[](const int index) const { return list[index]; }

private:
    T* list;
    int num;
    int size;
    std::int16_t granularity;
    std::uint8_t memTag;
    std::uint8_t listStatic;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idRecoveredList<int>) == 16,
    "Recovered list ABI changed");
#endif

