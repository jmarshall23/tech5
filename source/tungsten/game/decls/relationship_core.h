#pragma once

#include "../entities/entityptr.h"

class idDeclFaction;
class idEntity;

struct idRelationship {
    enum attitude_t : int {
        ATTITUDE_UNKNOWN = -1,
        ATTITUDE_DESPISE = 0,
        ATTITUDE_HATE = 1,
        ATTITUDE_DISLIKE = 2,
        ATTITUDE_NEUTRAL = 3,
        ATTITUDE_LIKE = 4,
        ATTITUDE_LOVE = 5,
        ATTITUDE_IDOLIZE = 6,
        ATTITUDE_MAX = 7
    };

    enum attitudeStage_t : int {
        ATTITUDESTAGE_OUTSIDER = 0,
        ATTITUDESTAGE_ACCEPTED = 1,
        ATTITUDESTAGE_HEROIC = 2,
        ATTITUDESTAGE_NUM = 3
    };

    idRelationship();

    static attitude_t AttitudeForFloat(float value);
    static float FloatForAttitude(attitude_t value);
    static attitudeStage_t AttitudeToAttitudeStage(attitude_t value);
    void AdjustAttitude(float amount);

    const idDeclFaction* otherFaction;
    attitude_t attitude;
    mutable float curAttitude;
    idEntityPtr<const idEntity> otherEntity;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idRelationship) == 16,
    "Recovered faction relationship ABI changed");
#endif
