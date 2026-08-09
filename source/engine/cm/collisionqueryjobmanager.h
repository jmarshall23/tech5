#pragma once

#include "cm/collisionmodel.h"
#include "cm/jobs/collisionmerge.h"
#include "idlib/math/rotation.h"

#include <cstdint>

class idParallelJobList;
struct idQueryData;
struct subModelQuery_t;

struct modelQuery_t {
    traceType_t type;
    queryParms_t* parms;
    const idTraceModel* trm;
    cmType_t modelType;
    const cm_polygonModel_t* polygonModel;
    const cm_sphereModel_t* sphereModel;
    const idJointMat* modelJoints;
    const char* userName;
    queryResults_t* resultsPtr;
    queryResults_t* finalResultsPtr;
    modelQuery_t* nextOnQuery;
    subModelQuery_t* subModelQueries;
    int numSubModelQueries;
    int executePriority;
    int mergePriority;
    modelQuery_t* nextInExecuteList;
    modelQuery_t* nextInMergeList;
    slideMoveState_t* slideMoveState;
    queryResults_t* mergeResults;
    int numMergeResults;
    int resultSize;
    queryResults_t* modelPosition;
    queryResults_t* dependency1;
    queryResults_t* dependency2;
    dependencyType_t dependencyType;
    int frameNumber;
    int pad[6];
};

struct subModelQuery_t {
    queryParms_t* parms;
    const idTraceModel* trm;
    const cm_subModel_t* subModel;
    const cm_subModelData_t* subModelData;
    int subModelNum;
    queryResults_t* resultsPtr;
    modelQuery_t* modelQuery;
    subModelQuery_t* nextOnModelQuery;
};

struct timings_t {
    timings_t();

    std::uint32_t min;
    std::uint32_t max;
    std::uint32_t total;
    std::uint32_t count;
};

struct queryDataStats_t {
    const char* userName;
    int numCollisionQueries;
    int numModelQueries;
    int numSubModelQueries;
    int queryDataSize;
    int finalResultSize;
    int maxCollisionQueries;
    int maxModelQueries;
    int maxSubModelQueries;
    int maxQueryDataSize;
    int maxFinalResultSize;
};

struct profile_t {
    timings_t timings[5];
};

struct jobGroup_t {
    modelQuery_t* stallingExecuteJobs;
    modelQuery_t* notStallingExecuteJobs1;
    modelQuery_t* notStallingExecuteJobs2;
    modelQuery_t* stallingMergeJobs;
    modelQuery_t* notStallingMergeJobs;
    int numJobs;
};

struct failedQuery_t {
    bool valid;
    queryResults_t results;
    queryParms_t parms;
    const idTraceModel* trm;
    idCollisionModel* trmModel;
    const cm_polygonModel_t* model;
    const cm_subModel_t* subModel;
    const cm_subModelData_t* subModelData;
    idBounds subModelBounds;
    int subModelNum;
};

class idCollisionQueryJobManager {
public:
    idCollisionQueryJobManager();
    ~idCollisionQueryJobManager();

    void Init();
    void Shutdown();
    void WaitForAllQueries();

