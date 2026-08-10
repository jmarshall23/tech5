#pragma once

#include "framework/usercmdgen.h"
#include "idlib/text/str.h"

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\keyinput.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1113; PDB kind: enum.
enum keyNum_t : __int32
{
  K_NONE = 0x0,
  K_ESCAPE = 0x1,
  K_1 = 0x2,
  K_2 = 0x3,
  K_3 = 0x4,
  K_4 = 0x5,
  K_5 = 0x6,
  K_6 = 0x7,
  K_7 = 0x8,
  K_8 = 0x9,
  K_9 = 0xA,
  K_0 = 0xB,
  K_MINUS = 0xC,
  K_EQUALS = 0xD,
  K_BACKSPACE = 0xE,
  K_TAB = 0xF,
  K_Q = 0x10,
  K_W = 0x11,
  K_E = 0x12,
  K_R = 0x13,
  K_T = 0x14,
  K_Y = 0x15,
  K_U = 0x16,
  K_I = 0x17,
  K_O = 0x18,
  K_P = 0x19,
  K_LBRACKET = 0x1A,
  K_RBRACKET = 0x1B,
  K_ENTER = 0x1C,
  K_LCTRL = 0x1D,
  K_A = 0x1E,
  K_S = 0x1F,
  K_D = 0x20,
  K_F = 0x21,
  K_G = 0x22,
  K_H = 0x23,
  K_J = 0x24,
  K_K = 0x25,
  K_L = 0x26,
  K_SEMICOLON = 0x27,
  K_APOSTROPHE = 0x28,
  K_GRAVE = 0x29,
  K_LSHIFT = 0x2A,
  K_BACKSLASH = 0x2B,
  K_Z = 0x2C,
  K_X = 0x2D,
  K_C = 0x2E,
  K_V = 0x2F,
  K_B = 0x30,
  K_N = 0x31,
  K_M = 0x32,
  K_COMMA = 0x33,
  K_PERIOD = 0x34,
  K_SLASH = 0x35,
  K_RSHIFT = 0x36,
  K_KP_STAR = 0x37,
  K_LALT = 0x38,
  K_SPACE = 0x39,
  K_CAPSLOCK = 0x3A,
  K_F1 = 0x3B,
  K_F2 = 0x3C,
  K_F3 = 0x3D,
  K_F4 = 0x3E,
  K_F5 = 0x3F,
  K_F6 = 0x40,
  K_F7 = 0x41,
  K_F8 = 0x42,
  K_F9 = 0x43,
  K_F10 = 0x44,
  K_PAUSE = 0x45,
  K_SCROLL = 0x46,
  K_KP_7 = 0x47,
  K_KP_8 = 0x48,
  K_KP_9 = 0x49,
  K_KP_MINUS = 0x4A,
  K_KP_4 = 0x4B,
  K_KP_5 = 0x4C,
  K_KP_6 = 0x4D,
  K_KP_PLUS = 0x4E,
  K_KP_1 = 0x4F,
  K_KP_2 = 0x50,
  K_KP_3 = 0x51,
  K_KP_0 = 0x52,
  K_KP_DOT = 0x53,
  K_F11 = 0x57,
  K_F12 = 0x58,
  K_F13 = 0x64,
  K_F14 = 0x65,
  K_F15 = 0x66,
  K_KANA = 0x70,
  K_CONVERT = 0x79,
  K_NOCONVERT = 0x7B,
  K_YEN = 0x7D,
  K_KP_EQUALS = 0x8D,
  K_CIRCUMFLEX = 0x90,
  K_AT = 0x91,
  K_COLON = 0x92,
  K_UNDERLINE = 0x93,
  K_KANJI = 0x94,
  K_STOP = 0x95,
  K_AX = 0x96,
  K_UNLABELED = 0x97,
  K_KP_ENTER = 0x9C,
  K_RCTRL = 0x9D,
  K_KP_COMMA = 0xB3,
  K_KP_SLASH = 0xB5,
  K_PRINTSCREEN = 0xB7,
  K_RALT = 0xB8,
  K_NUMLOCK = 0xC5,
  K_HOME = 0xC7,
  K_UPARROW = 0xC8,
  K_PGUP = 0xC9,
  K_LEFTARROW = 0xCB,
  K_RIGHTARROW = 0xCD,
  K_END = 0xCF,
  K_DOWNARROW = 0xD0,
  K_PGDN = 0xD1,
  K_INS = 0xD2,
  K_DEL = 0xD3,
  K_LWIN = 0xDB,
  K_RWIN = 0xDC,
  K_APPS = 0xDD,
  K_POWER = 0xDE,
  K_SLEEP = 0xDF,
  K_JOY1 = 0x100,
  K_JOY2 = 0x101,
  K_JOY3 = 0x102,
  K_JOY4 = 0x103,
  K_JOY5 = 0x104,
  K_JOY6 = 0x105,
  K_JOY7 = 0x106,
  K_JOY8 = 0x107,
  K_JOY9 = 0x108,
  K_JOY10 = 0x109,
  K_JOY11 = 0x10A,
  K_JOY12 = 0x10B,
  K_JOY13 = 0x10C,
  K_JOY14 = 0x10D,
  K_JOY15 = 0x10E,
  K_JOY16 = 0x10F,
  K_JOY_STICK1_UP = 0x110,
  K_JOY_STICK1_DOWN = 0x111,
  K_JOY_STICK1_LEFT = 0x112,
  K_JOY_STICK1_RIGHT = 0x113,
  K_JOY_STICK2_UP = 0x114,
  K_JOY_STICK2_DOWN = 0x115,
  K_JOY_STICK2_LEFT = 0x116,
  K_JOY_STICK2_RIGHT = 0x117,
  K_JOY_TRIGGER1 = 0x118,
  K_JOY_TRIGGER2 = 0x119,
  K_JOY_DPAD_UP = 0x11A,
  K_JOY_DPAD_DOWN = 0x11B,
  K_JOY_DPAD_LEFT = 0x11C,
  K_JOY_DPAD_RIGHT = 0x11D,
  K_MOUSE1 = 0x11E,
  K_MOUSE2 = 0x11F,
  K_MOUSE3 = 0x120,
  K_MOUSE4 = 0x121,
  K_MOUSE5 = 0x122,
  K_MOUSE6 = 0x123,
  K_MOUSE7 = 0x124,
  K_MOUSE8 = 0x125,
  K_MWHEELDOWN = 0x126,
  K_MWHEELUP = 0x127,
  K_LAST_KEY = 0x128,
};

