#pragma once

#include "idlib/handle.h"
#include "idlib/hashing/crc8.h"

#include <cstdint>

class idMD6SkelData {
public:
    std::uint16_t size;
    std::uint16_t numJoints;
    std::uint16_t numUserChannels;
    idHandle<unsigned short, invalidCrc_t, 65535> parentTblCrc;
    std::uint16_t basePoseOffset;
    std::uint16_t inverseBasePoseOffset;
    std::uint16_t inverseBasePoseQuatOffset;
    std::uint16_t parentTblOffset;
    std::uint16_t jointHandleTblOffset;
    std::uint16_t userChannelHandleTblOffset;
    std::uint16_t jointWeightOffsets[8];
    std::uint16_t userWeightOffsets[8];
    std::uint8_t pad[12];
};

static_assert(sizeof(idMD6SkelData) == 64,
    "Recovered MD6 skeleton-data ABI changed");
