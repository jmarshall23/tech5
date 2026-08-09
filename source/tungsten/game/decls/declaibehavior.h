#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declaibehavior.h
// Recovered logical types: 22
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13790; PDB kind: struct.
struct idDeclGoreBehavior::fullBodyExplosion_t
{
  float chanceOfLimbloss;
  float chanceOfWound;
  float chanceOfHeadshot;
  int maxPieces;
  int maxWounds;
};

// IDA Local Type ordinal 13791; PDB kind: class.
class __declspec(align(4)) idDeclGoreBehavior : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13792.
  virtual ~idDeclGoreBehavior();
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

  idDeclGoreBehavior::fullBodyExplosion_t bodyExplosion;
  bool enableLimbloss;
  bool enableHeadShots;
  bool enableBodyWound;
  bool enableFullBodyExplosion;
  bool enableGoreWhenAlive;
};

// IDA Local Type ordinal 16646; PDB kind: struct.
struct idDeclAIBehavior::idDamageBehaviors
{
  float twitchThresholdStanding;
  float staggerThresholdStanding;
  float twitchThresholdWalking;
  float staggerThresholdWalking;
  float twitchThresholdRunning;
  float staggerThresholdRunning;
  int minStaggerPainInterval;
  float movingPainSpeed;
  float movingDeathSpeed;
  float slowMovingDeathSpeed;
  float injuredRunThreshold;
  int injuredChance;
  int injuredDontMoveCount;
  float groundBleedRate;
  float standingBleedRate;
  const idDeclDamage *bleedOutDamageDecl;
  idSkillSetting<float> difficultyDamageScale;
  __int8 hasBlood : 1;
  __int8 usesRechargeHints : 1;
  __int8 hasDeathIntensities : 1;
  __int8 hasMovingDeathAnims : 1;
  __int8 hasDeathAnims : 1;
  __int8 hasMovingPainAnims : 1;
  __int8 hasAdditivePains : 1;
  __int8 canTakeDamage : 1;
  unsigned __int8 : 2;
  __int8 fourDirExplosionPain : 1;
  __int8 usesExplosionPains : 1;
  __int8 ignoreDeathRagdoll : 1;
  __int8 deathStopsAmbientSound : 1;
  __int8 explodesOnStrike : 1;
  __int8 canRocketsImpale : 1;
  const idDeclEntityDef *explosionEntity;
  const idDeclEntityDef *lootBox;
  float shieldChargeThreshold;
  float shieldBackOnThreshold;
  aiInjuredRunMode_t injuredRunMode;
};

// IDA Local Type ordinal 16647; PDB kind: struct.
struct __declspec(align(4)) idDeclAIBehavior::idMovementBehaviors
{
  float crouchMoveMax;
  float injuredCrouchMoveMax;
  float runMoveMin;
  float sprintMoveMin;
  int coverCrouchPathTime;
  int coverRunPathTime;
  int coverSprintPathTime;
  int fireRunningToCoverChance;
  float cornerCircleRadius;
  float alignToPointDistance;
  __int8 allowEnemySightedCrouchIdle : 1;
  __int8 enemyCloseObscurityTest : 1;
  __int8 strafeMoveToEntity : 1;
  __int8 runFacingForward : 1;
  __int8 useOldAlignToPoint : 1;
  __int8 allowTransitionOvershoot : 1;
  __int8 crouchWhenStill : 1;
  __int8 runsIfShotAt : 1;
  unsigned __int8 : 7;
  __int8 obstacleAvoid_IgnorePlayer : 1;
};

// IDA Local Type ordinal 16650; PDB kind: struct.
struct __declspec(align(4)) idDeclAIBehavior::idTakeCoverBehaviors
{
  idSkillSetting<int> maxWaitTimeAfterReachingCover;
  idSkillSetting<int> minWaitInCoverTime;
  idSkillSetting<int> maxWaitInCoverTime;
  idSkillSetting<bool> usesForwardCover;
  idSkillSetting<bool> usesBackwardCover;
};

// IDA Local Type ordinal 16651; PDB kind: struct.
struct idDeclAIBehavior::idRunTypeBehaviors
{
  int scrambleRunIndex;
  int gunDownIndex;
  int downStairsIndex;
  int upStairsIndex;
  int narrowIndex;
  int duckIndex;
  int farRunIndex;
  float minFarRunDistance;
  float maxFarRunDistance;
  float blendRate;
};

// IDA Local Type ordinal 16652; PDB kind: struct.
struct idDeclAIBehavior::idIdleBehaviors
{
  int gunDownIndex;
  int narrowIndex;
  int duckIndex;
};

