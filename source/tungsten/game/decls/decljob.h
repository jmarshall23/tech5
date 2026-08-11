#pragma once

#include "decljobref.h"
#include "decls/decltypeinfo.h"
#include "idlib/langdict.h"

class idAI2;
class idDeclCameraTrigger;
class idDeclFaction;
class idDeclInventory;
class idDeclJobNote;
class idDeclJobTimerEvent;
class idDeclLayer;
class idMaterial;
enum rageStat_t : int;

enum garageList_t : int {
    GARAGE_NONE = 0,
    GARAGE_HAGER = 1,
    GARAGE_WELLSPRING = 2,
    GARAGE_SUBWAYTOWN = 3,
    GARAGE_MAX = 4
};

enum gameDLCState_t : int {
    GAME_DLC_STATE_DEFAULT = 0,
    GAME_DLC_STATE_AUTHORITY = 1,
    GAME_DLC_STATE_SEWERS = 2
};

enum gameDemoType_t : int {
    GAME_DEMO_TYPE_NONE = 0,
    GAME_DEMO_TYPE_FIRSTLOOK = 1,
    GAME_DEMO_TYPE_PLAYTEST = 2,
    GAME_DEMO_TYPE_NEXTDEMO = 3,
    GAME_DEMO_TYPE_FUTURE = 4
};

class idStrMapName : public idStr {
public:
    using idStr::idStr;
};

class idDeclGameStateInt : public idDeclTypeInfo {
public:
    idDeclGameStateInt() = default;
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }
    static idDeclInfoTemplate<idDeclGameStateInt> resourceList;
};

#ifndef TUNGSTEN_GAME_STATE_INT_DEFINED
#define TUNGSTEN_GAME_STATE_INT_DEFINED
class idGameStateInt {
public:
    idGameStateInt();
    explicit idGameStateInt(const idDeclGameStateInt* gameStateDecl);
    virtual ~idGameStateInt() = default;

    const idDeclGameStateInt* decl;
    int gameStateValue;
};
#endif

class idDeclJobServices {
public:
    virtual ~idDeclJobServices() = default;
    virtual int GetAINpcNameIndex(const idAI2*) const { return -1; }
};

void Tungsten_SetDeclJobServices(idDeclJobServices* services);
idDeclJobServices& Tungsten_DeclJobServices();

class idDeclJob : public idDeclTypeInfo {
public:
    enum jobPreConditionType_t : int {
        JOBPRECONDITION_NONE = 0,
        JOBPRECONDITION_JOB = 1,
        JOBPRECONDITION_ITEM = 2,
        JOBPRECONDITION_GAMESTATEINT = 3
    };

    enum jobCompleteType_t : int {
        JOBCOMPLETE_NONE = 0,
        JOBCOMPLETE_ITEM = 1,
        JOBCOMPLETE_TRIGGER = 2,
        JOBCOMPLETE_JOB = 3,
        JOBCOMPLETE_JOB_ACCEPTED = 4,
        JOBCOMPLETE_GAMESTATEINT = 5,
        JOBCOMPLETE_JUSTDISPLAY = 6
    };

    enum jobType_t : int {
        JOBTYPE_NONE = 0,
        JOBTYPE_REQUIRED = 1,
        JOBTYPE_SIMPLE = 2,
        JOBTYPE_OPTIONAL = 3,
        JOBTYPE_OPTIONAL_POSTED = 4,
        JOBTYPE_REPEATING = 5,
        JOBTYPE_APPROACHVO = 6,
        JOBTYPE_RADIOVO = 7,
        JOBTYPE_DATAMANAGEMENT = 8,
        JOBTYPE_DYNAMIC_COMBAT = 9,
        JOBTYPE_DYNAMIC_OTHER = 10,
        JOBTYPE_JUSTGUI = 11,
        JOBTYPE_INFO = 12
    };

    enum jobPreConditionStatus_t : int {
        JOBPRECONDITIONSTATUS_ACCEPTED = 0,
        JOBPRECONDITIONSTATUS_READYTOTURNIN = 1,
        JOBPRECONDITIONSTATUS_COMPLETED = 2
    };

    enum jobRewardType_t : int {
        JOBREWARD_NONE = 0,
        JOBREWARD_ITEM = 1,
        JOBREWARD_ITEM_REMOVE = 2,
        JOBREWARD_FACTION = 3,
        JOBREWARD_JOBCOMPLETION = 4,
        JOBREWARD_JOBACCEPT = 5,
        JOBREWARD_JOBREMOVE = 6,
        JOBREWARD_JOBREMOVE_INPROGRESS = 7,
        JOBREWARD_USEALTERNATEHANDS = 8,
        JOBREWARD_GAMESTATEINT = 9,
        JOBREWARD_GARAGE = 10,
        JOBREWARD_ACTIVATE_JOB = 11
    };

