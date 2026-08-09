#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\gamesys\circularbuffer.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14496; PDB kind: class.
class idCircularBuffer<idVec3,5>
{
public:
  idVec3 buffer[5];
  int num;
  int head;
};

// IDA Local Type ordinal 15576; PDB kind: class.
class idCircularBuffer<idSpawnManager::Command,128>
{
public:
  idSpawnManager::Command buffer[128];
  int num;
  int head;
};

// IDA Local Type ordinal 24084; PDB kind: class.
class CircularBuffer
{
public:
  unsigned int size;
  void **buffer;
  void *unalignedPointer;
};
