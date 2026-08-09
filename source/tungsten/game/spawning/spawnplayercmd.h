#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\spawning\spawnplayercmd.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15581; PDB kind: class.
class idSpawnPlayerCmdData
{
public:
  int playerIndex;
  gameTeam_t allowedTeams;
  int loadoutIndex;
  const idSpawnNodeGroup *spawnNodeGroup;
  bool teleport;
  bool onlyInitialNodes;
  void *userdata;
};

// IDA Local Type ordinal 15585; PDB kind: struct.
struct idSpawnPlayerCmd::deferredVisibilityQuery_t
{
  idClipQuery visibilityQuery;
  int locationIndex;
  float valueModifier;
};

// IDA Local Type ordinal 15587; PDB kind: class.
class idSpawnPlayerCmd : public idSpawnManager::CommandExecutorT<idSpawnPlayerCmdData>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15588.
  virtual ~idSpawnPlayerCmd();
  virtual void GenerateLocations(const idSpawnManager::Command *, const idSpawnManager::Context *, idList<idSpawnLocation,5> *);
  virtual bool EvaluateContext(const idSpawnManager::Command *, idSpawnManager::Context *);
  virtual const idVec3 *GetActorSize(const idVec3 *result, const idSpawnManager::Command *);
  virtual idEntity *Complete(const idSpawnManager::Command *, const idSpawnManager::Context *, const idSpawnLocation *);
  virtual void Fail(const idSpawnManager::Command *, const idSpawnManager::Context *);

  idList<idVec3,5> hostileGrenadeLocations;
  idList<float,5> hostileGrenadesDangerRadiusSq;
  idVec3 raycastOffset;
  idList<idSpawnPlayerCmd::deferredVisibilityQuery_t,5> deferredVisibilityQueries;
};
