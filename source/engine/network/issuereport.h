#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\network\issuereport.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17681; PDB kind: class.
class idIssueReport
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17682.
  virtual ~idIssueReport();
  virtual void WriteReport();

  idStr attachFileName;
};
