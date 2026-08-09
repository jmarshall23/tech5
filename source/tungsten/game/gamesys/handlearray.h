#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\gamesys\handlearray.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15578; PDB kind: class.
class idHandleArray<idSpawnResult,10>
{
public:
  idSpawnResult *data;
  unsigned int *handles;
  unsigned int maxHandles;
  unsigned int counter;
};
