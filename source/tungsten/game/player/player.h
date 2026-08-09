#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\player\player.h
// Recovered logical types: 149
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1105; PDB kind: enum.
enum idPlayer::tensionType_t : __int32
{
  PLAYER_TENSION_NONE = 0x0,
  PLAYER_TENSION_TENTATIVE = 0x1,
  PLAYER_TENSION_HOSTILE = 0x2,
};

// IDA Local Type ordinal 1207; PDB kind: enum.
enum idPlayer::offerChoice_t : __int32
{
  OFFERCHOICE_DECLINED = 0x0,
  OFFERCHOICE_ACCEPTED = 0x1,
  OFFERCHOICE_PURCHASE = 0x2,
  OFFERCHOICE_GENERICSELECTION_1 = 0x3,
  OFFERCHOICE_GENERICSELECTION_2 = 0x4,
  OFFERCHOICE_GENERICSELECTION_3 = 0x5,
  OFFERCHOICE_GENERICSELECTION_4 = 0x6,
  OFFERCHOICE_UNKNOWN = 0x7,
};

// IDA Local Type ordinal 1208; PDB kind: enum.
enum idPlayer::offerType_t : __int32
{
  OFFERTYPE_NONE = 0x0,
  OFFERTYPE_JOB = 0x1,
  OFFERTYPE_VENDER = 0x2,
};

// IDA Local Type ordinal 1237; PDB kind: enum.
enum idPlayer::idPlayerBehaviorContextualShimmyState_t : __int32
{
  CONTEXTUAL_SHIMMY_STATE_NONE = 0x0,
  CONTEXTUAL_SHIMMY_STATE_MOUNT_LEFT_0 = 0x1,
  CONTEXTUAL_SHIMMY_STATE_MOUNT_RIGHT_0 = 0x2,
  CONTEXTUAL_SHIMMY_STATE_MOUNT_BACK_0 = 0x3,
  CONTEXTUAL_SHIMMY_STATE_MOUNT_LEFT_90 = 0x4,
  CONTEXTUAL_SHIMMY_STATE_MOUNT_RIGHT_90 = 0x5,
  CONTEXTUAL_SHIMMY_STATE_MOUNT_LEFT_180 = 0x6,
  CONTEXTUAL_SHIMMY_STATE_MOUNT_RIGHT_180 = 0x7,
  CONTEXTUAL_SHIMMY_STATE_MOUNT_INSIDESSHQ_CLIMBOUT = 0x8,
  CONTEXTUAL_SHIMMY_STATE_MOUNT_CUSTOMANIM = 0x9,
  CONTEXTUAL_SHIMMY_STATE_IDLE = 0xA,
  CONTEXTUAL_SHIMMY_STATE_SHIMMY_RIGHT = 0xB,
  CONTEXTUAL_SHIMMY_STATE_SHIMMY_LEFT = 0xC,
  CONTEXTUAL_SHIMMY_STATE_DISMOUNT_RIGHT = 0xD,
  CONTEXTUAL_SHIMMY_STATE_DISMOUNT_FORWARD = 0xE,
  CONTEXTUAL_SHIMMY_STATE_DISMOUNT_LEFT = 0xF,
  CONTEXTUAL_SHIMMY_STATE_DISMOUNT_FALL = 0x10,
  CONTEXTUAL_SHIMMY_STATE_DISMOUNT_CUSTOMANIM = 0x11,
  CONTEXTUAL_SHIMMY_STATE_SWITCH_OUT90RIGHT = 0x12,
  CONTEXTUAL_SHIMMY_STATE_SWITCH_OUT90LEFT = 0x13,
  CONTEXTUAL_SHIMMY_STATE_SWITCH_IN90RIGHT = 0x14,
  CONTEXTUAL_SHIMMY_STATE_SWITCH_IN90LEFT = 0x15,
  CONTEXTUAL_SHIMMY_STATE_MAX = 0x16,
};

// IDA Local Type ordinal 1239; PDB kind: enum.
typedef idPlayer::idPlayerBehaviorWallClimb::bodyRotationAnim_t idPlayer::idPlayerBehaviorContextualShimmy::bodyRotationAnim_t;

// IDA Local Type ordinal 1240; PDB kind: enum.
enum idPlayer::idPlayerBehaviorWallClimbState_t : __int32
{
  WALLCLIMB_STATE_NONE = 0x0,
  WALLCLIMB_STATE_MOUNT = 0x1,
  WALLCLIMB_STATE_IDLE = 0x2,
  WALLCLIMB_STATE_CLIMB_UP = 0x3,
  WALLCLIMB_STATE_CLIMB_DOWN = 0x4,
  WALLCLIMB_STATE_DISMOUNT_UP = 0x5,
  WALLCLIMB_STATE_DISMOUNT_FALL = 0x6,
  WALLCLIMB_STATE_SHUTDOWN = 0x7,
  WALLCLIMB_STATE_MAX = 0x8,
};

// IDA Local Type ordinal 1241; PDB kind: enum.
typedef idPlayer::idPlayerBehaviorSprintSlide::bodyRotationAnim_t idPlayer::idPlayerBehaviorWallClimb::bodyRotationAnim_t;

// IDA Local Type ordinal 1247; PDB kind: enum.
enum idPlayer::idPlayerBehaviorTakedown::idPlayerBehaviorTakedownState_t : __int32
{
  TAKEDOWNSTATE_NONE = 0x0,
  TAKEDOWNSTATE_INTAKEDOWN = 0x1,
};

// IDA Local Type ordinal 1248; PDB kind: enum.
enum idPlayer::idPlayerBehaviorSprintSlideState_t : __int32
{
  SPRINT_SLIDE_STATE_NONE = 0x0,
  SPRINT_SLIDE_STATE_SLIDING = 0x1,
  SPRINT_SLIDE_STATE_END_STAND = 0x2,
  SPRINT_SLIDE_STATE_END_CROUCH = 0x3,
  SPRINT_SLIDE_STATE_END_FALL = 0x4,
  SPRINT_SLIDE_STATE_MAX = 0x5,
};

// IDA Local Type ordinal 1249; PDB kind: enum.
typedef idPlayer::idPlayerBehaviorContextualLadder::bodyRotationAnim_t idPlayer::idPlayerBehaviorSprintSlide::bodyRotationAnim_t;

// IDA Local Type ordinal 1252; PDB kind: enum.
enum idPlayer::idPlayerBehaviorLeanState_t : __int32
{
  LEAN_STATE_NONE = 0x0,
  LEAN_STATE_LEANING = 0x1,
  LEAN_STATE_RESTART = 0x2,
  LEAN_STATE_END = 0x3,
  LEAN_STATE_MAX = 0x4,
};

// IDA Local Type ordinal 1256; PDB kind: enum.
enum idPlayer::idPlayerBehaviorContextualLadderState_t : __int32
{
  CONTEXTUAL_LADDER_STATE_NONE = 0x0,
  CONTEXTUAL_LADDER_STATE_MOUNT_BOTTOM = 0x1,
  CONTEXTUAL_LADDER_STATE_MOUNT_MID = 0x2,
  CONTEXTUAL_LADDER_STATE_MOUNT_TOP = 0x3,
  CONTEXTUAL_LADDER_STATE_IDLE_UP_LEFT = 0x4,
  CONTEXTUAL_LADDER_STATE_IDLE_UP_RIGHT = 0x5,
  CONTEXTUAL_LADDER_STATE_CLIMB_DOWN_LEFT = 0x6,
  CONTEXTUAL_LADDER_STATE_CLIMB_DOWN_RIGHT = 0x7,
  CONTEXTUAL_LADDER_STATE_CLIMB_UP_LEFT = 0x8,
  CONTEXTUAL_LADDER_STATE_CLIMB_UP_RIGHT = 0x9,
  CONTEXTUAL_LADDER_STATE_SLIDE_DOWN_LEFT = 0xA,
  CONTEXTUAL_LADDER_STATE_SLIDE_DOWN_RIGHT = 0xB,
  CONTEXTUAL_LADDER_STATE_DISMOUNT_GROUND = 0xC,
  CONTEXTUAL_LADDER_STATE_DISMOUNT_MID = 0xD,
  CONTEXTUAL_LADDER_STATE_DISMOUNT_MID_PUSH = 0xE,
  CONTEXTUAL_LADDER_STATE_DISMOUNT_TOP = 0xF,
  CONTEXTUAL_LADDER_STATE_DEBUG_TEST_ANIM = 0x10,
  CONTEXTUAL_LADDER_STATE_MAX = 0x11,
};

