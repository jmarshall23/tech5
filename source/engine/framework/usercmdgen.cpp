#include "framework/framework_runtime_internal.h"

#include "framework/usercmdgen.h"
#include "framework/framework_hooks.h"
#include "framework/keyinput.h"
#include "idlib/csystems/cvarsystem.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/lib_print.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace tech5Framework {
void SubmitUserCommand(const userCommand_t& command) { runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); auto found = state.userCommands.find(command.deviceNum); if (found == state.userCommands.end() || command.sequence >= found->second.sequence) state.userCommands[command.deviceNum] = command; }
bool GetUserCommand(int deviceNum, userCommand_t& command) { runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); const auto found = state.userCommands.find(deviceNum); if (found == state.userCommands.end()) return false; command = found->second; return true; }
void ClearUserCommands() { runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); state.userCommands.clear(); }
} // namespace tech5Framework

idUsercmdGenLocal usercmdGenLocal;
idUsercmdGen* usercmdGen = &usercmdGenLocal;

void usercmd_t::Print() const {
    idLibPrint::Printf("buttons=%d move=(%d,%d,%d) angles=(%d,%d,%d)\n",
        buttons, forwardmove, rightmove, upmove, angles[0], angles[1], angles[2]);
}

namespace {

struct userCmdString_t {
    const char* string;
    cmdGenButton_t button;
};

const userCmdString_t USER_COMMAND_STRINGS[] = {
    {"_attack", UB_ATTACK1}, {"_attack1", UB_ATTACK1},
    {"_attack2", UB_ATTACK2}, {"_altattack", UB_ATTACK2},
    {"_use", UB_USE}, {"_zoom", UB_ZOOM}, {"_sprint", UB_SPRINT},
    {"_useAndReload", UB_USE_AND_RELOAD},
    {"_changeWeapon", UB_CHANGEWEAPON}, {"_reload", UB_WEAP_RELOAD},
    {"_weapnext", UB_WEAP_NEXT}, {"_weapprev", UB_WEAP_PREV},
    {"_weapon0", UB_WEAP_0}, {"_weapon1", UB_WEAP_1},
    {"_weapon2", UB_WEAP_2}, {"_weapon3", UB_WEAP_3},
    {"_weapon4", UB_WEAP_4}, {"_weapon5", UB_WEAP_5},
    {"_weapNextInInventory", UB_WEAP_NEXT_IN_INV},
    {"_weapPrevInInventory", UB_WEAP_PREV_IN_INV},
    {"_weapPrevEquipped", UB_WEAP_PREV_EQUIPPED},
    {"_toggleDualWield", UB_TOGGLEDUALWIELD},
    {"_quickUse", UB_QUICK_USE}, {"_quickSelect", UB_QUICK_SELECT},
    {"_coverMode", UB_COVERMODE}, {"_cycleTarget", UB_CYCLE_TARGET},
    {"_switchPosition", UB_SWITCH_POS}, {"_scores", UB_SCOREBOARD},
    {"_inventory", UB_INVENTORY},
    {"_toggleFireModeLeft", UB_TOGGLEFIREMODE_LEFT},
    {"_toggleFireModeRight", UB_TOGGLEFIREMODE_RIGHT},
    {"_nextQuickItem", UB_NEXT_QUICK_ITEM},
    {"_prevQuickItem", UB_PREV_QUICK_ITEM},
    {"_moveUp", UB_MOVEUP}, {"_moveDown", UB_MOVEDOWN},
    {"_moveLeft", UB_MOVELEFT}, {"_moveRight", UB_MOVERIGHT},
    {"_forward", UB_MOVEFORWARD}, {"_back", UB_MOVEBACK},
    {"_lookup", UB_LOOKUP}, {"_lookdown", UB_LOOKDOWN},
    {"_left", UB_LOOKLEFT}, {"_right", UB_LOOKRIGHT},
    {nullptr, UB_NONE}
};

signed char ButtonAxis(const bool positive, const bool negative) {
    return static_cast<signed char>((positive ? 127 : 0)
        - (negative ? 127 : 0));
}

int MacroDevice() {
    const idCVar* const overrideCVar = cvarSystem != nullptr
        ? cvarSystem->Find("mp_bot_input_override") : nullptr;
    const int requested = overrideCVar != nullptr
        ? overrideCVar->GetInteger() : 0;
    return requested >= 0 && requested < 6 ? requested : 0;
}

idStr DefaultMacroName(const int device) {
    idStr name;
    name.Format("temp.macro.%d.cmd", device);
    return name;
}

signed char AddMove(const signed char lhs, const signed char rhs) {
    return static_cast<signed char>((std::max)(-128,
        (std::min)(127, static_cast<int>(lhs) + static_cast<int>(rhs))));
}

} // namespace

