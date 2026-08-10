#include "aieventsound.h"

#include <algorithm>
#include <cmath>

idAIEventSound::idAIEventSound() = default;

bool idAIEventSound::InternalIsTouching(
        const idEntity* const entity, const int) {
    idVec3 entityOrigin;
    if (!Tungsten_GetAIEventEntityWorldOrigin(entity, entityOrigin)) {
        return false;
    }
    return (entityOrigin - origin).LengthSqr()
        <= GetRadius() * GetRadius();
}

float idAIEventSound::InternalGetIntensity(
        const idEntity* const entity) {
    idVec3 listenerOrigin;
    if (!Tungsten_GetAIEventEntityWorldOrigin(entity, listenerOrigin)) {
        return 0.0f;
    }

    idVec3 delta = listenerOrigin - origin;
    float distance = delta.Length();
    float occlusion = 0.0f;
    const bool occluded = Tungsten_AIEventSoundTraceOccluded(
        origin, listenerOrigin);
    Tungsten_DebugAIEventSoundTrace(origin, listenerOrigin, occluded);
    if (occluded) {
        occlusion = 0.5f;
        if (delta.z > 0.0f) {
            delta.z *= 3.0f;
            distance = delta.Length();
        }
    }

    const float volume = eventDecl != nullptr ? eventDecl->volume : 1.0f;
    const float intensityScale = eventDecl != nullptr
        ? eventDecl->intensityScale : 1.0f;
    const float intensity = volume
        * (1.0f - distance / GetRadius())
        * (1.0f - occlusion) * intensityScale;
    return (std::max)(0.0f, intensity);
}
