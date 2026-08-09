#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\targetting\selectors\turrettargetselector.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 19009; PDB kind: class.
class __declspec(align(4)) idTurretTargetSelector : public idTargetSelector
{
public:
  // Recovered virtual interface; IDA vtable ordinal 19010.
  virtual ~idTurretTargetSelector();
  virtual float GetWeight(const idEntity *, const idTargetInfo *);

  idEntityPtr<idEntity> lastTarget;
  idEntityPtr<idEntity> lastAttacker;
  float maxTargetDistance;
  float minTargetDistance;
  idVec3 forwardSearchDir;
  float maxSearchAngle;
  bool trackOnlyPlayer;
};