// IDA Local Type ordinal 1257; PDB kind: enum.
enum idPlayer::idPlayerBehaviorContextualLadderDismountType_t : __int32
{
  CONTEXTUAL_LADDER_DISMOUNT_TYPE_NONE = 0x0,
  CONTEXTUAL_LADDER_DISMOUNT_TYPE_LEFT = 0x1,
  CONTEXTUAL_LADDER_DISMOUNT_TYPE_RIGHT = 0x2,
  CONTEXTUAL_LADDER_DISMOUNT_TYPE_BACK = 0x3,
  CONTEXTUAL_LADDER_DISMOUNT_TYPE_JUMP = 0x4,
  CONTEXTUAL_LADDER_DISMOUNT_TYPE_MAX = 0x5,
};

// IDA Local Type ordinal 1258; PDB kind: enum.
enum idPlayer::idPlayerBehaviorContextualLadder::sharedLadderAliases_t : __int32
{
  SHARED_ALIAS_MOUNT_BOTTOM = 0x0,
  SHARED_ALIAS_MOUNT_MID_OUT = 0x1,
  SHARED_ALIAS_MOUNT_TOP = 0x2,
  SHARED_ALIAS_SLIDESTOPLEFT = 0x3,
  SHARED_ALIAS_SLIDESTOPRIGHT = 0x4,
  SHARED_ALIAS_IDLEUPLEFT = 0x5,
  SHARED_ALIAS_IDLEUPRIGHT = 0x6,
  SHARED_ALIAS_CLIMBDOWNLEFT = 0x7,
  SHARED_ALIAS_CLIMBDOWNRIGHT = 0x8,
  SHARED_ALIAS_CLIMBUPLEFT = 0x9,
  SHARED_ALIAS_CLIMBUPRIGHT = 0xA,
  SHARED_ALIAS_SLIDEINTOLEFT = 0xB,
  SHARED_ALIAS_SLIDEINTORIGHT = 0xC,
  SHARED_ALIAS_SLIDEDISMOUNTLEFT = 0xD,
  SHARED_ALIAS_SLIDEDISMOUNTRIGHT = 0xE,
  SHARED_ALIAS_DISMOUNTBOTTOMRIGHT = 0xF,
  SHARED_ALIAS_DISMOUNTBOTTOMLEFT = 0x10,
  SHARED_ALIAS_DISMOUNTMIDLEFT = 0x11,
  SHARED_ALIAS_DISMOUNTMIDRIGHT = 0x12,
  SHARED_ALIAS_DISMOUNTTOPRIGHT = 0x13,
  SHARED_ALIAS_DISMOUNTTOPLEFT = 0x14,
  SHARED_ALIAS_SLIDERIGHT = 0x15,
  SHARED_ALIAS_SLIDELEFT = 0x16,
  SHARED_ALIAS_MAX = 0x17,
};

// IDA Local Type ordinal 1259; PDB kind: enum.
enum idPlayer::idPlayerBehaviorShared::thirdPersonModelFlags_t : __int32
{
  TPMODELFLAG_AUTO_ALIGN_TO_PLAYER = 0x1,
  TPMODELFLAG_ANIM_DELTAS_APPLY_TO_PLAYER = 0x2,
  TPMODELFLAG_ANIM_DELTAS_CLIP = 0x4,
  TPMODELFLAG_ANIM_DELTAS_SMOOTH = 0x8,
  TPMODELFLAG_ANIM_DELTAS_REPEAT_ON_ZERO = 0x10,
  TPMODELFLAG_ANIM_DELTAS_SKIP_ONE_FRAME = 0x20,
};

// IDA Local Type ordinal 1260; PDB kind: enum.
enum idPlayer::idPlayerBehaviorShared::thirdPersonModelResultFlags_t : __int32
{
  TPMODELRESULTFLAG_ANIM_DELTAS_SMOOTHED_POS = 0x1,
  TPMODELRESULTFLAG_ANIM_DELTAS_SMOOTHED_ROT = 0x2,
  TPMODELRESULTFLAG_ANIM_DELTAS_REPEATED_POS = 0x4,
  TPMODELRESULTFLAG_ANIM_DELTAS_REPEATED_ROT = 0x8,
  TPMODELRESULTFLAG_ANIM_DELTAS_INCLUDES_EXTERNAL = 0x10,
};

// IDA Local Type ordinal 1269; PDB kind: enum.
typedef firePoint_t idPlayer::firePoint_t;

// IDA Local Type ordinal 1282; PDB kind: enum.
enum idPlayer::idPlayerBehaviorContextualLadder::bodyRotationAnim_t : __int32
{
  BODY_ROTATION_CENTER = 0x0,
  BODY_ROTATION_LEFT = 0x1,
  BODY_ROTATION_RIGHT = 0x2,
  BODY_ROTATION_UP = 0x3,
  BODY_ROTATION_DOWN = 0x4,
  BODY_ROTATION_MAX = 0x5,
};

// IDA Local Type ordinal 1290; PDB kind: enum.
enum idPlayer::lightDebugHelperModelType_t : __int32
{
  LIGHTDEBUGHELPERMODELTYPE_INVALID = 0xFFFFFFFF,
  LIGHTDEBUGHELPERMODELTYPE_BLACK_100 = 0x0,
  LIGHTDEBUGHELPERMODELTYPE_GREY = 0x1,
  LIGHTDEBUGHELPERMODELTYPE_GREY_50 = 0x2,
  LIGHTDEBUGHELPERMODELTYPE_WHITE = 0x3,
  LIGHTDEBUGHELPERMODELTYPE_NUM = 0x4,
};

// IDA Local Type ordinal 2142; PDB kind: enum.
enum idLayer::layerState_t : __int32
{
  LAYERSTATE_DEACTIVE = 0x0,
  LAYERSTATE_ACTIVE = 0x1,
};

// IDA Local Type ordinal 2283; PDB kind: enum.
enum aiPlayer_t : __int32
{
  AIPLAYER_CLOSEST = 0x0,
  AIPLAYER_FARTHEST = 0x1,
  AIPLAYER_LOWEST_HEALTH = 0x2,
  AIPLAYER_HIGHEST_HEALTH = 0x3,
  AIPLAYER_MAX = 0x4,
};

// IDA Local Type ordinal 2754; PDB kind: enum.
enum idPlayer::guiModelType_t : __int32
{
  GUI_MODEL_INVALID = 0x0,
  GUI_MODEL_INVENTORY = 0x1,
  GUI_MODEL_WEAPONSELECT = 0x2,
};

// IDA Local Type ordinal 3530; PDB kind: unknown.
typedef CCalHttpStream::<unnamed_tag> CCalPlayer::<unnamed_tag>;

