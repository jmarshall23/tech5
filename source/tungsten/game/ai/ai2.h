#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\ai2.h
// Recovered logical types: 36
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1288; PDB kind: enum.
enum idAI2::aiCondition_t : __int32
{
  CONDITION_NONE = 0x0,
  CONDITION_UNAVAILABLE = 0x1,
  CONDITION_PINNED = 0x2,
  CONDITION_CANT_SEE = 0x4,
  CONDITION_INJURED = 0x8,
  CONDITION_INTIMIDATED = 0x10,
  CONDITION_FIRING = 0x20,
  CONDITION_RELOADING = 0x40,
  CONDITION_MOVING = 0x80,
  CONDITION_REQUEST_HOLD_FIRE = 0x100,
  CONDITION_REQUEST_COVER_FIRE = 0x200,
  CONDITION_REQUEST_GRENADE = 0x400,
  CONDITION_FORCE_CHARGE = 0x800,
  CONDITION_MUST_SEARCH = 0x1000,
  CONDITION_GW_PERFECT_AIM = 0x2000,
  CONDITION_GW_ALL_FIRE_FROM_COVER = 0x4000,
  CONDITION_GW_MAX_HOLD_TRIGGER = 0x8000,
  CONDITION_GW_INFINITE_AMMO = 0x10000,
  CONDITION_GW_DAMAGE_SCALE = 0x20000,
};

// IDA Local Type ordinal 2253; PDB kind: enum.
enum idAI2::idVisibilityObscurity::obscurity_t : __int32
{
  OBSCURITY_UNKNOWN = 0x0,
  OBSCURITY_PATH_BLOCKED = 0x1,
  OBSCURITY_PATH_OPEN_WITH_OBSCURITY = 0x2,
  OBSCURITY_PATH_OPEN_WITH_COVER = 0x3,
  OBSCURITY_PATH_OPEN_AND_ENEMY_VISIBLE = 0x4,
  OBSCURITY_NUM = 0x5,
};

// IDA Local Type ordinal 2254; PDB kind: enum.
enum idAI2::idVisibilityObscurity::obscurityTest_t : __int32
{
  OBSCURITYTEST_MUZZLE_POS = 0x0,
  OBSCURITYTEST_HALF_HEIGHT_FAR_LEFT = 0x1,
  OBSCURITYTEST_HALF_HEIGHT_FAR_RIGHT = 0x2,
  OBSCURITYTEST_HALF_HEIGHT_NEAR_LEFT = 0x3,
  OBSCURITYTEST_HALF_HEIGHT_NEAR_RIGHT = 0x4,
  OBSCURITYTEST_FULL_HEIGHT_FORWARD = 0x5,
  OBSCURITYTEST_FULL_HEIGHT_BACK = 0x6,
  OBSCURITYTEST_NUM = 0x7,
};

// IDA Local Type ordinal 2333; PDB kind: enum.
enum idAI2::aiErrorFlags_t : __int32
{
  AIERRORFLAG_NONE = 0x0,
  AIERRORFLAG_NO_AAS = 0x1,
  AIERRORFLAG_OUT_OF_AAS = 0x2,
  AIERRORFLAG_MOVE_FAILED = 0x4,
  AIERRORFLAG_STUCK = 0x8,
  AIERRORFLAG_OBSTRUCTED = 0x10,
  AIERRORFLAG_NO_ANIMWEB_PATH = 0x20,
  AIERRORFLAG_MAX = 0x6,
};

// IDA Local Type ordinal 2386; PDB kind: enum.
enum idAI2::aiDebugLevel_t : __int32
{
  AIDEBUGLEVEL_NONE = 0x0,
  AIDEBUGLEVEL_ERROR = 0x1,
  AIDEBUGLEVEL_ACTION = 0x2,
};

// IDA Local Type ordinal 2394; PDB kind: enum.
enum idAI2::idVisibilityObscurity::obscurityQuery_t : __int32
{
  OBSCURITYQUERY_CROUCH_COVER = 0x0,
  OBSCURITYQUERY_DODGE_LEFT = 0x1,
  OBSCURITYQUERY_DIVE_LEFT = 0x2,
  OBSCURITYQUERY_DODGE_RIGHT = 0x3,
  OBSCURITYQUERY_DIVE_RIGHT = 0x4,
  OBSCURITYQUERY_DIVE_FWD = 0x5,
  OBSCURITYQUERY_DIVE_BACK = 0x6,
  OBSCURITYQUERY_MAX = 0x7,
};

