#include "aianimwebtransitions.h"

#include <algorithm>
#include <cmath>
#include <cfloat>

namespace {

constexpr float kTraceClearFraction = 0.99000001f;
constexpr float kCosThirtyDegrees = 0.86602539f;
constexpr float kCosFortyFiveDegrees = 0.70710677f;
constexpr float kDepartureAngleInfluence = 3.0f;
constexpr float kTurnAngleInfluence = 500.0f;
constexpr float kArrivalAngleInfluence = 150.0f;
constexpr float kDirectionEpsilon = 1.0e-20f;

idVec3 TransformLocal(const idMat3& axis, const idVec3& local) {
    // idTech matrices store basis vectors, so a local vector is expanded by
    // columns here.  This is the component order materialized in the dump.
    return idVec3(
        axis[0].x * local.x + axis[1].x * local.y + axis[2].x * local.z,
        axis[0].y * local.x + axis[1].y * local.y + axis[2].y * local.z,
        axis[0].z * local.x + axis[1].z * local.y + axis[2].z * local.z);
}

float DistanceSqrXY(const idVec3& lhs, const idVec3& rhs) {
    const float x = lhs.x - rhs.x;
    const float y = lhs.y - rhs.y;
    return x * x + y * y;
}

float DistanceXY(const idVec3& lhs, const idVec3& rhs) {
    return std::sqrt(DistanceSqrXY(lhs, rhs));
}

float Distance(const idVec3& lhs, const idVec3& rhs) {
    return (lhs - rhs).Length();
}

idVec3 Normalized(idVec3 vector) {
    vector.NormalizeFast();
    return vector;
}

idVec3 NormalizedXY(idVec3 vector) {
    vector.z = 0.0f;
    vector.NormalizeFast();
    return vector;
}

idVec3 ClosestPointOnSegment(const idVec3& point,
        const idVec3& start, const idVec3& end) {
    const idVec3 segment = end - start;
    const float lengthSqr = segment.LengthSqr();
    if (lengthSqr <= kDirectionEpsilon) {
        return start;
    }
    const float scale = (std::max)(0.0f, (std::min)(1.0f,
        (point - start).Dot(segment) / lengthSqr));
    return start + segment * scale;
}

idMat3 InverseOrIdentity(idMat3 matrix) {
    if (!matrix.InverseSelf()) {
        return idMat3(1.0f);
    }
    return matrix;
}

void StoreResult(const idAnimWebTransitions::transitionData_t& transition,
        const idVec3& startOrigin, const idVec3& destOrigin,
        idAnimWebTransitions::transitionQueryResult_t& out) {
    // The dump's two five-dword copies resolve to dst -> dst and src -> via.
    out.dst = transition.dst;
    out.via = transition.src;
    out.startOrigin = startOrigin;
    out.destOrigin = destOrigin;
    out.selectionIndex = transition.selectionIndex;
    out.approximatePathDistance = transition.approximatePathDistance;
    out.anim = transition.anim;
}

bool FlagsAccepted(const idAnimWebTransitions::transitionData_t& transition,
        const idAnimWebTransitions::transitionQueryValidation_t& validation) {
    return (transition.flags & ~validation.allowedFlags) == 0
        && (transition.flags & validation.requiredFlags)
            == validation.requiredFlags;
}

float SuggestedFlagScale(
        const idAnimWebTransitions::transitionData_t& transition,
        const idAnimWebTransitions::transitionQueryValidation_t& validation) {
    return validation.suggestedFlags != 0
        && (transition.flags & validation.suggestedFlags)
            != validation.suggestedFlags ? 1.1f : 1.0f;
}

void ResetNavTraces(idAnimWebTransitions::transitionData_t& transition) {
    for (auto& trace : transition.navTraces) {
        trace = idAnimWebTransitions::navTraceData_t();
    }
}

} // namespace

// Retail symbol: ??0navTraceData_t@idAnimWebTransitions@@QAA@XZ
idAnimWebTransitions::navTraceData_t::navTraceData_t()
    : start(0.0f, 0.0f, 0.0f)
    , stop(0.0f, 0.0f, 0.0f)
    , fraction(-1.0f)
    , num{-1, -1}
    , numIndex(0) {
}

idAnimWebTransitions::transitionData_t::transitionData_t()
    : deltaOrigin(0.0f, 0.0f, 0.0f)
    , deltaAxis(1.0f)
    , deltaCorrectEndDistanceSqr(0.0f)
    , apex(0.0f, 0.0f, 0.0f)
    , deltaCorrectEndTranslation(0.0f, 0.0f, 0.0f)
    , deltaCorrectEndAxis(1.0f)
    , deltaCorrectGoalTranslation(0.0f, 0.0f, 0.0f)
    , deltaCorrectGoalAxis(1.0f)
    , hasApex(false)
    , flags(0)
    , approximatePathDistance(0.0f)
    , src()
    , via()
    , dst()
    , anim(nullptr)
    , navTraces()
    , selectionIndex(-1) {
}

