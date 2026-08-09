#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aiplayerinteraction.h
// Recovered logical types: 14
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1316; PDB kind: enum.
enum aiPlayerInteraction_t::interactionTestConditionType_t : __int32
{
  INTERACTIONCONDITION_NONE = 0x0,
  INTERACTIONCONDITION_JOB = 0x1,
  INTERACTIONCONDITION_ITEM = 0x2,
  INTERACTIONCONDITION_GAMESTATEINT = 0x3,
  INTERACTIONCONDITION_FORCEFALSE = 0x4,
  INTERACTIONCONDITION_FORCETRUE = 0x5,
};

// IDA Local Type ordinal 1317; PDB kind: enum.
enum aiPlayerInteraction_t::interactionTestJobStatus_t : __int32
{
  INTERACTIONTEST_JOBSTATUS_ACCEPTED = 0x0,
  INTERACTIONTEST_JOBSTATUS_READYTOTURNIN = 0x1,
  INTERACTIONTEST_JOBSTATUS_COMPLETED = 0x2,
};

// IDA Local Type ordinal 2251; PDB kind: enum.
enum playerInteractionState_t : __int32
{
  PISTATE_INACTIVE = 0x0,
  PISTATE_APPROACH_PLAYED = 0x1,
  PISTATE_JOB_SETUP_PLAYED = 0x2,
  PISTATE_JOB_END_PLAYED = 0x3,
  PISTATE_JOB_IN_PROGRESS = 0x4,
};

// IDA Local Type ordinal 14442; PDB kind: class.
class idAIPlayerInteractionMemory : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14443.
  virtual idTypeInfo *GetType();
  virtual ~idAIPlayerInteractionMemory();

  idStr declName;
  idList<bool,5> approachPlayedList;
  idList<bool,5> jobOfferPlayedList;
};

// IDA Local Type ordinal 16613; PDB kind: class.
class aiPlayerInteraction_t::interactionJobVO_t
{
public:
  const idDeclVoiceOver *jobOfferVO;
  const idDeclVoiceOver *jobEndVO;
  const idDeclVoiceOver *jobByeVO;
  const idDeclVoiceOver *jobInProgressVO;
  const idDeclVoiceOver *jobCompleteVO;
  const idDeclVoiceOver *jobFailVO;
};

// IDA Local Type ordinal 16614; PDB kind: class.
class aiPlayerInteraction_t::interactionTestCondition_t
{
public:
  aiPlayerInteraction_t::interactionTestConditionType_t condition;
  idDeclJobRef jobDecl;
  aiPlayerInteraction_t::interactionTestJobStatus_t jobStatus;
  const idDeclInventory *inventoryDecl;
  const idDeclGameStateInt *gameStateIntDecl;
  int count;
};

// IDA Local Type ordinal 16618; PDB kind: class.
class aiPlayerInteraction_t::oneOffClothesData_t
{
public:
  const idDeclPlayerArmor *clothing;
  const idDeclVoiceOver *responseVO;
};

// IDA Local Type ordinal 16620; PDB kind: class.
class aiPlayerInteraction_t::oneOffClothesInteraction_t
{
public:
  idList<aiPlayerInteraction_t::oneOffClothesData_t,5> clothingData;
  const idDeclJob *jobToSetReady;
};

// IDA Local Type ordinal 16621; PDB kind: class.
class aiPlayerInteraction_t
{
public:
  idStr interactName;
  int interactIndex;
  bool activateWhenVisible;
  float interactionFoV;
  bool allowBodyRotation;
  bool allowAutoFocus;
  bool waitTillInteractIdle;
  bool allowHeadTracking;
  bool forceDoNotStopOnPlayerDepature;
  bool countPlayerControlledAsDeparture;
  const idDeclVoiceOver *approachVO;
  const idDeclVoiceOver *secondaryApproachVO;
  bool lowerWorldSoundVolumeForApproachVO;
  idStr idleAnim;
  const idDeclVoiceOver *messageVO;
  bool messageExpiresInteraction;
  idStr messageTriggerEnt;
  bool messageTriggerPostMessage;
  const idDeclGameStateInt *interactionGameStateIntDecl;
  const idDeclVoiceOver *finishedVO;
  const idDeclVoiceOver *abortedVO;
  idStr actionNodeGroupName;
  posture_t posture;
  sitState_t sitState;
  standState_t standState;
  const idDeclJob *interactionJob;
  aiPlayerInteraction_t::interactionJobVO_t interactionJobVO;
  idList<aiPlayerInteraction_t::interactionTestCondition_t,5> isAvailableCondition;
  idList<aiPlayerInteraction_t::interactionTestCondition_t,5> hasExpiredCondition;
  bool expiredOnAny;
  idList<aiPlayerInteraction_t::interactionTestCondition_t,5> canBeClosedCondition;
  bool forceNoMerchant;
  aiPlayerInteraction_t::oneOffClothesInteraction_t oneOffClothesInteraction;
};

// IDA Local Type ordinal 16625; PDB kind: struct.
struct demoAIPlayerInteractionPair_t
{
  gameDemoType_t demoType;
  const idDeclAIPlayerInteraction *playerInteraction;
};

