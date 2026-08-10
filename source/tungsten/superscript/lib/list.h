#pragma once

#include <algorithm>
#include <cassert>

// SuperScript list storage recovered from PDB type 13833 and the explicit
// int/string instantiations in superscript/lib/list.h. Capacity is always
// rounded to an eight-element boundary.
template<typename T>
class ssList {
public:
    ssList()
        : data(nullptr), num(0), size(0), threadId(0) {
    }

    ssList(const ssList& source)
        : data(nullptr), num(0), size(0), threadId(0) {
        Append(source);
    }

    ~ssList() {
        Clear();
    }

    void Clear() {
        delete[] data;
        data = nullptr;
        num = 0;
        size = 0;
    }

    int Num() const { return num; }

    T& Get(const int index) {
        assert(index >= 0 && index < num);
        return data[index];
    }

    const T& Get(const int index) const {
        assert(index >= 0 && index < num);
        return data[index];
    }

    T& operator[](const int index) { return Get(index); }
    const T& operator[](const int index) const { return Get(index); }

    int Find(const T& element) const {
        for (int index = 0; index < num; ++index) {
            if (data[index] == element) {
                return index;
            }
        }
        return -1;
    }

    void Reverse() {
        // Hex-Rays lost one side of this scalar swap in the int
        // instantiation; the named operation and loop bounds disambiguate it.
        for (int index = 0; index < num / 2; ++index) {
            using std::swap;
            swap(data[index], data[num - index - 1]);
        }
    }

    void Remove(const int index) {
        assert(index >= 0 && index < num);
        if (index < 0 || index >= num) {
            return;
        }
        for (int cursor = index; cursor < num - 1; ++cursor) {
            data[cursor] = data[cursor + 1];
        }
        --num;
    }

    void RemoveFast(const int index) {
        assert(index >= 0 && index < num);
        if (index < 0 || index >= num) {
            return;
        }
        if (index < num - 1) {
            data[index] = data[num - 1];
        }
        --num;
    }

    bool RemoveElement(const T& element) {
        const int index = Find(element);
        if (index < 0) {
            return false;
        }
        Remove(index);
        return true;
    }

    bool RemoveElementFast(const T& element) {
        const int index = Find(element);
        if (index < 0) {
            return false;
        }
        RemoveFast(index);
        return true;
    }

    int Insert(const T& element, int index) {
        if (num == size) {
            Resize(num + 1);
        }
        if (index < 0) {
            index = 0;
        } else if (index > num) {
            index = num;
        }
        for (int cursor = num; cursor > index; --cursor) {
            data[cursor] = data[cursor - 1];
        }
        ++num;
        data[index] = element;
        return index;
    }

    int Append(const T& element) {
        return Insert(element, num);
    }

    int Append(const ssList& source) {
        assert(this != &source);
        if (this == &source) {
            return -1;
        }
        Resize(num + source.num);
        int result = -1;
        for (int index = 0; index < source.num; ++index) {
            result = Insert(source.data[index], num);
        }
        return result;
    }

    int AppendUnique(const ssList& source) {
        int result = -1;
        for (int index = 0; index < source.num; ++index) {
            if (Find(source.data[index]) < 0) {
                result = Insert(source.data[index], num);
            } else {
                result = -1;
            }
        }
        return result;
    }

    T* data;
    int num;
    int size;
    int threadId;

private:
    void Resize(const int newSize) {
        if (newSize <= 0) {
            Clear();
            return;
        }
        const int retained = std::min(num, newSize);
        const int roundedSize = (newSize + 7) & ~7;
        T* const replacement = new T[roundedSize];
        for (int index = 0; index < retained; ++index) {
            replacement[index] = data[index];
        }
        delete[] data;
        data = replacement;
        num = retained;
        size = roundedSize;
    }
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(ssList<int>) == 16,
    "Recovered SuperScript list ABI changed");
#endif
