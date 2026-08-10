#include "framework/framework_runtime_internal.h"

#include "framework/common_local.h"
#include "framework/framework_hooks.h"
#include "framework/keyinput.h"
#include "framework/resourcelist.h"
#include "framework/usercmdgen.h"
#include "idlib/csystems/cvarsystem.h"

namespace tech5Framework {
void SetSessionState(sessionState_t value) { runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); state.session = value; }
sessionState_t SessionState() { runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); return state.session; }
} // namespace tech5Framework

idFile* idCommonLocal::DetachActiveReadSnapshotFile() {
    idFile* const result = activeReadSnapshotFile;
    activeReadSnapshotFile = nullptr;
    activeReadSnapshotTag = 0;
    return result;
}

idFile* idCommonLocal::DetachActiveWriteSnapshotFile() {
    idFile* const result = activeWriteSnapshotFile;
    activeWriteSnapshotFile = nullptr;
    activeWriteSnapshotTag = 0;
    return result;
}

idFile* idCommonLocal::GetActiveReadSnapshotFile() {
    return activeReadSnapshotFile;
}

idFile* idCommonLocal::GetActiveWriteSnapshotFile() {
    return activeWriteSnapshotFile;
}

snapshotState_t idCommonLocal::SnapshotState() {
    return static_cast<snapshotState_t>(activeReadSnapshotFile != nullptr
        ? 1 : activeWriteSnapshotFile != nullptr ? 2 : 0);
}

void idCommonLocal::QueueSnapshotMemFile(idFile_Memory* const file,
        const unsigned int tag) {
    if (queuedSnapshotFile != file) delete queuedSnapshotFile;
    queuedSnapshotFile = file;
    queuedSnapshotTag = tag;
}

void idCommonLocal::ClearQueuedSnapshotFile() {
    delete queuedSnapshotFile;
    queuedSnapshotFile = nullptr;
    queuedSnapshotTag = 0;
}

void idCommonLocal::PlayQueuedSnapshotFile() {
    StopSnapshotFilePlayback();
    activeReadSnapshotFile = queuedSnapshotFile;
    activeReadSnapshotTag = queuedSnapshotTag;
    queuedSnapshotFile = nullptr;
    queuedSnapshotTag = 0;
    if (activeReadSnapshotFile != nullptr) {
        activeReadSnapshotFile->Seek(0, FS_SEEK_SET);
        demoMode = DEMO_PLAY;
    }
}

void idCommonLocal::RecordSnapshotFile(idFile* const file,
        const unsigned int tag) {
    StopSnapshotFileRecord();
    activeWriteSnapshotFile = file;
    activeWriteSnapshotTag = tag;
    demoMode = file != nullptr ? DEMO_RECORD : DEMO_NONE;
}

void idCommonLocal::PlaySnapshotFile(idFile* const file,
        const unsigned int tag) {
    StopSnapshotFilePlayback();
    activeReadSnapshotFile = file;
    activeReadSnapshotTag = tag;
    demoMode = file != nullptr ? DEMO_PLAY : DEMO_NONE;
}

void idCommonLocal::StopSnapshotFilePlayback() {
    delete activeReadSnapshotFile;
    activeReadSnapshotFile = nullptr;
    activeReadSnapshotTag = 0;
    if (!DemoRecording()) {
        demoMode = DEMO_NONE;
    }
}

void idCommonLocal::StopSnapshotFileRecord() {
    if (activeWriteSnapshotFile != nullptr) activeWriteSnapshotFile->Flush();
    delete activeWriteSnapshotFile;
    activeWriteSnapshotFile = nullptr;
    activeWriteSnapshotTag = 0;
    if (!DemoPlaying()) {
        demoMode = DEMO_NONE;
    }
}

void idCommonLocal::CloseSnapshotFiles() {
    StopSnapshotFilePlayback();
    StopSnapshotFileRecord();
    ClearQueuedSnapshotFile();
}

bool idCommonLocal::DemoPlaying() {
    return demoMode == DEMO_PLAY || demoMode == DEMO_TIMETRIAL;
}

bool idCommonLocal::DemoRecording() {
    return demoMode == DEMO_RECORD || demoMode == DEMO_RECORD_CLIENT;
}

