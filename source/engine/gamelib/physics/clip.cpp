#include "gamelib/physics/clip.h"

#include "cm/collisionmodel.h"
#include "cm/collisionmodelmanager.h"
#include "gamelib/aas2/aas2.h"
#include "gamelib/physics/tracemodelcache.h"
#include "gamelib/physics/tracemodelrecycler.h"
#include "idlib/geometry/tracemodel.h"
#include "idlib/geometry/winding.h"

#include <algorithm>
#include <cstring>
#include <vector>

namespace {

bool BoundsIntersect(const idBounds& first, const idBounds& second) {
    for (int axis = 0; axis < 3; ++axis) {
        if (first[1][axis] < second[0][axis]
            || first[0][axis] > second[1][axis]) return false;
    }
    return true;
}

idBounds PointBounds(const idVec3& point) {
    idBounds result;
    result[0] = point;
    result[1] = point;
    return result;
}

idBounds MotionBounds(const idVec3& start, const idVec3& end,
        const idClipModel* const model, const idMat3& axis) {
    idBounds result;
    if (model != nullptr) {
        result.FromTransformedBounds(model->GetBounds(), start, axis);
        idBounds endBounds;
        endBounds.FromTransformedBounds(model->GetBounds(), end, axis);
        for (int component = 0; component < 3; ++component) {
            result[0][component] = (std::min)(result[0][component],
                endBounds[0][component]);
            result[1][component] = (std::max)(result[1][component],
                endBounds[1][component]);
        }
    } else {
        result[0].Set((std::min)(start.x, end.x),
            (std::min)(start.y, end.y), (std::min)(start.z, end.z));
        result[1].Set((std::max)(start.x, end.x),
            (std::max)(start.y, end.y), (std::max)(start.z, end.z));
    }
    return result;
}

void CollectTraceModels(const idClipModel* const model,
        std::vector<const idTraceModel*>& output) {
    if (model == nullptr) return;
    for (int index = 0; index < model->GetNumTraceModels(); ++index) {
        const idTraceModel* const traceModel = model->GetTraceModel(index);
        if (traceModel != nullptr) output.push_back(traceModel);
    }
}

void AppendPositionedModel(const idClipModel* const model,
        std::vector<idPositionedCollisionModel>& output) {
    if (model == nullptr || !model->IsEnabled() || model->IsDeleted()) return;
    idCollisionModel* const collisionModel = model->GetCollisionModel();
    if (collisionModel == nullptr) return;
    idPositionedCollisionModel positioned{};
    positioned.model = collisionModel;
    positioned.modelJoints = nullptr;
    positioned.modelOrigin = model->GetOrigin();
    positioned.modelAxis = model->GetAxis();
    positioned.modelEntityNum = model->GetEntityNumber();
    positioned.modelPhysicsId = model->GetPhysicsId();
    positioned.modelBodyId = model->GetBodyId();
    positioned.modelContentsOverride = model->GetContents();
    positioned.modelQuery = model->collisionQuery;
    output.push_back(positioned);
}

void CollectPositionedModels(const idClip& clip, const int contentMask,
        const int passEntityNumber, const bool ignoreWorld,
        std::vector<idPositionedCollisionModel>& output) {
    if (!ignoreWorld && clip.world != nullptr
        && (clip.world->GetContents() & contentMask) != 0) {
        AppendPositionedModel(clip.world, output);
    }
    if (clip.clipSectors.IsEmpty()) return;
    for (clipLink_t* link = clip.clipSectors[0].clipLinks;
         link != nullptr; link = link->nextInSector) {
        idClipModel* const model = link->clipModel;
        if (model == nullptr || model == clip.world
            || model->GetEntityNumber() == passEntityNumber
            || (model->GetContents() & contentMask) == 0) continue;
        AppendPositionedModel(model, output);
    }
}

idClipQuery ToClipQuery(const idCollisionQuery query) {
    idClipQuery result{};
    result.index = query.offset;
    return result;
}

idCollisionQuery ToCollisionQuery(const idClipQuery query) {
    idCollisionQuery result{};
    result.offset = query.index;
    return result;
}

idClipModel* FindLinkedModel(const idClip& clip, const int entityNumber,
        const int physicsId, const int bodyId) {
    if (clip.world != nullptr && clip.world->GetEntityNumber() == entityNumber
        && clip.world->GetPhysicsId() == physicsId
        && clip.world->GetBodyId() == bodyId) return clip.world;
    if (clip.clipSectors.IsEmpty()) return nullptr;
    for (clipLink_t* link = clip.clipSectors[0].clipLinks;
         link != nullptr; link = link->nextInSector) {
        idClipModel* const model = link->clipModel;
        if (model != nullptr && model->GetEntityNumber() == entityNumber
            && model->GetPhysicsId() == physicsId
            && model->GetBodyId() == bodyId) return model;
    }
    return nullptr;
}

} // namespace

