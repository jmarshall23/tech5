#include "bitblockallocator.h"

#include <algorithm>
#include <cstdlib>
#include <cstring>

idBitBlockAllocator::idBitBlockAllocator(const int blocksWide,
    const int blocksHigh)
    : width(std::max(0, blocksWide)), height(std::max(0, blocksHigh)),
      bits(nullptr) {
    const std::size_t count = static_cast<std::size_t>(width)
        * static_cast<std::size_t>(height);
    if (count != 0) {
        bits = static_cast<unsigned char*>(std::calloc((count + 7u) / 8u, 1));
    }
}

idBitBlockAllocator::~idBitBlockAllocator() {
    std::free(bits);
}

void idBitBlockAllocator::Clear() {
    if (bits != nullptr) {
        const std::size_t count = static_cast<std::size_t>(width)
            * static_cast<std::size_t>(height);
        std::memset(bits, 0, (count + 7u) / 8u);
    }
}

bool idBitBlockAllocator::Get(const int x, const int y) const {
    if (bits == nullptr || x < 0 || y < 0 || x >= width || y >= height) {
        return false;
    }
    const int bit = y * width + x;
    return (bits[bit >> 3] & (1u << (bit & 7))) != 0;
}

void idBitBlockAllocator::Set(const int x, const int y) {
    if (bits == nullptr || x < 0 || y < 0 || x >= width || y >= height) {
        return;
    }
    const int bit = y * width + x;
    bits[bit >> 3] |= static_cast<unsigned char>(1u << (bit & 7));
}

void idBitBlockAllocator::FillBlock(const int x, const int y,
    const int w, const int h) {
    for (int row = 0; row < h; ++row) {
        for (int column = 0; column < w; ++column) {
            Set(x + column, y + row);
        }
    }
}

void idBitBlockAllocator::FillBitBlock(const int x, const int y,
    const idBitBlockAllocator& block) {
    for (int row = 0; row < block.height; ++row) {
        for (int column = 0; column < block.width; ++column) {
            if (block.Get(column, row)) {
                Set(x + column, y + row);
            }
        }
    }
}

bool idBitBlockAllocator::TestBlock(const int x, const int y, const int w,
    const int h, int* const fail) const {
    if (w < 0 || h < 0 || x < 0 || y < 0 || x + w > width || y + h > height) {
        return false;
    }
    if (fail != nullptr && fail[0] >= x && fail[0] < x + w
        && fail[1] >= y && fail[1] < y + h) {
        return false;
    }
    for (int row = 0; row < h; ++row) {
        for (int column = w - 1; column >= 0; --column) {
            if (Get(x + column, y + row)) {
                if (fail != nullptr) {
                    fail[0] = x + column;
                    fail[1] = y + row;
                }
                return false;
            }
        }
    }
    return true;
}

bool idBitBlockAllocator::TestBitBlock(const int x, const int y,
    const idBitBlockAllocator& block) const {
    if (x < 0 || y < 0 || x + block.width > width || y + block.height > height) {
        return false;
    }
    for (int row = 0; row < block.height; ++row) {
        for (int column = 0; column < block.width; ++column) {
            if (block.Get(column, row) && Get(x + column, y + row)) {
                return false;
            }
        }
    }
    return true;
}

bool idBitBlockAllocator::FindBlockLinear(int& x, int& y, const int w,
    const int h) {
    int fail[2] = { -1, -1 };
    for (y = 0; y <= height - h; ++y) {
        for (x = 0; x <= width - w; ++x) {
            if (TestBlock(x, y, w, h, fail)) {
                FillBlock(x, y, w, h);
                return true;
            }
        }
    }
    return false;
}

bool idBitBlockAllocator::FindBitBlockLinear(int& x, int& y,
    const idBitBlockAllocator& block) {
    for (y = 0; y <= height - block.height; ++y) {
        for (x = 0; x <= width - block.width; ++x) {
            if (TestBitBlock(x, y, block)) {
                FillBitBlock(x, y, block);
                return true;
            }
        }
    }
    return false;
}

void SeparateBits(const int value, int& x, int& y) {
    x = 0;
    y = 0;
    const unsigned int bits = static_cast<unsigned int>(value);
    for (unsigned int index = 0; index < 16; ++index) {
        x |= static_cast<int>(((bits >> (index * 2)) & 1u) << index);
        y |= static_cast<int>(((bits >> (index * 2 + 1)) & 1u) << index);
    }
}

void SeparateBits2(const int bits, int& x, int& y) {
    SeparateBits(bits, x, y);
}

bool idBitBlockAllocator::FindBlockInterleaved(int& x, int& y, const int w,
    const int h, int& searchPoint, const bool naturallyAlign) {
    if (w > width || h > height || w < 0 || h < 0) {
        return false;
    }
    if (searchPoint < 0) {
        searchPoint = 0;
    }
    const int count = width * height;
    int fail[2] = { -1, -1 };
    const auto nextPowerOfTwo = [](const int value) {
        int power = 1;
        while (power < std::max(1, value)) {
            power <<= 1;
        }
        return power;
    };
    const int alignX = nextPowerOfTwo(w);
    const int alignY = nextPowerOfTwo(h);
    for (; searchPoint < count; ++searchPoint) {
        const int interleaved = naturallyAlign
            ? searchPoint
            : ((searchPoint >> 1) ^ searchPoint);
        SeparateBits2(interleaved, x, y);
        if (naturallyAlign
            && (x / alignX != (x + std::max(0, w - 1)) / alignX
                || y / alignY != (y + std::max(0, h - 1)) / alignY)) {
            continue;
        }
        if (TestBlock(x, y, w, h, fail)) {
            FillBlock(x, y, w, h);
            return true;
        }
    }
    return false;
}
