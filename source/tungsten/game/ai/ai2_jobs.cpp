#include "ai2_jobs.h"

#include <cstdarg>
#include <cstdio>

namespace {

const char* SafeName(const char* text) {
    return text != nullptr ? text : "";
}

const char* JobName(const idDeclJob* job) {
    return job != nullptr ? SafeName(Tungsten_GetAI2JobDeclName(*job)) : "";
}

void LogMissingVoice(const char* label, const idDeclJob* job) {
    idAI2::Job_DebugPrintf("Job '%s' missing %s VO.", JobName(job), label);
}

} // namespace

// Retail symbol: ?Job_DebugPrintf@idAI2@@SAXPBDZZ
// EA: 0x82A384A8, RVA: 0x00A384A8
void idAI2::Job_DebugPrintf(const char* format, ...) {
    if (!Tungsten_IsAI2JobDebugEnabled()) {
        return;
    }
    char text[2048];
    va_list arguments;
    va_start(arguments, format);
    std::vsnprintf(text, sizeof(text), format != nullptr ? format : "",
        arguments);
    va_end(arguments);
    text[sizeof(text) - 1] = '\0';
    Tungsten_PrintAI2JobDebug(text);
}

// Retail symbol: ?Job_Approach@idAI2@@QAAPBVidDeclVoiceOver@@PAVidEntity@@_N@Z
// EA: 0x82A38510, RVA: 0x00A38510
const idDeclVoiceOver* idAI2::Job_Approach(
        idEntity* playerEntity, const bool playVoiceOver) {
    idPlayer* const player = Tungsten_CastAI2JobPlayer(playerEntity);
    idAI2JobInteractionRuntime runtime{};
    if (player == nullptr
        || !Tungsten_GetAI2JobInteractionRuntime(*this, runtime)) {
        return nullptr;
    }

    const bool approachAlreadyPlayed = Tungsten_GetAI2JobApproachPlayed(
        *player, *runtime.declaration, runtime.interactionNumber);
    const idDeclVoiceOver* selectedVoice = nullptr;
    if (approachAlreadyPlayed) {
        selectedVoice = runtime.secondaryApproachVoice;
        if (selectedVoice == nullptr) {
            Job_DebugPrintf("'%s': no secondary approach VO.\n",
                SafeName(Tungsten_GetAI2JobAIName(*this)));
            return nullptr;
        }
        Job_DebugPrintf("'%s': playing secondary approach VO: %s.\n",
            SafeName(Tungsten_GetAI2JobAIName(*this)),
            SafeName(Tungsten_GetAI2JobVoiceName(*selectedVoice)));
    } else {
        selectedVoice = runtime.approachVoice;
        if (selectedVoice != nullptr) {
            Job_DebugPrintf("'%s': playing approach VO: %s.\n",
                SafeName(Tungsten_GetAI2JobAIName(*this)),
                SafeName(Tungsten_GetAI2JobVoiceName(*selectedVoice)));
        } else {
            Job_DebugPrintf("'%s': no approach VO.\n",
                SafeName(Tungsten_GetAI2JobAIName(*this)));
        }

        if (runtime.job != nullptr && runtime.giveAndCompleteOnApproach) {
            Job_DebugPrintf(
                "'%s': completing Job because of giveAndCompleteOnApproach %s. (well after the vo...)\n",
                SafeName(Tungsten_GetAI2JobAIName(*this)),
                JobName(runtime.job));
            Tungsten_SetAI2SavedCompleteJob(*this, runtime.job);
        }
        Tungsten_SetAI2JobApproachPlayed(*player, *runtime.declaration,
            runtime.interactionNumber, true);
    }

    if (selectedVoice != nullptr && playVoiceOver) {
        // Retail passes approachVO here even on the secondary-approach path.
        if (runtime.approachVoice != nullptr) {
            Tungsten_PlayAI2JobVoice(
                *this, *runtime.approachVoice, AIVOICEPRIORITY_MED);
        }
    }
    return selectedVoice;
}

