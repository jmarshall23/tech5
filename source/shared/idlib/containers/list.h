#pragma once

#include <algorithm>
#include <cstdint>
#include <new>
#include <utility>

// Reconstructed from the common layout shared by all 2,438 recovered PDB
// instantiations and the template bodies in the Hex-Rays list.h dump.
template<typename type, int memoryTag = 5>
class idList {
public:
    type* list;
    int num;
    int size;
    std::int16_t granularity;
    std::uint8_t memTag;
    std::uint8_t listStatic;

    explicit idList(const int initialGranularity = 16)
        : list(nullptr), num(0), size(0),
          granularity(static_cast<std::int16_t>(initialGranularity)),
          memTag(static_cast<std::uint8_t>(memoryTag)), listStatic(0) {}

    idList(const idList& other) : idList(other.granularity) { *this = other; }

    ~idList() {
        if (listStatic == 0) delete[] list;
    }

    idList& operator=(const idList& other) {
        if (this != &other && SetNum(other.num)) {
            for (int index = 0; index < num; ++index) list[index] = other.list[index];
        }
        return *this;
    }

    int Num() const { return num; }
    int NumAllocated() const { return size; }
    int MemoryUsed() const { return size * static_cast<int>(sizeof(type)); }
    bool IsEmpty() const { return num == 0; }
    type* Ptr() { return list; }
    const type* Ptr() const { return list; }

    type& operator[](const int index) { return list[index]; }
    const type& operator[](const int index) const { return list[index]; }

    void SetGranularity(const int newGranularity) {
        granularity = static_cast<std::int16_t>(newGranularity > 0 ? newGranularity : 16);
    }

    bool Resize(const int newSize) {
        if (newSize < 0 || (listStatic != 0 && newSize > size)) return false;
        if (newSize == size) return true;
        type* replacement = new (std::nothrow) type[newSize];
        if (replacement == nullptr && newSize != 0) return false;
        const int copyCount = (std::min)(num, newSize);
        for (int index = 0; index < copyCount; ++index)
            replacement[index] = std::move(list[index]);
        if (listStatic == 0) delete[] list;
        list = replacement;
        size = newSize;
        num = copyCount;
        listStatic = 0;
        return true;
    }

    bool PreAllocate(const int requestedSize) {
        if (requestedSize <= size) return true;
        return Resize(RoundedCapacity(requestedSize));
    }

    bool SetNum(const int newNum) {
        if (newNum < 0) return false;
        if (newNum > size && !PreAllocate(newNum)) return false;
        num = newNum;
        return true;
    }

    type* Alloc() {
        if (!SetNum(num + 1)) return nullptr;
        return &list[num - 1];
    }

    int Append(const type& object) {
        if (!SetNum(num + 1)) return -1;
        list[num - 1] = object;
        return num - 1;
    }

    int Append(type&& object) {
        if (!SetNum(num + 1)) return -1;
        list[num - 1] = std::move(object);
        return num - 1;
    }

    int AddUnique(const type& object) {
        const int found = FindIndex(object);
        return found >= 0 ? found : Append(object);
    }

    int Insert(const type& object, int index = 0) {
        if (index < 0) index = 0;
        if (index > num) index = num;
        if (!SetNum(num + 1)) return -1;
        for (int move = num - 1; move > index; --move)
            list[move] = std::move(list[move - 1]);
        list[index] = object;
        return index;
    }

    int FindIndex(const type& object) const {
        for (int index = 0; index < num; ++index)
            if (list[index] == object) return index;
        return -1;
    }

    type* Find(const type& object) {
        const int index = FindIndex(object);
        return index >= 0 ? &list[index] : nullptr;
    }

    const type* Find(const type& object) const {
        const int index = FindIndex(object);
        return index >= 0 ? &list[index] : nullptr;
    }

    bool RemoveIndex(const int index) {
        if (index < 0 || index >= num) return false;
        for (int move = index; move + 1 < num; ++move)
            list[move] = std::move(list[move + 1]);
        --num;
        return true;
    }

    bool RemoveIndexFast(const int index) {
        if (index < 0 || index >= num) return false;
        if (index != num - 1) list[index] = std::move(list[num - 1]);
        --num;
        return true;
    }

    bool Remove(const type& object) { return RemoveIndex(FindIndex(object)); }

    void Clear() { num = 0; }

    void ClearFree() {
        num = 0;
        if (listStatic == 0) {
            delete[] list;
            list = nullptr;
            size = 0;
        }
    }

    void Swap(idList& other) {
        using std::swap;
        swap(list, other.list); swap(num, other.num); swap(size, other.size);
        swap(granularity, other.granularity); swap(memTag, other.memTag);
        swap(listStatic, other.listStatic);
    }

protected:
    void SetStaticBuffer(type* buffer, const int capacity) {
        if (listStatic == 0) delete[] list;
        list = buffer;
        num = 0;
        size = capacity;
        granularity = 0;
        listStatic = 1;
    }

private:
    int RoundedCapacity(const int requestedSize) const {
        const int step = granularity > 0 ? granularity : 16;
        return ((requestedSize + step - 1) / step) * step;
    }
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idList<int, 5>) == 16, "Recovered idList ABI changed");
#endif

