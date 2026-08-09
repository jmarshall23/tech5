#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declmetrics.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15396; PDB kind: class.
class idDeclMetric : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15397.
  virtual ~idDeclMetric();
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

  rageStat_t stat;
  rageStatAggregationMethod aggregate;
  idList<idStr,5> weaponDecls;
  bool isWeaponStat;
  int xp;
  idList<rageStatXpBonus,5> xpBonus;
  idStrId displayName;
};
