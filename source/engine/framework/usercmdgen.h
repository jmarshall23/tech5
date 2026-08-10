#pragma once

#include "idlib/filesystem/file.h"
#include "idlib/math/angles.h"

#include <cstdint>
#include <cstring>

enum cmdGenButton_t : int {
    UB_ATTACK1 = 0x00, UB_ATTACK2 = 0x01, UB_USE = 0x02,
    UB_ZOOM = 0x03, UB_SPRINT = 0x04, UB_USE_AND_RELOAD = 0x05,
    UB_CHANGEWEAPON = 0x06, UB_WEAP_RELOAD = 0x07, UB_WEAP_NEXT = 0x08,
    UB_WEAP_PREV = 0x09, UB_WEAP_0 = 0x0A, UB_WEAP_1 = 0x0B,
    UB_WEAP_2 = 0x0C, UB_WEAP_3 = 0x0D, UB_WEAP_4 = 0x0E,
    UB_WEAP_5 = 0x0F, UB_WEAP_NEXT_IN_INV = 0x10,
    UB_WEAP_PREV_IN_INV = 0x11, UB_WEAP_PREV_EQUIPPED = 0x12,
    UB_NOTHING = 0x13, UB_TOGGLEDUALWIELD = 0x14, UB_QUICK_USE = 0x15,
    UB_QUICK_SELECT = 0x16, UB_COVERMODE = 0x17, UB_CYCLE_TARGET = 0x18,
    UB_SWITCH_POS = 0x19, UB_SCOREBOARD = 0x1A, UB_INVENTORY = 0x1B,
    UB_TOGGLEFIREMODE_LEFT = 0x1C, UB_TOGGLEFIREMODE_RIGHT = 0x1D,
    UB_NEXT_QUICK_ITEM = 0x20, UB_PREV_QUICK_ITEM = 0x21,
    UB_MOVEUP = 0x30, UB_MOVEDOWN = 0x31, UB_MOVELEFT = 0x32,
    UB_MOVERIGHT = 0x33, UB_MOVEFORWARD = 0x34, UB_MOVEBACK = 0x35,
    UB_LOOKUP = 0x36, UB_LOOKDOWN = 0x37, UB_LOOKLEFT = 0x38,
    UB_LOOKRIGHT = 0x39, UB_NONE = 0x3A, UB_MAX = 0x3B
};

struct inputSettings_t {
    int bindset = 0;
    bool lookInvert = false;
    bool absoluteAngles = false;
    float mouseSens = 1.0f;
    float mouseSensScale = 1.0f;
    float joySensScale = 1.0f;
    float joyPitchSpeed = 140.0f;
    float joyYawSpeed = 240.0f;
};

class alignas(4) usercmd_t {
public:
    void ClearMoveCmds() { forwardmove = rightmove = upmove = 0; }
    void Clear() { std::memset(this, 0, sizeof(*this)); }
    void Print() const;
    int buttons;
    std::int16_t buttons2;
    char forwardmove;
    char rightmove;
    char upmove;
    unsigned char reserved : 6;
    unsigned char fromBot : 1;
    unsigned char inhibited : 1;
    std::int16_t angles[3];
    int clientGameFrame;
    float pos[3];
    std::int16_t pitch, yaw, roll;
    unsigned char predictionStateBits;
    int serverGameTime;
    std::uint16_t fireCount;
    std::int16_t fireAngles[2];
    std::int16_t firePos[3];
    unsigned char vehicleThrottle;
    unsigned char speed;
};

class idUserCmdMgr {
public:
    usercmd_t cmdBuffer[128][6];
    int writeFrame[6];
    int readFrame[6];
};

class idUsercmdGen {
public:
    virtual ~idUsercmdGen() = default;
    virtual void Init() = 0;
    virtual void Shutdown() = 0;
    virtual void Clear() = 0;
    virtual void ClearAngles() = 0;
    virtual void SaveGame(idFile*) = 0;
    virtual bool LoadGame(idFile*) = 0;
    virtual cmdGenButton_t BindStringUsercmdAction(const char*) const = 0;
    virtual usercmd_t GetUsercmd(int, const inputSettings_t&, bool, int) = 0;
    virtual void GetRecordedUserCmd(int, usercmd_t&) = 0;
    virtual bool RecordPlay(int, bool, const char*) = 0;
    virtual bool GetUseAimAssist() const = 0;
};

class idUsercmdGenLocal : public idUsercmdGen {
public:
    idUsercmdGenLocal();
    ~idUsercmdGenLocal() override;
    void Init() override;
    void Shutdown() override;
    void Clear() override;
    void ClearAngles() override;
    void SaveGame(idFile*) override;
    bool LoadGame(idFile*) override;
    cmdGenButton_t BindStringUsercmdAction(const char*) const override;
    usercmd_t GetUsercmd(int, const inputSettings_t&, bool, int) override;
    void GetRecordedUserCmd(int, usercmd_t&) override;
    bool RecordPlay(int, bool, const char*) override;
    bool GetUseAimAssist() const override;

    struct usercmdDevice_t {
        int lastPollTime;
        idAngles angles;
        bool keyState[296];
        float joystickAxis[6];
    };

    void Key(int inputDeviceNum, int keyNum, bool down);
    void Mouse(int inputDeviceNum);
    void Keyboard(int inputDeviceNum);
    void Joystick(int inputDeviceNum);
    void KeyMove();
    void MouseMove();
    void CircleToSquare(float& x, float& y) const;
    void HandleJoystickAxis(int axis, int actionNegative,
        int actionPositive, float threshold, float value, bool digital);
    void JoystickMove(int elapsedMilliseconds);
    void AimAssist();
    void WeaponKick();

    int pollTime;
    usercmdDevice_t devices[4];
    bool buttonState[UB_MAX];
    int lastCommandTime;
    bool initialized;
    int currentDeviceNum;
    usercmdDevice_t* currentDevice;
    inputSettings_t currentSettings;
    usercmd_t cmd;
    float mouseDx;
    float mouseDy;
    int lastInputFrame;
    idFile* cmdFiles[6];
    bool recording[6];
    int loopPlayCmds[6];
    bool aimAssist;
    bool joystickSnapDisabled;
    float lastUsedLookValue[4];
    float lastUsedLookValuePitch[4];
    bool allowButtonInputDuringPlay;
};

extern idUsercmdGenLocal usercmdGenLocal;
extern idUsercmdGen* usercmdGen;

const char* UsercmdActionString(int action);
void RegisterUsercmdCommands();
