#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\targetting\filters\authorityrepairbottargetfilters.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 21690; PDB kind: class.
class idAuthorityRepairBotEnemyTargetFilter : public idTargetFilter
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21691.
  virtual ~idAuthorityRepairBotEnemyTargetFilter();
  virtual bool InternalFilter(const idEntity *, const idTargetInfo *);

};

// IDA Local Type ordinal 21789; PDB kind: class.
class idAuthorityRepairBotFriendlyTargetFilter : public idTargetFilter
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21790.
  virtual ~idAuthorityRepairBotFriendlyTargetFilter();
  virtual bool InternalFilter(const idEntity *, const idTargetInfo *);

};
