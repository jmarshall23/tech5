#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\decl.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13303; PDB kind: class.
class idDecl : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13310.
  virtual ~idDecl();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();
  virtual unsigned int GetDeclTimestamp();
  virtual idDeclInfo *GetDeclInfo();
  virtual bool RebuildTextSource();
  virtual bool SetImplicitText();
  virtual const char *DefaultDefinition();
  virtual void LogMissingDecl();
  virtual void Parse(idParser *);
  virtual void FreeData();
  virtual unsigned int Size();

  char *textSource;
  int textLength;
  unsigned int md5Checksum;
  bool programaticallyDefined;
  idDeclSource *declSource;
};

// IDA Local Type ordinal 32608; PDB kind: typedef.
typedef idDeclFX *fxDecl;
