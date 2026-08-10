#include "framework/playerprofile.h"

#include "framework/common.h"
#include "framework/framework_runtime_internal.h"
#include "idlib/lib_print.h"

idPlayerProfile::idPlayerProfile()
    : state(IDLE), requestedState(IDLE), deviceNum(-1), hasUser(false),
      achievementBits(0), achievementBits2(0), dlcReleaseVersion(0) {
    SetDefaults();
}

idPlayerProfile::~idPlayerProfile() = default;

void idPlayerProfile::SetDefaults() {
    hasUser = true;
    achievementBits = 0;
    achievementBits2 = 0;
    dlcReleaseVersion = 0;
    stats.SetNum(MAX_PLAYER_PROFILE_STATS);
    for (int index = 0; index < stats.Num(); ++index) {
        stats[index].i = 0;
    }
}

bool idPlayerProfile::Serialize(idSerializer*) { return false; }
bool idPlayerProfile::UpdateDisplayModeFromCvars() { return false; }
bool idPlayerProfile::CommitDisplayChanges() { return false; }
float idPlayerProfile::GetMouseSensitivity() const { return 1.0f; }
int idPlayerProfile::GetLevel() const { return 0; }
int idPlayerProfile::GetChosenEmblem() const { return 0; }
void idPlayerProfile::SetInvertLook(bool) {}
unsigned int idPlayerProfile::GetSubtitleLanguageMask() const { return 0xFFFFFFFFu; }

idPlayerProfile* idPlayerProfile::CreatePlayerProfile(const int deviceIndex) {
    idPlayerProfile* const profile = new idPlayerProfile();
    profile->deviceNum = deviceIndex;
    return profile;
}

void idPlayerProfile::SetAchievement(const int achievement) {
    if (achievement >= 0 && achievement < 64) {
        achievementBits |= std::uint64_t(1) << achievement;
    } else if (achievement >= 64 && achievement < 128) {
        achievementBits2 |= std::uint64_t(1) << (achievement - 64);
    }
}

bool idPlayerProfile::GetAchievement(const int achievement) const {
    if (achievement >= 0 && achievement < 64) {
        return (achievementBits & (std::uint64_t(1) << achievement)) != 0;
    }
    return achievement >= 64 && achievement < 128
        && (achievementBits2 & (std::uint64_t(1) << (achievement - 64))) != 0;
}

void idPlayerProfile::ClearAchievement(const int achievement) {
    if (achievement >= 0 && achievement < 64) {
        achievementBits &= ~(std::uint64_t(1) << achievement);
    } else if (achievement >= 64 && achievement < 128) {
        achievementBits2 &= ~(std::uint64_t(1) << (achievement - 64));
    }
}

void idPlayerProfile::StatSetInt(const int stat, const int value) {
    if (stat >= 0 && stat < stats.Num()) stats[stat].i = value;
}

void idPlayerProfile::StatSetFloat(const int stat, const float value) {
    if (stat >= 0 && stat < stats.Num()) stats[stat].f = value;
}

int idPlayerProfile::StatGetInt(const int stat) const {
    return stat >= 0 && stat < stats.Num() ? stats[stat].i : 0;
}

float idPlayerProfile::StatGetFloat(const int stat) const {
    return stat >= 0 && stat < stats.Num() ? stats[stat].f : 0.0f;
}

void idPlayerProfile::SaveSettings() {
    if (state != SAVING && requestedState == IDLE) {
        requestedState = SAVE_REQUESTED;
    }
}

void idPlayerProfile::LoadSettings() {
    if (hasUser && state != LOADING && requestedState == IDLE) {
        requestedState = LOAD_REQUESTED;
    }
}

void RegisterPlayerProfileCommands() {
    tech5Framework::RegisterCommand("setProfileDefaults",
        [](const std::vector<idStr>&) {
            idPlayerProfile* const profile = common != nullptr
                ? common->GetProfileFromMasterLocalUser() : nullptr;
            if (profile == nullptr) {
                idLibPrint::Warning(
                    "setProfileDefaults: no master local-user profile");
                return;
            }
            profile->SetDefaults();
            profile->SaveSettings();
        });
}