// IDA Local Type ordinal 14312; PDB kind: class.
class idPlayer : public idActor
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34003.
  virtual idTypeInfo *GetType();
  virtual ~idPlayer();
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

  idRenderModel *lightDebugHelperModel;
  idPlayer::lightDebugHelperModelType_t lightDebugHelperCommited;
  const idMaterial *lightDebugHelperTypes[4];
  const idDeclEntityDef *thirdPersonHandsDef;
  idAlignedEntity *thirdPersonHands;
  const idDeclEntityDef *thirdPersonLegsDef;
  idAlignedEntity *thirdPersonLegs;
  idPlayer::idPlayerBehaviors behaviors;
  int debugHud_x;
  int debugHud_y;
  int currentDPadSelection;
  int vehicleWeaponGroupIndex;
  int vehicleQuickUseIndex;
  bool loadoutChanged;
  idInventoryItem *holsteredForRCcontroller;
  bool snapBackFromRCcontroller;
  int spawnTimeMS;
  const idDeclMD6 *handsModel;
  const idDeclPlayerProps *playerProps;
  const idDeclEntityDef *playerDriver[2];
  idDragEntity dragEntity;
  decayParams_s standDecay;
  decayParams_s crouchDecay;
  bool ignoreFallDamage;
  idPlayer::playerBodyAnimInfo_t bodyAnimInfo;
  idTungstenHealth playerHealth;
  idVec2 guiObjectScreenCoords;
  idEntityPtr<idEntity> guiInteractionEntity;
  bool isControllingAi;
  int vendorKeyIndex;
  idGatherQuery lootQuery;
  bool lootSoundPlayed;
  idGatherQuery onlinePlayerUseableQuery;
  bool shouldHideVehicles;
  const idDeclParticle *prtUnderwater;
  const idDeclParticle *prtWaterTransition;
  const idDeclParticle *prtWaterSplash;
  bool transitionEffectIsRunning;
  bool underwaterEffectIsRunning;
  bool lastFrameUnderwater;
  bool lastFrameInWater;
  int lastDamagedTime;
  int lastHealthUpdate;
  int bonusStamp;
  idPlayer::tensionType_t currentPlayerTension;
  int lastSetTensionTime;
  idVolume_ShowGui_Leveltransition *levelTransitionGuiVolume;
  bool levelTransitionGuiVolumeActive;
  bool inPersonalGarage;
  idStaticList<idEntityPtr<idEntity>,2> droppableList;
  idMat3 modelAxis;
  idVec3 playerModelOffset;
  idList<idHandle<int,enum invalidAttachment_t,-1>,5> throwableAttachments;
  int maxTimeUnderwater;
  int refillAirTime;
  float sprintAirReductionScale;
  const idDeclDamage *suffocationDamage;
  int diveTime;
  float airLeft;
  idEntityPtr<idEntity> deathTrigger;
  idJobManager jobManager;
  idJobTimerManager jobTimerManager;
  idPlayer::offerChoice_t lastOfferChoice;
  idGameLayerManager gameLayerManager;
  idPlayer::infoMessages_t infoMessages;
  idPlayer::npcInteractionState_t npcInteractionState;
  const idDeclInventory *mutantTag;
  idList<idPlayer::newInventoryItems_t,5> newItemList;
  unsigned __int8 : 1;
  __int8 readingLevelStateFromFile : 1;
  __int8 transitioning : 1;
  __int8 noTarget : 1;
  __int8 noPlayerDeath : 1;
  __int8 infiniteHealth : 1;
  __int8 godMode : 1;
  __int8 hidden : 1;
  int lastIncapacitate;
  idPlayerAuditor auditor;
  float hitFlashDuration;
  int hitFlashTime;
  idStaticList<idEntityPtr<idEntity const >,4> nearbyThreats;
  idDeathCamera *deathCamera;
  idOnlineVehicleDeathCamera *onlineVehicleDeathCamera;
  idThrownCamera *thrownCamera;
  idInteractionCamera *dynamicInteractionCamera;
  idSpectatorCamera *spectatorCamera;
  idSlowMotionCamera *slowMotionCamera;
  idReviveCamera *reviveCamera;
  idHandle<int,enum invalidAttachment_t,-1> reviveItemAttachment;
  idEntityPtr<idCamera> controlledCameraEntity;
  bool controlledCameraEntityAllowHUD;
  idEntityPtr<idVehicle> lastVehicle;
  idBot *botController;
  const idDeclTable *easyTable;
  const idDeclTable *normalTable;
  const idDeclTable *hardTable;
  const idDeclTable *nightmareTable;
  float applyDamageScale;
  int applyDamageScaleEndTime;
  int invulnerabilityEndTime;
  bool isInvulnerable;
  int bulletTimeEndTime;
  int authorityStartTime;
  int authorityEndTime;
  const idMaterial *authorityIcon;
  idClipQuery dofFocusTrace;
  float dofCurrentFocus;
  float dofGoalFocus;
  idVec3 onAiPushDir;
  int onAiChangePushDirMilliSeconds;
  idPlayer::idPlayerCover cover;
  idSpringCamera *springCamera;
  int overrideActiveJob;
  idEntityPtr<idPlayer> reviveTarget;
  idEntityPtr<idEntity> killer;
  idVec3 lastSpawnPos;
  profileStatValue_t stats[500];
  idAchievementManager achievementManager;
  const idAAS2 *aas;
  idVec3 previousCoverCheckPos;
  int currentCoverCheckIndex;
  idList<idPlayerCoverScore_t,5> playerCoverScores;
  const idDeclInventory *cashDecl;
  const idDeclInventory *cashVehicleDecl;
  const idDeclDuck *incapDuck;
  const idDeclMD6 *coopModelDef;
  const idDeclAiEvent *playerAimEventDecl;
  const idDeclAiEvent *playerInteractionEventDecl;
  const idDeclAiEvent *bodyEventDecl;
  const idDeclEntityDef *demonPlayer;
  idAASPositionMgr aasPositionMgr;
};

// IDA Local Type ordinal 14315; PDB kind: struct.
struct idPlayer::idPlayerBehaviorShared
{
  int thirdPersonHandsFlags;
  int thirdPersonLegsFlags;
  int sharedFlags;
  idVec3 deltaTransExternalWorld;
  idVec3 deltaTransScale;
};

// IDA Local Type ordinal 14318; PDB kind: struct.
struct idPlayer::idPlayerBehaviorContextualShimmy
{
  idEntityPtr<idLedge> ledge;
  idEntityPtr<idUseLedge> useLedge;
  int currentLedgeBit;
  int nextLedgeBit;
  idPlayer::idPlayerBehaviorContextualShimmyState_t state;
  idPlayer::idPlayerBehaviorContextualShimmyState_t prevState;
  idPlayer::idPlayerBehaviorContextualShimmyState_t dismountState;
  bool bEnabled;
  int initiateInputTime;
  idVec3 legsAlignPos;
  idSpring<idVec1> averagedBodyRotationT;
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> bodyRotationAnimAliasHandles[3];
  float fireTimeMS;
  idSpring<idVec1> extraWorldTranslationBlend;
  idSpring<idVec1> extraWorldRotationBlend;
  int nextFidgetTime;
};

// IDA Local Type ordinal 14320; PDB kind: struct.
struct idPlayer::idPlayerBehaviorWallClimb
{
  idEntityPtr<idWallClimb> wallClimb;
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> bodyRotationAnimAliasHandles[3];
  idPlayer::idPlayerBehaviorWallClimbState_t state;
  bool bEnabled;
  idVec3 legsAlignPos;
  float sidewaysPosition;
  idSpring<idVec1> averagedBodyRotationT;
  idSpring<idVec1> extraWorldTranslationBlend;
  idSpring<idVec1> extraWorldRotationBlend;
  idSpring<idVec1> sideWaysTranslationBlend;
  int nextFidgetTime;
};

// IDA Local Type ordinal 14323; PDB kind: struct.
struct idPlayer::idPlayerBehaviorSprintSlide
{
  float additiveAnimAlphaMin;
  float additiveAnimAlphaMax;
  float additiveAnimAlphaMinSpeed;
  float additiveAnimAlphaMaxSpeed;
  float cameraShakeMin;
  float cameraShakeMax;
  float cameraShakeMinSpeed;
  float cameraShakeMaxSpeed;
  const idDeclImpactSound *slideSounds;
  float sndSlideMinVolume;
  float sndSlideMinVolumeSpeed;
  float sndSlideMaxVolume;
  float sndSlideMaxVolumeSpeed;
  idPlayer::idPlayerBehaviorSprintSlideState_t state;
  bool startSlide;
  bool endSlide;
  idVec3 forwardDir;
  float forwardSpeed;
  bool forceEndSlide;
  float maxSpeed;
  float friction;
  bool handsDeferredSave;
  bool legsDeferredSave;
  idSpringCamera::calculateViewStage_t springCamForceCalculateViewStageSave;
  float walkFrictionSave;
  idUCmdInhibit::inhibitFlags_t inhibitFlagsSave;
  int slideStartTime;
  idSpring<idVec3> legsFwdDirSpring;
  idSpring<idVec2> bodyRotationPos;
  idSpring<idVec1> bodyRotationAlpha;
  float bodyRotationAnimWeights[5];
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> bodyRotationLegsAnimAliasHandles[5];
  bool bEnabled;
  bool playLoopingSlideSound;
  const idSoundShader *loopingSlideSound;
};