// Retail symbol: ?Job_Offer@idAI2@@QAAPBVidDeclVoiceOver@@PAVidEntity@@_N@Z
// EA: 0x82A386A8, RVA: 0x00A386A8
const idDeclVoiceOver* idAI2::Job_Offer(
        idEntity* playerEntity, const bool playVoiceOver) {
    idPlayer* const player = Tungsten_CastAI2JobPlayer(playerEntity);
    idAI2JobInteractionRuntime runtime{};
    if (player == nullptr
        || !Tungsten_GetAI2JobInteractionRuntime(*this, runtime)
        || runtime.job == nullptr) {
        return nullptr;
    }

    if (playVoiceOver) {
        if (runtime.offerVoice != nullptr) {
            Tungsten_PlayAI2JobVoice(
                *this, *runtime.offerVoice, AIVOICEPRIORITY_MED);
            Job_DebugPrintf("'%s': playing job offer VO.\n",
                SafeName(Tungsten_GetAI2JobAIName(*this)));
        } else {
            LogMissingVoice("job offer", runtime.job);
        }
    }
    Tungsten_SetAI2JobOfferPlayed(*player, *runtime.declaration,
        runtime.interactionNumber, true);
    return runtime.offerVoice;
}

// Retail symbol: ?Job_MessageVO@idAI2@@QAAPBVidDeclVoiceOver@@PAVidEntity@@_N1@Z
// EA: 0x82A38778, RVA: 0x00A38778
const idDeclVoiceOver* idAI2::Job_MessageVO(idEntity* playerEntity,
        const bool playVoiceOver, const bool checkAIType) {
    idPlayer* const player = Tungsten_CastAI2JobPlayer(playerEntity);
    idAI2JobInteractionRuntime runtime{};
    if (player == nullptr
        || !Tungsten_GetAI2JobInteractionRuntime(*this, runtime)) {
        return nullptr;
    }

    if (playVoiceOver) {
        if (runtime.messageVoice != nullptr) {
            Tungsten_PlayAI2JobVoice(
                *this, *runtime.messageVoice, AIVOICEPRIORITY_HIGH);
            Job_DebugPrintf("'%s': playing message VO.\n",
                SafeName(Tungsten_GetAI2JobAIName(*this)));
        } else {
            Job_DebugPrintf("Interaction '%s' missing message VO.",
                SafeName(Tungsten_GetAI2JobInteractionDeclName(
                    *runtime.declaration)));
        }
    }

    if (runtime.messageTriggerEntityName != nullptr
        && runtime.messageTriggerEntityName[0] != '\0'
        && !runtime.messageTriggerPostMessage) {
        const char* activatedName = nullptr;
        if (Tungsten_FindAndActivateAI2JobTrigger(
                runtime.messageTriggerEntityName, *player, activatedName)) {
            Job_DebugPrintf("Interaction '%s' triggering entity %s.",
                SafeName(Tungsten_GetAI2JobInteractionDeclName(
                    *runtime.declaration)), SafeName(activatedName));
        } else {
            Job_DebugPrintf(
                "Interaction '%s' could not find trigger entity %s.",
                SafeName(Tungsten_GetAI2JobInteractionDeclName(
                    *runtime.declaration)), runtime.messageTriggerEntityName);
        }
    }

    if (runtime.messageExpiresInteraction
        && (!checkAIType || !Tungsten_IsAI2JobMerchant(*this, *player))) {
        Tungsten_SetAI2JobOfferPlayed(*player, *runtime.declaration,
            runtime.interactionNumber, true);
    }
    return runtime.messageVoice;
}

// Retail symbol: ?Job_Complete@idAI2@@QAAPBVidDeclVoiceOver@@PAVidEntity@@_N@Z
// EA: 0x82A38900, RVA: 0x00A38900
const idDeclVoiceOver* idAI2::Job_Complete(
        idEntity* playerEntity, const bool playVoiceOver) {
    idAI2JobInteractionRuntime runtime{};
    if (Tungsten_CastAI2JobPlayer(playerEntity) == nullptr
        || !Tungsten_GetAI2JobInteractionRuntime(*this, runtime)) {
        return nullptr;
    }
    if (runtime.completeVoice != nullptr) {
        Job_DebugPrintf("'%s': playing job complete VO.\n",
            SafeName(Tungsten_GetAI2JobAIName(*this)));
    } else {
        LogMissingVoice("job complete", runtime.job);
    }
    Tungsten_SetAI2SavedCompleteJob(*this, runtime.job);
    if (runtime.completeVoice != nullptr && playVoiceOver) {
        Tungsten_PlayAI2JobVoice(
            *this, *runtime.completeVoice, AIVOICEPRIORITY_MED);
    }
    return runtime.completeVoice;
}

