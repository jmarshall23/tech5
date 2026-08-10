#pragma once

#include "../entities/entityptr.h"
#include "../../../shared/idlib/math/vector.h"
#include "../../../shared/idlib/text/str.h"

class idBot;
class idEntity;

enum botAimPriority_t : int {
    AIM_PRIORITY_NULL = 0,
    AIM_PRIORITY_LOOK_AT_MOVE_POINT = 1,
    AIM_PRIORITY_LOOK_AT_POI = 2,
    AIM_PRIORITY_BEHAVIOR_DRIVEN = 3,
    AIM_PRIORITY_LOOK_AT_SPECIAL_MOVE_POINT = 4,
    AIM_PRIORITY_DEBUG_OVERRIDE = 5,
    AIM_PRIORITY_MAX = 6
};

enum botAimType_t : int {
    AIM_TYPE_NONE = 0,
    AIM_TYPE_ENTITY = 1,
    AIM_TYPE_POSITION = 2,
    AIM_TYPE_DIRECTION = 3
};

enum aimPoint_t : int {
    AIMPOINT_ORIGIN = 0,
    AIMPOINT_HEAD = 1,
    AIMPOINT_TORSO = 2,
    AIMPOINT_CENTER = 3,
    AIMPOINT_LEGS = 4,
    AIMPOINT_FEET = 5,
    AIMPOINT_BEST = 6,
    AIMPOINT_EYELEVEL = 7,
    AIMPOINT_LOOKAHEAD = 8,
    AIMPOINT_MAX = 9
};

class idBotAimState {
public:
    struct BotAimRequest_t {
        BotAimRequest_t();
        void Reset();

        botAimPriority_t aimPriority;
        botAimType_t aimType;
        aimPoint_t aimPoint;
        int aimStartTimeInMS;
        int aimValidTimeInMS;
        idVec3 aimVector;
        idStr aimUserName;
        idEntityPtr<const idEntity> aimEntity;
    };

    idBotAimState();
    ~idBotAimState();

    int FindIndexOfAimRequestUser(const char* userName) const;

    idVec3 currentAimPoint;
    idBot* owner;
    idAngles desiredViewAngles;
    BotAimRequest_t aimRequests[4];
};

static_assert(sizeof(idBotAimState::BotAimRequest_t) == 68,
    "Recovered bot aim request ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idBotAimState) == 300,
    "Recovered bot aim state ABI changed");
#endif

