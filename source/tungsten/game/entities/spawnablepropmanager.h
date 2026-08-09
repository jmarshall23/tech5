#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\spawnablepropmanager.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16494; PDB kind: struct.
struct idSpawnablePropManager::spawnables_t
{
  idStaticList<idProp_Spawnable *,4> entity;
  int next;
};

// IDA Local Type ordinal 16497; PDB kind: class.
class idSpawnablePropManager
{
public:
  idStaticList<idSpawnablePropManager::spawnables_t,8> spawnable;
};
