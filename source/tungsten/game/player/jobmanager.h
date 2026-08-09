#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\player\jobmanager.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14451; PDB kind: class.
class idJobManager
{
public:
  idList<idJob *,5> jobs;
  idList<idSpecialEvent *,5> specialEvent_Jumps;
  const idDeclSpecialEvent_Area *specialEventAreaDecl;
  idList<idSpecialEvent_Area_Tracker *,5> specialEventAreaTrackers;
  idList<idAIPlayerInteractionMemory *,5> playerInteractionMemories;
  idList<idGameStateInt *,5> gameStateInts;
  idList<idRaceStatusMemory *,5> raceStatusMemories;
  idList<idStr,5> dlcRewardsRecieved;
  idPlayer *owner;
  bool useAlternateHands;
  bool saveRequested;
  int activeJobIndex;
  bool inDebug;
  bool inInitState;
  bool hackNoItemRewards;
  bool hackIgnoreDebugRewards;
  bool hackIgnoreLayerChanges;
  garageList_t newVehicleGarage;
};
