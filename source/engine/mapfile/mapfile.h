#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\mapfile\mapfile.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15161; PDB kind: class.
class __declspec(align(4)) idMapFile
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15162.
  virtual ~idMapFile();

  idStr name;
  int version;
  unsigned int fileTime;
  unsigned int geometryCRC;
  bool hasPrimitiveData;
  idList<idMapEntity *,5> entities;
  idMapEditorStates groupStates;
  idList<idRefMapDef,5> referenceMaps;
  idMapEntity *parentReference;
  bool expandReferences;
  idGame *game;
  bool entitiesAreReference;
  bool ignoreGroupInfo;
};
