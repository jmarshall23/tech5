#include "scenepoint_common.h"

#include <algorithm>
#include <cmath>

namespace {

constexpr int kScenePointEnabled = 0x08;
constexpr int kScriptedScenePoint = 0x001;
constexpr int kPlayerMustBeInArc = 0x010;
constexpr int kPlayerMustBeOutsideArc = 0x020;
constexpr int kRejectDamageAfterTake = 0x040;
constexpr int kRejectDamageAfterActivate = 0x080;
constexpr int kRejectAwareEnemy = 0x100;
constexpr int kRejectVisibleEnemy = 0x200;

constexpr int kAllowTactical = 0x01;
constexpr int kPreferNear = 0x02;
constexpr int kPreferBehindEnemy = 0x04;
constexpr int kAllowNonPositiveHistory = 0x08;
constexpr int kIgnoreFocusSide = 0x10;
constexpr int kPreferTurret = 0x20;

float Clamp01(const float value) {
    return (std::max)(0.0f, (std::min)(value, 1.0f));
}

float Length2D(const idVec3& value) {
    return std::sqrt(value.x * value.x + value.y * value.y);
}

float Normalize(idVec3& value) {
    const float length = std::sqrt(value.x * value.x
        + value.y * value.y + value.z * value.z);
    if (length > 0.0f) {
        const float inverseLength = 1.0f / length;
        value.x *= inverseLength;
        value.y *= inverseLength;
        value.z *= inverseLength;
    }
    return length;
}

float Dot(const idVec3& left, const idVec3& right) {
    return left.x * right.x + left.y * right.y + left.z * right.z;
}

bool GetPointRuntime(const idAI2& ai, const idScenePoint* point,
        const idAIPos& focus, idScenePointRuntime& runtime) {
    runtime = {};
    return point != nullptr
        && Tungsten_GetScenePointRuntime(ai, *point, focus, runtime);
}

} // namespace

// Retail symbol: ?IsScriptScenePointValid@@YA_NPBVidAI2@@PBVidScenePoint@@@Z
// EA: 0x82AF5A30, RVA: 0x00AF5A30
bool IsScriptScenePointValid(const idAI2* const ai,
        const idScenePoint* const scriptScenePoint) {
    if (ai == nullptr || scriptScenePoint == nullptr) {
        return false;
    }

    idScriptScenePointRuntime runtime{};
    if (!Tungsten_GetScriptScenePointRuntime(
            *ai, *scriptScenePoint, runtime)
        || (runtime.scriptFlags & kScriptedScenePoint) == 0) {
        return false;
    }
    if ((runtime.scriptFlags & kPlayerMustBeInArc) != 0
            && runtime.hasPlayer && !runtime.playerInArc) {
        return false;
    }
    if ((runtime.scriptFlags & kPlayerMustBeOutsideArc) != 0
            && runtime.hasPlayer && runtime.playerInArc) {
        return false;
    }
    if ((runtime.scriptFlags & kRejectDamageAfterTake) != 0
            && runtime.lastDamageTime > 0
            && runtime.currentScenePointTakeTime > 0
            && runtime.lastDamageTime
                > runtime.currentScenePointTakeTime) {
        return false;
    }
    if ((runtime.scriptFlags & kRejectDamageAfterActivate) != 0
            && runtime.lastDamageTime > 0
            && runtime.currentScenePointActivateTime > 0
            && runtime.lastDamageTime
                > runtime.currentScenePointActivateTime) {
        return false;
    }
    if ((runtime.scriptFlags & kRejectAwareEnemy) != 0
            && runtime.hasEnemyState && runtime.enemyAwareness > 1u) {
        return false;
    }
    if ((runtime.scriptFlags & kRejectVisibleEnemy) != 0
            && runtime.hasEnemyState && runtime.enemyVisible) {
        return false;
    }
    return true;
}