idClip::idClip()
    : world(nullptr), temporaryClipModel(nullptr), defaultClipModel(nullptr),
      playerMeleeClipModel(nullptr), clip8x8(nullptr), clip8x8x8(nullptr),
      clip16x16(nullptr), clip16x16x16(nullptr), clip24x24(nullptr),
      clip32x32(nullptr), clip8x16(nullptr), clip48x48(nullptr),
      clip96x96(nullptr), clip24x24x96(nullptr), clip32x32x96(nullptr),
      clip48x48x96(nullptr), clipLinkAllocator(false), clipSectors(),
      touchCount(0), aases{}, traceModelCache(nullptr),
      traceModelRecycler(nullptr), deletedClipModels(nullptr), streamAreas(),
      queryParms(nullptr), numQueryParms(0), translationQueries(),
      rotationQueries(), motionQueries(), motionContactsQueries(),
      stepMoveQueries(), stepMoveContactsQueries(), slideMoveQueries(),
      slideMoveContactsQueries(), contentsQueries(), contactsQueries(),
      clipQueries(), localTranslationQueries(), localContentsQueries(),
      translationTraceModelQueries(), collisionQueries{},
      collisionQueryFirstSubmittedIndex(0), collisionQueryLastSubmittedIndex(0),
      collisionQueryFirstAllocedIndex(0), collisionQueryLastAllocedIndex(0),
      collisionQueryLastResolvedIndex(0), gatherQueryUserNames{},
      gatherQueries{}, gatherQueryFirstSubmittedIndex(0),
      gatherQueryLastSubmittedIndex(0), gatherQueryFirstAllocedIndex(0),
      gatherQueryLastAllocedIndex(0), gatherResults{},
      gatherResultFirstSubmittedIndex(0), gatherResultLastSubmittedIndex(0),
      gatherResultFirstAllocedIndex(0), gatherResultLastAllocedIndex(0),
      residencyQueries{}, residencyQueryFirstSubmittedIndex(0),
      residencyQueryLastSubmittedIndex(0), residencyQueryFirstAllocedIndex(0),
      residencyQueryLastAllocedIndex(0) {
}

idClip::~idClip() {
    Shutdown();
}

void idClip::Init(idCollisionModel* const worldModel,
        idTraceModelCache* const cache, idTraceModelRecycler* const recycler) {
    Shutdown();
    traceModelCache = cache;
    traceModelRecycler = recycler;
    clipSectors.SetNum(1);
    clipSectors[0].axis = -1;
    clipSectors[0].dist = 0.0f;
    clipSectors[0].children[0] = nullptr;
    clipSectors[0].children[1] = nullptr;
    clipSectors[0].clipLinks = nullptr;
    if (worldModel != nullptr) {
        world = new idClipModel(this, worldModel);
        world->Link(0, -1, 0, idVec3(), idMat3(1.0f));
    }
}

void idClip::Shutdown() {
    DeleteClipModels();
    if (world != nullptr) {
        idClipModel* const oldWorld = world;
        world = nullptr;
        delete oldWorld;
    }
    clipSectors.SetNum(0);
    clipLinkAllocator.Shutdown();
    streamAreas.ClearFree();
    delete[] queryParms;
    queryParms = nullptr;
    numQueryParms = 0;
    traceModelCache = nullptr;
    traceModelRecycler = nullptr;
    deletedClipModels = nullptr;
}

void idClip::StartQueryFrame() {
    collisionModelManager.StartQueryFrame();
}

