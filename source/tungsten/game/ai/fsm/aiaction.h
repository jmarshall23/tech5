#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\fsm\aiaction.h
// Recovered logical types: 26
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1549; PDB kind: enum.
enum idAIAction::flag_t : __int32
{
  FLAG_NONE = 0x0,
  FLAG_BLOCKS_SCRIPT = 0x1,
  FLAG_STOPS_MOVEMENT = 0x2,
};

// IDA Local Type ordinal 1603; PDB kind: enum.
enum idAIActionParm::parm_t : __int32
{
  P_NONE = 0x0,
  P_DISCRETE = 0x1,
  P_FLOAT = 0x2,
  P_STRING = 0x3,
  P_DECL = 0x4,
  P_MAX = 0x5,
};

// IDA Local Type ordinal 1605; PDB kind: enum.
enum idAIActionParm::subParm_t : __int32
{
  SP_INTEGER = 0x0,
  SP_BOOL = 0x1,
  SP_ARRIVALACTION = 0x2,
  SP_POSTURE = 0x3,
  SP_COVERACTION = 0x4,
  SP_EQUIPSLOT = 0x5,
  SP_ALERTCYCLE = 0x6,
  SP_FIREMODE = 0x7,
  SP_AIMPOINT = 0x8,
  SP_WALKSTATE = 0x9,
  SP_AIPLAYER = 0xA,
  SP_OVERRIDEANIM = 0xB,
  SP_PAIN = 0xC,
  SP_AIDIRECTION = 0xD,
  SP_DODGEDIR = 0xE,
  SP_SUBWEB = 0xF,
  SP_ACTIONBOOL = 0x10,
  SP_FLOAT = 0x11,
  SP_VEC3 = 0x12,
  SP_ANGLES = 0x13,
  SP_STRING = 0x14,
  SP_ANIM_ALIAS = 0x15,
  SP_ANIM_WEB_NODE = 0x16,
  SP_ENTITY_NAME = 0x17,
  SP_DECL_VOICEOVER = 0x18,
  SP_DECL_SOUND = 0x19,
  SP_DECL_AMMO = 0x1A,
  SP_DECL_WEAPON = 0x1B,
  SP_AIVAROP = 0x1C,
  SP_AIVARTYPE = 0x1D,
  SP_DECL_INVENTORY = 0x1E,
  SP_AIANIMWEB = 0x1F,
  SP_AIACTIONSCRIPTFLAG = 0x20,
  SP_AIPERCEPTIONFLAG = 0x21,
  SP_SITSTATE = 0x22,
  SP_STANDSTATE = 0x23,
  SP_IDLESTATE = 0x24,
  SP_SETMOVEPUSHSTATUS = 0x25,
  SP_AIMOVEMENTMODE = 0x26,
  SP_AIANIMWAIT = 0x27,
  SP_AIIDLETURN = 0x28,
  SP_ACCURACY = 0x29,
  SP_AIMOVEREASON = 0x2A,
  SP_MOVE_TO_SCENEPOINT_FLAGS = 0x2B,
  SP_COMMAND_MOVE = 0x2C,
  SP_MAX = 0x2D,
};

// IDA Local Type ordinal 2380; PDB kind: enum.
enum aiActionBool_t : __int32
{
  AIACTION_FALSE = 0x0,
  AIACTION_TRUE = 0x1,
};

// IDA Local Type ordinal 15691; PDB kind: struct.
struct vaiAction_t::fireAtEnemy_t
{
  idEntityPtr<idEntity> enemy;
  float time;
};

// IDA Local Type ordinal 15692; PDB kind: struct.
struct vaiAction_t::aiGoIdle_t
{
  bool activate;
  bool goIdle;
};

// IDA Local Type ordinal 15693; PDB kind: struct.
struct vaiAction_t::damageEntity_t
{
  idList<idEntityPtr<idEntity>,5> entityList;
  idEntityPtr<idEntity> attacker;
  float damage;
};

// IDA Local Type ordinal 15694; PDB kind: struct.
struct vaiAction_t::throwAttachedItem_t::item_t
{
  idStr name;
  float force;
  idEntityPtr<idEntity> atEntity;
};

// IDA Local Type ordinal 15696; PDB kind: struct.
struct vaiAction_t::throwAttachedItem_t
{
  idList<vaiAction_t::throwAttachedItem_t::item_t,5> itemList;
};