const char* UsercmdActionString(const int action) {
    for (const userCmdString_t* entry = USER_COMMAND_STRINGS;
            entry->string != nullptr; ++entry) {
        if (entry->button == action) return entry->string;
    }
    return "";
}

idUsercmdGenLocal::idUsercmdGenLocal()
    : pollTime(0), devices{}, buttonState{}, lastCommandTime(0),
      initialized(false), currentDeviceNum(0), currentDevice(&devices[0]),
      currentSettings(), mouseDx(0.0f), mouseDy(0.0f), lastInputFrame(0),
      cmdFiles{}, recording{}, loopPlayCmds{}, aimAssist(true),
      joystickSnapDisabled(false), lastUsedLookValue{},
      lastUsedLookValuePitch{}, allowButtonInputDuringPlay(false) {
    cmd.Clear();
}
idUsercmdGenLocal::~idUsercmdGenLocal() {
    for (idFile*& file : cmdFiles) {
        delete file;
        file = nullptr;
    }
}
void idUsercmdGenLocal::Init() { initialized = true; Clear(); }
void idUsercmdGenLocal::Shutdown() {
    for (int device = 0; device < 6; ++device) {
        delete cmdFiles[device];
        cmdFiles[device] = nullptr;
        recording[device] = false;
    }
    initialized = false;
    Clear();
}
void idUsercmdGenLocal::Clear() {
    for (usercmdDevice_t& device : devices) {
        std::memset(device.keyState, 0, sizeof(device.keyState));
        std::memset(device.joystickAxis, 0, sizeof(device.joystickAxis));
        device.angles = idAngles(0.0f, 0.0f, 0.0f);
        device.lastPollTime = 0;
    }
    std::memset(buttonState, 0, sizeof(buttonState));
    currentSettings = inputSettings_t();
    currentDeviceNum = 0;
    currentDevice = &devices[0];
    lastInputFrame = 0;
    mouseDx = mouseDy = 0.0f;
    cmd.Clear();
    tech5Framework::ClearUserCommands();
}
void idUsercmdGenLocal::ClearAngles() { cmd.angles[0] = cmd.angles[1] = cmd.angles[2] = 0; }
void idUsercmdGenLocal::SaveGame(idFile* file) { if (file != nullptr) file->Write(&cmd, sizeof(cmd)); }
bool idUsercmdGenLocal::LoadGame(idFile* file) { return file != nullptr && file->Read(&cmd, sizeof(cmd)) == sizeof(cmd); }
cmdGenButton_t idUsercmdGenLocal::BindStringUsercmdAction(
        const char* const command) const {
    if (command == nullptr) return UB_NONE;
    for (const userCmdString_t* entry = USER_COMMAND_STRINGS;
         entry->string != nullptr; ++entry) {
        if (idStr::Icmp(command, entry->string) == 0) return entry->button;
    }
    return UB_NONE;
}

