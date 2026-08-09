#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\effectphysics\effectphysicsbroadphase.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14572; PDB kind: class.
class idEffectPhysicsBroadPhase::idSPMarker
{
public:
  __int16 value;
  unsigned __int16 data;
};

// IDA Local Type ordinal 14574; PDB kind: class.
class idEffectPhysicsBroadPhase
{
public:
  idClip *clip;
  idTraceModelCache *traceModelCache;
  idList<idSPObject *,59> objects;
  idList<idEffectPhysicsBroadPhase::idSPMarker,59> markers[3];
};