void idClip::EndQueryFrame() {
    ResolveCollisionQueries();
    collisionModelManager.EndQueryFrame();
    DeleteClipModels();
}

void idClip::ResolveCollisionQueries() {
    collisionModelManager.WaitForAllQueries();
    collisionQueryLastResolvedIndex = collisionQueryLastSubmittedIndex;
}

void idClip::DeleteClipModel(idClipModel* const clipModel) {
    if (clipModel == nullptr || clipModel == world) return;
    clipModel->Unlink();
    clipModel->nextDeleted = deletedClipModels;
    deletedClipModels = clipModel;
}

void idClip::DeleteClipModels() {
    while (deletedClipModels != nullptr) {
        idClipModel* const model = deletedClipModels;
        deletedClipModels = model->nextDeleted;
        model->nextDeleted = nullptr;
        delete model;
    }
}

void idClip::InitializeAASLinks(const int aasType) {
    if (aasType < 0 || aasType >= 8 || aases[aasType] == nullptr
        || clipSectors.IsEmpty()) return;
    for (clipLink_t* link = clipSectors[0].clipLinks;
         link != nullptr; link = link->nextInSector) {
        idClipModel* const model = link->clipModel;
        if (model != nullptr && model->aasLinks[aasType] == nullptr)
            model->aasLinks[aasType] = aases[aasType]->LinkClipModel(model);
    }
}

const idBounds& idClip::GetWorldBounds() const {
    static idBounds emptyBounds{};
    return world != nullptr ? world->GetBounds() : emptyBounds;
}

void idClip::AddStreamArea(const int areaNum) {
    if (streamAreas.FindIndex(areaNum) < 0) streamAreas.Append(areaNum);
}

void idClip::ClearStreamAreas() {
    streamAreas.Clear();
}

int idClip::FindStreamArea(const idClipModel*) {
    return streamAreas.IsEmpty() ? -1 : streamAreas[0];
}

int idClip::GetClipModelsTouchingBounds(const idBounds& queryBounds,
        const int contentMask, idClipModel** const output,
        const int maxOutput) const {
    if (output == nullptr || maxOutput <= 0 || clipSectors.IsEmpty()) return 0;
    int count = 0;
    for (clipLink_t* link = clipSectors[0].clipLinks;
         link != nullptr && count < maxOutput; link = link->nextInSector) {
        idClipModel* const model = link->clipModel;
        if (model == nullptr || !model->IsEnabled()
            || (model->GetContents() & contentMask) == 0
            || !BoundsIntersect(queryBounds, model->GetAbsBounds())) continue;
        output[count++] = model;
    }
    return count;
}

int idClip::GetClipModelsTouchingLine(const idVec3& start,
        const idVec3& end, const int contentMask,
        idClipModel** const output, const int maxOutput) const {
    if (output == nullptr || maxOutput <= 0 || clipSectors.IsEmpty()) return 0;
    int count = 0;
    for (clipLink_t* link = clipSectors[0].clipLinks;
         link != nullptr && count < maxOutput; link = link->nextInSector) {
        idClipModel* const model = link->clipModel;
        if (model == nullptr || !model->IsEnabled()
            || (model->GetContents() & contentMask) == 0
            || !model->GetAbsBounds().LineIntersection(start, end)) continue;
        output[count++] = model;
    }
    return count;
}

int idClip::GetEntitiesTouchingBounds(const idBounds& bounds,
        const int contentMask, int* const entities,
        const int maxEntities) const {
    if (entities == nullptr || maxEntities <= 0) return 0;
    std::vector<idClipModel*> models(static_cast<std::size_t>(maxEntities));
    const int modelCount = GetClipModelsTouchingBounds(bounds, contentMask,
        models.data(), maxEntities);
    int count = 0;
    for (int index = 0; index < modelCount; ++index) {
        const int entity = models[index]->GetEntityNumber();
        bool duplicate = false;
        for (int other = 0; other < count; ++other)
            if (entities[other] == entity) duplicate = true;
        if (!duplicate) entities[count++] = entity;
    }
    return count;
}

