#include "cm/collisionqueryjobmanager.h"

#include "cm/jobs/polygonmodel/polygonmodel.h"

#include <algorithm>
#include <climits>
#include <cstring>
#include <malloc.h>
#include <new>
#include <vector>

namespace {

struct pcQuerySlot_t {
    queryResults_t primary;
    queryResults_t secondary;
    bool hasSecondary;
};

struct pcQueryMemory_t {
    void* data;
    std::size_t size;
};

} // namespace

struct idQueryData {
    idQueryData();
    ~idQueryData();

    void AdvanceSubModelQueryFirstSubmittedIndex(std::uint64_t newIndex);
    void StartFrame();
    int UpdateQueryDataStats(queryDataStats_t* stats, int& numStats,
        int maxStats, queryDataStats_t& totalStats);
    void EndFrame();
    void Clear();
    void ReleaseQueryOnlyData();

    modelQuery_t* AllocModelQuery();
    subModelQuery_t* AllocSubModelQuery();
    queryParms_t* AllocQueryParms();
    slideMoveState_t* AllocSlideMoveState();
    queryResults_t* AllocIntermediateResults(unsigned int numResults,
        unsigned int resultSize);
    queryResults_t* AllocFinalResult(unsigned int totalSize);

    std::vector<pcQuerySlot_t*> outstanding;
    std::vector<modelQuery_t*> modelQueries;
    std::vector<subModelQuery_t*> subModelQueries;
    std::vector<queryParms_t*> queryParms;
    std::vector<slideMoveState_t*> slideMoveStates;
    std::vector<pcQueryMemory_t> intermediateResults;
    std::vector<pcQueryMemory_t> finalResults;
    bool started;
    int failedModelQuery;
    int failedSubModelQuery;
    int failedQueryParms;
    int failedIntermediateResults;
    int failedFinalResults;
    int failedSlideMoveState;
    int failedMergeResults;
};

timings_t::timings_t()
    : min(UINT_MAX), max(0), total(0), count(0) {
}

idQueryData::idQueryData()
    : started(false), failedModelQuery(0), failedSubModelQuery(0),
      failedQueryParms(0), failedIntermediateResults(0),
      failedFinalResults(0), failedSlideMoveState(0),
      failedMergeResults(0) {
}

idQueryData::~idQueryData() {
    Clear();
}

void idQueryData::AdvanceSubModelQueryFirstSubmittedIndex(
    const std::uint64_t newIndex) {
    const std::size_t count = newIndex >= subModelQueries.size()
        ? subModelQueries.size() : static_cast<std::size_t>(newIndex);
    for (std::size_t index = 0; index < count; ++index) {
        subModelQuery_t* const query = subModelQueries[index];
        if (query->subModel != nullptr && query->subModelData != nullptr) {
            ReleaseSubModelData(*query->subModel, query->subModelData);
            query->subModelData = nullptr;
        }
        delete query;
    }
    subModelQueries.erase(subModelQueries.begin(),
        subModelQueries.begin() + count);
}

void idQueryData::StartFrame() {
    started = true;
}

int idQueryData::UpdateQueryDataStats(queryDataStats_t* const stats,
    int& numStats, const int maxStats, queryDataStats_t& totalStats) {
    totalStats.numCollisionQueries = 0;
    totalStats.numModelQueries = 0;
    totalStats.numSubModelQueries = 0;
    totalStats.queryDataSize = 0;
    totalStats.finalResultSize = 0;

    for (int index = 0; index < numStats; ++index) {
        stats[index].numCollisionQueries = 0;
        stats[index].numModelQueries = 0;
        stats[index].numSubModelQueries = 0;
        stats[index].queryDataSize = 0;
        stats[index].finalResultSize = 0;
    }

    for (const modelQuery_t* const query : modelQueries) {
        const char* const userName = query->userName != nullptr
            ? query->userName : "*Unknown*";
        int statIndex = 0;
        while (statIndex < numStats
            && stats[statIndex].userName != userName) {
            ++statIndex;
        }
        if (statIndex == numStats) {
            if (numStats >= maxStats || stats == nullptr) {
                continue;
            }
            std::memset(&stats[statIndex], 0, sizeof(stats[statIndex]));
            stats[statIndex].userName = userName;
            ++numStats;
        }

        queryDataStats_t& entry = stats[statIndex];
        const int resultSize = query->type >= TRACE_CONTACTS_UNI_DIR
            ? 992 : 192;
        entry.numCollisionQueries += query->nextOnQuery == nullptr ? 1 : 0;
        ++entry.numModelQueries;
        entry.numSubModelQueries += query->numSubModelQueries;
        entry.queryDataSize += (std::max)(1,
            query->numSubModelQueries) * resultSize;
        entry.finalResultSize += query->finalResultsPtr != nullptr
            ? resultSize : 0;
    }

    for (int index = 0; index < numStats; ++index) {
        queryDataStats_t& entry = stats[index];
        entry.maxCollisionQueries = (std::max)(entry.maxCollisionQueries,
            entry.numCollisionQueries);
        entry.maxModelQueries = (std::max)(entry.maxModelQueries,
            entry.numModelQueries);
        entry.maxSubModelQueries = (std::max)(entry.maxSubModelQueries,
            entry.numSubModelQueries);
        entry.maxQueryDataSize = (std::max)(entry.maxQueryDataSize,
            entry.queryDataSize);
        entry.maxFinalResultSize = (std::max)(entry.maxFinalResultSize,
            entry.finalResultSize);
        totalStats.numCollisionQueries += entry.numCollisionQueries;
        totalStats.numModelQueries += entry.numModelQueries;
        totalStats.numSubModelQueries += entry.numSubModelQueries;
        totalStats.queryDataSize += entry.queryDataSize;
        totalStats.finalResultSize += entry.finalResultSize;
    }

    totalStats.maxCollisionQueries = (std::max)(
        totalStats.maxCollisionQueries, totalStats.numCollisionQueries);
    totalStats.maxModelQueries = (std::max)(totalStats.maxModelQueries,
        totalStats.numModelQueries);
    totalStats.maxSubModelQueries = (std::max)(
        totalStats.maxSubModelQueries, totalStats.numSubModelQueries);
    totalStats.maxQueryDataSize = (std::max)(totalStats.maxQueryDataSize,
        totalStats.queryDataSize);
    totalStats.maxFinalResultSize = (std::max)(
        totalStats.maxFinalResultSize, totalStats.finalResultSize);
    return numStats;
}

