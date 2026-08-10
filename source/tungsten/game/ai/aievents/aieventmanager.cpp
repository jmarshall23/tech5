#include "aieventmanager.h"

#include <algorithm>
#include <cstdio>

int Tungsten_GetAIEventEntitySpawnId(const idEntity* entity);
const idEntity* Tungsten_ResolveAIEventEntity(int spawnId);
int Tungsten_GetAIEventSize(const idAIEvent* event);
const char* Tungsten_GetAIEventTypeName(const idTypeInfo* eventType);

namespace {

bool EventHasExpired(const idAIEvent* const event,
        const int currentTime) {
    const int duration = event->GetDuration();
    return duration != -1 && currentTime > event->startTime + duration;
}

void DrawEventDebug(idAIEvent* const event, const int level,
        const int currentTime) {
    const int duration = level > 2
        ? level : Tungsten_GetAIEventGameMillisecondsPerFrame();
    event->InternalDrawDebug(level, currentTime, duration);
}

} // namespace

// Retail symbol: ?GetEventType@idAIEventManager@@CAPBVidTypeInfo@@PBVidDeclAiEvent@@@Z
// EA: 0x82A43020, RVA: 0x00A43020
const idTypeInfo* idAIEventManager::GetEventType(
        const idDeclAiEvent* const eventDecl) {
    if (eventDecl == nullptr) {
        return nullptr;
    }

    idAIEventConcreteType_t concreteType;
    switch (eventDecl->eventClass) {
    case idAIEvent::AIEVENT_FOOTSTEP:
    case idAIEvent::AIEVENT_GUNFIRE:
    case idAIEvent::AIEVENT_EXPLOSION:
    case idAIEvent::AIEVENT_INVESTIGATE:
    case idAIEvent::AIEVENT_DOOR_MOTION:
    case idAIEvent::AIEVENT_DEAD_BODY_LAND:
    case idAIEvent::AIEVENT_DEPLOY_SOUND:
    case idAIEvent::AIEVENT_VEHICLE_SOUND:
    case idAIEvent::AIEVENT_PLAYER_INTERACTION:
    case idAIEvent::AIEVENT_RELOAD:
    case idAIEvent::AIEVENT_PROJECTILE_IMPACT:
        concreteType = AIEVENT_TYPE_SOUND;
        break;
    case idAIEvent::AIEVENT_GRENADE:
        concreteType = AIEVENT_TYPE_PROJECTED_SPHERE;
        break;
    case idAIEvent::AIEVENT_BODY:
    case idAIEvent::AIEVENT_POSSESSION:
    case idAIEvent::AIEVENT_PLAYER_GRENADE:
        concreteType = AIEVENT_TYPE_SPHERE;
        break;
    case idAIEvent::AIEVENT_VEHICLE:
        concreteType = AIEVENT_TYPE_VEHICLE;
        break;
    case idAIEvent::AIEVENT_AIM:
        concreteType = AIEVENT_TYPE_PLAYER_AIM;
        break;
    case idAIEvent::AIEVENT_VOICE:
        concreteType = AIEVENT_TYPE_VOICE;
        break;
    case idAIEvent::AIEVENT_PROJECTILE:
        concreteType = AIEVENT_TYPE_PROJECTILE;
        break;
    case idAIEvent::AIEVENT_DELAYED_VO:
        concreteType = AIEVENT_TYPE_DELAYED_VO;
        break;
    default:
        return nullptr;
    }
    return Tungsten_GetAIEventConcreteType(concreteType);
}

// Retail symbol: ?GetEvent@idAIEventManager@@QAAPAVidAIEvent@@ABV?$idHandle@HW4invalidAIEvent_t@@$0?0@@@Z
// EA: 0x82A433B0, RVA: 0x00A433B0
idAIEvent* idAIEventManager::GetEvent(const idAIEventHandle& handle) {
    const int key = handle.value;
    for (int index = eventHash.First(key); index >= 0;
            index = eventHash.Next(index)) {
        if (index < eventList.Num()
                && eventList[index] != nullptr
                && eventList[index]->handle == key) {
            return eventList[index];
        }
    }
    return nullptr;
}

