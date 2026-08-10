#include "framework/keyinput.h"
#include "framework/framework_runtime.h"

#include "idlib/csystems/cvarsystem.h"
#include "idlib/lib_print.h"
#include "idlib/text/str.h"

#include <algorithm>
#include <array>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <map>
#include <string>

namespace {
struct keyState_t {
    bool down = false;
    std::array<std::string, BIND_MAX> bindings;
};

std::map<int, std::array<keyState_t, K_LAST_KEY>> deviceStates;
int bindDevice = 0;
thread_local char keyName[32];

idCVar in_bindset("in_bindset", "0", CVAR_INTEGER | CVAR_ARCHIVE,
    "active key binding set", 0.0f, static_cast<float>(BIND_MAX - 1));
idCVar key_deviceBindOverride("key_deviceBindOverride", "-1", CVAR_INTEGER,
    "override the input device used by bind commands", -1.0f, 3.0f);

struct namedKey_t { const char* name; keyNum_t key; };
const namedKey_t NAMED_KEYS[] = {
    {"ESCAPE", K_ESCAPE}, {"TAB", K_TAB}, {"ENTER", K_ENTER},
    {"SPACE", K_SPACE}, {"BACKSPACE", K_BACKSPACE}, {"UPARROW", K_UPARROW},
    {"DOWNARROW", K_DOWNARROW}, {"LEFTARROW", K_LEFTARROW},
    {"RIGHTARROW", K_RIGHTARROW}, {"MOUSE1", K_MOUSE1}, {"MOUSE2", K_MOUSE2},
    {"MOUSE3", K_MOUSE3}, {"MWHEELUP", K_MWHEELUP},
    {"MWHEELDOWN", K_MWHEELDOWN}, {"JOY1", K_JOY1}, {"JOY2", K_JOY2},
    {"JOY3", K_JOY3}, {"JOY4", K_JOY4}, {"F1", K_F1}, {"F2", K_F2},
    {"F3", K_F3}, {"F4", K_F4}, {"F5", K_F5}, {"F6", K_F6},
    {"F7", K_F7}, {"F8", K_F8}, {"F9", K_F9}, {"F10", K_F10},
    {"F11", K_F11}, {"F12", K_F12}
};

inputType_t TypeForKey(const keyNum_t key) {
    if (key >= K_MOUSE1) return INPUT_TYPE_MOUSE;
    if (key >= K_JOY1) return INPUT_TYPE_GAMEPAD;
    return INPUT_TYPE_KEYBOARD;
}

int CommandDevice() {
    const int overrideDevice = key_deviceBindOverride.GetInteger();
    return overrideDevice >= 0 ? overrideDevice : bindDevice;
}

bindSet_t CommandBindSet() {
    return static_cast<bindSet_t>((std::max)(0,
        (std::min)(BIND_MAX - 1, in_bindset.GetInteger())));
}
}

int Key_CovertHIDCode(const int hid) {
    // USB HID usage -> recovered DirectInput/keyNum scan code table.
    static const int hidToKey[107] = {
        0,0,0,0,30,48,46,32,18,33,34,35,23,36,37,38,50,49,24,25,
        16,19,31,20,22,47,17,45,21,44,2,3,4,5,6,7,8,9,10,11,
        28,1,14,15,57,12,13,26,27,43,0,39,40,41,51,52,53,58,59,60,
        61,62,63,64,65,66,67,68,87,88,183,70,69,210,199,201,211,
        207,209,205,203,208,200,197,181,55,74,78,156,79,80,81,75,
        76,77,71,72,73,82,83,0,221,222,141,100,101,102
    };
    static const int modifiers[8] = {29, 42, 56, 219, 157, 54, 184, 220};
    if (hid >= 0
        && hid < static_cast<int>(sizeof(hidToKey) / sizeof(hidToKey[0]))) {
        return hidToKey[hid];
    }
    if (hid >= 224 && hid <= 231) return modifiers[hid - 224];
    return K_NONE;
}

keyNum_t idKeyInput::StringToKeyNum(const char* const string) {
    if (string == nullptr || *string == '\0') return K_NONE;
    if (string[1] == '\0') {
        const char upper = static_cast<char>(std::toupper(
            static_cast<unsigned char>(*string)));
        if (upper >= 'A' && upper <= 'Z') {
            static const keyNum_t letters[] = {K_A,K_B,K_C,K_D,K_E,K_F,K_G,K_H,
                K_I,K_J,K_K,K_L,K_M,K_N,K_O,K_P,K_Q,K_R,K_S,K_T,K_U,K_V,K_W,
                K_X,K_Y,K_Z};
            return letters[upper - 'A'];
        }
        if (upper >= '0' && upper <= '9') {
            static const keyNum_t digits[] = {K_0,K_1,K_2,K_3,K_4,K_5,K_6,K_7,K_8,K_9};
            return digits[upper - '0'];
        }
    }
    for (const namedKey_t& item : NAMED_KEYS) {
        if (idStr::Icmp(item.name, string) == 0) return item.key;
    }
    if (string[0] == 'K' && string[1] == '_') {
        const int value = std::atoi(string + 2);
        return value >= 0 && value < K_LAST_KEY ? static_cast<keyNum_t>(value)
                                                : K_NONE;
    }
    return K_NONE;
}

