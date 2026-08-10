#pragma once

#include "../entities/entityptr.h"

class idEntity;

// Temporary integration seams for the unrecovered idPlayer RTTI and gameLocal
// translation units. The standalone verification target supplies them; the
// full game runtime will bind them to idPlayer::CastTo and scaled game time.
int Tungsten_GetPlayerEntityNumber(const idEntity* entity);
int Tungsten_GetScaledGameMilliseconds();

class idEngagementTracker {
public:
    void Update(float elapsedTime);
    void OnEngaged(const idEntity* attacker, float engagementTimeOverride);

    idEntityPtr<idEntity> lastAttacker;
    int lastAttackerTime;
    int lastNonPlayerEngagementTime;
    float nonPlayerEngagementTimer;
    float playerEngagementTimers[6];
    bool isEngaged;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idEngagementTracker) == 44,
    "Recovered idEngagementTracker layout changed");
#endif