int idClip::GetEntitiesTouchingLine(const idVec3& start,
        const idVec3& end, const int contentMask, int* const entities,
        const int maxEntities) const {
    if (entities == nullptr || maxEntities <= 0) return 0;
    std::vector<idClipModel*> models(static_cast<std::size_t>(maxEntities));
    const int modelCount = GetClipModelsTouchingLine(start, end, contentMask,
        models.data(), maxEntities);
    int count = 0;
    for (int index = 0; index < modelCount; ++index) {
        const int entity = models[index]->GetEntityNumber();
        bool duplicate = false;
        for (int other = 0; other < count; ++other)
            if (entities[other] == entity) duplicate = true;
        if (!duplicate) entities[count++] = entity;
    }
    return count;
}

idGatherQuery idClip::GatherTouchingBounds(const idBounds& bounds,
        const int contentMask, const int passEntityNumber,
        const char* const userName) {
    const std::uint64_t queryIndex = gatherQueryLastSubmittedIndex++;
    idClipGatherQuery& query = gatherQueries[queryIndex & 255];
    query.vectors[0] = bounds[0];
    query.vectors[1] = bounds[1];
    query.clipMask = contentMask;
    query.passEntityNumber = static_cast<std::int16_t>(passEntityNumber);
    query.gatherType = GATHER_TOUCHING_BOUNDS;
    query.firstResultIndex = static_cast<std::uint16_t>(
        gatherResultLastSubmittedIndex & 2047);
    idClipModel* models[2048];
    const int count = GetClipModelsTouchingBounds(bounds, contentMask,
        models, 2048);
    query.numResults = static_cast<std::uint16_t>(count);
    for (int index = 0; index < count; ++index) {
        idGatherResult& result = gatherResults[
            gatherResultLastSubmittedIndex++ & 2047];
        result.query = models[index]->collisionQuery;
        result.physicsId = models[index]->GetPhysicsId();
        result.bodyId = static_cast<std::int16_t>(models[index]->GetBodyId());
        result.entityNumber = static_cast<std::int16_t>(
            models[index]->GetEntityNumber());
    }
    gatherQueryUserNames[queryIndex & 255] = userName;
    return idGatherQuery{queryIndex};
}

idGatherQuery idClip::GatherTouchingClipModel(const idVec3& origin,
        const idClipModel* const model, const idMat3& axis,
        const int contentMask, const int passEntityNumber,
        const char* const userName) {
    idBounds bounds = PointBounds(origin);
    if (model != nullptr)
        bounds.FromTransformedBounds(model->GetBounds(), origin, axis);
    return GatherTouchingBounds(bounds, contentMask, passEntityNumber,
        userName);
}

int idClip::GetGatheredClipModels(const idGatherQuery& handle,
        idClipModel** const output, const int maxOutput) {
    if (output == nullptr || maxOutput <= 0
        || handle.index >= gatherQueryLastSubmittedIndex) return 0;
    const idClipGatherQuery& query = gatherQueries[handle.index & 255];
    const int count = (std::min)(maxOutput,
        static_cast<int>(query.numResults));
    int outputCount = 0;
    for (int index = 0; index < count; ++index) {
        const idGatherResult& result = gatherResults[
            (query.firstResultIndex + index) & 2047];
        idClipModel* const model = FindLinkedModel(*this,
            result.entityNumber, result.physicsId, result.bodyId);
        if (model != nullptr) output[outputCount++] = model;
    }
    return outputCount;
}

int idClip::GetGatheredEntities(const idGatherQuery& handle,
        int* const output, const int maxOutput) {
    if (output == nullptr || maxOutput <= 0
        || handle.index >= gatherQueryLastSubmittedIndex) return 0;
    const idClipGatherQuery& query = gatherQueries[handle.index & 255];
    int count = 0;
    for (int index = 0; index < query.numResults && count < maxOutput;
         ++index) {
        const int entity = gatherResults[
            (query.firstResultIndex + index) & 2047].entityNumber;
        bool duplicate = false;
        for (int other = 0; other < count; ++other)
            if (output[other] == entity) duplicate = true;
        if (!duplicate) output[count++] = entity;
    }
    return count;
}

idResidencyQuery idClip::TestResidency(const idBounds& bounds) {
    const std::uint64_t index = residencyQueryLastSubmittedIndex++;
    idClipResidencyQuery& query = residencyQueries[index & 1023];
    query.absBounds = bounds;
    query.resident = true;
    return idResidencyQuery{index};
}

