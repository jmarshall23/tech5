#pragma once

#include "../../../engine/decls/decltypeinfo.h"

class alignas(4) idDeclGoreBehavior : public idDeclTypeInfo {
public:
    struct fullBodyExplosion_t {
        float chanceOfLimbloss;
        float chanceOfWound;
        float chanceOfHeadshot;
        int maxPieces;
        int maxWounds;
    };

    idDeclGoreBehavior();

    // Retail symbol: ?GetDeclInfo@idDeclGoreBehavior@@UBAPAVidDeclInfo@@XZ
    // EA: 0x82BBE790, RVA: 0x00BBE790
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    fullBodyExplosion_t bodyExplosion;
    bool enableLimbloss;
    bool enableHeadShots;
    bool enableBodyWound;
    bool enableFullBodyExplosion;
    bool enableGoreWhenAlive;

    static idDeclInfoTemplate<idDeclGoreBehavior> resourceList;
};

static_assert(sizeof(idDeclGoreBehavior::fullBodyExplosion_t) == 20,
    "Recovered gore explosion settings layout changed");

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclGoreBehavior) == 92,
    "Recovered idDeclGoreBehavior layout changed");
#endif
