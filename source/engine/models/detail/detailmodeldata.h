#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\detail\detailmodeldata.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23362; PDB kind: class.
class idDetailModelData : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23363.
  virtual ~idDetailModelData();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  idDetailPaletteData *paletteData;
  int paletteIdx;
};