idClipQuery idClip::Translation(trace_t* const result,
        const idVec3& start, const idVec3& end,
        const idClipModel* const movingModel, const idMat3& axis,
        const int contentMask, const int passEntityNumber,
        const bool ignoreWorld, const char* const userName) {
    std::vector<const idTraceModel*> traceModels;
    std::vector<idPositionedCollisionModel> models;
    CollectTraceModels(movingModel, traceModels);
    CollectPositionedModels(*this, contentMask, passEntityNumber,
        ignoreWorld, models);
    const idBounds bounds = MotionBounds(start, end, movingModel, axis);
    return ToClipQuery(collisionModelManager.Translation(result, start, end,
        bounds, traceModels.empty() ? nullptr : traceModels.data(),
        static_cast<int>(traceModels.size()), axis, contentMask,
        models.empty() ? nullptr : models.data(),
        static_cast<int>(models.size()), userName));
}

idClipQuery idClip::LocalTranslation(const idClipQuery localSpace,
        const idVec3& start, const idVec3& end,
        const idClipModel* const movingModel, const idMat3& axis,
        const int contentMask, const int passEntityNumber,
        const bool ignoreWorld, const char* const userName) {
    std::vector<const idTraceModel*> traceModels;
    std::vector<idPositionedCollisionModel> models;
    CollectTraceModels(movingModel, traceModels);
    CollectPositionedModels(*this, contentMask, passEntityNumber,
        ignoreWorld, models);
    const idBounds bounds = MotionBounds(start, end, movingModel, axis);
    return ToClipQuery(collisionModelManager.LocalTranslation(
        ToCollisionQuery(localSpace), start, end, bounds,
        traceModels.empty() ? nullptr : traceModels.data(),
        static_cast<int>(traceModels.size()), axis, contentMask,
        models.empty() ? nullptr : models.data(),
        static_cast<int>(models.size()), userName));
}

idClipQuery idClip::TranslationTraceModel(trace_t* const result,
        const idVec3& start, const idVec3& end,
        const idClipModel* const movingModel, const idVec3& modelOrigin,
        const idMat3& modelAxis, const int contentMask,
        const char* const userName) {
    std::vector<const idTraceModel*> traceModels;
    CollectTraceModels(movingModel, traceModels);
    idPositionedCollisionModel positioned{};
    positioned.model = movingModel != nullptr
        ? movingModel->GetCollisionModel() : nullptr;
    positioned.modelOrigin = modelOrigin;
    positioned.modelAxis = modelAxis;
    positioned.modelContentsOverride = contentMask;
    const idBounds bounds = MotionBounds(start, end, movingModel, modelAxis);
    return ToClipQuery(collisionModelManager.Translation(result, start, end,
        bounds, traceModels.empty() ? nullptr : traceModels.data(),
        static_cast<int>(traceModels.size()), modelAxis, contentMask,
        positioned.model != nullptr ? &positioned : nullptr,
        positioned.model != nullptr ? 1 : 0, userName));
}

idClipQuery idClip::Rotation(trace_t* const result, const idVec3& start,
        const idRotation& rotation, const idClipModel* const movingModel,
        const idMat3& axis, const int contentMask,
        const int passEntityNumber, const bool ignoreWorld,
        const char* const userName) {
    std::vector<const idTraceModel*> traceModels;
    std::vector<idPositionedCollisionModel> models;
    CollectTraceModels(movingModel, traceModels);
    CollectPositionedModels(*this, contentMask, passEntityNumber,
        ignoreWorld, models);
    const idBounds bounds = MotionBounds(start, start, movingModel, axis);
    return ToClipQuery(collisionModelManager.Rotation(result, start,
        rotation, bounds,
        traceModels.empty() ? nullptr : traceModels.data(),
        static_cast<int>(traceModels.size()), axis, contentMask,
        models.empty() ? nullptr : models.data(),
        static_cast<int>(models.size()), userName));
}

