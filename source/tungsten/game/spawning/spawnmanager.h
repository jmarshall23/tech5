#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\spawning\spawnmanager.h
// Recovered logical types: 6
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1141; PDB kind: enum.
enum idSpawnManager::Command::commandState_t : __int32
{
  CS_GENERATE_LOCATIONS = 0x0,
  CS_EVALUATE_LOCATIONS = 0x1,
  CS_JITTER_AND_SORT_LOCATIONS = 0x2,
  CS_FIND_BEST_LOCATION = 0x3,
  CS_COMPLETE_COMMAND = 0x4,
  CS_FAIL_COMMAND = 0x5,
};

// IDA Local Type ordinal 15565; PDB kind: class.
class idSpawnManager
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15575.
  virtual ~idSpawnManager();
  virtual idSpawnManager::CommandExecutor *GetExecutor(int);

  idCircularBuffer<idSpawnManager::Command,128> commandQueue;
  idSpawnManager::Context context;
  idHandleArray<idSpawnResult,10> spawnResults;
  int debugHighestValueIndex;
  float debugValueDiff;
  float debugLowestValue;
  float debugFlashTimer;
  float debugNodeTimeout;
};

// IDA Local Type ordinal 15566; PDB kind: class.
class idSpawnManager::CommandExecutor
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15574.
  virtual ~CommandExecutor();
  virtual void GenerateLocations(const idSpawnManager::Command *, const idSpawnManager::Context *, idList<idSpawnLocation,5> *);
  virtual bool EvaluateContext(const idSpawnManager::Command *, idSpawnManager::Context *);
  virtual const idVec3 *GetActorSize(const idVec3 *result, const idSpawnManager::Command *);
  virtual idEntity *Complete(const idSpawnManager::Command *, const idSpawnManager::Context *, const idSpawnLocation *);
  virtual void Fail(const idSpawnManager::Command *, const idSpawnManager::Context *);

};

// IDA Local Type ordinal 15567; PDB kind: class.
class idSpawnManager::Command
{
public:
  idSpawnManager::Command::commandState_t state;
  int type;
  int dataIndex;
  unsigned int resultHandle;
};

// IDA Local Type ordinal 15573; PDB kind: class.
class idSpawnManager::Context
{
public:
  idList<idSpawnLocation,5> spawnLocations;
  int currentLocationIndex;
  float minLocationValue;
  float maxLocactionValue;
};

// IDA Local Type ordinal 15583; PDB kind: class.
class idSpawnManager::CommandExecutorT<idSpawnPlayerCmdData> : public idSpawnManager::CommandExecutor
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15584.
  virtual ~CommandExecutorT();
  virtual void GenerateLocations(const idSpawnManager::Command *, const idSpawnManager::Context *, idList<idSpawnLocation,5> *);
  virtual bool EvaluateContext(const idSpawnManager::Command *, idSpawnManager::Context *);
  virtual const idVec3 *GetActorSize(const idVec3 *result, const idSpawnManager::Command *);
  virtual idEntity *Complete(const idSpawnManager::Command *, const idSpawnManager::Context *, const idSpawnLocation *);
  virtual void Fail(const idSpawnManager::Command *, const idSpawnManager::Context *);

  idList<int,5> freeDataIndices;
  idList<idSpawnPlayerCmdData,5> dataArray;
};