// Retail header symbol: ??0transitionQueryResult_t@idAnimWebTransitions@@QAA@XZ
idAnimWebTransitions::transitionQueryResult_t::transitionQueryResult_t()
    : dst()
    , via()
    , startOrigin(0.0f, 0.0f, 0.0f)
    , destOrigin(0.0f, 0.0f, 0.0f)
    , selectionIndex(-1)
    , approximatePathDistance(0.0f)
    , anim(nullptr) {
}

// Retail header symbol:
// ??0transitionQueryValidation_t@idAnimWebTransitions@@QAA@XZ
idAnimWebTransitions::transitionQueryValidation_t::
transitionQueryValidation_t()
    : selectType(CHOOSE_ANGLE_DISTANCE_ERROR)
    , requiredSourceAlignAngleDot(kCosThirtyDegrees)
    , requiredMoveAlignAngleDot(kCosFortyFiveDegrees)
    , movementDistanceFudge(0.0f)
    , usePathDirectionForMoveAlign(false)
    , usePathDirectionForSourceAlign(false)
    , maxMoveDistanceMultiplier(1.0f)
    , allowedFlags(-24577)
    , requiredFlags(0)
    , suggestedFlags(0)
    , checkMaxMovementDistance(true)
    , requiredApexAlignAngleDot(kCosFortyFiveDegrees)
    , usePathDirectionForApexAlign(false)
    , checkAnimTooShort(true)
    , navProbeAnimTranslation(false)
    , navProbeAnimApex(true)
    , navProbeToPathPosition(false)
    , allowRejections(true) {
}

// Retail header symbol: ??0transitionCache_t@idAnimWebTransitions@@QAA@XZ
idAnimWebTransitions::transitionCache_t::transitionCache_t()
    : srcState()
    , dstState()
    , lastCheckFlags(0)
    , transitions(0)
    , maximumDeltaOriginDistanceSqr(0.0f)
    , maximumPathDistance(0.0f)
    , minimumDeltaOriginDistanceSqr(0.0f)
    , nodeIndex() {
    transitions.Clear();
}

// Retail header symbol: ??0transitionQueryParms_t@idAnimWebTransitions@@QAA@XZ
idAnimWebTransitions::transitionQueryParms_t::transitionQueryParms_t()
    : sourceOrigin1(0.0f, 0.0f, 0.0f)
    , sourceOrigin2(0.0f, 0.0f, 0.0f)
    , sourceAxis(1.0f)
    , destinationOrigin(0.0f, 0.0f, 0.0f)
    , destinationAxis(1.0f)
    , turnPoint(0.0f, 0.0f, 0.0f)
    , totalPathDistance(0.0f)
    , pathDistanceAlongAxis(0.0f)
    , debugDrawTime(1)
    , cachedCorners() {
}

idAnimWebTransitions::defaultStepTransitionValidation_t::
defaultStepTransitionValidation_t() {
    selectType = CHOOSE_ANGLE_DISTANCE_ERROR;
    requiredSourceAlignAngleDot = -0.000000050005699f;
    requiredMoveAlignAngleDot = -1.0f;
    movementDistanceFudge = 20.0f;
    allowedFlags = -1;
    requiredApexAlignAngleDot = -1.0f;
}

idAnimWebTransitions::defaultArrivalTransitionValidation_t::
defaultArrivalTransitionValidation_t() {
    selectType = CHOOSE_CLOSEST_TO_PATH_RELATIVE;
    requiredSourceAlignAngleDot = -0.000000050005699f;
    requiredMoveAlignAngleDot = -0.000000050005699f;
    movementDistanceFudge = 5.0f;
    usePathDirectionForMoveAlign = true;
    usePathDirectionForSourceAlign = true;
    allowedFlags = -1;
    requiredApexAlignAngleDot = -0.000000050005699f;
    usePathDirectionForApexAlign = true;
}

idAnimWebTransitions::defaultFlightTransitionValidation_t::
defaultFlightTransitionValidation_t() {
    selectType = CHOOSE_CLOSEST_TO_DESTINATION;
    requiredSourceAlignAngleDot = -1.0f;
    requiredMoveAlignAngleDot = -1.0f;
    movementDistanceFudge = 5.0f;
    maxMoveDistanceMultiplier = 2.0f;
    allowedFlags = -1;
    checkMaxMovementDistance = false;
    requiredApexAlignAngleDot = -1.0f;
}

idAnimWebTransitions::defaultSoftStopTransitionValidation_t::
defaultSoftStopTransitionValidation_t() {
    requiredSourceAlignAngleDot = -1.0f;
    requiredMoveAlignAngleDot = -1.0f;
    movementDistanceFudge = 5.0f;
    allowedFlags = -1;
    checkMaxMovementDistance = false;
    requiredApexAlignAngleDot = -1.0f;
}

idAnimWebTransitions::defaultDepartureTransitionValidation_t::
defaultDepartureTransitionValidation_t() {
    selectType = CHOOSE_CLOSEST_TO_PATH_RELATIVE;
    requiredSourceAlignAngleDot = kCosThirtyDegrees;
    requiredMoveAlignAngleDot = kCosFortyFiveDegrees;
    movementDistanceFudge = 5.0f;
    usePathDirectionForMoveAlign = true;
    allowedFlags = -1;
    requiredApexAlignAngleDot = kCosFortyFiveDegrees;
    usePathDirectionForApexAlign = true;
    navProbeToPathPosition = true;
}

