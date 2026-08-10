#include "coverquery.h"

#include <algorithm>
#include <cmath>
#include <limits>

const idVec3 idCoverQuery::INVALID_ORIGIN(
    std::numeric_limits<float>::max(),
    std::numeric_limits<float>::max(),
    std::numeric_limits<float>::max());

const float idCoverQuery::MAX_COVER_ARC_ACOS_DEGREES =
    std::cos(55.0f * 0.01745329251994329577f);

// Header-origin retail symbol: ??0idCoverQuery@@QAA@PAVidAI2@@ABVidAICover@@H@Z
// EA: 0x82A023B0, RVA: 0x00A023B0
idCoverQuery::idCoverQuery(idAI2* const aiValue,
        const idAICover& excludedCover, const int flags)
    : ai(aiValue)
    , target()
    , excludeCover(excludedCover)
    , debugLevel(0)
    , queryFlags(flags)
    , minTravelTimeIndex(-1)
    , minTravelTime(0.0f)
    , maxTravelTimeIndex(-1)
    , maxTravelTime(0.0f)
    , travelTimeRange(0.0f)
    , aiaiPos{}
    , aivcPos{}
    , relevantCover(16) {
}

// Retail symbol: ?DebugFailed@idCoverQuery@@IBAMPBDABVidVec3@@H@Z
// EA: 0x82A8AD90, RVA: 0x00A8AD90
float idCoverQuery::DebugFailed(const char* const message,
        const idVec3& origin, const int minLevel) const {
    Tungsten_DebugCoverQueryFailure(
        *this, message, origin, nullptr, minLevel);
    return 0.0f;
}

// Retail symbol: ?DebugFailedTarget@idCoverQuery@@IBAMPBDABVidVec3@@1H@Z
// EA: 0x82A8AEC0, RVA: 0x00A8AEC0
float idCoverQuery::DebugFailedTarget(const char* const message,
        const idVec3& origin, const idVec3& targetOrigin,
        const int minLevel) const {
    Tungsten_DebugCoverQueryFailure(
        *this, message, origin, &targetOrigin, minLevel);
    return 0.0f;
}

// Retail symbol: ?DebugSucceeded@idCoverQuery@@IBAMMMMMMMMMMABVidVec3@@0H@Z
// EA: 0x82A8B080, RVA: 0x00A8B080
float idCoverQuery::DebugSucceeded(const float score,
        const float targetScore, const float aiScore,
        const float angleScore, const float groupScore,
        const float enemyVisibilityScore, const float aiVisibilityScore,
        const float miscScore, const idVec3& coverOrigin,
        const idVec3& targetOrigin, const int minLevel) const {
    const float components[] = {score, targetScore, aiScore, angleScore,
        groupScore, enemyVisibilityScore, aiVisibilityScore, miscScore};
    Tungsten_DebugCoverQuerySuccess(*this, components,
        static_cast<int>(sizeof(components) / sizeof(components[0])),
        coverOrigin, targetOrigin, minLevel);
    return score;
}

// Retail symbol: ?DebugSucceededAvoid@idCoverQuery@@IBAMMMMMMMMABVidVec3@@0H@Z
// EA: 0x82A8B328, RVA: 0x00A8B328
float idCoverQuery::DebugSucceededAvoid(const float score,
        const float angleScore, const float angle, const float travelScore,
        const float proximityScore, const float awayScore,
        const float velocityScore, const idVec3& coverOrigin,
        const idVec3& targetOrigin, const int minLevel) const {
    const float components[] = {score, angleScore, angle, travelScore,
        proximityScore, awayScore, velocityScore};
    Tungsten_DebugCoverQuerySuccess(*this, components,
        static_cast<int>(sizeof(components) / sizeof(components[0])),
        coverOrigin, targetOrigin, minLevel);
    return score;
}

// Retail symbol: ??0coverTarget_t@idCoverQuery@@QAA@XZ
// EA: 0x82A8B5B8, RVA: 0x00A8B5B8
idCoverQuery::coverTarget_t::coverTarget_t()
    : spawnId(0x1FFF)
    , origin(idCoverQuery::INVALID_ORIGIN)
    , eyePoint(idCoverQuery::INVALID_ORIGIN)
    , aiPos{}
    , vcPos{}
    , confirmedTime(-1) {
}

