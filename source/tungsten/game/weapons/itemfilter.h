#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\weapons\itemfilter.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17484; PDB kind: class.
class idItemFilter : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17485.
  virtual idTypeInfo *GetType();
  virtual ~idItemFilter();
  virtual void InternalPreFilterItems();
  virtual bool InternalFilter(const idInventoryItem *);
  virtual void InternalPostFilterItems();

  const idEntity *owner;
};
