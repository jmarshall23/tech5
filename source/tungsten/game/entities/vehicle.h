#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\vehicle.h
// Recovered logical types: 19
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1219; PDB kind: enum.
enum vehicleSeat_t : __int32
{
  SEAT_DRIVER = 0x0,
  SEAT_GUNNER = 0x1,
  SEAT_MAX = 0x2,
};

// IDA Local Type ordinal 1644; PDB kind: enum.
enum vehicleType_t : __int32
{
  VEHICLE_TYPE_NONE = 0x0,
  VEHICLE_TYPE_BUGGY = 0x1,
  VEHICLE_TYPE_MONARCH = 0x2,
  VEHICLE_TYPE_CUPRINO = 0x3,
  VEHICLE_TYPE_REGIME = 0x4,
  VEHICLE_TYPE_ALL = 0x5,
  VEHICLE_TYPE_MAX = 0x6,
};

// IDA Local Type ordinal 1665; PDB kind: enum.
typedef idAIScriptedAnimWeb::stateMarker_t idVehicle::animStateMarker_t;

// IDA Local Type ordinal 14636; PDB kind: class.
class idVehicle : public idAnimatedEntity
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34079.
  virtual idTypeInfo *GetType();
  virtual ~idVehicle();
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
  virtual void Respawn();
  virtual bool EnterVehicle(idEntity *, vehicleSeat_t);
  virtual bool ExitVehicle(int, bool, bool);
  virtual float GetMaxSpeed();
  virtual float GetMaxReverseSpeed();
  virtual void UseAiProperties(bool);
  virtual void UpdateDriverViewAngles(const usercmd_t *, const usercmd_t *);
  virtual void InventoryAdded_Server(idInventoryItem *, int);
  virtual idEntity *ThrowAttachedItem(idInventoryItem *);
  virtual float GetHealth();
  virtual void SetHealth(const float);
  virtual float GetMaxHealth();
  virtual void SetMaxHealth(const float);
  virtual bool IncreaseHealth(const float);
  virtual bool ZoomIn();
  virtual bool ZoomOut();

  int lastDrawTime;
  idList<detachable_t,5> detachableItemsBaseList;
  idStaticList<detachable_t,70> detachableItems;
  vehicleMaterialTheme_t materialTheme;
  idStr normalSkin;
  vehicleClass_t vehicleClass;
  int respawnInGarageTime;
  bool allowWeaponChange;
  const idDeclInventory *inventoryItem;
  float collisionImpulse;
  float collisionVerticalImpulse;
  int lastAiDifficultyRating;
  idList<idVehicle::eventAnimEntry_t,5> eventAnimList;
  idStaticList<idVehicle::itemSkinRef_t,50> itemSkinList;
  bool isUsable;
  idList<idVehicle::seatInfo_t,5> seatInfo;
  idStr forceEntryTagName;
  tagData_t forceEntryTagData;
  idStr driverName;
  idEntityPtr<idEntity> cachedPlayerDriver;
  const idDeclInventory *keys;
  idVehicleKey *playerKey;
  __unaligned __declspec(align(1)) idVehicleKey tempPlayerKey;
  idList<idVehicle::playerRewardForKilling_t,5> playerRewardsForKilling;
  idEntityPtr<idEntity> targetToActivateOnDeath;
  idList<idInventoryAttachmentDef,5> startingInventory;
  const idDeclVehicleUpgrade *tiresSpiked;
  const idDeclVehicleUpgrade *tiresUpgraded;
  const idDeclVehicleUpgrade *tiresUpgradedSpiked;
  float damageAiSpeed;
  bool provideDynamicCover;
  const idMaterial *enterIcon;
  idList<idDeclWeapon const *,5> startingWeapons;
  bool hasInfiniteAmmo;
  idAttachmentCollection attachments;
  vehicleClan_t vehicleClan;
  float health;
  float maxHealth;
  float mpMaxHealth;
  float healthScaledDamage;
  float overallDamageScale;
  float maxArmoredHealth;
  bool lastMaxArmoredHealthFromKey;
  damageInfo_t lastDamage;
  idArray<idVec3,8> aiTargetPos;
  const idDeclEntityDef *armorPropDef;
  const idDeclEntityDef *occupantDef;
  const idDeclEntityDef *passengerOccupantDef;
  bool allowExit;
  bool giveRewardWhenKilled;
  const idDeclInventory *alternateEngine;
  int spikeDetachableFound;
  idArray<int,4> spikeDetachableIndex;
  idAngles freeAngles;
  idAngles currentViewAngles;
  idAngles lastCarAngles;
  idAngles minDriverViewAngles;
  idAngles maxDriverViewAngles;
  int wildSpinTime;
  float viewAnglesDeltaPerc;
  int quickTurnLastPressed;
  int quickTurnTotalTime;
  int quickTurnStartTime;
  bool quickTurnActive;
  int quickTurnDir;
  int quickTurnLastSteerDir;
  idAngles driverViewAngles;
  idList<idEntityPtr<idEntity>,5> touching;
  const idDeclAiEvent *attachedEventDecl[2];
  idHandle<int,enum invalidAIEvent_t,-1> eventHandles[2];
  bool removeWhenDead;
  idLinkList<idVehicle> controlNode;
  float rolloverForce;
  idEntityPtr<idEntity> collisionDamageAttacker;
  const idDeclDamage *collisionDamage;
  int collisionDamageTime;
  bool allowAmmoTransfer;
  bool allowQuickItemTransfer;
  const idDeclVehicleProps *vehicleProps;
  bool cleanUpVehicleProps;
  const idDeclVehicleDecalDamage *vehicleDecalDamage;
  const idDeclVehicleWindowKit *vehicleWindowKit;
  idVehicleWindow vehicleWindow;
  float exitVehicleZDelta;
  float zoom_fov_x;
  idHandle<int,enum invalidInfluenceTrail_t,-1> influenceTrail;
  idAnimator_VehicleCar vehicleAnimator;
  idAnimator_Channel eventAnimator;
  idAnimator_Channel eventAnimatorHands;
  idAnimator_Channel eventAnimatorLegs;
  idVehicleCoverMgr vehicleCover;
  idVehicle::eventAnimSupport_t eventAnimSupport;
  bool exitButtonDownOnEnter;
  const idDeclRenderParm *rp_modelAngles;
  float windowMovement;
  float windowMovementScale;
};

