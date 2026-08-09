#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\clientgame\gamelayermanager.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14465; PDB kind: class.
class __declspec(align(4)) idGameLayerManager
{
public:
  idList<idEntityRetainedState,5> entityRetainedStates;
  idList<idRetainedItemMemoryForMap,5> retainedItemMemoryForMap;
  idPlayer *owner;
  idList<idLayer,5> playerLayers;
  idList<idStr,5> layers_DeactiveToActive;
  idList<idStr,5> layers_ActiveToDeactivate;
  idList<idStr,5> layers_ToRemove;
  idList<idStr,5> layers_ToRemoveFromGameLocalLists;
  idList<idStr,5> layers_ToMarkActiveNextMapLoad;
  idList<idStr,5> layers_ToMarkDeactiveNextMapLoad;
  bool inDebug;
  bool inInitState;
};