// IDA Local Type ordinal 14324; PDB kind: struct.
struct idPlayer::idPlayerContextualLadderTestInfo
{
  bool bDisabled;
  bool bDetectedLadder;
  bool bDetectedLadderTop;
  idVec3 point;
  idVec3 normal;
  int surfaceFlags;
};

// IDA Local Type ordinal 14325; PDB kind: struct.
struct __declspec(align(8)) idPlayer::idPlayerBehaviorContextualLadder
{
  idPlayer::idPlayerBehaviorContextualLadderState_t state;
  idPlayer::idPlayerBehaviorContextualLadderState_t prevState;
  idPlayer::idPlayerBehaviorContextualLadderDismountType_t dismountType;
  bool bEnabled;
  int initiateInputTime;
  idPlayer::idPlayerContextualLadderTestInfo testForward;
  idPlayer::idPlayerContextualLadderTestInfo testBackward;
  idPlayer::idPlayerContextualLadderTestInfo testRight;
  idPlayer::idPlayerContextualLadderTestInfo testLeft;
  idPlayer::idPlayerContextualLadderTestInfo testTop;
  idPlayer::idPlayerContextualLadderTestInfo testBottom;
  float groundDist;
  float ceilingDist;
  idVec3 ladderNormal;
  idVec3 ladderUp;
  idVec3 ladderRight;
  idVec3 handsAlignPos;
  idVec3 legsAlignPos;
  idVec3 prevPlayerMovementPos;
  idAngles prevPlayerMovementAngles;
  float prevPlayerDeltaZ;
  idSpring<idVec2> averagedBodyRotationT;
  int canMountTime;
  idSpring<idVec1> speedScaleSpring;
  idClipQuery ladderClipQuery;
  bool invertInput;
  bool blockClimpOffAtTop;
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> legsAliases[23];
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> armsAliases[23];
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> armsRotationAnimAliasHandles[5];
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> legsRotationAnimAliasHandles[5];
};

// IDA Local Type ordinal 14326; PDB kind: struct.
struct __declspec(align(4)) idPlayer::idPlayerBehaviorLean
{
  idPlayer::idPlayerBehaviorLeanState_t state;
  idSpring<idVec3> leanOffset;
  idSpring<idVec1> rollOffset;
  float maxLeanDistLeft;
  float maxLeanDistRight;
  float maxLeanDistUp;
  bool startLean;
  bool endLean;
  idVec3 forwardDir;
  bool forceEndLean;
  idSpringCamera::calculateViewStage_t springCamForceCalculateViewStageSave;
  int leanStartTime;
  bool bEnabled;
};

// IDA Local Type ordinal 14327; PDB kind: struct.
struct idPlayer::idPlayerBehaviorTakedown
{
  idPlayer::idPlayerBehaviorTakedown::idPlayerBehaviorTakedownState_t state;
  idVec3 enemyPosition;
  idMat3 enemyAxis;
};

// IDA Local Type ordinal 14328; PDB kind: struct.
struct __declspec(align(8)) idPlayer::idPlayerBehaviors
{
  idPlayer::idPlayerBehaviorShared shared;
  idPlayer::idPlayerBehaviorContextualShimmy contextualShimmy;
  idPlayer::idPlayerBehaviorWallClimb wallClimb;
  idPlayer::idPlayerBehaviorSprintSlide sprintSlide;
  idPlayer::idPlayerBehaviorContextualLadder contextualLadder;
  idPlayer::idPlayerBehaviorLean lean;
  idPlayer::idPlayerBehaviorTakedown takedown;
  idList<idVec3,5> animDeltasTrans;
  idList<idAngles,5> animDeltasRot;
};

// IDA Local Type ordinal 14353; PDB kind: struct.
struct idPlayer::playerBodyAnimInfo_t
{
  bool turning;
  int framesIdle;
  idClipQuery movementQuery;
  idClipQuery jumpQuery;
  bool physicsJumped;
  bool hasJumped;
  int framesInAir;
  bool jumpPreLand;
  bool fwdMovementBlocked;
  idVec3 lastVelocity;
  tagData_t leftHandIKTag;
};

// IDA Local Type ordinal 14462; PDB kind: class.
class idLayer : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14463.
  virtual idTypeInfo *GetType();
  virtual ~idLayer();

  idStr layerDeclName;
  idLayer::layerState_t layerState;
};

// IDA Local Type ordinal 14466; PDB kind: struct.
struct idPlayer::infoMessages_t
{
  bool seenDiceHelp;
  int savedInventoryScreen;
};

// IDA Local Type ordinal 14467; PDB kind: class.
class idPlayer::npcInteractionState_t
{
public:
  idPlayer::offerType_t offerType;
  idStr offeringEntity;
  idStr interaction;
};

// IDA Local Type ordinal 14468; PDB kind: struct.
struct idPlayer::newInventoryItems_t
{
  const idDeclInventory *decl;
  bool seen;
  int page;
};

// IDA Local Type ordinal 14988; PDB kind: struct.
struct idPlayer::idPlayerCover
{
  const idAAS2 *aas;
  idVec3 intersectionPoint;
  idVec3 wallNormal;
  playerCoverPoint_t coverPoints[2];
};

// IDA Local Type ordinal 17516; PDB kind: class.
class idPlayerArmor : public idInventoryItem
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17517.
  virtual idTypeInfo *GetType();
  virtual ~idPlayerArmor();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void Init(const idDeclInventory *);
  virtual void Merge(idPresentable *, idInventoryCollection *, const idDeclInventory *);
  virtual void Hide();
  virtual void Show();
  virtual void OnEquip(const idPresentable *, idFXManager *);
  virtual void OnUnequip(const idPresentable *, idFXManager *);
  virtual void OnClone(const idInventoryItem *);
  virtual int GetCount();
  virtual bool CanUse(idActor *);
  virtual bool Use(idActor *);
  virtual bool CanUseInVehicle(idActor *);
  virtual bool ClientUse(idPresentablePlayer *);
  virtual void Serialize(idSerializer *, idInventoryCollection *);
  virtual void SerializeNonPrediction(idSerializer *, idInventoryCollection *);
  virtual void ClientUpdate();
  virtual void GetPickupHudInfo(const idEntity *, idPickupHudInfo *);

  float curArmorValue;
};

// IDA Local Type ordinal 17617; PDB kind: class.
class idPlayerStart : public idSpawnNode
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17618.
  virtual idTypeInfo *GetType();
  virtual ~idPlayerStart();
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
  virtual void GetValidSpawnLocations(const idGameplayFilterTarget *, const gameTeam_t *, float, bool, idList<idSpawnLocation,5> *, const int);
  virtual void ReportBlockedLocation(int);
  virtual int GetApproximateLocationCount();
  virtual bool Debug_IsValid();
  virtual void Debug_Draw(idSpawnNode::debugDrawLevel_t);

  idEntityPtr<idEntity> deathTrigger;
  idEntityPtr<idEntity> vehicle;
};

// IDA Local Type ordinal 17689; PDB kind: class.
class __declspec(align(4)) idPlayer::jobMessage_t
{
public:
  idStr message;
  bool complete;
};

// IDA Local Type ordinal 17705; PDB kind: class.
class idPlayer::OfferJob::__l2::idSWFScriptFunction_AcceptJob : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17706.
  virtual ~idSWFScriptFunction_AcceptJob();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idAI2 *ai;
  const idDeclJob *job;
};

