#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\libs\mgrd\include\rd\common.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17417; PDB kind: class.
class idCommon
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17439.
  virtual ~idCommon();
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

};
