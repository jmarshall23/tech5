#pragma once

#include "framework/common.h"
#include "framework/framework_runtime.h"
#include "idlib/lib_print.h"
#include "idlib/containers/list.h"
#include "idlib/containers/hashindex.h"
#include "idlib/filesystem/file.h"
#include "idlib/text/strstatic.h"
#include "idlib/uniquewarning.h"

class idBitMsg;
class idCmdArgs;
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
struct gameReturn_t;
struct idGameSpawnInfo;
struct sysEvent_t;
class usercmd_t;
enum pacifierState_t : int;
enum snapshotState_t : int;
enum toolFlag_t : int;

class idCommonLocal : public idCommon {
public:
    class idLogFileWriter : public idPrintListener {
    public:
        idLogFileWriter();
        ~idLogFileWriter() override;
        void Print(const char* message) override;
        void CloseLogFile();

        idFile* logFile;
        bool recursing;
    };

    class idWarningList : public idPrintListener {
    public:
        idWarningList();
        ~idWarningList() override;
        void Print(const char* message) override;

        idList<idUniqueWarning, TAG_DEBUG> list;
        idHashIndex hash;
        idStrStatic<128> caption;
    };

    class idRefreshOnPrint : public idPrintListener {
    public:
        idRefreshOnPrint();
        ~idRefreshOnPrint() override;
        void Print(const char* message) override;

        idCommonLocal* cl;
        bool set;
    };

    enum demoMode_t : int {
        DEMO_NONE = 0,
        DEMO_RECORD = 1,
        DEMO_RECORD_CLIENT = 2,
        DEMO_PLAY = 3,
        DEMO_TIMETRIAL = 4
    };

    idCommonLocal();
    ~idCommonLocal() override;

    void Init(int argc, const char** argv, const char* commandLine) override;
    void Quit(int exitCode) override;
    void Shutdown(int exitCode) override;
    bool IsInitialized() override;
    void Frame() override;
    void BeginTerminationThread() override;
    void EndTerminationThread() override;
    void SyncAllBackgroundOperations(bool waitForResources) override;
    void InitTool(toolFlag_t tool) override;
    void UpdateTool(toolFlag_t tool) override;
    void GetToolReferenceMap(toolFlag_t tool, idStr* map) override;
    void ActivateTool(bool active) override;
    bool IsToolActive() override;
    void RegisterMapChangeListener(idMapChangeListener* listener) override;
    void UnRegisterMapChangeListener(idMapChangeListener* listener) override;
    void WriteConfigToFile(const char* filename) override;
    void SetRefreshOnPrint(bool enabled) override;
    void ClearWarnings(const char* reason) override;
    void PrintWarnings() override;
    void DumpWarnings(const char* fileName);
    void UpdateConsoleDisplay(bool force) override;
    void UpdateLevelLoadPacifier(float progress, pacifierState_t state,
        bool force, bool updateScreen) override;
    int PlayLoadSound() override;
    void SetLoadScreenInfo(const idStr* mapName,
        const idStr* loadScreen) override;
    void StartLevelLoad(const idStr& mapName, bool playVideo);
    void StopLevelLoad(bool stopSound);
    bool IsMainMenuActive() override;
    bool IsGamePaused() override;
    bool IsInGame() override;
    bool IsServer() override;
    bool IsClient() override;
    bool IsMultiplayer() override;
    snapshotState_t SnapshotState() override;
    void PrepareSnapshot(idSnapShot*, gameReturn_t*,
        idSnapShot* previous) override;
    bool SnapshotsAreStalled() override;
    bool AllowCheats() override;
    bool IsDialogActive() override;
    bool IsDialogPausing() override;
    void AddDialog(gameDialogMessages_t message, dialogType_t type,
        idSWFScriptFunction* accept, idSWFScriptFunction* cancel, bool pause,
        const char* location = nullptr, int line = 0,
        bool leaveOnReset = false, bool waitOnAtlas = false,
        bool renderDuringLoad = false) override;
    void AddDynamicDialog(gameDialogMessages_t message,
        const idStaticList<idSWFScriptFunction*, 4>* callbacks,
        const idStaticList<idStrId, 4>* options, bool pause,
        idStrStatic<256> text, bool leaveOnReset, bool waitOnAtlas,
        bool renderDuringLoad) override;
    void AddDialogIntVal(const char* name, int value) override;
    bool HasDialogMsg(gameDialogMessages_t message,
        bool* isActive) override;
    void ClearDialog(gameDialogMessages_t message,
        const char* location = nullptr, int line = 0) override;
    idStr GetDialogMsg(gameDialogMessages_t message) const;
    void RemoveWaitDialogs();
    void ClearAllDialogHack();
    void ReleaseCallBacks(int index);
    bool HandleDialogEvent(const sysEvent_t* event);
    void ShowDialog(const idDialogInfo& info, bool waitForAtlas);
    void ShowNextDialog(bool waitForAtlas);
    void InitDialog();
    void AddDialogInternal(idDialogInfo& info);
    void RenderDialog(bool loading);
    void KillDialog();
    void ActivateDialog(bool active);
    void ClearDialogs(bool force) override;
    void SetInitialized(bool value);
    void InitCommands();
    void InitLanguageDict();
    void SetCommandLineCVars(const idCmdArgs& args, bool init);
    void WriteSysEvent(const sysEvent_t& event);
    bool ReadSysEvent(sysEvent_t& event);
    void ResetMapHeap();
    void UploadCrashDumps();

