#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declemblems.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2094; PDB kind: enum.
enum idDeclEmblem::emblemCategory_t : __int32
{
  EMBLEM_COOP = 0x0,
  EMBLEM_VDM = 0x1,
};

// IDA Local Type ordinal 17910; PDB kind: class.
class idDeclEmblem : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17911.
  virtual ~idDeclEmblem();
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
  idList<idDeclAchievement::statConstraint_t,5> requirements;
  bool allEventsRequired;
  idDeclEmblem::emblemCategory_t category;
  idStrId unlockDescription;
  int index;
};

// IDA Local Type ordinal 20271; PDB kind: class.
class idSort_DeclEmblemPtr : public idSort_Quick<idDeclEmblem const *,idSort_DeclEmblemPtr>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20272.
  virtual ~idSort_DeclEmblemPtr();
  virtual void Sort(const idDeclEmblem **, unsigned int);

};
