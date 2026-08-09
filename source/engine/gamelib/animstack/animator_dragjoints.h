#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\animstack\animator_dragjoints.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17138; PDB kind: class.
class idAnimator_DragJoints : public idAnimator_Base
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17141.
  virtual ~idAnimator_DragJoints();
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
  int blendFrame;
  int numBlendFrames;
  idAnimator_AnimWeb *animweb;
  idList<idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t>,5> subwebs;
  idIndex<short,enum invalidJointIndex_t> baseJoint;
  idList<idAnimator_DragJoints::idJoint,5> joints;
  idTreeAnimator *animator;
  idMD6LeafPause animLeaf;
  idMD6Branch *mergeBranch;
};

// IDA Local Type ordinal 17139; PDB kind: class.
class idAnimator_DragJoints::idJoint
{
public:
  idIndex<short,enum invalidJointIndex_t> index;
  idVec3 position;
  float length;
  idMat3 originalRotation;
};

// IDA Local Type ordinal 21513; PDB kind: class.
class idAnimatorParms_DragJoints : public idAnimatorParms_Base
{
public:
  const idDeclDragJoints *declDragJoints;
};
