#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\cover\coverqueryavoid.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 21111; PDB kind: class.
class idCoverQueryAvoid : public idCoverQuery
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21112.
  virtual ~idCoverQueryAvoid();
  virtual void InternalPreScore();
  virtual void InternalSetupTarget(const idCoverQuery::coverTarget_t *);
  virtual float InternalScoreCover(const idCoverQuery::coverCache_t *);

  float maxAvoidTime;
  const idEntity *avoidEnt;
  idAASPosition avoidvcPos;
  idVec3 avoidOrigin;
};
