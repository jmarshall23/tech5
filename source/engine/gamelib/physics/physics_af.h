#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\physics\physics_af.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14613; PDB kind: class.
class idPhysics_AF : public idPhysics_DynamicBase
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14623.
  virtual ~idPhysics_AF();
  virtual void SetClipModel(idClipModel *, float, int, bool);
  virtual idClipModel *GetClipModel(int);
  virtual int GetNumClipModels();
  virtual void SetMass(float, int);
  virtual float GetMass(int);
  virtual void SetContents(int, int);
  virtual int GetContents(int);
  virtual void SetClipMask(int, int);
  virtual int GetClipMask(int);
  virtual const idBounds *GetBounds(int);
  virtual const idBounds *GetAbsBounds(int);
  virtual void SetOrigin(const idVec3 *, int);
  virtual void SetAxis(const idMat3 *, int);
  virtual void Translate(const idVec3 *, int);
  virtual void Rotate(const idRotation *, int);
  virtual const idVec3 *GetOrigin(int);
  virtual const idMat3 *GetAxis(int);
  virtual const idVec3 *GetLocalOrigin(int);
  virtual const idMat3 *GetLocalAxis(int);
  virtual void SetLinearVelocity(const idVec3 *, int);
  virtual void SetAngularVelocity(const idVec3 *, int);
  virtual idVec3 *GetLinearVelocity(idVec3 *result, int);
  virtual idVec3 *GetAngularVelocity(idVec3 *result, int);
  virtual void SetGravity(const idVec3 *);
  virtual const idVec3 *GetGravity();
  virtual const idVec3 *GetGravityNormal();
  virtual void SetWaterLevel(float, int);
  virtual float GetWaterLevel(int);
  virtual void SetWaterViscosity(float, int);
  virtual float GetWaterViscosity(int);
  virtual void SetWaterEntNum(int);
  virtual int GetWaterEntNum();
  virtual void SetWaterSurfaceWrldHeight(float);
  virtual float GetWaterSurfaceWrldHeight();
  virtual void GetImpactInfo(const int, const idVec3 *, impactInfo_t *);
  virtual void ApplyImpulse(const int, const idVec3 *, const idVec3 *);
  virtual void ApplyForce(const int, const idVec3 *, const idVec3 *);
  virtual void Activate();
  virtual void PutToRest();
  virtual bool IsAtRest();
  virtual bool IsPushable(int);
  virtual void SaveState();
  virtual void RestoreState();
  virtual bool Evaluate(int, int);
  virtual void UpdateTime(int);
  virtual void ClipTranslation(trace_t *, const idVec3 *, const idClipModel *);
  virtual void ClipRotation(trace_t *, const idRotation *, const idClipModel *);
  virtual int ClipContents(const idClipModel *, int);
  virtual void DisableClip();
  virtual void EnableClip();
  virtual void UnlinkClip();
  virtual void LinkClip();
  virtual bool EvaluateContacts();
  virtual int GetNumContacts();
  virtual const contactInfo_t *GetContact(int);
  virtual void ClearContacts();
  virtual void AddContactPhysics(idPhysics *);
  virtual void RemoveContactPhysics(idPhysics *);
  virtual int GetNumContactPhysics();
  virtual idPhysics *GetContactPhysics(int);
  virtual void ActivateContactPhysics();
  virtual bool HasGroundContacts();
  virtual bool IsGroundEntity(int);
  virtual bool IsGroundClipModel(int, int);
  virtual void SetPushed(int);
  virtual idVec3 *GetPushedLinearVelocity(idVec3 *result, const int);
  virtual idVec3 *GetPushedAngularVelocity(idVec3 *result, const int);
  virtual void SetMaster(bool, const idVec3 *, const idMat3 *, const bindFlags_t);
  virtual void SetLocalOrigin(const idVec3 *, int);
  virtual void SetLocalAxis(const idMat3 *, int);
  virtual int GetBlockingEntityNum();
  virtual int GetLinearEndTime();
  virtual int GetAngularEndTime();
  virtual bool IsInNonResidentCollisionArea(bool);
  virtual bool IsOutsideWorld();
  virtual void Serialize(idSerializer *);

  idList<idAFTree *,71> trees;
  idList<idAFBody *,71> bodies;
  idList<idAFConstraint *,71> constraints;
  idList<idAFConstraint *,71> primaryConstraints;
  idList<idAFConstraint *,71> auxiliaryConstraints;
  idList<idAFConstraint *,71> frameConstraints;
  idList<idAFConstraint_Contact *,71> contactConstraints;
  idList<int,71> contactBodies;
  idStaticList<idPhysics_AF::noclipBodyInfo_t,8> noclipBodies;
  bool changedAF;
  float linearFriction;
  float angularFriction;
  float contactFriction;
  float bouncyness;
  float totalMass;
  idVec2 suspendVelocity;
  idVec2 suspendAcceleration;
  float noMoveTime;
  float noMoveTranslation;
  float noMoveRotation;
  float minMoveTime;
  float maxMoveTime;
  float impulseThreshold;
  float timeScale;
  float timeScaleRampStart;
  float timeScaleRampEnd;
  float jointFrictionScale;
  float jointFrictionDent;
  float jointFrictionDentStart;
  float jointFrictionDentEnd;
  float jointFrictionDentScale;
  float contactFrictionScale;
  float contactFrictionDent;
  float contactFrictionDentStart;
  float contactFrictionDentEnd;
  float contactFrictionDentScale;
  idFader errorReduction;
  idFader errorReductionMax;
  idFader lcpEpsilon;
  idFader limitErrorReduction;
  idFader limitErrorReductionMax;
  idFader limitLcpEpsilon;
  idFader contactErrorReduction;
  idFader contactErrorReductionMax;
  idFader contactLcpEpsilon;
  idFader universalErrorReduction;
  idFader universalErrorReductionMax;
  idFader universalTorsionLcpEpsilon;
  int passEntityNum;
  bool selfCollision;
  bool comeToRest;
  bool linearTime;
  bool noImpact;
  bool worldConstraintsLocked;
  bool forcePushable;
  bool addContactConstraints;
  bool addGravity;
  idAFBody *masterBody;
  AFPState_t current;
  AFPState_t saved;
  float lastTimeStep;
  int endTime;
  float timeStep;
  idVec3 lastImpulse;
  idLCP *lcp;
};

// IDA Local Type ordinal 14619; PDB kind: struct.
struct idPhysics_AF::noclipBodyInfo_t
{
  int bodyId;
  int originalClipMask;
  idClipQuery query;
};
