#pragma once

#include "idlib/handle.h"

enum invalidCrc_t : int {
    INVALID_CRC = 0xFFFF
};

typedef idHandle<unsigned short, invalidCrc_t,
    static_cast<unsigned short>(INVALID_CRC)> crc_t;

static_assert(sizeof(crc_t) == 2, "Recovered crc_t ABI changed");