// IDA Local Type ordinal 2395; PDB kind: enum.
enum idAI2::coverApproach_t : __int32
{
  COVER_APPROACH_FORWARD = 0x0,
  COVER_APPROACH_LEFT = 0x1,
  COVER_APPROACH_RIGHT = 0x2,
  COVER_APPROACH_TURN_AROUND_LEFT = 0x3,
  COVER_APPROACH_WRAP_AROUND_LEFT = 0x4,
  COVER_APPROACH_TURN_AROUND_RIGHT = 0x5,
  COVER_APPROACH_WRAP_AROUND_RIGHT = 0x6,
  COVER_APPROACH_JUMPOVER = 0x7,
  COVER_APPROACH_MAX = 0x8,
};

// IDA Local Type ordinal 16561; PDB kind: class.
class idAI2 : public idActor
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17261.
  virtual idTypeInfo *GetType();
  virtual ~idAI2();
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
  virtual void RepairShield(const float);
  virtual const idVec3 *GetEyeOffset(const idVec3 *result);
  virtual void GetViewTransform(idVec3 *, idMat3 *);
  virtual void GetLastEyePos(idVec3 *);
  virtual void GetEyeAxis(idMat3 *);
  virtual void SetEyeAxis(const idMat3 *);
  virtual idAnimator_AF::testSolidResult_t StartRagdoll(const idRagdollInfo *);
  virtual void StopRagdoll();
  virtual equipSlot_t GetWeaponSlot();
  virtual idWeapon *GetEquippedWeapon();
  virtual bool EquipItem(idInventoryItem *, equipSlot_t);
  virtual bool UnequipItem(idInventoryItem *);
  virtual bool HolsterItem(idInventoryItem *, bool);
  virtual void ShowAttachment(idInventoryItem *);
  virtual void HideAttachment(idInventoryItem *);
  virtual void DropAttachment(const equipSlot_t);
  virtual void DropAttachment_2(idInventoryItem *);
  virtual idEntity *DropItem(idInventoryItem *, bool, bool, int, const idVec3 *, const idVec3 *);
  virtual idInventoryItem *GetEquipped(const equipSlot_t);
  virtual void ClearEquipped(idInventoryItem *);
  virtual void ClearEquipped_2(const equipSlot_t);
  virtual idFXManager *GetFXMgrForAttachment(idInventoryItem *);
  virtual idStrId *GetCurrentNPC(idStrId *result);
  virtual idAASPositionMgr *GetAASPositionMgr();
  virtual bool HasSyncedWalks();
  virtual void SetApplyBulletTime(float, float);
  virtual void SetApplyInvulnerability(float);
  virtual void SetApplyAuthorityForce(float, const idDeclInventory *);
  virtual bool CanBeHealed();
  virtual posture_t GetPosture();
  virtual void SetPosture(const posture_t);
  virtual leanState_t GetLeanState();
  virtual void SetLeanState(const leanState_t);
  virtual walkState_t GetWalkState();
  virtual void SetWalkState(const walkState_t);
  virtual weaponReadyState_t GetWeaponReadyState();
  virtual void SetWeaponReadyState(const weaponReadyState_t);
  virtual float GetApplyDamageScale();
  virtual void SetApplyDamageScale(float, float);
  virtual const idVehicle *GetVehicle();
  virtual idVehicle *GetVehicle_2();
  virtual bool IsDrivingVehicle();
  virtual usableState_t GetOnlineUsableState();
  virtual aiWalkModifier_t GetWalkModifier();
  virtual aiWalkModifier_t GetRunModifier();
  virtual int AddFiber(const idHandle<int,enum invalidFiberId_t,0>);
  virtual void RemoveFiber(const idHandle<int,enum invalidFiberId_t,0>);
  virtual void SetEventOverloadEnableFlags(const idAIEvent::aiEventClass_t);
  virtual void SetEventOverloadDisableFlags(const idAIEvent::aiEventClass_t);
  virtual int GetEventResponseFlags();
  virtual const idAINavPowerMoverParms *GetNavParms();
  virtual const idAINavPowerMover3DParms *GetNavParms3d();

  idAI2::idAIConstant aiConstants;
  idAIEditable aiEditable;
  idAI2::idAIVolatile aiVolatile;
  idAIHealth aiHealth;
  idComponentActionScript actionScript;
  idAIFSMCallback fsmCallback;
  const idDeclInventory *inventoryDecl;
  idFormationCoverMgr formationCover;
  int takedownWindowClosed;
  idAIScriptProxy scriptProxy;
  idAI2Patch1 patch1;
};

