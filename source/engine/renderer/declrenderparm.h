#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\declrenderparm.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13548; PDB kind: class.
class idDeclRenderParm : public idDecl
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13549.
  virtual ~idDeclRenderParm();
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

  int parmIndex;
  parmType_t parmType;
  parmCreator_t creator;
  bool cubeFilterTexture;
  parmValue_t declaredValue;
  parmEdit_t edit;
  float editRange[2];
};
