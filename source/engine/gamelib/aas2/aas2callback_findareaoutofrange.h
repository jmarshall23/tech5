#pragma once

#include "gamelib/aas2/aas2callback_avoidlocation.h"

class idClip;

class idAAS2Callback_FindAreaOutOfRange
    : public idAAS2Callback_AvoidLocation {
public:
    ~idAAS2Callback_FindAreaOutOfRange() override = default;
    bool PathValid(const idAAS2* aas, const idVec3* start,
        const idVec3* end) override;
    int AdditionalTravelTimeForPath(const idAAS2* aas,
        const idVec3* start, const idVec3* end) override;
    bool AreaIsGoal(const idAAS2* aas, int areaNumber,
        const idVec3* origin) override;

    idClip* clip;
    idVec3 targetPos;
    float maxDistSqr;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAAS2Callback_FindAreaOutOfRange) == 48,
    "Recovered out-of-range AAS callback ABI changed");
#endif
