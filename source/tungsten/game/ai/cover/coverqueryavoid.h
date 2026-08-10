#pragma once

#include "coverquery.h"

class idCoverQueryAvoid : public idCoverQuery {
public:
    idCoverQueryAvoid(idAI2* ai, const idEntity* avoidEntity,
        const idAICover& exclude, float maximumAvoidTime);
    ~idCoverQueryAvoid() override = default;

protected:
    void InternalPreScore() override;
    float InternalScoreCover(const coverCache_t& cached) override;

public:
    float maxAvoidTime;
    const idEntity* avoidEnt;
    idAASPosition avoidvcPos;
    idVec3 avoidOrigin;
};

idVec3 Tungsten_GetCoverQueryEntityOrigin(const idEntity& entity);
idVec3 Tungsten_GetCoverQueryAILinearVelocity(const idAI2& ai);
bool Tungsten_GetCoverQueryProjectileDamageRadius(
    const idEntity& entity, float& damageRadius);
bool Tungsten_CoverQueryAvoidMatchesTarget(
    const idEntity& entity, int targetSpawnId);
