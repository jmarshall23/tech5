#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declgore.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13305; PDB kind: class.
class idDeclSource
{
public:
  idAtomicString name;
  idDeclFile *sourceFile;
  int sourceLine;
  idDeclSource *nextInFile;
  bool isStatic;
  int sourceTextOffset;
  int sourceTextLength;
};

// IDA Local Type ordinal 15460; PDB kind: class.
class idDeclGore : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15461.
  virtual ~idDeclGore();
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

  idList<idGorePieceInfo_t,5> gorePieces;
  idList<deferredDecalParams_t,5> damageSplatterDecals;
  idList<idDeclEntityDef *,5> fullBodyBreakableGibs;
  idGoreDeathFade deathFadeInfo;
};
