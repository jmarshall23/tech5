#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\targetting\filters\followtargetfilter.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22064; PDB kind: class.
class idFollowTargetFilter : public idTargetFilter
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22065.
  virtual ~idFollowTargetFilter();
  virtual bool InternalFilter(const idEntity *, const idTargetInfo *);

};