// IDA Local Type ordinal 16653; PDB kind: struct.
struct idDeclAIBehavior::idRageBehaviors
{
  int angryRageAfterHurtChance;
  int angryRageAfterMissingChance;
  int angryRageAfterAttractChance;
  float angryRageWhenCloseDistance;
  int tauntRageAfterHitEnemyChance;
  int tauntRageBehindEnemyChance;
  int tauntRageFleeingEnemyChance;
  int tauntRageAfterKillingEnemyChance;
  int minRageInterval;
  int maxRageInterval;
  int staleAngryRageThreshold;
  int staleTauntRageThreshold;
  bool useGroupRageLimit;
  float minRageFacingDot;
};

// IDA Local Type ordinal 16654; PDB kind: struct.
struct idDeclAIBehavior::idBackstandBehaviors
{
  float approachDistance;
  float riseDistance;
  float commitDistance;
  float attackReach;
  float standReach;
  float groundReach;
  float riseTime;
};

// IDA Local Type ordinal 16655; PDB kind: class.
class idDeclAIBehavior::idAIIntimidationBehaviors
{
public:
  aiConfidenceLevel_t minConfidenceLevel;
  aiConfidenceLevel_t maxConfidenceLevel;
  aiConfidenceLevel_t intimidationConfidence;
  aiConfidenceLevel_t minTauntConfidence;
  int minIntimidationTime;
  float healthFactor;
  float avoidFactor;
  float firedAtFactor;
  float heavyFiredAtFactor;
  float recentlyKilledGroupMemberFactor;
  float recentHeavilyKilledGroupMemberFactor;
  float recentlyKilledHeaviesFactor;
  float injured;
  float heavyConfidenceBoost;
  float deadGroupMemberCap;
  float closeEnemyFactor;
  float closeEnemyDist;
};

// IDA Local Type ordinal 16656; PDB kind: class.
class idDeclAIBehavior::idAIClanDistinctionBehaviors
{
public:
  unsigned __int8 : 3;
  __int8 dodgeOnlyAfterMemberKilled : 1;
  __int8 fallbackVo : 1;
  __int8 retreatVo : 1;
  __int8 advanceVo : 1;
  __int8 coveringFire : 1;
};

// IDA Local Type ordinal 16657; PDB kind: class.
class __declspec(align(4)) idDeclAIBehavior::idAIDodgingBehaviors
{
public:
  int gunfireDodgeCoverChance;
  int gunfireDodgeNoCoverChance;
  int aimDodgeCoverChance;
  int aimHeavyDodgeNoCoverChance;
  int painDiveCoverChance;
  int painDiveNoCoverChance;
  int gunfireHeavyDiveCoverChance;
  int gunfireHeavyDiveNoCoverChance;
  int aimHeavyDiveCoverChance;
  int aimHeavyDiveNoCoverChance;
  int gunfireFlinchChance;
  int gunfireLightDiveNoCoverChance;
  int aimLightDiveNoCoverChance;
  int gunfireForwardDiveChance;
  idSkillSetting<int> aimForwardDiveChance;
  int avoidDiveChance;
  int avoidForwardDiveChance;
  float tooCloseDist;
  float closeRangeDist;
  float mediumRangeDist;
  int aimCoverHideChance;
  int aimHeavyCoverHideChance;
  int gunfireCoverHideChance;
  int damageCoverHideChance;
  bool onlyCoverHideNoHelmet;
  int gunfireHideBailChance;
  int damageHideBailChance;
  int damageHideBailMaxChance;
  int minAimDodgeInterval;
  int maxAimDodgeInterval;
  float sidestepDistance;
  float diveDistance;
  bool mustBeDirectTarget;
  float lightFiredAtAngle;
  float mediumFiredAtAngle;
  float heavyFiredAtAngle;
  bool disableHintNodeUnderFire;
};

// IDA Local Type ordinal 16663; PDB kind: class.
class idDeclAIBehavior::idForwardCoverCaps
{
public:
  idAICoverCapabilities meleeCoverCaps;
  idAICoverCapabilities pistolCoverCaps;
  idAICoverCapabilities rifleCoverCaps;
};

// IDA Local Type ordinal 16664; PDB kind: class.
class idDeclAIBehavior::idBackwardCoverCaps
{
public:
  idAICoverCapabilities meleeCoverCaps;
  idAICoverCapabilities pistolCoverCaps;
  idAICoverCapabilities rifleCoverCaps;
};

// IDA Local Type ordinal 16665; PDB kind: class.
class idDeclAIBehavior::idDynamicCoverCaps
{
public:
  unsigned __int8 : 5;
  __int8 providesFormationCover : 1;
  __int8 usesFormationCover : 1;
  __int8 usesVehicleCover : 1;
};

