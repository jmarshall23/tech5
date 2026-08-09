#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\effectphysics\effectphysicsdebrisemitter.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14594; PDB kind: struct.
struct idEffectPhysicsDebrisEmitter::emitBufferItem_t
{
  idVec3 pos;
  idVec3 normal;
  int count;
};

// IDA Local Type ordinal 14595; PDB kind: class.
class idEffectPhysicsDebrisEmitter
{
public:
  idEffectPhysicsPieceEmitter piecePhysics;
  idEffectPhysicsDebrisEmitter::emitBufferItem_t emitBuffer[10];
  int emitBufferPos;
  int serializeEmitCount;
  bool skipFirstFrame;
  bool active;
  idRandom2 random;
};
