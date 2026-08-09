#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\imagetools\filter\filter.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 3070; PDB kind: enum.
enum idFilter::bicubicFilter_t : __int32
{
  BICUBIC_PHOTOSHOP = 0x0,
  BICUBIC_SHIFTED = 0x1,
};

// IDA Local Type ordinal 14263; PDB kind: class.
class idMD6Filter : public idMD6Node
{
public:
};

// IDA Local Type ordinal 21415; PDB kind: struct.
struct aiFilter_t
{
  const char *filterName;
  int filter;
};

// IDA Local Type ordinal 23011; PDB kind: class.
class idFilter
{
public:
};
