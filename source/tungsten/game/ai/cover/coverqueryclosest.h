#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\cover\coverqueryclosest.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 21380; PDB kind: class.
class idCoverQueryClosest : public idCoverQuery
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21381.
  virtual ~idCoverQueryClosest();
  virtual void InternalPreScore();
  virtual void InternalSetupTarget(const idCoverQuery::coverTarget_t *);
  virtual float InternalScoreCover(const idCoverQuery::coverCache_t *);

  idVec3 desiredCoverPosition;
};
