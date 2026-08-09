#pragma once

#include "cm/jobs/collisionresults.h"
#include "cm/jobs/collisionquery.h"
#include "gamelib/physics/clipmodel.h"
#include "idlib/blockalloc_base.h"
#include "idlib/containers/list.h"
#include "idlib/containers/staticlist.h"
#include "idlib/math/rotation.h"

#include <cstdint>

class idAAS2;
class idCollisionModel;
class idFixedWinding;
class idTraceModel;
class idTraceModelCache;
class idTraceModelRecycler;
class idTypeInfoTools;
struct idPositionedCollisionModel;

#ifndef ID_CLIP_QUERY_DEFINED
#define ID_CLIP_QUERY_DEFINED
struct idClipQuery { std::uint64_t index; };
#endif

struct idGatherQuery { std::uint64_t index; };
#ifndef ID_RESIDENCY_QUERY_DEFINED
#define ID_RESIDENCY_QUERY_DEFINED
struct idResidencyQuery { std::uint64_t index; };
#endif

struct clipSector_t {
    int axis;
    float dist;
    clipSector_t* children[2];
    clipLink_t* clipLinks;
};

struct clipQueryStats_t {
    const char* userName;
    int count;
    int max;
};

class idClip {
public:
    enum queryType_t : int {
        QUERY_VALID = 0,
        QUERY_CANCELED,
        QUERY_SUBMITTED_TRANSLATION,
        QUERY_SUBMITTED_ROTATION,
        QUERY_SUBMITTED_MOTION,
        QUERY_SUBMITTED_MOTION_CONTACTS,
        QUERY_SUBMITTED_STEPMOVE,
        QUERY_SUBMITTED_STEPMOVE_CONTACTS,
        QUERY_SUBMITTED_SLIDEMOVE,
        QUERY_SUBMITTED_SLIDEMOVE_CONTACTS,
        QUERY_SUBMITTED_CONTENTS,
        QUERY_SUBMITTED_CONTACTS,
        QUERY_SUBMITTED_CLIP
    };

    enum gatherType_t : int {
        GATHER_TOUCHING_BOUNDS = 0,
        GATHER_TOUCHING_LINE = 1,
        GATHER_TOUCHING_CLIPMODEL = 2
    };

    struct idClipQueryParms {
        idVec3 start;
        idVec3 end;
        idVec3 origin;
        idVec3 vec;
        float f1;
        float f2;
        idMat3 startAxis;
        int clipMask;
        std::uint16_t passEntityNumber;
        std::uint16_t flags;
        std::uint8_t pad[12];
        unsigned int queryIndex;
        const idClipModel* clipModel;
        const idTraceModel* traceModel;
        const char* userName;
    };

    struct idClipCollisionQuery {
        queryType_t type;
        int parmIndex;
        idClipModel* clipModel;
        idCollisionQuery query;
    };

    struct idClipGatherQuery {
        idVec3 vectors[4];
        int clipMask;
        std::int16_t passEntityNumber;
        std::int16_t gatherType;
        std::uint16_t firstResultIndex;
        std::uint16_t numResults;
        const idClipModel* clipModel;
    };

    struct idGatherResult {
        idCollisionQuery query;
        int physicsId;
        std::int16_t bodyId;
        std::int16_t entityNumber;
    };

    struct idClipResidencyQuery {
        idBounds absBounds;
        bool resident;
        std::uint8_t pad[7];
    };

    idClip();
    ~idClip();
    void Init(idCollisionModel* worldModel, idTraceModelCache* cache,
        idTraceModelRecycler* recycler);
    void Shutdown();
    void StartQueryFrame();
    void EndQueryFrame();
    void ResolveCollisionQueries();
    void DeleteClipModels();
    void DeleteClipModel(idClipModel* clipModel);
    void InitializeAASLinks(int aasType);
    const idBounds& GetWorldBounds() const;
    void AddStreamArea(int areaNum);
    void ClearStreamAreas();
    int FindStreamArea(const idClipModel* clipModel);

    int GetClipModelsTouchingBounds(const idBounds& bounds, int contentMask,
        idClipModel** clipModels, int maxClipModels) const;
    int GetClipModelsTouchingLine(const idVec3& start, const idVec3& end,
        int contentMask, idClipModel** clipModels,
        int maxClipModels) const;
    int GetEntitiesTouchingBounds(const idBounds& bounds, int contentMask,
        int* entityNumbers, int maxEntities) const;
    int GetEntitiesTouchingLine(const idVec3& start, const idVec3& end,
        int contentMask, int* entityNumbers, int maxEntities) const;
    idGatherQuery GatherTouchingBounds(const idBounds& bounds,
        int contentMask, int passEntityNumber, const char* userName);
    idGatherQuery GatherTouchingClipModel(const idVec3& origin,
        const idClipModel* clipModel, const idMat3& axis, int contentMask,
        int passEntityNumber, const char* userName);
    int GetGatheredClipModels(const idGatherQuery& query,
        idClipModel** clipModels, int maxClipModels);
    int GetGatheredEntities(const idGatherQuery& query,
        int* entityNumbers, int maxEntities);
    idResidencyQuery TestResidency(const idBounds& bounds);