// IDA Local Type ordinal 17707; PDB kind: class.
class idPlayer::OfferJob::__l3::idSWFScriptFunction_ReallyAcceptJob : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17708.
  virtual ~idSWFScriptFunction_ReallyAcceptJob();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idAI2 *ai;
  const idDeclJob *job;
};

// IDA Local Type ordinal 17709; PDB kind: class.
class idPlayer::OfferJob::__l4::idSWFScriptFunction_DeclineJob : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17710.
  virtual ~idSWFScriptFunction_DeclineJob();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idAI2 *ai;
  const idDeclJob *job;
};

// IDA Local Type ordinal 17711; PDB kind: class.
class idPlayer::OfferJob::__l5::idSWFScriptFunction_EndInteractionView : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17712.
  virtual ~idSWFScriptFunction_EndInteractionView();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idAI2 *ai;
};

// IDA Local Type ordinal 17713; PDB kind: class.
class idPlayer::OfferJob::__l6::idSWFScriptFunction_GetJobDesc : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17714.
  virtual ~idSWFScriptFunction_GetJobDesc();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  const idDeclJob *job;
};

// IDA Local Type ordinal 17715; PDB kind: class.
class idPlayer::OfferJob::__l7::idSWFScriptFunction_AIAllowsCanCloseGUI : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17716.
  virtual ~idSWFScriptFunction_AIAllowsCanCloseGUI();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idAI2 *ai;
};

// IDA Local Type ordinal 17717; PDB kind: class.
class idPlayer::OfferJob::__l8::idSWFScriptFunction_deactivateBlankCallback : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17718.
  virtual ~idSWFScriptFunction_deactivateBlankCallback();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 17719; PDB kind: class.
class idPlayer::ShowJobBoard::__l2::idSWFScriptFunction_JobBoardSelectJob : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17720.
  virtual ~idSWFScriptFunction_JobBoardSelectJob();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  const idDeclJob *jobDecl;
  idPlayer *player;
};

// IDA Local Type ordinal 17721; PDB kind: class.
class idPlayer::ShowJobBoard::__l3::idSWFScriptFunction_JobBoardDeactivateCallback : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17722.
  virtual ~idSWFScriptFunction_JobBoardDeactivateCallback();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17723; PDB kind: class.
class idPlayer::OfferWares::__l5::idSWFScriptFunction_PlayerInventory_FreeRepair : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17724.
  virtual ~idSWFScriptFunction_PlayerInventory_FreeRepair();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17725; PDB kind: class.
class idPlayer::OfferWares::__l7::idSWFScriptFunction_PlayerCash_get : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17726.
  virtual ~idSWFScriptFunction_PlayerCash_get();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17727; PDB kind: class.
class idPlayer::OfferWares::__l8::idSWFScriptFunction_SwitchCamera : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17728.
  virtual ~idSWFScriptFunction_SwitchCamera();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17729; PDB kind: class.
class idPlayer::OfferWares::__l9::idSWFScriptFunction_PlayerVendorDeactivateCallback : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17730.
  virtual ~idSWFScriptFunction_PlayerVendorDeactivateCallback();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idAI2 *ai;
};

// IDA Local Type ordinal 17731; PDB kind: class.
class idPlayer::OfferWares::__l10::idSWFScriptFunction_PlayerVendor_GetVehicleHeading : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17732.
  virtual ~idSWFScriptFunction_PlayerVendor_GetVehicleHeading();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17733; PDB kind: class.
class idPlayer::OfferWares::__l11::idSWFScriptFunction_PlayerVendor_GetNumVehicles : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17734.
  virtual ~idSWFScriptFunction_PlayerVendor_GetNumVehicles();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17735; PDB kind: class.
class idPlayer::OfferWares::__l12::idSWFScriptFunction_PlayerVendor_ToTuner : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17736.
  virtual ~idSWFScriptFunction_PlayerVendor_ToTuner();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  const aiPlayerInteraction_t *interaction;
  idAI2 *offeringAI;
};

// IDA Local Type ordinal 17737; PDB kind: class.
class idPlayer::LaunchPlayTestGui::__l5::idSWFScriptFunction_PlaytestAvailableModel_Refresh : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17738.
  virtual ~idSWFScriptFunction_PlaytestAvailableModel_Refresh();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idSWFScriptObject *object;
};

// IDA Local Type ordinal 17739; PDB kind: class.
class idPlayer::LaunchPlayTestGui::__l6::idSWFScriptFunction_DoReaction : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17740.
  virtual ~idSWFScriptFunction_DoReaction();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idSWFScriptObject *object;
};

// IDA Local Type ordinal 17741; PDB kind: class.
class idPlayer::LaunchPlayTestGui::__l7::idSWFScriptFunction_ClearPlaytestModel : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17742.
  virtual ~idSWFScriptFunction_ClearPlaytestModel();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idSWFScriptObject *object;
};

// IDA Local Type ordinal 17743; PDB kind: class.
class idPlayer::LaunchPlayTestGui::__l8::idSWFScriptFunction_DoBack : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17744.
  virtual ~idSWFScriptFunction_DoBack();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idSWFScriptObject *object;
};

// IDA Local Type ordinal 17745; PDB kind: class.
class idPlayer::LaunchDebugJobGui::__l7::idSWFScriptFunction_PlayerJobsDebug_Refresh : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17746.
  virtual ~idSWFScriptFunction_PlayerJobsDebug_Refresh();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idSWFScriptObject *object;
};

// IDA Local Type ordinal 17747; PDB kind: class.
class idPlayer::LaunchDebugJobGui::__l3::idSWFScriptFunction_DoClear : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17748.
  virtual ~idSWFScriptFunction_DoClear();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17749; PDB kind: class.
class idPlayer::LaunchDebugJobGui::__l4::idSWFScriptFunction_ShutDownResponse : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17750.
  virtual ~idSWFScriptFunction_ShutDownResponse();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17751; PDB kind: class.
class __declspec(align(4)) idPlayer::ShowInventory::__l23::idSWFScriptFunction_PlayerInventory_Refresh : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17752.
  virtual ~idSWFScriptFunction_PlayerInventory_Refresh();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idSWFScriptObject *inventory;
  idSWFScriptObject *quickInventory;
  bool inVehicle;
};

// IDA Local Type ordinal 17753; PDB kind: class.
class idPlayer::ShowInventory::__l26::idSWFScriptFunction_PlayerWeapons_Refresh : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17754.
  virtual ~idSWFScriptFunction_PlayerWeapons_Refresh();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idSWFScriptObject *object;
};

// IDA Local Type ordinal 17755; PDB kind: class.
class idPlayer::ShowInventory::__l34::idSWFScriptFunction_PlayerJobs_Refresh : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17756.
  virtual ~idSWFScriptFunction_PlayerJobs_Refresh();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idSWFScriptObject *object;
};

// IDA Local Type ordinal 17757; PDB kind: class.
class idPlayer::ShowInventory::__l37::idSWFScriptFunction_PlayerSchematics_Refresh : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17758.
  virtual ~idSWFScriptFunction_PlayerSchematics_Refresh();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idSWFScriptObject *object;
};

// IDA Local Type ordinal 17759; PDB kind: class.
class idPlayer::ShowInventory::__l38::idSWFScriptFunction_PlayerVehicles_Refresh : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17760.
  virtual ~idSWFScriptFunction_PlayerVehicles_Refresh();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idSWFScriptObject *object;
};

// IDA Local Type ordinal 17761; PDB kind: class.
class idPlayer::ShowInventory::__l19::idSWFScriptFunction_CanScrollJobs : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17762.
  virtual ~idSWFScriptFunction_CanScrollJobs();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  int scrollTime;
};

// IDA Local Type ordinal 17763; PDB kind: class.
class idPlayer::ShowInventory::__l20::idSWFScriptFunction_GetScreenFade : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17764.
  virtual ~idSWFScriptFunction_GetScreenFade();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  int startTime;
};

// IDA Local Type ordinal 17765; PDB kind: class.
class idPlayer::ShowInventory::__l21::idSWFScriptFunction_GetShouldScreenFade : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17766.
  virtual ~idSWFScriptFunction_GetShouldScreenFade();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  int startTime;
};

