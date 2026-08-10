#include "aievent.h"

int Tungsten_GetAIEventEntitySpawnId(const idEntity* entity);
const idEntity* Tungsten_ResolveAIEventEntity(int spawnId);
bool Tungsten_GetAIEventEntityOrigin(int spawnId, idVec3& origin);
idDeclInfo* Tungsten_GetAIDeclResourceList();

int idAIEvent::numEvents = 0;

// Retail symbol: ??0idDeclAiEvent@@QAA@XZ
// EA: 0x82A42BC8, RVA: 0x00A42BC8
idDeclAiEvent::idDeclAiEvent()
    : initialPoolSize(8)
    , eventClass(idAIEvent::AIEVENT_NONE)
    , priority(idAIEvent::AIPRIORITY_VERY_LOW)
    , duration(0)
    , attached(false)
    , instigatorStimulus(false)
    , lookAheadTime(0.0f)
    , volume(1.0f)
    , intensityScale(1.0f)
    , radius(0.0f)
    , bounds{
        idVec3(1.0e30f, 1.0e30f, 1.0e30f),
        idVec3(-1.0e30f, -1.0e30f, -1.0e30f) }
    , distance(0.0f)
    , clipMask()
    , voiceMessage(VOICEMSG_MAX)
    , delayedMessage(AIVOICE_MAX)
    , arcWidthDegrees(0.0f)
    , heightMin(0.0f)
    , heightMax(0.0f)
    , painType(PAIN_NONE) {
}

// Retail symbol: ?GetDeclInfo@idDeclAiEvent@@UBAPAVidDeclInfo@@XZ
// EA: 0x82A42CD0, RVA: 0x00A42CD0
idDeclInfo* idDeclAiEvent::GetDeclInfo() const {
    return Tungsten_GetAIDeclResourceList();
}

// Retail symbol: ?GetDuration@idAIEvent@@QBAHXZ
// EA: 0x82A42CE0, RVA: 0x00A42CE0
int idAIEvent::GetDuration() const {
    return eventDecl != nullptr ? eventDecl->duration : 0;
}

// Retail symbol: ?GetPriority@idAIEvent@@QBAHXZ
// EA: 0x82A42CF8, RVA: 0x00A42CF8
idAIEvent::aiEventPriority_t idAIEvent::GetPriority() const {
    return eventDecl != nullptr
        ? eventDecl->priority : AIPRIORITY_VERY_LOW;
}

// Retail symbol: ?GetInstigatorStimulus@idAIEvent@@QBA_NXZ
// EA: 0x82A42D10, RVA: 0x00A42D10
bool idAIEvent::GetInstigatorStimulus() const {
    return eventDecl != nullptr && eventDecl->instigatorStimulus;
}

// Retail symbol: ?GetEventClass@idAIEvent@@QBA?AW4aiEventClass_t@1@XZ
// EA: 0x82A42D28, RVA: 0x00A42D28
idAIEvent::aiEventClass_t idAIEvent::GetEventClass() const {
    return eventDecl != nullptr ? eventDecl->eventClass : AIEVENT_NONE;
}

// Retail symbol: ?UpdateAttached@idAIEvent@@AAA?AW4aiEventUpdateResult_t@1@H@Z
// EA: 0x82A42D40, RVA: 0x00A42D40
idAIEvent::aiEventUpdateResult_t idAIEvent::UpdateAttached(
        const int currentTime) {
    return Tungsten_ResolveAIEventEntity(originator.GetSpawnId()) != nullptr
        ? InternalUpdateAttached(currentTime) : AIUPDATE_REMOVE;
}

// Retail symbol: ?Update@idAIEvent@@QAA?AW4aiEventUpdateResult_t@1@H@Z
// EA: 0x82A42DE0, RVA: 0x00A42DE0
idAIEvent::aiEventUpdateResult_t idAIEvent::Update(const int currentTime) {
    if (eventDecl == nullptr || !eventDecl->attached) {
        return InternalUpdate(currentTime);
    }
    const aiEventUpdateResult_t attachedResult = UpdateAttached(currentTime);
    return attachedResult != AIUPDATE_REMOVE
        ? InternalUpdate(currentTime) : attachedResult;
}

// Retail symbol: ??0idAIEvent@@QAA@XZ
// EA: 0x82A42E60, RVA: 0x00A42E60
idAIEvent::idAIEvent()
    : eventDecl(nullptr)
    , enabled(true)
    , originator()
    , instigator()
    , origin(0.0f, 0.0f, 0.0f)
    , stimulusOrigin(0.0f, 0.0f, 0.0f)
    , startTime(-1)
    , handle(numEvents++) {
}

idAIEvent::~idAIEvent() = default;

// Retail symbol:
// ?Init@idAIEvent@@QAAXPBVidDeclAiEvent@@PBVidEntity@@1ABVidVec3@@@Z
// EA: 0x82A42EF0, RVA: 0x00A42EF0
void idAIEvent::Init(
        const idDeclAiEvent* const declaration,
        const idEntity* const originatorEntity,
        const idEntity* const instigatorEntity,
        const idVec3& eventOrigin) {
    eventDecl = declaration;
    originator.SetSpawnId(
        Tungsten_GetAIEventEntitySpawnId(originatorEntity));
    instigator.SetSpawnId(
        Tungsten_GetAIEventEntitySpawnId(instigatorEntity));
    origin = eventOrigin;
}

// Retail symbol:
// ?InternalUpdateAttached@idAIEvent@@MAA?AW4aiEventUpdateResult_t@1@H@Z
// EA: 0x82A42F78, RVA: 0x00A42F78
idAIEvent::aiEventUpdateResult_t idAIEvent::InternalUpdateAttached(
        const int currentTime) {
    (void)currentTime;
    idVec3 attachedOrigin;
    if (!Tungsten_GetAIEventEntityOrigin(
            originator.GetSpawnId(), attachedOrigin)) {
        return AIUPDATE_REMOVE;
    }
    origin = attachedOrigin;
    return AIUPDATE_OK;
}

// Retail symbol: ?GetInstigator@idAIEvent@@QBAPBVidEntity@@XZ
// EA: 0x82558090, RVA: 0x00558090
const idEntity* idAIEvent::GetInstigator() const {
    return Tungsten_ResolveAIEventEntity(instigator.GetSpawnId());
}

// Retail symbol: ?GetOriginator@idAIEvent@@QBAPBVidEntity@@XZ
// EA: 0x829FBD70, RVA: 0x009FBD70
const idEntity* idAIEvent::GetOriginator() const {
    return Tungsten_ResolveAIEventEntity(originator.GetSpawnId());
}
