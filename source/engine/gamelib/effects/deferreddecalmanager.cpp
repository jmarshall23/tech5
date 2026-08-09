#include "gamelib/effects/deferreddecalmanager.h"

#include "gamelib/physics/physics.h"
#include "idlib/lib_print.h"

idClipQuery GameLib_SubmitDeferredDecalLineTrace(idClip* clip,
    const idVec3& start, const idVec3& end, int clipMask);
bool GameLib_GetDeferredDecalLineTraceResult(idClip* clip,
    idClipQuery& query, trace_t& result);
void GameLib_AddDeferredDecalFromPoint(idRenderModelDecal* decalModel,
    const deferredDecalParams_t& parameters, int time,
    const idVec3& origin, const idVec3& normal);

namespace {

constexpr std::uint64_t RECOVERED_EMPTY_CLIP_QUERY = 0x000007D000000000ULL;

} // namespace

idDeferredDecalQuery::idDeferredDecalQuery() {
    Reset();
}

void idDeferredDecalQuery::Reset() {
    theQuery.index = RECOVERED_EMPTY_CLIP_QUERY;
    decalParams.decalMat = nullptr;
    decalParams.depth = 8.0f;
    decalParams.size.Set(32.0f, 32.0f);
    decalParams.angle = 0.0f;
    decalParams.lifetime = 10000;
    decalParams.fadetime = 2000;
    decalParams.fadeInEndTime = 0;
    origin.Zero();
    normal.Zero();
}

idDeferredDecalManager::idDeferredDecalManager()
    : lineQueries{}
    , numLineQueries(0)
    , clip(nullptr)
    , decalModel(nullptr) {
}

void idDeferredDecalManager::Init(idClip* const clip_,
    idRenderModelDecal* const decalModel_) {
    clip = clip_;
    decalModel = decalModel_;
}

void idDeferredDecalManager::Shutdown() {
    numLineQueries = 0;
    clip = nullptr;
    decalModel = nullptr;
    for (idDeferredDecalQuery& query : lineQueries) {
        query.Reset();
    }
}

void idDeferredDecalManager::AddDecalFromLineTrace(
    const deferredDecalParams_t* const decalParameters,
    const idVec3& start, const idVec3& end, const int clipMask) {
    if (clip == nullptr || decalModel == nullptr) {
        return;
    }
    if (numLineQueries >= 16) {
        idLibPrint::Warning("Too many deferred decal queries this frame!");
        return;
    }
    if (decalParameters == nullptr || decalParameters->decalMat == nullptr) {
        idLibPrint::Warning(
            "Null decal passed in to  "
            "idDeferredDecalManager::AddDecalFromLineTrace");
        return;
    }

    idDeferredDecalQuery& query = lineQueries[numLineQueries];
    query.Reset();
    query.theQuery = GameLib_SubmitDeferredDecalLineTrace(
        clip, start, end, clipMask);
    query.decalParams = *decalParameters;
    ++numLineQueries;
}

void idDeferredDecalManager::AddDecalFromPoint(
    const deferredDecalParams_t* const decalParameters, const int time,
    const idVec3& origin, const idVec3& normal) {
    if (clip == nullptr || decalModel == nullptr) {
        return;
    }
    if (decalParameters == nullptr || decalParameters->decalMat == nullptr) {
        idLibPrint::Warning(
            "Null decal passed in to  "
            "idDeferredDecalManager::AddDecalFromLineTrace");
        return;
    }

    GameLib_AddDeferredDecalFromPoint(
        decalModel, *decalParameters, time, origin, normal);
}

void idDeferredDecalManager::Update(const int time) {
    if (clip == nullptr || decalModel == nullptr) {
        return;
    }

    for (int index = 0; index < numLineQueries; ++index) {
        idDeferredDecalQuery& query = lineQueries[index];
        trace_t result{};
        if (GameLib_GetDeferredDecalLineTraceResult(
                clip, query.theQuery, result) && result.fraction < 1.0f) {
            AddDecalFromPoint(&query.decalParams, time,
                result.endpos, result.c.normal);
        }
        query.Reset();
    }
    numLineQueries = 0;
}
