#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\aas2file\aas2debugareamodel.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23519; PDB kind: class.
class idAAS2DebugAreaModel : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23520.
  virtual ~idAAS2DebugAreaModel();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  idAAS2DebugAreaModelData data;
  unsigned int sourceTimestamp;
};
