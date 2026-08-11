#include "game/decls/decljob.h"

#include "game/decls/declfaction.h"
#include "game/decls/declinventory.h"

namespace {

class DefaultJobServices final : public idDeclJobServices {
};

DefaultJobServices defaultJobServices;
idDeclJobServices* jobServices = &defaultJobServices;

const char* InventoryDebugName(const idDeclInventory* inventory) {
    if (inventory == nullptr) {
        return "";
    }
    if (inventory->displayName.IsValid()) {
        return inventory->displayName.GetLocalizedString();
    }
    return inventory->GetName();
}

const char* JobDebugName(const idDeclJob* job) {
    if (job == nullptr) {
        return "";
    }
    const idStrId name = job->GetJobName();
    if (name.IsValid()) {
        return name.GetLocalizedString();
    }
    return job->GetName();
}

void AppendInteger(idStr& target, const char* format, int value) {
    idStr text;
    text.Format(format, value);
    target.Append(text);
}

void AppendNameAndInteger(idStr& target, const char* name, int value) {
    idStr text;
    text.Format("%s %d", name != nullptr ? name : "", value);
    target.Append(text);
}

} // namespace

void Tungsten_SetDeclJobServices(idDeclJobServices* services) {
    jobServices = services != nullptr ? services : &defaultJobServices;
}

idDeclJobServices& Tungsten_DeclJobServices() {
    return *jobServices;
}

// EA 0x82BC59B0
bool idDeclJob::IsJobHidden() const {
    return jobType == JOBTYPE_APPROACHVO
        || jobType == JOBTYPE_RADIOVO
        || jobType == JOBTYPE_DATAMANAGEMENT;
}

// EA 0x82BC59E0
bool idDeclJob::IsJobImportant() const {
    return jobType == JOBTYPE_REQUIRED || treatAsImportantIfNotRequired;
}

// EA 0x82BC5A08
bool idDeclJob::IsJobImportantForActiveJob() const {
    return jobType == JOBTYPE_REQUIRED
        || jobType == JOBTYPE_SIMPLE
        || jobType == JOBTYPE_OPTIONAL
        || jobType == JOBTYPE_OPTIONAL_POSTED;
}

// EA 0x82BC5A40
bool idDeclJob::UseDynamicJobHud() const {
    return jobType == JOBTYPE_DYNAMIC_COMBAT
        || jobType == JOBTYPE_DYNAMIC_OTHER;
}

// EA 0x82BC5A68
bool idDeclJob::DontSaveProgressToFile() const {
    return jobType == JOBTYPE_DYNAMIC_OTHER;
}

// EA 0x82BC5A80
bool idDeclJob::ShowsGUI() const {
    return normalFlowVars.showsGUI
        && (jobType == JOBTYPE_REQUIRED
            || jobType == JOBTYPE_OPTIONAL
            || jobType == JOBTYPE_OPTIONAL_POSTED
            || jobType == JOBTYPE_REPEATING
            || jobType == JOBTYPE_JUSTGUI);
}

// EA 0x82BC5AC0
bool idDeclJob::IsQuestJob() const {
    return jobType == JOBTYPE_REQUIRED
        || jobType == JOBTYPE_SIMPLE
        || jobType == JOBTYPE_OPTIONAL
        || jobType == JOBTYPE_OPTIONAL_POSTED
        || jobType == JOBTYPE_REPEATING;
}

// EA 0x82BC5B00
bool idDeclJob::IsSimple() const {
    return jobType == JOBTYPE_SIMPLE;
}

// EA 0x82BC5B18
bool idDeclJob::IsOptionalQuestJob() const {
    return jobType == JOBTYPE_OPTIONAL
        || jobType == JOBTYPE_OPTIONAL_POSTED;
}

// EA 0x82BC5B40
idStrId idDeclJob::GetJobName() const {
    return jobNameId;
}

// EA 0x82BC5B50
idStrId idDeclJob::GetJobSummary() const {
    return jobSummaryId;
}

// EA 0x82BC5B60
idStrId idDeclJob::GetJobRequirements() const {
    return jobRequirementsId;
}

// EA 0x82BC5B70
idStrId idDeclJob::GetJobReward() const {
    return jobRewardId;
}

// EA 0x82BC5B88
const idDeclJob::jobPreCondition_t* idDeclJob::GetJobPrecondition(
        int index) const {
    return &preconditions[index];
}

// EA 0x82BC5B98
int idDeclJob::GetNumJobRewards() const {
    return rewards.Num();
}

// EA 0x82BC5BA0
const idDeclJob::jobReward_t* idDeclJob::GetJobReward(int index) const {
    return &rewards[index];
}

// EA 0x82BC5BB8
int idDeclJob::GetNumDebugRewards() const {
    return debugInfo.debug_accepted.debugRewards.Num()
        + debugInfo.debug_readyToTurnIn.debugRewards.Num()
        + debugInfo.debug_completed.debugRewards.Num();
}

