#pragma once

#include "../../../engine/decls/decltypeinfo.h"
#include "../../../shared/idlib/math/degrees.h"

struct trackingParms_t {
    float kickScale;
    degrees_t rate;
    degrees_t acceleration;
    degrees_t deceleration;
    float springMass;
    float springTightness;
    float springDampen;
    float springMaxSpeed;
    float springRestLength;
    float springMaxLength;
};

class idDeclTrackingParms : public idDeclTypeInfo {
public:
    // Retail symbol: ??0idDeclTrackingParms@@QAA@XZ
    // EA: 0x82BD3048, RVA: 0x00BD3048
    idDeclTrackingParms() : parms(0) {}
    ~idDeclTrackingParms() override = default;

    // Retail symbol: ?GetDeclInfo@idDeclTrackingParms@@UBAPAVidDeclInfo@@XZ
    // EA: 0x82BD30E8, RVA: 0x00BD30E8
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    idList<trackingParms_t, 5> parms;

    static idDeclInfoTemplate<idDeclTrackingParms> resourceList;
};

static_assert(sizeof(trackingParms_t) == 40,
    "Recovered tracking-parameter row layout changed");

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclTrackingParms) == 80,
    "Recovered tracking-parameter declaration ABI changed");
#endif
