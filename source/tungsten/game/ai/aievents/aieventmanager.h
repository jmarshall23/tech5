#pragma once

#include "aievent.h"
#include "aieventpool.h"
#include "../../../../shared/idlib/containers/hashindex.h"

class idCmdArgs;
class idEntity;

using idAIEventHandle = idHandle<int, invalidAIEvent_t, -1>;

// The retail manager selected one of these concrete idAIEvent descendants
// from idDeclAiEvent::eventClass.  Type registration remains a game-runtime
// concern, so the recovered source asks the integration layer for the
// corresponding idTypeInfo object.
enum idAIEventConcreteType_t : int {
    AIEVENT_TYPE_SOUND = 0,
    AIEVENT_TYPE_PROJECTED_SPHERE,
    AIEVENT_TYPE_SPHERE,
    AIEVENT_TYPE_VEHICLE,
    AIEVENT_TYPE_PLAYER_AIM,
    AIEVENT_TYPE_VOICE,
    AIEVENT_TYPE_PROJECTILE,
    AIEVENT_TYPE_DELAYED_VO
};

struct idAIEventManagerRuntimeState {
    int debugLevel;
    int showEvents;
    int printEvents;
    bool stopTime;
    int clientFrameCount;

    idAIEventManagerRuntimeState()
        : debugLevel(0), showEvents(0), printEvents(0),
          stopTime(false), clientFrameCount(0) {
    }
};

const idTypeInfo* Tungsten_GetAIEventConcreteType(
    idAIEventConcreteType_t concreteType);
int Tungsten_GetAIEventDeclCount();
const idDeclAiEvent* Tungsten_GetAIEventDecl(int index);
void Tungsten_GetAIEventManagerRuntimeState(
    idAIEventManagerRuntimeState& state);
void Tungsten_AIEventManagerPrint(const char* text);
void Tungsten_AIEventManagerReportEvent(
    const idAIEvent* event, int currentTime);
bool Tungsten_CanReceiveAIEvents(idEntity* receiver, int currentTime);
bool Tungsten_RespondsToAIEvent(
    idEntity* receiver, const idAIEvent* event);
void Tungsten_OnAIEvent(idEntity* receiver, idAIEvent* event);

class idAIEventManager {
public:
    idAIEventManager();
    ~idAIEventManager();

    idAIEvent* GetEvent(const idAIEventHandle& handle);
    const idAIEvent* GetEvent(const idAIEventHandle& handle) const;

    void RemoveReceiver(idEntity* receiver);
    void ShowStats();
    void RemoveEntityEvents(const idEntity* entity);
    void RemoveEntityEventsOfType(const idEntity* entity,
        idAIEvent::aiEventClass_t eventClass);
    void EnableEvents(const idEntity* entity, int eventClassFlags,
        bool enable);
    void MapShutdown();
    void SetEventInstigator(idAIEventHandle& handle,
        const idEntity* instigator);
    void Init();
    void UpdateEvents(int currentTime);
    idAIEventHandle AddEvent(const idDeclAiEvent* eventDecl,
        int currentTime, const idEntity* originator,
        const idEntity* instigator, const idVec3& origin,
        int delay = 0);
    void RemoveEvent(const idAIEventHandle& handle);
    void AddReceiver(idEntity* receiver);

    // These fields retain the recovered retail ordering and make the class
    // usable by the surrounding partially reconstructed game-local object.
    idList<idAIEvent*, 5> eventList;
    idHashIndex eventHash;
    idList<idEntityPtr<idEntity>, 5> receivers;
    idList<idAIEventPool*, 5> eventPools;

private:
    static const idTypeInfo* GetEventType(const idDeclAiEvent* eventDecl);
    idAIEventPool* FindPoolForEventDecl(
        const idDeclAiEvent* eventDecl) const;
    void RemoveEvent(int index);
    idAIEventPool* AddPool(const idDeclAiEvent* eventDecl);
    idAIEvent* AllocEvent(const idDeclAiEvent* eventDecl);
    idAIEvent* AddEvent(const idDeclAiEvent* eventDecl,
        int currentTime, int delay);
    void RebuildEventHash();
};

idAIEventManager* Tungsten_GetAIEventManagerForCommand();
void aievents_stats_f(const idCmdArgs& args);

