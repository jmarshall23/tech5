#include "framework/framework_runtime_internal.h"

namespace tech5Framework {

runtimeState_t& State() {
    static runtimeState_t state;
    return state;
}

void Init(const char* const commandLine) {
    runtimeState_t& state = State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    state.lifecycle = lifecycle_t::initializing;
    state.session = sessionState_t::idle;
    state.frame = 0;
    state.milliseconds = 0;
    state.commandLine = commandLine != nullptr ? commandLine : "";
    state.commands.clear();
    state.dialogs.clear();
    state.dialogIntValues.clear();
    state.dialogActive = false;
    state.saveIndicatorRequested = false;
    state.saveIndicatorClearTime = 0;
    state.loadProgress = 0.0f;
    state.loadPhase.Clear();
    state.networkMessages.clear();
    state.consoleLines.clear();
    state.consoleSequence = 0;
    state.debugHUD.clear();
    state.debugMenu.clear();
    state.playtestEvents.clear();
    state.userCommands.clear();
}

void Shutdown() {
    runtimeState_t& state = State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    state.lifecycle = lifecycle_t::terminating;
    state.commands.clear();
    ClearDialogs(true);
    state.dialogIntValues.clear();
    state.networkMessages.clear();
    state.consoleLines.clear();
    state.debugHUD.clear();
    state.debugMenu.clear();
    state.playtestEvents.clear();
    state.userCommands.clear();
    state.session = sessionState_t::idle;
    state.lifecycle = lifecycle_t::stopped;
}

lifecycle_t Lifecycle() {
    runtimeState_t& state = State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    return state.lifecycle;
}

std::uint64_t FrameNumber() {
    runtimeState_t& state = State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    return state.frame;
}

} // namespace tech5Framework

#include "framework/common_local.h"
#include "framework/console.h"
#include "framework/consolehistory.h"
#include "framework/debugmenu.h"
#include "framework/framework_hooks.h"
#include "framework/gamesystem.h"
#include "framework/loadscreen.h"
#include "framework/regression.h"
#include "framework/rendermanager.h"
#include "framework/resourcelist.h"
#include "framework/resourcemanager.h"
#include "framework/streamfilecache.h"
#include "framework/sysevent.h"
#include "framework/usercmdgen.h"
#include "idlib/csystems/cmdsystem.h"
#include "idlib/csystems/cvarsystem.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/lib_print.h"
#include "idlib/sys/sys_alloc.h"
#include "idlib/text/cmdargs.h"

#include <cstdint>
#include <cctype>
#include <string>

// CVar declarations and defaults recovered from common.cpp. The PC port keeps
// the original public names, including timescale/slowmoscale and the historical
// com_writeDumpPath spelling.
idCVar com_safemode("com_safemode", "0", CVAR_BOOL | CVAR_NOCHEAT,
    "delete video/config files and restore game defaults");
idCVar com_skipIntroVideo("com_skipIntroVideo", "0", CVAR_BOOL,
    "skip the intro video");
idCVar com_waitForSavegames("com_waitForSavegames", "1", CVAR_BOOL,
    "during map heap reset, wait for savegames to complete");
idCVar com_headless("com_headless", "0", CVAR_BOOL,
    "run without graphics");
idCVar com_speeds("com_speeds", "0", CVAR_INTEGER,
    "show engine timings", 0.0f, 4.0f);
idCVar com_timescale("timescale", "1", CVAR_FLOAT,
    "scale game time", 0.1f, 10.0f);
idCVar com_slowmoscale("slowmoscale", "1", CVAR_FLOAT,
    "slow motion scale", 0.1f, 1.0f);
idCVar com_editorActive("com_editorActive", "0",
    CVAR_BOOL | CVAR_NOCHEAT, "1 when an editor has focus");
idCVar com_captureSamples("com_captureSamples", "1", CVAR_INTEGER,
    "number of samples for captured screenshots");
idCVar com_capturePath("com_capturePath", "", 0,
    "optional path appended to screenshots/");
idCVar com_captureTGA("com_captureTGA", "0", CVAR_INTEGER,
    "capture format: 0 JPG, 1 TGA, 2 PNG");
