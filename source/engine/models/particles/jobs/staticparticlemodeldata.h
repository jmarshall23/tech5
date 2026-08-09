#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\particles\jobs\staticparticlemodeldata.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13431; PDB kind: class.
class idStaticParticleModelData : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13432.
  virtual ~idStaticParticleModelData();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  unsigned int timestamp;
  idDrawVert *staticVerts;
  int numStaticVerts;
};
