#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\seenbits.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13646; PDB kind: class.
class idSeenBits
{
public:
  int merges;
  int layoutVersion;
  int width;
  int coarsestLevel;
  __int64 bitArraySize;
  unsigned __int8 *bits;
  __int64 levelOffset[32];
};
