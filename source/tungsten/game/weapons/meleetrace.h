#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\weapons\meleetrace.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1065; PDB kind: enum.
enum idMeleeTrace::meleeDamage_t : __int32
{
  MELEE_IMPACT = 0x0,
  MELEE_SEMI_CONTINUOUS = 0x1,
  MELEE_FIRST_PLUS_ACTOR = 0x2,
  MELEE_CONTINUOUS = 0x3,
  MELEE_MAX = 0x4,
};

// IDA Local Type ordinal 1066; PDB kind: enum.
enum idMeleeTrace::meleeBounds_t : __int32
{
  BOUNDS_LINE = 0x0,
  BOUNDS_8x8 = 0x1,
  BOUNDS_16x16 = 0x2,
  BOUNDS_24x24 = 0x3,
  BOUNDS_32x32 = 0x4,
  BOUNDS_48x48 = 0x5,
  BOUNDS_96x96 = 0x6,
  BOUNDS_PLAYER_MELEE = 0x7,
  BOUNDS_CUSTOM = 0x8,
  BOUNDS_MAX = 0x9,
};

// IDA Local Type ordinal 13670; PDB kind: struct.
struct modelTrace_t
{
  localTrace_t tr;
  const idRenderModelSurface *surf;
  const idRenderModel *entity;
};

// IDA Local Type ordinal 15372; PDB kind: class.
class idMeleeTrace : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15373.
  virtual idTypeInfo *GetType();
  virtual ~idMeleeTrace();

  const idDeclDamage *damageDef;
  const idDeclProjectileImpactEffect *impactEffect;
  int upgradDamageScale;
  idIndex<short,enum invalidJointIndex_t> jointIndex;
  idIndex<short,enum invalidJointIndex_t> jointIndex2;
  tagData_t tagData;
  bool useWeaponAnimator;
  bool useTagData;
  bool weaponTagData;
  bool hasKilled;
  bool hasHit;
  int numSamples;
  float damageCap;
  unsigned __int8 meleeType;
  unsigned __int8 boundsType;
  idVec3 prevPos;
  idClipModel *clipModel;
  idEntity *hitEntity;
  const idWeapon *weapon;
  int lastHitTime;
};