// IDA Local Type ordinal 17767; PDB kind: class.
class idPlayer::ShowInventory::__l22::idSWFScriptFunction_Category_Refresh : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17768.
  virtual ~idSWFScriptFunction_Category_Refresh();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idSWFScriptObject *categories;
};

// IDA Local Type ordinal 17769; PDB kind: class.
class idPlayer::ShowInventory::__l24::idSWFScriptFunction_PlayerUnequipItem : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17770.
  virtual ~idSWFScriptFunction_PlayerUnequipItem();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPresentablePlayer *player;
};

// IDA Local Type ordinal 17771; PDB kind: class.
class idPlayer::ShowInventory::__l25::idSWFScriptFunction_PlayerInventory_AvailQuickSlot : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17772.
  virtual ~idSWFScriptFunction_PlayerInventory_AvailQuickSlot();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17773; PDB kind: class.
class idPlayer::ShowInventory::__l27::idSWFScriptFuntion_PlayerWeapons_EquipWeapon : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17774.
  virtual ~idSWFScriptFuntion_PlayerWeapons_EquipWeapon();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17775; PDB kind: class.
class idPlayer::ShowInventory::__l28::idSWFScriptFuntion_PlayerWeapons_UnequipWeapon : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17776.
  virtual ~idSWFScriptFuntion_PlayerWeapons_UnequipWeapon();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17777; PDB kind: class.
class idPlayer::ShowInventory::__l31::idSWFScriptFunction_GetActiveJob : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17778.
  virtual ~idSWFScriptFunction_GetActiveJob();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17779; PDB kind: class.
class idPlayer::ShowInventory::__l35::idSWFScriptFunction_PlayerInventory_GetCash : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17780.
  virtual ~idSWFScriptFunction_PlayerInventory_GetCash();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17781; PDB kind: class.
class idPlayer::ShowInventory::__l36::idSWFScriptFunction_PlayerInventory_GetVehicleCash : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17782.
  virtual ~idSWFScriptFunction_PlayerInventory_GetVehicleCash();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17783; PDB kind: class.
class idPlayer::ShowInventory::__l39::idSWFScriptFunction_PlayerInventory_Deactivate : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17784.
  virtual ~idSWFScriptFunction_PlayerInventory_Deactivate();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17785; PDB kind: class.
class idPlayer::ShowInventory::__l40::idSWFScriptFunction_PlayerInventory_EquipDeactivate : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17786.
  virtual ~idSWFScriptFunction_PlayerInventory_EquipDeactivate();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idSWF *gui;
};

// IDA Local Type ordinal 17787; PDB kind: class.
class idPlayer::ShowInventory::__l41::idSWFScriptFunction_PlayerInventory_UseDeactivate : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17788.
  virtual ~idSWFScriptFunction_PlayerInventory_UseDeactivate();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idSWF *gui;
};

// IDA Local Type ordinal 17789; PDB kind: class.
class idPlayer::ShowInventory::__l42::idSWFScriptFunction_PlayerInventory_SetInventoryScreen : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17790.
  virtual ~idSWFScriptFunction_PlayerInventory_SetInventoryScreen();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17791; PDB kind: class.
class idPlayer::ShowInventory::__l43::idSWFScriptFunction_PlayerInventory_GetPersonalStats : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17792.
  virtual ~idSWFScriptFunction_PlayerInventory_GetPersonalStats();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idSWFScriptObject *object;
};

// IDA Local Type ordinal 17793; PDB kind: class.
class idPlayer::ShowInventory::__l44::idSWFScriptFunciton_TriggerEntity : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17794.
  virtual ~idSWFScriptFunciton_TriggerEntity();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17795; PDB kind: class.
class idPlayer::TakeViewNotes::__l3::idSWFScriptFunction_TakeViewNotes : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17796.
  virtual ~idSWFScriptFunction_TakeViewNotes();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idStr viewNoteDirectory;
};

// IDA Local Type ordinal 17797; PDB kind: class.
class idPlayer::TakeViewNotes::__l4::idSWFScriptFunction_TakeViewNoteScreenCap : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17798.
  virtual ~idSWFScriptFunction_TakeViewNoteScreenCap();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idStr viewNoteDirectory;
  idStr viewOrientation;
};

// IDA Local Type ordinal 17799; PDB kind: class.
class idPlayer::TakeViewNotes::__l5::idSWFScriptFunction_CloseTakeViewNotes : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17800.
  virtual ~idSWFScriptFunction_CloseTakeViewNotes();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 17801; PDB kind: class.
class idPlayer::TakeViewNotes::__l2::idSWFScriptFunction_WriteScreenCap : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17802.
  virtual ~idSWFScriptFunction_WriteScreenCap();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 17803; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l3::idSWFScriptFunction_PlayerGarage_RefreshQuickItems : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17804.
  virtual ~idSWFScriptFunction_PlayerGarage_RefreshQuickItems();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWFScriptObject *object;
  idPlayer *player;
};

// IDA Local Type ordinal 17805; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l4::idSWFScriptFunction_PlayerGarage_EquipItem : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17806.
  virtual ~idSWFScriptFunction_PlayerGarage_EquipItem();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWFScriptObject *object;
  idPlayer *player;
};

// IDA Local Type ordinal 17807; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l5::idSWFScriptFunction_PlayerGarage_IsItemEquipped : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17808.
  virtual ~idSWFScriptFunction_PlayerGarage_IsItemEquipped();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWFScriptObject *object;
  idPlayer *player;
};

// IDA Local Type ordinal 17809; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l6::idSWFScriptFunction_PlayerGarage_UnequipItem : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17810.
  virtual ~idSWFScriptFunction_PlayerGarage_UnequipItem();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWFScriptObject *object;
  idPlayer *player;
};

// IDA Local Type ordinal 17811; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l7::idSWFScriptFunction_PlayerGarage_ExitGarageToTown : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17812.
  virtual ~idSWFScriptFunction_PlayerGarage_ExitGarageToTown();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idVehicleKey *key;
  idTownGarageCamera *camera;
};

// IDA Local Type ordinal 17813; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l8::idSWFScriptFunction_PlayerGarage_ExitGarageToWasteland : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17814.
  virtual ~idSWFScriptFunction_PlayerGarage_ExitGarageToWasteland();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idVehicleKey *key;
  idTownGarageCamera *camera;
};

// IDA Local Type ordinal 17815; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l9::idSWFScriptFunction_PlayerGarage_PreviousBay : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17816.
  virtual ~idSWFScriptFunction_PlayerGarage_PreviousBay();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idTownGarageCamera *camera;
};

// IDA Local Type ordinal 17817; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l10::idSWFScriptFunction_PlayerGarage_NextBay : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17818.
  virtual ~idSWFScriptFunction_PlayerGarage_NextBay();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idTownGarageCamera *camera;
};

// IDA Local Type ordinal 17819; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l14::idSWFScriptFunction_PlayerGarage_CanRepairVehicle : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17820.
  virtual ~idSWFScriptFunction_PlayerGarage_CanRepairVehicle();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idTownGarageCamera *camera;
};

// IDA Local Type ordinal 17821; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l15::idSWFScriptFunction_PlayerGarage_RepairVehicle : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17822.
  virtual ~idSWFScriptFunction_PlayerGarage_RepairVehicle();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idTownGarageCamera *camera;
};

// IDA Local Type ordinal 17823; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l16::idSWFScriptFunction_PlayerGarage_GetCash : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17824.
  virtual ~idSWFScriptFunction_PlayerGarage_GetCash();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17825; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l17::idSWFScriptFunction_PlayerGarage_GetVehicleDamage : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17826.
  virtual ~idSWFScriptFunction_PlayerGarage_GetVehicleDamage();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idTownGarageCamera *camera;
};

// IDA Local Type ordinal 17827; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l18::idSWFScriptFunction_PlayerGarage_GetVehicleRepairCost : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17828.
  virtual ~idSWFScriptFunction_PlayerGarage_GetVehicleRepairCost();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idTownGarageCamera *camera;
};

