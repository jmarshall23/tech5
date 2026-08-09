#pragma once

class idBitFlag32 {
public:
    int flags;

    idBitFlag32()
        : flags(0) {
    }

    idBitFlag32(const int initialFlags)
        : flags(initialFlags) {
    }

    void Clear() { flags = 0; }
    void Set(const int mask) { flags |= mask; }
    void Clear(const int mask) { flags &= ~mask; }
    bool IsSet(const int mask) const { return (flags & mask) != 0; }

    operator int() const { return flags; }
};

static_assert(sizeof(idBitFlag32) == 4, "Recovered idBitFlag32 ABI changed");

