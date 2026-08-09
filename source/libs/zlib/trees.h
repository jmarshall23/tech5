#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\libs\zlib\trees.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23853; PDB kind: class.
class idSort_Trees : public idSort_Quick<idIndex<int,enum invalidAASTree_t>,idSort_Trees>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23854.
  virtual ~idSort_Trees();
  virtual void Sort(idIndex<int,enum invalidAASTree_t> *, unsigned int);

  const idAAS2File *file;
  const idVec3 *normal;
};
