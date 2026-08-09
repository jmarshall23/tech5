#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\gamestate\aientitystate.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2654; PDB kind: enum.
enum idAIEntityState::aiEntityStateFlags_t : __int32
{
  AIESFL_VALID = 0x1,
  AIESFL_NEWLY_AWARE = 0x2,
};

// IDA Local Type ordinal 15965; PDB kind: class.
class idAIEntityState : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15966.
  virtual idTypeInfo *GetType();
  virtual ~idAIEntityState();

  idAISenseState_Hearing hearingSense;
  idAISenseState_Sight sightSense;
  idArray<aiSenseState_t *,2> senses;
  idSpawnId spawnId;
  int initTime;
  int visChangeTime;
  float lastVisualStimulus;
  unsigned __int8 highestAwareness;
  unsigned __int8 curAwareness;
  unsigned __int8 lastSense;
  unsigned __int8 lastVisible;
  unsigned __int8 entityType;
  unsigned __int8 : 6;
  __int8 newlyAware : 1;
  __int8 valid : 1;
  idAASPosition aasPosition;
};

// IDA Local Type ordinal 15967; PDB kind: struct.
struct idAIEntityState::aiDefVisInfo_t
{
  idClipQuery eyeQuery;
  idClipQuery boundsQuery;
  idVec3 delta;
  float fovWeight;
  int entityNum;
  bool closeEnough;
  idClipQuery lastSeenPosQuery;
};

// IDA Local Type ordinal 20495; PDB kind: struct.
struct __declspec(align(4)) idAIEntityState::stimulusToSense_t
{
  aiSense_t sense;
  aiAwareness_t awareness;
  bool trigger;
};
