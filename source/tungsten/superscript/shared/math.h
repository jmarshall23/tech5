#pragma once

#include "../lib/vector.h"

class math {
public:
    static void AngToVectors(const ssVector& angles, ssVector* forward,
        ssVector* right, ssVector* up);

    static const float TWO_PI;
    static const float ONE_OVER_TWO_PI;
};
