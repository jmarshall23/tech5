#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\water\watersurfacesim.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 18863; PDB kind: class.
class idWaterSurfaceSim
{
public:
  unsigned int width;
  unsigned int height;
  float spacing;
  float damping;
  float speed;
  float timeStep;
  bool visible;
  idVec3 origin;
  idRandom2 rnd;
  int currentDeferred;
  int numDisturbances;
  int allocWidth;
  int allocHeight;
  int numBlocksX;
  int numBlocksY;
  idList<unsigned int,54> simulateParms;
  idList<unsigned char,54> vertGradient;
  idList<float,54> waveHeight[2];
  idList<float,54> dummyBlock;
  idList<waterDisturbanceParms_t,54> waterDisturbances[2];
};
