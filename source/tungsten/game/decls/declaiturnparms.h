#pragma once

#include "../../../engine/decls/decltypeinfo.h"

class alignas(4) idDeclAITurnParms : public idDeclTypeInfo {
public:
    // Retail symbol: ??0idDeclAITurnParms@@QAA@XZ
    // EA: 0x82BD23F8, RVA: 0x00BD23F8
    idDeclAITurnParms()
        : baseTurnName("turn")
        , turnDelay(1000)
        , extraAngleScale(0.0f)
        , maxAngle(-1.0f)
        , allowTurns(true)
        , allowCrouchedTurns(true)
        , allowSittingTurns(false)
        , predictTurns(true)
        , turnToFocus(true) {
    }

    ~idDeclAITurnParms() override = default;

    // Retail symbol: ?GetDeclInfo@idDeclAITurnParms@@UBAPAVidDeclInfo@@XZ
    // EA: 0x82BD24B8, RVA: 0x00BD24B8
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    idStr baseTurnName;
    int turnDelay;
    float extraAngleScale;
    float maxAngle;
    bool allowTurns;
    bool allowCrouchedTurns;
    bool allowSittingTurns;
    bool predictTurns;
    bool turnToFocus;

    static idDeclInfoTemplate<idDeclAITurnParms> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclAITurnParms) == 116,
    "Recovered AI turn-parameter declaration ABI changed");
#endif
