#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\compilers\newmap\paralleltask.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23739; PDB kind: class.
class __declspec(align(8)) idParallelTask
{
public:
  idList<idStr,5> printLines;
  unsigned int thread;
  idStr name;
  parallelTaskParms_t taskParms;
  __int64 startMicroseconds;
  __int64 stopMicroseconds;
  bool completed;
  bool taskError;
};

// IDA Local Type ordinal 23740; PDB kind: struct.
struct parallelTaskParms_t
{
  idParallelTask *task;
  unsigned int (__fastcall *function)(void *);
  void *parms;
};