const idAIEvent* idAIEventManager::GetEvent(
        const idAIEventHandle& handle) const {
    return const_cast<idAIEventManager*>(this)->GetEvent(handle);
}

// Retail symbol: ?FindPoolForEventDecl@idAIEventManager@@ABAPAVidAIEventPool@@PBVidDeclAiEvent@@@Z
// EA: 0x82A43420, RVA: 0x00A43420
idAIEventPool* idAIEventManager::FindPoolForEventDecl(
        const idDeclAiEvent* const eventDecl) const {
    const idTypeInfo* const eventType = GetEventType(eventDecl);
    if (eventType == nullptr) {
        return nullptr;
    }
    for (int index = 0; index < eventPools.Num(); ++index) {
        idAIEventPool* const pool = eventPools[index];
        if (pool != nullptr && pool->eventType == eventType) {
            return pool;
        }
    }
    return nullptr;
}

void idAIEventManager::RebuildEventHash() {
    eventHash.Clear();
    for (int index = 0; index < eventList.Num(); ++index) {
        if (eventList[index] != nullptr) {
            eventHash.Add(eventList[index]->handle.value, index);
        }
    }
}

// Retail symbol: ?RemoveEvent@idAIEventManager@@AAAXH@Z
// EA: 0x82A434B8, RVA: 0x00A434B8
void idAIEventManager::RemoveEvent(const int index) {
    if (index < 0 || index >= eventList.Num()) {
        return;
    }
    idAIEvent* const event = eventList[index];
    eventList.RemoveIndexFast(index);
    RebuildEventHash();
    if (event != nullptr) {
        idAIEventPool* const pool = FindPoolForEventDecl(event->eventDecl);
        if (pool != nullptr) {
            pool->FreeEvent(event);
        }
    }
}

// Retail symbol: ?RemoveReceiver@idAIEventManager@@QAAXPAVidEntity@@@Z
// EA: 0x82A43548, RVA: 0x00A43548
void idAIEventManager::RemoveReceiver(idEntity* const receiver) {
    for (int index = 0; index < receivers.Num(); ++index) {
        if (Tungsten_ResolveAIEventEntity(
                receivers[index].GetSpawnId()) == receiver) {
            receivers.RemoveIndexFast(index);
            return;
        }
    }
}

// Retail symbol: ?ShowStats@idAIEventManager@@QAAXXZ
// EA: 0x82A43628, RVA: 0x00A43628
void idAIEventManager::ShowStats() {
    Tungsten_AIEventManagerPrint("AI Event Manager Stats:\n");
    unsigned int totalSize = 4u * static_cast<unsigned int>(
        eventPools.NumAllocated() + eventList.NumAllocated() + 20);
    for (int index = 0; index < eventList.Num(); ++index) {
        totalSize += static_cast<unsigned int>(
            Tungsten_GetAIEventSize(eventList[index]));
    }

    int totalAllocated = 0;
    int totalFree = 0;
    char line[256];
    for (int index = 0; index < eventPools.Num(); ++index) {
        const idAIEventPool* const pool = eventPools[index];
        if (pool == nullptr) {
            continue;
        }
        const unsigned int poolSize = pool->GetSize();
        const int allocated = pool->NumAllocatedEvents();
        const int freeEvents = pool->NumFreeEvents();
        std::snprintf(line, sizeof(line),
            "Pool '%s': %u bytes, # allocated = %d, # free = %d\n",
            Tungsten_GetAIEventTypeName(pool->eventType), poolSize,
            allocated, freeEvents);
        Tungsten_AIEventManagerPrint(line);
        totalSize += poolSize;
        totalAllocated += allocated;
        totalFree += freeEvents;
    }
    Tungsten_AIEventManagerPrint("------------------------\n");
    std::snprintf(line, sizeof(line), "%d active events\n",
        eventList.Num());
    Tungsten_AIEventManagerPrint(line);
    std::snprintf(line, sizeof(line), "%d event pools\n",
        eventPools.Num());
    Tungsten_AIEventManagerPrint(line);
    std::snprintf(line, sizeof(line),
        "Total: %u KB, # allocated = %d, # free = %d\n",
        totalSize >> 10, totalAllocated, totalFree);
    Tungsten_AIEventManagerPrint(line);
}

