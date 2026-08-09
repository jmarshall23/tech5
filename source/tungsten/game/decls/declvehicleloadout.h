#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declvehicleloadout.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17942; PDB kind: class.
class idDeclVehicleLoadout : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17943.
  virtual ~idDeclVehicleLoadout();
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

  idStrId desc;
  const idDeclVehicleUnlock *vehicleClass;
  const idDeclVehicleUnlock *vehicle;
  const idDeclVehicleUnlock *weaponPrimary;
  const idDeclVehicleUnlock *weaponSecondary;
  const idDeclVehicleUnlock *quickUse1;
  const idDeclVehicleUnlock *quickUse2;
  bool isDefault;
  int order;
};
