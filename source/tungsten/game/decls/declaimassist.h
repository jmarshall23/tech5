#pragma once

#include "../../../engine/decls/decltypeinfo.h"
#include "../player/aimassistdata.h"

class idDeclAimAssist : public idDeclTypeInfo {
public:
    idDeclAimAssist() = default;
    ~idDeclAimAssist() override = default;

    // Retail symbol: ?GetDeclInfo@idDeclAimAssist@@UBAPAVidDeclInfo@@XZ
    // EA: 0x82BCC868, RVA: 0x00BCC868
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    aimAssistData_t baseData;

    static idDeclInfoTemplate<idDeclAimAssist> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclAimAssist) == 180,
    "Recovered aim-assist declaration ABI changed");
#endif
