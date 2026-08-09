#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declaccolades.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 18362; PDB kind: class.
class idDeclAccolade : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18363.
  virtual ~idDeclAccolade();
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

  int ordinal;
  const idMaterial *icon;
  rageStat_t stat;
  idStr accoladeName;
  idStr description;
  int index;
};

// IDA Local Type ordinal 20275; PDB kind: class.
class idSort_DeclAccoladePtr : public idSort_Quick<idDeclAccolade const *,idSort_DeclAccoladePtr>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20276.
  virtual ~idSort_DeclAccoladePtr();
  virtual void Sort(const idDeclAccolade **, unsigned int);

};
