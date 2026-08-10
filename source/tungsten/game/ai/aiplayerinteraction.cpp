#include "aiplayerinteraction.h"

namespace {

bool JobConditionMet(const idAIInteractionJobRuntime& job,
        const aiInteractionTestJobStatus_t requiredStatus) {
    if (!job.exists) {
        return false;
    }
    switch (requiredStatus) {
    case INTERACTIONTEST_JOBSTATUS_COMPLETED:
        return job.completed;
    case INTERACTIONTEST_JOBSTATUS_READYTOTURNIN:
        return job.completed || job.readyToTurnIn
            || job.readyToTurnInUnknown;
    case INTERACTIONTEST_JOBSTATUS_ACCEPTED:
        return job.completed || job.readyToTurnIn || job.accepted
            || job.readyToTurnInUnknown;
    default:
        return false;
    }
}

void AppendDebug(idStr* const debugString,
        const char* const format, const int index) {
    if (debugString == nullptr) {
        return;
    }
    idStr line;
    line.Format(format, index);
    debugString->Append(line);
}

void AppendJobDebug(idStr* const debugString,
        const char* const format, const int index,
        const bool isOverride) {
    if (debugString == nullptr) {
        return;
    }
    idStr line;
    line.Format(format, index, isOverride ? 1 : 0);
    debugString->Append(line);
}

} // namespace

idAIInteractionCondition::idAIInteractionCondition()
    : condition(INTERACTIONCONDITION_NONE)
    , jobName()
    , jobStatus(INTERACTIONTEST_JOBSTATUS_ACCEPTED)
    , inventoryDecl(nullptr)
    , gameStateIntDecl(nullptr)
    , count(0) {
}

// Retail symbol: ?Init@idAIPlayerInteraction@@QAA_NPBVidAnimatedEntity@@PBVidDeclAIPlayerInteraction@@@Z
// EA: 0x82A5FBB8, RVA: 0x00A5FBB8
bool idAIPlayerInteraction::Init(const idAnimatedEntity* const newOwner,
        const idDeclAIPlayerInteraction* const newDecl) {
    owner = newOwner;
    decl = newDecl;
    return true;
}

// Retail symbol: ??0idAIPlayerInteraction@@QAA@XZ
// EA: 0x82A5FBD0, RVA: 0x00A5FBD0
idAIPlayerInteraction::idAIPlayerInteraction()
    : decl(nullptr)
    , owner(nullptr) {
}

// Retail symbol: ?GetInteraction@idAIPlayerInteraction@@QBAPBVaiPlayerInteraction_t@@H@Z
// EA: 0x82A5FBF0, RVA: 0x00A5FBF0
const aiPlayerInteraction_t* idAIPlayerInteraction::GetInteraction(
        const int index) const {
    return decl != nullptr
        ? Tungsten_GetAIPlayerInteractionAt(*decl, index) : nullptr;
}

// Retail symbol: ?GetInteractionIndex@idAIPlayerInteraction@@QBAHPBVaiPlayerInteraction_t@@@Z
// EA: 0x82A5FC08, RVA: 0x00A5FC08
int idAIPlayerInteraction::GetInteractionIndex(
        const aiPlayerInteraction_t* const interaction) const {
    if (decl == nullptr || interaction == nullptr) {
        return -1;
    }
    const int count = Tungsten_GetAIPlayerInteractionCount(*decl);
    for (int index = 0; index < count; ++index) {
        if (Tungsten_GetAIPlayerInteractionAt(*decl, index)
                == interaction) {
            return index;
        }
    }
    return -1;
}