idCVar com_capturePrimes("com_capturePrimes", "0", CVAR_INTEGER,
    "number of prime screens used while capturing");
idCVar net_usePlatformBackend("net_usePlatformBackend", "1", CVAR_BOOL,
    "use the platform backend rather than a direct connection");
idCVar com_multiplayer("com_multiplayer", "0", CVAR_BOOL,
    "enable multiplayer code paths");
idCVar com_uploadDumps("com_uploadDumps", "1", CVAR_BOOL,
    "upload crash dumps on boot");
idCVar com_uploadDumpPath("com_writeDumpPath",
    "nfs:4@mgfiles01.ad.machinegames.com/crashdumps/", 0,
    "path used for crash dumps");
idCVar com_fixedTic("com_fixedTic", "1", CVAR_BOOL,
    "run a single game frame per render frame");
idCVar com_traceFrame("com_traceFrame", "0", CVAR_INTEGER,
    "trace a full frame");
idCVar com_useMapHeap("com_useMapHeap", "1", CVAR_BOOL,
    "use a separate heap for each map load");
idCVar com_showMapLoadStatus("com_showMapLoadStatus", "0", CVAR_BOOL,
    "show level load pacifier text");

idCommonLocal commonLocal;
idCommon* common = &commonLocal;

namespace {

constexpr std::uint32_t EVENT_FILE_MAGIC = 6172860u;
constexpr int EVENT_FILE_VERSION = 1;
constexpr int MAX_EVENT_PAYLOAD = 16 * 1024 * 1024;

std::uint32_t ByteSwap32(const std::uint32_t value) {
    return (value >> 24u) | ((value >> 8u) & 0x0000FF00u)
        | ((value << 8u) & 0x00FF0000u) | (value << 24u);
}

bool HasCaseInsensitivePrefix(const char* value, const char* prefix,
        const int length) {
    if (value == nullptr || prefix == nullptr) return false;
    for (int index = 0; index < length; ++index) {
        if (value[index] == '\0' || prefix[index] == '\0') {
            return value[index] == prefix[index];
        }
        const unsigned char left = static_cast<unsigned char>(value[index]);
        const unsigned char right = static_cast<unsigned char>(prefix[index]);
        if (std::tolower(left) != std::tolower(right)) return false;
    }
    return true;
}

void BuildCommandLine(const int argc, const char** const argv,
        const char* const supplied, idStr& text, idCmdArgs& args) {
    text.Clear();
    args.Clear();
    if (supplied != nullptr) {
        text = supplied;
        args.TokenizeString(supplied, true);
        return;
    }
    for (int index = 0; index < argc; ++index) {
        if (index > 0) text.Append(" ");
        const char* const value = argv != nullptr && argv[index] != nullptr
            ? argv[index] : "";
        text.Append(value);
        args.AppendArg(value);
    }
}

void AppendStartupToken(std::string& command, const char* const token) {
    if (!command.empty()) command.push_back(' ');
    const std::string value = token != nullptr ? token : "";
    if (value.find_first_of(" \t") == std::string::npos) {
        command += value;
    } else {
        command.push_back('"');
        command += value;
        command.push_back('"');
    }
}

void ExecuteStartupCommand(const std::string& command) {
    if (command.empty() || tech5Framework::ExecuteCommand(command.c_str())) {
        return;
    }
    if (frameworkHooks.ownerCommand != nullptr) {
        idCmdArgs args(command.c_str(), true);
        frameworkHooks.ownerCommand(args.Argv(0), args);
    }
}

void ExecuteStartupCommands(const idCmdArgs& args) {
    std::string command;
    bool collect = false;
    for (int index = 0; index < args.Argc(); ++index) {
        const char* token = args.Argv(index);
        if (token[0] == '+') {
            ExecuteStartupCommand(command);
            command.clear();
            ++token;
            if (*token == '\0' && ++index < args.Argc()) {
                token = args.Argv(index);
            }
            const bool isSet = HasCaseInsensitivePrefix(token, "set", 3);
            const bool isCVar = cvarSystem != nullptr
                && cvarSystem->Find(token) != nullptr;
            collect = !isSet && !isCVar;
            if (collect) AppendStartupToken(command, token);
        } else if (collect) {
            AppendStartupToken(command, token);
        }
    }
    ExecuteStartupCommand(command);
}

void CloseEventPlayback(idCommonLocal& local) {
    delete local.eventFile;
    local.eventFile = nullptr;
    local.recordState = RECORD_NONE;
    local.eventFileVersion = 0;
    local.readAsciiEvents = false;
    local.eventFileBigEndian = false;
    com_fixedTic.SetBool(false, true);
    if (usercmdGen != nullptr) usercmdGen->RecordPlay(0, false, nullptr);
    if (local.regression != nullptr) local.regression->SetName("");
}

} // namespace

