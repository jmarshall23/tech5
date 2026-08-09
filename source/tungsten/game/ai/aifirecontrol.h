#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aifirecontrol.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17118; PDB kind: class.
class __declspec(align(4)) idAIFireControl : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17120.
  virtual idTypeInfo *GetType();
  virtual ~idAIFireControl();
  virtual void DormantEnd(const int);
  virtual int GetNextPullTriggerTime(const idWeapon *);
  virtual void ResetNextPullTriggerTime(idAI2 *);
  virtual void Update_Weapon(idAI2 *, const int);
  virtual void Update_HoldFire(idAI2 *, const int);
  virtual void Update_FireWhenReady(idAI2 *, const int);
  virtual void Update_SprayWhenReady(idAI2 *, const int);
  virtual int NumWeaponInfos();
  virtual const idAIFireControl::weaponInfo_t *GetWeaponInfo(const int);
  virtual bool CanFireWeapons(idAI2 *, const idAIEntityState *, const int);
  virtual void SetNextPullTriggerTime(const idWeapon *, const int);
  virtual void SetEndBurstTime(const idWeapon *, const int);
  virtual int GetEndBurstTime(const idWeapon *);
  virtual void SetFireAtLastKnownDuration(const idWeapon *, const int);
  virtual int GetFireAtLastKnownDuration(const idWeapon *);

  aiFireMode_t fireMode;
  bool freeAmmo;
  bool allowReloads;
};

// IDA Local Type ordinal 17119; PDB kind: struct.
const struct idAIFireControl::weaponInfo_t
{
  equipSlot_t slot;
};

// IDA Local Type ordinal 21466; PDB kind: struct.
struct idAIFireControl_Human::fcWeaponState_t
{
  int nextPullTriggerTime;
  int endBurstTime;
  int fireAtLastKnownDuration;
};

// IDA Local Type ordinal 21467; PDB kind: class.
class idAIFireControl_Human : public idAIFireControl
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21468.
  virtual idTypeInfo *GetType();
  virtual ~idAIFireControl_Human();
  virtual void DormantEnd(const int);
  virtual int GetNextPullTriggerTime(const idWeapon *);
  virtual void ResetNextPullTriggerTime(idAI2 *);
  virtual void Update_Weapon(idAI2 *, const int);
  virtual void Update_HoldFire(idAI2 *, const int);
  virtual void Update_FireWhenReady(idAI2 *, const int);
  virtual void Update_SprayWhenReady(idAI2 *, const int);
  virtual int NumWeaponInfos();
  virtual const idAIFireControl::weaponInfo_t *GetWeaponInfo(const int);
  virtual bool CanFireWeapons(idAI2 *, const idAIEntityState *, const int);
  virtual void SetNextPullTriggerTime(const idWeapon *, const int);
  virtual void SetEndBurstTime(const idWeapon *, const int);
  virtual int GetEndBurstTime(const idWeapon *);
  virtual void SetFireAtLastKnownDuration(const idWeapon *, const int);
  virtual int GetFireAtLastKnownDuration(const idWeapon *);

  idAIFireControl_Human::fcWeaponState_t weaponStates[2];
};
