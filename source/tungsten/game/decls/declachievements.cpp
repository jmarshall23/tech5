#include "game/decls/declachievements.h"

#include <cstdio>

idDeclInfoTemplate<idDeclAchievement> idDeclAchievement::resourceList(
    "achievement", "idDeclAchievement", "decl");

// EA 0x82BBB188
void idDeclAchievement::LoadAllDecls() {
    char name[32];
    for (int index = 1; index <= 50; ++index) {
        std::snprintf(name, sizeof(name), "achievement_%02d", index);
        resourceList.Load(name, false, false);
    }
}

// EA 0x82BBB240
idDeclAchievement::idDeclAchievement()
    : achievementName()
    , description()
    , id(GAME_ACHIEVEMENT_NONE)
    , flags()
    , item()
    , jobDecl()
    , trigger()
    , races()
    , allRacesRequired(true)
    , events()
    , allEventsRequired(true)
    , achievements()
    , avatarAwardId(static_cast<avatarAward_t>(0)) {
    flags.reserved = 0;
    flags.sys_mac = 1;
    flags.sys_ps3 = 1;
    flags.sys_xbox = 1;
    flags.sys_pc = 1;
    flags.internalUse = 0;
}

