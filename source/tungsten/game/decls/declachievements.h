#pragma once

#include "../../../engine/decls/decltypeinfo.h"
#include "../../../shared/idlib/langdict.h"
#include "../ragestats.h"
#include "../player/achievementids.h"
#include "decljobref.h"

#include <cstdint>

enum triggerAchievementId_t : int;
enum raceMemoryPlace_t : int;
enum avatarAward_t : int;

class idDeclAchievement : public idDeclTypeInfo {
public:
    struct flags_t {
        std::uint8_t reserved : 3;
        std::uint8_t sys_mac : 1;
        std::uint8_t sys_ps3 : 1;
        std::uint8_t sys_xbox : 1;
        std::uint8_t sys_pc : 1;
        std::uint8_t internalUse : 1;
    };

    struct inventoryAchievement_t {
        idStr itemDecl;
        int count;
    };

    struct raceAchievement_t {
        idStr raceName;
        raceMemoryPlace_t place;
    };

    struct statConstraint_t {
        rageStat_t stat;
        int count;
    };

    idDeclAchievement();
    ~idDeclAchievement() override = default;

    // Retail symbol: ?GetDeclInfo@idDeclAchievement@@UBAPAVidDeclInfo@@XZ
    // EA: 0x82BBB488, RVA: 0x00BBB488
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    static void LoadAllDecls();

    idStrId achievementName;
    idStrId description;
    achievementId_t id;
    flags_t flags;
    idList<inventoryAchievement_t, 5> item;
    idList<idDeclJobRef, 5> jobDecl;
    idList<triggerAchievementId_t, 5> trigger;
    idList<raceAchievement_t, 5> races;
    bool allRacesRequired;
    idList<statConstraint_t, 5> events;
    bool allEventsRequired;
    idList<achievementId_t, 5> achievements;
    avatarAward_t avatarAwardId;

    static idDeclInfoTemplate<idDeclAchievement> resourceList;
};

static_assert(sizeof(idDeclAchievement::flags_t) == 1,
    "Recovered achievement flags layout changed");
static_assert(sizeof(idDeclAchievement::inventoryAchievement_t) == 36,
    "Recovered inventory-achievement row layout changed");
static_assert(sizeof(idDeclAchievement::raceAchievement_t) == 36,
    "Recovered race-achievement row layout changed");
static_assert(sizeof(idDeclAchievement::statConstraint_t) == 8,
    "Recovered stat-constraint row layout changed");

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclAchievement) == 188,
    "Recovered achievement declaration ABI changed");
#endif