// IDA Local Type ordinal 16674; PDB kind: class.
class idDeclAIBehavior : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16675.
  virtual ~idDeclAIBehavior();
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

  int traversalAimEvasionDuration;
  int traversalGunfireEvasionDuration;
  int traversalAttackTolerance;
  float traversalEvasionAimDist;
  float traversalEvasionGunfireDist;
  __int8 canUseTeleporters : 1;
  __int8 canUseElevators : 1;
  __int8 canUseLadders : 1;
  __int8 canClimbBarriers : 1;
  __int8 canDropOffBarriers : 1;
  __int8 canClimbLedges : 1;
  __int8 canDropOffLedges : 1;
  __int8 canUseStairs : 1;
  __int8 usesSearch : 1;
  __int8 isVehicleChaser : 1;
  __int8 useTurningCircles : 1;
  __int8 hasBumpedReaction : 1;
  __int8 canUseTraversalEvasions : 1;
  __int8 canUseTraversals : 1;
  __int8 canSwim : 1;
  __int8 canJump : 1;
  __int8 usesOnElevator : 1;
  __int8 usesBackStand : 1;
  __int8 usesPanic : 1;
  __int8 usesAvoidCower : 1;
  __int8 usesAvoidDive : 1;
  __int8 usesAvoidCover : 1;
  __int8 usesAvoidRun : 1;
  __int8 usesAvoid : 1;
  unsigned __int8 : 5;
  __int8 usesCombatLookFocusRelaxed : 1;
  __int8 usesCombatLookFocus : 1;
  __int8 canBeTagged : 1;
  idDeclAIBehavior::idDamageBehaviors damageBehaviors;
  __int8 usesStrafeApproach : 1;
  __int8 usesSneakUpOnEnemy : 1;
  __int8 usesMelee : 1;
  __int8 usesOpenCombat : 1;
  __int8 usesFallback : 1;
  __int8 usesAdvance : 1;
  __int8 usesScenePoints : 1;
  __int8 usesCombat : 1;
  unsigned __int8 : 4;
  __int8 subtitlesInCombat : 1;
  __int8 usesShootIdle : 1;
  __int8 dontLeaveTurretsEasily : 1;
  __int8 usesTurrets : 1;
  equipSlot_t weaponSlot;
  float friendlyAttitudeAdjust;
  float neutralAttitudeAdjust;
  float attitudeAdjust;
  idSkillSetting<float> throwLag;
  idSkillSetting<float> maxThrowError;
  aiItemSelect_t itemSelect[3];
  float muzzleTraceClearOffset;
  float minThrowDot;
  idDeclAmmo *combatAmmo;
  float aimOffset;
  idDeclAIBehavior::idMovementBehaviors movementBehaviors;
  idList<enum encounterGroupRole_t,5> rolePreferenceOrder;
  idRelationship::attitude_t followFriendlyThreshold;
  bool lookAtFriendlyTarget;
  bool chasesProjectiles;
  bool canGreetPlayers;
  bool canGreetHumans;
  bool investigatesBody;
  idDeclAIBehavior::idTakeCoverBehaviors takeCoverBehaviors;
  __int8 hasCrouches : 1;
  __int8 has157Turns : 1;
  __int8 hasCombatSprints : 1;
  __int8 hasWalkInserts : 1;
  __int8 hasSyncedWalks : 1;
  __int8 hasCombatWalks : 1;
  __int8 canRetreat : 1;
  __int8 canCharge : 1;
  unsigned __int8 : 7;
  __int8 hasBackStandLerps : 1;
  unsigned __int8 doubleBlinkChance;
  __int16 doubleBlinkInterval;
  __int16 minBlinkInterval;
  __int16 maxBlinkInterval;
  __int16 jitterMinInterval;
  __int16 jitterMaxInterval;
  idDeclAIBehavior::idRunTypeBehaviors runTypeBehaviors;
  idDeclAIBehavior::idIdleBehaviors idleBehaviors;
  float openCombatDuration;
  float exposeCoverDistance;
  float exposeCoverMinDistance;
  float optimalCoverDistance;
  float exposeCoverTravelTime;
  int exposeCoverOpenCombatChance;
  float coverPathNearDistance;
  int minFireFromCoverDuration;
  int maxFireFromCoverDuration;
  int repeatExposeCoverChargeTime;
  idRelationship::attitude_t friendlyFireThreshold;
  float freeAmmoDistance;
  idDeclAIBehavior::idRageBehaviors rageBehaviors;
  float enemyTooCloseToGoProne;
  float enemyTooCloseToGoProneFacing;
  float closeMeleeDist;
  float mediumMeleeDist;
  float longMeleeDist;
  float movingMeleeDist;
  int minCloseMeleeInterval;
  int maxCloseMeleeInterval;
  float meleeExtrapolate;
  const idDeclDamage *closeMeleeKickDamage;
  const idDeclDamage *closeMeleePunchDamage;
  const idDeclProjectileImpactEffect *meleeImpactEffect;
  int meleeFromStunChance;
  int stunIgnoreTime;
  int leapAttackChance;
  int minLeapAttackInterval;
  int maxLeapAttackInterval;
  float maxLeapAttackDistance;
  float minLeapAttackDistance;
  float leapAttackTargetExtrapolate;
  float leapAttackSpeed;
  idDeclAIBehavior::idBackstandBehaviors backstandBehaviors;
  idDeclAIBehavior::idAIIntimidationBehaviors intimidation;
  idDeclAIBehavior::idAIClanDistinctionBehaviors clanDistinctionBehaviors;
  int maxChargeDuration;
  int minChargeInterval;
  int maxChargeInterval;
  int chargeChance;
  float minChargeDistance;
  float maxChargeDistance;
  idDeclAIBehavior::idAIDodgingBehaviors dodging;
  int meleeDodgeChance;
  int minMeleeDodgeInterval;
  int maxMeleeDodgeInterval;
  float noticeGrenadeChance;
  int minThrowInterval;
  int maxThrowInterval;
  int minOCThrowInterval;
  int maxOCThrowInterval;
  int minCoverDuration;
  int maxCoverDuration;
  int noContactInterval;
  int breakCoverDuration;
  int combatTimeoutInterval;
  int searchTimeoutInterval;
  int obstacleStopDistance;
  int surroundRadius;
  int minControlTime;
  int maxControlTime;
  int controlIntroDuration;
  const idDeclDamage *controlSelfDamage;
  const idDeclDamage *controlSplashDamage;
  const idDeclParticle *controlEndParticle;
  const idDeclFaction *berzerkerFaction;
  const idDeclParticle *bfgDeathParticle;
  idDeclAIBehavior::idForwardCoverCaps forwardCoverCaps;
  idDeclAIBehavior::idBackwardCoverCaps backwardCoverCaps;
  idDeclAIBehavior::idDynamicCoverCaps dynamicCoverCaps;
  idList<idAIFormation,5> formations;
  idStaticList<idDeclAITurnParms const *,3> turnParms;
  idAINavPowerMoverParms navpower;
};

