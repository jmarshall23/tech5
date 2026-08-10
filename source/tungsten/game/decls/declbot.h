#pragma once

#include "../../../engine/decls/decltypeinfo.h"
#include "../../../shared/idlib/text/str.h"

class idDeclBot : public idDeclTypeInfo {
public:
    idDeclBot();
    ~idDeclBot() override;

    // Retail symbol: ?GetDeclInfo@idDeclBot@@UBAPAVidDeclInfo@@XZ
    // EA: 0x82BBC9D0, RVA: 0x00BBC9D0
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    static void LoadAllDecls();

    idStr botName;

    static idDeclInfoTemplate<idDeclBot> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclBot) == 96, "Recovered idDeclBot layout changed");
#endif
