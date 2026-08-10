#pragma once

#include "aicover.h"
#include "../aaspositionmgr.h"
#include "idlib/containers/list.h"

class idAI2;

class idCoverQuery {
public:
    struct coverTarget_t {
        coverTarget_t();

        idSpawnId spawnId;
        idVec3 origin;
        idVec3 eyePoint;
        idAASPosition aiPos;
        idAASPosition vcPos;
        int confirmedTime;
    };

    struct coverCache_t {
        int index;
        idAASPosition aiPos;
        idAASPosition vcPos;
        int vcAreaNum;
        idVec3 delta;
        float linearDistance;
        float travelTime;
        float score;
    };

    idCoverQuery(idAI2* ai, const idAICover& exclude, int flags);
    virtual ~idCoverQuery() = default;

    bool Execute(const idList<coverTarget_t, 5>& targets,
        const idVec3& referencePoint, idAICover& bestCover, bool inAvoid);

    static const idVec3 INVALID_ORIGIN;
    static const float MAX_COVER_ARC_ACOS_DEGREES;

protected:
    virtual void InternalPreScore() {}
    virtual void InternalSetupTarget(const coverTarget_t&) {}
    virtual float InternalScoreCover(const coverCache_t&) { return 0.0f; }

    void PreScore();
    void SetupTarget(const coverTarget_t& newTarget);
    float ScoreCover(const coverCache_t& cached);
    void FindRelevantCover();

    float DebugFailed(const char* message, const idVec3& origin,
        int minLevel) const;
    float DebugFailedTarget(const char* message, const idVec3& origin,
        const idVec3& targetOrigin, int minLevel) const;
    float DebugSucceeded(float score, float targetScore, float aiScore,
        float angleScore, float groupScore, float enemyVisibilityScore,
        float aiVisibilityScore, float miscScore,
        const idVec3& coverOrigin, const idVec3& targetOrigin,
        int minLevel) const;
    float DebugSucceededAvoid(float score, float angleScore, float angle,
        float travelScore, float proximityScore, float awayScore,
        float velocityScore, const idVec3& coverOrigin,
        const idVec3& targetOrigin, int minLevel) const;

public:
    idAI2* ai;
    coverTarget_t target;
    idAICover excludeCover;
    int debugLevel;
    int queryFlags;
    int minTravelTimeIndex;
    float minTravelTime;
    int maxTravelTimeIndex;
    float maxTravelTime;
    float travelTimeRange;
    idAASPosition aiaiPos;
    idAASPosition aivcPos;
    idList<coverCache_t, 5> relevantCover;
};

// Engine-owned state used by the recovered query orchestration.
int Tungsten_GetCoverQueryDebugLevel(const idAI2& ai);
bool Tungsten_CoverQueryHasCover(const idAI2& ai,
    const idVec3& referencePoint, int currentTime, bool inAvoid);
int Tungsten_GetCoverQueryGameMilliseconds();
const idAAS2* Tungsten_GetCoverQueryAAS(const idAI2& ai);
const idAAS2* Tungsten_GetCoverQueryVisibilityAAS();
idVec3 Tungsten_GetCoverQueryAIOrigin(const idAI2& ai);
bool Tungsten_GetCoverQueryTargetState(const idAI2& ai, int spawnId,
    idVec3& origin, idVec3& eyePoint, int& confirmedTime);
int Tungsten_GetCoverQueryKnownCoverCount(const idAI2& ai);
const idAICover* Tungsten_GetCoverQueryKnownCover(
    const idAI2& ai, int index);
bool Tungsten_CoverQueryReserverUsesCover(
    const idEntity& reserver, const idAICover& cover);
void Tungsten_CoverQueryReservationWarning(int coverIndex);
bool Tungsten_CoverQueryHasOrientation(
    const idAI2& ai, const idAICover& cover);
bool Tungsten_IsCoverQueryBlocked(
    const idAI2& ai, const idAICover& cover);
void Tungsten_DebugCoverQueryFailure(const idCoverQuery& query,
    const char* message, const idVec3& origin,
    const idVec3* targetOrigin, int minLevel);
void Tungsten_DebugCoverQuerySuccess(const idCoverQuery& query,
    const float* components, int componentCount,
    const idVec3& coverOrigin, const idVec3& targetOrigin, int minLevel);
void Tungsten_DebugCoverQueryResult(const idCoverQuery& query,
    const idAICover& cover, float score, bool selected);
