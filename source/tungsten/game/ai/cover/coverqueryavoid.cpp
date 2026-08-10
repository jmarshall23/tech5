#include "coverqueryavoid.h"

#include <algorithm>
#include <cmath>

namespace {

float Clamp01(const float value) {
    return std::max(0.0f, std::min(1.0f, value));
}

} // namespace

// Header-origin retail symbol: ??0idCoverQueryAvoid@@QAA@PAVidAI2@@PBVidEntity@@ABVidAICover@@M@Z
// EA: 0x82AC2198, RVA: 0x00AC2198
idCoverQueryAvoid::idCoverQueryAvoid(idAI2* const aiValue,
        const idEntity* const avoidEntity, const idAICover& exclude,
        const float maximumAvoidTime)
    : idCoverQuery(aiValue, exclude, 31)
    , maxAvoidTime(maximumAvoidTime)
    , avoidEnt(avoidEntity)
    , avoidvcPos{}
    , avoidOrigin(0.0f, 0.0f, 0.0f) {
}

// Retail symbol: ?InternalPreScore@idCoverQueryAvoid@@EAAXXZ
// EA: 0x82A8CD68, RVA: 0x00A8CD68
void idCoverQueryAvoid::InternalPreScore() {
    if (avoidEnt == nullptr) {
        avoidvcPos = idAASPosition{};
        avoidOrigin.Zero();
        return;
    }
    avoidOrigin = Tungsten_GetCoverQueryEntityOrigin(*avoidEnt);
    avoidvcPos.Update(Tungsten_GetCoverQueryVisibilityAAS(), avoidOrigin);
}

// Retail symbol: ?InternalScoreCover@idCoverQueryAvoid@@EAAMABUcoverCache_t@idCoverQuery@@@Z
// EA: 0x82A8CDE8, RVA: 0x00A8CDE8
float idCoverQueryAvoid::InternalScoreCover(const coverCache_t& cached) {
    if (ai == nullptr) {
        return 0.0f;
    }
    const idAICover* const cover =
        Tungsten_GetCoverQueryKnownCover(*ai, cached.index);
    if (cover == nullptr || !cover->IsValid()) {
        return 0.0f;
    }
    if (cover->IsFullyExposed()) {
        return DebugFailed("FULLY EXPOSED", cover->GetOrigin(), 1);
    }
    if (cached.travelTime >= maxAvoidTime) {
        return DebugFailed("TOO_FAR", cover->GetOrigin(), 1);
    }

    const bool avoidingTarget = avoidEnt != nullptr
        && Tungsten_CoverQueryAvoidMatchesTarget(
            *avoidEnt, target.spawnId.value);
    float proximityRadius = 128.0f;
    float damageRadius = 0.0f;
    if (avoidEnt != nullptr
        && Tungsten_GetCoverQueryProjectileDamageRadius(
            *avoidEnt, damageRadius)) {
        proximityRadius = std::max(128.0f - damageRadius, 0.0f);
    }

    const float lowAngleScore = avoidingTarget ? 0.0f : 0.5f;
    const float angle = cover->AngleToPoint(target.origin, false);
    float angleScore = lowAngleScore;
    if (angle >= -90.0f && angle <= 60.0f) {
        angleScore = angle <= 0.0f ? 1.0f
            : lowAngleScore
                + (60.0f - angle) * (1.0f - lowAngleScore) / 60.0f;
    }

    float travelScore = 1.0f;
    if (avoidingTarget && maxAvoidTime > 0.0f) {
        travelScore = Clamp01(cached.travelTime / maxAvoidTime);
    }

    const float targetDistance =
        (target.origin - cover->GetOrigin()).Length();
    const float closeness = proximityRadius > 0.0f
        ? Clamp01((proximityRadius - targetDistance) / proximityRadius)
        : 0.0f;
    const float proximityScore =
        1.0f - (1.0f - closeness) * (1.0f - angleScore);

    float awayScore = 1.0f;
    float velocityScore = 1.0f;
    if (avoidingTarget) {
        idVec3 coverDirection = cover->GetOrigin()
            - Tungsten_GetCoverQueryAIOrigin(*ai);
        const float coverDistance = coverDirection.NormalizeFast();
        if (coverDistance > 32.0f) {
            idVec3 targetDirection = target.origin
                - Tungsten_GetCoverQueryAIOrigin(*ai);
            if (targetDirection.NormalizeFast() > 1.0f) {
                awayScore = Clamp01(
                    (1.0f - coverDirection.Dot(targetDirection)) * 0.5f);
            }
            idVec3 velocity = Tungsten_GetCoverQueryAILinearVelocity(*ai);
            if (velocity.NormalizeFast() > 1.0f) {
                velocityScore = Clamp01(
                    0.75f + 0.25f * velocity.Dot(coverDirection));
            }
        }
    }

    const float score = velocityScore * awayScore * proximityScore
        * travelScore * angleScore;
    return DebugSucceededAvoid(score, angleScore, angle, travelScore,
        proximityScore, awayScore, velocityScore, cover->GetOrigin(),
        target.origin, 1);
}
