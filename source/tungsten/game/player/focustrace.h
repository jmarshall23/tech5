#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\player\focustrace.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1352; PDB kind: enum.
enum idFocusTrace::focusTraceNum_t : __int32
{
  MAX_FOCUS_TRACES = 0x4,
};

// IDA Local Type ordinal 15119; PDB kind: struct.
struct idFocusTrace::focusTrace_t
{
  idEntityPtr<idEntity> entity;
  float distance;
  float dot;
  idClipQuery pointTrace;
};

// IDA Local Type ordinal 15120; PDB kind: class.
class __declspec(align(8)) idFocusTrace
{
public:
  idVec3 start;
  idVec3 close;
  idVec3 end;
  float distance;
  bool closeEnough;
  idEntityPtr<idEntity> ent;
  idClipQuery pointTrace;
  idGatherQuery gatherQuery;
  idFocusTrace::focusTrace_t focusTraces[4];
  int numFocusTraces;
  trace_t tr;
};