idClipQuery idClip::Motion(trace_t* const result, const idVec3& start,
        const idVec3& end, const idRotation& rotation,
        const idClipModel* const movingModel, const idMat3& axis,
        const int contentMask, const int passEntityNumber,
        const bool ignoreWorld, const char* const userName) {
    std::vector<const idTraceModel*> traceModels;
    std::vector<idPositionedCollisionModel> models;
    CollectTraceModels(movingModel, traceModels);
    CollectPositionedModels(*this, contentMask, passEntityNumber,
        ignoreWorld, models);
    const idBounds bounds = MotionBounds(start, end, movingModel, axis);
    return ToClipQuery(collisionModelManager.Motion(result, start, end,
        rotation, bounds,
        traceModels.empty() ? nullptr : traceModels.data(),
        static_cast<int>(traceModels.size()), axis, contentMask,
        models.empty() ? nullptr : models.data(),
        static_cast<int>(models.size()), userName));
}

idClipQuery idClip::MotionContacts(trace_t* const result,
        contactsResult_t* const contacts, const idVec3& start,
        const idVec3& end, const idRotation& rotation, const float depth,
        const idClipModel* const movingModel, const idMat3& axis,
        const int contentMask, const int passEntityNumber,
        const bool ignoreWorld, const char* const userName) {
    std::vector<const idTraceModel*> traceModels;
    std::vector<idPositionedCollisionModel> models;
    CollectTraceModels(movingModel, traceModels);
    CollectPositionedModels(*this, contentMask, passEntityNumber,
        ignoreWorld, models);
    const idBounds bounds = MotionBounds(start, end, movingModel, axis);
    return ToClipQuery(collisionModelManager.MotionContacts(result, contacts,
        start, end, rotation, depth, bounds,
        traceModels.empty() ? nullptr : traceModels.data(),
        static_cast<int>(traceModels.size()), axis, contentMask,
        models.empty() ? nullptr : models.data(),
        static_cast<int>(models.size()), userName));
}

idClipQuery idClip::StepMove(trace_t* const result, const idVec3& start,
        const idVec3& end, const idVec3& downNormal, const float stepUp,
        const float stepDown, const idClipModel* const movingModel,
        const idMat3& axis, const int contentMask,
        const int passEntityNumber, const bool ignoreWorld,
        const char* const userName) {
    std::vector<const idTraceModel*> traceModels;
    std::vector<idPositionedCollisionModel> models;
    CollectTraceModels(movingModel, traceModels);
    CollectPositionedModels(*this, contentMask, passEntityNumber,
        ignoreWorld, models);
    const idBounds bounds = MotionBounds(start, end, movingModel, axis);
    return ToClipQuery(collisionModelManager.StepMove(result, start, end,
        downNormal, stepUp, stepDown, bounds,
        traceModels.empty() ? nullptr : traceModels.data(),
        static_cast<int>(traceModels.size()), axis, contentMask,
        models.empty() ? nullptr : models.data(),
        static_cast<int>(models.size()), userName));
}

idClipQuery idClip::StepMoveContacts(trace_t* const result,
        contactsResult_t* const contacts, const idVec3& start,
        const idVec3& end, const idVec3& downNormal, const float stepUp,
        const float stepDown, const idClipModel* const movingModel,
        const idMat3& axis, const int contentMask,
        const int passEntityNumber, const bool ignoreWorld,
        const char* const userName) {
    std::vector<const idTraceModel*> traceModels;
    std::vector<idPositionedCollisionModel> models;
    CollectTraceModels(movingModel, traceModels);
    CollectPositionedModels(*this, contentMask, passEntityNumber,
        ignoreWorld, models);
    const idBounds bounds = MotionBounds(start, end, movingModel, axis);
    return ToClipQuery(collisionModelManager.StepMoveContacts(result,
        contacts, start, end, downNormal, stepUp, stepDown, bounds,
        traceModels.empty() ? nullptr : traceModels.data(),
        static_cast<int>(traceModels.size()), axis, contentMask,
        models.empty() ? nullptr : models.data(),
        static_cast<int>(models.size()), userName));
}

