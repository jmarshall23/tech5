#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\static\staticmodelmanager.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 18729; PDB kind: class.
class idStaticModelManager
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18731.
  virtual ~idStaticModelManager();
  virtual void Init();
  virtual const idStaticModel *FindStaticModel(const char *, bool);
  virtual void AddStaticModel(idStaticModel *);
  virtual void ReloadModels();
  virtual void CalculateStats(idStaticModelManager::idStats *);

};

// IDA Local Type ordinal 18730; PDB kind: struct.
struct idStaticModelManager::idStats
{
  int totalCPUMem;
  int totalGPUMem;
  int inUse;
  int totalVerts;
  int totalTriangles;
  int totalSurfaces;
};

// IDA Local Type ordinal 23184; PDB kind: class.
class idStaticModelManagerLocal : public idStaticModelManager
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23185.
  virtual ~idStaticModelManagerLocal();
  virtual void Init();
  virtual const idStaticModel *FindStaticModel(const char *, bool);
  virtual void AddStaticModel(idStaticModel *);
  virtual void ReloadModels();
  virtual void CalculateStats(idStaticModelManager::idStats *);

};
