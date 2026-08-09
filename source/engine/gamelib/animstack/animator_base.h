#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\animstack\animator_base.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1357; PDB kind: enum.
enum idAnimator_Base::priority_t : __int32
{
  PRIORITY_WEB = 0x0,
  PRIORITY_AFTER_WEB = 0x1,
  PRIORITY_IK = 0x63,
  PRIORITY_AF = 0x64,
};

// IDA Local Type ordinal 14224; PDB kind: class.
class __declspec(align(4)) idAnimator_Base
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14289.
  virtual ~idAnimator_Base();
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

  idGameTimeManagerPtr gametimeManager;
  md6WeightGroup_t weightGroup;
  md6WeightGroup_t filterGroup;
  idAnimator_Base::serializeProps_t serializeProps;
  bool initialized;
};

// IDA Local Type ordinal 14288; PDB kind: class.
class idAnimatorParms_Base
{
public:
  idAnimStack *animStack;
  idStr name;
  idMD6Blend::blendOp_t blendOp;
  idMD6Blend::originBlend_t originBlend;
  md6WeightGroup_t weightGroup;
  md6WeightGroup_t filterGroup;
  float alpha;
};

// IDA Local Type ordinal 14291; PDB kind: struct.
struct __declspec(align(4)) idAnimator_Base::serializeProps_t
{
  idMD6Branch *serializedTrees[2];
  idAnimStack *animStack;
  idClip *clip;
  bool createdThroughSerialization;
};