    idPlayerProfile* GetProfileFromMasterLocalUser() override;
    int GetMasterLocalUserInputDevice() override;
    int GetMasterLocalUserPlayerId() override;
    idLocalUser* GetMasterLocalUser() override;
    void ResetPlayerInput(int deviceNum) override;
    void UpdateBotUserCmds(int player, const usercmd_t* command) override;
    int GetRecentInputDevice() override;
    int GetFocusDeviceNum() override;
    void SetFocusDeviceNum(int deviceNum) override;
    int GetPauseMenuDeviceNum() override;
    void SetPauseMenuDeviceNum(int deviceNum) override;
    bool GetAutosaveEnabled() override;
    void EnableAutosaves(bool enabled) override;
    void ShowSaveIndicator(bool show, bool force) override;

    idGame* Game() override;
    idRenderWorld* RW() override;
    idSoundWorld* SW() override;
    const idGame* Game_2() const;
    void ExecuteMapChange(const idGameSpawnInfo*, idFile* saveFile) override;
    void PrepareForMapChange();
    void FinalizeMapChange(const idGameSpawnInfo&, idFile* saveFile);
    void LoadMainMenu();
    void LeaveGame(bool force);
    void Disconnect(bool force);

    void RecordPlayback(bool record, const char* fileName) override;
    recordState_t GetRecordState() override;
    idRegression* GetRegression() override;
    void RecordSnapshotFile(idFile* file, unsigned int tag) override;
    void PlaySnapshotFile(idFile* file, unsigned int tag) override;
    void QueueSnapshotMemFile(idFile_Memory* file,
        unsigned int tag) override;
    void ClearQueuedSnapshotFile() override;
    void PlayQueuedSnapshotFile() override;
    void StopSnapshotFilePlayback() override;
    void StopSnapshotFileRecord() override;
    void CloseSnapshotFiles() override;
    bool DemoPlaying() override;
    bool DemoRecording() override;
    bool TimeTrialPlaying() override;
    bool TimeTrialRecording() override;
    idFile* DetachActiveReadSnapshotFile() override;
    idFile* DetachActiveWriteSnapshotFile() override;
    idFile* GetActiveReadSnapshotFile() override;
    idFile* GetActiveWriteSnapshotFile() override;

    void NetReceiveReliable(int peer, idBitMsg* message, int type) override;
    void NetReceiveSnapshot(idSnapShot* snapshot) override;
    void NetReceiveUsercmds(idBitMsg* message) override;
    void WriteUserCmdDelta(idBitMsg& message, const usercmd_t& command,
        const usercmd_t* base);
    void ReadUserCmdDelta(const idBitMsg& message, usercmd_t& command,
        const usercmd_t* base);
    int NetWriteResources(idLZWCompressor*, int start, int max,
        bool writeResourceNames) override;
    void NetReadResources(idLZWCompressor*) override;
    int GetSnapRate() override;
    bool IsLosingConnectionToHost() override;
    idRenderVideoOverlay* VideoOverlay() override;
    void PurgeOverlays() override;
    idFile* GetLogfile() override;

    idLogFileWriter logFileWriter;
    idWarningList warningList;
    idRefreshOnPrint refreshOnPrint;
    bool com_fullyInitialized;
    bool inConsoleCommand;
    bool insideUpdateScreen;
    bool consoleUsed;
    bool server;
    bool client;
    bool multiplayer;
    bool shutdownExecuted;
    bool quitFlag;
    int quitExitCode;
    int frameTime;
    demoMode_t demoMode;
    bool autosavesEnabled;
    bool snapshotsStalled;
    bool losingConnection;
    bool terminationActive;
    int recentInputDevice;
    int focusDevice;
    int pauseMenuDevice;
    int snapRate;
    recordState_t recordState;
    int eventFileVersion;
    bool readAsciiEvents;
    bool eventFileBigEndian;
    unsigned int activeReadSnapshotTag;
    unsigned int activeWriteSnapshotTag;
    unsigned int queuedSnapshotTag;
    idFile* eventFile;
    idFile* activeReadSnapshotFile;
    idFile* activeWriteSnapshotFile;
    idFile_Memory* queuedSnapshotFile;
    idGame* game;
    idRenderWorld* renderWorld;
    idSoundWorld* soundWorld;
    idPlayerProfile* masterProfile;
    idLocalUser* masterLocalUser;
    idRegression* regression;
    idRenderVideoOverlay* videoOverlay;
    idList<idMapChangeListener*> mapChangeListeners;
};

extern idCommonLocal commonLocal;

void RegisterDialogCommands();
