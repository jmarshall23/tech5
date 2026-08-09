#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\vehicleweapon.h
// Recovered logical types: 7
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1648; PDB kind: enum.
enum vehicleWeaponAnimState_t : __int32
{
  VW_ANIM_NONE = 0x0,
  VW_ANIM_IDLE = 0x1,
  VW_FIRST_WEAPON_CHANGE_ANIM = 0x2,
  VW_ANIM_ENTRY = 0x2,
  VW_ANIM_EXIT = 0x3,
  VW_ANIM_MANNED_IDLE = 0x4,
  VW_ANIM_MANNED_ENTRY = 0x5,
  VW_ANIM_MANNED_EXIT = 0x6,
  VW_ANIM_GUNNER_ENTER = 0x7,
  VW_ANIM_GUNNER_EXIT = 0x8,
  VW_LAST_WEAPON_CHANGE_ANIM = 0x9,
  VW_ANIM_FIRE = 0xA,
  VW_ANIM_MAX = 0xB,
};

// IDA Local Type ordinal 2081; PDB kind: enum.
enum idDeclVehicleWeapon::vehicleWeaponType_t : __int32
{
  VEHICLEWEAPON_NONE = 0x0,
  VEHICLEWEAPON_MG = 0x1,
  VEHICLEWEAPON_MISSILE = 0x2,
  VEHICLEWEAPON_HEAVY_MG = 0x3,
  VEHICLEWEAPON_ROCKET = 0x4,
  VEHICLEWEAPON_NAIL_GUN = 0x5,
  VEHICLEWEAPON_RAIL_GUN = 0x6,
  VEHICLEWEAPON_PULSE_CANNON = 0x7,
  VEHICLEWEAPON_CLUSTER_BOMB = 0x8,
};

// IDA Local Type ordinal 14733; PDB kind: class.
class idVehicleWeapon : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14740.
  virtual idTypeInfo *GetType();
  virtual ~idVehicleWeapon();

  idPresentableVehicle *presentableVehicleCar;
  idVehicle *vehicle;
  idTreeAnimator *treeAnimator;
  idMD6LeafPlay leafPlay;
  idWeapon *weapon;
  idVehicleWeapon *dependentWeapon;
  idMat3 targetAxis;
  idVec3 jointOrigin;
  idMat3 jointMat;
  idVec3 spinJointOrigin;
  idMat3 spinJointMat;
  idIndex<short,enum invalidJointIndex_t> pitchJointIndex;
  idIndex<short,enum invalidJointIndex_t> yawJointIndex;
  idIndex<short,enum invalidJointIndex_t> rollJointIndex;
  idVec3 lastTargetPos;
  idMat3 lastWeaponAxis;
  idAngles targetAngles;
  idHandle<int,enum invalidAttachment_t,-1> attachHandle;
  float rollDelta;
  bool spinupFire;
  bool yawLockedToVehicle;
  int animCount;
  idArray<idVehicleWeapon::animInfo_t,4> animQueue;
  idVehicleWeapon::animInfo_t animState;
  idArray<idVehicleWeapon::animInfo_t,11> animTable;
  int launchDelayTime;
  float rollAngle;
  float maxRollSpeed;
  int firingTime;
  int sequenceFired;
  soundChannel_t fireSoundChannel;
  idPresentablePtr<idPresentable> presentable;
  idPresentablePtr<idPresentable> lastPresentable;
  idVehicleWeapon *remoteFireWeapon;
  int remoteFireTime;
  idPresentablePtr<idPresentable> remoteFireAttacker;
  bool remoteFireLockedOn;
  idPresentablePtr<idPresentable> remoteFireTarget;
  float remoteFireDamageScale;
  float remoteFireAddSpread;
  bool remoteFireInfiniteAmmo;
  idLaserSight laserSight;
  bool hasClearShot;
  idClipQuery deferredWeaponTrace;
};

// IDA Local Type ordinal 14734; PDB kind: struct.
struct __declspec(align(2)) idVehicleWeapon::animInfo_t
{
  vehicleWeaponAnimState_t state;
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> aliasHandle;
  bool looping;
};

// IDA Local Type ordinal 17533; PDB kind: class.
class idVehicle_QuickUseWeapon : public idVehicleQuickItem
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34074.
  virtual idTypeInfo *GetType();
  virtual ~idVehicle_QuickUseWeapon();
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

// IDA Local Type ordinal 18316; PDB kind: struct.
struct idDeclVehicleWeapon::anims_t
{
  idStr idle;
  idStr entry;
  idStr exit;
  idStr fire;
  idStr mannedIdle;
  idStr mannedEntry;
  idStr mannedExit;
  idStr gunnerEnter;
  idStr gunnerExit;
};

// IDA Local Type ordinal 18317; PDB kind: class.
class idDeclVehicleWeapon : public idDeclWeapon
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34110.
  virtual ~idDeclVehicleWeapon();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();
  virtual unsigned int GetDeclTimestamp();
  virtual idDeclInfo *GetDeclInfo();
  virtual bool RebuildTextSource();
  virtual bool SetImplicitText();
  virtual const char *DefaultDefinition();
  virtual void LogMissingDecl();
  virtual void Parse(idParser *);
  virtual void FreeData();
  virtual unsigned int Size();

  idDeclVehicleWeapon::anims_t anims;
  idStr pitchJointName;
  idStr yawJointName;
  idStr spinJointName;
  float spinDir;
  int spinAxis;
  bool isDependent;
  idStr playerSeatWeapon;
  idStr transitionSeat;
  idStr zoomSeat;
  idStr npcSeatWeapon;
  const idSoundShader *switchToSound;
  const idSoundShader *beginFireSound;
  const idSoundShader *endFireSound;
  const idSoundShader *beginDryFireSound;
  const idSoundShader *dryFireSound;
  const idSoundShader *quadFireLoop;
  bool canAttackActors;
  bool useLaserSight;
  idDeclVehicleWeapon *remoteFireWeapon;
  float remoteWeaponDelay;
  bool isRemoteFired;
  float aiMinDelayTimeSecs;
  float aiMaxDelayTimeSecs;
  float aiMinFireTimeSecs;
  float aiMaxFireTimeSecs;
  idAngles minAngles;
  idAngles maxAngles;
  idAngles minAnglesAtWeapon;
  idAngles maxAnglesAtWeapon;
  idAngles aiMinAngles;
  idAngles aiMaxAngles;
  bool playerRotatable;
  float rotateSpeed;
  idVec3 viewOffset;
  idDeclVehicleWeapon::vehicleWeaponType_t vehicleWeaponType;
  float lockAimAssist;
  bool disableHudTarget;
  idVec3 positionOffsetHack;
};
