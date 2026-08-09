#pragma once

// Recovered from tungsten.exe.h.  The tag type prevents unrelated handles
// with the same storage type from being mixed, while InvalidValue is part of
// the type and supplies the default/invalid representation.
template<typename valueType, typename invalidType, valueType InvalidValue>
class idHandle {
public:
    valueType value;

    idHandle()
        : value(InvalidValue) {
    }

    idHandle(const valueType initialValue)
        : value(initialValue) {
    }

    bool IsValid() const {
        return value != InvalidValue;
    }

    void Invalidate() {
        value = InvalidValue;
    }

    valueType Get() const {
        return value;
    }

    operator valueType() const {
        return value;
    }

    idHandle& operator=(const valueType newValue) {
        value = newValue;
        return *this;
    }

    bool operator==(const idHandle& other) const { return value == other.value; }
    bool operator!=(const idHandle& other) const { return value != other.value; }
    bool operator<(const idHandle& other) const { return value < other.value; }

    bool operator==(const valueType other) const { return value == other; }
    bool operator!=(const valueType other) const { return value != other; }
};

template<typename valueType, typename invalidType, valueType InvalidValue>
inline bool operator==(const valueType lhs,
    const idHandle<valueType, invalidType, InvalidValue>& rhs) {
    return rhs == lhs;
}

template<typename valueType, typename invalidType, valueType InvalidValue>
inline bool operator!=(const valueType lhs,
    const idHandle<valueType, invalidType, InvalidValue>& rhs) {
    return rhs != lhs;
}

// Exact two-word layout recovered as IDA local type 14180.
struct pvsHandle_t {
    int i;
    unsigned int h;
};

static_assert(sizeof(pvsHandle_t) == 8, "Recovered pvsHandle_t ABI changed");