// IDA Local Type ordinal 16587; PDB kind: class.
class idAI2::idAIConstant::idAIPhysics
{
public:
  idVec3 playerCollisionSize;
  float heightCrouched;
  float aiPathfindRadius;
  idContents contents;
  idContents clipMask;
  idContents playerClipMask;
};

// IDA Local Type ordinal 16589; PDB kind: class.
class __declspec(align(4)) idAI2::idAIConstant::idAIMovement
{
public:
  idStr aasName;
  idRange<float> moveSpeed;
  idRange<float> bodyTurnRate;
  idRange<float> moveTurnRate;
  float accelRate;
  float decelRate;
  idTypesafeNumber<float,enum DegreesUnique_t> alignmentTolerance;
  aiMovementMode_t defaultMovementMode;
  idEntityInfluenceTrail influence;
  bool useMoveFSM;
  bool allowStrafing;
};

// IDA Local Type ordinal 16591; PDB kind: class.
class __declspec(align(4)) idAI2::idAnimWebDefaults
{
public:
  idAnimWebPath webPath;
  idList<idAtomicString,5> activeLayers;
  bool enabled;
};

// IDA Local Type ordinal 16592; PDB kind: class.
class __declspec(align(4)) idAI2::idAIConstant::idAIAnimation
{
public:
  const idDeclAnimWeb *animWebs[1];
  idAI2::idAnimWebDefaults animWebDefaults[1];
  idStr eyeInfoName;
  idAtomicString viewTagName;
  __int8 useFaceManager : 1;
  __int8 useLidDeformation : 1;
  __int8 useBlinking : 1;
  __int8 useFaceSetupEyeTracking : 1;
  __int8 useEyeTracking : 1;
  __int8 useGestures : 1;
  __int8 useLipsync : 1;
  __int8 useMoods : 1;
  unsigned __int8 : 2;
  __int8 useFaceSetupEyeTrackingEnabled : 1;
  __int8 useFacialAnimsEnabled : 1;
  __int8 useGesturesEnabled : 1;
  __int8 useLipsyncEnabled : 1;
  __int8 useMoodsEnabled : 1;
  __int8 useFacialAnims : 1;
};

// IDA Local Type ordinal 16593; PDB kind: class.
class idAI2::idAIConstant::idAIOnlineScoring
{
public:
  bool heavy;
};

// IDA Local Type ordinal 16594; PDB kind: class.
class __declspec(align(4)) idAI2::idAIConstant
{
public:
  idAI2::idAIConstant::idAIPhysics physics;
  idAI2::idAIConstant::idAIMovement movement;
  idAI2::idAIConstant::idAIAnimation animation;
  idAI2::idAIConstant::idAIOnlineScoring onlineScoring;
};

// IDA Local Type ordinal 16717; PDB kind: class.
class idAI2::idAIVolatile::idAIPhysics
{
public:
  idPhysics_AI object;
  aiExtendedClipModelStatus_t extendedClipModelStatus;
  int extendedClipModelEndTime;
  idClipModel *extendedClipModel;
  idAIMoveState moveState;
  int movePushEndTime;
  int restoreSolidCollisionTime;
};

// IDA Local Type ordinal 16718; PDB kind: class.
class idAI2::idAIVolatile::idAIPerception
{
public:
  float fovDot;
  int flags;
};

// IDA Local Type ordinal 16719; PDB kind: class.
class idAI2::idAIVolatile::idAIAAS
{
public:
  const idAAS2 *aas;
  int travelFlags;
};

// IDA Local Type ordinal 16720; PDB kind: class.
class idAI2::idAIVolatile::idAIHeadTracking
{
public:
  idAngles targetKickOffset;
  idAngles curKickOffset;
  idAngles kickAccelRate;
  idAngles kickDecelRate;
};

// IDA Local Type ordinal 16721; PDB kind: class.
class idAI2::idAIVolatile::idAIEyeTracking
{
public:
  idHandle<unsigned short,enum invalidEyeInfo_t,65535> eyeInfoHandle;
};

// IDA Local Type ordinal 16735; PDB kind: class.
class idAI2::idAIVolatile::idAIFocusInfo
{
public:
  idArray<idFocusInfo,2> foci;
  idAIOrientation bodyOrientation;
  bool enableHeadTracking;
  bool enableBodyRotation;
  bool enableAutoFocus;
  bool enableGreetings;
  idCheckSurroundingsState checkSurroundingsState;
};

