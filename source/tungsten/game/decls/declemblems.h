#pragma once

#include "declachievements.h"

class idMaterial;

class idDeclEmblem : public idDeclTypeInfo {
public:
    enum emblemCategory_t : int {
        EMBLEM_COOP = 0,
        EMBLEM_VDM = 1
    };

    idDeclEmblem();
    ~idDeclEmblem() override;

    // Retail symbol: ?GetDeclInfo@idDeclEmblem@@UBAPAVidDeclInfo@@XZ
    // EA: 0x82BBDC48, RVA: 0x00BBDC48
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    int ordinal;
    const idMaterial* icon;
    idList<idDeclAchievement::statConstraint_t, 5> requirements;
    bool allEventsRequired;
    emblemCategory_t category;
    idStrId unlockDescription;
    int index;

    static idDeclInfoTemplate<idDeclEmblem> resourceList;
    static idList<const idDeclEmblem*, 5> orderedList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclEmblem) == 104,
    "Recovered emblem declaration ABI changed");
#endif
