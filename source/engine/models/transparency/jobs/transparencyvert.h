#pragma once

#include "idlib/math/vector.h"

#include <cstdint>

class idTransparencyVert {
public:
    idVec3 xyz;
    std::int16_t st[2];
    std::int16_t st1[2];
    std::uint8_t normal[4];
    std::uint8_t tangent[4];
    std::uint8_t color[4];
};

static_assert(sizeof(idTransparencyVert) == 32,
    "Recovered transparency vertex ABI changed");