// Retail symbol: ?Job_Failed@idAI2@@QAAPBVidDeclVoiceOver@@PAVidEntity@@_N@Z
// EA: 0x82A389C0, RVA: 0x00A389C0
const idDeclVoiceOver* idAI2::Job_Failed(
        idEntity* playerEntity, const bool playVoiceOver) {
    idAI2JobInteractionRuntime runtime{};
    if (Tungsten_CastAI2JobPlayer(playerEntity) == nullptr
        || !Tungsten_GetAI2JobInteractionRuntime(*this, runtime)) {
        return nullptr;
    }
    if (runtime.failedVoice == nullptr) {
        LogMissingVoice("job failed", runtime.job);
    } else if (playVoiceOver) {
        Tungsten_PlayAI2JobVoice(
            *this, *runtime.failedVoice, AIVOICEPRIORITY_MED);
        Job_DebugPrintf("'%s': playing job failed VO.\n",
            SafeName(Tungsten_GetAI2JobAIName(*this)));
    }
    Tungsten_AI2PlayerInteractionDone(*this, false);
    return runtime.failedVoice;
}

// Retail symbol: ?Job_InProgress@idAI2@@QAAPBVidDeclVoiceOver@@PAVidEntity@@_N@Z
// EA: 0x82A38A70, RVA: 0x00A38A70
const idDeclVoiceOver* idAI2::Job_InProgress(
        idEntity* playerEntity, const bool playVoiceOver) {
    idAI2JobInteractionRuntime runtime{};
    if (Tungsten_CastAI2JobPlayer(playerEntity) == nullptr
        || !Tungsten_GetAI2JobInteractionRuntime(*this, runtime)) {
        return nullptr;
    }
    if (runtime.inProgressVoice != nullptr) {
        if (playVoiceOver) {
            Tungsten_PlayAI2JobVoice(
                *this, *runtime.inProgressVoice, AIVOICEPRIORITY_MED);
            Job_DebugPrintf("'%s': playing job in progress VO.\n",
                SafeName(Tungsten_GetAI2JobAIName(*this)));
        }
    } else if (runtime.job != nullptr) {
        LogMissingVoice("job in progress", runtime.job);
    } else {
        Job_DebugPrintf("No Job on DeliverJobInProgressVO!");
    }
    return runtime.inProgressVoice;
}

// Retail symbol: ?Job_Accepted@idAI2@@QAAPBVidDeclVoiceOver@@PAVidEntity@@_N@Z
// EA: 0x82A38B40, RVA: 0x00A38B40
const idDeclVoiceOver* idAI2::Job_Accepted(
        idEntity* playerEntity, const bool playVoiceOver) {
    idPlayer* const player = Tungsten_CastAI2JobPlayer(playerEntity);
    idAI2JobInteractionRuntime runtime{};
    if (player == nullptr
        || !Tungsten_GetAI2JobInteractionRuntime(*this, runtime)) {
        return nullptr;
    }
    Tungsten_SetAI2JobPlayerOfferChoiceUnknown(*player);

    if (runtime.job != nullptr
        && Tungsten_IsAI2JobReadyToComplete(*player, *runtime.job, *this)) {
        Tungsten_SetAI2JobReadyToTurnIn(*player, *runtime.job,
            false, true, false, false);
        Tungsten_MarkAI2JobDisplayAlreadyCompleted(*player, *runtime.job);
        return nullptr;
    }

    if (runtime.job != nullptr) {
        if (runtime.acceptImmediately) {
            Tungsten_AcceptAI2Job(*player, *runtime.job, false, false);
        } else {
            Tungsten_SetAI2SavedAcceptJob(*this, runtime.job);
        }
    }

    if (runtime.acceptedByeVoice != nullptr) {
        if (playVoiceOver) {
            Tungsten_PlayAI2JobVoice(
                *this, *runtime.acceptedByeVoice, AIVOICEPRIORITY_HIGH);
            Job_DebugPrintf("'%s': playing job bye(accepted) VO.\n",
                SafeName(Tungsten_GetAI2JobAIName(*this)));
        }
    } else if (runtime.job != nullptr) {
        LogMissingVoice("job bye(accepted)", runtime.job);
    }
    return runtime.acceptedByeVoice;
}

