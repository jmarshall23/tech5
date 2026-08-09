#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\turretgunner.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1692; PDB kind: enum.
enum idTurretGunner::triggerPhaseOn_t : __int32
{
  TRIGGERPHASE_IDLE = 0x0,
  TRIGGERPHASE_START_PULL = 0x1,
  TRIGGERPHASE_WINDING_UP = 0x2,
  TRIGGERPHASE_FIRING = 0x3,
  TRIGGERPHASE_WINDING_DOWN = 0x4,
  TRIGGERPHASE_MAX = 0x5,
};

// IDA Local Type ordinal 1696; PDB kind: enum.
enum idTurretGunner::firingPhaseOn_t : __int32
{
  FIRINGPHASE_SHOOTING_AT_PLAYER = 0x0,
  FIRINGPHASE_SHOOTING_AT_PLAYERS_LAST_POSITION = 0x1,
  FIRINGPHASE_SUPPRESSING_NEAR_PLAYER = 0x2,
  FIRINGPHASE_SUPPRESSING_AT_ANTICIPATED_POSITION = 0x3,
  FIRINGPHASE_SUPPRESSING_NEAR_PLAYER_AGAIN = 0x4,
  FIRINGPHASE_SUPPRESSING_RANDOM = 0x5,
  FIRINGPHASE_MAX = 0x6,
};

// IDA Local Type ordinal 18986; PDB kind: class.
class idTurretGunner : public idAnimatedEntity
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18988.
  virtual idTypeInfo *GetType();
  virtual ~idTurretGunner();
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
  virtual void SetHealth(const float);
  virtual float GetMaxBaseHealth();
  virtual void SetMaxHealth(const float);

  const idDeclAnimWeb *webDecl;
  const idDeclTrackingParms *declTrackingParms;
  float minMinionHeadStartTime;
  float maxMinionHeadStartTime;
  idFaction faction;
  const idMaterial *aiPortrait;
  idList<idStr,5> radiusDamageJointNames;
  const idDeclGore *goreDef;
  idGoreComponent goreComponent;
  idTurretSpawnerControlGroup *spawnerControlGroup;
  bool isGunnerInitialized;
  bool canFire;
  idVec3 gunnerAimPoint;
  __unaligned __declspec(align(1)) idAnimWeb_TurretGunner animWeb;
  idAnimator_Channel painAnimator;
  idFaceMgr faceMgr;
  idAIWorldState worldState;
  idEntityPtr<idEntity> enemy;
  int oldNumKilled;
  idEntityPtr<idEntity> randomLivingMinion;
  int numSkippedPinatas;
  idEntityPtr<idEntity> pinataMinion;
  int forgivePinataMinionTime;
  float maxHealth;
  float health;
  bool didBonusDamageForThisTaunt;
  int nextFireTime;
  int pullTriggerTime;
  int releaseTriggerTime;
  int launchInitialMinionTime;
  int launchMinionTime;
  int minionEscalationLevel;
  int overheatTime;
  float currTriggerDownAdjust;
  float currFireIntervalAdjust;
  idTurretGunner::firingPhaseOn_t currentFiringPhaseOn;
  int endPhaseTime;
  idTurretGunner::triggerPhaseOn_t pullTriggerPhase;
  int pullTriggerPhaseEndTime;
  idEntityPtr<idAICombatHint> closestFireHint;
  idEntityPtr<idAICombatHint> anticipatedFireHint;
  idList<idEntityPtr<idAICombatHint>,5> otherFireHintsList;
  int otherFireHintOn;
  idEntityPtr<idAICombatHint> lastFireHintUsed;
  idEntityPtr<idAICombatHint> currentSuppressionFireHint;
  int startStrafeTime;
  int endStrafeTime;
  int thisStrafeTime;
  idVec3 startStrafePoint;
  idVec3 endStrafePoint;
};

// IDA Local Type ordinal 18987; PDB kind: class.
class idAnimWeb_TurretGunner : public idAnimator_AnimWeb
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18989.
  virtual ~idAnimWeb_TurretGunner();
  virtual idAnimator_Base::priority_t GetStackPriority();
  virtual serializeType_t GetSerializeType();
  virtual void SerializeSnapshot(idSerializer *);
  virtual void PreBlendSnapshot(idAnimStack *, int, const int, float);
  virtual void PreSerializeInit(idAnimStack *, idClip *, idGameTimeManager *);
  virtual bool InternalInit(const idAnimatorParms_Base *);
  virtual bool InternalPostInit(const idAnimatorParms_Base *);
  virtual void InternalShutdown(idAnimStack *);
  virtual void InternalPreBlendTree(const idAnimStack *, const int, const int);
  virtual void InternalPostBlendTree(const idAnimStack *, const int);
  virtual void InternalStart(const idAnimStack *, const int, const idTypesafeNumber<int,enum gameTimeUnique_t>);
  virtual void InternalEnd(const idAnimStack *, const int, const idTypesafeNumber<int,enum gameTimeUnique_t>);
  virtual void InternalBlend(const idAnimStack *, const int, const float, const idTypesafeNumber<int,enum gameTimeUnique_t>);
  virtual bool InternalIsContributing();
  virtual const idMD6Branch *InternalGetMergeBranch();
  virtual idMD6Branch *InternalGetMergeBranch_2();
  virtual void InternalPause(const idAnimStack *, const idTypesafeNumber<int,enum gameTimeUnique_t>);
  virtual void InternalUnpause(const idAnimStack *, const idTypesafeNumber<int,enum gameTimeUnique_t>);
  virtual const idMD6Branch *InternalGetEndBranch();
  virtual idMD6Branch *InternalGetEndBranch_2();
  virtual const idHandle<short,enum invalidAnimWebHandle_t,-1> *GetHandle();
  virtual void InternalInitWeb();
  virtual void InternalUpdate(const int);
  virtual idDeclAnimWebNode::animDelta_t InternalGetCurrentAnimDeltaMode();
  virtual void InternalSetAnimDelta(const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t>, const idDeclAnimWebNode *);
  virtual int InternalGetEdgeCost(const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>, const idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>);
  virtual void InternalStartPath();
  virtual void InternalUpdateScalars(const int);
  virtual void InternalStartBlend(const idDeclAnimWebNode *, const idDeclAnimWebNode *, const int);
  virtual void InternalFinishBlend(const idDeclAnimWebNode *, const idDeclAnimWebNode *, const int);
  virtual awCheckPathResult_t CheckNextNode(const idDeclAnimWebNode *, const idDeclAnimWebNode *);
  virtual bool InternalShouldStartNextNode(const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>, const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>, const int, const int, const blendParms_t *, idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t>, const bool, animWebEvent_t *);
  virtual void InternalTriggerEvent(const idDeclAnimWebNode *, const animWebEvent_t, const idHandle<short,enum invalidAnimWebHandle_t,-1> *, const int, const int);
  virtual void InternalTriggerBlendEvent(int, idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t>, idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>, idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>, const int);
  virtual bool InternalRemapNames(idStr *, idStr *);
  virtual void InternalUpdateBlendEvents(const idAnimStack *, const int, const int);

  idTurretGunner *gunner;
};
