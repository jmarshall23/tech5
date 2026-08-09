#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\animwebs\declanimwebedge.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2302; PDB kind: enum.
enum idDeclAnimWebEdge::edgeFlags_t : __int32
{
  EDGEFLAG_RANDOM_WEIGHT = 0x1,
};

// IDA Local Type ordinal 15053; PDB kind: class.
class idDeclAnimWebEdge
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15054.
  virtual ~idDeclAnimWebEdge();

  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> destSubWebIndex;
  __declspec(align(4)) blendParms_t blendParms;
  unsigned __int16 customFlags;
};
