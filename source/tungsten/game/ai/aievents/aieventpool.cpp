#include "aieventpool.h"

#include "aievent.h"

idAIEvent* Tungsten_CreateAIEvent(const idTypeInfo* eventType);
void Tungsten_ResetAIEvent(idAIEvent* event);
void Tungsten_DestroyAIEvent(idAIEvent* event);
int Tungsten_GetAIEventSize(const idAIEvent* event);
const char* Tungsten_GetAIEventTypeName(const idTypeInfo* eventType);
void Tungsten_AIEventPoolExceeded(const char* className);

// Retail symbol: ?AllocEvent@idAIEventPool@@QAAPAVidAIEvent@@XZ
// EA: 0x82A44D40, RVA: 0x00A44D40
idAIEvent* idAIEventPool::AllocEvent() {
    idAIEvent* event = nullptr;
    if (!freeEvents.IsEmpty()) {
        event = freeEvents[freeEvents.Num() - 1];
        freeEvents.RemoveIndexFast(freeEvents.Num() - 1);
        Tungsten_ResetAIEvent(event);
    } else if (eventType != nullptr) {
        event = Tungsten_CreateAIEvent(eventType);
        Tungsten_AIEventPoolExceeded(
            Tungsten_GetAIEventTypeName(eventType));
    }
    return event;
}

// Retail symbol: ?GetSize@idAIEventPool@@QBAIXZ
// EA: 0x82A44E08, RVA: 0x00A44E08
unsigned int idAIEventPool::GetSize() const {
    unsigned int size = 4;
    for (int index = 0; index < freeEvents.Num(); ++index) {
        size += static_cast<unsigned int>(
            Tungsten_GetAIEventSize(freeEvents[index]));
    }
    return size;
}

// Retail symbol: ?Free@idAIEventPool@@AAAXXZ
// EA: 0x82A44E70, RVA: 0x00A44E70
void idAIEventPool::Free() {
    for (int index = 0; index < freeEvents.Num(); ++index) {
        Tungsten_DestroyAIEvent(freeEvents[index]);
    }
    freeEvents.ClearFree();
}

// Retail symbol: ??0idAIEventPool@@AAA@XZ
// EA: 0x82A44F20, RVA: 0x00A44F20
idAIEventPool::idAIEventPool()
    : initialPoolSize(0)
    , eventType(nullptr)
    , freeEvents(0) {
}

// Retail symbol: ??0idAIEventPool@@QAA@PBVidTypeInfo@@@Z
// EA: 0x82A44FC8, RVA: 0x00A44FC8
idAIEventPool::idAIEventPool(const idTypeInfo* const type)
    : initialPoolSize(0)
    , eventType(type)
    , freeEvents(0) {
}

// Retail symbol: ??1idAIEventPool@@UAA@XZ
// EA: 0x82A45070, RVA: 0x00A45070
idAIEventPool::~idAIEventPool() {
    Free();
}

// Retail symbol: ?AllocInitialPool@idAIEventPool@@QAAXXZ
// EA: 0x82A45180, RVA: 0x00A45180
void idAIEventPool::AllocInitialPool() {
    if (eventType == nullptr || initialPoolSize <= 0) {
        return;
    }
    if (!freeEvents.SetNum(initialPoolSize)) {
        return;
    }
    for (int index = 0; index < initialPoolSize; ++index) {
        freeEvents[index] = Tungsten_CreateAIEvent(eventType);
    }
}

// Retail symbol: ?FreeEvent@idAIEventPool@@QAAXPAVidAIEvent@@@Z
// EA: 0x82A45200, RVA: 0x00A45200
void idAIEventPool::FreeEvent(idAIEvent* const event) {
    freeEvents.Append(event);
}
