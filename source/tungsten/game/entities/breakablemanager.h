#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\breakablemanager.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16474; PDB kind: struct.
struct idBreakableManager::breakables_t
{
  idStaticList<idEntity *,16> entity;
  int next;
};

// IDA Local Type ordinal 16477; PDB kind: class.
class idBreakableManager
{
public:
  idStaticList<idBreakableManager::breakables_t,16> breakable;
};
