#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\drone.h
// Recovered logical types: 9
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1952; PDB kind: unknown.
enum idDrone::<unnamed_tag> : __int32
{
  BOTTOM_ATTACHMENT = 0x0,
  TOP_ATTACHMENT = 0x1,
  LEFT_ATTACHMENT = 0x2,
  RIGHT_ATTACHMENT = 0x3,
  NUM_ATTACHMENTS = 0x4,
};

// IDA Local Type ordinal 1953; PDB kind: enum.
enum idDrone::droneState_t : __int32
{
  DS_WAITING = 0x0,
  DS_SEARCHING = 0x1,
  DS_MOVING = 0x2,
  DS_SCANNING = 0x3,
  DS_RETREATING = 0x4,
  DS_HIDE = 0x5,
  DS_DEATH = 0x6,
  DS_SET_SPEED = 0x7,
  DS_ADJUST_SPEED = 0x8,
  DS_NUM_DRONE_STATES = 0x9,
};

// IDA Local Type ordinal 1954; PDB kind: enum.
enum idDrone::droneMoveState_t : __int32
{
  DMS_STOPPED = 0x0,
  DMS_SEARCHING = 0x1,
  DMS_SLOW = 0x2,
  DMS_NORMAL = 0x3,
  DMS_FAST = 0x4,
  DMS_NUM_DRONE_MOVE_STATES = 0x5,
};

// IDA Local Type ordinal 1955; PDB kind: enum.
enum idDrone::dronePathType_t : __int32
{
  DPT_MOVE_TO = 0x0,
  DPT_PATROL = 0x1,
  DPT_SEARCH = 0x2,
  DPT_GOAL = 0x3,
  DPT_AVOID = 0x4,
  DPT_NUM_DRONE_PATH_TYPES = 0x5,
};

// IDA Local Type ordinal 1956; PDB kind: enum.
enum idDrone::droneDeath_t : __int32
{
  DD_EXPLOSION = 0x0,
  DD_SPINNING_OUT_OF_CONTROL = 0x1,
  DD_RANDOM_DRONE_DEATH = 0x2,
};

