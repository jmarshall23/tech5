#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\playerprofile.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1505; PDB kind: enum.
enum idPlayerProfile::state_t : __int32
{
  SAVING = 0x1,
  LOADING = 0x2,
  SAVE_REQUESTED = 0x3,
  LOAD_REQUESTED = 0x4,
  ERR = 0x5,
};

// IDA Local Type ordinal 15132; PDB kind: class.
class idPlayerProfile
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15133.
  virtual ~idPlayerProfile();
  virtual void SetDefaults();
  virtual bool Serialize(idSerializer *);
  virtual bool UpdateDisplayModeFromCvars();
  virtual bool CommitDisplayChanges();
  virtual float GetMouseSensitivity();
  virtual int GetLevel();
  virtual int GetChosenEmblem();
  virtual void SetInvertLook(bool);
  virtual unsigned int GetSubtitleLanguageMask();

  __declspec(align(8)) idPlayerProfile::state_t state;
  idPlayerProfile::state_t requestedState;
  int deviceNum;
  bool hasUser;
  unsigned __int64 achievementBits;
  unsigned __int64 achievementBits2;
  int dlcReleaseVersion;
  idStaticList<profileStatValue_t,500> stats;
};
