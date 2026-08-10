#pragma once

#include "animwebstate.h"

#include "idlib/containers/array.h"
#include "idlib/containers/staticlist.h"

class idAI2;
class idMD6Anim;

// Recovered from the retail PDB type stream.  Keeping this declaration in a
// small common header breaks the original aianimwebstate/transitions include
// cycle without changing the nested type names used by either translation
// unit.
class idAnimWebTransitions {
public:
    enum navTraceResult_t : int {
        TRACE_CLEAR = 0,
        TRACE_BLOCKED = 1,
        TRACE_WAITING = 2
    };

    struct navTraceData_t {
        navTraceData_t();

        idVec3 start;
        idVec3 stop;
        float fraction;
        int num[2];
        int numIndex;
    };

    struct transitionData_t {
        transitionData_t();

        idVec3 deltaOrigin;
        idMat3 deltaAxis;
        float deltaCorrectEndDistanceSqr;
        idVec3 apex;
        idVec3 deltaCorrectEndTranslation;
        idMat3 deltaCorrectEndAxis;
        idVec3 deltaCorrectGoalTranslation;
        idMat3 deltaCorrectGoalAxis;
        bool hasApex;
        int flags;
        float approximatePathDistance;
        idAnimWebState src;
        idAnimWebState via;
        idAnimWebState dst;
        const idMD6Anim* anim;
        idArray<navTraceData_t, 8> navTraces;
        int selectionIndex;
    };

    struct transitionCache_t {
        transitionCache_t();
        void Clear();

        idAnimWebState srcState;
        idAnimWebState dstState;
        int lastCheckFlags;
        idList<transitionData_t, 5> transitions;
        float maximumDeltaOriginDistanceSqr;
        float maximumPathDistance;
        float minimumDeltaOriginDistanceSqr;
        idAnimWebNodeIndex nodeIndex;
    };

    struct transitionQueryParms_t {
        transitionQueryParms_t();

        idVec3 sourceOrigin1;
        idVec3 sourceOrigin2;
        idMat3 sourceAxis;
        idVec3 destinationOrigin;
        idMat3 destinationAxis;
        idVec3 turnPoint;
        float totalPathDistance;
        float pathDistanceAlongAxis;
        int debugDrawTime;
        idStaticList<idVec3, 31> cachedCorners;
    };

    struct transitionQueryValidation_t {
        enum selectionType_t : int {
            CHOOSE_ANGLE_DISTANCE_ERROR = 0,
            CHOOSE_CLOSEST_TO_DESTINATION = 1,
            CHOOSE_CLOSEST_TO_SEGMENT = 2,
            CHOOSE_CLOSEST_ANGLE_START = 3,
            CHOOSE_CLOSEST_TO_PATH_RELATIVE = 4
        };

        transitionQueryValidation_t();

        selectionType_t selectType;
        float requiredSourceAlignAngleDot;
        float requiredMoveAlignAngleDot;
        float movementDistanceFudge;
        bool usePathDirectionForMoveAlign;
        bool usePathDirectionForSourceAlign;
        float maxMoveDistanceMultiplier;
        int allowedFlags;
        int requiredFlags;
        int suggestedFlags;
        bool checkMaxMovementDistance;
        float requiredApexAlignAngleDot;
        bool usePathDirectionForApexAlign;
        bool checkAnimTooShort;
        bool navProbeAnimTranslation;
        bool navProbeAnimApex;
        bool navProbeToPathPosition;
        bool allowRejections;
    };

    struct transitionQueryResult_t {
        transitionQueryResult_t();

        idAnimWebState dst;
        idAnimWebState via;
        idVec3 startOrigin;
        idVec3 destOrigin;
        int selectionIndex;
        float approximatePathDistance;
        const idMD6Anim* anim;
    };

    struct transition_t {
        idAnimWebNodeIndex src;
        idAnimWebNodeIndex via;
        idAnimWebNodeIndex dst;
    };

    struct defaultArrivalTransitionValidation_t
        : transitionQueryValidation_t {
        defaultArrivalTransitionValidation_t();
    };
    struct defaultStepTransitionValidation_t
        : transitionQueryValidation_t {
        defaultStepTransitionValidation_t();
    };
    struct defaultFlightTransitionValidation_t
        : transitionQueryValidation_t {
        defaultFlightTransitionValidation_t();
    };
    struct defaultSoftStopTransitionValidation_t
        : transitionQueryValidation_t {
        defaultSoftStopTransitionValidation_t();
    };
    struct defaultDepartureTransitionValidation_t
        : transitionQueryValidation_t {
        defaultDepartureTransitionValidation_t();
    };

