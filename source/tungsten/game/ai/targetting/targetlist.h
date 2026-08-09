#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\targetting\targetlist.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1069; PDB kind: enum.
enum garageList_t : __int32
{
  GARAGE_NONE = 0x0,
  GARAGE_HAGER = 0x1,
  GARAGE_WELLSPRING = 0x2,
  GARAGE_SUBWAYTOWN = 0x3,
  GARAGE_MAX = 0x4,
};

// IDA Local Type ordinal 1829; PDB kind: enum.
enum targetListType_t : __int32
{
  TARGETTYPE_ENTER = 0x0,
  TARGETTYPE_EXIT = 0x1,
  TARGETTYPE_PRIMARYFIRE = 0x2,
  TARGETTYPE_SECONDARYFIRE = 0x3,
};

// IDA Local Type ordinal 19000; PDB kind: class.
class idTargetList
{
public:
  const idTargetCache *targetCache;
  idStaticList<int,8> viableTargets;
  int bestTargetIndex;
};

// IDA Local Type ordinal 31826; PDB kind: typedef.
typedef idStaticList<idEntityPtr<idEntity const >,4> threatList_t;