const idAnimWebTransitions::defaultArrivalTransitionValidation_t
    idAnimWebTransitions::defaultArrivalTransitionValidation;
const idAnimWebTransitions::defaultStepTransitionValidation_t
    idAnimWebTransitions::defaultStepTransitionValidation;
const idAnimWebTransitions::defaultFlightTransitionValidation_t
    idAnimWebTransitions::defaultFlightTransitionValidation;
const idAnimWebTransitions::defaultSoftStopTransitionValidation_t
    idAnimWebTransitions::defaultSoftStopTransitionValidation;
const idAnimWebTransitions::defaultDepartureTransitionValidation_t
    idAnimWebTransitions::defaultDepartureTransitionValidation;

// Retail symbol:
// ?GetDistanceToPath@idAnimWebTransitions@@SAMABV?$idStaticList@VidVec3@@$0BP@@@ABVidVec3@@1AAV3@2@Z
// EA: 0x82A63418, RVA: 0x00A63418
float idAnimWebTransitions::GetDistanceToPath(
        const idStaticList<idVec3, 31>& path,
        const idVec3& startOrigin, const idVec3& testPoint,
        idVec3& outPositionOnPath, idVec3& outDirectionOnPath) {
    if (path.Num() == 0) {
        outPositionOnPath = startOrigin;
        outDirectionOnPath.Set(0.0f, 0.0f, 1.0f);
        return Distance(testPoint, startOrigin);
    }

    idVec3 segmentStart = startOrigin;
    idVec3 segmentEnd = path[0];
    idVec3 bestPoint = ClosestPointOnSegment(
        testPoint, segmentStart, segmentEnd);
    idVec3 bestDirection = segmentEnd - segmentStart;
    float bestDistanceSqr = (testPoint - bestPoint).LengthSqr();

    for (int index = 1; index < path.Num(); ++index) {
        segmentStart = segmentEnd;
        segmentEnd = path[index];
        const idVec3 point = ClosestPointOnSegment(
            testPoint, segmentStart, segmentEnd);
        // Retail compares later segments in XY only, even though the first
        // segment was seeded with a full three-dimensional distance.
        const float distanceSqr = DistanceSqrXY(testPoint, point);
        if (distanceSqr < bestDistanceSqr) {
            bestDistanceSqr = distanceSqr;
            bestPoint = point;
            bestDirection = segmentEnd - segmentStart;
        }
    }

    outPositionOnPath = bestPoint;
    outDirectionOnPath = Normalized(bestDirection);
    return std::sqrt(bestDistanceSqr);
}

// Retail symbol:
// ?GetPathPositionAndDirection@idAnimWebTransitions@@SAHABV?$idStaticList@VidVec3@@$0BP@@@MABVidVec3@@1AAV3@2@Z
// EA: 0x82A636E0, RVA: 0x00A636E0
int idAnimWebTransitions::GetPathPositionAndDirection(
        const idStaticList<idVec3, 31>& path, float distanceAhead,
        const idVec3& startDirection, const idVec3& startPosition,
        idVec3& outPosition, idVec3& outDirection) {
    if (path.Num() == 0) {
        outPosition = startPosition;
        outDirection = startDirection;
        return -1;
    }

    idVec3 position = startPosition;
    idVec3 direction = startDirection;
    for (int index = 0; index < path.Num(); ++index) {
        idVec3 segmentDirection = path[index] - position;
        const float segmentLength = segmentDirection.NormalizeFast();
        if (distanceAhead <= segmentLength) {
            outPosition = position + segmentDirection * distanceAhead;
            outDirection = segmentDirection;
            return 0;
        }
        distanceAhead -= segmentLength;
        position = path[index];
        direction = segmentDirection;
    }

    outPosition = position;
    outDirection = direction;
    return 0;
}

// Retail symbol: ?Clear@transitionCache_t@idAnimWebTransitions@@QAAXXZ
// EA: 0x82A638D8, RVA: 0x00A638D8
void idAnimWebTransitions::transitionCache_t::Clear() {
    srcState.Clear();
    dstState.Clear();
    transitions.Clear();
    nodeIndex.Invalidate();
}

// Retail symbol:
// ?CleanupNavTraces@idAnimWebTransitions@@SAXPAVidAI2@@AAUtransitionCache_t@1@@Z
// EA: 0x82A63920, RVA: 0x00A63920
void idAnimWebTransitions::CleanupNavTraces(
        idAI2* const ai, transitionCache_t& cache) {
    if (ai == nullptr) {
        return;
    }
    for (int transitionIndex = 0;
            transitionIndex < cache.transitions.Num(); ++transitionIndex) {
        for (auto& trace : cache.transitions[transitionIndex].navTraces) {
            for (const int queryNumber : trace.num) {
                if (queryNumber >= 0) {
                    Tungsten_ReleaseAIAnimWebNavTrace(*ai, queryNumber);
                }
            }
        }
    }
}

