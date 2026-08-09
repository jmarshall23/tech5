#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\savegame.h
// Recovered logical types: 7
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 963; PDB kind: enum.
enum saveGameType_t : __int32
{
  SAVEGAMEFILE_NONE = 0x0,
  SAVEGAMEFILE_TEXT = 0x1,
  SAVEGAMEFILE_BINARY = 0x2,
  SAVEGAMEFILE_COMPRESSED = 0x4,
  SAVEGAMEFILE_PIPELINED = 0x8,
  SAVEGAMEFILE_THUMB = 0x10,
  SAVEGAMEFILE_BKGRND_IMAGE = 0x20,
  SAVEGAMEFILE_AUTO_DELETE = 0x40,
  SAVEGAMEFILE_OPTIONAL = 0x80,
};

// IDA Local Type ordinal 1526; PDB kind: enum.
enum saveGameError_t : __int32
{
  SAVEGAME_E_NONE = 0x0,
  SAVEGAME_E_CANCELLED = 0x1,
  SAVEGAME_E_INSUFFICIENT_ROOM = 0x2,
  SAVEGAME_E_CORRUPTED = 0x4,
  SAVEGAME_E_UNABLE_TO_SELECT_STORAGE_DEVICE = 0x8,
  SAVEGAME_E_UNKNOWN = 0x10,
  SAVEGAME_E_INVALID_FILENAME = 0x20,
  SAVEGAME_E_STEAM_ERROR = 0x40,
  SAVEGAME_E_FOLDER_NOT_FOUND = 0x80,
  SAVEGAME_E_FILE_NOT_FOUND = 0x100,
  SAVEGAME_E_DLC_NOT_FOUND = 0x200,
  SAVEGAME_E_INVALID_USER = 0x400,
  SAVEGAME_E_PROFILE_TOO_BIG = 0x800,
  SAVEGAME_E_DISC_SWAP = 0x1000,
  SAVEGAME_E_INCOMPATIBLE_NEWER_VERSION = 0x2000,
  SAVEGAME_E_BITS_USED = 0xE,
  SAVEGAME_E_NUM = 0xF,
};

// IDA Local Type ordinal 2528; PDB kind: enum.
enum idSaveGameManager::packageType_t : __int32
{
  PACKAGE_PROFILE = 0x0,
  PACKAGE_GAME = 0x1,
  PACKAGE_RAW = 0x2,
  PACKAGE_NUM = 0x3,
};

// IDA Local Type ordinal 17404; PDB kind: class.
class __declspec(align(4)) idSaveGameThread : public idSysThread
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17405.
  virtual ~idSaveGameThread();
  virtual int Run();

  saveGameThreadArgs_t data;
  volatile bool cancel;
};

// IDA Local Type ordinal 17406; PDB kind: class.
class __declspec(align(8)) idSaveGameManager
{
public:
  idSaveGameProcessor *processor;
  idStaticList<idSaveGameProcessor *,4> processorQueue;
  bool cancel;
  idSaveGameThread saveThread;
  int delayStart;
  int startTime;
  bool continueProcessing;
  int submittedProcessorHandle;
  int executingProcessorHandle;
  int lastExecutedProcessorHandle;
  idStaticList<idSaveGameDetails,16> enumeratedSaveGames;
  bool storageAvailable;
};

// IDA Local Type ordinal 21721; PDB kind: struct.
struct saveGameCheck_t
{
  bool exists;
  bool autosaveExists;
  const char *autosaveFolder;
};

// IDA Local Type ordinal 22666; PDB kind: class.
class idSaveGameManager::Pump::__l47::idSWFScriptFunction_TryAgain : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22667.
  virtual ~idSWFScriptFunction_TryAgain();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSaveGameManager *manager;
  idSaveGameProcessor *processor;
};