void idQueryData::EndFrame() {
    started = false;
}

void idQueryData::Clear() {
    ReleaseQueryOnlyData();
    for (pcQuerySlot_t* const slot : outstanding) {
        delete slot;
    }
    outstanding.clear();
    for (const pcQueryMemory_t& block : finalResults) {
        _aligned_free(block.data);
    }
    finalResults.clear();
    started = false;
    failedModelQuery = 0;
    failedSubModelQuery = 0;
    failedQueryParms = 0;
    failedIntermediateResults = 0;
    failedFinalResults = 0;
    failedSlideMoveState = 0;
    failedMergeResults = 0;
}

void idQueryData::ReleaseQueryOnlyData() {
    AdvanceSubModelQueryFirstSubmittedIndex(subModelQueries.size());
    for (modelQuery_t* const query : modelQueries) {
        delete query;
    }
    modelQueries.clear();
    for (queryParms_t* const parms : queryParms) {
        delete parms;
    }
    queryParms.clear();
    for (slideMoveState_t* const state : slideMoveStates) {
        delete state;
    }
    slideMoveStates.clear();
    for (const pcQueryMemory_t& block : intermediateResults) {
        _aligned_free(block.data);
    }
    intermediateResults.clear();
}

modelQuery_t* idQueryData::AllocModelQuery() {
    if (modelQueries.size() >= 2048) {
        ++failedModelQuery;
        return nullptr;
    }
    modelQuery_t* const query = new (std::nothrow) modelQuery_t{};
    if (query == nullptr) {
        ++failedModelQuery;
        return nullptr;
    }
    modelQueries.push_back(query);
    return query;
}

subModelQuery_t* idQueryData::AllocSubModelQuery() {
    if (subModelQueries.size() >= 4096) {
        ++failedSubModelQuery;
        return nullptr;
    }
    subModelQuery_t* const query = new (std::nothrow) subModelQuery_t{};
    if (query == nullptr) {
        ++failedSubModelQuery;
        return nullptr;
    }
    subModelQueries.push_back(query);
    return query;
}

queryParms_t* idQueryData::AllocQueryParms() {
    if (queryParms.size() >= 2048) {
        ++failedQueryParms;
        return nullptr;
    }
    queryParms_t* const parms = new (std::nothrow) queryParms_t{};
    if (parms == nullptr) {
        ++failedQueryParms;
        return nullptr;
    }
    queryParms.push_back(parms);
    return parms;
}

slideMoveState_t* idQueryData::AllocSlideMoveState() {
    if (slideMoveStates.size() >= 128) {
        ++failedSlideMoveState;
        return nullptr;
    }
    slideMoveState_t* const state =
        new (std::nothrow) slideMoveState_t{};
    if (state == nullptr) {
        ++failedSlideMoveState;
        return nullptr;
    }
    slideMoveStates.push_back(state);
    return state;
}

queryResults_t* idQueryData::AllocIntermediateResults(
    const unsigned int numResults, const unsigned int resultSize) {
    constexpr std::size_t capacity = 1024 * 1024;
    if (numResults == 0 || resultSize == 0
        || numResults > capacity / resultSize) {
        const std::uint64_t requested =
            static_cast<std::uint64_t>(numResults) * resultSize;
        failedIntermediateResults += static_cast<int>((std::min)(requested,
            static_cast<std::uint64_t>(INT_MAX)));
        return nullptr;
    }
    const std::size_t size = static_cast<std::size_t>(numResults)
        * resultSize;
    std::size_t allocated = 0;
    for (const pcQueryMemory_t& block : intermediateResults) {
        allocated += block.size;
    }
    if (size > capacity - (std::min)(allocated, capacity)) {
        failedIntermediateResults += static_cast<int>((std::min)(size,
            static_cast<std::size_t>(INT_MAX)));
        return nullptr;
    }
    void* const memory = _aligned_malloc(size, 128);
    if (memory == nullptr) {
        failedIntermediateResults += static_cast<int>((std::min)(size,
            static_cast<std::size_t>(INT_MAX)));
        return nullptr;
    }
    std::memset(memory, 0, size);
    intermediateResults.push_back({memory, size});
    return static_cast<queryResults_t*>(memory);
}