// Retail symbol: ?PreScore@idCoverQuery@@AAAXXZ
// EA: 0x82A8B800, RVA: 0x00A8B800
void idCoverQuery::PreScore() {
    InternalPreScore();
}

// Retail symbol: ?SetupTarget@idCoverQuery@@AAAXABUcoverTarget_t@1@@Z
// EA: 0x82A8B8C0, RVA: 0x00A8B8C0
void idCoverQuery::SetupTarget(const coverTarget_t& newTarget) {
    target = newTarget;
    if (target.spawnId.value != 0x1FFF && ai != nullptr) {
        Tungsten_GetCoverQueryTargetState(*ai, target.spawnId.value,
            target.origin, target.eyePoint, target.confirmedTime);
    }
    const idAAS2* const visibilityAas = Tungsten_GetCoverQueryVisibilityAAS();
    target.vcPos.Update(visibilityAas, target.origin);
    target.aiPos.Update(ai != nullptr ? Tungsten_GetCoverQueryAAS(*ai) : nullptr,
        target.origin);
    InternalSetupTarget(target);
}

// Retail symbol: ?ScoreCover@idCoverQuery@@AAAMABUcoverCache_t@1@@Z
// EA: 0x82A8BB58, RVA: 0x00A8BB58
float idCoverQuery::ScoreCover(const coverCache_t& cached) {
    return InternalScoreCover(cached);
}

// Retail symbol: ?FindRelevantCover@idCoverQuery@@AAAXXZ
// EA: 0x82A8BCC0, RVA: 0x00A8BCC0
void idCoverQuery::FindRelevantCover() {
    relevantCover.Clear();
    minTravelTimeIndex = -1;
    maxTravelTimeIndex = -1;
    minTravelTime = std::numeric_limits<float>::max();
    maxTravelTime = std::numeric_limits<float>::min();

    if (ai == nullptr) {
        travelTimeRange = 0.0f;
        return;
    }

    const idAAS2* const visibilityAas = Tungsten_GetCoverQueryVisibilityAAS();
    const int coverCount = Tungsten_GetCoverQueryKnownCoverCount(*ai);
    for (int index = 0; index < coverCount; ++index) {
        const idAICover* const candidate =
            Tungsten_GetCoverQueryKnownCover(*ai, index);
        if (candidate == nullptr) {
            continue;
        }
        if (*candidate == excludeCover) {
            DebugFailed("EXCLUDE", candidate->GetOrigin(), 2);
            continue;
        }
        if (!candidate->IsValid()) {
            DebugFailed("INVALID", candidate->GetOrigin(), 2);
            continue;
        }
        if (!candidate->IsUsable()) {
            DebugFailed("UNUSABLE", candidate->GetOrigin(), 2);
            continue;
        }
        if (candidate->IsReserved()
            && static_cast<const void*>(candidate->GetReserver())
                != static_cast<const void*>(ai)) {
            const idEntity* const reserver = candidate->GetReserver();
            if (reserver != nullptr
                && Tungsten_CoverQueryReserverUsesCover(
                    *reserver, *candidate)) {
                DebugFailed("RESERVED", candidate->GetOrigin(), 2);
                continue;
            }
            Tungsten_CoverQueryReservationWarning(candidate->coverIndex);
            candidate->Unreserve();
        }
        if ((queryFlags & 0x10) == 0 && candidate->IsPartiallyExposed()) {
            DebugFailed("PARTIAL", candidate->GetOrigin(), 2);
            continue;
        }
        const posture_t posture = candidate->GetCoverPosture();
        if (posture == POSTURE_CROUCHED && (queryFlags & 0x08) == 0) {
            DebugFailed("CROUCHING", candidate->GetOrigin(), 2);
            continue;
        }
        if (posture == POSTURE_STANDING && (queryFlags & 0x04) == 0) {
            DebugFailed("STANDING", candidate->GetOrigin(), 2);
            continue;
        }
        if (!Tungsten_CoverQueryHasOrientation(*ai, *candidate)) {
            DebugFailed("ORIENTATION", candidate->GetOrigin(), 2);
            continue;
        }
        if (Tungsten_IsCoverQueryBlocked(*ai, *candidate)) {
            DebugFailed("BLOCKED", candidate->GetOrigin(), 2);
            continue;
        }

        coverCache_t* const cached = relevantCover.Alloc();
        if (cached == nullptr) {
            break;
        }
        cached->index = index;
        cached->vcPos = idAASPosition{};
        cached->vcPos.Update(visibilityAas, candidate->GetOrigin());
        cached->vcAreaNum = cached->vcPos.GetAreaNum();
        cached->aiPos = idAASPosition{};
        cached->aiPos.Initialize(candidate->aas, candidate->GetAreaNum(),
            candidate->GetOrigin());
        cached->delta = candidate->GetOrigin() - aiaiPos.origin;
        cached->linearDistance = cached->delta.Length();
        cached->score = 1.0f;
        cached->travelTime = cached->linearDistance * 4.1666665f * 0.001f;
        if (cached->travelTime < minTravelTime) {
            minTravelTime = cached->travelTime;
            minTravelTimeIndex = index;
        }
        if (cached->travelTime > maxTravelTime) {
            maxTravelTime = cached->travelTime;
            maxTravelTimeIndex = index;
        }
    }

    travelTimeRange = std::max(
        maxTravelTime - minTravelTime - 0.001f, 0.0f);
}

