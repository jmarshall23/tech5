#pragma once

#include "aieventsphere.h"

class idAIEventSound : public idAIEventSphere {
public:
    idAIEventSound();
    ~idAIEventSound() override = default;

    bool InternalIsTouching(
        const idEntity* entity, int currentTime) override;
    float InternalGetIntensity(const idEntity* entity) override;
};

bool Tungsten_AIEventSoundTraceOccluded(
    const idVec3& origin, const idVec3& listenerOrigin);
void Tungsten_DebugAIEventSoundTrace(const idVec3& origin,
    const idVec3& listenerOrigin, bool occluded);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAIEventSound) == 52,
    "Recovered sound AI-event ABI changed");
#endif
