#include "runningaverage.h"

#include <algorithm>
#include <cstdlib>

idRunningAverage::idRunningAverage()
    : maxNum(0)
    , current(0)
    , vals{nullptr, 0, 0, 16, 5, 0} {
}

idRunningAverage::~idRunningAverage() {
    std::free(vals.list);
}

float idRunningAverage::GetAverage() {
    if (vals.num == 0) {
        return 0.0f;
    }

    float total = 0.0f;
    for (int index = 0; index < vals.num; ++index) {
        total += vals.list[index];
    }
    return total / static_cast<float>(vals.num);
}

float idRunningAverage::GetMin() {
    if (vals.num == 0) {
        return 0.0f;
    }

    float minimum = vals.list[0];
    for (int index = 1; index < vals.num; ++index) {
        minimum = std::min(minimum, vals.list[index]);
    }
    return minimum;
}

float idRunningAverage::GetMax() {
    if (vals.num == 0) {
        return 0.0f;
    }

    float maximum = vals.list[0];
    for (int index = 1; index < vals.num; ++index) {
        maximum = std::max(maximum, vals.list[index]);
    }
    return maximum;
}

void idRunningAverage::Init(const int num) {
    current = 0;

    if (num <= 0) {
        vals.num = 0;
        maxNum = 0;
        return;
    }

    if (vals.size < num) {
        float* const replacement = static_cast<float*>(
            std::malloc(sizeof(float) * static_cast<std::size_t>(num))
        );
        if (replacement == nullptr) {
            vals.num = 0;
            maxNum = 0;
            return;
        }
        std::free(vals.list);
        vals.list = replacement;
        vals.size = num;
    }

    vals.num = 0;
    maxNum = num;
}

void idRunningAverage::Add(const float val) {
    if (maxNum <= 0) {
        return;
    }

    if (vals.num != maxNum) {
        ++vals.num;
        current = vals.num - 1;
    } else {
        ++current;
        if (current >= maxNum) {
            current = 0;
        }
    }

    vals.list[current] = val;
}