// IDA Local Type ordinal 14674; PDB kind: struct.
struct __declspec(align(4)) idVehicle::eventAnimEntry_t
{
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> animationHandle;
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> animationHandleHands;
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> animationHandleLegs;
  idVehicleOccupant *legsOccupantDummy;
  idAnimAliasRef animation;
  idAnimAliasRef animationHands;
  idAnimAliasRef animationLegs;
  idEntityPtr<idEntity> perfectOriginRef;
  idList<idEntityPtr<idEntity>,5> triggerEnter;
  idList<idEntityPtr<idEntity>,5> triggerLeave;
  idAtomicString cameraJoint;
  const idDeclMD6 *handsModelDecl;
  const idDeclMD6 *legsModelDecl;
  const idDeclEntityDef *legsDummyDef;
  int jumpToState;
  int blendTime;
  unsigned __int8 : 4;
  __int8 turnOffPhysics : 1;
  __int8 loop : 1;
  __int8 useDeltaMovement : 1;
  __int8 useAnimationOrigin : 1;
};

// IDA Local Type ordinal 14676; PDB kind: struct.
struct idVehicle::itemSkinRef_t
{
  const idDeclInventory *declInventory;
  const idDeclSkins *declSkin;
};

// IDA Local Type ordinal 14680; PDB kind: struct.
struct idVehicle::seatInfo_t
{
  idStr tagName;
  idRenderModel *model;
  bool weaponAttach;
  bool playerCanOccupy;
  bool isEasilyThrown;
  bool isFake;
  idList<idEntityPtr<idEntity>,5> enterAnim;
  idStr enterViaAnimRefStr;
  idStr enterDstAnimRefStr;
  idList<idEntityPtr<idEntity>,5> exitAnim;
  idStr exitViaAnimRefStr;
  idStr exitDstAnimRefStr;
  idEntityPtr<idEntity> exitSnapToEntity;
  bool exitHideEntity;
  idEntityPtr<idVehicleOccupant> vehicleOccupant;
};

