#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\fileresource.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 5027; PDB kind: struct.
struct _DXFILELOADRESOURCE
{
  HINSTANCE__ *hModule;
  const char *lpName;
  const char *lpType;
};

// IDA Local Type ordinal 22454; PDB kind: class.
class idFileResource : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22455.
  virtual ~idFileResource();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  unsigned int timestamp;
  unsigned int length;
  void *data;
};

// IDA Local Type ordinal 29898; PDB kind: typedef.
typedef _DXFILELOADRESOURCE DXFILELOADRESOURCE;
