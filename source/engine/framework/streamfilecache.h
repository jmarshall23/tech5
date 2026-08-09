#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\streamfilecache.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 12275; PDB kind: class.
class __declspec(align(4)) idStreamFileCache
{
public:
  idSysMutex interfaceMutex;
  idStreamControlThread *controlThread;
  volatile bool cancelToTerminate;
};
