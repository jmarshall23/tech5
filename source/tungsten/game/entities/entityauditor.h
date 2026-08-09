#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\entityauditor.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14470; PDB kind: class.
class idEntityAuditor
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14495.
  virtual ~idEntityAuditor();
  virtual void CollectData(const idEntity *, const int);
  virtual void Audit(idEncounterGroup *, const idEntity *, const int, idAuditResults *);
  virtual void Clear();

};
