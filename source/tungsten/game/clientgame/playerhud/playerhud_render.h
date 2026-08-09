#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15322; PDB kind: class.
class idPlayerHud_Render
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15323.
  virtual ~idPlayerHud_Render();

  idSWF *hud;
  bool showScoreboard;
  int playerNum;
  int minigameResult;
  int minigameStage;
  float minigameRangeIndicator;
};