void idUsercmdGenLocal::Key(const int inputDeviceNum, const int keyNum,
        const bool down) {
    if (inputDeviceNum < 0 || inputDeviceNum >= 4
        || keyNum < 0 || keyNum >= 296) return;
    devices[inputDeviceNum].keyState[keyNum] = down;
    const int action = idKeyInput::GetUsercmdAction(inputDeviceNum,
        static_cast<bindSet_t>(currentSettings.bindset),
        static_cast<keyNum_t>(keyNum));
    if (action >= 0 && action < UB_MAX) buttonState[action] = down;
}

void idUsercmdGenLocal::Mouse(const int device) {
    if (frameworkHooks.pollMouse != nullptr) {
        frameworkHooks.pollMouse(*this, device);
    }
}
void idUsercmdGenLocal::Keyboard(const int device) {
    if (frameworkHooks.pollKeyboard != nullptr) {
        frameworkHooks.pollKeyboard(*this, device);
    }
}
void idUsercmdGenLocal::Joystick(const int device) {
    if (frameworkHooks.pollJoystick != nullptr) {
        frameworkHooks.pollJoystick(*this, device);
    }
}

void idUsercmdGenLocal::KeyMove() {
    cmd.forwardmove = ButtonAxis(buttonState[UB_MOVEFORWARD],
        buttonState[UB_MOVEBACK]);
    cmd.rightmove = ButtonAxis(buttonState[UB_MOVERIGHT],
        buttonState[UB_MOVELEFT]);
    cmd.upmove = ButtonAxis(buttonState[UB_MOVEUP], buttonState[UB_MOVEDOWN]);
}

void idUsercmdGenLocal::MouseMove() {
    float yawDelta = mouseDx * currentSettings.mouseSens
        * currentSettings.mouseSensScale;
    float pitchDelta = mouseDy * currentSettings.mouseSens
        * currentSettings.mouseSensScale;
    if (currentSettings.lookInvert) pitchDelta = -pitchDelta;
    currentDevice->angles.yaw -= yawDelta;
    currentDevice->angles.pitch += pitchDelta;
    mouseDx = mouseDy = 0.0f;
}

void idUsercmdGenLocal::CircleToSquare(float& x, float& y) const {
    const float originalX = x;
    const float originalY = y;
    x = originalX * std::sqrt((std::max)(0.0f,
        1.0f - 0.5f * originalY * originalY));
    y = originalY * std::sqrt((std::max)(0.0f,
        1.0f - 0.5f * originalX * originalX));
}

void idUsercmdGenLocal::HandleJoystickAxis(const int axis,
        const int actionNegative, const int actionPositive,
        const float threshold, const float value, const bool digital) {
    if (axis >= 0 && axis < 6) currentDevice->joystickAxis[axis] = value;
    if (!digital) return;
    if (actionNegative >= 0 && actionNegative < UB_MAX) {
        buttonState[actionNegative] = value < -threshold;
    }
    if (actionPositive >= 0 && actionPositive < UB_MAX) {
        buttonState[actionPositive] = value > threshold;
    }
}

void idUsercmdGenLocal::JoystickMove(const int elapsedMilliseconds) {
    const float seconds = (std::max)(elapsedMilliseconds, 0) * 0.001f;
    currentDevice->angles.yaw -= currentDevice->joystickAxis[2]
        * currentSettings.joyYawSpeed * currentSettings.joySensScale * seconds;
    float pitch = currentDevice->joystickAxis[3]
        * currentSettings.joyPitchSpeed * currentSettings.joySensScale * seconds;
    currentDevice->angles.pitch += currentSettings.lookInvert ? -pitch : pitch;
}

void idUsercmdGenLocal::AimAssist() {
    if (frameworkHooks.aimAssist != nullptr) {
        frameworkHooks.aimAssist(cmd, currentDeviceNum, currentSettings);
    }
}
void idUsercmdGenLocal::WeaponKick() {
    if (frameworkHooks.weaponKick != nullptr) {
        frameworkHooks.weaponKick(cmd, currentDeviceNum, currentSettings);
    }
}

