#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declaiinteraction.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2352; PDB kind: enum.
enum idDeclAIInteraction::interactionEvent_t : __int32
{
  IEV_ACTIONSCRIPT = 0x0,
  IEV_MAX = 0x1,
};

// IDA Local Type ordinal 20188; PDB kind: struct.
struct idDeclAIInteraction::eventData_t
{
  idDeclAIInteraction::interactionEvent_t type;
  int timeMS;
  int durationMS;
  int actorIndex;
  idList<idScriptAction,5> actionScript;
};

// IDA Local Type ordinal 20190; PDB kind: class.
class idDeclAIInteraction : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20191.
  virtual ~idDeclAIInteraction();
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

  idList<idDeclAIInteraction::eventData_t,5> events;
};
