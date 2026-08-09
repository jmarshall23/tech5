#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\usercmdgen.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14079; PDB kind: class.
class __declspec(align(4)) usercmd_t
{
public:
  int buttons;
  __int16 buttons2;
  char forwardmove;
  char rightmove;
  char upmove;
  unsigned __int8 : 6;
  __int8 fromBot : 1;
  __int8 inhibited : 1;
  __int16 angles[3];
  int clientGameFrame;
  float pos[3];
  __int16 pitch;
  __int16 yaw;
  __int16 roll;
  unsigned __int8 predictionStateBits;
  int serverGameTime;
  unsigned __int16 fireCount;
  __int16 fireAngles[2];
  __int16 firePos[3];
  unsigned __int8 vehicleThrottle;
  unsigned __int8 speed;
};

// IDA Local Type ordinal 15136; PDB kind: class.
class idUserCmdMgr
{
public:
  usercmd_t cmdBuffer[128][6];
  int writeFrame[6];
  int readFrame[6];
};

// IDA Local Type ordinal 17669; PDB kind: class.
class idUsercmdGen
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17670.
  virtual ~idUsercmdGen();
  virtual void Init();
  virtual void Shutdown();
  virtual void Clear();
  virtual void ClearAngles();
  virtual void SaveGame(idFile *);
  virtual bool LoadGame(idFile *);
  virtual cmdGenButton_t BindStringUsercmdAction(const char *);
  virtual usercmd_t *GetUsercmd(usercmd_t *result, int, const inputSettings_t *, bool, int);
  virtual void GetRecordedUserCmd(int, usercmd_t *);
  virtual bool RecordPlay(int, bool, const char *);
  virtual bool GetUseAimAssist();

};

// IDA Local Type ordinal 23528; PDB kind: struct.
struct idUsercmdGenLocal::usercmdDevice_t
{
  int lastPollTime;
  idAngles angles;
  bool keyState[296];
  float joystickAxis[6];
};

// IDA Local Type ordinal 23529; PDB kind: class.
class idUsercmdGenLocal : public idUsercmdGen
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23530.
  virtual ~idUsercmdGenLocal();
  virtual void Init();
  virtual void Shutdown();
  virtual void Clear();
  virtual void ClearAngles();
  virtual void SaveGame(idFile *);
  virtual bool LoadGame(idFile *);
  virtual cmdGenButton_t BindStringUsercmdAction(const char *);
  virtual usercmd_t *GetUsercmd(usercmd_t *result, int, const inputSettings_t *, bool, int);
  virtual void GetRecordedUserCmd(int, usercmd_t *);
  virtual bool RecordPlay(int, bool, const char *);
  virtual bool GetUseAimAssist();

  int pollTime;
  idUsercmdGenLocal::usercmdDevice_t devices[4];
  bool buttonState[59];
  int lastCommandTime;
  bool initialized;
  int currentDeviceNum;
  idUsercmdGenLocal::usercmdDevice_t *currentDevice;
  inputSettings_t currentSettings;
  usercmd_t cmd;
  float mouseDx;
  float mouseDy;
  int lastInputFrame;
  idFile *cmdFiles[6];
  bool recording[6];
  int loopPlayCmds[6];
  bool aimAssist;
  bool joystickSnapDisabled;
  float lastUsedLookValue[4];
  float lastUsedLookValuePitch[4];
  bool allowButtonInputDuringPlay;
  const idDeclTable *sensitivityJoy1;
  const idDeclTable *sensitivityJoy2;
};
