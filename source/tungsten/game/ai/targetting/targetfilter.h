#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\targetting\targetfilter.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14955; PDB kind: class.
class idBotTargetFilter
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14959.
  virtual ~idBotTargetFilter();
  virtual const char *GetDebugName();
  virtual void PreCheckTargets(const int);
  virtual void CheckTarget(const int, idBotTargetRecord *);
  virtual void SortTargets();
  virtual void Reset();

  int bestTargetIndex;
  idEntityPtr<idEntity> bestTarget;
};

// IDA Local Type ordinal 18990; PDB kind: class.
class idTargetFilter
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18991.
  virtual ~idTargetFilter();
  virtual bool InternalFilter(const idEntity *, const idTargetInfo *);

  aiAwareness_t minAwareness;
};

// IDA Local Type ordinal 20487; PDB kind: class.
class idAvoidTargetFilter : public idTargetFilter
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20488.
  virtual ~idAvoidTargetFilter();
  virtual bool InternalFilter(const idEntity *, const idTargetInfo *);

};
