#pragma once

#include "aieventsound.h"

class idAIEventVoice : public idAIEventSound {
public:
    idAIEventVoice();
    ~idAIEventVoice() override = default;

    voiceMessageType_t GetVoiceMessageType() const;
    bool InternalIsTouching(
        const idEntity* entity, int currentTime) override;
};

class idAIEvent_DelayedVO : public idAIEvent {
public:
    ~idAIEvent_DelayedVO() override = default;

    voiceMsg_t GetMessage() const;
    bool InternalIsTouching(
        const idEntity* entity, int currentTime) override;
};

bool Tungsten_AIEventEntitiesShareEncounterGroup(
    const idEntity* listener, int originatorSpawnId);
void Tungsten_DebugAIEventVoiceTrace(const idVec3& origin,
    const idVec3& listenerOrigin, int resultKind);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAIEventVoice) == 52,
    "Recovered voice AI-event ABI changed");
static_assert(sizeof(idAIEvent_DelayedVO) == 52,
    "Recovered delayed-voice AI-event ABI changed");
#endif