usercmd_t idUsercmdGenLocal::GetUsercmd(const int device,
        const inputSettings_t& settings, const bool inhibit, const int frame) {
    if (device >= 0 && device < 4) {
        currentDeviceNum = device;
        currentDevice = &devices[device];
    }
    currentSettings = settings;

    const int now = frameworkHooks.milliseconds != nullptr
        ? frameworkHooks.milliseconds() : frame * 16;
    const int previousPoll = currentDevice->lastPollTime;
    pollTime = now;
    cmd.Clear();
    std::memset(buttonState, 0, sizeof(buttonState));
    Mouse(device);
    Keyboard(device);
    Joystick(device);
    for (int key = 0; key < 296; ++key) {
        if (!currentDevice->keyState[key]) continue;
        const int action = idKeyInput::GetUsercmdAction(device,
            static_cast<bindSet_t>(currentSettings.bindset),
            static_cast<keyNum_t>(key));
        if (action >= 0 && action < UB_MAX) buttonState[action] = true;
    }

    cmd.inhibited = inhibit;
    cmd.clientGameFrame = frame;
    cmd.buttons = 0;
    for (int action = 0; action < 32 && action < UB_MAX; ++action) {
        if (buttonState[action]) cmd.buttons |= 1 << action;
    }
    cmd.buttons2 = 0;
    for (int action = 32; action < UB_MAX; ++action) {
        if (buttonState[action]) cmd.buttons2 |= 1 << (action - 32);
    }
    if (inhibit) {
        cmd.ClearMoveCmds();
        mouseDx = mouseDy = 0.0f;
    } else {
        KeyMove();
        MouseMove();
        JoystickMove((std::max)(0, now - previousPoll));
        if (aimAssist) AimAssist();
        WeaponKick();
    }
    cmd.angles[0] = static_cast<std::int16_t>(currentDevice->angles.pitch
        * (65536.0f / 360.0f));
    cmd.angles[1] = static_cast<std::int16_t>(currentDevice->angles.yaw
        * (65536.0f / 360.0f));
    cmd.angles[2] = static_cast<std::int16_t>(currentDevice->angles.roll
        * (65536.0f / 360.0f));
    currentDevice->lastPollTime = now;

    if (device >= 0 && device < 6 && cmdFiles[device] != nullptr) {
        if (recording[device]) {
            cmdFiles[device]->Write(&cmd, sizeof(cmd));
        } else {
            const usercmd_t liveCmd = cmd;
            usercmd_t recordedCmd;
            bool haveRecordedCmd =
                cmdFiles[device]->Read(&recordedCmd, sizeof(recordedCmd))
                    == sizeof(recordedCmd);
            if (!haveRecordedCmd && loopPlayCmds[device] != 0) {
                if (loopPlayCmds[device] > 0) --loopPlayCmds[device];
                cmdFiles[device]->Seek(0, FS_SEEK_SET);
                haveRecordedCmd =
                    cmdFiles[device]->Read(&recordedCmd, sizeof(recordedCmd))
                        == sizeof(recordedCmd);
            }
            if (haveRecordedCmd) {
                cmd = recordedCmd;
                if (allowButtonInputDuringPlay) {
                    cmd.buttons |= liveCmd.buttons;
                    cmd.buttons2 |= liveCmd.buttons2;
                    cmd.forwardmove = AddMove(cmd.forwardmove,
                        liveCmd.forwardmove);
                    cmd.rightmove = AddMove(cmd.rightmove,
                        liveCmd.rightmove);
                    cmd.upmove = AddMove(cmd.upmove, liveCmd.upmove);
                }
            } else {
                delete cmdFiles[device];
                cmdFiles[device] = nullptr;
                loopPlayCmds[device] = 0;
                allowButtonInputDuringPlay = false;
            }
        }
    }
    tech5Framework::userCommand_t portable = {device, frame, cmd.buttons,
        static_cast<float>(cmd.forwardmove), static_cast<float>(cmd.rightmove),
        static_cast<float>(cmd.yaw), static_cast<float>(cmd.pitch)};
    tech5Framework::SubmitUserCommand(portable);
    lastInputFrame = frame;
    return cmd;
}