// IDA Local Type ordinal 14687; PDB kind: struct.
struct idVehicleKey::armorInfo_t
{
  const idDeclInventory *decl;
  float health;
};

// IDA Local Type ordinal 14690; PDB kind: class.
class idVehicleKey : public idInventoryItem
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34063.
  virtual idTypeInfo *GetType();
  virtual ~idVehicleKey();
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

  bool initArmorFromVehicle;
  bool doTotalRepairOnSpawn;
  float repairCost;
  float health;
  float maxHealth;
  prestige_t prestige;
  performanceStats_t performanceStats;
  bool upgradeAvailable;
  idList<idDeclVehicleUpgrade const *,5> equippedUpgrades;
  int currentWeaponGroup;
  int numVehicleKills;
  idList<idList<idDeclVehicleUpgrade const *,5>,5> validUpgrades;
  idList<idDeclVehicleUpgrade const *,5> baseParts;
  garageList_t vehicleGarage;
  bool enterVehicle;
  bool shouldGarageView;
  idVec3 position;
  idMat3 orientation;
  idStr referenceVehicleName;
  idEntityPtr<idEntity> garageBay;
  idStaticList<idVehicleKey::armorInfo_t,50> armorInfo;
  idStaticList<idVehicleKey::armorInfo_t,50> upgradedArmorList;
};

// IDA Local Type ordinal 14691; PDB kind: struct.
struct idVehicle::playerRewardForKilling_t
{
  const idDeclInventory *reward;
  const idDeclJob *job;
};

// IDA Local Type ordinal 14731; PDB kind: struct.
struct idVehicle::eventAnimSupport_t
{
  idQuat orgRotation;
  idVec3 orgOrigin;
  idQuat nextRotation;
  idVec3 nextOrigin;
  int animStartFrame;
  int animUpdatedFrame;
  int currentState;
  int queuedAnimState;
  int queuedBlendTime;
  idList<int,5> prevContents;
  idList<int,5> prevClipMasks;
  idList<int,5> prevWheelClipMasks;
};

// IDA Local Type ordinal 15982; PDB kind: struct.
struct idVehicle_Car::vquInfo_t
{
  int numActive;
  int deactivateTime;
};

// IDA Local Type ordinal 15983; PDB kind: struct.
struct idVehicle_Car::vehicleSoundState_t
{
  bool engineRunning;
  int nextZoomTime;
  int nextBackfireTime;
  int nextBurpTime;
  bool isCruising;
  int fadeMusicTime;
};

// IDA Local Type ordinal 15984; PDB kind: struct.
struct idVehicle_Car::vehicleDamage_t
{
  const idDeclDamage *vehicle;
  const idDeclDamage *runOver;
  const idDeclDamage *world;
  const idDeclDamage *prop;
  const idDeclDamage *explode;
  const idDeclDamage *fire;
  const idDeclDamage *rcbombDecl;
  const idDeclDamage *rcbombSplashDecl;
  const idDeclDamage *spikeDamage;
  const idDeclDamage *collisionDeathDecl;
};

// IDA Local Type ordinal 15985; PDB kind: struct.
struct idVehicle_Car::vehicleHitData_t
{
  idEntityPtr<idVehicle_Car> otherCar;
  int nextCollisionTime;
};

