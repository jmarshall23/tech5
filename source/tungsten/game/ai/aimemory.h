#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aimemory.h
// Recovered logical types: 6
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2245; PDB kind: enum.
enum idAIMemory::aiMemoryFlags_t : __int32
{
  AIMEMORY_FORCE_COVER = 0x1,
};

// IDA Local Type ordinal 2250; PDB kind: enum.
enum idAIMemory::aiSearchToStimulusMode : __int32
{
  AISEARCH_TO_STIMULUS_NONE = 0x0,
  AISEARCH_TO_STIMULUS_EYES = 0x1,
  AISEARCH_TO_STIMULUS_ORIGIN = 0x2,
};

// IDA Local Type ordinal 2258; PDB kind: enum.
enum idAIMemory::aiMemoryAnimAfterOverride : __int32
{
  AIMEMORY_ANIMAFTER_OVERRIDE_DEFAULT = 0x0,
  AIMEMORY_ANIMAFTER_OVERRIDE_IDLE = 0x1,
  AIMEMORY_ANIMAFTER_OVERRIDE_RUN = 0x2,
};

// IDA Local Type ordinal 12930; PDB kind: class.
class __declspec(align(4)) idFile_Memory : public idFile
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12932.
  virtual ~idFile_Memory();
  virtual const char *GetName();
  virtual const char *GetFullPath();
  virtual unsigned int Read(void *, unsigned int);
  virtual unsigned int Write(const void *, unsigned int);
  virtual unsigned int ReadOfs(__int64, void *, unsigned int);
  virtual unsigned int WriteOfs(__int64, const void *, unsigned int);
  virtual bool Lock(__int64, unsigned int, fsLock_t);
  virtual bool Unlock(__int64, unsigned int);
  virtual __int64 Length();
  virtual void SetLength(unsigned int);
  virtual __int64 Tell();
  virtual int Seek(__int64, fsOrigin_t);
  virtual unsigned int Printf(const char *, ...);
  virtual unsigned int VPrintf(const char *, char *);
  virtual unsigned int WriteFloatString(const char *, ...);
  virtual unsigned int Timestamp();
  virtual void Flush();
  virtual void ForceFlush();
  virtual int GetSectorSize();
  virtual fsDevice_t GetDevice();
  virtual bool IsOSNative();
  virtual void Clear(bool);

  idStrStatic<260> name;
  int mode;
  unsigned int maxSize;
  unsigned int fileSize;
  unsigned int allocated;
  unsigned int timestamp;
  char *filePtr;
  char *curPtr;
  bool ownsData;
};

// IDA Local Type ordinal 17228; PDB kind: struct.
struct __declspec(align(4)) idAIMemory::idScenePointList
{
  idList<idEntityPtr<idScenePoint>,5> scenePointList;
  bool hasSearchedForScenePoints;
};

