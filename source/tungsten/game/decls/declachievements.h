#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declachievements.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14992; PDB kind: struct.
struct idDeclAchievement::flags_t
{
  unsigned __int8 : 3;
  __int8 sys_mac : 1;
  __int8 sys_ps3 : 1;
  __int8 sys_xbox : 1;
  __int8 sys_pc : 1;
  __int8 internalUse : 1;
};

// IDA Local Type ordinal 14993; PDB kind: struct.
struct idDeclAchievement::inventoryAchievement_t
{
  idStr itemDecl;
  int count;
};

// IDA Local Type ordinal 14996; PDB kind: struct.
struct idDeclAchievement::raceAchievement_t
{
  idStr raceName;
  raceMemoryPlace_t place;
};

// IDA Local Type ordinal 14998; PDB kind: struct.
struct idDeclAchievement::statConstraint_t
{
  rageStat_t stat;
  int count;
};

// IDA Local Type ordinal 15001; PDB kind: class.
class idDeclAchievement : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15002.
  virtual ~idDeclAchievement();
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

  idStrId achievementName;
  idStrId description;
  achievementId_t id;
  idDeclAchievement::flags_t flags;
  idList<idDeclAchievement::inventoryAchievement_t,5> item;
  idList<idDeclJobRef,5> jobDecl;
  idList<enum triggerAchievementId_t,5> trigger;
  idList<idDeclAchievement::raceAchievement_t,5> races;
  bool allRacesRequired;
  idList<idDeclAchievement::statConstraint_t,5> events;
  bool allEventsRequired;
  idList<enum achievementId_t,5> achievements;
  avatarAward_t avatarAwardId;
};
