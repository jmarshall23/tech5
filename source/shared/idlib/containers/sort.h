#pragma once

#include <utility>

template<typename type>
inline void SwapValues(type& left, type& right) {
    using std::swap;
    swap(left, right);
}

template<typename type>
class idSort {
public:
    virtual ~idSort() = default;
    virtual void Sort(type* base, unsigned int num) = 0;
};

template<typename type>
class idSort_QuickDefault {
public:
    int Compare(const type& left, const type& right) const {
        return left < right ? -1 : (right < left ? 1 : 0);
    }
};

template<typename type, typename comparer = idSort_QuickDefault<type>>
class idSort_Quick : public idSort<type>, public comparer {
public:
    void Sort(type* base, const unsigned int num) override {
        if (base == nullptr || num < 2) return;
        QuickSort(base, 0, static_cast<int>(num) - 1);
    }

private:
    void QuickSort(type* base, int left, int right) {
        int i = left;
        int j = right;
        const type pivot = base[left + (right - left) / 2];
        while (i <= j) {
            while (this->Compare(base[i], pivot) < 0) ++i;
            while (this->Compare(base[j], pivot) > 0) --j;
            if (i <= j) {
                if (i != j) SwapValues(base[i], base[j]);
                ++i;
                --j;
            }
        }
        if (left < j) QuickSort(base, left, j);
        if (i < right) QuickSort(base, i, right);
    }
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idSort_Quick<int>) == 4, "Recovered idSort ABI changed");
#endif