// IDA Local Type ordinal 15945; PDB kind: class.
class __declspec(align(8)) idDrone : public idAnimatedEntity
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15979.
  virtual idTypeInfo *GetType();
  virtual ~idDrone();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void PostSpawn();
  virtual void Remove();
  virtual void DeleteSubEntities();
  virtual bool Draw(idPlayer *);
  virtual void JobSync();
  virtual void Think();
  virtual void PauseThink();
  virtual bool ShouldEnterDormancy();
  virtual bool ShouldLeaveDormancy();
  virtual void DormantBegin();
  virtual void DormantEnd(const int);
  virtual idRenderModelInfo *GetRenderModelInfo();
  virtual const idRenderModelInfo *GetRenderModelInfo_2();
  virtual void GetScale(idVec3 *);
  virtual void SetScale(const idVec3 *);
  virtual void SetModelByName(const char *);
  virtual void SetModel(idRenderModel *);
  virtual const idMaterial *GetCustomMaterial();
  virtual void SetColor(const idVec4 *);
  virtual void SetColor_2(const idColor *);
  virtual void SetColor_3(const idVec3 *);
  virtual void SetColor_4(float, float, float);
  virtual void SetColor_5(float, float, float, float);
  virtual void GetColor(idVec4 *);
  virtual void GetColor_2(idColor *);
  virtual void GetColor_3(idVec3 *);
  virtual void Hide(bool);
  virtual void Hide_2();
  virtual void Show();
  virtual void GetModelTransform(idVec3 *, idMat3 *);
  virtual void GetSoundTransform(idVec3 *, idMat3 *);
  virtual void UpdateModelTransform();
  virtual void UpdateFX();
  virtual void ProjectOverlay(const idVec3 *, const idVec3 *, float, const char *);
  virtual idPresentable *AllocPresentable(idRenderModel *);
  virtual const idComponentTimeLine *GetComponentTimeLine();
  virtual idComponentTimeLine *GetComponentTimeLine_2();
  virtual bool UpdateAnimationControllers();
  virtual void UpdateAttachments();
  virtual const idAnimStack *GetAnimStack();
  virtual idAnimStack *GetAnimStack_2();
  virtual idIndex<short,enum invalidJointIndex_t> *GetJointIndexFromTrace(idIndex<short,enum invalidJointIndex_t> *result, trace_t);
  virtual awPathResult_t ChangeAnimWebState(const char *, const char *);
  virtual awPathResult_t ChangeAnimWebState_2(const char *);
  virtual awPathResult_t ForceAnimWebState(const char *);
  virtual awPathResult_t ChangeAnimWebStateVia(const char *, const char *, const char *, const char *);
  virtual awPathResult_t ChangeAnimWebStateVia_2(const char *, const char *);
  virtual idAnimWebCmdCtx *GetAnimWebCmdCtx();
  virtual const idAnimWebCmdCtx *GetAnimWebCmdCtx_2();
  virtual const idAnimator_AF *GetAF();
  virtual idAnimator_AF *GetAF_2();
  virtual void PreBind();
  virtual void PostBind();
  virtual void PreUnbind();
  virtual void PostUnbind();
  virtual const splineLocation_t *GetSplineLocation();
  virtual void SetAxis(const idMat3 *);
  virtual bool CanDisablePhysics(const idEntity *);
  virtual collide_t Collide(const int, trace_t *, const idVec3 *);
  virtual collide_t Contact(const int, contactInfo_t *);
  virtual void ApplyImpulse(const int, const int, const idVec3 *, const idVec3 *);
  virtual void ApplyImpulseFromEntity(const idEntity *, const int, const idVec3 *, const idVec3 *);
  virtual void ApplyForce(const int, const int, const idVec3 *, const idVec3 *);
  virtual bool Crush(const int);
  virtual void ApplyDamage(const int, const int, const idDeclDamage *);
  virtual void ActivatePhysics(const int);
  virtual void DeactivatePhysics(const int);
  virtual void ApplyWaterEffects(const int, const int);
  virtual void ApplyWaterSplashEffects(const int, const int, surfTypes_t, idPhysicsCallbacks::splashState_t);
  virtual bool TakesDamage();
  virtual void DamageFeedback(idEntity *, idEntity *, const idDeclDamage *, float *);
  virtual void KilledNotification(const idEntity *, const idEntity *, const idDeclDamage *, const float);
  virtual float Damage(idEntity *, idEntity *, const idDeclDamage *, const float, const idVec3 *, trace_t *);
  virtual bool CalcDamageImpulse(const idEntity *, const idEntity *, const idDeclDamage *, const float, const idVec3 *, const trace_t *, idVec3 *, idVec3 *);
  virtual bool IsTargetLockable(const idDeclAmmo *);
  virtual void AddProjectileLock();
  virtual void RemoveProjectileLock();
  virtual const idScriptObject *GetScriptObject();
  virtual idScriptObject *GetScriptObject_2();
  virtual bool ShouldConstructScriptObjectAtSpawn();
  virtual idThread *GetStateThread();
  virtual int AddThread(const idHandle<int,enum invalidThreadHandle_t,0>);
  virtual void RemoveThread(const idHandle<int,enum invalidThreadHandle_t,0>);
  virtual idHandle<int,enum invalidThreadHandle_t,0> *GetThread(idHandle<int,enum invalidThreadHandle_t,0> *result, const int);
  virtual int NumThreads();
  virtual int MaxThreads();
  virtual void ExecuteThread(idThread *);
  virtual void ResetFSMWaitThreadIfPossible(idThread *);
  virtual bool HandleGuiEvent(const sysEvent_t *);
  virtual void ActivateTargets(idEntity *);
  virtual bool GetRcCarCanTarget();
  virtual const idBaseHealth *GetHealthComponent();
  virtual idBaseHealth *GetHealthComponent_2();
  virtual const idSmartLootComponent *GetSmartLootComponent();
  virtual idSmartLootComponent *GetSmartLootComponent_2();
  virtual void Teleport(const idVec3 *, const idAngles *);
  virtual bool IsPusher();
  virtual const idList<idEntityPtr<idEntity>,5> *GetTriggerTouchList();
  virtual idList<idEntityPtr<idEntity>,5> *GetTriggerTouchList_2();
  virtual void TestFunctionality();
  virtual float GetUsableDistance();
  virtual float GetCrosshairIconDistance();
  virtual usableState_t GetUsableState(const idEntity *, const idFocusTrace *);
  virtual bool ModifyCrosshairInfo(const idEntity *, const idFocusTrace *, const usableState_t, idCrosshairInfo *);
  virtual bool IsCrosshairDisabled(const idEntity *, const idFocusTrace *, const usableState_t);
  virtual bool IsCrosshairSubdued(const idEntity *, const idFocusTrace *, const usableState_t);
  virtual bool IsEverUsable(const idEntity *);
  virtual bool IsCurrentlyUsable(const idEntity *);
  virtual bool Use(idEntity *, const usableState_t);
  virtual void Dropped(idEntity *, const idDeclInventory *);
  virtual const idInventoryCollection *GetInventory();
  virtual idInventoryCollection *GetInventory_2();
  virtual void InventoryAdded(idInventoryItem *, int);
  virtual void InventoryRemoved(idInventoryItem *);
  virtual const idAttachmentCollection *GetAttachments();
  virtual idAttachmentCollection *GetAttachments_2();
  virtual void EnableAIEventResponse(const idAIEvent::aiEventClass_t);
  virtual void DisableAIEventResponse(const idAIEvent::aiEventClass_t);
  virtual bool CanReceiveAIEvents(const int);
  virtual bool RespondsToAIEvent(const idAIEvent *);
  virtual void OnAIEvent(const idAIEvent *);
  virtual bool IsDead();
  virtual bool IsDying();
  virtual idFaction *GetFaction();
  virtual const idFaction *GetFaction_2();
  virtual idEntityAuditor *GetAuditor();
  virtual void GetVisibilityPoint(const visPoint_t, idVec3 *);
  virtual void GetAimPoint(const aimPoint_t, idVec3 *);
  virtual void GetEyePos(idVec3 *);
  virtual bool IsVisible();
  virtual idDynamicCoverMgr *GetDynamicCoverMgr();
  virtual const idDynamicCoverMgr *GetDynamicCoverMgr_2();
  virtual const idAAS2 *GetAAS();
  virtual void GetViewStateFOV(idVec3 *, unsigned __int8 *, unsigned __int8 *);
  virtual void GetViewStateFOV_2(idVec3 *, unsigned __int8 *, unsigned __int8 *);
  virtual int GetNumRepairBotTetherPoints();
  virtual bool GetRepairBotTetherPoint(const int, const int, idVec3 *);
  virtual idEntityInterface *CreateEntityInterface(idGame *);
  virtual void ShowEditingDialog();
  virtual void UpdateEditingDialog();
  virtual void UpdateModifiedProperties();
  virtual inputSettings_t *GetInputSettings(inputSettings_t *result, idPlayer *);
  virtual bool EvaluateControls(usercmd_t *, usercmd_t *);
  virtual void CheckForErrors(idList<idStr,5> *);
  virtual void DebugDrawEntity(const idColor *, int);
  virtual void ClientThink();
  virtual void Serialize(idSerializer *);
  virtual void PostSerializeRead(bool);
  virtual void OnActivate(idEntity *);
  virtual void OnMakeActivatable(const bool);
  virtual void OnNotifyProgressionOwner();
  virtual void Reset();
  virtual int GetDefaultSurfaceType();
  virtual idList<idIndex<short,enum invalidJointIndex_t>,5> *GetRadiusDamageJointIndices();
  virtual const idList<idIndex<short,enum invalidJointIndex_t>,5> *GetRadiusDamageJointIndices_2();
  virtual idMD6Node *GetMD6Tree();
  virtual const idMD6Node *GetMD6Tree_2();
  virtual idAnimator_AnimWeb *GetAnimatorAnimWeb();
  virtual bool IsAnimating();
  virtual const idDeclFX *GetFXDecl();
  virtual const idDeclFacialAnimationSet *GetFacialAnimationSet();
  virtual float GetHealth();

  bool slowForPlayer;
  idEntityPtr<idNavSplinePath> initialPath;
  idEntityPtr<idSplineWaypoint> initialWaypoint;
  idDrone::droneState_t initialState;
  bool fleeNearEnemyFlag;
  float startingHealth;
  const idDeclParticle *smokeParticle[3];
  const idDeclParticle *sparkParticle[2];
  const idDeclParticle *sputterParticle[3];
  const idDeclParticle *deathParticle[3];
  const idDeclProjectileImpactEffect *declWallSpark;
  const idDeclBreakable *declBreakable;
  idEnum<enum idDrone::droneState_t,9> currentState;
  idEnum<enum idDrone::droneState_t,9> nextState;
  int changeStateTime;
  idEnum<enum idDrone::droneState_t,9> lastNonScanState;
  idEnum<enum idDrone::droneMoveState_t,5> moveStates[4];
  float moveStateMemberships[4];
  float moveStateMembershipDeltas[4];
  idDrone::dronePathType_t currentPathType;
  int currentPathTypeParm;
  int patrolWaypointOn;
  int patrolDirection;
  idList<idSplineWaypoint const *,5> patrolWaypoints;
  float searchDirection;
  int searchNextUpdateTime;
  idList<idSplineWaypoint const *,5> goals;
  idList<float,5> goalSearchDirections;
  idVec3 splineAheadPositions[4];
  bool firstThinkFlag;
  float health;
  idVec3 currentPosition;
  idVec3 previousOrigin;
  idVec3 desiredFacing;
  idVec3 currentFacing;
  float allowFacingChanges;
  idMat3 currentAxis;
  idMat3 previousAxis;
  float desiredSpeed;
  float desiredSpeedMultiplier;
  float overrideMaxDesiredSpeed;
  int resetSpeedOverrideCounter;
  float currentSpeed;
  float allowSpeedChanges;
  float lastFrameOverMove;
  float desiredRoll;
  float currentRoll;
  float allowRollChanges;
  float pitchToAlterSpeed;
  float lookUpToGoUpAount;
  float lowerNoseWhenAccelerating;
  float emergencyBrakeScaler;
  float obstacleAvoidanceMaxSpeed;
  idVec3 goalAvoidanceOffset;
  idVec3 averageAvoidanceOffset;
  int numActivates;
  idAttachmentCollection attachments;
  idHandle<int,enum invalidAttachment_t,-1> attachmentHandles[4];
  float weaponStatus[4];
  float weaponArmSpeed[4];
  int weaponArmTime[4];
  int weaponDisarmTime[4];
  idNavSplinePosition navSplinePosition;
  navSplinePath_t splinePathToGoal;
  idAISplinePathMgr *splinePathMgr;
  float deltaToFinalGoal;
  float distanceToFinalGoal;
  idNavSplinePosition immediateGoalSplinePosition;
  idVec3 immediateGoalPosition;
  idVec3 finalGoalPosition;
  float goalRightDistance;
  float splineDistanceToFinalGoal;
  float rightDistanceToFinalGoal;
  float nearestPlayerDistance;
  float outOfControl;
  idVec3 additivePosition;
  idVec3 additiveMomentum;
  idQuat additiveFacing;
  idQuat additiveAngularMomentum;
  idClipQuery clipQuery;
  const idDeclParticle *groundParticlesFromFan;
  float secBetweenAdd;
  float maxAltitude;
  float particlesMultiplier;
  float addedParticleMovement;
  idEntityInfluenceTrail influence;
  float controllerShakeHighMag;
  float controllerShakeLowMag;
  int nextGroundFXTime;
  idClipQuery fanToGroundQuery[3];
  idList<idDrone::blendedSounds_t,5> smallEngineSounds;
  idList<idDrone::blendedSounds_t,5> largeEngineSounds;
  idList<idDrone::blendedSounds_t,5> afterburnerSounds;
  const idSoundShader *scannerSound;
  const idSoundShader *stopScannerSound;
  const idSoundShader *deployWeaponSound;
  const idSoundShader *stowWeaponSound;
  const idSoundShader *scanPlayerSound;
  const idSoundShader *explosionSound;
  float minPitchByClosing;
  float maxPitchByClosing;
  float largeEngineThrustLevel;
  float smallEngineThrustLevel;
  float afterburnerThrustLevel;
  float engineSoundsFade;
  const idDeclTrackingParms *declTrackingParms;
  idFaction faction;
  float visibleSightTime;
  float visibleSightRadius;
  float disengageEnemyDistance;
  float optimalFocusEntityDistance;
  float optimalFocusAICuriosity;
  float optimalFocusPlayerCuriosity;
  const idMaterial *focusEntityMaterial;
  float focusEntityWidth;
  float focusEntityLength;
  idLaserBeam focusEntityEffect;
  idAIWorldState worldState;
  idEntityPtr<idEntity> currentEnemy;
  bool isScannerOn;
  idEntityPtr<idEntity> currentScanEntity;
  float currentScanEntityCuriosity;
  float currentScanEntityEffectOn;
  idList<idEntityPtr<idEntity>,5> previousFocusEntities;
  idList<int,5> previousFocusEntityTimes;
  float focusEntityScanBob;
  float focusEntityScanBobDelta;
  idEntityPtr<idEntity> nearestForwardAi;
  int nearestForwardAiTime;
  const idMaterial *thrusterMaterial;
  float thrusterWidth;
  float thrusterLength;
  idLaserBeam thrusterEffect;
  float lastThrusterPower[10];
  float thrusterShown[10];
  fxExtraCondition_t thrusterFx[10];
  bool wasAfterburnerFxStarted;
  idVec3 lastMovement;
  idVec3 previousNonThrustMovement;
  float thrusterPerceivedFriction;
  float afterburnerAmount;
  int nextAfterburnerSmokeTime;
  idVec3 bobGoal;
  float engineSmokeAmount;
  int nextEngineSmokeTime;
  int nextSputterTime;
  idEffectPhysicsDebrisEmitter debrisEmitter;
  idList<idEntityPtr<idEntity>,5> touching;
  idNavPathPosTracker *enemyTracker;
  idList<idDrone::behaviorPoint_t,5> behaviorPoints;
  int nextBehaviorPointToTest;
  idList<idDrone::damageBehavior_t,5> damageBehaviors;
  float activateCuriosityOverride;
  int currentBehaviorPoint;
  idVec3 ahead[4];
  float aheadDistance[4];
  idVec3 toAhead[4];
  idVec3 aheadToAhead[4];
  float dot0to1to2;
  float dot1to2to3;
  bool rigidPhysicsEnabled;
  idPhysics_RigidBody rigidPhysics;
  bool wasRemoveEventPosted;
  idDrone::droneDeath_t deathVarietyDesired;
  int deathDoneTime;
  idEntityPtr<idEntity> deathTrigger;
  float delayToHideDrone;
  float minDeathThrustDuration;
  float maxDeathThrustDuration;
  idVec3 recentForceApplied;
  idVec3 deathThrust;
  __unaligned __declspec(align(1)) idLinkList<idDrone> droneNode;
};

