#pragma once

template<typename type>
class idSearch {
public:
    virtual ~idSearch() = default;
    virtual int Search(const type* base, unsigned int num,
        const type& value) const = 0;
    virtual int Search_FirstGreater(const type* base, int num,
        const type& value) const = 0;
    virtual int Search_FirstGreaterEqual(const type* base, int num,
        const type& value) const = 0;
    virtual int Search_LastLess(const type* base, int num,
        const type& value) const = 0;
    virtual int Search_LastLessEqual(const type* base, int num,
        const type& value) const = 0;
};

template<typename type, typename derived>
class idSearch_Binary : public idSearch<type> {
public:
    int Search(const type* base, const unsigned int num,
        const type& value) const override {
        if (base == nullptr || num == 0) {
            return -1;
        }
        const int index = Search_LastLessEqual(base, static_cast<int>(num), value);
        return Compare(base[index], value) == 0 ? index : -1;
    }

    int Search_FirstGreater(const type* base, const int num,
        const type& value) const override {
        int first = 0;
        int count = num < 0 ? 0 : num;
        while (count > 0) {
            const int step = count / 2;
            const int middle = first + step;
            if (Compare(base[middle], value) <= 0) {
                first = middle + 1;
                count -= step + 1;
            } else {
                count = step;
            }
        }
        return first;
    }

    int Search_FirstGreaterEqual(const type* base, const int num,
        const type& value) const override {
        int first = 0;
        int count = num < 0 ? 0 : num;
        while (count > 0) {
            const int step = count / 2;
            const int middle = first + step;
            if (Compare(base[middle], value) < 0) {
                first = middle + 1;
                count -= step + 1;
            } else {
                count = step;
            }
        }
        return first;
    }

    int Search_LastLess(const type* base, const int num,
        const type& value) const override {
        const int result = Search_FirstGreaterEqual(base, num, value) - 1;
        return result < 0 ? 0 : result;
    }

    int Search_LastLessEqual(const type* base, const int num,
        const type& value) const override {
        const int result = Search_FirstGreater(base, num, value) - 1;
        return result < 0 ? 0 : result;
    }

private:
    int Compare(const type& left, const type& right) const {
        return static_cast<const derived*>(this)->Compare(left, right);
    }
};

template<typename type>
class idSearch_BinaryDefault
    : public idSearch_Binary<type, idSearch_BinaryDefault<type>> {
public:
    int Compare(const type& left, const type& right) const {
        if (left < right) {
            return -1;
        }
        if (right < left) {
            return 1;
        }
        return 0;
    }
};

template<typename type>
using idSearch_DefaultCompare = idSearch_BinaryDefault<type>;
