#pragma once

#include "idlib/containers/staticlist.h"

#include <cstdint>

class idSerializer;
class idLocalUser;
class idProfileMgr;

#ifndef PROFILE_STAT_VALUE_T_DEFINED
#define PROFILE_STAT_VALUE_T_DEFINED
union profileStatValue_t {
    int i;
    float f;
};
#endif

class idPlayerProfile {
    friend class idLocalUser;
    friend class idProfileMgr;
public:
    static const int MAX_PLAYER_PROFILE_STATS = 500;

    enum state_t : int {
        IDLE = 0,
        SAVING = 1,
        LOADING = 2,
        SAVE_REQUESTED = 3,
        LOAD_REQUESTED = 4,
        ERR = 5
    };

    idPlayerProfile();
    virtual ~idPlayerProfile();
    virtual void SetDefaults();
    virtual bool Serialize(idSerializer* serializer);
    virtual bool UpdateDisplayModeFromCvars();
    virtual bool CommitDisplayChanges();
    virtual float GetMouseSensitivity() const;
    virtual int GetLevel() const;
    virtual int GetChosenEmblem() const;
    virtual void SetInvertLook(bool invert);
    virtual unsigned int GetSubtitleLanguageMask() const;

    static idPlayerProfile* CreatePlayerProfile(int deviceIndex);
    bool Serialize(idSerializer& serializer) { return Serialize(&serializer); }
    int GetDeviceNumForProfile() const { return deviceNum; }
    void SetDeviceNumForProfile(int value) { deviceNum = value; }
    state_t GetState() const { return state; }
    state_t GetRequestedState() const { return requestedState; }
    bool IsDirty() const { return true; }

    void SetAchievement(int achievement);
    void ClearAchievement(int achievement);
    bool GetAchievement(int achievement) const;
    void StatSetInt(int stat, int value);
    void StatSetFloat(int stat, float value);
    int StatGetInt(int stat) const;
    float StatGetFloat(int stat) const;
    void SaveSettings();
    void SaveSettings(bool) { SaveSettings(); }
    void LoadSettings();
    int GetDlcReleaseVersion() const { return dlcReleaseVersion; }
    void SetDlcReleaseVersion(int value) { dlcReleaseVersion = value; }
    void MarkDirty(bool) {}

    alignas(8) state_t state;
    state_t requestedState;
    int deviceNum;
    bool hasUser;
    std::uint64_t achievementBits;
    std::uint64_t achievementBits2;
    int dlcReleaseVersion;
    idStaticList<profileStatValue_t, MAX_PLAYER_PROFILE_STATS> stats;

protected:
    void SetState(state_t value) { state = value; }
    void SetRequestedState(state_t value) { requestedState = value; }
};

void RegisterPlayerProfileCommands();
