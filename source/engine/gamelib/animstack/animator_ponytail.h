#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\animstack\animator_ponytail.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16487; PDB kind: class.
class __declspec(align(4)) idAnimator_Ponytail : public idAnimator_Base
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16488.
  virtual ~idAnimator_Ponytail();
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

  const idDeclPonytail *declPonytail;
  idTreeAnimator *parentAnimator;
  idList<idIndex<short,enum invalidJointIndex_t>,30> joints;
  idMD6Branch *mergeBranch;
  idMD6LeafPause *pauseLeaf;
  idMD6LeafPlay *playLeaf;
  idMD6Branch *lerpBranch;
  idList<idPonytailSegment,30> segments;
  idSpring<idVec3> ptEndSpring;
  bool isInitialized;
};

// IDA Local Type ordinal 20441; PDB kind: class.
class idAnimatorParms_Ponytail : public idAnimatorParms_Base
{
public:
  const idDeclPonytail *declPonytail;
  idTreeAnimator *parentAnimator;
};
