#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\effectphysics\effectphysicscuttable.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2911; PDB kind: unknown.
enum idEffectPhysicsCuttable::<unnamed_tag> : __int32
{
  MAX_PIECES = 0x8,
  MAX_BUFFERS = 0xA,
};

// IDA Local Type ordinal 17356; PDB kind: struct.
struct idEffectPhysicsCuttable::model_t
{
  int index;
  int timeStamp;
};

// IDA Local Type ordinal 17363; PDB kind: struct.
struct idEffectPhysicsCuttable::piece_t
{
  idEffectPhysicsProperties *properties;
  idEffectPhysicsRigidBody *rigidBody;
  const idDeclImpactSound *soundTable;
  idEffectPhysicsCollision collision;
  idMat3 orientation;
  idVec3 position;
  int timeStamp;
  int firstCollisionTime;
  int renderModelIndex;
  int nextSoundTime;
  float minBounceVelocitySqr;
};

// IDA Local Type ordinal 17366; PDB kind: class.
class idEffectPhysicsCuttable
{
public:
  idStaticList<idEffectPhysicsCuttable::model_t,10> freeModels;
  idStaticList<idRenderModelCuttableDynamic *,10> models;
  idStaticList<idEffectPhysicsCuttable::piece_t,8> pieces;
  idEffectPhysicsBroadPhase broadPhase;
  float pieceCollisionAgeDecay;
  float pieceFriction;
  int pieceMaxLifeTime;
  int pieceLifeTime;
  int pieceFadeTime;
  int pieceMass;
  idSoundWorld *soundWorld;
};
