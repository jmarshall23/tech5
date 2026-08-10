#include "aieventvoice.h"

voiceMessageType_t idAIEventVoice::GetVoiceMessageType() const {
    return eventDecl != nullptr ? eventDecl->voiceMessage : VOICEMSG_MAX;
}

voiceMsg_t idAIEvent_DelayedVO::GetMessage() const {
    return eventDecl != nullptr ? eventDecl->delayedMessage : AIVOICE_MAX;
}

idAIEventVoice::idAIEventVoice() = default;

bool idAIEventVoice::InternalIsTouching(
        const idEntity* const entity, const int currentTime) {
    if (Tungsten_AIEventEntitiesShareEncounterGroup(
            entity, originator.GetSpawnId())) {
        return true;
    }

    idVec3 listenerOrigin;
    if (!Tungsten_GetAIEventEntityWorldOrigin(entity, listenerOrigin)) {
        return false;
    }
    const float distance = (listenerOrigin - origin).Length();
    if (Tungsten_AIEventSoundTraceOccluded(origin, listenerOrigin)
            && distance > GetRadius() * 0.5f) {
        Tungsten_DebugAIEventVoiceTrace(origin, listenerOrigin, -1);
        return false;
    }

    const bool touching = idAIEventSound::InternalIsTouching(
        entity, currentTime);
    Tungsten_DebugAIEventVoiceTrace(
        origin, listenerOrigin, touching ? 1 : 0);
    return touching;
}

bool idAIEvent_DelayedVO::InternalIsTouching(
        const idEntity* const entity, const int) {
    return Tungsten_ResolveAIEventEntity(instigator.GetSpawnId()) == entity;
}