const char* idKeyInput::KeyNumToString(const keyNum_t key) {
    for (const namedKey_t& item : NAMED_KEYS) if (item.key == key) return item.name;
    for (char c = 'A'; c <= 'Z'; ++c) {
        char text[2] = {c, 0};
        if (StringToKeyNum(text) == key) { keyName[0] = c; keyName[1] = 0; return keyName; }
    }
    std::snprintf(keyName, sizeof(keyName), "K_%d", static_cast<int>(key));
    return keyName;
}

const char* idKeyInput::LocalizedKeyName(keyNum_t key) { return KeyNumToString(key); }
bool idKeyInput::IsValidRebindKey(keyNum_t key) { return key > K_NONE && key < K_LAST_KEY && key != K_ESCAPE; }

int idKeyInput::GetUsercmdAction(int deviceNum, bindSet_t set, keyNum_t key) {
    const char* binding = GetBinding(deviceNum, set, key);
    return binding != nullptr && *binding != '\0' && usercmdGen != nullptr
        ? static_cast<int>(usercmdGen->BindStringUsercmdAction(binding))
        : static_cast<int>(UB_NONE);
}

void idKeyInput::SetUserDeviceNumForBind(int deviceNum) { bindDevice = deviceNum; }

void idKeyInput::PreliminaryKeyEvent(int deviceNum, keyNum_t key, bool down) {
    if (deviceNum >= 0 && deviceNum < 4
            && key > K_NONE && key < K_LAST_KEY) {
        deviceStates[deviceNum][key].down = down;
    }
}

bool idKeyInput::IsDown(int deviceNum, keyNum_t key) {
    return deviceNum >= 0 && deviceNum < 4 && key > K_NONE
        && key < K_LAST_KEY && deviceStates[deviceNum][key].down;
}

void idKeyInput::ClearStates() {
    for (auto& device : deviceStates) for (keyState_t& key : device.second) key.down = false;
}

void idKeyInput::SetBinding(int deviceNum, bindSet_t set, keyNum_t key,
        const char* binding) {
    if (key > K_NONE && key < K_LAST_KEY && set >= 0 && set < BIND_MAX)
        if (deviceNum >= 0 && deviceNum < 4)
            deviceStates[deviceNum][key].bindings[set] =
                binding != nullptr ? binding : "";
}

const char* idKeyInput::GetBinding(int deviceNum, bindSet_t set, keyNum_t key) {
    if (deviceNum < 0 || deviceNum >= 4 || key <= K_NONE
            || key >= K_LAST_KEY || set < 0 || set >= BIND_MAX) return "";
    return deviceStates[deviceNum][key].bindings[set].c_str();
}

bool idKeyInput::UnbindBinding(int deviceNum, bindSet_t set, const char* binding) {
    bool removed = false;
    for (keyState_t& key : deviceStates[deviceNum]) {
        if (idStr::Icmp(key.bindings[set].c_str(), binding) == 0) {
            key.bindings[set].clear(); removed = true;
        }
    }
    return removed;
}

void idKeyInput::UnbindBinding(int deviceNum, bindSet_t set,
        const char* binding, inputType_t type) {
    for (int index = 0; index < K_LAST_KEY; ++index) {
        if (TypeForKey(static_cast<keyNum_t>(index)) == type
                && idStr::Icmp(deviceStates[deviceNum][index].bindings[set].c_str(), binding) == 0)
            deviceStates[deviceNum][index].bindings[set].clear();
    }
}

bool idKeyInput::ExecKeyBinding(int deviceNum, bindSet_t set, keyNum_t key) {
    const char* const binding = GetBinding(deviceNum, set, key);
    if (binding[0] == '\0' || GetUsercmdAction(deviceNum, set, key) != UB_NONE) {
        return false;
    }
    return tech5Framework::ExecuteCommand(binding);
}

idStr idKeyInput::GetUsercmdActionStr(int action) {
    return idStr(UsercmdActionString(action));
}

