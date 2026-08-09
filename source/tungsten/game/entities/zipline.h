#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\zipline.h
// Recovered logical types: 13
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1617; PDB kind: enum.
enum idProp_Zipline::ziplineState_t : __int32
{
  ZIPLINE_START_ATTACH = 0x0,
  ZIPLINE_ANIMATE_TO_ATTACH = 0x1,
  ZIPLINE_READY = 0x2,
  ZIPLINE_MOVE_DOWN = 0x3,
  ZIPLINE_WAIT_FOR_UP = 0x4,
  ZIPLINE_MOVE_UP = 0x5,
};

// IDA Local Type ordinal 1618; PDB kind: enum.
enum idProp_Zipline::ziplineSpeedState_t : __int32
{
  ZIPLINE_STARTED = 0x0,
  ZIPLINE_ACCEL = 0x1,
  ZIPLINE_CONSTANT_VEL = 0x2,
  ZIPLINE_DECEL = 0x3,
  ZIPLINE_STOPPED = 0x4,
};

// IDA Local Type ordinal 1619; PDB kind: enum.
enum idProp_Zipline::ziplinePhysicsState_t : __int32
{
  ZIPLINE_PHYSICS_ACCEL = 0x0,
  ZIPLINE_PHYSICS_DECEL = 0x1,
  ZIPLINE_PHYSICS_DONE = 0x2,
};

// IDA Local Type ordinal 18795; PDB kind: class.
class idProp_Zipline::idProp_ZiplinePathParams
{
public:
  idEntityPtr<idMover> startMover;
  idEntityPtr<idMover> endMover;
  const idDeclEntityDef *endpointMoverDecl;
  const idDeclEntityDef *splinePathDef;
  idSplinePath *implicitTravelPath;
  idSplinePath *implicitReversePath;
  idSplinePath *implicitSlackPath;
  idEntityPtr<idSplinePath> travelPath;
  idEntityPtr<idSplinePath> reversePath;
  idEntityPtr<idSplinePath> slackPath;
  float travelSag;
  float reverseSag;
  float slackSag;
  const idMaterial *cableMaterial;
  float splineLerpingPower;
  float diameter;
  int cableDivisions;
  int unitsPerSplinePoints;
  float tautFraction;
  float startDist;
  float endDist;
};

// IDA Local Type ordinal 18796; PDB kind: class.
class idProp_Zipline::idProp_ZiplineOscillationParams
{
public:
  float fwdMagMin;
  float fwdMagMax;
  float fwdMag;
  float fwdFreqMin;
  float fwdFreqMax;
  float fwdFreq;
  float rtMagMin;
  float rtMagMax;
  float rtMag;
  float rtFreqMin;
  float rtFreqMax;
  float rtFreq;
  float upMagMin;
  float upMagMax;
  float upMag;
  float upFreqMin;
  float upFreqMax;
  float upFreq;
};

// IDA Local Type ordinal 18797; PDB kind: class.
class idProp_Zipline::idProp_ZiplineSoundParams
{
public:
  const idSoundShader *sndStart;
  const idSoundShader *sndAccel;
  float sndAccelMinVolume;
  float sndAccelMinVolumeSpeed;
  float sndAccelMaxVolume;
  float sndAccelMaxVolumeSpeed;
  float sndAccelMinPitch;
  float sndAccelMinPitchSpeed;
  float sndAccelMaxPitch;
  float sndAccelMaxPitchSpeed;
  const idSoundShader *sndMoveUp;
  const idSoundShader *sndMoveDown;
  float sndMoveMinVolume;
  float sndMoveMinVolumeSpeed;
  float sndMoveMaxVolume;
  float sndMoveMaxVolumeSpeed;
  const idSoundShader *sndWind;
  const idDeclTable *sndWindVolumeTable;
  const idDeclTable *sndWindPitchTable;
  const idSoundShader *sndDecel;
  const idSoundShader *sndStop;
  const idSoundShader *sndAttach;
  const idSoundShader *sndDetach;
};

