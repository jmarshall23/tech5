#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\targetting\selectors\authorityrepairbottargetselectors.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22010; PDB kind: class.
class idAuthorityRepairBotFriendlyTargetSelector : public idTargetSelector
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22011.
  virtual ~idAuthorityRepairBotFriendlyTargetSelector();
  virtual float GetWeight(const idEntity *, const idTargetInfo *);

};

// IDA Local Type ordinal 22356; PDB kind: class.
class idAuthorityRepairBotEnemyTargetSelector : public idTargetSelector
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22357.
  virtual ~idAuthorityRepairBotEnemyTargetSelector();
  virtual float GetWeight(const idEntity *, const idTargetInfo *);

  idEntityPtr<idEntity> lastTarget;
  idEntityPtr<idEntity> lastAttacker;
  float maxTargetDistance;
};
