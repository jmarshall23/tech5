#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\timemanager.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14456; PDB kind: class.
class idJobTimerManager
{
public:
  bool active;
  idList<idJobTimerIteration,5> iterations;
};

// IDA Local Type ordinal 17372; PDB kind: class.
class idTimeManager
{
public:
  int gameHz;
  idTypesafeNumber<int,enum gameTimeUnique_t> gameTimePerFrame;
};