// Retail symbol: ?Execute@idCoverQuery@@QAA_NABV?$idList@UcoverTarget_t@idCoverQuery@@$04@@ABVidVec3@@AAVidAICover@@_N@Z
// EA: 0x82A8C778, RVA: 0x00A8C778
bool idCoverQuery::Execute(const idList<coverTarget_t, 5>& targets,
        const idVec3& referencePoint, idAICover& bestCover,
        const bool inAvoid) {
    if (ai == nullptr) {
        return false;
    }
    debugLevel = Tungsten_GetCoverQueryDebugLevel(*ai);
    const int currentTime = Tungsten_GetCoverQueryGameMilliseconds();
    if (!Tungsten_CoverQueryHasCover(
            *ai, referencePoint, currentTime, inAvoid)) {
        return false;
    }

    const idVec3 aiOrigin = Tungsten_GetCoverQueryAIOrigin(*ai);
    aivcPos.Update(Tungsten_GetCoverQueryVisibilityAAS(), aiOrigin);
    aiaiPos.Update(Tungsten_GetCoverQueryAAS(*ai), aiOrigin);
    FindRelevantCover();
    PreScore();

    const float minimumScore = inAvoid ? 0.1f : 0.0f;
    float bestScore = 0.0f;
    int bestRelevantIndex = -1;
    for (int targetIndex = 0; targetIndex < targets.Num(); ++targetIndex) {
        SetupTarget(targets[targetIndex]);
        for (int coverIndex = 0; coverIndex < relevantCover.Num();
                ++coverIndex) {
            coverCache_t& cached = relevantCover[coverIndex];
            cached.score *= ScoreCover(cached);
            if (targetIndex == targets.Num() - 1) {
                if (cached.score > bestScore && cached.score > minimumScore) {
                    bestScore = cached.score;
                    bestRelevantIndex = coverIndex;
                }
                const idAICover* const candidate =
                    Tungsten_GetCoverQueryKnownCover(*ai, cached.index);
                if (candidate != nullptr) {
                    Tungsten_DebugCoverQueryResult(
                        *this, *candidate, cached.score, false);
                }
            }
        }
    }

    if (bestRelevantIndex < 0) {
        return false;
    }
    const idAICover* const selected = Tungsten_GetCoverQueryKnownCover(
        *ai, relevantCover[bestRelevantIndex].index);
    if (selected == nullptr) {
        return false;
    }
    bestCover = *selected;
    Tungsten_DebugCoverQueryResult(*this, bestCover, bestScore, true);
    return true;
}
