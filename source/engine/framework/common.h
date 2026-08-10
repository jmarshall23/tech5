#pragma once

#include "framework/dialog.h"
#include "idlib/containers/staticlist.h"
#include "idlib/langdict.h"
#include "idlib/text/strstatic.h"

class idBitMsg;
class idCVar;
class idFile;
class idFile_Memory;
class idGame;
class idLocalUser;
class idLZWCompressor;
class idMapChangeListener;
class idPlayerProfile;
class idRegression;
class idRenderVideoOverlay;
class idRenderWorld;
class idSnapShot;
class idSoundWorld;
class idSWFScriptFunction;
class usercmd_t;
struct gameReturn_t;
struct idGameSpawnInfo;
enum pacifierState_t : int;
enum recordState_t : int {
    RECORD_NONE = 0,
    RECORD_MAKE = 1,
    RECORD_PLAY = 2
};
enum snapshotState_t : int;
enum toolFlag_t : int;

// Vtable order recovered from the tungsten executable's idCommon type.
class idCommon {
public:
    virtual ~idCommon() = default;
    virtual void Init(int, const char**, const char*) = 0;
    virtual void Quit(int) = 0;
    virtual void Shutdown(int) = 0;
    virtual bool IsInitialized() = 0;
    virtual void BeginTerminationThread() = 0;
    virtual void EndTerminationThread() = 0;
    virtual void SyncAllBackgroundOperations(bool) = 0;
    virtual void Frame() = 0;
    virtual void InitTool(toolFlag_t) = 0;
    virtual void UpdateTool(toolFlag_t) = 0;
    virtual void GetToolReferenceMap(toolFlag_t, idStr*) = 0;
    virtual void ActivateTool(bool) = 0;
    virtual void RegisterMapChangeListener(idMapChangeListener*) = 0;
    virtual void UnRegisterMapChangeListener(idMapChangeListener*) = 0;
    virtual void WriteConfigToFile(const char*) = 0;
    virtual void SetRefreshOnPrint(bool) = 0;
    virtual void PrintWarnings() = 0;
    virtual void ClearWarnings(const char*) = 0;
    virtual void UpdateConsoleDisplay(bool) = 0;
    virtual void UpdateLevelLoadPacifier(float, pacifierState_t,
        bool, bool) = 0;
    virtual int PlayLoadSound() = 0;
    virtual void SetLoadScreenInfo(const idStr*, const idStr*) = 0;
    virtual idPlayerProfile* GetProfileFromMasterLocalUser() = 0;
    virtual int GetMasterLocalUserInputDevice() = 0;
    virtual int GetMasterLocalUserPlayerId() = 0;
    virtual idLocalUser* GetMasterLocalUser() = 0;
    virtual void ResetPlayerInput(int) = 0;
    virtual void UpdateBotUserCmds(int, const usercmd_t*) = 0;
    virtual bool IsMainMenuActive() = 0;
    virtual bool IsGamePaused() = 0;
    virtual bool IsInGame() = 0;
    virtual snapshotState_t SnapshotState() = 0;
    virtual void PrepareSnapshot(idSnapShot*, gameReturn_t*, idSnapShot*) = 0;
    virtual bool IsServer() = 0;
    virtual bool IsClient() = 0;
    virtual bool SnapshotsAreStalled() = 0;
    virtual bool IsMultiplayer() = 0;
    virtual bool IsToolActive() = 0;
    virtual bool AllowCheats() = 0;
    virtual void AddDialog(gameDialogMessages_t, dialogType_t,
        idSWFScriptFunction*, idSWFScriptFunction*, bool, const char*, int,
        bool, bool, bool) = 0;
    virtual void AddDynamicDialog(gameDialogMessages_t,
        const idStaticList<idSWFScriptFunction*, 4>*,
        const idStaticList<idStrId, 4>*, bool, idStrStatic<256>,
        bool, bool, bool) = 0;
    virtual void AddDialogIntVal(const char*, int) = 0;
    virtual void ClearDialogs(bool) = 0;
    virtual bool HasDialogMsg(gameDialogMessages_t, bool*) = 0;
    virtual void ClearDialog(gameDialogMessages_t, const char*, int) = 0;
    virtual bool IsDialogActive() = 0;
    virtual bool IsDialogPausing() = 0;
    virtual int GetRecentInputDevice() = 0;
    virtual int GetFocusDeviceNum() = 0;
    virtual void SetFocusDeviceNum(int) = 0;
    virtual int GetPauseMenuDeviceNum() = 0;
    virtual void SetPauseMenuDeviceNum(int) = 0;
    virtual bool GetAutosaveEnabled() = 0;
    virtual void EnableAutosaves(bool) = 0;
    virtual void ShowSaveIndicator(bool, bool) = 0;
    virtual idGame* Game() = 0;
    virtual idRenderWorld* RW() = 0;
    virtual idSoundWorld* SW() = 0;
    virtual void ExecuteMapChange(const idGameSpawnInfo*, idFile*) = 0;
    virtual void RecordPlayback(bool, const char*) = 0;
    virtual recordState_t GetRecordState() = 0;
    virtual idRegression* GetRegression() = 0;
    virtual void RecordSnapshotFile(idFile*, unsigned int) = 0;
    virtual void PlaySnapshotFile(idFile*, unsigned int) = 0;
    virtual void QueueSnapshotMemFile(idFile_Memory*, unsigned int) = 0;
    virtual void ClearQueuedSnapshotFile() = 0;
    virtual void PlayQueuedSnapshotFile() = 0;
    virtual void StopSnapshotFilePlayback() = 0;
    virtual void StopSnapshotFileRecord() = 0;
    virtual void CloseSnapshotFiles() = 0;
    virtual bool DemoPlaying() = 0;
    virtual bool DemoRecording() = 0;
    virtual bool TimeTrialPlaying() = 0;
    virtual bool TimeTrialRecording() = 0;
    virtual idFile* DetachActiveReadSnapshotFile() = 0;
    virtual idFile* DetachActiveWriteSnapshotFile() = 0;
    virtual idFile* GetActiveReadSnapshotFile() = 0;
    virtual idFile* GetActiveWriteSnapshotFile() = 0;
    virtual void NetReceiveReliable(int, idBitMsg*, int) = 0;
    virtual void NetReceiveSnapshot(idSnapShot*) = 0;
    virtual void NetReceiveUsercmds(idBitMsg*) = 0;
    virtual int NetWriteResources(idLZWCompressor*, int, int, bool) = 0;
    virtual void NetReadResources(idLZWCompressor*) = 0;
    virtual int GetSnapRate() = 0;
    virtual bool IsLosingConnectionToHost() = 0;
    virtual idRenderVideoOverlay* VideoOverlay() = 0;
    virtual void PurgeOverlays() = 0;
    virtual idFile* GetLogfile() = 0;
};

extern idCommon* common;

// Recovered framework CVars owned by common.cpp.
extern idCVar com_safemode;
extern idCVar com_skipIntroVideo;
extern idCVar com_waitForSavegames;
extern idCVar com_headless;
extern idCVar com_speeds;
extern idCVar com_timescale;
extern idCVar com_slowmoscale;
extern idCVar com_editorActive;
extern idCVar com_captureSamples;
extern idCVar com_capturePath;
extern idCVar com_captureTGA;
extern idCVar com_capturePrimes;
extern idCVar net_usePlatformBackend;
extern idCVar com_multiplayer;
extern idCVar com_uploadDumps;
extern idCVar com_uploadDumpPath;
extern idCVar com_fixedTic;
extern idCVar com_traceFrame;
extern idCVar com_useMapHeap;
extern idCVar com_showMapLoadStatus;
