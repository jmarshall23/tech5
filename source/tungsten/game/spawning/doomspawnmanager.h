#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\spawning\doomspawnmanager.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1142; PDB kind: enum.
enum idDoomSpawnManager::commandType_t : __int32
{
  CT_SPAWN_PLAYER = 0x0,
  CT_SPAWN_PLAYER_INITIAL = 0x1,
  NUM_SPAWN_CMD_TYPES = 0x2,
};

// IDA Local Type ordinal 15589; PDB kind: class.
class idDoomSpawnManager : public idSpawnManager
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15590.
  virtual ~idDoomSpawnManager();
  virtual idSpawnManager::CommandExecutor *GetExecutor(int);

  idSpawnPlayerCmd spawnPlayerCmd;
};
