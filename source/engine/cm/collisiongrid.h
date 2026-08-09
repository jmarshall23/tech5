#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\cm\collisiongrid.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15896; PDB kind: class.
class idCollisionGridState
{
public:
  const idMaterial *material;
  int numActive;
  int firstActive;
  idBitArray active;
};

// IDA Local Type ordinal 15897; PDB kind: class.
class idCollisionGrid : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15898.
  virtual ~idCollisionGrid();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();
  virtual void CreateState(idCollisionGridState *);
  virtual void InactivateFill(const idVec2i *, int, idCollisionGridState *);
  virtual bool IsValid();

};

// IDA Local Type ordinal 23778; PDB kind: class.
class idCollisionGridLocal : public idCollisionGrid
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23779.
  virtual ~idCollisionGridLocal();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();
  virtual void CreateState(idCollisionGridState *);
  virtual void InactivateFill(const idVec2i *, int, idCollisionGridState *);
  virtual bool IsValid();

  idGenGridModel grid;
  int binaryTimeStamp;
  int sourceTimeStamp;
};
