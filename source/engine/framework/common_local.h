#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\common_local.h
// Recovered logical types: 11
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2946; PDB kind: enum.
enum idCommonLocal::demoMode_t : __int32
{
  DEMO_NONE = 0x0,
  DEMO_RECORD = 0x1,
  DEMO_RECORD_CLIENT = 0x2,
  DEMO_PLAY = 0x3,
  DEMO_TIMETRIAL = 0x4,
};

// IDA Local Type ordinal 2947; PDB kind: unknown.
enum idCommonLocal::<unnamed_tag> : __int32
{
  SS_FS_READ = 0x0,
  SS_FS_WRITE = 0x1,
  SS_FS_MAX = 0x2,
};

// IDA Local Type ordinal 22480; PDB kind: class.
class __declspec(align(8)) idCommonLocal : public idCommon
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22499.
  virtual ~idCommonLocal();
  virtual void Init(int, const char **, const char *);
  virtual void Quit(int);
  virtual void Shutdown(int);
  virtual bool IsInitialized();
  virtual void BeginTerminationThread();
  virtual void EndTerminationThread();
  virtual void SyncAllBackgroundOperations(bool);
  virtual void Frame();
  virtual void InitTool(const toolFlag_t);
  virtual void UpdateTool(const toolFlag_t);
  virtual void GetToolReferenceMap(const toolFlag_t, idStr *);
  virtual void ActivateTool(bool);
  virtual void RegisterMapChangeListener(idMapChangeListener *);
  virtual void UnRegisterMapChangeListener(idMapChangeListener *);
  virtual void WriteConfigToFile(const char *);
  virtual void SetRefreshOnPrint(bool);
  virtual void PrintWarnings();
  virtual void ClearWarnings(const char *);
  virtual void UpdateConsoleDisplay(bool);
  virtual void UpdateLevelLoadPacifier(float, pacifierState_t, bool, bool);
  virtual int PlayLoadSound();
  virtual void SetLoadScreenInfo(const idStr *, const idStr *);
  virtual idPlayerProfile *GetProfileFromMasterLocalUser();
  virtual int GetMasterLocalUserInputDevice();
  virtual int GetMasterLocalUserPlayerId();
  virtual idLocalUser *GetMasterLocalUser();
  virtual void ResetPlayerInput(int);
  virtual void UpdateBotUserCmds(const int, const usercmd_t *);
  virtual bool IsMainMenuActive();
  virtual bool IsGamePaused();
  virtual bool IsInGame();
  virtual snapshotState_t SnapshotState();
  virtual void PrepareSnapshot(idSnapShot *, gameReturn_t *, idSnapShot *);
  virtual bool IsServer();
  virtual bool IsClient();
  virtual bool SnapshotsAreStalled();
  virtual bool IsMultiplayer();
  virtual bool IsToolActive();
  virtual bool AllowCheats();
  virtual void AddDialog(gameDialogMessages_t, dialogType_t, idSWFScriptFunction *, idSWFScriptFunction *, bool, const char *, int, bool, bool, bool);
  virtual void AddDynamicDialog(gameDialogMessages_t, const idStaticList<idSWFScriptFunction *,4> *, const idStaticList<idStrId,4> *, bool, idStrStatic<256>, bool, bool, bool);
  virtual void AddDialogIntVal(const char *, int);
  virtual void ClearDialogs(bool);
  virtual bool HasDialogMsg(gameDialogMessages_t, bool *);
  virtual void ClearDialog(gameDialogMessages_t, const char *, int);
  virtual bool IsDialogActive();
  virtual bool IsDialogPausing();
  virtual int GetRecentInputDevice();
  virtual int GetFocusDeviceNum();
  virtual void SetFocusDeviceNum(int);
  virtual int GetPauseMenuDeviceNum();
  virtual void SetPauseMenuDeviceNum(int);
  virtual bool GetAutosaveEnabled();
  virtual void EnableAutosaves(bool);
  virtual void ShowSaveIndicator(bool, bool);
  virtual idGame *Game();
  virtual idRenderWorld *RW();
  virtual idSoundWorld *SW();
  virtual void ExecuteMapChange(const idGameSpawnInfo *, idFile *);
  virtual void RecordPlayback(bool, const char *);
  virtual recordState_t GetRecordState();
  virtual idRegression *GetRegression();
  virtual void RecordSnapshotFile(idFile *, unsigned int);
  virtual void PlaySnapshotFile(idFile *, unsigned int);
  virtual void QueueSnapshotMemFile(idFile_Memory *, unsigned int);
  virtual void ClearQueuedSnapshotFile();
  virtual void PlayQueuedSnapshotFile();
  virtual void StopSnapshotFilePlayback();
  virtual void StopSnapshotFileRecord();
  virtual void CloseSnapshotFiles();
  virtual bool DemoPlaying();
  virtual bool DemoRecording();
  virtual bool TimeTrialPlaying();
  virtual bool TimeTrialRecording();
  virtual idFile *DetachActiveReadSnapshotFile();
  virtual idFile *DetachActiveWriteSnapshotFile();
  virtual idFile *GetActiveReadSnapshotFile();
  virtual idFile *GetActiveWriteSnapshotFile();
  virtual void NetReceiveReliable(int, idBitMsg *, int);
  virtual void NetReceiveSnapshot(idSnapShot *);
  virtual void NetReceiveUsercmds(idBitMsg *);
  virtual int NetWriteResources(idLZWCompressor *, int, int, bool);
  virtual void NetReadResources(idLZWCompressor *);
  virtual int GetSnapRate();
  virtual bool IsLosingConnectionToHost();
  virtual idRenderVideoOverlay *VideoOverlay();
  virtual void PurgeOverlays();
  virtual idFile *GetLogfile();
  virtual const idGame *Game_2();

  idCommonLocal::idLogFileWriter logFileWriter;
  idCommonLocal::idWarningList warningList;
  idCommonLocal::idRefreshOnPrint refreshOnPrint;
  bool com_fullyInitialized;
  bool inConsoleCommand;
  bool insideUpdateScreen;
  production_t production;
  idSourceControlWrapper sourceControl;
  char savegameCheckpointFolder[64];
  bool askedToLoadFromCheckpoint;
  bool showedErrorLoadingGameDialog;
  unsigned int savegameCheckpointPreviousDeviceId;
  idGame *game;
  idFile *eventFile;
  recordState_t recordState;
  idRegressionLocal regression;
  bool readAsciiEvents;
  int eventFileVersion;
  idCommonLocal::demoMode_t demoMode;
  idCommonLocal::<unnamed_type_ssFileState> ssFileState[2];
  unsigned __int64 snapRate;
  unsigned __int64 actualRate;
  unsigned __int64 snapTime;
  unsigned __int64 snapTimeDelta;
  unsigned __int64 snapTimeWrite;
  unsigned __int64 snapCurrentTime;
  gameReturn_t snapCurrent;
  gameReturn_t snapPrevious;
  float snapCurrentResidual;
  float snapTimeBuffered;
  float effectiveSnapRate;
  int totalBufferedTime;
  int totalRecvTime;
  idFile_Memory *queuedSnapshotFile;
  unsigned int queuedSnapshotFileTag;
  bool shutdownExecuted;
  bool quitFlag;
  int quitExitCode;
  bool autosavesEnabled;
  int recentInputDevice;
  int focusDevice;
  int pauseMenuDevice;
  idGaugeMetric snapDeltaTime;
  bool purgeOverlays;
  bool preventOverlayPurge;
  idTerminationThread *terminationThread;
  int readSnapshotIndex;
  int writeSnapshotIndex;
  idArray<idSnapShot,16> receivedSnaps;
  float optimalPCTBuffer;
  float optimalTimeBuffered;
  float optimalTimeBufferedWindow;
  int userCmdFrame;
  idDebugGraph *graph;
  idDebugGraph *graphSnapRate;
  idSnapShot oldss;
  idList<idMapChangeListener *,5> mapChangeListeners;
  inputSettings_t inputSettings[4];
  idUserCmdMgr userCmdMgr;
  int levelLoadInProgress;
  idSWF *loadingGui;
  idRenderModelGui *guiModel;
  int lastPacifierSessionTime;
  int lastPacifierGuiTime;
  int lastPacifierTooltipTime;
  bool dialogWingstickActive;
  bool dialogPause;
  idSWF *dialog;
  idSWF *saveIndicator;
  idSubtitles_VideoOverlay *videoOverlay;
  idRenderModelGui *dialogGuiModel;
  idRenderModelGui *saveIndicatorGuiModel;
  bool dialogShowingSaveIndicatorRequested;
  int dialogShowingSaveIndicatorTimeRemaining;
  idStaticList<idDialogInfo,4> messageList;
  idStaticList<idLoadScreenInfo,16> loadScreenInfo;
  int startSaveTime;
  int stopSaveTime;
  bool dialogInUse;
};

