#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\spawning\spawnnodegroup.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15580; PDB kind: class.
class idSpawnNodeGroup
{
public:
  idList<idSpawnNode *,5> nodes;
  int approximateLocationCount;
};
