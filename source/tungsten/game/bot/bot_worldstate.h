#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\bot\bot_worldstate.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14961; PDB kind: class.
class idBotWorldState
{
public:
  int enemyCheckDebounce;
  int lastEnemyUpdateTime;
  int lastAttackerTime;
  int lastUpdatedEntityListHandle;
  float fov;
  idBotTargetFilter *targetFilter;
  idBot *owner;
  idEntityPtr<idEntity const > lastAttacker;
  idList<idBotTargetRecord,5> targetRecords;
};