// IDA Local Type ordinal 15697; PDB kind: struct.
struct vaiAction_t::trigger_t
{
  idList<idEntityPtr<idEntity>,5> targetList;
};

// IDA Local Type ordinal 15698; PDB kind: struct.
struct vaiAction_t::occupantLookAt_t
{
  bool driver;
  bool passenger;
  idEntityPtr<idEntity> target;
  float time;
};

// IDA Local Type ordinal 15699; PDB kind: struct.
struct vaiAction_t::forceSteering_t
{
  float time;
  float angle;
  float speed;
};

// IDA Local Type ordinal 15700; PDB kind: struct.
struct vaiAction_t::boostFx_t
{
  float time;
};

// IDA Local Type ordinal 15701; PDB kind: struct.
struct vaiAction_t::vehicleCam_t
{
  bool activate;
  idStr tagName;
  float fwdOfs;
  float rtOfs;
  float upOfs;
};

// IDA Local Type ordinal 15702; PDB kind: struct.
struct vaiAction_t::removeEntity_t
{
  idList<idEntityPtr<idEntity>,5> entityList;
};

// IDA Local Type ordinal 15703; PDB kind: struct.
struct vaiAction_t::allowWeaponChange_t
{
  bool activate;
  bool allowChange;
};

// IDA Local Type ordinal 15704; PDB kind: struct.
struct vaiAction_t::nextWeapon_t
{
  bool activate;
};

// IDA Local Type ordinal 15705; PDB kind: struct.
struct vaiAction_t::vehicleDamageScale_t
{
  idList<idEntityPtr<idEntity>,5> entityList;
  float damageScale;
};

// IDA Local Type ordinal 15706; PDB kind: struct.
struct vaiAction_t::vehicleCollisionDamage_t
{
  idList<idEntityPtr<idEntity>,5> entityList;
  const idDeclDamage *declDamage;
};

// IDA Local Type ordinal 15707; PDB kind: struct.
struct vaiAction_t::vehicleCollisionImpulse_t
{
  idList<idEntityPtr<idEntity>,5> entityList;
  float impulse;
  float verticalImpulse;
};

// IDA Local Type ordinal 15708; PDB kind: struct.
struct vaiAction_t::tireFriction_t
{
  float frontFriction;
  float rearFriction;
  float frictionTime;
};

// IDA Local Type ordinal 15709; PDB kind: struct.
struct vaiAction_t
{
  vaiAction_t::fireAtEnemy_t fireAtEnemy;
  vaiAction_t::aiGoIdle_t aiGoIdle;
  vaiAction_t::damageEntity_t damageEntity;
  vaiAction_t::throwAttachedItem_t throwAttachedItem;
  vaiAction_t::trigger_t trigger;
  vaiAction_t::occupantLookAt_t occupantLookAt;
  vaiAction_t::forceSteering_t forceSteering;
  vaiAction_t::boostFx_t boostFx;
  vaiAction_t::vehicleCam_t vehicleCam;
  vaiAction_t::removeEntity_t removeEntity;
  vaiAction_t::allowWeaponChange_t allowWeaponChange;
  vaiAction_t::nextWeapon_t nextWeapon;
  vaiAction_t::vehicleDamageScale_t vehicleDamageScale;
  vaiAction_t::vehicleCollisionDamage_t vehicleCollisionDamage;
  vaiAction_t::vehicleCollisionImpulse_t vehicleCollisionImpulse;
  vaiAction_t::tireFriction_t tireFriction;
};

// IDA Local Type ordinal 16639; PDB kind: class.
class idAIActionParm
{
public:
  unsigned __int16 type;
  unsigned __int16 subType;
  int intVal;
  idVec3 floatVal;
  const idDecl *declVal;
  idStr strVal;
};

// IDA Local Type ordinal 16998; PDB kind: class.
class idAIAction : public idAIState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17263.
  virtual idTypeInfo *GetType();
  virtual ~idAIAction();
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