// IDA Local Type ordinal 18798; PDB kind: class.
class idProp_Zipline::idProp_ZiplineFXParams
{
public:
  float fxSpeedSlow;
  float fxSpeedMed;
  float fxSpeedFast;
  float fxSpeedLudicrous;
  int currentSpeedFX;
};

// IDA Local Type ordinal 18799; PDB kind: class.
class __declspec(align(4)) idProp_Zipline::idProp_ZiplineViewParams
{
public:
  bool applyCameraShakeFx;
  float viewDegreesPerSecond;
  float maxSpeedForFx;
  idAngles maxCameraShakeAngle;
  float maxFov;
  float maxPitch;
  float maxYaw;
  int returnToCenterTime;
  float fxPower;
  bool hideHandleWithPlayer;
};

// IDA Local Type ordinal 18800; PDB kind: class.
class idProp_Zipline::idProp_ZiplineTimings
{
public:
  int downMoveTime;
  int upMoveTime;
  int waitTime;
  int dropOffTime;
  int attachAnimationTime;
  int accelTime;
  int decelTime;
};

// IDA Local Type ordinal 18801; PDB kind: class.
class idProp_Zipline::idProp_ZiplinePhysicsParams
{
public:
  bool usePhysicsDescent;
  float gravity;
  float acceleration;
  int accelerationTime;
  float maxSpeed;
  float brakingDecel;
  float friction;
  float curSpeed;
  float curDist;
  idVec3 curVel;
  int accelerationTimeRemaining;
  idProp_Zipline::ziplinePhysicsState_t state;
};

// IDA Local Type ordinal 18802; PDB kind: class.
class idZiplinePoint
{
public:
  idVec3 point;
  idVec3 slackDelta;
};

// IDA Local Type ordinal 18804; PDB kind: class.
class idZipline
{
public:
  idList<idZiplinePoint,5> points;
  float totalLength;
};

// IDA Local Type ordinal 18810; PDB kind: class.
class idProp_Zipline : public idProp_Usable
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18811.
  virtual idTypeInfo *GetType();
  virtual ~idProp_Zipline();
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

  idProp_Zipline::idProp_ZiplinePathParams ziplinePathParams;
  idProp_Zipline::idProp_ZiplineOscillationParams ziplineOscillationParams;
  idProp_Zipline::idProp_ZiplineSoundParams ziplineSounds;
  idProp_Zipline::idProp_ZiplineFXParams ziplineFXParams;
  idProp_Zipline::idProp_ZiplineViewParams ziplineViewParams;
  idProp_Zipline::idProp_ZiplineTimings ziplineTimings;
  idProp_Zipline::idProp_ZiplinePhysicsParams ziplinePhysicsParams;
  idEntityPtr<idEntity> ownerEntity;
  idProp_Zipline::ziplineState_t state;
  idProp_Zipline::ziplineState_t nextState;
  idProp_Zipline::ziplineSpeedState_t speedState;
  idProp_Zipline::ziplineSpeedState_t speedNextState;
  int speedStateDuration;
  int speedStateTimeLeft;
  int soundFlags;
  int currentMoveTime;
  int startTime;
  int attachStartTime;
  int waitingStartTime;
  int dropOffStartTime;
  int animationDoneTime;
  bool manualUpdate;
  int useBufferTime;
  idVec3 attachOrigin;
  idIndex<short,enum invalidJointIndex_t> eyeJoint;
  float swayMult;
  idAngles anglesOffset;
  idVec3 initialPlayerPos;
  idQuat initialPlayerRot;
  idVec3 destPlayerPos;
  idQuat destPlayerRot;
  idVec3 prevPlayerPos;
  idVec3 prevHandlePos;
  idAngles prevViewAngles;
  idZipline ziplines[2];
  int currentZipline;
  idCurve_Spline<idVec3> *currentDrawnSpline;
  float currentDrawnSplineLength;
  idSpring<idVec1> slackSpring;
  idRenderModelZipline *cableModel;
};