idStr idKeyInput::KeysFromBinding(int deviceNum, bindSet_t set,
        const char* binding, const bool firstOnly) {
    idStr result;
    for (int index = 0; index < K_LAST_KEY; ++index) {
        if (idStr::Icmp(deviceStates[deviceNum][index].bindings[set].c_str(), binding) == 0) {
            if (result.Length() != 0) result.Append(" or ");
            const keyNum_t key = static_cast<keyNum_t>(index);
            if (TypeForKey(key) != INPUT_TYPE_KEYBOARD) result.Append("<");
            result.Append(LocalizedKeyName(key));
            if (TypeForKey(key) != INPUT_TYPE_KEYBOARD) result.Append(">");
            if (firstOnly) break;
        }
    }
    return result;
}

void RegisterKeyInputCommands() {
    tech5Framework::RegisterCommand("unbindAll",
        [](const std::vector<idStr>&) {
            const int device = CommandDevice();
            const bindSet_t set = CommandBindSet();
            for (int key = K_NONE; key < K_LAST_KEY; ++key) {
                idKeyInput::SetBinding(device, set,
                    static_cast<keyNum_t>(key), "");
            }
        });
    tech5Framework::RegisterCommand("bind",
        [](const std::vector<idStr>& args) {
            if (args.size() < 2) {
                idLibPrint::Printf(
                    "bind <key> [command] : attach a command to a key\n");
                return;
            }
            const keyNum_t key = idKeyInput::StringToKeyNum(args[1].c_str());
            if (key == K_NONE) {
                idLibPrint::Printf("\"%s\" isn't a valid key\n",
                    args[1].c_str());
                return;
            }
            const int device = CommandDevice();
            const bindSet_t set = CommandBindSet();
            if (args.size() == 2) {
                const char* const binding = idKeyInput::GetBinding(
                    device, set, key);
                idLibPrint::Printf(binding[0] != '\0'
                    ? "\"%s\" = \"%s\"\n" : "\"%s\" is not bound\n",
                    args[1].c_str(), binding);
                return;
            }
            idStr binding;
            for (std::size_t index = 2; index < args.size(); ++index) {
                if (index != 2) binding.Append(' ');
                binding.Append(args[index]);
            }
            idKeyInput::SetBinding(device, set, key, binding.c_str());
        });
    tech5Framework::RegisterCommand("unbind",
        [](const std::vector<idStr>& args) {
            if (args.size() != 2) {
                idLibPrint::Printf(
                    "unbind <key> : remove commands from a key\n");
                return;
            }
            const int device = CommandDevice();
            const bindSet_t set = CommandBindSet();
            const keyNum_t key = idKeyInput::StringToKeyNum(args[1].c_str());
            if (key != K_NONE) {
                idKeyInput::SetBinding(device, set, key, "");
            } else if (!idKeyInput::UnbindBinding(device, set,
                    args[1].c_str())) {
                idLibPrint::Printf("\"%s\" isn't a valid key\n",
                    args[1].c_str());
            }
        });
    tech5Framework::RegisterCommand("listBinds",
        [](const std::vector<idStr>&) {
            const int device = CommandDevice();
            for (int setIndex = 0; setIndex < BIND_MAX; ++setIndex) {
                idLibPrint::Printf("Bindset %d\n", setIndex);
                for (int keyIndex = K_NONE; keyIndex < K_LAST_KEY;
                        ++keyIndex) {
                    const char* const binding = idKeyInput::GetBinding(device,
                        static_cast<bindSet_t>(setIndex),
                        static_cast<keyNum_t>(keyIndex));
                    if (*binding != '\0') {
                        idLibPrint::Printf("%s \"%s\"\n",
                            idKeyInput::KeyNumToString(
                                static_cast<keyNum_t>(keyIndex)), binding);
                    }
                }
            }
        });
}

keyBindings_t idKeyInput::KeyBindingsFromBinding(const int deviceNum,
        const bindSet_t set, const char* const binding) {
    keyBindings_t result;
    if (binding == nullptr || *binding == '\0') return result;
    for (int index = K_NONE; index < K_LAST_KEY; ++index) {
        const keyNum_t key = static_cast<keyNum_t>(index);
        if (idStr::Icmp(GetBinding(deviceNum, set, key), binding) != 0) {
            continue;
        }
        idStr* destination = &result.keyboard;
        const inputType_t type = TypeForKey(key);
        if (type == INPUT_TYPE_MOUSE) destination = &result.mouse;
        else if (type == INPUT_TYPE_GAMEPAD) destination = &result.gamepad;
        const char* const keyText = LocalizedKeyName(key);
        if (keyText == nullptr || *keyText == '\0') continue;
        if (destination->Length() != 0) destination->Append(", ");
        destination->Append(keyText);
    }
    return result;
}