// Retail symbol:
// ?AnyInteractionConditionMet@idAIPlayerInteraction@@QBA_NABV?$idList@VinteractionTestCondition_t@aiPlayerInteraction_t@@$04@@PBVidPlayer@@_N@Z
// EA: 0x82A5FC28, RVA: 0x00A5FC28
bool idAIPlayerInteraction::AnyInteractionConditionMet(
        const idAIInteractionConditionList& conditions,
        const idPlayer* const player, bool passOnEmpty) const {
    if (conditions.IsEmpty()) {
        return passOnEmpty;
    }
    if (player == nullptr) {
        return false;
    }
    for (int index = 0; index < conditions.Num(); ++index) {
        const idAIInteractionCondition& condition = conditions[index];
        switch (condition.condition) {
        case INTERACTIONCONDITION_JOB: {
            idAIInteractionJobRuntime job{};
            if (Tungsten_GetAIInteractionJobByName(
                    *player, condition.jobName.c_str(), job)
                && JobConditionMet(job, condition.jobStatus)) {
                return true;
            }
            passOnEmpty = false;
            break;
        }
        case INTERACTIONCONDITION_ITEM: {
            if (condition.inventoryDecl == nullptr) {
                Tungsten_WarnAIPlayerInteraction(
                    "Interaction has item based condition, no item is defined on the interaction");
                break;
            }
            bool found = false;
            int itemCount = 0;
            Tungsten_GetAIInteractionInventoryCount(*player,
                *condition.inventoryDecl, found, itemCount);
            if (condition.count >= 1) {
                if (found && itemCount >= condition.count) {
                    return true;
                }
                passOnEmpty = false;
            } else {
                if (found && itemCount >= condition.count) {
                    return false;
                }
                return true;
            }
            break;
        }
        case INTERACTIONCONDITION_GAMESTATEINT: {
            if (condition.gameStateIntDecl == nullptr) {
                Tungsten_WarnAIPlayerInteraction(
                    "Interaction has gameStateInt based condition, no gameStateInt is defined on the interaction");
                break;
            }
            int value = 0;
            if (Tungsten_GetAIInteractionGameStateInt(*player,
                    *condition.gameStateIntDecl, value)
                && value >= condition.count) {
                return true;
            }
            passOnEmpty = false;
            break;
        }
        case INTERACTIONCONDITION_FORCEFALSE:
            return false;
        case INTERACTIONCONDITION_FORCETRUE:
            return true;
        default:
            break;
        }
    }
    return passOnEmpty;
}

// Retail symbol:
// ?InteractionConditionMet@idAIPlayerInteraction@@QBA_NABV?$idList@VinteractionTestCondition_t@aiPlayerInteraction_t@@$04@@PBVidPlayer@@_N@Z
// EA: 0x82A5FF20, RVA: 0x00A5FF20
bool idAIPlayerInteraction::InteractionConditionMet(
        const idAIInteractionConditionList& conditions,
        const idPlayer* const player, bool passOnEmpty) const {
    if (conditions.IsEmpty()) {
        return passOnEmpty;
    }
    if (player == nullptr) {
        return false;
    }
    for (int index = 0; index < conditions.Num(); ++index) {
        const idAIInteractionCondition& condition = conditions[index];
        switch (condition.condition) {
        case INTERACTIONCONDITION_JOB: {
            idAIInteractionJobRuntime job{};
            if (!Tungsten_GetAIInteractionJobByName(
                    *player, condition.jobName.c_str(), job)
                || !JobConditionMet(job, condition.jobStatus)) {
                return false;
            }
            passOnEmpty = true;
            break;
        }
        case INTERACTIONCONDITION_ITEM: {
            if (condition.inventoryDecl == nullptr) {
                Tungsten_WarnAIPlayerInteraction(
                    "Interaction has item based condition, no item is defined on the interaction");
                break;
            }
            bool found = false;
            int itemCount = 0;
            Tungsten_GetAIInteractionInventoryCount(*player,
                *condition.inventoryDecl, found, itemCount);
            if (condition.count < 1) {
                if (found && itemCount >= condition.count) {
                    return false;
                }
            } else if (!found || itemCount < condition.count) {
                return false;
            }
            passOnEmpty = true;
            break;
        }
        case INTERACTIONCONDITION_GAMESTATEINT: {
            if (condition.gameStateIntDecl == nullptr) {
                Tungsten_WarnAIPlayerInteraction(
                    "Interaction has gameStateInt based condition, no gameStateInt is defined on the interaction");
                break;
            }
            int value = 0;
            if (!Tungsten_GetAIInteractionGameStateInt(*player,
                    *condition.gameStateIntDecl, value)
                || value < condition.count) {
                return false;
            }
            passOnEmpty = true;
            break;
        }
        case INTERACTIONCONDITION_FORCEFALSE:
            return false;
        case INTERACTIONCONDITION_FORCETRUE:
            return true;
        default:
            break;
        }
    }
    return passOnEmpty;
}

// Retail symbol:
// ?InteractionHasExpired@idAIPlayerInteraction@@QBA_NPBVaiPlayerInteraction_t@@PBVidPlayer@@PBVidDeclAIPlayerInteraction@@H@Z
// EA: 0x82A60208, RVA: 0x00A60208
bool idAIPlayerInteraction::InteractionHasExpired(
        const aiPlayerInteraction_t* const interaction,
        const idPlayer* const player,
        const idDeclAIPlayerInteraction* const interactionDecl,
        const int interactionNumber) const {
    if (interaction == nullptr || player == nullptr) {
        return false;
    }
    idAIPlayerInteractionRuntime runtime{};
    if (!Tungsten_GetAIPlayerInteractionRuntime(
            *interaction, runtime)) {
        return false;
    }
    if (runtime.interactionJob != nullptr) {
        idAIInteractionJobRuntime job{};
        if (Tungsten_GetAIInteractionJobByDecl(
                *player, *runtime.interactionJob, job)
            && job.exists && job.completed) {
            return true;
        }
    } else if (runtime.messageExpiresInteraction
        && interactionDecl != nullptr
        && Tungsten_GetAIInteractionJobOfferPlayed(
            *player, *interactionDecl, interactionNumber)) {
        return true;
    }
    if (runtime.hasExpiredConditions == nullptr) {
        return false;
    }
    return runtime.expiredOnAny
        ? AnyInteractionConditionMet(
            *runtime.hasExpiredConditions, player, false)
        : InteractionConditionMet(
            *runtime.hasExpiredConditions, player, false);
}

