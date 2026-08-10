#pragma once

#include "ai2_interactions.h"

class idDeclAIPlayerInteraction;
class idDeclJob;
class idDeclVoiceOver;

enum aiVoicePriority_t : int {
    AIVOICEPRIORITY_NONE = 0,
    AIVOICEPRIORITY_LOW = 1,
    AIVOICEPRIORITY_MED = 2,
    AIVOICEPRIORITY_HIGH = 3,
    AIVOICEPRIORITY_PAIN = 4,
    AIVOICEPRIORITY_DEATH = 5
};

// Snapshot of the current aiPlayerInteraction_t and the declaration/list
// entries read by ai2_jobs.cpp.  The owning declarations remain opaque until
// their generated headers are replaced with reviewed source surfaces.
struct idAI2JobInteractionRuntime {
    const aiPlayerInteraction_t* interaction;
    const idDeclAIPlayerInteraction* declaration;
    int interactionNumber;
    const idDeclJob* job;
    bool giveAndCompleteOnApproach;
    bool acceptImmediately;
    bool messageExpiresInteraction;
    const char* messageTriggerEntityName;
    bool messageTriggerPostMessage;
    const idDeclVoiceOver* approachVoice;
    const idDeclVoiceOver* secondaryApproachVoice;
    const idDeclVoiceOver* offerVoice;
    const idDeclVoiceOver* messageVoice;
    const idDeclVoiceOver* completeVoice;
    const idDeclVoiceOver* failedVoice;
    const idDeclVoiceOver* inProgressVoice;
    const idDeclVoiceOver* acceptedByeVoice;
    const idDeclVoiceOver* abortedVoice;
    const idDeclVoiceOver* endVoice;
};

bool Tungsten_GetAI2JobInteractionRuntime(
    const idAI2& ai, idAI2JobInteractionRuntime& runtime);
idPlayer* Tungsten_CastAI2JobPlayer(idEntity* entity);
const char* Tungsten_GetAI2JobAIName(const idAI2& ai);
const char* Tungsten_GetAI2JobDeclName(const idDeclJob& job);
const char* Tungsten_GetAI2JobInteractionDeclName(
    const idDeclAIPlayerInteraction& declaration);
const char* Tungsten_GetAI2JobVoiceName(const idDeclVoiceOver& voice);

bool Tungsten_IsAI2JobDebugEnabled();
void Tungsten_PrintAI2JobDebug(const char* text);
void Tungsten_WarnAI2Job(const char* text);
void Tungsten_PlayAI2JobVoice(idAI2& ai,
    const idDeclVoiceOver& voice, aiVoicePriority_t priority);

bool Tungsten_GetAI2JobApproachPlayed(const idPlayer& player,
    const idDeclAIPlayerInteraction& declaration, int interactionNumber);
void Tungsten_SetAI2JobApproachPlayed(idPlayer& player,
    const idDeclAIPlayerInteraction& declaration, int interactionNumber,
    bool played);
bool Tungsten_GetAI2JobOfferPlayed(const idPlayer& player,
    const idDeclAIPlayerInteraction& declaration, int interactionNumber);
void Tungsten_SetAI2JobOfferPlayed(idPlayer& player,
    const idDeclAIPlayerInteraction& declaration, int interactionNumber,
    bool played);
bool Tungsten_IsAI2JobInProgress(
    const idPlayer& player, const idDeclJob& job);
bool Tungsten_IsAI2JobReadyToComplete(const idPlayer& player,
    const idDeclJob& job, const idAI2& npc);
void Tungsten_SetAI2JobReadyToTurnIn(idPlayer& player,
    const idDeclJob& job, bool completeTree, bool giveJobIfNeeded,
    bool hideIfGiven, bool force);
void Tungsten_MarkAI2JobDisplayAlreadyCompleted(
    idPlayer& player, const idDeclJob& job);
void Tungsten_AcceptAI2Job(idPlayer& player,
    const idDeclJob& job, bool completeTree, bool force);
void Tungsten_CompleteAI2Job(idPlayer& player,
    const idDeclJob& job, bool completeTree, bool giveJob, bool force);
const idDeclJob* Tungsten_FindAI2CompletedJob(
    const idPlayer& player, const idAI2& completionNPC);

const idDeclJob* Tungsten_GetAI2SavedCompleteJob(const idAI2& ai);
void Tungsten_SetAI2SavedCompleteJob(idAI2& ai, const idDeclJob* job);
const idDeclJob* Tungsten_GetAI2SavedAcceptJob(const idAI2& ai);
void Tungsten_SetAI2SavedAcceptJob(idAI2& ai, const idDeclJob* job);

void Tungsten_SetAI2JobPlayerOfferChoiceUnknown(idPlayer& player);
void Tungsten_SetAI2JobPlayerOfferChoiceDeclined(idPlayer& player);
bool Tungsten_IsAI2JobMerchant(const idAI2& ai, const idPlayer& player);
bool Tungsten_FindAndActivateAI2JobTrigger(
    const char* entityName, idPlayer& activator, const char*& activatedName);
void Tungsten_FadeAI2JobVoice(idAI2& ai);
void Tungsten_ResetAI2JobFace(idAI2& ai);
int Tungsten_GetAI2JobNextVoiceTime(const idAI2& ai);
int Tungsten_GetAI2JobGameMilliseconds();

const char* Tungsten_GetAI2JobPlayerControlName(const idPlayer& player);
bool Tungsten_AI2JobShowsGUI(const idDeclJob& job);
void Tungsten_SetAI2JobGuiInteractionEntity(
    idPlayer& player, const idAI2& ai);
void Tungsten_ClearAI2TriggeredInteraction(idAI2& ai);
void Tungsten_SetAI2JobInteractionUsable(idAI2& ai, bool usable);
void Tungsten_OfferAI2JobInteraction(idPlayer& player,
    const aiPlayerInteraction_t& interaction, idAI2& offeringAI);
