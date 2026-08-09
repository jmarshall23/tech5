#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\streamfilelog.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23532; PDB kind: class.
class idStreamFileLog
{
public:
  int numEntries;
  int maxEntries;
  sflEntry_t *entries;
  idSysMutex mutex;
  sflIO_t driveState[3];
  sflEntry_t *currentEntry[3];
};
