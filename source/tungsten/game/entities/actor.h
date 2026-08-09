#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\actor.h
// Recovered logical types: 9
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14220; PDB kind: class.
class __declspec(align(8)) idActor : public idAnimatedEntity
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15260.
  virtual idTypeInfo *GetType();
  virtual ~idActor();
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

  bool looted;
  idEntityPtr<idEntity> droppedItem1;
  idEntityPtr<idEntity> droppedItem2;
  idEntityPtr<idEntity> attachedLoot;
  idEngagementTracker engagementTracker;
  bool spawnPending;
  idDeferredVisGrid deferredVisGrid;
  idAnimator_AF afProperties;
  idActor::idActorConstant actorConstants;
  idRagdollInfo ragdollInfo;
  idActor::idActorEditable actorEditable;
  idStrId npcName;
  idFaction faction;
  const idDeclFaction *tempFaction;
  int tempFactionTime;
  actorFactionType factionType;
  float weaponProficiency;
  float armorProficiency;
  float shieldBleedThrough;
  float mass;
  bool lootable;
  bool dropRandomLoot;
  idList<idInventoryAttachmentDef,5> startingInventory;
  idList<idEntityAttachmentDef,5> entityAttachments;
  idDisassembleLoot disassembleLoot;
  idSmartLootComponentActor smartLoot;
  takedownTypes_t takedownTypes;
  idActor::idActorVolatile actorVolatile;
  idAnimator_WalkIK walkIK;
  const idDeclWalkIK *walkIKDecl;
  idInventoryItem *equipped[15];
  idAttachmentCollection attachments;
  idLinkList<idActor> actorNode;
  idInventoryCollection inventory;
  int damageGroup;
  idList<idEntityPtr<idEntity>,5> touching;
  idActorPhysicsCallbacks actorPhysicsCallbacks;
};

// IDA Local Type ordinal 15225; PDB kind: class.
class idActor::idActorConstant::idActorModel
{
public:
  idStr soundJoint;
  idVec3 modelOffset;
};

// IDA Local Type ordinal 15226; PDB kind: class.
class idActor::idActorConstant::idActorPerception
{
public:
  idVec3 eyeOffset;
  idVec3 crouchedEyeOffset;
};

// IDA Local Type ordinal 15230; PDB kind: struct.
struct idActor::idActorConstant::waterInteraction_t
{
  const idDeclParticle *waterPrtSlow;
  const idDeclParticle *waterPrtFast;
  const idDeclParticle *waterPrtSplash;
  float moveSpeedSlow;
  float emissionRate;
};

// IDA Local Type ordinal 15231; PDB kind: class.
class idActor::idActorConstant
{
public:
  idActor::idActorConstant::idActorModel modelInfo;
  idActor::idActorConstant::idActorPerception perception;
  idActorSounds actorSounds;
  bool useCombatBox;
  const idDeclProjectileImpactEffect *footstepEffectTable_Sprint;
  const idDeclProjectileImpactEffect *footstepEffectTable;
  const idDeclProjectileImpactEffect *footstepEffectTable_SlowWalk;
  const idDeclProjectileImpactEffect *footstepEffectTable_CrouchWalk;
  const idDeclProjectileImpactEffect *footstepEffectTable_Landing;
  const idDeclFootstepEvents *footstepEvents;
  idActor::idActorConstant::waterInteraction_t waterInteraction;
  actorClass_t actorClass;
  float aimAssistRadiusOverrideScale;
};

// IDA Local Type ordinal 15236; PDB kind: struct.
struct idActor::idActorEditable
{
  posture_t bodyState;
  standState_t standState;
  sitState_t sitState;
  turnState_t turnState;
  mentalState_t mentalState;
  bool forceBodyState;
  bool isInteracting;
  idList<idDamageGroup,5> damageGroups;
  idList<idStr,5> radiusDamageJoints;
};

// IDA Local Type ordinal 15246; PDB kind: struct.
struct __declspec(align(4)) idActor::idActorVolatile::idActorModelCache
{
  idMat3 modelAxis;
  idMat3 eyeAxis;
  idVec3 eyePos;
  idIndex<short,enum invalidJointIndex_t> soundJoint;
};

// IDA Local Type ordinal 15247; PDB kind: struct.
struct idActor::idActorVolatile::idPainInfo
{
  idHandle<int,enum invalidJointGroupHandle,0> jointGroupHandle;
  idEntityPtr<idEntity const > attacker;
  idEntityPtr<idEntity const > inflictor;
  idIndex<short,enum invalidJointIndex_t> joint;
  painType_t type;
  damageDirection_t direction;
  damageIntensity_t intensity;
  const idDeclDamage *damageDecl;
};

// IDA Local Type ordinal 15248; PDB kind: struct.
struct idActor::idActorVolatile
{
  idActor::idActorVolatile::idActorModelCache modelInfo;
  idActor::idActorVolatile::idPainInfo pain;
  walkState_t walkState;
  leanState_t leanState;
  weaponReadyState_t weaponReadyState;
  bool onStairs;
  int postureChangeTime;
  float damageTakenMultiplier;
  idAASPosition aasPosition;
};