// Retail symbol: ?aievents_stats_f@@YAXABVidCmdArgs@@@Z
// EA: 0x82A43770, RVA: 0x00A43770
void aievents_stats_f(const idCmdArgs& args) {
    (void)args;
    idAIEventManager* const manager =
        Tungsten_GetAIEventManagerForCommand();
    if (manager != nullptr) {
        manager->ShowStats();
    }
}

// Retail symbol: ??0idAIEventManager@@QAA@XZ
// EA: 0x82A43A18, RVA: 0x00A43A18
idAIEventManager::idAIEventManager()
    : eventList(0)
    , eventHash(1024, 1024, TAG_HASHINDEX)
    , receivers(0)
    , eventPools(0) {
}

// Retail symbol: ?RemoveEntityEvents@idAIEventManager@@QAAXPBVidEntity@@@Z
// EA: 0x82A43B38, RVA: 0x00A43B38
void idAIEventManager::RemoveEntityEvents(const idEntity* const entity) {
    for (int index = eventList.Num() - 1; index >= 0; --index) {
        if (Tungsten_ResolveAIEventEntity(
                eventList[index]->originator.GetSpawnId()) == entity) {
            RemoveEvent(index);
        }
    }
}

// Retail symbol: ?RemoveEntityEventsOfType@idAIEventManager@@QAAXPBVidEntity@@W4aiEventClass_t@idAIEvent@@@Z
// EA: 0x82A43BD8, RVA: 0x00A43BD8
void idAIEventManager::RemoveEntityEventsOfType(
        const idEntity* const entity,
        const idAIEvent::aiEventClass_t eventClass) {
    for (int index = eventList.Num() - 1; index >= 0; --index) {
        idAIEvent* const event = eventList[index];
        if (Tungsten_ResolveAIEventEntity(
                event->originator.GetSpawnId()) == entity
                && event->GetEventClass() == eventClass) {
            RemoveEvent(index);
        }
    }
}

// Retail symbol: ?EnableEvents@idAIEventManager@@QAAXPBVidEntity@@H_N@Z
// EA: 0x82A43C90, RVA: 0x00A43C90
void idAIEventManager::EnableEvents(const idEntity* const entity,
        const int eventClassFlags, const bool enable) {
    for (int index = eventList.Num() - 1; index >= 0; --index) {
        idAIEvent* const event = eventList[index];
        if (Tungsten_ResolveAIEventEntity(
                event->originator.GetSpawnId()) == entity
                && (event->GetEventClass() & eventClassFlags) != 0) {
            event->enabled = enable;
        }
    }
}

// Retail symbol: ?MapShutdown@idAIEventManager@@QAAXXZ
// EA: 0x82A43D50, RVA: 0x00A43D50
void idAIEventManager::MapShutdown() {
    for (int index = 0; index < eventList.Num(); ++index) {
        idAIEvent* const event = eventList[index];
        if (event != nullptr) {
            idAIEventPool* const pool =
                FindPoolForEventDecl(event->eventDecl);
            if (pool != nullptr) {
                pool->FreeEvent(event);
            }
        }
    }
    eventList.ClearFree();

    for (int index = 0; index < eventPools.Num(); ++index) {
        delete eventPools[index];
    }
    eventPools.ClearFree();
    receivers.ClearFree();
    eventHash.Clear();
}

// Retail symbol: ??1idAIEventManager@@QAA@XZ
// EA: 0x82A43EB0, RVA: 0x00A43EB0
idAIEventManager::~idAIEventManager() {
    MapShutdown();
}

// Retail symbol: ?SetEventInstigator@idAIEventManager@@QAAXAAV?$idHandle@HW4invalidAIEvent_t@@$0?0@@PBVidEntity@@@Z
// EA: 0x82A43FB8, RVA: 0x00A43FB8
void idAIEventManager::SetEventInstigator(idAIEventHandle& handle,
        const idEntity* const instigator) {
    idAIEvent* const event = GetEvent(handle);
    if (event != nullptr) {
        event->instigator.SetSpawnId(
            Tungsten_GetAIEventEntitySpawnId(instigator));
    }
}

