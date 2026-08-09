#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\animwebs\declanimwebnode.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1347; PDB kind: enum.
enum idDeclAnimWebNode::nodeFlag_t : __int32
{
  NODEFLAG_START_TRANSITION = 0x1,
  NODEFLAG_STOP_TRANSITION = 0x2,
  NODEFLAG_STEP_TRANSITION = 0x4,
  NODEFLAG_TURN_TRANSITION = 0x8,
  NODEFLAG_BLENDOUT = 0x10,
  NODEFLAG_ADDITIVECAMERA = 0x20,
  NODEFLAG_GENERIC_TRANSITION = 0x40,
  NODEFLAG_HIDE = 0x80,
};

// IDA Local Type ordinal 1359; PDB kind: enum.
enum idDeclAnimWebNode::animDelta_t : __int32
{
  ANIMDELTA_DEFAULT = 0x0,
  ANIMDELTA_FULL = 0x1,
  ANIMDELTA_FULL_NOCLIP = 0x2,
  ANIMDELTA_FULL_GRAVITY = 0x3,
  ANIMDELTA_TURN = 0x4,
  ANIMDELTA_FULL_VELOCITY = 0x5,
  ANIMDELTA_FULL_DRIVE_AI = 0x6,
  ANIMDELTA_IGNORE = 0x7,
  ANIMDELTA_MAX = 0x8,
};

// IDA Local Type ordinal 15042; PDB kind: class.
class idDeclAnimWebNode::idModelInfo
{
public:
  idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> modelIndex;
  idAtomicString blendEq;
  idAtomicString blendEqFixed;
  idList<idMD6AnimProps,32> animProps;
  idList<float,32> *coordinates;
  idList<idDeclAnimWebTagGroup,32> *tagGroups;
};

// IDA Local Type ordinal 15044; PDB kind: struct.
struct idDeclAnimWebNode::toolSettings_t
{
  idVec3 pos;
};

// IDA Local Type ordinal 15045; PDB kind: class.
class idDeclAnimWebNode
{
public:
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> nodeIndex;
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> subWebIndex;
  idDeclAnimWeb::stateList_t states;
  unsigned __int8 animDelta;
  unsigned __int8 flags;
  unsigned __int16 customFlags;
  idList<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,32> edges;
  idList<idDeclAnimWebNode::idModelInfo,32> modelInfo;
  idDeclAnimWebNode::toolSettings_t settings;
};