void BitmapConsoleFatalError(const char* const message) {
    if (console != nullptr) {
        console->Print(message != nullptr ? message : "Fatal error");
        console->DrawBitmapConsole();
    }
    commonLocal.UpdateConsoleDisplay(true);
}

idCommonLocal::idCommonLocal()
    : com_fullyInitialized(false), inConsoleCommand(false),
      insideUpdateScreen(false), consoleUsed(false), server(false),
      client(false), multiplayer(false), shutdownExecuted(false),
      quitFlag(false), quitExitCode(0), frameTime(0), demoMode(DEMO_NONE),
      autosavesEnabled(true), snapshotsStalled(false),
      losingConnection(false), terminationActive(false), recentInputDevice(0),
      focusDevice(0), pauseMenuDevice(0), snapRate(30),
      recordState(RECORD_NONE), eventFileVersion(0),
      readAsciiEvents(false), eventFileBigEndian(false),
      activeReadSnapshotTag(0), activeWriteSnapshotTag(0),
      queuedSnapshotTag(0), eventFile(nullptr),
      activeReadSnapshotFile(nullptr), activeWriteSnapshotFile(nullptr),
      queuedSnapshotFile(nullptr), game(nullptr), renderWorld(nullptr),
      soundWorld(nullptr), masterProfile(nullptr), masterLocalUser(nullptr),
      regression(nullptr), videoOverlay(nullptr) {
}

idCommonLocal::~idCommonLocal() {
    CloseSnapshotFiles();
    delete eventFile;
    eventFile = nullptr;
    recordState = RECORD_NONE;
    refreshOnPrint.UnRegisterPrintListener();
    warningList.UnRegisterPrintListener();
    logFileWriter.UnRegisterPrintListener();
}

void idCommonLocal::Init(const int argc, const char** const argv,
        const char* const commandLine) {
    if (com_fullyInitialized) return;

    shutdownExecuted = false;
    quitFlag = false;
    quitExitCode = 0;
    terminationActive = false;
    idStr commandLineText;
    idCmdArgs commandLineArgs;
    BuildCommandLine(argc, argv, commandLine, commandLineText,
        commandLineArgs);
    tech5Framework::Init(commandLineText.c_str());

    idLibPrint::RegisterFatalErrorHandler(BitmapConsoleFatalError);
    ClearWarnings("Tungsten initialization");
    if (cmdSystem != nullptr) cmdSystem->Init();
    idCVar::RegisterStaticVars();
    SetCommandLineCVars(commandLineArgs, true);

    if (console != nullptr) console->Init();
    warningList.RegisterPrintListener();
    refreshOnPrint.RegisterPrintListener();

    if (fileSystem != nullptr && !fileSystem->IsInitialized()) {
        fileSystem->Init();
    }
    logFileWriter.RegisterPrintListener();
    if (resourceManager != nullptr) resourceManager->Init();
    if (streamFileCache != nullptr) streamFileCache->Init();

    SetCommandLineCVars(commandLineArgs, false);
    multiplayer = com_multiplayer.GetBool();

    if (console != nullptr) console->InitGuiModel();
    if (gameSystem != nullptr) gameSystem->Init();
    if (resourceManager != nullptr) resourceManager->SetFileHook();
    if (frameworkHooks.ownerCommand != nullptr) InitLanguageDict();
    if (resourceManager != nullptr) resourceManager->ReleaseFileHook();
    if (usercmdGen != nullptr) usercmdGen->Init();
    if (resourceManager != nullptr) resourceManager->Init2(false);
    if (console != nullptr) console->LoadGraphics();

    InitCommands();
    if (debugMenu != nullptr) debugMenu->Init();
    InitDialog();
    idResourceList::MarkAllStaticResources();
    loadScreen.Init();
    LoadMainMenu();
    if (console != nullptr) console->ClearNotifyLines();
    consoleHistory.LoadHistoryFile();

    com_fullyInitialized = true;
    {
        tech5Framework::runtimeState_t& state = tech5Framework::State();
        std::lock_guard<std::recursive_mutex> lock(state.mutex);
        state.lifecycle = tech5Framework::lifecycle_t::running;
    }
    if (resourceManager != nullptr) resourceManager->StartupComplete();
    if (cvarSystem != nullptr) cvarSystem->ClearModifiedCVars();

    idLibPrint::Printf("Command line is: %s\n", commandLineText.c_str());
    PrintWarnings();
    ExecuteStartupCommands(commandLineArgs);
}

