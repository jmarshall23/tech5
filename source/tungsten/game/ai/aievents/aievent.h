#pragma once

#include "../../entities/entityptr.h"
#include "../../../../shared/idlib/bv/bounds.h"
#include "../../../../shared/idlib/handle.h"
#include "../../../../shared/idlib/math/vector.h"

#include <cstdint>

class idDeclInfo;
class idEntity;
class idTypeInfo;

bool Tungsten_GetAIEventEntityOrigin(int spawnId, idVec3& origin);
const idEntity* Tungsten_ResolveAIEventEntity(int spawnId);
bool Tungsten_GetAIEventEntityLinearVelocity(
    int spawnId, idVec3& velocity);
bool Tungsten_GetAIEventEntityWorldOrigin(
    const idEntity* entity, idVec3& origin);
int Tungsten_GetAIEventGameMillisecondsPerFrame();

enum invalidAIEvent_t : int;

enum voiceMessageType_t : int {
    VOICEMSG_SIGHTED_ENEMY = 0,
    VOICEMSG_HEARD_SOMETHING = 1,
    VOICEMSG_SAW_SOMETHING = 2,
    VOICEMSG_TOOK_DAMAGE = 3,
    VOICEMSG_GOT_KILLED = 4,
    VOICEMSG_FOUND_DEAD_BODY = 5,
    VOICEMSG_MEMBER_KILLED = 6,
    VOICEMSG_MAX = 7
};

enum voiceMsg_t : int {
    AIVOICE_SEARCH_START_FROM_COMBAT = 0,
    AIVOICE_COMBAT_CHANGE_POSITION = 1,
    AIVOICE_COMBAT_FIRST_SPOT = 2,
    AIVOICE_COMBAT_RESPOT = 3,
    AIVOICE_COMBAT_FLANK_SPOT = 4,
    AIVOICE_COMBAT_DOWNED = 5,
    AIVOICE_COMBAT_LOSING_BATTLE = 6,
    AIVOICE_COMBAT_RELOAD = 7,
    AIVOICE_COMBAT_FIGHT_MOTIVATION = 8,
    AIVOICE_COMBAT_FIGHT_MOTIVATION_RESPONSE = 9,
    AIVOICE_MAX = 10
};

enum painType_t : int {
    PAIN_NONE = 0,
    PAIN_FLINCH = 1,
    PAIN_STAGGER = 2,
    PAIN_STUN = 3,
    PAIN_STUN_IGNORE = 4,
    PAIN_DEATH = 5,
    PAYNE_MAX = 6
};

struct idContents {
    std::uint32_t bits;

    idContents() : bits(0) {}
};

class idAIEvent {
public:
    enum aiEventClass_t : int {
        AIEVENT_NONE = 0x0,
        AIEVENT_FOOTSTEP = 0x1,
        AIEVENT_GUNFIRE = 0x2,
        AIEVENT_EXPLOSION = 0x4,
        AIEVENT_GRENADE = 0x8,
        AIEVENT_BODY = 0x10,
        AIEVENT_VEHICLE = 0x20,
        AIEVENT_AIM = 0x40,
        AIEVENT_VOICE = 0x200,
        AIEVENT_INVESTIGATE = 0x800,
        AIEVENT_PROJECTILE = 0x1000,
        AIEVENT_POSSESSION = 0x2000,
        AIEVENT_DOOR_MOTION = 0x10000,
        AIEVENT_DEAD_BODY_LAND = 0x20000,
        AIEVENT_DEPLOY_SOUND = 0x40000,
        AIEVENT_VEHICLE_SOUND = 0x80000,
        AIEVENT_PLAYER_GRENADE = 0x100000,
        AIEVENT_PLAYER_INTERACTION = 0x200000,
        AIEVENT_RELOAD = 0x1000000,
        AIEVENT_PROJECTILE_IMPACT = 0x2000000,
        AIEVENT_DELAYED_VO = 0x4000000,
        AIEVENT_ALL_AI = static_cast<int>(0xFFEFFFFFu),
        AIEVENT_ALL_PLAYER = 0x100000,
        AIEVENT_ALL = -1
    };

    enum aiEventUpdateResult_t : int {
        AIUPDATE_OK = 0,
        AIUPDATE_REMOVE = 1
    };

    enum aiEventPriority_t : int {
        AIPRIORITY_VERY_LOW = 0,
        AIPRIORITY_LOW = 25,
        AIPRIORITY_MEDIUM = 50,
        AIPRIORITY_HIGH = 75,
        AIPRIORITY_VERY_HIGH = 100
    };

    enum aiEventTrigger_t : int {
        TRIGGERS_NOTHING = 0,
        TRIGGERS_COMBAT = 1,
        TRIGGERS_SEARCH = 2,
        TRIGGERS_RELAXED = 4
    };

    idAIEvent();
    virtual idTypeInfo* GetType() = 0;
    virtual ~idAIEvent();

    virtual void Clear() = 0;
    virtual aiEventUpdateResult_t InternalUpdate(int currentTime) = 0;
    virtual aiEventUpdateResult_t InternalUpdateAttached(int currentTime);
    virtual bool InternalIsTouching(const idEntity* entity, int currentTime) = 0;
    virtual void InternalDrawDebug(int level, int currentTime, int duration) = 0;
    virtual float InternalGetIntensity(const idEntity* entity) = 0;

    void Init(const class idDeclAiEvent* decl, const idEntity* originator,
        const idEntity* instigator, const idVec3& origin);
    aiEventUpdateResult_t Update(int currentTime);
    int GetDuration() const;
    aiEventPriority_t GetPriority() const;
    bool GetInstigatorStimulus() const;
    aiEventClass_t GetEventClass() const;
    const idEntity* GetInstigator() const;
    const idEntity* GetOriginator() const;

    const class idDeclAiEvent* eventDecl;
    bool enabled;
    idEntityPtr<const idEntity> originator;
    idEntityPtr<const idEntity> instigator;
    idVec3 origin;
    idVec3 stimulusOrigin;
    int startTime;
    idHandle<int, invalidAIEvent_t, -1> handle;

    static int numEvents;

private:
    aiEventUpdateResult_t UpdateAttached(int currentTime);
};

class idDeclAiEvent {
public:
    idDeclAiEvent();
    virtual ~idDeclAiEvent() = default;
    virtual idDeclInfo* GetDeclInfo() const;

    int initialPoolSize;
    idAIEvent::aiEventClass_t eventClass;
    idAIEvent::aiEventPriority_t priority;
    int duration;
    bool attached;
    bool instigatorStimulus;
    float lookAheadTime;
    float volume;
    float intensityScale;
    float radius;
    idBounds bounds;
    float distance;
    idContents clipMask;
    voiceMessageType_t voiceMessage;
    voiceMsg_t delayedMessage;
    float arcWidthDegrees;
    float heightMin;
    float heightMax;
    painType_t painType;
};

static_assert(sizeof(idContents) == 4,
    "Recovered AI-event contents mask layout changed");