// Retail symbol:
// ?FindDepartureTransition@idAnimWebTransitions@@SA_NPBVidAI2@@ABUtransitionQueryValidation_t@1@AAUtransitionCache_t@1@ABUtransitionQueryParms_t@1@AAUtransitionQueryResult_t@1@AA_N@Z
// EA: 0x82A63A70, RVA: 0x00A63A70
bool idAnimWebTransitions::FindDepartureTransition(const idAI2* const ai,
        const transitionQueryValidation_t& validation,
        transitionCache_t& cache, const transitionQueryParms_t& parms,
        transitionQueryResult_t& out,
        bool& wasRejectedBasedOnDistanceAlone) {
    wasRejectedBasedOnDistanceAlone = false;
    if (ai == nullptr || cache.transitions.Num() == 0) {
        return false;
    }

    int bestIndex = -1;
    float bestScore = FLT_MAX;
    idVec3 bestDestination;

    for (int index = 0; index < cache.transitions.Num(); ++index) {
        transitionData_t& transition = cache.transitions[index];
        if (!FlagsAccepted(transition, validation)) {
            continue;
        }

        const idVec3 goalOrigin = parms.sourceOrigin1
            + TransformLocal(parms.sourceAxis,
                transition.deltaCorrectGoalTranslation);
        const idMat3 goalAxis = parms.sourceAxis
            * InverseOrIdentity(transition.deltaCorrectGoalAxis);
        const idVec3 goalDirection = goalAxis[0];
        const float planarMovementDistance =
            DistanceXY(parms.sourceOrigin1, goalOrigin);

        idVec3 pathPosition;
        idVec3 pathDirection;
        if (validation.usePathDirectionForMoveAlign) {
            GetDistanceToPath(parms.cachedCorners, parms.sourceOrigin1,
                goalOrigin, pathPosition, pathDirection);
        } else {
            GetPathPositionAndDirection(parms.cachedCorners,
                planarMovementDistance, parms.sourceAxis[0],
                parms.sourceOrigin1, pathPosition, pathDirection);
        }

        const float moveAlignment = goalDirection.Dot(pathDirection);
        const bool mayReject = validation.allowRejections
            && (transition.src.GetCustomFlags() & 0x10) == 0;
        if (mayReject && validation.requiredMoveAlignAngleDot > -1.0f
            && moveAlignment < validation.requiredMoveAlignAngleDot) {
            continue;
        }
        if (mayReject
            && transition.approximatePathDistance > parms.totalPathDistance) {
            wasRejectedBasedOnDistanceAlone = true;
            continue;
        }

        idVec3 apexOrigin = goalOrigin;
        if (transition.hasApex) {
            apexOrigin = parms.sourceOrigin1
                + TransformLocal(parms.sourceAxis, transition.apex);
        }
        if (mayReject && validation.requiredApexAlignAngleDot > -1.0f) {
            const idVec3 apexDirection = Normalized(
                apexOrigin - parms.sourceOrigin1);
            float apexAlignment;
            if (validation.usePathDirectionForApexAlign) {
                idVec3 closest;
                idVec3 unusedDirection;
                GetDistanceToPath(parms.cachedCorners,
                    parms.sourceOrigin1, apexOrigin,
                    closest, unusedDirection);
                apexAlignment = apexDirection.Dot(Normalized(
                    closest - parms.sourceOrigin1));
            } else {
                apexAlignment = apexDirection.Dot(parms.sourceAxis[0]);
            }
            if (apexAlignment < validation.requiredApexAlignAngleDot) {
                continue;
            }
        }

        if (mayReject && validation.navProbeAnimApex
            && ((transition.hasApex
                    && transition.navTraces[0].fraction
                        <= kTraceClearFraction)
                || transition.navTraces[1].fraction
                    <= kTraceClearFraction)) {
            continue;
        }
        if (mayReject && validation.navProbeToPathPosition
            && transition.navTraces[2].fraction <= kTraceClearFraction) {
            continue;
        }

        const float suggestionScale =
            SuggestedFlagScale(transition, validation);
        float score = 0.0f;
        if (validation.selectType ==
                transitionQueryValidation_t::CHOOSE_CLOSEST_ANGLE_START) {
            score = (1.0f - moveAlignment) + suggestionScale;
        } else if (validation.selectType ==
                transitionQueryValidation_t::
                    CHOOSE_CLOSEST_TO_PATH_RELATIVE) {
            const float distanceToPath = GetDistanceToPath(
                parms.cachedCorners, parms.sourceOrigin1,
                goalOrigin, pathPosition, pathDirection);
            const float apexToGoal = transition.hasApex
                ? Distance(apexOrigin, goalOrigin) : 0.0f;
            const float transitionDistance =
                Distance(parms.sourceOrigin1, apexOrigin) + apexToGoal;
            const float relativeDistance = planarMovementDistance > 0.0f
                ? distanceToPath / planarMovementDistance : distanceToPath;
            score = (1.0f - transitionDistance * 0.0015f)
                * (((1.0f - moveAlignment) * kDepartureAngleInfluence)
                    * suggestionScale + relativeDistance);
        }

        if (score < bestScore) {
            bestScore = score;
            bestIndex = index;
            bestDestination = goalOrigin;
        }
    }

    if (bestIndex < 0) {
        return false;
    }
    StoreResult(cache.transitions[bestIndex], parms.sourceOrigin1,
        bestDestination, out);
    return true;
}

