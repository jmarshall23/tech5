#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14580; PDB kind: class.
class idEffectPhysicsPieceEmitter::idBreakablePiece
{
public:
  idEffectPhysicsRigidBody *rigidBody;
  idEffectPhysicsCollision collision;
  int emitTime;
  int firstCollisionTime;
};

// IDA Local Type ordinal 14592; PDB kind: struct.
struct idEffectPhysicsPieceEmitter::pieceEmitterSound_t
{
  idSoundWorld *soundWorld;
  const idDeclImpactSound *impactTable;
  int nextSoundTime;
  float minBounceVelSqr;
};

// IDA Local Type ordinal 14593; PDB kind: class.
class __declspec(align(4)) idEffectPhysicsPieceEmitter
{
public:
  idList<idEffectPhysicsProperties *,59> properties;
  idList<idEffectPhysicsPieceEmitter::idBreakablePiece,59> pieces;
  idEffectPhysicsBroadPhase broadPhase;
  idRandom random;
  float pieceMass;
  float pieceCollisionAgeDecay;
  float pieceCollisionVolumeDecay;
  idRenderModelDiscreteAnimation *model;
  const idDeclBreakable *decl;
  idRenderModelEffects *modelEffects;
  idEffectPhysicsPieceEmitter::pieceEmitterSound_t soundInfo;
  int pieceLifeTime;
  float pieceFriction;
  int pieceIndex;
  int numPiecesInUse;
  bool hidden;
  bool hiddenOverride;
};
