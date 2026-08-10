#pragma once

#include "../../../engine/decls/decltypeinfo.h"

class idDeclOnlinePerk : public idDeclTypeInfo {
public:
    idDeclOnlinePerk();

    // Retail symbol: ?GetDeclInfo@idDeclOnlinePerk@@UBAPAVidDeclInfo@@XZ
    // EA: 0x82BCA798, RVA: 0x00BCA798
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    static void LoadAllDecls();

    float boostUpModifier;
    float duraBumpModifier;
    float jumpManModifier;
    float overAmmoModifier;
    float lockJackModifier;
    float fasterFasterModifier;
    float theSnapperModifier;
    int overLoadModifier;

    static idDeclInfoTemplate<idDeclOnlinePerk> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclOnlinePerk) == 96,
    "Recovered idDeclOnlinePerk layout changed");
#endif
