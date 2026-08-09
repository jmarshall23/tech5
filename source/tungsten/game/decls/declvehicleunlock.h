#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declvehicleunlock.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15542; PDB kind: class.
class idDeclVehicleUnlock : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15545.
  virtual ~idDeclVehicleUnlock();
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

  vehicleUnlockType_t unlockType;
  int levelRequired;
  idStrId displayName;
  int quantity;
  int rangeRank;
  int damageRank;
  int accuracyRank;
  int rateOfFireRank;
  idStrId description;
  const idMaterial *loadoutIcon;
  const idMaterial *bigLoadoutIcon;
  const idDeclVehicleUnlock *upgradeTo;
  int spRequired;
  rageStat_t metricType;
  int ordinal;
  idList<idDeclVehicleUnlock::inventoryUnlock_t,5> items;
};

// IDA Local Type ordinal 15543; PDB kind: struct.
struct idDeclVehicleUnlock::inventoryUnlock_t
{
  idStr itemDeclStr;
  idStr entityDefStr;
  idStr soundDeclStr;
  int count;
  itemUnlockType_t itemType;
  vehicleType_t vehicleType;
};

// IDA Local Type ordinal 18432; PDB kind: class.
class idSort_DeclVehicleUnlockPtr_ByName : public idSort_Quick<idDeclVehicleUnlock const *,idSort_DeclVehicleUnlockPtr_ByName>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18433.
  virtual ~idSort_DeclVehicleUnlockPtr_ByName();
  virtual void Sort(const idDeclVehicleUnlock **, unsigned int);

};