// IDA Local Type ordinal 17232; PDB kind: class.
class __declspec(align(4)) idAIMemory
{
public:
  idAIStateTransition::aiTransCode_t transCode;
  idEntityPtr<idEntity const > currentEnemy;
  idEntityPtr<idEntity const > ambushTarget;
  idEntityPtr<idEntity const > currentAggroTarget;
  idEntityPtr<idEntity const > currentFriendly;
  idEntityPtr<idEntity const > currentNeutral;
  idEntityPtr<idEntity> currentFriendlyBlocker;
  int currentFriendlyBlockerTime;
  idAIPos currentEnemySuspectedPos;
  idAIPos lEnemyTrailPos[5];
  int nextEnemyTrailTime;
  int enemyTrailUpdatePeriod;
  int iEnemyTrailFinger;
  idEntityPtr<idEntity const > actionEntity;
  idEntityPtr<idEntity const > transitionEntity;
  idEntityPtr<idEntity const > spottedEnemyTrigger;
  idEntityPtr<idEntity const > detectedEnemyTrigger;
  idEntityPtr<idEntity> usedProp;
  idEntityPtr<idEntity const > nearbyPossessed;
  int endOpenCombatTime;
  int openCombatCoverCheckTime;
  idVec3 spawnPosition;
  int spawnTime;
  idAICover invalidCover;
  idAICover currentCover;
  idAICover lastCover;
  idAICover lCoverHistory[5];
  int nextCoverActionTime;
  int endCoverActionTime;
  int endBurstTime;
  int nextBurstTime;
  int exitCoverTime;
  int reachedCoverTime;
  int coverExposedTime;
  bool newCoverSet;
  bool forceCharge;
  idEntityPtr<idInfoPath> currentPath;
  idEntityPtr<idInfoPath const > nextPath;
  int lastDamageTime;
  int lastStunTime;
  int lastFiredAtTime;
  int lastAimedAtTime;
  int lastHeavyAimedAtTime;
  int endHeavyAimedAtTime;
  int lastHeavyFiredAtTime;
  int justAimedAtTime;
  int lastSurprisedTime;
  int lastFireTime;
  int lastIntimidationTime;
  int startIntimidationTime;
  int armorPopOffAccumulation;
  idEntityPtr<idEntity> lastAttacker;
  idEntityPtr<idEntity> lastInflictor;
  idEntityPtr<idEntity const > lastToucher;
  bool justTouched;
  idEntityPtr<idEntity> entityToPush;
  overrideAnim_t searchAction;
  alertCycle_t highestAlertCycle;
  bool enemyPathBlocked;
  bool allowCombat;
  bool allowSearch;
  idAIMemory::aiSearchToStimulusMode searchToStimulusMode;
  int enemyTravelTime;
  idVec3 enemyApproachPoint;
  idAIMemory::aiMemoryAnimAfterOverride animAfterOverride;
  idAICover cachedCover;
  idVec3 cachedDestination;
  int currentSearchHintIndex;
  int flags;
  int nextCloseMeleeTime;
  int nextMoveTime;
  int lastMoveFailedTime;
  int nextDodgeTime;
  int movementStartTime;
  int movementMaxDuration;
  int movementFailedTime;
  int lastChargeTime;
  int nextChargeTime;
  int retryCombatTime;
  idEntityPtr<idEntity const > ignoredProjectile;
  idEntityPtr<idEntity const > avoidEntity;
  idVec3 avoidancePoint;
  idVec3 avoidanceDir;
  int lastAvoidTime;
  int lastDiveTime;
  idVec3 miscVec3;
  int nextLeapAttackTime;
  idVec3 leapTarget;
  idAIProjectileInfo projectileInfo;
  int nextThrowTime;
  idAILoopAnimExitAtEnd loopAnimExitAtEnd;
  int waitExpireTime;
  aiConfidenceLevel_t confidenceLevel;
  idEntityPtr<idEntity const > fireBlocker;
  __int16 numShotsThisPullBlockedConsecutive;
  __int16 numShotsThisPullBlocked;
  __int16 numShotsThisPull;
  bool muzzleInSolid;
  bool temporaryHoldFire;
  bool shouldCrouch;
  int wantAngryRageTime;
  int wantTauntRageTime;
  int soonestAngryRageTime;
  int soonestTauntRageTime;
  int coveringFireTime;
  __int16 pathBlockedCounter;
  equipSlot_t reloadSlot;
  int lastActuallySeenEnemyTime;
  bool painFailed;
  bool killedHeavily;
  idEntityPtr<idEntity const > backstandHint;
  idMat3 backstandAlignment;
  idVec3 backstandRisePosition;
  idEntityPtr<idActionNode> currentActionNode;
  int actionNodeNum;
  int actionNodeAnimIndex;
  bool reachedActionNode;
  idAIGreetingParms greetingParms;
  int currentPlayerInteraction;
  idEntityPtr<idPlayer> interactionEntity;
  idEntityPtr<idInteractionCamera> interactionCamera;
  idEntityPtr<idInfoPath const > interactionPoint;
  const idDeclJob *completeJobDecl;
  const idDeclJob *acceptJobDecl;
  idEntityPtr<idPlayer> triggeredInteraction;
  bool interactionIsUsable;
  int actionNodeBlockedTime;
  idEntityPtr<idPlayer> controllingPlayer;
  idEntityPtr<idAIInteraction> currentInteraction;
  float scriptedAggro;
  int scriptedAggroEndTime;
  idStr varName;
  aiVarOp_t varOp;
  idStr varValue;
  idList<idVolume_ScenePoints *,5> scenePointVolumes;
  idAIMemory::idScenePointList combatScenePoints;
  idAIMemory::idScenePointList searchScenePoints;
  idAIMemory::idScenePointList roamScenePoints;
  idAIMemory::idScenePointList lookScenePoints;
  idScenePoint *curScenePoint;
  idScenePoint *curLookScenePoint;
  idScenePoint *overrideScenePoint;
  idScenePoint *keptOverrideScenePoint;
  int lastScenePointSearchTime;
  int lastLookScenePointSearchTime;
  bool curScenePointDirty;
  bool curLookScenePointDirty;
  int curScenePointTakeTime;
  int curScenePointActivateTime;
  idEntityPtr<idScenePoint_UserGroup> scenePointUserGroup;
  idScenePoint *scenePointHistory[5];
  idScenePoint *lookScenePointHistory[5];
  idEntityPtr<idVolume_Restriction> restrictionVolume;
  idAIPos restrictionPos;
  bool restrictionVolumeActive;
  bool restrictionStopOnEnter;
  int gangstaTimeout;
  bool enableGangstaPose;
};
