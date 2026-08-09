#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\player\playerprofilegame.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2577; PDB kind: enum.
enum idPlayerProfileGame::displayMode_t : __int32
{
  DISPLAY_INVALID = 0xFFFFFFFF,
  DISPLAY_WINDOWED = 0x0,
  DISPLAY_FULLSCREEN = 0x1,
  MAX_DISPLAY_MODES = 0x2,
};

// IDA Local Type ordinal 2578; PDB kind: enum.
enum idPlayerProfileGame::syncTypes_t : __int32
{
  SYNC_INVALID = 0xFFFFFFFF,
  SYNC_TEAR = 0x0,
  SYNC_ON = 0x1,
  SYNC_SMART = 0x2,
  MAX_SYNC_COUNT = 0x3,
};

// IDA Local Type ordinal 17945; PDB kind: class.
class __declspec(align(8)) idPlayerProfileGame : public idPlayerProfile
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17950.
  virtual ~idPlayerProfileGame();
  virtual void SetDefaults();
  virtual bool Serialize(idSerializer *);
  virtual bool UpdateDisplayModeFromCvars();
  virtual bool CommitDisplayChanges();
  virtual float GetMouseSensitivity();
  virtual int GetLevel();
  virtual int GetChosenEmblem();
  virtual void SetInvertLook(bool);
  virtual unsigned int GetSubtitleLanguageMask();
  virtual void SetChosenEmblem(int);

  bool useSubtitles;
  bool useAimAssist;
  bool useGamepad;
  bool useVibrate;
  float joyXSensitivity;
  float joyYSensitivity;
  int fpsConfigSet;
  unsigned int subtitleMask;
  bool GPUtranscodeEnabled;
  int antristropicFilter;
  float gammaValue;
  bool seenInstallMessage;
  int secretAndProgressStamp;
  unsigned int progressBits[8];
  unsigned int secretBits[64];
  unsigned int completedBits[8];
  idStr savedSpawnMap;
  idStr savedSpawnSpot;
  idStr savedLayers;
  int savedVariationIndex;
  int savedPartIndex;
  idStaticList<idPlayerProfileGame::profileLoadout_t,5> loadouts;
  int chosenEmblem;
  idStaticList<int,100> newEmblems;
  int vdmModeIndex;
  int vdmMapIndex;
  int vdmScoreLimit;
  int vdmTimeLimit;
  bool vdmPrivate;
  int coopMapIndex;
  bool coopPrivate;
  int coopDifficulty;
};

// IDA Local Type ordinal 17946; PDB kind: struct.
struct idPlayerProfileGame::profileLoadout_t
{
  idStrStatic<64> name;
  int slot[6];
};