// IDA Local Type ordinal 17829; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l19::idSWFScriptFunction_PlayerGarage_CanTune : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17830.
  virtual ~idSWFScriptFunction_PlayerGarage_CanTune();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idTownGarageCamera *camera;
};

// IDA Local Type ordinal 17831; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l20::idSWFScriptFunction_PlayerGarage_GetVehicleName : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17832.
  virtual ~idSWFScriptFunction_PlayerGarage_GetVehicleName();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idTownGarageCamera *camera;
};

// IDA Local Type ordinal 17833; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l21::idSWFScriptFunction_PlayerGarage_GetVehicleClass : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17834.
  virtual ~idSWFScriptFunction_PlayerGarage_GetVehicleClass();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idTownGarageCamera *camera;
};

// IDA Local Type ordinal 17835; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l22::idSWFScriptFunction_PlayerGarage_GetNumTargets : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17836.
  virtual ~idSWFScriptFunction_PlayerGarage_GetNumTargets();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idTownGarageCamera *camera;
};

// IDA Local Type ordinal 17837; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l23::idSWFScriptFunction_PlayerGarage_GetVehiclePrestige : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17838.
  virtual ~idSWFScriptFunction_PlayerGarage_GetVehiclePrestige();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idTownGarageCamera *camera;
};

// IDA Local Type ordinal 17839; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l26::idSWFScriptFunction_PlayerGarage_ZoomToTrophy : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17840.
  virtual ~idSWFScriptFunction_PlayerGarage_ZoomToTrophy();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idTownGarageCamera *camera;
};

// IDA Local Type ordinal 17841; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l27::idSWFScriptFunction_PlayerGarage_ZoomFromTrohpy : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17842.
  virtual ~idSWFScriptFunction_PlayerGarage_ZoomFromTrohpy();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idTownGarageCamera *camera;
};

// IDA Local Type ordinal 17843; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l28::idSWFScriptFunction_PlayerGarage_ToggleCarTrophyView : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17844.
  virtual ~idSWFScriptFunction_PlayerGarage_ToggleCarTrophyView();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idTownGarageCamera *camera;
};

// IDA Local Type ordinal 17845; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l29::idSWFScriptFunction_PlayerGarage_ToggleGarageBlur : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17846.
  virtual ~idSWFScriptFunction_PlayerGarage_ToggleGarageBlur();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17847; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l30::idSWFScriptFunction_PlayerGarage_UpdateSchematic : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17848.
  virtual ~idSWFScriptFunction_PlayerGarage_UpdateSchematic();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17849; PDB kind: class.
class __declspec(align(4)) idPlayer::EnterPersonalGarage::__l31::idSWFScriptFunction_PlayerGarage_ActivateTuner : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17850.
  virtual ~idSWFScriptFunction_PlayerGarage_ActivateTuner();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idTownGarageCamera *camera;
  bool fromGarage;
};

// IDA Local Type ordinal 17851; PDB kind: class.
class idPlayer::EnterPersonalGarage::__l32::idSWFScriptFunction_PlayerGarage_GetNumVehicleKills : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17852.
  virtual ~idSWFScriptFunction_PlayerGarage_GetNumVehicleKills();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idTownGarageCamera *camera;
};

// IDA Local Type ordinal 17853; PDB kind: class.
class idPlayer::ShowVehicleTuner::__l2::idSWFScriptFunction_PlayerGarage_RefreshUpgrades : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17854.
  virtual ~idSWFScriptFunction_PlayerGarage_RefreshUpgrades();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idVehicleKey *key;
  idSWFScriptObject *object;
};

// IDA Local Type ordinal 17855; PDB kind: class.
class idPlayer::ShowVehicleTuner::__l3::idSWFScriptFunction_PlayerGarage_RefreshTypes : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17856.
  virtual ~idSWFScriptFunction_PlayerGarage_RefreshTypes();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idVehicleKey *key;
  idSWFScriptObject *object;
  idPlayer *player;
};

// IDA Local Type ordinal 17857; PDB kind: class.
class idPlayer::ShowVehicleTuner::__l4::idSWFScriptFunction_PlayerGarage_EquipUpgrade : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17858.
  virtual ~idSWFScriptFunction_PlayerGarage_EquipUpgrade();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idVehicleKey *key;
  idSWFScriptObject *object;
  idSWF *gui;
};

// IDA Local Type ordinal 17859; PDB kind: class.
class idPlayer::ShowVehicleTuner::__l5::idSWFScriptFunction_PlayerGarage_ReturnToGarage : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17860.
  virtual ~idSWFScriptFunction_PlayerGarage_ReturnToGarage();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idVehicleKey *key;
  idTownGarageCamera *camera;
};

// IDA Local Type ordinal 17861; PDB kind: class.
class idPlayer::ShowVehicleTuner::__l6::idSWFScriptFunction_PlayerGarage_ReturnToVendor : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17862.
  virtual ~idSWFScriptFunction_PlayerGarage_ReturnToVendor();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  const aiPlayerInteraction_t *interaction;
  idAI2 *offeringAI;
};

// IDA Local Type ordinal 17863; PDB kind: class.
class idPlayer::ShowVehicleTuner::__l7::idSWFScriptFunction_PlayerGarage_TriggerSchematicRender : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17864.
  virtual ~idSWFScriptFunction_PlayerGarage_TriggerSchematicRender();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idVehicleKey *key;
  idPlayer *player;
  bool fromGarage;
  idTownGarageCamera *camera;
};

// IDA Local Type ordinal 17865; PDB kind: class.
class idPlayer::ShowVehicleTuner::__l8::idSWFScriptFunction_PlayerGarage_SelectVehicleComponent : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17866.
  virtual ~idSWFScriptFunction_PlayerGarage_SelectVehicleComponent();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idVehicleKey *key;
  idPlayer *player;
};

// IDA Local Type ordinal 17867; PDB kind: class.
class idPlayer::ShowVehicleTuner::__l9::idSWFScriptFunction_PlayerGarage_KillVehicle : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17868.
  virtual ~idSWFScriptFunction_PlayerGarage_KillVehicle();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idTownGarageCamera *camera;
};

// IDA Local Type ordinal 17869; PDB kind: class.
class idPlayer::ShowVehicleTuner::__l10::idSWFScriptFunction_PlayerGarage_VehicleRating : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17870.
  virtual ~idSWFScriptFunction_PlayerGarage_VehicleRating();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idVehicleKey *key;
};

// IDA Local Type ordinal 17871; PDB kind: class.
class idPlayer::ShowVehicleTuner::__l11::idSWFScriptFunction_PlayerGarage_NeedsRepairToInstall : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17872.
  virtual ~idSWFScriptFunction_PlayerGarage_NeedsRepairToInstall();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idVehicleKey *key;
};

// IDA Local Type ordinal 17873; PDB kind: class.
class idPlayer::ShowVehicleTuner::__l12::idSWFScriptFunction_PlayerGarage_VehicleName : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17874.
  virtual ~idSWFScriptFunction_PlayerGarage_VehicleName();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idVehicleKey *key;
};

// IDA Local Type ordinal 17875; PDB kind: class.
class idPlayer::ShowVehicleTuner::__l13::idSWFScriptFunction_PlayerGarage_CanRepairVehicle : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17876.
  virtual ~idSWFScriptFunction_PlayerGarage_CanRepairVehicle();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idVehicleKey *key;
};

// IDA Local Type ordinal 17877; PDB kind: class.
class idPlayer::ShowVehicleTuner::__l14::idSWFScriptFunction_PlayerGarage_RepairVehicle : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17878.
  virtual ~idSWFScriptFunction_PlayerGarage_RepairVehicle();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idVehicleKey *key;
};

// IDA Local Type ordinal 17879; PDB kind: class.
class idPlayer::ShowVehicleTuner::__l15::idSWFScriptFunction_PlayerGarage_GetCash : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17880.
  virtual ~idSWFScriptFunction_PlayerGarage_GetCash();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
};