// Retail symbol: ?SupportsCustomCoverSet@@YA_NPBVidAI2@@ABVidAnimWebPath@@@Z
// EA: 0x82AF5C28, RVA: 0x00AF5C28
bool SupportsCustomCoverSet(const idAI2* const ai,
        const idAnimWebPath& animPath) {
    if (ai == nullptr || animPath.Length() == 0) {
        return false;
    }

    idStr expectedSubWeb;
    Tungsten_GetScenePointWeaponPrefix(*ai, expectedSubWeb);
    expectedSubWeb.Append("fcover_custom");

    idStr subWebName;
    idStr stateName;
    Tungsten_SplitScenePointAnimWebPath(
        *ai, animPath.c_str(), subWebName, stateName);
    return idStr::Cmp(subWebName.c_str(), expectedSubWeb.c_str()) == 0
        && Tungsten_HasScenePointAnimWebState(
            *ai, subWebName.c_str(), stateName.c_str());
}

// Retail symbol:
// ?GetBestScenePoint@@YAPAVidScenePoint@@PAVidAI2@@MMABVidAIPos@@W4scenePointType_t@@W4scenePointLookFlags_t@@@Z
// EA: 0x82AF5E00, RVA: 0x00AF5E00
idScenePoint* GetBestScenePoint(idAI2* const ai,
        float minRange, float maxRange, const idAIPos& focus,
        const scenePointType_t type,
        const scenePointLookFlags_t lookFlags) {
    if (ai == nullptr) {
        return nullptr;
    }

    idScenePointSelectionRuntime selection{};
    if (!Tungsten_GetScenePointSelectionRuntime(
            *ai, type, selection)
        || !selection.usesScenePointType) {
        return nullptr;
    }

    idScenePoint* overridePoint = selection.overrideScenePoint;
    if (selection.lastHeldScenePoint != nullptr && type != LOOK) {
        idScenePointRuntime chained{};
        if (selection.nextMatchingScenePoint != nullptr) {
            if (GetPointRuntime(*ai, selection.nextMatchingScenePoint,
                    focus, chained) && chained.enabled) {
                overridePoint = selection.nextMatchingScenePoint;
                Tungsten_SetOverrideScenePoint(*ai, overridePoint);
            }
        } else if (selection.nextScenePoint != nullptr
                && GetPointRuntime(*ai, selection.nextScenePoint,
                    focus, chained) && chained.enabled) {
            Tungsten_SetOverrideScenePoint(
                *ai, selection.nextScenePoint);
            return nullptr;
        }
    }

    idScenePointRuntime overrideRuntime{};
    if (overridePoint != nullptr) {
        if (!GetPointRuntime(
                *ai, overridePoint, focus, overrideRuntime)
            || !overrideRuntime.enabled || overrideRuntime.type != type) {
            overridePoint = nullptr;
        } else if ((overrideRuntime.scriptFlags
                        & kScriptedScenePoint) != 0
                && IsScriptScenePointValid(ai, overridePoint)) {
            // This early path in the executable intentionally bypasses the
            // focus-validity and arc checks for a valid scripted override.
            Tungsten_SetOverrideScenePoint(*ai, nullptr);
            return overridePoint;
        }
    }

    if (!focus.valid) {
        return nullptr;
    }
    if (overridePoint != nullptr) {
        if (type == ROAM
                || (type > ROAM && type <= COMBAT
                    && overrideRuntime.inFocusArc)) {
            Tungsten_SetOverrideScenePoint(*ai, nullptr);
            return overridePoint;
        }
        return nullptr;
    }
    if (!selection.hasScenePointVolumes) {
        return nullptr;
    }
    if (selection.candidateCount <= 0
            || selection.candidatePoints == nullptr) {
        Tungsten_SetScenePointSelectionTime(
            *ai, type, selection.currentTime);
        return nullptr;
    }

    idVec3 referenceOrigin = selection.aiOrigin;
    const float originalRangeDelta = maxRange - minRange;
    const float inverseRange = 1.0f
        / (maxRange < minRange ? minRange + 1000.0f
                              : originalRangeDelta);
    if (selection.hasSquadLeader) {
        referenceOrigin = selection.squadLeaderOrigin;
        minRange = 0.0f;
        maxRange = selection.squadScenePointRange;
    }

    idScenePoint* bestPoint = nullptr;
    float bestScore = 0.0f;
    for (int index = 0; index < selection.candidateCount; ++index) {
        idScenePoint* const point = selection.candidatePoints[index];
        idScenePointRuntime candidate{};
        if (!GetPointRuntime(*ai, point, focus, candidate)
                || !candidate.enabled || candidate.type != type
                || (candidate.hasCurrentUser
                    && selection.currentTime < candidate.requestTime)) {
            continue;
        }

        const idVec3 fromReference =
            candidate.origin - referenceOrigin;
        const float horizontalDistance = Length2D(fromReference);
        if (horizontalDistance < minRange
                || (maxRange > 0.0f
                    && horizontalDistance > maxRange)
                || (maxRange > 0.0f
                    && std::fabs(fromReference.z) > maxRange)) {
            continue;
        }

        idVec3 normalizedFromReference = fromReference;
        Normalize(normalizedFromReference);
        const float distanceScore =
            (selection.selectionFlags & kPreferNear) != 0
                ? 1.0f - Clamp01(
                    (horizontalDistance - minRange) * inverseRange)
                : 0.5f;
        float score = Tungsten_ScenePointRandomFloat()
                * selection.coverRandomWeight
            + distanceScore + 1.0f
            - selection.coverVerticalWeight
                * std::fabs(normalizedFromReference.z);

        if ((type == SEARCH || type == COMBAT)
                && !candidate.inFocusArc) {
            continue;
        }
        switch (type) {
        case LOOK:
            if (!candidate.lookCastValid
                    || (candidate.lookFlags
                        & static_cast<int>(lookFlags)) == 0
                    || !candidate.inFocusArc) {
                continue;
            }
            break;
        case SEARCH:
            if (Length2D(focus.origin - candidate.origin)
                    < Length2D(focus.origin - referenceOrigin)) {
                score += 1.0f;
            }
            break;
        case COMBAT:
            if (!candidate.combatCastValid) {
                continue;
            }
            if (candidate.hasTurret) {
                if ((selection.selectionFlags & kPreferTurret) != 0) {
                    score += 3.0f;
                }
            } else if (candidate.tactical) {
                if ((selection.selectionFlags & kAllowTactical) == 0) {
                    continue;
                }
                score += selection.coverTacticalWeight;
            }
            if (candidate.hasDeathAnimation) {
                score += 0.5f;
            }
            if (candidate.customCoverSet != nullptr
                    && candidate.customCoverSet->Length() != 0) {
                if (!SupportsCustomCoverSet(
                        ai, *candidate.customCoverSet)) {
                    continue;
                }
                score += 1.5f;
            }
            break;
        default:
            break;
        }

        if ((selection.selectionFlags & kIgnoreFocusSide) == 0) {
            idVec3 pointFromFocus = candidate.origin - focus.origin;
            idVec3 focusFromReference = focus.origin - referenceOrigin;
            Normalize(pointFromFocus);
            const float focusDistance = Normalize(focusFromReference);
            if (fromReference.Length() > focusDistance
                    && Dot(pointFromFocus, focusFromReference)
                        > 0.70700002f) {
                continue;
            }
        }

        if ((selection.selectionFlags & kPreferBehindEnemy) != 0
                && selection.hasEnemy) {
            idVec3 pointFromFocus = candidate.origin - focus.origin;
            Normalize(pointFromFocus);
            score += 1.0f
                - Clamp01(Dot(pointFromFocus, selection.enemyForward));
        }

        if (type == LOOK) {
            if (candidate.lookHistoryScore <= 0.0f) {
                continue;
            }
            score += candidate.lookHistoryScore;
        } else {
            if ((selection.selectionFlags
                    & kAllowNonPositiveHistory) == 0
                    && candidate.historyScore <= 0.0f) {
                continue;
            }
            score += candidate.historyScore
                * (type == COMBAT
                    ? selection.coverHistoryWeight : 1.0f);
        }

        if (score > bestScore) {
            bestScore = score;
            bestPoint = point;
        }
    }

    if (bestPoint == nullptr) {
        Tungsten_SetScenePointSelectionTime(
            *ai, type, selection.currentTime);
    }
    return bestPoint;
}
