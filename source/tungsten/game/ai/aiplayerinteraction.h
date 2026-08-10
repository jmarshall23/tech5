#pragma once

#include "idlib/containers/list.h"
#include "idlib/text/str.h"

class idAnimatedEntity;
class idDeclAIPlayerInteraction;
class idDeclGameStateInt;
class idDeclInventory;
class idDeclJob;
class idPlayer;
struct aiPlayerInteraction_t;

enum aiInteractionConditionType_t : int {
    INTERACTIONCONDITION_NONE = 0,
    INTERACTIONCONDITION_JOB = 1,
    INTERACTIONCONDITION_ITEM = 2,
    INTERACTIONCONDITION_GAMESTATEINT = 3,
    INTERACTIONCONDITION_FORCEFALSE = 4,
    INTERACTIONCONDITION_FORCETRUE = 5
};

enum aiInteractionTestJobStatus_t : int {
    INTERACTIONTEST_JOBSTATUS_ACCEPTED = 0,
    INTERACTIONTEST_JOBSTATUS_READYTOTURNIN = 1,
    INTERACTIONTEST_JOBSTATUS_COMPLETED = 2
};

struct idAIInteractionCondition {
    idAIInteractionCondition();

    aiInteractionConditionType_t condition;
    idStr jobName;
    aiInteractionTestJobStatus_t jobStatus;
    const idDeclInventory* inventoryDecl;
    const idDeclGameStateInt* gameStateIntDecl;
    int count;
};

using idAIInteractionConditionList =
    idList<idAIInteractionCondition, 5>;

struct idAIInteractionJobRuntime {
    bool exists;
    bool completed;
    bool readyToTurnIn;
    bool accepted;
    bool readyToTurnInUnknown;
    bool available;
};

struct idAIPlayerInteractionRuntime {
    const idDeclJob* interactionJob;
    bool messageExpiresInteraction;
    bool expiredOnAny;
    bool hasJobCompleteVoice;
    const idAIInteractionConditionList* isAvailableConditions;
    const idAIInteractionConditionList* hasExpiredConditions;
    const idAIInteractionConditionList* canBeClosedConditions;
};

class idAIPlayerInteraction {
public:
    idAIPlayerInteraction();

    bool Init(const idAnimatedEntity* owner,
        const idDeclAIPlayerInteraction* decl);
    const aiPlayerInteraction_t* GetInteraction(int index) const;
    int GetInteractionIndex(
        const aiPlayerInteraction_t* interaction) const;
    bool AnyInteractionConditionMet(
        const idAIInteractionConditionList& conditions,
        const idPlayer* player, bool passOnEmpty) const;
    bool InteractionConditionMet(
        const idAIInteractionConditionList& conditions,
        const idPlayer* player, bool passOnEmpty) const;
    bool InteractionHasExpired(
        const aiPlayerInteraction_t* interaction,
        const idPlayer* player,
        const idDeclAIPlayerInteraction* interactionDecl,
        int interactionNumber) const;
    bool InteractionCanBeClosed(
        const aiPlayerInteraction_t* interaction,
        const idPlayer* player) const;
    const aiPlayerInteraction_t* FindInteraction(
        const idPlayer* player, bool modifyState,
        idStr* debugString = nullptr) const;

    const idDeclAIPlayerInteraction* decl;
    const idAnimatedEntity* owner;
};

int Tungsten_GetAIPlayerInteractionCount(
    const idDeclAIPlayerInteraction& decl);
const aiPlayerInteraction_t* Tungsten_GetAIPlayerInteractionAt(
    const idDeclAIPlayerInteraction& decl, int index);
bool Tungsten_GetAIPlayerInteractionRuntime(
    const aiPlayerInteraction_t& interaction,
    idAIPlayerInteractionRuntime& runtime);
bool Tungsten_GetAIInteractionJobByName(const idPlayer& player,
    const char* jobName, idAIInteractionJobRuntime& runtime);
bool Tungsten_GetAIInteractionJobByDecl(const idPlayer& player,
    const idDeclJob& job, idAIInteractionJobRuntime& runtime);
bool Tungsten_GetAIInteractionInventoryCount(const idPlayer& player,
    const idDeclInventory& inventory, bool& found, int& count);
bool Tungsten_GetAIInteractionGameStateInt(const idPlayer& player,
    const idDeclGameStateInt& gameState, int& value);
bool Tungsten_GetAIInteractionJobOfferPlayed(const idPlayer& player,
    const idDeclAIPlayerInteraction& decl, int interactionNumber);
bool Tungsten_IsAIInteractionPlayerInVehicle(const idPlayer& player);
void Tungsten_WarnAIPlayerInteraction(const char* text);
