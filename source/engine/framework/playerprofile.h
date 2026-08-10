#pragma once

#include "idlib/containers/staticlist.h"

#include <cstdint>

class idSerializer;

#ifndef PROFILE_STAT_VALUE_T_DEFINED
#define PROFILE_STAT_VALUE_T_DEFINED
union profileStatValue_t {
    int i;
    float f;
};
#endif

class idPlayerProfile {
public:
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
    virtual float GetMouseSensitivity();
    virtual int GetLevel();
    virtual int GetChosenEmblem();
    virtual void SetInvertLook(bool invert);
    virtual unsigned int GetSubtitleLanguageMask();

    void SetAchievement(int achievement);
    bool GetAchievement(int achievement) const;
    void StatSetInt(int stat, int value);
    void StatSetFloat(int stat, float value);
    int StatGetInt(int stat) const;
    float StatGetFloat(int stat) const;
    void SaveSettings();
    void LoadSettings();

    alignas(8) state_t state;
    state_t requestedState;
    int deviceNum;
    bool hasUser;
    std::uint64_t achievementBits;
    std::uint64_t achievementBits2;
    int dlcReleaseVersion;
    idStaticList<profileStatValue_t, 500> stats;
};

void RegisterPlayerProfileCommands();
