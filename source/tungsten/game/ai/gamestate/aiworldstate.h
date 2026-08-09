#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\gamestate\aiworldstate.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1695; PDB kind: enum.
enum idAIWorldState::visibilityEffectsMask_t : __int32
{
  VBE_DISTANCE = 0x1,
  VBE_FACING = 0x2,
  VBE_CROUCHING = 0x4,
  VBE_COVER = 0x8,
  VBE_DISPLACEMENT = 0x10,
  VBE_SPEED = 0x20,
  VBE_LIGHT = 0x40,
  VBE_MAP = 0x80,
  VBE_CAMOUFLAGE = 0x100,
  VBE_AWARENESS = 0x200,
  VBE_SIZE = 0x400,
  VBE_ALL = 0xFFFFFFFF,
};

// IDA Local Type ordinal 15973; PDB kind: class.
class __declspec(align(8)) idAIWorldState : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15974.
  virtual idTypeInfo *GetType();
  virtual ~idAIWorldState();

  idIndex<signed char,enum invalidEntityStateIndex_t> ents[8];
  idIndex<signed char,enum invalidEntityStateIndex_t> freeEnts[8];
  __int16 numEnts;
  __int16 numFreeEnts;
  idAIEntityState entityStates[8];
  idList<idAIEntityState::aiDefVisInfo_t,5> aiDeferredVisInfo;
  idList<idAIEntityState::aiDefVisInfo_t,5> aiDeferredRefreshInfo;
  idGatherQuery gatherQuery;
  idTargetCache targetCache;
  int lastUpdateFrameNum;
  idVec3 lastUpdatePos;
  float radius;
  float visibleSightTime;
  int friendlyVisibilityEffectsMask;
  int enemyVisibilityEffectsMask;
  int initialUpdateCount;
  bool updateFriendly;
  bool refreshFriendly;
  bool bOwnerAiInCover;
};
