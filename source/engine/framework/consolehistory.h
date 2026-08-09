#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\consolehistory.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23111; PDB kind: class.
class idConsoleHistory
{
public:
  int upPoint;
  int downPoint;
  int returnLine;
  int numHistory;
  idArray<idStr,64> historyLines;
};
