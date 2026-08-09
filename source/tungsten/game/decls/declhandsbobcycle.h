#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declhandsbobcycle.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 20199; PDB kind: class.
class __declspec(align(2)) idDeclHandsBobCycle : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20200.
  virtual ~idDeclHandsBobCycle();
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

  idAtomicString subweb;
  idHandsBobCycleSingleCycleData_t idleData;
  idHandsBobCycleSingleCycleData_t runData;
  idHandsBobCycleSingleCycleData_t sprintData;
  idHandsBobCycleSingleCycleData_t crouchData;
  idHandsBobCycleSingleCycleData_t zoomData;
  idHandsBobCycleSingleCycleData_t pdaData;
  bool scaleAlphaWithSpeed;
  bool hasSprint;
  bool inited;
};