queryResults_t* idQueryData::AllocFinalResult(
    const unsigned int totalSize) {
    std::size_t allocated = 0;
    for (const pcQueryMemory_t& block : finalResults) {
        allocated += block.size;
    }
    if (totalSize == 0 || totalSize > 512 * 1024 - (std::min)(allocated,
            static_cast<std::size_t>(512 * 1024))) {
        failedFinalResults += static_cast<int>(totalSize);
        return nullptr;
    }
    void* const memory = _aligned_malloc(totalSize, 128);
    if (memory == nullptr) {
        failedFinalResults += static_cast<int>(totalSize);
        return nullptr;
    }
    std::memset(memory, 0, totalSize);
    finalResults.push_back({memory, totalSize});
    return static_cast<queryResults_t*>(memory);
}

namespace {

pcQuerySlot_t* Slot(const idCollisionQuery& query) {
    return reinterpret_cast<pcQuerySlot_t*>(
        static_cast<std::uintptr_t>(query.offset));
}

pcQuerySlot_t* OwnedSlot(const idQueryData* const data,
    const idCollisionQuery& query) {
    pcQuerySlot_t* const slot = Slot(query);
    if (data == nullptr || slot == nullptr) {
        return nullptr;
    }
    return std::find(data->outstanding.begin(), data->outstanding.end(),
        slot) != data->outstanding.end() ? slot : nullptr;
}

idCollisionQuery MakeQuery(idQueryData* const data, pcQuerySlot_t* slot) {
    if (data != nullptr) {
        data->outstanding.push_back(slot);
    }
    idCollisionQuery query;
    query.offset = static_cast<std::uint64_t>(
        reinterpret_cast<std::uintptr_t>(slot));
    return query;
}

void InitResult(queryResults_t& result, const traceType_t type,
    const idVec3& end, const idMat3& axis) {
    std::memset(&result, 0, sizeof(result));
    result.query.type = type;
    result.query.status = QUERY_STATUS_SUCCESS;
    result.query.done = 1;
    if (type == TRACE_CONTACTS_UNI_DIR || type == TRACE_CONTACTS_OMNI_DIR) {
        reinterpret_cast<contactsResult_t*>(result.data)->numContacts = 0;
    } else if (type == TRACE_CLIP) {
        reinterpret_cast<clipResult_t*>(result.data)->numVerts = 0;
        reinterpret_cast<clipResult_t*>(result.data)->numIndices = 0;
    } else {
        trace_t& trace = *reinterpret_cast<trace_t*>(result.data);
        std::memset(&trace, 0, sizeof(trace));
        trace.fraction = 1.0f;
        trace.endpos = end;
        trace.endAxis = axis;
    }
}

idCollisionQuery SubmitSimple(idQueryData* const data,
    const traceType_t type,
    const idVec3& start, const idVec3& end, const idRotation* rotation,
    const idVec3& direction, const float depth,
    const idTraceModel** const trms, const int numTrms,
    const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* const models, const int numModels) {
    pcQuerySlot_t* const slot = new pcQuerySlot_t;
    slot->hasSecondary = false;
    InitResult(slot->primary, type, end, trmAxis);
    std::vector<queryResults_t> mergeResults;
    if (models != nullptr && numModels > 0) {
        for (int modelNumber = 0; modelNumber < numModels; ++modelNumber) {
            const idPositionedCollisionModel& positioned = models[modelNumber];
            const idCollisionModelLocal* const local =
                dynamic_cast<const idCollisionModelLocal*>(positioned.model);
            if (local == nullptr) {
                continue;
            }
            const int traceModelCount = (std::max)(1, numTrms);
            for (int trmNumber = 0; trmNumber < traceModelCount; ++trmNumber) {
                const idTraceModel* const trm = trms != nullptr && numTrms > 0
                    ? trms[trmNumber] : nullptr;
                queryParms_t parms{};
                parms.type = type;
                parms.autoMerge = true;
                parms.testQuery = type == TRACE_TRANSLATION
                    || type == TRACE_ROTATION;
                parms.start = start;
                parms.end = end;
                if (rotation != nullptr) {
                    parms.rotationOrigin = rotation->origin;
                    parms.rotationAxis = rotation->vec;
                    parms.rotationAngle = rotation->angle;
                }
                parms.dir = direction;
                parms.depth = depth;
                parms.trmAxis = trmAxis;
                parms.contentMask = contentMask;
                parms.modelOrigin = positioned.modelOrigin;
                parms.modelAxis = positioned.modelAxis;
                parms.modelEntityNum = positioned.modelEntityNum;
                parms.modelPhysicsId = positioned.modelPhysicsId;
                parms.modelBodyId = positioned.modelBodyId;
                parms.modelContentsOverride = positioned.modelContentsOverride;
                parms.selfId = 0;
                queryResults_t modelResult{};
                modelResult.query.status = QUERY_STATUS_PENDING;
                idTraceWork work;
                work.Init();
                if (local->modelType == CM_POLYGONMODEL) {
                    idCollisionQueryExecute::ExecutePolygonModelQuery(&work,
                        modelResult, &parms, trm, &local->polygonModel);
                } else if (local->modelType == CM_SPHEREMODEL
                    && local->sphereModel != nullptr) {
                    idCollisionQueryExecute::ExecuteSphereModelQuery(
                        modelResult, &parms, positioned.modelJoints,
                        local->sphereModel);
                }
                mergeResults.push_back(modelResult);
            }
        }
    }
    if (!mergeResults.empty()) {
        idCollisionDetectionMerge::MergeQueryResults(&slot->primary,
            sizeof(queryResults_t), type, mergeResults.data(),
            static_cast<int>(mergeResults.size()), nullptr,
            DEPENDENCY_NONE, nullptr, nullptr);
        slot->primary.query.done = 1;
        slot->primary.query.type = type;
        if (slot->primary.query.status == QUERY_STATUS_PENDING) {
            slot->primary.query.status = QUERY_STATUS_SUCCESS;
        }
    }
    return MakeQuery(data, slot);
}

void DestroyQuery(idQueryData* const data, idCollisionQuery& query) {
    pcQuerySlot_t* const slot = OwnedSlot(data, query);
    if (data != nullptr && slot != nullptr) {
        const auto found = std::find(data->outstanding.begin(),
            data->outstanding.end(), slot);
        data->outstanding.erase(found);
        delete slot;
    }
    query.offset = 0;
}

} // namespace

