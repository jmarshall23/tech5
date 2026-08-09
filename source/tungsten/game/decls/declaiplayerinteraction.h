#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declaiplayerinteraction.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16623; PDB kind: class.
class idDeclAIPlayerInteraction : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16624.
  virtual ~idDeclAIPlayerInteraction();
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

  float approachRadius;
  float departureRadius;
  float lookAheadTime;
  idList<aiPlayerInteraction_t,5> interactList;
};