void idUsercmdGenLocal::GetRecordedUserCmd(const int device,
        usercmd_t& result) {
    const usercmd_t liveCmd = result;
    if (device >= 0 && device < 6 && cmdFiles[device] != nullptr
            && !recording[device]) {
        usercmd_t recordedCmd;
        if (cmdFiles[device]->Read(&recordedCmd, sizeof(recordedCmd))
                == sizeof(recordedCmd)) {
            result = recordedCmd;
            if (allowButtonInputDuringPlay) {
                result.buttons |= liveCmd.buttons;
                result.buttons2 |= liveCmd.buttons2;
                result.forwardmove = AddMove(result.forwardmove,
                    liveCmd.forwardmove);
                result.rightmove = AddMove(result.rightmove,
                    liveCmd.rightmove);
                result.upmove = AddMove(result.upmove, liveCmd.upmove);
            }
            return;
        }
    }
    result = cmd;
}

bool idUsercmdGenLocal::RecordPlay(const int device, const bool record,
        const char* const fileName) {
    if (device < 0 || device >= 6) return false;
    delete cmdFiles[device];
    cmdFiles[device] = nullptr;
    recording[device] = false;
    loopPlayCmds[device] = 0;
    if (fileName == nullptr || *fileName == '\0') return true;
    if (fileSystem == nullptr) return false;
    cmdFiles[device] = record
        ? fileSystem->OpenFileWrite(fileName, FSPATH_BASE)
        : fileSystem->OpenFileRead(fileName);
    recording[device] = record && cmdFiles[device] != nullptr;
    return cmdFiles[device] != nullptr;
}

bool idUsercmdGenLocal::GetUseAimAssist() const { return aimAssist; }

void RegisterUsercmdCommands() {
    tech5Framework::RegisterCommand("CmdMacroRecord",
        [](const std::vector<idStr>& args) {
            const int device = MacroDevice();
            const idStr defaultName = DefaultMacroName(device);
            const char* const fileName = args.size() > 1
                ? args[1].c_str() : defaultName.c_str();
            if (usercmdGenLocal.RecordPlay(device, true, fileName)) {
                usercmdGenLocal.loopPlayCmds[device] = 0;
                usercmdGenLocal.allowButtonInputDuringPlay = false;
                idLibPrint::Printf("Recording cmd macro to %s\n", fileName);
            } else {
                idLibPrint::Warning(
                    "CmdMacroRecord: couldn't open %s", fileName);
            }
        });
    tech5Framework::RegisterCommand("CmdMacroStop",
        [](const std::vector<idStr>&) {
            const int device = MacroDevice();
            delete usercmdGenLocal.cmdFiles[device];
            usercmdGenLocal.cmdFiles[device] = nullptr;
            usercmdGenLocal.recording[device] = false;
            usercmdGenLocal.loopPlayCmds[device] = 0;
            usercmdGenLocal.allowButtonInputDuringPlay = false;
            idLibPrint::Printf("Stopped Cmd Macro\n");
        });
    tech5Framework::RegisterCommand("CmdMacroPlay",
        [](const std::vector<idStr>& args) {
            const int device = MacroDevice();
            const idStr defaultName = DefaultMacroName(device);
            const char* const fileName = args.size() > 1
                ? args[1].c_str() : defaultName.c_str();
            const int loops = args.size() > 2
                ? std::atoi(args[2].c_str()) : -1;
            if (usercmdGenLocal.RecordPlay(device, false, fileName)) {
                usercmdGenLocal.loopPlayCmds[device] = loops;
                usercmdGenLocal.allowButtonInputDuringPlay = true;
                idLibPrint::Printf("Playing cmd macro %s\n", fileName);
            } else {
                idLibPrint::Warning("CmdMacroPlay: couldn't open %s",
                    fileName);
            }
        });
}