idCollisionQueryJobManager::idCollisionQueryJobManager()
    : queryData(nullptr), dummyQueryResults(nullptr), queryFrameNumber(0),
      stalledFrameNumber(0), firstWaitTime(0), numJobGroups(0),
      jobGroups(nullptr), jobList(nullptr) {
    std::memset(&failedQuery, 0, sizeof(failedQuery));
}

idCollisionQueryJobManager::~idCollisionQueryJobManager() {
    Shutdown();
}

void idCollisionQueryJobManager::Init() {
    Shutdown();
    queryData = new idQueryData;
    dummyQueryResults = new queryResults_t;
    std::memset(dummyQueryResults, 0, sizeof(*dummyQueryResults));
    dummyQueryResults->query.done = 1;
    dummyQueryResults->query.merged = 1;
    dummyQueryResults->query.status = QUERY_STATUS_SUCCESS;
    queryFrameNumber = 0;
    stalledFrameNumber = 0;
    firstWaitTime = 0;
}

void idCollisionQueryJobManager::Shutdown() {
    if (queryData != nullptr) {
        delete queryData;
        queryData = nullptr;
    }
    delete dummyQueryResults;
    dummyQueryResults = nullptr;
    delete[] jobGroups;
    jobGroups = nullptr;
    numJobGroups = 0;
    jobList = nullptr;
}

void idCollisionQueryJobManager::WaitForAllQueries() {
    // Queries execute synchronously on PC.  This preserves the recovered wait
    // contract while avoiding the Xenon SPU/parallel-job dependency.
    if (queryData != nullptr) {
        queryData->ReleaseQueryOnlyData();
    }
}

idCollisionQuery idCollisionQueryJobManager::SubmitTranslationQuery(
    const idVec3& start, const idVec3& end, const idBounds&,
    const idTraceModel** trms, const int numTrms, const idMat3& trmAxis,
    const int contentMask, const idPositionedCollisionModel* models,
    const int numModels, const char*) {
    return SubmitSimple(queryData, TRACE_TRANSLATION, start, end, nullptr,
        idVec3(0, 0, 0), 0.0f, trms, numTrms, trmAxis, contentMask,
        models, numModels);
}

idCollisionQuery idCollisionQueryJobManager::SubmitLocalTranslationQuery(
    idCollisionQuery localSpace, const idVec3& start, const idVec3& end,
    const idBounds& bounds, const idTraceModel** trms, const int numTrms,
    const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* models, const int numModels,
    const char* userName) {
    pcQuerySlot_t* const localSlot = OwnedSlot(queryData, localSpace);
    if (localSlot == nullptr) {
        return SubmitTranslationQuery(start, end, bounds, trms, numTrms,
            trmAxis, contentMask, models, numModels, userName);
    }
    queryParms_t source{};
    source.start = start;
    source.end = end;
    source.trmAxis = trmAxis;
    queryParms_t transformed;
    idCollisionQueryExecute::SetupDependentParms(&transformed, &source,
        &localSlot->primary, DEPENDENCY_LOCAL_SPACE,
        &localSlot->primary, nullptr);
    return SubmitTranslationQuery(transformed.start, transformed.end, bounds,
        trms, numTrms, transformed.trmAxis, contentMask,
        models, numModels, userName);
}

idCollisionQuery idCollisionQueryJobManager::SubmitRotationQuery(
    const idVec3& start, const idRotation& rotation, const idBounds&,
    const idTraceModel** trms, const int numTrms, const idMat3& trmAxis,
    const int contentMask, const idPositionedCollisionModel* models,
    const int numModels, const char*) {
    return SubmitSimple(queryData, TRACE_ROTATION, start, start, &rotation,
        idVec3(0, 0, 0), 0.0f, trms, numTrms, trmAxis,
        contentMask, models, numModels);
}