// EA 0x82BC5BE0
int idDeclJob::GetNumCompletionRequirements() const {
    return completion.Num();
}

// EA 0x82BC5BE8
const idDeclJob::jobComplete_t* idDeclJob::GetCompletionRequirement(
        int index) const {
    return &completion[index];
}

// EA 0x82BC5BF8
bool idDeclJob::AIMatchesJobCompleteNPC(const idAI2* ai) const {
    return ai != nullptr
        && completeNPCName.GetIndex()
            == Tungsten_DeclJobServices().GetAINpcNameIndex(ai);
}

// EA 0x82BC5C20
idGameStateInt::idGameStateInt()
    : decl(nullptr)
    , gameStateValue(0) {
}

// EA 0x82BC5C40
idGameStateInt::idGameStateInt(const idDeclGameStateInt* gameStateDecl)
    : decl(gameStateDecl)
    , gameStateValue(0) {
}

// EA 0x82BC5CD8
idStr idDeclJob::BuildRewardDebugString(jobReward_t reward,
        idStr& debugString) const {
    switch (reward.reward) {
    case JOBREWARD_NONE:
        debugString.Append("NONE ? : ");
        break;
    case JOBREWARD_ITEM:
        debugString.Append("ITEM : ");
        debugString.Append(InventoryDebugName(reward.inventoryDecl));
        AppendInteger(debugString, " %d", reward.count);
        break;
    case JOBREWARD_ITEM_REMOVE:
        debugString.Append("REMOVE ITEM : ");
        debugString.Append(InventoryDebugName(reward.inventoryDecl));
        AppendInteger(debugString, " %d", reward.count);
        break;
    case JOBREWARD_FACTION:
        debugString.Append("FACTION : ");
        if (reward.factionDecl != nullptr) {
            debugString.Append(reward.factionDecl->GetName());
        }
        break;
    case JOBREWARD_JOBCOMPLETION:
        debugString.Append("JOB COMPLETION: ");
        debugString.Append(JobDebugName(reward.jobDecl));
        break;
    case JOBREWARD_JOBACCEPT:
        debugString.Append("JOB ACCEPT: ");
        debugString.Append(JobDebugName(reward.jobDecl));
        break;
    case JOBREWARD_JOBREMOVE:
        debugString.Append("JOB REMVOE: ");
        debugString.Append(JobDebugName(reward.jobDecl));
        break;
    case JOBREWARD_JOBREMOVE_INPROGRESS:
        debugString.Append("JOB REMVOE IN PROGRESS: ");
        debugString.Append(JobDebugName(reward.jobDecl));
        break;
    case JOBREWARD_USEALTERNATEHANDS:
        debugString.Append("Use alternate hands: ");
        break;
    case JOBREWARD_GAMESTATEINT:
        debugString.Append("GAME STATE INT: ");
        if (reward.gameStateIntDecl != nullptr) {
            AppendNameAndInteger(debugString,
                reward.gameStateIntDecl->GetName(), reward.count);
        }
        break;
    case JOBREWARD_GARAGE:
        debugString.Append("Garage Reward");
        break;
    case JOBREWARD_ACTIVATE_JOB:
        debugString.Append("Activate Job");
        break;
    default:
        debugString.Append("ERROR!");
        break;
    }
    return debugString;
}

// EA 0x82BC5FE8
idStr idDeclJob::GetJobRewardDebugString(int index) const {
    idStr result;
    return BuildRewardDebugString(rewards[index], result);
}

// EA 0x82BC60F8
idStr idDeclJob::GetJobDebugRewardDebugString(int index) const {
    idStr result;
    const int acceptedCount = debugInfo.debug_accepted.debugRewards.Num();
    if (index < acceptedCount) {
        result.Append("ACCEPTED _ ");
        return BuildRewardDebugString(
            debugInfo.debug_accepted.debugRewards[index], result);
    }

    index -= acceptedCount;
    const int readyCount = debugInfo.debug_readyToTurnIn.debugRewards.Num();
    if (index < readyCount) {
        result.Append("READY _ ");
        return BuildRewardDebugString(
            debugInfo.debug_readyToTurnIn.debugRewards[index], result);
    }

    index -= readyCount;
    if (index < debugInfo.debug_completed.debugRewards.Num()) {
        result.Append("COMPLETE _ ");
        return BuildRewardDebugString(
            debugInfo.debug_completed.debugRewards[index], result);
    }

    result.Append("Error finding debug reward");
    return result;
}

// EA 0x82BC6328
idStr idDeclJob::GetJobAcceptRewardDebugString(int index) const {
    idStr result;
    return BuildRewardDebugString(acceptRewards[index], result);
}

// EA 0x82BC6438
idStr idDeclJob::GetJobReadyRewardDebugString(int index) const {
    idStr result;
    return BuildRewardDebugString(readyRewards[index], result);
}

