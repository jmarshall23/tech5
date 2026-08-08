#pragma once

#include <cstdint>

class idBitBlockAllocator {
public:
    idBitBlockAllocator(int blocksWide, int blocksHigh);
    ~idBitBlockAllocator();

    idBitBlockAllocator(const idBitBlockAllocator&) = delete;
    idBitBlockAllocator& operator=(const idBitBlockAllocator&) = delete;

    void Clear();
    void FillBlock(int x, int y, int w, int h);
    void FillBitBlock(int x, int y, const idBitBlockAllocator& block);
    bool TestBlock(int x, int y, int w, int h, int* fail = nullptr) const;
    bool TestBitBlock(int x, int y, const idBitBlockAllocator& block) const;
    bool FindBlockLinear(int& x, int& y, int w, int h);
    bool FindBitBlockLinear(int& x, int& y, const idBitBlockAllocator& block);
    bool FindBlockInterleaved(int& x, int& y, int w, int h,
        int& searchPoint, bool naturallyAlign);

    int Width() const { return width; }
    int Height() const { return height; }
    bool Get(int x, int y) const;

private:
    int width;
    int height;
    unsigned char* bits;

    void Set(int x, int y);
};

void SeparateBits(int bits, int& x, int& y);
void SeparateBits2(int bits, int& x, int& y);

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idBitBlockAllocator) == 12,
    "Recovered idBitBlockAllocator ABI changed");
#endif
