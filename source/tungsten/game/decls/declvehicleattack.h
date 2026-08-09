#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declvehicleattack.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2035; PDB kind: enum.
enum vehicleAttack_t : __int32
{
  ATTACK_IDLE = 0x0,
  ATTACK_RAM_ENEMY = 0x1,
  ATTACK_RANGE_SHOOT = 0x2,
  ATTACK_STRAFE_SHOOT = 0x3,
  ATTACK_CIRCLE_SHOOT = 0x4,
  ATTACK_CHASE_REAR_BUMP = 0x5,
  ATTACK_CHASE_SIDE_BUMP = 0x6,
  ATTACK_CHASE_SHOOT = 0x7,
  ATTACK_CHASE_SIDE_SHOOT = 0x8,
  ATTACK_CHASE_BYPASS = 0x9,
  ATTACK_HITANDRUN = 0xA,
  ATTACK_WAYPOINT_TAG = 0xB,
  ATTACK_FIRE_WEAPON = 0xC,
  ATTACK_RANDOM_FOLLOW = 0xD,
  ATTACK_CHASE_POWERTURN_SHOOT = 0xE,
  ATTACK_RC_BOMB_OUTSIDE = 0xF,
  ATTACK_RC_BOMB_RACE = 0x10,
  ATTACK_RC_BOMB_INSIDE = 0x11,
  ATTACK_FREE_FORM = 0x12,
  ATTACK_MP_STOP = 0x13,
  ATTACK_MP_RAM = 0x14,
  ATTACK_MP_CHASE = 0x15,
  ATTACK_MP_PICKUP_ITEM = 0x16,
  ATTACK_MP_REPAIR_STATION = 0x17,
  ATTACK_MP_CTF_CAPTURE_FLAG = 0x18,
  ATTACK_MP_CTF_DEFEND_BASE = 0x19,
  ATTACK_MP_CTF_ENEMY_FLAG_TO_BASE = 0x1A,
  ATTACK_MP_CTF_DEFEND_TEAMMATE = 0x1B,
  ATTACK_MP_CTF_FIND_LOST_FLAG = 0x1C,
  ATTACK_MP_CTF_GET_FLAG_FROM_ENEMY = 0x1D,
  ATTACK_NONE = 0x1E,
};

// IDA Local Type ordinal 15637; PDB kind: class.
class idDeclVehicleAttack : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15638.
  virtual ~idDeclVehicleAttack();
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

  vehicleAttack_t state;
  vehicleAttackParams_t params;
};