// Retail symbol:
// ?FindTurnTransition@idAnimWebTransitions@@SA_NPBVidAI2@@ABUtransitionQueryValidation_t@1@AAUtransitionCache_t@1@ABUtransitionQueryParms_t@1@AAUtransitionQueryResult_t@1@@Z
// EA: 0x82A64C50, RVA: 0x00A64C50
bool idAnimWebTransitions::FindTurnTransition(const idAI2* const ai,
        const transitionQueryValidation_t& validation,
        transitionCache_t& cache, const transitionQueryParms_t& parms,
        transitionQueryResult_t& out) {
    if (ai == nullptr || cache.transitions.Num() == 0) {
        return false;
    }

    int bestIndex = -1;
    float bestScore = FLT_MAX;
    idVec3 bestDestination;

    for (int index = 0; index < cache.transitions.Num(); ++index) {
        transitionData_t& transition = cache.transitions[index];
        if (!FlagsAccepted(transition, validation)) {
            continue;
        }

        const idVec3 destination = parms.sourceOrigin1
            + TransformLocal(parms.sourceAxis, transition.deltaOrigin);
        const idMat3 endAxis = parms.sourceAxis
            * transition.deltaAxis.Transpose();
        const idVec3 sourceForward = NormalizedXY(parms.sourceAxis[0]);
        const idVec3 endForward = NormalizedXY(endAxis[0]);
        const idVec3 planeNormal(-endForward.y, endForward.x, 0.0f);
        const float denominator = sourceForward.Dot(planeNormal);
        if (std::fabs(denominator) <= kDirectionEpsilon) {
            continue;
        }

        const float intersectionScale =
            (destination - parms.sourceOrigin1).Dot(planeNormal)
                / denominator;
        const idVec3 intersection = parms.sourceOrigin1
            + sourceForward * intersectionScale;
        const float turnPointDistance =
            DistanceXY(parms.sourceOrigin1, parms.turnPoint);
        if (turnPointDistance > intersectionScale
            || turnPointDistance < intersectionScale - 100.0f) {
            continue;
        }

        const float transitionPathDistance =
            DistanceXY(parms.sourceOrigin1, intersection)
            + DistanceXY(destination, intersection);
        idVec3 pathPosition;
        idVec3 pathDirection;
        GetPathPositionAndDirection(parms.cachedCorners,
            transitionPathDistance, parms.sourceAxis[0],
            parms.sourceOrigin1, pathPosition, pathDirection);
        pathDirection = NormalizedXY(pathDirection);
        const float alignment = pathDirection.Dot(endForward);
        if (alignment < kCosThirtyDegrees
            || transition.navTraces[0].fraction <= kTraceClearFraction) {
            continue;
        }

        const float suggestionPenalty = validation.suggestedFlags != 0
            && (transition.flags & validation.suggestedFlags)
                != validation.suggestedFlags ? 0.1f : 0.0f;
        const float score =
            (1.0f - alignment + suggestionPenalty)
                * kTurnAngleInfluence
            + DistanceXY(parms.turnPoint, intersection);
        if (score < bestScore) {
            bestScore = score;
            bestIndex = index;
            bestDestination = destination;
        }
    }

    if (bestIndex < 0) {
        return false;
    }
    StoreResult(cache.transitions[bestIndex], parms.sourceOrigin1,
        bestDestination, out);
    return true;
}

