#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\particles\jobs\particleparm.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13433; PDB kind: class.
class idParticleParm
{
public:
  float val0;
  float val1;
  float variance;
  __int16 tableIdx;
  __int16 table2Idx;
  particleCalcType_t calcType;
};

// IDA Local Type ordinal 14008; PDB kind: struct.
struct effectParticleParms_t
{
  int startTime;
  int duration;
  const idParticleStage *stage;
  const idLookupTable *tables;
  int numTables;
  int diversity;
  idVec3 origin;
  idMat3 axis;
  idVec3 velocity;
  idVec3 wind;
  float shadow;
  int currTime;
  int numParticles;
  unsigned int color;
};

// IDA Local Type ordinal 14015; PDB kind: struct.
const struct modelParticleParms_t
{
  int stopTime;
  float timeOffset;
  int diversity;
  float coverage;
  idVec4 color;
  idVec4 wind;
  idVec3 distribScale;
  idVec3 origin;
  idMat3 axis;
  idVec3 scale;
  idVec3 velocity;
  float shadow;
  float alphaScaleOverride;
  unsigned __int8 lod;
  unsigned __int8 pad[3];
};
