#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\mover.h
// Recovered logical types: 22
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1397; PDB kind: enum.
enum idNpMover::moverOrientMode_t : __int32
{
  Orient_InDirection = 0x0,
  Orient_ToPoint = 0x1,
  Orient_InTravelDirection = 0x2,
  Orient_StrictlyInTravelDirection = 0x3,
};

// IDA Local Type ordinal 1398; PDB kind: enum.
enum idNpMover::moveInDirFlags_t : __int32
{
  MoveInDir_StopWhenBlocked = 0x1,
  MoveInDir_PushableByConstraintSolver = 0x2,
};

// IDA Local Type ordinal 1859; PDB kind: enum.
enum moverDir_t : __int32
{
  DIR_UP = 0xFFFFFFFF,
  DIR_DOWN = 0xFFFFFFFE,
  DIR_BACK = 0xFFFFFFFA,
  DIR_REL_UP = 0xFFFFFFF9,
  DIR_REL_DOWN = 0xFFFFFFF8,
  DIR_REL_LEFT = 0xFFFFFFF7,
  DIR_REL_RIGHT = 0xFFFFFFF6,
  DIR_REL_FORWARD = 0xFFFFFFF5,
  DIR_REL_BACK = 0xFFFFFFF4,
};

// IDA Local Type ordinal 1861; PDB kind: enum.
typedef idMoverMM::moveStage_t idMover::moveStage_t;

// IDA Local Type ordinal 1862; PDB kind: enum.
typedef idMoverMM::moverCommand_t idMover::moverCommand_t;

// IDA Local Type ordinal 1868; PDB kind: enum.
enum idMoverMM::moveStage_t : __int32
{
  ACCELERATION_STAGE = 0x0,
  LINEAR_STAGE = 0x1,
  DECELERATION_STAGE = 0x2,
  FINISHED_STAGE = 0x3,
};

// IDA Local Type ordinal 1869; PDB kind: enum.
enum idMoverMM::moverCommand_t : __int32
{
  MOVER_NONE = 0x0,
  MOVER_ROTATING = 0x1,
  MOVER_MOVING = 0x2,
  MOVER_SPLINE = 0x3,
};

// IDA Local Type ordinal 18232; PDB kind: struct.
struct __declspec(align(2)) idNpMover::idGotoParms
{
  idVec3 goalPos;
  float stopDistAllowed;
  float stopDistDesired;
  idVec3 orientAtGoalDir;
  bool orientAtGoalEnabled;
  bool stopAtGoal;
  bool pushThroughCrowd;
};

// IDA Local Type ordinal 18233; PDB kind: class.
class idNpMover
{
public:
  idNpMoverImpl *impl;
};

// IDA Local Type ordinal 18234; PDB kind: struct.
struct idNpMover::idFollowParms
{
  int formation;
  float followDistance;
  float arcSpread;
};

// IDA Local Type ordinal 18236; PDB kind: struct.
struct __declspec(align(4)) idNpMover::idProbeResults
{
  idVec3 endPos;
  float distTotal;
  float distFraction;
  float distTravelled;
  idNpAreaHandle endArea;
  int collisionEdge;
  bool collided;
};

// IDA Local Type ordinal 18239; PDB kind: struct.
struct idNpMover::idProbeInput
{
  navLayer_t layer;
  navObstacleFlags_t obstacleMask;
  navCustomFlags_t surfacesUsable;
  int debugDrawTime;
};

// IDA Local Type ordinal 18240; PDB kind: struct.
struct __declspec(align(4)) idNpMover::idLinkUseParms
{
  navLinkFlags_t linkFlags;
  idEntityPtr<idEntity> linkEntityStart;
  idEntityPtr<idEntity> linkEntityEnd;
  idVec3 startPos;
  idVec3 startNormal;
  idVec3 endPos;
  idVec3 endNormal;
  float mustUseDist;
  float mayUseDist;
  float jumpTimeRemaining;
  unsigned __int8 : 6;
  __int8 customLinkMode : 1;
  __int8 isJumpLink : 1;
};

// IDA Local Type ordinal 18241; PDB kind: struct.
struct idNpMover::idTurnInPlaceInfo
{
  idVec3 finalDirection;
  float degreesToTarget;
  float turnTimeLeft;
};

