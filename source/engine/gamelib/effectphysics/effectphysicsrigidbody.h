#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\effectphysics\effectphysicsrigidbody.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14577; PDB kind: struct.
struct idEffectPhysicsRigidBody::effectRBState_t
{
  idVec3 position;
  idMat3 orientation;
  idVec3 linearMomentum;
  idVec3 angularMomentum;
  idVec3 externalForce;
  idVec3 externalTorque;
};

// IDA Local Type ordinal 14578; PDB kind: class.
class __declspec(align(8)) idEffectPhysicsRigidBody
{
public:
  const idEffectPhysicsProperties *properties;
  idEffectPhysicsRigidBody::effectRBState_t currentState;
  idSPObject SPObject;
  bool active;
  bool settled;
};

// IDA Local Type ordinal 21719; PDB kind: struct.
struct idEffectPhysicsRigidBody::effectRBDelta_t
{
  idVec3 translation;
  idRotation rotation;
  idVec3 linearForce;
  idVec3 angularForce;
};
