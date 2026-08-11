#include "game/decls/declonlinegamemode.h"

#include "idlib/lib_print.h"

idDeclInfoTemplate<idDeclPvPMap> idDeclPvPMap::resourceList(
    "pvpMap", "idDeclPvPMap", "tdef");
idDeclInfoTemplate<idDeclGameMode> idDeclGameMode::resourceList(
    "gameMode", "idDeclGameMode", "tdef");
idDeclInfoTemplate<idDeclCoopMap> idDeclCoopMap::resourceList(
    "coopMap", "idDeclCoopMap", "tdef");
idList<const idDeclGameMode*, 5> idDeclGameMode::challengeModeLookup;

namespace {
void LoadAllSources(idDeclInfo& resourceList) {
    for (int sourceIndex = 0;
            sourceIndex < resourceList.declSources.Num(); ++sourceIndex) {
        const idDeclSource* source = resourceList.declSources[sourceIndex];
        if (source != nullptr && source->name.c_str() != nullptr) {
            resourceList.FindWithInheritance(source->name.c_str(), false);
        }
    }
}
}

// EA 0x82BC9950
void idDeclPvPMap::LoadAllDecls() {
    LoadAllSources(resourceList);
}

// EA 0x82BC99B0
void idDeclCoopMap::LoadAllDecls() {
    LoadAllSources(resourceList);
}

// EA 0x82BC9A10
idDeclGameMode::idDeclGameMode()
    : migrationStats()
    , challengeMode(CHALLENGE_MODE_NORMAL)
    , displayName()
    , description()
    , titleStorageModeName()
    , primaryScoreboardInfo{idStrId(), static_cast<rageStat_t>(-1)}
    , secondaryScoreboardInfo{idStrId(), static_cast<rageStat_t>(-1)}
    , secondaryLeaderboardStat(static_cast<rageStat_t>(-1))
    , menuMaterial(nullptr)
    , levelRequired(0)
    , isTeamGame(false)
    , menuIndex(0)
    , gameType(GAME_TYPE_PVP) {
}

// EA 0x82BC9AF0
idDeclGameMode::~idDeclGameMode() = default;

// EA 0x82BC9C08
idDeclPvPMap::idDeclPvPMap()
    : displayName()
    , description()
    , mapFile()
    , titleStorageMapName()
    , levelRequired(0)
    , material(nullptr)
    , modes()
    , menuIndex(0)
    , gameType(GAME_TYPE_PVP) {
}

// EA 0x82BCA070
idDeclPvPMap::~idDeclPvPMap() = default;

// EA 0x82BC9D68
void idDeclGameMode::LoadAllDecls() {
    LoadAllSources(resourceList);

    challengeModeLookup.SetNum(CHALLENGE_MODE_MAX);
    for (int index = 0; index < challengeModeLookup.Num(); ++index) {
        challengeModeLookup[index] = nullptr;
    }

    for (int modeIndex = 0; modeIndex < resourceList.num; ++modeIndex) {
        const idDeclGameMode* mode = static_cast<const idDeclGameMode*>(
            resourceList.Index(modeIndex));
        if (mode == nullptr) {
            continue;
        }

        const int lookupIndex = static_cast<int>(mode->challengeMode);
        if (lookupIndex < 0 || lookupIndex >= challengeModeLookup.Num()) {
            continue;
        }
        if (challengeModeLookup[lookupIndex] != nullptr) {
            idLibPrint::Warning(
                "idDeclGameMode [ %s ] failed to load. Challenge mode %d "
                "already exists. Last seen in %s.",
                mode->GetName(), lookupIndex,
                challengeModeLookup[lookupIndex]->GetName());
        } else {
            challengeModeLookup[lookupIndex] = mode;
        }
    }
}

// EA 0x82BC9F30
idDeclCoopMap::idDeclCoopMap()
    : displayName()
    , description()
    , introQuote()
    , map()
    , cashRequired(0)
    , material(nullptr)
    , challenges()
    , specialCollectionStat(static_cast<rageStat_t>(-1))
    , menuIndex(0)
    , loadScreenAlternate(0)
    , gameType(GAME_TYPE_COOP) {
}

// EA 0x82BCA1D8
idDeclCoopMap::~idDeclCoopMap() = default;

// EA 0x82DBF048
idStr idOnlineChallenge::GetMapLayers() const {
    return mapLayers;
}
