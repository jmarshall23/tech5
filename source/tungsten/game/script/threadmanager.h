#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\script\threadmanager.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16006; PDB kind: class.
class idThreadManager
{
public:
  idThread *currentThread;
  int threadIndex;
  idList<idThread *,58> threadList;
  trace_t trace;
};
