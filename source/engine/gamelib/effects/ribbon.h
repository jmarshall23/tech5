#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\effects\ribbon.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14136; PDB kind: struct.
struct idRibbon::ribbonNode_t
{
  idVec3 origin;
  idVec3 origin2;
  idVec3 velocity;
  idVec3 orientVec;
  idVec4 color;
  int spawnTime;
  float nodeLength;
};

// IDA Local Type ordinal 14137; PDB kind: class.
class __declspec(align(4)) idRibbon
{
public:
  ribbonState_t ribbonState;
  idVec3 spawnOrg;
  int spawnTime;
  int numActiveNodes;
  int currHeadIdx;
  float startVariance;
  int prevTime;
  idVec3 prevOrigin;
  idVec3 prevOrigin2;
  const idDeclRibbon *ribbonDecl;
  idVec4 globalColor;
  idRibbon::ribbonNode_t ribbonNodes[128];
  bool explicitDefineBothEdges;
};
