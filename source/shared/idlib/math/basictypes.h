#pragma once

#include <cstdint>

class idBoundedIntBase {
public:
    virtual ~idBoundedIntBase() = default;
    virtual void SetValue(int value) = 0;
    virtual int GetValue() const = 0;
};

template<int MIN_VALUE, int MAX_VALUE>
class idBoundedInt final : public idBoundedIntBase {
public:
    explicit idBoundedInt(const int initialValue = MIN_VALUE)
        : value(MIN_VALUE) {
        SetValue(initialValue);
    }

    void SetValue(const int newValue) override {
        value = newValue < MIN_VALUE ? MIN_VALUE
            : (newValue > MAX_VALUE ? MAX_VALUE : newValue);
    }

    int GetValue() const override {
        return value;
    }

    operator int() const {
        return value;
    }

private:
    int value;
};

class idBoundedFloatBase {
public:
    virtual ~idBoundedFloatBase() = default;
    virtual void SetValue(float value) = 0;
    virtual float GetValue() const = 0;
};

// The original uses four integral template arguments so floating-point bounds
// remain legal in the C++03-era source. Only <0,0,1,0> occurs in tungsten;
// the second and fourth arguments represent the fractional decimal component.
template<int MIN_WHOLE, int MIN_FRACTION, int MAX_WHOLE, int MAX_FRACTION>
class idBoundedFloat final : public idBoundedFloatBase {
public:
    explicit idBoundedFloat(const float initialValue = Minimum())
        : value(Minimum()) {
        SetValue(initialValue);
    }

    void SetValue(const float newValue) override {
        value = newValue < Minimum() ? Minimum()
            : (newValue > Maximum() ? Maximum() : newValue);
    }

    float GetValue() const override {
        return value;
    }

    operator float() const {
        return value;
    }

private:
    float value;

    static constexpr float Fraction(const int digits) {
        return static_cast<float>(digits) / 1000.0f;
    }

    static constexpr float Minimum() {
        return static_cast<float>(MIN_WHOLE) + Fraction(MIN_FRACTION);
    }

    static constexpr float Maximum() {
        return static_cast<float>(MAX_WHOLE) + Fraction(MAX_FRACTION);
    }
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idBoundedInt<0, 4>) == 8,
    "Recovered idBoundedInt ABI changed");
static_assert(sizeof(idBoundedFloat<0, 0, 1, 0>) == 8,
    "Recovered idBoundedFloat ABI changed");
#endif