// IDA Local Type ordinal 16736; PDB kind: class.
class idAI2::idAIVolatile::idAIFacialInfo
{
public:
  idDeclFacialAnimationSet *currentFacialAnimSet;
};

// IDA Local Type ordinal 16737; PDB kind: class.
class __declspec(align(8)) idAI2::idAIVolatile::idAIWorldStateInfo
{
public:
  idAIWorldState worldState;
  idEntityPtr<idEntity> fakeEnemy;
};

// IDA Local Type ordinal 16746; PDB kind: class.
class __declspec(align(8)) idAI2::idAIVolatile::idAIDeath
{
public:
  int nextPainTime;
  int ragdollAtRestTime;
  int deathTime;
  int injuredCount;
  int maxDeferDeathTime;
  idGoreComponent goreComponent;
  idAIDeathInfo deathInfo;
  __int8 lootBoxEvent : 1;
  __int8 noRagdoll : 1;
  __int8 isRagdolling : 1;
  __int8 retryDeath : 1;
  __int8 droppedLootBox : 1;
  __int8 oneShotted : 1;
  __int8 isSmoking : 1;
  __int8 disableDeathAnims : 1;
  unsigned __int8 : 6;
  __int8 forceAllowLooting : 1;
  __int8 removeEventCalled : 1;
};

// IDA Local Type ordinal 16753; PDB kind: class.
class idAI2::idAIVolatile::idAIPain
{
public:
  idAIDamageInfo damageInfo;
};

// IDA Local Type ordinal 17117; PDB kind: class.
class __declspec(align(4)) idAI2::idAIVolatile::idAIFSMInfo
{
public:
  idAIFSMManager fsmManager;
  __unaligned __declspec(align(1)) idAIActionManager actionManager;
  alertCycle_t alertCycle;
  alertCycle_t previousAlertCycle;
  bool suspend;
};

// IDA Local Type ordinal 17121; PDB kind: class.
class idAI2::idAIVolatile::idAICoverInfo
{
public:
  coverAction_t coverAction;
  coverAction_t coverActionToAvoid;
  coverOrientation_t coverOrientation;
};

// IDA Local Type ordinal 17122; PDB kind: class.
class idAI2::idAIVolatile::idDodgeInfo
{
public:
  int nextDodgeTime;
  aiMovementMode_t preDodgeMoveMode;
};

// IDA Local Type ordinal 17125; PDB kind: class.
class idAI2::idAIVolatile::idAIEventInfo
{
public:
  int flags;
  int overloadEnableFlags;
  int overloadDisableFlags;
  int nextAIEventTime;
  idStaticList<idHandle<int,enum invalidAIEvent_t,-1>,4> pendingAIEvents;
};

// IDA Local Type ordinal 17202; PDB kind: class.
class idAI2::idAIVolatile::idAIAnimationInfo
{
public:
  idArray<idAnimWebAI,1> animWebAnimator;
  aiSubWeb_t subWeb;
  idAnimWebCmdCtx awCmdCtx;
  idAnimator_TurretNxN<3> turretAnimator;
  idAnimator_Pain painAnimator;
  idAnimator_RollBones rollBonesAnimator;
  idAnimator_FaceTracks faceAnimator;
  idAnimator_DragJoints dragJointsAnimator;
  tagData_t viewTagData;
  int meleeFlags;
  int crouchMeleeFlags;
  idAnimFSMHumanoid animFSM;
};

// IDA Local Type ordinal 17205; PDB kind: class.
class idAI2::idAIVolatile::idPlayerAIControl
{
public:
  idAICamera_Control camera;
  idEntityPtr<idPlayer> player;
  float minHealth;
  int endControlTime;
  int startControlTime;
  int nextBeatTime;
  bool heartBeatLub;
  bool popping;
  idVec3 bodyHitNormal;
  idHandle<int,enum invalidAIEvent_t,-1> possessionEvent;
  idAngles viewAngle;
  idInterpolate<float> introInterp;
  idClipQuery attackQuery;
};

// IDA Local Type ordinal 17210; PDB kind: class.
class idAI2::idAIVolatile::idAIScriptInfo
{
public:
  int flags;
  idThread *thread;
  idStaticList<idHandle<int,enum invalidThreadHandle_t,0>,4> threads;
  idStaticList<idHandle<int,enum invalidFiberId_t,0>,4> fibers;
  const idAIEvent *currentAIEvent;
  int lastAIEventClass;
  idVec3 lastAIEventOrigin;
  idEntityPtr<idEntity> lastAIEventOriginator;
  idEntityPtr<idEntity> lastAIEventInstigator;
};