    enum jobGiverFaction_t : int {
        JOBFACTION_NONE = 0,
        JOBFACTION_BOUNTY = 1,
        JOBFACTION_WASTELANDER = 2,
        JOBFACTION_WELLSPRING = 3,
        JOBFACTION_SUBWAYTOWN = 4,
        JOBFACTION_REGIME = 5,
        JOBFACTION_MUTANTBASH = 6
    };

    struct jobNormalFlowVars_t {
        bool showsGUI;
    };

    struct jobPreCondition_t {
        jobPreCondition_t()
            : precondition(JOBPRECONDITION_NONE)
            , jobDecl()
            , jobStatus(JOBPRECONDITIONSTATUS_ACCEPTED)
            , inventoryDecl(nullptr)
            , count(0)
            , removeInventory(false)
            , gameStateIntDecl(nullptr) {
        }

        jobPreConditionType_t precondition;
        idDeclJobRef jobDecl;
        jobPreConditionStatus_t jobStatus;
        const idDeclInventory* inventoryDecl;
        int count;
        bool removeInventory;
        const idDeclGameStateInt* gameStateIntDecl;
    };

    struct jobReward_t {
        jobReward_t()
            : reward(JOBREWARD_NONE)
            , inventoryDecl(nullptr)
            , count(0)
            , factionDecl(nullptr)
            , jobDecl(nullptr)
            , gameStateIntDecl(nullptr)
            , garage(GARAGE_NONE)
            , stat(static_cast<rageStat_t>(-1))
            , statAmount(0) {
        }

        jobRewardType_t reward;
        const idDeclInventory* inventoryDecl;
        int count;
        const idDeclFaction* factionDecl;
        const idDeclJob* jobDecl;
        const idDeclGameStateInt* gameStateIntDecl;
        garageList_t garage;
        rageStat_t stat;
        int statAmount;
    };

    struct jobComplete_t {
        jobComplete_t()
            : completion(JOBCOMPLETE_NONE)
            , inventoryDecl(nullptr)
            , count(0)
            , removeInventory(false)
            , showTrackerMessage(false)
            , justDisplayCountsReadyAsComplete(false)
            , triggerMessage()
            , jobDecl()
            , gameStateIntDecl(nullptr) {
        }

        jobCompleteType_t completion;
        const idDeclInventory* inventoryDecl;
        int count;
        bool removeInventory;
        bool showTrackerMessage;
        bool justDisplayCountsReadyAsComplete;
        idStrId triggerMessage;
        idDeclJobRef jobDecl;
        const idDeclGameStateInt* gameStateIntDecl;
    };

    struct jobLayerInfo_t {
        idList<const idDeclLayer*, 5> acceptLayers;
        idList<const idDeclLayer*, 5> acceptLayersDeactive;
        idList<const idDeclLayer*, 5> acceptLayersRemove;
        idList<const idDeclLayer*, 5> readyLayers;
        idList<const idDeclLayer*, 5> readyLayersDeactive;
        idList<const idDeclLayer*, 5> readyLayersRemove;
        idList<const idDeclLayer*, 5> completeLayers;
        idList<const idDeclLayer*, 5> completeLayersDeactive;
        idList<const idDeclLayer*, 5> completeLayersRemove;
    };

    struct jobNoteInfo_t {
        idList<const idDeclJobNote*, 5> acceptJobNotes;
        idList<const idDeclJobNote*, 5> acceptJobNotesRemove;
        idList<const idDeclJobNote*, 5> readyJobNotes;
        idList<const idDeclJobNote*, 5> readyJobNotesRemove;
        idList<const idDeclJobNote*, 5> completeJobNotes;
        idList<const idDeclJobNote*, 5> completeJobNotesRemove;
        idList<const idDeclJobNote*, 5> relevantMapNotesRemove;
        idList<const idDeclJobNote*, 5> relevantMapNotes;
    };

    struct jobSpawnInfo_t {
        jobSpawnInfo_t();
        idStr spawnSpot;
        idStr mapName;
        idList<const idDeclLayer*, 5> layerList;
        idList<const idDeclLayer*, 5> layerListDeactive;
        int delayTime;
        bool hideVehicles;
    };

