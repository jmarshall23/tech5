#pragma once

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>

class idSpatialVec {
public:
    idSpatialVec()
        : size(0), allocated(0), p(nullptr) {
    }

    explicit idSpatialVec(const int length)
        : idSpatialVec() {
        SetSize(length);
    }

    idSpatialVec(const idSpatialVec& other)
        : idSpatialVec() {
        SetSize(other.size);
        if (p != nullptr && other.p != nullptr) {
            std::memcpy(p, other.p, sizeof(float) * other.size);
        }
    }

    idSpatialVec(idSpatialVec&& other) noexcept
        : size(other.size), allocated(other.allocated), p(other.p) {
        other.size = 0;
        other.allocated = 0;
        other.p = nullptr;
    }

    ~idSpatialVec() {
        if (allocated > 0) {
            std::free(p);
        }
    }

    idSpatialVec& operator=(const idSpatialVec& other) {
        if (this != &other) {
            SetSize(other.size);
            if (p != nullptr && other.p != nullptr) {
                std::memcpy(p, other.p, sizeof(float) * other.size);
            }
        }
        return *this;
    }

    idSpatialVec& operator=(idSpatialVec&& other) noexcept {
        if (this != &other) {
            if (allocated > 0) {
                std::free(p);
            }
            size = other.size;
            allocated = other.allocated;
            p = other.p;
            other.size = 0;
            other.allocated = 0;
            other.p = nullptr;
        }
        return *this;
    }

    void SetData(const int length, float* data) {
        if (allocated > 0) {
            std::free(p);
        }
        p = data;
        size = static_cast<std::int16_t>(std::max(0, length));
        allocated = static_cast<std::int16_t>(-std::max(8, length));
        if (p != nullptr) {
            for (int index = size; index < -allocated; ++index) {
                p[index] = 0.0f;
            }
        }
    }

    bool SetSize(const int newSize) {
        if (newSize < 0 || newSize > 32767) {
            return false;
        }
        const int capacity = allocated < 0 ? -allocated : allocated;
        if (p == nullptr || newSize > capacity) {
            const int newCapacity = std::max(8, (newSize + 7) & ~7);
            float* const replacement = static_cast<float*>(
                std::calloc(static_cast<std::size_t>(newCapacity), sizeof(float))
            );
            if (replacement == nullptr) {
                return false;
            }
            if (p != nullptr) {
                std::memcpy(replacement, p,
                    sizeof(float) * static_cast<std::size_t>(std::min<int>(size, newSize)));
            }
            if (allocated > 0) {
                std::free(p);
            }
            p = replacement;
            allocated = static_cast<std::int16_t>(newCapacity);
        } else if (newSize > size) {
            std::memset(p + size, 0,
                sizeof(float) * static_cast<std::size_t>(newSize - size));
        }
        size = static_cast<std::int16_t>(newSize);
        return true;
    }

    void ChangeSize(const int newSize) {
        SetSize(newSize);
    }

    void Zero() {
        if (p != nullptr) {
            std::memset(p, 0, sizeof(float) * static_cast<std::size_t>(size));
        }
    }

    void Clamp(const float minimum, const float maximum) {
        for (int index = 0; index < size; ++index) {
            p[index] = std::max(minimum, std::min(maximum, p[index]));
        }
    }

    float LengthSqr() const {
        float sum = 0.0f;
        for (int index = 0; index < size; ++index) {
            sum += p[index] * p[index];
        }
        return sum;
    }

    float Length() const {
        return std::sqrt(LengthSqr());
    }

    int GetSize() const { return size; }
    float* ToFloatPtr() { return p; }
    const float* ToFloatPtr() const { return p; }

    float& operator[](const int index) { return p[index]; }
    float operator[](const int index) const { return p[index]; }

private:
    std::int16_t size;
    std::int16_t allocated;
    float* p;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idSpatialVec) == 8, "Recovered idSpatialVec ABI changed");
#endif