idCollisionQuery idCollisionQueryJobManager::SubmitMotionQuery(
    const idVec3& start, const idVec3& end, const idRotation& rotation,
    const idBounds& bounds, const idTraceModel** trms, const int numTrms,
    const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* models, const int numModels,
    const char* userName) {
    idCollisionQuery translation = SubmitTranslationQuery(start, end, bounds,
        trms, numTrms, trmAxis, contentMask, models, numModels, userName);
    idCollisionQuery rotationQuery = SubmitRotationQuery(start, rotation,
        bounds, trms, numTrms, trmAxis, contentMask,
        models, numModels, userName);
    pcQuerySlot_t* const finalSlot = new pcQuerySlot_t;
    finalSlot->hasSecondary = false;
    InitResult(finalSlot->primary, TRACE_TRANSLATION, end, trmAxis);
    idCollisionDetectionMerge::MergeMotionResults(
        reinterpret_cast<trace_t*>(finalSlot->primary.data),
        reinterpret_cast<trace_t*>(Slot(rotationQuery)->primary.data),
        reinterpret_cast<trace_t*>(Slot(translation)->primary.data));
    DestroyQuery(queryData, translation);
    DestroyQuery(queryData, rotationQuery);
    return MakeQuery(queryData, finalSlot);
}

idCollisionQuery idCollisionQueryJobManager::SubmitMotionContactsQuery(
    const idVec3& start, const idVec3& end, const idRotation& rotation,
    const float depth, const idBounds& bounds, const idTraceModel** trms,
    const int numTrms, const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* models, const int numModels,
    const char* userName) {
    idCollisionQuery motion = SubmitMotionQuery(start, end, rotation, bounds,
        trms, numTrms, trmAxis, contentMask, models, numModels, userName);
    pcQuerySlot_t* const slot = Slot(motion);
    const trace_t& trace = *reinterpret_cast<const trace_t*>(slot->primary.data);
    idCollisionQuery contacts = SubmitContactsQuery(trace.endpos,
        idVec3(0, 0, 0), depth, bounds, trms, numTrms, trace.endAxis,
        contentMask, models, numModels, userName);
    slot->secondary = Slot(contacts)->primary;
    slot->hasSecondary = true;
    DestroyQuery(queryData, contacts);
    return motion;
}

idCollisionQuery idCollisionQueryJobManager::SubmitContentsQuery(
    const idVec3& start, const idBounds&, const idTraceModel** trms,
    const int numTrms, const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* models, const int numModels,
    const char*) {
    const traceType_t type = trms == nullptr || numTrms == 0
        ? TRACE_CONTENTS_POINT : TRACE_CONTENTS;
    return SubmitSimple(queryData, type, start, start, nullptr,
        idVec3(0, 0, 0),
        0.0f, trms, numTrms, trmAxis, contentMask, models, numModels);
}

idCollisionQuery idCollisionQueryJobManager::SubmitLocalContentsQuery(
    idCollisionQuery localSpace, const idVec3& start,
    const idBounds& bounds, const idTraceModel** trms, const int numTrms,
    const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* models, const int numModels,
    const char* userName) {
    pcQuerySlot_t* const localSlot = OwnedSlot(queryData, localSpace);
    idVec3 transformedStart = start;
    idMat3 transformedAxis = trmAxis;
    if (localSlot != nullptr) {
        queryParms_t source{};
        source.start = source.end = start;
        source.trmAxis = trmAxis;
        queryParms_t transformed;
        idCollisionQueryExecute::SetupDependentParms(&transformed, &source,
            &localSlot->primary, DEPENDENCY_LOCAL_SPACE,
            &localSlot->primary, nullptr);
        transformedStart = transformed.start;
        transformedAxis = transformed.trmAxis;
    }
    return SubmitContentsQuery(transformedStart, bounds, trms, numTrms,
        transformedAxis, contentMask, models, numModels, userName);
}

idCollisionQuery idCollisionQueryJobManager::SubmitContactsQuery(
    const idVec3& start, const idVec3& direction, const float depth,
    const idBounds&, const idTraceModel** trms, const int numTrms,
    const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* models, const int numModels,
    const char*) {
    const traceType_t type = direction.LengthSqr() > 1.0e-12f
        ? TRACE_CONTACTS_UNI_DIR : TRACE_CONTACTS_OMNI_DIR;
    return SubmitSimple(queryData, type, start, start, nullptr,
        direction, depth,
        trms, numTrms, trmAxis, contentMask, models, numModels);
}

idCollisionQuery idCollisionQueryJobManager::SubmitClipQuery(
    const idVec3& start, const idBounds&, const idTraceModel** trms,
    const int numTrms, const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* models, const int numModels,
    const char*) {
    return SubmitSimple(queryData, TRACE_CLIP, start, start, nullptr,
        idVec3(0, 0, 0), 0.0f, trms, numTrms, trmAxis,
        contentMask, models, numModels);
}

