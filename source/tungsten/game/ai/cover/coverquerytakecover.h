#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\cover\coverquerytakecover.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 20508; PDB kind: class.
class idCoverQueryTakeCover : public idCoverQuery
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20509.
  virtual ~idCoverQueryTakeCover();
  virtual void InternalPreScore();
  virtual void InternalSetupTarget(const idCoverQuery::coverTarget_t *);
  virtual float InternalScoreCover(const idCoverQuery::coverCache_t *);

};
