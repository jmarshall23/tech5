#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\physics\afbody.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14602; PDB kind: class.
class idAFBody
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14603.
  virtual ~idAFBody();
  virtual void Serialize(idSerializer *);

  __declspec(align(16)) idAtomicString name;
  idClipModel *clipModel;
  int clipMask;
  float linearFrictionWater;
  float angularFrictionWater;
  float linearFriction;
  float angularFriction;
  float contactFriction;
  float bouncyness;
  idVec3 frictionDir;
  idVec3 contactMotorDir;
  float contactMotorVelocity;
  float contactMotorForce;
  float mass;
  float invMass;
  idVec3 centerOfMass;
  idMat3 inertiaTensor;
  idMat3 inverseInertiaTensor;
  idAFBody *parent;
  idList<idAFBody *,71> children;
  idAFConstraint *primaryConstraint;
  idList<idAFConstraint *,71> constraints;
  idAFTree *tree;
  idAFBody::afBodyFlags_t fl;
  AFBodyPState_t current;
  AFBodyPState_t saved;
  idClipQuery motionQuery;
  idSpatialMat inverseWorldSpatialInertia;
  idSpatialMat I;
  idSpatialMat invI;
  idSpatialMat J;
  idStaticSpatialVec s;
  idStaticSpatialVec totalForce;
  idStaticSpatialVec auxForce;
  idStaticSpatialVec acceleration;
  float *response;
  int *responseIndex;
  int numResponses;
  int maxAuxiliaryIndex;
  int maxSubTreeAuxiliaryIndex;
};

// IDA Local Type ordinal 14607; PDB kind: struct.
struct idAFBody::afBodyFlags_t
{
  __int8 clearClipMaskInSolid : 1;
  __int8 noSyncCollide : 1;
  __int8 isZero : 1;
  __int8 useContactMotorDir : 1;
  __int8 useFrictionDir : 1;
  __int8 spatialInertiaSparse : 1;
  __int8 selfCollision : 1;
  __int8 clipMaskSet : 1;
};