idCollisionQuery idCollisionQueryJobManager::SubmitStepMoveQuery(
    const idVec3& start, const idVec3& end, const idVec3& downNormal,
    const float stepUp, const float stepDown, const idBounds& bounds,
    const idTraceModel** trms, const int numTrms, const idMat3& trmAxis,
    const int contentMask, const idPositionedCollisionModel* models,
    const int numModels, const char* userName) {
    const auto runTranslation = [&](const idVec3& from,
        const idVec3& to) {
        idCollisionQuery query = SubmitTranslationQuery(from, to, bounds,
            trms, numTrms, trmAxis, contentMask, models, numModels,
            userName);
        trace_t trace = *reinterpret_cast<const trace_t*>(
            Slot(query)->primary.data);
        DestroyQuery(queryData, query);
        return trace;
    };

    const trace_t forward1 = runTranslation(start, end);
    const idVec3 stepUpEnd = forward1.endpos
        - downNormal * stepUp;
    const trace_t up = runTranslation(forward1.endpos, stepUpEnd);
    const idVec3 remaining = (end - start)
        * (1.0f - forward1.fraction);
    const trace_t forward2 = runTranslation(up.endpos,
        up.endpos + remaining);
    const float climbed = stepUp * up.fraction;
    const trace_t down = runTranslation(forward2.endpos,
        forward2.endpos + downNormal * (climbed + stepDown));

    pcQuerySlot_t* const slot = new pcQuerySlot_t;
    slot->hasSecondary = false;
    InitResult(slot->primary, TRACE_TRANSLATION, end, trmAxis);
    idCollisionDetectionMerge::MergeStepMoveResults(
        reinterpret_cast<trace_t*>(slot->primary.data), &down,
        &forward2, &forward1, false);
    slot->primary.query.merged = 1;
    return MakeQuery(queryData, slot);
}

idCollisionQuery idCollisionQueryJobManager::SubmitStepMoveContactsQuery(
    const idVec3& start, const idVec3& end, const idVec3& downNormal,
    const float stepUp, const float stepDown, const idBounds& bounds,
    const idTraceModel** trms, const int numTrms, const idMat3& trmAxis,
    const int contentMask, const idPositionedCollisionModel* models,
    const int numModels, const char* userName) {
    idCollisionQuery query = SubmitStepMoveQuery(start, end, downNormal,
        stepUp, stepDown, bounds, trms, numTrms, trmAxis, contentMask,
        models, numModels, userName);
    pcQuerySlot_t* const slot = Slot(query);
    const trace_t& trace = *reinterpret_cast<const trace_t*>(slot->primary.data);
    idCollisionQuery contacts = SubmitContactsQuery(trace.endpos,
        downNormal, 0.5f, bounds, trms, numTrms, trace.endAxis,
        contentMask, models, numModels, userName);
    slot->secondary = Slot(contacts)->primary;
    slot->hasSecondary = true;
    DestroyQuery(queryData, contacts);
    return query;
}

idCollisionQuery idCollisionQueryJobManager::SubmitSlideMoveQuery(
    const idVec3& start, const idVec3& velocity,
    const idVec3& gravityVector, const float stepUp,
    const float stepDown, const idBounds& bounds,
    const idTraceModel** trms, const int numTrms, const idMat3& trmAxis,
    const int contentMask, const idPositionedCollisionModel* models,
    const int numModels, const char* userName) {
    slideMoveState_t state{};
    idCollisionDetectionMerge::InitSlideMoveState(&state, velocity,
        gravityVector);
    trace_t trace{};
    trace.fraction = 1.0f;
    trace.endpos = start;
    trace.endAxis = trmAxis;
    idVec3 current = start;
    idVec3 downDirection(0.0f, 0.0f, -1.0f);
    const float gravityLength = gravityVector.Length();
    if (gravityLength > 1.0e-6f) {
        downDirection = gravityVector * (1.0f / gravityLength);
    }
    for (int iteration = 0; iteration < 4
        && state.fractionRemaining > 0.0f; ++iteration) {
        const idVec3 target = current
            + state.velocity * state.fractionRemaining;
        idCollisionQuery step = SubmitStepMoveQuery(current, target,
            downDirection, stepUp, stepDown, bounds, trms, numTrms,
            trmAxis, contentMask, models, numModels, userName);
        trace = *reinterpret_cast<const trace_t*>(Slot(step)->primary.data);
        DestroyQuery(queryData, step);
        current = trace.endpos;
        if (idCollisionDetectionMerge::UpdateSlideMoveState(&state,
                &trace)) {
            break;
        }
    }
    trace.endpos = current;
    idCollisionDetectionMerge::FinishSlideMoveState(&state, &trace);

    pcQuerySlot_t* const slot = new pcQuerySlot_t;
    slot->hasSecondary = false;
    InitResult(slot->primary, TRACE_TRANSLATION, current, trmAxis);
    *reinterpret_cast<trace_t*>(slot->primary.data) = trace;
    slot->primary.query.merged = 1;
    return MakeQuery(queryData, slot);
}

idCollisionQuery idCollisionQueryJobManager::SubmitSlideMoveContactsQuery(
    const idVec3& start, const idVec3& velocity,
    const idVec3& gravityVector, const float stepUp, const float stepDown,
    const idBounds& bounds, const idTraceModel** trms, const int numTrms,
    const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* models, const int numModels,
    const char* userName) {
    idCollisionQuery query = SubmitSlideMoveQuery(start, velocity,
        gravityVector, stepUp, stepDown, bounds, trms, numTrms, trmAxis,
        contentMask, models, numModels, userName);
    pcQuerySlot_t* const slot = Slot(query);
    const trace_t& trace = *reinterpret_cast<const trace_t*>(slot->primary.data);
    idVec3 contactDirection(0.0f, 0.0f, -1.0f);
    const float gravityLength = gravityVector.Length();
    if (gravityLength > 1.0e-6f) {
        contactDirection = gravityVector * (1.0f / gravityLength);
    }
    idCollisionQuery contacts = SubmitContactsQuery(trace.endpos,
        contactDirection, 0.5f, bounds, trms, numTrms, trace.endAxis,
        contentMask, models, numModels, userName);
    slot->secondary = Slot(contacts)->primary;
    slot->hasSecondary = true;
    DestroyQuery(queryData, contacts);
    return query;
}

