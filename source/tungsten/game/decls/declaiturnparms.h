#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declaiturnparms.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16670; PDB kind: class.
class __declspec(align(4)) idDeclAITurnParms : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16671.
  virtual ~idDeclAITurnParms();
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

  idStr baseTurnName;
  int turnDelay;
  float extraAngleScale;
  float maxAngle;
  bool allowTurns;
  bool allowCrouchedTurns;
  bool allowSittingTurns;
  bool predictTurns;
  bool turnToFocus;
};