    idClipQuery Translation(trace_t* result, const idVec3& start,
        const idVec3& end, const idClipModel* clipModel,
        const idMat3& axis, int contentMask, int passEntityNumber,
        bool ignoreWorld, const char* userName);
    idClipQuery LocalTranslation(idClipQuery localSpace,
        const idVec3& start, const idVec3& end,
        const idClipModel* clipModel, const idMat3& axis,
        int contentMask, int passEntityNumber, bool ignoreWorld,
        const char* userName);
    idClipQuery TranslationTraceModel(trace_t* result,
        const idVec3& start, const idVec3& end,
        const idClipModel* clipModel, const idVec3& modelOrigin,
        const idMat3& modelAxis, int contentMask, const char* userName);
    idClipQuery Rotation(trace_t* result, const idVec3& start,
        const idRotation& rotation, const idClipModel* clipModel,
        const idMat3& axis, int contentMask, int passEntityNumber,
        bool ignoreWorld, const char* userName);
    idClipQuery Motion(trace_t* result, const idVec3& start,
        const idVec3& end, const idRotation& rotation,
        const idClipModel* clipModel, const idMat3& axis,
        int contentMask, int passEntityNumber, bool ignoreWorld,
        const char* userName);
    idClipQuery MotionContacts(trace_t* result, contactsResult_t* contacts,
        const idVec3& start, const idVec3& end,
        const idRotation& rotation, float depth,
        const idClipModel* clipModel, const idMat3& axis,
        int contentMask, int passEntityNumber, bool ignoreWorld,
        const char* userName);
    idClipQuery StepMove(trace_t* result, const idVec3& start,
        const idVec3& end, const idVec3& downNormal,
        float stepUp, float stepDown, const idClipModel* clipModel,
        const idMat3& axis, int contentMask, int passEntityNumber,
        bool ignoreWorld, const char* userName);
    idClipQuery StepMoveContacts(trace_t* result,
        contactsResult_t* contacts, const idVec3& start,
        const idVec3& end, const idVec3& downNormal,
        float stepUp, float stepDown, const idClipModel* clipModel,
        const idMat3& axis, int contentMask, int passEntityNumber,
        bool ignoreWorld, const char* userName);
    idClipQuery SlideMoveContacts(trace_t* result,
        contactsResult_t* contacts, const idVec3& start,
        const idVec3& end, const idVec3& downNormal,
        float stepUp, const idClipModel* clipModel, const idMat3& axis,
        int contentMask, int passEntityNumber, bool ignoreWorld,
        const char* userName);
    idClipQuery Contents(trace_t* result, const idVec3& start,
        const idClipModel* clipModel, const idMat3& axis,
        int contentMask, int passEntityNumber, const char* userName);
    idClipQuery LocalContents(idClipQuery localSpace, const idVec3& start,
        const idClipModel* clipModel, const idMat3& axis,
        int contentMask, int passEntityNumber, const char* userName);
    idClipQuery Contacts(contactsResult_t* result, const idVec3& start,
        const idVec3& direction, float depth,
        const idClipModel* clipModel, const idMat3& axis,
        int contentMask, int passEntityNumber, const char* userName);
    idClipQuery Clip(clipResult_t* result, const idVec3& start,
        const idTraceModel* traceModel, const idMat3& axis,
        int contentMask, int passEntityNumber, const char* userName);

    void TranslationModel(trace_t& result, const idVec3& start,
        const idVec3& end, const idClipModel* clipModel,
        const idMat3& axis, int contentMask, const idVec3& modelOrigin,
        const idClipModel* model, const idMat3& modelAxis) const;
    void RotationModel(trace_t& result, const idVec3& start,
        const idRotation& rotation, const idClipModel* clipModel,
        const idMat3& axis, int contentMask, const idVec3& modelOrigin,
        const idClipModel* model, const idMat3& modelAxis) const;
    void ContentsModel(trace_t& result, const idVec3& start,
        const idClipModel* clipModel, const idMat3& axis, int contentMask,
        const idVec3& modelOrigin, const idClipModel* model,
        const idMat3& modelAxis) const;
    bool GetModelContactFeature(const contactInfo_t& contact,
        const idClipModel* model, idFixedWinding& winding) const;
    void PrintStatistics();
    void DrawWorld(const idVec3&, const idMat3&, float, bool) {}
    void DrawSingleClipModel(idClipModel*, const idVec3&,
        const idMat3&, int) {}
    void ShowCollisionPoint(const contactInfo_t&,
        const idTypeInfoTools*) {}
    void ShowCollisionSurfaces(const idVec3&, const idMat3&, int, int,
        const idTypeInfoTools*) {}

