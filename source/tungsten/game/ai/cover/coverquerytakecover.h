#pragma once

#include "coverquery.h"

struct idTakeCoverGroupMember {
    float distanceToCover;
    bool contributes;
};

struct idTakeCoverRuntime {
    bool hasCurrentEnemy;
    bool targetIsCurrentEnemy;
    bool staleNonEnemyTarget;
    bool roleAllowed;
    bool usePlayerCoverCheck;
    bool targetIsPlayer;
    bool hasPlayerCoverScore;
    bool pathPassesNear;
    bool groupFastTravel;
    bool coverHasDynamicOwner;
    float playerStandingScore;
    float playerFirePointScore;
    float deferredVisibilityThreshold;
    float targetTravelDistanceThreshold;
    float minimumTargetDistance;
    float idealTargetDistance;
    float minimumTargetTravelTime;
    float maxEnemyCoverDistance;
    int targetToCoverTravelTime;
    float coverVisibilityRatio;
    float coverAngle;
    float historyScore;
    float groupPenaltyDistance;
    int groupMemberCount;
    idTakeCoverGroupMember groupMembers[64];
};

class idCoverQueryTakeCover : public idCoverQuery {
public:
    using idCoverQuery::idCoverQuery;
    ~idCoverQueryTakeCover() override = default;

protected:
    float InternalScoreCover(const coverCache_t& cached) override;
};

bool Tungsten_GetTakeCoverRuntime(const idCoverQueryTakeCover& query,
    const idAICover& cover, const idCoverQuery::coverCache_t& cached,
    const idCoverQuery::coverTarget_t& target,
    idTakeCoverRuntime& runtime);
