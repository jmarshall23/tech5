#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aigui.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2356; PDB kind: enum.
enum aiGuiInfo_t::aiState_t : __int32
{
  STATE_ALIVE = 0x0,
  STATE_HIDDEN = 0x2,
};

// IDA Local Type ordinal 17305; PDB kind: class.
class __declspec(align(4)) idAIGUI
{
public:
  idList<idGuiPage *,5> pages;
  idList<idGuiPage *,5> debugPages;
  idRenderModelGui *guiModel;
  bool initialized;
};

// IDA Local Type ordinal 21448; PDB kind: struct.
struct aiGuiInfo_t
{
  idEntity *ai;
  aiGuiInfo_t::aiState_t aiState;
};