// Retail symbol:
// ?FindCommonArrivalTransition@idAnimWebTransitions@@SA_NPBVidAI2@@ABUtransitionQueryValidation_t@1@AAUtransitionCache_t@1@ABUtransitionQueryParms_t@1@AAUtransitionQueryResult_t@1@@Z
// EA: 0x82A65980, RVA: 0x00A65980
bool idAnimWebTransitions::FindCommonArrivalTransition(
        const idAI2* const ai,
        const transitionQueryValidation_t& validation,
        transitionCache_t& cache, const transitionQueryParms_t& parms,
        transitionQueryResult_t& out) {
    if (ai == nullptr || cache.transitions.Num() == 0) {
        return false;
    }

    const idVec3 sourceToDestination =
        parms.destinationOrigin - parms.sourceOrigin1;
    const float availableDistance = (std::max)(0.0f,
        sourceToDestination.Length() - validation.movementDistanceFudge);
    const float availableDistanceSqr =
        availableDistance * availableDistance;
    const idVec3 movementDirection = availableDistance > kDirectionEpsilon
        ? sourceToDestination * (1.0f / availableDistance)
        : parms.sourceAxis[0];

    int bestIndex = -1;
    int bestAlignmentClass = 0;
    int requiredAlignmentClass = 0;
    float bestScore = FLT_MAX;
    idVec3 bestStart;

    for (int index = 0; index < cache.transitions.Num(); ++index) {
        transitionData_t& transition = cache.transitions[index];
        if (!FlagsAccepted(transition, validation)) {
            continue;
        }
        if (validation.checkMaxMovementDistance
            && validation.allowRejections
            && transition.deltaCorrectEndDistanceSqr
                > availableDistanceSqr) {
            continue;
        }

        const idMat3 transitionAxis =
            parms.destinationAxis * transition.deltaAxis;
        const idVec3 startOrigin = parms.destinationOrigin
            + TransformLocal(transitionAxis, -transition.deltaOrigin);

        idVec3 pathPosition = startOrigin;
        idVec3 pathDirection = movementDirection;
        float distanceToPath = 0.0f;
        if (validation.usePathDirectionForMoveAlign
            || validation.usePathDirectionForSourceAlign
            || validation.usePathDirectionForApexAlign) {
            distanceToPath = GetDistanceToPath(parms.cachedCorners,
                parms.sourceOrigin1, startOrigin,
                pathPosition, pathDirection);
        }

        const idVec3 sourceAlignmentDirection =
            validation.usePathDirectionForSourceAlign
                ? pathDirection : movementDirection;
        const float sourceAlignment =
            transitionAxis[0].Dot(sourceAlignmentDirection);
        bool alignmentClass = false;
        if (validation.requiredSourceAlignAngleDot > -1.0f
            && validation.allowRejections) {
            alignmentClass = sourceAlignment > kCosThirtyDegrees;
            if (sourceAlignment < validation.requiredSourceAlignAngleDot) {
                continue;
            }
        }

        idVec3 apexOrigin = parms.destinationOrigin;
        if (transition.hasApex) {
            apexOrigin = startOrigin
                + TransformLocal(transitionAxis, transition.apex);
        }
        float movementAlignment = sourceAlignment;
        if (validation.requiredMoveAlignAngleDot > -1.0f
            && validation.allowRejections) {
            if (transition.deltaOrigin.LengthSqr() > 1.0f) {
                const idVec3 animationDirection =
                    Normalized(apexOrigin - startOrigin);
                movementAlignment = animationDirection.Dot(
                    validation.usePathDirectionForMoveAlign
                        ? pathDirection : movementDirection);
            }
            alignmentClass = alignmentClass
                && movementAlignment > kCosThirtyDegrees;
            if (movementAlignment < validation.requiredMoveAlignAngleDot) {
                continue;
            }
        }

        if (validation.requiredApexAlignAngleDot > -1.0f
            && validation.allowRejections) {
            idVec3 apexDirection;
            idVec3 alignmentDirection;
            if (validation.usePathDirectionForApexAlign) {
                apexDirection = Normalized(apexOrigin - pathPosition);
                alignmentDirection = pathDirection;
            } else {
                apexDirection = Normalized(
                    apexOrigin - parms.sourceOrigin1);
                alignmentDirection = movementDirection;
            }
            if (apexDirection.Dot(alignmentDirection)
                    < validation.requiredApexAlignAngleDot) {
                continue;
            }
        }

        if (validation.navProbeAnimApex
            && ((transition.hasApex
                    && transition.navTraces[0].fraction
                        <= kTraceClearFraction)
                || transition.navTraces[1].fraction
                    <= kTraceClearFraction)) {
            continue;
        }
        if (validation.checkAnimTooShort && validation.allowRejections) {
            requiredAlignmentClass |= alignmentClass ? 1 : 0;
            if (availableDistanceSqr > transition.deltaOrigin.LengthSqr()) {
                continue;
            }
        }
        if (validation.navProbeAnimTranslation
            && !validation.navProbeAnimApex
            && validation.allowRejections
            && transition.navTraces[2].fraction <= kTraceClearFraction) {
            continue;
        }

        float score = 0.0f;
        switch (validation.selectType) {
        case transitionQueryValidation_t::CHOOSE_CLOSEST_TO_DESTINATION: {
            const idVec3 predictedDestination = parms.sourceOrigin1
                + TransformLocal(parms.sourceAxis, transition.deltaOrigin);
            score = (parms.destinationOrigin
                - predictedDestination).LengthSqr();
            break;
        }
        case transitionQueryValidation_t::CHOOSE_CLOSEST_ANGLE_START:
            score = 1.0f - sourceAlignment;
            break;
        case transitionQueryValidation_t::CHOOSE_CLOSEST_TO_PATH_RELATIVE: {
            const float apexToDestination = transition.hasApex
                ? Distance(apexOrigin, parms.destinationOrigin) : 0.0f;
            const float transitionDistance =
                Distance(startOrigin, apexOrigin) + apexToDestination;
            score = transitionDistance > kDirectionEpsilon
                ? (1.0f - transitionDistance * 0.001f)
                    * (distanceToPath / transitionDistance)
                : distanceToPath;
            break;
        }
        case transitionQueryValidation_t::CHOOSE_ANGLE_DISTANCE_ERROR:
        case transitionQueryValidation_t::CHOOSE_CLOSEST_TO_SEGMENT:
        default:
            score = (1.0f - movementAlignment)
                    * kArrivalAngleInfluence
                + DistanceXY(parms.sourceOrigin1, startOrigin);
            break;
        }
        score *= SuggestedFlagScale(transition, validation);

        const int candidateAlignmentClass = alignmentClass ? 1 : 0;
        if (score < bestScore
            && (!validation.checkAnimTooShort
                || candidateAlignmentClass == requiredAlignmentClass)) {
            bestScore = score;
            bestIndex = index;
            bestStart = startOrigin;
            bestAlignmentClass = candidateAlignmentClass;
        }
    }

    if (bestIndex < 0
        || (validation.checkAnimTooShort
            && bestAlignmentClass != requiredAlignmentClass)) {
        return false;
    }
    StoreResult(cache.transitions[bestIndex], bestStart,
        parms.destinationOrigin, out);
    return true;
}

