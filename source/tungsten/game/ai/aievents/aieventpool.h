#pragma once

#include "../../../../shared/idlib/containers/list.h"

class idAIEvent;
class idTypeInfo;

class idAIEventPool {
public:
    idAIEventPool();
    explicit idAIEventPool(const idTypeInfo* eventType);
    virtual ~idAIEventPool();

    virtual idTypeInfo* GetType() { return nullptr; }

    idAIEvent* AllocEvent();
    void FreeEvent(idAIEvent* event);
    void AllocInitialPool();
    unsigned int GetSize() const;

    int NumFreeEvents() const { return freeEvents.Num(); }
    int NumAllocatedEvents() const { return freeEvents.NumAllocated(); }

    int initialPoolSize;
    const idTypeInfo* eventType;

private:
    void Free();

    idList<idAIEvent*, 5> freeEvents;
};
