#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\particles\jobs\particlegen.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 21646; PDB kind: struct.
struct particleGen_t
{
  int index;
  float cycleAge;
  float totalAge;
  float particleLife;
  float frac;
  float parmVal;
  idRandom2 random;
  idRandom2 originalRandom;
  idVec4 vertColor;
};