    struct jobAutoTransitionInfo_t {
        jobSpawnInfo_t acceptSpawnInfo;
        jobSpawnInfo_t readySpawnInfo;
        jobSpawnInfo_t completeSpawnInfo;
        jobSpawnInfo_t failSpawnInfo;
    };

    struct jobDebugInfo_t {
        idList<jobReward_t, 5> debugRewards;
    };

    struct jobDebugMasterInfo_t {
        jobDebugInfo_t debug_accepted;
        jobDebugInfo_t debug_readyToTurnIn;
        jobDebugInfo_t debug_completed;
    };

    idDeclJob();
    ~idDeclJob() override = default;
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    bool IsJobHidden() const;
    bool IsJobImportant() const;
    bool IsJobImportantForActiveJob() const;
    bool UseDynamicJobHud() const;
    bool DontSaveProgressToFile() const;
    bool ShowsGUI() const;
    bool IsQuestJob() const;
    bool IsSimple() const;
    bool IsOptionalQuestJob() const;

    idStrId GetJobName() const;
    idStrId GetJobSummary() const;
    idStrId GetJobRequirements() const;
    idStrId GetJobReward() const;

    const jobPreCondition_t* GetJobPrecondition(int index) const;
    int GetNumJobRewards() const;
    const jobReward_t* GetJobReward(int index) const;
    int GetNumDebugRewards() const;
    int GetNumCompletionRequirements() const;
    const jobComplete_t* GetCompletionRequirement(int index) const;
    bool AIMatchesJobCompleteNPC(const idAI2* ai) const;

    idStr BuildRewardDebugString(jobReward_t reward,
        idStr& debugString) const;
    idStr GetJobRewardDebugString(int index) const;
    idStr GetJobDebugRewardDebugString(int index) const;
    idStr GetJobAcceptRewardDebugString(int index) const;
    idStr GetJobReadyRewardDebugString(int index) const;
    idStr GetJobPreconditionDebugString(int index) const;
    idStr GetCompletionRequirementDebugString(int index) const;

    idStrId jobNameId;
    idStrId jobSummaryId;
    idStrId jobRequirementsId;
    idStrId jobRewardId;
    idStrId jobStanleyObjId;
    idList<idStrMapName, 5> relevantMaps;
    jobType_t jobType;
    bool treatAsImportantIfNotRequired;
    bool acceptNeedsVerification;
    bool aiAcceptImmediatly;
    bool sniperMission;
    int challengeLevel;
    jobNormalFlowVars_t normalFlowVars;
    bool giveAndCompleteOnApproach;
    const idDeclJobTimerEvent* jobTimerEvent;
    idList<jobPreCondition_t, 5> preconditions;
    idList<jobReward_t, 5> acceptRewards;
    idList<jobReward_t, 5> readyRewards;
    idList<jobComplete_t, 5> completion;
    idList<jobReward_t, 5> rewards;
    idList<idStr, 5> acceptedMiniMapTravelEnt;
    idList<idStr, 5> readyToTurnInMiniMapCompletionEnt;
    idStrId completeNPCName;
    jobLayerInfo_t jobLayerInfo;
    jobNoteInfo_t jobNoteInfo;
    jobAutoTransitionInfo_t jobAutoTransitionInfo;
    bool discSwappingJob;
    jobGiverFaction_t jobGiverFaction;
    jobDebugMasterInfo_t debugInfo;
    idDeclJobRef parentWithoutPrecondition;
    idList<const idDeclCameraTrigger*, 5> cameras;
    int cameraIndex;
    bool showOnDebugJobGUI;
    const idMaterial* jobImage;
    bool doesFakeJob;
    idStrId fakeJobName;
    idStrId fakeJobObj;
    idStrId fakeJobCompleteNPC;
    idStr fakeJobMiniMapEnt;
    bool ignoreFakeJob;
    bool breakFakeJobCheck;
    gameDLCState_t requiredDLC;
    bool autoCompletes;
    int autoCompleteDistance;
    idList<gameDemoType_t, 5> demoStates;

    static idDeclInfoTemplate<idDeclJob> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idGameStateInt) == 12,
    "Recovered game-state integer ABI changed");
static_assert(sizeof(idDeclJob::jobReward_t) == 36,
    "Recovered job reward ABI changed");
static_assert(sizeof(idDeclJob::jobPreCondition_t) == 56,
    "Recovered job precondition ABI changed");
static_assert(sizeof(idDeclJob::jobComplete_t) == 56,
    "Recovered job completion ABI changed");
static_assert(sizeof(idDeclJob) == 1120,
    "Recovered job declaration ABI changed");
#endif