// Retail symbol: ?AddPool@idAIEventManager@@AAAPAVidAIEventPool@@PBVidDeclAiEvent@@@Z
// EA: 0x82A44040, RVA: 0x00A44040
idAIEventPool* idAIEventManager::AddPool(
        const idDeclAiEvent* const eventDecl) {
    if (eventDecl == nullptr || eventDecl->initialPoolSize <= 0) {
        return nullptr;
    }
    idAIEventPool* pool = FindPoolForEventDecl(eventDecl);
    if (pool == nullptr) {
        const idTypeInfo* const eventType = GetEventType(eventDecl);
        if (eventType == nullptr) {
            return nullptr;
        }
        pool = new idAIEventPool(eventType);
        if (eventPools.Append(pool) < 0) {
            delete pool;
            return nullptr;
        }
    }
    pool->initialPoolSize += eventDecl->initialPoolSize;
    return pool;
}

// Retail symbol: ?Init@idAIEventManager@@QAAXXZ
// EA: 0x82A44140, RVA: 0x00A44140
void idAIEventManager::Init() {
    const int declarationCount = Tungsten_GetAIEventDeclCount();
    for (int index = 0; index < declarationCount; ++index) {
        const idDeclAiEvent* const declaration =
            Tungsten_GetAIEventDecl(index);
        if (declaration != nullptr) {
            AddPool(declaration);
        }
    }
    for (int index = 0; index < eventPools.Num(); ++index) {
        if (eventPools[index] != nullptr) {
            eventPools[index]->AllocInitialPool();
        }
    }
    std::sort(eventPools.Ptr(), eventPools.Ptr() + eventPools.Num(),
        [](const idAIEventPool* const left,
                const idAIEventPool* const right) {
            if (left == nullptr) {
                return right != nullptr;
            }
            return right != nullptr
                && left->NumAllocatedEvents()
                    < right->NumAllocatedEvents();
        });
}

// Retail symbol: ?AllocEvent@idAIEventManager@@AAAPAVidAIEvent@@PBVidDeclAiEvent@@@Z
// EA: 0x82A44268, RVA: 0x00A44268
idAIEvent* idAIEventManager::AllocEvent(
        const idDeclAiEvent* const eventDecl) {
    idAIEventPool* pool = FindPoolForEventDecl(eventDecl);
    if (pool == nullptr) {
        pool = AddPool(eventDecl);
    }
    return pool != nullptr ? pool->AllocEvent() : nullptr;
}

// Retail symbol: ?UpdateEvents@idAIEventManager@@QAAXH@Z
// EA: 0x82A442C0, RVA: 0x00A442C0
void idAIEventManager::UpdateEvents(const int currentTime) {
    idAIEventManagerRuntimeState runtimeState;
    Tungsten_GetAIEventManagerRuntimeState(runtimeState);
    const int showEvents = runtimeState.debugLevel > 0
        ? runtimeState.showEvents : 0;

    for (int index = eventList.Num() - 1; index >= 0; --index) {
        idAIEvent* const event = eventList[index];
        if (currentTime >= event->startTime && event->enabled) {
            if (EventHasExpired(event, currentTime)
                    || event->Update(currentTime)
                        == idAIEvent::AIUPDATE_REMOVE) {
                RemoveEvent(index);
            } else if (showEvents > 0 && showEvents < 3) {
                DrawEventDebug(event, showEvents, currentTime);
            }
        }
    }

    for (int receiverIndex = receivers.Num() - 1;
            receiverIndex >= 0; --receiverIndex) {
        idEntity* const receiver = const_cast<idEntity*>(
            Tungsten_ResolveAIEventEntity(
                receivers[receiverIndex].GetSpawnId()));
        if (receiver == nullptr) {
            receivers.RemoveIndexFast(receiverIndex);
            continue;
        }
        if (!Tungsten_CanReceiveAIEvents(receiver, currentTime)) {
            continue;
        }
        for (int eventIndex = 0; eventIndex < eventList.Num();
                ++eventIndex) {
            idAIEvent* const event = eventList[eventIndex];
            if (currentTime < event->startTime
                    || EventHasExpired(event, currentTime)) {
                continue;
            }
            if (Tungsten_ResolveAIEventEntity(
                    event->originator.GetSpawnId()) != receiver
                    && Tungsten_RespondsToAIEvent(receiver, event)
                    && event->InternalIsTouching(
                        receiver, currentTime)) {
                Tungsten_OnAIEvent(receiver, event);
            }
        }
    }
}

