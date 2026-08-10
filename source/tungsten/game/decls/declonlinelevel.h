#pragma once

#include "../../../engine/decls/decltypeinfo.h"
#include "idlib/containers/list.h"

struct onlineLevel_t {
    int baseXp;
    float localXpScale;
    int loadouts;
};

class idDeclOnlineLevel : public idDeclTypeInfo {
public:
    idDeclOnlineLevel();
    ~idDeclOnlineLevel() override = default;

    int GetNumLoadouts(int level) const;
    int GetXpRequiredForLevel(int level) const;
    int GetLevelForXp(int xp) const;

    idDeclInfo* GetDeclInfo() const override { return &resourceList; }
    static void LoadAllDecls();

    idList<onlineLevel_t, 5> levelList;
    float globalXpScale;
    int xpCap;

    static idDeclInfoTemplate<idDeclOnlineLevel> resourceList;
};

static_assert(sizeof(onlineLevel_t) == 12,
    "Recovered online-level entry ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclOnlineLevel) == 88,
    "Recovered online-level declaration ABI changed");
#endif