// IDA Local Type ordinal 18812; PDB kind: class.
class idMover : public idEntity
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18816.
  virtual idTypeInfo *GetType();
  virtual ~idMover();
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
  virtual usableState_t GetOnlineUsableState();
  virtual void DoneMoving();
  virtual void DoneRotating();
  virtual void BeginMove(idThread *);
  virtual void BeginRotation(idThread *, bool);

  idPhysics_Parametric physicsObj;
  idMover::moveState_t move;
  int soundFlags;
  idMover::rotationState_t rot;
  idHandle<int,enum invalidThreadHandle_t,0> move_thread;
  idHandle<int,enum invalidThreadHandle_t,0> rotate_thread;
  idAngles dest_angles;
  idAngles angle_delta;
  idVec3 dest_position;
  idVec3 move_delta;
  float move_speed;
  int move_time;
  int deceltime;
  int acceltime;
  bool resetPathOnCompletion;
  bool stopRotation;
  bool useSplineAngles;
  idMover::moverCommand_t lastCommand;
  int crunchSoundTime;
  const idDeclDamage *crushDamage;
  const idSoundShader *sndCrush;
  float health;
  bool solid;
  bool noPush;
  const idSoundShader *sndAccel;
  const idSoundShader *sndDecel;
  const idSoundShader *sndMove;
  const idSoundShader *sndFoliage;
  idEntityInfluenceTrail influence;
  bool impaleEntity;
  float impaleDepth;
  idStr constraintName;
  idEntityPtr<idEntity> impaledEntity;
  bool needsReset;
  int savedAFContents;
  idVec3 lastOrigin;
  float smoothMovement;
  idVec3 averageModelOrigin;
  idMat3 averageModelAxis;
  highlightColor_t highlightColor;
  idList<idEntityPtr<idEntity>,5> guiTargets;
  idMover::navSpace_t navigationSpace;
};

// IDA Local Type ordinal 18813; PDB kind: struct.
struct idMover::moveState_t
{
  idMover::moveStage_t stage;
  idMover::moveStage_t currentStage;
  int acceleration;
  int movetime;
  int deceleration;
  idVec3 dir;
};

// IDA Local Type ordinal 18814; PDB kind: struct.
struct idMover::rotationState_t
{
  idMover::moveStage_t stage;
  idMover::moveStage_t currentStage;
  int acceleration;
  int movetime;
  int deceleration;
  idAngles rot;
};

// IDA Local Type ordinal 18815; PDB kind: struct.
struct idMover::navSpace_t
{
  navLayerMask_t navSpaceLayers;
  idNavigationSpace navSpace;
};

