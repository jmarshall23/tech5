#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\skeletalanimation\md6animevent.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13388; PDB kind: class.
class __declspec(align(4)) idMD6AnimEvent
{
public:
  idVarArgs<4> args;
  idCachedJoint *cachedJoint;
  __int16 eventNum;
  __int16 frameNum;
  idHandle<unsigned int,enum invalidAnimEventId_t,0> eventId;
  bool locked;
  unsigned __int8 row;
};
