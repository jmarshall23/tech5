#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\physics\physics.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1033; PDB kind: enum.
enum physicsType_t : __int32
{
  PHYSICS_INVALID = 0x0,
  PHYSICS_STATIC = 0x1,
  PHYSICS_STATICMULTI = 0x2,
  PHYSICS_AI = 0x3,
  PHYSICS_PLAYER = 0x4,
  PHYSICS_PARAMETRIC = 0x5,
  PHYSICS_RIGIDBODY = 0x6,
  PHYSICS_RIGIDBODY3DOF = 0x7,
  PHYSICS_AF = 0x8,
  PHYSICS_ROBOT = 0x9,
};

// IDA Local Type ordinal 2858; PDB kind: enum.
enum idPhysics::residency_t : __int32
{
  RESIDENCY_NOT_TESTED = 0x0,
  RESIDENCY_YES = 0x1,
  RESIDENCY_NO = 0x2,
};

// IDA Local Type ordinal 14164; PDB kind: class.
class idPhysics
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14168.
  virtual ~idPhysics();
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

  __declspec(align(8)) physicsType_t type;
  int physicsId;
  int entityNumber;
  idPhysics *nextInHash;
  idClip *clip;
  idPhysicsCallbacks *callbacks;
  idResidencyQuery residencyQuery;
  idPhysics::residency_t collisionResidency;
};

// IDA Local Type ordinal 19509; PDB kind: class.
class idPhysics_Robot : public idPhysics_DynamicBase
{
public:
  // Recovered virtual interface; IDA vtable ordinal 19510.
  virtual ~idPhysics_Robot();
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

  idClipQuery stepMoveQuery;
  idMat3 clipAxis;
  idVec3 lastCollisionNormal;
  idClipModel *clipModel;
  robotPState_t savedState;
  robotPState_t currentState;
  float maxStepHeight;
  float minFloorCosine;
  float mass;
  float invMass;
  bool noImpact;
  float timeStep;
  int timeStepMS;
};
