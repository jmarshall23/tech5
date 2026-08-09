#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declonlinelevel.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17916; PDB kind: struct.
struct onlineLevel_t
{
  int baseXp;
  float localXpScale;
  int loadouts;
};

// IDA Local Type ordinal 17918; PDB kind: class.
class idDeclOnlineLevel : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17919.
  virtual ~idDeclOnlineLevel();
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

  idList<onlineLevel_t,5> levelList;
  float globalXpScale;
  int xpCap;
};
