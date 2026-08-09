#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\network\snapshot.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1101; PDB kind: enum.
enum snapshotState_t : __int32
{
  SNAP_NONE = 0x0,
  SNAP_READING = 0x1,
  SNAP_WRITING = 0x2,
};

// IDA Local Type ordinal 13672; PDB kind: struct.
struct idSnapShot::objectBuffer_t
{
  unsigned __int8 *data;
  unsigned int size;
};

// IDA Local Type ordinal 13673; PDB kind: struct.
struct __declspec(align(4)) idSnapShot::objectState_t
{
  unsigned __int16 objectNum;
  idSnapShot::objectBuffer_t buffer;
  unsigned int visMask;
  bool stale;
  bool deleted;
  int changedCount;
  int expectedSequence;
  bool createdFromTemplate;
};

// IDA Local Type ordinal 13683; PDB kind: class.
class __declspec(align(4)) idSnapShot
{
public:
  idList<idSnapShot::objectState_t *,57> objectStates;
  idBlockAlloc<idSnapShot::objectState_t,16,57> allocatedObjs;
  idSerializerLog *serializeLog;
  int time;
  int recvTime;
  bool isGlobalHeap;
};

// IDA Local Type ordinal 22183; PDB kind: struct.
struct idSnapShot::submitDeltaJobsInfo_t
{
  objParms_t *objParms;
  int maxObjParms;
  unsigned __int8 *objMemory;
  objHeader_t *headers;
  int maxHeaders;
  int maxObjMemory;
  lzwParm_t *lzwParms;
  int maxDeltaParms;
  idSnapShot *oldSnap;
  int visIndex;
  int baseSequence;
  idSnapShot *templateStates;
  lzwInOutData_t *lzwInOutData;
  idParallelJobList *snapshotJobList;
};