// Retail symbol: ?Job_Declined@idAI2@@QAAPBVidDeclVoiceOver@@PAVidEntity@@_N@Z
// EA: 0x82A38CB0, RVA: 0x00A38CB0
const idDeclVoiceOver* idAI2::Job_Declined(
        idEntity* playerEntity, const bool playVoiceOver) {
    idPlayer* const player = Tungsten_CastAI2JobPlayer(playerEntity);
    idAI2JobInteractionRuntime runtime{};
    if (player == nullptr) {
        return nullptr;
    }
    Tungsten_SetAI2JobPlayerOfferChoiceUnknown(*player);
    if (!Tungsten_GetAI2JobInteractionRuntime(*this, runtime)) {
        return nullptr;
    }
    if (runtime.abortedVoice != nullptr) {
        if (playVoiceOver) {
            Tungsten_PlayAI2JobVoice(
                *this, *runtime.abortedVoice, AIVOICEPRIORITY_MED);
            Job_DebugPrintf("'%s': playing job aborted VO.\n",
                SafeName(Tungsten_GetAI2JobAIName(*this)));
        }
    } else {
        Tungsten_FadeAI2JobVoice(*this);
        Job_DebugPrintf("AI: '%s' no job abort vo",
            SafeName(Tungsten_GetAI2JobAIName(*this)));
    }
    return runtime.abortedVoice;
}

// Retail symbol: ?Job_CompleteSavedJob@idAI2@@QAA_NPAVidPlayer@@@Z
// EA: 0x82A38D78, RVA: 0x00A38D78
bool idAI2::Job_CompleteSavedJob(idPlayer* player) {
    const idDeclJob* const job = Tungsten_GetAI2SavedCompleteJob(*this);
    if (job == nullptr || player == nullptr) {
        return false;
    }
    Tungsten_CompleteAI2Job(*player, *job, false, true, false);
    Tungsten_SetAI2SavedCompleteJob(*this, nullptr);
    return true;
}

// Retail symbol: ?Job_AcceptSavedJob@idAI2@@QAA_NPAVidPlayer@@@Z
// EA: 0x82A38DF8, RVA: 0x00A38DF8
bool idAI2::Job_AcceptSavedJob(idPlayer* player) {
    const idDeclJob* const job = Tungsten_GetAI2SavedAcceptJob(*this);
    if (job == nullptr || player == nullptr) {
        return false;
    }
    Tungsten_AcceptAI2Job(*player, *job, false, false);
    Tungsten_SetAI2SavedAcceptJob(*this, nullptr);
    return true;
}

// Retail symbol: ?Job_GetPlayerInteractionState@idAI2@@QBA?AW4playerInteractionState_t@@PBVidPlayer@@@Z
// EA: 0x82A38E70, RVA: 0x00A38E70
playerInteractionState_t idAI2::Job_GetPlayerInteractionState(
        const idPlayer* player) const {
    idAI2JobInteractionRuntime runtime{};
    if (!Tungsten_GetAI2JobInteractionRuntime(*this, runtime)
        || runtime.declaration == nullptr) {
        return PISTATE_INACTIVE;
    }
    if (runtime.job != nullptr
        && Tungsten_IsAI2JobInProgress(*player, *runtime.job)) {
        return PISTATE_JOB_IN_PROGRESS;
    }
    if (Tungsten_GetAI2JobOfferPlayed(*player, *runtime.declaration,
            runtime.interactionNumber)) {
        return PISTATE_JOB_SETUP_PLAYED;
    }
    return Tungsten_GetAI2JobApproachPlayed(*player, *runtime.declaration,
            runtime.interactionNumber)
        ? PISTATE_APPROACH_PLAYED : PISTATE_INACTIVE;
}

