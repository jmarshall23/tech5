#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\bot\bot_weaponstate.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1262; PDB kind: enum.
enum botWeaponSlots_t : __int32
{
  WEAPON_SLOT_MELEE = 0x0,
  WEAPON_SLOT_PRIMARY = 0x1,
  WEAPON_SLOT_SECONDARY = 0x2,
  WEAPON_SLOT_EXPLOSIVE = 0x3,
  WEAPON_SLOT_MAX = 0x4,
};

// IDA Local Type ordinal 1292; PDB kind: enum.
enum botWeaponCategory_t : __int32
{
  WEAPON_CATEGORY_MELEE = 0x0,
  WEAPON_CATEGORY_SMG = 0x1,
  WEAPON_CATEGORY_SHOTGUN = 0x2,
  WEAPON_CATEGORY_SNIPER = 0x3,
  WEAPON_CATEGORY_THROWN = 0x4,
  WEAPON_CATEGORY_MAX = 0x5,
};

// IDA Local Type ordinal 14980; PDB kind: struct.
struct idBotWeaponState::BotWeaponRequest_t
{
  botWeaponPriority_t weaponPriority;
  botWeaponSlots_t weaponSlot;
  botWeaponFireMode_t weaponFireMode;
  struct idBotWeapon *weaponHandler;
  idStr weaponUserName;
};

// IDA Local Type ordinal 14982; PDB kind: class.
class idBotWeaponState
{
public:
  idBot *owner;
  idBotWeaponState::BotWeaponRequest_t weaponRequests[4];
  idList<idBotWeapon *,5> weapons;
  botWeaponCategory_t currentWeaponCategory;
};
