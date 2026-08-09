#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\encountergroups.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14471; PDB kind: class.
class idEncounterGroup
{
public:
  idStr groupName;
  idList<idEncounterGroup *,5> childGroups;
  idList<idStr,5> childGroupNames;
  idEncounterState spawnState;
  idEncounterState ownGroupAlertState;
  idEncounterState otherGroupAlertState;
  bool enabled;
  idEntityPtr<idAI2> leader;
  int maxSimultaneousFirers;
  int noRageMemberCount;
  int nonGroupRushUnits;
  int groupRushTime;
  int minGrenadeRethrowTime;
  idList<idEncounterGroupExpr,5> triggers;
  int maxMembers;
  idList<idEntityPtr<idAI2>,5> members;
  int numLivingMembers;
  int numDeadMembers;
  float recentHeavilyKilledMembers;
  float recentlyKilledMembers;
  float recentlyKilledHeavies;
  idFaction faction;
  aiConfidenceLevel_t confidenceLevel;
  alertCycle_t highestMemberAlertCycle;
  bool anyMemberHasSeenDeadBody;
  bool shouldAmbush;
  bool shouldGroupRush;
  bool groupGoodWill;
  idEncounterGroup::idGoodWillSettings goodWillSettings;
  int nextGroupMemberRoleUpdateTime;
  int nextGrenadeTime;
  idHandle<short,enum invalidEncounterGroup_t,-1> handle;
  bool active;
  idAIVoiceController voiceController;
  idList<idEncounterGroup::searchPoint_t,5> searchPointList;
  int curCombatStage;
  int pendingCombatStage;
  int pendingCombatStageTime;
  int stageChangeTime;
  idList<idCombatStage,5> combatStages;
  int initialCombatStage;
  idList<idEntityPtr<idAISearchHintGroup>,5> searchHintGroups;
  idStaticList<idEncounterGroup::target_t,16> targetList;
};

// IDA Local Type ordinal 14479; PDB kind: struct.
struct idEncounterGroup::idGoodWillSettings
{
  unsigned __int8 : 3;
  __int8 maxHoldTrigger : 1;
  __int8 allFireFromCover : 1;
  __int8 infiniteAmmo : 1;
  __int8 perfectAim : 1;
  __int8 surroundTrigger : 1;
  float damageScale;
};

// IDA Local Type ordinal 14482; PDB kind: struct.
struct __declspec(align(4)) idEncounterGroup::searchPoint_t
{
  int hintNodeIndex;
  float searchDist;
  bool visited;
};

// IDA Local Type ordinal 14491; PDB kind: struct.
struct idEncounterGroup::target_t
{
  idEntityPtr<idEntity> target;
  int frame;
};

// IDA Local Type ordinal 28836; PDB kind: typedef.
typedef idList<idEncounterGroup,5> encounterGroupList_t;
