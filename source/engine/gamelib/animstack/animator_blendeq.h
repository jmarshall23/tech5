#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\animstack\animator_blendeq.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 19144; PDB kind: class.
class idAnimator_BlendEq::idNamedAnim
{
public:
  const idMD6Anim *anim;
  unsigned __int8 wrapMode;
  unsigned __int8 weightGroup;
  float rate;
};

// IDA Local Type ordinal 19146; PDB kind: class.
class idAnimator_BlendEq : public idAnimator_Base
{
public:
  // Recovered virtual interface; IDA vtable ordinal 19147.
  virtual ~idAnimator_BlendEq();
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

  idStr blendEq;
  idMD6Branch *mergeBranch;
  idList<idAnimWebScalar,33> scalars;
  idList<idAnimWebScalarPair,33> scalarPairs;
  idScalarMemBlock *scalarMem;
  idList<idAnimator_BlendEq::idNamedAnim,33> namedAnims;
};

// IDA Local Type ordinal 19152; PDB kind: class.
class idAnimatorParms_BlendEq : public idAnimatorParms_Base
{
public:
  idStr blendEq;
  idList<idAnimWebScalar,5> scalars;
  idScalarMemBlock *scalarMem;
  idList<idAnimator_BlendEq::idNamedAnim,5> anims;
};