// IDA Local Type ordinal 17049; PDB kind: class.
class idAction_WaitForPlayerInteraction : public idAIAction
{
public:
  // Recovered virtual interface; IDA vtable ordinal 33823.
  virtual idTypeInfo *GetType();
  virtual ~idAction_WaitForPlayerInteraction();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void Save(const idFiniteStateMachine *, idFile_String *, const char *);
  virtual void InternalInitState(const idFiniteStateMachine *);
  virtual bool InternalCanUse(idFiniteStateMachine *, const int);
  virtual void InternalEnterState(idFiniteStateMachine *, const int);
  virtual void InternalExitState(idFiniteStateMachine *, const int);
  virtual void InternalWork(idFiniteStateMachine *, const int);
  virtual void InternalReenterState(idFiniteStateMachine *, const int, const int);
  virtual bool InternalIsStateWaiting(idFiniteStateMachine *, const int);
  virtual void InternalGetDebugString(idStr *);
  virtual bool AIState_CanUse(idAI2 *, idAIFSM *, const int);
  virtual void AIState_EnterState(idAI2 *, idAIFSM *, const int);
  virtual void AIState_ExitState(idAI2 *, idAIFSM *, const int);
  virtual void AIState_Work(idAI2 *, idAIFSM *, const int);
  virtual void AIState_ReenterState(idAI2 *, idAIFSM *, const int, const int);
  virtual bool AIState_IsWaiting(idAI2 *, idAIFSM *, const int);
  virtual const idEventDef *GetActionEventDef();
  virtual int GetActionFlags();
  virtual void AIAction_EnterState(idAI2 *, idAIFSM *, const int);
  virtual void AIAction_ExitState(idAI2 *, idAIFSM *, const int);
  virtual void AIAction_Work(idAI2 *, idAIFSM *, const int);
  virtual void AIAction_ReenterState(idAI2 *, idAIFSM *, const int);
  virtual bool AIAction_IsWaiting(idAI2 *, idAIFSM *, const int);

  float maxDist;
};

// IDA Local Type ordinal 17078; PDB kind: class.
class __unaligned __declspec(align(4)) idAction_ForcePlayerInteraction : public idAIAction
{
public:
  // Recovered virtual interface; IDA vtable ordinal 33754.
  virtual idTypeInfo *GetType();
  virtual ~idAction_ForcePlayerInteraction();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void Save(const idFiniteStateMachine *, idFile_String *, const char *);
  virtual void InternalInitState(const idFiniteStateMachine *);
  virtual bool InternalCanUse(idFiniteStateMachine *, const int);
  virtual void InternalEnterState(idFiniteStateMachine *, const int);
  virtual void InternalExitState(idFiniteStateMachine *, const int);
  virtual void InternalWork(idFiniteStateMachine *, const int);
  virtual void InternalReenterState(idFiniteStateMachine *, const int, const int);
  virtual bool InternalIsStateWaiting(idFiniteStateMachine *, const int);
  virtual void InternalGetDebugString(idStr *);
  virtual bool AIState_CanUse(idAI2 *, idAIFSM *, const int);
  virtual void AIState_EnterState(idAI2 *, idAIFSM *, const int);
  virtual void AIState_ExitState(idAI2 *, idAIFSM *, const int);
  virtual void AIState_Work(idAI2 *, idAIFSM *, const int);
  virtual void AIState_ReenterState(idAI2 *, idAIFSM *, const int, const int);
  virtual bool AIState_IsWaiting(idAI2 *, idAIFSM *, const int);
  virtual const idEventDef *GetActionEventDef();
  virtual int GetActionFlags();
  virtual void AIAction_EnterState(idAI2 *, idAIFSM *, const int);
  virtual void AIAction_ExitState(idAI2 *, idAIFSM *, const int);
  virtual void AIAction_Work(idAI2 *, idAIFSM *, const int);
  virtual void AIAction_ReenterState(idAI2 *, idAIFSM *, const int);
  virtual bool AIAction_IsWaiting(idAI2 *, idAIFSM *, const int);

};

// IDA Local Type ordinal 17234; PDB kind: class.
class idAIPlayerInteraction : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17235.
  virtual idTypeInfo *GetType();
  virtual ~idAIPlayerInteraction();

  const idDeclAIPlayerInteraction *decl;
  const idAnimatedEntity *owner;
};

// IDA Local Type ordinal 19557; PDB kind: class.
class idProp_PlayerInteraction : public idProp_Usable
{
public:
  // Recovered virtual interface; IDA vtable ordinal 19558.
  virtual idTypeInfo *GetType();
  virtual ~idProp_PlayerInteraction();
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
  virtual void GetUseLocation(const idActor *, idVec3 *);
  virtual usableState_t GetOnlineUsableState();

  idAnimator_Channel channelAnimator;
  int nextIdleTime;
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> idleAnimAlias;
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> useOnAnimAlias;
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> useOffAnimAlias;
  idEntityPtr<idVolume> useVolume;
  bool shouldLockCamera;
  idVec3 playerPos;
  idVec3 playerLookAtPos;
  idDeclInventory *itemToPickUp;
};