void idCommonLocal::Quit(const int code) {
    quitExitCode = code;
    quitFlag = true;
}

void idCommonLocal::Shutdown(const int code) {
    if (shutdownExecuted) return;
    shutdownExecuted = true;
    com_fullyInitialized = false;
    quitExitCode = code;
    {
        tech5Framework::runtimeState_t& state = tech5Framework::State();
        std::lock_guard<std::recursive_mutex> lock(state.mutex);
        state.lifecycle = tech5Framework::lifecycle_t::terminating;
    }

    CloseEventPlayback(*this);
    CloseSnapshotFiles();
    if (frameworkHooks.syncRenderThread != nullptr) {
        frameworkHooks.syncRenderThread();
    }
    KillDialog();
    if (frameworkHooks.stopAllSounds != nullptr) {
        frameworkHooks.stopAllSounds();
    }
    if (gameSystem != nullptr) gameSystem->FreeGame(&game);
    insideUpdateScreen = false;
    loadScreen.Shutdown();
    if (frameworkHooks.shutdownSoundRelatedSystems != nullptr) {
        frameworkHooks.shutdownSoundRelatedSystems();
    }
    if (usercmdGen != nullptr) usercmdGen->Shutdown();
    if (streamFileCache != nullptr) streamFileCache->Shutdown();
    if (gameSystem != nullptr) gameSystem->Shutdown();
    if (resourceManager != nullptr) resourceManager->Shutdown();
    logFileWriter.CloseLogFile();
    if (console != nullptr) console->Shutdown();
    ClearWarnings("Tungsten shutdown");
    warningList.caption.Clear();
    refreshOnPrint.UnRegisterPrintListener();
    warningList.UnRegisterPrintListener();
    logFileWriter.UnRegisterPrintListener();
    tech5Framework::Shutdown();
    terminationActive = false;
    quitFlag = false;

    if (frameworkHooks.systemQuit != nullptr) {
        frameworkHooks.systemQuit(code);
    }
}

bool idCommonLocal::IsInitialized() { return com_fullyInitialized; }

void idCommonLocal::BeginTerminationThread() {
    if (terminationActive) return;
    terminationActive = true;
}

void idCommonLocal::EndTerminationThread() {
    if (!terminationActive) return;
    terminationActive = false;
}

void idCommonLocal::SyncAllBackgroundOperations(const bool exceptSounds) {
    renderManager.ClearAllGuiModels();
    if (frameworkHooks.endVirtualTexturePreloading != nullptr) {
        frameworkHooks.endVirtualTexturePreloading();
    }
    if (frameworkHooks.syncRenderThread != nullptr) {
        frameworkHooks.syncRenderThread();
    }
    if (frameworkHooks.finishVirtualTextureFeedback != nullptr) {
        frameworkHooks.finishVirtualTextureFeedback();
    }
    if (frameworkHooks.waitCollisionQueries != nullptr) {
        frameworkHooks.waitCollisionQueries();
    }
    if (frameworkHooks.waitParallelJobs != nullptr) {
        frameworkHooks.waitParallelJobs();
    }
    if (com_waitForSavegames.GetBool()
            && frameworkHooks.waitSaveGames != nullptr) {
        frameworkHooks.waitSaveGames();
    }
    if (frameworkHooks.waitSoundThread != nullptr) {
        frameworkHooks.waitSoundThread();
    }
    if (!exceptSounds && frameworkHooks.stopAllSounds != nullptr) {
        frameworkHooks.stopAllSounds();
    }
    if (streamFileCache != nullptr) streamFileCache->Flush();
}

