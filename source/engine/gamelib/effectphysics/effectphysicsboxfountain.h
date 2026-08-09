#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\effectphysics\effectphysicsboxfountain.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16038; PDB kind: class.
class __declspec(align(8)) idEffectPhysicsBoxFountain
{
public:
  idEffectPhysicsBroadPhase broadPhase;
  idEffectPhysicsProperties properties;
  idList<idEffectPhysicsRigidBody *,59> rigidBodies;
  idRenderModelManyBoxes *manyBoxes;
  int lastFireTime;
  int currentFireRigidBody;
  idVec3 startOrigin;
  idVec3 spawnOrigin;
  idSPObject spawnObject;
  idRandom random;
};
