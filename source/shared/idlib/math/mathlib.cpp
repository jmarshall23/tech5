#include "mathlib.h"

#include <cstdint>

int InterleaveBits(const int x, const int y) {
    const std::uint32_t xBits = static_cast<std::uint32_t>(x);
    const std::uint32_t yBits = static_cast<std::uint32_t>(y);
    std::uint32_t interleaved = 0;

    for (int bit = 0; bit < 16; ++bit) {
        interleaved |= ((xBits >> bit) & 1u) << (bit * 2);
        interleaved |= ((yBits >> bit) & 1u) << (bit * 2 + 1);
    }

    return static_cast<int>(interleaved);
}

void DeInterleaveBits(const int bits, int& x, int& y) {
    const std::uint32_t interleaved = static_cast<std::uint32_t>(bits);
    std::uint32_t xBits = 0;
    std::uint32_t yBits = 0;

    for (int bit = 0; bit < 16; ++bit) {
        xBits |= ((interleaved >> (bit * 2)) & 1u) << bit;
        yBits |= ((interleaved >> (bit * 2 + 1)) & 1u) << bit;
    }

    x = static_cast<int>(xBits);
    y = static_cast<int>(yBits);
}

