#pragma once

#include <cassert>
#include <cmath>

class idComplex {
public:
    float r;
    float i;

    idComplex() = default;
    idComplex(const float real, const float imaginary) : r(real), i(imaginary) {}

    void Set(const float real, const float imaginary) { r = real; i = imaginary; }
    void Zero() { r = 0.0f; i = 0.0f; }

    float operator[](const int index) const {
        assert(index >= 0 && index < 2);
        return (&r)[index];
    }
    float& operator[](const int index) {
        assert(index >= 0 && index < 2);
        return (&r)[index];
    }

    idComplex operator-() const { return idComplex(-r, -i); }
    idComplex operator+(const idComplex& other) const {
        return idComplex(r + other.r, i + other.i);
    }
    idComplex operator-(const idComplex& other) const {
        return idComplex(r - other.r, i - other.i);
    }
    idComplex operator*(const idComplex& other) const {
        return idComplex(r * other.r - i * other.i,
            i * other.r + r * other.i);
    }
    idComplex operator/(const idComplex& other) const {
        const float denominator = other.r * other.r + other.i * other.i;
        assert(denominator != 0.0f);
        return idComplex((r * other.r + i * other.i) / denominator,
            (i * other.r - r * other.i) / denominator);
    }
    idComplex operator*(const float scale) const { return idComplex(r * scale, i * scale); }
    idComplex operator/(const float scale) const {
        assert(scale != 0.0f);
        return idComplex(r / scale, i / scale);
    }
    idComplex operator+(const float value) const { return idComplex(r + value, i); }
    idComplex operator-(const float value) const { return idComplex(r - value, i); }

    idComplex& operator+=(const idComplex& other) { r += other.r; i += other.i; return *this; }
    idComplex& operator-=(const idComplex& other) { r -= other.r; i -= other.i; return *this; }
    idComplex& operator*=(const idComplex& other) { return *this = *this * other; }
    idComplex& operator/=(const idComplex& other) { return *this = *this / other; }
    idComplex& operator+=(const float value) { r += value; return *this; }
    idComplex& operator-=(const float value) { r -= value; return *this; }
    idComplex& operator*=(const float scale) { r *= scale; i *= scale; return *this; }
    idComplex& operator/=(const float scale) {
        assert(scale != 0.0f); r /= scale; i /= scale; return *this;
    }

    bool Compare(const idComplex& other) const { return r == other.r && i == other.i; }
    bool Compare(const idComplex& other, const float epsilon) const {
        return std::fabs(r - other.r) <= epsilon
            && std::fabs(i - other.i) <= epsilon;
    }
    bool operator==(const idComplex& other) const { return Compare(other); }
    bool operator!=(const idComplex& other) const { return !Compare(other); }

    idComplex Reciprocal() const {
        const float denominator = r * r + i * i;
        assert(denominator != 0.0f);
        return idComplex(r / denominator, -i / denominator);
    }
    idComplex Sqrt() const {
        const float magnitude = Abs();
        const float real = std::sqrt((magnitude + r) * 0.5f);
        const float imaginary = std::copysign(
            std::sqrt((magnitude - r) * 0.5f), i);
        return idComplex(real, imaginary);
    }
    float Abs() const { return std::sqrt(r * r + i * i); }
    int GetDimension() const { return 2; }
    const float* ToFloatPtr() const { return &r; }
    float* ToFloatPtr() { return &r; }
};

inline idComplex operator*(const float lhs, const idComplex& rhs) { return rhs * lhs; }
inline idComplex operator/(const float lhs, const idComplex& rhs) {
    return idComplex(lhs, 0.0f) / rhs;
}
inline idComplex operator+(const float lhs, const idComplex& rhs) { return rhs + lhs; }
inline idComplex operator-(const float lhs, const idComplex& rhs) {
    return idComplex(lhs - rhs.r, -rhs.i);
}

static_assert(sizeof(idComplex) == 8, "Recovered idComplex ABI changed");