// Retail symbol: ?Job_PlayerLeft@idAI2@@QAAPBVidDeclVoiceOver@@PAVidEntity@@_N@Z
// EA: 0x82A38F38, RVA: 0x00A38F38
const idDeclVoiceOver* idAI2::Job_PlayerLeft(
        idEntity* playerEntity, const bool playVoiceOver) {
    idPlayer* const player = Tungsten_CastAI2JobPlayer(playerEntity);
    if (player == nullptr) {
        return nullptr;
    }
    Job_CompleteSavedJob(player);
    Job_AcceptSavedJob(player);

    idAI2JobInteractionRuntime runtime{};
    if (!Tungsten_GetAI2JobInteractionRuntime(*this, runtime)) {
        return nullptr;
    }
    Tungsten_FadeAI2JobVoice(*this);
    Tungsten_ResetAI2JobFace(*this);

    const idDeclVoiceOver* abortedVoice = nullptr;
    if (Tungsten_GetAI2JobNextVoiceTime(*this)
        > Tungsten_GetAI2JobGameMilliseconds()) {
        abortedVoice = runtime.abortedVoice;
        if (abortedVoice != nullptr && playVoiceOver) {
            Tungsten_PlayAI2JobVoice(
                *this, *abortedVoice, AIVOICEPRIORITY_MED);
        }
    }
    Tungsten_AI2PlayerInteractionDone(*this, true);
    return abortedVoice;
}

// Retail symbol: ?Job_End@idAI2@@QAAPBVidDeclVoiceOver@@PAVidEntity@@_N@Z
// EA: 0x82A39038, RVA: 0x00A39038
const idDeclVoiceOver* idAI2::Job_End(
        idEntity* playerEntity, const bool playVoiceOver) {
    idPlayer* const player = Tungsten_CastAI2JobPlayer(playerEntity);
    idAI2JobInteractionRuntime runtime{};
    if (player == nullptr
        || !Tungsten_GetAI2JobInteractionRuntime(*this, runtime)) {
        return nullptr;
    }

    const char* const controlName = Tungsten_GetAI2JobPlayerControlName(*player);
    if (controlName != nullptr) {
        char warning[1024];
        std::snprintf(warning, sizeof(warning),
            "early out of Job_End because player is already controled by something.  %s",
            controlName);
        warning[sizeof(warning) - 1] = '\0';
        Tungsten_WarnAI2Job(warning);
        if (runtime.job != nullptr && Tungsten_AI2JobShowsGUI(*runtime.job)) {
            Tungsten_SetAI2JobPlayerOfferChoiceDeclined(*player);
        }
        return nullptr;
    }

    const idDeclJob* const completedJob =
        Tungsten_FindAI2CompletedJob(*player, *this);
    if (completedJob != nullptr) {
        Tungsten_SetAI2SavedCompleteJob(*this, completedJob);
    }
    if (runtime.job == nullptr) {
        return nullptr;
    }
    if (Tungsten_AI2JobShowsGUI(*runtime.job)) {
        Tungsten_SetAI2JobGuiInteractionEntity(*player, *this);
    }

    if (playVoiceOver) {
        if (runtime.endVoice != nullptr) {
            Tungsten_PlayAI2JobVoice(
                *this, *runtime.endVoice, AIVOICEPRIORITY_MED);
            Job_DebugPrintf("'%s': playing job end VO.\n",
                SafeName(Tungsten_GetAI2JobAIName(*this)));
        } else {
            LogMissingVoice("job end", runtime.job);
        }
    }
    Tungsten_SetAI2JobOfferPlayed(*player, *runtime.declaration,
        runtime.interactionNumber, true);
    Tungsten_ClearAI2TriggeredInteraction(*this);
    Tungsten_SetAI2JobInteractionUsable(*this, false);
    Tungsten_OfferAI2JobInteraction(*player, *runtime.interaction, *this);
    return runtime.endVoice;
}