// EA 0x82BC6C18
idStr idDeclJob::GetJobPreconditionDebugString(int index) const {
    const jobPreCondition_t precondition = preconditions[index];
    idStr result;
    switch (precondition.precondition) {
    case JOBPRECONDITION_NONE:
        result.Append("NONE ? : ");
        break;
    case JOBPRECONDITION_JOB:
        result.Append("JOB : ");
        result.Append(precondition.jobDecl);
        switch (precondition.jobStatus) {
        case JOBPRECONDITIONSTATUS_ACCEPTED:
            result.Append(" _ ACCEPTED");
            break;
        case JOBPRECONDITIONSTATUS_READYTOTURNIN:
            result.Append(" _ READY");
            break;
        case JOBPRECONDITIONSTATUS_COMPLETED:
            result.Append(" _ COMPLETE");
            break;
        default:
            break;
        }
        break;
    case JOBPRECONDITION_ITEM:
        result.Append("ITEM : ");
        result.Append(InventoryDebugName(precondition.inventoryDecl));
        AppendInteger(result, " %d", precondition.count);
        if (precondition.removeInventory) {
            result.Append(" _ REMOVE");
        }
        break;
    case JOBPRECONDITION_GAMESTATEINT:
        result.Append("GAMESTATEINT: ");
        if (precondition.gameStateIntDecl != nullptr) {
            AppendNameAndInteger(result,
                precondition.gameStateIntDecl->GetName(),
                precondition.count);
        }
        break;
    default:
        result.Append("ERROR!");
        break;
    }
    return result;
}

// EA 0x82BC6E58
idStr idDeclJob::GetCompletionRequirementDebugString(int index) const {
    const jobComplete_t requirement = completion[index];
    idStr result;
    switch (requirement.completion) {
    case JOBCOMPLETE_NONE:
        result.Append("NONE ? : ");
        break;
    case JOBCOMPLETE_ITEM:
        result.Append("ITEM : ");
        result.Append(InventoryDebugName(requirement.inventoryDecl));
        AppendInteger(result, " %d", requirement.count);
        if (requirement.removeInventory) {
            result.Append(" _ REMOVE");
        }
        break;
    case JOBCOMPLETE_TRIGGER:
        result.Append("TRIGGER : ");
        result.Append(requirement.triggerMessage.GetLocalizedString());
        break;
    case JOBCOMPLETE_JOB:
        result.Append("JOB COMPLETE : ");
        result.Append(requirement.jobDecl);
        break;
    case JOBCOMPLETE_JOB_ACCEPTED:
        result.Append("JOB ACCEPTED : ");
        result.Append(requirement.jobDecl);
        break;
    case JOBCOMPLETE_GAMESTATEINT:
        result.Append("GAMESTATEINT : ");
        if (requirement.gameStateIntDecl != nullptr) {
            AppendNameAndInteger(result,
                requirement.gameStateIntDecl->GetName(),
                requirement.count);
        }
        break;
    default:
        result.Append("ERROR!");
        break;
    }
    return result;
}

// Retail symbol: ??0jobSpawnInfo_t@idDeclJob@@QAA@XZ
// EA 0x82BC70A8 (header-defined retail constructor).
idDeclJob::jobSpawnInfo_t::jobSpawnInfo_t()
    : spawnSpot()
    , mapName()
    , layerList()
    , layerListDeactive()
    , delayTime(1500)
    , hideVehicles(false) {
}

// EA 0x82BC7940
idDeclJob::idDeclJob()
    : jobNameId()
    , jobSummaryId()
    , jobRequirementsId()
    , jobRewardId()
    , jobStanleyObjId()
    , relevantMaps()
    , jobType(JOBTYPE_NONE)
    , treatAsImportantIfNotRequired(false)
    , acceptNeedsVerification(false)
    , aiAcceptImmediatly(true)
    , sniperMission(false)
    , challengeLevel(0)
    , normalFlowVars{ true }
    , giveAndCompleteOnApproach(false)
    , jobTimerEvent(nullptr)
    , preconditions()
    , acceptRewards()
    , readyRewards()
    , completion()
    , rewards()
    , acceptedMiniMapTravelEnt()
    , readyToTurnInMiniMapCompletionEnt()
    , completeNPCName()
    , jobLayerInfo()
    , jobNoteInfo()
    , jobAutoTransitionInfo()
    , discSwappingJob(false)
    , jobGiverFaction(JOBFACTION_NONE)
    , debugInfo()
    , parentWithoutPrecondition()
    , cameras()
    , cameraIndex(-1)
    , showOnDebugJobGUI(true)
    , jobImage(nullptr)
    , doesFakeJob(false)
    , fakeJobName()
    , fakeJobObj()
    , fakeJobCompleteNPC()
    , fakeJobMiniMapEnt()
    , ignoreFakeJob(false)
    , breakFakeJobCheck(false)
    , requiredDLC(GAME_DLC_STATE_DEFAULT)
    , autoCompletes(true)
    , autoCompleteDistance(160)
    , demoStates() {
}
