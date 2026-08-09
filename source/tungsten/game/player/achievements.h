#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\player\achievements.h
// Recovered logical types: 8
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1196; PDB kind: enum.
enum achievementId_t : __int32
{
  GAME_ACHIEVEMENT_NONE = 0x0,
  GAME_ACHIEVEMENT_01 = 0x1,
  GAME_ACHIEVEMENT_02 = 0x2,
  GAME_ACHIEVEMENT_03 = 0x3,
  GAME_ACHIEVEMENT_04 = 0x4,
  GAME_ACHIEVEMENT_05 = 0x5,
  GAME_ACHIEVEMENT_06 = 0x6,
  GAME_ACHIEVEMENT_07 = 0x7,
  GAME_ACHIEVEMENT_08 = 0x8,
  GAME_ACHIEVEMENT_09 = 0x9,
  GAME_ACHIEVEMENT_10 = 0xA,
  GAME_ACHIEVEMENT_11 = 0xB,
  GAME_ACHIEVEMENT_12 = 0xC,
  GAME_ACHIEVEMENT_13 = 0xD,
  GAME_ACHIEVEMENT_14 = 0xE,
  GAME_ACHIEVEMENT_15 = 0xF,
  GAME_ACHIEVEMENT_16 = 0x10,
  GAME_ACHIEVEMENT_17 = 0x11,
  GAME_ACHIEVEMENT_18 = 0x12,
  GAME_ACHIEVEMENT_19 = 0x13,
  GAME_ACHIEVEMENT_20 = 0x14,
  GAME_ACHIEVEMENT_21 = 0x15,
  GAME_ACHIEVEMENT_22 = 0x16,
  GAME_ACHIEVEMENT_23 = 0x17,
  GAME_ACHIEVEMENT_24 = 0x18,
  GAME_ACHIEVEMENT_25 = 0x19,
  GAME_ACHIEVEMENT_26 = 0x1A,
  GAME_ACHIEVEMENT_27 = 0x1B,
  GAME_ACHIEVEMENT_28 = 0x1C,
  GAME_ACHIEVEMENT_29 = 0x1D,
  GAME_ACHIEVEMENT_30 = 0x1E,
  GAME_ACHIEVEMENT_31 = 0x1F,
  GAME_ACHIEVEMENT_32 = 0x20,
  GAME_ACHIEVEMENT_33 = 0x21,
  GAME_ACHIEVEMENT_34 = 0x22,
  GAME_ACHIEVEMENT_35 = 0x23,
  GAME_ACHIEVEMENT_36 = 0x24,
  GAME_ACHIEVEMENT_37 = 0x25,
  GAME_ACHIEVEMENT_38 = 0x26,
  GAME_ACHIEVEMENT_39 = 0x27,
  GAME_ACHIEVEMENT_40 = 0x28,
  GAME_ACHIEVEMENT_41 = 0x29,
  GAME_ACHIEVEMENT_42 = 0x2A,
  GAME_ACHIEVEMENT_43 = 0x2B,
  GAME_ACHIEVEMENT_44 = 0x2C,
  GAME_ACHIEVEMENT_45 = 0x2D,
  GAME_ACHIEVEMENT_46 = 0x2E,
  GAME_ACHIEVEMENT_47 = 0x2F,
  GAME_ACHIEVEMENT_48 = 0x30,
  GAME_ACHIEVEMENT_49 = 0x31,
  GAME_ACHIEVEMENT_50 = 0x32,
  GAME_ACHIEVEMENT_END = 0x33,
  GAME_ACHIEVEMENT_NUM = 0x32,
};

// IDA Local Type ordinal 1494; PDB kind: enum.
enum __bitmask idAchievementSystemXbox::state_t : __int32
{
  STATE_WRITING = 0x1,
};

// IDA Local Type ordinal 15003; PDB kind: struct.
struct idAchievement::eventAchievementInfo_t
{
  int count;
};

// IDA Local Type ordinal 15004; PDB kind: struct.
struct idAchievement::raceAchievementInfo_t
{
  raceMemoryPlace_t place;
};

// IDA Local Type ordinal 15005; PDB kind: class.
class idAchievement : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15006.
  virtual idTypeInfo *GetType();
  virtual ~idAchievement();

  const idDeclAchievement *decl;
  bool itemsFulfilled;
  bool jobsFulfilled;
  bool triggersFulfilled;
  bool eventsFulfilled;
  bool racesFulfilled;
  bool achievementsFulfilled;
  bool triggersActivated[6];
  bool achievementsGained[49];
  idAchievement::eventAchievementInfo_t eventInfo[30];
  idAchievement::raceAchievementInfo_t racesInfo[30];
};

// IDA Local Type ordinal 17407; PDB kind: class.
class idAchievementSystem
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17410.
  virtual ~idAchievementSystem();
  virtual void Init();
  virtual void Shutdown();
  virtual bool IsInitialized();
  virtual void RegisterLocalUser(idLocalUser *);
  virtual void RemoveLocalUser(idLocalUser *);
  virtual void AchievementUnlock(idLocalUser *, const int);
  virtual void AchievementLock(idLocalUser *, const int);
  virtual void AchievementLockAll(idLocalUser *, const int);
  virtual void Pump();
  virtual void Reset(idLocalUser *);
  virtual void Cancel(idLocalUser *);
  virtual bool GetAchievementDescription(idLocalUser *, const int, achievementDescription_t *);
  virtual bool GetRequiredStorage(unsigned __int64 *);
  virtual bool GetAchievementState(idLocalUser *, idArray<bool,128> *);
  virtual bool SetAchievementState(idLocalUser *, idArray<bool,128> *);

  idStaticList<idLocalUser *,2> users;
};

// IDA Local Type ordinal 18522; PDB kind: struct.
struct idAchievementSystemXbox::achievementAction_t
{
  idStaticList<XUSER_ACHIEVEMENT,128> pendingAchievments;
  idStaticList<XUSER_ACHIEVEMENT,128> achievements;
  idAchievementSystemXbox::state_t state;
  _XOVERLAPPED overlapped;
};

// IDA Local Type ordinal 18524; PDB kind: class.
class idAchievementSystemXbox : public idAchievementSystem
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18525.
  virtual ~idAchievementSystemXbox();
  virtual void Init();
  virtual void Shutdown();
  virtual bool IsInitialized();
  virtual void RegisterLocalUser(idLocalUser *);
  virtual void RemoveLocalUser(idLocalUser *);
  virtual void AchievementUnlock(idLocalUser *, const int);
  virtual void AchievementLock(idLocalUser *, const int);
  virtual void AchievementLockAll(idLocalUser *, const int);
  virtual void Pump();
  virtual void Reset(idLocalUser *);
  virtual void Cancel(idLocalUser *);
  virtual bool GetAchievementDescription(idLocalUser *, const int, achievementDescription_t *);
  virtual bool GetRequiredStorage(unsigned __int64 *);
  virtual bool GetAchievementState(idLocalUser *, idArray<bool,128> *);
  virtual bool SetAchievementState(idLocalUser *, idArray<bool,128> *);

  idArray<idAchievementSystemXbox::achievementAction_t,2> achievementAction;
};
