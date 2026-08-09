#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\cover\coveractions.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1578; PDB kind: enum.
enum coverAction_t : __int32
{
  COVERACTION_NONE = 0x0,
  COVERACTION_FIRE_OVER = 0x1,
  COVERACTION_FIRE_LEAN_LEFT = 0x2,
  COVERACTION_FIRE_LEAN_RIGHT = 0x3,
  COVERACTION_FIRE_STEP_LEFT = 0x4,
  COVERACTION_FIRE_STEP_RIGHT = 0x5,
  COVERACTION_BLINDFIRE_OVER = 0x6,
  COVERACTION_BLINDFIRE_LEFT = 0x7,
  COVERACTION_BLINDFIRE_RIGHT = 0x8,
  COVERACTION_PEEK_OVER = 0x9,
  COVERACTION_PEEK_LEFT = 0xA,
  COVERACTION_PEEK_RIGHT = 0xB,
  COVERACTION_HIDE = 0xC,
  COVERACTION_RAIL_DOWN = 0xD,
  COVERACTION_RAIL_UP = 0xE,
  COVERACTION_RAIL_LEFT = 0xF,
  COVERACTION_RAIL_RIGHT = 0x10,
  COVERACTION_MAX = 0x11,
};

// IDA Local Type ordinal 16658; PDB kind: class.
class __declspec(align(4)) idCoverActions
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16659.
  virtual ~idCoverActions();
  virtual void Clear();

  unsigned __int8 : 3;
  __int8 fireStepRight : 1;
  __int8 fireLeanRight : 1;
  __int8 fireStepLeft : 1;
  __int8 fireLeanLeft : 1;
  __int8 fireOver : 1;
};

// IDA Local Type ordinal 19842; PDB kind: class.
class idCoverTransitions
{
public:
  __int8 jumpover : 1;
  __int8 wrapAroundRight : 1;
  __int8 turnAroundRight : 1;
  __int8 right : 1;
  __int8 wrapAroundLeft : 1;
  __int8 turnAroundLeft : 1;
  __int8 left : 1;
  __int8 forward : 1;
};

// IDA Local Type ordinal 20868; PDB kind: struct.
struct __declspec(align(4)) coverOptions_t
{
  coverAction_t coverAction;
  bool sameSide;
  bool avoid;
};