idClipQuery idClip::SlideMoveContacts(trace_t* const result,
        contactsResult_t* const contacts, const idVec3& start,
        const idVec3& velocity, const idVec3& gravityVector,
        const float stepUp, const idClipModel* const movingModel,
        const idMat3& axis, const int contentMask,
        const int passEntityNumber, const bool ignoreWorld,
        const char* const userName) {
    std::vector<const idTraceModel*> traceModels;
    std::vector<idPositionedCollisionModel> models;
    CollectTraceModels(movingModel, traceModels);
    CollectPositionedModels(*this, contentMask, passEntityNumber,
        ignoreWorld, models);
    const idBounds bounds = MotionBounds(start, start + velocity,
        movingModel, axis);
    return ToClipQuery(collisionModelManager.SlideMoveContacts(result,
        contacts, start, velocity, gravityVector, stepUp, stepUp, bounds,
        traceModels.empty() ? nullptr : traceModels.data(),
        static_cast<int>(traceModels.size()), axis, contentMask,
        models.empty() ? nullptr : models.data(),
        static_cast<int>(models.size()), userName));
}

idClipQuery idClip::Contents(trace_t* const result, const idVec3& start,
        const idClipModel* const movingModel, const idMat3& axis,
        const int contentMask, const int passEntityNumber,
        const char* const userName) {
    std::vector<const idTraceModel*> traceModels;
    std::vector<idPositionedCollisionModel> models;
    CollectTraceModels(movingModel, traceModels);
    CollectPositionedModels(*this, contentMask, passEntityNumber,
        false, models);
    const idBounds bounds = MotionBounds(start, start, movingModel, axis);
    return ToClipQuery(collisionModelManager.Contents(result, start, bounds,
        traceModels.empty() ? nullptr : traceModels.data(),
        static_cast<int>(traceModels.size()), axis, contentMask,
        models.empty() ? nullptr : models.data(),
        static_cast<int>(models.size()), userName));
}

idClipQuery idClip::LocalContents(const idClipQuery localSpace,
        const idVec3& start, const idClipModel* const movingModel,
        const idMat3& axis, const int contentMask,
        const int passEntityNumber, const char* const userName) {
    std::vector<const idTraceModel*> traceModels;
    std::vector<idPositionedCollisionModel> models;
    CollectTraceModels(movingModel, traceModels);
    CollectPositionedModels(*this, contentMask, passEntityNumber,
        false, models);
    const idBounds bounds = MotionBounds(start, start, movingModel, axis);
    return ToClipQuery(collisionModelManager.LocalContents(
        ToCollisionQuery(localSpace), start, bounds,
        traceModels.empty() ? nullptr : traceModels.data(),
        static_cast<int>(traceModels.size()), axis, contentMask,
        models.empty() ? nullptr : models.data(),
        static_cast<int>(models.size()), userName));
}

idClipQuery idClip::Contacts(contactsResult_t* const result,
        const idVec3& start, const idVec3& direction, const float depth,
        const idClipModel* const movingModel, const idMat3& axis,
        const int contentMask, const int passEntityNumber,
        const char* const userName) {
    std::vector<const idTraceModel*> traceModels;
    std::vector<idPositionedCollisionModel> models;
    CollectTraceModels(movingModel, traceModels);
    CollectPositionedModels(*this, contentMask, passEntityNumber,
        false, models);
    const idBounds bounds = MotionBounds(start, start + direction * depth,
        movingModel, axis);
    return ToClipQuery(collisionModelManager.Contacts(result, start,
        direction, depth, bounds,
        traceModels.empty() ? nullptr : traceModels.data(),
        static_cast<int>(traceModels.size()), axis, contentMask,
        models.empty() ? nullptr : models.data(),
        static_cast<int>(models.size()), userName));
}

idClipQuery idClip::Clip(clipResult_t* const result, const idVec3& start,
        const idTraceModel* const traceModel, const idMat3& axis,
        const int contentMask, const int passEntityNumber,
        const char* const userName) {
    std::vector<idPositionedCollisionModel> models;
    CollectPositionedModels(*this, contentMask, passEntityNumber,
        false, models);
    const idTraceModel* traceModels[1] = { traceModel };
    const idBounds bounds = traceModel != nullptr
        ? MotionBounds(start, start, nullptr, axis) : PointBounds(start);
    return ToClipQuery(collisionModelManager.Clip(result, start, bounds,
        traceModel != nullptr ? traceModels : nullptr,
        traceModel != nullptr ? 1 : 0, axis, contentMask,
        models.empty() ? nullptr : models.data(),
        static_cast<int>(models.size()), userName));
}

