#pragma once

#include <cstdint>

class idMD6AnimData {
public:
    enum animFlag_t : std::uint16_t {
        ANIM_FLAG_ADDITIVE = 0x0001,
        ANIM_FLAG_USE_FORWARD_TRANSLATION = 0x0002,
        ANIM_FLAG_USE_LEFT_TRANSLATION = 0x0004,
        ANIM_FLAG_USE_UP_TRANSLATION = 0x0008,
        ANIM_FLAG_USE_ROTATION = 0x0010,
        ANIM_FLAG_IGNORE_BOUNDS = 0x0020,
        ANIM_FLAG_DEFAULTED = 0x0040,
        ANIM_FLAG_PROXY = 0x0080,
        ANIM_FLAG_RETARGET_ADDITIVE = 0x0100,
        ANIM_FLAG_FRAME_ZERO_DELTA = 0x0200,
        ANIM_FLAG_HAS_JOINT_DATA = 0x0400,
        ANIM_FLAG_HAS_USER_CHANNEL_DATA = 0x0800,
        ANIM_FLAG_HAS_ORIGIN_DELTA = 0x1000,
        ANIM_FLAG_INJURED = 0x2000,
        ANIM_FLAG_SCRAMBLE = 0x4000,
        ANIM_FLAG_FACETRACKS_COMPOSITE = 0x8000
    };

    unsigned int totalSize;
    std::uint16_t size;
    std::uint16_t flags;
    std::uint16_t numFrames;
    std::uint16_t frameRate;
    std::uint16_t numFrameSets;
    std::uint16_t frameSetTblOffset;
    std::uint16_t frameSetOffsetTblOffset;
    std::uint16_t numAnimMaps;
    std::uint16_t constROffset;
    std::uint16_t constSOffset;
    std::uint16_t constTOffset;
    std::uint16_t constUOffset;
    std::uint16_t nextSize;
    std::uint16_t jointWeightsOffset;
    float startDelta[12];
    float endDelta[12];
};

static_assert(sizeof(idMD6AnimData) == 128,
    "Recovered MD6 animation-data ABI changed");