// Retail symbol:
// ?InteractionCanBeClosed@idAIPlayerInteraction@@QBA_NPBVaiPlayerInteraction_t@@PBVidPlayer@@@Z
// EA: 0x82A602B8, RVA: 0x00A602B8
bool idAIPlayerInteraction::InteractionCanBeClosed(
        const aiPlayerInteraction_t* const interaction,
        const idPlayer* const player) const {
    if (interaction == nullptr || player == nullptr) {
        return false;
    }
    idAIPlayerInteractionRuntime runtime{};
    return Tungsten_GetAIPlayerInteractionRuntime(*interaction, runtime)
        && runtime.canBeClosedConditions != nullptr
        && InteractionConditionMet(
            *runtime.canBeClosedConditions, player, true);
}

// Retail symbol:
// ?FindInteraction@idAIPlayerInteraction@@QAAPBVaiPlayerInteraction_t@@PBVidPlayer@@_NPAVidStr@@@Z
// EA: 0x82A602C8, RVA: 0x00A602C8
const aiPlayerInteraction_t* idAIPlayerInteraction::FindInteraction(
        const idPlayer* const player, const bool,
        idStr* const debugString) const {
    if (decl == nullptr) {
        if (debugString != nullptr) {
            debugString->Append("no decl\n");
        }
        return nullptr;
    }
    if (player == nullptr) {
        Tungsten_WarnAIPlayerInteraction(
            "No player passed into idAIPlayerInteraction::FindInteraction?");
        return nullptr;
    }
    if (Tungsten_IsAIInteractionPlayerInVehicle(*player)) {
        if (debugString != nullptr) {
            debugString->Append("player in car\n");
        }
        return nullptr;
    }
    const aiPlayerInteraction_t* selected = nullptr;
    bool selectedIsJobOverride = false;
    const int count = Tungsten_GetAIPlayerInteractionCount(*decl);
    for (int index = 0; index < count; ++index) {
        const aiPlayerInteraction_t* const interaction =
            Tungsten_GetAIPlayerInteractionAt(*decl, index);
        if (interaction == nullptr) {
            AppendDebug(debugString,
                "%d no interaction on decl?\n", index);
            continue;
        }
        if (InteractionHasExpired(interaction, player, decl, index)) {
            AppendDebug(debugString, "%d expired\n", index);
            continue;
        }
        idAIPlayerInteractionRuntime runtime{};
        if (!Tungsten_GetAIPlayerInteractionRuntime(
                *interaction, runtime)
            || runtime.isAvailableConditions == nullptr
            || !InteractionConditionMet(
                *runtime.isAvailableConditions, player, true)) {
            AppendDebug(debugString, "%d unavail\n", index);
            continue;
        }
        if (runtime.interactionJob == nullptr) {
            if (selected == nullptr) {
                selected = interaction;
                AppendDebug(debugString, "%d CURRENT\n", index);
            } else {
                AppendDebug(debugString,
                    "%d valid, but late\n", index);
            }
            continue;
        }
        idAIInteractionJobRuntime job{};
        const bool gotJob = Tungsten_GetAIInteractionJobByDecl(
            *player, *runtime.interactionJob, job);
        if (gotJob && job.exists
            && (job.accepted || job.readyToTurnIn)) {
            const bool jobOverride =
                job.readyToTurnIn && runtime.hasJobCompleteVoice;
            if (selected == nullptr) {
                selected = interaction;
                selectedIsJobOverride = jobOverride;
                AppendJobDebug(debugString, "%d JOB, %d\n",
                    index, jobOverride);
            } else if (!selectedIsJobOverride && jobOverride) {
                selected = interaction;
                selectedIsJobOverride = true;
                AppendJobDebug(debugString,
                    "%d JOB OVERRIDE, %d\n", index, true);
            } else {
                AppendJobDebug(debugString, "%d job, %d\n",
                    index, jobOverride);
            }
        } else if (job.available) {
            if (selected == nullptr) {
                selected = interaction;
                AppendDebug(debugString, "%d JOB\n", index);
            } else {
                AppendDebug(debugString, "%d job\n", index);
            }
        } else {
            AppendDebug(debugString, "%d job unavail\n", index);
        }
    }
    return selected;
}
