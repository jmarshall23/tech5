#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\targetting\filters\friendlytargetfilter.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 20483; PDB kind: class.
class idFriendlyTargetFilter : public idTargetFilter
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20484.
  virtual ~idFriendlyTargetFilter();
  virtual bool InternalFilter(const idEntity *, const idTargetInfo *);

};

// IDA Local Type ordinal 20485; PDB kind: class.
class idFriendlyDeadTargetFilter : public idTargetFilter
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20486.
  virtual ~idFriendlyDeadTargetFilter();
  virtual bool InternalFilter(const idEntity *, const idTargetInfo *);

};
