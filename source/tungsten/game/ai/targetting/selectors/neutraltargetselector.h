#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\targetting\selectors\neutraltargetselector.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 20477; PDB kind: class.
class idNeutralTargetSelector : public idTargetSelector
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20478.
  virtual ~idNeutralTargetSelector();
  virtual float GetWeight(const idEntity *, const idTargetInfo *);

};
