#pragma once

#include "decljobref.h"

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\decljob.h
// Recovered logical types: 18
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1193; PDB kind: enum.
enum idDeclJob::jobPreConditionType_t : __int32
{
  JOBPRECONDITION_NONE = 0x0,
  JOBPRECONDITION_JOB = 0x1,
  JOBPRECONDITION_ITEM = 0x2,
  JOBPRECONDITION_GAMESTATEINT = 0x3,
};

// IDA Local Type ordinal 1194; PDB kind: enum.
enum idDeclJob::jobCompleteType_t : __int32
{
  JOBCOMPLETE_NONE = 0x0,
  JOBCOMPLETE_ITEM = 0x1,
  JOBCOMPLETE_TRIGGER = 0x2,
  JOBCOMPLETE_JOB = 0x3,
  JOBCOMPLETE_JOB_ACCEPTED = 0x4,
  JOBCOMPLETE_GAMESTATEINT = 0x5,
  JOBCOMPLETE_JUSTDISPLAY = 0x6,
};

// IDA Local Type ordinal 1195; PDB kind: enum.
enum idDeclJob::jobType_t : __int32
{
  JOBTYPE_NONE = 0x0,
  JOBTYPE_REQUIRED = 0x1,
  JOBTYPE_SIMPLE = 0x2,
  JOBTYPE_OPTIONAL = 0x3,
  JOBTYPE_OPTIONAL_POSTED = 0x4,
  JOBTYPE_REPEATING = 0x5,
  JOBTYPE_APPROACHVO = 0x6,
  JOBTYPE_RADIOVO = 0x7,
  JOBTYPE_DATAMANAGEMENT = 0x8,
  JOBTYPE_DYNAMIC_COMBAT = 0x9,
  JOBTYPE_DYNAMIC_OTHER = 0xA,
  JOBTYPE_JUSTGUI = 0xB,
  JOBTYPE_INFO = 0xC,
};

// IDA Local Type ordinal 1325; PDB kind: enum.
enum idDeclJob::jobPreConditionStatus_t : __int32
{
  JOBPRECONDITIONSTATUS_ACCEPTED = 0x0,
  JOBPRECONDITIONSTATUS_READYTOTURNIN = 0x1,
  JOBPRECONDITIONSTATUS_COMPLETED = 0x2,
};

// IDA Local Type ordinal 1326; PDB kind: enum.
enum idDeclJob::jobRewardType_t : __int32
{
  JOBREWARD_NONE = 0x0,
  JOBREWARD_ITEM = 0x1,
  JOBREWARD_ITEM_REMOVE = 0x2,
  JOBREWARD_FACTION = 0x3,
  JOBREWARD_JOBCOMPLETION = 0x4,
  JOBREWARD_JOBACCEPT = 0x5,
  JOBREWARD_JOBREMOVE = 0x6,
  JOBREWARD_JOBREMOVE_INPROGRESS = 0x7,
  JOBREWARD_USEALTERNATEHANDS = 0x8,
  JOBREWARD_GAMESTATEINT = 0x9,
  JOBREWARD_GARAGE = 0xA,
  JOBREWARD_ACTIVATE_JOB = 0xB,
};

// IDA Local Type ordinal 2076; PDB kind: enum.
enum idDeclJob::jobGiverFaction_t : __int32
{
  JOBFACTION_NONE = 0x0,
  JOBFACTION_BOUNTY = 0x1,
  JOBFACTION_WASTELANDER = 0x2,
  JOBFACTION_WELLSPRING = 0x3,
  JOBFACTION_SUBWAYTOWN = 0x4,
  JOBFACTION_REGIME = 0x5,
  JOBFACTION_MUTANTBASH = 0x6,
};

// IDA Local Type ordinal 14370; PDB kind: struct.
struct idDeclJob::jobNormalFlowVars_t
{
  bool showsGUI;
};

// IDA Local Type ordinal 14373; PDB kind: class.
class idDeclJob::jobPreCondition_t
{
public:
  idDeclJob::jobPreConditionType_t precondition;
  idDeclJobRef jobDecl;
  idDeclJob::jobPreConditionStatus_t jobStatus;
  const idDeclInventory *inventoryDecl;
  int count;
  bool removeInventory;
  const idDeclGameStateInt *gameStateIntDecl;
};