// IDA Local Type ordinal 15987; PDB kind: class.
class idVehicle_Car : public idVehicle
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34138.
  virtual idTypeInfo *GetType();
  virtual ~idVehicle_Car();
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
  virtual void Respawn();
  virtual bool EnterVehicle(idEntity *, vehicleSeat_t);
  virtual bool ExitVehicle(int, bool, bool);
  virtual float GetMaxSpeed();
  virtual float GetMaxReverseSpeed();
  virtual void UseAiProperties(bool);
  virtual void UpdateDriverViewAngles(const usercmd_t *, const usercmd_t *);
  virtual void InventoryAdded_Server(idInventoryItem *, int);
  virtual idEntity *ThrowAttachedItem(idInventoryItem *);
  virtual float GetHealth();
  virtual void SetHealth(const float);
  virtual float GetMaxHealth();
  virtual void SetMaxHealth(const float);
  virtual bool IncreaseHealth(const float);
  virtual bool ZoomIn();
  virtual bool ZoomOut();

  idStrId voiceOverNameString;
  int damageSandwichFunTime[2];
  idVehicle_Car::aiProperties_t aiProperties;
  idVehicle_Car::aiProperties_t savedProperties;
  bool savedPropertiesUpdated;
  bool isWasteland2;
  idVec3 baseCOG;
  int frictionOverrideTime;
  float frictionOverrideFront;
  float frictionOverrideRear;
  idVehicle_Car::vquInfo_t vquInfo[11];
  idEntityPtr<idEntity> enterTarget;
  int ghostEndTime;
  int pitStartTime;
  idEntity *pitLastEntity;
  idVec3 lastOrigin;
  float magnetRange;
  float previousCompression;
  idVehicle_Car::vehicleSoundState_t soundState;
  bool hideSteeringWheel;
  bool dropItemsWhenKilled;
  bool ghostCollision;
  const idDeclEntityDef *boostItem;
  const idDeclEntityDef *ammoItem;
  const idDeclEntityDef *healthItem;
  idVehicle_Car::vehicleDamage_t damages;
  bool playerWasOccupant;
  int attackOverTime;
  const idDeclEntityDef *rcBombDropItem;
  const idDeclAiEvent *vehicleSoundEventDecl;
  const idDeclAiEvent *explosionEventDecl;
  idEntityPtr<idEntity> cinimaticViewPoint;
  bool reducedRCFadeBack;
  int savedSurfaceType;
  bool canBePitted;
  bool specialDeathActive;
  int specialDeathStartTime;
  bool destroyed;
  bool specialDeathCollision;
  specialDeath_t specialDeath;
  idEntityPtr<idEntity> specialDeathAttacker;
  bool forceInstantDeath;
  idStr callOnCollision;
  const idDeclVehicleUnlock *equippedUnlocks[6];
  vehicleType_t vehicleType;
  idVehicle_Megabooster boostpad;
  int boostlevel;
  int movePlayerToVehicle;
  idAngles cameraBreath;
  idAngles cameraBreathPrev;
  int cameraBreathNextUpdate;
  float lastThinkHealth;
  float constantCollisionScale;
  idList<idVehicle_Car::vehicleHitData_t,5> hitList;
  bool droppedByPlayer;
  idEntityPtr<idPlayer> controllingPlayer;
  idLinkList<idVehicle_Car> rcControlNode;
};

// IDA Local Type ordinal 17521; PDB kind: class.
class idVehicle_Jump : public idVehicleQuickItem
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34072.
  virtual idTypeInfo *GetType();
  virtual ~idVehicle_Jump();
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
  virtual bool Use(idPresentableVehicle *);
  virtual void Think(idPresentable *);
  virtual void Think();
  virtual void VehicleDied();
  virtual int GetCooldown();

};

// IDA Local Type ordinal 17539; PDB kind: class.
class idVehicle_EMP : public idVehicleQuickItem
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34069.
  virtual idTypeInfo *GetType();
  virtual ~idVehicle_EMP();
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
  virtual bool Use(idPresentableVehicle *);
  virtual void Think(idPresentable *);
  virtual void Think();
  virtual void VehicleDied();
  virtual int GetCooldown();

};

// IDA Local Type ordinal 18919; PDB kind: struct.
struct idVehicle::SetExitPosition::__l2::exit_spots
{
  idVec2 pos;
  vehicleSeat_t seat;
};