bool idCollisionQueryJobManager::GetRotationResult(idTraceWork*,
    trace_t* const result, idCollisionQuery& query, const bool peek) {
    pcQuerySlot_t* const slot = OwnedSlot(queryData, query);
    if (slot == nullptr || result == nullptr) {
        return false;
    }
    *result = *reinterpret_cast<const trace_t*>(slot->primary.data);
    if (!peek) {
        DestroyQuery(queryData, query);
    }
    return true;
}

bool idCollisionQueryJobManager::GetTraceResult(trace_t* const result,
    idCollisionQuery& query, const bool peek) {
    pcQuerySlot_t* const slot = OwnedSlot(queryData, query);
    if (slot == nullptr || result == nullptr) {
        return false;
    }
    *result = *reinterpret_cast<const trace_t*>(slot->primary.data);
    if (!peek) {
        DestroyQuery(queryData, query);
    }
    return true;
}

bool idCollisionQueryJobManager::GetContactsResult(
    contactsResult_t* const result, idCollisionQuery& query,
    const bool peek) {
    pcQuerySlot_t* const slot = OwnedSlot(queryData, query);
    if (slot == nullptr || result == nullptr) {
        return false;
    }
    result->CopyFrom(*reinterpret_cast<const contactsResult_t*>(
        slot->primary.data));
    if (!peek) {
        DestroyQuery(queryData, query);
    }
    return true;
}

bool idCollisionQueryJobManager::GetMotionContactsResult(idTraceWork*,
    trace_t* const result, contactsResult_t* const contacts,
    idCollisionQuery& query, const bool peek) {
    pcQuerySlot_t* const slot = OwnedSlot(queryData, query);
    if (slot == nullptr) {
        return false;
    }
    if (result != nullptr) {
        *result = *reinterpret_cast<const trace_t*>(slot->primary.data);
    }
    if (contacts != nullptr) {
        if (slot->hasSecondary) {
            contacts->CopyFrom(*reinterpret_cast<const contactsResult_t*>(
                slot->secondary.data));
        } else {
            contacts->numContacts = 0;
        }
    }
    if (!peek) {
        DestroyQuery(queryData, query);
    }
    return true;
}

bool idCollisionQueryJobManager::GetClipResult(idTraceWork*,
    clipResult_t* const result, idCollisionQuery& query, const bool peek) {
    pcQuerySlot_t* const slot = OwnedSlot(queryData, query);
    if (slot == nullptr || result == nullptr) {
        return false;
    }
    *result = *reinterpret_cast<const clipResult_t*>(slot->primary.data);
    if (!peek) {
        DestroyQuery(queryData, query);
    }
    return true;
}

bool idCollisionQueryJobManager::GetSlideMoveContactsResult(idTraceWork* tw,
    trace_t* result, contactsResult_t* contacts, idCollisionQuery& query,
    const bool peek) {
    return GetMotionContactsResult(tw, result, contacts, query, peek);
}

void idCollisionQueryJobManager::ShowDebugInfo() {
    // Profiling accumulators are retained in the recovered layout.  Console
    // presentation belongs to the later renderer/console integration.
}

void idCollisionQueryJobManager::StartFrame() {
    if (queryData != nullptr) {
        queryData->StartFrame();
    }
}

void idCollisionQueryJobManager::EndFrame() {
    if (queryData != nullptr) {
        queryData->EndFrame();
    }
}

void idCollisionQueryJobManager::SubmitQueries() {
    if (queryData != nullptr) {
        queryData->ReleaseQueryOnlyData();
    }
    ++queryFrameNumber;
    // Synchronous PC submissions are complete before this fence is reached.
}

void CollisionMergeJob(modelQuery_t* const query) {
    if (query == nullptr || query->finalResultsPtr == nullptr) {
        return;
    }
    idCollisionDetectionMerge::MergeQueryResults(query->finalResultsPtr,
        query->resultSize, query->type, query->mergeResults,
        query->numMergeResults, query->slideMoveState,
        query->dependencyType, query->dependency1, query->dependency2);
    query->finalResultsPtr->query.mergeThreadId = 0;
    query->finalResultsPtr->query.merged = 1;
}

void CollisionExecuteJob(modelQuery_t* const query) {
    if (query == nullptr || query->parms == nullptr
        || query->resultsPtr == nullptr) {
        return;
    }
    queryParms_t parms{};
    idCollisionQueryExecute::SetupDependentParms(&parms, query->parms,
        query->modelPosition, query->dependencyType, query->dependency1,
        query->dependency2);
    if (query->modelType == CM_POLYGONMODEL
        && query->polygonModel != nullptr) {
        idTraceWork work;
        work.Init();
        idCollisionQueryExecute::ExecutePolygonModelQuery(&work,
            *query->resultsPtr, &parms, query->trm, query->polygonModel);
    } else if (query->modelType == CM_SPHEREMODEL
        && query->sphereModel != nullptr) {
        idCollisionQueryExecute::ExecuteSphereModelQuery(*query->resultsPtr,
            &parms, query->modelJoints, query->sphereModel);
    }
    query->resultsPtr->query.executeThreadId = 0;
    query->resultsPtr->query.done = 1;
}