    idClipModel* world;
    idClipModel* temporaryClipModel;
    idClipModel* defaultClipModel;
    idClipModel* playerMeleeClipModel;
    idClipModel* clip8x8;
    idClipModel* clip8x8x8;
    idClipModel* clip16x16;
    idClipModel* clip16x16x16;
    idClipModel* clip24x24;
    idClipModel* clip32x32;
    idClipModel* clip8x16;
    idClipModel* clip48x48;
    idClipModel* clip96x96;
    idClipModel* clip24x24x96;
    idClipModel* clip32x32x96;
    idClipModel* clip48x48x96;
    idBlockAlloc<clipLink_t, 256, 13> clipLinkAllocator;
    idStaticList<clipSector_t, 8191> clipSectors;
    int touchCount;
    idAAS2* aases[8];
    idTraceModelCache* traceModelCache;
    idTraceModelRecycler* traceModelRecycler;
    idClipModel* deletedClipModels;
    idList<int, 13> streamAreas;
    idClipQueryParms* queryParms;
    int numQueryParms;
    idStaticList<unsigned int, 2048> translationQueries;
    idStaticList<unsigned int, 2048> rotationQueries;
    idStaticList<unsigned int, 2048> motionQueries;
    idStaticList<unsigned int, 2048> motionContactsQueries;
    idStaticList<unsigned int, 2048> stepMoveQueries;
    idStaticList<unsigned int, 2048> stepMoveContactsQueries;
    idStaticList<unsigned int, 2048> slideMoveQueries;
    idStaticList<unsigned int, 2048> slideMoveContactsQueries;
    idStaticList<unsigned int, 2048> contentsQueries;
    idStaticList<unsigned int, 2048> contactsQueries;
    idStaticList<unsigned int, 2048> clipQueries;
    idStaticList<unsigned int, 2048> localTranslationQueries;
    idStaticList<unsigned int, 2048> localContentsQueries;
    idStaticList<unsigned int, 2048> translationTraceModelQueries;
    idClipCollisionQuery collisionQueries[4096];
    std::uint64_t collisionQueryFirstSubmittedIndex;
    std::uint64_t collisionQueryLastSubmittedIndex;
    std::uint64_t collisionQueryFirstAllocedIndex;
    std::uint64_t collisionQueryLastAllocedIndex;
    std::uint64_t collisionQueryLastResolvedIndex;
    const char* gatherQueryUserNames[256];
    idClipGatherQuery gatherQueries[256];
    std::uint64_t gatherQueryFirstSubmittedIndex;
    std::uint64_t gatherQueryLastSubmittedIndex;
    std::uint64_t gatherQueryFirstAllocedIndex;
    std::uint64_t gatherQueryLastAllocedIndex;
    idGatherResult gatherResults[2048];
    std::uint64_t gatherResultFirstSubmittedIndex;
    std::uint64_t gatherResultLastSubmittedIndex;
    std::uint64_t gatherResultFirstAllocedIndex;
    std::uint64_t gatherResultLastAllocedIndex;
    idClipResidencyQuery residencyQueries[1024];
    std::uint64_t residencyQueryFirstSubmittedIndex;
    std::uint64_t residencyQueryLastSubmittedIndex;
    std::uint64_t residencyQueryFirstAllocedIndex;
    std::uint64_t residencyQueryLastAllocedIndex;
};

static_assert(sizeof(idClipQuery) == 8,
    "Recovered clip-query ABI changed");
static_assert(sizeof(idGatherQuery) == 8,
    "Recovered gather-query ABI changed");
static_assert(sizeof(idResidencyQuery) == 8,
    "Recovered residency-query ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idClip::idClipQueryParms) == 128,
    "Recovered clip query parameters ABI changed");
static_assert(sizeof(idClip::idClipCollisionQuery) == 24,
    "Recovered collision query ABI changed");
static_assert(sizeof(idClip::idClipGatherQuery) == 64,
    "Recovered gather query ABI changed");
static_assert(sizeof(idClip::idGatherResult) == 16,
    "Recovered gather result ABI changed");
static_assert(sizeof(idClip::idClipResidencyQuery) == 32,
    "Recovered residency state ABI changed");
#endif
