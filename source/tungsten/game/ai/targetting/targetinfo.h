#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\targetting\targetinfo.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15969; PDB kind: class.
class __declspec(align(4)) idTargetInfo
{
public:
  const idAIEntityState *es;
  float distSqr;
  float distTo;
  idVec3 delta;
  idVec3 faceDir;
  idVec3 dirTo;
  char attitude;
  unsigned __int8 healthRatio;
};