// Retail symbol:
// ?ResolveAndSubmitNavTrace@idAnimWebTransitions@@SA?AW4navTraceResult_t@1@PAVidAI2@@AAUnavTraceData_t@1@@Z
// EA: 0x82A66E20, RVA: 0x00A66E20
idAnimWebTransitions::navTraceResult_t
idAnimWebTransitions::ResolveAndSubmitNavTrace(
        idAI2* const ai, navTraceData_t& trace) {
    if (ai == nullptr) {
        return TRACE_WAITING;
    }

    bool resolved = false;
    int traceIndex = trace.numIndex;
    for (int offset = 0; offset < 2; ++offset) {
        traceIndex = (trace.numIndex + offset) % 2;
        const int queryNumber = trace.num[traceIndex];
        if (queryNumber < 0) {
            continue;
        }
        trace.fraction = Tungsten_GetAIAnimWebNavTraceResult(
            *ai, queryNumber);
        if (trace.fraction > -1.0f) {
            resolved = true;
            Tungsten_ReleaseAIAnimWebNavTrace(*ai, queryNumber);
            break;
        }
    }

    trace.numIndex = traceIndex;
    trace.num[trace.numIndex] = Tungsten_AddAIAnimWebNavTrace(
        *ai, trace.start, trace.stop);
    if (!resolved) {
        return TRACE_WAITING;
    }
    return trace.fraction == 1.0f ? TRACE_CLEAR : TRACE_BLOCKED;
}

// Retail symbol:
// ?PrepareDepartureTraces@idAnimWebTransitions@@SA_NPAVidAI2@@ABUtransitionQueryValidation_t@1@AAUtransitionCache_t@1@ABUtransitionQueryParms_t@1@@Z
// EA: 0x82A66F30, RVA: 0x00A66F30
bool idAnimWebTransitions::PrepareDepartureTraces(idAI2* const ai,
        const transitionQueryValidation_t& validation,
        transitionCache_t& cache, const transitionQueryParms_t& parms) {
    if (cache.transitions.Num() == 0) {
        return false;
    }

    bool allResolved = true;
    for (int index = 0; index < cache.transitions.Num(); ++index) {
        transitionData_t& transition = cache.transitions[index];
        const idVec3 goalOrigin = parms.sourceOrigin1
            + TransformLocal(parms.sourceAxis,
                transition.deltaCorrectGoalTranslation);
        const idMat3 goalAxis = parms.sourceAxis
            * InverseOrIdentity(transition.deltaCorrectGoalAxis);
        const float movementDistance =
            DistanceXY(parms.sourceOrigin1, goalOrigin);
        idVec3 pathPosition;
        idVec3 pathDirection;
        if (validation.usePathDirectionForMoveAlign) {
            GetDistanceToPath(parms.cachedCorners, parms.sourceOrigin1,
                goalOrigin, pathPosition, pathDirection);
        } else {
            GetPathPositionAndDirection(parms.cachedCorners,
                movementDistance, goalAxis[0], parms.sourceOrigin1,
                pathPosition, pathDirection);
        }

        const idVec3 apexOrigin = transition.hasApex
            ? parms.sourceOrigin1
                + TransformLocal(parms.sourceAxis, transition.apex)
            : goalOrigin;
        if (validation.navProbeAnimApex) {
            if (transition.hasApex) {
                transition.navTraces[0].start = goalOrigin;
                transition.navTraces[0].stop = apexOrigin;
                if (ResolveAndSubmitNavTrace(ai,
                        transition.navTraces[0]) == TRACE_WAITING) {
                    allResolved = false;
                }
            }
            transition.navTraces[1].start = apexOrigin;
            transition.navTraces[1].stop = parms.sourceOrigin1;
            if (ResolveAndSubmitNavTrace(ai,
                    transition.navTraces[1]) == TRACE_WAITING) {
                allResolved = false;
            }
        }
        if (validation.navProbeToPathPosition) {
            transition.navTraces[2].start = goalOrigin;
            transition.navTraces[2].stop = pathPosition;
            if (ResolveAndSubmitNavTrace(ai,
                    transition.navTraces[2]) == TRACE_WAITING) {
                allResolved = false;
            }
        }
    }
    return allResolved;
}

