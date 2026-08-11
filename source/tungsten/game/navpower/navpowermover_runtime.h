#pragma once

#include "navpowermover.h"
#include "../entities/entityptr.h"

class idEntity;
class idNpAreaHandleImpl;
class idNpMoverImpl;
class idNpNavigatorImpl;

// The implementation is owned by NavPower.  Its allocation, pool and bfx
// forwarding operations remain outside this recovered data-contract slice.
class idNpAreaHandle {
public:
    idNpAreaHandle() : impl(nullptr) {}

    idNpAreaHandleImpl* impl;
};

class idNpMover {
public:
    struct idProbeResults {
        idProbeResults();

        idVec3 endPos;
        float distTotal;
        float distFraction;
        float distTravelled;
        idNpAreaHandle endArea;
        int collisionEdge;
        bool collided;
    };

    struct idLinkUseParms {
        idLinkUseParms();

        navLinkFlags_t linkFlags;
        idEntityPtr<idEntity> linkEntityStart;
        idEntityPtr<idEntity> linkEntityEnd;
        idVec3 startPos;
        idVec3 startNormal;
        idVec3 endPos;
        idVec3 endNormal;
        float mustUseDist;
        float mayUseDist;
        float jumpTimeRemaining;
        unsigned char reserved : 6;
        bool customLinkMode : 1;
        bool isJumpLink : 1;
    };

    idNpMoverImpl* impl;
};

struct idNpCornerInfo {
    enum cornerType_t : int {
        CORNER_NOT_A_LINK = 0,
        CORNER_LINKSTART = 1,
        CORNER_LINKEND = 2
    };

    idNpCornerInfo();

    cornerType_t cornerType;
    idVec3 position;
    idVec3 areaNormal;
    navLinkFlags_t linkFlags;
    float mustUseDist;
    float mayUseDist;
    idEntityPtr<idEntity> linkEntityStart;
    idEntityPtr<idEntity> linkEntityEnd;
    idNpLink link;
    unsigned char reserved : 3;
    bool isPointGrounded : 1;
    bool biDirectional : 1;
    bool jumpLink : 1;
    bool stopToUse : 1;
    bool isGoal : 1;
};

class idNpNavigator {
public:
    struct idNavWedge {
        bool IsHeadingInside(float heading) const;

        float angleStart;
        float angleEnd;
    };

    struct idAdvanceInfo {
        enum posType_t : int {
            POS_SURFACE = 0,
            POS_LINK = 1,
            POS_GOAL = 2
        };

        idAdvanceInfo();

        posType_t advancePosType;
        idVec3 advancePos;
        float advanceDistance;
        idNpAreaHandle advanceArea;
        idNpLink advanceLink;
        idNpMover::idLinkUseParms linkInfo;
        bool linkBackWards;
    };

    idNpNavigatorImpl* impl;
};

static_assert(sizeof(idNpAreaHandle) == 4,
    "Recovered NavPower area handle ABI changed");
static_assert(sizeof(idNpMover::idProbeResults) == 36,
    "Recovered NavPower probe result ABI changed");
static_assert(sizeof(idNpMover::idLinkUseParms) == 76,
    "Recovered NavPower link-use parameters ABI changed");
static_assert(sizeof(idNpCornerInfo) == 60,
    "Recovered NavPower corner information ABI changed");
static_assert(sizeof(idNpNavigator::idAdvanceInfo) == 112,
    "Recovered NavPower advance information ABI changed");
static_assert(sizeof(idNpNavigator::idNavWedge) == 8,
    "Recovered NavPower navigation wedge ABI changed");
