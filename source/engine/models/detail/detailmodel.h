#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\detail\detailmodel.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13622; PDB kind: class.
class idDetailModel : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13623.
  virtual ~idDetailModel();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  dm_model_t detailModelData;
  idList<idDeclDetail const *,5> sharedAttributes;
  dm_modelStats_t stats;
};
