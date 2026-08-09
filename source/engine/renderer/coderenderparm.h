#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\coderenderparm.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 19088; PDB kind: class.
class idCodeRenderParm
{
public:
  idAtomicString name;
  const char *initString;
  int parmIndex;
  parmType_t parmType;
  bool cubeFilterTexture;
  parmValue_t declaredValue;
  parmEdit_t edit;
  float editRange[2];
};
