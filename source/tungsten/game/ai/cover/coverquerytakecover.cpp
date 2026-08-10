#include "coverquerytakecover.h"

#include <algorithm>

namespace {

float Clamp01(const float value) {
    return (std::max)(0.0f, (std::min)(value, 1.0f));
}

} // namespace

float idCoverQueryTakeCover::InternalScoreCover(
        const coverCache_t& cached) {
    if (ai == nullptr) {
        return 0.0f;
    }
    const idAICover* const cover =
        Tungsten_GetCoverQueryKnownCover(*ai, cached.index);
    if (cover == nullptr || !cover->IsValid()) {
        return 0.0f;
    }

    idTakeCoverRuntime runtime{};
    if (!Tungsten_GetTakeCoverRuntime(
            *this, *cover, cached, target, runtime)
            || !runtime.hasCurrentEnemy || cover->ShouldAvoid()) {
        return 0.0f;
    }
    if (!cover->IsPointInFrontOf(target.origin)) {
        return DebugFailedTarget(
            "BEHIND", cover->GetOrigin(), target.origin, 1);
    }
    if (!cover->IsPointInArc(
            target.origin, MAX_COVER_ARC_ACOS_DEGREES)) {
        return DebugFailedTarget(
            "NOT_IN_ARC", cover->GetOrigin(), target.origin, 1);
    }
    if (runtime.staleNonEnemyTarget) {
        return 1.0f;
    }
    if (!runtime.roleAllowed) {
        return DebugFailed("ROLE", cover->GetOrigin(), 2);
    }

    const bool fullyExposed = cover->IsFullyExposed();
    if (runtime.usePlayerCoverCheck && runtime.targetIsPlayer
            && runtime.hasPlayerCoverScore && !fullyExposed
            && runtime.playerStandingScore
                > runtime.deferredVisibilityThreshold) {
        return DebugFailedTarget(
            "TARGET_VISIBLE", cover->GetOrigin(), target.origin, 1);
    }
    if (runtime.pathPassesNear) {
        return DebugFailedTarget(
            "PATH_NEAR", cover->GetOrigin(), target.origin, 1);
    }

    const float targetDistance =
        (target.aiPos.origin - cover->GetOrigin()).Length();
    if (targetDistance < runtime.targetTravelDistanceThreshold
            && cached.aiPos.GetAreaNum() > 0
            && runtime.targetToCoverTravelTime > 0
            && runtime.targetToCoverTravelTime * 0.01f
                < runtime.minimumTargetTravelTime) {
        return DebugFailedTarget(
            "TARGET_CLOSE", cover->GetOrigin(), target.origin, 1);
    }

    const float travelScale = runtime.groupFastTravel ? 1.0f : 0.25f;
    const float aiScore = runtime.targetIsCurrentEnemy
        ? Clamp01(1.0f / (cached.travelTime * travelScale + 1.0f))
        : 1.0f;
    if (targetDistance < runtime.minimumTargetDistance) {
        return DebugFailedTarget(
            "TARGET_NEAR", cover->GetOrigin(), target.origin, 1);
    }

    float targetScore = 0.0f;
    if (targetDistance < runtime.idealTargetDistance) {
        targetScore = targetDistance / runtime.idealTargetDistance;
    } else if (!runtime.targetIsCurrentEnemy) {
        targetScore = 1.0f;
    } else if (targetDistance < runtime.maxEnemyCoverDistance) {
        targetScore = 1.0f
            - (targetDistance - runtime.idealTargetDistance)
                / (runtime.maxEnemyCoverDistance
                    - runtime.idealTargetDistance);
    }

    float groupScore = 1.0f;
    if (runtime.targetIsCurrentEnemy) {
        const int memberCount = (std::min)(runtime.groupMemberCount, 64);
        for (int index = 0; index < memberCount; ++index) {
            const idTakeCoverGroupMember& member =
                runtime.groupMembers[index];
            if (!member.contributes
                    || member.distanceToCover >= runtime.groupPenaltyDistance) {
                continue;
            }
            groupScore *= 0.5f
                + 0.5f * member.distanceToCover
                    / runtime.groupPenaltyDistance;
        }
    }

    // The retail call is intentionally retained for explicit partially
    // exposed cover even though its boolean result is not consumed.
    if (cover->IsPartiallyExposed()) {
        cover->IsExplicit();
    }

    float enemyVisibilityScore = 1.0f;
    if (runtime.targetIsCurrentEnemy) {
        if (runtime.targetIsPlayer && runtime.hasPlayerCoverScore) {
            enemyVisibilityScore =
                runtime.playerFirePointScore * 0.6f + 0.4f;
        } else if (runtime.targetIsPlayer
                && !runtime.coverHasDynamicOwner) {
            enemyVisibilityScore = 0.4f;
        } else if (!runtime.targetIsPlayer) {
            enemyVisibilityScore =
                runtime.coverVisibilityRatio * 0.6f + 0.4f;
        }
    }

    float aiVisibilityScore = 1.0f;
    if (runtime.targetIsPlayer && runtime.hasPlayerCoverScore) {
        aiVisibilityScore =
            (1.0f - runtime.playerStandingScore) * 0.9f + 0.1f;
    } else if (runtime.targetIsPlayer
            && !runtime.coverHasDynamicOwner) {
        aiVisibilityScore = 0.1f;
    }

    float angleScore;
    if (!runtime.targetIsCurrentEnemy && runtime.coverAngle < 0.0f) {
        angleScore = 1.0f;
    } else if (runtime.coverAngle < -15.0f
            || runtime.coverAngle > 55.0f) {
        angleScore = 0.0f;
    } else if (runtime.coverAngle <= 0.0f) {
        angleScore = (runtime.coverAngle + 15.0f)
            * (0.25f / 15.0f);
    } else {
        angleScore = 1.0f - runtime.coverAngle / 110.0f;
    }

    const float score = Clamp01(runtime.historyScore * angleScore
        * aiVisibilityScore * enemyVisibilityScore * groupScore
        * targetScore * aiScore);
    return DebugSucceeded(score, targetScore, aiScore, angleScore,
        groupScore, enemyVisibilityScore, aiVisibilityScore, 1.0f,
        cover->GetOrigin(), target.origin, 1);
}