bool idCommonLocal::TimeTrialPlaying() {
    return demoMode == DEMO_TIMETRIAL && activeReadSnapshotFile != nullptr;
}

bool idCommonLocal::TimeTrialRecording() {
    return demoMode == DEMO_TIMETRIAL && activeWriteSnapshotFile != nullptr;
}

recordState_t idCommonLocal::GetRecordState() {
    return recordState;
}

idPlayerProfile* idCommonLocal::GetProfileFromMasterLocalUser() {
    return masterProfile;
}
int idCommonLocal::GetMasterLocalUserInputDevice() { return focusDevice; }
int idCommonLocal::GetMasterLocalUserPlayerId() { return 0; }
idLocalUser* idCommonLocal::GetMasterLocalUser() { return masterLocalUser; }

void idCommonLocal::ResetPlayerInput(int) {
    idKeyInput::ClearStates();
    if (usercmdGen != nullptr) usercmdGen->Clear();
}

void idCommonLocal::UpdateBotUserCmds(const int player,
        const usercmd_t* const command) {
    if (command == nullptr) return;
    tech5Framework::userCommand_t portable = {player,
        command->clientGameFrame, command->buttons,
        static_cast<float>(command->forwardmove),
        static_cast<float>(command->rightmove),
        static_cast<float>(command->yaw), static_cast<float>(command->pitch)};
    tech5Framework::SubmitUserCommand(portable);
}

int idCommonLocal::GetRecentInputDevice() { return recentInputDevice; }
int idCommonLocal::GetFocusDeviceNum() { return focusDevice; }
void idCommonLocal::SetFocusDeviceNum(const int deviceNum) {
    focusDevice = deviceNum;
    recentInputDevice = deviceNum;
}
int idCommonLocal::GetPauseMenuDeviceNum() { return pauseMenuDevice; }
void idCommonLocal::SetPauseMenuDeviceNum(const int deviceNum) {
    pauseMenuDevice = deviceNum;
}
bool idCommonLocal::GetAutosaveEnabled() { return autosavesEnabled; }
void idCommonLocal::EnableAutosaves(const bool enabled) {
    autosavesEnabled = enabled;
}
void idCommonLocal::ShowSaveIndicator(const bool show, bool) {
    tech5Framework::runtimeState_t& state = tech5Framework::State();
    {
        std::lock_guard<std::recursive_mutex> lock(state.mutex);
        state.saveIndicatorRequested = show;
        if (show) {
            const int now = frameworkHooks.milliseconds != nullptr
                ? frameworkHooks.milliseconds() : state.milliseconds;
            const idCVar* const clearTime = cvarSystem != nullptr
                ? cvarSystem->Find("dialog_saveClearLevel1") : nullptr;
            state.saveIndicatorClearTime = now
                + (clearTime != nullptr ? clearTime->GetInteger() : 1000);
        }
    }
    if (frameworkHooks.showSaveIndicator != nullptr) {
        frameworkHooks.showSaveIndicator(show);
    }
}

idGame* idCommonLocal::Game() { return game; }
idRenderWorld* idCommonLocal::RW() { return renderWorld; }
idSoundWorld* idCommonLocal::SW() { return soundWorld; }
const idGame* idCommonLocal::Game_2() const { return game; }
idRegression* idCommonLocal::GetRegression() { return regression; }

void idCommonLocal::PrepareForMapChange() {
    SyncAllBackgroundOperations(true);
    tech5Framework::SetSessionState(tech5Framework::sessionState_t::loading);
    idResourceList::ResetNetworkResources();
}

void idCommonLocal::FinalizeMapChange(const idGameSpawnInfo&,
        idFile*) {
    tech5Framework::SetSessionState(tech5Framework::sessionState_t::active);
}

void idCommonLocal::ExecuteMapChange(const idGameSpawnInfo*, idFile*) {
    PrepareForMapChange();
    tech5Framework::SetSessionState(tech5Framework::sessionState_t::active);
}

void idCommonLocal::LoadMainMenu() {
    tech5Framework::SetSessionState(tech5Framework::sessionState_t::idle);
}

void idCommonLocal::LeaveGame(bool) {
    idResourceList::ResetNetworkResources();
    tech5Framework::SetSessionState(tech5Framework::sessionState_t::idle);
}

void idCommonLocal::Disconnect(const bool force) { LeaveGame(force); }
