#pragma once

#include "../../../shared/idlib/containers/list.h"
#include "../../../shared/idlib/text/str.h"
#include "../entities/entityptr.h"

class idEntity;

class idDeclAIInteraction {
public:
    enum interactionEvent_t : int {
        IEV_ACTIONSCRIPT = 0,
        IEV_MAX = 1
    };

    struct eventData_t {
        interactionEvent_t type;
        int timeMS;
        int durationMS;
        int actorIndex;
        idList<int, 5> actionScript;

        eventData_t()
            : type(IEV_MAX), timeMS(0), durationMS(0), actorIndex(-1),
              actionScript(0) {}
    };

    idDeclAIInteraction();
    virtual ~idDeclAIInteraction() = default;

    idList<eventData_t, 5> events;
    idStr name;
};

class idAIInteraction {
public:
    idAIInteraction();

    void Spawn();
    void BeginInteraction(idEntity* activatorEntity);
    void EndInteraction();
    virtual void Think();
    virtual void OnActivate(idEntity* activatorEntity);

    void SetName(const char* value) { name = value; }
    void AddTargetSpawnId(int spawnId) {
        targets.Append(idEntityPtr<idEntity>(spawnId));
    }

    int startTime;
    const idDeclAIInteraction* interactionDecl;
    int nextEvent;
    idEntityPtr<idEntity> activator;
    idList<idEntityPtr<idEntity>, 5> targets;
    idStr name;
};

int Tungsten_GetAIInteractionMilliseconds();
int Tungsten_GetEntitySpawnId(const idEntity* entity);
void Tungsten_SetAIInteractionThinkActive(
    idAIInteraction* interaction, bool active);
void Tungsten_SetAIInteractionCurrent(
    int targetSpawnId, idAIInteraction* interaction, bool active);
bool Tungsten_StartAIInteractionAction(
    int targetSpawnId, const idDeclAIInteraction::eventData_t& eventData,
    idAIInteraction* executor, int activatorSpawnId, int currentTime);
void Tungsten_AIInteractionWarning(
    const char* message, const char* name, int eventIndex, int actorIndex);
void Tungsten_AIInteractionError(
    const char* message, const char* name, int eventIndex);
