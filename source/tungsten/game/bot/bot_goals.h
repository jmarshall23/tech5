#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\bot\bot_goals.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14985; PDB kind: struct.
struct idBotGoal::goalCombatSettings_t
{
  float combatMaxRange;
};

// IDA Local Type ordinal 14986; PDB kind: class.
class idBotGoal
{
public:
  bool goalEnemyLocked;
  idBotGoal::goalCombatSettings_t goalCombatSettings;
  int goalEnemyTargetRecordIndex;
  idBitFlag32 goalType;
  idEntityPtr<idEntity> goalEnemy;
  idEntityPtr<idEntity> goalEntity;
  float goalRadius;
  idVec3 goalPosition;
};
