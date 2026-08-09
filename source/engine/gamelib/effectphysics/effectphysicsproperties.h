#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\effectphysics\effectphysicsproperties.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14575; PDB kind: class.
class idEffectPhysicsProperties
{
public:
  idEffectPhysicsBroadPhase *broadPhase;
  int traceModelIndex;
  int clipMask;
  float linearFriction;
  float angularFriction;
  float contactFriction;
  float linearFrictionWater;
  float angularFrictionWater;
  float bouncyness;
  idVec3 gravityVector;
  bool worldCollisionOnly;
  bool simplePointCollision;
  float crazyBounceChance;
  float mass;
  float inverseMass;
  idVec3 centerOfMass;
  idMat3 inertiaTensor;
  idMat3 inverseInertiaTensor;
  float stopSpeed;
  float maxLinearVelocity;
  float maxAngularVelocity;
};
