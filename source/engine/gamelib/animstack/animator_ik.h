#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\animstack\animator_ik.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15249; PDB kind: class.
class idAnimator_IK : public idAnimator_Base
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15250.
  virtual ~idAnimator_IK();
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
  virtual void Evaluate();

  bool enabled;
  bool ikInitialized;
  bool ik_activate;
  int entityNum;
  idTreeAnimator *animator;
  idClip *clip;
};

// IDA Local Type ordinal 15255; PDB kind: class.
class __declspec(align(8)) idAnimator_WalkIK : public idAnimator_IK
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15256.
  virtual ~idAnimator_WalkIK();
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
  virtual void Evaluate();

  const idDeclWalkIK *decl;
  idClipModel *clipModel;
  int clipMask;
  idVec3 upNormal;
  idClipModel *footModel;
  bool createdClipModel;
  int numLegs;
  int enabledLegs;
  idIndex<short,enum invalidJointIndex_t> footJoints[8];
  idIndex<short,enum invalidJointIndex_t> ankleJoints[8];
  idIndex<short,enum invalidJointIndex_t> kneeJoints[8];
  idIndex<short,enum invalidJointIndex_t> hipJoints[8];
  idIndex<short,enum invalidJointIndex_t> dirJoints[8];
  idIndex<short,enum invalidJointIndex_t> waistJointHandle;
  idVec3 hipForward[8];
  idVec3 kneeForward[8];
  float upperLegLength[8];
  float lowerLegLength[8];
  idMat3 upperLegToHipJoint[8];
  idMat3 lowerLegToKneeJoint[8];
  idMat3 kneeJointTransform[8];
  int pivotFoot;
  float pivotYaw;
  idVec3 pivotPos;
  bool onGround;
  bool onStairs;
  bool isDead;
  bool oldHeightsValid;
  float oldWaistHeight;
  float oldAnkleHeights[8];
  int oldGroundPhysicsId;
  idVec3 oldGroundPhysicsOrigin;
  int surfaceTypes[8];
  idClipQuery modelQuery;
  idClipQuery waistQuery;
  idClipQuery legQueries[8];
  idClipQuery footQueries[8];
  idVec3 lastModelSpaceFootOrigin[8];
  float groundTraceDist;
  float internalRadiusXY;
  idMD6LeafPause animLeaf;
  idMD6Branch *mergeBranch;
};

// IDA Local Type ordinal 18903; PDB kind: struct.
struct __declspec(align(2)) idAnimator_ReachIK::targetTransform_t
{
  idVec3 origin;
  idMat3 axis;
  tagData_t selfTag;
  bool validOrigin;
  bool validAxis;
  bool validTag;
};

// IDA Local Type ordinal 18904; PDB kind: class.
class idAnimator_ReachIK : public idAnimator_IK
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18905.
  virtual ~idAnimator_ReachIK();
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
  virtual void Evaluate();

  const idDeclReachIK *decl;
  int numArms;
  int enabledArms;
  idIndex<short,enum invalidJointIndex_t> handJoints[2];
  idIndex<short,enum invalidJointIndex_t> elbowJoints[2];
  idIndex<short,enum invalidJointIndex_t> shoulderJoints[2];
  idAnimator_ReachIK::targetTransform_t targetTransforms[2];
  idVec3 shoulderForward[2];
  idVec3 elbowForward[2];
  float upperArmLength[2];
  float lowerArmLength[2];
  idMat3 upperArmToShoulderJoint[2];
  idMat3 lowerArmToElbowJoint[2];
};