// IDA Local Type ordinal 21521; PDB kind: class.
enum bindSet_t : int {
  BIND_DEFAULT = 0,
  BIND_SINGLEPLAYER_FIRST_PERSON = 0,
  BIND_MULTIPLAYER_FIRST_PERSON = 1,
  BIND_DRIVE = 2,
  BIND_POSSESS = 3,
  BIND_REMOTE = 4,
  BIND_VEHICLE_GUNNER = 5,
  BIND_VEHICLE_PASSENGER = 6,
  BIND_MAX = 7
};

enum inputType_t : int {
  INPUT_TYPE_KEYBOARD = 0,
  INPUT_TYPE_MOUSE = 1,
  INPUT_TYPE_GAMEPAD = 2
};

struct keyBindings_t {
  idStr keyboard;
  idStr mouse;
  idStr gamepad;
};

class idKeyAction {
public:
  idKeyAction() : usercmdAction(UB_NONE) {}
  cmdGenButton_t usercmdAction;
  idStr binding;
};

int Key_CovertHIDCode(int hid);

class idKeyInput {
public:
  static keyNum_t StringToKeyNum(const char* string);
  static const char* KeyNumToString(keyNum_t key);
  static const char* LocalizedKeyName(keyNum_t key);
  static bool IsValidRebindKey(keyNum_t key);
  static int GetUsercmdAction(int deviceNum, bindSet_t bindSet, keyNum_t key);
  static void SetUserDeviceNumForBind(int deviceNum);
  static void PreliminaryKeyEvent(int deviceNum, keyNum_t key, bool down);
  static bool IsDown(int deviceNum, keyNum_t key);
  static void ClearStates();
  static void SetBinding(int deviceNum, bindSet_t bindSet, keyNum_t key,
      const char* binding);
  static const char* GetBinding(int deviceNum, bindSet_t bindSet, keyNum_t key);
  static bool UnbindBinding(int deviceNum, bindSet_t bindSet,
      const char* binding);
  static void UnbindBinding(int deviceNum, bindSet_t bindSet,
      const char* binding, inputType_t inputType);
  static bool ExecKeyBinding(int deviceNum, bindSet_t bindSet, keyNum_t key);
  static idStr GetUsercmdActionStr(int action);
  static idStr KeysFromBinding(int deviceNum, bindSet_t bindSet,
      const char* binding, bool localized);
  static keyBindings_t KeyBindingsFromBinding(int deviceNum,
      bindSet_t bindSet, const char* binding);
};

void RegisterKeyInputCommands();