bool idCollisionQueryJobManager::WaitForQueryResults(
    queryResults_t* const results) {
    return results != nullptr && results->query.done != 0;
}

modelQuery_t* idCollisionQueryJobManager::AllocModelQuery(
    const idPositionedCollisionModel& model) {
    if (queryData == nullptr || model.model == nullptr) {
        return nullptr;
    }
    const idCollisionModelLocal* const local =
        dynamic_cast<const idCollisionModelLocal*>(model.model);
    if (local == nullptr) {
        return nullptr;
    }
    modelQuery_t* const query = queryData->AllocModelQuery();
    queryParms_t* const parms = queryData->AllocQueryParms();
    if (query == nullptr || parms == nullptr) {
        return nullptr;
    }
    query->parms = parms;
    query->modelType = local->modelType;
    query->polygonModel = &local->polygonModel;
    query->sphereModel = local->sphereModel;
    query->modelJoints = model.modelJoints;
    query->resultsPtr = dummyQueryResults;
    query->finalResultsPtr = dummyQueryResults;
    query->mergeResults = dummyQueryResults;
    query->executePriority = 1023;
    query->mergePriority = 1023;
    query->frameNumber = queryFrameNumber;
    query->parms->modelOrigin = model.modelOrigin;
    query->parms->modelAxis = model.modelAxis;
    query->parms->modelEntityNum = model.modelEntityNum;
    query->parms->modelPhysicsId = model.modelPhysicsId;
    query->parms->modelBodyId = model.modelBodyId;
    query->parms->modelContentsOverride = model.modelContentsOverride;
    return query;
}

idCollisionQuery idCollisionQueryJobManager::AllocFinishedFinalResult(
    const traceType_t firstType, const traceType_t,
    const idVec3& endPosition, const idMat3& endAxis, const char*) {
    pcQuerySlot_t* const slot = new pcQuerySlot_t;
    slot->hasSecondary = false;
    InitResult(slot->primary, firstType, endPosition, endAxis);
    slot->primary.query.merged = 1;
    return MakeQuery(queryData, slot);
}

idCollisionQuery idCollisionQueryJobManager::AddModelQueryToMergeList(
    modelQuery_t* const modelQuery, const int mergePriority,
    slideMoveState_t* const slideMoveState) {
    if (modelQuery == nullptr) {
        return idCollisionQuery{0};
    }
    pcQuerySlot_t* const slot = new pcQuerySlot_t;
    slot->hasSecondary = false;
    InitResult(slot->primary, modelQuery->type,
        modelQuery->parms != nullptr ? modelQuery->parms->end
            : idVec3(0.0f, 0.0f, 0.0f),
        modelQuery->parms != nullptr ? modelQuery->parms->trmAxis
            : idMat3());
    modelQuery->mergePriority = mergePriority;
    modelQuery->slideMoveState = slideMoveState;
    modelQuery->finalResultsPtr = &slot->primary;
    CollisionMergeJob(modelQuery);
    return MakeQuery(queryData, slot);
}

void idCollisionQueryJobManager::AddModelQueryToExecuteList(
    modelQuery_t* const modelQuery, const idCollisionQuery modelPosition,
    const idCollisionQuery dependency1, const idCollisionQuery dependency2,
    const dependencyType_t dependencyType, const idVec3& globalStart,
    const idVec3& globalEnd, const idBounds&, int& executePriority) {
    if (modelQuery == nullptr) {
        return;
    }
    pcQuerySlot_t* const modelPositionSlot =
        OwnedSlot(queryData, modelPosition);
    pcQuerySlot_t* const dependency1Slot =
        OwnedSlot(queryData, dependency1);
    pcQuerySlot_t* const dependency2Slot =
        OwnedSlot(queryData, dependency2);
    modelQuery->modelPosition = modelPositionSlot != nullptr
        ? &modelPositionSlot->primary : nullptr;
    modelQuery->dependency1 = dependency1Slot != nullptr
        ? &dependency1Slot->primary : nullptr;
    modelQuery->dependency2 = dependency2Slot != nullptr
        ? &dependency2Slot->primary : nullptr;
    modelQuery->dependencyType = dependencyType;
    modelQuery->executePriority = executePriority++;
    if (modelQuery->parms != nullptr) {
        modelQuery->parms->start = globalStart;
        modelQuery->parms->end = globalEnd;
    }
    CollisionExecuteJob(modelQuery);
}

void idCollisionQueryJobManager::CreateMergeJobs(idParallelJobList*,
    modelQuery_t* modelQuery) {
    for (; modelQuery != nullptr;
         modelQuery = modelQuery->nextInMergeList) {
        if (modelQuery->mergePriority != 1023) {
            CollisionMergeJob(modelQuery);
        }
    }
}

void idCollisionQueryJobManager::CreateExecuteJobs(idParallelJobList*,
    modelQuery_t* modelQuery) {
    for (; modelQuery != nullptr;
         modelQuery = modelQuery->nextInExecuteList) {
        if (modelQuery->executePriority != 1023) {
            CollisionExecuteJob(modelQuery);
        }
    }
}
