#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\physics\tracemodelcache.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14116; PDB kind: struct.
struct idTraceModelCache::trmCache_t
{
  idTraceModel *trm;
  int refCount;
  float volume;
  idVec3 centerOfMass;
  idMat3 inertiaTensor;
  const idMaterial *material;
  idCollisionModel *collisionModel;
  bool hasWater;
  idList<traceModelWater_t,54> waterPoints;
};

// IDA Local Type ordinal 14121; PDB kind: class.
class idTraceModelCache
{
public:
  idStr mapName;
  idBlockAlloc<idTraceModelCache::trmCache_t,64,13> cacheAllocator;
  idList<idTraceModelCache::trmCache_t *,13> cache;
  idHashIndex hash;
};
