#include "coverqueryclosest.h"

// Retail symbol: ?InternalScoreCover@idCoverQueryClosest@@MAAMABUcoverCache_t@idCoverQuery@@@Z
// EA: 0x82A8D220, RVA: 0x00A8D220
float idCoverQueryClosest::InternalScoreCover(
        const coverCache_t& cached) {
    if (ai == nullptr) {
        return 0.0f;
    }
    const idAICover* const cover =
        Tungsten_GetCoverQueryKnownCover(*ai, cached.index);
    if (cover == nullptr || !cover->IsValid()) {
        return 0.0f;
    }
    if (!cover->IsPointInFrontOf(target.origin)) {
        return DebugFailedTarget("BEHIND", cover->GetOrigin(),
            target.origin, 1);
    }

    idVec3 eyePoint;
    Tungsten_GetCoverQueryEyePoint(*cover, *ai, eyePoint);
    const bool partiallyExposed = cover->IsPartiallyExposed();
    float playerStandingScore = 0.0f;
    if (Tungsten_GetCoverQueryPlayerStandingScore(
            target.spawnId.value, cover->coverIndex,
            playerStandingScore)) {
        if (!partiallyExposed && playerStandingScore > 0.5f) {
            return DebugFailedTarget("TARGET_VISIBLE (PCS)",
                cover->GetOrigin(), target.origin, 1);
        }
    } else if (!partiallyExposed && target.vcPos.aas != nullptr
        && Tungsten_IsCoverQueryPointVisible(eyePoint, target.eyePoint,
            *target.vcPos.aas, target.vcPos.GetAreaNum())) {
        return DebugFailedTarget("TARGET_VISIBLE(AASVIS)",
            cover->GetOrigin(), target.origin, 1);
    }

    if (Tungsten_CoverQueryPathPassesNear(*ai, aiaiPos, cached.aiPos,
            target.aiPos, Tungsten_GetCoverQueryPathNearDistance(*ai))) {
        return DebugFailedTarget("PATH_NEAR", cover->GetOrigin(),
            target.aiPos.origin, 1);
    }

    const idVec3 delta = cover->GetOrigin() - desiredCoverPosition;
    const float distanceSqr = delta.LengthSqr();
    if (distanceSqr > 512.0f * 512.0f) {
        return 0.0f;
    }
    return 1.0f - distanceSqr * (1.0f / (512.0f * 512.0f));
}

// Retail symbol: ??0idCoverQueryClosest@@QAA@PAVidAI2@@ABVidAICover@@ABVidVec3@@@Z
// EA: 0x82A8D510, RVA: 0x00A8D510
idCoverQueryClosest::idCoverQueryClosest(idAI2* const aiValue,
        const idAICover& exclude, const idVec3& desiredPosition)
    : idCoverQuery(aiValue, exclude, 31)
    , desiredCoverPosition(desiredPosition) {
}