// IDA Local Type ordinal 17881; PDB kind: class.
class idPlayer::ShowVehicleTuner::__l16::idSWFScriptFunction_PlayerGarage_GetVehicleDamage : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17882.
  virtual ~idSWFScriptFunction_PlayerGarage_GetVehicleDamage();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idVehicleKey *key;
};

// IDA Local Type ordinal 17883; PDB kind: class.
class idPlayer::ShowVehicleTuner::__l17::idSWFScriptFunction_PlayerGarage_GetVehicleRepairCost : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17884.
  virtual ~idSWFScriptFunction_PlayerGarage_GetVehicleRepairCost();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idVehicleKey *key;
};

// IDA Local Type ordinal 17885; PDB kind: class.
class idPlayer::OfferWares::__l4::idSWFScriptFunction_MerchantInventory_Refresh : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17886.
  virtual ~idSWFScriptFunction_MerchantInventory_Refresh();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idEntityPtr<idAI2> vendor;
  idSWFScriptObject *object;
};

// IDA Local Type ordinal 17887; PDB kind: class.
class idPlayer::OfferWares::__l6::idSWFScriptFunction_PlayerInventory_Refresh : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17888.
  virtual ~idSWFScriptFunction_PlayerInventory_Refresh();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idEntityPtr<idAI2> vendor;
  idSWFScriptObject *object;
};

// IDA Local Type ordinal 18016; PDB kind: class.
class idPlayer::RestartMapForMissionFailure::__l9::idSWFScriptFunction_PlayerInstanceDeath : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18017.
  virtual ~idSWFScriptFunction_PlayerInstanceDeath();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idSWF *gui;
};

// IDA Local Type ordinal 18018; PDB kind: class.
class idPlayer::RestartMapForMissionFailure::__l10::idSWFScriptFunction_ExitToMenu : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18019.
  virtual ~idSWFScriptFunction_ExitToMenu();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 18020; PDB kind: class.
class idPlayer::RestartMapForMissionFailure::__l11::idSWFScriptFunction_setLoadOnly : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18021.
  virtual ~idSWFScriptFunction_setLoadOnly();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 18022; PDB kind: class.
class idPlayer::RestartMapForMissionFailure::__l12::idSWFScriptFunction_loadMostRecent : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18023.
  virtual ~idSWFScriptFunction_loadMostRecent();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 18024; PDB kind: class.
class idPlayer::Killed::__l11::idSWFScriptFunction_PlayerInstanceDeath : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18025.
  virtual ~idSWFScriptFunction_PlayerInstanceDeath();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idSWF *gui;
};

// IDA Local Type ordinal 18026; PDB kind: class.
class idPlayer::Killed::__l12::idSWFScriptFunction_ExitToMenu : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18027.
  virtual ~idSWFScriptFunction_ExitToMenu();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 18028; PDB kind: class.
class idPlayer::Killed::__l27::idSWFScriptFunction_PlayerVehicleDeath : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18029.
  virtual ~idSWFScriptFunction_PlayerVehicleDeath();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayer *player;
  idSWF *gui;
};

// IDA Local Type ordinal 18030; PDB kind: class.
class idPlayer::Killed::__l28::idSWFScriptFunction_ExitToMenu : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18031.
  virtual ~idSWFScriptFunction_ExitToMenu();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 18032; PDB kind: class.
class idPlayer::Killed::__l14::idSWFScriptFunction_loadMostRecent : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18033.
  virtual ~idSWFScriptFunction_loadMostRecent();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 18034; PDB kind: class.
class idPlayer::Killed::__l13::idSWFScriptFunction_setLoadOnly : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18035.
  virtual ~idSWFScriptFunction_setLoadOnly();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 18036; PDB kind: class.
class idPlayer::Killed::__l30::idSWFScriptFunction_loadMostRecent : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18037.
  virtual ~idSWFScriptFunction_loadMostRecent();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 18038; PDB kind: class.
class idPlayer::Killed::__l29::idSWFScriptFunction_setLoadOnly : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18039.
  virtual ~idSWFScriptFunction_setLoadOnly();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 18917; PDB kind: class.
class idMediaPlayer
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18918.
  virtual ~idMediaPlayer();
  virtual void Start();
  virtual void Stop();
  virtual void Pause();
  virtual void Resume();
  virtual void NextSong();
  virtual void PreviousSong();
  virtual void Volume(float);
  virtual int GetCurrentPlaylist();
  virtual void SetCurrentPlaylist(int);

};

// IDA Local Type ordinal 22008; PDB kind: struct.
struct idPlayer::idPlayerVehicleInfo
{
  bool enabled;
  bool enterVehicle;
  idVec3 position;
  idMat3 orientation;
  const idDeclEntityDef *vehicle;
};

// IDA Local Type ordinal 25872; PDB kind: class.
class CCalPlayer : public CCalBase
{
public:
  // Recovered virtual interface; IDA vtable ordinal 25876.
  virtual ~CCalPlayer();
  virtual unsigned int AddRef();
  virtual unsigned int Release();
  virtual HRESULT Lock();
  virtual HRESULT TryLock();
  virtual HRESULT Unlock();
  virtual CCalBase *Enqueue(CCalBase **);
  virtual CCalBase *Dequeue(CCalBase **);
  virtual HRESULT GetHResult();
  virtual CCalBase::MEDIA_TYPE GetMediaType();
  virtual HRESULT Create(CCalDecoder *, CCalRenderer *);
  virtual HRESULT Create_2();
  virtual HRESULT Close();
  virtual HRESULT RegisterNotification(CCalBase::NOTIFICATION_TYPE, void (__fastcall *)(void *), void *);
  virtual HRESULT RegisterNotification_2(CCalBase::NOTIFICATION_TYPE, void (__fastcall *)(void *));
  virtual HRESULT ConnectDecoder(CCalDecoder *);
  virtual HRESULT ConnectRenderer(CCalRenderer *);
  virtual HRESULT ConnectInput(CCalStream *);
  virtual HRESULT DisconnectDecoder();
  virtual HRESULT DisconnectRenderer();
  virtual HRESULT DisconnectInput();
  virtual HRESULT GetMediaInfo(const CCalImageInfo **);
  virtual HRESULT GetMediaInfo_2(const CCalSubInfo **);
  virtual HRESULT GetMediaInfo_3(const CCalVideoInfo **);
  virtual HRESULT GetMediaInfo_4(const CCalAudioInfo **);
  virtual HRESULT Play(CCalBase::PLAY_FLAGS);
  virtual HRESULT Pause();
  virtual HRESULT Resume();
  virtual HRESULT Stop();
  virtual HRESULT Rewind(CCalBase::POSITION);
  virtual HRESULT Seek(unsigned int, unsigned int *);
  virtual HRESULT GetStatus(CCalBase::PLAYER_STATE *, unsigned int *);
  virtual void EndOfFrameCallback();
  virtual void InitializeMemberVariables();
  virtual void WaitForPlayEvent();
  virtual void WaitForEndOfFrameEvent();
  virtual void SetPlayEvent();
  virtual void SetEndOfFrameEvent();
  virtual void ResetPlayEvent();
  virtual CCalBase::PLAYER_STATE GetState();
  virtual CCalBase::PLAYER_FLAGS GetFlags();
  virtual void SetState(CCalBase::PLAYER_STATE);
  virtual void SetFlags(CCalBase::PLAYER_FLAGS);
  virtual void ClearFlags(CCalBase::PLAYER_FLAGS);

  CCalMemoryQueue m_Queue;
  void (__fastcall *m_pfnEndOfFrameNotification)(void *);
  void (__fastcall *m_pfnStateChangeNotification)(void *);
  void *m_pvEndOfFrameContext;
  void *m_pvStateChangeContext;
  _KEVENT m_PlayEvent;
  _KEVENT m_EndOfFrameEvent;
  CCalBase::PLAYER_STATE m_State;
  unsigned int m_ulFlags;
  volatile unsigned int m_ulLockLevel;
  int m_bDecoderOutputConnected;
  int m_bRendererInputConnected;
};
