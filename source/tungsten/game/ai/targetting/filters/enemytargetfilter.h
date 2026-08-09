#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\targetting\filters\enemytargetfilter.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 18992; PDB kind: class.
class idEnemyTargetFilter : public idTargetFilter
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18993.
  virtual ~idEnemyTargetFilter();
  virtual bool InternalFilter(const idEntity *, const idTargetInfo *);

};
