#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\bot\global\bot_tracemanager.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16515; PDB kind: struct.
struct idBotTraceManager::perceptionData_t
{
  int lastSeenTime;
  int lastUpdateTime;
};

// IDA Local Type ordinal 16516; PDB kind: struct.
struct idBotTraceManager::entityData_t
{
  int lastUpdateTime;
  idEntityPtr<idEntity const > ent;
};

// IDA Local Type ordinal 16517; PDB kind: struct.
struct idBotTraceManager::traceWorkData_t
{
  int srcIndex;
  int targetIndex;
  idClipQuery clipQuery;
};

// IDA Local Type ordinal 16518; PDB kind: class.
class idBotTraceManager
{
public:
  int curEntDataIndex;
  int curTraceIndex;
  int numActiveTraces;
  idBotTraceManager::perceptionData_t perceptionTable[6][32];
  idBotTraceManager::entityData_t entityData[32];
  idBotTraceManager::traceWorkData_t traceWorkData[8];
  idStaticList<int,6> playerUpdateIndexes;
};
