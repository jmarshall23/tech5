#pragma once

#include "../../../engine/decls/decltypeinfo.h"
#include "../ragestats.h"

class idMaterial;

class idDeclAccolade : public idDeclTypeInfo {
public:
    idDeclAccolade();
    ~idDeclAccolade() override = default;

    // Retail symbol: ?GetDeclInfo@idDeclAccolade@@UBAPAVidDeclInfo@@XZ
    // EA: 0x82BBAE38, RVA: 0x00BBAE38
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    const char* GetIconName() const;
    static void LoadAllDecls();

    int ordinal;
    const idMaterial* icon;
    rageStat_t stat;
    idStr accoladeName;
    idStr description;
    mutable int index;

    static idDeclInfoTemplate<idDeclAccolade> resourceList;
    static idList<const idDeclAccolade*, 5> orderedList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclAccolade) == 144,
    "Recovered accolade declaration ABI changed");
#endif
