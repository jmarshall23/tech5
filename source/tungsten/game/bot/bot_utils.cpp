#include "bot_utils.h"

#include <cmath>

namespace {
idBotUtilsServices* g_utilsServices = nullptr;

constexpr float ANGLES_TO_TEST[] = {
    0.0f, 45.0f, -45.0f, 90.0f,
    -90.0f, 135.0f, -135.0f, 180.0f
};
constexpr float DEG_TO_RAD = 0.01745329251994329577f;

idVec3 RotateAroundUp(const idVec3& vector, const float degrees) {
    const float sine = std::sin(degrees * DEG_TO_RAD);
    const float cosine = std::cos(degrees * DEG_TO_RAD);
    return idVec3(vector.x * cosine - vector.y * sine,
        vector.x * sine + vector.y * cosine, vector.z);
}
} // namespace

void Tungsten_SetBotUtilsServices(idBotUtilsServices* const services) {
    g_utilsServices = services;
}

// Retail symbol: ?FindAvoidEntityPoint@idBotUtils@@SA_NPBVidBot@@PBVidEntity@@MAAVidVec3@@PBV4@M@Z
// EA: 0x82B44060, RVA: 0x00B44060
bool idBotUtils::FindAvoidEntityPoint(const idBot* const bot,
        const idEntity* const entity, const float moveDist, idVec3& point,
        const idVec3* const anchorPoint, const float anchorRadius) {
    if (bot == nullptr || entity == nullptr || g_utilsServices == nullptr) {
        return false;
    }
    const idAAS2* const aas = g_utilsServices->GetBotAAS(*bot);
    if (aas == nullptr) {
        return false;
    }
    const int areaNum = g_utilsServices->GetBotAreaNum(*bot, *aas);
    if (areaNum == 0) {
        return false;
    }

    const idVec3 entityOrigin = g_utilsServices->GetEntityOrigin(*entity);
    const idVec3 botOrigin = g_utilsServices->GetBotOrigin(*bot);
    idVec3 awayDirection = botOrigin - entityOrigin;
    awayDirection.NormalizeFast();
    const idVec3 entityForward =
        g_utilsServices->GetEntityForward(*entity);
    const float anchorRadiusSqr = anchorRadius * anchorRadius;
    float bestScore = -1.0f;
    idVec3 bestPoint(0.0f, 0.0f, 0.0f);

    for (const float angle : ANGLES_TO_TEST) {
        if (bestScore >= 1.0f) {
            break;
        }
        const idVec3 candidate = botOrigin
            + RotateAroundUp(awayDirection, angle) * moveDist;
        if (anchorPoint != nullptr) {
            const float deltaX = candidate.x - anchorPoint->x;
            const float deltaY = candidate.y - anchorPoint->y;
            if (deltaX * deltaX + deltaY * deltaY > anchorRadiusSqr) {
                continue;
            }
        }

        idVec3 candidateFromEntity = candidate - entityOrigin;
        candidateFromEntity.NormalizeFast();
        const float facingPenalty = candidateFromEntity.Dot(entityForward)
            > 0.85f ? 0.5f : 1.0f;
        const float fraction = g_utilsServices->TraceAvoidFloor(
            *bot, *aas, areaNum, botOrigin, candidate);
        if (fraction > bestScore) {
            bestPoint = candidate;
            bestScore = fraction * facingPenalty;
        }
    }
    if (bestScore == -1.0f) {
        return false;
    }
    point = bestPoint;
    return true;
}
