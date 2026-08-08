#pragma once

#include <type_traits>

template<typename valueType, typename invalidType>
class idIndex {
public:
    idIndex()
        : value(static_cast<valueType>(-1)) {
    }

    explicit idIndex(const valueType index)
        : value(index) {
    }

    bool IsValid() const {
        return value != static_cast<valueType>(-1);
    }

    void Invalidate() {
        value = static_cast<valueType>(-1);
    }

    valueType Get() const {
        return value;
    }

    operator valueType() const {
        return value;
    }

    bool operator==(const idIndex& other) const { return value == other.value; }
    bool operator!=(const idIndex& other) const { return value != other.value; }
    bool operator<(const idIndex& other) const { return value < other.value; }

private:
    valueType value;
};

enum class idRecoveredInvalidIndex : int { invalid = -1 };
static_assert(sizeof(idIndex<short, idRecoveredInvalidIndex>) == sizeof(short),
    "Recovered idIndex ABI changed");