void idCommonLocal::ActivateTool(const bool active) {
    com_editorActive.SetBool(active, true);
}

bool idCommonLocal::IsToolActive() { return com_editorActive.GetBool(); }

void idCommonLocal::InitTool(const toolFlag_t) { ActivateTool(true); }

void idCommonLocal::UpdateTool(const toolFlag_t) {
    if (IsToolActive()) UpdateConsoleDisplay(false);
}

void idCommonLocal::GetToolReferenceMap(const toolFlag_t,
        idStr* const map) {
    if (map != nullptr) *map = tech5Framework::LoadPhase();
}

void idCommonLocal::RegisterMapChangeListener(
        idMapChangeListener* const listener) {
    if (listener != nullptr && mapChangeListeners.FindIndex(listener) < 0) {
        mapChangeListeners.Append(listener);
    }
}

void idCommonLocal::UnRegisterMapChangeListener(
        idMapChangeListener* const listener) {
    mapChangeListeners.Remove(listener);
}

void idCommonLocal::RecordPlayback(const bool record,
        const char* const fileName) {
    const recordState_t previousState = recordState;
    CloseEventPlayback(*this);

    if (record && previousState == RECORD_MAKE) return;
    if (!record && previousState == RECORD_PLAY && regression != nullptr
            && regression->GetTestInProgress()) {
        regression->NextTest();
        return;
    }
    if (fileName == nullptr || *fileName == '\0' || fileSystem == nullptr) {
        return;
    }

    idStr baseName(fileName);
    baseName.StripFileExtension();
    idStr commandPath("regression/events/");
    commandPath.Append(baseName.c_str());
    commandPath.Append(".cmds");
    idStr eventPath("regression/events/");
    eventPath.Append(baseName.c_str());
    eventPath.Append(".events");

    eventFile = record
        ? fileSystem->OpenFileWrite(eventPath.c_str(), FSPATH_BASE)
        : fileSystem->OpenFileRead(eventPath.c_str());
    if (eventFile == nullptr) {
        idLibPrint::Warning("Common::RecordPlayback could not open file %s",
            eventPath.c_str());
        return;
    }
    if (usercmdGen == nullptr
            || !usercmdGen->RecordPlay(0, record, commandPath.c_str())) {
        idLibPrint::Warning("Common::RecordPlayback could not open file %s",
            commandPath.c_str());
        CloseEventPlayback(*this);
        return;
    }

    recordState = record ? RECORD_MAKE : RECORD_PLAY;
    com_fixedTic.SetBool(true, true);
    if (regression != nullptr) regression->SetName(baseName.c_str());

    if (record) {
        const std::uint32_t magic = EVENT_FILE_MAGIC;
        const int version = EVENT_FILE_VERSION;
        if (eventFile->Write(&magic, sizeof(magic)) != sizeof(magic)
                || eventFile->Write(&version, sizeof(version))
                    != sizeof(version)) {
            idLibPrint::Warning("Common::RecordPlayback could not write %s",
                eventPath.c_str());
            CloseEventPlayback(*this);
        } else {
            eventFileVersion = version;
        }
        return;
    }

    std::uint32_t magic = 0;
    if (eventFile->Read(&magic, sizeof(magic)) == sizeof(magic)
            && (magic == EVENT_FILE_MAGIC
                || ByteSwap32(magic) == EVENT_FILE_MAGIC)) {
        eventFileBigEndian = magic != EVENT_FILE_MAGIC;
        std::uint32_t version = 0;
        if (eventFile->Read(&version, sizeof(version)) != sizeof(version)) {
            CloseEventPlayback(*this);
            return;
        }
        if (eventFileBigEndian) version = ByteSwap32(version);
        eventFileVersion = static_cast<int>(version);
    } else {
        eventFileVersion = 0;
        eventFileBigEndian = false;
        eventFile->Seek(0, FS_SEEK_SET);
    }
}

