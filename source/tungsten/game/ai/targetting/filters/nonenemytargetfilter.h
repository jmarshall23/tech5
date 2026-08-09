#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\targetting\filters\nonenemytargetfilter.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 19950; PDB kind: class.
class idNonEnemyTargetFilter : public idTargetFilter
{
public:
  // Recovered virtual interface; IDA vtable ordinal 19951.
  virtual ~idNonEnemyTargetFilter();
  virtual bool InternalFilter(const idEntity *, const idTargetInfo *);

};