// IDA Local Type ordinal 17213; PDB kind: class.
class __declspec(align(4)) idAI2::idAIVolatile::idAIDebugging
{
public:
  idArray<idRenderModel *,6> debugModels;
  idArray<idSoundShader const *,6> debugSounds;
  idAI2::aiDebugLevel_t modelLevel;
  idAI2::aiDebugLevel_t soundLevel;
  idStr debugText;
  idAI2::aiDebugLevel_t textLevel;
  int errorFlags;
  char modelIndex;
  char soundIndex;
};

// IDA Local Type ordinal 17214; PDB kind: class.
class idAI2::idAIVolatile::idAIGroupStatus
{
public:
  encounterGroupRole_t currentRole;
  encounterGroupRole_t pendingRole;
  idAI2::aiCondition_t condition;
  bool roleChangeResponseRequired;
  bool voChainAudible;
  voChainState_t voChainCategory;
  voChainState_t voChainState;
  idAI2::aiCondition_t preventativeCondition;
};

// IDA Local Type ordinal 17237; PDB kind: class.
class __declspec(align(8)) idAI2::idVisibilityObscurity
{
public:
  idClipQuery clipQuery[7];
  idArray<enum idAI2::idVisibilityObscurity::obscurity_t,7> visibilityObscurity;
  int lastSubmitFrame;
  bool anyCover;
  bool anyClearLanes;
  bool valid;
};

// IDA Local Type ordinal 17240; PDB kind: class.
class idAI2::idAIVolatile
{
public:
  idAI2::idAIVolatile::idAIPhysics physics;
  idAI2::idAIVolatile::idAIPerception perception;
  idAI2::idAIVolatile::idAIAAS aas;
  idAI2::idAIVolatile::idAIHeadTracking headTracking;
  idAI2::idAIVolatile::idAIEyeTracking eyeTracking;
  idAI2::idAIVolatile::idAIFocusInfo focus;
  idAI2::idAIVolatile::idAIFacialInfo facialInfo;
  idAI2::idAIVolatile::idAIWorldStateInfo world;
  idAI2::idAIVolatile::idAIDeath death;
  idAI2::idAIVolatile::idAIPain pain;
  __unaligned __declspec(align(1)) idAI2::idAIVolatile::idAIFSMInfo fsms;
  idAIFireControl *fireControl;
  idAI2::idAIVolatile::idAICoverInfo cover;
  idAI2::idAIVolatile::idDodgeInfo dodging;
  idAI2::idAIVolatile::idAIEventInfo aiEvents;
  idAI2::idAIVolatile::idAIAnimationInfo animation;
  idAI2::idAIVolatile::idPlayerAIControl playerControl;
  idAI2::idAIVolatile::idAIScriptInfo script;
  idAI2::idAIVolatile::idAIDebugging debugging;
  idAI2::idAIVolatile::idAIGroupStatus groupStatus;
  idArray<idTrajectory_Parabolic,4> trajectories;
  idAIMemory memory;
  idAIVoiceController voiceController;
  idHandle<short,enum invalidEncounterGroup_t,-1> encounterGroupHandle;
  idAICoverManager coverManager;
  idFaceMgr faceMgr;
  idAIPlayerInteraction aiPlayerInteraction;
  playerInteractionState_t tempPlayerInteractionInfoState;
  __int8 isInCombatForSubtitles : 1;
  __int8 leftPlayerInteractionRadius : 1;
  __int8 receivedPlayerInteractionEvent : 1;
  __int8 activateWhenVisibleOverride : 1;
  __int8 isIdleTracking : 1;
  __int8 isInteracting : 1;
  __int8 incapacitatedPlayer : 1;
  __int8 firstThink : 1;
  unsigned __int8 : 7;
  __int8 isObstacleAvoiding_Player : 1;
  __int16 dropState;
  __int16 numActionNodes;
  idAI2::idVisibilityObscurity visibilityObscurity;
  idMeleeTrace meleeTrace;
  idClipQuery dropToGroundQuery;
  idArray<float,6> playerDamageTaken;
  idArray<int,6> playerMeleeTime;
};

// IDA Local Type ordinal 21514; PDB kind: class.
class idAI2::FindClosestFocus::__l2::idLookDebug
{
public:
  idAI2 *ai;
  const char *text;
  int time;
};
