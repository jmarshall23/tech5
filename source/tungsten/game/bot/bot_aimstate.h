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

// Runtime-owned player, entity-table, cvar, and debug-render operations used
// by the recovered aim state.  Keeping these behind a service preserves the
// retail 300-byte idBotAimState layout while the surrounding game runtime is
// recovered translation unit by translation unit.
class idBotAimStateServices {
public:
    virtual ~idBotAimStateServices() = default;

    virtual int GetScaledGameTime() const = 0;
    virtual int GetAimSkill() const = 0;
    virtual idAngles GetOwnerViewAngles(const idBot& bot) const = 0;
    virtual idVec3 GetOwnerEyePosition(const idBot& bot) const = 0;
    virtual int GetEntitySpawnId(const idEntity* entity) const = 0;
    virtual const idEntity* ResolveEntitySpawnId(int spawnId) const = 0;
    virtual idVec3 GetEntityOrigin(const idEntity& entity) const = 0;
    virtual bool GetEntityAimPoint(const idEntity& entity,
        aimPoint_t aimPoint, idVec3& result) const = 0;
    virtual idVec3 GetEntityLinearVelocity(const idEntity& entity) const = 0;
    virtual bool ShouldShowAimPoint(const idBot& bot) const = 0;
    virtual void DebugAimPoint(const idVec3& point) const = 0;
};

void Tungsten_SetBotAimStateServices(idBotAimStateServices* services);

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

    float GetAimOffset(float distToAimPointSqr) const;
    void CalcDesiredViewAngles(const idVec3& desiredAimVector);
    int FindIndexOfAimRequestUser(const char* userName) const;
    void Update();
    void AddAimRequestPosition(const idVec3& pos,
        botAimPriority_t priority, const char* userName,
        float aimTimeInSeconds);
    void AddAimRequestEntity(const idEntity* entity,
        botAimPriority_t priority, const char* userName,
        aimPoint_t aimPoint, float aimTimeInSeconds);
    void ClearOldAimRequests();
    void PostUpdate();

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