void idClip::TranslationModel(trace_t& result, const idVec3& start,
        const idVec3& end, const idClipModel* const movingModel,
        const idMat3& axis, const int contentMask,
        const idVec3& modelOrigin, const idClipModel* const model,
        const idMat3& modelAxis) const {
    std::vector<const idTraceModel*> traces;
    CollectTraceModels(movingModel, traces);
    idPositionedCollisionModel positioned{};
    if (model != nullptr) {
        positioned.model = model->GetCollisionModel();
        positioned.modelOrigin = modelOrigin;
        positioned.modelAxis = modelAxis;
        positioned.modelEntityNum = model->GetEntityNumber();
        positioned.modelPhysicsId = model->GetPhysicsId();
        positioned.modelBodyId = model->GetBodyId();
        positioned.modelContentsOverride = model->GetContents();
    }
    collisionModelManager.Translation(&result, start, end,
        MotionBounds(start, end, movingModel, axis),
        traces.empty() ? nullptr : traces.data(),
        static_cast<int>(traces.size()), axis, contentMask,
        positioned.model != nullptr ? &positioned : nullptr,
        positioned.model != nullptr ? 1 : 0, "TranslationModel");
}

void idClip::RotationModel(trace_t& result, const idVec3& start,
        const idRotation& rotation, const idClipModel* const movingModel,
        const idMat3& axis, const int contentMask,
        const idVec3& modelOrigin, const idClipModel* const model,
        const idMat3& modelAxis) const {
    std::vector<const idTraceModel*> traces;
    CollectTraceModels(movingModel, traces);
    idPositionedCollisionModel positioned{};
    if (model != nullptr) {
        positioned.model = model->GetCollisionModel();
        positioned.modelOrigin = modelOrigin;
        positioned.modelAxis = modelAxis;
        positioned.modelContentsOverride = model->GetContents();
    }
    collisionModelManager.Rotation(&result, start, rotation,
        MotionBounds(start, start, movingModel, axis),
        traces.empty() ? nullptr : traces.data(),
        static_cast<int>(traces.size()), axis, contentMask,
        positioned.model != nullptr ? &positioned : nullptr,
        positioned.model != nullptr ? 1 : 0, "RotationModel");
}

void idClip::ContentsModel(trace_t& result, const idVec3& start,
        const idClipModel* const movingModel, const idMat3& axis,
        const int contentMask, const idVec3& modelOrigin,
        const idClipModel* const model, const idMat3& modelAxis) const {
    std::vector<const idTraceModel*> traces;
    CollectTraceModels(movingModel, traces);
    idPositionedCollisionModel positioned{};
    if (model != nullptr) {
        positioned.model = model->GetCollisionModel();
        positioned.modelOrigin = modelOrigin;
        positioned.modelAxis = modelAxis;
        positioned.modelContentsOverride = model->GetContents();
    }
    collisionModelManager.Contents(&result, start,
        MotionBounds(start, start, movingModel, axis),
        traces.empty() ? nullptr : traces.data(),
        static_cast<int>(traces.size()), axis, contentMask,
        positioned.model != nullptr ? &positioned : nullptr,
        positioned.model != nullptr ? 1 : 0, "ContentsModel");
}

bool idClip::GetModelContactFeature(const contactInfo_t& contact,
        const idClipModel* const model, idFixedWinding& winding) const {
    if (model == nullptr) return false;
    idCollisionModel* const collisionModel = model->GetCollisionModel();
    if (collisionModel == nullptr) return false;
    if (contact.type == CONTACT_EDGE) {
        idVec3 points[2];
        if (!collisionModel->GetEdge(contact.modelFeature,
                points[0], points[1])) return false;
        winding.Clear();
        winding.AddPoint(points[0]);
        winding.AddPoint(points[1]);
        return true;
    }
    if (contact.type == CONTACT_MODELVERTEX) {
        idVec3 point;
        if (!collisionModel->GetVertex(contact.modelFeature, point))
            return false;
        winding.Clear();
        winding.AddPoint(point);
        return true;
    }
    return collisionModel->GetPolygon(contact.modelFeature, winding);
}

void idClip::PrintStatistics() {
}
