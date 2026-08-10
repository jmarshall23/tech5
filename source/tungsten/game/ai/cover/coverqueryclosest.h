#pragma once

#include "coverquery.h"

class idCoverQueryClosest : public idCoverQuery {
public:
    idCoverQueryClosest(idAI2* ai, const idAICover& exclude,
        const idVec3& desiredCoverPosition);
    ~idCoverQueryClosest() override = default;

protected:
    float InternalScoreCover(const coverCache_t& cached) override;

public:
    idVec3 desiredCoverPosition;
};

bool Tungsten_GetCoverQueryPlayerStandingScore(
    int targetSpawnId, int coverIndex, float& standingScore);
bool Tungsten_IsCoverQueryPointVisible(const idVec3& eyePoint,
    const idVec3& destinationPoint, const idAAS2& aas, int areaNum);
float Tungsten_GetCoverQueryPathNearDistance(const idAI2& ai);
bool Tungsten_CoverQueryPathPassesNear(const idAI2& ai,
    const idAASPosition& start, const idAASPosition& goal,
    const idAASPosition& test, float nearDistance);
void Tungsten_GetCoverQueryEyePoint(
    const idAICover& cover, const idAI2& ai, idVec3& eyePoint);
