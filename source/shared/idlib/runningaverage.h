#pragma once

#include <cstdint>

// Recovered layout of idList<float, 5> from tungsten.exe.h type 12501. This
// private storage facade preserves the recovered container definition
// while retaining the original Win32 field widths and offsets.
struct idRunningAverageFloatList {
    float* list;
    int num;
    int size;
    std::int16_t granularity;
    std::uint8_t memTag;
    std::uint8_t listStatic;
};

static_assert(
    sizeof(idRunningAverageFloatList) == 16,
    "Recovered idList<float, 5> layout changed"
);

// tungsten.exe.h type 12505.
class idRunningAverage {
public:
    idRunningAverage();
    ~idRunningAverage();

    idRunningAverage(const idRunningAverage&) = delete;
    idRunningAverage& operator=(const idRunningAverage&) = delete;

    float GetAverage();
    float GetMin();
    float GetMax();
    void Init(int num);
    void Add(float val);

private:
    int maxNum;
    int current;
    idRunningAverageFloatList vals;
};

static_assert(sizeof(idRunningAverage) == 24, "idRunningAverage ABI changed");
