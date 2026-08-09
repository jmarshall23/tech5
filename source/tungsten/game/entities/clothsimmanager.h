#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\clothsimmanager.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1528; PDB kind: enum.
enum idClothSimManager::clothSims_t::state_t : __int32
{
  READY_TO_USE = 0x0,
  READY_TO_FREE = 0x1,
};

// IDA Local Type ordinal 16498; PDB kind: struct.
struct idClothSimManager::clothSims_t
{
  idClothSimManager::clothSims_t::state_t state;
  idClothSim *clothSim;
};

// IDA Local Type ordinal 16501; PDB kind: class.
class idClothSimManager
{
public:
  idStaticList<idClothSimManager::clothSims_t,16> cloth;
};
