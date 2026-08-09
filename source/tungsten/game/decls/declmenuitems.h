#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declmenuitems.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16054; PDB kind: class.
class idDeclDevMenuList : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16058.
  virtual ~idDeclDevMenuList();
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

  idList<idDeclDevMenuList::idDevMenuOption,5> devMenuList;
};

// IDA Local Type ordinal 16056; PDB kind: class.
class idDeclDevMenuList::idDevMenuOption
{
public:
  idStr devMenuDisplayName;
  const idDeclDevMenuList *devMenuSubList;
  idStrMapName devMenuMapName;
  bool devMenuLoadMapAsMP;
  idList<idStr,5> devMenuCommandStrings;
  idStr devMenuSpawnSpot;
  idDeclRaceDescRef devMenuRaceDescDecl;
  idDeclJobRef devMenuMissionDecl;
  simpleMissionStatus_t devMenuMissionStatus;
  idList<idDeclLayer const *,5> devMenuAddActiveLayers;
  idList<idDeclLayer const *,5> devMenuRemoveActiveLayers;
  idStr devMenuActiveLayers;
  idList<idDeclLayer const *,5> devMenuAddDeactiveLayers;
  idList<idDeclLayer const *,5> devMenuRemoveDeactiveLayers;
  idStr devMenuDeactiveLayers;
};

// IDA Local Type ordinal 18381; PDB kind: class.
class idDeclMenuItem : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18382.
  virtual ~idDeclMenuItem();
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

  const idMaterial *material;
  idStr title;
  idStr help;
  vehicleLoadoutSlot_t loadoutSlot;
  int index;
};
