#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\targetting\selectors\enemytargetselector.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 18996; PDB kind: class.
class idEnemyTargetSelector : public idTargetSelector
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18997.
  virtual ~idEnemyTargetSelector();
  virtual float GetWeight(const idEntity *, const idTargetInfo *);

};
