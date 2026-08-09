#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\springcamera.h
// Recovered logical types: 6
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1244; PDB kind: enum.
enum idSpringCamera::duration_t : __int32
{
  DURATION_NEVER = 0x0,
  DURATION_ALWAYS = 0x1,
  DURATION_ANIM = 0x2,
  DURATION_MAX = 0x3,
};

// IDA Local Type ordinal 1245; PDB kind: enum.
enum idSpringCamera::lookMode_t : __int32
{
  LOOK_NONE = 0x0,
  LOOK_HEADING = 0x1,
  LOOK_POSITION = 0x2,
  LOOK_ADD_HEADING = 0x3,
  LOOK_ADD_HEADING_AUTOCENTER = 0x4,
  LOOK_ADD_DELTAANGLES = 0x5,
};

// IDA Local Type ordinal 1246; PDB kind: enum.
enum idSpringCamera::blendMode_t : __int32
{
  BLEND_SMOOTH = 0x0,
  BLEND_SMOOTH_SNAP_SMOOTH = 0x1,
  BLEND_SNAP_SNAP_SMOOTH = 0x2,
  BLEND_SNAP = 0x3,
  BLEND_FOLLOW_SNAP_LOOK_SMOOTH_SNAP_SMOOTH = 0x4,
  BLEND_MAX = 0x5,
};

// IDA Local Type ordinal 1250; PDB kind: enum.
enum idSpringCamera::state_t : __int32
{
  STATE_INACTIVE = 0x0,
  STATE_BLEND_IN = 0x1,
  STATE_REACTIVATE = 0x2,
  STATE_ACTIVE = 0x3,
  STATE_ACTIVE_READY_TO_BLEND_OUT = 0x4,
  STATE_BLEND_OUT = 0x5,
  STATE_MAX = 0x7,
};

// IDA Local Type ordinal 1251; PDB kind: enum.
enum idSpringCamera::calculateViewStage_t : __int32
{
  STAGE_DEFAULT = 0x0,
  STAGE_UPDATE = 0x1,
  STAGE_DRAW = 0x2,
};

// IDA Local Type ordinal 14989; PDB kind: class.
class __declspec(align(8)) idSpringCamera : public idCamera
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34055.
  virtual idTypeInfo *GetType();
  virtual ~idSpringCamera();
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
  virtual void HandleUserCmds(const usercmd_t *, const usercmd_t *);
  virtual int InhibitFlags();
  virtual int InhibitButtons();
  virtual bool CanShowCrosshair();
  virtual bool InternalActivate(idEntity *);
  virtual bool InternalDeactivate();

  idSpring<idVec1> followBlendSpring;
  idSpring<idVec1> lookBlendSpring;
  idSpring<idVec3> springFollowPos;
  idSpring<idVec3> springLookFwdDir;
  idSpring<idVec3> springLookUpDir;
  idSpring<idVec1> springFOV;
  idSpring<idVec3> springAutoCenter;
  idEntityPtr<idEntity> followEntity;
  idTreeAnimator *followAnimator;
  idIndex<short,enum invalidJointIndex_t> followJointIndex;
  idEntityPtr<idEntity> lookEntity;
  idTreeAnimator *lookAnimator;
  idIndex<short,enum invalidJointIndex_t> lookJointIndex;
  const idMD6Skel *lookSkeleton;
  idSpringCamera::duration_t followDuration;
  idSpringCamera::duration_t lookDuration;
  idSpringCamera::lookMode_t lookMode;
  idSpringCamera::blendMode_t lookBlendMode;
  idSpringCamera::blendMode_t followBlendMode;
  idIndex<short,enum invalidUserChannelIndex_t> fovUserChannel;
  idSpringCamera::state_t followState;
  idSpringCamera::state_t lookState;
  idSpringCamera::state_t state;
  int lastUpdateFrame;
  idVec3 viewOrigin;
  idMat3 viewAxis;
  float viewFov;
  idVec3 viewVelocity;
  int viewTimestamp;
  idVec3 fromViewOrigin;
  idMat3 fromViewAxis;
  idEntityPtr<idEntity> activatorParent;
  idVec3 activatorParentPos;
  bool calculateViewInDraw;
  bool manualUpdate;
  bool calculatedView;
  bool calculatedViewOrigin;
  bool usesUserChannelFov;
  bool resetManualUpdate;
  bool getPlayerLookFromView;
  idSpringCamera::calculateViewStage_t forceCalculateViewStage;
  float constraintConeDegs;
  float autoCenterSpringK;
  bool clipTestMovement;
  float clipTestRadius;
  float clipTestHeight;
  idVec3 clipTestResult;
  bool inhibitControl;
};
