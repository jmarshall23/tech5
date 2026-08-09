#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\effects\tracermanager.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15276; PDB kind: struct.
struct idTracerManager::tracerBufferItem_t
{
  int startTime;
  int lifeTime;
  float speed;
  idVec3 origin;
  idVec3 dir;
  float length;
  float height;
  const idMaterial *mat;
  idVec3 maxDist;
  bool ensureVisual;
  float fractionInsured;
  int playerIndex;
};

// IDA Local Type ordinal 15277; PDB kind: class.
class idTracerManager
{
public:
  idRenderModelEffects *effectsModel;
  idTracerManager::tracerBufferItem_t tracerBuffer[4];
  int tracerBufferPos;
  int serializeTracerCount;
  bool catchingUp;
  int localPlayerIndex;
};
