#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\animstack\animator_jointmod.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15447; PDB kind: class.
class idAnimator_JointMod : public idAnimator_Base
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15448.
  virtual ~idAnimator_JointMod();
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

  bool enabled;
  idList<idIndex<short,enum invalidJointIndex_t>,5> jointIndex;
  idList<idMat3,5> jointValue;
  idTreeAnimator *treeAnimator;
  animationPose_t poseToModify;
};

// IDA Local Type ordinal 18840; PDB kind: class.
class idAnimatorParms_JointMod : public idAnimatorParms_Base
{
public:
  idTreeAnimator *treeAnimator;
  animationPose_t poseToModify;
};
