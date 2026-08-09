#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\animation\declfacialanimationset.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15189; PDB kind: class.
class idDeclFacialAnimationSet : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15190.
  virtual ~idDeclFacialAnimationSet();
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

  idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,5> normalGlances;
  idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,5> squintGlances;
  idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,5> ambientCycles;
  idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,5> ambientFidgets;
  idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,5> focusCycles;
  idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,5> focusFidgets;
};