// IDA Local Type ordinal 16677; PDB kind: class.
class idDeclAIBehaviorVO::idVoiceSearch
{
public:
  idVoiceInfo startFromCombat;
};

// IDA Local Type ordinal 16678; PDB kind: class.
class idDeclAIBehaviorVO::idVoiceCombat
{
public:
  idVoiceInfo changePosition;
  idVoiceInfo firstSpot;
  idVoiceInfo reSpot;
  idVoiceInfo flankSpot;
  idVoiceInfo downed;
  idVoiceInfo losingBattle;
  idVoiceInfo reload;
  idVoiceInfo fightMotivation;
  idVoiceInfo fightMotivationResponse;
};

// IDA Local Type ordinal 16679; PDB kind: struct.
struct idDeclAIBehaviorVO::jobResponseInfo_t
{
  idDeclJobRef jobDecl;
  const idDeclVoiceOver *voiceOver;
};

// IDA Local Type ordinal 16681; PDB kind: class.
class idDeclAIBehaviorVO : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16682.
  virtual ~idDeclAIBehaviorVO();
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

  idDeclAIBehaviorVO::idVoiceSearch search;
  idDeclAIBehaviorVO::idVoiceCombat combat;
  idList<idDeclAIBehaviorVO::jobResponseInfo_t,5> jobResponseInfo;
};

// IDA Local Type ordinal 16688; PDB kind: class.
class idDeclAIBehaviorVOChains : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16689.
  virtual ~idDeclAIBehaviorVOChains();
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

  idList<idVOChain,5> combatVoChains;
};

// IDA Local Type ordinal 16690; PDB kind: class.
class idDeclAIBehaviorEvents : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16691.
  virtual ~idDeclAIBehaviorEvents();
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

  const idDeclAiEvent *bodyEventDecl;
  const idDeclAiEvent *electricDeathEventDecl;
  const idDeclAiEvent *mutantAttackEventDecl;
  const idDeclAiEvent *possessionEventDecl;
  const idDeclAiEvent *deadBodyLandEventDecl;
  const idDeclAiEvent *gotKilledVoiceEventDecl;
  const idDeclAiEvent *sawSomethingVoiceEventDecl;
  const idDeclAiEvent *heardSomethingVoiceEventDecl;
  const idDeclAiEvent *memberKilledVoiceEventDecl;
  const idDeclAiEvent *foundDeadBodyVoiceEventDecl;
  const idDeclAiEvent *enemySightedVoiceEventDecl;
  const idDeclAiEvent *injuredVOEventDecl;
  const idDeclAiEvent *crapVOEventDecl;
  const idDeclAiEvent *intimidatedVOEventDecl;
  const idDeclAiEvent *enemyKilledVOEventDecl;
  const idDeclAiEvent *losingBattleVOEventDecl;
  const idDeclAiEvent *memberKilledVOEventDecl;
};