void idCommonLocal::SetCommandLineCVars(const idCmdArgs& args,
        const bool init) {
    for (int index = 0; index < args.Argc(); ++index) {
        const char* token = args.Argv(index);
        if (token == nullptr || token[0] != '+') continue;
        ++token;
        if (*token == '\0' && ++index < args.Argc()) {
            token = args.Argv(index);
        }
        if (HasCaseInsensitivePrefix(token, "set", 3)) {
            if (++index >= args.Argc()) break;
            token = args.Argv(index);
        }
        idCVar* const variable = cvarSystem != nullptr
            ? cvarSystem->Find(token) : nullptr;
        if (variable == nullptr || ((variable->GetFlags() & CVAR_INIT) != 0
                && !init) || index + 1 >= args.Argc()) {
            continue;
        }
        variable->SetString(args.Argv(++index), true);
    }
}

void idCommonLocal::WriteSysEvent(const sysEvent_t& event) {
    if (eventFile == nullptr || recordState != RECORD_MAKE) return;
    eventFile->Write(&event.evPtrLength, sizeof(event.evPtrLength));
    if (event.evPtrLength > 0 && event.evPtr != nullptr) {
        eventFile->Write(event.evPtr,
            static_cast<unsigned int>(event.evPtrLength));
    }
    eventFile->Write(&event.evType, sizeof(event.evType));
    eventFile->Write(&event.evValue, sizeof(event.evValue));
    eventFile->Write(&event.evValue2, sizeof(event.evValue2));
    eventFile->Write(&event.inputDevice, sizeof(event.inputDevice));
}

bool idCommonLocal::ReadSysEvent(sysEvent_t& event) {
    if (eventFile == nullptr || recordState != RECORD_PLAY) return false;
    if (event.evPtr != nullptr) {
        Sys_Free(event.evPtr);
        event.evPtr = nullptr;
    }

    std::uint32_t rawLength = 0;
    unsigned int bytesRead = eventFile->Read(&rawLength, sizeof(rawLength));
    if (bytesRead != sizeof(rawLength)) {
        RecordPlayback(false, nullptr);
        return false;
    }
    std::uint32_t length = eventFileBigEndian
        ? ByteSwap32(rawLength) : rawLength;
    if (eventFileVersion == 0 && !eventFileBigEndian) {
        const std::uint32_t swapped = ByteSwap32(rawLength);
        if ((length > MAX_EVENT_PAYLOAD
                || (length > 1024u * 1024u && swapped < length))
                && swapped <= MAX_EVENT_PAYLOAD) {
            eventFileBigEndian = true;
            length = swapped;
        }
    }
    if (length > MAX_EVENT_PAYLOAD) {
        RecordPlayback(false, nullptr);
        return false;
    }
    event.evPtrLength = static_cast<int>(length);
    if (event.evPtrLength > 0) {
        event.evPtr = Sys_Alloc(length, TAG_TEMP);
        if (event.evPtr == nullptr) {
            RecordPlayback(false, nullptr);
            return false;
        }
        bytesRead += eventFile->Read(event.evPtr, length);
    }

    std::uint32_t values[4] = {};
    for (std::uint32_t& value : values) {
        bytesRead += eventFile->Read(&value, sizeof(value));
        if (eventFileBigEndian) value = ByteSwap32(value);
    }
    if (eventFileVersion == 0 && !eventFileBigEndian
            && values[0] > static_cast<std::uint32_t>(SE_CONSOLE)
            && ByteSwap32(values[0])
                <= static_cast<std::uint32_t>(SE_CONSOLE)) {
        eventFileBigEndian = true;
        for (std::uint32_t& value : values) value = ByteSwap32(value);
    }
    event.evType = static_cast<sysEventType_t>(values[0]);
    event.evValue = static_cast<int>(values[1]);
    event.evValue2 = static_cast<int>(values[2]);
    event.inputDevice = static_cast<int>(values[3]);

    if (bytesRead == length + 20u) {
        if (eventFileVersion < 1 && event.evType == SE_KEY) {
            readAsciiEvents = true;
            idLibPrint::Warning("Event key values may be in ASCII format; "
                "re-record this event file for portable playback.");
        }
        return true;
    }
    if (event.evPtr != nullptr) {
        Sys_Free(event.evPtr);
        event.evPtr = nullptr;
    }
    event.evPtrLength = 0;
    RecordPlayback(false, nullptr);
    return false;
}

