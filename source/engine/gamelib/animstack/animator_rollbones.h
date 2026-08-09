#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\animstack\animator_rollbones.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17131; PDB kind: class.
class idAnimator_RollBones : public idAnimator_Base
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17134.
  virtual ~idAnimator_RollBones();
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
  virtual void PreBlendSnapshot_2(idAnimStack *, int, float);

  bool enabled;
  idTreeAnimator *animator;
  idMD6LeafPause animLeaf;
  idMD6Branch *mergeBranch;
  idList<idAnimator_RollBones::idRollInstance,5> rollBones;
};

// IDA Local Type ordinal 17132; PDB kind: class.
class idAnimator_RollBones::idRollInstance
{
public:
  idVec3 rollAxis;
  float rollAmount;
  idIndex<short,enum invalidJointIndex_t> rollSourceJoint;
  idIndex<short,enum invalidJointIndex_t> rollDestJoint;
};

// IDA Local Type ordinal 20088; PDB kind: class.
class idAnimatorParms_RollBones : public idAnimatorParms_Base
{
public:
  const idDeclRollBones *declRollBones;
};
