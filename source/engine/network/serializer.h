#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\network\serializer.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13123; PDB kind: class.
class __declspec(align(4)) idSimpleSerializer
{
public:
  unsigned __int8 *data;
  int size;
  int pos;
  bool writing;
};

// IDA Local Type ordinal 13524; PDB kind: class.
class idSerializer
{
public:
  bool writing;
  idBitMsg *msg;
};

// IDA Local Type ordinal 13678; PDB kind: struct.
struct idSerializerLog::logEntry_t
{
  idStr typeName;
  idStr instanceName;
  int objID;
  int parent;
  int parentObjID;
  int start;
  int end;
  int startWriteBit;
  int endWriteBit;
};

// IDA Local Type ordinal 13680; PDB kind: struct.
struct idSerializerLog::compressionEntry_t
{
  int objID;
  int csize;
};

// IDA Local Type ordinal 13682; PDB kind: class.
class idSerializerLog
{
public:
  idList<idSerializerLog::logEntry_t,44> logEntries;
  idList<idSerializerLog::compressionEntry_t,44> compressionEntries;
  int finalCompressedSize;
  int finalUncompressedSize;
  bool fragmented;
  int lastEntry;
  int lastObjID;
  int refCount;
};