void idCommonLocal::ResetMapHeap() {
    SyncAllBackgroundOperations(false);
    if (frameworkHooks.resetNetworkingState != nullptr) {
        frameworkHooks.resetNetworkingState();
    }
    tech5Framework::ClearNetworkMessages();
    renderManager.Clear();
    KillDialog();
    if (console != nullptr) console->ClearEditLine();
    ClearWarnings("");
    if (frameworkHooks.unbindAllVideos != nullptr) {
        frameworkHooks.unbindAllVideos();
    }
    if (frameworkHooks.resetVirtualTextures != nullptr) {
        frameworkHooks.resetVirtualTextures();
    }

    const bool canReset = frameworkHooks.canResetMapHeap != nullptr
        ? frameworkHooks.canResetMapHeap() : renderWorld == nullptr;
    if (canReset) {
        if (frameworkHooks.shutdownSoundRelatedSystems != nullptr) {
            frameworkHooks.shutdownSoundRelatedSystems();
        }
        if (streamFileCache != nullptr) streamFileCache->ClearMem(true);
        idResourceList::FreeAllDynamicResources();
        if (frameworkHooks.freeDynamicMapResources != nullptr) {
            frameworkHooks.freeDynamicMapResources();
        }
        if (com_useMapHeap.GetBool()) mem.ResetMapHeap();
        if (frameworkHooks.initializeSoundRelatedSystems != nullptr) {
            frameworkHooks.initializeSoundRelatedSystems();
        }
    }
    InitDialog();
}

void idCommonLocal::UploadCrashDumps() {
    // The dump uploader is platform/network owned. AMQP remains intentionally
    // outside this framework conversion until that subsystem is recovered.
    idCmdArgs args("uploadCrashDumps", true);
    if (frameworkHooks.ownerCommand != nullptr) {
        frameworkHooks.ownerCommand("uploadCrashDumps", args);
    }
}

void idCommonLocal::Frame() {
    if (!com_fullyInitialized) return;
    tech5Framework::RunFrame(frameTime);
    if (quitFlag) Shutdown(quitExitCode);
}

void idCommonLocal::UpdateConsoleDisplay(const bool force) {
    if (insideUpdateScreen || (!force && !com_fullyInitialized)) return;
    insideUpdateScreen = true;
    renderManager.UpdateConsole();
    insideUpdateScreen = false;
}

void idCommonLocal::WriteConfigToFile(const char* const filename) {
    if (fileSystem == nullptr || filename == nullptr || *filename == '\0') {
        return;
    }
    idFile* const file = fileSystem->OpenFileWrite(filename, FSPATH_BASE);
    if (file == nullptr) return;
    file->Printf("// generated by recovered idTech 5 framework\n");
    file->Printf("configVersion %d\n", 1);
    if (cvarSystem != nullptr) {
        cvarSystem->WriteFlaggedVariables(CVAR_ARCHIVE, file);
    }
    file->Flush();
    delete file;
}

bool idCommonLocal::IsMainMenuActive() {
    return tech5Framework::SessionState()
        == tech5Framework::sessionState_t::idle;
}

bool idCommonLocal::IsGamePaused() {
    return tech5Framework::SessionState()
        == tech5Framework::sessionState_t::paused;
}

bool idCommonLocal::IsInGame() {
    return tech5Framework::SessionState()
        == tech5Framework::sessionState_t::active;
}

bool idCommonLocal::IsServer() { return server; }
bool idCommonLocal::IsClient() { return client; }
bool idCommonLocal::IsMultiplayer() { return multiplayer; }

void idCommonLocal::SetInitialized(const bool value) {
    com_fullyInitialized = value;
    tech5Framework::runtimeState_t& state = tech5Framework::State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    state.lifecycle = value ? tech5Framework::lifecycle_t::running
        : tech5Framework::lifecycle_t::stopped;
}
