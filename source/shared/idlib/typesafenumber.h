#pragma once

// Recovered one-field strongly-typed number used for angles and time units.
// The empty uniqueType parameter carries the unit without adding storage.
template<typename valueType, typename uniqueType>
class idTypesafeNumber {
public:
    valueType value;

    idTypesafeNumber() = default;

    idTypesafeNumber(const valueType initialValue)
        : value(initialValue) {
    }

    valueType Get() const {
        return value;
    }

    operator valueType() const {
        return value;
    }

    idTypesafeNumber& operator=(const valueType newValue) {
        value = newValue;
        return *this;
    }

    idTypesafeNumber& operator+=(const idTypesafeNumber& other) {
        value += other.value;
        return *this;
    }

    idTypesafeNumber& operator-=(const idTypesafeNumber& other) {
        value -= other.value;
        return *this;
    }

    bool operator==(const idTypesafeNumber& other) const { return value == other.value; }
    bool operator!=(const idTypesafeNumber& other) const { return value != other.value; }
    bool operator<(const idTypesafeNumber& other) const { return value < other.value; }
    bool operator<=(const idTypesafeNumber& other) const { return value <= other.value; }
    bool operator>(const idTypesafeNumber& other) const { return value > other.value; }
    bool operator>=(const idTypesafeNumber& other) const { return value >= other.value; }
};

template<typename valueType, typename uniqueType>
inline idTypesafeNumber<valueType, uniqueType> operator+(
    idTypesafeNumber<valueType, uniqueType> lhs,
    const idTypesafeNumber<valueType, uniqueType>& rhs) {
    lhs += rhs;
    return lhs;
}

template<typename valueType, typename uniqueType>
inline idTypesafeNumber<valueType, uniqueType> operator-(
    idTypesafeNumber<valueType, uniqueType> lhs,
    const idTypesafeNumber<valueType, uniqueType>& rhs) {
    lhs -= rhs;
    return lhs;
}

