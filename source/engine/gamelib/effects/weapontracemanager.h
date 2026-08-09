#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\effects\weapontracemanager.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1836; PDB kind: enum.
enum weaponTrace_t::weaponTraceType_t : __int32
{
  WEAPON_TRACE_BULLET = 0x0,
  WEAPON_TRACE_EXPLOSION = 0x1,
  WEAPON_TRACE_PROJECTILE = 0x2,
};

// IDA Local Type ordinal 14146; PDB kind: struct.
struct weaponTrace_t
{
  idVec3 start;
  idVec3 end;
  idVec3 impactPoint;
  idVec3 dir;
  idSpawnId attacker;
  idSpawnId projectile;
  const idDeclDamage *damageDecl;
  float radius;
  weaponTrace_t::weaponTraceType_t weaponTraceType;
};

// IDA Local Type ordinal 14149; PDB kind: class.
class idWeaponTraceManager
{
public:
  idStaticList<weaponTrace_t,6> weaponTraces[2];
  int currentDeferred;
};
