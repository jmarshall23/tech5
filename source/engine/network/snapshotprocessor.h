#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\network\snapshotprocessor.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 21666; PDB kind: struct.
struct idSnapshotProcessor::jobMemory_t
{
  idArray<objParms_t,4096> objParms;
  idArray<objHeader_t,256> headers;
  idArray<lzwParm_t,32> lzwParms;
  idArray<lzwDelta_t,1> lzwDeltas;
  idArray<unsigned char,8192> lzwMem;
  lzwInOutData_t lzwInOutData;
};

// IDA Local Type ordinal 21667; PDB kind: class.
class idSnapshotProcessor
{
public:
  int snapSequence;
  int baseSequence;
  int lastFullSnapBaseSequence;
  idSnapShot baseState;
  idDataQueue<64,65536> deltas;
  idArray<idSerializerLog *,64> deltaLogs;
  idSnapShot pendingSnap;
  bool hasPendingSnap;
  idSnapshotProcessor::jobMemory_t *jobMemory;
  idSnapShot submittedState;
  idSnapShot templateStates;
  idSnapShot submittedTemplateStates;
  int partialBaseSequence;
};
