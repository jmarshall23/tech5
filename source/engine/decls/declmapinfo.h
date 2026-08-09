#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\declmapinfo.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13304; PDB kind: class.
class idDeclInfo : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13309.
  virtual ~idDeclInfo();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();
  virtual idDecl *AllocDecl();

  const char *name;
  const char *classname;
  const char *fileExtension;
  idAtomicString nameExtension;
  idAtomicString defaultFolder;
  idDeclInfo *parent;
  void (__fastcall *onReload)(const idDecl *);
  idList<idDeclSource *,46> declSources;
  idHashIndex declSourceHash;
  int declSourceDynamicStartIndex;
};

// IDA Local Type ordinal 17938; PDB kind: class.
class idDeclMapInfo::loadingVideos_t
{
public:
  idAtomicString layerMask;
  idAtomicString videoFile;
};

// IDA Local Type ordinal 17940; PDB kind: class.
class idDeclMapInfo : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17941.
  virtual ~idDeclMapInfo();
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

  idStrId prettyMapName;
  int discNumber;
  int dlcId;
  idList<idDeclMapInfo::loadingVideos_t,5> loadingVideos;
};
