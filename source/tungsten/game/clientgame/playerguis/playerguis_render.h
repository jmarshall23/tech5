#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\clientgame\playerguis\playerguis_render.h
// Recovered logical types: 6
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1271; PDB kind: enum.
enum idPlayerGuis_Render::playerGuis_t : __int32
{
  GUI_TEXT_CHAT = 0x0,
  GUI_GAMEOVER = 0x1,
  GUI_NUM_GUIS = 0x2,
};

// IDA Local Type ordinal 15324; PDB kind: struct.
struct idPlayerGuis_Render::playerGuisInfo_t::objectiveResults_t::playerResults_t
{
  int score;
  int kills;
  int multiKills;
  int headshotKills;
  int assists;
  int defends;
  int revives;
};

// IDA Local Type ordinal 15325; PDB kind: struct.
struct idPlayerGuis_Render::playerGuisInfo_t::objectiveResults_t
{
  bool show;
  int earnedCash;
  int killCount;
  int killBonus;
  int itemCount;
  int itemBonus;
  int collectNum;
  int collectMax;
  int time;
  int parTime;
  int bonusCash;
  int totalCash;
  idPlayerGuis_Render::playerGuisInfo_t::objectiveResults_t::playerResults_t playerObjectives[2];
  int totalTime;
  int collectibles;
  int collectiblesMax;
  int collectibleBonusScore;
  int finalScore;
  int rating;
};

// IDA Local Type ordinal 15326; PDB kind: struct.
struct idPlayerGuis_Render::playerGuisInfo_t
{
  idPlayerGuis_Render::playerGuisInfo_t::objectiveResults_t objectiveResults;
};

// IDA Local Type ordinal 15327; PDB kind: class.
class idPlayerGuis_Render
{
public:
  idPlayerGuis_Render::playerGuisInfo_t playerGuiInfo;
  idSWF *guis[2];
  int playerNum;
  idStr textChatHistory;
};

// IDA Local Type ordinal 20329; PDB kind: class.
class idPlayerGuis_Render::Init::__l15::idSWFScriptFunction_SendChatText : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20330.
  virtual ~idSWFScriptFunction_SendChatText();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPlayerGuis_Render *owner;
};