// Retail symbol: ?AddEvent@idAIEventManager@@AAAPAVidAIEvent@@PBVidDeclAiEvent@@HH@Z
// EA: 0x82A44688, RVA: 0x00A44688
idAIEvent* idAIEventManager::AddEvent(
        const idDeclAiEvent* const eventDecl,
        const int currentTime, const int delay) {
    idAIEventManagerRuntimeState runtimeState;
    Tungsten_GetAIEventManagerRuntimeState(runtimeState);
    if ((runtimeState.stopTime && runtimeState.clientFrameCount > 10)
            || eventDecl == nullptr
            || GetEventType(eventDecl) == nullptr) {
        return nullptr;
    }
    idAIEvent* const event = AllocEvent(eventDecl);
    if (event == nullptr) {
        return nullptr;
    }
    const int index = eventList.Append(event);
    if (index < 0) {
        idAIEventPool* const pool = FindPoolForEventDecl(eventDecl);
        if (pool != nullptr) {
            pool->FreeEvent(event);
        }
        return nullptr;
    }
    eventHash.Add(event->handle.value, index);
    event->startTime = currentTime + delay;
    return event;
}

// Retail symbol: ?AddEvent@idAIEventManager@@QAA?AV?$idHandle@HW4invalidAIEvent_t@@$0?0@@PBVidDeclAiEvent@@HPBVidEntity@@1ABVidVec3@@H@Z
// EA: 0x82A44958, RVA: 0x00A44958
idAIEventHandle idAIEventManager::AddEvent(
        const idDeclAiEvent* const eventDecl, const int currentTime,
        const idEntity* const originator,
        const idEntity* const instigator, const idVec3& origin,
        const int delay) {
    idAIEvent* const event = AddEvent(eventDecl, currentTime, delay);
    if (event == nullptr) {
        return idAIEventHandle(-1);
    }

    idVec3 eventOrigin = origin;
    if (eventDecl->attached) {
        const int spawnId =
            Tungsten_GetAIEventEntitySpawnId(originator);
        Tungsten_GetAIEventEntityOrigin(spawnId, eventOrigin);
    }
    event->Init(eventDecl, originator, instigator, eventOrigin);

    idAIEventManagerRuntimeState runtimeState;
    Tungsten_GetAIEventManagerRuntimeState(runtimeState);
    if (runtimeState.printEvents > 0) {
        Tungsten_AIEventManagerReportEvent(event, currentTime);
    }
    if (runtimeState.debugLevel > 0 && runtimeState.showEvents > 2) {
        DrawEventDebug(event, runtimeState.showEvents, currentTime);
    }
    return event->handle;
}

// Retail symbol: ?RemoveEvent@idAIEventManager@@QAAXABV?$idHandle@HW4invalidAIEvent_t@@$0?0@@@Z
// EA: 0x82A44B88, RVA: 0x00A44B88
void idAIEventManager::RemoveEvent(const idAIEventHandle& handle) {
    for (int index = eventList.Num() - 1; index >= 0; --index) {
        if (eventList[index]->handle == handle) {
            RemoveEvent(index);
            return;
        }
    }
}

// Retail symbol: ?AddReceiver@idAIEventManager@@QAAXPAVidEntity@@@Z
// EA: 0x82A44CA0, RVA: 0x00A44CA0
void idAIEventManager::AddReceiver(idEntity* const receiver) {
    idEntityPtr<idEntity> receiverPtr;
    receiverPtr.SetSpawnId(Tungsten_GetAIEventEntitySpawnId(receiver));
    for (int index = 0; index < receivers.Num(); ++index) {
        if (receivers[index].GetSpawnId()
                == receiverPtr.GetSpawnId()) {
            return;
        }
    }
    receivers.Append(receiverPtr);
}
