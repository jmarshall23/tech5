#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\network\localreport.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17683; PDB kind: class.
class idLocalReport : public idIssueReport
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17684.
  virtual ~idLocalReport();
  virtual void WriteReport();

  idStr fileName;
};
