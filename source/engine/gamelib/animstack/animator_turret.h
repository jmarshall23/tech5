#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\animstack\animator_turret.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17129; PDB kind: class.
class __declspec(align(4)) idAnimator_TurretNxN<3> : public idAnimator_Synced
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17130.
  virtual ~idAnimator_TurretNxN();
  virtual idAnimator_Base::priority_t GetStackPriority();
  virtual serializeType_t GetSerializeType();
  virtual void SerializeSnapshot(idSerializer *);
  virtual void PreBlendSnapshot(idAnimStack *, int, const int, float);
  virtual void PreSerializeInit(idAnimStack *, idClip *, idGameTimeManager *);
  virtual bool InternalInit(const idAnimatorParms_Base *);
  virtual bool InternalPostInit(const idAnimatorParms_Base *);
  virtual void InternalShutdown(idAnimStack *);
  virtual void InternalPreBlendTree(const idAnimStack *, const int, const int);
  virtual void InternalPostBlendTree(const idAnimStack *, const int);
  virtual void InternalStart(const idAnimStack *, const int, const idTypesafeNumber<int,enum gameTimeUnique_t>);
  virtual void InternalEnd(const idAnimStack *, const int, const idTypesafeNumber<int,enum gameTimeUnique_t>);
  virtual void InternalBlend(const idAnimStack *, const int, const float, const idTypesafeNumber<int,enum gameTimeUnique_t>);
  virtual bool InternalIsContributing();
  virtual const idMD6Branch *InternalGetMergeBranch();
  virtual idMD6Branch *InternalGetMergeBranch_2();
  virtual void InternalPause(const idAnimStack *, const idTypesafeNumber<int,enum gameTimeUnique_t>);
  virtual void InternalUnpause(const idAnimStack *, const idTypesafeNumber<int,enum gameTimeUnique_t>);
  virtual const idMD6Branch *InternalGetEndBranch();
  virtual idMD6Branch *InternalGetEndBranch_2();

  int lastBlendTriangle;
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> vertexAliasHandles[9];
};

// IDA Local Type ordinal 20101; PDB kind: struct.
struct idAnimator_TurretNxN<3>::triangle_t
{
  unsigned __int8 vertex1;
  unsigned __int8 vertex2;
  unsigned __int8 vertex3;
};

// IDA Local Type ordinal 20102; PDB kind: struct.
struct idAnimator_TurretNxN<3>::blendgrid_t
{
  idVec3 vertexLocations[9];
  idAnimator_TurretNxN<3>::triangle_t blendTriangles[8];
};

// IDA Local Type ordinal 29856; PDB kind: typedef.
typedef idAnimator_TurretNxN<3> idAnimator_Turret;

// IDA Local Type ordinal 32078; PDB kind: typedef.
typedef idAnimator_TurretNxN<3> idAnimator_Turret3x3;
