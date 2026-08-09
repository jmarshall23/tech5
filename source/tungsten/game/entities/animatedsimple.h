#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\animatedsimple.h
// Recovered logical types: 7
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1800; PDB kind: enum.
enum idAnimatedSimple::stateMarker_t : __int32
{
  STATE_RANDOM = 0xFFFFFFFE,
  STATE_NONE = 0xFFFFFFFF,
};

// IDA Local Type ordinal 2003; PDB kind: enum.
typedef idAIScriptedAnimWeb::loopTriggerType_t idAnimatedSimple::loopTriggerType_t;

// IDA Local Type ordinal 19585; PDB kind: struct.
struct __declspec(align(4)) idAnimatedSimple::idHitDetection_t
{
  idEntityPtr<idEntity> callTargetWhenDead;
  idEntityPtr<idEntity> onIgnoredDamageTrigger;
  idStr callWhenDead;
  int health;
  idDeclDamage::damageType_t ignoreDamageTypes;
  bool shouldGetHit;
  bool hasBeenKilled;
};

// IDA Local Type ordinal 19586; PDB kind: struct.
struct __declspec(align(4)) idAnimatedSimple::animEntry_t
{
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> animationHandle;
  idAnimAliasRef animation;
  idEntityPtr<idEntity> perfectOriginRef;
  idList<idEntityPtr<idEntity>,5> triggerEnter;
  idList<idEntityPtr<idEntity>,5> triggerLeave;
  idList<idEntityPtr<idEntity>,5> triggerLoopCount;
  idList<idEntityPtr<idEntity>,5> triggerAnimDone;
  float timeScale;
  int jumpToState;
  int blendTime;
  int loopCountToTrigger;
  idAnimatedSimple::loopTriggerType_t loopTriggerType;
  unsigned __int8 : 1;
  __int8 useTimeControl : 1;
  __int8 useAnimationScale : 1;
  __int8 hideWhenDone : 1;
  __int8 useDeltaMovement : 1;
  __int8 loop : 1;
  __int8 useAnimationOrigin : 1;
  __int8 playDefault : 1;
};

// IDA Local Type ordinal 19588; PDB kind: struct.
struct idAnimatedSimple::attachment_t
{
  idStr tag;
  const idDeclEntityDef *entityDef;
  idStr entityName;
  const idDeclMD6 *md6;
  idStr lwoName;
  idDeclInventory *itemDef;
  idHandle<int,enum invalidAttachment_t,-1> attachHandle;
  equipSlot_t equipSlot;
};

// IDA Local Type ordinal 19590; PDB kind: struct.
struct idAnimatedSimple::idFacialOptions_t
{
  unsigned __int8 : 1;
  __int8 useFacialAnims : 1;
  __int8 useFaceManager : 1;
  __int8 useLidDeformation : 1;
  __int8 useBlinking : 1;
  __int8 useFaceSetupEyeTracking : 1;
  __int8 useEyeTracking : 1;
  __int8 useLipsync : 1;
};

// IDA Local Type ordinal 19591; PDB kind: class.
class __declspec(align(8)) idAnimatedSimple : public idAnimatedEntity
{
public:
  // Recovered virtual interface; IDA vtable ordinal 19592.
  virtual idTypeInfo *GetType();
  virtual ~idAnimatedSimple();
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

  idAnimatedSimple::idHitDetection_t hitDetectionOptions;
  idList<idAnimatedSimple::animEntry_t,5> animList;
  idList<idAnimatedSimple::attachment_t,5> startingAttachments;
  idAnimatedSimple::idFacialOptions_t facialOptions;
  idStrId displayName;
  unsigned __int8 : 1;
  __int8 noDeferredPositon : 1;
  __int8 sceneModel : 1;
  __int8 isOkWithoutModel : 1;
  __int8 ignoreMovement : 1;
  __int8 playerShouldLowerWeapon : 1;
  __int8 applyAnimTransformLocal : 1;
  __int8 applyAnimTransform : 1;
  __declspec(align(4)) idAnimator_Channel channelAnimator;
  idAnimator_Paused pausedAnimator;
  idAnimator_FaceTracks faceAnimator;
  idAttachmentCollection attachments;
  idFaceMgr faceMgr;
  idQuat orgRotation;
  idVec3 orgOrigin;
  idQuat nextRotation;
  idVec3 nextOrigin;
  idVec3 prevTrans;
  float externalTime;
  int animStartFrame;
  int animUpdatedFrame;
  int physicsContent;
  int currentState;
  int queuedAnimState;
  int queuedBlendTime;
  int currentLoopCount;
  int queuePauseFrame;
  bool queuePause;
  bool wasLooping;
  bool isPaused;
  bool hasCheckedDefault;
};
