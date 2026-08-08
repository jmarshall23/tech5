#pragma once

#include "bounds.h"

#include <algorithm>
#include <cstdint>
#include <limits>

class idBoundsShort {
public:
    std::int16_t b[2][3];

    void SetBounds(const idBounds& bounds) {
        for (int side = 0; side < 2; ++side) {
            for (int axis = 0; axis < 3; ++axis) {
                const int integerValue = static_cast<int>(bounds[side][axis]);
                b[side][axis] = static_cast<std::int16_t>(std::max(
                    static_cast<int>(std::numeric_limits<std::int16_t>::min()),
                    std::min(
                        static_cast<int>(std::numeric_limits<std::int16_t>::max()),
                        integerValue
                    )
                ));
            }
        }
    }

    idBounds ToBounds() const {
        idBounds result;
        for (int side = 0; side < 2; ++side) {
            for (int axis = 0; axis < 3; ++axis) {
                result[side][axis] = static_cast<float>(b[side][axis]);
            }
        }
        return result;
    }

    bool IntersectsBounds(const idBoundsShort& other) const {
        for (int axis = 0; axis < 3; ++axis) {
            if (b[0][axis] > other.b[1][axis]
                || other.b[0][axis] > b[1][axis]) {
                return false;
            }
        }
        return true;
    }
};

static_assert(sizeof(idBoundsShort) == 12, "idBoundsShort ABI changed");
