#pragma once

#include "aieventtrace.h"

bool Tungsten_GetAIEventEntityLinearVelocity(
    int spawnId, idVec3& velocity);

class idAIEventProjectile : public idAIEventTrace {
public:
    idAIEventProjectile();
    ~idAIEventProjectile() override = default;

    aiEventUpdateResult_t InternalUpdateAttached(int currentTime) override;
    float GetDistance() const override;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAIEventProjectile) == 208,
    "Recovered projectile AI-event ABI changed");
#endif