// IDA Local Type ordinal 15949; PDB kind: struct.
struct idDrone::blendedSounds_t
{
  const idSoundShader *sound;
  float minSpeedPitch;
  float maxSpeedPitch;
  float minThrustPitch;
  float maxThrustPitch;
  float minThrustVolume;
  float maxThrustVolume;
};

// IDA Local Type ordinal 15975; PDB kind: struct.
struct idDrone::behaviorPoint_t
{
  idEntityPtr<idEntity> entityToScan;
  int minTriggerCount;
  int maxTriggerCount;
  float distanceToScan;
  float slowDistance;
  float forcedCuriosity;
  float scanChance;
  int maxNumScans;
  idEntityPtr<idEntity> startScanTrigger;
  idEntityPtr<idEntity> endScanTrigger;
  idDrone::droneState_t exitScanState;
  idEntityPtr<idSplineWaypoint> endScanWaypoint;
  float endScanDesiredSpeedMultiplier;
  bool wasDroneWithinRange;
  int numScansDone;
  int nextScanTime;
};

// IDA Local Type ordinal 15977; PDB kind: struct.
struct __declspec(align(4)) idDrone::damageBehavior_t
{
  int minTriggerCount;
  int maxTriggerCount;
  float healthPercent;
  idEntityPtr<idEntity> trigger;
  bool scanAttackerFlag;
  idEntityPtr<idEntity> scanEntity;
  float forcedCuriosity;
  float desiredSpeedMultiplier;
  bool hasBehaviorTriggered;
};
