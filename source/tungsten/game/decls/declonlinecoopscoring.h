#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declonlinecoopscoring.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 20143; PDB kind: struct.
struct idDeclOnlineCoopScoring::cooptScoring_Event_t
{
  float assistPct;
  int enemyKill;
  int enemyHeadhshotKill;
  int enemySpecialKill;
  int heavyKill;
  int heavyHeadhshotKill;
  int heavySpecialKill;
  int doubleKill;
  int tripleKill;
  int quadKill;
  int killingSpree;
  int collectiableBonus;
};

// IDA Local Type ordinal 20144; PDB kind: struct.
struct idDeclOnlineCoopScoring::coopScoring_Multiplier_t::damageMultiplierTable_t
{
  float multiplier;
  int numTimesHit;
};

// IDA Local Type ordinal 20146; PDB kind: struct.
struct idDeclOnlineCoopScoring::coopScoring_Multiplier_t
{
  float normalDamageMultiplierPointsFactor;
  float headshotDamageMultiplierPointsFactor;
  float takenNormalDamageScale;
  float takenMeleeDamageScale;
  float takenProjectileDamageScale;
  float takenDamageMultiplierScale;
  int assistPoints;
  int revengePoints;
  int comboPoints;
  int defendPoints;
  int covertPoints;
  int brutalPoints;
  int incapacitatePoints;
  int incapacitatePointsPerSecond;
  float revivePCTPoints;
  int idlePointsPerSecond;
  float idlePointsStartupTime;
  idList<idDeclOnlineCoopScoring::coopScoring_Multiplier_t::damageMultiplierTable_t,5> takenDamageTable;
  int takenDamageResetTime;
};

// IDA Local Type ordinal 20147; PDB kind: class.
class idDeclOnlineCoopScoring : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20148.
  virtual ~idDeclOnlineCoopScoring();
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

  idDeclOnlineCoopScoring::cooptScoring_Event_t events;
  idDeclOnlineCoopScoring::coopScoring_Multiplier_t multiplier;
  int multiplierPointsPerLevel;
  int multiplierPointsLevelBuffer;
  int maxMultiplierPoints;
  const idDeclOnlineScoringCallout *multiplierUpCallout;
  const idDeclOnlineScoringCallout *multiplierDownCallout;
  const idDeclOnlineScoringCallout *headshotCallout;
  const idDeclOnlineScoringCallout *defendCallout;
  const idDeclOnlineScoringCallout *assistCallout;
  const idDeclOnlineScoringCallout *revengeCallout;
  const idDeclOnlineScoringCallout *comboCallout;
  const idDeclOnlineScoringCallout *brutalCallout;
  const idDeclOnlineScoringCallout *covertCallout;
  const idDeclOnlineScoringCallout *doubleKillCallout;
  const idDeclOnlineScoringCallout *tripleKillCallout;
  const idDeclOnlineScoringCallout *quadKillCallout;
  const idDeclOnlineScoringCallout *killingSpreeCallout;
  const idDeclOnlineScoringCallout *collectableCallout;
};
