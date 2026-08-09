#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\guis\font.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 4619; PDB kind: struct.
struct HFONT__
{
  int unused;
};

// IDA Local Type ordinal 14902; PDB kind: class.
class idFont : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14905.
  virtual ~idFont();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  idFont *alias;
  fontInfo_t *fontInfo;
  unsigned int timestamp;
};

// IDA Local Type ordinal 28778; PDB kind: typedef.
typedef HFONT__ *HFONT;
