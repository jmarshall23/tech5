#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\guis\swf\swf_spriteinstance.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14786; PDB kind: class.
class idSWFSpriteInstance
{
public:
  bool isPlaying;
  bool isVisible;
  bool childrenRunning;
  bool firstRun;
  unsigned __int16 currentFrame;
  unsigned __int16 frameCount;
  idSWFSprite *sprite;
  idSWFSpriteInstance *parent;
  int depth;
  int itemIndex;
  const idMaterial *materialOverride;
  unsigned __int16 materialWidth;
  unsigned __int16 materialHeight;
  float xOffset;
  float yOffset;
  idSWFScriptObject *scriptObject;
  idList<swfDisplayEntry_t,72> displayList;
  idAtomicString name;
  idList<idSWFSpriteInstance::swfAction_t,72> actions;
  idSWFScriptFunction_Script *actionScript;
  idSWFScriptVar onEnterFrame;
  int followBorder;
};

// IDA Local Type ordinal 14799; PDB kind: struct.
struct idSWFSpriteInstance::swfAction_t
{
  const unsigned __int8 *data;
  unsigned int dataLength;
};

// IDA Local Type ordinal 21856; PDB kind: struct.
struct __declspec(align(4)) idSWFSpriteInstance::placeObject2Data_t
{
  unsigned __int64 flags;
  int depth;
  int characterID;
  idStr name;
  swfMatrix_t matrix;
  swfColorXform_t cxf;
  float ratio;
  unsigned __int16 clipDepth;
};

// IDA Local Type ordinal 21857; PDB kind: struct.
struct __declspec(align(8)) idSWFSpriteInstance::placeObject3Data_t
{
  unsigned __int64 flags;
  unsigned __int16 blendMode;
};
