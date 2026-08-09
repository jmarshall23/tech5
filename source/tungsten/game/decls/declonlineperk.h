#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declonlineperk.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 20131; PDB kind: class.
class idDeclOnlinePerk : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20132.
  virtual ~idDeclOnlinePerk();
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

  float boostUpModifier;
  float duraBumpModifier;
  float jumpManModifier;
  float overAmmoModifier;
  float lockJackModifier;
  float fasterFasterModifier;
  float theSnapperModifier;
  int overLoadModifier;
};
