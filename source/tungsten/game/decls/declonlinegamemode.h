#pragma once

#include "decls/decltypeinfo.h"
#include "game/online_types.h"
#include "idlib/containers/list.h"
#include "idlib/containers/staticlist.h"
#include "idlib/langdict.h"
#include "idlib/text/str.h"

class idMaterial;
enum rageStat_t : int;

struct idOnlineScoreboardInfo {
    idStrId title;
    rageStat_t stat;
};

class idDeclGameMode;

struct idOnlineMode {
    const idDeclGameMode* mode;
    idStr mapLayers;
};

struct idOnlineChallenge {
    idStr GetMapLayers() const;

    idStrId displayName;
    idStrId description;
    idStr mapLayers;
    int cashRequired;
    rageStat_t nightmareCompletionStat;
    rageStat_t completionStat;
    rageStat_t collectionStat;
    rageStat_t specialCollectionStat;
    int leaderboard;
    rageStat_t unlockStatRequired;
    idStrId unlockDescription;
    rageStat_t completionUnlock;
};

class idDeclGameMode : public idDeclTypeInfo {
public:
    idDeclGameMode();
    ~idDeclGameMode() override;

    idDeclInfo* GetDeclInfo() const override { return &resourceList; }
    static void LoadAllDecls();

    idStaticList<rageStat_t, 8> migrationStats;
    challengeGameMode_t challengeMode;
    idStrId displayName;
    idStrId description;
    idStr titleStorageModeName;
    idOnlineScoreboardInfo primaryScoreboardInfo;
    idOnlineScoreboardInfo secondaryScoreboardInfo;
    rageStat_t secondaryLeaderboardStat;
    idMaterial* menuMaterial;
    int levelRequired;
    bool isTeamGame;
    int menuIndex;
    gameType_t gameType;

    static idDeclInfoTemplate<idDeclGameMode> resourceList;
    static idList<const idDeclGameMode*, 5> challengeModeLookup;
};

class idDeclPvPMap : public idDeclTypeInfo {
public:
    idDeclPvPMap();
    ~idDeclPvPMap() override;

    idDeclInfo* GetDeclInfo() const override { return &resourceList; }
    static void LoadAllDecls();

    idStrId displayName;
    idStrId description;
    idStr mapFile;
    idStr titleStorageMapName;
    int levelRequired;
    const idMaterial* material;
    idList<idOnlineMode, 5> modes;
    int menuIndex;
    gameType_t gameType;

    static idDeclInfoTemplate<idDeclPvPMap> resourceList;
};

class idDeclCoopMap : public idDeclTypeInfo {
public:
    idDeclCoopMap();
    ~idDeclCoopMap() override;

    idDeclInfo* GetDeclInfo() const override { return &resourceList; }
    static void LoadAllDecls();

    idStrId displayName;
    idStrId description;
    idStrId introQuote;
    idStr map;
    int cashRequired;
    const idMaterial* material;
    idList<idOnlineChallenge, 5> challenges;
    rageStat_t specialCollectionStat;
    int menuIndex;
    int loadScreenAlternate;
    gameType_t gameType;

    static idDeclInfoTemplate<idDeclCoopMap> resourceList;
};

static_assert(sizeof(idOnlineScoreboardInfo) == 8,
    "Recovered online-scoreboard-info ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idOnlineMode) == 36,
    "Recovered online-mode ABI changed");
static_assert(sizeof(idOnlineChallenge) == 76,
    "Recovered online-challenge ABI changed");
static_assert(sizeof(idDeclGameMode) == 196,
    "Recovered game-mode declaration ABI changed");
static_assert(sizeof(idDeclPvPMap) == 168,
    "Recovered PvP-map declaration ABI changed");
static_assert(sizeof(idDeclCoopMap) == 148,
    "Recovered co-op-map declaration ABI changed");
#endif
