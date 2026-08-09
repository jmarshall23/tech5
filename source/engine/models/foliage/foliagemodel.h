#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\foliage\foliagemodel.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13600; PDB kind: class.
class idFoliageModel : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13601.
  virtual ~idFoliageModel();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  fm_model_t foliageModelData;
  idList<idDeclFoliage const *,5> sharedAttributes;
  fm_modelStats_t stats;
};