// IDA Local Type ordinal 19684; PDB kind: class.
class __declspec(align(8)) idMoverMM : public idAnimatedEntity
{
public:
  // Recovered virtual interface; IDA vtable ordinal 19705.
  virtual idTypeInfo *GetType();
  virtual ~idMoverMM();
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
  virtual float Damage_2(idEntity *, idEntity *, const idDeclDamage *, const float, const idVec3 *, const trace_t *);
  virtual bool IsUsable(const idEntity *);
  virtual void SpawnModifierEntity(const splineMoverModifier_t *, idPhysics_ParametricMM *);
  virtual void DoneMoving();
  virtual void DoneRotating();
  virtual void BeginMove();
  virtual void BeginRotation(bool);
  virtual bool TravelSpline(idEntity *, float, bool, bool);
  virtual void ReverseDirection();
  virtual void SetSplineOffset(idVec3, float);
  virtual void SetSplineOffsetScale(idVec3, float);
  virtual bool StartSpline(idEntity *, bool, float);
  virtual bool StartSplineExplicit(idCurve_Spline<idVec3> *, bool, float);
  virtual bool HandleInitialModifiers(const idList<splineMoverModifier_t,5> *);
  virtual void UpdateMoverModifier(idPhysics_ParametricMM *, int *, moverModifierFunction_t, float, bool);
  virtual void HandleMoverModifier(const splineMoverModifier_t *, idPhysics_ParametricMM *, moverModifierFunction_t, float, float, float, bool);
  virtual void HandleNextMoverModifier_Speed(idPhysics_ParametricMM *, float, float);
  virtual void HandleNextMoverModifier_Orientation(idPhysics_ParametricMM *, float, float);
  virtual void HandleNextMoverModifier_Offset(idPhysics_ParametricMM *, float, float);
  virtual void HandleNextMoverModifier_BlendToAnimSpeed(idPhysics_ParametricMM *, float, float);
  virtual void HandleMoverModifier_Sound(const splineMoverModifier_t *, idPhysics_ParametricMM *, float, float);
  virtual void HandleMoverModifier_Script(const splineMoverModifier_t *, idPhysics_ParametricMM *, float, float);
  virtual void HandleMoverModifier_Pause(const splineMoverModifier_t *, idPhysics_ParametricMM *, float, float);
  virtual void HandleMoverModifier_Spline(const splineMoverModifier_t *, idPhysics_ParametricMM *, float, float);
  virtual void HandleMoverModifier_Target(const splineMoverModifier_t *, idPhysics_ParametricMM *, float, float);
  virtual void HandleMoverModifier_Reverse(const splineMoverModifier_t *, idPhysics_ParametricMM *, float, float);
  virtual void HandleMoverModifier_Oscillation(const splineMoverModifier_t *, idPhysics_ParametricMM *, float, float);
  virtual void HandleMoverModifier_SpawnEntity(const splineMoverModifier_t *, idPhysics_ParametricMM *, float, float);
  virtual void HandleMoverModifier_Anim(const splineMoverModifier_t *, idPhysics_ParametricMM *, float, float);
  virtual void HandleMoverModifier_Vehicle(const splineMoverModifier_t *, idPhysics_ParametricMM *, float, float);
  virtual void HandleMoverModifier_Ai(const splineMoverModifier_t *, idPhysics_ParametricMM *, float, float);
  virtual void HandleMoverModifier_RailEvent(const splineMoverModifier_t *, idPhysics_ParametricMM *, float, float);
  virtual void HandleMoverModifier_MeleeEvent(const splineMoverModifier_t *, idPhysics_ParametricMM *, float, float);
  virtual void HandleMoverModifier_SwarmEvent(const splineMoverModifier_t *, idPhysics_ParametricMM *, float, float);

  idPhysics_ParametricMM physicsObj;
  idMoverMM::moveState_t move;
  moverModifierFunction_t modifierIgnoreFlags;
  int soundFlags;
  contentsFlags_t contentsFlags;
  bool forwardSpline;
  float move_speed;
  int move_time;
  int deceltime;
  int acceltime;
  float initialSpeed;
  idAngles dest_angles;
  idQuat dest_quat;
  idVec3 dest_position;
  idCurve_Spline<idVec3> *spline;
  idSplinePathMM *splinePath;
  const idList<splineMoverModifier_t,5> *splineMoverModifiers;
  int splineModifierIndex;
  float splineModifierLengthOffset;
  float splineTotalLength;
  bool useSplineAngles;
  bool ignoreSplinePitch;
  idVec3 move_delta;
  bool stopRotation;
  idMoverMM::moverCommand_t lastCommand;
  bool skipInitialForcedModifiers;
  bool applyAnimationOffsetOnNextFrame;
  idMat3 animationOffsetAxis;
  idVec3 animationOffsetTranslation;
  float health;
  idMoverMM::rotationState_t rot;
  int crunchSoundTime;
  const idDeclDamage *crushDamage;
  const idSoundShader *sndCrush;
  bool noPush;
  const idSoundShader *sndAccel;
  const idSoundShader *sndDecel;
  const idSoundShader *sndMove;
  idList<idMoverMM::moverSoundInterpolater_t,5> sndVolumeInterpolaters;
  idList<idMoverMM::moverSoundInterpolater_t,5> sndPitchInterpolaters;
  idList<idEntityPtr<idEntity>,5> guiTargets;
};

// IDA Local Type ordinal 19695; PDB kind: struct.
struct idMoverMM::moveState_t
{
  idMoverMM::moveStage_t stage;
  int acceleration;
  int movetime;
  int deceleration;
  idVec3 dir;
  idVec3 endPos;
  idAngles endAngles;
};

// IDA Local Type ordinal 19702; PDB kind: struct.
struct idMoverMM::rotationState_t
{
  idMoverMM::moveStage_t stage;
  int acceleration;
  int movetime;
  int deceleration;
  idVec3 vec;
  float speed;
};

// IDA Local Type ordinal 19703; PDB kind: struct.
struct idMoverMM::moverSoundInterpolater_t
{
  idEntityPtr<idEntity> targetEmitter;
  soundChannel_t channel;
  idInterpolate<float> interpolater;
};
