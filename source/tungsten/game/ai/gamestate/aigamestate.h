#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\gamestate\aigamestate.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16546; PDB kind: class.
class idAIGameState
{
public:
  idArray<aiLatchedState_t *,8192> entStates;
  idArray<aiLatchedEvent_t *,256> events;
  idList<idSpawnId,5> forcedLatches;
  idBlockAlloc<aiLatchedState_t,256,63> stateAllocator;
  idBlockAlloc<aiLatchedEvent_t,64,63> eventAllocator;
  int gameTime;
  int gameFrame;
  int numEvents;
  int garbageIndex;
};