// IDA Local Type ordinal 14381; PDB kind: class.
class idDeclJob : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14420.
  virtual ~idDeclJob();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();
  virtual unsigned int GetDeclTimestamp();
  virtual idDeclInfo *GetDeclInfo();
  virtual bool RebuildTextSource();
  virtual bool SetImplicitText();
  virtual const char *DefaultDefinition();
  virtual void LogMissingDecl();
  virtual void Parse(idParser *);
  virtual void FreeData();
  virtual unsigned int Size();

  idStrId jobNameId;
  idStrId jobSummaryId;
  idStrId jobRequirementsId;
  idStrId jobRewardId;
  idStrId jobStanleyObjId;
  idList<idStrMapName,5> relevantMaps;
  idDeclJob::jobType_t jobType;
  bool treatAsImportantIfNotRequired;
  bool acceptNeedsVerification;
  bool aiAcceptImmediatly;
  bool sniperMission;
  int challengeLevel;
  idDeclJob::jobNormalFlowVars_t normalFlowVars;
  bool giveAndCompleteOnApproach;
  const idDeclJobTimerEvent *jobTimerEvent;
  idList<idDeclJob::jobPreCondition_t,5> preconditions;
  idList<idDeclJob::jobReward_t,5> acceptRewards;
  idList<idDeclJob::jobReward_t,5> readyRewards;
  idList<idDeclJob::jobComplete_t,5> completion;
  idList<idDeclJob::jobReward_t,5> rewards;
  idList<idStr,5> acceptedMiniMapTravelEnt;
  idList<idStr,5> readyToTurnInMiniMapCompletionEnt;
  idStrId completeNPCName;
  idDeclJob::jobLayerInfo_t jobLayerInfo;
  idDeclJob::jobNoteInfo_t jobNoteInfo;
  idDeclJob::jobAutoTransitionInfo_t jobAutoTransitionInfo;
  bool discSwappingJob;
  idDeclJob::jobGiverFaction_t jobGiverFaction;
  idDeclJob::jobDebugMasterInfo_t debugInfo;
  idDeclJobRef parentWithoutPrecondition;
  idList<idDeclCameraTrigger const *,5> cameras;
  int cameraIndex;
  bool showOnDebugJobGUI;
  const idMaterial *jobImage;
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
  idList<enum gameDemoType_t,5> demoStates;
};

// IDA Local Type ordinal 14382; PDB kind: class.
class idDeclJob::jobReward_t
{
public:
  idDeclJob::jobRewardType_t reward;
  const idDeclInventory *inventoryDecl;
  int count;
  const idDeclFaction *factionDecl;
  const idDeclJob *jobDecl;
  const idDeclGameStateInt *gameStateIntDecl;
  garageList_t garage;
  rageStat_t stat;
  int statAmount;
};

// IDA Local Type ordinal 14384; PDB kind: class.
class idDeclJob::jobComplete_t
{
public:
  idDeclJob::jobCompleteType_t completion;
  const idDeclInventory *inventoryDecl;
  int count;
  bool removeInventory;
  bool showTrackerMessage;
  bool justDisplayCountsReadyAsComplete;
  idStrId triggerMessage;
  idDeclJobRef jobDecl;
  const idDeclGameStateInt *gameStateIntDecl;
};

// IDA Local Type ordinal 14389; PDB kind: class.
class idDeclJob::jobLayerInfo_t
{
public:
  idList<idDeclLayer const *,5> acceptLayers;
  idList<idDeclLayer const *,5> acceptLayersDeactive;
  idList<idDeclLayer const *,5> acceptLayersRemove;
  idList<idDeclLayer const *,5> readyLayers;
  idList<idDeclLayer const *,5> readyLayersDeactive;
  idList<idDeclLayer const *,5> readyLayersRemove;
  idList<idDeclLayer const *,5> completeLayers;
  idList<idDeclLayer const *,5> completeLayersDeactive;
  idList<idDeclLayer const *,5> completeLayersRemove;
};

// IDA Local Type ordinal 14393; PDB kind: class.
class idDeclJob::jobNoteInfo_t
{
public:
  idList<idDeclJobNote const *,5> acceptJobNotes;
  idList<idDeclJobNote const *,5> acceptJobNotesRemove;
  idList<idDeclJobNote const *,5> readyJobNotes;
  idList<idDeclJobNote const *,5> readyJobNotesRemove;
  idList<idDeclJobNote const *,5> completeJobNotes;
  idList<idDeclJobNote const *,5> completeJobNotesRemove;
  idList<idDeclJobNote const *,5> relevantMapNotesRemove;
  idList<idDeclJobNote const *,5> relevantMapNotes;
};

// IDA Local Type ordinal 14394; PDB kind: class.
class __declspec(align(4)) idDeclJob::jobSpawnInfo_t
{
public:
  idStr spawnSpot;
  idStr mapName;
  idList<idDeclLayer const *,5> layerList;
  idList<idDeclLayer const *,5> layerListDeactive;
  int delayTime;
  bool hideVehicles;
};

// IDA Local Type ordinal 14395; PDB kind: class.
class idDeclJob::jobAutoTransitionInfo_t
{
public:
  idDeclJob::jobSpawnInfo_t acceptSpawnInfo;
  idDeclJob::jobSpawnInfo_t readySpawnInfo;
  idDeclJob::jobSpawnInfo_t completeSpawnInfo;
  idDeclJob::jobSpawnInfo_t failSpawnInfo;
};

// IDA Local Type ordinal 14396; PDB kind: class.
class idDeclJob::jobDebugInfo_t
{
public:
  idList<idDeclJob::jobReward_t,5> debugRewards;
};

// IDA Local Type ordinal 14397; PDB kind: class.
class idDeclJob::jobDebugMasterInfo_t
{
public:
  idDeclJob::jobDebugInfo_t debug_accepted;
  idDeclJob::jobDebugInfo_t debug_readyToTurnIn;
  idDeclJob::jobDebugInfo_t debug_completed;
};
