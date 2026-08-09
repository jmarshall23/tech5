#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\aas2file\aas2debugareamodeldata.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23514; PDB kind: struct.
struct idAAS2DebugAreaModelData::areaTri_t
{
  int v0;
  int v1;
  int v2;
};

// IDA Local Type ordinal 23516; PDB kind: struct.
struct idAAS2DebugAreaModelData::debugAreaInfo_t
{
  idList<idAAS2DebugAreaModelData::areaTri_t,5> tris;
};

// IDA Local Type ordinal 23518; PDB kind: class.
class idAAS2DebugAreaModelData
{
public:
  idList<idVec3,5> vertices;
  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5> areas;
};

// IDA Local Type ordinal 23883; PDB kind: class.
class idAAS2DebugAreaModelData::LoadBinary::__l2::idLocalFileBuffer
{
public:
  unsigned int dataLen;
  char *data;
};
