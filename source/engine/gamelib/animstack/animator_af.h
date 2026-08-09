#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\animstack\animator_af.h
// Recovered logical types: 8
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2022; PDB kind: enum.
enum idAnimator_AF::testSolidResult_t : __int32
{
  TESTSOLID_NOT_IN_SOLID = 0x0,
  TESTSOLID_IN_SOLID_NOCLIP = 0x1,
  TESTSOLID_IN_SOLID = 0x2,
  TESTSOLID_MAX = 0x3,
};

// IDA Local Type ordinal 2608; PDB kind: enum.
enum idAnimator_AF::idBindConstraint::bindConstraint_t : __int32
{
  Fixed = 0x0,
  BallAndSocket = 0x1,
  Universal = 0x2,
};

// IDA Local Type ordinal 14649; PDB kind: class.
class __declspec(align(8)) idAnimator_AF : public idAnimator_Base
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14668.
  virtual ~idAnimator_AF();
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
  virtual void ApplyWaterSplashEffects(const int, const int, surfTypes_t, idPhysicsCallbacks::splashState_t);

  const idDeclAF *articulatedFigure;
  const idDeclImpactSound *sndBounceTable;
  const idDeclImpactParticle *prtBounceTable;
  idList<idAnimator_AF::idBindConstraint,71> bindConstraints;
  bool canDeattachBones;
  idStr afName;
  idClip *clip;
  idTreeAnimator *treeAnimator;
  const idMD6Anim *modifiedAnim;
  idVec3 baseOrigin;
  idMat3 baseAxis;
  idList<idAnimator_AF::idAFJointMod,71> jointMods;
  idList<int,71> jointBody;
  idVec3 lastRenderModelOrigin;
  idMat3 lastRenderModelAxis;
  idVec3 gravityBeforeSync;
  int poseTime;
  int restStartTime;
  bool modifiesOrigin;
  bool isLoaded;
  bool isRunningPhysics;
  bool isActive;
  bool isClientAuthoritativeActive;
  bool isSyncing;
  bool hasBindConstraints;
  bool walkIKDisabled;
  idList<idAnimator_AF::idSyncConstraint,71> syncConstraints;
  idPhysics_AF physicsObj;
  idPhysicsCallbacks *physicsCallbacks;
  idMD6LeafPause AFLeaf;
  idMD6Branch *mergeBranch;
  idSoundEmitter *soundEmitter;
  soundChannel_t bounceChannel;
  int nextSoundTime;
  idImpactManager *impactMgr;
  bool oldIsActive;
  idAnimatedEntityPhysicsCallbacksFake *fakeCB;
  const idDeclAF *storedDeclAF;
  int lastTime;
  int initCount;
  int lastImpulseTime;
  idAnimator_AF::afImpulse_t serializeImpulseBuffer[8];
  int numSerializedImpulses;
  bool inheritAnimationVelocity;
  bool inheritOverrideVelocity;
  idVec3 overrideVelocity;
};

// IDA Local Type ordinal 14659; PDB kind: class.
class __declspec(align(4)) idAnimator_AF::idBindConstraint
{
public:
  idAnimator_AF::idBindConstraint::bindConstraint_t type;
  idStr name;
  idStr bodyName;
  idStr jointName;
  bool shouldClamp;
};

// IDA Local Type ordinal 14661; PDB kind: class.
class idAnimator_AF::idAFJointMod
{
public:
  int bodyId;
  idVec3 jointBodyOrigin;
  idMat3 jointBodyAxis;
  idIndex<short,enum invalidJointIndex_t> jointIndex;
  AFJointModType_t jointMod;
};

// IDA Local Type ordinal 14663; PDB kind: class.
class idAnimator_AF::idSyncConstraint
{
public:
  idHandle<unsigned short,enum invalidJointHandle_t,65535> jointHandle;
  idAFConstraint *constraint;
};

// IDA Local Type ordinal 14667; PDB kind: struct.
struct idAnimator_AF::afImpulse_t
{
  int physId;
  int bodyId;
  idVec3 point;
  idVec3 impulse;
};

// IDA Local Type ordinal 23496; PDB kind: struct.
struct idAnimator_AF::InitAF::__l39::local_t
{
};