// IDA Local Type ordinal 22481; PDB kind: class.
class __declspec(align(4)) idCommonLocal::idLogFileWriter : public idPrintListener
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22482.
  virtual ~idLogFileWriter();
  virtual void Print(const char *);

  idFile *logFile;
  bool recursing;
};

// IDA Local Type ordinal 22484; PDB kind: class.
class idCommonLocal::idWarningList : public idPrintListener
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22485.
  virtual ~idWarningList();
  virtual void Print(const char *);

  idList<idUniqueWarning,3> list;
  idHashIndex hash;
  idStrStatic<128> caption;
};

// IDA Local Type ordinal 22486; PDB kind: class.
class __declspec(align(4)) idCommonLocal::idRefreshOnPrint : public idPrintListener
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22487.
  virtual ~idRefreshOnPrint();
  virtual void Print(const char *);

  idCommonLocal *cl;
  bool set;
};

// IDA Local Type ordinal 22488; PDB kind: unknown.
struct idCommonLocal::<unnamed_type_ssFileState>
{
  idCompressor *compressor;
  idCompressor *compressor2;
  idFile *file;
  idSnapShot *ss;
  int resources;
};

// IDA Local Type ordinal 23669; PDB kind: struct.
struct idCommonLocal::DrawSnapshotMetrics::__l11::local_t
{
};

// IDA Local Type ordinal 23671; PDB kind: class.
class idCommonLocal::StartLevelLoad::__l19::idSWFScriptFunction_RandZeroToNMinusOneTipIndex : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23672.
  virtual ~idSWFScriptFunction_RandZeroToNMinusOneTipIndex();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *gui;
};

// IDA Local Type ordinal 23677; PDB kind: class.
class idCommonLocal::ShowDialog::__l19::idSWFScriptFunction_Accept : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23678.
  virtual ~idSWFScriptFunction_Accept();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  gameDialogMessages_t msg;
};

// IDA Local Type ordinal 23681; PDB kind: class.
class __declspec(align(4)) idCommonLocal::UploadCrashDumps::__l2::idCDWriter : public idSysThread
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23682.
  virtual ~idCDWriter();
  virtual int Run();

  __int64 writeTimeUS;
  __int64 writeTotal;
  void *data;
  __int64 size;
  idFile *file;
  bool result;
};