    static const defaultArrivalTransitionValidation_t
        defaultArrivalTransitionValidation;
    static const defaultStepTransitionValidation_t
        defaultStepTransitionValidation;
    static const defaultFlightTransitionValidation_t
        defaultFlightTransitionValidation;
    static const defaultSoftStopTransitionValidation_t
        defaultSoftStopTransitionValidation;
    static const defaultDepartureTransitionValidation_t
        defaultDepartureTransitionValidation;

    static float GetDistanceToPath(
        const idStaticList<idVec3, 31>& path,
        const idVec3& startOrigin, const idVec3& testPoint,
        idVec3& outPositionOnPath, idVec3& outDirectionOnPath);
    static int GetPathPositionAndDirection(
        const idStaticList<idVec3, 31>& path, float distanceAhead,
        const idVec3& startDirection, const idVec3& startPosition,
        idVec3& outPosition, idVec3& outDirection);
    static void CleanupNavTraces(idAI2* ai, transitionCache_t& cache);
    static bool FindDepartureTransition(const idAI2* ai,
        const transitionQueryValidation_t& validation,
        transitionCache_t& cache, const transitionQueryParms_t& parms,
        transitionQueryResult_t& out,
        bool& wasRejectedBasedOnDistanceAlone);
    static bool FindTurnTransition(const idAI2* ai,
        const transitionQueryValidation_t& validation,
        transitionCache_t& cache, const transitionQueryParms_t& parms,
        transitionQueryResult_t& out);
    static bool FindCommonArrivalTransition(const idAI2* ai,
        const transitionQueryValidation_t& validation,
        transitionCache_t& cache, const transitionQueryParms_t& parms,
        transitionQueryResult_t& out);
    static navTraceResult_t ResolveAndSubmitNavTrace(
        idAI2* ai, navTraceData_t& trace);
    static bool PrepareDepartureTraces(idAI2* ai,
        const transitionQueryValidation_t& validation,
        transitionCache_t& cache, const transitionQueryParms_t& parms);
    static bool PrepareArrivalTraces(idAI2* ai,
        const transitionQueryValidation_t& validation,
        transitionCache_t& cache, const transitionQueryParms_t& parms);
    static void FillTransitionCache(idAI2* ai, transitionCache_t& cache,
        const idAnimWebState& transitionState);
    static void InitTransitionCache(idAI2* ai, transitionCache_t& cache,
        const idAnimWebState& srcState, const idAnimWebState& dstState,
        int nodeCheckFlags, const char* additionalSubweb);
};

// These seams are the boundary to the still-unrecovered idAnimBaseFSM nav
// queue and animator event decoder.  The recovered source retains ownership
// of query rotation, selection, scoring, cache bounds, and trace endpoints.
float Tungsten_GetAIAnimWebNavTraceResult(const idAI2& ai, int queryNumber);
void Tungsten_ReleaseAIAnimWebNavTrace(idAI2& ai, int queryNumber);
int Tungsten_AddAIAnimWebNavTrace(
    idAI2& ai, const idVec3& start, const idVec3& stop);
bool Tungsten_DecodeAIAnimWebTransition(const idAI2& ai,
    const idAnimWebState& transitionState, const idMD6Anim& animation,
    int animationIndex, idAnimWebTransitions::transitionData_t& data);
bool Tungsten_FindAIAnimWebTransitionState(const idAI2& ai,
    const idAnimWebState& source, const idAnimWebState& destination,
    int nodeCheckFlags, const char* additionalSubweb,
    idAnimWebState& transitionState);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimWebTransitions::navTraceData_t) == 40,
    "Recovered animation-web nav trace ABI changed");
static_assert(sizeof(idAnimWebTransitions::transitionData_t) == 560,
    "Recovered animation-web transition ABI changed");
static_assert(sizeof(idAnimWebTransitions::transitionCache_t) == 76,
    "Recovered animation-web transition cache ABI changed");
static_assert(sizeof(idAnimWebTransitions::transitionQueryResult_t) == 76,
    "Recovered animation-web query result ABI changed");
static_assert(sizeof(idAnimWebTransitions::transitionQueryValidation_t) == 52,
    "Recovered animation-web query validation ABI changed");
#endif