// Retail symbol:
// ?PrepareArrivalTraces@idAnimWebTransitions@@SA_NPAVidAI2@@ABUtransitionQueryValidation_t@1@AAUtransitionCache_t@1@ABUtransitionQueryParms_t@1@@Z
// EA: 0x82A672F0, RVA: 0x00A672F0
bool idAnimWebTransitions::PrepareArrivalTraces(idAI2* const ai,
        const transitionQueryValidation_t& validation,
        transitionCache_t& cache, const transitionQueryParms_t& parms) {
    if (cache.transitions.Num() == 0) {
        return true;
    }

    bool allResolved = true;
    for (int index = 0; index < cache.transitions.Num(); ++index) {
        transitionData_t& transition = cache.transitions[index];
        const idMat3 transitionAxis =
            parms.destinationAxis * transition.deltaAxis;
        const idVec3 startOrigin = parms.destinationOrigin
            + TransformLocal(transitionAxis, -transition.deltaOrigin);
        const idVec3 apexOrigin = transition.hasApex
            ? startOrigin + TransformLocal(transitionAxis, transition.apex)
            : parms.destinationOrigin;

        if (validation.navProbeAnimApex) {
            if (transition.hasApex) {
                transition.navTraces[0].start = parms.destinationOrigin;
                transition.navTraces[0].stop = apexOrigin;
                if (ResolveAndSubmitNavTrace(ai,
                        transition.navTraces[0]) == TRACE_WAITING) {
                    allResolved = false;
                }
            }
            transition.navTraces[1].start = apexOrigin;
            transition.navTraces[1].stop = startOrigin;
            if (ResolveAndSubmitNavTrace(ai,
                    transition.navTraces[1]) == TRACE_WAITING) {
                allResolved = false;
            }
        }
        if (validation.navProbeAnimTranslation
            && !validation.navProbeAnimApex) {
            transition.navTraces[2].start = parms.destinationOrigin;
            transition.navTraces[2].stop = startOrigin;
            if (ResolveAndSubmitNavTrace(ai,
                    transition.navTraces[2]) == TRACE_WAITING) {
                allResolved = false;
            }
        }
    }
    return allResolved;
}

// Retail symbol:
// ?FillTransitionCache@idAnimWebTransitions@@SAXPAVidAI2@@AAUtransitionCache_t@1@ABVidAnimWebState@@@Z
// EA: 0x82A676F8, RVA: 0x00A676F8
void idAnimWebTransitions::FillTransitionCache(idAI2* const ai,
        transitionCache_t& cache,
        const idAnimWebState& transitionState) {
    if (ai == nullptr || !transitionState.Verify()) {
        return;
    }

    cache.maximumDeltaOriginDistanceSqr = 0.0f;
    cache.nodeIndex = transitionState.node;
    const idDeclMD6* const model = transitionState.GetModel(0);
    const int animationCount = transitionState.GetNumAnims(model);
    bool hasDistance = false;
    for (int animationIndex = 0;
            animationIndex < animationCount; ++animationIndex) {
        const idMD6Anim* const animation = transitionState.GetAnimByIndex(
            model, animationIndex, 0);
        if (animation == nullptr) {
            continue;
        }

        transitionData_t transition;
        if (!Tungsten_DecodeAIAnimWebTransition(*ai, transitionState,
                *animation, animationIndex, transition)) {
            continue;
        }
        transition.src = transitionState;
        transition.anim = animation;
        transition.selectionIndex = animationIndex;
        ResetNavTraces(transition);

        const float distanceSqr = transition.deltaOrigin.LengthSqr();
        cache.maximumDeltaOriginDistanceSqr = (std::max)(
            cache.maximumDeltaOriginDistanceSqr, distanceSqr);
        if (!hasDistance) {
            cache.minimumDeltaOriginDistanceSqr = distanceSqr;
            hasDistance = true;
        } else {
            cache.minimumDeltaOriginDistanceSqr = (std::min)(
                cache.minimumDeltaOriginDistanceSqr, distanceSqr);
        }
        cache.maximumPathDistance = (std::max)(
            cache.maximumPathDistance,
            transition.approximatePathDistance);
        cache.transitions.Append(transition);
    }
}

// Retail symbol:
// ?InitTransitionCache@idAnimWebTransitions@@SAXPAVidAI2@@AAUtransitionCache_t@1@ABVidAnimWebState@@2HPBD@Z
// EA: 0x82A68560, RVA: 0x00A68560
void idAnimWebTransitions::InitTransitionCache(idAI2* const ai,
        transitionCache_t& cache, const idAnimWebState& srcState,
        const idAnimWebState& dstState, const int nodeCheckFlags,
        const char* const additionalSubweb) {
    cache.transitions.Clear();
    cache.srcState = srcState;
    cache.dstState = dstState;
    cache.lastCheckFlags = nodeCheckFlags;

    if (ai == nullptr) {
        cache.nodeIndex.Invalidate();
        return;
    }
    idAnimWebState transitionState;
    if (Tungsten_FindAIAnimWebTransitionState(*ai, srcState, dstState,
            nodeCheckFlags, additionalSubweb, transitionState)
        && transitionState.Verify()) {
        FillTransitionCache(ai, cache, transitionState);
    } else {
        cache.nodeIndex.Invalidate();
    }
}
