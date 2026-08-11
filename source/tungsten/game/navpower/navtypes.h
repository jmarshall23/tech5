#pragma once

enum navLayer_t : int {
    NAVLAYER_PLAYER = 0,
    NAVLAYER_MONSTER16 = 1,
    NAVLAYER_MONSTER32 = 2,
    NAVLAYER_MONSTER48 = 3,
    NAVLAYER_MONSTER96 = 4,
    NAVLAYER_MONSTER128 = 5,
    NAVLAYER_FLIGHT = 6,
    NAVLAYER_NONE = 7,
    NAVLAYER_MAX = 8
};

enum navCustomFlags_t : int {
    NavCustomNone = 0,
    NavCustomClimbTick = 1,
    NavCustomClimbImp = 2,
    NavFlightLanding = 64,
    NavCustomAll = -1
};

struct idNavCoverInfo_t {
    float coverHeight;
    float coverFireOverHeight;
    float coverStepOutDist;
    float coverStepOutHeight;
};

static_assert(sizeof(idNavCoverInfo_t) == 16,
    "Recovered navigation cover-info ABI changed");
