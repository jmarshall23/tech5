#pragma once

#include "cm/jobs/collisionquery.h"

enum collisionFeature_t : int {
    COLLISION_FEATURE_INVALID = 0,
    COLLISION_FEATURE_VERTEX = 1,
    COLLISION_FEATURE_EDGE = 2,
    COLLISION_FEATURE_POLYGON = 3,
    COLLISION_FEATURE_POLYTOPE = 4
};

struct slideMoveState_t {
    idVec3 velocity;
    idVec3 endVelocity;
    contactInfo_t firstContact;
    float fractionRemaining;
    float steppedUp;
    idVec3 startNormal;
    idVec3 planes[4];
    int numPlanes;
    int pad;
};

bool ClipVelocity(idVec3& velocity, const idVec3* planes, int numPlanes);

class idCollisionDetectionMerge {
public:
    static void MergeContentsResults(queryResults_t* finalResult,
        const queryResults_t* mergeResults, int numMergeResults,
        int resultSize);
    static void MergeMotionResults(trace_t* result, const trace_t* rotation,
        const trace_t* translation);
    static void MergeStepMoveResults(trace_t* result, const trace_t* down,
        const trace_t* forward2, const trace_t* forward1, bool slideMove);
    static void InitSlideMoveState(slideMoveState_t* state,
        const idVec3& velocity, const idVec3& gravityVector);
    static bool UpdateSlideMoveState(slideMoveState_t* state,
        trace_t* trace);
    static void FinishSlideMoveState(slideMoveState_t* state,
        trace_t* trace);
    static void MergeTraceResults(queryResults_t* finalResult,
        const queryResults_t* mergeResults, int numMergeResults,
        int resultSize);
    static void MergeContactsResults(queryResults_t* finalResult,
        const queryResults_t* mergeResults, int numMergeResults,
        int resultSize);
    static void MergeClipResults(queryResults_t* finalResult,
        const queryResults_t* mergeResults, int numMergeResults,
        int resultSize);
    static void MergeQueryResults(queryResults_t* finalResult,
        int resultSize, traceType_t type,
        const queryResults_t* mergeResults, int numMergeResults,
        slideMoveState_t* slideMoveState, dependencyType_t dependencyType,
        const queryResults_t* dependency1,
        const queryResults_t* dependency2);
};

static_assert(sizeof(slideMoveState_t) == 176,
    "Recovered slideMoveState_t ABI changed");