    idCollisionQuery SubmitTranslationQuery(const idVec3& start,
        const idVec3& end, const idBounds& globalBounds,
        const idTraceModel** trms, int numTrms, const idMat3& trmAxis,
        int contentMask, const idPositionedCollisionModel* models,
        int numModels, const char* userName);
    idCollisionQuery SubmitLocalTranslationQuery(idCollisionQuery localSpace,
        const idVec3& start, const idVec3& end,
        const idBounds& globalBounds, const idTraceModel** trms,
        int numTrms, const idMat3& trmAxis, int contentMask,
        const idPositionedCollisionModel* models, int numModels,
        const char* userName);
    idCollisionQuery SubmitRotationQuery(const idVec3& start,
        const idRotation& rotation, const idBounds& globalBounds,
        const idTraceModel** trms, int numTrms, const idMat3& trmAxis,
        int contentMask, const idPositionedCollisionModel* models,
        int numModels, const char* userName);
    idCollisionQuery SubmitMotionQuery(const idVec3& start,
        const idVec3& end, const idRotation& rotation,
        const idBounds& globalBounds, const idTraceModel** trms,
        int numTrms, const idMat3& trmAxis, int contentMask,
        const idPositionedCollisionModel* models, int numModels,
        const char* userName);
    idCollisionQuery SubmitMotionContactsQuery(const idVec3& start,
        const idVec3& end, const idRotation& rotation, float depth,
        const idBounds& globalBounds, const idTraceModel** trms,
        int numTrms, const idMat3& trmAxis, int contentMask,
        const idPositionedCollisionModel* models, int numModels,
        const char* userName);
    idCollisionQuery SubmitContentsQuery(const idVec3& start,
        const idBounds& globalBounds, const idTraceModel** trms,
        int numTrms, const idMat3& trmAxis, int contentMask,
        const idPositionedCollisionModel* models, int numModels,
        const char* userName);
    idCollisionQuery SubmitLocalContentsQuery(idCollisionQuery localSpace,
        const idVec3& start, const idBounds& globalBounds,
        const idTraceModel** trms, int numTrms, const idMat3& trmAxis,
        int contentMask, const idPositionedCollisionModel* models,
        int numModels, const char* userName);
    idCollisionQuery SubmitContactsQuery(const idVec3& start,
        const idVec3& direction, float depth,
        const idBounds& globalBounds, const idTraceModel** trms,
        int numTrms, const idMat3& trmAxis, int contentMask,
        const idPositionedCollisionModel* models, int numModels,
        const char* userName);
    idCollisionQuery SubmitClipQuery(const idVec3& start,
        const idBounds& globalBounds, const idTraceModel** trms,
        int numTrms, const idMat3& trmAxis, int contentMask,
        const idPositionedCollisionModel* models, int numModels,
        const char* userName);
    idCollisionQuery SubmitStepMoveQuery(const idVec3& start,
        const idVec3& end, const idVec3& downNormal, float stepUp,
        float stepDown, const idBounds& globalBounds,
        const idTraceModel** trms, int numTrms, const idMat3& trmAxis,
        int contentMask, const idPositionedCollisionModel* models,
        int numModels, const char* userName);
    idCollisionQuery SubmitStepMoveContactsQuery(const idVec3& start,
        const idVec3& end, const idVec3& downNormal, float stepUp,
        float stepDown, const idBounds& globalBounds,
        const idTraceModel** trms, int numTrms, const idMat3& trmAxis,
        int contentMask, const idPositionedCollisionModel* models,
        int numModels, const char* userName);
    idCollisionQuery SubmitSlideMoveQuery(const idVec3& start,
        const idVec3& velocity, const idVec3& gravityVector, float stepUp,
        float stepDown, const idBounds& globalBounds,
        const idTraceModel** trms, int numTrms, const idMat3& trmAxis,
        int contentMask, const idPositionedCollisionModel* models,
        int numModels, const char* userName);
    idCollisionQuery SubmitSlideMoveContactsQuery(const idVec3& start,
        const idVec3& velocity, const idVec3& gravityVector, float stepUp,
        float stepDown, const idBounds& globalBounds,
        const idTraceModel** trms, int numTrms, const idMat3& trmAxis,
        int contentMask, const idPositionedCollisionModel* models,
        int numModels, const char* userName);

    bool GetRotationResult(idTraceWork* tw, trace_t* result,
        idCollisionQuery& query, bool peek);
    bool GetTraceResult(trace_t* result, idCollisionQuery& query,
        bool peek);
    bool GetContactsResult(contactsResult_t* result,
        idCollisionQuery& query, bool peek);
    bool GetMotionContactsResult(idTraceWork* tw, trace_t* result,
        contactsResult_t* contacts, idCollisionQuery& query, bool peek);
    bool GetClipResult(idTraceWork* tw, clipResult_t* result,
        idCollisionQuery& query, bool peek);
    bool GetSlideMoveContactsResult(idTraceWork* tw, trace_t* result,
        contactsResult_t* contacts, idCollisionQuery& query, bool peek);

    void ShowDebugInfo();
    void StartFrame();
    void EndFrame();
    void SubmitQueries();

    bool WaitForQueryResults(queryResults_t* results);
    modelQuery_t* AllocModelQuery(
        const idPositionedCollisionModel& model);
    idCollisionQuery AllocFinishedFinalResult(traceType_t firstType,
        traceType_t secondType, const idVec3& endPosition,
        const idMat3& endAxis, const char* userName);
    idCollisionQuery AddModelQueryToMergeList(modelQuery_t* modelQuery,
        int mergePriority, slideMoveState_t* slideMoveState);
    void AddModelQueryToExecuteList(modelQuery_t* modelQuery,
        idCollisionQuery modelPosition, idCollisionQuery dependency1,
        idCollisionQuery dependency2, dependencyType_t dependencyType,
        const idVec3& globalStart, const idVec3& globalEnd,
        const idBounds& globalBounds, int& executePriority);
    void CreateMergeJobs(idParallelJobList* jobList,
        modelQuery_t* modelQuery);
    void CreateExecuteJobs(idParallelJobList* jobList,
        modelQuery_t* modelQuery);

    idQueryData* queryData;
    queryResults_t* dummyQueryResults;
    int queryFrameNumber;
    int stalledFrameNumber;
    std::uint64_t firstWaitTime;
    int numJobGroups;
    jobGroup_t* jobGroups;
    idParallelJobList* jobList;
    failedQuery_t failedQuery;
    profile_t threadProfile[8];
    profile_t translationProfile;
    profile_t rotationProfile;
    profile_t contentsProfile;
    profile_t contactsProfile;
    profile_t clipProfile;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(timings_t) == 16,
    "Recovered timings_t ABI changed");
static_assert(sizeof(queryDataStats_t) == 44,
    "Recovered queryDataStats_t ABI changed");
static_assert(sizeof(idCollisionQueryJobManager) == 2304,
    "Recovered idCollisionQueryJobManager ABI changed");
#endif
