#include "aiinteraction.h"

// Retail symbol: ??0idAIInteraction@@QAA@XZ
// EA: 0x82A52088, RVA: 0x00A52088
idAIInteraction::idAIInteraction()
    : startTime(-1)
    , interactionDecl(nullptr)
    , nextEvent(-1)
    , activator()
    , targets(0)
    , name() {
}

// Retail symbol: ?Spawn@idAIInteraction@@QAAXXZ
// EA: 0x82A520E0, RVA: 0x00A520E0
void idAIInteraction::Spawn() {
    Tungsten_SetAIInteractionThinkActive(this, false);
    if (interactionDecl == nullptr) {
        Tungsten_AIInteractionWarning(
            "no interaction decl specified", name.c_str(), -1, -1);
        return;
    }

    int previousTime = 0;
    for (int index = 0; index < interactionDecl->events.Num(); ++index) {
        const idDeclAIInteraction::eventData_t& event =
            interactionDecl->events[index];
        if (event.type == idDeclAIInteraction::IEV_MAX) {
            Tungsten_AIInteractionError(
                "event has an invalid type", interactionDecl->name.c_str(),
                index);
            return;
        }
        if (event.timeMS < previousTime) {
            Tungsten_AIInteractionError(
                "events must be sorted by increasing time",
                interactionDecl->name.c_str(), index);
            return;
        }
        previousTime = event.timeMS;
    }
}

// Retail symbol: ?BeginInteraction@idAIInteraction@@AAAXPAVidEntity@@@Z
// EA: 0x82A521B0, RVA: 0x00A521B0
void idAIInteraction::BeginInteraction(idEntity* const activatorEntity) {
    if (interactionDecl == nullptr) {
        Tungsten_AIInteractionWarning(
            "no interaction decl specified", name.c_str(), -1, -1);
        return;
    }

    startTime = Tungsten_GetAIInteractionMilliseconds();
    nextEvent = 0;
    activator.SetSpawnId(activatorEntity != nullptr
        ? Tungsten_GetEntitySpawnId(activatorEntity) : 0x1FFF);
    Tungsten_SetAIInteractionThinkActive(this, true);
    for (int index = 0; index < targets.Num(); ++index) {
        Tungsten_SetAIInteractionCurrent(
            targets[index].GetSpawnId(), this, true);
    }
}

// Retail symbol: ?EndInteraction@idAIInteraction@@AAAXXZ
// EA: 0x82A52308, RVA: 0x00A52308
void idAIInteraction::EndInteraction() {
    for (int index = 0; index < targets.Num(); ++index) {
        Tungsten_SetAIInteractionCurrent(
            targets[index].GetSpawnId(), this, false);
    }
    activator.Invalidate();
    nextEvent = -1;
    startTime = -1;
    Tungsten_SetAIInteractionThinkActive(this, false);
}

// Retail symbol: ?Think@idAIInteraction@@UAAXXZ
// EA: 0x82A523D8, RVA: 0x00A523D8
void idAIInteraction::Think() {
    if (interactionDecl == nullptr || interactionDecl->events.IsEmpty()) {
        Tungsten_SetAIInteractionThinkActive(this, false);
        return;
    }
    if (nextEvent < 0 || nextEvent >= interactionDecl->events.Num()) {
        return;
    }

    const int currentTime = Tungsten_GetAIInteractionMilliseconds();
    const int elapsedTime = currentTime - startTime;
    while (nextEvent < interactionDecl->events.Num()) {
        const idDeclAIInteraction::eventData_t& event =
            interactionDecl->events[nextEvent];
        if (event.timeMS > elapsedTime) {
            return;
        }

        if (event.type == idDeclAIInteraction::IEV_ACTIONSCRIPT) {
            bool started = false;
            if (event.actorIndex >= 0 && event.actorIndex < targets.Num()) {
                started = Tungsten_StartAIInteractionAction(
                    targets[event.actorIndex].GetSpawnId(), event, this,
                    activator.GetSpawnId(), currentTime);
            }
            if (!started) {
                Tungsten_AIInteractionWarning(
                    "invalid actorIndex for action script",
                    interactionDecl->name.c_str(), nextEvent,
                    event.actorIndex);
            }
        }
        ++nextEvent;
    }
    EndInteraction();
}

// Retail symbol: ?OnActivate@idAIInteraction@@UAAXPAVidEntity@@@Z
// EA: 0x82A525E0, RVA: 0x00A525E0
void idAIInteraction::OnActivate(idEntity* const activatorEntity) {
    BeginInteraction(activatorEntity);
}

// Retail symbol: ??0idDeclAIInteraction@@QAA@XZ
// EA: 0x82A525F0, RVA: 0x00A525F0
idDeclAIInteraction::idDeclAIInteraction()
    : events(0)
    , name() {
}
