#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.h
// Recovered logical types: 7
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15408; PDB kind: class.
class __declspec(align(2)) idEffectPhysicsBreakable::idExplosion
{
public:
  idBreakableExplosion decl;
  int startTime;
  int fxIndex;
  idVec3 worldPosition;
  bool effectsEnabled;
  bool forceApplied;
  bool localSpace;
};

// IDA Local Type ordinal 15412; PDB kind: class.
class idEffectPhysicsBreakable::idTrail
{
public:
  idBreakableTrail decl;
  idList<int,59> pieceStartTime;
  idList<idVec3,59> pieceLastParticleDropPos;
};

// IDA Local Type ordinal 15415; PDB kind: class.
class idEffectPhysicsBreakable::idBreakableParticle
{
public:
  const idDeclParticle *particle;
  idVec3 pos;
  int startTime;
};

// IDA Local Type ordinal 15417; PDB kind: class.
class idEffectPhysicsBreakable::idDecalFX
{
public:
  idBreakableDecal decl;
  idList<int,59> pieceStartTime;
  idList<idVec3,59> lastCollisionPos;
  idList<idVec3,59> lastCollisionNormal;
  idList<idVec3,59> pieceLastDecalDropPos;
};

// IDA Local Type ordinal 15419; PDB kind: class.
class idEffectPhysicsBreakable::idSpark
{
public:
  const idMaterial *material;
  float velocityScale;
  float size;
};

// IDA Local Type ordinal 15421; PDB kind: struct.
struct idEffectPhysicsBreakable::breakablePieceSound_t
{
  idSoundWorld *soundWorld;
  idSoundEmitter *emitter;
  soundChannel_t channel;
  const idDeclImpactSound *impactTable;
  int nextSoundTime;
  float minBounceVelSqr;
};

// IDA Local Type ordinal 15422; PDB kind: class.
class idEffectPhysicsBreakable
{
public:
  idList<idEffectPhysicsProperties *,59> properties;
  idList<idEffectPhysicsRigidBody *,59> rigidBodies;
  idList<idEffectPhysicsCollision,59> collisions;
  idCollisionModel *basePiece;
  idList<idEffectPhysicsBreakable::idExplosion,59> explosions;
  idList<idFXManager,59> explosionFX;
  idList<idEffectPhysicsBreakable::idTrail,59> trails;
  idList<float,59> damage;
  idList<idEffectPhysicsBreakable::idBreakableParticle,59> particles;
  idList<idEffectPhysicsBreakable::idDecalFX,59> decals;
  idList<idEffectPhysicsBreakable::idSpark,59> sparks;
  idList<int,5> pieceActivationTimes;
  idEffectPhysicsBroadPhase broadPhase;
  idRandom random;
  idGameLibEffects *gameLibEffects;
  idRenderModelDiscreteAnimation *model;
  const idDeclBreakable *decl;
  idEffectPhysicsBreakable::breakablePieceSound_t soundInfo;
};
