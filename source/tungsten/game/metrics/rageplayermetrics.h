#pragma once

#include "levelstats.h"

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\metrics\rageplayermetrics.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15539; PDB kind: class.
class idRagePlayerMetrics : public idEventReceiver
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15540.
  virtual idTypeInfo *GetType();
  virtual ~idRagePlayerMetrics();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);

  idStaticList<idRageStat,256> stats;
  idEventReceiver *eventListener;
  int entityNumber;
  int lastKillTimestamp;
  int currentKillStreak;
  int killsThisLife;
  int currentRallyStreak;
  float kdr;
  int shieldActivationTime;
  bool inGame;
  bool isAchievementReady;
  int spawnTimestamp;
  int bullyTimestamp;
  int maxChainTimestamp;
  idVec3 origin;
  bool allowSpecialKill;
  idList<weaponQueueEntry_t,5> weaponQueue;
  weaponQueueEntry_t lastHit;
  int shotId;
  int timeBucket;
  idLevelStats levelStats;
};
