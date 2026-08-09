#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\fsm\fsmlog.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17252; PDB kind: class.
class idFSMLog
{
public:
  idList<idFSMLogEntry,5> list;
  int first;
  int maxSize;
};
