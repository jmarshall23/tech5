#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\weapons\fireparms.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15270; PDB kind: class.
class idFireParms
{
public:
  idPresentablePtr<idPresentable> attacker;
  idPresentablePtr<idPresentable> presentableWeapon;
  idWeapon *weapon;
  int ignoreEntityNum;
  idList<idEntityPtr<idEntity>,5> targetList;
  idPresentablePtr<idPresentable> target;
  idVec3 targetPos;
  const idDeclWeapon *wepDef;
  idVec3 start;
  idVec3 muzzleOffset;
  int muzzleTagIndex;
  idMat3 fireAxis;
  const idDeclProjectile *projDef;
  idEntityPtr<idProjectile> projectile;
  weaponStatsTag_t tag;
  __int8 noDecals : 1;
  __int8 forceNoSpread : 1;
  __int8 useTargetPos : 1;
  __int8 alwaysTracer : 1;
  __int8 fromPlayer : 1;
  __int8 freeAmmo : 1;
  __int8 silenced : 1;
  __int8 simulateProjectiles : 1;
  unsigned __int8 : 5;
  __int8 secondaryAmmo : 1;
  __int8 fromWithinVehicle : 1;
  __int8 noDamage : 1;
  float damageScale;
  float addSpread;
  float startSpeed;
  int startTime;
};

// IDA Local Type ordinal 23640; PDB kind: struct.
struct idRbParms::p_t
{
  int width;
  int height;
  int antiAlias;
  int outline;
  int ambientOcclusionSamples;
  bool saveLocalMap;
  bool saveMaskMap;
  bool saveGlobalMap;
  bool saveAmbientMap;
  bool showMiss;
  bool facet;
  bool saveColorMap;
  bool drawNormals;
  bool clampTextureSpace;
  float traceFrac;
  float traceDist;
};

// IDA Local Type ordinal 23641; PDB kind: struct.
struct idRbParms
{
  idRbParms::p_t p;
  idStr outputName;
  idStr cpuModelName;
  idList<idStr,5> highNames;
};