// IDA Local Type ordinal 17115; PDB kind: class.
class idAIActionManager : public idFSMManager
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17116.
  virtual idTypeInfo *GetType();
  virtual ~idAIActionManager();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual idFiniteStateMachine *AllocFSM(const idTypeInfo *, const idFiniteStateMachineParams *);
  virtual const idFiniteStateMachine *FindFSM(const idTypeInfo *);
  virtual const idFiniteStateMachine *FindFSM_2(const char *);
  virtual idFiniteStateMachine *FindFSM_3(const idTypeInfo *);
  virtual idFiniteStateMachine *FindFSM_4(const char *);
  virtual void FreeFSM(const idTypeInfo *);
  virtual void FreeFSM_2(const char *);

  idAction_MoveToPoint actionMoveToPoint;
  idAction_MoveToPointNoFail actionMoveToPointNoFail;
  __unaligned __declspec(align(1)) idAction_MoveToEntity actionMoveToEntity;
  __unaligned __declspec(align(1)) idAction_MoveToEntityNoFail actionMoveToEntityNoFail;
  idAction_MoveToPathPoint actionMoveToPathPoint;
  __unaligned __declspec(align(1)) idAction_MoveToPathPointNoFail actionMoveToPathPointNoFail;
  idAction_MoveToCover actionMoveToCover;
  __unaligned __declspec(align(1)) idAction_UseZipline actionUseZipline;
  idAction_SetMovePushStatus actionSetMovePushStatus;
  __unaligned __declspec(align(1)) idAction_Idle actionIdle;
  __unaligned __declspec(align(1)) idAction_Pain actionPain;
  idAction_StandToCrouch actionStandToCrouch;
  idAction_CrouchToStand actionCrouchToStand;
  idAction_PullTriggerRight actionPullTriggerRight;
  __unaligned __declspec(align(1)) idAction_ReleaseTriggerRight actionReleaseTriggerRight;
  idAction_PullTriggerLeft actionPullTriggerLeft;
  __unaligned __declspec(align(1)) idAction_ReleaseTriggerLeft actionReleaseTriggerLeft;
  idAction_ReloadWeapon actionReloadWeapon;
  __unaligned __declspec(align(1)) idAction_ReloadWeaponTorso actionReloadWeaponTorso;
  idAction_WaitForAnim actionWaitForAnim;
  __unaligned __declspec(align(1)) idAction_WaitForAnimVia actionWaitForAnimVia;
  idAction_LoopAnim actionLoopAnim;
  __unaligned __declspec(align(1)) idAction_LoopAnimExitAtEnd actionLoopAnimExitAtEnd;
  idAction_StartAnim actionStartAnim;
  __unaligned __declspec(align(1)) idAction_WaitForTraversalAnim actionWaitForTraversalAnim;
  idAction_ChangeAnimState actionChangeAnimState;
  __unaligned __declspec(align(1)) idAction_ChangeAnimStateVia actionChangeAnimStateVia;
  idAction_ForceAnimState actionForceAnimState;
  __unaligned __declspec(align(1)) idAction_Dodge actionDodge;
  __unaligned __declspec(align(1)) idAction_Wait actionWait;
  idAction_Melee actionMelee;
  __unaligned __declspec(align(1)) idAction_TurnToPoint actionTurnToPoint;
  __unaligned __declspec(align(1)) idAction_TurnToEntity actionTurnToEntity;
  __unaligned __declspec(align(1)) idAction_TurnToEntityWithOffset actionTurnToEntityWithOffset;
  __unaligned __declspec(align(1)) idAction_Dive actionDive;
  idAction_LeapAttack actionLeapAttack;
  __unaligned __declspec(align(1)) idAction_WaitForEntity actionWaitForEntity;
  idAction_EnterVehicle actionEnterVehicle;
  __unaligned __declspec(align(1)) idAction_PlayVoiceOver actionPlayVoiceOver;
  __unaligned __declspec(align(1)) idAction_StopVoiceOver actionStopVoiceOver;
  idAction_PlayInteractionVoiceOver actionPlayInteractionVoiceOver;
  idAction_PlayOverrideAnim actionPlayOverrideAnim;
  __unaligned __declspec(align(1)) idAction_PlayOverrideAnimInterrupt actionPlayOverrideAnimInterrupt;
  idAction_DrawWeapon actionDrawWeapon;
  __unaligned __declspec(align(1)) idAction_HolsterWeapon actionHolsterWeapon;
  idAction_PerformCoverAction actionPerformCoverAction;
  __unaligned __declspec(align(1)) idAction_WaitForPlayerInteraction actionWaitForPlayerInteraction;
  __unaligned __declspec(align(1)) idAction_WaitForAIVar actionWaitForAIVar;
  idAction_PerfectMovement actionPerfectMovement;
  idAction_SetAlertCycle actionSetAlertCycle;
  __unaligned __declspec(align(1)) idAction_SetFocus actionSetFocus;
  idAction_ClearLookFocus actionClearLookFocus;
  __unaligned __declspec(align(1)) idAction_ClearAimFocus actionClearAimFocus;
  idAction_SetAimPoint actionSetAimPoint;
  __unaligned __declspec(align(1)) idAction_SetFireMode actionSetFireMode;
  idAction_SetScriptAbort actionSetScriptAbort;
  __unaligned __declspec(align(1)) idAction_SetPosture actionSetPosture;
  idAction_SetWalkState actionSetWalkState;
  __unaligned __declspec(align(1)) idAction_SetSitState actionSetSitState;
  idAction_SetStandState actionSetStandState;
  __unaligned __declspec(align(1)) idAction_SetIdleState actionSetIdleState;
  idAction_SetPlayerEnemy actionSetPlayerEnemy;
  __unaligned __declspec(align(1)) idAction_SetEnemy actionSetEnemy;
  idAction_SearchToTarget actionSearchToTarget;
  __unaligned __declspec(align(1)) idAction_SetPlayerFocus actionSetPlayerFocus;
  idAction_SetActionNodeGroup actionSetActionNodeGroup;
  __unaligned __declspec(align(1)) idAction_Trigger actionTrigger;
  idAction_EnableDamage actionEnableDamage;
  __unaligned __declspec(align(1)) idAction_EnablePain actionEnablePain;
  idAction_EnableAutoFocus actionEnableAutoFocus;
  __unaligned __declspec(align(1)) idAction_EnableBodyRotation actionEnableBodyRotation;
  idAction_EnableWalkIK actionEnableWalkIK;
  __unaligned __declspec(align(1)) idAction_EnableHeadTracking actionEnableHeadTracking;
  idAction_ForceOpenCombat actionForceOpenCombat;
  __unaligned __declspec(align(1)) idAction_ForceAwarenessByDistance actionForceAwarenessByDistance;
  idAction_ForcePlayerInteraction actionForcePlayerInteraction;
  __unaligned __declspec(align(1)) idAction_SetAIVar actionSetAIVar;
  idAction_SetScriptFlag actionSetScriptFlag;
  __unaligned __declspec(align(1)) idAction_ClearScriptFlag actionClearScriptFlag;
  idAction_SetPerceptionFlag actionSetPerceptionFlag;
  __unaligned __declspec(align(1)) idAction_ClearPerceptionFlag actionClearPerceptionFlag;
  idAction_IgnorePlayerApproach actionIgnorePlayerApproach;
  __unaligned __declspec(align(1)) idAction_NoticePlayerApproach actionNoticePlayerApproach;
  idAction_SetSubWeb actionSetSubWeb;
  __unaligned __declspec(align(1)) idAction_GiveItem actionGiveItem;
  idAction_TakeItem actionTakeItem;
  __unaligned __declspec(align(1)) idAction_ClearWorldState actionClearWorldState;
  idAction_ShowAttachment actionShowAttachment;
  __unaligned __declspec(align(1)) idAction_HideAttachment actionHideAttachment;
  idAction_DropAttachment actionDropAttachment;
  __unaligned __declspec(align(1)) idAction_SetMoveMode actionSetMoveMode;
  idAction_SetAccuracy actionSetAccuracy;
  __unaligned __declspec(align(1)) idAction_ScriptedAnimWeb actionScriptedAnimWeb;
  __unaligned __declspec(align(1)) idAction_MoveToScenePoint actionMoveToScenePoint;
  idLegsFSM legsFSM;
  idList<idAIAction *,5> actionStates;
  idHashTableT<int,idAIAction *> actionsHash;
  int actionEventTransCode;
};

// IDA Local Type ordinal 21499; PDB kind: class.
class __declspec(align(4)) idAIActionParm::idSubParmInfo
{
public:
  const char *typeName;
  const char *mediaFilter;
  idAIActionParm::parm_t parmType;
  bool isEnum;
};
